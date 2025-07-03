#include "zen/ogFileSelect.h"
#include "zen/EffectMgr2D.h"
#include "zen/ogNitaku.h"
#include "P2D/TextBox.h"
#include "jaudio/verysimple.h"
#include "SoundMgr.h"
#include "gameflow.h"
#include "DebugLog.h"

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
DEFINE_PRINT("OgFileSelectSection")

/*
 * --INFO--
 * Address:	8019719C
 * Size:	00010C
 */
void zen::ogScrFileSelectMgr::setOperateMode_Copy()
{
	SetTitleMsg(SelectSourceFileForCopy);

	for (int i = 0; i < 3; i++) {
		if (i != mCurrSlotIdx) {
			mCopyTargetFileIndex = i;
			break;
		}
	}

	PRINT("cL(%d,%d)  cR(%d,%d)\n", mCopyCursorLPosX[mCopyTargetFileIndex], mCopyCursorLPosY[mCopyTargetFileIndex],
	      mCopyCursorRPosX[mCopyTargetFileIndex], mCopyCursorRPosY[mCopyTargetFileIndex]);

	mCopyLeftCursor.init(mCopyCursorsScreen, mOperationCursorsScreenPane, 'z00l', mCopyCursorLPosX[mCopyTargetFileIndex],
	                     mCopyCursorLPosY[mCopyTargetFileIndex]);
	mCopyRightCursor.init(mCopyCursorsScreen, mOperationCursorsScreenPane, 'z00r', mCopyCursorRPosX[mCopyTargetFileIndex],
	                      mCopyCursorRPosY[mCopyTargetFileIndex]);

	mOperationCursorsScreenPane->show();
	paneOnOffXY(false);
	mIsCopyTargetSelectionActive = 1;
	mCopyLeftCursor.scale(1.0f, 0.25f);
	mCopyRightCursor.scale(1.0f, 0.25f);

	STACK_PAD_VAR(4);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void zen::ogScrFileSelectMgr::MoveCpyCursor(int id, f32 a2)
{
	mCopyLeftCursor.move(mCopyCursorLPosX[id], mCopyCursorLPosY[id], a2);
	mCopyRightCursor.move(mCopyCursorRPosX[id], mCopyCursorRPosY[id], a2);
}

/*
 * --INFO--
 * Address:	801972A8
 * Size:	0003A8
 */
void zen::ogScrFileSelectMgr::CopyEffectStart()
{
	Vector3f effPos;
	Vector3f attractorPos;

	P2DPane* pane1 = mIconOnyonPanes[mCurrSlotIdx];
	P2DPane* pane2 = mIconOnyonDestPanes[mCopyTargetFileIndex];

	effPos.set(0.0f, 0.0f, 0.0f);
	effPos.x = f32(pane1->getPosH()) + f32(pane1->getWidth()) / 2.0f;
	effPos.y = 480.0f - (f32(pane1->getPosV()) + f32(pane1->getHeight()) / 2.0f);

	pane2->getDispPos(&attractorPos);
	attractorPos.y = 480.0f - attractorPos.y;

	mFileCopyEffectOnyon = mFxMgr->create(EFF2D_Unk42, effPos, nullptr, nullptr);
	mFileCopyEffectOnyon->setNewtonField(attractorPos, 0.0046f, true);

	pane1 = mIconPikminPanes[mCurrSlotIdx];
	pane2 = mIconPikminDestPanes[mCopyTargetFileIndex];

	effPos.set(0.0f, 0.0f, 0.0f);
	effPos.x = f32(pane1->getPosH()) + f32(pane1->getWidth()) / 2.0f;
	effPos.y = 480.0f - (f32(pane1->getPosV()) + f32(pane1->getHeight()) / 2.0f);

	pane2->getDispPos(&attractorPos);
	attractorPos.y = 480.0f - attractorPos.y;

	mFileCopyEffectPikminGroup = mFxMgr->create(EFF2D_Unk41, effPos, nullptr, nullptr);
	mFileCopyEffectPikminGroup->setNewtonField(attractorPos, 0.0046f, true);
}

/*
 * --INFO--
 * Address:	80197650
 * Size:	000488
 */
void zen::ogScrFileSelectMgr::OperateCopy(Controller* input)
{
	if (mIsCopyCompleteMessageActive) {
		mOpCompletePane->show();
		mCopyAnimTimer -= gsys->getFrameTime();
		if (mCopyAnimTimer < 0.0f) {
			mIsCopyCompleteMessageActive = false;
			setOperateMode(Normal);
			mOpCompletePane->hide();
		}
		return;
	}

	if (mIsCopyingFileActive) {
		mOpInProgressPane->show();
		mCardAccessIcon->show();

		f32 rate = mCopyAnimTimer;
		int x, y;
#if defined(VERSION_G98E01_PIKIDEMO)
		if (rate > 2.25f) {
			y = mCardAccessIcon->getPosV();
			x = f32((rate - 2.25f) / 0.75) * 640.0f;
		} else if (rate < 0.75f) {
			y = mCardAccessIcon->getPosV();
			x = f32((rate - 0.75f) / 0.75) * 640.0f;
			mCardAccessIcon->move(x, y);
		} else {
			x = mCardAccessIcon->getPosH();
			y = mCardAccessIcon->getPosV();
		}
#else
		if (rate > 2.7f) {
			y = mCardAccessIcon->getPosV();
			x = (rate - 2.7f) / 0.3f * 640.0f;
		} else if (rate < 0.3f) {
			y = mCardAccessIcon->getPosV();
			x = (rate - 0.3f) / 0.3f * 640.0f;
			mCardAccessIcon->move(x, y);
		} else {
			x = mCardAccessIcon->getPosH();
			y = mCardAccessIcon->getPosV();
		}
#endif

		mCardAccessIcon->move(x, y);
		mCopyAnimTimer -= gsys->getFrameTime();

		if (mCopyAnimTimer < 0.0f && gameflow.mMemoryCard.hasCardFinished()) {
#if defined(VERSION_G98E01_PIKIDEMO)
			seSystem->playSysSe(JACSYS_CardOK);
#else
			seSystem->playSysSe(SYSSE_CARDOK);
#endif
			copyCardInfosSub();
			ChkNewData();
			mIsCopyingFileActive         = false;
			mIsCopyCompleteMessageActive = true;
#if defined(VERSION_G98E01_PIKIDEMO)
			mCopyAnimTimer = 2.0f;
#else
			mCopyAnimTimer = 1.0f;
#endif
			mOpInProgressPane->hide();
			mCardAccessIcon->hide();
			mFileCopyEffectOnyon->finish();
			mFileCopyEffectPikminGroup->finish();
		}
		return;
	}

	if (mIsCopyTargetSelectionActive) {
		if (input->keyClick(KBBTN_B)) {
#if defined(VERSION_G98E01_PIKIDEMO)
			seSystem->playSysSe(JACSYS_Cancel);
#else
			seSystem->playSysSe(SYSSE_CANCEL);
#endif
			setOperateMode(Normal);
		} else if (input->keyClick(KBBTN_A)) {
#if defined(VERSION_G98E01_PIKIDEMO)
			seSystem->playSysSe(JACSYS_Decide1);
#else
			seSystem->playSysSe(SYSSE_DECIDE1);
#endif
			mIsCopyTargetSelectionActive = false;
			mYesNoDialogPane->show();
			mYesNoDialogImage->show();
			mYesNoDialogImage->setAlpha(mYesNoDialogPromptText->getAlphaChar());
			mCopyLeftCursor.scale(0.0f, 0.25f);
			mCopyRightCursor.scale(0.0f, 0.25f);
			OpenYesNoWindow();
			SetTitleMsg(ConfirmFileCopy);
		} else if (input->keyClick(KBBTN_MSTICK_LEFT)) {
			for (int i = 0; i < 3; i++) {
				if (i != mCurrSlotIdx) {
#if defined(VERSION_G98E01_PIKIDEMO)
					seSystem->playSysSe(JACSYS_Move1);
#else
					seSystem->playSysSe(SYSSE_MOVE1);
#endif
					mCopyTargetFileIndex = i;
					break;
				}
			}
			MoveCpyCursor(mCopyTargetFileIndex, 0.25f);
		} else if (input->keyClick(KBBTN_MSTICK_RIGHT)) {
			for (int i = 2; i >= 0; i--) {
				if (i != mCurrSlotIdx) {
#if defined(VERSION_G98E01_PIKIDEMO)
					seSystem->playSysSe(JACSYS_Move1);
#else
					seSystem->playSysSe(SYSSE_MOVE1);
#endif
					mCopyTargetFileIndex = i;
					break;
				}
			}
			MoveCpyCursor(mCopyTargetFileIndex, 0.25f);
		}

		return;
	}

	ogNitakuMgr::NitakuStatus status = mNitaku->update(input);
	if (status >= 4) {
		CloseYesNoWindow();
	}
	if (status == ogNitakuMgr::Status_4) {
#if defined(VERSION_G98E01_PIKIDEMO)
		seSystem->playSysSe(JACSYS_Cancel);
#else
		seSystem->playSysSe(SYSSE_CANCEL);
#endif
		setOperateMode(Normal);
	} else if (status == ogNitakuMgr::ExitSuccess) {
		mIsCopyingFileActive = true;
		mCopyAnimTimer       = 3.0f;
#if defined(VERSION_G98E01_PIKIDEMO)
		seSystem->playSysSe(JACSYS_CardAccess);
#else
		seSystem->playSysSe(SYSSE_CARDACCESS);
#endif
		gameflow.mMemoryCard.copyFile(mCardInfo[mCurrSlotIdx], mCardInfo[mCopyTargetFileIndex]);
		CopyEffectStart();
		mConfirmCopyText->hide();
	} else if (status == ogNitakuMgr::ExitFailure) {
		setOperateMode(Normal);
	}

	STACK_PAD_VAR(4);
}
