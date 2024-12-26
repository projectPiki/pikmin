#ifndef _KOGANE_H
#define _KOGANE_H

#include "types.h"
#include "Boss.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

struct KoganeAi;

/**
 * @brief TODO.
 */
struct KoganeProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to KoganeProp for ease of use.
	 */
	struct KoganeProperties : public Parameters {
		inline KoganeProperties() // TODO
		    : mAppearTriggerRadius(this, 30.0f, 0.0f, 0.0f, "o00", nullptr)
		    , mAppearScaleUpSpeed(this, 6.0f, 0.0f, 0.0f, "o01", nullptr)
		    , mDisappearScaleDownSpeed(this, 6.0f, 0.0f, 0.0f, "o02", nullptr)
		    , mMoveSpeed(this, 250.0f, 0.0f, 0.0f, "p00", nullptr)
		    , mTurnSpeed(this, 10.0f, 0.0f, 0.0f, "p10", nullptr)
		    , mGoalAngleMin(this, 30.0f, 0.0f, 0.0f, "p50", nullptr)
		    , mGoalAngleMax(this, 90.0f, 0.0f, 0.0f, "p51", nullptr)
		    , mGoalDistMin(this, 100.0f, 0.0f, 0.0f, "p52", nullptr)
		    , mGoalDistMax(this, 200.0f, 0.0f, 0.0f, "p53", nullptr)
		    , mAppearTimeMin(this, 20.0f, 0.0f, 0.0f, "t00", nullptr)
		    , mAppearTimeMax(this, 30.0f, 0.0f, 0.0f, "t01", nullptr)
		    , mIdleTimeMin(this, 0.5f, 0.0f, 0.0f, "t10", nullptr)
		    , mIdleTimeMax(this, 3.0f, 0.0f, 0.0f, "t11", nullptr)
		    , mMaxSingleRunTime(this, 1.5f, 0.0f, 0.0f, "t50", nullptr)
		    , mModelScale(this, 1.0f, 0.0f, 0.0f, "s00", nullptr)
		{
		}

		// _200-_204 = Parameters
		Parm<f32> mAppearTriggerRadius;     // _204, o00
		Parm<f32> mAppearScaleUpSpeed;      // _214, o01
		Parm<f32> mDisappearScaleDownSpeed; // _224, o02
		Parm<f32> mMoveSpeed;               // _234, p00
		Parm<f32> mTurnSpeed;               // _244, p10
		Parm<f32> mGoalAngleMin;            // _254, p50
		Parm<f32> mGoalAngleMax;            // _264, p51
		Parm<f32> mGoalDistMin;             // _274, p52
		Parm<f32> mGoalDistMax;             // _284, p53
		Parm<f32> mAppearTimeMin;           // _294, t00
		Parm<f32> mAppearTimeMax;           // _2A4, t01
		Parm<f32> mIdleTimeMin;             // _2B4, t10
		Parm<f32> mIdleTimeMax;             // _2C4, t11
		Parm<f32> mMaxSingleRunTime;        // _2D4, t50
		Parm<f32> mModelScale;              // _2E4, s00
	};

	KoganeProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mKoganeProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	KoganeProperties mKoganeProps; // _200
};

/**
 * @brief TODO.
 */
struct Kogane : public Boss {
	Kogane(CreatureProp*);

	virtual void init(Vector3f&);               // _28
	virtual f32 getiMass();                     // _38
	virtual void collisionCallback(CollEvent&); // _A8
	virtual void update();                      // _E0
	virtual void refresh(Graphics&);            // _EC
	virtual void doAI();                        // _104
	virtual void doAnimation();                 // _108
	virtual void doKill();                      // _10C
	virtual void exitCourse();                  // _110
	virtual void drawShape(Graphics&);          // _120

	inline KoganeProp* getKoganeProp() { return static_cast<KoganeProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss
	u8 _3B8;             // _3B8
	u8 _3B9;             // _3B9
	KoganeAi* mKoganeAi; // _3BC
};

/**
 * @brief TODO.
 *
 * @note Size: 0x20.
 */
struct KoganeAi : public PaniAnimKeyListener {
	KoganeAi(Kogane*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void createWaterEffect();
	void killCallBackEffect(bool);
	void initAI(Kogane*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void setMapAttribute();
	void setNewTargetPosition();
	void setRouteTargetPosition();
	void birthItemPellet(int);
	void birthItemWater(int, f32);
	void createPellet();
	void appearTransit();
	void initCreate(int);
	void update();

	// unused/inlined:
	void keyAction2();
	void keyAction3();
	void setEveryFrame();
	void checkAppearTimeCounter();
	void calcScaleUp();
	void makeTargetRandom();
	void makeStopMoving();
	void resultFlagOn();
	void dieTransit();
	void isMotionFinishTransit();
	void startWalkTransit();
	void stopWalkTransit();
	void changeTargetTransit();
	void createPelletTransit();
	void initDie(int);
	void initAppear(int);
	void initWalkRandom(int, bool);
	void initStopWalk(int);
	void dieState();
	void walkRandomState();
	void stopWalkState();
	void createState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	u8 _04[0x20 - 0x4]; // _04, unknown
};

/**
 * @brief TODO
 */
struct KoganeGenRippleCallBack : public zen::CallBack1<zen::particleGenerator*> {
	KoganeGenRippleCallBack();

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

#endif
