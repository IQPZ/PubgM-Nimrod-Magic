#pragma once
extern ImFont* m_FVisuals;
extern ImFont* m_WeaponsFont;
extern ImFont* bold;
extern ImFont* weapons;
//Flags Structs
struct FlagsData {
	char Item_Game_Name[60] = { '\0' };
	GLuint Item_texture;

};
class FLAGS
{
public:
	FLAGS() {};
	int Count = 0;
	FlagsData Flaggs[500];
};

namespace Icons
{
	extern GLuint Background_info;
	extern GLuint Logo;
	extern GLuint Pills_Pickup;
	extern GLuint Firstaid_Pickup;
	extern GLuint FirstAidbox_Pickup;
	extern GLuint Injection_Pickup;
	extern GLuint PickUp_BP_Bike;
	extern GLuint PickUp_BP_Helmet_Lv2_B;
	extern GLuint PickUp_BP_Helmet_Lv3_B;
	extern GLuint PickUp_BP_Bag_Lv3_B;
	extern GLuint PickUp_BP_Bag_Lv2_B;
	extern GLuint PickUp_BP_Armor_Lv3;
	extern GLuint PickUp_BP_Armor_Lv2;
	extern GLuint BP_WB_Vertical_Pickup;
	extern GLuint BP_Sniper_Mosin_Wrapper;
	extern GLuint BP_Sniper_AMR_Wrapper;
	extern GLuint BP_Sniper_SKS_Wrapper;
	extern GLuint BP_Sniper_Mk14_Wrapper;
	extern GLuint BP_Sniper_AWM_Wrapper;
	extern GLuint BP_Sniper_Kar98k_Wrapper;
	extern GLuint BP_Sniper_M24_Wrapper;
	extern GLuint BP_Rifle_SCAR_Wrapper;
	extern GLuint BP_Rifle_Groza_Wrapper;
	extern GLuint BP_Rifle_M416_Wrapper;
	extern GLuint BP_Rifle_M762_Wrapper;
	extern GLuint BP_Rifle_AKM_Wrapper;
	extern GLuint BP_Rifle_AUG_Wrapper;
	extern GLuint BP_Rifle_G36_Wrapper;
	extern GLuint BP_ShotGun_DP12_Wrapper;
	extern GLuint BP_QT_A_Pickup;
	extern GLuint BP_QK_Large_Compensator_Pickup;
	extern GLuint BP_QK_Large_Suppressor_Pickup;
	extern GLuint BP_MZJ_6X_Pickup;
	extern GLuint BP_MZJ_8X_Pickup;
	extern GLuint BP_Other_DP28_Wrapper;
	extern GLuint BP_Other_MG3_Wrapper;
	extern GLuint BP_Other_M249_Wrapper;
	extern GLuint BP_MachineGun_Uzi_Wrapper;
	extern GLuint BP_MachineGun_UMP9_Wrapper;
	extern GLuint BP_MZJ_3X_Pickup;
	extern GLuint BP_MZJ_4X_Pickup;
	extern GLuint BP_MachineGun_MP5K_Wrapper;
	extern GLuint BP_MachineGun_PP19_Wrapper;
	extern GLuint BP_Grenade_Burn_Weapon_Wrapper;
	extern GLuint BP_Grenade_Shoulei_Weapon_Wrapper;
	extern GLuint BP_Grenade_Smoke_Weapon_Wrapper;
	extern GLuint BP_Grenade_Stun_Weapon_Wrapper;
	extern GLuint BP_Grenade_EmergencyCall_Weapon_Wrapper;
	extern GLuint BP_DJ_Large_EQ_Pickup;
	extern GLuint BP_Pistol_Flaregun_Wrapper;
	extern GLuint GoldenTokenWrapper;
	extern GLuint SecurityCard;

	extern GLuint DeadBox;
	extern GLuint Drop;

}

namespace GL3
{

	extern void InitImGui(GLFWwindow* hWindow);
	extern void GL3Render(GLFWwindow* hWindow);
	extern void release(GLFWwindow* hWindow);

}

extern FLAGS* Flags;
