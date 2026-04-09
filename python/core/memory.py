from __future__ import annotations

import ctypes
from ctypes import wintypes
from typing import Iterable

kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)

PROCESS_ALL_ACCESS = 0x001F0FFF

ReadProcessMemory = kernel32.ReadProcessMemory
ReadProcessMemory.argtypes = [
    wintypes.HANDLE,
    wintypes.LPCVOID,
    wintypes.LPVOID,
    ctypes.c_size_t,
    ctypes.POINTER(ctypes.c_size_t),
]
ReadProcessMemory.restype = wintypes.BOOL

WriteProcessMemory = kernel32.WriteProcessMemory
WriteProcessMemory.argtypes = [
    wintypes.HANDLE,
    wintypes.LPVOID,
    wintypes.LPCVOID,
    ctypes.c_size_t,
    ctypes.POINTER(ctypes.c_size_t),
]
WriteProcessMemory.restype = wintypes.BOOL

OpenProcess = kernel32.OpenProcess
OpenProcess.argtypes = [wintypes.DWORD, wintypes.BOOL, wintypes.DWORD]
OpenProcess.restype = wintypes.HANDLE

CloseHandle = kernel32.CloseHandle
CloseHandle.argtypes = [wintypes.HANDLE]
CloseHandle.restype = wintypes.BOOL

GetExitCodeProcess = kernel32.GetExitCodeProcess
GetExitCodeProcess.argtypes = [wintypes.HANDLE, ctypes.POINTER(wintypes.DWORD)]
GetExitCodeProcess.restype = wintypes.BOOL

STILL_ACTIVE = 259


class MemoryProcess:
    def __init__(self, pid: int) -> None:
        self.pid = pid
        self.handle = OpenProcess(PROCESS_ALL_ACCESS, False, pid)
        if not self.handle:
            err = ctypes.get_last_error()
            raise OSError(err, f"OpenProcess failed: {err}")

    def close(self) -> None:
        if self.handle:
            CloseHandle(self.handle)
            self.handle = None

    def is_alive(self) -> bool:
        if not self.handle:
            return False
        code = wintypes.DWORD()
        ok = GetExitCodeProcess(self.handle, ctypes.byref(code))
        return bool(ok and code.value == STILL_ACTIVE)

    def _resolve_address(self, chain: Iterable[int]) -> int:
        addrs = list(chain)
        if not addrs:
            raise ValueError("empty address chain")

        current = 0
        for i, addr in enumerate(addrs):
            target = current + addr
            if i == len(addrs) - 1:
                return target

            buf = ctypes.c_uint32()
            read = ctypes.c_size_t(0)
            ok = ReadProcessMemory(
                self.handle,
                ctypes.c_void_p(target),
                ctypes.byref(buf),
                ctypes.sizeof(buf),
                ctypes.byref(read),
            )
            if not ok or read.value != ctypes.sizeof(buf):
                raise RuntimeError(f"ReadProcessMemory failed at 0x{target:08X}")
            current = int(buf.value)

        raise RuntimeError("unreachable")

    def read_uint32(self, chain: Iterable[int]) -> int:
        target = self._resolve_address(chain)
        buf = ctypes.c_uint32()
        read = ctypes.c_size_t(0)
        ok = ReadProcessMemory(
            self.handle,
            ctypes.c_void_p(target),
            ctypes.byref(buf),
            ctypes.sizeof(buf),
            ctypes.byref(read),
        )
        if not ok or read.value != ctypes.sizeof(buf):
            raise RuntimeError(f"Read uint32 failed at 0x{target:08X}")
        return int(buf.value)

    def read_int32(self, chain: Iterable[int]) -> int:
        target = self._resolve_address(chain)
        buf = ctypes.c_int32()
        read = ctypes.c_size_t(0)
        ok = ReadProcessMemory(
            self.handle,
            ctypes.c_void_p(target),
            ctypes.byref(buf),
            ctypes.sizeof(buf),
            ctypes.byref(read),
        )
        if not ok or read.value != ctypes.sizeof(buf):
            raise RuntimeError(f"Read int32 failed at 0x{target:08X}")
        return int(buf.value)

    def read_bytes(self, chain: Iterable[int], size: int) -> bytes:
        target = self._resolve_address(chain)
        buf = (ctypes.c_ubyte * size)()
        read = ctypes.c_size_t(0)
        ok = ReadProcessMemory(
            self.handle,
            ctypes.c_void_p(target),
            ctypes.byref(buf),
            size,
            ctypes.byref(read),
        )
        if not ok or read.value != size:
            raise RuntimeError(f"Read bytes failed at 0x{target:08X}")
        return bytes(buf)

    def write_int32(self, value: int, chain: Iterable[int]) -> None:
        target = self._resolve_address(chain)
        buf = ctypes.c_int32(value)
        written = ctypes.c_size_t(0)
        ok = WriteProcessMemory(
            self.handle,
            ctypes.c_void_p(target),
            ctypes.byref(buf),
            ctypes.sizeof(buf),
            ctypes.byref(written),
        )
        if not ok or written.value != ctypes.sizeof(buf):
            raise RuntimeError(f"Write int32 failed at 0x{target:08X}")

    def write_bytes(self, data: bytes, chain: Iterable[int]) -> None:
        target = self._resolve_address(chain)
        size = len(data)
        buf = (ctypes.c_ubyte * size).from_buffer_copy(data)
        written = ctypes.c_size_t(0)
        ok = WriteProcessMemory(
            self.handle,
            ctypes.c_void_p(target),
            ctypes.byref(buf),
            size,
            ctypes.byref(written),
        )
        if not ok or written.value != size:
            raise RuntimeError(f"Write bytes failed at 0x{target:08X}")
