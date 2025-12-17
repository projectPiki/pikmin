#ifndef _AYU_H
#define _AYU_H

#include "types.h"

/**
 * @brief TODO
 */
struct ayuID {
	ayuID() { mID = 0; }
	ayuID(immut char* id) { Set(id); }

	void Set(immut char* id) { mID = *(s32*)id; }
	s32& Num() { return mID; };

	s32 mID; // _00
};

struct MemHead {
	u32 mTagAndSize; // _00, stores a tag in the most significant byte and size in 16-byte units in the lower bytes
	MemHead* mNext;  // _04
	MemHead* mPrev;  // _08
};

/**
 * @brief TODO
 */
struct AyuCache {
	AyuCache(u32);

	void init(u32, u32);
	void* mallocL(u32);
	void cacheFree(void*);
	bool isEmpty();
	u32 largestBlockFree();

	int getIndex();
	void releaseIndex(int);
	void deleteIdAll(u32);
	u32 amountFree();

	MemHead mFreeBlockHead;      // _00
	u8 _0C[0x10 - 0x0c];         // _0C, padding to align
	MemHead mAllocatedBlockHead; // _10
	u32 mBlockGuardValue;        // _1C, Magic number (e.g., 0x87654321) used as a guard/canary for memory blocks
	u32 mCurrentAllocationTag;   // _20, tag value (0-255) applied to new allocations via mallocL, stored in the high byte of MemHead's flag
	u32 mTotalAllocatedUnits;    // _24
	u32 mTotalCacheSizeBytes;    // _28
	u8 mPageIndexPool[256];      // _2C
	u32 mNextPageSlot;           // _12C
};

/**
 * @brief TODO
 */
struct AyuStack {
	AyuStack() { mIsActive = false; }

	void reset(int);
	void* push(int);
	void pop();

	// unused/inlined:
	void create(immut char* name, int allocType, void* stackTop, int stackSize, bool isProtectionEnabled);
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

	s32 mAllocType;         // _00
	int mSize;              // _04
	int mTotalSize;         // _08
	u32 mInitialStackTop;   // _0C
	u32 mInitialStackLimit; // _10
	u32 mStackTop;          // _14
	u32 mStackLimit;        // _18
	bool mProtectOverflow;  // _1C
	bool mIsActive;         // _1D
	immut char* mName;      // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct AyuHeap : public AyuStack {
	AyuHeap() { }

	void init(immut char* name, int allocType, void* stackTop, int stackSize);

	// _00-_24 = AyuStack
	u8 _24; // _24
};

#endif
