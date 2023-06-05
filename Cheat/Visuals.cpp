#include "Includes.h"
namespace Visuals
{
#pragma region utils drawing
	void RenderCircle3D(Manager gm, FVector position, float points, float radius, D3DXCOLOR color)
	{
		float step = (float)M_PI * 2.0f / points;

		for (float a = 0; a < (M_PI * 2.0f); a += step)
		{
			FVector start(radius * cosf(a) + position.X, radius * sinf(a) + position.Y, position.Z);
			FVector end(radius * cosf(a + step) + position.X, radius * sinf(a + step) + position.Y, position.Z);

			FVector start2d, end2d;
			if (!gm.WorldToScreen(start, start2d) || !gm.WorldToScreen(end, end2d))
				return;

			GL3Draw::GetInstance()->RenderLine(ImVec2(start2d.X, start2d.Y), ImVec2(end2d.X, end2d.Y), color, 1.f);

		}
	}

	void DrawBoneHead(Manager gm, Player pEnemySoldier, FVector from, D3DXCOLOR color, float distanceValue)
	{
		float kalinlik = Settings::ESP::Options::Skeletonthickness;

		FVector W2S_from = from;
		FVector oW2S_from;
		FVector vecScreenOrgin;
		FVector ovecScreenOrgin;
		if (!gm.WorldToScreen(W2S_from, oW2S_from)) return;
		if (!gm.WorldToScreen(pEnemySoldier.Bones.A0, ovecScreenOrgin)) return;

		GL3Draw::GetInstance()->RenderCircle(ImVec2(oW2S_from.X, oW2S_from.Y), (ovecScreenOrgin.Y - oW2S_from.Y) / 10, color, kalinlik);
	}
	void DrawBone(Manager gm, FVector from, FVector to, D3DXCOLOR color, float distanceValue)
	{
		float kalinlik = Settings::ESP::Options::Skeletonthickness;
		FVector W2S_from = from;
		FVector oW2S_from;
		if (!gm.WorldToScreen(W2S_from, oW2S_from)) return;
		FVector  W2S_to = to;
		FVector oW2S_to;
		if (!gm.WorldToScreen(W2S_to, oW2S_to)) return;
		GL3Draw::GetInstance()->RenderLine(ImVec2(oW2S_from.X, oW2S_from.Y), ImVec2(oW2S_to.X, oW2S_to.Y), color, kalinlik);
	}
	void DrawSkeletonESP(Manager gm, Player pEnemySoldier, D3DXCOLOR Color)
	{
		DrawBoneHead(gm, pEnemySoldier, pEnemySoldier.Bones.A6, Color, pEnemySoldier.Distance);

		DrawBone(gm, pEnemySoldier.Bones.A5, pEnemySoldier.Bones.A4, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A4, pEnemySoldier.Bones.A3, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A3, pEnemySoldier.Bones.A2, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A2, pEnemySoldier.Bones.A1, Color, pEnemySoldier.Distance);

		DrawBone(gm, pEnemySoldier.Bones.A1, pEnemySoldier.Bones.A53, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A1, pEnemySoldier.Bones.A57, Color, pEnemySoldier.Distance);

		DrawBone(gm, pEnemySoldier.Bones.A5, pEnemySoldier.Bones.A11, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A5, pEnemySoldier.Bones.A32, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A11, pEnemySoldier.Bones.A12, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A32, pEnemySoldier.Bones.A33, Color, pEnemySoldier.Distance);

		DrawBone(gm, pEnemySoldier.Bones.A33, pEnemySoldier.Bones.A34, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A34, pEnemySoldier.Bones.A35, Color, pEnemySoldier.Distance);

		DrawBone(gm, pEnemySoldier.Bones.A12, pEnemySoldier.Bones.A13, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A13, pEnemySoldier.Bones.A14, Color, pEnemySoldier.Distance);

		DrawBone(gm, pEnemySoldier.Bones.A57, pEnemySoldier.Bones.A58, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A58, pEnemySoldier.Bones.A59, Color, pEnemySoldier.Distance);

		DrawBone(gm, pEnemySoldier.Bones.A53, pEnemySoldier.Bones.A54, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.A54, pEnemySoldier.Bones.A55, Color, pEnemySoldier.Distance);
	}
	void box3d_lines(Manager gm, FVector center, float x1, float y1, float z1, float x2, float y2, float z2, D3DXCOLOR col, float thickness = 1)
	{
		FVector pointPos1 = { center.X + x1, center.Y + y1, center.Z + z1 };
		FVector pointPos2 = { center.X + x2, center.Y + y2, center.Z + z2 };

		FVector sxy1;
		if (!gm.WorldToScreen(pointPos1, sxy1)) return;
		FVector sxy2;
		if (!gm.WorldToScreen(pointPos2, sxy2)) return;

		if (sxy1.X != 0 || sxy1.Y != 0 || sxy2.X != 0 || sxy2.Y != 0)
			GL3Draw::GetInstance()->RenderLine(ImVec2(sxy1.X, sxy1.Y), ImVec2(sxy2.X, sxy2.Y), col, thickness);
	}
	void box3d(Manager gm, FVector center, float w, float h, D3DXCOLOR col, float thickness = 1)
	{
#define padding 10
		box3d_lines(gm, center, -w, -w, 0, w, -w, 0, col, thickness);
		box3d_lines(gm, center, -w, -w, h, w, -w, h, col, thickness);

		box3d_lines(gm, center, -w, -w, 0, -w, -w, h, col, thickness);
		box3d_lines(gm, center, w, -w, 0, w, -w, h, col, thickness);

		box3d_lines(gm, center, w, w + padding, 0, w, w + padding, h, col, thickness);
		box3d_lines(gm, center, -w, w + padding, 0, -w, w + padding, h, col, thickness);
		box3d_lines(gm, center, w, w + padding, 0, -w, w + padding, 0, col, thickness);
		box3d_lines(gm, center, w, w + padding, h, -w, w + padding, h, col, thickness);

		box3d_lines(gm, center, -w, -w, 0, -w, w + padding, 0, col, thickness);
		box3d_lines(gm, center, w, w + padding, 0, w, -w, 0, col, thickness);
		box3d_lines(gm, center, -w, -w, h, -w, w + padding, h, col, thickness);
		box3d_lines(gm, center, w, w + padding, h, w, -w, h, col, thickness);
	}

#pragma endregion
	void ESP()
	{
		if (GetAsyncKeyState(Settings::ESP::Options::FightModeKey)) {
			Settings::ESP::Options::FightMode = !Settings::ESP::Options::FightMode;
			Sleep(150);
		}
		Manager gm(Globals::width, Globals::height);

		for (Player& player : gm.Players) {
			FVector footLocation = player.origin;
			FVector headLocation = footLocation;
			footLocation.Z -= 100;
			FVector oheadLocation = FVector();
			FVector ofootLocation = FVector();

			D3DXCOLOR PlayerBox = D3DXCOLOR();
			D3DXCOLOR PlayerSnapline = D3DXCOLOR();
			D3DXCOLOR PlayerSkeleton = D3DXCOLOR();
			D3DXCOLOR PlayerDirectionLine = D3DXCOLOR();
			D3DXCOLOR PlayerKnocked = D3DXCOLOR();
			D3DXCOLOR PlayerSpot = D3DXCOLOR();
			D3DXCOLOR PlayerWeaponWarning = D3DXCOLOR();

			std::vector<Text> PlayerTexts = std::vector<Text>();

			if (player.Team == gm.LocalPlayer.Team) {
				PlayerKnocked = D3DXCOLOR(Settings::Color::Players::Team::knocked[0], Settings::Color::Players::Team::knocked[1], Settings::Color::Players::Team::knocked[2], 1.f);
				PlayerBox = D3DXCOLOR(Settings::Color::Players::Team::box[0], Settings::Color::Players::Team::box[1], Settings::Color::Players::Team::box[2], 1.f);
				PlayerSnapline = D3DXCOLOR(Settings::Color::Players::Team::snapline[0], Settings::Color::Players::Team::snapline[1], Settings::Color::Players::Team::snapline[2], 1.f);
				PlayerSkeleton = D3DXCOLOR(Settings::Color::Players::Team::skeleton[0], Settings::Color::Players::Team::skeleton[1], Settings::Color::Players::Team::skeleton[2], 1.f);
				PlayerDirectionLine = D3DXCOLOR(Settings::Color::Players::Team::directionLine[0], Settings::Color::Players::Team::directionLine[1], Settings::Color::Players::Team::directionLine[2], 1.f);
				PlayerSpot = D3DXCOLOR(Settings::Color::Players::Team::spot[0], Settings::Color::Players::Team::spot[1], Settings::Color::Players::Team::spot[2], 1.f);
				PlayerWeaponWarning = D3DXCOLOR(Settings::Color::Players::Team::weaponwarning[0], Settings::Color::Players::Team::weaponwarning[1], Settings::Color::Players::Team::weaponwarning[2], 1.f);

			}
			else if (player.IsBot == true)
			{
				PlayerKnocked = D3DXCOLOR(Settings::Color::Players::Bot::knocked[0], Settings::Color::Players::Bot::knocked[1], Settings::Color::Players::Bot::knocked[2], 1.f);
				PlayerBox = D3DXCOLOR(Settings::Color::Players::Bot::box[0], Settings::Color::Players::Bot::box[1], Settings::Color::Players::Bot::box[2], 1.f);
				PlayerSnapline = D3DXCOLOR(Settings::Color::Players::Bot::snapline[0], Settings::Color::Players::Bot::snapline[1], Settings::Color::Players::Bot::snapline[2], 1.f);
				PlayerSkeleton = D3DXCOLOR(Settings::Color::Players::Bot::skeleton[0], Settings::Color::Players::Bot::skeleton[1], Settings::Color::Players::Bot::skeleton[2], 1.f);
				PlayerDirectionLine = D3DXCOLOR(Settings::Color::Players::Bot::directionLine[0], Settings::Color::Players::Bot::directionLine[1], Settings::Color::Players::Bot::directionLine[2], 1.f);
				PlayerSpot = D3DXCOLOR(Settings::Color::Players::Bot::spot[0], Settings::Color::Players::Bot::spot[1], Settings::Color::Players::Bot::spot[2], 1.f);
				PlayerWeaponWarning = D3DXCOLOR(Settings::Color::Players::Bot::weaponwarning[0], Settings::Color::Players::Bot::weaponwarning[1], Settings::Color::Players::Bot::weaponwarning[2], 1.f);

			}
			else {
				PlayerKnocked = D3DXCOLOR(Settings::Color::Players::Enemy::knocked[0], Settings::Color::Players::Enemy::knocked[1], Settings::Color::Players::Enemy::knocked[2], 1.f);
				PlayerSpot = D3DXCOLOR(Settings::Color::Players::Enemy::spot[0], Settings::Color::Players::Enemy::spot[1], Settings::Color::Players::Enemy::spot[2], 1.f);
				PlayerWeaponWarning = D3DXCOLOR(Settings::Color::Players::Enemy::weaponwarning[0], Settings::Color::Players::Enemy::weaponwarning[1], Settings::Color::Players::Enemy::weaponwarning[2], 1.f);

				if (Settings::ESP::Options::colorbyteamid)
				{
					std::srand(player.Team);
					float R = (BYTE)(rand() % 255) / 255.f;
					float G = (BYTE)(rand() % 255) / 255.f;
					float B = (BYTE)(rand() % 255) / 255.f;
					float A = 1.f;

					PlayerBox.r = R;
					PlayerBox.g = G;
					PlayerBox.b = B;
					PlayerBox.a = A;

					PlayerSnapline.r = R;
					PlayerSnapline.g = G;
					PlayerSnapline.b = B;
					PlayerSnapline.a = A;

					PlayerSkeleton.r = R;
					PlayerSkeleton.g = G;
					PlayerSkeleton.b = B;
					PlayerSkeleton.a = A;

					PlayerDirectionLine.r = R;
					PlayerDirectionLine.g = G;
					PlayerDirectionLine.b = B;
					PlayerDirectionLine.a = A;

				}
				else
				{
					PlayerBox = D3DXCOLOR(Settings::Color::Players::Enemy::box[0], Settings::Color::Players::Enemy::box[1], Settings::Color::Players::Enemy::box[2], 1.f);
					PlayerSnapline = D3DXCOLOR(Settings::Color::Players::Enemy::snapline[0], Settings::Color::Players::Enemy::snapline[1], Settings::Color::Players::Enemy::snapline[2], 1.f);
					PlayerSkeleton = D3DXCOLOR(Settings::Color::Players::Enemy::skeleton[0], Settings::Color::Players::Enemy::skeleton[1], Settings::Color::Players::Enemy::skeleton[2], 1.f);
					PlayerDirectionLine = D3DXCOLOR(Settings::Color::Players::Enemy::directionLine[0], Settings::Color::Players::Enemy::directionLine[1], Settings::Color::Players::Enemy::directionLine[2], 1.f);
				}

			}

			if (player.NearDeathBreath < 100.f)
			{
				PlayerBox = PlayerKnocked;
				PlayerSnapline = PlayerKnocked;
				PlayerSkeleton = PlayerKnocked;
				PlayerDirectionLine = PlayerKnocked;
				PlayerSpot = PlayerKnocked;
			}

			if checkSetting(Settings::ESP::Players::Team::spot, Settings::ESP::Players::Enemy::spot)
			{
				if ((GnameType::playerstatus(player.status) == "Aiming" || GnameType::playerstatus(player.status) == "Peek" || GnameType::playerstatus(player.status) == "Firing"))
				{
					PlayerBox = PlayerSpot;
					PlayerSnapline = PlayerSpot;
					PlayerSkeleton = PlayerSpot;
					PlayerDirectionLine = PlayerSpot;
				}
			}
			if checkSetting(Settings::ESP::Players::Team::WeaponWarning, Settings::ESP::Players::Enemy::WeaponWarning)
			{
				if (GnameType::Weapon_IsSniper(player.weapon) || GnameType::Weapon_ShotGun(player.weapon))
				{
					PlayerBox = PlayerWeaponWarning;
					PlayerSnapline = PlayerWeaponWarning;
					PlayerSkeleton = PlayerWeaponWarning;
					PlayerDirectionLine = PlayerWeaponWarning;
				}
			}
			if checkSetting(Settings::ESP::Players::Team::skeleton, Settings::ESP::Players::Enemy::skeleton) {
				DrawSkeletonESP(gm, player, PlayerSkeleton);
			}
			if checkSetting(Settings::ESP::Players::Team::boxes, Settings::ESP::Players::Enemy::boxes)
			{
				if (Settings::ESP::Options::boxtype == 5)
				{
					if (player.PoseType == 0 || player.PoseType == 3)  box3d(gm, footLocation, 40, 190, PlayerBox, Settings::ESP::Options::Boxthickness);
					if (player.PoseType == 1 || player.PoseType == 4)  box3d(gm, footLocation, 40, 143, PlayerBox, Settings::ESP::Options::Boxthickness);
					if (player.PoseType == 2 || player.PoseType == 5)  box3d(gm, footLocation, 80, 123, PlayerBox, Settings::ESP::Options::Boxthickness);
					if (player.PoseType == 8)  box3d(gm, footLocation, 80, 100, PlayerBox, Settings::ESP::Options::Boxthickness);
				}
			}
			if checkSetting(Settings::ESP::Players::Team::directionLine, Settings::ESP::Players::Enemy::directionLine)
			{
				if (GnameType::playerstatus(player.status) != "Driving") {
					FVector start = player.ESPDirectionLine.HEAD;
					FVector angles = player.RelativeRotation.ToVector();
					FVector end = angles * (Settings::ESP::Options::DirectionLineSize)+start;
					FVector screen_start, screen_end;
					if (gm.WorldToScreen(start, screen_start) &&  gm.WorldToScreen(end, screen_end))
					{
						GL3Draw::GetInstance()->RenderLine(ImVec2(screen_start.X, screen_start.Y), ImVec2(screen_end.X, screen_end.Y), PlayerDirectionLine, 1.f);
						GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(screen_end.X, screen_end.Y), 4, PlayerDirectionLine);
					}
				}
			}
			if (checkSetting(Settings::ESP::Players::Team::prediction, Settings::ESP::Players::Enemy::prediction) && Settings::Aimbot::prediction == false)
			{
				if ((GnameType::playerstatus(player.status) != "Driving") && player.ComponentVelocity.Size() > 400 && gm.LocalPlayer.bIsGunADS == true)
				{

					float InitialSpeed = gm.LocalPlayer.BulletFireSpeed;
					FVector BONE = player.ESPPrediction.HEAD;
					FVector velocity = player.ComponentVelocity;

					FVector AimCorrection =	Utils::AimbotCorrection(InitialSpeed, MyLocalPlayer.WeaponPose, BONE, velocity);
					BONE.X = AimCorrection.X;
					BONE.Y = AimCorrection.Y;
					BONE.Z = AimCorrection.Z;

					FVector OUTBONE, ovecScreenOrgin , OUTHEAD;
					if (gm.WorldToScreen(BONE, OUTBONE) && gm.WorldToScreen(player.ESPPrediction.ROOT, ovecScreenOrgin) && gm.WorldToScreen(player.ESPPrediction.HEAD, OUTHEAD))
					{
						if (Settings::ESP::Options::predictiontype == 0)
						{
							GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Diagonal, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 10, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
							GL3Draw::GetInstance()->RenderCircle(ImVec2(OUTBONE.X, OUTBONE.Y), (ovecScreenOrgin.Y - OUTHEAD.Y) / 4, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
							GL3Draw::GetInstance()->RenderLine(ImVec2(OUTHEAD.X, OUTHEAD.Y), ImVec2(OUTBONE.X, OUTBONE.Y), D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
						}
						else if (Settings::ESP::Options::predictiontype == 1)
						{
							GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Plus, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 10, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
							GL3Draw::GetInstance()->RenderCircle(ImVec2(OUTBONE.X, OUTBONE.Y), (ovecScreenOrgin.Y - OUTHEAD.Y) / 4, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
							GL3Draw::GetInstance()->RenderLine(ImVec2(OUTHEAD.X, OUTHEAD.Y), ImVec2(OUTBONE.X, OUTBONE.Y), D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
						}
						else
						{
							GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Dot, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 4, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));

						}
					}
				}
			}

			if (player.PoseType == 0 || player.PoseType == 3) headLocation.Z += 90.f;
			if (player.PoseType == 1 || player.PoseType == 4) headLocation.Z += 40.f;
			if (player.PoseType == 2 || player.PoseType == 5) headLocation.Z += 7.5f;
			if (player.PoseType == 8) headLocation.Z += 20.f;
			if ((gm.WorldToScreen(footLocation, ofootLocation) && (gm.WorldToScreen(headLocation, oheadLocation)))) {
				float w2sHeight = Math::Distance3D(ofootLocation, oheadLocation);
				float w2sWidth = w2sHeight;
				float heightoffset = Math::Distance3D(ofootLocation, oheadLocation);
				float H = w2sHeight;
				float W = H / 2;
				float X = oheadLocation.X - W / 2;
				if (player.PoseType == 1 || player.PoseType == 4) w2sWidth /= 2;
				if (player.PoseType == 2 || player.PoseType == 5) w2sWidth /= 1.5;
				if (Settings::ESP::Options::ESPStyle == 0) {
					if checkSetting(Settings::ESP::Players::Team::snaplines, Settings::ESP::Players::Enemy::snaplines) {
						GL3Draw::GetInstance()->RenderLine(ImVec2(Globals::width / 2, 0), ImVec2(oheadLocation.X, oheadLocation.Y), PlayerSnapline, 1.f);
					}
					if checkSetting(Settings::ESP::Players::Team::boxes, Settings::ESP::Players::Enemy::boxes) {

						if (Settings::ESP::Options::boxtype == 0)
						{
							if (!Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->DrawBox(X, oheadLocation.Y, W, H, PlayerBox, Settings::ESP::Options::Boxthickness);
							else if (Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->DrawOutlineBox(X, oheadLocation.Y, W, H, PlayerBox, Settings::ESP::Options::Boxthickness);

						}
						if (Settings::ESP::Options::boxtype == 1)
						{
							if (!Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->DrawCoalBox(X, oheadLocation.Y, W, H, PlayerBox, Settings::ESP::Options::Boxthickness);
							else if (Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->DrawOutlineCoalBox(X, oheadLocation.Y, W, H, PlayerBox, Settings::ESP::Options::Boxthickness);

						}
						if (Settings::ESP::Options::boxtype == 2)
						{
							if (!Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->GenuineBox(X, oheadLocation.Y, W, H, PlayerBox, Settings::ESP::Options::Boxthickness);
							else if (Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->GenuineOutlineBox(X, oheadLocation.Y, W, H, PlayerBox, Settings::ESP::Options::Boxthickness);
						}
						if (Settings::ESP::Options::boxtype == 3)
						{
							GL3Draw::GetInstance()->DrawOctagonBox(X, oheadLocation.Y, W, H, PlayerBox, Settings::ESP::Options::Boxthickness);
						}
						if (Settings::ESP::Options::boxtype == 4)
						{
							GL3Draw::GetInstance()->DrawOctagonCoalBox(X, oheadLocation.Y, W, H, PlayerBox, Settings::ESP::Options::Boxthickness);

						}
					}
					if checkSetting(Settings::ESP::Players::Team::filledbox, Settings::ESP::Players::Enemy::filledbox) {
						GL3Draw::GetInstance()->DrawBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);

					}
					if checkSetting(Settings::ESP::Players::Team::health, Settings::ESP::Players::Enemy::health) {
						float HP = 0;
						D3DXCOLOR Color = D3DXCOLOR();
						if (player.Health > 0)
						{
							HP = player.Health;
							Color = D3DXCOLOR(.48f, .98f, 0.f, 1.f);
						}
						else
						{
							HP = player.NearDeathBreath;
							Color = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
						}
						if (Settings::ESP::Options::healthbartype == 0)
							GL3Draw::GetInstance()->HorizontalDrawHealth(X, oheadLocation.Y - 6, W, 4, (int)HP, (int)player.HealthMax, Color, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
						else if (Settings::ESP::Options::healthbartype == 1)
							GL3Draw::GetInstance()->VerticalHealthBar(X - 6, oheadLocation.Y, 4, H, (int)HP, (int)player.HealthMax, Color, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
						else
							PlayerTexts.push_back(Text(m_FVisuals, std::to_string((int)HP) + "%hp", 2, 14, Color));
					}
					if checkSetting(Settings::ESP::Players::Team::weapon, Settings::ESP::Players::Enemy::weapon) {
						PlayerTexts.push_back(Text(m_FVisuals, GnameType::PlayerWeapon(player.weapon).append("[" + std::to_string((int)player.Ammo) + "/" + std::to_string((int)player.AmmoMax) + "]").append("[" + GnameType::scopes(((int)player.ScopeFov)) + "]"), 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
					}
					if checkSetting(Settings::ESP::Players::Team::nation, Settings::ESP::Players::Enemy::nation) {
						const auto player_Nation = player.Nation;
						auto ws = std::wstring(player_Nation);
						auto pNamePlate = std::string(ws.begin(), ws.end());

						if (Settings::ESP::Options::Nationtype == 0)
							PlayerTexts.push_back(Text(m_FVisuals, pNamePlate, 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
						else
							PlayerTexts.push_back(Text(m_FVisuals, GnameType::GetNationName(pNamePlate), 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
					}
					if checkSetting(Settings::ESP::Players::Team::status, Settings::ESP::Players::Enemy::status)
					{
						PlayerTexts.push_back(Text(m_FVisuals, GnameType::playerstatus(player.status), 2, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
					}
					if checkSetting(Settings::ESP::Players::Team::distance, Settings::ESP::Players::Enemy::distance) {
						if (player.Distance > 0)
							PlayerTexts.push_back(Text(m_FVisuals, std::to_string((int)player.Distance) + "M", 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
					}
					if (checkSetting(Settings::ESP::Players::Team::name, Settings::ESP::Players::Enemy::name)) {
						if (player.IsBot)
							PlayerTexts.push_back(Text(m_FVisuals, "BOT", 0, Settings::ESP::Options::PlayerNameSize, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
						else
							PlayerTexts.push_back(Text(m_FVisuals, player.Name, 0, Settings::ESP::Options::PlayerNameSize, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
					}
				}
				else
				{
					if checkSetting(Settings::ESP::Players::Team::snaplines, Settings::ESP::Players::Enemy::snaplines) {
						GL3Draw::GetInstance()->RenderLine(ImVec2(Globals::width / 2, 0), ImVec2(oheadLocation.X, oheadLocation.Y - 40), PlayerSnapline, 1.f);
					}
					if checkSetting(Settings::ESP::Players::Team::boxes, Settings::ESP::Players::Enemy::boxes) {

						if (Settings::ESP::Options::boxtype == 0)
						{
							if (!Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->DrawBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);
							else if (Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->DrawOutlineBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);

						}
						if (Settings::ESP::Options::boxtype == 1)
						{
							if (!Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->DrawCoalBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);
							else if (Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->DrawOutlineCoalBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);

						}
						if (Settings::ESP::Options::boxtype == 2)
						{
							if (!Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->GenuineBox(X, oheadLocation.Y, W, H, PlayerBox);
							else if (Settings::ESP::Options::esp_Outline)
								GL3Draw::GetInstance()->GenuineOutlineBox(X, oheadLocation.Y, W, H, PlayerBox);
						}
						if (Settings::ESP::Options::boxtype == 3)
						{
							GL3Draw::GetInstance()->DrawOctagonBox(X, oheadLocation.Y, W, H, PlayerBox);
						}
						if (Settings::ESP::Options::boxtype == 4)
						{
							GL3Draw::GetInstance()->DrawOctagonCoalBox(X, oheadLocation.Y, W, H, PlayerBox);

						}
					}
					if checkSetting(Settings::ESP::Players::Team::filledbox, Settings::ESP::Players::Enemy::filledbox) {
						GL3Draw::GetInstance()->DrawBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);

					}
					if (checkSetting(Settings::ESP::Players::Team::name, Settings::ESP::Players::Enemy::name)) {
						GL3Draw::GetInstance()->AddImage(ImVec2(oheadLocation.X - 65, oheadLocation.Y - 27), ImVec2(130, 25), (void*)(intptr_t)Icons::Background_info, D3DXCOLOR(1, 1, 1, 1));
						PlayerTexts.push_back(Text(m_FVisuals, player.Name, 0, 18, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
					}
					if checkSetting(Settings::ESP::Players::Team::weapon, Settings::ESP::Players::Enemy::weapon)
					{
						GL3Draw::GetInstance()->RenderText(m_WeaponsFont, GnameType::PlayerWeaponFont(player.weapon), ImVec2(oheadLocation.X - 25, oheadLocation.Y - 60), 50, D3DXCOLOR(1, 1, 1, 1));
					}
					if checkSetting(Settings::ESP::Players::Team::nation, Settings::ESP::Players::Enemy::nation)
					{
						const auto player_Nation = player.Nation;
						auto ws = std::wstring(player_Nation);
						auto pNamePlate = std::string(ws.begin(), ws.end());
						for (size_t j = 0; j < Flags->Count; j++)
						{
							if (pNamePlate == Flags->Flaggs[j].Item_Game_Name) {
								GL3Draw::GetInstance()->AddImage(ImVec2(oheadLocation.X - 65, oheadLocation.Y - 25), ImVec2(20, 20), (void*)(intptr_t)Flags->Flaggs[j].Item_texture, D3DXCOLOR(1, 1, 1, 1));
							}
						}

					}
					if checkSetting(Settings::ESP::Players::Team::health, Settings::ESP::Players::Enemy::health) {
						float HP = 0;
						D3DXCOLOR Color = D3DXCOLOR();
						if (player.Health > 0)
						{
							HP = player.Health;
							Color = D3DXCOLOR(.62, .62, .62, 1.f);
						}
						else
						{
							HP = player.NearDeathBreath;
							Color = D3DXCOLOR(1.f, 0.f, 0.f, 1.f);
						}
						GL3Draw::GetInstance()->HorizontalDrawHealth(oheadLocation.X - (130 / 2), oheadLocation.Y - 4, 130, 4, (int)HP, (int)player.HealthMax, Color, D3DXCOLOR(0.f, 0.f, 0.f, 1.f));
					}
					if checkSetting(Settings::ESP::Players::Team::status, Settings::ESP::Players::Enemy::status)
					{
						PlayerTexts.push_back(Text(m_FVisuals, GnameType::playerstatus(player.status), 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
					}
					if checkSetting(Settings::ESP::Players::Team::distance, Settings::ESP::Players::Enemy::distance) {
						PlayerTexts.push_back(Text(m_FVisuals, std::to_string((int)player.Distance) + "M", 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
					}

				}
				int middle = oheadLocation.X;
				int Top[3] = { oheadLocation.Y,ofootLocation.Y, oheadLocation.Y };
				for (auto text : PlayerTexts)
				{
					int fontsize = text.size;
					float offset = (text.text.length() * fontsize) / 6;
					switch (text.side)
					{
					case 0:
						Top[0] -= fontsize + 15;
						GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(middle - offset, Top[0] + 8), text.size, text.color);
						break;
					case 1:
						GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(ofootLocation.X - offset, Top[1] + 2), text.size, text.color);
						Top[1] += fontsize + 1;
						break;
					case 2:
						GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(middle + (heightoffset / 5) + fontsize, Top[2] - 8), text.size, text.color);
						Top[2] += fontsize + 1;
						break;
					}
				}
			}
			else
			{
				if (player.Distance > Settings::ESP::Options::max_distance_offscreen)
					continue;
				if checkSetting(Settings::ESP::Players::Team::offscreen, Settings::ESP::Players::Enemy::offscreen)
				{
					FVector2D EntityPos = Utils::WorldToRadar(CameraCacheEntry.Rotation, CameraCacheEntry.Location, player.origin, FVector2D(0, 0), FVector2D(Globals::width, Globals::height));
					int radar_range = Settings::ESP::Options::offscreen_range;
					int x, y;
					x = EntityPos.X;
					y = EntityPos.Y;

					auto angle = FVector();
					Utils::VectorAnglesRadar(FVector((float)(Globals::width / 2) - x, (float)(Globals::height / 2) - y, 0.f), angle);

					const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
					const auto new_point_x = (Globals::width / 2) + (radar_range) / 2 * 8 * cosf(angle_yaw_rad);
					const auto new_point_y = (Globals::height / 2) + (radar_range) / 2 * 8 * sinf(angle_yaw_rad);

					std::array<FVector, 3> points
					{
						FVector(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((radar_range) / 4 + 3.5f) / 2, 0.f),
						FVector(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f),
						FVector(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((radar_range) / 4 + 3.5f) / 2, 0.f)
					};

					Utils::RotateTriangle(points, angle.Y + 180.f);

					GL3Draw::GetInstance()->RenderTriangleFilled(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), ImColor(1.f, 0.f, 0.f));
				}
			}
			PlayerTexts.clear();
		}
		for (Vehicle& vehicle : gm.Vehicles) {
			if (!Settings::ESP::Options::FightMode) {
				FVector Location = vehicle.origin;
				FVector screen = FVector();
				std::vector<Text> VehicleTexts = std::vector<Text>();
				D3DXCOLOR Color3DBOX = D3DXCOLOR();
				D3DXCOLOR ColorName = D3DXCOLOR();
				if (vehicle.ReplicatedMovement.LinearVelocity.Size() > 100)
				{
					Color3DBOX = D3DXCOLOR(Settings::Color::Vehicle::velocity[0], Settings::Color::Vehicle::velocity[1], Settings::Color::Vehicle::velocity[2], 1.f);
					ColorName = D3DXCOLOR(Settings::Color::Vehicle::velocity[0], Settings::Color::Vehicle::velocity[1], Settings::Color::Vehicle::velocity[2], 1.f);
				}
				else
				{
					Color3DBOX = D3DXCOLOR(Settings::Color::Vehicle::Box[0], Settings::Color::Vehicle::Box[1], Settings::Color::Vehicle::Box[2], 1.f);
					ColorName = D3DXCOLOR(Settings::Color::Vehicle::Name[0], Settings::Color::Vehicle::Name[1], Settings::Color::Vehicle::Name[2], 1.f);
				}

				if (Settings::ESP::Other::vehicleExplosionWarning) {
					if (vehicle.HP <= 20.f)
						RenderCircle3D(gm, FVector(Location.X, Location.Y, Location.Z - 100), 50.f, 450.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
				}
				if (Settings::ESP::Vehicle::vehicleDirectionLine)
				{
					if (vehicle.ReplicatedMovement.LinearVelocity.Size() > 100)
					{
						FVector start = FVector(Location.X, Location.Y, Location.Z + 100.f);
						FVector angles = vehicle.ReplicatedMovement.Rotation.ToVector();
						FVector end = angles * Settings::ESP::Options::VehicleDirectionLineSize + start;
						FVector screen_start, screen_end;
						if (gm.WorldToScreen(start, screen_start) && gm.WorldToScreen(end, screen_end)) {
							GL3Draw::GetInstance()->RenderLine(ImVec2(screen_start.X, screen_start.Y), ImVec2(screen_end.X, screen_end.Y), D3DXCOLOR(Settings::Color::Vehicle::DirectionLine[0], Settings::Color::Vehicle::DirectionLine[1], Settings::Color::Vehicle::DirectionLine[2], 1.f), 1.f);
							GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(screen_end.X, screen_end.Y), 4, D3DXCOLOR(Settings::Color::Vehicle::DirectionLine[0], Settings::Color::Vehicle::DirectionLine[1], Settings::Color::Vehicle::DirectionLine[2], 1.f));
						}
					}
				}
				if (Settings::ESP::Vehicle::vehiclePrediction && Settings::Aimbot::prediction == false)
				{
					if (vehicle.ReplicatedMovement.LinearVelocity.Size() > 100 && gm.LocalPlayer.bIsGunADS == true)
					{
						FVector VehicleLocation = FVector(Location.X, Location.Y, Location.Z + 130.f);

						float Gravity = gm.LocalPlayer.LaunchGravityScale;
						float InitialSpeed = gm.LocalPlayer.BulletFireSpeed;
						FVector BONE = VehicleLocation;
						FVector velocity = vehicle.ReplicatedMovement.LinearVelocity;
						auto Distance = CameraCacheEntry.Location.Distance(BONE) / 100.f;

						FVector AimCorrection = Utils::AimbotCorrection(InitialSpeed, MyLocalPlayer.WeaponPose, BONE, velocity);
						BONE.X = AimCorrection.X;
						BONE.Y = AimCorrection.Y;
						BONE.Z = AimCorrection.Z;

						FVector OUTBONE, ovecScreenOrgin, OUTHEAD;
						if (gm.WorldToScreen(BONE, OUTBONE) && gm.WorldToScreen(VehicleLocation, OUTHEAD))
						{
							if (Settings::ESP::Options::predictiontype2 == 0)
							{
								GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Diagonal, OUTBONE.X, OUTBONE.Y, 5, 2.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
								GL3Draw::GetInstance()->RenderCircle(ImVec2(OUTBONE.X, OUTBONE.Y), 10, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
								GL3Draw::GetInstance()->RenderLine(ImVec2(OUTHEAD.X, OUTHEAD.Y), ImVec2(OUTBONE.X, OUTBONE.Y), D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
							}
							else if (Settings::ESP::Options::predictiontype2 == 1)
							{
								GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Plus, OUTBONE.X, OUTBONE.Y, 5, 2.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
								GL3Draw::GetInstance()->RenderCircle(ImVec2(OUTBONE.X, OUTBONE.Y), 10, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
								GL3Draw::GetInstance()->RenderLine(ImVec2(OUTHEAD.X, OUTHEAD.Y), ImVec2(OUTBONE.X, OUTBONE.Y), D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
							}
							else
							{
								GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Dot, OUTBONE.X, OUTBONE.Y, 10, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));

							}
						}
					}
				}
				if (Settings::ESP::Vehicle::vehicleBox)
					box3d(gm, Location, 240.f, 225.f, Color3DBOX);

				if (gm.WorldToScreen(Location, screen)) {

					int wheelscount = 0;
					if (vehicle.Wheel.FirstWheel == 0) wheelscount += 1;
					if (vehicle.Wheel.SecondWheel == 0) wheelscount += 1;
					if (vehicle.Wheel.ThirdWheel == 0) wheelscount += 1;
					if (vehicle.Wheel.FourthWheel == 0) wheelscount += 1;

					if (Settings::ESP::Vehicle::vehicleName)
						GL3Draw::GetInstance()->RenderText(m_FVisuals, GnameType::GetVehicleType(vehicle.items).append(" ").append(std::to_string((int)vehicle.Distance)).append(" M").c_str(), ImVec2(screen.X, screen.Y), 14, ColorName);
					if (Settings::ESP::Vehicle::vehicleWheelDamaged)
						GL3Draw::GetInstance()->RenderText(m_FVisuals, std::string("Wheel Damage").append(" ").append(std::to_string((int)wheelscount)).c_str(), ImVec2(screen.X, screen.Y + 12), 14, ColorName);

					if (Settings::ESP::Vehicle::vehicleHP)
						GL3Draw::GetInstance()->HorizontalDrawHealth(screen.X, screen.Y + 26, 50, 4, (int)vehicle.HP, (int)100, D3DXCOLOR(.48f, .98f, 0.f, 1.f), D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
					if (Settings::ESP::Vehicle::vehicleOil)
						GL3Draw::GetInstance()->HorizontalDrawHealth(screen.X, screen.Y + 30, 50, 4, (int)vehicle.Fuel, (int)100, D3DXCOLOR(.5f, .5f, .5f, 1.f), D3DXCOLOR(1.f, 0.f, 0.f, 1.f));


				}
				VehicleTexts.clear();
			}
		}
		for (RedZone& redzone : gm.RedZones) {
			if (!Settings::ESP::Options::FightMode) {
				FVector Location = redzone.origin;
				if (Settings::ESP::Other::redzone)
					RenderCircle3D(gm, FVector(Location.X, Location.Y, Location.Z - 100), 50.f, 500.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
			}

		}
		for (Loot& loot : gm.Loots) {
			if (!Settings::ESP::Options::FightMode) {
				FVector Location = loot.origin;
				FVector screen = FVector();
				std::vector<Text> LootTexts = std::vector<Text>();
				if (gm.WorldToScreen(Location, screen)) {

					if (Settings::ESP::Options::loottype == 0)
					{
						if (GnameType::ItemRifle(loot.items) && Settings::ESP::Loot::lootarweapon)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::ar[0], Settings::Color::Loot::ar[1], Settings::Color::Loot::ar[2], 1.f)));
						}
						if (GnameType::ItemSmg(loot.items) && Settings::ESP::Loot::lootsmgweapon)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::smg[0], Settings::Color::Loot::smg[1], Settings::Color::Loot::smg[2], 1.f)));
						}
						if (GnameType::ItemSniper(loot.items) && Settings::ESP::Loot::lootsniperweapon)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::sniper[0], Settings::Color::Loot::sniper[1], Settings::Color::Loot::sniper[2], 1.f)));
						}
						if (GnameType::ItemArmor(loot.items) && Settings::ESP::Loot::lootarmor)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::armor[0], Settings::Color::Loot::armor[1], Settings::Color::Loot::armor[2], 1.f)));
						}
						if (GnameType::ItemHelmet(loot.items) && Settings::ESP::Loot::loothelmet)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::helmet[0], Settings::Color::Loot::helmet[1], Settings::Color::Loot::helmet[2], 1.f)));
						}
						if (GnameType::ItemBag(loot.items) && Settings::ESP::Loot::lootbackpack)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::backpack[0], Settings::Color::Loot::backpack[1], Settings::Color::Loot::backpack[2], 1.f)));
						}
						if (GnameType::ItemScops(loot.items) && Settings::ESP::Loot::lootscopes)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::scopes[0], Settings::Color::Loot::scopes[1], Settings::Color::Loot::scopes[2], 1.f)));
						}
						if (GnameType::ItemShotgun(loot.items) && Settings::ESP::Loot::lootshotgun)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::shotgun[0], Settings::Color::Loot::shotgun[1], Settings::Color::Loot::shotgun[2], 1.f)));
						}
						if (GnameType::ItemOther(loot.items) && Settings::ESP::Loot::lootother)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::other[0], Settings::Color::Loot::other[1], Settings::Color::Loot::other[2], 1.f)));
						}
						if (GnameType::ItemSpecial(loot.items) && Settings::ESP::Loot::lootspecial)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::special[0], Settings::Color::Loot::special[1], Settings::Color::Loot::other[2], 1.f)));
						}
						if (GnameType::ItemMaterial(loot.items) && Settings::ESP::Loot::lootaccessories)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::accessories[0], Settings::Color::Loot::accessories[1], Settings::Color::Loot::accessories[2], 1.f)));
						}
						if (GnameType::ItemEnergy(loot.items) && Settings::ESP::Loot::lootenergy)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::energy[0], Settings::Color::Loot::energy[1], Settings::Color::Loot::energy[2], 1.f)));
						}
						if (GnameType::ItemGrenade(loot.items) && Settings::ESP::Loot::lootgrenade)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::grenade[0], Settings::Color::Loot::grenade[1], Settings::Color::Loot::grenade[2], 1.f)));
						}
						if (GnameType::ItemBicycle(loot.items) && Settings::ESP::Loot::lootbicycle)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
								LootTexts.push_back(Text(m_FVisuals, GnameType::g_ItemHash[loot.items].szEN, 1, 14, D3DXCOLOR(Settings::Color::Loot::bicycle[0], Settings::Color::Loot::bicycle[1], Settings::Color::Loot::bicycle[2], 1.f)));
						}
						for (auto text : LootTexts)
						{
							GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(screen.X, screen.Y), text.size, text.color);
						}

					}
					else
					{
						if (GnameType::ItemRifle(loot.items) && Settings::ESP::Loot::lootarweapon)	//ÎäÆ÷
						{

							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Rifle_AKM_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Rifle_AKM_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Rifle_AUG_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Rifle_AUG_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Rifle_G36_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Rifle_G36_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Rifle_Groza_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Rifle_Groza_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Rifle_M416_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Rifle_M416_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Rifle_M762_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Rifle_M762_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Rifle_SCAR_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Rifle_SCAR_Wrapper, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemSmg(loot.items) && Settings::ESP::Loot::lootsmgweapon)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "MachineGun_MP5K_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_MachineGun_MP5K_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "MachineGun_PP19_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_MachineGun_PP19_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "MachineGun_Uzi_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_MachineGun_Uzi_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "MachineGun_UMP9_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_MachineGun_UMP9_Wrapper, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemSniper(loot.items) && Settings::ESP::Loot::lootsniperweapon)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Sniper_AWM_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Sniper_AWM_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Sniper_Kar98k_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Sniper_Kar98k_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Sniper_M24_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Sniper_M24_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Sniper_Mosin_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Sniper_Mosin_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Sniper_Mk14_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Sniper_Mk14_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Sniper_AMR_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Sniper_AMR_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Sniper_SKS_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Sniper_SKS_Wrapper, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemArmor(loot.items) && Settings::ESP::Loot::lootarmor)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "PickUp_BP_Armor_Lv2")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::PickUp_BP_Armor_Lv2, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "PickUp_BP_Armor_Lv3")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::PickUp_BP_Armor_Lv3, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemHelmet(loot.items) && Settings::ESP::Loot::loothelmet)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "PickUp_BP_Helmet_Lv2")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::PickUp_BP_Helmet_Lv2_B, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "PickUp_BP_Helmet_Lv3")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::PickUp_BP_Helmet_Lv3_B, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemBag(loot.items) && Settings::ESP::Loot::lootbackpack)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "PickUp_BP_Bag_Lv2")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::PickUp_BP_Bag_Lv2_B, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "PickUp_BP_Bag_Lv3")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::PickUp_BP_Bag_Lv3_B, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemScops(loot.items) && Settings::ESP::Loot::lootscopes)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "MZJ_3X_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_MZJ_3X_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "MZJ_4X_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_MZJ_4X_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "MZJ_6X_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_MZJ_6X_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "MZJ_8X_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_MZJ_8X_Pickup, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemShotgun(loot.items) && Settings::ESP::Loot::lootshotgun)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "ShotGun_DP12_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_ShotGun_DP12_Wrapper, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemOther(loot.items) && Settings::ESP::Loot::lootother)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Other_DP28_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Other_DP28_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Other_M249_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Other_M249_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Other_MG3_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Other_MG3_Wrapper, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemSpecial(loot.items) && Settings::ESP::Loot::lootspecial)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Pistol_Flaregun_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Pistol_Flaregun_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "GoldenTokenWrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::GoldenTokenWrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "SecurityCardWrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::SecurityCard, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemMaterial(loot.items) && Settings::ESP::Loot::lootaccessories)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "DJ_Large_EQ_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_DJ_Large_EQ_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "QK_Large_Compensator_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_QK_Large_Compensator_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "QK_Large_Suppressor_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_QK_Large_Suppressor_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "QT_A_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_QT_A_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "WB_Vertical_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_WB_Vertical_Pickup, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemEnergy(loot.items) && Settings::ESP::Loot::lootenergy)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Injection_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::Injection_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Pills_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::Pills_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Firstaid_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::Firstaid_Pickup, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "FirstAidbox_Pickup")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::FirstAidbox_Pickup, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemGrenade(loot.items) && Settings::ESP::Loot::lootgrenade)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Grenade_Burn_Weapon_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Grenade_Burn_Weapon_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Grenade_Shoulei_Weapon_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Grenade_Shoulei_Weapon_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Grenade_Smoke_Weapon_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Grenade_Smoke_Weapon_Wrapper, D3DXCOLOR(1, 1, 1, 1));
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "Grenade_EmergencyCall_Weapon_Wrapper")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::BP_Grenade_EmergencyCall_Weapon_Wrapper, D3DXCOLOR(1, 1, 1, 1));

							}
						}
						if (GnameType::ItemBicycle(loot.items) && Settings::ESP::Loot::lootbicycle)	//ÎäÆ÷
						{
							if (GnameType::g_ItemHash.count(loot.items))
							{
								if (std::string(GnameType::g_ItemHash[loot.items].szTexture) == "PickUp_BP_Bike")
									GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(Settings::ESP::Options::iconwidth, Settings::ESP::Options::iconheight), (void*)(intptr_t)Icons::PickUp_BP_Bike, D3DXCOLOR(1, 1, 1, 1));

							}
						}
					}

					LootTexts.clear();
				}
			}
		}
		for (Inventory& inventory : gm.Inventorys)
		{
			if (!Settings::ESP::Options::FightMode) {
				FVector Location = inventory.origin;
				FVector screen = FVector();
				if (gm.WorldToScreen(Location, screen))
				{
					if (Settings::ESP::Inventory::AirDrop)
					{
						if (GnameType::IsAirDropBox(inventory.items))
						{

							if (inventory.bIsSuperAirdrop) {
								if (inventory.IsAirOpen)
									GL3Draw::GetInstance()->RenderText(m_FVisuals, std::string("Super Crate [Opened] ").append(std::to_string((int)inventory.Distance).append(" M")), ImVec2(screen.X, screen.Y), 14, D3DXCOLOR(Settings::Color::Other::AirDrop[0], Settings::Color::Other::AirDrop[1], Settings::Color::Other::AirDrop[2], 1.f));
								else
									GL3Draw::GetInstance()->RenderText(m_FVisuals, std::string("Super Crate ").append(std::to_string((int)inventory.Distance).append(" M")), ImVec2(screen.X, screen.Y), 14, D3DXCOLOR(Settings::Color::Other::AirDrop[0], Settings::Color::Other::AirDrop[1], Settings::Color::Other::AirDrop[2], 1.f));
							}
							else
							{
								if (inventory.IsAirOpen)
									GL3Draw::GetInstance()->RenderText(m_FVisuals, std::string("Air Crate [Opened] ").append(std::to_string((int)inventory.Distance).append(" M")), ImVec2(screen.X, screen.Y), 14, D3DXCOLOR(Settings::Color::Other::AirDrop[0], Settings::Color::Other::AirDrop[1], Settings::Color::Other::AirDrop[2], 1.f));
								else
									GL3Draw::GetInstance()->RenderText(m_FVisuals, std::string("Air Crate ").append(std::to_string((int)inventory.Distance).append(" M")), ImVec2(screen.X, screen.Y), 14, D3DXCOLOR(Settings::Color::Other::AirDrop[0], Settings::Color::Other::AirDrop[1], Settings::Color::Other::AirDrop[2], 1.f));
							}


						}
					}
					if (Settings::ESP::Inventory::Deadbox)
					{
						if (GnameType::IsDeathbox(inventory.items) && inventory.Distance < 100)
						{
							GL3Draw::GetInstance()->RenderText(m_FVisuals, std::string("Creat Box ").append(std::to_string((int)inventory.Distance).append(" M")), ImVec2(screen.X, screen.Y), 14, D3DXCOLOR(Settings::Color::Other::deadbox[0], Settings::Color::Other::deadbox[1], Settings::Color::Other::deadbox[2], 1.f));

						}

					}
					if (Settings::ESP::Inventory::TreasureChest)
					{
						if (GnameType::IsTreasureChest(inventory.items))
						{
							if (inventory.Distance < 100)
							{
								GL3Draw::GetInstance()->RenderText(m_FVisuals, std::string(GnameType::TreasureChest(inventory.items)).append(" ").append(std::to_string((int)inventory.Distance).append(" M")), ImVec2(screen.X, screen.Y), 14, D3DXCOLOR(Settings::Color::Other::treasurechest[0], Settings::Color::Other::treasurechest[1], Settings::Color::Other::treasurechest[2], 1.f));
							}
						}

					}
					if (Settings::ESP::Inventory::InventoryDetails)
					{
						if (GnameType::IsAirDropList(inventory.items))
						{
							if (inventory.Distance < 100)
							{
								for (int i = 0; i < inventory.boxItem.size(); i++)
								{
									GL3Draw::GetInstance()->RenderText(m_FVisuals, inventory.boxItem[i], ImVec2(screen.X, screen.Y - 15 * (i + 1)), 14, D3DXCOLOR(Settings::Color::Other::InventoryDetails[0], Settings::Color::Other::InventoryDetails[1], Settings::Color::Other::InventoryDetails[2], 1.f));
								}
							}
						}
						if (GnameType::IsDeathbox(inventory.items))
						{
							if (inventory.Distance < 100)
							{
								for (int i = 0; i < inventory.boxItem.size(); i++)
								{
									GL3Draw::GetInstance()->RenderText(m_FVisuals, inventory.boxItem[i], ImVec2(screen.X, screen.Y - 15 * (i + 1)), 14, D3DXCOLOR(Settings::Color::Other::InventoryDetails[0], Settings::Color::Other::InventoryDetails[1], Settings::Color::Other::InventoryDetails[2], 1.f));
								}
							}
						}
					}
				}
			}
		}
		for (Grenade& grenade : gm.Grenades)
		{
			FVector Location = grenade.origin;
			FVector screen = FVector();
			std::vector<Text> GrenadeTexts = std::vector<Text>();
			std::string dis = std::to_string((int)grenade.Distance).append(" M").c_str();
			if (gm.WorldToScreen(Location, screen))
			{
				if (Settings::ESP::Other::EspGrenade) {
					if (GnameType::IsSmokeGrenade(grenade.items))	//ÎäÆ÷
					{
						if (Settings::ESP::Options::GrenadeType == 0) {
							GrenadeTexts.push_back(Text(m_FVisuals, (GnameType::PlayerGrenade(grenade.items)) + std::string(" " + dis), 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
							GL3Draw::GetInstance()->RenderCircle(ImVec2(screen.X, screen.Y), 6.f, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
						}
						else
						{
							GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(35, 35), (void*)(intptr_t)Icons::BP_Grenade_Smoke_Weapon_Wrapper, D3DXCOLOR(1, 1, 1, 1));

						}
					}
					if (GnameType::IsBurnGrenade(grenade.items))
					{
						if (Settings::ESP::Options::GrenadeType == 0) {
							GrenadeTexts.push_back(Text(m_FVisuals, (GnameType::PlayerGrenade(grenade.items)) + std::string(" " + dis), 1, 14, D3DXCOLOR(1.f, .64, 0.f, 1.f)));
							GL3Draw::GetInstance()->RenderCircle(ImVec2(screen.X, screen.Y), 6.f, D3DXCOLOR(1.f, .64, 0.f, 1.f), 2.f);
						}
						else
						{
							GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(35, 35), (void*)(intptr_t)Icons::BP_Grenade_Burn_Weapon_Wrapper, D3DXCOLOR(1, 1, 1, 1));
						}
						RenderCircle3D(gm, FVector(Location.X, Location.Y, Location.Z - 50), 50.f, 390, D3DXCOLOR(1.f, .64, 0.f, 1.f));

					}
					if (GnameType::IsShouleiGrenade(grenade.items))
					{
						if (Settings::ESP::Options::GrenadeType == 0) {
							GrenadeTexts.push_back(Text(m_FVisuals, (GnameType::PlayerGrenade(grenade.items)) + std::string(" " + dis), 1, 14, D3DXCOLOR(1.f, 0.f, 0.f, 1.f)));
							GL3Draw::GetInstance()->RenderCircle(ImVec2(screen.X, screen.Y), 6.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f), 2.f);
						}
						else
						{
							GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(35, 35), (void*)(intptr_t)Icons::BP_Grenade_Shoulei_Weapon_Wrapper, D3DXCOLOR(1, 1, 1, 1));

						}
						RenderCircle3D(gm, FVector(Location.X, Location.Y, Location.Z - 50), 50.f, 950.f, D3DXCOLOR(1.f, 0.64f, 0.f, 1.f));
						RenderCircle3D(gm, FVector(Location.X, Location.Y, Location.Z - 50), 50.f, 475.f, D3DXCOLOR(1.0f, 0.32f, 0.f, 1.f));
						RenderCircle3D(gm, FVector(Location.X, Location.Y, Location.Z - 50), 50.f, 237.f, D3DXCOLOR(1.0f, 0.26f, 0.2f, 1.f));
						RenderCircle3D(gm, FVector(Location.X, Location.Y, Location.Z - 50), 50.f, 118.f, D3DXCOLOR(1.0f, 0.f, 0.f, 1.f));

					}
					if (GnameType::IsStunGrenade(grenade.items))
					{
						if (Settings::ESP::Options::GrenadeType == 0) {
							GrenadeTexts.push_back(Text(m_FVisuals, (GnameType::PlayerGrenade(grenade.items)) + std::string(" " + dis), 1, 14, D3DXCOLOR(.75, .75, .75, 1.f)));
							GL3Draw::GetInstance()->RenderCircle(ImVec2(screen.X, screen.Y), 6.f, D3DXCOLOR(.75, .75, .75, 1.f), 2.f);
						}
						else
						{
							GL3Draw::GetInstance()->AddImage(ImVec2(screen.X, screen.Y - 25), ImVec2(35, 35), (void*)(intptr_t)Icons::BP_Grenade_Stun_Weapon_Wrapper, D3DXCOLOR(1, 1, 1, 1));

						}
					}

				}
				for (auto text : GrenadeTexts)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(screen.X, screen.Y), text.size, text.color);
				}

			}
			GrenadeTexts.clear();
		}

	}

	void RunDraw()
	{
		ESP();
	}
}