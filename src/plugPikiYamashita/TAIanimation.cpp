#include "TAI/Animation.h"

#include "DebugLog.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(14)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT(nullptr);

/**
 * @todo: Documentation
 */
AnimInfo* TAIanimation::addAnimation(immut char* anim)
{
	mAnimInfo = mAnimMgr->addAnimation(anim, true);
	if (!mAnimInfo) {
		ERROR("%s is not found.\n"); // including the name breaks matching
	}
	return mAnimInfo;
}
