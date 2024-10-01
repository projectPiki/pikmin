#ifndef _TEKI_H
#define _TEKI_H

#include "types.h"
#include "Creature.h"
#include "ObjectMgr.h"
#include "PaniAnimator.h"
#include "PelletView.h"
#include "Interactions.h"

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
	TEKIOPT_Unk12            = 1 << 12, // 0x1000
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

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct TekiEvent {
	TekiEvent(int, Teki*);
	TekiEvent(int, Teki*, Creature*);

	void init(int, Teki*, Creature*);

	int _00;       // _00
	Teki* mTeki;   // _04
	Creature* _08; // _08
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
	virtual void viewGetScale();                         // _160
	virtual void viewGetBottomRadius();                  // _164
	virtual void viewGetHeight();                        // _168
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
	virtual void setTekiOption(int);                     // _1CC
	virtual void clearTekiOption(int);                   // _1D0
	virtual void setTekiOptions(int);                    // _1D4
	virtual void clearTekiOptions();                     // _1D8
	virtual void setAnimationKeyOption(int);             // _1DC
	virtual void clearAnimationKeyOption(int);           // _1E0
	virtual void setAnimationKeyOptions(int);            // _1E4
	virtual void clearAnimationKeyOptions();             // _1E8
	virtual void dieSoon();                              // _1EC
	virtual void becomeCorpse();                         // _1F0

	bool isPellet(int);
	void calcCircleDistanceStatic(Vector3f&, f32, Vector3f&, f32);
	void calcSphereDistanceStatic(Vector3f&, f32, Vector3f&, f32);
	void moveTowardStatic(Vector3f&, Vector3f&, f32, Vector3f&);
	void arrivedAt(f32, f32);
	void prepareEffects();
	void startStoppingMove();
	void finishStoppingMove();
	void getVelocityAnimationSpeed(f32);
	void releasePlatCollisions();
	void createDeadEffect();
	void createSoulEffect();
	void spawnItems();
	void spawnPellets(int, int, int);
	void spawnWaters(int);
	void spawnCorpseParts();
	void outputSpawnPosition(Vector3f&);
	void getPersonalityF(int);
	void getParameterF(int);
	f32 getDirection() { return mDirection; } // weak function
	void nearestAngleTarget(Creature*);
	void cullableCenter(Creature&, f32);
	void cullableSphere(Creature&, f32);
	void inSectorPosition(Vector3f&, f32, f32);
	void visibleCreature(Creature&);
	void separateCreature(Creature&);
	void contactCreature(Creature&);
	void attackableCreature(Creature&);
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
	void getStrategy();
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

	// whatever this code is, it comes up in a few spots to do with replacing creature targets
	// it needs more inlining/to add more to the stack though
	inline void removeTarget()
	{
		if (_418) {
			_418->subCnt();
			_418 = nullptr;
		}
	}

	inline void addTarget(Creature* target)
	{
		if (_418) {
			removeTarget();
		}
		_418 = target;
		if (_418) {
			_418->addCnt();
		}
	}

	inline bool isTekiOption(int opt) const { return mTekiOptions & opt; }
	inline bool isAnimKeyOption(int opt) const { return mAnimKeyOptions & opt; }

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
	u8 _2C0[0x2C8 - 0x2C4]; // _2C0, TODO: work out members
	void* _2C8;             // _2C8
	PaniAnimator* _2CC;     // _2CC
	u8 _2D0[0x31C - 0x2D0]; // _2D0, TODO: work out members
	u32 _31C;               // _31C
	TekiTypes mTekiType;    // _320
	int _324;               // _324, related to states
	bool _328;              // _328, related to states
	u8 _329[0x334 - 0x329]; // _329, TODO: work out members
	int _334;               // _334, related to actions
	int _338;               // _338, unknown, state id of some description?
	u8 _33C[0x388 - 0x33C]; // _33C, TODO: work out members
	Vector3f _388;          // _388, possibly position
	f32 _394;               // _394
	u8 _398[0x3B4 - 0x398]; // _398, TODO: work out members
	f32 mMotionSpeed;       // _3B4
	u8 _3B8[0x410 - 0x3B8]; // _3B8, TODO: work out members
	int mTekiOptions;       // _410
	int mAnimKeyOptions;    // _414
	Creature* _418;         // _418, maybe attack target?
	u8 _41C[0x454 - 0x41C]; // _41C, TODO: work out members
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

	// _00       = VTBL
	// _000-_46C = NTeki
	u8 _46C[0x478 - 0x46C]; // _46C, TODO: work out members
	f32 _478;               // _478
	u8 _47C[0x498 - 0x47C]; // _47C, TODO: work out members
	u32 _498[8];            // _498, array of something, probably not u32s
	u8 _4B8[0x538 - 0x4B8]; // _4B8, TODO: work out members
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
	void getTypeIndex(char*);
	void setUsingType(int, bool);

	static void initTekiMgr();

	static char* typeNames[TEKI_TypeCount];
	static u32 typeIds[TEKI_TypeCount];

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
