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
DEFINE_ERROR()

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
MemStat::MemStat()
{
	reset();
}

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

	if (info) {
		mPrevInfoStack[mStatCount] = mCurrentInfo;
		mStatCount++;
		if (mStatCount == 32) {
			ERROR("%s:start", name);
		}
		mCurrentInfo       = info;
		gsys->mCurrMemInfo = mCurrentInfo;

	} else {
		PRINT("no info !!\n");
	}
}

/*
 * --INFO--
 * Address:	80086848
 * Size:	000078
 */
void MemStat::end(char* name)
{
	int unused;
	if (!memStat) {
		return;
	}

	MemInfo* info = getInfo(name);
	if (info) {
		// Remove the current info from the stack
		mStatCount--;
		!!mStatCount;
		unused             = mStatCount;
		mCurrentInfo       = mPrevInfoStack[mStatCount];
		gsys->mCurrMemInfo = mCurrentInfo;
	} else {
		PRINT("no INFOOO\n", name);
	}
	!(unused++);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
int MemStat::getMemorySize(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
int MemStat::getRestMemory()
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
MemInfo* MemStat::getInfo(char* name)
{
	return getInfoRec(name, &mInfoListRoot);
}

/*
 * --INFO--
 * Address:	80086918
 * Size:	000238
 */
void MemStat::printInfoRec(MemInfo* baseInfo, int idx)
{
	STACK_PAD_VAR(191); // this is a LOT of stack inflation, gotta be from some debug stuff.

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
