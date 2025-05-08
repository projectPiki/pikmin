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
#include "SoundMgr.h"
#include "sysNew.h"
#include "gameflow.h"
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
DEFINE_PRINT("OgSaveSection")

/*
 * --INFO--
 * Address:	80195740
 * Size:	00073C
 */
zen::ogSaveMgr::ogSaveMgr()
{
	_30     = 0;
	mScreen = new P2DScreen;
	mScreen->set("screen/blo/ac_save.blo", true, true, true);
	mStatus = Status_NULL;

	_34 = (P2DTextBox*)mScreen->search('he00', true);
	_38 = (P2DTextBox*)mScreen->search('he01', true);
	_3C = mScreen->search('hs00', true);
	_40 = mScreen->search('hs01', true);
	_4C = (P2DTextBox*)mScreen->search('se_c', true);
	_70 = (P2DPicture*)mScreen->search('back', true);
	_50 = (P2DTextBox*)mScreen->search('sa_c', true);
	_54 = (P2DTextBox*)mScreen->search('sa_s', true);
	_58 = mScreen->search('sakc', true);
	_5C = mScreen->search('saks', true);

	_34->show();
	_38->show();
	_3C->show();
	_40->show();
	_70->setAlpha(0);
	_78 = mScreen->search('1win', true);
	_78->show();
	_78->setOffset(_78->getWidth() / 2, _78->getHeight() / 2);
	_78->setScale(0.0f);

	_18 = new ogNitakuMgr(mScreen, _34, _38, _4C, true, true);

	_80 = mScreen->search('chui', true);
	_80->show();
	_80->setOffset(_80->getWidth() / 2, _80->getHeight() / 2);
	_80->setScale(0.0f);

	_60 = new ogFadeMgr(_50, _50->getAlpha());
	_64 = new ogFadeMgr(_54, _54->getAlpha());
	_68 = new ogFadeMgr(_58, 255);
	_6C = new ogFadeMgr(_5C, 255);

	_24 = new P2DScreen;
	_24->set("screen/blo/black.blo", false, false, true);
	_28 = (P2DPicture*)_24->search('blck', true);
	_28->setAlpha(255);

	_0C = new P2DScreen;
	_0C->set("screen/blo/ac_save2.blo", true, true, true);
	_44 = (P2DTextBox*)_0C->search('he00', true);
	_48 = (P2DTextBox*)_0C->search('he01', true);

	_7C = _0C->search('2win', true);
	_7C->show();
	_7C->setOffset(_7C->getWidth() / 2, _7C->getHeight() / 2);
	_7C->setScale(0.0f);

	_74 = (P2DPicture*)_0C->search('back', true);
	_74->setAlpha(0);

	_1C = new ogNitakuMgr(_0C, _44, _48, _4C, true, true);
	PRINT("%%%%%%%%%%%%%%%%%%%%   OGAWA SAVE STEP 1   %%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	mMemCheckMgr = new ogScrMemChkMgr;
	mSaveFail    = new DrawSaveFailure;
	mSaveFail->init();
	_84 = new ogScrFileChkSelMgr;
	PRINT("%%%%%%%%%%%%%%%%%%%%   OGAWA SAVE STEP 2   %%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	_10 = 0.0f;
	_04 = Status_NULL;
	_14 = 0;
}

/*
 * --INFO--
 * Address:	80195E7C
 * Size:	0000C0
 */
void zen::ogSaveMgr::start()
{
	mStatus = Status_1;
	_10     = 0.0f;
	_78->setScale(0.0f);
	_78->show();
	_7C->setScale(0.0f);
	_7C->show();
	_34->show();
	_38->show();
	_3C->show();
	_40->show();
	_50->hide();
	_54->hide();
	_70->setAlpha(0);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
void zen::ogSaveMgr::startDirectSave(s16 state)
{
	start();
	mStatus = Status_3;
	_10     = 0.0f;
	_32     = state;
	_34->hide();
	_38->hide();
	_3C->hide();
	_40->hide();
	_50->hide();
	_54->hide();
	_70->setAlpha(0);
}

/*
 * --INFO--
 * Address:	80195F3C
 * Size:	000834
 */
zen::ogSaveMgr::SaveStatus zen::ogSaveMgr::update(Controller* input)
{
	if (mStatus == Status_NULL) {
		return mStatus;
	}

	if (mStatus >= Status_12) {
		mStatus = Status_NULL;
		return mStatus;
	}

	_24->update();
	bool savefail = mSaveFail->update(input);
	if (savefail == false) {
		return mStatus;
	}

	ogScrFileChkSelMgr::returnStatusFlag fileChkSelRes = _84->update(input, _88);
	if (fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_Unk2 || fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_Unk3
	    || fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_Unk4) {
		gameflow.mPlayState._23             = _88._04;
		gameflow.mGamePrefs.mSpareSaveGames = _88.mIndex + 1;
		mStatus                             = Status_3;
		_10                                 = 0.0f;
		_30                                 = 0;

	} else if (fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_Unk5) {
		mStatus = Status_13;
		_30     = 0;
		return mStatus;

	} else if (fileChkSelRes == ogScrFileChkSelMgr::FILECHKSEL_Unk1) {
		mStatus = Status_12;
		_30     = 0;
		return mStatus;

	} else if (fileChkSelRes != ogScrFileChkSelMgr::FILECHKSEL_NULL) {
		_30 = 1;
		return mStatus;
	}

	zen::ogScrMemChkMgr::MemChkStatus memCheckRes = mMemCheckMgr->update(input);
	if (memCheckRes == 21) {
		_84->startSave();
		_30     = 1;
		mStatus = Status_3;
		_10     = 0.0f;
	} else if (memCheckRes == 20) {
		mStatus = Status_13;
		return mStatus;

	} else if (memCheckRes == 19) {
		mStatus = Status_12;
		return mStatus;

	} else if (memCheckRes != -1) {
		return mStatus;
	}

	_10 += gsys->getFrameTime();
	mScreen->update();
	int nikatu1 = _18->update(input);
	_0C->update();
	int nikatu2 = _1C->update(input);
	_60->update();
	_64->update();
	_68->update();
	_6C->update();

	switch (mStatus) {
	case Status_1:
		if (_10 > 0.25f) {
			mStatus = Status_0;
			_78->setScale(1.0f);
			_18->start();
			PRINT("SAVE FADEIN END \n");
		} else {
			f32 t = _10 / 0.25f;
			_78->setScale(t);
			f32 alpha = f32(_4C->getAlpha() * t);
			_70->setAlpha(alpha);
			PRINT("SAVE FADEIN alpha = %d\n", (int)alpha);
		}
		break;

	case Status_3:
		if (_10 > 0.25f) {
			mStatus = Status_4;
			_10     = 0.0f;
			_78->setScale(1.0f);
			_50->show();
			_54->show();
			_60->start(ogFadeMgr::Status_1, 0.25f);
			_68->start(ogFadeMgr::Status_1, 0.25f);
			PRINT("######################\n");
			PRINT("##\tSAVE to (%d)   ##\n", _32);
			PRINT("######################\n");
		} else {
			f32 t = _10 / 0.25f;
			_78->setScale(t);
			_70->setAlpha(_4C->getAlpha() * t);
		}
		break;

	case Status_2:
		if (_10 > 0.25f) {
			mStatus = _04;
			_78->setScale(0.0f);
		} else {
			f32 t = 1.0f - _10 / 0.25f;
			_78->setScale(t);
			_70->setAlpha(_4C->getAlpha() * t);
		}
		break;

	case Status_0:
		if (nikatu1 == 5) {
			mStatus = Status_4;
			_10     = 0.0f;
			_34->hide();
			_38->hide();
			_3C->hide();
			_40->hide();
			_50->show();
			_54->show();
			_60->start(ogFadeMgr::Status_1, 0.25f);
			_68->start(ogFadeMgr::Status_1, 0.25f);

			// why.
			BOOL cardChanged = !gameflow.mMemoryCard.hasCardChanged();
			if (!cardChanged) {
				PRINT("#############################\n");
				PRINT("#      NOT SAME FILE        #\n");
				PRINT("#############################\n");
				mMemCheckMgr->start();
				if (mMemCheckMgr->update(input) == 21) {
					_84->startSave();
					mStatus = Status_3;
					_10     = 0.0f;
				}
			} else {
				PRINT("#############################\n");
				PRINT("#         SAME FILE         #\n");
				PRINT("#############################\n");
			}
		} else if (nikatu1 == 6) {
			mStatus = Status_7;
			_10     = 0.0f;
		} else if (nikatu1 == 4) {
			seSystem->playSysSe(SYSSE_CANCEL);
			_04     = Status_12;
			mStatus = Status_2;
			_10     = 0.0f;
		}
		break;

	case Status_4:
		if (_10 < 1.0f) {
			f32 scale = 3.0f * _10 / 1.0f;
			if (scale > 1.0f) {
				scale = 1.0f;
			}
			_80->setScale(scale);
		} else {
			mStatus = Status_5;
			_10     = 0.0f;
			seSystem->playSysSe(SYSSE_CARDACCESS);
			gameflow.mMemoryCard.saveCurrentGame();
		}
		break;

	case Status_5:
		_80->setScale(1.0f);
		seSystem->playSysSe(SYSSE_CARDOK);
		if (gameflow.mMemoryCard.didSaveFail()) {
			mSaveFail->open(1.0f);
			_04     = Status_12;
			mStatus = Status_2;
			_10     = 0.0f;
		} else {
			mStatus = Status_6;
			_10     = 0.0f;
			_60->start(ogFadeMgr::Status_2, 0.25f);
			_68->start(ogFadeMgr::Status_2, 0.25f);
			_64->start(ogFadeMgr::Status_1, 0.25f);
			_6C->start(ogFadeMgr::Status_1, 0.25f);
		}
		break;

	case Status_6:
		if (_10 > 1.0f) {
			_04     = Status_14;
			mStatus = Status_2;
			_10     = 0.0f;
			_64->start(ogFadeMgr::Status_2, 0.25f);
			_6C->start(ogFadeMgr::Status_2, 0.25f);
		}
		break;

	case Status_7:
		if (_10 > 0.25f) {
			_78->setScale(0.0f);
			mStatus = Status_8;
			_10     = 0.0f;
		} else {
			_78->setScale(1.0f - (_10 / 0.25f));
		}
		break;

	case Status_8:
		if (_10 > 0.25f) {
			mStatus = Status_9;
			_7C->setScale(1.0f);
			_1C->start();
		} else {
			_7C->setScale((_10 / 0.25f));
		}
		break;

	case Status_9:
		if (nikatu2 == 5) {
			_04     = Status_13;
			mStatus = Status_10;
			_10     = 0.0f;
		} else if (nikatu2 == 6) {
			_04     = Status_15;
			mStatus = Status_10;
			_10     = 0.0f;
		} else if (nikatu2 == 4) {
			seSystem->playSysSe(SYSSE_CANCEL);
			_04     = Status_1;
			mStatus = Status_10;
			_10     = 0.0f;
		}
		break;

	case Status_10:
		if (_10 > 0.25f) {
			_7C->setScale(0.0f);
			mStatus = _04;
			_10     = 0.0f;
		} else {
			_7C->setScale(1.0f - (_10 / 0.25f));
		}
		break;

	case Status_11:
		if (!savefail) {
			_04     = Status_12;
			mStatus = Status_2;
			_10     = 0.0f;
		}
		break;
	}

	mStatus ? "fake" : "fake";
	mStatus ? "fake" : "fake";

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

	if (_30) {
		_24->draw(0, 0, &graf);
		_84->draw(gfx);
	} else {
		mScreen->draw(0, 0, &graf);
		_0C->draw(0, 0, &graf);
		mMemCheckMgr->draw(gfx);
		mSaveFail->draw(gfx);
	}
}
