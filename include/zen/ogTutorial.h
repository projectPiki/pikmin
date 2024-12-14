#ifndef _ZEN_OGTUTORIAL_H
#define _ZEN_OGTUTORIAL_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DTextBox;

namespace zen {

struct ogScrMessageMgr;

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

	ogScrMessageMgr* mMessageMgr; // _00
	int _04;                      // _04
};

extern char** bloFiles_Tutorial[];

} // namespace zen

#endif
