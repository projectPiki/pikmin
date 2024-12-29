#include "Dolphin/os.h"
#include "Dolphin/hw_regs.h"

static SIControl Si = { -1, 0, 0, nullptr, nullptr };
static SIPacket Packet[SI_MAX_CHAN];
static OSAlarm Alarm[SI_MAX_CHAN];

// useful macros.
#define ROUND(n, a) (((u32)(n) + (a)-1) & ~((a)-1))

// forward-declared static functions.
static BOOL __SITransfer(s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback);
static BOOL SIGetResponseRaw(s32 chan);
static void GetTypeCallback(s32 chan, u32 error, OSContext* context);

/*
 * --INFO--
 * Address:	801FAFA8
 * Size:	000020
 */
BOOL SIBusy(void) { return Si.chan != -1 ? TRUE : FALSE; }

/*
 * --INFO--
 * Address:	801FAFC8
 * Size:	000244
 */
static u32 CompleteTransfer(void)
{
	u32 sr;
	u32 i;
	u32 rLen;
	u8* input;
	u32 temp;

	sr                   = __SIRegs[SI_STAT];
	__SIRegs[SI_CC_STAT] = 1 << 31;

	if (Si.chan != -1) {
		input = Si.input;
		rLen  = (Si.inputBytes / 4);
		for (i = 0; i < rLen; i++) {
			*((u32*)input)++ = __SIRegs[i + 0x20];
		}

		rLen = Si.inputBytes & 3;
		if (rLen != 0) {
			temp = __SIRegs[i + 32];
			for (i = 0; i < rLen; i++) {
				*(input++) = temp >> ((3 - i) * 8);
			}
		}
		sr >>= ((3 - Si.chan) * 8);
		sr &= 0xF;
		Si.chan = -1;
	}

	return sr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void SITransferNext(s32 chan)
{
	int i;
	SIPacket* packet;

	for (i = 0; i < SI_MAX_CHAN; ++i) {
		++chan;
		chan %= SI_MAX_CHAN;
		packet = &Packet[chan];
		if (packet->chan != -1 && packet->fire <= OSGetTime()) {
			if (__SITransfer(packet->chan, packet->output, packet->outputBytes, packet->input, packet->inputBytes, packet->callback)) {
				OSCancelAlarm(&Alarm[chan]);
				packet->chan = -1;
			}
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	801FB20C
 * Size:	000118
 */
static void SIIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	s32 chan;
	u32 sr;
	SICallback callback;

	chan        = Si.chan;
	sr          = CompleteTransfer();
	callback    = Si.callback;
	Si.callback = 0;

	SITransferNext(chan);

	if (callback) {
		callback(chan, sr, context);
	}
}

/*
 * --INFO--
 * Address:	801FB324
 * Size:	000074
 */
void SIInit(void)
{
	Packet[0].chan = Packet[1].chan = Packet[2].chan = Packet[3].chan = -1;

	__SIRegs[SI_POLL] = 0;

	while (__SIRegs[SI_CC_STAT] & 1) {
		;
	}

	__SIRegs[SI_CC_STAT] = 0x80000000;

	__OSSetInterruptHandler(__OS_INTERRUPT_PI_SI, SIIntrruptHandler);
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_SI);
}

/*
 * --INFO--
 * Address:	801FB398
 * Size:	000208
 */
static BOOL __SITransfer(s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback)
{
	BOOL enabled;
	u32 rLen;
	u32 i;
	u32 sr;
	SIComm comcsr;

	enabled = OSDisableInterrupts();
	if (Si.chan != -1) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	sr = __SIRegs[SI_STAT];
	sr &= (0xF000000) >> (8 * chan);
	__SIRegs[SI_STAT] = sr;

	Si.chan       = chan;
	Si.callback   = callback;
	Si.inputBytes = inputBytes;
	Si.input      = input;

	rLen = ROUND(outputBytes, 4) / 4;
	for (i = 0; i < rLen; i++) {
		__SIRegs[SI_IO_BUFFER + i] = ((u32*)output)[i];
	}

	comcsr.val            = 0;
	comcsr.flags.tcint    = 1;
	comcsr.flags.tcintmsk = callback ? 1 : 0;
	comcsr.flags.outlngth = (outputBytes == SI_MAX_COMCSR_OUTLNGTH) ? 0 : outputBytes;
	comcsr.flags.inlngth  = (inputBytes == SI_MAX_COMCSR_INLNGTH) ? 0 : inputBytes;
	comcsr.flags.channel  = chan;
	comcsr.flags.tstart   = 1;
	__SIRegs[SI_CC_STAT]  = comcsr.val;

	OSRestoreInterrupts(enabled);

	return TRUE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void SISync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FB5A0
 * Size:	000010
 */
u32 SIGetStatus(s32) { return __SIRegs[SI_STAT]; }

/*
 * --INFO--
 * Address:	801FB5B0
 * Size:	000014
 */
void SISetCommand(s32 chan, u32 command) { __SIRegs[3 * chan] = command; }

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void SIGetCommand(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FB5C4
 * Size:	000010
 */
void SITransferCommands(void) { __SIRegs[SI_STAT] = 0x80000000; }

/*
 * --INFO--
 * Address:	801FB5D4
 * Size:	000060
 */
u32 SISetXY(u32 x, u32 y)
{
	u32 poll;
	BOOL enabled;

	poll = x << 16;
	poll |= y << 8;

	enabled = OSDisableInterrupts();

	Si.poll &= ~(0x03FF0000 | 0x0000FF00);
	Si.poll |= poll;
	poll = Si.poll;

	OSRestoreInterrupts(enabled);
	return poll;
}

/*
 * --INFO--
 * Address:	801FB634
 * Size:	00009C
 */
u32 SIEnablePolling(u32 poll)
{
	BOOL enabled;
	u32 en;

	if (poll == 0) {
		return Si.poll;
	}

	enabled = OSDisableInterrupts();

	poll >>= (31 - 7);
	en = poll & 0xF0;

	poll &= (en >> 4) | 0x03FFFFF0;

	poll &= ~0x03FFFF00;

	Si.poll &= ~(en >> 4);

	Si.poll |= poll;

	poll = Si.poll;

	SITransferCommands();

	__SIRegs[SI_POLL] = poll;

	OSRestoreInterrupts(enabled);

	return poll;
}

/*
 * --INFO--
 * Address:	801FB6D0
 * Size:	00006C
 */
u32 SIDisablePolling(u32 poll)
{
	BOOL enabled;

	if (poll == 0) {
		return Si.poll;
	}

	enabled = OSDisableInterrupts();

	poll >>= (31 - 7);
	poll &= 0xF0;

	poll = Si.poll & ~poll;

	__SIRegs[SI_POLL] = poll;
	Si.poll           = poll;

	OSRestoreInterrupts(enabled);
	return poll;
}

/*
 * --INFO--
 * Address:	801FB73C
 * Size:	000024
 */
void SIGetResponse(s32 chan, void* data)
{
	((u32*)data)[0] = __SIRegs[chan * 3 + 1];
	((u32*)data)[1] = __SIRegs[chan * 3 + 2];
}

/*
 * --INFO--
 * Address:	801FB760
 * Size:	00008C
 */
static void AlarmHandler(OSAlarm* alarm, OSContext* context)
{
	s32 chan;
	SIPacket* packet;

	chan   = alarm - Alarm;
	packet = &Packet[chan];
	if (packet->chan != -1) {
		if (__SITransfer(packet->chan, packet->output, packet->outputBytes, packet->input, packet->inputBytes, packet->callback)) {

			packet->chan = -1;
		}
	}
}

/*
 * --INFO--
 * Address:	801FB7EC
 * Size:	00013C
 */
BOOL SITransfer(s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback, OSTime delay)
{
	BOOL enabled;
	SIPacket* packet = &Packet[chan];
	OSTime now;

	enabled = OSDisableInterrupts();
	if (packet->chan != -1) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	now = OSGetTime();
	if (delay == 0) {
		delay = now;
	}

	if (now < delay) {
		OSSetAbsAlarm(&Alarm[chan], delay, AlarmHandler);
	} else if (__SITransfer(chan, output, outputBytes, input, inputBytes, callback)) {
		OSRestoreInterrupts(enabled);
		return TRUE;
	}

	packet->chan        = chan;
	packet->output      = output;
	packet->outputBytes = outputBytes;
	packet->input       = input;
	packet->inputBytes  = inputBytes;
	packet->callback    = callback;
	packet->fire        = delay;

	OSRestoreInterrupts(enabled);
	return TRUE;
}
