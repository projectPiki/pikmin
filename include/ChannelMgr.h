#ifndef _CHANNELMGR_H
#define _CHANNELMGR_H

#include "types.h"

struct ChannelMgr {
	ChannelMgr();

	f32 mRumbleTimer;     // _00
	f32 mRumbleIntensity; // _04
	f32 mRumbleScale;     // _08
	s32 _0C;              // _0C
	s32 _10;              // _10
};

#endif
