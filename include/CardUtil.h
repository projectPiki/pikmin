#ifndef _CARDUTIL_H
#define _CARDUTIL_H

#include "types.h"

struct CARDStat;

/**
 * @brief TODO
 */
struct CardUtilDirent {
	// TODO: members
};

// Global CARD utility functions:
void CardUtilResultCode();
void CardUtilMount(s32, void*);
void CardUtilUnmount(s32);
void CardUtilIsCardBusy();
void CardUtilIdleWhileBusy();
void CardUtilErase(s32, s32);
void CardUtilOpen(s32, s32, void*);
void CardUtilSave(s32, CARDStat*, void*);
void CardUtilWrite(s32, s32, void*, u32, u32);
void CardUtilInit(void*, u32, s32);

#endif
