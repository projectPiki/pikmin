#include "PaniAnimator.h"
#include "sysNew.h"
#include "PikiMacros.h"
#include "nlib/System.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "panianimator");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

char* PaniAnimator::keyNames[6] = {
	"loop start", "loop end", "action 0", "action 1", "action 2", "action 3",
};

/*
 * --INFO--
 * Address:	8011EF58
 * Size:	000034
 */
PaniMotionInfo::PaniMotionInfo(int motionIdx) { init(motionIdx, nullptr); }

/*
 * --INFO--
 * Address:	8011EF8C
 * Size:	000030
 */
PaniMotionInfo::PaniMotionInfo(int motionIdx, PaniAnimKeyListener* listener) { init(motionIdx, listener); }

/*
 * --INFO--
 * Address:	8011EFBC
 * Size:	00000C
 */
void PaniMotionInfo::init(int motionIdx, PaniAnimKeyListener* listener)
{
	mMotionIdx = motionIdx;
	mListener  = listener;
}

/*
 * --INFO--
 * Address:	8011EFC8
 * Size:	000034
 */
PaniMotion::PaniMotion(int p1) { init(p1, 1); }

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
PaniMotion::PaniMotion(int p1, int p2)
{
	init(p1, p2);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011EFFC
 * Size:	00000C
 */
void PaniMotion::init(int p1, int p2)
{
	_00 = p1;
	_04 = p2;
}

/*
 * --INFO--
 * Address:	8011F008
 * Size:	00006C
 */
PaniMotionTable::PaniMotionTable(int count)
{
	mMotionCount = count;
	mMotions     = new PaniMotion*[mMotionCount];

	for (int i = 0; i < mMotionCount; i++) {
		mMotions[i] = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8011F074
 * Size:	00006C
 */
PaniSoundTable::PaniSoundTable(int count)
{
	mSoundCount = count;
	mSounds     = new u32*[mSoundCount];

	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = 0;
	}
}

/*
 * --INFO--
 * Address:	8011F0E0
 * Size:	000044
 */
PaniAnimator::PaniAnimator()
{
	_38           = -1;
	mIsFinished   = false;
	mListener     = nullptr;
	mAnimInfo     = nullptr;
	mMotionTable  = nullptr;
	mMotionIdx    = -1;
	mCurrentFrame = 0.0f;
}

/*
 * --INFO--
 * Address:	8011F124
 * Size:	00006C
 */
void PaniAnimator::init(AnimContext* context, AnimMgr* mgr, PaniMotionTable* table)
{
	mContext      = context;
	mMgr          = mgr;
	mAnimInfo     = nullptr;
	mCurrentFrame = 0.0f;
	mMotionTable  = table;
	if (mgr->countAnims()) {
		startAnim(2, 0, 0, 8);
	}
}

/*
 * --INFO--
 * Address:	8011F190
 * Size:	000008
 */
void PaniAnimator::changeContext(AnimContext* context) { mContext = context; }

/*
 * --INFO--
 * Address:	8011F198
 * Size:	000028
 */
void PaniAnimator::updateContext()
{
	if (mAnimInfo) {
		mContext->mData         = mAnimInfo->mData;
		mContext->mCurrentFrame = mCurrentFrame;
	}
}

/*
 * --INFO--
 * Address:	8011F1C0
 * Size:	000070
 */
void PaniAnimator::startMotion(PaniMotionInfo& info)
{
	if (mAnimInfo) {
		mMotionIdx  = info.mMotionIdx;
		mListener   = info.mListener;
		_38         = 0;
		_40         = 0;
		mIsFinished = false;
		startAnim(2, mMotionTable->mMotions[mMotionIdx]->_00, 0, 8);
	}
}

/*
 * --INFO--
 * Address:	8011F230
 * Size:	0000B0
 */
void PaniAnimator::finishMotion(PaniMotionInfo& info)
{
	if (!mAnimInfo) {
		return;
	}

	mListener   = info.mListener;
	mIsFinished = true;

	f32 maxFrame = (f32)((!mAnimInfo) ? -1 : mAnimInfo->mData->mNumFrames);
	if (mCurrentFrame >= maxFrame) {
		mCurrentFrame = maxFrame;
		finishAnimation();
	} else {
		startAnim(2, _1C, -1, 8);
	}
}

/*
 * --INFO--
 * Address:	8011F2E0
 * Size:	00010C
 */
void PaniAnimator::animate(f32 speed)
{
	if (!mAnimInfo) {
		return;
	}

	if (speed < 0.0f) {
		DEBUGPRINT(_38 < 0);
	}

	if (_38 < 0) {
		return;
	}

	f32 keyVal1 = (f32)mAnimInfo->getKeyValue(_20);
	f32 keyVal2 = (f32)mAnimInfo->getKeyValue(_24);
	if (keyVal1 > keyVal2) {
		DEBUGPRINT(keyVal1 < keyVal2);
		return;
	}

	speed *= NSystem::system->getFrameTime();
	mCurrentFrame += speed;

	checkConstantKeys();
	checkEventKeys(mCurrentFrame - speed, mCurrentFrame);
	if (mCurrentFrame >= keyVal2) {
		mCurrentFrame = keyVal2;
		finishAnimation();
	}
}

/*
 * --INFO--
 * Address:	8011F3EC
 * Size:	0000D0
 */
void PaniAnimator::checkConstantKeys()
{
	if (_38 < 0) {
		DEBUGPRINT(mAnimInfo->countIKeys());
	}

	if (mAnimInfo->countIKeys() > 16) {
		DEBUGPRINT(mAnimInfo->countIKeys());
	}

	for (_38; _38 < mAnimInfo->countIKeys(); _38++) {
		int keyIdx = getInfoKeyValue(_38);
		f32 value  = getKeyValue(keyIdx);

		if (mCurrentFrame < value) {
			return;
		}
		checkConstantKey(_38);
	}
}

/*
 * --INFO--
 * Address:	8011F4BC
 * Size:	0001C0
 */
void PaniAnimator::checkConstantKey(int idx)
{
	int type = mAnimInfo->getInfoKey(idx)->_06;
	if (mIsFinished == false) {
		if (type == 0) {
			_40 = idx;
		} else if (type == 1) {
			int keyIdx1 = getInfoKeyValue(_40);
			int keyIdx2 = getInfoKeyValue(idx);
			f32 keyVal1 = getKeyValue(keyIdx1);
			f32 keyVal2 = getKeyValue(keyIdx2);
			mCurrentFrame -= (keyVal2 - keyVal1);
			_38 = _40;
		}
	}

	if (type == 0) {
		if (mListener) {
			PaniAnimKeyEvent event(5);
			mListener->animationKeyUpdated(event);
		}
	} else if (type == 1) {
		if (mListener) {
			PaniAnimKeyEvent event(6);
			mListener->animationKeyUpdated(event);
		}
	}

	if (type >= 2 && type <= 5 && mListener) {
		PaniAnimKeyEvent event(type - 1);
		mListener->animationKeyUpdated(event);
	}
}

/*
 * --INFO--
 * Address:	8011F67C
 * Size:	000124
 */
void PaniAnimator::checkEventKeys(f32 p1, f32 p2)
{
	if (!mListener) {
		return;
	}

	for (int i = 0; i < mAnimInfo->countEKeys(); i++) {
		AnimKey* eventKey = mAnimInfo->getEventKey(i);

		f32 val2 = eventKey->getKeyValue();
		f32 val1 = eventKey->getKeyValue();
		if (p1 <= val1 && val2 < p2) {
			int type = 0;
			if (eventKey->_04 == 0) {
				type = 7;
			} else if (eventKey->_04 == 1) {
				type = 8;
			}

			mListener->animationKeyUpdated(PaniAnimKeyEvent(type, eventKey->_06));
		}
	}
}

/*
 * --INFO--
 * Address:	8011F7A0
 * Size:	000054
 */
void PaniAnimator::finishAnimation()
{
	_38 = -1;
	if (mListener) {
		mListener->animationKeyUpdated(PaniAnimKeyEvent(0));
	}
}

/*
 * --INFO--
 * Address:	8011F7F4
 * Size:	0000AC
 */
f32 PaniAnimator::getKeyValueByKeyType(int type)
{
	u32 badCompiler;
	for (int i = 0; i < mAnimInfo->countIKeys(); i++) {
		if (type == mAnimInfo->getInfoKey(i)->_06) {
			int keyIdx = mAnimInfo->getInfoKey(i)->_00;
			return getKeyValue(keyIdx);
		}
	}

	return 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void PaniAnimator::checkCounter_4DEBUG()
{
	// UNUSED FUNCTION
}
