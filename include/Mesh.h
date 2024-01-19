#ifndef _MESH_H
#define _MESH_H

#include "types.h"
#include "CoreNode.h"

struct MtxGroup;

/**
 * @brief TODO
 */
struct Mesh : public CoreNode {
	Mesh();

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_14 = CoreNode
	int _14;                 // _14
	int _18;                 // _18
	int _1C;                 // _1C
	int _20;                 // _20
	MtxGroup* mMtxGroupList; // _24
	int _28;                 // _28
	int _2C;                 // _2C
};

#endif
