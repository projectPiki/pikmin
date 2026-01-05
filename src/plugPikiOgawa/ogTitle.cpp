#include "zen/ogTitle.h"

#include "DebugLog.h"
#include "P2D/TextBox.h"
#include "SoundID.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/DrawMenu.h"
#include "zen/ZenController.h"
#include "zen/ogSub.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("OgTitleSection")

/**
 * @todo: Documentation
 * @note UNUSED Size: 000068
 */
void zen::ogScrTitleMgr::getGamePrefs()
{
	mBgmVol = gameflow.mGamePrefs.getBgmVol();
	mSfxVol = gameflow.mGamePrefs.getSfxVol();

	mStereoMode = gameflow.mGamePrefs.getStereoMode();
	mVibeMode   = gameflow.mGamePrefs.getVibeMode();
	mChildMode  = gameflow.mGamePrefs.getChildMode();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080
 */
void zen::ogScrTitleMgr::setGamePrefs()
{
	gameflow.mGamePrefs.setBgmVol(mBgmVol);
	gameflow.mGamePrefs.setSfxVol(mSfxVol);
	gameflow.mGamePrefs.setStereoMode(mStereoMode);
	gameflow.mGamePrefs.setVibeMode(mVibeMode);
	gameflow.mGamePrefs.setChildMode(mChildMode);
}

/**
 * @todo: Documentation
 */
zen::ogScrTitleMgr::ogScrTitleMgr()
{
	mMenuNoChallenge   = new DrawMenu("screen/blo/m_select.blo", false, false);
	mMenuWithChallenge = new DrawMenu("screen/blo/m_selec2.blo", false, false);
	mMainMenu          = mMenuNoChallenge;

	mOptionsMenu  = new DrawMenu("screen/blo/option.blo", false, false);
	mSoundMenu    = new DrawMenu("screen/blo/s_select.blo", false, false);
	mRumbleMenu   = new DrawMenu("screen/blo/v_select.blo", false, false);
	mLanguageMenu = new DrawMenu("screen/blo/ms_selec.blo", false, false);

	mInput = new ZenController(nullptr);
	mInput->setRepeatTime(0.2f);

	static_cast<P2DPicture*>(mMenuNoChallenge->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mMenuWithChallenge->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mOptionsMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mSoundMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mRumbleMenu->getScreenPtr()->search('back', true))->setAlpha(0);
	static_cast<P2DPicture*>(mLanguageMenu->getScreenPtr()->search('back', true))->setAlpha(0);

	mSoundScreen      = mSoundMenu->getScreenPtr();
	mStereoButton     = static_cast<P2DPicture*>(mSoundScreen->search('on21', true));
	mMonoButton       = static_cast<P2DPicture*>(mSoundScreen->search('on22', true));
	mSelectedButton   = static_cast<P2DTextBox*>(mSoundScreen->search('on_c', true));
	mUnselectedButton = static_cast<P2DTextBox*>(mSoundScreen->search('offc', true));

	mAlphaMgr = new setTenmetuAlpha(mStereoButton, 0.5f, 0.0f, 0, 255);

#if defined(VERSION_GPIP01_00)
	char path[4];
#else
	char path[12];
#endif
	for (int i = 0; i < 10; i++) {
		sprintf(path, "on%02d", i + 1);
		u32 test          = RGBA_TO_U32(path[0], path[1], path[2], path[3]);
		mBgmVolButtons[i] = (P2DPicture*)mSoundScreen->search(test, true);
	}
	for (int i = 0; i < 10; i++) {
		sprintf(path, "on%02d", i + 11);
		u32 test          = RGBA_TO_U32(path[0], path[1], path[2], path[3]);
		mSfxVolButtons[i] = (P2DPicture*)mSoundScreen->search(test, true);
	}

	mStatus            = STATUS_Null;
	mPendingExitStatus = mStatus;
	mCurrentSelection  = 0;
	mCurrentMenuID     = MENU_MainMenu;
	getGamePrefs();
	_A4           = 0;
	_A6           = 0;
	mNoInputTimer = 0.0f;
	mStartDelay   = 3;

#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
	mLanguageMenu->setCancelSE(JACSYS_Decide1);
	mRumbleMenu->setCancelSE(JACSYS_Decide1);
	mSoundMenu->setCancelSE(JACSYS_Decide1);
#elif defined(VERSION_GPIP01_00)
	mLanguageMenu->setCancelSE(SYSSE_DECIDE1);
	mRumbleMenu->setCancelSE(SYSSE_DECIDE1);
	mSoundMenu->setCancelSE(SYSSE_DECIDE1);
#else
	mLanguageMenu->setCancelSE(SYSSE_DECIDE1);
	mRumbleMenu->setCancelSE(SYSSE_DECIDE1);
	mSoundMenu->setCancelSE(SYSSE_DECIDE1);
	mOptionsMenu->setMenuItemActiveSw(1, false);
#endif

	StereoOnOff(false);
	DispBarBGM(false);
	DispBarSE(false);
}

/**
 * @todo: Documentation
 */
void zen::ogScrTitleMgr::start(bool hasChallenge)
{
	getGamePrefs();
	if (hasChallenge) {
		mMainMenu = mMenuWithChallenge;
	} else {
		mMainMenu = mMenuNoChallenge;
	}

#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
	SeSystem::playSysSe(SE_PIKI_ATTACK_VOICE);
#else
	SeSystem::playSysSe(YMENU_SELECT2);
#endif

	mMainMenu->start(-1);
	mCurrentMenuID     = MENU_MainMenu;
	_A4                = 0;
	_A6                = 0;
	mNoInputTimer      = 0.0f;
	mPendingExitStatus = STATUS_ExitToStart;
	mStatus            = STATUS_Starting;
	mStartDelay        = 3;
}

/**
 * @todo: Documentation
 */
zen::ogScrTitleMgr::TitleStatus zen::ogScrTitleMgr::update(Controller* input)
{
	STACK_PAD_VAR(8);
	if (mStatus == STATUS_Null) {
		return mStatus;
	}

	if (mStatus == STATUS_Starting) {
		mStartDelay--;
		if (mStartDelay <= 0) {
			mStatus = STATUS_Active;
		}
		return mStatus;
	}

	if (mStatus == STATUS_Exiting) {
		mStatus = mPendingExitStatus;
		return mStatus;
	}

	if (mStatus >= STATUS_ExitToStart) {
		mStatus = STATUS_Null;
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
		mMainMenu->update(input);
	}

	switch (mCurrentMenuID) {
	case MENU_MainMenu:
		mMainMenu->update(input);
		int flag0         = mMainMenu->getStatusFlag();
		mCurrentSelection = mMainMenu->getSelectMenu();
		if (flag0 != 0) {
			break;
		}
		if (mCurrentSelection == 0) {
			// Start
			mPendingExitStatus = STATUS_ExitToStoryMode;
			mStatus            = STATUS_Exiting;
			return mStatus;
		}
		if (mCurrentSelection == 1) {
			// Options
			mCurrentMenuID = MENU_Options;
			mOptionsMenu->start(0);
			break;
		}
		if (mCurrentSelection == 2) {
			// Challenge Mode
			mPendingExitStatus = STATUS_ExitToChallengeMode;
			mStatus            = STATUS_Exiting;
			return mStatus;
		}
		if (mMainMenu->checkSelectMenuCancel()) {
			mPendingExitStatus = STATUS_ExitToStart;
			mStatus            = STATUS_Exiting;
			return mStatus;
		}
		break;

	case MENU_Options:
		mOptionsMenu->update(input);
		int flag1         = mOptionsMenu->getStatusFlag();
		mCurrentSelection = mOptionsMenu->getSelectMenu();
		if (flag1 != 0) {
			break;
		}
		if (mCurrentSelection == 0) {
			// Sound
			mCurrentMenuID = MENU_Sound;
			mSoundMenu->start(0);
			break;
		}
		if (mCurrentSelection == 1) {
			// Language
			mCurrentMenuID = MENU_Language;
#if defined(VERSION_GPIP01_00)
			mLanguageMenu->start(mChildMode);
#else
			if (mChildMode) {
				mLanguageMenu->start(1);
			} else {
				mLanguageMenu->start(0);
			}
#endif
			break;
		}
		if (mCurrentSelection == 2) {
			// Rumble
			mCurrentMenuID = MENU_Rumble;
			if (mVibeMode) {
				mRumbleMenu->start(0);
			} else {
				mRumbleMenu->start(1);
			}
			break;
		}
		if (mCurrentSelection == 3) {
			// High Scores
			mPendingExitStatus = STATUS_ExitToHiScore;
			mStatus            = STATUS_Exiting;
			return mStatus;
		}

		if (mOptionsMenu->checkSelectMenuCancel()) {
#if defined(VERSION_PIKIDEMO)
			STACK_PAD_VAR(2);
#else
			bool vibe   = gameflow.mGamePrefs.getVibeMode();
			bool stereo = gameflow.mGamePrefs.getStereoMode();
#if defined(VERSION_GPIP01_00)
			int child = gameflow.mGamePrefs.getChildMode();
#else
			bool child = gameflow.mGamePrefs.getChildMode();
#endif
			u8 bgmVol = gameflow.mGamePrefs.getBgmVol();
			u8 sfxVol = gameflow.mGamePrefs.getSfxVol();
			if (gameflow.mMemoryCard.getMemoryCardState(true) == 0 && gameflow.mMemoryCard.mSaveFileIndex >= 0) {
				gameflow.mMemoryCard.loadOptions();
			}
			gameflow.mGamePrefs.setVibeMode(vibe);
			gameflow.mGamePrefs.setStereoMode(stereo);
			gameflow.mGamePrefs.setChildMode(child);
			gameflow.mGamePrefs.setBgmVol(bgmVol);
			gameflow.mGamePrefs.setSfxVol(sfxVol);
			gameflow.mGamePrefs.mChangesPending = false;
			gameflow.mMemoryCard.saveOptions();
#endif

			mOptionsMenu->setCancelSelectMenuNo(-1);
			mMainMenu->start(-1);
			mCurrentMenuID = MENU_MainMenu;
		}
		break;

	case MENU_Sound:
		mSoundMenu->update(input);
		int flag2         = mSoundMenu->getStatusFlag();
		mCurrentSelection = mSoundMenu->getSelectMenu();
		if (mInput->keyRepeat(KBBTN_MSTICK_LEFT)) {
			switch (mCurrentSelection) {
			case 0:
				// Stereo/Mono
				if (!mStereoMode) {
					mStereoMode = true;
					setGamePrefs();

					// For every time this sound is played here, it worked correctly in USA demo, then broken in final USA (Jac_PlaySystemSe
					// is meant to use its own sound ids for system sounds), then fixed AGAIN in a different way for PAL
#if defined(BUGFIX) || defined(VERSION_GPIP01_00)
					seSystem->playSysSe(Sound_Config);
#elif defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
					Jac_PlaySystemSe(JACSYS_SoundConfig);
#else
					Jac_PlaySystemSe(Sound_Config);
#endif
				}
				break;

			case 1:
				// Music Volume
				if (mBgmVol > 0) {
					mBgmVol--;
					setGamePrefs();
#if defined(BUGFIX) || defined(VERSION_GPIP01_00)
					seSystem->playSysSe(Sound_Config);
#elif defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
					Jac_PlaySystemSe(JACSYS_SoundConfig);
#else
					Jac_PlaySystemSe(Sound_Config);
#endif
				}
				break;

			case 2:
				// SGX Volume
				if (mSfxVol > 0) {
					mSfxVol--;
					setGamePrefs();
#if defined(BUGFIX) || defined(VERSION_GPIP01_00)
					seSystem->playSysSe(Sound_Config);
#elif defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
					Jac_PlaySystemSe(JACSYS_SoundConfig);
#else
					Jac_PlaySystemSe(Sound_Config);
#endif
				}
				break;
			}
		}
		if (mInput->keyRepeat(KBBTN_MSTICK_RIGHT)) {
			switch (mCurrentSelection) {
			case 0:
				// Stereo/Mono
				if (mStereoMode) {
					mStereoMode = false;
					setGamePrefs();
#if defined(BUGFIX) || defined(VERSION_GPIP01_00)
					seSystem->playSysSe(Sound_Config);
#elif defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
					Jac_PlaySystemSe(JACSYS_SoundConfig);
#else
					Jac_PlaySystemSe(Sound_Config);
#endif
				}
				break;

			case 1:
				// Music Volume
				if (mBgmVol < 10) {
					mBgmVol++;
					setGamePrefs();
#if defined(BUGFIX) || defined(VERSION_GPIP01_00)
					seSystem->playSysSe(Sound_Config);
#elif defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
					Jac_PlaySystemSe(JACSYS_SoundConfig);
#else
					Jac_PlaySystemSe(Sound_Config);
#endif
				}
				break;

			case 2:
				// SFX Volume
				if (mSfxVol < 10) {
					mSfxVol++;
					setGamePrefs();
#if defined(BUGFIX) || defined(VERSION_GPIP01_00)
					seSystem->playSysSe(Sound_Config);
#elif defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
					Jac_PlaySystemSe(JACSYS_SoundConfig);
#else
					Jac_PlaySystemSe(Sound_Config);
#endif
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
			mCurrentMenuID = MENU_Options;
			break;
		}

		if (mSoundMenu->checkSelectMenuCancel()) {
			mSoundMenu->setCancelSelectMenuNo(-1);
			mOptionsMenu->start(-1);
			mCurrentMenuID = MENU_Options;
		}
		break;

	case MENU_Rumble:
		mRumbleMenu->update(input);
		int flag3         = mRumbleMenu->getStatusFlag();
		mCurrentSelection = mRumbleMenu->getSelectMenu();
		if (input->keyClick(KBBTN_MSTICK_UP | KBBTN_MSTICK_DOWN)) {
			if (mCurrentSelection == 0) {
				// ON
				mVibeMode = true;
			} else {
				// OFF
				mVibeMode = false;
			}

			setGamePrefs();
		}

		if (flag3 != 0) {
			break;
		}

		if (mCurrentSelection >= 0) {
			mOptionsMenu->start(-1);
			mCurrentMenuID = MENU_Options;
			break;
		}

		if (mRumbleMenu->checkSelectMenuCancel()) {
			mRumbleMenu->setCancelSelectMenuNo(-1);
			mOptionsMenu->start(-1);
			mCurrentMenuID = MENU_Options;
		}
		break;

	case MENU_Language:
		mLanguageMenu->update(input);
		int flag4         = mLanguageMenu->getStatusFlag();
		mCurrentSelection = mLanguageMenu->getSelectMenu();
#if defined(VERSION_GPIP01_00)
		if (mCurrentSelection >= 0) {
			mChildMode = mCurrentSelection;
		}
		if (flag4) {
			break;
		}
		STACK_PAD_VAR(1);
		setGamePrefs();
#else
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
#endif
		mPendingExitStatus = STATUS_ExitToStart;
		mStatus            = STATUS_Exiting;
		return mStatus;
		break;
	}

	return mStatus;
}

/**
 * @todo: Documentation
 */
void zen::ogScrTitleMgr::draw(Graphics& gfx)
{
	if (mStatus != STATUS_Null && mStatus != STATUS_Starting) {
		switch (mCurrentMenuID) {
		case MENU_MainMenu:
			mMainMenu->draw(gfx);
			break;
		case MENU_Options:
			mOptionsMenu->draw(gfx);
			break;
		case MENU_Sound:
			mSoundMenu->draw(gfx);
			break;
		case MENU_Rumble:
			mRumbleMenu->draw(gfx);
			break;
		case MENU_Language:
			mLanguageMenu->draw(gfx);
			break;
		}
	}
}

/**
 * @todo: Documentation
 */
void zen::ogScrTitleMgr::StereoOnOff(bool isSelected)
{
	if (mStereoMode) {
		setTextColor(mSelectedButton, mStereoButton);
		setTextColor(mUnselectedButton, mMonoButton);
		if (isSelected) {
			mAlphaMgr->update(mStereoButton);
		} else {
			mStereoButton->setAlpha(255);
		}
	} else {
		setTextColor(mUnselectedButton, mStereoButton);
		setTextColor(mSelectedButton, mMonoButton);
		if (isSelected) {
			mAlphaMgr->update(mMonoButton);
		} else {
			mMonoButton->setAlpha(255);
		}
	}
}

/**
 * @todo: Documentation
 */
void zen::ogScrTitleMgr::DispBarBGM(bool isSelected)
{
	for (int i = 0; i < 10; i++) {
		if (i < mBgmVol - 1) {
			setTextColor(mSelectedButton, mBgmVolButtons[i]);
			mBgmVolButtons[i]->setAlpha(255);
		} else if (i == mBgmVol - 1) {
			setTextColor(mSelectedButton, mBgmVolButtons[i]);
			if (isSelected) {
				mAlphaMgr->update(mBgmVolButtons[i]);
			} else {
				mBgmVolButtons[i]->setAlpha(255);
			}
		} else {
			setTextColor(mUnselectedButton, mBgmVolButtons[i]);
		}
	}
}

/**
 * @todo: Documentation
 */
void zen::ogScrTitleMgr::DispBarSE(bool isSelected)
{
	for (int i = 0; i < 10; i++) {
		if (i < mSfxVol - 1) {
			setTextColor(mSelectedButton, mSfxVolButtons[i]);
			mSfxVolButtons[i]->setAlpha(255);
		} else if (i == mSfxVol - 1) {
			setTextColor(mSelectedButton, mSfxVolButtons[i]);
			if (isSelected) {
				mAlphaMgr->update(mSfxVolButtons[i]);
			} else {
				mSfxVolButtons[i]->setAlpha(255);
			}
		} else {
			setTextColor(mUnselectedButton, mSfxVolButtons[i]);
		}
	}
}
