#ifndef _SOUNDMGR_H
#define _SOUNDMGR_H

#include "types.h"
#include "Node.h"
#include "Parameters.h"
#include "Ayu.h"
#include "Win.h"
#include "SoundID.h"

struct Creature;

/**
 * @brief TODO
 */
struct SVector_ {
	// TODO: members
};

/**
 * @brief TODO
 */
struct SeConstant : public Node {

	/**
	 * @brief TODO
	 *
	 * @note Fabricated. Offsets are relative to SeConstant for convenience.
	 */
	struct SeParms : public Parameters {
		SeParms()
		    : _24(this, 700.0f, 0.0f, 0.0f, "p00", nullptr)
		    , _34(this, 400.0f, 0.0f, 0.0f, "p01", nullptr)
		    , _44(this, 800.0f, 0.0f, 0.0f, "p02", nullptr)
		{
		}

		// _20-_24 = Parameters
		Parm<f32> _24; // _24, p00
		Parm<f32> _34; // _34, p01
		Parm<f32> _44; // _44, p02
	};

	SeConstant();

	virtual void read(RandomAccessStream& input) // _0C (weak)
	{
		mParms.read(input);
	}

	// _00     = VTBL
	// _00-_20 = Node
	SeParms mParms; // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct SeContext {
	SeContext();
	SeContext(Creature*, int);

	void setContext(Creature*, int);
	void playSound(int);
	void stopSound(int);
	void update();
	void releaseEvent();

	// unused/inlined:
	void getPos();
	void getObjType();
	void createEvent(int);
	void dump();

	// TODO: members
	u32 _00;       // _00, unknown
	Creature* _04; // _04, unknown
	int _08;       // _08, could be s32 or u32
	u16 _0C;       // _0C, could be s16
	Vector3f _10;  // _10
	Vector3f _1C;  // _1C
};

/*
 * @brief TODO
 */
struct SeMgr : public Node {
	SeMgr();

	virtual void update(); // _10

	void playNaviSound(s32, s32);
	void addInfo(int, char*);
	void joinBattle();
	void leaveBattle();
	void setPikiNum(int);

	// unused/inlined:
	void findInfo(int);
	void play(u32);
	void stop(u32);
	void playBGM(u32);
	void stopBGM();
	void stopSoundAll();

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO
 */
struct SeWin : public GmWin {
	virtual void open();              // _10
	virtual void close();             // _14
	virtual void update();            // _18
	virtual void doRender(Graphics&); // _1C

	// _00     = VTBL
	// _00-_14 = GmWin?
	// TODO: members
};

/**
 * @brief TODO
 *
 * @note Size: 0x78.
 */
struct SeSystem {

	/*
	 * @brief TODO
	 */
	struct Event {
		Event();

		// TODO: members
	};

	SeSystem();

	void initEvent();
	void resetSystem();
	void createEvent(SeContext*, int, SVector_*);
	void playPikiSound(int, Vector3f&);
	void playSoundDirect(int, int, Vector3f&);
	void destroyEvent(SeContext*, s32);
	void getEvent(SeContext*);
	void draw3d(Graphics&);
	void draw2d(Graphics&);
	void dumpEvents();
	void update(Graphics&, Vector3f&);
	void calcCameraPos(Vector3f&, Vector3f&);
	void getJacID(int);
	void exitCourse();
	void stopPlayerSe(int);

	// unused/inlined:
	void getEvent(s32);
	void getSoundName(int);
	void getEventType(int);
	void isLoopType(int);

	static void playSysSe(int);
	static void stopSysSe(int);
	static void playPlayerSe(int);

	// TODO: members
	u8 _00[0x78]; // _00, unknown
};

extern SeSystem* seSystem;
extern SeMgr* seMgr;

#endif
