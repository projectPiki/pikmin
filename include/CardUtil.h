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
struct CardUtilDirent {
	// TODO: members
};

struct CardUtilThread {
	OSThread mThread; // _00
};

struct CardUtilControl {
	OSMutex mMutex; // _00
	OSCond mCondition;
	int mChannel;
	int mCommand;
	int test[1];
	int mFileId;
	int test2[8];
	OSMutex mMutex2;
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
