#include "sysNew.h"

#include "DebugLog.h"
#include "MemStat.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(6)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("sysNew");

/*
 * --INFO--
 * Address:	80047004
 * Size:	000164
 */
void* System::alloc(u32 size)
{
	void* result = nullptr;
	if (size & 0x3) {
		size = (size + 3) & ~0x3;
	}

	if (gsys->mActiveHeapIdx < 0) {
#if 0
		// The DLL uses `GlobalAlloc` here and has an ERROR if that fails.  This branch of code is probably DLL exclusive,
		// since the GCN can't just ask WinAPI for unlimited memory.  We'll see once JPN Demo version matching begins.
		if (!result) {
			ERROR("new[] %d failed", size);
		}
#endif
	} else {
		AyuHeap* heap = &gsys->mHeaps[gsys->mActiveHeapIdx];
		if (size == 0) {
			PRINT("trying to allocate %d bytes on heap\n", 0);
		}
		result = heap->push(size);
		if (!result) {
			ERROR("new[] %d failed in heap '%s'", gsys->mActiveHeapIdx, size);
		}

		if (size == 0 || gsys->mForcePrint) {
			bool print         = gsys->mTogglePrint;
			gsys->mTogglePrint = TRUE;
			gsys->mTogglePrint = print;
		}

		MemInfo* info = gsys->mCurrMemInfo;
		while (info) {
			info->mMemorySize += size;
			info = static_cast<MemInfo*>(info->mParent);
		}

		if ((u32)result & 0x3) {
			((u32)result); // idek man
		}

		int length = size / 4;
		for (int i = 0; i < length; i++) {
			((u32*)result)[i] = 0;
		}
	}

	return result;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void* operator new(u32, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80047168
 * Size:	000044
 */
void* operator new[](u32 size, int alignment)
{
	u32 alloc  = (u32)System::alloc(size + alignment);
	u32 result = (alloc + (alignment - 1)) & ~(alignment - 1);
	return (void*)result;
}

/*
 * --INFO--
 * Address:	800471AC
 * Size:	000004
 */
void operator delete(void*)
{
}

/*
 * --INFO--
 * Address:	800471B0
 * Size:	000004
 */
void operator delete[](void*)
{
}
