#ifndef _ZEN_OGMESSAGE_H
#define _ZEN_OGMESSAGE_H

#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "VersionGroups.h"
#include "types.h"

struct Controller;
struct Graphics;
struct P2DTextBox;
struct P2DPicture;
struct Font;

namespace zen {
struct ogMsgCtrlTagMgr;
struct setTenmetuAlpha;

struct TextInfoType {
	char* mScreenResourcePath; // _00
	s16 mMsgUniqueId;          // _04
	s16 mMsgSegmentCount;      // _06
};

/**
 * @brief TODO
 *
 * @note Size: 0xA5F0.
 */
struct ogScrMessageMgr {
public:
	/**
	 * @brief Defines the operational states of the message manager.
	 */
	enum MessageStatus {
		STATE_Inactive = -1,        // The manager is idle and not displaying any message.
		STATE_ActiveDisplay,        // Message is fully displayed and active, awaiting user interaction.
		STATE_StartDelay,           // An initial delay period before the message begins to fade in.
		STATE_FadingIn,             // Message is currently fading into view. Alpha is progressively increased.
		STATE_FadingOut,            // Message is currently fading out of view. Alpha is progressively decreased.
		STATE_TransitionToInactive, // A transitional state before the manager becomes fully inactive, follows STATE_FadingOut
	};

	ogScrMessageMgr(char*);

	void resetPage();
	void start(int);
	void setPage(int);
	void nextPage();
	void backPage();
	void MakeAndSetPageInfo(char***);
	void dispAll();
	void fadeOut();
	MessageStatus update(Controller*);
	void draw(Graphics&);

	// unused/inlined:
	void ReadAllScreen();
	void setScreenAlpha(u8);

	// DLL inlines
	TextInfoType* getPageInfo() { return mPageInfos[mCurrPageNum]; }
	s16 getTxtLineMax() { return mActivePaneCount; }
	P2DScreen* getBaseScreenPtr() { return mBaseScreen; }
	P2DScreen* getScreenPtr() { return mCurrentScreen; }

	void setLastPageAbutton(bool set) { mIsUiInputDisabled = set; }
	void setSolidMode(bool set) { mAlwaysShowNextPrompt = set; }

	void setCursorXY(P2DTextBox* textBox)
	{
		mCursorTargetX = textBox->getPosH() + textBox->getCursorX();
		mCursorTargetY = textBox->getPosV() + textBox->getCursorY() - 24;
	}
	void setScale(f32 scale)
	{
		mBaseScreen->setScale(scale);
		mCurrentScreen->setScale(scale);
	}

	bool checkDisp() { return mHasDrawOccurredThisFrame; }

	void move(int x, int y)
	{
		mBaseScreen->move(x, y);
		mCurrentScreen->move(x, y);
	}

private:
	s16 SearchTopPage(int);
	void setMessagePage(int);
	s16 makePageInfo(char***);
	void cnvSingleMulti(char*);
	void cnvButtonIcon(char*);
	void setPageInfoSub();

	P2DScreen* mBaseScreen;                   // _00
	ogMsgCtrlTagMgr* mCtrlTagMgr;             // _04
	Font* mFont;                              // _08
	P2DPicture* mCursorPane;                  // _0C
	P2DPicture* mButtonPromptPane;            // _10
	setTenmetuAlpha* mCursorBlinker;          // _14
	setTenmetuAlpha* mButtonPromptBlinker;    // _18
	TextInfoType* mPageInfos[300];            // _1C, unsure of array size, make it less if necessary
	MessageStatus mState;                     // _4CC
	s16 mCurrPageNum;                         // _4D0
	f32 mTextAnimationProgress;               // _4D4
	f32 mScreenFadeTimer;                     // _4D8
	bool mIsPageFullyRevealed;                // _4DC
	bool mIsTextPausedByTag;                  // _4DD
	bool mIsUiInputDisabled;                  // _4DE
	bool mHasDrawOccurredThisFrame;           // _4DF
	bool mAlwaysShowNextPrompt;               // _4E0
	s16 mStateEntryDelay;                     // _4E2
	s16 mCursorTargetX;                       // _4E4
	s16 mCursorTargetY;                       // _4E6
	s16 mCurrentTextCharOffset;               // _4E8
	s16 mNextPaneId;                          // _4EA
	s16 mActivePaneId;                        // _4EC
	s16 mCurrentMessageId;                    // _4EE
	s16 mPageInfoEntryCount;                  // _4F0
	char mFormattedDisplayStrings[20][0x400]; // _4F2
	s16 mPageDrawDelayTimer;                  // _54F2
	bool mIsInitialPageLoad;                  // _54F4
	P2DScreen* mCurrentScreen;                // _54F8
	P2DPane* mPagePaneList[20];               // _54FC
#if defined(VERSION_PIKIDEMO)
#else
	char mRawPageTextBoxStrings[20][0x400]; // _554C
#endif
	char* mProcessedTextBoxStrings[20]; // _A54C
	s16 mActivePaneCount;               // _A59C
#if defined(VERSION_PIKIDEMO)
#else
	char mButtonTagChars[12];         // _A59E
	char mButtonTagIconStrings[34];   // _A5AA, unknown size
	char* mDefaultButtonMarkupColour; // _A5CC
	char* mButtonMarkupColours[8];    // _A5D0
#endif
};

} // namespace zen

#endif
