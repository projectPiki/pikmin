#ifndef _PIKI_H
#define _PIKI_H

#include "types.h"
#include "Creature.h"
#include "PaniPikiAnimator.h"

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

	// _00      = VTBL
	// _00-_2B8 = Creature
	// _2B8     = PaniAnimKeyListener
	u8 _2BC[0x354 - 0x2BC];       // _2BC, TODO: work out members
	PaniPikiAnimMgr mPikiAnimMgr; // _354
	u8 _400;                      // _400
	u8 _401[0x408 - 0x401];       // _401, unknown
	u8 _408;                      // _408
	u8 _409;                      // _409
	u8 _40A[0x424 - 0x40A];       // _40A, unknown
	u8 _424;                      // _424
	u16 _426;                     // _426
	u8 _428[0x8];                 // _428, unknown
	u32 _430;                     // _430, unknown
	u8 _434[0x48C - 0x434];       // _434, unknown
	f32 _48C;                     // _48C
	PikiStateMachine* mFSM;       // _490
	u8 _494[0x4];                 // _494, unknown
	f32 _498;                     // _498
	f32 _49C;                     // _49C, some form of angle?
	u8 _4A0;                      // _4A0
	CollPart* mSwallowMouthPart;  // _4A4
	Creature* _4A8;               // _4A8, maybe puffstool/kinoko leader?
	u8 _4AC[0x4F8 - 0x4AC];       // _4AC, unknown
	TopAction* _4F8;              // _4F8, may be just Action*
	u16 _4FC;                     // _4FC
	u32 _500;                     // _500, unknown
	Navi* mNavi;                  // _504
	u8 _508[0x8];                 // _508, unknown
	u16 mColor;                   // _510, red/yellow/blue
	u8 _512[0x520 - 0x512];       // _4FC, TODO: work out members
	int mHappa;                   // _520, leaf/bud/flower
	u8 _524[0x585 - 0x524];       // _4FC, TODO: work out members
};

/**
 * @brief TODO
 */
struct PikiShapeObject {
	PikiShapeObject(Shape*);

	void exitCourse();
	void getAnimMgr();
	void initOnce();

	static void init();

	// unused/inlined:
	void create(int);

	// TODO: members
};

#endif
