#ifndef _ZEN_DRAWGAMEOVER_H
#define _ZEN_DRAWGAMEOVER_H

#include "types.h"

struct Graphics;
struct Controller;
struct P2DPane;

namespace zen {

/**
 * @brief TODO
 */
struct DrawGameOver {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		// TODO: this
	};

	DrawGameOver();

	void start(modeFlag, f32);
	bool update(Controller*);
	void draw(Graphics&);

	// TODO: members
	u8 _00[0x1C];
};

/**
 * @brief TODO
 */
struct DrawGameOverLetter {
	DrawGameOverLetter();

	void init(P2DPane*);
	void initParams();
	bool update();

	// TODO: members
};

} // namespace zen

#endif
