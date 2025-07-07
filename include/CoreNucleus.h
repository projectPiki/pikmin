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

	/**
	 * @brief TODO.
	 *
	 * @note Offset comments are relative to CoreNucleusProp for ease of use.
	 */
	struct CoreNucleusProperties : public Parameters {
		inline CoreNucleusProperties() // TODO
		{
		}

		// _200-_204 = Parameters
	};

	CoreNucleusProp();

	virtual void read(RandomAccessStream& input) // _08
	{
		mCreatureProps.Parameters::read(input);
		mBossProps.Parameters::read(input);
		mCoreNucleusProps.Parameters::read(input);
	};

	// _54       = VTBL 1
	// _1EC      = VTBL 2
	// _00-_1EC  = BossProp
	// _1EC-_200 = CoreNode
	CoreNucleusProperties mCoreNucleusProps; // _200
};

/**
 * @brief TODO.
 *
 * @note Size: 0x3C8.
 */
struct CoreNucleus : public Boss {
	CoreNucleus(CreatureProp*);

	virtual void init(Vector3f& pos);           // _28
	virtual f32 getiMass();                     // _38
	virtual void collisionCallback(CollEvent&); // _A8
	virtual void update();                      // _E0
	virtual void refresh(Graphics&);            // _EC
	virtual void doAI();                        // _104
	virtual void doAnimation();                 // _108
	virtual void doKill();                      // _10C
	virtual void exitCourse();                  // _110
	virtual void drawShape(Graphics&);          // _120

	inline CoreNucleusProp* getCoreNucleusProp() { return static_cast<CoreNucleusProp*>(mProps); }

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
	CoreNucleusAi(CoreNucleus*);

	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _08

	void initAI(CoreNucleus*);
	void keyAction0();
	void keyAction1();
	void keyLoopEnd();
	void keyFinished();
	void playSound(int);
	void setHitMotionStart();
	void update();

	// unused/inlined:
	void keyAction2();
	void keyAction3();
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

	inline void setCore(CoreNucleus* core) { mCore = core; }

	// _00     = VTBL
	// _00-_04 = PaniAnimKeyListener
	bool mIsHit;        // _04
	CoreNucleus* mCore; // _08
};

#endif
