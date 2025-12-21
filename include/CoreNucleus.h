#ifndef _CORENUCLEUS_H
#define _CORENUCLEUS_H

#include "Boss.h"
#include "types.h"

struct CoreNucleusAi;
struct Slime;

/**
 * @brief TODO.
 */
enum CoreNucleusAIStateID {
	COREAI_Die    = 0,
	COREAI_Damage = 1,
	COREAI_Follow = 2,
	COREAI_Hit    = 3,
};

/**
 * @brief TODO.
 */
struct CoreNucleusProp : public BossProp, public CoreNode {
public:
	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to CoreNucleusProp for ease of use.
	 */
	struct Parms : public Parameters {
		inline Parms() // TODO
		{
		}

		// _200-_204 = Parameters
	};

	CoreNucleusProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.read(input);
		mBossProps.read(input);
		mCoreNucleusProps.read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	Parms mCoreNucleusProps; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x3C8.
 */
struct CoreNucleus : public Boss {
	friend struct CoreNucleusAi;

	// This feels a little extra but then again so does Goolix as a whole.
	friend struct SlimeAi;
	friend struct BossMgr; // To initialize `mSlime`.

public:
	CoreNucleus(CreatureProp*);

	virtual void init(immut Vector3f& pos);           // _28
	virtual f32 getiMass();                           // _38
	virtual void collisionCallback(immut CollEvent&); // _A8
	virtual void update();                            // _E0
	virtual void refresh(Graphics&);                  // _EC
	virtual void doAI();                              // _104
	virtual void doAnimation();                       // _108
	virtual void doKill();                            // _10C
	virtual void exitCourse();                        // _110
	virtual void drawShape(Graphics&);                // _120

private:
	// _00      = VTBL
	// _00-_3B8 = Boss
	u8 _3B8[0x4];           // _3B8, unknown
	Slime* mSlime;          // _3BC
	CoreNucleusAi* mCoreAi; // _3C0
	u8 _3C4[0x4];           // _3C4, unknown
};

/**
 * @brief TODO.
 *
 * @note Size: 0xC.
 */
struct CoreNucleusAi : public PaniAnimKeyListener {
public:
	CoreNucleusAi(CoreNucleus*);

	void initAI(CoreNucleus*);
	void update();
	void setHitMotionStart();

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
	bool hitMotionStartTransit();
	void initDie(int);
	void initDamage(int);
	void initFollow(int);
	void initHit(int);
	void dieState();
	void damageState();
	void followState();
	void hitState();

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	bool mIsHit;        // _04
	CoreNucleus* mCore; // _08
};

#endif
