#ifndef _CMRESULTMODE_H
#define _CMRESULTMODE_H

/**
 * .obj __vt__12CMresultMode, weak
 * .4byte __RTTI__12CMresultMode
 * .4byte 0
 * .4byte update__12CMresultModeFP10Controller
 * .4byte draw__12CMresultModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct CMresultMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
