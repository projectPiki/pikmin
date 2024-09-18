#ifndef _CREATURENODE_H
#define _CREATURENODE_H

#include "types.h"
#include "ObjectMgr.h"

/**
 * @brief TODO.
 */
struct CreatureNode : public CoreNode {

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO.
 */
struct CreatureNodeMgr : public ObjectMgr {
	virtual Creature* getCreature(int); // _08
	virtual int getFirst();             // _0C
	virtual int getNext(int);           // _10
	virtual bool isDone(int);           // _14
	virtual ~CreatureNodeMgr();         // _48
	virtual int getSize();              // _60
	virtual int getMax();               // _64

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = ObjectMgr
	// TODO: members
};

#endif
