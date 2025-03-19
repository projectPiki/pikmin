#ifndef _JAUDIO_WAVEREAD_H
#define _JAUDIO_WAVEREAD_H

#include "types.h"

void Wave_Test(u8*);
void GetSound_Test(u32);
void Wavegroup_Regist(void*, u32);
void Wavegroup_Init();
void WaveidToWavegroup(u32, u32);
void WaveScene_Set(u32, u32);
void WaveScene_Load(u32, u32);
void WaveScene_Close(u32, u32);
void WaveScene_Erase(u32, u32);

#endif
