#ifndef _BASEAPP_H
#define _BASEAPP_H

#include "Node.h"

struct AtxCommandStream;
struct AgeServer;

struct BaseApp : public Node {
	BaseApp();
	int idleupdate(void);

	float rnd(float);
	float rnd(void);

	void startAgeServer(void);
	void stopAgeServer(void);

	virtual void genAge(class AgeServer&);

	virtual ~BaseApp(void);
	virtual void InitApp(char*);
	virtual int idle(void);
	virtual bool keyDown(int, int, int);
	virtual void softReset(void);
	virtual void useHeap(int);
	virtual void procCmd(char*);

	AtxCommandStream* mCommandStream; // _20
	AgeServer* mAgeServer;            // _24
	s8 _28;                           // _28
	s32 _2C;                          // _2C
	Node mWindowNode;                 // _30
	u32 mHeapIndex;                   // _50
};

#endif // _BASEAPP_H
