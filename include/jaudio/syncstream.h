#ifndef _JAUDIO_SYNCSTREAM_H
#define _JAUDIO_SYNCSTREAM_H

#include "types.h"

typedef struct dspch_ dspch_;
typedef struct DSPchannel_ DSPchannel_; // TODO: WHAT ARE YOU?
typedef struct StreamCtrl_ StreamCtrl_;
typedef struct BufControl_ BufControl_;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Init_StreamAudio(void);
void Get_StreamAudio_Handle(void);
void StreamAudio_Start(int, int, char*, int, int, int);
void RegisterStreamCallback(int (*)(u32, s32));
void Jac_Decode_ADPCM(void);
void StreamSyncCheckReady(void);
int StreamSyncCheckReadyID(int, int);
BOOL StreamSyncCheckBusy(u32, u32);
int StreamSyncPlayAudio(f32, int, int, int);
void StreamSyncStopAudio(int);
void StreamChgPitch(void);
void StreamChgVolume(int, int, int);
void StreamChgMixLevel(int, int, int);
void StreamGetCurrentFrame(void);
void StreamSetDVDPause(u32, u32);
void StreamCheckRemainBuffers(void);
int StreamCheckAudioFormat(int);
void StreamCheckBufferEmpty(void);
void StreamCheckBufferRemainSize(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
