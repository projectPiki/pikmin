#ifndef _BASEAPP_H
#define _BASEAPP_H

#include "Node.h"
#include "system.h"

struct AtxCommandStream;
struct AgeServer;

struct BaseApp : public Node {
public:
	BaseApp();
	int idleupdate();

	f32 rnd(f32);
	f32 rnd();

	void startAgeServer();
	void stopAgeServer();

	virtual ~BaseApp();                                   // _30
	virtual void InitApp(char*) { }                       // _34
	virtual int idle() { return 0; }                      // _38
	virtual bool keyDown(int, int, int) { return false; } // _3C
	virtual void softReset();                             // _40
	virtual void useHeap(int index)                       // _44
	{
		mHeapIndex = index;
		gsys->setHeap(mHeapIndex);
	}
	virtual void procCmd(char*) { } // _48

protected:
	// _00     = VTBL
	// _00-_20 = Node
	AtxCommandStream* mCommandStream; // _20
	AgeServer* mAgeServer;            // _24
	s8 _28;                           // _28
	BOOL mIsReadyToDraw;              // _2C
	Node mWindowNode;                 // _30
	u32 mHeapIndex;                   // _50
};

extern BaseApp* app;

#endif
