#ifndef _CLOTHFADER_H
#define _CLOTHFADER_H

/**
 * .obj __vt__10ClothFader, weak
 * .4byte __RTTI__10ClothFader
 * .4byte 0
 * .4byte initFadeIn__10ClothFaderFv
 * .4byte updateFadeIn__10ClothFaderFv
 * .4byte drawFadeIn__10ClothFaderFR8Graphics
 * .4byte initFadeOut__10ClothFaderFv
 * .4byte updateFadeOut__10ClothFaderFv
 * .4byte drawFadeOut__10ClothFaderFR8Graphics
 */

/**
 * @brief TODO
 */
struct ClothFader {
	virtual void initFadeIn();           // _08
	virtual void updateFadeIn();         // _0C
	virtual void drawFadeIn(Graphics&);  // _10
	virtual void initFadeOut();          // _14
	virtual void updateFadeOut();        // _18
	virtual void drawFadeOut(Graphics&); // _1C
};

#endif
