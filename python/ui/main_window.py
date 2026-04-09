from __future__ import annotations

import ctypes
import json
from pathlib import Path

from PySide6.QtCore import QLocale, QTimer
from PySide6.QtWidgets import (
    QCheckBox,
    QComboBox,
    QFileDialog,
    QFormLayout,
    QGridLayout,
    QGroupBox,
    QLabel,
    QLineEdit,
    QMainWindow,
    QMessageBox,
    QPushButton,
    QTabWidget,
    QVBoxLayout,
    QWidget,
)

from core.pvz_adapter import PvZAdapter

EN = [
    "Peashooter","Sunflower","Cherry Bomb","Wall-nut","Potato Mine","Snow Pea","Chomper","Repeater",
    "Puff-shroom","Sun-shroom","Fume-shroom","Grave Buster","Hypno-shroom","Scaredy-shroom","Ice-shroom","Doom-shroom",
    "Lily Pad","Squash","Threepeater","Tangle Kelp","Jalapeno","Spikeweed","Torchwood","Tall-nut",
    "Sea-shroom","Plantern","Cactus","Blover","Split Pea","Starfruit","Pumpkin","Magnet-shroom",
    "Cabbage-pult","Flower Pot","Kernel-pult","Coffee Bean","Garlic","Umbrella Leaf","Marigold","Melon-pult",
    "Gatling Pea","Twin Sunflower","Gloom-shroom","Cattail","Winter Melon","Gold Magnet","Spikerock","Cob Cannon",
]
ZH = [
    "豌豆射手","向日葵","樱桃炸弹","坚果","土豆地雷","寒冰射手","大嘴花","双发射手",
    "小喷菇","阳光菇","大喷菇","墓碑吞噬者","魅惑菇","胆小菇","寒冰菇","毁灭菇",
    "睡莲","倭瓜","三线射手","缠绕海草","火爆辣椒","地刺","火炬树桩","高坚果",
    "海蘑菇","路灯花","仙人掌","三叶草","分裂豆","杨桃","南瓜头","磁力菇",
    "卷心菜投手","花盆","玉米投手","咖啡豆","大蒜","叶子保护伞","金盏花","西瓜投手",
    "机枪射手","双子向日葵","忧郁菇","香蒲","冰西瓜","吸金磁","地刺王","玉米加农炮",
]

ZH_ZOMBIES = [
    "普通僵尸", "旗帜僵尸", "路障僵尸", "撑杆僵尸", "铁桶僵尸", "读报僵尸", "铁门僵尸", "橄榄球僵尸",
    "舞王僵尸", "伴舞僵尸", "鸭子救生圈僵尸", "潜水僵尸", "冰车僵尸", "雪橇车小队", "海豚骑士僵尸", "小丑僵尸",
    "气球僵尸", "矿工僵尸", "跳跳僵尸", "雪人僵尸", "蹦极僵尸", "扶梯僵尸", "投石车僵尸", "白眼巨人",
    "小鬼僵尸", "僵王博士", "豌豆僵尸", "坚果僵尸", "辣椒僵尸", "机枪豌豆僵尸", "倭瓜僵尸", "高坚果僵尸", "红眼巨人",
]


class MainWindow(QMainWindow):

    def __init__(self) -> None:
        super().__init__()
        self.setWindowTitle("PvZ Toolkit Python")
        self.adapter = PvZAdapter()
        self.loaded_slot_preset: list[dict] = []
        self.slot_count_cache = -1

        root = QWidget(self)
        self.setCentralWidget(root)
        lay = QVBoxLayout(root)

        self.status_label = QLabel("状态：未连接")
        lay.addWidget(self.status_label)

        conn = QGroupBox("连接设置")
        f = QFormLayout(conn)
        self.force_english_check = QCheckBox("强制英文偏移（测试）")
        self.force_profile_combo = QComboBox(); self.force_profile_combo.addItems(["1096-en", "1073-en", "1065-en", "1051-en"])
        self.auto_refresh_check = QCheckBox("自动刷新"); self.auto_refresh_check.setChecked(True); self.auto_refresh_check.stateChanged.connect(self.on_toggle_auto_refresh)
        b_attach = QPushButton("连接游戏"); b_attach.clicked.connect(self.on_attach)
        f.addRow(self.force_english_check); f.addRow("强制配置", self.force_profile_combo); f.addRow(self.auto_refresh_check); f.addRow(b_attach)
        lay.addWidget(conn)

        self.tabs = QTabWidget(); lay.addWidget(self.tabs)
        self.resource_tab, self.combat_tab, self.plant_tab = QWidget(), QWidget(), QWidget()
        self.tabs.addTab(self.resource_tab, "资源"); self.tabs.addTab(self.combat_tab, "战场"); self.tabs.addTab(self.plant_tab, "植物")
        self._build_resource_tab(); self._build_combat_tab(); self._build_plant_tab()

        self._z_prev_down = False

        self.timer = QTimer(self); self.timer.setInterval(700); self.timer.timeout.connect(self.on_timer); self.timer.start()
        self.hotkey_timer = QTimer(self); self.hotkey_timer.setInterval(30); self.hotkey_timer.timeout.connect(self.on_hotkey_poll); self.hotkey_timer.start()

    def _is_zh(self) -> bool:
        return (not self.force_english_check.isChecked()) and QLocale.system().language() == QLocale.Language.Chinese

    def _name(self, t: int) -> str:
        if 0 <= t < 48: return ZH[t] if self._is_zh() else EN[t]
        return f"Unknown({t})"

    def _status(self, text: str) -> None:
        self.status_label.setText(f"状态：{text}")

    def _warn(self, title: str, text: str) -> None:
        self._status(text); QMessageBox.warning(self, title, text)

    def on_hotkey_poll(self) -> None:
        z_now = bool(ctypes.windll.user32.GetAsyncKeyState(ord("Z")) & 0x8000)
        if z_now and not self._z_prev_down:
            self.on_apply_loaded_slot_preset()
        self._z_prev_down = z_now

    def _rebuild_plant_combo(self) -> None:
        cur = self.slot_type_combo.currentData() if hasattr(self, "slot_type_combo") else 0
        self.slot_type_combo.blockSignals(True); self.slot_type_combo.clear()
        for i in range(48): self.slot_type_combo.addItem(f"[{i}] {self._name(i)}", i)
        if isinstance(cur, int) and 0 <= cur < 48: self.slot_type_combo.setCurrentIndex(cur)
        self.slot_type_combo.blockSignals(False)

    def _render_summary(self, payload: list[dict]) -> None:
        lines = ["十格摘要："]
        for i, it in enumerate(payload[:10]):
            t = int(it["plant_type"]); lines.append(f"第{i+1}格 = {self._name(t)} [{t}] / {'模仿者' if bool(it['imitater']) else '普通'}")
        self.preset_summary.setText("\n".join(lines))

    def _build_resource_tab(self) -> None:
        lay = QVBoxLayout(self.resource_tab)
        self.sun_label = QLabel("阳光: --"); self.money_label = QLabel("金币: --")
        self.sun_input = QLineEdit(); self.money_input = QLineEdit()
        b_rs = QPushButton("读取阳光"); b_ws = QPushButton("写入阳光"); b_rm = QPushButton("读取金币"); b_wm = QPushButton("写入金币")
        self.sun_limit = QCheckBox("阳光无上限")
        self.auto_collected = QCheckBox("自动收集")
        self.not_drop_loot = QCheckBox("不掉落物品")
        b_rs.clicked.connect(self.on_refresh_sun); b_ws.clicked.connect(self.on_set_sun); b_rm.clicked.connect(self.on_refresh_money); b_wm.clicked.connect(self.on_set_money)
        self.sun_limit.stateChanged.connect(self.on_toggle_sun_limit)
        self.auto_collected.stateChanged.connect(self.on_toggle_auto_collected)
        self.not_drop_loot.stateChanged.connect(self.on_toggle_not_drop_loot)
        for w in [self.sun_label, self.sun_input, b_rs, b_ws, self.money_label, self.money_input, b_rm, b_wm, self.sun_limit, self.auto_collected, self.not_drop_loot]: lay.addWidget(w)

    def _build_combat_tab(self) -> None:
        lay = QVBoxLayout(self.combat_tab)
        self.ui_label = QLabel("GameUI: --"); self.mode_label = QLabel("Mode: --"); self.scene_label = QLabel("Scene: --")
        self.scene_combo = QComboBox(); self.scene_combo.addItems(["0", "1", "2", "3", "4", "5"])
        b_ref = QPushButton("刷新"); b_set = QPushButton("写入场景")
        self.no_fog = QCheckBox("无雾")
        self.no_fog.stateChanged.connect(self.on_toggle_no_fog)
        b_ref.clicked.connect(self.on_refresh_combat); b_set.clicked.connect(self.on_set_scene)
        for w in [self.ui_label, self.mode_label, self.scene_label, b_ref, self.scene_combo, b_set, self.no_fog]: lay.addWidget(w)

        g_put = QGroupBox("投放（测试）")
        gp = QFormLayout(g_put)
        self.put_row_combo = QComboBox(); self.put_row_combo.addItems(["全部", "1", "2", "3", "4", "5", "6"])
        self.put_col_combo = QComboBox(); self.put_col_combo.addItems(["全部", "1", "2", "3", "4", "5", "6", "7", "8", "9"])
        self.put_plant_combo = QComboBox()
        for i in range(48): self.put_plant_combo.addItem(f"[{i}] {self._name(i)}", i)
        self.put_plant_im = QCheckBox("模仿者")
        self.put_zombie_combo = QComboBox()
        for i, name in enumerate(ZH_ZOMBIES): self.put_zombie_combo.addItem(f"{name} [ID:{i}]", i)
        b_put_plant = QPushButton("放植物")
        b_put_zombie = QPushButton("放僵尸")
        b_put_ladder = QPushButton("放梯子")
        b_put_grave = QPushButton("放墓碑")
        b_put_plant.clicked.connect(self.on_put_plant)
        b_put_zombie.clicked.connect(self.on_put_zombie)
        b_put_ladder.clicked.connect(self.on_put_ladder)
        b_put_grave.clicked.connect(self.on_put_grave)
        gp.addRow("行", self.put_row_combo)
        gp.addRow("列", self.put_col_combo)
        gp.addRow("植物", self.put_plant_combo)
        gp.addRow(self.put_plant_im)
        gp.addRow("僵尸", self.put_zombie_combo)
        gp.addRow(b_put_plant)
        gp.addRow(b_put_zombie)
        gp.addRow(b_put_ladder)
        gp.addRow(b_put_grave)
        lay.addWidget(g_put)

    def _build_plant_tab(self) -> None:
        lay = QVBoxLayout(self.plant_tab)
        self.free_planting = QCheckBox("免费种植"); self.free_planting.stateChanged.connect(self.on_toggle_free); lay.addWidget(self.free_planting)
        self.placed_anywhere = QCheckBox("任意种植（含预览）")
        self.placed_anywhere.stateChanged.connect(self.on_toggle_placed_anywhere)
        self.mushrooms_awake = QCheckBox("蘑菇唤醒")
        self.mushrooms_awake.stateChanged.connect(self.on_toggle_mushrooms_awake)
        self.stop_spawning = QCheckBox("停止出怪")
        self.stop_spawning.stateChanged.connect(self.on_toggle_stop_spawning)
        self.reload_instantly = QCheckBox("立即装填")
        self.reload_instantly.stateChanged.connect(self.on_toggle_reload_instantly)
        self.no_cooldown = QCheckBox("无冷却")
        self.no_cooldown.stateChanged.connect(self.on_toggle_no_cooldown)
        self.lock_butter = QCheckBox("锁定黄油")
        self.lock_butter.stateChanged.connect(self.on_toggle_lock_butter)
        self.no_crater = QCheckBox("无坑洞")
        self.no_crater.stateChanged.connect(self.on_toggle_no_crater)
        self.no_ice_trail = QCheckBox("无冰道")
        self.no_ice_trail.stateChanged.connect(self.on_toggle_no_ice_trail)
        self.stop_zombies = QCheckBox("停止僵尸")
        self.stop_zombies.stateChanged.connect(self.on_toggle_stop_zombies)
        self.zombie_not_explode = QCheckBox("僵尸不爆炸")
        self.zombie_not_explode.stateChanged.connect(self.on_toggle_zombie_not_explode)

        g_switches = QGroupBox("战场开关")
        gls = QGridLayout(g_switches)
        switches = [
            self.placed_anywhere,
            self.mushrooms_awake,
            self.stop_spawning,
            self.reload_instantly,
            self.no_cooldown,
            self.lock_butter,
            self.no_crater,
            self.no_ice_trail,
            self.stop_zombies,
            self.zombie_not_explode,
        ]
        for i, w in enumerate(switches):
            gls.addWidget(w, i // 2, i % 2)
        lay.addWidget(g_switches)

        g1 = QGroupBox("卡槽编辑"); gl1 = QVBoxLayout(g1)
        self.slot_count_label = QLabel("卡槽数量: --")
        self.slot_choice = QComboBox(); self.slot_choice.currentIndexChanged.connect(self.on_slot_changed)
        self.slot_type_combo = QComboBox(); self._rebuild_plant_combo()
        self.slot_im = QCheckBox("模仿者")
        b_read = QPushButton("读取本格"); b_write = QPushButton("应用本格")
        b_read.clicked.connect(self.on_read_slot_one); b_write.clicked.connect(self.on_apply_slot_one)
        for w in [self.slot_count_label, self.slot_choice, self.slot_type_combo, self.slot_im, b_read, b_write]: gl1.addWidget(w)
        lay.addWidget(g1)

        g2 = QGroupBox("十卡预设"); gl2 = QVBoxLayout(g2)
        self.preset_info = QLabel("未加载预设")
        self.preset_summary = QLabel("十格摘要：\n(暂无)"); self.preset_summary.setWordWrap(True)
        b_refresh = QPushButton("当前十卡一键刷新到界面")
        b_save = QPushButton("保存当前十卡"); b_load = QPushButton("读取预设文件"); b_apply = QPushButton("应用已读取预设 (Z)")
        b_refresh.clicked.connect(self.on_refresh_current_ten_to_ui)
        b_save.clicked.connect(self.on_save_slot_preset); b_load.clicked.connect(self.on_load_slot_preset); b_apply.clicked.connect(self.on_apply_loaded_slot_preset)
        b_apply.setShortcut("Z")
        for w in [self.preset_info, self.preset_summary, b_refresh, b_save, b_load, b_apply]: gl2.addWidget(w)
        lay.addWidget(g2)

    def on_attach(self) -> None:
        r = self.adapter.attach(self.force_english_check.isChecked(), self.force_profile_combo.currentText())
        self._status(r.message)
        if not r.ok: QMessageBox.warning(self, "连接失败", r.message); return
        self._rebuild_plant_combo(); self.refresh_slot_count_label(); self.on_timer()

    def on_toggle_auto_refresh(self) -> None:
        self.timer.start() if self.auto_refresh_check.isChecked() else self.timer.stop()

    def on_timer(self) -> None:
        if not self.adapter.is_ready(): return
        try:
            self.sun_label.setText(f"阳光: {self.adapter.get_sun()}")
            self.money_label.setText(f"金币: {self.adapter.get_money()}")
            self.ui_label.setText(f"GameUI: {self.adapter.get_game_ui()}")
            self.mode_label.setText(f"Mode: {self.adapter.get_game_mode()}")
            self.scene_label.setText(f"Scene: {self.adapter.get_scene()}")
            self.refresh_slot_count_label()
        except Exception:
            pass

    def refresh_slot_count_label(self) -> None:
        try:
            c = self.adapter.get_slot_count(); self.slot_count_label.setText(f"卡槽数量: {c}")
            if c != self.slot_count_cache:
                cur = self.slot_choice.currentIndex()
                self.slot_choice.blockSignals(True)
                self.slot_choice.clear(); self.slot_choice.addItems([f"第{i+1}格" for i in range(c)])
                if c > 0: self.slot_choice.setCurrentIndex(min(max(cur, 0), c - 1))
                self.slot_choice.blockSignals(False)
                self.slot_count_cache = c
        except Exception:
            self.slot_count_label.setText("卡槽数量: --")

    def on_slot_changed(self) -> None:
        if self.adapter.is_ready() and self.slot_choice.count() > 0: self.on_read_slot_one()

    def on_refresh_sun(self) -> None:
        try: self.sun_label.setText(f"阳光: {self.adapter.get_sun()}")
        except Exception as ex: self._warn("读取失败", str(ex))

    def on_set_sun(self) -> None:
        try: self.adapter.set_sun(int(self.sun_input.text().strip()))
        except Exception as ex: self._warn("写入失败", str(ex))

    def on_refresh_money(self) -> None:
        try: self.money_label.setText(f"金币: {self.adapter.get_money()}")
        except Exception as ex: self._warn("读取失败", str(ex))

    def on_set_money(self) -> None:
        try: self.adapter.set_money(int(self.money_input.text().strip()))
        except Exception as ex: self._warn("写入失败", str(ex))

    def on_toggle_sun_limit(self) -> None:
        try: self.adapter.set_unlock_sun_limit(self.sun_limit.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_auto_collected(self) -> None:
        try: self.adapter.set_auto_collected(self.auto_collected.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_not_drop_loot(self) -> None:
        try: self.adapter.set_not_drop_loot(self.not_drop_loot.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_refresh_combat(self) -> None:
        try:
            self.ui_label.setText(f"GameUI: {self.adapter.get_game_ui()}")
            self.mode_label.setText(f"Mode: {self.adapter.get_game_mode()}")
            self.scene_label.setText(f"Scene: {self.adapter.get_scene()}")
        except Exception as ex: self._warn("读取失败", str(ex))

    def on_set_scene(self) -> None:
        try: self.adapter.set_scene(self.scene_combo.currentIndex())
        except Exception as ex: self._warn("写入失败", str(ex))

    def _put_row_col(self) -> tuple[int, int]:
        row_idx = self.put_row_combo.currentIndex()
        col_idx = self.put_col_combo.currentIndex()
        row = -1 if row_idx == 0 else row_idx - 1
        col = -1 if col_idx == 0 else col_idx - 1
        return row, col

    def on_put_plant(self) -> None:
        try:
            row, col = self._put_row_col()
            self.adapter.put_plant(row, col, int(self.put_plant_combo.currentData()), self.put_plant_im.isChecked())
        except Exception as ex: self._warn("放置失败", str(ex))

    def on_put_zombie(self) -> None:
        try:
            row, col = self._put_row_col()
            zombie_type = int(self.put_zombie_combo.currentData())
            self.adapter.put_zombie(row, col, zombie_type)
        except Exception as ex: self._warn("放置失败", str(ex))

    def on_put_ladder(self) -> None:
        try:
            row, col = self._put_row_col()
            self.adapter.put_ladder(row, col)
        except Exception as ex: self._warn("放置失败", str(ex))

    def on_put_grave(self) -> None:
        try:
            row, col = self._put_row_col()
            self.adapter.put_grave(row, col)
        except Exception as ex: self._warn("放置失败", str(ex))

    def on_toggle_free(self) -> None:
        try: self.adapter.set_free_planting(self.free_planting.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_placed_anywhere(self) -> None:
        try: self.adapter.set_placed_anywhere(self.placed_anywhere.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_mushrooms_awake(self) -> None:
        try: self.adapter.set_mushrooms_awake(self.mushrooms_awake.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_stop_spawning(self) -> None:
        try: self.adapter.set_stop_spawning(self.stop_spawning.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_reload_instantly(self) -> None:
        try: self.adapter.set_reload_instantly(self.reload_instantly.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_no_cooldown(self) -> None:
        try: self.adapter.set_no_cooldown(self.no_cooldown.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_lock_butter(self) -> None:
        try: self.adapter.set_lock_butter(self.lock_butter.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_no_crater(self) -> None:
        try: self.adapter.set_no_crater(self.no_crater.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_no_ice_trail(self) -> None:
        try: self.adapter.set_no_ice_trail(self.no_ice_trail.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_stop_zombies(self) -> None:
        try: self.adapter.set_stop_zombies(self.stop_zombies.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_zombie_not_explode(self) -> None:
        try: self.adapter.set_zombie_not_explode(self.zombie_not_explode.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_toggle_no_fog(self) -> None:
        try: self.adapter.set_no_fog(self.no_fog.isChecked())
        except Exception as ex: self._warn("修改失败", str(ex))

    def on_read_slot_one(self) -> None:
        try:
            t, im = self.adapter.get_slot_seed(self.slot_choice.currentIndex())
            self.slot_type_combo.setCurrentIndex(max(0, min(47, t))); self.slot_im.setChecked(im)
        except Exception as ex: self._warn("读取失败", str(ex))

    def on_apply_slot_one(self) -> None:
        try: self.adapter.set_slot_seed(self.slot_choice.currentIndex(), int(self.slot_type_combo.currentData()), self.slot_im.isChecked())
        except Exception as ex: self._warn("写入失败", str(ex))

    def on_refresh_current_ten_to_ui(self) -> None:
        try:
            payload = self.adapter.read_slot_preset_payload(); self._render_summary(payload); self.preset_info.setText("已刷新当前十卡")
        except Exception as ex: self._warn("刷新失败", str(ex))

    def on_save_slot_preset(self) -> None:
        try:
            payload = self.adapter.read_slot_preset_payload()
            path, _ = QFileDialog.getSaveFileName(self, "保存卡槽预设", "slot_preset.json", "JSON (*.json)")
            if not path: return
            Path(path).write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")
            self.preset_info.setText(f"已保存十卡预设（{len(payload)} 格）"); self._render_summary(payload)
        except Exception as ex: self._warn("保存失败", str(ex))

    def on_load_slot_preset(self) -> None:
        try:
            path, _ = QFileDialog.getOpenFileName(self, "读取卡槽预设", "", "JSON (*.json)")
            if not path: return
            data = json.loads(Path(path).read_text(encoding="utf-8"))
            if not isinstance(data, list): raise RuntimeError("预设文件格式错误")
            self.loaded_slot_preset = data
            self.preset_info.setText(f"已加载预设（{len(data)} 格）"); self._render_summary(self.loaded_slot_preset)
        except Exception as ex: self._warn("读取失败", str(ex))

    def on_apply_loaded_slot_preset(self) -> None:
        try:
            if not self.loaded_slot_preset: raise RuntimeError("请先读取预设文件")
            self.adapter.apply_slot_preset_payload(self.loaded_slot_preset)
            self.preset_info.setText("已应用十卡预设"); self._render_summary(self.loaded_slot_preset); self.on_read_slot_one()
        except Exception as ex: self._warn("应用失败", str(ex))
