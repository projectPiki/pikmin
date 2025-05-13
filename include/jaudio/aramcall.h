#ifndef _JAUDIO_ARAMCALL_H
#define _JAUDIO_ARAMCALL_H

#include "types.h"

typedef struct jaheap_ jaheap_;

void Jac_RegisterARAMCallback(u32 (*)(char*, u32, u32, u32*, jaheap_*));
void LoadAram(char*, u32*, u32);
void LoadAramSingle(char*, u32, u32, u32*, u32);
void Jac_WaveDirectorySet(char*);
void Get_AramMotherHeap();
void Show_AramMotherHeap();
void Collect_AramMotherHeap();
void Init_AramMotherHeap();
void LoadAram_Default(char*, u32, u32, u32*, jaheap_*);
void LoadAram_All(char*, u32*, jaheap_*);
void LoadAram_One(char*, u32, u32, u32*, jaheap_*);

#endif
