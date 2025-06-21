#ifndef _ZEN_DRAWGAMEOVER_H
#define _ZEN_DRAWGAMEOVER_H

#include "types.h"
#include "zen/DrawCommon.h"

struct Graphics;
struct Controller;
struct P2DPane;

namespace zen {

/**
 * @brief TODO
 *
 * @note Size: 0x30. In drawGameOver.cpp for PRINT/ERROR reasons.
 */
struct DrawGameOverLetter;

/**
 * @brief TODO
 *
 * @note Size: 0xC. In drawGameOver.cpp for PRINT/ERROR reasons.
 */
struct DrawGameOverScreen;

/**
 * @brief The current state of the "Game Over" screen logic.
 */
DEFINE_ENUM_TYPE(GameOverState,
                 Inactive  = 0, // The screen is not active.
                 Start     = 1, // The screen has started and is in an initial delay period.
                 WaitInput = 2  // The screen is waiting for player input or a timeout to finish.
);

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct DrawGameOver {

	/**
	 * @brief The type of "Game Over" screen to display.
	 */
	enum modeFlag {
		MODE_GameOverA = 0, // The normal "gameover.blo" screen.
		MODE_GameOverB = 1, // The alternative "gameove2.blo" screen.
	};

	DrawGameOver();

	void start(modeFlag, f32);
	bool update(Controller*);
	void draw(Graphics&);

	int mState;                        // _00
	DrawGameOverScreen* mGameOverA;    // _04
	DrawGameOverScreen* mGameOverB;    // _08
	DrawGameOverScreen* mActiveScreen; // _0C
	modeFlag mMode;                    // _10
	f32 mStateTimer;                   // _14
	f32 mInputWaitTime;                // _18
};

} // namespace zen

#endif
