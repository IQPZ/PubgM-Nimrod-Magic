#pragma once
extern INT MagicBulletHook;

namespace libs
{

	extern DWORD UE4;
}
namespace offsets
{
	extern DWORD LibUe4;
	extern DWORD Gname;
	extern DWORD Gworld;

	extern DWORD PersistentLevel;
	extern DWORD NetDriver;
	extern DWORD ServerConnection;
	extern DWORD PlayerController;
	extern DWORD AcknowledgedPawn;
	extern DWORD PlayerCameraManager;
	extern DWORD CameraCache;
	extern DWORD Mesh;
	extern DWORD MinLOD;
	extern DWORD RootComponent;
	extern DWORD WeaponManagerComponent;
	extern DWORD CurrentWeaponReplicated;
	extern DWORD RelativeLocation; // Player location
	extern DWORD bDead;
	extern DWORD Nation;
	extern DWORD PlayerName;
	extern DWORD TeamID;
	extern DWORD CurrentStates;
	extern DWORD Health;
	extern DWORD HealthMax;
	extern DWORD bIsAI; //isbot
	extern DWORD VehicleCommon;
	extern DWORD HP;
	extern DWORD HPMax;
	extern DWORD FuelMax;
	extern DWORD Fuel;
	extern DWORD PoseState;
	extern DWORD ScopeFov;
	extern DWORD PickUpDataList;
	extern DWORD CurBulletNumInClip;
	extern DWORD CurMaxBulletNumInOneClip;
	extern DWORD NearDeathBreath; // player Health Knocked 
	extern DWORD RelativeRotation;
	extern DWORD ComponentVelocity;
	extern DWORD BulletRange;
	extern DWORD ShootWeaponEntityComp;
	extern DWORD AccessoriesVRecoilFactor;
	extern DWORD ReplicatedMovement;
	extern DWORD bIsWeaponFiring;
	extern DWORD bIsGunADS;
	extern DWORD IsTimeOut;
	extern DWORD bIsAirOpen;
	extern DWORD bIsSuperAirdrop;
	extern DWORD bAutoDestroyWhenFinished;
	extern DWORD WheelsCurrentHP;
	extern DWORD LaunchGravityScale;
	extern DWORD GameState;
	extern DWORD GameModeClass;
	extern DWORD PlayerNum;
	extern DWORD AlivePlayerNum;
	extern DWORD AliveTeamNum;
	extern DWORD PlayerNumPerTeam;
	extern DWORD ElapsedTime;

}
enum class ESTEPoseState : uint8_t
{
	ESTEPoseState__Stand = 0,
	ESTEPoseState__Crouch = 1,
	ESTEPoseState__Prone = 2,
	ESTEPoseState__Sprint = 3,
	ESTEPoseState__CrouchSprint = 4,
	ESTEPoseState__Crawl = 5,
	ESTEPoseState__Swim = 6,
	ESTEPoseState__SwimSprint = 7,
	ESTEPoseState__Dying = 8,
	ESTEPoseState__DyingBeCarried = 9,
	ESTEPoseState__ESTEPoseState_MAX = 10
};

enum BONES
{
	BONE_ROOT = 0,
	BONE_HEAD = 6,
	BONE_NECK = 5,
	BONE_SPINE_01 = 1,
	BONE_SPINE_02 = 2,
	BONE_SPINE_03 = 3,
	BONE_LEFTSHOULDER = 12,
	BONE_RIGHTSHOULDER = 33,
	BONE_LEFTELBOWROLL = 13,
	BONE_RIGHTELBOWROLL = 34,
	BONE_LEFTHAND = 64,
	BONE_RIGHTHAND = 63,
	BONE_LEFTKNEEROLL = 54,
	BONE_RIGHTKNEEROLL = 58,
	BONE_LEFTFOOT = 55,
	BONE_RIGHTFOOT = 59
};


