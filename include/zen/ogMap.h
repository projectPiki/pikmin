#ifndef _ZEN_OGMAP_H
#define _ZEN_OGMAP_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DPane;
struct P2DTextBox;
struct P2DScreen;
struct P2DPicture;

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
	P2DScreen* mCurrentScreen;     // _04
	P2DScreen* mTestScreen;        // _08, test.blo
	P2DScreen* mTest2Screen;       // _0C, test2.blo
	TypingTextMgr* mTypingTextMgr; // _10
	s16 mMode;                     // _14
	f32 mFrameTimer;               // _18
	P2DPane* mPic1;                // _1C
	P2DPicture* mCursorPane;       // _20
	f32 mPic1PositionX;            // _24
	f32 mPic1PositionY;            // _28
	s16 mScreenPosX;               // _2C
	s16 mScreenPosY;               // _2E
};

} // namespace zen

#endif
