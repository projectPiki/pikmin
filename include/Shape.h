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
	    : _00(0)
	    , _04(0)
	    , _08(0)
	    , _0C(0)
	{
	}

	void animate(f32*);
	void updateContext();

	u32 _00;       // _00
	u32 _04;       // _04
	Material* _08; // _08
	u32 _0C;       // _0C
};

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
	int _24;            // _24
	int _28;            // _28
	FaceNode mFaceNode; // _2C
};

/**
 * @brief TODO
 */
struct DlobjInfo : public GfxobjInfo {
	DlobjInfo();
};

/**
 * @brief TODO
 */
struct BaseShape : public CoreNode {
	BaseShape();

	virtual void read(RandomAccessStream&); // _0C
	virtual void optimize();                // _10
	virtual void update();                  // _14
	virtual void render(struct Graphics&);  // _18
	virtual void render2d(Graphics&);       // _1C
	virtual RouteGroup* makeRouteGroup();   // _20

	void importIni(RandomAccessStream&);
	void countMaterials(Joint*, u32);
	void recTraverseMaterials(Joint*, IDelegate2<Joint*, u32>*);
	void instanceMaterials(int);
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
	void findCollTri(Vector3f&, Vector3f&, Vector3f&, char*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 mSystemFlags;                 // _14
	AnimContext* mCurrentAnimContext; // _18, current animation
	AnimContext** mAnimContextList;   // _1C
	u32 _20;                          // _20
	AnimFrameCacher* mFrameCacher;    // _24
	Matrix4f* mAnimMatrices;          // _28
	u32 _2C;                          // _2C
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
	s32 _60;                          // _60
	s32* _64;                         // _64
	s32 mTexAttrCount;                // _68
	TexAttr* mTexAttrList;            // _6C
	s32 _70;                          // _70
	s32 mTextureCount;                // _74
	TexImg* mTextureList;             // _78
	LightGroup mLightGroup;           // _7C
	ObjCollInfo mCollisionInfo;       // _E8
	u32 _13C;                         // _13C, flag of some kind?
	BoundBox _140;                    // _140
	u8 _158[0x164 - 0x158];           // _158
	u32 _164;                         // _164
	u32 _168;                         // _168
	u32 _16C;                         // _16C
	u32 _170;                         // _170
	u32 _174;                         // _174
	RouteGroup mRouteGroup;           // _178
	s32 mVertexCount;                 // _238 - from here down might match the names/types from _27C on from the DLL?
	Vector3f* mVertexList;            // _23C
	u8 _240[0x4];                     // _240
	u32 _244;                         // _244
	u32 _248;                         // _248
	u8 _24C[0x26C - 0x24C];           // _18C
	u32 _26C;                         // _26C
	u32 _270;                         // _270
	u32 _274;                         // _274
	u32 _278;                         // _278
	u32 _27C;                         // _27C
	u32 _280;                         // _280
	u32 _284;                         // _284
	u32 _288;                         // _288
	s32 mNormalCount;                 // _28C
	Vector3f* mNormals;               // _290
	u8 _294[0x4];                     // _294
	u32 _298;                         // _298
	u32 _29C;                         // _29C
	Texture* _2A0;                    // _2A0
	u32 _2A4;                         // _2A4
	u32 _2A8;                         // _2A8
	u8 _2AC;                          // _2AC

	// OLD - idk what this is from but it's not correct.
	// s32 mSystemUsed;                   // _14
	// AnimContext* mCurrentAnimations;   // _18
	// AnimContext** mAnimOverrides;      // _1C
	// AnimContext* mBackupAnimOverrides; // _20
	// AnimFrameCacher* mFrameCacher;     // _24
	// Matrix4f* mAnimMatrix;             // _28
	// int _2C;                           // _2C
	// int mEnvelopeCount;                // _30
	// Envelope* mEnvelopeList;           // _34
	// s32 mVtxMatrixCount;               // _38
	// VtxMatrix* mVtxMatrixList;         // _3C
	// s32 mMaterialCount;                // _40
	// Material* mMaterialList;           // _44
	// s32 mTevInfoCount;                 // _48
	// PVWTevInfo* mTevInfoList;          // _4C
	// s32 mMeshCount;                    // _50
	// Mesh* mMeshList;                   // _54
	// s32 mJointCount;                   // _58
	// Joint* mJoints;                    // _5C
	// s32 mRouteGroupCount;              // _60
	// RouteGroup* mRouteGroupList;       // _64
	// s32 mTextureAttributesCount;       // _68
	// TexAttr* mTextureAttributeList;    // _6C
	// s32 _70;                           // _70
	// s32 mTextureCount;                 // _74
	// TexImg* mTextureList;              // _78
	// AnimData mAnimData;                // _7C
	// LightGroup mGroups;                // _C0
	// ObjCollInfo mCollisionInfo;        // _12C
	// s32 _180;                          // _180
	// BoundBox mCourseExtents;           // _184
	// f32 mGridSize;                     // _19C
	// s32 mGridSizeX;                    // _1A0
	// s32 mGridSizeY;                    // _1A4
	// s32* mCollisionTriangles;          // _1A8
	// s32 mCollTriCount;                 // _1AC
	// CollTriInfo* mCollTriInfoList;     // _1B0
	// s32 mBaseRoomCount;                // _1B4
	// BaseRoomInfo* mRoomInfoList;       // _1B8
	// u8 _1BC[0xC0];                     // _1BC
	// s32 mVertexCount;                  // _27C - maybe these match above from _238?
	// Vector3f* mVertexList;             // _280
	// s32 mVertexColourCount;            // _284
	// Colour* mVertexColourList;         // _288
	// s32 mTexCoordSetCount;             // _28C
	// s32 mTexCoordCount[8];             // _290
	// Vector2f* mTexCoords[8];           // _2B0
	// s32 mNormalCount;                  // _2D0
	// Vector3f* mNormals;                // _2D4
	// s32 mNbtCount;                     // _2D8
	// NBT* mNbtList;                     // _2DC
	// s32 mAttrListCount;                // _2E0
	// Texture** mExternalTextureList;    // _2E4
	// s32 mAttrListMatCount;             // _2E8
	// u32 _2EC;                          // _2EC
	// u8 _2F0;                           // _2FO
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
	CachedShape() { _00 = _04 = this; }

	// TODO: members
	CachedShape* _00;   // _00, maybe prev and next?
	CachedShape* _04;   // _04
	u8 _08[0x18 - 0x8]; // _08
};

#endif
