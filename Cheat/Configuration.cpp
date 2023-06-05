#include "Includes.h"
namespace Config {
	bool ScanColorFromCvar(const char* str, float* colors)
	{
		int len = strlen(str);
		if (len > 11)return false;
		int clrnum = 0;
		int clrsum = 0;
		for (int i = 0; i < len; i++)
		{
			if (clrnum >= 3)return false;
			if (str[i] >= '0' && str[i] <= '9')
			{
				clrsum = clrsum * 10 + str[i] - (int)'0';
			}
			else
			{
				colors[clrnum++] = (float)clrsum / 255.f;
				clrsum = 0;
			}
		}
		colors[clrnum] = (float)clrsum / 255.f;
		return true;
	}

	void LoadSettings(std::string szIniFile)
	{
		CSX::Cvar::InitPath(szIniFile.c_str());
#pragma region Screen
		Settings::Screen::TotalPlayers = CSX::Cvar::LoadCvar(xorstr_("SCREEN"), xorstr_("S_TotalPlayers"), Settings::Screen::TotalPlayers) != false;
		Settings::Screen::PlayerAiming = CSX::Cvar::LoadCvar(xorstr_("SCREEN"), xorstr_("S_PlayerAiming"), Settings::Screen::PlayerAiming) != false;
		Settings::Screen::ServerInfo = CSX::Cvar::LoadCvar(xorstr_("SCREEN"), xorstr_("S_ServerInfo"), Settings::Screen::ServerInfo) != false;

#pragma endregion 
#pragma region Aimbot

		Settings::Aimbot::enable = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("A_Enable"), Settings::Aimbot::enable) != false;
		Settings::Aimbot::aimknocked = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("A_Aimknocked"), Settings::Aimbot::aimknocked) != false;

		Settings::Aimbot::prediction = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("A_Prediction"), Settings::Aimbot::prediction) != false;
		Settings::Aimbot::drawfov = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("A_Drawfov"), Settings::Aimbot::drawfov) != false;
		Settings::Aimbot::drawhitbox = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("A_Drawhitbox"), Settings::Aimbot::drawhitbox) != false;

		Settings::Aimbot::ARConfig::enable = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_enable"), Settings::Aimbot::ARConfig::enable) != false;
		Settings::Aimbot::ARConfig::aimkey = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_aimkey"), Settings::Aimbot::ARConfig::aimkey);
		Settings::Aimbot::ARConfig::autolock = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_autolock"), Settings::Aimbot::ARConfig::autolock) != false;
		Settings::Aimbot::ARConfig::distance = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_Distance"), Settings::Aimbot::ARConfig::distance);
		Settings::Aimbot::ARConfig::fov = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_fov"), Settings::Aimbot::ARConfig::fov);
		Settings::Aimbot::ARConfig::smooth = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_smooth"), Settings::Aimbot::ARConfig::smooth);
		Settings::Aimbot::ARConfig::recoil = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_recoil"), Settings::Aimbot::ARConfig::recoil) != false;
		Settings::Aimbot::ARConfig::compesation = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_compesation"), Settings::Aimbot::ARConfig::compesation);
		Settings::Aimbot::ARConfig::hitbox = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("AR_hitbox"), Settings::Aimbot::ARConfig::hitbox);

		Settings::Aimbot::SMGConfig::enable = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_enable"), Settings::Aimbot::SMGConfig::enable) != false;
		Settings::Aimbot::SMGConfig::aimkey = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_aimkey"), Settings::Aimbot::SMGConfig::aimkey);
		Settings::Aimbot::SMGConfig::autolock = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_autolock"), Settings::Aimbot::SMGConfig::autolock) != false;
		Settings::Aimbot::SMGConfig::distance = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_Distance"), Settings::Aimbot::SMGConfig::distance);
		Settings::Aimbot::SMGConfig::fov = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_fov"), Settings::Aimbot::SMGConfig::fov);
		Settings::Aimbot::SMGConfig::smooth = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_smooth"), Settings::Aimbot::SMGConfig::smooth);
		Settings::Aimbot::SMGConfig::compesation = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_compesation"), Settings::Aimbot::SMGConfig::compesation);
		Settings::Aimbot::SMGConfig::recoil = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_recoil"), Settings::Aimbot::SMGConfig::recoil) != false;
		Settings::Aimbot::SMGConfig::hitbox = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("SMG_hitbox"), Settings::Aimbot::SMGConfig::hitbox) ;

		Settings::Aimbot::SniperConfig::enable = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_enable"), Settings::Aimbot::SniperConfig::enable) != false;
		Settings::Aimbot::SniperConfig::aimkey = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_aimkey"), Settings::Aimbot::SniperConfig::aimkey);
		Settings::Aimbot::SniperConfig::autolock = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_autolock"), Settings::Aimbot::SniperConfig::autolock) != false;
		Settings::Aimbot::SniperConfig::distance = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_Distance"), Settings::Aimbot::SniperConfig::distance);
		Settings::Aimbot::SniperConfig::fov = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_fov"), Settings::Aimbot::SniperConfig::fov);
		Settings::Aimbot::SniperConfig::smooth = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_smooth"), Settings::Aimbot::SniperConfig::smooth);
		Settings::Aimbot::SniperConfig::recoil = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_recoil"), Settings::Aimbot::SniperConfig::recoil) != false;
		Settings::Aimbot::SniperConfig::compesation = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_compesation"), Settings::Aimbot::SniperConfig::compesation);
		Settings::Aimbot::SniperConfig::hitbox = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("Sniper_hitbox"), Settings::Aimbot::SniperConfig::hitbox) ;

		Settings::Aimbot::ShotGunConfig::enable = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_enable"), Settings::Aimbot::ShotGunConfig::enable) != false;
		Settings::Aimbot::ShotGunConfig::aimkey = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_aimkey"), Settings::Aimbot::ShotGunConfig::aimkey);
		Settings::Aimbot::ShotGunConfig::autolock = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_autolock"), Settings::Aimbot::ShotGunConfig::autolock) != false;
		Settings::Aimbot::ShotGunConfig::distance = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_Distance"), Settings::Aimbot::ShotGunConfig::distance);
		Settings::Aimbot::ShotGunConfig::fov = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_fov"), Settings::Aimbot::ShotGunConfig::fov);
		Settings::Aimbot::ShotGunConfig::smooth = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_smooth"), Settings::Aimbot::ShotGunConfig::smooth);
		Settings::Aimbot::ShotGunConfig::recoil = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_recoil"), Settings::Aimbot::ShotGunConfig::recoil) != false;
		Settings::Aimbot::ShotGunConfig::compesation = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_compesation"), Settings::Aimbot::ShotGunConfig::compesation);
		Settings::Aimbot::ShotGunConfig::hitbox = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_hitbox"), Settings::Aimbot::ShotGunConfig::hitbox);

		Settings::Aimbot::LMGConfig::enable = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_enable"), Settings::Aimbot::LMGConfig::enable) != false;
		Settings::Aimbot::LMGConfig::aimkey = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_aimkey"), Settings::Aimbot::LMGConfig::aimkey);
		Settings::Aimbot::LMGConfig::autolock = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_autolock"), Settings::Aimbot::LMGConfig::autolock) != false;
		Settings::Aimbot::LMGConfig::distance = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_Distance"), Settings::Aimbot::LMGConfig::distance);
		Settings::Aimbot::LMGConfig::fov = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_fov"), Settings::Aimbot::LMGConfig::fov);
		Settings::Aimbot::LMGConfig::smooth = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_smooth"), Settings::Aimbot::LMGConfig::smooth);
		Settings::Aimbot::LMGConfig::recoil = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_recoil"), Settings::Aimbot::LMGConfig::recoil) != false;
		Settings::Aimbot::LMGConfig::compesation = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_compesation"), Settings::Aimbot::LMGConfig::compesation);
		Settings::Aimbot::LMGConfig::hitbox = CSX::Cvar::LoadCvar(xorstr_("AIMBOT"), xorstr_("LMG_hitbox"), Settings::Aimbot::LMGConfig::hitbox);

#pragma endregion
#pragma region Esp
		Settings::ESP::Players::Team::name = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamName"), Settings::ESP::Players::Team::name) != false;
		Settings::ESP::Players::Team::boxes = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamBox"), Settings::ESP::Players::Team::boxes) != false;
		Settings::ESP::Players::Team::distance = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamDistance"), Settings::ESP::Players::Team::distance) != false;
		Settings::ESP::Players::Team::snaplines = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamSnaplines"), Settings::ESP::Players::Team::snaplines) != false;
		Settings::ESP::Players::Team::health = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamHealth"), Settings::ESP::Players::Team::health) != false;
		Settings::ESP::Players::Team::filledbox = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamFilledbox"), Settings::ESP::Players::Team::filledbox) != false;
		Settings::ESP::Players::Team::skeleton = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamSkeleton"), Settings::ESP::Players::Team::skeleton) != false;
		Settings::ESP::Players::Team::offscreen = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamOffscreen"), Settings::ESP::Players::Team::offscreen) != false;
		Settings::ESP::Players::Team::weapon = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamWeapon"), Settings::ESP::Players::Team::weapon) != false;
		Settings::ESP::Players::Team::status = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamStatus"), Settings::ESP::Players::Team::status) != false;
		Settings::ESP::Players::Team::nation = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamNation"), Settings::ESP::Players::Team::nation) != false;
		Settings::ESP::Players::Team::directionLine = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamDirectionLine"), Settings::ESP::Players::Team::directionLine) != false;
		Settings::ESP::Players::Team::prediction = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamPrediction"), Settings::ESP::Players::Team::prediction) != false;
		Settings::ESP::Players::Team::spot = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamSpot"), Settings::ESP::Players::Team::spot) != false;
		Settings::ESP::Players::Team::WeaponWarning = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TeamWeaponWarning"), Settings::ESP::Players::Team::WeaponWarning) != false;

		Settings::ESP::Players::Enemy::name = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyName"), Settings::ESP::Players::Enemy::name) != false;
		Settings::ESP::Players::Enemy::boxes = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyBox"), Settings::ESP::Players::Enemy::boxes) != false;
		Settings::ESP::Players::Enemy::distance = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyDistance"), Settings::ESP::Players::Enemy::distance) != false;
		Settings::ESP::Players::Enemy::snaplines = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemySnaplines"), Settings::ESP::Players::Enemy::snaplines) != false;
		Settings::ESP::Players::Enemy::health = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyHealth"), Settings::ESP::Players::Enemy::health) != false;
		Settings::ESP::Players::Enemy::filledbox = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyFilledbox"), Settings::ESP::Players::Enemy::filledbox) != false;
		Settings::ESP::Players::Enemy::skeleton = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemySkull"), Settings::ESP::Players::Enemy::skeleton) != false;
		Settings::ESP::Players::Enemy::offscreen = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyOffscreen"), Settings::ESP::Players::Enemy::offscreen) != false;
		Settings::ESP::Players::Enemy::weapon = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyWeapon"), Settings::ESP::Players::Enemy::weapon) != false;
		Settings::ESP::Players::Enemy::status = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyStatus"), Settings::ESP::Players::Enemy::status) != false;
		Settings::ESP::Players::Enemy::nation = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyNation"), Settings::ESP::Players::Enemy::nation) != false;
		Settings::ESP::Players::Enemy::directionLine = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyDirectionLine"), Settings::ESP::Players::Enemy::directionLine) != false;
		Settings::ESP::Players::Enemy::prediction = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyPrediction"), Settings::ESP::Players::Enemy::prediction) != false;
		Settings::ESP::Players::Enemy::spot = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemySpot"), Settings::ESP::Players::Enemy::spot) != false;
		Settings::ESP::Players::Enemy::WeaponWarning = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EnemyWeaponWarning"), Settings::ESP::Players::Enemy::WeaponWarning) != false;

		Settings::ESP::Other::EspGrenade = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_EspGrenade"), Settings::ESP::Other::EspGrenade) != false;
		Settings::ESP::Other::redzone = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_RedZone"), Settings::ESP::Other::redzone) != false;
		Settings::ESP::Other::vehicleExplosionWarning = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehicleExplosionWarning"), Settings::ESP::Other::vehicleExplosionWarning) != false;

		Settings::ESP::Vehicle::vehicleBox = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehicleBox"), Settings::ESP::Vehicle::vehicleBox) != false;
		Settings::ESP::Vehicle::vehicleDirectionLine = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehicleDirectionLine"), Settings::ESP::Vehicle::vehicleDirectionLine) != false;
		Settings::ESP::Vehicle::vehicleHP = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehicleHP"), Settings::ESP::Vehicle::vehicleHP) != false;
		Settings::ESP::Vehicle::vehicleName = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehicleName"), Settings::ESP::Vehicle::vehicleName) != false;
		Settings::ESP::Vehicle::vehicleWheelDamaged = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehicleWheelDamaged"), Settings::ESP::Vehicle::vehicleWheelDamaged) != false;

		Settings::ESP::Vehicle::vehicleOil = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehicleOil"), Settings::ESP::Vehicle::vehicleOil) != false;
		Settings::ESP::Vehicle::vehiclePrediction = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehiclePrediction"), Settings::ESP::Vehicle::vehiclePrediction) != false;

		Settings::ESP::Loot::lootaccessories = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootAccessories"), Settings::ESP::Loot::lootaccessories) != false;
		Settings::ESP::Loot::lootarmor = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootArmor"), Settings::ESP::Loot::lootarmor) != false;
		Settings::ESP::Loot::lootarweapon = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootARWeapon"), Settings::ESP::Loot::lootarweapon) != false;
		Settings::ESP::Loot::lootshotgun = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootShotgun"), Settings::ESP::Loot::lootshotgun) != false;
		Settings::ESP::Loot::lootbackpack = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootBackpack"), Settings::ESP::Loot::lootbackpack) != false;
		Settings::ESP::Loot::lootenergy = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootEnergy"), Settings::ESP::Loot::lootenergy) != false;
		Settings::ESP::Loot::lootgrenade = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootGrenade"), Settings::ESP::Loot::lootgrenade) != false;
		Settings::ESP::Loot::loothelmet = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootHelmet"), Settings::ESP::Loot::loothelmet) != false;
		Settings::ESP::Loot::lootother = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootOther"), Settings::ESP::Loot::lootother) != false;
		Settings::ESP::Loot::lootscopes = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootScopes"), Settings::ESP::Loot::lootscopes) != false;
		Settings::ESP::Loot::lootsmgweapon = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootSMGWeapon"), Settings::ESP::Loot::lootsmgweapon) != false;
		Settings::ESP::Loot::lootsniperweapon = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootSniperWeapon"), Settings::ESP::Loot::lootsniperweapon) != false;
		Settings::ESP::Loot::lootspecial = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootSpecial"), Settings::ESP::Loot::lootspecial) != false;
		Settings::ESP::Loot::lootbicycle = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootBicycle"), Settings::ESP::Loot::lootbicycle) != false;

		Settings::ESP::Inventory::AirDrop = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_AirDrop"), Settings::ESP::Inventory::AirDrop) != false;
		Settings::ESP::Inventory::Deadbox = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_Deadbox"), Settings::ESP::Inventory::Deadbox) != false;
		Settings::ESP::Inventory::TreasureChest = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_TreasureChest"), Settings::ESP::Inventory::TreasureChest) != false;
		Settings::ESP::Inventory::InventoryDetails = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_InventoryDetails"), Settings::ESP::Inventory::InventoryDetails) != false;

		Settings::ESP::Options::colorbyteamid = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_ColorByTeamID"), Settings::ESP::Options::colorbyteamid);
		Settings::ESP::Options::playersdis = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_PlayersDistance"), Settings::ESP::Options::playersdis);
		Settings::ESP::Options::vehiclesdis = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_vehiclesDistance"), Settings::ESP::Options::vehiclesdis);
		Settings::ESP::Options::max_distance_offscreen = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_OffscreenDistance"), Settings::ESP::Options::max_distance_offscreen);
		Settings::ESP::Options::boxtype = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_boxType"), Settings::ESP::Options::boxtype);
		Settings::ESP::Options::healthbartype = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_HealthBartype"), Settings::ESP::Options::healthbartype);
		Settings::ESP::Options::offscreen_range = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_OffscreenRange"), Settings::ESP::Options::offscreen_range);
		Settings::ESP::Options::esp_Outline = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_Outline"), Settings::ESP::Options::esp_Outline) != false;
		Settings::ESP::Options::predictiontype = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_PredictionType"), Settings::ESP::Options::predictiontype);
		Settings::ESP::Options::Nationtype = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_NationType"), Settings::ESP::Options::Nationtype);
		Settings::ESP::Options::predictiontype2 = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_VehiclePredictiontype"), Settings::ESP::Options::predictiontype2);
		Settings::ESP::Options::loottype = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_LootType"), Settings::ESP::Options::loottype);
		Settings::ESP::Options::GrenadeType = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_GrenadeType"), Settings::ESP::Options::GrenadeType);
		Settings::ESP::Options::iconwidth = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_Looticonwidth"), Settings::ESP::Options::iconwidth);
		Settings::ESP::Options::iconheight = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_Looticonheight"), Settings::ESP::Options::iconheight);
		Settings::ESP::Options::FightModeKey = CSX::Cvar::LoadCvar(xorstr_("ESP"), xorstr_("E_FightModeKey"), Settings::ESP::Options::FightModeKey);

#pragma endregion
#pragma region Radar
		Settings::Radar::enable = CSX::Cvar::LoadCvar(xorstr_("RADAR"), xorstr_("R_Enable"), Settings::Radar::enable) != false;
		Settings::Radar::teamRadar = CSX::Cvar::LoadCvar(xorstr_("RADAR"), xorstr_("R_TeamPlayers"), Settings::Radar::teamRadar) != false;
		Settings::Radar::enemyRadar = CSX::Cvar::LoadCvar(xorstr_("RADAR"), xorstr_("R_EnemyPlayers"), Settings::Radar::enemyRadar) != false;
		Settings::Radar::vehicleRadar = CSX::Cvar::LoadCvar(xorstr_("RADAR"), xorstr_("R_Vehicle"), Settings::Radar::vehicleRadar) != false;
		Settings::Radar::airdropRadar = CSX::Cvar::LoadCvar(xorstr_("RADAR"), xorstr_("R_AirDrop"), Settings::Radar::airdropRadar) != false;

		Settings::Radar::radartype = CSX::Cvar::LoadCvar(xorstr_("RADAR"), xorstr_("R_RadarType"), Settings::Radar::radartype);
		Settings::Radar::distance_Radar = CSX::Cvar::LoadCvar(xorstr_("RADAR"), xorstr_("R_Playersdistance"), Settings::Radar::distance_Radar);
#pragma endregion
#pragma region Micro
		Settings::Micro::AR::micro_Iron = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_Iron"), Settings::Micro::AR::micro_Iron) != false;
		Settings::Micro::AR::micro_RedDot = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_RedDot"), Settings::Micro::AR::micro_RedDot) != false;
		Settings::Micro::AR::micro_X2 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_X2"), Settings::Micro::AR::micro_X2) != false;
		Settings::Micro::AR::micro_X3 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_X3"), Settings::Micro::AR::micro_X3) != false;
		Settings::Micro::AR::micro_X4 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_X4"), Settings::Micro::AR::micro_X4) != false;
		Settings::Micro::AR::microaxis_Iron.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_Iron"), Settings::Micro::AR::microaxis_Iron.X);
		Settings::Micro::AR::microaxis_Iron.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_Iron"), Settings::Micro::AR::microaxis_Iron.Y);
		Settings::Micro::AR::microaxis_RedDot.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_RedDot"), Settings::Micro::AR::microaxis_RedDot.X);
		Settings::Micro::AR::microaxis_RedDot.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_RedDot"), Settings::Micro::AR::microaxis_RedDot.Y);
		Settings::Micro::AR::microaxis_X2.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_X2"), Settings::Micro::AR::microaxis_X2.X);
		Settings::Micro::AR::microaxis_X2.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_X2"), Settings::Micro::AR::microaxis_X2.Y);
		Settings::Micro::AR::microaxis_X3.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_X3"), Settings::Micro::AR::microaxis_X3.X);
		Settings::Micro::AR::microaxis_X3.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_X3"), Settings::Micro::AR::microaxis_X3.Y);
		Settings::Micro::AR::microaxis_X4.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_X4"), Settings::Micro::AR::microaxis_X4.X);
		Settings::Micro::AR::microaxis_X4.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_X4"), Settings::Micro::AR::microaxis_X4.Y);

		Settings::Micro::SMG::micro_Iron = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_Iron"), Settings::Micro::SMG::micro_Iron) != false;
		Settings::Micro::SMG::micro_RedDot = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_RedDot"), Settings::Micro::SMG::micro_RedDot) != false;
		Settings::Micro::SMG::micro_X2 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_X2"), Settings::Micro::SMG::micro_X2) != false;
		Settings::Micro::SMG::micro_X3 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_X3"), Settings::Micro::SMG::micro_X3) != false;
		Settings::Micro::SMG::micro_X4 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_X4"), Settings::Micro::SMG::micro_X4) != false;
		Settings::Micro::SMG::microaxis_Iron.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_Iron"), Settings::Micro::SMG::microaxis_Iron.X);
		Settings::Micro::SMG::microaxis_Iron.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_Iron"), Settings::Micro::SMG::microaxis_Iron.Y);
		Settings::Micro::SMG::microaxis_RedDot.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_RedDot"), Settings::Micro::SMG::microaxis_RedDot.X);
		Settings::Micro::SMG::microaxis_RedDot.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_RedDot"), Settings::Micro::SMG::microaxis_RedDot.Y);
		Settings::Micro::SMG::microaxis_X2.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_X2"), Settings::Micro::SMG::microaxis_X2.X);
		Settings::Micro::SMG::microaxis_X2.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_X2"), Settings::Micro::SMG::microaxis_X2.Y);
		Settings::Micro::SMG::microaxis_X3.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_X3"), Settings::Micro::SMG::microaxis_X3.X);
		Settings::Micro::SMG::microaxis_X3.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_X3"), Settings::Micro::SMG::microaxis_X3.Y);
		Settings::Micro::SMG::microaxis_X4.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_X4"), Settings::Micro::SMG::microaxis_X4.X);
		Settings::Micro::SMG::microaxis_X4.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_X4"), Settings::Micro::SMG::microaxis_X4.Y);

		Settings::Micro::LMG::micro_Iron = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_Iron"), Settings::Micro::LMG::micro_Iron) != false;
		Settings::Micro::LMG::micro_RedDot = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_RedDot"), Settings::Micro::LMG::micro_RedDot) != false;
		Settings::Micro::LMG::micro_X2 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_X2"), Settings::Micro::LMG::micro_X2) != false;
		Settings::Micro::LMG::micro_X3 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_X3"), Settings::Micro::LMG::micro_X3) != false;
		Settings::Micro::LMG::micro_X4 = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_X4"), Settings::Micro::LMG::micro_X4) != false;
		Settings::Micro::LMG::microaxis_Iron.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_Iron"), Settings::Micro::LMG::microaxis_Iron.X);
		Settings::Micro::LMG::microaxis_Iron.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_Iron"), Settings::Micro::LMG::microaxis_Iron.Y);
		Settings::Micro::LMG::microaxis_RedDot.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_RedDot"), Settings::Micro::LMG::microaxis_RedDot.X);
		Settings::Micro::LMG::microaxis_RedDot.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_RedDot"), Settings::Micro::LMG::microaxis_RedDot.Y);
		Settings::Micro::LMG::microaxis_X2.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_X2"), Settings::Micro::LMG::microaxis_X2.X);
		Settings::Micro::LMG::microaxis_X2.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_X2"), Settings::Micro::LMG::microaxis_X2.Y);
		Settings::Micro::LMG::microaxis_X3.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_X3"), Settings::Micro::LMG::microaxis_X3.X);
		Settings::Micro::LMG::microaxis_X3.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_X3"), Settings::Micro::LMG::microaxis_X3.Y);
		Settings::Micro::LMG::microaxis_X4.X = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_X4"), Settings::Micro::LMG::microaxis_X4.X);
		Settings::Micro::LMG::microaxis_X4.Y = CSX::Cvar::LoadCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_X4"), Settings::Micro::LMG::microaxis_X4.Y);


#pragma endregion
#pragma region Crosshair
		Settings::Crosshair::c_enable = CSX::Cvar::LoadCvar(xorstr_("CROSSHAIR"), xorstr_("C_Enable"), Settings::Crosshair::c_enable) != false;
		Settings::Crosshair::crosshair = CSX::Cvar::LoadCvar(xorstr_("CROSSHAIR"), xorstr_("C_Crosshair"), Settings::Crosshair::crosshair);
		Settings::Crosshair::size = CSX::Cvar::LoadCvar(xorstr_("CROSSHAIR"), xorstr_("C_Size"), Settings::Crosshair::size);
		Settings::Crosshair::stroke = CSX::Cvar::LoadCvar(xorstr_("CROSSHAIR"), xorstr_("C_Stroke"), Settings::Crosshair::stroke);
#pragma endregion
#pragma region Colors
		std::string TeamBox = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_TeamBox"), "0,0,0");
		std::string TeamDirectionLine = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_TeamDirectionLine"), "0,0,0");
		std::string TeamSkeleton = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_TeamSkeleton"), "0,0,0");
		std::string TeamSnapline = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_TeamSnapline"), "0,0,0");
		std::string TeamKnocked = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_TeamKnocked"), "0,0,0");
		std::string TeamSpot = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_TeamSpot"), "0,0,0");
		std::string TeamWeaponWarning = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_TeamWeaponWarning"), "0,0,0");

		std::string EnemyBox = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_EnemyBox"), "0,0,0");
		std::string EnemyDirectionLine = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_EnemyDirectionLine"), "0,0,0");
		std::string EnemySkeleton = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_EnemySkeleton"), "0,0,0");
		std::string EnemySnapline = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_EnemySnapline"), "0,0,0");
		std::string EnemyKnocked = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_EnemyKnocked"), "0,0,0");
		std::string EnemySpot = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_EnemySpot"), "0,0,0");
		std::string EnemyWeaponWarning = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_EnemyWeaponWarning"), "0,0,0");

		std::string LootAccessories = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootAccessories"), "0,0,0");
		std::string LootAR = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootAR"), "0,0,0");
		std::string LootArmor = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootArmor"), "0,0,0");
		std::string LootBackpack = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootBackpack"), "0,0,0");
		std::string LootGrenade = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootGrenade"), "0,0,0");
		std::string LootEnergy = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootEnergy"), "0,0,0");
		std::string LootHelmet = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootHelmet"), "0,0,0");
		std::string Lootother = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootOther"), "0,0,0");
		std::string LootScopes = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootScopes"), "0,0,0");
		std::string LootSMG = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootSMG"), "0,0,0");
		std::string LootSniper = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootSniper"), "0,0,0");
		std::string LootSpecial = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootSpecial"), "0,0,0");
		std::string LootShotgun = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootShotgun"), "0,0,0");
		std::string LootBicycle = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_LootBicycle"), "0,0,0");

		std::string RadarBOT = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_RadarBOT"), "0,0,0");
		std::string RadarEnemy = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_RadarEnemy"), "0,0,0");
		std::string RadarTeam = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_RadarTeam"), "0,0,0");
		std::string RadarVehicle = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_RadarVehicle"), "0,0,0");
		std::string RadarAirDrop = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_RadarAirDrop"), "0,0,0");

		std::string VehicleBox = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_VehicleBox"), "0,0,0");
		std::string VehicleDirectionLine = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_VehicleDirectionLine"), "0,0,0");
		std::string VehicleName = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_VehicleName"), "0,0,0,255");
		std::string VehicleVelocity = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_VehicleVelocity"), "0,0,0,255");

		std::string OtherDeadbox = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_OtherDeadbox"), "0,0,0");
		std::string OtherAirDrop = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_OtherAirDrop"), "0,0,0");
		std::string OtherTreasureChest = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_OtherTreasureChest"), "0,0,0");
		std::string OtherInventoryDetails = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_OtherInventoryDetails"), "0,0,0");

		std::string Crosshair = CSX::Cvar::LoadCvar(xorstr_("COLORS"), xorstr_("CLR_Crosshair"), "0,0,0");

		std::string BOTBox = CSX::Cvar::LoadCvar(xorstr_("COLORS"), "CLR_BOTBox", "0,0,0");
		std::string BOTDirectionLine = CSX::Cvar::LoadCvar(xorstr_("COLORS"), "CLR_BOTDirectionLine", "0,0,0");
		std::string BOTSkeleton = CSX::Cvar::LoadCvar(xorstr_("COLORS"), "CLR_BOTSkeleton", "0,0,0");
		std::string BOTSnapline = CSX::Cvar::LoadCvar(xorstr_("COLORS"), "CLR_BOTSnapline", "0,0,0");
		std::string BOTKnocked = CSX::Cvar::LoadCvar(xorstr_("COLORS"), "CLR_BOTKnocked", "0,0,0");
		std::string BOTSpot = CSX::Cvar::LoadCvar(xorstr_("COLORS"), "CLR_BOTSpot", "0,0,0");

		std::string Menu = CSX::Cvar::LoadCvar(xorstr_("COLORS"), "CLR_Menu", "0,0,0");

		ScanColorFromCvar(OtherDeadbox.c_str(), Settings::Color::Other::deadbox);
		ScanColorFromCvar(OtherAirDrop.c_str(), Settings::Color::Other::AirDrop);
		ScanColorFromCvar(OtherTreasureChest.c_str(), Settings::Color::Other::treasurechest);
		ScanColorFromCvar(OtherInventoryDetails.c_str(), Settings::Color::Other::InventoryDetails);

		ScanColorFromCvar(TeamBox.c_str(), Settings::Color::Players::Team::box);
		ScanColorFromCvar(TeamDirectionLine.c_str(), Settings::Color::Players::Team::directionLine);
		ScanColorFromCvar(TeamSkeleton.c_str(), Settings::Color::Players::Team::skeleton);
		ScanColorFromCvar(TeamSnapline.c_str(), Settings::Color::Players::Team::snapline);
		ScanColorFromCvar(TeamKnocked.c_str(), Settings::Color::Players::Team::knocked);
		ScanColorFromCvar(TeamSpot.c_str(), Settings::Color::Players::Team::spot);
		ScanColorFromCvar(TeamWeaponWarning.c_str(), Settings::Color::Players::Team::weaponwarning);

		ScanColorFromCvar(EnemyBox.c_str(), Settings::Color::Players::Enemy::box);
		ScanColorFromCvar(EnemyDirectionLine.c_str(), Settings::Color::Players::Enemy::directionLine);
		ScanColorFromCvar(EnemySkeleton.c_str(), Settings::Color::Players::Enemy::skeleton);
		ScanColorFromCvar(EnemySnapline.c_str(), Settings::Color::Players::Enemy::snapline);
		ScanColorFromCvar(EnemyKnocked.c_str(), Settings::Color::Players::Enemy::knocked);
		ScanColorFromCvar(EnemySpot.c_str(), Settings::Color::Players::Enemy::spot);
		ScanColorFromCvar(EnemyWeaponWarning.c_str(), Settings::Color::Players::Enemy::weaponwarning);

		ScanColorFromCvar(LootAccessories.c_str(), Settings::Color::Loot::accessories);
		ScanColorFromCvar(LootAR.c_str(), Settings::Color::Loot::ar);
		ScanColorFromCvar(LootArmor.c_str(), Settings::Color::Loot::armor);
		ScanColorFromCvar(LootBackpack.c_str(), Settings::Color::Loot::backpack);
		ScanColorFromCvar(LootGrenade.c_str(), Settings::Color::Loot::grenade);
		ScanColorFromCvar(LootEnergy.c_str(), Settings::Color::Loot::energy);
		ScanColorFromCvar(LootHelmet.c_str(), Settings::Color::Loot::helmet);
		ScanColorFromCvar(Lootother.c_str(), Settings::Color::Loot::other);
		ScanColorFromCvar(LootScopes.c_str(), Settings::Color::Loot::scopes);
		ScanColorFromCvar(LootShotgun.c_str(), Settings::Color::Loot::shotgun);
		ScanColorFromCvar(LootBicycle.c_str(), Settings::Color::Loot::bicycle);

		ScanColorFromCvar(LootSMG.c_str(), Settings::Color::Loot::smg);
		ScanColorFromCvar(LootSniper.c_str(), Settings::Color::Loot::sniper);
		ScanColorFromCvar(LootSpecial.c_str(), Settings::Color::Loot::special);

		ScanColorFromCvar(RadarBOT.c_str(), Settings::Color::Radar::BOT);
		ScanColorFromCvar(RadarEnemy.c_str(), Settings::Color::Radar::Enemy);
		ScanColorFromCvar(RadarTeam.c_str(), Settings::Color::Radar::Team);
		ScanColorFromCvar(RadarVehicle.c_str(), Settings::Color::Radar::Vehicle);
		ScanColorFromCvar(RadarAirDrop.c_str(), Settings::Color::Radar::AirDrop);

		ScanColorFromCvar(VehicleBox.c_str(), Settings::Color::Vehicle::Box);
		ScanColorFromCvar(VehicleDirectionLine.c_str(), Settings::Color::Vehicle::DirectionLine);
		ScanColorFromCvar(VehicleName.c_str(), Settings::Color::Vehicle::Name);
		ScanColorFromCvar(VehicleVelocity.c_str(), Settings::Color::Vehicle::velocity);

		ScanColorFromCvar(Crosshair.c_str(), Settings::Color::Crosshair::crosshair);

		ScanColorFromCvar(BOTBox.c_str(), Settings::Color::Players::Bot::box);
		ScanColorFromCvar(BOTDirectionLine.c_str(), Settings::Color::Players::Bot::directionLine);
		ScanColorFromCvar(BOTSkeleton.c_str(), Settings::Color::Players::Bot::skeleton);
		ScanColorFromCvar(BOTSnapline.c_str(), Settings::Color::Players::Bot::snapline);
		ScanColorFromCvar(BOTKnocked.c_str(), Settings::Color::Players::Bot::knocked);
		ScanColorFromCvar(BOTSpot.c_str(), Settings::Color::Players::Bot::spot);

		ScanColorFromCvar(Menu.c_str(), Settings::Color::Menu::color);

#pragma endregion
#pragma region Setting

		Settings::Setting::vsync = CSX::Cvar::LoadCvar(xorstr_("Setting"), xorstr_("vsync"), Settings::Setting::vsync) != false;
		Settings::Setting::fps = CSX::Cvar::LoadCvar(xorstr_("Setting"), xorstr_("fps"), Settings::Setting::fps);

		Settings::Menu::chroma_menu = CSX::Cvar::LoadCvar(xorstr_("Menu"), xorstr_("chroma"), Settings::Menu::chroma_menu) != false;
		Settings::Menu::drawdots = CSX::Cvar::LoadCvar(xorstr_("Menu"), xorstr_("drawdots"), Settings::Menu::drawdots) != false;
		Settings::Menu::watermark = CSX::Cvar::LoadCvar(xorstr_("Menu"), xorstr_("watermark"), Settings::Menu::watermark) != false;

#pragma endregion
	}
	void SaveSettings(std::string szIniFile)
	{
		CSX::Cvar::InitPath(szIniFile.c_str());
#pragma region Screen
		CSX::Cvar::SaveCvar(xorstr_("SCREEN"), xorstr_("S_TotalPlayers"), Settings::Screen::TotalPlayers);
		CSX::Cvar::SaveCvar(xorstr_("SCREEN"), xorstr_("S_PlayerAiming"), Settings::Screen::PlayerAiming);
		CSX::Cvar::SaveCvar(xorstr_("SCREEN"), xorstr_("S_ServerInfo"), Settings::Screen::ServerInfo);

#pragma endregion 
#pragma region Aimbot

		CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("A_Enable"), Settings::Aimbot::enable);
		CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("A_Aimknocked"), Settings::Aimbot::aimknocked);


		CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("A_Prediction"), Settings::Aimbot::prediction);
		CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("A_Drawfov"), Settings::Aimbot::drawfov);
		CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("A_Drawhitbox"), Settings::Aimbot::drawhitbox);

		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_enable"), Settings::Aimbot::ARConfig::enable);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_aimkey"), Settings::Aimbot::ARConfig::aimkey);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_autolock"), Settings::Aimbot::ARConfig::autolock);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_Distance"), Settings::Aimbot::ARConfig::distance);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_fov"), Settings::Aimbot::ARConfig::fov);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_smooth"), Settings::Aimbot::ARConfig::smooth);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_recoil"), Settings::Aimbot::ARConfig::recoil);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_compesation"), Settings::Aimbot::ARConfig::compesation);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("AR_hitbox"), Settings::Aimbot::ARConfig::hitbox);

		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_enable"), Settings::Aimbot::SMGConfig::enable);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_aimkey"), Settings::Aimbot::SMGConfig::aimkey);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_autolock"), Settings::Aimbot::SMGConfig::autolock);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_Distance"), Settings::Aimbot::SMGConfig::distance);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_fov"), Settings::Aimbot::SMGConfig::fov);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_smooth"), Settings::Aimbot::SMGConfig::smooth);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_compesation"), Settings::Aimbot::SMGConfig::compesation);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_recoil"), Settings::Aimbot::SMGConfig::recoil);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("SMG_hitbox"), Settings::Aimbot::SMGConfig::hitbox);

		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_enable"), Settings::Aimbot::SniperConfig::enable);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_aimkey"), Settings::Aimbot::SniperConfig::aimkey);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_autolock"), Settings::Aimbot::SniperConfig::autolock);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_Distance"), Settings::Aimbot::SniperConfig::distance);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_fov"), Settings::Aimbot::SniperConfig::fov);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_smooth"), Settings::Aimbot::SniperConfig::smooth);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_recoil"), Settings::Aimbot::SniperConfig::recoil);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_compesation"), Settings::Aimbot::SniperConfig::compesation);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("Sniper_hitbox"), Settings::Aimbot::SniperConfig::hitbox);

		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_enable"), Settings::Aimbot::ShotGunConfig::enable);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_aimkey"), Settings::Aimbot::ShotGunConfig::aimkey);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_autolock"), Settings::Aimbot::ShotGunConfig::autolock);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_Distance"), Settings::Aimbot::ShotGunConfig::distance);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_fov"), Settings::Aimbot::ShotGunConfig::fov);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_smooth"), Settings::Aimbot::ShotGunConfig::smooth);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_recoil"), Settings::Aimbot::ShotGunConfig::recoil);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_compesation"), Settings::Aimbot::ShotGunConfig::compesation);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("ShotGun_hitbox"), Settings::Aimbot::ShotGunConfig::hitbox);

		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_enable"), Settings::Aimbot::LMGConfig::enable);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_aimkey"), Settings::Aimbot::LMGConfig::aimkey);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_autolock"), Settings::Aimbot::LMGConfig::autolock);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_Distance"), Settings::Aimbot::LMGConfig::distance);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_fov"), Settings::Aimbot::LMGConfig::fov);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_smooth"), Settings::Aimbot::LMGConfig::smooth);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_recoil"), Settings::Aimbot::LMGConfig::recoil);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_compesation"), Settings::Aimbot::LMGConfig::compesation);
		 CSX::Cvar::SaveCvar(xorstr_("AIMBOT"), xorstr_("LMG_hitbox"), Settings::Aimbot::LMGConfig::hitbox);
#pragma endregion
#pragma region Esp
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamName"), Settings::ESP::Players::Team::name);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamBox"), Settings::ESP::Players::Team::boxes);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamDistance"), Settings::ESP::Players::Team::distance);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamSnaplines"), Settings::ESP::Players::Team::snaplines);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamHealth"), Settings::ESP::Players::Team::health);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamFilledbox"), Settings::ESP::Players::Team::filledbox);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamSkeleton"), Settings::ESP::Players::Team::skeleton);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamOffscreen"), Settings::ESP::Players::Team::offscreen);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamWeapon"), Settings::ESP::Players::Team::weapon);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamStatus"), Settings::ESP::Players::Team::status);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamNation"), Settings::ESP::Players::Team::nation);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamDirectionLine"), Settings::ESP::Players::Team::directionLine);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamPrediction"), Settings::ESP::Players::Team::prediction);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamSpot"), Settings::ESP::Players::Team::spot);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TeamWeaponWarning"), Settings::ESP::Players::Team::WeaponWarning);

		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyName"), Settings::ESP::Players::Enemy::name);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyBox"), Settings::ESP::Players::Enemy::boxes);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyDistance"), Settings::ESP::Players::Enemy::distance);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemySnaplines"), Settings::ESP::Players::Enemy::snaplines);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyHealth"), Settings::ESP::Players::Enemy::health);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyFilledbox"), Settings::ESP::Players::Enemy::filledbox);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemySkull"), Settings::ESP::Players::Enemy::skeleton);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyOffscreen"), Settings::ESP::Players::Enemy::offscreen);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyWeapon"), Settings::ESP::Players::Enemy::weapon);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyStatus"), Settings::ESP::Players::Enemy::status);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyNation"), Settings::ESP::Players::Enemy::nation);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyDirectionLine"), Settings::ESP::Players::Enemy::directionLine);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyPrediction"), Settings::ESP::Players::Enemy::prediction);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemySpot"), Settings::ESP::Players::Enemy::spot);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EnemyWeaponWarning"), Settings::ESP::Players::Enemy::WeaponWarning);


		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_EspGrenade"), Settings::ESP::Other::EspGrenade);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_RedZone"), Settings::ESP::Other::redzone);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehicleExplosionWarning"), Settings::ESP::Other::vehicleExplosionWarning);

		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehicleBox"), Settings::ESP::Vehicle::vehicleBox);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehicleDirectionLine"), Settings::ESP::Vehicle::vehicleDirectionLine);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehicleHP"), Settings::ESP::Vehicle::vehicleHP);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehicleName"), Settings::ESP::Vehicle::vehicleName);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehicleWheelDamaged"), Settings::ESP::Vehicle::vehicleWheelDamaged);

		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehicleOil"), Settings::ESP::Vehicle::vehicleOil);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehiclePrediction"), Settings::ESP::Vehicle::vehiclePrediction);

		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootAccessories"), Settings::ESP::Loot::lootaccessories);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootArmor"), Settings::ESP::Loot::lootarmor);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootARWeapon"), Settings::ESP::Loot::lootarweapon);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootShotgun"), Settings::ESP::Loot::lootshotgun);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootBackpack"), Settings::ESP::Loot::lootbackpack);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootEnergy"), Settings::ESP::Loot::lootenergy);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootGrenade"), Settings::ESP::Loot::lootgrenade);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootHelmet"), Settings::ESP::Loot::loothelmet);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootOther"), Settings::ESP::Loot::lootother);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootScopes"), Settings::ESP::Loot::lootscopes);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootSMGWeapon"), Settings::ESP::Loot::lootsmgweapon);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootSniperWeapon"), Settings::ESP::Loot::lootsniperweapon);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootSpecial"), Settings::ESP::Loot::lootspecial);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootBicycle"), Settings::ESP::Loot::lootbicycle);

		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_AirDrop"), Settings::ESP::Inventory::AirDrop);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_Deadbox"), Settings::ESP::Inventory::Deadbox);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_TreasureChest"), Settings::ESP::Inventory::TreasureChest);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_InventoryDetails"), Settings::ESP::Inventory::InventoryDetails);

		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_ColorByTeamID"), Settings::ESP::Options::colorbyteamid);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_PlayersDistance"), Settings::ESP::Options::playersdis);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehiclesDistance"), Settings::ESP::Options::vehiclesdis);

		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_OffscreenDistance"), Settings::ESP::Options::max_distance_offscreen);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_boxType"), Settings::ESP::Options::boxtype);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_HealthBartype"), Settings::ESP::Options::healthbartype);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_OffscreenRange"), Settings::ESP::Options::offscreen_range);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_Outline"), Settings::ESP::Options::esp_Outline);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_PredictionType"), Settings::ESP::Options::predictiontype);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_NationType"), Settings::ESP::Options::Nationtype);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_VehiclePredictiontype"), Settings::ESP::Options::predictiontype2);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_LootType"), Settings::ESP::Options::loottype);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_GrenadeType"), Settings::ESP::Options::GrenadeType);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_Looticonwidth"), Settings::ESP::Options::iconwidth);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_Looticonheight"), Settings::ESP::Options::iconheight);
		CSX::Cvar::SaveCvar(xorstr_("ESP"), xorstr_("E_FightModeKey"), Settings::ESP::Options::FightModeKey);

#pragma endregion
#pragma region Radar
		CSX::Cvar::SaveCvar(xorstr_("RADAR"), xorstr_("R_Enable"), Settings::Radar::enable);
		CSX::Cvar::SaveCvar(xorstr_("RADAR"), xorstr_("R_TeamPlayers"), Settings::Radar::teamRadar);
		CSX::Cvar::SaveCvar(xorstr_("RADAR"), xorstr_("R_EnemyPlayers"), Settings::Radar::enemyRadar);
		CSX::Cvar::SaveCvar(xorstr_("RADAR"), xorstr_("R_Vehicle"), Settings::Radar::vehicleRadar);
		CSX::Cvar::SaveCvar(xorstr_("RADAR"), xorstr_("R_AirDrop"), Settings::Radar::airdropRadar);

		CSX::Cvar::SaveCvar(xorstr_("RADAR"), xorstr_("R_RadarType"), Settings::Radar::radartype);
		CSX::Cvar::SaveCvar(xorstr_("RADAR"), xorstr_("R_Playersdistance"), Settings::Radar::distance_Radar);
#pragma endregion
#pragma region Micro
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_Iron"), Settings::Micro::AR::micro_Iron);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_RedDot"), Settings::Micro::AR::micro_RedDot);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_X2"), Settings::Micro::AR::micro_X2);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_X3"), Settings::Micro::AR::micro_X3);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_Micro_X4"), Settings::Micro::AR::micro_X4);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_Iron"), Settings::Micro::AR::microaxis_Iron.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_Iron"), Settings::Micro::AR::microaxis_Iron.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_RedDot"), Settings::Micro::AR::microaxis_RedDot.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_RedDot"), Settings::Micro::AR::microaxis_RedDot.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_X2"), Settings::Micro::AR::microaxis_X2.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_X2"), Settings::Micro::AR::microaxis_X2.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_X3"), Settings::Micro::AR::microaxis_X3.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_X3"), Settings::Micro::AR::microaxis_X3.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisX_X4"), Settings::Micro::AR::microaxis_X4.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_AR_MicroAxisY_X4"), Settings::Micro::AR::microaxis_X4.Y);

		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_Iron"), Settings::Micro::SMG::micro_Iron);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_RedDot"), Settings::Micro::SMG::micro_RedDot);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_X2"), Settings::Micro::SMG::micro_X2);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_X3"), Settings::Micro::SMG::micro_X3);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_Micro_X4"), Settings::Micro::SMG::micro_X4);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_Iron"), Settings::Micro::SMG::microaxis_Iron.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_Iron"), Settings::Micro::SMG::microaxis_Iron.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_RedDot"), Settings::Micro::SMG::microaxis_RedDot.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_RedDot"), Settings::Micro::SMG::microaxis_RedDot.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_X2"), Settings::Micro::SMG::microaxis_X2.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_X2"), Settings::Micro::SMG::microaxis_X2.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_X3"), Settings::Micro::SMG::microaxis_X3.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_X3"), Settings::Micro::SMG::microaxis_X3.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisX_X4"), Settings::Micro::SMG::microaxis_X4.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_SMG_MicroAxisY_X4"), Settings::Micro::SMG::microaxis_X4.Y);

		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_Iron"), Settings::Micro::LMG::micro_Iron);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_RedDot"), Settings::Micro::LMG::micro_RedDot);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_X2"), Settings::Micro::LMG::micro_X2);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_X3"), Settings::Micro::LMG::micro_X3);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_Micro_X4"), Settings::Micro::LMG::micro_X4);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_Iron"), Settings::Micro::LMG::microaxis_Iron.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_Iron"), Settings::Micro::LMG::microaxis_Iron.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_RedDot"), Settings::Micro::LMG::microaxis_RedDot.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_RedDot"), Settings::Micro::LMG::microaxis_RedDot.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_X2"), Settings::Micro::LMG::microaxis_X2.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_X2"), Settings::Micro::LMG::microaxis_X2.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_X3"), Settings::Micro::LMG::microaxis_X3.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_X3"), Settings::Micro::LMG::microaxis_X3.Y);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisX_X4"), Settings::Micro::LMG::microaxis_X4.X);
		CSX::Cvar::SaveCvar(xorstr_("MICRO"), xorstr_("M_LMG_MicroAxisY_X4"), Settings::Micro::LMG::microaxis_X4.Y);


#pragma endregion
#pragma region Crosshair
		CSX::Cvar::SaveCvar(xorstr_("CROSSHAIR"), xorstr_("C_Enable"), Settings::Crosshair::c_enable);
		CSX::Cvar::SaveCvar(xorstr_("CROSSHAIR"), xorstr_("C_Crosshair"), Settings::Crosshair::crosshair);
		CSX::Cvar::SaveCvar(xorstr_("CROSSHAIR"), xorstr_("C_Size"), Settings::Crosshair::size);
		CSX::Cvar::SaveCvar(xorstr_("CROSSHAIR"), xorstr_("C_Stroke"), Settings::Crosshair::stroke);
#pragma endregion
#pragma region Colors
		std::string TeamBox =
			std::to_string(int(Settings::Color::Players::Team::box[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::box[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::box[2] * 255.f));

		std::string TeamDirectionLine =
			std::to_string(int(Settings::Color::Players::Team::directionLine[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::directionLine[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::directionLine[2] * 255.f));

		std::string TeamSkeleton =
			std::to_string(int(Settings::Color::Players::Team::skeleton[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::skeleton[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::skeleton[2] * 255.f));

		std::string TeamSnapline =
			std::to_string(int(Settings::Color::Players::Team::snapline[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::snapline[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::snapline[2] * 255.f));

		std::string TeamKnocked =
			std::to_string(int(Settings::Color::Players::Team::knocked[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::knocked[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::knocked[2] * 255.f));

		std::string TeamSpot =
			std::to_string(int(Settings::Color::Players::Team::spot[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::spot[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::spot[2] * 255.f));

		std::string TeamWeaponWarning =
			std::to_string(int(Settings::Color::Players::Team::weaponwarning[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::weaponwarning[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::weaponwarning[2] * 255.f));

		std::string EnemyBox =
			std::to_string(int(Settings::Color::Players::Enemy::snapline[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::snapline[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::snapline[2] * 255.f));

		std::string EnemyDirectionLine =
			std::to_string(int(Settings::Color::Players::Enemy::directionLine[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::directionLine[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::directionLine[2] * 255.f));

		std::string EnemySkeleton =
			std::to_string(int(Settings::Color::Players::Enemy::skeleton[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::skeleton[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::skeleton[2] * 255.f));

		std::string EnemySnapline =
			std::to_string(int(Settings::Color::Players::Enemy::snapline[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::snapline[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::snapline[2] * 255.f));

		std::string EnemyKnocked =
			std::to_string(int(Settings::Color::Players::Enemy::knocked[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::knocked[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::knocked[2] * 255.f));

		std::string EnemySpot =
			std::to_string(int(Settings::Color::Players::Enemy::spot[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::spot[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::spot[2] * 255.f));

		std::string EnemyWeaponWarning =
			std::to_string(int(Settings::Color::Players::Enemy::weaponwarning[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::weaponwarning[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::weaponwarning[2] * 255.f));

		std::string LootAccessories =
			std::to_string(int(Settings::Color::Loot::accessories[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::accessories[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::accessories[2] * 255.f));

		std::string LootAR =
			std::to_string(int(Settings::Color::Loot::ar[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::ar[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::ar[2] * 255.f));

		std::string LootArmor =
			std::to_string(int(Settings::Color::Loot::armor[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::armor[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::armor[2] * 255.f));

		std::string LootBackpack =
			std::to_string(int(Settings::Color::Loot::backpack[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::backpack[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::backpack[2] * 255.f));

		std::string LootGrenade =
			std::to_string(int(Settings::Color::Loot::grenade[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::grenade[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::grenade[2] * 255.f));

		std::string LootEnergy =
			std::to_string(int(Settings::Color::Loot::energy[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::energy[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::energy[2] * 255.f));

		std::string LootHelmet =
			std::to_string(int(Settings::Color::Loot::helmet[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::helmet[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::helmet[2] * 255.f));

		std::string Lootother =
			std::to_string(int(Settings::Color::Loot::other[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::other[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::other[2] * 255.f));

		std::string LootScopes =
			std::to_string(int(Settings::Color::Loot::scopes[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::scopes[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::scopes[2] * 255.f));

		std::string LootShotgun =
			std::to_string(int(Settings::Color::Loot::shotgun[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::shotgun[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::shotgun[2] * 255.f));

		std::string LootBicycle =
			std::to_string(int(Settings::Color::Loot::bicycle[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::bicycle[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::bicycle[2] * 255.f));

		
		std::string LootSMG =
			std::to_string(int(Settings::Color::Loot::smg[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::smg[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::smg[2] * 255.f));

		std::string LootSniper =
			std::to_string(int(Settings::Color::Loot::sniper[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::sniper[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::sniper[2] * 255.f));

		std::string LootSpecial =
			std::to_string(int(Settings::Color::Loot::special[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::special[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::special[2] * 255.f));


		std::string RadarBOT =
			std::to_string(int(Settings::Color::Radar::BOT[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::BOT[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::BOT[2] * 255.f));

		std::string RadarEnemy =
			std::to_string(int(Settings::Color::Radar::Enemy[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Enemy[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Enemy[2] * 255.f));

		std::string RadarTeam =
			std::to_string(int(Settings::Color::Radar::Team[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Team[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Team[2] * 255.f));

		std::string RadarVehicle =
			std::to_string(int(Settings::Color::Radar::Vehicle[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Vehicle[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Vehicle[2] * 255.f));

		std::string RadarAirDrop =
			std::to_string(int(Settings::Color::Radar::AirDrop[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::AirDrop[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::AirDrop[2] * 255.f));

		std::string VehicleBox =
			std::to_string(int(Settings::Color::Vehicle::Box[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Vehicle::Box[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Vehicle::Box[2] * 255.f));

		std::string VehicleDirectionLine =
			std::to_string(int(Settings::Color::Vehicle::DirectionLine[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Vehicle::DirectionLine[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Vehicle::DirectionLine[2] * 255.f));

		std::string VehicleName =
			std::to_string(int(Settings::Color::Vehicle::Name[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Vehicle::Name[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Vehicle::Name[2] * 255.f));

		std::string VehicleVelocity =
			std::to_string(int(Settings::Color::Vehicle::velocity[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Vehicle::velocity[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Vehicle::velocity[2] * 255.f));

		std::string OtherDeadbox =
			std::to_string(int(Settings::Color::Other::deadbox[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Other::deadbox[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Other::deadbox[2] * 255.f));

		std::string OtherAirDrop =
			std::to_string(int(Settings::Color::Other::AirDrop[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Other::AirDrop[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Other::AirDrop[2] * 255.f));

		std::string OtherTreasureChest =
			std::to_string(int(Settings::Color::Other::treasurechest[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Other::treasurechest[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Other::treasurechest[2] * 255.f));

		std::string OtherInventoryDetails =
			std::to_string(int(Settings::Color::Other::InventoryDetails[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Other::InventoryDetails[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Other::InventoryDetails[2] * 255.f));

		std::string Crosshair =
			std::to_string(int(Settings::Color::Crosshair::crosshair[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Crosshair::crosshair[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Crosshair::crosshair[2] * 255.f));

		std::string BOTBox =
			std::to_string(int(Settings::Color::Players::Bot::box[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::box[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::box[2] * 255.f));

		std::string BOTDirectionLine =
			std::to_string(int(Settings::Color::Players::Bot::directionLine[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::directionLine[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::directionLine[2] * 255.f));

		std::string BOTSkeleton =
			std::to_string(int(Settings::Color::Players::Bot::skeleton[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::skeleton[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::skeleton[2] * 255.f));

		std::string BOTSnapline =
			std::to_string(int(Settings::Color::Players::Bot::snapline[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::snapline[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::snapline[2] * 255.f));

		std::string BOTKnocked =
			std::to_string(int(Settings::Color::Players::Bot::knocked[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::knocked[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::knocked[2] * 255.f));

		std::string BOTSpot =
			std::to_string(int(Settings::Color::Players::Bot::spot[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::spot[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::spot[2] * 255.f));

		std::string Menu =
			std::to_string(int(Settings::Color::Menu::color[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Menu::color[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Menu::color[2] * 255.f));

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_TeamBox"), TeamBox);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_TeamDirectionLine"), TeamDirectionLine);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_TeamSkeleton"), TeamSkeleton);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_TeamSnapline"), TeamSnapline);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_TeamKnocked"), TeamKnocked);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_TeamSpot"), TeamSpot);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_TeamWeaponWarning"), TeamWeaponWarning);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_EnemyBox"), EnemyBox);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_EnemyDirectionLine"), EnemyDirectionLine);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_EnemySkeleton"), EnemySkeleton);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_EnemySnapline"), EnemySnapline);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_EnemyKnocked"), EnemyKnocked);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_EnemySpot"), EnemySpot);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_EnemyWeaponWarning"), EnemyWeaponWarning);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootAccessories"), LootAccessories);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootAR"), LootAR);
		CSX::Cvar::SaveCvar(xorstr_("COLOR)"), xorstr_("CLR_LootArmor"), LootArmor);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootBackpack"), LootBackpack);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootGrenade"), LootGrenade);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootEnergy"), LootEnergy);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootHelmet"), LootHelmet);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_Lootother"), Lootother);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootScopes"), LootScopes);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootShotgun"), LootShotgun);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootBicycle"), LootBicycle);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootSMG"), LootSMG);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootSniper"), LootSniper);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_LootSpecial"), LootSpecial);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_RadarBOT"), RadarBOT);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_RadarEnemy"), RadarEnemy);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_RadarTeam"), RadarTeam);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_RadarVehicle"), RadarVehicle);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_RadarAirDrop"), RadarAirDrop);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_VehicleBox"), VehicleBox);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_VehicleDirectionLine"), VehicleDirectionLine);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_VehicleName"), VehicleName);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_VehicleVelocity"), VehicleVelocity);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_OtherDeadbox"), OtherDeadbox);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_OtherAirDrop"), OtherAirDrop);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_OtherTreasureChest"), OtherTreasureChest);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_OtherInventoryDetails"), OtherInventoryDetails);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_Crosshair"), Crosshair);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_BOTBox"), BOTBox);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_BOTDirectionLine"), BOTDirectionLine);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_BOTSkeleton"), BOTSkeleton);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_BOTSnapline"), BOTSnapline);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_BOTKnocked"), BOTKnocked);
		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_BOTSpot"), BOTSpot);

		CSX::Cvar::SaveCvar(xorstr_("COLORS"), xorstr_("CLR_Menu"), Menu);

#pragma endregion
#pragma region Setting

		CSX::Cvar::SaveCvar(xorstr_("Setting"), xorstr_("vsync"), Settings::Setting::vsync);
		CSX::Cvar::SaveCvar(xorstr_("Setting"), xorstr_("fps"), Settings::Setting::fps);

		CSX::Cvar::SaveCvar(xorstr_("Menu"), xorstr_("chroma"), Settings::Menu::chroma_menu);
		CSX::Cvar::SaveCvar(xorstr_("Menu"), xorstr_("drawdots"), Settings::Menu::drawdots);
		CSX::Cvar::SaveCvar(xorstr_("Menu"), xorstr_("watermark"), Settings::Menu::watermark);
#pragma endregion
	}
}