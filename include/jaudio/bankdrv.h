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

void Bank_InstChange(Bank_*, u32);
void Bank_VoiceChange(Bank_*, u32);
void Bank_PercChange(Bank_*, u32);
void Bank_GetInstKeymap(Inst_*, u8);
void Bank_GetInstVmap(Inst_*, u8, u8);
void Bank_GetPercVmap(Perc_*, u8, u8);
void Bank_GetVoiceMap(Voice_*, u16);
void Bank_SenseToOfs(Sense_*, u8);
void Bank_RandToOfs(Rand_*);
void Bank_OscToOfs(Osc_*, Oscbuf_*);

#endif
