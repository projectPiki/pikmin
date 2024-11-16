#ifndef _FLOWCONTROLLER_H
#define _FLOWCONTROLLER_H

#include "types.h"
#include "OnePlayerSection.h"

struct StageInfo;

/**
 * @brief TODO
 *
 * @note Size: 0x25C.
 */
struct FlowController {
	inline FlowController()
	{
		_244 = 0;
		_230 = 0;
	}

	void readMapList(char*);

	// unused/inlined:
	void setStage(char*);

	// TODO: members
	StageInfo mRootInfo;    // _00
	StageInfo* _A8;         // _A8
	u8 _AC[0x4];            // _AC, unknown
	char _B0[0x10];         // _B0, i have no idea how big this array is, this is a guess for now
	u8 _C0[0x230 - 0xC0];   // _B4, unknown
	u32 _230;               // _230, unknown
	u8 _234[0x244 - 0x234]; // _234, unknown
	int _244;               // _244
	u8 _248[0x24C - 0x248]; // _248, unknown
	u32 _24C;               // _24C, unknown
	u32 _250;               // _250, unknown
	u8 _254[0x25C - 0x254]; // _254, unknown
};

extern FlowController flowCont;

#endif
