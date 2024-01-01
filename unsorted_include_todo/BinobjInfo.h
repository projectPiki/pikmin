#ifndef _BINOBJINFO_H
#define _BINOBJINFO_H

/**
 * .obj __vt__10BinobjInfo, weak
 * .4byte __RTTI__10BinobjInfo
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
struct BinobjInfo : public GfxobjInfo {

};

#endif
