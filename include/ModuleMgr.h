#ifndef _MODULEMGR_H
#define _MODULEMGR_H

#include "types.h"

#include <windows.h>

/**
 * @todo Documentation
 */
class MenuPlugin {
public:
	MenuPlugin();
	void insert(MenuPlugin*);

	MenuPlugin* mPrev; // _00
	char* mName;       // _04
	MenuPlugin* mNext; // _08
};

/**
 * @todo Documentation
 */
class SYSCORE_API Module {
public:
	~Module();

	void Load(char*);
	void menuPlugins(MenuPlugin&, HMENU);

	void (*mNewObjAddr)(char); // _00
	void (*mObjListAddr)();    // _04
	void (*mAutoStartAddr)();  // _08
	HMODULE mHInstance;        // _0C
	char* mLibName;            // _10
	Module* mPrev;             // _14
	Module* mNext;             // _18
};

/**
 * @todo Documentation
 */
class SYSCORE_API ModuleMgr {
public:
	ModuleMgr();
	~ModuleMgr();

	Module* findModule(char*);
	Module* loadModule(char*);
	void* Alloc(char*);
	void listModules();
	void UnLoad(Module*);

	Module* mTopModule; // _00
	int mModuleCount;   // _04
};

#endif
