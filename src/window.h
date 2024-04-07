
#pragma once

#include <FL/x.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Double_Window.H>
#include <Fl/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Table.H>
#include <FL/fl_ask.H>

#include <Windows.h>
#include <ShlObj.h>
#include <VersionHelpers.h>

#include <iostream>
#include <map>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <filesystem>
#include <regex>
#include <algorithm>

#include "pvz.h"
#include "lineup.h"
#include "../res/version.h"

namespace Pt
{

#define EMOJI(e, s) ((std::string(this->emoji ? (e) : "▢") + ((s)[0] == 0 ? "" : " ") + (s)).c_str())

// Implement Fl_Choice's response to the scroll wheel
class Fl_Choice_ : public Fl_Choice
{
  public:
    Fl_Choice_(int, int, int, int, const char *);
    ~Fl_Choice_();
    int handle(int);

  public:
    bool scrollable = false;
};

// Implement Fl_Input to clear before dragging into the path
class Fl_Input_ : public Fl_Input
{
  public:
    Fl_Input_(int, int, int, int, const char *);
    ~Fl_Input_();
    int handle(int);
};

// A table showing monster details
class SpawnTable : public Fl_Table
{
  public:
    SpawnTable(int, int, int, int, const char *);
    ~SpawnTable();
    void UpdateData(std::array<int, 1000>);

  public:
    static const int ROWS = 33;     // 33 Plant zombies
    static const int COLS = 20 + 1; // 20 wave + total
    int data[ROWS][COLS] = {{0}};
    int total = 0;
    void draw_cell(TableContext, int, int, int, int, int, int);
};

class SpawnWindow : public Fl_Double_Window
{
  public:
    SpawnWindow(int, int, const char *);
    ~SpawnWindow();
    void UpdateData(std::array<int, 1000>);

  public:
    SpawnTable *table_spawn;
    Fl_Button *button_update_details;
    Fl_Menu_Button *button_zombies_list;
    Fl_Box *box_mask_spawn_types;
    bool emoji = false;

  public:
    void tooltips(bool);
    bool on = false;
};

class Window : public Fl_Double_Window
{
  public:
    Window(int, int, const char *);
    ~Window();

    void ReadSettings();
    void WriteSettings();

    Fl_Check_Button *check_reg_zombie; // Added new button
	
	Fl_Tabs *tabs;

    Fl_Group *group_resource;
    Fl_Round_Button *check_unlock_sun_limit;
    Fl_Value_Input *input_sun;
    Fl_Button *button_sun;
    Fl_Box *box_money;
    Fl_Value_Input *input_money;
    Fl_Button *button_money;
    Fl_Check_Button *check_auto_collected;
    Fl_Check_Button *check_not_drop_loot;
    Fl_Check_Button *check_fertilizer;
    Fl_Check_Button *check_bug_spray;
    Fl_Check_Button *check_tree_food;
    Fl_Check_Button *check_chocolate;
    Fl_Box *box_wisdom_tree;
    Fl_Value_Input *input_wisdom_tree;
    Fl_Button *button_wisdom_tree;
    Fl_Check_Button *check_free_planting;
    Fl_Check_Button *check_placed_anywhere;
    Fl_Check_Button *check_fast_belt;
    Fl_Check_Button *check_lock_shovel;
    Fl_Choice_ *choice_mode;
    Fl_Choice_ *choice_adventure;
    Fl_Button *button_mix;
    Fl_Value_Input *input_level;
    Fl_Button *button_level;
    Fl_Button *button_unlock;
    Fl_Button *button_direct_win;

    Fl_Group *group_battle;
    Fl_Choice_ *choice_row;
    Fl_Choice_ *choice_col;
    Fl_Choice_ *choice_plant;
    Fl_Choice_ *choice_zombie;
    Fl_Button *button_put_plant;
    Fl_Check_Button *check_imitater;
    Fl_Button *button_put_zombie;
    Fl_Button *button_put_ladder;
    Fl_Button *button_put_grave;
    Fl_Button *button_put_rake;
    Fl_Menu_Button *button_lawn_mower;
    Fl_Choice_ *choice_item;
    Fl_Button *button_clear;
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

    Fl_Group *group_lineup;
    Fl_Choice_ *choice_slot;
    Fl_Choice_ *choice_seed;
    Fl_Button *button_seed;
    Fl_Check_Button *check_seed_imitater;
    Fl_Check_Button *check_lineup_mode;
    Fl_Button *button_auto_ladder;
    unsigned int lily_pad_col_lower[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    unsigned int lily_pad_col_upper[8] = {2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int flower_pot_col_lower[7] = {1, 4, 4, 4, 4, 4, 4};
    unsigned int flower_pot_col_upper[7] = {3, 4, 5, 6, 7, 8, 9};
    Fl_Menu_Button *button_put_lily_pad;
    Fl_Menu_Button *button_put_flower_pot;
    Fl_Button *button_reset;
    Fl_Choice_ *choice_scene;
    std::vector<Lineup> lineups;
    unsigned int lineup_count[6] = {0};
    Fl_Button *button_load_lineup;
    Fl_Choice_ *choice_lineup_name[6];
    Fl_Text_Buffer *buffer_lineup_string;
    Fl_Text_Editor *editor_lineup_string;
    Fl_Button *button_get_lineup;
    Fl_Button *button_copy_lineup;
    Fl_Button *button_paste_lineup;
    Fl_Button *button_set_lineup;
    Fl_Button *button_capture;

    Fl_Group *group_spawn;
    int spawn_type[20];
    bool limit_species = true;
    Fl_Check_Button *check_zombie[20];
    Fl_Button *button_show_details;
    Fl_Choice_ *choice_giga_weight;
    Fl_Check_Button *check_giga_limit;
    Fl_Button *button_set_spawn;
    Fl_Menu_Button *button_spawn_extra;
    Fl_Menu_Button *button_spawn_mode;

    Fl_Group *group_others;
    Fl_Choice_ *choice_music;
    Fl_Button *button_music;
    Fl_Button *button_userdata;
    Fl_Check_Button *check_no_fog;
    Fl_Check_Button *check_see_vase;
    Fl_Check_Button *check_background;
    Fl_Check_Button *check_readonly;
    Fl_Button *button_file;
    Fl_Input_ *input_file;
    Fl_Button *button_unpack;
    Fl_Button *button_dir;
    Fl_Input_ *input_dir;
    Fl_Button *button_pack;
    Fl_Choice_ *choice_debug;
    Fl_Button *button_debug;
    Fl_Choice_ *choice_speed;
    Fl_Button *button_speed;
    Fl_Check_Button *check_limbo_page;
    Fl_Choice_ *choice_scheme;
    Fl_Check_Button *check_tooltips;
    Fl_Button *button_document;
    Fl_Button *button_about;

    Fl_Box *box_mask_resource;
    Fl_Box *box_mask_battle;
    Fl_Box *box_mask_lineup;
    Fl_Box *box_mask_spawn;
    Fl_Box *box_mask_others;

    int result = PVZ_NOT_FOUND;
    Fl_Box *game_status;
    Fl_Box *game_status_tip;
    bool bad_version_warned = false;

    bool emoji = false;
    bool emoji_i = false;

  protected:
    std::string utf8_encode(const std::wstring &);
    std::wstring utf8_decode(const std::string &);

    static void cb_find_result(void *, int);
    inline void cb_find_result(int);
    static void cb_find_result_tooltip(Fl_Widget *, void *);
    inline void cb_find_result_tooltip();

    inline void keep_selected_feature();

    static void cb_mode(Fl_Widget *, void *);
    inline void cb_mode();

    static void cb_load_lineup(Fl_Widget *, void *);
    inline void cb_load_lineup();

    inline void import_lineup_list(bool);
    inline void import_lineup_list_file(std::wstring);

    static void cb_switch_lineup_scene(Fl_Widget *, void *);
    inline void cb_switch_lineup_scene();

    static void cb_show_lineup_string(Fl_Widget *, void *);
    inline void cb_show_lineup_string();

    static void cb_copy_lineup(Fl_Widget *, void *);
    inline void cb_copy_lineup();

    static void cb_paste_lineup(Fl_Widget *, void *);
    inline void cb_paste_lineup();

    static void cb_spawn_mutex_0(Fl_Widget *, void *);
    inline void cb_spawn_mutex_0();

    static void cb_spawn_mutex_3(Fl_Widget *, void *);
    inline void cb_spawn_mutex_3();

    static void cb_spawn_count_check(Fl_Widget *, void *);
    inline void cb_spawn_count_check();

    static void cb_clear_checked_zombies(Fl_Widget *, void *);
    inline void cb_clear_checked_zombies();

    static void cb_disable_limit_species(Fl_Widget *, void *);
    inline void cb_disable_limit_species();

    static void cb_switch_spawn_mode(Fl_Widget *, void *);
    inline void cb_switch_spawn_mode();

    static void cb_open_file(Fl_Widget *, void *);
    inline void cb_open_file();

    static void cb_open_dir(Fl_Widget *, void *);
    inline void cb_open_dir();

    static void cb_scheme(Fl_Widget *, void *);
    inline void cb_scheme();

    static void cb_tooltips(Fl_Widget *, void *);
    inline void cb_tooltips();

    static void cb_document(Fl_Widget *, void *);
    inline void cb_document();

    static void cb_about(Fl_Widget *, void *);
    inline void cb_about();
};

} // namespace Pt
