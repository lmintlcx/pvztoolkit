
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

    // Safely inject
    void asm_code_inject();

    // Apply hack
    template <typename T, size_t size>
    void enable_hack(HACK<T, size>, bool);

    // Apply hacks
    template <typename T, size_t size>
    void enable_hack(std::vector<HACK<T, size>>, bool);

    // Set the callback function for finding games
    void callback(cb_func, void *);

    // Search for Plants vs. Zombies, found a supported version and return true
    bool FindPvZ();

    // Whether the game is started normally
     //Check before each modification
     bool GameOn();

     // game path
     std::string GamePath();

     // game mode
     int GameMode();

     // game interface
     int GameUI();

     // game venue
     int GetScene();
     void SetScene(int, bool);

     //The number of rows in the field
     int GetRowCount();

   protected:
     //Callback function pointer and window pointer
     cb_func cb_find_result;
     void *window;

   public:
     //The following is the modification function

     // Unlock the game
     void UnlockTrophy();

     // Pass directly
     void DirectWin();

     //Remove the upper limit
     void UnlockSunLimit(bool);

     //Modify sunshine
     void SetSun(int);

     //Modify gold coins
     void SetMoney(int);

     // Automatically collect
     void AutoCollected(bool);

     // No loot drops
     void NotDropLoot(bool);

     // Unlimited flower fertilizer
     void FertilizerUnlimited(bool);

     // Unlimited pesticides
     void BugSprayUnlimited(bool);

     // Unlimited chocolate
     void ChocolateUnlimited(bool);

     //Unlimited tree fertilizer
     void TreeFoodUnlimited(bool);

     // Wisdom tree height
     void SetTreeHeight(int);

     // Free card use
     void FreePlanting(bool);

     //Place it randomly
     void PlacedAnywhere(bool);

     // close transmission
     void FastBelt(bool);

     // Continuous shovel
     void LockShovel(bool);

     // Chaos level
     void MixMode(int, int);

     // Endless rounds
     void EndlessRounds(int);

     // Generate plants
    void asm_put_plant(int, int, int, bool, bool);
    void PutPlant(int, int, int, bool);

    // Generate zombies
     void asm_put_zombie(int, int, int);
     void PutZombie(int, int, int);

     // Generate tombstone
     void asm_put_grave(int, int);
     void PutGrave(int, int);

     // Generate ladders and smart ladders
     void asm_put_ladder(int, int);
     void PutLadder(int, int);
     void AutoLadder(bool);

     // Generate rake
     void asm_put_rake(int, int);
     void PutRake(int, int);

     // Start/delete/restore the cart
     void SetLawnMowers(int);

     // Clear all plants
     void ClearAllPlants();

     // kill all zombies
     void KillAllZombies();

     // Clean up site items
     void ClearGridItems(std::vector<int>);

     // Plants are invincible
     void PlantInvincible(bool);

     // plants are fragile
     void PlantWeak(bool);

     // Zombies are invincible
     void ZombieInvincible(bool);

     // Zombies are weak
     void ZombieWeak(bool);

     // Load immediately
     void ReloadInstantly(bool);

     // Mushroom wakes up
     void MushroomsAwake(bool);

     // Pause spawning monsters
     void StopSpawning(bool);

     // stalled
     void StopZombies(bool);

     // Lock butter
     void LockButter(bool);

     // Leave no craters
     void NoCrater(bool);

     // No grinding ice road
     void NoIceTrail(bool);

     // Clown (pepper) does not explode
     void ZombieNotExplode(bool);

     // Get a card from a certain slot in the card slot, and the imitator will get an additional 48
     int GetSlotSeed(int);

     // Modify a certain card in the card slot
    void SetSlotSeed(int, int, bool);

    // Plant water lilies in waterways
     void LilyPadOnPool(int, int);

     //Place flower pots on the roof
     void FlowerPotOnRoof(int, int);

     // Window screenshot
     void Screenshot();

     // get code
     Lineup GetLineup();

     // Arrange the formation
     void SetLineup(Lineup);

     // Generate a monster list based on the type of monsters
     void generate_spawn_list();

     // Update the monster preview on the card selection interface
     void update_spawn_preview();

     // Get the monster spawn list
     std::array<int, 1000> GetSpawnList();

     //Modify the monster spawn list
     void SetSpawnList(std::array<int, 1000>);

     //Built-in function generates a strange list
     void InternalSpawn(std::array<bool, 33>);

     // Customize the filled monster list
     void CustomizeSpawn(std::array<bool, 33>, bool, bool, int);

     //Modify background music
     void SetMusic(int);

     // Clear dense fog
     void NoFog(bool);

     // jar perspective
     void SeeVase(bool);

     // Background process
     void BackgroundRunning(bool);

     //Archive read only
     void UserdataReadonly(bool);

     // Built-in debugging mode
     void DebugMode(int);

     // Frame generation time
     int GetFrameDuration();
     void SetFrameDuration(int);

     //Show hidden levels
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
