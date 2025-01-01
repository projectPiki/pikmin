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
		AnimData();

		// 10219570
		inline void setData(Texture* tex, f32 time)
		{
			mTexture = tex;
			mTime    = time;
		}

		Texture* mTexture;
		f32 mTime;
	};

	void setData(u32 index, Texture* texture, f32 time); // 102193B0
	Texture* update();                                   // 102194A0

	// 101E14A0
	inline Texture* getTexPtr() { return mData[mCurrentAnimIndex].mTexture; }

	u32 mCurrentAnimIndex; // _00
	u32 mAnimSize;         // _04
	AnimData* mData;       // _08
	f32 mAnimTimer;        // _0C
};

} // namespace zen

#endif
