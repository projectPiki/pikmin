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
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
struct DrawGameOver {

	/**
	 * @brief TODO
	 */
	enum modeFlag {
		MODE_Unk0 = 0,
		MODE_Unk1 = 1,
	};

	DrawGameOver();

	void start(modeFlag, f32);
	bool update(Controller*);
	void draw(Graphics&);

	int _00;                 // _00
	DrawGameOverScreen* _04; // _04
	DrawGameOverScreen* _08; // _08
	DrawGameOverScreen* _0C; // _0C
	modeFlag mMode;          // _10
	f32 _14;                 // _14
	f32 _18;                 // _18
};

} // namespace zen

#endif
