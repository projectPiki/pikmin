#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"

static SIControl Si = { -1, 0, 0, NULL, NULL };
static SIPacket Packet[SI_MAX_CHAN];
static OSAlarm Alarm[SI_MAX_CHAN];

// useful macros.
#define ROUND(n, a) (((u32)(n) + (a) - 1) & ~((a) - 1))

// forward-declared static functions.
static BOOL __SITransfer(s32 chan, void* output, u32 outputBytes, void* input, u32 inputBytes, SICallback callback);
static BOOL SIGetResponseRaw(s32 chan);
static void GetTypeCallback(s32 chan, u32 error, OSContext* context);

#if defined(VERSION_G98E01_PIKIDEMO)
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
static vu32 InputBufferVcount[SI_MAX_CHAN];

#endif

/**
 * @TODO: Documentation
 */
BOOL SIBusy(void)
{
	return Si.chan != -1 ? TRUE : FALSE;
}

#if defined(VERSION_G98E01_PIKIDEMO)
BOOL SIIsChanBusy(s32 chan)
{
	return (Packet[chan].chan != -1 || Si.chan == chan);
}

static void SIClearTCInterrupt()
{
	u32 reg;

	reg = __SIRegs[13];
	reg |= 0x80000000;
	reg &= ~0x00000001;
	__SIRegs[13] = reg;
}
#endif

/**
 * @TODO: Documentation
 */
static u32 CompleteTransfer(void)
{
#if defined(VERSION_G98E01_PIKIDEMO)

	u32 sr;
	u32 i;
	u32 rLen;
	u8* input;

	sr = __SIRegs[14];
	SIClearTCInterrupt();

	if (Si.chan != -1) {
		XferTime[Si.chan] = __OSGetSystemTime();

		input = Si.input;

		rLen = Si.inputBytes / 4;
		for (i = 0; i < rLen; i++) {
			*(u32*)input = __SIRegs[32 + i];
			input += 4;
		}

		rLen = Si.inputBytes & 3;
		if (rLen) {
			u32 temp = __SIRegs[32 + i];
			for (i = 0; i < rLen; i++) {
				*input++ = (u8)((temp >> ((3 - i) * 8)) & 0xff);
			}
		}

		if (__SIRegs[13] & 0x20000000) {
			sr >>= 8 * (3 - Si.chan);
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

		Si.chan = -1;
	}
	return sr;

#else
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
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
void SITransferNext(s32 chan)
{
	int i;
	SIPacket* packet;

	for (i = 0; i < SI_MAX_CHAN; ++i) {
		++chan;
		chan %= SI_MAX_CHAN;
		packet = &Packet[chan];
#if defined(VERSION_G98E01_PIKIDEMO)
		if (packet->chan != -1 && packet->fire <= __OSGetSystemTime()) {
#else
		if (packet->chan != -1 && packet->fire <= OSGetTime()) {
#endif
			if (__SITransfer(packet->chan, packet->output, packet->outputBytes, packet->input, packet->inputBytes, packet->callback)) {
				OSCancelAlarm(&Alarm[chan]);
				packet->chan = -1;
			}
			break;
		}
	}
}

#if defined(VERSION_G98E01_PIKIDEMO)
static void SIInterruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	u32 reg;

	reg = __SIRegs[13];

	if ((reg & 0xc0000000) == 0xc0000000) {
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

		sr = __SIRegs[14];
		sr &= 0xf000000 >> (8 * chan);
		__SIRegs[14] = sr;

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
			if (!(Si.poll & (SI_CHAN0_BIT >> (31 - 7 + i)))) {
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
}

static BOOL SIEnablePollingInterrupt(BOOL enable)
{
	BOOL enabled;
	BOOL rc;
	u32 reg;
	int i;

	enabled = OSDisableInterrupts();
	reg     = __SIRegs[13];
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
	__SIRegs[13] = reg;
	OSRestoreInterrupts(enabled);
	return rc;
}

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

/**
 * @TODO: Documentation
 */
void SIInit(void)
{
	Packet[0].chan = Packet[1].chan = Packet[2].chan = Packet[3].chan = -1;

	__SIRegs[SI_POLL] = 0;

	while (__SIRegs[SI_CC_STAT] & 1) {
		;
	}

	__SIRegs[SI_CC_STAT] = 0x80000000;

#if defined(VERSION_G98E01_PIKIDEMO)
	__OSSetInterruptHandler(__OS_INTERRUPT_PI_SI, SIInterruptHandler);
#else
	__OSSetInterruptHandler(__OS_INTERRUPT_PI_SI, SIIntrruptHandler);
#endif
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_SI);

#if defined(VERSION_G98E01_PIKIDEMO)
	SIGetType(0);
	SIGetType(1);
	SIGetType(2);
	SIGetType(3);
#endif
}

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

#if defined(VERSION_G98E01_PIKIDEMO)
	comcsr.val = __SIRegs[13];
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
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
u32 SIGetStatus(s32 chan)
{
#if defined(VERSION_G98E01_PIKIDEMO)
	BOOL enabled;
	u32 sr;
	int chanShift;

	enabled   = OSDisableInterrupts();
	sr        = __SIRegs[14];
	chanShift = 8 * (SI_MAX_CHAN - 1 - chan);
	sr >>= chanShift;
	if (sr & SI_ERROR_NO_RESPONSE) {
		if (!(Type[chan] & SI_ERROR_BUSY)) {
			Type[chan] = SI_ERROR_NO_RESPONSE;
		}
	}
	OSRestoreInterrupts(enabled);
	return sr;
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
 * @note UNUSED Size: 000014
 */
void SIGetCommand(void)
{
	// UNUSED FUNCTION
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

	Si.poll &= ~(0x03FF0000 | 0x0000FF00);
	Si.poll |= poll;
	poll = Si.poll;

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
	poll &= 0xF0;

	poll = Si.poll & ~poll;

	__SIRegs[SI_POLL] = poll;
	Si.poll           = poll;

	OSRestoreInterrupts(enabled);
	return poll;
}

#if defined(VERSION_G98E01_PIKIDEMO)
static BOOL SIGetResponseRaw(s32 chan)
{
	u32 sr;

	sr = SIGetStatus(chan);
	if (sr & SI_ERROR_RDST) {
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
#if defined(VERSION_G98E01_PIKIDEMO)
BOOL SIGetResponse(s32 chan, void* data)
{
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
void SIGetResponse(s32 chan, void* data)
{
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
#if defined(VERSION_G98E01_PIKIDEMO)
	BOOL enabled;
	SIPacket* packet = &Packet[chan];
	OSTime now;
	OSTime fire;

	enabled = OSDisableInterrupts();
	if (packet->chan != -1 || Si.chan == chan) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	now = __OSGetSystemTime();
	if (delay == 0) {
		fire = now;
	} else {
		fire = XferTime[chan] + delay;
	}
	if (now < fire) {
		delay = fire - now;
		OSSetAlarm(&Alarm[chan], delay, AlarmHandler);
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
	packet->fire        = fire;

	OSRestoreInterrupts(enabled);
	return TRUE;
#else
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
#endif
}

#if defined(VERSION_G98E01_PIKIDEMO)

static void CallTypeAndStatusCallback(s32 chan, u32 type)
{
	SITypeAndStatusCallback callback;
	int i;

	for (i = 0; i < 4; ++i) {
		callback = TypeCallback[chan][i];
		if (callback) {
			TypeCallback[chan][i] = 0;
			callback(chan, type);
		}
	}
}

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

	chanBit = SI_CHAN0_BIT >> chan;
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
			if (TypeCallback[chan][i] == 0) {
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

char* SIGetTypeString(u32 type)
{
	switch (SIDecodeType(type)) {
	case SI_ERROR_NO_RESPONSE:
		return "No response";
	case SI_N64_CONTROLLER:
		return "N64 controller";
	case SI_N64_MIC:
		return "N64 microphone";
	case SI_N64_KEYBOARD:
		return "N64 keyboard";
	case SI_N64_MOUSE:
		return "N64 mouse";
	case SI_GBA:
		return "GameBoy Advance";
	case SI_GC_CONTROLLER:
		return "Standard controller";
	case SI_GC_RECEIVER:
		return "Wireless receiver";
	case SI_GC_WAVEBIRD:
		return "WaveBird controller";
	case SI_GC_KEYBOARD:
		return "Keyboard";
		// case SI_GC_STEERING:
		//	return "Steering";
	}
}

#endif
