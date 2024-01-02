#ifndef _AYUSTACK_H
#define _AYUSTACK_H

#include "types.h"

struct AyuStack {
	AyuStack(void);

	bool checkOverflow(void);
	void checkStack(void);
	void create(char*, int, void*, int, bool);
	int getFree(void);
	int getMaxFree(void);
	int getSize(void);
	int getTopUsed(void);
	int getUsed(void);
	void inactivate(void);
	void pop(void);
	void* push(int);
	void reset(int);
	void reset(void);
	int setAllocType(int);

	s32 mAllocType;        // _00
	s32 mSize;             // _04
	s32 mUsed;             // _08
	u32* mTop;             // _0C
	s32 mTopSize;          // _10
	u32* mStackPointer;    // _14
	s32 mTopFree;          // _18
	bool mProtectOverflow; // _1C
	bool mIsActive;        // _1D
	s8* mName;             // _20
};

#endif