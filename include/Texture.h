#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "CoreNode.h"

struct Texture;

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

	virtual void read(RandomAccessStream&); // _0C

	// _00     = VTBL
	// _00-_14 = CoreNode
	int mIndex;        // _14
	int mTextureIndex; // _18
	short mTilingType; // _1C
	short mFlags;      // _1E
	short _20;         // _20
	short _22;         // _22
	float _24;         // _24
	char* mName;       // _28
	Texture* mTexture; // _2C
	TexImg* mImage;    // _30
};

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

struct TexImg : public CoreNode {
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

struct Texture {
	virtual void attach();       // _08
	virtual void detach();       // _0C
	virtual void makeResident(); // _10 (weak)

	Texture();
	void getAlpha(int, int);
	void read(RandomAccessStream&);
	void createBuffer(int, int, int, void*);
	void grabBuffer(int, int, bool, bool);
	void decodeData(TexImg*);

	// _00 = VTBL
	short _04;         // _04
	short _06;         // _06
	short mWidth;      // _08
	short mHeight;     // _0A
	int mTileSizeX;    // _0C
	int mTileSizeY;    // _10
	void* mPixelData;  // _14
	u32* mTextureData; // _18
	float _1C;         // _1C
	float _20;         // _20
	int _24;           // _24
	int _28;           // _28
	int _2C;           // _2C
	int _30;           // _30
};

#endif
