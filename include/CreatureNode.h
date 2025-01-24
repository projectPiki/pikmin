#ifndef _CREATURENODE_H
#define _CREATURENODE_H

#include "types.h"
#include "ObjectMgr.h"

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct CreatureNode : public CoreNode {
	inline CreatureNode()
	    : CoreNode("cnode")
	{
		mCreature = nullptr;
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	Creature* mCreature; // _14
};

/**
 * @brief TODO.
 */
struct CreatureNodeMgr : public ObjectMgr {
	virtual Creature* getCreature(int);      // _08
	virtual int getFirst();                  // _0C
	virtual int getNext(int);                // _10
	virtual bool isDone(int);                // _14
	virtual ~CreatureNodeMgr() { }           // _48
	virtual int getSize();                   // _60
	virtual int getMax() { return 0x10000; } // _64

	// _00     = VTBL 1
	// _08     = VTBL 2
	// _00-_28 = ObjectMgr
	CreatureNode mRootNode; // _28
};

#endif
