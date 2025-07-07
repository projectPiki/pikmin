#include "Dolphin/hio.h"
#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"

static s32 Chan = -1;
static HIOCallback ExiCallback;
static HIOCallback TxCallback;
static HIOCallback RxCallback;

/*
 * --INFO--
 * Address:	8020D388
 * Size:	00000C
 */
static void ExtHandler(s32 chan, OSContext* context)
{
	Chan = -1;
}

/*
 * --INFO--
 * Address:	8020D394
 * Size:	000030
 */
static void ExiHandler(s32 chan, OSContext* context)
{
	if (ExiCallback) {
		ExiCallback();
	}
}

/*
 * --INFO--
 * Address:	8020D3C4
 * Size:	00003C
 */
static void DbgHandler(__OSInterrupt interrupt, OSContext* context)
{
	__PIRegs[PI_INTRPT_SRC] = 0x1000;
	if (ExiCallback) {
		ExiCallback();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
static void TxHandler(s32 chan, OSContext* context)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
static void RxHandler(s32 chan, OSContext* context)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020D400
 * Size:	0001C4
 */
BOOL HIOEnumDevices(HIOEnumCallback callback)
{
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
}

/*
 * --INFO--
 * Address:	8020D5C4
 * Size:	000234
 */
BOOL HIOInit(s32 chan, HIOCallback callback)
{
	int err;
	u32 cmd;
	u32 id;

	if (__OSGetDIConfig() == 0xFF) {
		Chan = -1;
		return FALSE;
	}

	if (Chan != -1) {
		return TRUE;
	}

	Chan        = chan;
	ExiCallback = callback;
	TxCallback  = NULL;
	RxCallback  = NULL;
	if (chan < 2) {
		while (EXIProbeEx(Chan) == 0) { }
		if (EXIAttach(Chan, ExtHandler) == FALSE) {
			Chan = -1;
			return FALSE;
		}
	}
	if (EXILock(Chan, 0, NULL) == FALSE) {
		EXIDetach(Chan);
		Chan = -1;
		return FALSE;
	}
	if (EXISelect(Chan, 0, 0) == FALSE) {
		EXIUnlock(Chan);
		EXIDetach(Chan);
		Chan = -1;
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
		if (chan < 2) {
			EXIDetach(Chan);
		}
		EXIUnlock(Chan);
		Chan = -1;
		return FALSE;
	}
	if (ExiCallback) {
		if (chan < 2) {
			EXISetExiCallback(Chan, ExiHandler);
		} else {
			__OSSetInterruptHandler(0x19, DbgHandler);
			__OSUnmaskInterrupts(0x40);
		}
	}

	return TRUE;
}

/*
 * --INFO--
 * Address:	8020D7F8
 * Size:	000130
 */
BOOL HIOReadMailbox(u32* word)
{
	int err;
	u32 cmd;

	if (Chan == -1 || __OSGetDIConfig() == 0xFF) {
		return FALSE;
	}

	if (EXILock(Chan, 0, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, 0, 4) == FALSE) {
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

/*
 * --INFO--
 * Address:	8020D928
 * Size:	0000F4
 */
BOOL HIOWriteMailbox(u32 word)
{
	int err;
	u32 cmd;

	if (Chan == -1 || __OSGetDIConfig() == 0xFF) {
		return FALSE;
	}
	if (EXILock(Chan, 0, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, 0, 4) == FALSE) {
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

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
BOOL HIORead(u32 addr, void* buffer, s32 size)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020DA1C
 * Size:	000144
 */
BOOL HIOWrite(u32 addr, void* buffer, s32 size)
{
	int err;
	u32 cmd;

	if (Chan == -1 || __OSGetDIConfig() == 0xFF) {
		return FALSE;
	}

	if (EXILock(Chan, 0, NULL) == FALSE) {
		return FALSE;
	}
	if (EXISelect(Chan, 0, 4) == FALSE) {
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

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
BOOL HIOReadAsync(u32 addr, void* buffer, s32 size, HIOCallback callback)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
BOOL HIOWriteAsync(u32 addr, void* buffer, s32 size, HIOCallback callback)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
BOOL HIOReadStatus(u32* status)
{
	// UNUSED FUNCTION
}
