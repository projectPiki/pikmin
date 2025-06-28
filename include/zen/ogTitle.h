#ifndef _ZEN_OGTITLE_H
#define _ZEN_OGTITLE_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DScreen;
struct P2DPane;
struct P2DPicture;
struct P2DTextBox;

namespace zen {

struct DrawMenu;
struct ZenController;
struct setTenmetuAlpha;

/**
 * @note Size: 0xA8.
 */
struct ogScrTitleMgr {
	enum TitleStatus {
		Status_Null = -1,
		Status_0    = 0,
		Status_1    = 1,
		Status_2    = 2,
		Status_3    = 3,
		Status_4    = 4,
		Status_5    = 5,
		Status_6    = 6,
		Status_7    = 7,
	};

	ogScrTitleMgr();

	void start(bool);
	TitleStatus update(Controller*);
	void draw(Graphics&);
	void StereoOnOff(bool);
	void DispBarBGM(bool);
	void DispBarSE(bool);

	// unused/inlined:
	void getGamePrefs();
	void setGamePrefs();

	TitleStatus mStatus;           // _00
	TitleStatus _04;               // _04
	ZenController* mInput;         // _08
	DrawMenu* mMenu1;              // _0C, no challenge mode
	DrawMenu* mMenu2;              // _10, with challenge mode
	DrawMenu* mUseMenu;            // _14
	DrawMenu* mOptionsMenu;        // _18
	DrawMenu* mSoundSelectMenu;    // _1C
	DrawMenu* mVSelectMenu;        // _20, need to figure out these two
	DrawMenu* mMsSelectMenu;       // _24
	setTenmetuAlpha* mAlphaMgr;    // _28
	P2DScreen* mSoundSelectScreen; // _2C
	P2DPicture* _30;               // _30
	P2DPicture* _34;               // _34
	P2DTextBox* _38;               // _38
	P2DTextBox* _3C;               // _3C
	P2DPicture* mBgmVolPanes[10];  // _40
	P2DPicture* mSfxVolPanes[10];  // _68
	f32 mNoInputTimer;             // _90
	int mCurrentSelection;         // _94
	s16 mCurrentMenu;              // _98
	s16 _9A;                       // _9A
	bool mStereoMode;              // _9C
	u8 _9D;                        // _9D
	s16 mBgmVol;                   // _9E
	s16 mSfxVol;                   // _A0
	bool mVibeMode;                // _A2
#if defined(VERSION_GPIP01_00)
	int mChildMode; // _A4
#else
	bool mChildMode; // _A3
#endif
	u8 _A4;  // _A4
	u8 _A5;  // _A5
	u16 _A6; // _A6
};

} // namespace zen

#endif
