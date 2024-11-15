#include "WindowsHModular/windows_loader.h"
#include <stdio.h>
#include <stdlib.h>
DoesNothing;

size_t baseAddress;

static inline void *Address(size_t value) {
	return (void *)(baseAddress + value - 0x140000000);
}

// this function will likely be removed in later versions of the modloader
__declspec(dllexport) void init() { MessageBoxA(NULL, "grr", "hia", MB_OK); }

void testInjection() {
	printf("test injection\n");

	MessageBoxA(NULL, "test injection", "Voltmeter", MB_OK);
}

__declspec(dllexport) void detourInit(void (*DetourAttach)(void *, void *)) {
	while (1) {}
	freopen("CONOUT$", "w", stdout);
	printf("detourInit voltmeter");
	DetourAttach(NULL, NULL);

	baseAddress = (size_t)GetModuleHandleA(NULL);
	PVOID *func_ptr = (PVOID *)malloc(sizeof(PVOID));
	void *TargetFunctionAddress = Address(0x14002db80);
	*func_ptr = TargetFunctionAddress;

	DetourAttach(func_ptr, &testInjection);
}
