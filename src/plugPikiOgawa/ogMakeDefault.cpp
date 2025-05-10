#include "zen/ogMakeDefault.h"
#include "zen/ogSub.h"
#include "P2D/Screen.h"
#include "P2D/Picture.h"
#include "P2D/Graph.h"
#include "sysNew.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
// DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	8019399C
 * Size:	000360
 */
zen::ogScrMakeDefaultMgr::ogScrMakeDefaultMgr()
{
	mScreen = new P2DScreen;
	mScreen->set("screen/blo/data_pf.blo", true, true, true);
	mScreen2 = new P2DScreen;
	mScreen2->set("screen/blo/black.blo", false, false, true);

	mBlackScreenOverlay = (P2DPicture*)mScreen2->search('blck', true);
	mBlackScreenOverlay->setAlpha(255);
	mAButtonPromptPicture       = (P2DPicture*)mScreen->search('abtn', true);
	mAButtonPromptAlphaAnimator = new setTenmetuAlpha(mAButtonPromptPicture, 1.0f);
	mAButtonPromptPicture->hide();

	mDefaultMessageTextBox   = (P2DTextBox*)mScreen->search('tx00', true);
	mDefaultMessageTypingMgr = new TypingTextMgr(mDefaultMessageTextBox);
	mActiveTypingTextMgr     = mDefaultMessageTypingMgr;

	mAdditionalTextPane1 = mScreen->search('tx01', true);
	mAdditionalTextPane2 = mScreen->search('tx02', true);
	mAdditionalTextPane3 = mScreen->search('tx03', true);

	mCursorPicture       = (P2DPicture*)mScreen->search('curs', true);
	mCursorAlphaAnimator = new setTenmetuAlpha(mCursorPicture, 0.5f);

	mOkMessageTextBox   = (P2DTextBox*)mScreen->search('pfok', true);
	mOkMessageTypingMgr = new TypingTextMgr(mOkMessageTextBox);

	mFailMessageTextBox   = (P2DTextBox*)mScreen->search('pfxx', true);
	mFailMessageTypingMgr = new TypingTextMgr(mFailMessageTextBox);

	mStateTimer = 0.0f;
	mStatus     = Status_Inactive;
}

/*
 * --INFO--
 * Address:	80193CFC
 * Size:	0000EC
 */
void zen::ogScrMakeDefaultMgr::start()
{
	mStatus     = Status_Initialising;
	mStateTimer = 0.0f;
	mAButtonPromptPicture->hide();
	mAdditionalTextPane1->hide();
	mAdditionalTextPane2->hide();
	mAdditionalTextPane3->hide();
	mCursorAlphaAnimator->start();
	mActiveTypingTextMgr->off();
	mActiveTypingTextMgr = mDefaultMessageTypingMgr;
	mActiveTypingTextMgr->start();
	mActiveTypingTextMgr->transCursor(mCursorPicture);
}

/*
 * --INFO--
 * Address:	80193DE8
 * Size:	000354
 */
zen::ogScrMakeDefaultMgr::MakeDefaultStatus zen::ogScrMakeDefaultMgr::update(Controller* input)
{
	if (mStatus == Status_Inactive) {
		return mStatus;
	}

	if (mStatus >= 4) {
		mStatus = Status_Inactive;
		return mStatus;
	}

	mStateTimer += gsys->getFrameTime();

	if (mStateTimer > 1.0f) {
		mAdditionalTextPane1->show();
	}
	if (mStateTimer > 2.0f) {
		mAdditionalTextPane2->show();
	}
	if (mStateTimer > 3.0f) {
		mAdditionalTextPane3->show();
	}
	mScreen->update();
	mScreen2->update();
	mCursorAlphaAnimator->update();
	mAButtonPromptAlphaAnimator->update();
	mActiveTypingTextMgr->update();
	mActiveTypingTextMgr->transCursor(mCursorPicture);

	if (mStatus == Status_Initialising) {
		if (mStateTimer < 0.5f) {
			mBlackScreenOverlay->setAlpha(255 - (int)((mStateTimer * 255.0f) / 0.5f));
		} else {
			mStatus     = Status_Processing;
			mStateTimer = 0.0f;
			gameflow.mMemoryCard.makeDefaultFile();
			mBlackScreenOverlay->setAlpha(0);
		}
		return mStatus;
	} else if (mStatus == Status_Exiting) {
		if (mStateTimer < 0.5f) {
			mBlackScreenOverlay->setAlpha((mStateTimer * 255.0f) / 0.5f);
		} else {
			mBlackScreenOverlay->setAlpha(255);
			mStatus     = mNextStatus;
			mStateTimer = 0.0f;
		}
		return mStatus;
	}

	switch (mStatus) {
	case Status_Processing:
		if (mStateTimer > 2.0f && gameflow.mMemoryCard.hasCardFinished()) {
			BOOL save = !gameflow.mMemoryCard.didSaveFail();
			if (save) {
				mActiveTypingTextMgr->off();
				mActiveTypingTextMgr = mOkMessageTypingMgr;
				mActiveTypingTextMgr->start();
				mNextStatus = Status_Success;
			} else {
				mActiveTypingTextMgr->off();
				mActiveTypingTextMgr = mFailMessageTypingMgr;
				mActiveTypingTextMgr->start();
				mNextStatus = Status_Failure;
			}
			mDefaultMessageTextBox->hide();
			mStatus     = Status_AwaitingConfirmation;
			mStateTimer = 0.0f;
			mAButtonPromptAlphaAnimator->start();
		}
		break;

	case Status_AwaitingConfirmation:
		if (checkTypingAll()) {
			mAButtonPromptPicture->show();
			if (input->keyClick(KBBTN_A)) {
				seSystem->playSysSe(SYSSE_DECIDE1);
				mStatus     = Status_Exiting;
				mStateTimer = 0.0f;
			}
		}
		break;
	}
	return mStatus;
}

/*
 * --INFO--
 * Address:	8019413C
 * Size:	0000A8
 */
void zen::ogScrMakeDefaultMgr::draw(Graphics& gfx)
{
	if (mStatus != Status_Inactive && mStatus < Status_Success) {
		P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
		graf.setPort();
		mScreen->draw(0, 0, &graf);
		mScreen2->draw(0, 0, &graf);
	}
}

/*
 * --INFO--
 * Address:	801941E4
 * Size:	000020
 */
bool zen::ogScrMakeDefaultMgr::checkTypingAll()
{
	if (mActiveTypingTextMgr->check() == 2) {
		return true;
	}
	return false;
}
