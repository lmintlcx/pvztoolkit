
#include <iostream>
#include <string>
#include <algorithm>

#include "pvz.h"

#include <Windows.h>

namespace Pt
{

PvZ::PvZ()
{
    this->find_result = PVZ_NOT_FOUND;

    this->cb_find_result = nullptr;
    this->window = nullptr;

    this->data_1_0_0_1051_en =
        {
            0x6a9ec0, // pvz_base

            0x454, // ms_per_frame

            0x768, // main_object

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

            0x15c, // spawn_preview

            0x160, // indirect_base
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
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // background_music

            {0x00552014, {0xfe}, {0xdb}}, // safe_thread

            {0x0043158f, {0xeb}, {0x75}},             // auto_collect
            {0x0041d025, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x0051f017, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x0051f110, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x0051ec38, {0x00}, {0xff}}, {0x0051ecb8, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042d463, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x0040fe30, {0x81}, {0x84}},                                 // planting_anywhere
            {0x00438e40, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x0042a2d9, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x00422d20, {0x80}, {0x8f}}, {0x00489ca1, {0x33}, {0x85}}}, // fast_belt
            {0x004123a3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040b9e2, {0x800f}, {0x840f}},             // hack_put_rake
            {0x0040bc98, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x0040bd14 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x00458000 + 2, {0x006799fc}, {0x00679bf8}}, // restore_lawn_mower_3

            {0x0052fcf1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x0041cc2f, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x005276ea, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x0046cfeb, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x0046d7a6, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x0052e93b, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x0045ee0a, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x0045ec66, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00462b80, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x0052fcf1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x0046cfeb, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x0046d7a6, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x0045ee0a, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x0053130f, {0x90909090}, {0x20247c2b}}, // zombie_immune_damage
            {0x00531045, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x00530c9b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x00532ba1, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x0041d8ff, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x004664f2, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x0046144a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0052fa82, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x00466601, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x0046d455, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x00458836, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x0053130f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_damage
            {0x00531045, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x00530c9b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x00532ba1, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x0046103b, {0x80}, {0x85}},                                 // reload_instantly
            {0x0045de8e, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004265dc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052ab2b, {0x54}, {0x64}}, {0x0052ab34, {0x54}, {0x44}}}, // stop_zombies
            {0x0045f1ec, {0x70}, {0x75}},                                 // lock_butter
            {0x0041d79e, {0x70}, {0x75}},                                 // no_crater
            {{0x0052a7b0, {0xc3}, {0x51}}, {0x0041f79a, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x00526afc, {0x81}, {0x8f}}, {0x005275dd, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043a153, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0041a68d, {0xd231}, {0xf23b}},                     // no_fog
            {0x0044e5cc, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x0054eba8, {0x00eb}, {0x2e74}},                     // background_running
            {0x0054b267, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00482149, {0x000c8b13 + 0x1b}, {0x000c8b13}},      // disable_save_userdata
            {0x0042df5d, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0044faf0, // call_update_main_ui
            0x0044f8e0, // call_reload_main_ui

            0x0040c3e0, // call_level_complete

            0x0042d1f0, // call_wisdom_tree

            0x0040d120, // call_put_plant
            0x00466b80, // call_put_plant_imitater
            0x0042a530, // call_put_plant_iz_style
            0x0042a0f0, // call_put_zombie
            0x0040ddc0, // call_put_zomboss
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

            0x0045e860, // call_wakeup_plant

            0x0040a160, // call_set_background
            0x005160c0, // call_delete_particle_system

            0x004092e0, // call_generate_spawn_list
            0x0040df70, // call_clear_spawn_preview
            0x0043a140, // call_update_spawn_preview

            0x0045b750, // call_set_music
        };

    this->data_1_2_0_1065_en =
        {
            0x6a9ec0, // pvz_base

            0x454, // ms_per_frame

            0x768, // main_object

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

            0x15c, // spawn_preview

            0x160, // indirect_base
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
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // background_music

            {0x00552244, {0xfe}, {0xdb}}, // safe_thread

            {0x004315ef, {0xeb}, {0x75}},             // auto_collect
            {0x0041d055, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x0051f367, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x0051f460, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x0051ef88, {0x00}, {0xff}}, {0x0051f008, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042d4c3, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x0040fe20, {0x81}, {0x84}},                                 // planting_anywhere
            {0x00438eb0, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x0042a339, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x00422d80, {0x80}, {0x8f}}, {0x00489ff1, {0x33}, {0x85}}}, // fast_belt
            {0x00412393, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040b9f2, {0x800f}, {0x840f}},             // hack_put_rake
            {0x0040bca8, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x0040bd24 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x00458160 + 2, {0x00679b5c}, {0x00679d58}}, // restore_lawn_mower_3

            {0x00530041, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x0041cc5f, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x00527a3a, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x0046d32b, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x0046dae6, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x0052ec8b, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x0045ef0a, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x0045ed66, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00462d00, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x00530041, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x0046d32b, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x0046dae6, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x0045ef0a, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x0053165f, {0x90909090}, {0x20247c2b}}, // zombie_immune_damage
            {0x00531395, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x00530feb, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x00532ef1, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x0041d933, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x00466672, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x004615ca, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0052fdd2, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x00466781, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x0046d795, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x00458996, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x0053165f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_damage
            {0x00531395, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x00530feb, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x00532ef1, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x004611bb, {0x80}, {0x85}},                                 // reload_instantly
            {0x0045df8e, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042663c, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052ae7b, {0x54}, {0x64}}, {0x0052ae84, {0x54}, {0x44}}}, // stop_zombies
            {0x0045f2ec, {0x70}, {0x75}},                                 // lock_butter
            {0x0041d7ce, {0x70}, {0x75}},                                 // no_crater
            {{0x0052ab00, {0xc3}, {0x51}}, {0x0041f7fa, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x00526e4c, {0x81}, {0x8f}}, {0x0052792d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043a1c3, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0041a6ad, {0xd231}, {0xf23b}},                     // no_fog
            {0x0044e71c, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x0054edd8, {0x00eb}, {0x2e74}},                     // background_running
            {0x0054b497, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00482499, {0x000c89f3 + 0x1b}, {0x000c89f3}},      // disable_save_userdata
            {0x0042dfbd, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0044fc30, // call_update_main_ui
            0x0044fa20, // call_reload_main_ui

            0x0040c3f0, // call_level_complete

            0x0042d250, // call_wisdom_tree

            0x0040d130, // call_put_plant
            0x00466d00, // call_put_plant_imitater
            0x0042a590, // call_put_plant_iz_style
            0x0042a150, // call_put_zombie
            0x0040ddd0, // call_put_zomboss
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

            0x0045e960, // call_wakeup_plant

            0x0040a170, // call_set_background
            0x005163b0, // call_delete_particle_system

            0x004092f0, // call_generate_spawn_list
            0x0040df80, // call_clear_spawn_preview
            0x0043a1b0, // call_update_spawn_preview

            0x0045b8b0, // call_set_music
        };

    this->data_1_0_4_7924_es =
        {
            0x6b9fe0, // pvz_base

            0x454, // ms_per_frame

            0x768, // main_object

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

            0x15c, // spawn_preview

            0x160, // indirect_base
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
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // background_music

            {0x005581c4, {0xfe}, {0xdb}}, // safe_thread

            {0x0043327f, {0xeb}, {0x75}},             // auto_collect
            {0x0041e9b5, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x00523497, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x00523590, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x005230b8, {0x00}, {0xff}}, {0x00523138, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042f103, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x00411370, {0x81}, {0x84}},                                 // planting_anywhere
            {0x0043ac50, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x0042bf49, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x00424960, {0x80}, {0x8f}}, {0x0048da11, {0x33}, {0x85}}}, // fast_belt
            {0x004138f3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040cef2, {0x800f}, {0x840f}},             // hack_put_rake
            {0x0040d1a8, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x0040d224 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x0045b490 + 2, {0x00688cc4}, {0x00688eb8}}, // restore_lawn_mower_3

            {0x00534161, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x0041e5bf, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x0052bb5a, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x00470aeb, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x004712a6, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x00532dab, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x004625da, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x00462436, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x004663d0, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x00534161, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x00470aeb, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x004712a6, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x004625da, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x0053577f, {0x90909090}, {0x20247c2b}}, // zombie_immune_damage
            {0x005354b5, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x0053510b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x00537011, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x0041f28f, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x00469d42, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x00464c9a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00533ef2, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x00469e51, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x00470f55, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x0045bcc6, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x0053577f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_damage
            {0x005354b5, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x0053510b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x00537011, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x0046488b, {0x80}, {0x85}},                                 // reload_instantly
            {0x0046165e, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042826c, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052ef9b, {0x54}, {0x64}}, {0x0052efa4, {0x54}, {0x44}}}, // stop_zombies
            {0x004629bc, {0x70}, {0x75}},                                 // lock_butter
            {0x0041f12e, {0x70}, {0x75}},                                 // no_crater
            {{0x0052ec20, {0xc3}, {0x51}}, {0x004213ea, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0052af6c, {0x81}, {0x8f}}, {0x0052ba4d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043c1e3, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0041bffd, {0xd231}, {0xf23b}},                     // no_fog
            {0x004513bc, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x00554cd8, {0x00eb}, {0x2e74}},                     // background_running
            {0x00551377, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00485e99, {0x000caed3 + 0x1b}, {0x000caed3}},      // disable_save_userdata
            {0x0042fc18, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x00452920, // call_update_main_ui
            0x00452710, // call_reload_main_ui

            0x0040d8f0, // call_level_complete

            0x0042ee90, // call_wisdom_tree

            0x0040e620, // call_put_plant
            0x0046a3d0, // call_put_plant_imitater
            0x0042c1a0, // call_put_plant_iz_style
            0x0042bd60, // call_put_zombie
            0x0040f2c0, // call_put_zomboss
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

            0x00462030, // call_wakeup_plant

            0x0040b670, // call_set_background
            0x0051a350, // call_delete_particle_system

            0x0040a7f0, // call_generate_spawn_list
            0x0040f470, // call_clear_spawn_preview
            0x0043c1d0, // call_update_spawn_preview

            0x0045eda0, // call_set_music
        };

    this->data_1_0_7_3556_es =
        {
            0x6ba008, // pvz_base

            0x454, // ms_per_frame

            0x768, // main_object

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

            0x15c, // spawn_preview

            0x160, // indirect_base
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
            0xf4,  //   tree_height
            0x1c0, //   twiddydinky

            0x83c, // background_music

            {0x00558344, {0xfe}, {0xdb}}, // safe_thread

            {0x004331df, {0xeb}, {0x75}},             // auto_collect
            {0x0041e975, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x005234e7, {0x00}, {0xff}},                                 // fertilizer_unlimited
            {0x005235e1, {0x00}, {0xff}},                                 // bug_spray_unlimited
            {{0x00523108, {0x00}, {0xff}}, {0x00523188, {0x00}, {0xff}}}, // chocolate_unlimited
            {0x0042f053, {0x00}, {0xff}},                                 // tree_food_unlimited

            {0x00411340, {0x81}, {0x84}},                                 // planting_anywhere
            {0x0043abc0, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x0042be99, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x004248b0, {0x80}, {0x8f}}, {0x0048d9b1, {0x33}, {0x85}}}, // fast_belt
            {0x004138c3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040cec2, {0x800f}, {0x840f}},             // hack_put_rake
            {0x0040d178, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x0040d1f4 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x0045b4f0 + 2, {0x00688d4c}, {0x00688f40}}, // restore_lawn_mower_3

            {0x005341f1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x0041e57f, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x0052bbca, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x00470b6b, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x00471326, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x00532e3b, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x0046268a, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x004624e6, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00466480, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x005341f1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x00470b6b, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x00471326, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x0046268a, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x0053580f, {0x90909090}, {0x20247c2b}}, // zombie_immune_damage
            {0x00535545, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x0053519b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x005370a1, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x0041f24f, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x00469df2, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x00464d4a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00533f82, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x00469f01, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x00470fd5, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x0045bd26, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x0053580f, {0x9090ff2b}, {0x20247c2b}}, // _zombie_immune_damage
            {0x00535545, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x0053519b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x005370a1, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x0046493b, {0x80}, {0x85}},                                 // reload_instantly
            {0x0046170e, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004281bc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0052f02b, {0x54}, {0x64}}, {0x0052f034, {0x54}, {0x44}}}, // stop_zombies
            {0x00462a6c, {0x70}, {0x75}},                                 // lock_butter
            {0x0041f0ee, {0x70}, {0x75}},                                 // no_crater
            {{0x0052ecb0, {0xc3}, {0x51}}, {0x0042133a, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0052afdc, {0x81}, {0x8f}}, {0x0052babd, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043c153, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0041bfcd, {0xd231}, {0xf23b}},                     // no_fog
            {0x0045143c, {0x0033b866}, {0x067ec085}},             // see_vase
            {0x00554e58, {0x00eb}, {0x2e74}},                     // background_running
            {0x005514f7, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00485eb9, {0x000cb033 + 0x1b}, {0x000cb033}},      // disable_save_userdata
            {0x0042fb68, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x004529a0, // call_update_main_ui
            0x00452790, // call_reload_main_ui

            0x0040d8c0, // call_level_complete

            0x0042ede0, // call_wisdom_tree

            0x0040e5f0, // call_put_plant
            0x0046a480, // call_put_plant_imitater
            0x0042c0f0, // call_put_plant_iz_style
            0x0042bcb0, // call_put_zombie
            0x0040f290, // call_put_zomboss
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

            0x004620e0, // call_wakeup_plant

            0x0040b640, // call_set_background
            0x0051a330, // call_delete_particle_system

            0x0040a7c0, // call_generate_spawn_list
            0x0040f440, // call_clear_spawn_preview
            0x0043c140, // call_update_spawn_preview

            0x0045ee00, // call_set_music
        };

    this->data_1_2_0_1073_en =
        {
            0x729670, // pvz_base

            0x454 + 0x60, // ms_per_frame

            0x768 + 0x100, // main_object

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

            0x15c + 0x18, // spawn_preview

            0x160 + 0x18, // indirect_base
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
            0xf4 + 0x28,   //   tree_height
            0x1c0 + 0x28,  //   twiddydinky

            0x83c + 0x120, // background_music

            {0x005d6c6e, {0xfe}, {0xc8}}, // safe_thread

            {0x004342f2, {0xeb}, {0x75}},             // auto_collect
            {0x0041fde6, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x0052992b, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x00529a23, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x00529545, {0x39}, {0xff}}, {0x005295c7, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x0043018d, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x004127f0, {0x81}, {0x84}},                                 // planting_anywhere
            {0x0043c030, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x0042ce79, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x004257ff, {0x80}, {0x8f}}, {0x004948ae, {0x33}, {0x85}}}, // fast_belt
            {0x00414d53, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040e291, {0x800f}, {0x840f}},             // hack_put_rake
            {0x0040e538, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x0040e5b4 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x0045b8d0 + 2, {0x006fe1e4}, {0x006fe3c8}}, // restore_lawn_mower_3

            {0x00540681, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x0041f9ef, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x00537d7a, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x0047169b, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x00471e59, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x0053f2bb, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x0046273a, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x00462596, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00466580, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x00540681, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x0047169b, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x00471e59, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x0046273a, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x00541cda, {0x90909090}, {0x20246c2b}}, // zombie_immune_damage
            {0x005419f5, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x0054164b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x00543571, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x004206d3, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x00469f62, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x00464e08, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0054040f, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x0046a071, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x00471b03, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x0045c0f5, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x00541cda, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_damage
            {0x005419f5, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x0054164b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x00543571, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x00464a0b, {0x80}, {0x85}},                                 // reload_instantly
            {0x004617c2, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004290dc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0053b433, {0x54}, {0x64}}, {0x0053b43c, {0x54}, {0x44}}}, // stop_zombies
            {0x00462b42, {0x70}, {0x75}},                                 // lock_butter
            {0x0042057d, {0x70}, {0x75}},                                 // no_crater
            {{0x0053b0b0, {0xc3}, {0x51}}, {0x004222ea, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0053718c, {0x81}, {0x8f}}, {0x00537c6d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043d363, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0041d17d, {0xd231}, {0xf23b}},                     // no_fog
            {0x004518aa, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x005d21d9, {0x00eb}, {0x4074}},                     // background_running
            {0x005cd993, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x0048cd63, {0x00140389 + 0x28}, {0x00140389}},      // disable_save_userdata
            {0x00430c80, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x00452d80, // call_update_main_ui
            0x00452b80, // call_reload_main_ui

            0x0040ecd0, // call_level_complete

            0x0042ff00, // call_wisdom_tree

            0x0040fa10, // call_put_plant
            0x0046a630, // call_put_plant_imitater
            0x0042d0d0, // call_put_plant_iz_style
            0x0042cc90, // call_put_zombie
            0x00410700, // call_put_zomboss
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

            0x00462190, // call_wakeup_plant

            0x0040c9f0, // call_set_background
            0x00520770, // call_delete_particle_system

            0x0040bc20, // call_generate_spawn_list
            0x004108e0, // call_clear_spawn_preview
            0x0043d350, // call_update_spawn_preview

            0x0045efa0, // call_set_music
        };

    this->data_1_2_0_1096_en =
        {
            0x731c50, // pvz_base

            0x454 + 0x60, // ms_per_frame

            0x768 + 0x100, // main_object

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

            0x15c + 0x18, // spawn_preview

            0x160 + 0x18, // indirect_base
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
            0xf4 + 0x28 + 4,  //   tree_height
            0x1c0 + 0x28 + 4, //   twiddydinky

            0x83c + 0x120, // background_music

            {0x005dd25e, {0xfe}, {0xc8}}, // safe_thread

            {0x004352f2, {0xeb}, {0x75}},             // auto_collect
            {0x00420bd6, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x0052da8b, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x0052db83, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x0052d6a5, {0x39}, {0xff}}, {0x0052d727, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x004311ed, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x00413350, {0x81}, {0x84}},                                 // planting_anywhere
            {0x0043d100, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x0042dec9, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x0042684f, {0x80}, {0x8f}}, {0x0049831e, {0x33}, {0x85}}}, // fast_belt
            {0x004158b3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040ee41, {0x800f}, {0x840f}},             // hack_put_rake
            {0x0040f0e8, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x0040f164 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x0045e220 + 2, {0x00706704}, {0x007068e8}}, // restore_lawn_mower_3

            {0x005447a1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x004207df, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x0053beda, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x00474ffb, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x004757b9, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x005433ab, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x0046511a, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x00464f76, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00468f60, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x005447a1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x00474ffb, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x004757b9, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x0046511a, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x00545dfa, {0x90909090}, {0x20246c2b}}, // zombie_immune_damage
            {0x00545b15, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x0054576b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x00547691, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x004214c3, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x0046c942, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x004677e8, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00544501, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x0046ca51, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x00475463, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x0045ea45, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x00545dfa, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_damage
            {0x00545b15, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x0054576b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x00547691, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x004673eb, {0x80}, {0x85}},                                 // reload_instantly
            {0x004641a2, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042a12c, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0053f533, {0x54}, {0x64}}, {0x0053f53c, {0x54}, {0x44}}}, // stop_zombies
            {0x00465522, {0x70}, {0x75}},                                 // lock_butter
            {0x0042136d, {0x70}, {0x75}},                                 // no_crater
            {{0x0053f1b0, {0xc3}, {0x51}}, {0x0042333a, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0053b2ec, {0x81}, {0x8f}}, {0x0053bdcd, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043e6a3, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0041df4d, {0xd231}, {0xf23b}},                     // no_fog
            {0x004531ca, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x005d87c9, {0x00eb}, {0x4074}},                     // background_running
            {0x005d3fd3, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x004907ea, {0x00142f42 + 0x28}, {0x00142f42}},      // disable_save_userdata
            {0x00431ce0, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x00454830, // call_update_main_ui
            0x00454630, // call_reload_main_ui

            0x0040f860, // call_level_complete

            0x00430f60, // call_wisdom_tree

            0x004105a0, // call_put_plant
            0x0046d010, // call_put_plant_imitater
            0x0042e120, // call_put_plant_iz_style
            0x0042dce0, // call_put_zombie
            0x00411290, // call_put_zomboss
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

            0x00464b70, // call_wakeup_plant

            0x0040d5a0, // call_set_background
            0x00524840, // call_delete_particle_system

            0x0040c7d0, // call_generate_spawn_list
            0x00411470, // call_clear_spawn_preview
            0x0043e690, // call_update_spawn_preview

            0x004618f0, // call_set_music
        };

    this->data_1_2_0_1093_de_es_fr_it =
        {
            0x73d7e8, // pvz_base

            0x454 + 0x60, // ms_per_frame

            0x768 + 0x100, // main_object

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

            0x15c + 0x18, // spawn_preview

            0x160 + 0x18, // indirect_base
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
            0xf4 + 0x28,   //   tree_height
            0x1c0 + 0x28,  //   twiddydinky

            0x83c + 0x120, // background_music

            {0x005dee1e, {0xfe}, {0xc8}}, // safe_thread

            {0x004362d2, {0xeb}, {0x75}},             // auto_collect
            {0x00421786, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x0052ddab, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x0052dea3, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x0052d9c5, {0x39}, {0xff}}, {0x0052da47, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x004321cd, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x00413b60, {0x81}, {0x84}},                                 // planting_anywhere
            {0x0043df40, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x0042ee69, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x0042775f, {0x80}, {0x8f}}, {0x004985fe, {0x33}, {0x85}}}, // fast_belt
            {0x004160e3, {0x39}, {0x89}},                                 // lock_shovel

            {0x0040f531, {0x800f}, {0x840f}},             // hack_put_rake
            {0x0040f7d8, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x0040f854 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x0045f110 + 2, {0x00711ee4}, {0x007120c8}}, // restore_lawn_mower_3

            {0x00544aa1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x0042138f, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x0053c20a, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x0047531b, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x00475ad9, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x005436db, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x004661ba, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x00466016, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x0046a000, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x00544aa1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x0047531b, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x00475ad9, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x004661ba, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x005460fa, {0x90909090}, {0x20246c2b}}, // zombie_immune_damage
            {0x00545e15, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x00545a6b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x00547991, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x00422073, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x0046d9e2, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x00468888, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0054482f, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x0046daf1, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x00475783, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x0045f935, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x005460fa, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_damage
            {0x00545e15, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x00545a6b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x00547991, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x0046848b, {0x80}, {0x85}},                                 // reload_instantly
            {0x00465242, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042b0dc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0053f863, {0x54}, {0x64}}, {0x0053f86c, {0x54}, {0x44}}}, // stop_zombies
            {0x004665c2, {0x70}, {0x75}},                                 // lock_butter
            {0x00421f1d, {0x70}, {0x75}},                                 // no_crater
            {{0x0053f4e0, {0xc3}, {0x51}}, {0x004241da, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0053b61c, {0x81}, {0x8f}}, {0x0053c0fd, {0x81}, {0x85}}}, // zombie_not_explode

            {0x0043f4e3, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0041ea6d, {0xd231}, {0xf23b}},                     // no_fog
            {0x0045484a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x005da319, {0x00eb}, {0x4074}},                     // background_running
            {0x005d5b43, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00490af3, {0x001447a9 + 0x28}, {0x001447a9}},      // disable_save_userdata
            {0x00432cdf, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x00455d90, // call_update_main_ui
            0x00455b90, // call_reload_main_ui

            0x0040ff50, // call_level_complete

            0x00431f40, // call_wisdom_tree

            0x00410c50, // call_put_plant
            0x0046e0b0, // call_put_plant_imitater
            0x0042f0d0, // call_put_plant_iz_style
            0x0042ec80, // call_put_zombie
            0x00411940, // call_put_zomboss
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

            0x00465c10, // call_wakeup_plant

            0x0040dc90, // call_set_background
            0x005247d0, // call_delete_particle_system

            0x0040cec0, // call_generate_spawn_list
            0x00411b20, // call_clear_spawn_preview
            0x0043f4d0, // call_update_spawn_preview

            0x00462980, // call_set_music
        };

    this->data_1_1_0_1056_zh =
        {
            0x7794f8, // pvz_base

            0x454 + 0x60, // ms_per_frame

            0x768 + 0x100, // main_object

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

            0x15c + 0x18, // spawn_preview

            0x160 + 0x18, // indirect_base
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
            0xf4 + 0x28,       //   tree_height
            0x1c0 + 0x28,      //   twiddydinky

            0x83c + 0x120 + 4, // background_music

            {0x005cfd4e, {0xfe}, {0xc8}}, // safe_thread

            {0x0044c5f2, {0xeb}, {0x75}},             // auto_collect
            {0x00435854, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x0054e0a4, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x0054e171, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x0054ddc3, {0x39}, {0xff}}, {0x0054de0a, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x00447d49, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x00425954, {0x81}, {0x84}},                                 // planting_anywhere
            {0x00454b67, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x004449e8, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x0043b8bf, {0x80}, {0x8f}}, {0x004b5b8e, {0x33}, {0x85}}}, // fast_belt
            {0x00427f13, {0x39}, {0x89}},                                 // lock_shovel

            {0x00420fc2, {0x800f}, {0x840f}},             // hack_put_rake
            {0x00421218, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x00421293 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x0047b807 + 2, {0x00746664}, {0x00746ab8}}, // restore_lawn_mower_3

            {0x005654c1, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x004354af, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x0055d00a, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x004920e5, {0x90, 0x90, 0x90}, {0x29, 0x46, 0x40}}, // plant_immune_pea
            {0x00492942, {0x90, 0x90, 0x90}, {0x29, 0x56, 0x40}}, // plant_immune_ball
            {0x0056404b, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x00482e33, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x00482ccb, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00486c90, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x005654c1, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x004920e5, {0x29, 0x76, 0x40}, {0x29, 0x46, 0x40}}, // _plant_immune_pea
            {0x00492942, {0x29, 0x76, 0x40}, {0x29, 0x56, 0x40}}, // _plant_immune_ball
            {0x00482e33, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x00566d06, {0x90909090}, {0x2024742b}}, // zombie_immune_damage
            {0x00566891, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x005663f8, {0xf633c033}, {0xf38b027c}}, // zombie_immune_type2
            {0x00568626, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x004361ee, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x0048a792, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x0048550a, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x00565243, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x0048a8b0, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x004925b3, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x0047bf85, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x00566d06, {0x9090f631}, {0x2024742b}}, // _zombie_immune_damage
            {0x00566891, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x005663f8, {0xf38bde8b}, {0xf38b027c}}, // _zombie_immune_type2
            {0x00568626, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x0048517c, {0x80}, {0x85}},                                 // reload_instantly
            {0x00481c44, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0043f17e, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x005604d7, {0x54}, {0x64}}, {0x005604e0, {0x54}, {0x44}}}, // stop_zombies
            {0x00483207, {0x70}, {0x75}},                                 // lock_butter
            {0x0043609d, {0x70}, {0x75}},                                 // no_crater
            {{0x00560150, {0xc3}, {0x51}}, {0x004385f6, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0055c5cc, {0x81}, {0x8f}}, {0x0055cf7a, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00456858, {0x80}, {0x85}}, // hack_spawn_preview

            {0x00430d9d, {0xd231}, {0xf23b}},                     // no_fog
            {0x0046df1a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x005cb249, {0x00eb}, {0x4074}},                     // background_running
            {0x005c6a73, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x004adf93, {0x00118239 + 0x28}, {0x00118239}},      // disable_save_userdata
            {0x0044895a, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x004720d0, // call_update_main_ui
            0x00471ed0, // call_reload_main_ui

            0x00421a20, // call_level_complete

            0x00447b20, // call_wisdom_tree

            0x00422610, // call_put_plant
            0x0048ae60, // call_put_plant_imitater
            0x00444c10, // call_put_plant_iz_style
            0x00444860, // call_put_zombie
            0x004236d0, // call_put_zomboss
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

            0x00482900, // call_wakeup_plant

            0x0041f3d0, // call_set_background
            0x005435f0, // call_delete_particle_system

            0x0041e840, // call_generate_spawn_list
            0x004238d0, // call_clear_spawn_preview
            0x00456840, // call_update_spawn_preview

            0x0047f240, // call_set_music
        };

    this->data_1_1_0_1056_ja =
        {
            0x7578f8, // pvz_base

            0x454 + 0x60, // ms_per_frame

            0x768 + 0x100, // main_object

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

            0x15c + 0x18, // spawn_preview

            0x160 + 0x18, // indirect_base
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
            0xf4 + 0x28,   //   tree_height
            0x1c0 + 0x28,  //   twiddydinky

            0x83c + 0x120, // background_music

            {0x00627ade, {0xfe}, {0xc8}}, // safe_thread

            {0x0043b3a2, {0xeb}, {0x75}},             // auto_collect
            {0x00424784, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x0053c864, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x0053c931, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x0053c583, {0x39}, {0xff}}, {0x0053c5ca, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x004368c9, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x004156b4, {0x81}, {0x84}},                                 // planting_anywhere
            {0x00443797, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x004334d8, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x0042ac2f, {0x80}, {0x8f}}, {0x004a411e, {0x33}, {0x85}}}, // fast_belt
            {0x00417c9b, {0x39}, {0x89}},                                 // lock_shovel

            {0x00410e12, {0x800f}, {0x840f}},             // hack_put_rake
            {0x00411068, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x004110e3 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x0046a117 + 2, {0x0072a8dc}, {0x0072ad30}}, // restore_lawn_mower_3

            {0x00553c3b, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x004243df, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x0054b78a, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x004809a5, {0x90, 0x90, 0x90}, {0x29, 0x46, 0x40}}, // plant_immune_pea
            {0x00481200, {0x90, 0x90, 0x90}, {0x29, 0x56, 0x40}}, // plant_immune_ball
            {0x005527cb, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x004716e3, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x0047157b, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00475540, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x00553c3b, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x004809a5, {0x29, 0x76, 0x40}, {0x29, 0x46, 0x40}}, // _plant_immune_pea
            {0x00481200, {0x29, 0x76, 0x40}, {0x29, 0x56, 0x40}}, // _plant_immune_ball
            {0x004716e3, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x00555476, {0x90909090}, {0x2024742b}}, // zombie_immune_damage
            {0x00555001, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x00554b68, {0xf633c033}, {0xf38b027c}}, // zombie_immune_type2
            {0x00556d96, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x0042511e, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x00479042, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x00473dba, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x005539c3, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x00479160, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x00480e73, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x0046a895, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x00555476, {0x9090f631}, {0x2024742b}}, // _zombie_immune_damage
            {0x00555001, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x00554b68, {0xf38bde8b}, {0xf38b027c}}, // _zombie_immune_type2
            {0x00556d96, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x00473a2c, {0x80}, {0x85}},                                 // reload_instantly
            {0x004704f4, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0042dd5e, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x0054ec57, {0x54}, {0x64}}, {0x0054ec60, {0x54}, {0x44}}}, // stop_zombies
            {0x00471ab7, {0x70}, {0x75}},                                 // lock_butter
            {0x00424fcd, {0x70}, {0x75}},                                 // no_crater
            {{0x0054e8d0, {0xc3}, {0x51}}, {0x004278c6, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0054ad4c, {0x81}, {0x8f}}, {0x0054b6fa, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00445488, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0041fcbd, {0xd231}, {0xf23b}},                     // no_fog
            {0x0045c66a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x00622fd9, {0x00eb}, {0x4074}},                     // background_running
            {0x0061e7f3, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x0049c733, {0x00181819 + 0x28}, {0x00181819}},      // disable_save_userdata
            {0x004374da, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x004605d0, // call_update_main_ui
            0x004603d0, // call_reload_main_ui

            0x00411880, // call_level_complete

            0x004366a0, // call_wisdom_tree

            0x00412370, // call_put_plant
            0x00479720, // call_put_plant_imitater
            0x00433700, // call_put_plant_iz_style
            0x00433330, // call_put_zombie
            0x00413430, // call_put_zomboss
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

            0x004711b0, // call_wakeup_plant

            0x0040f220, // call_set_background
            0x00531c40, // call_delete_particle_system

            0x0040e690, // call_generate_spawn_list
            0x00413630, // call_clear_spawn_preview
            0x00445470, // call_update_spawn_preview

            0x0046dcf0, // call_set_music
        };

    this->data_1_1_0_1056_zh_2012_06 =
        {
            0x755e0c, // pvz_base

            0x454 + 0x60, // ms_per_frame

            0x768 + 0x100, // main_object

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

            0x15c + 0x18, // spawn_preview

            0x160 + 0x18, // indirect_base
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
            0xf4 + 0x28,       //   tree_height
            0x1c0 + 0x28,      //   twiddydinky

            0x83c + 0x120 + 4, // background_music

            {0x0062941e, {0xfe}, {0xc8}}, // safe_thread

            {0x0043cc72, {0xeb}, {0x75}},             // auto_collect
            {0x00428c36, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x00534d7b, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x00534e73, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x00534995, {0x39}, {0xff}}, {0x00534a17, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x0043885d, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x0041bd2e, {0x81}, {0x84}},                                 // planting_anywhere
            {0x00444790, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x00435579, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x0042e58f, {0x80}, {0x8f}}, {0x0049f6fe, {0x33}, {0x85}}}, // fast_belt
            {0x0041e36e, {0x39}, {0x89}},                                 // lock_shovel

            {0x00417731, {0x800f}, {0x840f}},             // hack_put_rake
            {0x004179d8, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x00417a54 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x00465f60 + 2, {0x00727894}, {0x00727a78}}, // restore_lawn_mower_3

            {0x0054ba6b, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x0042883f, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x0054316a, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x0047c3db, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x0047cb99, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x0054a6ab, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x0046d13a, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x0046cf96, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00470f80, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x0054ba6b, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x0047c3db, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x0047cb99, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x0046d13a, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x0054d0ba, {0x90909090}, {0x20246c2b}}, // zombie_immune_damage
            {0x0054cdd5, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x0054ca2b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x0054e951, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x00429523, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x00474962, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x0046f808, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0054b7ff, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x00474a71, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x0047c843, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x00466785, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x0054d0ba, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_damage
            {0x0054cdd5, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x0054ca2b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x0054e951, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x0046f40b, {0x80}, {0x85}},                                 // reload_instantly
            {0x0046c1c2, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x004318bc, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x00546823, {0x54}, {0x64}}, {0x0054682c, {0x54}, {0x44}}}, // stop_zombies
            {0x0046d542, {0x70}, {0x75}},                                 // lock_butter
            {0x004293cd, {0x70}, {0x75}},                                 // no_crater
            {{0x005464a0, {0xc3}, {0x51}}, {0x0042b0b9, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0054257c, {0x81}, {0x8f}}, {0x0054305d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00445d33, {0x80}, {0x85}}, // hack_spawn_preview

            {0x0042616d, {0xd231}, {0xf23b}},                     // no_fog
            {0x00459c1a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x00624919, {0x00eb}, {0x4074}},                     // background_running
            {0x00620143, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00497ed3, {0x001879c9 + 0x28}, {0x001879c9}},      // disable_save_userdata
            {0x0043935a, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0045c6a0, // call_update_main_ui
            0x0045c4a0, // call_reload_main_ui

            0x00418140, // call_level_complete

            0x004385d0, // call_wisdom_tree

            0x00418d70, // call_put_plant
            0x00475050, // call_put_plant_imitater
            0x004357d0, // call_put_plant_iz_style
            0x00435390, // call_put_zombie
            0x00419a60, // call_put_zomboss
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

            0x0046cb90, // call_wakeup_plant

            0x00415e90, // call_set_background
            0x0052b620, // call_delete_particle_system

            0x004150c0, // call_generate_spawn_list
            0x00419c50, // call_clear_spawn_preview
            0x00445d20, // call_update_spawn_preview

            0x00469a10, // call_set_music
        };

    this->data_1_1_0_1056_zh_2012_07 =
        {
            0x757e0c, // pvz_base

            0x454 + 0x60, // ms_per_frame

            0x768 + 0x100, // main_object

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

            0x15c + 0x18, // spawn_preview

            0x160 + 0x18, // indirect_base
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
            0xf4 + 0x28,       //   tree_height
            0x1c0 + 0x28,      //   twiddydinky

            0x83c + 0x120 + 4, // background_music

            {0x006271fe, {0xfe}, {0xc8}}, // safe_thread

            {0x0043d8c2, {0xeb}, {0x75}},             // auto_collect
            {0x00429896, {0x90, 0xe9}, {0x0f, 0x8f}}, // zombie_no_falling

            {0x0053594b, {0x39}, {0xff}},                                 // fertilizer_unlimited
            {0x00535a43, {0x39}, {0xff}},                                 // bug_spray_unlimited
            {{0x00535565, {0x39}, {0xff}}, {0x005355e7, {0x39}, {0xff}}}, // chocolate_unlimited
            {0x004394cd, {0x39}, {0xff}},                                 // tree_food_unlimited

            {0x0041c9ae, {0x81}, {0x84}},                                 // planting_anywhere
            {0x004453b0, {0xeb}, {0x74}},                                 // planting_anywhere_preview
            {0x004361e9, {0x8d}, {0x84}},                                 // planting_anywhere_iz
            {{0x0042f1ff, {0x80}, {0x8f}}, {0x004a030e, {0x33}, {0x85}}}, // fast_belt
            {0x0041efee, {0x39}, {0x89}},                                 // lock_shovel

            {0x00418381, {0x800f}, {0x840f}},             // hack_put_rake
            {0x00418628, {0x60eb}, {0x0975}},             // restore_lawn_mower_1
            {0x004186a4 + 3, {0x01}, {0x00}},             // restore_lawn_mower_2
            {0x00466d60 + 2, {0x00728aac}, {0x00728c90}}, // restore_lawn_mower_3

            {0x0054c67b, {0x46, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // plant_immune_bite
            {0x0042949f, {0xeb}, {0x74}},                         // plant_immune_blast
            {0x00543d7a, {0xeb}, {0x75}},                         // plant_immune_burn
            {0x0047d0db, {0x90, 0x90, 0x90}, {0x29, 0x50, 0x40}}, // plant_immune_pea
            {0x0047d899, {0x90, 0x90, 0x90}, {0x29, 0x4e, 0x40}}, // plant_immune_ball
            {0x0054b2bb, {0xeb}, {0x74}},                         // plant_immune_squish
            {0x0046df8a, {0x70}, {0x75}},                         // plant_immune_spikeweed
            {0x0046dde6, {0x00}, {0xce}},                         // plant_immune_spikerock
            {0x00471dd0, {0xc2, 0x04, 0x00}, {0x53, 0x55, 0x8b}}, // plant_immune_zomboss

            {0x0054c67b, {0x66, 0x40, 0x00}, {0x46, 0x40, 0xfc}}, // _plant_immune_bite
            {0x0047d0db, {0x29, 0x40, 0x40}, {0x29, 0x50, 0x40}}, // _plant_immune_pea
            {0x0047d899, {0x29, 0x76, 0x40}, {0x29, 0x4e, 0x40}}, // _plant_immune_ball
            {0x0046df8a, {0xeb}, {0x75}},                         // _plant_immune_spikeweed

            {0x0054dcca, {0x90909090}, {0x20246c2b}}, // zombie_immune_damage
            {0x0054d9e5, {0xc0}, {0xc8}},             // zombie_immune_type1
            {0x0054d63b, {0xd233c033}, {0xc28b027c}}, // zombie_immune_type2
            {0x0054f561, {0x81}, {0x8d}},             // zombie_immune_ashes
            {0x0042a183, {0xeb}, {0x7f}},             // zombie_immune_cherry
            {0x004757b2, {0xeb}, {0x75}},             // zombie_immune_jalapeno
            {0x00470658, {0xeb}, {0x74}},             // zombie_immune_chomper
            {0x0054c40f, {0x00}, {0x01}},             // zombie_immune_hypno
            {0x004758c1, {0x90, 0x90}, {0x74, 0x05}}, // zombie_immune_blover
            {0x0047d543, {0xeb}, {0x74}},             // zombie_immune_nearby
            {0x00467585, {0xeb}, {0x74}},             // zombie_immune_lawnmower

            {0x0054dcca, {0x9090ed2b}, {0x20246c2b}}, // _zombie_immune_damage
            {0x0054d9e5, {0xc9}, {0xc8}},             // _zombie_immune_type1
            {0x0054d63b, {0xc28bd08b}, {0xc28b027c}}, // _zombie_immune_type2
            {0x0054f561, {0x80}, {0x8d}},             // _zombie_immune_ashes

            {0x0047025b, {0x80}, {0x85}},                                 // reload_instantly
            {0x0046d012, {0xeb}, {0x74}},                                 // mushrooms_awake
            {0x0043252c, {0xeb}, {0x74}},                                 // stop_spawning
            {{0x00547433, {0x54}, {0x64}}, {0x0054743c, {0x54}, {0x44}}}, // stop_zombies
            {0x0046e392, {0x70}, {0x75}},                                 // lock_butter
            {0x0042a02d, {0x70}, {0x75}},                                 // no_crater
            {{0x005470b0, {0xc3}, {0x51}}, {0x0042bd29, {0xeb}, {0x75}}}, // no_ice_trail
            {{0x0054318c, {0x81}, {0x8f}}, {0x00543c6d, {0x81}, {0x85}}}, // zombie_not_explode

            {0x00446953, {0x80}, {0x85}}, // hack_spawn_preview

            {0x00426dbd, {0xd231}, {0xf23b}},                     // no_fog
            {0x0045aa7a, {0x0033b866}, {0x047ec085}},             // see_vase
            {0x006226e9, {0x00eb}, {0x4074}},                     // background_running
            {0x0061df13, {0x70}, {0x74}},                         // disable_delete_userdata
            {0x00498b63, {0x00184b09 + 0x28}, {0x00184b09}},      // disable_save_userdata
            {0x00439fca, {0x38, 0x59, 0x54}, {0x88, 0x59, 0x54}}, // unlock_limbo_page

            0x0045d540, // call_update_main_ui
            0x0045d300, // call_reload_main_ui

            0x00418d90, // call_level_complete

            0x00439240, // call_wisdom_tree

            0x004199c0, // call_put_plant
            0x00475ea0, // call_put_plant_imitater
            0x00436440, // call_put_plant_iz_style
            0x00436000, // call_put_zombie
            0x0041a6b0, // call_put_zomboss
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

            0x0046d9e0, // call_wakeup_plant

            0x00416ae0, // call_set_background
            0x0052c250, // call_delete_particle_system

            0x00415d10, // call_generate_spawn_list
            0x0041a8a0, // call_clear_spawn_preview
            0x00446940, // call_update_spawn_preview

            0x0046a810, // call_set_music
        };

    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_NOT_FOUND, data_1_0_0_1051_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_OPEN_ERROR, data_1_0_0_1051_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_UNSUPPORTED, data_1_0_0_1051_en));

    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_0_0_1051_EN, data_1_0_0_1051_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_2_0_1065_EN, data_1_2_0_1065_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_0_4_7924_ES, data_1_0_4_7924_es));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_0_7_3556_ES, data_1_0_7_3556_es));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_2_0_1073_EN, data_1_2_0_1073_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_2_0_1096_EN, data_1_2_0_1096_en));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_2_0_1093_DE_ES_FR_IT, data_1_2_0_1093_de_es_fr_it));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_1_0_1056_ZH, data_1_1_0_1056_zh));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_1_0_1056_JA, data_1_1_0_1056_ja));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_1_0_1056_ZH_2012_06, data_1_1_0_1056_zh_2012_06));
    this->ver_map.insert(std::pair<int, PVZ_DATA>(PVZ_1_1_0_1056_ZH_2012_07, data_1_1_0_1056_zh_2012_07));

    // FindPvZ();
}

PvZ::~PvZ()
{
}

void PvZ::asm_code_inject()
{
    // 其他地方预先判断了, 这里其实不用
    // if (GameOn())
    // {
    enable_hack(data().safe_thread, true);
    Sleep(GetFrameDuration() * 2);
    Code::asm_code_inject(this->handle);
    enable_hack(data().safe_thread, false);
    // }
}

bool PvZ::FindPvZ()
{
    this->find_result = PVZ_NOT_FOUND;

    std::vector<std::wstring> pvz_titles = {
        L"Plants vs. Zombies",                    //
        L"Plants vs. Zombies 1.2.0.1073",         //
        L"Plants vs. Zombies 1.2.0.1073 RELEASE", //
        L"Plants vs. Zombies GOTY",               //
        L"Pflanzen gegen Zombies 1.2.0.1093",     //
        L"Plantas contra Zombis 1.2.0.1093",      //
        L"Plantes contre Zombies 1.2.0.1093",     //
        L"Piante contro zombi 1.2.0.1093",        //
        L"植物大战僵尸中文版",                    //
        L"植物大战僵尸汉化版",                    //
    };                                            //

    for (size_t i = 0; i <= pvz_titles.size(); i++)
    {
        bool found = false;

        // 优先查找已知标题, 兼顾各种瞎动标题的改版
        if (i != pvz_titles.size())
            found = OpenByWindow(L"MainWindow", pvz_titles[i].c_str());
        else
            found = OpenByWindow(L"MainWindow", nullptr);

        // 注意分支完整
        if (found)
        {
            if (IsValid()) // 没权限拿不到进程句柄
            {
                if (this->name != L"Plants vs. Zombies" || this->of_name != L"PlantsVsZombies.exe")
                {
                    this->find_result = PVZ_NOT_FOUND;
                }
                else
                {
                    if (this->version == L"1.0.0.1051" //
                        && ReadMemory<unsigned int>({0x004140c5}) == 0x0019b337)
                        this->find_result = PVZ_1_0_0_1051_EN;

                    else if (this->version == L"1.2.0.1065" //
                             && ReadMemory<unsigned int>({0x004140d5}) == 0x0019b827)
                        this->find_result = PVZ_1_2_0_1065_EN;

                    else if (this->version == L"1.0.4.7924" //
                             && ReadMemory<unsigned int>({0x00415635}) == 0x001a0177)
                        this->find_result = PVZ_1_0_4_7924_ES;

                    else if (this->version == L"1.0.7.3556" //
                             && ReadMemory<unsigned int>({0x00415605}) == 0x001a0297)
                        this->find_result = PVZ_1_0_7_3556_ES;

                    else if (this->version == L"1.2.0.1073" //
                             && ReadMemory<unsigned int>({0x00416a20}) == 0x001e887c)
                        this->find_result = PVZ_1_2_0_1073_EN;

                    else if ((this->version == L"1.2.0.1095" || this->version == L"1.2.0.1096") //
                             && ReadMemory<unsigned int>({0x004175b0}) == 0x001edd3c)
                        this->find_result = PVZ_1_2_0_1096_EN;

                    else if (this->version == L"1.2.0.1093" //
                             && ReadMemory<unsigned int>({0x00417d80}) == 0x001efd9c)
                        this->find_result = PVZ_1_2_0_1093_DE_ES_FR_IT;

                    else if ((this->version == L"1.2.0.1073" || this->version == L"GOTY") //
                             && ReadMemory<unsigned int>({0x00429c79}) == 0x0016a043)
                        this->find_result = PVZ_1_1_0_1056_ZH;

                    else if (this->version == L"1.2.0.1073" //
                             && ReadMemory<unsigned int>({0x00419b5c}) == 0x0016ab60)
                        this->find_result = PVZ_1_1_0_1056_JA;

                    else if (this->version == L"1.2.0.1073" //
                             && ReadMemory<unsigned int>({0x004201a5}) == 0x001ceb17)
                        this->find_result = PVZ_1_1_0_1056_ZH_2012_06;

                    else if (this->version == L"1.2.0.1073" //
                             && ReadMemory<unsigned int>({0x00420df5}) == 0x001ce9f7)
                        this->find_result = PVZ_1_1_0_1056_ZH_2012_07;

                    else
                        this->find_result = PVZ_UNSUPPORTED;
                }
            }
            else
            {
                this->find_result = PVZ_OPEN_ERROR;
            }
        }
        else
        {
            this->find_result = PVZ_NOT_FOUND;
        }

        // 没有找到窗口/打开进程失败就继续找
        if (this->find_result == PVZ_NOT_FOUND || this->find_result == PVZ_OPEN_ERROR)
            continue;
        // 找到了支持/不支持的版本则终止循环
        else
            break;
    }

    bool supported = this->find_result != PVZ_NOT_FOUND     //
                     && this->find_result != PVZ_OPEN_ERROR //
                     && this->find_result != PVZ_UNSUPPORTED;

    if (!supported)
    {
        if (IsValid())
            CloseHandle(this->handle);
        this->hwnd = nullptr;
        this->pid = 0;
        this->handle = nullptr;
        this->path = L"";
        this->name = L"";
        this->version = L"";
        this->of_name = L"";
    }

    if (cb_find_result != nullptr && this->window != nullptr)
        cb_find_result(this->window, this->find_result);

    return supported;
}

void PvZ::callback(cb_func func, void *win)
{
    this->cb_find_result = func;
    this->window = win;
}

PVZ_DATA PvZ::data()
{
    return this->ver_map[this->find_result];
}

bool PvZ::GameOn()
{
    bool on = this->find_result != PVZ_NOT_FOUND      //
              && this->find_result != PVZ_OPEN_ERROR  //
              && this->find_result != PVZ_UNSUPPORTED //
              && IsValid();

    if (on)
    {
#ifdef _DEBUG
        std::wcout << L"游戏已经打开, 可以修改." << std::endl;
#endif
    }
    else
    {
        on = FindPvZ();
#ifdef _DEBUG
        std::wcout << L"游戏没有正常打开, 重新查找: " << (on ? L"找到了" : L"没找到") << std::endl;
#endif
    }

    return on;
}

bool PvZ::isGOTY()
{
    return (this->find_result == PVZ_1_2_0_1073_EN              //
            || this->find_result == PVZ_1_2_0_1096_EN           //
            || this->find_result == PVZ_1_2_0_1093_DE_ES_FR_IT  //
            || this->find_result == PVZ_1_1_0_1056_ZH           //
            || this->find_result == PVZ_1_1_0_1056_JA           //
            || this->find_result == PVZ_1_1_0_1056_ZH_2012_06   //
            || this->find_result == PVZ_1_1_0_1056_ZH_2012_07); //
}

int PvZ::GameMode()
{
    return ReadMemory<int>({data().pvz_base, data().game_mode});
}

int PvZ::GameUI()
{
    return ReadMemory<int>({data().pvz_base, data().game_ui});
}

int PvZ::GetScene()
{
    int scene = -1;

    int ui = GameUI();
    if (ui == 2 || ui == 3)
        scene = ReadMemory<int>({data().pvz_base, data().main_object, data().scene});

    return scene;
}

void PvZ::SetScene(int scene)
{
    if (scene < 0 || scene > 5)
        return;

    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    asm_init();
    asm_mov_exx_dword_ptr(Reg::ESI, data().pvz_base);
    asm_mov_exx_dword_ptr_exx_add(Reg::ESI, data().main_object);
    asm_add_list({0xc7, 0x86});  // mov [esi+0000554C],scene
    asm_add_dword(data().scene); //
    asm_add_dword(scene);        //
    asm_call(data().call_set_background);
    asm_ret();
    asm_code_inject();

    // 1.lawn 2.bare 3.pool
    // 0.none 1.land 2.water
    switch (scene)
    {
    case 0:
    case 1:
    case 4:
    case 5:
        WriteMemory<int, 6 * 9>({1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 2,
                                 1, 1, 1, 1, 1, 2},
                                {data().pvz_base, data().main_object, data().block_type});
        WriteMemory<int, 6>({1, 1, 1, 1, 1, 0},
                            {data().pvz_base, data().main_object, data().row_type});
        break;
    case 2:
    case 3:
    default:
        WriteMemory<int, 6 * 9>({1, 1, 3, 3, 1, 1,
                                 1, 1, 3, 3, 1, 1,
                                 1, 1, 3, 3, 1, 1,
                                 1, 1, 3, 3, 1, 1,
                                 1, 1, 3, 3, 1, 1,
                                 1, 1, 3, 3, 1, 1,
                                 1, 1, 3, 3, 1, 1,
                                 1, 1, 3, 3, 1, 1,
                                 1, 1, 3, 3, 1, 1},
                                {data().pvz_base, data().main_object, data().block_type});
        WriteMemory<int, 6>({1, 1, 2, 2, 1, 1},
                            {data().pvz_base, data().main_object, data().row_type});
        break;
    }

    // 泳池和雾夜仍然保留水波光
    if (scene == 2 || scene == 3)
        return;

    unsigned int particle_system_struct_size = 0x2c;

    asm_init();
    auto particle_system_offset = ReadMemory<uintptr_t>({data().pvz_base, data().anim, data().unnamed, data().particle_system});
    auto particle_system_count_max = ReadMemory<uintptr_t>({data().pvz_base, data().anim, data().unnamed, data().particle_system_count_max});
    for (size_t i = 0; i < particle_system_count_max; i++)
    {
        auto particle_system_type = ReadMemory<int>({particle_system_offset + data().particle_system_type + particle_system_struct_size * i});
        auto particle_system_dead = ReadMemory<bool>({particle_system_offset + data().particle_system_dead + particle_system_struct_size * i});
        if (!particle_system_dead && particle_system_type == 34)
        {
            uintptr_t addr = particle_system_offset + particle_system_struct_size * i;
            asm_push(addr);
            asm_call(data().call_delete_particle_system);
        }
    }
    asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
    asm_add_list({0xc7, 0x80});                  // mov [eax+00005620],00000000
    asm_add_dword(data().particle_systems_addr); //
    asm_add_dword(0);                            //
    asm_ret();
    asm_code_inject();
}

int PvZ::GetRowCount()
{
    int scene = GetScene();
    return (scene == 2 || scene == 3) ? 6 : 5;
}

// 以下是修改功能

void PvZ::UnlockTrophy()
{
    if (!GameOn())
        return;

    auto userdata = ReadMemory<uintptr_t>({data().pvz_base, data().user_data});
    if (userdata == 0) // 还没建立用户
        return;

    auto playthrough = userdata + data().playthrough;

    // Adventure
    int adventure_playthrough = ReadMemory<int>({playthrough});
    if (adventure_playthrough < 2)
        WriteMemory<int>(2, {playthrough});
    playthrough += 1 * sizeof(int);

    // Survival
    // Survival Hard
    WriteMemory<int, 5 + 5>({5, 5, 5, 5, 5, 10, 10, 10, 10, 10}, {playthrough});
    playthrough += (5 + 5) * sizeof(int);

    // Survival Endless
    playthrough += 5 * sizeof(int);

    // Mini-games
    WriteMemory<int, 20>({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {playthrough});
    playthrough += 20 * sizeof(int);

    // Hidden Mini-games
    // Squirrel
    // Wisdom Tree (Height)
    playthrough += (13 + 1 + 1) * sizeof(int);

    // Vasebreaker
    WriteMemory<int, 9>({1, 1, 1, 1, 1, 1, 1, 1, 1}, {playthrough});
    playthrough += 9 * sizeof(int);

    // Vasebreaker Endless
    playthrough += 1 * sizeof(int);

    // I, Zombie
    WriteMemory<int, 9>({1, 1, 1, 1, 1, 1, 1, 1, 1}, {playthrough});
    playthrough += 9 * sizeof(int);

    // I, Zombie Endless
    playthrough += 1 * sizeof(int);

    // Upsell
    // Intro
    playthrough += (1 + 1) * sizeof(int);

    auto twiddydinky = userdata + data().twiddydinky;
    assert(twiddydinky == playthrough + 28 * 4);

    // Gatling Pea
    // Twin Sunflower
    // Gloom-shroom
    // Cattail
    // Winter Melon
    // Gold Magnet
    // Spikerock
    // Cob Cannon
    WriteMemory<int, 8>({1, 1, 1, 1, 1, 1, 1, 1}, {twiddydinky});
    twiddydinky += 8 * sizeof(int);

    // Imitater
    WriteMemory<int>(1, {twiddydinky});
    twiddydinky += 1 * sizeof(int);

    // unknown
    // Marigold Sprout x3
    // Golden Watering Can
    // Fertilizer
    // Bug Spray
    // Phonograph
    // Gardening Glove
    // Mushroom Garden
    // Wheel Barrow
    // Snail
    twiddydinky += (1 + 3 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1) * sizeof(int);

    // 6+4 seed slots
    WriteMemory<int>(4, {twiddydinky});
    twiddydinky += 1 * sizeof(int);

    // Pool Cleaner
    WriteMemory<int>(1, {twiddydinky});
    twiddydinky += 1 * sizeof(int);

    // Roof Cleaner
    WriteMemory<int>(1, {twiddydinky});
    twiddydinky += 1 * sizeof(int);

    // Garden Rake
    // Aquarium Garden
    // Chocolate
    twiddydinky += (1 + 1 + 1) * sizeof(int);

    // Tree of Wisdom
    WriteMemory<int>(1, {twiddydinky});
    twiddydinky += 1 * sizeof(int);

    // Tree Food
    twiddydinky += 1 * sizeof(int);

    // Wall-nut First Aid
    WriteMemory<int>(1, {twiddydinky});
    twiddydinky += 1 * sizeof(int);

    // 刷新主界面
    if (adventure_playthrough == 0 && GameUI() == 1)
    {
        // // TODO
        // if (isGOTY())
        // {
        //     int frame_time = GetFrameDuration();
        //     SetFrameDuration(1);
        //     for (size_t i = 0; i < 150; i++)
        //     {
        //         PostMessage(this->hwnd, WM_KEYDOWN, VK_UP, 0);
        //         PostMessage(this->hwnd, WM_KEYUP, VK_UP, 0);
        //         Sleep(3);
        //     }
        //     SetFrameDuration(frame_time);
        // }
        asm_init();
        asm_mov_exx_dword_ptr(Reg::ESI, data().pvz_base);
        asm_call(data().call_update_main_ui);
        asm_mov_exx_dword_ptr(Reg::ECX, data().pvz_base);
        asm_call(data().call_reload_main_ui);
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::DirectWin()
{
    if (!GameOn())
        return;
    if (GameUI() != 3)
        return;

    int frame_time = GetFrameDuration();

    int mode = GameMode();
    bool light_cob = 11 <= mode && mode <= 15;

    if (light_cob)
    {
        int game_clock = ReadMemory<int>({data().pvz_base, data().main_object, data().game_clock});
        int frame_to_wait = 75 - ((game_clock + 500) % 75);
        if (ReadMemory<bool>({data().pvz_base, data().main_object, data().game_paused}))
        {
            if (frame_to_wait != 0)
            {
                // 解除暂停
                PostMessage(hwnd, WM_KEYDOWN, VK_SPACE, 0);
                PostMessage(hwnd, WM_KEYUP, VK_SPACE, 0);
                Sleep(frame_to_wait * frame_time);
                // 暂停
                PostMessage(hwnd, WM_KEYDOWN, VK_SPACE, 0);
                PostMessage(hwnd, WM_KEYUP, VK_SPACE, 0);
            }
        }
        else
        {
            Sleep(frame_to_wait * frame_time);
            // 暂停
            PostMessage(hwnd, WM_KEYDOWN, VK_SPACE, 0);
            PostMessage(hwnd, WM_KEYUP, VK_SPACE, 0);
        }
        Sleep(frame_time);
    }

    if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
    {
        asm_init();
        asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
        asm_push_exx(Reg::EAX);
        asm_call(data().call_level_complete);
        asm_ret();
        asm_code_inject();
    }
    else
    {
        asm_init();
        asm_mov_exx_dword_ptr(Reg::ECX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().main_object);
        asm_call(data().call_level_complete);
        asm_ret();
        asm_code_inject();
    }

    if (light_cob)
    {
        Sleep(frame_time);
        // 解除暂停
        PostMessage(hwnd, WM_KEYDOWN, VK_SPACE, 0);
        PostMessage(hwnd, WM_KEYUP, VK_SPACE, 0);
    }

    // #ifdef _DEBUG
    //     Sleep(frame_time * (500 + 10));
    //     std::cout << ReadMemory<int>({data().pvz_base, data().main_object, data().game_clock}) % 75 << std::endl;
    // #endif

    // unsigned int slot_seed_struct_size = 0x50;
    // std::vector<int> seed_types = {40, 41, 42, 43, 44, 45, 46, 47, 8, 48};
    // std::vector<int> seed_types_im = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 8};
    // auto slots_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().slot});
    // for (size_t i = 0; i < 10; i++)
    // {
    //     WriteMemory<int>(seed_types[i], {slots_offset + data().slot_seed_type + i * slot_seed_struct_size});
    //     WriteMemory<int>(seed_types_im[i], {slots_offset + data().slot_seed_type_im + i * slot_seed_struct_size});
    // }
}

void PvZ::SetSun(int sun)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    WriteMemory<int>(sun, {data().pvz_base, data().main_object, data().sun});
}

void PvZ::SetMoney(int money)
{
    if (!GameOn())
        return;

    if (ReadMemory<uintptr_t>({data().pvz_base, data().user_data}) != 0)
        WriteMemory<int>(money, {data().pvz_base, data().user_data, data().money});
}

void PvZ::AutoCollect(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().auto_collect, on);
}

void PvZ::ZombieNoFalling(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().zombie_no_falling, on);
}

void PvZ::FertilizerUnlimited(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().fertilizer_unlimited, on);
    if (on && ReadMemory<uintptr_t>({data().pvz_base, data().user_data}) != 0)
        WriteMemory<int>(1000 + 20, {data().pvz_base, data().user_data, data().twiddydinky + 14 * 4});
}

void PvZ::BugSprayUnlimited(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().bug_spray_unlimited, on);
    if (on && ReadMemory<uintptr_t>({data().pvz_base, data().user_data}) != 0)
        WriteMemory<int>(1000 + 20, {data().pvz_base, data().user_data, data().twiddydinky + 15 * 4});
}

void PvZ::ChocolateUnlimited(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().chocolate_unlimited, on);
    if (on && ReadMemory<uintptr_t>({data().pvz_base, data().user_data}) != 0)
        WriteMemory<int>(1000 + 20, {data().pvz_base, data().user_data, data().twiddydinky + 26 * 4});
}

void PvZ::TreeFoodUnlimited(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().tree_food_unlimited, on);
    if (on && ReadMemory<uintptr_t>({data().pvz_base, data().user_data}) != 0)
        WriteMemory<int>(1000 + 20, {data().pvz_base, data().user_data, data().twiddydinky + 28 * 4});
}

void PvZ::SetTreeHeight(int height)
{
    if (!GameOn())
        return;

    if (GameMode() == 50) // Zen Garden
    {
        WriteMemory<int>(height - 1, {data().pvz_base, data().user_data, data().tree_height});

        if (isGOTY())
        {
            if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
            {
                asm_init();
                asm_mov_exx_dword_ptr(Reg::EBX, data().pvz_base);
                asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().main_object);
                asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().indirect_base);
                asm_push_exx(Reg::EBX);
                asm_call(data().call_wisdom_tree);
                asm_ret();
                asm_code_inject();
            }
            else if (this->find_result == PVZ_1_1_0_1056_ZH_2012_06 || this->find_result == PVZ_1_1_0_1056_ZH_2012_07)
            {
                asm_init();
                asm_mov_exx_dword_ptr(Reg::EDI, data().pvz_base);
                asm_mov_exx_dword_ptr_exx_add(Reg::EDI, data().main_object);
                asm_mov_exx_dword_ptr_exx_add(Reg::EDI, data().indirect_base);
                asm_call(data().call_wisdom_tree);
                asm_ret();
                asm_code_inject();
            }
            else
            {
                asm_init();
                asm_mov_exx_dword_ptr(Reg::ESI, data().pvz_base);
                asm_mov_exx_dword_ptr_exx_add(Reg::ESI, data().main_object);
                asm_mov_exx_dword_ptr_exx_add(Reg::ESI, data().indirect_base);
                asm_call(data().call_wisdom_tree);
                asm_ret();
                asm_code_inject();
            }
        }
        else
        {
            asm_init();
            asm_mov_exx(Reg::EDI, data().pvz_base);
            asm_call(data().call_wisdom_tree);
            asm_ret();
            asm_code_inject();
        }
    }
    else
    {
        if (ReadMemory<uintptr_t>({data().pvz_base, data().user_data}) != 0)
            WriteMemory<int>(height, {data().pvz_base, data().user_data, data().tree_height});
    }
}

void PvZ::FreePlanting(bool on)
{
    if (!GameOn())
        return;

    WriteMemory<int>(static_cast<int>(on), {data().pvz_base, data().free_planting});

    if (GameUI() != 3)
        return;

    unsigned int slot_seed_struct_size = 0x50;

    auto slot_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().slot});
    auto slot_count = ReadMemory<uint32_t>({slot_offset + data().slot_count});
    for (size_t i = 0; i < slot_count; i++)
    {
        int slot_seed_cd_total = ReadMemory<int>({slot_offset + data().slot_seed_cd_total + slot_seed_struct_size * i});
        WriteMemory<int>(slot_seed_cd_total, {slot_offset + data().slot_seed_cd_past + slot_seed_struct_size * i});
    }
}

void PvZ::PlantingAnywhere(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().planting_anywhere, on);
    enable_hack(data().planting_anywhere_preview, on);
    enable_hack(data().planting_anywhere_iz, on);
}

void PvZ::FastBelt(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().fast_belt, on);
}

void PvZ::LockShovel(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().lock_shovel, on);

    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    auto cursor_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().cursor});
    if (on)
    {
        WriteMemory<int>(6, {cursor_offset + data().cursor_grab});
    }
    else
    {
        if (ReadMemory<int>({cursor_offset + data().cursor_grab}) == 6)
            WriteMemory<int>(0, {cursor_offset + data().cursor_grab});
    }
}

void PvZ::MixMode(int mode, int level)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    if (mode == 0) // 冒险模式
    {
        WriteMemory<int>(level, {data().pvz_base, data().user_data, data().level});
        WriteMemory<int>(level, {data().pvz_base, data().main_object, data().adventure_level});
    }
    WriteMemory<int>(mode, {data().pvz_base, data().game_mode});
}

void PvZ::JumpLevel(int level)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    int mode = GameMode();
    if (mode == 60 || mode == 70 || (mode >= 11 && mode <= 15)) // 仅限无尽模式
    {
        auto indirect_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().indirect_base});
        WriteMemory<int>(level, {indirect_offset + data().endless_rounds});
    }
}

void PvZ::asm_put_plant(int row, int col, int type, bool imitater, bool iz_style)
{
    if (imitater)
    {
        asm_push(type);
        asm_push(48);
    }
    else
    {
        asm_push(-1);
        asm_push(type);
    }
    asm_mov_exx(Reg::EAX, row);
    asm_push(col);
    asm_mov_exx_dword_ptr(Reg::EBP, data().pvz_base);
    asm_mov_exx_dword_ptr_exx_add(Reg::EBP, data().main_object);
    asm_push_exx(Reg::EBP);
    asm_call(data().call_put_plant);

    // 多余的过程是为了让 eax 值为目标植物的地址以供后续的布阵函数使用

    if (imitater)
    {
        asm_mov_exx_dword_ptr(Reg::ECX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().main_object);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().plant);
        asm_mov_exx_dword_ptr(Reg::EBX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().main_object);
        asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().plant_next_pos);
        asm_add_list(0x69, 0xdb, 0x4c, 0x01, 0x00, 0x00); // imul ebx,ebx,plant_struct_size
        asm_add_list(0x01, 0xd9);                         // add ecx,ebx
        asm_push_exx(Reg::ECX);
        asm_add_list(0x8b, 0xf0); // mov esi,eax
        asm_call(data().call_put_plant_imitater);
        asm_pop_exx(Reg::ECX);
        asm_add_list(0x8b, 0xc1); // mov eax,ecx
    }

    if (iz_style)
    {
        asm_add_list(0x8b, 0xf0); // mov esi,eax
        asm_push_exx(Reg::EAX);
        asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().indirect_base);
        asm_call(data().call_put_plant_iz_style);
        asm_add_list(0x8b, 0xc6); // mov eax,esi
    }
}

void PvZ::PutPlant(int row, int col, int type, bool imitater)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    int row_count = GetRowCount();        // 行数
    int col_count = (type == 47 ? 8 : 9); // 玉米加农炮不种在九列
    int width = (type == 47 ? 2 : 1);     // 玉米加农炮宽度两列
    int mode = GameMode();
    bool iz_style = (mode >= 61 && mode <= 70);
    asm_init();
    if (row == -1 && col == -1)
        for (int r = 0; r < row_count; r++)
            for (int c = 0; c < col_count; c += width)
                asm_put_plant(r, c, type, imitater, iz_style);
    else if (row != -1 && col == -1)
        for (int c = 0; c < col_count; c += width)
            asm_put_plant(row, c, type, imitater, iz_style);
    else if (row == -1 && col != -1)
        for (int r = 0; r < row_count; r++)
            asm_put_plant(r, col, type, imitater, iz_style);
    else
        asm_put_plant(row, col, type, imitater, iz_style);
    asm_ret();
    asm_code_inject();
}

void PvZ::asm_put_zombie(int row, int col, int type)
{
    if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
    {
        asm_push(type); // 0x6a byte(type)
        asm_mov_exx_dword_ptr(Reg::ECX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().main_object);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().indirect_base);
        asm_push_exx(Reg::ECX);
        asm_mov_exx(Reg::EAX, row);
        asm_mov_exx(Reg::ECX, col);
        asm_call(data().call_put_zombie);
    }
    else
    {
        asm_push(col);
        asm_push(type);
        asm_mov_exx(Reg::EAX, row);
        asm_mov_exx_dword_ptr(Reg::ECX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().main_object);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().indirect_base);
        asm_call(data().call_put_zombie);
    }
}

void PvZ::PutZombie(int row, int col, int type)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    if (type == 25) // 僵王
    {
        asm_init();
        asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
        asm_push(0);
        asm_push(25);
        asm_call(data().call_put_zomboss);
        asm_ret();
        asm_code_inject();
        return;
    }
    int row_count = GetRowCount();
    int col_count = 9;
    asm_init();
    if (row == -1 && col == -1)
        for (int r = 0; r < row_count; r++)
            for (int c = 0; c < col_count; c++)
                asm_put_zombie(r, c, type);
    else if (row != -1 && col == -1)
        for (int c = 0; c < col_count; c++)
            asm_put_zombie(row, c, type);
    else if (row == -1 && col != -1)
        for (int r = 0; r < row_count; r++)
            asm_put_zombie(r, col, type);
    else
        asm_put_zombie(row, col, type);
    asm_ret();
    asm_code_inject();
}

void PvZ::asm_put_grave(int row, int col)
{
    if (isGOTY())
    {
        asm_mov_exx_dword_ptr(Reg::ECX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().main_object);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().indirect_base);
        asm_push_exx(Reg::ECX);
        asm_mov_exx(Reg::EDI, row);
        asm_mov_exx(Reg::EBX, col);
        asm_call(data().call_put_grave);
    }
    else
    {
        asm_mov_exx_dword_ptr(Reg::EDX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDX, data().main_object);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDX, data().indirect_base);
        asm_push_exx(Reg::EDX);
        asm_mov_exx(Reg::EDI, row);
        asm_mov_exx(Reg::EBX, col);
        asm_call(data().call_put_grave);
    }
}

void PvZ::PutGrave(int row, int col)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    int row_count = GetRowCount();
    int col_count = 9;
    asm_init();
    if (row == -1 && col == -1)
        for (int r = 0; r < row_count; r++)
            for (int c = 0; c < col_count; c++)
                asm_put_grave(r, c);
    else if (row != -1 && col == -1)
        for (int c = 0; c < col_count; c++)
            asm_put_grave(row, c);
    else if (row == -1 && col != -1)
        for (int r = 0; r < row_count; r++)
            asm_put_grave(r, col);
    else
        asm_put_grave(row, col);
    asm_ret();
    asm_code_inject();
}

void PvZ::asm_put_ladder(int row, int col)
{
    asm_mov_exx(Reg::EDI, row);
    asm_push(col);
    asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
    asm_call(data().call_put_ladder);
}

void PvZ::PutLadder(int row, int col)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    int row_count = GetRowCount();
    int col_count = 9;
    asm_init();
    if (row == -1 && col == -1)
        for (int r = 0; r < row_count; r++)
            for (int c = 0; c < col_count; c++)
                asm_put_ladder(r, c);
    else if (row != -1 && col == -1)
        for (int c = 0; c < col_count; c++)
            asm_put_ladder(row, c);
    else if (row == -1 && col != -1)
        for (int r = 0; r < row_count; r++)
            asm_put_ladder(r, col);
    else
        asm_put_ladder(row, col);
    asm_ret();
    asm_code_inject();
}

void PvZ::AutoLadder(bool imitater_pumpkin_only = true)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int grid_item_struct_size = 0xec;
    unsigned int plant_struct_size = 0x14c;

    bool has_ladder[6][9] = {{false}}; // 已有梯子的位置

    ClearGridItems({3}); // 清空所有梯子

    // auto grid_item_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().grid_item_count_max});
    // auto grid_item_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().grid_item});
    // for (size_t i = 0; i < grid_item_count_max; i++)
    // {
    //     auto grid_item_dead = ReadMemory<bool>({grid_item_offset + data().grid_item_dead + grid_item_struct_size * i});
    //     auto grid_item_type = ReadMemory<int>({grid_item_offset + data().grid_item_type + grid_item_struct_size * i});
    //     if (!grid_item_dead && grid_item_type == 3) // 3 梯子
    //     {
    //         auto grid_item_row = ReadMemory<uint32_t>({grid_item_offset + data().grid_item_row + grid_item_struct_size * i});
    //         auto grid_item_col = ReadMemory<uint32_t>({grid_item_offset + data().grid_item_col + grid_item_struct_size * i});
    //         has_ladder[grid_item_row][grid_item_col] = true;
    //     }
    // }

#ifdef _DEBUG
    std::wcout << L"已有梯子情况: " << std::endl;
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
            std::cout << has_ladder[r][c] << " ";
        std::cout << std::endl;
    }
#endif

    auto plant_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().plant});

    asm_init();
    for (size_t i = 0; i < plant_count_max; i++)
    {
        auto plant_dead = ReadMemory<bool>({plant_offset + data().plant_dead + plant_struct_size * i});
        auto plant_squished = ReadMemory<bool>({plant_offset + data().plant_squished + plant_struct_size * i});
        auto plant_type = ReadMemory<uint32_t>({plant_offset + data().plant_type + plant_struct_size * i});
        if (!plant_dead && !plant_squished && plant_type == 30) // 30 南瓜
        {
            auto plant_row = ReadMemory<uint32_t>({plant_offset + data().plant_row + plant_struct_size * i});
            auto plant_col = ReadMemory<uint32_t>({plant_offset + data().plant_col + plant_struct_size * i});
            auto plant_imitater = //
                ReadMemory<int>({plant_offset + data().plant_imitater + plant_struct_size * i}) == 48;
            // 1.草地 2.裸地 3.泳池
            auto block_type = ReadMemory<int>({data().pvz_base, data().main_object,                       //
                                               data().block_type + 0x04 * plant_row + 0x18 * plant_col}); //
            if (plant_col != 0 && block_type == 1 && !has_ladder[plant_row][plant_col]                    //
                && (!imitater_pumpkin_only || (imitater_pumpkin_only && plant_imitater)))                 //
            {
#ifdef _DEBUG
                std::wcout << L"搭梯: " << (plant_row + 1) << L" " << (plant_col + 1) << std::endl;
#endif
                asm_put_ladder(plant_row, plant_col);
            }
        }
    }
    asm_ret();
    asm_code_inject();
}

void PvZ::asm_put_rake(int row, int col)
{
    WriteMemory<int>(row, {data().call_put_rake_row + 1});
    WriteMemory<int>(col, {data().call_put_rake_col + 4});

    asm_init();
    if (isGOTY())
    {
        if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
        {
            asm_mov_exx_dword_ptr(Reg::ECX, data().pvz_base);
            asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().main_object);
            asm_push_exx(Reg::ECX);
        }
        else
        {
            asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
            asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
        }
    }
    else
    {
        asm_mov_exx_dword_ptr(Reg::EDX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDX, data().main_object);
        asm_push_exx(Reg::EDX);
    }
    asm_call(data().call_put_rake);
    asm_ret();
    asm_code_inject();
}

void PvZ::PutRake(int row, int col)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    std::array<uint8_t, 8> reset_code_rake_col = {0};
    std::array<uint8_t, 7> reset_code_rake_row = {0};
    std::array<uint8_t, 6> reset_code_rake_row_goty = {0};

    reset_code_rake_col = ReadMemory<uint8_t, 8>({data().call_put_rake_col});
    if (!isGOTY())
        reset_code_rake_row = ReadMemory<uint8_t, 7>({data().call_put_rake_row});
    else
        reset_code_rake_row_goty = ReadMemory<uint8_t, 6>({data().call_put_rake_row});

    if (!isGOTY())
        WriteMemory<uint8_t, 7>({0xba, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90}, {data().call_put_rake_row});
    else
        WriteMemory<uint8_t, 6>({0xbf, 0x00, 0x00, 0x00, 0x00, 0x90}, {data().call_put_rake_row});

    enable_hack(data().hack_put_rake, true);

    int row_count = GetRowCount();
    int col_count = 9;
    if (row == -1 && col == -1)
        for (int r = 0; r < row_count; r++)
            for (int c = 0; c < col_count; c++)
                asm_put_rake(r, c);
    else if (row != -1 && col == -1)
        for (int c = 0; c < col_count; c++)
            asm_put_rake(row, c);
    else if (row == -1 && col != -1)
        for (int r = 0; r < row_count; r++)
            asm_put_rake(r, col);
    else
        asm_put_rake(row, col);

    enable_hack(data().hack_put_rake, false);

    WriteMemory<uint8_t, 8>(reset_code_rake_col, {data().call_put_rake_col});
    if (!isGOTY())
        WriteMemory<uint8_t, 7>(reset_code_rake_row, {data().call_put_rake_row});
    else
        WriteMemory<uint8_t, 6>(reset_code_rake_row_goty, {data().call_put_rake_row});
}

// 0.启动 1.删除 2.恢复
void PvZ::SetLawnMowers(int option)
{
    // #ifdef _DEBUG
    //     HACK<uint32_t, 1> test_hack = data().restore_lawn_mower_3;
    //     assert(ReadMemory<uint32_t>({test_hack.mem_addr}) == test_hack.reset_value[0]);
    //     assert(ReadMemory<float>({test_hack.hack_value[0]}) == -21.00f);
    //     assert(ReadMemory<float>({test_hack.reset_value[0]}) == -160.00f);
    // #endif

    if (option != 0 && option != 1 && option != 2)
        return;

    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int lawn_mower_struct_size = 0x48;

    auto lawn_mower_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().lawn_mower_count_max});
    auto lawn_mower_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().lawn_mower});

    if (option == 2)
    {
        enable_hack(data().restore_lawn_mower_1, true);
        enable_hack(data().restore_lawn_mower_2, true);
        enable_hack(data().restore_lawn_mower_3, true);
    }

    asm_init();
    for (size_t i = 0; i < lawn_mower_count_max; i++)
    {
        auto lawn_mower_dead = ReadMemory<bool>({lawn_mower_offset + data().lawn_mower_dead + lawn_mower_struct_size * i});
        if (!lawn_mower_dead)
        {
            uint32_t addr = lawn_mower_offset + lawn_mower_struct_size * i;
            if (option == 0)
            {
                if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
                    asm_mov_exx(Reg::EBX, addr);
                else
                    asm_mov_exx(Reg::ESI, addr);
                asm_call(data().call_start_lawn_mower);
            }
            else
            {
                asm_mov_exx(Reg::EAX, addr);
                asm_call(data().call_delete_lawn_mower);
            }
        }
    }
    if (option == 2)
    {
        asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
        asm_push_exx(Reg::EAX);
        asm_call(data().call_restore_lawn_mower);
    }
    asm_ret();
    asm_code_inject();

    if (option == 2)
    {
        enable_hack(data().restore_lawn_mower_1, false);
        enable_hack(data().restore_lawn_mower_2, false);
        enable_hack(data().restore_lawn_mower_3, false);
    }
}

void PvZ::ClearAllPlants()
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int plant_struct_size = 0x14c;

    auto plant_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().plant});

    asm_init();
    for (size_t i = 0; i < plant_count_max; i++)
    {
        auto plant_dead = ReadMemory<bool>({plant_offset + data().plant_dead + plant_struct_size * i});
        auto plant_squished = ReadMemory<bool>({plant_offset + data().plant_squished + plant_struct_size * i});
        if (!plant_dead && !plant_squished)
        {
            uint32_t addr = plant_offset + plant_struct_size * i;
            asm_push(addr);
            asm_call(data().call_delete_plant);
        }
    }
    asm_ret();
    asm_code_inject();
}

void PvZ::KillAllZombies()
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int zombie_struct_size = isGOTY() ? 0x168 : 0x15c;

    auto zombie_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().zombie_count_max});
    auto zombie_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().zombie});
    for (size_t i = 0; i < zombie_count_max; i++)
    {
        if (!ReadMemory<bool>({zombie_offset + data().zombie_dead + i * zombie_struct_size}))     // 没有消失
            WriteMemory<int>(3, {zombie_offset + data().zombie_status + i * zombie_struct_size}); // 3 秒杀
    }
}

// 1 墓碑
// 2 弹坑
// 3 梯子
// 4/5 传送门
// 7 罐子
// 10 蜗牛
// 11 钉耙
// 12 脑子
void PvZ::ClearGridItems(std::vector<int> types)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int grid_item_struct_size = 0xec;

    auto grid_item_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().grid_item_count_max});
    auto grid_item_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().grid_item});

    asm_init();
    for (size_t i = 0; i < grid_item_count_max; i++)
    {
        auto grid_item_dead = ReadMemory<bool>({grid_item_offset + data().grid_item_dead + grid_item_struct_size * i});
        auto grid_item_type = ReadMemory<int>({grid_item_offset + data().grid_item_type + grid_item_struct_size * i});
        if (!grid_item_dead && std::find(types.begin(), types.end(), grid_item_type) != types.end())
        {
            int addr = grid_item_offset + grid_item_struct_size * i;
            asm_mov_exx(Reg::ESI, addr);
            asm_call(data().call_delete_grid_item);
        }
    }
    asm_ret();
    asm_code_inject();
}

void PvZ::PlantInvincible(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().plant_immune_bite, on);
    enable_hack(data().plant_immune_blast, on);
    enable_hack(data().plant_immune_burn, on);
    enable_hack(data().plant_immune_pea, on);
    enable_hack(data().plant_immune_ball, on);
    enable_hack(data().plant_immune_squish, on);
    enable_hack(data().plant_immune_spikeweed, on);
    enable_hack(data().plant_immune_spikerock, on);
    enable_hack(data().plant_immune_zomboss, on);
}

void PvZ::PlantWeak(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data()._plant_immune_bite, on);
    enable_hack(data()._plant_immune_pea, on);
    enable_hack(data()._plant_immune_ball, on);
    enable_hack(data()._plant_immune_spikeweed, on);
}

void PvZ::ZombieInvincible(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().zombie_immune_damage, on);
    enable_hack(data().zombie_immune_type1, on);
    enable_hack(data().zombie_immune_type2, on);
    enable_hack(data().zombie_immune_ashes, on);
    enable_hack(data().zombie_immune_cherry, on);
    enable_hack(data().zombie_immune_jalapeno, on);
    enable_hack(data().zombie_immune_chomper, on);
    enable_hack(data().zombie_immune_hypno, on);
    enable_hack(data().zombie_immune_blover, on);
    enable_hack(data().zombie_immune_nearby, on);
    enable_hack(data().zombie_immune_lawnmower, on);
}

void PvZ::ZombieWeak(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data()._zombie_immune_damage, on);
    enable_hack(data()._zombie_immune_type1, on);
    enable_hack(data()._zombie_immune_type2, on);
    enable_hack(data()._zombie_immune_ashes, on);
}

void PvZ::ReloadInstantly(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().reload_instantly, on);
}

void PvZ::MushroomsAwake(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().mushrooms_awake, on);

    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int plant_struct_size = 0x14c;

    if (on)
    {
        auto plant_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().plant_count_max});
        auto plant_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().plant});
        asm_init();
        for (size_t i = 0; i < plant_count_max; i++)
        {
            auto plant_dead = ReadMemory<bool>({plant_offset + data().plant_dead + plant_struct_size * i});
            auto plant_squished = ReadMemory<bool>({plant_offset + data().plant_squished + plant_struct_size * i});
            auto plant_asleep = ReadMemory<bool>({plant_offset + data().plant_asleep + plant_struct_size * i});
            if (!plant_dead && !plant_squished && plant_asleep)
            {
                uint32_t addr = plant_offset + plant_struct_size * i;
                if (isGOTY())
                    asm_mov_exx(Reg::EDI, addr);
                else
                    asm_mov_exx(Reg::EAX, addr);
                asm_push(0);
                asm_call(data().call_wakeup_plant);
            }
        }
        asm_ret();
        asm_code_inject();
    }
}

void PvZ::StopSpawning(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().stop_spawning, on);
}

void PvZ::StopZombies(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().stop_zombies, on);
}

void PvZ::LockButter(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().lock_butter, on);
}

void PvZ::NoCrater(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().no_crater, on);
}

void PvZ::NoIceTrail(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().no_ice_trail, on);

    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    if (on)
    {
        for (size_t i = 0; i < 6; ++i)
            WriteMemory<int>(1, {data().pvz_base, data().main_object, data().ice_trail_cd + i * 4});
    }
}

void PvZ::ZombieNotExplode(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().zombie_not_explode, on);
}

int PvZ::GetSlotSeed(int index)
{
    int seed_type = 0;
    int seed_type_im = 0;

    if (!GameOn())
        return -1;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return -1;

    unsigned int slot_seed_struct_size = 0x50;

    auto slot_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().slot});
    seed_type = ReadMemory<int>({slot_offset + data().slot_seed_type + index * slot_seed_struct_size});
    seed_type_im = ReadMemory<int>({slot_offset + data().slot_seed_type_im + index * slot_seed_struct_size});

    if (seed_type == 48) // 模仿者
        return seed_type_im + 48;
    else
        return seed_type;
}

void PvZ::SetSlotSeed(int index, int type, bool imitater = false)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int slot_seed_struct_size = 0x50;

    auto slot_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().slot});
    if (imitater)
    {
        WriteMemory<int>(48, {slot_offset + data().slot_seed_type + index * slot_seed_struct_size});
        WriteMemory<int>(type, {slot_offset + data().slot_seed_type_im + index * slot_seed_struct_size});
    }
    else
    {
        WriteMemory<int>(type, {slot_offset + data().slot_seed_type + index * slot_seed_struct_size});
        WriteMemory<int>(-1, {slot_offset + data().slot_seed_type_im + index * slot_seed_struct_size});
    }
}

void PvZ::LilyPadOnPool(int from_col, int to_col)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    unsigned int plant_struct_size = 0x14c;

    auto plant_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().plant});
    bool has_plant[6][9] = {{false}};

    for (size_t i = 0; i < plant_count_max; i++)
    {
        auto plant_dead = ReadMemory<bool>({plant_offset + data().plant_dead + plant_struct_size * i});
        auto plant_squished = ReadMemory<bool>({plant_offset + data().plant_squished + plant_struct_size * i});
        auto plant_row = ReadMemory<uint32_t>({plant_offset + data().plant_row + plant_struct_size * i});
        auto plant_col = ReadMemory<uint32_t>({plant_offset + data().plant_col + plant_struct_size * i});
        if (!plant_dead && !plant_squished)
            has_plant[plant_row][plant_col] = true;
    }

    asm_init();
    int rows = GetRowCount();
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            // 1.草地 2.裸地 3.泳池
            auto block_type = ReadMemory<int>({data().pvz_base, data().main_object,       //
                                               data().block_type + 0x04 * r + 0x18 * c}); //
            if (block_type == 3 && !has_plant[r][c] && from_col - 1 <= c && c <= to_col - 1)
                asm_put_plant(r, c, 16, false, false); // 16 睡莲
        }
    }
    asm_ret();
    asm_code_inject();
}

void PvZ::FlowerPotOnRoof(int from_col, int to_col)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    int scene = GetScene();
    if (scene != 4 && scene != 5)
        return;

    unsigned int plant_struct_size = 0x14c;

    auto plant_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().plant});
    bool has_plant[5][9] = {{false}};

    for (size_t i = 0; i < plant_count_max; i++)
    {
        auto plant_dead = ReadMemory<bool>({plant_offset + data().plant_dead + plant_struct_size * i});
        auto plant_squished = ReadMemory<bool>({plant_offset + data().plant_squished + plant_struct_size * i});
        auto plant_row = ReadMemory<uint32_t>({plant_offset + data().plant_row + plant_struct_size * i});
        auto plant_col = ReadMemory<uint32_t>({plant_offset + data().plant_col + plant_struct_size * i});
        if (!plant_dead && !plant_squished)
            has_plant[plant_row][plant_col] = true;
    }

    asm_init();
    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 9; c++)
            if (!has_plant[r][c] && from_col - 1 <= c && c <= to_col - 1)
                asm_put_plant(r, c, 33, false, false); // 33 花盆
    asm_ret();
    asm_code_inject();
}

void PvZ::Screenshot()
{
    if (!GameOn())
        return;

    RECT rcClient = {0, 0, 800, 600};
    // if (GetClientRect(this->hwnd, &rcClient) == 0)
    //     return;
    int cx = rcClient.right - rcClient.left;
    int cy = rcClient.bottom - rcClient.top;
    // if (cx == 0 || cy == 0)
    //     return;

    HDC hdcWindow = nullptr;
    HDC hdcMemDC = nullptr;
    HBITMAP hbmScreen = nullptr;

    hdcWindow = GetDC(this->hwnd);
    if (!hdcWindow)
        goto done;
    hdcMemDC = CreateCompatibleDC(hdcWindow);
    if (!hdcMemDC)
        goto done;
    hbmScreen = CreateCompatibleBitmap(hdcWindow, cx, cy);
    if (!hbmScreen)
        goto done;

    SelectObject(hdcMemDC, hbmScreen);
    if (BitBlt(hdcMemDC, 0, 0, cx, cy, hdcWindow, 0, 0, SRCCOPY) == 0)
        goto done;

    // 保存到剪贴板
    if (OpenClipboard(nullptr) != 0)
    {
        EmptyClipboard();
        SetClipboardData(CF_BITMAP, hbmScreen);
        CloseClipboard();
    }

done:
    DeleteObject(hbmScreen);
    DeleteObject(hdcMemDC);
    ReleaseDC(this->hwnd, hdcWindow);
}

std::string PvZ::GetLineup()
{
    uint16_t items[6 * 9] = {0};
    uint8_t rake_row = 0, scene = 2;

    if (!GameOn())
        goto encode;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        goto encode;

    scene = GetScene();

    uint16_t plant[6 * 9] = {0};
    uint16_t plant_im[6 * 9] = {0};
    uint16_t plant_awake[6 * 9] = {0};
    uint16_t base[6 * 9] = {0};
    uint16_t base_im[6 * 9] = {0};
    uint16_t pumpkin[6 * 9] = {0};
    uint16_t pumpkin_im[6 * 9] = {0};
    uint16_t coffee[6 * 9] = {0};
    uint16_t coffee_im[6 * 9] = {0};
    uint16_t ladder[6 * 9] = {0};

    unsigned int plant_struct_size = 0x14c;
    unsigned int grid_item_struct_size = 0xec;

    auto plant_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().plant});
    for (size_t i = 0; i < plant_count_max; i++)
    {
        auto plant_dead = ReadMemory<bool>({plant_offset + data().plant_dead + plant_struct_size * i});
        auto plant_squished = ReadMemory<bool>({plant_offset + data().plant_squished + plant_struct_size * i});
        auto plant_type = ReadMemory<uint32_t>({plant_offset + data().plant_type + plant_struct_size * i});
        if (!plant_dead && !plant_squished && 0 <= plant_type && plant_type <= 47)
        {
            auto plant_row = ReadMemory<uint32_t>({plant_offset + data().plant_row + plant_struct_size * i});
            auto plant_col = ReadMemory<uint32_t>({plant_offset + data().plant_col + plant_struct_size * i});
            auto plant_asleep = ReadMemory<bool>({plant_offset + data().plant_asleep + plant_struct_size * i});
            auto plant_imitater = ReadMemory<int>({plant_offset + data().plant_imitater + plant_struct_size * i}) == 48;
            if (plant_type == 16 || plant_type == 33) // 睡莲 花盆
            {
                base[plant_row * 9 + plant_col] = (plant_type == 16) ? 1 : 2;
                base_im[plant_row * 9 + plant_col] = plant_imitater ? 1 : 0;
            }
            else if (plant_type == 30) // 南瓜
            {
                pumpkin[plant_row * 9 + plant_col] = 1;
                pumpkin_im[plant_row * 9 + plant_col] = plant_imitater ? 1 : 0;
            }
            else if (plant_type == 35) // 咖啡
            {
                coffee[plant_row * 9 + plant_col] = 1;
                coffee_im[plant_row * 9 + plant_col] = plant_imitater ? 1 : 0;
            }
            else // 主要植物
            {
                plant[plant_row * 9 + plant_col] = plant_type + 1;
                plant_im[plant_row * 9 + plant_col] = plant_imitater ? 1 : 0;
                plant_awake[plant_row * 9 + plant_col] = plant_asleep ? 0 : 1;
            }
        }
    }

    auto grid_item_count_max = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().grid_item_count_max});
    auto grid_item_offset = ReadMemory<uintptr_t>({data().pvz_base, data().main_object, data().grid_item});
    for (size_t i = 0; i < grid_item_count_max; i++)
    {
        auto grid_item_dead = ReadMemory<bool>({grid_item_offset + data().grid_item_dead + grid_item_struct_size * i});
        auto grid_item_type = ReadMemory<int>({grid_item_offset + data().grid_item_type + grid_item_struct_size * i});
        if (!grid_item_dead && (grid_item_type == 1 || grid_item_type == 3 || grid_item_type == 11))
        {
            auto grid_item_row = ReadMemory<uint32_t>({grid_item_offset + data().grid_item_row + grid_item_struct_size * i});
            auto grid_item_col = ReadMemory<uint32_t>({grid_item_offset + data().grid_item_col + grid_item_struct_size * i});
            if (grid_item_type == 1) // 墓碑
            {
                base[grid_item_row * 9 + grid_item_col] = 3;
                base_im[grid_item_row * 9 + grid_item_col] = 0;
            }
            else if (grid_item_type == 3) // 梯子
            {
                ladder[grid_item_row * 9 + grid_item_col] = 1;
            }
            else // 钉耙
            {
                rake_row = grid_item_row + 1;
            }
        }
    }

    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            uint16_t item = 0;
            item += 0b1111110000000000 & (plant[r * 9 + c] << 10);
            item += 0b0000001000000000 & (plant_im[r * 9 + c] << 9);
            item += 0b0000000100000000 & (plant_awake[r * 9 + c] << 8);
            item += 0b0000000011000000 & (base[r * 9 + c] << 6);
            item += 0b0000000000100000 & (base_im[r * 9 + c] << 5);
            item += 0b0000000000010000 & (pumpkin[r * 9 + c] << 4);
            item += 0b0000000000001000 & (pumpkin_im[r * 9 + c] << 3);
            item += 0b0000000000000100 & (coffee[r * 9 + c] << 2);
            item += 0b0000000000000010 & (coffee_im[r * 9 + c] << 1);
            item += 0b0000000000000001 & (ladder[r * 9 + c] << 0);
            items[r * 9 + c] = item;
        }
    }

#ifdef _DEBUG
    std::cout << std::endl;
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 9; c++)
            std::cout << std::bitset<16>(items[r * 9 + c]) << " ";
        std::cout << std::endl;
    }
    std::cout << std::bitset<8>((rake_row << 4) | (scene & 0b00001111));
    std::cout << std::endl;
#endif

encode:

    unsigned long size = 121; // compressBound(6*9*2)
    unsigned char lineup_bin[128] = {0};
    unsigned long cut_size = ((scene == 2 || scene == 3) ? 6 : 5) * 9 * sizeof(uint16_t);
    compress2(lineup_bin, &size, (unsigned char *)items, cut_size, Z_BEST_COMPRESSION);
    lineup_bin[size - 1 + 1] = (rake_row << 4) | (scene & 0b00001111);

    for (size_t i = 0; i < size + 1; i++)
        lineup_bin[i] = lineup_bin[i] ^ (unsigned char)0x54;

    DWORD len = 256;
    char lineup_str[256] = {0};
    CryptBinaryToStringA(lineup_bin, size + 1, CRYPT_STRING_BASE64, lineup_str, &len);

    std::string lineup(lineup_str);
    lineup.erase(std::remove(lineup.begin(), lineup.end(), '\r'), lineup.end());
    lineup.erase(std::remove(lineup.begin(), lineup.end(), '\n'), lineup.end());
#ifdef _DEBUG
    std::cout << lineup << " " << lineup.size() << std::endl;
#endif

    return lineup;
}

void PvZ::SetLineup(std::string lineup)
{
    const bool may_sleep[] = {false, false, false, false, false, false, false, false,
                              true, true, true, false, true, true, true, true,
                              false, false, false, false, false, false, false, false,
                              true, false, false, false, false, false, false, true,
                              false, false, false, false, false, false, false, false,
                              false, false, true, false, false, false, false, false};

    if (!std::regex_match(lineup, std::regex("[a-zA-Z0-9+/=]{18,164}")))
        return;
    if (lineup.size() % 4 != 0)
        return;
    if (std::count(lineup.begin(), lineup.end(), '=') > 2)
        return;

    uint16_t items[6 * 9] = {0};
    uint8_t rake_row = 0, scene = 2;

    unsigned long size = 128;
    unsigned char lineup_bin[128] = {0};
    BOOL ret_decode = CryptStringToBinaryA(lineup.c_str(), 0, CRYPT_STRING_BASE64, lineup_bin, &size, nullptr, nullptr);
    if (ret_decode == FALSE)
        return;

    for (size_t i = 0; i < size; i++)
        lineup_bin[i] = lineup_bin[i] ^ (unsigned char)0x54;

    rake_row = lineup_bin[size - 1] >> 4;
    scene = lineup_bin[size - 1] & 0b00001111;
    if (scene >= 6)
        return;
    if (rake_row != 0 && rake_row > ((scene == 2 || scene == 3) ? 6 : 5))
        return;
    if ((scene == 2 || scene == 3) && (rake_row == 3 || rake_row == 4))
        return;

    unsigned long cut_size = 6 * 9 * sizeof(uint16_t);
    int ret_decomp = uncompress((unsigned char *)items, &cut_size, lineup_bin, size - 1);
    if (ret_decomp != Z_OK)
        return;
    if (cut_size != ((scene == 2 || scene == 3) ? 6 : 5) * 9 * sizeof(uint16_t))
        return;

#ifdef _DEBUG
    std::cout << std::endl;
    std::cout << std::bitset<8>(lineup_bin[size - 1]);
    std::cout << std::endl;
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 9; c++)
            std::cout << std::bitset<16>(items[r * 9 + c]) << " ";
        std::cout << std::endl;
    }
#endif

    uint16_t plant[6 * 9] = {0};
    uint16_t plant_im[6 * 9] = {0};
    uint16_t plant_awake[6 * 9] = {0};
    uint16_t base[6 * 9] = {0};
    uint16_t base_im[6 * 9] = {0};
    uint16_t pumpkin[6 * 9] = {0};
    uint16_t pumpkin_im[6 * 9] = {0};
    uint16_t coffee[6 * 9] = {0};
    uint16_t coffee_im[6 * 9] = {0};
    uint16_t ladder[6 * 9] = {0};

    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            uint16_t item = items[r * 9 + c];
            plant[r * 9 + c] = (item & 0b1111110000000000) >> 10;
            plant_im[r * 9 + c] = (item & 0b0000001000000000) >> 9;
            plant_awake[r * 9 + c] = (item & 0b0000000100000000) >> 8;
            base[r * 9 + c] = (item & 0b0000000011000000) >> 6;
            base_im[r * 9 + c] = (item & 0b0000000000100000) >> 5;
            pumpkin[r * 9 + c] = (item & 0b0000000000010000) >> 4;
            pumpkin_im[r * 9 + c] = (item & 0b0000000000001000) >> 3;
            coffee[r * 9 + c] = (item & 0b0000000000000100) >> 2;
            coffee_im[r * 9 + c] = (item & 0b0000000000000010) >> 1;
            ladder[r * 9 + c] = (item & 0b0000000000000001) >> 0;
        }
    }

    // 下面是正式布阵

    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    int mode = GameMode();
    bool is_el = mode >= 11 && mode <= 15;
    bool is_iz = mode >= 61 && mode <= 70;
    if (!is_el && !is_iz)
        return;

    ClearGridItems({1, 3, 11});
    ClearAllPlants();
    auto has_lawn_mower = ReadMemory<uint32_t>({data().pvz_base, data().main_object, data().lawn_mower_count}) > 0;
    if (has_lawn_mower)
        SetLawnMowers(1);

    if (static_cast<int>(scene) != GetScene())
        SetScene(static_cast<int>(scene));
    int music_id = scene + 1;
    if (music_id == 6)
        music_id = 2;
    SetMusic(music_id);
    if (has_lawn_mower)
        SetLawnMowers(2);

    if (rake_row != 0)
    {
        int r = rake_row - 1;
        int c = 8 - 1;
        PutRake(r, c);
    }

    asm_init();
    // 睡莲 花盆
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (base[r * 9 + c] == 1)
                asm_put_plant(r, c, 16, base_im[r * 9 + c] == 1, is_iz);
            else if (base[r * 9 + c] == 2)
                asm_put_plant(r, c, 33, base_im[r * 9 + c] == 1, is_iz);
        }
    }
    // 主要植物
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (plant[r * 9 + c] == 0)
                continue;

            int plant_type = plant[r * 9 + c] - 1;
            bool plant_imitater = plant_im[r * 9 + c] == 1;
            bool plant_asleep = plant_awake[r * 9 + c] == 0;

            if (plant_type < 0 || plant_type > 47       //
                || plant_type == 16 || plant_type == 33 //
                || plant_type == 30 || plant_type == 35)
                continue;

            asm_put_plant(r, c, plant_type, plant_imitater, is_iz);

            // 蘑菇类植物唤醒
            if ((scene == 0 || scene == 2 || scene == 4) //
                && may_sleep[plant_type] && !plant_asleep)
            {
                asm_push_exx(Reg::EAX);
                if (isGOTY())
                    asm_add_list(0x8b, 0xf8); // mov edi,eax
                asm_push(0);
                asm_call(data().call_wakeup_plant);
                asm_pop_exx(Reg::EAX);
            }

            // 土豆雷和阳光菇长大
            if (plant_type == 4 || plant_type == 9)
            {
                asm_add_list(0xc7, 0x40, 0x54); // mov [eax+54],00000001
                asm_add_dword(0x00000001);
            }
        }
    }
    // 南瓜壳
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (pumpkin[r * 9 + c] == 1)
                asm_put_plant(r, c, 30, pumpkin_im[r * 9 + c] == 1, is_iz);
        }
    }
    // 咖啡豆
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (coffee[r * 9 + c] == 1)
                asm_put_plant(r, c, 35, coffee_im[r * 9 + c] == 1, is_iz);
        }
    }
    // 墓碑
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (base[r * 9 + c] == 3)
                asm_put_grave(r, c);
        }
    }
    // 梯子
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (ladder[r * 9 + c] == 1)
                asm_put_ladder(r, c);
        }
    }
    asm_ret();
    asm_code_inject();

    Sleep(GetFrameDuration());
}

// 根据出怪种类生成出怪列表
void PvZ::generate_spawn_list()
{
    if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
    {
        asm_init();
        asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
        asm_call(data().call_generate_spawn_list);
        asm_ret();
        asm_code_inject();
    }
    else
    {
        asm_init();
        asm_mov_exx_dword_ptr(Reg::EDI, data().pvz_base);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDI, data().main_object);
        asm_call(data().call_generate_spawn_list);
        asm_ret();
        asm_code_inject();
    }
}

// 更新选卡界面的出怪预览
void PvZ::update_spawn_preview()
{
    enable_hack(data().hack_spawn_preview, true);
    asm_init();
    asm_mov_exx_dword_ptr(Reg::EBX, data().pvz_base);
    asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().main_object);
    asm_call(data().call_clear_spawn_preview);
    asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().main_object);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().spawn_preview);
    asm_push_exx(Reg::EAX);
    asm_call(data().call_update_spawn_preview);
    asm_ret();
    asm_code_inject();
    enable_hack(data().hack_spawn_preview, false);
}

std::array<int, 1000> PvZ::GetSpawnList()
{
    std::array<int, 1000> zl;
    zl.fill(-1);

    if (!GameOn())
        return zl;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return zl;

    zl = ReadMemory<int, 1000>({data().pvz_base, data().main_object, data().spawn_list});

#ifdef _DEBUG
    std::cout << std::dec; // ffffffff -> -1
    std::cout << std::endl;
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 50; j++)
            std::cout << zl[i * 50 + j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
#endif

    for (size_t i = 0; i < 20; i++)
    {
        // 每一波遇到 -1 之后忽略后面的出怪
        // 所以就算读到了数据也改成 -1
        bool ignore_rest = false;
        for (size_t j = 0; j < 50; j++)
        {
            if (zl[i * 50 + j] == -1)
            {
                ignore_rest = true;
                continue;
            }
            if (ignore_rest)
            {
                zl[i * 50 + j] = -1;
            }
        }
    }

    return zl;
}

void PvZ::InternalSpawn(std::array<bool, 33> zombies)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    WriteMemory(zombies, {data().pvz_base, data().main_object, data().spawn_type});

    std::array<int, 2000> zombies_list;
    zombies_list.fill(-1);
    WriteMemory(zombies_list, {data().pvz_base, data().main_object, data().spawn_list});

    generate_spawn_list();
    if (ui == 2)
        update_spawn_preview();
}

void PvZ::CustomizeSpawn(std::array<bool, 33> zombies, bool limit_giga, bool simulate, int giga_weight)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    std::array<bool, 20> giga_waves;
    giga_waves.fill(true);
    if (limit_giga)
        for (size_t w = 11; w <= 19; w++)
            giga_waves[w - 1] = false;

    std::vector<double> weights = {
        4000, // 普僵
        0,    // 旗帜
        4000, // 路障
        2000, // 撑杆
        3000, // 铁桶
        1000, // 读报
        3500, // 铁门
        2000, // 橄榄
        1000, // 舞王
        0,    // 伴舞
        0,    // 鸭子
        2000, // 潜水
        2000, // 冰车
        2000, // 雪橇
        1500, // 海豚
        1000, // 小丑
        2000, // 气球
        1000, // 矿工
        1000, // 跳跳
        1,    // 雪人
        1000, // 蹦极
        1000, // 扶梯
        1500, // 投篮
        1500, // 白眼
        0,    // 小鬼
        0,    // 僵博
        4000, // 豌豆
        3000, // 坚果
        1000, // 辣椒
        2000, // 机枪
        2000, // 窝瓜
        2000, // 高墙
        6000  // 红眼
    };

#ifdef _DEBUG
    if (this->version == L"1.0.0.1051")
        for (size_t i = 0; i < 33; i++)
            assert(ReadMemory<int>({0x0069da94 + i * 0x1c}) == static_cast<int>(weights[i]));
#endif

    weights[0] = 400;
    weights[2] = 1000;
    std::vector<double> weights_flag = weights;
    weights[32] = giga_weight;
    std::vector<double> weights_normal = weights;
    std::discrete_distribution<unsigned int> dist_flag(weights_flag.begin(), weights_flag.end());
    std::discrete_distribution<unsigned int> dist_normal(weights_normal.begin(), weights_normal.end());
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen(static_cast<unsigned int>(seed));

    // 僵尸列表
    std::array<int, 1000> zombies_list;
    zombies_list.fill(-1);

    bool has_flag = zombies[1];
    bool has_yeti = zombies[19];
    bool has_bungee = zombies[20];
    bool has_giga = zombies[32];

    bool limit_flag = true;
    bool limit_yeti = true;
    bool limit_bungee = true;

    int count = 0;
    for (size_t i = 0; i < 33; i++)
        if (zombies[i])
            count++;

    if (count > 0)
    {
        int type = 0;
        for (size_t i = 0; i < 1000; i++)
        {
            do
            {
                if (simulate)
                {
                    if (((i / 50) % 10) == 9) // 旗帜波
                        type = dist_flag(gen);
                    else
                        type = dist_normal(gen);
                }
                else
                {
                    type += 1;
                    type %= 33;
                }
            } while ((!zombies[type])                                                          //
                     || (has_flag && limit_flag && type == 1)                                  //
                     || (has_yeti && limit_yeti && type == 19)                                 //
                     || (has_bungee && limit_bungee && type == 20)                             //
                     || (has_giga && limit_giga && type == 32 && !giga_waves[(i / 50) % 20])); //

            zombies_list[i] = type;
        }

        std::vector<size_t> index_flag = {450,                                       //
                                          950};                                      //
        std::vector<size_t> index_zombie = {451, 452, 453, 454, 455, 456, 457, 458,  //
                                            951, 952, 953, 954, 955, 956, 957, 958}; //
        std::vector<size_t> index_bungee = {459, 460, 461, 462,                      //
                                            959, 960, 961, 962};                     //

        if ((has_flag && limit_flag) || simulate)
            for (auto i : index_flag)
                zombies_list[i] = 1;

        if (simulate)
            for (auto i : index_zombie)
                zombies_list[i] = 0;

        if (has_bungee && limit_bungee)
            for (auto i : index_bungee)
                zombies_list[i] = 20;

        if (has_yeti && limit_yeti)
            zombies_list[rand() % 1000] = 19;
    }

    WriteMemory(zombies_list, {data().pvz_base, data().main_object, data().spawn_list});
    if (ui == 2)
        update_spawn_preview();
}

void PvZ::SetMusic(int id)
{
    if (!GameOn())
        return;

    asm_init();
    asm_mov_exx(Reg::EDI, id);
    asm_mov_exx_dword_ptr(Reg::EAX, data().pvz_base);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().background_music);
    asm_call(data().call_set_music);
    asm_ret();
    asm_code_inject();
}

void PvZ::NoFog(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().no_fog, on);
}

void PvZ::SeeVase(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().see_vase, on);
}

void PvZ::BackgroundRunning(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().background_running, on);
}

void PvZ::UserdataReadonly(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().disable_delete_userdata, on);
    enable_hack(data().disable_save_userdata, on);

    if (this->find_result == PVZ_1_2_0_1096_EN)
    {
        // Steam云同步自带不能删档的问题, 额外加上禁止存档
        enable_hack(HACK<uint8_t, 3>{0x00498440, {0xc2, 0x0c, 0x00}, {0x6a, 0xff, 0x68}}, on);
    }
}

void PvZ::DebugMode(int mode)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    WriteMemory<int>(mode, {data().pvz_base, data().main_object, data().debug_mode});
}

int PvZ::GetFrameDuration()
{
    int time_ms = 10;

    if (!GameOn())
        return time_ms;

    time_ms = ReadMemory<int>({data().pvz_base, data().ms_per_frame});

    return time_ms;
}

void PvZ::SetFrameDuration(int time_ms)
{
    if (!GameOn())
        return;

    WriteMemory<int>(time_ms, {data().pvz_base, data().ms_per_frame});
}

void PvZ::UnlockLimboPage(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().unlock_limbo_page, on);
}

} // namespace Pt
