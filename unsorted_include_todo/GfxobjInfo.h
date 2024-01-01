#ifndef _GFXOBJINFO_H
#define _GFXOBJINFO_H

/**
 * .obj __vt__10GfxobjInfo, weak
 * .4byte __RTTI__10GfxobjInfo
 * .4byte 0
 * .4byte attach__10GfxobjInfoFv
 * .4byte detach__10GfxobjInfoFv
*/

/**
 * @brief TODO
 */
struct GfxobjInfo {
	virtual void attach();  // _08
	virtual void detach();  // _0C

};

#endif
