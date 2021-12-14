
#include "toolkit.h"

namespace Pt
{

Toolkit::Toolkit(int width, int height, const char *title)
    : Window(width, height, title)
{
    // 子窗口

    window_spawn = new SpawnWindow(0, 0, "");

    // 窗口回调函数

    button_show_details->callback(cb_show_details, this);

    window_spawn->button_update_details->callback(cb_update_details, this);

    window_spawn->callback(cb_on_hide_spawn_details, this);

    // 工作类

    pvz = new PvZ();
    pvz->callback(cb_find_result, this);
    // pvz->FindPvZ(); // 在 main() 里调用

    pak = new PAK();

    // 工作回调函数

    check_unlock_sun_limit->callback(cb_unlock_sun_limit, this);
    button_sun->callback(cb_set_sun, this);
    button_money->callback(cb_set_money, this);
    check_auto_collected->callback(cb_auto_collected, this);
    check_not_drop_loot->callback(cb_not_drop_loot, this);

    check_fertilizer->callback(cb_fertilizer, this);
    check_bug_spray->callback(cb_bug_spray, this);
    check_tree_food->callback(cb_tree_food, this);
    check_chocolate->callback(cb_chocolate, this);

    button_wisdom_tree->callback(cb_wisdom_tree, this);

    check_free_planting->callback(cb_free_planting, this);
    check_placed_anywhere->callback(cb_placed_anywhere, this);
    check_fast_belt->callback(cb_fast_belt, this);
    check_lock_shovel->callback(cb_lock_shovel, this);

    button_mix->callback(cb_mix_mode, this);
    button_level->callback(cb_endless_rounds, this);

    button_unlock->callback(cb_unlock, this);
    button_direct_win->callback(cb_direct_win, this);

    button_put_plant->callback(cb_put_plant, this);
    button_put_zombie->callback(cb_put_zombie, this);
    button_put_ladder->callback(cb_put_ladder, this);
    button_put_grave->callback(cb_put_grave, this);
    button_put_rake->callback(cb_put_rake, this);

    button_lawn_mower->callback(cb_lawn_mower, this);
    button_clear->callback(cb_clear, this);

    check_plant_invincible->callback(cb_plant_invincible, this);
    check_plant_weak->callback(cb_plant_weak, this);
    check_zombie_invincible->callback(cb_zombie_invincible, this);
    check_zombie_weak->callback(cb_zombie_weak, this);
    check_reload_instantly->callback(cb_reload_instantly, this);
    check_mushroom_awake->callback(cb_mushroom_awake, this);
    check_stop_spawning->callback(cb_stop_spawning, this);
    check_stop_zombies->callback(cb_stop_zombies, this);
    check_lock_butter->callback(cb_lock_butter, this);
    check_no_crater->callback(cb_no_crater, this);
    check_no_ice_trail->callback(cb_no_ice_trail, this);
    check_zombie_not_explode->callback(cb_zombie_not_explode, this);

    choice_slot->callback(cb_get_seed, this); // cb_tooltips
    button_seed->callback(cb_set_seed, this);

    check_lineup_mode->callback(cb_lineup_mode, this);
    button_auto_ladder->callback(cb_auto_ladder, this);
    button_put_lily_pad->callback(cb_put_lily_pad, this);
    button_put_flower_pot->callback(cb_put_flower_pot, this);
    button_reset->callback(cb_reset_scene, this);

    button_get_lineup->callback(cb_get_lineup, this);
    button_set_lineup->callback(cb_set_lineup, this);
    button_capture->callback(cb_capture, this);

    button_set_spawn->callback(cb_set_spawn, this);

    button_music->callback(cb_music, this);
    button_userdata->callback(cb_userdata, this);

    check_no_fog->callback(cb_no_fog, this);
    check_see_vase->callback(cb_see_vase, this);
    check_background->callback(cb_background, this);
    check_readonly->callback(cb_readonly, this);

    button_unpack->callback(cb_unpack, this);
    button_pack->callback(cb_pack, this);

    button_debug->callback(cb_debug_mode, this);
    button_speed->callback(cb_speed, this);
    check_limbo_page->callback(cb_limbo_page, this);

    check_tooltips->callback(cb_tooltips, this); // 重载

    this->cb_tooltips();
}

Toolkit::~Toolkit()
{
    delete pvz;
    delete pak;
}

void Toolkit::cb_tooltips(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_tooltips();
}

void Toolkit::cb_tooltips()
{
    bool on = check_tooltips->value() == 1;

    window_spawn->tooltips(on);

    if (window_spawn->shown() == 1)
    {
        button_show_details->copy_label(EMOJI("📉", "隐藏详情"));
        button_show_details->copy_tooltip(on ? "Hide Details" : nullptr);
    }
    else
    {
        button_show_details->copy_label(EMOJI("📈", "查看详情"));
        button_show_details->copy_tooltip(on ? "Show Details" : nullptr);
    }

    Window::cb_tooltips(); // 放在最后
}

void Toolkit::close_all_sub_window()
{
    if (window_spawn->shown() == 1)
        window_spawn->hide();
}

void Toolkit::cb_show_details(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_show_details();
}

void Toolkit::cb_show_details()
{
    if (window_spawn->shown() == 0)
    {
        window_spawn->show();
        cb_update_details();
    }
    else
    {
        window_spawn->hide();
    }

    cb_tooltips();
}

void Toolkit::cb_update_details(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_update_details();
}

void Toolkit::cb_update_details()
{
    std::array<int, 1000> zombies_list;
    zombies_list.fill(-1);

    if (!pvz->GameOn())
    {
        // 没有打开游戏
    }
    else
    {
        int game_ui = pvz->GameUI();
        if (game_ui != 2 && game_ui != 3)
        {
            // 未进入选卡或者战斗界面
        }
        else
        {
            int game_mode = pvz->GameMode();
            if (game_mode >= 1 && game_mode <= 5)
            {
                zombies_list = pvz->GetSpawnList();
                for (size_t i = 500; i < 1000; i++)
                    zombies_list[i] = -1;
            }
            else if (game_mode >= 6 && game_mode <= 15)
            {
                zombies_list = pvz->GetSpawnList();
            }
            else
            {
                // 不支持非生存模式
            }
        }
    }

    window_spawn->UpdateData(zombies_list);
}

void Toolkit::cb_on_hide_spawn_details(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_on_hide_spawn_details();
}

void Toolkit::cb_on_hide_spawn_details()
{
    window_spawn->hide();

    cb_tooltips();
}

//
//
//
//
//

void Toolkit::cb_unlock_sun_limit(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_unlock_sun_limit();
}

void Toolkit::cb_unlock_sun_limit()
{
    pvz->UnlockSunLimit(check_unlock_sun_limit->value());
}

void Toolkit::cb_set_sun(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_set_sun();
}

void Toolkit::cb_set_sun()
{
    pvz->SetSun(static_cast<int>(input_sun->value()));
}

void Toolkit::cb_set_money(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_set_money();
}

void Toolkit::cb_set_money()
{
    pvz->SetMoney(static_cast<int>(input_money->value()));
}

void Toolkit::cb_auto_collected(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_auto_collected();
}

void Toolkit::cb_auto_collected()
{
    pvz->AutoCollected(check_auto_collected->value());
}

void Toolkit::cb_not_drop_loot(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_not_drop_loot();
}

void Toolkit::cb_not_drop_loot()
{
    pvz->NotDropLoot(check_not_drop_loot->value());
}

void Toolkit::cb_fertilizer(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_fertilizer();
}

void Toolkit::cb_fertilizer()
{
    pvz->FertilizerUnlimited(check_fertilizer->value());
}

void Toolkit::cb_bug_spray(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_bug_spray();
}

void Toolkit::cb_bug_spray()
{
    pvz->BugSprayUnlimited(check_bug_spray->value());
}

void Toolkit::cb_tree_food(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_tree_food();
}

void Toolkit::cb_tree_food()
{
    pvz->TreeFoodUnlimited(check_tree_food->value());
}

void Toolkit::cb_chocolate(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_chocolate();
}

void Toolkit::cb_chocolate()
{
    pvz->ChocolateUnlimited(check_chocolate->value());
}

void Toolkit::cb_wisdom_tree(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_wisdom_tree();
}

void Toolkit::cb_wisdom_tree()
{
    pvz->SetTreeHeight(static_cast<int>(input_wisdom_tree->value()));
}

void Toolkit::cb_free_planting(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_free_planting();
}

void Toolkit::cb_free_planting()
{
    pvz->FreePlanting(check_free_planting->value());
}

void Toolkit::cb_placed_anywhere(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_placed_anywhere();
}

void Toolkit::cb_placed_anywhere()
{
    pvz->PlacedAnywhere(check_placed_anywhere->value());
}

void Toolkit::cb_fast_belt(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_fast_belt();
}

void Toolkit::cb_fast_belt()
{
    pvz->FastBelt(check_fast_belt->value());
}

void Toolkit::cb_lock_shovel(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_lock_shovel();
}

void Toolkit::cb_lock_shovel()
{
    pvz->LockShovel(check_lock_shovel->value());
}

void Toolkit::cb_mix_mode(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_mix_mode();
}

void Toolkit::cb_mix_mode()
{
    int mode = choice_mode->value();
    int level = choice_adventure->value();

    if (mode == 0) // 冒险模式
        level++;

    pvz->MixMode(mode, level);
}

void Toolkit::cb_endless_rounds(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_endless_rounds();
}

void Toolkit::cb_endless_rounds()
{
    pvz->EndlessRounds(static_cast<int>(input_level->value()));
}

void Toolkit::cb_unlock(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_unlock();
}

void Toolkit::cb_unlock()
{
    pvz->UnlockTrophy();
}

void Toolkit::cb_direct_win(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_direct_win();
}

void Toolkit::cb_direct_win()
{
    if (!pvz->GameOn())
        return;

    HANDLE hThread = CreateThread(nullptr, 0, cb_direct_win_thread, this, 0, nullptr);

    DWORD dwExitCode = STILL_ACTIVE;
    while (GetExitCodeThread(hThread, &dwExitCode) != 0 //
           && dwExitCode == STILL_ACTIVE)
    {
        Fl::check();
        Sleep(1);
    }

    CloseHandle(hThread);

    button_direct_win->take_focus();
}

DWORD Toolkit::cb_direct_win_thread(void *w)
{
    ((Toolkit *)w)->cb_direct_win_thread();
    return 0;
}

void Toolkit::cb_direct_win_thread()
{
    Fl::lock();
    button_direct_win->deactivate();
    Fl::unlock();
    Fl::awake();

    pvz->DirectWin();

    Fl::lock();
    button_direct_win->activate();
    Fl::unlock();
    Fl::awake();
}

void Toolkit::cb_put_plant(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_put_plant();
}

void Toolkit::cb_put_plant()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    int type = choice_plant->value();
    bool imitater = check_imitater->value();
    pvz->PutPlant(row, col, type, imitater);
}

void Toolkit::cb_put_zombie(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_put_zombie();
}

void Toolkit::cb_put_zombie()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    int type = choice_zombie->value();
    pvz->PutZombie(row, col, type);
}

void Toolkit::cb_put_ladder(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_put_ladder();
}

void Toolkit::cb_put_ladder()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    pvz->PutLadder(row, col);
}

void Toolkit::cb_put_grave(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_put_grave();
}

void Toolkit::cb_put_grave()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    pvz->PutGrave(row, col);
}

void Toolkit::cb_put_rake(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_put_rake();
}

void Toolkit::cb_put_rake()
{
    int row = choice_row->value() - 1;
    int col = choice_col->value() - 1;
    pvz->PutRake(row, col);
}

void Toolkit::cb_lawn_mower(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_lawn_mower();
}

void Toolkit::cb_lawn_mower()
{
    pvz->SetLawnMowers(button_lawn_mower->value());
}

void Toolkit::cb_clear(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_clear();
}

void Toolkit::cb_clear()
{
    switch (choice_item->value())
    {
    case 0: // 植物
        pvz->ClearAllPlants();
        break;
    case 1: // 僵尸
        pvz->KillAllZombies();
        break;
    case 2: // 梯子
        pvz->ClearGridItems({3});
        break;
    case 3: // 墓碑
        pvz->ClearGridItems({1});
        break;
    case 4: // 钉耙
        pvz->ClearGridItems({11});
        break;
    default:
        break;
    }
}

void Toolkit::cb_plant_invincible(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_plant_invincible();
}

void Toolkit::cb_plant_invincible()
{
    if (check_plant_weak->value())
        check_plant_weak->value(0);

    pvz->PlantWeak(false);
    pvz->PlantInvincible(check_plant_invincible->value());
}

void Toolkit::cb_plant_weak(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_plant_weak();
}

void Toolkit::cb_plant_weak()
{
    if (check_plant_invincible->value())
        check_plant_invincible->value(0);

    pvz->PlantInvincible(false);
    pvz->PlantWeak(check_plant_weak->value());
}

void Toolkit::cb_zombie_invincible(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_zombie_invincible();
}

void Toolkit::cb_zombie_invincible()
{
    if (check_zombie_weak->value())
        check_zombie_weak->value(0);

    pvz->ZombieWeak(false);
    pvz->ZombieInvincible(check_zombie_invincible->value());
}

void Toolkit::cb_zombie_weak(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_zombie_weak();
}

void Toolkit::cb_zombie_weak()
{
    if (check_zombie_invincible->value())
        check_zombie_invincible->value(0);

    pvz->ZombieInvincible(false);
    pvz->ZombieWeak(check_zombie_weak->value());
}

void Toolkit::cb_reload_instantly(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_reload_instantly();
}

void Toolkit::cb_reload_instantly()
{
    pvz->ReloadInstantly(check_reload_instantly->value());
}

void Toolkit::cb_mushroom_awake(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_mushroom_awake();
}

void Toolkit::cb_mushroom_awake()
{
    pvz->MushroomsAwake(check_mushroom_awake->value());
}

void Toolkit::cb_stop_spawning(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_stop_spawning();
}

void Toolkit::cb_stop_spawning()
{
    pvz->StopSpawning(check_stop_spawning->value());
}

void Toolkit::cb_stop_zombies(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_stop_zombies();
}

void Toolkit::cb_stop_zombies()
{
    pvz->StopZombies(check_stop_zombies->value());
}

void Toolkit::cb_lock_butter(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_lock_butter();
}

void Toolkit::cb_lock_butter()
{
    pvz->LockButter(check_lock_butter->value());
}

void Toolkit::cb_no_crater(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_no_crater();
}

void Toolkit::cb_no_crater()
{
    pvz->NoCrater(check_no_crater->value());
}

void Toolkit::cb_no_ice_trail(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_no_ice_trail();
}

void Toolkit::cb_no_ice_trail()
{
    pvz->NoIceTrail(check_no_ice_trail->value());
}

void Toolkit::cb_zombie_not_explode(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_zombie_not_explode();
}

void Toolkit::cb_zombie_not_explode()
{
    pvz->ZombieNotExplode(check_zombie_not_explode->value());
}

void Toolkit::cb_get_seed(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_get_seed();
}

void Toolkit::cb_get_seed()
{
    int seed_type;
    bool is_imitater;

    int seed = pvz->GetSlotSeed(choice_slot->value());
    if (seed >= 48)
    {
        seed_type = seed - 48;
        is_imitater = true;
    }
    else
    {
        seed_type = seed;
        is_imitater = false;
    }

    choice_seed->value(seed_type);
    check_seed_imitater->value(is_imitater);

    cb_tooltips();
}

void Toolkit::cb_set_seed(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_set_seed();
}

void Toolkit::cb_set_seed()
{
    int index = choice_slot->value();
    int seed_type = choice_seed->value();
    bool is_imitater = check_seed_imitater->value();

    pvz->SetSlotSeed(index, seed_type, is_imitater);
}

void Toolkit::cb_lineup_mode(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_lineup_mode();
}

void Toolkit::cb_lineup_mode()
{
    bool do_do_callback = pvz->IsValid();

    std::vector<Fl_Check_Button *> check_buttons = {
        check_auto_collected,
        check_free_planting,
        check_plant_invincible,
        check_plant_weak,
        check_reload_instantly,
        check_stop_spawning,
        check_no_fog,
    };

    if (check_lineup_mode->value())
    {
        // 勾选时开启所有功能, 然后按钮组恢复原状态
        for (size_t i = 0; i < check_buttons.size(); i++)
        {
            check_buttons[i]->deactivate();
            if (check_buttons[i] == check_plant_weak)
                continue;
            int ori_val = check_buttons[i]->value();
            check_buttons[i]->value(1);
            if (do_do_callback)
                check_buttons[i]->do_callback();
            check_buttons[i]->value(ori_val);
        }
    }
    else
    {
        // 取消时应用按钮组已勾选状态
        for (size_t i = 0; i < check_buttons.size(); i++)
        {
            check_buttons[i]->activate();
            if (check_buttons[i] == check_plant_weak)
                continue;
            if (do_do_callback)
                check_buttons[i]->do_callback();
        }
    }
}

void Toolkit::cb_auto_ladder(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_auto_ladder();
}

void Toolkit::cb_auto_ladder()
{
    pvz->AutoLadder(true);
}

void Toolkit::cb_put_lily_pad(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_put_lily_pad();
}

void Toolkit::cb_put_lily_pad()
{
    int i = button_put_lily_pad->value();
    if (i < 0 || i >= 8)
        return;
    int from_col = lily_pad_col_lower[i];
    int to_col = lily_pad_col_upper[i];
    pvz->LilyPadOnPool(from_col, to_col);
}

void Toolkit::cb_put_flower_pot(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_put_flower_pot();
}

void Toolkit::cb_put_flower_pot()
{
    int i = button_put_flower_pot->value();
    if (i < 0 || i >= 7)
        return;
    int from_col = flower_pot_col_lower[i];
    int to_col = flower_pot_col_upper[i];
    pvz->FlowerPotOnRoof(from_col, to_col);
}

void Toolkit::cb_reset_scene(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_reset_scene();
}

void Toolkit::cb_reset_scene()
{
    pvz->SetScene(choice_scene->value(), true);
}

void Toolkit::cb_get_lineup(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_get_lineup();
}

void Toolkit::cb_get_lineup()
{
    Lineup lineup = pvz->GetLineup();
    std::string str = lineup.Generate();
    buffer_lineup_string->text(str.c_str());
}

void Toolkit::cb_set_lineup(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_set_lineup();
}

void Toolkit::cb_set_lineup()
{
    std::string str = buffer_lineup_string->text();

    // Base64Url 转标准 Base64
    std::replace(str.begin(), str.end(), '-', '+');
    std::replace(str.begin(), str.end(), '_', '/');
    switch (str.size() % 4)
    {
    case 0:
        break;
    case 1:
        return;
    case 2:
        str += "==";
        break;
    case 3:
        str += "=";
        break;
    }

    Lineup lineup(str);
    pvz->SetLineup(lineup);
}

void Toolkit::cb_capture(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_capture();
}

void Toolkit::cb_capture()
{
    pvz->Screenshot();
}

void Toolkit::cb_set_spawn(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_set_spawn();
}

void Toolkit::cb_set_spawn()
{
    int spawn_mode = button_spawn_mode->value();
    // std::cout << "Spawn Mode: " << spawn_mode << std::endl;

    if (!pvz->GameOn())
        return;
    int game_ui = pvz->GameUI();
    if (game_ui != 2 && game_ui != 3)
        return;
    // 极限和模拟出怪功能仅适用于生存模式
    int game_mode = pvz->GameMode();
    if ((game_mode < 1 || game_mode > 15) && spawn_mode != 0)
        return;

    std::array<bool, 33> zombies = {false};
    for (size_t i = 0; i < 20; i++)
        zombies[spawn_type[i]] = (check_zombie[i]->value() == 1);
    int giga_weight = 1000 + 100 * choice_giga_weight->value();
    bool limit_giga = check_giga_limit->value() == 1;

    switch (spawn_mode)
    {
    case 0: // 自然
        zombies[0] = true;
        pvz->InternalSpawn(zombies);
        break;

    case 1: // 极限
    default:
        zombies[0] = true;
        zombies[1] = true;
        pvz->CustomizeSpawn(zombies, limit_giga, false, 1000);
        break;

    case 2: // 模拟
        zombies[0] = true;
        zombies[1] = true;
        pvz->CustomizeSpawn(zombies, limit_giga, true, giga_weight);
        break;
    }

    if (window_spawn->shown() == 1)
        cb_update_details();
}

void Toolkit::cb_music(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_music();
}

void Toolkit::cb_music()
{
    pvz->SetMusic(choice_music->value() + 1);
}

void Toolkit::cb_userdata(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_userdata();
}

void Toolkit::cb_userdata()
{
    auto open = [](std::string p)
    {
        DWORD fa = GetFileAttributesA(p.c_str());
        if ((fa != INVALID_FILE_ATTRIBUTES) && (fa & FILE_ATTRIBUTE_DIRECTORY))
            ShellExecuteA(nullptr, "open", p.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
    };

    auto wopen = [](std::wstring p)
    {
        DWORD fa = GetFileAttributesW(p.c_str());
        if ((fa != INVALID_FILE_ATTRIBUTES) && (fa & FILE_ATTRIBUTE_DIRECTORY))
            ShellExecuteW(nullptr, L"open", p.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
    };

    DWORD dwVersion = 0;
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD dwBuild = 0;
    dwVersion = GetVersion(); // 不加 manifest 的情况下 win8.1 及以上系统只返回 win8
    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));
    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));
    printf("Windows version: %d.%d (%d).\n", dwMajorVersion, dwMinorVersion, dwBuild);

    if (dwMajorVersion < 6)
    {
        // 2000/XP 系统下才会使用 `安装目录/userdata` 做存档位置
        // 需要找到游戏才能定位到游戏安装目录
        std::string exe_path = pvz->GamePath();
        std::string path = exe_path.substr(0, exe_path.find_last_of("\\") + 1) + "userdata";
        open(path);
    }

    TCHAR szPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(nullptr, CSIDL_COMMON_APPDATA, nullptr, 0, szPath)))
    {
        wopen(std::wstring(szPath) + L"\\PopCap Games\\BloomAndDoom\\userdata");
        wopen(std::wstring(szPath) + L"\\PopCap Games\\PlantsVsZombies\\userdata");
        wopen(std::wstring(szPath) + L"\\Steam\\PlantsVsZombies\\userdata");
        wopen(std::wstring(szPath) + L"\\Zoo\\PlantsVsZombies\\userdata");
        wopen(std::wstring(szPath) + L"\\Reflexive\\PlantsVsZombies\\userdata");
    }

    std::wstring path;
    HKEY hKey;
    DWORD ret = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Valve\\Steam", //
                              0, KEY_QUERY_VALUE, &hKey);
    if (ret == ERROR_SUCCESS) // 检查有没有安装 Steam
    {
        DWORD dwType = REG_SZ;
        TCHAR szSteamPath[MAX_PATH];
        DWORD dwSize = MAX_PATH;
        DWORD status = RegQueryValueExW(hKey, L"InstallPath", 0, &dwType, (LPBYTE)&szSteamPath, &dwSize);
        if (status == ERROR_SUCCESS)
            path = std::wstring(szSteamPath) + L"\\userdata"; // 通过注册表找到的安装位置 + userdata
        RegCloseKey(hKey);
    }
    DWORD fa = GetFileAttributesW(path.c_str());
    if (!path.empty() && (fa != INVALID_FILE_ATTRIBUTES) && (fa & FILE_ATTRIBUTE_DIRECTORY))
    {
        WIN32_FIND_DATA ffd;
        HANDLE hf;
        hf = FindFirstFileW((path + L"\\*").c_str(), &ffd);
        if (hf != INVALID_HANDLE_VALUE)
        {
            do
            {
                std::wstring name = ffd.cFileName;
                if (name == L"." || name == L".." || name == L"thumbs.db" || name == L"Thumbs.db")
                    continue;
                if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                    path = path + L"\\" + name + L"\\3590\\remote";
                    wopen(path);
                }
            } while (FindNextFileW(hf, &ffd) != 0);
            FindClose(hf);
        }
    }
}

void Toolkit::cb_no_fog(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_no_fog();
}

void Toolkit::cb_no_fog()
{
    pvz->NoFog(check_no_fog->value());
}

void Toolkit::cb_see_vase(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_see_vase();
}

void Toolkit::cb_see_vase()
{
    pvz->SeeVase(check_see_vase->value());
}

void Toolkit::cb_background(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_background();
}

void Toolkit::cb_background()
{
    pvz->BackgroundRunning(check_background->value());
}

void Toolkit::cb_readonly(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_readonly();
}

void Toolkit::cb_readonly()
{
    pvz->UserdataReadonly(check_readonly->value());
}

void Toolkit::cb_unpack(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_unpack();
}

void Toolkit::cb_unpack()
{
    HANDLE hThread = CreateThread(nullptr, 0, cb_unpack_thread, this, 0, nullptr);

    DWORD dwExitCode = STILL_ACTIVE;
    while (GetExitCodeThread(hThread, &dwExitCode) != 0 //
           && dwExitCode == STILL_ACTIVE)
    {
        Fl::check();
        Sleep(1);
    }

    CloseHandle(hThread);

    button_unpack->take_focus();

    if (this->unpack_result == 0xFFFFFFFF)
    {
        return;
    }
    else if (this->unpack_result == UNPACK_SUCCESS)
    {
        fl_message_title("解包完成");
        fl_message(this->unpack_text.c_str());
    }
    else
    {
        fl_message_title("解包出错");
        fl_alert(this->unpack_text.c_str());
    }
}

DWORD Toolkit::cb_unpack_thread(void *w)
{
    ((Toolkit *)w)->cb_unpack_thread();
    return 0;
}

void Toolkit::cb_unpack_thread()
{
    this->unpack_result = 0xFFFFFFFF;
    this->unpack_text = "";

    std::string src_file = std::string(input_file->value());
    std::string dst_dir = std::string(input_dir->value());
    if (src_file.empty() || dst_dir.empty())
        return;

    Fl::lock();
    button_file->deactivate();
    input_file->deactivate();
    button_unpack->deactivate();
    button_dir->deactivate();
    input_dir->deactivate();
    button_pack->deactivate();
    Fl::unlock();
    Fl::awake();

    int ret = pak->Unpack(src_file, dst_dir);

    Fl::lock();
    button_file->activate();
    input_file->activate();
    button_unpack->activate();
    button_dir->activate();
    input_dir->activate();
    button_pack->activate();
    Fl::unlock();
    Fl::awake();

    this->unpack_result = ret;

    std::vector<std::tuple<int, std::string>> msg = {
        {UNPACK_SRC_NOT_EXIST, "打开源文件失败！"},           //
        {UNPACK_SRC_SIZE_ERROR, "获取源文件大小失败！"},      //
        {UNPACK_SRC_LOAD_ERROR, "读取源文件内容失败！"},      //
        {UNPACK_SRC_HEADER_ERROR, "文件头格式不正确！"},      //
        {UNPACK_SRC_DATA_ERROR, "文件数据已经损坏！"},        //
        {UNPACK_PATH_CREATE_ERROR, "解包路径创建失败！"},     //
        {UNPACK_FILE_CREATE_ERROR, "解包文件创建失败！"},     //
        {UNPACK_FILE_WRITE_ERROR, "解包文件写入失败！"},      //
        {UNPACK_SUCCESS, "解包后的文件夹位于：\n" + dst_dir}, //
    };

    for (size_t i = 0; i < msg.size(); i++)
    {
        auto [result, text] = msg[i];
        if (ret == result)
        {
            this->unpack_text = text;
            break;
        }
    }
}

void Toolkit::cb_pack(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_pack();
}

void Toolkit::cb_pack()
{
    HANDLE hThread = CreateThread(nullptr, 0, cb_pack_thread, this, 0, nullptr);

    DWORD dwExitCode = STILL_ACTIVE;
    while (GetExitCodeThread(hThread, &dwExitCode) != 0 //
           && dwExitCode == STILL_ACTIVE)
    {
        Fl::check();
        Sleep(1);
    }

    CloseHandle(hThread);

    button_pack->take_focus();

    if (this->pack_result == 0xFFFFFFFF)
    {
        return;
    }
    else if (this->pack_result == PACK_SUCCESS)
    {
        fl_message_title("打包完成");
        fl_message(this->pack_text.c_str());
    }
    else
    {
        fl_message_title("打包出错");
        fl_alert(this->pack_text.c_str());
    }
}

DWORD Toolkit::cb_pack_thread(void *w)
{
    ((Toolkit *)w)->cb_pack_thread();
    return 0;
}

void Toolkit::cb_pack_thread()
{
    this->pack_result = 0xFFFFFFFF;
    this->pack_text = "";

    std::string src_dir = std::string(input_dir->value());
    if (src_dir.empty())
        return;
    std::string dst_file = src_dir.substr(0, src_dir.find_last_of("\\")) + "\\" //
                           + "main_" + std::to_string(std::time(nullptr)) + ".pak";

    Fl::lock();
    button_file->deactivate();
    input_file->deactivate();
    button_unpack->deactivate();
    button_dir->deactivate();
    input_dir->deactivate();
    button_pack->deactivate();
    Fl::unlock();
    Fl::awake();

    int ret = pak->Pack(src_dir, dst_file);

    Fl::lock();
    button_file->activate();
    input_file->activate();
    button_unpack->activate();
    button_dir->activate();
    input_dir->activate();
    button_pack->activate();
    Fl::unlock();
    Fl::awake();

    this->pack_result = ret;

    std::vector<std::tuple<int, std::string>> msg = {
        {PACK_SRC_NOT_EXIST, "打开源文件夹失败！"},        //
        {PACK_SRC_EMPTY_ERROR, "源文件夹为空！"},          //
        {PACK_PATH_CREATE_ERROR, "打包路径创建失败！"},    //
        {PACK_FILE_CREATE_ERROR, "打包文件创建失败！"},    //
        {PACK_FILE_WRITE_ERROR, "打包文件写入失败！"},     //
        {PACK_SRC_READ_ERROR, "打包源文件读取失败！"},     //
        {PACK_SUCCESS, "打包后的文件位于：\n" + dst_file}, //
    };

    for (size_t i = 0; i < msg.size(); i++)
    {
        auto [result, text] = msg[i];
        if (ret == result)
        {
            this->pack_text = text;
            break;
        }
    }
}

void Toolkit::cb_debug_mode(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_debug_mode();
}

void Toolkit::cb_debug_mode()
{
    pvz->DebugMode(choice_debug->value());
}

void Toolkit::cb_speed(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_speed();
}

void Toolkit::cb_speed()
{
    int time_ms[] = {
        1,   // 10x
        2,   // 5x
        5,   // 2x
        10,  // 1x
        20,  // 0.5x
        50,  // 0.2x
        100, // 0.1x
    };
    pvz->SetFrameDuration(time_ms[choice_speed->value()]);
}

void Toolkit::cb_limbo_page(Fl_Widget *, void *w)
{
    ((Toolkit *)w)->cb_limbo_page();
}

void Toolkit::cb_limbo_page()
{
    pvz->UnlockLimboPage(check_limbo_page->value());
}

} // namespace Pt
