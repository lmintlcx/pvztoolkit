
#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <Fl/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Table.H>
#include <FL/fl_draw.H>

#include "pvz.h"
#include "pak.h"

#include <Windows.h>
#include <ShlObj.h>
#include <ShellAPI.h>

namespace Pt::zh
{

// const char *plants[];
// const char *zombies[];
// const char *modes[];

// 实现 Fl_Choice 对滚轮的响应
class Fl_Choice_ : public Fl_Choice
{
public:
    Fl_Choice_(int, int, int, int, const char *);
    ~Fl_Choice_();

public:
    int Fl_Choice_::handle(int);
    bool scrollable = false;
};

// 显示出怪详情的表格
class SpawnTable : public Fl_Table
{
public:
    SpawnTable(int, int, int, int, const char *);
    ~SpawnTable();

public:
    static const int ROWS = 33;     // 33 种僵尸
    static const int COLS = 20 + 1; // 20 波 + 总数
    int data[ROWS][COLS] = {{0}};
    int total = 0;
    void UpdateData(std::array<int, 1000>);
    void draw_row_header(const char *, int, int, int, int);
    void draw_col_header(const char *, int, int, int, int);
    void draw_data(const char *, int, int, int, int, Fl_Color);
    void draw_cell(TableContext, int, int, int, int, int, int);
};

class Window : public Fl_Window
{
public:
    Window(int, int, const char *);
    ~Window();

    Fl_Tabs *tabs;

    Fl_Group *group_resource;
    Fl_Value_Input *input_sun;
    Fl_Button *button_sun;
    Fl_Value_Input *input_money;
    Fl_Button *button_money;
    Fl_Check_Button *check_auto_collect;
    Fl_Check_Button *check_no_falling;
    Fl_Check_Button *check_fertilizer;
    Fl_Check_Button *check_bug_spray;
    Fl_Check_Button *check_chocolate;
    Fl_Check_Button *check_tree_food;
    Fl_Value_Input *input_wisdom_tree;
    Fl_Button *button_wisdom_tree;
    Fl_Check_Button *check_free_planting;
    Fl_Check_Button *check_planting_anywhere;
    Fl_Check_Button *check_fast_belt;
    Fl_Check_Button *check_lock_shovel;
    Fl_Choice_ *choice_slot;
    Fl_Choice_ *choice_seed;
    Fl_Check_Button *check_seed_imitater;
    Fl_Button *button_seed;
    Fl_Choice_ *choice_music;
    Fl_Button *button_music;
    Fl_Value_Input *input_level;
    Fl_Button *button_level;

    Fl_Group *group_battle;
    Fl_Choice_ *choice_row;
    Fl_Choice_ *choice_col;
    Fl_Choice_ *choice_plant;
    Fl_Choice_ *choice_zombie;
    Fl_Button *button_put_plant;
    Fl_Button *button_put_zombie;
    Fl_Check_Button *check_imitater;
    Fl_Button *button_put_grave;
    Fl_Button *button_direct_win;
    Fl_Choice_ *choice_item;
    Fl_Button *button_clear;
    Fl_Button *button_put_ladder;
    Fl_Button *button_auto_ladder;
    Fl_Check_Button *check_plant_invincible;
    Fl_Check_Button *check_plant_weak;
    Fl_Check_Button *check_zombie_invincible;
    Fl_Check_Button *check_zombie_weak;
    Fl_Check_Button *check_reload_instantly;
    Fl_Check_Button *check_mushroom_awake;
    Fl_Check_Button *check_stop_spawning;
    Fl_Check_Button *check_stop_zombies;
    Fl_Check_Button *check_lock_butter;
    Fl_Check_Button *check_no_crater;
    Fl_Check_Button *check_no_ice_trail;
    Fl_Check_Button *check_zombie_not_explode;

    Fl_Group *group_spawn;
    int spawn_type[20];
    Fl_Check_Button *check_zombie[20];
    Fl_Button *button_show_details;
    Fl_Check_Button *check_limit_count;
    Fl_Button *button_internal_spawn;
    Fl_Button *button_customize_spawn;

    Fl_Group *group_others;
    Fl_Choice_ *choice_mode;
    Fl_Button *button_mix;
    Fl_Button *button_userdata;
    Fl_Check_Button *check_no_fog;
    Fl_Check_Button *check_see_vase;
    Fl_Check_Button *check_background;
    Fl_Check_Button *check_readonly;
    Fl_Button *button_file;
    Fl_Input *input_file;
    Fl_Button *button_unpack;
    Fl_Button *button_dir;
    Fl_Input *input_dir;
    Fl_Button *button_pack;
    Fl_Choice_ *choice_debug;
    Fl_Button *button_debug;
    Fl_Check_Button *check_show_hidden_games;
    Fl_Button *button_download;
    Fl_Button *button_update;
    Fl_Button *button_about;

    Fl_Box *game_status;
    Fl_Box *game_status_tooltip;

    Fl_Double_Window *window_spawn;
    SpawnTable *table_spawn;
    Fl_Button *button_update_details;

    PvZ *pvz;
    PAK *pak;

private:
    static std::string get_nt_version();

    std::string utf8_encode(const std::wstring &);
    std::wstring utf8_decode(const std::string &);

    static void cb_find_result(void *, int);
    inline void cb_find_result(int);

    inline void keep_selected_feature();

    static void cb_set_sun(Fl_Widget *, void *);
    inline void cb_set_sun();

    static void cb_set_money(Fl_Widget *, void *);
    inline void cb_set_money();

    static void cb_auto_collect(Fl_Widget *, void *);
    inline void cb_auto_collect();

    static void cb_no_falling(Fl_Widget *, void *);
    inline void cb_no_falling();

    static void cb_fertilizer(Fl_Widget *, void *);
    inline void cb_fertilizer();

    static void cb_bug_spray(Fl_Widget *, void *);
    inline void cb_bug_spray();

    static void cb_chocolate(Fl_Widget *, void *);
    inline void cb_chocolate();

    static void cb_tree_food(Fl_Widget *, void *);
    inline void cb_tree_food();

    static void cb_wisdom_tree(Fl_Widget *, void *);
    inline void cb_wisdom_tree();

    static void cb_free_planting(Fl_Widget *, void *);
    inline void cb_free_planting();

    static void cb_planting_anywhere(Fl_Widget *, void *);
    inline void cb_planting_anywhere();

    static void cb_fast_belt(Fl_Widget *, void *);
    inline void cb_fast_belt();

    static void cb_lock_shovel(Fl_Widget *, void *);
    inline void cb_lock_shovel();

    static void cb_get_seed(Fl_Widget *, void *);
    inline void cb_get_seed();

    static void cb_set_seed(Fl_Widget *, void *);
    inline void cb_set_seed();

    static void cb_music(Fl_Widget *, void *);
    inline void cb_music();

    static void cb_level(Fl_Widget *, void *);
    inline void cb_level();

    static void cb_put_plant(Fl_Widget *, void *);
    inline void cb_put_plant();

    static void cb_put_zombie(Fl_Widget *, void *);
    inline void cb_put_zombie();

    static void cb_put_grave(Fl_Widget *, void *);
    inline void cb_put_grave();

    static void cb_direct_win(Fl_Widget *, void *);
    inline void cb_direct_win();

    static void cb_clear(Fl_Widget *, void *);
    inline void cb_clear();

    static void cb_put_ladder(Fl_Widget *, void *);
    inline void cb_put_ladder();

    static void cb_auto_ladder(Fl_Widget *, void *);
    inline void cb_auto_ladder();

    static void cb_plant_invincible(Fl_Widget *, void *);
    inline void cb_plant_invincible();

    static void cb_plant_weak(Fl_Widget *, void *);
    inline void cb_plant_weak();

    static void cb_zombie_invincible(Fl_Widget *, void *);
    inline void cb_zombie_invincible();

    static void cb_zombie_weak(Fl_Widget *, void *);
    inline void cb_zombie_weak();

    static void cb_reload_instantly(Fl_Widget *, void *);
    inline void cb_reload_instantly();

    static void cb_mushroom_awake(Fl_Widget *, void *);
    inline void cb_mushroom_awake();

    static void cb_stop_spawning(Fl_Widget *, void *);
    inline void cb_stop_spawning();

    static void cb_stop_zombies(Fl_Widget *, void *);
    inline void cb_stop_zombies();

    static void cb_lock_butter(Fl_Widget *, void *);
    inline void cb_lock_butter();

    static void cb_no_crater(Fl_Widget *, void *);
    inline void cb_no_crater();

    static void cb_no_ice_trail(Fl_Widget *, void *);
    inline void cb_no_ice_trail();

    static void cb_zombie_not_explode(Fl_Widget *, void *);
    inline void cb_zombie_not_explode();

    static void cb_spawn_mutex_0(Fl_Widget *, void *);
    inline void cb_spawn_mutex_0();

    static void cb_spawn_mutex_3(Fl_Widget *, void *);
    inline void cb_spawn_mutex_3();

    static void cb_show_details(Fl_Widget *, void *);
    inline void cb_show_details();

    static void cb_update_details(Fl_Widget *, void *);
    inline void cb_update_details();

    static void cb_spawn_count_check(Fl_Widget *, void *);
    inline void cb_spawn_count_check();

    static void cb_internal_spawn(Fl_Widget *, void *);
    inline void cb_internal_spawn();

    static void cb_customize_spawn(Fl_Widget *, void *);
    inline void cb_customize_spawn();

    static void cb_mix_mode(Fl_Widget *, void *);
    inline void cb_mix_mode();

    static void cb_userdata(Fl_Widget *, void *);
    inline void cb_userdata();

    static void cb_no_fog(Fl_Widget *, void *);
    inline void cb_no_fog();

    static void cb_see_vase(Fl_Widget *, void *);
    inline void cb_see_vase();

    static void cb_background(Fl_Widget *, void *);
    inline void cb_background();

    static void cb_readonly(Fl_Widget *, void *);
    inline void cb_readonly();

    static void cb_open_file(Fl_Widget *, void *);
    inline void cb_open_file();

    static void cb_open_dir(Fl_Widget *, void *);
    inline void cb_open_dir();

    static void cb_unpack(Fl_Widget *, void *);
    inline void cb_unpack();
    static DWORD WINAPI cb_unpack_thread(void *);
    inline void cb_unpack_thread();

    static void cb_pack(Fl_Widget *, void *);
    inline void cb_pack();
    static DWORD WINAPI cb_pack_thread(void *);
    inline void cb_pack_thread();

    static void cb_debug_mode(Fl_Widget *, void *);
    inline void cb_debug_mode();

    static void cb_show_hidden_games(Fl_Widget *, void *);
    inline void cb_show_hidden_games();

    static void cb_download(Fl_Widget *, void *);
    inline void cb_download();

    static void cb_update(Fl_Widget *, void *);
    inline void cb_update();

    static void cb_about(Fl_Widget *, void *);
    inline void cb_about();

    static void cb_on_hide_details(Fl_Widget *, void *);
    inline void cb_on_hide_details();
};

} // namespace Pt
