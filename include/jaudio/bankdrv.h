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

Inst_* Bank_InstChange(Bank_*, u32);
Voice_* Bank_VoiceChange(Bank_*, u32);
Perc_* Bank_PercChange(Bank_*, u32);
int Bank_GetInstKeymap(Inst_*, u8);
int Bank_GetInstVmap(Inst_*, u8, u8);
int Bank_GetPercVmap(Perc_*, u8, u8);
int Bank_GetVoiceMap(Voice_*, u16);
int Bank_SenseToOfs(Sense_*, u8);
f32 Bank_RandToOfs(Rand_* rand);
int Bank_OscToOfs(Osc_*, Oscbuf_*);

#endif
