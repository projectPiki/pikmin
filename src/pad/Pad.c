#include "Dolphin/pad.h"
#include "Dolphin/os.h"
#include "Dolphin/vi.h"
#include <stddef.h>
#include <string.h>

#define LATENCY 8

#define PAD_ALL                                                                                                                          \
	(PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_DOWN | PAD_BUTTON_UP | PAD_TRIGGER_Z | PAD_TRIGGER_R | PAD_TRIGGER_L | PAD_BUTTON_A \
	 | PAD_BUTTON_B | PAD_BUTTON_X | PAD_BUTTON_Y | PAD_BUTTON_MENU | 0x2000 | 0x0080)

#define RES_WIRELESS_LITE 0x40000

extern u16 __OSWirelessPadFixMode AT_ADDRESS(OS_BASE_CACHED | 0x30E0);

static int Initialized;   // size: 0x4, address: 0x0
static u32 EnabledBits;   // size: 0x4, address: 0x4
static u32 ResettingBits; // size: 0x4, address: 0x8
#if defined(VERSION_GPIP01_00)
#else
static u32 ProbingBits; // size: 0x4, address: 0xC
#endif
static u32 RecalibrateBits; // size: 0x4, address: 0x10
static u32 WaitingBits;     // size: 0x4, address: 0x14
static u32 CheckingBits;    // size: 0x4, address: 0x18

#if defined(VERSION_GPIP01_00)
static u32 PendingBits;
#else
static u32 cmdTypeAndStatus;
#endif

#if defined(VERSION_GPIP01_00)
#else
static u32 PADType[PAD_MAX_CONTROLLERS]; // size: 0x10, address: 0x0
#endif
static u32 Type[PAD_MAX_CONTROLLERS];                // size: 0x10, address: 0x0
static struct PADStatus Origin[PAD_MAX_CONTROLLERS]; // size: 0x30, address: 0x10
#if defined(VERSION_GPIP01_00)
static u32 CmdProbeDevice[PAD_MAX_CONTROLLERS];
static void (*SamplingCallback)();
#else
static u32 cmdProbeDevice[PAD_MAX_CONTROLLERS];
static u32 cmdFixDevice[PAD_MAX_CONTROLLERS];
#endif

// functions
static u16 GetWirelessID(s32 chan);
static void SetWirelessID(s32 chan, u16 id);
static int DoReset();
static void PADEnable(s32 chan);
static void ProbeWireless(s32 chan);
static void PADProbeCallback(s32 chan, u32 error, OSContext* context);
static void PADDisable(s32 chan);
static void UpdateOrigin(s32 chan);
static void PADOriginCallback(s32 chan, u32 error, OSContext* context);
static void PADFixCallback(s32 unused, u32 error, struct OSContext* context);
static void PADResetCallback(s32 unused, u32 error, struct OSContext* context);
int PADReset(u32 mask);
BOOL PADRecalibrate(u32 mask);
BOOL PADInit();
static void PADTypeAndStatusCallback(s32 chan, u32 type);
#if defined(VERSION_GPIP01_00)
static void PADReceiveCheckCallback(s32 chan, u32 type);
#else
static void PADReceiveCheckCallback(s32 chan, u32 error, OSContext* arg2);
#endif
u32 PADRead(struct PADStatus* status);
void PADSetSamplingRate(u32 msec);
void __PADTestSamplingRate(u32 tvmode);
void PADControlAllMotors(const u32* commandArray);
void PADControlMotor(s32 chan, u32 command);
void PADSetSpec(u32 spec);
u32 PADGetSpec();
static void SPEC0_MakeStatus(s32 chan, PADStatus* status, u32 data[2]);
static void SPEC1_MakeStatus(s32 chan, PADStatus* status, u32 data[2]);
static s8 ClampS8(s8 var, s8 org);
static u8 ClampU8(u8 var, u8 org);
static void SPEC2_MakeStatus(s32 chan, PADStatus* status, u32 data[2]);
int PADGetType(s32 chan, u32* type);
BOOL PADSync(void);
void PADSetAnalogMode(u32 mode);
static BOOL OnReset(BOOL f);

static s32 ResettingChan                                = 0x00000020; // size: 0x4, address: 0x0
static u32 XPatchBits                                   = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT;
static u32 AnalogMode                                   = 0x00000300;       // size: 0x4, address: 0x4
static u32 Spec                                         = 0x00000005;       // size: 0x4, address: 0x8
static void (*MakeStatus)(s32, struct PADStatus*, u32*) = SPEC2_MakeStatus; // size: 0x4, address: 0xC
#if defined(VERSION_GPIP01_00)
static u32 CmdReadOrigin = 0x41000000;
static u32 CmdCalibrate  = 0x42000000;
#else
static u32 cmdReadOrigin = 0x41000000;
static u32 cmdCalibrate  = 0x42000000;
#endif

static OSResetFunctionInfo ResetFunctionInfo = {
	OnReset,
	127,
	NULL,
	NULL,
};

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000044
 */
static u16 GetWirelessID(s32 chan)
{
	struct OSSramEx* sram;
	u16 id;

	sram = __OSLockSramEx();
	id   = sram->wirelessPadID[chan];
	__OSUnlockSramEx(0);
	return id;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000068
 */
static void SetWirelessID(s32 chan, u16 id)
{
	struct OSSramEx* sram = __OSLockSramEx();

	if (sram->wirelessPadID[chan] != id) {
		sram->wirelessPadID[chan] = id;
		__OSUnlockSramEx(1);
		return;
	}
	__OSUnlockSramEx(0);
}

/**
 * @TODO: Documentation
 */
static int DoReset(void)
{
#if defined(VERSION_GPIP01_00)
	u32 chanBit;
#else
	int rc;
	u32 chanBit;
	rc = 1;
#endif

	ResettingChan = __mwerks_cntlzw(ResettingBits);

#if defined(VERSION_GPIP01_00)
	if (ResettingChan != 0x20) {
		chanBit = PAD_CHAN0_BIT >> ResettingChan;
		ResettingBits &= ~chanBit;
		memset(&Origin[ResettingChan], 0, 0xc);
		SIGetTypeAsync(ResettingChan, PADTypeAndStatusCallback);
	}
#else
	if ((ResettingChan >= 0) && (ResettingChan < 4)) {
		memset(&Origin[ResettingChan], 0, 0xC);
		Type[ResettingChan]    = 0;
		PADType[ResettingChan] = 0;
		rc                     = SITransfer(ResettingChan, &cmdTypeAndStatus, 1, &Type[ResettingChan], 3, PADResetCallback, 0);
		chanBit                = (0x80000000 >> ResettingChan);
		ResettingBits &= ~chanBit;
		if (rc == 0) {
			ResettingChan = 0x20;
			ResettingBits = 0;
		}
	}
	return rc;
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000060
 */
static void PADEnable(s32 chan)
{
	u32 cmd;
	u32 chanBit;
	u32 data[2];

	chanBit = 0x80000000 >> chan;
	EnabledBits |= chanBit;
	SIGetResponse(chan, &data);
	OSAssertLine(0x1C4, !(Type[chan] & RES_WIRELESS_LITE));
	cmd = (AnalogMode | 0x400000);
	SISetCommand(chan, cmd);
	SIEnablePolling(EnabledBits);
}

#if defined(VERSION_GPIP01_00)
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

	chanBit = 0x80000000 >> chan;
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
#endif

#if defined(VERSION_GPIP01_00)
#else
/**
 * @TODO: Documentation
 */
static void PADProbeCallback(s32 chan, u32 error, OSContext* context)
{
	OSAssertLine(0x1F5, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
	OSAssertLine(0x1F6, chan == ResettingChan);

	if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))) {
		u32 type;
		type = Type[chan];
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
#if defined(VERSION_GPIP01_00)
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

	chanBit = 0x80000000 >> chan;
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

#if defined(VERSION_GPIP01_00)
	if ((XPatchBits & chanBit) != 0 && origin->stickX > 64 && (SIGetType(chan) & 0xFFFF0000) == SI_GC_CONTROLLER) {
#else
	if ((XPatchBits & chanBit) != 0 && origin->stickX > 64 && (Type[chan] & 0xFFFF0000) == SI_GC_CONTROLLER) {
#endif
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

#if defined(VERSION_GPIP01_00)
	if ((error & SI_ERROR_NO_RESPONSE))
		PADDisable(chan);
#endif
}

#if defined(VERSION_GPIP01_00)
/**
 * @TODO: Documentation
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
#endif

#if defined(VERSION_GPIP01_00)
static void PADTypeAndStatusCallback(s32 chan, u32 type)
{
	u32 chanBit;
	u32 recalibrate;
	int rc;
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

	if (rc == 0) {
		PendingBits |= chanBit;
		DoReset();
	}
}

/**
 * @TODO: Documentation
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
#endif

/**
 * @TODO: Documentation
 */
static void PADFixCallback(s32 unused, u32 error, struct OSContext* context)
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
#if defined(VERSION_GPIP01_00)
			SITransfer(ResettingChan, &CmdReadOrigin, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
#else
			SITransfer(ResettingChan, &cmdReadOrigin, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
#endif
			return;
		}
		frame = (ResettingChan << 0x16) | 0x4D000000 | (__OSWirelessPadFixMode << 8) & 0x3FFF00u;
#if defined(VERSION_GPIP01_00)
		SITransfer(ResettingChan, &CmdProbeDevice[ResettingChan], 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
#else
		SITransfer(ResettingChan, &cmdProbeDevice[ResettingChan], 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
#endif
		return;
	}
	DoReset();
}

#if defined(VERSION_GPIP01_00)
#else
u32 __PADFixBits; // size: 0x4, address: 0x24

/**
 * @TODO: Documentation
 */
static void PADResetCallback(s32 unused, u32 error, struct OSContext* context)
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
	chanBit                       = 0x80000000 >> ResettingChan;
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
			SITransfer(ResettingChan, &cmdCalibrate, 3, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		SITransfer(ResettingChan, &cmdReadOrigin, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
		return;
	}
	id = (GetWirelessID(ResettingChan) << 8);
	if ((fix != 0) && (id & 0x100000)) {
		cmdFixDevice[ResettingChan] = (id & 0xCFFF00) | 0x4E000000 | 0x100000;
		SITransfer(ResettingChan, &cmdFixDevice[ResettingChan], 3, &Type[ResettingChan], 3, PADFixCallback, 0);
		return;
	}
	if (type & 0x100000) {
		if ((id & 0xCFFF00) != (type & 0xCFFF00)) {
			if (!(id & 0x100000)) {
				id = (type & 0xCFFF00);
				id |= 0x100000;
				SetWirelessID(ResettingChan, (u16)(id >> 8) & 0xFFFFFF);
			}
			cmdFixDevice[ResettingChan] = id | 0x4E000000;
			SITransfer(ResettingChan, &cmdFixDevice[ResettingChan], 3, &Type[ResettingChan], 3, PADFixCallback, 0);
			return;
		}
		if ((type & 0x40000000) && !(type & 0x80000) && !(type & 0x40000)) {
			SITransfer(ResettingChan, &cmdReadOrigin, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		SITransfer(ResettingChan, &cmdProbeDevice[ResettingChan], 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
		return;
	}
	if (type & 0x40000000) {
		u32 id = (type & 0xCFFF00);
		id |= 0x100000;
		SetWirelessID(ResettingChan, (u16)(id >> 8) & 0xFFFFFF);
		cmdFixDevice[ResettingChan] = id | 0x4E000000;
		SITransfer(ResettingChan, &cmdFixDevice[ResettingChan], 3, &Type[ResettingChan], 3, PADFixCallback, 0);
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
int PADReset(u32 mask)
{
#if defined(VERSION_GPIP01_00)
	BOOL enabled;
	u32 disabledBits;

	enabled = OSDisableInterrupts();

	mask |= PendingBits;
	PendingBits = 0;
	mask &= ~(WaitingBits | CheckingBits);
	ResettingBits |= mask;
	disabledBits = ResettingBits & EnabledBits;
	EnabledBits &= ~mask;

	if (Spec == PAD_SPEC_4)
		RecalibrateBits |= mask;

	SIDisablePolling(disabledBits);
	if (ResettingChan == 0x20)
		DoReset();

	OSRestoreInterrupts(enabled);

	return TRUE;
#else
	int enabled;
	int rc;

	rc = 0;
	OSAssertMsgLine(0x392, !(mask & 0x0FFFFFFF), "PADReset(): invalid mask");

	enabled = OSDisableInterrupts();

	mask = mask & ~(CheckingBits | (ProbingBits | WaitingBits));
	ResettingBits |= mask;
	EnabledBits &= ~mask;
	WaitingBits &= ~mask;
	if (Spec == PAD_SPEC_4) {
		RecalibrateBits |= mask;
	}
	SIDisablePolling(ResettingBits);
	if (ResettingChan == 0x20) {
		rc = DoReset();
	}

	OSRestoreInterrupts(enabled);
	return rc;
#endif
}

u8 GameChoice AT_ADDRESS(OS_BASE_CACHED | 0x30E3);

/**
 * @TODO: Documentation
 */
BOOL PADRecalibrate(u32 mask)
{
	BOOL intrEnabled;
	BOOL ret;

	ret = FALSE;

#if defined(VERSION_GPIP01_00)
#else
	OSAssertMsgLine(0x3BD, !(mask & 0x0FFFFFFF), "PADReset(): invalid mask");
#endif

	intrEnabled = OSDisableInterrupts();
#if defined(VERSION_GPIP01_00)
	mask |= PendingBits;
	PendingBits = 0;
	mask &= ~(WaitingBits | CheckingBits);
	ResettingBits |= mask;
	ret = ResettingBits & EnabledBits;
#else
	mask &= ~(CheckingBits | (ProbingBits | WaitingBits));
	ResettingBits |= mask;
#endif

	EnabledBits &= ~mask;

#if defined(VERSION_GPIP01_00)
	if (!(GameChoice & 0x40)) {
		RecalibrateBits |= mask;
	}
	SIDisablePolling(ret);
#else
	RecalibrateBits |= mask;
	SIDisablePolling(ResettingBits);
#endif

#if defined(VERSION_GPIP01_00)
	if ((s32)ResettingChan == 32)
		DoReset();
	OSRestoreInterrupts(intrEnabled);
	return TRUE;
#else
	if ((s32)ResettingChan == 32)
		ret = DoReset();
	OSRestoreInterrupts(intrEnabled);
	return ret;
#endif
}

u32 __PADSpec; // size: 0x4, address: 0x20

/**
 * @TODO: Documentation
 */
BOOL PADInit()
{
	s32 chan;

#if defined(VERSION_GPIP01_00)
	if (Initialized)
		return TRUE;

	if (__PADSpec)
		PADSetSpec(__PADSpec);

	Initialized = TRUE;

	if (__PADFixBits != 0) {
		OSTime time = OSGetTime();
		__OSWirelessPadFixMode
		    = (u16)((((time) & 0xffff) + ((time >> 16) & 0xffff) + ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff)) & 0x3fffu);
		RecalibrateBits = PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT;
	}

	for (chan = 0; chan < SI_MAX_CHAN; ++chan)
		CmdProbeDevice[chan] = (0x4d << 24) | (chan << 22) | ((__OSWirelessPadFixMode & 0x3fff) << 8);

	SIRefreshSamplingRate();
	OSRegisterResetFunction(&ResetFunctionInfo);
#else
	OSTime time;

	if (!Initialized) {
		if (__PADSpec) {
			PADSetSpec(__PADSpec);
		}

		if (__PADFixBits == -1) {
			time = OSGetTime();
			__OSWirelessPadFixMode
			    = (u16)((((time) & 0xffff) + ((time >> 16) & 0xffff) + ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff)) & 0x3fffu);
		}

		for (chan = 0; chan < SI_MAX_CHAN; chan++) {
			cmdProbeDevice[chan] = 0x4D000000 | (chan << 22) | (__OSWirelessPadFixMode & 0x3FFF) << 8;
		}

		Initialized = TRUE;
		PADSetSamplingRate(0);
		OSRegisterResetFunction(&ResetFunctionInfo);
	}
#endif
	return PADReset(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
}

#if defined(VERSION_GPIP01_00)
#else
static void PADReceiveCheckCallback(s32 chan, u32 error, OSContext* arg2)
{
	u32 type;
	u32 chanBit;

	type = Type[chan];

	chanBit = PAD_CHAN0_BIT >> chan;

	WaitingBits &= ~chanBit;
	CheckingBits &= ~chanBit;

	if (EnabledBits & chanBit) {
		if (!(error & 0xF) && (type & 0x80000000) && (type & 0x02000000) && (type & 0x40000000) && !(type & 0x04000000)) {
			SITransfer(chan, &cmdReadOrigin, 1, &Origin[chan], 0xA, PADOriginUpdateCallback, 0);
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
#if defined(VERSION_GPIP01_00)
	BOOL enabled;
	s32 chan;
	u32 data[2];
	u32 chanBit;
	u32 sr;
	int chanShift;
	u32 motor;

	enabled = OSDisableInterrupts();

	motor = 0;

	for (chan = 0; chan < SI_MAX_CHAN; chan++, status++) {
		chanBit   = PAD_CHAN0_BIT >> chan;
		chanShift = 8 * (SI_MAX_CHAN - 1 - chan);

		if (PendingBits & chanBit) {
			PADReset(0);
			status->err = PAD_ERR_NOT_READY;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

		if ((ResettingBits & chanBit) || ResettingChan == chan) {
			status->err = PAD_ERR_NOT_READY;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

		if (!(EnabledBits & chanBit)) {
			status->err = (s8)PAD_ERR_NO_CONTROLLER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

		if (SIIsChanBusy(chan)) {
			status->err = PAD_ERR_TRANSFER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

		sr = SIGetStatus(chan);
		if (sr & SI_ERROR_NO_RESPONSE) {
			SIGetResponse(chan, data);

			if (WaitingBits & chanBit) {
				status->err = (s8)PAD_ERR_NONE;
				memset(status, 0, offsetof(PADStatus, err));

				if (!(CheckingBits & chanBit)) {
					CheckingBits |= chanBit;
					SIGetTypeAsync(chan, PADReceiveCheckCallback);
				}
				continue;
			}

			PADDisable(chan);

			status->err = (s8)PAD_ERR_NO_CONTROLLER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

		if (!(SIGetType(chan) & SI_GC_NOMOTOR)) {
			motor |= chanBit;
		}

		if (!SIGetResponse(chan, data)) {
			status->err = PAD_ERR_TRANSFER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

		if (data[0] & 0x80000000) {
			status->err = PAD_ERR_TRANSFER;
			memset(status, 0, offsetof(PADStatus, err));
			continue;
		}

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

	OSRestoreInterrupts(enabled);

	return motor;
#else
	s32 chan;
	u32 data[2];
	u32 chanBit;
	u32 sr;
	int chanShift;
	int enabled;
	u32 motor;

	motor = 0;

	for (chan = 0; chan < 4; chan++, status++) {
		chanBit   = 0x80000000 >> chan;
		chanShift = (3 - chan) * 8;
		if ((ResettingBits & chanBit) || (ResettingChan == chan)) {
			status->err = -2;
			memset(status, 0, 0xA);
		} else if (!(EnabledBits & chanBit)) {
			status->err = -1;
			memset(status, 0, 0xA);
		} else {
			sr = SIGetStatus(3 - chan);
			if (sr & (8 << chanShift)) {
				if (WaitingBits & chanBit) {
					status->err = 0;
					memset(status, 0, 0xA);
					if (!(CheckingBits & chanBit)) {
						enabled = OSDisableInterrupts();
						if (SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3, PADReceiveCheckCallback, 0) != 0) {
							CheckingBits |= chanBit;
						}
						OSRestoreInterrupts(enabled);
					}
				} else {
					PADDisable(chan);
					status->err = -1;
					memset(status, 0, 0xA);
				}
			} else {
				if (!(ProbingBits & chanBit) && !(Type[chan] & SI_GC_NOMOTOR)) {
					motor |= chanBit;
				}
				if (!(sr & (0x20 << chanShift))) {
					status->err = -3;
					memset(status, 0, 0xA);
				} else {
					SIGetResponse(chan, &data);
					if (data[0] & 0x80000000) {
						status->err = -3;
						memset(status, 0, 0xA);
					} else if (ProbingBits & chanBit) {
						status->err = -1;
						memset(status, 0, 0xA);
					} else {
						MakeStatus(chan, status, data);
						if (status->button & 0x2000) {
							status->err = -3;
							memset(status, 0, 0xA);
							SITransfer(chan, &cmdReadOrigin, 1, &Origin[chan], 0xA, PADOriginUpdateCallback, 0);
						} else {
							status->err = 0;
							status->button &= 0xFFFFFF7F;
						}
					}
				}
			}
		}
	}
	return motor;
#endif
}

#if defined(VERSION_GPIP01_00)
#else

typedef struct XY {
	/* 0x00 */ u8 line;
	/* 0x01 */ u8 count;
} XY;

static XY XYNTSC[12] = { { 0xF7, 0x02 }, { 0x0E, 0x13 }, { 0x1D, 0x09 }, { 0x25, 0x07 }, { 0x34, 0x05 }, { 0x41, 0x04 },
	                     { 0x57, 0x03 }, { 0x57, 0x03 }, { 0x57, 0x03 }, { 0x83, 0x02 }, { 0x83, 0x02 }, { 0x83, 0x02 } };

static XY XYPAL[12] = { { 0x94, 0x03 }, { 0x0D, 0x18 }, { 0x1A, 0x0C }, { 0x27, 0x08 }, { 0x34, 0x06 }, { 0x3E, 0x05 },
	                    { 0x4E, 0x04 }, { 0x68, 0x03 }, { 0x68, 0x03 }, { 0x68, 0x03 }, { 0x68, 0x03 }, { 0x9C, 0x02 } };

/**
 * @TODO: Documentation
 */
void PADSetSamplingRate(u32 msec)
{
	u32 tv;
	XY* xy;

	OSAssertMsgLine(0x4CE, (msec <= 0xB), "PADSetSamplingRate(): out of rage (0 <= msec <= 11)");
	if (msec > 0xB) {
		msec = 0xB;
	}
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
		OSErrorLine(1296, "PADSetSamplingRate: unknown TV format");
	}
	}
	SISetXY(xy[msec].line, xy[msec].count);
	SIEnablePolling(EnabledBits);
}
#endif

#if defined(VERSION_GPIP01_00)
#else
/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000CC
 */
void PADControlAllMotors(const u32* commandArray)
{
	BOOL enabled;
	int chan;
	u32 command;
	BOOL commit;
	u32 chanBit;

	enabled = OSDisableInterrupts();
	commit  = FALSE;

	for (chan = 0; chan < SI_MAX_CHAN; chan++, commandArray++) {
		chanBit = PAD_CHAN0_BIT >> chan;
		if ((EnabledBits & chanBit) && !(ProbingBits & chanBit) && !(Type[chan] & 0x20000000)) {
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
	// UNUSED FUNCTION
}
#endif

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
#if defined(VERSION_GPIP01_00)
	if ((EnabledBits & chanBit) && !(SIGetType(chan) & SI_GC_NOMOTOR)) {
#else
	if ((EnabledBits & chanBit) && !(ProbingBits & chanBit) && !(Type[chan] & 0x20000000)) {
#endif
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
 * @note UNUSED Size: 000008
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
	chanBit = 0x80000000 >> chan;
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

#if defined(VERSION_GPIP01_00)
#else
/**
 * @TODO: Documentation
 * @note UNUSED Size: 000078
 */
void PADSetAnalogMode(u32 mode)
{
	BOOL enabled;
	u32 mask;

	OSAssertMsgLine(0x6C9, (mode < 8), "PADSetAnalogMode(): invalid mode");

	enabled    = OSDisableInterrupts();
	AnalogMode = mode << 8;
	mask       = EnabledBits & ~ProbingBits;

	EnabledBits &= ~mask;
	WaitingBits &= ~mask;
	CheckingBits &= ~mask;

	SIDisablePolling(mask);
	OSRestoreInterrupts(enabled);
	// UNUSED FUNCTION
}
#endif

/**
 * @TODO: Documentation
 */
static BOOL OnReset(BOOL f)
{
	BOOL sync;
	static BOOL recalibrated = FALSE;

#if defined(VERSION_GPIP01_00)
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

#if defined(VERSION_GPIP01_00)
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

PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback)
{
	PADSamplingCallback prev;

	prev             = SamplingCallback;
	SamplingCallback = callback;
	if (callback)
		SIRegisterPollingHandler(SamplingHandler);
	else
		SIUnregisterPollingHandler(SamplingHandler);

	return prev;
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
