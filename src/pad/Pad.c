#include "Dolphin/pad.h"
#include "Dolphin/os.h"
#include "Dolphin/vi.h"

#define LATENCY 8

#define PAD_ALL                                                                                                                          \
	(PAD_BUTTON_LEFT | PAD_BUTTON_RIGHT | PAD_BUTTON_DOWN | PAD_BUTTON_UP | PAD_TRIGGER_Z | PAD_TRIGGER_R | PAD_TRIGGER_L | PAD_BUTTON_A \
	 | PAD_BUTTON_B | PAD_BUTTON_X | PAD_BUTTON_Y | PAD_BUTTON_MENU | 0x2000 | 0x0080)

#define RES_WIRELESS_LITE 0x40000

u16 __OSWirelessPadFixMode AT_ADDRESS(0x800030E0);

static int Initialized;     // size: 0x4, address: 0x0
static u32 EnabledBits;     // size: 0x4, address: 0x4
static u32 ResettingBits;   // size: 0x4, address: 0x8
static u32 ProbingBits;     // size: 0x4, address: 0xC
static u32 RecalibrateBits; // size: 0x4, address: 0x10
static u32 WaitingBits;     // size: 0x4, address: 0x14
static u32 CheckingBits;    // size: 0x4, address: 0x18
static u32 cmdTypeAndStatus;

static u32 PADType[PAD_MAX_CONTROLLERS];             // size: 0x10, address: 0x0
static u32 Type[PAD_MAX_CONTROLLERS];                // size: 0x10, address: 0x0
static struct PADStatus Origin[PAD_MAX_CONTROLLERS]; // size: 0x30, address: 0x10
static u32 cmdProbeDevice[PAD_MAX_CONTROLLERS];
static u32 cmdFixDevice[PAD_MAX_CONTROLLERS];

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
static void PADReceiveCheckCallback(s32 chan, u32 error, OSContext* arg2);
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
static u32 cmdReadOrigin                                = 0x41000000;
static u32 cmdCalibrate                                 = 0x42000000;

static OSResetFunctionInfo ResetFunctionInfo = {
	OnReset,
	127,
	NULL,
	NULL,
};

/*
 * --INFO--
 * Address:	........
 * Size:	000044
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

/*
 * --INFO--
 * Address:	........
 * Size:	000068
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

/*
 * --INFO--
 * Address:	80203E04
 * Size:	0000D4
 */
static int DoReset(void)
{
	int rc;
	u32 chanBit;

	rc            = 1;
	ResettingChan = __cntlzw(ResettingBits);
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
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
static void PADEnable(s32 chan)
{
	u32 cmd;
	u32 chanBit;
	u32 data[2];

	chanBit = 0x80000000 >> chan;
	EnabledBits |= chanBit;
	SIGetResponse(chan, &data);
	ASSERTLINE(0x1C4, !(Type[chan] & RES_WIRELESS_LITE));
	cmd = (AnalogMode | 0x400000);
	SISetCommand(chan, cmd);
	SIEnablePolling(EnabledBits);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
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

/*
 * --INFO--
 * Address:	80203ED8
 * Size:	0001DC
 */
static void PADProbeCallback(s32 chan, u32 error, OSContext* context)
{
	ASSERTLINE(0x1F5, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
	ASSERTLINE(0x1F6, chan == ResettingChan);
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

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
static void PADDisable(s32 chan)
{
	int enabled;
	u32 chanBit;

	enabled = OSDisableInterrupts();
	chanBit = 0x80000000 >> chan;
	SIDisablePolling(chanBit);
	EnabledBits &= ~chanBit;
	WaitingBits &= ~chanBit;
	CheckingBits &= ~chanBit;
	ProbingBits &= ~chanBit;
	SetWirelessID(chan, 0);
	OSRestoreInterrupts(enabled);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802040B4
 * Size:	000194
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
		origin->triggerLeft &= ~15;
		origin->triggerRight &= ~15;
		origin->analogA &= ~15;
		origin->analogB &= ~15;
		break;
	case 0x00000100u:
		origin->substickX &= ~15;
		origin->substickY &= ~15;
		origin->analogA &= ~15;
		origin->analogB &= ~15;
		break;
	case 0x00000200u:
		origin->substickX &= ~15;
		origin->substickY &= ~15;
		origin->triggerLeft &= ~15;
		origin->triggerRight &= ~15;
		break;
	case 0x00000300u:
		break;
	case 0x00000400u:
		break;
	}

	origin->stickX -= 128;
	origin->stickY -= 128;
	origin->substickX -= 128;
	origin->substickY -= 128;

	if ((XPatchBits & chanBit) != 0 && origin->stickX > 64 && (Type[chan] & 0xFFFF0000) == SI_GC_CONTROLLER) {
		origin->stickX = 0;
	}
}

/*
 * --INFO--
 * Address:	80204248
 * Size:	00011C
 */
static void PADOriginCallback(s32 chan, u32 error, OSContext* context)
{
	ASSERTLINE(0x267, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);
	ASSERTLINE(0x268, chan == ResettingChan);
	if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))) {
		UpdateOrigin(ResettingChan);
		PADEnable(ResettingChan);
	}
	DoReset();
}

/*
 * --INFO--
 * Address:	80204364
 * Size:	00003C
 */
static void PADOriginUpdateCallback(s32 chan, u32 error, OSContext* context)
{
	ASSERTLINE(0x285, 0 <= chan && chan < SI_MAX_CHAN);
	if (!(EnabledBits & (PAD_CHAN0_BIT >> chan)))
		return;
	if (!(error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION)))
		UpdateOrigin(chan);
}

/*
 * --INFO--
 * Address:	802043A0
 * Size:	000254
 */
static void PADFixCallback(s32 unused, u32 error, struct OSContext* context)
{
	u32 type;
	u32 id;
	u32 frame;

	ASSERTLINE(0x2A9, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);

	if (!(error & 0xF)) {
		type = Type[ResettingChan];
		id   = (GetWirelessID(ResettingChan) << 8);
		if (!(type & 0x100000) || ((id & 0xCFFF00u) != (type & 0xCFFF00))) {
			DoReset();
			return;
		}
		if ((type & 0x40000000) && !(type & 0x80000) && !(type & 0x40000)) {
			SITransfer(ResettingChan, &cmdReadOrigin, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		frame = (ResettingChan << 0x16) | 0x4D000000 | (__OSWirelessPadFixMode << 8) & 0x3FFF00u;
		SITransfer(ResettingChan, &cmdProbeDevice[ResettingChan], 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
		return;
	}
	DoReset();
}

u32 __PADFixBits; // size: 0x4, address: 0x24

/*
 * --INFO--
 * Address:	802045F4
 * Size:	000730
 */
static void PADResetCallback(s32 unused, u32 error, struct OSContext* context)
{
	u32 type;
	u32 id;
	u32 recalibrate;
	u32 chanBit;
	int fix;

	ASSERTLINE(0x2E9, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);

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

/*
 * --INFO--
 * Address:	80204D24
 * Size:	00016C
 */
int PADReset(u32 mask)
{
	int enabled;
	int rc;

	rc = 0;
	ASSERTMSGLINE(0x392, !(mask & 0x0FFFFFFF), "PADReset(): invalid mask");
	enabled = OSDisableInterrupts();
	mask    = mask & ~(CheckingBits | (ProbingBits | WaitingBits));
	ResettingBits |= mask;
	EnabledBits &= ~mask;
	WaitingBits &= ~mask;
	if (Spec == 4) {
		RecalibrateBits |= mask;
	}
	SIDisablePolling(ResettingBits);
	if (ResettingChan == 0x20) {
		rc = DoReset();
	}
	OSRestoreInterrupts(enabled);
	return rc;
}

/*
 * --INFO--
 * Address:	80204E90
 * Size:	000154
 */
BOOL PADRecalibrate(u32 mask)
{
	BOOL intrEnabled;
	BOOL ret;

	ret = FALSE;
	ASSERTMSGLINE(0x3BD, !(mask & 0x0FFFFFFF), "PADReset(): invalid mask");
	intrEnabled = OSDisableInterrupts();
	mask &= ~(CheckingBits | (ProbingBits | WaitingBits));
	ResettingBits |= mask;
	EnabledBits &= ~mask;
	RecalibrateBits |= mask;
	SIDisablePolling(ResettingBits);
	if ((s32)ResettingChan == 32)
		ret = DoReset();
	OSRestoreInterrupts(intrEnabled);
	return ret;
}

u32 __PADSpec; // size: 0x4, address: 0x20

/*
 * --INFO--
 * Address:	80204FE4
 * Size:	0001C4
 */
BOOL PADInit()
{
	s32 chan;
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
	return PADReset(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
}

/*
 * --INFO--
 * Address:	802051A8
 * Size:	00015C
 */
static void PADReceiveCheckCallback(s32 chan, u32 error, OSContext* arg2)
{
	u32 type;
	u32 chanBit;

	type    = Type[chan];
	chanBit = 0x80000000 >> chan;
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

/*
 * --INFO--
 * Address:	80205304
 * Size:	000338
 */
u32 PADRead(PADStatus* status)
{
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
}

typedef struct XY {
	/* 0x00 */ u8 line;
	/* 0x01 */ u8 count;
} XY;

static XY XYNTSC[12] = { { 0xF7, 0x02 }, { 0x0E, 0x13 }, { 0x1D, 0x09 }, { 0x25, 0x07 }, { 0x34, 0x05 }, { 0x41, 0x04 },
	                     { 0x57, 0x03 }, { 0x57, 0x03 }, { 0x57, 0x03 }, { 0x83, 0x02 }, { 0x83, 0x02 }, { 0x83, 0x02 } };

static XY XYPAL[12] = { { 0x94, 0x03 }, { 0x0D, 0x18 }, { 0x1A, 0x0C }, { 0x27, 0x08 }, { 0x34, 0x06 }, { 0x3E, 0x05 },
	                    { 0x4E, 0x04 }, { 0x68, 0x03 }, { 0x68, 0x03 }, { 0x68, 0x03 }, { 0x68, 0x03 }, { 0x9C, 0x02 } };

/*
 * --INFO--
 * Address:	8020563C
 * Size:	0000B0
 */
void PADSetSamplingRate(u32 msec)
{
	u32 tv;
	XY* xy;

	ASSERTMSGLINE(0x4CE, (msec <= 0xB), "PADSetSamplingRate(): out of rage (0 <= msec <= 11)");
	if (msec > 0xB) {
		msec = 0xB;
	}
	tv = VIGetTvFormat();
	switch (tv) {
	case VI_NTSC:
	case VI_MPAL:
		xy = XYNTSC;
		break;
	case VI_PAL:
		xy = XYPAL;
		break;
	default:
		OSPanic("Pad.c", 1296, "PADSetSamplingRate: unknown TV format");
	}
	SISetXY(xy[msec].line, xy[msec].count);
	SIEnablePolling(EnabledBits);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
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
			ASSERTMSGLINE(0x545, !(command & 0xFFFFFFFC), "PADControlAllMotors(): invalid command");
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

/*
 * --INFO--
 * Address:	802056EC
 * Size:	0000BC
 */
void PADControlMotor(s32 chan, u32 command)
{
	BOOL enabled;
	u32 chanBit;

	ASSERTMSGLINE(0x568, !(command & 0xFFFFFFFC), "PADControlMotor(): invalid command");

	enabled = OSDisableInterrupts();
	chanBit = PAD_CHAN0_BIT >> chan;
	if ((EnabledBits & chanBit) && !(ProbingBits & chanBit) && !(Type[chan] & 0x20000000)) {
		if (Spec < PAD_SPEC_2 && command == PAD_MOTOR_STOP_HARD)
			command = PAD_MOTOR_STOP;
		SISetCommand(chan, (0x40 << 16) | AnalogMode | (command & (0x00000001 | 0x00000002)));
		SITransferCommands();
	}
	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	802057A8
 * Size:	000060
 */
void PADSetSpec(u32 spec)
{
	ASSERTLINE(0x58C, !Initialized);
	__PADSpec = 0;
	switch (spec) {
	case PAD_SPEC_0:
		MakeStatus = SPEC0_MakeStatus;
		break;
	case PAD_SPEC_1:
		MakeStatus = SPEC1_MakeStatus;
		break;
	case PAD_SPEC_2:
	case PAD_SPEC_3:
	case PAD_SPEC_4:
	case PAD_SPEC_5:
		MakeStatus = SPEC2_MakeStatus;
		break;
	}
	Spec = spec;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
u32 PADGetSpec(void)
{
	return Spec;
}

/*
 * --INFO--
 * Address:	80205808
 * Size:	000174
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

/*
 * --INFO--
 * Address:	8020597C
 * Size:	000174
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

/*
 * --INFO--
 * Address:	........
 * Size:	000054
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

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
static u8 ClampU8(u8 var, u8 org)
{
	if (var < org)
		var = org;
	return var -= org;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80205AF0
 * Size:	0003F8
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
		status->substickX    = (s8)(data[1] >> 24);
		status->substickY    = (s8)(data[1] >> 16);
		status->triggerLeft  = (u8)(((data[1] >> 12) & 0x0f) << 4);
		status->triggerRight = (u8)(((data[1] >> 8) & 0x0f) << 4);
		status->analogA      = (u8)(((data[1] >> 4) & 0x0f) << 4);
		status->analogB      = (u8)(((data[1] >> 0) & 0x0f) << 4);
		break;
	case 0x00000100:
		status->substickX    = (s8)(((data[1] >> 28) & 0x0f) << 4);
		status->substickY    = (s8)(((data[1] >> 24) & 0x0f) << 4);
		status->triggerLeft  = (u8)(data[1] >> 16);
		status->triggerRight = (u8)(data[1] >> 8);
		status->analogA      = (u8)(((data[1] >> 4) & 0x0f) << 4);
		status->analogB      = (u8)(((data[1] >> 0) & 0x0f) << 4);
		break;
	case 0x00000200:
		status->substickX    = (s8)(((data[1] >> 28) & 0x0f) << 4);
		status->substickY    = (s8)(((data[1] >> 24) & 0x0f) << 4);
		status->triggerLeft  = (u8)(((data[1] >> 20) & 0x0f) << 4);
		status->triggerRight = (u8)(((data[1] >> 16) & 0x0f) << 4);
		status->analogA      = (u8)(data[1] >> 8);
		status->analogB      = (u8)(data[1] >> 0);
		break;
	case 0x00000300:
		status->substickX    = (s8)(data[1] >> 24);
		status->substickY    = (s8)(data[1] >> 16);
		status->triggerLeft  = (u8)(data[1] >> 8);
		status->triggerRight = (u8)(data[1] >> 0);
		status->analogA      = 0;
		status->analogB      = 0;
		break;
	case 0x00000400:
		status->substickX    = (s8)(data[1] >> 24);
		status->substickY    = (s8)(data[1] >> 16);
		status->triggerLeft  = 0;
		status->triggerRight = 0;
		status->analogA      = (u8)(data[1] >> 8);
		status->analogB      = (u8)(data[1] >> 0);
		break;
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

/*
 * --INFO--
 * Address:	........
 * Size:	000054
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

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
BOOL PADSync(void)
{
	return ResettingBits == 0 && (s32)ResettingChan == 32 && !SIBusy();
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void PADSetAnalogMode(u32 mode)
{
	BOOL enabled;
	u32 mask;

	ASSERTMSGLINE(0x6C9, (mode < 8), "PADSetAnalogMode(): invalid mode");

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

/*
 * --INFO--
 * Address:	80205EE8
 * Size:	00011C
 */
static BOOL OnReset(BOOL f)
{
	BOOL sync;
	static BOOL recalibrated = FALSE;

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

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void __PADDisableXPatch(void)
{
	XPatchBits = 0;
}
