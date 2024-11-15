#pragma once
#define DoesNothing // good for make clangd shut up
#ifndef __unix__
#include <windows.h>
#else
#include "WindowsHModular/include/win32/windows.h"
#include "custom.h"
#endif
