#include "Omake.h"
#include "NaviMgr.h"
#include "Pcam/CameraManager.h"
#include "Pcam/Camera.h"
#include "KMath.h"
#include "stl/math.h"
#include "DebugLog.h"
#include "sysNew.h"

AttentionCamera* attentionCamera;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("attentionCamera")

/*
 * --INFO--
 * Address:	80078DB0
 * Size:	0001E8
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

/*
 * --INFO--
 * Address:	........
 * Size:	000054
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

/*
 * --INFO--
 * Address:	80079464
 * Size:	000050
 */
void AttentionCamera::finish()
{
	mTarget    = naviMgr->getNavi();
	mFadeState = 1;
	mActiveFader->initFadeOut();
}

/*
 * --INFO--
 * Address:	800794B4
 * Size:	0000F0
 */
void AttentionCamera::update()
{
	switch (mFadeState) {
	case 1:
		if (!mActiveFader->updateFadeOut()) {
			return;
		}
		mTarget->mFaceDirection = roundAng(getCameraSafeAngle(mTarget->mPosition, 600.0f, 400.0f));

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

/*
 * --INFO--
 * Address:	800795B8
 * Size:	00005C
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

/*
 * --INFO--
 * Address:	........
 * Size:	000058
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

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
void NoiseFunction::init(int count)
{
	mCount  = count;
	mValues = new f32[mCount];
	for (int i = 0; i < count; i++) {
		mValues[i] = gsys->getRand(1.0f);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
f32 NoiseFunction::getValue(f32 x)
{
	int boundX = (int)x % mCount;
	f32 roundX = x - boundX;
	return (1.0f - roundX) * mValues[boundX] + roundX * mValues[(int)(x + 1.0f) % mCount];
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
void TurbulenceFun::init(int p1, int count)
{
	NoiseFunction::init(count);
	_UNUSED08  = p1;
	mFrequency = p1 / count;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000240
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
