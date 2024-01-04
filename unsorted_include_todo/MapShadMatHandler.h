#ifndef _MAPSHADMATHANDLER_H
#define _MAPSHADMATHANDLER_H

/**
 * .obj __vt__17MapShadMatHandler, weak
 * .4byte __RTTI__17MapShadMatHandler
 * .4byte 0
 * .4byte setMaterial__17MapShadMatHandlerFP8Material
 * .4byte setTexMatrix__15MaterialHandlerFb
 */

struct MaterialHandler {
	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C
};

/**
 * @brief TODO
 */
struct MapShadMatHandler : public MaterialHandler {
	virtual void setMaterial(Material*); // _08
};

#endif
