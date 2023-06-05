#pragma once


namespace apiinfo
{
	extern std::string user;
	extern 	std::string _expire;
	extern 	std::string NumOnlineUsers;
}

namespace securehwid
{

}
namespace Share
{
	extern float AimFov;
	extern int distance;
	extern bool E_Magic;

}
namespace Settings
{
	namespace Aimbot
	{
		extern bool enable;
		extern int aimmode;
		extern int mode;
		extern bool prediction;

		extern bool drawfov;
		extern bool drawhitbox;
		extern int hitboxtype;
		extern bool aimknocked;
		extern bool unlockmagiclegit;
		namespace PistolConfig
		{
			extern bool enable;
			extern bool autolock;
			extern float fov;
			extern bool recoil;
			extern float compesation;
			extern float smooth;
			extern bool legitaim;
			extern int hitbox;
			extern int distance;
			extern int aimkey;

			namespace PerfectHit
			{
				extern int Start;
				extern int End;
			}
		}
		namespace ARConfig
		{
			extern bool enable;
			extern bool autolock;
			extern float fov;
			extern bool recoil;
			extern float compesation;
			extern float smooth;
			extern bool legitaim;
			extern int hitbox;
			extern int distance;
			extern int aimkey;

			namespace PerfectHit
			{
				extern int Start;
				extern int End;
			}
		}
		namespace SMGConfig
		{
			extern bool enable;
			extern bool autolock;
			extern float fov;
			extern bool recoil;
			extern float compesation;
			extern float smooth;
			extern bool legitaim;
			extern int hitbox;
			extern int distance;
			extern int aimkey;

			namespace PerfectHit
			{
				extern int Start;
				extern int End;
			}
		}
		namespace SniperConfig
		{
			extern bool enable;
			extern bool autolock;
			extern float fov;
			extern bool recoil;
			extern float compesation;
			extern float smooth;
			extern bool legitaim ;
			extern int hitbox;
			extern int distance;
			extern int aimkey;

			namespace PerfectHit
			{
				extern int Start;
				extern int End;
			}
		}
		namespace ShotGunConfig
		{
			extern bool enable;
			extern bool autolock;
			extern float fov;
			extern bool recoil;
			extern float compesation;
			extern float smooth;
			extern bool legitaim;
			extern int hitbox;
			extern int distance;
			extern int aimkey;

			namespace PerfectHit
			{
				extern int Start;
				extern int End;
			}
		}
		namespace LMGConfig
		{
			extern bool enable;
			extern bool autolock;
			extern float fov;
			extern bool recoil;
			extern float compesation;
			extern float smooth;
			extern bool legitaim;
			extern int hitbox;
			extern int distance;
			extern int aimkey;

			namespace PerfectHit
			{
				extern int Start;
				extern int End;
			}
		}
	}
	namespace ESP
	{
		namespace Players
		{
			namespace Team
			{
				extern bool directionLine;
				extern bool name;
				extern bool boxes;
				extern bool distance;
				extern bool nation;
				extern bool status;
				extern bool snaplines;
				extern bool health;
				extern bool weapon;
				extern bool filledbox;
				extern bool skeleton;
				extern bool offscreen;
				extern bool prediction;
				extern bool spot;
				extern bool WeaponWarning;

			}
			namespace Enemy
			{
				extern bool directionLine;
				extern bool name;
				extern bool boxes;
				extern bool distance;
				extern bool nation;
				extern bool status;
				extern bool snaplines;
				extern bool health;
				extern bool weapon;
				extern bool filledbox;
				extern bool skeleton;
				extern bool offscreen;
				extern bool prediction;
				extern bool spot;
				extern bool WeaponWarning;
			}

		}
		namespace Loot
		{
			extern bool lootspecial ;
			extern bool lootarweapon ;
			extern bool lootsmgweapon ;
			extern bool lootsniperweapon ;
			extern bool loothelmet ;
			extern bool lootarmor ;
			extern bool lootbackpack ;
			extern bool lootshotgun;
			extern bool lootscopes ;
			extern bool lootother ;
			extern bool lootaccessories ;
			extern bool lootenergy ;
			extern bool lootgrenade ;
			extern bool lootbicycle;

		}
		namespace Vehicle
		{
			extern bool vehicleName;
			extern bool vehicleWheelDamaged;
			extern bool vehicleOil;
			extern bool vehicleHP;
			extern bool vehicleBox;
			extern bool vehicleDirectionLine;
			extern bool vehiclePrediction;

		}
		namespace Inventory
		{
			extern bool Deadbox;
			extern bool AirDrop;
			extern bool TreasureChest;
			extern bool InventoryDetails;

		}
		namespace Other
		{
			extern bool redzone;
			extern bool EspGrenade;
			extern bool vehicleExplosionWarning;
		}
		namespace Options
		{
			extern bool colorbyteamid;
			extern int boxtype;
			extern int healthbartype;
			extern int Nationtype;
			extern int DirectionLineSize;
			extern int VehicleDirectionLineSize;
			extern int offscreen_range;
			extern int max_distance_offscreen;
			extern int playersdis;
			extern int vehiclesdis;
			extern bool esp_Outline;
			extern int predictiontype;
			extern int predictiontype2;
			extern int loottype;
			extern int iconwidth;
			extern int iconheight;
			extern int GrenadeType;
			extern bool FightMode;
			extern int FightModeKey;

			extern int FixAim;

			extern float Boxthickness;
			extern float snaplinesthickness;
			extern float Skeletonthickness;
			extern int PlayerNameSize;

			extern int ESPStyle;


		}
	}
	namespace Radar
	{
		extern bool enable;
		extern bool teamRadar;
		extern bool enemyRadar;
		extern bool vehicleRadar;
		extern bool airdropRadar;

		extern int radartype;
		extern int distance_Radar;

	}
	namespace Micro
	{
		namespace AR
		{
			extern bool micro_Iron;
			extern bool micro_RedDot;
			extern bool micro_X2;
			extern bool micro_X3;
			extern bool micro_X4;
			extern FVector2D microaxis_Iron;
			extern FVector2D microaxis_RedDot;
			extern FVector2D microaxis_X2;
			extern FVector2D microaxis_X3;
			extern FVector2D microaxis_X4;

		}
		namespace SMG
		{
			extern bool micro_Iron;
			extern bool micro_RedDot;
			extern bool micro_X2;
			extern bool micro_X3;
			extern bool micro_X4;
			extern FVector2D microaxis_Iron;
			extern FVector2D microaxis_RedDot;
			extern FVector2D microaxis_X2;
			extern FVector2D microaxis_X3;
			extern FVector2D microaxis_X4;

		}
		namespace LMG
		{
			extern bool micro_Iron;
			extern bool micro_RedDot;
			extern bool micro_X2;
			extern bool micro_X3;
			extern bool micro_X4;
			extern FVector2D microaxis_Iron;
			extern FVector2D microaxis_RedDot;
			extern FVector2D microaxis_X2;
			extern FVector2D microaxis_X3;
			extern FVector2D microaxis_X4;

		}

	}
	namespace Crosshair
	{
		extern bool c_enable;
		extern int crosshair;
		extern float size;
		extern float stroke;
	}
	namespace Screen
	{
		extern bool PlayerAiming;
		extern bool TotalPlayers;
		extern bool ServerInfo;

	}
	namespace Color
	{
		extern float rainbow;
		namespace Players
		{
			
				namespace Team
				{
					extern float box[3];
					extern float snapline[3];
					extern float skeleton[3];
					extern float directionLine[3];
					extern float knocked[3];
					extern float spot[3];
					extern float weaponwarning[3];

				}
				namespace Enemy
				{
					extern float box[3] ;
					extern float snapline[3];
					extern float skeleton[3];
					extern float directionLine[3];
					extern float knocked[3];
					extern float spot[3];
					extern float weaponwarning[3];
				}
				namespace Bot
				{
					extern float box[3];
					extern float snapline[3];
					extern float skeleton[3];
					extern float directionLine[3];
					extern float knocked[3];
					extern float spot[3];
					extern float weaponwarning[3];
				}

		}
		namespace Loot
		{
			extern float special[3];
			extern float ar[3];
			extern float smg[3];
			extern float sniper[3];
			extern float helmet[3];
			extern float armor[3];
			extern float backpack[3];
			extern float scopes[3];
			extern float shotgun[3];
			extern float other[3];
			extern float accessories[3];
			extern float energy[3];
			extern float grenade[3];
			extern float bicycle[3];

		}
		namespace Vehicle
		{
			extern float Name[3];
			extern float Box[3];
			extern float DirectionLine[3];
			extern float velocity[3];
		}
		namespace Radar
		{
			extern float Enemy[3];
			extern float Team[3];
			extern float BOT[3];
			extern float Vehicle[3];
			extern float AirDrop[3];

		}
		namespace Crosshair
		{
			extern float crosshair[3];

		}
		namespace Other
		{
			extern float deadbox[3];
			extern float AirDrop[3];
			extern float treasurechest[3];
			extern float InventoryDetails[3];

		}
		namespace Menu
		{
			extern float color[3];
		}
	}
	namespace Setting
	{
		extern bool vsync;
		extern int fps;
	}
	namespace Menu
	{
		extern bool chroma_menu;
		extern bool drawdots;
		extern bool watermark;

	}
	namespace UI
	{
		extern int tab_aimbot;
		extern int player_esp;
		extern int vehicle_esp;
		extern int items_esp;
		extern int other_esp;
		extern int micro_weapon;
		extern int micro_scope;
		extern int colors_players;
		extern int colors_vehicle;
		extern int colors_items;
		extern int colors_radar;

	}
}

