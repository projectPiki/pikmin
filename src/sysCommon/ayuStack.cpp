#include "Ayu.h"

#include "system.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(7)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("AyuStack");

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void AyuStack::create(char* name, int allocType, void* stackTop, int stackSize, bool isProtectionEnabled)
{
	mAllocType         = allocType;
	mIsActive          = true;
	mName              = name;
	mInitialStackTop   = (u32)stackTop;
	mInitialStackLimit = mInitialStackTop + stackSize;
	mSize              = mInitialStackLimit - mInitialStackTop;
	mProtectOverflow   = isProtectionEnabled;
	if (mProtectOverflow) {
		((u32*)mInitialStackTop)[0] = 0x12345678;
	}

	reset();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void AyuStack::reset()
{
	mStackTop   = mInitialStackTop;
	mStackLimit = mInitialStackLimit;
	mTotalSize  = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void AyuStack::checkStack()
{
	if (mAllocType & 2 && mStackTop - *((u32*)mStackTop - 2) != mInitialStackTop) {
		ERROR("trashed memory stack (%s)\n", mName);
	}
}

/*
 * --INFO--
 * Address:	800246E4
 * Size:	0000BC
 */
void AyuStack::reset(int i)
{
	if (i & 2) {
		int prev = setAllocType(i);
		gsys->invalidateObjs(mInitialStackTop, mStackTop);

		while (mStackTop != mInitialStackTop) {
			pop();
		}

		setAllocType(prev);
	}

	if (i & 1) {
		int prev = setAllocType(i);
		gsys->invalidateObjs(mStackLimit, mInitialStackLimit);

		while (mStackLimit != mInitialStackLimit) {
			pop();
		}

		setAllocType(prev);
	}
}

/*
 * --INFO--
 * Address:	800247A0
 * Size:	000114
 */
void* AyuStack::push(int requestedSize)
{
	if (!requestedSize) {
		requestedSize = 1;
	}

	if (IS_NOT_ALIGNED(requestedSize, 8)) {
		requestedSize = ALIGN_NEXT(requestedSize, 8);
	}

	if (mAllocType == 2) {
		if (mStackTop + (requestedSize + 8) > mStackLimit) {
			return nullptr;
		}

		u32 previousSize;
		u32 stackStart;
		if (mStackTop != mInitialStackTop) {
			int tmp      = mStackTop - 8;
			previousSize = *(u32*)(mStackTop - 8);
			stackStart   = tmp;
		} else {
			previousSize = 0;
			stackStart   = mStackTop;
		}

		mTotalSize += (requestedSize + 8);
		mStackTop += (requestedSize + 8);
		*(u32*)(mStackTop - 8) = previousSize + (requestedSize + 8);

		if (mAllocType & 2) {
			if (mStackTop - *(u32*)(mStackTop - 8) > mInitialStackTop) {
				(mStackTop);
			}
		}

		return (void*)stackStart;
	} else {
		if (mStackLimit - (requestedSize + 8) < mStackTop) {
			return nullptr;
		}

		mTotalSize += (requestedSize + 8);
		mStackLimit -= (requestedSize + 8);
		*(u32*)mStackLimit = (requestedSize + 8);
		return (void*)(mStackLimit + 8);
	}
}

/*
 * --INFO--
 * Address:	800248B4
 * Size:	000054
 */
void AyuStack::pop()
{
	if (mAllocType == 2) {
		u32 subVal = *(u32*)(mStackTop - 8);
		mTotalSize -= subVal;
		mStackTop -= subVal;
		return;
	}

	u32 diffVal = *(u32*)mStackLimit;
	mTotalSize -= diffVal;
	mStackLimit += diffVal;
}

/*
 * --INFO--
 * Address:	80024908
 * Size:	000074
 */
void AyuHeap::init(char* name, int allocType, void* stackTop, int stackSize)
{
	create(name, allocType, stackTop, stackSize, false);
	_24 = 0;
}

/*
 * --INFO--
 * Address:	8002497C
 * Size:	000068
 */
AyuCache::AyuCache(u32 cacheSize)
{
	PRINT("Creating cache of size %.2f k\n", cacheSize / 1024.0f);

	s32 alignedSize = OSRoundUp32B(cacheSize);
	u32 bufAddr     = (u32) new char[(alignedSize / 4) * 4];
	init(bufAddr, bufAddr + alignedSize);
}

/*
 * --INFO--
 * Address:	800249E4
 * Size:	000198
 */
void AyuCache::init(u32 a2, u32 a3)
{
	mTotalAllocatedUnits            = 0;
	mTotalCacheSizeBytes            = (a3 - a2);
	mCurrentAllocationTag           = 0;
	mAllocatedBlockHead.mNext       = &mAllocatedBlockHead;
	mAllocatedBlockHead.mPrev       = &mAllocatedBlockHead;
	mAllocatedBlockHead.mTagAndSize = 0;
	mBlockGuardValue                = 0x87654321;

	u32* ptr = (u32*)a2;
	ptr[1]   = (u32)this;
	ptr[2]   = (u32)this;
	ptr[0]   = ((a3 - a2) >> 4) - 0x1000001;
	ptr[3]   = 0x87654321;

	mFreeBlockHead.mNext       = (MemHead*)a2;
	mFreeBlockHead.mPrev       = (MemHead*)a2;
	mFreeBlockHead.mTagAndSize = 0xFF000000;

	for (int i = 0; i < 256; i++) {
		mPageIndexPool[i] = i;
	}

	mNextPageSlot = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
int AyuCache::getIndex()
{
	return mPageIndexPool[mNextPageSlot++];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void AyuCache::releaseIndex(int idx)
{
	for (int i = 0;; i++) {
		if (i >= mNextPageSlot) {
			ERROR("Could not release the index %d\n", idx);
		}

		if (mPageIndexPool[i] == idx) {
			break;
		}
	}

	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void linkChunk(MemHead* p1, u32 p2, MemHead* p3)
{
	p1->mNext        = p3;
	p1->mPrev        = p3->mPrev;
	p3->mPrev        = p1;
	p1->mPrev->mNext = p1;
	p1->mTagAndSize  = p2;
}

/*
 * --INFO--
 * Address:	80024B7C
 * Size:	000120
 */
void* AyuCache::mallocL(u32 size)
{
	u32 a          = (size + 0xF) >> 4;
	MemHead* chunk = nullptr;
	for (MemHead* i = mFreeBlockHead.mNext; i != &mFreeBlockHead; i = i->mNext) {
		int b = (i->mTagAndSize & 0xFFFFFF) - a;
		if (b >= 0 && b < 0x7FFFFFFF) {
			chunk = i;
			break;
		}
	}

	if (!chunk) {
		return nullptr;
	}

	if ((chunk->mTagAndSize & 0xFFFFFF) == a) {
		chunk->mNext->mPrev = chunk->mPrev;
		chunk->mPrev->mNext = chunk->mNext;
	} else {
		MemHead* tmp           = (MemHead*)((u32)chunk + 16 * a + 16);
		tmp->mNext             = chunk->mNext;
		tmp->mPrev             = chunk->mPrev;
		tmp->mNext->mPrev      = tmp;
		tmp->mPrev->mNext      = tmp;
		tmp->mTagAndSize       = chunk->mTagAndSize - a - 1;
		(tmp + 1)->mTagAndSize = 0x87654321;
	}

	linkChunk(chunk, (mCurrentAllocationTag << 24) + a, &mAllocatedBlockHead);

	mTotalAllocatedUnits += chunk->mTagAndSize & 0xFFFFFF;
	MemHead* next     = chunk + 1;
	next->mTagAndSize = 0x12345678;

	return ((u32*)chunk + 4);
}

/*
 * --INFO--
 * Address:	80024C9C
 * Size:	000114
 */
void AyuCache::cacheFree(void* cache)
{
	MemHead* blockToFree = (MemHead*)((u32)cache - 16);
	mTotalAllocatedUnits -= blockToFree->mTagAndSize & 0xFFFFFF;

	// Find insertion point in the address-sorted free list
	MemHead* b = &mFreeBlockHead;
	for (MemHead* i = mFreeBlockHead.mNext; i != &mFreeBlockHead && b == &mFreeBlockHead; i = i->mNext) {
		if (blockToFree < i) {
			b = i;
		}
	}

	blockToFree->mNext->mPrev = blockToFree->mPrev;
	blockToFree->mPrev->mNext = blockToFree->mNext;

	// Add to free list with updated flags (marking as free)
	linkChunk(blockToFree, (blockToFree->mTagAndSize & 0xFFFFFF) - 0x1000000, b);

	// Coalesce with adjacent free blocks
	// Forward coalesce: merge with the next physical block if it's also free
	if ((MemHead*)((u32)blockToFree + 16 * (blockToFree->mTagAndSize & 0xFFFFFF) + 16) == blockToFree->mNext) {
		blockToFree->mTagAndSize += (blockToFree->mNext->mTagAndSize & 0xFFFFFF) + 1;
		blockToFree->mNext->mNext->mPrev = blockToFree;
		blockToFree->mNext               = blockToFree->mNext->mNext;
	}

	// Backward coalesce: merge with the previous physical block if it's also free
	if ((MemHead*)((u32)blockToFree->mPrev + (16 * (blockToFree->mPrev->mTagAndSize & 0xFFFFFF)) + 16) == blockToFree) {
		blockToFree->mPrev->mTagAndSize += (blockToFree->mTagAndSize & 0xFFFFFF) + 1;
		blockToFree->mNext->mPrev = blockToFree->mPrev;
		blockToFree->mPrev->mNext = blockToFree->mNext;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void AyuCache::deleteIdAll(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
u32 AyuCache::amountFree()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80024DB0
 * Size:	000018
 */
bool AyuCache::isEmpty()
{
	return mAllocatedBlockHead.mNext == &mAllocatedBlockHead;
}

/*
 * --INFO--
 * Address:	80024DC8
 * Size:	000034
 */
u32 AyuCache::largestBlockFree()
{
	u32 max = 0;
	for (MemHead* i = mFreeBlockHead.mNext; i != &mFreeBlockHead; i = i->mNext) {
		if (16 * (i->mTagAndSize & 0xFFFFFF) > max) {
			max = 16 * (i->mTagAndSize & 0xFFFFFF);
		}
	}

	return max;
}
