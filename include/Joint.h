#ifndef _JOINT_H
#define _JOINT_H

#include "types.h"
#include "CoreNode.h"
#include "Vector3f.h"
#include "Matrix4f.h"
#include "BoundBox.h"

struct AnimContext;
struct Material;
struct BaseShape;
struct Mesh;

/**
 * @brief TODO
 */
struct Joint : public CoreNode {
	struct MatPoly : public CoreNode {
		MatPoly()
		    : CoreNode("matpoly")
		{
		}

		MatPoly(Material* mat, Mesh* mesh)
		    : CoreNode("matpoly")
		{
			mMaterial = mat;
			mMesh     = mesh;
			_24       = 0;
		}

		Material* mMaterial; // _14
		Mesh* mMesh;         // _18
		int mIndex;          // _1C
		int _20;             // _20
		int _24;             // _24
	};

	Joint();

	virtual void read(RandomAccessStream&); // _0C

	void recOverrideAnim(AnimContext*);

	// unused/inlined:
	void recShowHierarchy();
	void overrideAnim(AnimContext*);
	void render(struct Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mIndex;              // _14
	int mParentIndex;        // _18
	int mType;               // _1C
	int mFlags;              // _20
	Vector3f mScale;         // _24
	Vector3f mRotation;      // _30
	Vector3f mTranslation;   // _3C
	Matrix4f mAnimMatrix;    // _48
	Matrix4f _88;            // _88
	u8 _C8;                  // _C8
	BoundBox mBounds;        // _CC
	MatPoly mMatPoly;        // _E4
	int _10C;                // _10C
	int mMatPolyCount;       // _110
	int _114;                // _114
	BaseShape* mParentShape; // _118
};

#endif
