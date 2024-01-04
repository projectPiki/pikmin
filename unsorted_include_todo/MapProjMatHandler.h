#ifndef _MAPPROJMATHANDLER_H
#define _MAPPROJMATHANDLER_H

/**
 * .obj __vt__17MapProjMatHandler, weak
 * .4byte __RTTI__17MapProjMatHandler
 * .4byte 0
 * .4byte setMaterial__17MapProjMatHandlerFP8Material
 * .4byte setTexMatrix__17MapProjMatHandlerFb
 */

/**
 * @brief TODO
 */
struct MapProjMatHandler {
	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C
};

#endif
