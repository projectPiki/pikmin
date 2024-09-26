#ifndef _ZEN_DRAWPROGRE_H
#define _ZEN_DRAWPROGRE_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct DrawProgreMes {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	void setMode(zen::DrawProgreMes::modeFlag);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawProgre {
	DrawProgre();

	void start();
	void update(Controller*);
	void draw(Graphics&);

	// TODO: members
};

} // namespace zen

#endif
