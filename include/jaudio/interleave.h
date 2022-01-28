#ifndef _JAUDIO_INTERLEAVE_H
#define _JAUDIO_INTERLEAVE_H

#include "types.h"

struct il_buf {
	BOOL _00;
	u8* _04;
	u32 _08;
	int _0C;
	u32 _10;
	u32 _14;
	u32 _18;
};

#endif
