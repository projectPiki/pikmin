#ifndef _ZEN_OGTUTORIAL_H
#define _ZEN_OGTUTORIAL_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DTextBox;

namespace zen {

/**
 * @brief TODO
 */
struct ogScrTutorialMgr {

	/**
	 * @brief TODO
	 */
	enum EnumTutorial {
		// TODO: this
	};

	ogScrTutorialMgr();

	void update(Controller*);
	void draw(Graphics&);
	void start(zen::ogScrTutorialMgr::EnumTutorial);

	// unused/inlined:
	void nextPage();
	void backPage();
	void setCursorXY(P2DTextBox*);

	// TODO: members
};

} // namespace zen

#endif
