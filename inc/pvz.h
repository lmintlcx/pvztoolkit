
#pragma once

#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <cassert>
#include <random>
#include <chrono>

#include <Windows.h>

#include "process.h"
#include "code.h"
#include "data.h"
#include "lineup.h"

namespace Pt
{

typedef void (*cb_func)(void *, int);

class PvZ : public Process, public Code, public Data
{
  public:
    PvZ();
    ~PvZ();

    // 安全地注入
    void asm_code_inject();

    // 应用 hack
    template <typename T, size_t size>
    void enable_hack(HACK<T, size>, bool);

    // 应用 hacks
    template <typename T, size_t size>
    void enable_hack(std::vector<HACK<T, size>>, bool);

    // 设置查找游戏的回调函数
    void callback(cb_func, void *);

    // 查找植物大战僵尸, 找到了支持的版本返回真
    bool FindPvZ();

    // 游戏是否正常开启
    // 每次修改前都要检查
    bool GameOn();

    // 游戏路径
    std::string GamePath();

    // 游戏模式
    int GameMode();

    // 游戏界面
    int GameUI();

    // 游戏场地
    int GetScene();
    void SetScene(int, bool);

    // 场地行数
    int GetRowCount();

  protected:
    // 回调函数指针和窗口指针
    cb_func cb_find_result;
    void *window;

  public:
    // 以下是修改功能

    // 解锁游戏
    void UnlockTrophy();

    // 直接过关
    void DirectWin();

    // 去除上限
    void UnlockSunLimit(bool);

    // 修改阳光
    void SetSun(int);

    // 修改金币
    void SetMoney(int);

    // 自动收集
    void AutoCollected(bool);

    // 不掉战利品
    void NotDropLoot(bool);

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

    // 随意放置
    void PlacedAnywhere(bool);

    // 紧密传送
    void FastBelt(bool);

    // 连续铲子
    void LockShovel(bool);

    // 混乱关卡
    void MixMode(int, int);

    // 无尽轮数
    void EndlessRounds(int);

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

    // 生成钉耙
    void asm_put_rake(int, int);
    void PutRake(int, int);

    // 启动/删除/恢复小推车
    void SetLawnMowers(int);

    // 清除所有植物
    void ClearAllPlants();

    // 杀死所有僵尸
    void KillAllZombies();

    // 清理场地物品
    void ClearGridItems(std::vector<int>);

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

    // 停滞不前
    void StopZombies(bool);

    // 锁定黄油
    void LockButter(bool);

    // 不留弹坑
    void NoCrater(bool);

    // 不磨冰道
    void NoIceTrail(bool);

    // 小丑(辣椒)不爆
    void ZombieNotExplode(bool);

    // 获取卡槽某格卡片, 模仿者额外加 48
    int GetSlotSeed(int);

    // 修改卡槽某格卡片
    void SetSlotSeed(int, int, bool);

    // 水路种睡莲
    void LilyPadOnPool(int, int);

    // 屋顶放花盆
    void FlowerPotOnRoof(int, int);

    // 窗口截图
    void Screenshot();

    // 获取代码
    Lineup GetLineup();

    // 布置阵型
    void SetLineup(Lineup);

    // 根据出怪种类生成出怪列表
    void generate_spawn_list();

    // 更新选卡界面的出怪预览
    void update_spawn_preview();

    // 获取刷怪列表
    std::array<int, 1000> GetSpawnList();

    // 修改刷怪列表
    void SetSpawnList(std::array<int, 1000>);

    // 内置函数生成出怪列表
    void InternalSpawn(std::array<bool, 33>);

    // 自定义填充出怪列表
    void CustomizeSpawn(std::array<bool, 33>, bool, bool, int);

    // 修改背景音乐
    void SetMusic(int);

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

    // 帧生成时间
    int GetFrameDuration();
    void SetFrameDuration(int);

    // 显示隐藏关卡
    void UnlockLimboPage(bool);
};

template <typename T, size_t size>
void PvZ::enable_hack(HACK<T, size> hack, bool on)
{
    if (hack.mem_addr == 0x00000000 || hack.mem_addr == 0xffffffff)
        return;

    if (on)
        WriteMemory(std::array<T, size>(hack.hack_value), {hack.mem_addr});
    else
        WriteMemory(std::array<T, size>(hack.reset_value), {hack.mem_addr});
}

template <typename T, size_t size>
void PvZ::enable_hack(std::vector<HACK<T, size>> hacks, bool on)
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
