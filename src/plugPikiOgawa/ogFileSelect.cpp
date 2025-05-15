#include "zen/ogFileSelect.h"
#include "zen/ogNitaku.h"
#include "zen/ogSub.h"
#include "zen/EffectMgr2D.h"
#include "zen/DrawCommon.h"
#include "P2D/Graph.h"
#include "P2D/Pane.h"
#include "P2D/Picture.h"
#include "P2D/TextBox.h"
#include "P2D/Screen.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "Graphics.h"
#include "MemoryCard.h"
#include "sysNew.h"
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
DEFINE_PRINT("OgFileSelectSection")

/*
 * --INFO--
 * Address:	80187790
 * Size:	000140
 */
void zen::ogScrFileSelectMgr::copyCardInfosSub()
{
	CardQuickInfo infos[4];
	gameflow.mMemoryCard.getQuickInfos(infos);

	for (int i = 0; i < 3; i++) {
		mCardInfo[i] = infos[i];
	}
}

/*
 * --INFO--
 * Address:	801878D0
 * Size:	0001F4
 */
bool zen::ogScrFileSelectMgr::getCardFileInfos()
{
	if (gameflow.mMemoryCard.getMemoryCardState(true) == 0 && gameflow.mMemoryCard.mSaveFileIndex >= 0) {
		bool vibe   = gameflow.mGamePrefs.getVibeMode();
		bool stereo = gameflow.mGamePrefs.getStereoMode();
		bool child  = gameflow.mGamePrefs.getChildMode();
		u8 bgmVol   = gameflow.mGamePrefs.getBgmVol();
		u8 sfxVol   = gameflow.mGamePrefs.mSfxVol; // stack's one too big, something's gotta give

		gameflow.mMemoryCard.loadOptions();

		gameflow.mGamePrefs.setVibeMode(vibe);
		gameflow.mGamePrefs.setStereoMode(stereo);
		gameflow.mGamePrefs.setChildMode(child);
		gameflow.mGamePrefs.setBgmVol(bgmVol);
		gameflow.mGamePrefs.setSfxVol(sfxVol);

		copyCardInfosSub();
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	80187AC4
 * Size:	000020
 */
void zen::ogScrFileSelectMgr::paneOnOffXY(bool set)
{
	if (mSaveMode) {
		mIsLayoutActive = false;
	} else {
		mIsLayoutActive = set;
	}
}

/*
 * --INFO--
 * Address:	80187AE4
 * Size:	0000E0
 */
void zen::ogScrFileSelectMgr::MovePaneXY()
{
	int x0 = mRootPane->getPosH();
	int y0 = mRootPane->getPosV();
	int x1 = mPosPane->getPosH();
	int y1 = mPosPane->getPosV();

	if (mIsLayoutActive) {
		if (x0 > mMainRootPaneTargetPosX) {
			x0 -= 40;
			if (x0 < mMainRootPaneTargetPosX) {
				x0 = mMainRootPaneTargetPosX;
			}
		}

		if (x1 > mPositioningPaneTargetPosX) {
			x1 -= 20;
			if (x1 < mPositioningPaneTargetPosX) {
				x1 = mPositioningPaneTargetPosX;
			}
		}
	} else {
		if (x0 < 650) {
			x0 += 40;
		}
		if (x1 < 650) {
			x1 += 20;
		}
	}

	mRootPane->move(x0, y0);
	mPosPane->move(x1, y1);
}

/*
 * --INFO--
 * Address:	80187BC4
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::OpenYesNoWindow()
{
	mIsDataAnimating    = 1;
	mDataAnimationTimer = 0.0f;
	mNitaku->start();
	mYesNoDialogPane->setScale(0.0f);
	int x = mYesNoDialogPane->getPosH() / 2;
	int y = mYesNoDialogPane->getPosV() / 2;
	mYesNoDialogPane->setOffset(x, y);
	mYesNoDialogPane->show();
	mYesNoDialogImage->show();
	mYesNoDialogImage->setAlpha(0);
}

/*
 * --INFO--
 * Address:	80187C78
 * Size:	000014
 */
void zen::ogScrFileSelectMgr::CloseYesNoWindow()
{
	mIsDataAnimating    = 0;
	mDataAnimationTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void zen::ogScrFileSelectMgr::UpDateYesNoWindow()
{
	if (mDataAnimationTimer < 0.25f) {
		mDataAnimationTimer += gsys->getFrameTime();
		f32 t = mDataAnimationTimer / 0.25f;
		if (mIsDataAnimating) {
			mYesNoDialogPane->setScale(t);
			f32 alpha = mYesNoDialogPromptText->getAlpha() * t;
			mYesNoDialogImage->setAlpha(alpha);
		} else {
			mYesNoDialogPane->setScale(1.0f - t);
			f32 alpha = mYesNoDialogPromptText->getAlpha() * (1.0f - t);
			mYesNoDialogImage->setAlpha(alpha);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void zen::ogScrFileSelectMgr::setOperateMode_Normal()
{
	SetTitleMsg(SelectDataToSave);
	if (mFileSlotSelectionStates[mCurrSlotIdx]) {
		paneOnOffXY(false);
	} else {
		paneOnOffXY(true);
	}

	mCopyLeftCursor.scale(0.0f, 0.2f);
	mCopyRightCursor.scale(0.0f, 0.2f);
}

/*
 * --INFO--
 * Address:	80187C8C
 * Size:	0000F0
 */
void zen::ogScrFileSelectMgr::setOperateMode(zen::ogScrFileSelectMgr::FileOperationMode mode)
{
	mOperation = mode;
	switch (mOperation) {
	case Normal:
		setOperateMode_Normal();
		break;

	case Copy:
		setOperateMode_Copy();
		break;

	case Delete:
		setOperateMode_Delete();
		break;
	}
}

/*
 * --INFO--
 * Address:	80187D7C
 * Size:	0004E0
 */
void zen::ogScrFileSelectMgr::getPane_FileTop1()
{
	mRootPane                  = mMainUIScreen->search('p_co', true);
	mPosPane                   = mMainUIScreen->search('p_sh', true);
	mMainRootPaneTargetPosX    = mRootPane->getPosH();
	mPositioningPaneTargetPosX = mPosPane->getPosH();
	mIsLayoutActive            = false;

	mTitleTextBasePane       = mMainUIScreen->search('p_ma', true);
	mYesNoDialogPane         = mMainUIScreen->search('yn_w', true);
	mCardAccessIcon          = (P2DPicture*)mMainUIScreen->search('chui', true);
	mYesNoDialogImage        = (P2DPicture*)mMainUIScreen->search('back', true);
	mYesNoDialogPromptText   = (P2DTextBox*)mMainUIScreen->search('se_c', true);
	mNitakuYesText           = (P2DTextBox*)mMainUIScreen->search('hai', true);
	mNitakuNoText            = (P2DTextBox*)mMainUIScreen->search('iie', true);
	mPromptSelectSavePane    = mMainUIScreen->search('dono', true);
	mCorruptText             = (P2DTextBox*)mMainUIScreen->search('hsho', true);
	mPromptNoCardPane        = mMainUIScreen->search('sho', true);
	mPromptCardErrPane       = mMainUIScreen->search('dsho', true);
	mPromptSelectCopySrcPane = mMainUIScreen->search('doko', true);
	mConfirmCopyText         = (P2DTextBox*)mMainUIScreen->search('d1co', true);
	mOpInProgressPane        = mMainUIScreen->search('copc', true);
	mPromptConfirmDelPane    = mMainUIScreen->search('dcxx', true);
	mOpCompletePane          = mMainUIScreen->search('dcop', true);
	mFormatDoneText          = (P2DTextBox*)mMainUIScreen->search('dasa', true);
	mPromptSaveFailPane      = mMainUIScreen->search('dosa', true);
	mPromptSaveOKPane        = mMainUIScreen->search('savc', true);
	mPromptCardFullPane      = mMainUIScreen->search('ddxx', true);
	mAltMsgText1             = (P2DTextBox*)mMainUIScreen->search('uasa', true);
	mAltMsgText2             = (P2DTextBox*)mMainUIScreen->search('u1co', true);
	mAltMsgText3             = (P2DTextBox*)mMainUIScreen->search('usho', true);

	Colour colour;
	colour.set(255, 255, 255, 255);
	mAltMsgText1->setCharColor(colour);
	mAltMsgText1->setAlpha(255);
	mAltMsgText2->setAlpha(255);
	mAltMsgText3->setAlpha(255);

	mStrCnvDataCorrupt    = new ogCnvStringMgr(mCorruptText);
	mStrCnvConfirmCopy    = new ogCnvStringMgr(mConfirmCopyText);
	mStrCnvFormatComplete = new ogCnvStringMgr(mFormatDoneText);

	mNitaku = new ogNitakuMgr(mMainUIScreen, mNitakuYesText, mNitakuNoText, mYesNoDialogPromptText, false, true);

	mYesNoDialogImage->hide();
	mYesNoDialogPane->hide();
	mCardAccessIcon->hide();
}

/*
 * --INFO--
 * Address:	8018825C
 * Size:	00032C
 */
void zen::ogScrFileSelectMgr::getPane_FileTop2()
{
	mFileInfoPane1       = mFileInfoScreen->search('da_1', true);
	mFileInfoPane2       = mFileInfoScreen->search('da_2', true);
	mFileInfoPane3       = mFileInfoScreen->search('da_3', true);
	mPartsTensPane       = mFileInfoScreen->search('ro_l', true);
	mPartsUnitsPane      = mFileInfoScreen->search('ro_r', true);
	mTotalPartsTensPane  = mFileInfoScreen->search('rt_l', true);
	mTotalPartsUnitsPane = mFileInfoScreen->search('rt_r', true);
	mRedPikiHundPane     = mFileInfoScreen->search('rc_l', true);
	mRedPikiTensPane     = mFileInfoScreen->search('rc_c', true);
	mRedPikiUnitsPane    = mFileInfoScreen->search('rc_r', true);
	mBluePikiHundPane    = mFileInfoScreen->search('bc_l', true);
	mBluePikiTensPane    = mFileInfoScreen->search('bc_c', true);
	mBluePikiUnitsPane   = mFileInfoScreen->search('bc_r', true);
	mYellowPikiHundPane  = mFileInfoScreen->search('yc_l', true);
	mYellowPikiTensPane  = mFileInfoScreen->search('yc_c', true);
	mYellowPikiUnitsPane = mFileInfoScreen->search('yc_r', true);
	mRedPikiInfoPane     = mFileInfoScreen->search('rcon', true);
	mBluePikiInfoPane    = mFileInfoScreen->search('bcon', true);
	mYellowPikiInfoPane  = mFileInfoScreen->search('ycon', true);
	mAllFileInfoPane     = mFileInfoScreen->search('dall', true);
	mNavInfoPane         = mFileInfoScreen->search('navi', true);
	mTopNewDataIconPane  = mFileInfoScreen->search('newd', true);

	mYesNoWindowChoice = mYellowPikiInfoPane->getPosH();
	mTailEffectCounter = mYellowPikiInfoPane->getPosV();
	setFileData(0);
}

/*
 * --INFO--
 * Address:	80188588
 * Size:	000164
 */
void zen::ogScrFileSelectMgr::setFileData(int fileNum)
{
	P2DScreen* screen = mFileInfoScreen;
	int* redNum       = &mCardInfo[fileNum].mRedPikiCount;
	int* blueNum      = &mCardInfo[fileNum].mBluePikiCount;
	int* yellowNum    = &mCardInfo[fileNum].mYellowPikiCount;
	int* partsNum     = &mCardInfo[fileNum].mCurrentPartsCount;
	mMaxPartsNum      = MAX_UFO_PARTS;

	setNumberTag(screen, 'ro_l', partsNum, 10);
	setNumberTag(screen, 'ro_r', partsNum, 1);
	setNumberTag(screen, 'rt_l', &mMaxPartsNum, 10);
	setNumberTag(screen, 'rt_r', &mMaxPartsNum, 1);
	setNumberTag(screen, 'rc_l', redNum, 100);
	setNumberTag(screen, 'rc_c', redNum, 10);
	setNumberTag(screen, 'rc_r', redNum, 1);
	setNumberTag(screen, 'bc_l', blueNum, 100);
	setNumberTag(screen, 'bc_c', blueNum, 10);
	setNumberTag(screen, 'bc_r', blueNum, 1);
	setNumberTag(screen, 'yc_l', yellowNum, 100);
	setNumberTag(screen, 'yc_c', yellowNum, 10);
	setNumberTag(screen, 'yc_r', yellowNum, 1);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void zen::ogScrFileSelectMgr::set_SM_C()
{
	for (int i = 0; i < 3; i++) {
		Colour colour = mDayCountColorSrcPic[i]->getWhite();
		u8 alpha      = mDayCountColorSrcPic[i]->getAlpha();

		mDayCount1DigitPic[i]->setWhite(colour);
		mDayCount1DigitPic[i]->setAlpha(alpha);
		mDayCount2DigitLPic[i]->setWhite(colour);
		mDayCount2DigitLPic[i]->setAlpha(alpha);
		mDayCount2DigitRPic[i]->setWhite(colour);
		mDayCount2DigitRPic[i]->setAlpha(alpha);
	}
}

/*
 * --INFO--
 * Address:	801886EC
 * Size:	000520
 */
void zen::ogScrFileSelectMgr::getPane_FileIcon()
{
	mSlotNormalPane = mSlotScreensData[0]->search('no_c', true);
	mSlotNewPane    = mSlotScreensData[0]->search('ne_c', true);

	for (int i = 0; i < 3; i++) {
		P2DScreen* screen     = mSlotScreensData[i];
		mIconDataRootPanes[i] = screen->search('root', true);
		mIconNewPanes[i]      = screen->search('newi', true);
		mIconEmptyPanes[i]    = screen->search('nemi', true);
		mIconNewPanes[i]->hide();
		mIconEmptyPanes[i]->hide();

		mIconOnyonPanes[i]  = screen->search('fp', true);
		mIconPikminPanes[i] = screen->search('fp_m', true);

		mIconOnyonPanes[i]->show();
		mIconPikminPanes[i]->show();

		int x = mIconOnyonPanes[i]->getWidth();
		int y = mIconOnyonPanes[i]->getHeight();
		mIconOnyonPanes[i]->setOffset(x / 2, y / 2);

		x = mIconPikminPanes[i]->getWidth();
		y = mIconPikminPanes[i]->getHeight();
		mIconPikminPanes[i]->setOffset(x / 2, y / 2);

		x = mIconNewPanes[i]->getWidth();
		y = mIconNewPanes[i]->getHeight();
		mIconNewPanes[i]->setOffset(x / 2, y / 2);

		x = mIconEmptyPanes[i]->getWidth();
		y = mIconEmptyPanes[i]->getHeight();
		mIconEmptyPanes[i]->setOffset(x / 2, y / 2);

		mOnyonIconPositionsX[i] = mIconOnyonPanes[i]->getPosH();
		mOnyonIconPositionsY[i] = mIconOnyonPanes[i]->getPosV();
		mNewIconPositionsX[i]   = mIconPikminPanes[i]->getPosH();
		mNewIconPositionsY[i]   = mIconPikminPanes[i]->getPosV();

		mOnyonIconScales[i] = mIconOnyonPanes[i]->getScale();
		mNewIconScales[i]   = mIconPikminPanes[i]->getScale();

		mNewIconInitX[i] = mIconNewPanes[i]->getPosH();
		mNewIconInitY[i] = mIconNewPanes[i]->getPosV();

		mEmptyIconInitX[i] = mIconEmptyPanes[i]->getPosH();
		mEmptyIconInitY[i] = mIconEmptyPanes[i]->getPosV();

		mIconFxAnchorPanes[i]   = screen->search('ce_p', true);
		mIconOnyonDestPanes[i]  = screen->search('ef_c', true);
		mIconPikminDestPanes[i] = screen->search('efmc', true);

		f32 scale = 0.7f;
		int x0    = mIconFxAnchorPanes[i]->getPosH();
		int y0    = mIconFxAnchorPanes[i]->getPosV();
		mSlotScreensData[i]->setOffset(x0, y0);
		mSlotScreensData[i]->setScale(scale);
		mSlotScreensNoData[i]->setOffset(x0, y0);
		mSlotScreensNoData[i]->setScale(scale);

		mDayCount1DigitPane[i]  = screen->search('dc_c', true);
		mDayCount1DigitPic[i]   = (P2DPicture*)screen->search('dcmc', true);
		mDayCount2DigitLPane[i] = screen->search('dc_l', true);
		mDayCount2DigitRPane[i] = screen->search('dc_r', true);
		mDayCount2DigitLPic[i]  = (P2DPicture*)screen->search('dcml', true);
		mDayCount2DigitRPic[i]  = (P2DPicture*)screen->search('dcmr', true);
		mDayCountColorSrcPic[i] = (P2DPicture*)screen->search('sm_c', true);

		Colour white = mDayCountColorSrcPic[i]->getWhite();
		u8 alpha     = mDayCountColorSrcPic[i]->getAlpha();

		PRINT("data %d : wc(%d,%d,%d) a %d\n", i, white.r, white.g, white.b, alpha);

		mDayCount1DigitPic[i]->setWhite(white);
		mDayCount1DigitPic[i]->setAlpha(alpha);
		mDayCount2DigitLPic[i]->setWhite(white);
		mDayCount2DigitLPic[i]->setAlpha(alpha);
		mDayCount2DigitRPic[i]->setWhite(white);
		mDayCount2DigitRPic[i]->setAlpha(alpha);

		OnOffKetaNissuu(i);
	}
}

/*
 * --INFO--
 * Address:	80188C0C
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::OnOffKetaNissuu(int fileNum)
{
	P2DScreen* screen = mSlotScreensData[fileNum];
	int* dayNum       = &mCardInfo[fileNum].mCurrentDay;

	if (mCardInfo[fileNum].mCurrentDay < 10) {
		setNumberTag(screen, 'dc_c', dayNum, 1);
		setNumberTag(screen, 'dcmc', dayNum, 1);

		mDayCount1DigitPane[fileNum]->show();
		mDayCount1DigitPic[fileNum]->show();
		mDayCount2DigitLPane[fileNum]->hide();
		mDayCount2DigitRPane[fileNum]->hide();
		mDayCount2DigitLPic[fileNum]->hide();
		mDayCount2DigitRPic[fileNum]->hide();
	} else {
		setNumberTag(screen, 'dc_l', dayNum, 10);
		setNumberTag(screen, 'dc_r', dayNum, 1);
		setNumberTag(screen, 'dcml', dayNum, 10);
		setNumberTag(screen, 'dcmr', dayNum, 1);

		mDayCount2DigitLPane[fileNum]->show();
		mDayCount2DigitRPane[fileNum]->show();
		mDayCount2DigitLPic[fileNum]->show();
		mDayCount2DigitRPic[fileNum]->show();
		mDayCount1DigitPane[fileNum]->hide();
		mDayCount1DigitPic[fileNum]->hide();
	}

	u32 badCompiler;
}

/*
 * --INFO--
 * Address:	80188DC4
 * Size:	0002F0
 */
void zen::ogScrFileSelectMgr::getPane_CpyCurScreen()
{
	P2DScreen* screen           = mCopyCursorsScreen;
	mOperationCursorsScreenPane = screen->search('root', true);
	P2DPane* paneUp0            = screen->search('i00u', true);
	P2DPane* paneDown0          = screen->search('i00d', true);
	P2DPane* paneUp1            = screen->search('i01u', true);
	P2DPane* paneDown1          = screen->search('i01d', true);
	P2DPane* paneUp2            = screen->search('i02u', true);
	P2DPane* paneDown2          = screen->search('i02d', true);

	paneUp0->hide();
	paneDown0->hide();
	paneUp1->hide();
	paneDown1->hide();
	paneUp2->hide();
	paneDown2->hide();

	mCopyCursorLPosX[0] = paneUp0->getPosH();
	mCopyCursorLPosY[0] = paneUp0->getPosV();
	mCopyCursorLPosX[1] = paneUp1->getPosH();
	mCopyCursorLPosY[1] = paneUp1->getPosV();
	mCopyCursorLPosX[2] = paneUp2->getPosH();
	mCopyCursorLPosY[2] = paneUp2->getPosV();

	mCopyCursorRPosX[0] = paneDown0->getPosH();
	mCopyCursorRPosY[0] = paneDown0->getPosV();
	mCopyCursorRPosX[1] = paneDown1->getPosH();
	mCopyCursorRPosY[1] = paneDown1->getPosV();
	mCopyCursorRPosX[2] = paneDown2->getPosH();
	mCopyCursorRPosY[2] = paneDown2->getPosV();

	mCopyLeftCursor.init(screen, mOperationCursorsScreenPane, 'z00l', mCopyCursorLPosX[0], mCopyCursorLPosY[0]);
	mCopyRightCursor.init(screen, mOperationCursorsScreenPane, 'z00r', mCopyCursorRPosX[0], mCopyCursorRPosY[0]);
}

/*
 * --INFO--
 * Address:	801890B4
 * Size:	000340
 */
void zen::ogScrFileSelectMgr::SetTitleMsg(zen::ogScrFileSelectMgr::TitleMessageIndex flag)
{
	mPromptSelectSavePane->hide();
	mCorruptText->hide();
	mPromptNoCardPane->hide();
	mPromptCardErrPane->hide();
	mPromptSelectCopySrcPane->hide();
	mConfirmCopyText->hide();
	mOpInProgressPane->hide();
	mPromptConfirmDelPane->hide();
	mOpCompletePane->hide();
	mFormatDoneText->hide();
	mPromptSaveFailPane->hide();
	mPromptSaveOKPane->hide();
	mPromptCardFullPane->hide();

	setSpecialNumber(6, mCurrSlotIdx + 1);
	setSpecialNumber(7, mCopyTargetFileIndex + 1);
	mStrCnvDataCorrupt->convert();
	mStrCnvConfirmCopy->convert();
	mStrCnvFormatComplete->convert();

	mAltMsgText1->setString(mFormatDoneText->getString());
	mAltMsgText2->setString(mConfirmCopyText->getString());
	mAltMsgText3->setString(mCorruptText->getString());

	if (flag != mTitleMsg) {
		mTitleMsg     = flag;
		mFadeOutTimer = 0.0f;
		mIsFadingOut  = 1;
	}

	switch (flag) {
	case SelectDataToSave:
		mPromptSelectSavePane->show();
		break;

	case DataCorrupted:
		mCorruptText->show();
		break;

	case NoMemoryCardInserted:
		mPromptNoCardPane->show();
		break;

	case MemoryCardErrorOccurred:
		mPromptCardErrPane->show();
		break;

	case SelectSourceFileForCopy:
		mPromptSelectCopySrcPane->show();
		break;

	case ConfirmFileCopy:
		mConfirmCopyText->show();
		break;

	case SelectFileForDelete:
		mOpInProgressPane->show();
		break;

	case ConfirmFileDelete:
		mPromptConfirmDelPane->show();
		break;

	case FormattingInProgress:
		mOpCompletePane->show();
		break;

	case FormatComplete:
		mFormatDoneText->show();
		break;

	case SaveFailedError:
		mPromptSaveFailPane->show();
		break;

	case SaveSuccessful:
		mPromptSaveOKPane->show();
		break;

	case MemoryCardFullError:
		mPromptCardFullPane->show();
		break;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B8
 */
void zen::ogScrFileSelectMgr::ScaleAnimeTitle()
{
	if (mIsFadingOut) {
		mFadeOutTimer += gsys->getFrameTime();
		if (mFadeOutTimer > 5.0f) {
			mIsFadingOut = 0;
		}

		f32 scale = calcPuruPuruScale(mFadeOutTimer);
		mTitleTextBasePane->setScale(scale, scale, 1.0f);
		int x = mTitleTextBasePane->getWidth();
		int y = mTitleTextBasePane->getHeight();
		mTitleTextBasePane->setOffset(x / 2, y / 2);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void zen::ogScrFileSelectMgr::ScaleAnimeData()
{
	if (mIsTitleAnimating) {
		mTitleAnimationTimer += gsys->getFrameTime();
		if (mTitleAnimationTimer > 5.0f) {
			mIsTitleAnimating = 0;
		}

		f32 scale = calcPuruPuruScale(mTitleAnimationTimer);
		mFileInfoScreen->setScale(scale, scale, 1.0f);
		mTitleTextBasePane->getWidth(); // nice copy and pasting ogawa
		mTitleTextBasePane->getHeight();
		mFileInfoScreen->setOffset(320, 400);
	}
}

/*
 * --INFO--
 * Address:	801893F4
 * Size:	0002C8
 */
void zen::ogScrFileSelectMgr::setDataNumber(int p1)
{
	mTitleAnimationTimer = 0.0f;
	mIsTitleAnimating    = 1;
	mFileInfoPane1->hide();
	mFileInfoPane2->hide();
	mFileInfoPane3->hide();

	switch (p1) {
	case 0:
		mFileInfoPane1->show();
		break;

	case 1:
		mFileInfoPane2->show();
		break;

	case 2:
		mFileInfoPane3->show();
		break;
	}

	ChkNewData();
	ChkOnyonOnOff();

	P2DPane* pane = mIconOnyonPanes[mCurrSlotIdx];
	Vector3f pos;
	pos.set(0.0f, 0.0f, 0.0f);
	pos.x = f32(pane->getPosH()) + f32(pane->getWidth()) / 2.0f;
	pos.y = 480.0f - (f32(pane->getPosV()) + f32(pane->getHeight()) / 2.0f);

	if (mCursorMoveEffectOnyon) {
		mCursorMoveEffectOnyon->forceFinish();
	}

	mCursorMoveEffectOnyon = mFxMgr->create(EFF2D_Unk36, pos, nullptr, nullptr);

	pane = mIconPikminPanes[mCurrSlotIdx];
	Vector3f pos2;
	pos2.set(0.0f, 0.0f, 0.0f);
	pos2.x = f32(pane->getPosH()) + f32(pane->getWidth()) / 2.0f;
	pos2.y = 480.0f - (f32(pane->getPosV()) + f32(pane->getHeight()) / 2.0f);

	if (mCursorMoveEffectPikminGroup) {
		mCursorMoveEffectPikminGroup->forceFinish();
	}

	mCursorMoveEffectPikminGroup = mFxMgr->create(EFF2D_Unk35, pos2, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void zen::ogScrFileSelectMgr::init()
{
	mSelectState                    = Inactive;
	mIsTailMoveEffectActive         = 0;
	mActiveTailMoveEffectsCount     = 0;
	mCanCreateNewFile               = 0;
	mMemoryCardCheckState           = 0;
	mIsCopyCompleteMessageActive    = 0;
	mSaveMode                       = 0;
	mMainInteractTimer              = 0.0f;
	mIsSelectionConfirmEffectActive = 0;
	mYesNoWindowChoice              = 0;
	mTailEffectCounter              = 0;
	mCursorMoveEffectOnyon          = 0;
	mCursorMoveEffectPikminGroup    = 0;
}

/*
 * --INFO--
 * Address:	801896BC
 * Size:	0008F8
 */
zen::ogScrFileSelectMgr::ogScrFileSelectMgr()
{
	init();
	mFxMgr              = new EffectMgr2D(16, 0x400, 0x400);
	mSlotScreensData[0] = new P2DScreen();
	mSlotScreensData[1] = new P2DScreen();
	mSlotScreensData[2] = new P2DScreen();
	mSlotScreensData[0]->set("screen/blo/data1.blo", true, true, true);
	mSlotScreensData[1]->set("screen/blo/data2.blo", true, true, true);
	mSlotScreensData[2]->set("screen/blo/data3.blo", true, true, true);

	mSlotScreensNoData[0] = new P2DScreen();
	mSlotScreensNoData[1] = new P2DScreen();
	mSlotScreensNoData[2] = new P2DScreen();
	mSlotScreensNoData[0]->set("screen/blo/data1_n.blo", true, true, true);
	mSlotScreensNoData[1]->set("screen/blo/data2_n.blo", true, true, true);
	mSlotScreensNoData[2]->set("screen/blo/data3_n.blo", true, true, true);
	int i;
	for (i = 0; i < 3; i++) {
		mIconNoDataRootPanes[i] = mSlotScreensNoData[i]->search('root', true);
	}

	mMainUIScreen = new P2DScreen();
	mMainUIScreen->set("screen/blo/data_t1.blo", true, true, true);
	mFileInfoScreen = new P2DScreen();
	mFileInfoScreen->set("screen/blo/data_t2.blo", true, true, true);
	mCopyCursorsScreen = new P2DScreen();
	mCopyCursorsScreen->set("screen/blo/data_i.blo", true, true, true);
	mBlackOverlayScreen = new P2DScreen();
	mBlackOverlayScreen->set("screen/blo/black.blo", false, false, true);

	mDeleteCursorPicture = (P2DPicture*)mBlackOverlayScreen->search('blck', true);
	mDeleteCursorPicture->setAlpha(255);

	getPane_FileTop1();
	getPane_FileTop2();
	getPane_FileIcon();
	getPane_CpyCurScreen();
	SetTitleMsg(SelectDataToSave);
	setOperateMode(Normal);

	for (i = 0; i < 3; i++) {
		mSlotScreensData[i]->setScale(1.0f);
		mSlotScreensNoData[i]->setScale(1.0f);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::ogScrFileSelectMgr::setDataScale()
{
	for (int i = 0; i < 3; i++) {
		mIconDataRootPanes[i]->setScale(mIconDataScales[i]);
		mIconNoDataRootPanes[i]->setScale(mIconNoDataScales[i]);
	}
}

/*
 * --INFO--
 * Address:	80189FC0
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::chaseDataScale()
{
	for (int i = 0; i < 3; i++) {
		if (mCurrSlotIdx == i) {
			mIconDataScales[i] += (1.0f - mIconDataScales[i]) / 10.0f;
			mIconNoDataScales[i] += (1.0f - mIconNoDataScales[i]) / 4.0f;
			P2DPaneLibrary::setFamilyAlpha(mIconOnyonPanes[i], 255);
			P2DPaneLibrary::setFamilyAlpha(mIconPikminPanes[i], 70);
			P2DPaneLibrary::setFamilyAlpha(mIconNewPanes[i], 255);
			P2DPaneLibrary::setFamilyAlpha(mIconEmptyPanes[i], 255);

		} else {
			mIconDataScales[i] += (0.7f - mIconDataScales[i]) / 10.0f;
			mIconNoDataScales[i] += (0.7f - mIconNoDataScales[i]) / 4.0f;
			P2DPaneLibrary::setFamilyAlpha(mIconOnyonPanes[i], 128);
			P2DPaneLibrary::setFamilyAlpha(mIconPikminPanes[i], 64);
			P2DPaneLibrary::setFamilyAlpha(mIconNewPanes[i], 128);
			P2DPaneLibrary::setFamilyAlpha(mIconEmptyPanes[i], 128);
		}
	}

	setDataScale();
}

/*
 * --INFO--
 * Address:	8018A178
 * Size:	0001B8
 */
void zen::ogScrFileSelectMgr::OnOffNewPane(int fileNum)
{
	if (mFileSlotSelectionStates[fileNum]) {
		mIconNewPanes[fileNum]->show();
		mIconEmptyPanes[fileNum]->show();
		mIconOnyonPanes[fileNum]->hide();
		mIconPikminPanes[fileNum]->hide();

		if (fileNum == mCurrSlotIdx) {
			mAllFileInfoPane->hide();
			mNavInfoPane->hide();
			mTopNewDataIconPane->show();
			paneOnOffXY(false);
		}
	} else {
		mIconNewPanes[fileNum]->hide();
		mIconEmptyPanes[fileNum]->hide();
		mIconOnyonPanes[fileNum]->show();
		mIconPikminPanes[fileNum]->show();
		OnOffKetaNissuu(fileNum);

		if (fileNum == mCurrSlotIdx) {
			setFileData(fileNum);
			mAllFileInfoPane->show();
			mNavInfoPane->show();
			mTopNewDataIconPane->hide();
			paneOnOffXY(true);
		}
	}
}

/*
 * --INFO--
 * Address:	8018A330
 * Size:	0000B8
 */
void zen::ogScrFileSelectMgr::ChkOnyonOnOff()
{
	int fileNum = mCurrSlotIdx;
	int reds    = mCardInfo[fileNum].mRedPikiCount;
	int blues   = mCardInfo[fileNum].mBluePikiCount;
	int yellows = mCardInfo[fileNum].mYellowPikiCount;

	if (reds < 0) {
		mRedPikiInfoPane->hide();
	} else {
		mRedPikiInfoPane->show();
	}
	if (blues < 0) {
		mBluePikiInfoPane->hide();
	} else {
		mBluePikiInfoPane->show();
	}
	if (yellows < 0) {
		mYellowPikiInfoPane->hide();
	} else {
		mYellowPikiInfoPane->show();
	}
}

/*
 * --INFO--
 * Address:	8018A3E8
 * Size:	000088
 */
void zen::ogScrFileSelectMgr::ChkNewData()
{
	mFileSlotSelectionStates[0] = mCardInfo[0]._08 == 1;
	mFileSlotSelectionStates[1] = mCardInfo[1]._08 == 1;
	mFileSlotSelectionStates[2] = mCardInfo[2]._08 == 1;

	for (int i = 0; i < 3; i++) {
		OnOffNewPane(i);
	}
}

/*
 * --INFO--
 * Address:	8018A470
 * Size:	000404
 */
void zen::ogScrFileSelectMgr::start(bool saveMode, int fileSelMode)
{
	PRINT("///////////// ogScrFileSelectMgr start() save_mode = %d  FS-Mode %d //////////////\n", saveMode, fileSelMode);
	init();
	mSaveMode = saveMode;
	if (mSaveMode) {
		SetTitleMsg(SaveFailedError);
	} else {
		SetTitleMsg(SelectDataToSave);
	}

	mCursorMoveEffectOnyon       = nullptr;
	mCursorMoveEffectPikminGroup = nullptr;
	getCardFileInfos();

	mIsTailMoveEffectActive      = 0;
	mActiveTailMoveEffectsCount  = 0;
	mCanCreateNewFile            = 0;
	mMemoryCardCheckState        = 0;
	mIsCopyingFileActive         = 0;
	mSelectionChangeTimer        = 0.0f;
	mSelectionConfirmEffectTimer = 0.0f;
	mSelectState                 = FileChosen;
	int i;
	for (i = 0; i < 3; i++) {
		if (i != mCurrSlotIdx) {
			mCopyTargetFileIndex = i;
			break;
		}
	}

	mCurrSlotIdx = 0;
	setDataNumber(mCurrSlotIdx);

	for (i = 0; i < 3; i++) {
		if (mCurrSlotIdx == i) {
			mIconDataScales[i]   = 1.0f;
			mIconNoDataScales[i] = 1.0f;
		} else {
			mIconDataScales[i]   = 0.7f;
			mIconNoDataScales[i] = 0.7f;
		}

		mOnyonIconCurrX[i]  = mOnyonIconPositionsX[i];
		mOnyonIconCurrY[i]  = mOnyonIconPositionsY[i];
		mPikminIconCurrX[i] = mNewIconPositionsX[i];
		mPikminIconCurrY[i] = mNewIconPositionsY[i];

		mIconOnyonPanes[i]->move(mOnyonIconCurrX[i], mOnyonIconCurrY[i]);
		mIconOnyonPanes[i]->setScale(1.0f);

		mIconPikminPanes[i]->move(mPikminIconCurrX[i], mPikminIconCurrY[i]);
		mIconPikminPanes[i]->setScale(1.0f);

		P2DPaneLibrary::setFamilyAlpha(mIconOnyonPanes[i], 255);

		mNewIconCurrX[i] = mNewIconInitX[i];
		mNewIconCurrY[i] = mNewIconInitY[i];
		mIconNewPanes[i]->move(mNewIconCurrX[i], mNewIconCurrY[i]);
		mIconNewPanes[i]->setScale(1.0f);

		mEmptyIconCurrX[i] = mEmptyIconInitX[i];
		mEmptyIconCurrY[i] = mEmptyIconInitY[i];
		mIconEmptyPanes[i]->move(mEmptyIconCurrX[i], mEmptyIconCurrY[i]);
		mIconEmptyPanes[i]->setScale(1.0f);
	}

	mIsSelectionConfirmEffectActive = 0;
	mTitleMsg                       = SelectDataToLoadOrSave;
	mIsFadingOut                    = 0;
	mIsTitleAnimating               = 0;

	mDeleteCursorPicture->setAlpha(255);

	setDataScale();

	if (!mSaveMode) {
		Vector3f pos;
		pos.set(320.0f, 240.0f, 0.0f);
		mFxMgr->create(EFF2D_Unk17, pos, nullptr, nullptr);
		mFxMgr->create(EFF2D_Unk18, pos, nullptr, nullptr);
		mFxMgr->create(EFF2D_Unk19, pos, nullptr, nullptr);
		mFxMgr->create(EFF2D_Unk20, pos, nullptr, nullptr);
		mFxMgr->create(EFF2D_Unk21, pos, nullptr, nullptr);
		mFxMgr->create(EFF2D_Unk22, pos, nullptr, nullptr);
		mFxMgr->create(EFF2D_Unk23, pos, nullptr, nullptr);
		mFxMgr->create(EFF2D_Unk24, pos, nullptr, nullptr);
	}

	PRINT("///////////// ogScrFileSelectMgr start() end //////////////\n");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void zen::ogScrFileSelectMgr::BeginFadeOut()
{
	mSelectState                 = ExitRequested;
	mSelectionConfirmEffectTimer = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
int zen::ogScrFileSelectMgr::CanToCopy(int p1)
{
	int res = 0;
	for (int i = 0; i < 3; i++) {
		if (mFileSlotSelectionStates[i] && i != p1) {
			res++;
		}
	}

	return res;
}

/*
 * --INFO--
 * Address:	8018A874
 * Size:	00036C
 */
void zen::ogScrFileSelectMgr::OperateSelect(Controller* controller)
{
	if (controller->keyClick(KBBTN_MSTICK_LEFT) && mCurrSlotIdx > 0) {
		SeSystem::playSysSe(SYSSE_MOVE1);
		mCurrSlotIdx--;
		setDataNumber(mCurrSlotIdx);
		return;
	}

	if (controller->keyClick(KBBTN_MSTICK_RIGHT) && mCurrSlotIdx < 2) {
		SeSystem::playSysSe(SYSSE_MOVE1);
		mCurrSlotIdx++;
		setDataNumber(mCurrSlotIdx);
		return;
	}

	if (controller->keyClick(KBBTN_A)) {
		SeSystem::playSysSe(SYSSE_DECIDE1);
		KetteiEffectStart();
		if (mSaveMode) {
			mSelectState                 = ExitRequested;
			mSelectionConfirmEffectTimer = 0.0f;
			BeginFadeOut();
		} else {
			mMainInteractTimer   = 0.0f;
			mSelectState         = OperationError;
			mTailEffectMoveTimer = 0.1f;
			if (mCursorMoveEffectOnyon) {
				mCursorMoveEffectOnyon->forceFinish();
			}
			if (mCursorMoveEffectPikminGroup) {
				mCursorMoveEffectPikminGroup->forceFinish();
			}

			TailEffectStart();
		}
		return;
	}

	if (controller->keyClick(KBBTN_B)) {
		mIsTailMoveEffectActive = 1;
		BeginFadeOut();
		SeSystem::playSysSe(SYSSE_CANCEL);
		if (mCursorMoveEffectOnyon) {
			mCursorMoveEffectOnyon->forceFinish();
		}
		if (mCursorMoveEffectPikminGroup) {
			mCursorMoveEffectPikminGroup->forceFinish();
		}
		return;
	}

	if (controller->keyClick(KBBTN_Y)) {
		if (!mFileSlotSelectionStates[mCurrSlotIdx] && !mSaveMode) {
			SeSystem::playSysSe(SYSSE_DECIDE1);
			setOperateMode(Copy);
		}
		return;
	}

	if (controller->keyClick(KBBTN_X)) {
		if (!mFileSlotSelectionStates[mCurrSlotIdx] && !mSaveMode) {
			SeSystem::playSysSe(SYSSE_DECIDE1);
			setOperateMode(Delete);
		}
	}
}

/*
 * --INFO--
 * Address:	8018ABE0
 * Size:	0001FC
 */
void zen::ogScrFileSelectMgr::KetteiEffectStart()
{
	Vector3f pos;
	pos.set(0.0f, 0.0f, 0.0f);
	pos.x = f32(mIconOnyonPanes[mCurrSlotIdx]->getPosH()) + f32(mIconOnyonPanes[mCurrSlotIdx]->getWidth()) / 2.0f;
	pos.y = 480.0f - (f32(mIconOnyonPanes[mCurrSlotIdx]->getPosV()) + f32(mIconOnyonPanes[mCurrSlotIdx]->getHeight()) / 2.0f);

	mFxMgr->create(EFF2D_Unk37, pos, nullptr, nullptr);

	pos.x = f32(mIconPikminPanes[mCurrSlotIdx]->getPosH()) + f32(mIconPikminPanes[mCurrSlotIdx]->getWidth()) / 2.0f;
	pos.y = 480.0f - (f32(mIconPikminPanes[mCurrSlotIdx]->getPosV()) + f32(mIconPikminPanes[mCurrSlotIdx]->getHeight()) / 2.0f);

	mFxMgr->create(EFF2D_Unk34, pos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	8018ADDC
 * Size:	0001D4
 */
void zen::ogScrFileSelectMgr::TailEffectStart()
{
	Vector3f pos;
	pos.set(0.0f, 0.0f, 0.0f);

	pos.x                        = f32(mIconOnyonPanes[mCurrSlotIdx]->getPosH()) + f32(mIconOnyonPanes[mCurrSlotIdx]->getWidth()) / 2.0f;
	pos.y                        = 480.0f - (mIconOnyonPanes[mCurrSlotIdx]->getPosV() + mIconOnyonPanes[mCurrSlotIdx]->getHeight());
	mSelectionConfirmEffectOnyon = mFxMgr->create(EFF2D_Unk38, pos, nullptr, nullptr);

	pos.x = f32(mIconPikminPanes[mCurrSlotIdx]->getPosH()) + f32(mIconPikminPanes[mCurrSlotIdx]->getWidth()) / 2.0f;
	pos.y = 480.0f - (mIconPikminPanes[mCurrSlotIdx]->getPosV() + mIconPikminPanes[mCurrSlotIdx]->getHeight());
	mSelectionConfirmEffectPikminGroup = mFxMgr->create(EFF2D_Unk33, pos, nullptr, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::TailEffectMove(int x, int y)
{
	Vector3f pos;
	int newX = x + mIconOnyonPanes[mCurrSlotIdx]->getWidth() / 2;
	int newY = y + mIconOnyonPanes[mCurrSlotIdx]->getHeight();

	pos.set(newX, 480 - newY, 0.0f);
	mSelectionConfirmEffectOnyon->setEmitPos(pos);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void zen::ogScrFileSelectMgr::TailEffectMoveM(int x, int y)
{
	Vector3f pos;
	int newX = x + mIconPikminPanes[mCurrSlotIdx]->getWidth() / 2;
	int newY = y + mIconPikminPanes[mCurrSlotIdx]->getHeight();

	pos.set(newX, 480 - newY + 100, 0.0f);
	mSelectionConfirmEffectPikminGroup->setEmitPos(pos);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void zen::ogScrFileSelectMgr::quit()
{
	mSelectState = Inactive;
	if (mCursorMoveEffectOnyon) {
		mCursorMoveEffectOnyon->forceFinish();
	}
	if (mCursorMoveEffectPikminGroup) {
		mCursorMoveEffectPikminGroup->forceFinish();
	}
}

/*
 * --INFO--
 * Address:	8018AFB0
 * Size:	000A20
 */
zen::ogScrFileSelectMgr::FileSelectUpdateResult zen::ogScrFileSelectMgr::update(Controller* controller, CardQuickInfo& cardInfo)
{
	if (mSelectState == Inactive) {
		return mSelectState;
	}

	cardInfo = mCardInfo[mCurrSlotIdx];
	mFxMgr->update();
	set_SM_C();
	MovePaneXY();
	ScaleAnimeTitle();
	ScaleAnimeData();
	UpDateYesNoWindow();

	if (mSelectionChangeTimer < 1.0f) {
		mSelectionChangeTimer += gsys->getFrameTime();
	}

	mCopyLeftCursor.update();
	mCopyRightCursor.update();

	if (mSelectState == FileChosen) {
		mSelectionConfirmEffectTimer += gsys->getFrameTime();
		if (mSelectionConfirmEffectTimer >= 0.5f) {
			mSelectState = Continue;
		} else {
			mIsSelectionConfirmEffectActive = 255.0f * mSelectionConfirmEffectTimer / 0.5f;
			mDeleteCursorPicture->setAlpha(255 - mIsSelectionConfirmEffectActive);
		}

		if (mSelectionConfirmEffectTimer < 0.05f) {
			return mSelectState;
		}
	} else if (mSelectState == ExitRequested) {
		mSelectionConfirmEffectTimer += gsys->getFrameTime();
		if (mSelectionConfirmEffectTimer >= 0.5f) {
			mFxMgr->killAll(true);
			if (mIsTailMoveEffectActive) {
				mSelectState = PostSaveAction;
			} else {
				switch (mCurrSlotIdx) {
				case 0:
					mSelectState = PostDeleteAction;
					break;

				case 1:
					mSelectState = PostCopyAction;
					break;

				case 2:
					mSelectState = CardBusy;
					break;

				default:
					mSelectState = ReturnToIPL;
					break;
				}
			}
		} else {
			mIsSelectionConfirmEffectActive = 255.0f * (0.5f - mSelectionConfirmEffectTimer) / 0.5f;
			mDeleteCursorPicture->setAlpha(255 - mIsSelectionConfirmEffectActive);
		}
		return mSelectState;

	} else if (mSelectState >= PostSaveAction) {
		quit();
		mSelectState = Inactive;
		return mSelectState;
	}

	chaseDataScale();

	for (int i = 0; i < 3; i++) {
		mSlotScreensData[i]->update();
		mSlotScreensNoData[i]->update();
	}

	mMainUIScreen->update();
	mFileInfoScreen->update();
	mCopyCursorsScreen->update();
	mBlackOverlayScreen->update();

	mMainInteractTimer += gsys->getFrameTime();

	if (mSelectState == OperationError) {
		mTailEffectMoveTimer += 0.4f;
		mOnyonIconCurrY[mCurrSlotIdx] -= mTailEffectMoveTimer;
		mPikminIconCurrY[mCurrSlotIdx] += mTailEffectMoveTimer;

		mIconOnyonPanes[mCurrSlotIdx]->move(mOnyonIconCurrX[mCurrSlotIdx], mOnyonIconCurrY[mCurrSlotIdx]);
		mIconPikminPanes[mCurrSlotIdx]->move(mPikminIconCurrX[mCurrSlotIdx], mPikminIconCurrY[mCurrSlotIdx]);

		mNewIconCurrY[mCurrSlotIdx] -= mTailEffectMoveTimer;
		mEmptyIconCurrY[mCurrSlotIdx] += mTailEffectMoveTimer;

		mIconNewPanes[mCurrSlotIdx]->move(mNewIconCurrX[mCurrSlotIdx], mNewIconCurrY[mCurrSlotIdx]);
		mIconEmptyPanes[mCurrSlotIdx]->move(mEmptyIconCurrX[mCurrSlotIdx], mEmptyIconCurrY[mCurrSlotIdx]);

		TailEffectMove(mOnyonIconCurrX[mCurrSlotIdx], mOnyonIconCurrY[mCurrSlotIdx]);
		TailEffectMoveM(mPikminIconCurrX[mCurrSlotIdx], mPikminIconCurrY[mCurrSlotIdx]);
		int diff = mOnyonIconPositionsY[mCurrSlotIdx] - mOnyonIconCurrY[mCurrSlotIdx];
		f32 v    = fabs((f64)diff);
		if (v > 200.0f) {
			v = 200.0f;
		}

		u32 badCompiler;
		Vector3f scale = mIconOnyonPanes[mCurrSlotIdx]->getScale();
		scale.x        = 1.0f - v / 200.0f;
		scale.y        = 1.0f - v / 200.0f;

		mIconOnyonPanes[mCurrSlotIdx]->setScale(scale);
		mIconPikminPanes[mCurrSlotIdx]->setScale(scale);

		mIconNewPanes[mCurrSlotIdx]->setScale(scale);
		mIconEmptyPanes[mCurrSlotIdx]->setScale(scale);

		if (mMainInteractTimer > 1.0f) {
			BeginFadeOut();
			mSelectionConfirmEffectOnyon->finish();
			mSelectionConfirmEffectPikminGroup->finish();
		}

		return mSelectState;
	}

	if (mMainInteractTimer > 1.0f) {
		switch (mOperation) {
		case Normal:
			OperateSelect(controller);
			break;

		case Copy:
			OperateCopy(controller);
			break;

		case Delete:
			OperateDelete(controller);
			break;
		}
	}

	mSelectState ? "fake" : "fake";
	mSelectState ? "fake" : "fake";
	mSelectState ? "fake" : "fake";
	mSelectState ? "fake" : "fake";
	mSelectState ? "fake" : "fake";
	mSelectState ? "fake" : "fake";
	mSelectState ? "fake" : "fake";
	mSelectState ? "fake" : "fake";

	return mSelectState;
}

/*
 * --INFO--
 * Address:	8018B9F4
 * Size:	00015C
 */
void zen::ogScrFileSelectMgr::draw(Graphics& gfx)
{
	if (mSelectState == Inactive) {
		return;
	}

	P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
	perspGraph.setPort();

	for (int i = 0; i < 3; i++) {
		mSlotScreensData[i]->draw(0, 0, &perspGraph);
		mSlotScreensNoData[i]->draw(0, 0, &perspGraph);
	}

	mFxMgr->draw(gfx);
	gfx.setFog(false);
	GXSetZMode(GX_FALSE, GX_ALWAYS, GX_FALSE);
	mCopyCursorsScreen->draw(0, 0, &perspGraph);
	mMainUIScreen->draw(0, 0, &perspGraph);
	mFileInfoScreen->draw(0, 0, &perspGraph);
	mBlackOverlayScreen->draw(0, 0, &perspGraph);
}
