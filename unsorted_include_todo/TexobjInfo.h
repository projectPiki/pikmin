#ifndef _TEXOBJINFO_H
#define _TEXOBJINFO_H

/**
 * .obj __vt__10TexobjInfo, weak
 * .4byte __RTTI__10TexobjInfo
 * .4byte 0
 * .4byte attach__10TexobjInfoFv
 * .4byte detach__10TexobjInfoFv
 */

/**
 * @brief TODO
 */
struct TexobjInfo {
	virtual void attach(); // _08
	virtual void detach(); // _0C
};

#endif
