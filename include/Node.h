#ifndef _NODE_H
#define _NODE_H

#include "types.h"
#include "CoreNode.h"

/**
 * @brief TODO
 */
struct Node : public CoreNode {
	Node(char* name);

	Node()
	    : CoreNode("<Node>")
	{
		init("<Node>");
	}

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
	// TODO: Why does it fail if i add these members back?
	// s32 mType;  // _14
	// s32 mFlags; // _18
	// s32 _1C; // _1C
};

struct FaceNode : public CoreNode {
	inline FaceNode()
	    : CoreNode("face")
	{
	}
	inline FaceNode(int) { }

	// _00     = VTBL
	// _00-_14 = CoreNode
	int _14; // _14
	int _18; // _18
	int _1C; // _1C
	int _20; // _20
	int _24; // _24
	int _28; // _28
	int _2C; // _2C
	int _30; // _30
	int _34; // _34
	int _38; // _38
	int _3C; // _3C
	int _40; // _40
	int _44; // _44
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
