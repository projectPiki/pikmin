#ifndef _AICREATURE_H
#define _AICREATURE_H

#include "types.h"
#include "Creature.h"
#include "Vector.h"
#include "PaniAnimator.h"

template <typename T>
struct AState;

/**
 * @brief TODO
 */
struct AICreature : public Creature, public PaniAnimKeyListener {
	AICreature(CreatureProp*);

	virtual void collisionCallback(CollEvent&);          // _A8
	virtual void bounceCallback();                       // _AC
	virtual void refresh(Graphics&) = 0;                 // _EC
	virtual void doKill()           = 0;                 // _10C
	virtual AState<AICreature>* getCurrState();          // _120 (weak)
	virtual void setCurrState(AState<AICreature>*);      // _124 (weak)
	virtual void playSound(int);                         // _128 (weak)
	virtual void playEffect(int);                        // _12C (weak)
	virtual void startMotion(int);                       // _130 (weak)
	virtual void finishMotion();                         // _134 (weak)
	virtual void finishMotion(f32);                      // _138 (weak)
	virtual void startMotion(int, f32);                  // _13C (weak)
	virtual void getCurrentMotionName();                 // _140 (weak)
	virtual void getCurrentMotionCounter();              // _144 (weak)
	virtual void getMotionSpeed();                       // _148 (weak)
	virtual void setMotionSpeed(f32);                    // _14C (weak)
	virtual void stopMotion();                           // _150 (weak)
	virtual void animationKeyUpdated(PaniAnimKeyEvent&); // _154 (weak)

	void clearEventFlags();
	void setEventFlag(int, bool);

	// unused/inlined:
	void checkEventFlag(int);

	// _00       = VTBL
	// _00-_2B8  = Creature
	// _2B8-_2BC = PaniAnimKeyListener
	u32 _2BC;                          // _2BC, unknown
	u8 _2C0[0x4];                      // _2C0, unknown
	Vector3f _2C4;                     // _2C4, could just be floats
	u32 _2D0;                          // _2D0, unknown
	u32 _2D4;                          // _2D4, unknown
	f32 _2D8;                          // _2D8
	u8 _2DC[0x8];                      // _2DC, unknown
	AState<AICreature>* mCurrentState; // _2E4
	u8 _2E8[0x4];                      // _2E8, unknown
	int _2EC;                          // _2EC, unknown
	int mMaxEventCnt;                  // _2F0
	bool mEventFlags[16];              // _2F4
};

#endif
