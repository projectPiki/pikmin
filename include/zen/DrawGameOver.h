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
	void update(Controller*);
	void draw(Graphics&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct DrawGameOverLetter {
	DrawGameOverLetter();

	void init(P2DPane*);
	void initParams();
	void update();

	// TODO: members
};

} // namespace zen

#endif
