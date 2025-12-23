#include "Omake.h"
#include "DebugLog.h"
#include "KMath.h"
#include "NaviMgr.h"
#include "Pcam/Camera.h"
#include "Pcam/CameraManager.h"
#include "stl/math.h"
#include "sysMath.h"
#include "sysNew.h"

AttentionCamera* attentionCamera;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("attentionCamera")

/**
 * @TODO: Documentation
 */
AttentionCamera::AttentionCamera()
{
	mFadeState  = 0;
	mMaxFaders  = 4;
	mFaderCount = 0;
	mFaders     = new Fader*[mMaxFaders];
	for (int i = 0; i < mMaxFaders; i++) {
		mFaders[i] = nullptr;
	}

	mFaders[0] = new DefaultFader();
	mFaderCount++;

	mFaders[1] = new SimpleFader();
	mFaderCount++;

	mFaders[2] = new ClothFader();
	mFaderCount++;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000054
 */
void AttentionCamera::start(u32 tag, Creature* target, f32 p3, f32 p4)
{
	mFadeState = 1;
	mTarget    = target;
	_UNUSED18  = p3;
	_UNUSED1C  = p4;
	setFader(tag);
	mActiveFader->initFadeOut();
}

/**
 * @TODO: Documentation
 */
void AttentionCamera::finish()
{
	mTarget    = naviMgr->getNavi();
	mFadeState = 1;
	mActiveFader->initFadeOut();
}

/**
 * @TODO: Documentation
 */
void AttentionCamera::update()
{
	switch (mFadeState) {
	case 1:
		if (!mActiveFader->updateFadeOut()) {
			return;
		}
		mTarget->mFaceDirection = roundAng(getCameraSafeAngle(mTarget->mSRT.t, 600.0f, 400.0f));

		// lol.
		if (mTarget->mObjType != OBJTYPE_Navi) {
			cameraMgr->mCamera->startCamera(mTarget);
		} else {
			cameraMgr->mCamera->startCamera(mTarget);
		}

		mFadeState = 2;
		mActiveFader->initFadeIn();
		break;
	case 2:
		if (mActiveFader->updateFadeIn()) {
			mFadeState = 0;
		}
		break;
	}
}

/**
 * @TODO: Documentation
 */
void AttentionCamera::refresh(Graphics& gfx)
{
	if (mFadeState == 1) {
		mActiveFader->drawFadeOut(gfx);
		return;
	}

	if (mFadeState == 2) {
		mActiveFader->drawFadeIn(gfx);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000058
 */
void AttentionCamera::setFader(u32 tag)
{
	int idx = 0;
	for (int i = 0; i < mFaderCount; i++) {
		if (mFaders[i]->mTag == tag) {
			idx = i;
			break;
		}
	}

	mActiveFader = mFaders[idx];
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000AC
 */
void NoiseFunction::init(int count)
{
	mCount  = count;
	mValues = new f32[mCount];
	for (int i = 0; i < count; i++) {
		mValues[i] = gsys->getRand(1.0f);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00008C
 */
f32 NoiseFunction::getValue(f32 x)
{
	int boundX = (int)x % mCount;
	f32 roundX = x - boundX;
	return (1.0f - roundX) * mValues[boundX] + roundX * mValues[(int)(x + 1.0f) % mCount];
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000EC
 */
void TurbulenceFun::init(int p1, int count)
{
	NoiseFunction::init(count);
	_UNUSED08  = p1;
	mFrequency = p1 / count;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000240
 */
f32 TurbulenceFun::getValue(f32 x)
{
	f32 res    = 0.0f;
	int a      = log(mFrequency) / log(2.0f);
	f32 b      = 1.0f;
	f32 factor = x / mFrequency;

	for (int i = 0; i < a; i++) {
		res += NoiseFunction::getValue(b * factor) / b;
		b *= 2.0f;
	}

	return res;
}
