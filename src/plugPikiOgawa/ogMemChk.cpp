#include "zen/ogMemChk.h"
#include "zen/EffectMgr2D.h"
#include "zen/ogNitaku.h"
#include "zen/ogSub.h"
#include "zen/ogMakeDefault.h"
#include "P2D/Screen.h"
#include "P2D/Picture.h"
#include "P2D/Graph.h"
#include "SoundMgr.h"
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
DEFINE_PRINT("OgMemChkSection")

/*
 * --INFO--
 * Address:	8018D04C
 * Size:	0009D0
 */
zen::ogScrMemChkMgr::ogScrMemChkMgr()
{
	mIsDebugMode = false;
	PRINT("---------------------------- ogScrMemChkMgr begin -----------\n");

	mBlackScreen = new P2DScreen;
	mBlackScreen->set("screen/blo/black.blo", false, false, true);
	mBlackPane = (P2DPicture*)mBlackScreen->search('blck', true);
	mBlackPane->setAlpha(255);

	mEfxMgr = new EffectMgr2D(0x20, 0x80, 0x80);
	mEfxA   = nullptr;
	mEfxB   = nullptr;

	mMainScreen = new P2DScreen;
	mMainScreen->set("screen/blo/data_m.blo", true, true, true);

	P2DScreen* screen = mMainScreen;

	// "If you format this Memory Card, all saved files will be erased. Is this OK?"
	mFormatConfirmTextBox = (P2DTextBox*)screen->search('shom', true);
	// "The Memory Card has been formatted."
	mFormattedTextBox = (P2DTextBox*)screen->search('shot', true);
	// "Formatting the Memory Card... Do not touch the Memory Card or POWER Button."
	mFormattingTextBox = (P2DTextBox*)screen->search('shch', true);
	// The Memory Card in Slot A is corrupted and needs to be formatted."
	mNeedFormatTextBox = (P2DTextBox*)screen->search('shoi', true);
	// "The Memory Card in Slot A is not formatted for use in this market. It must be formatted. Is this OK?"
	mDoFixUnformattedTextBox = (P2DTextBox*)screen->search('shok', true);
	// "The Memory Card could not be formatted."
	mCantFormatTextBox = (P2DTextBox*)screen->search('shos', true);
	mYesPane           = (P2DTextBox*)screen->search('hai', true);  // "Yes"
	mNoPane            = (P2DTextBox*)screen->search('iie', true);  // "No"
	mYesPane2          = (P2DTextBox*)screen->search('haic', true); // "Yes"
	mNoPane2           = (P2DTextBox*)screen->search('iiec', true); // "No"
	// "Some Pikmin save data is corrupted. The Pikmin file will now be repaired. Do not touch the Memory Card or POWER Button."
	mRepairFileTextBox = (P2DTextBox*)screen->search('shuf', true);
	// "The Pikmin file has been repaired."
	mRepairSuccessTextBox = (P2DTextBox*)screen->search('shsi', true);
	// "Some Pikmin save data could not be repaired."
	mRepairFailTextBox = (P2DTextBox*)screen->search('shxx', true);
	// There is no Memory Card in Slot A, so you won't be able to save your game. Continue without saving?"
	mNoCardTextBox = (P2DTextBox*)screen->search('sari', true);
	// The Memory Card in Slot A does not have enough space available. Pikmin needs 1 file and 19 blocks of memory to save. Continue
	// without saving?"
	mCardFullTextBox = (P2DTextBox*)screen->search('memo', true);
	// "The Memory Card in Slot A is not compatible with Pikmin. You can't save.  Continue without saving?"
	mUnusableCardTextBox = (P2DTextBox*)screen->search('brom', true);
	// "The Memory Card inserted in Slot A is not formatted for use in this market. It must be formatted. Is this OK?"
	mUnformattedCardTextBox = (P2DTextBox*)screen->search('kaim', true);
	// "The Memory Card inserted  in Slot A is damaged or corrupted. You can't save. Do you still want to continue?"
	mBrokenCardTextBox = (P2DTextBox*)screen->search('ijom', true);
	// "The device in Slot A cannot be used. You can't save. Is this OK?"
	mNotACardTextBox = (P2DTextBox*)screen->search('naim', true);
	// The Memory Card in Slot A does not have enough space available. Pikmin needs 1 file and 19 blocks of memory to save. Continue
	// without saving?"
	mFileNotMadeTextBox = (P2DTextBox*)screen->search('file', true);
	mYesNoWindow        = screen->search('yn_w', true);
	mCapsulePane        = screen->search('cpsl', true);

	mAButtonPane     = (P2DPicture*)mMainScreen->search('abtn', true);
	mAButtonAlphaMgr = new setTenmetuAlpha(mAButtonPane, 1.0f);
	mAButtonPane->hide();
	mFormatEffPane = (P2DPicture*)mMainScreen->search('main', true);

	mFormatConfirmTextBox->hide();
	mFormattedTextBox->hide();
	mFormattingTextBox->hide();
	mCantFormatTextBox->hide();
	mNeedFormatTextBox->hide();
	mDoFixUnformattedTextBox->hide();
	mRepairFileTextBox->hide();
	mRepairSuccessTextBox->hide();
	mRepairFailTextBox->hide();
	mNoCardTextBox->hide();
	mCardFullTextBox->hide();
	mUnusableCardTextBox->hide();
	mUnformattedCardTextBox->hide();
	mBrokenCardTextBox->hide();
	mBrokenCardTextBox->hide(); // gotta hide this one twice, just to be sure
	mFileNotMadeTextBox->hide();

	mCursorPane     = (P2DPicture*)mMainScreen->search('curs', true);
	mCursorAlphaMgr = new setTenmetuAlpha(mCursorPane, 0.5f);

	mFormatConfirmTextMgr    = new TypingTextMgr(mFormatConfirmTextBox);
	mFormattingTextMgr       = new TypingTextMgr(mFormattingTextBox);
	mFormattedTextMgr        = new TypingTextMgr(mFormattedTextBox);
	mCantFormatTextMgr       = new TypingTextMgr(mCantFormatTextBox);
	mNeedFormatTextMgr       = new TypingTextMgr(mNeedFormatTextBox);
	mDoFixUnformattedTextMgr = new TypingTextMgr(mDoFixUnformattedTextBox);
	mRepairFileTextMgr       = new TypingTextMgr(mRepairFileTextBox);
	mRepairSuccessTextMgr    = new TypingTextMgr(mRepairSuccessTextBox);
	mRepairFailTextMgr       = new TypingTextMgr(mRepairFailTextBox);
	mNoCardTextMgr           = new TypingTextMgr(mNoCardTextBox);
	mCardFullTextMgr         = new TypingTextMgr(mCardFullTextBox);
	mUnusableCardTextMgr     = new TypingTextMgr(mUnusableCardTextBox);
	mUnformattedCardTextMgr  = new TypingTextMgr(mUnformattedCardTextBox);
	mBrokenCardTextMgr       = new TypingTextMgr(mBrokenCardTextBox);
	mNotACardTextMgr         = new TypingTextMgr(mNotACardTextBox);
	mFileNotMadeTextMgr      = new TypingTextMgr(mFileNotMadeTextBox);

	mActiveTextMgr   = mNoCardTextMgr;
	mState           = STATE_NULL;
	mPrevStatusCheck = STATE_NULL;

	P2DTextBox* a1 = (P2DTextBox*)mMainScreen->search('fomt', true); // "Format"
	P2DTextBox* a2 = (P2DTextBox*)mMainScreen->search('cws', true);  // "Continue without saving"
	P2DTextBox* a3 = (P2DTextBox*)mMainScreen->search('rtry', true); // "Retry"
	P2DTextBox* a4 = (P2DTextBox*)mMainScreen->search('se_c', true);
	mNitakuMgr     = new ogNitakuMgr(mMainScreen, mYesPane2, mNoPane2, a4, false, false);
	a1->hide();
	a2->hide();
	a3->hide();
	mYesText            = mYesPane->getString();
	mNoText             = mNoPane->getString();
	mFormatText         = a1->getString();
	mContinueNoSaveText = a2->getString();
	mRetryText          = a3->getString();

	mMakeDefaultMgr = new ogScrMakeDefaultMgr;
	DispYesNo(true);
	DispAcup(false);
	PRINT("---------------------------- ogScrMemChkMgr finish -----------\n");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_Y_N()
{
	mYesPane->setString(mYesText);
	mNoPane->setString(mNoText);
	mYesPane2->setString(mYesText);
	mNoPane2->setString(mNoText);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_W_R()
{
	mYesPane->setString(mContinueNoSaveText);
	mNoPane->setString(mRetryText);
	mYesPane2->setString(mContinueNoSaveText);
	mNoPane2->setString(mRetryText);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void zen::ogScrMemChkMgr::SetNitaku_F_N()
{
	mYesPane->setString(mFormatText);
	mNoPane->setString(mNoText);
	mYesPane2->setString(mFormatText);
	mNoPane2->setString(mNoText);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void zen::ogScrMemChkMgr::StartSub()
{
	mActiveTextMgr->off();
	mActiveTextMgr->transCursor(mCursorPane);

	mCursorAlphaMgr->start();
	mAButtonPane->hide();
	DispAcup(false);
	DispYesNo(true);
	mNitakuMgr->start();
	mDrawWaitCounter = 3;
}

/*
 * --INFO--
 * Address:	8018DA1C
 * Size:	000258
 */
void zen::ogScrMemChkMgr::StatusCheck()
{
	SetNitaku_Y_N();

	switch (mState) {
	case STATE_UnformattedCard:
		mPrevStatusCheck = STATE_UnformattedCard;
		mState           = STATE_WritingFormatMesg;
		setPCtex(mDoFixUnformattedTextMgr);
		SetNitaku_F_N();
		break;
	case STATE_BrokenCard:
		mPrevStatusCheck = STATE_BrokenCard;
		mState           = STATE_WritingFormatMesg;
		setPCtex(mNeedFormatTextMgr);
		SetNitaku_F_N();
		break;
	}

	// Because the first switch wasnt good enough
	switch (mState) {
	case STATE_WritingFormatMesg:
		break;
	case STATE_NoCard:
		setPCtex(mNoCardTextMgr);
		PRINT("<<<<<<<<<< ERR_NOCARD in ogMemChk >>>>>>>>>>\n");
		break;
	case STATE_NotACard:
		setPCtex(mNotACardTextMgr);
		PRINT("<<<<<<<<<< ERR_NOTACARD in ogMemChk >>>>>>>>>>\n");
		break;
	case STATE_UnformattedCard:
		setPCtex(mUnformattedCardTextMgr);
		PRINT("<<<<<<<<<< ERR_ENCODING in ogMemChk >>>>>>>>>>\n");
		SetNitaku_W_R();
		break;
	case STATE_BrokenCard:
		setPCtex(mBrokenCardTextMgr);
		PRINT("<<<<<<<<<< ERR_BROKEN in ogMemChk >>>>>>>>>>\n");
		SetNitaku_W_R();
		break;
	case STATE_CardFull:
		setPCtex(mCardFullTextMgr);
		PRINT("<<<<<<<<<< ERR_FULLUP in ogMemChk >>>>>>>>>>\n");
		break;
	case STATE_UnusableCard:
		setPCtex(mUnusableCardTextMgr);
		PRINT("<<<<<<<<<< ERR_UNUSABLE in ogMemChk >>>>>>>>>>\n");
		break;
	case STATE_FileNotMade:
		setPCtex(mFileNotMadeTextMgr);
		PRINT("<<<<<<<<<< ERR_NOFILE in ogMemChk >>>>>>>>>>\n");
		break;
	case STATE_RepairFile:
		setPCtex(mRepairFileTextMgr);
		PRINT("<<<<<<<<<< REPAIR_NOW in ogMemChk >>>>>>>>>>\n");
		break;
	case STATE_RepairSuccess:
		setPCtex(mRepairSuccessTextMgr);
		PRINT("<<<<<<<<<< REPAIR_END in ogMemChk >>>>>>>>>>\n");
		break;
	case STATE_RepairFail:
		setPCtex(mRepairFailTextMgr);
		PRINT("<<<<<<<<<< REPAIR_MISS in ogMemChk >>>>>>>>>>\n");
		break;
	default:
		mActiveTextMgr->off();
		break;
	}

	mWaitTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	8018DC74
 * Size:	000044
 */
void zen::ogScrMemChkMgr::setPCtex(TypingTextMgr* text)
{
	mActiveTextMgr->off();
	mActiveTextMgr = text;
	mActiveTextMgr->start();
}

/*
 * --INFO--
 * Address:	8018DCB8
 * Size:	000038
 */
void zen::ogScrMemChkMgr::DispYesNo(bool set)
{
	if (set) {
		mYesNoWindow->show();
	} else {
		mYesNoWindow->hide();
	}
}

/*
 * --INFO--
 * Address:	8018DCF0
 * Size:	000038
 */
void zen::ogScrMemChkMgr::DispAcup(bool set)
{
	if (set) {
		mCapsulePane->show();
	} else {
		mCapsulePane->hide();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void zen::ogScrMemChkMgr::MakeDefFileStart()
{
	mMakeDefaultMgr->start();
	mState     = STATE_MakeDefaultFile;
	mWaitTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
void zen::ogScrMemChkMgr::RepairFileStart()
{
	gameflow.mMemoryCard.repairFile();
	mState = STATE_RepairFile;
	setPCtex(mRepairFileTextMgr);
	mWaitTimer = 0.0f;
	DispYesNo(false);
}

/*
 * --INFO--
 * Address:	8018DD28
 * Size:	000224
 */
void zen::ogScrMemChkMgr::start()
{
	mIsDebugMode = false;
	mState       = STATE_Unk0;
	if (!ogCheckInsCard()) {
		PRINT("ERR_NOCARD in ogMemChk\n");
		mState = STATE_NoCard;
	} else {
		int cardstate = gameflow.mMemoryCard.getMemoryCardState(false);
		PRINT("ogMemChk error = %d \n", cardstate);
		if (cardstate == -2) {
			PRINT("ERR_NOTACARD in ogMemChk\n");
			mState = STATE_NotACard;
		} else if (cardstate == -5) {
			PRINT("ERR_ENCODING in ogMemChk\n");
			mState = STATE_UnformattedCard;
		} else if (cardstate == -4) {
			PRINT("ERR_BROKEN in ogMemChk\n");
			mState = STATE_BrokenCard;
		} else if (cardstate == -3) {
			PRINT("ERR_FULLUP in ogMemChk\n");
			mState = STATE_CardFull;
		} else if (cardstate == -6) {
			PRINT("ERR_UNUSABLE in ogMemChk\n");
			mState = STATE_UnusableCard;
		} else if (cardstate == -8) {
			PRINT("ERR_NOFILE in ogMemChk\n");
			mState = STATE_FileNotMade;
		} else if (gameflow.mMemoryCard.mSaveFileIndex < 0) {
			MakeDefFileStart();
		} else if (gameflow.mMemoryCard.isFileBroken()) {
			RepairFileStart();
		}
	}

	StartSub();
	StatusCheck();
}

/*
 * --INFO--
 * Address:	8018DF4C
 * Size:	000190
 */
void zen::ogScrMemChkMgr::DebugStart(int state)
{
	mIsDebugMode = true;
	mDebugState  = state;
	PRINT("@@@@@@@@@@@@@@ DebugStart(%d)  status = %d @@@@@@@@@@@@@@\n", state, mState);

	if (state >= 1 && state <= 9) {

		mState = (MemChkStatus)(state + 7);

		if (state == 8) {
			MakeDefFileStart();
		} else if (state == 9) {
			RepairFileStart();
		}

		StartSub();
		StatusCheck();
		return;
	}

	start();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000120
 */
void zen::ogScrMemChkMgr::FormatEffectStart()
{
	P2DPane* pane = mFormatEffPane;
	Vector3f pos;
	pos.set(320.0f, 240.0f, 0.0f);
	pos.x = f32(pane->getPosH()) + f32(pane->getWidth()) / 2.0f;
	pos.y = 480.0f - (f32(pane->getPosV()) + f32(pane->getHeight()) / 2.0f);
	PRINT("FormatEffectStart !! (%f,%f)\n", pos.x, pos.y);
	mEfxA = mEfxMgr->create(EFF2D_Unk39, pos, nullptr, nullptr);
	mEfxB = mEfxMgr->create(EFF2D_Unk40, pos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
bool zen::ogScrMemChkMgr::checkTypingAll()
{
	if (mActiveTextMgr->check() == TypingTextMgr::STATE_2) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void zen::ogScrMemChkMgr::checkErrNitaku(ogNitakuMgr* mgr, Controller* input)
{
	if (checkTypingAll()) {
		DispYesNo(true);
		ogNitakuMgr::NitakuStatus status = mgr->update(input);
		if (status == ogNitakuMgr::Status_6) {
			mState = STATE_ErrorA;
		} else if (status == ogNitakuMgr::Status_5) {
			mState = STATE_ErrorB;
		}
	} else {
		DispYesNo(false);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void zen::ogScrMemChkMgr::setNoCard()
{
	mState = STATE_NoCard;
	setErrorMessage();
	DispYesNo(false);
	mAButtonPane->hide();
	DispAcup(false);
	SetNitaku_Y_N();
	mNitakuMgr->start();
	setPCtex(mNoCardTextMgr);

	if (mEfxA) {
		mEfxA->finish();
	}

	if (mEfxB) {
		mEfxB->finish();
	}
}

/*
 * --INFO--
 * Address:	8018E0DC
 * Size:	000EC4
 */
zen::ogScrMemChkMgr::MemChkStatus zen::ogScrMemChkMgr::update(Controller* input)
{
	if (mState == STATE_NULL) {
		return mState;
	}

	if (mState == STATE_Unk0) {
		mState = STATE_Finished;
		return mState;
	}

	if (mState >= STATE_ErrorA) {
		mState = STATE_NULL;
		return mState;
	}

	mWaitTimer += gsys->getFrameTime();

	bool hasCard = ogCheckInsCard();
	if (!hasCard && mState != STATE_NoCard) {
		setNoCard();
	}

	switch (mState) {
	case STATE_NoCard:
		if (hasCard) {
			start();
			return mState;
		}
		checkErrNitaku(mNitakuMgr, input);
		break;

	case STATE_UnformattedCard:
		SetNitaku_W_R();
		PRINT("##### MEMCHK_DISP_ERR_KAIGAI  ######\n");
		checkErrNitaku(mNitakuMgr, input);
		break;

	case STATE_BrokenCard:
		SetNitaku_W_R();
		PRINT("##### MEMCHK_DISP_ERR_IJYOU  ######\n");
		checkErrNitaku(mNitakuMgr, input);
		break;

	case STATE_CardFull:
	case STATE_FileNotMade:
		SetNitaku_W_R();
		checkErrNitaku(mNitakuMgr, input);
		break;

	case STATE_NotACard:
	case STATE_UnusableCard:
		checkErrNitaku(mNitakuMgr, input);
		break;

	case STATE_WritingFormatMesg:
		if (checkTypingAll()) {
			mState = STATE_DoFormatSelection;
			SetNitaku_F_N();
			mNitakuMgr->start();
			DispYesNo(true);
		} else {
			DispYesNo(false);
		}
		break;

	case STATE_DoFormatSelection: {
		int stat = mNitakuMgr->update(input);
		if (stat >= ogNitakuMgr::Status_4) {
			if (stat == ogNitakuMgr::Status_5) {
				setPCtex(mFormatConfirmTextMgr);
				mState     = STATE_FormatConfirmation;
				mWaitTimer = 0.0f;
			} else {
				_C4 = 0.0f;
				if (mPrevStatusCheck == STATE_UnformattedCard) {
					setPCtex(mUnformattedCardTextMgr);
					mState = STATE_UnformattedCard;
					mNitakuMgr->start();
				} else if (mPrevStatusCheck == STATE_BrokenCard) {
					setPCtex(mBrokenCardTextMgr);
					mState = STATE_BrokenCard;
					mNitakuMgr->start();
				} else {
					mState = STATE_WritingFormatMesg;
				}
				mWaitTimer = 0.0f;
			}
		}
	} break;

	case STATE_FormatConfirmation:
		if (checkTypingAll()) {
			mState = STATE_DoYouFormat;
			SetNitaku_Y_N();
			mNitakuMgr->start();
			DispYesNo(true);
		} else {
			DispYesNo(false);
		}
		break;

	case STATE_DoYouFormat: {
		int stat = mNitakuMgr->update(input);
		if (stat >= ogNitakuMgr::Status_4) {
			if (stat == ogNitakuMgr::Status_5) {
				setPCtex(mFormattingTextMgr);
				mState = STATE_Formatting;
				DispYesNo(false);
				DispAcup(false);
				mWaitTimer = 0.0f;
				FormatEffectStart();
			} else {
				if (mPrevStatusCheck == STATE_UnformattedCard) {
					setPCtex(mDoFixUnformattedTextMgr);
				} else if (mPrevStatusCheck == STATE_BrokenCard) {
					setPCtex(mNeedFormatTextMgr);
				}
				mWaitTimer = 0.0f;
				mState     = STATE_WritingFormatMesg;
			}
		}
	} break;

	case STATE_Formatting:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll() && mWaitTimer > 6.0f) {
			mEfxA->finish();
			mEfxB->finish();
			bool format = true;
			if (gameflow.mMemoryCard.doFormatCard()) {
				format = false;
			}
			if (format) {
				setPCtex(mFormattedTextMgr);
				mAButtonPane->show();
				mAButtonAlphaMgr->start();
				mState = STATE_FormatSuccess;
			} else {
				setPCtex(mCantFormatTextMgr);
				mAButtonPane->show();
				mAButtonAlphaMgr->start();
				mState = STATE_FormatFail;
			}
		}
		break;

	case STATE_FormatSuccess:
		DispYesNo(false);
		DispAcup(true);
		mAButtonAlphaMgr->update();
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
			seSystem->playSysSe(SYSSE_DECIDE1);
			_C4 = 0.0f;
			if (gameflow.mMemoryCard.mSaveFileIndex < 0) {
				MakeDefFileStart();
			} else {
				mState = STATE_Finished;
			}
		}
		break;

	case STATE_FormatFail:
		mAButtonAlphaMgr->update();
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
			seSystem->playSysSe(SYSSE_DECIDE1);
			_C4    = 0.0f;
			mState = STATE_NULL;
			start();
		}
		break;

	case STATE_MakeDefaultFile: {
		int stat = mMakeDefaultMgr->update(input);
		if (stat == ogScrMakeDefaultMgr::Status_Success) {
			mState = STATE_Finished;
		} else if (stat == ogScrMakeDefaultMgr::Status_Failure) {
			setPCtex(mBrokenCardTextMgr);
			mState = STATE_BrokenCard;
			SetNitaku_Y_N();
			mNitakuMgr->start();
			_C4        = 0.0f;
			mWaitTimer = 0.0f;
		}
	} break;

	case STATE_RepairFile:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll() && mWaitTimer > 10.0f) {
			int fail = !gameflow.mMemoryCard.didSaveFail();
			if (fail) {
				mState = STATE_RepairSuccess;
				setPCtex(mRepairSuccessTextMgr);
			} else {
				mState = STATE_RepairFail;
				setPCtex(mRepairFailTextMgr);
			}
			mWaitTimer = 0.0f;
			mAButtonAlphaMgr->start();
		}
		break;

	case STATE_RepairSuccess:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll()) {
			mAButtonPane->show();
			mAButtonAlphaMgr->update();
			if (input->keyClick(KBBTN_A | KBBTN_START)) {
				seSystem->playSysSe(SYSSE_DECIDE1);
				mState = STATE_Finished;
			}
		}
		break;

	case STATE_RepairFail:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll()) {
			mAButtonPane->show();
			mAButtonAlphaMgr->update();
			if (input->keyClick(KBBTN_A | KBBTN_START)) {
				seSystem->playSysSe(SYSSE_DECIDE1);
				setPCtex(mBrokenCardTextMgr);
				mState = STATE_BrokenCard;
				SetNitaku_W_R();
				mNitakuMgr->start();
				_C4        = 0.0f;
				mWaitTimer = 0.0f;
			}
		}
		break;
	}

	setErrorMessage();

	if (mState >= STATE_ErrorA) {
		return mState;
	}
	mEfxMgr->update();
	mMainScreen->update();
	mCursorAlphaMgr->update();
	mActiveTextMgr->update();
	mActiveTextMgr->transCursor(mCursorPane);
	mBlackScreen->update();

	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	mState ? "fake" : "fake";
	return mState;
}

/*
 * --INFO--
 * Address:	8018EFA0
 * Size:	000110
 */
void zen::ogScrMemChkMgr::draw(Graphics& gfx)
{
	if (mState == STATE_NULL) {
		return;
	}
	if (mState >= STATE_ErrorA) {
		return;
	}

	if (mDrawWaitCounter > 0) {
		mDrawWaitCounter--;
		return;
	}

	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();
	mBlackScreen->draw(0, 0, &graf);

	switch (mState) {
	case STATE_MakeDefaultFile:
		mMakeDefaultMgr->draw(gfx);
		break;

	case STATE_ErrorA:
	case STATE_Finished:
		break;

	case STATE_NoCard:
	default:
		mMainScreen->draw(0, 0, &graf);
		mEfxMgr->draw(gfx);
		break;
	}
}

/*
 * --INFO--
 * Address:	8018F0B0
 * Size:	000144
 */
void zen::ogScrMemChkMgr::setErrorMessage()
{
	mNoCardTextBox->hide();
	mNotACardTextBox->hide();
	mUnformattedCardTextBox->hide();
	mBrokenCardTextBox->hide();
	mCardFullTextBox->hide();
	mUnusableCardTextBox->hide();
	mFileNotMadeTextBox->hide();

	switch (mState) {
	case STATE_NoCard:
		mNoCardTextBox->show();
		break;
	case STATE_NotACard:
		mNotACardTextBox->show();
		break;
	case STATE_UnformattedCard:
		mUnformattedCardTextBox->show();
		break;
	case STATE_BrokenCard:
		mBrokenCardTextBox->show();
		break;
	case STATE_CardFull:
		mCardFullTextBox->show();
		break;
	case STATE_UnusableCard:
		mUnusableCardTextBox->show();
		break;
	case STATE_FileNotMade:
		mFileNotMadeTextBox->show();
		break;
	}
}
