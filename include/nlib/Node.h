#ifndef _NLIB_NODE_H
#define _NLIB_NODE_H

#include "nlib/Array.h"
#include "types.h"

/**
 * @brief TODO
 */
class NNode {
public:
	NNode(int);

	virtual void setChild(int, NNode*); // _08
	virtual void addChild(NNode*);      // _0C
	virtual void addChild(int, NNode*); // _10
	virtual void removeChild(NNode*);   // _14
	virtual void removeChild(int);      // _18
	virtual void removeAllChildren();   // _1C

	NNode* getChild(int);

	// DLL inline:
	int getChildCount()
	{
		if (!mNodeArray) {
			return 0;
		}
		return mNodeArray->getSize();
	}

	// _00 = VTBL
	NArray<NNode>* mNodeArray; // _04
};

/**
 * @brief TODO
 */
class NListNode {
public:
	NListNode(); // unused/inlined

	// unused/inlined:
	void addChild(NListNode*);
	void removeChild(NListNode*);
	int getChildCount();
	void addChild(int, NListNode*);
	void toString();

	NListNode* _00; // _00
	NListNode* _04; // _04
};

/**
 * @brief TODO
 */
class NList {
public:
	NList(); // unused/inlined

	// unused/inlined:
	void addList(NList*);
	void toString();

	NList* _00; // _00
};

#endif
