#ifndef _PANIITEMANIMATOR_H
#define _PANIITEMANIMATOR_H

/**
 * .obj __vt__16PaniItemAnimator, weak
 * .4byte __RTTI__16PaniItemAnimator
 * .4byte 0
 * .4byte changeContext__12PaniAnimatorFP11AnimContext
 * .4byte animate__12PaniAnimatorFf
 * .4byte finishOneShot__8AnimatorFv
 * .4byte finishLoop__8AnimatorFv
 * .4byte updateContext__12PaniAnimatorFv
 */

struct PaniAnimator {
	virtual void changeContext(AnimContext*); // _08
	virtual void animate(float);              // _0C
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
struct PaniItemAnimator : public PaniAnimator, public Animator {

	void createMotionTable();
	PaniItemAnimator();
};

#endif
