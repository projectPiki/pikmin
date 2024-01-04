#ifndef _SIMPLEFADER_H
#define _SIMPLEFADER_H

/**
 * .obj __vt__11SimpleFader, weak
 * .4byte __RTTI__11SimpleFader
 * .4byte 0
 * .4byte initFadeIn__11SimpleFaderFv
 * .4byte updateFadeIn__11SimpleFaderFv
 * .4byte drawFadeIn__11SimpleFaderFR8Graphics
 * .4byte initFadeOut__11SimpleFaderFv
 * .4byte updateFadeOut__11SimpleFaderFv
 * .4byte drawFadeOut__11SimpleFaderFR8Graphics
 */

/**
 * @brief TODO
 */
struct SimpleFader {
	virtual void initFadeIn();           // _08
	virtual void updateFadeIn();         // _0C
	virtual void drawFadeIn(Graphics&);  // _10
	virtual void initFadeOut();          // _14
	virtual void updateFadeOut();        // _18
	virtual void drawFadeOut(Graphics&); // _1C
};

#endif
