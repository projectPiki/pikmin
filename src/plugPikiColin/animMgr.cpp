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
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

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
		if (key1->mKeyframeIndex > mData->mNumFrames - 1) {
			key1->mKeyframeIndex = mData->mNumFrames - 1;
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
		if (eventKey->mKeyframeIndex > mData->mNumFrames - 1) {
			eventKey->mKeyframeIndex = mData->mNumFrames - 1;
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
	key2->mKeyframeIndex = mData->mNumFrames - 1;
	mAnimKeys.add(key2);

	checkAnimData();

	mParams.mFlags.mValue = 5;

	updateAnimFlags();
	setIndex();
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x738C
	  stwu      r1, -0x58(r1)
	  stmw      r27, 0x44(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  lis       r3, 0x8022
	  li        r30, 0
	  subi      r31, r13, 0x7628
	  addi      r29, r5, 0
	  addi      r4, r27, 0x14
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802A
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x60F8
	  addi      r3, r1, 0x20
	  stw       r30, 0x10(r27)
	  addi      r5, r3, 0
	  addi      r3, r27, 0x18
	  stw       r30, 0xC(r27)
	  stw       r30, 0x8(r27)
	  stw       r31, 0x4(r27)
	  stw       r0, 0x0(r27)
	  stw       r30, 0x14(r27)
	  lwz       r0, -0x7624(r13)
	  stw       r0, 0x28(r1)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x20(r1)
	  bl        0xE904
	  lis       r3, 0x802A
	  addi      r0, r3, 0x60C4
	  stw       r0, 0x20(r27)
	  li        r0, 0x2
	  addi      r5, r1, 0x1C
	  stw       r0, 0x24(r27)
	  addi      r3, r27, 0x28
	  addi      r4, r27, 0x14
	  lwz       r0, -0x7620(r13)
	  stw       r0, 0x30(r1)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x1C(r1)
	  bl        0xE8D0
	  lis       r3, 0x802A
	  addi      r0, r3, 0x6098
	  stw       r0, 0x30(r27)
	  addi      r4, r27, 0x38
	  addi      r3, r27, 0x58
	  lfs       f0, -0x7B20(r2)
	  addi      r0, r27, 0x48
	  stfs      f0, 0x34(r27)
	  stw       r30, 0x38(r27)
	  sth       r30, 0x3C(r27)
	  stb       r30, 0x3E(r27)
	  stb       r30, 0x3F(r27)
	  stw       r30, 0x44(r27)
	  stw       r30, 0x40(r27)
	  stw       r30, 0x48(r27)
	  sth       r30, 0x4C(r27)
	  stb       r30, 0x4E(r27)
	  stb       r30, 0x4F(r27)
	  stw       r30, 0x54(r27)
	  stw       r30, 0x50(r27)
	  stw       r30, 0x58(r27)
	  sth       r30, 0x5C(r27)
	  stb       r30, 0x5E(r27)
	  stb       r30, 0x5F(r27)
	  stw       r30, 0x64(r27)
	  stw       r30, 0x60(r27)
	  stw       r30, 0x10(r27)
	  stw       r30, 0xC(r27)
	  stw       r30, 0x8(r27)
	  stw       r31, 0x4(r27)
	  stw       r28, 0x70(r27)
	  stw       r4, 0x44(r27)
	  stw       r4, 0x40(r27)
	  stw       r3, 0x64(r27)
	  stw       r3, 0x60(r27)
	  stw       r0, 0x54(r27)
	  stw       r0, 0x50(r27)
	  lwz       r3, 0x4(r29)
	  bl        0x1C91C0
	  subic.    r4, r3, 0x1
	  addi      r0, r4, 0x1
	  mtctr     r0
	  blt-      .loc_0x180

	.loc_0x160:
	  lwz       r3, 0x4(r29)
	  lbzx      r0, r3, r4
	  cmplwi    r0, 0x2F
	  beq-      .loc_0x180
	  cmplwi    r0, 0x5C
	  beq-      .loc_0x180
	  subi      r4, r4, 0x1
	  bdnz+     .loc_0x160

	.loc_0x180:
	  lwz       r0, 0x4(r29)
	  add       r3, r4, r0
	  addi      r3, r3, 0x1
	  bl        -0xFF4C
	  stw       r3, 0x4(r27)
	  li        r3, 0x10
	  stw       r29, 0x68(r27)
	  bl        -0x9298
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x1C8
	  li        r0, 0
	  stw       r0, 0x0(r6)
	  sth       r0, 0x4(r6)
	  stb       r0, 0x6(r6)
	  stb       r0, 0x7(r6)
	  stw       r0, 0xC(r6)
	  stw       r0, 0x8(r6)

	.loc_0x1C8:
	  li        r28, 0
	  stw       r28, 0x0(r6)
	  li        r3, 0x10
	  lwz       r5, 0x40(r27)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x92EC
	  addi      r6, r3, 0
	  mr.       r0, r6
	  beq-      .loc_0x218
	  stw       r28, 0x0(r6)
	  sth       r28, 0x4(r6)
	  stb       r28, 0x6(r6)
	  stb       r28, 0x7(r6)
	  stw       r28, 0xC(r6)
	  stw       r28, 0x8(r6)

	.loc_0x218:
	  lwz       r4, 0x68(r27)
	  mr        r3, r27
	  lwz       r4, 0x30(r4)
	  subi      r0, r4, 0x1
	  stw       r0, 0x0(r6)
	  lwz       r5, 0x40(r27)
	  lwz       r0, 0xC(r5)
	  stw       r0, 0xC(r6)
	  stw       r5, 0x8(r6)
	  lwz       r4, 0xC(r5)
	  stw       r6, 0x8(r4)
	  stw       r6, 0xC(r5)
	  bl        -0x324
	  li        r0, 0x5
	  stw       r0, 0x24(r27)
	  mr        r3, r27
	  bl        0x4BC
	  mr        r3, r27
	  bl        .loc_0x27C
	  mr        r3, r27
	  lmw       r27, 0x44(r1)
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x27C:
	*/
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
	mParams.mFlags.mValue = flags;
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
				keys[i]._07            = input.readByte();
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
			keys[i]._07            = input.readByte();
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
	mData->mAnimFlags = mParams.mFlags.mValue;
}

/*
 * --INFO--
 * Address:	80050824
 * Size:	000080
 */
AnimKey* AnimInfo::addKeyFrame()
{
	AnimKey* keyFrame        = new AnimKey();
	keyFrame->mKeyframeIndex = mData->mNumFrames - 1;
	mAnimKeys.add(keyFrame);
	return keyFrame;
}

/*
 * --INFO--
 * Address:	800508A4
 * Size:	000234
 */
AnimMgr::AnimMgr(Shape* shape, char* p2, int p3, char* p4)
{
	setName("AnimMgr");
	mParent = shape;
	_B4     = p3 & 0x7FFF;
	mAnimList.initCore("anims");
	loadAnims(p2, p4);
}

/*
 * --INFO--
 * Address:	80050B04
 * Size:	0001E8
 */
void AnimMgr::loadAnims(char*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x350(r1)
	  stmw      r27, 0x33C(r1)
	  addi      r30, r3, 0
	  addi      r29, r5, 0
	  beq-      .loc_0x1D4
	  addi      r3, r30, 0
	  addi      r5, r4, 0
	  subi      r4, r13, 0x7628
	  li        r6, 0x1
	  bl        -0x10494
	  lwz       r0, 0xB4(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x1D4
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        -0x11B2C
	  lwz       r3, 0x50(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  li        r0, 0
	  b         .loc_0x64

	.loc_0x60:
	  li        r0, 0x1

	.loc_0x64:
	  mr        r27, r0
	  addi      r28, r3, 0
	  addi      r31, r30, 0x34
	  b         .loc_0xA8

	.loc_0x74:
	  lwz       r5, 0x4(r31)
	  addi      r3, r1, 0x230
	  lwz       r6, 0x4(r28)
	  crclr     6, 0x6
	  subi      r4, r13, 0x760C
	  bl        0x1C5A0C
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x230
	  bl        -0x117EC
	  cmplwi    r3, 0
	  bne-      .loc_0xA4
	  addi      r27, r27, 0x1

	.loc_0xA4:
	  lwz       r28, 0xC(r28)

	.loc_0xA8:
	  cmplwi    r28, 0
	  bne+      .loc_0x74
	  cmpwi     r27, 0
	  beq-      .loc_0x11C
	  lwz       r0, 0x3C(r30)
	  cmplwi    r29, 0
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x1FC(r3)
	  beq-      .loc_0xD4
	  mr        r4, r29
	  b         .loc_0xDC

	.loc_0xD4:
	  lwz       r3, 0x3C(r30)
	  lwz       r4, 0x4(r3)

	.loc_0xDC:
	  crclr     6, 0x6
	  addi      r3, r1, 0x130
	  bl        0x1C59B0
	  cmplwi    r29, 0
	  bne-      .loc_0x10C
	  addi      r3, r1, 0x130
	  bl        0x1C8814
	  addi      r0, r1, 0x12D
	  crclr     6, 0x6
	  add       r3, r0, r3
	  subi      r4, r13, 0x7604
	  bl        0x1C598C

	.loc_0x10C:
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x130
	  li        r5, 0
	  bl        -0x10E48

	.loc_0x11C:
	  lis       r3, 0x802A
	  lwz       r27, 0x50(r30)
	  addi      r29, r3, 0x5FE4
	  b         .loc_0x1CC

	.loc_0x12C:
	  lwz       r5, 0x4(r31)
	  addi      r3, r1, 0x30
	  lwz       r6, 0x4(r27)
	  crclr     6, 0x6
	  subi      r4, r13, 0x760C
	  bl        0x1C5954
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r1, 0x30
	  lwz       r4, 0x3C(r30)
	  li        r6, 0x1
	  bl        -0x11768
	  stw       r3, 0x68(r27)
	  lwz       r5, 0x68(r27)
	  cmplwi    r5, 0
	  beq-      .loc_0x19C
	  lwz       r4, 0x70(r27)
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r4, 0x34
	  lwz       r5, 0x4(r5)
	  lwz       r4, 0x4(r4)
	  bl        -0x11834
	  stw       r3, 0x6C(r27)
	  mr        r3, r27
	  lwz       r0, 0x24(r27)
	  lwz       r4, 0x68(r27)
	  stw       r0, 0x24(r4)
	  bl        -0xC74
	  b         .loc_0x1C8

	.loc_0x19C:
	  li        r3, 0x44
	  bl        -0x9CA0
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x1BC
	  lwz       r4, 0x3C(r30)
	  lwz       r5, 0x58(r4)
	  bl        -0x23620

	.loc_0x1BC:
	  stw       r28, 0x68(r27)
	  lwz       r3, 0x68(r27)
	  stw       r29, 0x4(r3)

	.loc_0x1C8:
	  lwz       r27, 0xC(r27)

	.loc_0x1CC:
	  cmplwi    r27, 0
	  bne+      .loc_0x12C

	.loc_0x1D4:
	  lmw       r27, 0x33C(r1)
	  lwz       r0, 0x354(r1)
	  addi      r1, r1, 0x350
	  mtlr      r0
	  blr
	*/
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
			if (info->mData) {
				break;
			}
			char buf[128];
			sprintf(buf, "%s/%s", mParams.mBasePath().mString, info->mName);
			info->mData             = mParent->loadAnimation(buf, true);
			info->mData->mAnimFlags = info->mParams.mFlags();
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
void Animator::startAnim(int p1, int p2, int p3, int p4)
{
	mAnimInfo = mMgr->findAnim(p2);
	if (p3 == -1) { }
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x160(r1)
	  stmw      r25, 0x144(r1)
	  mr        r27, r3
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  addi      r31, r7, 0
	  lwz       r25, 0x0(r3)
	  li        r3, 0
	  lwz       r26, 0x50(r25)
	  b         .loc_0x8C

	.loc_0x34:
	  cmpw      r3, r29
	  bne-      .loc_0x84
	  lwz       r0, 0x68(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  lwz       r6, 0x4(r26)
	  addi      r3, r1, 0x34
	  lwz       r5, 0x38(r25)
	  crclr     6, 0x6
	  subi      r4, r13, 0x760C
	  bl        0x1C55CC
	  lwz       r3, 0x3C(r25)
	  addi      r4, r1, 0x34
	  li        r5, 0x1
	  bl        -0x1C1E8
	  stw       r3, 0x68(r26)
	  lwz       r0, 0x24(r26)
	  lwz       r3, 0x68(r26)
	  stw       r0, 0x24(r3)
	  b         .loc_0x98

	.loc_0x84:
	  lwz       r26, 0xC(r26)
	  addi      r3, r3, 0x1

	.loc_0x8C:
	  cmplwi    r26, 0
	  bne+      .loc_0x34
	  li        r26, 0

	.loc_0x98:
	  cmpwi     r30, -0x1
	  stw       r26, 0x28(r27)
	  bne-      .loc_0xB8
	  lwz       r0, 0x1C(r27)
	  cmpw      r0, r29
	  bne-      .loc_0xB8
	  lwz       r30, 0x20(r27)
	  b         .loc_0x110

	.loc_0xB8:
	  lwz       r5, 0x28(r27)
	  li        r4, 0
	  lwz       r3, 0x44(r5)
	  addi      r0, r5, 0x38
	  b         .loc_0xE4

	.loc_0xCC:
	  cmpw      r4, r30
	  bne-      .loc_0xDC
	  lwz       r0, 0x0(r3)
	  b         .loc_0xF0

	.loc_0xDC:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0xE4:
	  cmplw     r3, r0
	  bne+      .loc_0xCC
	  li        r0, 0

	.loc_0xF0:
	  xoris     r0, r0, 0x8000
	  lfd       f1, -0x7B18(r2)
	  stw       r0, 0x13C(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x138(r1)
	  lfd       f0, 0x138(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x2C(r27)

	.loc_0x110:
	  lfs       f2, 0x2C(r27)
	  lfs       f0, -0x7B1C(r2)
	  fcmpo     cr0, f2, f0
	  blt-      .loc_0x154
	  lwz       r3, 0x28(r27)
	  lis       r0, 0x4330
	  lfd       f1, -0x7B18(r2)
	  lwz       r3, 0x68(r3)
	  lwz       r3, 0x30(r3)
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x13C(r1)
	  stw       r0, 0x138(r1)
	  lfd       f0, 0x138(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x15C

	.loc_0x154:
	  lfs       f0, -0x7B1C(r2)
	  stfs      f0, 0x2C(r27)

	.loc_0x15C:
	  lwz       r5, 0x28(r27)
	  li        r4, 0
	  lwz       r6, 0x44(r5)
	  addi      r0, r5, 0x38
	  addi      r3, r6, 0
	  b         .loc_0x17C

	.loc_0x174:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0x17C:
	  cmplw     r3, r0
	  bne+      .loc_0x174
	  cmpw      r31, r4
	  blt-      .loc_0x1B0
	  addi      r3, r6, 0
	  addi      r0, r5, 0x38
	  li        r4, 0
	  b         .loc_0x1A4

	.loc_0x19C:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0x1A4:
	  cmplw     r3, r0
	  bne+      .loc_0x19C
	  subi      r31, r4, 0x1

	.loc_0x1B0:
	  addi      r3, r6, 0
	  addi      r0, r5, 0x38
	  li        r4, 0
	  b         .loc_0x1C8

	.loc_0x1C0:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0x1C8:
	  cmplw     r3, r0
	  bne+      .loc_0x1C0
	  cmpw      r30, r4
	  blt-      .loc_0x1F8
	  addi      r0, r5, 0x38
	  li        r3, 0
	  b         .loc_0x1EC

	.loc_0x1E4:
	  lwz       r6, 0xC(r6)
	  addi      r3, r3, 0x1

	.loc_0x1EC:
	  cmplw     r6, r0
	  bne+      .loc_0x1E4
	  subi      r30, r3, 0x1

	.loc_0x1F8:
	  stw       r29, 0x1C(r27)
	  stw       r28, 0x18(r27)
	  stw       r30, 0x20(r27)
	  stw       r31, 0x24(r27)
	  lwz       r0, 0x164(r1)
	  lmw       r25, 0x144(r1)
	  addi      r1, r1, 0x160
	  mtlr      r0
	  blr
	*/
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
	startAnim(_08, _0C, _10, _14);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x8(r3)
	  lwz       r5, 0xC(r3)
	  lwz       r6, 0x10(r3)
	  lwz       r7, 0x14(r3)
	  bl        -0x23C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800511C0
 * Size:	00005C
 */
void Animator::updateContext()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lis       r0, 0x4330
	  lwz       r5, 0x28(r3)
	  lwz       r4, 0x4(r3)
	  lwz       r5, 0x68(r5)
	  stw       r5, 0x0(r4)
	  lfs       f0, 0x2C(r3)
	  lwz       r4, 0x4(r3)
	  stfs      f0, 0x4(r4)
	  lwz       r4, 0x28(r3)
	  lfs       f2, 0x2C(r3)
	  lwz       r4, 0x68(r4)
	  lfd       f1, -0x7B18(r2)
	  lwz       r3, 0x30(r4)
	  xoris     r3, r3, 0x8000
	  stw       r3, 0x14(r1)
	  stw       r0, 0x10(r1)
	  lfd       f0, 0x10(r1)
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8005121C
 * Size:	00023C
 */
void Animator::animate(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  lwz       r6, 0x28(r3)
	  lwz       r0, 0x24(r6)
	  rlwinm.   r0,r0,0,30,30
	  beq-      .loc_0x28
	  b         .loc_0x2C

	.loc_0x28:
	  lfs       f1, 0x34(r6)

	.loc_0x2C:
	  lwz       r7, 0x44(r6)
	  addi      r0, r6, 0x38
	  lwz       r5, 0x20(r31)
	  li        r4, 0
	  addi      r3, r7, 0
	  b         .loc_0x5C

	.loc_0x44:
	  cmpw      r4, r5
	  bne-      .loc_0x54
	  lwz       r0, 0x0(r3)
	  b         .loc_0x68

	.loc_0x54:
	  lwz       r3, 0xC(r3)
	  addi      r4, r4, 0x1

	.loc_0x5C:
	  cmplw     r3, r0
	  bne+      .loc_0x44
	  li        r0, 0

	.loc_0x68:
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x7B18(r2)
	  stw       r0, 0x4C(r1)
	  lis       r0, 0x4330
	  lwz       r4, 0x24(r31)
	  li        r3, 0
	  stw       r0, 0x48(r1)
	  addi      r0, r6, 0x38
	  lfd       f0, 0x48(r1)
	  fsubs     f3, f0, f2
	  b         .loc_0xAC

	.loc_0x94:
	  cmpw      r3, r4
	  bne-      .loc_0xA4
	  lwz       r0, 0x0(r7)
	  b         .loc_0xB8

	.loc_0xA4:
	  lwz       r7, 0xC(r7)
	  addi      r3, r3, 0x1

	.loc_0xAC:
	  cmplw     r7, r0
	  bne+      .loc_0x94
	  li        r0, 0

	.loc_0xB8:
	  xoris     r3, r0, 0x8000
	  lwz       r0, 0x18(r31)
	  stw       r3, 0x4C(r1)
	  lis       r3, 0x4330
	  lfd       f2, -0x7B18(r2)
	  cmpwi     r0, 0
	  stw       r3, 0x48(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f4, f0, f2
	  beq-      .loc_0x1EC
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x174
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x2C(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f1, 0x2C(r31)
	  fcmpo     cr0, f1, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x164
	  lwz       r0, 0x18(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x140
	  fsubs     f0, f4, f3
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x2C(r31)
	  fcmpo     cr0, f0, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1EC
	  stfs      f3, 0x2C(r31)
	  b         .loc_0x1EC

	.loc_0x140:
	  lfs       f0, -0x7B10(r2)
	  mr        r3, r31
	  fsubs     f0, f4, f0
	  stfs      f0, 0x2C(r31)
	  lwz       r12, 0x30(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1EC

	.loc_0x164:
	  fcmpo     cr0, f1, f3
	  bge-      .loc_0x1EC
	  stfs      f3, 0x2C(r31)
	  b         .loc_0x1EC

	.loc_0x174:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x2C(r31)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f1, 0x2C(r31)
	  fcmpo     cr0, f1, f4
	  bge-      .loc_0x1E0
	  lwz       r0, 0x18(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1C4
	  fsubs     f0, f3, f4
	  fadds     f0, f1, f0
	  stfs      f0, 0x2C(r31)
	  lfs       f0, 0x2C(r31)
	  fcmpo     cr0, f0, f4
	  bge-      .loc_0x1EC
	  stfs      f4, 0x2C(r31)
	  b         .loc_0x1EC

	.loc_0x1C4:
	  stfs      f4, 0x2C(r31)
	  mr        r3, r31
	  lwz       r12, 0x30(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1EC

	.loc_0x1E0:
	  fcmpo     cr0, f1, f3
	  ble-      .loc_0x1EC
	  stfs      f3, 0x2C(r31)

	.loc_0x1EC:
	  lfs       f0, 0x2C(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stfd      f0, 0x48(r1)
	  cmpwi     r0, 0
	  lwz       r4, 0x4C(r1)
	  blt-      .loc_0x220
	  lwz       r3, 0x28(r31)
	  lwz       r3, 0x68(r3)
	  lwz       r0, 0x30(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x228

	.loc_0x220:
	  lfs       f0, -0x7B1C(r2)
	  stfs      f0, 0x2C(r31)

	.loc_0x228:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80051458
 * Size:	000008
 */
void Animator::changeContext(AnimContext* context)
{
	mContext = context;
}
