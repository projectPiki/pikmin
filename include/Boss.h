#ifndef _BOSS_H
#define _BOSS_H

#include "types.h"
#include "Creature.h"
#include "CreatureProp.h"
#include "ID32.h"
#include "PaniAnimator.h"
#include "ObjectMgr.h"
#include "SearchSystem.h"
#include "Vector.h"

struct BirthInfo;
struct GenObjectBoss;

/**
 * @brief TODO
 */
struct BossProp : public CreatureProp {

	/**
	 * @brief TODO
	 *
	 * @note Offset comments are relative to BossProp for ease of use.
	 */
	struct Properties : public Parameters {
		inline Properties()
		    : mTerritoryRadius(this, 200.0f, 0.0f, 0.0f, "b00", nullptr)
		    , _6C(this, 100.0f, 0.0f, 0.0f, "b01", nullptr)
		    , _7C(this, 100.0f, 0.0f, 0.0f, "b02", nullptr)
		    , _8C(this, 360.0f, 0.0f, 0.0f, "b03", nullptr)
		    , mMaxHealth(this, 1000.0f, 0.0f, 0.0f, "b10", nullptr)
		    , _AC(this, 1.0f, 0.0f, 0.0f, "b13", nullptr)
		    , _BC(this, 0.0f, 0.0f, 0.0f, "b11", nullptr)
		    , _CC(this, 1.0f, 0.0f, 0.0f, "b14", nullptr)
		    , _DC(this, 1.0f, 0.0f, 0.0f, "b12", nullptr)
		    , _EC(this, 5000.0f, 0.0f, 0.0f, "c00", nullptr)
		    , _FC(this, 30.0f, 0.0f, 0.0f, "c01", nullptr)
		    , mFlickChance(this, 1.0f, 0.0f, 0.0f, "d00", nullptr)
		    , mFlickKnockback(this, 100.0f, 0.0f, 0.0f, "d01", nullptr)
		    , mFlickDamage(this, 0.0f, 0.0f, 0.0f, "d02", nullptr)
		    , mRenderSphereRadius(this, 10.0f, 0.0f, 0.0f, "p00", nullptr)
		    , mRenderSphereHeight(this, 0.0f, 0.0f, 0.0f, "p00", nullptr)
		    , _15C(this, 1, 0, 0, "i10", nullptr)
		    , _16C(this, 10, 0, 0, "i00", nullptr)
		    , _17C(this, 20, 0, 0, "i01", nullptr)
		    , _18C(this, 30, 0, 0, "i02", nullptr)
		    , _19C(this, 10, 0, 0, "i03", nullptr)
		    , _1AC(this, 50, 0, 0, "i04", nullptr)
		    , _1BC(this, 100, 0, 0, "i05", nullptr)
		    , _1CC(this, 200, 0, 0, "i06", nullptr)
		    , _1DC(this, 1, 0, 0, "i90", nullptr)
		{
		}

		// _58-_5C = Parameters
		Parm<f32> mTerritoryRadius;    // _5C, b00
		Parm<f32> _6C;                 // _6C, b01 - weight area?
		Parm<f32> _7C;                 // _7C, b02 - search radius?
		Parm<f32> _8C;                 // _8C, b03 - search angle?
		Parm<f32> mMaxHealth;          // _9C, b10
		Parm<f32> _AC;                 // _AC, b13 - recovery time?
		Parm<f32> _BC;                 // _BC, b11 - recovery rate?
		Parm<f32> _CC;                 // _CC, b14 - special attack effect?
		Parm<f32> _DC;                 // _DC, b12 - bomb effectiveness?
		Parm<f32> _EC;                 // _EC, c00 - life gauge scale?
		Parm<f32> _FC;                 // _FC, c01 - life gauge height?
		Parm<f32> mFlickChance;        // _10C, d00
		Parm<f32> mFlickKnockback;     // _11C, d01
		Parm<f32> mFlickDamage;        // _12C, d02
		Parm<f32> mRenderSphereRadius; // _13C, p00
		Parm<f32> mRenderSphereHeight; // _14C, p01
		Parm<int> _15C;                // _15C, i10, special damage count?
		Parm<int> _16C;                // _16C, i00, flick piki count 1?
		Parm<int> _17C;                // _17C, i01, flick piki count 2?
		Parm<int> _18C;                // _18C, i02, flick piki count 3?
		Parm<int> _19C;                // _19C, i03, flick damage count 1?
		Parm<int> _1AC;                // _1AC, i04, flick damage count 2?
		Parm<int> _1BC;                // _1BC, i05, flick damage count 3?
		Parm<int> _1CC;                // _1CC, i06, flick damage count 4?
		Parm<int> _1DC;                // _1DC, i90, AI culling type (0=Cull off camera, 1=AI always on)?
	};

	BossProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
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
	Boss(CreatureProp*);

	virtual Vector3f getCentre();                      // _58
	virtual f32 getShadowSize();                       // _70
	virtual bool isVisible();                          // _74
	virtual bool isOrganic();                          // _78
	virtual bool isAtari();                            // _84
	virtual bool isAlive();                            // _88
	virtual bool isFixed();                            // _8C
	virtual bool needShadow();                         // _90
	virtual bool ignoreAtari(Creature*);               // _98
	virtual bool stimulate(Interaction&);              // _A0
	virtual void collisionCallback(CollEvent&);        // _A8
	virtual void wallCallback(Plane&, DynCollObject*); // _B4
	virtual void update();                             // _E0
	virtual void refresh(Graphics&);                   // _EC
	virtual void refresh2d(Graphics&);                 // _F0
	virtual void doKill();                             // _10C
	virtual void exitCourse();                         // _110
	virtual bool isBossBgm();                          // _114
	virtual bool attackDefaultPortion();               // _118
	virtual void bombDamageCounter(CollPart*);         // _11C
	virtual void drawShape(Graphics&);                 // _120

	void initBoss(struct BirthInfo&, int);
	void calcFlickPiki();
	void createPellet(Vector3f&, f32, bool);
	void changeDirection(f32);
	void stopMovement();
	void calcBossDamage();
	void makeTargetCreature();
	void makeTargetRandom(f32);
	void chaseNaviTransit();
	void chasePikiTransit();
	void targetLostTransit();
	void inSideWaitRangeTransit();
	void outSideChaseRangeTransit();
	bool inSearchAngle(Creature*);
	void flickPikiTransit();
	int getStickPikiCount();
	int getStickMouthPikiCount();
	int getStickNoMouthPikiCount();
	void killStickToMouthPiki();
	void getMapAttribute(Vector3f&);
	bool insideAndInSearch();
	void updateBoss();
	void refreshViewCulling(Graphics&);

	// unused/inlined:
	void towardFaceDirection(f32);
	void checkInWater(Vector3f&);
	void recoveryLife();

	inline f32 getMotionSpeed() { return mMotionSpeed; }
	inline f32 setMotionSpeed(f32 speed) { mMotionSpeed = speed; }

	inline void set2B8(u8 val) { _2B8 = val; }
	inline void set2BB(u8 val) { _2BB = val; }
	inline void set2BD(u8 val) { _2BD = val; }
	inline void set2BE(u8 val) { _2BE = val; }

	inline int getCurrStateID() { return _2E4; }
	inline void set2E0(f32 val) { _2E0 = val; }  // name these better later
	inline void set2E4(int val) { _2E4 = val; }  // name these better later
	inline void set2E8(int val) { _2E8 = val; }  // name these better later
	inline void set2EC(int val) { _2EC = val; }  // name these better later
	inline void set2D4(f32 val) { _2D4 = val; }  // name these better later
	inline void inc2EC(int amt) { _2EC += amt; } // name these better later

	// these names are a guess
	inline f32 getDamage() { return mDamage; }
	inline void setDamage(f32 damage) { mDamage = damage; }
	inline void addDamage(f32 damage) { mDamage += damage; }

	inline bool isDead() { return !(mCurrentHealth > 0.0f); }
	inline bool hasHealth() { return mCurrentHealth > 0.0f; }

	inline bool is2BD() { return _2BD; }

	// _00      = VTBL
	// _00-_2B8 = Creature
	u8 _2B8;                       // _2B8
	u8 _2B9;                       // _2B9
	u8 _2BA;                       // _2BA
	u8 _2BB;                       // _2BB
	u8 _2BC;                       // _2BC
	bool _2BD;                     // _2BD
	u8 _2BE;                       // _2BE
	u8 _2BF;                       // _2BF
	f32 mDamage;                   // _2C0
	f32 mCurrentHealth;            // _2C4
	f32 mMaxHealth;                // _2C8
	u8 _2CC[0x2D4 - 0x2CC];        // _2CC, unknown
	f32 _2D4;                      // _2D4
	f32 mMotionSpeed;              // _2D8
	u8 _2DC[0x2E0 - 0x2DC];        // _2DC, unknown
	f32 _2E0;                      // _2E0
	u32 _2E4;                      // _2E4, maybe int?
	u32 _2E8;                      // _2E8, maybe int?
	u32 _2EC;                      // _2EC, maybe int?
	u8 _2F0[0x300 - 0x2F0];        // _2F0, unknown
	Vector3f _300;                 // _300
	Vector3f _30C;                 // _30C
	u8 _318[0x4];                  // _318, unknown
	ID32 mID;                      // _31C
	Vector3f _328;                 // _328
	u8 _334[0x8];                  // _334, unknown
	PaniTekiAnimator mAnimator;    // _33C
	BossShapeObject* mShapeObject; // _390
	SearchData mSearchData[3];     // _394
};

/**
 * @brief TODO
 */
struct BossNode : public CoreNode {
	BossNode();

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct BossMgr : public ObjectMgr {
	BossMgr();

	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14
	virtual ~BossMgr();                 // _48
	virtual void update();              // _4C
	virtual void refresh(Graphics&);    // _58
	virtual int getSize();              // _60
	virtual int getMax();               // _64
	virtual void killAll();             // _74

	void addUseCount(int, int);
	void constructBoss();
	void initSlime(int);
	void init(int, int);
	Boss* create(int, BirthInfo&, GenObjectBoss*);
	void kill(Creature*);
	void refresh2d(Graphics&);
	void finalSetup();
	void getBossShapeObject(int);

	// unused/inlined:
	void useBoss(int);
	void getUseCount(int);
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
	void createBoss(int);

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = ObjectMgr
	int _28; // _28, unknown - number of slimecreatures? number of bosses?
};

/**
 * @brief TODO
 */
struct BossAnimationManager : public Node {
	BossAnimationManager(BossMgr*);

	// _00     = VTBL
	// _00-_20 = Node
	BossMgr* mBossMgr; // _20
	                   // TODO: members
};

extern BossMgr* bossMgr;

#endif
