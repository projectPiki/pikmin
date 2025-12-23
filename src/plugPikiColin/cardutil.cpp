#include "CardUtil.h"

#include "DebugLog.h"
#include "gameflow.h"

/// Global thread for async card operations called directly by the game code.
CardUtilThread CardThread;

/// Global object for handling card command queueing and execution.
CardUtilControl CardControl;

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("CardUtil")

/**
 * @brief Gets number of directory entries in card list.
 * @note UNUSED Size: 000010
 */
int CardUtilNumFiles()
{
	return CardControl.mDirentCount;
}

/**
 * @brief Locks directory mutex.
 *
 * Ensures thread-safe access to card directory data. Pair with CardUtilUnlockDirectory.
 *
 * @note UNUSED Size: 000038
 */
void CardUtilLockDirectory()
{
	OSLockMutex(&CardControl.mDirMutex);
}

/**
 * @brief Unlocks directory mutex.
 *
 * Ensures thread-safe access to card directory data. Pair with CardUtilLockDirectory.
 *
 * @note UNUSED Size: 00002C
 */
void CardUtilUnlockDirectory()
{
	OSUnlockMutex(&CardControl.mDirMutex);
}

/**
 * @brief Gets pointer to number of unused memory card bytes.
 * @note UNUSED Size: 000010
 */
s32* CardUtilByteNotUsed()
{
	return &CardControl.mByteNotUsed;
}

/**
 * @brief Stripped function, not yet decompiled or reconstructed.
 * @note UNUSED Size: 000028
 */
s32 CardUtilBlocksNotUsed()
{
	// UNUSED FUNCTION
}

/**
 * @brief Gets pointer to number of unused file slots.
 * @note UNUSED Size: 000010
 */
s32* CardUtilFilesNotUsed()
{
	return &CardControl.mFilesNotUsed;
}

/**
 * @brief Gets pointer to memory card sector size.
 * @note UNUSED Size: 000010
 */
u32* CardUtilSectorSize()
{
	return &CardControl.mSectorSize;
}

/**
 * @brief Mounts the memory card in given channel and resets control information.
 *
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param workArea Address of memory card working memory.
 * @return CARD result code from last operation hit - 0 or 1 if no error, negative if error.
 */
static s32 DoMount(s32 chan, void* workArea)
{
	// reset directory count (thread-safe)
	CardUtilLockDirectory();
	CardControl.mDirentCount = 0;
	CardUtilUnlockDirectory();

	// reset control values and mount card
	CardControl.mFilesNotUsed  = 0;
	CardControl.mByteNotUsed   = 0;
	CardControl.mOperationSize = CARD_WORKAREA_SIZE;
	s32 res                    = CARDMount(chan, (CARDMemoryCard*)workArea, nullptr);
	switch (res) {
	case CARD_RESULT_READY:
	case CARD_RESULT_BROKEN: {
		// fetch sector size for utility purposes (+ check card is accessible as a side effect)
		s32 sectorRes = CARDGetSectorSize(chan, CardUtilSectorSize());
		if (sectorRes < 0) {
			// throw error
			return sectorRes;
		}

		// double check card is valid and working
		res = CARDCheck(chan);
	} break;

	case CARD_RESULT_ENCODING: {
		// fetch sector size for utility purposes (+ check card is accessible as a side effect)
		s32 sectorRes = CARDGetSectorSize(chan, CardUtilSectorSize());
		if (sectorRes < 0) {
			// throw error
			return sectorRes;
		}
	} break;
	}

	// if everything is fine, calc what's free on memory card and update our values
	if (res == CARD_RESULT_READY) {
		res = CARDFreeBlocks(chan, CardUtilByteNotUsed(), CardUtilFilesNotUsed());
	}
	return res;
}

/**
 * @brief Unmounts memory card in given channel.
 *
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @return CARD result code from last operation hit - 0 or 1 if no error, negative if error.
 * @note UNUSED Size: 000064
 */
static s32 DoUnmount(s32 chan)
{
	// reset directory count (thread-safe)
	CardUtilLockDirectory();
	CardControl.mDirentCount = 0;
	CardUtilUnlockDirectory();

	return CARDUnmount(chan);
}

/**
 * @brief Formats memory card in given channel.
 *
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @return CARD result code from last operation hit - 0 or 1 if no error, negative if error.
 * @note UNUSED Size: 000088
 */
static s32 DoFormat(s32 chan)
{
	// reset directory count (thread-safe)
	CardUtilLockDirectory();
	CardControl.mDirentCount = 0;
	CardUtilUnlockDirectory();

	CardControl.mOperationSize = CARD_WORKAREA_SIZE;
	s32 res                    = CARDFormat(chan);
	if (res == CARD_RESULT_READY) {
		res = CARDFreeBlocks(chan, CardUtilByteNotUsed(), CardUtilFilesNotUsed());
	}
	return res;
}

/**
 * @brief Erases a file by index.
 *
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param fileNo Index of directory entry to erase.
 * @return CARD result code from deleting or freeing blocks - 0 or 1 = successful, negative = error.
 */
static s32 DoErase(s32 chan, s32 fileNo)
{
	CardControl.mOperationSize = 0x4000;
	int resDel                 = CARDFastDelete(chan, fileNo);
	if (resDel < 0) {
		// throw error
		return resDel;
	}

	// if we have a list going, need to also remove the entry from that.
	if (CardControl.mDirentList) {
		CardUtilDirent* entry = &CardControl.mDirentList[0];
		for (entry; entry < &(CardControl.mDirentList)[CardControl.mDirentCount]; entry++) {

			int entryNo = entry->mFileNo;
			// make sure we're erasing the right entry
			if (entryNo != fileNo) {
				continue;
			}

			// move any entries after the target back over it to keep memory contiguous (thread-safe)
			CardUtilLockDirectory();
			memmove(entry, entry + 1, (u8*)&(CardControl.mDirentList)[CardControl.mDirentCount] - (u8*)(entry + 1));
			CardControl.mDirentCount--;
			DCStoreRange(entry, (u8*)&(CardControl.mDirentList)[CardControl.mDirentCount] - (u8*)entry);
			CardUtilUnlockDirectory();
		}
	}

	return CARDFreeBlocks(chan, CardUtilByteNotUsed(), CardUtilFilesNotUsed());
}

/**
 * @brief Reads card data in for any Pikmin save files and populates the directory entry list.
 *
 * Specifically reads in comment, icon and banner information. Also handles any temporary files.
 *
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param dirent Array of directory entries, to be filled with save file information from the card.
 * @return CARD result code from last operation hit - 0 or 1 if no error, negative if error.
 */
static s32 DoList(s32 chan, CardUtilDirent* dirent)
{
	DVDDiskID* diskID = DVDGetCurrentDiskID();
	int res           = CARD_RESULT_READY;

	// update card control structure with directory entry list (thread-safe)
	CardUtilLockDirectory();
	CardControl.mDirentList  = dirent;
	CardControl.mDirentCount = 0;
	CardUtilUnlockDirectory();

	if (!dirent) {
		// no buffer to fill, return early
		return CARD_RESULT_READY;
	}

	// clear entire buffer (up to 127 entries) before filling it with data
	memset(dirent, 0, CARD_MAX_FILE * sizeof(CardUtilDirent));

	CARDFileInfo info;
	char newFileName[CARD_FILENAME_MAX + 1];
	char tempFileName[CARD_FILENAME_MAX + 1];

	// scan up to 127 file slots
	for (int i = 0; i < CARD_MAX_FILE; i++) {
		CardUtilDirent& entry = dirent[CardControl.mDirentCount];
		// grab card state for this slot and check it's valid
		if (CARDGetStatus(chan, i, &entry.mState) < 0) {
			continue;
		}

		// confirm data is for the right game (via game name and company) otherwise skip
		if (memcmp(entry.mState.gameName, diskID->gameName, 4) != 0) {
			continue;
		}
		if (memcmp(entry.mState.company, diskID->company, 2) != 0) {
			continue;
		}

		// ~ indicates a temp file, handle that separately
		if (entry.mState.fileName[0] == '~') {

			// try and rename it to remove the ~
			strncpy(tempFileName, entry.mState.fileName, CARD_FILENAME_MAX);
			tempFileName[CARD_FILENAME_MAX] = 0; // 0-terminated string

			strncpy(newFileName, &tempFileName[1], CARD_FILENAME_MAX);
			newFileName[CARD_FILENAME_MAX] = 0; // 0-terminated string

			// if we have a comment, assume it's a valid temp file and try and rename it
			if (entry.mState.commentAddr <= entry.mState.length - CARD_COMMENT_SIZE) {
				if (CARDRename(chan, tempFileName, newFileName) == 0) {
					// renamed! redo this entry with the new name
					i--;
					continue;
				}
			}

			// no comment present OR rename failed, delete the temp file
			res = CARDFastDelete(chan, i);
			if (res >= 0) {
				res = CARDFreeBlocks(chan, CardUtilByteNotUsed(), CardUtilFilesNotUsed());
				if (res >= 0) {
					continue;
				}
			}
			// either the delete or freeing of blocks failed, throw an error
			return res;
		}

		// clear comment buffer before we try and read in data
		memset(entry.mFileCommentData, 0, CARD_COMMENT_SIZE);

		// if we have comment data, read it in
		if (entry.mState.commentAddr <= entry.mState.length - CARD_COMMENT_SIZE) {
			res = CARDFastOpen(chan, i, &info);
			if (res < 0) {
				// throw error
				return res;
			}

			s32 commentStart = TRUNC(entry.mState.commentAddr, CARD_READ_SIZE);
			s32 commentEnd   = entry.mState.commentAddr + CARD_COMMENT_SIZE;
			res              = CARDRead(&info, &entry, ALIGN_NEXT(commentEnd - commentStart, CARD_READ_SIZE), commentStart);
			CARDClose(&info);
			if (res < 0) {
				// throw error
				return res;
			}

			void* dst = entry.mFileCommentData;
			void* src = &entry.mFileData[OFFSET(entry.mState.commentAddr, CARD_READ_SIZE)];
			memmove(dst, src, CARD_COMMENT_SIZE);
		}

		if (entry.mState.bannerFormat || entry.mState.iconFormat) {
			if (entry.mState.offsetData <= entry.mState.length && entry.mState.iconAddr < entry.mState.offsetData) {
				int resOpen = CARDFastOpen(chan, i, &info);
				if (resOpen < 0) {
					// throw error
					return resOpen;
				}

				s32 offset = TRUNC(entry.mState.iconAddr, CARD_READ_SIZE);
				res        = CARDRead(&info, &entry, ALIGN_NEXT(entry.mState.offsetData - offset, CARD_READ_SIZE), offset);
				CARDClose(&info);
				if (res < 0) {
					// throw error
					return res;
				}

				memmove(&entry, &entry.mFileData[OFFSET(entry.mState.iconAddr, CARD_READ_SIZE)],
				        entry.mState.offsetData - entry.mState.iconAddr);

				DCFlushRange(&entry, entry.mState.offsetData - entry.mState.iconAddr);

				entry.mAnimTotalFrames = 0;
				int iconCnt;
				int j;
				int count;
				for (j = 0, count = 0, iconCnt = 0; count < 8; count++, j++) {
					int speed = CARDGetIconSpeed(&entry.mState, count);
					if (speed == CARD_STAT_SPEED_END) {
						break;
					}

					entry.mAnimFrameOffsets[j] = entry.mAnimTotalFrames;
					entry.mAnimIconIndices[j]  = iconCnt;
					entry.mAnimTotalFrames += speed << 2;

					if (CARDGetIconFormat(&entry.mState, iconCnt) != CARD_STAT_ICON_NONE) {
						iconCnt++;
					}
				}

				if (CARDGetIconAnim(&entry.mState) == CARD_STAT_ANIM_BOUNCE && count > 2) {
					for (int k = count - 2; k > 0; k--) {
						int speed                  = CARDGetIconSpeed(&entry.mState, k);
						entry.mAnimFrameOffsets[j] = entry.mAnimTotalFrames;
						entry.mAnimIconIndices[j]  = entry.mAnimIconIndices[k];
						entry.mAnimTotalFrames += speed << 2;
						j++;
					}
				}
			}
		}

		entry.mFileNo = i;

		// increment card control's count (thread-safe)
		CardUtilLockDirectory();
		CardControl.mDirentCount++;
		CardUtilUnlockDirectory();
	}

	return res;
}

/**
 * @brief Opens memory card in given channel and reads in the data in given slot.
 *
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param fileNo Index of directory entry to read in.
 * @param workBuffer Pointer to working area to read data into.
 * @return CARD result code from last operation hit - 0 or 1 if no error, negative if error.
 * @note UNUSED Size: 0000A0
 */
static s32 DoOpen(s32 chan, s32 fileNo, void* workBuffer)
{
	CARDStat state;
	CARDFileInfo info;
	s32 res = CARDGetStatus(chan, fileNo, &state);
	if (res < 0) {
		// throw error
		return res;
	}
	res = CARDFastOpen(chan, fileNo, &info);
	if (res < 0) {
		// throw error
		return res;
	}
	CardControl.mOperationSize = state.length;
	res                        = CARDRead(&info, workBuffer, state.length, 0);
	CARDClose(&info);
	return res;
}

/**
 * @brief Writes data to the given memory card slot.
 *
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param fileNo Index of directory entry to write to.
 * @param data Pointer to data buffer to write from.
 * @param length Length of data to write.
 * @param offset Offset of data to write (within data buffer).
 * @return CARD result code from last operation hit - 0 or 1 if no error, negative if error.
 * @note UNUSED Size: 00008C
 */
static s32 DoWrite(s32 chan, s32 fileNo, void* data, u32 length, u32 offset)
{
	CARDStat state;
	CARDFileInfo info;
	s32 res = CARDGetStatus(chan, fileNo, &state);
	if (res < 0) {
		// throw error
		return res;
	}
	res = CARDFastOpen(chan, fileNo, &info);
	if (res < 0) {
		// throw error
		return res;
	}
	res = CARDWrite(&info, data, length, offset);
	CARDClose(&info);
	return res;
}

/**
 * @brief Saves an entire file to memory card.
 *
 * File is provided in pieces - the state (summary info) and data pointer.
 *
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param fileState CARDStat pointer for file to save.
 * @param fileData Data pointer for file to save.
 * @return CARD result code from last operation hit - 0 or 1 if no error, negative if error.
 */
static s32 DoSave(s32 chan, CARDStat* fileState, void* fileData)
{
	CARDFileInfo info;
	// get 0-terminated file name string
	char fileName[CARD_FILENAME_MAX + 1];
	strncpy(fileName, fileState->fileName, CARD_FILENAME_MAX);
	fileName[CARD_FILENAME_MAX] = 0;

	// make sure file name is within length bounds
	if (strlen(fileName) >= CARD_FILENAME_MAX) {
		return CARD_RESULT_NAMETOOLONG;
	}

	// don't try and save a temporary file - only proper files allowed
	if (fileName[0] == '~') {
		// dramatic
		return CARD_RESULT_FATAL_ERROR;
	}

	char tempFileName[CARD_FILENAME_MAX + 1];

	// temp file names start with "~"
	tempFileName[0] = '~';
	strncpy(&tempFileName[1], fileState->fileName, CARD_FILENAME_MAX - 1);
	tempFileName[CARD_FILENAME_MAX] = 0;

	int newFileNo;
	int oldFileNo = -1;

	// check if file exists
	if (CARDOpen(chan, fileName, &info) == CARD_RESULT_READY) {
		oldFileNo = info.fileNo;
		CARDClose(&info);
	}

	CardControl.mOperationSize = fileState->length + 0x8000;
	if (oldFileNo >= 0 && oldFileNo < CARD_MAX_FILE) {
		CardControl.mOperationSize += 0x4000;
	}

	// try and create temp file
	int resCreate = CARDCreate(chan, tempFileName, fileState->length, &info);
	if (resCreate < 0) {
		// throw error
		return resCreate;
	}

	newFileNo = info.fileNo;

	// write data to temp file
	int resWrite = CARDWrite(&info, fileData, fileState->length, 0);
	CARDClose(&info);
	if (resWrite < 0 || (resWrite = CARDSetStatus(chan, newFileNo, fileState)) < 0) {
		// throw error
		return resWrite;
	}

	// if old file exists, delete it
	if (oldFileNo >= 0 && oldFileNo < CARD_MAX_FILE) {
		int resDel = CARDFastDelete(chan, oldFileNo);
		if (resDel < 0) {
			// throw error
			return resDel;
		}
	}

	// rename temp file to final name
	int resRename = CARDRename(chan, tempFileName, fileName);
	if (resRename < 0) {
		// throw error
		return resRename;
	}

	// if no directory list, update our free space counters and return
	if (!CardControl.mDirentList) {
		return CARDFreeBlocks(chan, CardUtilByteNotUsed(), CardUtilFilesNotUsed());
	}

	// update or add directory entry (thread-safe)
	CardUtilLockDirectory();
	CardUtilDirent* entry;
	if (oldFileNo == -1) {
		// new file, add at end
		entry = &CardControl.mDirentList[CardControl.mDirentCount];
		CardControl.mDirentCount++;
	} else {
		// existing file, find and update
		entry               = CardControl.mDirentList;
		CardUtilDirent* end = &CardControl.mDirentList[CardControl.mDirentCount];
		for (entry; entry < end; entry++) {
			if (entry->mFileNo == oldFileNo) {
				break;
			}
		}
		if (entry == end) {
			// failed to find file, add at end
			CardControl.mDirentCount++;
		}
	}

	// clear comment data
	memset(entry->mFileCommentData, 0, CARD_COMMENT_SIZE);

	// copy comment data from save buffer, if present
	if (fileState->commentAddr <= fileState->length - CARD_COMMENT_SIZE) {
		memmove(entry->mFileCommentData, (void*)((u32)fileData + fileState->commentAddr), CARD_COMMENT_SIZE);
	}

	// handle icon/banner data, if present
	entry->mAnimTotalFrames = 0;
	if (fileState->bannerFormat || fileState->iconFormat) {
		memmove(entry, (void*)((u32)fileData + fileState->iconAddr), fileState->offsetData - fileState->iconAddr);
		DCFlushRange(entry, fileState->offsetData - fileState->iconAddr);

		int iconCnt;
		int i;
		int count;
		for (i = 0, count = 0, iconCnt = 0; count < 8; count++, i++) {
			int speed = CARDGetIconSpeed(fileState, count);
			if (speed == CARD_STAT_SPEED_END) {
				break;
			}

			entry->mAnimFrameOffsets[i] = entry->mAnimTotalFrames;
			entry->mAnimIconIndices[i]  = iconCnt;
			entry->mAnimTotalFrames += speed << 2;

			if (CARDGetIconFormat(fileState, iconCnt) != CARD_STAT_ICON_NONE) {
				iconCnt++;
			}
		}

		// handle bounce return frames
		if (CARDGetIconAnim(fileState) == CARD_STAT_ANIM_BOUNCE && count > 2) {
			for (int j = count - 2; j > 0; j--) {
				int speed                   = CARDGetIconSpeed(fileState, j);
				entry->mAnimFrameOffsets[i] = entry->mAnimTotalFrames;
				entry->mAnimIconIndices[i]  = entry->mAnimIconIndices[j];
				entry->mAnimTotalFrames += speed << 2;
				i++;
			}
		}
	}

	// copy CARDStat to entry and update file number
	memcpy(&entry->mState, fileState, sizeof(CARDStat));
	entry->mFileNo = newFileNo;
	CardUtilUnlockDirectory();

	// update free space counters
	return CARDFreeBlocks(chan, CardUtilByteNotUsed(), CardUtilFilesNotUsed());
}

/**
 * @brief Issues a command to the card utility thread for async execution.
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param command Command code (see `CardUtilCommands` enum).
 * @param file File number or, for saving, a casted file state pointer.
 * @param workBuffer Pointer to data buffer or directory entry list.
 * @param offset Offset for write operations.
 * @param length Length for write operations.
 * @return CARD result code from last operation hit - 0 or 1 if no error, negative if error.
 */
static s32 CardUtilCommand(s32 chan, s32 command, s32 file, void* workBuffer, u32 offset, u32 length)
{
	OSLockMutex(&CardControl.mMutex);
	int res;
	if (CardControl.mChannel != -1) {
		// card thread is busy
		res = CardControl.mResultCode;
	} else {
		// notify global control of command parameters
		CardControl.mChannel    = chan;
		CardControl.mCommand    = command;
		CardControl.mFileNo     = (void*)file;
		CardControl.mDataPtr    = workBuffer;
		CardControl.mOffset     = offset;
		CardControl.mLength     = length;
		CardControl.mResultCode = CARD_RESULT_BUSY;

		if (command != CARDCMD_List) {
			CardControl.mTransferredBytes = CARDGetXferredBytes(chan);
		}
		res = CARD_RESULT_READY;
		// wake up card thread
		OSSignalCond(&CardControl.mCondition);
	}
	OSUnlockMutex(&CardControl.mMutex);
	return res;
}

/**
 * @brief Gets the result code for the last completed operation.
 */
s32 CardUtilResultCode()
{
	return CardControl.mResultCode;
}

/**
 * @brief Signals to mount card (async).
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param workBuffer Working area to mount card to.
 */
void CardUtilMount(s32 chan, void* workBuffer)
{
	CardUtilCommand(chan, CARDCMD_Mount, 0, workBuffer, 0, 0);
}

/**
 * @brief Signals to unmount card (async).
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 */
void CardUtilUnmount(s32 chan)
{
	CardUtilCommand(chan, CARDCMD_Unmount, 0, nullptr, 0, 0);
}

/**
 * @brief Signals to retrieve save file list (async).
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param dirList Array to write list of save files to.
 * @note UNUSED Size: 000034
 */
void CardUtilList(s32 chan, CardUtilDirent* dirList)
{
	CardUtilCommand(chan, CARDCMD_List, 0, dirList, 0, 0);
}

/**
 * @brief Signals to format card (async).
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @note UNUSED Size: 000034
 */
void CardUtilFormat(s32 chan)
{
	CardUtilCommand(chan, CARDCMD_Format, 0, nullptr, 0, 0);
}

/**
 * @brief Checks if card is busy.
 */
bool CardUtilIsCardBusy()
{
	return CardControl.mChannel != -1;
}

/**
 * @brief Yields working thread while card is busy.
 */
void CardUtilIdleWhileBusy()
{
	while (CardControl.mChannel != -1) {
		OSYieldThread();
	}
}

/**
 * @brief Signals to erase file from card (async).
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param fileNo File number/index to erase.
 */
void CardUtilErase(s32 chan, s32 fileNo)
{
	CardUtilCommand(chan, CARDCMD_Erase, fileNo, nullptr, 0, 0);
}

/**
 * @brief Signals to read in data from card (async).
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param fileNo Index of file to read in.
 * @param workBuffer Pointer to working area to read data into.
 */
void CardUtilOpen(s32 chan, s32 fileNo, void* workBuffer)
{
	CardUtilCommand(chan, CARDCMD_Open, fileNo, workBuffer, 0, 0);
}

/**
 * @brief Signals to save file to card (async).
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param fileState Status info for file to save.
 * @param data Pointer to file data to save.
 */
void CardUtilSave(s32 chan, CARDStat* fileState, void* data)
{
	// no clue why they needed to force the CARDStat pointer in as a long
	CardUtilCommand(chan, CARDCMD_Save, (s32)fileState, data, 0, 0);
}

/**
 * @brief Signals to write a chunk of data to card (async).
 * @param chan Memory card channel (0 or 1 for Slot A or Slot B).
 * @param fileNo Index of file to write to.
 * @param data Pointer to data to write from.
 * @param offset Offset of data to write (within data buffer).
 * @param length Length of data to write.
 */
void CardUtilWrite(s32 chan, s32 fileNo, void* data, u32 offset, u32 length)
{
	CardUtilCommand(chan, CARDCMD_Write, fileNo, data, offset, length);
}

/**
 * @brief Main loop for the card utility thread.
 *
 * Waits for commands to be issued to CardControl, then executes them
 * on the memory card in a thread-safe manner.
 *
 * @note Parameter and return are unused, but required to align with the `OSThreadStartFunction` typedef.
 * @warning NON-MATCHING! Functionally equivalent.
 */
static void* CardUtilMain(void*)
{
	// I think variable declaration needs jostling, along with maybe some inline adjustments.
	s32 chan;   // r23
	void* data; // r22
	s32 offset; // r21
	s32 res;    // r20
	void* file; // r19
	s32 length; // r17
	s32 cmd;    // r16
	while (true) {

		OSLockMutex(&CardControl.mMutex);
		while (!CardUtilIsCardBusy()) {
			OSWaitCond(&CardControl.mCondition, &CardControl.mMutex);
		}

		// get command info from global object (thread-safe)
		cmd    = CardControl.mCommand; // r16
		chan   = CardControl.mChannel; // r23
		file   = CardControl.mFileNo;  // r19
		data   = CardControl.mDataPtr; // r22
		offset = CardControl.mOffset;  // r21
		length = CardControl.mLength;  // r17
		OSUnlockMutex(&CardControl.mMutex);

		// execute command
		switch (cmd) {
		case CARDCMD_Mount:
			res = DoMount(chan, data);
			break;

		case CARDCMD_Unmount:
			res = DoUnmount(chan);
			break;

		case CARDCMD_Format:
			res = DoFormat(chan);
			break;

		case CARDCMD_List:
			res = DoList(chan, (CardUtilDirent*)data);
			break;

		case CARDCMD_Erase:
			res = DoErase(chan, (s32)file);
			break;

		case CARDCMD_Open:
			res = DoOpen(chan, (s32)file, data);
			break;

		case CARDCMD_Save:
			res = DoSave(chan, (CARDStat*)file, data);
			break;

		case CARDCMD_Write:
			u32 uLength = length;
			res         = DoWrite(chan, (s32)file, data, uLength, offset);
			break;
		}

		// update global objects with results
		OSLockMutex(&CardControl.mMutex);
		if (res == CARD_RESULT_IOERROR) {
			gameflow.mMemoryCard.mDidSaveFail = true;
		}
		CardControl.mResultCode = res;
		// mark card as idle
		CardControl.mChannel = -1;
		OSUnlockMutex(&CardControl.mMutex);

		STACK_PAD_TERNARY(CardControl.mChannel, 1);
	}
}

/**
 * @brief Initialises the card utility thread and associated sync primitives.
 *
 * @param stack Stack pointer for card utility thread.
 * @param stackSize Size of stack for card utility thread.
 * @param prio Thread priority for card utility thread.
 */
void CardUtilInit(void* stack, u32 stackSize, s32 prio)
{
	OSInitMutex(&CardControl.mMutex);
	OSInitMutex(&CardControl.mDirMutex);
	OSInitCond(&CardControl.mCondition);
	OSCreateThread(&CardThread.mThread, CardUtilMain, nullptr, stack, stackSize, prio, OS_THREAD_ATTR_DETACH);
	OSResumeThread(&CardThread.mThread);
}

/**
 * @brief Stripped function, not yet decompiled or reconstructed.
 * @note UNUSED Size: 000238
 */
void CardUtilDrawIcon(int, int, int, void*, void*, u16, u16, int)
{
	// UNUSED FUNCTION
}

/**
 * @brief Stripped function, not yet decompiled or reconstructed.
 * @note UNUSED Size: 000168
 */
void CardUtilDrawAnimatedIcon(CardUtilDirent*, int, int, int)
{
	// UNUSED FUNCTION
}

/**
 * @brief Stripped function, not yet decompiled or reconstructed.
 * @note UNUSED Size: 000050
 */
void CardUtilGetProgress(s32)
{
	// UNUSED FUNCTION
}
