#ifndef _ZEN_DRAWACCOUNT_H
#define _ZEN_DRAWACCOUNT_H

#include "types.h"
#include "zen/DrawCommon.h"

struct Graphics;

namespace zen {

/**
 * @brief TODO
 */
struct AccountData {
	AccountData() { }
	AccountData(s16 minPiki, s16 maxPiki, s16 deadPiki, s16 deadTeki, s16 pellets)
	{
		_00 = minPiki;
		_02 = maxPiki;
		_04 = deadPiki;
		_06 = deadTeki;
		_08 = pellets;
	}

	s16 _00; // _00
	s16 _02; // _02
	s16 _04; // _04
	s16 _06; // _06
	s16 _08; // _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x120.
 */
struct DrawAccount : public DrawScreen {

	DrawAccount();

	virtual void update(); // _08

	void start(AccountData&);
	void draw(Graphics&);

	// unused/inlined:

	// _00-_100 = DrawScreen
	u8 _100[0x120 - 0x100]; // _100, unknown
};

} // namespace zen

extern zen::DrawAccount* accountWindow;

#endif
