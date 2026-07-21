#ifndef _JAUDIO_NOTEON_H
#define _JAUDIO_NOTEON_H

#include "types.h"

typedef struct seqp_ seqp_;

s32 NoteON(seqp_* track, s32 channel, s32 key, s32 velocity, s32 playId);
s32 NoteOFF_R(seqp_* track, u8 channelIndex, u16 releaseFrames);
s32 NoteOFF(seqp_* track, u8 channelIndex);
s32 GateON(seqp_* track, s32 channelId, s32 key, s32 velocity, s32 playId);
void ProgramChange(s32 chan);
BOOL CheckNoteStop(seqp_* track, s32 channelIndex);

#endif
