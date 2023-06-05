#include "Includes.h"

namespace apiinfo
{
	std::string user = "";
	std::string _expire = "";
	std::string NumOnlineUsers = "";

}
namespace securehwid
{

}
namespace Share
{
	float AimFov = 0;
	int distance = 250;
	bool E_Magic = false;

}
namespace Settings
{
	namespace Aimbot
	{
		bool enable = false;
		int aimmode = 0;
		int mode = 0;
		bool prediction = false;

		bool drawfov = false;
		bool drawhitbox = false;
		int hitboxtype = 0;
		bool aimknocked = false;
		bool unlockmagiclegit = false;
		namespace PistolConfig
		{
			bool enable = false;
			bool autolock = false;
			float fov = 15;
			bool recoil = false ;
			float compesation = 0;
			float smooth = 30;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 250;
			int aimkey = 1;

			namespace PerfectHit
			{
				int Start = 5;
				int End = 16;
			}
		}
		namespace ARConfig
		{
			bool enable = false;
			bool autolock = false;
			float fov = 15;
			bool recoil = false;
			float compesation = 0;
			float smooth = 30;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 250;
			int aimkey = 1;

			namespace PerfectHit
			{
				int Start = 5;
				int End = 16;
			}
		}
		namespace SMGConfig
		{
			bool enable = false;
			bool autolock = false;
			float fov = 15;
			bool recoil = false;
			float compesation = 0;
			float smooth = 30;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 250;
			int aimkey = 1;

			namespace PerfectHit
			{
				int Start = 5;
				int End = 16;
			}
		}
		namespace SniperConfig
		{
			 bool enable = false;
			 bool autolock = false;
			 float fov = 15;
			 bool recoil = false;
			 float compesation = 0;
			 float smooth = 30;
			 bool legitaim = false;
			 int hitbox = 0;
			 int distance = 250;
			 int aimkey = 1;

			 namespace PerfectHit
			 {
				 int Start = 5;
				 int End = 16;
			 }
		}
		namespace ShotGunConfig
		{
			bool enable = false;
			bool autolock = false;
			float fov = 15;
			bool recoil = false;
			float compesation = 0;
			float smooth = 30;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 250;
			int aimkey = 1;

			namespace PerfectHit
			{
				int Start = 5;
				int End = 16;
			}
		}
		namespace LMGConfig
		{
			bool enable = false;
			bool autolock = false;
			float fov = 15;
			bool recoil = false;
			float compesation = 0;
			float smooth = 30;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 250;
			int aimkey = 1;
			namespace PerfectHit
			{
				int Start = 5;
				int End = 16;
			}
		}
	}
	namespace ESP
	{

		namespace Players
		{

			namespace Team
			{
				bool directionLine = false;
				bool name = false;
				bool boxes = false;
				bool distance = false;
				bool nation = false;
				bool status = false;
				bool snaplines = false;
				bool health = false;
				bool weapon = false;
				bool filledbox = false;
				bool skeleton = false;
				bool offscreen = false;
				bool prediction = false;
				bool spot = false;
				bool WeaponWarning = false;
			}
			namespace Enemy
			{
				bool directionLine = false;
				bool name = false;
				bool boxes = false;
				bool distance = true;
				bool nation = false;
				bool status = false;
				bool snaplines = false;
				bool health = false;
				bool weapon = false;
				bool filledbox = false;
				bool skeleton = false;
				bool offscreen = false;
				bool prediction = false;
				bool spot = false;
				bool WeaponWarning = false;

			}

		}
		namespace Loot
		{
			bool lootspecial = false;
			bool lootarweapon = false;
			bool lootsmgweapon = false;
			bool lootsniperweapon = false;
			bool loothelmet = false;
			bool lootarmor = false;
			bool lootbackpack = false;
			bool lootscopes = false;
			bool lootshotgun = false;
			bool lootother = false;
			bool lootaccessories = false;
			bool lootenergy = false;
			bool lootgrenade = false;
			bool lootbicycle = false;

		}
		namespace Vehicle
		{
			bool vehicleName = false;
			bool vehicleWheelDamaged = false;
			bool vehicleOil = false;
			bool vehicleHP = false;
			bool vehicleBox = false;
			bool vehicleDirectionLine = false;
			bool vehiclePrediction = false;
		}
		namespace Inventory
		{
			bool Deadbox = false;
			bool AirDrop = false;
			bool TreasureChest = false;
			bool InventoryDetails = false;

		}
		namespace Other
		{
			bool redzone = false;
			bool EspGrenade = false;
			bool vehicleExplosionWarning = false;

		}
		namespace Options
		{
			bool colorbyteamid = false;
			int boxtype = 0;
			int healthbartype = 0;
			int Nationtype = 0;
			int DirectionLineSize = 500;
		    int VehicleDirectionLineSize = 500;
			int offscreen_range = 100;
			int max_distance_offscreen = 400;
			int playersdis = 400;
			int vehiclesdis = 600;
			bool esp_Outline = false;
			int predictiontype = 0;
			int predictiontype2 = 0;
			int loottype = 0;
			int iconwidth = 32;
			int iconheight = 32;
			int GrenadeType = 1;
			bool FightMode = false;
			int FightModeKey = 0;

			float Boxthickness = 1.f;
			float snaplinesthickness = 1.f;
			float Skeletonthickness = 1.f;
			int PlayerNameSize = 14;

			int ESPStyle = 1;

		}
	}
	namespace Micro
	{
		namespace AR
		{
			bool micro_Iron = false;
			bool micro_RedDot = false;
			bool micro_X2 = false;
			bool micro_X3 = false;
			bool micro_X4 = false;
			FVector2D microaxis_Iron = {};
			FVector2D microaxis_RedDot = {};
			FVector2D microaxis_X2 = {};
			FVector2D microaxis_X3 = {};
			FVector2D microaxis_X4 = {};

		}
		namespace SMG
		{
			bool micro_Iron = false;
			bool micro_RedDot = false;
			bool micro_X2 = false;
			bool micro_X3 = false;
			bool micro_X4 = false;
			FVector2D microaxis_Iron = {};
			FVector2D microaxis_RedDot = {};
			FVector2D microaxis_X2 = {};
			FVector2D microaxis_X3 = {};
			FVector2D microaxis_X4 = {};

		}
		namespace LMG
		{
			bool micro_Iron = false;
			bool micro_RedDot = false;
			bool micro_X2 = false;
			bool micro_X3 = false;
			bool micro_X4 = false;
			FVector2D microaxis_Iron = {};
			FVector2D microaxis_RedDot = {};
			FVector2D microaxis_X2 = {};
			FVector2D microaxis_X3 = {};
			FVector2D microaxis_X4 = {};

		}

	}
	namespace Radar
	{
		bool enable = false;
		bool teamRadar = false;
		bool enemyRadar = false;
		bool vehicleRadar = false;
		bool airdropRadar = false;

		int radartype = 0;
		int distance_Radar = 600;

	}
	namespace Crosshair
	{
		bool c_enable = false;
		int crosshair = 6;
		float size = 0;
		float stroke = 0;
	}
	namespace Screen
	{
		bool PlayerAiming = false;
		bool TotalPlayers = false;
		bool ServerInfo = false;

	}
	namespace Color
	{
		float rainbow = 0.f;
		namespace Players
		{
			namespace Team
			{
				float box[3] = { 0.f, 0.f, 1.f };
				float snapline[3] = { 0.f, 0.f, 1.f };
				float skeleton[3] = { 0.f, 0.f, 1.f };
				float directionLine[3] = { 0.f, 0.f, 1.f };
				float knocked[3] = { 1.f, 1.f, 1.f };
				float spot[3] = { 1.f, 0.f, 0.f };
				float weaponwarning[3] = { 1.f, 0.f, 0.f };

			}
			namespace Enemy
			{
				float box[3] = { 1.f, 1.f, 0.f };
				float snapline[3] = { 1.f, 1.f, 0.f };
				float skeleton[3] = { 1.f, 1.f, 0.f };
				float directionLine[3] = { 1.f, 1.f, 0.f };
				float knocked[3] = { 1.f, 1.f, 1.f };
				float spot[3] = { 1.f, 0.f, 0.f };
				float weaponwarning[3] = { .49f, 0.f, 1.f };

			}

			namespace Bot
			{
				float box[3] = { 1.f, 1.f, 1.f };
				float snapline[3] = { 1.f, 1.f, 1.f };
				float skeleton[3] = { 1.f, 1.f, 1.f };
				float directionLine[3] = { 1.f, 1.f, 1.f };
				float knocked[3] = { 1.f, 1.f, 1.f };
				float spot[3] = { 1.f, 0.f, 0.f };
				float weaponwarning[3] = { 1.f, 0.f, 0.f };
			}
		}
		namespace Loot
		{
			float special[3] = { 1.f, 0.f, 0.f };
			float ar[3] = { 0.f, 1.f, 0.f };
			float smg[3] = { 1.f, .64f, 0.f };
			float sniper[3] = { 1.f, .27, 0.f };
			float helmet[3] = { 1.f, 1.f, 0.f};
			float armor[3] = { 1.f, 1.f, 0.f };
			float backpack[3] = { 1.f, 1.f, 0.f };
			float scopes[3] = { 1.f, 0.f, 1.f };
			float shotgun[3] = { .75f, .75f, .75f };
			float other[3] = { .50, .50, 0.f };
			float accessories[3] = { .75f, .75f, .75f };
			float energy[3] = { 1.f, 1.f, 1.f };
			float grenade[3] = { 0.8f, 0.4f, 0.f };
			float bicycle[3] = { 0.f, 1.f, 1.f };

		}
		namespace Vehicle
		{
			float Name[3] = { 1.f, .64, 0.f };
			float Box[3] = { 1.f, .64, 0.f };
			float DirectionLine[3] = { 1.f, .64, 0.f };
			float velocity[3] = { 1.f, 0, 0.f };
		}
		namespace Radar
		{
			float Enemy[3] = { 1.f, 1.f, 0.f };
			float Team[3] = { 0.f, 0.f, 1.f };
			float BOT[3] = { 1.f, 1.f, 1.f };
			float Vehicle[3] = { 1.f, 0.f,0.f };
			float AirDrop[3] = { 0.f, 0.f,1.f };

		}
		namespace Crosshair
		{
			float crosshair[3] = { 0.f, 1.f, 0.f};
		}
		namespace Other
		{
			float deadbox[3] = { 1.f, 1.f, 1.f };
			float AirDrop[3] = { 0.f, 0.f, 1.f };
			float treasurechest[3] = { .83f, .68f, .21f };
			float InventoryDetails[3] = { 1.f, 1.f, 0.f };
		}
		namespace Menu
		{
			float color[3] = { 1.f, 0.f, 0.f };
		}
	
	}
	namespace Setting
	{
		bool vsync = true;
		int fps = 1;
	}
	namespace Menu
	{
		bool chroma_menu = false;
		bool drawdots = false;
		bool watermark = true;

	}
	namespace UI
	{
		int tab_aimbot = 0;
		int player_esp = 0;
		int vehicle_esp = 0;
		int items_esp = 0;
		int other_esp = 0;
		int micro_weapon = 0;
		int micro_scope = 0;
		int colors_players = 0;
		int colors_vehicle = 0;
		int colors_items = 0;
		int colors_radar = 0;
	}

}