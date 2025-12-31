#include "zen/TexAnim.h"
#include "DebugLog.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(16)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr);

/**
 * @todo: Documentation
 */
void zen::TexAnim::setData(u32 index, Texture* texture, f32 time)
{
	if (index < mAnimSize) {
		mData[index].setData(texture, time);
	} else {
		ERROR("texNo ERROR %d < %d \n", index, mAnimSize);
	}
}

/**
 * @todo: Documentation
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
