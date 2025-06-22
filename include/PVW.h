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
		mTime = input.readByte();
		input.readByte();
		input.readByte();
		input.readByte();
		mValue   = input.readFloat();
		mTangent = input.readFloat();
	}

	u8 mTime;     // _00
	f32 mValue;   // _04
	f32 mTangent; // _08
};

/**
 * @brief TODO
 */
struct PVWKeyInfoS10 {
	void read(RandomAccessStream& input)
	{
		mTime       = input.readShort();
		u16 padding = input.readShort();
		mValue      = input.readFloat();
		mTangent    = input.readFloat();
	}

	s16 mTime;    // _00
	f32 mValue;   // _04
	f32 mTangent; // _08
};

struct PVWKeyInfoF32 {
	void read(RandomAccessStream& input)
	{
		mTime    = input.readFloat();
		mValue   = input.readFloat();
		mTangent = input.readFloat();
	}

	f32 mTime;    // _00
	f32 mValue;   // _04
	f32 mTangent; // _08
};

template <typename T>
struct PVWAnimInfo1Intermediate {
	void read(RandomAccessStream& input)
	{
		mTime = input.readInt();
		mData.read(input);
	}

	u32 mTime; // _00
	T mData;   // _04
};

template <typename T>
struct PVWAnimInfo3Intermediate {
	void read(RandomAccessStream& input)
	{
		mTime = input.readInt();
		mRedData.read(input);
		mGreenData.read(input);
		mBlueData.read(input);
	}

	u32 mTime;    // _00
	T mRedData;   // _04
	T mGreenData; // _14
	T mBlueData;  // _24
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
 * @brief Lighting control flags for PVW materials
 */
DEFINE_ENUM_TYPE(LightingControlFlags,
                 EnableColor0   = 0x0001, ///< Enable lighting for color channel 0
                 EnableSpecular = 0x0002, ///< Enable specular lighting (color channel 1)
                 EnableAlpha0   = 0x0004, ///< Enable lighting for alpha channel 0

                 DiffFnColor0Shift   = 3, ///< Diffuse function for color 0 (bits 3-4)
                 DiffFnAlpha0Shift   = 5, ///< Diffuse function for alpha 0 (bits 5-6)
                 DiffFnSpecularShift = 7, ///< Diffuse function for specular (bits 7-8)

                 AmbSrcColor0Vtx = 0x0200, ///< Use vertex color for ambient color 0 (vs register)
                 AmbSrcAlpha0Vtx = 0x0400, ///< Use vertex alpha for ambient alpha 0 (vs register)
                 MatSrcColor0Vtx = 0x0800, ///< Use vertex color for material color 0 (vs register)
                 MatSrcAlpha0Vtx = 0x1000, ///< Use vertex alpha for material alpha 0 (vs register)
);

/**
 * @brief TODO
 * @note Size: 0xC.
 */
struct PVWLightingInfo {
	PVWLightingInfo()
	{
		mNumChans = 1;
		mCtrlFlag = LightingControlFlags::EnableColor0;
		_UNUSED08 = 50.0f;
	}

	void read(RandomAccessStream&);

	u32 mCtrlFlag; // _00, see LightingControlFlags enum
	u32 mNumChans; // _04
	f32 _UNUSED08; // _08
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

	PVWAnimInfo3<PVWKeyInfoS10> mInfo; // _00
};

/**
 * @brief TODO
 */
struct PVWAlphaShortAnimInfo {
	void extract(f32, ShortColour&);

	PVWAnimInfo1<PVWKeyInfoS10> mInfo; // _00
};

/**
 * @brief TODO
 */
struct PVWTexAnimInfo {
	void extract(f32, Vector3f&);

	PVWAnimInfo3<PVWKeyInfoF32> mInfo; // _00
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

	Vector3f mScale;              // _00
	u32 mTextureDataCount;        // _0C
	u32 mTexGenDataCount;         // _10
	u32 mUseScale;                // _14
	u32 mTevStageCount;           // _18
	PVWTextureData* mTextureData; // _1C
	PVWTexGenData* mTexGenData;   // _20
};

/**
 * @brief TODO
 */
struct PVWTevColReg {
	PVWTevColReg() { mCurrentAnimFrame = 0.0f; }

	void animate(f32*, ShortColour&);

	void read(RandomAccessStream& input)
	{
		mAnimatedColor.read(input);
		mAnimFrameCount = input.readInt();
		mAnimSpeed      = input.readFloat();
		mColorAnimData.mInfo.read(input);
		mAlphaAnimData.mInfo.read(input);
	}

	ShortColour mAnimatedColor;            // _00
	u32 mAnimFrameCount;                   // _08
	f32 mAnimSpeed;                        // _0C
	PVWColourShortAnimInfo mColorAnimData; // _10
	PVWAlphaShortAnimInfo mAlphaAnimData;  // _10
	f32 mCurrentAnimFrame;                 // _20
};

/**
 * @brief TODO
 */
struct PVWCombiner {
	void read(RandomAccessStream& input)
	{
		mInArgA   = input.readByte();
		mInArgB   = input.readByte();
		mInArgC   = input.readByte();
		mInArgD   = input.readByte();
		mTevOp    = input.readByte();
		mBias     = input.readByte();
		mScale    = input.readByte();
		mDoClamp  = input.readByte();
		mOutReg   = input.readByte();
		_UNUSED09 = input.readByte();
		_UNUSED0A = input.readByte();
		_UNUSED0B = input.readByte();
	}

	u8 mInArgA;   // _00
	u8 mInArgB;   // _01
	u8 mInArgC;   // _02
	u8 mInArgD;   // _03
	u8 mTevOp;    // _04
	u8 mBias;     // _05
	u8 mScale;    // _06
	u8 mDoClamp;  // _07
	u8 mOutReg;   // _08
	u8 _UNUSED09; // _09
	u8 _UNUSED0A; // _0A
	u8 _UNUSED0B; // _0B
};

/**
 * @brief TODO
 */
struct PVWTevStage {
	void read(RandomAccessStream& input)
	{
		_UNUSED00     = input.readByte();
		mTexCoordID   = input.readByte();
		mTexMapID     = input.readByte();
		mChannelID    = input.readByte();
		mTevKColorSel = input.readByte();
		mTevKAlphaSel = input.readByte();
		u8 unused     = input.readByte();
		u8 unused2    = input.readByte();
		mTevColorCombiner.read(input);
		mTevAlphaCombiner.read(input);
	}

	u8 _UNUSED00;                  // _00
	u8 mTexCoordID;                // _01
	u8 mTexMapID;                  // _02
	u8 mChannelID;                 // _03
	u8 mTevKColorSel;              // _04
	u8 mTevKAlphaSel;              // _05
	PVWCombiner mTevColorCombiner; // _06
	PVWCombiner mTevAlphaCombiner; // _12
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
		mKonstColors[0].read(input);
		mKonstColors[1].read(input);
		mKonstColors[2].read(input);
		mKonstColors[3].read(input);
		mTevStageCount = input.readInt();
		if (mTevStageCount) {
			mTevStages = new PVWTevStage[mTevStageCount];
			for (int i = 0; i < mTevStageCount; i++) {
				mTevStages[i].read(input);
			}
		}
	}

	PVWTevColReg mTevColRegs[3]; // _00
	Colour mKonstColors[4];      // _6C
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
		mCurrentFrame  = 0.0f;
		mTexture       = nullptr;
		mIsMatrixDirty = 0;
	}

	void animate(f32*, Matrix4f&);
	void read(RandomAccessStream&);

	u32 mSourceAttrIndex;            // _00
	TexAttr* mTextureAttribute;      // _04
	Texture* mTexture;               // _08
	u16 _UNUSED0C;                   // _0C
	u16 _UNUSED0E;                   // _0E
	u8 _UNUSED10;                    // _10
	u8 _UNUSED11;                    // _11
	u8 _UNUSED12;                    // _12
	u8 _UNUSED13;                    // _13
	u8 mAnimationFactor;             // _14
	u8 _UNUSED15;                    // _15
	u8 mIsMatrixDirty;               // _16
	u32 _UNUSED18;                   // _18
	f32 mScaleX;                     // _1C
	f32 mScaleY;                     // _20
	f32 mRotationZ;                  // _24
	f32 mTranslationX;               // _28
	f32 mTranslationY;               // _2C
	f32 mPivotX;                     // _30
	f32 mPivotY;                     // _34
	u32 mTotalFrameCount;            // _38
	f32 mAnimSpeed;                  // _3C
	PVWTexAnimInfo mScaleInfo;       // _40
	PVWTexAnimInfo mRotationInfo;    // _48
	PVWTexAnimInfo mTranslationInfo; // _50
	f32 mCurrentFrame;               // _58
	Matrix4f mAnimatedTexMtx;        // _5C
};

/**
 * @brief TODO
 */
struct PVWTexGenData {
	// unused/inlined:
	void read(RandomAccessStream& input);

	u8 mTexCoordID; // _00
	u8 mTexGenType; // _01
	u8 mTexGenSrc;  // _02
	u8 mMatrixType; // _03
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
