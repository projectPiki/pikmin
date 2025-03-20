#ifndef _JAUDIO_SYNCSTREAM_H
#define _JAUDIO_SYNCSTREAM_H

#include "types.h"

typedef struct dspch_ dspch_;
typedef struct DSPchannel_ DSPchannel_;
typedef struct StreamCtrl_ StreamCtrl_;
typedef struct BufControl_ BufControl_;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Stop_DirectPCM(dspch_*);
void Play_DirectPCM(dspch_*, s16*, u16, u32);
void Get_DirectPCM_LoopRemain(DSPchannel_*);
void Get_DirectPCM_Counter(DSPchannel_*);
void Get_DirectPCM_Remain(DSPchannel_*);
void Init_StreamAudio(void);
void Get_StreamAudio_Handle(void);
void StreamAudio_Start(void);
void RegisterStreamCallback(void);
void Jac_Decode_ADPCM(void);
void StreamSyncCheckReady(void);
void StreamSyncCheckReadyID(void);
BOOL StreamSyncCheckBusy(unknown, unknown);
void StreamSyncPlayAudio(void);
void StreamSyncStopAudio(void);
void StreamChgPitch(void);
void StreamChgVolume(void);
void StreamChgMixLevel(void);
void StreamGetCurrentFrame(void);
void StreamSetDVDPause(unknown, unknown);
void StreamCheckRemainBuffers(void);
void StreamCheckAudioFormat(void);
void StreamCheckBufferEmpty(void);
void StreamCheckBufferRemainSize(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
