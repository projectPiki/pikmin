#include "Dolphin/card.h"
#include <string.h>

/**
 * @TODO: Documentation
 */
s32 CARDRenameAsync(s32 channel, const char* oldName, const char* newName, CARDCallback callback)
{
	CARDControl* card;
	CARDDirectoryBlock* dir;
	CARDDir* ent;
	s32 result;
	int fileNo;
	int newNo;
	int oldNo;

	if (oldName[0] == 0xFF || newName[0] == 0xFF || oldName[0] == 0 || newName[0] == 0) {
		return CARD_RESULT_FATAL_ERROR;
	}
	if (CARD_FILENAME_MAX < (u32)strlen(oldName) || CARD_FILENAME_MAX < (u32)strlen(newName)) {
		return CARD_RESULT_NAMETOOLONG;
	}
	result = __CARDGetControlBlock(channel, &card);
	if (result < 0) {
		return result;
	}
	newNo = oldNo = -1;
	dir           = __CARDGetDirBlock(card);
	for (fileNo = 0; fileNo < CARD_MAX_FILE; fileNo++) {
		ent = &dir->entries[fileNo];
		if (ent->gameName[0] == 0xFF) {
			continue;
		}

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_G98P01_PIKIDEMO) || defined(VERSION_GPIP01_00)
		if (memcmp(ent->gameName, card->diskID->gameName, sizeof(ent->gameName)) != 0
		    || memcmp(ent->company, card->diskID->company, sizeof(ent->company)) != 0) {
#else
		if (memcmp(ent->gameName, __CARDDiskID->gameName, sizeof(ent->gameName)) != 0
		    || memcmp(ent->company, __CARDDiskID->company, sizeof(ent->company)) != 0) {
#endif
			continue;
		}

		if (__CARDCompareFileName(ent, oldName)) {
			oldNo = fileNo;
		}
		if (__CARDCompareFileName(ent, newName)) {
			newNo = fileNo;
		}
	}

	if (oldNo == -1) {
		return __CARDPutControlBlock(card, CARD_RESULT_NOFILE);
	}
	if (newNo != -1) {
		return __CARDPutControlBlock(card, CARD_RESULT_EXIST);
	}

	ent = &dir->entries[oldNo];
#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_G98P01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	result = __CARDAccess(card, ent);
#else
	result = __CARDAccess(ent);
#endif
	if (result < 0) {
		return __CARDPutControlBlock(card, result);
	}

	strncpy((char*)ent->fileName, newName, CARD_FILENAME_MAX);
	ent->time = (u32)OSTicksToSeconds(OSGetTime());

	result = __CARDUpdateDir(channel, callback);
	if (result < 0) {
		__CARDPutControlBlock(card, result);
	}

	return result;
}

/**
 * @TODO: Documentation
 */
s32 CARDRename(s32 channel, const char* oldName, const char* newName)
{
	s32 result = CARDRenameAsync(channel, oldName, newName, __CARDSyncCallback);

	if (result < 0) {
		return result;
	}
	return __CARDSync(channel);
}
