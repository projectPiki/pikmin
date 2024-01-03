#ifndef _TAIANIMATION_H
#define _TAIANIMATION_H
#include "types.h"

struct AnimInfo {
	AnimInfo();
};
struct AnimMgr {
	AnimMgr();
	AnimInfo* addAnimation(char*, bool);
};

struct TAIanimation {
	u32 _00;             // _00
	AnimMgr* mAnimmgr;   // _04
	AnimInfo* mAniminfo; // _08

	AnimInfo* addAnimation(char* anim);
};
#endif
