#include <Windows.h>
#include <Winternl.h>
#include <tlhelp32.h>
#include <vector>
#include <Memory>
#include <array>

#pragma comment(lib, "ntdll.lib")
#pragma warning(disable: 4996)
#define IOCTL_Imgui CTL_CODE(FILE_DEVICE_UNKNOWN, 0x909, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_HIDE_MEMORY CTL_CODE(FILE_DEVICE_UNKNOWN, 0x908, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_VIRTUAL_QUERY_MEMORY CTL_CODE(FILE_DEVICE_UNKNOWN, 0x907, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ALLOCATE_VIRUTAL_MEMORY CTL_CODE(FILE_DEVICE_UNKNOWN, 0x906, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PROTECT_VIRUTAL_MEMORY CTL_CODE(FILE_DEVICE_UNKNOWN, 0x905, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_GET_MODULE_BASE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x904, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_READ_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x903, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)
#define IOCTL_WRITE_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x902, METHOD_OUT_DIRECT, FILE_ANY_ACCESS)
#define IOCTL_BASE_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x901, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PEB_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x900, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define DRIVER_NAME L"\\\\.\\d905b673"

#define ValidPointer( pointer ) ( pointer != NULL && (DWORD_PTR)pointer >= 0x10000 && (DWORD_PTR)pointer < 0x00007FFFFFFEFFFF /*&& some other checks*/ )

typedef enum _MEMORY_INFORMATION_CLASS
{
	MemoryBasicInformation, // MEMORY_BASIC_INFORMATION
	MemoryWorkingSetInformation, // MEMORY_WORKING_SET_INFORMATION
	MemoryMappedFilenameInformation, // UNICODE_STRING
	MemoryRegionInformation, // MEMORY_REGION_INFORMATION
	MemoryWorkingSetExInformation, // MEMORY_WORKING_SET_EX_INFORMATION
	MemorySharedCommitInformation, // MEMORY_SHARED_COMMIT_INFORMATION
	MemoryImageInformation // MEMORY_IMAGE_INFORMATION
} MEMORY_INFORMATION_CLASS;
typedef struct _CLIENT_ID {
	HANDLE UniqueProcess;
	HANDLE UniqueThread;
} CLIENT_ID;
EXTERN_C NTSTATUS NTAPI NtReadVirtualMemory(HANDLE, PVOID, PVOID, ULONG, PULONG);
EXTERN_C NTSTATUS NTAPI NtWriteVirtualMemory(HANDLE, PVOID, PVOID, ULONG, PULONG);
EXTERN_C NTSTATUS NTAPI NtOpenProcess(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, CLIENT_ID);
EXTERN_C NTSTATUS NTAPI NtQueryVirtualMemory(HANDLE, PVOID, MEMORY_INFORMATION_CLASS, PVOID, SIZE_T, PSIZE_T);
EXTERN_C NTSTATUS NTAPI NtAllocateVirtualMemory(HANDLE, PVOID, ULONG_PTR, PSIZE_T, ULONG, ULONG);
EXTERN_C NTSTATUS NTAPI NtProtectVirtualMemory(HANDLE, PVOID, PSIZE_T, ULONG, PULONG);

#pragma comment(lib, "MoaRpm.lib")

class MoaRpm {
public:
	static enum MOA_MODE {
		 STANDARD,
		 NTDLL,
		 KERNEL
	};
private:
	DWORD pID;
	HANDLE hProcess;
	MOA_MODE mode = MOA_MODE::STANDARD;
	BOOL load_driver(std::string TargetDriver, std::string TargetServiceName, std::string TargetServiceDesc);

	BOOL delete_service(std::string TargetServiceName);
	std::string exePath();
	bool isElevated();

	bool isTestMode();

	void init(DWORD pID, MOA_MODE AccessMode);
	int InternalErrorHandler(unsigned int Code, struct _EXCEPTION_POINTERS* EP);
	int find(BYTE* buffer, int dwBufferSize, BYTE* bstr, DWORD dwStrLen);

public:
	MoaRpm(DWORD pID, MOA_MODE AccessMode);
	MoaRpm(const char* windowname, MOA_MODE AccessMode);
	~MoaRpm();
	void readRaw(LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesRead);
	void writeRaw(LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T *lpNumberOfBytesRead);
	uint64_t ModuleBase(std::string moduleToFind);
	uint64_t ImageBase();

	uint64_t KGetPeb();
	bool VirtualProtect(LPVOID address, size_t size, DWORD protect, PDWORD oldprotect);
	LPVOID VirtualAlloc(LPVOID address, size_t size, DWORD allocation_type, DWORD protect);
	size_t VirtualQuery(LPCVOID address, MEMORY_BASIC_INFORMATION* mbi, size_t size);

	bool search(BYTE* bSearchData, int nSearchSize, DWORD_PTR dwStartAddr, DWORD_PTR dwEndAddr, BOOL bIsCurrProcess, int iSearchMode, std::vector<DWORD_PTR>& vRet);
	std::uintptr_t FindSignature(const char* sig, const char* mask);

	template<class T>
	T PatternScan(const char* signature, int offset);

	template<typename T>
	bool read_array(uintptr_t address, T* array, size_t len);

	template <class cData>
	cData read(DWORD_PTR Address);

	template <class cData>
	bool write(DWORD_PTR Address, cData buffer);

	template <class vType>
	vType ReadPtr(std::initializer_list<DWORD_PTR> _Offsets, bool ReadFirstOffset);

	template <class vType>
	bool WritePtr(std::initializer_list<DWORD_PTR> _Offsets, vType _value, bool ReadFirstOffset);

	template<class CharT = char>
	std::basic_string<CharT> readString(DWORD_PTR address, size_t max_length = 256);
	std::string read_ascii(const std::uintptr_t address, std::size_t size);
	std::wstring read_unicode(const std::uintptr_t address, std::size_t size);
	uint64_t ReadChain(uint64_t base, const std::vector<uint64_t>& offsets);
	std::wstring ReadWstr( uintptr_t address);

};

template<typename T>
 bool MoaRpm::read_array( uintptr_t address, T* array, size_t len) {
	 if (ValidPointer(address))
	 this->readRaw(address, array, sizeof(T) * len, 0);
	 return true;
}

template <class cData>
cData MoaRpm::read(DWORD_PTR Address) {
	cData B;
	SIZE_T bytesRead;
	if (ValidPointer(Address))
	this->readRaw((LPCVOID)Address, &B, sizeof(B), &bytesRead);
	return B;
}

template <class cData>
bool MoaRpm::write(DWORD_PTR Address, cData buffer) {
	SIZE_T bytesRead;
	if (ValidPointer(Address))
	this->writeRaw((LPCVOID)Address, &buffer, sizeof(cData), &bytesRead);
	return true;
}

template <class vType>
vType MoaRpm::ReadPtr(std::initializer_list<DWORD_PTR> _Offsets, bool ReadFirstOffset)
{
	DWORD_PTR LastPtr = NULL;
	int OffsetsSize = NULL;
	std::vector<DWORD_PTR> Offsets = { NULL };
	Offsets = _Offsets;
	OffsetsSize = Offsets.size();
	LastPtr = this->read<DWORD_PTR>((ReadFirstOffset ? this->read<DWORD_PTR>(Offsets[0]) : Offsets[0]) + Offsets[1]);
	for (size_t i = 2; i < OffsetsSize - 1; i++)
		if (!(LastPtr = this->read<DWORD_PTR>(LastPtr + Offsets[i])))
			return vType();
	return this->read<vType>(LastPtr + Offsets[OffsetsSize - 1]);
}

template <class vType>
bool MoaRpm::WritePtr(std::initializer_list<DWORD_PTR> _Offsets, vType _value, bool ReadFirstOffset)
{
	DWORD_PTR LastPtr = NULL;
	int OffsetsSize = NULL;
	std::vector<DWORD_PTR> Offsets = { NULL };
	Offsets = _Offsets;
	OffsetsSize = Offsets.size();
	LastPtr = this->read<DWORD_PTR>((ReadFirstOffset ? this->read<DWORD_PTR>(Offsets[0]) : Offsets[0]) + Offsets[1]);
	for (size_t i = 2; i < OffsetsSize - 1; i++)
		if (!(LastPtr = this->read<DWORD_PTR>(LastPtr + Offsets[i])))
			return FALSE;
	return this->write<vType>(LastPtr + Offsets[OffsetsSize - 1], _value);
}

template<class CharT>
std::basic_string<CharT> MoaRpm::readString(DWORD_PTR address, size_t max_length)
{
	std::basic_string<CharT> str(max_length, CharT());
	SIZE_T bytesRead;
	if (ValidPointer(address))
	this->readRaw((LPVOID)address, &str[0], sizeof(CharT) * max_length, &bytesRead);
	auto it = str.find(CharT());
	if (it == str.npos) str.clear();
	else str.resize(it);
	return str;
}
extern MoaRpm* rpm;