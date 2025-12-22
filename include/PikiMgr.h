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
 * @brief Parameters for controlling piki behaviour, dynamics, and visuals.
 *
 * @note Size: 0x52C.
 */
struct PikiProp : public CreatureProp {
	PikiProp() { mCreatureProps.mFriction(0.1f); }

	/**
	 * @brief Nested struct for piki-specific parameters.
	 *
	 * @note Offsets are relative to PikiProp for convenience.
	 */
	struct Parms : public Parameters {
		Parms()
		    : mMinMoveSpeed(this, 84.0f, 0.0f, 500.0f, "p00", "歩く速度")
		    , mMaxLeafMoveSpeed(this, 162.5f, 0.0f, 500.0f, "p01", "走る速度")
		    , mMaxFlowerMoveSpeed(this, 220.0f, 0.0f, 500.0f, "p54", "花ピキスピード")
		    , mMaxBudMoveSpeed(this, 160.0f, 0.0f, 500.0f, "p65", "つぼみスピード")
		    , mPikiDisplayScale(this, 1.0f, 0.1f, 10.0f, "p38", "ピキ表示スケール")
		    , mPikiMaxHealth(this, 100.0f, 0.0f, 1000.0f, "p03", "標準ライフ")
		    , mSkinnyPikiHealth(this, 150.0f, 0.0f, 1000.0f, "p10", "のっぽライフ")
		    , mFatPikiHealth(this, 200.0f, 0.0f, 1000.0f, "p11", "でぶライフ")
		    , mBlueAttackPower(this, 10.0f, 0.0f, 1000.0f, "p04", "青 攻撃力")
		    , mRedAttackPower(this, 15.0f, 0.0f, 1000.0f, "p12", "赤 攻撃力")
		    , mYellowAttackPower(this, 10.0f, 0.0f, 1000.0f, "p13", "黄 攻撃力")
		    , mBudEnergyRequirement(this, 1, 1, 100, "p05", "つぼみに必要なエネルギー数")
		    , mFlowerEnergyRequirement(this, 2, 1, 100, "p06", "花に必要なエネルギー数")
		    , mPluckStrength0(this, 0.8f, 0.0f, 2.0f, "p07", "ノーマルピキのスケール")
		    , mPluckStrength1(this, 1.5f, 0.0f, 2.0f, "p08", "のっぽピキのスケール")
		    , mPluckStrength2(this, 1.2f, 0.0f, 2.0f, "p09", "ふとっちょピキのスケール")
		    , mPressDeathFactor(this, 5.0f, 0.0f, 10.0f, "p14", "つぶれ総時間")
		    , mNormalPikiPressFactor(this, 3.0f, 0.0f, 10.0f, "p15", "ぺったんこ時間")
		    , mWildPikiPressFactor(this, 1.0f, 0.0f, 10.0f, "p16", "波時間")
		    , mFatPikiPressFactor(this, 40.0f, 0.0f, 200.0f, "p37", "Wave Attac 攻撃範囲")
		    , mStepSpeedThreshold(this, 5.0f, 0.0f, 500.0f, "p17", "ASIBUMI 開始スピード")
		    , mWalkSpeedThreshold(this, 35.0f, 0.0f, 500.0f, "p18", "WALK 開始スピード")
		    , mRunSpeedThreshold(this, 70.0f, 0.0f, 500.0f, "p19", "RUN 開始スピード")
		    , mEscapeSpeedThreshold(this, 160.0f, 0.0f, 500.0f, "p20", "ESCAPE 開始スピード")
		    , mMinWalkAnimSpeed(this, 30.0f, 0.0f, 300.0f, "p21", "WALK 再生フレーム数(min)")
		    , mMaxWalkAnimSpeed(this, 60.0f, 0.0f, 300.0f, "p22", "WALK 再生フレーム数(max)")
		    , mMinRunAnimSpeed(this, 30.0f, 0.0f, 300.0f, "p23", "RUN 再生フレーム数(min)")
		    , mMaxRunAnimSpeed(this, 60.0f, 0.0f, 300.0f, "p24", "RUN 再生フレーム数(max)")
		    , mEscapeAnimSpeed(this, 30.0f, 0.0f, 300.0f, "p25", "ESCAPE 再生フレーム数(min)")
		    , mUnusedAnimSpeed(this, 60.0f, 0.0f, 300.0f, "p26", "ESCAPE 再生フレーム数(max)")
		    , mMinPikiSize(this, 6.0f, 0.0f, 100.0f, "p27", "当たりサイズ(min)")
		    , mMaxPikiSize(this, 10.0f, 0.0f, 100.0f, "p34", "当たりサイズ(max)")
		    , mInvMass(this, 100.0f, 0.0f, 2000.0f, "p28", "重さの逆数")
		    , mCollisionRadius(this, 8.0f, 0.0f, 100.0f, "p39", "地面当たりサイズ")
		    , mFormationSlipRange(this, 600.0f, 0.0f, 10000.0f, "p29", "white 距離")
		    , mFormationBreakRange(this, 1000.0f, 0.0f, 10000.0f, "p30", "gray 距離")
		    , mMaxLostChildTime(this, 10.0f, 0.0f, 1000.0f, "p31", "迷子時間")
		    , mUnusedWhiteFreeDistance(this, 200.0f, 0.0f, 10000.0f, "p32", "white 距離(Free)")
		    , mUnusedGrayFreeDistance(this, 800.0f, 0.0f, 10000.0f, "p33", "gray 距離(Free)")
		    , mUnusedDynWallPushTime(this, 0.6f, 0.0f, 10.0f, "p35", "壁を押し始める時間(Dynamic)")
		    , mUnusedStaticWallPushTime(this, 0.6f, 0.0f, 10.0f, "p36", "壁を押し始める時間(Static)")
		    , mDefaultFreeBoidTime(this, 15.0f, 1.0f, 1080.0f, "p40", "フリーになるまでの時間")
		    , mIdleAttackSearchRange(this, 100.0f, 1.0f, 1000.0f, "p41", "敵のサーチエリア")
		    , mIdleWorkSearchRange(this, 100.0f, 1.0f, 1000.0f, "p42", "Gem のサーチエリア")
		    , mMaxFlickKnockDownTime(this, 0.7f, 0.0f, 10.0f, "p43", "はじかれて起きるまでの最長時間")
		    , mMinFlickKnockDownTime(this, 0.7f, 0.0f, 10.0f, "p74", "はじかれて起きるまでの最小時間")
		    , mUnusedLeafBudTime(this, 10.0f, 1.0f, 1000.0f, "p44", "leaf->bud    の時間（秒）")
		    , mUnusedBudFlowerTime(this, 10.0f, 1.0f, 1000.0f, "p45", "bud->flower  の時間（秒）")
		    , mUnusedFlowerSeedTime(this, 10.0f, 1.0f, 1000.0f, "p46", "flower->seed の時間（秒）")
		    , mUnusedSeedLeafTime(this, 10.0f, 1.0f, 1000.0f, "p47", "seed->leaf   の時間（秒）")
		    , mFlowerGravityScale(this, 0.01f, 0.0f, 1.0f, "p48", "花ピキ重力率")
		    , mSeedUpTime(this, 1.0f, 0.0f, 300.0f, "p49", "taneupTime（秒）")
		    , mPluckWaitTime(this, 1.0f, 0.0f, 300.0f, "p50", "hatugaTime（秒）")
		    , mGrowUpTime(this, 4.0f, 0.0f, 300.0f, "p51", "growupTime（秒）")
		    , mWiltTime(this, 4.0f, 0.0f, 300.0f, "p52", "kareTime（秒）")
		    , mRebirthSeedTime(this, 1.0f, 0.0f, 300.0f, "p53", "rebirthTime（秒）")
		    , mPanicTime(this, 3.0f, 0.0f, 30.0f, "p55", "火に包まれて死ぬまでの時間")
		    , mPikiLeaveSeedChance(this, 0.8f, 0.0f, 1.0f, "p56", "花ピキが種として再生する確率")
		    , mBombSetFuseTime(this, 2.0f, 0.0f, 60.0f, "p57", "爆発までの時間")
		    , mBombExplodeRadius(this, 50.0f, 0.0f, 1000.0f, "p58", "爆弾効果範囲")
		    , mBombDamageBomb(this, 200.0f, 0.0f, 1000.0f, "p59", "爆弾ダメージ量 水門")
		    , mBombDamageNavi(this, 10.0f, 0.0f, 1000.0f, "p75", "爆弾ダメージ Orima")
		    , mBombDamageEnemy(this, 120.0f, 0.0f, 1000.0f, "p76", "爆弾ダメージ Teki")
		    , mBombDamagePiki(this, 765.0f, 0.0f, 1000.0f, "p77", "爆弾ダメージ Piki")
		    , mSunsetSafetyRange(this, 200.0f, 0.0f, 5000.0f, "p60", "日没生き残り範囲")
		    , mPostWorkJoinPartyRange(this, 250.0f, 0.0f, 5000.0f, "p61", "隊列起動距離")
		    , mMinStartDrownFrames(this, 30, 0, 300, "p62", "おぼれフレーム数")
		    , mRandStartDrownFrames(this, 10, 0, 300, "p63", "おぼれフレーム数（ばらつき）")
		    , mUnusedPushTime(this, 5.0f, 1.0f, 120.0f, "p64", "壁押しあきらめ時間")
		    , mBombTargetSearchRange(this, 300.0f, 0.0f, 1000.0f, "p66", "BOMB サーチ距離")
		    , mBombThrowMinDistance(this, 110.0f, 0.0f, 1000.0f, "p67", "BOMB throw Min")
		    , mBombThrowMaxDistance(this, 160.0f, 0.0f, 1000.0f, "p68", "BOMB throw Max")
		    , mBombThrowTimeoutTime(this, 1.5f, 0.0f, 60.0f, "p69", "BOMB 置き逃げ時間")
		    , mBombThrowSpeed(this, 150.0f, 0.0f, 1000.0f, "p70", "BOMB 投げスピード")
		    , mBombWarnPikiRange(this, 300.0f, 0.0f, 1000.0f, "p71", "BOMB 警告範囲")
		    , mBombAimTime(this, 0.65f, 0.0f, 10.0f, "p72", "BOMB 間、タイム")
		    , mBombSetDistance(this, 50.0f, 0.0f, 1000.0f, "p73", "BOMB セット距離")
		{
		}

		// _58-_5C = Parameters
		Parm<f32> mMinMoveSpeed;             // _5C, p00 - walking speed
		Parm<f32> mMaxLeafMoveSpeed;         // _6C, p01 - running speed
		Parm<f32> mMaxFlowerMoveSpeed;       // _7C, p54 - flower piki speed
		Parm<f32> mMaxBudMoveSpeed;          // _8C, p65 - bud piki speed
		Parm<f32> mPikiDisplayScale;         // _9C, p38 - only used for "pressed" rescaling and restoring afterwards
		Parm<f32> mPikiMaxHealth;            // _AC, p03 - max health (but always instakilled)
		Parm<f32> mSkinnyPikiHealth;         // _BC, p10 - unused, named from DLL text
		Parm<f32> mFatPikiHealth;            // _CC, p11 - unused, named from DLL text
		Parm<f32> mBlueAttackPower;          // _DC, p04 - blue pikmin attack power
		Parm<f32> mRedAttackPower;           // _EC, p12 - red pikmin attack power
		Parm<f32> mYellowAttackPower;        // _FC, p13 - yellow/other pikmin attack power
		Parm<int> mBudEnergyRequirement;     // _10C, p05 - unused, named from DLL text
		Parm<int> mFlowerEnergyRequirement;  // _11C, p06 - unused, named from DLL text
		Parm<f32> mPluckStrength0;           // _12C, p07 - unused, from some abandoned behaviour
		Parm<f32> mPluckStrength1;           // _13C, p08 - unused, from some abandoned behaviour
		Parm<f32> mPluckStrength2;           // _14C, p09 - unused, from some abandoned behaviour
		Parm<f32> mPressDeathFactor;         // _15C, p14 - total time to die from crushing/also controls press scale
		Parm<f32> mNormalPikiPressFactor;    // _16C, p15 - related to scale normal piki expands to when pressed/crushed
		Parm<f32> mWildPikiPressFactor;      // _17C, p16 - unused, named from DLL text
		Parm<f32> mFatPikiPressFactor;       // _18C, p37 - unused, named from DLL text
		Parm<f32> mStepSpeedThreshold;       // _19C, p17 - below this = Wait anim, above this = Asibumi anim
		Parm<f32> mWalkSpeedThreshold;       // _1AC, p18 - below this = Asibumi anim, above this = Walk anim
		Parm<f32> mRunSpeedThreshold;        // _1BC, p19 - below this = Walk anim, above this = Run anim
		Parm<f32> mEscapeSpeedThreshold;     // _1CC, p20 - below this = Run anim, above this = Nigeru anim
		Parm<f32> mMinWalkAnimSpeed;         // _1DC, p21 - slowest fps to do walk animation at
		Parm<f32> mMaxWalkAnimSpeed;         // _1EC, p22 - fastest fps to do walk animation at
		Parm<f32> mMinRunAnimSpeed;          // _1FC, p23 - slowest fps to do run animation at
		Parm<f32> mMaxRunAnimSpeed;          // _20C, p24 - fastest fps to do run animation at
		Parm<f32> mEscapeAnimSpeed;          // _21C, p25 - fps to do escape animation at
		Parm<f32> mUnusedAnimSpeed;          // _22C, p26 - unused, probably another anim speed
		Parm<f32> mMinPikiSize;              // _23C, p27 - used for some niche things (shadow scale, culling, default collisions)
		Parm<f32> mMaxPikiSize;              // _24C, p34 - pikis are randomly assigned between mMinPikiSize and mMaxPikiSize on init
		Parm<f32> mInvMass;                  // _25C, p28 - inverse mass for collision calcs
		Parm<f32> mCollisionRadius;          // _26C, p39 - radius for collision calcs
		Parm<f32> mFormationSlipRange;       // _27C, p29 - if piki is this far or more from its squad slot, reassign it a new slot
		Parm<f32> mFormationBreakRange;      // _28C, p30 - if piki is this far or more from its squad slot, remove it from party
		Parm<f32> mMaxLostChildTime;         // _29C, p31 - if piki has been in "slip" range for this much time, remove it from party
		Parm<f32> mUnusedWhiteFreeDistance;  // _2AC, p32 - unused - white = "slip range", unsure of purpose
		Parm<f32> mUnusedGrayFreeDistance;   // _2BC, p33 - unused - gray = "break range", unsure of purpose
		Parm<f32> mUnusedDynWallPushTime;    // _2CC, p35 - unused, named from DLL text
		Parm<f32> mUnusedStaticWallPushTime; // _2DC, p36 - unused, named from DLL text
		Parm<f32> mDefaultFreeBoidTime;      // _2EC, p40 - default timer to use when making dismiss groups
		Parm<f32> mIdleAttackSearchRange;    // _2FC, p41 - range to look for enemies, bridges and bomb spawners while idle
		Parm<f32> mIdleWorkSearchRange;      // _30C, p42 - range to look for pellets, grass, loose bombs, walls, sticks while idle
		Parm<f32> mMaxFlickKnockDownTime;    // _31C, p43 - max time to stay knocked down for after getting flicked
		Parm<f32> mMinFlickKnockDownTime;    // _32C, p74 - min time to stay knocked down for after getting flicked (random between)
		Parm<f32> mUnusedLeafBudTime;        // _33C, p44 - unused, probably related to GrowState
		Parm<f32> mUnusedBudFlowerTime;      // _34C, p45 - unused, probably related to GrowState
		Parm<f32> mUnusedFlowerSeedTime;     // _35C, p46 - unused, probably related to GrowState
		Parm<f32> mUnusedSeedLeafTime;       // _36C, p47 - unused, probably related to GrowState
		Parm<f32> mFlowerGravityScale;       // _37C, p48 - scaling factor used to modify flower piki throw trajectories
		Parm<f32> mSeedUpTime;               // _38C, p49 - time until visible after getting planted
		Parm<f32> mPluckWaitTime;            // _39C, p50 - time until pluckable when planted
		Parm<f32> mGrowUpTime;               // _3AC, p51 - time from seed -> bud and bud -> flower
		Parm<f32> mWiltTime;                 // _3BC, p52 - time from flower -> back to seed
		Parm<f32> mRebirthSeedTime;          // _3CC, p53 - time after wilting before seed pops back up
		Parm<f32> mPanicTime;                // _3DC, p55 - time to flail when on fire/bubbled before death
		Parm<f32> mPikiLeaveSeedChance;      // _3EC, p56 - chance for a flower to leave a seed upon death
		Parm<f32> mBombSetFuseTime;          // _3FC, p57 - time until a bomb explodes after being set down by a piki
		Parm<f32> mBombExplodeRadius;        // _40C, p58 - explosion radius to damage things within upon bomb detonation
		Parm<f32> mBombDamageBomb;           // _41C, p59 - damage bombs deal to other bombs; DLL name suggests it was meant for walls
		Parm<f32> mBombDamageNavi;           // _42C, p75 - damage bombs deal to captains (and walls!)
		Parm<f32> mBombDamageEnemy;          // _43C, p76 - damage bombs deal to tekis and bosses
		Parm<f32> mBombDamagePiki;           // _44C, p77 - damage bombs deal to pikis
		Parm<f32> mSunsetSafetyRange;        // _45C, p60 - radius around onions and ship that pikis are "safe" within at sunset
		Parm<f32> mPostWorkJoinPartyRange;   // _46C, p61 - max navi-piki range to rejoin squad after finishing an action
		Parm<int> mMinStartDrownFrames;      // _47C, p62 - min frames from water contact to going into drown state
		Parm<int> mRandStartDrownFrames;     // _48C, p63 - actual drown transit starts between min frames and (min + rand) frames
		Parm<f32> mUnusedPushTime;           // _49C, p64 - unused, sets a(n unused) variable in ActPush
		Parm<f32> mBombTargetSearchRange;    // _4AC, p66 - how far to look for bomb (set or throw) targets (tekis, bosses, walls)
		Parm<f32> mBombThrowMinDistance;     // _4BC, p67 - must be at least this far away from target to throw bomb
		Parm<f32> mBombThrowMaxDistance;     // _4CC, p68 - must be at least this close to target to throw bomb
		Parm<f32> mBombThrowTimeoutTime;     // _4DC, p69 - if we're too close for this amount of time, stop trying to throw and drop it
		Parm<f32> mBombThrowSpeed;           // _4EC, p70 - horizontal speed to throw bomb at
		Parm<f32> mBombWarnPikiRange;        // _4FC, p71 - range to "warn" pikis within when bomb is thrown or set
		Parm<f32> mBombAimTime;              // _50C, p72 - time to "aim" before trying to throw bomb
		Parm<f32> mBombSetDistance;          // _51C, p73 - if we're within this distance of a wall, set the bomb
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
