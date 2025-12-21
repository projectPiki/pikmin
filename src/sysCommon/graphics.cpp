#include "Graphics.h"

#include "Collision.h"
#include "Colour.h"
#include "DebugLog.h"
#include "Font.h"
#include "Material.h"
#include "PVW.h"
#include "Plane.h"
#include "Shape.h"
#include "Texture.h"
#include "nlib/Math.h"
#include "stl/math.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(17)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("Graphics");

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void Colour::write(Stream& s)
{
	r = s.readByte();
	g = s.readByte();
	b = s.readByte();
	a = s.readByte();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void PVWLightingInfo::read(RandomAccessStream& s)
{
	mCtrlFlag = s.readInt();
	_UNUSED08 = s.readFloat();
}

/*
 * --INFO--
 * Address:	80025914
 * Size:	000120
 */
void PVWPolygonColourInfo::animate(f32* data, Colour& col)
{
	// If there is no animation loaded, don't do anything
	if (mTotalFrameCount == 0) {
		return;
	}

	if (data) {
		mCurrentFrame = std::fmodf(data[0], mTotalFrameCount);
	} else {
		// If no new data is provided, increment the current frame
		mCurrentFrame += gsys->getFrameTime() * (30.0f * mSpeed);

		// Wrap around if we've reached the end of the animation
		if (mCurrentFrame >= mTotalFrameCount - 1) {
			mCurrentFrame = 0.0f;
		}
	}

	// Animate colour and transparency separately
	mColourInfo.extract(mCurrentFrame, col);
	mAlphaInfo.extract(mCurrentFrame, col);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
 */
f32 subExtract(f32 time, immut AKeyInfo& src, immut AKeyInfo& dest)
{
	f32 a = time - src.mKeyframePosition;
	f32 b = 1.0f / (dest.mKeyframePosition - src.mKeyframePosition);
	f32 c = (a * a) * b;
	f32 d = c * b;
	f32 e = a * d;
	f32 f = e * b;

	f32 result = (2.0f * f - 3.0f * d + 1.0f) * src.mValue + (-2.0f * f + 3.0f * d) * dest.mValue + (e - 2.0f * c + a) * src.mStartTangent
	           + (e - c) * dest.mEndTangent;
	return result;
}

/*
 * --INFO--
 * Address:	80025A34
 * Size:	000498
 */
void PVWColourAnimInfo::extract(f32 value, Colour& target)
{
	// If there is no animation data, return without modification
	if (mAnimInfo.mSize == 0) {
		return;
	}

	if (mAnimInfo.mSize == 1) {
		target.r = mAnimInfo.mKeyframes[0].mRedData.mTime;
		target.g = mAnimInfo.mKeyframes[0].mGreenData.mTime;
		target.b = mAnimInfo.mKeyframes[0].mBlueData.mTime;
		return;
	}

	int idx = 0;
	for (int i = 0; i < (int)mAnimInfo.mSize - 1; i++) {
		if (mAnimInfo.mKeyframes[i].mTime <= value && mAnimInfo.mKeyframes[i + 1].mTime >= value) {
			idx = i;
			break;
		}
	}

	f32 red   = subExtract(value,
	                       AKeyInfo(mAnimInfo.mKeyframes[idx].mTime, mAnimInfo.mKeyframes[idx].mRedData.mTime,
	                                mAnimInfo.mKeyframes[idx].mRedData.mValue, mAnimInfo.mKeyframes[idx].mRedData.mTangent),
	                       AKeyInfo(mAnimInfo.mKeyframes[idx + 1].mTime, mAnimInfo.mKeyframes[idx + 1].mRedData.mTime,
	                                mAnimInfo.mKeyframes[idx + 1].mRedData.mValue, mAnimInfo.mKeyframes[idx + 1].mRedData.mTangent));
	f32 green = subExtract(value,
	                       AKeyInfo(mAnimInfo.mKeyframes[idx].mTime, mAnimInfo.mKeyframes[idx].mGreenData.mTime,
	                                mAnimInfo.mKeyframes[idx].mGreenData.mValue, mAnimInfo.mKeyframes[idx].mGreenData.mTangent),
	                       AKeyInfo(mAnimInfo.mKeyframes[idx + 1].mTime, mAnimInfo.mKeyframes[idx + 1].mGreenData.mTime,
	                                mAnimInfo.mKeyframes[idx + 1].mGreenData.mValue, mAnimInfo.mKeyframes[idx + 1].mGreenData.mTangent));
	f32 blue  = subExtract(value,
	                       AKeyInfo(mAnimInfo.mKeyframes[idx].mTime, mAnimInfo.mKeyframes[idx].mBlueData.mTime,
	                                mAnimInfo.mKeyframes[idx].mBlueData.mValue, mAnimInfo.mKeyframes[idx].mBlueData.mTangent),
	                       AKeyInfo(mAnimInfo.mKeyframes[idx + 1].mTime, mAnimInfo.mKeyframes[idx + 1].mBlueData.mTime,
	                                mAnimInfo.mKeyframes[idx + 1].mBlueData.mValue, mAnimInfo.mKeyframes[idx + 1].mBlueData.mTangent));

	int r;
	if (red < 0.0f) {
		r = 0;
	} else if (red > 255.0f) {
		r = 255;
	} else {
		r = (u8)red;
	}

	target.r = r;

	int g;
	if (green < 0.0f) {
		g = 0;
	} else if (green > 255.0f) {
		g = 255;
	} else {
		g = (u8)green;
	}

	target.g = g;

	int b;
	if (blue < 0.0f) {
		b = 0;
	} else if (blue > 255.0f) {
		b = 255;
	} else {
		b = (u8)blue;
	}

	target.b = b;
}

/*
 * --INFO--
 * Address:	80025ECC
 * Size:	0001F8
 */
void PVWAlphaAnimInfo::extract(f32 value, Colour& target)
{
	// If there is no animation data, return without modification
	if (mAnimInfo.mSize == 0) {
		return;
	}

	if (mAnimInfo.mSize == 1) {
		target.a = mAnimInfo.mKeyframes[0].mData.mTime;
		return;
	}

	int idx = 0;
	for (int i = 0; i < (int)mAnimInfo.mSize - 1; i++) {
		if (mAnimInfo.mKeyframes[i].mTime <= value && mAnimInfo.mKeyframes[i + 1].mTime >= value) {
			idx = i;
			break;
		}
	}

	f32 alpha = subExtract(value,
	                       AKeyInfo(mAnimInfo.mKeyframes[idx].mTime, mAnimInfo.mKeyframes[idx].mData.mTime,
	                                mAnimInfo.mKeyframes[idx].mData.mValue, mAnimInfo.mKeyframes[idx].mData.mTangent),
	                       AKeyInfo(mAnimInfo.mKeyframes[idx + 1].mTime, mAnimInfo.mKeyframes[idx + 1].mData.mTime,
	                                mAnimInfo.mKeyframes[idx + 1].mData.mValue, mAnimInfo.mKeyframes[idx + 1].mData.mTangent));

	int a;
	if (alpha < 0.0f) {
		a = 0;
	} else if (alpha > 255.0f) {
		a = 255;
	} else {
		a = (u8)alpha;
	}

	target.a = a;
}

/*
 * --INFO--
 * Address:	800260C4
 * Size:	0004A0
 */
void PVWColourShortAnimInfo::extract(f32 value, ShortColour& target)
{
	// If there is no animation data, return without modification
	if (mInfo.mSize == 0) {
		return;
	}

	if (mInfo.mSize == 1) {
		target.r = mInfo.mKeyframes[0].mRedData.mTime;
		target.g = mInfo.mKeyframes[0].mGreenData.mTime;
		target.b = mInfo.mKeyframes[0].mBlueData.mTime;
		return;
	}

	int idx = 0;
	for (int i = 0; i < (int)mInfo.mSize - 1; i++) {
		if (mInfo.mKeyframes[i].mTime <= value && mInfo.mKeyframes[i + 1].mTime >= value) {
			idx = i;
			break;
		}
	}

	f32 red   = subExtract(value,
	                       AKeyInfo(mInfo.mKeyframes[idx].mTime, mInfo.mKeyframes[idx].mRedData.mTime, mInfo.mKeyframes[idx].mRedData.mValue,
	                                mInfo.mKeyframes[idx].mRedData.mTangent),
	                       AKeyInfo(mInfo.mKeyframes[idx + 1].mTime, mInfo.mKeyframes[idx + 1].mRedData.mTime,
	                                mInfo.mKeyframes[idx + 1].mRedData.mValue, mInfo.mKeyframes[idx + 1].mRedData.mTangent));
	f32 green = subExtract(value,
	                       AKeyInfo(mInfo.mKeyframes[idx].mTime, mInfo.mKeyframes[idx].mGreenData.mTime,
	                                mInfo.mKeyframes[idx].mGreenData.mValue, mInfo.mKeyframes[idx].mGreenData.mTangent),
	                       AKeyInfo(mInfo.mKeyframes[idx + 1].mTime, mInfo.mKeyframes[idx + 1].mGreenData.mTime,
	                                mInfo.mKeyframes[idx + 1].mGreenData.mValue, mInfo.mKeyframes[idx + 1].mGreenData.mTangent));
	f32 blue  = subExtract(value,
	                       AKeyInfo(mInfo.mKeyframes[idx].mTime, mInfo.mKeyframes[idx].mBlueData.mTime,
	                                mInfo.mKeyframes[idx].mBlueData.mValue, mInfo.mKeyframes[idx].mBlueData.mTangent),
	                       AKeyInfo(mInfo.mKeyframes[idx + 1].mTime, mInfo.mKeyframes[idx + 1].mBlueData.mTime,
	                                mInfo.mKeyframes[idx + 1].mBlueData.mValue, mInfo.mKeyframes[idx + 1].mBlueData.mTangent));

	int r;
	if (red < -1023.0f) {
		r = -1023;
	} else if (red > 1023.0f) {
		r = 1023;
	} else {
		r = (s16)red;
	}

	target.r = r;

	int g;
	if (green < -1023.0f) {
		g = -1023;
	} else if (green > 1023.0f) {
		g = 1023;
	} else {
		g = (s16)green;
	}

	target.g = g;

	int b;
	if (blue < -1023.0f) {
		b = -1023;
	} else if (blue > 1023.0f) {
		b = 1023;
	} else {
		b = (s16)blue;
	}

	target.b = b;
}

/*
 * --INFO--
 * Address:	80026564
 * Size:	000208
 */
void PVWAlphaShortAnimInfo::extract(f32 value, ShortColour& target)
{
	// If there is no animation data, return without modification
	if (mInfo.mSize == 0) {
		return;
	}

	if (mInfo.mSize == 1) {
		target.a = mInfo.mKeyframes[0].mData.mTime;
		return;
	}

	int idx = 0;
	for (int i = 0; i < (int)mInfo.mSize - 1; i++) {
		if (mInfo.mKeyframes[i].mTime <= value && mInfo.mKeyframes[i + 1].mTime >= value) {
			idx = i;
			break;
		}
	}

	f32 alpha = subExtract(value,
	                       AKeyInfo(mInfo.mKeyframes[idx].mTime, mInfo.mKeyframes[idx].mData.mTime, mInfo.mKeyframes[idx].mData.mValue,
	                                mInfo.mKeyframes[idx].mData.mTangent),
	                       AKeyInfo(mInfo.mKeyframes[idx + 1].mTime, mInfo.mKeyframes[idx + 1].mData.mTime,
	                                mInfo.mKeyframes[idx + 1].mData.mValue, mInfo.mKeyframes[idx + 1].mData.mTangent));

	int a;
	if (alpha < 0.0f) {
		a = 0;
	} else if (alpha > 255.0f) {
		a = 255;
	} else {
		a = (s16)alpha;
	}

	target.a = a;
}

/*
 * --INFO--
 * Address:	8002676C
 * Size:	0003B0
 */
void PVWTexAnimInfo::extract(f32 value, Vector3f& target)
{
	// If there is no animation data, return without modification
	if (mInfo.mSize == 0) {
		return;
	}

	if (mInfo.mSize == 1) {
		target.x = mInfo.mKeyframes[0].mRedData.mTime;
		target.y = mInfo.mKeyframes[0].mGreenData.mTime;
		target.z = mInfo.mKeyframes[0].mBlueData.mTime;
		return;
	}

	int idx = 0;
	if (value >= f32(mInfo.mKeyframes[mInfo.mSize - 1].mTime)) {
		target.x = mInfo.mKeyframes[mInfo.mSize - 1].mRedData.mTime;
		target.y = mInfo.mKeyframes[mInfo.mSize - 1].mGreenData.mTime;
		target.z = mInfo.mKeyframes[mInfo.mSize - 1].mBlueData.mTime;
		return;
	}
	for (int i = 0; i < (int)mInfo.mSize - 1; i++) {
		if (mInfo.mKeyframes[i].mTime <= value && mInfo.mKeyframes[i + 1].mTime >= value) {
			idx = i;
			break;
		}
	}

	target.x = subExtract(value,
	                      AKeyInfo(mInfo.mKeyframes[idx].mTime, mInfo.mKeyframes[idx].mRedData.mTime, mInfo.mKeyframes[idx].mRedData.mValue,
	                               mInfo.mKeyframes[idx].mRedData.mTangent),
	                      AKeyInfo(mInfo.mKeyframes[idx + 1].mTime, mInfo.mKeyframes[idx + 1].mRedData.mTime,
	                               mInfo.mKeyframes[idx + 1].mRedData.mValue, mInfo.mKeyframes[idx + 1].mRedData.mTangent));
	target.y = subExtract(value,
	                      AKeyInfo(mInfo.mKeyframes[idx].mTime, mInfo.mKeyframes[idx].mGreenData.mTime,
	                               mInfo.mKeyframes[idx].mGreenData.mValue, mInfo.mKeyframes[idx].mGreenData.mTangent),
	                      AKeyInfo(mInfo.mKeyframes[idx + 1].mTime, mInfo.mKeyframes[idx + 1].mGreenData.mTime,
	                               mInfo.mKeyframes[idx + 1].mGreenData.mValue, mInfo.mKeyframes[idx + 1].mGreenData.mTangent));
	target.z = subExtract(value,
	                      AKeyInfo(mInfo.mKeyframes[idx].mTime, mInfo.mKeyframes[idx].mBlueData.mTime,
	                               mInfo.mKeyframes[idx].mBlueData.mValue, mInfo.mKeyframes[idx].mBlueData.mTangent),
	                      AKeyInfo(mInfo.mKeyframes[idx + 1].mTime, mInfo.mKeyframes[idx + 1].mBlueData.mTime,
	                               mInfo.mKeyframes[idx + 1].mBlueData.mValue, mInfo.mKeyframes[idx + 1].mBlueData.mTangent));
}

/*
 * --INFO--
 * Address:	80026B1C
 * Size:	0002F8
 */
void PVWTextureData::animate(f32* p1, Matrix4f& mtx)
{
	if (mAnimationFactor == 255) {
		return;
	}

	Vector3f vec1(1.0f, 1.0f, 0.0f);
	Vector3f vec2(0.0f, 0.0f, 0.0f);
	Vector3f vec3(0.0f, 0.0f, 0.0f);

	if (!mTotalFrameCount) {
		if (!mIsMatrixDirty) {
			vec1.set(mScaleX, mScaleY, 0.0f);
			vec2.set(0.0f, 0.0f, mRotationZ);
			vec3.set(mTranslationX, mTranslationY, 0.0f);
		}
	} else {
		if (p1) {
			mCurrentFrame = std::fmodf(*p1, (f32)mTotalFrameCount);
		} else {
			mCurrentFrame += gsys->getFrameTime() * (30.0f * mAnimSpeed);
			if (mCurrentFrame >= f32(mTotalFrameCount - 1)) {
				mCurrentFrame = 0.0f;
			}
		}

		mScaleInfo.extract(mCurrentFrame, vec1);
		mRotationInfo.extract(mCurrentFrame, vec2);
		mTranslationInfo.extract(mCurrentFrame, vec3);
		mIsMatrixDirty = false;
	}

	if (!mIsMatrixDirty) {
		f32 sinTheta = sinf(vec2.z * PI / 180.0f);
		f32 cosTheta = cosf(vec2.z * PI / 180.0f);

		mtx.mMtx[0][0] = vec1.x * cosTheta;
		mtx.mMtx[0][1] = -vec1.x * sinTheta;
		mtx.mMtx[0][2] = 0.0f;
		mtx.mMtx[0][3] = -vec1.x * cosTheta * mPivotX + vec1.x * sinTheta * mPivotY + mPivotX + vec3.x;

		mtx.mMtx[1][0] = vec1.y * sinTheta;
		mtx.mMtx[1][1] = vec1.y * cosTheta;
		mtx.mMtx[1][2] = 0.0f;
		mtx.mMtx[1][3] = -vec1.y * sinTheta * mPivotX - vec1.y * cosTheta * mPivotY + mPivotY + vec3.y;

		mtx.mMtx[2][0] = 0.0f;
		mtx.mMtx[2][1] = 0.0f;
		mtx.mMtx[2][2] = 1.0f;
		mtx.mMtx[2][3] = 0.0f;

		mtx.mMtx[3][0] = 0.0f;
		mtx.mMtx[3][1] = 0.0f;
		mtx.mMtx[3][2] = 0.0f;
		mtx.mMtx[3][3] = 1.0f;

		mIsMatrixDirty = true;
	}
}

/*
 * --INFO--
 * Address:	80026E14
 * Size:	0005A4
 */
void PVWTextureData::read(RandomAccessStream& stream)
{
	mSourceAttrIndex = stream.readInt();
	_UNUSED0C        = stream.readShort();
	_UNUSED0E        = stream.readShort();
	_UNUSED10        = stream.readByte();
	_UNUSED11        = stream.readByte();
	_UNUSED12        = stream.readByte();
	_UNUSED13        = stream.readByte();
	mAnimationFactor = stream.readInt();
	mTotalFrameCount = stream.readInt();
	mAnimSpeed       = stream.readFloat();
	mScaleX          = stream.readFloat();
	mScaleY          = stream.readFloat();
	mRotationZ       = stream.readFloat();
	mTranslationX    = stream.readFloat();
	mTranslationY    = stream.readFloat();
	mPivotX          = stream.readFloat();
	mPivotY          = stream.readFloat();

	mScaleInfo.mInfo.read(stream);
	mRotationInfo.mInfo.read(stream);
	mTranslationInfo.mInfo.read(stream);

	if (mAnimationFactor != 0xFF) {
		(mAnimationFactor); // fake
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void PVWTexGenData::read(RandomAccessStream& input)
{
	mTexCoordID = input.readByte();
	mTexGenType = input.readByte();
	mTexGenSrc  = input.readByte();
	mMatrixType = input.readByte();
}

/*
 * --INFO--
 * Address:	800273B8
 * Size:	0001E8
 */
void PVWTextureInfo::read(RandomAccessStream& input)
{
	mUseScale = input.readInt();
	mScale.read(input);
	mTexGenDataCount = input.readInt();
	if (mTexGenDataCount) {
		mTexGenData = new PVWTexGenData[mTexGenDataCount];

		for (int i = 0; i < mTexGenDataCount; i++) {
			mTexGenData[i].read(input);
		}
	}

	mTevStageCount    = 0;
	mTextureDataCount = input.readInt();
	if (mTextureDataCount) {
		mTextureData = new PVWTextureData[mTextureDataCount];

		for (int i = 0; i < mTextureDataCount; i++) {
			mTextureData[i].read(input);
			if (mTextureData[i]._UNUSED11 == 2) {
				mTevStageCount++;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800275B8
 * Size:	000120
 */
void PVWTevColReg::animate(f32* p1, ShortColour& color)
{
	if (!mAnimFrameCount) {
		return;
	}

	if (p1) {
		mCurrentAnimFrame = std::fmodf(*p1, mAnimFrameCount);
	} else {
		mCurrentAnimFrame += gsys->getFrameTime() * (30.0f * mAnimSpeed);
		if (mCurrentAnimFrame >= f32(mAnimFrameCount - 1)) {
			mCurrentAnimFrame = 0.0f;
		}
	}

	mColorAnimData.extract(mCurrentAnimFrame, color);
	mAlphaAnimData.extract(mCurrentAnimFrame, color);
}

/*
 * --INFO--
 * Address:	800276D8
 * Size:	000054
 */
void Material::attach()
{
	gsys->mDGXGfx->useDList(gsys->mDGXGfx->compileMaterial(this));
}

/*
 * --INFO--
 * Address:	80027738
 * Size:	000238
 */
void Material::read(RandomAccessStream& input)
{
	mFlags        = input.readInt();
	mTextureIndex = input.readInt();
	Colour().read(input);

	if (mFlags & MATFLAG_PVW) {
		mTevInfoIndex = input.readInt();
		mColourInfo.read(input);
		mLightingInfo.read(input);
		mPeInfo.read(input);
		mTextureInfo.read(input);
	}
}

/*
 * --INFO--
 * Address:	80027CB8
 * Size:	0002D0
 */
void Font::setTexture(Texture* tex, int numRows, int numCols)
{
	mTexture    = tex;
	mChars      = new FontChar[numRows * numCols];
	mCharWidth  = mTexture->mWidth / numRows;
	mCharHeight = mTexture->mHeight / numCols;

	int charIndex = 0;
	for (int i = 0; i < numCols; i++) {
		for (int j = 0; j < numRows; j++) {
			int leftEdge  = 0;
			int rightEdge = 0;

			// Find left boundary
			for (int k = 0; k < mCharWidth; k++) {
				int alphaCount = 0;
				for (int m = 0; m < mCharHeight - 1; m++) {
					if (!tex->getAlpha(k + (j * mCharWidth), m + (i * mCharHeight))) {
						alphaCount++;
					}
				}

				if (alphaCount != mCharHeight - 1) {
					break;
				}

				leftEdge = k;
			}

			// Find right boundary
			for (int k = mCharWidth - 1; k >= 0; k--) {
				int alphaCount = 0;
				for (int m = 0; m < mCharHeight - 1; m++) {
					if (!tex->getAlpha(k + (j * mCharWidth), m + (i * mCharHeight))) {
						alphaCount++;
					}
				}

				if (alphaCount != mCharHeight - 1) {
					break;
				}

				rightEdge = mCharWidth - k;
			}

			// Find baseline
			int baseline    = -1;
			int baselinePos = mCharWidth;
			for (int k = 0; k < mCharWidth; k++) {
				int x    = j * mCharWidth;
				int y    = (mCharHeight + (i * mCharHeight));
				u8 alpha = tex->getAlpha(k + x, y - 1);
				if (baseline < 0) {
					if (!alpha) {
						baseline = k;
					}
				} else if (alpha) {
					baselinePos = k;
					break;
				}
			}

			// This is ridiculous, seriously? why?
			// so much indexing, this isn't even an inline function
			mChars[charIndex].mCharSpacing         = baselinePos - baseline;
			mChars[charIndex].mLeftOffset          = baseline - leftEdge;
			mChars[charIndex].mTextureX            = leftEdge + j * mCharWidth;
			mChars[charIndex].mWidth               = mCharWidth - leftEdge - rightEdge;
			mChars[charIndex].mTextureY            = i * mCharHeight;
			mChars[charIndex].mHeight              = mCharHeight - 1;
			mChars[charIndex].mTextureCoords.mMinX = (s16)mChars[charIndex].mTextureX;
			mChars[charIndex].mTextureCoords.mMinY = (s16)mChars[charIndex].mTextureY;
			mChars[charIndex].mTextureCoords.mMaxX = (s16)mChars[charIndex].mTextureX + (s16)mChars[charIndex].mWidth;
			mChars[charIndex].mTextureCoords.mMaxY = (s16)mChars[charIndex].mTextureY + (s16)mChars[charIndex].mHeight - 1;

			charIndex++;
		}
	}
}

// this needs to be in a function, but it straight up never gets used, so.
static void unusedStatic()
{
	static const char* mappingTypes[3] = { "Normal", "Projection", "Environ" };
}

static u16 sjis_convert_table[0x258] = {
	0,     0x118, 0x119, 0xC,   0xE,   0x60,  0x1A,  0x1B,  0x1F,  0x1,   0x2,   0,     0,     0,     0,     0x3E,  0,     0,     0,
	0,     0,     0,     0,     0,     0x123, 0,     0,     0xD,   0xD,   0xD,   0xF,   0x3C,  0x11A, 0,     0,     0x117, 0,     0x7,
	0x7,   0x2,   0x2,   0x8,   0x9,   0x0,   0,     0x3B,  0x3D,  0,     0,     0,     0,     0,     0,     0x11F, 0x120, 0,     0,
	0,     0,     0xB,   0xD,   0,     0,     0,     0,     0x1D,  0,     0x1C,  0x1E,  0,     0,     0,     0,     0,     0,     0,
	0x7,   0x2,   0,     0,     0x4,   0,     0,     0x5,   0x3,   6,     0xA,   0x20,  0,     0,     0x122, 0,     0x121, 0,     0,
	0,     0,     0x5C,  0,     0,     0,     0,     0,     0,     0x11C, 0x11B, 0x11E, 0x11D, 0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     3,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0x10,  0x11,  0x12,  0x13,  0x14,  0x15,  0x16,  0x17,  0x18,  0x19,  0,     0,     0,     0,
	0,     0,     0,     0x21,  0x22,  0x23,  0x24,  0x25,  0x26,  0x27,  0x28,  0x29,  0x2A,  0x2B,  0x2C,  0x2D,  0x2E,  0x2F,  0x30,
	0x31,  0x32,  0x33,  0x34,  0x35,  0x36,  0x37,  0x38,  0x39,  0x3A,  0,     0,     0,     0,     0,     0,     0,     0x41,  0x42,
	0x43,  0x44,  0x45,  0x46,  0x47,  0x48,  0x49,  0x4A,  0x4B,  0x4C,  0x4D,  0x4E,  0x4F,  0x50,  0x51,  0x52,  0x53,  0x54,  0x55,
	0x56,  0x57,  0x58,  0x59,  0x5A,  0,     0,     0,     0,     0x61,  0x62,  0x63,  0x64,  0x65,  0x66,  0x67,  0x68,  0x69,  0x6A,
	0x6B,  0x6C,  0x6D,  0x6E,  0x6F,  0x70,  0x71,  0x72,  0x73,  0x74,  0x75,  0x76,  0x77,  0x78,  0x79,  0x7A,  0x7B,  0x7C,  0x7D,
	0x7E,  0x7F,  0x80,  0x81,  0x82,  0x83,  0x84,  0x85,  0x86,  0x87,  0x88,  0x89,  0x8A,  0x8B,  0x8C,  0x8D,  0x8E,  0x8F,  0x90,
	0x91,  0x92,  0x93,  0x94,  0x95,  0x96,  0x97,  0x98,  0x99,  0x9A,  0x9B,  0x9C,  0x9D,  0x9E,  0x9F,  0xA0,  0xA1,  0xA2,  0xA3,
	0xA4,  0xA5,  0xA6,  0xA7,  0xA8,  0xA9,  0xAA,  0xAB,  0xAC,  0xAD,  0xAE,  0xAF,  0xB0,  0xB1,  0xB2,  0xB3,  0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0xC1,
	0xC2,  0xC3,  0xC4,  0xC5,  0xC6,  0xC7,  0xC8,  0xC9,  0xCA,  0xCB,  0xCC,  0xCD,  0xCE,  0xCF,  0xD0,  0xD1,  0xD2,  0xD3,  0xD4,
	0xD5,  0xD6,  0xD7,  0xD8,  0xD9,  0xDA,  0xDB,  0xDC,  0xDD,  0xDE,  0xDF,  0xE0,  0xE1,  0xE2,  0xE3,  0xE4,  0xE5,  0xE6,  0xE7,
	0xE8,  0xE9,  0xEA,  0xEB,  0xEC,  0xED,  0xEE,  0xEF,  0xF0,  0xF1,  0xF2,  0xF3,  0xF4,  0xF5,  0xF6,  0xF7,  0xF8,  0xF9,  0xFA,
	0xFB,  0xFC,  0xFD,  0xFE,  0xFF,  0,     0x100, 0x101, 0x102, 0x103, 0x104, 0x105, 0x106, 0x107, 0x108, 0x109, 0x10A, 0x10B, 0x10C,
	0x10D, 0x10E, 0x10F, 0x110, 0x111, 0x112, 0x113, 0x114, 0x115, 0x116, 0x0,
};

static char kanji_convert_table[] ATTRIBUTE_ALIGN(32) = {
#if defined(VERSION_GPIP01_00)
	"日目時私未知星大地\x85\x20名前宇宙旅途中流墜落愛機号多失無残姿動一重迎教気猛毒酸素含生命維持装置限度修復考船探検奇妙物体待立上何械観察"
	"芽光放"
#else
	"日目時私未知星大地横名前宇宙旅途中流墜落愛機号多失無残姿動一重迎教気猛毒酸素含生命維持装置限度修復考船探検奇妙物体待立上何械観察芽光放"
#endif
	"思試引抜植見害好野菜呼投反応操作回転今来倒取増殖母彼態不議少能力調必要興味集団合行習性利用繰希望灯近押解散隊列記録画面安心幸運事離陸可"
	"飛明捜索後入森昨出下全滅種掴切色同赤注意深口部分他違黄帰特穴掘石割内高収個範囲没太陽仕暗去食発荷伝質超科学結晶除汚移永久燃料電済位確認"
	"間叩当最激本妻子供顔浮射線遠外音鳴役息座娘元空欠嵐強噴脱速加費良家計衝撃吸亜複通雑場所父親人美咲別感続金属品買理遊泳腰晩庫以状実組異常"
	"聞快配乗約束尾現念故終巻頭土製値打夜楽身向算果焼便成功驚緒暮付借戻昇窓広満帯始惑遭難協者郷長眠油断服界達非送闘左表示族存在徴耳奥開洞窟"
	"青会視手足小水自助消原周辺映十字効率眼定降樹海備早就湿源朝進完練寝指正直勇初恐景員険話情報数変化与方整奮新道恵単判葉花仲然獲冒破壊敵圏"
	"平歩炎天卵軟接触至死攻駆繁栄巨丸呑弾半折胞吐連錯乱振払堅夢追昼怖揺丈先止胴弱点簡甲羅岩量込捕透核法怒奴等構厄介橋苦労系貝真珠価罠禁巣風"
	"造勢戦襲言遮和厳密頂着休年昔想像響返白敏再還我懸草誰工月司髪毛細番予殊影過関係誇育腹次矢窒寸覚覗屋忘血航誌亡泉夕使期敗容制挿読扱説書閉"
	"績匹累替角更包獰吹遇悪似謎守有軽様告武器危崩順形養境届両衛貫渦砕淵裂凡義務貴毎賊突測庭円翔魅夫秩低爆住笑"
};

/*
 * --INFO--
 * Address:	80027FB4
 * Size:	00000C
 */
int Font::charToIndex(char c)
{
	return c - 0x20;
}

/*
 * --INFO--
 * Address:	80027FC0
 * Size:	000098
 */
static s16 searchKanjiCode(u16 code)
{
	u32 codeBytes[2];
	codeBytes[0] = u16(code >> 8) & 0xFF;
	codeBytes[1] = code & 0xFF;

	s16 len = strlen(kanji_convert_table) >> 1;
	s16 res = -1;

	for (s16 i = 0; i < len; i++) {
		if (kanji_convert_table[2 * i] == codeBytes[0] && kanji_convert_table[2 * i + 1] == codeBytes[1]) {
			res = i;
			break;
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	80028058
 * Size:	0000DC
 */
int Font::charToIndex(u16 c)
{
	if (c >= 0x8140 && c <= 0x8396) {
		return sjis_convert_table[c - 0x8140];
	}

	int kanji = searchKanjiCode(c);
	return ((s16)kanji != -1) ? (s16)kanji + 0x126 : '_';
}

/*
 * --INFO--
 * Address:	80028134
 * Size:	0000E0
 */
int Font::stringWidth(immut char* str)
{
	int width = 0;
	while (*str) {
		int idx;
#if defined(VERSION_GPIP01_00)
		STACK_PAD_VAR(4);
		if (*str >= 0xa0) {
			idx = *str - 0x20;
			str++;
		} else if (*str & 0x80) {
#else
		if (*str & 0x80) {
#endif
			u16 c = (str[0] << 8) | (str[1] & 0xFF);
			idx   = charToIndex(c);
			str += 2;
		} else {
			idx = charToIndex(*str);
			str++;
		}
		width += mChars[idx].mCharSpacing;
	}

	return width + 1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003A0
 */
void GfxInfo::createCollData(immut Vector3f* pos, f32)
{
	mTriangles = new CollTriInfo[_1C[0]];
	mBox.resetBound();
	pos->length(); // this is load-bearing for sdata2 ordering
	               // more here, but this is enough to get the weak ctors to spawn
}

/*
 * --INFO--
 * Address:	80028280
 * Size:	000034
 */
void MaterialHandler::setMaterial(Material* mat)
{
	mGfx->setMaterial(mat, false);
}

/*
 * --INFO--
 * Address:	800282B4
 * Size:	000030
 */
void MaterialHandler::setTexMatrix(bool p1)
{
	mGfx->initReflectTex(p1);
}

/*
 * --INFO--
 * Address:	800282E4
 * Size:	0001C8
 */
Graphics::Graphics()
{
	PRINT("dgxgraphics constructor\n");

	mRenderMode = 0;

	for (int i = 0; i < 0x1000; i++) {
		sintable[i] = NMathF::sin(TAU * (i / 4096.0f));
		costable[i] = NMathF::cos(TAU * (i / 4096.0f));
	}

	mActiveTexture[0] = nullptr;
	mActiveTexture[1] = nullptr;
	mActiveTexture[2] = nullptr;
	mActiveTexture[3] = nullptr;
	mActiveTexture[4] = nullptr;
	mActiveTexture[5] = nullptr;
	mActiveTexture[6] = nullptr;
	mActiveTexture[7] = nullptr;

	_308 = 0;

	mCurrentMaterial = nullptr;
	mLightCam        = nullptr;

	// Well I suppose this has to initialize *somewhere*.
	const_cast<Matrix4f&>(Matrix4f::ident).makeIdentity();

	mCurrentMaterialHandler = nullptr;
	mDefaultMaterialHandler = new MaterialHandler();

	mMaxMatrixCount = gsys->mMatrixCount;
	mSystemMatrices = gsys->mMatrices;

	mCachedShapeMax = 1000;
	mCachedShapes   = new CachedShape[mCachedShapeMax];

	mAmbientFogColour.set(0, 0, 0x30, 0xFF);
	mLightIntensity = 1.0f;
}

/*
 * --INFO--
 * Address:	800284B8
 * Size:	000050
 */
void Graphics::initRender(int, int)
{
	mActiveLightMask = 0;
	mLight.initCore("");
	resetMatrixBuffer();
	resetCacheBuffer();
}

/*
 * --INFO--
 * Address:	80028508
 * Size:	00000C
 */
void Graphics::resetMatrixBuffer()
{
	mActiveMatrixIdx = nullptr;
}

/*
 * --INFO--
 * Address:	80028514
 * Size:	00001C
 */
Matrix4f* Graphics::getMatrices(int requestedMatrixCount)
{
	if (mActiveMatrixIdx + requestedMatrixCount > mMaxMatrixCount) {
		ERROR("using too many matrices!!\n");
	}

	Matrix4f* mtx = &mSystemMatrices[mActiveMatrixIdx];
	mActiveMatrixIdx += requestedMatrixCount;
	return mtx;
}

/*
 * --INFO--
 * Address:	80028530
 * Size:	000018
 */
void Graphics::resetCacheBuffer()
{
	mShapeCache.mNext = &mShapeCache;
	mShapeCache.mPrev = &mShapeCache;

	mCachedShapeCount = nullptr;
}

/*
 * --INFO--
 * Address:	80028548
 * Size:	000184
 */
void Graphics::cacheShape(BaseShape* shape, ShapeDynMaterials* mats)
{
	if (mCachedShapeCount >= mCachedShapeMax) {
		ERROR("using too many shapes!!\n");
	}

	CachedShape* cache = &mCachedShapes[mCachedShapeCount];
	Vector3f pos(shape->getAnimMatrix(0).mMtx[0][3], shape->getAnimMatrix(0).mMtx[1][3], shape->getAnimMatrix(0).mMtx[2][3]);
	cache->mDistanceFromOrigin = pos.length();

	bool far = false;
	for (CachedShape* i = mShapeCache.mPrev; i != &mShapeCache; i = i->mPrev) {
		if (cache->mDistanceFromOrigin >= i->mDistanceFromOrigin) {
			i->insertAfter(cache);
			far = true;
			break;
		}
	}

	if (!far) {
		mShapeCache.insertAfter(cache);
	}

	cache->mDynMaterials = mats;
	cache->mParentShape  = (Shape*)shape;
	cache->mAnimMatrices = shape->mAnimMatrices;
	mCachedShapeCount++;
}

/*
 * --INFO--
 * Address:	800286CC
 * Size:	0000A0
 */
void Graphics::flushCachedShapes()
{
	u32 oldRenderState = mRenderState;

	mRenderState = GFXRENDER_Unk3;
	for (CachedShape* i = mShapeCache.mPrev; i != &mShapeCache; i = i->mPrev) {
		if (i->mDynMaterials) {
			for (ShapeDynMaterials* j = i->mDynMaterials; j; j = j->mParent) {
				j->updateContext();
			}
		}

		i->mParentShape->mAnimMatrices = i->mAnimMatrices;
		drawMeshes(*mCamera, i->mParentShape);
	}
	mRenderState = oldRenderState;
}

static u32 convFmts[] = {
	TEX_FMT_I4,   TEX_FMT_I8,   TEX_FMT_IA4,  TEX_FMT_IA8,  TEX_FMT_RGB565, TEX_FMT_RGB5A3, TEX_FMT_RGBA8, TEX_FMT_NULL,
	TEX_FMT_NULL, TEX_FMT_NULL, TEX_FMT_NULL, TEX_FMT_NULL, TEX_FMT_NULL,   TEX_FMT_NULL,   TEX_FMT_S3TC,
};

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
u32 TexImg::convFormat(u32 inFmt)
{
	return convFmts[inFmt];
	// UNUSED FUNCTION
}

static immut char* fmtNames[] = {
	"TEX_FMT_RGB565", "TEX_FMT_S3TC", "TEX_FMT_RGB5A3", "TEX_FMT_I4", "TEX_FMT_I8", "TEX_FMT_IA4", "TEX_FMT_IA8", "TEX_FMT_RGBA8",
};

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
immut char* TexImg::formatName(u32 format)
{
	return fmtNames[format];
}

/*
 * --INFO--
 * Address:	8002876C
 * Size:	00009C
 */
int TexImg::calcDataSize(int format, int width, int height)
{
	s32 size = 0;

	switch (format) {
	case 1:
		size = (width * height / 8) * 4;
		break;
	case 2:
		size = width * height * 2;
		break;
	case 0:
		size = width * height * 2;
		break;
	case 3:
		size = width * height / 2;
		break;
	case 4:
		size = width * height;
		break;
	case 5:
		size = width * height;
		break;
	case 6:
		size = width * height * 2;
		break;
	case 7:
		size = width * height * 4;
		break;
	case 8:
		size = width * height;
		break;
	case 9:
		size = width * height;
		break;
	}

	return size;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void TexImg::setColour(Colour&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80028808
 * Size:	000130
 */
void TexImg::read(RandomAccessStream& stream)
{
	mWidth         = stream.readShort();
	mHeight        = stream.readShort();
	mFormat        = static_cast<TexImgFormat>(stream.readInt());
	mDataPtrOffset = stream.readInt();

	s32 _ = stream.readInt();
	_     = stream.readInt();
	_     = stream.readInt();
	_     = stream.readInt();

	mDataSize    = stream.readInt();
	mTextureData = new (0x20) u8[mDataSize];
	stream.read(mTextureData, mDataSize);
}

/*
 * --INFO--
 * Address:	80028938
 * Size:	000058
 */
void TexImg::getTileSize(int format, u32& xSize, u32& ySize)
{
	switch (format) {
	case 3:
		xSize = 8;
		ySize = 8;
		break;
	case 4:
	case 5:
	case 9:
		xSize = 8;
		ySize = 4;
		break;
	default:
		xSize = 4;
		ySize = 4;
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00014C
 */
void TexImg::readTexData(Texture* tex, RandomAccessStream& stream, u8* data)
{
	mDataSize = TexImg::calcDataSize(mFormat, mWidth, mHeight);

	if (!data) {
		mTextureData = new (0x20) u8[mDataSize];
	} else {
		mTextureData = data;
	}

	stream.read(mTextureData, mDataSize);
	TexImg::getTileSize(mFormat, tex->mTileSizeX, tex->mTileSizeY);
	tex->mWidthFactor  = 1.0f / mWidth;
	tex->mHeightFactor = 1.0f / mHeight;
	tex->decodeData(this);
}

static const char* btitexFmts[] = {
	"GX_TF_I4", "GX_TF_I8", "GX_TF_IA4", "GX_TF_IA8", "GX_TF_RGB565", "GX_TF_RGB5A3", "GX_TF_RGBA8", "INVALID",
	"INVALID",  "INVALID",  "INVALID",   "INVALID",   "INVALID",      "INVALID",      "GX_TF_CMPR",
};

static const char* btipalFmts[] = {
	"GX_TF_C4",
	"GX_TF_C8",
	"GX_TF_C14X2",
};

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void TexImg::dumpBti(Texture* tex, immut char* name, RandomAccessStream& input, RandomAccessStream& output)
{
#ifdef WIN32
	// read BTI function
	// blah blah

	// if some bollocks
	// now lets get to the fun parts

	// this is wrong btw, I can't be bothered to check if this shows up
	// but im doing it anyway, **** it
	output.print("// %s (%d colour) format %s : data = %d bytes\n", output.mPath, 0, btipalFmts[tex->mTexFormat]);
	output.print("// texture size = %d x %d\n");
	output.print("static u16 %s_palette[%d] ATTRIBUTE_ALIGN(32) = {\n");
	output.print("\t");
	PRINT("sending colour %d, %d, %d\n");
	output.print("0x%04x,");
	output.print("\n");
	output.print("\t};\n\n");

	// so much code i skipped over lol
	output.print("// %s got normal image of format %s : data = %d bytes\n");
	output.print("// texture size = %d x %d\n");

	output.print("static u8 %s_data[%d] ATTRIBUTE_ALIGN(32) = {\n");
	output.print("\t");
	output.print("0x%02x,");
	output.print("\n");
	output.print("\t};\n\n");

#endif
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80028990
 * Size:	0003EC
 */
void TexImg::importBti(Texture* tex, RandomAccessStream& input, u8* data)
{
	BtiHeader bti;
	bti.read(input);

	mFormat = (TexImgFormat)convFormat(bti.mImageFormat);
	mWidth  = bti.mWidth;
	mHeight = bti.mHeight;

	u32 x;
	u32 y;
	getTileSize(mFormat, x, y);
	if (mWidth % x || mHeight % y) {
		ERROR("Texture %s is not correct size %d x %d\n", input.mPath, mWidth, mHeight);
	}
	if (bti.mImageDataOffset != sizeof(BtiHeader)) {
		ERROR("Bti file has imageData at offset %d!!!\n", bti.mImageDataOffset);
	}

	tex->mTexFlags = (!bti.mWrapS ? 0x1 : 0) | (!bti.mWrapT ? 0x100 : 0);

	readTexData(tex, input, data);
}

/*
 * --INFO--
 * Address:	80028D7C
 * Size:	0001A8
 */
void TexImg::importTxe(Texture* tex, RandomAccessStream& stream)
{
	mWidth         = stream.readShort();
	mHeight        = stream.readShort();
	mFormat        = static_cast<TexImgFormat>((u16)stream.readShort());
	tex->mTexFlags = mFormat >> 8;

	mFormat = static_cast<TexImgFormat>(mFormat & 0xFF);

	s16 _  = stream.readShort();
	s32 __ = stream.readInt();
	for (int i = 0; i < 10; i++) {
		stream.readShort();
	}

	readTexData(tex, stream, nullptr);
}

/*
 * --INFO--
 * Address:	80028F24
 * Size:	0001E4
 */
void TexAttr::initImage()
{
	mTexture = new Texture();

	if (!mTexture) {
		ERROR("could not make texture!!\n");
	}

	TexImg::getTileSize(mImage->mFormat, mTexture->mTileSizeX, mTexture->mTileSizeY);

	if (mUseOffsetImgData) {
		mTexture->mTextureData = (u32*)(mImage->mDataPtrOffset - 1);
		mTexture->mLODBias     = mLODBias;
	} else {
		mTexture->mTextureData = nullptr;
		mTexture->mLODBias     = 0.0f;
	}

	mTexture->mWidthFactor  = 1.0f / mImage->mWidth;
	mTexture->mHeightFactor = 1.0f / mImage->mHeight;

	mTexture->mTexFlags = mTilingType;

	int i = strlen(gsys->mCurrentShape->mName) - 1;
	for (i; i >= 0; i--) {
		if (gsys->mCurrentShape->mName[i] == '/') {
			break;
		}
	}

	char path[PATH_MAX];
	sprintf(path, "%s:%d", &gsys->mCurrentShape->mName[i + 1], mTextureIndex);

	gsys->addTexture(mTexture, path);
	mTexture->decodeData(mImage);
}

/*
 * --INFO--
 * Address:	80029108
 * Size:	0000AC
 */
void TexAttr::read(RandomAccessStream& stream)
{
	mTextureIndex = stream.readShort();
	stream.readShort();
	mTilingType       = stream.readShort();
	mUseOffsetImgData = stream.readShort();
	mLODBias          = stream.readFloat();
}

/*
 * --INFO--
 * Address:	800291B4
 * Size:	0002BC
 */
void Graphics::drawCylinder(immut Vector3f& p1, immut Vector3f& p2, f32 p3, immut Matrix4f& p4)
{
	useTexture(nullptr, GX_TEXMAP0);

	Vector3f vec1(p1);
	Vector3f vec2 = p2 - p1;
	f32 distance  = vec2.normalise();

	vec2 = vec2 * (distance / 16.0f);
	for (int i = 0; i < 16; i++) {
		Matrix4f a;
		Matrix4f b;

		a.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, f32(i) * (PI / 8.0f), 0.0f), vec1);
		p4.multiplyTo(a, b);
		useMatrix(b, 0);

		for (int j = 0; j < 16; j++) {
			// Calculate angles for current and next point
			f32 currentAngle = f32(j) * (PI / 8.0f);
			f32 nextAngle    = f32((j + 1) % 32) * (PI / 8.0f);

			drawLine(Vector3f(sinf(currentAngle) * p3, 0.0f, cosf(currentAngle) * p3),
			         Vector3f(sinf(nextAngle) * p3, 0.0f, cosf(nextAngle) * p3));
		}

		vec1 = vec1 + vec2;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E8
 */
void Graphics::drawCircle(immut Vector3f&, f32, immut Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80029470
 * Size:	0001FC
 */
void Graphics::drawSphere(immut Vector3f& p1, f32 p2, immut Matrix4f& p3)
{
	useTexture(nullptr, GX_TEXMAP0);

	for (int i = 0; i < 16; i++) {
		Matrix4f mtx1;
		Matrix4f mtx2;

		mtx1.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, f32(i) * (PI / 8.0f), 0.0f), p1);
		p3.multiplyTo(mtx1, mtx2);
		useMatrix(mtx2, 0);

		for (int j = 0; j < 16; j++) {
			f32 theta0 = f32(j) * (PI / 8.0f);
			f32 theta1 = f32((j + 1) % 32) * (PI / 8.0f);

			drawLine(Vector3f(sinf(theta0) * p2, cosf(theta0) * p2, 0.0f), Vector3f(sinf(theta1) * p2, cosf(theta1) * p2, 0.0f));
		}
	}
}

/*
 * --INFO--
 * Address:	8002966C
 * Size:	000170
 */
void Graphics::perspPrintf(Font* font, immut Vector3f& pos, int p3, int p4, immut char* fmt, ...)
{
	char buf[PATH_MAX];
	va_list vlist;
	va_start(vlist, fmt);
	vsprintf(buf, fmt, vlist);
	useTexture(font->mTexture, GX_TEXMAP0);
	int x = p3;
	int y = p4;
	for (int i = 0; i < (int)strlen(buf); i++) {
		RectArea rect(x - font->mChars[buf[i] - 32].mLeftOffset, font->mChars[buf[i] - 32].mHeight + y,
		              (x - font->mChars[buf[i] - 32].mLeftOffset) + font->mChars[buf[i] - 32].mWidth, y);
		drawRectangle(rect, font->mChars[buf[i] - 32].mTextureCoords, &pos);
		x += font->mChars[buf[i] - 32].mCharSpacing;
	}
}

/*
 * --INFO--
 * Address:	800297DC
 * Size:	000114
 */
int Graphics::calcLighting(f32 intensity)
{
	mLightIntensity = intensity;

	setAmbient();

	s32 lightIndex   = 0;
	mActiveLightMask = 0;

	FOREACH_NODE(Light, mLight.mChild, l)
	{
		mActiveLightMask |= 1 << lightIndex;
		setLight(l, lightIndex);

		// 8 light maximum, restricted by GX
		if (++lightIndex == 7u) {
			break;
		}
	}

	if (mLight.mChild) {
		mLightDistance = 50.0f;
		setLight((Light*)mLight.mChild, 7);
	}

	if (lightIndex > gsys->mActiveLightCount) {
		gsys->mActiveLightCount = lightIndex;
	}

	setLighting(true, nullptr);
	return lightIndex;

	s32 unused[2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001D0
 */
int Graphics::calcSphereLighting(immut Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003A4
 */
int Graphics::calcBoxLighting(immut BoundBox&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800298F4
 * Size:	00007C
 */
void CacheTexture::makeResident()
{
	if (gsys->mCacher && !gsys->mIsLoadingActive) {
		if (!mActiveCache) {
			gsys->mCacher->cacheTexture(this);
			gsys->copyCacheToTexture(this);
		} else {
			gsys->mCacher->updateInfo(this);
		}
	}
}
