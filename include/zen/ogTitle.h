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
public:
	enum TitleMenuID {
		MENU_MainMenu = 0,
		MENU_Options  = 1,
		MENU_Sound    = 2,
		MENU_Rumble   = 3,
		MENU_Language = 4,

	};

	enum TitleStatus {
		STATUS_Null                = -1,
		STATUS_Active              = 0,
		STATUS_Starting            = 1,
		STATUS_Exiting             = 2,
		STATUS_ExitToStart         = 3,
		STATUS_ExitToStoryMode     = 4,
		STATUS_Unk5                = 5,
		STATUS_ExitToChallengeMode = 6,
		STATUS_ExitToHiScore       = 7,
	};

	ogScrTitleMgr();

	TitleStatus update(Controller*);
	void start(bool);
	void draw(Graphics&);

private:
	void getGamePrefs();
	void setGamePrefs();
	void StereoOnOff(bool);
	void DispBarBGM(bool);
	void DispBarSE(bool);

	TitleStatus mStatus;            // _00
	TitleStatus mPendingExitStatus; // _04
	ZenController* mInput;          // _08
	DrawMenu* mMenuNoChallenge;     // _0C, no challenge mode
	DrawMenu* mMenuWithChallenge;   // _10, with challenge mode
	DrawMenu* mMainMenu;            // _14
	DrawMenu* mOptionsMenu;         // _18
	DrawMenu* mSoundMenu;           // _1C
	DrawMenu* mRumbleMenu;          // _20, need to figure out these two
	DrawMenu* mLanguageMenu;        // _24
	setTenmetuAlpha* mAlphaMgr;     // _28
	P2DScreen* mSoundScreen;        // _2C
	P2DPicture* mStereoButton;      // _30
	P2DPicture* mMonoButton;        // _34
	P2DTextBox* mSelectedButton;    // _38
	P2DTextBox* mUnselectedButton;  // _3C
	P2DPicture* mBgmVolButtons[10]; // _40
	P2DPicture* mSfxVolButtons[10]; // _68
	f32 mNoInputTimer;              // _90
	int mCurrentSelection;          // _94
	s16 mCurrentMenuID;             // _98
	s16 mStartDelay;                // _9A
	bool mStereoMode;               // _9C
	u8 _9D;                         // _9D
	s16 mBgmVol;                    // _9E
	s16 mSfxVol;                    // _A0
	bool mVibeMode;                 // _A2
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
