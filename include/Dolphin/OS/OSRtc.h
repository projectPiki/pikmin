#ifndef _DOLPHIN_OS_OSRTC_H
#define _DOLPHIN_OS_OSRTC_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

// RTC defines.
#define RTC_CMD_READ  0x20000000
#define RTC_CMD_WRITE 0xA0000000

#define RTC_SRAM_ADDR 0x00000100
#define RTC_SRAM_SIZE 64

#define RTC_CHAN 0
#define RTC_DEV  1
#define RTC_FREQ 3

// Sram function type.
typedef void (*SramCallback)(void);

// Struct for static RAM (size 0x14).
typedef struct OSSram {
	u16 checkSum;      // _00
	u16 checkSumInv;   // _02
	u32 ead0;          // _04
	u32 ead1;          // _08
	u32 counterBias;   // _0C
	s8 displayOffsetH; // _10
	u8 ntd;            // _11
	u8 language;       // _12
	u8 flags;          // _13
} OSSram;

// Struct for expanded/external static RAM (size 0x2C).
typedef struct OSSramEx {
	u8 flashID[2][12];      // _00
	u32 wirelessKeyboardID; // _18
	u16 wirelessPadID[4];   // _1C
	u8 dvdErrorCode;        // _24
	u8 reserved_25;         // _25
	u8 flashIDCheckSum[2];  // _26
	u16 gbs;                // _28
	u8 reserved_2A[2];      // _2A
} OSSramEx;

// Struct for controlling static RAM (for OSRtc.c).
typedef struct SramControlBlock {
	u8 sram[0x40];         // _00
	u32 offset;            // _40
	BOOL enabled;          // _44
	BOOL locked;           // _48
	BOOL sync;             // _4C
	SramCallback callback; // _50
} SramControlBlock;

// SRAM functions.
void __OSInitSram();
OSSram* __OSLockSram();
OSSramEx* __OSLockSramEx();
BOOL __OSUnlockSram(BOOL commit);
BOOL __OSUnlockSramEx(BOOL commit);
BOOL __OSSyncSram(void);

#define OS_SOUND_MODE_MONO   0u
#define OS_SOUND_MODE_STEREO 1u

u32 OSGetSoundMode();
void OSSetSoundMode(u32 mode);

#define OS_PROGRESSIVE_MODE_OFF 0u
#define OS_PROGRESSIVE_MODE_ON  1u

u32 OSGetProgressiveMode();
void OSSetProgressiveMode(u32 on);

#define OS_LANG_ENGLISH 0u
#define OS_LANG_GERMAN  1u
#define OS_LANG_FRENCH  2u
#define OS_LANG_SPANISH 3u
#define OS_LANG_ITALIAN 4u
#define OS_LANG_DUTCH   5u

u8 OSGetLanguage();
void OSSetLanguage(u8 language);

#define OS_EURGB60_OFF 0u
#define OS_EURGB60_ON  1u

u32 OSGetEuRgb60Mode();
void OSSetEuRgb60Mode(u32 on);

void OSSetWirelessID(s32 channel, u16 id);
u16 OSGetWirelessID(s32 channel);

END_SCOPE_EXTERN_C

#endif
