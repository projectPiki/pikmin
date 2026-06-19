// This file also implements "OSExi.c" (`OS_BUILD_VERSION < 20011217L`). Don't break compatibility!

#include "Dolphin/exi.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include <string.h>

// These formerly public interface functions got renamed when they became private implementation details.
// This preprocessor block handles two issues stemming from that. If `OS_BUILD_VERSION >= 20011112L`, it
// makes the functions static. If not, then it silently renames the functions for matching using macros.
#if OS_BUILD_VERSION >= 20011112L
static BOOL __EXIProbe(s32 chan);
static BOOL __EXIAttach(s32 chan, EXICallback extCallback);
#else
#define __EXIProbe  EXIProbe
#define __EXIAttach EXIAttach
#endif

#define EXI_0LENGTH_EXILENGTH_MASK 0x03FFFFE0

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
		if ((exi->exiCallback == NULL && exi2->exiCallback == NULL) || (exi->state & EXI_STATE_LOCKED)) {
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_2_EXI);
		} else {
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_2_EXI);
		}
		break;
	}
	case 1:
	{
		if (exi->exiCallback == NULL || (exi->state & EXI_STATE_LOCKED)) {
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXI);
		} else {
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXI);
		}
		break;
	}
	case 2:
	{
		if (__OSGetInterruptHandler(__OS_INTERRUPT_PI_DEBUG) == NULL || (exi->state & EXI_STATE_LOCKED)) {
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
	EXIControl* exi;
	u8* buf;
	u32 data;
	int i;
	int len;

	exi = &Ecb[chan];
	OSAssertLine(0x115, 0 <= chan && chan < EXI_MAX_CHAN);

	if ((exi->state & EXI_STATE_BUSY)) {
		if ((exi->state & EXI_STATE_IMM) && (len = exi->immLen) != 0) {
			buf  = exi->immBuf;
			data = EXIREG(chan, 4);
			for (i = 0; i < len; i++) {
				*buf++ = data >> ((3 - i) * 8);
			}
		}
		exi->state &= ~EXI_STATE_BUSY;
	}
}

/**
 * @TODO: Documentation
 */
BOOL EXIImm(s32 chan, void* buf, s32 len, u32 type, EXICallback callback)
{
	EXIControl* exi;
	BOOL enabled;

	exi = &Ecb[chan];
	OSAssertLine(0x13B, exi->state & EXI_STATE_SELECTED);
	OSAssertLine(0x13C, 0 <= chan && chan < EXI_MAX_CHAN);
	OSAssertLine(0x13D, 0 < len && len <= MAX_IMM);
	OSAssertLine(0x13E, type < MAX_TYPE);
	enabled = OSDisableInterrupts();

	if ((exi->state & EXI_STATE_BUSY) || !(exi->state & EXI_STATE_SELECTED)) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	exi->tcCallback = callback;
	if (exi->tcCallback) {
		EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
		__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_TC >> (chan * 3));
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
	EXIControl* exi;
	BOOL enabled;

	exi = &Ecb[chan];
	OSAssertLine(0x1A4, exi->state & EXI_STATE_SELECTED);
	OSAssertLine(0x1A5, OFFSET(buf, 32) == 0);
	OSAssertLine(0x1A6, 0 < len && OFFSET(len, 32) == 0);
	OSAssertLine(0x1A8, ((u32)len & ~EXI_0LENGTH_EXILENGTH_MASK) == 0);
	OSAssertLine(0x1AA, type == EXI_READ || type == EXI_WRITE);
	enabled = OSDisableInterrupts();

	if ((exi->state & EXI_STATE_BUSY) || !(exi->state & EXI_STATE_SELECTED)) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	exi->tcCallback = callback;
	if (exi->tcCallback) {
		EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
		__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_TC >> (chan * 3));
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
	EXIControl* exi;
	BOOL rc;
	BOOL enabled;

	exi = &Ecb[chan];
	rc  = FALSE;
	OSAssertLine(0x1D7, 0 <= chan && chan < EXI_MAX_CHAN);

	while (exi->state & EXI_STATE_SELECTED) {
		if (!((EXIREG(chan, 3) & 1) >> 0)) {
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
	OSAssertLine(0x1E9, !(exi->state & EXI_STATE_BUSY));
	return rc;
}

/**
 * @TODO: Documentation
 */
u32 EXIClearInterrupts(s32 chan, BOOL exi, BOOL tc, BOOL ext)
{
	u32 cpr;
	u32 prev;

	OSAssertLine(0x1FE, 0 <= chan && chan < EXI_MAX_CHAN);
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
	EXIControl* exi;
	EXICallback prev;
	BOOL enabled;

	exi = &Ecb[chan];
	OSAssertLine(0x220, 0 <= chan && chan < EXI_MAX_CHAN);
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
 * @note UNUSED Size: 00003C (OS_BUILD_REVISION <  20011112L)
 * @note UNUSED Size: 00004C (OS_BUILD_REVISION >= 20011112L)
 */
void EXIProbeReset()
{
	__EXIProbeStartTime[0] = __EXIProbeStartTime[1] = 0;
#if OS_BUILD_VERSION >= 20011112L
	Ecb[0].idTime = Ecb[1].idTime = 0;
#endif
	__EXIProbe(0);
	__EXIProbe(1);
}

/**
 * @TODO: Documentation
 * @note If `!(OS_BUILD_REVISION >= 20011112L)`, then this function is named `EXIProbe`.
 */
BOOL __EXIProbe(s32 chan)
{
	EXIControl* exi;
	BOOL enabled;
	BOOL rc;
	u32 cpr;
	s32 t;

	exi = &Ecb[chan];
	OSAssertLine(0x256, 0 <= chan && chan < EXI_MAX_CHAN);
	if (chan == 2) {
		return TRUE;
	}

	rc      = TRUE;
	enabled = OSDisableInterrupts();
	cpr     = EXIREG(chan, 0);

	if (!(exi->state & EXI_STATE_ATTACHED)) {
		if (cpr & 0x00000800) {
			EXIClearInterrupts(chan, FALSE, FALSE, TRUE);
#if OS_BUILD_VERSION >= 20011112L
			exi->idTime = 0;
#endif
			__EXIProbeStartTime[chan] = 0;
		}

		if (cpr & 0x00001000) {
			t = (s32)(OSTicksToMilliseconds(OSGetTime()) / 100) + 1;
#if OS_BUILD_VERSION >= 20011112L
			if (__EXIProbeStartTime[chan] == 0)
#else
			if ((u32)__EXIProbeStartTime[chan] == 0)
#endif
			{
				__EXIProbeStartTime[chan] = t;
			}
			if (t - __EXIProbeStartTime[chan] < 300 / 100) {
				rc = FALSE;
			}
		} else {
#if OS_BUILD_VERSION >= 20011112L
			exi->idTime = 0;
#endif
			__EXIProbeStartTime[chan] = 0;
			rc                        = FALSE;
		}
	} else if (!(cpr & 0x00001000) || (cpr & 0x00000800)) {
#if OS_BUILD_VERSION >= 20011112L
		exi->idTime = 0;
#endif
		__EXIProbeStartTime[chan] = 0;
		rc                        = FALSE;
	}

	OSRestoreInterrupts(enabled);
	return rc;
}

#if OS_BUILD_VERSION >= 20011112L

/**
 * @TODO: Documentation
 */
BOOL EXIProbe(s32 chan)
{
	u32 id;
	EXIControl* exi;
	BOOL rc;

	exi = &Ecb[chan];
	rc  = __EXIProbe(chan);
	if (rc && exi->idTime == 0) {
		rc = EXIGetID(chan, 0, &id) ? TRUE : FALSE;
	}
	return rc;
}

#endif

/**
 * @TODO: Documentation
 */
s32 EXIProbeEx(s32 chan)
{
	if (EXIProbe(chan))
		return 1;
#if OS_BUILD_VERSION >= 20011112L
	if (__EXIProbeStartTime[chan] != 0)
#else
	if ((u32)__EXIProbeStartTime[chan] != 0)
#endif
		return 0;
	return -1;
}

/**
 * @TODO: Documentation
 * @note If `!(OS_BUILD_REVISION >= 20011112L)`, then this function is named `EXIAttach`.
 */
BOOL __EXIAttach(s32 chan, EXICallback extCallback)
{
	EXIControl* exi;
	BOOL enabled;
	BOOL rc;

	exi     = &Ecb[chan];
	enabled = OSDisableInterrupts();

#if OS_BUILD_VERSION >= 20011112L
	if ((exi->state & EXI_STATE_ATTACHED) || __EXIProbe(chan) == 0)
#else
	if ((exi->state & EXI_STATE_ATTACHED))
#endif
	{
		OSRestoreInterrupts(enabled);
		rc = FALSE;
	}
#if OS_BUILD_VERSION >= 20011112L
#else
	else if (__EXIProbe(chan) == FALSE) {
		OSRestoreInterrupts(enabled);
		rc = FALSE;
	}
#endif
	else {
		EXIClearInterrupts(chan, TRUE, FALSE, FALSE);
		exi->extCallback = extCallback;
		__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXT >> (chan * 3));
		exi->state |= EXI_STATE_ATTACHED;
		OSRestoreInterrupts(enabled);
		rc = TRUE;
	}

	return rc;
}

#if OS_BUILD_VERSION >= 20011112L

/**
 * @TODO: Documentation
 */
BOOL EXIAttach(s32 chan, EXICallback extCallback)
{
	EXIControl* exi;
	BOOL enabled;
	BOOL rc;

	exi = &Ecb[chan];
	OSAssertLine(0x2AE, 0 <= chan && chan < 2);

	EXIProbe(chan);

	enabled = OSDisableInterrupts();
	if (exi->idTime == 0) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}
	rc = __EXIAttach(chan, extCallback);

	OSRestoreInterrupts(enabled);
	return rc;
}

#endif

/**
 * @TODO: Documentation
 */
BOOL EXIDetach(s32 chan)
{
	EXIControl* exi;
	BOOL enabled;

	exi = &Ecb[chan];
	OSAssertLine(0x2D7, 0 <= chan && chan < 2);
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
	__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0 >> (chan * 3));

	OSRestoreInterrupts(enabled);
	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL EXISelect(s32 chan, u32 dev, u32 freq)
{
	EXIControl* exi;
	u32 cpr;
	BOOL enabled;

	exi = &Ecb[chan];
	OSAssertLine(0x2FF, 0 <= chan && chan < EXI_MAX_CHAN);
	OSAssertLine(0x300, chan == 0 && dev < EXI_MAX_DEV || dev == 0);
	OSAssertLine(0x301, freq < EXI_MAX_FREQ);
	OSAssertLine(0x302, !(exi->state & EXI_STATE_SELECTED));
	enabled = OSDisableInterrupts();

	if ((exi->state & EXI_STATE_SELECTED)
	    || chan != 2
	           && (dev == 0 && !(exi->state & EXI_STATE_ATTACHED) && !__EXIProbe(chan) || !(exi->state & EXI_STATE_LOCKED)
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
	EXIControl* exi;
	u32 cpr;
	BOOL enabled;

	exi = &Ecb[chan];
	OSAssertLine(0x335, 0 <= chan && chan < EXI_MAX_CHAN);
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
		return __EXIProbe(chan) ? TRUE : FALSE;
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
	OSAssertLine(0x368, 0 <= chan && chan < EXI_MAX_CHAN);
	exi = &Ecb[chan];

	EXIClearInterrupts(chan, TRUE, FALSE, FALSE);
	callback = exi->exiCallback;
	if (callback) {
#if OS_BUILD_VERSION >= 20011112L
		OSContext exceptionContext;
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
#endif
		callback(chan, context);
#if OS_BUILD_VERSION >= 20011112L
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
#endif
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

	chan = (interrupt - __OS_INTERRUPT_EXI_0_TC) / 3;
	OSAssertLine(0x383, 0 <= chan && chan < EXI_MAX_CHAN);
	exi = &Ecb[chan];

	__OSMaskInterrupts(OS_INTERRUPTMASK(interrupt));
	EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
	callback = exi->tcCallback;
	if (callback) {
#if OS_BUILD_VERSION >= 20011112L
		OSContext exceptionContext;
#endif
		exi->tcCallback = NULL;
		CompleteTransfer(chan);
#if OS_BUILD_VERSION >= 20011112L
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
#endif
		callback(chan, context);
#if OS_BUILD_VERSION >= 20011112L
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
#endif
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
	OSAssertLine(0x3A2, 0 <= chan && chan < 2);

	__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0 >> (chan * 3));
	EXIREG(chan, 0) = 0;
	exi             = &Ecb[chan];
	callback        = exi->extCallback;
	exi->state &= ~EXI_STATE_ATTACHED;
	if (callback) {
#if OS_BUILD_VERSION >= 20011112L
		OSContext exceptionContext;
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
#endif
		exi->extCallback = NULL;
		callback(chan, context);
#if OS_BUILD_VERSION >= 20011112L
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
#endif
	}
}

/**
 * @TODO: Documentation
 */
void EXIInit(void)
{
	__OSMaskInterrupts(OS_INTERRUPTMASK_EXI);

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

	if (OSGetConsoleType() & OS_CONSOLE_DEVELOPMENT) {
		EXIProbeReset();
	}
}

/**
 * @TODO: Documentation
 */
BOOL EXILock(s32 chan, u32 dev, EXICallback unlockedCallback)
{
	EXIControl* exi;
	BOOL enabled;
	int i;

	exi = &Ecb[chan];
	OSAssertLine(0x3F2, 0 <= chan && chan < EXI_MAX_CHAN);
	OSAssertLine(0x3F3, chan == 0 && dev < EXI_MAX_DEV || dev == 0);
	enabled = OSDisableInterrupts();

	if (exi->state & EXI_STATE_LOCKED) {
		if (unlockedCallback) {
			OSAssertLine(0x3F9, chan == 0 && exi->items < (EXI_MAX_DEV - 1) || exi->items == 0);
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

	OSAssertLine(0x409, exi->items == 0);
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
	EXIControl* exi;
	BOOL enabled;
	EXICallback unlockedCallback;

	exi = &Ecb[chan];
	OSAssertLine(0x421, 0 <= chan && chan < EXI_MAX_CHAN);
	enabled = OSDisableInterrupts();

	if (!(exi->state & EXI_STATE_LOCKED)) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}
	exi->state &= ~EXI_STATE_LOCKED;
	SetExiInterruptMask(chan, exi);

	if (exi->items > 0) {
		unlockedCallback = exi->queue[0].callback;
		if (--exi->items > 0) {
			memmove(&exi->queue[0], &exi->queue[1], exi->items * sizeof(exi->queue[0]));
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
	EXIControl* exi;

	exi = &Ecb[chan];
	OSAssertLine(0x446, 0 <= chan && chan < EXI_MAX_CHAN);
	return exi->state;
}

/**
 * @TODO: Documentation
 */
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
#if OS_BUILD_VERSION >= 20011112L
	EXIControl* exi;
	BOOL err;
	u32 cmd;
	s32 startTime;
	BOOL enabled;

	exi = &Ecb[chan];
	OSAssertLine(0x45A, 0 <= chan && chan < EXI_MAX_CHAN);

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
	if (!err) {
		err = !EXISelect(chan, dev, EXI_FREQ_1M);
		if (!err) {
			cmd = 0;
			err |= !EXIImm(chan, &cmd, 2, EXI_WRITE, NULL);
			err |= !EXISync(chan);
			err |= !EXIImm(chan, id, 4, EXI_READ, NULL);
			err |= !EXISync(chan);
			err |= !EXIDeselect(chan);
		}
		EXIUnlock(chan);
	}

	if (chan < 2 && dev == 0) {
		EXIDetach(chan);
		enabled = OSDisableInterrupts();
		err |= (startTime != __EXIProbeStartTime[chan]);
		if (!err) {
			exi->id     = *id;
			exi->idTime = startTime;
		}
		OSRestoreInterrupts(enabled);

		return err ? 0 : exi->idTime;
	}

	return err ? 0 : 1;
#endif
}
