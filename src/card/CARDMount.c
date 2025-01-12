#include "Dolphin/card.h"

static u32 SectorSizeTable[8] = {
	8 * 1024, 16 * 1024, 32 * 1024, 64 * 1024, 128 * 1024, 256 * 1024, 0, 0,
};

static u32 LatencyTable[8] = {
	4, 8, 16, 32, 64, 128, 256, 512,
};

static void DoUnmount(s32 channel, s32 result);

/*
 * --INFO--
 * Address:	8020AAA4
 * Size:	000020
 */
BOOL CARDProbe(s32 channel)
{
	return EXIProbe(channel);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
s32 CARDProbeEx(s32 channel, s32* memSize, s32* sectorSize)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8020AAC4
 * Size:	0003B8
 */
static s32 DoMount(s32 channel)
{
	CARDControl* card;
	u32 id;
	u8 status;
	s32 result;
	OSSramEx* sram;
	int i;
	u8 checkSum;
	int step;

	card = &__CARDBlock[channel];

	if (card->mountStep == 0) {
		result = __CARDReadNintendoID(channel, &id);
		if (result < 0) {
			goto error;
		}

		card->size       = (u16)(id & 0xFC);
		card->sectorSize = SectorSizeTable[(id & 0x00003800) >> 11];
		card->cBlock     = (u16)((card->size * 1024 * 1024 / 8) / card->sectorSize);
		card->latency    = LatencyTable[(id & 0x00000700) >> 8];

		if (card->sectorSize == 0 || card->cBlock < 8) {
			result = CARD_RESULT_WRONGDEVICE;
			goto error;
		}

		result = __CARDClearStatus(channel);
		if (result < 0) {
			goto error;
		}
		result = __CARDReadStatus(channel, &status);
		if (result < 0) {
			goto error;
		}

		if (!EXIProbe(channel)) {
			result = CARD_RESULT_NOCARD;
			goto error;
		}

		if (!(status & 0x40)) {
			result = __CARDUnlock(channel, card->id);
			if (result < 0) {
				goto error;
			}

			checkSum = 0;
			sram     = __OSLockSramEx();
			for (i = 0; i < 12; i++) {
				sram->flashID[channel][i] = card->id[i];
				checkSum += card->id[i];
			}
			sram->flashIDCheckSum[channel] = (u8)~checkSum;
			__OSUnlockSramEx(TRUE);

			return result;
		} else {
			card->mountStep = 1;

			checkSum = 0;
			sram     = __OSLockSramEx();
			for (i = 0; i < 12; i++) {
				checkSum += sram->flashID[channel][i];
			}
			__OSUnlockSramEx(FALSE);
			if (sram->flashIDCheckSum[channel] != (u8)~checkSum) {
				result = CARD_RESULT_IOERROR;
				goto error;
			}
		}
	}

	if (card->mountStep == 1) {
		card->mountStep = 2;

		result = __CARDEnableInterrupt(channel, TRUE);
		if (result < 0) {
			goto error;
		}

		EXISetExiCallback(channel, __CARDExiHandler);
		EXIUnlock(channel);
		DCInvalidateRange(card->workArea, CARD_WORKAREA_SIZE);
	}

	step   = card->mountStep - 2;
	result = __CARDRead(channel, (u32)card->sectorSize * step, CARD_SYSTEM_BLOCK_SIZE,
	                    (u8*)card->workArea + (CARD_SYSTEM_BLOCK_SIZE * step), __CARDMountCallback);
	if (result < 0) {
		__CARDPutControlBlock(card, result);
	}
	return result;

error:
	EXIUnlock(channel);
	DoUnmount(channel, result);
	return result;
}

/*
 * --INFO--
 * Address:	8020AE7C
 * Size:	000108
 */
void __CARDMountCallback(s32 channel, s32 result)
{
	CARDControl* card;
	CARDCallback callback;

	card = &__CARDBlock[channel];

	switch (result) {
	case CARD_RESULT_READY:
		if (++card->mountStep < CARD_MAX_MOUNT_STEP) {
			result = DoMount(channel);
			if (0 <= result) {
				return;
			}
		} else {
			result = __CARDVerify(card);
		}
		break;
	case CARD_RESULT_UNLOCKED:
		result = DoMount(channel);
		if (0 <= result) {
			return;
		}
		break;
	case CARD_RESULT_IOERROR:
	case CARD_RESULT_NOCARD:
		DoUnmount(channel, result);
		break;
	}

	callback          = card->apiCallback;
	card->apiCallback = nullptr;
	__CARDPutControlBlock(card, result);
	callback(channel, result);
}

/*
 * --INFO--
 * Address:	8020AF84
 * Size:	000188
 */
s32 CARDMountAsync(s32 channel, CARDMemoryCard* workArea, CARDCallback detachCallback, CARDCallback attachCallback)
{
	CARDControl* card;
	BOOL enabled;

	if (channel < 0 || 2 <= channel) {
		return CARD_RESULT_FATAL_ERROR;
	}
	card = &__CARDBlock[channel];

	enabled = OSDisableInterrupts();
	if (card->result == CARD_RESULT_BUSY) {
		OSRestoreInterrupts(enabled);
		return CARD_RESULT_BUSY;
	}

	if (!card->attached && (EXIGetState(channel) & 0x08)) {
		OSRestoreInterrupts(enabled);
		return CARD_RESULT_WRONGDEVICE;
	}

	card->result      = CARD_RESULT_BUSY;
	card->workArea    = workArea;
	card->extCallback = detachCallback;
	card->apiCallback = attachCallback ? attachCallback : __CARDDefaultApiCallback;
	card->exiCallback = nullptr;

	if (!card->attached && !EXIAttach(channel, __CARDExtHandler)) {
		card->result = CARD_RESULT_NOCARD;
		OSRestoreInterrupts(enabled);
		return CARD_RESULT_NOCARD;
	}

	card->mountStep = 0;
	card->attached  = TRUE;
	EXISetExiCallback(channel, 0);
	OSCancelAlarm(&card->alarm);

	card->currentDir = 0;
	card->currentFat = 0;

	OSRestoreInterrupts(enabled);

	card->unlockCallback = __CARDMountCallback;
	if (!EXILock(channel, 0, __CARDUnlockedHandler)) {
		return CARD_RESULT_READY;
	}
	card->unlockCallback = nullptr;

	return DoMount(channel);
}

/*
 * --INFO--
 * Address:	8020B10C
 * Size:	000048
 */
s32 CARDMount(s32 channel, CARDMemoryCard* workArea, CARDCallback detachCallback)
{
	s32 result = CARDMountAsync(channel, workArea, detachCallback, __CARDSyncCallback);
	if (result < 0) {
		return result;
	}

	return __CARDSync(channel);
}

/*
 * --INFO--
 * Address:	8020B154
 * Size:	00009C
 */
static void DoUnmount(s32 channel, s32 result)
{
	CARDControl* card;
	BOOL enabled;

	card    = &__CARDBlock[channel];
	enabled = OSDisableInterrupts();
	if (card->attached) {
		EXISetExiCallback(channel, 0);
		EXIDetach(channel);
		OSCancelAlarm(&card->alarm);
		card->attached  = FALSE;
		card->result    = result;
		card->mountStep = 0;
	}
	OSRestoreInterrupts(enabled);
}

/*
 * --INFO--
 * Address:	8020B1F0
 * Size:	0000AC
 */
s32 CARDUnmount(s32 channel)
{
	CARDControl* card;
	s32 result;

	result = __CARDGetControlBlock(channel, &card);
	if (result < 0) {
		return result;
	}
	DoUnmount(channel, CARD_RESULT_NOCARD);
	return CARD_RESULT_READY;
}
