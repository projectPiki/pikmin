#include "zen/ogPause.h"
#include "DebugLog.h"
#include "P2D/Graph.h"
#include "P2D/Picture.h"
#include "P2D/Screen.h"
#include "P2D/TextBox.h"
#include "PlayerState.h"
#include "sysNew.h"
#include "zen/DrawMenu.h"

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
DEFINE_PRINT("OgPauseSection")

/*
 * --INFO--
 * Address:	80182318
 * Size:	000324
 */
zen::ogScrPauseMgr::ogScrPauseMgr()
{
	mMode        = 0;
	mBlackScreen = new P2DScreen();
	mBlackScreen->set("screen/blo/black.blo", false, false, true);
	// this might be P2DTextBox instead, unsure
	mBlackPane = static_cast<P2DPicture*>(mBlackScreen->search('blck', true));
	mBlackPane->setAlpha(0);

#if defined(VERSION_PIKIDEMO)
	mDrawMenu1 = new DrawMenu("screen/blo/ot_pause.blo", false, false);
#else
	mDrawMenu1 = new DrawMenu("screen/blo/pause.blo", false, false);
#endif
	_14       = mDrawMenu1->getScreenPtr();
	mTextBox4 = static_cast<P2DTextBox*>(_14->search('yame', true));
	mTextBox5 = static_cast<P2DTextBox*>(_14->search('he02', true));
	mTextBox6 = static_cast<P2DTextBox*>(_14->search('hm02', true));

	_3C = mTextBox4->getString();
	_40 = mTextBox5->getString();

	mTextBox4->hide();

#if defined(VERSION_PIKIDEMO)
	mDrawMenu2 = new DrawMenu("screen/blo/ot_pa_ok.blo", false, false);
#else
	mDrawMenu2 = new DrawMenu("screen/blo/pause_ok.blo", false, false);
#endif
	_18       = mDrawMenu2->getScreenPtr();
	mTextBox1 = static_cast<P2DTextBox*>(_18->search('yame', true));
	mTextBox2 = static_cast<P2DTextBox*>(_18->search('titl', true));
	mTextBox3 = static_cast<P2DTextBox*>(_18->search('even', true));

	mTextBox1->hide();
	mTextBox2->hide();
	mTextBox3->hide();

	mState = PAUSE_NULL;
	_00    = false;

	// this might be P2DTextBox instead, unsure
	mBackPane1 = static_cast<P2DPicture*>(_14->search('back', true));
	mBackPane1->setAlpha(0);
	mBackPane1->hide();

	// this might be P2DTextBox instead, unsure
	mBackPane2 = static_cast<P2DPicture*>(_18->search('back', true));
	mBackPane2->setAlpha(0);
	mBackPane2->hide();
}

/*
 * --INFO--
 * Address:	8018263C
 * Size:	00008C
 */
void zen::ogScrPauseMgr::start(bool p1)
{
	mMode = p1;

	if (mMode != 0) {
		mTextBox5->setString(_3C);
		mTextBox6->setString(_3C);
	} else {
		mTextBox5->setString(_40);
		mTextBox6->setString(_40);
	}

	mDrawMenu1->start(-1);
	mState      = PAUSE_Unk1;
	mFrameTimer = 0.0f;
	_00         = true;
}

/*
 * --INFO--
 * Address:	801826C8
 * Size:	0003C0
 */
zen::ogScrPauseMgr::PauseStatus zen::ogScrPauseMgr::update(Controller* controller)
{
	if (mState == PAUSE_NULL) {
		return mState;
	}

	if (mState >= PAUSE_Unk5) {
		mState = PAUSE_NULL;
		return mState;
	}

	if (playerState->getCurrDay() == 0 || playerState->getCurrDay() == playerState->getTotalDays() - 1) {
		mDrawMenu1->setMenuItemActiveSw(1, false);
	} else {
		mDrawMenu1->setMenuItemActiveSw(1, true);
	}

	mBlackScreen->update();
	mDrawMenu1->update(controller);
	mDrawMenu2->update(controller);
	mFrameTimer += gsys->getFrameTime();

	switch (mState) {
	case PAUSE_Unk1:
		if (mFrameTimer < 0.5f) {
			_54 = 128.0f * mFrameTimer / 0.5f;
			mBlackPane->setAlpha(_54);
		} else {
			mBlackPane->setAlpha(128);
			mState = PAUSE_Unk0;
		}
		break;

	case PAUSE_Unk2:
		if (mFrameTimer < 0.5f) {
			_54 = 128.0f * mFrameTimer / 0.5f;
			mBlackPane->setAlpha(128 - _54);
		} else {
			mBlackPane->setAlpha(0);
			mState = mState2;
			_00    = false;
		}
		break;

	case PAUSE_Unk0:
		DrawMenu::StatusFlag status = mDrawMenu1->getStatusFlag();
		int selectMenu              = mDrawMenu1->getSelectMenu();

		if (status != DrawMenu::STATUS_Unk0) {
			break;
		}

		if (selectMenu <= 0) {
			mState2     = PAUSE_Unk5;
			mState      = PAUSE_Unk2;
			mFrameTimer = 0.0f;
			break;
		}
		if (selectMenu == 1) {
			mState = PAUSE_Unk3;
			mDrawMenu2->start(0);
			mTextBox1->hide();
			mTextBox2->hide();
			mTextBox3->show();
			break;
		}
		if (selectMenu == 2) {
			mState = PAUSE_Unk4;
			mDrawMenu2->start(0);
			mTextBox1->hide();
			mTextBox2->hide();
			mTextBox3->hide();
			if (mMode) {
				mTextBox1->show();
			} else {
				mTextBox2->show();
			}
			break;
		}
		break;
	case PAUSE_Unk3:
	case PAUSE_Unk4:
		int status2     = mDrawMenu2->getStatusFlag();
		int selectMenu2 = mDrawMenu2->getSelectMenu();
		if (status2 == DrawMenu::STATUS_Unk0) {
			if (selectMenu2 == 0) {
				switch (mState) {
				case PAUSE_Unk3:
					mState2 = PAUSE_Unk6;
					break;
				case PAUSE_Unk4:
					mState2 = PAUSE_Unk7;
					break;
				}

				mState      = PAUSE_Unk2;
				mFrameTimer = 0.0f;
				break;
			}

			if (mDrawMenu2->checkSelectMenuCancel() || selectMenu2 == 1) {
				mDrawMenu2->setCancelSelectMenuNo(-1);
				mDrawMenu1->start(-1);
				mState = PAUSE_Unk0;
			}
		}
		break;
	}

	STACK_PAD_VAR(1);
	return mState;
}

/*
 * --INFO--
 * Address:	80182A88
 * Size:	0000B0
 */
void zen::ogScrPauseMgr::draw(Graphics& gfx)
{
	if (mState == PAUSE_NULL) {
		return;
	}

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();
	mBlackScreen->draw(0, 0, &perspGraph);
	mDrawMenu1->draw(gfx);
	mDrawMenu2->draw(gfx);
}
