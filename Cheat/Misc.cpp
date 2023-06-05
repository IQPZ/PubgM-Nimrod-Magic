#include "Includes.h"

namespace Misc
{
	void DrawingGameState()
	{
		auto& style = ImGui::GetStyle();
		style.Alpha = 1.f;
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1, 0.1f, 1.f);
		ImGui::SetNextWindowPos(ImVec2(200, 0), ImGuiWindowFlags_NoScrollbar);
		ImGui::SetNextWindowBgAlpha(0.50f);
		if (ImGui::Begin(xorstr_("Server Info"), &Settings::Screen::ServerInfo, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			std::string num1 = "-";
			std::string num2 = "-";
			std::string num3 = "-";
			std::string num4 = "-";
			std::string num5 = "-";

			if (IsInGame == true) {
				num1 = std::to_string(EntityGameState[0].PlayerNumPerTeam);
				num2 = std::to_string(EntityGameState[0].PlayerNum);
				num3 = std::to_string(EntityGameState[0].AlivePlayerNum);
				num4 = std::to_string(EntityGameState[0].AliveTeamNum);
				num5 = EntityGameState[0].ElapsedTime;
			}
			ImGui::SetWindowSize(ImVec2(210, 130));
			ImGui::Separator();
			ImGui::Text(std::string("Total Player Per Team: ").append(num1).c_str());
			ImGui::Separator();
			ImGui::Text(std::string("Total Players: ").append(num2).c_str());
			ImGui::Separator();
			ImGui::Text(std::string("Alive Players: ").append(num3).c_str());
			ImGui::Separator();
			ImGui::Text(std::string("Alive Team: ").append(num4).c_str());
			ImGui::Separator();
			ImGui::Text(std::string("Elapsed Time: ").append(num5).c_str());
			ImGui::Separator();
			ImGui::End();
		}

	}


	void DrawingAimingList()
	{
		Manager gm(Globals::width, Globals::height);
		int players = 0;
		int weapons = 0;
		int scopes = 0;
		std::string PlayerName = "";
		std::string WeaponName = "";
		std::string ScopeName = "";
		for (Player& player : gm.Players) {
			if (player.IsBot == false && player.Health > 0 && player.Team != gm.LocalPlayer.Team && (GnameType::playerstatus(player.status) == "Aiming" || GnameType::playerstatus(player.status) == "Firing") || GnameType::playerstatus(player.status) == "Peek") {
				auto delta = (player.origin - CameraCacheEntry.Location);
				FRotator ideal = (delta.ToRotator()).ClampAngles();
				auto angDelta = (ideal - player.RelativeRotation).ClampAngles();
				float angFOV = angDelta.Size() - player.ScopeFov;
				bool aiming = false;
				if (GnameType::scopes((int)player.ScopeFov) == "Iron")
				{
					if (angFOV >= 109.000f && angFOV <= 109.999f)
					{
						aiming = true;
					}
				}
				else if (GnameType::scopes((int)player.ScopeFov) == "RedDot")
				{
					if (angFOV >= 123.000f && angFOV <= 124.999f)
					{
						aiming = true;
					}
				}
				else if (GnameType::scopes((int)player.ScopeFov) == "X2")
				{
					if (angFOV >= 134.000f && angFOV <= 135.999f)
					{
						aiming = true;
					}
				}
				else if (GnameType::scopes((int)player.ScopeFov) == "X3")
				{
					if (angFOV >= 152.000f && angFOV <= 153.999f)
					{
						aiming = true;
					}
				}
				else if (GnameType::scopes((int)player.ScopeFov) == "X4")
				{
					if (angFOV >= 158.000f && angFOV <= 159.999f)
					{
						aiming = true;
					}
				}
				else if (GnameType::scopes((int)player.ScopeFov) == "X6")
				{
					if (angFOV >= 165.000f && angFOV <= 166.999f)
					{
						aiming = true;
					}
				}
				else if (GnameType::scopes((int)player.ScopeFov) == "X8")
				{
					if (angFOV >= 167.000f && angFOV <= 168.999f)
					{
						aiming = true;
					}
				}
				else {
					aiming = false;
				}
				if (aiming)
				{

					auto pNamePlate = player.Name;
					auto pPlayerWeapon = GnameType::PlayerWeapon(player.weapon);
					auto pPlayerscope = GnameType::scopes((int)player.ScopeFov);
					if (pNamePlate != "") {
						PlayerName += pNamePlate;
						PlayerName += "\n";
						players++;

						WeaponName += pPlayerWeapon;
						WeaponName += "\n";
						weapons++;

						ScopeName += pPlayerscope;
						ScopeName += "\n";
						scopes++;
					}

				}
			}

		}
		auto& style = ImGui::GetStyle();
		style.Alpha = 1.f;
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1, 0.1f, 1.f);
		ImGui::SetNextWindowPos(ImVec2(200, 0), ImGuiWindowFlags_NoScrollbar);
		if (ImGui::Begin(xorstr_("Aiming At You"), &Settings::Screen::PlayerAiming, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			if (players > 0) PlayerName += "\n";
			if (weapons > 0) WeaponName += "\n";
			if (scopes > 0) ScopeName += "\n";
			ImVec2 size = ImGui::CalcTextSize(PlayerName.c_str());
			ImGui::SetWindowSize(ImVec2(200, 80 + size.y));
			ImGui::Columns(3);
			ImGui::Separator();

			ImGui::Text("Player");
			ImGui::NextColumn();

			ImGui::Text("Weapon");
			ImGui::NextColumn();

			ImGui::Text("Scope");
			ImGui::NextColumn();
			ImGui::Separator();

			ImGui::Text(PlayerName.c_str());
			ImGui::NextColumn();

			ImGui::Text(WeaponName.c_str());
			ImGui::NextColumn();

			ImGui::Text(ScopeName.c_str());
			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::End();
		}

	}
	void DrawingTotalPlayers()
	{
		Manager gm(Globals::width, Globals::height);
		ImGui::SetNextWindowBgAlpha(0.50f);
		std::string dis = std::to_string((int)gm.ClosestVisibleEnemy.Distance).append(" M").c_str();
		std::string c_players = "Player ";
		std::string c_bots = "Bot ";
		std::string c_Dis = "Closest Distance ";

		auto& style = ImGui::GetStyle();
		style.Alpha = 1.f;
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1, 0.1f, 1.f);
		ImGui::SetNextWindowPos(ImVec2(500, 0), ImGuiWindowFlags_NoScrollbar);
		if (ImGui::Begin(xorstr_("TotalPlayers"), &Settings::Screen::TotalPlayers, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::SetWindowSize(ImVec2(200, 57));
			ImGui::Separator();
			ImGui::PushFont(m_FVisuals);
			ImGui::Text(c_players.append(std::to_string((int)TotalEnemy)).c_str());
			ImGui::SameLine(100);
			ImGui::Text(c_bots.append(std::to_string((int)TotalBots)).c_str());
			ImGui::Separator();
			ImGui::Text(c_Dis.append(dis).c_str());
			ImGui::PopFont();
			ImGui::Separator();
			ImGui::End();
		}

	}
	void DrawRadars()
	{
		auto& style = ImGui::GetStyle();
		style.Alpha = 1.f;
		style.Colors[ImGuiCol_TitleBg] = ImColor(21, 21, 21, 255);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(21, 21, 21, 255);
		style.Colors[ImGuiCol_TitleBgActive] = ImColor(21, 21, 21, 255);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1, 0.1f, 1.f);
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiWindowFlags_NoScrollbar);

		if (ImGui::Begin("Radar", &Settings::Radar::enable, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar))
		{
			ImVec2 siz = ImGui::GetContentRegionAvail();
			ImVec2 pos = ImGui::GetCursorScreenPos();
			float RadarCenterX = pos.x + (siz.x / 2);
			float RadarCenterY = pos.y + (siz.y / 2);
			if (!Settings::Menu::chroma_menu)
				GL3Draw::GetInstance()->RenderRect(ImVec2(pos.x, pos.y), ImVec2(pos.x + siz.x, pos.y + siz.y), D3DXCOLOR(Settings::Color::Menu::color[0], Settings::Color::Menu::color[1], Settings::Color::Menu::color[2], 1.f), 0.0F, -1, 1.5f);
			else
				GL3Draw::GetInstance()->RenderRect(ImVec2(pos.x, pos.y), ImVec2(pos.x + siz.x, pos.y + siz.y), ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f), 0.0F, -1, 1.5f);

			GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(RadarCenterX, RadarCenterY), 2, ImGui::GetColorU32(ImVec4(100, 100, 100, 100)));
			D3DXCOLOR Chosencolor = D3DXCOLOR();
			Manager gm(Globals::width, Globals::height);
			D3DXCOLOR PlayerColor = D3DXCOLOR();
			D3DXCOLOR VehicleColor = D3DXCOLOR();
			D3DXCOLOR AirDrop = D3DXCOLOR();

			for (Player& player : gm.Players) {
				if (player.Team == gm.LocalPlayer.Team)
				{
					PlayerColor = D3DXCOLOR(Settings::Color::Radar::Team[0], Settings::Color::Radar::Team[1], Settings::Color::Radar::Team[2], 1.f);

				}
				else if (player.IsBot == true)
				{
					PlayerColor = D3DXCOLOR(Settings::Color::Radar::BOT[0], Settings::Color::Radar::BOT[1], Settings::Color::Radar::BOT[2], 1.f);
				}
				else
				{
					PlayerColor = D3DXCOLOR(Settings::Color::Radar::Enemy[0], Settings::Color::Radar::Enemy[1], Settings::Color::Radar::Enemy[2], 1.f);

				}
				float dis = CameraCacheEntry.Location.Distance(player.origin) / 100.f;

				FVector2D single = Utils::WorldToRadar(CameraCacheEntry.Rotation, CameraCacheEntry.Location, player.origin, FVector2D(pos.x, pos.y), FVector2D(siz.x, siz.y));
				if checkSetting(Settings::Radar::teamRadar, Settings::Radar::enemyRadar)
				{
					if (dis >= 0.f && dis < Settings::Radar::distance_Radar)
					{
						if (Settings::Radar::radartype == 0)
							GL3Draw::GetInstance()->RenderText(m_FVisuals, std::to_string((int)dis), ImVec2(single.X, single.Y), 12, PlayerColor);
						else
							GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(single.X, single.Y), 3, PlayerColor);

					}
				}
			}
			for (Vehicle& vehicle : gm.Vehicles)
			{
				if (vehicle.ReplicatedMovement.LinearVelocity.Size() > 100)
				{
					VehicleColor = D3DXCOLOR(Settings::Color::Radar::Vehicle[0], Settings::Color::Radar::Vehicle[1], Settings::Color::Radar::Vehicle[2], 1.f);
					float dis = CameraCacheEntry.Location.Distance(vehicle.origin) / 100.f;

					FVector2D single = Utils::WorldToRadar(CameraCacheEntry.Rotation, CameraCacheEntry.Location, vehicle.origin, FVector2D(pos.x, pos.y), FVector2D(siz.x, siz.y));
					if (Settings::Radar::vehicleRadar)
					{
						if (dis >= 0.f && dis < Settings::Radar::distance_Radar)
						{
							if (Settings::Radar::radartype == 0)
								GL3Draw::GetInstance()->RenderText(m_FVisuals, std::to_string((int)dis), ImVec2(single.X, single.Y), 12, VehicleColor);
							else
								GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(single.X, single.Y), 3, VehicleColor);
						}
					}
				}
			}

			for (Inventory& inventory : gm.Inventorys)
			{
				if (GnameType::IsAirDropBox(inventory.items))
				{
					AirDrop = D3DXCOLOR(Settings::Color::Radar::AirDrop[0], Settings::Color::Radar::AirDrop[1], Settings::Color::Radar::AirDrop[2], 1.f);
					float dis = CameraCacheEntry.Location.Distance(inventory.origin) / 100.f;

					FVector2D single = Utils::WorldToRadar(CameraCacheEntry.Rotation, CameraCacheEntry.Location, inventory.origin, FVector2D(pos.x, pos.y), FVector2D(siz.x, siz.y));
					if (Settings::Radar::airdropRadar)
					{
						if (dis >= 0.f && dis < Settings::Radar::distance_Radar)
						{
							if (Settings::Radar::radartype == 0)
								GL3Draw::GetInstance()->RenderText(m_FVisuals, std::to_string((int)dis), ImVec2(single.X, single.Y), 12, AirDrop);
							else
								GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(single.X, single.Y), 3, AirDrop);
						}
					}
				}

			}
		}ImGui::End();
	}
	void Crosshair()
	{
		switch (Settings::Crosshair::crosshair)
		{
		case GL3Draw::CrosshairStyle::Dot:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Dot, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Plus:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Plus, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Cross:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Cross, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Gap:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Gap, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Diagonal:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Diagonal, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Swastika:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Swastika, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::HitMaker:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::HitMaker, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		default:
			break;
		}

	}
	void RCS()
	{
		for (;;)
		{
			bool Enable = false;
			FVector2D MicroAxis = {};
			if ((Utils::keydown(VK_LBUTTON)))
			{
				if (MyLocalPlayer.bIsWeaponFiring == true && MyLocalPlayer.bIsGunADS == true) {

					if (GnameType::Weapon_IsAR(MyLocalPlayer.weapon))
					{
						if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "Iron")
						{
							Enable = Settings::Micro::AR::micro_Iron;
							MicroAxis.X = Settings::Micro::AR::microaxis_Iron.X;
							MicroAxis.Y = Settings::Micro::AR::microaxis_Iron.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "RedDot")
						{
							Enable = Settings::Micro::AR::micro_RedDot;
							MicroAxis.X = Settings::Micro::AR::microaxis_RedDot.X;
							MicroAxis.Y = Settings::Micro::AR::microaxis_RedDot.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X2")
						{
							Enable = Settings::Micro::AR::micro_X2;
							MicroAxis.X = Settings::Micro::AR::microaxis_X2.X;
							MicroAxis.Y = Settings::Micro::AR::microaxis_X2.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X3")
						{
							Enable = Settings::Micro::AR::micro_X3;
							MicroAxis.X = Settings::Micro::AR::microaxis_X3.X;
							MicroAxis.Y = Settings::Micro::AR::microaxis_X3.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X4")
						{
							Enable = Settings::Micro::AR::micro_X4;
							MicroAxis.X = Settings::Micro::AR::microaxis_X4.X;
							MicroAxis.Y = Settings::Micro::AR::microaxis_X4.Y;
						}
						else
						{
							Enable = false;
							MicroAxis.X = 0;
							MicroAxis.Y = 0;

						}
					}
					else if (GnameType::Weapon_IsSMG(MyLocalPlayer.weapon))
					{
						if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "Iron")
						{
							Enable = Settings::Micro::SMG::micro_Iron;
							MicroAxis.X = Settings::Micro::SMG::microaxis_Iron.X;
							MicroAxis.Y = Settings::Micro::SMG::microaxis_Iron.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "RedDot")
						{
							Enable = Settings::Micro::SMG::micro_RedDot;
							MicroAxis.X = Settings::Micro::SMG::microaxis_RedDot.X;
							MicroAxis.Y = Settings::Micro::SMG::microaxis_RedDot.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X2")
						{
							Enable = Settings::Micro::SMG::micro_X2;
							MicroAxis.X = Settings::Micro::SMG::microaxis_X2.X;
							MicroAxis.Y = Settings::Micro::SMG::microaxis_X2.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X3")
						{
							Enable = Settings::Micro::SMG::micro_X3;
							MicroAxis.X = Settings::Micro::SMG::microaxis_X3.X;
							MicroAxis.Y = Settings::Micro::SMG::microaxis_X3.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X4")
						{
							Enable = Settings::Micro::SMG::micro_X4;
							MicroAxis.X = Settings::Micro::SMG::microaxis_X4.X;
							MicroAxis.Y = Settings::Micro::SMG::microaxis_X4.Y;
						}
						else
						{
							Enable = false;
							MicroAxis.X = 0;
							MicroAxis.Y = 0;

						}
					}
					else if (GnameType::Weapon_IsOther(MyLocalPlayer.weapon))
					{
						if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "Iron")
						{
							Enable = Settings::Micro::LMG::micro_Iron;
							MicroAxis.X = Settings::Micro::LMG::microaxis_Iron.X;
							MicroAxis.Y = Settings::Micro::LMG::microaxis_Iron.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "RedDot")
						{
							Enable = Settings::Micro::LMG::micro_RedDot;
							MicroAxis.X = Settings::Micro::LMG::microaxis_RedDot.X;
							MicroAxis.Y = Settings::Micro::LMG::microaxis_RedDot.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X2")
						{
							Enable = Settings::Micro::LMG::micro_X2;
							MicroAxis.X = Settings::Micro::LMG::microaxis_X2.X;
							MicroAxis.Y = Settings::Micro::LMG::microaxis_X2.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X3")
						{
							Enable = Settings::Micro::LMG::micro_X3;
							MicroAxis.X = Settings::Micro::LMG::microaxis_X3.X;
							MicroAxis.Y = Settings::Micro::LMG::microaxis_X3.Y;

						}
						else if (GnameType::scopes((int)MyLocalPlayer.ScopeFov) == "X4")
						{
							Enable = Settings::Micro::LMG::micro_X4;
							MicroAxis.X = Settings::Micro::LMG::microaxis_X4.X;
							MicroAxis.Y = Settings::Micro::LMG::microaxis_X4.Y;
						}
						else
						{
							Enable = false;
							MicroAxis.X = 0;
							MicroAxis.Y = 0;

						}
					}
					else
					{
					Enable = false;
					MicroAxis.X = 0;
					MicroAxis.Y = 0;

					}
					if (Enable) {
						FVector2D GetMicroAxis = MicroAxis;
						Inputs::mouse_move(GetMicroAxis.X, GetMicroAxis.Y);

					}

				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}

	void RunDraw()
	{
		if(Settings::Screen::ServerInfo)
		DrawingGameState();

		if (Settings::Crosshair::c_enable)
			Crosshair();

		if (Settings::Screen::PlayerAiming)
			DrawingAimingList();

		if (Settings::Screen::TotalPlayers)
			DrawingTotalPlayers();

		if (Settings::Radar::enable)
			DrawRadars();


	}
	void Run()
	{
		RCS();
	}
}