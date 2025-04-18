#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "CoreNode.h"
#include "GfxObject.h"
#include "Dolphin/gx.h"
#include "Ayu.h"

struct Texture;
struct TexImg;
struct Colour;
struct TexobjInfo;

/**
 * @brief TODO
 */
enum TexImgFormat {
	TEX_FMT_RGB565 = 0,
	TEX_FMT_S3TC   = 1,
	TEX_FMT_RGB5A3 = 2,
	TEX_FMT_I4     = 3,
	TEX_FMT_I8     = 4,
	TEX_FMT_IA4    = 5,
	TEX_FMT_IA8    = 6,
	TEX_FMT_RGBA8  = 7,
	TEX_FMT_Z8     = 8,
	TEX_FMT_COUNT, // 9
};

/**
 * @brief TODO
 */
struct TexAttr : public CoreNode {
	enum TilingType {
		TILING_REPEAT = 0,
		TILING_CLAMP  = 1,
	};

	enum Flags {
		FLAG_EDG = 2,
		FLAG_XLU = 4,
	};

	TexAttr()
	    : CoreNode("texattr")
	{
		mTextureName = nullptr;
		mTexture     = nullptr;
		mImage       = nullptr;
		mTilingType  = TILING_REPEAT;
		_20          = 0;
		_24          = 0.0f;
	}

	virtual void read(RandomAccessStream&); // _0C

	void initImage();

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mIndex;         // _14
	int mTextureIndex;  // _18
	s16 mTilingType;    // _1C
	s16 mFlags;         // _1E
	u16 _20;            // _20
	s16 _22;            // _22
	f32 _24;            // _24
	char* mTextureName; // _28
	Texture* mTexture;  // _2C
	TexImg* mImage;     // _30
};

/**
 * @brief TODO
 */
struct TexImg : public CoreNode {
	TexImg()
	    : CoreNode("texImg")
	{
		_24        = 1;
		mPixelData = nullptr;
	}

	void read(RandomAccessStream&);
	void importBti(Texture*, RandomAccessStream&, u8*);
	void importTxe(Texture*, RandomAccessStream&);

	static int calcDataSize(int texFmt, int width, int height);
	static void getTileSize(int texFmt, u32& tileSizeX, u32& tileSizeY);
	static char* formatName(u32 texFmt);

	// unused/inlined:
	void convFormat(u32);
	void setColour(Colour&);
	void readTexData(Texture*, RandomAccessStream&, u8*);
	void dumpBti(Texture*, char*, RandomAccessStream&, RandomAccessStream&);

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mIndex;           // _14
	TexImgFormat mFormat; // _18
	int mWidth;           // _1C
	int mHeight;          // _20
	int _24;              // _24
	int mDataSize;        // _28
	void* mTextureData;   // _2C
	void* mPixelData;     // _30
};

/**
 * @brief TODO
 *
 * @note Size: 0x3C.
 */
struct Texture : public GfxObject {
	/**
	 * @brief TODO
	 */
	enum TexFlags {
		TEX_CLAMP_S  = 1 << 0, //  0x1
		TEX_MIRROR_S = 1 << 1, // 0x2
		TEX_Unk2     = 1 << 2, // 0x4
		TEX_Unk3     = 1 << 3, // 0x8
		TEX_Unk4     = 1 << 4, // 0x10
		TEX_Unk5     = 1 << 5, // 0x20
		TEX_Unk6     = 1 << 6, // 0x40
		TEX_Unk7     = 1 << 7, // 0x80
		TEX_CLAMP_T  = 1 << 8, // 0x100
		TEX_MIRROR_T = 1 << 9, // 0x200
	};

	Texture();

	virtual void attach();          // _08
	virtual void detach();          // _0C
	virtual void makeResident() { } // _10 (weak)

	u8 getAlpha(int x, int y);
	void read(RandomAccessStream& input);
	void createBuffer(int width, int height, int texFmt, void* buf);
	void grabBuffer(int width, int height, bool doClear, bool useMIPmap);
	void decodeData(TexImg* texImg);

	// unused/inlined:
	void offsetGLtoGX(int, int);
	u8 getRed(int, int);

	// _00 = VTBL
	u16 mTexFormat;    // _04, see TexImgFormat enum
	u16 mTexFlags;     // _06
	u16 mWidth;        // _08
	u16 mHeight;       // _0A
	u32 mTileSizeX;    // _0C
	u32 mTileSizeY;    // _10
	void* mPixelData;  // _14
	u32* mTextureData; // _18
	f32 mLODBias;      // _1C
	u32 _20;           // _20, -1 if detached, 0 if attached
	GXTexObj* mTexObj; // _24
	f32 mWidthFactor;  // _28, 1.0f / width
	f32 mHeightFactor; // _2C, 1.0f / height
	u32 _30;           // _30
	u32 _34;           // _34, unknown
	TexobjInfo* mInfo; // _38
};

struct Texture;

/**
 * @brief TODO
 */
struct TexobjInfo : public GfxobjInfo {
	TexobjInfo()
	    : mTexture(nullptr)
	{
	}

	virtual void attach() { mTexture->attach(); } // _08
	virtual void detach() { mTexture->detach(); } // _0C

	// _1C     = VTBL
	// _00-_1C = GfxobjInfo
	GfxObject* mTexture; // _20,  yes this is a GfxObject*, not a Texture*
};

struct CacheInfo {
	void insertAfter(CacheInfo* other)
	{
		other->mNext = mNext;
		other->mPrev = this;

		mNext->mPrev = other;
		mNext        = other;
	}

	void remove()
	{
		mNext->mPrev = mPrev;
		mPrev->mNext = mNext;
	}

	char* mName;      // _00
	CacheInfo* mPrev; // _04
	CacheInfo* mNext; // _08
};

/**
 * @note Size: 0x14
 */
struct TexCacheInfo : public CacheInfo {
	TexCacheInfo() { initData(); }

	void initData() { _10 = 0; }

	// _00 - _0C = CacheInfo
	TexobjInfo* _0C; // _0C
	u32 _10;         // _10
};

/**
 * @brief TODO
 * @note Size: 0x4C
 */
struct CacheTexture : public Texture {
	CacheTexture()
	{
		mCacheInfo = nullptr;
		mTexImage  = 0;
		_40        = 0;
	}

	virtual void makeResident(); // _10

	// _00     = VTBL
	// _00-_3C = Texture
	TexCacheInfo* mCacheInfo; // _3C
	TexCacheInfo* _40;        // _40
	TexImg* mTexImage;        // _44
	u32 _48;                  // _48
};

/**
 * @brief TODO
 */
struct TextureCacher : public TexCacheInfo {
	TextureCacher(u32 size)
	{
		mCache = new AyuCache(size);
		mName  = "root";
		mPrev  = this;
		mNext  = this;
	}

	void updateInfo(CacheTexture*);
	void purgeAll();
	void removeOldest();
	void cacheTexture(CacheTexture*);

	// _00 - _10 = TexCacheInfo
	AyuCache* mCache; // _14
};

#endif
