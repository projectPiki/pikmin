#ifndef _SAVEMESMODE_H
#define _SAVEMESMODE_H

/**
 * .obj __vt__11SaveMesMode, weak
 * .4byte __RTTI__11SaveMesMode
 * .4byte 0
 * .4byte update__11SaveMesModeFP10Controller
 * .4byte draw__11SaveMesModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct SaveMesMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
