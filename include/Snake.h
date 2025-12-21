#ifndef _SNAKE_H
#define _SNAKE_H

#include "Boss.h"
#include "Collision.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

struct Snake;
struct SnakeAi;
struct SnakeBody;
struct SnakeGenBodyOnGroundCallBack;
struct SnakeGenBodyRotateCallBack;

#define SNAKE_PROP          (static_cast<SnakeProp*>(mProps)->mSnakeProps)
#define C_SNAKE_PROP(snake) (static_cast<SnakeProp*>((snake)->mProps)->mSnakeProps)

/**
 * @brief TODO.
 */
enum SnakeAIStateID {
	SNAKEAI_Die       = 0,
	SNAKEAI_Struggle  = 1,
	SNAKEAI_ChaseNavi = 2,
	SNAKEAI_ChasePiki = 3,
	SNAKEAI_Attack    = 4,
	SNAKEAI_Eat       = 5,
	SNAKEAI_Wait      = 6,
	SNAKEAI_GoInto    = 7,
	SNAKEAI_Under     = 8,
	SNAKEAI_Appear    = 9,
};

/**
 * @brief TODO.
 */
enum SnakeAIAttackID {
	SNAKEATK_Near  = 0,
	SNAKEATK_Mid   = 1,
	SNAKEATK_Far   = 2,
	SNAKEATK_Right = 3,
	SNAKEATK_Left  = 4,
	SNAKEATK_COUNT, // 5
};

/**
 * @brief TODO.
 *
 * @note Size: 0x504
 */
struct SnakeProp : public BossProp, public CoreNode {
public:
	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to SnakeProp for ease of use.
	 */
	struct SnakeProperties : public Parameters {
		inline SnakeProperties()
		    : mType1DetectionRadius(this, 150.0f, 0.0f, 500.0f, "p00", "")
		    , mType1AppearDist(this, 100.0f, 0.0f, 300.0f, "p01", "")
		    , mType2AppearFrontDist(this, 200.0f, 0.0f, 500.0f, "u00", "2:Front Length")
		    , mType2AppearSideDist(this, 100.0f, 0.0f, 500.0f, "u01", "2:Side Length")
		    , mType2AppearVertDist(this, 50.0f, 0.0f, 300.0f, "u02", "2:Vertical Length")
		    , mAttackDamageNavi(this, 25.0f, 0.0f, 100.0f, "p10", "Attack Damage Navi")
		    , mNearAttackDist(this, 5.0f, 0.0f, 500.0f, "p20", "Near Attack Dist")
		    , mNearAttackLimit(this, 80.0f, 0.0f, 500.0f, "p21", "Near Attack Limit")
		    , mNearAttackMinus(this, -15.0f, -500.0f, 500.0f, "p22", "Near Attack Minus")
		    , mNearAttackPlus(this, 15.0f, -500.0f, 500.0f, "p23", "Near Attack Plus")
		    , mNearAttackHeight(this, 15.0f, 0.0f, 100.0f, "p24", "Near Attack Height")
		    , mMidAttackDist(this, 80.0f, 0.0f, 500.0f, "p30", "Mid Attack Dist")
		    , mMidAttackLimit(this, 150.0f, 0.0f, 500.0f, "p31", "Mid Attack Limit")
		    , mMidAttackMinus(this, -20.0f, -500.0f, 500.0f, "p32", "Mid Attack Minus")
		    , mMidAttackPlus(this, 20.0f, -500.0f, 500.0f, "p33", "Mid Attack Plus")
		    , mMidAttackHeight(this, 15.0f, 0.0f, 100.0f, "p34", "Mid Attack Height")
		    , mFarAttackDist(this, 150.0f, 0.0f, 500.0f, "p40", "Far Attack Dist")
		    , mFarAttackLimit(this, 220.0f, 0.0f, 500.0f, "p41", "Far Attack Limit")
		    , mFarAttackMinus(this, -25.0f, -500.0f, 500.0f, "p42", "Far Attack Minus")
		    , mFarAttackPlus(this, 25.0f, -500.0f, 500.0f, "p43", "Far Attack Plus")
		    , mFarAttackHeight(this, 15.0f, 0.0f, 100.0f, "p44", "Far Attack Height")
		    , mRightAttackDist(this, 70.0f, 0.0f, 500.0f, "p50", "Right Attack Dist")
		    , mRightAttackLimit(this, 120.0f, 0.0f, 500.0f, "p51", "Right Attack Limit")
		    , mRightAttackMinus(this, 30.0f, -500.0f, 500.0f, "p52", "Right Attack Minus")
		    , mRightAttackPlus(this, 100.0f, -500.0f, 500.0f, "p53", "Right Attack Plus")
		    , mRightAttackHeight(this, 15.0f, 0.0f, 100.0f, "p54", "Right Attack Height")
		    , mLeftAttackDist(this, 70.0f, 0.0f, 500.0f, "p60", "Left Attack Dist")
		    , mLeftAttackLimit(this, 120.0f, 0.0f, 500.0f, "p61", "Left Attack Limit")
		    , mLeftAttackMinus(this, -100.0f, -500.0f, 500.0f, "p62", "Left Attack Minus")
		    , mLeftAttackPlus(this, -30.0f, -500.0f, 500.0f, "p63", "Left Attack Plus")
		    , mLeftAttackHeight(this, 15.0f, 0.0f, 100.0f, "p64", "Left Attack Height")
		    , mNormBodyTurnSpeed(this, 1.5f, 0.0f, 5.0f, "t00", "Norm Body Turn")
		    , mChaseBodyTurnSpeed(this, 4.0f, 0.0f, 5.0f, "t01", "Chase Body Turn")
		    , mChaseBlendingRate(this, 1.0f, 0.0f, 30.0f, "t10", "Chase Blend Ratio")
		    , mWaitBeforeDiveTime(this, 2.5f, 0.0f, 10.0f, "q00", "Dive Time")
		    , mWaitUndergroundTime(this, 0.0f, 0.0f, 10.0f, "q02", "Under Time")
		    , mDeadHeadScaleSpeed(this, 10.0f, 0.0f, 100.0f, "s00", "Head Scale Speed")
		    , mDeadHeadScaleTimer(this, 1.0f, 0.0f, 10.0f, "s01", "Head Scale Timer")
		    , mDeadBodyScaleSpeed(this, 5.0f, 0.0f, 100.0f, "s02", "Body Scale Speed")
		    , mDeadBodyScaleTimer(this, 0.75f, 0.0f, 10.0f, "s03", "Body Scale Timer")
		    , mDeadBodyScaleSegmentRatio(this, 0.1f, 0.0f, 1.0f, "s04", "Body Timer Up Ratio")
		    , mFastAppearChance(this, 0.7f, 0.0f, 1.0f, "s10", "Normal Appear Type")
		    , mStrugglePikiMin(this, 5, 0, 100, "i10", "Struggle Piki(Min)")
		    , mStrugglePikiMax(this, 20, 0, 100, "i11", "Struggle Piki(Max)")
		    , mStruggleLoopMid(this, 1, 0, 10, "i12", "Struggle Loop(Mid)")
		    , mStruggleLoopMax(this, 3, 0, 10, "i13", "Struggle Loop(Max)")
		    , mHeadPelletIndex(this, 1, -1, 3, "i30", "Head Pellet Index")
		    , mBodyPelletIndex(this, 0, -1, 3, "i31", "Body Pellet Index")
		{
		}

		// _200-_204 = Parameters
		Parm<f32> mType1DetectionRadius;      // _204
		Parm<f32> mType1AppearDist;           // _214
		Parm<f32> mType2AppearFrontDist;      // _224
		Parm<f32> mType2AppearSideDist;       // _234
		Parm<f32> mType2AppearVertDist;       // _244
		Parm<f32> mAttackDamageNavi;          // _254
		Parm<f32> mNearAttackDist;            // _264
		Parm<f32> mNearAttackLimit;           // _274
		Parm<f32> mNearAttackMinus;           // _284
		Parm<f32> mNearAttackPlus;            // _294
		Parm<f32> mNearAttackHeight;          // _2A4
		Parm<f32> mMidAttackDist;             // _2B4
		Parm<f32> mMidAttackLimit;            // _2C4
		Parm<f32> mMidAttackMinus;            // _2D4
		Parm<f32> mMidAttackPlus;             // _2E4
		Parm<f32> mMidAttackHeight;           // _2F4
		Parm<f32> mFarAttackDist;             // _304
		Parm<f32> mFarAttackLimit;            // _314
		Parm<f32> mFarAttackMinus;            // _324
		Parm<f32> mFarAttackPlus;             // _334
		Parm<f32> mFarAttackHeight;           // _344
		Parm<f32> mRightAttackDist;           // _354
		Parm<f32> mRightAttackLimit;          // _364
		Parm<f32> mRightAttackMinus;          // _374
		Parm<f32> mRightAttackPlus;           // _384
		Parm<f32> mRightAttackHeight;         // _394
		Parm<f32> mLeftAttackDist;            // _3A4
		Parm<f32> mLeftAttackLimit;           // _3B4
		Parm<f32> mLeftAttackMinus;           // _3C4
		Parm<f32> mLeftAttackPlus;            // _3D4
		Parm<f32> mLeftAttackHeight;          // _3E4
		Parm<f32> mNormBodyTurnSpeed;         // _3F4
		Parm<f32> mChaseBodyTurnSpeed;        // _404
		Parm<f32> mChaseBlendingRate;         // _414
		Parm<f32> mWaitBeforeDiveTime;        // _424
		Parm<f32> mWaitUndergroundTime;       // _434
		Parm<f32> mDeadHeadScaleSpeed;        // _444
		Parm<f32> mDeadHeadScaleTimer;        // _454
		Parm<f32> mDeadBodyScaleSpeed;        // _464
		Parm<f32> mDeadBodyScaleTimer;        // _474
		Parm<f32> mDeadBodyScaleSegmentRatio; // _484
		Parm<f32> mFastAppearChance;          // _494
		Parm<int> mStrugglePikiMin;           // _4A4
		Parm<int> mStrugglePikiMax;           // _4B4
		Parm<int> mStruggleLoopMid;           // _4C4
		Parm<int> mStruggleLoopMax;           // _4D4
		Parm<int> mHeadPelletIndex;           // _4E4
		Parm<int> mBodyPelletIndex;           // _4F4
	};

	SnakeProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mBossProps.read(input);
		mSnakeProps.read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	SnakeProperties mSnakeProps; // _200
};

// https://intns.github.io/media/snake_joints.png
BEGIN_ENUM_TYPE(SnakeJointType)
enum {
	Root         = 0, // bodyjnt1
	Segment1     = 1, // bodyjnt2
	Segment2     = 2, // bodyjnt3
	Segment4     = 3, // bodyjnt4
	Segment5     = 4, // bodyjnt5, middle
	Segment6     = 5, // bodyjnt6
	Segment7     = 6, // bodyjnt7
	Neck         = 7, // bodyjnt8
	SegmentCount = 8,

	// 8 is the eye root
	RightEye = 9,  // bb_rme
	LeftEye  = 10, // bb_lme

	JawHinge   = 11, // kutijnt1
	LeftCheek  = 12, // kamujnt3
	RightCheek = 13, // kamujnt2
	Beak       = 14, // kamujnt1
} END_ENUM_TYPE;

/**
 * @brief Snake Body controller
 *
 * @note Size: 0x890.
 */
struct SnakeBody {
public:
	SnakeBody(Snake*);

	void init(immut Vector3f&, Snake*);
	void killCallBackEffect(bool);
	void refresh(BossShapeObject*, Graphics&);
	void update();
	void setBodyOnGroundEffect();
	void initBlending(f32);

private:
	void updateBlendingRatio();
	void setInitializePosition();
	void copyAnimPosition();
	void makeHeadDirection();
	void makeTurnVelocity();
	void makeNewPosition();
	void makeResultPosition();
	void makeVectorMatrix();
	void createDeadPellet(immut Vector3f&, int);
	void createDeadHeadEffect();
	void createDeadBodyEffect();
	void makeDeadPattern01();
	void makeDeadPattern02();
	void makeDeadScaleParms();
	void makeAnimation(BossShapeObject*, Graphics&);
	void makeBodySize();
	void makeHeadPosition();
	void makeBodyMatrix();
	void makeAnimMatrix();
	void caseOfMatrix(Matrix4f*);
	void checkBlendingParm(Matrix4f*);
	void makeBlending(Matrix4f*);
	void setDeadPattern01(Matrix4f*);
	void setDeadPattern02(Matrix4f*);
	void setDeadScale(Matrix4f*);
	void returnJoint(BossShapeObject*, Graphics&, immut Matrix4f*);

public:
	Snake* mSnake;                                               // _00
	bool mIsDying;                                               // _04
	bool mUseBlend;                                              // _05
	int mDeadEffectSegmentIndex;                                 // _08
	f32 mBlendingRatio;                                          // _0C
	f32 mBlendingRate;                                           // _10
	f32 mSegmentLengthList[7];                                   // _14
	f32 mSegmentScaleList[SnakeJointType::SegmentCount];         // _30
	Vector3f mNeckPosition;                                      // _50
	Vector3f mSegmentPositionList[SnakeJointType::SegmentCount]; // _5C
	Vector3f mSegmentTurnVelocityList[6];                        // _BC
	Vector3f mAnimPosList[SnakeJointType::SegmentCount][4];      // _104
	Matrix4f mSegmentMatrices[SnakeJointType::SegmentCount];     // _284
	Matrix4f mPrevAnimMatrices[SnakeJointType::SegmentCount];    // _484
	Matrix4f mActiveAnimMatrices[SnakeJointType::SegmentCount];  // _684
	SnakeGenBodyOnGroundCallBack* mOnGroundCallBack;             // _884
	SnakeGenBodyRotateCallBack* mRotateCallBack;                 // _888
	zen::particleGenerator** mDeadPtclGens;                      // _88C
};

/**
 * @brief TODO.
 *
 * @note Size: 0x3DC.
 */
struct Snake : public Boss {
	friend struct SnakeAi;
	friend struct SnakeBody;

	friend struct SnakeGenBodyOnGroundCallBack;
	friend struct SnakeGenBodyRotateCallBack;

public:
	/**
	 * @brief TODO.
	 */
	struct BoundSphereUpdater : public CollPartUpdater {
		inline BoundSphereUpdater(Snake* snake) { mSnake = snake; }

		virtual Vector3f getPos() // _08
		{
			mCentrePosition.x = (mSnake->mSnakeBody->mNeckPosition.x + mSnake->mSRT.t.x) / 2.0f;
			mCentrePosition.y = (mSnake->mSnakeBody->mNeckPosition.y + mSnake->mSRT.t.y) / 2.0f;
			mCentrePosition.z = (mSnake->mSnakeBody->mNeckPosition.z + mSnake->mSRT.t.z) / 2.0f;

			return mCentrePosition;
		}
		virtual f32 getSize() // _0C
		{
			mSize = mSnake->mSnakeBody->mNeckPosition.distance(mCentrePosition);
			mSize += 55.0f;
			return mSize;
		}

		// _00     = VTBL
		// _00-_1C = CollPartUpdater
		Snake* mSnake;            // _1C
		f32 mSize;                // _20
		Vector3f mCentrePosition; // _24
	};
	friend struct BoundSphereUpdater;

	Snake(CreatureProp*);

	virtual void init(immut Vector3f&); // _28
	virtual f32 getiMass();             // _38
	virtual f32 getCentreSize();        // _5C
	virtual void update();              // _E0
	virtual void refresh(Graphics&);    // _EC
	virtual void refresh2d(Graphics&);  // _F0
	virtual void doAI();                // _104
	virtual void doAnimation();         // _108
	virtual void doKill();              // _10C
	virtual void exitCourse();          // _110
	virtual void drawShape(Graphics&);  // _120

	void setBossType(bool);

private:
	// _00      = VTBL
	// _00-_3B8 = Boss
	BoundSphereUpdater* mBoundsUpdater; // _3B8
	bool mBossType;                     // _3BC
	f32 _3C0;                           // _3C0
	f32 _3C4;                           // _3C4
	SnakeAi* mSnakeAi;                  // _3C8
	SnakeBody* mSnakeBody;              // _3CC
	Vector3f mSpawnPosition;            // _3D0
};

/**
 * @brief TODO.
 *
 * @note Size: 0x50.
 */
struct SnakeAi : public PaniAnimKeyListener {
public:
	SnakeAi(Snake*);

	void initAI(Snake*);
	void update();

private:
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&); // _08

	void keyAction0();
	void keyAction1();
	void keyAction2();
	void keyAction3();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void setEveryFrame();
	void setInitPosition();
	void setUnderPosition();
	void setAppearPosition01();
	void setAppearPosition02();
	void traceTargetPosition();
	void setAttackPosition();
	void checkAttackTarget();
	void naviNudge();
	void setMouthCollPart(int);
	int getMouthCollPart(int);
	void pikiStickMouth();
	void eatStickToMouthPiki();
	void nearNaviInAttackArea(Creature**, f32*, int);
	void nearPikiInAttackArea(Creature**, f32*, int);
	bool naviInAttackArea(int);
	bool pikiInAttackArea(int);
	bool appearType01();
	bool appearType02();
	void resultFlagOn();
	void resultFlagSeen();
	bool dieTransit();
	bool struggleTransit();
	bool chaseNaviTransit();
	bool chasePikiTransit();
	bool targetLostTransit();
	bool attackTransit(int);
	bool collPartMaxTransit();
	bool eatPikiTransit();
	bool intoGroundTransit();
	bool diveTimerTransit();
	bool underTimerTransit();
	bool appearTransit();
	void initDie(int);
	void initStruggle(int);
	void initChase(int);
	void initAttack(int, f32);
	void initEat(int);
	void initWait(int);
	void initGointo(int);
	void initUnder(int);
	void initAppear(int);
	void dieState();
	void struggleState();
	void chaseState();
	void attackState();
	void eatState();
	void waitState();
	void gointoState();
	void underState();

public:
	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	bool mIsFacingTarget;       // _04
	bool mIsAttackAllowed;      // _05
	bool mFastAppear;           // _06
	int mMouthSlotFlag;         // _08, keeps track of which slots are occupied
	int mOccupiedSlotCount;     // _0C
	int mMaxSlotCount;          // _10
	int mAttackId;              // _14
	f32* mAttackDists;          // _18, array of 5 floats
	f32* mAttackLimits;         // _1C, array of 5 floats
	f32* mAttackMinus;          // _20, array of 5 floats
	f32* mAttackPlus;           // _24, array of 5 floats
	f32* mAttackHeights;        // _28, array of 5 floats
	u32* _2C;                   // _2C, array of 5 somethings
	Vector3f* mAttackPositions; // _30, array of 5 vectors
	Vector3f mSnakeFrontDir;    // _34
	Vector3f mSnakeSideDir;     // _40
	Snake* mSnake;              // _4C
};

/**
 * @brief TODO
 */
struct SnakeGenBodyOnGroundCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		if (!mSnake->getAlive() || mSnake->getNextState() == 8) {
			ptclGen->finish();
		}

		return true;
	}

	void set(Snake* snake) { mSnake = snake; }

private:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	Snake* mSnake; // _04
};

/**
 * @brief TODO
 */
struct SnakeGenBodyRotateCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		if (mSnake->mSnakeAi->mIsFacingTarget) {
			ptclGen->startGen();
		} else {
			ptclGen->stopGen();
		}

		if (!mSnake->getAlive() || mSnake->getNextState() == 8) {
			ptclGen->finish();
		}

		return true;
	}

	void set(Snake* snake) { mSnake = snake; }

private:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	Snake* mSnake; // _04
};

#endif
