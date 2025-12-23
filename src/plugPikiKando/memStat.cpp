#include "MemStat.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "system.h"
#include <string.h>

MemStat* memStat;

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(4)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("memStat");

/**
 * @TODO: Documentation
 */
MemStat::MemStat()
{
	reset();
}

/**
 * @TODO: Documentation
 */
void MemStat::reset()
{
	mInfoListRoot.initCore("infoList");
	mCurrentInfo = &mInfoListRoot;
	mStatCount   = 0;
}

/**
 * @TODO: Documentation
 */
void MemStat::start(immut char* name)
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

/**
 * @TODO: Documentation
 */
void MemStat::end(immut char* name)
{
	if (!memStat) {
		return;
	}

	MemInfo* info = getInfo(name);
	if (info) {
		// Remove the current info from the stack
#if defined(BUGFIX)
		if (mStatCount == 0) {
			ERROR("%s:end", name);
		}
		mStatCount--;
#else
		mStatCount--;
		// Trick question!  MWCC refuses to treat this condition with respect, but MSVC emits code indicating `mStatCount` is unsigned
		// and thus it would be UNDEFINED BEHAVIOR for it to underflow.  Sorry Kando, the C++ Standard says fuck your underflow check.
		if (mStatCount < 0) {
			ERROR("%s:end", name);
		}
#endif
		mCurrentInfo       = mPrevInfoStack[mStatCount];
		gsys->mCurrMemInfo = mCurrentInfo;
	} else {
		PRINT("no INFOOO\n", name);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
int MemStat::getMemorySize(immut char* name)
{
	// UNUSED FUNCTION
	if (MemInfo* info = getInfo(name)) {
		return info->mMemorySize;
	}
	return 0;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
int MemStat::getRestMemory()
{
	// UNUSED FUNCTION
	return gsys->getHeap(SYSHEAP_App)->getFree();
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
MemInfo* MemStat::getInfo(immut char* name)
{
	return getInfoRec(name, &mInfoListRoot);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
MemInfo* MemStat::getInfoRec(immut char* name, MemInfo* info)
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
