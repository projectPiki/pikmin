#ifndef _SYSTEM_H
#define _SYSTEM_H
#include "types.h"
struct BaseApp {
};

struct System {
	char filler0[0x28C - 0x0];
	float m_28C;
	char filler1[0x334 - 0x290];
	void Initialise();
	static void* alloc(size_t);
	void run(BaseApp* ptr);
};

extern System* gsys;

struct NodeMgr {
	char filler0[0x18];
	NodeMgr();
};
extern NodeMgr* nodeMgr;
struct PlugPikiApp : public BaseApp {
	char filler0[0x54];
	PlugPikiApp();
};

extern "C" void OSPanic(const char* filename, int line, const char* msg, ...);

inline void* operator new(size_t size) { return System::alloc(size); }
#endif
