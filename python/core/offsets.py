from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class BytePatch:
    addr: int
    hack: bytes
    reset: bytes


@dataclass(frozen=True)
class VersionOffsets:
    name: str
    timestamp: int
    lawn: int
    board: int
    slot: int
    slot_count: int
    slot_seed_type: int
    slot_seed_type_im: int
    game_ui: int
    game_mode: int
    scene: int
    free_planting: int
    sun: int
    user_data: int
    money: int
    unlock_sun_limit: BytePatch
    placed_anywhere: BytePatch
    placed_anywhere_preview: BytePatch
    mushrooms_awake: BytePatch
    stop_spawning: BytePatch
    auto_collected: BytePatch
    reload_instantly: BytePatch
    no_cooldown_1: BytePatch
    no_cooldown_2: BytePatch
    not_drop_loot: BytePatch
    lock_butter: BytePatch
    no_crater: BytePatch
    no_ice_trail_1: BytePatch
    no_ice_trail_2: BytePatch
    stop_zombies_1: BytePatch
    stop_zombies_2: BytePatch
    zombie_not_explode_1: BytePatch
    zombie_not_explode_2: BytePatch
    no_fog: BytePatch
    challenge: int
    call_put_plant: int
    call_put_zombie: int
    call_put_grave: int
    call_put_ladder: int


OFFSETS_1051_EN = VersionOffsets(
    name="1.0.0.1051 (en)",
    timestamp=0x49ECF563,
    lawn=0x6A9EC0,
    board=0x768,
    slot=0x144,
    slot_count=0x24,
    slot_seed_type=0x5C,
    slot_seed_type_im=0x60,
    game_ui=0x7FC,
    game_mode=0x7F8,
    scene=0x554C,
    free_planting=0x814,
    sun=0x5560,
    user_data=0x82C,
    money=0x28,
    unlock_sun_limit=BytePatch(addr=0x00430A23, hack=b"\xEB", reset=b"\x7E"),
    placed_anywhere=BytePatch(addr=0x0040FE30, hack=b"\x81", reset=b"\x84"),
    placed_anywhere_preview=BytePatch(addr=0x00438E40, hack=b"\xEB", reset=b"\x74"),
    mushrooms_awake=BytePatch(addr=0x0045DE8E, hack=b"\xEB", reset=b"\x74"),
    stop_spawning=BytePatch(addr=0x004265DC, hack=b"\xEB", reset=b"\x74"),
    auto_collected=BytePatch(addr=0x0043158F, hack=b"\xEB", reset=b"\x75"),
    reload_instantly=BytePatch(addr=0x0046103B, hack=b"\x80", reset=b"\x85"),
    no_cooldown_1=BytePatch(addr=0x00461565, hack=b"\x70", reset=b"\x75"),
    no_cooldown_2=BytePatch(addr=0x00461E37, hack=b"\x80", reset=b"\x85"),
    not_drop_loot=BytePatch(addr=0x00530276, hack=b"\x66", reset=b"\x5B"),
    lock_butter=BytePatch(addr=0x0045F1EC, hack=b"\x70", reset=b"\x75"),
    no_crater=BytePatch(addr=0x0041D79E, hack=b"\x70", reset=b"\x75"),
    no_ice_trail_1=BytePatch(addr=0x0052A7B0, hack=b"\xC3", reset=b"\x51"),
    no_ice_trail_2=BytePatch(addr=0x0041F79A, hack=b"\xEB", reset=b"\x75"),
    stop_zombies_1=BytePatch(addr=0x0052AB2B, hack=b"\x54", reset=b"\x64"),
    stop_zombies_2=BytePatch(addr=0x0052AB34, hack=b"\x54", reset=b"\x44"),
    zombie_not_explode_1=BytePatch(addr=0x00526AFC, hack=b"\x81", reset=b"\x8F"),
    zombie_not_explode_2=BytePatch(addr=0x005275DD, hack=b"\x81", reset=b"\x85"),
    no_fog=BytePatch(addr=0x0041A68D, hack=b"\x31\xD2", reset=b"\x3B\xF2"),
    challenge=0x160,
    call_put_plant=0x0040D120,
    call_put_zombie=0x0042A0F0,
    call_put_grave=0x00426620,
    call_put_ladder=0x00408F40,
)

OFFSETS_1065_EN = VersionOffsets(
    name="1.2.0.1065 (en)",
    timestamp=0x4A37D6AF,
    lawn=0x6A9EC0,
    board=0x768,
    slot=0x144,
    slot_count=0x24,
    slot_seed_type=0x5C,
    slot_seed_type_im=0x60,
    game_ui=0x7FC,
    game_mode=0x7F8,
    scene=0x554C,
    free_planting=0x814,
    sun=0x5560,
    user_data=0x82C,
    money=0x28,
    unlock_sun_limit=BytePatch(addr=0x00430A83, hack=b"\xEB", reset=b"\x7E"),
    placed_anywhere=BytePatch(addr=0x0040FE20, hack=b"\x81", reset=b"\x84"),
    placed_anywhere_preview=BytePatch(addr=0x00438EB0, hack=b"\xEB", reset=b"\x74"),
    mushrooms_awake=BytePatch(addr=0x0045DF8E, hack=b"\xEB", reset=b"\x74"),
    stop_spawning=BytePatch(addr=0x0042663C, hack=b"\xEB", reset=b"\x74"),
    auto_collected=BytePatch(addr=0x004315EF, hack=b"\xEB", reset=b"\x75"),
    reload_instantly=BytePatch(addr=0x004611BB, hack=b"\x80", reset=b"\x85"),
    no_cooldown_1=BytePatch(addr=0x004616E5, hack=b"\x70", reset=b"\x75"),
    no_cooldown_2=BytePatch(addr=0x00461FB7, hack=b"\x80", reset=b"\x85"),
    not_drop_loot=BytePatch(addr=0x005305C6, hack=b"\x66", reset=b"\x5B"),
    lock_butter=BytePatch(addr=0x0045F2EC, hack=b"\x70", reset=b"\x75"),
    no_crater=BytePatch(addr=0x0041D7CE, hack=b"\x70", reset=b"\x75"),
    no_ice_trail_1=BytePatch(addr=0x0052AB00, hack=b"\xC3", reset=b"\x51"),
    no_ice_trail_2=BytePatch(addr=0x0041F7FA, hack=b"\xEB", reset=b"\x75"),
    stop_zombies_1=BytePatch(addr=0x0052AE7B, hack=b"\x54", reset=b"\x64"),
    stop_zombies_2=BytePatch(addr=0x0052AE84, hack=b"\x54", reset=b"\x44"),
    zombie_not_explode_1=BytePatch(addr=0x00526E4C, hack=b"\x81", reset=b"\x8F"),
    zombie_not_explode_2=BytePatch(addr=0x0052792D, hack=b"\x81", reset=b"\x85"),
    no_fog=BytePatch(addr=0x0041A6AD, hack=b"\x31\xD2", reset=b"\x3B\xF2"),
    challenge=0x160,
    call_put_plant=0x0040D130,
    call_put_zombie=0x0042A150,
    call_put_grave=0x00426680,
    call_put_ladder=0x00408F50,
)

OFFSETS_1073_EN = VersionOffsets(
    name="GOTY 1.2.0.1073 (en)",
    timestamp=0x4C2E3453,
    lawn=0x729670,
    board=0x868,
    slot=0x15C,
    slot_count=0x24,
    slot_seed_type=0x5C,
    slot_seed_type_im=0x60,
    game_ui=0x91C,
    game_mode=0x918,
    scene=0x5564,
    free_planting=0x934,
    sun=0x5578,
    user_data=0x94C,
    money=0x50,
    unlock_sun_limit=BytePatch(addr=0x0041E6F5, hack=b"\xEB", reset=b"\x7E"),
    placed_anywhere=BytePatch(addr=0x004127F0, hack=b"\x81", reset=b"\x84"),
    placed_anywhere_preview=BytePatch(addr=0x0043C030, hack=b"\xEB", reset=b"\x74"),
    mushrooms_awake=BytePatch(addr=0x004617C2, hack=b"\xEB", reset=b"\x74"),
    stop_spawning=BytePatch(addr=0x004290DC, hack=b"\xEB", reset=b"\x74"),
    auto_collected=BytePatch(addr=0x004342F2, hack=b"\xEB", reset=b"\x75"),
    reload_instantly=BytePatch(addr=0x00464A0B, hack=b"\x80", reset=b"\x85"),
    no_cooldown_1=BytePatch(addr=0x00464F25, hack=b"\x70", reset=b"\x75"),
    no_cooldown_2=BytePatch(addr=0x00465817, hack=b"\x80", reset=b"\x85"),
    not_drop_loot=BytePatch(addr=0x00540C06, hack=b"\x66", reset=b"\x5B"),
    lock_butter=BytePatch(addr=0x00462B42, hack=b"\x70", reset=b"\x75"),
    no_crater=BytePatch(addr=0x0042057D, hack=b"\x70", reset=b"\x75"),
    no_ice_trail_1=BytePatch(addr=0x0053B0B0, hack=b"\xC3", reset=b"\x51"),
    no_ice_trail_2=BytePatch(addr=0x004222EA, hack=b"\xEB", reset=b"\x75"),
    stop_zombies_1=BytePatch(addr=0x0053B433, hack=b"\x54", reset=b"\x64"),
    stop_zombies_2=BytePatch(addr=0x0053B43C, hack=b"\x54", reset=b"\x44"),
    zombie_not_explode_1=BytePatch(addr=0x0053718C, hack=b"\x81", reset=b"\x8F"),
    zombie_not_explode_2=BytePatch(addr=0x00537C6D, hack=b"\x81", reset=b"\x85"),
    no_fog=BytePatch(addr=0x0041D17D, hack=b"\x31\xD2", reset=b"\x3B\xF2"),
    challenge=0x160 + 0x18,
    call_put_plant=0x0040FA10,
    call_put_zombie=0x0042CC90,
    call_put_grave=0x00429120,
    call_put_ladder=0x0040B870,
)

OFFSETS_1096_EN = VersionOffsets(
    name="GOTY 1.2.0.1096 (en)",
    timestamp=0x4D02B058,
    lawn=0x731C50,
    board=0x868,
    slot=0x15C,
    slot_count=0x24,
    slot_seed_type=0x5C,
    slot_seed_type_im=0x60,
    game_ui=0x91C,
    game_mode=0x918,
    scene=0x5564,
    free_planting=0x934,
    sun=0x5578,
    user_data=0x94C,
    money=0x54,
    unlock_sun_limit=BytePatch(addr=0x0041F4E5, hack=b"\xEB", reset=b"\x7E"),
    placed_anywhere=BytePatch(addr=0x00413350, hack=b"\x81", reset=b"\x84"),
    placed_anywhere_preview=BytePatch(addr=0x0043D100, hack=b"\xEB", reset=b"\x74"),
    mushrooms_awake=BytePatch(addr=0x004641A2, hack=b"\xEB", reset=b"\x74"),
    stop_spawning=BytePatch(addr=0x0042A12C, hack=b"\xEB", reset=b"\x74"),
    auto_collected=BytePatch(addr=0x004352F2, hack=b"\xEB", reset=b"\x75"),
    reload_instantly=BytePatch(addr=0x004673EB, hack=b"\x80", reset=b"\x85"),
    no_cooldown_1=BytePatch(addr=0x00467905, hack=b"\x70", reset=b"\x75"),
    no_cooldown_2=BytePatch(addr=0x004681F7, hack=b"\x80", reset=b"\x85"),
    not_drop_loot=BytePatch(addr=0x00544D26, hack=b"\x66", reset=b"\x5B"),
    lock_butter=BytePatch(addr=0x00465522, hack=b"\x70", reset=b"\x75"),
    no_crater=BytePatch(addr=0x0042136D, hack=b"\x70", reset=b"\x75"),
    no_ice_trail_1=BytePatch(addr=0x0053F1B0, hack=b"\xC3", reset=b"\x51"),
    no_ice_trail_2=BytePatch(addr=0x0042333A, hack=b"\xEB", reset=b"\x75"),
    stop_zombies_1=BytePatch(addr=0x0053F533, hack=b"\x54", reset=b"\x64"),
    stop_zombies_2=BytePatch(addr=0x0053F53C, hack=b"\x54", reset=b"\x44"),
    zombie_not_explode_1=BytePatch(addr=0x0053B2EC, hack=b"\x81", reset=b"\x8F"),
    zombie_not_explode_2=BytePatch(addr=0x0053BDCD, hack=b"\x81", reset=b"\x85"),
    no_fog=BytePatch(addr=0x0041DF4D, hack=b"\x31\xD2", reset=b"\x3B\xF2"),
    challenge=0x160 + 0x18,
    call_put_plant=0x004105A0,
    call_put_zombie=0x0042DCE0,
    call_put_grave=0x0042A170,
    call_put_ladder=0x0040C420,
)

VERSIONS_BY_TIMESTAMP = {
    OFFSETS_1051_EN.timestamp: OFFSETS_1051_EN,
    OFFSETS_1065_EN.timestamp: OFFSETS_1065_EN,
    OFFSETS_1073_EN.timestamp: OFFSETS_1073_EN,
    OFFSETS_1096_EN.timestamp: OFFSETS_1096_EN,
}

KNOWN_VERSION_NAMES = {
    0x49ECF563: "1.0.0.1051 (en)",
    0x4A37D6AF: "1.2.0.1065 (en)",
    0x4A5B7963: "1.0.4.7924 (es)",
    0x4C237519: "1.0.7.3556 (es)",
    0x4CE4C3D6: "1.0.7.3467 (ru)",
    0x4C2E3453: "GOTY 1.2.0.1073 (en)",
    0x4D02B058: "GOTY 1.2.0.1096 (en)",
    0x4CA31BAA: "GOTY 1.2.0.1093 (de/es/fr/it)",
    0x4C563DE1: "GOTY 1.1.0.1056 (zh)",
    0x4CC8E5F8: "GOTY 1.1.0.1056 (ja)",
    0x4FCD7BE2: "GOTY 1.1.0.1056 (zh 2012-06)",
    0x5003D437: "GOTY 1.1.0.1056 (zh 2012-07)",
    0x49359C21: "BETA 0.1.1.1014 (en)",
    0x499A6204: "BETA 0.9.9.1029 (en)",
}

FORCE_ENGLISH_PROFILES = {
    "1051-en": OFFSETS_1051_EN,
    "1065-en": OFFSETS_1065_EN,
    "1073-en": OFFSETS_1073_EN,
    "1096-en": OFFSETS_1096_EN,
}

WINDOW_TITLES = [
    "Plants vs. Zombies",
    "Plants vs. Zombies 1.2.0.1073",
    "Plants vs. Zombies 1.2.0.1073 RELEASE",
    "Plants vs. Zombies GOTY",
    "Pflanzen gegen Zombies 1.2.0.1093",
    "Plantas contra Zombis 1.2.0.1093",
    "Plantes contre Zombies 1.2.0.1093",
    "Piante contro zombi 1.2.0.1093",
    "Bloom & Doom BETA 0.1.1.1014",
    "Plants vs. Zombies BETA 0.9.9.1029",
]

PROCESS_EXE_NAMES = {
    "plantsvszombies.exe",
    "popcapgame1.exe",
    "pvz.exe",
}
