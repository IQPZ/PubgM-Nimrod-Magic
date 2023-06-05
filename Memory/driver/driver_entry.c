#include "stdafx.h"

PDEVICE_OBJECT driver_object;
UNICODE_STRING dev, dos;


NTSTATUS unload_driver(PDRIVER_OBJECT driver) {
	IoDeleteSymbolicLink(&dos);
	IoDeleteDevice(driver->DeviceObject);
}
NTSTATUS ioctl_create(PDEVICE_OBJECT device, PIRP irp) {
	irp->IoStatus.Status = STATUS_SUCCESS;
	irp->IoStatus.Information = 0;
	IoCompleteRequest(irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}
NTSTATUS ioctl_close(PDEVICE_OBJECT device, PIRP irp) {
	irp->IoStatus.Status = STATUS_SUCCESS;
	irp->IoStatus.Information = 0;
	IoCompleteRequest(irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

DWORD GetHandleTableOffset()
{
	
	RTL_OSVERSIONINFOW ver = { 0 };
	RtlGetVersion(&ver);

	switch (ver.dwBuildNumber)
	{
	case WINDOWS_1803:
		return 0x418;
		break;
	case WINDOWS_1809:
		return 0x418;
		break;
	case WINDOWS_1903:
		return 0x418;
		break;
	case WINDOWS_1909:
		return 0x418;
		break;
	case WINDOWS_2004:
		return 0x570;
		break;
	case WINDOWS_20H2:
		return 0x570;
		break;
	case WINDOWS_21H1:
		return 0x570;
		break;
	default:
		return 0x570;
	}
	
}
DWORD GetActiveProcessLinks()
{
	
	RTL_OSVERSIONINFOW ver = { 0 };
	RtlGetVersion(&ver);

	switch (ver.dwBuildNumber)
	{
	case WINDOWS_1803:
		return 0x2e8;
		break;
	case WINDOWS_1809:
		return 0x2e8;
		break;
	case WINDOWS_1903:
		return 0x2f0;
		break;
	case WINDOWS_1909:
		return 0x2f0;
		break;
	case WINDOWS_2004:
		return 0x448;
		break;
	case WINDOWS_20H2:
		return 0x448;
		break;
	case WINDOWS_21H1:
		return 0x448;
		break;
	default:
		return 0x448;
	}
	
}
NTSTATUS HideProcessByProcessId(HANDLE ProcessId)
{
	POBJECT_HEADER ObjectHeader = NULL;
	ULONG HandleTableOffset = GetHandleTableOffset(); //struct _HANDLE_TABLE* ObjectTable;

	ULONG     ActiveProcessLinksOffset = GetActiveProcessLinks();
	PEPROCESS Process = NULL;
	NTSTATUS  status = STATUS_SUCCESS;

	if (!ActiveProcessLinksOffset) {
		return STATUS_UNSUCCESSFUL;
	}

	KeEnterCriticalRegion();
	status = PsLookupProcessByProcessId(ProcessId, &Process);
	if (!NT_SUCCESS(status))
	{
		return STATUS_UNSUCCESSFUL;
	}


	ObjectHeader = (POBJECT_HEADER)((ULONG64)Process - 0x30);

	ObjectHeader->KernelOnlyAccess = 1;
	ObjectHeader->DefaultSecurityQuota = 1;

	//RemoveEntryList((PLIST_ENTRY)((PUCHAR)Process + ActiveProcessLinksOffset));
	//InitializeListHead((PLIST_ENTRY)((PUCHAR)Process + ActiveProcessLinksOffset));  //SelfConnected

	//PHANDLE_TABLE ObjectTable = *(PHANDLE_TABLE*)((PUCHAR)Process + HandleTableOffset);
	//PLIST_ENTRY HandleTableListAddress = &ObjectTable->HandleTableList;
	//RemoveEntryList(HandleTableListAddress);
	//InitializeListHead(HandleTableListAddress);
//	ObjectTable->UniqueProcessId = NULL;
	ObDereferenceObject(Process);
	KeLeaveCriticalRegion();
	return status;
}
PVOID GetImageBase(HANDLE PID)
{
	

	PEPROCESS Process;
	PVOID BaseAddress = NULL;
	if (NT_SUCCESS(PsLookupProcessByProcessId(PID, &Process)))
	{

		BaseAddress = (PVOID)PsGetProcessSectionBaseAddress(Process);

	}
	

	return BaseAddress;

}
PVOID GetProcessPeb(HANDLE PID)
{
	

	PEPROCESS process;
	PVOID BaseAddress = NULL;
	if (NT_SUCCESS(PsLookupProcessByProcessId(PID, &process)))
	{

		BaseAddress = (PVOID)PsGetProcessPeb(process);

	}
	

	return BaseAddress;
}
NTSTATUS ReadProcessMemory(HANDLE PID, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size) {
	

	NTSTATUS status = STATUS_SUCCESS;
	SIZE_T Result;
	PEPROCESS SourceProcess;
	if (NT_SUCCESS(PsLookupProcessByProcessId(PID, &SourceProcess)))
	{
		__try {
			if (NT_SUCCESS(MmCopyVirtualMemory(SourceProcess, SourceAddress, PsGetCurrentProcess(), TargetAddress, Size, KernelMode, &Result)))
				status = STATUS_SUCCESS;
			else
				status = STATUS_ACCESS_DENIED;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			status = STATUS_ACCESS_DENIED;
		}
	}
	

	return status;

}
NTSTATUS WriteProcessMemory(HANDLE PID, PVOID SourceAddress, PVOID TargetAddress, SIZE_T Size) {
	

	NTSTATUS status = STATUS_SUCCESS;
	SIZE_T Result;
	PEPROCESS SourceProcess;
	if (NT_SUCCESS(PsLookupProcessByProcessId(PID, &SourceProcess)))
	{
		__try {
		if (NT_SUCCESS(MmCopyVirtualMemory(PsGetCurrentProcess(), TargetAddress, SourceProcess, SourceAddress, Size, KernelMode, &Result)))
			status = STATUS_SUCCESS;
		else
			status = STATUS_ACCESS_DENIED;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			status = STATUS_ACCESS_DENIED;
		}

	}
	
	return status;

}
ULONGLONG GetModuleHandle(ULONG pid, LPCWSTR module_name) {
	

	PEPROCESS target_proc;
	ULONGLONG base = 0;
	if (!NT_SUCCESS(PsLookupProcessByProcessId((HANDLE)pid, &target_proc)))
		return 0;
	KeAttachProcess((PKPROCESS)target_proc);
	PPEB peb = PsGetProcessPeb(target_proc);
	if (!peb)
		goto end;
	if (!peb->Ldr || !peb->Ldr->Initialized)
		goto end;
	UNICODE_STRING module_name_unicode;
	RtlInitUnicodeString(&module_name_unicode, module_name);
	for (PLIST_ENTRY list = peb->Ldr->InLoadOrderModuleList.Flink;
		list != &peb->Ldr->InLoadOrderModuleList;
		list = list->Flink) {
		PLDR_DATA_TABLE_ENTRY entry = CONTAINING_RECORD(list, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);
		if (RtlCompareUnicodeString(&entry->BaseDllName, &module_name_unicode, TRUE) == 0) {
			base = entry->DllBase;
			goto end;
		}
	}
end:
	KeDetachProcess();
	ObDereferenceObject(target_proc);
	
	return base;
}
NTSTATUS IOCTL(PDEVICE_OBJECT DeviceObject, PIRP irp) {
	

	NTSTATUS status;
	ULONG info_size = 0;
	PUCHAR UserBuffer = NULL;
	PIO_STACK_LOCATION stack = IoGetCurrentIrpStackLocation(irp);
	ULONG control_code = stack->Parameters.DeviceIoControl.IoControlCode;
	switch (control_code)
	{
	case IOCTL_READ_MEM: {
		

		p_rw buffer = (p_rw)irp->AssociatedIrp.SystemBuffer;
		buffer->PID ^= 0x8fea0644;
		buffer->Addr ^= 0xfcb3e314;
		buffer->Bytes ^= 0x544becbe;
		UserBuffer = (PUCHAR)MmGetSystemAddressForMdlSafe(irp->MdlAddress, NormalPagePriority);
		if ( UserBuffer && ValidPointer(buffer->Addr)  && buffer->PID != NULL) {
			ReadProcessMemory((HANDLE)buffer->PID, buffer->Addr, (PVOID)UserBuffer, buffer->Bytes);
		}
		KeFlushIoBuffers(irp->MdlAddress, TRUE, FALSE);
		status = STATUS_SUCCESS;
		info_size = sizeof(k_rw);
		

	}break;
	case IOCTL_WRITE_MEM: {
		

		p_rw buffer = (p_rw)irp->AssociatedIrp.SystemBuffer;
		buffer->PID ^= 0x8fea0644;
		buffer->Addr ^= 0xfcb3e314;
		buffer->Bytes ^= 0x544becbe;
		UserBuffer = (PUCHAR)MmGetSystemAddressForMdlSafe(irp->MdlAddress, NormalPagePriority);
		if (UserBuffer && ValidPointer(buffer->Addr) && buffer->PID != NULL) {
			WriteProcessMemory((HANDLE)buffer->PID, buffer->Addr, (PVOID)UserBuffer, buffer->Bytes);
		}
		KeFlushIoBuffers(irp->MdlAddress, TRUE, FALSE);
		status = STATUS_SUCCESS;
		info_size = sizeof(k_rw);
		

	}break;
	case IOCTL_BASE_MEM: {
		

		p_imagebase buffer = (p_imagebase)irp->AssociatedIrp.SystemBuffer;
		if (buffer->PID != NULL) {
			ULONGLONG GetBase = GetImageBase((HANDLE)buffer->PID);
			buffer->Base = GetBase;
		}
		status = STATUS_SUCCESS;
		info_size = sizeof(k_imagebase);
		

	}break;
	case IOCTL_PEB_MEM: {
		

		p_pebbase buffer = (p_pebbase)irp->AssociatedIrp.SystemBuffer;
		if (buffer->PID != NULL) {
			ULONGLONG GetBase = GetProcessPeb((HANDLE)buffer->PID);
			buffer->Base = GetBase;
		}
		status = STATUS_SUCCESS;
		info_size = sizeof(k_pebbase);
		

	}break;
	case IOCTL_GET_MODULE_BASE: {
		

		p_modulehandle buffer = (p_modulehandle)irp->AssociatedIrp.SystemBuffer;
		if (buffer->PID != NULL) {
			ULONGLONG GetBase = GetModuleHandle((HANDLE)buffer->PID, buffer->name);
			buffer->Base = GetBase;
		}
		status = STATUS_SUCCESS;
		info_size = sizeof(k_modulehandle);
		

	}break;
	case IOCTL_PROTECT_VIRUTAL_MEMORY: {
		

		p_protectvirutal buffer = (p_protectvirutal)irp->AssociatedIrp.SystemBuffer;
		if (buffer->PID != NULL)
		{
			PEPROCESS target_proc;
			status = PsLookupProcessByProcessId(buffer->PID, &target_proc);
			if (NT_SUCCESS(status))
			{
				KAPC_STATE apc;
				KeStackAttachProcess(target_proc, &apc);
				status = ZwProtectVirtualMemory(ZwCurrentProcess(), &buffer->address, &buffer->size, buffer->protect, &buffer->protect);
				KeUnstackDetachProcess(&apc);
				if (NT_SUCCESS(status)) {
				}
				ObfDereferenceObject(target_proc);
			}
		}
		status = STATUS_SUCCESS;
		info_size = sizeof(k_protectvirutal);
		

	}break;
	case IOCTL_ALLOCATE_VIRUTAL_MEMORY: {
		

		p_allocation buffer = (p_allocation)irp->AssociatedIrp.SystemBuffer;
		if (buffer->PID != NULL)
		{
			PEPROCESS target_proc;
			status = PsLookupProcessByProcessId(buffer->PID, &target_proc);
			if (NT_SUCCESS(status)) {
				KAPC_STATE apc;
				KeStackAttachProcess(target_proc, &apc);
				status = ZwAllocateVirtualMemory(ZwCurrentProcess(), &buffer->address, 0, &buffer->size,
					buffer->type, buffer->protect);
				KeUnstackDetachProcess(&apc);
				ObfDereferenceObject(target_proc);
			}
		}
		status = STATUS_SUCCESS;
		info_size = sizeof(k_allocation);
		

	}break;
	case IOCTL_VIRTUAL_QUERY_MEMORY: {
		

		PREQUEST_QUERY buffer = (PREQUEST_QUERY)irp->AssociatedIrp.SystemBuffer;
		if (buffer->PID != NULL)
		{
			PEPROCESS target_process = NULL;
			status = PsLookupProcessByProcessId(buffer->PID, &target_process);
			if (NT_SUCCESS(status)) {
				(KeAttachProcess)((PKPROCESS)target_process);
				MEMORY_BASIC_INFORMATION MeMBI = { 0 };
				status = ZwQueryVirtualMemory(ZwCurrentProcess(), buffer->address, MemoryBasicInformation, &MeMBI, sizeof(MeMBI), &buffer->size);
				(KeDetachProcess)();
				if (NT_SUCCESS(status)) {
					RtlCopyMemory(buffer->MBI, &MeMBI, sizeof(MeMBI));
				}
				(ObfDereferenceObject)(target_process);

			}
		}
		status = STATUS_SUCCESS;
		info_size = sizeof(REQUEST_QUERY);
		

	}break;
	case IOCTL_HIDE_MEMORY: {
		
		p_hide buffer = (p_hide)irp->AssociatedIrp.SystemBuffer;
		if (buffer->PID != NULL)
		{
			status = HideProcessByProcessId(buffer->PID);
			if (NT_SUCCESS(status))
			{
				buffer->result = 1;
			}
			else
			{
				buffer->result = 0;

			}
		}
		status = STATUS_SUCCESS;
		info_size = sizeof(k_hide);
		
	}break;

	default:
		status = STATUS_INVALID_PARAMETER;
		info_size = 0;
		break;
	}
	irp->IoStatus.Status = status;
	irp->IoStatus.Information = info_size;
	IoCompleteRequest(irp, IO_NO_INCREMENT);
	return status;

}
NTSTATUS init(PDRIVER_OBJECT driver,PUNICODE_STRING path) {
	
	RtlInitUnicodeString(&dev, drv_device);
	RtlInitUnicodeString(&dos, drv_dos_device);

	IoCreateDevice(driver, 0, &dev, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &driver_object);
	IoCreateSymbolicLink(&dos, &dev);

	driver->MajorFunction[IRP_MJ_DEVICE_CONTROL] = IOCTL;
	driver->MajorFunction[IRP_MJ_CREATE] = ioctl_create;
	driver->MajorFunction[IRP_MJ_CLOSE] = ioctl_close;
	driver->DriverUnload = unload_driver;

	driver_object->Flags |= DO_DIRECT_IO;
	driver_object->Flags &= ~DO_DEVICE_INITIALIZING;
	

	return STATUS_SUCCESS;
}
NTSTATUS DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING path) {
	NTSTATUS        status;
	UNICODE_STRING drv_name;
	RtlInitUnicodeString(&drv_name, drv);
	return IoCreateDriver(&drv_name, &init);
}
