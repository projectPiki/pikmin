#ifndef _JAUDIO_AUDIOTHREAD_H
#define _JAUDIO_AUDIOTHREAD_H

#include "Dolphin/OS/OSMessage.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

/////////// JAUDIO AUDIO THREAD DEFINITIONS ///////////
// Defines.
#define AUDIO_THREAD_FLAG_DVD   (1 << 0)
#define AUDIO_THREAD_FLAG_AUDIO (1 << 1)
#define AUDIO_THREAD_FLAG_NEOS  (1 << 2)

#define AUDIO_STACK_SIZE       0x1000
#define AUDIOPROC_MQ_BUF_COUNT 16

#define AUDIOPROC_MESSAGE_UPDATE_DAC ((OSMessage)0)
#define AUDIOPROC_MESSAGE_DSP_SYNC   ((OSMessage)1)
#define AUDIOPROC_MESSAGE_NEOS_SYNC  ((OSMessage)2)
#define AUDIOPROC_MESSAGE_3          ((OSMessage)3)

///////////////////////////////////////////////////////

//////////// JAUDIO AUDIO THREAD FUNCTIONS ////////////
void DspSyncCountClear(int count);
int DspSyncCountCheck();
void StopAudioThread();
void StartAudioThread(void* heap, s32 heapSize, u32 aramSize, u32 flags);

static void OSInitFastCast(); // idk why this is in here tbh, but it needs to be.

///////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
