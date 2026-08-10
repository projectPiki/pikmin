#include "ToolWindow.h"

#include <stdio.h>

/**
 * @brief Process parameters from `UIWindowWndProc` callback.
 */
int ToolWindow::processMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_NOTIFY:
	{
		// TODO: WinAPI is complicated.  These need to be `reinterpret_cast` to some classes.
		LPARAM local_c  = lParam;
		WPARAM local_10 = wParam;
		if (true) {
			LPARAM local_14 = lParam;
			char local_214[512];
			LoadString(0, 0, local_214, 256);
			sprintf(0, local_214);
		}
		break;
	}
	}

	UIWindow::processMessage(hWnd, uMsg, wParam, lParam);
}

/**
 * @todo Documentation
 */
void ToolWindow::initTools(HINSTANCE hInst, int msg, LPTBBUTTON param_3, LPTBADDBITMAP param_4)
{
	mWindowInst = hInst;

	HBITMAP unused2;
	int local_10; // TODO: This is probably something else.
	HBITMAP unused;

	// Some concentrated weirdness going on here.
	unused   = LoadBitmap(hInst, MAKEINTRESOURCE(param_4->nID));
	local_10 = 0;
	unused2  = unused;

	// TODO: Create macros to name all of these user-defined message identifiers.
	SendMessage(mWindow->mWindowHandle, WM_USER + 0x1e, 0x14, 0);
	SendMessage(mWindow->mWindowHandle, WM_USER + 0x20, 0, 0x190019); // TODO: lParam is definitely some macro
	SendMessage(mWindow->mWindowHandle, WM_USER + 0x13, msg, reinterpret_cast<LPARAM>(&local_10));
	SendMessage(mWindow->mWindowHandle, WM_USER + 0x14, msg, reinterpret_cast<LPARAM>(param_3));
	SendMessage(mWindow->mWindowHandle, WM_USER + 0x21, 0, 0);
}

/**
 * @todo Documentation
 */
void ToolWindow::createWindow(char* param_1, char* param_2, HMENU hMenu)
{
	UIWindow::createWindow(param_1, param_2, hMenu);
	mWindow = new UIWindow(this, 0xf, 0x52000340, 0, false); // TODO: Replace magic numbers
	mWindow->sizeWindow(mWidth, mHeight, 0);
	mWindow->createWindow("ToolbarWindow32", "toolbar", nullptr);
}
