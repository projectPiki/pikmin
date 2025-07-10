#include "DebugLog.h"
#include "SoundMgr.h"
#include "VersionGroups.h"
#include "gameflow.h"
#include "jaudio/verysimple.h"
#include "zen/EffectMgr2D.h"
#include "zen/ogFileSelect.h"
#include "zen/ogNitaku.h"

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
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	80197AD8
 * Size:	000064
 */
void zen::ogScrFileSelectMgr::setOperateMode_Delete()
{
	SetTitleMsg(DataCorrupted);
	OpenYesNoWindow();
	paneOnOffXY(false);
	mCopyLeftCursor.scale(0.0f, 0.001f);
	mCopyRightCursor.scale(0.0f, 0.001f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000178
 */
void zen::ogScrFileSelectMgr::DeleteEffectStart()
{
#if defined(VERSION_PIKIDEMO)
#else
	SetTitleMsg(NoMemoryCardInserted);
#endif
	Vector3f pos1, pos2;

	pos1.set(0.0f, 0.0f, 0.0f);

	// this is to fix stack
#if defined(VERSION_PIKIDEMO)
	pos1.x = mIconOnyonPanes[mCurrSlotIdx]->getPosH() + mIconOnyonPanes[mCurrSlotIdx]->getWidth() / 2.0f;
#else
	f32 w  = mIconOnyonPanes[mCurrSlotIdx]->getPosH() + mIconOnyonPanes[mCurrSlotIdx]->getWidth() / 2.0f;
	pos1.x = w;
#endif

	f32 h  = mIconOnyonPanes[mCurrSlotIdx]->getPosV() + mIconOnyonPanes[mCurrSlotIdx]->getHeight() / 2.0f;
	pos1.y = 480.0f - h;
	mFxMgr->create(EFF2D_Unk44, pos1, nullptr, nullptr);

	pos2.set(pos1.x, (480.0f - pos1.y) - 80.0f, 0.0f);
	mFxMgr->create(EFF2D_Unk43, pos2, nullptr, nullptr);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80197B3C
 * Size:	0003EC
 */
void zen::ogScrFileSelectMgr::OperateDelete(Controller* input)
{
	if (mMemoryCardCheckState) {
		mTailEffectSpawnTimer -= gsys->getFrameTime();
		if (mTailEffectSpawnTimer < 0.0f) {
			mMemoryCardCheckState = false;
			setOperateMode(Normal);
		}
		return;
	}

	if (mCanCreateNewFile) {
#if defined(VERSION_PIKIDEMO)
#else
		mCardAccessIcon->show();
		f32 rate = mTailEffectSpawnTimer;
		int x, y;
		if (rate > 1.7f) {
			y = mCardAccessIcon->getPosV();
			x = (rate - 1.7f) / 0.3f * 640.0f;
		} else if (rate < 0.3f) {
			y = mCardAccessIcon->getPosV();
			x = (rate - 0.3f) / 0.3f * 640.0f;
			mCardAccessIcon->move(x, y);
		} else {
			x = mCardAccessIcon->getPosH();
			y = mCardAccessIcon->getPosV();
		}
		mCardAccessIcon->move(x, y);
#endif
		mTailEffectSpawnTimer -= gsys->getFrameTime();

#if defined(VERSION_PIKIDEMO)
		if (mTailEffectSpawnTimer < 0.0f && gameflow.mMemoryCard.hasCardFinished()) {
			seSystem->playSysSe(JACSYS_CardOK);
			copyCardInfosSub();
			ChkNewData();
			mCanCreateNewFile     = false;
			mMemoryCardCheckState = true;
			mTailEffectSpawnTimer = 1.0f;
		}
#else
		if (!mIsDeletingFileActive && gameflow.mMemoryCard.hasCardFinished()) {
			mIsDeletingFileActive = true;
			copyCardInfosSub();
			ChkNewData();
			seSystem->playSysSe(SYSSE_CARDOK);
		}
		if (mIsDeletingFileActive && mTailEffectSpawnTimer < 0.0f) {
			mCanCreateNewFile     = false;
			mMemoryCardCheckState = true;
			mTailEffectSpawnTimer = 1.0f;
			mCardAccessIcon->hide();
			SetTitleMsg(MemoryCardErrorOccurred);
		}
#endif
		return;
	}

	ogNitakuMgr::NitakuStatus status = mNitaku->update(input);
	if (status >= 4) {
		CloseYesNoWindow();
	}
	if (status == ogNitakuMgr::Status_4) {
#if defined(VERSION_PIKIDEMO)
		seSystem->playSysSe(JACSYS_Cancel);
#else
		seSystem->playSysSe(SYSSE_CANCEL);
#endif
		setOperateMode(Normal);
	} else if (status == 5) {
#if defined(VERSION_PIKIDEMO)
		seSystem->playSysSe(JACSYS_CardAccess);
#else
		seSystem->playSysSe(SYSSE_CARDACCESS);
#endif
		gameflow.mMemoryCard.delFile(mCardInfo[mCurrSlotIdx]);
		DeleteEffectStart();
#if defined(VERSION_PIKIDEMO)
		mTailEffectSpawnTimer = 1.0f;
		mCanCreateNewFile     = true;
#else
		mTailEffectSpawnTimer = 2.0f;
		mCanCreateNewFile     = true;
		mIsDeletingFileActive = false;
#endif
	} else if (status == 6) {
		setOperateMode(Normal);
	}
}
