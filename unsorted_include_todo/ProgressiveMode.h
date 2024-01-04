#ifndef _PROGRESSIVEMODE_H
#define _PROGRESSIVEMODE_H

/**
 * .obj __vt__15ProgressiveMode, weak
 * .4byte __RTTI__15ProgressiveMode
 * .4byte 0
 * .4byte update__15ProgressiveModeFP10Controller
 * .4byte draw__15ProgressiveModeFR8Graphics
 */

/**
 * @brief TODO
 */
struct ProgressiveMode {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C
};

#endif
