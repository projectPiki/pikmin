#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "CoreNode.h"
#include "GfxObject.h"
#include "PVW.h"
#include "Stream.h"

struct Graphics;
struct Colour;

/**
 * @brief Enum for material flags.
 */
enum MaterialFlags {
	MATFLAG_PVW          = 1 << 0,  ///< 0x0001, Enables programmable vertex/pixel features.
	MATFLAG_OPAQUE       = 1 << 8,  ///< 0x0100, Opaque material (no blending).
	MATFLAG_ALPHA_TEST   = 1 << 9,  ///< 0x0200, Hard-edged alpha cutout.
	MATFLAG_ALPHA_BLEND  = 1 << 10, ///< 0x0400, Smooth alpha blending.
	MATFLAG_INVERT_BLEND = 1 << 15, ///< 0x8000, Invert blend mode (e.g., for shadows).
	MATFLAG_SKIP         = 1 << 16, ///< 0x10000, Skip rendering this material.
};

/**
 * @brief TODO
 * @note Size: 0x9C.
 */
struct Material : public CoreNode {
	Material()
	    : CoreNode("material")
	{
		mIndex         = 0;
		mEnvMapTexture = nullptr;
		mTexture       = nullptr;
		mAttribute     = nullptr;
		mEnvMapTexture = nullptr;
		mFlags         = MATFLAG_OPAQUE;
		getColour().set(0xFF, 0xFF, 0xFF, 0xFF);
		mTevInfoIndex   = 0;
		mDisplayListPtr = nullptr;
	}

	virtual void read(RandomAccessStream&); // _0C
	virtual void attach();                  // _10

	void setColour(immut Colour& color)
	{
		if (mLightingInfo.mCtrlFlag & LightingControlFlags::EnableSpecular) {
			mTevInfo->mTevColRegs[0].mAnimatedColor.r = color.r;
			mTevInfo->mTevColRegs[0].mAnimatedColor.g = color.g;
			mTevInfo->mTevColRegs[0].mAnimatedColor.b = color.b;
			mTevInfo->mTevColRegs[0].mAnimatedColor.a = color.a;
		} else {
			mColourInfo.mColour = color;
		}
	}

	// This function is called `Colour` according to the ILK, but that's confusing, inconsistent with `setColour`,
	// and an issue for code portability (e.g. "-Wchanges-meaning" in GCC, which is an error without "-fpermissive").
	Colour& getColour() { return mColourInfo.mColour; }

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 mIndex;                       // _14
	u32 mFlags;                       // _18, see MaterialFlags enum
	int mTextureIndex;                // _1C
	TexAttr* mAttribute;              // _20
	Texture* mTexture;                // _24
	Texture* mEnvMapTexture;          // _28
	PVWPolygonColourInfo mColourInfo; // _2C [0x20]
	PVWLightingInfo mLightingInfo;    // _4C [0x0C]
	PVWPeInfo mPeInfo;                // _58 [0x10]
	PVWTextureInfo mTextureInfo;      // _68 [0x24]
	u32 mTevInfoIndex;                // _8C
	PVWTevInfo* mTevInfo;             // _90
	u32 mDisplayListSize;             // _94
	u8* mDisplayListPtr;              // _98
};

/**
 * @brief TODO
 */
struct MatobjInfo : public GfxobjInfo {
	MatobjInfo()
	{
		mTarget = nullptr;
		mString = "material";
		mId.setID('_gfx');
	}

	virtual void attach() { mTarget->attach(); } // _08
	virtual void detach() { }                    // _0C

	// _1C     = VTBL
	// _00-_20 = GfxobjInfo
	Material* mTarget; // _24
};

/**
 * @brief TODO
 */
struct MaterialHandler {
	MaterialHandler() { mGfx = nullptr; }

	Graphics* mGfx; // _00
	// _04     = VTBL

	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C
};

#endif
