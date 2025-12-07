#ifndef _NUCLEUS_H
#define _NUCLEUS_H

#include "Boss.h"
#include "types.h"

struct Slime;
struct NucleusAi;

/**
 * @brief TODO.
 */
enum NucleusAIStateID {
	NUCLEUSAI_Die    = 0,
	NUCLEUSAI_Damage = 1,
	NUCLEUSAI_Follow = 2,
};

/**
 * @brief TODO.
 */
struct NucleusProp : public BossProp, public CoreNode {
public:
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
		mCreatureProps.read(input);
		mBossProps.read(input);
		mNucleusProps.read(input);
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
	friend struct NucleusAi;

	// This feels a little extra but then again so does Goolix as a whole.
	friend struct SlimeAi;
	friend struct BossMgr; // To initialize `mSlime`.

public:
	Nucleus(CreatureProp*);

	virtual void init(immut Vector3f&); // _28
	virtual f32 getiMass();             // _38
	virtual void update();              // _E0
	virtual void refresh(Graphics&);    // _EC
	virtual void doAI();                // _104
	virtual void doAnimation();         // _108
	virtual void doKill();              // _10C
	virtual void exitCourse();          // _110
	virtual void drawShape(Graphics&);  // _120

private:
	// _00      = VTBL
	// _00-_3B8 = Boss?
	Slime* mSlime;         // _3B8
	NucleusAi* mNucleusAi; // _3BC
};

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct NucleusAi : public PaniAnimKeyListener {
public:
	NucleusAi(Nucleus*);

	void initAI(Nucleus*);
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
	void setBossPosition();
	void setSlimeDamagePoint();
	void afterProcessing();
	bool dieTransit();
	bool isMotionFinishTransit();
	bool damageTransit();
	void initDie(int);
	void initDamage(int);
	void initFollow(int);
	void dieState();
	void damageState();
	void followState();

public:
	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	int mStickPikiCount; // _04
	Nucleus* mNucleus;   // _08
};

#endif
