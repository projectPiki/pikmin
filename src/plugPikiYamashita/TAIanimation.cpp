#include "TAI/Animation.h"

/*
 * --INFO--
 * Address:	801A3594
 * Size:	00003C
 */
AnimInfo* TAIanimation::addAnimation(char* anim)
{
	mAnimInfo = mAnimmgr->addAnimation(anim, true);
	return mAnimInfo;
}
