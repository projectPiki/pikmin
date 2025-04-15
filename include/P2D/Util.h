#ifndef _P2D_UTIL_H
#define _P2D_UTIL_H

#include "types.h"

/**
 * @brief TODO
 */
enum P2DBinding {
	P2DBIND_Unk0 = 0x1,
	P2DBIND_Unk1 = 0x2,
	P2DBIND_Unk2 = 0x4,
	P2DBIND_Unk3 = 0x8,

	P2DBIND_All = P2DBIND_Unk0 | P2DBIND_Unk1 | P2DBIND_Unk2 | P2DBIND_Unk3,
};

/**
 * @brief TODO
 */
enum P2DMirror {
	P2DMIRROR_Unk0 = 0,
	P2DMIRROR_Unk1 = 1,
	P2DMIRROR_Unk2 = 2,
};

/**
 * @brief TODO
 */
enum P2DWrapmode {
	P2DWRAP_NULL = -1,
	P2DWRAP_Unk0 = 0,
};

/**
 * @brief TODO
 */
enum P2DRotateAxis {
	P2DROTATE_Unk1 = 1,
	P2DROTATE_X    = 'x', // 120
	P2DROTATE_Y    = 'y', // 121
	P2DROTATE_Z    = 'z', // 122
};

/**
 * @brief TODO
 */
enum P2DTextBoxHBinding {

};

/**
 * @brief TODO
 */
enum P2DTextBoxVBinding {

};

#endif
