#ifndef _TAIANIMATION_H
#define _TAIANIMATION_H

#include "types.h"
#include "Animator.h"
#include "teki.h"

/**
 * @brief TODO
 */
struct TAIanimation {
	TAIanimation(int tekiType, char* bunFile)
	{
		if (tekiMgr->isUsingType(tekiType)) {
			mAnimMgr = tekiMgr->mTekiShapes[tekiType]->mAnimMgr;
			gsys->loadBundle(bunFile, false);
		} else {
			mAnimMgr = nullptr;
		}
		mAnimInfo = nullptr;
	}

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
	AnimMgr* mAnimMgr;   // _04
	AnimInfo* mAnimInfo; // _08
};

#endif
