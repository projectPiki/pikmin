#ifndef _GFXOBJECT_H
#define _GFXOBJECT_H

/**
 * .obj __vt__9GfxObject, weak
 * .4byte __RTTI__9GfxObject
 * .4byte 0
 * .4byte attach__9GfxObjectFv
 * .4byte detach__9GfxObjectFv
 */

/**
 * @brief TODO
 */
struct GfxObject {
	virtual void attach(); // _08
	virtual void detach(); // _0C
};

#endif
