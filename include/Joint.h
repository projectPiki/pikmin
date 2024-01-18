#ifndef _JOINT_H
#define _JOINT_H

#include "types.h"
#include "CoreNode.h"

struct AnimContext;

/**
 * @brief TODO
 */
struct Joint : public CoreNode {
	Joint();

	virtual void read(RandomAccessStream&); // _0C

	void recOverrideAnim(AnimContext*);

	// unused/inlined:
	void recShowHierarchy();
	void overrideAnim(AnimContext*);
	void render(struct Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	int _14;    // _14
	int mIndex; // _18
	u8 _1C[0x100];
};

#endif
