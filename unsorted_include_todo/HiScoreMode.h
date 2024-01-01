#ifndef _HISCOREMODE_H
#define _HISCOREMODE_H

/**
 * .obj __vt__11HiScoreMode, weak
 * .4byte __RTTI__11HiScoreMode
 * .4byte 0
 * .4byte update__11HiScoreModeFP10Controller
 * .4byte draw__11HiScoreModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct HiScoreMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
