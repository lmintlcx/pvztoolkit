from __future__ import annotations

import ctypes
from ctypes import wintypes
from dataclasses import dataclass
from typing import Optional

from .memory import MemoryProcess
from .offsets import (
    FORCE_ENGLISH_PROFILES,
    KNOWN_VERSION_NAMES,
    PROCESS_EXE_NAMES,
    VERSIONS_BY_TIMESTAMP,
    WINDOW_TITLES,
    VersionOffsets,
)

user32 = ctypes.WinDLL("user32", use_last_error=True)
kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)

FindWindowW = user32.FindWindowW
FindWindowW.argtypes = [wintypes.LPCWSTR, wintypes.LPCWSTR]
FindWindowW.restype = wintypes.HWND

GetWindowThreadProcessId = user32.GetWindowThreadProcessId
GetWindowThreadProcessId.argtypes = [wintypes.HWND, ctypes.POINTER(wintypes.DWORD)]
GetWindowThreadProcessId.restype = wintypes.DWORD

TH32CS_SNAPPROCESS = 0x00000002
TH32CS_SNAPMODULE = 0x00000008
TH32CS_SNAPMODULE32 = 0x00000010
INVALID_HANDLE_VALUE = ctypes.c_void_p(-1).value
MAX_PATH = 260


class PROCESSENTRY32W(ctypes.Structure):
    _fields_ = [
        ("dwSize", wintypes.DWORD),
        ("cntUsage", wintypes.DWORD),
        ("th32ProcessID", wintypes.DWORD),
        ("th32DefaultHeapID", ctypes.c_size_t),
        ("th32ModuleID", wintypes.DWORD),
        ("cntThreads", wintypes.DWORD),
        ("th32ParentProcessID", wintypes.DWORD),
        ("pcPriClassBase", ctypes.c_long),
        ("dwFlags", wintypes.DWORD),
        ("szExeFile", wintypes.WCHAR * MAX_PATH),
    ]


class MODULEENTRY32W(ctypes.Structure):
    _fields_ = [
        ("dwSize", wintypes.DWORD),
        ("th32ModuleID", wintypes.DWORD),
        ("th32ProcessID", wintypes.DWORD),
        ("GlblcntUsage", wintypes.DWORD),
        ("ProccntUsage", wintypes.DWORD),
        ("modBaseAddr", ctypes.POINTER(ctypes.c_ubyte)),
        ("modBaseSize", wintypes.DWORD),
        ("hModule", wintypes.HMODULE),
        ("szModule", wintypes.WCHAR * 256),
        ("szExePath", wintypes.WCHAR * MAX_PATH),
    ]


CreateToolhelp32Snapshot = kernel32.CreateToolhelp32Snapshot
CreateToolhelp32Snapshot.argtypes = [wintypes.DWORD, wintypes.DWORD]
CreateToolhelp32Snapshot.restype = wintypes.HANDLE

Process32FirstW = kernel32.Process32FirstW
Process32FirstW.argtypes = [wintypes.HANDLE, ctypes.POINTER(PROCESSENTRY32W)]
Process32FirstW.restype = wintypes.BOOL

Process32NextW = kernel32.Process32NextW
Process32NextW.argtypes = [wintypes.HANDLE, ctypes.POINTER(PROCESSENTRY32W)]
Process32NextW.restype = wintypes.BOOL

Module32FirstW = kernel32.Module32FirstW
Module32FirstW.argtypes = [wintypes.HANDLE, ctypes.POINTER(MODULEENTRY32W)]
Module32FirstW.restype = wintypes.BOOL

CloseHandle = kernel32.CloseHandle
CloseHandle.argtypes = [wintypes.HANDLE]
CloseHandle.restype = wintypes.BOOL

VirtualAllocEx = kernel32.VirtualAllocEx
VirtualAllocEx.argtypes = [wintypes.HANDLE, wintypes.LPVOID, ctypes.c_size_t, wintypes.DWORD, wintypes.DWORD]
VirtualAllocEx.restype = wintypes.LPVOID

VirtualFreeEx = kernel32.VirtualFreeEx
VirtualFreeEx.argtypes = [wintypes.HANDLE, wintypes.LPVOID, ctypes.c_size_t, wintypes.DWORD]
VirtualFreeEx.restype = wintypes.BOOL

CreateRemoteThread = kernel32.CreateRemoteThread
CreateRemoteThread.argtypes = [wintypes.HANDLE, wintypes.LPVOID, ctypes.c_size_t, wintypes.LPVOID, wintypes.LPVOID, wintypes.DWORD, ctypes.POINTER(wintypes.DWORD)]
CreateRemoteThread.restype = wintypes.HANDLE

WaitForSingleObject = kernel32.WaitForSingleObject
WaitForSingleObject.argtypes = [wintypes.HANDLE, wintypes.DWORD]
WaitForSingleObject.restype = wintypes.DWORD

MEM_COMMIT = 0x1000
MEM_RESERVE = 0x2000
MEM_RELEASE = 0x8000
PAGE_EXECUTE_READWRITE = 0x40
INFINITE = 0xFFFFFFFF


@dataclass
class AttachResult:
    ok: bool
    message: str


class PvZAdapter:
    def __init__(self) -> None:
        self.process: Optional[MemoryProcess] = None
        self.offsets: Optional[VersionOffsets] = None
        self.detected_timestamp: Optional[int] = None
        self.detected_version_name: Optional[str] = None
        self.forced_profile_name: Optional[str] = None

    def detach(self) -> None:
        if self.process:
            self.process.close()
            self.process = None
        self.offsets = None
        self.detected_timestamp = None
        self.detected_version_name = None
        self.forced_profile_name = None

    def is_ready(self) -> bool:
        return bool(self.process and self.process.is_alive() and self.offsets)

    def attach(self, force_english: bool = False, force_profile: str = "1096-en") -> AttachResult:
        self.detach()

        pid = self._find_pid_by_window()
        if pid == 0:
            pid = self._find_pid_by_process_name()

        if pid == 0:
            return AttachResult(False, "未找到 PvZ 进程（窗口与进程名都未匹配）")

        try:
            self.process = MemoryProcess(pid)

            stamp, version_name = self._detect_version(pid)
            self.detected_timestamp = stamp
            self.detected_version_name = version_name

            if force_english:
                chosen = FORCE_ENGLISH_PROFILES.get(force_profile)
                if not chosen:
                    self.detach()
                    return AttachResult(False, f"无效强制英文配置: {force_profile}")
                self.offsets = chosen
                self.forced_profile_name = force_profile
                stamp_text = f"0x{stamp:08X}" if stamp is not None else "unknown"
                return AttachResult(
                    True,
                    f"已连接 PID={pid}，检测={version_name}({stamp_text})，强制偏移={chosen.name}",
                )

            if stamp is None:
                self.detach()
                return AttachResult(False, "连接到进程，但版本时间戳读取失败；可勾选强制英文偏移进行测试")

            matched = VERSIONS_BY_TIMESTAMP.get(stamp)
            if not matched:
                self.detach()
                return AttachResult(False, f"检测到未适配版本: {version_name} (0x{stamp:08X})")

            self.offsets = matched
            return AttachResult(True, f"已连接 PID={pid}，版本={matched.name}")
        except Exception as ex:
            self.detach()
            return AttachResult(False, f"打开进程失败: {ex}")

    def _find_pid_by_window(self) -> int:
        hwnd = None
        for title in WINDOW_TITLES:
            h = FindWindowW("MainWindow", title)
            if h:
                hwnd = h
                break

        if not hwnd:
            h = FindWindowW("MainWindow", None)
            if h:
                hwnd = h

        if not hwnd:
            return 0

        pid = wintypes.DWORD(0)
        GetWindowThreadProcessId(hwnd, ctypes.byref(pid))
        return int(pid.value)

    def _find_pid_by_process_name(self) -> int:
        snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)
        if snap == INVALID_HANDLE_VALUE:
            return 0

        try:
            pe = PROCESSENTRY32W()
            pe.dwSize = ctypes.sizeof(PROCESSENTRY32W)

            ok = Process32FirstW(snap, ctypes.byref(pe))
            while ok:
                exe = pe.szExeFile.lower()
                if exe in PROCESS_EXE_NAMES:
                    return int(pe.th32ProcessID)
                ok = Process32NextW(snap, ctypes.byref(pe))
            return 0
        finally:
            CloseHandle(snap)

    def _get_main_module_base(self, pid: int) -> Optional[int]:
        snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid)
        if snap == INVALID_HANDLE_VALUE:
            return None

        try:
            me = MODULEENTRY32W()
            me.dwSize = ctypes.sizeof(MODULEENTRY32W)
            ok = Module32FirstW(snap, ctypes.byref(me))
            if not ok:
                return None
            return ctypes.cast(me.modBaseAddr, ctypes.c_void_p).value
        finally:
            CloseHandle(snap)

    def _detect_version(self, pid: int) -> tuple[Optional[int], str]:
        if not self.process:
            return None, "未连接"

        base = self._get_main_module_base(pid)
        if base is None:
            return None, "未知版本（无法获取模块基址）"

        try:
            pe_header_offset = self.process.read_uint32([base + 0x3C])
            nth = base + pe_header_offset
            stamp = self.process.read_uint32([nth + 0x08])
            name = KNOWN_VERSION_NAMES.get(stamp, "未知版本")
            return stamp, name
        except Exception:
            return None, "未知版本（无法读取时间戳）"

    def _ensure(self) -> tuple[MemoryProcess, VersionOffsets]:
        if not self.process or not self.process.is_alive() or not self.offsets:
            raise RuntimeError("进程未连接或已退出")
        return self.process, self.offsets

    def _assemble_put_plant(self, row: int, col: int, plant_type: int, imitater: bool) -> bytes:
        _, off = self._ensure()
        code = bytearray()
        if imitater:
            code += b"\x68" + int(plant_type).to_bytes(4, "little", signed=True)
            code += b"\x6A\x30"
        else:
            code += b"\x6A\xFF"
            code += b"\x68" + int(plant_type).to_bytes(4, "little", signed=True)
        code += b"\xB8" + int(row).to_bytes(4, "little", signed=True)
        code += b"\x68" + int(col).to_bytes(4, "little", signed=True)
        code += b"\x8B\x2D" + int(off.lawn).to_bytes(4, "little")
        code += b"\x8B\xAD" + int(off.board).to_bytes(4, "little")
        code += b"\x55"
        code += b"\xBE" + int(off.call_put_plant).to_bytes(4, "little")
        code += b"\xFF\xD6"
        code += b"\xC3"
        return bytes(code)

    def _assemble_put_zombie(self, row: int, col: int, zombie_type: int) -> bytes:
        _, off = self._ensure()
        code = bytearray()
        code += b"\x68" + int(col).to_bytes(4, "little", signed=True)
        code += b"\x68" + int(zombie_type).to_bytes(4, "little", signed=True)
        code += b"\xB8" + int(row).to_bytes(4, "little", signed=True)
        code += b"\x8B\x0D" + int(off.lawn).to_bytes(4, "little")
        code += b"\x8B\x89" + int(off.board).to_bytes(4, "little")
        code += b"\x8B\x89" + int(off.challenge).to_bytes(4, "little")
        code += b"\xBE" + int(off.call_put_zombie).to_bytes(4, "little")
        code += b"\xFF\xD6"
        code += b"\xC3"
        return bytes(code)

    def _assemble_put_grave(self, row: int, col: int) -> bytes:
        _, off = self._ensure()
        code = bytearray()
        code += b"\x8B\x15" + int(off.lawn).to_bytes(4, "little")
        code += b"\x8B\x92" + int(off.board).to_bytes(4, "little")
        code += b"\x8B\x92" + int(off.challenge).to_bytes(4, "little")
        code += b"\x52"
        code += b"\xBF" + int(row).to_bytes(4, "little", signed=True)
        code += b"\xBB" + int(col).to_bytes(4, "little", signed=True)
        code += b"\xBE" + int(off.call_put_grave).to_bytes(4, "little")
        code += b"\xFF\xD6"
        code += b"\xC3"
        return bytes(code)

    def _assemble_put_ladder(self, row: int, col: int) -> bytes:
        _, off = self._ensure()
        code = bytearray()
        code += b"\xBF" + int(row).to_bytes(4, "little", signed=True)
        code += b"\x68" + int(col).to_bytes(4, "little", signed=True)
        code += b"\xA1" + int(off.lawn).to_bytes(4, "little")
        code += b"\x8B\x80" + int(off.board).to_bytes(4, "little")
        code += b"\xBE" + int(off.call_put_ladder).to_bytes(4, "little")
        code += b"\xFF\xD6"
        code += b"\xC3"
        return bytes(code)

    def _run_remote_code(self, code: bytes) -> None:
        proc, _ = self._ensure()
        remote = VirtualAllocEx(proc.handle, None, len(code), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE)
        if not remote:
            raise RuntimeError("VirtualAllocEx 失败")
        try:
            proc.write_bytes(code, [int(ctypes.cast(remote, ctypes.c_void_p).value)])
            thread = CreateRemoteThread(proc.handle, None, 0, remote, None, 0, None)
            if not thread:
                raise RuntimeError("CreateRemoteThread 失败")
            try:
                WaitForSingleObject(thread, INFINITE)
            finally:
                CloseHandle(thread)
        finally:
            VirtualFreeEx(proc.handle, remote, 0, MEM_RELEASE)

    def _check_combat_ui(self) -> None:
        ui = self.get_game_ui()
        if ui not in (2, 3):
            raise RuntimeError(f"当前 GameUI={ui}，不在战斗界面")

    def _row_count(self) -> int:
        scene = self.get_scene()
        return 6 if scene in (2, 3) else 5

    def _iter_targets(self, row: int, col: int, col_max: int = 9):
        rows = range(self._row_count()) if row == -1 else [row]
        cols = range(col_max) if col == -1 else [col]
        for r in rows:
            for c in cols:
                yield r, c

    def put_plant(self, row: int, col: int, plant_type: int, imitater: bool) -> None:
        self._check_combat_ui()
        col_max = 8 if plant_type == 47 else 9
        for r, c in self._iter_targets(row, col, col_max):
            self._run_remote_code(self._assemble_put_plant(r, c, plant_type, imitater))

    def put_zombie(self, row: int, col: int, zombie_type: int) -> None:
        self._check_combat_ui()
        for r, c in self._iter_targets(row, col, 9):
            self._run_remote_code(self._assemble_put_zombie(r, c, zombie_type))

    def put_grave(self, row: int, col: int) -> None:
        self._check_combat_ui()
        for r, c in self._iter_targets(row, col, 9):
            self._run_remote_code(self._assemble_put_grave(r, c))

    def put_ladder(self, row: int, col: int) -> None:
        self._check_combat_ui()
        for r, c in self._iter_targets(row, col, 9):
            self._run_remote_code(self._assemble_put_ladder(r, c))

    def get_game_ui(self) -> int:
        proc, off = self._ensure()
        return proc.read_int32([off.lawn, off.game_ui])

    def get_game_mode(self) -> int:
        proc, off = self._ensure()
        return proc.read_int32([off.lawn, off.game_mode])

    def get_scene(self) -> int:
        proc, off = self._ensure()
        return proc.read_int32([off.lawn, off.board, off.scene])

    def set_scene(self, scene: int) -> None:
        if scene < 0 or scene > 5:
            raise RuntimeError("场景范围必须是 0~5")
        proc, off = self._ensure()
        ui = self.get_game_ui()
        if ui not in (2, 3):
            raise RuntimeError(f"当前 GameUI={ui}，不在战斗界面")
        proc.write_int32(scene, [off.lawn, off.board, off.scene])

    def set_free_planting(self, enabled: bool) -> None:
        proc, off = self._ensure()
        proc.write_int32(1 if enabled else 0, [off.lawn, off.free_planting])

    def get_slot_count(self) -> int:
        proc, off = self._ensure()
        slot_offset = proc.read_uint32([off.lawn, off.board, off.slot])
        if slot_offset == 0:
            raise RuntimeError("卡槽数据不可用")
        return proc.read_int32([slot_offset + off.slot_count])

    def get_slot_seed(self, index: int) -> tuple[int, bool]:
        proc, off = self._ensure()
        ui = self.get_game_ui()
        if ui not in (2, 3):
            raise RuntimeError(f"当前 GameUI={ui}，不在战斗界面")

        slot_offset = proc.read_uint32([off.lawn, off.board, off.slot])
        if slot_offset == 0:
            raise RuntimeError("卡槽数据不可用")

        slot_count = proc.read_int32([slot_offset + off.slot_count])
        if index < 0 or index >= slot_count:
            raise RuntimeError(f"卡槽索引越界: {index}")

        slot_seed_struct_size = 0x50
        seed_type = proc.read_int32([slot_offset + off.slot_seed_type + index * slot_seed_struct_size])
        seed_type_im = proc.read_int32([slot_offset + off.slot_seed_type_im + index * slot_seed_struct_size])

        if seed_type == 48:
            return seed_type_im, True
        return seed_type, False

    def set_slot_seed(self, index: int, plant_type: int, imitater: bool) -> None:
        proc, off = self._ensure()
        ui = self.get_game_ui()
        if ui not in (2, 3):
            raise RuntimeError(f"当前 GameUI={ui}，不在战斗界面")

        slot_offset = proc.read_uint32([off.lawn, off.board, off.slot])
        if slot_offset == 0:
            raise RuntimeError("卡槽数据不可用")

        slot_count = proc.read_int32([slot_offset + off.slot_count])
        if index < 0 or index >= slot_count:
            raise RuntimeError(f"卡槽索引越界: {index}")

        slot_seed_struct_size = 0x50
        if imitater:
            proc.write_int32(48, [slot_offset + off.slot_seed_type + index * slot_seed_struct_size])
            proc.write_int32(plant_type, [slot_offset + off.slot_seed_type_im + index * slot_seed_struct_size])
        else:
            proc.write_int32(plant_type, [slot_offset + off.slot_seed_type + index * slot_seed_struct_size])
            proc.write_int32(-1, [slot_offset + off.slot_seed_type_im + index * slot_seed_struct_size])

    def read_slot_preset_payload(self) -> list[dict]:
        count = self.get_slot_count()
        if count < 10:
            raise RuntimeError(f"当前仅有 {count} 个卡槽，无法保存十卡预设")
        payload: list[dict] = []
        for i in range(10):
            plant_type, imitater = self.get_slot_seed(i)
            payload.append({"index": i, "plant_type": plant_type, "imitater": imitater})
        return payload

    def apply_slot_preset_payload(self, payload: list[dict]) -> None:
        count = self.get_slot_count()
        if count < 10:
            raise RuntimeError(f"当前仅有 {count} 个卡槽，无法应用十卡预设")
        if len(payload) < 10:
            raise RuntimeError("预设内容不足十卡")
        for item in payload[:10]:
            idx = int(item["index"])
            plant_type = int(item["plant_type"])
            imitater = bool(item["imitater"])
            self.set_slot_seed(idx, plant_type, imitater)

    def get_sun(self) -> int:
        proc, off = self._ensure()
        return proc.read_int32([off.lawn, off.board, off.sun])

    def set_sun(self, value: int) -> None:
        proc, off = self._ensure()
        ui = self.get_game_ui()
        if ui not in (2, 3):
            raise RuntimeError(f"当前 GameUI={ui}，不在战斗界面")
        proc.write_int32(value, [off.lawn, off.board, off.sun])

    def get_money(self) -> int:
        proc, off = self._ensure()
        user_data = proc.read_uint32([off.lawn, off.user_data])
        if user_data == 0:
            raise RuntimeError("未创建存档用户，无法读取金币")
        return proc.read_int32([off.lawn, off.user_data, off.money])

    def set_money(self, value: int) -> None:
        proc, off = self._ensure()
        user_data = proc.read_uint32([off.lawn, off.user_data])
        if user_data == 0:
            raise RuntimeError("未创建存档用户，无法写入金币")
        proc.write_int32(value, [off.lawn, off.user_data, off.money])

    def set_unlock_sun_limit(self, enabled: bool) -> None:
        proc, off = self._ensure()
        patch = off.unlock_sun_limit
        proc.write_bytes(patch.hack if enabled else patch.reset, [patch.addr])

    def set_placed_anywhere(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p1 = off.placed_anywhere
        p2 = off.placed_anywhere_preview
        proc.write_bytes(p1.hack if enabled else p1.reset, [p1.addr])
        proc.write_bytes(p2.hack if enabled else p2.reset, [p2.addr])

    def set_mushrooms_awake(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p = off.mushrooms_awake
        proc.write_bytes(p.hack if enabled else p.reset, [p.addr])

    def set_stop_spawning(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p = off.stop_spawning
        proc.write_bytes(p.hack if enabled else p.reset, [p.addr])

    def set_auto_collected(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p = off.auto_collected
        proc.write_bytes(p.hack if enabled else p.reset, [p.addr])

    def set_reload_instantly(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p = off.reload_instantly
        proc.write_bytes(p.hack if enabled else p.reset, [p.addr])

    def set_no_cooldown(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p1 = off.no_cooldown_1
        p2 = off.no_cooldown_2
        proc.write_bytes(p1.hack if enabled else p1.reset, [p1.addr])
        proc.write_bytes(p2.hack if enabled else p2.reset, [p2.addr])

    def set_not_drop_loot(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p = off.not_drop_loot
        proc.write_bytes(p.hack if enabled else p.reset, [p.addr])

    def set_lock_butter(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p = off.lock_butter
        proc.write_bytes(p.hack if enabled else p.reset, [p.addr])

    def set_no_crater(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p = off.no_crater
        proc.write_bytes(p.hack if enabled else p.reset, [p.addr])

    def set_no_ice_trail(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p1 = off.no_ice_trail_1
        p2 = off.no_ice_trail_2
        proc.write_bytes(p1.hack if enabled else p1.reset, [p1.addr])
        proc.write_bytes(p2.hack if enabled else p2.reset, [p2.addr])

    def set_stop_zombies(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p1 = off.stop_zombies_1
        p2 = off.stop_zombies_2
        proc.write_bytes(p1.hack if enabled else p1.reset, [p1.addr])
        proc.write_bytes(p2.hack if enabled else p2.reset, [p2.addr])

    def set_zombie_not_explode(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p1 = off.zombie_not_explode_1
        p2 = off.zombie_not_explode_2
        proc.write_bytes(p1.hack if enabled else p1.reset, [p1.addr])
        proc.write_bytes(p2.hack if enabled else p2.reset, [p2.addr])

    def set_no_fog(self, enabled: bool) -> None:
        proc, off = self._ensure()
        p = off.no_fog
        proc.write_bytes(p.hack if enabled else p.reset, [p.addr])
