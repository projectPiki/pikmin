#include "sysNew.h"

#include "DebugLog.h"
#include "MemStat.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(4)

/**
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("sysNew");

/**
 * @brief Allocate zero-initialized heap memory from currently active system heap.
 *
 * Rounds request to 4-byte alignment, updates active memory-info chain, and emits
 * diagnostics for invalid heap state or allocation failures.
 *
 * @param size Requested allocation size in bytes.
 * @return Pointer to allocated memory, or nullptr if no allocation is produced.
 */
void* System::alloc(size_t size)
{
	void* allocatedBlock = nullptr;
	if (size & 0x3) {
		size = (size + 3) & ~0x3;
	}

	if (gsys->mActiveHeapIdx >= 0) {
		AyuHeap* heap = &gsys->mHeaps[gsys->mActiveHeapIdx];
		if (size == 0) {
			PRINT("trying to allocate %d bytes on heap\n", 0);
		}
		allocatedBlock = heap->push(size);
		if (!allocatedBlock) {
			ERROR("new[] %d failed in heap '%s'", size, heap->mName);
		}

		if (size == 0 || gsys->mForcePrint) {
			bool savedTogglePrint = gsys->mTogglePrint;
			gsys->mTogglePrint = TRUE;
			gsys->mTogglePrint = savedTogglePrint;
		}

		// Propagate allocation size through nested memory-info scopes.
		MemInfo* memInfo = gsys->mCurrMemInfo;
		while (memInfo) {
			memInfo->mMemorySize += size;
			memInfo = static_cast<MemInfo*>(memInfo->mParent);
		}

		if ((u32)allocatedBlock & 0x3) {
			ERROR("acquired memory not long aligned %08x!!\n", (u32)allocatedBlock);
		}

		// Clear allocation in 32-bit chunks before handing it to callers.
		u32* allocatedWords = (u32*)allocatedBlock;
		int wordCount       = size / 4;
		for (int wordIndex = 0; wordIndex < wordCount; wordIndex++) {
			allocatedWords[wordIndex] = 0;
		}
	} else {
#if defined(WIN32)
		// The DLL uses `GlobalAlloc` here and has an ERROR if that fails.  This branch of code is probably DLL exclusive,
		// since the GCN can't just ask WinAPI for unlimited memory.  We'll see once JPN Demo version matching begins.
		if (!allocatedBlock) {
			ERROR("new[] %d failed", size);
		}
#else
		ERROR("no heap specified\n");
#endif
	}

	return allocatedBlock;
}

/**
 * @brief Allocate memory with explicit alignment for scalar `new`.
 * @param size Requested payload size in bytes.
 * @param alignment Required alignment in bytes.
 * @return Aligned pointer into over-allocated block from `System::alloc`.
 * @note UNUSED Size: 000044 (Matching by size)
 */
void* operator new(size_t size, int alignment)
{
	u32 allocationBase = (u32)System::alloc(size + alignment);
	u32 alignedAddress = (allocationBase + (alignment - 1)) & ~(alignment - 1);
	return (void*)alignedAddress;
}

/**
 * @brief Allocate memory with explicit alignment for array `new[]`.
 * @param size Requested payload size in bytes.
 * @param alignment Required alignment in bytes.
 * @return Aligned pointer into over-allocated block from `System::alloc`.
 */
void* operator new[](size_t size, int alignment)
{
	u32 allocationBase = (u32)System::alloc(size + alignment);
	u32 alignedAddress = (allocationBase + (alignment - 1)) & ~(alignment - 1);
	return (void*)alignedAddress;
}

/**
 * @brief Scalar delete overload used by this build.
 */
void operator delete(void*)
{
}

/**
 * @brief Array delete overload used by this build.
 */
void operator delete[](void*)
{
}
