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
	void mallocL(u32);
	void cacheFree(void*);
	bool isEmpty();
	void largestBlockFree();

	void getIndex();
	void releaseIndex(int);
	void deleteIdAll(u32);
	void amountFree();

	// TODO: members
};

/**
 * @brief TODO
 */
struct AyuStack {
	AyuStack() { mIsActive = false; }

	bool checkOverflow();
	inline void checkStack();
	void create(char*, int, void*, int, bool);
	int getFree();
	int getMaxFree();
	int getSize();
	int getTopUsed();
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

	void init(char*, int, void*, int);

	// _00-_24 = AyuStack
	int _24; // _24
};

#endif
