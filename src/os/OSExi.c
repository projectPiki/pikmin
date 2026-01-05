#include "Dolphin/os.h"
#include <stddef.h>
#include <string.h>

// This OS file in particular is really fussy, so I'm just seperating the whole thing for v37 (USA) and v47 (USA Demo)
#if defined(VERSION_G98E01_PIKIDEMO)
typedef void (*EXICallback)(s32, OSContext*);

#define EXI_0LENGTH_EXILENGTH_MASK 0x03FFFFE0

static EXIControl Ecb[EXI_MAX_CHAN];

static void SetExiInterruptMask(s32 chan, struct EXIControl* exi);
static void CompleteTransfer(s32 chan);
int EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
int EXIImmEx(s32 chan, void* buf, s32 len, u32 mode);
int EXIDma(s32 chan, void* buf, s32 len, u32 type, EXICallback callback);
int EXISync(s32 chan);
EXICallback EXISetExiCallback(s32 chan, EXICallback exiCallback);
void EXIProbeReset();
static int __EXIProbe(s32 chan);
int EXIProbe(s32 chan);
int EXIAttach(s32 chan, EXICallback extCallback);
int EXIDetach(s32 chan);
int EXISelect(s32 chan, u32 dev, u32 freq);
int EXIDeselect(s32 chan);
static void EXIIntrruptHandler(signed short interrupt, struct OSContext* context);
static void TCIntrruptHandler(signed short interrupt, struct OSContext* context);
static void EXTIntrruptHandler(signed short interrupt, struct OSContext* context);
void EXIInit();
int EXILock(s32 chan, u32 dev, void (*unlockedCallback)(s32, struct OSContext*));
int EXIUnlock(s32 chan);
u32 EXIGetState(s32 chan);

static void SetExiInterruptMask(s32 chan, struct EXIControl* exi)
{
	struct EXIControl* exi2 = &Ecb[2];

	switch (chan) {
	case 0:
	{
		if ((exi->exiCallback == 0 && exi2->exiCallback == 0) || exi->state & 0x10) {
			__OSMaskInterrupts(0x410000U);
			return;
		}
		__OSUnmaskInterrupts(0x410000U);
		return;
	}
	case 1:
	{
		if (exi->exiCallback == 0 || exi->state & 0x10) {
			__OSMaskInterrupts(0x80000U);
			return;
		}
		__OSUnmaskInterrupts(0x80000U);
		return;
	}
	case 2:
	{
		if ((__OSGetInterruptHandler(0x19) == 0U) || (exi->state & 0x10)) {
			__OSMaskInterrupts(0x40U);
			return;
		}
		__OSUnmaskInterrupts(0x40U);
		return;
	}
	}
}

static void CompleteTransfer(s32 chan)
{
	struct EXIControl* exi;
	unsigned char* buf;
	u32 data;
	int i;
	int len;

	exi = &Ecb[chan];
	ASSERTLINE(0x115, 0 <= chan && chan < EXI_MAX_CHAN);

	if (exi->state & 3) {
		if (exi->state & 2) {
			if ((len = exi->immLen) != 0) {
				buf  = exi->immBuf;
				data = __EXIRegs[(chan * 5) + 4];
				for (i = 0; i < len; i++) {
					*buf++ = data >> ((3 - i) * 8);
				}
			}
		}
		exi->state &= ~3;
	}
}

int EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
	struct EXIControl* exi;
	int enabled;
	u32 data;
	int i;

	exi = &Ecb[chan];
	ASSERTLINE(0x13B, exi->state & EXI_STATE_SELECTED);
	ASSERTLINE(0x13C, 0 <= chan && chan < EXI_MAX_CHAN);
	ASSERTLINE(0x13D, 0 < len && len <= MAX_IMM);
	ASSERTLINE(0x13E, type < MAX_TYPE);
	enabled = OSDisableInterrupts();
	if ((exi->state & 3) || !(exi->state & 4)) {
		OSRestoreInterrupts(enabled);
		return 0;
	}
	exi->tcCallback = callback;
	if (exi->tcCallback) {
		EXIClearInterrupts(chan, 0, 1, 0);
		__OSUnmaskInterrupts(0x200000U >> (chan * 3));
	}
	exi->state |= 2;
	if (type != 0) {
		data = 0;
		for (i = 0; i < len; i++) {
			data |= ((u8*)buf)[i] << ((3 - i) * 8);
		}
		__EXIRegs[(chan * 5) + 4] = data;
	}
	exi->immBuf               = buf;
	exi->immLen               = (type != 1) ? len : 0;
	__EXIRegs[(chan * 5) + 3] = (type << 2) | 1 | ((len - 1) << 4);
	OSRestoreInterrupts(enabled);
	return 1;
}

int EXIImmEx(s32 chan, void* buf, s32 len, u32 mode)
{
	s32 xLen;

	while (len) {
		xLen = (len < 4) ? len : 4;
		if (EXIImm(chan, buf, xLen, mode, 0) == 0) {
			return 0;
		}
		if (EXISync(chan) == 0) {
			return 0;
		}
		((u8*)buf) += xLen;
		len -= xLen;
	}
	return 1;
}

int EXIDma(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
	struct EXIControl* exi;
	int enabled;

	exi = &Ecb[chan];

	ASSERTLINE(0x1A4, exi->state & EXI_STATE_SELECTED);
	ASSERTLINE(0x1A5, OFFSET(buf, 32) == 0);
	ASSERTLINE(0x1A6, 0 < len && OFFSET(len, 32) == 0);
	ASSERTLINE(0x1A8, ((u32)len & ~EXI_0LENGTH_EXILENGTH_MASK) == 0);
	ASSERTLINE(0x1AA, type == EXI_READ || type == EXI_WRITE);

	enabled = OSDisableInterrupts();
	if ((exi->state & 3) || !(exi->state & 4)) {
		OSRestoreInterrupts(enabled);
		return 0;
	}
	exi->tcCallback = callback;
	if ((u32)exi->tcCallback) {
		EXIClearInterrupts(chan, 0, 1, 0);
		__OSUnmaskInterrupts(0x200000U >> (chan * 3));
	}
	exi->state |= 1;
	__EXIRegs[(chan * 5) + 1] = (u32)buf & 0x03FFFFE0;
	__EXIRegs[(chan * 5) + 2] = len;
	__EXIRegs[(chan * 5) + 3] = (type * 4) | 3;
	OSRestoreInterrupts(enabled);
	return 1;
}

#define EXI_REG_MAX       5
#define EXI_USB_ADAPTER   0x01010000
#define EXI_FREQ_1M       0
#define EXIREG(chan, idx) (__EXIRegs[((chan) * EXI_REG_MAX) + (idx)])

int EXISync(s32 chan)
{
	struct EXIControl* exi;
	int rc;
	int enabled;

	exi = &Ecb[chan];
	rc  = 0;
	ASSERTLINE(0x1D7, 0 <= chan && chan < EXI_MAX_CHAN);
	while ((exi->state & 4)) {
		if (!(__EXIRegs[(chan * 5) + 3] & 1)) {
			enabled = OSDisableInterrupts();
			if (exi->state & 4) {
				CompleteTransfer(chan);
				if (__OSGetDIConfig() != 0xff || exi->immLen != 4 || (EXIREG(chan, 0) & 0x00000070) != (EXI_FREQ_1M << 4)
				    || (EXIREG(chan, 4) != EXI_USB_ADAPTER)) {
					rc = TRUE;
				}
			}
			OSRestoreInterrupts(enabled);
			break;
		}
	}
	ASSERTLINE(0x1E9, !(exi->state & EXI_STATE_BUSY));
	return rc;
}

BOOL EXIClearInterrupts(s32 chan, int exi, int tc, int ext)
{
	u32 cpr;
	u32 prev;

	ASSERTLINE(0x1FE, 0 <= chan && chan < EXI_MAX_CHAN);
	cpr = prev = __EXIRegs[(chan * 5)];
	prev &= 0x7F5;
	if (exi != 0) {
		prev |= 2;
	}
	if (tc != 0) {
		prev |= 8;
	}
	if (ext != 0) {
		prev |= 0x800;
	}
	__EXIRegs[(chan * 5)] = prev;
	return cpr;
}

EXICallback EXISetExiCallback(s32 chan, EXICallback exiCallback)
{
	struct EXIControl* exi;
	EXICallback prev;
	int enabled;

	exi = &Ecb[chan];
	ASSERTLINE(0x220, 0 <= chan && chan < EXI_MAX_CHAN);
	enabled          = OSDisableInterrupts();
	prev             = exi->exiCallback;
	exi->exiCallback = exiCallback;
	if (chan != 2) {
		SetExiInterruptMask(chan, exi);
	} else {
		SetExiInterruptMask(0, &Ecb[0]);
	}
	OSRestoreInterrupts(enabled);
	return prev;
}

void EXIProbeReset()
{
	__EXIProbeStartTime[0] = __EXIProbeStartTime[1] = 0;
	Ecb[0].idTime = Ecb[1].idTime = 0;
	__EXIProbe(0);
	__EXIProbe(1);
}

static int __EXIProbe(s32 chan)
{
	struct EXIControl* exi;
	int enabled;
	int rc;
	u32 cpr;
	s32 t;

	exi = &Ecb[chan];
	ASSERTLINE(0x256, 0 <= chan && chan < EXI_MAX_CHAN);
	if (chan == 2) {
		return 1;
	}
	rc      = 1;
	enabled = OSDisableInterrupts();
	cpr     = __EXIRegs[(chan * 5)];
	if (!(exi->state & 8)) {
		if (cpr & 0x800) {
			EXIClearInterrupts(chan, 0, 0, 1);
			exi->idTime               = 0;
			__EXIProbeStartTime[chan] = 0;
		}
		if (cpr & 0x1000) {
			t = ((s32)(OSTicksToMilliseconds(OSGetTime()) / 100) + 1);

			if (__EXIProbeStartTime[chan] == 0) {
				__EXIProbeStartTime[chan] = t;
			}
			if (t - (s32)__EXIProbeStartTime[chan] < 3) {
				rc = 0;
			}
		} else {
			exi->idTime               = 0;
			__EXIProbeStartTime[chan] = 0;
			rc                        = 0;
		}
	} else if (!(cpr & 0x1000) || (cpr & 0x800)) {
		exi->idTime               = 0;
		__EXIProbeStartTime[chan] = 0;
		rc                        = 0;
	}
	OSRestoreInterrupts(enabled);
	return rc;
}

int EXIProbe(s32 chan)
{
	int var_r3;
	struct EXIControl* exi = &Ecb[chan];

	if ((var_r3 = __EXIProbe(chan))) {
		u32 id;
		if (exi->idTime == 0) {
			if (EXIGetID(chan, 0, &id) != 0) {
				var_r3 = 1;
			} else {
				var_r3 = 0;
			}
		}
	}
	return var_r3;
}

s32 EXIProbeEx(s32 chan)
{
	if (EXIProbe(chan)) {
		return 1;
	}
	if (__EXIProbeStartTime[chan]) {
		return 0;
	}
	return -1;
}

static int __EXIAttach(s32 chan, EXICallback extCallback)
{
	struct EXIControl* exi = &Ecb[chan];
	int enabled            = OSDisableInterrupts();
	int result;

	if (exi->state & 8 || __EXIProbe(chan) == 0) {
		OSRestoreInterrupts(enabled);
		result = 0;
	} else {
		u32 intr;
		EXIClearInterrupts(chan, 1, 0, 0);
		exi->extCallback = extCallback;
		__OSUnmaskInterrupts(0x100000U >> (chan * 3));
		exi->state |= 8;
		OSRestoreInterrupts(enabled);
		result = 1;
	}
	return result;
}

int EXIAttach(s32 chan, EXICallback extCallback)
{
	struct EXIControl* exi;
	int enabled;
	int result;

	exi = &Ecb[chan];
	ASSERTLINE(0x2AE, 0 <= chan && chan < 2);

	EXIProbe(chan);

	enabled = OSDisableInterrupts();
	if (exi->idTime == 0) {
		OSRestoreInterrupts(enabled);
		return 0;
	}
	result = __EXIAttach(chan, extCallback);

	OSRestoreInterrupts(enabled);
	return result;
}

int EXIDetach(s32 chan)
{
	struct EXIControl* exi;
	int enabled;

	exi = &Ecb[chan];
	ASSERTLINE(0x2D7, 0 <= chan && chan < 2);
	enabled = OSDisableInterrupts();
	if (!(exi->state & 8)) {
		OSRestoreInterrupts(enabled);
		return 1;
	}
	if ((exi->state & 0x10) && (exi->dev == 0)) {
		OSRestoreInterrupts(enabled);
		return 0;
	}
	exi->state &= ~8;
	__OSMaskInterrupts(0x700000U >> (chan * 3));
	OSRestoreInterrupts(enabled);
	return 1;
}

int EXISelect(s32 chan, u32 dev, u32 freq)
{
	struct EXIControl* exi;
	u32 cpr;
	int enabled;

	exi = &Ecb[chan];

	ASSERTLINE(0x2FF, 0 <= chan && chan < EXI_MAX_CHAN);
	ASSERTLINE(0x300, chan == 0 && dev < EXI_MAX_DEV || dev == 0);
	ASSERTLINE(0x301, freq < EXI_MAX_FREQ);
	ASSERTLINE(0x302, !(exi->state & EXI_STATE_SELECTED));

	enabled = OSDisableInterrupts();
	if ((exi->state & 4)
	    || ((chan != 2) && (((dev == 0) && !(exi->state & 8) && (__EXIProbe(chan) == 0)) || !(exi->state & 0x10) || (exi->dev != dev)))) {
		OSRestoreInterrupts(enabled);
		return 0;
	}
	exi->state |= 4;
	cpr = __EXIRegs[(chan * 5)];
	cpr &= 0x405;
	cpr |= (((1 << dev) << 7) | (freq * 0x10));
	__EXIRegs[(chan * 5)] = cpr;
	if (exi->state & 8) {
		switch (chan) {
		case 0:
		{
			__OSMaskInterrupts(0x100000U);
			break;
		}
		case 1:
		{
			__OSMaskInterrupts(0x20000U);
			break;
		}
		}
	}
	OSRestoreInterrupts(enabled);
	return 1;
}

int EXIDeselect(s32 chan)
{
	struct EXIControl* exi;
	u32 cpr;
	int enabled;

	exi = &Ecb[chan];
	ASSERTLINE(0x335, 0 <= chan && chan < EXI_MAX_CHAN);
	enabled = OSDisableInterrupts();
	if (!(exi->state & 4)) {
		OSRestoreInterrupts(enabled);
		return 0;
	}
	exi->state &= ~4;
	cpr                   = __EXIRegs[(chan * 5)];
	__EXIRegs[(chan * 5)] = cpr & 0x405;
	if (exi->state & 8) {
		switch (chan) {
		case 0:
		{
			__OSUnmaskInterrupts(0x100000U);
			break;
		}
		case 1:
		{
			__OSUnmaskInterrupts(0x20000U);
			break;
		}
		}
	}
	OSRestoreInterrupts(enabled);
	if ((chan != 2) && (cpr & 0x80)) {
		if (__EXIProbe(chan) != 0) {
			return 1;
		}
		return 0;
	}
	return 1;
}

static void EXIIntrruptHandler(signed short interrupt, struct OSContext* context)
{
	s32 chan;
	struct EXIControl* exi;
	EXICallback callback;
	OSContext old;
	int stack, stack2;

	chan = (interrupt - 9) / 3;

	ASSERTLINE(0x368, 0 <= chan && chan < EXI_MAX_CHAN);
	exi = &Ecb[chan];
	EXIClearInterrupts(chan, 1, 0, 0);
	callback = exi->exiCallback;
	if (callback) {
		OSClearContext(&old);
		OSSetCurrentContext(&old);
		callback(chan, context);
		OSClearContext(&old);
		OSSetCurrentContext(context);
	}
}

static void TCIntrruptHandler(signed short interrupt, struct OSContext* context)
{
	s32 chan;
	struct EXIControl* exi;
	EXICallback callback;
	OSContext old;
	int stack, stack2;

	chan = (interrupt - 10) / 3;

	ASSERTLINE(0x383, 0 <= chan && chan < EXI_MAX_CHAN);
	exi = &Ecb[chan];
	__OSMaskInterrupts(0x80000000U >> interrupt);
	EXIClearInterrupts(chan, 0, 1, 0);
	callback = exi->tcCallback;
	if (callback) {
		exi->tcCallback = NULL;
		CompleteTransfer(chan);
		OSClearContext(&old);
		OSSetCurrentContext(&old);
		callback(chan, context);
		OSClearContext(&old);
		OSSetCurrentContext(context);
	}
}

static void EXTIntrruptHandler(signed short interrupt, struct OSContext* context)
{
	s32 chan;
	struct EXIControl* exi;
	EXICallback callback;
	OSContext old;

	chan = (interrupt - 11) / 3;

	ASSERTLINE(0x3A2, 0 <= chan && chan < 2);
	__OSMaskInterrupts(0x700000U >> (chan * 3));
	__EXIRegs[(chan * 5)] = 0;
	exi                   = &Ecb[chan];
	callback              = exi->extCallback;
	exi->state &= 0xFFFFFFF7;
	if (callback) {
		OSClearContext(&old);
		OSSetCurrentContext(&old);
		exi->extCallback = 0;
		callback(chan, context);
		OSClearContext(&old);
		OSSetCurrentContext(context);
	}
}

void EXIInit()
{
	__OSMaskInterrupts(0x7F8000U);
	__EXIRegs[0]  = 0;
	__EXIRegs[5]  = 0;
	__EXIRegs[10] = 0;
	__EXIRegs[0]  = 0x2000;
	__OSSetInterruptHandler(9, EXIIntrruptHandler);
	__OSSetInterruptHandler(10, TCIntrruptHandler);
	__OSSetInterruptHandler(11, EXTIntrruptHandler);
	__OSSetInterruptHandler(12, EXIIntrruptHandler);
	__OSSetInterruptHandler(13, TCIntrruptHandler);
	__OSSetInterruptHandler(14, EXTIntrruptHandler);
	__OSSetInterruptHandler(15, EXIIntrruptHandler);
	__OSSetInterruptHandler(16, TCIntrruptHandler);

	if (OSGetConsoleType() & 0x10000000) {
		EXIProbeReset();
	}
}

int EXILock(s32 chan, u32 dev, void (*unlockedCallback)(s32, struct OSContext*))
{
	struct EXIControl* exi;
	int enabled;
	int i;

	exi = &Ecb[chan];
	ASSERTLINE(0x3F2, 0 <= chan && chan < EXI_MAX_CHAN);
	ASSERTLINE(0x3F3, chan == 0 && dev < EXI_MAX_DEV || dev == 0);
	enabled = OSDisableInterrupts();

	if (exi->state & 0x10) {
		if (unlockedCallback) {
			ASSERTLINE(0x3F9, chan == 0 && exi->items < (EXI_MAX_DEV - 1) || exi->items == 0);
			for (i = 0; i < exi->items; i++) {
				if (exi->queue[i].dev == dev) {
					OSRestoreInterrupts(enabled);
					return 0;
				}
			}
			exi->queue[exi->items].callback = unlockedCallback;
			exi->queue[exi->items].dev      = dev;
			exi->items++;
		}
		OSRestoreInterrupts(enabled);
		return 0;
	}
	ASSERTLINE(0x409, exi->items == 0);
	exi->state |= 0x10;
	exi->dev = dev;
	SetExiInterruptMask(chan, exi);
	OSRestoreInterrupts(enabled);
	return 1;
}

int EXIUnlock(s32 chan)
{
	struct EXIControl* exi;
	int enabled;
	EXICallback unlockedCallback;

	exi = &Ecb[chan];
	ASSERTLINE(0x421, 0 <= chan && chan < EXI_MAX_CHAN);
	enabled = OSDisableInterrupts();
	if (!(exi->state & 0x10)) {
		OSRestoreInterrupts(enabled);
		return 0;
	}
	exi->state &= 0xFFFFFFEF;
	SetExiInterruptMask(chan, exi);
	if (exi->items > 0) {
		unlockedCallback = exi->queue[0].callback;
		if (--exi->items > 0) {
			memmove(&exi->queue[0], &exi->queue[1], exi->items * 8);
		}
		unlockedCallback(chan, 0);
	}
	OSRestoreInterrupts(enabled);
	return 1;
}

u32 EXIGetState(s32 chan)
{
	struct EXIControl* exi;

	exi = &Ecb[chan];
	ASSERTLINE(0x446, 0 <= chan && chan < EXI_MAX_CHAN);
	return exi->state;
}

static void UnlockedHandler(s32 chan, OSContext* context)
{
	u32 id;
	EXIGetID(chan, 0, &id);
}

s32 EXIGetID(s32 chan, u32 dev, u32* id)
{
	int err;
	u32 cmd;
	struct EXIControl* exi = &Ecb[chan];
	s32 startTime;

	ASSERTLINE(0x45A, 0 <= chan && chan < EXI_MAX_CHAN);

	if (chan < 2 && dev == 0) {
		if (!__EXIProbe(chan)) {
			return 0;
		}

		if (exi->idTime == __EXIProbeStartTime[chan]) {
			*id = exi->id;
			return exi->idTime;
		}

		if (!__EXIAttach(chan, NULL)) {
			return 0;
		}
		startTime = __EXIProbeStartTime[chan];
	}

	err = !EXILock(chan, dev, (chan < 2 && dev == 0) ? UnlockedHandler : NULL);
	if (err == 0) {
		err = !EXISelect(chan, dev, 0);
		if (err == 0) {
			cmd = 0;
			err |= !EXIImm(chan, &cmd, 2, 1, 0);
			err |= !EXISync(chan);
			err |= !EXIImm(chan, id, 4, 0, 0);
			err |= !EXISync(chan);
			err |= !EXIDeselect(chan);
		}
		EXIUnlock(chan);
	}
	if ((chan < 2) && (dev == 0)) {
		int enabled;
		EXIDetach(chan);
		enabled = OSDisableInterrupts();
		err |= (startTime != __EXIProbeStartTime[chan]);

		if (err == 0) {
			exi->id     = *id;
			exi->idTime = startTime;
		}

		OSRestoreInterrupts(enabled);
		return err ? 0 : exi->idTime;
	}
	if (err) {
		return 0;
	}
	return 1;
}
#else

static EXIControl Ecb[EXI_MAX_CHAN];

/**
 * @TODO: Documentation
 */
static void SetExiInterruptMask(s32 chan, EXIControl* exi)
{
	EXIControl* exi2;

	exi2 = &Ecb[2];
	switch (chan) {
	case 0:
	{
		if ((exi->exiCallback == 0 && exi2->exiCallback == 0) || (exi->state & EXI_STATE_LOCKED)) {
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_2_EXI);
		} else {
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_2_EXI);
		}
		break;
	}
	case 1:
	{
		if (exi->exiCallback == 0 || (exi->state & EXI_STATE_LOCKED)) {
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXI);
		} else {
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXI);
		}
		break;
	}
	case 2:
	{
		if (__OSGetInterruptHandler(__OS_INTERRUPT_PI_DEBUG) == 0 || (exi->state & EXI_STATE_LOCKED)) {
			__OSMaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);
		} else {
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);
		}
		break;
	}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000164
 */
static void CompleteTransfer(s32 chan)
{
	EXIControl* exi = &Ecb[chan];
	u8* buf;
	u32 data;
	int i;
	int len;

	if (exi->state & EXI_STATE_BUSY) {
		if ((exi->state & EXI_STATE_IMM) && (len = exi->immLen)) {
			buf  = exi->immBuf;
			data = EXIREG(chan, 4);
			for (i = 0; i < len; i++) {
				*buf++ = (u8)((data >> ((3 - i) * 8)) & 0xff);
			}
		}
		exi->state &= ~EXI_STATE_BUSY;
	}
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
BOOL EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
	EXIControl* exi = &Ecb[chan];
	BOOL enabled;

	enabled = OSDisableInterrupts();
	if ((exi->state & EXI_STATE_BUSY) || !(exi->state & EXI_STATE_SELECTED)) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	exi->tcCallback = callback;
	if (exi->tcCallback) {
		EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
		__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_TC >> (3 * chan));
	}

	exi->state |= EXI_STATE_IMM;

	if (type != EXI_READ) {
		u32 data;
		int i;

		data = 0;
		for (i = 0; i < len; i++) {
			data |= ((u8*)buf)[i] << ((3 - i) * 8);
		}
		EXIREG(chan, 4) = data;
	}

	exi->immBuf = buf;
	exi->immLen = (type != EXI_WRITE) ? len : 0;

	EXIREG(chan, 3) = EXI_0CR(1, 0, type, len - 1);

	OSRestoreInterrupts(enabled);

	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL EXIImmEx(s32 chan, void* buf, s32 len, u32 mode)
{
	s32 xLen;

	while (len) {
		xLen = (len < 4) ? len : 4;
		if (!EXIImm(chan, buf, xLen, mode, NULL)) {
			return FALSE;
		}

		if (!EXISync(chan)) {
			return FALSE;
		}

		(u8*)buf += xLen;
		len -= xLen;
	}
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL EXIDma(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
	EXIControl* exi = &Ecb[chan];
	BOOL enabled;

	enabled = OSDisableInterrupts();
	if ((exi->state & EXI_STATE_BUSY) || !(exi->state & EXI_STATE_SELECTED)) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	exi->tcCallback = callback;
	if (exi->tcCallback) {
		EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
		__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_TC >> (3 * chan));
	}

	exi->state |= EXI_STATE_DMA;

	EXIREG(chan, 1) = (u32)buf & 0x3ffffe0;
	EXIREG(chan, 2) = (u32)len;
	EXIREG(chan, 3) = EXI_0CR(1, 1, type, 0);

	OSRestoreInterrupts(enabled);

	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL EXISync(s32 chan)
{
	EXIControl* exi = &Ecb[chan];
	BOOL rc         = FALSE;
	BOOL enabled;

	while (exi->state & EXI_STATE_SELECTED) {
		if (((EXIREG(chan, 3) & 1) >> 0) == 0) {
			enabled = OSDisableInterrupts();
			if (exi->state & EXI_STATE_SELECTED) {
				CompleteTransfer(chan);
				if (__OSGetDIConfig() != 0xff || exi->immLen != 4 || (EXIREG(chan, 0) & 0x00000070) != (EXI_FREQ_1M << 4)
				    || (EXIREG(chan, 4) != EXI_USB_ADAPTER)) {
					rc = TRUE;
				}
			}
			OSRestoreInterrupts(enabled);
			break;
		}
	}
	return rc;
}

/**
 * @TODO: Documentation
 */
int EXIClearInterrupts(s32 chan, BOOL exi, BOOL tc, BOOL ext)
{
	u32 cpr;
	u32 prev;

	prev = cpr = EXIREG(chan, 0);
	cpr &= 0x7f5;
	if (exi)
		cpr |= 2;
	if (tc)
		cpr |= 8;
	if (ext)
		cpr |= 0x800;
	EXIREG(chan, 0) = cpr;
	return prev;
}

/**
 * @TODO: Documentation
 */
EXICallback EXISetExiCallback(s32 chan, EXICallback exiCallback)
{
	EXIControl* exi = &Ecb[chan];
	EXICallback prev;
	BOOL enabled;

	enabled          = OSDisableInterrupts();
	prev             = exi->exiCallback;
	exi->exiCallback = exiCallback;

	if (chan != 2) {
		SetExiInterruptMask(chan, exi);
	} else {
		SetExiInterruptMask(0, &Ecb[0]);
	}

	OSRestoreInterrupts(enabled);
	return prev;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00003C
 */
void EXIProbeReset(void)
{
	__EXIProbeStartTime[0] = __EXIProbeStartTime[1] = 0;
	__EXIProbe(0);
	__EXIProbe(1);
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
BOOL EXIProbe(s32 chan)
{
	EXIControl* exi = &Ecb[chan];
	BOOL enabled;
	BOOL rc;
	u32 cpr;
	s32 t;

	if (chan == 2) {
		return TRUE;
	}

	rc      = TRUE;
	enabled = OSDisableInterrupts();
	cpr     = EXIREG(chan, 0);
	if (!(exi->state & EXI_STATE_ATTACHED)) {
		if (cpr & 0x00000800) {
			EXIClearInterrupts(chan, FALSE, FALSE, TRUE);
			__EXIProbeStartTime[chan] = 0;
		}

		if (cpr & 0x00001000) {
			t = (s32)(OSTicksToMilliseconds(OSGetTime()) / 100) + 1;
			if ((u32)__EXIProbeStartTime[chan] == 0) {
				__EXIProbeStartTime[chan] = t;
			}
			if (t - __EXIProbeStartTime[chan] < 300 / 100) {
				rc = FALSE;
			}
		} else {
			__EXIProbeStartTime[chan] = 0;
			rc                        = FALSE;
		}
	} else if (!(cpr & 0x00001000) || (cpr & 0x00000800)) {
		__EXIProbeStartTime[chan] = 0;
		rc                        = FALSE;
	}
	OSRestoreInterrupts(enabled);
	return rc;
}

/**
 * @TODO: Documentation
 */
s32 EXIProbeEx(s32 chan)
{
	if (EXIProbe(chan)) {
		return 1;
	} else if ((u32)__EXIProbeStartTime[chan] != 0) {
		return 0;
	}
	return -1;
}

/**
 * @TODO: Documentation
 */
BOOL EXIAttach(s32 chan, EXICallback extCallback)
{
	EXIControl* exi = &Ecb[chan];
	BOOL enabled;
	u32 stack1; // unused, just stack filling
	u32 stack2; // unused, just stack filling

	enabled = OSDisableInterrupts();
	if ((exi->state & EXI_STATE_ATTACHED)) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	if (EXIProbe(chan) == FALSE) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	EXIClearInterrupts(chan, TRUE, FALSE, FALSE);

	exi->extCallback = extCallback;
	__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXT >> (3 * chan));
	exi->state |= EXI_STATE_ATTACHED;
	OSRestoreInterrupts(enabled);

	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL EXIDetach(s32 chan)
{
	EXIControl* exi = &Ecb[chan];
	BOOL enabled;

	enabled = OSDisableInterrupts();
	if (!(exi->state & EXI_STATE_ATTACHED)) {
		OSRestoreInterrupts(enabled);
		return TRUE;
	}
	if ((exi->state & EXI_STATE_LOCKED) && exi->dev == 0) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	exi->state &= ~EXI_STATE_ATTACHED;
	__OSMaskInterrupts((OS_INTERRUPTMASK_EXI_0_EXT | OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_0_TC) >> (3 * chan));
	OSRestoreInterrupts(enabled);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL EXISelect(s32 chan, u32 dev, u32 freq)
{
	EXIControl* exi = &Ecb[chan];
	u32 cpr;
	BOOL enabled;

	enabled = OSDisableInterrupts();

	if ((exi->state & EXI_STATE_SELECTED)
	    || chan != 2
	           && (dev == 0 && !(exi->state & EXI_STATE_ATTACHED) && !EXIProbe(chan) || !(exi->state & EXI_STATE_LOCKED)
	               || (exi->dev != dev))) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	exi->state |= EXI_STATE_SELECTED;
	cpr = EXIREG(chan, 0);
	cpr &= 0x405;
	cpr |= EXI_CPR_CS(dev) | EXI_CPR_CLK(freq);
	EXIREG(chan, 0) = cpr;

	if (exi->state & EXI_STATE_ATTACHED) {
		switch (chan) {
		case 0:
		{
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXT);
			break;
		}
		case 1:
		{
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXT);
			break;
		}
		}
	}

	OSRestoreInterrupts(enabled);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL EXIDeselect(s32 chan)
{
	EXIControl* exi = &Ecb[chan];
	u32 cpr;
	BOOL enabled;

	enabled = OSDisableInterrupts();
	if (!(exi->state & EXI_STATE_SELECTED)) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}
	exi->state &= ~EXI_STATE_SELECTED;
	cpr             = EXIREG(chan, 0);
	EXIREG(chan, 0) = cpr & 0x405;

	if (exi->state & EXI_STATE_ATTACHED) {
		switch (chan) {
		case 0:
		{
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXT);
			break;
		}
		case 1:
		{
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXT);
			break;
		}
		}
	}

	OSRestoreInterrupts(enabled);

	if (chan != 2 && (cpr & EXI_CPR_CS(0))) {
		return EXIProbe(chan) ? TRUE : FALSE;
	}

	return TRUE;
}

/**
 * @TODO: Documentation
 */
static void EXIIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	s32 chan;
	EXIControl* exi;
	EXICallback callback;

	chan = (interrupt - __OS_INTERRUPT_EXI_0_EXI) / 3;
	exi  = &Ecb[chan];
	EXIClearInterrupts(chan, TRUE, FALSE, FALSE);
	callback = exi->exiCallback;
	if (callback) {
		callback(chan, context);
	}
}

/**
 * @TODO: Documentation
 */
static void TCIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	s32 chan;
	EXIControl* exi;
	EXICallback callback;
	int pad, pad2;

	chan = (interrupt - __OS_INTERRUPT_EXI_0_TC) / 3;
	exi  = &Ecb[chan];
	__OSMaskInterrupts(OS_INTERRUPTMASK(interrupt));
	EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
	callback = exi->tcCallback;
	if (callback) {
		exi->tcCallback = 0;
		CompleteTransfer(chan);
		callback(chan, context);
	}
}

/**
 * @TODO: Documentation
 */
static void EXTIntrruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	s32 chan;
	EXIControl* exi;
	EXICallback callback;

	chan = (interrupt - __OS_INTERRUPT_EXI_0_EXT) / 3;
	__OSMaskInterrupts((OS_INTERRUPTMASK_EXI_0_EXT | OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_0_TC) >> (3 * chan));
	__EXIRegs[(chan * 5)] = 0;

	exi      = &Ecb[chan];
	callback = exi->extCallback;
	exi->state &= ~EXI_STATE_ATTACHED;
	if (callback) {
		exi->extCallback = 0;
		callback(chan, context);
	}
}

/**
 * @TODO: Documentation
 */
void EXIInit(void)
{
	__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_0_TC | OS_INTERRUPTMASK_EXI_0_EXT | OS_INTERRUPTMASK_EXI_1_EXI
	                   | OS_INTERRUPTMASK_EXI_1_TC | OS_INTERRUPTMASK_EXI_1_EXT | OS_INTERRUPTMASK_EXI_2_EXI | OS_INTERRUPTMASK_EXI_2_TC);

	EXIREG(0, 0) = 0;
	EXIREG(1, 0) = 0;
	EXIREG(2, 0) = 0;

	EXIREG(0, 0) = 0x00002000;

	__OSSetInterruptHandler(__OS_INTERRUPT_EXI_0_EXI, EXIIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_EXI_0_TC, TCIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_EXI_0_EXT, EXTIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_EXI_1_EXI, EXIIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_EXI_1_TC, TCIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_EXI_1_EXT, EXTIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_EXI_2_EXI, EXIIntrruptHandler);
	__OSSetInterruptHandler(__OS_INTERRUPT_EXI_2_TC, TCIntrruptHandler);

	if (OSGetConsoleType() & 0x10000000) {
		__EXIProbeStartTime[0] = __EXIProbeStartTime[1] = 0;
		EXIProbe(0);
		EXIProbe(1);
	}
}

/**
 * @TODO: Documentation
 */
BOOL EXILock(s32 chan, u32 dev, EXICallback unlockedCallback)
{
	EXIControl* exi = &Ecb[chan];
	BOOL enabled;
	int i;

	enabled = OSDisableInterrupts();
	if (exi->state & EXI_STATE_LOCKED) {
		if (unlockedCallback) {
			for (i = 0; i < exi->items; i++) {
				if (exi->queue[i].dev == dev) {
					OSRestoreInterrupts(enabled);
					return FALSE;
				}
			}
			exi->queue[exi->items].callback = unlockedCallback;
			exi->queue[exi->items].dev      = dev;
			exi->items++;
		}
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	exi->state |= EXI_STATE_LOCKED;
	exi->dev = dev;
	SetExiInterruptMask(chan, exi);

	OSRestoreInterrupts(enabled);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL EXIUnlock(s32 chan)
{
	EXIControl* exi = &Ecb[chan];
	BOOL enabled;
	EXICallback unlockedCallback;

	enabled = OSDisableInterrupts();
	if (!(exi->state & EXI_STATE_LOCKED)) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}
	exi->state &= ~EXI_STATE_LOCKED;
	SetExiInterruptMask(chan, exi);

	if (0 < exi->items) {
		unlockedCallback = exi->queue[0].callback;
		if (0 < --exi->items) {
			memmove(&exi->queue[0], &exi->queue[1], sizeof(exi->queue[0]) * exi->items);
		}
		unlockedCallback(chan, 0);
	}

	OSRestoreInterrupts(enabled);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
u32 EXIGetState(s32 chan)
{
	EXIControl* exi = &Ecb[chan];

	return (u32)exi->state;
}

static void UnlockedHandler(s32 chan, OSContext* context)
{
	u32 id;

	EXIGetID(chan, 0, &id);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0002D4
 */
s32 EXIGetID(s32 chan, u32 dev, u32* id)
{
	// UNUSED FUNCTION
}
#endif
