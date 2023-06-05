#pragma once
#define GLFW_EXPOSE_NATIVE_WIN32
#pragma warning(disable : 4996)

/* Windows SDK */
#include <fstream>
#include <algorithm>
#include <functional>
#include <windows.h>
#include <locale>
#include <codecvt>
#include <cstdio>
#include <iostream>
#include <sstream>      // std::stringstream
#include <vector>
#include <array>
#include <cctype>
#include <chrono>
#include <memory>
#include <thread>
#include <map>
#include <mutex>
#include <process.h>
#include <TlHelp32.h>
#include <dwmapi.h>
#include <D3dx9math.h>
#include <ShlObj.h>
#include <iomanip>
#include <tchar.h>

#include <Iphlpapi.h>
#include <Assert.h>
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "dwmapi.lib")

/* Overlay */
#include "GL/glew.h"
#include "ImGui/imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "ImGui/imgui_internal.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "memoryfonts.h"
#include "memoryicons.h"
#include "GL3.h"
#include "ui.h"

#include "Vector.h"
#include "math.h"



#include "structs.h"
#include "Globals.h"
#include "Settings.h"
#include "utils.h"
#include "Render.h"
#include "xor.hpp"
#include "CSX_Cvar.h"
#include "FarsiType.h"


#include "driver.h"
#include "kdmapper/kdmapper.hpp"
#include "kRpm.h"
#include "OtherMemory.h"


#include "Offsets.h"
#include "GnameType.h"
#include "SDK.h"

#include "Aimbot.h"
#include "Visuals.h"
#include "Misc.h"

#include "Configuration.hpp"
#include "Menu.h"



#include "Dots.h"
#include "Watermark.h"



#include "WinReg.hpp"




using namespace std;
using std::pair;
using std::vector;
using std::wcout;
using std::wstring;

using winreg::RegKey;
using winreg::RegException;
using winreg::RegExpected;

#define checkSetting(teamval, enemyval) (((gm.LocalPlayer.Team == player.Team) && teamval) || ((gm.LocalPlayer.Team != player.Team) && enemyval))
#define pasteColor(x) x.r, x.g, x.b
#define pasteColorA(x) x.r, x.g, x.b, x.a
#define IM_PI                   3.14159265358979323846f
#define RAD2DEG( x )  ( (float)(x) * (float)(180.f / IM_PI) )
#define DEG2RAD( x ) ( (float)(x) * (float)(IM_PI / 180.f) )

#include "defs.h"
