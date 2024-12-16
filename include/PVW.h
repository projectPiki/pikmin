#ifndef _PVW_H
#define _PVW_H

#include "types.h"

struct Colour;
struct Matrix4f;
struct RandomAccessStream;
struct ShortColour;
struct Vector3f;

/**
 * @brief TODO
 */
struct PVWKeyInfoU8 {
	u8 _00;  // _00
	f32 _04; // _04
	f32 _08; // _08
};

/**
 * @brief TODO
 */
struct PVWKeyInfoS10 {
};

struct PVWKeyInfoF32 {
	f32 _00; // _00
	f32 _04; // _04
	f32 _08; // _08
};

/**
 * @brief TODO
 */
struct PVWLightingInfo {
	// unused/inlined:
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

struct PVWColourKeyframe {
	int _00;
	char _04;
	int _08;
	int _0C;
	char _10;
	int _14;
	int _18;
	f32 _1C;
};

/**
 * @brief TODO
 * @note Size: 0x8.
 */
struct PVWColourAnimInfo {
	void extract(f32, Colour&);

	u32 mTotalFrameCount; // _00
	f32* _04;             // _04, guessed type
};

/**
 * @brief TODO
 *
 */
struct PVWAlphaAnimInfo {
	void extract(f32, Colour&);

	u32 _00; // _00
	u32 _04; // _04
};

/**
 * @brief TODO
 */
struct PVWPolygonColourInfo : Colour {
	void animate(f32*, Colour&);

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
template <typename T>
struct PVWAnimInfo1 {
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
template <typename T>
struct PVWAnimInfo3 {
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWTexAnimInfo {
	void extract(f32, Vector3f&);
};

/**
 * @brief TODO
 */
struct PVWTextureInfo {
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWTevInfo {
};

/**
 * @brief TODO
 */
struct PVWTextureData {
	PVWTextureData();

	void animate(f32*, Matrix4f&);
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWTexGenData {
	// unused/inlined:
	void read(RandomAccessStream&);
};

/**
 * @brief TODO
 */
struct PVWTevColReg {
	PVWTevColReg();

	void animate(f32*, ShortColour&);
};

/**
 * @brief TODO
 */
struct PVWTevStage {
	void read(RandomAccessStream&);
};

#endif
