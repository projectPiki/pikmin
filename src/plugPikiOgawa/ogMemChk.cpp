#include "zen/ogMemChk.h"
#include "DebugLog.h"
#include "Dolphin/card.h"
#include "P2D/Graph.h"
#include "P2D/Screen.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "jaudio/verysimple.h"
#include "zen/EffectMgr2D.h"
#include "zen/ogMakeDefault.h"
#include "zen/ogNitaku.h"
#include "zen/ogSub.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("OgMemChkSection")

/**
 * @TODO: Documentation
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

	mYesPane = (P2DTextBox*)screen->search('hai', true); // "Yes"
	mNoPane  = (P2DTextBox*)screen->search('iie', true); // "No"

#if defined(VERSION_PIKIDEMO)
#else
	mYesPane2 = (P2DTextBox*)screen->search('haic', true); // "Yes"
	mNoPane2  = (P2DTextBox*)screen->search('iiec', true); // "No"
#endif

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

	mYesNoWindow = screen->search('yn_w', true);
	mCapsulePane = screen->search('cpsl', true);

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

	// gotta hide this one twice, just to be sure
	mBrokenCardTextBox->hide();
	mBrokenCardTextBox->hide();

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
	mStatus          = Inactive;
	mPrevStatusCheck = Inactive;

#if defined(VERSION_PIKIDEMO)
	P2DTextBox* yes = (P2DTextBox*)mMainScreen->search('hai', true); // "yes"
	P2DTextBox* no  = (P2DTextBox*)mMainScreen->search('iie', true); // "no"
	P2DTextBox* a4  = (P2DTextBox*)mMainScreen->search('se_c', true);
	mNitakuMgr      = new ogNitakuMgr(mMainScreen, yes, no, a4, false, false);
#else
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
#endif

	mMakeDefaultMgr = new ogScrMakeDefaultMgr;
	DispYesNo(true);
	DispAcup(false);
	PRINT("---------------------------- ogScrMemChkMgr finish -----------\n");
}

#if defined(VERSION_PIKIDEMO)
#else
/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void zen::ogScrMemChkMgr::SetNitaku_Y_N()
{

	mYesPane->setString(mYesText);
	mNoPane->setString(mNoText);
	mYesPane2->setString(mYesText);
	mNoPane2->setString(mNoText);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void zen::ogScrMemChkMgr::SetNitaku_W_R()
{
	mYesPane->setString(mContinueNoSaveText);
	mNoPane->setString(mRetryText);
	mYesPane2->setString(mContinueNoSaveText);
	mNoPane2->setString(mRetryText);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000034
 */
void zen::ogScrMemChkMgr::SetNitaku_F_N()
{
	mYesPane->setString(mFormatText);
	mNoPane->setString(mNoText);
	mYesPane2->setString(mFormatText);
	mNoPane2->setString(mNoText);
}
#endif

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000C4
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

/**
 * @TODO: Documentation
 */
void zen::ogScrMemChkMgr::StatusCheck()
{
#if defined(VERSION_PIKIDEMO)
#else
	SetNitaku_Y_N();
#endif

	switch (mStatus) {
	case UnformattedCard:
		mPrevStatusCheck = UnformattedCard;
		mStatus          = WritingFormatMsg;
		setPCtex(mDoFixUnformattedTextMgr);
#if defined(VERSION_PIKIDEMO)
#else
		SetNitaku_F_N();
#endif
		break;
	case BrokenCard:
		mPrevStatusCheck = BrokenCard;
		mStatus          = WritingFormatMsg;
		setPCtex(mNeedFormatTextMgr);
#if defined(VERSION_PIKIDEMO)
#else
		SetNitaku_F_N();
#endif
		break;
	}

	// Because the first switch wasnt good enough
	switch (mStatus) {
	case WritingFormatMsg:
		break;
	case NoCard:
		setPCtex(mNoCardTextMgr);
		PRINT("<<<<<<<<<< ERR_NOCARD in ogMemChk >>>>>>>>>>\n");
		break;
	case NotACard:
		setPCtex(mNotACardTextMgr);
		PRINT("<<<<<<<<<< ERR_NOTACARD in ogMemChk >>>>>>>>>>\n");
		break;
	case UnformattedCard:
		setPCtex(mUnformattedCardTextMgr);
		PRINT("<<<<<<<<<< ERR_ENCODING in ogMemChk >>>>>>>>>>\n");
#if defined(VERSION_PIKIDEMO)
#else
		SetNitaku_W_R();
#endif
		break;
	case BrokenCard:
		setPCtex(mBrokenCardTextMgr);
		PRINT("<<<<<<<<<< ERR_BROKEN in ogMemChk >>>>>>>>>>\n");
#if defined(VERSION_PIKIDEMO)
#else
		SetNitaku_W_R();
#endif
		break;
	case CardFull:
		setPCtex(mCardFullTextMgr);
		PRINT("<<<<<<<<<< ERR_FULLUP in ogMemChk >>>>>>>>>>\n");
		break;
	case UnusableCard:
		setPCtex(mUnusableCardTextMgr);
		PRINT("<<<<<<<<<< ERR_UNUSABLE in ogMemChk >>>>>>>>>>\n");
		break;
	case FileNotMade:
		setPCtex(mFileNotMadeTextMgr);
		PRINT("<<<<<<<<<< ERR_NOFILE in ogMemChk >>>>>>>>>>\n");
		break;
	case RepairFile:
		setPCtex(mRepairFileTextMgr);
		PRINT("<<<<<<<<<< REPAIR_NOW in ogMemChk >>>>>>>>>>\n");
		break;
	case RepairSuccess:
		setPCtex(mRepairSuccessTextMgr);
		PRINT("<<<<<<<<<< REPAIR_END in ogMemChk >>>>>>>>>>\n");
		break;
	case RepairFail:
		setPCtex(mRepairFailTextMgr);
		PRINT("<<<<<<<<<< REPAIR_MISS in ogMemChk >>>>>>>>>>\n");
		break;
	default:
		mActiveTextMgr->off();
		break;
	}

	mWaitTimer = 0.0f;
}

/**
 * @TODO: Documentation
 */
void zen::ogScrMemChkMgr::setPCtex(TypingTextMgr* text)
{
	mActiveTextMgr->off();
	mActiveTextMgr = text;
	mActiveTextMgr->start();
}

/**
 * @TODO: Documentation
 */
void zen::ogScrMemChkMgr::DispYesNo(bool set)
{
	if (set) {
		mYesNoWindow->show();
	} else {
		mYesNoWindow->hide();
	}
}

/**
 * @TODO: Documentation
 */
void zen::ogScrMemChkMgr::DispAcup(bool set)
{
	if (set) {
		mCapsulePane->show();
	} else {
		mCapsulePane->hide();
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000040
 */
void zen::ogScrMemChkMgr::MakeDefFileStart()
{
	mMakeDefaultMgr->start();
	mStatus    = MakeDefaultFile;
	mWaitTimer = 0.0f;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00008C
 */
void zen::ogScrMemChkMgr::RepairFileStart()
{
	gameflow.mMemoryCard.repairFile();
	mStatus = RepairFile;
	setPCtex(mRepairFileTextMgr);
	mWaitTimer = 0.0f;
	DispYesNo(false);
}

/**
 * @TODO: Documentation
 */
void zen::ogScrMemChkMgr::start()
{
	mIsDebugMode = false;
	mStatus      = Starting;

	if (!ogCheckInsCard()) { // why is this not CARD_RESULT_NOCARD, Ogawa?
		PRINT("ERR_NOCARD in ogMemChk\n");
		mStatus = NoCard;
	} else {
		int cardstate = gameflow.mMemoryCard.getMemoryCardState(false);
		PRINT("ogMemChk error = %d \n", cardstate);
		if (cardstate == CARD_RESULT_WRONGDEVICE) {
			PRINT("ERR_NOTACARD in ogMemChk\n");
			mStatus = NotACard;
		} else if (cardstate == CARD_RESULT_IOERROR) {
			PRINT("ERR_ENCODING in ogMemChk\n");
			mStatus = UnformattedCard;
		} else if (cardstate == CARD_RESULT_NOFILE) {
			PRINT("ERR_BROKEN in ogMemChk\n");
			mStatus = BrokenCard;
		} else if (cardstate == CARD_RESULT_NOCARD) {
			PRINT("ERR_FULLUP in ogMemChk\n");
			mStatus = CardFull;
		} else if (cardstate == CARD_RESULT_BROKEN) {
			PRINT("ERR_UNUSABLE in ogMemChk\n");
			mStatus = UnusableCard;
		} else if (cardstate == CARD_RESULT_NOENT) {
			PRINT("ERR_NOFILE in ogMemChk\n");
			mStatus = FileNotMade;
		} else if (gameflow.mMemoryCard.mSaveFileIndex < 0) {
			MakeDefFileStart();
		} else if (gameflow.mMemoryCard.isFileBroken()) {
			RepairFileStart();
		}
	}

	StartSub();
	StatusCheck();
}

/**
 * @TODO: Documentation
 */
void zen::ogScrMemChkMgr::DebugStart(int state)
{
	mIsDebugMode = true;
	mDebugState  = state;
	PRINT("@@@@@@@@@@@@@@ DebugStart(%d)  status = %d @@@@@@@@@@@@@@\n", state, mStatus);

	if (state >= WritingFormatMsg && state <= NotACard) {

		mStatus = static_cast<MemChkStatus>(state + 7);

		// If there's no card, create a default file
		if (state == NoCard) {
			MakeDefFileStart();
		} else if (state == NotACard) {
			RepairFileStart();
		}

		StartSub();
		StatusCheck();
		return;
	}

	start();
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000120
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000020
 */
bool zen::ogScrMemChkMgr::checkTypingAll()
{
	return mActiveTextMgr->check() == TypingTextMgr::STATE_Complete ? true : false;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000A8
 */
void zen::ogScrMemChkMgr::checkErrNitaku(ogNitakuMgr* mgr, Controller* input)
{
	if (checkTypingAll()) {
		DispYesNo(true);
#if defined(VERSION_PIKIDEMO)
		ogNitakuMgr::NitakuStatus status = mNitakuMgr->update(input);
#else
		ogNitakuMgr::NitakuStatus status = mgr->update(input);
#endif
		if (status == ogNitakuMgr::ExitFailure) {
			mStatus = ExitFailure;
		} else if (status == ogNitakuMgr::ExitSuccess) {
			mStatus = ExitSuccess;
		}
	} else {
		DispYesNo(false);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000100
 */
void zen::ogScrMemChkMgr::setNoCard()
{
	mStatus = NoCard;
	setErrorMessage();
	DispYesNo(false);
	mAButtonPane->hide();
	DispAcup(false);
#if defined(VERSION_PIKIDEMO)
#else
	SetNitaku_Y_N();
#endif
	mNitakuMgr->start();
	setPCtex(mNoCardTextMgr);

	if (mEfxA) {
		mEfxA->finish();
	}

	if (mEfxB) {
		mEfxB->finish();
	}
}

/**
 * @TODO: Documentation
 */
zen::ogScrMemChkMgr::MemChkStatus zen::ogScrMemChkMgr::update(Controller* input)
{
	if (mStatus == Inactive) {
		return mStatus;
	}

	if (mStatus == Starting) {
		mStatus = Finished;
		return mStatus;
	}

	if (mStatus >= ExitFailure) {
		mStatus = Inactive;
		return mStatus;
	}

	mWaitTimer += gsys->getFrameTime();

	bool hasCard = ogCheckInsCard();
	if (!hasCard && mStatus != NoCard) {
		setNoCard();
	}

	switch (mStatus) {
	case NoCard:
		if (hasCard) {
			start();
			return mStatus;
		}
		checkErrNitaku(mNitakuMgr, input);
		break;

	case UnformattedCard:
#if defined(VERSION_PIKIDEMO)
#else
		SetNitaku_W_R();
		PRINT("##### MEMCHK_DISP_ERR_KAIGAI  ######\n");
		checkErrNitaku(mNitakuMgr, input);
#endif
		break;

	case BrokenCard:
#if defined(VERSION_PIKIDEMO)
#else
		SetNitaku_W_R();
#endif
		PRINT("##### MEMCHK_DISP_ERR_IJYOU  ######\n");
		checkErrNitaku(mNitakuMgr, input);
		break;

	case CardFull:
	case FileNotMade:
#if defined(VERSION_PIKIDEMO)
#else
		SetNitaku_W_R();
#endif
		checkErrNitaku(mNitakuMgr, input);
		break;

	case NotACard:
	case UnusableCard:
		checkErrNitaku(mNitakuMgr, input);
		break;

	case WritingFormatMsg:
		if (checkTypingAll()) {
			mStatus = DoFormatSelection;
#if defined(VERSION_PIKIDEMO)
#else
			SetNitaku_F_N();
#endif
			mNitakuMgr->start();
			DispYesNo(true);
		} else {
			DispYesNo(false);
		}
		break;

	case DoFormatSelection: {
		ogNitakuMgr::NitakuStatus stat = mNitakuMgr->update(input);
		if (stat >= ogNitakuMgr::Status_4) {
			if (stat == ogNitakuMgr::ExitSuccess) {
				setPCtex(mFormatConfirmTextMgr);
				mStatus    = FormatConfirmation;
				mWaitTimer = 0.0f;
			} else {
				_UNUSEDC4 = 0.0f;
				if (mPrevStatusCheck == UnformattedCard) {
					setPCtex(mUnformattedCardTextMgr);
					mStatus = UnformattedCard;
					mNitakuMgr->start();
				} else if (mPrevStatusCheck == BrokenCard) {
					setPCtex(mBrokenCardTextMgr);
					mStatus = BrokenCard;
					mNitakuMgr->start();
				} else {
					mStatus = WritingFormatMsg;
				}
				mWaitTimer = 0.0f;
			}
		}
	} break;

	case FormatConfirmation:
		if (checkTypingAll()) {
			mStatus = DoYouFormat;
#if defined(VERSION_PIKIDEMO)
#else
			SetNitaku_Y_N();
#endif
			mNitakuMgr->start();
			DispYesNo(true);
		} else {
			DispYesNo(false);
		}
		break;

	case DoYouFormat: {
		int stat = mNitakuMgr->update(input);
		if (stat >= ogNitakuMgr::Status_4) {
			if (stat == ogNitakuMgr::ExitSuccess) {
				setPCtex(mFormattingTextMgr);
				mStatus = Formatting;
				DispYesNo(false);
				DispAcup(false);
				mWaitTimer = 0.0f;
				FormatEffectStart();
			} else {
				if (mPrevStatusCheck == UnformattedCard) {
					setPCtex(mDoFixUnformattedTextMgr);
				} else if (mPrevStatusCheck == BrokenCard) {
					setPCtex(mNeedFormatTextMgr);
				}
				mWaitTimer = 0.0f;
				mStatus    = WritingFormatMsg;
			}
		}
	} break;

	case Formatting:
		DispYesNo(false);
		DispAcup(true);
#if defined(VERSION_PIKIDEMO)
		if (mWaitTimer > 3.0f) {
#else
		if (checkTypingAll() && mWaitTimer > 6.0f) {
#endif
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
				mStatus = FormatSuccess;
			} else {
				setPCtex(mCantFormatTextMgr);
				mAButtonPane->show();
				mAButtonAlphaMgr->start();
				mStatus = FormatFail;
			}
		}
		break;

	case FormatSuccess:
		DispYesNo(false);
		DispAcup(true);
		mAButtonAlphaMgr->update();
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
#if defined(VERSION_PIKIDEMO)
			seSystem->playSysSe(JACSYS_Decide1); // this is the wrong enum, devs.
#else
			seSystem->playSysSe(SYSSE_DECIDE1);
#endif
			_UNUSEDC4 = 0.0f;
			if (gameflow.mMemoryCard.mSaveFileIndex < 0) {
#if defined(VERSION_PIKIDEMO)
				mMakeDefaultMgr->start();
				mStatus = MakeDefaultFile;
#else
				MakeDefFileStart();
#endif
			} else {
				mStatus = Finished;
			}
		}
		break;

	case FormatFail:
		mAButtonAlphaMgr->update();
		if (input->keyClick(KBBTN_A | KBBTN_START)) {
#if defined(VERSION_PIKIDEMO)
			seSystem->playSysSe(JACSYS_Decide1);
#else
			seSystem->playSysSe(SYSSE_DECIDE1);
#endif
			_UNUSEDC4 = 0.0f;
			mStatus   = Inactive;
			start();
		}
		break;

	case MakeDefaultFile: {
		int stat = mMakeDefaultMgr->update(input);
		if (stat == ogScrMakeDefaultMgr::Success) {
			mStatus = Finished;
		} else if (stat == ogScrMakeDefaultMgr::Failure) {
#if defined(VERSION_PIKIDEMO)
			start();
#else
			setPCtex(mBrokenCardTextMgr);
			mStatus = BrokenCard;
			SetNitaku_Y_N();
			mNitakuMgr->start();
			_UNUSEDC4  = 0.0f;
			mWaitTimer = 0.0f;
#endif
		}
	} break;

	case RepairFile:
		DispYesNo(false);
		DispAcup(true);
#if defined(VERSION_PIKIDEMO)
		if (checkTypingAll() && mWaitTimer > 5.0f) {
#else
		if (checkTypingAll() && mWaitTimer > 10.0f) {
#endif
			int fail = !gameflow.mMemoryCard.didSaveFail();
			if (fail) {
				mStatus = RepairSuccess;
				setPCtex(mRepairSuccessTextMgr);
			} else {
				mStatus = RepairFail;
				setPCtex(mRepairFailTextMgr);
			}
			mWaitTimer = 0.0f;
			mAButtonAlphaMgr->start();
		}
		break;

	case RepairSuccess:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll()) {
			mAButtonPane->show();
			mAButtonAlphaMgr->update();
			if (input->keyClick(KBBTN_A | KBBTN_START)) {
#if defined(VERSION_PIKIDEMO)
				seSystem->playSysSe(JACSYS_Decide1);
#else
				seSystem->playSysSe(SYSSE_DECIDE1);
#endif
				mStatus = Finished;
			}
		}
		break;

	case RepairFail:
		DispYesNo(false);
		DispAcup(true);
		if (checkTypingAll()) {
			mAButtonPane->show();
			mAButtonAlphaMgr->update();
			if (input->keyClick(KBBTN_A | KBBTN_START)) {
#if defined(VERSION_PIKIDEMO)
				seSystem->playSysSe(JACSYS_Decide1);
				start();
#else
				seSystem->playSysSe(SYSSE_DECIDE1);
				setPCtex(mBrokenCardTextMgr);
				mStatus = BrokenCard;
				SetNitaku_W_R();
				mNitakuMgr->start();
				_UNUSEDC4  = 0.0f;
				mWaitTimer = 0.0f;
#endif
			}
		}
		break;
	}

	setErrorMessage();

	if (mStatus >= ExitFailure) {
		return mStatus;
	}
	mEfxMgr->update();
	mMainScreen->update();
	mCursorAlphaMgr->update();
	mActiveTextMgr->update();
	mActiveTextMgr->transCursor(mCursorPane);
	mBlackScreen->update();

#if defined(VERSION_PIKIDEMO)
	STACK_PAD_TERNARY(mStatus, 8);
#else
	STACK_PAD_TERNARY(mStatus, 10);
#endif
	return mStatus;
}

/**
 * @TODO: Documentation
 */
void zen::ogScrMemChkMgr::draw(Graphics& gfx)
{
	if (mStatus == Inactive) {
		return;
	}
	if (mStatus >= ExitFailure) {
		return;
	}

	if (mDrawWaitCounter > 0) {
		mDrawWaitCounter--;
		return;
	}

	P2DPerspGraph graf(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	graf.setPort();
	mBlackScreen->draw(0, 0, &graf);

	switch (mStatus) {
	case MakeDefaultFile:
		mMakeDefaultMgr->draw(gfx);
		break;

	case ExitFailure:
	case Finished:
		break;

	case NoCard:
	default:
		mMainScreen->draw(0, 0, &graf);
		mEfxMgr->draw(gfx);
		break;
	}
}

/**
 * @TODO: Documentation
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

	switch (mStatus) {
	case NoCard:
		mNoCardTextBox->show();
		break;
	case NotACard:
		mNotACardTextBox->show();
		break;
	case UnformattedCard:
		mUnformattedCardTextBox->show();
		break;
	case BrokenCard:
		mBrokenCardTextBox->show();
		break;
	case CardFull:
		mCardFullTextBox->show();
		break;
	case UnusableCard:
		mUnusableCardTextBox->show();
		break;
	case FileNotMade:
		mFileNotMadeTextBox->show();
		break;
	}
}
