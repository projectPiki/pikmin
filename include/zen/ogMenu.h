#ifndef _ZEN_OGMENU_H
#define _ZEN_OGMENU_H

#include "types.h"

struct Controller;
struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct ogDrawScrMenu {
	ogDrawScrMenu();

	void update(Controller*, bool, bool);

	// unused/inlined:
	void setScreen(char*);
	void calcAngleSpeed(f32);
	void draw(Graphics&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct ogDrawScrController {
	ogDrawScrController();

	void update();

	// unused/inlined:
	void setWinColor();
	void setOriginalColor();
	void setHantenColor();

	// TODO: members
};

/**
 * @brief TODO
 */
struct ogDrawScrInfo {
	ogDrawScrInfo();

	void start();

	// unused/inlined:
	void update(Controller*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct ogDrawScrInfo2 {
	ogDrawScrInfo2(); // unused/inlined

	// unused/inlined:
	void start();
	void update(Controller*);
	void drawHougaku(Graphics&);

	// TODO: members
};

/**
 * @brief TODO
 */
struct ogScrMenuMgr {
	ogScrMenuMgr();

	void start();
	void update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void updateInfo(Controller*);
	void updateCont(Controller*);

	// TODO: members
};

// unused global functions:
void ChkAngle(f32*);

} // namespace zen

#endif
