#include "Dolphin/pad.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include "Dolphin/si.h"
#include "Dolphin/vi.h"
#include <stddef.h>
#include <string.h>

// For ease of implementing multiple revisions, static variables that were renamed go by their final
// names everywhere in this file and are silently renamed for older revisions via the below macros.
#if OS_BUILD_VERSION >= 20011002L
#else
#define CmdTypeAndStatus cmdTypeAndStatus // This one was renamed only to go unused, lol.
#define CmdReadOrigin    cmdReadOrigin
#define CmdCalibrate     cmdCalibrate
#define CmdProbeDevice   cmdProbeDevice
#define CmdFixDevice     cmdFixDevice // This one wasn't renamed, but now it's the odd one out.
#endif

#define RES_WIRELESS_LITE 0x40000

typedef void (*MakeStatusCallback)(s32, PADStatus*, u32*);

static void PADResetCallback(s32 unused, u32 error, OSContext* context);
static void PADTypeAndStatusCallback(s32 chan, u32 type);
#if OS_BUILD_VERSION >= 20011002L
static void PADReceiveCheckCallback(s32 chan, u32 type);
#else
static void PADReceiveCheckCallback(s32 chan, u32 error, OSContext* arg2);
#endif
static void SPEC0_MakeStatus(s32 chan, PADStatus* status, u32 data[2]);
static void SPEC1_MakeStatus(s32 chan, PADStatus* status, u32 data[2]);
static void SPEC2_MakeStatus(s32 chan, PADStatus* status, u32 data[2]);
static BOOL OnReset(BOOL f);

extern u16 __OSWirelessPadFixMode AT_ADDRESS(OS_BASE_CACHED | 0x30E0);
extern u8 GameChoice AT_ADDRESS(OS_BASE_CACHED | 0x30E3);

static BOOL Initialized = FALSE;

static u32 EnabledBits   = 0x00000000;
static u32 ResettingBits = 0x00000000;
#if OS_BUILD_VERSION >= 20011002L
#else
static u32 ProbingBits = 0x00000000;
#endif
static u32 RecalibrateBits = 0x00000000;
static u32 WaitingBits     = 0x00000000;
static u32 CheckingBits    = 0x00000000;
#if OS_BUILD_VERSION >= 20011002L
static u32 PendingBits = 0x00000000;
#endif

#if OS_BUILD_VERSION >= 20011002L
#else
static u32 PADType[PAD_MAX_CONTROLLERS];
#endif
static u32 Type[PAD_MAX_CONTROLLERS];
static PADStatus Origin[PAD_MAX_CONTROLLERS];

static s32 ResettingChan             = 0x00000020;
static u32 XPatchBits                = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT;
static u32 AnalogMode                = 0x00000300;
static u32 Spec                      = 0x00000005;
static MakeStatusCallback MakeStatus = SPEC2_MakeStatus;
#if OS_BUILD_VERSION >= 20011002L && OS_BUILD_VERSION < 20011217L
static u32 SamplingRate = 0; // This was moved to SISamplingRate.c
#endif
#if OS_BUILD_VERSION >= 20011002L
static PADSamplingCallback SamplingCallback = NULL;
#endif

static u32 CmdReadOrigin    = 0x41000000;
static u32 CmdCalibrate     = 0x42000000;
static u32 CmdTypeAndStatus = 0x00000000;
static u32 CmdProbeDevice[PAD_MAX_CONTROLLERS];
#if OS_BUILD_VERSION >= 20011002L
#else
static u32 CmdFixDevice[PAD_MAX_CONTROLLERS];
#endif

static OSResetFunctionInfo ResetFunctionInfo = {
	OnReset,
	127,
	NULL,
	NULL,
};

#if OS_BUILD_VERSION >= 20011002L
extern u32 __PADFixBits; // This was moved to SIBios.c
#else
u32 __PADFixBits;
#endif
u32 __PADSpec;

// TODO: This struct changed / moved a lot.
typedef struct XY {
#if OS_BUILD_VERSION >= 20011002L
	u16 line;
#else
	u8 line;
#endif
	u8 count;
} XY;

#if OS_BUILD_VERSION >= 20011217L
extern XY XYNTSC[12]; // This was moved to SISamplingRate.c
extern XY XYPAL[12];  // This was moved to SISamplingRate.c
#else
static XY XYNTSC[12] = {
#if OS_BUILD_VERSION >= 20011002L
	{ 0xF6, 0x02 }, { 0x0E, 0x13 }, { 0x1E, 0x09 },
#else
	{ 0xF7, 0x02 }, { 0x0E, 0x13 }, { 0x1D, 0x09 },
#endif
	{ 0x25, 0x07 }, { 0x34, 0x05 }, { 0x41, 0x04 }, { 0x57, 0x03 }, { 0x57, 0x03 },
	{ 0x57, 0x03 }, { 0x83, 0x02 }, { 0x83, 0x02 }, { 0x83, 0x02 },
};
static XY XYPAL[12] = {
#if OS_BUILD_VERSION >= 20011002L
	{ 0x128, 0x02 },
#else
	{ 0x94, 0x03 },
#endif
	{ 0x0D, 0x18 },  { 0x1A, 0x0C }, { 0x27, 0x08 }, { 0x34, 0x06 }, { 0x3E, 0x05 }, { 0x4E, 0x04 },
	{ 0x68, 0x03 },  { 0x68, 0x03 }, { 0x68, 0x03 }, { 0x68, 0x03 }, { 0x9C, 0x02 },
};
#endif

#if OS_BUILD_VERSION >= 20011002L
#else

/**
 * This was moved to OSRtc.c
 * @note UNUSED Size: 000044
 */
static u16 GetWirelessID(s32 chan)
{
	OSSramEx* sram;
	u16 id;

	sram = __OSLockSramEx();
	id   = sram->wirelessPadID[chan];
	__OSUnlockSramEx(FALSE);
	return id;
}

/**
 * This was moved to OSRtc.c
 * @note UNUSED Size: 000068
 */
static void SetWirelessID(s32 chan, u16 id)
{
	OSSramEx* sram = __OSLockSramEx();

	if (sram->wirelessPadID[chan] != id) {
		sram->wirelessPadID[chan] = id;
		__OSUnlockSramEx(TRUE);
		return;
	}
	__OSUnlockSramEx(FALSE);
}

#endif

/**
 * @TODO: Documentation
 */
#if OS_BUILD_VERSION >= 20011002L
static void DoReset(void)
#else
static BOOL DoReset(void)
#endif
{
	u32 chanBit;
#if OS_BUILD_VERSION >= 20011002L
#else
	BOOL rc;
	rc = TRUE;
#endif

	ResettingChan = __mwerks_cntlzw(ResettingBits);

#if OS_BUILD_VERSION >= 20011002L
	if (ResettingChan != 0x20) {
		chanBit = PAD_CHAN0_BIT >> ResettingChan;
		ResettingBits &= ~chanBit;
		memset(&Origin[ResettingChan], 0, sizeof(PADStatus));
		SIGetTypeAsync(ResettingChan, PADTypeAndStatusCallback);
	}
#else
	if ((ResettingChan >= 0) && (ResettingChan < 4)) {
		memset(&Origin[ResettingChan], 0, sizeof(PADStatus));
		Type[ResettingChan]    = 0;
		PADType[ResettingChan] = 0;
		rc                     = SITransfer(ResettingChan, &CmdTypeAndStatus, 1, &Type[ResettingChan], 3, PADResetCallback, 0);
		chanBit                = PAD_CHAN0_BIT >> ResettingChan;
		ResettingBits &= ~chanBit;
		if (!rc) {
			ResettingChan = 0x20;
			ResettingBits = 0;
		}
	}
	return rc;
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000060 (Matching by size)
 */
static void PADEnable(s32 chan)
{
	u32 cmd;
	u32 chanBit;
	u32 data[2];

	chanBit = PAD_CHAN0_BIT >> chan;
	EnabledBits |= chanBit;
	SIGetResponse(chan, &data);
	OSAssertLine(0x1C4, !(Type[chan] & RES_WIRELESS_LITE));
	cmd = (AnalogMode | 0x400000);
	SISetCommand(chan, cmd);
	SIEnablePolling(EnabledBits);
}

#if OS_BUILD_VERSION >= 20011002L
#else

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000C0
 */
static void ProbeWireless(s32 chan)
{
	u32 cmd;
	u32 chanBit;
	u32 type;
	u32 data[2];

	chanBit = PAD_CHAN0_BIT >> chan;
	EnabledBits |= chanBit;
	ProbingBits |= chanBit;
	SIGetResponse(chan, &data);
	type = Type[chan];
	if (!(type & 0x02000000)) {
		cmd = (chan << 0xE) | 0x4D0000 | (__OSWirelessPadFixMode & 0x3FFF);
	} else if (((type & 0xC0000) + 0xFFFC0000) == 0) {
		cmd = 0x500000;
	} else {
		cmd = (type & 0x70000) + 0x440000;
	}
	SISetCommand(chan, cmd);
	SIEnablePolling(EnabledBits);
}

/**
 * This was moved to later in this file.
 */
static void PADProbeCallback(s32 chan, u32 error, OSContext* context)
{
	OSAssertLine(0x1F5, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
	OSAssertLine(0x1F6, chan == ResettingChan);

	if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))) {
		u32 type = Type[chan];
		if (!(type & 0x80000) && !(type & 0x40000)) {
			PADEnable(ResettingChan);
			WaitingBits |= PAD_CHAN0_BIT >> ResettingChan;
		} else {
			ProbeWireless(ResettingChan);
		}
	}
	DoReset();
}

#endif

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000C0
 */
static void PADDisable(s32 chan)
{
	int enabled;
	u32 chanBit;

	enabled = OSDisableInterrupts();
	chanBit = PAD_CHAN0_BIT >> chan;
	SIDisablePolling(chanBit);
	EnabledBits &= ~chanBit;
	WaitingBits &= ~chanBit;
	CheckingBits &= ~chanBit;
#if OS_BUILD_VERSION >= 20011002L
	PendingBits &= ~chanBit;
	OSSetWirelessID(chan, 0);
#else
	ProbingBits &= ~chanBit;
	SetWirelessID(chan, 0);
#endif
	OSRestoreInterrupts(enabled);
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
static void UpdateOrigin(s32 chan)
{
	PADStatus* origin;
	u32 chanBit;

	chanBit = PAD_CHAN0_BIT >> chan;
	origin  = &Origin[chan];
	switch (AnalogMode & 0x00000700u) {
	case 0x00000000u:
	case 0x00000500u:
	case 0x00000600u:
	case 0x00000700u:
	{
		origin->triggerLeft &= ~15;
		origin->triggerRight &= ~15;
		origin->analogA &= ~15;
		origin->analogB &= ~15;
		break;
	}
	case 0x00000100u:
	{
		origin->substickX &= ~15;
		origin->substickY &= ~15;
		origin->analogA &= ~15;
		origin->analogB &= ~15;
		break;
	}
	case 0x00000200u:
	{
		origin->substickX &= ~15;
		origin->substickY &= ~15;
		origin->triggerLeft &= ~15;
		origin->triggerRight &= ~15;
		break;
	}
	case 0x00000300u:
	{
		break;
	}
	case 0x00000400u:
	{
		break;
	}
	}

	origin->stickX -= 128;
	origin->stickY -= 128;
	origin->substickX -= 128;
	origin->substickY -= 128;

#if OS_BUILD_VERSION >= 20011002L
	if ((XPatchBits & chanBit) != 0 && origin->stickX > 64 && (SIGetType(chan) & 0xFFFF0000) == SI_GC_CONTROLLER)
#else
	if ((XPatchBits & chanBit) != 0 && origin->stickX > 64 && (Type[chan] & 0xFFFF0000) == SI_GC_CONTROLLER)
#endif
	{
		origin->stickX = 0;
	}
}

/**
 * @TODO: Documentation
 */
static void PADOriginCallback(s32 chan, u32 error, OSContext* context)
{
	OSAssertLine(0x267, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
	OSAssertLine(0x268, chan == ResettingChan);
	if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))) {
		UpdateOrigin(ResettingChan);
		PADEnable(ResettingChan);
	}
	DoReset();
}

/**
 * @TODO: Documentation
 */
static void PADOriginUpdateCallback(s32 chan, u32 error, OSContext* context)
{
	OSAssertLine(0x285, 0 <= chan && chan < SI_MAX_CHAN);
	if (!(EnabledBits & (PAD_CHAN0_BIT >> chan)))
		return;
	if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)))
		UpdateOrigin(chan);
#if OS_BUILD_VERSION >= 20011002L
	if ((error & SI_ERROR_NO_RESPONSE))
		PADDisable(chan);
#endif
}

#if OS_BUILD_VERSION >= 20011002L

/**
 * This was moved from earlier in this file.
 */
static void PADProbeCallback(s32 chan, u32 error, OSContext* context)
{
	OSAssertLine(0x1F5, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
	OSAssertLine(0x1F6, chan == ResettingChan);

	if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))) {
		PADEnable(ResettingChan);
		WaitingBits |= PAD_CHAN0_BIT >> ResettingChan;
	}
	DoReset();
}

/**
 * @TODO: Documentation
 */
static void PADTypeAndStatusCallback(s32 chan, u32 type)
{
	u32 chanBit;
	u32 recalibrate;
	BOOL rc;
	u32 error;

	rc          = TRUE;
	chanBit     = PAD_CHAN0_BIT >> ResettingChan;
	recalibrate = RecalibrateBits & chanBit;
	RecalibrateBits &= ~chanBit;

	if (type & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_COLLISION | SI_ERROR_NO_RESPONSE)) {
		DoReset();
		return;
	}

	type &= ~0xff;
	Type[ResettingChan] = type;

	if ((type & SI_TYPE_MASK) != SI_TYPE_GC || !(type & SI_GC_STANDARD)) {
		DoReset();
		return;
	}

	if (Spec < PAD_SPEC_2) {
		PADEnable(ResettingChan);
		DoReset();
		return;
	}

	if (!(type & SI_GC_WIRELESS) || (type & SI_WIRELESS_IR)) {
		if (recalibrate) {
			rc = SITransfer(ResettingChan, &CmdCalibrate, 3, &Origin[ResettingChan], 10, PADOriginCallback, 0);
		} else {
			rc = SITransfer(ResettingChan, &CmdReadOrigin, 1, &Origin[ResettingChan], 10, PADOriginCallback, 0);
		}
	} else if ((((type & SI_WIRELESS_FIX_ID) != 0) && ((type & SI_WIRELESS_CONT_MASK) == 0)) && ((type & SI_WIRELESS_LITE) == 0)) {
		if (type & SI_WIRELESS_RECEIVED) {
			rc = SITransfer(ResettingChan, &CmdReadOrigin, 1, &Origin[ResettingChan], 10, PADOriginCallback, 0);
		} else {
			rc = SITransfer(ResettingChan, &CmdProbeDevice[ResettingChan], 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
		}
	}

	if (!rc) {
		PendingBits |= chanBit;
		DoReset();
	}
}

/**
 * This was moved from later in this file
 */
static void PADReceiveCheckCallback(s32 chan, u32 type)
{
	u32 error;
	u32 chanBit;

	chanBit = PAD_CHAN0_BIT >> chan;

	if (!(EnabledBits & chanBit))
		return;

	error = type & 0xff;
	type &= ~0xff;

	WaitingBits &= ~chanBit;
	CheckingBits &= ~chanBit;

	if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)) && (type & SI_GC_WIRELESS)
	    && (type & SI_WIRELESS_FIX_ID) && (type & SI_WIRELESS_RECEIVED) && !(type & SI_WIRELESS_IR)
	    && (type & SI_WIRELESS_CONT_MASK) == SI_WIRELESS_CONT && !(type & SI_WIRELESS_LITE)) {
		SITransfer(chan, &CmdReadOrigin, 1, &Origin[chan], 10, PADOriginUpdateCallback, 0);
	} else {
		PADDisable(chan);
	}
}

#else

/**
 * @TODO: Documentation
 */
static void PADFixCallback(s32 unused, u32 error, OSContext* context)
{
	u32 type;
	u32 id;
	u32 frame;

	OSAssertLine(0x2A9, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);

	if (!(error & 0xF)) {
		type = Type[ResettingChan];
		id   = (GetWirelessID(ResettingChan) << 8);
		if (!(type & 0x100000) || ((id & 0xCFFF00u) != (type & 0xCFFF00))) {
			DoReset();
			return;
		}
		if ((type & 0x40000000) && !(type & 0x80000) && !(type & 0x40000)) {
			SITransfer(ResettingChan, &CmdReadOrigin, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		frame = (ResettingChan << 0x16) | 0x4D000000 | (__OSWirelessPadFixMode << 8) & 0x3FFF00u;
		SITransfer(ResettingChan, &CmdProbeDevice[ResettingChan], 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
		return;
	}
	DoReset();
}

/**
 * @TODO: Documentation
 */
static void PADResetCallback(s32 unused, u32 error, OSContext* context)
{
	u32 type;
	u32 id;
	u32 recalibrate;
	u32 chanBit;
	int fix;

	OSAssertLine(0x2E9, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);

	if (error & 0xF) {
		Type[ResettingChan] = 0;
	}

	PADType[ResettingChan] = type = Type[ResettingChan];
	chanBit                       = PAD_CHAN0_BIT >> ResettingChan;
	recalibrate                   = RecalibrateBits & chanBit;
	RecalibrateBits &= ~chanBit;
	fix = __PADFixBits & chanBit;
	__PADFixBits &= ~chanBit;
	if ((error & 0xF) || (((type & 0x18000000) + 0xF8000000) != 0)) {
		SetWirelessID(ResettingChan, 0);
		DoReset();
		return;
	}
	if (Spec < 2) {
		PADEnable(ResettingChan);
		DoReset();
		return;
	}
	if (!(type & 0x80000000) || (type & 0x04000000)) {
		SetWirelessID(ResettingChan, 0);
		if (!(type & 0x01000000)) {
			DoReset();
			return;
		}
		if (recalibrate != 0) {
			SITransfer(ResettingChan, &CmdCalibrate, 3, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		SITransfer(ResettingChan, &CmdReadOrigin, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
		return;
	}
	id = (GetWirelessID(ResettingChan) << 8);
	if ((fix != 0) && (id & 0x100000)) {
		CmdFixDevice[ResettingChan] = (id & 0xCFFF00) | 0x4E000000 | 0x100000;
		SITransfer(ResettingChan, &CmdFixDevice[ResettingChan], 3, &Type[ResettingChan], 3, PADFixCallback, 0);
		return;
	}
	if (type & 0x100000) {
		if ((id & 0xCFFF00) != (type & 0xCFFF00)) {
			if (!(id & 0x100000)) {
				id = (type & 0xCFFF00);
				id |= 0x100000;
				SetWirelessID(ResettingChan, (u16)(id >> 8) & 0xFFFFFF);
			}
			CmdFixDevice[ResettingChan] = id | 0x4E000000;
			SITransfer(ResettingChan, &CmdFixDevice[ResettingChan], 3, &Type[ResettingChan], 3, PADFixCallback, 0);
			return;
		}
		if ((type & 0x40000000) && !(type & 0x80000) && !(type & 0x40000)) {
			SITransfer(ResettingChan, &CmdReadOrigin, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		SITransfer(ResettingChan, &CmdProbeDevice[ResettingChan], 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
		return;
	}
	if (type & 0x40000000) {
		u32 id = (type & 0xCFFF00);
		id |= 0x100000;
		SetWirelessID(ResettingChan, (u16)(id >> 8) & 0xFFFFFF);
		CmdFixDevice[ResettingChan] = id | 0x4E000000;
		SITransfer(ResettingChan, &CmdFixDevice[ResettingChan], 3, &Type[ResettingChan], 3, PADFixCallback, 0);
		return;
	}
	SetWirelessID(ResettingChan, 0);
	ProbeWireless(ResettingChan);
	DoReset();
}

#endif

/**
 * @TODO: Documentation
 */
BOOL PADReset(u32 mask)
{
	BOOL enabled;
#if OS_BUILD_VERSION >= 20011002L
#if OS_BUILD_VERSION >= 20011112L
	u32 disabledBits;
#endif
#else
	BOOL rc = FALSE;
#endif

	OSAssertMsgLine(0x392, !(mask & 0x0FFFFFFF), "PADReset(): invalid mask");
	enabled = OSDisableInterrupts();

#if OS_BUILD_VERSION >= 20011002L
	mask |= PendingBits;
	PendingBits = 0;
	mask &= ~(WaitingBits | CheckingBits);
	ResettingBits |= mask;
#if OS_BUILD_VERSION >= 20011112L
	disabledBits = ResettingBits & EnabledBits;
#endif
	EnabledBits &= ~mask;
#else
	mask = mask & ~(CheckingBits | (ProbingBits | WaitingBits));
	ResettingBits |= mask;
	EnabledBits &= ~mask;
	WaitingBits &= ~mask;
#endif

	if (Spec == PAD_SPEC_4) {
		RecalibrateBits |= mask;
	}

#if OS_BUILD_VERSION >= 20011112L
	SIDisablePolling(disabledBits);
	if (ResettingChan == 0x20) {
		DoReset();
	}
#else
	SIDisablePolling(ResettingBits);
	if (ResettingChan == 0x20) {
#if OS_BUILD_VERSION >= 20011002L
		DoReset();
#else
		rc = DoReset();
#endif
	}
#endif

	OSRestoreInterrupts(enabled);

#if OS_BUILD_VERSION >= 20011002L
	return TRUE;
#else
	return rc;
#endif
}

/**
 * @TODO: Documentation
 */
BOOL PADRecalibrate(u32 mask)
{
	BOOL enabled;
#if OS_BUILD_VERSION >= 20011002L
#if OS_BUILD_VERSION >= 20011112L
	u32 disabledBits;
#endif
#else
	BOOL rc = FALSE;
#endif

	OSAssertMsgLine(0x3BD, !(mask & 0x0FFFFFFF), "PADRecalibrate(): invalid mask");
	enabled = OSDisableInterrupts();

#if OS_BUILD_VERSION >= 20011002L
	mask |= PendingBits;
	PendingBits = 0;
	mask &= ~(WaitingBits | CheckingBits);
	ResettingBits |= mask;
#if OS_BUILD_VERSION >= 20011112L
	disabledBits = ResettingBits & EnabledBits;
#endif
#else
	mask &= ~(CheckingBits | (ProbingBits | WaitingBits));
	ResettingBits |= mask;
#endif
	EnabledBits &= ~mask;

#if OS_BUILD_VERSION >= 20011002L
	if (!(GameChoice & 0x40)) {
		RecalibrateBits |= mask;
	}
#if OS_BUILD_VERSION >= 20011112L
	SIDisablePolling(disabledBits);
#else
	SIDisablePolling(ResettingBits);
#endif
#else
	RecalibrateBits |= mask;
	SIDisablePolling(ResettingBits);
#endif

	if (ResettingChan == 32) {
#if OS_BUILD_VERSION >= 20011002L
		DoReset();
#else
		rc = DoReset();
#endif
	}

	OSRestoreInterrupts(enabled);

#if OS_BUILD_VERSION >= 20011002L
	return TRUE;
#else
	return rc;
#endif
}

/**
 * @TODO: Documentation
 */
BOOL PADInit(void)
{
	s32 chan;
	OSTime time;

#if OS_BUILD_VERSION >= 20011002L
	if (Initialized) {
		return TRUE;
	} else
#else
	if (!Initialized)
#endif
	{
		if (__PADSpec) {
			PADSetSpec(__PADSpec);
		}

#if OS_BUILD_VERSION >= 20011217L
		Initialized = TRUE;
#endif

#if OS_BUILD_VERSION >= 20011002L
		if (__PADFixBits != 0)
#else
		if (__PADFixBits == -1)
#endif
		{
			time = OSGetTime();
			__OSWirelessPadFixMode
			    = (u16)((((time) & 0xffff) + ((time >> 16) & 0xffff) + ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff)) & 0x3fffu);
#if OS_BUILD_VERSION >= 20011002L
			RecalibrateBits = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT;
#endif
		}

		for (chan = 0; chan < SI_MAX_CHAN; ++chan) {
			CmdProbeDevice[chan] = (0x4d << 24) | (chan << 22) | ((__OSWirelessPadFixMode & 0x3fff) << 8);
		}

#if OS_BUILD_VERSION >= 20011217L
		SIRefreshSamplingRate();
#else
		Initialized = TRUE;
		PADSetSamplingRate(0);
#endif
		OSRegisterResetFunction(&ResetFunctionInfo);
	}
	return PADReset(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
}

#if OS_BUILD_VERSION >= 20011002L
#else

/**
 * This was moved to earlier in this file
 */
static void PADReceiveCheckCallback(s32 chan, u32 error, OSContext*)
{
	u32 type;
	u32 chanBit;

	type    = Type[chan];
	chanBit = PAD_CHAN0_BIT >> chan;

	WaitingBits &= ~chanBit;
	CheckingBits &= ~chanBit;

	if (EnabledBits & chanBit) {
		if (!(error & 0xF) && (type & 0x80000000) && (type & 0x02000000) && (type & 0x40000000) && !(type & 0x04000000)) {
			SITransfer(chan, &CmdReadOrigin, 1, &Origin[chan], 0xA, PADOriginUpdateCallback, 0);
			return;
		}
		PADDisable(chan);
	}
}

#endif

/**
 * @TODO: Documentation
 */
u32 PADRead(PADStatus* status)
{
	BOOL enabled;
	s32 chan;
	u32 data[2];
	u32 chanBit;
	u32 sr;
	int chanShift;
	u32 motor;

#if OS_BUILD_VERSION >= 20011002L
	enabled = OSDisableInterrupts();
#endif

	motor = 0;

	for (chan = 0; chan < SI_MAX_CHAN; chan++, status++) {
		chanBit   = PAD_CHAN0_BIT >> chan;
		chanShift = 8 * (SI_MAX_CHAN - 1 - chan);

#if OS_BUILD_VERSION >= 20011002L
		if (PendingBits & chanBit) {
			PADReset(0);
			status->err = PAD_ERR_NOT_READY;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}
#endif

		if ((ResettingBits & chanBit) || ResettingChan == chan) {
			status->err = PAD_ERR_NOT_READY;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

		if (!(EnabledBits & chanBit)) {
			status->err = PAD_ERR_NO_CONTROLLER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

#if OS_BUILD_VERSION >= 20011002L
		if (SIIsChanBusy(chan)) {
			status->err = PAD_ERR_TRANSFER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}
#endif

#if OS_BUILD_VERSION >= 20011112L
		sr = SIGetStatus(chan);
		if (sr & SI_ERROR_NO_RESPONSE)
#elif OS_BUILD_VERSION >= 20011002L
		sr = SIGetStatus();
		if (sr & (SI_ERROR_NO_RESPONSE << chanShift))
#else
		sr = SIGetStatus(SI_MAX_CHAN - 1 - chan);
		if (sr & (SI_ERROR_NO_RESPONSE << chanShift))
#endif
		{
#if OS_BUILD_VERSION >= 20011002L
			SIGetResponse(chan, data);
#endif

			if (WaitingBits & chanBit) {
				status->err = PAD_ERR_NONE;
				memset(status, 0, offsetof(PADStatus, err));

				if (!(CheckingBits & chanBit)) {
#if OS_BUILD_VERSION >= 20011002L // TODO
					CheckingBits |= chanBit;
					SIGetTypeAsync(chan, PADReceiveCheckCallback);
#else
					enabled = OSDisableInterrupts();
					if (SITransfer(chan, &CmdTypeAndStatus, 1, &Type[chan], 3, PADReceiveCheckCallback, 0) != 0) {
						CheckingBits |= chanBit;
					}
					OSRestoreInterrupts(enabled);
#endif
				}
			} else {
				PADDisable(chan);
				status->err = PAD_ERR_NO_CONTROLLER;
				memset(status, 0, offsetof(PADStatus, err));
			}
			continue;
		}

#if OS_BUILD_VERSION >= 20011002L
		if (!(SIGetType(chan) & SI_GC_NOMOTOR))
#else
		if (!(ProbingBits & chanBit) && !(Type[chan] & SI_GC_NOMOTOR))
#endif
		{
			motor |= chanBit;
		}

#if OS_BUILD_VERSION >= 20011002L
		if (!SIGetResponse(chan, data))
#else
		if (!(sr & (0x20 << chanShift)))
#endif
		{
			status->err = PAD_ERR_TRANSFER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}
#if OS_BUILD_VERSION >= 20011002L
#else
		SIGetResponse(chan, &data);
#endif

		if (data[0] & 0x80000000) {
			status->err = PAD_ERR_TRANSFER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

#if OS_BUILD_VERSION >= 20011002L
#else
		if (ProbingBits & chanBit) {
			status->err = PAD_ERR_NO_CONTROLLER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}
#endif

		MakeStatus(chan, status, data);

		// Check and clear PAD_ORIGIN bit
		if (status->button & 0x2000) {
			status->err = PAD_ERR_TRANSFER;
			memset(status, 0, offsetof(PADStatus, err));

			// Get origin. It is okay if the following transfer fails
			// since the PAD_ORIGIN bit remains until the read origin
			// command complete.
			SITransfer(chan, &CmdReadOrigin, 1, &Origin[chan], 10, PADOriginUpdateCallback, 0);
			continue;
		}

		status->err = PAD_ERR_NONE;

		// Clear PAD_INTERFERE bit
		status->button &= ~0x0080;
	}

#if OS_BUILD_VERSION >= 20011002L
	OSRestoreInterrupts(enabled);
#endif
	return motor;
}

/**
 * This implementation was moved to SISetSamplingRate.c (`SISetSamplingRate`)
 * @note UNUSED Size: 000020 (`OS_BUILD_VERSION >= 20011217L`) (Matching by size)
 */
void PADSetSamplingRate(u32 msec)
{
#if OS_BUILD_VERSION >= 20011217L
	// It's unclear how this function was stubbed, but you're not supposed to use it anymore.
	PPCHalt();
#else
	u32 tv;
	XY* xy;
#if OS_BUILD_VERSION >= 20011002L
	BOOL enabled;
	int test;
#endif

	OSAssertMsgLine(0x4CE, (msec <= 11), "PADSetSamplingRate(): out of rage (0 <= msec <= 11)");
	if (msec > 11) {
		msec = 11;
	}
#if OS_BUILD_VERSION >= 20011002L
	enabled      = OSDisableInterrupts();
	SamplingRate = msec;
#endif

	tv = VIGetTvFormat();
	switch (tv) {
	case VI_NTSC:
	case VI_MPAL:
	{
		xy = XYNTSC;
		break;
	}
	case VI_PAL:
	{
		xy = XYPAL;
		break;
	}
	default:
	{
#if OS_BUILD_VERSION >= 20011112L
		OSErrorLine(1174, "PADSetSamplingRate: unknown TV format");
#elif OS_BUILD_VERSION >= 20011002L
		OSErrorLine(1153, "PADSetSamplingRate: unknown TV format");
#else
		OSErrorLine(1296, "PADSetSamplingRate: unknown TV format");
#endif
		break;
	}
	}
#if OS_BUILD_VERSION >= 20011002L
	SISetXY((__VIRegs[VI_CLOCK_SEL] & 1 ? 2u : 1u) * xy[msec].line, xy[msec].count);
#else
	SISetXY(xy[msec].line, xy[msec].count);
#endif
	SIEnablePolling(EnabledBits);

#if OS_BUILD_VERSION >= 20011002L
	OSRestoreInterrupts(enabled);
#endif
#endif
}

#if OS_BUILD_VERSION >= 20011002L && OS_BUILD_VERSION < 20011217L
/**
 * This implementation was moved to SISamplingRate.c (`SIRefreshSamplingRate`)
 */
void __PADRefreshSamplingRate(void)
{
	PADSetSamplingRate(SamplingRate);
}
#endif

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000CC (OS_BUILD_VERSION <  20011002L) (Matching by size)
 * @note UNUSED Size: 0000B8 (OS_BUILD_VERSION >= 20011002L) (Matching by size)
 */
void PADControlAllMotors(const u32* commandArray)
{
	// UNUSED FUNCTION

	BOOL enabled;
	int chan;
	u32 command;
	BOOL commit;
	u32 chanBit;

	enabled = OSDisableInterrupts();
	commit  = FALSE;

	for (chan = 0; chan < SI_MAX_CHAN; chan++, commandArray++) {
		chanBit = PAD_CHAN0_BIT >> chan;
#if OS_BUILD_VERSION >= 20011002L
		if ((EnabledBits & chanBit) && !(SIGetType(chan) & SI_GC_NOMOTOR))
#else
		if ((EnabledBits & chanBit) && !(ProbingBits & chanBit) && !(Type[chan] & SI_GC_NOMOTOR))
#endif
		{
			command = *commandArray;
			OSAssertMsgLine(0x545, !(command & 0xFFFFFFFC), "PADControlAllMotors(): invalid command");
			if (Spec < PAD_SPEC_2 && command == PAD_MOTOR_STOP_HARD)
				command = PAD_MOTOR_STOP;
			SISetCommand(chan, (0x40 << 16) | AnalogMode | (command & (0x00000001 | 0x00000002)));
			commit = TRUE;
		}
	}
	if (commit)
		SITransferCommands();
	OSRestoreInterrupts(enabled);
}

/**
 * @TODO: Documentation
 */
void PADControlMotor(s32 chan, u32 command)
{
	BOOL enabled;
	u32 chanBit;

	OSAssertMsgLine(0x568, !(command & 0xFFFFFFFC), "PADControlMotor(): invalid command");

	enabled = OSDisableInterrupts();
	chanBit = PAD_CHAN0_BIT >> chan;
#if OS_BUILD_VERSION >= 20011002L
	if ((EnabledBits & chanBit) && !(SIGetType(chan) & SI_GC_NOMOTOR))
#else
	if ((EnabledBits & chanBit) && !(ProbingBits & chanBit) && !(Type[chan] & SI_GC_NOMOTOR))
#endif
	{
		if (Spec < PAD_SPEC_2 && command == PAD_MOTOR_STOP_HARD)
			command = PAD_MOTOR_STOP;
		SISetCommand(chan, (0x40 << 16) | AnalogMode | (command & (0x00000001 | 0x00000002)));
		SITransferCommands();
	}
	OSRestoreInterrupts(enabled);
}

/**
 * @TODO: Documentation
 */
void PADSetSpec(u32 spec)
{
	OSAssertLine(0x58C, !Initialized);
	__PADSpec = 0;
	switch (spec) {
	case PAD_SPEC_0:
	{
		MakeStatus = SPEC0_MakeStatus;
		break;
	}
	case PAD_SPEC_1:
	{
		MakeStatus = SPEC1_MakeStatus;
		break;
	}
	case PAD_SPEC_2:
	case PAD_SPEC_3:
	case PAD_SPEC_4:
	case PAD_SPEC_5:
	{
		MakeStatus = SPEC2_MakeStatus;
		break;
	}
	}
	Spec = spec;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000008 (Matching by size)
 */
u32 PADGetSpec(void)
{
	return Spec;
}

/**
 * @TODO: Documentation
 */
static void SPEC0_MakeStatus(s32 chan, PADStatus* status, u32 data[2])
{
	status->button = 0;
	status->button |= ((data[0] >> 16) & 0x0008) ? PAD_BUTTON_A : 0;
	status->button |= ((data[0] >> 16) & 0x0020) ? PAD_BUTTON_B : 0;
	status->button |= ((data[0] >> 16) & 0x0100) ? PAD_BUTTON_X : 0;
	status->button |= ((data[0] >> 16) & 0x0001) ? PAD_BUTTON_Y : 0;
	status->button |= ((data[0] >> 16) & 0x0010) ? PAD_BUTTON_START : 0;
	status->stickX       = (s8)(data[1] >> 16);
	status->stickY       = (s8)(data[1] >> 24);
	status->substickX    = (s8)(data[1]);
	status->substickY    = (s8)(data[1] >> 8);
	status->triggerLeft  = (u8)(data[0] >> 8);
	status->triggerRight = (u8)data[0];
	status->analogA      = 0;
	status->analogB      = 0;
	if (170 <= status->triggerLeft)
		status->button |= PAD_TRIGGER_L;
	if (170 <= status->triggerRight)
		status->button |= PAD_TRIGGER_R;
	status->stickX -= 128;
	status->stickY -= 128;
	status->substickX -= 128;
	status->substickY -= 128;
}

/**
 * @TODO: Documentation
 */
static void SPEC1_MakeStatus(s32 chan, PADStatus* status, u32 data[2])
{
	status->button = 0;
	status->button |= ((data[0] >> 16) & 0x0080) ? PAD_BUTTON_A : 0;
	status->button |= ((data[0] >> 16) & 0x0100) ? PAD_BUTTON_B : 0;
	status->button |= ((data[0] >> 16) & 0x0020) ? PAD_BUTTON_X : 0;
	status->button |= ((data[0] >> 16) & 0x0010) ? PAD_BUTTON_Y : 0;
	status->button |= ((data[0] >> 16) & 0x0200) ? PAD_BUTTON_START : 0;

	status->stickX    = (s8)(data[1] >> 16);
	status->stickY    = (s8)(data[1] >> 24);
	status->substickX = (s8)(data[1]);
	status->substickY = (s8)(data[1] >> 8);

	status->triggerLeft  = (u8)(data[0] >> 8);
	status->triggerRight = (u8)data[0];

	status->analogA = 0;
	status->analogB = 0;

	if (170 <= status->triggerLeft)
		status->button |= PAD_TRIGGER_L;
	if (170 <= status->triggerRight)
		status->button |= PAD_TRIGGER_R;

	status->stickX -= 128;
	status->stickY -= 128;
	status->substickX -= 128;
	status->substickY -= 128;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000054
 */
static s8 ClampS8(s8 var, s8 org)
{
	if (0 < org) {
		s8 min = (s8)(-128 + org);
		if (var < min)
			var = min;
	} else if (org < 0) {
		s8 max = (s8)(127 + org);
		if (max < var)
			var = max;
	}
	return var -= org;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00001C
 */
static u8 ClampU8(u8 var, u8 org)
{
	if (var < org)
		var = org;
	return var -= org;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
static void SPEC2_MakeStatus(s32 chan, PADStatus* status, u32 data[2])
{
	PADStatus* origin;

	status->button = (u16)((data[0] >> 16) & PAD_ALL);
	status->stickX = (s8)(data[0] >> 8);
	status->stickY = (s8)(data[0]);

	switch (AnalogMode & 0x00000700) {
	case 0x00000000:
	case 0x00000500:
	case 0x00000600:
	case 0x00000700:
	{
		status->substickX    = (s8)(data[1] >> 24);
		status->substickY    = (s8)(data[1] >> 16);
		status->triggerLeft  = (u8)(((data[1] >> 12) & 0x0f) << 4);
		status->triggerRight = (u8)(((data[1] >> 8) & 0x0f) << 4);
		status->analogA      = (u8)(((data[1] >> 4) & 0x0f) << 4);
		status->analogB      = (u8)(((data[1] >> 0) & 0x0f) << 4);
		break;
	}
	case 0x00000100:
	{
		status->substickX    = (s8)(((data[1] >> 28) & 0x0f) << 4);
		status->substickY    = (s8)(((data[1] >> 24) & 0x0f) << 4);
		status->triggerLeft  = (u8)(data[1] >> 16);
		status->triggerRight = (u8)(data[1] >> 8);
		status->analogA      = (u8)(((data[1] >> 4) & 0x0f) << 4);
		status->analogB      = (u8)(((data[1] >> 0) & 0x0f) << 4);
		break;
	}
	case 0x00000200:
	{
		status->substickX    = (s8)(((data[1] >> 28) & 0x0f) << 4);
		status->substickY    = (s8)(((data[1] >> 24) & 0x0f) << 4);
		status->triggerLeft  = (u8)(((data[1] >> 20) & 0x0f) << 4);
		status->triggerRight = (u8)(((data[1] >> 16) & 0x0f) << 4);
		status->analogA      = (u8)(data[1] >> 8);
		status->analogB      = (u8)(data[1] >> 0);
		break;
	}
	case 0x00000300:
	{
		status->substickX    = (s8)(data[1] >> 24);
		status->substickY    = (s8)(data[1] >> 16);
		status->triggerLeft  = (u8)(data[1] >> 8);
		status->triggerRight = (u8)(data[1] >> 0);
		status->analogA      = 0;
		status->analogB      = 0;
		break;
	}
	case 0x00000400:
	{
		status->substickX    = (s8)(data[1] >> 24);
		status->substickY    = (s8)(data[1] >> 16);
		status->triggerLeft  = 0;
		status->triggerRight = 0;
		status->analogA      = (u8)(data[1] >> 8);
		status->analogB      = (u8)(data[1] >> 0);
		break;
	}
	}

	status->stickX -= 128;
	status->stickY -= 128;
	status->substickX -= 128;
	status->substickY -= 128;

	origin               = &Origin[chan];
	status->stickX       = ClampS8(status->stickX, origin->stickX);
	status->stickY       = ClampS8(status->stickY, origin->stickY);
	status->substickX    = ClampS8(status->substickX, origin->substickX);
	status->substickY    = ClampS8(status->substickY, origin->substickY);
	status->triggerLeft  = ClampU8(status->triggerLeft, origin->triggerLeft);
	status->triggerRight = ClampU8(status->triggerRight, origin->triggerRight);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000054
 */
int PADGetType(s32 chan, u32* type)
{
	u32 chanBit;

	*type   = Type[chan];
	chanBit = PAD_CHAN0_BIT >> chan;
	if (ResettingBits & chanBit || ResettingChan == chan || !(EnabledBits & chanBit)) {
		return 0;
	}
	return 1;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
BOOL PADSync(void)
{
	return ResettingBits == 0 && (s32)ResettingChan == 32 && !SIBusy();
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000078 (OS_BUILD_VERSION <  20011002L) (Matching by size)
 * @note UNUSED Size: 000074 (OS_BUILD_VERSION >= 20011002L) (Matching by size)
 */
void PADSetAnalogMode(u32 mode)
{
	BOOL enabled;
	u32 mask;

	OSAssertMsgLine(0x6C9, (mode < 8), "PADSetAnalogMode(): invalid mode");

	enabled    = OSDisableInterrupts();
	AnalogMode = mode << 8;
#if OS_BUILD_VERSION >= 20011002L
	mask = EnabledBits; // This is a guess
#else
	mask = EnabledBits & ~ProbingBits;
#endif

	EnabledBits &= ~mask;
	WaitingBits &= ~mask;
	CheckingBits &= ~mask;

	SIDisablePolling(mask);
	OSRestoreInterrupts(enabled);
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
static BOOL OnReset(BOOL f)
{
	BOOL sync;
	static BOOL recalibrated = FALSE;

#if OS_BUILD_VERSION >= 20011002L
	if (SamplingCallback)
		PADSetSamplingCallback(NULL);
#endif

	if (!f) {
		sync = PADSync();
		if (!recalibrated && sync) {
			recalibrated = PADRecalibrate(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
			return FALSE;
		}
		return sync;
	} else
		recalibrated = FALSE;

	return TRUE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00000C
 */
void __PADDisableXPatch(void)
{
	XPatchBits = 0;
}

#if OS_BUILD_VERSION >= 20011002L

static void SamplingHandler(__OSInterrupt interrupt, OSContext* context)
{
	OSContext exceptionContext;

	if (SamplingCallback) {
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
		SamplingCallback();
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
	}
}

#if OS_BUILD_VERSION >= 20011112L
PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback)
#else
void PADSetSamplingCallback(PADSamplingCallback callback)
#endif
{
#if OS_BUILD_VERSION >= 20011112L
	PADSamplingCallback prev;
	prev = SamplingCallback;
#endif

	SamplingCallback = callback;
	if (callback)
		SIRegisterPollingHandler(SamplingHandler);
	else
		SIUnregisterPollingHandler(SamplingHandler);

#if OS_BUILD_VERSION >= 20011112L
	return prev;
#endif
}

BOOL __PADDisableRecalibration(BOOL disable)
{
	BOOL enabled;
	BOOL prev;

	enabled = OSDisableInterrupts();
	prev    = (GameChoice & 0x40) ? TRUE : FALSE;
	GameChoice &= (u8)~0x40;
	if (disable) {
		GameChoice |= 0x40;
	}
	OSRestoreInterrupts(enabled);
	return prev;
}

#endif
