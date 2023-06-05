#include "Includes.h"
namespace menu
{
	int	iVisualsSubTab = 0;
	int	iMiscSubTab = 0;

	void InputHandler() {
		for (int i = 0; i < 5; i++) ImGui::GetIO().MouseDown[i] = false;
		int button = -1;
		if (GetAsyncKeyState(VK_LBUTTON)) button = 0;
		if (button != -1) ImGui::GetIO().MouseDown[button] = true;
	}
	//void CreateStyle()
	//{
	//	ImGuiStyle& _style = ImGui::GetStyle();
	//	if (!Settings::Menu::chroma_menu) {

	//	ImVec4* colors = ImGui::GetStyle().Colors;
	//	colors[ImGuiCol_Text] = ImVec4(0.75f, 0.75f, 0.75f, 1.00f);
	//	colors[ImGuiCol_TextDisabled] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
	//	colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.94f);
	//	colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	//	colors[ImGuiCol_Border] = ImVec4(0.00f, 0.00f, 0.00f, 0.94f); // line box child

	//	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//	colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	//	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	//	colors[ImGuiCol_FrameBgActive] = ImVec4(0.39f, 0.20f, 0.20f, 0.67f);
	//	colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	//	colors[ImGuiCol_TitleBgActive] = ImVec4(0.48f, 0.16f, 0.16f, 1.00f);
	//	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	//	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);

	//	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	//	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	//	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	//	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	//	colors[ImGuiCol_CheckMark] = ImVec4(0.56f, 0.10f, 0.10f, 1.00f);
	//	colors[ImGuiCol_SliderGrab] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	//	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);

	//	colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	//	colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	//	colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	//	colors[ImGuiCol_Header] = ImVec4(0.33f, 0.35f, 0.36f, 0.53f);
	//	colors[ImGuiCol_HeaderHovered] = ImVec4(0.76f, 0.28f, 0.44f, 0.67f);
	//	colors[ImGuiCol_HeaderActive] = ImVec4(0.47f, 0.47f, 0.47f, 0.67f);
	//	colors[ImGuiCol_Separator] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
	//	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
	//	colors[ImGuiCol_SeparatorActive] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);
	//	colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
	//	colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
	//	colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
	//	colors[ImGuiCol_Tab] = ImVec4(0.07f, 0.07f, 0.07f, 0.51f);
	//	colors[ImGuiCol_TabHovered] = ImVec4(0.86f, 0.23f, 0.43f, 0.67f);
	//	colors[ImGuiCol_TabActive] = ImVec4(0.19f, 0.19f, 0.19f, 0.57f);
	//	colors[ImGuiCol_TabUnfocused] = ImVec4(0.05f, 0.05f, 0.05f, 0.90f);
	//	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13f, 0.13f, 0.13f, 0.74f);

	//	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	//	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	//	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	//	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	//	colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
	//	colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
	//	colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
	//	colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//	colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
	//	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	//	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	//	colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	//	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	//	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	//	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);


	//	ImGuiStyle& style = ImGui::GetStyle();

	//	style.GrabMinSize = 10;

	//	}
	//	else
	//	{

	//		_style.Colors[ImGuiCol_Text] = ImVec4{ 1.0f, 1.0f, 1.0f, 1.0f };
	//		_style.Colors[ImGuiCol_Border] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.29f };
	//		_style.Colors[ImGuiCol_Separator] = ImVec4{ 0.44f, 0.37f, 0.61f, 1.0f };
	//		_style.Colors[ImGuiCol_ChildBg] = ImColor(21, 17, 29);//rgb(53, 59, 72)
	//		_style.Colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.1f, 0.13f, 1.0f };
	//		_style.Colors[ImGuiCol_Button] = ImVec4{ 0.13f, 0.13f, 0.17, 1.0f };
	//		_style.Colors[ImGuiCol_ButtonActive] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.Colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
	//		_style.Colors[ImGuiCol_FrameBg] = ImVec4{ 0.13f, 0.13, 0.17, 1.0f };
	//		_style.Colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
	//		_style.Colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
	//		_style.Colors[ImGuiCol_SliderGrab] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.Colors[ImGuiCol_SliderGrabActive] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.Colors[ImGuiCol_Header] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.Colors[ImGuiCol_HeaderActive] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.Colors[ImGuiCol_HeaderHovered] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.Colors[ImGuiCol_CheckMark] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.Colors[ImGuiCol_TitleBg] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.Colors[ImGuiCol_TitleBgActive] = ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f);
	//		_style.GrabMinSize = 10;
	//	}
	//	ImGui::GetStyle() = _style;

	//}
	void CreateStyle()
	{
		auto& colors = ImGui::GetStyle().Colors;
		
		colors[ImGuiCol_WindowBg] = ImVec4{ 0.10f , 0.10f , 0.10f , 0.10f };
		colors[ImGuiCol_MenuBarBg] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };

		// Border
		colors[ImGuiCol_Border] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_BorderShadow] = ImVec4{ 0.10f , 0.10f , 0.10f , 0.10f };

		// Text
		colors[ImGuiCol_Text] = ImVec4{ 1.0f, 1.0f, 1.0f, 1.0f };
		colors[ImGuiCol_TextDisabled] = ImVec4{ 0.5f, 0.5f, 0.5f, 1.0f };

		// Headers
		colors[ImGuiCol_Header] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
		colors[ImGuiCol_HeaderActive] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };

		// Buttons
		colors[ImGuiCol_Button] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };
		colors[ImGuiCol_ButtonActive] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };
		colors[ImGuiCol_CheckMark] = ImVec4{ 0.74f, 0.58f, 0.98f, 1.0f };

		// Popups
		colors[ImGuiCol_PopupBg] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };

		// Slider
		colors[ImGuiCol_SliderGrab] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.54f };
		colors[ImGuiCol_SliderGrabActive] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };

		// Frame BG
		colors[ImGuiCol_FrameBg] = ImVec4{ 0.276f, 0.276f, 0.276f, 0.540f };
		colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.276f, 0.276f, 0.276f, 0.540f };
		colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.276f, 0.276f, 0.276f, 0.540f };

		// Tabs
		colors[ImGuiCol_Tab] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_TabHovered] = ImVec4{ 0.24, 0.24f, 0.32f, 1.0f };
		colors[ImGuiCol_TabActive] = ImVec4{ 0.2f, 0.22f, 0.27f, 1.0f };
		colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };

		// Title
		colors[ImGuiCol_TitleBg] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
		colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };

		// Scrollbar
		colors[ImGuiCol_ScrollbarBg] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_ScrollbarGrab] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };

		// Seperator
		colors[ImGuiCol_Separator] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_SeparatorHovered] = ImVec4{ 0.74f, 0.58f, 0.98f, 1.0f };
		colors[ImGuiCol_SeparatorActive] = ImVec4{ 0.84f, 0.58f, 1.0f, 1.0f };

		// Resize Grip
		colors[ImGuiCol_ResizeGrip] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_ResizeGripHovered] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };
		colors[ImGuiCol_ResizeGripActive] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };

		// Docking FrameRounding


		auto& style = ImGui::GetStyle();
		style.TabRounding = 4;
		style.ScrollbarRounding = 9;
		style.WindowRounding = 7;
		style.FrameRounding = 12.000f;
		style.GrabRounding = 12.000f;
		style.GrabMinSize = 5.0f;
		style.FrameRounding = 3;
		style.PopupRounding = 4;
		style.ChildRounding = 4;
		style.Alpha = 100.0f;
		
		
	}



#define loop(n) for(int ii = 0; ii < n; ++ ii)
	template<size_t N>
	void RENDER_TAB_SAMELINE(char* (&names)[N], int& activetab, float w, float h)
	{
		bool values[N] = { false };
		values[activetab] = true;
		for (auto i = 0; i < N; ++i) {
			if (ImGui::ToggleButton(names[i], &values[i], 6, ImVec2{ w, h }))
				activetab = i;
			ImGui::SameLine();
		}
	}
	template<size_t N>
	void RENDER_TAB(char* (&names)[N], int& activetab, float w, float h)
	{
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 255);
		bool values[N] = { false };
		values[activetab] = true;
		for (auto i = 0; i < N; ++i) {
			ImGui::NewLine(); ImGui::NewLine();
			ImGui::SameLine((190 / 2) - (w / 2));
			if (ImGui::ToggleButton(names[i], &values[i], i, ImVec2{ w, h }))
				activetab = i;
		}
		ImGui::PopStyleVar();
	}


	void tab_Aimbot()
	{
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.20f, 0.20f, 0.20f, 0.20f));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		loop(3)ImGui::Spacing();

		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 7);
		ImGui::Text(xorstr_("Main"));
		ImGui::PopFont();
		ImGui::BeginChild(xorstr_("##aimbot-1"), ImVec2(290, 300), true);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 3);
		ImGui::NewLine();
		ImGui::Checkbox("Enable ##aimbot", &Settings::Aimbot::enable);
		ImGui::Combo(xorstr_("Aim Mode"), &Settings::Aimbot::aimmode, xorstr_("Aimbot\0SilentAim\0PerfectHit[Legit Magic]\0Aimbot+PerfectHit\0")); // magic

		ImGui::Combo(xorstr_("Mode"), &Settings::Aimbot::mode, xorstr_("crosshair\0Distance"));

		ImGui::EndChild();
		ImGui::NextColumn();
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 7);
		ImGui::Text("Extra");
		ImGui::PopFont();
		ImGui::BeginChild(xorstr_("##aimbot-2"), ImVec2(290, 300), true);
		ImGui::NewLine();

		ImGui::Checkbox(xorstr_("Aim Knocked"), &Settings::Aimbot::aimknocked);

		ImGui::Checkbox(xorstr_("Aim Prediction"), &Settings::Aimbot::prediction);

		ImGui::Checkbox(xorstr_("Draw Fov"), &Settings::Aimbot::drawfov);
		ImGui::Checkbox(xorstr_("Draw HitBox"), &Settings::Aimbot::drawhitbox);

		if(Settings::Aimbot::aimmode == 2)
			ImGui::Checkbox(xorstr_("Unlock Fov LegitMagic"), &Settings::Aimbot::unlockmagiclegit);

		if (Settings::Aimbot::drawhitbox)
			ImGui::Combo(xorstr_("HitBox Type"), &Settings::Aimbot::hitboxtype, xorstr_("type1\0type2\0type3"));

		ImGui::EndChild();

		ImGui::Columns(1, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 7);
		ImGui::Text("Weapons Config");
		ImGui::PopFont();
		ImGui::BeginChild(xorstr_("##aimbot-3"), ImVec2(608, 260), true);
		
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
			ImGui::PushFont(weapons);
			static char* guns[] = { "A","B","C","D","E","F" };
			RENDER_TAB_SAMELINE(guns, Settings::UI::tab_aimbot, 588 / 6, 30);
			ImGui::PopStyleVar();

			ImGui::PopFont();
		
		ImGui::NewLine(); ImGui::NewLine();
		switch (Settings::UI::tab_aimbot)
		{
		case 0:
			ImGui::Checkbox(xorstr_("Enable##1"), &Settings::Aimbot::ARConfig::enable);
			ImGui::Text(xorstr_("Aim Key"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::ARConfig::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##1"), &Settings::Aimbot::ARConfig::autolock);
			ImGui::SliderInt(xorstr_("Distance##1"), &Settings::Aimbot::ARConfig::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##1"), &Settings::Aimbot::ARConfig::fov, 1.f, 180.0f, "%1.0f");
			if(Settings::Aimbot::aimmode !=1)
			ImGui::SliderFloat(xorstr_("Smooth##1"), &Settings::Aimbot::ARConfig::smooth, 1.0f, 100.0f, "%1.0f");
			ImGui::Checkbox(xorstr_("RCS##1"), &Settings::Aimbot::ARConfig::recoil);
			if (Settings::Aimbot::ARConfig::recoil)
				ImGui::SliderFloat(xorstr_("Compesation##1"), &Settings::Aimbot::ARConfig::compesation, 0.1f, 3.0f, "%0.1f");

			ImGui::Checkbox(xorstr_("Nearest Bone##1"), &Settings::Aimbot::ARConfig::legitaim);
			if (!Settings::Aimbot::ARConfig::legitaim)
			ImGui::Combo(xorstr_("HitBox##1"), &Settings::Aimbot::ARConfig::hitbox, xorstr_("Head\0Neck\0Spine"));
			if (Settings::Aimbot::aimmode == 2 || Settings::Aimbot::aimmode == 3)
			{
				ImGui::Text(xorstr_("Magic Single Bulit##1"));
				ImGui::SliderInt(xorstr_("Start Magic Bulit ##1"), &Settings::Aimbot::ARConfig::PerfectHit::Start, 0, 30);
				ImGui::SliderInt(xorstr_("End Magic Bulit ##1"), &Settings::Aimbot::ARConfig::PerfectHit::End, 0, 30);
			}
			break;
		case 1:
			ImGui::Checkbox(xorstr_("Enable##2"), &Settings::Aimbot::PistolConfig::enable);
			ImGui::Text(xorstr_("Aim Key"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::PistolConfig::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##2"), &Settings::Aimbot::PistolConfig::autolock);
			ImGui::SliderInt(xorstr_("Distance##2"), &Settings::Aimbot::PistolConfig::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##2"), &Settings::Aimbot::PistolConfig::fov, 1.f, 180.0f, "%1.0f");
			if (Settings::Aimbot::aimmode != 1)
			ImGui::SliderFloat(xorstr_("Smooth##2"), &Settings::Aimbot::PistolConfig::smooth, 1.0f, 100.0f, "%1.0f");
			ImGui::Checkbox(xorstr_("RCS##2"), &Settings::Aimbot::PistolConfig::recoil);
			if (Settings::Aimbot::PistolConfig::recoil)
				ImGui::SliderFloat(xorstr_("Compesation##2"), &Settings::Aimbot::PistolConfig::compesation, 0.1f, 3.0f, "%0.1f");

			ImGui::Checkbox(xorstr_("Nearest Bone##2"), &Settings::Aimbot::PistolConfig::legitaim);
			if (!Settings::Aimbot::PistolConfig::legitaim)
			ImGui::Combo(xorstr_("HitBox##2"), &Settings::Aimbot::PistolConfig::hitbox, xorstr_("Head\0Neck\0Spine"));
			if (Settings::Aimbot::aimmode == 2 || Settings::Aimbot::aimmode == 3)
			{
				ImGui::Text(xorstr_("Magic Single Bulit##1"));
				ImGui::SliderInt(xorstr_("Start Magic Bulit ##1"), &Settings::Aimbot::PistolConfig::PerfectHit::Start, 0, 30);
				ImGui::SliderInt(xorstr_("End Magic Bulit ##1"), &Settings::Aimbot::PistolConfig::PerfectHit::End, 0, 30);
			}
			break;
		case 2:
			ImGui::Checkbox(xorstr_("Enable##3"), &Settings::Aimbot::SniperConfig::enable);
			ImGui::Text(xorstr_("Aim Key"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::SniperConfig::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##3"), &Settings::Aimbot::SniperConfig::autolock);
			ImGui::SliderInt(xorstr_("Distance##3"), &Settings::Aimbot::SniperConfig::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##3"), &Settings::Aimbot::SniperConfig::fov, 1.f, 180.0f, "%1.0f");
			if (Settings::Aimbot::aimmode != 1)
			ImGui::SliderFloat(xorstr_("Smooth##3"), &Settings::Aimbot::SniperConfig::smooth, 1.0f, 100.0f, "%1.0f");
			ImGui::Checkbox(xorstr_("RCS##3"), &Settings::Aimbot::SniperConfig::recoil);
			if (Settings::Aimbot::SniperConfig::recoil)
				ImGui::SliderFloat(xorstr_("Compesation##3"), &Settings::Aimbot::SniperConfig::compesation, 0.1f, 3.0f, "%0.1f");

			ImGui::Checkbox(xorstr_("Nearest Bone##3"), &Settings::Aimbot::SniperConfig::legitaim);
			if (!Settings::Aimbot::SniperConfig::legitaim)
			ImGui::Combo(xorstr_("HitBox##3"), &Settings::Aimbot::SniperConfig::hitbox, xorstr_("Head\0Neck\0Spine"));
			if (Settings::Aimbot::aimmode == 2 || Settings::Aimbot::aimmode == 3)
			{
				ImGui::Text(xorstr_("Magic Single Bulit##1"));
				ImGui::SliderInt(xorstr_("Start Magic Bulit ##1"), &Settings::Aimbot::SniperConfig::PerfectHit::Start, 0, 30);
				ImGui::SliderInt(xorstr_("End Magic Bulit ##1"), &Settings::Aimbot::SniperConfig::PerfectHit::End, 0, 30);
			}
			break;
		case 3:
			ImGui::Checkbox(xorstr_("Enable##4"), &Settings::Aimbot::SMGConfig::enable);
			ImGui::Text(xorstr_("Aim Key"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::SMGConfig::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##4"), &Settings::Aimbot::SMGConfig::autolock);
			ImGui::SliderInt(xorstr_("Distance##4"), &Settings::Aimbot::SMGConfig::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##4"), &Settings::Aimbot::SMGConfig::fov, 1.f, 180.0f, "%1.0f");
			if (Settings::Aimbot::aimmode != 1)
			ImGui::SliderFloat(xorstr_("Smooth##4"), &Settings::Aimbot::SMGConfig::smooth, 1.0f, 100.0f, "%1.0f");
			ImGui::Checkbox(xorstr_("RCS##4"), &Settings::Aimbot::SMGConfig::recoil);
			if (Settings::Aimbot::SMGConfig::recoil)
				ImGui::SliderFloat(xorstr_("Compesation##4"), &Settings::Aimbot::SMGConfig::compesation, 0.1f, 3.0f, "%0.1f");

			ImGui::Checkbox(xorstr_("Nearest Bone##4"), &Settings::Aimbot::SMGConfig::legitaim);
			if (!Settings::Aimbot::SMGConfig::legitaim)
			ImGui::Combo(xorstr_("HitBox##4"), &Settings::Aimbot::SMGConfig::hitbox, xorstr_("Head\0Neck\0Spine"));
			if (Settings::Aimbot::aimmode == 2 || Settings::Aimbot::aimmode == 3)
			{
				ImGui::Text(xorstr_("Magic Single Bulit##1"));
				ImGui::SliderInt(xorstr_("Start Magic Bulit ##1"), &Settings::Aimbot::SMGConfig::PerfectHit::Start, 0, 30);
				ImGui::SliderInt(xorstr_("End Magic Bulit ##1"), &Settings::Aimbot::SMGConfig::PerfectHit::End, 0, 30);
			}
			break;
		case 4:
			ImGui::Checkbox(xorstr_("Enable##5"), &Settings::Aimbot::ShotGunConfig::enable);
			ImGui::Text(xorstr_("Aim Key"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::ShotGunConfig::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##5"), &Settings::Aimbot::ShotGunConfig::autolock);
			ImGui::SliderInt(xorstr_("Distance##5"), &Settings::Aimbot::ShotGunConfig::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##5"), &Settings::Aimbot::ShotGunConfig::fov, 1.f, 180.0f, "%1.0f");
			if (Settings::Aimbot::aimmode != 1)
			ImGui::SliderFloat(xorstr_("Smooth##5"), &Settings::Aimbot::ShotGunConfig::smooth, 1.0f, 100.0f, "%1.0f");
			ImGui::Checkbox(xorstr_("RCS##5"), &Settings::Aimbot::ShotGunConfig::recoil);
			if (Settings::Aimbot::ShotGunConfig::recoil)
				ImGui::SliderFloat(xorstr_("Compesation##5"), &Settings::Aimbot::ShotGunConfig::compesation, 0.1f, 3.0f, "%0.1f");

			ImGui::Checkbox(xorstr_("Nearest Bone##5"), &Settings::Aimbot::ShotGunConfig::legitaim);
			if (!Settings::Aimbot::ShotGunConfig::legitaim)
			ImGui::Combo(xorstr_("HitBox##5"), &Settings::Aimbot::ShotGunConfig::hitbox, xorstr_("Head\0Neck\0Spine"));
			if (Settings::Aimbot::aimmode == 2 || Settings::Aimbot::aimmode == 3)
			{
				ImGui::Text(xorstr_("Magic Single Bulit##1"));
				ImGui::SliderInt(xorstr_("Start Magic Bulit ##1"), &Settings::Aimbot::ShotGunConfig::PerfectHit::Start, 0, 30);
				ImGui::SliderInt(xorstr_("End Magic Bulit ##1"), &Settings::Aimbot::ShotGunConfig::PerfectHit::End, 0, 30);
			}
			break;
		case 5:
			ImGui::Checkbox(xorstr_("Enable##6"), &Settings::Aimbot::LMGConfig::enable);
			ImGui::Text(xorstr_("Aim Key"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::LMGConfig::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##6"), &Settings::Aimbot::LMGConfig::autolock);
			ImGui::SliderInt(xorstr_("Distance##6"), &Settings::Aimbot::LMGConfig::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##6"), &Settings::Aimbot::LMGConfig::fov, 1.f, 180.0f, "%1.0f");
			if (Settings::Aimbot::aimmode != 1)
			ImGui::SliderFloat(xorstr_("Smooth##6"), &Settings::Aimbot::LMGConfig::smooth, 1.0f, 100.0f, "%1.0f");
			ImGui::Checkbox(xorstr_("RCS##6"), &Settings::Aimbot::LMGConfig::recoil);
			if (Settings::Aimbot::LMGConfig::recoil)
				ImGui::SliderFloat(xorstr_("Compesation##6"), &Settings::Aimbot::LMGConfig::compesation, 0.1f, 3.0f, "%0.1f");

			ImGui::Checkbox(xorstr_("Nearest Bone##6"), &Settings::Aimbot::LMGConfig::legitaim);
			if (!Settings::Aimbot::LMGConfig::legitaim)
			ImGui::Combo(xorstr_("HitBox##6"), &Settings::Aimbot::LMGConfig::hitbox, xorstr_("Head\0Neck\0Spine"));
			if (Settings::Aimbot::aimmode == 2 || Settings::Aimbot::aimmode == 3)
			{
				ImGui::Text(xorstr_("Magic Single Bulit##1"));
				ImGui::SliderInt(xorstr_("Start Magic Bulit ##1"), &Settings::Aimbot::LMGConfig::PerfectHit::Start, 0, 30);
				ImGui::SliderInt(xorstr_("End Magic Bulit ##1"), &Settings::Aimbot::LMGConfig::PerfectHit::End, 0, 30);
			}
			break;
		default:
			break;
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
	void tab_Visuals()
	{
		loop(3)ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.20f, 0.20f, 0.20f, 0.20f));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SameLine((290 / 2) - (75 / 2));
		ImGui::Text(xorstr_("Player"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##visuals-1"), ImVec2(290, 362), true);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* player_esp[] = { "Enemy","Team","Settings" };
		RENDER_TAB_SAMELINE(player_esp, Settings::UI::player_esp, 280 / 3, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();

		switch (Settings::UI::player_esp)
		{
		case 0:
			ImGui::Checkbox(xorstr_("Box"), &Settings::ESP::Players::Enemy::boxes);
			ImGui::SameLine(150);
			ImGui::Checkbox(xorstr_("Weapon Warning"), &Settings::ESP::Players::Enemy::WeaponWarning);
			ImGui::Checkbox(xorstr_("Name"), &Settings::ESP::Players::Enemy::name);
			ImGui::Checkbox(xorstr_("Distance"), &Settings::ESP::Players::Enemy::distance);
			ImGui::Checkbox(xorstr_("Snapline"), &Settings::ESP::Players::Enemy::snaplines);
			ImGui::Checkbox(xorstr_("Nation"), &Settings::ESP::Players::Enemy::nation);
			ImGui::Checkbox(xorstr_("Status"), &Settings::ESP::Players::Enemy::status);
			ImGui::Checkbox(xorstr_("Health"), &Settings::ESP::Players::Enemy::health);
			ImGui::Checkbox(xorstr_("Weapon"), &Settings::ESP::Players::Enemy::weapon);
			ImGui::Checkbox(xorstr_("Filledbox"), &Settings::ESP::Players::Enemy::filledbox);
			ImGui::Checkbox(xorstr_("Skeleton"), &Settings::ESP::Players::Enemy::skeleton);
			ImGui::Checkbox(xorstr_("Offscreen"), &Settings::ESP::Players::Enemy::offscreen);
			ImGui::Checkbox(xorstr_("Direction Line"), &Settings::ESP::Players::Enemy::directionLine);
			ImGui::Checkbox(xorstr_("Prediction"), &Settings::ESP::Players::Enemy::prediction);
			ImGui::Checkbox(xorstr_("Spot"), &Settings::ESP::Players::Enemy::spot);

			break;
		case 1:
			ImGui::Checkbox(xorstr_("Box##1"), &Settings::ESP::Players::Team::boxes);
			ImGui::SameLine(150);
			ImGui::Checkbox(xorstr_("Weapon Warning##1"), &Settings::ESP::Players::Team::WeaponWarning);
			ImGui::Checkbox(xorstr_("Name##1"), &Settings::ESP::Players::Team::name);
			ImGui::Checkbox(xorstr_("Distance##1"), &Settings::ESP::Players::Team::distance);
			ImGui::Checkbox(xorstr_("Snapline##1"), &Settings::ESP::Players::Team::snaplines);
			ImGui::Checkbox(xorstr_("Nation##1"), &Settings::ESP::Players::Team::nation);
			ImGui::Checkbox(xorstr_("Status##1"), &Settings::ESP::Players::Team::status);
			ImGui::Checkbox(xorstr_("Health##1"), &Settings::ESP::Players::Team::health);
			ImGui::Checkbox(xorstr_("Weapon##1"), &Settings::ESP::Players::Team::weapon);
			ImGui::Checkbox(xorstr_("Filledbox##1"), &Settings::ESP::Players::Team::filledbox);
			ImGui::Checkbox(xorstr_("Skeleton##1"), &Settings::ESP::Players::Team::skeleton);
			ImGui::Checkbox(xorstr_("Offscreen##1"), &Settings::ESP::Players::Team::offscreen);
			ImGui::Checkbox(xorstr_("Direction Line##1"), &Settings::ESP::Players::Team::directionLine);
			ImGui::Checkbox(xorstr_("Prediction##1"), &Settings::ESP::Players::Team::prediction);
			ImGui::Checkbox(xorstr_("Spot##1"), &Settings::ESP::Players::Team::spot);

			break;
		case 2:
			ImGui::Checkbox(xorstr_("Color By TeamID"), &Settings::ESP::Options::colorbyteamid);
			ImGui::Checkbox(xorstr_("Outline"), &Settings::ESP::Options::esp_Outline);
			ImGui::Combo(xorstr_("Box Type"), &Settings::ESP::Options::boxtype, xorstr_("Box\0CornersBox\0GenuineBox\0OctagonBox\0OctagonCornersBox\0ThreeD"));
			ImGui::Combo(xorstr_("Health Type"), &Settings::ESP::Options::healthbartype, xorstr_("Horizontal\0Vertical"));
			ImGui::SliderInt(xorstr_("Direction Line Size"), &Settings::ESP::Options::DirectionLineSize, 1, 500);
			ImGui::SliderInt(xorstr_("Distance Offscreen"), &Settings::ESP::Options::max_distance_offscreen, 1, 180);
			ImGui::SliderInt(xorstr_("Offscreen Range"), &Settings::ESP::Options::offscreen_range, 1, 180);
			ImGui::SliderInt(xorstr_("Players Distance"), &Settings::ESP::Options::playersdis, 1, 400);
			ImGui::Combo(xorstr_("Prediction Type"), &Settings::ESP::Options::predictiontype, xorstr_("Diagonal\0Plus\0Dot"));
			ImGui::Combo(xorstr_("Nation Type"), &Settings::ESP::Options::Nationtype, xorstr_("Short\0Full"));
			ImGui::Combo(xorstr_("ESP Style"), &Settings::ESP::Options::ESPStyle, xorstr_("Style1\0 Style2"));

			ImGui::SliderInt(xorstr_("Name Size"), &Settings::ESP::Options::PlayerNameSize, 1, 20);
			ImGui::SliderFloat(xorstr_("Box thickness"), &Settings::ESP::Options::Boxthickness, 1.0f, 5.0f, "%0.1f");
			ImGui::SliderFloat(xorstr_("Snaplines thickness"), &Settings::ESP::Options::snaplinesthickness, 1.0f, 5.0f, "%0.1f");
			ImGui::SliderFloat(xorstr_("Skeleton thickness"), &Settings::ESP::Options::Skeletonthickness, 1.0f, 5.0f, "%0.1f");

			ImGui::Text(xorstr_("Fighter Mode Key"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::ESP::Options::FightModeKey);

			break;
		}

		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (115 / 2));
		ImGui::Text(xorstr_("Vehicles"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##visuals-2"), ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* colored_models_char[] = { "Vehicle","Settings" };
		RENDER_TAB_SAMELINE(colored_models_char, Settings::UI::vehicle_esp, 280 / 2, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();
		switch (Settings::UI::vehicle_esp)
		{
		case 0:
			ImGui::Checkbox(xorstr_("Name##2"), &Settings::ESP::Vehicle::vehicleName);
			ImGui::Checkbox(xorstr_("Box##2"), &Settings::ESP::Vehicle::vehicleBox);
			ImGui::Checkbox(xorstr_("Damage"), &Settings::ESP::Vehicle::vehicleHP);
			ImGui::Checkbox(xorstr_("Wheel Damaged"), &Settings::ESP::Vehicle::vehicleWheelDamaged);
			ImGui::Checkbox(xorstr_("Oil"), &Settings::ESP::Vehicle::vehicleOil);
			ImGui::Checkbox(xorstr_("Direction Line##2"), &Settings::ESP::Vehicle::vehicleDirectionLine);
			ImGui::Checkbox(xorstr_("Prediction##2"), &Settings::ESP::Vehicle::vehiclePrediction);
			break;
		case 1:
			ImGui::SliderInt(xorstr_("Direction Line Size##2"), &Settings::ESP::Options::VehicleDirectionLineSize, 1, 500);
			ImGui::SliderInt(xorstr_("Vehicle Distance"), &Settings::ESP::Options::vehiclesdis, 1, 600);
			ImGui::Combo(xorstr_("Prediction Type##2"), &Settings::ESP::Options::predictiontype2, xorstr_("Diagonal\0Plus\0Dot"));

			break;
		default:
			break;
		}

		ImGui::EndChild();


		ImGui::NextColumn();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (70 / 2));
		ImGui::Text(xorstr_("Items"));
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
		ImGui::BeginChild(xorstr_("##visuals-3"), ImVec2(290, 362), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* other_esp_char[] = { "Items","Settings" };
		RENDER_TAB_SAMELINE(other_esp_char, Settings::UI::items_esp, 280 / 2, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();
		switch (Settings::UI::items_esp)
		{
		case 0:
			ImGui::Checkbox(xorstr_("Special"), &Settings::ESP::Loot::lootspecial);
			ImGui::Checkbox(xorstr_("AR"), &Settings::ESP::Loot::lootarweapon);
			ImGui::Checkbox(xorstr_("SMG"), &Settings::ESP::Loot::lootsmgweapon);
			ImGui::Checkbox(xorstr_("Sniper"), &Settings::ESP::Loot::lootsniperweapon);
			ImGui::Checkbox(xorstr_("Machinegun"), &Settings::ESP::Loot::lootother);
			ImGui::Checkbox(xorstr_("Shotgun"), &Settings::ESP::Loot::lootshotgun);
			ImGui::Checkbox(xorstr_("Helmet"), &Settings::ESP::Loot::loothelmet);
			ImGui::Checkbox(xorstr_("Armor"), &Settings::ESP::Loot::lootarmor);
			ImGui::Checkbox(xorstr_("Backpack"), &Settings::ESP::Loot::lootbackpack);
			ImGui::Checkbox(xorstr_("Scope"), &Settings::ESP::Loot::lootscopes);
			ImGui::Checkbox(xorstr_("Accessories"), &Settings::ESP::Loot::lootaccessories);
			ImGui::Checkbox(xorstr_("Energy"), &Settings::ESP::Loot::lootenergy);
			ImGui::Checkbox(xorstr_("Grenade"), &Settings::ESP::Loot::lootgrenade);
			ImGui::Checkbox(xorstr_("Bicycle"), &Settings::ESP::Loot::lootbicycle);

			break;
		case 1:
			ImGui::Combo(xorstr_("Item Type"), &Settings::ESP::Options::loottype, xorstr_("Name\0Icon"));
			ImGui::SliderInt(xorstr_("Size Width"), &Settings::ESP::Options::iconwidth, 1, 128);
			ImGui::SliderInt(xorstr_("Size Height"), &Settings::ESP::Options::iconheight, 1, 128);
			break;
		default:
			break;
		}
		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (52 / 2));
		ImGui::Text(xorstr_("Other"));
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::BeginChild(xorstr_("##visuals-4"), ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* effects_esp_char[] = { "Other","Settings" };
		RENDER_TAB_SAMELINE(effects_esp_char, Settings::UI::other_esp, 280 / 2, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();
		switch (Settings::UI::other_esp)
		{
		case 0:
			ImGui::Checkbox(xorstr_("RedZone Warning"), &Settings::ESP::Other::redzone);
			ImGui::Checkbox(xorstr_("Grenade Warning"), &Settings::ESP::Other::EspGrenade);
			ImGui::Checkbox(xorstr_("Vehicle Explosion Warning"), &Settings::ESP::Other::vehicleExplosionWarning);
			ImGui::Checkbox(xorstr_("Deadbox"), &Settings::ESP::Inventory::Deadbox);
			ImGui::Checkbox(xorstr_("AirDrop"), &Settings::ESP::Inventory::AirDrop);
			ImGui::Checkbox(xorstr_("TreasureChest"), &Settings::ESP::Inventory::TreasureChest);
			ImGui::Checkbox(xorstr_("Inventory Details"), &Settings::ESP::Inventory::InventoryDetails);
			break;
		case 1:
			ImGui::Combo(xorstr_("Grenade Type"), &Settings::ESP::Options::GrenadeType, xorstr_("Name\0Icon"));
			break;
		default:
			break;
		}
		ImGui::EndChild();


		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
	void tab_Misc()
	{

		loop(3)ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.20f, 0.20f, 0.20f, 0.20f));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SameLine((290 / 2) - (75 / 2));
		ImGui::Text(xorstr_("Radar"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##misc-1"), ImVec2(290, 362), true);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();

		ImGui::Checkbox(xorstr_("Enable"), &Settings::Radar::enable);
		ImGui::Checkbox(xorstr_("Team"), &Settings::Radar::teamRadar);
		ImGui::Checkbox(xorstr_("Enemy"), &Settings::Radar::enemyRadar);
		ImGui::Checkbox(xorstr_("Vehicle"), &Settings::Radar::vehicleRadar);
		ImGui::Checkbox(xorstr_("AirDrop"), &Settings::Radar::airdropRadar);
		ImGui::Combo(xorstr_("Radar type"), &Settings::Radar::radartype, xorstr_("Distance\0Dot"));
		ImGui::SliderInt(xorstr_("Distance"), &Settings::Radar::distance_Radar, 1, 1000);


		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (115 / 2));
		ImGui::Text(xorstr_("Crosshair"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##misc-2"), ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::Checkbox(xorstr_("Enable"), &Settings::Crosshair::c_enable);
		ImGui::Combo(xorstr_("Crosshair Type"), &Settings::Crosshair::crosshair, xorstr_("Dot\0Plus\0Cross\0Gap\0Diagonal\0Swastika\0HitMaker"));
		ImGui::SliderFloat(xorstr_("size"), &Settings::Crosshair::size, 1.f, 10.0f, "%1.0f");
		ImGui::SliderFloat(xorstr_("stroke"), &Settings::Crosshair::stroke, 1.f, 10.0f, "%1.0f");
		ImGui::ColorEdit3(xorstr_("Color"), Settings::Color::Crosshair::crosshair);

		ImGui::EndChild();


		ImGui::NextColumn();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (70 / 2));
		ImGui::Text(xorstr_("Micro"));
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
		ImGui::BeginChild(xorstr_("##misc-3"), ImVec2(290, 362), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		static char* Weapon_char[] = { "AR","SMG","LMG"};
		RENDER_TAB_SAMELINE(Weapon_char, Settings::UI::micro_weapon, 280 / 3, 20);
		ImGui::NewLine();   ImGui::NewLine();

		static char* scope_char[] = { "Iron","RedDot","X2" ,"X3","X4" };
		RENDER_TAB_SAMELINE(scope_char, Settings::UI::micro_scope, 280 / 5, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();
		switch (Settings::UI::micro_weapon)
		{
		case 0:
			if (Settings::UI::micro_scope == 0)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::AR::micro_Iron);
				ImGui::SliderFloat(xorstr_("Axis X ##1"), &Settings::Micro::AR::microaxis_Iron.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##2"), &Settings::Micro::AR::microaxis_Iron.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 1)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::AR::micro_RedDot);
				ImGui::SliderFloat(xorstr_("Axis X ##3"), &Settings::Micro::AR::microaxis_RedDot.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##4"), &Settings::Micro::AR::microaxis_RedDot.Y, 1.0f, 10.0f, "%0.1f");

			}
			else if (Settings::UI::micro_scope == 2)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::AR::micro_X2);
				ImGui::SliderFloat(xorstr_("Axis X ##5"), &Settings::Micro::AR::microaxis_X2.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##6"), &Settings::Micro::AR::microaxis_X2.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 3)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::AR::micro_X3);
				ImGui::SliderFloat(xorstr_("Axis X ##7"), &Settings::Micro::AR::microaxis_X3.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##8"), &Settings::Micro::AR::microaxis_X3.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 4)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::AR::micro_X4);
				ImGui::SliderFloat(xorstr_("Axis X ##9"), &Settings::Micro::AR::microaxis_X4.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##10"), &Settings::Micro::AR::microaxis_X4.Y, 1.0f, 10.0f, "%0.1f");
			}
			break;
		case 1:
			if (Settings::UI::micro_scope == 0)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::SMG::micro_Iron);
				ImGui::SliderFloat(xorstr_("Axis X ##1"), &Settings::Micro::SMG::microaxis_Iron.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##2"), &Settings::Micro::SMG::microaxis_Iron.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 1)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::SMG::micro_RedDot);
				ImGui::SliderFloat(xorstr_("Axis X ##3"), &Settings::Micro::SMG::microaxis_RedDot.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##4"), &Settings::Micro::SMG::microaxis_RedDot.Y, 1.0f, 10.0f, "%0.1f");

			}
			else if (Settings::UI::micro_scope == 2)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::SMG::micro_X2);
				ImGui::SliderFloat(xorstr_("Axis X ##5"), &Settings::Micro::SMG::microaxis_X2.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##6"), &Settings::Micro::SMG::microaxis_X2.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 3)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::SMG::micro_X3);
				ImGui::SliderFloat(xorstr_("Axis X ##7"), &Settings::Micro::SMG::microaxis_X3.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##8"), &Settings::Micro::SMG::microaxis_X3.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 4)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::SMG::micro_X4);
				ImGui::SliderFloat(xorstr_("Axis X ##9"), &Settings::Micro::SMG::microaxis_X4.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##10"), &Settings::Micro::SMG::microaxis_X4.Y, 1.0f, 10.0f, "%0.1f");
			}

			break;
		case 2:
			if (Settings::UI::micro_scope == 0)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::LMG::micro_Iron);
				ImGui::SliderFloat(xorstr_("Axis X ##1"), &Settings::Micro::LMG::microaxis_Iron.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##2"), &Settings::Micro::LMG::microaxis_Iron.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 1)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::LMG::micro_RedDot);
				ImGui::SliderFloat(xorstr_("Axis X ##3"), &Settings::Micro::LMG::microaxis_RedDot.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##4"), &Settings::Micro::LMG::microaxis_RedDot.Y, 1.0f, 10.0f, "%0.1f");

			}
			else if (Settings::UI::micro_scope == 2)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::LMG::micro_X2);
				ImGui::SliderFloat(xorstr_("Axis X ##5"), &Settings::Micro::LMG::microaxis_X2.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##6"), &Settings::Micro::LMG::microaxis_X2.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 3)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::LMG::micro_X3);
				ImGui::SliderFloat(xorstr_("Axis X ##7"), &Settings::Micro::LMG::microaxis_X3.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##8"), &Settings::Micro::LMG::microaxis_X3.Y, 1.0f, 10.0f, "%0.1f");
			}
			else if (Settings::UI::micro_scope == 4)
			{
				ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::LMG::micro_X4);
				ImGui::SliderFloat(xorstr_("Axis X ##9"), &Settings::Micro::LMG::microaxis_X4.X, -10.f, 10.0f, "%0.1f");
				ImGui::SliderFloat(xorstr_("Axis Y ##10"), &Settings::Micro::LMG::microaxis_X4.Y, 1.0f, 10.0f, "%0.1f");
			}

			break;
		default:
			break;
		}
		

		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (52 / 2));
		ImGui::Text(xorstr_("General"));
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::BeginChild(xorstr_("##misc-4"), ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::Checkbox(xorstr_("Total Players"), &Settings::Screen::TotalPlayers);
		ImGui::Checkbox(xorstr_("Player Aiming"), &Settings::Screen::PlayerAiming);
		ImGui::Checkbox(xorstr_("Server Info"), &Settings::Screen::ServerInfo);

		ImGui::EndChild();


		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();



	}
	void tab_Color()
	{
		loop(3)ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.20f, 0.20f, 0.20f, 0.20f));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SameLine((290 / 2) - (75 / 2));
		ImGui::Text(xorstr_("Players"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##colors-1"), ImVec2(290, 362), true);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* player_esp[] = { "Enemy","Team","Bot" };
		RENDER_TAB_SAMELINE(player_esp, Settings::UI::colors_players, 280 / 3, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();

		switch (Settings::UI::colors_players)
		{
		case 0:
			ImGui::ColorEdit3(xorstr_("Box"), Settings::Color::Players::Enemy::box);
			ImGui::ColorEdit3(xorstr_("Snapline"), Settings::Color::Players::Enemy::snapline);
			ImGui::ColorEdit3(xorstr_("Skeleton"), Settings::Color::Players::Enemy::skeleton);
			ImGui::ColorEdit3(xorstr_("DirectionLine"), Settings::Color::Players::Enemy::directionLine);
			ImGui::ColorEdit3(xorstr_("Knocked"), Settings::Color::Players::Enemy::knocked);
			ImGui::ColorEdit3(xorstr_("Spot"), Settings::Color::Players::Enemy::spot);
			ImGui::ColorEdit3(xorstr_("Weapon Warning"), Settings::Color::Players::Enemy::weaponwarning);


			break;
		case 1:
			ImGui::ColorEdit3(xorstr_("Box##2"), Settings::Color::Players::Team::box);
			ImGui::ColorEdit3(xorstr_("Snapline##2"), Settings::Color::Players::Team::snapline);
			ImGui::ColorEdit3(xorstr_("Skeleton##2"), Settings::Color::Players::Team::skeleton);
			ImGui::ColorEdit3(xorstr_("DirectionLine##2"), Settings::Color::Players::Team::directionLine);
			ImGui::ColorEdit3(xorstr_("Knocked##2"), Settings::Color::Players::Team::knocked);
			ImGui::ColorEdit3(xorstr_("Spot##2"), Settings::Color::Players::Team::spot);
			ImGui::ColorEdit3(xorstr_("Weapon Warning##2"), Settings::Color::Players::Team::weaponwarning);

			break;
		case 2:
			ImGui::ColorEdit3(xorstr_("Box##3"), Settings::Color::Players::Bot::box);
			ImGui::ColorEdit3(xorstr_("Snapline##3"), Settings::Color::Players::Bot::snapline);
			ImGui::ColorEdit3(xorstr_("Skeleton##3"), Settings::Color::Players::Bot::skeleton);
			ImGui::ColorEdit3(xorstr_("DirectionLine##3"), Settings::Color::Players::Bot::directionLine);
			ImGui::ColorEdit3(xorstr_("Knocked##3"), Settings::Color::Players::Bot::knocked);
			ImGui::ColorEdit3(xorstr_("Spot##3"), Settings::Color::Players::Bot::spot);
			ImGui::ColorEdit3(xorstr_("WeaponWarning##2"), Settings::Color::Players::Bot::weaponwarning);

			break;
		}

		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (115 / 2));
		ImGui::Text(xorstr_("Vehicles"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##colors-2"), ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::ColorEdit3(xorstr_("Box##4"), Settings::Color::Vehicle::Box);
		ImGui::ColorEdit3(xorstr_("Name##4"), Settings::Color::Vehicle::Name);
		ImGui::ColorEdit3(xorstr_("DirectionLine##4"), Settings::Color::Vehicle::DirectionLine);
		ImGui::ColorEdit3(xorstr_("Velocity##4"), Settings::Color::Vehicle::velocity);

		ImGui::EndChild();


		ImGui::NextColumn();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (70 / 2));
		ImGui::Text(xorstr_("Items"));
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
		ImGui::BeginChild(xorstr_("##colors-3"), ImVec2(290, 362), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* other_esp_char[] = { "Items","Other" };
		RENDER_TAB_SAMELINE(other_esp_char, Settings::UI::colors_items, 280 / 2, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();
		switch (Settings::UI::colors_items)
		{
		case 0:
			ImGui::ColorEdit3(xorstr_("Special"), Settings::Color::Loot::special);
			ImGui::ColorEdit3(xorstr_("AR"), Settings::Color::Loot::ar);
			ImGui::ColorEdit3(xorstr_("SMG"), Settings::Color::Loot::smg);
			ImGui::ColorEdit3(xorstr_("Sniper"), Settings::Color::Loot::sniper);
			ImGui::ColorEdit3(xorstr_("Machine Gun"), Settings::Color::Loot::other);
			ImGui::ColorEdit3(xorstr_("Shotgun"), Settings::Color::Loot::shotgun);
			ImGui::ColorEdit3(xorstr_("Helmet"), Settings::Color::Loot::helmet);
			ImGui::ColorEdit3(xorstr_("Armor"), Settings::Color::Loot::armor);
			ImGui::ColorEdit3(xorstr_("Backpack"), Settings::Color::Loot::backpack);
			ImGui::ColorEdit3(xorstr_("Scope"), Settings::Color::Loot::scopes);
			ImGui::ColorEdit3(xorstr_("Accessories"), Settings::Color::Loot::accessories);
			ImGui::ColorEdit3(xorstr_("Energy"), Settings::Color::Loot::energy);
			ImGui::ColorEdit3(xorstr_("Grenade"), Settings::Color::Loot::grenade);
			ImGui::ColorEdit3(xorstr_("Bicycle"), Settings::Color::Loot::bicycle);

			break;
		case 1:
			ImGui::ColorEdit3(xorstr_("Deadbox"), Settings::Color::Other::deadbox);
			ImGui::ColorEdit3(xorstr_("AirDrop"), Settings::Color::Other::AirDrop);
			ImGui::ColorEdit3(xorstr_("Treasure Chest"), Settings::Color::Other::treasurechest);
			ImGui::ColorEdit3(xorstr_("Inventory Details"), Settings::Color::Other::InventoryDetails);
			break;
		default:
			break;
		}

		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (52 / 2));
		ImGui::Text(xorstr_("Radar"));
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::BeginChild(xorstr_("##colors-4"), ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::ColorEdit3(xorstr_("Enemy##5"), Settings::Color::Radar::Enemy);
		ImGui::ColorEdit3(xorstr_("Team##5"), Settings::Color::Radar::Team);
		ImGui::ColorEdit3(xorstr_("Bot##5"), Settings::Color::Radar::BOT);
		ImGui::ColorEdit3(xorstr_("Vehicle##5"), Settings::Color::Radar::Vehicle);
		ImGui::ColorEdit3(xorstr_("AirDrop##5"), Settings::Color::Radar::AirDrop);


		ImGui::EndChild();


		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
	inline void AddUnderLine(ImColor col_)
	{
		ImVec2 min = ImGui::GetItemRectMin();
		ImVec2 max = ImGui::GetItemRectMax();
		min.y = max.y;
		ImGui::GetWindowDrawList()->AddLine(min, max, col_, 1.0f);
	}

	inline void TextURL(const char* name_, const char* URL_, int SameLineBefore_, int SameLineAfter_)
	{
		if (1 == SameLineBefore_) { ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x); }
		ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered]);
		ImGui::Text(name_);
		ImGui::PopStyleColor();
		if (ImGui::IsItemHovered())
		{
			if (ImGui::IsMouseClicked(0))
			{
				string myurl = string(reinterpret_cast<const string::value_type*>(URL_));
				system(std::string("start " + myurl).c_str());
			}
			AddUnderLine(ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered]);
			ImGui::SetTooltip( "  Server Nimrod\n%s", URL_);
		}
		else
		{
			AddUnderLine(ImGui::GetStyle().Colors[ImGuiCol_Button]);
		}
		if (1 == SameLineAfter_) { ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x); }
	}
	void tab_Settings()
	{
		loop(2) ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.20f, 0.20f, 0.20f, 0.20f));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		/**/
		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (35 / 2));
		ImGui::Text(xorstr_("Config"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##settings-1"), ImVec2(290, 300), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::NewLine();
		static int iConfigSelect = 0;
		static int iMenuSheme = 1;
		std::string ConfigName = "Config";
		ImGui::ComboBoxArray(xorstr_("Select Config"), &iConfigSelect, Utils::ConfigList);
		ImGui::Separator();
		if (ImGui::Button(xorstr_("Create")))
		{
			std::string ConfigFileName = ConfigName.append(std::to_string((int)Utils::ConfigList.size() + 1));

			if (ConfigFileName.size() < 1)
			{
				ConfigFileName = "";
			}
			if (ConfigFileName != "") {
				Config::SaveSettings(xorstr_(".\\Res\\Config\\") + ConfigFileName + ".ini");
				Utils::RefreshConfigs(xorstr_(".\\Res\\Config\\*.ini"));
			}
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr_("Save")))
		{
			if (Utils::ConfigList.size() != 0)
			{
				Config::SaveSettings(xorstr_(".\\Res\\Config\\") + Utils::ConfigList[iConfigSelect]);
				Utils::RefreshConfigs(xorstr_(".\\Res\\Config\\*.ini"));
			}
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr_("Load")))
		{
			if (Utils::ConfigList.size() != 0)
			{
				Config::LoadSettings(xorstr_(".\\Res\\Config\\") + Utils::ConfigList[iConfigSelect]);
				Utils::RefreshConfigs(xorstr_(".\\Res\\Config\\*.ini"));
			}
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr_("Delete")))
		{
			if (Utils::ConfigList.size() != 0)
			{
				std::string szIniFile = xorstr_(".\\Res\\Config\\") + Utils::ConfigList[iConfigSelect];
				remove(szIniFile.c_str());
				Utils::RefreshConfigs(xorstr_(".\\Res\\Config\\*.ini"));
			}
		}
		ImGui::NewLine();
		ImGui::EndChild();
		/**/
		ImGui::NextColumn();
		/**/
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (ImGui::CalcTextSize("General").x / 2));
		ImGui::Text(xorstr_("General"));
		ImGui::PopFont();
		ImGui::BeginChild(xorstr_("##settings-2"), ImVec2(290, 300), true);
		ImGui::NewLine();
		ImGui::Checkbox(xorstr_("Vsync"), &Settings::Setting::vsync);
		if (Settings::Setting::vsync == true)
			ImGui::Combo(xorstr_("FPS"), &Settings::Setting::fps, xorstr_("30\0 60\0 90"));
		//ImGui::Checkbox("Watermark", &Settings::Menu::watermark);
		//ImGui::Checkbox("Draw Dots", &Settings::Menu::drawdots);
		//ImGui::Checkbox("Chroma Menu", &Settings::Menu::chroma_menu);
		if (Settings::Menu::chroma_menu == false)
			ImGui::ColorEdit3("##menu_color", Settings::Color::Menu::color, ImGuiColorEditFlags_NoInputs);  ImGui::SameLine(); ImGui::Text("Menu color");
		
	
		


		ImGui::EndChild();
		
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::NextColumn();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (290 / 2));
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##settings-3"), ImVec2(500, 600), true);
		ImGui::NewLine(); 
		ImGui::Separator();
		ImGui::Text(xorstr_("User Information"));
		ImGui::Text(xorstr_("User Name: "));
		ImGui::SameLine();
		ImGui::Text(apiinfo::user.c_str());
		ImGui::Text(xorstr_("User Online: "));
		ImGui::SameLine();
		ImGui::Text(apiinfo::NumOnlineUsers.c_str());

		ImGui::Text(xorstr_("Expire Date: "));
		ImGui::SameLine();
		ImGui::Text(apiinfo::_expire.c_str());
		ImGui::Separator();

		ImGui::EndChild();
	}

	void tab_Main()
	{

		static int Tab = 0;
		char* tabs[] = { "Aimbot","Visuals","Misc","Colors","Settings" };
		
		ImGui::SetNextWindowSize(ImVec2(850, 660));
		ImGui::Begin(xorstr_("##teste"), &Globals::isopened, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + 850, p.y + +5), ImGui::GetColorU32(ImGuiCol_ButtonActive));
		ImGui::PopStyleVar();
		ImGui::Columns(2, NULL, false);

		static float initial_spacing = 225.f;
		if (initial_spacing)
			ImGui::SetColumnWidth(0, initial_spacing), initial_spacing = 0;

		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 16);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 20);
		ImGui::BeginChild("##1", ImVec2(190, 605), true);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
		ImGui::NewLine(); ImGui::NewLine();
		ImGui::SameLine((160 / 2) - (100 / 2));
		ImGui::Image((void*)(intptr_t)Icons::Logo, ImVec2(128, 128));
		ImGui::NewLine();



		ImGui::NewLine(); ImGui::NewLine(); ImGui::NewLine();
		RENDER_TAB(tabs, Tab, 160, 40);

		ImGui::EndChild();

		ImGui::NextColumn();

		ImGui::PushItemWidth(623);
		ImGui::BeginChild(xorstr_("##2"), ImVec2(623, 660), false);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + 850, p.y + +5), ImGui::GetColorU32(ImGuiCol_ButtonActive) /*ImColor::HSV(rainbow,1.f,1.f)*/);
		ImGui::PopStyleVar();
		ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
		switch (Tab)
		{
		case 0:
			tab_Aimbot();
			break;
		case 1:
			tab_Visuals();
			break;
		case 2:
			tab_Misc();
			break;
		case 3:
			tab_Color();
			break;
		case 4:
			tab_Settings();
			break;
		default:
			break;
		}
		
		

		ImGui::EndChild();
		ImGui::PopItemWidth();

		ImGui::Columns(1, NULL, false);

		ImGui::End();
	}
	void init()
	{

		Settings::Color::rainbow += 0.0005f;
		if (Settings::Color::rainbow > 1.f)
			Settings::Color::rainbow = 0.f;

		float c[3] = { 1.f,1.f,1.f };
		if (Settings::Color::Menu::color != c)
			CreateStyle();
		if (Settings::Menu::chroma_menu)
			CreateStyle();

		if (Globals::isopened)
		{
			tab_Main();
		}
	}

	


}