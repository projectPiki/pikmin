#include "Dolphin/hio.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include <stddef.h>

static s32 Chan = -1;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
static u32 Dev;
#endif
static HIOCallback ExiCallback;
static HIOCallback TxCallback;
static HIOCallback RxCallback;

/**
 * @TODO: Documentation
 */
static void ExtHandler(s32 chan, OSContext* context)
{
	Chan = -1;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	Dev = 0;
	if ((chan < 2)) {
		EXISetExiCallback(chan, NULL);
		return;
	}
#endif
}

/**
 * @TODO: Documentation
 */
static void ExiHandler(s32 chan, OSContext* context)
{
	if (ExiCallback) {
		ExiCallback();
	}
}

/**
 * @TODO: Documentation
 */
static void DbgHandler(__OSInterrupt interrupt, OSContext* context)
{
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	OSContext exceptionContext;
#endif

	__PIRegs[0] = 0x1000;
	if (ExiCallback) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(&exceptionContext);
		ExiCallback();
		OSClearContext(&exceptionContext);
		OSSetCurrentContext(context);
#else
		ExiCallback();
#endif
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
static void TxHandler(s32 chan, OSContext* context)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
static void RxHandler(s32 chan, OSContext* context)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
BOOL HIOEnumDevices(HIOEnumCallback callback)
{
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	s32 chan;
	u32 id;

	if (Chan != -1 || callback == NULL) {
		return FALSE;
	}
	Dev = 0;
	for (chan = 0; chan <= 2; chan++) {
		if (chan < 2) {
			do {
			} while (EXIProbeEx(chan) == 0);
		}
		if ((EXIGetID(chan, Dev, &id) != 0) && ((u32)(id + 0xFEFF0000) == 0U) && (callback(chan) == 0)) {
			return TRUE;
		}
	}
	return TRUE;
#else
	BOOL result;
	s32 chan;
	int err;
	u32 cmd;
	u32 id;

	if (Chan == -1 && callback) {
		result = TRUE;
		for (chan = 0; chan <= 2; chan++) {
			if (chan < 2) {
				while (EXIProbeEx(chan) == 0) { }
				if (EXIAttach(chan, ExtHandler) == 0) {
					continue;
				}
			}
			if (EXILock(chan, 0, NULL) == 0) {
				EXIDetach(chan);
				continue;
			}
			if (EXISelect(chan, 0, 0) == 0) {
				EXIUnlock(chan);
				EXIDetach(chan);
				continue;
			}
			cmd = 0;
			err = 0;
			err |= !EXIImm(chan, &cmd, 2, 1, NULL);
			err |= !EXISync(chan);
			err |= !EXIImm(chan, &id, 4, 0, NULL);
			err |= !EXISync(chan);
			err |= !EXIDeselect(chan);
			EXIUnlock(chan);
			if (err == 0 && id == 0x1010000) {
				result = callback(chan);
			}
			if (chan < 2) {
				EXIDetach(chan);
			}
			EXIUnlock(chan);
			if (result == FALSE) {
				return TRUE;
			}
		}
		return TRUE;
	}
	return FALSE;
#endif
}

/**
 * @TODO: Documentation
 */
BOOL HIOInit(s32 chan, HIOCallback callback)
{
	int err;
	u32 cmd;
	u32 id;

	if (__OSGetDIConfig() == 0xFF) {
		Chan = -1;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		Dev = 0;
#endif
		return FALSE;
	}

	if (Chan != -1) {
		return TRUE;
	}

	Chan        = chan;
	ExiCallback = callback;
	TxCallback  = NULL;
	RxCallback  = NULL;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	if (chan < 2 && Dev == 0) {
#else
	if (chan < 2) {
#endif
		while (EXIProbeEx(Chan) == 0) { }
		if (EXIAttach(Chan, ExtHandler) == FALSE) {
			Chan = -1;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
			Dev = 0;
#endif
			return FALSE;
		}
	}
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	if (EXILock(Chan, Dev, NULL) == FALSE) {
#else
	if (EXILock(Chan, 0, NULL) == FALSE) {
#endif
		EXIDetach(Chan);
		Chan = -1;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		Dev = 0;
#endif
		return FALSE;
	}
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	if (EXISelect(Chan, Dev, 0) == FALSE) {
#else
	if (EXISelect(Chan, 0, 0) == FALSE) {
#endif
		EXIUnlock(Chan);
		EXIDetach(Chan);
		Chan = -1;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		Dev = 0;
#endif
		return FALSE;
	}
	cmd = 0;
	err = 0;
	err |= !EXIImm(Chan, &cmd, 2, 1, NULL);
	err |= !EXISync(Chan);
	err |= !EXIImm(Chan, &id, 4, 0, NULL);
	err |= !EXISync(Chan);
	err |= !EXIDeselect(Chan);
	EXIUnlock(Chan);
	if (err != 0 || id != 0x1010000) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		if (chan < 2 && Dev == 0) {
#else
		if (chan < 2) {
#endif
			EXIDetach(Chan);
		}
		EXIUnlock(Chan);
		Chan = -1;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
		Dev = 0;
#endif
		return FALSE;
	}
	if (ExiCallback) {
		if (chan < 2) {
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
			if (Dev == 0) {
				EXISetExiCallback(Chan, ExiHandler);
			} else {
				EXISetExiCallback(2, ExiHandler);
			}
#else
			EXISetExiCallback(Chan, ExiHandler);
#endif
		} else {
			__OSSetInterruptHandler(0x19, DbgHandler);
			__OSUnmaskInterrupts(0x40);
		}
	}

	return TRUE;
}

/**
 * @TODO: Documentation
 */
BOOL HIOReadMailbox(u32* word)
{
	int err;
	u32 cmd;

	if (Chan == -1 || __OSGetDIConfig() == 0xFF) {
		return FALSE;
	}

#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	if (EXILock(Chan, Dev, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, Dev, 4) == FALSE) {
#else
	if (EXILock(Chan, 0, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, 0, 4) == FALSE) {
#endif
		EXIUnlock(Chan);
		return FALSE;
	}

	cmd = 0x60000000;
	err = 0;
	err |= !EXIImm(Chan, &cmd, 2, 1, NULL);
	err |= !EXISync(Chan);
	err |= !EXIImm(Chan, word, 4, 0, NULL);
	err |= !EXISync(Chan);
	err |= !EXIDeselect(Chan);
	EXIUnlock(Chan);
	return !err;
}

/**
 * @TODO: Documentation
 */
BOOL HIOWriteMailbox(u32 word)
{
	int err;
	u32 cmd;

	if (Chan == -1 || __OSGetDIConfig() == 0xFF) {
		return FALSE;
	}
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	if (EXILock(Chan, Dev, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, Dev, 4) == FALSE) {
#else
	if (EXILock(Chan, 0, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, 0, 4) == FALSE) {
#endif
		EXIUnlock(Chan);
		return FALSE;
	}
	cmd = (word & 0x1FFFFFFF) | 0xC0000000;
	err = 0;
	err |= !EXIImm(Chan, &cmd, 4, 1, NULL);
	err |= !EXISync(Chan);
	err |= !EXIDeselect(Chan);
	EXIUnlock(Chan);
	return !err;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000144
 */
BOOL HIORead(u32 addr, void* buffer, s32 size)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
BOOL HIOWrite(u32 addr, void* buffer, s32 size)
{
	int err;
	u32 cmd;

	if (Chan == -1 || __OSGetDIConfig() == 0xFF) {
		return FALSE;
	}

#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
	if (EXILock(Chan, Dev, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, Dev, 4) == FALSE) {
#else
	if (EXILock(Chan, 0, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, 0, 4) == FALSE) {
#endif
		EXIUnlock(Chan);
		return FALSE;
	}
	cmd = ((addr << 8) & 0x01FFFC00) | 0xA0000000;
	err = 0;
	err |= !EXIImm(Chan, &cmd, 4, 1, NULL);
	err |= !EXISync(Chan);
	err |= !EXIDma(Chan, buffer, size, 1, NULL);
	err |= !EXISync(Chan);
	err |= !EXIDeselect(Chan);
	EXIUnlock(Chan);
	return !err;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000128
 */
BOOL HIOReadAsync(u32 addr, void* buffer, s32 size, HIOCallback callback)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000128
 */
BOOL HIOWriteAsync(u32 addr, void* buffer, s32 size, HIOCallback callback)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000130
 */
BOOL HIOReadStatus(u32* status)
{
	// UNUSED FUNCTION
}
