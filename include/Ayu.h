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

	// TODO: members
};

/**
 * @brief TODO
 */
struct AyuStack {
	AyuStack();

	bool checkOverflow();
	void checkStack();
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
	int setAllocType(int);

	int mAllocType;        // _00
	int mSize;             // _04
	int mUsed;             // _08
	u32* mTop;             // _0C
	int mTopSize;          // _10
	u32* mStackPointer;    // _14
	int mTopFree;          // _18
	bool mProtectOverflow; // _1C
	bool mIsActive;        // _1D
	char* mName;           // _20
};

/**
 * @brief TODO
 */
struct AyuHeap : public AyuStack {
	AyuHeap();

	void init(char*, int, void*, int);

	// _00-_24 = AyuStack
	int _24; // _24
};

#endif
