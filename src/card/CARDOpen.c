#include "Dolphin/card.h"

#include <string.h>

/**
 * @TODO: Documentation
 */
BOOL __CARDCompareFileName(CARDDir* entry, const char* fileName)
{
	char* entName;
	char c1;
	char c2;
	int n;

	entName = (char*)entry->fileName;
	n       = CARD_FILENAME_MAX;
	while (0 <= --n) {
		if ((c1 = *entName++) != (c2 = *fileName++)) {
			return FALSE;
		} else if (c2 == '\0') {
			return TRUE;
		}
	}

	if (*fileName == '\0') {
		return TRUE;
	}

	return FALSE;
}

/**
 * @TODO: Documentation
 */
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
s32 __CARDAccess(CARDControl* card, CARDDir* entry)
#else
s32 __CARDAccess(CARDDir* entry)
#endif
{
	if (entry->gameName[0] == 0xFF) {
		return CARD_RESULT_NOFILE;
	}

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	if (card->diskID == &__CARDDiskNone
	    || (memcmp(entry->gameName, card->diskID->gameName, sizeof(entry->gameName)) == 0
	        && memcmp(entry->company, card->diskID->company, sizeof(entry->company)) == 0)) {
		return CARD_RESULT_READY;
	}
#else
	if (__CARDDiskID == &__CARDDiskNone
	    || (memcmp(entry->gameName, __CARDDiskID->gameName, 4) == 0 && memcmp(entry->company, __CARDDiskID->company, 2) == 0)) {
		return CARD_RESULT_READY;
	}
#endif
	return CARD_RESULT_NOPERM;
}

/**
 * @TODO: Documentation
 */
s32 __CARDIsPublic(CARDDir* ent)
{
	if (ent->gameName[0] == 0xFF) {
		return CARD_RESULT_NOFILE;
	}
	if (ent->permission & CARD_ATTR_PUBLIC) {
		return CARD_RESULT_READY;
	}
	return CARD_RESULT_NOPERM;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000148
 */
s32 __CARDGetFileNo(CARDControl* card, const char* fileName, s32* outFileNo)
{
	CARDDirectoryBlock* dir;
	CARDDir* entry;
	s32 fileNo;
	s32 result;

	if (!card->attached) {
		return CARD_RESULT_NOCARD;
	}

	dir = __CARDGetDirBlock(card);
	for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
		entry = &dir->entries[fileNo];
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		result = __CARDAccess(card, entry);
#else
		result = __CARDAccess(entry);
#endif
		if (result < 0) {
			continue;
		}
		if (__CARDCompareFileName(entry, fileName)) {
			*outFileNo = fileNo;
			return CARD_RESULT_READY;
		}
	}

	return CARD_RESULT_NOFILE;
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
s32 CARDFastOpen(s32 channel, s32 fileNo, CARDFileInfo* fileInfo)
{
	CARDControl* card;
	s32 result;
	CARDDirectoryBlock* dir;
	CARDDir* ent;

	if (fileNo < 0 || fileNo >= CARD_MAX_FILE) {
		return CARD_RESULT_FATAL_ERROR;
	}

	fileInfo->chan = -1;
	result         = __CARDGetControlBlock(channel, &card);
	if (result < 0) {
		return result;
	}

	dir = __CARDGetDirBlock(card);
	ent = &dir->entries[fileNo];
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	result = __CARDAccess(card, ent);
#else
	result = __CARDAccess(ent);
#endif
	if (result == CARD_RESULT_NOPERM) {
		result = __CARDIsPublic(ent);
	}
	if (result >= 0) {
		if (!CARDIsValidBlockNo(card, ent->startBlock)) {
			result = CARD_RESULT_BROKEN;
		} else {
			fileInfo->chan   = channel;
			fileInfo->fileNo = fileNo;
			fileInfo->offset = 0;
			fileInfo->iBlock = ent->startBlock;
		}
	}
	return __CARDPutControlBlock(card, result);
}

/**
 * @TODO: Documentation
 */
s32 CARDOpen(s32 chan, const char* fileName, CARDFileInfo* fileInfo)
{
	CARDControl* card;
	CARDDirectoryBlock* dir;
	CARDDir* ent;
	s32 result;
	s32 fileNo;

	fileInfo->chan = -1;
	result         = __CARDGetControlBlock(chan, &card);
	if (result < 0) {
		return result;
	}
	result = __CARDGetFileNo(card, fileName, &fileNo);
	if (0 <= result) {
		dir = __CARDGetDirBlock(card);
		ent = &dir->entries[fileNo];
		if (!CARDIsValidBlockNo(card, ent->startBlock)) {
			result = CARD_RESULT_BROKEN;
		} else {
			fileInfo->chan   = chan;
			fileInfo->fileNo = fileNo;
			fileInfo->offset = 0;
			fileInfo->iBlock = ent->startBlock;
		}
	}
	return __CARDPutControlBlock(card, result);
}

/**
 * @TODO: Documentation
 */
s32 CARDClose(CARDFileInfo* fileInfo)
{
	CARDControl* card;
	s32 result;

	result = __CARDGetControlBlock(fileInfo->chan, &card);
	if (result < 0) {
		return result;
	}

	fileInfo->chan = -1;
	return __CARDPutControlBlock(card, CARD_RESULT_READY);
}

/**
 * @TODO: Documentation
 */
BOOL __CARDIsOpened(CARDControl* card, s32 fileNo)
{
	return FALSE;
}
