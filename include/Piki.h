#ifndef _PIKI_H
#define _PIKI_H

#include "types.h"
#include "Creature.h"
#include "PaniPikiAnimator.h"
#include "OdoMeter.h"

struct TopAction;
struct Navi;
struct PikiStateMachine;
struct PikiProp;

/**
 * @brief TODO
 */
enum PikiColor {
	Blue   = 0,
	Red    = 1,
	Yellow = 2,
	PikiColorCount, // 3

	PikiMinColor = Blue,
	PikiMaxColor = Yellow,
	PIKI_Kinoko  = 3,
};

/**
 * @brief TODO
 */
enum PikiHappa {
	Leaf   = 0,
	Bud    = 1,
	Flower = 2,
	PikiHappaCount, // 3

	PikiMinHappa = Leaf,
	PikiMaxHappa = Flower,
};

// clang-format off
DEFINE_ENUM_TYPE(
	PikiMode,

    FreeMode = 0, 
    FormationMode,
    AttackMode,
    NukuMode,
    GuardMode,
    PickMode,
    DecoyMode,
    ArrowMode,
    CarryMode,
    TransportMode,
    RopeMode,
    EnterMode,
    ExitMode,
    BreakwallMode,
    MineMode,
    KinokoMode,
    BridgeMode,
    PushstoneMode,
    PutbombMode,
    RescueMode,
    WeedMode,
    PebbleMode,
    BomakeMode,
    BoMode,
    WarriorMode
);
// clang-format on

/**
 * @brief TODO
 */
struct Piki : public Creature, public PaniAnimKeyListener {
	Piki(CreatureProp*);

	virtual void addCntCallback();                       // _08
	virtual void subCntCallback();                       // _0C
	virtual bool platAttachable();                       // _14
	virtual bool doDoAI();                               // _1C
	virtual void resetPosition(Vector3f&);               // _2C
	virtual f32 getiMass();                              // _38
	virtual f32 getSize();                               // _3C
	virtual Vector3f getShadowPos();                     // _68
	virtual bool isVisible();                            // _74
	virtual bool isBuried();                             // _80
	virtual bool isAtari();                              // _84
	virtual bool isAlive();                              // _88
	virtual bool isFixed();                              // _8C
	virtual bool needShadow();                           // _90
	virtual bool needFlick(Creature*);                   // _94
	virtual bool ignoreAtari(Creature*);                 // _98
	virtual bool stimulate(Interaction&);                // _A0
	virtual void sendMsg(Msg*);                          // _A4
	virtual void collisionCallback(CollEvent&);          // _A8
	virtual void bounceCallback();                       // _AC
	virtual void jumpCallback();                         // _B0
	virtual void wallCallback(Plane&, DynCollObject*);   // _B4
	virtual void offwallCallback(DynCollObject*);        // _B8
	virtual void stickToCallback(Creature*);             // _C4
	virtual void dump();                                 // _C8
	virtual bool isRopable();                            // _D4
	virtual bool mayIstick();                            // _D8
	virtual int getFormationPri();                       // _DC
	virtual Vector3f getCatchPos(Creature*);             // _100
	virtual void doAI();                                 // _104
	virtual void doAnimation();                          // _108
	virtual void doKill();                               // _10C
	virtual bool isKinoko() = 0;                         // _120
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _124
	virtual void initBirth();                            // _128
	virtual void changeShape(int) { }                    // _12C
	virtual void setFlower(int) { }                      // _130
	virtual void setLeaves(int);                         // _134

	void getSpeed(f32);
	void setSpeed(f32, Vector3f&);
	void setSpeed(f32, f32);
	void init(Navi*);
	bool isFruit();
	void updateLookCreature();
	void updateWalkAnimation();
	void realAI();
	void changeMode(int, Navi*);
	void startHimaLook(Vector3f*);
	void finishLook();
	bool isLooking();
	void updateLook();
	void demoCheck();
	void startDemo();
	void finishDemo();
	void appearDemo();
	void getUpperMotionIndex();
	void getAttackPower();
	void findRoute(int, int, bool, bool);
	void moveRouteTraceDynamic(f32);
	void initRouteTrace(Vector3f&, bool);
	void moveRouteTrace(f32);
	void crGetPoint(int);
	void crPointOpen(int);
	void crGetRadius(int);
	void crMakeRefs();
	bool hasBomb();
	void startFire();
	void endFire();
	bool isTeki(Piki*);
	void actOnSituaton(); // dev spelling
	int getState();
	void graspSituation(Creature**);
	void initColor(int);
	void startKinoko();
	void endKinoko();
	void setColor(int);
	void setPastel();
	void unsetPastel();
	void updateColor();
	void startDamage();
	void finishDamage();
	bool isThrowable();
	void startMotion(struct PaniMotionInfo&, PaniMotionInfo&);
	void enableMotionBlend();
	void checkBridgeWall(Creature*, Vector3f&);

	static bool isSafeMePos(Vector3f&);

	// unused/inlined:
	void getPikiState();
	void initRouteTraceDynamic(Creature*);
	void updateFire();
	void getNaviID();
	void getLastState();
	void birthBuried();
	void isGrowable();
	void isTamable();
	void growup();
	void doMotionBlend();
	void swapMotion(PaniMotionInfo&, PaniMotionInfo&);
	void setSpeed(f32);
	void getCurrentMotionName();

	// defined in PikiMgr.h to avoid include looping
	inline PikiProp* getPikiProp();

	// 100AEBD0 in plugPiki
	inline void setPositionA(Vector3f* other)
	{
		_33C = other;

		_340 = 0;
		_330 = 0;

		// _338 is a counter
		if (_338) {
			subCnt();
			_338 = 0;
		}
	}

	inline void resetVariables()
	{
		_33C = 0;
		_348 = 0.0f;
		_344 = 0.0f;
		_340 = 0;
		_330 = 0;

		if (_338) {
			subCnt();
			_338 = 0;
		}
	}

	// _00      = VTBL
	// _00-_2B8 = Creature
	// _2B8     = PaniAnimKeyListener
	OdoMeter mOdometer;           // _2BC
	u32 _2C0;                     // _2C0
	u32 _2C4;                     // _2C4
	u32 _2C8;                     // _2C8
	u32 _2CC;                     // _2CC
	u32 _2D0;                     // _2D0
	u32 _2D4;                     // _2D4
	u32 _2D8;                     // _2D8
	u32 _2DC;                     // _2DC
	u32 _2E0;                     // _2E0
	u32 _2E4;                     // _2E4
	u32 _2E8;                     // _2E8
	u32 _2EC;                     // _2EC
	u32 _2F0;                     // _2F0
	u32 _2F4;                     // _2F4
	u32 _2F8;                     // _2F8
	u32 _308;                     // _308
	u32 _30C;                     // _30C
	u32 _310;                     // _310
	u32 _314;                     // _314
	u32 _318;                     // _318
	u32 _31C;                     // _31C
	u32 _320;                     // _320
	u32 _324;                     // _324
	u32 _328;                     // _328
	u32 _32C;                     // _32C
	u8 _330;                      // _330
	u32 _334;                     // _334
	u32 _338;                     // _338
	Vector3f* _33C;               // _33C
	u8 _340;                      // _340
	f32 _344;                     // _344
	f32 _348;                     // _348
	u32 _34C;                     // _34C
	u32 _350;                     // _350
	PaniPikiAnimMgr mPikiAnimMgr; // _354
	u8 mEmotion;                  // _400
	u8 _401[0x408 - 0x401];       // _401
	u8 _408;                      // _408
	bool mIsCallable;             // _409
	u8 _40A[0x424 - 0x40A];       // _40A
	u8 _424;                      // _424
	u16 _426;                     // _426
	u8 _428[0x8];                 // _428
	u32 _430;                     // _430
	u32 _434;                     // _434
	u32 _438;                     // _438
	u32 mPlayerId;                // _43C
	u32 _440;                     // _440
	u32 _444;                     // _444
	u32 _448;                     // _448
	u32 _44C;                     // _44C
	u32 _450;                     // _450
	u32 _454;                     // _454
	u32 _458;                     // _458
	u32 _45C;                     // _45C
	u32 _460;                     // _460
	Vector3f _464;                // _464
	u8 mWantToStick;              // _470
	u8 _471[0x48C - 0x471];       // _471
	f32 _48C;                     // _48C
	PikiStateMachine* mFSM;       // _490
	u8 _494[0x4];                 // _494
	f32 _498;                     // _498, knockback? impulse velocity magnitude?
	f32 mRotationAngle;           // _49C
	u8 _4A0;                      // _4A0
	CollPart* mSwallowMouthPart;  // _4A4
	Creature* _4A8;               // _4A8, maybe puffstool/kinoko leader?
	u8 _4AC[0x4F8 - 0x4AC];       // _4AC
	TopAction* _4F8;              // _4F8, may be just Action*
	u16 mMode;                    // _4FC, use PikiMode enum
	u32 _500;                     // _500
	Navi* mNavi;                  // _504
	u8 _508[0x8];                 // _508
	u16 mColor;                   // _510, red/yellow/blue
	u8 _512[0x518 - 0x512];       // _4FC
	u8 _518;                      // _518
	u8 _519;                      // _519
	u8 _51A[0x520 - 0x51A];       // _51A
	int mHappa;                   // _520, leaf/bud/flower
	u8 _524[0x585 - 0x524];       // _524
};

/**
 * @brief TODO
 */
struct PikiShapeObject {
	PikiShapeObject(Shape*);

	void exitCourse();

	static AnimMgr* getAnimMgr();
	static void init();
	static void initOnce();

	// unused/inlined:
	void create(int);

	static bool firstTime;
	static PikiShapeObject* _instances[4];

	Shape* mShape;          // _00
	AnimContext mAnimatorA; // _04
	AnimContext mAnimatorB; // _14
	AnimMgr* mAnimMgr;      // _24
};

#endif
