#ifndef _KOGANE_H
#define _KOGANE_H

#include "types.h"
#include "Boss.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

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
		{
		}

		// _200-_204 = Parameters
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
	// _00-_3B8 = Boss?
	// TODO: members
};

/**
 * @brief TODO.
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
	// TODO: members
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
