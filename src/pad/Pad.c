#include "Dolphin/os.h"
#include "Dolphin/pad.h"
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
void PADRead(struct PADStatus* status);
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
			frame = 0x41000000;
			SITransfer(ResettingChan, &frame, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		frame = (ResettingChan << 0x16) | 0x4D000000 | (__OSWirelessPadFixMode << 8) & 0x3FFF00u;
		SITransfer(ResettingChan, &frame, 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
		return;
	}
	DoReset();
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,28,31
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0x33B0
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  bne-      .loc_0x19C
	  lwz       r30, 0x2A38(r13)
	  rlwinm    r0,r30,2,0,29
	  add       r3, r31, r0
	  lwz       r29, 0x10(r3)
	  bl        -0x9A34
	  rlwinm    r0,r30,1,0,30
	  add       r3, r3, r0
	  lhz       r30, 0x1C(r3)
	  li        r3, 0
	  bl        -0x96C0
	  rlwinm.   r0,r29,0,11,11
	  rlwinm    r4,r30,8,0,23
	  beq-      .loc_0x74
	  lis       r3, 0xD0
	  subi      r0, r3, 0x100
	  and       r3, r4, r0
	  and       r0, r29, r0
	  cmplw     r3, r0
	  beq-      .loc_0x114

	.loc_0x74:
	  lwz       r0, 0x3360(r13)
	  cntlzw    r0, r0
	  stw       r0, 0x2A38(r13)
	  lwz       r0, 0x2A38(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x238
	  cmpwi     r0, 0x4
	  bge-      .loc_0x238
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  li        r4, 0
	  li        r5, 0xC
	  addi      r3, r3, 0x20
	  bl        -0x201128
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x45F4
	  rlwinm    r0,r3,2,0,29
	  li        r30, 0
	  add       r6, r31, r0
	  stwu      r30, 0x10(r6)
	  addi      r4, r13, 0x3374
	  stwx      r30, r31, r0
	  li        r5, 0x1
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  bl        -0x8C94
	  lwz       r0, 0x2A38(r13)
	  lis       r4, 0x8000
	  lwz       r5, 0x3360(r13)
	  cmpwi     r3, 0
	  srw       r0, r4, r0
	  andc      r0, r5, r0
	  stw       r0, 0x3360(r13)
	  bne-      .loc_0x238
	  li        r0, 0x20
	  stw       r30, 0x3360(r13)
	  stw       r0, 0x2A38(r13)
	  b         .loc_0x238

	.loc_0x114:
	  rlwinm.   r0,r29,0,1,1
	  beq-      .loc_0x160
	  rlwinm.   r0,r29,0,12,12
	  bne-      .loc_0x160
	  rlwinm.   r0,r29,0,13,13
	  bne-      .loc_0x160
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x4248
	  mulli     r0, r3, 0xC
	  add       r6, r31, r0
	  addi      r4, r13, 0x2A4C
	  li        r5, 0x1
	  li        r7, 0xA
	  li        r10, 0
	  li        r9, 0
	  addi      r6, r6, 0x20
	  bl        -0x8D0C
	  b         .loc_0x238

	.loc_0x160:
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x3ED8
	  mulli     r0, r3, 0xC
	  rlwinm    r4,r3,2,0,29
	  add       r4, r31, r4
	  add       r6, r31, r0
	  li        r5, 0x3
	  li        r7, 0x8
	  li        r10, 0
	  li        r9, 0
	  addi      r4, r4, 0x50
	  addi      r6, r6, 0x20
	  bl        -0x8D48
	  b         .loc_0x238

	.loc_0x19C:
	  lwz       r0, 0x3360(r13)
	  cntlzw    r0, r0
	  stw       r0, 0x2A38(r13)
	  lwz       r0, 0x2A38(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x238
	  cmpwi     r0, 0x4
	  bge-      .loc_0x238
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  li        r4, 0
	  li        r5, 0xC
	  addi      r3, r3, 0x20
	  bl        -0x201250
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x45F4
	  rlwinm    r0,r3,2,0,29
	  li        r30, 0
	  add       r6, r31, r0
	  stwu      r30, 0x10(r6)
	  addi      r4, r13, 0x3374
	  stwx      r30, r31, r0
	  li        r5, 0x1
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  bl        -0x8DBC
	  lwz       r0, 0x2A38(r13)
	  lis       r4, 0x8000
	  lwz       r5, 0x3360(r13)
	  cmpwi     r3, 0
	  srw       r0, r4, r0
	  andc      r0, r5, r0
	  stw       r0, 0x3360(r13)
	  bne-      .loc_0x238
	  li        r0, 0x20
	  stw       r30, 0x3360(r13)
	  stw       r0, 0x2A38(r13)

	.loc_0x238:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  mtlr      r0
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  blr
	*/
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
	u32 frame;

	ASSERTLINE(0x2E9, 0 <= ResettingChan && ResettingChan < SI_MAX_CHAN);

	type        = Type[ResettingChan];
	chanBit     = 0x80000000 >> ResettingChan;
	recalibrate = RecalibrateBits & chanBit;
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
			frame = 0x42000000;
			SITransfer(ResettingChan, &frame, 3, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		frame = 0x41000000;
		SITransfer(ResettingChan, &frame, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
		return;
	}
	id = (GetWirelessID(ResettingChan) << 8);
	if ((fix != 0) && (id & 0x100000)) {
		frame = (id & 0xCFFF00) | 0x4E000000 | 0x100000;
		SITransfer(ResettingChan, &frame, 3, &Type[ResettingChan], 3, PADFixCallback, 0);
		return;
	}
	if (type & 0x100000) {
		if ((id & 0xCFFF00) != (type & 0xCFFF00)) {
			if (!(id & 0x100000)) {
				id = (type & 0xCFFF00);
				id |= 0x100000;
				SetWirelessID(ResettingChan, (u16)(id >> 8) & 0xFFFFFF);
			}
			frame = id | 0x4E000000;
			SITransfer(ResettingChan, &frame, 3, &Type[ResettingChan], 3, PADFixCallback, 0);
			return;
		}
		if ((type & 0x40000000) && !(type & 0x80000) && !(type & 0x40000)) {
			frame = 0x41000000;
			SITransfer(ResettingChan, &frame, 1, &Origin[ResettingChan], 0xA, PADOriginCallback, 0);
			return;
		}
		frame = (ResettingChan << 0x16) | 0x4D000000 | ((__OSWirelessPadFixMode << 8) & 0x3FFF00u);
		SITransfer(ResettingChan, &frame, 3, &Origin[ResettingChan], 8, PADProbeCallback, 0);
		return;
	}
	if (type & 0x40000000) {
		u32 id = (type & 0xCFFF00);
		id |= 0x100000;
		SetWirelessID(ResettingChan, (u16)(id >> 8) & 0xFFFFFF);
		frame = id | 0x4E000000;
		SITransfer(ResettingChan, &frame, 3, &Type[ResettingChan], 3, PADFixCallback, 0);
		return;
	}
	SetWirelessID(ResettingChan, 0);
	ProbeWireless(ResettingChan);
	DoReset();
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm.   r5,r4,0,28,31
	  stw       r0, 0x4(r1)
	  lis       r3, 0x803D
	  stwu      r1, -0x60(r1)
	  stmw      r26, 0x48(r1)
	  addi      r31, r3, 0x33B0
	  beq-      .loc_0x34
	  lwz       r0, 0x2A38(r13)
	  li        r4, 0
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  stw       r4, 0x10(r3)

	.loc_0x34:
	  lwz       r29, 0x2A38(r13)
	  lis       r30, 0x8000
	  cmplwi    r5, 0
	  rlwinm    r0,r29,2,0,29
	  add       r3, r31, r0
	  lwz       r28, 0x10(r3)
	  srw       r7, r30, r29
	  not       r6, r7
	  stwx      r28, r31, r0
	  lwz       r5, 0x3368(r13)
	  lwz       r3, 0x3380(r13)
	  and       r4, r5, r6
	  and       r0, r3, r6
	  stw       r4, 0x3368(r13)
	  and       r27, r5, r7
	  stw       r0, 0x3380(r13)
	  and       r26, r3, r7
	  bne-      .loc_0x8C
	  rlwinm    r3,r28,0,3,4
	  subis     r0, r3, 0x800
	  cmplwi    r0, 0
	  beq-      .loc_0x160

	.loc_0x8C:
	  bl        -0x9CDC
	  rlwinm    r0,r29,1,0,30
	  add       r3, r3, r0
	  lhzu      r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xB8
	  li        r0, 0
	  sth       r0, 0x0(r3)
	  li        r3, 0x1
	  bl        -0x9978
	  b         .loc_0xC0

	.loc_0xB8:
	  li        r3, 0
	  bl        -0x9984

	.loc_0xC0:
	  lwz       r0, 0x3360(r13)
	  cntlzw    r0, r0
	  stw       r0, 0x2A38(r13)
	  lwz       r0, 0x2A38(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x71C
	  cmpwi     r0, 0x4
	  bge-      .loc_0x71C
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  li        r4, 0
	  li        r5, 0xC
	  addi      r3, r3, 0x20
	  bl        -0x2013C8
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x45F4
	  rlwinm    r0,r3,2,0,29
	  li        r27, 0
	  add       r6, r31, r0
	  stwu      r27, 0x10(r6)
	  addi      r4, r13, 0x3374
	  stwx      r27, r31, r0
	  li        r5, 0x1
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  bl        -0x8F34
	  lwz       r0, 0x2A38(r13)
	  lis       r4, 0x8000
	  lwz       r5, 0x3360(r13)
	  cmpwi     r3, 0
	  srw       r0, r4, r0
	  andc      r0, r5, r0
	  stw       r0, 0x3360(r13)
	  bne-      .loc_0x71C
	  li        r0, 0x20
	  stw       r27, 0x3360(r13)
	  stw       r0, 0x2A38(r13)
	  b         .loc_0x71C

	.loc_0x160:
	  lwz       r0, 0x2A44(r13)
	  cmplwi    r0, 0x2
	  bge-      .loc_0x238
	  lwz       r0, 0x335C(r13)
	  addi      r3, r29, 0
	  addi      r4, r1, 0x38
	  or        r0, r0, r7
	  stw       r0, 0x335C(r13)
	  bl        -0x9038
	  lwz       r0, 0x2A40(r13)
	  addi      r3, r29, 0
	  oris      r4, r0, 0x40
	  bl        -0x91D4
	  lwz       r3, 0x335C(r13)
	  bl        -0x9158
	  lwz       r0, 0x3360(r13)
	  cntlzw    r0, r0
	  stw       r0, 0x2A38(r13)
	  lwz       r0, 0x2A38(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x71C
	  cmpwi     r0, 0x4
	  bge-      .loc_0x71C
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  li        r4, 0
	  li        r5, 0xC
	  addi      r3, r3, 0x20
	  bl        -0x2014A4
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x45F4
	  rlwinm    r0,r3,2,0,29
	  li        r27, 0
	  add       r6, r31, r0
	  stwu      r27, 0x10(r6)
	  addi      r4, r13, 0x3374
	  stwx      r27, r31, r0
	  li        r5, 0x1
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  bl        -0x9010
	  lwz       r0, 0x2A38(r13)
	  cmpwi     r3, 0
	  lwz       r3, 0x3360(r13)
	  srw       r0, r30, r0
	  andc      r0, r3, r0
	  stw       r0, 0x3360(r13)
	  bne-      .loc_0x71C
	  li        r0, 0x20
	  stw       r27, 0x3360(r13)
	  stw       r0, 0x2A38(r13)
	  b         .loc_0x71C

	.loc_0x238:
	  rlwinm.   r0,r28,0,0,0
	  beq-      .loc_0x248
	  rlwinm.   r0,r28,0,5,5
	  beq-      .loc_0x394

	.loc_0x248:
	  bl        -0x9E98
	  rlwinm    r0,r29,1,0,30
	  add       r3, r3, r0
	  lhzu      r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x274
	  li        r0, 0
	  sth       r0, 0x0(r3)
	  li        r3, 0x1
	  bl        -0x9B34
	  b         .loc_0x27C

	.loc_0x274:
	  li        r3, 0
	  bl        -0x9B40

	.loc_0x27C:
	  rlwinm.   r0,r28,0,7,7
	  bne-      .loc_0x324
	  lwz       r0, 0x3360(r13)
	  cntlzw    r0, r0
	  stw       r0, 0x2A38(r13)
	  lwz       r0, 0x2A38(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x71C
	  cmpwi     r0, 0x4
	  bge-      .loc_0x71C
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  li        r4, 0
	  li        r5, 0xC
	  addi      r3, r3, 0x20
	  bl        -0x20158C
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x45F4
	  rlwinm    r0,r3,2,0,29
	  li        r27, 0
	  add       r6, r31, r0
	  stwu      r27, 0x10(r6)
	  addi      r4, r13, 0x3374
	  stwx      r27, r31, r0
	  li        r5, 0x1
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  bl        -0x90F8
	  lwz       r0, 0x2A38(r13)
	  lis       r4, 0x8000
	  lwz       r5, 0x3360(r13)
	  cmpwi     r3, 0
	  srw       r0, r4, r0
	  andc      r0, r5, r0
	  stw       r0, 0x3360(r13)
	  bne-      .loc_0x71C
	  li        r0, 0x20
	  stw       r27, 0x3360(r13)
	  stw       r0, 0x2A38(r13)
	  b         .loc_0x71C

	.loc_0x324:
	  cmplwi    r27, 0
	  beq-      .loc_0x360
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x4248
	  mulli     r0, r3, 0xC
	  add       r6, r31, r0
	  addi      r4, r13, 0x2A50
	  li        r5, 0x3
	  li        r7, 0xA
	  li        r10, 0
	  li        r9, 0
	  addi      r6, r6, 0x20
	  bl        -0x9160
	  b         .loc_0x71C

	.loc_0x360:
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x4248
	  mulli     r0, r3, 0xC
	  add       r6, r31, r0
	  addi      r4, r13, 0x2A4C
	  li        r5, 0x1
	  li        r7, 0xA
	  li        r10, 0
	  li        r9, 0
	  addi      r6, r6, 0x20
	  bl        -0x9194
	  b         .loc_0x71C

	.loc_0x394:
	  bl        -0x9FE4
	  rlwinm    r0,r29,1,0,30
	  add       r3, r3, r0
	  lhz       r27, 0x1C(r3)
	  li        r3, 0
	  bl        -0x9C70
	  cmpwi     r26, 0
	  rlwinm    r29,r27,8,0,23
	  beq-      .loc_0x408
	  rlwinm.   r0,r29,0,11,11
	  beq-      .loc_0x408
	  lis       r4, 0xD0
	  lwz       r3, 0x2A38(r13)
	  subi      r0, r4, 0x100
	  and       r0, r29, r0
	  rlwinm    r6,r3,2,0,29
	  add       r4, r31, r6
	  oris      r0, r0, 0x4E10
	  lis       r5, 0x8020
	  stwu      r0, 0x60(r4)
	  add       r6, r31, r6
	  addi      r8, r5, 0x43A0
	  li        r5, 0x3
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  addi      r6, r6, 0x10
	  bl        -0x9208
	  b         .loc_0x71C

	.loc_0x408:
	  rlwinm.   r0,r28,0,11,11
	  beq-      .loc_0x530
	  lis       r3, 0xD0
	  subi      r3, r3, 0x100
	  and       r0, r29, r3
	  and       r3, r28, r3
	  cmplw     r0, r3
	  beq-      .loc_0x4A8
	  rlwinm.   r0,r29,0,11,11
	  bne-      .loc_0x46C
	  oris      r29, r3, 0x10
	  lwz       r27, 0x2A38(r13)
	  bl        -0xA088
	  rlwinm    r0,r27,1,0,30
	  add       r4, r3, r0
	  lhzu      r0, 0x1C(r4)
	  rlwinm    r3,r29,24,16,31
	  cmplw     r0, r3
	  beq-      .loc_0x464
	  sth       r3, 0x0(r4)
	  li        r3, 0x1
	  bl        -0x9D24
	  b         .loc_0x46C

	.loc_0x464:
	  li        r3, 0
	  bl        -0x9D30

	.loc_0x46C:
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  oris      r0, r29, 0x4E00
	  rlwinm    r5,r3,2,0,29
	  addi      r8, r4, 0x43A0
	  add       r4, r31, r5
	  stwu      r0, 0x60(r4)
	  add       r6, r31, r5
	  li        r5, 0x3
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  addi      r6, r6, 0x10
	  bl        -0x92A8
	  b         .loc_0x71C

	.loc_0x4A8:
	  rlwinm.   r0,r28,0,1,1
	  beq-      .loc_0x4F4
	  rlwinm.   r0,r28,0,12,12
	  bne-      .loc_0x4F4
	  rlwinm.   r0,r28,0,13,13
	  bne-      .loc_0x4F4
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x4248
	  mulli     r0, r3, 0xC
	  add       r6, r31, r0
	  addi      r4, r13, 0x2A4C
	  li        r5, 0x1
	  li        r7, 0xA
	  li        r10, 0
	  li        r9, 0
	  addi      r6, r6, 0x20
	  bl        -0x92F4
	  b         .loc_0x71C

	.loc_0x4F4:
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x3ED8
	  mulli     r0, r3, 0xC
	  rlwinm    r4,r3,2,0,29
	  add       r4, r31, r4
	  add       r6, r31, r0
	  li        r5, 0x3
	  li        r7, 0x8
	  li        r10, 0
	  li        r9, 0
	  addi      r4, r4, 0x50
	  addi      r6, r6, 0x20
	  bl        -0x9330
	  b         .loc_0x71C

	.loc_0x530:
	  rlwinm.   r0,r28,0,1,1
	  beq-      .loc_0x5BC
	  lis       r3, 0xD0
	  lwz       r27, 0x2A38(r13)
	  subi      r0, r3, 0x100
	  and       r26, r28, r0
	  oris      r26, r26, 0x10
	  bl        -0xA19C
	  rlwinm    r0,r27,1,0,30
	  add       r4, r3, r0
	  lhzu      r0, 0x1C(r4)
	  rlwinm    r3,r26,24,16,31
	  cmplw     r0, r3
	  beq-      .loc_0x578
	  sth       r3, 0x0(r4)
	  li        r3, 0x1
	  bl        -0x9E38
	  b         .loc_0x580

	.loc_0x578:
	  li        r3, 0
	  bl        -0x9E44

	.loc_0x580:
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  oris      r0, r26, 0x4E00
	  rlwinm    r5,r3,2,0,29
	  addi      r8, r4, 0x43A0
	  add       r4, r31, r5
	  stwu      r0, 0x60(r4)
	  add       r6, r31, r5
	  li        r5, 0x3
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  addi      r6, r6, 0x10
	  bl        -0x93BC
	  b         .loc_0x71C

	.loc_0x5BC:
	  lwz       r27, 0x2A38(r13)
	  bl        -0xA210
	  rlwinm    r0,r27,1,0,30
	  add       r3, r3, r0
	  lhzu      r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5EC
	  li        r0, 0
	  sth       r0, 0x0(r3)
	  li        r3, 0x1
	  bl        -0x9EAC
	  b         .loc_0x5F4

	.loc_0x5EC:
	  li        r3, 0
	  bl        -0x9EB8

	.loc_0x5F4:
	  lwz       r29, 0x2A38(r13)
	  lis       r27, 0x8000
	  lwz       r3, 0x335C(r13)
	  addi      r4, r1, 0x1C
	  srw       r5, r27, r29
	  lwz       r0, 0x3364(r13)
	  or        r3, r3, r5
	  stw       r3, 0x335C(r13)
	  mr        r3, r29
	  or        r0, r0, r5
	  stw       r0, 0x3364(r13)
	  bl        -0x94D8
	  rlwinm    r0,r29,2,0,29
	  add       r3, r31, r0
	  lwz       r4, 0x10(r3)
	  rlwinm.   r0,r4,0,6,6
	  bne-      .loc_0x650
	  lhz       r0, 0x30E0(r27)
	  rlwinm    r3,r29,14,0,17
	  oris      r3, r3, 0x4D
	  rlwinm    r0,r0,0,18,31
	  or        r4, r3, r0
	  b         .loc_0x670

	.loc_0x650:
	  rlwinm    r3,r4,0,12,13
	  subis     r0, r3, 0x4
	  cmplwi    r0, 0
	  bne-      .loc_0x668
	  lis       r4, 0x50
	  b         .loc_0x670

	.loc_0x668:
	  rlwinm    r3,r4,0,13,15
	  addis     r4, r3, 0x44

	.loc_0x670:
	  mr        r3, r29
	  bl        -0x96B8
	  lwz       r3, 0x335C(r13)
	  bl        -0x963C
	  lwz       r0, 0x3360(r13)
	  cntlzw    r0, r0
	  stw       r0, 0x2A38(r13)
	  lwz       r0, 0x2A38(r13)
	  cmpwi     r0, 0
	  blt-      .loc_0x71C
	  cmpwi     r0, 0x4
	  bge-      .loc_0x71C
	  mulli     r0, r0, 0xC
	  add       r3, r31, r0
	  li        r4, 0
	  li        r5, 0xC
	  addi      r3, r3, 0x20
	  bl        -0x201988
	  lwz       r3, 0x2A38(r13)
	  lis       r4, 0x8020
	  addi      r8, r4, 0x45F4
	  rlwinm    r0,r3,2,0,29
	  li        r27, 0
	  add       r6, r31, r0
	  stwu      r27, 0x10(r6)
	  addi      r4, r13, 0x3374
	  stwx      r27, r31, r0
	  li        r5, 0x1
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  bl        -0x94F4
	  lwz       r0, 0x2A38(r13)
	  lis       r4, 0x8000
	  lwz       r5, 0x3360(r13)
	  cmpwi     r3, 0
	  srw       r0, r4, r0
	  andc      r0, r5, r0
	  stw       r0, 0x3360(r13)
	  bne-      .loc_0x71C
	  li        r0, 0x20
	  stw       r27, 0x3360(r13)
	  stw       r0, 0x2A38(r13)

	.loc_0x71C:
	  lmw       r26, 0x48(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
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
	if (!Initialized) {
		if (__PADSpec)
			PADSetSpec(__PADSpec);

		if (__PADFixBits == 0xFFFFFFFF) {
			OSTime time = OSGetTime();
			__OSWirelessPadFixMode
			    = (u16)((((time) & 0xffff) + ((time >> 16) & 0xffff) + ((time >> 32) & 0xffff) + ((time >> 48) & 0xffff)) & 0x3fffu);
		}

		Initialized = TRUE;

		PADSetSamplingRate(0);
		OSRegisterResetFunction(&ResetFunctionInfo);
	}
	return PADReset(PAD_CHAN0_BIT | PAD_CHAN1_BIT | PAD_CHAN2_BIT | PAD_CHAN3_BIT);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x803D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r25, 0x1C(r1)
	  addi      r31, r3, 0x33B0
	  lwz       r0, 0x3358(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x124
	  lwz       r3, 0x337C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x34
	  bl        0x794

	.loc_0x34:
	  lwz       r3, 0x3380(r13)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0xC4
	  bl        -0x7C88
	  addi      r25, r4, 0
	  addi      r26, r3, 0
	  li        r5, 0x10
	  bl        0x102E0
	  lis       r5, 0x1
	  subi      r27, r5, 0x1
	  li        r28, 0
	  and       r6, r4, r27
	  and       r4, r25, r27
	  and       r5, r3, r28
	  and       r0, r26, r28
	  addc      r29, r4, r6
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  adde      r30, r0, r5
	  li        r5, 0x20
	  bl        0x102AC
	  and       r4, r4, r27
	  and       r0, r3, r28
	  addc      r29, r4, r29
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  adde      r30, r0, r30
	  li        r5, 0x30
	  bl        0x1028C
	  and       r0, r4, r27
	  addc      r4, r0, r29
	  li        r0, 0x3FFF
	  and       r0, r4, r0
	  lis       r3, 0x8000
	  sth       r0, 0x30E0(r3)

	.loc_0xC4:
	  lis       r5, 0x8000
	  lhz       r4, 0x30E0(r5)
	  li        r0, 0x1
	  li        r3, 0
	  rlwinm    r4,r4,8,10,23
	  oris      r4, r4, 0x4D00
	  stw       r4, 0x50(r31)
	  lhz       r4, 0x30E0(r5)
	  rlwinm    r4,r4,8,10,23
	  oris      r4, r4, 0x4D40
	  stw       r4, 0x54(r31)
	  lhz       r4, 0x30E0(r5)
	  rlwinm    r4,r4,8,10,23
	  oris      r4, r4, 0x4D80
	  stw       r4, 0x58(r31)
	  lhz       r4, 0x30E0(r5)
	  rlwinm    r4,r4,8,10,23
	  oris      r4, r4, 0x4DC0
	  stw       r4, 0x5C(r31)
	  stw       r0, 0x3358(r13)
	  bl        0x544
	  lis       r3, 0x802F
	  subi      r3, r3, 0x74B8
	  bl        -0xB044

	.loc_0x124:
	  lis       r29, 0xF000
	  li        r27, 0
	  bl        -0xC194
	  lwz       r0, 0x3364(r13)
	  mr        r28, r3
	  lwz       r6, 0x336C(r13)
	  lwz       r4, 0x3370(r13)
	  or        r3, r0, r6
	  lwz       r0, 0x2A44(r13)
	  or        r3, r4, r3
	  lwz       r4, 0x3360(r13)
	  andc      r29, r29, r3
	  lwz       r3, 0x335C(r13)
	  or        r5, r4, r29
	  not       r7, r29
	  stw       r5, 0x3360(r13)
	  and       r4, r3, r7
	  and       r3, r6, r7
	  stw       r4, 0x335C(r13)
	  cmplwi    r0, 0x4
	  stw       r3, 0x336C(r13)
	  bne-      .loc_0x188
	  lwz       r0, 0x3368(r13)
	  or        r0, r0, r29
	  stw       r0, 0x3368(r13)

	.loc_0x188:
	  lwz       r3, 0x3360(r13)
	  bl        -0x9AA0
	  lwz       r0, 0x2A38(r13)
	  cmpwi     r0, 0x20
	  bne-      .loc_0x1A4
	  bl        -0x137C
	  mr        r27, r3

	.loc_0x1A4:
	  mr        r3, r28
	  bl        -0xC1E8
	  mr        r3, r27
	  lmw       r25, 0x1C(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
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
void PADRead(PADStatus* status)
{
	s32 chan;
	u32 data[2];
	u32 chanBit;
	u32 sr;
	int chanShift;
	u32 frame;
	int enabled;

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
			sr = SIGetStatus(chan);
			if (sr & (8 << chanShift)) {
				if (WaitingBits & chanBit) {
					status->err = 0;
					memset(status, 0, 0xA);
					if (!(CheckingBits & chanBit)) {
						enabled = OSDisableInterrupts();
						frame   = 0;
						if (SITransfer(chan, &frame, 1, &Type[chan], 3, PADReceiveCheckCallback, 0) != 0) {
							CheckingBits |= chanBit;
						}
						OSRestoreInterrupts(enabled);
					}
				} else {
					PADDisable(chan);
					status->err = -1;
					memset(status, 0, 0xA);
				}
			} else if (!(sr & (0x20 << chanShift))) {
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
				} else if (status->button & 0x2000) {
					status->err = -3;
					memset(status, 0, 0xA);
					frame = 0x41000000;
					SITransfer(chan, &frame, 1, &Origin[chan], 0xA, PADOriginUpdateCallback, 0);
				} else {
					status->err = 0;
					MakeStatus(chan, status, data);
					status->button &= 0xFFFFFF7F;
				}
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x33D0
	  lis       r6, 0x803D
	  stwu      r1, -0x48(r1)
	  lis       r4, 0x8020
	  stmw      r21, 0x1C(r1)
	  li        r23, 0
	  mulli     r5, r23, 0xC
	  add       r25, r0, r5
	  lis       r5, 0x8020
	  rlwinm    r7,r23,2,0,29
	  addi      r0, r6, 0x33C0
	  add       r27, r0, r7
	  addi      r21, r3, 0
	  addi      r31, r4, 0x4364
	  addi      r30, r5, 0x51A8
	  li        r22, 0
	  li        r26, 0
	  lis       r29, 0x8000

	.loc_0x54:
	  lwz       r0, 0x3360(r13)
	  srw       r24, r29, r23
	  subfic    r3, r23, 0x3
	  and.      r0, r0, r24
	  rlwinm    r28,r3,3,0,28
	  bne-      .loc_0x78
	  lwz       r0, 0x2A38(r13)
	  cmpw      r0, r23
	  bne-      .loc_0x94

	.loc_0x78:
	  li        r0, -0x2
	  stb       r0, 0xA(r21)
	  addi      r3, r21, 0
	  li        r4, 0
	  li        r5, 0xA
	  bl        -0x202070
	  b         .loc_0x304

	.loc_0x94:
	  lwz       r0, 0x335C(r13)
	  and.      r0, r0, r24
	  bne-      .loc_0xBC
	  li        r0, -0x1
	  stb       r0, 0xA(r21)
	  addi      r3, r21, 0
	  li        r4, 0
	  li        r5, 0xA
	  bl        -0x202098
	  b         .loc_0x304

	.loc_0xBC:
	  bl        -0x9E20
	  li        r0, 0x8
	  slw       r0, r0, r28
	  and.      r0, r3, r0
	  beq-      .loc_0x1E8
	  lwz       r0, 0x336C(r13)
	  and.      r0, r0, r24
	  beq-      .loc_0x14C
	  li        r0, 0
	  stb       r0, 0xA(r21)
	  addi      r3, r21, 0
	  li        r4, 0
	  li        r5, 0xA
	  bl        -0x2020D4
	  lwz       r0, 0x3370(r13)
	  and.      r0, r0, r24
	  bne-      .loc_0x304
	  bl        -0xC488
	  addi      r28, r3, 0
	  addi      r3, r23, 0
	  addi      r6, r27, 0
	  addi      r8, r30, 0
	  addi      r4, r13, 0x3374
	  li        r5, 0x1
	  li        r7, 0x3
	  li        r10, 0
	  li        r9, 0
	  bl        -0x9C40
	  cmpwi     r3, 0
	  beq-      .loc_0x140
	  lwz       r0, 0x3370(r13)
	  or        r0, r0, r24
	  stw       r0, 0x3370(r13)

	.loc_0x140:
	  mr        r3, r28
	  bl        -0xC4A4
	  b         .loc_0x304

	.loc_0x14C:
	  bl        -0xC4D4
	  addi      r28, r3, 0
	  addi      r3, r24, 0
	  bl        -0x9D8C
	  lwz       r0, 0x335C(r13)
	  not       r6, r24
	  lwz       r4, 0x336C(r13)
	  lwz       r3, 0x3370(r13)
	  and       r5, r0, r6
	  lwz       r0, 0x3364(r13)
	  and       r4, r4, r6
	  and       r3, r3, r6
	  and       r0, r0, r6
	  stw       r5, 0x335C(r13)
	  stw       r4, 0x336C(r13)
	  stw       r3, 0x3370(r13)
	  stw       r0, 0x3364(r13)
	  bl        -0xAAF0
	  addi      r4, r26, 0x1C
	  add       r4, r3, r4
	  lhz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x1BC
	  li        r0, 0
	  sth       r0, 0x0(r4)
	  li        r3, 0x1
	  bl        -0xA78C
	  b         .loc_0x1C4

	.loc_0x1BC:
	  li        r3, 0
	  bl        -0xA798

	.loc_0x1C4:
	  mr        r3, r28
	  bl        -0xC528
	  li        r0, -0x1
	  stb       r0, 0xA(r21)
	  addi      r3, r21, 0
	  li        r4, 0
	  li        r5, 0xA
	  bl        -0x2021C4
	  b         .loc_0x304

	.loc_0x1E8:
	  lwz       r0, 0x3364(r13)
	  and.      r0, r0, r24
	  bne-      .loc_0x204
	  lwz       r0, 0x0(r27)
	  rlwinm.   r0,r0,0,2,2
	  bne-      .loc_0x204
	  or        r22, r22, r24

	.loc_0x204:
	  li        r0, 0x20
	  slw       r0, r0, r28
	  and.      r0, r3, r0
	  bne-      .loc_0x230
	  li        r0, -0x3
	  stb       r0, 0xA(r21)
	  addi      r3, r21, 0
	  li        r4, 0
	  li        r5, 0xA
	  bl        -0x20220C
	  b         .loc_0x304

	.loc_0x230:
	  addi      r3, r23, 0
	  addi      r4, r1, 0xC
	  bl        -0x9E00
	  lwz       r0, 0xC(r1)
	  rlwinm.   r0,r0,0,0,0
	  beq-      .loc_0x264
	  li        r0, -0x3
	  stb       r0, 0xA(r21)
	  addi      r3, r21, 0
	  li        r4, 0
	  li        r5, 0xA
	  bl        -0x202240
	  b         .loc_0x304

	.loc_0x264:
	  lwz       r0, 0x3364(r13)
	  and.      r0, r0, r24
	  beq-      .loc_0x28C
	  li        r0, -0x1
	  stb       r0, 0xA(r21)
	  addi      r3, r21, 0
	  li        r4, 0
	  li        r5, 0xA
	  bl        -0x202268
	  b         .loc_0x304

	.loc_0x28C:
	  lwz       r12, 0x2A48(r13)
	  addi      r3, r23, 0
	  addi      r4, r21, 0
	  mtlr      r12
	  addi      r5, r1, 0xC
	  blrl
	  lhz       r0, 0x0(r21)
	  rlwinm.   r0,r0,0,18,18
	  beq-      .loc_0x2F0
	  li        r0, -0x3
	  stb       r0, 0xA(r21)
	  addi      r3, r21, 0
	  li        r4, 0
	  li        r5, 0xA
	  bl        -0x2022A8
	  addi      r3, r23, 0
	  addi      r6, r25, 0
	  addi      r8, r31, 0
	  addi      r4, r13, 0x2A4C
	  li        r5, 0x1
	  li        r7, 0xA
	  li        r10, 0
	  li        r9, 0
	  bl        -0x9E00
	  b         .loc_0x304

	.loc_0x2F0:
	  li        r0, 0
	  stb       r0, 0xA(r21)
	  lhz       r0, 0x0(r21)
	  rlwinm    r0,r0,0,25,23
	  sth       r0, 0x0(r21)

	.loc_0x304:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x4
	  addi      r27, r27, 0x4
	  addi      r26, r26, 0x2
	  addi      r25, r25, 0xC
	  addi      r21, r21, 0xC
	  blt+      .loc_0x54
	  mr        r3, r22
	  lmw       r21, 0x1C(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
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
