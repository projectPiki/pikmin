#ifndef _FINALRESULTMODE_H
#define _FINALRESULTMODE_H

/**
 * .obj __vt__15FinalResultMode, weak
 * .4byte __RTTI__15FinalResultMode
 * .4byte 0
 * .4byte update__15FinalResultModeFP10Controller
 * .4byte draw__15FinalResultModeFR8Graphics
 */

/**
 * @brief TODO
 */
struct FinalResultMode {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C
};

#endif
