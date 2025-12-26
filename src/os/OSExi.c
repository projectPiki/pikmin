#include "Dolphin/os.h"

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
		if ((exi->exiCallback == 0 && exi2->exiCallback == 0) || (exi->state & EXI_STATE_LOCKED)) {
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_2_EXI);
		} else {
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_2_EXI);
		}
		break;
	case 1:
		if (exi->exiCallback == 0 || (exi->state & EXI_STATE_LOCKED)) {
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXI);
		} else {
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXI);
		}
		break;
	case 2:
		if (__OSGetInterruptHandler(__OS_INTERRUPT_PI_DEBUG) == 0 || (exi->state & EXI_STATE_LOCKED)) {
			__OSMaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);
		} else {
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_PI_DEBUG);
		}
		break;
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
#if defined(VERSION_G98E01_PIKIDEMO)
	Ecb[0].idTime = Ecb[1].idTime = 0;
#endif
	__EXIProbe(0);
	__EXIProbe(1);
	// UNUSED FUNCTION
}

#if defined(VERSION_G98E01_PIKIDEMO)
static BOOL __EXIProbe(s32 chan)
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
			__EXIProbeStartTime[chan] = exi->idTime = 0;
		}

		if (cpr & 0x00001000) {
			t = (s32)(OSTicksToMilliseconds(OSGetTime()) / 100) + 1;
			if (__EXIProbeStartTime[chan] == 0) {
				__EXIProbeStartTime[chan] = t;
			}
			if (t - __EXIProbeStartTime[chan] < 300 / 100) {
				rc = FALSE;
			}
		} else {
			__EXIProbeStartTime[chan] = exi->idTime = 0;
			rc                                      = FALSE;
		}
	} else if (!(cpr & 0x00001000) || (cpr & 0x00000800)) {
		__EXIProbeStartTime[chan] = exi->idTime = 0;
		rc                                      = FALSE;
	}
	OSRestoreInterrupts(enabled);

	return rc;
}
#endif

/**
 * @TODO: Documentation
 */
BOOL EXIProbe(s32 chan)
{
#if defined(VERSION_G98E01_PIKIDEMO)

	EXIControl* exi = &Ecb[chan];
	BOOL rc;
	u32 id;

	rc = __EXIProbe(chan);
	if (rc && exi->idTime == 0) {
		rc = EXIGetID(chan, 0, &id) ? TRUE : FALSE;
	}
	return rc;
#else
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
#endif
}

/**
 * @TODO: Documentation
 */
s32 EXIProbeEx(s32 chan)
{
	if (EXIProbe(chan)) {
		return 1;
#if defined(VERSION_G98E01_PIKIDEMO)
	} else if (__EXIProbeStartTime[chan] != 0) {
#else
	} else if ((u32)__EXIProbeStartTime[chan] != 0) {
#endif
		return 0;
	}
	return -1;
}

/**
 * @TODO: Documentation
 */
BOOL EXIAttach(s32 chan, EXICallback extCallback)
{
#if defined(VERSION_G98E01_PIKIDEMO)

	EXIControl* exi = &Ecb[chan];
	BOOL enabled, enabled2;
	BOOL rc;

	u32 stack1; // unused, just stack filling
	u32 stack2; // unused, just stack filling

	EXIProbe(chan);

	enabled = OSDisableInterrupts();
	if (exi->idTime == 0) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}

	enabled2 = OSDisableInterrupts();
	if (!(exi->state & 8) && !__EXIProbe(chan)) {
		OSRestoreInterrupts(enabled2);
		rc = FALSE;
	} else {
		EXIClearInterrupts(chan, TRUE, FALSE, FALSE);

		exi->extCallback = extCallback;
		__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXT >> (3 * chan));
		exi->state |= EXI_STATE_ATTACHED;
		OSRestoreInterrupts(enabled2);
		rc = TRUE;
	}
	OSRestoreInterrupts(enabled);
	return rc;
#else

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
#endif
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
#if defined(VERSION_G98E01_PIKIDEMO)
	if ((exi->state & EXI_STATE_SELECTED)
	    || chan != 2
	           && (dev == 0 && !(exi->state & EXI_STATE_ATTACHED) && !__EXIProbe(chan) || !(exi->state & EXI_STATE_LOCKED)
	               || (exi->dev != dev))) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}
#else
	if ((exi->state & EXI_STATE_SELECTED)
	    || chan != 2
	           && (dev == 0 && !(exi->state & EXI_STATE_ATTACHED) && !EXIProbe(chan) || !(exi->state & EXI_STATE_LOCKED)
	               || (exi->dev != dev))) {
		OSRestoreInterrupts(enabled);
		return FALSE;
	}
#endif

	exi->state |= EXI_STATE_SELECTED;
	cpr = EXIREG(chan, 0);
	cpr &= 0x405;
	cpr |= EXI_CPR_CS(dev) | EXI_CPR_CLK(freq);
	EXIREG(chan, 0) = cpr;

	if (exi->state & EXI_STATE_ATTACHED) {
		switch (chan) {
		case 0:
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXT);
			break;
		case 1:
			__OSMaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXT);
			break;
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
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXT);
			break;
		case 1:
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_1_EXT);
			break;
		}
	}

	OSRestoreInterrupts(enabled);

#if defined(VERSION_G98E01_PIKIDEMO)
	if (chan != 2 && (cpr & EXI_CPR_CS(0))) {
		return __EXIProbe(chan) ? TRUE : FALSE;
	}
#else
	if (chan != 2 && (cpr & EXI_CPR_CS(0))) {
		return EXIProbe(chan) ? TRUE : FALSE;
	}
#endif

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
#if defined(VERSION_G98E01_PIKIDEMO)
	OSContext exceptionContext;
	int pad, pad2;
#endif

	chan = (interrupt - __OS_INTERRUPT_EXI_0_EXI) / 3;
	exi  = &Ecb[chan];
	EXIClearInterrupts(chan, TRUE, FALSE, FALSE);
	callback = exi->exiCallback;
	if (callback) {
#if defined(VERSION_G98E01_PIKIDEMO)

		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
		callback(chan, context);
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
#else
		callback(chan, context);
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
#if defined(VERSION_G98E01_PIKIDEMO)
	OSContext exceptionContext;
#endif
	int pad, pad2;

	chan = (interrupt - __OS_INTERRUPT_EXI_0_TC) / 3;
	exi  = &Ecb[chan];
	__OSMaskInterrupts(OS_INTERRUPTMASK(interrupt));
	EXIClearInterrupts(chan, FALSE, TRUE, FALSE);
	callback = exi->tcCallback;
	if (callback) {
		exi->tcCallback = 0;
		CompleteTransfer(chan);
#if defined(VERSION_G98E01_PIKIDEMO)
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
		callback(chan, context);
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
#else
		callback(chan, context);
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
#if defined(VERSION_G98E01_PIKIDEMO)
	OSContext exceptionContext;
#endif

	chan = (interrupt - __OS_INTERRUPT_EXI_0_EXT) / 3;
	__OSMaskInterrupts((OS_INTERRUPTMASK_EXI_0_EXT | OS_INTERRUPTMASK_EXI_0_EXI | OS_INTERRUPTMASK_EXI_0_TC) >> (3 * chan));
	__EXIRegs[(chan * 5)] = 0;

	exi      = &Ecb[chan];
	callback = exi->extCallback;
	exi->state &= ~EXI_STATE_ATTACHED;
	if (callback) {
#if defined(VERSION_G98E01_PIKIDEMO)
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
		exi->extCallback = 0;
		callback(chan, context);
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
#else
		exi->extCallback = 0;
		callback(chan, context);
#endif
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
#if defined(VERSION_G98E01_PIKIDEMO)
		__EXIProbeStartTime[0] = __EXIProbeStartTime[1] = 0;
		Ecb[1].idTime                                   = 0;
		Ecb[0].idTime                                   = 0;
		__EXIProbe(0);
		__EXIProbe(1);
#else
		__EXIProbeStartTime[0] = __EXIProbeStartTime[1] = 0;
		EXIProbe(0);
		EXIProbe(1);
#endif
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
#if defined(VERSION_G98E01_PIKIDEMO)
	EXIControl* exi = &Ecb[chan];
	BOOL err;
	u32 cmd;
	s32 startTime;
	BOOL enabled;

	if (chan < 2 && dev == 0) {
		if (!__EXIProbe(chan)) {
			return 0;
		}

		if (exi->idTime == __EXIProbeStartTime[chan]) {
			*id = exi->id;
			return exi->idTime;
		}

		enabled = OSDisableInterrupts();
		if (!(exi->state & 8) && !__EXIProbe(chan)) {
			OSRestoreInterrupts(enabled);
			err = FALSE;
		} else {
			EXIClearInterrupts(chan, TRUE, FALSE, FALSE);

			exi->extCallback = 0;
			__OSUnmaskInterrupts(OS_INTERRUPTMASK_EXI_0_EXT >> (3 * chan));
			exi->state |= EXI_STATE_ATTACHED;
			OSRestoreInterrupts(enabled);
			err = TRUE;
		}
		if (!err) {
			return FALSE;
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

	return err ? 0 : !0;
#endif
}
