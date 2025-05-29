#include "Dolphin/card.h"

static void WriteCallback(s32 channel, s32 result);
static void EraseCallback(s32 channel, s32 result);

/*
 * --INFO--
 * Address:	802094AC
 * Size:	000008
 */
CARDFatBlock* __CARDGetFatBlock(CARDControl* card)
{
	return card->currentFat;
}

/*
 * --INFO--
 * Address:	802094B4
 * Size:	0000D4
 */
void WriteCallback(s32 channel, s32 result)
{
	CARDControl* card;
	CARDCallback callback;
	CARDFatBlock* fat;
	CARDFatBlock* fatBack;

	card = &__CARDBlock[channel];

	if (result >= 0) {
		fat     = &card->workArea->blockAllocMap;
		fatBack = &card->workArea->blockAllocMapBackup;

		if (card->currentFat == fat) {
			card->currentFat = fatBack;
			memcpy(fatBack, fat, 0x2000);
		} else {
			card->currentFat = fat;
			memcpy(fat, fatBack, 0x2000);
		}
	}

	if (card->apiCallback == NULL) {
		__CARDPutControlBlock(card, result);
	}

	callback = card->eraseCallback;
	if (callback) {
		card->eraseCallback = NULL;
		callback(channel, result);
	}
}

/*
 * --INFO--
 * Address:	80209588
 * Size:	0000C8
 */
void EraseCallback(s32 channel, s32 result)
{
	CARDControl* card;
	CARDCallback callback;
	u32 temp[2]; /* this compiler sucks */
	CARDFatBlock* fat;
	u32 addr;

	card = &__CARDBlock[channel];
	if (result < 0) {
		goto error;
	}

	fat    = __CARDGetFatBlock(card);
	addr   = ((u32)fat - (u32)card->workArea) / CARD_SYSTEM_BLOCK_SIZE * card->sectorSize;
	result = __CARDWrite(channel, addr, CARD_SYSTEM_BLOCK_SIZE, fat, WriteCallback);
	if (result < 0) {
		goto error;
	}

	return;

error:
	if (card->apiCallback == NULL) {
		__CARDPutControlBlock(card, result);
	}
	callback = card->eraseCallback;
	if (callback) {
		card->eraseCallback = NULL;
		callback(channel, result);
	}
}

/*
 * --INFO--
 * Address:	80209650
 * Size:	000118
 */
s32 __CARDAllocBlock(s32 chan, u32 cBlock, CARDCallback callback)
{
	CARDControl* card;
	CARDFatBlock* fat;
	u16 iBlock;
	u16 startBlock;
	u16 prevBlock;
	u16 count;

	card = &__CARDBlock[chan];
	if (!card->attached) {
		return CARD_RESULT_NOCARD;
	}

	fat = __CARDGetFatBlock(card);
	if (fat->freeBlocks < cBlock) {
		return CARD_RESULT_INSSPACE;
	}

	fat->freeBlocks -= cBlock;
	startBlock = 0xFFFF;
	iBlock     = fat->lastAllocBlock;
	count      = 0;
	while (0 < cBlock) {
		if (card->cBlock - 5 < ++count) {
			return CARD_RESULT_BROKEN;
		}

		iBlock++;
		if (!CARDIsValidBlockNo(card, iBlock)) {
			iBlock = 5;
		}

		if (((u16*)fat)[iBlock] == 0) {
			if (startBlock == 0xFFFF) {
				startBlock = iBlock;
			} else {
				((u16*)fat)[prevBlock] = iBlock;
			}
			prevBlock           = iBlock;
			((u16*)fat)[iBlock] = 0xFFFF;
			--cBlock;
		}
	}
	fat->lastAllocBlock = iBlock;
	card->startBlock    = startBlock;

	return __CARDUpdateFatBlock(chan, fat, callback);
}

/*
 * --INFO--
 * Address:	80209768
 * Size:	00009C
 */
s32 __CARDFreeBlock(s32 channel, u16 nBlock, CARDCallback callback)
{
	CARDControl* card;
	CARDFatBlock* fat;
	u16 nextBlock;
	u16* tmp;

	card = &__CARDBlock[channel];
	if (!card->attached) {
		return CARD_RESULT_NOCARD;
	}

	fat = __CARDGetFatBlock(card);
	tmp = (u16*)fat;
	while (nBlock != 0xFFFF) {
		if (!CARDIsValidBlockNo(card, nBlock)) {
			return CARD_RESULT_BROKEN;
		}

		nextBlock   = tmp[nBlock];
		tmp[nBlock] = 0;
		nBlock      = nextBlock;
		fat->freeBlocks++;
	}

	return __CARDUpdateFatBlock(channel, fat, callback);
}

/*
 * --INFO--
 * Address:	80209804
 * Size:	0000AC
 */
s32 __CARDUpdateFatBlock(s32 channel, CARDFatBlock* fat, CARDCallback callback)
{
	CARDControl* card;

	card = &__CARDBlock[channel];
	++fat->checkCode;
	__CARDCheckSum(&fat->checkCode, 0x1FFC, &fat->checkSum, &fat->checkSumInv);
	DCStoreRange(fat, 0x2000);
	card->eraseCallback = callback;

	return __CARDEraseSector(channel, (((u32)fat - (u32)card->workArea) / CARD_SYSTEM_BLOCK_SIZE) * card->sectorSize, EraseCallback);
}
