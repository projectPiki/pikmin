#ifndef _ZEN_DRAWWMPAUSE_H
#define _ZEN_DRAWWMPAUSE_H

#include "types.h"

struct Graphics;
struct Controller;
struct P2DPicture;

namespace zen {

struct DrawMenu;

/**
 * @brief TODO
 */
struct DrawWMPause {

	/**
	 * @brief World map exit status codes
	 */
	enum returnStatusFlag {
		RETURN_NULL    = -1,
		CourseSelected = 0, // Player selected a course
		DiaryOpened    = 1, // Player opened captain's diary
		Cancelled      = 2, // Player cancelled/exited map
	};

	DrawWMPause();

	void start();
	returnStatusFlag update(Controller*);
	void draw(Graphics&);

	DrawMenu* mPauseMenu;         // _00
	returnStatusFlag mReturnFlag; // _04
	P2DPicture* mBackPane;        // _08
};

} // namespace zen

#endif
