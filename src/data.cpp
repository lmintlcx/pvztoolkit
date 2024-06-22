
#include "../inc/data.h"

namespace Pt
{

Data::Data()
{
    this->find_result = PVZ_NOT_FOUND;

#ifdef _PVZ_BETA_LEAK_SUPPORT

    this->data_beta_0_1_1_1014_en =
        {
            0x7552a8, // path
            0x69f498, // lawn

            0x454, // frame_duration

            0x768, // board

            0x90,     // zombie
            0x28,     //   zombie_status
            0xf0 + 0, //   zombie_dead
            0x94,     // zombie_count_max

            0xac,      // plant
            0x1c,      //   plant_row
            0x24,      //   plant_type
            0x28,      //   plant_col
            0x140 + 0, //   plant_imitater
            0x44 + 0,  //   plant_dead
            0x45 + 0,  //   plant_squished
            0x13c + 0, //   plant_asleep
            0xb0,      // plant_count_max
            0xb8,      // plant_next_pos

            0x100, // lawn_mower
            0x30,  //   lawn_mower_dead
            0x104, // lawn_mower_count_max
            0x110, // lawn_mower_count

            0x11c, // grid_item
            0x08,  //   grid_item_type
            0x10,  //   grid_item_col
            0x14,  //   grid_item_row
            0x20,  //   grid_item_dead
            0x120, // grid_item_count_max

            0x138, // cursor
            0x30,  //   cursor_grab

            0x144, // slot
            0x24,  //   slot_count
            0x4c,  //   slot_seed_cd_past
            0x50,  //   slot_seed_cd_total
            0x5c,  //   slot_seed_type
            0x60,  //   slot_seed_type_im

            0x15c, // cut_scene

            0x160, // challenge
            0x6c,  //   endless_rounds

            0x164,  // game_paused
            0x168,  // block_type
            0x5d8,  // row_type
            0x624,  // ice_trail_cd
            0x6b4,  // spawn_list
            0x54d4, // spawn_type
            0x554c, // scene
            0x5550, // adventure_level
            0x5560, // sun
            0x5568, // game_clock
            0x55f8, // debug_mode
            0x5620, // particle_systems_addr

            0x770, // game_selector

            0x7f5, // tod_mode

            0x7f8, // game_mode
            0x7fc, // game_ui

            0x814, // free_planting

            0x820, // anim
            0x00,  //   unnamed
            0x00,  //     particle_system
            0x00,  //       particle_system_type
            0x1c,  //       particle_system_dead
            0x04,  //     particle_system_count_max

            0x82c,     // user_data
            0x24,      //   level
            0x28,      //   money
            0x2c,      //   playthrough
            0x30 + 4,  //   mini_games
            0xf4 + 0,  //   tree_height
            0x1c0 + 4, //   twiddydinky

            0x83c, // music

            {0x0052f9b4, {0xfe}, {0xdb}}, // block_main_loop

            {0x00408885, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x0042ebb1, {0xeb}, {0x75}}, // auto_collected
            {0x0051797f, {0x60}, {0x55}}, // not_drop_loot

            {0x0050e3b4, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x0050e455, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x0050e1f5, {0x00}, {0xff}}, {0x0050e20c, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x00000000, {0x00}, {0x00}},                                 // tree_food_unlimited

            {0x004194be, {0x81}, {0x84}},                                 // placed_anywhere
            {0x00430285, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x00427b0a, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x0041e151, {0x80}, {0x8f}}, {0x00477ddb, {0x33}, {0x85}}}, // fast_belt
            {0x0041794c, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040c8cb, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040a064 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0044aebc + 2, {0x0064fdb8}, {0x0064fd44}}, // lawn_mower_initialize

            {0x00000000, {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00}}, // plant_immune_eat
            {0x0040b93d, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x00519ae8, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x0045e787, {0x90, 0x90, 0x90}, {0x29, 0x57, 0x48}}, // plant_immune_projectile
            {0x0045ec65, {0x90, 0x90, 0x90}, {0x29, 0x57, 0x48}}, // plant_immune_lob_motion
            {0x005115bb, {0xeb}, {0x74}},                         // plant_immune_square
            {0x00455a9e, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x0045593e, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00458b70, {0xc3, 0x8b, 0xf1}, {0x56, 0x8b, 0xf1}}, // plant_immune_squish

            {0x00000000, {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00}}, // _plant_immune_eat
            {0x0045e787, {0x29, 0x7f, 0x48}, {0x29, 0x57, 0x48}}, // _plant_immune_projectile
            {0x0045ec65, {0x29, 0x7f, 0x48}, {0x29, 0x57, 0x48}}, // _plant_immune_lob_motion
            {0x00455a9e, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x00000000, {0x00000000}, {0x00000000}}, // zombie_immune_body_damage
            {0x0051b763, {0x29, 0xd2}, {0x2b, 0xca}}, // zombie_immune_helm_damage
            {0x0051b25d, {0xc031ff31}, {0xf88b027c}}, // zombie_immune_shield_damage
            {0x0051f60d, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0040bd15, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x00451b02, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00458a5f, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00511893, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x00451be6, {0xeb, 0x0b}, {0x74, 0x0b}}, // zombie_immune_blow_away
            {0x0045e0d5, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0044b6ad, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x00000000, {0x00000000}, {0x00000000}}, // _zombie_immune_body_damage
            {0x0051b763, {0x29, 0xc9}, {0x2b, 0xca}}, // _zombie_immune_helm_damage
            {0x0051b25d, {0xf88bc78b}, {0xf88b027c}}, // _zombie_immune_shield_damage
            {0x0051f60d, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x00452d23, {0x80}, {0x85}},                                 // reload_instantly
            {{0x004583c8, {0x80}, {0x85}}, {0x004528ff, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00458b09, {0x70}, {0x75}}, {0x00452e9c, {0x80}, {0x85}}}, // no_cooldown
            {0x00454dc2, {0xeb}, {0x75}},                                 // mushrooms_awake
            {0x0041fe2f, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x005132ee, {0x54}, {0x64}}, {0x00513259, {0x54}, {0x44}}}, // stop_zombies
            {0x004580e1, {0x70}, {0x75}},                                 // lock_butter
            {0x0040bc80, {0x70}, {0x75}},                                 // no_crater
            {{0x00510b80, {0xc3}, {0x56}}, {0x004282bd, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x00519883, {0x81}, {0x8f}}, {0x00519a88, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00430e9e, {0x80}, {0x85}}, // hack_street_zombies

            {0x0040efa8, {0xd231}, {0xf23b}},                     // no_fog
            {0x00440048, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x0052eeab, {0x00eb}, {0x2d74}},                     // background_running
            {0x00531197, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00473cbf, {0x000c583d + 0x26}, {0x000c583d}},      // disable_save_userdata
            {0x0042adc6, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0043dce0, // call_sync_profile

            0x0041b8d0, // call_fade_out_level

            0x00000000, // call_wisdom_tree

            0x00411820, // call_put_plant
            0x00457160, // call_put_plant_imitater
            0x00420e40, // call_put_plant_iz_style
            0x00420dc0, // call_put_zombie
            0x0040a3c0, // call_put_zombie_in_row
            0x0041fe70, // call_put_grave
            0x00409b40, // call_put_ladder
            0x0040c8b0, // call_put_rake
            0x0040c9fc, // call_put_rake_row
            0x0040c965, // call_put_rake_col

            0x0044b3b0, // call_start_lawn_mower
            0x0044b540, // call_delete_lawn_mower
            0x00409fa0, // call_restore_lawn_mower

            0x00454630, // call_delete_plant
            0x0043f3a0, // call_delete_grid_item

            0x004520f0, // call_set_plant_sleeping

            0x00420b90, // call_puzzle_next_stage_clear
            0x004103c0, // call_pick_background
            0x00506100, // call_delete_particle_system

            0x0040fd50, // call_pick_zombie_waves
            0x0040d480, // call_remove_cutscene_zombies
            0x00430e90, // call_place_street_zombies

            0x0044d6d0, // call_play_music
        };

    this->data_beta_0_9_9_1029_en =
        {
            0x7668b8, // path
            0x6b0a40, // lawn

            0x454, // frame_duration

            0x768, // board

            0x90,     // zombie
            0x28,     //   zombie_status
            0xf0 + 0, //   zombie_dead
            0x94,     // zombie_count_max

            0xac,      // plant
            0x1c,      //   plant_row
            0x24,      //   plant_type
            0x28,      //   plant_col
            0x140 + 0, //   plant_imitater
            0x44 + 0,  //   plant_dead
            0x45 + 0,  //   plant_squished
            0x13c + 0, //   plant_asleep
            0xb0,      // plant_count_max
            0xb8,      // plant_next_pos

            0x100, // lawn_mower
            0x30,  //   lawn_mower_dead
            0x104, // lawn_mower_count_max
            0x110, // lawn_mower_count

            0x11c, // grid_item
            0x08,  //   grid_item_type
            0x10,  //   grid_item_col
            0x14,  //   grid_item_row
            0x20,  //   grid_item_dead
            0x120, // grid_item_count_max

            0x138, // cursor
            0x30,  //   cursor_grab

            0x144, // slot
            0x24,  //   slot_count
            0x4c,  //   slot_seed_cd_past
            0x50,  //   slot_seed_cd_total
            0x5c,  //   slot_seed_type
            0x60,  //   slot_seed_type_im

            0x15c, // cut_scene

            0x160, // challenge
            0x6c,  //   endless_rounds

            0x164,  // game_paused
            0x168,  // block_type
            0x5d8,  // row_type
            0x624,  // ice_trail_cd
            0x6b4,  // spawn_list
            0x54d4, // spawn_type
            0x554c, // scene
            0x5550, // adventure_level
            0x5560, // sun
            0x5568, // game_clock
            0x55f8, // debug_mode
            0x5620, // particle_systems_addr

            0x770, // game_selector

            0x7f5, // tod_mode

            0x7f8, // game_mode
            0x7fc, // game_ui

            0x814, // free_planting

            0x820, // anim
            0x00,  //   unnamed
            0x00,  //     particle_system
            0x00,  //       particle_system_type
            0x1c,  //       particle_system_dead
            0x04,  //     particle_system_count_max

            0x82c, // user_data
            0x24,  //   level
            0x28,  //   money
            0x2c,  //   playthrough
            0x30,  //   mini_games
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // music

            {0x0053d484, {0xfe}, {0xdb}}, // block_main_loop

            {0x004093f5, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x00432c01, {0xeb}, {0x75}}, // auto_collected
            {0x0052549c, {0x60}, {0x55}}, // not_drop_loot

            {0x0051b617, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x0051b6c1, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x0051b424, {0x00}, {0xff}}, {0x0051b459, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x004293b1, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x0041b0aa, {0x81}, {0x84}},                                 // placed_anywhere
            {0x00437e84, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042a814, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x00420461, {0x80}, {0x8f}}, {0x00483a9b, {0x33}, {0x85}}}, // fast_belt
            {0x0041943c, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040d82b, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040acad + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0045551c + 2, {0x0065f150}, {0x0065f118}}, // lawn_mower_initialize

            {0x00000000, {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00}}, // plant_immune_eat
            {0x0040c84d, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x00527d68, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x00468a77, {0x90, 0x90, 0x90}, {0x29, 0x57, 0x48}}, // plant_immune_projectile
            {0x00468f1a, {0x90, 0x90, 0x90}, {0x29, 0x4f, 0x48}}, // plant_immune_lob_motion
            {0x0051ebeb, {0xeb}, {0x74}},                         // plant_immune_square
            {0x004600ae, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x0045ff7e, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00463050, {0xc3, 0x8b, 0xf1}, {0x56, 0x8b, 0xf1}}, // plant_immune_squish

            {0x00000000, {0x00, 0x00, 0x00}, {0x00, 0x00, 0x00}}, // _plant_immune_eat
            {0x00468a77, {0x29, 0x7f, 0x48}, {0x29, 0x57, 0x48}}, // _plant_immune_projectile
            {0x00468f1a, {0x29, 0x7f, 0x48}, {0x29, 0x4f, 0x48}}, // _plant_immune_lob_motion
            {0x004600ae, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x0052d35e, {0x90909090}, {0x1c246c2b}}, // zombie_immune_body_damage
            {0x005299a3, {0x29, 0xd2}, {0x2b, 0xca}}, // zombie_immune_helm_damage
            {0x0052949d, {0xc031ff31}, {0xf88b027c}}, // zombie_immune_shield_damage
            {0x0052d97d, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0040cc85, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x0045bc42, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00462f2f, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0051ef03, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x0045bd26, {0xeb, 0x0b}, {0x74, 0x0b}}, // zombie_immune_blow_away
            {0x00468475, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x004558ad, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x0052d35e, {0x9090ed29}, {0x1c246c2b}}, // _zombie_immune_body_damage
            {0x005299a3, {0x29, 0xc9}, {0x2b, 0xca}}, // _zombie_immune_helm_damage
            {0x0052949d, {0xf88bc78b}, {0xf88b027c}}, // _zombie_immune_shield_damage
            {0x0052d97d, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x0045ceb3, {0x80}, {0x85}},                                 // reload_instantly
            {{0x00462878, {0x80}, {0x85}}, {0x0045ca6f, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00462fde, {0x70}, {0x75}}, {0x0045d14c, {0x80}, {0x85}}}, // no_cooldown
            {0x0045f3ed, {0xeb}, {0x75}},                                 // mushrooms_awake
            {0x00421f1f, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x00520c64, {0x54}, {0x64}}, {0x00520c6d, {0x54}, {0x44}}}, // stop_zombies
            {0x00462591, {0x70}, {0x75}},                                 // lock_butter
            {0x0040cbef, {0x70}, {0x75}},                                 // no_crater
            {{0x0051e1f0, {0xc3}, {0x56}}, {0x0042b69d, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x00527b03, {0x81}, {0x8f}}, {0x00527d08, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00438aae, {0x80}, {0x85}}, // hack_street_zombies

            {0x004101e8, {0xd231}, {0xf23b}},                     // no_fog
            {0x00449358, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x0053c97b, {0x00eb}, {0x2d74}},                     // background_running
            {0x0053ec77, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x0047f69f, {0x000c788d + 0x26}, {0x000c788d}},      // disable_save_userdata
            {0x0042e5b2, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x004462d0, // call_sync_profile

            0x0041d920, // call_fade_out_level

            0x00429f30, // call_wisdom_tree

            0x004118f0, // call_put_plant
            0x00461630, // call_put_plant_imitater
            0x00422f50, // call_put_plant_iz_style
            0x00422ed0, // call_put_zombie
            0x0040b140, // call_put_zombie_in_row
            0x00421f70, // call_put_grave
            0x0040a730, // call_put_ladder
            0x0040d810, // call_put_rake
            0x0040d95c, // call_put_rake_row
            0x0040d8c5, // call_put_rake_col

            0x004553f0, // call_start_lawn_mower
            0x00455740, // call_delete_lawn_mower
            0x0040abe0, // call_restore_lawn_mower

            0x0045ec60, // call_delete_plant
            0x004486a0, // call_delete_grid_item

            0x0045c210, // call_set_plant_sleeping

            0x00422c90, // call_puzzle_next_stage_clear
            0x00416e10, // call_pick_background
            0x00512fe0, // call_delete_particle_system

            0x004110e0, // call_pick_zombie_waves
            0x0040e4f0, // call_remove_cutscene_zombies
            0x00438aa0, // call_place_street_zombies

            0x00457f90, // call_play_music
        };

#endif

    this->data_1_0_0_1051_en =
        {
            0x6a6cc8, // path
            0x6a9ec0, // lawn

            0x454, // frame_duration

            0x768, // board

            0x90, // zombie
            0x28, //   zombie_status
            0xec, //   zombie_dead
            0x94, // zombie_count_max

            0xac,  // plant
            0x1c,  //   plant_row
            0x24,  //   plant_type
            0x28,  //   plant_col
            0x138, //   plant_imitater
            0x141, //   plant_dead
            0x142, //   plant_squished
            0x143, //   plant_asleep
            0xb0,  // plant_count_max
            0xb8,  // plant_next_pos

            0x100, // lawn_mower
            0x30,  //   lawn_mower_dead
            0x104, // lawn_mower_count_max
            0x110, // lawn_mower_count

            0x11c, // grid_item
            0x08,  //   grid_item_type
            0x10,  //   grid_item_col
            0x14,  //   grid_item_row
            0x20,  //   grid_item_dead
            0x120, // grid_item_count_max

            0x138, // cursor
            0x30,  //   cursor_grab

            0x144, // slot
            0x24,  //   slot_count
            0x4c,  //   slot_seed_cd_past
            0x50,  //   slot_seed_cd_total
            0x5c,  //   slot_seed_type
            0x60,  //   slot_seed_type_im

            0x15c, // cut_scene

            0x160, // challenge
            0x6c,  //   endless_rounds

            0x164,  // game_paused
            0x168,  // block_type
            0x5d8,  // row_type
            0x624,  // ice_trail_cd
            0x6b4,  // spawn_list
            0x54d4, // spawn_type
            0x554c, // scene
            0x5550, // adventure_level
            0x5560, // sun
            0x5568, // game_clock
            0x55f8, // debug_mode
            0x5620, // particle_systems_addr

            0x770, // game_selector

            0x7f5, // tod_mode

            0x7f8, // game_mode
            0x7fc, // game_ui

            0x814, // free_planting

            0x820, // anim
            0x00,  //   unnamed
            0x00,  //     particle_system
            0x00,  //       particle_system_type
            0x1c,  //       particle_system_dead
            0x04,  //     particle_system_count_max

            0x82c, // user_data
            0x24,  //   level
            0x28,  //   money
            0x2c,  //   playthrough
            0x30,  //   mini_games
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // music

            {0x00552014, {0xfe}, {0xdb}}, // block_main_loop

            {0x00430a23, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x0043158f, {0xeb}, {0x75}}, // auto_collected
            {0x00530276, {0x66}, {0x5b}}, // not_drop_loot

            {0x0051f017, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x0051f110, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x0051ec38, {0x00}, {0xff}}, {0x0051ecb8, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042d463, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x0040fe30, {0x81}, {0x84}},                                 // placed_anywhere
            {0x00438e40, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042a2d9, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x00422d20, {0x80}, {0x8f}}, {0x00489ca1, {0x33}, {0x85}}}, // fast_belt
            {0x004123a3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040b9e2, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040bd14 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x00458000 + 2, {0x006799fc}, {0x00679bf8}}, // lawn_mower_initialize

            {0x0052fcf1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0041cc2f, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x005276ea, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x0046cfeb, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x0046d7a6, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x0052e93b, {0xeb}, {0x74}},                         // plant_immune_square
            {0x0045ee0a, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x0045ec66, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00462b80, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x0052fcf1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x0046cfeb, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x0046d7a6, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x0045ee0a, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x0053130f, {0x90909090}, {0x20247c2b}}, // zombie_immune_body_damage
            {0x00531044, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x00530c9b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x00532ba1, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0041d8ff, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x004664f2, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x0046144a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0052fa82, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x00466601, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x0046d455, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x00458836, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x0053130f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_body_damage
            {0x00531044, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x00530c9b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x00532ba1, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x0046103b, {0x80}, {0x85}},                                 // reload_instantly
            {{0x0045fe54, {0x80}, {0x85}}, {0x0045fba3, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00461565, {0x70}, {0x75}}, {0x00461e37, {0x80}, {0x85}}}, // no_cooldown
            {0x0045de8e, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004265dc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052ab2b, {0x54}, {0x64}}, {0x0052ab34, {0x54}, {0x44}}}, // stop_zombies
            {0x0045f1ec, {0x70}, {0x75}},                                 // lock_butter
            {0x0041d79e, {0x70}, {0x75}},                                 // no_crater
            {{0x0052a7b0, {0xc3}, {0x51}}, {0x0041f79a, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x00526afc, {0x81}, {0x8f}}, {0x005275dd, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043a153, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041a68d, {0xd231}, {0xf23b}},                     // no_fog
            {0x0044e5cc, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x0054eba8, {0x00eb}, {0x2e74}},                     // background_running
            {0x0054b267, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00482149, {0x000c8b13 + 0x1b}, {0x000c8b13}},      // disable_save_userdata
            {0x0042df5d, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0044a320, // call_sync_profile

            0x0040c3e0, // call_fade_out_level

            0x0042d1f0, // call_wisdom_tree

            0x0040d120, // call_put_plant
            0x00466b80, // call_put_plant_imitater
            0x0042a530, // call_put_plant_iz_style
            0x0042a0f0, // call_put_zombie
            0x0040ddc0, // call_put_zombie_in_row
            0x00426620, // call_put_grave
            0x00408f40, // call_put_ladder
            0x0040b9c0, // call_put_rake
            0x0040bb25, // call_put_rake_row
            0x0040ba8e, // call_put_rake_col

            0x00458da0, // call_start_lawn_mower
            0x00458d10, // call_delete_lawn_mower
            0x0040bc70, // call_restore_lawn_mower

            0x004679b0, // call_delete_plant
            0x0044d000, // call_delete_grid_item

            0x0045e860, // call_set_plant_sleeping

            0x00429e50, // call_puzzle_next_stage_clear
            0x0040a160, // call_pick_background
            0x005160c0, // call_delete_particle_system

            0x004092e0, // call_pick_zombie_waves
            0x0040df70, // call_remove_cutscene_zombies
            0x0043a140, // call_place_street_zombies

            0x0045b750, // call_play_music
        };

    this->data_1_2_0_1065_en =
        {
            0x6a6cc8, // path
            0x6a9ec0, // lawn

            0x454, // frame_duration

            0x768, // board

            0x90, // zombie
            0x28, //   zombie_status
            0xec, //   zombie_dead
            0x94, // zombie_count_max

            0xac,  // plant
            0x1c,  //   plant_row
            0x24,  //   plant_type
            0x28,  //   plant_col
            0x138, //   plant_imitater
            0x141, //   plant_dead
            0x142, //   plant_squished
            0x143, //   plant_asleep
            0xb0,  // plant_count_max
            0xb8,  // plant_next_pos

            0x100, // lawn_mower
            0x30,  //   lawn_mower_dead
            0x104, // lawn_mower_count_max
            0x110, // lawn_mower_count

            0x11c, // grid_item
            0x08,  //   grid_item_type
            0x10,  //   grid_item_col
            0x14,  //   grid_item_row
            0x20,  //   grid_item_dead
            0x120, // grid_item_count_max

            0x138, // cursor
            0x30,  //   cursor_grab

            0x144, // slot
            0x24,  //   slot_count
            0x4c,  //   slot_seed_cd_past
            0x50,  //   slot_seed_cd_total
            0x5c,  //   slot_seed_type
            0x60,  //   slot_seed_type_im

            0x15c, // cut_scene

            0x160, // challenge
            0x6c,  //   endless_rounds

            0x164,  // game_paused
            0x168,  // block_type
            0x5d8,  // row_type
            0x624,  // ice_trail_cd
            0x6b4,  // spawn_list
            0x54d4, // spawn_type
            0x554c, // scene
            0x5550, // adventure_level
            0x5560, // sun
            0x5568, // game_clock
            0x55f8, // debug_mode
            0x5620, // particle_systems_addr

            0x770, // game_selector

            0x7f5, // tod_mode

            0x7f8, // game_mode
            0x7fc, // game_ui

            0x814, // free_planting

            0x820, // anim
            0x00,  //   unnamed
            0x00,  //     particle_system
            0x00,  //       particle_system_type
            0x1c,  //       particle_system_dead
            0x04,  //     particle_system_count_max

            0x82c, // user_data
            0x24,  //   level
            0x28,  //   money
            0x2c,  //   playthrough
            0x30,  //   mini_games
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // music

            {0x00552244, {0xfe}, {0xdb}}, // block_main_loop

            {0x00430a83, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x004315ef, {0xeb}, {0x75}}, // auto_collected
            {0x005305c6, {0x66}, {0x5b}}, // not_drop_loot

            {0x0051f367, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x0051f460, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x0051ef88, {0x00}, {0xff}}, {0x0051f008, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042d4c3, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x0040fe20, {0x81}, {0x84}},                                 // placed_anywhere
            {0x00438eb0, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042a339, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x00422d80, {0x80}, {0x8f}}, {0x00489ff1, {0x33}, {0x85}}}, // fast_belt
            {0x00412393, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040b9f2, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040bd24 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x00458160 + 2, {0x00679b5c}, {0x00679d58}}, // lawn_mower_initialize

            {0x00530041, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0041cc5f, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x00527a3a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x0046d32b, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x0046dae6, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x0052ec8b, {0xeb}, {0x74}},                         // plant_immune_square
            {0x0045ef0a, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x0045ed66, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00462d00, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x00530041, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x0046d32b, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x0046dae6, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x0045ef0a, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x0053165f, {0x90909090}, {0x20247c2b}}, // zombie_immune_body_damage
            {0x00531394, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x00530feb, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x00532ef1, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0041d933, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x00466672, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x004615ca, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0052fdd2, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x00466781, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x0046d795, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x00458996, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x0053165f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_body_damage
            {0x00531394, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x00530feb, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x00532ef1, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x004611bb, {0x80}, {0x85}},                                 // reload_instantly
            {{0x0045ffd4, {0x80}, {0x85}}, {0x0045fd23, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x004616e5, {0x70}, {0x75}}, {0x00461fb7, {0x80}, {0x85}}}, // no_cooldown
            {0x0045df8e, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042663c, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052ae7b, {0x54}, {0x64}}, {0x0052ae84, {0x54}, {0x44}}}, // stop_zombies
            {0x0045f2ec, {0x70}, {0x75}},                                 // lock_butter
            {0x0041d7ce, {0x70}, {0x75}},                                 // no_crater
            {{0x0052ab00, {0xc3}, {0x51}}, {0x0041f7fa, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x00526e4c, {0x81}, {0x8f}}, {0x0052792d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043a1c3, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041a6ad, {0xd231}, {0xf23b}},                     // no_fog
            {0x0044e71c, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x0054edd8, {0x00eb}, {0x2e74}},                     // background_running
            {0x0054b497, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00482499, {0x000c89f3 + 0x1b}, {0x000c89f3}},      // disable_save_userdata
            {0x0042dfbd, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0044a430, // call_sync_profile

            0x0040c3f0, // call_fade_out_level

            0x0042d250, // call_wisdom_tree

            0x0040d130, // call_put_plant
            0x00466d00, // call_put_plant_imitater
            0x0042a590, // call_put_plant_iz_style
            0x0042a150, // call_put_zombie
            0x0040ddd0, // call_put_zombie_in_row
            0x00426680, // call_put_grave
            0x00408f50, // call_put_ladder
            0x0040b9d0, // call_put_rake
            0x0040bb35, // call_put_rake_row
            0x0040ba9e, // call_put_rake_col

            0x00458f00, // call_start_lawn_mower
            0x00458e70, // call_delete_lawn_mower
            0x0040bc80, // call_restore_lawn_mower

            0x00467b30, // call_delete_plant
            0x0044d150, // call_delete_grid_item

            0x0045e960, // call_set_plant_sleeping

            0x00429eb0, // call_puzzle_next_stage_clear
            0x0040a170, // call_pick_background
            0x005163b0, // call_delete_particle_system

            0x004092f0, // call_pick_zombie_waves
            0x0040df80, // call_remove_cutscene_zombies
            0x0043a1b0, // call_place_street_zombies

            0x0045b8b0, // call_play_music
        };

    this->data_1_0_4_7924_es =
        {
            0x6b6de0, // path
            0x6b9fe0, // lawn

            0x454, // frame_duration

            0x768, // board

            0x90, // zombie
            0x28, //   zombie_status
            0xec, //   zombie_dead
            0x94, // zombie_count_max

            0xac,  // plant
            0x1c,  //   plant_row
            0x24,  //   plant_type
            0x28,  //   plant_col
            0x138, //   plant_imitater
            0x141, //   plant_dead
            0x142, //   plant_squished
            0x143, //   plant_asleep
            0xb0,  // plant_count_max
            0xb8,  // plant_next_pos

            0x100, // lawn_mower
            0x30,  //   lawn_mower_dead
            0x104, // lawn_mower_count_max
            0x110, // lawn_mower_count

            0x11c, // grid_item
            0x08,  //   grid_item_type
            0x10,  //   grid_item_col
            0x14,  //   grid_item_row
            0x20,  //   grid_item_dead
            0x120, // grid_item_count_max

            0x138, // cursor
            0x30,  //   cursor_grab

            0x144, // slot
            0x24,  //   slot_count
            0x4c,  //   slot_seed_cd_past
            0x50,  //   slot_seed_cd_total
            0x5c,  //   slot_seed_type
            0x60,  //   slot_seed_type_im

            0x15c, // cut_scene

            0x160, // challenge
            0x6c,  //   endless_rounds

            0x164,  // game_paused
            0x168,  // block_type
            0x5d8,  // row_type
            0x624,  // ice_trail_cd
            0x6b4,  // spawn_list
            0x54d4, // spawn_type
            0x554c, // scene
            0x5550, // adventure_level
            0x5560, // sun
            0x5568, // game_clock
            0x55f8, // debug_mode
            0x5620, // particle_systems_addr

            0x770, // game_selector

            0x7f5, // tod_mode

            0x7f8, // game_mode
            0x7fc, // game_ui

            0x814, // free_planting

            0x820, // anim
            0x00,  //   unnamed
            0x00,  //     particle_system
            0x00,  //       particle_system_type
            0x1c,  //       particle_system_dead
            0x04,  //     particle_system_count_max

            0x82c, // user_data
            0x24,  //   level
            0x28,  //   money
            0x2c,  //   playthrough
            0x30,  //   mini_games
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // music

            {0x005581c4, {0xfe}, {0xdb}}, // block_main_loop

            {0x00432713, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x0043327f, {0xeb}, {0x75}}, // auto_collected
            {0x005346e6, {0x66}, {0x5b}}, // not_drop_loot

            {0x00523497, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x00523590, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x005230b8, {0x00}, {0xff}}, {0x00523138, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042f103, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x00411370, {0x81}, {0x84}},                                 // placed_anywhere
            {0x0043ac50, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042bf49, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x00424960, {0x80}, {0x8f}}, {0x0048da11, {0x33}, {0x85}}}, // fast_belt
            {0x004138f3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040cef2, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040d224 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0045b490 + 2, {0x00688cc4}, {0x00688eb8}}, // lawn_mower_initialize

            {0x00534161, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0041e5bf, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x0052bb5a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x00470aeb, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x004712a6, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x00532dab, {0xeb}, {0x74}},                         // plant_immune_square
            {0x004625da, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x00462436, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x004663d0, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x00534161, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x00470aeb, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x004712a6, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x004625da, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x0053577f, {0x90909090}, {0x20247c2b}}, // zombie_immune_body_damage
            {0x005354b4, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x0053510b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x00537011, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0041f28f, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x00469d42, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00464c9a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00533ef2, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x00469e51, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x00470f55, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0045bcc6, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x0053577f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_body_damage
            {0x005354b4, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x0053510b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x00537011, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x0046488b, {0x80}, {0x85}},                                 // reload_instantly
            {{0x004636a4, {0x80}, {0x85}}, {0x004633f3, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00464db5, {0x70}, {0x75}}, {0x00465687, {0x80}, {0x85}}}, // no_cooldown
            {0x0046165e, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042826c, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052ef9b, {0x54}, {0x64}}, {0x0052efa4, {0x54}, {0x44}}}, // stop_zombies
            {0x004629bc, {0x70}, {0x75}},                                 // lock_butter
            {0x0041f12e, {0x70}, {0x75}},                                 // no_crater
            {{0x0052ec20, {0xc3}, {0x51}}, {0x004213ea, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0052af6c, {0x81}, {0x8f}}, {0x0052ba4d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043c1e3, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041bffd, {0xd231}, {0xf23b}},                     // no_fog
            {0x004513bc, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x00554cd8, {0x00eb}, {0x2e74}},                     // background_running
            {0x00551377, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00485e99, {0x000caed3 + 0x1b}, {0x000caed3}},      // disable_save_userdata
            {0x0042fc18, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0044d0c0, // call_sync_profile

            0x0040d8f0, // call_fade_out_level

            0x0042ee90, // call_wisdom_tree

            0x0040e620, // call_put_plant
            0x0046a3d0, // call_put_plant_imitater
            0x0042c1a0, // call_put_plant_iz_style
            0x0042bd60, // call_put_zombie
            0x0040f2c0, // call_put_zombie_in_row
            0x004282b0, // call_put_grave
            0x0040a450, // call_put_ladder
            0x0040ced0, // call_put_rake
            0x0040d035, // call_put_rake_row
            0x0040cf9e, // call_put_rake_col

            0x0045c230, // call_start_lawn_mower
            0x0045c1a0, // call_delete_lawn_mower
            0x0040d180, // call_restore_lawn_mower

            0x0046b200, // call_delete_plant
            0x0044fdf0, // call_delete_grid_item

            0x00462030, // call_set_plant_sleeping

            0x0042bac0, // call_puzzle_next_stage_clear
            0x0040b670, // call_pick_background
            0x0051a350, // call_delete_particle_system

            0x0040a7f0, // call_pick_zombie_waves
            0x0040f470, // call_remove_cutscene_zombies
            0x0043c1d0, // call_place_street_zombies

            0x0045eda0, // call_play_music
        };

    this->data_1_0_7_3556_es =
        {
            0x6b6e00, // path
            0x6ba008, // lawn

            0x454, // frame_duration

            0x768, // board

            0x90, // zombie
            0x28, //   zombie_status
            0xec, //   zombie_dead
            0x94, // zombie_count_max

            0xac,  // plant
            0x1c,  //   plant_row
            0x24,  //   plant_type
            0x28,  //   plant_col
            0x138, //   plant_imitater
            0x141, //   plant_dead
            0x142, //   plant_squished
            0x143, //   plant_asleep
            0xb0,  // plant_count_max
            0xb8,  // plant_next_pos

            0x100, // lawn_mower
            0x30,  //   lawn_mower_dead
            0x104, // lawn_mower_count_max
            0x110, // lawn_mower_count

            0x11c, // grid_item
            0x08,  //   grid_item_type
            0x10,  //   grid_item_col
            0x14,  //   grid_item_row
            0x20,  //   grid_item_dead
            0x120, // grid_item_count_max

            0x138, // cursor
            0x30,  //   cursor_grab

            0x144, // slot
            0x24,  //   slot_count
            0x4c,  //   slot_seed_cd_past
            0x50,  //   slot_seed_cd_total
            0x5c,  //   slot_seed_type
            0x60,  //   slot_seed_type_im

            0x15c, // cut_scene

            0x160, // challenge
            0x6c,  //   endless_rounds

            0x164,  // game_paused
            0x168,  // block_type
            0x5d8,  // row_type
            0x624,  // ice_trail_cd
            0x6b4,  // spawn_list
            0x54d4, // spawn_type
            0x554c, // scene
            0x5550, // adventure_level
            0x5560, // sun
            0x5568, // game_clock
            0x55f8, // debug_mode
            0x5620, // particle_systems_addr

            0x770, // game_selector

            0x7f5, // tod_mode

            0x7f8, // game_mode
            0x7fc, // game_ui

            0x814, // free_planting

            0x820, // anim
            0x00,  //   unnamed
            0x00,  //     particle_system
            0x00,  //       particle_system_type
            0x1c,  //       particle_system_dead
            0x04,  //     particle_system_count_max

            0x82c, // user_data
            0x24,  //   level
            0x28,  //   money
            0x2c,  //   playthrough
            0x30,  //   mini_games
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // music

            {0x00558344, {0xfe}, {0xdb}}, // block_main_loop

            {0x00432673, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x004331df, {0xeb}, {0x75}}, // auto_collected
            {0x00534776, {0x66}, {0x5b}}, // not_drop_loot

            {0x005234e7, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x005235e1, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x00523108, {0x00}, {0xff}}, {0x00523188, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042f053, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x00411340, {0x81}, {0x84}},                                 // placed_anywhere
            {0x0043abc0, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042be99, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x004248b0, {0x80}, {0x8f}}, {0x0048d9b1, {0x33}, {0x85}}}, // fast_belt
            {0x004138c3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040cec2, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040d1f4 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0045b4f0 + 2, {0x00688d4c}, {0x00688f40}}, // lawn_mower_initialize

            {0x005341f1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0041e57f, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x0052bbca, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x00470b6b, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x00471326, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x00532e3b, {0xeb}, {0x74}},                         // plant_immune_square
            {0x0046268a, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x004624e6, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00466480, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x005341f1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x00470b6b, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x00471326, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x0046268a, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x0053580f, {0x90909090}, {0x20247c2b}}, // zombie_immune_body_damage
            {0x00535544, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x0053519b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x005370a1, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0041f24f, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x00469df2, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00464d4a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00533f82, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x00469f01, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x00470fd5, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0045bd26, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x0053580f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_body_damage
            {0x00535544, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x0053519b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x005370a1, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x0046493b, {0x80}, {0x85}},                                 // reload_instantly
            {{0x00463754, {0x80}, {0x85}}, {0x004634a3, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00464e65, {0x70}, {0x75}}, {0x00465737, {0x80}, {0x85}}}, // no_cooldown
            {0x0046170e, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004281bc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052f02b, {0x54}, {0x64}}, {0x0052f034, {0x54}, {0x44}}}, // stop_zombies
            {0x00462a6c, {0x70}, {0x75}},                                 // lock_butter
            {0x0041f0ee, {0x70}, {0x75}},                                 // no_crater
            {{0x0052ecb0, {0xc3}, {0x51}}, {0x0042133a, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0052afdc, {0x81}, {0x8f}}, {0x0052babd, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043c153, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041bfcd, {0xd231}, {0xf23b}},                     // no_fog
            {0x0045143c, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x00554e58, {0x00eb}, {0x2e74}},                     // background_running
            {0x005514f7, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00485eb9, {0x000cb033 + 0x1b}, {0x000cb033}},      // disable_save_userdata
            {0x0042fb68, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0044d140, // call_sync_profile

            0x0040d8c0, // call_fade_out_level

            0x0042ede0, // call_wisdom_tree

            0x0040e5f0, // call_put_plant
            0x0046a480, // call_put_plant_imitater
            0x0042c0f0, // call_put_plant_iz_style
            0x0042bcb0, // call_put_zombie
            0x0040f290, // call_put_zombie_in_row
            0x00428200, // call_put_grave
            0x0040a420, // call_put_ladder
            0x0040cea0, // call_put_rake
            0x0040d005, // call_put_rake_row
            0x0040cf6e, // call_put_rake_col

            0x0045c290, // call_start_lawn_mower
            0x0045c200, // call_delete_lawn_mower
            0x0040d150, // call_restore_lawn_mower

            0x0046b2b0, // call_delete_plant
            0x0044fe70, // call_delete_grid_item

            0x004620e0, // call_set_plant_sleeping

            0x0042ba10, // call_puzzle_next_stage_clear
            0x0040b640, // call_pick_background
            0x0051a330, // call_delete_particle_system

            0x0040a7c0, // call_pick_zombie_waves
            0x0040f440, // call_remove_cutscene_zombies
            0x0043c140, // call_place_street_zombies

            0x0045ee00, // call_play_music
        };

    this->data_1_0_7_3467_ru =
        {
            0x6b6de0, // path
            0x6b9ff0, // lawn

            0x454, // frame_duration

            0x768, // board

            0x90, // zombie
            0x28, //   zombie_status
            0xec, //   zombie_dead
            0x94, // zombie_count_max

            0xac,  // plant
            0x1c,  //   plant_row
            0x24,  //   plant_type
            0x28,  //   plant_col
            0x138, //   plant_imitater
            0x141, //   plant_dead
            0x142, //   plant_squished
            0x143, //   plant_asleep
            0xb0,  // plant_count_max
            0xb8,  // plant_next_pos

            0x100, // lawn_mower
            0x30,  //   lawn_mower_dead
            0x104, // lawn_mower_count_max
            0x110, // lawn_mower_count

            0x11c, // grid_item
            0x08,  //   grid_item_type
            0x10,  //   grid_item_col
            0x14,  //   grid_item_row
            0x20,  //   grid_item_dead
            0x120, // grid_item_count_max

            0x138, // cursor
            0x30,  //   cursor_grab

            0x144, // slot
            0x24,  //   slot_count
            0x4c,  //   slot_seed_cd_past
            0x50,  //   slot_seed_cd_total
            0x5c,  //   slot_seed_type
            0x60,  //   slot_seed_type_im

            0x15c, // cut_scene

            0x160, // challenge
            0x6c,  //   endless_rounds

            0x164,  // game_paused
            0x168,  // block_type
            0x5d8,  // row_type
            0x624,  // ice_trail_cd
            0x6b4,  // spawn_list
            0x54d4, // spawn_type
            0x554c, // scene
            0x5550, // adventure_level
            0x5560, // sun
            0x5568, // game_clock
            0x55f8, // debug_mode
            0x5620, // particle_systems_addr

            0x770, // game_selector

            0x7f5, // tod_mode

            0x7f8, // game_mode
            0x7fc, // game_ui

            0x814, // free_planting

            0x820, // anim
            0x00,  //   unnamed
            0x00,  //     particle_system
            0x00,  //       particle_system_type
            0x1c,  //       particle_system_dead
            0x04,  //     particle_system_count_max

            0x82c, // user_data
            0x24,  //   level
            0x28,  //   money
            0x2c,  //   playthrough
            0x30,  //   mini_games
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // music

            {0x005588b4, {0xfe}, {0xdb}}, // block_main_loop

            {0x004329a5, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x0043350f, {0xeb}, {0x75}}, // auto_collected
            {0x00534cf6, {0x66}, {0x5b}}, // not_drop_loot

            {0x005239f7, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x00523af0, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x00523618, {0x00}, {0xff}}, {0x00523698, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042f383, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x00411410, {0x81}, {0x84}},                                 // placed_anywhere
            {0x0043af20, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042c159, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x00424a80, {0x80}, {0x8f}}, {0x0048dd81, {0x33}, {0x85}}}, // fast_belt
            {0x004139b3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040cf82, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040d2b4 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0045b700 + 2, {0x00688d5c}, {0x00688f50}}, // lawn_mower_initialize

            {0x00534771, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0041e6ef, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x0052c12a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x00470dbb, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x00471576, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x005333bb, {0xeb}, {0x74}},                         // plant_immune_square
            {0x0046287a, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x004626d8, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00466690, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x00534771, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x00470dbb, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x00471576, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x0046287a, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x00535d8f, {0x90909090}, {0x20247c2b}}, // zombie_immune_body_damage
            {0x00535ac4, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x00535720, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x00537621, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0041f3ef, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x0046a012, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00464f4a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00534502, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x0046a121, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x00471225, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0045bf36, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x00535d8f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_body_damage
            {0x00535ac4, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x00535720, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x00537621, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x00464b3b, {0x80}, {0x85}},                                 // reload_instantly
            {{0x00463944, {0x80}, {0x85}}, {0x00463693, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00465065, {0x70}, {0x75}}, {0x00465938, {0x80}, {0x85}}}, // no_cooldown
            {0x00461900, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004283ac, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052f5ab, {0x54}, {0x64}}, {0x0052f5b4, {0x54}, {0x44}}}, // stop_zombies
            {0x00462c62, {0x70}, {0x75}},                                 // lock_butter
            {0x0041f27e, {0x70}, {0x75}},                                 // no_crater
            {{0x0052f230, {0xc3}, {0x51}}, {0x004214ea, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0052b53c, {0x81}, {0x8f}}, {0x0052c01d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043c4a3, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041c11d, {0xd231}, {0xf23b}},                     // no_fog
            {0x004516ac, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x005553c8, {0x00eb}, {0x2e74}},                     // background_running
            {0x00551a67, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00486259, {0x000cb203 + 0x1b}, {0x000cb203}},      // disable_save_userdata
            {0x0042feaa, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0044d3a0, // call_sync_profile

            0x0040d980, // call_fade_out_level

            0x0042f110, // call_wisdom_tree

            0x0040e6b0, // call_put_plant
            0x0046a6a0, // call_put_plant_imitater
            0x0042c3c0, // call_put_plant_iz_style
            0x0042bf70, // call_put_zombie
            0x0040f350, // call_put_zombie_in_row
            0x004283f0, // call_put_grave
            0x0040a470, // call_put_ladder
            0x0040cf60, // call_put_rake
            0x0040d0c5, // call_put_rake_row
            0x0040d02e, // call_put_rake_col

            0x0045c4a0, // call_start_lawn_mower
            0x0045c410, // call_delete_lawn_mower
            0x0040d210, // call_restore_lawn_mower

            0x0046b4d0, // call_delete_plant
            0x004500e0, // call_delete_grid_item

            0x004622d0, // call_set_plant_sleeping

            0x0042bcd0, // call_puzzle_next_stage_clear
            0x0040b690, // call_pick_background
            0x0051a7f0, // call_delete_particle_system

            0x0040a810, // call_pick_zombie_waves
            0x0040f500, // call_remove_cutscene_zombies
            0x0043c490, // call_place_street_zombies

            0x0045f050, // call_play_music
        };

    this->data_goty_1_2_0_1073_en =
        {
            0x726090, // path
            0x729670, // lawn

            0x454 + 0x60, // frame_duration

            0x768 + 0x100, // board

            0x90 + 0x18, // zombie
            0x28,        //   zombie_status
            0xec,        //   zombie_dead
            0x94 + 0x18, // zombie_count_max

            0xac + 0x18, // plant
            0x1c,        //   plant_row
            0x24,        //   plant_type
            0x28,        //   plant_col
            0x138,       //   plant_imitater
            0x141,       //   plant_dead
            0x142,       //   plant_squished
            0x143,       //   plant_asleep
            0xb0 + 0x18, // plant_count_max
            0xb8 + 0x18, // plant_next_pos

            0x100 + 0x18, // lawn_mower
            0x30,         //   lawn_mower_dead
            0x104 + 0x18, // lawn_mower_count_max
            0x110 + 0x18, // lawn_mower_count

            0x11c + 0x18, // grid_item
            0x08,         //   grid_item_type
            0x10,         //   grid_item_col
            0x14,         //   grid_item_row
            0x20,         //   grid_item_dead
            0x120 + 0x18, // grid_item_count_max

            0x138 + 0x18, // cursor
            0x30,         //   cursor_grab

            0x144 + 0x18, // slot
            0x24,         //   slot_count
            0x4c,         //   slot_seed_cd_past
            0x50,         //   slot_seed_cd_total
            0x5c,         //   slot_seed_type
            0x60,         //   slot_seed_type_im

            0x15c + 0x18, // cut_scene

            0x160 + 0x18, // challenge
            0x6c,         //   endless_rounds

            0x164 + 0x18,  // game_paused
            0x168 + 0x18,  // block_type
            0x5d8 + 0x18,  // row_type
            0x624 + 0x18,  // ice_trail_cd
            0x6b4 + 0x18,  // spawn_list
            0x54d4 + 0x18, // spawn_type
            0x554c + 0x18, // scene
            0x5550 + 0x18, // adventure_level
            0x5560 + 0x18, // sun
            0x5568 + 0x18, // game_clock
            0x55f8 + 0x18, // debug_mode
            0x5620 + 0x18, // particle_systems_addr

            0x770 + 0x100, // game_selector

            0x7f5 + 0x120, // tod_mode

            0x7f8 + 0x120, // game_mode
            0x7fc + 0x120, // game_ui

            0x814 + 0x120, // free_planting

            0x820 + 0x120, // anim
            0x00,          //   unnamed
            0x00,          //     particle_system
            0x00,          //       particle_system_type
            0x1c,          //       particle_system_dead
            0x04,          //     particle_system_count_max

            0x82c + 0x120, // user_data
            0x24 + 0x28,   //   level
            0x28 + 0x28,   //   money
            0x2c + 0x28,   //   playthrough
            0x30 + 0x28,   //   mini_games
            0xf4 + 0x28,   //   tree_height
            0x1c0 + 0x28,  //   twiddydinky

            0x83c + 0x120, // music

            {0x005d6c6e, {0xfe}, {0xc8}}, // block_main_loop

            {0x0041e6f5, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x004342f2, {0xeb}, {0x75}}, // auto_collected
            {0x00540c06, {0x66}, {0x5b}}, // not_drop_loot

            {0x0052992b, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x00529a23, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x00529545, {0x39}, {0xff}}, {0x005295c7, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x0043018d, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x004127f0, {0x81}, {0x84}},                                 // placed_anywhere
            {0x0043c030, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042ce79, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x004257ff, {0x80}, {0x8f}}, {0x004948ae, {0x33}, {0x85}}}, // fast_belt
            {0x00414d53, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040e291, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040e5b4 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0045b8d0 + 2, {0x006fe1e4}, {0x006fe3c8}}, // lawn_mower_initialize

            {0x00540681, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0041f9ef, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x00537d7a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x0047169b, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x00471e59, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x0053f2bb, {0xeb}, {0x74}},                         // plant_immune_square
            {0x0046273a, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x00462596, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00466580, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x00540681, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x0047169b, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x00471e59, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x0046273a, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x00541cda, {0x90909090}, {0x20246c2b}}, // zombie_immune_body_damage
            {0x005419f4, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x0054164b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x00543571, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x004206d3, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x00469f62, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00464e08, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0054040f, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x0046a071, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x00471b03, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0045c0f5, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x00541cda, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_body_damage
            {0x005419f4, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x0054164b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x00543571, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x00464a0b, {0x80}, {0x85}},                                 // reload_instantly
            {{0x00463824, {0x80}, {0x85}}, {0x00463573, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00464f25, {0x70}, {0x75}}, {0x00465817, {0x80}, {0x85}}}, // no_cooldown
            {0x004617c2, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004290dc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0053b433, {0x54}, {0x64}}, {0x0053b43c, {0x54}, {0x44}}}, // stop_zombies
            {0x00462b42, {0x70}, {0x75}},                                 // lock_butter
            {0x0042057d, {0x70}, {0x75}},                                 // no_crater
            {{0x0053b0b0, {0xc3}, {0x51}}, {0x004222ea, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0053718c, {0x81}, {0x8f}}, {0x00537c6d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043d363, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041d17d, {0xd231}, {0xf23b}},                     // no_fog
            {0x004518aa, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x005d21d9, {0x00eb}, {0x4074}},                     // background_running
            {0x005cd993, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x0048cd63, {0x00140389 + 0x28}, {0x00140389}},      // disable_save_userdata
            {0x00430c80, {0x38, 0x58, 0x64}, {0x88, 0x58, 0x64}}, // unlock_limbo_page

            0x0044d270, // call_sync_profile

            0x0040ecd0, // call_fade_out_level

            0x0042ff00, // call_wisdom_tree

            0x0040fa10, // call_put_plant
            0x0046a630, // call_put_plant_imitater
            0x0042d0d0, // call_put_plant_iz_style
            0x0042cc90, // call_put_zombie
            0x00410700, // call_put_zombie_in_row
            0x00429120, // call_put_grave
            0x0040b870, // call_put_ladder
            0x0040e270, // call_put_rake
            0x0040e3ca, // call_put_rake_row
            0x0040e333, // call_put_rake_col

            0x0045c660, // call_start_lawn_mower
            0x0045c5d0, // call_delete_lawn_mower
            0x0040e510, // call_restore_lawn_mower

            0x0046b470, // call_delete_plant
            0x004502b0, // call_delete_grid_item

            0x00462190, // call_set_plant_sleeping

            0x0042c9f0, // call_puzzle_next_stage_clear
            0x0040c9f0, // call_pick_background
            0x00520770, // call_delete_particle_system

            0x0040bc20, // call_pick_zombie_waves
            0x004108e0, // call_remove_cutscene_zombies
            0x0043d350, // call_place_street_zombies

            0x0045efa0, // call_play_music
        };

    this->data_goty_1_2_0_1096_en =
        {
            0x72e670, // path
            0x731c50, // lawn

            0x454 + 0x60, // frame_duration

            0x768 + 0x100, // board

            0x90 + 0x18, // zombie
            0x28,        //   zombie_status
            0xec,        //   zombie_dead
            0x94 + 0x18, // zombie_count_max

            0xac + 0x18, // plant
            0x1c,        //   plant_row
            0x24,        //   plant_type
            0x28,        //   plant_col
            0x138,       //   plant_imitater
            0x141,       //   plant_dead
            0x142,       //   plant_squished
            0x143,       //   plant_asleep
            0xb0 + 0x18, // plant_count_max
            0xb8 + 0x18, // plant_next_pos

            0x100 + 0x18, // lawn_mower
            0x30,         //   lawn_mower_dead
            0x104 + 0x18, // lawn_mower_count_max
            0x110 + 0x18, // lawn_mower_count

            0x11c + 0x18, // grid_item
            0x08,         //   grid_item_type
            0x10,         //   grid_item_col
            0x14,         //   grid_item_row
            0x20,         //   grid_item_dead
            0x120 + 0x18, // grid_item_count_max

            0x138 + 0x18, // cursor
            0x30,         //   cursor_grab

            0x144 + 0x18, // slot
            0x24,         //   slot_count
            0x4c,         //   slot_seed_cd_past
            0x50,         //   slot_seed_cd_total
            0x5c,         //   slot_seed_type
            0x60,         //   slot_seed_type_im

            0x15c + 0x18, // cut_scene

            0x160 + 0x18, // challenge
            0x6c,         //   endless_rounds

            0x164 + 0x18,  // game_paused
            0x168 + 0x18,  // block_type
            0x5d8 + 0x18,  // row_type
            0x624 + 0x18,  // ice_trail_cd
            0x6b4 + 0x18,  // spawn_list
            0x54d4 + 0x18, // spawn_type
            0x554c + 0x18, // scene
            0x5550 + 0x18, // adventure_level
            0x5560 + 0x18, // sun
            0x5568 + 0x18, // game_clock
            0x55f8 + 0x18, // debug_mode
            0x5620 + 0x18, // particle_systems_addr

            0x770 + 0x100, // game_selector

            0x7f5 + 0x120, // tod_mode

            0x7f8 + 0x120, // game_mode
            0x7fc + 0x120, // game_ui

            0x814 + 0x120, // free_planting

            0x820 + 0x120, // anim
            0x00,          //   unnamed
            0x00,          //     particle_system
            0x00,          //       particle_system_type
            0x1c,          //       particle_system_dead
            0x04,          //     particle_system_count_max

            0x82c + 0x120,    // user_data
            0x24 + 0x28 + 4,  //   level
            0x28 + 0x28 + 4,  //   money
            0x2c + 0x28 + 4,  //   playthrough
            0x30 + 0x28 + 4,  //   mini_games
            0xf4 + 0x28 + 4,  //   tree_height
            0x1c0 + 0x28 + 4, //   twiddydinky

            0x83c + 0x120, // music

            {0x005dd25e, {0xfe}, {0xc8}}, // block_main_loop

            {0x0041f4e5, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x004352f2, {0xeb}, {0x75}}, // auto_collected
            {0x00544d26, {0x66}, {0x5b}}, // not_drop_loot

            {0x0052da8b, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x0052db83, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x0052d6a5, {0x39}, {0xff}}, {0x0052d727, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x004311ed, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x00413350, {0x81}, {0x84}},                                 // placed_anywhere
            {0x0043d100, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042dec9, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x0042684f, {0x80}, {0x8f}}, {0x0049831e, {0x33}, {0x85}}}, // fast_belt
            {0x004158b3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040ee41, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040f164 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0045e220 + 2, {0x00706704}, {0x007068e8}}, // lawn_mower_initialize

            {0x005447a1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x004207df, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x0053beda, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x00474ffb, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x004757b9, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x005433ab, {0xeb}, {0x74}},                         // plant_immune_square
            {0x0046511a, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x00464f76, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00468f60, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x005447a1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x00474ffb, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x004757b9, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x0046511a, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x00545dfa, {0x90909090}, {0x20246c2b}}, // zombie_immune_body_damage
            {0x00545b14, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x0054576b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x00547691, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x004214c3, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x0046c942, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x004677e8, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00544501, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x0046ca51, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x00475463, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0045ea45, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x00545dfa, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_body_damage
            {0x00545b14, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x0054576b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x00547691, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x004673eb, {0x80}, {0x85}},                                 // reload_instantly
            {{0x00466204, {0x80}, {0x85}}, {0x00465f53, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00467905, {0x70}, {0x75}}, {0x004681f7, {0x80}, {0x85}}}, // no_cooldown
            {0x004641a2, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042a12c, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0053f533, {0x54}, {0x64}}, {0x0053f53c, {0x54}, {0x44}}}, // stop_zombies
            {0x00465522, {0x70}, {0x75}},                                 // lock_butter
            {0x0042136d, {0x70}, {0x75}},                                 // no_crater
            {{0x0053f1b0, {0xc3}, {0x51}}, {0x0042333a, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0053b2ec, {0x81}, {0x8f}}, {0x0053bdcd, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043e6a3, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041df4d, {0xd231}, {0xf23b}},                     // no_fog
            {0x004531ca, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x005d87c9, {0x00eb}, {0x4074}},                     // background_running
            {0x005d3fd3, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x004907ea, {0x00142f42 + 0x28}, {0x00142f42}},      // disable_save_userdata
            {0x00431ce0, {0x38, 0x58, 0x64}, {0x88, 0x58, 0x64}}, // unlock_limbo_page

            0x0044eb90, // call_sync_profile

            0x0040f860, // call_fade_out_level

            0x00430f60, // call_wisdom_tree

            0x004105a0, // call_put_plant
            0x0046d010, // call_put_plant_imitater
            0x0042e120, // call_put_plant_iz_style
            0x0042dce0, // call_put_zombie
            0x00411290, // call_put_zombie_in_row
            0x0042a170, // call_put_grave
            0x0040c420, // call_put_ladder
            0x0040ee20, // call_put_rake
            0x0040ef7a, // call_put_rake_row
            0x0040eee3, // call_put_rake_col

            0x0045efb0, // call_start_lawn_mower
            0x0045ef20, // call_delete_lawn_mower
            0x0040f0c0, // call_restore_lawn_mower

            0x0046de50, // call_delete_plant
            0x00451bd0, // call_delete_grid_item

            0x00464b70, // call_set_plant_sleeping

            0x0042da40, // call_puzzle_next_stage_clear
            0x0040d5a0, // call_pick_background
            0x00524840, // call_delete_particle_system

            0x0040c7d0, // call_pick_zombie_waves
            0x00411470, // call_remove_cutscene_zombies
            0x0043e690, // call_place_street_zombies

            0x004618f0, // call_play_music
        };

    this->data_goty_1_2_0_1093_de_es_fr_it =
        {
            0x73a208, // path
            0x73d7e8, // lawn

            0x454 + 0x60, // frame_duration

            0x768 + 0x100, // board

            0x90 + 0x18, // zombie
            0x28,        //   zombie_status
            0xec,        //   zombie_dead
            0x94 + 0x18, // zombie_count_max

            0xac + 0x18, // plant
            0x1c,        //   plant_row
            0x24,        //   plant_type
            0x28,        //   plant_col
            0x138,       //   plant_imitater
            0x141,       //   plant_dead
            0x142,       //   plant_squished
            0x143,       //   plant_asleep
            0xb0 + 0x18, // plant_count_max
            0xb8 + 0x18, // plant_next_pos

            0x100 + 0x18, // lawn_mower
            0x30,         //   lawn_mower_dead
            0x104 + 0x18, // lawn_mower_count_max
            0x110 + 0x18, // lawn_mower_count

            0x11c + 0x18, // grid_item
            0x08,         //   grid_item_type
            0x10,         //   grid_item_col
            0x14,         //   grid_item_row
            0x20,         //   grid_item_dead
            0x120 + 0x18, // grid_item_count_max

            0x138 + 0x18, // cursor
            0x30,         //   cursor_grab

            0x144 + 0x18, // slot
            0x24,         //   slot_count
            0x4c,         //   slot_seed_cd_past
            0x50,         //   slot_seed_cd_total
            0x5c,         //   slot_seed_type
            0x60,         //   slot_seed_type_im

            0x15c + 0x18, // cut_scene

            0x160 + 0x18, // challenge
            0x6c,         //   endless_rounds

            0x164 + 0x18,  // game_paused
            0x168 + 0x18,  // block_type
            0x5d8 + 0x18,  // row_type
            0x624 + 0x18,  // ice_trail_cd
            0x6b4 + 0x18,  // spawn_list
            0x54d4 + 0x18, // spawn_type
            0x554c + 0x18, // scene
            0x5550 + 0x18, // adventure_level
            0x5560 + 0x18, // sun
            0x5568 + 0x18, // game_clock
            0x55f8 + 0x18, // debug_mode
            0x5620 + 0x18, // particle_systems_addr

            0x770 + 0x100, // game_selector

            0x7f5 + 0x120, // tod_mode

            0x7f8 + 0x120, // game_mode
            0x7fc + 0x120, // game_ui

            0x814 + 0x120, // free_planting

            0x820 + 0x120, // anim
            0x00,          //   unnamed
            0x00,          //     particle_system
            0x00,          //       particle_system_type
            0x1c,          //       particle_system_dead
            0x04,          //     particle_system_count_max

            0x82c + 0x120, // user_data
            0x24 + 0x28,   //   level
            0x28 + 0x28,   //   money
            0x2c + 0x28,   //   playthrough
            0x30 + 0x28,   //   mini_games
            0xf4 + 0x28,   //   tree_height
            0x1c0 + 0x28,  //   twiddydinky

            0x83c + 0x120, // music

            {0x005dee1e, {0xfe}, {0xc8}}, // block_main_loop

            {0x00420095, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x004362d2, {0xeb}, {0x75}}, // auto_collected
            {0x00545026, {0x66}, {0x5b}}, // not_drop_loot

            {0x0052ddab, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x0052dea3, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x0052d9c5, {0x39}, {0xff}}, {0x0052da47, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x004321cd, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x00413b60, {0x81}, {0x84}},                                 // placed_anywhere
            {0x0043df40, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x0042ee69, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x0042775f, {0x80}, {0x8f}}, {0x004985fe, {0x33}, {0x85}}}, // fast_belt
            {0x004160e3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040f531, {0x800f}, {0x840f}},             // rake_unlimited
            {0x0040f854 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0045f110 + 2, {0x00711ee4}, {0x007120c8}}, // lawn_mower_initialize

            {0x00544aa1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0042138f, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x0053c20a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x0047531b, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x00475ad9, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x005436db, {0xeb}, {0x74}},                         // plant_immune_square
            {0x004661ba, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x00466016, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x0046a000, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x00544aa1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x0047531b, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x00475ad9, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x004661ba, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x005460fa, {0x90909090}, {0x20246c2b}}, // zombie_immune_body_damage
            {0x00545e14, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x00545a6b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x00547991, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x00422073, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x0046d9e2, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00468888, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0054482f, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x0046daf1, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x00475783, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0045f935, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x005460fa, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_body_damage
            {0x00545e14, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x00545a6b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x00547991, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x0046848b, {0x80}, {0x85}},                                 // reload_instantly
            {{0x004672a4, {0x80}, {0x85}}, {0x00466ff3, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x004689a5, {0x70}, {0x75}}, {0x00469297, {0x80}, {0x85}}}, // no_cooldown
            {0x00465242, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042b0dc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0053f863, {0x54}, {0x64}}, {0x0053f86c, {0x54}, {0x44}}}, // stop_zombies
            {0x004665c2, {0x70}, {0x75}},                                 // lock_butter
            {0x00421f1d, {0x70}, {0x75}},                                 // no_crater
            {{0x0053f4e0, {0xc3}, {0x51}}, {0x004241da, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0053b61c, {0x81}, {0x8f}}, {0x0053c0fd, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043f4e3, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041ea6d, {0xd231}, {0xf23b}},                     // no_fog
            {0x0045484a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x005da319, {0x00eb}, {0x4074}},                     // background_running
            {0x005d5b43, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00490af3, {0x001447a9 + 0x28}, {0x001447a9}},      // disable_save_userdata
            {0x00432cdf, {0x38, 0x58, 0x64}, {0x88, 0x58, 0x64}}, // unlock_limbo_page

            0x004501d0, // call_sync_profile

            0x0040ff50, // call_fade_out_level

            0x00431f40, // call_wisdom_tree

            0x00410c50, // call_put_plant
            0x0046e0b0, // call_put_plant_imitater
            0x0042f0d0, // call_put_plant_iz_style
            0x0042ec80, // call_put_zombie
            0x00411940, // call_put_zombie_in_row
            0x0042b120, // call_put_grave
            0x0040cb10, // call_put_ladder
            0x0040f510, // call_put_rake
            0x0040f66a, // call_put_rake_row
            0x0040f5d3, // call_put_rake_col

            0x0045fea0, // call_start_lawn_mower
            0x0045fe10, // call_delete_lawn_mower
            0x0040f7b0, // call_restore_lawn_mower

            0x0046eef0, // call_delete_plant
            0x00453250, // call_delete_grid_item

            0x00465c10, // call_set_plant_sleeping

            0x0042e9e0, // call_puzzle_next_stage_clear
            0x0040dc90, // call_pick_background
            0x005247d0, // call_delete_particle_system

            0x0040cec0, // call_pick_zombie_waves
            0x00411b20, // call_remove_cutscene_zombies
            0x0043f4d0, // call_place_street_zombies

            0x00462980, // call_play_music
        };

    this->data_goty_1_1_0_1056_zh =
        {
            0x775a90, // path
            0x7794f8, // lawn

            0x454 + 0x60, // frame_duration

            0x768 + 0x100, // board

            0x90 + 0x18, // zombie
            0x28,        //   zombie_status
            0xec,        //   zombie_dead
            0x94 + 0x18, // zombie_count_max

            0xac + 0x18, // plant
            0x1c,        //   plant_row
            0x24,        //   plant_type
            0x28,        //   plant_col
            0x138,       //   plant_imitater
            0x141,       //   plant_dead
            0x142,       //   plant_squished
            0x143,       //   plant_asleep
            0xb0 + 0x18, // plant_count_max
            0xb8 + 0x18, // plant_next_pos

            0x100 + 0x18, // lawn_mower
            0x30,         //   lawn_mower_dead
            0x104 + 0x18, // lawn_mower_count_max
            0x110 + 0x18, // lawn_mower_count

            0x11c + 0x18, // grid_item
            0x08,         //   grid_item_type
            0x10,         //   grid_item_col
            0x14,         //   grid_item_row
            0x20,         //   grid_item_dead
            0x120 + 0x18, // grid_item_count_max

            0x138 + 0x18, // cursor
            0x30,         //   cursor_grab

            0x144 + 0x18, // slot
            0x24,         //   slot_count
            0x4c,         //   slot_seed_cd_past
            0x50,         //   slot_seed_cd_total
            0x5c,         //   slot_seed_type
            0x60,         //   slot_seed_type_im

            0x15c + 0x18, // cut_scene

            0x160 + 0x18, // challenge
            0x6c,         //   endless_rounds

            0x164 + 0x18,  // game_paused
            0x168 + 0x18,  // block_type
            0x5d8 + 0x18,  // row_type
            0x624 + 0x18,  // ice_trail_cd
            0x6b4 + 0x18,  // spawn_list
            0x54d4 + 0x18, // spawn_type
            0x554c + 0x18, // scene
            0x5550 + 0x18, // adventure_level
            0x5560 + 0x18, // sun
            0x5568 + 0x18, // game_clock
            0x55f8 + 0x18, // debug_mode
            0x5620 + 0x18, // particle_systems_addr

            0x770 + 0x100, // game_selector

            0x7f5 + 0x120 + 4, // tod_mode

            0x7f8 + 0x120 + 4, // game_mode
            0x7fc + 0x120 + 4, // game_ui

            0x814 + 0x120 + 4, // free_planting

            0x820 + 0x120 + 4, // anim
            0x00,              //   unnamed
            0x00,              //     particle_system
            0x00,              //       particle_system_type
            0x1c,              //       particle_system_dead
            0x04,              //     particle_system_count_max

            0x82c + 0x120 + 4, // user_data
            0x24 + 0x28,       //   level
            0x28 + 0x28,       //   money
            0x2c + 0x28,       //   playthrough
            0x30 + 0x28,       //   mini_games
            0xf4 + 0x28,       //   tree_height
            0x1c0 + 0x28,      //   twiddydinky

            0x83c + 0x120 + 4, // music

            {0x005cfd4e, {0xfe}, {0xc8}}, // block_main_loop

            {0x0044ba56, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x0044c5f2, {0xeb}, {0x75}}, // auto_collected
            {0x00565a9a, {0x6a}, {0x5b}}, // not_drop_loot

            {0x0054e0a4, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x0054e171, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x0054ddc3, {0x39}, {0xff}}, {0x0054de0a, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x00447d49, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x00425954, {0x81}, {0x84}},                                 // placed_anywhere
            {0x00454b67, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x004449e8, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x0043b8bf, {0x80}, {0x8f}}, {0x004b5b8e, {0x33}, {0x85}}}, // fast_belt
            {0x00427f13, {0x39}, {0x89}},                                 // lock_shovel

            {0x00420fc2, {0x800f}, {0x840f}},             // rake_unlimited
            {0x00421293 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0047b807 + 2, {0x00746664}, {0x00746ab8}}, // lawn_mower_initialize

            {0x005654c1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x004354af, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x0055d00a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x004920e5, {0x90, 0x90, 0x90}, {0x29, 0x46, 0x40}}, // plant_immune_projectile
            {0x00492942, {0x90, 0x90, 0x90}, {0x29, 0x56, 0x40}}, // plant_immune_lob_motion
            {0x0056404b, {0xeb}, {0x74}},                         // plant_immune_square
            {0x00482e33, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x00482ccb, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00486c90, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x005654c1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x004920e5, {0x29, 0x76, 0x40}, {0x29, 0x46, 0x40}}, // _plant_immune_projectile
            {0x00492942, {0x29, 0x76, 0x40}, {0x29, 0x56, 0x40}}, // _plant_immune_lob_motion
            {0x00482e33, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x00566d06, {0x90909090}, {0x2024742b}}, // zombie_immune_body_damage
            {0x00566890, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x005663f8, {0xf633c033}, {0xf38b027c}}, // zombie_immune_shield_damage
            {0x00568626, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x004361ee, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x0048a792, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x0048550a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00565243, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x0048a8b0, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x004925b3, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0047bf85, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x00566d06, {0x9090f631}, {0x2024742b}}, // _zombie_immune_body_damage
            {0x00566890, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x005663f8, {0xf38bde8b}, {0xf38b027c}}, // _zombie_immune_shield_damage
            {0x00568626, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x0048517c, {0x80}, {0x85}},                                 // reload_instantly
            {{0x00483ed3, {0x80}, {0x85}}, {0x00483bfb, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x004855f5, {0x70}, {0x75}}, {0x00485ec7, {0x80}, {0x85}}}, // no_cooldown
            {0x00481c44, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0043f17e, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x005604d7, {0x54}, {0x64}}, {0x005604e0, {0x54}, {0x44}}}, // stop_zombies
            {0x00483207, {0x70}, {0x75}},                                 // lock_butter
            {0x0043609d, {0x70}, {0x75}},                                 // no_crater
            {{0x00560150, {0xc3}, {0x51}}, {0x004385f6, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0055c5cc, {0x81}, {0x8f}}, {0x0055cf7a, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00456858, {0x80}, {0x85}}, // hack_street_zombies

            {0x00430d9d, {0xd231}, {0xf23b}},                     // no_fog
            {0x0046df1a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x005cb249, {0x00eb}, {0x4074}},                     // background_running
            {0x005c6a73, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x004adf93, {0x00118239 + 0x28}, {0x00118239}},      // disable_save_userdata
            {0x0044895a, {0x38, 0x58, 0x64}, {0x88, 0x58, 0x64}}, // unlock_limbo_page

            0x00469630, // call_sync_profile

            0x00421a20, // call_fade_out_level

            0x00447b20, // call_wisdom_tree

            0x00422610, // call_put_plant
            0x0048ae60, // call_put_plant_imitater
            0x00444c10, // call_put_plant_iz_style
            0x00444860, // call_put_zombie
            0x004236d0, // call_put_zombie_in_row
            0x0043f1c0, // call_put_grave
            0x0041e440, // call_put_ladder
            0x00420fa0, // call_put_rake
            0x00421101, // call_put_rake_row
            0x0042106c, // call_put_rake_col

            0x0047c4d0, // call_start_lawn_mower
            0x0047c440, // call_delete_lawn_mower
            0x004211f0, // call_restore_lawn_mower

            0x0048bcc0, // call_delete_plant
            0x0046ca10, // call_delete_grid_item

            0x00482900, // call_set_plant_sleeping

            0x00444450, // call_puzzle_next_stage_clear
            0x0041f3d0, // call_pick_background
            0x005435f0, // call_delete_particle_system

            0x0041e840, // call_pick_zombie_waves
            0x004238d0, // call_remove_cutscene_zombies
            0x00456840, // call_place_street_zombies

            0x0047f240, // call_play_music
        };

    this->data_goty_1_1_0_1056_ja =
        {
            0x7541f8, // path
            0x7578f8, // lawn

            0x454 + 0x60, // frame_duration

            0x768 + 0x100, // board

            0x90 + 0x18, // zombie
            0x28,        //   zombie_status
            0xec,        //   zombie_dead
            0x94 + 0x18, // zombie_count_max

            0xac + 0x18, // plant
            0x1c,        //   plant_row
            0x24,        //   plant_type
            0x28,        //   plant_col
            0x138,       //   plant_imitater
            0x141,       //   plant_dead
            0x142,       //   plant_squished
            0x143,       //   plant_asleep
            0xb0 + 0x18, // plant_count_max
            0xb8 + 0x18, // plant_next_pos

            0x100 + 0x18, // lawn_mower
            0x30,         //   lawn_mower_dead
            0x104 + 0x18, // lawn_mower_count_max
            0x110 + 0x18, // lawn_mower_count

            0x11c + 0x18, // grid_item
            0x08,         //   grid_item_type
            0x10,         //   grid_item_col
            0x14,         //   grid_item_row
            0x20,         //   grid_item_dead
            0x120 + 0x18, // grid_item_count_max

            0x138 + 0x18, // cursor
            0x30,         //   cursor_grab

            0x144 + 0x18, // slot
            0x24,         //   slot_count
            0x4c,         //   slot_seed_cd_past
            0x50,         //   slot_seed_cd_total
            0x5c,         //   slot_seed_type
            0x60,         //   slot_seed_type_im

            0x15c + 0x18, // cut_scene

            0x160 + 0x18, // challenge
            0x6c,         //   endless_rounds

            0x164 + 0x18,  // game_paused
            0x168 + 0x18,  // block_type
            0x5d8 + 0x18,  // row_type
            0x624 + 0x18,  // ice_trail_cd
            0x6b4 + 0x18,  // spawn_list
            0x54d4 + 0x18, // spawn_type
            0x554c + 0x18, // scene
            0x5550 + 0x18, // adventure_level
            0x5560 + 0x18, // sun
            0x5568 + 0x18, // game_clock
            0x55f8 + 0x18, // debug_mode
            0x5620 + 0x18, // particle_systems_addr

            0x770 + 0x100, // game_selector

            0x7f5 + 0x120, // tod_mode

            0x7f8 + 0x120, // game_mode
            0x7fc + 0x120, // game_ui

            0x814 + 0x120, // free_planting

            0x820 + 0x120, // anim
            0x00,          //   unnamed
            0x00,          //     particle_system
            0x00,          //       particle_system_type
            0x1c,          //       particle_system_dead
            0x04,          //     particle_system_count_max

            0x82c + 0x120, // user_data
            0x24 + 0x28,   //   level
            0x28 + 0x28,   //   money
            0x2c + 0x28,   //   playthrough
            0x30 + 0x28,   //   mini_games
            0xf4 + 0x28,   //   tree_height
            0x1c0 + 0x28,  //   twiddydinky

            0x83c + 0x120, // music

            {0x00627ade, {0xfe}, {0xc8}}, // block_main_loop

            {0x0043a806, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x0043b3a2, {0xeb}, {0x75}}, // auto_collected
            {0x0055420a, {0x6a}, {0x5b}}, // not_drop_loot

            {0x0053c864, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x0053c931, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x0053c583, {0x39}, {0xff}}, {0x0053c5ca, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x004368c9, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x004156b4, {0x81}, {0x84}},                                 // placed_anywhere
            {0x00443797, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x004334d8, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x0042ac2f, {0x80}, {0x8f}}, {0x004a411e, {0x33}, {0x85}}}, // fast_belt
            {0x00417c9b, {0x39}, {0x89}},                                 // lock_shovel

            {0x00410e12, {0x800f}, {0x840f}},             // rake_unlimited
            {0x004110e3 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x0046a117 + 2, {0x0072a8dc}, {0x0072ad30}}, // lawn_mower_initialize

            {0x00553c3b, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x004243df, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x0054b78a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x004809a5, {0x90, 0x90, 0x90}, {0x29, 0x46, 0x40}}, // plant_immune_projectile
            {0x00481200, {0x90, 0x90, 0x90}, {0x29, 0x56, 0x40}}, // plant_immune_lob_motion
            {0x005527cb, {0xeb}, {0x74}},                         // plant_immune_square
            {0x004716e3, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x0047157b, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00475540, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x00553c3b, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x004809a5, {0x29, 0x76, 0x40}, {0x29, 0x46, 0x40}}, // _plant_immune_projectile
            {0x00481200, {0x29, 0x76, 0x40}, {0x29, 0x56, 0x40}}, // _plant_immune_lob_motion
            {0x004716e3, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x00555476, {0x90909090}, {0x2024742b}}, // zombie_immune_body_damage
            {0x00555000, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x00554b68, {0xf633c033}, {0xf38b027c}}, // zombie_immune_shield_damage
            {0x00556d96, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0042511e, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x00479042, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00473dba, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x005539c3, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x00479160, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x00480e73, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x0046a895, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x00555476, {0x9090f631}, {0x2024742b}}, // _zombie_immune_body_damage
            {0x00555000, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x00554b68, {0xf38bde8b}, {0xf38b027c}}, // _zombie_immune_shield_damage
            {0x00556d96, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x00473a2c, {0x80}, {0x85}},                                 // reload_instantly
            {{0x00472783, {0x80}, {0x85}}, {0x004724ab, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00473ea5, {0x70}, {0x75}}, {0x00474777, {0x80}, {0x85}}}, // no_cooldown
            {0x004704f4, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042dd5e, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0054ec57, {0x54}, {0x64}}, {0x0054ec60, {0x54}, {0x44}}}, // stop_zombies
            {0x00471ab7, {0x70}, {0x75}},                                 // lock_butter
            {0x00424fcd, {0x70}, {0x75}},                                 // no_crater
            {{0x0054e8d0, {0xc3}, {0x51}}, {0x004278c6, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0054ad4c, {0x81}, {0x8f}}, {0x0054b6fa, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00445488, {0x80}, {0x85}}, // hack_street_zombies

            {0x0041fcbd, {0xd231}, {0xf23b}},                     // no_fog
            {0x0045c66a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x00622fd9, {0x00eb}, {0x4074}},                     // background_running
            {0x0061e7f3, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x0049c733, {0x00181819 + 0x28}, {0x00181819}},      // disable_save_userdata
            {0x004374da, {0x38, 0x58, 0x64}, {0x88, 0x58, 0x64}}, // unlock_limbo_page

            0x00457d60, // call_sync_profile

            0x00411880, // call_fade_out_level

            0x004366a0, // call_wisdom_tree

            0x00412370, // call_put_plant
            0x00479720, // call_put_plant_imitater
            0x00433700, // call_put_plant_iz_style
            0x00433330, // call_put_zombie
            0x00413430, // call_put_zombie_in_row
            0x0042dda0, // call_put_grave
            0x0040e290, // call_put_ladder
            0x00410df0, // call_put_rake
            0x00410f51, // call_put_rake_row
            0x00410ebc, // call_put_rake_col

            0x0046ade0, // call_start_lawn_mower
            0x0046ad50, // call_delete_lawn_mower
            0x00411040, // call_restore_lawn_mower

            0x0047a580, // call_delete_plant
            0x0045b160, // call_delete_grid_item

            0x004711b0, // call_set_plant_sleeping

            0x00432f20, // call_puzzle_next_stage_clear
            0x0040f220, // call_pick_background
            0x00531c40, // call_delete_particle_system

            0x0040e690, // call_pick_zombie_waves
            0x00413630, // call_remove_cutscene_zombies
            0x00445470, // call_place_street_zombies

            0x0046dcf0, // call_play_music
        };

    this->data_goty_1_1_0_1056_zh_2012_06 =
        {
            0x7525b0, // path
            0x755e0c, // lawn

            0x454 + 0x60, // frame_duration

            0x768 + 0x100, // board

            0x90 + 0x18, // zombie
            0x28,        //   zombie_status
            0xec,        //   zombie_dead
            0x94 + 0x18, // zombie_count_max

            0xac + 0x18, // plant
            0x1c,        //   plant_row
            0x24,        //   plant_type
            0x28,        //   plant_col
            0x138,       //   plant_imitater
            0x141,       //   plant_dead
            0x142,       //   plant_squished
            0x143,       //   plant_asleep
            0xb0 + 0x18, // plant_count_max
            0xb8 + 0x18, // plant_next_pos

            0x100 + 0x18, // lawn_mower
            0x30,         //   lawn_mower_dead
            0x104 + 0x18, // lawn_mower_count_max
            0x110 + 0x18, // lawn_mower_count

            0x11c + 0x18, // grid_item
            0x08,         //   grid_item_type
            0x10,         //   grid_item_col
            0x14,         //   grid_item_row
            0x20,         //   grid_item_dead
            0x120 + 0x18, // grid_item_count_max

            0x138 + 0x18, // cursor
            0x30,         //   cursor_grab

            0x144 + 0x18, // slot
            0x24,         //   slot_count
            0x4c,         //   slot_seed_cd_past
            0x50,         //   slot_seed_cd_total
            0x5c,         //   slot_seed_type
            0x60,         //   slot_seed_type_im

            0x15c + 0x18, // cut_scene

            0x160 + 0x18, // challenge
            0x6c,         //   endless_rounds

            0x164 + 0x18,  // game_paused
            0x168 + 0x18,  // block_type
            0x5d8 + 0x18,  // row_type
            0x624 + 0x18,  // ice_trail_cd
            0x6b4 + 0x18,  // spawn_list
            0x54d4 + 0x18, // spawn_type
            0x554c + 0x18, // scene
            0x5550 + 0x18, // adventure_level
            0x5560 + 0x18, // sun
            0x5568 + 0x18, // game_clock
            0x55f8 + 0x18, // debug_mode
            0x5620 + 0x18, // particle_systems_addr

            0x770 + 0x100, // game_selector

            0x7f5 + 0x120 + 4, // tod_mode

            0x7f8 + 0x120 + 4, // game_mode
            0x7fc + 0x120 + 4, // game_ui

            0x814 + 0x120 + 4, // free_planting

            0x820 + 0x120 + 4, // anim
            0x00,              //   unnamed
            0x00,              //     particle_system
            0x00,              //       particle_system_type
            0x1c,              //       particle_system_dead
            0x04,              //     particle_system_count_max

            0x82c + 0x120 + 4, // user_data
            0x24 + 0x28,       //   level
            0x28 + 0x28,       //   money
            0x2c + 0x28,       //   playthrough
            0x30 + 0x28,       //   mini_games
            0xf4 + 0x28,       //   tree_height
            0x1c0 + 0x28,      //   twiddydinky

            0x83c + 0x120 + 4, // music

            {0x0062941e, {0xfe}, {0xc8}}, // block_main_loop

            {0x0043c0c1, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x0043cc72, {0xeb}, {0x75}}, // auto_collected
            {0x0054bfe6, {0x66}, {0x5b}}, // not_drop_loot

            {0x00534d7b, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x00534e73, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x00534995, {0x39}, {0xff}}, {0x00534a17, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x0043885d, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x0041bd2e, {0x81}, {0x84}},                                 // placed_anywhere
            {0x00444790, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x00435579, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x0042e58f, {0x80}, {0x8f}}, {0x0049f6fe, {0x33}, {0x85}}}, // fast_belt
            {0x0041e36e, {0x39}, {0x89}},                                 // lock_shovel

            {0x00417731, {0x800f}, {0x840f}},             // rake_unlimited
            {0x00417a54 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x00465f60 + 2, {0x00727894}, {0x00727a78}}, // lawn_mower_initialize

            {0x0054ba6b, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0042883f, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x0054316a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x0047c3db, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x0047cb99, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x0054a6ab, {0xeb}, {0x74}},                         // plant_immune_square
            {0x0046d13a, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x0046cf96, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00470f80, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x0054ba6b, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x0047c3db, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x0047cb99, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x0046d13a, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x0054d0ba, {0x90909090}, {0x20246c2b}}, // zombie_immune_body_damage
            {0x0054cdd4, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x0054ca2b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x0054e951, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x00429523, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x00474962, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x0046f808, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0054b7ff, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x00474a71, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x0047c843, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x00466785, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x0054d0ba, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_body_damage
            {0x0054cdd4, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x0054ca2b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x0054e951, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x0046f40b, {0x80}, {0x85}},                                 // reload_instantly
            {{0x0046e224, {0x80}, {0x85}}, {0x0046df73, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x0046f925, {0x70}, {0x75}}, {0x00470217, {0x80}, {0x85}}}, // no_cooldown
            {0x0046c1c2, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004318bc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x00546823, {0x54}, {0x64}}, {0x0054682c, {0x54}, {0x44}}}, // stop_zombies
            {0x0046d542, {0x70}, {0x75}},                                 // lock_butter
            {0x004293cd, {0x70}, {0x75}},                                 // no_crater
            {{0x005464a0, {0xc3}, {0x51}}, {0x0042b0b9, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0054257c, {0x81}, {0x8f}}, {0x0054305d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00445d33, {0x80}, {0x85}}, // hack_street_zombies

            {0x0042616d, {0xd231}, {0xf23b}},                     // no_fog
            {0x00459c1a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x00624919, {0x00eb}, {0x4074}},                     // background_running
            {0x00620143, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00497ed3, {0x001879c9 + 0x28}, {0x001879c9}},      // disable_save_userdata
            {0x0043935a, {0x38, 0x58, 0x64}, {0x88, 0x58, 0x64}}, // unlock_limbo_page

            0x00455420, // call_sync_profile

            0x00418140, // call_fade_out_level

            0x004385d0, // call_wisdom_tree

            0x00418d70, // call_put_plant
            0x00475050, // call_put_plant_imitater
            0x004357d0, // call_put_plant_iz_style
            0x00435390, // call_put_zombie
            0x00419a60, // call_put_zombie_in_row
            0x00431900, // call_put_grave
            0x00414d10, // call_put_ladder
            0x00417710, // call_put_rake
            0x0041786a, // call_put_rake_row
            0x004177d3, // call_put_rake_col

            0x00466cf0, // call_start_lawn_mower
            0x00466c60, // call_delete_lawn_mower
            0x004179b0, // call_restore_lawn_mower

            0x00475e90, // call_delete_plant
            0x00458620, // call_delete_grid_item

            0x0046cb90, // call_set_plant_sleeping

            0x004350f0, // call_puzzle_next_stage_clear
            0x00415e90, // call_pick_background
            0x0052b620, // call_delete_particle_system

            0x004150c0, // call_pick_zombie_waves
            0x00419c50, // call_remove_cutscene_zombies
            0x00445d20, // call_place_street_zombies

            0x00469a10, // call_play_music
        };

    this->data_goty_1_1_0_1056_zh_2012_07 =
        {
            0x7545b0, // path
            0x757e0c, // lawn

            0x454 + 0x60, // frame_duration

            0x768 + 0x100, // board

            0x90 + 0x18, // zombie
            0x28,        //   zombie_status
            0xec,        //   zombie_dead
            0x94 + 0x18, // zombie_count_max

            0xac + 0x18, // plant
            0x1c,        //   plant_row
            0x24,        //   plant_type
            0x28,        //   plant_col
            0x138,       //   plant_imitater
            0x141,       //   plant_dead
            0x142,       //   plant_squished
            0x143,       //   plant_asleep
            0xb0 + 0x18, // plant_count_max
            0xb8 + 0x18, // plant_next_pos

            0x100 + 0x18, // lawn_mower
            0x30,         //   lawn_mower_dead
            0x104 + 0x18, // lawn_mower_count_max
            0x110 + 0x18, // lawn_mower_count

            0x11c + 0x18, // grid_item
            0x08,         //   grid_item_type
            0x10,         //   grid_item_col
            0x14,         //   grid_item_row
            0x20,         //   grid_item_dead
            0x120 + 0x18, // grid_item_count_max

            0x138 + 0x18, // cursor
            0x30,         //   cursor_grab

            0x144 + 0x18, // slot
            0x24,         //   slot_count
            0x4c,         //   slot_seed_cd_past
            0x50,         //   slot_seed_cd_total
            0x5c,         //   slot_seed_type
            0x60,         //   slot_seed_type_im

            0x15c + 0x18, // cut_scene

            0x160 + 0x18, // challenge
            0x6c,         //   endless_rounds

            0x164 + 0x18,  // game_paused
            0x168 + 0x18,  // block_type
            0x5d8 + 0x18,  // row_type
            0x624 + 0x18,  // ice_trail_cd
            0x6b4 + 0x18,  // spawn_list
            0x54d4 + 0x18, // spawn_type
            0x554c + 0x18, // scene
            0x5550 + 0x18, // adventure_level
            0x5560 + 0x18, // sun
            0x5568 + 0x18, // game_clock
            0x55f8 + 0x18, // debug_mode
            0x5620 + 0x18, // particle_systems_addr

            0x770 + 0x100, // game_selector

            0x7f5 + 0x120 + 4, // tod_mode

            0x7f8 + 0x120 + 4, // game_mode
            0x7fc + 0x120 + 4, // game_ui

            0x814 + 0x120 + 4, // free_planting

            0x820 + 0x120 + 4, // anim
            0x00,              //   unnamed
            0x00,              //     particle_system
            0x00,              //       particle_system_type
            0x1c,              //       particle_system_dead
            0x04,              //     particle_system_count_max

            0x82c + 0x120 + 4, // user_data
            0x24 + 0x28,       //   level
            0x28 + 0x28,       //   money
            0x2c + 0x28,       //   playthrough
            0x30 + 0x28,       //   mini_games
            0xf4 + 0x28,       //   tree_height
            0x1c0 + 0x28,      //   twiddydinky

            0x83c + 0x120 + 4, // music

            {0x006271fe, {0xfe}, {0xc8}}, // block_main_loop

            {0x0043cd11, {0xeb}, {0x7e}}, // unlock_sun_limit
            {0x0043d8c2, {0xeb}, {0x75}}, // auto_collected
            {0x0054cbf6, {0x66}, {0x5b}}, // not_drop_loot

            {0x0053594b, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x00535a43, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x00535565, {0x39}, {0xff}}, {0x005355e7, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x004394cd, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x0041c9ae, {0x81}, {0x84}},                                 // placed_anywhere
            {0x004453b0, {0xeb}, {0x74}},                                 // placed_anywhere_preview
            {0x004361e9, {0x8d}, {0x84}},                                 // placed_anywhere_iz
            {{0x0042f1ff, {0x80}, {0x8f}}, {0x004a030e, {0x33}, {0x85}}}, // fast_belt
            {0x0041efee, {0x39}, {0x89}},                                 // lock_shovel

            {0x00418381, {0x800f}, {0x840f}},             // rake_unlimited
            {0x004186a4 + 3, {0x01}, {0x00}},             // init_lawn_mowers
            {0x00466d60 + 2, {0x00728aac}, {0x00728c90}}, // lawn_mower_initialize

            {0x0054c67b, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_eat
            {0x0042949f, {0xeb}, {0x74}},                         // plant_immune_radius
            {0x00543d7a, {0xeb}, {0x75}},                         // plant_immune_jalapeno
            {0x0047d0db, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_projectile
            {0x0047d899, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_lob_motion
            {0x0054b2bb, {0xeb}, {0x74}},                         // plant_immune_square
            {0x0046df8a, {0x70}, {0x75}},                         // plant_immune_row_area
            {0x0046dde6, {0x00}, {0xce}},                         // plant_immune_spike_rock
            {0x00471dd0, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_squish

            {0x0054c67b, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_eat
            {0x0047d0db, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_projectile
            {0x0047d899, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_lob_motion
            {0x0046df8a, {0xeb}, {0x75}},                         // _plant_immune_row_area

            {0x0054dcca, {0x90909090}, {0x20246c2b}}, // zombie_immune_body_damage
            {0x0054d9e4, {0x2b, 0xc0}, {0x2b, 0xc8}}, // zombie_immune_helm_damage
            {0x0054d63b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_shield_damage
            {0x0054f561, {0x81}, {0x8d}},             // zombie_immune_burn_crumble
            {0x0042a183, {0xeb}, {0x7f}},             // zombie_immune_radius
            {0x004757b2, {0xeb}, {0x75}},             // zombie_immune_burn_row
            {0x00470658, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0054c40f, {0x00}, {0x01}},             // zombie_immune_mind_controll
            {0x004758c1, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blow_away
            {0x0047d543, {0xeb}, {0x74}},             // zombie_immune_splash
            {0x00467585, {0xeb}, {0x74}},             // zombie_immune_lawn_mower

            {0x0054dcca, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_body_damage
            {0x0054d9e4, {0x2b, 0xc9}, {0x2b, 0xc8}}, // _zombie_immune_helm_damage
            {0x0054d63b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_shield_damage
            {0x0054f561, {0x80}, {0x8d}},             // _zombie_immune_burn_crumble

            {0x0047025b, {0x80}, {0x85}},                                 // reload_instantly
            {{0x0046f074, {0x80}, {0x85}}, {0x0046edc3, {0x70}, {0x75}}}, // grow_up_quickly
            {{0x00470775, {0x70}, {0x75}}, {0x00471067, {0x80}, {0x85}}}, // no_cooldown
            {0x0046d012, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0043252c, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x00547433, {0x54}, {0x64}}, {0x0054743c, {0x54}, {0x44}}}, // stop_zombies
            {0x0046e392, {0x70}, {0x75}},                                 // lock_butter
            {0x0042a02d, {0x70}, {0x75}},                                 // no_crater
            {{0x005470b0, {0xc3}, {0x51}}, {0x0042bd29, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0054318c, {0x81}, {0x8f}}, {0x00543c6d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00446953, {0x80}, {0x85}}, // hack_street_zombies

            {0x00426dbd, {0xd231}, {0xf23b}},                     // no_fog
            {0x0045aa7a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x006226e9, {0x00eb}, {0x4074}},                     // background_running
            {0x0061df13, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00498b63, {0x00184b09 + 0x28}, {0x00184b09}},      // disable_save_userdata
            {0x00439fca, {0x38, 0x58, 0x64}, {0x88, 0x58, 0x64}}, // unlock_limbo_page

            0x004560d0, // call_sync_profile

            0x00418d90, // call_fade_out_level

            0x00439240, // call_wisdom_tree

            0x004199c0, // call_put_plant
            0x00475ea0, // call_put_plant_imitater
            0x00436440, // call_put_plant_iz_style
            0x00436000, // call_put_zombie
            0x0041a6b0, // call_put_zombie_in_row
            0x00432570, // call_put_grave
            0x00415960, // call_put_ladder
            0x00418360, // call_put_rake
            0x004184ba, // call_put_rake_row
            0x00418423, // call_put_rake_col

            0x00467af0, // call_start_lawn_mower
            0x00467a60, // call_delete_lawn_mower
            0x00418600, // call_restore_lawn_mower

            0x00476ce0, // call_delete_plant
            0x00459480, // call_delete_grid_item

            0x0046d9e0, // call_set_plant_sleeping

            0x00435d60, // call_puzzle_next_stage_clear
            0x00416ae0, // call_pick_background
            0x0052c250, // call_delete_particle_system

            0x00415d10, // call_pick_zombie_waves
            0x0041a8a0, // call_remove_cutscene_zombies
            0x00446940, // call_place_street_zombies

            0x0046a810, // call_play_music
        };

    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_NOT_FOUND, data_1_0_0_1051_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_OPEN_ERROR, data_1_0_0_1051_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_UNSUPPORTED, data_1_0_0_1051_en));

#ifdef _PVZ_BETA_LEAK_SUPPORT
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_BETA_0_1_1_1014_EN, data_beta_0_1_1_1014_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_BETA_0_9_9_1029_EN, data_beta_0_9_9_1029_en));
#endif

    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_0_0_1051_EN, data_1_0_0_1051_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_2_0_1065_EN, data_1_2_0_1065_en));

    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_0_4_7924_ES, data_1_0_4_7924_es));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_0_7_3556_ES, data_1_0_7_3556_es));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_0_7_3467_RU, data_1_0_7_3467_ru));

    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_GOTY_1_2_0_1073_EN, data_goty_1_2_0_1073_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_GOTY_1_2_0_1096_EN, data_goty_1_2_0_1096_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_GOTY_1_2_0_1093_DE_ES_FR_IT, data_goty_1_2_0_1093_de_es_fr_it));

    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_GOTY_1_1_0_1056_ZH, data_goty_1_1_0_1056_zh));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_GOTY_1_1_0_1056_JA, data_goty_1_1_0_1056_ja));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_GOTY_1_1_0_1056_ZH_2012_06, data_goty_1_1_0_1056_zh_2012_06));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_GOTY_1_1_0_1056_ZH_2012_07, data_goty_1_1_0_1056_zh_2012_07));
}

Data::~Data()
{
}

#ifdef _PVZ_BETA_LEAK_SUPPORT
bool Data::isBETA()
{
    return (this->find_result == PVZ_BETA_0_1_1_1014_EN      //
            || this->find_result == PVZ_BETA_0_9_9_1029_EN); //
}
#endif

bool Data::isGOTY()
{
    return (this->find_result == PVZ_GOTY_1_2_0_1073_EN              //
            || this->find_result == PVZ_GOTY_1_2_0_1096_EN           //
            || this->find_result == PVZ_GOTY_1_2_0_1093_DE_ES_FR_IT  //
            || this->find_result == PVZ_GOTY_1_1_0_1056_ZH           //
            || this->find_result == PVZ_GOTY_1_1_0_1056_JA           //
            || this->find_result == PVZ_GOTY_1_1_0_1056_ZH_2012_06   //
            || this->find_result == PVZ_GOTY_1_1_0_1056_ZH_2012_07); //
}

PVZ_DATA Data::data()
{
    return this->ver_map[this->find_result];
}

} // namespace Pt
