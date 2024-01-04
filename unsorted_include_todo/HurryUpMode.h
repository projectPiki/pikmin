#ifndef _HURRYUPMODE_H
#define _HURRYUPMODE_H

/**
 * .obj __vt__11HurryUpMode, weak
 * .4byte __RTTI__11HurryUpMode
 * .4byte 0
 * .4byte update__11HurryUpModeFP10Controller
 * .4byte draw__11HurryUpModeFR8Graphics
 */

/**
 * @brief TODO
 */
struct HurryUpMode {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C
};

#endif
