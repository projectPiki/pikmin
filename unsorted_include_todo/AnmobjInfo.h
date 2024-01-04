#ifndef _ANMOBJINFO_H
#define _ANMOBJINFO_H

/**
 * .obj __vt__10AnmobjInfo, global
 * .4byte __RTTI__10AnmobjInfo
 * .4byte 0
 * .4byte attach__10GfxobjInfoFv
 * .4byte detach__10AnmobjInfoFv
 */

struct GfxobjInfo {
	virtual void attach(); // _08
};

/**
 * @brief TODO
 */
struct AnmobjInfo : public GfxobjInfo {
	virtual void detach(); // _0C
};

#endif
