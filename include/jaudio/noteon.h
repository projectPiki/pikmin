#ifndef _JAUDIO_NOTEON_H
#define _JAUDIO_NOTEON_H

#include "jaudio/jammain_2.h"

#include "types.h"

void NoteON(seqp_*, s32, s32, s32, s32);
void NoteOFF_R(seqp_*, u8, u16);
void NoteOFF(seqp_*, u8);
void GateON(seqp_*, s32, s32, s32, s32);
void ProgramChange(s32);
BOOL CheckNoteStop(seqp_*, s32);

#endif
