#include "TAI/Animation.h"

#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(14)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr);

AnimInfo* TAIanimation::addAnimation(immut char* anim)
{
	mAnimInfo = mAnimMgr->addAnimation(anim, true);
	if (!mAnimInfo) {
		ERROR("%s is not found.\n", anim);
	}
	return mAnimInfo;
}
