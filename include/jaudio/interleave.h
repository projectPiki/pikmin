#ifndef _JAUDIO_INTERLEAVE_H
#define _JAUDIO_INTERLEAVE_H

#include "types.h"

/**
 * @brief TODO
 */
typedef struct il_buf {
	BOOL _00; // _00
	u8* _04;  // _04
	u32 _08;  // _08
	int _0C;  // _0C
	u32 _10;  // _10
	u32 _14;  // _14
	u32 _18;  // _18
} il_buf;

// Global functions:
void Jac_SendStreamData(u8*, u32);
BOOL Jac_CheckStreamFree(u32);
BOOL Jac_CheckStreamRemain(u32);
void Jac_GetStreamData(u8*, u32);
void Jac_InitStreamData(u8*, u32);

// Unused functions:
void Jac_GetStreamRemain();

#endif
