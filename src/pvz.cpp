
#include "pvz.h"

namespace Pt
{

PvZ::PvZ()
{
    this->cb_find_result = nullptr;
    this->window = nullptr;

    // FindPvZ();
}

PvZ::~PvZ()
{
}

void PvZ::asm_code_inject()
{
    // if (GameOn()) // 其他地方预先判断了, 这里其实不用
    {
        enable_hack(data().block_main_loop, true);
        Sleep(GetFrameDuration() * 2);
        Code::asm_code_inject(this->handle);
        enable_hack(data().block_main_loop, false);
    }
}

void PvZ::callback(cb_func func, void *win)
{
    this->cb_find_result = func;
    this->window = win;
}

bool PvZ::FindPvZ()
{
    this->find_result = PVZ_NOT_FOUND;

    std::vector<std::wstring> pvz_titles = {
        L"Bloom & Doom BETA 0.1.1.1014",          //
        L"Plants vs. Zombies BETA 0.9.9.1029",    //
        L"Plants vs. Zombies",                    //
        L"Plants vs. Zombies 1.2.0.1073",         //
        L"Plants vs. Zombies 1.2.0.1073 RELEASE", //
        L"Plants vs. Zombies GOTY",               //
        L"Pflanzen gegen Zombies 1.2.0.1093",     //
        L"Plantas contra Zombis 1.2.0.1093",      //
        L"Plantes contre Zombies 1.2.0.1093",     //
        L"Piante contro zombi 1.2.0.1093",        //
    };                                            //

    for (size_t i = 0; i < pvz_titles.size() + 1; i++)
    {
        bool found = false;

        // 优先查找已知标题, 兼顾其他改动了标题的版本
        if (i != pvz_titles.size())
            found = OpenByWindow(L"MainWindow", pvz_titles[i].c_str());
        else
            found = OpenByWindow(L"MainWindow", nullptr);

        // 注意分支完整
        if (found)
        {
            if (IsValid())
            {
                auto nth = 0x00400000 + ReadMemory<uintptr_t>({0x00400000 + 0x3c});
                auto lcd = 0x00400000 + ReadMemory<uintptr_t>({nth + 0xc8});
                std::string pdb;
                if (lcd != (0x00400000 + 0))
                    pdb = ReadMemory<std::string>({lcd + ReadMemory<uintptr_t>({lcd}) + 0x18});
                // std::cout << pdb << std::endl;
                auto none = std::string::npos;
                if (pdb.empty()                                                        //
                    || (pdb.find(".pdb") == none)                                      //
                    || (pdb.find("\\Lawn\\") == none && pdb.find("\\lawn\\") == none)) //
                {
                    // 找到的可能是其他宝开游戏
                    this->find_result = PVZ_NOT_FOUND;
                }
                else
                {
                    this->find_result = PVZ_UNSUPPORTED;
                }

                // version detection key value
                std::vector<std::tuple<unsigned int, int>> v = {
                    {0x49359c21, PVZ_BETA_0_1_1_1014_EN},     //
                    {0x499a6204, PVZ_BETA_0_9_9_1029_EN},     //
                    {0x49ecf563, PVZ_1_0_0_1051_EN},          //
                    {0x4a37d6af, PVZ_1_2_0_1065_EN},          //
                    {0x4a5b7963, PVZ_1_0_4_7924_ES},          //
                    {0x4c237519, PVZ_1_0_7_3556_ES},          //
                    {0x4ce4c3d6, PVZ_1_0_7_3467_RU},          //
                    {0x4c2e3453, PVZ_1_2_0_1073_EN},          //
                    {0x4d02b058, PVZ_1_2_0_1096_EN},          //
                    {0x4ca31baa, PVZ_1_2_0_1093_DE_ES_FR_IT}, //
                    {0x4c563de1, PVZ_1_1_0_1056_ZH},          //
                    {0x4cc8e5f8, PVZ_1_1_0_1056_JA},          //
                    {0x4fcd7be2, PVZ_1_1_0_1056_ZH_2012_06},  //
                    {0x5003d437, PVZ_1_1_0_1056_ZH_2012_07},  //
                };

                auto time_compiled = ReadMemory<unsigned int>({nth + 0x08});
                for (size_t j = 0; j < v.size(); j++)
                {
                    auto [time_date_stamp, version_name] = v[j];
                    if (time_compiled == time_date_stamp)
                    {
                        this->find_result = version_name;
                        break;
                    }
                }
            }
            else // 没权限拿不到进程句柄
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
    }

#ifdef _DEBUG
    if (supported)
        WriteMemory<bool>(true, {data().lawn, data().tod_mode});
#endif

    if (cb_find_result != nullptr && this->window != nullptr)
        cb_find_result(this->window, this->find_result);

    return supported;
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

std::string PvZ::GamePath()
{
    return ReadMemory<std::string>({data().path});
}

int PvZ::GameMode()
{
    return ReadMemory<int>({data().lawn, data().game_mode});
}

int PvZ::GameUI()
{
    return ReadMemory<int>({data().lawn, data().game_ui});
}

int PvZ::GetScene()
{
    int scene = -1;

    int ui = GameUI();
    if (ui == 2 || ui == 3)
        scene = ReadMemory<int>({data().lawn, data().board, data().scene});

    return scene;
}

void PvZ::SetScene(int scene, bool reset)
{
    if (scene < 0 || scene > 5)
        return;

    if (!GameOn())
        return;

    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    auto has_lawn_mower = //
        ReadMemory<uint32_t>({data().lawn, data().board, data().lawn_mower_count}) > 0;

    int music_id = scene + 1;
    if (music_id == 6)
        music_id = 2;

    if (GetScene() == scene)
        goto reset_scene;

    if (has_lawn_mower)
        SetLawnMowers(1);

    if (isBETA())
    {
        unsigned int scene_id[6] = {1, 2, 3, 4, 5, 7};
        if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
        {
            WriteMemory<uint8_t, 7>({0xb8, 0x03, 0x00, 0x00, 0x00, 0x90, 0x90}, {0x004103e1});
            WriteMemory<uint32_t>(scene_id[scene], {0x004103e1 + 1});
        }
        else if (this->find_result == PVZ_BETA_0_9_9_1029_EN)
        {
            WriteMemory<uint8_t, 7>({0xb8, 0x03, 0x00, 0x00, 0x00, 0x90, 0x90}, {0x00416e31});
            WriteMemory<uint32_t>(scene_id[scene], {0x00416e31 + 1});
        }
    }

    asm_init();
    asm_mov_exx_dword_ptr(Reg::ESI, data().lawn);
    asm_mov_exx_dword_ptr_exx_add(Reg::ESI, data().board);
    asm_add_list({0xc7, 0x86});  // mov [esi+0000554C],scene
    asm_add_dword(data().scene); //
    asm_add_dword(scene);        //
    if (isBETA())
        asm_mov_exx_exx(Reg::ECX, Reg::ESI);
    asm_call(data().call_pick_background);
    asm_ret();
    asm_code_inject();

    if (isBETA())
    {
        if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
            // movzx eax,byte ptr [eax+00410A50]
            WriteMemory<uint8_t, 7>({0x0f, 0xb6, 0x80, 0x50, 0x0a, 0x41, 0x00}, {0x004103e1});
        else if (this->find_result == PVZ_BETA_0_9_9_1029_EN)
            // movzx eax,byte ptr [eax+00417480]
            WriteMemory<uint8_t, 7>({0x0f, 0xb6, 0x80, 0x80, 0x74, 0x41, 0x00}, {0x00416e31});
    }

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
                                {data().lawn, data().board, data().block_type});
        WriteMemory<int, 6>({1, 1, 1, 1, 1, 0},
                            {data().lawn, data().board, data().row_type});
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
                                {data().lawn, data().board, data().block_type});
        WriteMemory<int, 6>({1, 1, 2, 2, 1, 1},
                            {data().lawn, data().board, data().row_type});
        break;
    }

    if (has_lawn_mower)
        SetLawnMowers(2);

    // 泳池和雾夜仍然保留水波光
    if (scene != 2 && scene != 3)
    {
        unsigned int particle_system_struct_size = 0x2c;
        asm_init();
        auto particle_system_offset = ReadMemory<uintptr_t>({data().lawn, data().anim, data().unnamed, data().particle_system});
        auto particle_system_count_max = ReadMemory<uintptr_t>({data().lawn, data().anim, data().unnamed, data().particle_system_count_max});
        for (size_t i = 0; i < particle_system_count_max; i++)
        {
            auto particle_system_type = ReadMemory<int>({particle_system_offset + data().particle_system_type + particle_system_struct_size * i});
            auto particle_system_dead = ReadMemory<bool>({particle_system_offset + data().particle_system_dead + particle_system_struct_size * i});
            if (!particle_system_dead && particle_system_type == 34)
            {
                uintptr_t addr = particle_system_offset + particle_system_struct_size * i;
                if (isBETA())
                    asm_mov_exx(Reg::ECX, addr);
                else
                    asm_push_dword(addr);
                asm_call(data().call_delete_particle_system);
            }
        }
        asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
        asm_add_list({0xc7, 0x80});                  // mov [eax+00005620],00000000
        asm_add_dword(data().particle_systems_addr); //
        asm_add_dword(0);                            //
        asm_ret();
        asm_code_inject();
    }

    SetMusic(music_id);

reset_scene:
    if (reset)
    {
        asm_init();
        asm_mov_exx_dword_ptr(Reg::EDI, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDI, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDI, data().challenge);
        asm_add_list({0xff, 0x8f}); // dec [edi+0000006c]
        asm_add_dword(data().endless_rounds);
        if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
            asm_push_exx(Reg::EDI);
        if (isBETA())
            asm_mov_exx_exx(Reg::ECX, Reg::EDI);
        asm_call(data().call_puzzle_next_stage_clear);
        asm_ret();
        asm_code_inject();
    }
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

    auto userdata = ReadMemory<uintptr_t>({data().lawn, data().user_data});
    if (userdata == 0) // 还没建立用户
        return;

    auto playthrough = userdata + data().playthrough;

    // Adventure
    int adventure_playthrough = ReadMemory<int>({playthrough});
    if (adventure_playthrough < 2)
        WriteMemory<int>(2, {playthrough});
    playthrough += 1 * sizeof(int);

    ///

    auto mini_games = userdata + data().mini_games;

    // Survival
    // Survival Hard
    WriteMemory<int, 5 + 5>({5, 5, 5, 5, 5, 10, 10, 10, 10, 10}, {mini_games});
    mini_games += (5 + 5) * sizeof(int);

    // Survival Endless
    mini_games += 5 * sizeof(int);

    // Mini-games
    WriteMemory<int, 20>({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {mini_games});
    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
        WriteMemory<int>(5, {mini_games + 18 * sizeof(int)});
    else if (this->find_result == PVZ_BETA_0_9_9_1029_EN)
        WriteMemory<int>(5, {mini_games + 15 * sizeof(int)});
    mini_games += 20 * sizeof(int);

    // Hidden Mini-games
    // Squirrel
    mini_games += (13 + 1) * sizeof(int);

    // Wisdom Tree (Height)
    if (this->find_result != PVZ_BETA_0_1_1_1014_EN)
        mini_games += 1 * sizeof(int);

    // Vasebreaker
    WriteMemory<int, 9>({1, 1, 1, 1, 1, 1, 1, 1, 1}, {mini_games});
    mini_games += 9 * sizeof(int);

    // Vasebreaker Endless
    mini_games += 1 * sizeof(int);

    // I, Zombie
    WriteMemory<int, 9>({1, 1, 1, 1, 1, 1, 1, 1, 1}, {mini_games});
    mini_games += 9 * sizeof(int);

    // I, Zombie Endless
    mini_games += 1 * sizeof(int);

    ////

    auto twiddydinky = userdata + data().twiddydinky;

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

    if (this->find_result != PVZ_BETA_0_1_1_1014_EN)
    {
        // Tree of Wisdom
        WriteMemory<int>(1, {twiddydinky});
        twiddydinky += 1 * sizeof(int);

        // Tree Food
        twiddydinky += 1 * sizeof(int);

        // Wall-nut First Aid
        WriteMemory<int>(1, {twiddydinky});
        twiddydinky += 1 * sizeof(int);
    }

    // 年度版成就
    if (isGOTY())
    {
        auto achievement = userdata + 0x24;
        if (this->find_result == PVZ_1_2_0_1096_EN)
        {
            std::array<bool, 21> values{};
            values.fill(true);
            WriteMemory(values, {achievement});
        }
        else
        {
            std::array<bool, 20> values{};
            values.fill(true);
            WriteMemory(values, {achievement});
        }
    }

    // 刷新主界面
    if (adventure_playthrough == 0 && GameUI() == 1)
    {
        // TODO 只能在主界面
        asm_init();
        asm_push_byte(1); // 显示 Loading
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().game_selector);
        if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
            asm_mov_exx_exx(Reg::ESI, Reg::ECX);
        asm_call(data().call_sync_profile);
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
        int game_clock = ReadMemory<int>({data().lawn, data().board, data().game_clock});
        int frame_to_wait = 75 - ((game_clock + 500) % 75);
        if (ReadMemory<bool>({data().lawn, data().board, data().game_paused}))
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
        asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
        asm_push_exx(Reg::EAX);
        asm_call(data().call_fade_out_level);
        asm_ret();
        asm_code_inject();
    }
    else
    {
        asm_init();
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        asm_call(data().call_fade_out_level);
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
    //     std::cout << ReadMemory<int>({data().lawn, data().board, data().game_clock}) % 75 << std::endl;
    // #endif

    // unsigned int slot_seed_struct_size = 0x50;
    // std::vector<int> seed_types = {40, 41, 42, 43, 44, 45, 46, 47, 8, 48};
    // std::vector<int> seed_types_im = {-1, -1, -1, -1, -1, -1, -1, -1, -1, 8};
    // auto slots_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().slot});
    // for (size_t i = 0; i < 10; i++)
    // {
    //     WriteMemory<int>(seed_types[i], {slots_offset + data().slot_seed_type + i * slot_seed_struct_size});
    //     WriteMemory<int>(seed_types_im[i], {slots_offset + data().slot_seed_type_im + i * slot_seed_struct_size});
    // }
}

void PvZ::UnlockSunLimit(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().unlock_sun_limit, on);
}

void PvZ::SetSun(int sun)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    WriteMemory<int>(sun, {data().lawn, data().board, data().sun});
}

void PvZ::SetMoney(int money)
{
    if (!GameOn())
        return;

    if (ReadMemory<uintptr_t>({data().lawn, data().user_data}) != 0)
        WriteMemory<int>(money, {data().lawn, data().user_data, data().money});
}

void PvZ::AutoCollected(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().auto_collected, on);
}

void PvZ::NotDropLoot(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().not_drop_loot, on);
}

void PvZ::FertilizerUnlimited(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().fertilizer_unlimited, on);
    if (on && ReadMemory<uintptr_t>({data().lawn, data().user_data}) != 0)
        WriteMemory<int>(1000 + 20, {data().lawn, data().user_data, data().twiddydinky + 14 * 4});
}

void PvZ::BugSprayUnlimited(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().bug_spray_unlimited, on);
    if (on && ReadMemory<uintptr_t>({data().lawn, data().user_data}) != 0)
        WriteMemory<int>(1000 + 20, {data().lawn, data().user_data, data().twiddydinky + 15 * 4});
}

void PvZ::ChocolateUnlimited(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().chocolate_unlimited, on);
    if (on && ReadMemory<uintptr_t>({data().lawn, data().user_data}) != 0)
        WriteMemory<int>(1000 + 10, {data().lawn, data().user_data, data().twiddydinky + 26 * 4});
}

void PvZ::TreeFoodUnlimited(bool on)
{
    if (!GameOn())
        return;

    // 早期测试版没有智慧树
    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
        return;

    enable_hack(data().tree_food_unlimited, on);
    if (on && ReadMemory<uintptr_t>({data().lawn, data().user_data}) != 0)
        WriteMemory<int>(1000 + 10, {data().lawn, data().user_data, data().twiddydinky + 28 * 4});
}

void PvZ::SetTreeHeight(int height)
{
    if (!GameOn())
        return;

    if (ReadMemory<uintptr_t>({data().lawn, data().user_data}) == 0)
        return;

    // 早期测试版没有智慧树
    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
        return;

    if (GameMode() == 50) // Zen Garden
    {
        WriteMemory<int>(height - 1, {data().lawn, data().user_data, data().tree_height});

        if (isGOTY())
        {
            if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
            {
                asm_init();
                asm_mov_exx_dword_ptr(Reg::EBX, data().lawn);
                asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().board);
                asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().challenge);
                asm_push_exx(Reg::EBX);
                asm_call(data().call_wisdom_tree);
                asm_ret();
                asm_code_inject();
            }
            else if (this->find_result == PVZ_1_1_0_1056_ZH_2012_06 || this->find_result == PVZ_1_1_0_1056_ZH_2012_07)
            {
                asm_init();
                asm_mov_exx_dword_ptr(Reg::EDI, data().lawn);
                asm_mov_exx_dword_ptr_exx_add(Reg::EDI, data().board);
                asm_mov_exx_dword_ptr_exx_add(Reg::EDI, data().challenge);
                asm_call(data().call_wisdom_tree);
                asm_ret();
                asm_code_inject();
            }
            else
            {
                asm_init();
                asm_mov_exx_dword_ptr(Reg::ESI, data().lawn);
                asm_mov_exx_dword_ptr_exx_add(Reg::ESI, data().board);
                asm_mov_exx_dword_ptr_exx_add(Reg::ESI, data().challenge);
                asm_call(data().call_wisdom_tree);
                asm_ret();
                asm_code_inject();
            }
        }
        else
        {
            if (this->find_result == PVZ_BETA_0_9_9_1029_EN)
            {
                asm_init();
                asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
                asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
                asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().challenge);
                asm_call(data().call_wisdom_tree);
                asm_ret();
                asm_code_inject();
            }
            else
            {
                asm_init();
                asm_mov_exx(Reg::EDI, data().lawn);
                asm_call(data().call_wisdom_tree);
                asm_ret();
                asm_code_inject();
            }
        }
    }
    else
    {
        if (ReadMemory<uintptr_t>({data().lawn, data().user_data}) != 0)
            WriteMemory<int>(height, {data().lawn, data().user_data, data().tree_height});
    }
}

void PvZ::FreePlanting(bool on)
{
    if (!GameOn())
        return;

    WriteMemory<int>(static_cast<int>(on), {data().lawn, data().free_planting});

    if (GameUI() != 3)
        return;

    unsigned int slot_seed_struct_size = 0x50;

    auto slot_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().slot});
    auto slot_count = ReadMemory<uint32_t>({slot_offset + data().slot_count});
    for (size_t i = 0; i < slot_count; i++)
    {
        int slot_seed_cd_total = ReadMemory<int>({slot_offset + data().slot_seed_cd_total + slot_seed_struct_size * i});
        WriteMemory<int>(slot_seed_cd_total, {slot_offset + data().slot_seed_cd_past + slot_seed_struct_size * i});
    }
}

void PvZ::PlacedAnywhere(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().placed_anywhere, on);
    enable_hack(data().placed_anywhere_preview, on);
    enable_hack(data().placed_anywhere_iz, on);
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

    auto cursor_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().cursor});
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
        WriteMemory<int>(level, {data().lawn, data().user_data, data().level});
        WriteMemory<int>(level, {data().lawn, data().board, data().adventure_level});
    }
    WriteMemory<int>(mode, {data().lawn, data().game_mode});
}

void PvZ::EndlessRounds(int level)
{
    if (!GameOn())
        return;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return;

    int mode = GameMode();
    if (mode == 60 || mode == 70 || (mode >= 11 && mode <= 15)) // 仅限无尽模式
    {
        auto indirect_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().challenge});
        WriteMemory<int>(level, {indirect_offset + data().endless_rounds});
    }
}

void PvZ::asm_put_plant(int row, int col, int type, bool imitater, bool iz_style)
{
    if (imitater)
    {
        asm_push_dword(type);
        asm_push_dword(48);
    }
    else
    {
        asm_push_dword(-1);
        asm_push_dword(type);
    }
    if (isBETA())
    {
        asm_push_dword(row);
        asm_push_dword(col);
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
    }
    else
    {
        asm_mov_exx(Reg::EAX, row);
        asm_push_dword(col);
        asm_mov_exx_dword_ptr(Reg::EBP, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EBP, data().board);
        asm_push_exx(Reg::EBP);
    }
    asm_call(data().call_put_plant);

    // 多余的过程是为了让 eax 值为目标植物的地址以供后续的布阵函数使用

    if (imitater)
    {
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().plant);
        asm_mov_exx_dword_ptr(Reg::EBX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().plant_next_pos);
        asm_add_list(0x69, 0xdb, 0x4c, 0x01, 0x00, 0x00); // imul ebx,ebx,plant_struct_size
        asm_add_list(0x01, 0xd9);                         // add ecx,ebx
        asm_push_exx(Reg::ECX);
        asm_mov_exx_exx(Reg::ESI, Reg::EAX);
        if (isBETA())
            asm_mov_exx_exx(Reg::ECX, Reg::EAX);
        asm_call(data().call_put_plant_imitater);
        asm_pop_exx(Reg::ECX);
        asm_mov_exx_exx(Reg::EAX, Reg::ECX);
    }

    if (iz_style)
    {
        asm_mov_exx_exx(Reg::ESI, Reg::EAX);
        asm_push_exx(Reg::EAX);
        asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().challenge);
        if (isBETA())
            asm_mov_exx_exx(Reg::ECX, Reg::EAX);
        asm_call(data().call_put_plant_iz_style);
        asm_mov_exx_exx(Reg::EAX, Reg::ESI);
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
        asm_push_dword(type); // 0x6a byte(type)
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().challenge);
        asm_push_exx(Reg::ECX);
        asm_mov_exx(Reg::EAX, row);
        asm_mov_exx(Reg::ECX, col);
        asm_call(data().call_put_zombie);
    }
    else if (isBETA())
    {
        asm_push_dword(row);
        asm_push_dword(col);
        asm_push_dword(type);
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().challenge);
        asm_call(data().call_put_zombie);
    }
    else
    {
        asm_push_dword(col);
        asm_push_dword(type);
        asm_mov_exx(Reg::EAX, row);
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().challenge);
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
        if (isBETA())
        {
            asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
            asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
            asm_push_dword(0);
            asm_push_dword(0);
            asm_push_dword(25);
        }
        else
        {
            asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
            asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
            asm_push_dword(0);
            asm_push_dword(25);
        }
        asm_call(data().call_put_zombie_in_row);
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
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().challenge);
        asm_push_exx(Reg::ECX);
        asm_mov_exx(Reg::EDI, row);
        asm_mov_exx(Reg::EBX, col);
        asm_call(data().call_put_grave);
    }
    else if (isBETA())
    {
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().challenge);
        asm_push_dword(row);
        asm_push_dword(col);
        asm_call(data().call_put_grave);
    }
    else
    {
        asm_mov_exx_dword_ptr(Reg::EDX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDX, data().board);
        asm_mov_exx_dword_ptr_exx_add(Reg::EDX, data().challenge);
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
    if (isBETA())
    {
        asm_push_dword(row);
        asm_push_dword(col);
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        asm_call(data().call_put_ladder);
    }
    else
    {
        asm_mov_exx(Reg::EDI, row);
        asm_push_dword(col);
        asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
        asm_call(data().call_put_ladder);
    }
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

    ClearGridItems({3}); // 清空所有梯子

    unsigned int plant_struct_size = 0x14c;

    auto plant_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().plant});

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
            auto block_type = ReadMemory<int>({data().lawn, data().board,                                 //
                                               data().block_type + 0x04 * plant_row + 0x18 * plant_col}); //
            if (plant_col != 0 && block_type == 1                                                         //
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
            asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
            asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
            asm_push_exx(Reg::ECX);
        }
        else
        {
            asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
            asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
        }
    }
    else
    {
        if (isBETA())
        {
            asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
            asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        }
        else
        {
            asm_mov_exx_dword_ptr(Reg::EDX, data().lawn);
            asm_mov_exx_dword_ptr_exx_add(Reg::EDX, data().board);
            asm_push_exx(Reg::EDX);
        }
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
        if (isBETA())
            WriteMemory<uint8_t, 7>({0xbd, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90}, {data().call_put_rake_row});
        else
            WriteMemory<uint8_t, 7>({0xba, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90}, {data().call_put_rake_row});
    else
        WriteMemory<uint8_t, 6>({0xbf, 0x00, 0x00, 0x00, 0x00, 0x90}, {data().call_put_rake_row});

    enable_hack(data().rake_unlimited, true);

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

    enable_hack(data().rake_unlimited, false);

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
    //     HACK<uint32_t, 1> test_hack = data().lawn_mower_initialize;
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

    auto lawn_mower_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().lawn_mower_count_max});
    auto lawn_mower_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().lawn_mower});

    if (option == 2)
    {
        enable_hack(data().init_lawn_mowers, true);
        enable_hack(data().lawn_mower_initialize, true);
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
                else if (isBETA())
                    asm_mov_exx(Reg::ECX, addr);
                else
                    asm_mov_exx(Reg::ESI, addr);
                asm_call(data().call_start_lawn_mower);
            }
            else
            {
                if (isBETA())
                    asm_mov_exx(Reg::ECX, addr);
                else
                    asm_mov_exx(Reg::EAX, addr);
                asm_call(data().call_delete_lawn_mower);
            }
        }
    }
    if (option == 2)
    {
        asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
        if (isBETA())
            asm_mov_exx_exx(Reg::ECX, Reg::EAX);
        else
            asm_push_exx(Reg::EAX);
        asm_call(data().call_restore_lawn_mower);
    }
    asm_ret();
    asm_code_inject();

    if (option == 2)
    {
        enable_hack(data().init_lawn_mowers, false);
        enable_hack(data().lawn_mower_initialize, false);
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

    auto plant_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().plant});

    asm_init();
    for (size_t i = 0; i < plant_count_max; i++)
    {
        auto plant_dead = ReadMemory<bool>({plant_offset + data().plant_dead + plant_struct_size * i});
        auto plant_squished = ReadMemory<bool>({plant_offset + data().plant_squished + plant_struct_size * i});
        if (!plant_dead && !plant_squished)
        {
            uint32_t addr = plant_offset + plant_struct_size * i;
            if (isBETA())
                asm_mov_exx(Reg::ECX, addr);
            else
                asm_push_dword(addr);
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
    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
        zombie_struct_size = 0x160;

    auto zombie_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().zombie_count_max});
    auto zombie_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().zombie});
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
    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
        grid_item_struct_size = 0x8c;

    auto grid_item_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().grid_item_count_max});
    auto grid_item_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().grid_item});

    asm_init();
    for (size_t i = 0; i < grid_item_count_max; i++)
    {
        auto grid_item_dead = ReadMemory<bool>({grid_item_offset + data().grid_item_dead + grid_item_struct_size * i});
        auto grid_item_type = ReadMemory<int>({grid_item_offset + data().grid_item_type + grid_item_struct_size * i});
        if (!grid_item_dead && std::find(types.begin(), types.end(), grid_item_type) != types.end())
        {
            int addr = grid_item_offset + grid_item_struct_size * i;
            if (isBETA())
                asm_mov_exx(Reg::ECX, addr);
            else
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

    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
    {
        HACK<uint8_t, 5 + 3> plant_immune_eat = {0x0052130a,                                        //
                                                 {0xbd, 0x00, 0x00, 0x00, 0x00, 0x01, 0x6e, 0x48},  //
                                                 {0xbd, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x6e, 0x48}}; //

        enable_hack(plant_immune_eat, on);
    }
    else if (this->find_result == PVZ_BETA_0_9_9_1029_EN)
    {
        HACK<uint8_t, 5 + 3> plant_immune_eat = {0x0052edf6,                                        //
                                                 {0xbd, 0x00, 0x00, 0x00, 0x00, 0x01, 0x6e, 0x48},  //
                                                 {0xbd, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x6e, 0x48}}; //

        enable_hack(plant_immune_eat, on);
    }

    enable_hack(data().plant_immune_eat, on);
    enable_hack(data().plant_immune_radius, on);
    enable_hack(data().plant_immune_jalapeno, on);
    enable_hack(data().plant_immune_projectile, on);
    enable_hack(data().plant_immune_lob_motion, on);
    enable_hack(data().plant_immune_square, on);
    enable_hack(data().plant_immune_row_area, on);
    enable_hack(data().plant_immune_spike_rock, on);
    enable_hack(data().plant_immune_squish, on);
}

void PvZ::PlantWeak(bool on)
{
    if (!GameOn())
        return;

    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
    {
        HACK<uint8_t, 5 + 3> _plant_immune_eat = {0x0052130a,                                        //
                                                  {0xbd, 0x00, 0x00, 0x00, 0x00, 0x21, 0x6e, 0x48},  //
                                                  {0xbd, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x6e, 0x48}}; //

        enable_hack(_plant_immune_eat, on);
    }
    else if (this->find_result == PVZ_BETA_0_9_9_1029_EN)
    {
        HACK<uint8_t, 5 + 3> _plant_immune_eat = {0x0052edf6,                                        //
                                                  {0xbd, 0x00, 0x00, 0x00, 0x00, 0x21, 0x6e, 0x48},  //
                                                  {0xbd, 0xfc, 0xff, 0xff, 0xff, 0x01, 0x6e, 0x48}}; //

        enable_hack(_plant_immune_eat, on);
    }
    enable_hack(data()._plant_immune_eat, on);
    enable_hack(data()._plant_immune_projectile, on);
    enable_hack(data()._plant_immune_lob_motion, on);
    enable_hack(data()._plant_immune_row_area, on);
}

void PvZ::ZombieInvincible(bool on)
{
    if (!GameOn())
        return;

    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
    {
        HACK<uint8_t, 4 + 6> zombie_immune_body_damage = {0x0051f084,                                                    //
                                                          {0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90},  //
                                                          {0x8b, 0x44, 0x24, 0x18, 0x29, 0x86, 0xcc, 0x00, 0x00, 0x00}}; //

        enable_hack(zombie_immune_body_damage, on);
    }

    enable_hack(data().zombie_immune_body_damage, on);
    enable_hack(data().zombie_immune_helm_damage, on);
    enable_hack(data().zombie_immune_shield_damage, on);
    enable_hack(data().zombie_immune_burn_crumble, on);
    enable_hack(data().zombie_immune_radius, on);
    enable_hack(data().zombie_immune_burn_row, on);
    enable_hack(data().zombie_immune_chomper, on);
    enable_hack(data().zombie_immune_mind_controll, on);
    enable_hack(data().zombie_immune_blow_away, on);
    enable_hack(data().zombie_immune_splash, on);
    enable_hack(data().zombie_immune_lawn_mower, on);
}

void PvZ::ZombieWeak(bool on)
{
    if (!GameOn())
        return;

    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
    {
        HACK<uint8_t, 4 + 6> _zombie_immune_body_damage = {0x0051f084,                                                    //
                                                           {0xc7, 0x86, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},  //
                                                           {0x8b, 0x44, 0x24, 0x18, 0x29, 0x86, 0xcc, 0x00, 0x00, 0x00}}; //

        enable_hack(_zombie_immune_body_damage, on);
    }

    enable_hack(data()._zombie_immune_body_damage, on);
    enable_hack(data()._zombie_immune_helm_damage, on);
    enable_hack(data()._zombie_immune_shield_damage, on);
    enable_hack(data()._zombie_immune_burn_crumble, on);
}

void PvZ::ReloadInstantly(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().reload_instantly, on);
    enable_hack(data().grow_up_quickly, on);
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
        auto plant_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().plant_count_max});
        auto plant_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().plant});
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
                else if (isBETA())
                    asm_mov_exx(Reg::ECX, addr);
                else
                    asm_mov_exx(Reg::EAX, addr);
                asm_push_byte(0);
                asm_call(data().call_set_plant_sleeping);
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
            WriteMemory<int>(1, {data().lawn, data().board, data().ice_trail_cd + i * 4});
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

    auto slot_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().slot});
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

    auto slot_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().slot});
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

    auto plant_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().plant});
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
            auto block_type = ReadMemory<int>({data().lawn, data().board,                 //
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

    auto plant_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().plant});
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

Lineup PvZ::GetLineup()
{
    Lineup lineup;

    if (!GameOn())
        return lineup;
    int ui = GameUI();
    if (ui != 2 && ui != 3)
        return lineup;

    lineup.scene = GetScene();

    unsigned int plant_struct_size = 0x14c;
    unsigned int grid_item_struct_size = 0xec;
    if (this->find_result == PVZ_BETA_0_1_1_1014_EN)
        grid_item_struct_size = 0x8c;

    auto plant_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().plant_count_max});
    auto plant_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().plant});
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
                lineup.base[plant_row * 9 + plant_col] = (plant_type == 16) ? 1 : 2;
                lineup.base_im[plant_row * 9 + plant_col] = plant_imitater ? 1 : 0;
            }
            else if (plant_type == 30) // 南瓜
            {
                lineup.pumpkin[plant_row * 9 + plant_col] = 1;
                lineup.pumpkin_im[plant_row * 9 + plant_col] = plant_imitater ? 1 : 0;
            }
            else if (plant_type == 35) // 咖啡
            {
                lineup.coffee[plant_row * 9 + plant_col] = 1;
                lineup.coffee_im[plant_row * 9 + plant_col] = plant_imitater ? 1 : 0;
            }
            else // 主要植物
            {
                lineup.plant[plant_row * 9 + plant_col] = plant_type + 1;
                lineup.plant_im[plant_row * 9 + plant_col] = plant_imitater ? 1 : 0;
                lineup.plant_awake[plant_row * 9 + plant_col] = plant_asleep ? 0 : 1;
            }
        }
    }

    auto grid_item_count_max = ReadMemory<uint32_t>({data().lawn, data().board, data().grid_item_count_max});
    auto grid_item_offset = ReadMemory<uintptr_t>({data().lawn, data().board, data().grid_item});
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
                lineup.base[grid_item_row * 9 + grid_item_col] = 3;
                lineup.base_im[grid_item_row * 9 + grid_item_col] = 0;
            }
            else if (grid_item_type == 3) // 梯子
            {
                lineup.ladder[grid_item_row * 9 + grid_item_col] = 1;
            }
            else // 钉耙
            {
                lineup.rake_row = grid_item_row + 1;
            }
        }
    }

    return lineup;
}

void PvZ::SetLineup(Lineup lineup)
{
    if (!lineup.OK())
        return;

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

    ClearGridItems({1, 2, 3, 11});
    ClearAllPlants();

    if (GetScene() != lineup.scene)
        SetScene(lineup.scene, true);

    if (lineup.rake_row != 0)
    {
        int r = lineup.rake_row - 1;
        int c = 8 - 1;
        PutRake(r, c);
    }

    asm_init();
    // 睡莲 花盆
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (lineup.base[r * 9 + c] == 1)
                asm_put_plant(r, c, 16, lineup.base_im[r * 9 + c] == 1, is_iz);
            else if (lineup.base[r * 9 + c] == 2)
                asm_put_plant(r, c, 33, lineup.base_im[r * 9 + c] == 1, is_iz);
        }
    }
    // 主要植物
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (lineup.plant[r * 9 + c] == 0)
                continue;

            int plant_type = lineup.plant[r * 9 + c] - 1;
            bool plant_imitater = lineup.plant_im[r * 9 + c] == 1;
            bool plant_asleep = lineup.plant_awake[r * 9 + c] == 0;

            if (plant_type < 0 || plant_type > 47       //
                || plant_type == 16 || plant_type == 33 //
                || plant_type == 30 || plant_type == 35)
                continue;

            asm_put_plant(r, c, plant_type, plant_imitater, is_iz);

            // 蘑菇类植物唤醒
            if ((lineup.scene == 0 || lineup.scene == 2 || lineup.scene == 4) //
                && lineup.may_sleep[plant_type] && !plant_asleep)
            {
                asm_push_exx(Reg::EAX);
                if (isGOTY())
                    asm_mov_exx_exx(Reg::EDI, Reg::EAX);
                else if (isBETA())
                    asm_mov_exx_exx(Reg::ECX, Reg::EAX);
                asm_push_byte(0);
                asm_call(data().call_set_plant_sleeping);
                asm_pop_exx(Reg::EAX);
            }

            // 土豆雷和阳光菇长大
            // mov [eax+54],00000001
            if (plant_type == 4 || plant_type == 9)
            {
                if (isBETA())
                    asm_add_list(0xc7, 0x40, 0x5c);
                else
                    asm_add_list(0xc7, 0x40, 0x54);
                asm_add_dword(1);
            }
        }
    }
    // 南瓜壳
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (lineup.pumpkin[r * 9 + c] == 1)
                asm_put_plant(r, c, 30, lineup.pumpkin_im[r * 9 + c] == 1, is_iz);
        }
    }
    // 咖啡豆
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (lineup.coffee[r * 9 + c] == 1)
                asm_put_plant(r, c, 35, lineup.coffee_im[r * 9 + c] == 1, is_iz);
        }
    }
    // 墓碑
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (lineup.base[r * 9 + c] == 3)
                asm_put_grave(r, c);
        }
    }
    // 梯子
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (lineup.ladder[r * 9 + c] == 1)
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
    asm_init();
    if (this->find_result == PVZ_1_1_0_1056_ZH || this->find_result == PVZ_1_1_0_1056_JA)
    {
        asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
    }
    else
    {
        if (isBETA())
        {
            asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
            asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().board);
        }
        else
        {
            asm_mov_exx_dword_ptr(Reg::EDI, data().lawn);
            asm_mov_exx_dword_ptr_exx_add(Reg::EDI, data().board);
        }
    }
    asm_call(data().call_pick_zombie_waves);
    asm_ret();
    asm_code_inject();
}

// 更新选卡界面的出怪预览
void PvZ::update_spawn_preview()
{
    enable_hack(data().hack_street_zombies, true);
    asm_init();
    asm_mov_exx_dword_ptr(Reg::EBX, data().lawn);
    asm_mov_exx_dword_ptr_exx_add(Reg::EBX, data().board);
    if (isBETA())
        asm_mov_exx_exx(Reg::ECX, Reg::EBX);
    asm_call(data().call_remove_cutscene_zombies);
    asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().board);
    asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().cut_scene);
    if (isBETA())
        asm_mov_exx_exx(Reg::ECX, Reg::EAX);
    else
        asm_push_exx(Reg::EAX);
    asm_call(data().call_place_street_zombies);
    asm_ret();
    asm_code_inject();
    enable_hack(data().hack_street_zombies, false);
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

    zl = ReadMemory<int, 1000>({data().lawn, data().board, data().spawn_list});

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

    WriteMemory(zombies, {data().lawn, data().board, data().spawn_type});

    std::array<int, 2000> zombies_list;
    zombies_list.fill(-1);
    WriteMemory(zombies_list, {data().lawn, data().board, data().spawn_list});

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
    if (this->find_result == PVZ_1_0_0_1051_EN)
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

    WriteMemory(zombies_list, {data().lawn, data().board, data().spawn_list});
    if (ui == 2)
        update_spawn_preview();
}

void PvZ::SetMusic(int id)
{
    if (!GameOn())
        return;

    asm_init();
    if (isBETA())
    {
        asm_push_dword(id);
        asm_mov_exx_dword_ptr(Reg::ECX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::ECX, data().music);
    }
    else
    {
        asm_mov_exx(Reg::EDI, id);
        asm_mov_exx_dword_ptr(Reg::EAX, data().lawn);
        asm_mov_exx_dword_ptr_exx_add(Reg::EAX, data().music);
    }
    asm_call(data().call_play_music);
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

    WriteMemory<int>(mode, {data().lawn, data().board, data().debug_mode});
}

int PvZ::GetFrameDuration()
{
    int time_ms = 10;

    if (!GameOn())
        return time_ms;

    time_ms = ReadMemory<int>({data().lawn, data().frame_duration});

    return time_ms;
}

void PvZ::SetFrameDuration(int time_ms)
{
    if (!GameOn())
        return;

    WriteMemory<int>(time_ms, {data().lawn, data().frame_duration});
}

void PvZ::UnlockLimboPage(bool on)
{
    if (!GameOn())
        return;

    enable_hack(data().unlock_limbo_page, on);
}

} // namespace Pt
