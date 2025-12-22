#include "DebugLog.h"
#include "NaviMgr.h"
#include "RumbleMgr.h"
#include "sysNew.h"

RumbleMgr* rumbleMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(12)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
ChannelDataMgr::ChannelDataMgr()
{
	mDataTbl = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void ChannelDataMgr::init()
{
	mDataTbl = channelDataTbl;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
ChannelData* ChannelDataMgr::getChannelDataTbl(int row)
{
	return &channelDataTbl[row];
}

/**
 * @TODO: Documentation
 */
ChannelMgr::ChannelMgr()
{
	mRumbleTimer     = 0.0f;
	mRumbleIntensity = 0.0f;
	mRumbleScale     = 1.0f;
	mActiveType      = -1;
	mData            = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void ChannelMgr::init(ChannelDataMgr* dataMgr)
{
	mRumbleTimer     = 0.0f;
	mRumbleIntensity = 0.0f;
	mRumbleScale     = 1.0f;
	mActiveType      = -1;
	mData            = nullptr;
	mDataMgr         = dataMgr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void ChannelMgr::reset()
{
	mRumbleTimer     = 0.0f;
	mRumbleIntensity = 0.0f;
	mRumbleScale     = 1.0f;
	mActiveType      = -1;
	mData            = nullptr;
}

/**
 * @TODO: Documentation
 */
void ChannelMgr::start(int idx, f32* valuePtr)
{
	mRumbleTimer = 0.0f;
	mData        = mDataMgr->getChannelDataTbl(idx);
	mActiveType  = idx;
	if (valuePtr) {
		if (*valuePtr < 0.0f) {
			ERROR("変な値が入ってます"); // 'there is a weird value' (lol)
		}

		if (*valuePtr < 1000.0f) {
			mRumbleScale = 1.0f - (*valuePtr / 1000.0f);
		} else {
			mRumbleScale = 0.0f;
		}
	} else {
		mRumbleScale = 1.0f;
	}
}

/**
 * @TODO: Documentation
 */
f32 ChannelMgr::update()
{
	mRumbleIntensity = 0.0f;

	if (mData) {
		mRumbleTimer += gsys->getFrameTime();
		for (int i = 0; i < *mData->mRumblePoint - 1; i++) {
			if (mRumbleTimer > mData->mRumbleFrame[i]) {
				f32 ratio        = (mRumbleTimer - mData->mRumbleFrame[i]) / (mData->mRumbleFrame[i + 1] - mData->mRumbleFrame[i]);
				mRumbleIntensity = (1.0f - ratio) * mData->mRumblePower[i] + ratio * mData->mRumblePower[i + 1];
			}
		}

		if (mRumbleTimer > mData->mRumbleFrame[*mData->mRumblePoint - 1]) {
			reset();
		}
	}

	mRumbleIntensity *= mRumbleScale;
	return mRumbleIntensity;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
ControlerMgr::ControlerMgr()
{
	mRumbleIntensity = 0.0f;
	mChannelMgrs     = new ChannelMgr[32];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000188
 */
void ControlerMgr::init()
{
	mRumbleIntensity = 0.0f;
	for (int i = 0; i < 32; i++) {
		mChannelMgrs[i].init(mDataMgr);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void ControlerMgr::reset()
{
	mRumbleIntensity = 0.0f;
	for (int i = 0; i < 32; i++) {
		mChannelMgrs[i].reset();
	}
}

/**
 * @TODO: Documentation
 */
void ControlerMgr::start(int idx, f32* valuePtr)
{
	for (int i = 0; i < 32; i++) {
		if (mChannelMgrs[i].isFree()) {
			mChannelMgrs[i].start(idx, valuePtr);
			return;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
void ControlerMgr::stop()
{
	for (int i = 0; i < 32; i++) {
		if (!mChannelMgrs[i].isFree()) {
			mChannelMgrs[i].reset();
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void ControlerMgr::stop(int type)
{
	for (int i = 0; i < 32; i++) {
		if (!mChannelMgrs[i].isFree() && mChannelMgrs[i].getActiveType() == type) {
			mChannelMgrs[i].reset();
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000AC
 */
f32 ControlerMgr::update()
{
	f32 peakRumbleValue = 0.0f;
	for (int i = 0; i < 32; i++) {
		mRumbleIntensity = mChannelMgrs[i].update();
		if (mRumbleIntensity > peakRumbleValue) {
			peakRumbleValue = mRumbleIntensity;
		}
	}

	mRumbleIntensity = peakRumbleValue;

	if (mRumbleIntensity > 1.0f) {
		mRumbleIntensity = 1.0f;
	} else if (mRumbleIntensity < 0.0f) {
		mRumbleIntensity = 0.0f;
	}

	return mRumbleIntensity;
}

/**
 * @TODO: Documentation
 */
RumbleMgr::RumbleMgr(bool p1, bool p2, bool p3, bool p4)
{
	mRumbleIntensity    = 0.0f;
	mRumbleFadeOutTimer = 0.0f;
	bool valArray[4];
	valArray[0] = p1;
	valArray[1] = p2;
	valArray[2] = p3;
	valArray[3] = p4;

	for (int i = 0; i < 4; i++) {
		mControlerMgrs[i] = nullptr;
		mSamples[i]       = nullptr;
		if (valArray[i]) {
			mControlerMgrs[i] = new ControlerMgr();
			mSamples[i]       = new RumbleSample(i);
		}
	}

	mDataMgr    = nullptr;
	mDataMgr    = new ChannelDataMgr();
	mIsEnabled  = 1;
	mIsDisabled = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001F8
 */
void RumbleMgr::init()
{
	mRumbleIntensity    = 0.0f;
	mRumbleFadeOutTimer = 0.0f;
	for (int i = 0; i < 4; i++) {
		if (mControlerMgrs[i]) {
			mControlerMgrs[i]->init();
		}
		if (mSamples[i]) {
			mSamples[i]->init();
		}
	}

	mDataMgr->init();
	mIsEnabled  = 1;
	mIsDisabled = 0;
}

/**
 * @TODO: Documentation
 */
void RumbleMgr::reset()
{
	mRumbleIntensity    = 0.0f;
	mRumbleFadeOutTimer = 0.0f;
	for (int i = 0; i < 4; i++) {
		if (mControlerMgrs[i]) {
			mControlerMgrs[i]->reset();
		}
		if (mSamples[i]) {
			mSamples[i]->simpleStop();
		}
	}
	mIsDisabled = 0;
}

/**
 * @TODO: Documentation
 */
void RumbleMgr::start(int type, int ctrlNum, f32* valuePtr)
{
	if (!mIsDisabled && mIsEnabled) {
		if (mControlerMgrs[ctrlNum]) {
			mControlerMgrs[ctrlNum]->start(type, valuePtr);
		}
	}
}

/**
 * @TODO: Documentation
 */
void RumbleMgr::start(int type, int ctrlNum, immut Vector3f& sourcePos)
{
	if (!mIsDisabled && mIsEnabled) {
		if (mControlerMgrs[ctrlNum]) {
			Navi* navi = naviMgr->getNavi(ctrlNum);
			f32 dist   = navi->getPosition().distance(sourcePos);
			start(type, ctrlNum, &dist);
		}
	}
}

/**
 * @TODO: Documentation
 */
void RumbleMgr::stop()
{
	for (int i = 0; i < 4; i++) {
		if (mControlerMgrs[i]) {
			mControlerMgrs[i]->stop();
		}
	}
}

/**
 * @TODO: Documentation
 */
void RumbleMgr::stop(int rumbleType, int controllerIndex)
{
	if (!mIsDisabled && mIsEnabled) {
		if (mControlerMgrs[controllerIndex]) {
			mControlerMgrs[controllerIndex]->stop(rumbleType);
		}
	}
}

/**
 * @TODO: Documentation
 */
void RumbleMgr::update()
{
	if (!mIsDisabled && mIsEnabled) {
		for (int i = 0; i < 4; i++) {
			if (mControlerMgrs[i]) {
				mRumbleIntensity = mControlerMgrs[i]->update();
				if (mRumbleFadeOutTimer > 0.0f) {
					mRumbleIntensity *= (1.0f - mRumbleIntensity) * (mRumbleFadeOutTimer / 0.5f) + 1.0f;
				}

				if (mRumbleIntensity > 1.0f) {
					mRumbleIntensity = 1.0f;
				} else if (mRumbleIntensity < 0.0f) {
					mRumbleIntensity = 0.0f;
				}

				mSamples[i]->simpleStart(mRumbleIntensity);
			}
		}

		if (mRumbleFadeOutTimer > 0.0f) {
			mRumbleFadeOutTimer -= gsys->getFrameTime();
		}
	}
}

/**
 * @TODO: Documentation
 */
void RumbleMgr::rumbleOption(bool p1)
{
	mIsEnabled = p1;

	if (!mIsEnabled) {
		reset();
	} else {
		reset();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void RumbleMgr::rumblePause(bool)
{
	// UNUSED FUNCTION
}
