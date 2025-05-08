#include "Animator.h"
#include "Ayu.h"
#include "Parameters.h"
#include "String.h"
#include "stl/string.h"
#include "Shape.h"
#include "system.h"
#include "sysNew.h"
#include "Dolphin/os.h"
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
 * Size:	0000F0
 */
DEFINE_PRINT("AnimMgr");

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void AnimInfo::initAnimData(AnimData*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80050024
 * Size:	0000DC
 */
void AnimInfo::checkAnimData()
{
	AnimKey* key1 = mAnimKeys.mNext;
	for (key1; key1 != &mAnimKeys; key1 = key1->mNext) {
		if (key1->mKeyframeIndex > mData->mTotalFrameCount - 1) {
			key1->mKeyframeIndex = mData->mTotalFrameCount - 1;
		}
	}

	AnimKey* infoKey = mInfoKeys.mNext;
	for (infoKey; infoKey != &mInfoKeys; infoKey = infoKey->mNext) {
		if (infoKey->mKeyframeIndex >= countAKeys()) {
			infoKey->mKeyframeIndex = countAKeys() - 1;
		}
	}

	AnimKey* eventKey = mEventKeys.mNext;
	for (eventKey; eventKey != &mEventKeys; eventKey = eventKey->mNext) {
		if (eventKey->mKeyframeIndex > mData->mTotalFrameCount - 1) {
			eventKey->mKeyframeIndex = mData->mTotalFrameCount - 1;
		}
	}
}

/*
 * --INFO--
 * Address:	80050100
 * Size:	00027C
 */
AnimInfo::AnimInfo(AnimMgr* mgr, AnimData* data)
    : CoreNode("")
{
	initCore("");
	mMgr            = mgr;
	mAnimKeys.mPrev = mAnimKeys.mNext = &mAnimKeys;
	mInfoKeys.mPrev = mInfoKeys.mNext = &mInfoKeys;
	mEventKeys.mPrev = mEventKeys.mNext = &mEventKeys;

	int pos = strlen(data->mName) - 1;
	for (pos; pos >= 0; pos--) {
		if ((u8)data->mName[pos] == (u8)'/' || (u8)data->mName[pos] == (u8)'\\') {
			break;
		}
	}

	mName = StdSystem::stringDup(&data->mName[pos + 1]);
	mData = data;

	AnimKey* key1        = new AnimKey();
	key1->mKeyframeIndex = 0;
	mAnimKeys.add(key1);

	AnimKey* key2        = new AnimKey();
	key2->mKeyframeIndex = mData->mTotalFrameCount - 1;
	mAnimKeys.add(key2);

	checkAnimData();

	mParams.mFlags.mValue = 5;

	updateAnimFlags();
	setIndex();
}

/*
 * --INFO--
 * Address:	8005037C
 * Size:	000048
 */
void AnimInfo::setIndex()
{
	mIndex = gsys->findAnyIndex(mMgr->mParams.mBasePath().mString, mData->mName);
}

/*
 * --INFO--
 * Address:	800503C4
 * Size:	000024
 */
void AnimInfo::setAnimFlags(u32 flags)
{
	mParams.mFlags(flags);
	updateAnimFlags();
}

/*
 * --INFO--
 * Address:	800503E8
 * Size:	000024
 */
int AnimInfo::countAKeys()
{
	int count    = 0;
	AnimKey* key = mAnimKeys.mNext;
	for (key; key != &mAnimKeys; key = key->mNext) {
		count++;
	}

	return count;
}

/*
 * --INFO--
 * Address:	8005040C
 * Size:	000024
 */
int AnimInfo::countIKeys()
{
	int count    = 0;
	AnimKey* key = mInfoKeys.mNext;
	for (key; key != &mInfoKeys; key = key->mNext) {
		count++;
	}

	return count;
}

/*
 * --INFO--
 * Address:	80050430
 * Size:	000024
 */
int AnimInfo::countEKeys()
{
	int count    = 0;
	AnimKey* key = mEventKeys.mNext;
	for (key; key != &mEventKeys; key = key->mNext) {
		count++;
	}

	return count;
}

/*
 * --INFO--
 * Address:	80050454
 * Size:	000038
 */
AnimKey* AnimInfo::getInfoKey(int idx)
{
	int i        = 0;
	AnimKey* key = mInfoKeys.mNext;
	for (key; key != &mInfoKeys; key = key->mNext, i++) {
		if (i == idx) {
			return key;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	8005048C
 * Size:	000038
 */
AnimKey* AnimInfo::getEventKey(int idx)
{
	int i        = 0;
	AnimKey* key = mEventKeys.mNext;
	for (key; key != &mEventKeys; key = key->mNext, i++) {
		if (i == idx) {
			return key;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800504C4
 * Size:	000038
 */
int AnimInfo::getKeyValue(int idx)
{
	int i        = 0;
	AnimKey* key = mAnimKeys.mNext;
	for (key; key != &mAnimKeys; key = key->mNext, i++) {
		if (i == idx) {
			return key->mKeyframeIndex;
		}
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800504FC
 * Size:	0002F8
 */
void AnimInfo::doread(RandomAccessStream& input, int p2)
{
	String str(nullptr, 0);
	input.readString(str);
	mName = StdSystem::stringDup(str.mString);
	mParams.read(input);

	mAnimKeys.mPrev = mAnimKeys.mNext = &mAnimKeys;
	mInfoKeys.mPrev = mInfoKeys.mNext = &mInfoKeys;
	mEventKeys.mPrev = mEventKeys.mNext = &mEventKeys;

	int numKeys = input.readInt();
	if (numKeys) {
		AnimKey* keys = new AnimKey[numKeys];
		for (int i = 0; i < numKeys; i++) {
			keys[i].mKeyframeIndex = input.readInt();
			mAnimKeys.add(&keys[i]);
		}
	}

	if (p2 >= 1) {
		int numKeys2 = input.readInt();
		if (numKeys2) {
			AnimKey* keys = new AnimKey[numKeys2];
			for (int i = 0; i < numKeys2; i++) {
				keys[i].mKeyframeIndex = input.readInt();
				keys[i].mEventKeyType  = input.readShort();
				keys[i].mEventId       = input.readByte();
				keys[i].mValue         = input.readByte();
				mInfoKeys.add(&keys[i]);
			}
		}
	}

	int numKeys3 = input.readInt();
	if (numKeys3) {
		AnimKey* keys = new AnimKey[numKeys3];
		for (int i = 0; i < numKeys3; i++) {
			keys[i].mKeyframeIndex = input.readInt();
			keys[i].mEventKeyType  = input.readShort();
			keys[i].mEventId       = input.readByte();
			keys[i].mValue         = input.readByte();
			if (keys[i].mEventKeyType >= 3) {
				keys[i].mEventKeyType = 0;
			}
			mEventKeys.add(&keys[i]);
		}
	}
}

/*
 * --INFO--
 * Address:	80050814
 * Size:	000010
 */
void AnimInfo::updateAnimFlags()
{
	mData->mAnimFlags = mParams.mFlags();
}

/*
 * --INFO--
 * Address:	80050824
 * Size:	000080
 */
AnimKey* AnimInfo::addKeyFrame()
{
	AnimKey* keyFrame        = new AnimKey();
	keyFrame->mKeyframeIndex = mData->mTotalFrameCount - 1;
	mAnimKeys.mPrev->insertAfter(keyFrame);
	return keyFrame;
}

/*
 * --INFO--
 * Address:	800508A4
 * Size:	000234
 */
AnimMgr::AnimMgr(Shape* shape, char* animPath, int flags, char* bundlePath)
{
	setName("AnimMgr");
	mParent   = shape;
	mIsLoaded = flags & 0x7FFF;
	mAnimList.initCore("anims");
	loadAnims(animPath, bundlePath);
}

/*
 * --INFO--
 * Address:	80050B04
 * Size:	0001E8
 */
void AnimMgr::loadAnims(char* animPath, char* bundlePath)
{

	if (!animPath) {
		return;
	}

	load("", animPath, 1);
	if (!mIsLoaded) {
		int free = gsys->getHeap(SYSHEAP_App)->getFree();

		int needBundleCount = (mAnimList.mChild) ? 0 : 1;
		char existingAnimPath[PATH_MAX];
		char finalBundlePath[PATH_MAX];
		char finalAnimPath[PATH_MAX];
		AnimInfo* info;
		for (info = (AnimInfo*)mAnimList.mChild; info; info = (AnimInfo*)info->mNext) {
			sprintf(existingAnimPath, "%s/%s", mParams.mBasePath().mString, info->mName);
			if (!gsys->findAnimation(existingAnimPath)) {
				needBundleCount++;
			}
		}

		if (needBundleCount) {
			gsys->mCurrentShape = mParent;
			sprintf(finalBundlePath, bundlePath ? bundlePath : mParent->mName);

			if (!bundlePath) {
				sprintf(&finalAnimPath[strlen(finalBundlePath) + 253], "anm");
			}

			gsys->loadBundle(finalBundlePath, false);
		}

		for (info = (AnimInfo*)mAnimList.mChild; info; info = (AnimInfo*)info->mNext) {
			sprintf(finalAnimPath, "%s/%s", mParams.mBasePath().mString, info->mName);
			info->mData = gsys->loadAnimation(mParent, finalAnimPath, true);
			if (info->mData) {
				info->setIndex();
				info->mData->mAnimFlags = info->mParams.mFlags();
				info->checkAnimData();
			} else {
				PRINT("COULD NOT FIND ANIM (%s) CREATING DUMMY\n", info->mName);
				info->mData = new AnimDck(mParent, mParent->mJointCount);
				info->mData->setName("Null Anim");
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80050CEC
 * Size:	00008C
 */
AnimInfo* AnimMgr::addAnimation(char* p1, bool p2)
{
	AnimInfo* info = new AnimInfo(this, gsys->loadAnimation(mParent, p1, p2));
	mAnimList.add(info);
	return info;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
AnimInfo* AnimMgr::findAnim(int idx)
{
	int i          = 0;
	AnimInfo* info = static_cast<AnimInfo*>(mAnimList.mChild);
	for (info; info; info = static_cast<AnimInfo*>(info->mNext), i++) {
		if (i == idx) {
			if (!info->mData) {
				char buf[PATH_MAX];
				sprintf(buf, "%s/%s", mParams.mBasePath().mString, info->mName);
				info->mData = mParent->loadAnimation(buf, true);
				info->updateAnimFlags();
			}
			return info;
		}
	}
	return nullptr;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80050D78
 * Size:	000020
 */
int AnimMgr::countAnims()
{
	int count = 0;
	FOREACH_NODE(AnimInfo, mAnimList.mChild, anim)
	{
		count++;
	}

	return count;
}

/*
 * --INFO--
 * Address:	80050D98
 * Size:	0001D8
 */
void AnimMgr::read(RandomAccessStream& input)
{
	int val       = input.readInt();
	int infoCount = input.readInt();

	mParams.read(input);
	mAnimList.initCore("");

	for (int i = 0; i < infoCount; i++) {
		AnimInfo* info = new AnimInfo();
		info->mMgr     = this;
		info->doread(input, val);
		mAnimList.add(info);
	}
}

/*
 * --INFO--
 * Address:	80050F70
 * Size:	00021C
 */
void Animator::startAnim(int p1, int animID, int firstKeyFrameIdx, int lastKeyFrameIdx)
{
	mAnimInfo = mMgr->findAnim(animID);
	if (firstKeyFrameIdx == -1 && mCurrentAnimID == animID) {
		firstKeyFrameIdx = mFirstFrameIndex;
	} else {
		mAnimationCounter = mAnimInfo->getKeyValue(firstKeyFrameIdx);
	}

	if (mAnimationCounter < 0.0f || mAnimationCounter >= mAnimInfo->mData->mTotalFrameCount) {
		PRINT("StartAnim: name = %s : numFrames = %d\n", mAnimInfo->mName, mAnimInfo->mData->mTotalFrameCount);
		ERROR("StartAnim: initialising with illegal counter value!! : %f\n", mAnimationCounter);
		mAnimationCounter = 0.0f;
	}

	if (lastKeyFrameIdx >= mAnimInfo->countAKeys()) {
		lastKeyFrameIdx = mAnimInfo->countAKeys() - 1;
	}
	if (firstKeyFrameIdx >= mAnimInfo->countAKeys()) {
		firstKeyFrameIdx = mAnimInfo->countAKeys() - 1;
	}

	mCurrentAnimID   = animID;
	mIsPlaying       = p1;
	mFirstFrameIndex = firstKeyFrameIdx;
	mLastFrameIndex  = lastKeyFrameIdx;
}

/*
 * --INFO--
 * Address:	8005118C
 * Size:	000004
 */
void Animator::finishLoop()
{
}

/*
 * --INFO--
 * Address:	80051190
 * Size:	000030
 */
void Animator::finishOneShot()
{
	startAnim(_08, mAnimationId, _10, _14);
}

/*
 * --INFO--
 * Address:	800511C0
 * Size:	00005C
 */
void Animator::updateContext()
{
	mContext->mData         = mAnimInfo->mData;
	mContext->mCurrentFrame = mAnimationCounter;
	if (mAnimationCounter >= mAnimInfo->mData->mTotalFrameCount) {
		ERROR("Cannot updateContext, frame too big %f\n", mAnimationCounter);
	}
}

/*
 * --INFO--
 * Address:	8005121C
 * Size:	00023C
 */
void Animator::animate(f32 speed)
{
	speed = (mAnimInfo->mParams.mFlags() & ANIMFLAG_Unk2) ? speed : mAnimInfo->mParams.mSpeed();

	f32 firstFrame = mAnimInfo->getKeyValue(mFirstFrameIndex);
	f32 lastFrame  = mAnimInfo->getKeyValue(mLastFrameIndex);
	if (mIsPlaying) {
		if (lastFrame > firstFrame) {
			mAnimationCounter += gsys->getFrameTime() * speed;
			if (mAnimationCounter >= lastFrame) {
				if (mIsPlaying == 1) {
					mAnimationCounter -= (lastFrame - firstFrame);
					if (mAnimationCounter >= lastFrame) {
						mAnimationCounter = firstFrame;
					}
				} else {
					mAnimationCounter = lastFrame - 1.0f;
					finishOneShot();
				}
			} else if (mAnimationCounter < firstFrame) {
				mAnimationCounter = firstFrame;
			}
		} else {
			mAnimationCounter -= gsys->getFrameTime() * speed;
			if (mAnimationCounter < lastFrame) {
				if (mIsPlaying == 1) {
					mAnimationCounter += (firstFrame - lastFrame);
					if (mAnimationCounter < lastFrame) {
						mAnimationCounter = lastFrame;
					}
				} else {
					mAnimationCounter = lastFrame;
					finishOneShot();
				}
			} else if (mAnimationCounter > firstFrame) {
				mAnimationCounter = firstFrame;
			}
		}
	}

	int currFrame = mAnimationCounter;
	if (currFrame < 0 || currFrame >= mAnimInfo->mData->mTotalFrameCount) {
		ERROR("Illegal counter value!! : %d, %f\n", currFrame, mAnimationCounter);
		mAnimationCounter = 0.0f;
	}
}
