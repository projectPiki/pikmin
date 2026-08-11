#include "sysNew.h"

#include "DebugLog.h"
#include "MemStat.h"

#if defined(WIN32)
#include <windows.h>
#endif

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(4)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("sysNew");

/**
 * In the DOL, `operator new` is an inline function found in "sysNew.h".  In the DLL, `System::alloc`
 * does not exist.  In the original codebase, these functions existed in different translation units.
 * WIN32 compiled "sysCore/sysNew.cpp", and GCN compiled "sysDolphin/sysNew.cpp".  That's not very DRY,
 * so we implement both functions in one place since they have significant overlap that can inform us.
 */
#if defined(WIN32)
void* operator new(size_t size)
#else
void* System::alloc(size_t size)
#endif
{
	void* result = nullptr;

	// Padding the size for the zeroing loop is unnecessary on Windows
#if defined(WIN32)
#else
	if (size & 3) {
		size = (size + 3) & ~3;
	}
#endif

	if (gsys->mActiveHeapIdx >= 0) {
		AyuHeap& heap = gsys->mHeaps[gsys->mActiveHeapIdx];

		if (size == 0) {
			PRINT("trying to allocate %d bytes on heap\n", size);
		}

		result = heap.push(size);
		if (!result) {
			ERROR("new[] %d failed in heap '%s'", size, heap.mName);
		}

		// This whole section is absent on Windows
#if defined(WIN32)
#else
		if (size == 0 || gsys->mToggleHeapAllocPrint) {
			bool print         = gsys->mTogglePrint;
			gsys->mTogglePrint = TRUE;
			// It's pretty clear there's supposed to be a print here, but it's unknown what it said.
			gsys->mTogglePrint = print;
		}

		MemInfo* info = gsys->mCurrMemInfo;
		while (info) {
			info->mMemorySize += size;
			info = static_cast<MemInfo*>(info->mParent);
		}

		if (reinterpret_cast<u32>(result) & 3) {
			ERROR("acquired memory not long aligned %08x!!\n", reinterpret_cast<u32>(result));
		}
#endif

		// GCN has an optimized memory zeroing loop
#if defined(WIN32)
		char* bytes = static_cast<char*>(result);
		for (int i = 0; i < static_cast<int>(size); ++i) {
			bytes[i] = 0;
		}
#else
		u32* longs = static_cast<u32*>(result);
		for (int i = 0; i < static_cast<int>(size / 4); i++) {
			longs[i] = 0;
		}
#endif
	} else {
#if defined(WIN32)
		result = GlobalAlloc(0, size);
		if (!result) {
			ERROR("new[] %d failed", size);
		}
#else
		ERROR("no heap specified\n");
#endif
	}

	return result;
}

#if defined(WIN32)

/**
 * @brief This entire function is identical to `operator new`.
 */
void* operator new[](size_t size)
{
	void* result = nullptr;

	// Padding the size for the zeroing loop is unnecessary on Windows
#if defined(WIN32)
#else
	if (size & 3) {
		size = (size + 3) & ~3;
	}
#endif

	if (gsys->mActiveHeapIdx >= 0) {
		AyuHeap& heap = gsys->mHeaps[gsys->mActiveHeapIdx];

		if (size == 0) {
			PRINT("trying to allocate %d bytes on heap\n", size);
		}

		result = heap.push(size);
		if (!result) {
			ERROR("new[] %d failed in heap '%s'", size, heap.mName);
		}

		// This whole section is absent on Windows
#if defined(WIN32)
#else
		if (size == 0 || gsys->mToggleHeapAllocPrint) {
			bool print         = gsys->mTogglePrint;
			gsys->mTogglePrint = TRUE;
			// It's pretty clear there's supposed to be a print here, but it's unknown what it said.
			gsys->mTogglePrint = print;
		}

		MemInfo* info = gsys->mCurrMemInfo;
		while (info) {
			info->mMemorySize += size;
			info = static_cast<MemInfo*>(info->mParent);
		}

		if (reinterpret_cast<u32>(result) & 3) {
			ERROR("acquired memory not long aligned %08x!!\n", reinterpret_cast<u32>(result));
		}
#endif

		// GCN has an optimized memory zeroing loop
#if defined(WIN32)
		char* bytes = static_cast<char*>(result);
		for (int i = 0; i < static_cast<int>(size); ++i) {
			bytes[i] = 0;
		}
#else
		u32* longs = static_cast<u32*>(result);
		for (int i = 0; i < static_cast<int>(size / 4); i++) {
			longs[i] = 0;
		}
#endif
	} else {
#if defined(WIN32)
		result = GlobalAlloc(0, size);
		if (!result) {
			ERROR("new[] %d failed", size);
		}
#else
		ERROR("no heap specified\n");
#endif
	}

	return result;
}

#endif

/**
 * @todo Documentation
 * @note UNUSED Size: 000044 (Matching by size)
 */
void* operator new(size_t size, int alignment)
{
	u32 intptr;

	void* ptr = operator new(size + alignment);
	intptr    = reinterpret_cast<u32>(ptr);

	// This minor discrepancy might be explained by this code originally living in two different TUs.
#if defined(WIN32)
	intptr = ALIGN_NEXT(intptr, alignment);
	return reinterpret_cast<void*>(intptr);
#else
	return reinterpret_cast<void*>(ALIGN_NEXT(intptr, alignment));
#endif
}

/**
 * @brief This entire function is identical to aligned `operator new`.
 */
void* operator new[](size_t size, int alignment)
{
	u32 intptr;

	void* ptr = operator new[](size + alignment);
	intptr    = reinterpret_cast<u32>(ptr);

	// This minor discrepancy might be explained by this code originally living in two different TUs.
#if defined(WIN32)
	intptr = ALIGN_NEXT(intptr, alignment);
	return reinterpret_cast<void*>(intptr);
#else
	return reinterpret_cast<void*>(ALIGN_NEXT(intptr, alignment));
#endif
}

/**
 * @todo: Documentation
 */
void operator delete(void* ptr)
{
#if defined(WIN32)
	if (gsys->mActiveHeapIdx >= 0) {
		return;
	}
	GlobalFree(ptr);
#endif
}

/**
 * @brief This entire function is identical to `operator delete`.
 */
void operator delete[](void* ptr)
{
#if defined(WIN32)
	if (gsys->mActiveHeapIdx >= 0) {
		return;
	}
	GlobalFree(ptr);
#endif
}
