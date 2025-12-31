#ifndef _PELLET_H
#define _PELLET_H

#include "CreatureProp.h"
#include "DualCreature.h"
#include "EffectMgr.h"
#include "ObjectMgr.h"
#include "PelletAnimator.h"
#include "PlayerState.h"
#include "Shape.h"
#include "StateMachine.h"
#include "types.h"

struct PaniAnimKeyEvent;
struct PaniMotionTable;
struct PelletShapeObject;
struct PelletStateMachine;
struct PelletView;
struct Shape;
struct RippleEffect;
struct Suckable;

/**
 * @brief TODO
 */
struct NumberPel {
	int mPelletColor; // _00
	int mPelletType;  // _04
	u32 mPelletID;    // _08
};

extern NumberPel numberPellets[13];

/**
 * @brief TODO
 */
enum PelletType {
	// Easier to label this separate, these will also have PelletColor as -1
	PELTYPE_Corpse = 0,

	// Blue, Red, Yellow pellets
	PELTYPE_Blue   = 0,
	PELTYPE_Red    = 1,
	PELTYPE_Yellow = 2,

	// Ship parts
	PELTYPE_UfoPart = 3,
};

/**
 * @brief TODO
 */
enum NumPelletType {
	NUMPEL_NULL         = -1,
	NUMPEL_OnePellet    = 0,
	NUMPEL_FivePellet   = 1,
	NUMPEL_TenPellet    = 2,
	NUMPEL_TwentyPellet = 3,
};

/**
 * @brief TODO
 */
enum PelletColor {
	PELCOLOR_Part = -2, // ship part (or other item, technically)

	PELCOLOR_NULL = -1,

	PELCOLOR_Blue   = 0,
	PELCOLOR_Red    = 1,
	PELCOLOR_Yellow = 2,

	PELCOLOR_MIN  = PELCOLOR_Blue,
	PELCOLOUR_MAX = PELCOLOR_Yellow,

	PELCOLOUR_COUNT,
};

/**
 * @brief Offset for pellet sound IDs associated with animations.
 *
 * @note Used with PaniAnimKeyEvent passing of sound IDs.
 * @note Add 0xBE to this to get SoundID offset.
 */
enum PelletAnimSoundID {
	PELSOUND_NONE     = -1,
	PELSOUND_Other    = 0,
	PELSOUND_Engine   = 1,
	PELSOUND_Gear     = 2,
	PELSOUND_Rader    = 3,
	PELSOUND_Spring   = 4,
	PELSOUND_Battery  = 5,
	PELSOUND_Zenmai   = 6,
	PELSOUND_MoneyBox = 7,
};

/**
 * @brief Index for bounce sounds used by Pellet.
 *
 * @note See bounceSounds table in pelletMgr.cpp
 */
enum PelletBounceSoundID {
	PELBOUNCE_NONE            = -1,
	PELBOUNCE_NormalPellet    = 0,
	PELBOUNCE_NormalUfoPart   = 1,
	PELBOUNCE_SpringUfoPart   = 2,
	PELBOUNCE_MoneyBoxUfoPart = 3,
	// everything else is unused, though bounceSounds has more entries
};

/**
 * @brief Index for UFO (ship) parts, usually referred to as UfoIndex.
 *
 * Soto = Outside (changes actual hull of the ship)
 * Fuzoku = Close friends (external changes to ship)
 * Naka = Inside (no visible changes)
 *
 * @note To convert to ID (e.g. 'uf01'), use PelletMgr::getUfoIDFromIndex.
 */
enum UfoPartIndex {
	UFO_NOPART            = -1, // No part found/invalid.
	UFO_Bowsprit          = 0,  // Soto 1
	UFO_GluonDrive        = 1,  // Soto 2
	UFO_AntiDioxinFilter  = 2,  // Soto 3
	UFO_EternalFuelDynamo = 3,  // Soto 4
	UFO_MainEngine        = 4,  // Soto 5
	UFO_WhimsicalRadar    = 5,  // Fuzoku 1
	UFO_InterstellarRadio = 6,  // Fuzoku 2
	UFO_GuardSatellite    = 7,  // Fuzoku 3
	UFO_ChronosReactor    = 8,  // Fuzoku 4
	UFO_RadiationCanopy   = 9,  // Fuzoku 5
	UFO_GeigerCounter     = 10, // Fuzoku 6
	UFO_Sagittarius       = 11, // Fuzoku 7
	UFO_Libra             = 12, // Fuzoku 8
	UFO_OmegaStabilizer   = 13, // Fuzoku 9
	UFO_IoniumJet1        = 14, // Fuzoku 10
	UFO_IoniumJet2        = 15, // Fuzoku 11
	UFO_ShockAbsorber     = 16, // Naka 1
	UFO_GravityJumper     = 17, // Naka 2
	UFO_PilotSeat         = 18, // Naka 3
	UFO_NovaBlaster       = 19, // Naka 4
	UFO_AutomaticGear     = 20, // Naka 5
	UFO_ZirconiumRotor    = 21, // Naka 6
	UFO_ExtraordinaryBolt = 22, // Naka 7
	UFO_RepairTypeBolt    = 23, // Naka 8
	UFO_SpaceFloat        = 24, // Naka 9
	UFO_MassageMachine    = 25, // Naka 10
	UFO_SecretSafe        = 26, // Naka 11
	UFO_PositronGenerator = 27, // Naka 12
	UFO_AnalogComputer    = 28, // Naka 13
	UFO_UVLamp            = 29, // Naka 14
	UFO_COUNT,                  // 30
	UFO_UNDEF = UFO_COUNT,      // 30, bad index
};

/**
 * @brief Part IDs for UFO (ship) parts, usually referred to as UfoID.
 *
 * @note To convert to index (e.g. 1, 5, 7), use PelletMgr::getUfoIndexFromID.
 */
enum UfoPartID {
	UFOID_Bowsprit          = 'ust1', // Soto 1
	UFOID_GluonDrive        = 'ust2', // Soto 2
	UFOID_AntiDioxinFilter  = 'ust3', // Soto 3
	UFOID_EternalFuelDynamo = 'ust4', // Soto 4
	UFOID_MainEngine        = 'ust5', // Soto 5
	UFOID_WhimsicalRadar    = 'uf01', // Fuzoku 1
	UFOID_InterstellarRadio = 'uf02', // Fuzoku 2
	UFOID_GuardSatellite    = 'uf03', // Fuzoku 3
	UFOID_ChronosReactor    = 'uf04', // Fuzoku 4
	UFOID_RadiationCanopy   = 'uf05', // Fuzoku 5
	UFOID_GeigerCounter     = 'uf06', // Fuzoku 6
	UFOID_Sagittarius       = 'uf07', // Fuzoku 7
	UFOID_Libra             = 'uf08', // Fuzoku 8
	UFOID_OmegaStabilizer   = 'uf09', // Fuzoku 9
	UFOID_IoniumJet1        = 'uf10', // Fuzoku 10
	UFOID_IoniumJet2        = 'uf11', // Fuzoku 11
	UFOID_ShockAbsorber     = 'un01', // Naka 1
	UFOID_GravityJumper     = 'un02', // Naka 2
	UFOID_PilotSeat         = 'un03', // Naka 3
	UFOID_NovaBlaster       = 'un04', // Naka 4
	UFOID_AutomaticGear     = 'un05', // Naka 5
	UFOID_ZirconiumRotor    = 'un06', // Naka 6
	UFOID_ExtraordinaryBolt = 'un07', // Naka 7
	UFOID_RepairTypeBolt    = 'un08', // Naka 8
	UFOID_SpaceFloat        = 'un09', // Naka 9
	UFOID_MassageMachine    = 'un10', // Naka 10
	UFOID_SecretSafe        = 'un11', // Naka 11
	UFOID_PositronGenerator = 'un12', // Naka 12
	UFOID_AnalogComputer    = 'un13', // Naka 13
	UFOID_UVLamp            = 'un14', // Naka 14
	UFOID_UNDEF             = 'udef',
};

/**
 * @brief TODO
 */
enum PelletMgrMovieFlags {
	PELMOVIE_Unk1 = 1 << 0, // 0x1
	PELMOVIE_Unk2 = 1 << 1, // 0x2
	PELMOVIE_Unk3 = 1 << 2, // 0x4
	PELMOVIE_Unk4 = 1 << 3, // 0x8
};

BEGIN_ENUM_TYPE(PelletMotionFlags)
enum {
	Unknown   = 1 << 0, // This doesn't mean anything, as it is enabled for all Pellets.
	UsePiston = 1 << 1, // This pellet has an upper animation, e.g. the Main Engine or Gluon Drive.
} END_ENUM_TYPE;

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct PelletProp : public CreatureProp {
	PelletProp() { mCreatureProps.mFriction(0.1f); }

	// _54     = VTBL
	// _00-_58 = CreatureProp
};

/**
 * @brief TODO
 */
struct PelletShapeObject {
	PelletShapeObject(immut char*, Shape*, immut char*, immut char*, int);

	bool isMotionFlag(u8 flag) { return mMotionFlag & flag; }
	void setMotionFlag(u8 flag) { mMotionFlag |= flag; }

	void genAge(AgeServer&);

	Shape* mShape;          // _00
	AnimMgr* mAnimMgr;      // _04
	AnimContext mAnimatorA; // _08
	AnimContext mAnimatorB; // _18
	u8 mMotionFlag;         // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x138.
 */
struct PelletConfig : public Parameters, public CoreNode {
	PelletConfig();

	// _04     = VTBL
	// _00-_04 = Parameters
	// _04-_18 = CoreNode
	Parm<String> mPelletName;         // _18, x99
	ID32 mModelId;                    // _2C
	ID32 mUnusedId;                   // _38
	ID32 mPelletId;                   // _44
	Parm<int> mPelletType;            // _50, p00
	Parm<int> mPelletColor;           // _60, p09
	Parm<int> mCarryMinPikis;         // _70, p01
	Parm<int> mCarryMaxPikis;         // _80, p02
	Parm<int> mUseDynamicMotion;      // _90, p03 - maybe model rotation when sucking into onyon?
	Parm<f32> _A0;                    // _A0, p04 - dynParm1?
	Parm<f32> _B0;                    // _B0, p05 - dynParm2?
	Parm<int> _C0;                    // _C0, p08 - dynCollNums?
	Parm<int> mMatchingOnyonSeeds;    // _D0, p06 - null produces fireworks
	Parm<int> mNonMatchingOnyonSeeds; // _E0, p07 - null produces fireworks
	Parm<f32> mPelletScale;           // _F0, p10
	Parm<f32> mCarryInfoHeight;       // _100, p11
	Parm<int> mAnimSoundID;           // _110, p12 - see PelletAnimSoundID enum
	Parm<int> mBounceSoundID;         // _120, p13
	int mRepairAnimJointIndex;        // _130

	// this has to be down here or the second VTBL spawns at 0x18 (should spawn at 0x134)

	virtual void read(RandomAccessStream&); // _18 (weak)

	void removeSelf(AgeServer&);

#ifdef WIN32
	virtual void genAge(AgeServer&);
	virtual void write(RandomAccessStream&);
#endif
};

/**
 * @brief TODO
 *
 * @note Size: 0x5BC.
 */
struct Pellet : public DualCreature, public PaniAnimKeyListener {
	friend struct PelletMgr;

public:
	Pellet();

	virtual void init(immut Vector3f&);                        // _28
	virtual void startAI(int);                                 // _34
	virtual f32 getiMass();                                    // _38
	virtual f32 getSize();                                     // _3C
	virtual f32 getCylinderHeight();                           // _44
	virtual void doSave(RandomAccessStream&);                  // _50
	virtual void doLoad(RandomAccessStream&);                  // _54
	virtual Vector3f getCentre();                              // _58
	virtual bool isVisible();                                  // _74
	virtual bool isAtari();                                    // _84
	virtual bool isAlive();                                    // _88
	virtual bool ignoreAtari(Creature*);                       // _98
	virtual bool isFree();                                     // _9C
	virtual bool stimulate(immut Interaction&);                // _A0
	virtual void collisionCallback(immut CollEvent&);          // _A8
	virtual void bounceCallback();                             // _AC
	virtual void startWaterEffect();                           // _CC
	virtual void finishWaterEffect();                          // _D0
	virtual void update();                                     // _E0
	virtual void postUpdate(int unused, f32 deltaTime);        // _E4
	virtual void refresh(Graphics&);                           // _EC
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _12C (weak)

	int getState();
	void setTrySound(bool);
	void startPick();
	void finishPick();
	void startGoal();
	void doCarry(Creature*, immut Vector3f&, u16);
	f32 getBottomRadius();
	bool startStickTeki(Creature*, f32);
	void endStickTeki(Creature*);
	bool winnable(int);
	bool stickSlot(int);
	void stickOffSlot(int);
	int getMinFreeSlotIndex();
	int getNearestFreeSlotIndex(immut Vector3f&);
	int getRandomFreeSlotIndex();
	Vector3f getSlotLocalPos(int, f32);
	Vector3f getSlotGlobalPos(int, f32);
	void startCarryMotion(f32);
	void finishMotion();

	// unused/inlined:
	void stopMotion();
	void startAppear();

	static bool isUfoPartsID(u32);

	AState<Pellet>* getCurrState() { return mCurrentState; }
	void setCurrState(AState<Pellet>* state) { mCurrentState = state; }

	void setMotionFlag(u8 flag) { mMotionFlag |= flag; }
	bool isMotionFlag(u8 flag) { return mMotionFlag & flag; }

	// this is just bool in the DLL, but seems to need to be BOOL/int to match initPellet
	BOOL isUfoParts()
	{
		if (mConfig) {
			return (mConfig->mPelletType() == PELTYPE_UfoPart);
		}
		return false;
	}

	bool isSlotFree(int slot) { return !isSlotFlag(slot); } // yeah actually.

	// DLL inlines to do:
	int getNearestFreeSlotIndex();

protected:
	virtual void doAnimation();                  // _108
	virtual void doKill();                       // _10C
	virtual void doRender(Graphics&, Matrix4f&); // _118
	virtual void doCreateColls(Graphics&);       // _11C

	void initSlotFlags();
	void setSlotFlag(int);
	void resetSlotFlag(int);
	bool isSlotFlag(int);

	void initPellet(PelletShapeObject*, PelletConfig*);
	void initPellet(PelletView*, PelletConfig*);

	// Some member variables (not grouped in any particular way) are directly accessed by a lot of stuff.
public:
	// _00       = VTBL1
	// _440      = VTBL2
	// _00-_440  = DualCreature
	// _440-_444 = PaniAnimKeyListener
	Vector3f mSpawnPosition;              // _444
	bool mUseSpawnPosition;               // _450
	bool mIsPlayTrySound;                 // _451
	u8 mMotionFlag;                       // _452
	RippleEffect* mRippleEffect;          // _454
	Suckable* mTargetGoal;                // _458
	CollPart* mStuckMouthPart;            // _45C
	f32 mStuckAngle;                      // _460
	Vector3f mLastPosition;               // _464
	PelletStateMachine* mStateMachine;    // _470
	AState<Pellet>* mCurrentState;        // _474
	Creature* mPikiCarrier;               // _478
	Vector3f mCarryDirection;             // _47C
	u16 mCarrierCount;                    // _488
	f32 mTransitionTimer;                 // _48C
	u16 mCarryState;                      // _490
	Vector3f mCurrentPelletPosition;      // _494
	u16 _4A0;                             // _4A0
	f32 mCurrentPelletHeight;             // _4A4
	PelletView* mPelletView;              // _4A8
	PelletAnimator mAnimator;             // _4AC
	PelletShapeObject* mShapeObject;      // _554
	u8 _558[0x4];                         // _558, unknown
	PelletConfig* mConfig;                // _55C
	f32 mMotionSpeed;                     // _560
	int mSlotFlags[3];                    // _564
	u16 mCarrierCounter;                  // _570
	CollInfo* mPelletCollInfo;            // _574
	SearchData mSearchData[4];            // _578
	ShapeDynMaterials mShapeDynMaterials; // _5A8
	bool mIsAlive;                        // _5B8
	bool mIsAIActive;                     // _5B9, name is a guess
};

/**
 * @brief TODO
 *
 * @note Size: 0x204.
 */
struct PelletMgr : public MonoObjectMgr {
	friend struct Pellet;

	// `PlayerState` is one of very few 100% confirmed breaches of interface in the codebase, as the ILK tells us the access modifiers
	// for all member functions.  `PlayerState::UfoParts` on the other hand is the single worst ambiguous breach of interface I've decided
	// to accept across the entire codebase (all protected member variables are guesses).  Because `PlayerState::UfoParts` is a child
	// struct, I must include the PlayerState header in its entirety to make it a friend in any way.  I want to believe the devs were
	// principled about proper encapsulation, but things like this make me question my faith.
	friend void PlayerState::registerUfoParts(int, u32, u32);        // Accesses `getShapeObject`.
	friend void PlayerState::UfoParts::initAnim(PelletShapeObject*); // Accesses `mUfoMotionTable`.

public:
	/**
	 * @brief TODO
	 */
	struct UseNode : public CoreNode {
		UseNode() { initCore("useNode"); }

		// _00     = VTBL
		// _00-_14 = CoreNode
		u32 mPelletID; // _14
	};

	PelletMgr(MapMgr*);

#ifdef WIN32
	virtual void genAge(AgeServer&);
#endif
	virtual ~PelletMgr() { }                // _48 (weak)
	virtual void refresh(Graphics&);        // _58
	virtual void read(RandomAccessStream&); // _84 (weak)

	bool decomposeNumberPellet(u32, int&, int&);
	void registerUfoParts();
	Pellet* newNumberPellet(int, int);
	Pellet* newPellet(u32, PelletView*);
	void addUseList(u32);
	void initShapeInfos();
	int getConfigIndex(u32);
	PelletConfig* getConfigFromIdx(int);
	PelletConfig* getConfig(u32);
	void readConfigs(RandomAccessStream&);
	void readAnimInfos(RandomAccessStream&);
	void initTekiNakaParts();
	void createShapeObjects();
	void refresh2d(Graphics&);

	// unused/inlined:
	bool useShape(u32);
	ID32 getConfigIdAt(int);

	bool isMovieFlag(u16 flag) { return mMovieFlags & flag; }
	void setMovieFlags(u16 flag) { mMovieFlags = flag; }

	static int getUfoIndexFromID(u32 ufoID);
	static u32 getUfoIDFromIndex(int);
	int getNumConfigs() { return mConfigNum; }

	// .dll exclusive functions
	void writeAnimInfos(RandomAccessStream&);
	void writeConfigs(RandomAccessStream&);
	void addAnimInfo(AgeServer&);
	void addConfig(AgeServer&);
	void animInfoRead(AgeServer&);
	void animInfoWrite(AgeServer&);
	void configRead(AgeServer&);
	void configWrite(AgeServer&);
	void removeAnimInfo(AgeServer&, PelletAnimInfo*);
	void removeConfig(AgeServer&, PelletConfig*);

protected:
	virtual Creature* createObject(); // _80

	PelletShapeObject* getShapeObject(u32); // I don't understand why this is protected, but the ILK says it is.

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	UseNode mUseList;                 // _3C
	int mConfigNum;                   // _54
	PelletConfig mConfigList;         // _58
	int mAnimInfoNum;                 // _190
	PelletAnimInfo mAnimInfoList;     // _194
	PelletProp* mPelletProps;         // _1F4
	PaniMotionTable* mUfoMotionTable; // _1F8
	int mReadStage;                   // _1FC, 0:read in configs, 1:read in animinfos
	u16 mMovieFlags;                  // _200, see PelletMgrMovieFlags enum
};

extern PelletMgr* pelletMgr;
extern bool SmartTurnOver;

#endif
