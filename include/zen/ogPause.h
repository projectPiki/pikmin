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
		PAUSE_NULL            = -1,
		PAUSE_Active          = 0,
		PAUSE_FadeIn          = 1,
		PAUSE_FadeOut         = 2,
		PAUSE_SunsetSubmenu   = 3,
		PAUSE_QuitGameSubmenu = 4,
		PAUSE_ExitToGameplay  = 5,
		PAUSE_ExitToSunset    = 6,
		PAUSE_ExitToTitle     = 7,

		PAUSE_EXIT_CODE = PAUSE_ExitToGameplay,
	};

	ogScrPauseMgr();

	void start(bool isChallengeMode);
	PauseStatus update(Controller* controller);
	void draw(Graphics& gfx);

	bool mIsActive;                        // _00, unknown
	PauseStatus mState;                    // _04
	PauseStatus mPendingExitState;         // _08
	DrawMenu* mMainMenu;                   // _0c
	DrawMenu* mSubMenu;                    // _10
	P2DScreen* mMainMenuScreen;            // _14
	P2DScreen* mSubMenuScreen;             // _18
	P2DScreen* mParentScreen;              // _1c, black.blo
	P2DPicture* mGameplayFilterPic;        // _20, creates filter over gameplay using a half-opaque big black screen
	P2DTextBox* mQuitChalModeSubTextBox;   // _24
	P2DTextBox* mContLastSaveSubTextBox;   // _28
	P2DTextBox* mGoToSunsetSubTextBox;     // _2c
	P2DTextBox* mQuitChalModeMainTextBox;  // _30
	P2DTextBox* mContLastSaveMainTextBox1; // _34
	P2DTextBox* mContLastSaveMainTextBox2; // _38
	char* mChalModeQuitText;               // _3c, unknown
	char* mStoryModeQuitText;              // _40, unknown
	bool mIsChallengeMode;                 // _44
	P2DPicture* mMainMenuBackFrame;        // _48
	P2DPicture* mSubMenuBackFrame;         // _4c
	f32 mFrameTimer;                       // _50
	u8 mFadeAlpha;                         // _54, unknown
};

} // namespace zen

#endif
