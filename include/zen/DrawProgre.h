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
 *
 * @note Size: 0x10.
 */
struct DrawProgre {

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	DrawProgre();

	void start();
	returnStatusFlag update(Controller*);
	void draw(Graphics&);

	u8 _00[0x10]; // _00, unknown
};

} // namespace zen

#endif
