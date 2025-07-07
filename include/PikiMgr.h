#ifndef _PIKIMGR_H
#define _PIKIMGR_H

#include "CreatureProp.h"
#include "ObjectMgr.h"
#include "ViewPiki.h"
#include "types.h"

struct Navi;
struct CPlate;

/**
 * @brief TODO
 */
enum PikiMgrRefreshFlags {
	PMREF_FreePiki      = 0x1,
	PMREF_FormationPiki = 0x2,
	PMREF_WorkPiki      = 0x4,
	PMREF_Unk4          = 0x8,
};

/**
 * @brief TODO
 */
enum PikiMgrUpdatingFlags {
	PMUPDATE_FreePiki      = 0x1,
	PMUPDATE_FormationPiki = 0x2,
	PMUPDATE_WorkPiki      = 0x4,
	PMUPDATE_Unk4          = 0x8,
};

/**
 * @brief TODO
 */
struct PikiProp : public CreatureProp {
	PikiProp() { mCreatureProps.mFriction(0.1f); }

	/**
	 * @brief TODO
	 *
	 * @note Offsets are relative to PikiProp for convenience.
	 */
	struct Parms : public Parameters {
		Parms()
		    : mMinMoveSpeed(this, 84.0f, 0.0f, 500.0f, "p00", nullptr)
		    , mMaxLeafMoveSpeed(this, 162.5f, 0.0f, 500.0f, "p01", nullptr)
		    , mMaxFlowerMoveSpeed(this, 220.0f, 0.0f, 500.0f, "p54", nullptr)
		    , mMaxBudMoveSpeed(this, 160.0f, 0.0f, 500.0f, "p65", nullptr)
		    , mPikiDisplayScale(this, 1.0f, 0.1f, 10.0f, "p38", nullptr)
		    , mPikiHealth(this, 100.0f, 0.0f, 1000.0f, "p03", nullptr)
		    , mSkinnyPikiHealth(this, 150.0f, 0.0f, 1000.0f, "p10", nullptr)
		    , mFatPikiHealth(this, 200.0f, 0.0f, 1000.0f, "p11", nullptr)
		    , mBlueAttackPower(this, 10.0f, 0.0f, 1000.0f, "p04", nullptr)
		    , mRedAttackPower(this, 15.0f, 0.0f, 1000.0f, "p12", nullptr)
		    , mYellowAttackPower(this, 10.0f, 0.0f, 1000.0f, "p13", nullptr)
		    , mBudEnergyRequirement(this, 1, 1, 100, "p05", nullptr)
		    , mFlowerEnergyRequirement(this, 2, 1, 100, "p06", nullptr)
		    , _12C(this, 0.8f, 0.0f, 2.0f, "p07", nullptr)
		    , _13C(this, 1.5f, 0.0f, 2.0f, "p08", nullptr)
		    , _14C(this, 1.2f, 0.0f, 2.0f, "p09", nullptr)
		    , _15C(this, 5.0f, 0.0f, 10.0f, "p14", nullptr)
		    , _16C(this, 3.0f, 0.0f, 10.0f, "p15", nullptr)
		    , _17C(this, 1.0f, 0.0f, 10.0f, "p16", nullptr)
		    , _18C(this, 40.0f, 0.0f, 200.0f, "p37", nullptr)
		    , _19C(this, 5.0f, 0.0f, 500.0f, "p17", nullptr)
		    , _1AC(this, 35.0f, 0.0f, 500.0f, "p18", nullptr)
		    , _1BC(this, 70.0f, 0.0f, 500.0f, "p19", nullptr)
		    , _1CC(this, 160.0f, 0.0f, 500.0f, "p20", nullptr)
		    , _1DC(this, 30.0f, 0.0f, 300.0f, "p21", nullptr)
		    , _1EC(this, 60.0f, 0.0f, 300.0f, "p22", nullptr)
		    , _1FC(this, 30.0f, 0.0f, 300.0f, "p23", nullptr)
		    , _20C(this, 60.0f, 0.0f, 300.0f, "p24", nullptr)
		    , _21C(this, 30.0f, 0.0f, 300.0f, "p25", nullptr)
		    , _22C(this, 60.0f, 0.0f, 300.0f, "p26", nullptr)
		    , _23C(this, 6.0f, 0.0f, 100.0f, "p27", nullptr)
		    , _24C(this, 10.0f, 0.0f, 100.0f, "p34", nullptr)
		    , _25C(this, 100.0f, 0.0f, 2000.0f, "p28", nullptr)
		    , mCollisionRadius(this, 8.0f, 0.0f, 100.0f, "p39", nullptr)
		    , _27C(this, 600.0f, 0.0f, 10000.0f, "p29", nullptr)
		    , _28C(this, 1000.0f, 0.0f, 10000.0f, "p30", nullptr)
		    , _29C(this, 10.0f, 0.0f, 1000.0f, "p31", nullptr)
		    , _2AC(this, 200.0f, 0.0f, 10000.0f, "p32", nullptr)
		    , _2BC(this, 800.0f, 0.0f, 10000.0f, "p33", nullptr)
		    , _2CC(this, 0.6f, 0.0f, 10.0f, "p35", nullptr)
		    , _2DC(this, 0.6f, 0.0f, 10.0f, "p36", nullptr)
		    , _2EC(this, 15.0f, 1.0f, 1080.0f, "p40", nullptr)
		    , _2FC(this, 100.0f, 1.0f, 1000.0f, "p41", nullptr)
		    , _30C(this, 100.0f, 1.0f, 1000.0f, "p42", nullptr)
		    , _31C(this, 0.7f, 0.0f, 10.0f, "p43", nullptr)
		    , _32C(this, 0.7f, 0.0f, 10.0f, "p74", nullptr)
		    , _33C(this, 10.0f, 1.0f, 1000.0f, "p44", nullptr)
		    , _34C(this, 10.0f, 1.0f, 1000.0f, "p45", nullptr)
		    , _35C(this, 10.0f, 1.0f, 1000.0f, "p46", nullptr)
		    , _36C(this, 10.0f, 1.0f, 1000.0f, "p47", nullptr)
		    , _37C(this, 0.01f, 0.0f, 1.0f, "p48", nullptr)
		    , _38C(this, 1.0f, 0.0f, 300.0f, "p49", nullptr)
		    , _39C(this, 1.0f, 0.0f, 300.0f, "p50", nullptr)
		    , _3AC(this, 4.0f, 0.0f, 300.0f, "p51", nullptr)
		    , _3BC(this, 4.0f, 0.0f, 300.0f, "p52", nullptr)
		    , _3CC(this, 1.0f, 0.0f, 300.0f, "p53", nullptr)
		    , _3DC(this, 3.0f, 0.0f, 30.0f, "p55", nullptr)
		    , mPikiLeaveSeedChance(this, 0.8f, 0.0f, 1.0f, "p56", nullptr)
		    , _3FC(this, 2.0f, 0.0f, 60.0f, "p57", nullptr)
		    , _40C(this, 50.0f, 0.0f, 1000.0f, "p58", nullptr)
		    , _41C(this, 200.0f, 0.0f, 1000.0f, "p59", nullptr)
		    , _42C(this, 10.0f, 0.0f, 1000.0f, "p75", nullptr)
		    , _43C(this, 120.0f, 0.0f, 1000.0f, "p76", nullptr)
		    , _44C(this, 765.0f, 0.0f, 1000.0f, "p77", nullptr)
		    , _45C(this, 200.0f, 0.0f, 5000.0f, "p60", nullptr)
		    , _46C(this, 250.0f, 0.0f, 5000.0f, "p61", nullptr)
		    , _47C(this, 30, 0, 300, "p62", nullptr)
		    , _48C(this, 10, 0, 300, "p63", nullptr)
		    , _49C(this, 5.0f, 1.0f, 120.0f, "p64", nullptr)
		    , mBombTargetSearchRadius(this, 300.0f, 0.0f, 1000.0f, "p66", nullptr)
		    , mBombPlaceMinDistance(this, 110.0f, 0.0f, 1000.0f, "p67", nullptr)
		    , mBombThrowMaxDistance(this, 160.0f, 0.0f, 1000.0f, "p68", nullptr)
		    , mBombPlaceDuration(this, 1.5f, 0.0f, 60.0f, "p69", nullptr)
		    , _4EC(this, 150.0f, 0.0f, 1000.0f, "p70", nullptr)
		    , _4FC(this, 300.0f, 0.0f, 1000.0f, "p71", nullptr)
		    , _50C(this, 0.65f, 0.0f, 10.0f, "p72", nullptr)
		    , _51C(this, 50.0f, 0.0f, 1000.0f, "p73", nullptr)
		{
		}

		// _58-_5C = Parameters
		Parm<f32> mMinMoveSpeed;            // _5C, p00 - walking speed?
		Parm<f32> mMaxLeafMoveSpeed;        // _6C, p01 - running speed?
		Parm<f32> mMaxFlowerMoveSpeed;      // _7C, p54 - flower piki speed?
		Parm<f32> mMaxBudMoveSpeed;         // _8C, p65 - bud piki speed?
		Parm<f32> mPikiDisplayScale;        // _9C, p38
		Parm<f32> mPikiHealth;              // _AC, p03
		Parm<f32> mSkinnyPikiHealth;        // _BC, p10 - unused
		Parm<f32> mFatPikiHealth;           // _CC, p11 - unused
		Parm<f32> mBlueAttackPower;         // _DC, p04
		Parm<f32> mRedAttackPower;          // _EC, p12
		Parm<f32> mYellowAttackPower;       // _FC, p13
		Parm<int> mBudEnergyRequirement;    // _10C, p05
		Parm<int> mFlowerEnergyRequirement; // _11C, p06
		Parm<f32> _12C;                     // _12C, p07
		Parm<f32> _13C;                     // _13C, p08
		Parm<f32> _14C;                     // _14C, p09
		Parm<f32> _15C;                     // _15C, p14
		Parm<f32> _16C;                     // _16C, p15 - scale normal piki?
		Parm<f32> _17C;                     // _17C, p16 - scale wild piki?
		Parm<f32> _18C;                     // _18C, p37 - fatty piki scale?
		Parm<f32> _19C;                     // _19C, p17
		Parm<f32> _1AC;                     // _1AC, p18
		Parm<f32> _1BC;                     // _1BC, p19
		Parm<f32> _1CC;                     // _1CC, p20
		Parm<f32> _1DC;                     // _1DC, p21
		Parm<f32> _1EC;                     // _1EC, p22
		Parm<f32> _1FC;                     // _1FC, p23
		Parm<f32> _20C;                     // _20C, p24
		Parm<f32> _21C;                     // _21C, p25
		Parm<f32> _22C;                     // _22C, p26
		Parm<f32> _23C;                     // _23C, p27
		Parm<f32> _24C;                     // _24C, p34
		Parm<f32> _25C;                     // _25C, p28
		Parm<f32> mCollisionRadius;         // _26C, p39
		Parm<f32> _27C;                     // _27C, p29
		Parm<f32> _28C;                     // _28C, p30
		Parm<f32> _29C;                     // _29C, p31
		Parm<f32> _2AC;                     // _2AC, p32
		Parm<f32> _2BC;                     // _2BC, p33
		Parm<f32> _2CC;                     // _2CC, p35
		Parm<f32> _2DC;                     // _2DC, p36
		Parm<f32> _2EC;                     // _2EC, p40
		Parm<f32> _2FC;                     // _2FC, p41
		Parm<f32> _30C;                     // _30C, p42
		Parm<f32> _31C;                     // _31C, p43
		Parm<f32> _32C;                     // _32C, p74
		Parm<f32> _33C;                     // _33C, p44
		Parm<f32> _34C;                     // _34C, p45
		Parm<f32> _35C;                     // _35C, p46
		Parm<f32> _36C;                     // _36C, p47
		Parm<f32> _37C;                     // _37C, p48
		Parm<f32> _38C;                     // _38C, p49
		Parm<f32> _39C;                     // _39C, p50
		Parm<f32> _3AC;                     // _3AC, p51
		Parm<f32> _3BC;                     // _3BC, p52
		Parm<f32> _3CC;                     // _3CC, p53
		Parm<f32> _3DC;                     // _3DC, p55
		Parm<f32> mPikiLeaveSeedChance;     // _3EC, p56, chance for a flower to leave a seed upon death
		Parm<f32> _3FC;                     // _3FC, p57
		Parm<f32> _40C;                     // _40C, p58
		Parm<f32> _41C;                     // _41C, p59
		Parm<f32> _42C;                     // _42C, p75
		Parm<f32> _43C;                     // _43C, p76
		Parm<f32> _44C;                     // _44C, p77
		Parm<f32> _45C;                     // _45C, p60
		Parm<f32> _46C;                     // _46C, p61
		Parm<int> _47C;                     // _47C, p62
		Parm<int> _48C;                     // _48C, p63
		Parm<f32> _49C;                     // _49C, p64
		Parm<f32> mBombTargetSearchRadius;  // _4AC, p66,
		Parm<f32> mBombPlaceMinDistance;    // _4BC, p67, how far to look for targets
		Parm<f32> mBombThrowMaxDistance;    // _4CC, p68, maximum distance for throwing bomb
		Parm<f32> mBombPlaceDuration;       // _4DC, p69, minimum distance for placing bombs
		Parm<f32> _4EC;                     // _4EC, p70
		Parm<f32> _4FC;                     // _4FC, p71
		Parm<f32> _50C;                     // _50C, p72
		Parm<f32> _51C;                     // _51C, p73
	};

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mPikiParms.read(input);
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
	Parms mPikiParms; // _58
};

/**
 * @brief TODO
 *
 * @note Size: 0x74.
 */
struct PikiMgr : public MonoObjectMgr {
	PikiMgr(Navi*);

	virtual ~PikiMgr() { }                  // _48
	virtual void update();                  // _4C
	virtual void refresh(Graphics&);        // _58
	virtual Creature* birth();              // _78
	virtual Creature* createObject();       // _80
	virtual void read(RandomAccessStream&); // _84

	void init();
	void dumpAll();

	// unused/inlined:
	CPlate* getFormationPikis();
	bool lostAllPikis();
	void refresh2d(Graphics&);

	// 1 = free, 2 = formation, 4 = work
	bool isUpdating(u16 flag) { return mUpdateFlag & flag; }
	void setUpdateFlag(u16 flag) { mUpdateFlag |= flag; }

	bool isRefreshing(u16 flag) { return mRefreshFlag & flag; }
	void setRefreshFlag(u16 flag) { mRefreshFlag |= flag; }

	void hideAll()
	{
		mUpdateFlag  = 0;
		mRefreshFlag = 0;
	}

	static bool meNukiMode;
	static bool meBirthMode;

	static bool containerDebug;
	static bool containerExitMode;

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	Shape* mLeafModel[3];          // _3C
	Shape* mPikiShape;             // _48
	MapMgr* mMapMgr;               // _4C
	u32 _50;                       // _50
	u32 _54;                       // _54
	u32 _58;                       // _58
	u32 _5C;                       // _5C
	u32 mDeadPikis;                // _60
	PaniMotionTable* mMotionTable; // _64
	PikiProp* mPikiParms;          // _68
	Navi* mNavi;                   // _6C
	u16 mUpdateFlag;               // _70
	u16 mRefreshFlag;              // _72
};

extern PikiMgr* pikiMgr;

#endif
