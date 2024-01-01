#ifndef _UFOPARTSMODE_H
#define _UFOPARTSMODE_H

/**
 * .obj __vt__12UfoPartsMode, weak
 * .4byte __RTTI__12UfoPartsMode
 * .4byte 0
 * .4byte update__12UfoPartsModeFP10Controller
 * .4byte draw__12UfoPartsModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct UfoPartsMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
