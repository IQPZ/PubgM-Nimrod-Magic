#pragma once
namespace Config {
	void LoadSettings(std::string szIniFile);
	void SaveSettings(std::string szIniFile);
	bool ScanColorFromCvar(const char* str, float* colors);
}

