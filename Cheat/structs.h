#pragma once

struct RepMovement
{
	FVector LinearVelocity;//[Offset: 0x0, Size: 12] // Vehicle move speed
	FVector AngularVelocity;//[Offset: 0xc, Size: 12]
	FVector Location;//[Offset: 0x18, Size: 12]
	FRotator Rotation;//[Offset: 0x24, Size: 12]

};
struct MinimalViewInfo {
	FVector Location;//[Offset: 0x0, Size: 12]
	FVector LocationLocalSpace;//[Offset: 0xc, Size: 12]
	FRotator Rotation;//[Offset: 0x18, Size: 12]
	float FOV;//[Offset: 0x24, Size: 4]

};
struct ObjectName
{
	char data[64];
};
typedef struct
{
	char szCN[0x100];
	char szEN[0x100];
	char szTexture[0x100];
}ITEM_NAME, * PITEM_NAME;
typedef struct _Players
{
	DWORD ptr;
	int status;
	int PoseType;
	float Health;
	float HealthMax;
	float ScopeFov;
	INT Team;
	bool IsBot;
	FVector origin;
	FVector WeaponPose;
	FLOAT Distance;
	std::string weapon;
	std::wstring Nation;
	std::string Name;
	int Ammo;
	int AmmoMax;
	float NearDeathBreath;
	FRotator RelativeRotation;
	float BulletFireSpeed;
	FVector ComponentVelocity;
	float AccessoriesVRecoilFactor;
	float LaunchGravityScale;
	bool bIsWeaponFiring;
	bool bIsGunADS;
	struct _ESPPrediction
	{
		FVector ROOT;
		FVector HEAD;

	}ESPPrediction;
	struct _ESPDirectionLine
	{
		FVector ROOT;
		FVector HEAD;

	}ESPDirectionLine;
	
	struct _AimBones
	{
		FVector ROOT;
		FVector HEAD;
		FVector NECK;
		FVector Chest;
		FVector NerstBone;
	}AimBones;
	struct _Bones
	{
		FVector A0;
		FVector A6;
		FVector A5;
		FVector A4;
		FVector A3;
		FVector A2;
		FVector A1;
		FVector A53;
		FVector A57;
		FVector A32;
		FVector A11;
		FVector A12;
		FVector A33;
		FVector A34;
		FVector A35;
		FVector A13;
		FVector A14;
		FVector A58;
		FVector A59;
		FVector A54;
		FVector A55;

	}Bones;
}A_Players;
typedef struct _Vehicle
{
	DWORD ptr;
	std::string items;
	FVector origin;
	FLOAT HP;
	FLOAT Fuel;
	RepMovement ReplicatedMovement;
	struct _Wheel
	{
		float FirstWheel;
		float SecondWheel;
		float ThirdWheel;
		float FourthWheel;
	}Wheel;
}A_Vehicle;
typedef struct _Loot
{
	DWORD ptr;
	FVector origin;
	std::string items;
}A_Loot;
typedef struct _RedZone
{
	DWORD ptr;
	FVector origin;
	std::string items;
}A_RedZone;
typedef struct _Invetory
{
	DWORD ptr;
	FVector origin;
	std::string items;
	std::vector<std::string> boxItem;
	bool IsAirOpen;
	bool bIsSuperAirdrop;
}A_Invetory;
typedef struct _Grenade
{
	DWORD ptr;
	FVector origin;
	std::string items;
	bool IsTimeOut;
}A_Grenade;


typedef struct _GameState
{
	DWORD ptr;
	int PlayerNum;
	int AlivePlayerNum;
	int AliveTeamNum;
	int PlayerNumPerTeam;
	std::string ElapsedTime;
}A_GameState;

extern MinimalViewInfo CameraCacheEntry;
extern A_Players MyLocalPlayer;
extern A_Vehicle MyLocalVehicle;
extern std::vector<A_Players> EntityList;
extern std::vector<A_Vehicle> EntityVehicle;
extern std::vector<A_RedZone> EntityRedZone;
extern std::vector<A_Loot> EntityLoot;
extern std::vector<A_Invetory> EntityInventory;
extern std::vector<A_Grenade> EntityGrenade;
extern std::vector<DWORD> TempEntityList;
extern std::vector<DWORD> TempEntityList2;
extern std::vector<A_GameState> EntityGameState;
extern bool IsInGame;

extern int TotalEnemy, TotalBots;

