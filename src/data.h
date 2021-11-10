
#pragma once

#include <map>
#include <vector>
#include <array>

namespace Pt
{

#define PVZ_NOT_FOUND 0
#define PVZ_OPEN_ERROR -1
#define PVZ_UNSUPPORTED 1

#define PVZ_BETA_0_1_1_1014_EN 901
#define PVZ_BETA_0_9_9_1029_EN 902

#define PVZ_1_0_0_1051_EN 1001
#define PVZ_1_2_0_1065_EN 1002

#define PVZ_1_0_4_7924_ES 1003
#define PVZ_1_0_7_3556_ES 1004
#define PVZ_1_0_7_3467_RU 1005

#define PVZ_1_2_0_1073_EN 2001
#define PVZ_1_2_0_1096_EN 2002
#define PVZ_1_2_0_1093_DE_ES_FR_IT 2003

#define PVZ_1_1_0_1056_ZH 2004
#define PVZ_1_1_0_1056_JA 2005
#define PVZ_1_1_0_1056_ZH_2012_06 2006
#define PVZ_1_1_0_1056_ZH_2012_07 2007

// 单独的一个 hack
// 包括 类型, 数目, 地址, 修改值, 原始值
// 一个功能的实现可能需要多个 hack
// 地址为 0 / -1 时忽略
template <typename T, size_t size>
struct HACK
{
    uintptr_t mem_addr;
    std::array<T, size> hack_value;
    std::array<T, size> reset_value;
};

// 用来保存不同版本的内存基址数据
struct PVZ_DATA
{
    uintptr_t path;
    uintptr_t lawn;

    uintptr_t frame_duration;

    uintptr_t board;

    uintptr_t zombie;
    uintptr_t zombie_status;
    uintptr_t zombie_dead;
    uintptr_t zombie_count_max;

    uintptr_t plant;
    uintptr_t plant_row;
    uintptr_t plant_type;
    uintptr_t plant_col;
    uintptr_t plant_imitater;
    uintptr_t plant_dead;
    uintptr_t plant_squished;
    uintptr_t plant_asleep;
    uintptr_t plant_count_max;
    uintptr_t plant_next_pos;

    uintptr_t lawn_mower;
    uintptr_t lawn_mower_dead;
    uintptr_t lawn_mower_count_max;
    uintptr_t lawn_mower_count;

    uintptr_t grid_item;
    uintptr_t grid_item_type;
    uintptr_t grid_item_col;
    uintptr_t grid_item_row;
    uintptr_t grid_item_dead;
    uintptr_t grid_item_count_max;

    uintptr_t cursor;
    uintptr_t cursor_grab;

    uintptr_t slot;
    uintptr_t slot_count;
    uintptr_t slot_seed_cd_past;
    uintptr_t slot_seed_cd_total;
    uintptr_t slot_seed_type;
    uintptr_t slot_seed_type_im;

    uintptr_t cut_scene;

    uintptr_t challenge;
    uintptr_t endless_rounds;

    uintptr_t game_paused;
    uintptr_t block_type;
    uintptr_t row_type;
    uintptr_t ice_trail_cd;
    uintptr_t spawn_list;
    uintptr_t spawn_type;
    uintptr_t scene;
    uintptr_t adventure_level;
    uintptr_t sun;
    uintptr_t game_clock;
    uintptr_t debug_mode;
    uintptr_t particle_systems_addr;

    uintptr_t game_selector;

    uintptr_t tod_mode;

    uintptr_t game_mode;
    uintptr_t game_ui;

    uintptr_t free_planting;

    uintptr_t anim;
    uintptr_t unnamed;
    uintptr_t particle_system;
    uintptr_t particle_system_type;
    uintptr_t particle_system_dead;
    uintptr_t particle_system_count_max;

    uintptr_t user_data;
    uintptr_t level;
    uintptr_t money;
    uintptr_t playthrough;
    uintptr_t mini_games;
    uintptr_t tree_height;
    uintptr_t twiddydinky;

    uintptr_t music;

    HACK<uint8_t, 1> block_main_loop;

    HACK<uint8_t, 1> unlock_sun_limit;
    HACK<uint8_t, 1> auto_collected;
    HACK<uint8_t, 1> not_drop_loot;

    HACK<uint8_t, 1> fertilizer_unlimited;
    HACK<uint8_t, 1> bug_spray_unlimited;
    std::vector<HACK<uint8_t, 1>> chocolate_unlimited;
    HACK<uint8_t, 1> tree_food_unlimited;

    HACK<uint8_t, 1> placed_anywhere;
    HACK<uint8_t, 1> placed_anywhere_preview;
    HACK<uint8_t, 1> placed_anywhere_iz;
    std::vector<HACK<uint8_t, 1>> fast_belt;
    HACK<uint8_t, 1> lock_shovel;

    HACK<uint16_t, 1> rake_unlimited;
    HACK<uint8_t, 1> init_lawn_mowers;
    HACK<uint32_t, 1> lawn_mower_initialize;

    HACK<uint8_t, 3> plant_immune_eat;
    HACK<uint8_t, 1> plant_immune_radius;
    HACK<uint8_t, 1> plant_immune_jalapeno;
    HACK<uint8_t, 3> plant_immune_projectile;
    HACK<uint8_t, 3> plant_immune_lob_motion;
    HACK<uint8_t, 1> plant_immune_square;
    HACK<uint8_t, 1> plant_immune_row_area;
    HACK<uint8_t, 1> plant_immune_spike_rock;
    HACK<uint8_t, 3> plant_immune_squish;

    HACK<uint8_t, 3> _plant_immune_eat;
    HACK<uint8_t, 3> _plant_immune_projectile;
    HACK<uint8_t, 3> _plant_immune_lob_motion;
    HACK<uint8_t, 1> _plant_immune_row_area;

    HACK<uint32_t, 1> zombie_immune_body_damage;
    HACK<uint8_t, 2> zombie_immune_helm_damage;
    HACK<uint32_t, 1> zombie_immune_shield_damage;
    HACK<uint8_t, 1> zombie_immune_burn_crumble;
    HACK<uint8_t, 1> zombie_immune_radius;
    HACK<uint8_t, 1> zombie_immune_burn_row;
    HACK<uint8_t, 1> zombie_immune_chomper;
    HACK<uint8_t, 1> zombie_immune_mind_controll;
    HACK<uint8_t, 2> zombie_immune_blow_away;
    HACK<uint8_t, 1> zombie_immune_splash;
    HACK<uint8_t, 1> zombie_immune_lawn_mower;

    HACK<uint32_t, 1> _zombie_immune_body_damage;
    HACK<uint8_t, 2> _zombie_immune_helm_damage;
    HACK<uint32_t, 1> _zombie_immune_shield_damage;
    HACK<uint8_t, 1> _zombie_immune_burn_crumble;

    HACK<uint8_t, 1> reload_instantly;
    std::vector<HACK<uint8_t, 1>> grow_up_quickly;
    HACK<uint8_t, 1> mushrooms_awake;
    HACK<uint8_t, 1> stop_spawning;
    std::vector<HACK<uint8_t, 1>> stop_zombies;
    HACK<uint8_t, 1> lock_butter;
    HACK<uint8_t, 1> no_crater;
    std::vector<HACK<uint8_t, 1>> no_ice_trail;
    std::vector<HACK<uint8_t, 1>> zombie_not_explode;

    HACK<uint8_t, 1> hack_street_zombies;

    HACK<uint16_t, 1> no_fog;
    HACK<uint32_t, 1> see_vase;
    HACK<uint16_t, 1> background_running;
    HACK<uint8_t, 1> disable_delete_userdata;
    HACK<uint32_t, 1> disable_save_userdata;
    HACK<uint8_t, 3> unlock_limbo_page;

    uintptr_t call_sync_profile;

    uintptr_t call_fade_out_level;

    uintptr_t call_wisdom_tree;

    uintptr_t call_put_plant;
    uintptr_t call_put_plant_imitater;
    uintptr_t call_put_plant_iz_style;
    uintptr_t call_put_zombie;
    uintptr_t call_put_zombie_in_row;
    uintptr_t call_put_grave;
    uintptr_t call_put_ladder;
    uintptr_t call_put_rake;
    uintptr_t call_put_rake_row;
    uintptr_t call_put_rake_col;

    uintptr_t call_start_lawn_mower;
    uintptr_t call_delete_lawn_mower;
    uintptr_t call_restore_lawn_mower;

    uintptr_t call_delete_plant;
    uintptr_t call_delete_grid_item;

    uintptr_t call_set_plant_sleeping;

    uintptr_t call_puzzle_next_stage_clear;
    uintptr_t call_pick_background;
    uintptr_t call_delete_particle_system;

    uintptr_t call_pick_zombie_waves;
    uintptr_t call_remove_cutscene_zombies;
    uintptr_t call_place_street_zombies;

    uintptr_t call_play_music;
};

class Data
{
  public:
    Data();
    ~Data();

    // 是否为测试版
    bool isBETA();

    // 是否为年度版
    bool isGOTY();

    // 根据版本号获取数据
    PVZ_DATA data();

  protected:
    // 查找结果
    int find_result;

    // 不同版本的内存数据
    PVZ_DATA data_beta_0_1_1_1014_en;
    PVZ_DATA data_beta_0_9_9_1029_en;
    PVZ_DATA data_1_0_0_1051_en;
    PVZ_DATA data_1_2_0_1065_en;
    PVZ_DATA data_1_0_4_7924_es;
    PVZ_DATA data_1_0_7_3556_es;
    PVZ_DATA data_1_0_7_3467_ru;
    PVZ_DATA data_1_2_0_1073_en;
    PVZ_DATA data_1_2_0_1096_en;
    PVZ_DATA data_1_2_0_1093_de_es_fr_it;
    PVZ_DATA data_1_1_0_1056_zh;
    PVZ_DATA data_1_1_0_1056_ja;
    PVZ_DATA data_1_1_0_1056_zh_2012_06;
    PVZ_DATA data_1_1_0_1056_zh_2012_07;

    // 将版本和对应数据联系起来的键值对
    std::map<int, PVZ_DATA> ver_map;
};

} // namespace Pt
