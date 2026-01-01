#include "Ayu.h"
#include "DebugLog.h"
#include "sysNew.h"
#include "system.h"

#define AYU_STACK_GUARD_WORD 0x12345678

#define AYU_CACHE_GUARD_WORD 0x87654321
#define AYU_CACHE_FREE_FLAG  0xFF000000

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(7)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("AyuStack");

/**
 * Creates and initializes a stack region with optional overflow protection.
 * @param name Name for debugging.
 * @param allocFlags Allocation mode flags (bitmask of AYU_STACK_GROW_*).
 * @param stackBase Start address of the stack memory.
 * @param stackSizeBytes Size of the stack region in bytes.
 * @param enableOverflowGuard Enables guard word for overflow checks when true.
 *
 * @note UNUSED Size: 000070
 */
void AyuStack::create(immut char* name, int allocFlags, void* stackBase, int stackSizeBytes, bool enableOverflowGuard)
{
	mAllocType         = allocFlags;
	mIsActive          = true;
	mName              = name;
	mInitialStackTop   = (u32)stackBase;
	mInitialStackLimit = mInitialStackTop + stackSizeBytes;
	mSize              = mInitialStackLimit - mInitialStackTop;
	mProtectOverflow   = enableOverflowGuard;
	if (mProtectOverflow) {
		((u32*)mInitialStackTop)[0] = AYU_STACK_GUARD_WORD; // Guard for overflow detection.
	}

	reset();
}

/**
 * @brief Resets stack pointers to their initial positions.
 * @note UNUSED Size: 00001C
 */
void AyuStack::reset()
{
	mStackTop   = mInitialStackTop;
	mStackLimit = mInitialStackLimit;
	mTotalSize  = 0;
}

/**
 * @brief Verifies guard values to detect stack corruption.
 * @note UNUSED Size: 000024
 */
void AyuStack::checkStack()
{
	if (mAllocType & AYU_STACK_GROW_UP && mStackTop - *((u32*)mStackTop - 2) != mInitialStackTop) {
		ERROR("trashed memory stack (%s)\n", mName);
	}
}

/**
 * Resets allocations based on bit flags (upper or lower stack).
 * @param resetFlags Bitmask indicating which stack direction to reset.
 */
void AyuStack::reset(int resetFlags)
{
	if (resetFlags & AYU_STACK_GROW_UP) {
		int prev = setAllocType(resetFlags);
		gsys->invalidateObjs(mInitialStackTop, mStackTop);

		while (mStackTop != mInitialStackTop) {
			pop();
		}

		setAllocType(prev);
	}

	if (resetFlags & AYU_STACK_GROW_DOWN) {
		int prev = setAllocType(resetFlags);
		gsys->invalidateObjs(mStackLimit, mInitialStackLimit);

		while (mStackLimit != mInitialStackLimit) {
			pop();
		}

		setAllocType(prev);
	}
}

/**
 * Allocates space from the stack, growing according to alloc type.
 * @param requestedSizeBytes Number of bytes requested.
 * @return Pointer to allocated region or nullptr on overflow.
 */
void* AyuStack::push(int requestedSizeBytes)
{
	if (!requestedSizeBytes) {
		requestedSizeBytes = 1;
	}

	if (IS_NOT_ALIGNED(requestedSizeBytes, 8)) {
		requestedSizeBytes = ALIGN_NEXT(requestedSizeBytes, 8);
	}

	if (mAllocType == AYU_STACK_GROW_UP) {
		if (mStackTop + (requestedSizeBytes + 8) > mStackLimit) {
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

		mTotalSize += (requestedSizeBytes + 8);
		mStackTop += (requestedSizeBytes + 8);
		*(u32*)(mStackTop - 8) = previousSize + (requestedSizeBytes + 8);

		// > is supposed to be != but ONLY THEN does it regswap :crying:
		if ((mAllocType & AYU_STACK_GROW_UP) && (mStackTop - *(u32*)(mStackTop - 8) > mInitialStackTop)) {
			ERROR("trashed memory stack (%s)\n", mName);
		}

		return (void*)stackStart;
	} else {
		if (mStackLimit - (requestedSizeBytes + 8) < mStackTop) {
			return nullptr;
		}

		mTotalSize += (requestedSizeBytes + 8);
		mStackLimit -= (requestedSizeBytes + 8);
		*(u32*)mStackLimit = (requestedSizeBytes + 8);
		return (void*)(mStackLimit + 8);
	}
}

/**
 * Frees the most recent allocation from the stack.
 */
void AyuStack::pop()
{
	if (mAllocType == AYU_STACK_GROW_UP) {
		u32 subVal = *(u32*)(mStackTop - 8);
		mTotalSize -= subVal;
		mStackTop -= subVal;
		return;
	}

	u32 diffVal = *(u32*)mStackLimit;
	mTotalSize -= diffVal;
	mStackLimit += diffVal;
}

/**
 * Initialises an AyuHeap wrapper around a stack region.
 * @param name Heap name for debugging.
 * @param allocFlags Allocation direction flags.
 * @param stackBase Start of the heap memory.
 * @param stackSizeBytes Size of the heap region in bytes.
 */
void AyuHeap::init(immut char* name, int allocFlags, void* stackBase, int stackSizeBytes)
{
	create(name, allocFlags, stackBase, stackSizeBytes, false);
	_24 = 0;
}

/**
 * Constructs a cache of the given size, aligned to 32 bytes.
 * @param cacheSize Desired cache size in bytes.
 */
AyuCache::AyuCache(u32 cacheSize)
{
	PRINT("Creating cache of size %.2f k\n", cacheSize / 1024.0f);

	s32 alignedSize = OSRoundUp32B(cacheSize);
	u32 bufAddr     = (u32) new char[(alignedSize / 4) * 4];
	init(bufAddr, bufAddr + alignedSize);
}

/**
 * Initialises cache metadata and free lists.
 * @param bufferStart Start address of cache buffer.
 * @param bufferEnd End address of cache buffer.
 */
void AyuCache::init(u32 bufferStart, u32 bufferEnd)
{
	mTotalAllocatedUnits            = 0;
	mTotalCacheSizeBytes            = (bufferEnd - bufferStart);
	mCurrentAllocationTag           = 0;
	mAllocatedBlockHead.mNext       = &mAllocatedBlockHead;
	mAllocatedBlockHead.mPrev       = &mAllocatedBlockHead;
	mAllocatedBlockHead.mTagAndSize = 0;
	mBlockGuardValue                = AYU_CACHE_GUARD_WORD;

	u32* ptr = (u32*)bufferStart;
	ptr[1]   = (u32)this;
	ptr[2]   = (u32)this;
	ptr[0]   = ((bufferEnd - bufferStart) >> 4) - 0x1000001;
	ptr[3]   = AYU_CACHE_GUARD_WORD;

	mFreeBlockHead.mNext       = (MemHead*)bufferStart;
	mFreeBlockHead.mPrev       = (MemHead*)bufferStart;
	mFreeBlockHead.mTagAndSize = AYU_CACHE_FREE_FLAG;

	for (int i = 0; i < 256; i++) {
		mPageIndexPool[i] = i;
	}

	mNextPageSlot = 0;
}

/**
 * @brief Retrieves the next page index for allocation.
 * @note UNUSED Size: 000018
 */
int AyuCache::getIndex()
{
	return mPageIndexPool[mNextPageSlot++];
}

/**
 * @brief Attempts to release a page index back to the pool.
 * @note UNUSED Size: 000060
 */
void AyuCache::releaseIndex(int index)
{
	for (int i = 0;; i++) {
		if (i >= mNextPageSlot) {
			ERROR("Could not release the index %d\n", index);
		}

		if (mPageIndexPool[i] == index) {
			break;
		}
	}

	// UNUSED FUNCTION
}

/**
 * @brief Links a chunk into a doubly-linked list with given tag/size.
 * @note UNUSED Size: 000020
 */
void linkChunk(MemHead* node, u32 tagAndSize, MemHead* listHead)
{
	node->mNext        = listHead;
	node->mPrev        = listHead->mPrev;
	listHead->mPrev    = node;
	node->mPrev->mNext = node;
	node->mTagAndSize  = tagAndSize;
}

/**
 * Allocates a block from the cache, splitting free blocks as needed.
 * @param sizeBytes Size in bytes to allocate.
 * @return Pointer to allocated block or nullptr if none fit.
 */
void* AyuCache::mallocL(u32 sizeBytes)
{
	u32 a          = (sizeBytes + 0xF) >> 4;
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
	next->mTagAndSize = AYU_STACK_GUARD_WORD;

	return ((u32*)chunk + 4);
}

/**
 * Frees a cache block and coalesces adjacent free space.
 * @param ptr Pointer previously returned by mallocL.
 */
void AyuCache::cacheFree(void* ptr)
{
	MemHead* blockToFree = (MemHead*)((u32)ptr - 16);
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

/**
 * @brief Deletes all entries matching an id (unused stub).
 * @note UNUSED Size: 00007C
 */
void AyuCache::deleteIdAll(u32)
{
	// UNUSED FUNCTION
}

/**
 * @brief Returns amount of free cache space (unused stub).
 * @note UNUSED Size: 00002C
 */
u32 AyuCache::amountFree()
{
	// UNUSED FUNCTION
}

/**
 * Checks whether the allocated list is empty.
 */
bool AyuCache::isEmpty()
{
	return mAllocatedBlockHead.mNext == &mAllocatedBlockHead;
}

/**
 * Returns the size of the largest free block in bytes.
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
