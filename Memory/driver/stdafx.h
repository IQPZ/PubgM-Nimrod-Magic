#pragma once
#include "definitions.h"

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

#define drv_device L"\\Device\\d905b673"
#define drv_dos_device L"\\DosDevices\\d905b673"
#define drv  L"\\Driver\\d905b673"

#define ValidPointer( pointer ) ( pointer != NULL && (DWORD_PTR)pointer >= 0x10000 && (DWORD_PTR)pointer < 0x00007FFFFFFEFFFF /*&& some other checks*/ )
typedef struct rw_t {
	ULONG PID;
	ULONGLONG Addr;
	SIZE_T Bytes;
} k_rw, *p_rw;
typedef struct imagebase_t {
	ULONG PID;
	ULONGLONG Base;
} k_imagebase, * p_imagebase;
typedef struct pebbase_t {
	ULONG PID;
	ULONGLONG Base;
} k_pebbase, * p_pebbase;
typedef struct modulehandle_t {
	ULONG PID;
	ULONGLONG Base;
	WCHAR name[260];
} k_modulehandle, * p_modulehandle;
typedef struct protectvirutal_t {
	ULONG PID;
	ULONGLONG address;
	SIZE_T size;
	ULONG protect;
} k_protectvirutal, * p_protectvirutal;
typedef struct allocation_t {
	ULONG PID;
	ULONGLONG address;
	SIZE_T size;
	ULONG type;
	ULONG protect;
} k_allocation, * p_allocation;
typedef struct _REQUEST_QUERY {
	ULONG PID;
	ULONGLONG address;
	MEMORY_BASIC_INFORMATION* MBI;
	SIZE_T  size;
} REQUEST_QUERY, * PREQUEST_QUERY;
typedef struct hide_t {
	ULONG PID;
	ULONG result;
} k_hide, * p_hide;
typedef struct Imgui_t {
	ULONG PID;
	ULONG name;
} k_Imgui, * p_Imgui;
