#ifndef _JAUDIO_SYNCSTREAM_H
#define _JAUDIO_SYNCSTREAM_H

#include "types.h"
#include "jaudio/dspinterface.h"

typedef struct dspch_ dspch_;
typedef struct DSPchannel_ DSPchannel_; // TODO: WHAT ARE YOU?
typedef struct StreamCtrl_ StreamCtrl_;
typedef struct BufControl_ BufControl_;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef int (*StreamCallback)(u32, s32);

void Init_StreamAudio(void);
void Get_StreamAudio_Handle(int);
void StreamAudio_Start(int, int, char*, int, int, int);
void RegisterStreamCallback(StreamCallback);
void Jac_Decode_ADPCM(void);
BOOL StreamSyncCheckReady(u32);
BOOL StreamSyncCheckReadyID(u32, u32);
BOOL StreamSyncCheckBusy(u32, u32);
int StreamSyncPlayAudio(f32, u32, int, int);
BOOL StreamSyncStopAudio(u32);
void StreamChgPitch(void);
void StreamChgVolume(u32, int, int);
void StreamChgMixLevel(u32, int, int);
void StreamGetCurrentFrame(void);
BOOL StreamSetDVDPause(u32, BOOL);
void StreamCheckRemainBuffers(void);
u8 StreamCheckAudioFormat(u32);
void StreamCheckBufferEmpty(void);
void StreamCheckBufferRemainSize(void);

struct BufControl_ {
	u8 _00;  // _00
	u8 _01;  // _01
	u8 _02;  // _02
	u8 _03;  // _03
	u32 _04; // _04
	u32 _08; // _08
	u32 _0C; // _0C
};

#define artificial_padding(currentOffset, lastOffset) u8 __##lastOffset##padding[currentOffset - lastOffset]

enum AudioFormat { AUDIOFRMT_ADPCM = 4, AUDIOFRMT_ADPCM4X = 5 };


// CONFIRMED SIZE: 0x21A50
struct StreamCtrl_ {
	u32 _00; // _00
	u32 _04; // _04
	u32 _08; // _08
	u8* _0C; // _0C
	artificial_padding(0x218C0, 0x10);
	BufControl_ buffCtrl[8]; // _218C0
	u8 _21940;               // _21940
	u8 _21941;               // _21941
	u8 _21942;               // _21942
	u8 _21943;               // _21943
	artificial_padding(0x21970, 0x21944);
	u32 _21970;
	u32 _21974;
	u32 _21978;
	u32 _2197C;
	u32 _21980;
	u32 _21984;      // _21984
	u32 _21988;      // _21988
	u32 _2198C;      // _2198C
	u16 _21990;      // _21990
	u16 audioFormat; // _21992
	artificial_padding(0x219A8, 0x21994);
	u32 _219A8;    // _219A8
	u32 _219AC;    // _219AC
	BOOL isPaused; // _219B0
	u32 _219B4;    // _219B4
	DVDFileInfo* _219B8;
	artificial_padding(0x219F4, 0x219B8);
	dspch_* dspch[2]; // _219F4
	artificial_padding(0x21A0C, 0x21A00);
	u32 _21A0C;
	u32 _21A10;
	artificial_padding(0x21A28, 0x21A14);
	DSPMixerChannel mixer; // _21A28
	f32 _21A30;            // _21A30
	u8 _21A34;             // _21A34
	u32 _21A38;            // _21A38
	u32 _21A3C;            // _21A3C
	u32 _21A40;            // _21A40
	u32 _21A44;            // _21A44
	u32 _21A48;            // _21A48
	u32 _21A4C;            // _21A4C
};

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
