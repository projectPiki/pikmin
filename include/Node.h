#ifndef _NODE_H
#define _NODE_H

#include "types.h"
#include "CoreNode.h"

/**
 * @brief TODO
 */
struct Node : public CoreNode {
	Node(char* name);

	virtual void update();                 // _10
	virtual void draw(struct Graphics&);   // _14
	virtual void render(Graphics&);        // _18
	virtual void concat();                 // _1C (weak)
	virtual void concat(struct VQS&);      // _20 (weak)
	virtual void concat(struct SRT&);      // _24 (weak)
	virtual void concat(struct Matrix4f&); // _28 (weak)
	virtual void getModelMatrix();         // _2C (weak)

	void init(char*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

/**
 * @brief TODO
 */
struct NodeMgr {
	NodeMgr();

	u8 _00[0x18]; // _00, unknown
};

extern NodeMgr* nodeMgr;

#endif
