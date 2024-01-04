#ifndef _ANIMATOR_H
#define _ANIMATOR_H

/**
 * .obj __vt__8Animator, global
 * .4byte __RTTI__8Animator
 * .4byte 0
 * .4byte changeContext__8AnimatorFP11AnimContext
 * .4byte animate__8AnimatorFf
 * .4byte finishOneShot__8AnimatorFv
 * .4byte finishLoop__8AnimatorFv
 */

/**
 * @brief TODO
 */
struct Animator {
	virtual void changeContext(AnimContext*); // _08
	virtual void animate(float);              // _0C
	virtual void finishOneShot();             // _10
	virtual void finishLoop();                // _14
};

#endif
