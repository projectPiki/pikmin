#include "Dolphin/card.h"

static void WriteCallback(s32 channel, s32 result);
static void EraseCallback(s32 channel, s32 result);

/*
 * --INFO--
 * Address:	802094AC
 * Size:	000008
 */
CARDFatBlock* __CARDGetFatBlock(CARDControl* card) { return card->currentFat; }

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

	if (card->apiCallback == nullptr) {
		__CARDPutControlBlock(card, result);
	}

	callback = card->eraseCallback;
	if (callback) {
		card->eraseCallback = nullptr;
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
	if (card->apiCallback == nullptr) {
		__CARDPutControlBlock(card, result);
	}
	callback = card->eraseCallback;
	if (callback) {
		card->eraseCallback = nullptr;
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
	// regswap - I've tried changing CARDFatBlock* to u16* (either with a cast, or by changing the whole repo)
	// still a r8/r9 regswap.
	CARDControl* card;
	CARDFatBlock* fat;
	u16 nextBlock;

	card = &__CARDBlock[channel];
	if (!card->attached) {
		return CARD_RESULT_NOCARD;
	}

	fat = __CARDGetFatBlock(card);
	while (nBlock != 0xFFFF) {
		if (!CARDIsValidBlockNo(card, nBlock)) {
			return CARD_RESULT_BROKEN;
		}

		nextBlock           = ((u16*)fat)[nBlock];
		((u16*)fat)[nBlock] = 0;
		nBlock              = nextBlock;
		fat->freeBlocks++;
	}

	return __CARDUpdateFatBlock(channel, fat, callback);
	/*
	.loc_0x0:
	  mflr      r0
	  mulli     r7, r3, 0x108
	  stw       r0, 0x4(r1)
	  lis       r6, 0x803D
	  stwu      r1, -0x8(r1)
	  addi      r0, r6, 0x3420
	  add       r9, r0, r7
	  lwz       r0, 0x0(r9)
	  cmpwi     r0, 0
	  bne-      .loc_0x30
	  li        r3, -0x3
	  b         .loc_0x8C

	.loc_0x30:
	  lwz       r8, 0x88(r9)
	  li        r7, 0
	  b         .loc_0x78

	.loc_0x3C:
	  rlwinm    r4,r4,0,16,31
	  cmplwi    r4, 0x5
	  blt-      .loc_0x54
	  lhz       r0, 0x10(r9)
	  cmplw     r4, r0
	  blt-      .loc_0x5C

	.loc_0x54:
	  li        r3, -0x6
	  b         .loc_0x8C

	.loc_0x5C:
	  rlwinm    r0,r4,1,0,30
	  add       r6, r8, r0
	  lhz       r4, 0x0(r6)
	  sth       r7, 0x0(r6)
	  lhz       r6, 0x6(r8)
	  addi      r0, r6, 0x1
	  sth       r0, 0x6(r8)

	.loc_0x78:
	  rlwinm    r0,r4,0,16,31
	  cmplwi    r0, 0xFFFF
	  bne+      .loc_0x3C
	  mr        r4, r8
	  bl        .loc_0x9C

	.loc_0x8C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x9C:
	*/
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
