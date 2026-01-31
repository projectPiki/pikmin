#ifndef _DOLPHIN_OS_OSSERIAL_H
#define _DOLPHIN_OS_OSSERIAL_H

#include "Dolphin/OS/OSContext.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

///////////////// SI TYPES /////////////////
// SI callback function type.
typedef void (*SICallback)(s32 chan, u32 sr, OSContext* context);
typedef void (*SITypeAndStatusCallback)(s32 chan, u32 type);

// Struct for SI information transfer (size 0x20).
typedef struct SIPacket {
	s32 chan;            // _00
	void* output;        // _04
	u32 outputBytes;     // _08
	void* input;         // _0C
	u32 inputBytes;      // _10
	SICallback callback; // _14
	OSTime fire;         // _18
} SIPacket;

// Struct for 'Si' object in SIBios.c (size 0x14).
typedef struct SIControl {
	s32 chan;            // _00
	u32 poll;            // _04
	u32 inputBytes;      // _08
	void* input;         // _0C
	SICallback callback; // _10
} SIControl;

// Struct to set and store flags (size 0x4).
typedef struct SICommFlags {
	u32 tcint : 1;
	u32 tcintmsk : 1;
	u32 comerr : 1;
	u32 rdstint : 1;
	u32 rdstintmsk : 1;
	u32 pad0 : 4;
	u32 outlngth : 7;
	u32 pad1 : 1;
	u32 inlngth : 7;
	u32 pad2 : 5;
	u32 channel : 2;
	u32 tstart : 1;
} SICommFlags;

// Union to control setting flags or overall word value (size 0x4).
typedef union SIComm {
	u32 val;
	SICommFlags flags;
} SIComm;

////////////////////////////////////////////

/////////////// SI FUNCTIONS ///////////////
BOOL SIBusy();
BOOL SIIsChanBusy(s32 chan);

BOOL SIRegisterPollingHandler(__OSInterruptHandler handler);
BOOL SIUnregisterPollingHandler(__OSInterruptHandler handler);

void SIInit(void);
u32 SIGetStatus(s32 chan);
void SISetCommand(s32 chan, u32 command);
void SITransferCommands(void);
u32 SISetXY(u32 x, u32 y);
u32 SIEnablePolling(u32 poll);
u32 SIDisablePolling(u32 poll);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
BOOL SIGetResponse(s32 chan, void* data);
#else
void SIGetResponse(s32 chan, void* data);
#endif
BOOL SITransfer(s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback, OSTime delay);
u32 SIGetType(s32 chan);
u32 SIGetTypeAsync(s32 chan, SITypeAndStatusCallback callback);
u32 SIDecodeType(u32 type);
u32 SIProbe(s32 chan);

////////////////////////////////////////////

////////// SI DEFINES ////////////
// Max settings.
#define SI_MAX_CHAN            4
#define SI_MAX_COMCSR_INLNGTH  128
#define SI_MAX_COMCSR_OUTLNGTH 128

// Serial error codes.
#define SI_ERROR_UNDER_RUN   0x0001
#define SI_ERROR_OVER_RUN    0x0002
#define SI_ERROR_COLLISION   0x0004
#define SI_ERROR_NO_RESPONSE 0x0008
#define SI_ERROR_WRST        0x0010
#define SI_ERROR_RDST        0x0020
#define SI_ERROR_UNKNOWN     0x0040
#define SI_ERROR_BUSY        0x0080

// Channels.
#define SI_CHAN0          0
#define SI_CHAN1          1
#define SI_CHAN2          2
#define SI_CHAN3          3
#define SI_CHAN0_BIT      0x80000000
#define SI_CHAN1_BIT      0x40000000
#define SI_CHAN2_BIT      0x20000000
#define SI_CHAN3_BIT      0x10000000
#define SI_CHAN_BIT(chan) (SI_CHAN0_BIT >> (chan))

// Command type and status codes.
#define SI_TYPE_MASK    0x18000000u
#define SI_TYPE_N64     0x00000000u
#define SI_TYPE_DOLPHIN 0x08000000u
#define SI_TYPE_GC      SI_TYPE_DOLPHIN

// GC-specific codes.
#define SI_GC_WIRELESS 0x80000000
#define SI_GC_NOMOTOR  0x20000000
#define SI_GC_STANDARD 0x01000000

// WaveBird codes.
#define SI_WIRELESS_RECEIVED  0x40000000
#define SI_WIRELESS_IR        0x04000000
#define SI_WIRELESS_STATE     0x02000000
#define SI_WIRELESS_ORIGIN    0x00200000
#define SI_WIRELESS_FIX_ID    0x00100000
#define SI_WIRELESS_TYPE      0x000f0000
#define SI_WIRELESS_LITE_MASK 0x000c0000
#define SI_WIRELESS_LITE      0x00040000
#define SI_WIRELESS_CONT_MASK 0x00080000
#define SI_WIRELESS_CONT      0x00000000
#define SI_WIRELESS_ID        0x00c0ff00
#define SI_WIRELESS_TYPE_ID   (SI_WIRELESS_TYPE | SI_WIRELESS_ID)

// Other controller codes.
#define SI_N64_CONTROLLER (SI_TYPE_N64 | 0x05000000)
#define SI_N64_MIC        (SI_TYPE_N64 | 0x00010000)
#define SI_N64_KEYBOARD   (SI_TYPE_N64 | 0x00020000)
#define SI_N64_MOUSE      (SI_TYPE_N64 | 0x02000000)
#define SI_GBA            (SI_TYPE_N64 | 0x00040000)
#define SI_GC_CONTROLLER  (SI_TYPE_GC | SI_GC_STANDARD)
#define SI_GC_RECEIVER    (SI_TYPE_GC | SI_GC_WIRELESS)
#define SI_GC_WAVEBIRD    (SI_TYPE_GC | SI_GC_WIRELESS | SI_GC_STANDARD | SI_WIRELESS_STATE | SI_WIRELESS_FIX_ID)
#define SI_GC_KEYBOARD    (SI_TYPE_GC | 0x00200000)
#define SI_GC_STEERING    (SI_TYPE_GC | 0x00000000)

//////////////////////////////////

END_SCOPE_EXTERN_C

#endif
