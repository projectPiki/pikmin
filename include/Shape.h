#ifndef _SHAPE_H
#define _SHAPE_H

#include "types.h"
#include "Node.h"
#include "Stream.h"
#include "Colour.h"
#include "Material.h"
#include "Texture.h"
#include "Collision.h"
#include "Matrix4f.h"
#include "GfxObject.h"
#include "BoundBox.h"
#include "Joint.h"
#include "Animator.h"
#include "Light.h"
#include "Route.h"

template <typename A, typename B>
struct IDelegate2;

struct AnimContext;
struct CmdStream;
struct RouteGroup;
struct VtxMatrix;
struct Texture;
struct CollTriInfo;
struct BaseRoomInfo;
struct NBT;
struct DispList;
struct PVWTevInfo;
struct LFlareGroup;
struct AnimFrameCacher;
struct Joint;
struct Joint::MatPoly;

struct NBT {
	Vector3f mNormal;   // _00
	Vector3f mBinormal; // _0C
	Vector3f mTangent;  // _18

	inline void read(RandomAccessStream& stream)
	{
		mNormal.read(stream);
		mBinormal.read(stream);
		mTangent.read(stream);
	}
};

/**
 * @brief TODO
 */
struct VtxMatrix {
	void read(RandomAccessStream&);
	void write(RandomAccessStream&);

	bool mHasPartialWeights; // _00
	u32 mIndex;              // _04
};

/**
 * @brief TODO
 */
struct Envelope {
	Envelope();

	void read(RandomAccessStream& stream);

	s32 mIndexCount; // _00
	s32* mIndices;   // _04
	f32* mWeights;   // _08
};

/**
 * @brief TODO
 */
struct MtxGroup {
	MtxGroup();

	void read(RandomAccessStream&);

	int mDependencyLength; // _00
	int* mDependencyList;  // _04
	int mDispListLength;   // _08
	DispList* mDispList;   // _0C
};

/**
 * @brief TODO
 * @note Size: 0x10.
 */
struct ShapeDynMaterials {
	ShapeDynMaterials()
	    : mParent(0)
	    , _04(0)
	    , _08(0)
	    , _0C(0)
	{
	}

	void animate(f32*);
	void updateContext();

	ShapeDynMaterials* mParent; // _00
	u32 _04;                    // _04
	Material* _08;              // _08
	u32 _0C;                    // _0C
};

DEFINE_ENUM_TYPE(DisplayListFlags, Front = 0, Other = 1, Both = 2, Stripped = 0x1000000);

/**
 * @brief TODO
 */
struct DispList : public CoreNode {
	DispList();

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mFlags;         // _14
	int mDataLength;    // _18
	char* mData;        // _1C
	int _20;            // _20
	int mNodeCount;     // _24
	int mFaceCount;     // _28
	FaceNode mFaceNode; // _2C
};

/**
 * @brief TODO
 */
struct DlobjInfo : public GfxobjInfo {
	DlobjInfo();
};

// clang-format off
DEFINE_ENUM_TYPE(BaseShapeChunk,
	Header           = 0x00,
	Vertex           = 0x10,
	VertexNormal     = 0x11,
	VertexNBT        = 0x12,
	VertexColour     = 0x13,
	TexCoord0        = 0x18,
	TexCoord1        = 0x19,
	TexCoord2        = 0x1A,
	TexCoord3        = 0x1B,
	TexCoord4        = 0x1C,
	TexCoord5        = 0x1D,
	TexCoord6        = 0x1E,
	TexCoord7        = 0x1F,
	Texture          = 0x20,
	TextureAttribute = 0x22,
	Material         = 0x30,
	VertexMatrix     = 0x40,
	MatrixEnvelope   = 0x41,
	Mesh             = 0x50,
	Joint            = 0x60,
	JointName        = 0x61,
	CollisionPrism   = 0x100,
	CollisionGrid    = 0x110,
	EndOfFile        = 0xFFFF,
);
// clang-format on

/**
 * @brief TODO
 */
struct BaseShape : public CoreNode {
	BaseShape();

	virtual void read(RandomAccessStream&);   // _0C
	virtual void optimize() { }               // _10
	virtual void update() { }                 // _14
	virtual void render(struct Graphics&) { } // _18
	virtual void render2d(Graphics&) { }      // _1C
	virtual RouteGroup* makeRouteGroup();     // _20

	void importIni(RandomAccessStream&);
	void countMaterials(Joint*, u32);
	void recTraverseMaterials(Joint*, IDelegate2<Joint*, u32>*);
	ShapeDynMaterials* instanceMaterials(int);
	void makeInstance(struct ShapeDynMaterials&, int);
	void drawculled(Graphics&, struct Camera&, ShapeDynMaterials*);
	void drawshape(Graphics&, Camera&, ShapeDynMaterials*);
	void resolveTextureNames();
	void recAddMatpoly(Joint*, int);
	void initIni(bool);
	void initialise();
	void createCollisions(int);
	void calcBasePose(struct Matrix4f&);
	AnimData* loadDck(char*, RandomAccessStream&);
	AnimData* importDck(char*, CmdStream*);
	AnimData* loadDca(char*, RandomAccessStream&);
	AnimData* loadAnimation(char*, bool);
	struct Matrix4f& getAnimMatrix(int);
	void backupAnimOverrides(AnimContext**);
	void restoreAnimOverrides();
	void overrideAnim(int, AnimContext*);
	void updateAnim(Graphics&, Matrix4f&, f32*);
	void calcWeightedMatrices();
	void makeNormalIndexes(u16*);
	f32 calcJointWorldPos(Graphics&, int, struct Vector3f&);
	void calcJointWorldDir(Graphics&, int, Vector3f&);

	// unused/inlined:
	void exportIni(RandomAccessStream&, bool);
	void drawobjcolls(Graphics&, Camera&);
	void drawlights(Graphics&, Camera&);
	void drawroutes(Graphics&, Camera&);
	void skipChunk(RandomAccessStream&, u32);
	void importDca(char*, CmdStream*);
	void calcJointWorldScale(Graphics&, int, Vector3f&);
	CollTriInfo* findCollTri(Vector3f&, Vector3f&, Vector3f&, char*);

	// DLL inlines:
	CollGroup* getCollTris(Vector3f& pos)
	{
		int x = (pos.x - _140.mMin.x) / _158;
		int z = (pos.z - _140.mMin.z) / _158;
		if (x < 0 || z < 0 || x >= _15C || z >= _160) {
			return nullptr;
		}
		return _164[x + z * _15C];
	}
	void removeMtxDependancy();

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 mSystemFlags;                 // _14
	AnimContext* mCurrentAnimContext; // _18, current animation
	AnimContext** mAnimContextList;   // _1C
	u32 _20;                          // _20
	AnimFrameCacher* mFrameCacher;    // _24
	Matrix4f* mAnimMatrices;          // _28
	u32 mAnimMatrixId;                // _2C
	s32 mEnvelopeCount;               // _30
	Envelope* mEnvelopeList;          // _34
	s32 mVtxMatrixCount;              // _38
	VtxMatrix* mVtxMatrixList;        // _3C
	s32 mMaterialCount;               // _40
	Material* mMaterialList;          // _44
	s32 mTevInfoCount;                // _48
	PVWTevInfo* mTevInfoList;         // _4C
	s32 mMeshCount;                   // _50
	Mesh* mMeshList;                  // _54
	s32 mJointCount;                  // _58
	Joint* mJointList;                // _5C
	s32 mTotalMatpolyCount;           // _60
	Joint::MatPoly** mMatpolyList;    // _64
	s32 mTexAttrCount;                // _68
	TexAttr* mTexAttrList;            // _6C
	s32 _70;                          // _70
	s32 mTextureCount;                // _74
	TexImg* mTextureList;             // _78
	LightGroup mLightGroup;           // _7C
	ObjCollInfo mCollisionInfo;       // _E8
	u32 _13C;                         // _13C, flag of some kind?
	BoundBox _140;                    // _140
	f32 _158;                         // _158
	int _15C;                         // _15C
	int _160;                         // _160
	CollGroup** _164;                 // _164
	int mTriCount;                    // _168
	CollTriInfo* mTriList;            // _16C
	u32 _170;                         // _170
	u32 _174;                         // _174
	RouteGroup mRouteGroup;           // _178
	s32 mVertexCount;                 // _238 - from here down might match the names/types from _27C on from the DLL?
	Vector3f* mVertexList;            // _23C
	u32 mNbtCount;                    // _240
	NBT* mNbtList;                    // _244
	s32 mTotalActiveTexCoords;        // _248
	s32 mTexCoordCounts[8];           // _24C
	Vector2f* mTexCoordList[8];       // _250
	s32 mNormalCount;                 // _28C
	Vector3f* mNormalList;            // _290
	u8 _294[0x4];                     // _294
	u32 _298;                         // _298
	u32 _29C;                         // _29C
	Texture* _2A0;                    // _2A0
	u32 _2A4;                         // _2A4
	u32 _2A8;                         // _2A8
	u8 _2AC;                          // _2AC
};

/**
 * @brief TODO
 *
 * @note Size: 0x2B0.
 */
struct Shape : public BaseShape {
	Shape();

	virtual void optimize(); // _10

	// _00      = VTBL
	// _00-_2B0 = BaseShape
};

/**
 * @brief TODO
 *
 * @note Size: 0x18.
 */
struct CachedShape {
	CachedShape() { mPrev = mNext = this; }

	inline void insertAfter(CachedShape* other)
	{
		other->mNext = mNext;
		other->mPrev = this;

		mNext->mPrev = other;
		mNext        = other;
	}

	CachedShape* mPrev;               // _00
	CachedShape* mNext;               // _04
	ShapeDynMaterials* mDynMaterials; // _08
	Shape* mParentShape;              // _0C
	Matrix4f* mAnimMatrices;          // _10
	f32 mDistanceFromOrigin;          // _14
};

#endif
