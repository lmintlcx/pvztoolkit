
#pragma once

#include <string>
#include <map>
#include <array>
#include <vector>
#include <initializer_list>
#include <stdint.h>

#include "process.h"
#include "code.h"

namespace Pt
{

#define PVZ_NOT_FOUND 0
#define PVZ_OPEN_ERROR 1
#define PVZ_UNSUPPORTED 2

#define PVZ_1_0_0_1051_EN 1001
#define PVZ_1_2_0_1065_EN 1002
#define PVZ_1_2_0_1073_EN 1003
#define PVZ_1_2_0_1096_EN 1004
#define PVZ_1_2_0_1093_DE_ES_FR_IT 1005
#define PVZ_1_1_0_1056_ZH 1006
#define PVZ_1_1_0_1056_JA 1007
#define PVZ_1_1_0_1056_ZH_2012_06 1008
#define PVZ_1_1_0_1056_ZH_2012_07 1009

typedef void (*cb_func)(void *, int);

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
    uintptr_t pvz_base;

    uintptr_t main_object;

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

    uintptr_t lawn_mower;
    uintptr_t lawn_mower_dead;
    uintptr_t lawn_mower_count_max;

    uintptr_t grid_item;
    uintptr_t grid_item_type;
    uintptr_t grid_item_col;
    uintptr_t grid_item_row;
    uintptr_t grid_item_dead;
    uintptr_t grid_item_count_max;

    uintptr_t cursor;
    uintptr_t cursor_grab;

    uintptr_t slot;
    uintptr_t slot_seed_type;
    uintptr_t slot_seed_type_im;

    uintptr_t spawn_preview;

    uintptr_t indirect_base;
    uintptr_t endless_rounds;

    uintptr_t game_paused;
    uintptr_t block_type;
    uintptr_t ice_trail_cd;
    uintptr_t spawn_list;
    uintptr_t spawn_type;
    uintptr_t scene;
    uintptr_t adventure_level;
    uintptr_t sun;
    uintptr_t game_clock;
    uintptr_t debug_mode;

    uintptr_t game_mode;
    uintptr_t game_ui;

    uintptr_t free_planting;

    uintptr_t user_data;
    uintptr_t level;
    uintptr_t money;
    uintptr_t tree_height;
    uintptr_t fertilizer;
    uintptr_t bug_spray;
    uintptr_t chocolate;
    uintptr_t tree_food;

    uintptr_t background_music;

    HACK<uint8_t, 1> safe_thread;

    HACK<uint8_t, 1> auto_collect;
    HACK<uint8_t, 2> zombie_no_falling;

    HACK<uint8_t, 1> fertilizer_unlimited;
    HACK<uint8_t, 1> bug_spray_unlimited;
    std::vector<HACK<uint8_t, 1>> chocolate_unlimited;
    HACK<uint8_t, 1> tree_food_unlimited;

    HACK<uint8_t, 1> planting_anywhere;
    HACK<uint8_t, 1> planting_anywhere_preview;
    HACK<uint8_t, 1> planting_anywhere_iz;
    std::vector<HACK<uint8_t, 1>> fast_belt;
    HACK<uint8_t, 1> lock_shovel;

    HACK<uint8_t, 3> plant_immune_bite;
    HACK<uint8_t, 1> plant_immune_blast;
    HACK<uint8_t, 1> plant_immune_burn;
    HACK<uint8_t, 3> plant_immune_pea;
    HACK<uint8_t, 3> plant_immune_ball;
    HACK<uint8_t, 1> plant_immune_squish;
    HACK<uint8_t, 1> plant_immune_spikeweed;
    HACK<uint8_t, 1> plant_immune_spikerock;
    HACK<uint8_t, 3> plant_immune_zomboss;

    HACK<uint8_t, 3> _plant_immune_bite;
    HACK<uint8_t, 3> _plant_immune_pea;
    HACK<uint8_t, 3> _plant_immune_ball;
    HACK<uint8_t, 1> _plant_immune_spikeweed;

    HACK<uint32_t, 1> zombie_immune_damage;
    HACK<uint8_t, 1> zombie_immune_type1;
    HACK<uint32_t, 1> zombie_immune_type2;
    HACK<uint8_t, 1> zombie_immune_ashes;
    HACK<uint8_t, 1> zombie_immune_cherry;
    HACK<uint8_t, 1> zombie_immune_jalapeno;
    HACK<uint8_t, 1> zombie_immune_chomper;
    HACK<uint8_t, 1> zombie_immune_hypno;
    HACK<uint8_t, 2> zombie_immune_blover;
    HACK<uint8_t, 1> zombie_immune_nearby;
    HACK<uint8_t, 1> zombie_immune_lawnmower;

    HACK<uint32_t, 1> _zombie_immune_damage;
    HACK<uint8_t, 1> _zombie_immune_type1;
    HACK<uint32_t, 1> _zombie_immune_type2;
    HACK<uint8_t, 1> _zombie_immune_ashes;

    HACK<uint8_t, 1> reload_instantly;
    HACK<uint8_t, 1> mushrooms_awake;
    HACK<uint8_t, 1> stop_spawning;
    std::vector<HACK<uint8_t, 1>> stop_zombies;
    HACK<uint8_t, 1> lock_butter;
    HACK<uint8_t, 1> no_crater;
    std::vector<HACK<uint8_t, 1>> no_ice_trail;
    std::vector<HACK<uint8_t, 1>> zombie_not_explode;

    HACK<uint8_t, 1> hack_spawn_preview;

    HACK<uint16_t, 1> no_fog;
    HACK<uint32_t, 1> see_vase;
    HACK<uint16_t, 1> background_running;
    HACK<uint8_t, 1> disable_delete_userdata;
    HACK<uint32_t, 1> disable_save_userdata;
    HACK<uint8_t, 3> unlock_limbo_page;

    uintptr_t call_wisdom_tree;
    uintptr_t call_set_music;

    uintptr_t call_put_plant;
    uintptr_t call_put_plant_imitater;
    uintptr_t call_put_plant_iz_style;
    uintptr_t call_put_zombie;
    uintptr_t call_put_zomboss;
    uintptr_t call_put_grave;
    uintptr_t call_put_ladder;

    uintptr_t call_delete_plant;
    uintptr_t call_delete_lawn_mower;
    uintptr_t call_delete_grid_item;

    uintptr_t call_level_complete;

    uintptr_t call_wakeup_plant;

    uintptr_t call_generate_spawn_list;
    uintptr_t call_clear_spawn_preview;
    uintptr_t call_update_spawn_preview;
};

class PvZ : public Process, public Code
{
public:
    PvZ();
    ~PvZ();

    // 安全地注♂入
    void asm_code_inject();

    // 查找植物大战僵尸, 找到了支持的版本返回真
    bool FindPvZ();

    // 设置查找游戏的回调函数
    void callback(cb_func, void *);

    // 游戏是否正常开启
    // 每次修改前都要检查
    bool GameOn();

    // 是否为年度版
    bool isGOTY();

    // 游戏模式
    int GameMode();

    // 游戏界面
    int GameUI();

    // 游戏场地
    int GetScene();

    // 场地行数
    int GetRowCount();

    // 应用 hack
    template <typename T, size_t size>
    void enable_hack(HACK<T, size>, bool);

    // 应用 hack(s)
    template <typename T, size_t size>
    void enable_hack(std::vector<HACK<T, size>>, bool);

    // 根据(支持的)版本号获取基址数据
    // 每次调用前都要用 GameOn() 检查
    PVZ_DATA data();

protected:
    // 查找结果
    int find_result;

    // 回调函数指针和窗口指针
    cb_func cb_find_result;
    void *window;

    // 不同版本的内存基址数据
    PVZ_DATA data_1_0_0_1051_en;
    PVZ_DATA data_1_2_0_1065_en;
    PVZ_DATA data_1_2_0_1073_en;
    PVZ_DATA data_1_2_0_1096_en;
    PVZ_DATA data_1_2_0_1093_de_es_fr_it;
    PVZ_DATA data_1_1_0_1056_zh;
    PVZ_DATA data_1_1_0_1056_ja;
    PVZ_DATA data_1_1_0_1056_zh_2012_06;
    PVZ_DATA data_1_1_0_1056_zh_2012_07;

    // 将版本和对应数据联系起来的键值对
    std::map<int, PVZ_DATA> ver_map;

public:
    // 以下是修改功能

    // 修改阳光
    void SetSun(int);

    // 修改金钱
    void SetMoney(int);

    // 自动收集
    void AutoCollect(bool);

    // 僵尸不掉钱
    void ZombieNoFalling(bool);

    // 花肥无限
    void FertilizerUnlimited(bool);

    // 杀虫剂无限
    void BugSprayUnlimited(bool);

    // 巧克力无限
    void ChocolateUnlimited(bool);

    // 树肥无限
    void TreeFoodUnlimited(bool);

    // 智慧树高度
    void SetTreeHeight(int);

    // 免费用卡
    void FreePlanting(bool);

    // 自由种植
    void PlantingAnywhere(bool);

    // 连续传送
    void FastBelt(bool);

    // 锁定铲子
    void LockShovel(bool);

    // 获取卡槽某格卡片, 模仿者额外加 48
    int GetSlotSeed(int);

    // 修改卡槽某格卡片
    void SetSlotSeed(int, int, bool);

    // 修改背景音乐
    void SetMusic(int);

    // 无尽模式跳关
    void JumpLevel(int);

    // 生成植物
    void asm_put_plant(int, int, int, bool, bool);
    void PutPlant(int, int, int, bool);

    // 生成僵尸
    void asm_put_zombie(int, int, int);
    void PutZombie(int, int, int);

    // 生成墓碑
    void asm_put_grave(int, int);
    void PutGrave(int, int);

    // 生成梯子和智能搭梯
    void asm_put_ladder(int, int);
    void PutLadder(int, int);
    void AutoLadder(bool);

    // 清除所有植物
    void ClearAllPlants();

    // 杀死所有僵尸
    void KillAllZombies();

    // 去掉所有小推车
    void ClearAllLawnMowers();

    // 清理场地物品
    void ClearGridItems(int);

    // 直接过关
    void DirectWin(bool);

    // 植物无敌
    void PlantInvincible(bool);

    // 植物脆弱
    void PlantWeak(bool);

    // 僵尸无敌
    void ZombieInvincible(bool);

    // 僵尸虚弱
    void ZombieWeak(bool);

    // 立刻装填
    void ReloadInstantly(bool);

    // 蘑菇睡醒
    void MushroomsAwake(bool);

    // 暂停刷怪
    void StopSpawning(bool);

    // 僵尸止步
    void StopZombies(bool);

    // 锁定黄油
    void LockButter(bool);

    // 不留弹坑
    void NoCrater(bool);

    // 不留冰道
    void NoIceTrail(bool);

    // 小丑(辣椒)不爆
    void ZombieNotExplode(bool);

    // 根据出怪种类生成出怪列表
    void generate_spawn_list();

    // 更新选卡界面的出怪预览
    void update_spawn_preview();

    // 获取刷怪列表
    std::array<int, 1000> GetSpawnList();

    // 内置函数生成出怪列表
    void InternalSpawn(std::array<bool, 33>);

    // 自定义填充出怪列表
    void CustomizeSpawn(std::array<bool, 33>);

    // 关卡混乱
    void MixMode(int, int);

    // 清除浓雾
    void NoFog(bool);

    // 罐子透视
    void SeeVase(bool);

    // 后台运行
    void BackgroundRunning(bool);

    // 存档只读
    void UserdataReadonly(bool);

    // 内置调试模式
    void DebugMode(int);

    // 显示隐藏小游戏
    void UnlockLimboPage(bool);
};

template <typename T, size_t size>
void PvZ::enable_hack(HACK<T, size> hack, bool on = true)
{
    if (hack.mem_addr == 0x00000000 || hack.mem_addr == 0xffffffff)
        return;

    if (on)
        WriteMemory(std::array<T, size>(hack.hack_value), {hack.mem_addr});
    else
        WriteMemory(std::array<T, size>(hack.reset_value), {hack.mem_addr});
}

template <typename T, size_t size>
void PvZ::enable_hack(std::vector<HACK<T, size>> hacks, bool on = true)
{
    for (size_t i = 0; i < hacks.size(); i++)
    {
        if (hacks[i].mem_addr == 0x00000000 || hacks[i].mem_addr == 0xffffffff)
            continue;

        if (on)
            WriteMemory(std::array<T, size>(hacks[i].hack_value), {hacks[i].mem_addr});
        else
            WriteMemory(std::array<T, size>(hacks[i].reset_value), {hacks[i].mem_addr});
    }
}

} // namespace Pt
