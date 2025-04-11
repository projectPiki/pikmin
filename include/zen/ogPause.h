#ifndef _ZEN_OGPAUSE_H
#define _ZEN_OGPAUSE_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DPane;
struct P2DTextBox;
struct P2DScreen;
struct P2DPicture;

namespace zen {

struct DrawMenu;
/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct ogScrPauseMgr {

	/**
	 * @brief TODO
	 */
	enum PauseStatus {
		PAUSE_NULL = -1,
		PAUSE_Unk0 = 0,
		PAUSE_Unk1 = 1,
		PAUSE_Unk2 = 2,
		PAUSE_Unk3 = 3,
		PAUSE_Unk4 = 4,
		PAUSE_Unk5 = 5,
		PAUSE_Unk6 = 6,
		PAUSE_Unk7 = 7,
	};

	ogScrPauseMgr();

	void start(bool);
	PauseStatus update(Controller*);
	void draw(Graphics&);

	u8 _00;                  // _00, unknown
	PauseStatus mState;      // _04
	PauseStatus mState2;     // _08
	DrawMenu* mDrawMenu1;    // _0c
	DrawMenu* mDrawMenu2;    // _10
	P2DScreen* _14;          // _14
	P2DScreen* _18;          // _18
	P2DScreen* mBlackScreen; // _1c, black.blo
	P2DPicture* mBlackPane;  // _20
	P2DTextBox* mTextBox1;   // _24
	P2DTextBox* mTextBox2;   // _28
	P2DTextBox* mTextBox3;   // _2c
	P2DTextBox* mTextBox4;   // _30
	P2DTextBox* mTextBox5;   // _34
	P2DTextBox* mTextBox6;   // _38
	char* _3C;               // _3c, unknown
	char* _40;               // _40, unknown
	bool mMode;              // _44
	P2DPicture* mBackPane1;  // _48
	P2DPicture* mBackPane2;  // _4c
	f32 mFrameTimer;         // _50
	u8 _54;                  // _54, unknown
};

} // namespace zen

#endif
