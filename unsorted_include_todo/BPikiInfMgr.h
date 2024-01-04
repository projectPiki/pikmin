#ifndef _BPIKIINFMGR_H
#define _BPIKIINFMGR_H

/**
 * .obj __vt__11BPikiInfMgr, global
 * .4byte __RTTI__11BPikiInfMgr
 * .4byte 0
 * .4byte init__10MonoInfMgrFi
 * .4byte getFreeInf__10MonoInfMgrFv
 * .4byte delInf__10MonoInfMgrFP7BaseInf
 * .4byte getFreeNum__10MonoInfMgrFv
 * .4byte getActiveNum__10MonoInfMgrFv
 * .4byte newInf__11BPikiInfMgrFv
 */

struct MonoInfMgr {
	virtual void init(int);        // _08
	virtual void getFreeInf();     // _0C
	virtual void delInf(BaseInf*); // _10
	virtual void getFreeNum();     // _14
	virtual void getActiveNum();   // _18
};

/**
 * @brief TODO
 */
struct BPikiInfMgr : public MonoInfMgr {
	virtual void newInf(); // _1C
};

#endif
