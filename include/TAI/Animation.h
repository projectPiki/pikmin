#ifndef _TAIANIMATION_H
#define _TAIANIMATION_H

#include "types.h"
#include "Animator.h"

/**
 * @brief TODO
 */
struct TAIanimation {
	// TAIanimation(int, char*); // DLL inline, to do

	AnimInfo* addAnimation(char* anim);

	void addInfoKey(int index, int value) { mAnimInfo->addInfoKey(new AnimKey(index, value)); }

	// DLL inlines to do:
	void addKeyFrame(int index)
	{
		mAnimInfo->mAnimKeys.mPrev->mKeyframeIndex = index;
		mAnimInfo->addKeyFrame();
	}
	void setAnimFlags(u32 flags) { mAnimInfo->setAnimFlags(flags); }

	u32 _00;             // _00
	AnimMgr* mAnimmgr;   // _04
	AnimInfo* mAnimInfo; // _08
};

#endif
