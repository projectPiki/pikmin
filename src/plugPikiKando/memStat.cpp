#include "MemStat.h"
#include "Dolphin/os.h"
#include "system.h"
#include "sysNew.h"
#include "stl/string.h"
#include "DebugLog.h"

MemStat* memStat;

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
DEFINE_PRINT("memStat");

/*
 * --INFO--
 * Address:	80086690
 * Size:	000080
 */
MemStat::MemStat() { reset(); }

/*
 * --INFO--
 * Address:	80086710
 * Size:	000028
 */
void MemStat::reset()
{
	mInfoListRoot.initCore("infoList");
	mCurrentInfo = &mInfoListRoot;
	mStatCount   = 0;
}

/*
 * --INFO--
 * Address:	80086738
 * Size:	000110
 */
void MemStat::start(char* name)
{
	if (!memStat) {
		return;
	}

	MemInfo* info = getInfo(name);
	if (!info) {
		info = new MemInfo;
		info->setName(name);
		info->mParent     = mCurrentInfo;
		info->mMemorySize = 0;
		mCurrentInfo->add(info);
	}

	if (!info) {
		return;
	}

	addInfo(info);
	gsys->setCurrMemInfo(mCurrentInfo);
}

/*
 * --INFO--
 * Address:	80086848
 * Size:	000078
 */
void MemStat::end(char* name)
{
	if (memStat && getInfo(name)) {
		// Remove the current info from the stack
		mStatCount--;
		(mStatCount > 0);

		// If the current info is not the root info, set the current info to the previous info
		mCurrentInfo       = mPrevInfoStack[mStatCount];
		gsys->mCurrMemInfo = mCurrentInfo;
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x2FE8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  mr        r3, r30
	  bl        0x84
	  cmplwi    r3, 0
	  beq-      .loc_0x60
	  lwz       r3, 0x9C(r30)
	  subi      r0, r3, 0x1
	  stw       r0, 0x9C(r30)
	  lwz       r5, 0x9C(r30)
	  rlwinm    r0,r5,2,0,29
	  add       r3, r30, r0
	  lwz       r0, 0x1C(r3)
	  stw       r0, 0x18(r30)
	  lwz       r0, 0x18(r30)
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x19C(r3)

	.loc_0x60:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void MemStat::getMemorySize(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void MemStat::getRestMemory()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800868C0
 * Size:	000034
 */
void MemStat::print()
{
	if (memStat) {
		printInfoRec(static_cast<MemInfo*>(mInfoListRoot.mChild), 4);
	}
}

/*
 * --INFO--
 * Address:	800868F4
 * Size:	000024
 */
MemInfo* MemStat::getInfo(char* name) { return getInfoRec(name, &mInfoListRoot); }

/*
 * --INFO--
 * Address:	80086918
 * Size:	000238
 */
void MemStat::printInfoRec(MemInfo* baseInfo, int idx)
{
	u32 badCompiler[191]; // this is a LOT of stack inflation, gotta be from some debug stuff.

	for (int i = 0; i < idx; i++) {
		;
	}

	if (baseInfo->mMemorySize >= 0x100000) {
		(f32(baseInfo->mMemorySize));
	} else {
		(f32(baseInfo->mMemorySize));
	}

	if (baseInfo->mChild) {
		printInfoRec(static_cast<MemInfo*>(baseInfo->mChild), idx + 4);
	}

	if (baseInfo->mNext) {
		printInfoRec(static_cast<MemInfo*>(baseInfo->mNext), idx);
	}
}

/*
 * --INFO--
 * Address:	80086B50
 * Size:	000174
 */
MemInfo* MemStat::getInfoRec(char* name, MemInfo* baseInfo)
{
	if (strcmp(baseInfo->mName, name) == 0) {
		return baseInfo;
	}

	if (static_cast<MemInfo*>(baseInfo->mNext)) {
		MemInfo* newInfo = getInfoRec(name, static_cast<MemInfo*>(baseInfo->mNext));
		if (newInfo) {
			return newInfo;
		}
	}

	if (static_cast<MemInfo*>(baseInfo->mChild)) {
		MemInfo* newInfo = getInfoRec(name, static_cast<MemInfo*>(baseInfo->mChild));
		if (newInfo) {
			return newInfo;
		}
	}

	return nullptr;
}
