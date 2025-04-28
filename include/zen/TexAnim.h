#ifndef _ZEN_TEXANIM_H
#define _ZEN_TEXANIM_H

#include "types.h"

struct Texture;

namespace zen {

/**
 * @brief A struct to hold texture animation data.
 */
struct TexAnim {

	/**
	 * @brief A struct to hold the animation data.
	 */
	struct AnimData {
		AnimData()
		{
			mTexture = nullptr;
			mTime    = 0.0f;
		}

		void setData(Texture* tex, f32 time)
		{
			mTexture = tex;
			mTime    = time;
		}

		Texture* mTexture; // _00
		f32 mTime;         // _04
	};

	TexAnim(int size)
	{
		mCurrentAnimIndex = 0;
		mAnimSize         = size;
		mData             = new AnimData[mAnimSize];
		mAnimTimer        = 0.0f;
	}

	void setData(u32 index, Texture* texture, f32 time);
	Texture* update();

	Texture* getTexPtr() { return mData[mCurrentAnimIndex].mTexture; }

	u32 mCurrentAnimIndex; // _00
	u32 mAnimSize;         // _04
	AnimData* mData;       // _08
	f32 mAnimTimer;        // _0C
};

} // namespace zen

#endif
