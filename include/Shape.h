#ifndef _SHAPE_H
#define _SHAPE_H

#include "Animator.h"
#include "BoundBox.h"
#include "Collision.h"
#include "Colour.h"
#include "GfxObject.h"
#include "Joint.h"
#include "Light.h"
#include "Material.h"
#include "Matrix4f.h"
#include "Node.h"
#include "Route.h"
#include "Stream.h"
#include "Texture.h"
#include "types.h"

template <typename A, typename B>
struct IDelegate2;

struct AnimContext;
struct AnimFrameCacher;
struct Camera;
struct CollTriInfo;
struct CmdStream;
struct DispList;
struct Graphics;
struct Joint;
struct LFlareGroup;
struct NBT;
struct PVWTevInfo;
struct RouteGroup;
struct Texture;
struct VtxMatrix;

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
	void read(RandomAccessStream& input)
	{
		int weights        = input.readShort();
		mHasPartialWeights = (weights >= 0) ? true : false;
		if (mHasPartialWeights) {
			mIndex = weights;
		} else {
			mIndex = -1 - weights;
		}
	}

	void write(RandomAccessStream&);

	bool mHasPartialWeights; // _00
	u32 mIndex;              // _04
};

/**
 * @brief TODO
 */
struct Envelope {
	Envelope()
	{
		mIndexCount   = 0;
		mJointIndices = nullptr;
		mWeights      = nullptr;
	}

	void read(RandomAccessStream& stream);

	s32 mIndexCount;    // _00
	s32* mJointIndices; // _04
	f32* mWeights;      // _08
};

/**
 * @brief TODO
 */
struct MtxGroup {
	MtxGroup()
	{
		mDepLength  = 0;
		mDispLength = 0;
		mDispList   = 0;
	}

	void read(RandomAccessStream&);

	int mDepLength;      // _00
	int* mDepList;       // _04
	int mDispLength;     // _08
	DispList* mDispList; // _0C
};

/**
 * @brief Container for the set of materials for a model instance, allowing for per-object animation and modification.
 *
 * @note Size: 0x10.
 */
struct ShapeDynMaterials {

	/// Constructs an empty animated material container with no connections.
	ShapeDynMaterials()
	    : mNext(nullptr)
	    , mMatCount(0)
	    , mMaterials(nullptr)
	    , mModel(nullptr)
	{
	}

	void animate(f32*);
	void updateContext();

	ShapeDynMaterials* mNext; ///< _00, next `ShapeDynMaterials` in the (singly-linked) list, if any.
	int mMatCount;            ///< _04, number of materials in container.
	Material* mMaterials;     ///< _08, array of `mMatCount` materials.
	BaseShape* mModel;        ///< _0C, model the materials are attached to.
};

BEGIN_ENUM_TYPE(DisplayListFlags)
enum {
	Front    = 0,         //
	Other    = 1,         //
	Both     = 2,         //
	Stripped = 0x1000000, //
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct DispList : public CoreNode {
	DispList()
	{
		mFaceNode.initCore("");

		mNodeCount = 0;
		mFaceCount = 0;
		mFlags     = 0;
		_20        = -1;
	}

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mFlags;         // _14
	int mDataLength;    // _18
	u8* mData;          // _1C
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

BEGIN_ENUM_TYPE(BaseShapeChunk)
enum {
	Header           = 0x00,   //
	Vertex           = 0x10,   //
	VertexNormal     = 0x11,   //
	VertexNBT        = 0x12,   //
	VertexColour     = 0x13,   //
	TexCoord0        = 0x18,   //
	TexCoord1        = 0x19,   //
	TexCoord2        = 0x1A,   //
	TexCoord3        = 0x1B,   //
	TexCoord4        = 0x1C,   //
	TexCoord5        = 0x1D,   //
	TexCoord6        = 0x1E,   //
	TexCoord7        = 0x1F,   //
	Texture          = 0x20,   //
	TextureAttribute = 0x22,   //
	Material         = 0x30,   //
	VertexMatrix     = 0x40,   //
	MatrixEnvelope   = 0x41,   //
	Mesh             = 0x50,   //
	Joint            = 0x60,   //
	JointName        = 0x61,   //
	CollisionPrism   = 0x100,  //
	CollisionGrid    = 0x110,  //
	EndOfFile        = 0xFFFF, //
} END_ENUM_TYPE;

BEGIN_ENUM_TYPE(ShapeFlags)
enum {
	None         = 0,      //
	AllowCaching = 1 << 1, // Allows caching of shape geometry into a display list.
	AlwaysRedraw = 1 << 2, // Forces the shape to be redrawn every frame, bypassing any cached display list.
	IsPlatform   = 1 << 4, // Indicates the shape is a platform or has platform collision.
} END_ENUM_TYPE;

/**
 * @brief Flags indicating which vertex data needs cache flushing
 */
BEGIN_ENUM_TYPE(VertexCacheFlags)
enum {
	None       = 0,       //
	VertexList = 1 << 0,  // Vertex position data needs cache flush
	NormalList = 1 << 1,  // Normal vector data needs cache flush
	NBTList    = 1 << 2,  // Normal/Binormal/Tangent data needs cache flush
	ColorList  = 1 << 4,  // Vertex color data needs cache flush
	TexCoord0  = 1 << 5,  // Texture coordinate 0 needs cache flush
	TexCoord1  = 1 << 6,  // Texture coordinate 1 needs cache flush
	TexCoord2  = 1 << 7,  // Texture coordinate 2 needs cache flush
	TexCoord3  = 1 << 8,  // Texture coordinate 3 needs cache flush
	TexCoord4  = 1 << 9,  // Texture coordinate 4 needs cache flush
	TexCoord5  = 1 << 10, // Texture coordinate 5 needs cache flush
	TexCoord6  = 1 << 11, // Texture coordinate 6 needs cache flush
	TexCoord7  = 1 << 12, // Texture coordinate 7 needs cache flush
} END_ENUM_TYPE;

/**
 * @brief TODO
 */
struct BaseShape : public CoreNode {
	BaseShape();

	virtual void read(RandomAccessStream&); // _0C
	virtual void optimize() { }             // _10
	virtual void update() { }               // _14
	virtual void render(Graphics&) { }      // _18
	virtual void render2d(Graphics&) { }    // _1C
	virtual RouteGroup* makeRouteGroup()    // _20
	{
		RouteGroup* newGroup   = new RouteGroup;
		newGroup->mParentShape = this;
		return newGroup;
	}

	void importIni(RandomAccessStream&);
	void countMaterials(Joint*, u32);
	void recTraverseMaterials(Joint*, IDelegate2<Joint*, u32>*);
	ShapeDynMaterials* instanceMaterials(int);
	void makeInstance(ShapeDynMaterials&, int);
	void drawculled(Graphics&, Camera&, ShapeDynMaterials*);
	void drawshape(Graphics&, Camera&, ShapeDynMaterials*);
	void resolveTextureNames();
	void recAddMatpoly(Joint*, int);
	void initIni(bool);
	void initialise();
	void createCollisions(int);
	void calcBasePose(immut Matrix4f&);
	AnimData* loadDck(immut char*, RandomAccessStream&);
	AnimData* importDck(immut char*, CmdStream*);
	AnimData* loadDca(immut char*, RandomAccessStream&);
	AnimData* loadAnimation(immut char* path, bool isRelativePath);
	Matrix4f& getAnimMatrix(int);
	void backupAnimOverrides(AnimContext**);
	void restoreAnimOverrides();
	void overrideAnim(int, AnimContext*);
	void updateAnim(Graphics&, immut Matrix4f&, f32*);
	void calcWeightedMatrices();
	void makeNormalIndexes(u16*);
	f32 calcJointWorldPos(Graphics&, int, Vector3f&);
	void calcJointWorldDir(Graphics&, int, Vector3f&);

	// unused/inlined:
	void exportIni(RandomAccessStream&, bool);
	void drawobjcolls(Graphics&, Camera&);
	void drawlights(Graphics&, Camera&);
	void drawroutes(Graphics&, Camera&);
	void skipChunk(RandomAccessStream&, u32);
	void importDca(immut char*, CmdStream*);
	void calcJointWorldScale(Graphics&, int, Vector3f&);
	CollTriInfo* findCollTri(Vector3f&, Vector3f&, Vector3f&, char*);

	// DLL inlines:
	CollGroup* getCollTris(immut Vector3f& pos)
	{
		int x = (pos.x - mCourseExtents.mMin.x) / mGridSize;
		int z = (pos.z - mCourseExtents.mMin.z) / mGridSize;
		if (x < 0 || z < 0 || x >= mGridSizeX || z >= mGridSizeY) {
			return nullptr;
		}
		return mCollGroups[x + z * mGridSizeX];
	}

	// todo, use .cpp version once shapeBase is linked
	void removeMtxDependancy() { }

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 mSystemFlags;                   // _14, see BaseShapeFlags enum
	AnimContext* mCurrentAnimation;     // _18
	AnimContext** mAnimOverrides;       // _1C
	AnimContext** mBackupAnimOverrides; // _20
	AnimFrameCacher* mFrameCacher;      // _24
	Matrix4f* mAnimMatrices;            // _28
	u32 mAnimMtxCount;                  // _2C
	s32 mEnvelopeCount;                 // _30
	Envelope* mEnvelopeList;            // _34
	s32 mVtxMatrixCount;                // _38
	VtxMatrix* mVtxMatrixList;          // _3C
	s32 mMaterialCount;                 // _40
	Material* mMaterialList;            // _44
	s32 mTevInfoCount;                  // _48
	PVWTevInfo* mTevInfoList;           // _4C
	s32 mMeshCount;                     // _50
	Mesh* mMeshList;                    // _54
	int mJointCount;                    // _58
	Joint* mJointList;                  // _5C
	s32 mTotalMatpolyCount;             // _60
	Joint::MatPoly** mMatpolyList;      // _64
	s32 mTexAttrCount;                  // _68
	TexAttr* mTexAttrList;              // _6C
	s32 _70;                            // _70
	s32 mTextureCount;                  // _74
	TexImg* mTextureList;               // _78
	// NB: there's an extra AnimData debugData; here in the DLL, so everything is shifted by 0x44.
	LightGroup mLightGroup;         // _7C
	ObjCollInfo mCollisionInfo;     // _E8
	u32 mVertexCacheFlags;          // _13C, see VertexCacheFlags enum
	BoundBox mCourseExtents;        // _140
	f32 mGridSize;                  // _158
	int mGridSizeX;                 // _15C
	int mGridSizeY;                 // _160
	CollGroup** mCollGroups;        // _164
	int mTriCount;                  // _168
	CollTriInfo* mTriList;          // _16C
	s32 mBaseRoomCount;             // _170
	RoomInfo* mRoomInfoList;        // _174
	RouteGroup mRouteGroup;         // _178
	s32 mVertexCount;               // _238
	Vector3f* mVertexList;          // _23C
	int mVtxColorCount;             // _240
	Colour* mVtxColorList;          // _244
	s32 mTotalActiveTexCoords;      // _248
	s32 mTexCoordCounts[8];         // _24C
	Vector2f* mTexCoordList[8];     // _26C
	s32 mNormalCount;               // _28C
	Vector3f* mNormalList;          // _290
	int mNBTCount;                  // _294
	NBT* mNBTList;                  // _298
	int mFallbackTexAttrCount;      // _29C
	Texture** mResolvedTextureList; // _2A0
	int mAttrListMatCount;          // _2A4
	char (*mTextureNameList)[32];   // _2A8
	u8 _2AC;                        // _2AC
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

	CachedShape* mPrev;                    // _00
	CachedShape* mNext;                    // _04
	ShapeDynMaterials* mAnimatedMaterials; // _08
	Shape* mParentShape;                   // _0C
	Matrix4f* mAnimMatrices;               // _10
	f32 mDistanceFromOrigin;               // _14
};

#endif
