#include "Dolphin/card.h"
#include <stddef.h>

static void EraseCallback(s32 chan, s32 result);

/**
 * @TODO: Documentation
 */
static void WriteCallback(s32 channel, s32 result)
{
	CARDControl* card;
	CARDCallback callback;
	CARDFatBlock* fat;
	CARDDirectoryBlock* dir;
	CARDDir* ent;
	CARDFileInfo* fileInfo;

	card = &__CARDBlock[channel];
	if (result < 0) {
		goto error;
	}

	fileInfo = card->fileInfo;
	if (fileInfo->length < 0) {
		result = CARD_RESULT_CANCELED;
		goto error;
	}

	fileInfo->length -= card->sectorSize;
	if (fileInfo->length <= 0) {
		dir               = __CARDGetDirBlock(card);
		ent               = &dir->entries[fileInfo->fileNo];
		ent->time         = (u32)OSTicksToSeconds(OSGetTime());
		callback          = card->apiCallback;
		card->apiCallback = NULL;
		result            = __CARDUpdateDir(channel, callback);

	} else {
		fat = __CARDGetFatBlock(card);
		fileInfo->offset += card->sectorSize;
		fileInfo->iBlock = ((u16*)fat)[fileInfo->iBlock];
		if (!CARDIsValidBlockNo(card, fileInfo->iBlock)) {
			result = CARD_RESULT_BROKEN;
			goto error;
		}
		result = __CARDEraseSector(channel, card->sectorSize * (u32)fileInfo->iBlock, EraseCallback);
	}

	if (result < 0) {
		goto error;
	}
	return;

error:
	callback          = card->apiCallback;
	card->apiCallback = NULL;
	__CARDPutControlBlock(card, result);
	callback(channel, result);
}

/**
 * @TODO: Documentation
 */
void EraseCallback(s32 channel, s32 result)
{
	CARDControl* card;
	CARDCallback callback;
	CARDFileInfo* fileInfo;

	card = &__CARDBlock[channel];
	if (result < 0) {
		goto error;
	}

	fileInfo = card->fileInfo;
	result   = __CARDWrite(channel, card->sectorSize * (u32)fileInfo->iBlock, card->sectorSize, card->buffer, WriteCallback);
	if (result < 0) {
		goto error;
	}
	return;

error:
	callback          = card->apiCallback;
	card->apiCallback = NULL;
	__CARDPutControlBlock(card, result);
	callback(channel, result);
}

/**
 * @TODO: Documentation
 */
s32 CARDWriteAsync(CARDFileInfo* fileInfo, void* buffer, s32 length, s32 offset, CARDCallback callback)
{
	CARDControl* card;
	s32 result;
	CARDDirectoryBlock* dir;
	CARDDir* ent;

	result = __CARDSeek(fileInfo, length, offset, &card);
	if (result < 0) {
		return result;
	}

	if (OFFSET(offset, card->sectorSize) != 0 || OFFSET(length, card->sectorSize) != 0) {
		return __CARDPutControlBlock(card, CARD_RESULT_FATAL_ERROR);
	}

	dir = __CARDGetDirBlock(card);
	ent = &dir->entries[fileInfo->fileNo];
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	result = __CARDAccess(card, ent);
#else
	result = __CARDAccess(ent);
#endif
	if (result < 0) {
		return __CARDPutControlBlock(card, result);
	}

	DCStoreRange(buffer, (u32)length);
	card->apiCallback = callback ? callback : __CARDDefaultApiCallback;
	card->buffer      = buffer;
	result            = __CARDEraseSector(fileInfo->chan, card->sectorSize * (u32)fileInfo->iBlock, EraseCallback);
	if (result < 0) {
		__CARDPutControlBlock(card, result);
	}
	return result;
}

/**
 * @TODO: Documentation
 */
s32 CARDWrite(CARDFileInfo* fileInfo, void* buffer, s32 length, s32 offset)
{
	s32 result = CARDWriteAsync(fileInfo, buffer, length, offset, __CARDSyncCallback);
	if (result < 0) {
		return result;
	}

	return __CARDSync(fileInfo->chan);
}
