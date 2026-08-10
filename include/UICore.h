#ifndef _UICORE_H
#define _UICORE_H

#include "types.h"

#include "Node.h"

#include <windows.h>

class UIWindow;

/**
 * @brief `Node` whose children are of type `UIWindow`.
 */
class SYSCORE_API UIMgr : public Node {
public:
	UIMgr();

	bool isActive();
	void activateWindow(HWND, UIWindow*);
	void RegisterGenWindowClass(char*, void*, bool);

	// _00     = VTBL
	// _00-_20 = Node
	Node mTop; // _20
};

extern UIMgr* uiMgr;

#endif
