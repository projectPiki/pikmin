#ifndef _MAPOBJANIMATOR_H
#define _MAPOBJANIMATOR_H

/**
 * .obj __vt__14MapObjAnimator, global
 * .4byte __RTTI__14MapObjAnimator
 * .4byte 0
 * .4byte changeContext__8AnimatorFP11AnimContext
 * .4byte animate__8AnimatorFf
 * .4byte finishOneShot__14MapObjAnimatorFv
 * .4byte finishLoop__8AnimatorFv
 */

struct Animator {
	virtual void changeContext(AnimContext*); // _08
	virtual void animate(f32);                // _0C
	virtual void finishOneShot();             // _10
	virtual void finishLoop();                // _14
};

/**
 * @brief TODO
 */
struct MapObjAnimator : public Animator {
	virtual void finishOneShot(); // _10
};

#endif
