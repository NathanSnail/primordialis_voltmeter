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
