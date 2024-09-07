#ifndef _BASEAPP_H
#define _BASEAPP_H

#include "Node.h"
#include "system.h"

struct AtxCommandStream;
struct AgeServer;

struct BaseApp : public Node {
	BaseApp();
	int idleupdate(void);

	f32 rnd(f32);
	f32 rnd(void);

	void startAgeServer(void);
	void stopAgeServer(void);

	virtual ~BaseApp(void);                               // _30
	virtual void InitApp(char*) { }                       // _34
	virtual int idle(void) { return 0; }                  // _38
	virtual bool keyDown(int, int, int) { return false; } // _3C
	virtual void softReset(void);                         // _40
	virtual void useHeap(int index)                       // _44
	{
		mHeapIndex = index;
		gsys->setHeap(mHeapIndex);
	}
	virtual void procCmd(char*) { } // _48

	// _00     = VTBL
	// _00-_20 = Node
	AtxCommandStream* mCommandStream; // _20
	AgeServer* mAgeServer;            // _24
	s8 _28;                           // _28
	s32 _2C;                          // _2C
	Node mWindowNode;                 // _30
	u32 mHeapIndex;                   // _50
};

#endif // _BASEAPP_H
