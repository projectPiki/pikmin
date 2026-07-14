#include "Texture.h"

#include "DebugLog.h"
#include "Dolphin/gx.h"
#include "Stream.h"
#include "sysNew.h"
#include "system.h"
#include <stddef.h>
#include <string.h>

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
#if defined(VERSION_GPIJ01) || defined(VERSION_DPIJ01_PIKIDEMO)
DEFINE_ERROR(12)
#else
DEFINE_ERROR(14)
#endif

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Texture");

/**
 * @todo: Documentation
 */
Texture::Texture()
{
	_30          = 0;
	_34          = 0;
	_20          = -1;
	mLODCount    = 0;
	mLODBias     = 0.0f;
	mTexObj      = new GXTexObj();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void Texture::offsetGLtoGX(int, int)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @brief Fabricated inline for matching DOL-exclusive code.
 */
static inline u32 calcQY(Texture* tex, int y)
{
	return y / tex->mTileSizeY;
}

/**
 * @brief Fabricated inline for matching DOL-exclusive code.
 */
static inline u32 calcQX(Texture* tex, int x)
{
	return x / tex->mTileSizeX;
}

/**
 * @brief Fabricated inline for matching DOL-exclusive code.
 */
static inline u32 calcRow(u16 width, const u32& tx, u32 ty)
{
	u32 area = tx * ty;
	u32 wt   = width / tx;
	return wt * area;
}

/**
 * @brief Fabricated inline for matching DOL-exclusive code.
 */
static inline u32 calcParts(Texture* tex, int x, int y, u32& area, u32& row)
{
	area   = tex->mTileSizeX * tex->mTileSizeY;
	row    = calcRow(tex->mWidth, tex->mTileSizeX, tex->mTileSizeY);
	u32 qy = calcQY(tex, y);
	return qy;
}

/**
 * @brief Fabricated inline for matching DOL-exclusive code.
 */
static inline int calcOffset(Texture* tex, int x, int y)
{
	u32 area;
	u32 row;
	u32 qy = calcParts(tex, x, y, area, row);
	u32 qx = calcQX(tex, x);
	x -= qx * tex->mTileSizeX;
	y -= qy * tex->mTileSizeY;
	int index = x + tex->mTileSizeX * y;
	qy *= row;
	int qxTerm = qx * area;
	index      = qy + (qxTerm + index);
	return index;
}

/**
 * @todo: Documentation
 */
u8 Texture::getAlpha(int x, int y)
{
	switch (mTexFormat) {
	case TEX_FMT_IA4:
	{
		u8* data = (u8*)mPixelData;
		u8 pixel = data[calcOffset(this, x, y)];
		return pixel & 0xF0;
	}
	default: // TEX_FMT_RGB5A3 assumed
	{
		u16* data = (u16*)mPixelData;
		u16 pixel = data[calcOffset(this, x, y)];
		if (pixel & 0x8000) {
			return 255;
		}
		return (pixel >> 7) & 0xE0;
	}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D4
 */
u8 Texture::getRed(int x, int y)
{
	switch (mTexFormat) {
	case TEX_FMT_IA4:
	{
		u8* data = (u8*)mPixelData;
		u8 pixel = data[calcOffset(this, x, y)];
		return pixel & 0x0F;
	}
	default: // TEX_FMT_RGB5A3 assumed
	{
		u16* data = (u16*)mPixelData;
		u16 pixel = data[calcOffset(this, x, y)];
		if (pixel & 0x8000) {
			return (pixel & 0x7C00) >> 7;
		}
		return (pixel & 0x0F00) >> 4;
	}
	}
}

/**
 * @todo: Documentation
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
		ERROR("Unknown texture extension (%s)!!\n", strlen(input.mPath) - 3 + input.mPath);
	}
	gsys->addTexture(this, input.mPath);
}

static GXTexFmt gxTexFmts[TEX_FMT_COUNT] = {
	GX_TF_RGB565, GX_TF_CMPR, GX_TF_RGB5A3, GX_TF_I4, GX_TF_I8, GX_TF_IA4, GX_TF_IA8, GX_TF_RGBA8, GX_TF_Z8,
};

/**
 * @todo: Documentation
 */
void Texture::detach()
{
	BUMP_REGISTER(r0);
	_20 = -1; // needs to use r4?
}

/**
 * @todo: Documentation
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
	if (mLODCount != 0) {
		useMIPmap = GX_TRUE;
	} else {
		useMIPmap = GX_FALSE;
	}

	GXInitTexObj(mTexObj, mPixelData, mWidth, mHeight, texFmt, sWrap, tWrap, useMIPmap);

	if (mLODCount != 0) {
		GXInitTexObjLOD(mTexObj, GX_LIN_MIP_LIN, GX_LINEAR, 0.0f, mLODCount, mLODBias, GX_FALSE, GX_FALSE, GX_ANISO_1);
	}
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void Texture::grabBuffer(int width, int height, bool enableDepth, bool useMIPmap)
{
	if (enableDepth) {
		GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
	}

	if (useMIPmap) {
		GXSetTexCopySrc(0, 0, width << 1, height << 1);
		GXSetTexCopyDst((u16)width, (u16)height, gxTexFmts[mTexFormat], GX_TRUE);
	} else {
		GXSetTexCopySrc(0, 0, width, height);
		GXSetTexCopyDst((u16)width, (u16)height, gxTexFmts[mTexFormat], GX_FALSE);
	}

	if (!enableDepth) {
		GXSetCopyFilter(GX_FALSE, nullptr, GX_FALSE, nullptr);
	}

	GXCopyTex(mPixelData, enableDepth);
	GXPixModeSync();
	GXSetZMode(GX_TRUE, GX_LESS, GX_TRUE);
}

/**
 * @todo: Documentation
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
