#ifndef _DEMO_H
#define _DEMO_H

#include "types.h"
#include "Node.h"
#include "Parameters.h"

struct Creature;

/**
 * @brief TODO
 */
enum EDemoFlags {
	DEMOFLAG_Unk0 = 0,
	DEMOFLAG_Unk1 = 1,
	// ...
	DEMOFLAG_Unk9 = 9,
	// ...
	DEMOFLAG_Unk27 = 27,
	DEMOFLAG_Unk28 = 28,
	DEMOFLAG_Unk29 = 29,
};

/**
 * @brief TODO
 */
struct DemoFlag {
	// TODO: this - only gets returned by DemoFlags::getDemoFlag smh
};

/**
 * @brief TODO
 */
struct DemoParms : public Node {

	struct Parms : Parameters {
		Parms();

		Parm<f32> mOnionBootTriggerRadius; // _00
		Parm<f32> mSeedDemoTriggerRadius;  // _10
		Parm<f32> mSeedDemoWaitTime;       // _20
		Parm<f32> _30;                     // _30
		Parm<f32> mDemoTriggerRadius;      // _40
	};

	DemoParms();

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_20 = Node
	Parms mParms; // _24
};

/**
 * @brief TODO
 */
struct DemoFlags {
	DemoFlags();

	void initGame();
	void initCourse();
	void update();
	void saveCard(RandomAccessStream&);
	void loadCard(RandomAccessStream&);
	void registerDemoFlag(int, char*, u16, u16, bool);
	bool isFlag(int);
	void resetFlag(int);
	void setFlag(int, Creature*);
	void setFlagOnly(int);
	void setTimer(f32, int, Creature*);
	void resetTimer();
	DemoFlag* getDemoFlag(int);

	// TODO: members
	u16 _00;     // _00
	u16 _02;     // _02
	u16 _04;     // _04
	u8* _08;     // _08
	u32* _0C;    // _0C
	u8 _10[0x4]; // _10, unknown
	f32 _14;     // _14
	u16 _18;     // _18
};

/**
 * @brief TODO
 *
 * @note Size: 0x1 (empty).
 */
struct DemoEventMgr {
	DemoEventMgr();

	void act(int, int);

	// unused/inlined:
	char* getEventName(int, int);
	char* getSenderName(int);

	// no members
};

extern DemoEventMgr* demoEventMgr;
extern DemoParms* demoParms;

#endif
