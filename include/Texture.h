#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "CoreNode.h"
#include "GfxObject.h"

struct Texture;
struct TexImg;
struct Colour;

enum TexImgFormat {
	TEX_FMT_RGB565 = 0,
	TEX_FMT_S3TC,
	TEX_FMT_RGB5A3,
	TEX_FMT_I4,
	TEX_FMT_I8,
	TEX_FMT_IA4,
	TEX_FMT_IA8,
	TEX_FMT_RGBA8,
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

	TexAttr();

	virtual void read(RandomAccessStream&); // _0C

	void initImage();

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mIndex;        // _14
	int mTextureIndex; // _18
	s16 mTilingType;   // _1C
	s16 mFlags;        // _1E
	s16 _20;           // _20
	s16 _22;           // _22
	f32 _24;           // _24
	char* mName;       // _28
	Texture* mTexture; // _2C
	TexImg* mImage;    // _30
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

	void calcDataSize(int, int, int);
	void read(RandomAccessStream&);
	void getTileSize(int, u32&, u32&);
	void importBti(Texture*, RandomAccessStream&, u8*);
	void importTxe(Texture*, RandomAccessStream&);

	// unused/inlined:
	void convFormat(u32);
	void formatName(u32);
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
 */
struct Texture : public GfxObject {
	Texture();

	virtual void attach();          // _08
	virtual void detach();          // _0C
	virtual void makeResident() { } // _10 (weak)

	u16 getAlpha(int, int);
	void read(RandomAccessStream&);
	void createBuffer(int, int, int, void*);
	void grabBuffer(int, int, bool, bool);
	void decodeData(TexImg*);

	// unused/inlined:
	void offsetGLtoGX(int, int);
	void getRed(int, int);

	// _00 = VTBL
	u16 _04;           // _04
	s16 _06;           // _06
	u16 mWidth;        // _08
	u16 mHeight;       // _0A
	u32 mTileSizeX;    // _0C
	u32 mTileSizeY;    // _10
	void* mPixelData;  // _14
	u32* mTextureData; // _18
	f32 _1C;           // _1C
	int _20;           // _20
	void* _24;         // _24, pointer to something of size 0x20
	int _28;           // _28
	int _2C;           // _2C
	int _30;           // _30
	int _34;           // _34
};

/**
 * @brief TODO
 */
struct TexobjInfo : public GfxobjInfo {
	virtual void attach() { mTexture->attach(); } // _08
	virtual void detach() { mTexture->detach(); } // _0C

	// _20     = VTBL
	// _00-_20 = GfxobjInfo
	GfxObject* mTexture; // _20,  yes this is a GfxObject*, not a Texture*
};

/**
 * @brief TODO
 */
struct CacheTexture : public Texture {
	virtual void makeResident(); // _10

	// _00     = VTBL
	// _00-_34 = Texture
	// TODO: members
};

/**
 * @brief TODO
 */
struct TextureCacher {
	void updateInfo(CacheTexture*);
	void purgeAll();
	void removeOldest();
	void cacheTexture(CacheTexture*);

	// TODO: members
};

#endif
