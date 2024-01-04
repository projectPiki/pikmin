#ifndef _INFMGR_H
#define _INFMGR_H

/**
 * .obj __vt__6InfMgr, weak
 * .4byte __RTTI__6InfMgr
 * .4byte 0
 * .4byte init__6InfMgrFi
 * .4byte 0
 * .4byte 0
 * .4byte 0
 * .4byte 0
 */

/**
 * @brief TODO
 */
struct InfMgr {
	virtual void init(int); // _08
	virtual void _0C() = 0; // _0C
	virtual void _10() = 0; // _10
	virtual void _14() = 0; // _14
	virtual void _18() = 0; // _18
};

#endif
