#include "AttachModule.h"

/**
 * @brief Global handle for the instance received by `DllMain`.
 */
HINSTANCE g_hInst;

/**
 * @brief Reusable DLL entry point function (every DLL compiles this file)
 */
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
	{
		g_hInst = hinstDLL;
		break;
	}
	}
	return TRUE;
}
