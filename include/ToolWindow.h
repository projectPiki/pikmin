#ifndef _TOOLWINDOW_H
#define _TOOLWINDOW_H

#include "types.h"

#include "UIWindow.h"

#include <commctrl.h>
#include <windows.h>

class SYSCORE_API ToolWindow : public UIWindow {
public:
	ToolWindow(UIWindow* parent, int param_2, int param_3, int param_4, bool param_5)
	    : UIWindow(parent, param_2, param_3, param_4, param_5)
	{
	}

	void initTools(HINSTANCE, int, LPTBBUTTON, LPTBADDBITMAP);

	// _00     = VTBL
	// _00-_88 = UIWindow
	virtual int processMessage(HWND, UINT, WPARAM, LPARAM); // _40
	virtual void createWindow(char*, char*, HMENU);         // _50

	UIWindow* mWindow;     // _88
	HINSTANCE mWindowInst; // _8C
};

#endif
