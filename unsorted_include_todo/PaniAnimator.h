#ifndef _PANIANIMATOR_H
#define _PANIANIMATOR_H

/**
 * .obj __vt__12PaniAnimator, global
 * .4byte __RTTI__12PaniAnimator
 * .4byte 0
 * .4byte changeContext__12PaniAnimatorFP11AnimContext
 * .4byte animate__12PaniAnimatorFf
 * .4byte finishOneShot__8AnimatorFv
 * .4byte finishLoop__8AnimatorFv
 * .4byte updateContext__12PaniAnimatorFv
 */

struct Animator {
	virtual void changeContext(AnimContext*); // _08
	virtual void animate(float);              // _0C
	virtual void finishOneShot();             // _10
	virtual void finishLoop();                // _14
};

/**
 * @brief TODO
 */
struct PaniAnimator : public Animator {
	virtual void changeContext(AnimContext*); // _08
	virtual void animate(float);              // _0C
	virtual void updateContext();             // _18
};

#endif
