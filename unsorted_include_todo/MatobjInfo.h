#ifndef _MATOBJINFO_H
#define _MATOBJINFO_H

/**
 * .obj __vt__10MatobjInfo, weak
 * .4byte __RTTI__10MatobjInfo
 * .4byte 0
 * .4byte attach__10MatobjInfoFv
 * .4byte detach__10MatobjInfoFv
 */

/**
 * @brief TODO
 */
struct MatobjInfo {
	virtual void attach(); // _08
	virtual void detach(); // _0C
};

#endif
