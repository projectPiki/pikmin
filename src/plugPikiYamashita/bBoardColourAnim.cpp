#include "zen/bBoardColourAnim.h"
#include "Colour.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("bBoardColourAnim")

// these are functions in the DLL, but I have no idea what their names are or if they're even in the DLL map we have
// I think they're probably genuinely static inlines, same as in particleGenerator. Thanks Yamashita.

static inline void bBoard_readU8(u8* outVal, u8*& data, u32 size)
{
	*outVal = *data;
	data += size;
}

static inline void bBoard_readFloatArray(f32** outArray, u8*& data, u32 size)
{
	*outArray = (f32*)data;
	for (u32 i = 0; i < size; i++) {
		data += 4;
	}
}

static inline void bBoard_readColourArray(Colour** outVal, u8*& data, u32 size)
{
	*outVal = (Colour*)data;
	data += size << 2;
}

static inline u8 bBoard_lerpColorComp(u8 c1, f32 r1, u8 c2, f32 r2)
{
	return c1 * r1 + c2 * r2;
}

static inline void bBoard_lerpColor(Colour* outColor, Colour* colA, f32 ratioA, Colour* colB, f32 ratioB)
{
	outColor->r = bBoard_lerpColorComp(colA->r, ratioA, colB->r, ratioB);
	outColor->g = bBoard_lerpColorComp(colA->g, ratioA, colB->g, ratioB);
	outColor->b = bBoard_lerpColorComp(colA->b, ratioA, colB->b, ratioB);
	outColor->a = bBoard_lerpColorComp(colA->a, ratioA, colB->a, ratioB);
}

/*
 * --INFO--
 * Address:	801A1E10
 * Size:	00009C
 */
void zen::bBoardColourAnimData::set(u8* data)
{
	if (data) {
		bBoard_readU8(&mBlendMode, data, 1);
		bBoard_readU8(&_01, data, 1);
		bBoard_readU8(&mFlags.all, data, 1);
		bBoard_readU8(&mMaxFrame, data, 1);
		bBoard_readFloatArray(&mFrameThresholds, data, mMaxFrame);
		bBoard_readColourArray(&mPrimColors, data, mMaxFrame);
		bBoard_readColourArray(&mEnvColors, data, mMaxFrame);
	}
}

/*
 * --INFO--
 * Address:	801A1EAC
 * Size:	0003C0
 */
void zen::bBoardColourAnim::update(f32 timeStep, Colour* primColor, Colour* envColor)
{
	f32 currThresh = (mLifeTime - 1) * mAnimData->mFrameThresholds[mFrame];
	f32 nextThresh = (mLifeTime - 1) * mAnimData->mFrameThresholds[mFrame + 1];
	f32 t          = (mAge - currThresh) / (nextThresh - currThresh);

	if (t > 1.0f) {
		t = 1.0f;
	}

	bBoard_lerpColor(primColor, &mAnimData->mPrimColors[mFrame], 1.0f - t, &mAnimData->mPrimColors[mFrame + 1], t);
	bBoard_lerpColor(envColor, &mAnimData->mEnvColors[mFrame], 1.0f - t, &mAnimData->mEnvColors[mFrame + 1], t);

	if (mAge >= nextThresh && ++mFrame >= mAnimData->mMaxFrame - 1) {
		if (mAnimData->mFlags.all) {
			mFrame = mAnimData->mMaxFrame - 1;
		} else {
			mFrame = 0;
		}
	}

	mAge += timeStep;
	if (mAge >= mLifeTime) {
		if (mAnimData->mFlags.all) {
			mAge   = mLifeTime;
			mFrame = mAnimData->mMaxFrame - 1;
		} else {
			mAge   = 0.0f;
			mFrame = 0;
		}
	}
}
