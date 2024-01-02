#ifndef _PANIANIMATOR_H
#define _PANIANIMATOR_H

#include "types.h"
#include "Animator.h"

struct PaniMotionTable;

/**
 * @brief TODO
 */
struct PaniAnimKeyEvent {
};

/**
 * @brief TODO
 */
struct PaniAnimKeyListener {

	virtual void animationKeyUpdated(PaniAnimKeyEvent&) = 0; // _08

	// _00 = VTBL
	// TODO: members
};

/**
 * @brief TODO
 */
struct PaniAnimator : public Animator {
	PaniAnimator();

	virtual void changeContext(AnimContext*); // _08
	virtual void animate(f32);                // _0C
	virtual void updateContext();             // _18

	void init(AnimContext*, AnimMgr*, PaniMotionTable*);

	// _30     = VTBL
	// _00-_34 = Animator
};

#endif
