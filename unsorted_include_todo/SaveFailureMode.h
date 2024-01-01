#ifndef _SAVEFAILUREMODE_H
#define _SAVEFAILUREMODE_H

/**
 * .obj __vt__15SaveFailureMode, weak
 * .4byte __RTTI__15SaveFailureMode
 * .4byte 0
 * .4byte update__15SaveFailureModeFP10Controller
 * .4byte draw__15SaveFailureModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct SaveFailureMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
