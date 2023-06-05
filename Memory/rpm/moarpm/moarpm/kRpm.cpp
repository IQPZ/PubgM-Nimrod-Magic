#include "xor.hpp"
#include "kRpm.h"



HANDLE NtOpenProcessZILZAL(DWORD dwDesiredAccess, DWORD dwProcessId)
{
	CLIENT_ID cid = { (HANDLE)dwProcessId, NULL };
	OBJECT_ATTRIBUTES oa;
	InitializeObjectAttributes(&oa, 0, 0, 0, 0);
	HANDLE hProcess = NULL;
	NTSTATUS ntStatus = NtOpenProcess(&hProcess, dwDesiredAccess, &oa, cid);
	SetLastError(ntStatus);
	return hProcess;
}

BOOL MoaRpm::load_driver(std::string TargetDriver, std::string TargetServiceName, std::string TargetServiceDesc)
{
	SC_HANDLE ServiceManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
	if (!ServiceManager) return FALSE;
	SC_HANDLE ServiceHandle = CreateService(ServiceManager, TargetServiceName.c_str(), TargetServiceDesc.c_str(), SERVICE_START | DELETE | SERVICE_STOP, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE, TargetDriver.c_str(), NULL, NULL, NULL, NULL, NULL);
	if (!ServiceHandle)
	{
		ServiceHandle = OpenService(ServiceManager, TargetServiceName.c_str(), SERVICE_START | DELETE | SERVICE_STOP);
		if (!ServiceHandle) return FALSE;
	}
	if (!StartServiceA(ServiceHandle, NULL, NULL)) return FALSE;
	CloseServiceHandle(ServiceHandle);
	CloseServiceHandle(ServiceManager);
	return TRUE;
}

BOOL MoaRpm::delete_service(std::string TargetServiceName)
{
	SERVICE_STATUS ServiceStatus;
	SC_HANDLE ServiceManager = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
	if (!ServiceManager) return FALSE;
	SC_HANDLE ServiceHandle = OpenService(ServiceManager, TargetServiceName.c_str(), SERVICE_STOP | DELETE);
	if (!ServiceHandle) return FALSE;
	if (!ControlService(ServiceHandle, SERVICE_CONTROL_STOP, &ServiceStatus)) return FALSE;
	if (!DeleteService(ServiceHandle)) return FALSE;
	CloseServiceHandle(ServiceHandle);
	CloseServiceHandle(ServiceManager);
	return TRUE;
}

std::string MoaRpm::exePath() {
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}

bool MoaRpm::isElevated() {
	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if (hToken) {
		CloseHandle(hToken);
	}
	return fRet;
}

bool MoaRpm::isTestMode() {
	typedef NTSTATUS(__stdcall* td_NtQuerySystemInformation)(
		ULONG           SystemInformationClass,
		PVOID           SystemInformation,
		ULONG           SystemInformationLength,
		PULONG          ReturnLength
		);

	struct SYSTEM_CODEINTEGRITY_INFORMATION {
		ULONG Length;
		ULONG CodeIntegrityOptions;
	};

	static td_NtQuerySystemInformation NtQuerySystemInformation = (td_NtQuerySystemInformation)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtQuerySystemInformation");

	SYSTEM_CODEINTEGRITY_INFORMATION Integrity = { sizeof(SYSTEM_CODEINTEGRITY_INFORMATION), 0 };
	NTSTATUS status = NtQuerySystemInformation(103, &Integrity, sizeof(Integrity), NULL);

	return (NT_SUCCESS(status) && (Integrity.CodeIntegrityOptions & 1));
}

void MoaRpm::init(DWORD pID, MOA_MODE AccessMode) {
	this->pID = pID;
	this->mode = AccessMode;
	if (this->mode == MOA_MODE::STANDARD) {
	//	this->hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, pID);
	}
	if (this->mode == MOA_MODE::NTDLL) {
	//	this->hProcess = NtOpenProcessZILZAL(PROCESS_ALL_ACCESS, pID);
	}
	if (this->mode == MOA_MODE::KERNEL) {
		if (!this->isElevated()) {
			MessageBox(NULL, xorstr_("Must be running as admin for kernel mode stuff"), xorstr_("Fatal Error"), MB_OK);
			exit(1);
		}
		if (!this->isTestMode()) {
			MessageBox(NULL, xorstr_("Must have testing mode enabled to load unsigned driver"), xorstr_("Fatal Error"), MB_OK);
			exit(1);
		}
		//this->load_driver(exePath() + "\\kRpm.sys", "kRpm", "Kernel level readprocessmemory and writeprocessmemory");
	}

}

int MoaRpm::InternalErrorHandler(unsigned int Code, struct _EXCEPTION_POINTERS* EP)
{
	return (Code == EXCEPTION_ACCESS_VIOLATION) ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH;
}
int MoaRpm::find(BYTE* buffer, int dwBufferSize, BYTE* bstr, DWORD dwStrLen) {
	if (dwBufferSize < 0) {
		return -1;
	}
	DWORD  i, j;
	for (i = 0; i < dwBufferSize; i++) {
		for (j = 0; j < dwStrLen; j++) {
			if (buffer[i + j] != bstr[j] && bstr[j] != '?')
				break;
		}
		if (j == dwStrLen)
			return i;
	}
	return -1;
}

MoaRpm::MoaRpm(DWORD pID, MOA_MODE AccessMode) {
	this->init(pID, AccessMode);
}

MoaRpm::MoaRpm(const char* windowname, MOA_MODE AccessMode) {
	HWND targetWindow =FindWindowA(NULL, windowname);
	CloseHandle(targetWindow);
	//if (!targetWindow) printf("target window not found");
	GetWindowThreadProcessId(targetWindow, &this->pID);
	//printf("Target PID:%d\n", this->pID);
	this->init(pID, AccessMode);
}

MoaRpm::~MoaRpm() {
	if (this->mode == MOA_MODE::KERNEL) {
		this->delete_service(xorstr_("ZakariaMaster"));
	}
	else {
		CloseHandle(this->hProcess);
	}
}

void MoaRpm::readRaw(LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesRead) {
	if (this->mode == MOA_MODE::STANDARD) {
		ReadProcessMemory(this->hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead);
	}
	if (this->mode == MOA_MODE::NTDLL) {
		NtReadVirtualMemory(this->hProcess, (PVOID)lpBaseAddress, lpBuffer, nSize, (PULONG)lpNumberOfBytesRead);
	}
	if (this->mode == MOA_MODE::KERNEL) {
		struct Rpmdata
		{
			ULONG pid;
			ULONGLONG SourceAddress;
			SIZE_T Size;
		} rpm;
		rpm.pid = pID;
		rpm.SourceAddress = (ULONGLONG)lpBaseAddress;
		rpm.Size = nSize;

		rpm.pid ^= 0x8fea0644;
		rpm.SourceAddress ^= 0xfcb3e314;
		rpm.Size ^= 0x544becbe;

		HANDLE hDevice = INVALID_HANDLE_VALUE;
		BOOL bResult = FALSE;
		DWORD junk = 0;
		hDevice = CreateFileW(xorstr_(DRIVER_NAME), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);            // do not copy file attributes
		if (hDevice != INVALID_HANDLE_VALUE) {
			bResult = DeviceIoControl(hDevice, IOCTL_READ_MEM, &rpm, sizeof(rpm), lpBuffer, nSize, &junk, (LPOVERLAPPED)NULL);
			CloseHandle(hDevice);
		}
	}
}

void MoaRpm::writeRaw(LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesRead) {
	if (this->mode == MOA_MODE::STANDARD) {
		WriteProcessMemory(this->hProcess, (PVOID)lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead);
	}
	if (this->mode == MOA_MODE::NTDLL) {
		NtWriteVirtualMemory(this->hProcess, (PVOID)lpBaseAddress, lpBuffer, nSize, (PULONG)lpNumberOfBytesRead);
	}
	if (this->mode == MOA_MODE::KERNEL) {
		struct Rpmdata
		{
			ULONG pid;
			ULONGLONG SourceAddress;
			SIZE_T Size;
		} rpm;
		rpm.pid = pID;
		rpm.SourceAddress = (ULONGLONG)lpBaseAddress;
		rpm.Size = nSize;

		rpm.pid ^= 0x8fea0644;
		rpm.SourceAddress ^= 0xfcb3e314;
		rpm.Size ^= 0x544becbe;

		HANDLE hDevice = INVALID_HANDLE_VALUE;
		BOOL bResult = FALSE;
		DWORD junk = 0;
		hDevice = CreateFileW(xorstr_(DRIVER_NAME), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);            // do not copy file attributes
		if (hDevice != INVALID_HANDLE_VALUE) {
			bResult = DeviceIoControl(hDevice, IOCTL_WRITE_MEM, &rpm, sizeof(rpm), lpBuffer, nSize, &junk, (LPOVERLAPPED)NULL);
			CloseHandle(hDevice);
		}
	}
}
uint64_t MoaRpm::ModuleBase(std::string moduleToFind) {
	if (this->mode == MOA_MODE::KERNEL)
	{
		struct Rpmdata
		{
			ULONG pid;
			ULONGLONG Base;
			WCHAR name[260];
		} rpm;
		rpm.pid = pID;
		std::wstring wstr{ std::wstring(moduleToFind.begin(), moduleToFind.end()) };
		memset(rpm.name, 0, sizeof(WCHAR) * 260);
		wcscpy(rpm.name, wstr.c_str());

		HANDLE hDevice = INVALID_HANDLE_VALUE;
		BOOL bResult = FALSE;
		DWORD junk = 0;
		hDevice = CreateFileW(xorstr_(DRIVER_NAME), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		if (hDevice != INVALID_HANDLE_VALUE) {
			bResult = DeviceIoControl(hDevice, IOCTL_GET_MODULE_BASE, &rpm, sizeof(rpm), &rpm, sizeof rpm, &junk, (LPOVERLAPPED)NULL);
			CloseHandle(hDevice);
			return rpm.Base;
		}

	}
	if (this->mode == MOA_MODE::STANDARD || this->mode == MOA_MODE::NTDLL)
	{
		MODULEENTRY32 module_entry{};
		module_entry.dwSize = sizeof(MODULEENTRY32);
		auto snapshot{ CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, this->pID) };
		if (snapshot == INVALID_HANDLE_VALUE)
			return false;
		if (Module32First(snapshot, &module_entry)) {
			do {
				if (!_stricmp(module_entry.szModule, moduleToFind.c_str())) {
					CloseHandle(snapshot);
					return (uint64_t)module_entry.hModule;
				}
				module_entry.dwSize = sizeof(MODULEENTRY32);
			} while (Module32Next(snapshot, &module_entry));
		}
		CloseHandle(snapshot);
		return NULL;
	}
	return NULL;
}
uint64_t MoaRpm::ImageBase()
{

	if (this->mode == MOA_MODE::KERNEL)
	{
		struct Rpmdata
		{
			ULONG pid;
			ULONGLONG Base;
		} rpm;
		rpm.pid = pID;

		HANDLE hDevice = INVALID_HANDLE_VALUE;
		BOOL bResult = FALSE;
		DWORD junk = 0;
		hDevice = CreateFileW(xorstr_(DRIVER_NAME), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		if (hDevice != INVALID_HANDLE_VALUE) {
			bResult = DeviceIoControl(hDevice, IOCTL_BASE_MEM, &rpm, sizeof(rpm), &rpm, sizeof rpm, &junk, (LPOVERLAPPED)NULL);
			CloseHandle(hDevice);
			return rpm.Base;
		}
	}
	if (this->mode == MOA_MODE::STANDARD || this->mode == MOA_MODE::NTDLL)
	{
		HANDLE snapshotModules = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, this->pID);
		if (snapshotModules == INVALID_HANDLE_VALUE)
			return NULL;

		MODULEENTRY32 me32;
		me32.dwSize = sizeof(MODULEENTRY32); // Set the size of the structure before using it.
		if (!Module32First(snapshotModules, &me32)) {
			CloseHandle(snapshotModules);
			return 0x0;
		}
		return (uint64_t)me32.modBaseAddr;
	}

	return NULL;
}

uint64_t MoaRpm::KGetPeb() {
	struct Rpmdata
	{
		ULONG pid;
		ULONGLONG Base;
	} rpm;
	rpm.pid = pID;

	HANDLE hDevice = INVALID_HANDLE_VALUE;
	BOOL bResult = FALSE;
	DWORD junk = 0;
	hDevice = CreateFileW(xorstr_(DRIVER_NAME), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (hDevice != INVALID_HANDLE_VALUE) {
		bResult = DeviceIoControl(hDevice, IOCTL_PEB_MEM, &rpm, sizeof(rpm), &rpm, sizeof rpm, &junk, (LPOVERLAPPED)NULL);
		CloseHandle(hDevice);
		return rpm.Base;
	}
	return NULL;
}
bool MoaRpm::VirtualProtect(LPVOID address, size_t size, DWORD protect, PDWORD oldprotect)
{
	if (this->mode == MOA_MODE::STANDARD)
	{
		VirtualProtectEx(this->hProcess, (LPVOID)address, size, protect, oldprotect);
		return oldprotect;

	}
	if (this->mode == MOA_MODE::NTDLL)
	{
		NtProtectVirtualMemory(this->hProcess, address, &size, protect, oldprotect);
	}
	if (this->mode == MOA_MODE::KERNEL)
	{
		struct Rpmdata
		{
			ULONG pid;
			ULONGLONG Address;
			SIZE_T Size;
			ULONG Protect;
		} rpm;
		rpm.pid = pID;
		rpm.Address = (ULONGLONG)address;
		rpm.Size = size;
		rpm.Protect = protect;

		HANDLE hDevice = INVALID_HANDLE_VALUE;
		BOOL bResult = FALSE;
		DWORD junk = 0;
		hDevice = CreateFileW(xorstr_(DRIVER_NAME), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		if (hDevice != INVALID_HANDLE_VALUE) {
			bResult = DeviceIoControl(hDevice, IOCTL_PROTECT_VIRUTAL_MEMORY, &rpm, sizeof(rpm), &rpm, sizeof rpm, &junk, (LPOVERLAPPED)NULL);
			CloseHandle(hDevice);
			memcpy(&oldprotect, &rpm.Protect, sizeof(rpm.Protect));

			return bResult;
		}

	}
	return NULL;
}
LPVOID MoaRpm::VirtualAlloc(LPVOID address,size_t size, DWORD allocation_type, DWORD protect)
{
	if (this->mode == MOA_MODE::STANDARD)
	{
		return VirtualAllocEx(this->hProcess, (void*)address, size, allocation_type, protect);
	}
	if (this->mode == MOA_MODE::NTDLL)
	{
		NtAllocateVirtualMemory(this->hProcess, address, 0, &size, allocation_type, protect);
	}
	if (this->mode == MOA_MODE::KERNEL)
	{
		struct Rpmdata
		{
			ULONG pid;
			ULONGLONG Address;
			SIZE_T Size;
			ULONG Type;
			ULONG Protect;
		} rpm;
		rpm.pid = pID;
		rpm.Address = (ULONGLONG)address;
		rpm.Size = size;
		rpm.Type = MEM_COMMIT | MEM_RESERVE;
		rpm.Protect = protect;


		HANDLE hDevice = INVALID_HANDLE_VALUE;
		BOOL bResult = FALSE;
		DWORD junk = 0;
		hDevice = CreateFileW(xorstr_(DRIVER_NAME), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		if (hDevice != INVALID_HANDLE_VALUE) {
			bResult = DeviceIoControl(hDevice, IOCTL_ALLOCATE_VIRUTAL_MEMORY, &rpm, sizeof(rpm), &rpm, sizeof rpm, &junk, (LPOVERLAPPED)NULL);
			CloseHandle(hDevice);
			return (LPVOID)(rpm.Address);
		}
	}

	return NULL;
}


size_t MoaRpm::VirtualQuery(LPCVOID address, MEMORY_BASIC_INFORMATION* mbi, size_t size)
{
	if (this->mode == MOA_MODE::STANDARD)
	{
		return VirtualQueryEx(hProcess, address, mbi, size);
	}
	if (this->mode == MOA_MODE::NTDLL)
	{
		return NtQueryVirtualMemory(hProcess, (PVOID)address, MEMORY_INFORMATION_CLASS::MemoryBasicInformation, &mbi, sizeof(mbi), (PSIZE_T)size);
	}
	if (this->mode == MOA_MODE::KERNEL)
	{
		struct Rpmdata
		{
			ULONG pid;
			ULONGLONG Address;
			MEMORY_BASIC_INFORMATION* MBI;
			SIZE_T  Size;
		} rpm;
		rpm.pid = pID;
		rpm.Address = (ULONGLONG)address;
		rpm.MBI = mbi;
		rpm.Size = size;

		HANDLE hDevice = INVALID_HANDLE_VALUE;
		BOOL bResult = FALSE;
		DWORD junk = 0;
		hDevice = CreateFileW(xorstr_(DRIVER_NAME), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		if (hDevice != INVALID_HANDLE_VALUE) {
			bResult = DeviceIoControl(hDevice, IOCTL_VIRTUAL_QUERY_MEMORY, &rpm, sizeof(rpm), &rpm, sizeof rpm, &junk, (LPOVERLAPPED)NULL);
			CloseHandle(hDevice);
			memcpy(mbi, rpm.MBI, sizeof(rpm.MBI));
			memcpy(&address, &rpm.Address, sizeof(rpm.Address));

			return rpm.Size;
		}
	}

	return NULL;
}

bool MoaRpm::search(BYTE* bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, BOOL bIsCurrProcess, int iSearchMode, std::vector<DWORD_PTR>& vRet) {

	typedef struct _MEMORY_REGION
	{
		DWORD_PTR dwBaseAddr;
		DWORD_PTR dwMemorySize;
	}MEMORY_REGION;

	MEMORY_BASIC_INFORMATION	mbi = {0};
	mbi.RegionSize = 0x400;

	SIZE_T bytesRead;
	std::vector<MEMORY_REGION> m_vMemoryRegion = {};
	DWORD dwAddress = dwStartAddr;

	MEMORY_REGION memSectorList[1000];

	int memSectorIndex = 0;
	
	while (VirtualQuery((LPCVOID)dwAddress, &mbi, sizeof(mbi)) && (dwAddress < dwEndAddr) && ((dwAddress + mbi.RegionSize) > dwAddress)) {
		if (
			(mbi.State == MEM_COMMIT) &&
			((mbi.Protect & PAGE_GUARD) == 0) &&
			(mbi.Protect != PAGE_NOACCESS) &&
			((mbi.AllocationProtect & PAGE_NOCACHE) != PAGE_NOCACHE)
			) {
			MEMORY_REGION mData = { 0 };
			mData.dwBaseAddr = (DWORD_PTR)mbi.BaseAddress;
			mData.dwMemorySize = mbi.RegionSize;
			m_vMemoryRegion.push_back(mData);
			memSectorList[memSectorIndex] = mData;
			memSectorIndex++;
		}
		dwAddress = (DWORD)mbi.BaseAddress + mbi.RegionSize;
	}
	std::vector<MEMORY_REGION>::iterator it;
	int memSectorCount = memSectorIndex;
	memSectorIndex = 0;
	DWORD_PTR curAddr = dwStartAddr;
	while (curAddr < dwEndAddr) {
		VirtualQuery((LPCVOID)curAddr, &mbi,sizeof(mbi));
		long regionSizeOrg = mbi.RegionSize;
		long regionSize = mbi.RegionSize;
		if (regionSize > 10) {
			BYTE* pCurrMemoryData = new BYTE[regionSize];
			ZeroMemory(pCurrMemoryData, regionSize);
			this->readRaw((PVOID)curAddr, (PVOID*)pCurrMemoryData, regionSize, &bytesRead);
			DWORD_PTR dwOffset = 0;
			int iOffset = find(pCurrMemoryData, regionSize, bSearchData, nSearchSize);
			while (iOffset != -1) {
				dwOffset += iOffset;
				vRet.push_back(dwOffset + curAddr);
				dwOffset += nSearchSize;
				iOffset = find(pCurrMemoryData + dwOffset, regionSize - dwOffset - nSearchSize, bSearchData, nSearchSize);
			}
			delete[] pCurrMemoryData;
		}
		memSectorIndex++;
		curAddr = curAddr + (DWORD_PTR)regionSizeOrg;
		continue;
	}
	return TRUE;
}
std::uintptr_t MoaRpm::FindSignature(const char* sig, const char* mask)
{
	auto buffer = std::make_unique<std::array<std::uint8_t, 0x100000>>();
	auto data = buffer.get()->data();
	uint64_t ImageBase = this->ImageBase();
	for (std::uintptr_t i = 0u; i < (2u << 25u); ++i)
	{
		this->readRaw((LPCVOID)(ImageBase + i * 0x100000), data, 0x100000,0);

		if (!data)
			return 0;

		for (std::uintptr_t j = 0; j < 0x100000u; ++j)
		{
			if ([](std::uint8_t const* data, std::uint8_t const* sig, char const* mask)
				{
					for (; *mask; ++mask, ++data, ++sig)
					{
						if (*mask == 'x' && *data != *sig) return false;
					}
					return (*mask) == 0;
				}(data + j, (std::uint8_t*)sig, mask))
			{
				std::uintptr_t result = ImageBase + i * 0x100000 + j;
				std::uint32_t rel = 0;

				this->readRaw((LPCVOID)(result + 3), &rel, sizeof(std::uint32_t),0);

				if (!rel)
					return 0;

				return result + rel + 7;
			}
		}
	}

	return 0;
}

template<class T>
T MoaRpm::PatternScan(const char* signature, int offset) {
	uint64_t ImageBase = this->ImageBase();
	int instructionLength = offset + sizeof(T);
	IMAGE_DOS_HEADER dos_header = this->read<IMAGE_DOS_HEADER>(ImageBase);
	IMAGE_NT_HEADERS64 nt_headers = this->read<IMAGE_NT_HEADERS64>(ImageBase + dos_header.e_lfanew);

	const size_t target_len = nt_headers.OptionalHeader.SizeOfImage;

	static auto patternToByte = [](const char* pattern)
	{
		auto bytes = std::vector<int>{};
		const auto start = const_cast<char*>(pattern);
		const auto end = const_cast<char*>(pattern) + strlen(pattern);

		for (auto current = start; current < end; ++current)
		{
			if (*current == '?')
			{
				++current;
				bytes.push_back(-1);
			}
			else { bytes.push_back(strtoul(current, &current, 16)); }
		}
		return bytes;
	};

	auto patternBytes = patternToByte(signature);
	const auto s = patternBytes.size();
	const auto d = patternBytes.data();

	auto target = std::unique_ptr<uint8_t[]>(new uint8_t[target_len]);
	if (read_array(ImageBase, target.get(), target_len)) {
		for (auto i = 0ul; i < nt_headers.OptionalHeader.SizeOfImage - s; ++i)
		{
			bool found = true;
			for (auto j = 0ul; j < s; ++j)
			{
				if (target[static_cast<size_t>(i) + j] != d[j] && d[j] != -1)
				{
					found = false;
					break;
				}
			}
			if (found) {
				return this->read<T>( ImageBase + i + offset) + i + instructionLength;
			}
		}
	}

	return NULL;
}

std::string MoaRpm::read_ascii(const std::uintptr_t address, std::size_t size)
{
	std::unique_ptr<char[]> buffer(new char[size]);
	this->readRaw((LPVOID)address, buffer.get(), size, 0);
	return std::string(buffer.get());
}
std::wstring MoaRpm::read_unicode(const std::uintptr_t address, std::size_t size)
{
	const auto buffer = std::make_unique<wchar_t[]>(size);
	this->readRaw((LPCVOID)address, buffer.get(), size * 2, 0);
	return std::wstring(buffer.get());
}
uint64_t MoaRpm::ReadChain(uint64_t base, const std::vector<uint64_t>& offsets) {
	uint64_t result = read<uint64_t>(base + offsets.at(0));
	for (int i = 1; i < offsets.size(); i++) {
		result = read<uint64_t>(result + offsets.at(i));
	}
	return result;
}
std::wstring MoaRpm::ReadWstr(uintptr_t address)
{
	wchar_t buffer[1024 * sizeof(wchar_t)];
	this->readRaw((LPCVOID)address, &buffer, 64 * sizeof(wchar_t),0);
	return std::wstring(buffer);
}