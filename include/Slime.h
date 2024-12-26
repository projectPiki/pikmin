#ifndef _SLIME_H
#define _SLIME_H

#include "types.h"
#include "Boss.h"
#include "Collision.h"

struct SlimeAi;
struct SlimeBody;
struct SlimeCreature;

/**
 * @brief TODO.
 */
struct SlimeProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to SlimeProp for ease of use.
	 */
	struct SlimeProperties : public Parameters {
		inline SlimeProperties()
		    : _204(this, 100.0f, 0.0f, 0.0f, "p00", nullptr)
		    , _214(this, 50.0f, 0.0f, 0.0f, "s00", nullptr)
		    , _224(this, 20.0f, 0.0f, 0.0f, "s01", nullptr)
		    , _234(this, 200.0f, 0.0f, 0.0f, "s10", nullptr)
		    , _244(this, 50.0f, 0.0f, 0.0f, "s11", nullptr)
		    , _254(this, 225.0f, 0.0f, 0.0f, "s20", nullptr)
		    , _264(this, 200.0f, 0.0f, 0.0f, "s21", nullptr)
		    , _274(this, 40.0f, 0.0f, 0.0f, "s30", nullptr)
		    , _284(this, 10.0f, 0.0f, 0.0f, "s40", nullptr)
		    , _294(this, 0.85f, 0.0f, 0.0f, "s50", nullptr)
		    , _2A4(this, 0.99f, 0.0f, 0.0f, "s51", nullptr)
		    , _2B4(this, 200.0f, 0.0f, 0.0f, "s60", nullptr)
		    , _2C4(this, 100.0f, 0.0f, 0.0f, "s61", nullptr)
		    , _2D4(this, 50.0f, 0.0f, 0.0f, "s62", nullptr)
		    , _2E4(this, 10.0f, 0.0f, 0.0f, "s63", nullptr)
		    , _2F4(this, 1.0f, 0.0f, 0.0f, "s64", nullptr)
		    , _304(this, 0.9f, 0.0f, 0.0f, "s70", nullptr)
		    , _314(this, 20.0f, 0.0f, 0.0f, "s71", nullptr)
		    , _324(this, 500.0f, 0.0f, 0.0f, "s80", nullptr)
		    , _334(this, 20.0f, 0.0f, 0.0f, "b00", nullptr)
		    , _344(this, 2.0f, 0.0f, 0.0f, "b01", nullptr)
		    , _354(this, 2.0f, 0.0f, 0.0f, "b02", nullptr)
		    , _364(this, 100.0f, 0.0f, 0.0f, "b10", nullptr)
		    , _374(this, 1000.0f, 0.0f, 0.0f, "b20", nullptr)
		    , _384(this, 50.0f, 0.0f, 0.0f, "b21", nullptr)
		    , _394(this, 0.7f, 0.0f, 0.0f, "b30", nullptr)
		    , _3A4(this, 0.5f, 0.0f, 0.0f, "b31", nullptr)
		    , mMaxSortCount(this, 10, 0, 0, "i00", nullptr)
		{
		}

		// _200-_204 = Parameters
		Parm<f32> _204;          // _204, p00 - detection radius?
		Parm<f32> _214;          // _214, s00 - max moving speed?
		Parm<f32> _224;          // _224, s01 - min moving speed?
		Parm<f32> _234;          // _234, s10 - normal max length?
		Parm<f32> _244;          // _244, s11 - normal min length?
		Parm<f32> _254;          // _254, s20 - max length at sticking?
		Parm<f32> _264;          // _264, s21 - min length at sticking?
		Parm<f32> _274;          // _274, s30 - dist between nuclei?
		Parm<f32> _284;          // _284, s40 - max stick piki num?
		Parm<f32> _294;          // _294, s50 - trace mid point?
		Parm<f32> _2A4;          // _2A4, s51 - mid point spring?
		Parm<f32> _2B4;          // _2B4, s60 - damage length 1?
		Parm<f32> _2C4;          // _2C4, s61 - damage length 2?
		Parm<f32> _2D4;          // _2D4, s62 - damage ratio 1?
		Parm<f32> _2E4;          // _2E4, s63 - damage ratio 2?
		Parm<f32> _2F4;          // _2F4, s64 - damage ratio 3?
		Parm<f32> _304;          // _304, s70 - contract trace end?
		Parm<f32> _314;          // _314, s71 - contract end spring?
		Parm<f32> _324;          // _324, s80 - dead scale speed?
		Parm<f32> _334;          // _334, b00 - body height?
		Parm<f32> _344;          // _344, b01 - body thickness (elongation)?
		Parm<f32> _354;          // _354, b02 - body thickness (contraction)?
		Parm<f32> _364;          // _364, b10 - max radius compensation?
		Parm<f32> _374;          // _374, b20 - radius contraction score?
		Parm<f32> _384;          // _384, b21 - vertex position score?
		Parm<f32> _394;          // _394, b30 - trace creature?
		Parm<f32> _3A4;          // _3A4, b31 - creature spring?
		Parm<int> mMaxSortCount; // _3B4, i00 - how many times to "sort" collision spheres
	};

	SlimeProp();

	virtual void read(RandomAccessStream&); // _08

	// _F8       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	SlimeProperties mSlimeProps; // _200
};

/**
 * @brief TODO.
 */
struct Slime : public Boss {

	/**
	 * @brief TODO.
	 *
	 * @note Size: 0x24.
	 */
	struct BoundSphereUpdater : public CollPartUpdater {
		BoundSphereUpdater(Slime* slime) { mSlime = slime; }

		virtual Vector3f getPos(); // _08
		virtual f32 getSize();     // _0C

		// _00     = VTBL
		// _00-_1C = CollPartUpdater
		Slime* mSlime; // _1C
		f32 mSize;     // _20
	};

	/**
	 * @brief TODO.
	 *
	 * @note Size: 0x24.
	 */
	struct CollideSphereUpdater : public CollPartUpdater {
		CollideSphereUpdater() { }

		virtual Vector3f getPos(); // _08
		virtual f32 getSize();     // _0C

		inline void init(Slime* slime, SlimeCreature* creature)
		{
			mSlime    = slime;
			mCreature = creature;
		}

		// _00     = VTBL
		// _00-_1C = CollPartUpdater
		Slime* mSlime;            // _1C
		SlimeCreature* mCreature; // _20
	};

	/**
	 * @brief TODO.
	 *
	 * @note Size: 0x20.
	 */
	struct TubeSphereUpdater : public CollPartUpdater {
		TubeSphereUpdater() { }

		virtual Vector3f getPos(); // _08
		virtual f32 getSize();     // _0C

		// _00     = VTBL
		// _00-_1C = CollPartUpdater
		CollPart* mSphere; // _1C
	};

	Slime(CreatureProp*, BossShapeObject*);

	virtual void init(Vector3f&);               // _28
	virtual f32 getiMass();                     // _38
	virtual f32 getCentreSize();                // _5C
	virtual void collisionCallback(CollEvent&); // _A8
	virtual void update();                      // _E0
	virtual void refresh(Graphics&);            // _EC
	virtual void doAI();                        // _104
	virtual void doAnimation();                 // _108
	virtual void doKill();                      // _10C
	virtual void exitCourse();                  // _110
	virtual void drawShape(Graphics&);          // _120

	inline CollideSphereUpdater* getCollideUpdater(int idx) { return &mCollideSphereUpdaters[idx]; }

	// _00      = VTBL
	// _00-_3B8 = Boss
	BoundSphereUpdater* mCentreUpdater;           // _3B8
	CollideSphereUpdater* mCollideSphereUpdaters; // _3BC
	TubeSphereUpdater* mTubeSphereUpdaters;       // _3C0
	u8 _3C4;                                      // _3C4
	u8 _3C5;                                      // _3C5
	u32 _3C8;                                     // _3C8, unknown
	int _3CC;                                     // _3CC
	f32 _3D0;                                     // _3D0
	f32 _3D4;                                     // _3D4
	f32 _3D8;                                     // _3D8
	Vector3f _3DC;                                // _3DC
	Vector3f _3E8;                                // _3E8
	SlimeCreature** mSlimeCreatures;              // _3F4
	u8 _3F8[0x8];                                 // _3F8, unknown
	SlimeAi* mSlimeAi;                            // _400
	SlimeBody* mSlimeBody;                        // _404
};

/**
 * @brief TODO.
 *
 * @note Size: 0x20.
 */
struct SlimeBody {
	SlimeBody(Slime*);

	void init(Slime*);
	void sortPosition(Vector3f*, Vector3f*, Vector3f*);
	void update();
	void refresh(BossShapeObject*, Graphics&);

	// unused/inlined:
	void traceCreaturePosition();
	void makeCentrePosition();
	void makeInnerPosition();
	void makeMaxRadius();
	void setSpherePosition();
	void calcVertexScore(Vector3f*, Vector3f*, f32*);
	void makeSlimeBody();
	void setJointPosition(BossShapeObject*, Graphics&);

	u8 _00[0x20]; // _00, unknown
};

/**
 * @brief TODO.
 */
struct SlimeCreature : public Creature {
	SlimeCreature(CreatureProp*);

	virtual f32 getiMass();                 // _38
	virtual f32 getSize();                  // _3C
	virtual Vector3f getCentre();           // _58
	virtual void setCentre(Vector3f&) { }   // _6C
	virtual bool isAtari();                 // _84
	virtual bool isAlive();                 // _88
	virtual bool isFixed() { return true; } // _8C
	virtual bool ignoreAtari(Creature*);    // _98
	virtual void update();                  // _E0
	virtual void refresh(Graphics&);        // _EC
	virtual void doAI();                    // _104
	virtual void doAnimation();             // _108
	virtual void doKill();                  // _10C

	void init(Vector3f&, Slime*);

	// _00      = VTBL
	// _00-_2B8 = Creature
	Slime* mSlime;             // _2B8
	Vector3f _2BC;             // _2BC
	SearchData mSearchData[3]; // _2C8
};

/**
 * @brief TODO.
 *
 * @note Size: 0x24.
 */
struct SlimeAi {
	SlimeAi(Slime*);

	void init(Slime*);
	void addDamagePoint(f32);
	void calcBubblePiki();
	void calcStickersRatio();
	void playExpandingSound();
	void calcCollisionCheck();
	void setLeaderNearerTarget();
	void moveFlagCheck();
	void makeFollowerVelocity();
	void makeLeaderVelocity();
	void setMidPointVelocity();
	void calcContractDamage();
	void contractCoreFlickPiki();
	void contractSubFlickPiki();
	void inCaseOfContract();
	void makeTargetRandom();
	void chaseNaviTransit();
	void chasePikiTransit();
	void targetLostTransit();
	void appearTransit();
	void initDie(int);
	void appearState();
	void update();

	// unused/inlined:
	void setEveryFrame();
	void afterProcessing();
	void setLeaderIndex();
	void makeInterrelation();
	void makeBodyThickness();
	void makeTargetPosition();
	void walkAllState();
	void setDieGoal();
	void setContractGoal();
	void setExpansionGoal();
	void setAppearGoal();
	void bothEndsToGoal();
	void bothEndsToAppearGoal();
	void setVelocity(f32);
	void motionFinishTransit();
	void dieTransit();
	void outSideChaseRangeTransit();
	void inSideWaitRangeTransit();
	void collisionContractTransit();
	void dissolutionContractTransit();
	void finishContractTransit();
	void finishExpansionTransit();
	void disAppearTransit();
	void initWalk(int);
	void initChase(int);
	void initContract(int);
	void initExpansion(int);
	void initAppear(int);
	void initDisAppear(int);
	void dieState();
	void walkRandomState();
	void walkGoHomeState();
	void chaseNaviState();
	void chasePikiState();
	void contractState();
	void expansionState();
	void stayState();
	void disAppearState();

	u8 _00[0x20];  // _00, unknown
	Slime* mSlime; // _20
};

#endif
