#ifndef _DEFAULTFADER_H
#define _DEFAULTFADER_H

/**
 * .obj __vt__12DefaultFader, weak
 * .4byte __RTTI__12DefaultFader
 * .4byte 0
 * .4byte initFadeIn__12DefaultFaderFv
 * .4byte updateFadeIn__12DefaultFaderFv
 * .4byte drawFadeIn__12DefaultFaderFR8Graphics
 * .4byte initFadeOut__12DefaultFaderFv
 * .4byte updateFadeOut__12DefaultFaderFv
 * .4byte drawFadeOut__12DefaultFaderFR8Graphics
 */

/**
 * @brief TODO
 */
struct DefaultFader {
	virtual void initFadeIn();           // _08
	virtual void updateFadeIn();         // _0C
	virtual void drawFadeIn(Graphics&);  // _10
	virtual void initFadeOut();          // _14
	virtual void updateFadeOut();        // _18
	virtual void drawFadeOut(Graphics&); // _1C
};

#endif
