#pragma once
static int S_width = 1920, S_height = 1080;
class Player {
private:

public:
	Player() {}
	Player(A_Players _Actor) {
			this->ptr = _Actor.ptr;
			this->Ammo = _Actor.Ammo;
			this->AmmoMax = _Actor.AmmoMax;
			this->weapon = _Actor.weapon;
			this->Team = _Actor.Team;
			this->Health = _Actor.Health;
			this->HealthMax = _Actor.HealthMax;
			this->IsBot = _Actor.IsBot;
			this->origin = _Actor.origin;
			this->WeaponPose = _Actor.WeaponPose;
			this->status = _Actor.status;
			this->PoseType = _Actor.PoseType;
			this->ScopeFov = _Actor.ScopeFov;
			this->Nation = _Actor.Nation;
			this->Name = _Actor.Name;
			this->NearDeathBreath = _Actor.NearDeathBreath;
			this->RelativeRotation = _Actor.RelativeRotation;
			this->BulletFireSpeed = _Actor.BulletFireSpeed;
			this->ComponentVelocity = _Actor.ComponentVelocity;
			this->AccessoriesVRecoilFactor = _Actor.AccessoriesVRecoilFactor;
			this->LaunchGravityScale = _Actor.LaunchGravityScale;

			this->bIsWeaponFiring = _Actor.bIsWeaponFiring;
			this->bIsGunADS = _Actor.bIsGunADS;

			this->ESPPrediction.ROOT = _Actor.ESPPrediction.ROOT;
			this->ESPPrediction.HEAD = _Actor.ESPPrediction.HEAD;

			this->ESPDirectionLine.ROOT = _Actor.ESPDirectionLine.ROOT;
			this->ESPDirectionLine.HEAD = _Actor.ESPDirectionLine.HEAD;

			this->AimBones.ROOT = _Actor.AimBones.ROOT;
			this->AimBones.HEAD = _Actor.AimBones.HEAD;
			this->AimBones.NECK = _Actor.AimBones.NECK;
			this->AimBones.Chest = _Actor.AimBones.Chest;
			this->AimBones.NerstBone = _Actor.AimBones.NerstBone;

			
			this->Bones.A0 = _Actor.Bones.A0;
			this->Bones.A6 = _Actor.Bones.A6;
			this->Bones.A5 = _Actor.Bones.A5;
			this->Bones.A4 = _Actor.Bones.A4;
			this->Bones.A3 = _Actor.Bones.A3;
			this->Bones.A2 = _Actor.Bones.A2;
			this->Bones.A1 = _Actor.Bones.A1;
			this->Bones.A53 = _Actor.Bones.A53;
			this->Bones.A57 = _Actor.Bones.A57;
			this->Bones.A32 = _Actor.Bones.A32;
			this->Bones.A11 = _Actor.Bones.A11;
			this->Bones.A12 = _Actor.Bones.A12;
			this->Bones.A33 = _Actor.Bones.A33;
			this->Bones.A34 = _Actor.Bones.A34;
			this->Bones.A35 = _Actor.Bones.A35;
			this->Bones.A13 = _Actor.Bones.A13;
			this->Bones.A14 = _Actor.Bones.A14;
			this->Bones.A58 = _Actor.Bones.A58;
			this->Bones.A59 = _Actor.Bones.A59;
			this->Bones.A54 = _Actor.Bones.A54;
			this->Bones.A55 = _Actor.Bones.A55;
		
	}
	DWORD ptr = 0;
	float NearDeathBreath = 0;
	int Ammo = 0;
	int AmmoMax = 0;
	int status = 0;
	int PoseType = 0;
	float Health = 0;
	float HealthMax = 0;
	float ScopeFov = 0.f;
	bool bIsWeaponFiring = false;
	INT Team = 0;
	bool IsBot = false;
	FVector origin = FVector();
	FVector WeaponPose = FVector();

	FLOAT Distance = 0;
	std::string weapon = "";
	std::wstring Nation = L"";
	std::string Name = "";
	float BulletFireSpeed = 0;
	float AccessoriesVRecoilFactor = 0;
	float LaunchGravityScale = 0;
	bool bIsGunADS = false;
	FVector ComponentVelocity = FVector();
	FRotator RelativeRotation = FRotator();
	struct _ESPPrediction
	{
		FVector ROOT = FVector();
		FVector HEAD = FVector();
	}ESPPrediction;
	struct _ESPDirectionLine
	{
		FVector ROOT = FVector();
		FVector HEAD = FVector();

	}ESPDirectionLine;

	struct _AimBones
	{
		FVector ROOT = FVector();
		FVector HEAD = FVector();
		FVector NECK = FVector();
		FVector Chest = FVector();
		FVector NerstBone = FVector();

	}AimBones;

	struct _Bones
	{
		FVector A0 = FVector();
		FVector A6 = FVector();
		FVector A5 = FVector();
		FVector A4 = FVector();
		FVector A3 = FVector();
		FVector A2 = FVector();
		FVector A1 = FVector();
		FVector A53 = FVector();
		FVector A57 = FVector();
		FVector A32 = FVector();
		FVector A11 = FVector();
		FVector A12 = FVector();
		FVector A33 = FVector();
		FVector A34 = FVector();
		FVector A35 = FVector();
		FVector A13 = FVector();
		FVector A14 = FVector();
		FVector A58 = FVector();
		FVector A59 = FVector();
		FVector A54 = FVector();
		FVector A55 = FVector();

	}Bones;

	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->Team != 0) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};
class Vehicle {
private:

public:
	Vehicle() {}
	Vehicle(A_Vehicle _Actor) {
			this->ptr = _Actor.ptr;
			this->items = _Actor.items;
			this->origin = _Actor.origin;
			this->HP = _Actor.HP;
			this->Fuel = _Actor.Fuel;
			this->ReplicatedMovement = _Actor.ReplicatedMovement;

			this->Wheel.FirstWheel = _Actor.Wheel.FirstWheel;
			this->Wheel.SecondWheel = _Actor.Wheel.SecondWheel;
			this->Wheel.ThirdWheel = _Actor.Wheel.ThirdWheel;
			this->Wheel.FourthWheel = _Actor.Wheel.FourthWheel;

	}
	DWORD ptr =0;
	std::string items = "";
	FVector origin = FVector();
	FLOAT Distance = 0;
	FLOAT HP = 0;
	FLOAT Fuel = 0;
	RepMovement ReplicatedMovement = {};
	struct _Wheel
	{
		float FirstWheel;
		float SecondWheel;
		float ThirdWheel;
		float FourthWheel;
	}Wheel;
	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->HP > NULL) &&
			(this->Fuel > NULL) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};
class RedZone {
private:

public:
	RedZone() {}
	RedZone(A_RedZone _Actor) {
			this->ptr = _Actor.ptr;
			this->items = _Actor.items;
			this->origin = _Actor.origin;
		
	}
	DWORD ptr = 0;
	FVector origin = FVector();
	FLOAT Distance = 0;
	std::string items = "";
	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};
class Loot {
private:

public:
	Loot() {}
	Loot(A_Loot _Actor) {
			this->ptr = _Actor.ptr;
			this->items = _Actor.items;
			this->origin = _Actor.origin;
		
	}
	DWORD ptr = 0;
	FVector origin = FVector();
	FLOAT Distance = 0;
	std::string items = "";
	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};
class Inventory {
private:
public:
	Inventory() {}
	Inventory(A_Invetory _Actor) {
			this->ptr = _Actor.ptr;
			this->items = _Actor.items;
			this->origin = _Actor.origin;
			this->boxItem = _Actor.boxItem;		
			this->IsAirOpen = _Actor.IsAirOpen;
			this->bIsSuperAirdrop = _Actor.bIsSuperAirdrop;
	}
	DWORD ptr = 0;
	FVector origin = FVector();
	FLOAT Distance = 0;
	std::string items = "";
	bool IsAirOpen = false;
	bool bIsSuperAirdrop = false;

	std::vector<std::string> boxItem = std::vector<std::string>();

	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};
class Grenade {
private:
public:
	Grenade() {}
	Grenade(A_Grenade _Actor) {
			this->ptr = _Actor.ptr;
			this->items = _Actor.items;
			this->origin = _Actor.origin;	
			this->IsTimeOut = _Actor.IsTimeOut;

	}
	DWORD ptr = 0;
	FVector origin = FVector();
	FLOAT Distance = 0;
	std::string items = "";
	bool IsTimeOut = false;

	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->IsTimeOut == false) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};
class GameState {
private:

public:
	GameState() {}
	GameState(A_GameState _Actor) {
		this->ptr = _Actor.ptr;
		this->PlayerNum = _Actor.PlayerNum;
		this->AlivePlayerNum = _Actor.AlivePlayerNum;
		this->AliveTeamNum = _Actor.AliveTeamNum;
		this->PlayerNumPerTeam = _Actor.PlayerNumPerTeam;
		this->ElapsedTime = _Actor.ElapsedTime;

	}
	DWORD ptr = 0;
	int PlayerNum;
	int AlivePlayerNum;
	int AliveTeamNum;
	int PlayerNumPerTeam;
	std::string ElapsedTime;

	BOOL IsValid() {
		if ((this->ptr != NULL)) 
			 return true;
		return false;
	}
};

class Manager {
private:
public:
	Player LocalPlayer = {};
	Vehicle LocalVehicles = {};
	std::vector<Player> Players = {};
	std::vector<Vehicle> Vehicles = {};
	std::vector<RedZone> RedZones = {};
	std::vector<Loot> Loots = {};
	std::vector<Inventory> Inventorys = {};
	std::vector<Grenade> Grenades = {};

	Player PlayersClosetCrossDistance = {};
	Vehicle VehiclesClosetCrossDistance = {};
	Player PlayersCenterCrossDistance = {};
	Vehicle VehiclesCenterCrossDistance = {};
	Player ClosestVisibleEnemy = {};

	Manager(int width, int height) {
		S_width = width;
		S_height = height;
		TotalEnemy = 0;
		TotalBots = 0;
	

		this->LocalPlayer = Player(MyLocalPlayer);
		this->LocalVehicles = Vehicle(MyLocalVehicle);

		for (size_t i = 0; i < EntityList.size(); i++) {
			Player player(EntityList[i]);

				if (player.IsValid() && player.ptr != this->LocalPlayer.ptr) {
					if (player.IsBot == true && player.Team != LocalPlayer.Team)
					{
						TotalBots++;
					}
					if (player.IsBot == false && player.Team != LocalPlayer.Team)
					{
						TotalEnemy++;
					}
					player.Distance = CameraCacheEntry.Location.Distance(player.origin) / 100.f;
					this->Players.push_back(player);
				}
			
		}

		for (size_t i = 0; i < EntityVehicle.size(); i++) {
			Vehicle vehicle(EntityVehicle[i]);
				if (vehicle.IsValid() && vehicle.ptr != this->LocalVehicles.ptr) {
					vehicle.Distance = CameraCacheEntry.Location.Distance(vehicle.origin) / 100.f;
					this->Vehicles.push_back(vehicle);
				}
			
		}

		for (size_t i = 0; i < EntityRedZone.size(); i++) {
			RedZone redzone(EntityRedZone[i]);
				if (redzone.IsValid()) {
					redzone.Distance = CameraCacheEntry.Location.Distance(redzone.origin) / 100.f;
					this->RedZones.push_back(redzone);
				}
			
		}

		for (size_t i = 0; i < EntityLoot.size(); i++) {
			Loot loot(EntityLoot[i]);
				if (loot.IsValid() && loot.ptr != this->LocalPlayer.ptr) {
					loot.Distance = CameraCacheEntry.Location.Distance(loot.origin) / 100.f;
					this->Loots.push_back(loot);
				}
			
		}

		for (size_t i = 0; i < EntityInventory.size(); i++) {
			Inventory inventory(EntityInventory[i]);

				if (inventory.IsValid() && inventory.ptr != this->LocalPlayer.ptr) {
					inventory.Distance = CameraCacheEntry.Location.Distance(inventory.origin) / 100.f;
					this->Inventorys.push_back(inventory);
				}
			
		}

		for (size_t i = 0; i < EntityGrenade.size(); i++) {
			Grenade grenade(EntityGrenade[i]);
				if (grenade.IsValid() && grenade.ptr != this->LocalPlayer.ptr) {
					grenade.Distance = CameraCacheEntry.Location.Distance(grenade.origin) / 100.f;
					this->Grenades.push_back(grenade);
				}
			
		}


		float MaxPlayersClosetCrossDistance = FLT_MAX;
		for (size_t i = 0; i < this->Players.size(); i++) {
			if (this->LocalPlayer.Health > 0 && this->Players[i].Team != this->LocalPlayer.Team && this->Players[i].Distance < Share::distance) {
				FVector Pos = FVector();
				if (WorldToScreen(this->Players[i].origin, Pos)) {
					float Radius = (Share::AimFov * 8);
					if (Pos.X <= ((S_width / 2) + Radius) &&
						Pos.X >= ((S_width / 2) - Radius) &&
						Pos.Y <= ((S_height / 2) + Radius) &&
						Pos.Y >= ((S_height / 2) - Radius))
					{
						if (this->Players[i].Distance < MaxPlayersClosetCrossDistance)
						{
							if (this->Players[i].Health > 0) {
								MaxPlayersClosetCrossDistance = this->Players[i].Distance;
								PlayersClosetCrossDistance = this->Players[i];
							}
							else
							{
								if (this->Players[i].NearDeathBreath < 100.f)
								{
									if (Settings::Aimbot::aimknocked) {
										MaxPlayersClosetCrossDistance = this->Players[i].Distance;
										PlayersClosetCrossDistance = this->Players[i];
									}
								}
							}
						}
					}
				}
			}
		}

		float MaxVehiclesClosetCrossDistance = FLT_MAX;
		for (size_t i = 0; i < this->Vehicles.size(); i++) {
			if (this->LocalPlayer.Health > 0 && this->Vehicles[i].Distance < Share::distance) {
				FVector Pos = FVector();
				if (WorldToScreen(this->Vehicles[i].origin, Pos)) {

					float Radius = (Share::AimFov * 8);
					if (Pos.X <= ((S_width / 2) + Radius) &&
						Pos.X >= ((S_width / 2) - Radius) &&
						Pos.Y <= ((S_height / 2) + Radius) &&
						Pos.Y >= ((S_height / 2) - Radius))
					{
						MaxVehiclesClosetCrossDistance = this->Vehicles[i].Distance;
						VehiclesClosetCrossDistance = this->Vehicles[i];
					}

				}

			}
		}

		float MaxPlayersCenterCrossDistance = FLT_MAX;
		for (size_t i = 0; i < this->Players.size(); i++) {
			if (this->LocalPlayer.Health > 0 && this->Players[i].Team != this->LocalPlayer.Team && this->Players[i].Distance < Share::distance) {
				FVector Pos = FVector();
				if (WorldToScreen(this->Players[i].origin, Pos)) {
					float Dist = Utils::GetCrossDistance(Pos.X, Pos.Y, S_width / 2, S_height / 2);
					if (Dist < MaxPlayersCenterCrossDistance)
					{
						float Radius = (Share::AimFov * 8);
						if (Pos.X <= ((S_width / 2) + Radius) &&
							Pos.X >= ((S_width / 2) - Radius) &&
							Pos.Y <= ((S_height / 2) + Radius) &&
							Pos.Y >= ((S_height / 2) - Radius))
						{
							if (this->Players[i].Health > 0) {
								MaxPlayersCenterCrossDistance = Dist;
								PlayersCenterCrossDistance = this->Players[i];
							}
							else
							{
								if (this->Players[i].NearDeathBreath < 100.f)
								{
									if (Settings::Aimbot::aimknocked) {
										MaxPlayersCenterCrossDistance = Dist;
										PlayersCenterCrossDistance = this->Players[i];
									}
								}
							}
						}
					}
				}
			}
		}

		float MaxVehiclesCenterCrossDistance = FLT_MAX;
		for (size_t i = 0; i < this->Vehicles.size(); i++) {
			if (this->LocalPlayer.Health > 0 && this->Vehicles[i].Distance < Share::distance) {
				FVector Pos = FVector();
				if (WorldToScreen(this->Vehicles[i].origin, Pos)) {
					float Dist = Utils::GetCrossDistance(Pos.X, Pos.Y, S_width / 2, S_height / 2);
					if (Dist < MaxVehiclesCenterCrossDistance)
					{
						float Radius = (Share::AimFov * 8);
						if (Pos.X <= ((S_width / 2) + Radius) &&
							Pos.X >= ((S_width / 2) - Radius) &&
							Pos.Y <= ((S_height / 2) + Radius) &&
							Pos.Y >= ((S_height / 2) - Radius))
						{
							MaxVehiclesCenterCrossDistance = Dist;
							VehiclesCenterCrossDistance = this->Vehicles[i];
						}
					}
				}

			}
		}

		float closestdis = FLT_MAX;
		for (int i = 0; i < this->Players.size(); i++) {
			if (this->LocalPlayer.Health > 0 && this->Players[i].Team != this->LocalPlayer.Team)
			{
				if ((this->Players[i].Distance < closestdis)) {
					ClosestVisibleEnemy = this->Players[i];
					closestdis = this->Players[i].Distance;
				}
			}
		}
	}


	bool WorldToScreen(FVector WorldLocation, FVector& Screenlocation)
	{
		FRotator Rotation = CameraCacheEntry.Rotation;
		D3DMATRIX tempMatrix = Math::Matrix(Rotation);

		FVector vAxisX, vAxisY, vAxisZ;

		vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
		vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
		vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

		FVector vDelta = WorldLocation - CameraCacheEntry.Location;
		FVector vTransformed = FVector(vDelta.Dot(vDelta, vAxisY), vDelta.Dot(vDelta, vAxisZ), vDelta.Dot(vDelta, vAxisX));

		if (vTransformed.Z < 0.0001f) return false;


		float FovAngle = CameraCacheEntry.FOV;

		float ScreenCenterX = S_width / 2;
		float ScreenCenterY = S_height / 2;
		float ScreenCenterZ = S_height / 2;

		Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
		Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
		Screenlocation.Z = ScreenCenterZ - vTransformed.Z * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;

		if (Screenlocation.X > S_width || Screenlocation.Y > S_height || Screenlocation.X < 0 || Screenlocation.Y < 0)
			return false;

		return true;
	}

	bool WorldToScreenAim(FVector WorldLocation, FRotator Rot, FVector& Screenlocation)
	{
		FRotator Rotation = Rot;
		D3DMATRIX tempMatrix = Math::Matrix(Rotation);

		FVector vAxisX, vAxisY, vAxisZ;

		vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
		vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
		vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

		FVector vDelta = WorldLocation - CameraCacheEntry.Location;
		FVector vTransformed = FVector(vDelta.Dot(vDelta, vAxisY), vDelta.Dot(vDelta, vAxisZ), vDelta.Dot(vDelta, vAxisX));

		if (vTransformed.Z < 0.0001f) return false;


		float FovAngle = CameraCacheEntry.FOV;

		float ScreenCenterX = S_width / 2;
		float ScreenCenterY = S_height / 2;
		float ScreenCenterZ = S_height / 2;

		Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
		Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
		Screenlocation.Z = ScreenCenterZ - vTransformed.Z * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;

		if (Screenlocation.X > S_width || Screenlocation.Y > S_height || Screenlocation.X < 0 || Screenlocation.Y < 0)
			return false;

		return true;
	}
	FVector CalcSoldierFuturePos(FVector InVec)
	{
		FVector NewPos = FVector(), OutPos = FVector();
		if (WorldToScreen(InVec, NewPos))
		{
			OutPos.X = NewPos.X;
			OutPos.Y = NewPos.Y;
			OutPos.Z = NewPos.Z;
		}
		else
		{
			OutPos.X = 0;
			OutPos.Y = 0;
			OutPos.Z = 0;

		}
		return OutPos;
	}



};
