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
BOOL StreamAudio_Start(u32, int, char*, int, int, u32);
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

// size 0x2420
struct STRUCT_0x2420 {
	u32 _00;
	artificial_padding(0x241C, 0x00);
};

// CONFIRMED SIZE: 0x21A50
struct StreamCtrl_ {
	struct STRUCT_0x2420 _00[6];
	artificial_padding(0x218C0, 0xD8C0);
	BufControl_ buffCtrl[6];      // _218C0
	BufControl_ buffCtrlExtra[2]; // _21920
	BufControl_ buffCtrlMain;     // _21940
	BufControl_ buffCtrlMain2;    // _21950
	BufControl_ buffCtrlMain3;    // _21960
	u32 _21970;                   // _21970
	u32 _21974;                   // _21974
	u32 _21978;                   // _21978
	u32 _2197C;                   // _2197C
	u32 _21980;                   // _21980
	u32 _21984;                   // _21984
	u32 _21988;                   // _21988
	u32 _2198C;                   // _2198C
	u16 _21990;                   // _21990
	u16 audioFormat;              // _21992
	u16 _21994;                   // _21994
	u16 _21996;
	u16 _21998;
	artificial_padding(0x219A8, 0x2199C);
	u32 _219A8;            // _219A8
	u32 _219AC;            // _219AC
	BOOL isPaused;         // _219B0
	u32 _219B4;            // _219B4
	DVDFileInfo fileinfo;  // _219B8
	dspch_* dspch[2];      // _219F4
	u32 _219FC;            // _219FC
	u32 _21A00;            // _21A00
	u32 _21A04;            // _21A04
	u32 _21A08;            // _21A08
	u32 _21A0C;            // _21A0C
	u32 _21A10;            // _21A10
	StreamCallback _21A14; // _21A14
	artificial_padding(0x21A28, 0x21A18);
	DSPMixerChannel mixer; // _21A28
	f32 _21A30;            // _21A30
	u8 _21A34;             // _21A34
	u32 _21A38;            // _21A38
	u32 _21A3C;            // _21A3C
	u32 _21A40;            // _21A40
	s32 _21A44;            // _21A44
	s32 _21A48;            // _21A48
	s32 _21A4C;            // _21A4C
};

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
