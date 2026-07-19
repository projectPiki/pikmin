#ifndef _JOINT_H
#define _JOINT_H

#include "BoundBox.h"
#include "CoreNode.h"
#include "Matrix4f.h"
#include "Vector.h"
#include "types.h"

class AnimContext;
class Material;
class BaseShape;
class Graphics;
class Mesh;
class Joint;

/**
 * @brief TODO
 */
class Joint : public CoreNode {
public:
	enum VisibilityFlags {
		NotVisible = 0,
		Visible    = 1,
	};

	class MatPoly : public CoreNode {
	public:
		MatPoly()
		    : CoreNode("matpoly")
		{
			mJointList = 0;
		}

		MatPoly(Material* mat, Mesh* mesh)
		    : CoreNode("matpoly")
		{
			mMaterial  = mat;
			mMesh      = mesh;
			mJointList = 0;
		}

		// CoreNode _00 - _14
		Material* mMaterial; // _14
		Mesh* mMesh;         // _18
		int mIndex;          // _1C
		int mMeshIndex;      // _20
		Joint* mJointList;   // _24
	};

	Joint()
	    : CoreNode(nullptr)
	{
		mVisibilityFlag = Visible;
		_10C            = 0;
	}

	virtual void read(RandomAccessStream&); // _0C
#if defined(WIN32)
	virtual void write(RandomAccessStream&);
#endif

	void recOverrideAnim(AnimContext*);

	// unused/inlined:
	void recShowHierarchy();
	void overrideAnim(AnimContext*);
	void render(Graphics&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mIndex;                  // _14
	int mParentIndex;            // _18
	int mType;                   // _1C
	int mVisibilityFlag;         // _20, see `VisibilityFlags` emum.
	Vector3f mScale;             // _24, surprisingly NOT part of an `SRT`
	Vector3f mRotation;          // _30, surprisingly NOT part of an `SRT`
	Vector3f mTranslation;       // _3C, surprisingly NOT part of an `SRT`
	Matrix4f mAnimMatrix;        // _48
	Matrix4f mInverseAnimMatrix; // _88
	bool mIsBillboard;           // _C8
	bool mUseVolume;             // _C9
	bool mUseLightGroup;         // _CA
	BoundBox mBounds;            // _CC
	MatPoly mMatPoly;            // _E4
	int _10C;                    // _10C
	int mMatPolyCount;           // _110
	int mCullIndex;              // _114
	BaseShape* mParentShape;     // _118
};

#endif
