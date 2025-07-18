#ifndef _LIGHT_H
#define _LIGHT_H

#include "Camera.h"
#include "Colour.h"
#include "Node.h"
#include "Vector.h"
#include "system.h"
#include "types.h"

struct CmdStream;
struct Graphics;
struct SceneData;
struct Shape;
struct Texture;

/**
 * @brief TODO
 *
 * @note Size: 0x2C.
 */
struct LFInfo {
	LFInfo() { mPrevInfo = nullptr; }

	Colour mColour;     // _00
	Vector3f mFlarePos; // _04
	Vector2f mSize;     // _10
	Vector2f mUvMin;    // _18
	Vector2f mUvMax;    // _20
	LFInfo* mPrevInfo;  // _28
};

/**
 * @brief TODO
 *
 * @note Size: 0x24.
 */
struct LightFlare : public CoreNode {
	LightFlare()
	    : CoreNode("")
	{
	}

	// unused/inlined:
	void loadini(CmdStream*);
	void saveini(char*, RandomAccessStream&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	f32 mSize;          // _14
	Vector3f mPosition; // _18
};

/**
 * @brief TODO
 */
struct LFlareGroup : public CoreNode {
	LFlareGroup()
	    : CoreNode("lfgroup")
	{
		mTexture   = nullptr;
		mMaterial  = 0;
		mLFInfo    = nullptr;
		mBlendMode = 1;
	}

	void addLFlare(Colour& color, Vector3f& pos, Vector2f& size, Vector2f* a5, Vector2f* a6)
	{
		LFInfo* info = gsys->getLFlareInfo();
		if (!info) {
			return;
		}

		info->mColour   = color;
		info->mFlarePos = pos;
		info->mSize     = size;

		if (a5 && a6) {
			info->mUvMin = *a5;
			info->mUvMax = *a6;
		} else {
			info->mUvMin.set(0.0f, 0.0f);
			info->mUvMax.set(1.0f, 1.0f);
		}

		info->mPrevInfo = mLFInfo;
		mLFInfo         = info;
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 _14;                    // _14
	struct Texture* mTexture;   // _18
	struct Material* mMaterial; // _1C
	LFInfo* mLFInfo;            // _20
	u32 mBlendMode;             // _24
};

/**
 * @brief TODO
 *
 * @note Size: 0x2D4.
 */
struct Light : public CoreNode {
	Light();

	void setLightDistAttn(f32, f32, int);
	void setLightSpot(f32, int);
	void update();

	// unused/inlined:
	void setLightParallel();
	void calcLightSizes();
	f32 calcLightMapRadius();
	f32 calcLightObjRadius();
	void refresh(Graphics&, LFlareGroup*);

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 mLightType;              // _14
	f32 mDistancedRange;         // _18
	f32 mAttenuation;            // _1C
	f32 mSpotAngle;              // _20
	u32 mMode;                   // _24
	u32 mSpotMode;               // _28
	f32 mConstantAttn;           // _2C
	f32 mLinearAttn;             // _30
	f32 mQuadAttn;               // _34
	f32 mSpotConstTerm;          // _38
	f32 mSpotLinearTerm;         // _3C
	f32 mSpotQuadTerm;           // _40
	f32 _44;                     // _44
	f32 _48;                     // _48
	u8 _4C[0x8];                 // _4C, unknown
	Vector3f mPosition;          // _54
	Vector3f mDirection;         // _60
	Colour mDiffuseColour;       // _6C
	u32 mLightValuesSet;         // _70
	CullFrustum* mFrustum;       // _74
	u32 _78;                     // _78
	u32 _7C;                     // _7C
	CullingPlane mCullPlanes[6]; // _80
	u8 _188[0x1C8 - 0x188];      // _188, unknown
	u8 _1C8;                     // _1C8
	u8 _1C9;                     // _1C9
	Vector3f _1CC;               // _1CC
	Vector3f _1D8;               // _1D8
	Vector3f _1E4;               // _1E4
	Vector3f _1F0;               // _1F0
	Vector3f _1FC;               // _1FC
	Vector3f _208;               // _208
	Vector3f _214;               // _214
	Vector3f _220;               // _220
	Vector3f _22C;               // _22C
	u8 _238[0x8];                // _238, unknown
	f32 _240;                    // _240
	f32 _244;                    // _244
	f32 _248;                    // _248
	u8 _24C[0x2D4 - 0x24C];      // _24C, unknown
};

/**
 * @brief TODO
 *
 * @note Size: 0x6C.
 */
struct LightGroup : public CoreNode {
	LightGroup()
	{
		mFlags      = 0;
		mType       = 0;
		mJointIndex = -1;
		mTexture    = nullptr;

		mFlares.initCore("");

		mLightColour.set(255, 255, 255, 255);
		mTexSource  = nullptr;
		mHaloTex    = nullptr;
		mFlareGroup = nullptr;
	}

#ifdef WIN32
	void addLight(struct Vector3f&, f32);
	void ageAddFlare(struct AgeServer&);
	void ageChangeTexture(struct AgeServer&);
	void ageDel(struct AgeServer&);

	virtual void genAge(class AgeServer&);
#endif

	void loadini(CmdStream*);
	void refresh(Graphics&, Matrix4f*);

	// unused/inlined:
	void saveini(char*, RandomAccessStream&);

	inline LFlareGroup* getLFlareGroup() { return mFlareGroup; }

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mFlags;               // _14
	int mType;                // _18
	u32 mJointIndex;          // _1C
	Texture* mTexture;        // _20
	Vector3f mDirection;      // _24
	Colour mLightColour;      // _30
	char* mTexSource;         // _34
	char* mMatSource;         // _38
	Texture* mHaloTex;        // _3C
	LightFlare mFlares;       // _40
	Shape* mParentShape;      // _64
	LFlareGroup* mFlareGroup; // _68
};

// clang-format off
DEFINE_ENUM_TYPE(
	LightPoolFlags,
	DrawFrustum = 1,
);
// clang-format on

/**
 * @brief TODO
 * @note 1001F2A0 in plugPiki.dll might allude to some members.
 * @note Size: 0x670.
 */
struct LightPool : public Node {
	LightPool();

	virtual void draw(Graphics&); // _14

	// _00     = VTBL
	// _00-_20 = Node
	Light mLight;              // _20
	LightCamera mCamera;       // _2F4
	f32 mFocusRotationAngle;   // _65C
	Colour mColour;            // _660
	Texture* mBoxTexture;      // _664
	Texture* mParticleTexture; // _668
	u8 mFlags;                 // _66C, use LightPoolFlags
};

/**
 * @brief TODO
 */
struct LightDataInfo {
	LightDataInfo() { mLight.mDistancedRange = 1000.0f; }

	void update(f32);

	AnimParam mLightPosAnims[3];     // _00
	AnimParam mLightColourAnims[3];  // _24
	AnimParam mLightVisibleAnims[1]; // _48
	int mIsActive;                   // _54
	Light mLight;                    // _58
	int mLightIdx;                   // _32C
	SceneData* mSceneData;           // _330
};

#endif
