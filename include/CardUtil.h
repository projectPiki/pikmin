#ifndef _CARDUTIL_H
#define _CARDUTIL_H

#include "Dolphin/OS/OSThread.h"
#include "Dolphin/OS/OSMutex.h"
#include "Dolphin/card.h"
#include "types.h"

struct CARDStat;

/**
 * @brief TODO
 */
enum CardUtilCommands {
	CARDCMD_Mount   = 1,
	CARDCMD_Unmount = 2,
	CARDCMD_Format  = 3,
	CARDCMD_List    = 4,
	CARDCMD_Erase   = 5,
	CARDCMD_Open    = 6,
	CARDCMD_Save    = 7,
	CARDCMD_Write   = 9,
};

/**
 * @brief TODO
 *
 * @note Size: 0x5B40 (or a multiple of that?)
 */
struct CardUtilDirent {
	u8 _00[0x5A40];            // _00, unknown
	s32 mFileNo;               // _5A40
	CARDStat mState;           // _5A44
	u32 _5AB0;                 // _5AB0, unknown
	u32 _5AB4[8];              // _5AB4, unknown
	u8 _5AD4[0x5AEC - 0x5AD4]; // _5AD4, unknown
	u32 _5AEC[8];              // _5AEC, unknown
	u8 _5B0C[0x5B40 - 0x5B0C]; // _5B0C, unknown
};

/**
 * @brief TODO
 */
struct CardUtilThread {
	OSThread mThread; // _00
};

/**
 * @brief TODO
 */
struct CardUtilControl {
	OSMutex mMutex;      // _00
	OSCond mCondition;   // _18
	s32 mChannel;        // _20
	s32 mCommand;        // _24
	s32 mFileNo;         // _28
	void* mAddr;         // _2C
	u32 mOffset;         // _30
	u32 mLength;         // _34
	s32 mResultCode;     // _38
	s32 mByteNotUsed;    // _3C
	s32 mFilesNotUsed;   // _40
	u32 mSectorSize;     // _44, unknown
	u32 _48;             // _48, unknown
	u32 _4C;             // _4C, unknown
	OSMutex mMutex2;     // _50
	CardUtilDirent* _68; // _68, unknown
	u32 _6C;             // _6C, unknown
};

// Global CARD utility functions:
int CardUtilResultCode();
void CardUtilMount(s32, void*);
void CardUtilUnmount(s32);
bool CardUtilIsCardBusy();
void CardUtilIdleWhileBusy();
void CardUtilErase(s32, s32);
void CardUtilOpen(s32, s32, void*);
void CardUtilSave(s32, CARDStat*, void*);
void CardUtilWrite(s32, s32, void*, u32, u32);
void CardUtilInit(void*, u32, s32);

#endif
