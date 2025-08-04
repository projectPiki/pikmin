#ifndef _JAUDIO_AUDIOSTRUCT_H
#define _JAUDIO_AUDIOSTRUCT_H

#include "Dolphin/os.h"
#include "jaudio/bx.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

///////////////// JAUDIO STRUCTURES /////////////////
// Members and names from AC and SMS Decomp with gratitude.

typedef struct ALHeap ALHeap;
typedef struct dspch_ dspch_; // TODO: Figure out why there is another struct named `DSPChannel_` in syncstream.c.
typedef struct Jac_MessageQueue Jac_MessageQueue;
typedef struct JCMgr JCMgr;
typedef struct jc_ jc_;
typedef struct jcs_ jcs_;
typedef struct Wave_ Wave_;

typedef enum JCSTATUS {
	JCSTAT_Unk0 = 0,
	JCSTAT_Unk1 = 1,
	JCSTAT_Unk2 = 2,
	JCSTAT_Unk6 = 6,
} JCSTATUS;

/**
 * @brief Audio heap.
 *
 * @note Size: 0x14.
 */
struct ALHeap {
	u8* base;    // _00
	u8* current; // _04
	int length;  // _08
	u32 count;   // _0C
	u8* last;    // _10
};

typedef enum DSPChannelCallbackEvent {
	DSPCHCB_NormalUpdate   = 0,
	DSPCHCB_Completion     = 2,
	DSPCHCB_StateChange    = 3,
	DSPCHCB_PriorityUpdate = 4,
} DSPChannelCallbackEvent;

#define DSPCHAN_CALLBACK_FORCE_STOP (-1) // AKA call me again in 65535 frames (never)
#define DSPCHAN_CALLBACK_STOP       (0)  // AKA call me again in 0 frames (immediate stop)
#define DSPCHAN_CALLBACK_CONTINUE   (1)  // AKA call me again in 1 frame (continue processing)

typedef int /*(DSPCHAN_CALLBACK_*)*/ (*DSPChannelCallback)(dspch_*, u32 /*aka DSPChannelCallbackEvent*/);

typedef enum DSPChannelAllocState {
	DSPCHAN_Free          = 0, // Channel is available for allocation
	DSPCHAN_MonoAllocated = 1, // Channel allocated for mono playback
	DSPCHAN_StereoLeft    = 2, // Left channel of stereo pair
	DSPCHAN_StereoRight   = 3, // Right channel of stereo pair
	DSPCHAN_Stopping      = 4  // Channel is being force stopped
} DSPChannelAllocState;

/**
 * @brief DSP channel structure.
 */
struct dspch_ {
	u8 buffer_idx;                    // _00
	u8 allocState;                    // _01, uses DSPChannelAllocState
	u8 _02;                           // _02
	u8 prio;                          // _03
	u16 releaseTime;                  // _04
	u16 callbackTimer;                // _06
	jc_* logicalChan;                 // _08
	DSPChannelCallback logicalChanCb; // _0C
};

#define DSPCHAN_MAX_PRIO (0x7f)

typedef struct PanMatrix_ {
	f32 values[3];
} PanMatrix_;

/**
 * @brief TODO
 *
 * @note Size: 0x74.
 */
struct jcs_ {
	u32 chanCount;          // _00, Number of channels in this system
	u32 chanAllocCount;     // _04, Total channel allocation counter
	jc_* freeChannels;      // _08, Linked list of free channels
	jc_* activeChannels;    // _0C, Linked list of active channels
	jc_* releasingChannels; // _10, Linked list of releasing channels
	jc_* waitingChannels;   // _14, Linked list of channels waiting for DSP
	f32 volume;             // _18, Master volume (default 1.0)
	f32 pitch;              // _1C, Master pitch/cent adjustment (default 1.0)
	f32 pan;                // _20, Master pan position (default 0.5)
	f32 fxmix;              // _24, Effects mix level (default 0.0)
	f32 dolby;              // _28, Dolby surround level (default 0.0)

	s16 firCoefficients[8]; // _2C, FIR filter coefficients (8 taps)
	s16 iirCoefficients[4]; // _3C, IIR filter coefficients

	char _44[8];           // _44
	s16 distFilter;        // _4C, Distance filter parameter (default 0)
	u16 busConnect[6];     // _4E, Bus routing configuration for 6 outputs
	u8 masterLevels[6];    // _5A
	u8 maxDelay;           // _60, Maximum delay setting (default 0)
	u8 filterMode;         // _61, Filter enable flags (bit 5=IIR, bits 0-4=FIR taps)
	u8 panCalcTypes[3];    // _62, Pan calculation types (default [26,1,1])
	u32 channelPriority;   // _68
	u16 releaseTime;       // _6C, Release/fade time in samples (default 600)
	int voiceStealingMode; // _70, Voice stealing enabled (0=off, 1=on)
};

// needed to match UpdateEffecterParam
typedef union MixConfig {
	u16 whole;
	struct {
		u8 upper;
		u8 lower0 : 4;
		u8 lower1 : 4;
	} parts;
} MixConfig;

typedef BOOL (*JCUpdateCallback)(jc_*, JCSTATUS);

/**
 * @brief TODO.
 */
struct jc_ {
	u8 velocity;                        // _00
	u8 note;                            // _01
	u8 pauseFlag;                       // _02
	u8 toFlush;                         // _03
	jcs_* chanMgr;                      // _04
	void** chanListHead;                // _08
	u8 logicalChanType;                 // _0C, 0 = Wave, 1 = ??, 2 = Oscillator
	Wave_* waveData;                    // _10
	u32 chanData;                       // _14
	u32 _18;                            // _18
	u32 _1C;                            // _1C
	dspch_* dspChannel;                 // _20
	void* nextChan;                     // _24, this is jcs_
	JCUpdateCallback updateCallback;    // _28
	JCUpdateCallback pitchSweepUpdater; // _2C
	s32 noteId;                         // _30
	s32 lastNotePlayed;                 // _34
	struct Osc_* mOscillators[4];       // _38
	struct Oscbuf_ mOscBuffers[2];      // _48
	f32 _78;                            // _78
	char _7C[8];                        // _7C
	f32 _84;                            // _84
	char _88[4];                        // _88
	f32 _8C;                            // _8C
	f32 _90;                            // _90
	f32 _94;                            // _94
	u16 _98;                            // _98
	u16 _9A;                            // _9A
	void* _9C;                          // _9C
	char _A0[8];                        // _A0
	f32 basePitch;                      // _A8
	f32 baseVolume;                     // _AC
	f32 currentPitch;                   // _B0
	f32 currentVolume;                  // _B4
	u8 panCalcTypes[3];                 // _B8
	PanMatrix_ panMatrices[4];          // _BC, 0 = Power distribution, 1 = Pan, 2 = Effects send (fxmix), 3 = Dolby surround
	f32 pitchModifier;                  // _EC
	f32 volumeModifier;                 // _F0
	f32 targetPitch;                    // _F4
	u16 finalPitch;                     // _F8
	u16 pitchSweepSteps;                // _FA
	jcs_* lastManager;                  // _FC
	f32 managerPitch;                   // _100
	f32 managerVolume;                  // _104
	MixConfig busRouting[6];            // _108
	u16 mixerLevels[6];                 // _114
	u32 channelPriority;                // _120
	u16 releaseTime;                    // _124
	u16 channelId;                      // _126
	int soundId;                        // _128
	u8 polyphonyCounter;                // _12C
	char _12D[3];                       // _12D
	int _130;                           // _130
	int _134;                           // _134
	int _138;                           // _138
	int _13C;                           // _13C
};

/////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
