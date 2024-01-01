#ifndef _WMPAUSEMODE_H
#define _WMPAUSEMODE_H

/**
 * .obj __vt__11WMPauseMode, weak
 * .4byte __RTTI__11WMPauseMode
 * .4byte 0
 * .4byte update__11WMPauseModeFP10Controller
 * .4byte draw__11WMPauseModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct WMPauseMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
