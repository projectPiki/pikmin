#ifndef _FLOWCONTROLLER_H
#define _FLOWCONTROLLER_H

#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x25C.
 */
struct FlowController {
	void readMapList(char*);

	// unused/inlined:
	void setStage(char*);

	// TODO: members
	u8 _00[0x244];          // _00, unknown
	int _244;               // _244
	u8 _248[0x24C - 0x248]; // _248, unknown
	u32 _24C;               // _24C, unknown
	u32 _250;               // _250, unknown
	u8 _254[0x25C - 0x254]; // _254, unknown
};

extern FlowController flowCont;

#endif
