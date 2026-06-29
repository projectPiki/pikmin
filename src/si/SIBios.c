// This file also implements "OSSerial.c" (`OS_BUILD_VERSION < 20011217L`). Don't break compatibility!

#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include "Dolphin/si.h"
#include "Dolphin/vi.h"
#include <stddef.h>

// For ease of implementing multiple revisions, this function that was renamed goes by its final
// name everywhere in this file and is silently renamed for older revisions via the below macro.
#if OS_BUILD_VERSION >= 20011002L
#else
#define SIInterruptHandler SIIntrruptHandler
#endif

static SIControl Si = { -1, 0, 0, NULL, NULL };
static SIPacket Packet[SI_MAX_CHAN];
static OSAlarm Alarm[SI_MAX_CHAN];

#if OS_BUILD_VERSION >= 20011002L

static u32 Type[SI_MAX_CHAN] = {
	SI_ERROR_NO_RESPONSE,
	SI_ERROR_NO_RESPONSE,
	SI_ERROR_NO_RESPONSE,
	SI_ERROR_NO_RESPONSE,
};

static OSTime TypeTime[SI_MAX_CHAN];
static OSTime XferTime[SI_MAX_CHAN];

static SITypeAndStatusCallback TypeCallback[SI_MAX_CHAN][4];
static __OSInterruptHandler RDSTHandler[4];

u32 __PADFixBits;

static BOOL InputBufferValid[SI_MAX_CHAN];
static u32 InputBuffer[SI_MAX_CHAN][2];
static volatile u32 InputBufferVcount[SI_MAX_CHAN];

#endif

static BOOL __SITransfer(s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback);
static BOOL SIGetResponseRaw(s32 chan);
static void GetTypeCallback(s32 chan, u32 error, OSContext* context);

/**
 * @TODO: Documentation
 */
BOOL SIBusy(void)
{
	return Si.chan != -1 ? TRUE : FALSE;
}

#if OS_BUILD_VERSION >= 20011002L

/**
 * @TODO: Documentation
 */
BOOL SIIsChanBusy(s32 chan)
{
	return (Packet[chan].chan != -1 || Si.chan == chan);
}

/**
 * @TODO: Documentation
 */
static void SIClearTCInterrupt(void)
{
	u32 reg;

	reg = __SIRegs[SI_CC_STAT];
	reg |= 0x80000000;
	reg &= ~0x00000001;
	__SIRegs[SI_CC_STAT] = reg;
}

#endif

/**
 * @TODO: Documentation
 */
static u32 CompleteTransfer(void)
{
	u32 sr;
	u32 i;
	u32 rLen;
	u8* input;
	u32 temp;

	sr = __SIRegs[SI_STAT];

#if OS_BUILD_VERSION >= 20011002L
	SIClearTCInterrupt();
#else
	__SIRegs[SI_CC_STAT] = 1 << 31;
#endif

	if (Si.chan != -1) {
#if OS_BUILD_VERSION >= 20011002L
		XferTime[Si.chan] = __OSGetSystemTime();
#endif

		input = Si.input;
		rLen  = Si.inputBytes / 4;
		for (i = 0; i < rLen; i++) {
			*(u32*)input = __SIRegs[SI_IO_BUFFER + i];
			input += 4;
		}

		rLen = Si.inputBytes & 3;
		if (rLen != 0) {
			temp = __SIRegs[SI_IO_BUFFER + i];
			for (i = 0; i < rLen; i++) {
				*input++ = temp >> (8 * (SI_MAX_CHAN - 1 - i));
			}
		}

#if OS_BUILD_VERSION >= 20011002L
		if (__SIRegs[SI_CC_STAT] & 0x20000000) {
			sr >>= 8 * (SI_MAX_CHAN - 1 - Si.chan);
			sr &= 0xf;

			if ((sr & SI_ERROR_NO_RESPONSE) && !(Type[Si.chan] & SI_ERROR_BUSY)) {
				Type[Si.chan] = SI_ERROR_NO_RESPONSE;
			}
			if (sr == 0) {
				sr = SI_ERROR_COLLISION;
			}
		} else {
			TypeTime[Si.chan] = __OSGetSystemTime();
			sr                = 0;
		}
#else
		sr >>= 8 * (SI_MAX_CHAN - 1 - Si.chan);
		sr &= 0xF;
#endif
		Si.chan = -1;
	}
	return sr;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
static void SITransferNext(s32 chan)
{
	int i;
	SIPacket* packet;

	for (i = 0; i < SI_MAX_CHAN; ++i) {
		++chan;
		chan %= SI_MAX_CHAN;
		packet = &Packet[chan];
#if OS_BUILD_VERSION >= 20011002L
		if (packet->chan != -1 && packet->fire <= __OSGetSystemTime())
#else
		if (packet->chan != -1 && packet->fire <= OSGetTime())
#endif
		{
			if (__SITransfer(packet->chan, packet->output, packet->outputBytes, packet->input, packet->inputBytes, packet->callback)) {
				OSCancelAlarm(&Alarm[chan]);
				packet->chan = -1;
			}
			break;
		}
	}
}

/**
 * @TODO: Documentation
 */
static void SIInterruptHandler(__OSInterrupt interrupt, OSContext* context)
{
#if OS_BUILD_VERSION >= 20011002L
	u32 reg;

	reg = __SIRegs[SI_CC_STAT];

	if ((reg & 0xc0000000) == 0xc0000000) {
#endif

		s32 chan;
		u32 sr;
		SICallback callback;

		chan        = Si.chan;
		sr          = CompleteTransfer();
		callback    = Si.callback;
		Si.callback = NULL;

		SITransferNext(chan);

		if (callback) {
			callback(chan, sr, context);
		}

#if OS_BUILD_VERSION >= 20011002L
		sr = __SIRegs[SI_STAT];
		sr &= 0xf000000 >> (8 * chan);
		__SIRegs[SI_STAT] = sr;

		if (Type[chan] == SI_ERROR_BUSY && !SIIsChanBusy(chan)) {
			static u32 cmdTypeAndStatus = 0 << 24;
			SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3, GetTypeCallback, OSMicrosecondsToTicks(65));
		}
	}

	if ((reg & 0x18000000) == 0x18000000) {

		int i;
		u32 vcount;
		u32 x;

		vcount = VIGetCurrentLine() + 1;
		x      = (Si.poll & 0x03ff0000) >> 16;

		for (i = 0; i < SI_MAX_CHAN; ++i) {
			if (SIGetResponseRaw(i)) {
				InputBufferVcount[i] = vcount;
			}
		}

		for (i = 0; i < SI_MAX_CHAN; ++i) {
			if (!(Si.poll & SI_CHAN_BIT(31 - 7 + i))) {
				continue;
			}
			if (InputBufferVcount[i] == 0 || InputBufferVcount[i] + (x / 2) < vcount) {
				return;
			}
		}

		for (i = 0; i < SI_MAX_CHAN; ++i) {
			InputBufferVcount[i] = 0;
		}

		for (i = 0; i < 4; ++i) {
			if (RDSTHandler[i]) {
				RDSTHandler[i](interrupt, context);
			}
		}
	}
#endif
}

#if OS_BUILD_VERSION >= 20011002L

/**
 * @TODO: Documentation
 */
static BOOL SIEnablePollingInterrupt(BOOL enable)
{
	BOOL enabled;
	BOOL rc;
	u32 reg;
	int i;

	enabled = OSDisableInterrupts();
	reg     = __SIRegs[SI_CC_STAT];
	rc      = (reg & 0x08000000) ? TRUE : FALSE;
	if (enable) {
		reg |= 0x08000000;
		for (i = 0; i < SI_MAX_CHAN; ++i) {
			InputBufferVcount[i] = 0;
		}
	} else {
		reg &= ~0x08000000;
	}
	reg &= ~0x80000001;
	__SIRegs[SI_CC_STAT] = reg;
	OSRestoreInterrupts(enabled);
	return rc;
}

/**
 * @TODO: Documentation
 */
BOOL SIRegisterPollingHandler(__OSInterruptHandler handler)
{
	BOOL enabled;
	int i;

	enabled = OSDisableInterrupts();
	for (i = 0; i < 4; ++i) {
		if (RDSTHandler[i] == handler) {
			OSRestoreInterrupts(enabled);
			return TRUE;
		}
	}
	for (i = 0; i < 4; ++i) {
		if (RDSTHandler[i] == 0) {
			RDSTHandler[i] = handler;
			SIEnablePollingInterrupt(TRUE);
			OSRestoreInterrupts(enabled);
			return TRUE;
		}
	}
	OSRestoreInterrupts(enabled);
	return FALSE;
}

/**
 * @TODO: Documentation
 */
BOOL SIUnregisterPollingHandler(__OSInterruptHandler handler)
{
	BOOL enabled;
	int i;

	enabled = OSDisableInterrupts();
	for (i = 0; i < 4; ++i) {
		if (RDSTHandler[i] == handler) {
			RDSTHandler[i] = 0;
			for (i = 0; i < 4; ++i) {
				if (RDSTHandler[i]) {
					break;
				}
			}
			if (i == 4) {
				SIEnablePollingInterrupt(FALSE);
			}
			OSRestoreInterrupts(enabled);
			return TRUE;
			break;
		}
	}
	OSRestoreInterrupts(enabled);
	return FALSE;
}

#endif

/**
 * @TODO: Documentation
 */
void SIInit(void)
{
	Packet[0].chan = Packet[1].chan = Packet[2].chan = Packet[3].chan = -1;

#if OS_BUILD_VERSION >= 20011217L
	Si.poll = 0;
	SISetSamplingRate(0);
#else
	__SIRegs[SI_POLL] = 0;
#endif

	while (__SIRegs[SI_CC_STAT] & 1)
		;

	__SIRegs[SI_CC_STAT] = 0x80000000;

	__OSSetInterruptHandler(__OS_INTERRUPT_PI_SI, SIInterruptHandler);
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_SI);

#if OS_BUILD_VERSION >= 20011002L
	SIGetType(0);
	SIGetType(1);
	SIGetType(2);
	SIGetType(3);
#endif
}

#define ROUND(n, a) (((u32)(n) + (a) - 1) & ~((a) - 1))

/**
 * @TODO: Documentation
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
	sr &= (0xf000000) >> (8 * chan);
	__SIRegs[SI_STAT] = sr;

	Si.chan       = chan;
	Si.callback   = callback;
	Si.inputBytes = inputBytes;
	Si.input      = input;

	rLen = ROUND(outputBytes, 4) / 4;
	for (i = 0; i < rLen; i++) {
		__SIRegs[SI_IO_BUFFER + i] = ((u32*)output)[i];
	}

#if OS_BUILD_VERSION >= 20011002L
	comcsr.val = __SIRegs[SI_CC_STAT];
#else
	comcsr.val = 0;
#endif
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000108
 */
void SISync(void)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 */
#if OS_BUILD_VERSION >= 20011002L && OS_BUILD_VERSION < 20011112L
u32 SIGetStatus(void)
#else
u32 SIGetStatus(s32 chan)
#endif
{
#if OS_BUILD_VERSION >= 20011112L
	BOOL enabled;
	u32 sr;
	int chanShift;

	enabled   = OSDisableInterrupts();
	sr        = __SIRegs[SI_STAT];
	chanShift = 8 * (SI_MAX_CHAN - 1 - chan);
	sr >>= chanShift;
	if (sr & SI_ERROR_NO_RESPONSE) {
		if (!(Type[chan] & SI_ERROR_BUSY)) {
			Type[chan] = SI_ERROR_NO_RESPONSE;
		}
	}
	OSRestoreInterrupts(enabled);
	return sr;
#elif OS_BUILD_VERSION >= 20011002L
	FORCE_DONT_INLINE; // TODO: Something else
#else
	return __SIRegs[SI_STAT];
#endif
}

/**
 * @TODO: Documentation
 */
void SISetCommand(s32 chan, u32 command)
{
	__SIRegs[3 * chan] = command;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000014 (Matching by size)
 */
u32 SIGetCommand(s32 chan)
{
	return __SIRegs[3 * chan];
}

/**
 * @TODO: Documentation
 */
void SITransferCommands(void)
{
	__SIRegs[SI_STAT] = 0x80000000;
}

/**
 * @TODO: Documentation
 */
u32 SISetXY(u32 x, u32 y)
{
	u32 poll;
	BOOL enabled;

	poll = x << 16;
	poll |= y << 8;

	enabled = OSDisableInterrupts();
	Si.poll &= ~(0x03ff0000 | 0x0000ff00);
	Si.poll |= poll;
	poll = Si.poll;
#if OS_BUILD_VERSION >= 20011217L
	__SIRegs[SI_POLL] = poll;
#endif
	OSRestoreInterrupts(enabled);
	return poll;
}

/**
 * @TODO: Documentation
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
	en = poll & 0xf0;

	poll &= (en >> 4) | 0x03fffff0;

	poll &= ~0x03ffff00;

	Si.poll &= ~(en >> 4);

	Si.poll |= poll;

	poll = Si.poll;

	SITransferCommands();

	__SIRegs[SI_POLL] = poll;

	OSRestoreInterrupts(enabled);

	return poll;
}

/**
 * @TODO: Documentation
 */
u32 SIDisablePolling(u32 poll)
{
	BOOL enabled;

	if (poll == 0) {
		return Si.poll;
	}

	enabled = OSDisableInterrupts();

	poll >>= (31 - 7);
	poll &= 0xf0;

	poll = Si.poll & ~poll;

	__SIRegs[SI_POLL] = poll;
	Si.poll           = poll;

	OSRestoreInterrupts(enabled);
	return poll;
}

#if OS_BUILD_VERSION >= 20011002L

/**
 * @TODO: Documentation
 */
static BOOL SIGetResponseRaw(s32 chan)
{
	u32 sr;

#if OS_BUILD_VERSION >= 20011002L && OS_BUILD_VERSION < 20011112L
	int chanShift;
	sr        = SIGetStatus();
	chanShift = 8 * (SI_MAX_CHAN - 1 - chan);
	if (sr & (SI_ERROR_RDST << chanShift))
#else
	sr = SIGetStatus(chan);
	if (sr & SI_ERROR_RDST)
#endif
	{
		InputBuffer[chan][0]   = __SIRegs[3 * chan + 1];
		InputBuffer[chan][1]   = __SIRegs[3 * chan + 2];
		InputBufferValid[chan] = TRUE;
		return TRUE;
	}
	return FALSE;
}

#endif

/**
 * @TODO: Documentation
 */
#if OS_BUILD_VERSION >= 20011002L
BOOL SIGetResponse(s32 chan, void* data)
#else
void SIGetResponse(s32 chan, void* data)
#endif
{
#if OS_BUILD_VERSION >= 20011002L
	BOOL rc;
	BOOL enabled;

	enabled = OSDisableInterrupts();
	SIGetResponseRaw(chan);
	rc                     = InputBufferValid[chan];
	InputBufferValid[chan] = FALSE;
	if (rc) {
		((u32*)data)[0] = InputBuffer[chan][0];
		((u32*)data)[1] = InputBuffer[chan][1];
	}
	OSRestoreInterrupts(enabled);
	return rc;
#else
	((u32*)data)[0] = __SIRegs[chan * 3 + 1];
	((u32*)data)[1] = __SIRegs[chan * 3 + 2];
#endif
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
BOOL SITransfer(s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback, OSTime delay)
{
	BOOL enabled;
	SIPacket* packet;
	OSTime now;
#if OS_BUILD_VERSION >= 20011002L
	OSTime fire;
#endif

	packet  = &Packet[chan];
	enabled = OSDisableInterrupts();

#if OS_BUILD_VERSION >= 20011002L
	if (packet->chan != -1 || Si.chan == chan)
#else
	if (packet->chan != -1)
#endif
	{
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

#if OS_BUILD_VERSION >= 20011002L
	now = __OSGetSystemTime();
	if (delay == 0) {
		fire = now;
	} else {
		fire = XferTime[chan] + delay;
	}
	if (now < fire) {
		delay = fire - now;
		OSSetAlarm(&Alarm[chan], delay, AlarmHandler);
	}
#else
	now = OSGetTime();
	if (delay == 0) {
		delay = now;
	}
	if (now < delay) {
		OSSetAbsAlarm(&Alarm[chan], delay, AlarmHandler);
	}
#endif
	else if (__SITransfer(chan, output, outputBytes, input, inputBytes, callback)) {
		OSRestoreInterrupts(enabled);
		return TRUE;
	}

	packet->chan        = chan;
	packet->output      = output;
	packet->outputBytes = outputBytes;
	packet->input       = input;
	packet->inputBytes  = inputBytes;
	packet->callback    = callback;
#if OS_BUILD_VERSION >= 20011002L
	packet->fire = fire;
#else
	packet->fire = delay;
#endif

	OSRestoreInterrupts(enabled);
	return TRUE;
}

#if OS_BUILD_VERSION >= 20011002L

/**
 * @TODO: Documentation
 */
static void CallTypeAndStatusCallback(s32 chan, u32 type)
{
	SITypeAndStatusCallback callback;
	int i;

	for (i = 0; i < 4; ++i) {
		callback = TypeCallback[chan][i];
		if (callback) {
			TypeCallback[chan][i] = NULL;
			callback(chan, type);
		}
	}
}

/**
 * @TODO: Documentation
 */
static void GetTypeCallback(s32 chan, u32 error, OSContext* context)
{
	static u32 cmdFixDevice[SI_MAX_CHAN];
	u32 type;
	u32 chanBit;
	BOOL fix;
	u32 id;

	Type[chan] &= ~SI_ERROR_BUSY;
	Type[chan] |= error;
	TypeTime[chan] = __OSGetSystemTime();

	type = Type[chan];

	chanBit = SI_CHAN_BIT(chan);
	fix     = (BOOL)(__PADFixBits & chanBit);
	__PADFixBits &= ~chanBit;

	if ((error & (SI_ERROR_UNDER_RUN | SI_ERROR_OVER_RUN | SI_ERROR_NO_RESPONSE | SI_ERROR_COLLISION))
	    || (type & SI_TYPE_MASK) != SI_TYPE_DOLPHIN || !(type & SI_GC_WIRELESS) || (type & SI_WIRELESS_IR)) {
		OSSetWirelessID(chan, 0);
		CallTypeAndStatusCallback(chan, Type[chan]);
		return;
	}

	id = (u32)(OSGetWirelessID(chan) << 8);

	if (fix && (id & SI_WIRELESS_FIX_ID)) {
		cmdFixDevice[chan] = 0x4Eu << 24 | (id & SI_WIRELESS_TYPE_ID) | SI_WIRELESS_FIX_ID;
		Type[chan]         = SI_ERROR_BUSY;
		SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
		return;
	}

	if (type & SI_WIRELESS_FIX_ID) {
		if ((id & SI_WIRELESS_TYPE_ID) != (type & SI_WIRELESS_TYPE_ID)) {
			if (!(id & SI_WIRELESS_FIX_ID)) {
				id = type & SI_WIRELESS_TYPE_ID;
				id |= SI_WIRELESS_FIX_ID;
				OSSetWirelessID(chan, (u16)((id >> 8) & 0xffff));
			}

			cmdFixDevice[chan] = 0x4E << 24 | id;
			Type[chan]         = SI_ERROR_BUSY;
			SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
			return;
		}
	} else if (type & SI_WIRELESS_RECEIVED) {
		id = type & SI_WIRELESS_TYPE_ID;
		id |= SI_WIRELESS_FIX_ID;

		OSSetWirelessID(chan, (u16)((id >> 8) & 0xffff));

		cmdFixDevice[chan] = 0x4E << 24 | id;
		Type[chan]         = SI_ERROR_BUSY;
		SITransfer(chan, &cmdFixDevice[chan], 3, &Type[chan], 3, GetTypeCallback, 0);
		return;
	} else {
		OSSetWirelessID(chan, 0);
	}

	CallTypeAndStatusCallback(chan, Type[chan]);
}

/**
 * @TODO: Documentation
 */
u32 SIGetType(s32 chan)
{
	static u32 cmdTypeAndStatus;
	BOOL enabled;
	u32 type;
	OSTime diff;

	enabled = OSDisableInterrupts();

	type = Type[chan];
	diff = __OSGetSystemTime() - TypeTime[chan];
	if (Si.poll & (0x80 >> chan)) {
		if (type != SI_ERROR_NO_RESPONSE) {
			TypeTime[chan] = __OSGetSystemTime();
			OSRestoreInterrupts(enabled);
			return type;
		} else {
			type = Type[chan] = SI_ERROR_BUSY;
		}
	} else if (diff <= OSMillisecondsToTicks(50) && type != SI_ERROR_NO_RESPONSE) {
		OSRestoreInterrupts(enabled);
		return type;
	} else if (diff <= OSMillisecondsToTicks(75)) {
		Type[chan] = SI_ERROR_BUSY;
	} else {
		type = Type[chan] = SI_ERROR_BUSY;
	}
	TypeTime[chan] = __OSGetSystemTime();

	SITransfer(chan, &cmdTypeAndStatus, 1, &Type[chan], 3, GetTypeCallback, OSMicrosecondsToTicks(65));

	OSRestoreInterrupts(enabled);
	return type;
}

/**
 * @TODO: Documentation
 */
u32 SIGetTypeAsync(s32 chan, SITypeAndStatusCallback callback)
{
	BOOL enabled;
	u32 type;

	enabled = OSDisableInterrupts();
	type    = SIGetType(chan);
	if (Type[chan] & SI_ERROR_BUSY) {
		int i;

		for (i = 0; i < 4; ++i) {
			if (TypeCallback[chan][i] == callback) {
				break;
			}
			if (TypeCallback[chan][i] == NULL) {
				TypeCallback[chan][i] = callback;
				break;
			}
		}
	} else {
		callback(chan, type);
	}
	OSRestoreInterrupts(enabled);
	return type;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000124
 */
u32 SIDecodeType(u32 type)
{
	TRAP_UNIMPLEMENTED;
	FORCE_DONT_INLINE;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000024
 */
u32 SIProbe(s32 chan)
{
	TRAP_UNIMPLEMENTED;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000158 (`OS_BUILD_VERSION >= 20011217L`)
 * @note UNUSED Size: 000140 (`OS_BUILD_VERSION >= 20011112L`)
 * @note UNUSED Size: 000128
 */
const char* SIGetTypeString(u32 type)
{
	switch (SIDecodeType(type)) {
	case SI_ERROR_NO_RESPONSE:
	{
		return "No response";
	}
	case SI_N64_CONTROLLER:
	{
		return "N64 controller";
	}
	case SI_N64_MIC:
	{
		return "N64 microphone";
	}
	case SI_N64_KEYBOARD:
	{
		return "N64 keyboard";
	}
	case SI_N64_MOUSE:
	{
		return "N64 mouse";
	}
	case SI_GBA:
	{
		return "GameBoy Advance";
	}
	case SI_GC_CONTROLLER:
	{
		return "Standard controller";
	}
	case SI_GC_RECEIVER:
	{
		return "Wireless receiver";
	}
	case SI_GC_WAVEBIRD:
	{
		return "WaveBird controller";
	}
#if OS_BUILD_VERSION >= 20011112L
	case SI_GC_KEYBOARD:
	{
		return "Keyboard";
	}
#endif
#if OS_BUILD_VERSION >= 20011217L
	case SI_GC_STEERING:
	{
		return "Steering";
	}
#endif
	}
}

#endif
