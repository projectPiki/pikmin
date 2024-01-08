#ifndef _TAIANIMATION_H
#define _TAIANIMATION_H

#include "types.h"
#include "Animator.h"

/**
 * @brief TODO
 */
struct TAIanimation {
	AnimInfo* addAnimation(char* anim);

	u32 _00;             // _00
	AnimMgr* mAnimmgr;   // _04
	AnimInfo* mAnimInfo; // _08
};

#endif
