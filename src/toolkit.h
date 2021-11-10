
#pragma once

#include "pvz.h"
#include "pak.h"
#include "window.h"

namespace Pt
{

class Toolkit : public Window
{
  public:
    Toolkit(int, int, const char *);
    ~Toolkit();

    static void cb_tooltips(Fl_Widget *, void *);
    inline void cb_tooltips();

    void close_all_sub_window();

  public:
    SpawnWindow *window_spawn;

    static void cb_show_details(Fl_Widget *, void *);
    inline void cb_show_details();

    static void cb_update_details(Fl_Widget *, void *);
    inline void cb_update_details();

    static void cb_on_hide_spawn_details(Fl_Widget *, void *);
    inline void cb_on_hide_spawn_details();

  public:
    PvZ *pvz;
    PAK *pak;

    static void cb_unlock_sun_limit(Fl_Widget *, void *);
    inline void cb_unlock_sun_limit();

    static void cb_set_sun(Fl_Widget *, void *);
    inline void cb_set_sun();

    static void cb_set_money(Fl_Widget *, void *);
    inline void cb_set_money();

    static void cb_auto_collected(Fl_Widget *, void *);
    inline void cb_auto_collected();

    static void cb_not_drop_loot(Fl_Widget *, void *);
    inline void cb_not_drop_loot();

    static void cb_fertilizer(Fl_Widget *, void *);
    inline void cb_fertilizer();

    static void cb_bug_spray(Fl_Widget *, void *);
    inline void cb_bug_spray();

    static void cb_tree_food(Fl_Widget *, void *);
    inline void cb_tree_food();

    static void cb_chocolate(Fl_Widget *, void *);
    inline void cb_chocolate();

    static void cb_wisdom_tree(Fl_Widget *, void *);
    inline void cb_wisdom_tree();

    static void cb_free_planting(Fl_Widget *, void *);
    inline void cb_free_planting();

    static void cb_placed_anywhere(Fl_Widget *, void *);
    inline void cb_placed_anywhere();

    static void cb_fast_belt(Fl_Widget *, void *);
    inline void cb_fast_belt();

    static void cb_lock_shovel(Fl_Widget *, void *);
    inline void cb_lock_shovel();

    static void cb_mix_mode(Fl_Widget *, void *);
    inline void cb_mix_mode();

    static void cb_endless_rounds(Fl_Widget *, void *);
    inline void cb_endless_rounds();

    static void cb_unlock(Fl_Widget *, void *);
    inline void cb_unlock();

    static void cb_direct_win(Fl_Widget *, void *);
    inline void cb_direct_win();
    static DWORD WINAPI cb_direct_win_thread(void *);
    inline void cb_direct_win_thread();

    static void cb_put_plant(Fl_Widget *, void *);
    inline void cb_put_plant();

    static void cb_put_zombie(Fl_Widget *, void *);
    inline void cb_put_zombie();

    static void cb_put_ladder(Fl_Widget *, void *);
    inline void cb_put_ladder();

    static void cb_put_grave(Fl_Widget *, void *);
    inline void cb_put_grave();

    static void cb_put_rake(Fl_Widget *, void *);
    inline void cb_put_rake();

    static void cb_lawn_mower(Fl_Widget *, void *);
    inline void cb_lawn_mower();

    static void cb_clear(Fl_Widget *, void *);
    inline void cb_clear();

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

    static void cb_get_seed(Fl_Widget *, void *);
    inline void cb_get_seed();

    static void cb_set_seed(Fl_Widget *, void *);
    inline void cb_set_seed();

    static void cb_lineup_mode(Fl_Widget *, void *);
    inline void cb_lineup_mode();

    static void cb_auto_ladder(Fl_Widget *, void *);
    inline void cb_auto_ladder();

    static void cb_put_lily_pad(Fl_Widget *, void *);
    inline void cb_put_lily_pad();

    static void cb_put_flower_pot(Fl_Widget *, void *);
    inline void cb_put_flower_pot();

    static void cb_reset_scene(Fl_Widget *, void *);
    inline void cb_reset_scene();

    static void cb_get_lineup(Fl_Widget *, void *);
    inline void cb_get_lineup();

    static void cb_set_lineup(Fl_Widget *, void *);
    inline void cb_set_lineup();

    static void cb_capture(Fl_Widget *, void *);
    inline void cb_capture();

    static void cb_set_spawn(Fl_Widget *, void *);
    inline void cb_set_spawn();

    static void cb_music(Fl_Widget *, void *);
    inline void cb_music();

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

    static void cb_speed(Fl_Widget *, void *);
    inline void cb_speed();

    static void cb_limbo_page(Fl_Widget *, void *);
    inline void cb_limbo_page();
};

} // namespace Pt
