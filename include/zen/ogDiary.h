#ifndef _ZEN_OGDIARY_H
#define _ZEN_OGDIARY_H

#include "GlobalGameOptions.h"
#include "types.h"
#include "zen/SpectrumCursorMgr.h"
#include "zen/ogMessage.h"

struct Controller;
struct Graphics;
struct P2DTextBox;
struct P2DPane;
struct P2DScreen;
struct P2DPicture;
struct Font;

namespace zen {

struct ZenController;
struct EffectMgr2D;
struct setTenmetuAlpha;
struct ogDrawDiary;
struct ogDrawSelectDiary;

/**
 * @brief Manages the diary screen, handling message display and page navigation.
 */
struct ogScrDiaryMgr {

	/**
	 * @brief Status of the main diary screen manager.
	 */
	enum DiaryStatus {
		Inactive = -1, // Manager is not active or initialized
		Active   = 0,  // Manager is actively updating the current diary page
	};

	ogScrDiaryMgr();

	DiaryStatus update(Controller* pController);
	void draw(Graphics& gfx);
	void start(s16 startScreenIndex, s16 day);
	void typePage();
	bool nextPage();
	void backPage();
	void exit();

	// unused/inlined:
	void setDiarySpecialNumber(s16 day);
	void setCursorXY(P2DTextBox* pTextBox);
	void updateDiary(Controller* pController);

	void setScale(f32 scale) { mMesgMgr->setScale(scale); }
	ogScrMessageMgr* getScrMsgMgr() { return mMesgMgr; }

	DiaryStatus mStatus;                     // _00
	ogScrMessageMgr* mMesgMgr;               // _04
	int mMessageMgrPosX;                     // _08
	int mMessageMgrPosY;                     // _0C
	ZenController* mController;              // _10
	Font* mFont;                             // _14
	P2DPane* mPaneCapu;                      // _18
	ogDrawDiary* mDiaryInstance;             // _1C
	ogDrawSelectDiary* mSelectDiaryInstance; // _20
	u8 _UNUSED24;                            // _24
};

/**
 * @brief Controls the visual presentation and animation of a single diary entry.
 */
struct ogDrawDiary {

	/**
	 * @brief Animation and interaction state for the diary display.
	 */
	enum DiaryStatus {
		Closed  = 0, // Diary is closed or has finished closing animation
		Opening = 1, // Diary is animating to an open state (scaling up)
		Active  = 2, // Diary is fully open and awaiting user input
		Closing = 3, // Diary is animating to a closed state (scaling down)
	};

	ogDrawDiary();

	void open(f32 screenCenterX, f32 screenCenterY, s16 day);
	DiaryStatus update(Controller* pController);

	// unused/inlined:
	void start();
	void setOffset();
	void draw(Graphics& gfx);

	ogScrDiaryMgr* mDiaryMgr; // _00
	EffectMgr2D* mEfxMgr;     // _04
	DiaryStatus mStatus;      // _08
	f32 mScreenScale;         // _0C
	P2DScreen* mScreen;       // _10
	f32 mScreenCenterX;       // _14
	f32 mScreenCenterY;       // _18
	f32 mOpeningOriginX;      // _1C
	f32 mOpeningOriginY;      // _20
};

/**
 * @brief Manages the interface for selecting a specific diary entry to view.
 *
 * @note Size: 0x2F0.
 */
struct ogDrawSelectDiary {

	/**
	 * @brief State of the diary selection screen.
	 */
	enum SelectDiaryStatus {
		Inactive           = -1, // Selection screen is not active
		Active             = 0,  // Screen is active, handling cursor and day choice
		FadingIn           = 1,  // Screen is performing a fade-in transition
		FadingOut          = 2,  // Screen is performing a fade-out transition
		ViewingSingleDiary = 3,  // Control is with individual diary view (ogDrawDiary)
		Exited             = 4,  // Screen has completed fade-out and is ready to be inactive
	};

	ogDrawSelectDiary();

	void start();
	void setCursorAlpha();
	bool MoveCursor();
	SelectDiaryStatus update(Controller* pController);
	void draw(Graphics& gfx);

	int getOpenX() { return mOpenTargetPane->getPosH() + mOpenTargetPane->getWidth() / 2; }
	int getOpenY() { return mOpenTargetPane->getPosV() + mOpenTargetPane->getHeight() / 2; }

	SelectDiaryStatus mStatus;                  // _00
	P2DScreen* mScreen;                         // _04
	SpectrumCursorMgr mLeftCursorMgr;           // _08
	SpectrumCursorMgr mRightCursorMgr;          // _38
	P2DPane* mDayIconUpPanes[MAX_DAYS];         // _68
	P2DPane* mDayIconDownPanes[MAX_DAYS];       // _E0
	P2DPane* _UNUSED168[MAX_DAYS];              // _168
	P2DPane* mDayDisplayPanes[MAX_DAYS];        // _1D0
	P2DPicture* _248[MAX_DAYS];                 // _248, no idea what this is
	P2DPane* mOpenTargetPane;                   // _2C0
	P2DScreen* mBlackFadeScreen;                // _2C4
	P2DPicture* mBlackFadePicture;              // _2C8
	P2DPicture* mAButtonIcon;                   // _2CC
	setTenmetuAlpha* mAButtonAlphaAnimator;     // _2D0
	ogDrawDiary* mDiaryInstance;                // _2D4
	zen::ogDrawDiary::DiaryStatus mDiaryStatus; // _2D8
	ZenController* mController;                 // _2DC
	s16 mSelectedColumnIndex;                   // _2E0
	s16 mSelectedRowIndex;                      // _2E2
	s16 mSelectionIndex;                        // _2E4
	u16 _UNUSED2E6;                             // _2E6
	s16 mCurrentDay;                            // _2E8
	f32 mTransitionTimer;                       // _2EC
};

} // namespace zen

#endif
