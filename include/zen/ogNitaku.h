#ifndef _ZEN_OGNITAKU_H
#define _ZEN_OGNITAKU_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DScreen;
struct P2DTextBox;

namespace zen {

/**
 * @brief TODO
 */
struct ogNitakuMgr {

	/**
	 * @brief TODO
	 */
	enum NitakuStatus {
		// TODO: this
	};

	ogNitakuMgr(P2DScreen*, P2DTextBox*, P2DTextBox*, P2DTextBox*, bool, bool);

	void start();
	NitakuStatus update(Controller*);
	void cursorEnable(f32);
	void cursorDisable(f32);

	// unused/inlined:
	void MoveCursorYes(f32);
	void MoveCursorNo(f32);
	void InitCursor();
	void stop();

	// TODO: members
	u8 _00[0xc4];
};

} // namespace zen

#endif
