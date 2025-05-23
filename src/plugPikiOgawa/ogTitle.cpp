#include "zen/ogTitle.h"
#include "zen/DrawMenu.h"
#include "gameflow.h"
#include "zen/ZenController.h"
#include "zen/ogSub.h"
#include "SoundID.h"
#include "sysNew.h"
#include "P2D/TextBox.h"
#include "SoundMgr.h"
#include "jaudio/verysimple.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("OgTitleSection")

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void zen::ogScrTitleMgr::getGamePrefs()
{
	mBgmVol = gameflow.mGamePrefs.getBgmVol();
	mSfxVol = gameflow.mGamePrefs.getSfxVol();

	mStereoMode = gameflow.mGamePrefs.getStereoMode();
	mVibeMode   = gameflow.mGamePrefs.getVibeMode();
	mChildMode  = gameflow.mGamePrefs.getChildMode();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrTitleMgr::setGamePrefs()
{
	gameflow.mGamePrefs.setBgmVol(mBgmVol);
	gameflow.mGamePrefs.setSfxVol(mSfxVol);
	gameflow.mGamePrefs.setStereoMode(mStereoMode);
	gameflow.mGamePrefs.setVibeMode(mVibeMode);
	gameflow.mGamePrefs.setChildMode(mChildMode);
}

/*
 * --INFO--
 * Address:	80181090
 * Size:	0004A8
 */
zen::ogScrTitleMgr::ogScrTitleMgr()
{
	mMenu1   = new DrawMenu("screen/blo/m_select.blo", false, false);
	mMenu2   = new DrawMenu("screen/blo/m_selec2.blo", false, false);
	mUseMenu = mMenu1;

	mOptionsMenu     = new DrawMenu("screen/blo/option.blo", false, false);
	mSoundSelectMenu = new DrawMenu("screen/blo/s_select.blo", false, false);
	mVSelectMenu     = new DrawMenu("screen/blo/v_select.blo", false, false);
	mMsSelectMenu    = new DrawMenu("screen/blo/ms_selec.blo", false, false);

	mInput = new ZenController(nullptr);
	mInput->setRepeatTime(0.2f);

	static_cast<P2DPicture*>(mMenu1->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mMenu2->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mOptionsMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mSoundSelectMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mVSelectMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mMsSelectMenu->getScreenPtr()->search('back', true))->setAlpha(0);

	mSoundSelectScreen = mSoundSelectMenu->getScreenPtr();
	_30                = static_cast<P2DPicture*>(mSoundSelectScreen->search('on21', true));
	_34                = static_cast<P2DPicture*>(mSoundSelectScreen->search('on22', true));
	_38                = static_cast<P2DTextBox*>(mSoundSelectScreen->search('on_c', true));
	_3C                = static_cast<P2DTextBox*>(mSoundSelectScreen->search('offc', true));

	mAlphaMgr = new setTenmetuAlpha(_30, 0.5f, 0.0f, 0, 255);

	char path[12];
	for (int i = 0; i < 10; i++) {
		sprintf(path, "on%02d", i + 1);
		u32 test        = RGBA_TO_U32(path[0], path[1], path[2], path[3]);
		mBgmVolPanes[i] = (P2DPicture*)mSoundSelectScreen->search(test, true);
	}
	for (int i = 0; i < 10; i++) {
		sprintf(path, "on%02d", i + 11);
		u32 test        = RGBA_TO_U32(path[0], path[1], path[2], path[3]);
		mSfxVolPanes[i] = (P2DPicture*)mSoundSelectScreen->search(test, true);
	}

	mStatus           = Status_Null;
	_04               = mStatus;
	mCurrentSelection = 0;
	mCurrentMenu      = 0;
	getGamePrefs();
	_A4           = 0;
	_A6           = 0;
	mNoInputTimer = 0.0f;
	_9A           = 3;

	mMsSelectMenu->setCancelSE(SYSSE_DECIDE1);
	mVSelectMenu->setCancelSE(SYSSE_DECIDE1);
	mSoundSelectMenu->setCancelSE(SYSSE_DECIDE1);

	mOptionsMenu->setMenuItemActiveSw(1, false);
	StereoOnOff(false);
	DispBarBGM(false);
	DispBarSE(false);
}

/*
 * --INFO--
 * Address:	80181538
 * Size:	0000E4
 */
void zen::ogScrTitleMgr::start(bool hasChallenge)
{
	getGamePrefs();
	if (hasChallenge) {
		mUseMenu = mMenu2;
	} else {
		mUseMenu = mMenu1;
	}
	SeSystem::playSysSe(YMENU_SELECT2);
	mUseMenu->start(-1);
	mCurrentMenu  = 0;
	_A4           = 0;
	_A6           = 0;
	mNoInputTimer = 0.0f;
	_04           = Status_3;
	mStatus       = Status_1;
	_9A           = 3;
}

/*
 * --INFO--
 * Address:	8018161C
 * Size:	0009F8
 */
zen::ogScrTitleMgr::TitleStatus zen::ogScrTitleMgr::update(Controller* input)
{
	u32 badCompiler[8];
	if (mStatus == -1) {
		return mStatus;
	}

	if (mStatus == 1) {
		_9A--;
		if (_9A <= 0) {
			mStatus = Status_0;
		}
		return mStatus;
	}

	if (mStatus == 2) {
		mStatus = _04;
		return mStatus;
	}

	if (mStatus >= 3) {
		mStatus = Status_Null;
		return mStatus;
	}

	mInput->setContPtr(input);
	mInput->update();
	if (input->keyDown(KBBTN_ANY)) {
		mNoInputTimer = 0.0f;
	}

	mNoInputTimer += gsys->getFrameTime();
	if (mNoInputTimer >= 60.0f) {
		input->updateCont(KBBTN_B);
		mUseMenu->update(input);
	}

	switch (mCurrentMenu) {
	case 0:
		mUseMenu->update(input);
		int flag0         = mUseMenu->getStatusFlag();
		mCurrentSelection = mUseMenu->getSelectMenu();
		if (flag0 != 0) {
			break;
		}
		if (mCurrentSelection == 0) {
			_04     = Status_4;
			mStatus = Status_2;
			return mStatus;
		}
		if (mCurrentSelection == 1) {
			mCurrentMenu = 1;
			mOptionsMenu->start(0);
			break;
		}
		if (mCurrentSelection == 2) {
			_04     = Status_6;
			mStatus = Status_2;
			return mStatus;
		}
		if (mUseMenu->checkSelectMenuCancel()) {
			_04     = Status_3;
			mStatus = Status_2;
			return mStatus;
		}
		break;
	case 1:
		mOptionsMenu->update(input);
		int flag1         = mOptionsMenu->getStatusFlag();
		mCurrentSelection = mOptionsMenu->getSelectMenu();
		if (flag1 != 0) {
			break;
		}
		if (mCurrentSelection == 0) {
			mCurrentMenu = 2;
			mSoundSelectMenu->start(0);
			break;
		}
		if (mCurrentSelection == 1) {
			mCurrentMenu = 4;
			if (mChildMode) {
				mMsSelectMenu->start(1);
			} else {
				mMsSelectMenu->start(0);
			}
			break;
		}
		if (mCurrentSelection == 2) {
			mCurrentMenu = 3;
			if (mVibeMode) {
				mVSelectMenu->start(0);
			} else {
				mVSelectMenu->start(1);
			}
			break;
		}
		if (mCurrentSelection == 3) {
			_04     = Status_7;
			mStatus = Status_2;
			return mStatus;
		}
		if (mOptionsMenu->checkSelectMenuCancel()) {
			bool vibe   = gameflow.mGamePrefs.getVibeMode();
			bool stereo = gameflow.mGamePrefs.getStereoMode();
			bool child  = gameflow.mGamePrefs.getChildMode();
			u8 bgmVol   = gameflow.mGamePrefs.getBgmVol();
			u8 sfxVol   = gameflow.mGamePrefs.getSfxVol();
			if (gameflow.mMemoryCard.getMemoryCardState(true) == 0 && gameflow.mMemoryCard.mSaveFileIndex >= 0) {
				gameflow.mMemoryCard.loadOptions();
			}
			gameflow.mGamePrefs.setVibeMode(vibe);
			gameflow.mGamePrefs.setStereoMode(stereo);
			gameflow.mGamePrefs.setChildMode(child);
			gameflow.mGamePrefs.setBgmVol(bgmVol);
			gameflow.mGamePrefs.setSfxVol(sfxVol);
			gameflow.mGamePrefs.mIsChanged = false;
			gameflow.mMemoryCard.saveOptions();

			mOptionsMenu->setCancelSelectMenuNo(-1);
			mUseMenu->start(-1);
			mCurrentMenu = 0;
		}
		break;
	case 2:
		mSoundSelectMenu->update(input);
		int flag2         = mSoundSelectMenu->getStatusFlag();
		mCurrentSelection = mSoundSelectMenu->getSelectMenu();
		if (mInput->keyRepeat(KBBTN_MSTICK_LEFT)) {
			switch (mCurrentSelection) {
			case 0:
				if (!mStereoMode) {
					mStereoMode = true;
					setGamePrefs();
					Jac_PlaySystemSe(Sound_Config);
				}
				break;

			case 1:
				if (mBgmVol > 0) {
					mBgmVol--;
					setGamePrefs();
					Jac_PlaySystemSe(Sound_Config);
				}
				break;

			case 2:
				if (mSfxVol > 0) {
					mSfxVol--;
					setGamePrefs();
					Jac_PlaySystemSe(Sound_Config);
				}
				break;
			}
		}
		if (mInput->keyRepeat(KBBTN_MSTICK_RIGHT)) {
			switch (mCurrentSelection) {
			case 0:
				if (mStereoMode) {
					mStereoMode = false;
					setGamePrefs();
					Jac_PlaySystemSe(Sound_Config);
				}
				break;

			case 1:
				if (mBgmVol < 10) {
					mBgmVol++;
					setGamePrefs();
					Jac_PlaySystemSe(Sound_Config);
				}
				break;

			case 2:
				if (mSfxVol < 10) {
					mSfxVol++;
					setGamePrefs();
					Jac_PlaySystemSe(Sound_Config);
				}
				break;
			}
		}

		StereoOnOff(mCurrentSelection == 0);
		DispBarBGM(mCurrentSelection == 1);
		DispBarSE(mCurrentSelection == 2);

		if (flag2 != 0) {
			break;
		}

		if (mCurrentSelection >= 0) {
			mOptionsMenu->start(-1);
			mCurrentMenu = 1;
			break;
		}

		if (mSoundSelectMenu->checkSelectMenuCancel()) {
			mSoundSelectMenu->setCancelSelectMenuNo(-1);
			mOptionsMenu->start(-1);
			mCurrentMenu = 1;
		}
		break;

	case 3:
		mVSelectMenu->update(input);
		int flag3         = mVSelectMenu->getStatusFlag();
		mCurrentSelection = mVSelectMenu->getSelectMenu();
		if (input->keyClick(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN)) {
			if (mCurrentSelection == 0) {
				mVibeMode = true;
			} else {
				mVibeMode = false;
			}

			setGamePrefs();
		}

		if (flag3 != 0) {
			break;
		}

		if (mCurrentSelection >= 0) {
			mOptionsMenu->start(-1);
			mCurrentMenu = 1;
			break;
		}

		if (mVSelectMenu->checkSelectMenuCancel()) {
			mVSelectMenu->setCancelSelectMenuNo(-1);
			mOptionsMenu->start(-1);
			mCurrentMenu = 1;
		}
		break;

	case 4:
		mMsSelectMenu->update(input);
		int flag4         = mMsSelectMenu->getStatusFlag();
		mCurrentSelection = mMsSelectMenu->getSelectMenu();
		if (input->keyClick(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN)) {
			if (mCurrentSelection == 0) {
				mChildMode = false;
			} else {
				mChildMode = true;
			}
			setGamePrefs();
		}

		if (flag4) {
			break;
		}
		_04     = Status_3;
		mStatus = Status_2;
		return mStatus;
		break;
	}

	return mStatus;
}

/*
 * --INFO--
 * Address:	80182014
 * Size:	000098
 */
void zen::ogScrTitleMgr::draw(Graphics& gfx)
{
	if (mStatus != Status_Null && mStatus != Status_1) {
		switch (mCurrentMenu) {
		case 0:
			mUseMenu->draw(gfx);
			break;
		case 1:
			mOptionsMenu->draw(gfx);
			break;
		case 2:
			mSoundSelectMenu->draw(gfx);
			break;
		case 3:
			mVSelectMenu->draw(gfx);
			break;
		case 4:
			mMsSelectMenu->draw(gfx);
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	801820AC
 * Size:	0000C4
 */
void zen::ogScrTitleMgr::StereoOnOff(bool set)
{
	if (mStereoMode) {
		setTextColor(_38, _30);
		setTextColor(_3C, _34);
		if (set) {
			mAlphaMgr->update(_30);
		} else {
			_30->setAlpha(255);
		}
	} else {
		setTextColor(_3C, _30);
		setTextColor(_38, _34);
		if (set) {
			mAlphaMgr->update(_34);
		} else {
			_34->setAlpha(255);
		}
	}
}

/*
 * --INFO--
 * Address:	80182170
 * Size:	0000D4
 */
void zen::ogScrTitleMgr::DispBarBGM(bool set)
{
	for (int i = 0; i < 10; i++) {
		if (i < mBgmVol - 1) {
			setTextColor(_38, mBgmVolPanes[i]);
			mBgmVolPanes[i]->setAlpha(255);
		} else if (i == mBgmVol - 1) {
			setTextColor(_38, mBgmVolPanes[i]);
			if (set) {
				mAlphaMgr->update(mBgmVolPanes[i]);
			} else {
				mBgmVolPanes[i]->setAlpha(255);
			}
		} else {
			setTextColor(_3C, mBgmVolPanes[i]);
		}
	}
}

/*
 * --INFO--
 * Address:	80182244
 * Size:	0000D4
 */
void zen::ogScrTitleMgr::DispBarSE(bool set)
{
	for (int i = 0; i < 10; i++) {
		if (i < mSfxVol - 1) {
			setTextColor(_38, mSfxVolPanes[i]);
			mSfxVolPanes[i]->setAlpha(255);
		} else if (i == mSfxVol - 1) {
			setTextColor(_38, mSfxVolPanes[i]);
			if (set) {
				mAlphaMgr->update(mSfxVolPanes[i]);
			} else {
				mSfxVolPanes[i]->setAlpha(255);
			}
		} else {
			setTextColor(_3C, mSfxVolPanes[i]);
		}
	}
}
