#pragma once
namespace othermem
{
	int getAowProcID();
	void killProcessByName(LPCSTR name);
	int GetProcessIdByName(LPCTSTR szProcess);
	DWORD FindProcessId(const std::string& processName);
	int GetProcessThreadNumByID(DWORD dwPID);

}
