#ifndef _AICREATURE_H
#define _AICREATURE_H

#include "types.h"
#include "Creature.h"
#include "Vector.h"
#include "PaniAnimator.h"

template <typename T>
struct AState;

template <typename T>
struct StateMachine;

struct CollEvent;

/**
 * @brief TODO
 *
 * @note Size: 0x304.
 */
struct AICreature : public Creature, public PaniAnimKeyListener {
	AICreature(CreatureProp*);

	virtual void collisionCallback(CollEvent&);                                     // _A8
	virtual void bounceCallback();                                                  // _AC
	virtual void refresh(Graphics&) = 0;                                            // _EC
	virtual void doKill()           = 0;                                            // _10C
	virtual AState<AICreature>* getCurrState() { return mCurrentState; }            // _120 (weak)
	virtual void setCurrState(AState<AICreature>* state) { mCurrentState = state; } // _124 (weak)
	virtual void playSound(int) { }                                                 // _128 (weak)
	virtual void playEffect(int) { }                                                // _12C (weak)
	virtual void startMotion(int) { }                                               // _130 (weak)
	virtual void finishMotion() { }                                                 // _134 (weak)
	virtual void finishMotion(f32) { }                                              // _138 (weak)
	virtual void startMotion(int, f32) { }                                          // _13C (weak)
	virtual char* getCurrentMotionName() { return "noname"; }                       // _140 (weak)
	virtual f32 getCurrentMotionCounter() { return -123.4f; }                       // _144 (weak)
	virtual f32 getMotionSpeed() { return -123.4f; }                                // _148 (weak)
	virtual void setMotionSpeed(f32) { }                                            // _14C (weak)
	virtual void stopMotion() { }                                                   // _150 (weak)
	virtual void animationKeyUpdated(PaniAnimKeyEvent&);                            // _154 (weak)

	void clearEventFlags();
	void setEventFlag(int, bool);

	// unused/inlined:
	bool checkEventFlag(int);

	// _00       = VTBL
	// _00-_2B8  = Creature
	// _2B8-_2BC = PaniAnimKeyListener
	Creature* mCollidingCreature;            // _2BC
	u32 _2C0;                                // _2C0, unknown
	Vector3f _2C4;                           // _2C4, could just be floats
	int _2D0;                                // _2D0, to do with bombs
	u32 _2D4;                                // _2D4, unknown
	f32 _2D8;                                // _2D8
	u8 _2DC[4];                              // _2DC, unknown
	f32 _2E0;                                // _2E0
	AState<AICreature>* mCurrentState;       // _2E4
	StateMachine<AICreature>* mStateMachine; // _2E8
	int mCurrentEventCount;                  // _2EC, unknown
	int mMaxEventCount;                      // _2F0
	bool mEventFlags[16];                    // _2F4
};

#endif
