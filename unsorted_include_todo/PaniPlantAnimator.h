#ifndef _PANIPLANTANIMATOR_H
#define _PANIPLANTANIMATOR_H

/**
 * .obj __vt__17PaniPlantAnimator, weak
 * .4byte __RTTI__17PaniPlantAnimator
 * .4byte 0
 * .4byte changeContext__12PaniAnimatorFP11AnimContext
 * .4byte animate__12PaniAnimatorFf
 * .4byte finishOneShot__8AnimatorFv
 * .4byte finishLoop__8AnimatorFv
 * .4byte updateContext__12PaniAnimatorFv
 */

struct PaniAnimator {
	virtual void changeContext(AnimContext*); // _08
	virtual void animate(f32);                // _0C
	virtual void _10() = 0;                   // _10
	virtual void _14() = 0;                   // _14
	virtual void updateContext();             // _18
};

struct Animator {
	virtual void _08() = 0;       // _08
	virtual void _0C() = 0;       // _0C
	virtual void finishOneShot(); // _10
	virtual void finishLoop();    // _14
};

/**
 * @brief TODO
 */
struct PaniPlantAnimator : public PaniAnimator, public Animator { };

#endif
