#ifndef _ZEN_OGMAP_H
#define _ZEN_OGMAP_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DPane;
struct P2DTextBox;
struct P2DScreen;

namespace zen {

struct TypingTextMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x30.
 */
struct ogScrMapMgr {

	/**
	 * @brief TODO
	 */
	enum MapStatus {
		MAP_NULL = -1,
		MAP_Unk0 = 0,
		MAP_Unk1 = 1,
		MAP_Unk2 = 2,
		MAP_Unk4 = 4,
	};

	ogScrMapMgr();

	void start(s16);
	MapStatus update(Controller*);
	void draw(Graphics&);

	MapStatus mState;              // _00
	P2DScreen* _04;                // _04
	P2DScreen* mTestScreen;        // _08, test.blo
	P2DScreen* mTest2Screen;       // _0C, test2.blo
	TypingTextMgr* mTypingTextMgr; // _10
	s16 _14;                       // _14
	f32 _18;                       // _18
	P2DPane* mPic1;                // _1C
	P2DPane* mCursorPane;          // _20
	f32 _24;                       // _24
	f32 _28;                       // _28
	s16 _2C;                       // _2C
	s16 _2E;                       // _2E
};

} // namespace zen

#endif
