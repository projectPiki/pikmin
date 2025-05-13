#ifndef _JAUDIO_HEAPCTRL_H
#define _JAUDIO_HEAPCTRL_H

#include "types.h"

typedef struct jaheap_ jaheap_;

struct jaheap_ {
	// TODO: Members
};

void Jac_GetUnlockHeap(jaheap_*);
void Jac_CheckAlloc(jaheap_*);
void Jac_InitHeap(jaheap_*);
void Jac_SelfInitHeap(jaheap_*, u32, u32, u32);
void Jac_SelfAllocHeap(jaheap_*, jaheap_*, u32, u32);
void Jac_SetGroupHeap(jaheap_*, jaheap_*);
void Jac_CutdownHeap(jaheap_*);
void Jac_InitMotherHeap(jaheap_*, u32, u32, u8);
void Jac_AllocHeap(jaheap_*, jaheap_*, u32);
void Jac_DeleteHeap(jaheap_*);
void Jac_GarbageCollection_St(jaheap_*);
void Jac_CheckFreeHeap_Total(jaheap_*);
void Jac_CheckFreeHeap_Linear(jaheap_*);
void Jac_ShowHeap(jaheap_*, u32);

#endif
