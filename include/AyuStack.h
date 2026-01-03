#ifndef _AYUSTACK_H
#define _AYUSTACK_H

#include "types.h"

struct MemHead {
	u32 mTagAndSize; // _00, tag in high byte; size in low 24 bits
	MemHead* mNext;  // _04, next node in list
	MemHead* mPrev;  // _08, previous node in list
};

/**
 * @brief TODO
 */
struct AyuCache {
	AyuCache(u32);

	void init(u32 bufferStart, u32 bufferEnd);
	void* mallocL(u32 sizeBytes);
	void cacheFree(void* ptr);
	bool isEmpty();
	u32 largestBlockFree();

	int getIndex();
	void releaseIndex(int);
	void deleteIdAll(u32);
	u32 amountFree();

	MemHead mFreeBlockHead;      // _00, sentinel head for address-sorted free list
	u8 _0C[0x4];                 // _0C, unused
	MemHead mAllocatedBlockHead; // _10, sentinel head for allocated list (typically MRU/LRU ordered)
	u32 mBlockGuardValue;        // _1C, guard/canary value written into headers/trailers
	u32 mCurrentAllocationTag;   // _20, tag (0-255) applied to new allocations via mallocL
	u32 mTotalAllocatedUnits;    // _24, allocated size in 16-byte units
	u32 mTotalCacheSizeBytes;    // _28, total cache size in bytes
	u8 mPageIndexPool[256];      // _2C, pool of indices used by cache paging
	u32 mNextPageSlot;           // _12C, next index slot to hand out
};

#define AYU_STACK_GROW_DOWN (1) // Grows toward lower addresses.
#define AYU_STACK_GROW_UP   (2) // Grows toward higher addresses.

/**
 * @brief TODO
 */
struct AyuStack {
	AyuStack() { mIsActive = false; }

	void reset(int resetFlags);
	void* push(int requestedSizeBytes);
	void pop();

	// unused/inlined:
	void create(immut char* name, int allocFlags, void* stackBase, int stackSizeBytes, bool enableOverflowGuard);
	void reset();
	void checkStack();

	// DLL inlines:
	int setAllocType(int type)
	{
		int old    = mAllocType;
		mAllocType = type;
		return old;
	}
	int getFree() { return mSize - mTotalSize; }
	int getTopUsed() { return mInitialStackLimit - mStackLimit; }
	int getMaxFree() { return (mSize - mTotalSize - 8 > 0) ? mSize - mTotalSize - 8 : 0; }
	void inactivate() { mIsActive = false; }

	s32 mAllocType;         // _00, allocation mode (e.g. AYU_STACK_GROW_DOWN/UP)
	int mSize;              // _04, total size in bytes
	int mTotalSize;         // _08, total bytes currently allocated
	u32 mInitialStackTop;   // _0C, base pointer for upward growth
	u32 mInitialStackLimit; // _10, base pointer for downward growth
	u32 mStackTop;          // _14, current top when growing upward
	u32 mStackLimit;        // _18, current limit when growing downward
	bool mProtectOverflow;  // _1C, whether guard word/checks are enabled
	bool mIsActive;         // _1D, whether this stack is currently active
	immut char* mName;      // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct AyuHeap : public AyuStack {
	AyuHeap() { }

	void init(immut char* name, int allocFlags, void* stackBase, int stackSizeBytes);

	// _00-_24 = AyuStack
	u8 _24; // _24
};

#endif
