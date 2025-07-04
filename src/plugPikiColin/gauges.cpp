#include "LifeGauge.h"
#include "Colour.h"
#include "sysNew.h"
#include "system.h"
#include "Light.h"
#include "Graphics.h"
#include "MoviePlayer.h"
#include "gameflow.h"
#include "DebugLog.h"

static Colour lgborder;
static Colour lglev0;
static Colour lglev1;
static Colour lglev2;
static Colour lglev3;

LifeGaugeMgr* lgMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Gauges")

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void GaugeInfo::init()
{
	mUpdateState    = 0;
	mAnimationPhase = 0.0f;
	mTextAlpha      = 0.0f;
	mHeightOffset   = 0.0f;
	PRINT("gauge init\n");
	mIsPendingRemoval = 0;
}

/*
 * --INFO--
 * Address:	8005B780
 * Size:	000150
 */
void GaugeInfo::update()
{
	switch (mUpdateState) {
	case 0: {
		mAnimationPhase += gsys->getFrameTime() * 2.0f;

		if (mAnimationPhase >= HALF_PI) {
			mUpdateState = 1;
		}

		f32 rotation = mAnimationPhase < HALF_PI ? mAnimationPhase : HALF_PI;

		mTextAlpha       = sinf(rotation) * 255.0f;
		mHeightOffset    = sinf(rotation) * 30.0f;
		mDigitBaseWidth  = sinf(rotation) * 8.0f;
		mDigitBaseHeight = sinf(rotation) * 8.0f;
		break;
	}

	case 1:
		if (mIsPendingRemoval) {
			mUpdateState = 2;
		}
		break;

	case 2:
		mTextAlpha -= gsys->getFrameTime() * 1200.0f;
		if (mTextAlpha < 0.0f) {
			mTextAlpha = 0.0f;
			lgMgr->removeLG(this);
		}
	}
}

/*
 * --INFO--
 * Address:	8005B8D0, 100377F0 in DLL
 * Size:	000210
 */
void GaugeInfo::showDigits(Vector3f position, Colour& colour, int number, f32 width, f32 height)
{
#if defined(VERSION_G98E01_PIKIDEMO)
	STACK_PAD_VAR(2);
	int num = number;
#else
	int num = number > 99 ? 99 : number;
#endif

	// Either 1 or 2 digits (0-99)
	int numDigits = num >= 10 ? 2 : 1;

	// If 2 digits, move the position to the left
	if (numDigits == 2) {
		position.x += width * 1.5f * 0.5f;
	}

	for (int i = 0; i < numDigits; i++) {
		f32 divisor = 1 / 11.0f;
		f32 uvStart = (num % 10) * divisor;
		f32 uvEnd   = ((num % 10) + 1.0f) * divisor;

		lgMgr->mLFlare->addLFlare(colour, position, Vector2f(width, height), &Vector2f(uvStart, 0.0f), &Vector2f(uvEnd, 1.0f));

		num /= 10;
		position.x -= width * 1.5f;
	}
	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	8005BAE0
 * Size:	000270
 */
void GaugeInfo::refresh(Graphics& gfx)
{
	Vector3f pos(mOwner->mPosition.x, mOwner->mPosition.y + mHeightOffset, mOwner->mPosition.z);
	pos.multMatrix(gfx.mCamera->mLookAtMtx);
	Colour colour;
	colour.set(255, 32, 32, (int)mTextAlpha);
	f32 a = (mPrimaryValue < mSecondaryValue) ? 0.75f : 1.0f;
	f32 b = (mPrimaryValue < mSecondaryValue) ? 1.0f : 0.75f;
	showDigits(pos, colour, mPrimaryValue, mDigitBaseWidth * a, mDigitBaseHeight * a);
	pos.y += 10.0f;
	f32 c = 1.0f;
	f32 d = 10.0f / 11.0f;
	lgMgr->mLFlare->addLFlare(colour, pos, Vector2f(mDigitBaseWidth, mDigitBaseHeight), &Vector2f(d, 0.0f), &Vector2f(c, 1.0f));
	pos.y += 10.0f;
	colour.set(32, 32, 255, (int)mTextAlpha);
	showDigits(pos, colour, mSecondaryValue, mDigitBaseWidth * b, mDigitBaseHeight * b);

	STACK_PAD_VAR(1);
	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	8005BD50
 * Size:	0000F0
 */
void LifeGaugeMgr::init(int count)
{
	mActiveGaugeList.initCore("");
	mInactiveGaugeList.initCore("");

	GaugeInfo* gaugeList = new GaugeInfo[count];

	for (int i = 0; i < count; i++) {
		mInactiveGaugeList.add(&gaugeList[i]);
	}

	mLFlare             = gsys->registerLFlare(gsys->loadTexture("intro/item_0_9.bti", true));
	mLFlare->mBlendMode = 5;
}

/*
 * --INFO--
 * Address:	8005BE94
 * Size:	000040
 */
void LifeGaugeMgr::update()
{
	FOREACH_NODE(GaugeInfo, mActiveGaugeList.mChild, gauge)
	{
		gauge->update();
	}
}

/*
 * --INFO--
 * Address:	8005BED4
 * Size:	000068
 */
void LifeGaugeMgr::refresh(Graphics& gfx)
{
	// WTF
	if (!gameflow.mMoviePlayer->mIsActive) {
		FOREACH_NODE(GaugeInfo, mActiveGaugeList.mChild, gauge)
		{
			gauge->refresh(gfx);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
GaugeInfo* LifeGaugeMgr::getGaugeInfo()
{
	if (mInactiveGaugeList.mChild) {
		GaugeInfo* info = (GaugeInfo*)mInactiveGaugeList.mChild;
		info->init();
		info->del();
		info->initCore("");
		return info;
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void LifeGaugeMgr::addLG(GaugeInfo* info)
{
	mActiveGaugeList.add(info);
}

/*
 * --INFO--
 * Address:	8005BF3C
 * Size:	000060
 */
void LifeGaugeMgr::removeLG(GaugeInfo* info)
{
	info->del();
	info->initCore("");
	mInactiveGaugeList.add(info);
}

/*
 * --INFO--
 * Address:	8005BF9C
 * Size:	0000D8
 */
LifeGauge::LifeGauge()
{
	mRenderStyle               = 0;
	mDisplayState              = 0;
	mFadeTransitionValue       = 0.0f;
	mVisibleHoldTimer          = 0.0f;
	mSnapToTargetHealth        = 0;
	mCurrentDisplayHealthRatio = 1.0f;
	mHealthRatio               = 1.0f;

	lgborder.set(0x80, 0x80, 0x80, 0xC0);
	lglev3.set(0x00, 0xFF, 0x00, 0xFF);
	lglev2.set(0x80, 0xFF, 0x00, 0xFF);
	lglev1.set(0xFF, 0xFF, 0x00, 0xFF);
	lglev0.set(0xFF, 0x00, 0x00, 0xFF);

	mOffset.set(0.0f, 100.0f, 0.0f);
	mScale       = 48.0f;
	mActiveGauge = 0;
}

/*
 * --INFO--
 * Address:	8005C074
 * Size:	000030
 */
void LifeGauge::updValue(f32 currHealth, f32 maxHealth)
{
	mHealthRatio = currHealth / maxHealth;
	if (mHealthRatio < 1.0f && mFadeTransitionValue != 1.0f) {
		mDisplayState = 1;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void LifeGauge::adjustValue()
{
	mCurrentDisplayHealthRatio += 2.0f * gsys->getFrameTime() * (mHealthRatio - mCurrentDisplayHealthRatio);
	if (mSnapToTargetHealth || absF(mCurrentDisplayHealthRatio - mHealthRatio) < 1.0f / 64.0f) {
		mCurrentDisplayHealthRatio = mHealthRatio;
	}
}

/*
 * --INFO--
 * Address:	8005C0A4
 * Size:	000EC8
 */
void LifeGauge::refresh(Graphics& gfx)
{
	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	switch (mDisplayState) {
	case 1:
		adjustValue();
		mFadeTransitionValue += 2.0f * gsys->getFrameTime();
		if (mFadeTransitionValue > 1.0f) {
			mFadeTransitionValue = 1.0f;
			mDisplayState        = 2;
			mVisibleHoldTimer    = 5.0f;
		}
		break;

	case 2:
		adjustValue();
		mVisibleHoldTimer -= gsys->getFrameTime();
		if (mVisibleHoldTimer <= 0.0f) {
			mVisibleHoldTimer = 0.0f;
			if (mRenderStyle == 0 || mCurrentDisplayHealthRatio <= 0.0f || mCurrentDisplayHealthRatio >= 1.0f) {
				mDisplayState = 3;
			}
		}
		break;

	case 3:
		mFadeTransitionValue -= 2.0f * gsys->getFrameTime();
		if (mFadeTransitionValue < 0.0f) {
			mFadeTransitionValue = 0.0f;
			mDisplayState        = 0;
		}
		break;
	}

	if (mDisplayState == 0) {
		return;
	}

	Colour colour;
	if (mCurrentDisplayHealthRatio > 0.75f) {
		lglev3.lerpTo(lglev2, 1.0f - (mCurrentDisplayHealthRatio - 0.75f) / 0.25f, colour);
	} else if (mCurrentDisplayHealthRatio > 0.5f) {
		lglev2.lerpTo(lglev1, 1.0f - (mCurrentDisplayHealthRatio - 0.5f) / 0.25f, colour);
	} else if (mCurrentDisplayHealthRatio > 0.25f) {
		lglev1.lerpTo(lglev0, 1.0f - (mCurrentDisplayHealthRatio - 0.25f) / 0.25f, colour);
	} else {
		colour = lglev0;
	}

	gfx.useTexture(nullptr, 0);
	Vector3f pos1 = mPosition + mOffset;
	Vector3f pos2 = mPosition + mOffset;

	f32 proj1 = gfx.mCamera->projectWorldPoint(gfx, pos1);
	f32 proj2 = gfx.mCamera->projectWorldPoint(gfx, pos2);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.setAuxColour(Colour(255, 255, 255, 255));

	STACK_PAD_VAR(2);
	if (proj1 > 0.0f && proj2 > 0.0f) {
		if (mRenderStyle == 0) {
			gfx.setColour(Colour(lgborder.r, lgborder.g, lgborder.b, (int)(f32(lgborder.a) * mFadeTransitionValue)), true);
			gfx.setAuxColour(Colour(lgborder.r, lgborder.g, lgborder.b, (int)(f32(lgborder.a) * mFadeTransitionValue)));
			gfx.lineRectangle(RectArea(pos2.x - 19.0f, pos2.y - 10.0f, pos2.x + 19.0f, pos2.y - 6.0f));

			gfx.drawLine(Vector3f(pos2.x - 10.0f, pos2.y - 5.0f, 0.0f), Vector3f(pos1.x, pos1.y, 0.0f));
			gfx.drawLine(Vector3f(pos2.x - 5.0f, pos2.y - 5.0f, 0.0f), Vector3f(pos1.x, pos1.y, 0.0f));

			gfx.setColour(Colour(colour.r, colour.g, colour.b, (int)(f32(colour.a) * mFadeTransitionValue)), true);
			gfx.setAuxColour(Colour(colour.r, colour.g, colour.b, (int)(f32(colour.a) * mFadeTransitionValue)));
			gfx.fillRectangle(
			    RectArea(pos2.x - 18.0f, pos2.y - 9.0f, pos2.x - 18.0f + (mCurrentDisplayHealthRatio * 37.0f), pos2.y - 7.0f));
			return;
		}

		f32 a = mScale * (1.0f - proj1);
		f32 b = a * 1.1666f;

		Vector3f vecs3D[4];
		Vector2f vecs2D[4];

		vecs2D[0].set(0.0f, 0.0f);
		vecs2D[1].set(0.0f, 0.0f);
		vecs2D[2].set(0.0f, 0.0f);
		vecs2D[3].set(0.0f, 0.0f);

		for (int i = 0; i < 32; i++) {
			f32 angle1 = f32(i) * (11.25f * PI / 180.0f);
			f32 angle2 = f32((i + 1) % 32) * (11.25f * PI / 180.0f);
			vecs3D[0].set(pos2.x, pos2.y, 0.0f);
			vecs3D[1].set(sinf(angle2) * -a + pos2.x, cosf(angle2) * -a + pos2.y, 0.0f);
			vecs3D[2].set(sinf(angle1) * -a + pos2.x, cosf(angle1) * -a + pos2.y, 0.0f);
			if ((mCurrentDisplayHealthRatio > 0.0f && i == 0) || i < int(32.0f * mCurrentDisplayHealthRatio)) {
				gfx.setColour(colour, true);
				gfx.drawOneTri(vecs3D, nullptr, vecs2D, 3);
			} else {
				gfx.setColour(Colour(32, 32, 32, 192), true);
				gfx.drawOneTri(vecs3D, nullptr, vecs2D, 3);
			}

			vecs3D[0].set(sinf(angle2) * -a + pos2.x, cosf(angle2) * -a + pos2.y, 0.0f);
			vecs3D[1].set(sinf(angle2) * -b + pos2.x, cosf(angle2) * -b + pos2.y, 0.0f);
			vecs3D[2].set(sinf(angle1) * -b + pos2.x, cosf(angle1) * -b + pos2.y, 0.0f);
			vecs3D[3].set(sinf(angle1) * -a + pos2.x, cosf(angle1) * -a + pos2.y, 0.0f);

			gfx.setColour(Colour(0, 0, 0, 255), true);
			gfx.drawOneTri(vecs3D, nullptr, vecs2D, 4);
		}
	}
}

/*
 * --INFO--
 * Address:	8005CF6C
 * Size:	000148
 */
void LifeGauge::countOn(Vector3f& p1, int p2, int p3)
{
	if (!mActiveGauge) {
		mCurrentDisplayHealthRatio = p2;
		mDisplayState              = 0;
		mVisibleHoldTimer          = 0.0f;
		if (mActiveGauge) {
			mActiveGauge->mIsPendingRemoval = 1;
			mActiveGauge                    = nullptr;
		}
		GaugeInfo* info = lgMgr->getGaugeInfo();
		if (info) {
			info->mOwner          = this;
			info->mPrimaryValue   = p2;
			info->mSecondaryValue = p3;
			lgMgr->addLG(info);
			mActiveGauge = info;
		}
	} else {
		mActiveGauge->mPrimaryValue   = p2;
		mActiveGauge->mSecondaryValue = p3;
	}

	mPosition = p1;
	if (mActiveGauge) {
		mActiveGauge->mOwnerCachedPosition = mPosition;
	}

	STACK_PAD_VAR(1);
}

/*
 * --INFO--
 * Address:	8005D0B4
 * Size:	000030
 */
void LifeGauge::countOff()
{
	mDisplayState     = -1;
	mVisibleHoldTimer = 0.0f;
	if (mActiveGauge) {
		mActiveGauge->mIsPendingRemoval = 1;
		mActiveGauge                    = nullptr;
	}
}
