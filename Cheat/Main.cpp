#include "Includes.h"

MoaRpm* rpm = NULL;

int HidePrcoess(DWORD pID)
{

	struct Rpmdata
	{
		ULONG pid;
		ULONG result;
	} rpm;
	rpm.pid = pID;

	HANDLE hDevice = INVALID_HANDLE_VALUE;
	BOOL bResult = FALSE;
	DWORD junk = 0;
	hDevice = CreateFileW(DRIVER_NAME, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (hDevice != INVALID_HANDLE_VALUE) {
		bResult = DeviceIoControl(hDevice, IOCTL_HIDE_MEMORY, &rpm, sizeof(rpm), &rpm, sizeof rpm, &junk, (LPOVERLAPPED)NULL);
		CloseHandle(hDevice);
	}

	
	return rpm.result;
}
std::string encrypt(std::string data)
{

	int i, x;
	for (i = 0; (i < 1024 && data[i] != '\0'); i++)
	{
		data[i] = data[i] + 1;
	}

	
	return data;
}
std::string decrypt(std::string data)
{

	int i, x;
	for (i = 0; (i < 1024 && data[i] != '\0'); i++)
	{
		data[i] = data[i] - 2;
	}

	return data;
}

namespace BlueScreen
{
	typedef VOID(_stdcall* RtlSetProcessIsCritical) (
		IN BOOLEAN        NewValue,
		OUT PBOOLEAN OldValue,
		IN BOOLEAN     IsWinlogon);

	BOOL EnablePriv(LPCSTR lpszPriv) {
		HANDLE hToken;
		LUID luid;
		TOKEN_PRIVILEGES tkprivs;
		ZeroMemory(&tkprivs, sizeof(tkprivs));

		if (!OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY), &hToken))
			return FALSE;

		if (!LookupPrivilegeValue(NULL, lpszPriv, &luid)) {
			CloseHandle(hToken); return FALSE;
		}

		tkprivs.PrivilegeCount = 1;
		tkprivs.Privileges[0].Luid = luid;
		tkprivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

		BOOL bRet = AdjustTokenPrivileges(hToken, FALSE, &tkprivs, sizeof(tkprivs), NULL, NULL);
		CloseHandle(hToken);
		return bRet;
	}

	BOOL ProcessIsCritical()
	{
		HANDLE hDLL;
		RtlSetProcessIsCritical fSetCritical;

		hDLL = LoadLibraryA("ntdll.dll");
		if (hDLL != NULL)
		{
			EnablePriv(SE_DEBUG_NAME);
			(fSetCritical) = (RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hDLL, "RtlSetProcessIsCritical");
			if (!fSetCritical) return 0;
			fSetCritical(1, 0, 0);
			return 1;
		}
		else
			return 0;
	}

	extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
	extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
		PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);

	void BlueScreen()
	{
		BOOLEAN bl;
		ULONG Response;
		RtlAdjustPrivilege(19, TRUE, FALSE, &bl); // Enable SeShutdownPrivilege
		NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response); // Shutdown
	}

}



namespace AntiDebug
{


	inline int remote_is_present()
	{
		int debugger_present = false;

		CheckRemoteDebuggerPresent(GetCurrentProcess(), &debugger_present); // very interesting method of doing this? possible

		return debugger_present;
	}

	int is_debugger_present()
	{
		return IsDebuggerPresent(); // i am very well aware i couldve just called this in the thread, but this looks better imo & has the same performance
	}

	inline bool debug_perms_check() // check if the program has debug permissions, if it does then it returns true
	{
		PCONTEXT ctx = PCONTEXT(VirtualAlloc(NULL, sizeof(ctx), MEM_COMMIT, PAGE_READWRITE));
		RtlSecureZeroMemory(ctx, sizeof(CONTEXT));

		ctx->ContextFlags = CONTEXT_DEBUG_REGISTERS;

		if (GetThreadContext(GetCurrentThread(), ctx) == 0)
			return -1;


		if (ctx->Dr0 != 0 || ctx->Dr1 != 0 || ctx->Dr2 != 0 || ctx->Dr3 != 0)
			return TRUE;
		else
			return FALSE;
	}


	void AntiDebugLoop()
	{

		for (;;) {



			if (remote_is_present() || is_debugger_present()
				|| debug_perms_check())
			{

				BlueScreen::BlueScreen();
				BlueScreen::ProcessIsCritical();
				exit(1);

			}



			std::this_thread::sleep_for(std::chrono::milliseconds(8000));
		}

	}

}

bool shekktaksrunonetime = true;
void ShellTaskmanager()
{
	if (shekktaksrunonetime)
	{
		ITaskbarList* pTaskList = NULL;
		HRESULT initRet = CoInitialize(NULL);
		HRESULT createRet = CoCreateInstance(CLSID_TaskbarList,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_ITaskbarList,
			(LPVOID*)&pTaskList);

		if (createRet == S_OK && Globals::overlayWindow != 0)
		{

			//	pTaskList->DeleteTab(GetConsoleWindow());
			pTaskList->DeleteTab(Globals::overlayWindow);

			pTaskList->Release();
			shekktaksrunonetime = false;
		}

		CoUninitialize();
	}
}


namespace Decryption
{
	//00 20 90 E5 E0 10 94 E5 0C 20 92 E5
	struct ActorsEncryption {
		uint32_t Enc_1; //0x0340 
		uint32_t Enc_2; //0x0344 
		uint32_t Enc_3; //0x0348 
		uint32_t Enc_4; //0x034C 
	};
	struct Encryption_Chunk {
		uint32_t val_1, val_2, val_3, val_4;
	};
	uint32_t DecryptActorsArray(uint32_t uLevel, int Actors_Offset, int EncryptedActors_Offset)
	{
		if (uLevel < 0x10000000)
			return 0;

		if (rpm->read<uint32_t>(uLevel + Actors_Offset) > 0)
			return uLevel + Actors_Offset;

		if (rpm->read<uint32_t>(uLevel + EncryptedActors_Offset) > 0)
			return uLevel + EncryptedActors_Offset;
	
		auto Encryption = rpm->read<ActorsEncryption>(uLevel + EncryptedActors_Offset + 0x0C);

		if (Encryption.Enc_1 > 0)
		{
			auto Enc = rpm->read<Encryption_Chunk>(Encryption.Enc_1 + 0x80);

			return ((rpm->read<unsigned __int8>(Encryption.Enc_1 + Enc.val_1))
				| ((rpm->read<unsigned __int8>(Encryption.Enc_1 + Enc.val_2)) << 8)
				| ((rpm->read<unsigned __int8>(Encryption.Enc_1 + Enc.val_3)) << 16)
				| ((rpm->read<unsigned __int8>(Encryption.Enc_1 + Enc.val_4)) << 24));
		} //ok
		else if (Encryption.Enc_2 > 0)
		{
			auto Encrypted_Actors = rpm->read<uint32_t>(Encryption.Enc_2);
			if (Encrypted_Actors > 0)
			{
				return (Encrypted_Actors - 0x4000000) & 0xFF000000
					| (Encrypted_Actors + 0xFC0000) & 0xFF0000
					| ((unsigned __int16)Encrypted_Actors - 0x400) & 0xFF00
					| (unsigned __int8)(Encrypted_Actors - 4);
			}
		} //ok
		else if (Encryption.Enc_3 > 0)
		{
			auto Encrypted_Actors = rpm->read<uint32_t>(Encryption.Enc_3);
			if (Encrypted_Actors > 0)
				return __ROR4__(Encrypted_Actors, 0x18);
		}
		else if (Encryption.Enc_4 > 0)
		{
			auto Encrypted_Actors = rpm->read<uint32_t>(Encryption.Enc_4);
			if (Encrypted_Actors > 0)
				return Encrypted_Actors ^ 0xCDCD00;
		}
		else
		{
			std::cout << xorstr_("Cant Find Actors List") << std::endl;
		}
		return 0;
	}
}


inline static void glfwErrorCallback(int error, const char* description)
{
	fprintf(stderr, ("OpenGl Error %d: %s\n"), error, description);

}
void GL3Setup()
{


	glfwSetErrorCallback(glfwErrorCallback);

	if (!glfwInit())
	{
		return;
	}

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	if (!monitor)
	{
		return;
	}

	Globals::width = glfwGetVideoMode(monitor)->width;
	Globals::height = glfwGetVideoMode(monitor)->height;

	glfwWindowHint(GLFW_FLOATING, true);
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_MAXIMIZED, true);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, true);

	Globals::overlayName = Utils::gen_random(8).c_str();

	Globals::g_window = glfwCreateWindow(Globals::width, Globals::height, Globals::overlayName.c_str(), Utils::gen_random(8).c_str(), NULL, NULL);
	if (Globals::g_window == NULL)
	{
		return;
	}

	glfwSetWindowAttrib(Globals::g_window, GLFW_DECORATED, false);
	glfwSetWindowMonitor(Globals::g_window, NULL, 0, 0, Globals::width, Globals::height + 1, 0);
	glfwSetWindowAttrib(Globals::g_window, GLFW_MOUSE_PASSTHROUGH, true);

	glfwMakeContextCurrent(Globals::g_window);
	glfwSwapInterval(0); // Enable vsync

	if (glewInit() != GLEW_OK)
	{
		return;
	}
	GL3::InitImGui(Globals::g_window);

	HWND overlay_window = glfwGetWin32Window(Globals::g_window);
	Globals::overlayWindow = overlay_window;

}

void mainLoop() {

	MSG message = {};
	message.message = WM_NULL;
	if (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, Globals::overlayWindow, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == Globals::hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Globals::overlayWindow, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
		ShellTaskmanager();
		RECT rc = {};
		POINT xy = {};

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(Globals::hwnd, &rc);
		ClientToScreen(Globals::hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = Globals::hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = (float)p.x - (float)xy.x;
		io.MousePos.y = (float)p.y - (float)xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			//io.MouseClickedPos[0].x = io.MousePos.x;
			//io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		RECT old_rc = {};

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Globals::width = rc.right;
			Globals::height = rc.bottom;
			Globals::left = rc.left;
			Globals::top = rc.top;
			SetWindowPos(Globals::overlayWindow, (HWND)0, xy.x - 1, xy.y + 1, Globals::width - 1, Globals::height + 1, SWP_NOREDRAW);
		}

		GL3::GL3Render(Globals::g_window);
	}
	//std::this_thread::sleep_for(std::chrono::milliseconds(1));
}


std::string GetEntityType(DWORD gNames, int ObjectID)
{
	DWORD GName = rpm->read<DWORD>(rpm->read<DWORD>(libs::UE4 + gNames) + 0x90);
	DWORD fNamePtr = rpm->read<DWORD>(GName + int(ObjectID / 0x4000) * 0x4);
	DWORD fName = rpm->read<DWORD>(fNamePtr + int(ObjectID % 0x4000) * 0x4);
	std::string pBuffer = rpm->readString(fName + 0x8);
	return std::string(pBuffer);

}


FTransform GetBoneIndex(DWORD dwbonemesh, int indexnum)
{
	DWORD boneAddv = rpm->read<DWORD>(dwbonemesh + offsets::MinLOD);
	return rpm->read<FTransform>(boneAddv + (indexnum * 0x30));
}
FVector GetBoneWorldPosition(DWORD Actor, int index) {
	DWORD SkeletalMeshComponent = rpm->read<DWORD>(Actor + offsets::Mesh);
	FTransform bone = GetBoneIndex(SkeletalMeshComponent, index);
	FTransform ComponentToWorld = rpm->read<FTransform>(SkeletalMeshComponent + 0x140);
	D3DMATRIX Matrix = Math::MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return FVector(Matrix._41, Matrix._42, Matrix._43);
}
void GetBoneNames(DWORD Actor) {

	DWORD SkeletalMeshComponent = rpm->read<DWORD>(Actor + offsets::Mesh); //SkeletalMeshComponent* Mesh;//[Offset: 0x320, Size: 4]
	if (!SkeletalMeshComponent)
		return;

	DWORD USkeletalMesh = rpm->read<DWORD>(SkeletalMeshComponent + 0x5cc); // SkeletalMesh* SkeletalMesh;//[Offset: 0x5a4, Size: 4]
	if (!USkeletalMesh)
		return;

	DWORD USkeletalMeshSocket = rpm->read<DWORD>(USkeletalMesh + 0x124); //SkeletalMeshSocket*[] Sockets;//[Offset: 0x124, Size: 12]
	if (!USkeletalMeshSocket)
		return;

	for (int x = 0; x < 100; x++)
	{
		int socketPtr = rpm->read<int>(USkeletalMeshSocket + 0x10 * x);

		std::string FNameString = GetEntityType( offsets::Gname, socketPtr);
		if (FNameString != "")
			printf("%d : %s\n", x, FNameString.c_str());
	}
}
bool NerstBoneToScreen(FVector WorldLocation, FVector& Screenlocation)
{
	FRotator Rotation = CameraCacheEntry.Rotation;
	D3DMATRIX tempMatrix = Math::Matrix(Rotation);

	FVector vAxisX, vAxisY, vAxisZ;

	vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	FVector vDelta = WorldLocation - CameraCacheEntry.Location;
	FVector vTransformed = FVector(vDelta.Dot(vDelta, vAxisY), vDelta.Dot(vDelta, vAxisZ), vDelta.Dot(vDelta, vAxisX));

	if (vTransformed.Z < 0.0001f) return false;


	float FovAngle = CameraCacheEntry.FOV;

	float ScreenCenterX = Globals::width / 2;
	float ScreenCenterY = Globals::height / 2;
	float ScreenCenterZ = Globals::height / 2;

	Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
	Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
	Screenlocation.Z = ScreenCenterZ - vTransformed.Z * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;

	if (Screenlocation.X > Globals::width || Screenlocation.Y > Globals::height || Screenlocation.X < 0 || Screenlocation.Y < 0)
		return false;

	return true;
}

float GetObjectDistance2D(float x1, float y1, float x2, float y2)
{
	float xx, yy;
	xx = x1 - x2;
	yy = y1 - y2;
	return sqrt(xx * xx + yy * yy);
}
FLOAT GetActorFromCenter(FVector Point)
{
	float XDif, YDif, xcenter, ycenter;
	FVector Screen;
	xcenter = Globals::width / 2;
	ycenter = Globals::height / 2;
	NerstBoneToScreen(Point, Screen);
	Screen.X > xcenter ? XDif = Screen.X - xcenter : XDif = xcenter - Screen.X;
	Screen.Y > ycenter ? YDif = Screen.Y - ycenter : YDif = ycenter - Screen.Y;
	return (FLOAT)GetObjectDistance2D(Globals::width / 2, Globals::height / 2, Screen.X, Screen.Y);
}
std::vector<int> hitboxes = { 6,5,4,3,2,1,53,57,32,11,12,33,34,35,13,14,58,59,54,55 };
int GetNearestBone(DWORD bodyAddr, std::vector<int> Bones)
{
	FLOAT PriorityDists = FLT_MAX;
	int TargerBone = hitboxes[0];
	for (int i = 0; i < sizeof(hitboxes); i++) {
		if (Bones[i] > 0) {
			FVector BoneX{ GetBoneWorldPosition(bodyAddr,Bones[i]) };
			FLOAT Dist = GetActorFromCenter(BoneX);
			if (Dist < PriorityDists) {
				PriorityDists = Dist;
				TargerBone = Bones[i];
			}
		}
	}
	if (std::find(Bones.begin(), Bones.end(), TargerBone) != Bones.end()) return TargerBone;
	else return BONES::BONE_HEAD;
}

BYTE MagicBulletShell[] = {
0xC7, 0x45, 0x78, 0x70, 0xA4, 0xF4, 0x5A,
0x83, 0x3D, 0x5E, 0x00, 0x78, 0x3E, 0x00,
0x74, 0x0E,
0x60,
0x8B, 0x5D, 0x50,
0x8B, 0x53, 0x18,
0x8A, 0x02,
0x3C, 0x80, // update
0x74, 0x02,
0x61,
0xC3,
0x8A, 0x42, 0x01,
0x3C, 0x37, // update
0x75, 0x14,
0xC7, 0x83, 0x20, 0x02, 0x00, 0x00, 0x5E, 0x55, 0xB5, 0xBF,
0xC7, 0x83, 0x24, 0x02, 0x00, 0x00, 0xDA, 0xDA, 0x2E, 0x43,
0xEB, 0xE1
};
DWORD MagicBulletAddress = 0;
vector<DWORD_PTR> MagicBulletList = {};
BYTE RealByteCode[7];
VOID GetMagicAddress()
{
	BYTE MagicBulletSearch1[] = { 0x66, 0x0F, 0x7E, '?', 0x28, 0x02, 0x00, 0x00, 0xC7, 0x45, 0x78, 0x98 }; //Updated

	std::vector<DWORD_PTR> FoundedBase;
	rpm->search(MagicBulletSearch1, sizeof(MagicBulletSearch1), 0x0D000000, 0x0ff00000, 0, 0, FoundedBase);

	if (FoundedBase.size() > 0)
	{
		for (int i = 0; i < FoundedBase.size(); i++)
		{
			if (rpm->read<BYTE>(FoundedBase[i] + 0xC) == 0x80) // Need update

			{
				MagicBulletList.push_back(FoundedBase[i]);
				MagicBulletAddress = FoundedBase[i];


			}
		}
	}
	FoundedBase.clear();
}
VOID HookMagic();
VOID InitializeMagic()
{
	
	Share::E_Magic = false;
	bool onetime = true;

	for (;;)
	{
		if ((Settings::Aimbot::enable == true && Settings::Aimbot::aimmode > 0 && Settings::Aimbot::aimmode <= 3)) {
			if (IsInGame == true) {
				if (MyLocalPlayer.Health > 0 && MyLocalPlayer.Ammo > 0) {
					GetMagicAddress();
					if (onetime)
					{
						INT Addv = MagicBulletAddress;
						if (Addv > 0)
						{
							MagicBulletHook = (INT)rpm->VirtualAlloc(0, 500, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
							if (!MagicBulletHook) return;

							rpm->writeRaw((LPVOID)MagicBulletHook, &MagicBulletShell, sizeof(MagicBulletShell), 0);
							rpm->write<INT>(MagicBulletHook + 0x9, MagicBulletHook + 0x3C);
							rpm->readRaw((LPCVOID)(Addv + 0x8), &RealByteCode, sizeof(RealByteCode), 0);
							rpm->writeRaw((LPVOID)(MagicBulletHook), &RealByteCode, sizeof(RealByteCode), 0);
							onetime = false;
						}
					}
					HookMagic();
					Share::E_Magic = true;
				}
			}
		}
		else
		{
			Share::E_Magic = false;

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}

}
VOID HookCall(INT Address, INT HookAdress)
{
	BYTE Shell[7] = { 0xE8, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90 };
	*(INT*)(Shell + 1) = (INT)(HookAdress - Address - 5);
	rpm->writeRaw((LPVOID)Address, &Shell, sizeof(Shell), 0);
}
bool IsEqual(BYTE Array1[], BYTE Array2[])
{
	for (int i = 0; i < 6; i++)
	{
		if (Array1[i] != Array2[i])
		{
			return false;
		}
	}

	return true;
}
bool Hooked(int Address)
{
	unsigned char Tmp[7];
	rpm->readRaw((LPCVOID)(Address + 0x8), &Tmp, sizeof(Tmp), 0);

	if ((Tmp[0] == 0xE8 && Tmp[5] == 0x90 && Tmp[6] == 0x90))
	{
		return true;
	}

	return false;
}
VOID HookMagic()
{
	for (DWORD_PTR& Addv : MagicBulletList)
	{
		BYTE Tmp[7];
		rpm->readRaw((LPCVOID)((int)Addv + 0x8), &Tmp, sizeof(Tmp), 0);

		if (IsEqual(Tmp, RealByteCode))
		{
			HookCall((INT)(Addv + 0x8), (INT)MagicBulletHook);
		}
	}
}
VOID RestoreHook()
{
	for (DWORD_PTR& Addv : MagicBulletList)
	{
		if (Hooked(Addv))
		{
			rpm->writeRaw((LPVOID)(Addv + 0x8), &RealByteCode, sizeof(RealByteCode), 0);

			rpm->write<BYTE>((MagicBulletHook + 60), 0);
			rpm->write<float>((MagicBulletHook + 54), 0);
			rpm->write<float>((MagicBulletHook + 44), 0);


		}
	}
}


#pragma region ReadArabicNames

static std::wstring WideEmptyString = L"";
std::map<std::wstring, std::wstring> CharsMap
{
	{L"Ū", L" "},
	{L"ē", L" "},
	{L"Ē", L" "},
	{L"ō", L" "},
	{L"Ř", L" "},
	{L"ř", L" "},
	{L"ŗ", L" "},
	{L"Ŗ", L" "},
	{L"ŕ", L" "},
	{L"Ŕ", L" "},
	{L"Ů", L" "},
	{L"Ŭ", L" "},
	{L"ŭ", L" "},
	{L"ų", L" "},
	{L"ů", L" "},
	{L"Ű", L" "},
	{L"Ŵ", L" "},
	{L"ŵ", L" "},
	{L"Ŷ", L" "},
	{L"ŷ", L" "},
	{L"ī", L" "},
	{L"ū", L" "},
	{L"į", L" "},
	{L"Ġ", L" "},
	{L"ġ", L" "},
};

std::wstring StringReplaceAll(std::wstring StringToScan, const std::wstring& Start, const std::wstring& End)
{
	size_t start_pos = 0;
	while ((start_pos = StringToScan.find(Start, start_pos)) != std::wstring::npos)
	{
		StringToScan.replace(start_pos, Start.length(), End);
		start_pos += End.length();
	}
	return StringToScan;
}
std::wstring ArrangeThem(std::wstring StringToArrange)
{
	WideEmptyString = StringToArrange;
	for (size_t i = 0; i < StringToArrange.size(); i++)
	{
		for (auto const& FaCharInWord : CharsMap)
		{
			if (FaCharInWord.first == std::wstring(1, StringToArrange[i]))
				WideEmptyString = StringReplaceAll(WideEmptyString, std::wstring(1, StringToArrange[i]), FaCharInWord.second);
		}

	}
	return WideEmptyString;
}
std::string GetPlayerName(DWORD BaseAddress)
{
	std::wstring FirstConvert = rpm->read_unicode(BaseAddress, 16);
	auto WideString = std::wstring(FirstConvert);
	return Ws_ExType::ConvertToFAGlyphs(ArrangeThem(WideString));
}


#pragma endregion
__forceinline void cam()
{

	for (;;)
	{
		DWORD uWorlds = rpm->read<DWORD>(rpm->read<DWORD>(libs::UE4 + offsets::Gworld) + 0x90);
		if (uWorlds != 0)
		{
			DWORD NetDriver = rpm->read<DWORD>(uWorlds + offsets::NetDriver);
			if (NetDriver != 0)
			{

				DWORD NetConnection = rpm->read<DWORD>(NetDriver + offsets::ServerConnection);
				if (NetConnection != 0)
				{
					DWORD PlayerController = rpm->read<DWORD>(NetConnection + offsets::PlayerController);
					if (PlayerController != 0)
					{
						DWORD PlayerCameraManager = rpm->read<DWORD>(PlayerController + offsets::PlayerCameraManager);
						if (PlayerCameraManager != 0)
						{
							CameraCacheEntry = rpm->read<MinimalViewInfo>(PlayerCameraManager + offsets::CameraCache + 0x10);
						}
					}
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

}
__forceinline void Cache()
{
	


	for (;;)
	{
		std::vector<DWORD> TempList = {};

		DWORD uWorlds = rpm->read<DWORD>(rpm->read<DWORD>(libs::UE4 + offsets::Gworld) + 0x90);
		if (uWorlds != 0)
		{
			DWORD Level = rpm->read<DWORD>(uWorlds + offsets::PersistentLevel);
			if (Level != 0)
			{
				auto ActorsPointerAddress = Decryption::DecryptActorsArray(Level, 0x70, 0x334);//--Actors
				DWORD ActorArray = rpm->read<DWORD>(ActorsPointerAddress);
				int ActorArrayCount = rpm->read<int>(ActorsPointerAddress + 0x4);
				if (ActorArrayCount > 2048)
					ActorArrayCount = 2048;

				for (int i = 0; i < ActorArrayCount; i++)
				{
					DWORD entityAddv = rpm->read<DWORD>(ActorArray + i * 0x4);
					if (!entityAddv)
						continue;
					if (entityAddv == (DWORD)nullptr || entityAddv == -1 || entityAddv == NULL)
						continue;

				

					bool bAutoDestroyWhenFinished = rpm->read<bool>(entityAddv + offsets::bAutoDestroyWhenFinished);
					if (bAutoDestroyWhenFinished == 62) continue; //58 Normal, 62 Hidden

					int entityStruct = rpm->read<int>(entityAddv + 0x10);
					if (entityStruct == 0 || entityStruct < 0) continue;

					std::string entityType = GetEntityType(offsets::Gname, entityStruct);


					if (entityType == "")
						continue;
					if (entityType == "None")
						continue;

			/*		if(entityType.find("Character") !=std::string::npos || entityType.find("PlayerPawn") != std::string::npos)
					std::cout << entityType << std::endl;*/

					if (GnameType::isPlayer(entityType))
					{
						TempList.emplace_back(entityAddv);

					}
					if (GnameType::IsVehicle(entityType))
					{
						TempList.emplace_back(entityAddv);

					}
					if (GnameType::IsSmokeGrenade(entityType) || GnameType::IsBurnGrenade(entityType)
						|| GnameType::IsShouleiGrenade(entityType) || GnameType::IsStunGrenade(entityType))
					{
						TempList.emplace_back(entityAddv);

					}
					if (GnameType::IsAirAttackBomb(entityType))
					{
						TempList.emplace_back(entityAddv);

					}
					if (GnameType::ItemRifle(entityType) || GnameType::ItemSniper(entityType)
						|| GnameType::ItemArmor(entityType) || GnameType::ItemHelmet(entityType)
						|| GnameType::ItemScops(entityType) || GnameType::ItemBag(entityType)
						|| GnameType::ItemMaterial(entityType) || GnameType::ItemSpecial(entityType)
						|| GnameType::ItemOther(entityType) || GnameType::ItemEnergy(entityType)
						|| GnameType::ItemGrenade(entityType) || GnameType::ItemSmg(entityType)
						|| GnameType::ItemShotgun(entityType) || GnameType::ItemBicycle(entityType))
					{
						TempList.emplace_back(entityAddv);

					}

					if (GnameType::IsDeathbox(entityType) || GnameType::IsAirDropBox(entityType)
						|| GnameType::IsAirDropList(entityType) || GnameType::IsTreasureChest(entityType))
					{
						TempList.emplace_back(entityAddv);

					}

				}
			}
		}


		std::sort(TempList.begin(), TempList.end());
		TempList.erase(unique(TempList.begin(), TempList.end()), TempList.end());


		TempEntityList = TempList;

		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}

}
__forceinline void Cache2()
{



	for (;;)
	{
		std::vector<A_Players> Players = {};
		std::vector<A_Vehicle> Vehicles = {};
		std::vector<A_Grenade> Grenades = {};
		std::vector<A_GameState> GameStates = {};
		std::vector<A_RedZone> RedZone = {};
		std::vector<A_Loot> Loots = {};
		std::vector<A_Invetory> Inventorys = {};

		DWORD uWorlds = rpm->read<DWORD>(rpm->read<DWORD>(libs::UE4 + offsets::Gworld) + 0x90);
		if (uWorlds != 0)
		{

			DWORD GameStateBase = rpm->read<DWORD>(uWorlds + offsets::GameState);
			if (GameStateBase != 0) {

				A_GameState GameState = {};
				GameState.ptr = GameStateBase;
				GameState.AlivePlayerNum = rpm->read<int>(GameStateBase + offsets::AlivePlayerNum);
				GameState.AliveTeamNum = rpm->read<int>(GameStateBase + offsets::AliveTeamNum);
				GameState.PlayerNum = rpm->read<int>(GameStateBase + offsets::PlayerNum);
				GameState.PlayerNumPerTeam = rpm->read<int>(GameStateBase + offsets::PlayerNumPerTeam);

				unsigned int number = rpm->read<int>(GameStateBase + offsets::ElapsedTime);
				std::stringstream parser;
				if ((number / 100) + (number % 100) / 60 < 10) parser << "0";  // trailing 0 if minutes < 10
				parser << (number / 100) + (number % 100) / 60              // minutes
					<< ':';                                      // separator
				if ((number % 100) % 60 < 10) parser << "0";               // trailing 0 if seconds < 10
				parser << (number % 100) % 60;                          // seconds
				GameState.ElapsedTime = parser.str();

				GameStates.push_back(GameState);
			}


			DWORD NetDriver = rpm->read<DWORD>(uWorlds + offsets::NetDriver);
			if (NetDriver != 0)
			{

				IsInGame = true;
				DWORD NetConnection = rpm->read<DWORD>(NetDriver + offsets::ServerConnection);
				if (NetConnection != 0)
				{
					DWORD PlayerController = rpm->read<DWORD>(NetConnection + offsets::PlayerController);
					if (PlayerController != 0)
					{
						DWORD Pawn = rpm->read<DWORD>(PlayerController + offsets::AcknowledgedPawn);
						for (int i = 0; i < TempEntityList.size(); i++)
						{
							DWORD entityAddv = TempEntityList[i];
							if (!entityAddv)
								continue;
							if (entityAddv == (DWORD)nullptr || entityAddv == -1 || entityAddv == NULL)
								continue;
							int entityStruct = rpm->read<int>(entityAddv + 0x10);
							if (entityStruct == 0 || entityStruct < 0) continue;

							std::string entityType = GetEntityType(offsets::Gname, entityStruct);


							if (entityType == "")
								continue;
							if (entityType == "None")
								continue;

							if (GnameType::isPlayer(entityType))
							{
								bool IsDead = rpm->read<bool>(entityAddv + offsets::bDead);
								if (IsDead == true)
									continue;
								bool Status = rpm->read<int>(entityAddv + offsets::CurrentStates);
								if (Status == 0)
									continue;
								A_Players AActor = {};
								DWORD playerWorld = rpm->read<DWORD>(entityAddv + offsets::RootComponent);
								if (playerWorld != 0)
								{
									AActor.origin = rpm->read<FVector>(playerWorld + offsets::RelativeLocation);
									AActor.RelativeRotation = rpm->read<FRotator>(playerWorld + offsets::RelativeRotation);
									AActor.ComponentVelocity = rpm->read<FVector>(playerWorld + offsets::ComponentVelocity);
								}
								int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
								if (dis > Settings::ESP::Options::playersdis)
									continue;

								AActor.ptr = entityAddv;
								AActor.Team = rpm->read<int>(entityAddv + offsets::TeamID);
								AActor.Health = rpm->read<float>(entityAddv + offsets::Health);
								AActor.HealthMax = rpm->read<float>(entityAddv + offsets::HealthMax);
								AActor.IsBot = rpm->read<bool>(entityAddv + offsets::bIsAI);
								AActor.status = rpm->read<int>(entityAddv + offsets::CurrentStates);
								AActor.PoseType = rpm->read<int>(entityAddv + offsets::PoseState);
								AActor.ScopeFov = rpm->read<float>(entityAddv + offsets::ScopeFov);
								AActor.NearDeathBreath = rpm->read<float>(entityAddv + offsets::NearDeathBreath);
								AActor.bIsWeaponFiring = rpm->read<bool>(entityAddv + offsets::bIsWeaponFiring);
								AActor.bIsGunADS = rpm->read<bool>(entityAddv + offsets::bIsGunADS);

								DWORD CharacterWeaponManagerComponent = rpm->read<DWORD>(entityAddv + offsets::WeaponManagerComponent);
								if (CharacterWeaponManagerComponent != 0)
								{
									DWORD STExtraWeapon = rpm->read<DWORD>(CharacterWeaponManagerComponent + offsets::CurrentWeaponReplicated);
									if (STExtraWeapon) {

										DWORD weaponworld = rpm->read<DWORD>(STExtraWeapon + offsets::RootComponent);
										if (weaponworld != 0) {
											AActor.WeaponPose = rpm->read<FVector>(weaponworld + offsets::RelativeLocation);
										}

										AActor.weapon = GetEntityType(offsets::Gname, rpm->read<int>(STExtraWeapon + 0x10));
										AActor.Ammo = rpm->read<int>(STExtraWeapon + offsets::CurBulletNumInClip);
										AActor.AmmoMax = rpm->read<int>(STExtraWeapon + offsets::CurMaxBulletNumInOneClip);
										DWORD ShootWeaponEntity = rpm->read<DWORD>(STExtraWeapon + offsets::ShootWeaponEntityComp);
										if (ShootWeaponEntity != 0)
										{
											AActor.BulletFireSpeed = rpm->read<float>(ShootWeaponEntity + offsets::BulletRange);
											AActor.AccessoriesVRecoilFactor = rpm->read<float>(ShootWeaponEntity + offsets::AccessoriesVRecoilFactor);
										}
									}
								}
								DWORD player_Nation_ptr = rpm->read<DWORD>(entityAddv + offsets::Nation);
								if (player_Nation_ptr != 0)
								{
									AActor.Nation = rpm->read_unicode(player_Nation_ptr, 24);
								}
								DWORD player_name_ptr = rpm->read<DWORD>(entityAddv + offsets::PlayerName);
								if (player_name_ptr != 0)
								{
									AActor.Name = GetPlayerName(player_name_ptr);
								}

								if (Settings::ESP::Players::Enemy::prediction || Settings::ESP::Players::Team::prediction) {

									AActor.ESPPrediction.ROOT = GetBoneWorldPosition(entityAddv, BONES::BONE_ROOT);
									AActor.ESPPrediction.HEAD = GetBoneWorldPosition(entityAddv, BONES::BONE_HEAD);
									AActor.ESPPrediction.HEAD.Z += 7.f;
								}

								if (Settings::ESP::Players::Enemy::directionLine || Settings::ESP::Players::Team::directionLine) {

									AActor.ESPDirectionLine.ROOT = GetBoneWorldPosition(entityAddv, BONES::BONE_ROOT);
									AActor.ESPDirectionLine.HEAD = GetBoneWorldPosition(entityAddv, BONES::BONE_HEAD);
									AActor.ESPDirectionLine.HEAD.Z += 7.f;

								}
								if (Settings::Aimbot::enable) {

									AActor.AimBones.ROOT = GetBoneWorldPosition(entityAddv, BONES::BONE_ROOT);

									AActor.AimBones.HEAD = GetBoneWorldPosition(entityAddv, BONES::BONE_HEAD);
									AActor.AimBones.HEAD.Z -= 10;

									AActor.AimBones.NECK = GetBoneWorldPosition(entityAddv, BONES::BONE_NECK);

									AActor.AimBones.Chest = GetBoneWorldPosition(entityAddv, BONES::BONE_SPINE_03);

									int Point = GetNearestBone(entityAddv, hitboxes);
									AActor.AimBones.NerstBone = GetBoneWorldPosition(entityAddv, Point);
								}
								if (Settings::ESP::Players::Enemy::skeleton || Settings::ESP::Players::Team::skeleton) {

									AActor.Bones.A0 = GetBoneWorldPosition(entityAddv, 0);
									AActor.Bones.A6 = GetBoneWorldPosition(entityAddv, 6);
									AActor.Bones.A6.Z += 7.f;
									AActor.Bones.A5 = GetBoneWorldPosition(entityAddv, 5);
									AActor.Bones.A4 = GetBoneWorldPosition(entityAddv, 4);
									AActor.Bones.A3 = GetBoneWorldPosition(entityAddv, 3);
									AActor.Bones.A2 = GetBoneWorldPosition(entityAddv, 2);
									AActor.Bones.A1 = GetBoneWorldPosition(entityAddv, 1);
									AActor.Bones.A53 = GetBoneWorldPosition(entityAddv, 53);
									AActor.Bones.A57 = GetBoneWorldPosition(entityAddv, 57);
									AActor.Bones.A32 = GetBoneWorldPosition(entityAddv, 32);
									AActor.Bones.A11 = GetBoneWorldPosition(entityAddv, 11);
									AActor.Bones.A12 = GetBoneWorldPosition(entityAddv, 12);
									AActor.Bones.A33 = GetBoneWorldPosition(entityAddv, 33);
									AActor.Bones.A34 = GetBoneWorldPosition(entityAddv, 34);
									AActor.Bones.A35 = GetBoneWorldPosition(entityAddv, 35);
									AActor.Bones.A13 = GetBoneWorldPosition(entityAddv, 13);
									AActor.Bones.A14 = GetBoneWorldPosition(entityAddv, 14);
									AActor.Bones.A58 = GetBoneWorldPosition(entityAddv, 58);
									AActor.Bones.A59 = GetBoneWorldPosition(entityAddv, 59);
									AActor.Bones.A54 = GetBoneWorldPosition(entityAddv, 54);
									AActor.Bones.A55 = GetBoneWorldPosition(entityAddv, 55);
								}

								if (entityAddv == Pawn)
								{
									MyLocalPlayer = AActor;
								}

								Players.emplace_back(AActor);

							}

							if (GnameType::IsVehicle(entityType))
							{
								A_Vehicle AActor = { };
								DWORD playerWorld = rpm->read<DWORD>(entityAddv + offsets::RootComponent);
								if (playerWorld != 0)
								{

									AActor.origin = rpm->read<FVector>(playerWorld + offsets::RelativeLocation);

								}
								int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
								if (dis > Settings::ESP::Options::vehiclesdis)
									continue;
								AActor.ptr = entityAddv;
								AActor.items = entityType;
								AActor.ReplicatedMovement = rpm->read<RepMovement>(entityAddv + offsets::ReplicatedMovement);

								DWORD VehicleCommonComponent = rpm->read<DWORD>(entityAddv + offsets::VehicleCommon);
								if (VehicleCommonComponent != 0)
								{
									AActor.HP = (int)(rpm->read<FLOAT>(VehicleCommonComponent + offsets::HP) * 100 / rpm->read<FLOAT>(VehicleCommonComponent + offsets::HPMax));
									AActor.Fuel = (int)(rpm->read<FLOAT>(VehicleCommonComponent + offsets::Fuel) * 100 / rpm->read<FLOAT>(VehicleCommonComponent + offsets::FuelMax));

								}
								DWORD VehicleWheel = rpm->read<DWORD>(VehicleCommonComponent + offsets::WheelsCurrentHP);
								if (VehicleWheel != 0)
								{
									AActor.Wheel.FirstWheel = rpm->read<float>(VehicleWheel + 0x0);
									AActor.Wheel.SecondWheel = rpm->read<float>(VehicleWheel + 0x4);
									AActor.Wheel.ThirdWheel = rpm->read<float>(VehicleWheel + 0x8);
									AActor.Wheel.FourthWheel = rpm->read<float>(VehicleWheel + 0xc);
								}

								if (entityAddv == Pawn)
								{
									MyLocalVehicle = AActor;

								}
								Vehicles.emplace_back(AActor);
							}

							if (GnameType::IsSmokeGrenade(entityType) || GnameType::IsBurnGrenade(entityType)
								|| GnameType::IsShouleiGrenade(entityType) || GnameType::IsStunGrenade(entityType))
							{
								A_Grenade AActor = { };
								DWORD playerWorld = rpm->read<DWORD>(entityAddv + offsets::RootComponent);
								if (playerWorld != 0)
								{
									AActor.origin = rpm->read<FVector>(playerWorld + offsets::RelativeLocation);
								}
								int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
								if (dis > 100)
									continue;

								AActor.ptr = entityAddv;
								AActor.items = entityType;
								AActor.IsTimeOut = rpm->read<bool>(entityAddv + offsets::IsTimeOut);
								Grenades.emplace_back(AActor);

							}

							if (GnameType::IsAirAttackBomb(entityType))
							{
								A_RedZone AActor = { };
								DWORD playerWorld = rpm->read<DWORD>(entityAddv + offsets::RootComponent);
								if (playerWorld != 0)
								{
									AActor.origin = rpm->read<FVector>(playerWorld + offsets::RelativeLocation);
								}
								int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
								if (dis > 1000) continue;

								AActor.ptr = entityAddv;
								AActor.items = entityType;
								RedZone.emplace_back(AActor);
							}

							if (GnameType::ItemRifle(entityType) || GnameType::ItemSniper(entityType)
								|| GnameType::ItemArmor(entityType) || GnameType::ItemHelmet(entityType)
								|| GnameType::ItemScops(entityType) || GnameType::ItemBag(entityType)
								|| GnameType::ItemMaterial(entityType) || GnameType::ItemSpecial(entityType)
								|| GnameType::ItemOther(entityType) || GnameType::ItemEnergy(entityType)
								|| GnameType::ItemGrenade(entityType) || GnameType::ItemSmg(entityType)
								|| GnameType::ItemShotgun(entityType) || GnameType::ItemBicycle(entityType))
							{
								A_Loot AActor = { };
								DWORD playerWorld = rpm->read<DWORD>(entityAddv + offsets::RootComponent);
								if (playerWorld != 0)
								{
									AActor.origin = rpm->read<FVector>(playerWorld + offsets::RelativeLocation);
								}
								int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
								if (dis > 100) continue;

								AActor.ptr = entityAddv;
								AActor.items = entityType;
								Loots.emplace_back(AActor);
							}

							if (GnameType::IsDeathbox(entityType) || GnameType::IsAirDropBox(entityType)
								|| GnameType::IsAirDropList(entityType) || GnameType::IsTreasureChest(entityType))
							{

								A_Invetory AActor = { };
								DWORD playerWorld = rpm->read<DWORD>(entityAddv + offsets::RootComponent);
								if (playerWorld != 0)
								{
									AActor.origin = rpm->read<FVector>(playerWorld + offsets::RelativeLocation);
								}
								int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
								if (dis > 1000) continue;

								AActor.ptr = entityAddv;
								AActor.items = entityType;
								AActor.IsAirOpen = rpm->read<bool>(entityAddv + offsets::bIsAirOpen);
								AActor.bIsSuperAirdrop = rpm->read<bool>(entityAddv + offsets::bIsSuperAirdrop);

								int count = rpm->read<int>(entityAddv + offsets::PickUpDataList + 0x4);
								if (count > 16)
									count = 16;

								AActor.boxItem.clear();
								DWORD PickUpItemData = rpm->read<DWORD>(entityAddv + offsets::PickUpDataList);
								if (PickUpItemData != 0)
								{
									for (int t = 0; t < count; t++)
									{
										std::string BoxItems = GnameType::GetBoxItems(rpm->read<int>(PickUpItemData + t * 0x30 + 0x4));
										if (BoxItems.find("tatti") == std::string::npos)
										{
											if (BoxItems != "")
												AActor.boxItem.push_back(BoxItems);
										}
									}
								}
								Inventorys.emplace_back(AActor);
							}
						}
					}
				}
			}
			else
			{
				IsInGame = false;
			}
		}


		EntityList = Players;

		EntityVehicle = Vehicles;

		EntityGrenade = Grenades;

		EntityGameState = GameStates;

		EntityRedZone = RedZone;

		EntityLoot = Loots;

		EntityInventory = Inventorys;

	
		std::this_thread::sleep_for(std::chrono::milliseconds(15));

	}

	
}

void OverlayThread()
{
	

	GL3Setup();

	Sleep(800);


	Globals::hwnd = FindWindow(0, "Gameloop");
	if (Globals::hwnd == 0)
	{
		std::cout << "Cant Find Window" << std::endl;
		return;
	}

	while (!glfwWindowShouldClose(Globals::g_window)) {
		mainLoop();
	}


}
std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}

bool KeyFile(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
std::string gMAC()
{
	PIP_ADAPTER_INFO AdapterInfo;
	DWORD dwBufLen = sizeof(IP_ADAPTER_INFO);
	char* mac_addr = (char*)malloc(18);

	AdapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
	if (AdapterInfo == NULL) {
		printf("Error allocating memory needed to call GetAdaptersinfo\n");
		free(mac_addr);
		return NULL; // it is safe to call free(NULL)
	}

	// Make an initial call to GetAdaptersInfo to get the necessary size into the dwBufLen variable
	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == ERROR_BUFFER_OVERFLOW) {
		free(AdapterInfo);
		AdapterInfo = (IP_ADAPTER_INFO*)malloc(dwBufLen);
		if (AdapterInfo == NULL) {
			printf("Error allocating memory needed to call GetAdaptersinfo\n");
			free(mac_addr);
			return NULL;
		}
	}

	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR) {
		// Contains pointer to current adapter info
		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
		do {
			// technically should look at pAdapterInfo->AddressLength
			//   and not assume it is 6.
			sprintf(mac_addr, "%02X:%02X:%02X:%02X:%02X:%02X",
				pAdapterInfo->Address[0], pAdapterInfo->Address[1],
				pAdapterInfo->Address[2], pAdapterInfo->Address[3],
				pAdapterInfo->Address[4], pAdapterInfo->Address[5]);
			//  printf("Address: %s, mac: %s\n", pAdapterInfo->IpAddressList.IpAddress.String, mac_addr);
			  // print them all, return the last one.
			  // return mac_addr;

			printf("\n");
			pAdapterInfo = pAdapterInfo->Next;
		} while (pAdapterInfo);
	}
	free(AdapterInfo);
	return mac_addr; // caller must free.
}

bool FixDriveBlockList()
{
	system("cls");
	bool isChange = false;

	RegKey VulnerableDriverBlocklist{ HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\CI\\Config" };
	if (VulnerableDriverBlocklist.IsValid()) {
		if (auto VulnerableDriverBlocklistEnable = VulnerableDriverBlocklist.TryGetDwordValue(L"VulnerableDriverBlocklistEnable"))
		{
			if (VulnerableDriverBlocklistEnable.GetValue() != 0)
			{
				VulnerableDriverBlocklist.SetDwordValue(L"VulnerableDriverBlocklistEnable", 0x0);
				isChange = true;
			}
		}
	}
	VulnerableDriverBlocklist.Close();

	RegKey DeviceGuard{ HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\DeviceGuard" };
	if (DeviceGuard.IsValid()) {

		if (auto EnableVirtualizationBasedSecurity = DeviceGuard.TryGetDwordValue(L"EnableVirtualizationBasedSecurity"))
		{
			if (EnableVirtualizationBasedSecurity.GetValue() != 0)
			{
				DeviceGuard.SetDwordValue(L"EnableVirtualizationBasedSecurity", 0x0);
				isChange = true;
			}

		}
		if (auto RequireMicrosoftSignedBootChain = DeviceGuard.TryGetDwordValue(L"RequireMicrosoftSignedBootChain"))
		{
			if (RequireMicrosoftSignedBootChain.GetValue() != 0)
			{
				DeviceGuard.SetDwordValue(L"RequireMicrosoftSignedBootChain", 0x0);
				isChange = true;
			}

		}

	}
	DeviceGuard.Close();

	RegKey DeviceGuard2{ HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\DeviceGuard\\Scenarios" };
	if (DeviceGuard2.IsValid())
	{
		if (DeviceGuard2.TrySetDwordValue(L"HypervisorEnforcedCodeIntegrity", 0x0).IsOk())
		{
			DeviceGuard2.SetDwordValue(L"HypervisorEnforcedCodeIntegrity", 0x0);
		}
	}
	DeviceGuard2.Close();

	if (isChange)
	{
		std::cout << xorstr_("Settings have been prepared and will be restarted after 10 seconds") << std::endl;
		Sleep(10 * 1000);
		system("shutdown /r");
		return false;
	}
	return true;
}
bool load_driver()
{

	auto expid = othermem::FindProcessId(decrypt("gzrnqtgt0gzg"));
	MoaRpm* ckrpm = new MoaRpm(expid, MoaRpm::MOA_MODE::KERNEL);
	if (ValidPointer(ckrpm->ImageBase())) {

		return true;
	}


	system("sc config vgc start= disabled & sc config vgk start= disabled & net stop vgc & net stop vgk & sc delete vgc & sc delete vgk & taskkill /IM vgtray.exe");
	bool free = false; //
	bool mdlMode = true;
	bool passAllocationPtr = false;

	HANDLE iqvw64e_device_handle = 0;

	if (intel_driver::IsRunning())
	{
		return false;
	}

	iqvw64e_device_handle = intel_driver::Load();
	std::vector<uint8_t> raw_image;
	for (size_t i = 0; i <= sizeof(Driver); i++)
	{
		raw_image.push_back(Driver[i]);
	}
	NTSTATUS exitCode = 0;
	if (!kdmapper::MapDriver(iqvw64e_device_handle, raw_image, 0, 0, free, true, mdlMode, passAllocationPtr, nullptr, &exitCode))
	{

		intel_driver::Unload(iqvw64e_device_handle);
		return false;

	}
	intel_driver::Unload(iqvw64e_device_handle);
	system("cls");
	Sleep(500);


	return true;


}

int main()
{



	std::thread(AntiDebug::AntiDebugLoop).detach();
	
	//othermem::killProcessByName(decrypt("CrrOctmgv0gzg").c_str());
	//othermem::killProcessByName(decrypt("CpftqkfGowncvqtGp0gzg").c_str());
	//othermem::killProcessByName(decrypt("CpftqkfGowncvqt0gzg").c_str());

	system(xorstr_("cls"));


	Globals::process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());


	if (!FixDriveBlockList())
	{
		std::cout << decrypt("EcpvaRtgrctcvkqpaEjgcv") << std::endl; //helpo
		Sleep(8000);
		exit(1);
	}
	if (!load_driver())
	{
		std::cout << decrypt("EcpvaNqcfaEjgcv") << std::endl;
		Sleep(8000);
		exit(1);
	}
	Sleep(2000);
	DWORD pid = GetCurrentProcessId();
	CreateDirectory(decrypt("0^Tgu").c_str(), NULL);

	if (1)
	{	

		std::cout << std::endl;


		std::cout << decrypt("YcvkpiaGowncvqtaQrgpg") << std::endl;
		while (othermem::getAowProcID() == NULL) { Sleep(500); }


		std::cout << decrypt("YcvkpiaIcogaQrgpgf") << std::endl;

	re:
		auto pID = othermem::getAowProcID();
		if (pID > 0)
		{

			rpm = new MoaRpm(pID, MoaRpm::MOA_MODE::KERNEL);
			DWORD libue4 = rpm->read<DWORD>(offsets::LibUe4);
			if (libue4 < 0x10000000)
				goto re;

			libs::UE4 = libue4;

			system("cls");
			CreateDirectory(decrypt("0^Tgu^Eqphki").c_str(), NULL);

			Utils::GuiFile = decrypt("0^Tgu^Eqphki^iwk0kpk");
			Utils::RefreshConfigs(decrypt("0^Tgu^Eqphki^,0kpk").c_str());
			GnameType::InitItemName();



			std::thread(Cache).detach();
			std::thread(Cache2).detach();
			std::thread(InitializeMagic).detach();
			std::thread(cam).detach();
			std::thread(Misc::Run).detach();
			std::thread(Aimbot::Run).detach();
			std::thread(OverlayThread).detach();

			
		}

	
		::ShowWindow(::GetConsoleWindow(), SW_HIDE);

		for (;;) {
			if (GetAsyncKeyState(VK_END)) {
				ImGui::SaveIniSettingsToDisk(decrypt("0^Tgu^Eqphki^iwk0kpk").c_str());

				if (Share::E_Magic == true)
				{
					RestoreHook();
				}
				Globals::isopened = false;
				FreeConsole();
				ExitProcess(1);
			}
			Sleep(500);
		}

	}
	else
	{
		Sleep(8000);
		exit(0);
	}


	return 0;
}

