#ifndef _JAUDIO_INTERLEAVE_H
#define _JAUDIO_INTERLEAVE_H

#include "types.h"

/**
 * @brief TODO
 */
struct il_buf {
	BOOL isInit;      // _00
	u8* bufData;      // _04
	u32 bufSize;      // _08
	u32 bufSendIdx;   // _0C
	u32 bufGetIdx;    // _10
	u32 streamRemain; // _14
	u32 streamFree;   // _18
};

typedef struct il_buf InterleaveBuffer;

BOOL Jac_SendStreamData(u8* data, u32 size);
BOOL Jac_CheckStreamFree(u32 size);
BOOL Jac_CheckStreamRemain(u32 size);
u32 Jac_GetStreamRemain(); // UNUSED
u32 Jac_GetStreamData(u8* data, u32 size);
void Jac_InitStreamData(u8* data, u32 size);

#endif
