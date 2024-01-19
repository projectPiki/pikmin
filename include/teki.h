#ifndef _TEKI_H
#define _TEKI_H

#include "types.h"
#include "Creature.h"
#include "ObjectMgr.h"
#include "PaniAnimator.h"
#include "PelletView.h"

struct Teki;

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
struct TekiMessage {
};

/**
 * @brief TODO
 */
struct BTeki : public Creature, public PelletView, virtual public PaniAnimKeyListener {
	BTeki();

	virtual void alwaysUpdatePlatform();                 // _18
	virtual void startAI(int);                           // _34
	virtual f32 getiMass();                              // _38
	virtual void doStore(CreatureInf*);                  // _48
	virtual void doRestore(CreatureInf*);                // _4C
	virtual void getShadowSize();                        // _70
	virtual bool isVisible();                            // _74
	virtual bool isOrganic();                            // _78
	virtual bool isAtari();                              // _84
	virtual bool isAlive();                              // _88
	virtual bool needShadow();                           // _90
	virtual bool ignoreAtari(Creature*);                 // _98
	virtual void stimulate(Interaction&);                // _A0
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
	void getDirection();
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
	void getClosestNaviPiki(Condition&, f32*);
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

	// _00       = VTBL
	// _000-_2B8 = Creature
	// _2B8-_2C0 = PelletView
	u8 _2C0[0x454 - 0x2C0]; // _2C0, TODO: work out members
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
	u8 _454[0x46C - 0x454]; // _454, TODO: work out members
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

	// _00       = VTBL
	// _000-_46C = NTeki
	u8 _46C[0x538 - 0x46C]; // _46C, TODO: work out members
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
 */
struct TekiMgr : public MonoObjectMgr {
	TekiMgr();

	virtual ~TekiMgr();              // _48
	virtual void update();           // _4C
	virtual void refresh(Graphics&); // _58
	virtual void createObject();     // _80

	void startStage();
	void newTeki(int);
	void reset();
	void getStrategy(int);
	void getTekiParameters(int);
	void getTekiShapeObject(int);
	void getSoundTable(int);
	void refresh2d(Graphics&);
	void setUsingTypeTable(bool);
	void setVisibleTypeTable(bool);
	void setVisibleType(int, bool);
	bool hasModel(int);
	void getResultFlag(int);

	// unused/inlined:
	void getTypeIndex(char*);
	void setUsingType(int, bool);

	static void initTekiMgr();

	// _00     = VTBL
	// _00-_1C = MonoObjectMgr?
	// TODO: members
};

#endif
