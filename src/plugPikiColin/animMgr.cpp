#include "Age.h"
#include "Animator.h"
#include "Ayu.h"
#include "Common/String.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "Parameters.h"
#include "Shape.h"
#include "sysNew.h"
#include "system.h"
#include <string.h>

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(12)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("AnimMgr");

/**
 * @todo: Documentation
 * @note UNUSED Size: 000084
 */
void AnimInfo::initAnimData(AnimData* data)
{
	int pos = strlen(data->mName) - 1;
	for (pos; pos >= 0; pos--) {
		if (data->mName[pos] == '/' || data->mName[pos] == '\\') {
			break;
		}
	}

	mName = StdSystem::stringDup(&data->mName[pos + 1]);
	mData = data;
}

/**
 * @todo: Documentation
 */
void AnimInfo::checkAnimData()
{
	AnimKey* animKey = mAnimKeys.mNext;
	for (animKey; animKey != &mAnimKeys; animKey = animKey->mNext) {
		if (animKey->mFrameIndex > mData->mTotalFrameCount - 1) {
			animKey->mFrameIndex = mData->mTotalFrameCount - 1;
		}
	}

	AnimKey* infoKey = mInfoKeys.mNext;
	for (infoKey; infoKey != &mInfoKeys; infoKey = infoKey->mNext) {
		if (infoKey->mFrameIndex >= countAKeys()) {
			infoKey->mFrameIndex = countAKeys() - 1;
		}
	}

	AnimKey* eventKey = mEventKeys.mNext;
	for (eventKey; eventKey != &mEventKeys; eventKey = eventKey->mNext) {
		if (eventKey->mFrameIndex > mData->mTotalFrameCount - 1) {
			eventKey->mFrameIndex = mData->mTotalFrameCount - 1;
		}
	}
}

/**
 * @todo: Documentation
 */
AnimInfo::AnimInfo(AnimMgr* mgr, AnimData* data)
    : CoreNode("")
{
	initCore("");
	mMgr            = mgr;
	mAnimKeys.mPrev = mAnimKeys.mNext = &mAnimKeys;
	mInfoKeys.mPrev = mInfoKeys.mNext = &mInfoKeys;
	mEventKeys.mPrev = mEventKeys.mNext = &mEventKeys;

	initAnimData(data);

	AnimKey* firstKey     = new AnimKey();
	firstKey->mFrameIndex = 0;
	mAnimKeys.mPrev->insertAfter(firstKey);

	AnimKey* lastKey     = new AnimKey();
	lastKey->mFrameIndex = mData->mTotalFrameCount - 1;
	mAnimKeys.mPrev->insertAfter(lastKey);

	checkAnimData();

	mParams.mFlags(ANIMFLAG_Unk1 | ANIMFLAG_UseCache);

	updateAnimFlags();
	setIndex();
}

/**
 * @todo: Documentation
 */
void AnimInfo::setIndex()
{
	mIndex = gsys->findAnyIndex(mMgr->mParams.mBasePath().mString, mData->mName);
}

/**
 * @todo: Documentation
 */
void AnimInfo::setAnimFlags(u32 flags)
{
	mParams.mFlags(flags);
	updateAnimFlags();
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
int AnimInfo::getKeyValue(int idx)
{
	int i        = 0;
	AnimKey* key = mAnimKeys.mNext;
	for (key; key != &mAnimKeys; key = key->mNext, i++) {
		if (i == idx) {
			return key->mFrameIndex;
		}
	}

	return nullptr;
}

/**
 * @todo: Documentation
 */
void AnimInfo::doread(RandomAccessStream& input, int version)
{
	String str(nullptr, 0);
	input.readString(str);
	mName = StdSystem::stringDup(str.mString);

	// read in parameters (flags and anim speed)
	mParams.read(input);

	// reset Anim, Info and Event key lists.
	mAnimKeys.mPrev = mAnimKeys.mNext = &mAnimKeys;
	mInfoKeys.mPrev = mInfoKeys.mNext = &mInfoKeys;
	mEventKeys.mPrev = mEventKeys.mNext = &mEventKeys;

	// read in keyframe indices for anim keys (if there are any)
	int animKeyNum = input.readInt();
	if (animKeyNum) {
		AnimKey* keys = new AnimKey[animKeyNum];
		for (int i = 0; i < animKeyNum; i++) {
			keys[i].mFrameIndex = input.readInt();
			mAnimKeys.mPrev->insertAfter(&keys[i]);
		}
	}

	// version 1 or later has Info key count (this is a guess)
	if (version >= 1) {
		int infoKeyNum = input.readInt();
		if (infoKeyNum) {
			AnimKey* keys = new AnimKey[infoKeyNum];
			for (int i = 0; i < infoKeyNum; i++) {
				keys[i].mFrameIndex = input.readInt();
				keys[i].mEventType  = input.readShort();
				keys[i].mEventCmdID = input.readByte();
				keys[i].mKeyType    = input.readByte();
				mInfoKeys.mPrev->insertAfter(&keys[i]);
			}
		}
	}

	// read in keyframe indices for event keys (if there are any)
	int eventKeyNum = input.readInt();
	if (eventKeyNum) {
		AnimKey* keys = new AnimKey[eventKeyNum];
		for (int i = 0; i < eventKeyNum; i++) {
			keys[i].mFrameIndex = input.readInt();
			keys[i].mEventType  = input.readShort();
			keys[i].mEventCmdID = input.readByte();
			keys[i].mKeyType    = input.readByte();

			// lock down any invalid event types
			if (keys[i].mEventType >= ANIMEVENT_COUNT) {
				keys[i].mEventType = ANIMEVENT_Notify;
			}
			mEventKeys.mPrev->insertAfter(&keys[i]);
		}
	}
}

/**
 * @todo: Documentation
 */
void AnimInfo::updateAnimFlags()
{
	mData->mAnimFlags = mParams.mFlags();
}

/**
 * @todo: Documentation
 */
AnimKey* AnimInfo::addKeyFrame()
{
	AnimKey* keyFrame     = new AnimKey();
	keyFrame->mFrameIndex = mData->mTotalFrameCount - 1;
	mAnimKeys.mPrev->insertAfter(keyFrame);
	return keyFrame;
}

/**
 * @todo: Documentation
 */
AnimMgr::AnimMgr(Shape* model, immut char* animPath, int flags, immut char* bundlePath)
{
	setName("AnimMgr");
	mModel       = model;
	mSkipLoading = flags & ANIMMGR_LOAD_SKIP_MASK;
	mAnimList.initCore("anims");
	loadAnims(animPath, bundlePath);
}

/**
 * @todo: Documentation
 */
void AnimMgr::loadAnims(immut char* animPath, immut char* bundlePath)
{
	if (!animPath) {
		return;
	}

	// load file and read in all parameters and managed animation information.
	load("", animPath, 1);

	// if not loaded, load all animations and bundles.
	if (!mSkipLoading) {
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
			gsys->mCurrentShape = mModel;
			sprintf(finalBundlePath, bundlePath ? bundlePath : mModel->mName);

			if (!bundlePath) {
				sprintf(&finalAnimPath[strlen(finalBundlePath) + 253], "anm");
			}

			gsys->loadBundle(finalBundlePath, false);
		}

		for (info = (AnimInfo*)mAnimList.mChild; info; info = (AnimInfo*)info->mNext) {
			sprintf(finalAnimPath, "%s/%s", mParams.mBasePath().mString, info->mName);
			info->mData = gsys->loadAnimation(mModel, finalAnimPath, true);
			if (info->mData) {
				info->setIndex();
				info->mData->mAnimFlags = info->mParams.mFlags();
				info->checkAnimData();
			} else {
				PRINT("COULD NOT FIND ANIM (%s) CREATING DUMMY\n", info->mName);
				info->mData = new AnimDck(mModel, mModel->mJointCount);
				info->mData->setName("Null Anim");
			}
		}
	}
}

/**
 * @todo: Documentation
 */
AnimInfo* AnimMgr::addAnimation(immut char* animPath, bool isRelativePath)
{
	AnimInfo* info = new AnimInfo(this, gsys->loadAnimation(mModel, animPath, isRelativePath));
	mAnimList.add(info);
	return info;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A4
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
				info->mData = mModel->loadAnimation(buf, true);
				info->updateAnimFlags();
			}
			return info;
		}
	}
	return nullptr;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void AnimMgr::read(RandomAccessStream& input)
{
	int version   = input.readInt();
	int infoCount = input.readInt();

	mParams.read(input);
	mAnimList.initCore("");

	for (int i = 0; i < infoCount; i++) {
		AnimInfo* info = new AnimInfo();
		info->mMgr     = this;
		info->doread(input, version);
		mAnimList.add(info);
	}
}

/**
 * @todo: Documentation
 */
void Animator::startAnim(int playState, int animID, int firstKeyFrameIdx, int lastKeyFrameIdx)
{
	mAnimInfo = mMgr->findAnim(animID);
	if (firstKeyFrameIdx == -1 && mCurrentAnimID == animID) {
		firstKeyFrameIdx = mStartKeyIndex;
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

	mCurrentAnimID = animID;
	mPlayState     = playState;
	mStartKeyIndex = firstKeyFrameIdx;
	mEndKeyIndex   = lastKeyFrameIdx;
}

/**
 * @todo: Documentation
 */
void Animator::finishLoop()
{
}

/**
 * @todo: Documentation
 */
void Animator::finishOneShot()
{
	startAnim(mPostOneShotPlayState, mPostOneShotAnimID, mPostOneShotStartKeyIndex, mPostOneShotEndKeyIndex);
}

/**
 * @todo: Documentation
 */
void Animator::updateContext()
{
	mContext->mData         = mAnimInfo->mData;
	mContext->mCurrentFrame = mAnimationCounter;
	if (mAnimationCounter >= mAnimInfo->mData->mTotalFrameCount) {
		ERROR("Cannot updateContext, frame too big %f\n", mAnimationCounter);
	}
}

/**
 * @todo: Documentation
 */
void Animator::animate(f32 animSpeed)
{
	animSpeed = (mAnimInfo->mParams.mFlags() & ANIMFLAG_UseDynamicSpeed) ? animSpeed : mAnimInfo->mParams.mSpeed();

	f32 firstFrame = mAnimInfo->getKeyValue(mStartKeyIndex);
	f32 lastFrame  = mAnimInfo->getKeyValue(mEndKeyIndex);
	if (mPlayState != ANIMSTATE_Inactive) {
		if (lastFrame > firstFrame) {
			// playing normally
			mAnimationCounter += gsys->getFrameTime() * animSpeed;

			// we've hit the end of the animation
			if (mAnimationCounter >= lastFrame) {
				if (mPlayState == ANIMSTATE_Loop) { // loop
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
			// playing in reverse
			mAnimationCounter -= gsys->getFrameTime() * animSpeed;
			if (mAnimationCounter < lastFrame) {
				if (mPlayState == ANIMSTATE_Loop) {
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

	// make sure frame counter has a valid value.
	int currFrame = mAnimationCounter;
	if (currFrame < 0 || currFrame >= mAnimInfo->mData->mTotalFrameCount) {
		ERROR("Illegal counter value!! : %d, %f\n", currFrame, mAnimationCounter);
		mAnimationCounter = 0.0f;
	}
}

// The functions following this point are exclusively found in the windows .dll build
// None of this is confirmed to be equivalent for obvious reasons

#ifdef WIN32

void AnimMgr::genAge(AgeServer& server)
{
	server.StartSection(mName, true);

	server.StartGroup("commands");
	server.NewButton("Add Animation", new Delegate1<AnimMgr, AgeServer&>(this, importAnimationButton), 444);
	server.NewButton("Load", new Delegate1<AnimMgr, AgeServer&>(this, genRead), 444);
	server.NewButton("Save", new Delegate1<AnimMgr, AgeServer&>(this, genWrite), 444);
	server.EndGroup();

	mParams.genAgeParms(server, 10);
	int index = 0;
	FOREACH_NODE(AnimInfo, mAnimList.mChild, anim)
	{
		char buf[256];
		sprintf(buf, "%d : %s", index, anim->mName);
		server.StartSection(buf, true);
		server.setSectionRefresh(new Delegate1<AnimInfo, AgeServer&>(anim, CoreNode::genAge));
		server.EndSection();
	}

	server.EndSection();
}

void AnimMgr::write(RandomAccessStream& stream)
{
	stream.writeInt(1);
	stream.writeInt(countAnims());
	mParams.write(stream);

	FOREACH_NODE(AnimInfo, mAnimList.mChild, anim)
	{
		anim->write(stream);
	}
}

void AnimMgr::importAnimationButton(AgeServer& server)
{
	AnimData* data = gsys->findAnyAnimation(mParams.mBasePath().mString);
	if (data) {
		addAnimation(data->mName, false);
		server.RefreshSection();
	} else {
		PRINT("COULD NOT FIND ANY ANIMATIONS in (%s)!!\n", mParams.mBasePath().mString);
	}
}

void AnimInfo::write(RandomAccessStream& stream)
{
	stream.writeString(mName);
	mParams.write(stream);

	stream.writeInt(countAKeys());
	AnimKey* animKey = mAnimKeys.mNext;
	for (animKey; animKey != &mAnimKeys; animKey = animKey->mNext) {
		stream.writeInt(animKey->mFrameIndex);
	}

	stream.writeInt(countIKeys());
	if (countIKeys()) {
		animKey = mInfoKeys.mNext;
		for (animKey; animKey != &mInfoKeys; animKey = animKey->mNext) {
			stream.writeInt(animKey->mFrameIndex);
			stream.writeShort(animKey->mEventType);
			stream.writeByte(animKey->mKeyType);
			stream.writeByte(animKey->mEventCmdID);
		}
	}

	stream.writeInt(countEKeys());
	animKey = mEventKeys.mNext;
	for (animKey; animKey != &mEventKeys; animKey = animKey->mNext) {
		stream.writeInt(animKey->mFrameIndex);
		stream.writeShort(animKey->mEventType);
		stream.writeByte(animKey->mKeyType);
		stream.writeByte(animKey->mEventCmdID);
	}
}

void AnimInfo::genAge(AgeServer& server)
{
	if (mData == nullptr) {
		return;
	}

	server.StartGroup("info");
	server.setOnChange(new Delegate1<AnimInfo, AgeServer&>(this, ageChangeAnim));
	server.StartOptionBox("select anim", &mIndex, 380);
	gsys->ageAnyAnimations(server, mMgr->mParams.mBasePath().mString);
	server.EndOptionBox();
	server.setOnChange((Delegate1<AnimInfo, AgeServer&>*)(nullptr));
	server.NewButton("Delete", new Delegate1<AnimInfo, AgeServer&>(this, ageDelAnim), 52);
	server.setOnChange(new Delegate<AnimInfo>(this, updateAnimFlags));
	server.StartBitGroup("flags", (u32*)&mParams.mFlags(), 120);
	server.NewBit("Constant", ANIMFLAG_Unk1, 1);
	server.NewBit("Velocity", ANIMFLAG_UseDynamicSpeed, 1);
	server.NewBit("Cachable", ANIMFLAG_UseCache, 0);
	server.EndBitGroup();
	server.setOnChange((Delegate<AnimInfo>*)(nullptr));
	server.NewEditor("Speed", &mParams.mSpeed(), 0.0f, 60.0f, 320);
	server.EndGroup();

	char buf[64];
	server.StartGroup("Anim keys");
	server.NewButton("add Key", new Delegate1<AnimInfo, AgeServer&>(this, ageAddKey), 508);
	AnimKey* animKey = mAnimKeys.mNext;
	int index        = 0;
	for (animKey; animKey != &mAnimKeys; animKey = animKey->mNext) {
		if (animKey == mAnimKeys.mNext) {
			sprintf(buf, "start key");
		} else if (animKey == &mAnimKeys) {
			sprintf(buf, "end key");
		} else {
			sprintf(buf, "key %d", index);
		}
		server.NewButton("delete", new Delegate1<AnimKey, AgeServer&>(animKey, AnimKey::ageDelLastKey), 120);
		server.NewEditor(buf, &animKey->mFrameIndex, 0, mData->mTotalFrameCount - 1, 320);
		index++;
	}
	server.EndGroup();

	server.StartGroup("Info keys");
	server.NewButton("add Info Key", new Delegate1<AnimInfo, AgeServer&>(this, ageAddInfoKey), 508);
	AnimKey* infoKey = mInfoKeys.mNext;
	index            = 0;
	for (infoKey; infoKey != &mInfoKeys; infoKey = infoKey->mNext) {
		sprintf(buf, "key %d", index);

		server.NewButton("delete", new Delegate1<AnimKey, AgeServer&>(infoKey, AnimKey::ageDelLastKey), 120);
		server.StartOptionBox("key no.", &infoKey->mFrameIndex, 170);
		int index2 = 0;
		for (animKey = mAnimKeys.mNext; animKey != &mAnimKeys; animKey = animKey->mNext) {
			if (animKey == mAnimKeys.mNext) {
				sprintf(buf, "start key");
			} else if (animKey->mNext == &mAnimKeys) {
				sprintf(buf, "end key");
			} else {
				sprintf(buf, "key %d", index2);
			}
			server.NewOption(buf, index2);
			index2++;
		}
		server.EndOptionBox();
		server.StartOptionBox("key type", &infoKey->mKeyType, 170);
		genAgeKeyTypes(server);
		server.EndOptionBox();
		index++;
	}
	server.EndGroup();

	server.StartGroup("Effect keys");
	server.NewButton("add Effect Key", new Delegate1<AnimInfo, AgeServer&>(this, ageAddEffectKey), 508);
	AnimKey* effectKey = mEventKeys.mNext;
	index              = 0;
	for (effectKey; effectKey != &mEventKeys; effectKey = effectKey->mNext) {
		sprintf(buf, "key %d", index);

		server.NewButton("DEL", new Delegate1<AnimKey, AgeServer&>(effectKey, AnimKey::ageDelLastKey), 120);
		server.StartOptionBox("type", (u16*)&effectKey->mEventType, 120);
		server.NewOption("SND", ANIMEVENT_Notify);
		server.NewOption("GFX", ANIMEVENT_Action);
		server.NewOption("EFF", ANIMEVENT_None);
		server.EndOptionBox();

		server.NewEditor("", (char*)&effectKey->mKeyType, 0, 0, 320);
		server.NewEditor("", &effectKey->mFrameIndex, 0, mData->mTotalFrameCount - 1, 230);
		index++;
	}
	server.EndGroup();
}

void AnimInfo::ageAddEffectKey(AgeServer& server)
{
	AnimKey* key     = new AnimKey;
	key->mFrameIndex = mData->mTotalFrameCount - 1;
	mEventKeys.insertAfter(key);
	server.RefreshSection();
}

void AnimInfo::ageAddInfoKey(AgeServer& server)
{
	AnimKey* key     = new AnimKey;
	key->mFrameIndex = countAKeys() - 1;
	mInfoKeys.insertAfter(key);
	server.RefreshSection();
}

void AnimInfo::ageAddKey(AgeServer& server)
{
	addKeyFrame();
	server.RefreshSection();
}

void AnimInfo::ageChangeAnim(AgeServer& server)
{
	AnimData* data;
	data = gsys->findIndexAnimation(mMgr->mParams.mBasePath().mString, mIndex);
	data = gsys->loadAnimation(mMgr->mModel, mName, true);
	initAnimData(data);
	checkAnimData();

	server.RefreshNode();
}

void AnimInfo::ageDelAnim(AgeServer& server)
{
	del();
	server.RefreshSection();
}

void AnimInfo::genAgeKeyTypes(AgeServer& server)
{
	static char* key_types[6] = { "loop_start", "loop_end", "action 0", "action 1", "action 2", "action 3" };
	for (int i = 0; i < 6; i++) {
		server.NewOption(key_types[i], i);
	}
}

void AnimKey::ageDelLastKey(AgeServer& server)
{
	remove();
	server.RefreshSection();
}

#endif
