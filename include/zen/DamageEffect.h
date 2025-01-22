#ifndef _ZEN_DAMAGEEFFECT_H
#define _ZEN_DAMAGEEFFECT_H

#include "types.h"

struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct DamageEffect {
	DamageEffect();

	bool update();
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
