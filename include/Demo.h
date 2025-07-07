#ifndef _DEMO_H
#define _DEMO_H

#include "GlobalGameOptions.h"
#include "Node.h"
#include "Parameters.h"
#include "types.h"

struct Creature;

/**
 * @brief TODO
 */
enum EDemoFlags {
	DEMOFLAG_NULL                = -1,
	DEMOFLAG_DiscoverRedOnyon    = 0,
	DEMOFLAG_DiscoverYellowOnyon = 1,
	DEMOFLAG_DiscoverBlueOnyon   = 2,
	DEMOFLAG_ApproachSeed        = 3,
	DEMOFLAG_PluckRedPikmin      = 4,
	DEMOFLAG_PluckYellowPikmin   = 5,
	DEMOFLAG_PluckBluePikmin     = 6,
	DEMOFLAG_NoPikminTimeout     = 7,
	DEMOFLAG_CameraInfo          = 8,
	DEMOFLAG_Unk9                = 9, // 'pellet grass battle timeout'
	DEMOFLAG_CollectFirstPellet  = 10,
	DEMOFLAG_FirstSluiceDown     = 11,
	DEMOFLAG_ApproachEngine      = 12,
	DEMOFLAG_CollectEngine       = 13,
	DEMOFLAG_StartBoxPush        = 14,
	DEMOFLAG_FinishBoxPush       = 15,
	DEMOFLAG_OnyonMenuInfo       = 16,
	DEMOFLAG_PostExtinctionSeed  = 17,
	DEMOFLAG_GrabFirstBomb       = 18,
	DEMOFLAG_FirstHurryUp        = 19,
	DEMOFLAG_FirstBombExplode    = 20,

	DEMOFLAG_PikminLimitOffset = 21, // each course's "you've exceeded 100 pikmin" text is this + stageID

	DEMOFLAG_PikminLimitTutorial    = 21,
	DEMOFLAG_PikminLimitForest      = 22,
	DEMOFLAG_PikminLimitCave        = 23,
	DEMOFLAG_PikminLimitYakushima   = 24,
	DEMOFLAG_PikminLimitLast        = 25,
	DEMOFLAG_FirstNectar            = 26,
	DEMOFLAG_FirstBombDeath         = 27,
	DEMOFLAG_CarryPathBlocked       = 28,
	DEMOFLAG_OlimarLowHealth        = 29,
	DEMOFLAG_Pluck15thPikmin        = 30,
	DEMOFLAG_FirstNoon              = 31,
	DEMOFLAG_UfoPartDiscoveryOffset = 32, // each part's discovery text is this + partID

	DEMOFLAG_COUNT = DEMOFLAG_UfoPartDiscoveryOffset + MAX_UFO_PARTS + 1,
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

		Parm<f32> mOnionBootTriggerRadius; // _24
		Parm<f32> mSeedDemoTriggerRadius;  // _34
		Parm<f32> mSeedDemoWaitTime;       // _44
		Parm<f32> _30;                     // _54
		Parm<f32> mDemoTriggerRadius;      // _64
	};

	DemoParms();

	virtual void read(RandomAccessStream& data) { mParms.read(data); } // _0C

	// _00     = VTBL
	// _00-_20 = Node
	Parms mParms; // _20
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

	int getEventMax() { return 6; }
	int getSenderMax() { return 0x20; }

	// no members
};

extern DemoEventMgr* demoEventMgr;
extern DemoParms* demoParms;

#endif
