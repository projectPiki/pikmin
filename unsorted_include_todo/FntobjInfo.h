#ifndef _FNTOBJINFO_H
#define _FNTOBJINFO_H

/**
 * .obj __vt__10FntobjInfo, weak
 * .4byte __RTTI__10FntobjInfo
 * .4byte 0
 * .4byte attach__10GfxobjInfoFv
 * .4byte detach__10GfxobjInfoFv
 */

struct GfxobjInfo {
	virtual void attach(); // _08
	virtual void detach(); // _0C
};

/**
 * @brief TODO
 */
struct FntobjInfo : public GfxobjInfo {
};

#endif
