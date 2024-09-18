#ifndef _DEMO_H
#define _DEMO_H

#include "types.h"
#include "Node.h"

struct Creature;

/**
 * @brief TODO
 */
struct DemoParms : public Node {

	/**
	 * @brief TODO
	 */
	struct Parms {
		Parms();

		// TODO: members
	};

	DemoParms();

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
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
	void getDemoFlag(int);

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
 */
struct DemoEventMgr {
	DemoEventMgr();

	void act(int, int);

	// unused/inlined:
	void getEventName(int, int);
	void getSenderName(int);

	// TODO: members
};

extern DemoEventMgr* demoEventMgr;

#endif
