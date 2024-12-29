#ifndef _FLOWCONTROLLER_H
#define _FLOWCONTROLLER_H

#include "types.h"
#include "OnePlayerSection.h"

struct StageInfo;
struct Navi;

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
	char _B0[0x80];         // _B0
	char _130[0x80];        // _130, stage file name?
	char _1B0[0x80];        // _1B0
	int _230;               // _230, unknown
	u8 _234[0x244 - 0x234]; // _234, unknown
	int _244;               // _244
	u32 _248;               // _248, unknown
	u32 _24C;               // _24C, unknown
	u32 _250;               // _250, unknown
	u32 _254;               // _254, unknown
	u32 _258;               // _258, unknown
};

extern FlowController flowCont;

#endif
