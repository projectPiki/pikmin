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

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	ogDrawScrMenu();

	returnStatusFlag update(Controller*, bool, bool);

	// unused/inlined:
	void setScreen(char*);
	void calcAngleSpeed(f32);
	bool draw(Graphics&);

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

	/**
	 * @brief TODO
	 */
	enum returnStatusFlag {
		// TODO: this
	};

	ogScrMenuMgr();

	void start();
	returnStatusFlag update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void updateInfo(Controller*);
	void updateCont(Controller*);

	// TODO: members
	u8 _00[0x6C]; // _00
};

// unused global functions:
void ChkAngle(f32*);

} // namespace zen

#endif
