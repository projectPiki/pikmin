#ifndef _FORMATIONMGR_H
#define _FORMATIONMGR_H

/**
 * .obj __vt__12FormationMgr, global
 * .4byte __RTTI__12FormationMgr
 * .4byte 0
 * .4byte getCreature__12FormationMgrFi
 * .4byte getFirst__12FormationMgrFv
 * .4byte getNext__12FormationMgrFi
 * .4byte isDone__12FormationMgrFi
 */

/**
 * @brief TODO
 */
struct FormationMgr {
	virtual void getCreature(int); // _08
	virtual void getFirst();       // _0C
	virtual void getNext(int);     // _10
	virtual void isDone(int);      // _14
};

#endif
