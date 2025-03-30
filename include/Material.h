#ifndef _MATERIAL_H
#define _MATERIAL_H

#include "Stream.h"
#include "CoreNode.h"
#include "GfxObject.h"
#include "PVW.h"

/**
 * @brief TODO
 * @note Size: 0x9C.
 */
struct Material : public CoreNode {
	Material()
	    : CoreNode("material")
	{
		mIndex = 0;
		_28    = 0;
		_24    = 0;
		_20    = 0;
		_28    = 0;
		mFlags = 0x100;
		Colour().set(0xFF, 0xFF, 0xFF, 0xFF);
		_8C             = 0;
		mDisplayListPtr = nullptr;
	}

	virtual void read(RandomAccessStream&); // _0C
	virtual void attach();                  // _10

	Colour& Colour() { return mColourInfo.mColour; }

	void setColour(struct Colour& color)
	{
		if (mLightingInfo._00 & 2) {
			mTevInfo->mTevColRegs[0]._00.r = color.r;
			mTevInfo->mTevColRegs[0]._00.g = color.g;
			mTevInfo->mTevColRegs[0]._00.b = color.b;
			mTevInfo->mTevColRegs[0]._00.a = color.a;
		} else {
			mColourInfo.mColour = color;
		}
	}

	// _00     = VTBL
	// _00-_14 = CoreNode
	u32 mIndex;                       // _14
	u32 mFlags;                       // _18 (PVW & 1, TEX & 2, XLU & 4)
	u32 mTextureIndex;                // _1C
	u32 _20;                          // _20
	u32 _24;                          // _24
	u32 _28;                          // _28
	PVWPolygonColourInfo mColourInfo; // _2C [0x20]
	PVWLightingInfo mLightingInfo;    // _4C [0x0C]
	PVWPeInfo mPeInfo;                // _58 [0x10]
	PVWTextureInfo mTextureInfo;      // _68 [0x24]
	u32 _8C;                          // _8C
	PVWTevInfo* mTevInfo;             // _90
	u32 mDisplayListSize;             // _94
	u8* mDisplayListPtr;              // _98
};

/**
 * @brief TODO
 */
struct MatobjInfo : public GfxobjInfo {
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
	MaterialHandler() { _00 = 0; }

	u32 _00; // _00
	// _04     = VTBL

	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C
};

#endif
