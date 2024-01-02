#ifndef _CORENODE_H
#define _CORENODE_H

#include "types.h"
#include "ANode.h"

/**
 * @brief TODO
 */
struct CoreNode : public ANode {
	virtual void read(struct RandomAccessStream&); // _0C (weak)

	// _00 = VTBL
	// TODO: members
};

#endif
