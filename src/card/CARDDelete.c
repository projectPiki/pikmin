#include "Dolphin/card.h"

/*
 * --INFO--
 * Address:	8020CA64
 * Size:	0000A4
 */
static void DeleteCallback(s32 channel, s32 result)
{
	CARDControl* card;
	CARDCallback callback;

	card              = &__CARDBlock[channel];
	callback          = card->apiCallback;
	card->apiCallback = NULL;

	if (result < 0) {
		goto error;
	}

	result = __CARDFreeBlock(channel, card->startBlock, callback);
	if (result < 0) {
		goto error;
	}
	return;

error:
	__CARDPutControlBlock(card, result);
	if (callback) {
		callback(channel, result);
	}
}

/*
 * --INFO--
 * Address:	8020CB08
 * Size:	000128
 */
s32 CARDFastDeleteAsync(s32 channel, s32 fileNo, CARDCallback callback)
{
	CARDControl* card;
	CARDDirectoryBlock* dir;
	CARDDir* ent;
	s32 result;

	if (fileNo < 0 || CARD_MAX_FILE <= fileNo) {
		return CARD_RESULT_FATAL_ERROR;
	}

	result = __CARDGetControlBlock(channel, &card);
	if (result < 0) {
		return result;
	}

	dir    = __CARDGetDirBlock(card);
	ent    = &dir->entries[fileNo];
	result = __CARDAccess(ent);
	if (result < 0) {
		return __CARDPutControlBlock(card, result);
	}

	if (__CARDIsOpened(card, fileNo)) {
		return __CARDPutControlBlock(card, CARD_RESULT_BUSY);
	}

	card->startBlock = ent->startBlock;
	memset(ent, 0xff, sizeof(CARDDir));

	card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
	result            = __CARDUpdateDir(channel, DeleteCallback);
	if (result < 0) {
		__CARDPutControlBlock(card, result);
	}
	return result;
}

/*
 * --INFO--
 * Address:	8020CC30
 * Size:	000048
 */
s32 CARDFastDelete(s32 channel, s32 fileNo)
{
	s32 result = CARDFastDeleteAsync(channel, fileNo, __CARDSyncCallback);

	if (result < 0) {
		return result;
	}
	return __CARDSync(channel);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
s32 CARDDeleteAsync(s32 chan, char* fileName, CARDCallback callback)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void CARDDelete(void)
{
	// UNUSED FUNCTION
}
