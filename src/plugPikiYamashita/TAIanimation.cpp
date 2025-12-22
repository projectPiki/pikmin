#include "TAI/Animation.h"

#include "DebugLog.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(14)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT(nullptr);

/**
 * @TODO: Documentation
 */
AnimInfo* TAIanimation::addAnimation(immut char* anim)
{
	mAnimInfo = mAnimMgr->addAnimation(anim, true);
	if (!mAnimInfo) {
		ERROR("%s is not found.\n", anim);
	}
	return mAnimInfo;
}
