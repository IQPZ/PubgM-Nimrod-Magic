#pragma once
class Inputs {
private:
	static DWORD SendScanCode(WORD scan, BOOL up)
	{
		INPUT inp = { 0 };
		inp.type = INPUT_KEYBOARD;
		inp.ki.wScan = scan;
		inp.ki.dwFlags = KEYEVENTF_SCANCODE | (up ? KEYEVENTF_KEYUP : 0);
		return SendInput(1, &inp, sizeof(inp)) ? NO_ERROR : GetLastError();
	}
public:
	static bool mouse_move(int x, int y)
	{
		INPUT input;
		input.type = INPUT_MOUSE;
		input.mi.mouseData = 0;
		input.mi.time = 0;
		input.mi.dx = x;
		input.mi.dy = y;
		input.mi.dwFlags = MOUSEEVENTF_MOVE;
		SendInput(1, &input, sizeof(input));
		return true;
	}
	static DWORD SendVirtualKey(UINT vk, BOOL up)
	{
		UINT scan = MapVirtualKey(vk, MAPVK_VK_TO_VSC);
		return scan ? SendScanCode(scan, up) : ERROR_NO_UNICODE_TRANSLATION;
	}
	bool static keydown(int key)
	{
		return (GetAsyncKeyState(key) & 0x8000) != 0;
	}
};

static class Text
{
public:
	ImFont* font;
	std::string text;
	int side;
	int size;
	D3DXCOLOR color;
	Text(ImFont* font, std::string text, int side, int size, D3DXCOLOR color) : font(font), text(text), side(side), size(size), color(color) {}
};
namespace Utils
{
	std::vector<std::string> Get_Dir_Files(std::string folder);
	const std::string gen_random(const int len);
	FVector AimbotCorrection(float bulletVelocity, FVector LocalPose, FVector targetPosition, FVector targetVelocity);
		std::string replaceFirstOccurrence(
		std::string& s,
		const std::string& toReplace,
		const std::string& replaceWith);
	void VectorAnglesRadar(FVector& forward, FVector& angles);
	void RotateTriangle(std::array<FVector, 3>& points, float rotation);
	FVector2D WorldToRadar(FRotator Rotation, FVector CameraLocation, FVector Origin, FVector2D RadarPosition, FVector2D RadarSize);
	bool keydown(int key);
	void AimAtPosV2(int screenwidth, int screenheight, float x, float y, float speed, float humanspeed, float humanscale);
		double GetCrossDistance(double x1, double y1, double x2, double y2);
	int get_fps();
	extern	std::vector<std::string> ConfigList;
	extern std::string GuiFile;

	void RefreshConfigs(std::string file);
	void ReadConfigs(LPCTSTR lpszFileName);

}