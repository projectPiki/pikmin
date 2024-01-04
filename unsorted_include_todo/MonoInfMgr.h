#ifndef _MONOINFMGR_H
#define _MONOINFMGR_H

/**
 * .obj __vt__10MonoInfMgr, global
 * .4byte __RTTI__10MonoInfMgr
 * .4byte 0
 * .4byte init__10MonoInfMgrFi
 * .4byte getFreeInf__10MonoInfMgrFv
 * .4byte delInf__10MonoInfMgrFP7BaseInf
 * .4byte getFreeNum__10MonoInfMgrFv
 * .4byte getActiveNum__10MonoInfMgrFv
 * .4byte 0
 */

/**
 * @brief TODO
 */
struct MonoInfMgr {
	virtual void init(int);        // _08
	virtual void getFreeInf();     // _0C
	virtual void delInf(BaseInf*); // _10
	virtual void getFreeNum();     // _14
	virtual void getActiveNum();   // _18
	virtual void _1C() = 0;        // _1C
};

#endif
