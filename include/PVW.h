#ifndef _PVW_H
#define _PVW_H

#include "types.h"
#include "Colour.h"
#include "Vector.h"
#include "Matrix4f.h"

struct Matrix4f;
struct RandomAccessStream;
struct ShortColour;
struct TexAttr;
struct Texture;

/**
 * @brief TODO
 */
struct PVWKeyInfoU8 {

	void read(RandomAccessStream& input)
	{
		_00 = input.readByte();
		input.readByte();
		input.readByte();
		input.readByte();
		_04 = input.readFloat();
		_08 = input.readFloat();
	}

	u8 _00;  // _00
	f32 _04; // _04
	f32 _08; // _08
};

/**
 * @brief TODO
 */
struct PVWKeyInfoS10 {
	void read(RandomAccessStream& input)
	{
		_00        = input.readShort();
		u16 unused = input.readShort();
		_04        = input.readFloat();
		_08        = input.readFloat();
	}

	s16 _00; // _00
	f32 _04; // _04
	f32 _08; // _08
};

struct PVWKeyInfoF32 {
	void read(RandomAccessStream& input)
	{
		_00 = input.readFloat();
		_04 = input.readFloat();
		_08 = input.readFloat();
	}

	f32 _00; // _00
	f32 _04; // _04
	f32 _08; // _08
};

template <typename T>
struct PVWAnimInfo1Intermediate {
	void read(RandomAccessStream& input)
	{
		_00 = input.readInt();
		_04.read(input);
	}

	u32 _00; // _00
	T _04;   // _04
};

template <typename T>
struct PVWAnimInfo3Intermediate {
	void read(RandomAccessStream& input)
	{
		_00 = input.readInt();
		_04.read(input);
		_14.read(input);
		_24.read(input);
	}

	u32 _00; // _00
	T _04;   // _04
	T _14;   // _14
	T _24;   // _24
};

template <typename T>
struct PVWAnimInfo1 {
	u32 mSize;                               // _00
	PVWAnimInfo1Intermediate<T>* mKeyframes; // _04

	void read(RandomAccessStream& stream)
	{
		mSize = stream.readInt();

		if (!mSize) {
			return;
		}

		mKeyframes = new PVWAnimInfo1Intermediate<T>[mSize];
		for (int i = 0; i < mSize; i++) {
			mKeyframes[i].read(stream);
		}
	}
};

template <typename T>
struct PVWAnimInfo3 {
	u32 mSize;                               // _00
	PVWAnimInfo3Intermediate<T>* mKeyframes; // _04

	void read(RandomAccessStream& stream)
	{
		mSize = stream.readInt();

		if (!mSize) {
			return;
		}

		mKeyframes = new PVWAnimInfo3Intermediate<T>[mSize];
		for (int i = 0; i < (int)mSize; i++) {
			mKeyframes[i].read(stream);
		}
	}
};

/**
 * @brief TODO
 * @note Size: 0xC.
 */
struct PVWLightingInfo {
	PVWLightingInfo()
	{
		_04 = 1;
		_00 = 1;
		_08 = 50.0f;
	}

	void read(RandomAccessStream&);

	u32 _00; // _00
	u32 _04; // _04
	f32 _08; // _08
};

struct AKeyInfo {
	AKeyInfo(f32 pos, f32 val, f32 inTan, f32 outTan)
	    : mKeyframePosition(pos)
	    , mValue(val)
	    , mEndTangent(inTan)
	    , mStartTangent(outTan)
	{
	}

	f32 mKeyframePosition; // _00
	f32 mValue;            // _04
	f32 mEndTangent;       // _08
	f32 mStartTangent;     // _0C
};

/**
 * @brief TODO
 * @note Size: 0x8.
 */
struct PVWColourAnimInfo {
	void extract(f32, Colour&);

	void read(RandomAccessStream& input) { mAnimInfo.read(input); }

	PVWAnimInfo3<PVWKeyInfoU8> mAnimInfo; // _00
};

/**
 * @brief TODO
 *
 */
struct PVWAlphaAnimInfo {
	void extract(f32, Colour&);

	void read(RandomAccessStream& input) { mAnimInfo.read(input); }

	PVWAnimInfo1<PVWKeyInfoU8> mAnimInfo; // _00
};

/**
 * @brief A class that contains information about a polygon's colour during animation.
 * @note Size: 0x20.
 */
struct PVWPolygonColourInfo {
	PVWPolygonColourInfo() { mCurrentFrame = 0.0f; }

	void animate(f32*, Colour&);

	void read(RandomAccessStream& input)
	{
		mColour.read(input);
		mTotalFrameCount = input.readInt();
		mSpeed           = input.readFloat();
		mColourInfo.read(input);
		mAlphaInfo.read(input);
	}

	Colour mColour;                // _00
	u32 mTotalFrameCount;          // _04
	f32 mSpeed;                    // _08
	PVWColourAnimInfo mColourInfo; // _0C
	PVWAlphaAnimInfo mAlphaInfo;   // _14
	f32 mCurrentFrame;             // _1C
};

/**
 * @brief TODO
 */
struct PVWColourShortAnimInfo {
	void extract(f32, ShortColour&);
};

/**
 * @brief TODO
 */
struct PVWAlphaShortAnimInfo {
	void extract(f32, ShortColour&);
};

/**
 * @brief TODO
 */
struct PVWTexAnimInfo {
	void extract(f32, Vector3f&);
};

struct PVWTextureData;
struct PVWTexGenData;

/**
 * @brief TODO
 * @note Size: 0x24.
 */
struct PVWTextureInfo {
	PVWTextureInfo()
	{
		mTevStageCount   = 0;
		mTexGenDataCount = 0;
	}

	void read(RandomAccessStream&);

	Vector3f _00;                 // _00
	u32 mTextureDataCount;        // _0C
	u32 mTexGenDataCount;         // _10
	u32 _14;                      // _14
	u32 mTevStageCount;           // _18
	PVWTextureData* mTextureData; // _1C
	PVWTexGenData* mTexGenData;   // _20
};

/**
 * @brief TODO
 */
struct PVWTevColReg {
	PVWTevColReg() { _20 = 0.0f; }

	void animate(f32*, ShortColour&);

	void read(RandomAccessStream& input)
	{
		mAnimatedColor.read(input);
		mIsAnimEnabled = input.readInt();
		_0C            = input.readFloat();
		_10.read(input);
		_18.read(input);
	}

	ShortColour mAnimatedColor;      // _00
	u32 mIsAnimEnabled;              // _08, unknown
	f32 _0C;                         // _0C
	PVWAnimInfo3<PVWKeyInfoS10> _10; // _10
	PVWAnimInfo1<PVWKeyInfoS10> _18; // _10
	f32 _20;                         // _20
};

/**
 * @brief TODO
 */
struct PVWCombiner {
	void read(RandomAccessStream& input)
	{
		_00 = input.readByte();
		_01 = input.readByte();
		_02 = input.readByte();
		_03 = input.readByte();
		_04 = input.readByte();
		_05 = input.readByte();
		_06 = input.readByte();
		_07 = input.readByte();
		_08 = input.readByte();
		_09 = input.readByte();
		_0A = input.readByte();
		_0B = input.readByte();
	}

	u8 _00; // _00
	u8 _01; // _01
	u8 _02; // _02
	u8 _03; // _03
	u8 _04; // _04
	u8 _05; // _05
	u8 _06; // _06
	u8 _07; // _07
	u8 _08; // _08
	u8 _09; // _09
	u8 _0A; // _0A
	u8 _0B; // _0B
};

/**
 * @brief TODO
 */
struct PVWTevStage {
	void read(RandomAccessStream& input)
	{
		_00        = input.readByte();
		_01        = input.readByte();
		_02        = input.readByte();
		_03        = input.readByte();
		_04        = input.readByte();
		_05        = input.readByte();
		u8 unused  = input.readByte();
		u8 unused2 = input.readByte();
		_06.read(input);
		_12.read(input);
	}

	u8 _00;          // _00
	u8 _01;          // _01
	u8 _02;          // _02
	u8 _03;          // _03
	u8 _04;          // _04
	u8 _05;          // _05
	PVWCombiner _06; // _06
	PVWCombiner _12; // _12
};

/**
 * @brief TODO
 *
 * @note Size: 0x84.
 */
struct PVWTevInfo {
	void read(RandomAccessStream& input)
	{
		mTevColRegs[0].read(input);
		mTevColRegs[1].read(input);
		mTevColRegs[2].read(input);
		_6C[0].read(input);
		_6C[1].read(input);
		_6C[2].read(input);
		_6C[3].read(input);
		mTevStageCount = input.readInt();
		if (mTevStageCount) {
			mTevStages = new PVWTevStage[mTevStageCount];
			for (int i = 0; i < mTevStageCount; i++) {
				mTevStages[i].read(input);
			}
		}
	}

	PVWTevColReg mTevColRegs[3]; // _00
	Colour _6C[4];               // _6C
	u32 mTevStageCount;          // _7C
	PVWTevStage* mTevStages;     // _80
};

/**
 * @brief TODO
 * @note Size: 0x9C.
 */
struct PVWTextureData {
	PVWTextureData()
	{
		_58      = 0.0f;
		mTexture = nullptr;
		_16      = 0;
	}

	void animate(f32*, Matrix4f&);
	void read(RandomAccessStream&);

	u32 mSourceAttrIndex;            // _00
	TexAttr* mTextureAttribute;      // _04
	Texture* mTexture;               // _08
	u16 _0C;                         // _0C
	u16 _0E;                         // _0E
	u8 _10;                          // _10
	u8 _11;                          // _11
	u8 _12;                          // _12
	u8 _13;                          // _13
	u8 mAnimationFactor;             // _14
	u8 _15;                          // _15
	u8 _16;                          // _16
	u32 _18;                         // _18
	f32 _1C;                         // _1C
	f32 _20;                         // _20
	f32 _24;                         // _24
	f32 _28;                         // _28
	f32 _2C;                         // _2C
	f32 _30;                         // _30
	f32 _34;                         // _34
	u32 _38;                         // _38
	f32 _3C;                         // _3C
	PVWAnimInfo3<PVWKeyInfoF32> _40; // _40
	PVWAnimInfo3<PVWKeyInfoF32> _48; // _48
	PVWAnimInfo3<PVWKeyInfoF32> _50; // _50
	f32 _58;                         // _58
	Matrix4f mAnimatedTexMtx;        // _5C
};

/**
 * @brief TODO
 */
struct PVWTexGenData {
	// unused/inlined:
	void read(RandomAccessStream& input);

	u8 _00; // _00
	u8 _01; // _01
	u8 _02; // _02
	u8 _03; // _03
};

/**
 * @brief TODO
 * @note Size: 0x10.
 */
struct PVWPeInfo {
	void read(RandomAccessStream& input)
	{
		mControlFlags      = input.readInt();
		mAlphaCompareFlags = input.readInt();
		mDepthTestFlags    = input.readInt();
		mBlendModeFlags    = input.readInt();
	}

	u32 mControlFlags;      // _00
	u32 mAlphaCompareFlags; // _04
	u32 mDepthTestFlags;    // _08
	u32 mBlendModeFlags;    // _0C
};

#endif
