#ifndef _NLIB_NODE_H
#define _NLIB_NODE_H

#include "types.h"
#include "nlib/Array.h"

/**
 * @brief TODO
 */
struct NNode {
	NNode(int);

	virtual void setChild(int, NNode*); // _08
	virtual void addChild(NNode*);      // _0C
	virtual void addChild(int, NNode*); // _10
	virtual void removeChild(NNode*);   // _14
	virtual void removeChild(int);      // _18
	virtual void removeAllChildren();   // _1C

	void getChild(int);

	// _00 = VTBL
	NArray<NNode>* mNodeArray; // _04
};

/**
 * @brief TODO
 */
struct NListNode {
	NListNode(); // unused/inlined

	// unused/inlined:
	void addChild(NListNode*);
	void removeChild(NListNode*);
	void getChildCount();
	void addChild(int, NListNode*);
	void toString();

	// TODO: members
};

/**
 * @brief TODO
 */
struct NList {
	NList(); // unused/inlined

	// unused/inlined:
	void addList(NList*);
	void toString();

	// TODO: members
};

#endif
