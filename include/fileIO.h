#ifndef _FILEIO_H
#define _FILEIO_H

#include "types.h"

#include <windows.h>

immut char* getOpenFilename(HWND hWnd, char* filter);
immut char* getSaveFilename(HWND hWnd, char* filter, immut char* initFileName);

#endif
