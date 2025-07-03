#include "zen/TexAnim.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(16)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr);

/*
 * --INFO--
 * Address:	801C10A0
 * Size:	000024
 */
void zen::TexAnim::setData(u32 index, Texture* texture, f32 time)
{
	if (index >= mAnimSize) {
		ERROR("texNo ERROR %d < %d \n", index, mAnimSize);
	} else {
		mData[index].setData(texture, time);
	}
}

/*
 * --INFO--
 * Address:	801C10C4
 * Size:	00007C
 */
Texture* zen::TexAnim::update()
{
	mAnimTimer += gsys->getFrameTime();

	zen::TexAnim::AnimData* anim = &mData[mCurrentAnimIndex];
	for (; mAnimTimer > anim->mTime; anim = &mData[mCurrentAnimIndex]) {
		mAnimTimer -= anim->mTime;
		if (++mCurrentAnimIndex >= mAnimSize) {
			mCurrentAnimIndex = 0;
		}
	}

	return anim->mTexture;
}
