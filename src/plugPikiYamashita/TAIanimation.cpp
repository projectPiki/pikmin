#include "TAIanimation.h"

/*
 * --INFO--
 * Address:	801A3594
 * Size:	00003C
 */
AnimInfo* TAIanimation::addAnimation(char* anim)
{
	mAniminfo = mAnimmgr->addAnimation(anim, true);
	return mAniminfo;
}
