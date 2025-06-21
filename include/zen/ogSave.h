#ifndef _ZEN_OGSAVE_H
#define _ZEN_OGSAVE_H

#include "types.h"
#include "MemoryCard.h"

struct Controller;
struct Graphics;
struct P2DPane;
struct P2DTextBox;
struct P2DPicture;
struct P2DScreen;

namespace zen {

struct ogScrFileChkSelMgr;
struct DrawSaveFailure;
struct ogScrMemChkMgr;
struct ogNitakuMgr;
struct ogFadeMgr;

/**
 * @brief TODO
 */
struct ogSaveMgr {
	/**
	 * @brief Save manager state machine status values
	 */
	enum SaveStatus {
		Inactive                 = -1, // Initial/inactive state
		MainSelectionActive      = 0,  // Main selection screen active
		FadeIn                   = 1,  // Fade in animation
		FadeOut                  = 2,  // Fade out animation
		PreparingSave            = 3,  // Preparing to save
		ShowingSaveNotice        = 4,  // Showing save notice
		SavingInProgress         = 5,  // Saving in progress
		SaveComplete             = 6,  // Save complete
		MainWindowFadeOut        = 7,  // Transitioning out of main window
		SecondaryWindowFadeIn    = 8,  // Transitioning into secondary window
		SecondarySelectionActive = 9,  // Secondary selection screen active
		SecondaryWindowFadeOut   = 10, // Transitioning out of secondary window
		HandleSaveFailure        = 11, // Save failure handling
		ExitFailure              = 12, // Exit with failure
		ExitSuccess              = 13, // Exit with success
		SaveCompletedSuccess     = 14, // Save completed successfully
		AlternativeExitSuccess   = 15, // Alternative success exit
	};

	ogSaveMgr();

	void start();
	SaveStatus update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void startDirectSave(s16);

	bool isFileMode() { return mFileChkSelected; }

	SaveStatus mStatus;                   // _00
	SaveStatus mNextStatus;               // _04
	P2DScreen* mScreen;                   // _08
	P2DScreen* mSecondaryScreen;          // _0C
	f32 mAnimTimer;                       // _10
	u16 _UNUSED14;                        // _14, unused
	ogNitakuMgr* mPrimaryNikatuMgr;       // _18
	ogNitakuMgr* mSecondaryNikatuMgr;     // _1C
	ogScrMemChkMgr* mMemCheckMgr;         // _20
	P2DScreen* mBlackScreen;              // _24
	P2DPicture* mBlackPicture;            // _28
	DrawSaveFailure* mSaveFail;           // _2C
	u8 mFileChkSelected;                  // _30
	u16 mDirectSaveState;                 // _32
	P2DTextBox* mHeader0TextBox;          // _34
	P2DTextBox* mHeader1TextBox;          // _38
	P2DPane* mHeaderSub0;                 // _3C
	P2DPane* mHeaderSub1;                 // _40
	P2DTextBox* mSecondaryHeader0TextBox; // _44
	P2DTextBox* mSecondaryHeader1TextBox; // _48
	P2DTextBox* mSaveCenterTextBox;       // _4C
	P2DTextBox* mSaveActionCenterTextBox; // _50
	P2DTextBox* mSaveActionSideTextBox;   // _54
	P2DPane* mSaveActionKC;               // _58
	P2DPane* mSaveActionKS;               // _5C
	ogFadeMgr* mSaveActionCenterFader;    // _60
	ogFadeMgr* mSaveActionSideFader;      // _64
	ogFadeMgr* mSaveActionKCFader;        // _68
	ogFadeMgr* mSaveActionKSFader;        // _6C
	P2DPicture* mBackPicture;             // _70
	P2DPicture* mSecondaryBackPicture;    // _74
	P2DPane* mWindow1;                    // _78
	P2DPane* mWindow2;                    // _7C
	P2DPane* mNoticePane;                 // _80
	ogScrFileChkSelMgr* mFileChkSelMgr;   // _84
	CardQuickInfo mFileChkData;           // _88
};

} // namespace zen

#endif
