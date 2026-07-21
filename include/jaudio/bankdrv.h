#ifndef _JAUDIO_BANKDRV_H
#define _JAUDIO_BANKDRV_H

#include "types.h"

typedef struct Bank_ Bank_;
typedef struct Inst_ Inst_;
typedef struct Perc_ Perc_;
typedef struct Voice_ Voice_;
typedef struct Sense_ Sense_;
typedef struct Rand_ Rand_;
typedef struct Osc_ Osc_;
typedef struct Oscbuf_ Oscbuf_;
typedef struct Vmap_ Vmap_;

Inst_* Bank_InstChange(Bank_* bank, u32 index);
Voice_* Bank_VoiceChange(Bank_* bank, u32 index);
Perc_* Bank_PercChange(Bank_* bank, u32 index);
int Bank_GetInstKeymap(Inst_* inst, u8 key);
int Bank_GetInstVmap(Inst_* inst, u8 key, u8 velocity);
Vmap_* Bank_GetPercVmap(Perc_* perc, u8 keyIdx, u8 vel);
int Bank_GetVoiceMap(Voice_* voice, u16 id);
f32 Bank_SenseToOfs(Sense_* sensor, u8 inputValue);
f32 Bank_RandToOfs(Rand_* rand);
f32 Bank_OscToOfs(Osc_* osc, Oscbuf_* oscBuf);

#endif
