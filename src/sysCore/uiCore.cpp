#include "UICore.h"

#include "AttachModule.h"
#include "Geometry.h"
#include "UIWindow.h"
#include "system.h"

#include <commctrl.h>

UIMgr* uiMgr;

/**
 * @todo Figure out what callback type this conforms to.
 */
void CALLBACK handlePopupMenu(HWND hWnd, LPINT param_2, POINT point, HMENU hMenu)
{
	if (!hMenu) {
		return;
	}

	if (param_2) {
		*param_2 = 1;
	}

	HMENU hSubMenu = GetSubMenu(hMenu, 0);
	ClientToScreen(hWnd, &point);

	RectArea rect(0, 0, 32, 32); // UB for no good reason.  Real "not invented here" moment.
	TrackPopupMenu(hSubMenu, 0, point.x, point.y, 0, hWnd, reinterpret_cast<RECT*>(&rect));

	DestroyMenu(hMenu);
}

/**
 * @brief Conforms to the `WNDPROC` callback type.
 */
LRESULT CALLBACK UIWindowWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_DESTROY:
	{
		nodeMgr->Del(reinterpret_cast<UIWindow*>(GetWindowLong(hWnd, 0)));
		break;
	}
	case WM_CREATE:
	{
		SetWindowLong(hWnd, 0, 0);
		break;
	}
	case WM_ACTIVATEAPP:
	{
		if (wParam) {
			if (!gsys->isShutdown() && !gsys->isActive()) {
				gsys->setActive(true);
				if (uiMgr) {
					uiMgr->activateWindow(hWnd, reinterpret_cast<UIWindow*>(GetWindowLong(hWnd, 0)));
				}
			}
		} else {
			if (gsys->isActive()) {
				gsys->setActive(false);
			}
		}
		return 0;
	}
	}

	UIWindow* window = reinterpret_cast<UIWindow*>(GetWindowLong(hWnd, 0));
	if (window && !gsys->isShutdown()) {
		window->processMessage(hWnd, uMsg, wParam, lParam);
	} else {
		DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

void UIMgr::activateWindow(HWND hWnd, UIWindow*)
{
	FOREACH_NODE_ALT(UIWindow, Child(), window)
	{
		window->activate();
	}
}

void UIMgr::RegisterGenWindowClass(char* className, void* wndProc, bool whichBackground)
{
	WNDCLASSEX lpwcx;

	// MSDN: "Be sure to set this member before calling the `GetClassInfoEx` function."
#if defined(BUGFIX) && 0
	// Pending ability to test bugfix
	lpwcx.cbSize = sizeof(WNDCLASSEX);
#endif

	if (!GetClassInfoEx(sysHInst, className, &lpwcx)) {
		lpwcx.cbSize        = sizeof(WNDCLASSEX);
		lpwcx.lpszClassName = className;
		lpwcx.hInstance     = sysHInst;
		lpwcx.lpfnWndProc   = wndProc ? reinterpret_cast<WNDPROC>(wndProc) : UIWindowWndProc;
		lpwcx.hCursor       = LoadCursor(nullptr, IDC_ARROW);
		lpwcx.hIcon         = LoadIcon(g_hInst, MAKEINTRESOURCE(101)); // TODO: User ordinal for Olimar icon?
		lpwcx.lpszMenuName  = nullptr;
		lpwcx.hbrBackground = reinterpret_cast<HBRUSH>(whichBackground ? 0x10 : 0); // TODO: MSDN documentation is hard to understand
		lpwcx.style         = CS_OWNDC;
		lpwcx.cbClsExtra    = 0;
		lpwcx.cbWndExtra    = 4; // TODO: I need some info on what those four bytes are.
		lpwcx.hIconSm       = LoadIcon(g_hInst, MAKEINTRESOURCE(101));
		RegisterClassEx(&lpwcx);
	}
}

UIMgr::UIMgr()
    : Node("UIMgr")
{
	RegisterGenWindowClass("DUIGenWin", nullptr, true);
	RegisterGenWindowClass("DUIClearWin", nullptr, false);
	InitCommonControls();

	nodeMgr->firstNode()->add(this);
}

UIMgr::~UIMgr()
{
	FOREACH_NODE_ALT(UIWindow, Child(), window)
	{
		DestroyWindow(window->mWindowHandle);
	}
}
