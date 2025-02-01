#ifndef _SOUNDMGR_H
#define _SOUNDMGR_H

#include "Ayu.h"
#include "Controller.h"
#include "Node.h"
#include "Parameters.h"
#include "SoundID.h"
#include "types.h"
#include "Win.h"

struct Creature;

/**
 * @brief TODO
 */
struct SeInfo {
	int mSeID;     // _00
	char* mSeName; // _04
};

/**
 * @brief TODO
 */
struct SVector_ {
	f32 x;
	f32 y;
	f32 z;
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
	bool releaseEvent();

	// unused/inlined:
	Vector3f getPos();
	int getObjType();
	void createEvent(int);
	void dump();

	void setPosition(Vector3f& pos) { mPosition = pos; }

	u32 mClock;               // _00
	Creature* mGameObj;       // _04
	int mEventHandle;         // _08
	u16 mEventType;           // _0C
	Vector3f mCameraPosition; // _10
	Vector3f mPosition;       // _1C
};

/*
 * @brief TODO
 */
struct SeMgr : public Node {
	SeMgr();

	virtual void update(); // _10

	void playNaviSound(s32, s32);
	void addInfo(int seID, char* seName);
	void joinBattle();
	void leaveBattle();
	void setPikiNum(int);

	// unused/inlined:
	SeInfo* findInfo(int seID);
	void playBGM(u32);
	void stopBGM();
	void stopSoundAll();

	static void play(u32);
	static void stop(u32);

	// DLL inlines:
	int getSENum() { return mSENum; }
	SeInfo* getIndexInfo(int idx) { return &mSeInfos[idx]; }

	// _00     = VTBL
	// _00-_20 = Node
	// _00-_30 = SeMgr
	int mBattleCount; // _20
	int mSENum;       // _24
	int mMaxInfos;    // _28
	SeInfo* mSeInfos; // _2C
};

/**
 * @brief Unused SE Test window.
 */
struct SeWin : public GmWin {
	virtual void open();                  // _10
	virtual void close();                 // _14
	virtual void update();                // _18
	virtual void doRender(Graphics& gfx); // _1C

	// _00     = VTBL
	// _00-_14 = CoreNode
	// _00-_48 = GmWin
	Controller* mController;  // _48
	int mCurrSeID;            // _4C
	int mSound;               // _50
	int mAnimFramesRemaining; // _54
	int mUp;                  // _58
	f32 mTime;                // _5C
	bool mStickWasPushed;     // _60
};

/**
 * @brief TODO
 *
 * @note Size: 0x78.
 */
struct SeSystem {

	struct Event {
		Event()
		{
			mHandle  = -1;
			mContext = nullptr;
		}

		int mHandle;         // _00
		SeContext* mContext; // _04
	};

	SeSystem();

	void initEvent();
	void resetSystem();
	int createEvent(SeContext*, int, SVector_*);
	void playPikiSound(int, Vector3f&);
	void playSoundDirect(int, int, Vector3f&);
	bool destroyEvent(SeContext*, s32);
	int getEvent(SeContext*);
	void draw3d(Graphics&);
	void draw2d(Graphics&);
	void dumpEvents();
	void update(Graphics&, Vector3f&);
	void calcCameraPos(Vector3f&, Vector3f&);
	int getJacID(int);
	void exitCourse();

	// unused/inlined:
	int getEvent(s32);
	char* getSoundName(int);
	int getEventType(int);
	bool isLoopType(int);

	static void playSysSe(int);
	static void stopSysSe(int);
	static void playPlayerSe(int);
	static void stopPlayerSe(int);

	int mMaxSoundID;          // _00
	Matrix4f mMtx;            // _04
	f32 _44;                  // _44, unused?
	Vector3f mPosition;       // _48
	int mCurrentContextCount; // _54
	int mMaxContextCount;     // _58
	SeContext* mContext;      // _5C
	SeConstant* mConstant;    // _60
	u32 mClock;               // _64
	int mCurrentEventCount;   // _68
	int mMaxEventCount;       // _6C
	Event* mEvents;           // _70
	bool mBossActive;         // _74
	bool mIsClosed;           // _75
};

extern SeSystem* seSystem;
extern SeMgr* seMgr;

#endif
