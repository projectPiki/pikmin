#include "fileIO.h"

#include "system.h"

#include <direct.h>

#include <stdio.h>

OPENFILENAME ofn;
static char s_dialogTitle[PATH_MAX];
static char s_initialDir[PATH_MAX];
static char s_fileName[PATH_MAX];

/**
 * @note Conforms to the `LPOFNHOOKPROC` callback type.
 */
static UINT CALLBACK openFileNameCallback(HWND hWnd, UINT message, WPARAM, LPARAM)
{
	switch (message) {
	case WM_INITDIALOG:
	{
		return TRUE;
	}
	}
	return FALSE;
}

/**
 * @todo Documentation
 */
static void initOpenFileName(HWND hWnd, char* filter)
{
	int filterLength = strlen(filter);
	for (int i = 0; i < filterLength; ++i) {
		if (filter[i] == '|') {
			filter[i] = '\0';
		}
	}

	ofn.lStructSize       = sizeof(OPENFILENAME);
	ofn.hwndOwner         = hWnd;
	ofn.hInstance         = sysHInst;
	ofn.lpstrFilter       = filter;
	ofn.lpstrCustomFilter = nullptr;
	ofn.nMaxCustFilter    = 0;
	ofn.nFilterIndex      = 0;
	ofn.lpstrFile         = nullptr;
	ofn.nMaxFile          = MAX_PATH;
	ofn.lpstrFileTitle    = nullptr;
	ofn.nMaxFileTitle     = 512; // Not `_MAX_FNAME`
	ofn.lpstrInitialDir   = nullptr;
	ofn.lpstrTitle        = nullptr;
	ofn.Flags             = 0;
	ofn.nFileOffset       = 0;
	ofn.nFileExtension    = 0;
	ofn.lpstrDefExt       = nullptr;
	ofn.lCustData         = 0;
	ofn.lpfnHook          = openFileNameCallback;
	ofn.lpTemplateName    = nullptr;
}

/**
 * @todo Documentation
 */
immut char* getOpenFilename(HWND hWnd, char* filter)
{
	sprintf(s_dialogTitle, "Open file ...");
	sprintf(s_initialDir, "%s", getcwd(nullptr, 0));
	sprintf(s_fileName, "");

	initOpenFileName(hWnd, filter);
	ofn.Flags      = OFN_ENABLESIZING | OFN_EXPLORER | OFN_ALLOWMULTISELECT | OFN_ENABLEHOOK;
	ofn.lpstrTitle = s_dialogTitle;
	ofn.lpstrFile  = s_fileName;
	// This is set to `MAX_PATH` (260) by default, but `s_fileName is `PATH_MAX` (256) characters long.
#if defined(BUGFIX) && 0
	// Pending ability to test bugfix
	ofn.nMaxFile = sizeof(s_fileName);
#endif
	ofn.lpstrInitialDir = s_initialDir;
	ofn.hwndOwner       = hWnd;

	bool success = GetOpenFileName(&ofn);
	if (success) {
		return ofn.lpstrFile;
	}
	return nullptr;
}

/**
 * @todo Documentation
 */
immut char* getSaveFilename(HWND hWnd, char* filter, immut char* initFileName)
{
	sprintf(s_dialogTitle, "Save file as ...");
	sprintf(s_initialDir, "%s", getcwd(nullptr, 0));
	sprintf(s_fileName, initFileName ? initFileName : "");

	initOpenFileName(hWnd, filter);
	ofn.Flags      = OFN_EXPLORER | OFN_NOREADONLYRETURN | OFN_ENABLEHOOK | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	ofn.lpstrTitle = s_dialogTitle;
	ofn.lpstrFile  = s_fileName;
	// This is set to `MAX_PATH` (260) by default, but `s_fileName is `PATH_MAX` (256) characters long.
#if defined(BUGFIX) && 0
	// Pending ability to test bugfix
	ofn.nMaxFile = sizeof(s_fileName);
#endif
	ofn.lpstrInitialDir = s_initialDir;
	ofn.hwndOwner       = hWnd;

	bool success = GetSaveFileName(&ofn);
	if (success) {
		return ofn.lpstrFile;
	}
	return nullptr;
}
