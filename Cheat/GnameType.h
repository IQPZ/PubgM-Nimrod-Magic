#pragma once

namespace GnameType
{

  extern std::map<std::string, ITEM_NAME> g_ItemHash;

	bool isPlayer(std::string type);
	bool IsDeathbox(std::string WeaponIndex);
	bool IsAirAttackBomb(std::string WeaponIndex);
	bool IsAirDropBox(std::string WeaponIndex);
	bool IsAirDropList(std::string WeaponIndex);
	bool IsTreasureChest(std::string type);
	bool IsVehicle(std::string type);
	bool IsSmokeGrenade(std::string classname);
	bool IsBurnGrenade(std::string classname);
	bool IsShouleiGrenade(std::string classname);
	bool IsStunGrenade(std::string classname);
	std::string PlayerGrenade(std::string str);
	std::string TreasureChest(std::string str);
	std::string GetVehicleType(std::string type);
	std::string scopes(int fov);
	std::string GetNationName(std::string str);
	std::string PlayerWeapon(std::string str);
	std::string PlayerWeaponFont(std::string str);
	std::string playerstatus(int GetEnemyState);
	bool Weapon_Pistol(std::string WeaponIndex);
	bool Weapon_IsAR(std::string WeaponIndex);
	bool Weapon_IsSMG(std::string WeaponIndex);
	bool Weapon_IsOther(std::string WeaponIndex);
	bool Weapon_IsSniper(std::string WeaponIndex);
	bool Weapon_ShotGun(std::string WeaponIndex);
	bool Weapon_IsGrenade(std::string WeaponIndex);
	bool ItemRifle(std::string Type);
	bool ItemMaterial(std::string Type);
	bool ItemScops(std::string Type);
	bool ItemShotgun(std::string Type);
	bool ItemSmg(std::string Type);
	bool ItemSniper(std::string Type);
	bool ItemOther(std::string Type);
	bool ItemBicycle(std::string Type);
	bool ItemSpecial(std::string Type);
	bool ItemArmor(std::string Type);
	bool ItemHelmet(std::string Type);
	bool ItemBag(std::string Type);
	bool ItemEnergy(std::string Type);
	bool ItemGrenade(std::string Type);
	void AddItemName(std::string id, char* pCN, char* pEN, char* pTexture);
	void InitItemName();
	std::string GetBoxItems(int code);

}



