#ifndef _TEKI_H
#define _TEKI_H

#include "types.h"
#include "Creature.h"
#include "ObjectMgr.h"
#include "PaniAnimator.h"
#include "PelletView.h"
#include "Interactions.h"
#include "nlib/Geometry.h"
#include "nlib/Function.h"
#include "ComplexCreature.h"
#include "CreatureCollPart.h"
#include "TekiParameters.h"
#include "TekiPersonality.h"
#include "Shape.h"
#include "system.h"

struct NTeki;
struct Teki;
struct TekiMgr;
struct CollEvent;
struct TekiAnimationManager;
struct TekiStrategy;
struct TekiStrategyTable;
struct TekiParameters;
struct PeveParabolaEvent;
struct PeveAccelerationEvent;
struct PeveCircleMoveEvent;
struct PeveHorizontalSinWaveEvent;
struct TekiPersonality;
struct CreaturePlatMgr;

namespace zen {
struct PtclGenPack;
} // namespace zen

namespace TekiNakata {
// Teki-making utility functions
void makeTekiParameters(TekiMgr*);
void makeTekis(TekiMgr*);

} // namespace TekiNakata

/**
 * @brief TODO
 */
enum TekiOptions {
	TEKIOPT_Visible          = 1 << 0,  // 0x1
	TEKIOPT_ShadowVisible    = 1 << 1,  // 0x2
	TEKIOPT_LifeGaugeVisible = 1 << 2,  // 0x4
	TEKIOPT_Atari            = 1 << 3,  // 0x8
	TEKIOPT_Alive            = 1 << 4,  // 0x10
	TEKIOPT_Organic          = 1 << 5,  // 0x20
	TEKIOPT_Unk6             = 1 << 6,  // 0x40
	TEKIOPT_ManualAnimation  = 1 << 7,  // 0x80
	TEKIOPT_Gravitatable     = 1 << 8,  // 0x100
	TEKIOPT_Invincible       = 1 << 9,  // 0x200
	TEKIOPT_Pressed          = 1 << 10, // 0x400
	TEKIOPT_Unk11            = 1 << 11, // 0x800
	TEKIOPT_StoppingMove     = 1 << 12, // 0x1000
	TEKIOPT_Drawed           = 1 << 13, // 0x2000
	TEKIOPT_ShapeVisible     = 1 << 14, // 0x4000
	TEKIOPT_DamageCountable  = 1 << 15, // 0x8000
};

/**
 * @brief TODO
 */
enum TekiTypes {
	TEKI_START    = 0,  // START OF VALID TEKI TYPES
	TEKI_Frog     = 0,  // 0, Yellow Wollywog
	TEKI_Iwagen   = 1,  // 1, Iwagen (unused enemy)
	TEKI_Iwagon   = 2,  // 2, Rolling Boulder
	TEKI_Chappy   = 3,  // 3, Dwarf Bulborb
	TEKI_Swallow  = 4,  // 4, Spotty Bulborb
	TEKI_Mizigen  = 5,  // 5, Honeywisp Spawner
	TEKI_Qurione  = 6,  // 6, Honeywisp
	TEKI_Palm     = 7,  // 7, Pellet Posy
	TEKI_Collec   = 8,  // 8, Breadbug
	TEKI_Kinoko   = 9,  // 9, Puffstool
	TEKI_Shell    = 10, // 10, Pearly Clamclamp (shell)
	TEKI_Napkid   = 11, // 11, Swooping Snitchbug
	TEKI_Hollec   = 12, // 12, Breadbug Nest
	TEKI_Pearl    = 13, // 13, Pearly Clamclamp (pearl)
	TEKI_Rocpe    = 14, // 14, Pearly Clamclamp (ship part)
	TEKI_Tank     = 15, // 15, Fiery Blowhog
	TEKI_Mar      = 16, // 16, Puffy Blowhog
	TEKI_Beatle   = 17, // 17, Armored Cannon Beetle
	TEKI_KabekuiA = 18, // 18, Female Sheargrub
	TEKI_KabekuiB = 19, // 19, Male Sheargrub
	TEKI_KabekuiC = 20, // 20, Shearwig
	TEKI_Tamago   = 21, // 21, Giant Egg (for Smoky Progg)
	TEKI_Dororo   = 22, // 22, Smoky Progg
	TEKI_HibaA    = 23, // 23, Fire Geyser
	TEKI_Miurin   = 24, // 24, Mamuta
	TEKI_Otama    = 25, // 25, Wogpole
	TEKI_Usuba    = 26, // 26, Usuba (unused enemy, crashes)
	TEKI_Yamash3  = 27, // 27, ? (unused enemy, crashes)
	TEKI_Yamash4  = 28, // 28, ? (unused enemy, crashes)
	TEKI_Yamash5  = 29, // 29, ? (unused enemy, crashes)
	TEKI_Namazu   = 30, // 30, Water Dumple
	TEKI_Chappb   = 31, // 31, Dwarf Bulbear
	TEKI_Swallob  = 32, // 32, Spotty Bulbear
	TEKI_Frow     = 33, // 33, Wollywog
	TEKI_Nakata1  = 34, // 34, ? (unused enemy, crashes)
	TEKI_TypeCount,     // 35
};

/**
 * @brief TODO
 */
struct TekiInteractionKey {
	TekiInteractionKey(int, Interaction*);

	// TODO: members
};

DEFINE_ENUM_TYPE(TekiEventType, Ground = 0, Entity = 1, Wall = 2);

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct TekiEvent {
	TekiEvent(int, Teki*);
	TekiEvent(int, Teki*, Creature*);

	void init(int, Teki*, Creature*);

	TekiEventType::Type mCollisionType; // _00
	Teki* mTeki;                        // _04
	Creature* mOther;                   // _08
};

/**
 * @brief TODO
 */
struct TekiShapeObject {
	TekiShapeObject(Shape*);

	Shape* mShape;            // _00
	AnimContext mAnimContext; // _04
	AnimMgr* mAnimMgr;        // _14
};

/**
 * @brief TODO
 */
struct TekiMessage {
	TekiMessage(int, NTeki*);

	int _00;      // _00
	NTeki* mTeki; // _04
};

/**
 * @brief TODO
 */
struct BTeki : public Creature, virtual public PaniAnimKeyListener, public PelletView {
	BTeki();

	virtual bool alwaysUpdatePlatform();                 // _18
	virtual void startAI(int);                           // _34
	virtual f32 getiMass();                              // _38
	virtual void doStore(CreatureInf*);                  // _48
	virtual void doRestore(CreatureInf*);                // _4C
	virtual f32 getShadowSize();                         // _70
	virtual bool isVisible();                            // _74
	virtual bool isOrganic();                            // _78
	virtual bool isAtari();                              // _84
	virtual bool isAlive();                              // _88
	virtual bool needShadow();                           // _90
	virtual bool ignoreAtari(Creature*);                 // _98
	virtual bool stimulate(Interaction&);                // _A0
	virtual void collisionCallback(CollEvent&);          // _A8
	virtual void bounceCallback();                       // _AC
	virtual void wallCallback(Plane&, DynCollObject*);   // _B4
	virtual void dump();                                 // _C8
	virtual void update();                               // _E0
	virtual void refresh(Graphics&);                     // _EC
	virtual void refresh2d(Graphics&);                   // _F0
	virtual void doAI();                                 // _104
	virtual void doAnimation();                          // _108
	virtual void doKill();                               // _10C
	virtual void exitCourse();                           // _110
	virtual void viewStartTrembleMotion(f32);            // _148
	virtual void viewSetMotionSpeed(f32);                // _14C
	virtual void viewDoAnimation();                      // _150
	virtual void viewFinishMotion();                     // _154
	virtual void viewDraw(Graphics&, Matrix4f&);         // _158
	virtual void viewKill();                             // _15C
	virtual Vector3f viewGetScale();                     // _160
	virtual f32 viewGetBottomRadius();                   // _164
	virtual f32 viewGetHeight();                         // _168
	virtual void init(int);                              // _16C
	virtual void reset();                                // _170
	virtual void startMotion(int);                       // _174
	virtual void die();                                  // _178
	virtual void updateTimers();                         // _17C
	virtual void gravitate(f32);                         // _180
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _184 (weak)
	virtual void getTekiCollisionSize();                 // _188
	virtual void makeDamaged();                          // _18C
	virtual void startDamageMotion(f32, f32);            // _190
	virtual void generateTeki(int);                      // _194
	virtual void spawnTeki(int);                         // _198
	virtual void shootBall(Creature&);                   // _19C
	virtual void eventPerformed(TekiEvent&);             // _1A0
	virtual void interact(struct TekiInteractionKey&);   // _1A4
	virtual void interactDefault(TekiInteractionKey&);   // _1A8
	virtual void drawDefault(Graphics&);                 // _1AC
	virtual void drawTekiShape(Graphics&);               // _1B0
	virtual void drawTekiDebugInfo(Graphics&);           // _1B4
	virtual void drawTekiDebugInfoDefault(Graphics&);    // _1B8
	virtual void playTableSound(int);                    // _1BC
	virtual void playSound(int);                         // _1C0
	virtual void stopSound(int);                         // _1C4
	virtual void createTekiEffect(int);                  // _1C8
	virtual void setTekiOption(int opt)                  // _1CC
	{
		mTekiOptions |= opt;
	}
	virtual void clearTekiOption(int);         // _1D0
	virtual void setTekiOptions(int);          // _1D4
	virtual void clearTekiOptions();           // _1D8
	virtual void setAnimationKeyOption(int);   // _1DC
	virtual void clearAnimationKeyOption(int); // _1E0
	virtual void setAnimationKeyOptions(int);  // _1E4
	virtual void clearAnimationKeyOptions();   // _1E8
	virtual void dieSoon();                    // _1EC
	virtual void becomeCorpse();               // _1F0

	bool arrivedAt(f32, f32);
	void prepareEffects();
	void startStoppingMove();
	void finishStoppingMove();
	f32 getVelocityAnimationSpeed(f32);
	void releasePlatCollisions();
	void createDeadEffect();
	void createSoulEffect();
	void spawnItems();
	void spawnPellets(int, int, int);
	void spawnWaters(int);
	void spawnCorpseParts();
	void outputSpawnPosition(Vector3f&);
	void nearestAngleTarget(Creature*);
	void cullableCenter(Creature&, f32);
	void cullableSphere(Creature&, f32);
	void inSectorPosition(Vector3f&, f32, f32);
	void visibleCreature(Creature&);
	void separateCreature(Creature&);
	void contactCreature(Creature&);
	bool attackableCreature(Creature&);
	void calcTargetAngle(Vector3f&);
	void moveToward(Vector3f&, f32);
	void turnToward(f32, f32);
	void rotateTeki(f32);
	Creature* getClosestNaviPiki(Condition&, f32*);
	void attackTarget(Creature&, f32, f32, Condition&);
	void outputHitCenter(Vector3f&);
	void interactNaviPiki(Interaction&, Condition&);
	void interactNavi(Interaction&, Condition&);
	void interactPiki(Interaction&, Condition&);
	void flick();
	void flick(struct InteractFlick&, InteractFlick&);
	void flickUpper();
	void flickUpper(InteractFlick&);
	void flickLower();
	void flickLower(InteractFlick&);
	void checkNaviPiki(Condition&);
	void countPikis(Condition&);
	void getFlickDamageCount(int);
	void getGravity();
	TekiStrategy* getStrategy();
	void getSeaLevel();
	void getYFromSeaLevel();
	void makePositionRoute(Vector3f&, Vector3f&, bool);
	void makeWayPointRoute(int, int, bool);
	void getTargetNearestWayPoint(Vector3f&);
	void getNearestWayPoint();
	void getWayPoint(int);
	void getRouteWayPoint(int);
	void updateLifeGauge();
	void drawRange(Graphics&, Vector3f&, f32, struct Colour&);
	void getFreeSlot();
	bool isFreeCollPart(CollPart*);
	void outputWorldAnimationPosition(Vector3f&, int, Matrix4f&);
	void getPositionMapCode(Vector3f&);
	void getPositionMapCode();
	bool inWaterTeki();
	void moveNestPosition();
	void startParticleGenerator(int);
	void stopParticleGenerator(int);
	void setParticleGeneratorPosition(int, Vector3f&);
	void setParticleGeneratorDirection(int, Vector3f&);
	void calcCollisionDistance(Creature&);
	void getCollisionSize();
	void setCorpsePartJoint(int, int);                          // unused
	void outputDirectionPosition(Vector3f&, f32, f32);          // unused
	void jumpTo(Vector3f&, f32);                                // unused
	void insideDirection(Vector3f&);                            // unused
	void attackRangeNaviPiki(Interaction&, Condition&);         // unused
	void interactTeki(Interaction&, Condition&);                // unused
	void countTekis(Condition&);                                // unused
	void getCameraAnimationMatrix(int);                         // unused
	void outputWorldAnimationMatrix(Matrix4f&, int, Matrix4f&); // unused
	void getCollisionCenter();                                  // unused

	static bool isPellet(int);
	static f32 calcCircleDistanceStatic(Vector3f&, f32, Vector3f&, f32);
	static f32 calcSphereDistanceStatic(Vector3f&, f32, Vector3f&, f32);
	static void moveTowardStatic(Vector3f&, Vector3f&, f32, Vector3f&);

	inline void setMotionSpeed(f32 speed)
	{
		setTekiOption(TEKI_OPTION_MANUAL_ANIMATION);
		mMotionSpeed = speed;
	}

	inline void setVisible() { setTekiOption(TEKI_OPTION_VISIBLE); }

	inline bool isTekiOption(int opt) const { return mTekiOptions & opt; }
	inline bool isAnimKeyOption(int opt) const { return mAnimKeyOptions & opt; }

	inline int getStateID() { return mStateID; }

	inline f32 getParticleFactor() { return getParameterF(19); } // rename later when we know what this is

	inline f32 doGetVelocityAnimSpeed() { return getVelocityAnimationSpeed(mTargetVelocity.length()); }

	// these are all correct name-wise according to the map or the DLL.
	f32 getDirection() { return mDirection; }                                 // weak function
	f32 getPersonalityF(int idx) { return mPersonality->mParams->getF(idx); } // weak
	int getPersonalityI(int idx) { return mPersonality->mParams->getI(idx); } // weak

	f32 getParameterF(int idx) { return mTekiParams->getF(idx); } // see TekiFloatParams enum
	int getParameterI(int idx) { return mTekiParams->getI(idx); } // see TekiIntParams enum

	void outputDirectionVector(Vector3f& outDir) { BTeki::outputDirectionVector(getDirection(), outDir); }

	void clearCreaturePointers()
	{
		for (int i = 0; i < 4; i++) {
			mTargetCreatures[i].reset();
		}
	}

	static void outputDirectionVector(f32 angle, Vector3f& outVec) { outVec.set(NMathF::sin(angle), 0.0f, NMathF::cos(angle)); }

	// this is basically two static enums smh
	static int TEKI_OPTION_VISIBLE;
	static int TEKI_OPTION_SHADOW_VISIBLE;
	static int TEKI_OPTION_LIFE_GAUGE_VISIBLE;
	static int TEKI_OPTION_ATARI;
	static int TEKI_OPTION_ALIVE;
	static int TEKI_OPTION_ORGANIC;
	static int TEKI_OPTION_MANUAL_ANIMATION;
	static int TEKI_OPTION_GRAVITATABLE;
	static int TEKI_OPTION_INVINCIBLE;
	static int TEKI_OPTION_PRESSED;
	static int TEKI_OPTION_DRAWED;
	static int TEKI_OPTION_SHAPE_VISIBLE;
	static int TEKI_OPTION_DAMAGE_COUNTABLE;

	static int ANIMATION_KEY_OPTION_FINISHED;
	static int ANIMATION_KEY_OPTION_ACTION_0;
	static int ANIMATION_KEY_OPTION_ACTION_1;
	static int ANIMATION_KEY_OPTION_ACTION_2;
	static int ANIMATION_KEY_OPTION_LOOPSTART;
	static int ANIMATION_KEY_OPTION_LOOPEND;

	// _00       = VTBL
	// _000-_2B8 = Creature
	// _2B8-_2C0 = PelletView
	// _2C0-_2C4 = ptr to PaniAnimKeyListener
	TekiParameters* mTekiParams;                  // _2C4
	TekiPersonality* mPersonality;                // _2C8
	PaniTekiAnimator* mTekiAnimator;              // _2CC
	TekiShapeObject* mTekiShape;                  // _2D0
	CreaturePlatMgr mPlatMgr;                     // _2D4
	int mIsDead;                                  // _31C
	TekiTypes mTekiType;                          // _320
	int mStateID;                                 // _324
	bool mIsStateReady;                           // _328
	u8 _329[0x330 - 0x329];                       // _329, TODO: work out members
	int mPreviousStateId;                         // _330
	int mCurrentQueueId;                          // _334
	int mActionStateId;                           // _338
	f32 mStoredDamage;                            // _33C, damage waiting to be applied on next makeDamaged call
	f32 _340;                                     // _340
	int _344;                                     // _344
	int _348;                                     // _348, size of array at _450
	u32 _34C;                                     // _34C, unknown
	u32 _350;                                     // _350
	int _354;                                     // _354
	NVector3fIOClass _358;                        // _358
	NVector3fIOClass _368;                        // _368
	NVector3fIOClass _378;                        // _378
	NVector3f mTargetPosition;                    // _388, possibly position
	f32 mTargetAngle;                             // _394
	NVector3f _398;                               // _398
	f32 _3A4;                                     // _3A4
	int mCurrentAnimEvent;                        // _3A8
	f32 mAnimationSpeed;                          // _3AC
	u32 _3B0;                                     // _3B0, unknown
	f32 mMotionSpeed;                             // _3B4
	f32 mPreStopAnimationSpeed;                   // _3B8
	u32 _3BC;                                     // _3BC, unknown
	f32 _3C0;                                     // _3C0
	f32 _3C4;                                     // _3C4
	f32 _3C8;                                     // _3C8
	f32 _3CC;                                     // _3CC
	f32 _3D0;                                     // _3D0
	f32 _3D4;                                     // _3D4
	zen::particleGenerator** mParticleGenerators; // _3D8
	zen::PtclGenPack* mParticleGenPack;           // _3DC
	ShapeDynMaterials mDynamicMaterials;          // _3E0, unknown
	int _3F0;                                     // _3F0
	int _3F4;                                     // _3F4
	int _3F8;                                     // _3F8
	int _3FC;                                     // _3FC
	int _400;                                     // _400
	int _404;                                     // _404
	int _408;                                     // _408
	int _40C;                                     // _40C
	int mTekiOptions;                             // _410
	int mAnimKeyOptions;                          // _414
	SmartPtr<Creature> mTargetCreatures[4];       // _418
	NVibrationFunction* mVibrationController;     // _428
	SearchData mTekiSearchData[3];                // _42C
	u32* _450;                                    // _450, array of something, unsure what
	                                              // _454 = PaniAnimKeyListener
};

/**
 * @brief TODO
 */
struct NTeki : public BTeki {
	NTeki();

	void sendMessage(int);
	void receiveMessage(TekiMessage&);

	// _00       = VTBL
	// _000-_454 = BTeki
	u8 _454[0x45C - 0x454];                    // _454, TODO: work out members
	PeveParabolaEvent* mParabolaEvent;         // _45C
	PeveAccelerationEvent* mAccelEvent;        // _460
	PeveCircleMoveEvent* mCircleMoveEvent;     // _464
	PeveHorizontalSinWaveEvent* mSinWaveEvent; // _468
	                                           // _46C = PaniAnimKeyListener
};

/**
 * @brief TODO
 */
struct YTeki : public NTeki {
	YTeki();

	virtual void doKill();     // _10C
	virtual void exitCourse(); // _110
	virtual void init(int);    // _16C

	bool isNaviWatch();
	void moveTowardPriorityFaceDir(Vector3f&, f32);
	void moveTowardPriorityFaceDir(Vector3f&, f32, f32);
	void turnToTarget();
	void flyingStay(f32);
	void killStickToMouthPiki();
	void startNewMotion(int);

	// unused/inlined:
	void getMapAttribute();

	// see TAIAappearKabekui::start
	inline void set4C8(u32 val) { _4C8 = (_4C8 & ~0xFFFFFFEF); }

	inline f32 getMotionLoopTimer() { return _478; }                                            // name is a guess
	inline void updateMotionLoopTimer() { _478 = getMotionLoopTimer() + gsys->getFrameTime(); } // name is a guess

	// _00       = VTBL
	// _000-_46C = NTeki
	u8 _46C[0x470 - 0x46C]; // _46C, TODO: work out members
	u32 _470;               // _470, unknown
	u8 _474[0x4];           // _474, TODO: work out members
	f32 _478;               // _478
	u8 _47C[0x490 - 0x47C]; // _47C, TODO: work out members
	f32 _490;               // _490
	u8 _494[0x4];           // _494, unknown
	u32 _498[8];            // _498, array of something, probably not u32s
	u8 _4B8[0x4C8 - 0x4B8]; // _4B8, TODO: work out members
	u8 _4C8;                // _4C8, bitflag?
	u8 _4C9[0x538 - 0x4C9]; // _4C9, TODO: work out members
	                        // _538 = PaniAnimKeyListener
};

/**
 * @brief TODO
 */
struct Teki : public YTeki {
	Teki();

	// _00       = VTBL
	// _000-_538 = YTeki
	// _538 = PaniAnimKeyListener
};

/**
 * @brief TODO
 *
 * @note Size: 0x1B4.
 */
struct TekiMgr : public MonoObjectMgr {
	TekiMgr();

	virtual ~TekiMgr() { }           // _48
	virtual void update();           // _4C
	virtual void refresh(Graphics&); // _58
	virtual Teki* createObject();    // _80

	void startStage();
	Teki* newTeki(int);
	void reset();
	TekiStrategy* getStrategy(int tekiType);
	TekiParameters* getTekiParameters(int tekiType);
	TekiShapeObject* getTekiShapeObject(int tekiType);
	PaniSoundTable* getSoundTable(int tekiType);
	void refresh2d(Graphics&);
	void setUsingTypeTable(bool);
	void setVisibleTypeTable(bool);
	void setVisibleType(int, bool);
	bool hasModel(int);
	int getResultFlag(int);

	// unused/inlined:
	void setUsingType(int, bool);

	static void initTekiMgr();
	static int getTypeIndex(char*);

	static char* getTypeName(int idx) { return typeNames[idx]; }
	static int getTypeId(int idx) { return typeIds[idx]; }

	static char* typeNames[TEKI_TypeCount];
	static int typeIds[TEKI_TypeCount];

	// DLL inlines to make:
	// bool hasType(int);
	// bool isUsingType(int);
	// bool isVisibleType(int);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
	// TODO: members
	TekiStrategyTable* mStrategyTable;            // _3C
	PaniMotionTable* mMotionTable;                // _40
	PaniSoundTable** mTekiSoundTables;            // _44
	TekiAnimationManager* mTekiAnimMgr;           // _48
	TekiParameters* mTekiParams[TEKI_TypeCount];  // _4C
	TekiShapeObject* mTekiShapes[TEKI_TypeCount]; // _D8
	bool mUsingType[TEKI_TypeCount];              // _164
	u32 _188;                                     // _188, unknown
	bool mVisibleType[TEKI_TypeCount];            // _18C
	u32 _1B0;                                     // _1B0, unknown
};

extern TekiMgr* tekiMgr;

#endif
