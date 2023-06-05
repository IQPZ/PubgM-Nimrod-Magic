#include "Includes.h"
MinimalViewInfo CameraCacheEntry = MinimalViewInfo();
A_Players MyLocalPlayer = {};
A_Vehicle MyLocalVehicle = {};
std::vector<A_Players> EntityList = {};
std::vector<A_Vehicle> EntityVehicle = {};
std::vector<A_RedZone> EntityRedZone = {};
std::vector<A_Loot> EntityLoot = {};
std::vector<A_Invetory> EntityInventory = {};
std::vector<A_Grenade> EntityGrenade = {};
std::vector<DWORD> TempEntityList = {};
std::vector<DWORD> TempEntityList2 = {};
std::vector<A_GameState> EntityGameState = {};
bool IsInGame = false;

int TotalEnemy = 0, TotalBots = 0;

