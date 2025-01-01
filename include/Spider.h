#ifndef _SPIDER_H
#define _SPIDER_H

#include "types.h"
#include "Boss.h"
#include "MapMgr.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

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

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to SpiderProp for ease of use.
	 */
	struct SpiderProperties : public Parameters {
		inline SpiderProperties()
		    : _204(this, 1.5f, 0.1f, 10.0f, "p10", "Motion Speed (UP)")
		    , _214(this, 0.113f, 0.0f, 0.5f, "p11", "Speed Down")
		    , _224(this, 0.37f, 0.1f, 1.0f, "p12", "")
		    , _234(this, 7.0f, 0.1f, 10.0f, "p13", "Motion Speed (DOWN)")
		    , _244(this, 0.1f, 0.0f, 10.0f, "p14", "Speed Up")
		    , _254(this, 10.0f, 0.1f, 100.0f, "p15", "")
		    , _264(this, 120.0f, 0.0f, 150.0f, "p20", "")
		    , _274(this, 15.0f, 0.0f, 100.0f, "p21", "")
		    , _284(this, 45.0f, 0.0f, 100.0f, "p22", "")
		    , _294(this, 15.0f, 0.0f, 10.0f, "p23", "")
		    , _2A4(this, 50.0f, 0.0f, 100.0f, "p24", "")
		    , _2B4(this, 75.0f, 0.0f, 100.0f, "p30", "")
		    , _2C4(this, 100.0f, 0.0f, 200.0f, "p31", "")
		    , _2D4(this, 100.0f, 0.0f, 150.0f, "p32", "Landing Radius(Min)")
		    , _2E4(this, 125.0f, 0.0f, 200.0f, "p33", "Landing Radius(Max)")
		    , _2F4(this, 0.7f, 0.0f, 1.0f, "p34", "")
		    , _304(this, 1.2f, 0.0f, 2.0f, "p35", "")
		    , _314(this, 1.8f, 0.5f, 2.0f, "p40", "")
		    , _324(this, 25.0f, 0.0f, 100.0f, "p50", "Step Area")
		    , _334(this, 20.0f, 0.0f, 100.0f, "p51", "Step Navi")
		    , _344(this, 200.0f, 0.0f, 200.0f, "p52", "Step Piki")
		    , _354(this, 0.3f, 0.0f, 1.0f, "p53", "Step Shake Off(%)")
		    , _364(this, 100.0f, 0.0f, 500.0f, "p54", "Shake Off Power")
		    , _374(this, 0.0f, 0.0f, 100.0f, "p55", "Shake Off Damage")
		    , _384(this, 0.15f, 0.0f, 1.0f, "p56", "Vibration")
		    , _394(this, 2.0f, 0.0f, 10.0f, "p57", "MAX Vibration")
		    , _3A4(this, 0.15f, 0.0f, 1.0f, "p60", "")
		    , _3B4(this, 0.95f, 0.0f, 1.0f, "p61", "")
		    , _3C4(this, 30.0f, 0.0f, 50.0f, "p62", "")
		    , _3D4(this, 0.01f, 0.0f, 1.0f, "p63", "")
		    , _3E4(this, 30.0f, 0.0f, 100.0f, "p70", "")
		    , _3F4(this, 2.0f, 0.0f, 10.0f, "p71", "")
		    , _404(this, 1.0f, 0.0f, 5.0f, "p72", "")
		    , _414(this, 0.5f, 0.0f, 2.0f, "p73", "")
		    , _424(this, 0.9f, 0.0f, 1.0f, "p74", "")
		    , _434(this, 1.6f, 0.0f, 3.0f, "p75", "")
		    , mSpawnTriggerDist(this, 180.0f, 0.0f, 500.0f, "c00", "")
		    , mDropTimer(this, 0.05f, 0.0f, 10.0f, "c01", "")
		    , mDeadBombEffectDelay(this, 5.9f, 0.0f, 10.0f, "t00", "Dead Bomb Effect")
		    , mDeadScaleStartDelay(this, 6.0f, 0.0f, 10.0f, "s00", "Dead Scale Start")
		    , mDeadScaleStageDelay(this, 0.1f, 0.1f, 10.0f, "s01", "Dead Scale Timing")
		    , mDeadMotionDelay(this, 0.1f, 0.1f, 10.0f, "s02", "Dead Scale Time")
		    , _4A4(this, 100.0f, 0.0f, 500.0f, "s10", "Stick Heiht Modify")
		    , _4B4(this, 100.0f, 0.0f, 500.0f, "s11", "Map Heiht Modify")
		    , _4C4(this, 150.0f, 0.0f, 300.0f, "s30", "Target Centre")
		    , _4D4(this, 0.5f, 0.0f, 1.0f, "s31", "Cent Leg Dist(Min)")
		    , _4E4(this, 0.75f, 0.0f, 1.0f, "s32", "Cent Leg Dist(Max)")
		    , mMinWaitCycles(this, 1, 1, 10, "i00", "")
		    , mMaxWaitCycles(this, 2, 1, 10, "i01", "")
		    , mMinWalkCycles(this, 2, 1, 10, "i02", "")
		    , mMaxWalkCycles(this, 4, 1, 10, "i03", "")
		    , mDoDropFromSky(this, 1, 0, 1, "i10", "")
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
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mSpiderProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	SpiderProperties mSpiderProps; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x764
 */
struct Spider : public Boss {
	Spider(CreatureProp*);

	virtual void init(Vector3f&);                   // _28
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

	inline SpiderProp* getSpiderProp() { return static_cast<SpiderProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss
	bool mIsBossBgm;             // _3B8
	u8 _3B9;                     // _3B9
	u8 _3BA;                     // _3BA
	u8 _3BB;                     // _3BB
	int _3BC;                    // _3BC
	SpiderAi* mSpiderAi;         // _3C0
	SpiderLeg* mSpiderLeg;       // _3C4
	bool mIsAppear;              // _3C8
	bool mHasShadow;             // _3C9
	ShadowCaster mShadowCaster;  // _3CC
	SpiderDrawer* mSpiderDrawer; // _760
};

/**
 * @brief TODO
 *
 * @note Size: 0x68C.
 */
struct SpiderLeg {
	SpiderLeg(Spider*);

	void setHalfDeadFallEffect(u32);
	void setDeadBombEffect(u32);
	void createHalfDeadEffect();
	void createDeadBombEffect();
	void createSmallSparkEffect(int);
	void createPerishEffect();
	void createRippleEffect(int);
	void killCallBackEffect(bool);
	void setLegScaleParam(int);
	void init(Spider*);
	void initParm(int);
	void setLegParameter();
	void setWalkNewParameter();
	void setShakeOffNewParameter();
	void setBodyShakeNewParameter();
	void setNextDirAndCent();
	void setWalkNewPosition();
	void checkMotionRatio();
	void makeNewPosition();
	void calcStickersPiki();
	void setIdealCentre(Vector3f&);
	void setRealCentre(Vector3f&);
	void updateAnimation(const BossShapeObject*, Graphics&, Matrix4f&);
	void getHeight();
	void stepDamageNavi(int);
	void stepDamagePiki(int);
	void stepShakeOffPiki(int);
	void emitOnGroundEffect(int);
	void setKneeDirection();
	void create3Joint(BossShapeObject*, Graphics&);
	void update();
	void refresh(BossShapeObject*, Graphics&);

	// unused/inlined:
	void setHalfDeadEffect(u32, int, int);
	void setSmallSparkEffect(u32, int*);
	void setPerishEffect(u32, int);
	void createHalfDeadFallEffect(int);
	void checkGroundTimer();
	void calcSpiderDirection();
	void calcShakeOffDirection();
	void calcShakeOff();
	void setCentrePosition();
	void setJointMatrix(const BossShapeObject*, Matrix4f&);
	void setLength();
	void getLegController();
	void setQuatParameter();
	void onGroundFunction();
	void emitOffGroundEffect();
	void getJointMatrix(Vector3f&, Vector3f&, Vector3f&, Matrix4f&);
	void calcQuatToMatrix(int);
	void createMatrixScale(BossShapeObject*, Graphics&);
	void setGroundFlag();
	void checkMotionFinished();

	Spider* mSpider;                                         // _00
	u8 _04;                                                  // _04
	u8 _05;                                                  // _05
	u8 _06;                                                  // _06
	u8 _07;                                                  // _07
	u8 _08[0xFC - 0x8];                                      // _08, unknown
	Vector3f _FC[4];                                         // _FC
	Vector3f _12C[12];                                       // _12C
	Vector3f _1BC[12];                                       // _1BC
	Vector3f _24C;                                           // _24C
	Vector3f _258;                                           // _258
	Vector3f _264;                                           // _264
	Quat _270;                                               // _270
	Matrix4f _280[16];                                       // _280
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
	SpiderAi(Spider*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initAI(Spider*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	bool appearTransit();
	void dieState();
	void update();

	// unused/inlined:
	void keyAction2();
	void keyAction3();
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
	void initDie(int);
	void initWalk(int);
	void initShakeOff(int);
	void initAppear(int);
	void initWait(int);
	void walkRandomState();
	void walkGoHomeState();
	void chaseNaviState();
	void chasePikiState();
	void shakeOffState();
	void waitState();
	void appearState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	Spider* mSpider; // _04
	bool _08;        // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct SpiderGenHalfDeadCallBackJoint : public zen::CallBack1<zen::particleGenerator*> {
	SpiderGenHalfDeadCallBackJoint() { }

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	u8 _04[8]; // _04, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct SpiderGenPerishCallBack : public zen::CallBack1<zen::particleGenerator*> {
	SpiderGenPerishCallBack() { }

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	u8 _04[0xC]; // _04, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct SpiderGenRippleCallBack : public zen::CallBack1<zen::particleGenerator*> {
	SpiderGenRippleCallBack() { }

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	u8 _04[4]; // _04, unknown
};

#endif
