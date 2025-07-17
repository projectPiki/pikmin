#include "MemStat.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "VersionGroups.h"
#include "stl/string.h"
#include "sysNew.h"
#include "system.h"

MemStat* memStat;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(4)

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
	if (!memStat) {
		return;
	}

	MemInfo* info = getInfo(name);
	if (info) {
		// Remove the current info from the stack
		mStatCount--;
		// Trick question!  MWCC refuses to treat this condition with respect, but MSVC emits code indicating `mStatCount` is unsigned
		// and thus it would be UNDEFINED BEHAVIOR for it to underflow.  Sorry Kando, the C++ Standard says fuck your underflow check.
		if (mStatCount < 0) {
			ERROR("%s:end", name);
		}
		mCurrentInfo       = mPrevInfoStack[mStatCount];
		gsys->mCurrMemInfo = mCurrentInfo;
	} else {
		PRINT("no INFOOO\n", name);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
int MemStat::getMemorySize(char* name)
{
	// UNUSED FUNCTION
	if (MemInfo* info = getInfo(name)) {
		return info->mMemorySize;
	}
	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
int MemStat::getRestMemory()
{
	// UNUSED FUNCTION
	return gsys->getHeap(SYSHEAP_App)->getFree();
}

/*
 * --INFO--
 * Address:	800868C0
 * Size:	000034
 */
void MemStat::print()
{
	if (memStat) {
#if defined(VERSION_PIKIDEMO)
		_Print("****** MEMORY INFO ******\n");
#else
		PRINT("****** MEMORY INFO ******\n");
#endif
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
void MemStat::printInfoRec(MemInfo* info, int indentation)
{
	int i;
	char leftPad[PATH_MAX];

	for (i = 0; i < indentation; i++) {
		leftPad[i] = '\t';
	}
	leftPad[i] = '\0';

	if (info->mMemorySize >= 1024 * 1024) {
#if defined(VERSION_PIKIDEMO)
		_Print("%s%s : %6.2f mbytes\n", leftPad, info->mName, info->mMemorySize / 1024.0f / 1024.0f);
#else
		PRINT("%s%s : %6.2f mbytes\n", leftPad, info->mName, info->mMemorySize / 1024.0f / 1024.0f);
#endif
	} else {
#if defined(VERSION_PIKIDEMO)
		_Print("%s%s : %6.2f kbytes\n", leftPad, info->mName, info->mMemorySize / 1024.0f);
#else
		PRINT("%s%s : %6.2f kbytes\n", leftPad, info->mName, info->mMemorySize / 1024.0f);
#endif
	}

	if (info->mChild) {
		printInfoRec(static_cast<MemInfo*>(info->mChild), indentation + 4);
	}

	if (info->mNext) {
		printInfoRec(static_cast<MemInfo*>(info->mNext), indentation);
	}
}

/*
 * --INFO--
 * Address:	80086B50
 * Size:	000174
 */
MemInfo* MemStat::getInfoRec(char* name, MemInfo* info)
{
	if (strcmp(info->mName, name) == 0) {
		return info;
	}

	if (static_cast<MemInfo*>(info->mNext)) {
		MemInfo* newInfo = getInfoRec(name, static_cast<MemInfo*>(info->mNext));
		if (newInfo) {
			return newInfo;
		}
	}

	if (static_cast<MemInfo*>(info->mChild)) {
		MemInfo* newInfo = getInfoRec(name, static_cast<MemInfo*>(info->mChild));
		if (newInfo) {
			return newInfo;
		}
	}

	return nullptr;
}
