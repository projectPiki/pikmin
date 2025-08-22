#ifndef _SLIME_H
#define _SLIME_H

#include "Boss.h"
#include "Collision.h"
#include "types.h"

/////////// Goolix (Slime) ///////////
// Goolix is comprised of lots of parts:
//    - Slime (main controlling entity)
//    - SlimeBody (mechanics)
//    - SlimeAi (state machine)
//    - CoreNucleus (pale core that "follows" the navi)
//    - Nucleus (dark core that pikis can attack/stick to)
//    - SlimeCreature (4 invisible entities to help control the locations of the goo)
//
// CoreNucleus and Nucleus also have their own state machines (CoreNucleusAi and NucleusAi)
// that help support the main creature's actions.

struct CoreNucleus;
struct Nucleus;
struct SlimeAi;
struct SlimeBody;
struct SlimeCreature;
struct Slime;

#define SLIME_PROP          (static_cast<SlimeProp*>(mProps)->mSlimeProps)
#define C_SLIME_PROP(slime) (static_cast<SlimeProp*>((slime)->mProps)->mSlimeProps)

/**
 * @brief TODO.
 */
enum SlimeAIStateID {
	SLIMEAI_Die        = 0,
	SLIMEAI_WalkRandom = 1,
	SLIMEAI_ChaseNavi  = 2,
	SLIMEAI_ChasePiki  = 3,
	SLIMEAI_WalkGoHome = 4,
	SLIMEAI_Contract   = 5,
	SLIMEAI_Expansion  = 6,
	SLIMEAI_Stay       = 7,
	SLIMEAI_Appear     = 8,
	SLIMEAI_Disappear  = 9,
};

/**
 * @brief TODO.
 */
enum SlimeCreatureIndexID {
	SLIMECREATURE_CoreOuter    = 0,
	SLIMECREATURE_CoreInner    = 1,
	SLIMECREATURE_NucleusInner = 2,
	SLIMECREATURE_NucleusOuter = 3,
	SLIMECREATURE_COUNT, // 4
};

/**
 * @brief TODO.
 */
enum SlimeContractHitType {
	SLIMEHIT_NoHit = -1,
	SLIMEHIT_Small = 0,
	SLIMEHIT_Mid   = 1,
	SLIMEHIT_Large = 2,
};

/**
 * @brief TODO.
 */
struct SlimeProp : public BossProp, public CoreNode {
public:
	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to SlimeProp for ease of use.
	 */
	struct SlimeProperties : public Parameters {
		inline SlimeProperties()
		    : mDetectionRadius(this, 100.0f, 0.0f, 0.0f, "p00", nullptr)
		    , mMaxMoveSpeed(this, 50.0f, 0.0f, 0.0f, "s00", nullptr)
		    , mMinMoveSpeed(this, 20.0f, 0.0f, 0.0f, "s01", nullptr)
		    , mNormalMaxLength(this, 200.0f, 0.0f, 0.0f, "s10", nullptr)
		    , mNormalMinLength(this, 50.0f, 0.0f, 0.0f, "s11", nullptr)
		    , mMaxLengthAtSticking(this, 225.0f, 0.0f, 0.0f, "s20", nullptr)
		    , mMinLengthAtSticking(this, 200.0f, 0.0f, 0.0f, "s21", nullptr)
		    , mDistanceBetweenNuclei(this, 40.0f, 0.0f, 0.0f, "s30", nullptr)
		    , mMaxStickPikiNum(this, 10.0f, 0.0f, 0.0f, "s40", nullptr)
		    , mTraceMidPoint(this, 0.85f, 0.0f, 0.0f, "s50", nullptr)
		    , mMidPointSpring(this, 0.99f, 0.0f, 0.0f, "s51", nullptr)
		    , mDamageLengthLarge(this, 200.0f, 0.0f, 0.0f, "s60", nullptr)
		    , mDamageLengthMid(this, 100.0f, 0.0f, 0.0f, "s61", nullptr)
		    , mDamageRatioLarge(this, 50.0f, 0.0f, 0.0f, "s62", nullptr)
		    , mDamageRatioMid(this, 10.0f, 0.0f, 0.0f, "s63", nullptr)
		    , mDamageRatioSmall(this, 1.0f, 0.0f, 0.0f, "s64", nullptr)
		    , mContractTraceEnd(this, 0.9f, 0.0f, 0.0f, "s70", nullptr)
		    , mContractSpringEnd(this, 20.0f, 0.0f, 0.0f, "s71", nullptr)
		    , mDeadScaleSpeed(this, 500.0f, 0.0f, 0.0f, "s80", nullptr)
		    , mBodyHeight(this, 20.0f, 0.0f, 0.0f, "b00", nullptr)
		    , mBodyThicknessElongate(this, 2.0f, 0.0f, 0.0f, "b01", nullptr)
		    , mBodyThicknessContract(this, 2.0f, 0.0f, 0.0f, "b02", nullptr)
		    , mMaxRadiusCompensation(this, 100.0f, 0.0f, 0.0f, "b10", nullptr)
		    , mRadiusContractionScore(this, 1000.0f, 0.0f, 0.0f, "b20", nullptr)
		    , mVertexPositionScore(this, 50.0f, 0.0f, 0.0f, "b21", nullptr)
		    , mTraceDrag(this, 0.7f, 0.0f, 0.0f, "b30", nullptr)
		    , mSpringForce(this, 0.5f, 0.0f, 0.0f, "b31", nullptr)
		    , mMaxSortCount(this, 10, 0, 0, "i00", nullptr)
		{
		}

		// _200-_204 = Parameters
		Parm<f32> mDetectionRadius;        // _204, p00 - detection radius?
		Parm<f32> mMaxMoveSpeed;           // _214, s00 - max moving speed?
		Parm<f32> mMinMoveSpeed;           // _224, s01 - min moving speed?
		Parm<f32> mNormalMaxLength;        // _234, s10 - normal max length?
		Parm<f32> mNormalMinLength;        // _244, s11 - normal min length?
		Parm<f32> mMaxLengthAtSticking;    // _254, s20 - max length at sticking?
		Parm<f32> mMinLengthAtSticking;    // _264, s21 - min length at sticking?
		Parm<f32> mDistanceBetweenNuclei;  // _274, s30 - dist between nuclei?
		Parm<f32> mMaxStickPikiNum;        // _284, s40 - max stick piki num?
		Parm<f32> mTraceMidPoint;          // _294, s50 - trace mid point?
		Parm<f32> mMidPointSpring;         // _2A4, s51 - mid point spring?
		Parm<f32> mDamageLengthLarge;      // _2B4, s60 - damage length 1?
		Parm<f32> mDamageLengthMid;        // _2C4, s61 - damage length 2?
		Parm<f32> mDamageRatioLarge;       // _2D4, s62 - damage ratio 1?
		Parm<f32> mDamageRatioMid;         // _2E4, s63 - damage ratio 2?
		Parm<f32> mDamageRatioSmall;       // _2F4, s64 - damage ratio 3?
		Parm<f32> mContractTraceEnd;       // _304, s70 - contract trace end?
		Parm<f32> mContractSpringEnd;      // _314, s71 - contract end spring?
		Parm<f32> mDeadScaleSpeed;         // _324, s80 - dead scale speed?
		Parm<f32> mBodyHeight;             // _334, b00 - body height?
		Parm<f32> mBodyThicknessElongate;  // _344, b01 - body thickness (elongation)?
		Parm<f32> mBodyThicknessContract;  // _354, b02 - body thickness (contraction)?
		Parm<f32> mMaxRadiusCompensation;  // _364, b10 - max radius compensation?
		Parm<f32> mRadiusContractionScore; // _374, b20 - radius contraction score?
		Parm<f32> mVertexPositionScore;    // _384, b21 - vertex position score?
		Parm<f32> mTraceDrag;              // _394, b30 - trace creature?
		Parm<f32> mSpringForce;            // _3A4, b31 - creature spring?
		Parm<int> mMaxSortCount;           // _3B4, i00 - how many times to "sort" collision spheres
	};

	SlimeProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mBossProps.read(input);
		mSlimeProps.read(input);
	}

	// _F8       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	SlimeProperties mSlimeProps; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x20.
 */
struct SlimeBody {
public:
	SlimeBody(Slime*);

	void init(Slime*);
	void refresh(BossShapeObject*, Graphics&);
	void update();

private:
	void traceCreaturePosition();
	void makeCentrePosition();
	void makeInnerPosition();
	void makeMaxRadius();
	void setSpherePosition();
	f32 calcVertexScore(Vector3f*, Vector3f*, f32*);
	void sortPosition(Vector3f*, Vector3f*, Vector3f*);
	void makeSlimeBody();
	void setJointPosition(BossShapeObject*, Graphics&);

	Slime* mSlime;                        // _00
	f32 mMaxRadius;                       // _04
	Vector3f* mVelocities;                // _08
	Vector3f* mPrevVelocities;            // _0C
	Vector3f* mRelativeVelocities;        // _10
	u16* mVertexNormalIndices;            // _14, normal index mapped by vertex index
	int* mNearestVertexToJoint;           // _18
	Vector3f* mNormalisedVertexPositions; // _1C
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
	Vector3f mTargetPosition;  // _2BC
	SearchData mSearchData[3]; // _2C8
};

/**
 * @brief TODO.
 */
struct Slime : public Boss {
	friend struct SlimeAi;
	friend struct SlimeBody;

	// This feels a little extra but then again so does Goolix as a whole.
	friend struct CoreNucleus;
	friend struct CoreNucleusAi;
	friend struct Nucleus;
	friend struct NucleusAi;
	friend struct BossMgr; // To initialize `mNucleus` and `mCore`.

	/**
	 * @brief TODO.
	 *
	 * @note Size: 0x24.
	 */
	struct BoundSphereUpdater : public CollPartUpdater {
		BoundSphereUpdater(Slime* slime) { mSlime = slime; }

		virtual Vector3f getPos() { return mSlime->mPosition; } // _08
		virtual f32 getSize()                                   // _0C
		{
			mSize = 0.0f;
			for (int i = 0; i < bossMgr->mSlimeCreatureCount; i++) {
				if (mSlime->mSlimeCreatures[i]) {
					f32 dist = mSlime->mPosition.distance(mSlime->mSlimeCreatures[i]->mPosition);
					if (dist > mSize) {
						mSize = dist;
					}
				}
			}

			mSize += 75.0f;
			return mSize;
		}

		// _00     = VTBL
		// _00-_1C = CollPartUpdater
		Slime* mSlime; // _1C
		f32 mSize;     // _20
	};
	friend struct BoundSphereUpdater;

	/**
	 * @brief TODO.
	 *
	 * @note Size: 0x24.
	 */
	struct CollideSphereUpdater : public CollPartUpdater {
		CollideSphereUpdater() { }

		virtual Vector3f getPos() { return mCreature->mPosition; } // _08
		virtual f32 getSize()                                      // _0C
		{
			Vector3f adjustVecs[4];

			adjustVecs[0].set(1.0f, 0.0f, 0.0f);
			adjustVecs[1].set(0.0f, 0.0f, 1.0f);
			adjustVecs[2] = -adjustVecs[0];
			adjustVecs[3] = -adjustVecs[1];

			f32 minDist = 12800.0f;
			for (int i = 0; i < 4; i++) {

				// weightPos is kind of the centre of mass?
				Vector3f weightPos = mCreature->mPosition
				                   + static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps.mMaxRadiusCompensation()
				                         * adjustVecs[i]; // max radius compensation

				Vector3f farPos  = weightPos;
				Vector3f nearPos = mCreature->mPosition;

				// iterate like 10 times to jiggle the weightPos closer to the middle of the 4 stick slimes
				for (int j = 0; j < static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps.mMaxSortCount(); j++) { // number of sorts?
					f32 score = 0.0f;

					weightPos.x = (farPos.x + nearPos.x) / 2.0f;
					weightPos.y = (farPos.y + nearPos.y) / 2.0f;
					weightPos.z = (farPos.z + nearPos.z) / 2.0f;

					for (int k = 0; k < 4; k++) {
						// why this isn't a vector distance, i have no clue.
						f32 x = weightPos.x - mSlime->mSlimeCreatures[k]->mPosition.x;
						f32 y = weightPos.y - mSlime->mSlimeCreatures[k]->mPosition.y;
						f32 z = weightPos.z - mSlime->mSlimeCreatures[k]->mPosition.z;
						score += mSlime->mAppearanceScale / std::sqrtf(SQUARE(x) + SQUARE(y) + SQUARE(z));
					}

					// closer to other stick slimes = higher score
					if (score > static_cast<SlimeProp*>(mSlime->mProps)->mSlimeProps.mVertexPositionScore()) { // vertex position score?
						nearPos.set(weightPos);
					} else {
						farPos.set(weightPos);
					}
				}

				// keep track of smallest distance from this piece of slime
				f32 dist = weightPos.distance(mCreature->mPosition);
				if (minDist > dist) {
					minDist = dist;
				}
			}

			return minDist - 15.0f;
		}

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
	friend struct CollideSphereUpdater;

	/**
	 * @brief TODO.
	 *
	 * @note Size: 0x20.
	 */
	struct TubeSphereUpdater : public CollPartUpdater {
		TubeSphereUpdater() { }

		virtual Vector3f getPos() { return mSphere->mCentre; } // _08
		virtual f32 getSize() { return mSphere->mRadius; }     // _0C

		inline void setSphere(CollPart* sphere) { mSphere = sphere; }

		// _00     = VTBL
		// _00-_1C = CollPartUpdater
		CollPart* mSphere; // _1C
	};
	friend struct TubeSphereUpdater;

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

private:
	// _00      = VTBL
	// _00-_3B8 = Boss
	BoundSphereUpdater* mCentreUpdater;           // _3B8
	CollideSphereUpdater* mCollideSphereUpdaters; // _3BC
	TubeSphereUpdater* mTubeSphereUpdaters;       // _3C0
	bool mIsMoveLeader;                           // _3C4, if true, move leader; if false, move follower
	bool mDoCrashContract;                        // _3C5
	int mLeaderCreatureIndex;                     // _3C8, which slime creature is the leader nucleus (outer)?
	int mFollowerCreatureIndex;                   // _3CC, which slime creature is the follower nucleus (outer)?
	f32 mLeaderSpeed;                             // _3D0
	f32 mAppearanceScale;                         // _3D4
	f32 mBodyThickness;                           // _3D8
	Vector3f mNucleusPosition;                    // _3DC
	Vector3f mCorePosition;                       // _3E8
	SlimeCreature** mSlimeCreatures;              // _3F4
	Nucleus* mNucleus;                            // _3F8
	CoreNucleus* mCore;                           // _3FC
	SlimeAi* mSlimeAi;                            // _400
	SlimeBody* mSlimeBody;                        // _404
};

/**
 * @brief TODO.
 *
 * @note Size: 0x24.
 */
struct SlimeAi {
public:
	SlimeAi(Slime*);

	void init(Slime*);
	void update();
	void addDamagePoint(f32);

private:
	void setEveryFrame();
	void afterProcessing();
	void calcBubblePiki();
	void calcStickersRatio();
	void setLeaderIndex();
	void makeInterrelation();
	void makeBodyThickness();
	void playExpandingSound();
	void calcCollisionCheck();
	void setLeaderNearerTarget();
	void moveFlagCheck();
	void makeTargetPosition();
	void makeFollowerVelocity();
	void makeLeaderVelocity();
	void setMidPointVelocity();
	void walkAllState();
	void calcContractDamage();
	void contractCoreFlickPiki();
	void contractSubFlickPiki();
	void inCaseOfContract();
	void setDieGoal();
	void setContractGoal();
	void setExpansionGoal();
	void setAppearGoal();
	void bothEndsToGoal();
	void bothEndsToAppearGoal();
	void makeTargetRandom();
	void setVelocity(f32);
	bool motionFinishTransit();
	bool dieTransit();
	bool outSideChaseRangeTransit();
	bool inSideWaitRangeTransit();
	bool chaseNaviTransit();
	bool chasePikiTransit();
	bool targetLostTransit();
	bool collisionContractTransit();
	bool dissolutionContractTransit();
	bool finishContractTransit();
	bool finishExpansionTransit();
	bool appearTransit();
	bool disAppearTransit();
	void initDie(int);
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
	void appearState();
	void disAppearState();

public:
	bool mIsContractFinished;       // _00
	bool mCanPlayExpandSound;       // _01
	int mPrevNucleusStickPikiCount; // _04
	int mContractHitType;           // _08
	int mBubbleCheckIndex;          // _0C
	f32 mContractDamage;            // _10
	f32 mStickersRatio;             // _14
	f32 mMaxLength;                 // _18
	f32 mMinLength;                 // _1C
	Slime* mSlime;                  // _20
};

#endif
