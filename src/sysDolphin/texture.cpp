#include "Texture.h"

#include "DebugLog.h"
#include "Dolphin/gx.h"
#include "Graphics.h"
#include "Stream.h"
#include "sysNew.h"
#include "system.h"
#include <stddef.h>
#include <string.h>

#if !PIKI_USE_DGX
#include <gl/gl.h>
#include <gl/glu.h>
#endif

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
	// One of these following two mystery members aren't initialized on OGL.
	// It's totally ambigious which one still exists, so I'll just pick one.
	_30 = 0;
#if PIKI_USE_DGX
	_34 = 0;
#endif
	mAttachName = -1;
	mLODCount   = 0;
	mLODBias    = 0.0f;
#if PIKI_USE_DGX
	mTexObj = new GXTexObj();
#endif
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
int Texture::offsetGLtoGX(int, int)
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
#if PIKI_USE_DGX
	switch (mTexFormat) {
	case TEX_FMT_IA4:
	{
		u8* data = static_cast<u8*>(mPixelData);
		u8 pixel = data[calcOffset(this, x, y)];
		return pixel & 0xF0;
	}
	default: // TEX_FMT_RGB5A3 assumed
	{
		u16* data = static_cast<u16*>(mPixelData);
		u16 pixel = data[calcOffset(this, x, y)];
		if (pixel & 0x8000) {
			return 255;
		}
		return (pixel >> 7) & 0xE0;
	}
	}
#else
	u8 alpha = static_cast<u32*>(mPixelData)[y * mWidth + x] >> 24;
	return alpha;
#endif
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D4
 */
u8 Texture::getRed(int x, int y)
{
#if PIKI_USE_DGX
	switch (mTexFormat) {
	case TEX_FMT_IA4:
	{
		u8* data = static_cast<u8*>(mPixelData);
		u8 pixel = data[calcOffset(this, x, y)];
		return pixel & 0x0F;
	}
	default: // TEX_FMT_RGB5A3 assumed
	{
		u16* data = static_cast<u16*>(mPixelData);
		u16 pixel = data[calcOffset(this, x, y)];
		if (pixel & 0x8000) {
			return (pixel & 0x7C00) >> 7;
		}
		return (pixel & 0x0F00) >> 4;
	}
	}
#else
	u8 red = static_cast<u32*>(mPixelData)[y * mWidth + x] & 0xFF;
	return red;
#endif
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
	mAttachName = -1; // needs to use r4?
}

/**
 * @todo: Documentation
 */
void Texture::attach()
{
	if (mAttachName == -1) {
#if PIKI_USE_DGX
		mAttachName = 0;

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
#else
		glGenTextures(1, reinterpret_cast<GLuint*>(&mAttachName));
		glBindTexture(GL_TEXTURE_2D, mAttachName);
		if (mTexFlags & TEX_CLAMP_S) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		} else {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		}
		if (mTexFlags & TEX_CLAMP_T) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		} else {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Check that the dimensions are each a power of 2 (up to 2048 x 2048 resolution) for mipmap support.
		int dimsArePow2 = 0;
		for (int i = 0; i < 12; i++) {
			if (mWidth == 1 << i) {
				dimsArePow2 |= 1;
			}
			if (mHeight == 1 << i) {
				dimsArePow2 |= 2;
			}
		}

		// Well this reinterpret cast is OBVIOUSLY wrong.  What up with the `System` class in the DLL?
		if (dimsArePow2 != (1 | 2) || /* reinterpret_cast<bool&>(gsys->mDGXGfx) && */ !(mTexFlags & TEX_Unk2)) {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			gluBuild2DMipmaps(GL_TEXTURE_2D, 4, mWidth, mHeight, GL_RGBA, GL_UNSIGNED_BYTE, mPixelData);
		} else {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, 4, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mPixelData);
		}

#endif
	}
}

/**
 * @todo: Documentation
 */
void Texture::createBuffer(int width, int height, int texFmt, void* buf)
{
#if PIKI_USE_DGX
	mTexFormat   = texFmt;
	mWidth       = width;
	mHeight      = height;
	int dataSize = TexImg::calcDataSize(mTexFormat, mWidth, mHeight);

	mPixelData = (buf) ? buf : new (0x20) u8[(dataSize / 2) * 2];

	mWidthFactor  = 1.0f / mWidth;
	mHeightFactor = 1.0f / mHeight;

	DCStoreRange(mPixelData, dataSize);

	TexImg::getTileSize(mTexFormat, mTileSizeX, mTileSizeY);
#else
	mPixelData = (buf) ? buf : new u8[width * height * 4];
	mWidth     = width;
	mHeight    = height;
#endif
}

/**
 * @todo: Documentation
 */
void Texture::grabBuffer(int width, int height, bool enableDepth, bool useMIPmap)
{
#if PIKI_USE_DGX
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
#else
	glReadPixels(0, glnHeight - width, width, height, GL_RGBA, GL_UNSIGNED_BYTE, mPixelData);
	// Matching this REQUIRES `mAttachName` be unsigned.  This will always be true.
	if (TERNARY_BUGFIX(mAttachName >= 0, mAttachName >= 0)) /* Pending ability to test bugfix */ {
		glBindTexture(GL_TEXTURE_2D, mAttachName);
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, mPixelData);
	}
#endif
}

// TODO: High chance that this macro appears in a lot more places.  Move it somewhere better.
#define SWAP16(x) (((x) & 0xFF) << 8 | ((x) & 0xFF00) >> 8)

/**
 * @todo: Documentation
 */
void Texture::decodeData(TexImg* texImg)
{
#if PIKI_USE_DGX
	mWidth     = texImg->mWidth;
	mHeight    = texImg->mHeight;
	mTexFormat = texImg->mFormat;
	mPixelData = texImg->mTextureData;
	if (!texImg->mPixelData && texImg->mTextureData) {
		DCStoreRange(mPixelData, texImg->mDataSize);
		texImg->mPixelData = mPixelData;
	}
#else
	createBuffer(texImg->mWidth, texImg->mHeight, texImg->mFormat, texImg->mPixelData);

	if (!texImg->mPixelData) {
		PRINT("decoding data %d x %d : %08x\n", texImg->mWidth, texImg->mHeight, texImg->mTextureData);
		switch (texImg->mFormat) {
		case TEX_FMT_S3TC:
		{
			decodeS3TC(mWidth, mHeight, static_cast<u8*>(texImg->mTextureData), static_cast<u8*>(mPixelData));
			break;
		}
		case TEX_FMT_RGB5A3:
		{
			u16* gxTexData = static_cast<u16*>(texImg->mTextureData);
			for (int gxOffset = 0; gxOffset < mWidth * mHeight; ++gxOffset) {
				u8 r, g, b, a;
				u16 gxTexel = SWAP16(gxTexData[gxOffset]);
				if (gxTexel & 0x8000) {
					r = ((gxTexel >> 10) & 0x1F) << 3;
					g = ((gxTexel >> 5) & 0x1F) << 3;
					b = ((gxTexel >> 0) & 0x1F) << 3;
					a = 0xFF;
				} else {
					r = ((gxTexel >> 8) & 0x0F) << 4;
					g = ((gxTexel >> 4) & 0x0F) << 4;
					b = ((gxTexel >> 0) & 0x0F) << 4;
					a = ((gxTexel >> 12) & 0x07) << 5;
				}
				int glOffset = offsetGXtoGL(gxOffset);
				if (glOffset >= mWidth * mHeight) {
					PRINT("too big an offset!\n");
					glOffset = 0;
				}
				static_cast<u32*>(mPixelData)[glOffset] = a << 24 | b << 16 | g << 8 | r << 0;
			}
			break;
		}
		case TEX_FMT_RGB565:
		{
			u16* gxTexData = static_cast<u16*>(texImg->mTextureData);
			for (int gxOffset = 0; gxOffset < mWidth * mHeight; ++gxOffset) {
				u8 r, g, b, a;
				u16 gxTexel = SWAP16(gxTexData[gxOffset]);

				r = ((gxTexel >> 11) & 0x1F) << 3;
				g = ((gxTexel >> 5) & 0x3f) << 2;
				b = ((gxTexel >> 0) & 0x1F) << 3;
				a = 255;

				int glOffset = offsetGXtoGL(gxOffset);
				if (glOffset >= mWidth * mHeight) {
					PRINT("too big an offset!\n");
					glOffset = 0;
				}
				static_cast<u32*>(mPixelData)[glOffset] = a << 24 | b << 16 | g << 8 | r << 0;
			}
			break;
		}
		case TEX_FMT_I4:
		{
			u8* gxTexData = static_cast<u8*>(texImg->mTextureData);
			for (int gxOffset = 0; gxOffset < mWidth / 2 * mHeight; ++gxOffset) {
				u8 r, g, b, a;
				u8 gxTexel = gxTexData[gxOffset];

				// I sure do love clang-format being a nuisance because of bad decisions at the start of the project.

				r = g = b = ((gxTexel & 0xF0) >> 4) << 4;
				a         = 255;

				static_cast<u32*>(mPixelData)[offsetGXtoGL(gxOffset * 2)] = a << 24 | b << 16 | g << 8 | r << 0;

				r = g = b = ((gxTexel & 0x0F) >> 0) << 4;

				static_cast<u32*>(mPixelData)[offsetGXtoGL(gxOffset * 2 + 1)] = a << 24 | b << 16 | g << 8 | r << 0;
			}
			break;
		}
		case TEX_FMT_IA4:
		{
			u8* gxTexData = static_cast<u8*>(texImg->mTextureData);
			for (int gxOffset = 0; gxOffset < mWidth * mHeight; ++gxOffset) {
				u8 r, g, b, a;
				u8 gxTexel = gxTexData[gxOffset];

				r = g = b = ((gxTexel & 0x0F) >> 0) << 4;
				a         = ((gxTexel & 0xF0) >> 4) << 4;

				static_cast<u32*>(mPixelData)[offsetGXtoGL(gxOffset)] = a << 24 | b << 16 | g << 8 | r << 0;
			}
			break;
		}
		case TEX_FMT_IA8:
		{
			u16* gxTexData = static_cast<u16*>(texImg->mTextureData);
			for (int gxOffset = 0; gxOffset < mWidth * mHeight; ++gxOffset) {
				u8 r, g, b, a;
				u16 gxTexel = SWAP16(gxTexData[gxOffset]);

				r = g = b = gxTexel & 0x00FF;
				a         = ((gxTexel) >> 8) & 0xFF;

				static_cast<u32*>(mPixelData)[offsetGXtoGL(gxOffset)] = a << 24 | b << 16 | g << 8 | r << 0;
			}
			break;
		}
		case TEX_FMT_I8:
		{
			u8* gxTexData = static_cast<u8*>(texImg->mTextureData);
			for (int gxOffset = 0; gxOffset < mWidth * mHeight; ++gxOffset) {
				u8 r, g, b, a;
				u8 gxTexel = gxTexData[gxOffset];

				r = g = b = gxTexel;
				a         = 255;

				static_cast<u32*>(mPixelData)[offsetGXtoGL(gxOffset)] = a << 24 | b << 16 | g << 8 | r << 0;
			}
			break;
		}
		case TEX_FMT_RGBA8:
		{
			u16* gxTexData = static_cast<u16*>(texImg->mTextureData);
			int gxOffset;
			// Decode alpha + red channels
			for (gxOffset = 0; gxOffset < mWidth * mHeight; ++gxOffset) {
				u8 r, a;
				int gxOffset  = (gxOffset / 16 * 32) + (gxOffset & 0x0F);
				u16 gxTexelRA = SWAP16(gxTexData[gxOffset]);

				a = (gxTexelRA >> 8) & 0xFF;
				r = (gxTexelRA >> 0) & 0xFF;

				static_cast<u32*>(mPixelData)[offsetGXtoGL(gxOffset)] = a << 24 | r << 0;
			}
			// Decode green + blue channels
			for (gxOffset = 0; gxOffset < mWidth * mHeight; ++gxOffset) {
				u8 g, b;
				int gxOffset  = (gxOffset / 16 * 32) + (gxOffset & 0x0F);
				u16 gxTexelGB = SWAP16(gxTexData[gxOffset + 16]);

				g = (gxTexelGB >> 8) & 0xFF;
				b = (gxTexelGB >> 0) & 0xFF;

				static_cast<u32*>(mPixelData)[offsetGXtoGL(gxOffset)] |= b << 16 | g << 8;
			}
			break;
		}
		case TEX_FMT_COUNT: // what?
		{
			u8* gxTexData = static_cast<u8*>(texImg->mTextureData);
			for (int gxOffset = 0; gxOffset < mWidth * mHeight; ++gxOffset) {
				u8 r, g, b, a;
				u8 gxTexel = gxTexData[gxOffset];

				r = g = b = gxTexel;
				a         = 255;

				static_cast<u32*>(mPixelData)[offsetGXtoGL(gxOffset)] = a << 24 | b << 16 | g << 8 | r << 0;
			}
			break;
		}
		case TEX_FMT_Z8:
		default:
			ERROR("Unknown texture format\n");
			break;
		}
		texImg->mPixelData = mPixelData;
	}
#endif
}
