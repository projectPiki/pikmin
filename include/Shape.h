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
#include "GfxobjInfo.h"

template <typename A, typename B>
struct IDelegate2;

struct AnimContext;
struct CmdStream;
struct Joint;
struct RouteGroup;
struct VtxMatrix;
struct Texture;
struct CollTriInfo;
struct BaseRoomInfo;
struct NBT;
struct DispList;

/**
 * @brief TODO
 */
struct Envelope {
	Envelope();

	// unused/inlined:
	void read(RandomAccessStream&);

	// TODO: members
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
 */
struct ShapeDynMaterials {
	void animate(f32*);
	void updateContext();
};

struct LFlareGroup;

struct LightFlare : public CoreNode {
	LightFlare() { }

	f32 mSize;          // _14
	Vector3f mPosition; // _18
};

/**
 * @brief TODO
 */
struct LightGroup : public CoreNode {
	LightGroup()
	{
		mFlags      = 0;
		mType       = 0;
		mJointIndex = -1;
		mTexture    = nullptr;
	}

#ifndef __MWERKS__
	void addLight(struct Vector3f&, float);
	void ageAddFlare(struct AgeServer&);
	void ageChangeTexture(struct AgeServer&);
	void ageDel(struct AgeServer&);

	virtual void genAge(class AgeServer&);

	void addLight(struct Vector3f&, float);
	void saveini(char*, struct RandomAccessStream&);
#endif

	void loadini(struct CmdStream*);
	void refresh(struct Graphics&, struct Matrix4f*);

	s32 mFlags;               // _14
	s32 mType;                // _18
	s32 mJointIndex;          // _1C
	Texture* mTexture;        // _20
	Vector3f mDirection;      // _24
	Colour mLightColour;      // _30
	s8* mTexSource;           // _34
	s8* mMatSource;           // _38
	Texture* mHaloTex;        // _3C
	LightFlare mFlares;       // _40
	s32 _64;                  // _64
	LFlareGroup* mFlareGroup; // _68
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
	virtual void makeRouteGroup();          // _20

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
	void loadDck(char*, RandomAccessStream&);
	void importDck(char*, CmdStream*);
	void loadDca(char*, RandomAccessStream&);
	void loadAnimation(char*, bool);
	void getAnimMatrix(int);
	void backupAnimOverrides(AnimContext**);
	void restoreAnimOverrides();
	void overrideAnim(int, AnimContext*);
	void updateAnim(Graphics&, Matrix4f&, f32*);
	void calcWeightedMatrices();
	void makeNormalIndexes(u16*);
	void calcJointWorldPos(Graphics&, int, struct Vector3f&);
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
	s32 mSystemUsed;                   // _14
	AnimContext* mCurrentAnimations;   // _18
	AnimContext** mAnimOverrides;      // _1C
	AnimContext* mBackupAnimOverrides; // _20
	AnimFrameCacher* mFrameCacher;     // _24
	Matrix4f* mAnimMatrix;             // _28
	int _2C;                           // _2C
	int mEnvelopeCount;                // _30
	Envelope* mEnvelopeList;           // _34
	s32 mVtxMatrixCount;               // _38
	VtxMatrix* mVtxMatrixList;         // _3C
	s32 mMaterialCount;                // _40
	Material* mMaterialList;           // _44
	s32 mTevInfoCount;                 // _48
	PVWTevInfo* mTevInfoList;          // _4C
	s32 mMeshCount;                    // _50
	Mesh* mMeshList;                   // _54
	s32 mJointCount;                   // _58
	Joint* mJoints;                    // _5C
	s32 mRouteGroupCount;              // _60
	RouteGroup* mRouteGroupList;       // _64
	s32 mTextureAttributesCount;       // _68
	TexAttr* mTextureAttributeList;    // _6C
	s32 _70;                           // _70
	s32 mTextureCount;                 // _74
	TexImg* mTextureList;              // _78
	AnimData mAnimData;                // _7C
	LightGroup mGroups;                // _C0
	ObjCollInfo mCollisionInfo;        // _12C
	s32 _180;                          // _180
	BoundBox mCourseExtents;           // _184
	f32 mGridSize;                     // _19C
	s32 mGridSizeX;                    // _1A0
	s32 mGridSizeY;                    // _1A4
	s32* mCollisionTriangles;          // _1A8
	s32 mCollTriCount;                 // _1AC
	CollTriInfo* mCollTriInfoList;     // _1B0
	s32 mBaseRoomCount;                // _1B4
	BaseRoomInfo* mRoomInfoList;       // _1B8
	u8 _1BC[0xC0];                     // _1BC
	s32 mVertexCount;                  // _27C
	Vector3f* mVertexList;             // _280
	s32 mVertexColourCount;            // _284
	Colour* mVertexColourList;         // _288
	s32 mTexCoordSetCount;             // _28C
	s32 mTexCoordCount[8];             // _290
	Vector2f* mTexCoords[8];           // _2B0
	s32 mNormalCount;                  // _2D0
	Vector3f* mNormals;                // _2D4
	s32 mNbtCount;                     // _2D8
	NBT* mNbtList;                     // _2DC
	s32 mAttrListCount;                // _2E0
	Texture** mExternalTextureList;    // _2E4
	s32 mAttrListMatCount;             // _2E8
	u32 _2EC;                          // _2EC
	u8 _2F0;                           // _2FO
};

/**
 * @brief TODO
 */
struct Shape : public BaseShape {
	Shape();

	virtual void optimize(); // _10

	// _00      = VTBL
	// _00-_2B0 = BaseShape
	// TODO: members
};

struct CamDataInfo {
	void update(f32, Matrix4f&);
};

struct LightDataInfo {
	void update(f32);
};

struct SceneData {
	void parse(CmdStream*);
	void getAnimInfo(CmdStream*);
};

#endif
