#ifndef _PELLET_H
#define _PELLET_H

#include "types.h"
#include "DualCreature.h"
#include "CreatureProp.h"
#include "ObjectMgr.h"
#include "PelletAnimator.h"
#include "StateMachine.h"
#include "Shape.h"

struct PaniAnimKeyEvent;
struct PaniMotionTable;
struct PelletShapeObject;
struct PelletStateMachine;
struct PelletView;
struct Shape;
struct RippleEffect;

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
	PELCOLOR_NULL = -1,

	PELCOLOR_Blue   = 0,
	PELCOLOR_Red    = 1,
	PELCOLOR_Yellow = 2,

	PELCOLOR_MIN  = PELCOLOR_Blue,
	PELCOLOUR_MAX = PELCOLOR_Yellow,

	PELCOLOUR_COUNT,
};

/**
 * @brief TODO
 */
struct PelletProp : public CreatureProp {

	// _54     = VTBL
	// _00-_58 = CreatureProp
	// TODO: members
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
	ID32 _2C;                         // _2C
	ID32 _38;                         // _38
	ID32 _44;                         // _44
	Parm<int> mPelletType;            // _50, p00
	Parm<int> mPelletColor;           // _60, p09
	Parm<int> mCarryMinPikis;         // _70, p01
	Parm<int> mCarryMaxPikis;         // _80, p02
	Parm<int> _90;                    // _90, p03 - maybe model rotation when sucking into onyon?
	Parm<f32> _A0;                    // _A0, p04 - dynParm1?
	Parm<f32> _B0;                    // _B0, p05 - dynParm2?
	Parm<int> _C0;                    // _C0, p08 - dynCollNums?
	Parm<int> mMatchingOnyonSeeds;    // _D0, p06 - null produces fireworks
	Parm<int> mNonMatchingOnyonSeeds; // _E0, p07 - null produces fireworks
	Parm<f32> mPelletScale;           // _F0, p10
	Parm<f32> mCarryInfoHeight;       // _100, p11
	Parm<int> _110;                   // _110, p12 - soundID of some description
	Parm<int> mBounceSoundID;         // _120, p13
	u32 _130;                         // _130, maybe int?

	// this has to be down here or the second VTBL spawns at 0x18 (should spawn at 0x134)

	virtual void read(RandomAccessStream&); // _18 (weak)
};

/**
 * @brief TODO
 *
 * @note Size: 0x5BC.
 */
struct Pellet : public DualCreature, public PaniAnimKeyListener {
	Pellet();

	virtual void init(Vector3f&);                        // _28
	virtual void startAI(int);                           // _34
	virtual f32 getiMass();                              // _38
	virtual f32 getSize();                               // _3C
	virtual f32 getCylinderHeight();                     // _44
	virtual void doSave(RandomAccessStream&);            // _50
	virtual void doLoad(RandomAccessStream&);            // _54
	virtual Vector3f getCentre();                        // _58
	virtual bool isVisible();                            // _74
	virtual bool isAtari();                              // _84
	virtual bool isAlive();                              // _88
	virtual bool ignoreAtari(Creature*);                 // _98
	virtual bool isFree();                               // _9C
	virtual bool stimulate(Interaction&);                // _A0
	virtual void collisionCallback(struct CollEvent&);   // _A8
	virtual void bounceCallback();                       // _AC
	virtual void startWaterEffect();                     // _CC
	virtual void finishWaterEffect();                    // _D0
	virtual void update();                               // _E0
	virtual void postUpdate(int, f32);                   // _E4
	virtual void refresh(Graphics&);                     // _EC
	virtual void doAnimation();                          // _108
	virtual void doKill();                               // _10C
	virtual void doRender(Graphics&, Matrix4f&);         // _118
	virtual void doCreateColls(Graphics&);               // _11C
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _12C (weak)

	int getState();
	void setTrySound(bool);
	void startPick();
	void finishPick();
	void startGoal();
	void doCarry(Creature*, Vector3f&, u16);
	f32 getBottomRadius();
	bool startStickTeki(Creature*, f32);
	void endStickTeki(Creature*);
	bool winnable(int);
	bool stickSlot(int);
	void stickOffSlot(int);
	int getMinFreeSlotIndex();
	int getNearestFreeSlotIndex(Vector3f&);
	int getRandomFreeSlotIndex();
	Vector3f getSlotLocalPos(int, f32);
	Vector3f getSlotGlobalPos(int, f32);
	void setSlotFlag(int);
	void resetSlotFlag(int);
	void isSlotFlag(int);
	void initPellet(PelletShapeObject*, PelletConfig*);
	void startCarryMotion(f32);
	void finishMotion();

	// unused/inlined:
	void initSlotFlags();
	void initPellet(PelletView*, PelletConfig*);
	void stopMotion();
	void startAppear();

	static bool isUfoPartsID(u32);

	AState<Pellet>* getCurrState() { return mCurrentState; }
	void setCurrState(AState<Pellet>* state) { mCurrentState = state; }

	void setMotionFlag(u8 flag) { mMotionFlag |= flag; }
	bool isMotionFlag(u8 flag) { return mMotionFlag & flag; }

	// DLL inlines to do:
	bool isUfoParts();

	bool isSlotFree(int);
	int getNearestFreeSlotIndex();

	// _00       = VTBL1
	// _440      = VTBL2
	// _00-_440  = DualCreature
	// _440-_444 = PaniAnimKeyListener
	Vector3f _444;                        // _444
	u8 _450;                              // _450
	bool mIsPlayTrySound;                 // _451
	u8 mMotionFlag;                       // _452
	RippleEffect* mRippleEffect;          // _454
	u8 _458[0x464 - 0x458];               // _458, unknown
	Vector3f _464;                        // _464
	PelletStateMachine* mStateMachine;    // _470
	AState<Pellet>* mCurrentState;        // _474
	Creature* _478;                       // _478
	Vector3f _47C;                        // _47C
	u16 _488;                             // _488
	f32 _48C;                             // _48C
	u16 _490;                             // _490
	Vector3f _494;                        // _494
	u8 _4A0[0x4A8 - 0x4A0];               // _4A0, unknown
	void* mPelletView;                    // _4A8, both PelletView* and Creature* - see Pellet::getBottomRadius
	PelletAnimator mAnimator;             // _4AC
	u32 _554;                             // _554, unknown
	u8 _558[0x4];                         // _558, unknown
	PelletConfig* mConfig;                // _55C
	f32 _560;                             // _560
	u8 _564[0x570 - 0x564];               // _564, unknown
	u16 _570;                             // _570
	CollInfo* mPelletCollInfo;            // _574
	SearchData mSearchData[4];            // _578
	ShapeDynMaterials mShapeDynMaterials; // _5A8
	bool mIsAlive;                        // _5B8
};

/**
 * @brief TODO
 *
 * @note Size: 0x204.
 */
struct PelletMgr : public MonoObjectMgr {

	/**
	 * @brief TODO
	 */
	struct UseNode : public CoreNode {
		// _00     = VTBL
		// _00-_14 = CoreNode
		// TODO: members
	};

	PelletMgr(MapMgr*);

	virtual ~PelletMgr();                   // _48 (weak)
	virtual void refresh(Graphics&);        // _58
	virtual Creature* createObject();       // _80
	virtual void read(RandomAccessStream&); // _84 (weak)

	bool decomposeNumberPellet(u32, int&, int&);
	void registerUfoParts();
	Pellet* newNumberPellet(int, int);
	Pellet* newPellet(u32, PelletView*);
	PelletShapeObject* getShapeObject(u32);
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

	static int getUfoIndexFromID(u32 ufoID);
	static u32 getUfoIDFromIndex(int);

	// DLL inlines to make:
	bool isMovieFlag(u16);
	int getNumConfigs();
	void setMovieFlags(u16);
	void writeAnimInfos(RandomAccessStream&);
	void writeConfigs(RandomAccessStream&);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	// TODO: members
	u8 _3C[0x1F8 - 0x3C];             // _3C, unknown
	PaniMotionTable* mUfoMotionTable; // _1F8
	u8 _1FC[0x204 - 0x1FC];           // _1FC, unknown
};

/**
 * @brief TODO
 */
struct PelletShapeObject {
	PelletShapeObject(char*, Shape*, char*, char*, int);

	Shape* mShape;          // _00
	AnimMgr* mAnimMgr;      // _04
	AnimContext mAnimatorA; // _08
	AnimContext mAnimatorB; // _18
	                        // TODO: members
};

extern PelletMgr* pelletMgr;
extern bool SmartTurnOver;

#endif
