#ifndef _WORLDMAPMODE_H
#define _WORLDMAPMODE_H

/**
 * .obj __vt__12WorldMapMode, weak
 * .4byte __RTTI__12WorldMapMode
 * .4byte 0
 * .4byte update__12WorldMapModeFP10Controller
 * .4byte draw__12WorldMapModeFR8Graphics
 */

/**
 * @brief TODO
 */
struct WorldMapMode {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C
};

#endif
