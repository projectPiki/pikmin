#ifndef _SNAKE_H
#define _SNAKE_H

#include "types.h"
#include "Boss.h"
#include "Collision.h"
#include "zen/Callback.h"
#include "zen/Particle.h"

/**
 * @brief TODO.
 */
struct SnakeProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to SnakeProp for ease of use.
	 */
	struct SnakeProperties : public Parameters {
		inline SnakeProperties() // TODO
		{
		}

		// _200-_204 = Parameters
	};

	SnakeProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mSnakeProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	SnakeProperties mSnakeProps; // _200
};

/**
 * @brief TODO.
 */
struct Snake : public Boss {

	/**
	 * @brief TODO.
	 */
	struct BoundSphereUpdater : public CollPartUpdater {

		virtual void getPos();  // _08
		virtual void getSize(); // _0C

		// _00     = VTBL?
		// _00-_04 = CollPartUpdater?
		// TODO: members
	};

	Snake(CreatureProp*);

	virtual void init(Vector3f&);      // _28
	virtual f32 getiMass();            // _38
	virtual f32 getCentreSize();       // _5C
	virtual void update();             // _E0
	virtual void refresh(Graphics&);   // _EC
	virtual void refresh2d(Graphics&); // _F0
	virtual void doAI();               // _104
	virtual void doAnimation();        // _108
	virtual void doKill();             // _10C
	virtual void exitCourse();         // _110
	virtual void drawShape(Graphics&); // _120

	void setBossType(bool);

	inline SnakeProp* getSnakeProp() { return static_cast<SnakeProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss?
	// TODO: members
};

/*
 * @brief TODO
 */
struct SnakeBody {
	SnakeBody(Snake*);

	void setBodyOnGroundEffect();
	void killCallBackEffect(bool);
	void init(Vector3f&, Snake*);
	void initBlending(f32);
	void makeTurnVelocity();
	void makeResultPosition();
	void makeVectorMatrix();
	void createDeadHeadEffect();
	void createDeadBodyEffect();
	void makeDeadPattern01();
	void update();
	void makeBodySize();
	void makeHeadPosition();
	void makeBodyMatrix();
	void makeAnimMatrix();
	void caseOfMatrix(Matrix4f*);
	void makeBlending(Matrix4f*);
	void setDeadPattern01(Matrix4f*);
	void returnJoint(BossShapeObject*, Graphics&, Matrix4f*);
	void refresh(BossShapeObject*, Graphics&);

	// unused/inlined:
	void updateBlendingRatio();
	void setInitializePosition();
	void copyAnimPosition();
	void makeHeadDirection();
	void makeNewPosition();
	void createDeadPellet(Vector3f&, int);
	void makeDeadPattern02();
	void makeDeadScaleParms();
	void makeAnimation(BossShapeObject*, Graphics&);
	void checkBlendingParm(Matrix4f*);
	void setDeadPattern02(Matrix4f*);
	void setDeadScale(Matrix4f*);

	// TODO: members
};

/**
 * @brief TODO.
 */
struct SnakeAi : public PaniAnimKeyListener {
	SnakeAi(Snake*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initAI(Snake*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void traceTargetPosition();
	void setAttackPosition();
	void checkAttackTarget();
	void naviNudge();
	void pikiStickMouth();
	void eatStickToMouthPiki();
	void nearNaviInAttackArea(Creature**, f32*, int);
	void nearPikiInAttackArea(Creature**, f32*, int);
	void naviInAttackArea(int);
	void pikiInAttackArea(int);
	void appearType01();
	void appearType02();
	void chaseNaviTransit();
	void chasePikiTransit();
	void targetLostTransit();
	void attackTransit(int);
	void collPartMaxTransit();
	void initAttack(int, f32);
	void initAppear(int);
	void struggleState();
	void update();

	// unused/inlined:
	void keyAction2();
	void keyAction3();
	void setEveryFrame();
	void setInitPosition();
	void setUnderPosition();
	void setAppearPosition01();
	void setAppearPosition02();
	void setMouthCollPart(int);
	void getMouthCollPart(int);
	void resultFlagOn();
	void resultFlagSeen();
	void dieTransit();
	void struggleTransit();
	void eatPikiTransit();
	void intoGroundTransit();
	void diveTimerTransit();
	void underTimerTransit();
	void appearTransit();
	void initDie(int);
	void initStruggle(int);
	void initChase(int);
	void initEat(int);
	void initWait(int);
	void initGointo(int);
	void initUnder(int);
	void dieState();
	void chaseState();
	void attackState();
	void eatState();
	void waitState();
	void gointoState();
	void underState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	// TODO: members
};

/**
 * @brief TODO
 */
struct SnakeGenBodyOnGroundCallBack : public zen::CallBack1<zen::particleGenerator*> {
	SnakeGenBodyOnGroundCallBack();

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

/**
 * @brief TODO
 */
struct SnakeGenBodyRotateCallBack : public zen::CallBack1<zen::particleGenerator*> {
	SnakeGenBodyRotateCallBack();

	virtual bool invoke(zen::particleGenerator*); // _08

	// _00     = VTBL?
	// _00-_04 = zen::CallBack1?
	// TODO: members
};

#endif
