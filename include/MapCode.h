#ifndef _MAPCODE_H
#define _MAPCODE_H

#include "types.h"

struct CollTriInfo;

/**
 * @brief TODO
 */
struct MapCode {
	u32 getAttribute(CollTriInfo*);
	u32 getSlipCode(CollTriInfo*);
	bool isBald(CollTriInfo*);

	// unused/inlined
	char* getAttributeName(int); // UNUSED

	u32 _00; // _00
	u32 _04; // _04
	u32 _08; // _08
	u32 _0C; // _0C
	u32 _10; // _10
	u32 _14; // _14
	u32 _18; // _18
	f32 _1C; // _1C
};

#endif
