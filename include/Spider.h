#ifndef _SPIDER_H
#define _SPIDER_H

#include "Boss.h"
#include "ShadowCaster.h"
#include "types.h"
#include "zen/CallBack.h"
#include "zen/particle.h"

struct SpiderAi;
struct SpiderLeg;
struct SpiderDrawer;
struct SpiderGenHalfDeadCallBackJoint;
struct SpiderGenPerishCallBack;
struct SpiderGenRippleCallBack;

#define SPIDER_PROP           (static_cast<SpiderProp*>(mProps)->mSpiderProps)
#define C_SPIDER_PROP(spider) (static_cast<SpiderProp*>((spider)->mProps)->mSpiderProps)

/**
 * @brief TODO.
 */
enum SpiderAIStateID {
	SPIDERAI_Die        = 0,
	SPIDERAI_WalkRandom = 1,
	SPIDERAI_ChaseNavi  = 2,
	SPIDERAI_ChasePiki  = 3,
	SPIDERAI_WalkGoHome = 4,
	SPIDERAI_ShakeOff   = 5,
	SPIDERAI_Wait       = 6,
	SPIDERAI_Start      = 7,
	SPIDERAI_Appear     = 8,
};

/**
 * @brief TODO.
 *
 * @note Size: 0x554.
 */
struct SpiderProp : public BossProp, public CoreNode {
public:
	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to SpiderProp for ease of use.
	 */
	struct Parms : public Parameters {
		inline Parms()
		    : _204(this, 1.5f, 0.1f, 10.0f, "p10", "Motion Speed (UP)")
		    , _214(this, 0.113f, 0.0f, 0.5f, "p11", "Speed Down")
		    , _224(this, 0.37f, 0.1f, 1.0f, "p12", "最低スピード")
		    , _234(this, 7.0f, 0.1f, 10.0f, "p13", "Motion Speed (DOWN)")
		    , _244(this, 0.1f, 0.0f, 10.0f, "p14", "Speed Up")
		    , _254(this, 10.0f, 0.1f, 100.0f, "p15", "最高スピード")
		    , _264(this, 120.0f, 0.0f, 150.0f, "p20", "足を上げる高さ")
		    , _274(this, 15.0f, 0.0f, 100.0f, "p21", "足の沈み")
		    , _284(this, 45.0f, 0.0f, 100.0f, "p22", "最低高度")
		    , _294(this, 15.0f, 0.0f, 10.0f, "p23", "体の沈み")
		    , _2A4(this, 50.0f, 0.0f, 100.0f, "p24", "体の沈み最大値")
		    , _2B4(this, 75.0f, 0.0f, 100.0f, "p30", "足を伸ばす距離(Min)")
		    , _2C4(this, 100.0f, 0.0f, 200.0f, "p31", "足を伸ばす距離(Max)")
		    , _2D4(this, 100.0f, 0.0f, 150.0f, "p32", "Landing Radius(Min)")
		    , _2E4(this, 125.0f, 0.0f, 200.0f, "p33", "Landing Radius(Max)")
		    , _2F4(this, 0.7f, 0.0f, 1.0f, "p34", "体の回転角度(Min)")
		    , _304(this, 1.2f, 0.0f, 2.0f, "p35", "体の回転角度(Max)")
		    , _314(this, 1.8f, 0.5f, 2.0f, "p40", "足をあげる時差")
		    , _324(this, 25.0f, 0.0f, 100.0f, "p50", "Step Area")
		    , _334(this, 20.0f, 0.0f, 100.0f, "p51", "Step Navi")
		    , _344(this, 200.0f, 0.0f, 200.0f, "p52", "Step Piki")
		    , _354(this, 0.3f, 0.0f, 1.0f, "p53", "Step Shake Off(%)")
		    , _364(this, 100.0f, 0.0f, 500.0f, "p54", "Shake Off Power")
		    , _374(this, 0.0f, 0.0f, 100.0f, "p55", "Shake Off Damage")
		    , _384(this, 0.15f, 0.0f, 1.0f, "p56", "Vibration")
		    , _394(this, 2.0f, 0.0f, 10.0f, "p57", "MAX Vibration")
		    , _3A4(this, 0.15f, 0.0f, 1.0f, "p60", "体のバネ")
		    , _3B4(this, 0.95f, 0.0f, 1.0f, "p61", "バネの引継ぎ値")
		    , _3C4(this, 30.0f, 0.0f, 50.0f, "p62", "体の揺れ最大値")
		    , _3D4(this, 0.01f, 0.0f, 1.0f, "p63", "体重移動(On Ground)")
		    , _3E4(this, 30.0f, 0.0f, 100.0f, "p70", "1:膝揺らし速度")
		    , _3F4(this, 2.0f, 0.0f, 10.0f, "p71", "1:膝揺らし時間")
		    , _404(this, 1.0f, 0.0f, 5.0f, "p72", "1:膝揺らし量")
		    , _414(this, 0.5f, 0.0f, 2.0f, "p73", "2:腰ひねりのバネ")
		    , _424(this, 0.9f, 0.0f, 1.0f, "p74", "2:バネの引継ぎ値")
		    , _434(this, 1.6f, 0.0f, 3.0f, "p75", "2:腰の回転量")
		    , mSpawnTriggerDist(this, 180.0f, 0.0f, 500.0f, "c00", "出現エリア")
		    , mDropTimer(this, 0.05f, 0.0f, 10.0f, "c01", "出現時間")
		    , mDeadBombEffectDelay(this, 5.9f, 0.0f, 10.0f, "t00", "Dead Bomb Effect")
		    , mDeadScaleStartDelay(this, 6.0f, 0.0f, 10.0f, "s00", "Dead Scale Start")
		    , mDeadScaleStageDelay(this, 0.1f, 0.1f, 10.0f, "s01", "Dead Scale Timing")
		    , mDeadMotionDelay(this, 0.1f, 0.1f, 10.0f, "s02", "Dead Scale Time")
		    , _4A4(this, 100.0f, 0.0f, 500.0f, "s10", "Stick Heiht Modify") // dev spelling
		    , _4B4(this, 100.0f, 0.0f, 500.0f, "s11", "Map Heiht Modify")   // dev spelling
		    , _4C4(this, 150.0f, 0.0f, 300.0f, "s30", "Target Centre")
		    , _4D4(this, 0.5f, 0.0f, 1.0f, "s31", "Cent Leg Dist(Min)")
		    , _4E4(this, 0.75f, 0.0f, 1.0f, "s32", "Cent Leg Dist(Max)")
		    , mMinWaitCycles(this, 1, 1, 10, "i00", "ウェイト回数(Min)")
		    , mMaxWaitCycles(this, 2, 1, 10, "i01", "ウェイト回数(Max)")
		    , mMinWalkCycles(this, 2, 1, 10, "i02", "ウォーク回数(Min)")
		    , mMaxWalkCycles(this, 4, 1, 10, "i03", "ウォーク回数(Max)")
		    , mDoDropFromSky(this, 1, 0, 1, "i10", "設置場所(0:地,1:空)")
		    , mDoFinalKillEffects(this, 1, 0, 1, "i20", "Erase Shape")
		{
		}

		// _200-_204 = Parameters
		Parm<f32> _204;                 // _204, p10 - normal foot raising speed?
		Parm<f32> _214;                 // _214, p11 - related to above?
		Parm<f32> _224;                 // _224, p12 - lowest speed?
		Parm<f32> _234;                 // _234, p13 - normal foot lowering speed?
		Parm<f32> _244;                 // _244, p14 - related to above?
		Parm<f32> _254;                 // _254, p15 - maximum speed?
		Parm<f32> _264;                 // _264, p20 - normal foot raising height?
		Parm<f32> _274;                 // _274, p21 - foot sink?
		Parm<f32> _284;                 // _284, p22 - minimum altitude?
		Parm<f32> _294;                 // _294, p23 - head dip factor (per pikmin)?
		Parm<f32> _2A4;                 // _2A4, p24 - head dip limit?
		Parm<f32> _2B4;                 // _2B4, p30 - stepping dist (min)?
		Parm<f32> _2C4;                 // _2C4, p31 - stepping dist (max)?
		Parm<f32> _2D4;                 // _2D4, p32 - feet spread radius (min)?
		Parm<f32> _2E4;                 // _2E4, p33 - feet spread radius (max)?
		Parm<f32> _2F4;                 // _2F4, p34 - body rotation angle (min)?
		Parm<f32> _304;                 // _304, p35 - body rotation angle (max)?
		Parm<f32> _314;                 // _314, p40 - min delay between stomps?
		Parm<f32> _324;                 // _324, p50 - hitbox size of stomping feet?
		Parm<f32> _334;                 // _334, p51 - damage to navi from stomp?
		Parm<f32> _344;                 // _344, p52 - damage to piki from stomp?
		Parm<f32> _354;                 // _354, p53 - step shake chance?
		Parm<f32> _364;                 // _364, p54 - step shake knockback?
		Parm<f32> _374;                 // _374, p55 - step shake damage?
		Parm<f32> _384;                 // _384, p56 - vibration?
		Parm<f32> _394;                 // _394, p57 - max vibration?
		Parm<f32> _3A4;                 // _3A4, p60 - body spring?
		Parm<f32> _3B4;                 // _3B4, p61 - spoke takeover value?
		Parm<f32> _3C4;                 // _3C4, p62 - max body sway?
		Parm<f32> _3D4;                 // _3D4, p63 - weight shift (on ground)?
		Parm<f32> _3E4;                 // _3E4, p70 - 1:knee shaking speed?
		Parm<f32> _3F4;                 // _3F4, p71 - 1:knee shaking time?
		Parm<f32> _404;                 // _404, p72 - 1:knee shaking amount?
		Parm<f32> _414;                 // _414, p73 - 2:spring of waist twist
		Parm<f32> _424;                 // _424, p74 - 2:transfer value of spring
		Parm<f32> _434;                 // _434, p75 - 2:waist rotation amount?
		Parm<f32> mSpawnTriggerDist;    // _444, c00, radius to trigger boss to fall
		Parm<f32> mDropTimer;           // _454, c01, time taken to fall from sky
		Parm<f32> mDeadBombEffectDelay; // _464, t00 - dead bomb effect delay
		Parm<f32> mDeadScaleStartDelay; // _474, s00 - base start delay
		Parm<f32> mDeadScaleStageDelay; // _484, s01 - creates "stages" of start, start + stage, start + 2*stage, etc.
		Parm<f32> mDeadMotionDelay;     // _494, s02 - extra delay time after above to do death anim/code kill
		Parm<f32> _4A4;                 // _4A4, s10 - stick height modify?
		Parm<f32> _4B4;                 // _4B4, s11 - map height modify?
		Parm<f32> _4C4;                 // _4C4, s30 - target centre?
		Parm<f32> _4D4;                 // _4D4, s31 - cent leg dist (min)?
		Parm<f32> _4E4;                 // _4E4, s32 - cent leg dist (max)?
		Parm<int> mMinWaitCycles;       // _4F4, i00 - num wait cycles (min)?
		Parm<int> mMaxWaitCycles;       // _504, i01 - num wait cycles (max)?
		Parm<int> mMinWalkCycles;       // _514, i02 - num walks (min)?
		Parm<int> mMaxWalkCycles;       // _524, i03 - num walks (max)?
		Parm<BOOL> mDoDropFromSky;      // _534, i10 - installation location (0:place 1:sky)?
		Parm<BOOL> mDoFinalKillEffects; // _544, i20 - if this is false, beady just. never fully dies.
	};

	SpiderProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mBossProps.read(input);
		mSpiderProps.read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	Parms mSpiderProps; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x764
 */
struct Spider : public Boss {
	friend struct SpiderAi;
	friend struct SpiderLeg;

	friend struct SpiderGenHalfDeadCallBackJoint;
	friend struct SpiderGenPerishCallBack;
	friend struct SpiderGenRippleCallBack;

public:
	Spider(CreatureProp*);

	virtual void init(immut Vector3f&);             // _28
	virtual f32 getiMass();                         // _38
	virtual void update();                          // _E0
	virtual void refresh(Graphics&);                // _EC
	virtual void doAI();                            // _104
	virtual void doAnimation();                     // _108
	virtual void doKill();                          // _10C
	virtual void exitCourse();                      // _110
	virtual bool isBossBgm() { return mIsBossBgm; } // _114
	virtual void drawShape(Graphics&);              // _120

	void draw(Graphics&);

private:
	// _00      = VTBL
	// _00-_3B8 = Boss
	bool mIsBossBgm;            // _3B8
	bool mCanCreatePerishFx;    // _3B9
	bool mIsHalfDead;           // _3BA
	bool mCanCreateDeadBombFx;  // _3BB
	int mActiveWalkCycleCount;  // _3BC
	SpiderAi* mSpiderAi;        // _3C0
	SpiderLeg* mSpiderLeg;      // _3C4
	bool mIsAppear;             // _3C8
	bool mHasShadow;            // _3C9
	ShadowCaster mShadowCaster; // _3CC, cast mDrawer to SpiderDrawer*
};

/**
 * @brief Spider leg motion types
 */
BEGIN_ENUM_TYPE(SpiderLegMotionType)
enum {
	Walk      = 0, // Normal walking motion
	ShakeOff  = 1, // Shaking off stuck pikmin (moves knees)
	BodyShake = 2, // Full body shake motion
} END_ENUM_TYPE;

/**
 * @brief TODO
 *
 * @note Size: 0x68C.
 */
struct SpiderLeg {
public:
	SpiderLeg(Spider*);

	void init(Spider*);
	void killCallBackEffect(bool);
	void update();
	void refresh(BossShapeObject*, Graphics&);

	void createHalfDeadEffect();
	void createHalfDeadFallEffect(int);
	void createDeadBombEffect();
	void createSmallSparkEffect(int);
	void createPerishEffect();
	void createRippleEffect(int);
	void setLegScaleParam(int);
	void initParm(int);

private:
	void setHalfDeadEffect(u32, int, int);
	void setHalfDeadFallEffect(u32);
	void setDeadBombEffect(u32);
	void setSmallSparkEffect(u32, int*);
	void setPerishEffect(u32, int);
	void setLegParameter();
	void setWalkNewParameter();
	void setShakeOffNewParameter();
	void setBodyShakeNewParameter();
	void setNextDirAndCent();
	void setWalkNewPosition();
	void checkGroundTimer();
	void checkMotionRatio();
	void makeNewPosition();
	void calcSpiderDirection();
	void calcShakeOffDirection();
	void calcStickersPiki();
	void calcShakeOff();
	void setIdealCentre(Vector3f&);
	void setRealCentre(immut Vector3f&);
	void setCentrePosition();
	void updateAnimation(const BossShapeObject*, Graphics&, Matrix4f&);
	void setJointMatrix(const BossShapeObject*, immut Matrix4f&);
	void setLength();
	void getHeight();
	void getLegController();
	void setQuatParameter();
	void stepDamageNavi(int);
	void stepDamagePiki(int);
	void stepShakeOffPiki(int);
	void emitOnGroundEffect(int);
	void onGroundFunction();
	void emitOffGroundEffect();
	void setKneeDirection();
	void getJointMatrix(immut Vector3f&, immut Vector3f&, immut Vector3f&, Matrix4f&);
	void calcQuatToMatrix(int);
	void create3Joint(BossShapeObject*, Graphics&);
	void createMatrixScale(BossShapeObject*, Graphics&);
	void setGroundFlag();
	void checkMotionFinished();

public:
	Spider* mSpider;                                         // _00
	bool mSoundQueued;                                       // _04
	bool mInitialised;                                       // _05
	bool mBodyShakeStarted;                                  // _06
	bool mMotionFinishFlag;                                  // _07
	bool mIsMoving;                                          // _08
	bool mLegMoving[4];                                      // _09
	bool mIsOnGround[4];                                     // _0D
	bool mPrevOnGround[4];                                   // _11
	bool mLegCanMove[4];                                     // _15
	bool mLegMidStep[4];                                     // _19
	bool mShakeDirectionChanged;                             // _1D
	bool mPrevShakeDirection;                                // _1E
	f32 mSegmentScale[16];                                   // _20
	f32 mJointBlendFactor[4];                                // _60
	f32 mGroundHeight[4];                                    // _70
	f32 mShakeAngle;                                         // _80
	f32 mShakeAngularVel;                                    // _84
	f32 mLegSegmentLength[4][2];                             // _88
	f32 mLegMotionProgress[4];                               // _A8
	u8 _B8[0xC8 - 0xB8];                                     // _B8, unknown
	f32 mShakePhase;                                         // _C8
	f32 mOscillationPhase;                                   // _CC
	f32 mFootRaiseHeightList[4];                             // _D0
	f32 mPikiWeightOffset;                                   // _E0
	f32 mTargetDirection;                                    // _E4
	int mStuckPikiCount[4];                                  // _E8
	SpiderLegMotionType::Type mMotionType;                   // _F8
	Vector3f mKneeDirection[4];                              // _FC
	Vector3f mJointPositions[4][3];                          // _12C
	Vector3f mBezierPoints[4][3];                            // _1BC
	Vector3f mTargetCentre;                                  // _24C
	Vector3f mCentreVelocity;                                // _258
	Vector3f mCurrentCentre;                                 // _264
	Quat mJointRotation;                                     // _270
	Matrix4f mJointMatrices[4][4];                           // _280
	SpiderGenHalfDeadCallBackJoint* mHalfDeadCallBackJoints; // _680
	SpiderGenPerishCallBack* mPerishCallBacks;               // _684
	SpiderGenRippleCallBack* mRippleCallBacks;               // _688
};

/**
 * @brief TODO.
 */
struct SpiderDrawer : public Node {
	SpiderDrawer(Spider* spider)
	    : Node("")
	{
		mSpider = spider;
	}

	virtual void draw(Graphics&); // _14

	// _00     = VTBL
	// _00-_20 = Node
	Spider* mSpider; // _20
};

/**
 * @brief TODO.
 *
 * @note Size: 0xC.
 */
struct SpiderAi : public PaniAnimKeyListener {
public:
	SpiderAi(Spider*);

	void initAI(Spider*);
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
	void checkFlickPiki();
	void checkHalfDead();
	void resultFlagOn();
	void resultFlagSeen();
	bool dieTransit();
	bool isMotionFinishTransit();
	bool outSideChaseRangeTransit();
	bool inSideWaitRangeTransit();
	bool chaseNaviTransit();
	bool chasePikiTransit();
	bool shakeOffTransit();
	bool targetLostTransit();
	bool appearTransit();
	void initDie(int);
	void initWalk(int);
	void initShakeOff(int);
	void initAppear(int);
	void initWait(int);
	void dieState();
	void walkRandomState();
	void walkGoHomeState();
	void chaseNaviState();
	void chasePikiState();
	void shakeOffState();
	void waitState();
	void appearState();

public:
	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	Spider* mSpider; // _04
	bool mCanFlick;  // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct SpiderGenHalfDeadCallBackJoint : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		ptclGen->setEmitPosPtr(mPosition);
		if (!mSpider->mIsHalfDead || !mSpider->getAlive()) {
			ptclGen->finish();
		}

		return true;
	}

	void set(immut Vector3f* pos, Spider* spider)
	{
		mPosition = pos;
		mSpider   = spider;
	}

private:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	immut Vector3f* mPosition; // _04
	Spider* mSpider;           // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct SpiderGenPerishCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		Vector3f midPt = *mStartPoint + *mEndPoint;
		midPt.multiply(0.5f);

		Vector3f dir = *mStartPoint - *mEndPoint;
		dir.normalise();

		ptclGen->setEmitPos(midPt);
		ptclGen->setEmitDir(dir);

		if (!mSpider->getMotionFinish()) {
			ptclGen->finish();
		}

		return true;
	}

	void set(immut Vector3f* start, immut Vector3f* end, Spider* spider)
	{
		mStartPoint = start;
		mEndPoint   = end;
		mSpider     = spider;
	}

private:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	immut Vector3f* mStartPoint; // _04
	immut Vector3f* mEndPoint;   // _08
	Spider* mSpider;             // _0C
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct SpiderGenRippleCallBack : public zen::CallBack1<zen::particleGenerator*> {
public:
	virtual bool invoke(zen::particleGenerator* ptclGen) // _08
	{
		if (!*mIsRunning) {
			ptclGen->finish();
		}

		return true;
	}

	void set(bool* cond) { mIsRunning = cond; }

private:
	// _00     = VTBL
	// _00-_04 = zen::CallBack1
	bool* mIsRunning; // _04
};

#endif
