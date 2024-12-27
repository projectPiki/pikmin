#ifndef _SPIDER_H
#define _SPIDER_H

#include "types.h"
#include "Boss.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

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
		inline SpiderProperties() // TODO
		{
		}

		// _200-_204 = Parameters
		u8 _204[0x554 - 0x204]; // _204, TODO: fill in
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

	virtual void init(Vector3f&);      // _28
	virtual f32 getiMass();            // _38
	virtual void update();             // _E0
	virtual void refresh(Graphics&);   // _EC
	virtual void doAI();               // _104
	virtual void doAnimation();        // _108
	virtual void doKill();             // _10C
	virtual void exitCourse();         // _110
	virtual bool isBossBgm();          // _114
	virtual void drawShape(Graphics&); // _120

	void draw(Graphics&);

	inline SpiderProp* getSpiderProp() { return static_cast<SpiderProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss
	u8 _3B8[0x764 - 0x3B8]; // _3B8, unknown
};

/*
 * @brief TODO
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

	// TODO: members
};

/**
 * @brief TODO.
 */
struct SpiderDrawer : public Node {

	virtual void draw(Graphics&); // _14

	// _00     = VTBL
	// _00-_20 = Node
	// TODO: members
};

/**
 * @brief TODO.
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
	// TODO: members
};

/**
 * @brief TODO
 */
struct SpiderGenHalfDeadCallBackJoint : public zen::CallBack1<zen::particleGenerator*> {
	SpiderGenHalfDeadCallBackJoint();

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

/**
 * @brief TODO
 */
struct SpiderGenPerishCallBack : public zen::CallBack1<zen::particleGenerator*> {
	SpiderGenPerishCallBack();

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

/**
 * @brief TODO
 */
struct SpiderGenRippleCallBack : public zen::CallBack1<zen::particleGenerator*> {
	SpiderGenRippleCallBack();

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

#endif
