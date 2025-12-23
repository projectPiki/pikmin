#include "Texture.h"

#include "DebugLog.h"
#include "Dolphin/gx.h"
#include "Stream.h"
#include "sysNew.h"
#include "system.h"
#include <string.h>

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(14)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Texture");

static GXTexFmt gxTexFmts[TEX_FMT_COUNT] = {
	GX_TF_RGB565, GX_TF_CMPR, GX_TF_RGB5A3, GX_TF_I4, GX_TF_I8, GX_TF_IA4, GX_TF_IA8, GX_TF_RGBA8, GX_TF_Z8,
};

/**
 * @TODO: Documentation
 */
Texture::Texture()
{
	_30          = 0;
	_34          = 0;
	_20          = -1;
	mTextureData = nullptr;
	mLODBias     = 0.0f;
	mTexObj      = new GXTexObj();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
void Texture::offsetGLtoGX(int, int)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
u8 Texture::getAlpha(int x, int y)
{
	switch (mTexFormat) {
	case TEX_FMT_IA4: {
		int tileArea = mTileSizeX * mTileSizeY;
		int x2       = x / mTileSizeX;
		int y2       = y / mTileSizeY;
		return ((u8*)mPixelData)[x2 * tileArea + (x % mTileSizeX) + mTileSizeX * (y % mTileSizeY) + y2 * ((mWidth / mTileSizeX) * tileArea)]
		     & 0xF0;
	}
	default: {
		int tileArea = mTileSizeX * mTileSizeY;
		int blockX   = (x / mTileSizeX) * (mWidth / mTileSizeX) * tileArea;
		int blockY   = (y / mTileSizeY) * tileArea;
		x %= mTileSizeX;
		y %= mTileSizeY;
		u16 alpha = ((u16*)mPixelData)[blockX + x + mTileSizeX * y + blockY];

		if (alpha & 0x8000) {
			return 255;
		}
		return (alpha >> 7) & 0xE0;
	}
	}

	/*
	.loc_0x0:
	  lhz       r0, 0x4(r3)
	  cmpwi     r0, 0x5
	  beq-      .loc_0x10
	  b         .loc_0x68

	.loc_0x10:
	  lwz       r7, 0x10(r3)
	  lwz       r10, 0xC(r3)
	  divwu     r8, r5, r7
	  lhz       r0, 0x8(r3)
	  lwz       r3, 0x14(r3)
	  divwu     r9, r4, r10
	  mullw     r11, r10, r7
	  divwu     r6, r0, r10
	  mullw     r0, r8, r7
	  mullw     r7, r6, r11
	  mullw     r6, r9, r10
	  sub       r0, r5, r0
	  mullw     r0, r10, r0
	  sub       r4, r4, r6
	  mullw     r5, r8, r7
	  add       r4, r4, r0
	  mullw     r0, r9, r11
	  add       r4, r4, r5
	  add       r4, r0, r4
	  lbzx      r0, r3, r4
	  rlwinm    r3,r0,0,24,27
	  blr

	.loc_0x68:
	  lwz       r7, 0x10(r3)
	  lwz       r10, 0xC(r3)
	  divwu     r8, r5, r7
	  lhz       r0, 0x8(r3)
	  lwz       r3, 0x14(r3)
	  divwu     r6, r0, r10
	  mullw     r0, r8, r7
	  mullw     r11, r10, r7
	  sub       r0, r5, r0
	  mullw     r7, r6, r11
	  divwu     r9, r4, r10
	  mullw     r6, r9, r10
	  mullw     r0, r10, r0
	  sub       r4, r4, r6
	  add       r4, r4, r0
	  mullw     r5, r8, r7
	  mullw     r0, r9, r11
	  add       r4, r4, r5
	  add       r4, r0, r4
	  rlwinm    r0,r4,1,0,30
	  lhzx      r3, r3, r0
	  rlwinm.   r0,r3,0,16,16
	  beq-      .loc_0xCC
	  li        r3, 0xFF
	  blr

	.loc_0xCC:
	  rlwinm    r3,r3,25,24,26
	  blr
	*/
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000D4
 */
u8 Texture::getRed(int, int)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Texture::read(RandomAccessStream& input)
{
	if (strcmp(input.mPath + (strlen(input.mPath) - 3), "txe") == 0) {
		TexImg* img = new TexImg;
		img->importTxe(this, input);
	} else if (strcmp(input.mPath + (strlen(input.mPath) - 3), "bti") == 0) {
		TexImg* img = new TexImg;
		img->importBti(this, input, nullptr);
	} else {
		size_t len = strlen(input.mPath);
		ERROR("Unknown texture extension (%s)!!\n", input.mPath - 3 + len);
	}
	gsys->addTexture(this, input.mPath);
}

/**
 * @TODO: Documentation
 */
void Texture::detach()
{
	BUMP_REGISTER(r0);
	_20 = -1; // needs to use r4?
}

/**
 * @TODO: Documentation
 */
void Texture::attach()
{
	if (_20 != -1) {
		return;
	}

	_20 = 0;

	GXTexWrapMode sWrap;
	if (mTexFlags & TEX_CLAMP_S) {
		sWrap = GX_CLAMP;
	} else if (mTexFlags & TEX_MIRROR_S) {
		sWrap = GX_MIRROR;
	} else {
		sWrap = GX_REPEAT;
	}

	GXTexWrapMode tWrap;
	if (mTexFlags & TEX_CLAMP_T) {
		tWrap = GX_CLAMP;
	} else if (mTexFlags & TEX_MIRROR_T) {
		tWrap = GX_MIRROR;
	} else {
		tWrap = GX_REPEAT;
	}

	GXTexFmt texFmt = gxTexFmts[mTexFormat];

	GXBool useMIPmap;
	if (mTextureData) {
		useMIPmap = GX_TRUE;
	} else {
		useMIPmap = GX_FALSE;
	}

	GXInitTexObj(mTexObj, mPixelData, mWidth, mHeight, texFmt, sWrap, tWrap, useMIPmap);

	if (mTextureData) {
		GXInitTexObjLOD(mTexObj, GX_LIN_MIP_LIN, GX_LINEAR, 0.0f, (u32)mTextureData, mLODBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
	}
}

/**
 * @TODO: Documentation
 */
void Texture::createBuffer(int width, int height, int texFmt, void* buf)
{
	mTexFormat   = texFmt;
	mWidth       = width;
	mHeight      = height;
	int dataSize = TexImg::calcDataSize(mTexFormat, mWidth, mHeight);

	mPixelData = (buf) ? buf : new (0x20) u8[(dataSize / 2) * 2];

	mWidthFactor  = 1.0f / mWidth;
	mHeightFactor = 1.0f / mHeight;

	DCStoreRange(mPixelData, dataSize);

	TexImg::getTileSize(mTexFormat, mTileSizeX, mTileSizeY);
}

/**
 * @TODO: Documentation
 */
void Texture::grabBuffer(int width, int height, bool doClear, bool useMIPmap)
{
	if (doClear) {
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	}

	if (useMIPmap) {
		GXSetTexCopySrc(0, 0, width << 1, height << 1);
		GXSetTexCopyDst((u16)width, (u16)height, gxTexFmts[mTexFormat], GX_TRUE);
	} else {
		GXSetTexCopySrc(0, 0, width, height);
		GXSetTexCopyDst((u16)width, (u16)height, gxTexFmts[mTexFormat], GX_FALSE);
	}

	if (!doClear) {
		GXSetCopyFilter(GX_FALSE, nullptr, GX_FALSE, nullptr);
	}

	GXCopyTex(mPixelData, doClear);
	GXPixModeSync();
	GXSetZMode(GX_TRUE, GX_LESS, GX_TRUE);
}

/**
 * @TODO: Documentation
 */
void Texture::decodeData(TexImg* texImg)
{
	mWidth     = texImg->mWidth;
	mHeight    = texImg->mHeight;
	mTexFormat = texImg->mFormat;
	mPixelData = texImg->mTextureData;
	if (!texImg->mPixelData && texImg->mTextureData) {
		DCStoreRange(mPixelData, texImg->mDataSize);
		texImg->mPixelData = mPixelData;
	}
}
