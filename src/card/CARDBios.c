#include "Dolphin/card.h"
#include "Dolphin/exi.h"
#include <stddef.h>

#if OS_BUILD_VERSION >= 20011112L
#else
DVDDiskID* __CARDDiskID;
#endif

DVDDiskID __CARDDiskNone;
CARDControl __CARDBlock[2];

static s32 Retry(s32 chan);
static BOOL OnReset(BOOL f);

static OSResetFunctionInfo ResetFunctionInfo = { OnReset, 127 };

#define AD1(x)   ((u8)(((x) >> 17) & 0x7f))
#define AD1EX(x) ((u8)(AD1(x) | 0x80));
#define AD2(x)   ((u8)(((x) >> 9) & 0xff))
#define AD3(x)   ((u8)(((x) >> 7) & 0x03))
#define BA(x)    ((u8)((x) & 0x7f))

/**
 * @TODO: Documentation
 */
void __CARDDefaultApiCallback(s32, s32)
{
}

/**
 * @TODO: Documentation
 */
void __CARDSyncCallback(s32 chan, s32 result)
{
	OSWakeupThread(&__CARDBlock[chan].threadQueue);
}

/**
 * @TODO: Documentation
 */
void __CARDExtHandler(s32 chan, OSContext* context)
{
	CARDControl* card;
	CARDCallback callback;

	card = &__CARDBlock[chan];
	if (card->attached) {
		card->attached = FALSE;
#if OS_BUILD_VERSION >= 20011002L
#else
		card->result = CARD_RESULT_NOCARD;
#endif
		EXISetExiCallback(chan, NULL);
		OSCancelAlarm(&card->alarm);
		callback = card->exiCallback;

		if (callback) {
			card->exiCallback = NULL;
			callback(chan, CARD_RESULT_NOCARD);
		}

#if OS_BUILD_VERSION >= 20011002L
		if (card->result != CARD_RESULT_BUSY) {
			card->result = CARD_RESULT_NOCARD;
		}
#endif

		callback = card->extCallback;
		if (callback && CARD_MAX_MOUNT_STEP <= card->mountStep) {
			card->extCallback = NULL;
			callback(chan, CARD_RESULT_NOCARD);
		}
	}
}

/**
 * @TODO: Documentation
 */
void __CARDExiHandler(s32 chan, OSContext* context)
{
	CARDControl* card;
	CARDCallback callback;
	u8 status;
	s32 result;

	OSAssertLine(0xDC, 0 <= chan && chan < 2);

	card = &__CARDBlock[chan];

	OSCancelAlarm(&card->alarm);

	if (!card->attached) {
		return;
	}

	if (!EXILock(chan, 0, 0)) {
		result = CARD_RESULT_FATAL_ERROR;
		goto fatal;
	}

	if ((result = __CARDReadStatus(chan, &status)) < 0 || (result = __CARDClearStatus(chan)) < 0) {
		goto error;
	}

	if ((result = (status & 0x18) ? CARD_RESULT_IOERROR : CARD_RESULT_READY) == CARD_RESULT_IOERROR && --card->retry > 0) {
		result = Retry(chan);
		if (result >= CARD_RESULT_READY) {
			return;
		}
		goto fatal;
	}

error:
	EXIUnlock(chan);

fatal:
	callback = card->exiCallback;
	if (callback) {
		card->exiCallback = NULL;
		callback(chan, result);
	}
}

/**
 * @TODO: Documentation
 */
void __CARDTxHandler(s32 chan, OSContext* context)
{
	CARDControl* card;
	CARDCallback callback;
	BOOL err;

	card = &__CARDBlock[chan];
	err  = !EXIDeselect(chan);
	EXIUnlock(chan);
	callback = card->txCallback;
	if (callback) {
		card->txCallback = NULL;
		callback(chan, (!err && EXIProbe(chan)) ? CARD_RESULT_READY : CARD_RESULT_NOCARD);
	}
}

/**
 * @TODO: Documentation
 */
void __CARDUnlockedHandler(s32 chan, OSContext* context)
{
	CARDControl* card;
	CARDCallback callback;

	card     = &__CARDBlock[chan];
	callback = card->unlockCallback;
	if (callback) {
		card->unlockCallback = NULL;
		callback(chan, EXIProbe(chan) ? CARD_RESULT_UNLOCKED : CARD_RESULT_NOCARD);
	}
}

/**
 * @TODO: Documentation
 */
int __CARDReadNintendoID(s32 chan, u32* id)
{
	BOOL err;
	u32 cmd;

	if (!EXISelect(chan, 0, 0)) {
		return CARD_RESULT_NOCARD;
	}

	cmd = 0;
	err = 0;
	err |= !EXIImm(chan, &cmd, 2, EXI_WRITE, NULL);
	err |= !EXISync(chan);
	err |= !EXIImm(chan, id, 4, EXI_READ, NULL);
	err |= !EXISync(chan);
	err |= !EXIDeselect(chan);

	if (err) {
		return CARD_RESULT_NOCARD;
	}

	if ((*id & 0xFFFF0000) || (*id & 3)) {
		return CARD_RESULT_WRONGDEVICE;
	}

	return CARD_RESULT_READY;
}

/**
 * @TODO: Documentation
 */
s32 __CARDEnableInterrupt(s32 chan, BOOL enable)
{
	BOOL err;
	u32 cmd;

	if (!EXISelect(chan, 0, 4)) {
		return CARD_RESULT_NOCARD;
	}

	cmd = enable ? 0x81010000 : 0x81000000;
	err = FALSE;
	err |= !EXIImm(chan, &cmd, 2, 1, NULL);
	err |= !EXISync(chan);
	err |= !EXIDeselect(chan);
	return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

/**
 * @TODO: Documentation
 */
s32 __CARDReadStatus(s32 chan, u8* status)
{
	BOOL err;
	u32 cmd;

	if (!EXISelect(chan, 0, 4)) {
		return CARD_RESULT_NOCARD;
	}

	cmd = 0x83000000;
	err = FALSE;
	err |= !EXIImm(chan, &cmd, 2, 1, NULL);
	err |= !EXISync(chan);
	err |= !EXIImm(chan, status, 1, 0, NULL);
	err |= !EXISync(chan);
	err |= !EXIDeselect(chan);
	return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

/**
 * @TODO: Documentation
 */
s32 __CARDClearStatus(s32 chan)
{
	BOOL err;
	u32 cmd;

	if (!EXISelect(chan, 0, 4)) {
		return CARD_RESULT_NOCARD;
	}

	cmd = 0x89000000;
	err = FALSE;
	err |= !EXIImm(chan, &cmd, 1, 1, NULL);
	err |= !EXISync(chan);
	err |= !EXIDeselect(chan);

	return err ? CARD_RESULT_NOCARD : CARD_RESULT_READY;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000AC
 */
void __CARDSleep(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000AC
 */
void __CARDWakeup(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
static void TimeoutHandler(OSAlarm* alarm, OSContext* context)
{
	s32 chan;
	CARDControl* card;
	CARDCallback callback;
	for (chan = 0; chan < 2; chan++) {
		card = &__CARDBlock[chan];
		if (alarm == &card->alarm) {
			break;
		}
	}

	if (!card->attached) {
		return;
	}

	EXISetExiCallback(chan, NULL);
	callback = card->exiCallback;
	if (callback) {
		card->exiCallback = NULL;
		callback(chan, CARD_RESULT_IOERROR);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F8
 */
static void SetupTimeoutAlarm(CARDControl* card)
{
	OSCancelAlarm(&card->alarm);
	switch (card->cmd[0]) {
	case 0xF2:
	{
		OSSetAlarm(&card->alarm, OSMillisecondsToTicks(100), TimeoutHandler);
		break;
	}
	case 0xF3:
	{
		break;
	}
	case 0xF4:
	case 0xF1:
	{
		OSSetAlarm(&card->alarm, OSSecondsToTicks((OSTime)2) * (card->sectorSize / 0x2000), TimeoutHandler);
		break;
	}
	}
}

/**
 * @TODO: Documentation
 */
static s32 Retry(s32 chan)
{
	CARDControl* card;
	card = &__CARDBlock[chan];

	if (!EXISelect(chan, 0, 4)) {
		EXIUnlock(chan);
		return CARD_RESULT_NOCARD;
	}

	SetupTimeoutAlarm(card);

	if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1)) {
		EXIDeselect(chan);
		EXIUnlock(chan);
		return CARD_RESULT_NOCARD;
	}

	if (card->cmd[0] == 0x52 && !EXIImmEx(chan, card->workArea->header.buffer, card->latency, 1)) {
		EXIDeselect(chan);
		EXIUnlock(chan);
		return CARD_RESULT_NOCARD;
	}

	if (card->mode == 0xffffffff) {
		EXIDeselect(chan);
		EXIUnlock(chan);
		return CARD_RESULT_READY;
	}

	if (!EXIDma(chan, card->buffer, (s32)((card->cmd[0] == 0x52) ? 512 : 128), card->mode, __CARDTxHandler)) {
		EXIDeselect(chan);
		EXIUnlock(chan);
		return CARD_RESULT_NOCARD;
	}

	return CARD_RESULT_READY;
}

/**
 * @TODO: Documentation
 */
static void UnlockedCallback(s32 chan, s32 result)
{
	CARDCallback callback;
	CARDControl* card;

	card = &__CARDBlock[chan];
	if (result >= CARD_RESULT_READY) {
		card->unlockCallback = UnlockedCallback;
		if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
			result = CARD_RESULT_READY;
		} else {
			card->unlockCallback = NULL;
			result               = Retry(chan);
		}
	}

	if (result < CARD_RESULT_READY) {
		switch (card->cmd[0]) {
		case 0x52:
		{
			callback = card->txCallback;
			if (callback) {
				card->txCallback = NULL;
				callback(chan, result);
			}
			break;
		}
		case 0xF2:
		case 0xF4:
		case 0xF1:
		{
			callback = card->exiCallback;
			if (callback) {
				card->exiCallback = NULL;
				callback(chan, result);
			}
			break;
		}
		}
	}
}

/**
 * @TODO: Documentation
 */
static s32 __CARDStart(s32 chan, CARDCallback txCallback, CARDCallback exiCallback)
{
#if OS_BUILD_VERSION >= 20011002L
	BOOL enabled;
#endif
	CARDControl* card;
	s32 result;

#if OS_BUILD_VERSION >= 20011002L
	enabled = OSDisableInterrupts();
#endif

	card = &__CARDBlock[chan];
	if (!card->attached) {
		result = CARD_RESULT_NOCARD;
	} else {

		if (txCallback) {
			card->txCallback = txCallback;
		}
		if (exiCallback) {
			card->exiCallback = exiCallback;
		}
		card->unlockCallback = UnlockedCallback;
		if (!EXILock(chan, 0, __CARDUnlockedHandler)) {
			result = CARD_RESULT_BUSY;
		} else {
			card->unlockCallback = NULL;

			if (!EXISelect(chan, 0, 4)) {
				EXIUnlock(chan);
				result = CARD_RESULT_NOCARD;
			} else {
				SetupTimeoutAlarm(card);
				result = CARD_RESULT_READY;
			}
		}
	}

#if OS_BUILD_VERSION >= 20011002L
	OSRestoreInterrupts(enabled);
#endif

	return result;
}

/**
 * @TODO: Documentation
 */
s32 __CARDReadSegment(s32 chan, CARDCallback callback)
{
	CARDControl* card;
	s32 result;

	card         = &__CARDBlock[chan];
	card->cmd[0] = 0x52;
	card->cmd[1] = AD1(card->addr);
	card->cmd[2] = AD2(card->addr);
	card->cmd[3] = AD3(card->addr);
	card->cmd[4] = BA(card->addr);
	card->cmdlen = 5;
	card->mode   = 0;
	card->retry  = 0;

	result = __CARDStart(chan, callback, 0);
	if (result == CARD_RESULT_BUSY) {
		return CARD_RESULT_READY;
	}

#if OS_BUILD_VERSION >= 20011002L
	if (result >= CARD_RESULT_READY) {
		if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1)
		    || !EXIImmEx(chan, card->workArea->header.buffer, card->latency,
		                 1)
		    || // XXX use DMA if possible
		    !EXIDma(chan, card->buffer, 512, card->mode, __CARDTxHandler)) {
			card->txCallback = 0;
			EXIDeselect(chan);
			EXIUnlock(chan);
			result = CARD_RESULT_NOCARD;
		} else {
			result = CARD_RESULT_READY;
		}
	}
	return result;
#else
	if (result < CARD_RESULT_READY) {
		return result;
	}

	if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1)
	    || !EXIImmEx(chan, card->workArea->header.buffer, card->latency,
	                 1)
	    || // XXX use DMA if possible
	    !EXIDma(chan, card->buffer, 512, card->mode, __CARDTxHandler)) {
		card->txCallback = 0;
		EXIDeselect(chan);
		EXIUnlock(chan);
		return CARD_RESULT_NOCARD;
	}
	return CARD_RESULT_READY;
#endif
}

/**
 * @TODO: Documentation
 */
s32 __CARDWritePage(s32 chan, CARDCallback callback)
{
	CARDControl* card;
	s32 result;

	card         = &__CARDBlock[chan];
	card->cmd[0] = 0xF2;
	card->cmd[1] = AD1(card->addr);
	card->cmd[2] = AD2(card->addr);
	card->cmd[3] = AD3(card->addr);
	card->cmd[4] = BA(card->addr);
	card->cmdlen = 5;
	card->mode   = 1;
	card->retry  = 3;

	result = __CARDStart(chan, NULL, callback);
#if OS_BUILD_VERSION >= 20011002L
	if (result == CARD_RESULT_BUSY) {
		result = CARD_RESULT_READY;
	} else if (result >= CARD_RESULT_READY) {
		if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1) || !EXIDma(chan, card->buffer, 128, card->mode, __CARDTxHandler)) {
			card->exiCallback = 0;
			EXIDeselect(chan);
			EXIUnlock(chan);
			result = CARD_RESULT_NOCARD;
		} else
			result = CARD_RESULT_READY;
	}
	return result;
#else
	if (result == CARD_RESULT_BUSY) {
		return CARD_RESULT_READY;
	}
	if (result < CARD_RESULT_READY) {
		return result;
	}
	if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1) || !EXIDma(chan, card->buffer, 128, card->mode, __CARDTxHandler)) {
		card->exiCallback = NULL;
		EXIDeselect(chan);
		EXIUnlock(chan);
		return CARD_RESULT_NOCARD;
	}
	return CARD_RESULT_READY;
#endif
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000E0
 */
void __CARDErase(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 __CARDEraseSector(s32 chan, u32 addr, CARDCallback callback)
{
	CARDControl* card;
	s32 result;

	card         = &__CARDBlock[chan];
	card->cmd[0] = 0xF1;
	card->cmd[1] = AD1(addr);
	card->cmd[2] = AD2(addr);
	card->cmdlen = 3;
	card->mode   = -1;
	card->retry  = 3;

	result = __CARDStart(chan, NULL, callback);

#if OS_BUILD_VERSION >= 20011002L
	if (result == CARD_RESULT_BUSY) {
		result = CARD_RESULT_READY;
	} else if (result >= CARD_RESULT_READY) {
		result = CARD_RESULT_READY;
		if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1)) {
			result            = CARD_RESULT_NOCARD;
			card->exiCallback = NULL;
		} else {
			result = CARD_RESULT_READY;
		}
		EXIDeselect(chan);
		EXIUnlock(chan);
	}
#else

	if (result == CARD_RESULT_BUSY) {
		return CARD_RESULT_READY;
	}

	if (result < CARD_RESULT_READY) {
		return result;
	}

	result = CARD_RESULT_READY;
	if (!EXIImmEx(chan, card->cmd, card->cmdlen, 1)) {
		result            = CARD_RESULT_NOCARD;
		card->exiCallback = NULL;
	}
	EXIDeselect(chan);
	EXIUnlock(chan);
#endif
	return result;
}

/**
 * @TODO: Documentation
 */
void CARDInit(void)
{
	s32 chan;

#if OS_BUILD_VERSION >= 20011112L
	if (__CARDBlock[0].diskID && __CARDBlock[1].diskID)
#else
	if (__CARDDiskID)
#endif
	{
		return;
	}

	DSPInit();
	OSInitAlarm();

	for (chan = 0; chan < 2; chan++) {
		CARDControl* card = &__CARDBlock[chan];

		card->result = CARD_RESULT_NOCARD;
		OSInitThreadQueue(&card->threadQueue);
		OSCreateAlarm(&card->alarm);
	}

	__CARDSetDiskID((DVDDiskID*)OSPhysicalToCached(0x0));

	OSRegisterResetFunction(&ResetFunctionInfo);
}

/**
 * @TODO: Documentation
 */
void __CARDSetDiskID(DVDDiskID* diskID)
{
#if OS_BUILD_VERSION >= 20011112L
	__CARDBlock[0].diskID = diskID ? diskID : &__CARDDiskNone;
	__CARDBlock[1].diskID = diskID ? diskID : &__CARDDiskNone;
#else
	__CARDDiskID = diskID ? diskID : &__CARDDiskNone;
#endif
}

/**
 * @TODO: Documentation
 */
s32 __CARDGetControlBlock(s32 chan, CARDControl** card)
{
	BOOL enabled;
	s32 result;
	CARDControl* reqCard;
#if OS_BUILD_VERSION >= 20011112L
	reqCard = &__CARDBlock[chan];
	if (chan < 0 || chan >= 2 || reqCard->diskID == NULL) {
		return CARD_RESULT_FATAL_ERROR;
	}

	enabled = OSDisableInterrupts();
#else
	if (chan < 0 || chan >= 2 || __CARDDiskID == NULL) {
		return CARD_RESULT_FATAL_ERROR;
	}

	enabled = OSDisableInterrupts();
	reqCard = &__CARDBlock[chan];
#endif
	if (!reqCard->attached) {
		result = CARD_RESULT_NOCARD;
	} else if (reqCard->result == CARD_RESULT_BUSY) {
		result = CARD_RESULT_BUSY;
	} else {
		reqCard->result      = CARD_RESULT_BUSY;
		result               = CARD_RESULT_READY;
		reqCard->apiCallback = NULL;
		*card                = reqCard;
	}
	OSRestoreInterrupts(enabled);
	return result;
}

/**
 * @TODO: Documentation
 */
s32 __CARDPutControlBlock(CARDControl* card, s32 result)
{
	BOOL enabled;

	enabled = OSDisableInterrupts();
#if OS_BUILD_VERSION >= 20011002L
	if (card->attached) {
		card->result = result;
	} else if (card->result == CARD_RESULT_BUSY) {
		card->result = result;
	} else {
		OSAssertLine(0x442, card->result == CARD_RESULT_NOCARD);
	}
#else
	if (card->attached) {
		card->result = result;
	}
#endif
	OSRestoreInterrupts(enabled);
	return result;
}

/**
 * @TODO: Documentation
 */
s32 CARDGetResultCode(s32 chan)
{
	CARDControl* card;

	if (chan < 0 || chan >= 2) {
		return CARD_RESULT_FATAL_ERROR;
	}

	card = &__CARDBlock[chan];
	return card->result;
}

/**
 * @TODO: Documentation
 */
s32 CARDFreeBlocks(s32 chan, s32* byteNotUsed, s32* filesNotUsed)
{
	CARDControl* card;
	s32 result;
	CARDFatBlock* fat;
	CARDDirectoryBlock* dir;
	CARDDir* ent;
	u16 fileNo;

	result = __CARDGetControlBlock(chan, &card);
	if (result < CARD_RESULT_READY) {
		return result;
	}

	fat = __CARDGetFatBlock(card);
	dir = __CARDGetDirBlock(card);
	if (fat == NULL || dir == NULL) {
		return __CARDPutControlBlock(card, CARD_RESULT_BROKEN);
	}

	if (byteNotUsed) {
		*byteNotUsed = (s32)(card->sectorSize * fat->freeBlocks);
	}

	if (filesNotUsed) {
		*filesNotUsed = 0;
		for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
			ent = &dir->entries[fileNo];
			if (ent->fileName[0] == 0xff) {
				++*filesNotUsed;
			}
		}
	}

	return __CARDPutControlBlock(card, CARD_RESULT_READY);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000070
 */
void CARDGetEncoding(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void CARDGetMemSize(void)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 CARDGetSectorSize(s32 chan, u32* size)
{
	CARDControl* card;
	s32 result;

	result = __CARDGetControlBlock(chan, &card);
	if (result < CARD_RESULT_READY) {
		return result;
	}
	*size = card->sectorSize;
	return __CARDPutControlBlock(card, 0);
}

/**
 * @TODO: Documentation
 */
s32 __CARDSync(s32 chan)
{
	CARDControl* card;
	s32 result;
	BOOL enabled;

	card    = &__CARDBlock[chan];
	enabled = OSDisableInterrupts();

	while ((result = CARDGetResultCode(chan)) == CARD_RESULT_BUSY) {
		OSSleepThread(&card->threadQueue);
	}

	OSRestoreInterrupts(enabled);
	return result;
}

/**
 * @TODO: Documentation
 */
static BOOL OnReset(BOOL f)
{
	if (!f) {
		if (CARDUnmount(0) == CARD_RESULT_BUSY || CARDUnmount(1) == CARD_RESULT_BUSY) {
			return FALSE;
		}
	}

	return TRUE;
}
