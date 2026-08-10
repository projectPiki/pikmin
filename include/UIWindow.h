#ifndef _UIWINDOW_H
#define _UIWINDOW_H

#include "types.h"

#include "Geometry.h"
#include "Node.h"

#include <windows.h>

class BaseApp;

/**
 * @brief Base class for the `UIWindow` class
 * @note Size: 0x50
 */
class SYSCORE_API UIFrame : public Node {
public:
	UIFrame();

	void calcClientFromFrame(RectArea&);
	void calcFrameFromClient(RectArea&);
	void setClient(RectArea&);
	void setFrame(RectArea&);

	// _00     = VTBL
	// _00-_20 = Node
	RectArea mFrame;  // _20
	RectArea mZero;   // _30
	RectArea mClient; // _40
};

/**
 * @brief Base class for many UI component classes
 * @note Size: 0x88
 */
class SYSCORE_API UIWindow : public UIFrame {
public:
	UIWindow(UIWindow* parent, int, int, int, bool);
	UIWindow();
	~UIWindow();

	void closeChildren();
	void initFrame(UIWindow*, int, int, int, bool);
	void sizeWindow(int width, int height, int);
	void updateMove(int, int);

	virtual void refreshWindow();                           // _34
	virtual void updateSizes(int, int);                     // _38
	virtual void activate();                                // _3C
	virtual int processMessage(HWND, UINT, WPARAM, LPARAM); // _40
	virtual int returnMessage(HWND, UINT, WPARAM, LPARAM);  // _44
	virtual void* resizeChildren(void*, RectArea&);         // _48
	virtual void* resizeFrame(void*, RectArea&);            // _4C
	virtual void createWindow(char*, char*, HMENU);         // _50
	virtual void dockTop(int, RectArea&, RectArea&);        // _54

	// _00     = VTBL
	// _00-_50 = UIFrame
	RectArea _50;       // _50
	UIWindow* mParent;  // _60
	HWND mWindowHandle; // _64
	int mStyle;         // _68
	int mExStyle;       // _6C
	int _70;            // _70
	int _74;            // _74
	int mWidth;         // _78
	int mHeight;        // _7C
	bool _80;           // _80
	HMENU mMenuHandle;  // _84
};

/**
 * @todo Documentation
 */
class SYSCORE_API SplitBar : public UIWindow {
public:
	SplitBar(UIWindow*, UIWindow*, unsigned long, int);

	void handleClick(int, int);
	void handleRelease(int, int);

	virtual int processMessage(HWND, UINT, WPARAM, LPARAM); // _40

	// _00     = VTBL
	// _00-_88 = UIWindow
	u8 mReleaseBar; // _88
	u32 mReleaseX;  // _8C
	u32 mReleaseY;  // _90
	UIWindow* _94;  // _94
	UIWindow* _98;  // _98
	u32 _9C;        // _9C
	HBRUSH mBrush;  // _A0
};

/**
 * @todo Documentation
 */
class SYSCORE_API VertSplitBar : public SplitBar {
public:
	VertSplitBar(UIWindow*, UIWindow*, unsigned long, int);

	virtual void trackMouse(int, int, int); // _58

	// _00     = VTBL
	// _00-_A4 = SplitBar
};

/**
 * @todo Documentation
 */
class SYSCORE_API HorzSplitBar : public SplitBar {
public:
	HorzSplitBar(UIWindow*, UIWindow*, unsigned long, int);

	virtual void trackMouse(int, int, int); // _58

	// _00     = VTBL
	// _00-_A4 = SplitBar
};

/**
 * @todo Documentation
 */
class SYSCORE_API ComboBox : public UIWindow {
public:
	ComboBox(UIWindow*, int, int, int, bool);

	void addOption(char*, bool);
	void selOption(int);

	virtual void createWindow(char*, char*, HMENU);         // _50
	virtual int processMessage(HWND, UINT, WPARAM, LPARAM); // _40
	virtual void entryHandler(char*);                       // _58

	// _00     = VTBL
	// _00-_88 = UIWindow
	UIWindow* mBoxWindow; // _88
	u32 mBoxExStyle;      // _8C
};

/**
 * @todo Documentation
 */
class SYSCORE_API EditBox : public ComboBox {
public:
	EditBox(UIWindow*, int, int, int, bool);

	virtual int processMessage(HWND, UINT, WPARAM, LPARAM); // _40
	virtual void entryHandler(char*);                       // _58

	// _00     = VTBL
	// _00-_90 = ComboBox
};

/**
 * @todo Documentation
 */
class SYSCORE_API OptionBox : public ComboBox {
public:
	OptionBox(UIWindow*, int, int, int, bool);

	virtual int processMessage(HWND, UINT, WPARAM, LPARAM); // _40
	virtual void selectionChanged(int);                     // _5C

	// _00     = VTBL
	// _00-_90 = ComboBox
};

/**
 * @todo Documentation
 */
class SYSCORE_API AppWindow : public UIWindow {
public:
	AppWindow(UIWindow*, int, int, int, bool);

	virtual int processMessage(HWND, UINT, WPARAM, LPARAM); // _40

	// _00     = VTBL
	// _00-_88 = UIWindow
	BaseApp* mApp; // _88
};

#endif
