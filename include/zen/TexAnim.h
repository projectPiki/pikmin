#ifndef _ZEN_TEXANIM_H
#define _ZEN_TEXANIM_H

#include "types.h"

struct Texture;

namespace zen {

/**
 * @brief TODO
 */
struct TexAnim {

	/**
	 * @brief TODO
	 */
	struct AnimData {
		AnimData();

		// TODO: members
	};

	void setData(u32, Texture*, f32);
	void update();

	// unused/inlined:

	// TODO: members
};

} // namespace zen

#endif
