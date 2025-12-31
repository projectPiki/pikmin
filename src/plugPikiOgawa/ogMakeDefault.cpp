#include "zen/ogMakeDefault.h"
#include "DebugLog.h"
#include "P2D/Graph.h"
#include "P2D/Screen.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/ogSub.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT(nullptr)

/**
 * @todo: Documentation
 */
zen::ogScrMakeDefaultMgr::ogScrMakeDefaultMgr()
{
	mScreen = new P2DScreen;
	mScreen->set("screen/blo/data_pf.blo", true, true, true);

	mBlackScreen = new P2DScreen;
	mBlackScreen->set("screen/blo/black.blo", false, false, true);
	mBlackScreenOverlay = (P2DPicture*)mBlackScreen->search('blck', true);
	mBlackScreenOverlay->setAlpha(255);

	mAButtonPromptPicture       = (P2DPicture*)mScreen->search('abtn', true);
	mAButtonPromptAlphaAnimator = new setTenmetuAlpha(mAButtonPromptPicture, 1.0f);
	mAButtonPromptPicture->hide();

	mDefaultMessageTextBox   = (P2DTextBox*)mScreen->search('tx00', true);
	mDefaultMessageTypingMgr = new TypingTextMgr(mDefaultMessageTextBox);
	mActiveTypingTextMgr     = mDefaultMessageTypingMgr;

	mOneSecondDelayPane   = mScreen->search('tx01', true);
	mTwoSecondDelayPane   = mScreen->search('tx02', true);
	mThreeSecondDelayPane = mScreen->search('tx03', true);

	mCursorPicture       = (P2DPicture*)mScreen->search('curs', true);
	mCursorAlphaAnimator = new setTenmetuAlpha(mCursorPicture, 0.5f);

	mOkMessageTextBox   = (P2DTextBox*)mScreen->search('pfok', true);
	mOkMessageTypingMgr = new TypingTextMgr(mOkMessageTextBox);

	mFailMessageTextBox   = (P2DTextBox*)mScreen->search('pfxx', true);
	mFailMessageTypingMgr = new TypingTextMgr(mFailMessageTextBox);

	mStateTimer = 0.0f;
	mStatus     = Inactive;
}

/**
 * @todo: Documentation
 */
void zen::ogScrMakeDefaultMgr::start()
{
	mStatus     = Initialising;
	mStateTimer = 0.0f;
	mAButtonPromptPicture->hide();
	mOneSecondDelayPane->hide();
	mTwoSecondDelayPane->hide();
	mThreeSecondDelayPane->hide();
	mCursorAlphaAnimator->start();
	mActiveTypingTextMgr->off();
	mActiveTypingTextMgr = mDefaultMessageTypingMgr;
	mActiveTypingTextMgr->start();
	mActiveTypingTextMgr->transCursor(mCursorPicture);
}

/**
 * @todo: Documentation
 */
zen::ogScrMakeDefaultMgr::MakeDefaultStatus zen::ogScrMakeDefaultMgr::update(Controller* input)
{
	if (mStatus == Inactive) {
		return mStatus;
	}

	// If the state is success or failure (exit condition), reset to inactivity
	if (mStatus >= Success) {
		mStatus = Inactive;
		return mStatus;
	}

	mStateTimer += gsys->getFrameTime();

	if (mStateTimer > 1.0f) {
		mOneSecondDelayPane->show();
	}

	if (mStateTimer > 2.0f) {
		mTwoSecondDelayPane->show();
	}

	if (mStateTimer > 3.0f) {
		mThreeSecondDelayPane->show();
	}

	mScreen->update();
	mBlackScreen->update();
	mCursorAlphaAnimator->update();
	mAButtonPromptAlphaAnimator->update();
	mActiveTypingTextMgr->update();
	mActiveTypingTextMgr->transCursor(mCursorPicture);

	if (mStatus == Initialising) {
		if (mStateTimer < 0.5f) {
			mBlackScreenOverlay->setAlpha(255 - (int)((mStateTimer * 255.0f) / 0.5f));
		} else {
			mStatus     = Processing;
			mStateTimer = 0.0f;
			gameflow.mMemoryCard.makeDefaultFile();
			mBlackScreenOverlay->setAlpha(0);
		}

		return mStatus;
	} else if (mStatus == Exiting) {
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
	case Processing:
#if defined(VERSION_GPIP01_00)
		if (mStateTimer > 6.0f && gameflow.mMemoryCard.hasCardFinished()) {
#else
		if (mStateTimer > 2.0f && gameflow.mMemoryCard.hasCardFinished()) {
#endif
			bool success = !gameflow.mMemoryCard.didSaveFail();

			if (success) {
				mActiveTypingTextMgr->off();
				mActiveTypingTextMgr = mOkMessageTypingMgr;
				mActiveTypingTextMgr->start();
				mNextStatus = Success;
			} else {
				mActiveTypingTextMgr->off();
				mActiveTypingTextMgr = mFailMessageTypingMgr;
				mActiveTypingTextMgr->start();
				mNextStatus = Failure;
			}

			mDefaultMessageTextBox->hide();
			mStatus     = AwaitingConfirmation;
			mStateTimer = 0.0f;
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
			mAButtonPromptPicture->show();
#endif
			mAButtonPromptAlphaAnimator->start();
		}
		break;

	case AwaitingConfirmation:
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
		if (input->keyClick(KBBTN_A)) {
			seSystem->playSysSe(JACSYS_Decide1);
			mStatus     = Exiting;
			mStateTimer = 0.0f;
		}
#else
		if (checkTypingAll()) {
			mAButtonPromptPicture->show();
			if (input->keyClick(KBBTN_A)) {
				seSystem->playSysSe(SYSSE_DECIDE1);
				mStatus     = Exiting;
				mStateTimer = 0.0f;
			}
		}
#endif
		break;
	}

	return mStatus;
}

/**
 * @todo: Documentation
 */
void zen::ogScrMakeDefaultMgr::draw(Graphics& gfx)
{
	if (mStatus != Inactive && mStatus < Success) {
		P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
		graf.setPort();
		mScreen->draw(0, 0, &graf);
		mBlackScreen->draw(0, 0, &graf);
	}
}

/**
 * @todo: Documentation
 */
bool zen::ogScrMakeDefaultMgr::checkTypingAll()
{
	return mActiveTypingTextMgr->check() == TypingTextMgr::STATE_Complete ? true : false;
}
