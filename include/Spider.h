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
		    , _444(this, 180.0f, 0.0f, 500.0f, "c00", "")
		    , _454(this, 0.05f, 0.0f, 10.0f, "c01", "")
		    , _464(this, 5.9f, 0.0f, 10.0f, "t00", "Dead Bomb Effect")
		    , _474(this, 6.0f, 0.0f, 10.0f, "s00", "Dead Scale Start")
		    , _484(this, 0.1f, 0.1f, 10.0f, "s01", "Dead Scale Timing")
		    , _494(this, 0.1f, 0.1f, 10.0f, "s02", "Dead Scale Time")
		    , _4A4(this, 100.0f, 0.0f, 500.0f, "s10", "Stick Heiht Modify")
		    , _4B4(this, 100.0f, 0.0f, 500.0f, "s11", "Map Heiht Modify")
		    , _4C4(this, 150.0f, 0.0f, 300.0f, "s30", "Target Centre")
		    , _4D4(this, 0.5f, 0.0f, 1.0f, "s31", "Cent Leg Dist(Min)")
		    , _4E4(this, 0.75f, 0.0f, 1.0f, "s32", "Cent Leg Dist(Max)")
		    , _4F4(this, 1, 1, 10, "i00", "")
		    , _504(this, 2, 1, 10, "i01", "")
		    , _514(this, 2, 1, 10, "i02", "")
		    , _524(this, 4, 1, 10, "i03", "")
		    , _534(this, 1, 0, 1, "i10", "")
		    , _544(this, 1, 0, 1, "i20", "Erase Shape")
		{
		}

		// _200-_204 = Parameters
		Parm<f32> _204; // _204
		Parm<f32> _214; // _214
		Parm<f32> _224; // _224
		Parm<f32> _234; // _234
		Parm<f32> _244; // _244
		Parm<f32> _254; // _254
		Parm<f32> _264; // _264
		Parm<f32> _274; // _274
		Parm<f32> _284; // _284
		Parm<f32> _294; // _294
		Parm<f32> _2A4; // _2A4
		Parm<f32> _2B4; // _2B4
		Parm<f32> _2C4; // _2C4
		Parm<f32> _2D4; // _2D4
		Parm<f32> _2E4; // _2E4
		Parm<f32> _2F4; // _2F4
		Parm<f32> _304; // _304
		Parm<f32> _314; // _314
		Parm<f32> _324; // _324
		Parm<f32> _334; // _334
		Parm<f32> _344; // _344
		Parm<f32> _354; // _354
		Parm<f32> _364; // _364
		Parm<f32> _374; // _374
		Parm<f32> _384; // _384
		Parm<f32> _394; // _394
		Parm<f32> _3A4; // _3A4
		Parm<f32> _3B4; // _3B4
		Parm<f32> _3C4; // _3C4
		Parm<f32> _3D4; // _3D4
		Parm<f32> _3E4; // _3E4
		Parm<f32> _3F4; // _3F4
		Parm<f32> _404; // _404
		Parm<f32> _414; // _414
		Parm<f32> _424; // _424
		Parm<f32> _434; // _434
		Parm<f32> _444; // _444
		Parm<f32> _454; // _454
		Parm<f32> _464; // _464
		Parm<f32> _474; // _474
		Parm<f32> _484; // _484
		Parm<f32> _494; // _494
		Parm<f32> _4A4; // _494
		Parm<f32> _4B4; // _494
		Parm<f32> _4C4; // _494
		Parm<f32> _4D4; // _494
		Parm<f32> _4E4; // _494
		Parm<int> _4F4; // _4A4
		Parm<int> _504; // _4B4
		Parm<int> _514; // _4C4
		Parm<int> _524; // _4D4
		Parm<int> _534; // _4E4
		Parm<int> _544; // _4F4
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
	u32 _3BC;                    // _3BC, unknown
	SpiderAi* mSpiderAi;         // _3C0
	SpiderLeg* mSpiderLeg;       // _3C4
	u8 _3C8;                     // _3C8
	u8 _3C9;                     // _3C9
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
	u8 _04[0xFC - 0x4];                                      // _04, unknown
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
	void appearTransit();
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
	void dieTransit();
	void isMotionFinishTransit();
	void outSideChaseRangeTransit();
	void inSideWaitRangeTransit();
	void chaseNaviTransit();
	void chasePikiTransit();
	void shakeOffTransit();
	void targetLostTransit();
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
	u8 _08;          // _08
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
