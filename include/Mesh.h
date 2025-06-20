#ifndef _MESH_H
#define _MESH_H

#include "types.h"
#include "CoreNode.h"

struct MtxGroup;

/**
 * @brief TODO
 */
struct Mesh : public CoreNode {
	Mesh()
	    : CoreNode("mesh")
	{
		mJointList        = nullptr;
		mParentJoint      = -1;
		mVertexDescriptor = 1;
	}

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mMeshIndex;          // _14
	int mParentJoint;        // _18
	int mMtxDepIdx;          // _1C, matrix dependency index (index into MtxGroup)
	int mMtxGroupCount;      // _20
	MtxGroup* mMtxGroupList; // _24
	Joint* mJointList;       // _28
	int mVertexDescriptor;   // _2C
};

#endif
