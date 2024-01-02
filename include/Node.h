#ifndef _NODE_H
#define _NODE_H

#include "types.h"
#include "CoreNode.h"

/**
 * @brief TODO
 */
struct Node : public CoreNode {
	virtual void update();                 // _10
	virtual void draw(struct Graphics&);   // _14
	virtual void render(Graphics&);        // _18
	virtual void concat();                 // _1C (weak)
	virtual void concat(struct VQS&);      // _20 (weak)
	virtual void concat(struct SRT&);      // _24 (weak)
	virtual void concat(struct Matrix4f&); // _28 (weak)
	virtual void getModelMatrix();         // _2C (weak)

	// _00 = VTBL
	// TODO: members
};

#endif
