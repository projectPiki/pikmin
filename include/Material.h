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
	Material();

	virtual void read(RandomAccessStream&); // _0C
	virtual void attach();                  // _10

	Colour& Colour() { return mColourInfo.mColour; }

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
	ShortColour* _90;                 // _90
	u32 mDisplayListSize;             // _94
	u32* mDisplayListPtr;             // _98
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
	virtual void setMaterial(Material*); // _08
	virtual void setTexMatrix(bool);     // _0C

	// TODO: members
};

#endif
