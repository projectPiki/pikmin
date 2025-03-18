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
void StreamAudio_Start(void);
void RegisterStreamCallback(void);
void Jac_Decode_ADPCM(void);
void StreamSyncCheckReady(void);
void StreamSyncCheckReadyID(void);
BOOL StreamSyncCheckBusy(u32, u32);
void StreamSyncPlayAudio(void);
void StreamSyncStopAudio(void);
void StreamChgPitch(void);
void StreamChgVolume(void);
void StreamChgMixLevel(void);
void StreamGetCurrentFrame(void);
void StreamSetDVDPause(u32, u32);
void StreamCheckRemainBuffers(void);
void StreamCheckAudioFormat(void);
void StreamCheckBufferEmpty(void);
void StreamCheckBufferRemainSize(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
