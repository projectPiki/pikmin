#ifndef _PIKIINFO_H
#define _PIKIINFO_H

#include "types.h"

struct PikiInfo {
	PikiInfo();

	void addFormationPiki();
	void subFormationPiki();

	int mFormationPikiCnt; // _00
	int _04;               // _04
	u32 _08;               // _08
	u32 _0C;               // _0C
	u32 _10;               // _10
	u32 _14;               // _14
	u32 _18;               // _18
};

extern PikiInfo* pikiInfo;

#endif
