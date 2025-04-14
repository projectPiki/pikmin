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
	 * @brief TODO
	 */
	enum returnStatusFlag {
		RETURN_NULL = -1,
		RETURN_Unk0 = 0,
		RETURN_Unk1 = 1,
		RETURN_Unk2 = 2,
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
