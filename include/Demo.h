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

	char* mName;     // _00
	u16 mIndex;      // _04
	s16 mMovieIndex; // _06
	u16 _08;         // _08
	bool _0A;        // _0A
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

	virtual void read(RandomAccessStream& data) { mParms.read(data); } // _0C

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

	u16 mFlagCount;            // _00
	u16 mCurrentDataIndex;     // _02
	u16 mFlagDataNum;          // _04
	u8* mStoredFlags;          // _08
	DemoFlag** mFlagDataList;  // _0C
	Creature* mTargetCreature; // _10
	f32 mWaitTimer;            // _14
	s16 mCurrentDemoIndex;     // _18
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
