#ifndef _POM_H
#define _POM_H

#include "types.h"
#include "Boss.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

/**
 * @brief TODO.
 */
struct PomProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to PomProp for ease of use.
	 */
	struct PomProperties : public Parameters {
		inline PomProperties() // TODO
		{
		}

		// _200-_204 = Parameters
	};

	PomProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mPomProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	PomProperties mPomProps; // _200
};

/**
 * @brief TODO.
 */
struct Pom : public Boss {
	Pom(CreatureProp*);

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

	void setColor(int);

	inline PomProp* getPomProp() { return static_cast<PomProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss?
	// TODO: members
};

/**
 * @brief TODO.
 */
struct PomAi : public PaniAnimKeyListener {
	PomAi(Pom*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initAI(Pom*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void killCallBackEffect(bool);
	void collidePetal(Creature*);
	void setCollideSound(Creature*);
	void killStickPiki();
	void createPikiHead();
	void calcPetalStickers();
	void initWait(int);
	void initDischarge(int);
	void update();

	// unused/inlined:
	void keyAction2();
	void keyAction3();
	void setEveryFrame();
	void resultFlagOn();
	void isMotionFinishTransit();
	void initDie(int);
	void dieState();
	void checkSwayAndScale();
	void calcSwayAndScale();
	void setInitPosition();
	void emitPomOpenEffect(u32);
	void createPomOpenEffect();
	void resultFlagSeen();
	void deadTransit();
	void petalOpenTransit();
	void petalShakeTransit();
	void petalCloseTransit();
	void dischargeTransit();
	void initPetalOpen(int);
	void initPetalShake(int);
	void initPetalClose(int);
	void waitState();
	void openState();
	void shakeState();
	void closeState();
	void dischargeState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct PomGenOpenStarCallBack : public zen::CallBack1<zen::particleGenerator*> {
	PomGenOpenStarCallBack();

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

#endif
