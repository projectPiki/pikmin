#include "PaniAnimator.h"
#include "DebugLog.h"
#include "nlib/System.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(3)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("panianimator");

immut char* PaniAnimator::keyNames[6] = {
	"loop start", "loop end", "action 0", "action 1", "action 2", "action 3",
};

PaniMotionInfo::PaniMotionInfo(int motionIdx)
{
	init(motionIdx, nullptr);
}

PaniMotionInfo::PaniMotionInfo(int motionIdx, PaniAnimKeyListener* listener)
{
	init(motionIdx, listener);
}

void PaniMotionInfo::init(int motionIdx, PaniAnimKeyListener* listener)
{
	mMotionIdx = motionIdx;
	mListener  = listener;
}

PaniMotion::PaniMotion(int animID)
{
	init(animID, 1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
PaniMotion::PaniMotion(int animID, int p2)
{
	init(animID, p2);
	// UNUSED FUNCTION
}

void PaniMotion::init(int id, int p2)
{
	mAnimID   = id;
	_UNUSED04 = p2;
}

PaniMotionTable::PaniMotionTable(int count)
{
	mMotionCount = count;
	mMotions     = new PaniMotion*[mMotionCount];

	for (int i = 0; i < mMotionCount; i++) {
		mMotions[i] = nullptr;
	}
}

PaniSoundTable::PaniSoundTable(int count)
{
	mSoundCount = count;
	mSounds     = new PaniSound*[mSoundCount];

	for (int i = 0; i < mSoundCount; i++) {
		mSounds[i] = nullptr;
	}
}

PaniAnimator::PaniAnimator()
{
	mCurrentKeyIndex  = -1;
	mIsFinished       = false;
	mListener         = nullptr;
	mAnimInfo         = nullptr;
	mMotionTable      = nullptr;
	mMotionIdx        = -1;
	mAnimationCounter = 0.0f;
}

void PaniAnimator::init(AnimContext* context, AnimMgr* mgr, PaniMotionTable* table)
{
	mContext          = context;
	mMgr              = mgr;
	mAnimInfo         = nullptr;
	mAnimationCounter = 0.0f;
	mMotionTable      = table;
	if (mgr->countAnims()) {
		startAnim(ANIMSTATE_OneShot, 0, 0, 8);
	}
}

void PaniAnimator::changeContext(AnimContext* context)
{
	mContext = context;
}

void PaniAnimator::updateContext()
{
	if (mAnimInfo) {
		mContext->mData         = mAnimInfo->mData;
		mContext->mCurrentFrame = mAnimationCounter;
	}
}

void PaniAnimator::startMotion(immut PaniMotionInfo& info)
{
	if (mAnimInfo) {
		mMotionIdx        = info.mMotionIdx;
		mListener         = info.mListener;
		mCurrentKeyIndex  = 0;
		mPreviousKeyIndex = 0;
		mIsFinished       = false;
		startAnim(ANIMSTATE_OneShot, getMotion(mMotionIdx)->mAnimID, 0, 8);
	}
}

void PaniAnimator::finishMotion(immut PaniMotionInfo& info)
{
	if (!mAnimInfo) {
		return;
	}

	mListener   = info.mListener;
	mIsFinished = true;

	f32 maxFrame = (f32)((!mAnimInfo) ? -1 : mAnimInfo->mData->mTotalFrameCount);
	if (mAnimationCounter >= maxFrame) {
		PRINT("!!!finishMotion:%08x:%f,%f\n", this, mAnimationCounter, maxFrame);
		mAnimationCounter = maxFrame;
		finishAnimation();
	} else {
		startAnim(ANIMSTATE_OneShot, mCurrentAnimID, -1, 8);
	}
}

void PaniAnimator::animate(f32 speed)
{
	if (!mAnimInfo) {
		return;
	}

	if (speed < 0.0f) {
		PRINT_NAKATA("!animate:%08x:%f,%f\n", this, mAnimationCounter, speed);
	}

	if (mCurrentKeyIndex < 0) {
		return;
	}

	f32 startValue = (f32)mAnimInfo->getKeyValue(mStartKeyIndex);
	f32 endValue   = (f32)mAnimInfo->getKeyValue(mEndKeyIndex);
	if (startValue > endValue) {
		PRINT_NAKATA("!animate:%08x:to<from:%f,%f,%f\n", this, endValue, startValue, mAnimationCounter);
		return;
	}

	speed *= NSystem::getFrameTime();
	mAnimationCounter += speed;

	checkConstantKeys();
	checkEventKeys(mAnimationCounter - speed, mAnimationCounter);
	if (mAnimationCounter >= endValue) {
		mAnimationCounter = endValue;
		finishAnimation();
	}
}

void PaniAnimator::checkConstantKeys()
{
	if (mCurrentKeyIndex < 0) {
		ERROR("checkConstantKeys:nextKeyInfoIndex:%d,%d\n", mEndKeyIndex, mAnimInfo->countIKeys());
	}

	if (mAnimInfo->countIKeys() > 16) {
		ERROR("checkConstantKeys:getKeyInfoCount():%d,%d\n", mEndKeyIndex, mAnimInfo->countIKeys());
	}

	for (; mCurrentKeyIndex < mAnimInfo->countIKeys(); mCurrentKeyIndex++) {
		int keyIdx = getInfoKeyValue(mCurrentKeyIndex);
		f32 value  = getKeyValue(keyIdx);

		if (mAnimationCounter < value) {
			return;
		}

		checkConstantKey(mCurrentKeyIndex);
	}
}

void PaniAnimator::checkConstantKey(int idx)
{
	int type = mAnimInfo->getInfoKey(idx)->mKeyType;

	if (!mIsFinished) {
		if (type == 0) {
			mPreviousKeyIndex = idx;
		} else if (type == 1) {
			int firstKeyID  = getInfoKeyValue(mPreviousKeyIndex);
			int secondKeyID = getInfoKeyValue(idx);

			f32 firstKeyValue  = getKeyValue(firstKeyID);
			f32 secondKeyValue = getKeyValue(secondKeyID);

			mAnimationCounter -= (secondKeyValue - firstKeyValue);
			mCurrentKeyIndex = mPreviousKeyIndex;
		}
	}

	if (type == 0) {
		if (mListener) {
			PaniAnimKeyEvent event(KEY_LoopStart);
			mListener->animationKeyUpdated(event);
		}
	} else if (type == 1) {
		if (mListener) {
			PaniAnimKeyEvent event(KEY_LoopEnd);
			mListener->animationKeyUpdated(event);
		}
	}

	if (type >= 2 && type <= 5 && mListener) {
		PaniAnimKeyEvent event(type - 1);
		mListener->animationKeyUpdated(event);
	}
}

void PaniAnimator::checkEventKeys(f32 startKeyframe, f32 endKeyframe)
{
	if (!mListener) {
		return;
	}

	for (int i = 0; i < mAnimInfo->countEKeys(); i++) {
		AnimKey* eventKey = mAnimInfo->getEventKey(i);

		// f32 val2 = eventKey->mKeyframeIndex;
		f32 frame = eventKey->mFrameIndex;
		STACK_PAD_VAR(1);
		if (startKeyframe <= frame && frame < endKeyframe) {
			int type = KEY_Finished;
			if (eventKey->mEventType == ANIMEVENT_Notify) {
				type = KEY_PlaySound;
			} else if (eventKey->mEventType == ANIMEVENT_Action) {
				type = KEY_PlayEffect;
			} else {
				PRINT("!checkEventKeys:%08x:not supported event type:%d\n", this, eventKey->mEventType);
			}

			mListener->animationKeyUpdated(PaniAnimKeyEvent(type, eventKey->mKeyType));
		}
	}
	STACK_PAD_TERNARY(startKeyframe, 1);
}

void PaniAnimator::finishAnimation()
{
	mCurrentKeyIndex = -1;
	if (mListener) {
		mListener->animationKeyUpdated(PaniAnimKeyEvent(KEY_Finished));
	}
}

f32 PaniAnimator::getKeyValueByKeyType(int type)
{
	STACK_PAD_VAR(1);
	for (int i = 0; i < mAnimInfo->countIKeys(); i++) {
		if (type == mAnimInfo->getInfoKey(i)->mKeyType) {
			int keyIdx = mAnimInfo->getInfoKey(i)->mFrameIndex;
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
	if (mAnimationCounter < 0.0f || mAnimInfo->mData->mTotalFrameCount <= mAnimationCounter) {
		PRINT("!checkCounter_4DEBUG:%08x:%d,%f/%f\n", this, mMotionIdx, mAnimationCounter, mAnimInfo->mData->mTotalFrameCount);
		ERROR("!checkCounter_4DEBUG:%08x:%d,%f/%f\n", this, mMotionIdx, mAnimationCounter, mAnimInfo->mData->mTotalFrameCount);
	}
}
