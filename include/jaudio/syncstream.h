#ifndef _JAUDIO_SYNCSTREAM_H
#define _JAUDIO_SYNCSTREAM_H

#include "jaudio/dspinterface.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

typedef struct dspch_ dspch_;
typedef struct DSPchannel_ DSPchannel_;
typedef struct StreamCtrl_ StreamCtrl_;
typedef struct StreamHeader_ StreamHeader_;
typedef struct BufControl_ BufControl_;

typedef int (*StreamCallback)(u32, s32);

void Init_StreamAudio(void);
void Get_StreamAudio_Handle(int);
BOOL StreamAudio_Start(u32, int, immut char*, int, int, StreamHeader_*);
void RegisterStreamCallback(StreamCallback);
void Jac_Decode_ADPCM(u8*, s16*, s16*, u32, u8, s16*);
BOOL StreamSyncCheckReady(u32);
BOOL StreamSyncCheckReadyID(u32, u32);
BOOL StreamSyncCheckBusy(u32, u32);
int StreamSyncPlayAudio(f32, u32, int, int);
BOOL StreamSyncStopAudio(u32);
void StreamChgPitch(void);
void StreamChgVolume(u32, int, int);
void StreamChgMixLevel(u32, int, int);
int StreamGetCurrentFrame(u32, u32);
BOOL StreamSetDVDPause(u32, BOOL);
void StreamCheckRemainBuffers(void);
u8 StreamCheckAudioFormat(u32);
void StreamCheckBufferEmpty(void);
void StreamCheckBufferRemainSize(void);

struct BufControl_ {
	u8 state;         // _00
	u8 maxBufCount;   // _01
	u8 currentBufIdx; // _02
	u8 activeBufIdx;  // _03
	u32 usedSize;     // _04
	u32 pos;          // _08
	u32 mLength;      // _0C
};

enum AudioFormat {
	AUDIOFRMT_16BIT_PCM = 2, // Uncompressed 16-bit PCM audio
	AUDIOFRMT_8BIT_PCM  = 3, // Uncompressed 8-bit PCM audio
	AUDIOFRMT_ADPCM     = 4, // ADPCM compressed audio
	AUDIOFRMT_ADPCM4X   = 5, // 4x compressed ADPCM variant
};

// size 0x20
struct StreamHeader_ {
	u32 fileSize;    // _00
	u32 sampleCount; // _04
	u16 sampleRate;  // _08
	u16 audioFormat; // _0A
	u16 _0C;         // _0C, unused
	u16 frameRate;   // _0E
	u32 _10[4];      // _10, unused
};

// size 0x2420
union UNION_0x2420 {
	StreamHeader_ header; // _00
	u8 data[0x2420];      // _20
};

// CONFIRMED SIZE: 0x21A50
struct StreamCtrl_ {
	union UNION_0x2420 data[6];   // _00
	s16 leftChanBufs[2][0x2000];  // _0D8C0
	s16 rightChanBufs[2][0x2000]; // _158C0
	s16 loopBufs[2][0x1000];      // _1D8C0, PCM data?
	BufControl_ buffCtrl[6];      // _218C0
	BufControl_ buffCtrlExtra[2]; // _21920
	BufControl_ buffCtrlMain;     // _21940
	BufControl_ buffCtrlMain2;    // _21950
	BufControl_ buffCtrlMain3;    // _21960
	u32 remainingBytes;           // _21970
	u32 bytesRead;                // _21974
	u32 chunkSize;                // _21978
	u32 lastLoadSize;             // _2197C
	u32 samplesDecoded;           // _21980
	u32 playbackState;            // _21984
	StreamHeader_ header;         // _21988
	s32 autoStart;                // _219A8
	s32 stopRequested;            // _219AC
	BOOL isPaused;                // _219B0
	s32 isAtEnd;                  // _219B4
	DVDFileInfo fileinfo;         // _219B8
	dspch_* dspch[2];             // _219F4
	u32 totalSamples;             // _219FC
	u32 loopSize;                 // _21A00
	u32 _21A04;                   // _21A04
	u32 frameCounter;             // _21A08
	u32 controllerId;             // _21A0C
	u32 streamId;                 // _21A10
	StreamCallback syncCallback;  // _21A14
	s16 leftAdpcmState[4];        // _21A18
	s16 rightAdpcmState[4];       // _21A20
	u16 volume[2];                // _21A28
	u16 mixLevel[2];              // _21A28
	f32 pitchRatio;               // _21A30
	u8 isFromFile;                // _21A34
	u32 updateFlags;              // _21A38
	u32 _21A3C;                   // _21A3C
	u32 samplesLoaded;            // _21A40
	s32 isBufferingComplete;      // _21A44
	s32 isLoadInProgress;         // _21A48
	s32 bufferMargin;             // _21A4C
};

END_SCOPE_EXTERN_C

#endif
