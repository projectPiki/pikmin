#ifndef _AYU_H
#define _AYU_H

#include "types.h"

/**
 * @brief TODO
 */
struct ayuID {
	inline ayuID(char* id) { Set(id); }

	void Set(char* id) { mID = *(u32*)id; }

	u32 mID; // _00
};

struct MemHead { };

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

	u32 _00;     // _00
	u32 _04;     // _04
	u32 _08;     // _08
	s8 _0C;      // _0C
	u32 _10;     // _10
	u32 _14;     // _14
	u32 _18;     // _18
	u32 _1C;     // _1C
	u32 _20;     // _20
	u32 _24;     // _24
	u32 _28;     // _28
	u8 _2C[256]; // _2C
	u32 _12C;    // _12C
};

/**
 * @brief TODO
 */
struct AyuStack {
	AyuStack() { mIsActive = false; }

	bool checkOverflow();
	inline void checkStack();
	void create(char* name, int allocType, void* stackTop, int stackSize, bool isProtectionEnabled);
	inline int getFree() { return mSize - mTotalSize; }
	int getMaxFree();
	int getSize();
	int getTopUsed() { return mInitialStackLimit - mStackLimit; }
	int getUsed();
	void inactivate();
	void pop();
	void* push(int);
	void reset(int);
	void reset();
	inline int setAllocType(int type)
	{
		int old    = mAllocType;
		mAllocType = type;
		return old;
	}

	s32 mAllocType;         // _00
	int mSize;              // _04
	int mTotalSize;         // _08
	u32 mInitialStackTop;   // _0C
	u32 mInitialStackLimit; // _10
	u32 mStackTop;          // _14
	u32 mStackLimit;        // _18
	bool mProtectOverflow;  // _1C
	bool mIsActive;         // _1D
	char* mName;            // _20
};

/**
 * @brief TODO
 *
 * @note Size: 0x28.
 */
struct AyuHeap : public AyuStack {
	AyuHeap() { }

	void init(char* name, int allocType, void* stackTop, int stackSize);

	// _00-_24 = AyuStack
	u8 _24; // _24
};

#endif
