#include "Includes.h"
INT MagicBulletHook = 0;
namespace libs
{
    DWORD UE4 = 0;
}
namespace offsets
{
    DWORD LibUe4 = 0xe0c3b60;

    DWORD Gname = 0x87590C4;
    DWORD Gworld = 0x8a9d624;

    DWORD PersistentLevel = 0x20;
    DWORD NetDriver = 0x24;
    DWORD ServerConnection = 0x60;
    DWORD PlayerController = 0x20;
    DWORD AcknowledgedPawn = 0x360;
    DWORD PlayerCameraManager = 0x370;
    DWORD CameraCache = 0x370;
    DWORD Mesh = 0x34c;
    DWORD MinLOD = 0x634;
    DWORD RootComponent = 0x150;
    DWORD WeaponManagerComponent = 0x1930;
    DWORD CurrentWeaponReplicated = 0x3fc;
    DWORD RelativeLocation = 0x150; // Player location
    DWORD bDead = 0x1231;
    DWORD Nation = 0x68c;
    DWORD PlayerName = 0x680;
    DWORD TeamID = 0x6b4;
    DWORD CurrentStates = 0xb18;
    DWORD Health = 0x9d0;
    DWORD HealthMax = 0x9d4;
    DWORD bIsAI = 0x734; //isbot
    DWORD VehicleCommon = 0x75c;
    DWORD HP = 0x1e4;
    DWORD HPMax = 0x1e0;
    DWORD FuelMax = 0x200;
    DWORD Fuel = 0x204;
    DWORD PoseState = 0xfe4;
    DWORD ScopeFov = 0x130c;
    DWORD PickUpDataList = 0x6a0;
    DWORD CurBulletNumInClip = 0xb58;
    DWORD CurMaxBulletNumInOneClip = 0xb6c;
    DWORD NearDeathBreath = 0x1234; // player Health Knocked 
    DWORD RelativeRotation = 0x124;
    DWORD ComponentVelocity = 0x1a0;
    DWORD BulletRange = 0x548;
    DWORD ShootWeaponEntityComp = 0xc70;
    DWORD AccessoriesVRecoilFactor = 0x8c8;
    DWORD ReplicatedMovement = 0x78;
    DWORD bIsWeaponFiring = 0xfd4;
    DWORD bIsGunADS = 0xb9d;
    DWORD IsTimeOut = 0x500;
    DWORD bIsAirOpen = 0x540;
    DWORD bIsSuperAirdrop = 0x3e0;
    DWORD bAutoDestroyWhenFinished = 0x130;
    DWORD WheelsCurrentHP = 0x1f0;
    DWORD LaunchGravityScale = 0x2f8;
    DWORD GameState = 0x138;
    DWORD GameModeClass = 0x308;

    DWORD PlayerNum = 0x548;
    DWORD AlivePlayerNum = 0x7e4;
    DWORD AliveTeamNum = 0x7e8;
    DWORD PlayerNumPerTeam = 0xaa0;
    DWORD ElapsedTime = 0x348;

}


