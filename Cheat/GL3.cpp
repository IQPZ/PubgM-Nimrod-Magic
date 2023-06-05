#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Includes.h"

FLAGS* Flags = new FLAGS();

ImFont* m_FVisuals = NULL;

ImFont* m_WeaponsFont = NULL;

ImFont* bold = NULL;
ImFont* weapons = NULL;

int ticks = 0;
int beforeclock = 0;

namespace Icons
{
	GLuint Background_info;
	GLuint Logo;
	GLuint Pills_Pickup;
	GLuint Firstaid_Pickup;
	GLuint FirstAidbox_Pickup;
	GLuint Injection_Pickup;
	GLuint PickUp_BP_Bike;
	GLuint PickUp_BP_Helmet_Lv2_B;
	GLuint PickUp_BP_Helmet_Lv3_B;
	GLuint PickUp_BP_Bag_Lv3_B;
	GLuint PickUp_BP_Bag_Lv2_B;
	GLuint PickUp_BP_Armor_Lv3;
	GLuint PickUp_BP_Armor_Lv2;
	GLuint BP_WB_Vertical_Pickup;
	GLuint BP_Sniper_Mosin_Wrapper;
	GLuint BP_Sniper_AMR_Wrapper;
	GLuint BP_Sniper_SKS_Wrapper;
	GLuint BP_Sniper_Mk14_Wrapper;
	GLuint BP_Sniper_AWM_Wrapper;
	GLuint BP_Sniper_Kar98k_Wrapper;
	GLuint BP_Sniper_M24_Wrapper;
	GLuint BP_Rifle_SCAR_Wrapper;
	GLuint BP_Rifle_Groza_Wrapper;
	GLuint BP_Rifle_M416_Wrapper;
	GLuint BP_Rifle_M762_Wrapper;
	GLuint BP_Rifle_AKM_Wrapper;
	GLuint BP_Rifle_AUG_Wrapper;
	GLuint BP_Rifle_G36_Wrapper;
	GLuint BP_ShotGun_DP12_Wrapper;
	GLuint BP_QT_A_Pickup;
	GLuint BP_QK_Large_Compensator_Pickup;
	GLuint BP_QK_Large_Suppressor_Pickup;
	GLuint BP_MZJ_6X_Pickup;
	GLuint BP_MZJ_8X_Pickup;
	GLuint BP_Other_DP28_Wrapper;
	GLuint BP_Other_MG3_Wrapper;
	GLuint BP_Other_M249_Wrapper;
	GLuint BP_MachineGun_Uzi_Wrapper;
	GLuint BP_MachineGun_UMP9_Wrapper;
	GLuint BP_MZJ_3X_Pickup;
	GLuint BP_MZJ_4X_Pickup;
	GLuint BP_MachineGun_MP5K_Wrapper;
	GLuint BP_MachineGun_PP19_Wrapper;
	GLuint BP_Grenade_Burn_Weapon_Wrapper;
	GLuint BP_Grenade_Shoulei_Weapon_Wrapper;
	GLuint BP_Grenade_Smoke_Weapon_Wrapper;
	GLuint BP_Grenade_Stun_Weapon_Wrapper;
	GLuint BP_Grenade_EmergencyCall_Weapon_Wrapper;
	GLuint BP_DJ_Large_EQ_Pickup;
	GLuint BP_Pistol_Flaregun_Wrapper;
	GLuint GoldenTokenWrapper;
	GLuint SecurityCard;

	GLuint DeadBox;
	GLuint Drop;

}

namespace GL3 {
	void toglemenu()
	{
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			Globals::isopened = !Globals::isopened;
			//glfwSetWindowAttrib(Globals::g_window, GLFW_MOUSE_PASSTHROUGH, !Globals::isopened);
			if (Globals::isopened)
			{
				/*	glClearColor(0.0, 0.0, 0.0, 0.8);
					HWND overlay_window = glfwGetWin32Window(Globals::g_window);
					SetForegroundWindow(overlay_window);*/
				SetWindowLongA(Globals::overlayWindow, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TOOLWINDOW);
			}
			else
			{
				/*glClearColor(0.0, 0.0, 0.0, 0.0);
				SetForegroundWindow(Globals::hwnd);*/
				SetWindowLongA(Globals::overlayWindow, GWL_EXSTYLE, (int)GetWindowLongA(Globals::overlayWindow, GWL_EXSTYLE) | WS_EX_TRANSPARENT);

			}
		}
	}
	bool LoadTextureFromFile(const char* filename, GLuint* out_texture)
	{
		// Load from file
		int image_width = 0;
		int image_height = 0;
		unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
		if (image_data == NULL) return false;

		// Create a OpenGL texture identifier
		GLuint image_texture;
		glGenTextures(1, &image_texture);
		glBindTexture(GL_TEXTURE_2D, image_texture);

		// Setup filtering parameters for display
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

		// Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
		glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
		stbi_image_free(image_data);

		*out_texture = image_texture;

		return true;
	}

	void LoadFlags() {
		std::vector<string> list = Utils::Get_Dir_Files(".\\Res\\Flags\\");
		int count = list.size();
		for (int i = 0; i < list.size(); i++) {
			if (strcmp(list[i].c_str(), ".") == 0 || strcmp(list[i].c_str(), "..") == 0)continue;
			string path = ".\\Res\\Flags\\";
			path.append(list[i]);
			string PathWithoutPNG = path.substr(0, path.size() - 4);
			string PathWithPng = path;
			string NameWithoutPNG = list[i].substr(0, list[i].size() - 4);
			string NameWithPNG = list[i];
			//cout << "Num " << i << "==>  " << PathWithoutPNG << endl;
			strcpy(Flags->Flaggs[i].Item_Game_Name, NameWithoutPNG.c_str());
			Flags->Count = count;
			LoadTextureFromFile(path.c_str(), &Flags->Flaggs[i].Item_texture);
		}
	}
	void InitItemesIcon()
	{
		LoadFlags();
		Icons::Background_info;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(Backgrund_Info_Icon, sizeof(Backgrund_Info_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::Background_info);
			glBindTexture(GL_TEXTURE_2D, Icons::Background_info);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::Logo;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(Logo_Icon, sizeof(Logo_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::Logo);
			glBindTexture(GL_TEXTURE_2D, Icons::Logo);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::Pills_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(Pills_Pickup_Icon, sizeof(Pills_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::Pills_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::Pills_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::Firstaid_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(Firstaid_Pickup_Icon, sizeof(Firstaid_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::Firstaid_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::Firstaid_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::FirstAidbox_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(FirstAidbox_Pickup_Icon, sizeof(FirstAidbox_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::FirstAidbox_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::FirstAidbox_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::Injection_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(Injection_Pickup_Icon, sizeof(Injection_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::Injection_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::Injection_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::PickUp_BP_Bike;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(PickUp_BP_Bike_Icon, sizeof(PickUp_BP_Bike_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::PickUp_BP_Bike);
			glBindTexture(GL_TEXTURE_2D, Icons::PickUp_BP_Bike);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::PickUp_BP_Helmet_Lv2_B;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(PickUp_BP_Helmet_Lv2_B_Icon, sizeof(PickUp_BP_Helmet_Lv2_B_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::PickUp_BP_Helmet_Lv2_B);
			glBindTexture(GL_TEXTURE_2D, Icons::PickUp_BP_Helmet_Lv2_B);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::PickUp_BP_Helmet_Lv3_B;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(PickUp_BP_Helmet_Lv3_B_Icon, sizeof(PickUp_BP_Helmet_Lv3_B_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::PickUp_BP_Helmet_Lv3_B);
			glBindTexture(GL_TEXTURE_2D, Icons::PickUp_BP_Helmet_Lv3_B);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::PickUp_BP_Bag_Lv3_B;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(PickUp_BP_Bag_Lv3_B_Icon, sizeof(PickUp_BP_Bag_Lv3_B_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::PickUp_BP_Bag_Lv3_B);
			glBindTexture(GL_TEXTURE_2D, Icons::PickUp_BP_Bag_Lv3_B);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::PickUp_BP_Bag_Lv2_B;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(PickUp_BP_Bag_Lv2_B_Icon, sizeof(PickUp_BP_Bag_Lv2_B_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::PickUp_BP_Bag_Lv2_B);
			glBindTexture(GL_TEXTURE_2D, Icons::PickUp_BP_Bag_Lv2_B);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::PickUp_BP_Armor_Lv3;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(PickUp_BP_Armor_Lv3_Icon, sizeof(PickUp_BP_Armor_Lv3_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::PickUp_BP_Armor_Lv3);
			glBindTexture(GL_TEXTURE_2D, Icons::PickUp_BP_Armor_Lv3);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::PickUp_BP_Armor_Lv2;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(PickUp_BP_Armor_Lv2_Icon, sizeof(PickUp_BP_Armor_Lv2_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::PickUp_BP_Armor_Lv2);
			glBindTexture(GL_TEXTURE_2D, Icons::PickUp_BP_Armor_Lv2);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_WB_Vertical_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_WB_Vertical_Pickup_Icon, sizeof(BP_WB_Vertical_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_WB_Vertical_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_WB_Vertical_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Sniper_Mosin_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Sniper_Mosin_Wrapper_Icon, sizeof(BP_Sniper_Mosin_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Sniper_Mosin_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Sniper_Mosin_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Sniper_AMR_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Sniper_AMR_Wrapper_Icon, sizeof(BP_Sniper_AMR_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Sniper_AMR_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Sniper_AMR_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Sniper_SKS_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Sniper_SKS_Wrapper_Icon, sizeof(BP_Sniper_SKS_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Sniper_SKS_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Sniper_SKS_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Sniper_Mk14_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Sniper_Mk14_Wrapper_Icon, sizeof(BP_Sniper_Mk14_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Sniper_Mk14_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Sniper_Mk14_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Sniper_AWM_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Sniper_AWM_Wrapper_Icon, sizeof(BP_Sniper_AWM_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Sniper_AWM_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Sniper_AWM_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Sniper_Kar98k_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Sniper_Kar98k_Wrapper_Icon, sizeof(BP_Sniper_Kar98k_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Sniper_Kar98k_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Sniper_Kar98k_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Sniper_M24_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Sniper_M24_Wrapper_Icon, sizeof(BP_Sniper_M24_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Sniper_M24_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Sniper_M24_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Rifle_SCAR_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Rifle_SCAR_Wrapper_Icon, sizeof(BP_Rifle_SCAR_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Rifle_SCAR_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Rifle_SCAR_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Rifle_Groza_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Rifle_Groza_Wrapper_Icon, sizeof(BP_Rifle_Groza_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Rifle_Groza_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Rifle_Groza_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Rifle_M416_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Rifle_M416_Wrapper_Icon, sizeof(BP_Rifle_M416_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Rifle_M416_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Rifle_M416_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Rifle_M762_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Rifle_M762_Wrapper_Icon, sizeof(BP_Rifle_M762_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Rifle_M762_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Rifle_M762_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Rifle_AKM_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Rifle_AKM_Wrapper_Icon, sizeof(BP_Rifle_AKM_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Rifle_AKM_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Rifle_AKM_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Rifle_AUG_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Rifle_AUG_Wrapper_Icon, sizeof(BP_Rifle_AUG_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Rifle_AUG_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Rifle_AUG_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Rifle_G36_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Rifle_G36_Wrapper_Icon, sizeof(BP_Rifle_G36_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Rifle_G36_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Rifle_G36_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_ShotGun_DP12_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_ShotGun_DP12_Wrapper_Icon, sizeof(BP_ShotGun_DP12_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_ShotGun_DP12_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_ShotGun_DP12_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_QT_A_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_QT_A_Pickup_Icon, sizeof(BP_QT_A_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_QT_A_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_QT_A_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_QK_Large_Compensator_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_QK_Large_Compensator_Pickup_Icon, sizeof(BP_QK_Large_Compensator_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_QK_Large_Compensator_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_QK_Large_Compensator_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_QK_Large_Suppressor_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_QK_Large_Suppressor_Pickup_Icon, sizeof(BP_QK_Large_Suppressor_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_QK_Large_Suppressor_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_QK_Large_Suppressor_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_MZJ_6X_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_MZJ_6X_Pickup_Icon, sizeof(BP_MZJ_6X_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_MZJ_6X_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_MZJ_6X_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_MZJ_8X_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_MZJ_8X_Pickup_Icon, sizeof(BP_MZJ_8X_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_MZJ_8X_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_MZJ_8X_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Other_DP28_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Other_DP28_Wrapper_Icon, sizeof(BP_Other_DP28_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Other_DP28_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Other_DP28_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Other_MG3_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Other_MG3_Wrapper_Icon, sizeof(BP_Other_MG3_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Other_MG3_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Other_MG3_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Other_M249_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Other_M249_Wrapper_Icon, sizeof(BP_Other_M249_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Other_M249_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Other_M249_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_MachineGun_Uzi_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_MachineGun_Uzi_Wrapper_Icon, sizeof(BP_MachineGun_Uzi_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_MachineGun_Uzi_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_MachineGun_Uzi_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_MachineGun_UMP9_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_MachineGun_UMP9_Wrapper_Icon, sizeof(BP_MachineGun_UMP9_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_MachineGun_UMP9_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_MachineGun_UMP9_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_MZJ_3X_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_MZJ_3X_Pickup_Icon, sizeof(BP_MZJ_3X_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_MZJ_3X_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_MZJ_3X_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_MZJ_4X_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_MZJ_4X_Pickup_Icon, sizeof(BP_MZJ_4X_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_MZJ_4X_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_MZJ_4X_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_MachineGun_MP5K_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_MachineGun_MP5K_Wrapper_Icon, sizeof(BP_MachineGun_MP5K_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_MachineGun_MP5K_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_MachineGun_MP5K_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_MachineGun_PP19_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_MachineGun_PP19_Wrapper_Icon, sizeof(BP_MachineGun_PP19_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_MachineGun_PP19_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_MachineGun_PP19_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Grenade_Burn_Weapon_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Grenade_Burn_Weapon_Wrapper_Icon, sizeof(BP_Grenade_Burn_Weapon_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Grenade_Burn_Weapon_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Grenade_Burn_Weapon_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Grenade_Shoulei_Weapon_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Grenade_Shoulei_Weapon_Wrapper_Icon, sizeof(BP_Grenade_Shoulei_Weapon_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Grenade_Shoulei_Weapon_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Grenade_Shoulei_Weapon_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Grenade_Smoke_Weapon_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Grenade_Smoke_Weapon_Wrapper_Icon, sizeof(BP_Grenade_Smoke_Weapon_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Grenade_Smoke_Weapon_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Grenade_Smoke_Weapon_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Grenade_Stun_Weapon_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Grenade_Stun_Weapon_Wrapper_Icon, sizeof(BP_Grenade_Stun_Weapon_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Grenade_Stun_Weapon_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Grenade_Stun_Weapon_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Grenade_EmergencyCall_Weapon_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Grenade_EmergencyCall_Weapon_Wrapper_Icon, sizeof(BP_Grenade_EmergencyCall_Weapon_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Grenade_EmergencyCall_Weapon_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Grenade_EmergencyCall_Weapon_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_DJ_Large_EQ_Pickup;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_DJ_Large_EQ_Pickup_Icon, sizeof(BP_DJ_Large_EQ_Pickup_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_DJ_Large_EQ_Pickup);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_DJ_Large_EQ_Pickup);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::BP_Pistol_Flaregun_Wrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(BP_Pistol_Flaregun_Wrapper_Icon, sizeof(BP_Pistol_Flaregun_Wrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::BP_Pistol_Flaregun_Wrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::BP_Pistol_Flaregun_Wrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::GoldenTokenWrapper;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(GoldenTokenWrapper_Icon, sizeof(GoldenTokenWrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::GoldenTokenWrapper);
			glBindTexture(GL_TEXTURE_2D, Icons::GoldenTokenWrapper);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::SecurityCard;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(SecurityCardWrapper_Icon, sizeof(SecurityCardWrapper_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::SecurityCard);
			glBindTexture(GL_TEXTURE_2D, Icons::SecurityCard);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::DeadBox;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(DeadBox_Icon, sizeof(DeadBox_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::DeadBox);
			glBindTexture(GL_TEXTURE_2D, Icons::DeadBox);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}

		Icons::Drop;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(Drop_Icon, sizeof(Drop_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::Drop);
			glBindTexture(GL_TEXTURE_2D, Icons::Drop);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}
	}

	void InitImGui(GLFWwindow* hWindow)
	{

	static const ImWchar rangesXX[] = {
	0x0020, 0x00FF,
	0x0600, 0x06FF,
	0x2010, 0x205E,
	0xFB50, 0xFBFF,
	0xFE00, 0xFEFF,
	0x0100, 0x017F,
	0x0300, 0x03ff,
	0xf000, 0xf3ff,
	0x0400, 0x044F,
	0xe000, 0xf8ff,
	0x3131, 0x3163,
	0xAC00, 0xD7A3,
	0x2000, 0x206F,
	0x3000, 0x30FF,
	0x31F0, 0x31FF,
	0xFF00, 0xFFEF,
	0x4e00, 0x9FAF,
	0x0400, 0x052F,
	0x2DE0, 0x2DFF,
	0xA640, 0xA69F,
	0x0E00, 0x0E7F,
	0x0102, 0x0103,
	0x0110, 0x0111,
	0x0128, 0x0129,
	0x0168, 0x0169,
	0x01A0, 0x01A1,
	0x01AF, 0x01B0,
	0x1EA0, 0x1EF9,
	0x02BC, 0x0384,
	0,
		};

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = nullptr;
		io.LogFilename = nullptr;
		ImGui::LoadIniSettingsFromDisk(xorstr_(".\\Res\\Config\\gui.ini"));

		ImFontConfig FontConfig = {};
		FontConfig.OversampleH = 1;
		FontConfig.OversampleV = 1;
		FontConfig.PixelSnapH = 1;

		ImGui::GetIO().FontDefault = io.Fonts->AddFontFromFileTTF(xorstr_(".\\Res\\Fonts\\bold.ttf"), 14.0f, &FontConfig, rangesXX);
		bold = io.Fonts->AddFontFromFileTTF(xorstr_(".\\Res\\Fonts\\bold.ttf"), 20.0f, &FontConfig, rangesXX);
		m_FVisuals = io.Fonts->AddFontFromFileTTF(xorstr_(".\\Res\\Fonts\\bold.ttf"), 18.0f, &FontConfig, rangesXX);// io.Fonts->AddFontFromFileTTF(skCrypt(".\\Res\\Fonts\\esp.ttf"), 18.0f, &FontConfig, rangesXX);

		m_WeaponsFont = io.Fonts->AddFontFromMemoryTTF(&WeaponsFonts_data, sizeof(WeaponsFonts_data), 100.f);
		weapons = io.Fonts->AddFontFromMemoryCompressedTTF(Weapons_compressed_data, Weapons_compressed_size, 30);


		ImGuiStyle& style = ImGui::GetStyle();
		style.Alpha = 0.0f;
		style.WindowPadding = ImVec2(8, 8);
		style.WindowMinSize = ImVec2(32, 32);
		style.WindowRounding = 0.5f;
		style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style.FramePadding = ImVec2(4, 2);
		style.FrameRounding = 0.0f;
		style.ItemSpacing = ImVec2(8, 4);
		style.ItemInnerSpacing = ImVec2(4, 4);
		style.TouchExtraPadding = ImVec2(0, 0);
		style.IndentSpacing = 21.0f;
		style.ColumnsMinSpacing = 3.0f;
		style.ScrollbarSize = 12.0f;
		style.ScrollbarRounding = 0.0f;
		style.GrabMinSize = 0.1f;
		style.GrabRounding = 0.0f;
		style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
		style.DisplayWindowPadding = ImVec2(22, 22);
		style.DisplaySafeAreaPadding = ImVec2(4, 4);
		style.AntiAliasedLines = true;
		style.CurveTessellationTol = 1.25f;

		ImGui_ImplGlfw_InitForOpenGL(hWindow, true);
		ImGui_ImplOpenGL3_Init(xorstr_("#version 130"));

	
		InitItemesIcon();

	}
	void release(GLFWwindow* hWindow)
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		glfwDestroyWindow(hWindow);
		glfwTerminate();

	}

	void GL3Render(GLFWwindow* hWindow)
	{
		int choisefps = 0;
		int vsyncA = clock();
		ticks += 1;
		if (beforeclock == 0) {
			beforeclock = clock();
		}
			toglemenu();

			glfwPollEvents();
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			GL3Draw::GetInstance()->BeginScene();
			GL3Draw::GetInstance()->DrawScene();
			GL3Draw::GetInstance()->EndScene();
			menu::init();

			ImGui::Render();
			int display_w, display_h;
			glfwGetFramebufferSize(hWindow, &display_w, &display_h);
			glViewport(0, 0, display_w, display_h);
			glClear(GL_COLOR_BUFFER_BIT);
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
			glfwSwapBuffers(hWindow);

			if (Settings::Setting::fps == 0)
				choisefps = 25;
			else if (Settings::Setting::fps == 1)
				choisefps = 14;
			else 
				choisefps = 9;
	

			if (Settings::Setting::vsync) {
				int pausetime = choisefps - (clock() - vsyncA);
				if (pausetime > 0 && pausetime < 30) {
					std::this_thread::sleep_for(std::chrono::milliseconds(pausetime));
				}
			}
			int afterclock = clock();
			if (afterclock - beforeclock > 1000) {
				Globals::FPS = ticks;
				beforeclock = 0;
				ticks = 0;
			}
	}
}
