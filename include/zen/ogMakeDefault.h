#ifndef _ZEN_OGMAKEDEFAULT_H
#define _ZEN_OGMAKEDEFAULT_H

#include "types.h"

struct Controller;
struct Graphics;
struct P2DScreen;
struct P2DPane;
struct P2DPicture;
struct P2DTextBox;

namespace zen {

struct setTenmetuAlpha;
struct TypingTextMgr;

/**
 * @brief TODO
 */
struct ogScrMakeDefaultMgr {
public:
	/**
	 * @brief Defines the states for the "make default save file" screen manager.
	 */
	enum MakeDefaultStatus {
		Inactive = -1,        // Screen is not active, or the 'make default file' process has fully completed.
		Processing,           // 'Make default file' operation is in progress; waiting for memory card, initial message is displayed.
		AwaitingConfirmation, // Operation result (success or failure) is displayed; waiting for user (A button) to confirm.
		Initialising,         // Fading in the UI and initiating the 'make default file' operation on the memory card.
		Exiting,              // Fading out the UI after user confirmation before Success or Failure.
		Success,              // 'Make default file' operation completed successfully. The screen will then become Inactive.
		Failure,              // 'Make default file' operation failed. The screen will then become Inactive.
	};

	ogScrMakeDefaultMgr();

	void start();
	MakeDefaultStatus update(Controller*);
	void draw(Graphics&);

private:
	bool checkTypingAll();

	MakeDefaultStatus mStatus;                    // _00
	MakeDefaultStatus mNextStatus;                // _04
	P2DScreen* mScreen;                           // _08
	P2DScreen* mBlackScreen;                      // _0C
	P2DPicture* mBlackScreenOverlay;              // _10
	int _14;                                      // _14
	P2DPicture* mCursorPicture;                   // _18
	P2DPicture* mAButtonPromptPicture;            // _1C
	setTenmetuAlpha* mCursorAlphaAnimator;        // _20
	setTenmetuAlpha* mAButtonPromptAlphaAnimator; // _24
	TypingTextMgr* mActiveTypingTextMgr;          // _28
	P2DTextBox* mOkMessageTextBox;                // _2C
	TypingTextMgr* mOkMessageTypingMgr;           // _30
	P2DTextBox* mFailMessageTextBox;              // _34
	TypingTextMgr* mFailMessageTypingMgr;         // _38
	P2DTextBox* mDefaultMessageTextBox;           // _3C
	TypingTextMgr* mDefaultMessageTypingMgr;      // _40
	P2DPane* mOneSecondDelayPane;                 // _44
	P2DPane* mTwoSecondDelayPane;                 // _48
	P2DPane* mThreeSecondDelayPane;               // _4C
	f32 mStateTimer;                              // _50
};

} // namespace zen

#endif
