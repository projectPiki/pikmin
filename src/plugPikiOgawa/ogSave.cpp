#include "zen/ogSave.h"
#include "P2D/Screen.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "P2D/Graph.h"
#include "zen/ogFileChkSel.h"
#include "zen/DrawSave.h"
#include "zen/ogMemChk.h"
#include "zen/ogNitaku.h"
#include "zen/ogSub.h"
#include "jaudio/verysimple.h"
#include "SoundMgr.h"
#include "sysNew.h"
#include "gameflow.h"
#include "DebugLog.h"
#include "VersionGroups.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("OgSaveSection")

/*
 * --INFO--
 * Address:	80195740
 * Size:	00073C
 */
zen::ogSaveMgr::ogSaveMgr()
{
#if defined(VERSION_PIKIDEMO)
#else
	mFileChkSelected = 0;
#endif
	mScreen = new P2DScreen;
	mScreen->set("screen/blo/ac_save.blo", true, true, true);
	mStatus = Inactive;

	mHeader0TextBox          = (P2DTextBox*)mScreen->search('he00', true);
	mHeader1TextBox          = (P2DTextBox*)mScreen->search('he01', true);
	mHeaderSub0              = mScreen->search('hs00', true);
	mHeaderSub1              = mScreen->search('hs01', true);
	mSaveCenterTextBox       = (P2DTextBox*)mScreen->search('se_c', true);
	mBackPicture             = (P2DPicture*)mScreen->search('back', true);
	mSaveActionCenterTextBox = (P2DTextBox*)mScreen->search('sa_c', true);
	mSaveActionSideTextBox   = (P2DTextBox*)mScreen->search('sa_s', true);
	mSaveActionKC            = mScreen->search('sakc', true);
	mSaveActionKS            = mScreen->search('saks', true);

	mHeader0TextBox->show();
	mHeader1TextBox->show();
	mHeaderSub0->show();
	mHeaderSub1->show();
	mBackPicture->setAlpha(0);
	mWindow1 = mScreen->search('1win', true);
	mWindow1->show();
	mWindow1->setOffset(mWindow1->getWidth() / 2, mWindow1->getHeight() / 2);
	mWindow1->setScale(0.0f);

	mPrimaryNikatuMgr = new ogNitakuMgr(mScreen, mHeader0TextBox, mHeader1TextBox, mSaveCenterTextBox, true, true);

	mNoticePane = mScreen->search('chui', true);
	mNoticePane->show();
	mNoticePane->setOffset(mNoticePane->getWidth() / 2, mNoticePane->getHeight() / 2);
	mNoticePane->setScale(0.0f);

	mSaveActionCenterFader = new ogFadeMgr(mSaveActionCenterTextBox, mSaveActionCenterTextBox->getAlpha());
	mSaveActionSideFader   = new ogFadeMgr(mSaveActionSideTextBox, mSaveActionSideTextBox->getAlpha());
	mSaveActionKCFader     = new ogFadeMgr(mSaveActionKC, 255);
	mSaveActionKSFader     = new ogFadeMgr(mSaveActionKS, 255);

	mBlackScreen = new P2DScreen;
	mBlackScreen->set("screen/blo/black.blo", false, false, true);
	mBlackPicture = (P2DPicture*)mBlackScreen->search('blck', true);
	mBlackPicture->setAlpha(255);

	mSecondaryScreen = new P2DScreen;
	mSecondaryScreen->set("screen/blo/ac_save2.blo", true, true, true);
	mSecondaryHeader0TextBox = (P2DTextBox*)mSecondaryScreen->search('he00', true);
	mSecondaryHeader1TextBox = (P2DTextBox*)mSecondaryScreen->search('he01', true);

	mWindow2 = mSecondaryScreen->search('2win', true);
	mWindow2->show();
	mWindow2->setOffset(mWindow2->getWidth() / 2, mWindow2->getHeight() / 2);
	mWindow2->setScale(0.0f);

	mSecondaryBackPicture = (P2DPicture*)mSecondaryScreen->search('back', true);
	mSecondaryBackPicture->setAlpha(0);

	mSecondaryNikatuMgr
	    = new ogNitakuMgr(mSecondaryScreen, mSecondaryHeader0TextBox, mSecondaryHeader1TextBox, mSaveCenterTextBox, true, true);
	PRINT("%%%%%%%%%%%%%%%%%%%%   OGAWA SAVE STEP 1   %%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	mMemCheckMgr = new ogScrMemChkMgr;
	mSaveFail    = new DrawSaveFailure;
	mSaveFail->init();
	mFileChkSelMgr = new ogScrFileChkSelMgr;
	PRINT("%%%%%%%%%%%%%%%%%%%%   OGAWA SAVE STEP 2   %%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	mAnimTimer  = 0.0f;
	mNextStatus = Inactive;
	_UNUSED14   = 0;
}

/*
 * --INFO--
 * Address:	80195E7C
 * Size:	0000C0
 */
void zen::ogSaveMgr::start()
{
	mStatus    = FadeIn;
	mAnimTimer = 0.0f;
	mWindow1->setScale(0.0f);
	mWindow1->show();
	mWindow2->setScale(0.0f);
	mWindow2->show();
	mHeader0TextBox->show();
	mHeader1TextBox->show();
	mHeaderSub0->show();
	mHeaderSub1->show();
	mSaveActionCenterTextBox->hide();
	mSaveActionSideTextBox->hide();
	mBackPicture->setAlpha(0);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
void zen::ogSaveMgr::startDirectSave(s16 state)
{
	start();
	mStatus          = PreparingSave;
	mAnimTimer       = 0.0f;
	mDirectSaveState = state;
	mHeader0TextBox->hide();
	mHeader1TextBox->hide();
	mHeaderSub0->hide();
	mHeaderSub1->hide();
	mSaveActionCenterTextBox->hide();
	mSaveActionSideTextBox->hide();
	mBackPicture->setAlpha(0);
}

/*
 * --INFO--
 * Address:	80195F3C
 * Size:	000834
 */
zen::ogSaveMgr::SaveStatus zen::ogSaveMgr::update(Controller* input)
{
	if (mStatus == Inactive) {
		return mStatus;
	}

	if (mStatus >= ExitFailure) {
		mStatus = Inactive;
		return mStatus;
	}
#if defined(VERSION_PIKIDEMO)
	mFileChkSelected = 1;
#endif

	mBlackScreen->update();
	bool savefail = mSaveFail->update(input);
	if (savefail == false) {
		return mStatus;
	}

	ogScrFileChkSelMgr::returnStatusFlag fileChkSelRes = mFileChkSelMgr->update(input, mFileChkData);
	if (fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_SelectionA || fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_SelectionB
	    || fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_SelectionC) {
		gameflow.mPlayState.mSaveFlags          = mFileChkData.mFlags;
		gameflow.mGamePrefs.mSpareSaveGameIndex = mFileChkData.mIndex + 1;
		mStatus                                 = PreparingSave;
		mAnimTimer                              = 0.0f;
		mFileChkSelected                        = 0;

	} else if (fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_Unk5) {
		mStatus = ExitSuccess;
#if defined(VERSION_PIKIDEMO)
#else
		mFileChkSelected = 0;
#endif
		return mStatus;

	} else if (fileChkSelRes == ogScrFileChkSelMgr::ErrorOrCompleted) {
		mStatus = ExitFailure;
#if defined(VERSION_PIKIDEMO)
#else
		mFileChkSelected = 0;
#endif
		return mStatus;

	} else if (fileChkSelRes != ogScrFileChkSelMgr::Null) {
#if defined(VERSION_PIKIDEMO)
		mFileChkSelected = 0;
#else
		mFileChkSelected = 1;
#endif
		return mStatus;
	}

	zen::ogScrMemChkMgr::MemChkStatus memCheckRes = mMemCheckMgr->update(input);
	if (memCheckRes == ogScrMemChkMgr::Finished) {
		mFileChkSelMgr->startSave();
#if defined(VERSION_PIKIDEMO)
#else
		mFileChkSelected = 1;
#endif
		mStatus    = PreparingSave;
		mAnimTimer = 0.0f;

	} else if (memCheckRes == ogScrMemChkMgr::ExitSuccess) {
		mStatus = ExitSuccess;
		return mStatus;

	} else if (memCheckRes == ogScrMemChkMgr::ExitFailure) {
		mStatus = ExitFailure;
		return mStatus;
	}
#if defined(VERSION_PIKIDEMO)
	else if (memCheckRes == ogScrMemChkMgr::Inactive)
#else
	else if (memCheckRes != ogScrMemChkMgr::Inactive) {
		return mStatus;
	}
#endif
	{
		mAnimTimer += gsys->getFrameTime();
		mScreen->update();
		int nikatu1 = mPrimaryNikatuMgr->update(input);
		mSecondaryScreen->update();
		int nikatu2 = mSecondaryNikatuMgr->update(input);
		mSaveActionCenterFader->update();
		mSaveActionSideFader->update();
		mSaveActionKCFader->update();
		mSaveActionKSFader->update();

		switch (mStatus) {
		case FadeIn:
			if (mAnimTimer > 0.25f) {
				mStatus = MainSelectionActive;
				mWindow1->setScale(1.0f);
				mPrimaryNikatuMgr->start();
				PRINT("SAVE FADEIN END \n");
			} else {
				f32 t = mAnimTimer / 0.25f;
				mWindow1->setScale(t);
				f32 alpha = f32(mSaveCenterTextBox->getAlpha() * t);
				mBackPicture->setAlpha(alpha);
#if defined(VERSION_PIKIDEMO)
#else
				PRINT("SAVE FADEIN alpha = %d\n", (int)alpha);
#endif
			}
			break;

		case PreparingSave:
			if (mAnimTimer > 0.25f) {
				mStatus    = ShowingSaveNotice;
				mAnimTimer = 0.0f;
				mWindow1->setScale(1.0f);
				mSaveActionCenterTextBox->show();
				mSaveActionSideTextBox->show();
				mSaveActionCenterFader->start(ogFadeMgr::STATUS_FadeIn, 0.25f);
				mSaveActionKCFader->start(ogFadeMgr::STATUS_FadeIn, 0.25f);
				PRINT("######################\n");
				PRINT("##\tSAVE to (%d)   ##\n", mDirectSaveState);
				PRINT("######################\n");
			} else {
				f32 t = mAnimTimer / 0.25f;
				mWindow1->setScale(t);
				mBackPicture->setAlpha(mSaveCenterTextBox->getAlpha() * t);
			}
			break;

		case FadeOut:
			if (mAnimTimer > 0.25f) {
				mStatus = mNextStatus;
				mWindow1->setScale(0.0f);
			} else {
				f32 t = 1.0f - mAnimTimer / 0.25f;
				mWindow1->setScale(t);
				mBackPicture->setAlpha(mSaveCenterTextBox->getAlpha() * t);
			}
			break;

		case MainSelectionActive:
			if (nikatu1 == 5) {
				mStatus    = ShowingSaveNotice;
				mAnimTimer = 0.0f;
				mHeader0TextBox->hide();
				mHeader1TextBox->hide();
				mHeaderSub0->hide();
				mHeaderSub1->hide();
				mSaveActionCenterTextBox->show();
				mSaveActionSideTextBox->show();
				mSaveActionCenterFader->start(ogFadeMgr::STATUS_FadeIn, 0.25f);
				mSaveActionKCFader->start(ogFadeMgr::STATUS_FadeIn, 0.25f);

				// why.
				BOOL cardChanged = !gameflow.mMemoryCard.hasCardChanged();
				if (!cardChanged) {
					PRINT("#############################\n");
					PRINT("#      NOT SAME FILE        #\n");
					PRINT("#############################\n");
					mMemCheckMgr->start();
					if (mMemCheckMgr->update(input) == ogScrMemChkMgr::Finished) {
						mFileChkSelMgr->startSave();
						mStatus    = PreparingSave;
						mAnimTimer = 0.0f;
					}
				} else {
					PRINT("#############################\n");
					PRINT("#         SAME FILE         #\n");
					PRINT("#############################\n");
				}
			} else if (nikatu1 == 6) {
				mStatus    = MainWindowFadeOut;
				mAnimTimer = 0.0f;
			} else if (nikatu1 == 4) {
#if defined(VERSION_PIKIDEMO)
				seSystem->playSysSe(JACSYS_Cancel);
#else
				seSystem->playSysSe(SYSSE_CANCEL);
#endif
				mNextStatus = ExitFailure;
				mStatus     = FadeOut;
				mAnimTimer  = 0.0f;
			}
			break;

		case ShowingSaveNotice:
			if (mAnimTimer < 1.0f) {
				f32 scale = 3.0f * mAnimTimer / 1.0f;
				if (scale > 1.0f) {
					scale = 1.0f;
				}
				mNoticePane->setScale(scale);
			} else {
				mStatus    = SavingInProgress;
				mAnimTimer = 0.0f;
#if defined(VERSION_PIKIDEMO)
				seSystem->playSysSe(JACSYS_CardAccess);
#else
				seSystem->playSysSe(SYSSE_CARDACCESS);
#endif
				gameflow.mMemoryCard.saveCurrentGame();
			}
			break;

		case SavingInProgress:
			mNoticePane->setScale(1.0f);
#if defined(VERSION_PIKIDEMO)
			seSystem->playSysSe(JACSYS_CardOK);
#else
			seSystem->playSysSe(SYSSE_CARDOK);
#endif
			if (gameflow.mMemoryCard.didSaveFail()) {
				mSaveFail->open(1.0f);
				mNextStatus = ExitFailure;
				mStatus     = FadeOut;
				mAnimTimer  = 0.0f;
			} else {
				mStatus    = SaveComplete;
				mAnimTimer = 0.0f;
				mSaveActionCenterFader->start(ogFadeMgr::STATUS_FadeOut, 0.25f);
				mSaveActionKCFader->start(ogFadeMgr::STATUS_FadeOut, 0.25f);
				mSaveActionSideFader->start(ogFadeMgr::STATUS_FadeIn, 0.25f);
				mSaveActionKSFader->start(ogFadeMgr::STATUS_FadeIn, 0.25f);
			}
			break;

		case SaveComplete:
			if (mAnimTimer > 1.0f) {
				mNextStatus = SaveCompletedSuccess;
				mStatus     = FadeOut;
				mAnimTimer  = 0.0f;
				mSaveActionSideFader->start(ogFadeMgr::STATUS_FadeOut, 0.25f);
				mSaveActionKSFader->start(ogFadeMgr::STATUS_FadeOut, 0.25f);
			}
			break;

		case MainWindowFadeOut:
			if (mAnimTimer > 0.25f) {
				mWindow1->setScale(0.0f);
				mStatus    = SecondaryWindowFadeIn;
				mAnimTimer = 0.0f;
			} else {
				mWindow1->setScale(1.0f - (mAnimTimer / 0.25f));
			}
			break;

		case SecondaryWindowFadeIn:
			if (mAnimTimer > 0.25f) {
				mStatus = SecondarySelectionActive;
				mWindow2->setScale(1.0f);
				mSecondaryNikatuMgr->start();
			} else {
				mWindow2->setScale((mAnimTimer / 0.25f));
			}
			break;

		case SecondarySelectionActive:
			if (nikatu2 == 5) {
				mNextStatus = ExitSuccess;
				mStatus     = SecondaryWindowFadeOut;
				mAnimTimer  = 0.0f;
			} else if (nikatu2 == 6) {
				mNextStatus = AlternativeExitSuccess;
				mStatus     = SecondaryWindowFadeOut;
				mAnimTimer  = 0.0f;
			} else if (nikatu2 == 4) {
#if defined(VERSION_PIKIDEMO)
				seSystem->playSysSe(JACSYS_Cancel);
#else
				seSystem->playSysSe(SYSSE_CANCEL);
#endif
				mNextStatus = FadeIn;
				mStatus     = SecondaryWindowFadeOut;
				mAnimTimer  = 0.0f;
			}
			break;

		case SecondaryWindowFadeOut:
			if (mAnimTimer > 0.25f) {
				mWindow2->setScale(0.0f);
				mStatus    = mNextStatus;
				mAnimTimer = 0.0f;
			} else {
				mWindow2->setScale(1.0f - (mAnimTimer / 0.25f));
			}
			break;

		case HandleSaveFailure:
			if (!savefail) {
				mNextStatus = ExitFailure;
				mStatus     = FadeOut;
				mAnimTimer  = 0.0f;
			}
			break;
		}

		STACK_PAD_TERNARY(mStatus, 2);
	}

	return mStatus;
}

/*
 * --INFO--
 * Address:	80196770
 * Size:	0000F4
 */
void zen::ogSaveMgr::draw(Graphics& gfx)
{
	if (mStatus == -1) {
		return;
	}

	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();

#if defined(VERSION_PIKIDEMO)
	if (!mFileChkSelected) {
		mBlackScreen->draw(0, 0, &graf);
		mFileChkSelMgr->draw(gfx);
		return;
	}
	mScreen->draw(0, 0, &graf);
	mSecondaryScreen->draw(0, 0, &graf);
	mMemCheckMgr->draw(gfx);
	mSaveFail->draw(gfx);
#else
		if (mFileChkSelected) {
			mBlackScreen->draw(0, 0, &graf);
			mFileChkSelMgr->draw(gfx);
		} else {
			mScreen->draw(0, 0, &graf);
			mSecondaryScreen->draw(0, 0, &graf);
			mMemCheckMgr->draw(gfx);
			mSaveFail->draw(gfx);
		}
#endif
}
