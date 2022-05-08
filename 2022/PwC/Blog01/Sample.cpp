#include <ntddk.h>

void SampleUnload(_In_ PDRIVER_OBJECT DriverObject);

extern "C" NTSTATUS 
DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);
	DriverObject->DriverUnload = SampleUnload;
	KdPrint(("This string makes it easy to ID the DriverEntry\n"));
	return STATUS_SUCCESS;
}

void SampleUnload(_In_ PDRIVER_OBJECT DriverObject) {
	UNREFERENCED_PARAMETER(DriverObject);
	KdPrint(("Unloading driver\n"));
}
