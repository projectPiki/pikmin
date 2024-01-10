#ifndef _MESH_H
#define _MESH_H

#include "types.h"
#include "CoreNode.h"

/**
 * @brief TODO
 */
struct Mesh : public CoreNode {
	Mesh();

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_14 = CoreNode
	// TODO: members
};

#endif
