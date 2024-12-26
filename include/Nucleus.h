#ifndef _NUCLEUS_H
#define _NUCLEUS_H

#include "types.h"
#include "Boss.h"

struct Slime;
struct NucleusAi;

/**
 * @brief TODO.
 */
struct NucleusProp : public BossProp, public CoreNode {

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to NucleusProp for ease of use.
	 */
	struct NucleusProperties : public Parameters {
		inline NucleusProperties() // TODO
		{
		}

		// _200-_204 = Parameters
	};

	NucleusProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mNucleusProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	NucleusProperties mNucleusProps; // _200
};

/**
 * @brief TODO.
 */
struct Nucleus : public Boss {
	Nucleus(CreatureProp*);

	virtual void init(Vector3f&);      // _28
	virtual f32 getiMass();            // _38
	virtual void update();             // _E0
	virtual void refresh(Graphics&);   // _EC
	virtual void doAI();               // _104
	virtual void doAnimation();        // _108
	virtual void doKill();             // _10C
	virtual void exitCourse();         // _110
	virtual void drawShape(Graphics&); // _120

	inline NucleusProp* getNucleusProp() { return static_cast<NucleusProp*>(mProps); }

	// _00      = VTBL
	// _00-_3B8 = Boss?
	Slime* mSlime;         // _3B8
	NucleusAi* mNucleusAI; // _3BC
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct NucleusAi : public PaniAnimKeyListener {
	NucleusAi(Nucleus*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initAI(Nucleus*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void update();

	// unused/inlined:
	void keyAction2();
	void keyAction3();
	void setEveryFrame();
	void setBossPosition();
	void setSlimeDamagePoint();
	void afterProcessing();
	void dieTransit();
	void isMotionFinishTransit();
	void damageTransit();
	void initDie(int);
	void initDamage(int);
	void initFollow(int);
	void dieState();
	void damageState();
	void followState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	int mStickPikiCount; // _04
	Nucleus* mNucleus;   // _08
};

#endif
