#ifndef _MATERIALHANDLER_H
#define _MATERIALHANDLER_H

/**
 * .obj __vt__15MaterialHandler, global
 * .4byte __RTTI__15MaterialHandler
 * .4byte 0
 * .4byte setMaterial__15MaterialHandlerFP8Material
 * .4byte setTexMatrix__15MaterialHandlerFb
 */

/**
 * @brief TODO
 */
struct MaterialHandler {
	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C
};

#endif
