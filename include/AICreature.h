#ifndef _AICREATURE_H
#define _AICREATURE_H

#include "Creature.h"
#include "PaniAnimator.h"
#include "Vector.h"
#include "types.h"

template <typename T>
class AState;

template <typename T>
class StateMachine;

class AICreature;
class CollEvent;

/**
 * @brief TODO
 *
 * @note Size: 0x48.
 */
struct SAIContext {
	SAIContext()
	{
		mCollidingCreature = nullptr;
		_08.set(0.0f, 0.0f, 0.0f);
		mCounter           = 0;
		mCurrAnimId        = 0;
		mCurrentState      = nullptr;
		mCurrentItemHealth = 0.0f;
	}

	Creature* mCollidingCreature;            // _00
	Creature* mTargetCreature;               // _04
	Vector3f _08;                            // _08
	int mCurrAnimId;                         // _14, to do with bombs
	int mCounter;                            // _18, used by `SluiceAI`, `PikiHeadAI`, and `GoalAI`.
	f32 mCurrentItemHealth;                  // _1C
	f32 _20;                                 // _20
	f32 mMaxItemHealth;                      // _24
	AState<AICreature>* mCurrentState;       // _28
	StateMachine<AICreature>* mStateMachine; // _2C
	int mCurrentEventCount;                  // _30
	int mMaxEventCount;                      // _34
	bool mEventFlags[16];                    // _38
};

/**
 * @brief TODO
 *
 * @note Size: 0x304.
 */
class AICreature : public Creature, public PaniAnimKeyListener {
public:
	AICreature(CreatureProp*);

	virtual void collisionCallback(immut CollEvent&);                                       // _A8
	virtual void bounceCallback();                                                          // _AC
	virtual void refresh(Graphics&) = 0;                                                    // _EC
	virtual void doKill()           = 0;                                                    // _10C
	virtual AState<AICreature>* getCurrState() { return mSAICtx.mCurrentState; }            // _120 (weak)
	virtual void setCurrState(AState<AICreature>* state) { mSAICtx.mCurrentState = state; } // _124 (weak)
	virtual void playSound(int) { }                                                         // _128 (weak)
	virtual void playEffect(int) { }                                                        // _12C (weak)
	virtual void startMotion(int) { }                                                       // _130 (weak)
	virtual void finishMotion() { }                                                         // _134 (weak)
	virtual void finishMotion(f32) { }                                                      // _138 (weak)
	virtual void startMotion(int, f32) { }                                                  // _13C (weak)
	virtual immut char* getCurrentMotionName() { return "noname"; }                         // _140 (weak)
	virtual f32 getCurrentMotionCounter() { return -123.4f; }                               // _144 (weak)
	virtual f32 getMotionSpeed() { return -123.4f; }                                        // _148 (weak)
	virtual void setMotionSpeed(f32) { }                                                    // _14C (weak)
	virtual void stopMotion() { }                                                           // _150 (weak)
	virtual void animationKeyUpdated(immut PaniAnimKeyEvent&);                              // _154 (weak)

	void clearEventFlags();
	void setEventFlag(int, bool);

	// unused/inlined:
	bool checkEventFlag(int);

	// _00       = VTBL
	// _00-_2B8  = Creature
	// _2B8-_2BC = PaniAnimKeyListener
	SAIContext mSAICtx; // _2BC
};

#endif
