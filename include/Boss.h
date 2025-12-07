#ifndef _BOSS_H
#define _BOSS_H

#include "Creature.h"
#include "CreatureProp.h"
#include "ID32.h"
#include "ObjectMgr.h"
#include "PaniAnimator.h"
#include "Plane.h"
#include "SearchSystem.h"
#include "Vector.h"
#include "types.h"

struct BirthInfo;
struct BossMgr;
struct GenObjectBoss;

#define BOSS_PROP         (static_cast<BossProp*>(mProps)->mBossProps)
#define C_BOSS_PROP(boss) (static_cast<BossProp*>((boss)->mProps)->mBossProps)

/**
 * @brief TODO
 */
enum BossID {
	BOSS_IDSTART     = 0,
	BOSS_Spider      = 0,
	BOSS_Snake       = 1,
	BOSS_Slime       = 2,
	BOSS_King        = 3,
	BOSS_Kogane      = 4,
	BOSS_Pom         = 5,
	BOSS_KingBack    = 6,
	BOSS_Nucleus     = 7,
	BOSS_CoreNucleus = 8,
	BOSS_BoxSnake    = 9,
	BOSS_Mizu        = 10,
	BOSS_Geyzer      = 11,
	BOSS_IDCOUNT, // 12
};

/**
 * @brief `GenObjectBoss` uses different IDs from the BossMgr.  CoreNucleus and Nucleus are skipped.
 */
enum GenBossID {
	GENBOSS_Spider   = 0,
	GENBOSS_Snake    = 1,
	GENBOSS_Slime    = 2,
	GENBOSS_King     = 3,
	GENBOSS_Kogane   = 4,
	GENBOSS_Pom      = 5,
	GENBOSS_KingBack = 6,
	GENBOSS_BoxSnake = 7,
	GENBOSS_Mizu     = 8,
	GENBOSS_Geyzer   = 9,
};

/**
 * @brief TODO
 *
 * @note Size: 0x1EC.
 */
struct BossProp : public CreatureProp {
public:
	/**
	 * @brief TODO
	 *
	 * @note Offset comments are relative to BossProp for ease of use.
	 */
	struct Properties : public Parameters {
		inline Properties()
		    : mTerritoryRadius(this, 200.0f, 0.0f, 0.0f, "b00", nullptr)
		    , mMaxWaitRadius(this, 100.0f, 0.0f, 0.0f, "b01", nullptr)
		    , mSearchRadius(this, 100.0f, 0.0f, 0.0f, "b02", nullptr)
		    , mSearchAngle(this, 360.0f, 0.0f, 0.0f, "b03", nullptr)
		    , mMaxHealth(this, 1000.0f, 0.0f, 0.0f, "b10", nullptr)
		    , mLifeRecoveryTime(this, 1.0f, 0.0f, 0.0f, "b13", nullptr)
		    , mLifeRecoveryRate(this, 0.0f, 0.0f, 0.0f, "b11", nullptr)
		    , _CC(this, 1.0f, 0.0f, 0.0f, "b14", nullptr)
		    , mBombDamageMultiplier(this, 1.0f, 0.0f, 0.0f, "b12", nullptr)
		    , mLifeGaugeScale(this, 5000.0f, 0.0f, 0.0f, "c00", nullptr)
		    , mLifeGaugeHeight(this, 30.0f, 0.0f, 0.0f, "c01", nullptr)
		    , mFlickChance(this, 1.0f, 0.0f, 0.0f, "d00", nullptr)
		    , mFlickKnockback(this, 100.0f, 0.0f, 0.0f, "d01", nullptr)
		    , mFlickDamage(this, 0.0f, 0.0f, 0.0f, "d02", nullptr)
		    , mRenderSphereRadius(this, 10.0f, 0.0f, 0.0f, "p00", nullptr)
		    , mRenderSphereHeight(this, 0.0f, 0.0f, 0.0f, "p01", nullptr)
		    , _15C(this, 1, 0, 0, "i10", nullptr)
		    , mFlickPikiCountAB(this, 10, 0, 0, "i00", nullptr)
		    , mFlickPikiCountBC(this, 20, 0, 0, "i01", nullptr)
		    , mFlickPikiCountCD(this, 30, 0, 0, "i02", nullptr)
		    , mFlickDamageCountA(this, 10, 0, 0, "i03", nullptr)
		    , mFlickDamageCountB(this, 50, 0, 0, "i04", nullptr)
		    , mFlickDamageCountC(this, 100, 0, 0, "i05", nullptr)
		    , mFlickDamageCountD(this, 200, 0, 0, "i06", nullptr)
		    , _1DC(this, 1, 0, 0, "i90", nullptr)
		{
		}

		// _58-_5C = Parameters
		Parm<f32> mTerritoryRadius;      // _5C, b00
		Parm<f32> mMaxWaitRadius;        // _6C, b01
		Parm<f32> mSearchRadius;         // _7C, b02
		Parm<f32> mSearchAngle;          // _8C, b03
		Parm<f32> mMaxHealth;            // _9C, b10
		Parm<f32> mLifeRecoveryTime;     // _AC, b13, recover (rate * max health) every n seconds
		Parm<f32> mLifeRecoveryRate;     // _BC, b11, fraction of max health to recover every time
		Parm<f32> _CC;                   // _CC, b14 - special attack effect?
		Parm<f32> mBombDamageMultiplier; // _DC, b12
		Parm<f32> mLifeGaugeScale;       // _EC, c00
		Parm<f32> mLifeGaugeHeight;      // _FC, c01
		Parm<f32> mFlickChance;          // _10C, d00
		Parm<f32> mFlickKnockback;       // _11C, d01
		Parm<f32> mFlickDamage;          // _12C, d02
		Parm<f32> mRenderSphereRadius;   // _13C, p00
		Parm<f32> mRenderSphereHeight;   // _14C, p01
		Parm<int> _15C;                  // _15C, i10, special damage count?
		Parm<int> mFlickPikiCountAB;     // _16C, i00, this amount and above, use damage threshold B
		Parm<int> mFlickPikiCountBC;     // _17C, i01, this amount and above, use damage threshold C
		Parm<int> mFlickPikiCountCD;     // _18C, i02, this amount and above, use damage threshold D
		Parm<int> mFlickDamageCountA;    // _19C, i03, damage count to cause flick with n < AB stickers
		Parm<int> mFlickDamageCountB;    // _1AC, i04, damage count to cause flick with AB <= n < BC stickers
		Parm<int> mFlickDamageCountC;    // _1BC, i05, damage count to cause flick with BC <= n < CD stickers
		Parm<int> mFlickDamageCountD;    // _1CC, i06, damage count to cause flick with n >= CD stickers
		Parm<int> _1DC;                  // _1DC, i90, AI culling type (0=Cull off camera, 1=AI always on)?
	};

	BossProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mBossProps.read(input);
	}

	// _54     = VTBL
	// _00-_58 = CreatureProp
	Properties mBossProps; // _58
};

/**
 * @brief TODO
 */
struct BossShapeObject {
	BossShapeObject(Shape*, char*);

	Shape* mShape;            // _00
	AnimContext mAnimContext; // _04
	AnimMgr* mAnimMgr;        // _14
};

/**
 * @brief TODO
 *
 * @note Size: 0x3B8.
 */
struct Boss : public Creature {
	friend struct BossMgr;

public:
	Boss(CreatureProp*);

	virtual bool isAlive() { return mIsAlive; }           // _88
	virtual bool isAtari() { return mIsAtari; }           // _84
	virtual bool isVisible() { return mIsVisible; }       // _74
	virtual bool isOrganic() { return mIsOrganic; }       // _78
	virtual bool isFixed() { return true; }               // _8C
	virtual bool ignoreAtari(Creature*) { return false; } // _98
	virtual Vector3f getCentre() { return mSRT.t; }       // _58
	virtual bool needShadow() { return mNeedShadow; }     // _90
	virtual f32 getShadowSize() { return mShadowSize; }   // _70
	virtual bool stimulate(immut Interaction&);           // _A0
	virtual void wallCallback(Plane&, DynCollObject*);    // _B4
	virtual void update() { }                             // _E0
	virtual void refresh(Graphics&) { }                   // _EC
	virtual void refresh2d(Graphics&);                    // _F0
	virtual void doKill() { }                             // _10C
	virtual void exitCourse() { }                         // _110
	virtual void collisionCallback(immut CollEvent&) { }  // _A8
	virtual bool isBossBgm() { return false; }            // _114
	virtual bool attackDefaultPortion() { return false; } // _118
	virtual void bombDamageCounter(CollPart*) { }         // _11C
	virtual void drawShape(Graphics&);                    // _120

	void initBoss(BirthInfo&, int);
	void calcFlickPiki();
	void createPellet(Vector3f&, f32, bool);
	bool changeDirection(f32);
	void stopMovement();
	void calcBossDamage();
	void makeTargetCreature();
	void makeTargetRandom(f32);
	bool chaseNaviTransit();
	bool chasePikiTransit();
	bool targetLostTransit();
	bool inSideWaitRangeTransit();
	bool outSideChaseRangeTransit();
	bool inSearchAngle(Creature*);
	bool flickPikiTransit();
	int getStickPikiCount();
	int getStickMouthPikiCount();
	int getStickNoMouthPikiCount();
	void killStickToMouthPiki();
	int getMapAttribute(Vector3f&);
	bool insideAndInSearch();
	void updateBoss();
	void refreshViewCulling(Graphics&);

	// unused/inlined:
	void towardFaceDirection(f32);
	bool checkInWater(Vector3f&);

	f32 getAnimTimer() { return mAnimTimer; }
	void addAnimTimer(f32 val) { mAnimTimer += val; }
	void setAnimTimer(f32 val) { mAnimTimer = val; }

	void setIsAlive(bool val) { mIsAlive = val; }
	void setIsAtari(bool val) { mIsAtari = val; }
	void setIsOrganic(bool val) { mIsOrganic = val; }
	void setInvincible(bool val) { mIsInvincible = val; }

	bool getInvincible() { return mIsInvincible; }
	bool getOnWall() { return mIsOnWall; }

	void setMotionFinish(bool isFinished) { mIsMotionFinished = isFinished; }
	bool getMotionFinish() { return mIsMotionFinished; }

	void setShadowNeed(bool val) { mNeedShadow = val; }
	void setOnWall(bool val) { mIsOnWall = val; }

	Creature* getTargetCreature() { return mTargetCreature; }
	void setTargetCreature(Creature* target) { mTargetCreature = target; }
	Vector3f* getTargetPosition() { return &mTargetPosition; }
	void setTargetPosition(Vector3f& pos) { mTargetPosition = pos; }

	int getCurrentState() { return mCurrentStateID; }
	void setCurrentState(int stateID) { mCurrentStateID = stateID; }

	int getNextState() { return mNextStateID; }
	void setNextState(int stateID) { mNextStateID = stateID; }

	void setShadowSize(f32 size) { mShadowSize = size; }

	int getLoopCounter() { return mAnimLoopCounter; }
	void setLoopCounter(int val) { mAnimLoopCounter = val; }
	void addLoopCounter(int amt) { mAnimLoopCounter += amt; }

	int getFlickDamageCount() { return mFlickDamageCount; }
	void setFlickDamageCount(int val) { mFlickDamageCount = val; }
	void addFlickDamageCount(int amt) { mFlickDamageCount += amt; }

	int getItemColour() { return mItemColour; }
	void setItemIndex(int val) { mItemIndex = val; }
	void setItemColour(int val) { mItemColour = val; }
	void setItemCount(int val) { mItemCount = val; }

	f32 getDamagePoint() { return mDamage; }
	void setDamagePoint(f32 damage) { mDamage = damage; }
	void addDamagePoint(f32 damage) { mDamage += damage; }

	bool getAlive() { return mCurrentLife > 0.0f; }

	Vector3f* getInitPosition() { return &mInitPosition; }
	void setInitPosition(Vector3f& pos) { mInitPosition = pos; }

	f32 getCurrentLife() { return mCurrentLife; }
	f32 getMaxLife() { return mMaxLife; }
	void subCurrentLife(f32 damage) { mCurrentLife -= damage; }

	inline f32 getWalkTimer() { return mWalkTimer; }
	inline void setWalkTimer(f32 val) { mWalkTimer = val; }
	inline void addWalkTimer(f32 val) { mWalkTimer += val; }

	inline f32 getAttackTimer() { return mAttackTimer; }
	inline void setAttackTimer(f32 val) { mAttackTimer = val; }
	inline void addAttackTimer(f32 val) { mAttackTimer += val; }

private:
	void recoveryLife();

protected:
	// _00      = VTBL
	// _00-_2B8 = Creature
	bool mIsAlive;                  // _2B8
	bool mIsAtari;                  // _2B9
	bool mIsVisible;                // _2BA
	bool mIsOrganic;                // _2BB
	bool mIsInvincible;             // _2BC
	bool mIsMotionFinished;         // _2BD
	bool mNeedShadow;               // _2BE
	bool mIsOnWall;                 // _2BF
	f32 mDamage;                    // _2C0
	f32 mCurrentLife;               // _2C4, current health (but there's a creature variable for that too)
	f32 mMaxLife;                   // _2C8, max health (but there's a creature variable for that too)
	f32 mLifeRecoveryTimer;         // _2CC
	f32 mWalkTimer;                 // _2D0, walk timer
	f32 mAttackTimer;               // _2D4, either mAttackTimer or mWalkTimer, unsure
	f32 mAnimTimer;                 // _2D8
	f32 mSearchAngle;               // _2DC
	f32 mShadowSize;                // _2E0
	int mCurrentStateID;            // _2E4
	int mNextStateID;               // _2E8
	int mAnimLoopCounter;           // _2EC
	int mFlickDamageCount;          // _2F0
	int mItemIndex;                 // _2F4
	int mItemColour;                // _2F8
	int mItemCount;                 // _2FC
	Vector3f mInitPosition;         // _300
	Vector3f mTargetPosition;       // _30C
	Creature* mTargetCreature;      // _318
	ID32 mPelletID;                 // _31C
	Plane mWallPlane;               // _328
	DynCollObject* mWallCollObject; // _338
	PaniTekiAnimator mAnimator;     // _33C
	BossShapeObject* mShapeObject;  // _390
	SearchData mSearchData[3];      // _394
};

/**
 * @brief TODO
 */
struct BossNode : public CoreNode {
	BossNode() { }

	BossNode(Boss* boss) { mBoss = boss; }

	// _00     = VTBL
	// _00-_14 = CoreNode
	Boss* mBoss; // _14
};

/**
 * @brief TODO
 */
struct BossAnimationManager : public Node {
	BossAnimationManager(BossMgr*);

	// _00     = VTBL
	// _00-_20 = Node
	BossMgr* mBossMgr; // _20
};

/**
 * @brief TODO
 */
struct BossMgr : public ObjectMgr {
public:
	BossMgr();

	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14
	virtual ~BossMgr() { }              // _48
	virtual void update();              // _4C
	virtual void refresh(Graphics&);    // _58
	virtual int getSize();              // _60
	virtual int getMax();               // _64
	virtual void killAll();             // _74

	void addUseCount(int, int);
	void constructBoss();
	void initSlime(int);
	void init(int, int);
	Creature* create(int, BirthInfo&, GenObjectBoss*);
	void kill(Creature*);
	void refresh2d(Graphics&);
	void finalSetup();
	BossShapeObject* getBossShapeObject(int bossID);

	// unused/inlined:
	bool useBoss(int bossID);
	int getUseCount(int bossID);

private:
	void animatorInit(Boss*);
	void initSpider(int);
	void initSnake(int);
	void initBoxSnake(int);
	void initKing(int);
	void initKogane(int);
	void initPom(int);
	void initKingBack(int);
	void initMizu(int);
	void initGeyzer(int);
	void setBossParam(Boss*, GenObjectBoss*);
	Boss* createBoss(int);

	// This has no getter but it's the only thing holding this class back from being properly encapsulated.  My guess
	// is it was genuinely left public in the original codebase because it is a stupid member variable to begin with.
public:
	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = ObjectMgr
	int mSlimeCreatureCount; // _28, this is always 4, idk why it's a variable

protected:
	bool mForceUpdate;               // _2C
	int* mActiveBossCounts;          // _30, indexed by BossID enum
	int* mInitialisedBossCounts;     // _34, indexed by BossID enum
	BossNode* mActiveNodes;          // _38, array of 12 BossNode lists, indexed by BossID enum
	BossNode* mFreeNodes;            // _3C, array of 12 BossNode lists, indexed by BossID enum
	int* mUseCounts;                 // _40, indexed by BossID enum
	BossAnimationManager* mAnimMgr;  // _44
	BossShapeObject** mShapeObjects; // _48, indexed by BossID enum
	BossProp** mBossProps;           // _4C, indexed by BossID enum
	PaniMotionTable* mMotionTable;   // _50
};

extern BossMgr* bossMgr;

#endif
