#ifndef _JAUDIO_HEAPCTRL_H
#define _JAUDIO_HEAPCTRL_H

#include "types.h"

typedef struct jaheap_ jaheap_;

struct jaheap_ {
	u8 _00;       // _00
	u8 _01;       // _01
	u16 _02;      // _02
	u32 _04;      // _04
	u32 _08;      // _08 (sign confirmed)
	u32 _0C;      // _0C
	u32 _10;      // _10 (related to totalSize?)
	jaheap_* _14; // _14
	jaheap_* _18; // _18
	jaheap_* _1C; // _1C
	jaheap_* _20; // _20 (100% sure Jac_SetGroupHeap)
	jaheap_* _24; // _24 (100% sure Jac_SetGroupHeap)
	jaheap_* _28; // _28 (100% sure Jac_SetGroupHeap)
};

void Jac_GetUnlockHeap(jaheap_*);
void Jac_CheckAlloc(jaheap_*);
void Jac_InitHeap(jaheap_*);
void Jac_SelfInitHeap(jaheap_*, u32, u32, u32);
void Jac_SelfAllocHeap(jaheap_*, jaheap_*, u32, u32);
BOOL Jac_SetGroupHeap(jaheap_*, jaheap_*);
void Jac_CutdownHeap(jaheap_*);
void Jac_InitMotherHeap(jaheap_*, u32, u32, u8);
void Jac_AllocHeap(jaheap_*, jaheap_*, u32);
void Jac_DeleteHeap(jaheap_*);
void Jac_GarbageCollection_St(jaheap_*);
void Jac_CheckFreeHeap_Total(jaheap_*);
void Jac_CheckFreeHeap_Linear(jaheap_*);
void Jac_ShowHeap(jaheap_*, u32);

#endif
