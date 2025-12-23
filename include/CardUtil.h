#ifndef _CARDUTIL_H
#define _CARDUTIL_H

#include "Dolphin/OS/OSMutex.h"
#include "Dolphin/OS/OSThread.h"
#include "Dolphin/card.h"
#include "types.h"

struct CARDStat;

////////////////////////////////////////////
//////////// CARD UTILITY TYPES ////////////
////////////////////////////////////////////

/**
 * @brief Card operation commands (to be performed asynchronously).
 */
enum CardUtilCommands {
	CARDCMD_Mount   = 1, ///< 0x1, mount card.
	CARDCMD_Unmount = 2, ///< 0x2, unmount card.
	CARDCMD_Format  = 3, ///< 0x3, format card.
	CARDCMD_List    = 4, ///< 0x4, fetch list of save files.
	CARDCMD_Erase   = 5, ///< 0x5, erase file.
	CARDCMD_Open    = 6, ///< 0x6, open and read file.
	CARDCMD_Save    = 7, ///< 0x7, save file.
	CARDCMD_Write   = 9, ///< 0x9, write data to file.
};

/**
 * @brief Structure of a single directory entry (file) for memory card save data.
 * @note Size: 0x5B40.
 */
struct CardUtilDirent {
	u8 mFileData[0x5A00];                   ///< _0000, actual file data buffer.
	u8 mFileCommentData[CARD_COMMENT_SIZE]; ///< _5A00, comment associated with file.
	s32 mFileNo;                            ///< _5A40, entry number in directory list.
	CARDStat mState;                        ///< _5A44, info relating to card status.
	u32 mAnimTotalFrames;                   ///< _5AB0, total animation frames for card data icon.
	u32 mAnimFrameOffsets[14];              ///< _5AB4, offsets for each animation frame (8 normal + 6 bounce).
	u32 mAnimIconIndices[14];               ///< _5AEC, icon indices for each frame (8 normal + 6 bounce).
	u8 _5B0C[0x5B40 - 0x5B24];              ///< _5B0C, unknown/padding.
};

/**
 * @brief Wrapper for the card operation thread.
 * @note Size: 0x310.
 */
struct CardUtilThread {
	OSThread mThread; ///< _00, thread for card operations.
};

/**
 * @brief Pikmin-specific memory card control structure.
 * @note Size: 0x70.
 */
struct CardUtilControl {
	OSMutex mMutex;              ///< _00, main mutex for card command queueing.
	OSCond mCondition;           ///< _18, condition for thread signalling.
	s32 mChannel;                ///< _20, current operation channel (0:Slot A or 1:Slot B).
	s32 mCommand;                ///< _24, current command (see `CardUtilCommands` enum).
	void* mFileNo;               ///< _28, file number OR pointer to file status for current file.
	void* mDataPtr;              ///< _2C, pointer to data to write from, or work area to mount/read into.
	u32 mOffset;                 ///< _30, offset within data buffer for write operations.
	u32 mLength;                 ///< _34, length of data to write for write operations.
	s32 mResultCode;             ///< _38, result code of last operation.
	s32 mByteNotUsed;            ///< _3C, free bytes on card.
	s32 mFilesNotUsed;           ///< _40, free file slots on card.
	u32 mSectorSize;             ///< _44, sector size of card.
	u32 mTransferredBytes;       ///< _48, transfer bytes - unused, likely for progress tracking.
	u32 mOperationSize;          ///< _4C, size of current operation - stored but unused, likely for progress tracking.
	OSMutex mDirMutex;           ///< _50, mutex for directory entry (file) list handling.
	CardUtilDirent* mDirentList; ///< _68, pointer to directory entry (file) list.
	int mDirentCount;            ///< _6C, number of directory entries (files).
};

////////////////////////////////////////////
/////// GLOBAL CARD UTILITY FUNCTIONS //////
////////////////////////////////////////////

s32 CardUtilResultCode();
void CardUtilMount(s32 chan, void* workBuffer);
void CardUtilUnmount(s32 chan);
bool CardUtilIsCardBusy();
void CardUtilIdleWhileBusy();
void CardUtilErase(s32 chan, s32 fileNo);
void CardUtilOpen(s32 chan, s32 fileNo, void* workBuffer);
void CardUtilSave(s32 chan, CARDStat* fileState, void* data);
void CardUtilWrite(s32 chan, s32 fileNo, void* data, u32 offset, u32 length);
void CardUtilInit(void* stack, u32 stackSize, s32 prio);

////////////////////////////////////////////

#endif
