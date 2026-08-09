#ifndef _RENDERWINDOW_H
#define _RENDERWINDOW_H

#include "types.h"

#include "UIWindow.h"

#include <windows.h>

class Graphics;

/**
 * @todo Documentation
 */
class SYSCORE_API RenderWindow : public UIWindow {
public:
	RenderWindow(UIWindow*, int, int, int, bool);

	void initOpenGL();
	void shutdownOpenGL();

	void clearRender();
	void paintRender(RectArea*);

	virtual void update();                                  // _10
	virtual int processMessage(HWND, UINT, WPARAM, LPARAM); // _40
	virtual void createWindow(char*, char*, HMENU);         // _50

	// _00     = VTBL
	// _00-_88 = UIWindow
	u32 mHeight;          // _88
	u32 mWidth;           // _8C
	HDC mRenderScene;     // _90
	u32 _94;              // _94
	bool mError;          // _98
	UIWindow* mBoxWindow; // _9C
	Graphics* _A0;        // _A0
};

#endif
