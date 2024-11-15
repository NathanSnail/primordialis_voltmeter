#include "windows_loader.h"
#ifdef __unix__
HANDLE CreateRemoteThread(HANDLE hProcess,
				  LPSECURITY_ATTRIBUTES lpThreadAttributes,
				  SIZE_T dwStackSize,
				  LPTHREAD_START_ROUTINE lpStartAddress,
				  LPVOID lpParameter, DWORD dwCreationFlags,
				  LPDWORD lpThreadId);
#endif
