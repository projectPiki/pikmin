#ifndef _MESH_H
#define _MESH_H

#include "CoreNode.h"
#include "types.h"

class MtxGroup;

/**
 * @brief TODO
 */
class Mesh : public CoreNode {
public:
	BEGIN_ENUM_TYPE(FeatureFlags)
	enum {
		PosAndNrm  = (1 << 0),  // Vertex position and normals (all models should have this)
		Tex1MtxIdx = (1 << 1),  // IDK what this does.  Is it for textures that shift when viewed at different angles?
		VtxColor   = (1 << 2),  // Vertex colors
		Tex0       = (1 << 3),  // Texture coordinates 0
		Tex1       = (1 << 4),  // Texture coordinates 1
		Tex2       = (1 << 5),  // Texture coordinates 2
		Tex3       = (1 << 6),  // Texture coordinates 3
		Tex4       = (1 << 7),  // Texture coordinates 4
		Tex5       = (1 << 8),  // Texture coordinates 5
		Tex6       = (1 << 9),  // Texture coordinates 6
		Tex7       = (1 << 10), // Texture coordinates 7
		VtxNBT     = (1 << 16), // Vertex normal, binormal, and tangent vectors (replaces typical vertex normals)
	} END_ENUM_TYPE;

	Mesh()
	    : CoreNode("mesh")
	{
		mJointList    = nullptr;
		mParentJoint  = -1;
		mFeatureFlags = FeatureFlags::PosAndNrm;
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
	int mFeatureFlags;       // _2C, aka vertex descriptors
};

#endif
