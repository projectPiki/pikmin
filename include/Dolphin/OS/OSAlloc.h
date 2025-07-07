#ifndef _DOLPHIN_OS_OSALLOC_H
#define _DOLPHIN_OS_OSALLOC_H

#include "Dolphin/OS/OSUtil.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

/////////// HEAP TYPES ///////////
// Useful typedef for heap locations.
typedef int OSHeapHandle;

// Alloc visitor function type.
typedef void (*OSAllocVisitor)(void* obj, u32 size);

// Current heap.
extern volatile OSHeapHandle __OSCurrHeap;

//////////////////////////////////

///////// HEAP FUNCTIONS /////////
// Heap functions.
void* OSInitAlloc(void* arenaStart, void* arenaEnd, int maxHeaps);
OSHeapHandle OSCreateHeap(void* start, void* end);
OSHeapHandle OSSetCurrentHeap(OSHeapHandle heap);
void OSFreeToHeap(OSHeapHandle heap, void* ptr);
void* OSAllocFromHeap(OSHeapHandle heap, u32 size);

//////////////////////////////////

////////// HEAP MACROS ///////////
// Returns ptr to allocated space (32-aligned).
#define OSAlloc(size) OSAllocFromHeap(__OSCurrHeap, (size))

// Deallocates 'ptr' to current heap.
#define OSFree(ptr) OSFreeToHeap(__OSCurrHeap, (ptr))

//////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
