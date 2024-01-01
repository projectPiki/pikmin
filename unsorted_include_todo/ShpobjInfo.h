#ifndef _SHPOBJINFO_H
#define _SHPOBJINFO_H

/**
 * .obj __vt__10ShpobjInfo, weak
 * .4byte __RTTI__10ShpobjInfo
 * .4byte 0
 * .4byte attach__10GfxobjInfoFv
 * .4byte detach__10GfxobjInfoFv
*/

struct GfxobjInfo {
	virtual void attach();  // _08
	virtual void detach();  // _0C
};

/**
 * @brief TODO
 */
struct ShpobjInfo : public GfxobjInfo {

};

#endif
