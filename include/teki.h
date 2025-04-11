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
#include "TAI/EffectAttack.h"
#include "zen/CallBack.h"

struct CollEvent;
struct CreaturePlatMgr;
struct NTeki;
struct PeveAccelerationEvent;
struct PeveCircleMoveEvent;
struct PeveHorizontalSinWaveEvent;
struct PeveParabolaEvent;
struct TAIeffectAttackEventCallBack;
struct Teki;
struct TekiAnimationManager;
struct TekiMgr;
struct TekiParameters;
struct TekiPersonality;
struct TekiStrategy;
struct TekiStrategyTable;
struct WorkObject;

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
	TEKI_NULL     = -1, // INVALID TEKI
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

DEFINE_ENUM_TYPE(TekiInteractType, Attack = 0, HitEffect = 1);

/**
 * @brief TODO
 */
struct TekiInteractionKey {
	TekiInteractionKey(int type, Interaction* interaction);

	int mInteractionType;      // _00
	Interaction* mInteraction; // _04
};

DEFINE_ENUM_TYPE(TekiEventType, Ground = 0, Entity = 1, Wall = 2, Pressed = 3, WakeUpCall = 4);

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct TekiEvent {
	TekiEvent(int collisionType, Teki* teki);
	TekiEvent(int collisionType, Teki* teki, Creature* other);

	void init(int collisionType, Teki* teki, Creature* other);

	TekiEventType::Type mEventType; // _00
	Teki* mTeki;                    // _04
	Creature* mOther;               // _08
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
	virtual void init(int tekiType);                     // _16C
	virtual void reset();                                // _170
	virtual void startMotion(int);                       // _174
	virtual void die();                                  // _178
	virtual void updateTimers();                         // _17C
	virtual void gravitate(f32);                         // _180
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _184 (weak)
	virtual f32 getTekiCollisionSize();                  // _188
	virtual void makeDamaged();                          // _18C
	virtual void startDamageMotion(f32, f32);            // _190
	virtual Teki* generateTeki(int);                     // _194
	virtual Teki* spawnTeki(int);                        // _198
	virtual void shootBall(Creature&);                   // _19C
	virtual void eventPerformed(TekiEvent&);             // _1A0
	virtual bool interact(struct TekiInteractionKey&);   // _1A4
	virtual bool interactDefault(TekiInteractionKey&);   // _1A8
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
	virtual void clearTekiOption(int opt) { mTekiOptions &= ~opt; } // _1D0
	virtual void setTekiOptions(int opts)                           // _1D4
	{
		mTekiOptions = opts;
	}
	virtual void clearTekiOptions() { mTekiOptions = 0; } // _1D8
	virtual void setAnimationKeyOption(int opt)           // _1DC
	{
		mAnimKeyOptions |= opt;
	}
	virtual void clearAnimationKeyOption(int opt) // _1E0
	{
		mAnimKeyOptions &= ~opt;
	}
	virtual void setAnimationKeyOptions(int opts) // _1E4
	{
		mAnimKeyOptions = opts;
	}
	virtual void clearAnimationKeyOptions() // _1E8
	{
		mAnimKeyOptions = 0;
	}
	virtual void dieSoon();                                                              // _1EC
	virtual void becomeCorpse();                                                         // _1F0
	virtual f32 getShadowSize() { return mTekiParams->getF(TPF_ShadowSize); }            // _70
	virtual bool isVisible() { return getTekiOption(TEKI_OPTION_VISIBLE) != 0; }         // _74
	virtual bool isOrganic() { return getTekiOption(TEKI_OPTION_ORGANIC) != 0; }         // _78
	virtual bool isAtari() { return getTekiOption(TEKI_OPTION_ATARI) != 0; }             // _84
	virtual bool isAlive() { return getTekiOption(TEKI_OPTION_ALIVE) != 0; }             // _88
	virtual bool needShadow() { return getTekiOption(TEKI_OPTION_SHADOW_VISIBLE) != 0; } // _90

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
	bool nearestAngleTarget(Creature*);
	bool cullableCenter(Creature&, f32);
	bool cullableSphere(Creature&, f32);
	bool inSectorPosition(Vector3f&, f32, f32);
	bool visibleCreature(Creature&);
	bool separateCreature(Creature&);
	bool contactCreature(Creature&);
	bool attackableCreature(Creature&);
	f32 calcTargetAngle(Vector3f&);
	bool moveToward(Vector3f&, f32);
	bool turnToward(f32, f32);
	void rotateTeki(f32);
	Creature* getClosestNaviPiki(Condition&, f32*);
	bool attackTarget(Creature&, f32, f32, Condition&);
	void outputHitCenter(Vector3f&);
	bool interactNaviPiki(Interaction&, Condition&);
	bool interactNavi(Interaction&, Condition&);
	bool interactPiki(Interaction&, Condition&);
	void flick();
	void flick(struct InteractFlick&, InteractFlick&);
	void flickUpper();
	void flickUpper(InteractFlick&);
	void flickLower();
	void flickLower(InteractFlick&);
	bool checkNaviPiki(Condition&);
	int countPikis(Condition&);
	int getFlickDamageCount(int);
	f32 getGravity();
	TekiStrategy* getStrategy();
	f32 getSeaLevel();
	f32 getYFromSeaLevel();
	void makePositionRoute(Vector3f&, Vector3f&, bool);
	void makeWayPointRoute(int, int, bool);
	WayPoint* getTargetNearestWayPoint(Vector3f&);
	WayPoint* getNearestWayPoint();
	WayPoint* getWayPoint(int);
	WayPoint* getRouteWayPoint(int);
	void updateLifeGauge();
	void drawRange(Graphics&, Vector3f&, f32, struct Colour&);
	CollPart* getFreeSlot();
	bool isFreeCollPart(CollPart*);
	void outputWorldAnimationPosition(Vector3f&, int, Matrix4f&);
	int getPositionMapCode(Vector3f&);
	int getPositionMapCode();
	bool inWaterTeki();
	void moveNestPosition();
	void startParticleGenerator(int);
	void stopParticleGenerator(int);
	void setParticleGeneratorPosition(int, Vector3f&);
	void setParticleGeneratorDirection(int, Vector3f&);
	f32 calcCollisionDistance(Creature&);
	f32 getCollisionSize();
	void setCorpsePartJoint(int, int);                          // unused
	void outputDirectionPosition(Vector3f&, f32, f32);          // unused
	void jumpTo(Vector3f&, f32);                                // unused
	bool insideDirection(Vector3f&);                            // unused
	bool attackRangeNaviPiki(Interaction&, Condition&);         // unused
	bool interactTeki(Interaction&, Condition&);                // unused
	int countTekis(Condition&);                                 // unused
	Matrix4f& getCameraAnimationMatrix(int);                    // unused
	void outputWorldAnimationMatrix(Matrix4f&, int, Matrix4f&); // unused
	Vector3f getCollisionCenter();                              // unused

	static bool arrivedAt(f32, f32);
	static bool isPellet(int);
	static f32 calcCircleDistanceStatic(Vector3f&, f32, Vector3f&, f32);
	static f32 calcSphereDistanceStatic(Vector3f&, f32, Vector3f&, f32);
	static bool moveTowardStatic(Vector3f&, Vector3f&, f32, Vector3f&);

	inline void setMotionSpeed(f32 speed)
	{
		setTekiOption(TEKI_OPTION_MANUAL_ANIMATION);
		mMotionSpeed = speed;
	}

	inline void setVisible() { setTekiOption(TEKI_OPTION_VISIBLE); }

	inline int getStateID() { return mStateID; }

	inline f32 getParticleFactor() { return getParameterF(TPF_RippleScale); } // rename later when we know what this is

	// these are all correct name-wise according to the map or the DLL.
	void setDirection(f32 dir) { mFaceDirection = dir; }
	f32 getDirection() { return mFaceDirection; } // weak function

	// NB: according to the DLL, this should use NMathI::checkBit, but that inflates stack too much
	bool getTekiOption(int opt) { return mTekiOptions & opt; }
	bool getAnimationKeyOption(int opt) { return mAnimKeyOptions & opt; }

	f32 getPersonalityF(int idx) { return mPersonality->getF(idx); } // weak
	int getPersonalityI(int idx) { return mPersonality->getI(idx); } // weak
	void setPersonalityF(int idx, f32 val) { mPersonality->setF(idx, val); }
	void setPersonalityI(int idx, int val) { mPersonality->setI(idx, val); }

	f32 getParameterF(int idx) { return mTekiParams->getF(idx); } // see Tekif32Params enum
	int getParameterI(int idx) { return mTekiParams->getI(idx); } // see TekiIntParams enum

	void outputDirectionVector(Vector3f& outDir) { BTeki::outputDirectionVector(getDirection(), outDir); }

	bool timerElapsed(int idx) { return mTimers[idx] <= 0.0f; }

	void clearCreaturePointers()
	{
		for (int i = 0; i < 4; i++) {
			mTargetCreatures[i].reset();
		}
	}

	// really nakata, was all this necessary (these are all DLL inlines)

	// NB: THIS INLINE NEEDS TO BE ABOVE STOPMOVE OR TAIIWAGEN SDATA BREAKS
	static void outputDirectionVector(f32 angle, Vector3f& outVec) { outVec.set(NMathF::sin(angle), 0.0f, NMathF::cos(angle)); }
	static f32 calcDirection(Vector3f& dir) { return NMathF::atan2(dir.x, dir.z); }

	void inputDirectionVector(Vector3f& dir) { setDirection(calcDirection(dir)); }

	void inputVelocity(Vector3f& vel) { mVelocity.input(vel); }
	void inputDrive(Vector3f& drive) { mTargetVelocity.input(drive); }
	void stopVelocity() { inputVelocity(Vector3f(0.0f, 0.0f, 0.0f)); }
	void stopDrive() { inputDrive(Vector3f(0.0f, 0.0f, 0.0f)); }
	void stopMove()
	{
		stopVelocity();
		stopDrive();
	}

	Vector3f& getDrive() { return mTargetVelocity; }
	f32 getDriveLength() { return mTargetVelocity.length(); }

	Vector3f& getNestPosition() { return mPersonality->mNestPosition; }
	f32 getTerritoryDistance() { return getNestPosition().distance(getPosition()); }

	ID32& getCorpsePartID(int paraID) { return mTekiParams->mParaIDs[paraID]; }

	void setCreaturePointer(int idx, Creature* target) { mTargetCreatures[idx].set(target); }
	Creature* getCreaturePointer(int idx) { return mTargetCreatures[idx].getPtr(); }
	void clearCreaturePointer(int idx) { mTargetCreatures[idx].reset(); }

	f32 getScaleRate() { return getParameterF(TPF_Scale) * getPersonalityF(TekiPersonality::FLT_Size); }

	f32 getAttackableRange() { return getParameterF(TPF_AttackableRange) * getScaleRate(); }
	f32 getAttackHitRange() { return getParameterF(TPF_AttackHitRange) * getScaleRate(); }
	f32 getLowerRange() { return getParameterF(TPF_LowerRange) * getScaleRate(); }
	f32 getAttackRange() { return getParameterF(TPF_AttackRange) * getScaleRate(); }
	f32 getScale() { return getScaleRate() * 1.0f; }

	f32 calcSphereDistance(Creature& other) { return getPosition().distance(other.getPosition()); }
	f32 calcTargetDirection(Vector3f& targetPos)
	{
		Vector3f dir;
		dir.sub2(targetPos, getPosition());
		return calcDirection(dir);
	}

	bool animationFinished() { return mTekiAnimator->isFinishing(); }

	/*
	    DLL inlines to make:
	    Vector3f& getVelocity();

	*/

	// this is basically two static enums smh
	static const int TEKI_OPTION_VISIBLE;
	static const int TEKI_OPTION_SHADOW_VISIBLE;
	static const int TEKI_OPTION_LIFE_GAUGE_VISIBLE;
	static const int TEKI_OPTION_ATARI;
	static const int TEKI_OPTION_ALIVE;
	static const int TEKI_OPTION_ORGANIC;
	static const int TEKI_OPTION_MANUAL_ANIMATION;
	static const int TEKI_OPTION_GRAVITATABLE;
	static const int TEKI_OPTION_INVINCIBLE;
	static const int TEKI_OPTION_PRESSED;
	static const int TEKI_OPTION_DRAWED;
	static const int TEKI_OPTION_SHAPE_VISIBLE;
	static const int TEKI_OPTION_DAMAGE_COUNTABLE;

	static const int ANIMATION_KEY_OPTION_FINISHED;
	static const int ANIMATION_KEY_OPTION_ACTION_0;
	static const int ANIMATION_KEY_OPTION_ACTION_1;
	static const int ANIMATION_KEY_OPTION_ACTION_2;
	static const int ANIMATION_KEY_OPTION_LOOPSTART;
	static const int ANIMATION_KEY_OPTION_LOOPEND;

	// _00       = VTBL
	// _000-_2B8 = Creature
	// _2B8-_2C0 = PelletView
	// _2C0-_2C4 = ptr to PaniAnimKeyListener
	TekiParameters* mTekiParams;                  // _2C4
	TekiPersonality* mPersonality;                // _2C8
	PaniTekiAnimator* mTekiAnimator;              // _2CC
	TekiShapeObject* mTekiShape;                  // _2D0
	CreaturePlatMgr mPlatMgr;                     // _2D4
	int mDeadState;                               // _31C
	TekiTypes mTekiType;                          // _320
	volatile int mStateID;                        // _324
	bool mIsStateReady;                           // _328
	u8 _329[0x330 - 0x329];                       // _329, TODO: work out members
	int mReturnStateID;                           // _330
	int mCurrentQueueId;                          // _334
	int mActionStateId;                           // _338
	f32 mStoredDamage;                            // _33C, damage waiting to be applied on next makeDamaged call
	f32 mDamageCount;                             // _340
	int _344;                                     // _344
	int mRouteWayPointMax;                        // _348, size of mRouteWayPoints array
	int mRouteWayPointCount;                      // _34C
	u32 mPathHandle;                              // _350
	int mCurrRouteWayPointID;                     // _354
	NVector3fIOClass mPositionIO;                 // _358
	NVector3fIOClass mVelocityIO;                 // _368
	NVector3fIOClass mAccelerationIO;             // _378
	NVector3f mTargetPosition;                    // _388, possibly position
	f32 mTargetAngle;                             // _394
	NVector3f mActionVelocity;                    // _398
	f32 _3A4;                                     // _3A4
	int mCurrentAnimEvent;                        // _3A8
	f32 mAnimationSpeed;                          // _3AC
	int mMotionLoopCount;                         // _3B0
	f32 mMotionSpeed;                             // _3B4
	f32 mPreStopAnimationSpeed;                   // _3B8
	int _3BC;                                     // _3BC, possibly mPelletPosyColor?
	f32 _3C0;                                     // _3C0
	f32 mTimers[5];                               // _3C4
	zen::particleGenerator** mParticleGenerators; // _3D8
	zen::PtclGenPack* mParticleGenPack;           // _3DC
	ShapeDynMaterials mDynamicMaterials;          // _3E0, unknown
	int mCorpsePartJoints[8];                     // _3F0
	int mTekiOptions;                             // _410
	int mAnimKeyOptions;                          // _414
	SmartPtr<Creature> mTargetCreatures[4];       // _418
	NVibrationFunction* mVibrationController;     // _428
	SearchData mTekiSearchData[3];                // _42C
	WayPoint** mRouteWayPoints;                   // _450, array of something, unsure what
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

	/**
	 * @brief TODO
	 */
	enum effFootIndexFlag {
		// TODO: this
	};

	/**
	 * @brief TODO
	 */
	enum ptclIndexFlag {
		PTCL_Unk0 = 0,
		PTCL_Unk1 = 1,
		PTCL_Unk2 = 2,
		PTCL_Unk3 = 3,
		PTCL_Unk4 = 4,
		PTCL_Unk5 = 5,
		PTCL_Unk6 = 6,
	};

	YTeki();

	virtual void doKill();          // _10C
	virtual void exitCourse();      // _110
	virtual void init(int tekiType) // _16C
	{
		BTeki::init(tekiType);
		mFrameCounter = 0.0f;
		for (int i = 0; i < 9; i++) {
			mPtclGenPtrs[i] = nullptr;
		}
	}

	bool isNaviWatch();
	void moveTowardPriorityFaceDir(Vector3f&, f32);
	void moveTowardPriorityFaceDir(Vector3f&, f32, f32);
	bool turnToTarget();
	void flyingStay(f32);
	void killStickToMouthPiki();
	bool startNewMotion(int);

	int getMapAttribute();

	// DLL inlines that have been checked:
	void setStaySwitch(bool isAppear) { mTekiSwitches.mStay = isAppear; }

	bool getFlyingSwitch() { return mTekiSwitches.mFlying; }
	void setFlyingSwitch(bool isFlying) { mTekiSwitches.mFlying = isFlying; }

	f32 getFootPosY(effFootIndexFlag footID) { return mFootPosY[footID]; }
	void setFootPosY(effFootIndexFlag footID, f32 posY) { mFootPosY[footID] = posY; }

	bool getFootEffectSwitch(effFootIndexFlag footID) { return (mTekiSwitches.mFootEffect) & (1 << footID); }
	void setFootEffectSwitch(effFootIndexFlag footID, bool isEff)
	{
		if (isEff) {
			mTekiSwitches.mFootEffect |= (1 << footID);
		} else {
			mTekiSwitches.mFootEffect &= ~(1 << footID);
		}
	}

	void setMapCode(int mapCode) { mMapCode = mapCode; }
	int getMapCode() { return mMapCode; }

	f32 getFrameCounter() { return mFrameCounter; }
	void setFrameCounter(f32 count) { mFrameCounter = count; }
	f32 addFrameCounter(f32 amt) { return mFrameCounter += amt; } // yeah.

	f32 getFrameCounterMax() { return mFrameCounterMax; }
	void setFrameCounterMax(f32 max) { mFrameCounterMax = max; }

	f32 getAngle() { return mTurnAngle; }
	void setAngle(f32 angle) { mTurnAngle = angle; }

	f32 getDororoGravity() { return mDororoGravity; }
	void setDororoGravity(f32 grav) { mDororoGravity = grav; }

	f32 getDesire() { return mDororoBarkDesire; }
	void setDesire(f32 val) { mDororoBarkDesire = val; }
	void addDesire(f32 amt) { mDororoBarkDesire += amt; }

	WorkObject* getWorkObjectPointer() { return mWorkObject; }
	void setWorkObjectPointer(WorkObject* obj) { mWorkObject = obj; }

	zen::particleGenerator* getPtclGenPtr(ptclIndexFlag idx) { return mPtclGenPtrs[idx]; }
	void setPtclGenPtr(ptclIndexFlag idx, zen::particleGenerator* ptclGen) { mPtclGenPtrs[idx] = ptclGen; }

	/*
	    DLL INLINED FUNCTIONS TO MAKE:

	    zen::CallBack1<zen::particleGenerator *> * getConeTypePtclCallBack();
	    zen::CallBack1<zen::particleGenerator *> * getCylinderTypePtclCallBack();
	    zen::CallBack1<zen::particleGenerator*>* getEventTypePtclCallBack();
	    void initConeTypePtclCallBack(Teki*, Vector3f&, Vector3f&, f32, f32, f32, f32, TAIeffectAttackEventCallBack*);
	    void initCylinderTYpePtclCallBack(Teki*, Vector3f&, Vector3f&, f32, f32, f32, f32, TAIeffectAttackEventCallBack*);
	    void initEventTypePtclCallBack();

	    f32 setAnimSpeed(f32);

	    f32 getSpeed();
	    void setSpeed(f32);
	    void addSpeed(f32);

	    f32 getExceptionalGravity();
	    void setExceptionalGravity(f32);

	    int getStatus();
	    void setStatus(int);

	    int getTableIndex();
	    void setTableIndex(int);

	    bool getTimerStart();
	    void setTimerStart(bool);

	    void setManualAnimation(bool);

	    bool getBiteSwitch();
	    void setBiteSwitch(bool);

	    bool getChokeSwitch();
	    void setChokeSwitch(bool);

	    bool getEffectSwitch();
	    void setEffectSwitch(bool);

	    bool getRunAwaySwitch();
	    void setRunAwaySwitch(bool);

	    bool getStaySwitch();
	*/

	// _00       = VTBL
	// _000-_46C = NTeki
	u8 _46C[0x470 - 0x46C];                  // _46C, TODO: work out members
	u32 _470;                                // _470, unknown
	int mMapCode;                            // _474
	f32 mFrameCounter;                       // _478
	f32 mFrameCounterMax;                    // _47C
	f32 mFootPosY[4];                        // _480, indexed by effFootIndexFlag
	f32 _490;                                // _490
	f32 mTurnAngle;                          // _494
	zen::particleGenerator* mPtclGenPtrs[8]; // _498, indexed by ptclIndexFlag
	u8 _4B8[0x4];                            // _4B8, unknown
	WorkObject* mWorkObject;                 // _4BC
	f32 mDororoGravity;                      // _4C0
	f32 mDororoBarkDesire;                   // _4C4
	struct {
		u32 m0 : 1;
		u32 m1 : 1;
		u32 m2 : 1;
		u32 mStay : 1;
		u32 mFlying : 1;
		u32 m5 : 2;
		u32 mFootEffect : 4;
	} mTekiSwitches;                         // _4C8
	TAIeffectAttackParam mEffectAttackParam; // _4CC
	ConeTypeCallBack mConeCallBack;          // _51C
	CylinderTypeCallBack mCylinderCallBack;  // _528
	EventTypeCallBack mEventCallBack;        // _530
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

	virtual ~TekiMgr() { }            // _48
	virtual void update();            // _4C
	virtual void refresh(Graphics&);  // _58
	virtual Creature* createObject(); // _80

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
	bool hasModel(int type);
	int getResultFlag(int);

	// unused/inlined:
	void setUsingType(int, bool);

	static void initTekiMgr();
	static int getTypeIndex(char*);

	static char* getTypeName(int idx) { return typeNames[idx]; }
	static int getTypeId(int idx) { return typeIds[idx]; }

	static char* typeNames[TEKI_TypeCount];
	static int typeIds[TEKI_TypeCount];

	bool isUsingType(int type) { return mUsingType[type]; }
	bool hasType(int type) { return mTekiParams[type] != nullptr; }
	bool isVisibleType(int type) { return mVisibleType[type]; }

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_3C = MonoObjectMgr
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
