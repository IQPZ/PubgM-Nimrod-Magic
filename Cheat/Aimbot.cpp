#include "Includes.h"
VOID RestoreHook();
namespace Aimbot
{
	FVector CopyBONE = FVector();
	FVector CopyHITBONE = FVector();
	FVector CopyRoot = FVector();
	bool fovdischeack = false;
	FRotator GetMagicCoord(FVector local, FVector target) {
		FVector rotation = { local.X - target.X,local.Y - target.Y,local.Z - target.Z };

		FRotator newViewAngle = FRotator();

		float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

		newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float)3.14159265358979323846);
		newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float)3.14159265358979323846);
		newViewAngle.Roll = (float)0.f;

		if (rotation.X >= 0.f)
			newViewAngle.Yaw += 180.0f;

		return newViewAngle;
	}
	int bulit = 0;

	void Aimbot()
	{
		for (;;)
		{
			Manager gm(Globals::width, Globals::height);

			bool enable = false;
			int aimkey = 1;
			bool autolock = false;
			bool nearestbone = false;
			Share::AimFov = 0;
			Share::distance = 0;
			bool recoil = false;
			float compesation = 0;
			float smooth = 0;
			int hitbox = 0;

			int Start_Bulit = 0;
			int End_Bulit = 0;

			if (GnameType::Weapon_Pistol(gm.LocalPlayer.weapon))
			{
				enable = Settings::Aimbot::PistolConfig::enable;
				aimkey = Settings::Aimbot::PistolConfig::aimkey;
				autolock = Settings::Aimbot::PistolConfig::autolock;
				nearestbone = Settings::Aimbot::PistolConfig::legitaim;
				Share::AimFov = Settings::Aimbot::PistolConfig::fov;
				Share::distance = Settings::Aimbot::PistolConfig::distance;
				recoil = Settings::Aimbot::PistolConfig::recoil;
				compesation = Settings::Aimbot::PistolConfig::compesation;
				smooth = Settings::Aimbot::PistolConfig::smooth;
				hitbox = Settings::Aimbot::PistolConfig::hitbox;
				Start_Bulit = Settings::Aimbot::PistolConfig::PerfectHit::Start;
				End_Bulit = Settings::Aimbot::PistolConfig::PerfectHit::End;

			}
			else if (GnameType::Weapon_IsAR(gm.LocalPlayer.weapon))
			{
				enable = Settings::Aimbot::ARConfig::enable;
				aimkey = Settings::Aimbot::ARConfig::aimkey;
				autolock = Settings::Aimbot::ARConfig::autolock;
				nearestbone = Settings::Aimbot::ARConfig::legitaim;
				Share::AimFov = Settings::Aimbot::ARConfig::fov;
				Share::distance = Settings::Aimbot::ARConfig::distance;
				recoil = Settings::Aimbot::ARConfig::recoil;
				compesation = Settings::Aimbot::ARConfig::compesation;
				smooth = Settings::Aimbot::ARConfig::smooth;
				hitbox = Settings::Aimbot::ARConfig::hitbox;
				Start_Bulit = Settings::Aimbot::PistolConfig::PerfectHit::Start;
				End_Bulit = Settings::Aimbot::PistolConfig::PerfectHit::End;

			}
			else if (GnameType::Weapon_IsSMG(gm.LocalPlayer.weapon))
			{
				enable = Settings::Aimbot::SMGConfig::enable;
				aimkey = Settings::Aimbot::SMGConfig::aimkey;
				autolock = Settings::Aimbot::SMGConfig::autolock;
				nearestbone = Settings::Aimbot::SMGConfig::legitaim;
				Share::AimFov = Settings::Aimbot::SMGConfig::fov;
				Share::distance = Settings::Aimbot::SMGConfig::distance;
				recoil = Settings::Aimbot::SMGConfig::recoil;
				compesation = Settings::Aimbot::SMGConfig::compesation;
				smooth = Settings::Aimbot::SMGConfig::smooth;
				hitbox = Settings::Aimbot::SMGConfig::hitbox;
				Start_Bulit = Settings::Aimbot::SMGConfig::PerfectHit::Start;
				End_Bulit = Settings::Aimbot::SMGConfig::PerfectHit::End;

			}
			else if (GnameType::Weapon_IsSniper(gm.LocalPlayer.weapon))
			{
				enable = Settings::Aimbot::SniperConfig::enable;
				aimkey = Settings::Aimbot::SniperConfig::aimkey;
				autolock = Settings::Aimbot::SniperConfig::autolock;
				nearestbone = Settings::Aimbot::SniperConfig::legitaim;
				Share::AimFov = Settings::Aimbot::SniperConfig::fov;
				Share::distance = Settings::Aimbot::SniperConfig::distance;
				recoil = Settings::Aimbot::SniperConfig::recoil;
				compesation = Settings::Aimbot::SniperConfig::compesation;
				smooth = Settings::Aimbot::SniperConfig::smooth;
				hitbox = Settings::Aimbot::SniperConfig::hitbox;

				Start_Bulit = Settings::Aimbot::SMGConfig::PerfectHit::Start;
				End_Bulit = Settings::Aimbot::SMGConfig::PerfectHit::End;

			}
			else if (GnameType::Weapon_ShotGun(gm.LocalPlayer.weapon))
			{
				enable = Settings::Aimbot::ShotGunConfig::enable;
				aimkey = Settings::Aimbot::ShotGunConfig::aimkey;
				autolock = Settings::Aimbot::ShotGunConfig::autolock;
				nearestbone = Settings::Aimbot::ShotGunConfig::legitaim;
				Share::AimFov = Settings::Aimbot::ShotGunConfig::fov;
				Share::distance = Settings::Aimbot::ShotGunConfig::distance;
				recoil = Settings::Aimbot::ShotGunConfig::recoil;
				compesation = Settings::Aimbot::ShotGunConfig::compesation;
				smooth = Settings::Aimbot::ShotGunConfig::smooth;
				hitbox = Settings::Aimbot::ShotGunConfig::hitbox;

				Start_Bulit = Settings::Aimbot::SMGConfig::PerfectHit::Start;
				End_Bulit = Settings::Aimbot::SMGConfig::PerfectHit::End;

			}
			else if (GnameType::Weapon_IsOther(gm.LocalPlayer.weapon))
			{
				enable = Settings::Aimbot::LMGConfig::enable;
				aimkey = Settings::Aimbot::LMGConfig::aimkey;
				autolock = Settings::Aimbot::LMGConfig::autolock;
				nearestbone = Settings::Aimbot::LMGConfig::legitaim;
				Share::AimFov = Settings::Aimbot::LMGConfig::fov;
				Share::distance = Settings::Aimbot::LMGConfig::distance;
				recoil = Settings::Aimbot::LMGConfig::recoil;
				compesation = Settings::Aimbot::LMGConfig::compesation;
				smooth = Settings::Aimbot::LMGConfig::smooth;
				hitbox = Settings::Aimbot::LMGConfig::hitbox;

				Start_Bulit = Settings::Aimbot::LMGConfig::PerfectHit::Start;
				End_Bulit = Settings::Aimbot::LMGConfig::PerfectHit::End;

			}
			else
			{
				enable = false;
				aimkey = 1;
				autolock = false;
				nearestbone = false;
				Share::AimFov = 0;
				Share::distance = 0;
				recoil = false;
				compesation = 0;
				smooth = 0;
				hitbox = 0;

				Start_Bulit = 0;
				End_Bulit = 0;

			}

			if (Settings::Aimbot::aimmode == 2)
			{
				if(!Settings::Aimbot::unlockmagiclegit)
				Share::AimFov = 4;
			}
			fovdischeack = enable;
			CopyBONE = { 0,0,0 };
			CopyHITBONE = { 0,0,0 };
			CopyRoot = { 0,0,0 };

			FVector HitBone = { 0,0,0 };
			float flRecoil = 0.f;
			FVector BONE = FVector();
			FVector HITBONE = FVector();

			if ((Utils::keydown(aimkey) || autolock) && Settings::Aimbot::enable)
			{

				if ((gm.LocalPlayer.Ammo > 0 && !GnameType::Weapon_IsGrenade(gm.LocalPlayer.weapon)) && enable)
				{

					std::vector<FVector> HitBoxesToScan = std::vector<FVector>();
					if (Settings::Aimbot::mode == 0)
					{
						if (nearestbone)
							hitbox = 3;

						switch (hitbox)
						{
						case 0:
							HitBoxesToScan.push_back(gm.PlayersCenterCrossDistance.AimBones.HEAD);
							break;
						case 1:
							HitBoxesToScan.push_back(gm.PlayersCenterCrossDistance.AimBones.NECK);
							break;
						case 2:
							HitBoxesToScan.push_back(gm.PlayersCenterCrossDistance.AimBones.Chest);
							break;
						case 3:
							HitBoxesToScan.push_back(gm.PlayersCenterCrossDistance.AimBones.NerstBone);
							break;

						default:
							break;
						}

					}
					else
					{

						if (nearestbone)
							hitbox = 3;

						switch (hitbox)
						{
						case 0:
							HitBoxesToScan.push_back(gm.PlayersClosetCrossDistance.AimBones.HEAD);
							break;
						case 1:
							HitBoxesToScan.push_back(gm.PlayersClosetCrossDistance.AimBones.NECK);
							break;
						case 2:
							HitBoxesToScan.push_back(gm.PlayersClosetCrossDistance.AimBones.Chest);
							break;
						case 3:
							HitBoxesToScan.push_back(gm.PlayersClosetCrossDistance.AimBones.NerstBone);
							break;
						default:
							break;
						}

					}
					for (auto hitbox : HitBoxesToScan)
					{
						if (hitbox.X > 0)
						{
							BONE = hitbox;
							HITBONE = hitbox;
							if (Settings::Aimbot::prediction)
							{

								float InitialSpeed = gm.LocalPlayer.BulletFireSpeed;
								FVector velocity;

								if (Settings::Aimbot::mode == 0)
								{
									if (GnameType::playerstatus(gm.PlayersCenterCrossDistance.status) == "Driving")
									{
										velocity = gm.VehiclesCenterCrossDistance.ReplicatedMovement.LinearVelocity;
									}
									else
									{
										velocity = gm.PlayersCenterCrossDistance.ComponentVelocity;
									}
								}
								else
								{
									if (GnameType::playerstatus(gm.PlayersClosetCrossDistance.status) == "Driving")
									{
										velocity = gm.VehiclesClosetCrossDistance.ReplicatedMovement.LinearVelocity;
									}
									else
									{
										velocity = gm.PlayersClosetCrossDistance.ComponentVelocity;
									}
								}

								FVector AimCorrection = Utils::AimbotCorrection(InitialSpeed, MyLocalPlayer.WeaponPose, BONE, velocity);
								BONE.X = AimCorrection.X;
								BONE.Y = AimCorrection.Y;
								BONE.Z = AimCorrection.Z;
							}
							if (recoil)
							{

								if (!GnameType::Weapon_IsSniper(gm.LocalPlayer.weapon))
								{
									FRotator sway = CameraCacheEntry.Rotation;
									sway.Pitch += gm.LocalPlayer.AccessoriesVRecoilFactor * compesation;
									FVector RCS;
									if (gm.WorldToScreenAim(BONE, sway, RCS))
									{
										HitBone = RCS;
									}
								}
								else
								{
									HitBone = gm.CalcSoldierFuturePos(FVector(BONE.X, BONE.Y, BONE.Z));
								}
							}
							else
							{
								HitBone = gm.CalcSoldierFuturePos(FVector(BONE.X, BONE.Y, BONE.Z));
							}
							auto HitBonePos = FVector2D(HitBone.X, HitBone.Y + flRecoil);
							if (Settings::Aimbot::aimmode == 0) {
								if (Share::E_Magic == true)
								{
									if (rpm->read<BYTE>(MagicBulletHook + 60) == 1.f) 
									{
										rpm->write<BYTE>((MagicBulletHook + 60), 0);

										rpm->write<float>((MagicBulletHook + 54), 0);
										rpm->write<float>((MagicBulletHook + 44), 0);
									}

								}
								Utils::AimAtPosV2(Globals::width, Globals::height, HitBonePos.X, HitBonePos.Y, smooth, 10, 5);

							}
							else if (Settings::Aimbot::aimmode == 1)
							{
								if (Share::E_Magic == true)
								{
									if (rpm->read<bool>(MagicBulletHook + 60) == 0)
										rpm->write<BYTE>((MagicBulletHook + 60), 1);

									if (rpm->read<bool>(MagicBulletHook + 60) == 1)
									{
										FRotator Magic = GetMagicCoord(gm.LocalPlayer.WeaponPose, BONE);
										rpm->write<float>((MagicBulletHook + 54), Magic.Yaw);
										rpm->write<float>((MagicBulletHook + 44), Magic.Pitch);

									}
								}
							}
							else if (Settings::Aimbot::aimmode == 2)
							{
								Share::E_Magic = true;
								if (Share::E_Magic == true)
								{

									if (gm.LocalPlayer.bIsWeaponFiring == true) {

										if (bulit >= Start_Bulit && bulit <= End_Bulit)
										{
											rpm->write<BYTE>((MagicBulletHook + 60), 1);
										}
										else
										{
											rpm->write<BYTE>((MagicBulletHook + 60), 0);
											rpm->write<float>((MagicBulletHook + 54), 0);
											rpm->write<float>((MagicBulletHook + 44), 0);

										}

										if (bulit >= 30)
											bulit = 0;

										bulit++;



										if (rpm->read<bool>(MagicBulletHook + 60) == 1) {
											FRotator Magic = GetMagicCoord(gm.LocalPlayer.WeaponPose, BONE);
											rpm->write<float>((MagicBulletHook + 54), Magic.Yaw);
											rpm->write<float>((MagicBulletHook + 44), Magic.Pitch);

										}
									}
								}
							}
							else if (Settings::Aimbot::aimmode == 3)
							{
								Share::E_Magic = true;
								if (Share::E_Magic == true)
								{

									if (gm.LocalPlayer.bIsWeaponFiring == true) {

										if (bulit >= Start_Bulit && bulit <= End_Bulit)
										{
											rpm->write<BYTE>((MagicBulletHook + 60), 1);
										}
										else
										{
											rpm->write<BYTE>((MagicBulletHook + 60), 0);
											rpm->write<float>((MagicBulletHook + 54), 0);
											rpm->write<float>((MagicBulletHook + 44), 0);

										}

										if (bulit >= 30)
											bulit = 0;

										bulit++;

										if (rpm->read<bool>(MagicBulletHook + 60) == 1) {
											FRotator Magic = GetMagicCoord(gm.LocalPlayer.WeaponPose, BONE);
											rpm->write<float>((MagicBulletHook + 54), Magic.Yaw);
											rpm->write<float>((MagicBulletHook + 44), Magic.Pitch);

										}

										Utils::AimAtPosV2(Globals::width, Globals::height, HitBonePos.X, HitBonePos.Y, smooth, 10, 5);

									}
								}
							}

							CopyBONE = BONE;
							CopyHITBONE = HITBONE;
							if (Settings::Aimbot::mode == 0)
								CopyRoot = gm.PlayersCenterCrossDistance.AimBones.ROOT;
							else
								CopyRoot = gm.PlayersClosetCrossDistance.AimBones.ROOT;

						}
						else
						{
							if (Share::E_Magic == true)
							{
								if (rpm->read<bool>(MagicBulletHook + 60) == 1)
								{
									rpm->write<BYTE>((MagicBulletHook + 60), 0);
									rpm->write<float>((MagicBulletHook + 54), 0);
									rpm->write<float>((MagicBulletHook + 44), 0);
								}
							}
						}
					}
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(10));

		}
	}

	void RunDraw()
	{
		Manager gm(Globals::width, Globals::height);

		if (Settings::Aimbot::drawfov && Settings::Aimbot::enable && fovdischeack)
		{
			if(Share::E_Magic == true)
			GL3Draw::GetInstance()->RenderCircle(ImVec2(Globals::width / 2, Globals::height / 2), Share::AimFov * 8, D3DXCOLOR(1.f, 0.f, 0.f, .3), 1);
			else
			GL3Draw::GetInstance()->RenderCircle(ImVec2(Globals::width / 2, Globals::height / 2), Share::AimFov * 8, D3DXCOLOR(1.f, 1.f, 1.f, .3), 1);

		}
		if (Settings::Aimbot::enable && Settings::Aimbot::drawhitbox)
		{
			if (CopyBONE.X > 0 && CopyHITBONE.X > 0 && CopyRoot.X > 0) {
				FVector OUTBONE, ovecScreenOrgin , OUTHEAD;
				if (gm.WorldToScreen(CopyBONE, OUTBONE) && gm.WorldToScreen(CopyRoot, ovecScreenOrgin) && gm.WorldToScreen(CopyHITBONE, OUTHEAD))
				{
					if (Settings::Aimbot::hitboxtype == 0)
					{
						GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Diagonal, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 10, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
						GL3Draw::GetInstance()->RenderCircle(ImVec2(OUTBONE.X, OUTBONE.Y), (ovecScreenOrgin.Y - OUTHEAD.Y) / 4, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
						GL3Draw::GetInstance()->RenderLine(ImVec2(OUTHEAD.X, OUTHEAD.Y), ImVec2(OUTBONE.X, OUTBONE.Y), D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
					}
					else if (Settings::Aimbot::hitboxtype == 1)
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

	}
	void Run()
	{
		Aimbot();
	}
}
 
