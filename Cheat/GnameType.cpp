#include "Includes.h"

namespace GnameType
{
	bool isPlayer(std::string type)
	{
		if (type == xorstr_("BP_PlayerCharacter_Dinosaur_C")
			|| type == xorstr_("BP_PlayerPawn_Dinosaur_Livik_C")
			|| type == xorstr_("BP_PlayerPawn_C")
			|| type == xorstr_("BP_PlayerPawn_AI_C")
			|| type == xorstr_("BP_PlayerPawn_FM_C")
			|| type == xorstr_("BP_PlayerPawn_FM_Bot_C")
			|| type == xorstr_("BP_PlayerCharacter_SlayTheBot_AI_C")
			|| type == xorstr_("BP_PlayerCharacter_TeamDeathAllMatch_C")
			|| type == xorstr_("BP_PlayerCharacter_FourMaps_TeamDeathAllMatch_C")
			|| type == xorstr_("BP_PlayerPawn_FM_AI_C")
			|| type == xorstr_("BP_PlayerPawn_SI_C")
			|| type == xorstr_("BP_PlayerPawn_ST_C")
			|| type == xorstr_("BP_PlayerPawn_ST_AI_C")
			|| type == xorstr_("BP_PlayerPawn_Heavy_C")
			|| type == xorstr_("BP_PlayerPawn_XT_C")
			|| type == xorstr_("BP_PlayerPawn_TDM_TPP_8v8_C")
			|| type == xorstr_("BP_PlayerPawn_TDM_TPP_C")
			|| type == xorstr_("BP_PlayerCharacter_BRTDM_C")
			|| type == xorstr_("BP_PlayerCharacter_SanHok_BRTDM_C")
			|| type == xorstr_("BP_PlayerCharacter_FourMap_BRTDM_C")
			|| type == xorstr_("BP_PlayerCharacter_EastAsiaRolePlay_C")
			|| type == xorstr_("BP_PlayerCharacter_Borderland_C")
			|| type == xorstr_("BP_PlayerCharacter_EastAsia_LivikRolePlay_C")
			|| type == xorstr_("BP_PlayerCharacter_Sink_Revival_C")
			|| type == xorstr_("BP_PlayerPawn_Sink_AI_C")
			|| type == xorstr_("BP_PlayerPawn_HT_AI_C")
			|| type == xorstr_("BP_PlayerCharacter_ZNQ5th_C")
			|| type == xorstr_("BP_PlayerCharacter_ZNQ5th_Livik_C")
			|| type == xorstr_("BP_PlayerCharacter_CreativeMode_C")
			|| type == xorstr_("BP_PlayerCharacter_ZNQ5thRolePlay_C")
			|| type == xorstr_("BP_PlayerCharacter_ZNQ5thRolePlay_Livik_C")
			)
			return true;
		else
			return false;
		return false;
	}
	bool IsAirAttackBomb(std::string WeaponIndex)
	{

		if (WeaponIndex == xorstr_("AirAttackBomb_C"))
			return true;
		else
			return false;
		return false;
	}
	bool IsDeathbox(std::string WeaponIndex)
	{

		if (WeaponIndex == xorstr_("PickUpListWrapperActor"))
			return true;
		else
			return false;
		return false;
	}
	bool IsAirDropList(std::string WeaponIndex)
	{
		if (WeaponIndex == xorstr_("AirDropListWrapperActor"))
			return true;
		else
			return false;
		return false;
	}
	bool IsAirDropBox(std::string WeaponIndex)
	{
		if (WeaponIndex == xorstr_("BP_AirDropBox_New_C") || WeaponIndex == xorstr_("BP_FootBallAirDropBox_C"))
			return true;
		else
			return false;
		return false;
	}
	bool IsTreasureChest(std::string type)
	{
		if (type == xorstr_("BP_TreasureChestActor_Medicine_C") || type == xorstr_("BP_TreasureChestActor_Gold_C")
			|| type == xorstr_("BP_TreasureChestActor_Weapon_C") || type == xorstr_("BP_WorldCupTreasureBox_MainPoi_C"))
			return true;
		else
			return false;
		return false;
	}
	bool IsVehicle(std::string type)
	{
		if (type == xorstr_("BP_VH_Buggy_2_C") || type == xorstr_("BP_VH_Buggy_C")
			|| type == xorstr_("BP_VH_Buggy_3_C") || type == xorstr_("BP_VH_Buggy_4_C")
			|| type == xorstr_("BP_VH_Buggy_5_C") || type == xorstr_("BP_VH_Buggy_6_C")
			|| type == xorstr_("VH_Dacia_C") || type == xorstr_("VH_Dacia_2_C")
			|| type == xorstr_("VH_Dacia_3_C") || type == xorstr_("VH_Dacia_4_C")
			|| type == xorstr_("VH_UAZ01_C") || type == xorstr_("VH_UAZ02_C")
			|| type == xorstr_("VH_UAZ03_C") || type == xorstr_("PickUp_01_C")
			|| type == xorstr_("PickUp_02_C") || type == xorstr_("PickUp_03_C")
			|| type == xorstr_("PickUp_04_C") || type == xorstr_("PickUp_05_C")
			|| type == xorstr_("PickUp_06_C") || type == xorstr_("PickUp_07_C")
			|| type == xorstr_("PickUp_08_C") || type == xorstr_("PickUp_09_C")
			|| type == xorstr_("PickUp_10_C") || type == xorstr_("VH_MiniBus_01_C")
			|| type == xorstr_("VH_MiniBus_02_C") || type == xorstr_("VH_MiniBus_03_C")
			|| type == xorstr_("Mirado_open_1_C") || type == xorstr_("Mirado_open_2_C")
			|| type == xorstr_("Mirado_open_3_C") || type == xorstr_("Mirado_open_4_C")
			|| type == xorstr_("Mirado_open_Golden_C") || type == xorstr_("Mirado_close_1_C")
			|| type == xorstr_("Mirado_close_2_C") || type == xorstr_("Mirado_close_3_C")
			|| type == xorstr_("Mirado_close_4_C") || type == xorstr_("VH_Scooter1_C")
			|| type == xorstr_("VH_Scooter2_C") || type == xorstr_("VH_Scooter3_C")
			|| type == xorstr_("Rony_1_C") || type == xorstr_("Rony_2_C")
			|| type == xorstr_("Rony_3_C") || type == xorstr_("LadaNiva_01_C")
			|| type == xorstr_("LadaNiva_02_C") || type == xorstr_("VH_Motorcycle_C")
			|| type == xorstr_("VH_Motorcycle_1_C") || type == xorstr_("VH_MotorcycleCart_C")
			|| type == xorstr_("VH_MotorcycleCart_1_C") || type == xorstr_("VH_Motorglider_C")
			|| type == xorstr_("VH_PG117_C") || type == xorstr_("AquaRail_1_C")
			|| type == xorstr_("water_Plane") || type == xorstr_("VH_Snowbike_C")
			|| type == xorstr_("VH_Snowbile_C") || type == xorstr_("VH_CoupeRB_1_C")
			|| type == xorstr_("BP_VH_Bigfoot_C") || type == xorstr_("VH_BRDM_C")
			|| type == xorstr_("BP_VH_Tuk_1_C") || type == xorstr_("VH_UTV_C")
			|| type == xorstr_("UH60_Vehicle_C") || type == xorstr_("ArmedUAZ_C")
			|| type == xorstr_("ArmedPickupFloat_low_C") || type == xorstr_("ArmedBuggyFloat_low_C")
			|| type == xorstr_("ArmedDacia_low_C") || type == xorstr_("AH6_Vehicle_C")
			|| type == xorstr_("BP_Bike_Pickable_C")
			|| type == xorstr_("BP_MediumTank_C")



			// //cheer park
			|| type == xorstr_("BP_VH_Buggy_SI_C")
			|| type == xorstr_("BP_VH_Tuk_1_SI_C")
			|| type == xorstr_("BP_Bike_WithRack_SI_C")
			|| type == xorstr_("VH_CoupeRB_1_SI_C")
			|| type == xorstr_("VH_Dacia_SI_C")
			|| type == xorstr_("VH_MotorcycleCart_SI_C")
			|| type == xorstr_("VH_Motorcycle_SI_C")
			|| type == xorstr_("VH_Motorglider_SI_C")
			|| type == xorstr_("VH_PG117_SI_C")
			|| type == xorstr_("VH_UAZ01_SI_C")
			|| type == xorstr_("Mirado_open_1_SI_C")
			|| type == xorstr_("VH_Snowmobile_C")
			// training grounds



			//|| type == xorstr_("x")
			//|| type == xorstr_("x")
			//|| type == xorstr_("x")

			)

			return true;
		else
			return false;
		return false;
	}

	bool IsSmokeGrenade(std::string classname)
	{

		if (classname == xorstr_("BP_Grenade_Smoke_C"))
			return true;
		else
			return false;
		return false;
	}
	bool IsBurnGrenade(std::string classname)
	{
		if (classname == xorstr_("BP_Grenade_Burn_C"))
			return true;
		else
			return false;
		return false;
	}
	bool IsShouleiGrenade(std::string classname)
	{

		if (classname == xorstr_("BP_Grenade_Shoulei_C") || classname == xorstr_("BP_Grenade_Shoulei_WithTips_C"))
			return true;
		else
			return false;
		return false;
	}
	bool IsStunGrenade(std::string classname)
	{
		if (classname == xorstr_("BP_Grenade_Stun_C"))
			return true;
		else
			return false;
		return false;
	}
	std::string TreasureChest(std::string str)
	{
		if (str == xorstr_("BP_TreasureChestActor_Medicine_C"))
			return "Medicine Chest";
		else if (str == xorstr_("BP_TreasureChestActor_Gold_C"))
			return "Gold Chest";
		else if (str == xorstr_("BP_TreasureChestActor_Weapon_C"))
			return "Weapon Chest";
		else if (str == xorstr_("BP_WorldCupTreasureBox_MainPoi_C"))
			return "MainPoi";
		else
			return "Unknow Chest";

		return "";
	}
	std::string PlayerGrenade(std::string str)
	{
		if (str == xorstr_("BP_Grenade_Smoke_C"))
			return "Smoke";
		else if (str == xorstr_("BP_Grenade_Burn_C"))
			return "Burn";
		else if (str == xorstr_("BP_Grenade_Stun_C"))
			return "Flash";
		else if (str == xorstr_("BP_Grenade_Shoulei_C") || str == xorstr_("BP_Grenade_Shoulei_WithTips_C"))
			return "Frag";
		else
			return "Unknow";

		return "";
	}
	std::string GetVehicleType(std::string type)
	{
		if (type == xorstr_("BP_VH_Buggy_2_C") || type == xorstr_("BP_VH_Buggy_C")
			|| type == xorstr_("BP_VH_Buggy_3_C") || type == xorstr_("BP_VH_Buggy_4_C")
			|| type == xorstr_("BP_VH_Buggy_5_C") || type == xorstr_("BP_VH_Buggy_6_C")
			|| type == xorstr_("BP_VH_Buggy_SI_C") //cheer park
			|| type == xorstr_("ArmedBuggyFloat_low_C"))

			return "Buggy";
		else if (type == xorstr_("VH_Dacia_2_C") || type == xorstr_("VH_Dacia_C")
			|| type == xorstr_("VH_Dacia_3_C") || type == xorstr_("VH_Dacia_4_C")
			|| type == xorstr_("VH_Dacia_SI_C") || type == xorstr_("VH_Dacia_C") //cheer park - training grounds
			|| type == xorstr_("ArmedDacia_low_C"))
			return "Dacia";
		else if (type == xorstr_("VH_UAZ02_C") || type == xorstr_("VH_UAZ01_C")
			|| type == xorstr_("VH_UAZ03_C") || type == xorstr_("ArmedUAZ_C"))
			return "UAZ";
		else if (type == xorstr_("Mirado_open_2_C") || type == xorstr_("Mirado_open_1_C")
			|| type == xorstr_("Mirado_open_3_C") || type == xorstr_("Mirado_open_4_C")
			|| type == xorstr_("Mirado_open_Golden_C") || type == xorstr_("Mirado_close_1_C")
			|| type == xorstr_("Mirado_close_2_C") || type == xorstr_("Mirado_close_3_C")
			|| type == xorstr_("VH_UAZ01_SI_C") || type == xorstr_("VH_UAZ01_C")//cheer park - training grounds
			|| type == xorstr_("Mirado_open_1_SI_C") // cheer park
			|| type == xorstr_("Mirado_close_4_C"))
			return "Mirado";
		else if (type == xorstr_("VH_Scooter2_C") || type == xorstr_("VH_Scooter1_C")

			|| type == xorstr_("VH_Scooter3_C"))
			return "Scooter";
		else if (type == xorstr_("VH_MotorcycleCart_C")
			|| type == xorstr_("VH_Scooter_C") || type == xorstr_("VH_MotorcycleCart_SI_C")//training grounds
			|| type == xorstr_("VH_Motorcycle_SI_C")
			|| type == xorstr_("VH_MotorcycleCart_1_C"))
			return "Motorcycle Cart";
		else if (type == xorstr_("Rony_2_C") || type == xorstr_("Rony_1_C")
			|| type == xorstr_("Rony_3_C"))
			return "Rony";
		else if (type == xorstr_("LadaNiva_02_C") || type == xorstr_("LadaNiva_01_C"))
			return "Lada Niva";
		else if (type == xorstr_("PickUp_02_C") || type == xorstr_("PickUp_01_C")
			|| type == xorstr_("PickUp_03_C") || type == xorstr_("PickUp_04_C")
			|| type == xorstr_("PickUp_05_C") || type == xorstr_("PickUp_06_C")
			|| type == xorstr_("PickUp_07_C") || type == xorstr_("PickUp_08_C")
			|| type == xorstr_("PickUp_09_C") || type == xorstr_("PickUp_10_C")
			|| type == xorstr_("ArmedPickupFloat_low_C"))
			return "Pickup";
		else if (type == xorstr_("VH_MiniBus_02_C") || type == xorstr_("VH_MiniBus_01_C")
			|| type == xorstr_("VH_MiniBus_03_C"))
			return "Mini Bus";
		else if (type == xorstr_("VH_Motorcycle_1_C") || type == xorstr_("VH_Motorcycle_C"))
			return "Motorcycle";
		else if (type == xorstr_("VH_Motorglider_SI_C") || type == xorstr_("VH_Motorglider_C"))
			return "Motor Glider";
		else if (type == xorstr_("BP_VH_Bigfoot_C"))
			return "Big Foot";
		else if (type == xorstr_("VH_CoupeRB_1_SI_C") || type == xorstr_("VH_CoupeRB_1_C"))
			return "Coupe RB";
		else if (type == xorstr_("VH_Snowbile_C"))
			return "Snowmobile";
		else if (type == xorstr_("BP_VH_Tuk_1_SI_C") || type == xorstr_("BP_VH_Tuk_1_C"))
			return "Tuk";
		else if (type == xorstr_("VH_BRDM_C"))
			return "BRDM";
		else if (type == xorstr_("VH_Snowbike_C")
			|| type == xorstr_("VH_Snowmobile_C")
			|| type == xorstr_("VH_Snowbike_C"))
			return "Snowbike";
		else if (type == xorstr_("AquaRail_1_C"))
			return "Aqua Rail";
		else if (type == xorstr_("water_Plane"))
			return "Water Plane";
		else if (type == xorstr_("VH_UTV_C"))
			return "UTV";
		else if (type == xorstr_("VH_PG117_SI_C") || type == xorstr_("VH_PG117_C"))
			return "PG117";
		else if (type == xorstr_("UH60_Vehicle_C"))
			return "UH-60";
		else if (type == xorstr_("AH6_Vehicle_C"))
			return "AH-6";
		else if (type == xorstr_("BP_Bike_WithRack_SI_C") || type == xorstr_("BP_Bike_Pickable_C"))
			return "Bicycle";

		else
			return "";
		return "";
	}

	std::string scopes(int fov)
	{
		if (fov == 70 || fov == 75)
			return "Iron";
		else if (fov == 55 || fov == 60)
			return "RedDot";
		else if (fov == 44)
			return "X2";
		else if (fov == 26)
			return "X3";
		else if (fov == 20)
			return "X4";
		else if (fov == 13)
			return "X6";
		else if (fov == 11)
			return "X8";
		else
			return "None";

		return "";
	}
	std::string GetNationName(std::string str)
	{
		if (str == "G1")
			return "Global";

		if (str == "AF")
			return "Afghanistan";

		if (str == "AL")
			return "Albania";

		if (str == "DZ")
			return "Algeria";

		if (str == "AS")
			return "American Samoa";

		if (str == "AD")
			return "Andorra";

		if (str == "AO")
			return "Angola";

		if (str == "AI")
			return "Anguilla";

		if (str == "AQ")
			return "Antarctica";

		if (str == "AG")
			return "Antigua & Barbuda";

		if (str == "AR")
			return "Argentina";

		if (str == "AM")
			return "Armenia";

		if (str == "AW")
			return "Aruba";

		if (str == "AU")
			return "Australia";

		if (str == "AT")
			return "Austria";

		if (str == "AZ")
			return "Azerbaijan";

		if (str == "BS")
			return "Bahamas";

		if (str == "BH")
			return "Bahrain";

		if (str == "BD")
			return "Bangladesh";

		if (str == "BB")
			return "Barbados";

		if (str == "BY")
			return "Belarus";

		if (str == "BE")
			return "Belgium";

		if (str == "BZ")
			return "Belize";

		if (str == "BJ")
			return "Benin";

		if (str == "BM")
			return "Bermuda";

		if (str == "BT")
			return "Bhutan";

		if (str == "BO")
			return "Bolivia";

		if (str == "BQ")
			return "Bonaire";

		if (str == "BA")
			return "Bosnia";

		if (str == "BW")
			return "Botswana";

		if (str == "BV")
			return "Bouvet Island";

		if (str == "BR")
			return "Brazil";

		if (str == "IO")
			return "British Indian";

		if (str == "BN")
			return "Brunei Darussalam";

		if (str == "BG")
			return "Bulgaria";

		if (str == "BF")
			return "Burkina Faso";

		if (str == "BI")
			return "Burundi";

		if (str == "CV")
			return "Cabo Verde";

		if (str == "KH")
			return "Cambodia";

		if (str == "CM")
			return "Cameroon";

		if (str == "CA")
			return "Canada";

		if (str == "KY")
			return "Cayman Islands";

		if (str == "CF")
			return "Cent. African Rep.";

		if (str == "TD")
			return "Chad";

		if (str == "CL")
			return "Chile";

		if (str == "CN")
			return "China";

		if (str == "CX")
			return "Christmas Island";

		if (str == "CC")
			return "Cocos Islands";

		if (str == "CO")
			return "Colombia";

		if (str == "KM")
			return "Comoros";

		if (str == "CD" || str == "CG")
			return "Congo";

		if (str == "CK")
			return "Cook Islands";

		if (str == "CR")
			return "Costa Rica";

		if (str == "HR")
			return "Croatia";

		if (str == "CU")
			return "Cuba";

		if (str == "CW")
			return "Curacao";

		if (str == "CY")
			return "Cyprus";

		if (str == "CZ")
			return "Czechia";

		if (str == "CI")
			return "Cote d Ivoire";

		if (str == "DK")
			return "Denmark";

		if (str == "DJ")
			return "Djibouti";

		if (str == "DM")
			return "Dominica";

		if (str == "DO")
			return "Dominican Republic";

		if (str == "EC")
			return "Ecuador";

		if (str == "EG")
			return "Egypt";

		if (str == "SV")
			return "El Salvador";

		if (str == "GQ")
			return "Equatorial Guinea";

		if (str == "ER")
			return "Eritrea";

		if (str == "EE")
			return "Estonia";

		if (str == "SZ")
			return "Eswatini";

		if (str == "ET")
			return "Ethiopia";

		if (str == "FK")
			return "Falkland Islands";

		if (str == "FO")
			return "Faroe Islands";

		if (str == "FJ")
			return "Fiji";

		if (str == "FI")
			return "Finland";

		if (str == "FR")
			return "France";

		if (str == "GF")
			return "French Guiana";

		if (str == "PF")
			return "French Polynesia";

		if (str == "TF")
			return "French Territories";

		if (str == "GA")
			return "Gabon";

		if (str == "GM")
			return "Gambia";

		if (str == "GE")
			return "Georgia";

		if (str == "DE")
			return "Germany";

		if (str == "GH")
			return "Ghana";

		if (str == "GI")
			return "Gibraltar";

		if (str == "GR")
			return "Greece";

		if (str == "GL")
			return "Greenland";

		if (str == "GD")
			return "Grenada";

		if (str == "GP")
			return "Guadeloupe";

		if (str == "GU")
			return "Guam";

		if (str == "GT")
			return "Guatemala";

		if (str == "GG")
			return "Guernsey";

		if (str == "GN")
			return "Guinea";

		if (str == "GW")
			return "Guinea-Bissau";

		if (str == "GY")
			return "Guyana";

		if (str == "HT")
			return "Haiti";

		if (str == "HM")
			return "McDonald Islands";

		if (str == "VA")
			return "Vatican";

		if (str == "HN")
			return "Honduras";

		if (str == "HK")
			return "Hong Kong";

		if (str == "HU")
			return "Hungary";

		if (str == "JM")
			return "Jamaica";

		if (str == "JP")
			return "Japan";

		if (str == "JE")
			return "Jersey";

		if (str == "JO")
			return "Jordan";

		if (str == "KZ")
			return "Kazakhstan";

		if (str == "KE")
			return "Kenya";

		if (str == "KI")
			return "Kiribati";

		if (str == "KP")
			return "South Korea";

		if (str == "KR")
			return "North Korea";

		if (str == "KW")
			return "Kuwait";

		if (str == "KG")
			return "Kyrgyzstan";

		if (str == "LA")
			return "LP Democratic Rep.";

		if (str == "LV")
			return "Latvia";

		if (str == "LB")
			return "Lebanon";

		if (str == "LS")
			return "Lesotho";

		if (str == "LR")
			return "Liberia";

		if (str == "LY")
			return "Libya";

		if (str == "LI")
			return "Liechtenstein";

		if (str == "LT")
			return "Lithuania";

		if (str == "LU")
			return "Luxembourg";

		if (str == "MO")
			return "Macao";

		if (str == "MG")
			return "Madagascar";

		if (str == "MW")
			return "Malawi";

		if (str == "MY")
			return "Malaysia";

		if (str == "MV")
			return "Maldives";

		if (str == "ML")
			return "Mali";

		if (str == "MT")
			return "Malta";

		if (str == "MH")
			return "Marshall Islands";

		if (str == "MQ")
			return "Martinique";

		if (str == "MR")
			return "Mauritania";

		if (str == "MU")
			return "Mauritius";

		if (str == "YT")
			return "Mayotte";

		if (str == "MX")
			return "Mexico";

		if (str == "FM")
			return "Micronesia";

		if (str == "MD")
			return "Moldova";

		if (str == "MC")
			return "Monaco";

		if (str == "MN")
			return "Mongolia";

		if (str == "ME")
			return "Montenegro";

		if (str == "MS")
			return "Montserrat";

		if (str == "MA")
			return "Morocco";

		if (str == "MZ")
			return "Mozambique";

		if (str == "MM")
			return "Myanmar";

		if (str == "NA")
			return "Namibia";

		if (str == "NR")
			return "Nauru";

		if (str == "NP")
			return "Nepal";

		if (str == "NL")
			return "Netherlands";

		if (str == "NC")
			return "New Caledonia";

		if (str == "NZ")
			return "New Zealand";

		if (str == "NI")
			return "Nicaragua";

		if (str == "NE")
			return "Niger";

		if (str == "NG")
			return "Nigeria";

		if (str == "NU")
			return "Niue";

		if (str == "NF")
			return "Norfolk Island";

		if (str == "MP")
			return "Mariana Islands";

		if (str == "NO")
			return "Norway";

		if (str == "OM")
			return "Oman";

		if (str == "PK")
			return "Pakistan";

		if (str == "PW")
			return "Palau";

		if (str == "PS")
			return "Palestine";

		if (str == "PA")
			return "Panama";

		if (str == "PG")
			return "Papua New Guinea";

		if (str == "PY")
			return "Paraguay";

		if (str == "PE")
			return "Peru";

		if (str == "PH")
			return "Philippines";

		if (str == "PN")
			return "Pitcairn";

		if (str == "PL")
			return "Poland";

		if (str == "PT")
			return "Portugal";

		if (str == "PR")
			return "Puerto Rico";

		if (str == "QA")
			return "Qatar";

		if (str == "MK")
			return "North Macedonia";

		if (str == "RO")
			return "Romania";

		if (str == "RU")
			return "Russia";

		if (str == "RW")
			return "Rwanda";

		if (str == "RE")
			return "Reunion";

		if (str == "BL")
			return "Saint Barthelemy";

		if (str == "SH")
			return "Saint Helena";

		if (str == "KN")
			return "Kitts and Nevis";

		if (str == "LC")
			return "Saint Lucia";

		if (str == "MF")
			return "Saint Martin";

		if (str == "PM")
			return "Saint Pierre";

		if (str == "VC")
			return "Saint Vincent";

		if (str == "WS")
			return "Samoa";

		if (str == "SM")
			return "San Marino";

		if (str == "ST")
			return "Sao Tome";

		if (str == "SA")
			return "Saudi Arabia";

		if (str == "SN")
			return "Senegal";

		if (str == "RS")
			return "Serbia";

		if (str == "SC")
			return "Seychelles";

		if (str == "SL")
			return "Sierra Leone";

		if (str == "SG")
			return "Singapore";

		if (str == "SX")
			return "Sint Maarten";

		if (str == "SK")
			return "Slovakia";

		if (str == "SI")
			return "Slovenia";

		if (str == "SB")
			return "Solomon Islands";

		if (str == "SO")
			return "Somalia";

		if (str == "ZA")
			return "South Africa";

		if (str == "GS")
			return "South Georgia";

		if (str == "SS")
			return "South Sudan";

		if (str == "ES")
			return "Spain";

		if (str == "LK")
			return "Sri Lanka";

		if (str == "SD")
			return "Sudan";

		if (str == "SR")
			return "Suriname";

		if (str == "SJ")
			return "Svalbard";

		if (str == "SE")
			return "Sweden";

		if (str == "CH")
			return "Switzerland";

		if (str == "SY")
			return "Syria";

		if (str == "TW")
			return "Taiwan";

		if (str == "TJ")
			return "Tajikistan";

		if (str == "TZ")
			return "Tanzania";

		if (str == "TH")
			return "Thailand";

		if (str == "TL")
			return "Timor-Leste";

		if (str == "TG")
			return "Togo";

		if (str == "TK")
			return "Tokelau";

		if (str == "TO")
			return "Tonga";

		if (str == "TT")
			return "Trinidad Tobago";

		if (str == "TN")
			return "Tunisia";

		if (str == "TR")
			return "Turkey";

		if (str == "TM")
			return "Turkmenistan";

		if (str == "TC")
			return "Turks & Caicos Islands";

		if (str == "TV")
			return "Tuvalu";

		if (str == "UG")
			return "Uganda";

		if (str == "UA")
			return "Ukraine";

		if (str == "AE")
			return "United Arab Emirates";

		if (str == "G1")
			return "United Kingdom";

		if (str == "GB")
			return "United Kingdom";

		if (str == "US")
			return "America";

		if (str == "UY")
			return "Uruguay";

		if (str == "UZ")
			return "Uzbekistan";

		if (str == "VU")
			return "Vanuatu";

		if (str == "VE")
			return "Venezuela";

		if (str == "VN")
			return "Viet Nam";

		if (str == "VG")
			return "Virgin Islands";

		if (str == "VI")
			return "Virgin Islands";

		if (str == "WF")
			return "Wallis and Futuna";

		if (str == "EH")
			return "Western Sahara";

		if (str == "YE")
			return "Yemen";

		if (str == "ZM")
			return "Zambia";

		if (str == "ZW")
			return "Zimbabwe";

		if (str == "AX")
			return "Aland Islands";

		if (str == "IS")
			return "Iceland";

		if (str == "IN")
			return "India";

		if (str == "ID")
			return "Indonesia";

		if (str == "IR")
			return "Iran";

		if (str == "IQ")
			return "Iraq";

		if (str == "IE")
			return "Ireland";

		if (str == "IM")
			return "Isle of Man";

		if (str == "IL")
			return "Israel";

		if (str == "IT")
			return "Italy";

		return "";
	}

	std::string PlayerWeapon(std::string str)
	{
		if (str == xorstr_("BP_Sniper_AWM_C"))
			return "AWM";
		else if (str == xorstr_("BP_Sniper_QBU_C"))
			return "QBU";
		else if (str == xorstr_("BP_Sniper_SLR_C"))
			return "SLR";
		else if (str == xorstr_("BP_Sniper_SKS_C"))
			return "SKS";
		else if (str == xorstr_("BP_Sniper_Mini14_C"))
			return "Mini14";
		else if (str == xorstr_("BP_Sniper_M24_C"))
			return "M24";
		else if (str == xorstr_("BP_Sniper_Kar98k_C"))
			return "Kar98k";
		else if (str == xorstr_("BP_Sniper_VSS_C"))
			return "VSS";
		else if (str == xorstr_("BP_Sniper_Win94_C"))
			return "Win94";
		else if (str == xorstr_("BP_Sniper_Mosin_C"))
			return "Mosin";
		else if (str == xorstr_("BP_Sniper_MK12_C"))
			return "MK12";
		else if (str == xorstr_("BP_Sniper_Mk14_C"))
			return "Mk14";
		else if (str == xorstr_("BP_Sniper_AMR_C"))
			return "AMR";
		else if (str == xorstr_("BP_Rifle_FAMAS_C"))
			return "FAMAS";
		else if (str == xorstr_("BP_Rifle_AUG_C"))
			return "AUG";
		else if (str == xorstr_("BP_Rifle_M762_C"))
			return "M762";
		else if (str == xorstr_("BP_Rifle_SCAR_C"))
			return "SCAR-L";
		else if (str == xorstr_("BP_Rifle_M416_C"))
			return "M416";
		else if (str == xorstr_("BP_Rifle_HoneyBadger_C"))
			return "HoneyBadger";
		else if (str == xorstr_("BP_Rifle_M16A4_C"))
			return "M16A4";
		else if (str == xorstr_("BP_Rifle_Mk47_C"))
			return "Mk47";
		else if (str == xorstr_("BP_Rifle_G36_C"))
			return "G36C";
		else if (str == xorstr_("BP_Rifle_QBZ_C"))
			return "QBZ";
		else if (str == xorstr_("BP_Rifle_AKM_C"))
			return "AKM";
		else if (str == xorstr_("BP_Rifle_Groza_C"))
			return "Groza";
		else if (str == xorstr_("BP_Other_DP28_C"))
			return "DP28";
		else if (str == xorstr_("BP_Other_HuntingBowEA_C"))
			return "HuntingBowEA";
		else if (str == xorstr_("BP_Other_M249_C"))
			return "M249";
		else if (str == xorstr_("BP_Other_MG3_C"))
			return "MG3";
		else if (str == xorstr_("BP_ShotGun_S12K_C"))
			return "S12K";
		else if (str == xorstr_("BP_ShotGun_DP12_C"))
			return "DP12";
		else if (str == xorstr_("BP_ShotGun_S686_C"))
			return "S686";
		else if (str == xorstr_("BP_ShotGun_S1897_C"))
			return "S1897";
		else if (str == xorstr_("BP_ShotGun_SawedOff_C"))
			return "SawedOff";
		else if (str == xorstr_("BP_ShotGun_Neostead2000_C"))
			return "Neostead2000";
		else if (str == xorstr_("BP_ShotGun_M1014_C"))
			return "M1014";
		else if (str == xorstr_("BP_MachineGun_P90_C"))
			return "P90";
		else if (str == xorstr_("BP_MachineGun_PP19_C"))
			return "PP19";
		else if (str == xorstr_("BP_MachineGun_TommyGun_C"))
			return "TommyGu";
		else if (str == xorstr_("BP_MachineGun_MP5K_C"))
			return "MP5K";
		else if (str == xorstr_("BP_MachineGun_UMP9_C"))
			return "UMP9";
		else if (str == xorstr_("BP_MachineGun_Vector_C"))
			return "Vector";
		else if (str == xorstr_("BP_MachineGun_Uzi_C"))
			return "Uzi";
		else if (str == xorstr_("BP_Pistol_Flaregun_C"))
			return "Flaregun";
		else if (str == xorstr_("BP_Pistol_R1895_C"))
			return "R1895";
		else if (str == xorstr_("BP_Pistol_Vz61_C"))
			return "Vz61";
		else if (str == xorstr_("BP_Pistol_P92_C"))
			return "P92";
		else if (str == xorstr_("BP_Pistol_P18C_C"))
			return "P18C";
		else if (str == xorstr_("BP_Pistol_R45_C"))
			return "R45";
		else if (str == xorstr_("BP_Pistol_P1911_C"))
			return "P1911";
		else if (str == xorstr_("BP_Pistol_DesertEagle_C"))
			return "DesertEagle";
		else if (str == xorstr_("BP_WEP_Mk14_C"))
			return "Mk14";
		else if (str == xorstr_("BP_Other_CrossBow_C"))
			return "CrossBow";
		else if (str == xorstr_("BP_Grenade_Shoulei_Weapon_C"))
			return "Shoulei Grenade";
		else if (str == xorstr_("BP_Grenade_Smoke_Weapon_C"))
			return "Smoke Grenade";
		else if (str == xorstr_("BP_Grenade_Burn_Weapon_C"))
			return "Burn Grenade";
		else
			return "Hands";
		return "";
	}

	std::string PlayerWeaponFont(std::string str)
	{
		if (str == xorstr_("BP_Sniper_AWM_C"))
			return "C";
		else if (str == xorstr_("BP_Sniper_QBU_C"))
			return "j";
		else if (str == xorstr_("BP_Sniper_SLR_C"))
			return "(";
		else if (str == xorstr_("BP_Sniper_SKS_C"))
			return "E";
		else if (str == xorstr_("BP_Sniper_Mini14_C"))
			return "F";
		else if (str == xorstr_("BP_Sniper_M24_C"))
			return "I";
		else if (str == xorstr_("BP_Sniper_Kar98k_C"))
			return "r";
		else if (str == xorstr_("BP_Sniper_VSS_C"))
			return "N";
		else if (str == xorstr_("BP_Sniper_Win94_C"))
			return "l";
		else if (str == xorstr_("BP_Sniper_Mosin_C"))
			return "q";
		else if (str == xorstr_("BP_Sniper_MK12_C"))
			return "p";
		else if (str == xorstr_("BP_Sniper_Mk14_C"))
			return "R";
		else if (str == xorstr_("BP_Sniper_AMR_C"))
			return "D";
		else if (str == xorstr_("BP_Rifle_FAMAS_C"))
			return "k";
		else if (str == xorstr_("BP_Rifle_AUG_C"))
			return "n";
		else if (str == xorstr_("BP_Rifle_M762_C"))
			return "H";
		else if (str == xorstr_("BP_Rifle_SCAR_C"))
			return "J";
		else if (str == xorstr_("BP_Rifle_M416_C"))
			return "A";
		else if (str == xorstr_("BP_Rifle_HoneyBadger_C"))
			return "g";
		else if (str == xorstr_("BP_Rifle_M16A4_C"))
			return "m";
		else if (str == xorstr_("BP_Rifle_Mk47_C"))
			return "i";
		else if (str == xorstr_("BP_Rifle_G36_C"))
			return "y";
		else if (str == xorstr_("BP_Rifle_QBZ_C"))
			return "o";
		else if (str == xorstr_("BP_Rifle_AKM_C"))
			return "B";
		else if (str == xorstr_("BP_Rifle_Groza_C"))
			return "K";
		else if (str == xorstr_("BP_Other_DP28_C"))
			return "L";
		else if (str == xorstr_("BP_Other_M249_C"))
			return "S";
		else if (str == xorstr_("BP_Other_MG3_C"))
			return "T";
		else if (str == xorstr_("BP_ShotGun_S12K_C"))
			return "U";
		else if (str == xorstr_("BP_ShotGun_DP12_C"))
			return "Y";
		else if (str == xorstr_("BP_ShotGun_S686_C"))
			return "W";
		else if (str == xorstr_("BP_ShotGun_S1897_C"))
			return "V";
		else if (str == xorstr_("BP_ShotGun_SawedOff_C"))
			return "X";
		else if (str == xorstr_("BP_ShotGun_Neostead2000_C"))
			return "s";
		else if (str == xorstr_("BP_ShotGun_M1014_C"))
			return "$";
		else if (str == xorstr_("BP_MachineGun_P90_C"))
			return "6";
		else if (str == xorstr_("BP_MachineGun_PP19_C"))
			return "7";
		else if (str == xorstr_("BP_MachineGun_TommyGun_C"))
			return "8";
		else if (str == xorstr_("BP_MachineGun_MP5K_C"))
			return "x";
		else if (str == xorstr_("BP_MachineGun_UMP9_C"))
			return "9";
		else if (str == xorstr_("BP_MachineGun_Vector_C"))
			return "Q";
		else if (str == xorstr_("BP_MachineGun_Uzi_C"))
			return "G";
		else if (str == xorstr_("BP_Pistol_Flaregun_C"))
			return "O";
		else if (str == xorstr_("BP_Pistol_R1895_C"))
			return ">";
		else if (str == xorstr_("BP_Pistol_Vz61_C"))
			return "@";
		else if (str == xorstr_("BP_Pistol_P92_C"))
			return "=";
		else if (str == xorstr_("BP_Pistol_P18C_C"))
			return "Z";
		else if (str == xorstr_("BP_Pistol_R45_C"))
			return ")";
		else if (str == xorstr_("BP_Pistol_P1911_C"))
			return "<";
		else if (str == xorstr_("BP_Pistol_DesertEagle_C"))
			return "W";
		else if (str == xorstr_("BP_WEP_Mk14_C"))
			return "R";
		else if (str == xorstr_("BP_Other_CrossBow_C"))
			return "P";
		else if (str == xorstr_("BP_Grenade_Shoulei_Weapon_C"))
			return "b";
		else if (str == xorstr_("BP_Grenade_Smoke_Weapon_C"))
			return "e";
		else if (str == xorstr_("BP_Grenade_Burn_Weapon_C"))
			return "c";
		else if (str == xorstr_("BP_Grenade_Stun_Weapon_C"))
			return "d";
		else
			return "";

		return "";
	}

	std::string playerstatus(int GetEnemyState)
	{
		switch (GetEnemyState)
		{
		case 0:
			return "AFK";
			break;
		case 1:
			return "In Water";
			break;
		case 268435464:
			return "Play Emotion";
			break;
		case 8:
			return "Stand";
			break;
		case 520:
		case 544:
		case 656:
		case 521:
		case 528:
			return "Aiming";
			break;
		case 1680:
		case 1672:
		case 1673:
		case 1032:
		case 1544:
		case 1545:
		case 1033:
			return "Peek";
			break;
		case 9:
			return "Walking";
			break;
		case 11:
			return "Running";
			break;
		case 4194304:
			return "Swimming";
			break;
		case 32784:
			return "Reviving";
			break;
		case 16777224:
			return "Climbing";
			break;
		case 8200:
		case 8208:
			return "Punching";
			break;
		case 16:
		case 17:
		case 19:
			return "Crouch";
			break;
		case 32:
		case 33:
		case 35:
		case 5445:
		case 762:
			return "Snake";
			break;
		case 72:
		case 73:
		case 75:
			return "Jumping";
			break;
		case 264:
		case 272:
		case 273:
		case 288:
		case 265:
		case 329:
			return "Reloading";
			break;
		case 137:
		case 144:
		case 201:
		case 145:
		case 160:
		case 649:
		case 648:
		case 1160:
		case 1161:
		case 1169:
			return "Firing";
			break;
		case 131070:
		case 131071:
		case 131072:
		case 131073:
		case 131075:
		case 131074:
			return "Knocked";
			break;
		case 33554440:
		case 524296:
		case 1048584:
		case 524288:
			return "Driving";
			break;
		case 16392:
		case 16393:
		case 16401:
		case 16416:
		case 16417:
		case 16457:
		case 16400:
		case 17401:
		case 17417:
		case 17425:
		case 17424:
			return "Throwing Bomb";
			break;
		default:
			return "";
			break;
		}
	}
	bool Weapon_Pistol(std::string WeaponIndex)
	{
		if (WeaponIndex == xorstr_("BP_Pistol_R1895_C") || WeaponIndex == xorstr_("BP_Pistol_Vz61_C")
			|| WeaponIndex == xorstr_("BP_Pistol_P92_C") || WeaponIndex == xorstr_("BP_Pistol_P18C_C")
			|| WeaponIndex == xorstr_("BP_Pistol_R45_C") || WeaponIndex == xorstr_("BP_Pistol_P1911_C")
			|| WeaponIndex == xorstr_("BP_Pistol_DesertEagle_C")
			)
			return true;
		else
			return false;
		return false;
	}
	bool Weapon_IsAR(std::string WeaponIndex)
	{

		if (WeaponIndex == xorstr_("BP_Rifle_AUG_C") || WeaponIndex == xorstr_("BP_Rifle_M762_C")
			|| WeaponIndex == xorstr_("BP_Rifle_SCAR_C") || WeaponIndex == xorstr_("BP_Rifle_M416_C")
			|| WeaponIndex == xorstr_("BP_Rifle_M16A4_C") || WeaponIndex == xorstr_("BP_Rifle_Mk47_C")
			|| WeaponIndex == xorstr_("BP_Rifle_G36_C") || WeaponIndex == xorstr_("BP_Rifle_QBZ_C")
			|| WeaponIndex == xorstr_("BP_Rifle_AKM_C") || WeaponIndex == xorstr_("BP_Rifle_Groza_C")
			|| WeaponIndex == xorstr_("BP_Rifle_FAMAS_C") || WeaponIndex == xorstr_("BP_Rifle_HoneyBadger_C")
			)
			return true;
		else
			return false;
		return false;
	}
	bool Weapon_IsSMG(std::string WeaponIndex)
	{
		if (WeaponIndex == xorstr_("BP_MachineGun_P90_C") || WeaponIndex == xorstr_("BP_MachineGun_PP19_C")
			|| WeaponIndex == xorstr_("BP_MachineGun_TommyGun_C") || WeaponIndex == xorstr_("BP_MachineGun_MP5K_C")
			|| WeaponIndex == xorstr_("BP_MachineGun_UMP9_C") || WeaponIndex == xorstr_("BP_MachineGun_Vector_C")
			|| WeaponIndex == xorstr_("BP_MachineGun_Uzi_C"))
			return true;
		else
			return false;
		return false;
	}
	bool Weapon_IsOther(std::string WeaponIndex)
	{
		if (WeaponIndex == xorstr_("BP_Other_DP28_C") || WeaponIndex == xorstr_("BP_Other_M249_C")
			|| WeaponIndex == xorstr_("BP_Other_CrossBow_C") || WeaponIndex == xorstr_("BP_Other_MG3_C")
			|| WeaponIndex == xorstr_("BP_Other_HuntingBowEA_C"))
			return true;
		else
			return false;
		return false;
	}
	bool Weapon_IsSniper(std::string WeaponIndex)
	{
		if (WeaponIndex == xorstr_("BP_Sniper_AWM_C") || WeaponIndex == xorstr_("BP_Sniper_QBU_C")
			|| WeaponIndex == xorstr_("BP_Sniper_SLR_C") || WeaponIndex == xorstr_("BP_Sniper_SKS_C")
			|| WeaponIndex == xorstr_("BP_Sniper_Mini14_C") || WeaponIndex == xorstr_("BP_Sniper_M24_C")
			|| WeaponIndex == xorstr_("BP_Sniper_Kar98k_C") || WeaponIndex == xorstr_("BP_Sniper_VSS_C")
			|| WeaponIndex == xorstr_("BP_Sniper_Win94_C") || WeaponIndex == xorstr_("BP_Sniper_Mosin_C")
			|| WeaponIndex == xorstr_("BP_Sniper_MK12_C") || WeaponIndex == xorstr_("BP_Sniper_Mk14_C")
			|| WeaponIndex == xorstr_("BP_Sniper_AMR_C"))
			return true;
		else
			return false;
		return false;
	}
	bool Weapon_ShotGun(std::string WeaponIndex)
	{
		if (WeaponIndex == xorstr_("BP_ShotGun_S12K_C") || WeaponIndex == xorstr_("BP_ShotGun_M1014_C")
			|| WeaponIndex == xorstr_("BP_ShotGun_S1897_C") || WeaponIndex == xorstr_("BP_ShotGun_S686_C")
			|| WeaponIndex == xorstr_("BP_ShotGun_SawedOff_C") || WeaponIndex == xorstr_("BP_ShotGun_DP12_C")
			|| WeaponIndex == xorstr_("BP_ShotGun_Neostead2000_Wrapper_C"))
			return true;
		else
			return false;
		return false;
	}
	bool Weapon_IsGrenade(std::string WeaponIndex)
	{

		if (WeaponIndex == xorstr_("BP_Grenade_Shoulei_Weapon_C") || WeaponIndex == xorstr_("BP_Grenade_Smoke_Weapon_C")
			|| WeaponIndex == xorstr_("BP_Grenade_Burn_Weapon_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemRifle(std::string Type)
	{

		if (Type == xorstr_("BP_Rifle_M762_Wrapper_C") || Type == xorstr_("BP_Rifle_SCAR_Wrapper_C")
			|| Type == xorstr_("BP_Rifle_AKM_Wrapper_C") || Type == xorstr_("BP_Rifle_M416_Wrapper_C")
			|| Type == xorstr_("BP_Rifle_G36_Wrapper_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemMaterial(std::string Type)
	{

		if (Type == xorstr_("BP_DJ_Large_EQ_Pickup_C") || Type == xorstr_("BP_QK_Large_Compensator_Pickup_C")
			|| Type == xorstr_("BP_QK_Large_Suppressor_Pickup_C") || Type == xorstr_("BP_WB_Vertical_Pickup_C")
			|| Type == xorstr_("BP_QT_A_Pickup_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemScops(std::string Type)
	{

		if (Type == xorstr_("BP_MZJ_4X_Pickup_C") || Type == xorstr_("BP_MZJ_6X_Pickup_C")
			|| Type == xorstr_("BP_MZJ_8X_Pickup_C") || Type == xorstr_("BP_MZJ_3X_Pickup_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemShotgun(std::string Type)
	{

		if (Type == xorstr_("BP_ShotGun_DP12_Wrapper_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemSmg(std::string Type)
	{

		if (Type == xorstr_("BP_MachineGun_PP19_Wrapper_C") || Type == xorstr_("BP_MachineGun_MP5K_Wrapper_C")
			|| Type == xorstr_("BP_MachineGun_Uzi_Wrapper_C") || Type == xorstr_("BP_MachineGun_UMP9_Wrapper_C")
			)
			return true;
		else
			return false;
		return false;
	}
	bool ItemSniper(std::string Type)
	{
		if (Type == xorstr_("BP_Sniper_AWM_Wrapper_C") || Type == xorstr_("BP_Sniper_Kar98k_Wrapper_C")
			|| Type == xorstr_("BP_Sniper_M24_Wrapper_C") || Type == xorstr_("BP_Sniper_Mosin_Wrapper_C")
			|| Type == xorstr_("BP_Sniper_Mk14_Wrapper_C") || Type == xorstr_("BP_Sniper_AMR_Wrapper_C")
			|| Type == xorstr_("BP_Sniper_SKS_Wrapper_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemOther(std::string Type)
	{

		if (Type == xorstr_("BP_Other_DP28_Wrapper_C") || Type == xorstr_("BP_Other_MG3_Wrapper_C")
			|| Type == xorstr_("BP_Other_M249_Wrapper_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemBicycle(std::string Type)
	{

		if (Type == xorstr_("PickUp_BP_Bike_C") || Type == xorstr_("PickUp_BP_Bike_2_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemSpecial(std::string Type)
	{
		if (Type == xorstr_("GoldenTokenWrapper_C") || Type == xorstr_("SecurityCardWrapper_C")  || Type == xorstr_("BP_Pistol_Flaregun_Wrapper_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemArmor(std::string Type)
	{
		if (Type == xorstr_("PickUp_BP_Armor_Lv3_C") || Type == xorstr_("PickUp_BP_Armor_Lv2_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemHelmet(std::string Type)
	{

		if (Type == xorstr_("PickUp_BP_Helmet_Lv3_C") || Type == xorstr_("PickUp_BP_Helmet_Lv2_C")
			|| Type == xorstr_("PickUp_BP_Helmet_Lv2_B_C") || Type == xorstr_("PickUp_BP_Helmet_Lv3_B_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemBag(std::string Type)
	{
		if (Type == xorstr_("PickUp_BP_Bag_Lv3_C") || Type == xorstr_("PickUp_BP_Bag_Lv3_B_C")
			|| Type == xorstr_("PickUp_BP_Bag_Lv2_C") || Type == xorstr_("PickUp_BP_Bag_Lv2_B"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemEnergy(std::string Type)
	{
		if (Type == xorstr_("Firstaid_Pickup_C") || Type == xorstr_("FirstAidbox_Pickup_C")
			|| Type == xorstr_("Injection_Pickup_C") || Type == xorstr_("Pills_Pickup_C"))
			return true;
		else
			return false;
		return false;
	}
	bool ItemGrenade(std::string Type)
	{

		if (Type == xorstr_("BP_Grenade_Shoulei_Weapon_Wrapper_C") || Type == xorstr_("BP_Grenade_Smoke_Weapon_Wrapper_C")
			|| Type == xorstr_("BP_Grenade_Burn_Weapon_Wrapper_C") || Type == xorstr_("BP_Grenade_EmergencyCall_Weapon_Wrapper_C"))
			return true;
		else
			return false;
		return false;
	}

	std::map<std::string, ITEM_NAME> g_ItemHash = {};

	void AddItemName(std::string id, char* pCN, char* pEN, char* pTexture)
	{
		ITEM_NAME in;
		lstrcpyA(in.szCN, pCN);
		lstrcpyA(in.szEN, pEN);
		lstrcpyA(in.szTexture, pTexture);
		g_ItemHash[id] = in;
	}

	void InitItemName()
	{
		g_ItemHash.clear();
		AddItemName(xorstr_("BP_Rifle_M762_Wrapper_C"), "", "M762", "Rifle_M762_Wrapper");
		AddItemName(xorstr_("BP_Rifle_AKM_Wrapper_C"), "", "AKM", "Rifle_AKM_Wrapper");
		AddItemName(xorstr_("BP_Rifle_SCAR_Wrapper_C"), "", "SCAR", "Rifle_SCAR_Wrapper");
		AddItemName(xorstr_("BP_Rifle_M416_Wrapper_C"), "", "M416", "Rifle_M416_Wrapper");
		AddItemName(xorstr_("BP_Rifle_G36_Wrapper_C"), "", "G36C", "Rifle_G36_Wrapper");

		AddItemName(xorstr_("BP_Sniper_AWM_Wrapper_C"), "", "AWM", "Sniper_AWM_Wrapper");
		AddItemName(xorstr_("BP_Sniper_Kar98k_Wrapper_C"), "", "Kar98k", "Sniper_Kar98k_Wrapper");
		AddItemName(xorstr_("BP_Sniper_M24_Wrapper_C"), "", "M24", "Sniper_M24_Wrapper");
		AddItemName(xorstr_("BP_Sniper_Mosin_Wrapper_C"), "", "Mosin", "Sniper_Mosin_Wrapper");
		AddItemName(xorstr_("BP_Sniper_Mk14_Wrapper_C"), "", "Mk14", "Sniper_Mk14_Wrapper");
		AddItemName(xorstr_("BP_Sniper_AMR_Wrapper_C"), "", "AMR", "Sniper_AMR_Wrapper");
		AddItemName(xorstr_("BP_Sniper_SKS_Wrapper_C"), "", "SKS", "Sniper_SKS_Wrapper");

		AddItemName(xorstr_("BP_Other_DP28_Wrapper_C"), "", "DP28", "Other_DP28_Wrapper");
		AddItemName(xorstr_("BP_Other_M249_Wrapper_C"), "", "M249", "Other_M249_Wrapper");
		AddItemName(xorstr_("BP_Other_MG3_Wrapper_C"), "", "MG3", "Other_MG3_Wrapper");

		AddItemName(xorstr_("BP_MachineGun_PP19_Wrapper_C"), "", "PP19", "MachineGun_PP19_Wrapper");
		AddItemName(xorstr_("BP_MachineGun_MP5K_Wrapper_C"), "", "MP5K", "MachineGun_MP5K_Wrapper");
		AddItemName(xorstr_("BP_MachineGun_Uzi_Wrapper_C"), "", "Uzi", "MachineGun_Uzi_Wrapper");
		AddItemName(xorstr_("BP_MachineGun_UMP9_Wrapper_C"), "", "UMP9", "MachineGun_UMP9_Wrapper");

		AddItemName(xorstr_("BP_ShotGun_DP12_Wrapper_C"), "", "DBS", "ShotGun_DP12_Wrapper");

		AddItemName(xorstr_("PickUp_BP_Armor_Lv3_C"), "", "ArmorLV3", "PickUp_BP_Armor_Lv3");
		AddItemName(xorstr_("PickUp_BP_Armor_Lv2_C"), "", "ArmorLV2", "PickUp_BP_Armor_Lv2");

		AddItemName(xorstr_("PickUp_BP_Helmet_Lv3_C"), "", "HelmetLV3", "PickUp_BP_Helmet_Lv3");
		AddItemName(xorstr_("PickUp_BP_Helmet_Lv3_B_C"), "", "HelmetLV3", "PickUp_BP_Helmet_Lv3");
		AddItemName(xorstr_("PickUp_BP_Helmet_Lv2_B_C"), "", "HelmetLV2", "PickUp_BP_Helmet_Lv2");
		AddItemName(xorstr_("PickUp_BP_Helmet_Lv2_C"), "", "HelmetLV2", "PickUp_BP_Helmet_Lv2");

		AddItemName(xorstr_("BP_MZJ_3X_Pickup_C"), "", "3X", "MZJ_3X_Pickup");
		AddItemName(xorstr_("BP_MZJ_4X_Pickup_C"), "", "4X", "MZJ_4X_Pickup");
		AddItemName(xorstr_("BP_MZJ_6X_Pickup_C"), "", "6X", "MZJ_6X_Pickup");
		AddItemName(xorstr_("BP_MZJ_8X_Pickup_C"), "", "8X", "MZJ_8X_Pickup");

		AddItemName(xorstr_("PickUp_BP_Bag_Lv3_C"), "", "BagLv3", "PickUp_BP_Bag_Lv3");
		AddItemName(xorstr_("PickUp_BP_Bag_Lv3_B_C"), "", "BagLv3", "PickUp_BP_Bag_Lv3");
		AddItemName(xorstr_("PickUp_BP_Bag_Lv2_C"), "", "BagLv2", "PickUp_BP_Bag_Lv2");
		AddItemName(xorstr_("PickUp_BP_Bag_Lv2_B_C"), "", "BagLv2", "PickUp_BP_Bag_Lv2");

		AddItemName(xorstr_("PickUp_BP_Bike_C"), "", "Bicycle", "PickUp_BP_Bike");
		AddItemName(xorstr_("PickUp_BP_Bike_2_C"), "", "Bicycle", "PickUp_BP_Bike");

		AddItemName(xorstr_("Firstaid_Pickup_C"), "", "Firstaid", "Firstaid_Pickup");
		AddItemName(xorstr_("FirstAidbox_Pickup_C"), "", "Medkit", "FirstAidbox_Pickup");
		AddItemName(xorstr_("Injection_Pickup_C"), "", "Adrenaline", "Injection_Pickup");
		AddItemName(xorstr_("Pills_Pickup_C"), "", "Pain Killer", "Pills_Pickup");

		AddItemName(xorstr_("BP_Grenade_Shoulei_Weapon_Wrapper_C"), "", "Shoulei", "Grenade_Shoulei_Weapon_Wrapper");
		AddItemName(xorstr_("BP_Grenade_Smoke_Weapon_Wrapper_C"), "", "Smoke", "Grenade_Smoke_Weapon_Wrapper");
		AddItemName(xorstr_("BP_Grenade_Burn_Weapon_Wrapper_C"), "", "Molotov", "Grenade_Burn_Weapon_Wrapper");
		AddItemName(xorstr_("BP_Grenade_EmergencyCall_Weapon_Wrapper_C"), "", "Emergency Call", "Grenade_EmergencyCall_Weapon_Wrapper");

		AddItemName(xorstr_("BP_DJ_Large_EQ_Pickup_C"), "", "AR Extended Quick", "DJ_Large_EQ_Pickup");
		AddItemName(xorstr_("BP_QK_Large_Compensator_Pickup_C"), "", "AR Compensator", "QK_Large_Compensator_Pickup");
		AddItemName(xorstr_("BP_QK_Large_Suppressor_Pickup_C"), "", "AR Suppressor", "QK_Large_Suppressor_Pickup");
		AddItemName(xorstr_("BP_WB_Vertical_Pickup_C"), "", "Vertical", "WB_Vertical_Pickup");
		AddItemName(xorstr_("BP_QT_A_Pickup_C"), "", "Tactical", "QT_A_Pickup");

		AddItemName(xorstr_("BP_Pistol_Flaregun_Wrapper_C"), "", "Flaregun", "Pistol_Flaregun_Wrapper");
		AddItemName(xorstr_("GoldenTokenWrapper_C"), "", "Golden Token", "GoldenTokenWrapper");
		AddItemName(xorstr_("SecurityCardWrapper_C"), "", "Acsses Card", "SecurityCardWrapper");
	}

	std::string GetBoxItems(int code)
	{
		if (code == 101008)
			return "M762";
		else if (code == 101003)
			return "SCAR-L";
		else if (code == 101004)
			return "M416";
		else if (code == 101010)
			return "G36C";
		else if (code == 101006)
			return "AUG";
		else if (code == 101101)
			return "ASM";
		else if (code == 101001)
			return "AKM";
		else if (code == 101005)
			return "Groza";
		else if (code == 103003)
			return "AWM";
		else if (code == 103002)
			return "M24";
		else if (code == 103001)
			return "Kar98k";
		else if (code == 103011)
			return "Mosin";
		else if (code == 103012)
			return "AMR";
		else if (code == 103004)
			return "SKS";
		else if (code == 103007)
			return "Mk14";

		else if (code == 502002)
			return "Helmet Lv.2";
		else if (code == 502003)
			return "Helmet Lv.3";
		else if (code == 503002)
			return "Armour Lv.2";
		else if (code == 503003)
			return "Armour Lv.3";
		else if (code == 501006)
			return "Bag Lv.3";
		else if (code == 501005)
			return "Bag Lv.2";
		else if (code == 203014)
			return "3X";
		else if (code == 203004)
			return "4x";
		else if (code == 203015)
			return "6x";
		else if (code == 203005)
			return "8x";
		else if (code == 106007)
			return "Flaregun";
		else if (code == 105001)
			return "M249";
		else if (code == 105002)
			return "DP28";
		else if (code == 105010)
			return "MG3";
		else if (code == 3000324)
			return "Golden Token";
		else if (code == 3000324)
			return "Acsses card";
		else if (code == 3000331)
			return "AR Suppressor";
		else if (code == 204013)
			return "AR Extended Quick";
		else if (code == 201009)
			return "AR Compensator";
		else if (code == 205002)
			return "Tactical";
		else if (code == 202002)
			return "Vertical";
		else if (code == 604007)
			return "Bicycle";
		else
			return "";

		return "";
	}
}