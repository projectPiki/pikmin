#include "RumbleMgr.h"
#include "NaviMgr.h"
#include "sysNew.h"
#include "DebugLog.h"

RumbleMgr* rumbleMgr;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

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

/*
 * --INFO--
 * Address:	8017C868
 * Size:	000028
 */
ChannelMgr::ChannelMgr()
{
	_00         = 0.0f;
	_04         = 0.0f;
	_08         = 1.0f;
	mActiveType = -1;
	mData       = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void ChannelMgr::init(ChannelDataMgr* dataMgr)
{
	_00         = 0.0f;
	_04         = 0.0f;
	_08         = 1.0f;
	mActiveType = -1;
	mData       = nullptr;
	mDataMgr    = dataMgr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void ChannelMgr::reset()
{
	_00         = 0.0f;
	_04         = 0.0f;
	_08         = 1.0f;
	mActiveType = -1;
	mData       = nullptr;
}

/*
 * --INFO--
 * Address:	8017C890
 * Size:	000060
 */
void ChannelMgr::start(int idx, f32* valuePtr)
{
	_00         = 0.0f;
	mData       = mDataMgr->getChannelDataTbl(idx);
	mActiveType = idx;
	if (valuePtr) {
		if (*valuePtr < 0.0f) {
			ERROR("変な値が入ってます"); // 'there is a weird value' (lol)
		}

		if (*valuePtr < 1000.0f) {
			_08 = 1.0f - (*valuePtr / 1000.0f);
		} else {
			_08 = 0.0f;
		}
	} else {
		_08 = 1.0f;
	}
}

/*
 * --INFO--
 * Address:	8017C8F0
 * Size:	0000FC
 */
f32 ChannelMgr::update()
{
	_04 = 0.0f;
	if (mData) {
		_00 += gsys->getFrameTime();
		for (int i = 0; i < mData->mRumblePoint->_00 - 1; i++) {
			if (_00 > mData->mRumbleFrame[i]) {
				f32 ratio = (_00 - mData->mRumbleFrame[i]) / (mData->mRumbleFrame[i + 1] - mData->mRumbleFrame[i]);
				_04       = (1.0f - ratio) * mData->mRumblePower[i] + ratio * mData->mRumblePower[i + 1];
			}
		}

		if (_00 > mData->mRumbleFrame[mData->mRumblePoint->_00 - 1]) {
			reset();
		}
	}

	_04 *= _08;
	return _04;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
ControlerMgr::ControlerMgr()
{
	_00          = 0.0f;
	mChannelMgrs = new ChannelMgr[32];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000188
 */
void ControlerMgr::init()
{
	_00 = 0.0f;
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
	_00 = 0.0f;
	for (int i = 0; i < 32; i++) {
		mChannelMgrs[i].reset();
	}
}

/*
 * --INFO--
 * Address:	8017C9EC
 * Size:	00009C
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
	f32 maxVal = 0.0f;
	for (int i = 0; i < 32; i++) {
		_00 = mChannelMgrs[i].update();
		if (_00 > maxVal) {
			maxVal = _00;
		}
	}

	_00 = maxVal;

	if (_00 > 1.0f) {
		_00 = 1.0f;
	} else if (_00 < 0.0f) {
		_00 = 0.0f;
	}

	return _00;
}

/*
 * --INFO--
 * Address:	8017CA88
 * Size:	000120
 */
RumbleMgr::RumbleMgr(bool p1, bool p2, bool p3, bool p4)
{
	_00 = 0.0f;
	_04 = 0.0f;
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

	mDataMgr = nullptr;
	mDataMgr = new ChannelDataMgr();
	_08      = 1;
	_09      = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001F8
 */
void RumbleMgr::init()
{
	_00 = 0.0f;
	_04 = 0.0f;
	for (int i = 0; i < 4; i++) {
		if (mControlerMgrs[i]) {
			mControlerMgrs[i]->init();
		}
		if (mSamples[i]) {
			mSamples[i]->init();
		}
	}

	mDataMgr->init();
	_08 = 1;
	_09 = 0;
}

/*
 * --INFO--
 * Address:	8017CBA8
 * Size:	0001A0
 */
void RumbleMgr::reset()
{
	_00 = 0.0f;
	_04 = 0.0f;
	for (int i = 0; i < 4; i++) {
		if (mControlerMgrs[i]) {
			mControlerMgrs[i]->reset();
		}
		if (mSamples[i]) {
			mSamples[i]->simpleStop();
		}
	}
	_09 = 0;
}

/*
 * --INFO--
 * Address:	8017CD48
 * Size:	00008C
 */
void RumbleMgr::start(int type, int ctrlNum, f32* valuePtr)
{
	if (!_09 && _08) {
		if (mControlerMgrs[ctrlNum]) {
			mControlerMgrs[ctrlNum]->start(type, valuePtr);
		}
	}
}

/*
 * --INFO--
 * Address:	8017CDD4
 * Size:	000120
 */
void RumbleMgr::start(int type, int ctrlNum, Vector3f& sourcePos)
{
	if (!_09 && _08) {
		if (mControlerMgrs[ctrlNum]) {
			Navi* navi = naviMgr->getNavi(ctrlNum);
			f32 dist   = navi->getPosition().distance(sourcePos);
			start(type, ctrlNum, &dist);
		}
	}
}

/*
 * --INFO--
 * Address:	8017CEF4
 * Size:	0001C4
 */
void RumbleMgr::stop()
{
	for (int i = 0; i < 4; i++) {
		if (mControlerMgrs[i]) {
			mControlerMgrs[i]->stop();
		}
	}
}

/*
 * --INFO--
 * Address:	8017D0B8
 * Size:	000140
 */
void RumbleMgr::stop(int type, int ctrlNum)
{
	if (!_09 && _08) {
		if (mControlerMgrs[ctrlNum]) {
			mControlerMgrs[ctrlNum]->stop(type);
		}
	}
}

/*
 * --INFO--
 * Address:	8017D1F8
 * Size:	00016C
 */
void RumbleMgr::update()
{
	if (!_09 && _08) {
		for (int i = 0; i < 4; i++) {
			if (mControlerMgrs[i]) {
				_00 = mControlerMgrs[i]->update();
				if (_04 > 0.0f) {
					_00 *= (1.0f - _00) * (_04 / 0.5f) + 1.0f;
				}

				if (_00 > 1.0f) {
					_00 = 1.0f;
				} else if (_00 < 0.0f) {
					_00 = 0.0f;
				}

				mSamples[i]->simpleStart(_00);
			}
		}

		if (_04 > 0.0f) {
			_04 -= gsys->getFrameTime();
		}
	}
}

/*
 * --INFO--
 * Address:	8017D364
 * Size:	00031C
 */
void RumbleMgr::rumbleOption(bool p1)
{
	// lol.
	_08 = p1;
	if (!_08) {
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
