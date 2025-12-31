#include "zen/ogFileChkSel.h"
#include "DebugLog.h"
#include "P2D/Graph.h"
#include "P2D/Screen.h"
#include "SoundMgr.h"
#include "jaudio/verysimple.h"
#include "sysNew.h"
#include "zen/ogFileSelect.h"
#include "zen/ogMemChk.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("OgFileChkSelectSection")

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
void zen::ogScrFileChkSelMgr::init()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
zen::ogScrFileChkSelMgr::ogScrFileChkSelMgr()
{
	mState           = Null;
	mIsSaveOperation = false;
	mSkipFileSelect  = false;
	mIsScreenVisible = false;
	mDataBScreen     = new P2DScreen();
	mDataBScreen->set("screen/blo/data_b.blo", true, true, true);
	mMemChkMgr     = new ogScrMemChkMgr();
	mFileSelectMgr = new ogScrFileSelectMgr();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000048
 */
void zen::ogScrFileChkSelMgr::startSub()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 */
void zen::ogScrFileChkSelMgr::start(bool skipFileSelect)
{
	PRINT("********** ogScrFileChkSelMgr %d ***************\n", skipFileSelect);
	mSkipFileSelect  = skipFileSelect;
	mIsSaveOperation = false;
	mState           = MemoryCheckInProgress;
	mMemChkMgr->start();
	_UNUSED0C        = false;
	mIsScreenVisible = false;
}

/**
 * @todo: Documentation
 */
void zen::ogScrFileChkSelMgr::startSave()
{
	PRINT("********** ogScrFileChkSelMgr for <<SAVE>> ***************\n");
	mSkipFileSelect  = false;
	mIsSaveOperation = true;
	mState           = MemoryCheckInProgress;
	mMemChkMgr->start();
	_UNUSED0C        = false;
	mIsScreenVisible = false;
}

/**
 * @todo: Documentation
 */
zen::ogScrFileChkSelMgr::returnStatusFlag zen::ogScrFileChkSelMgr::update(Controller* controller, CardQuickInfo& cardInfo)
{
	if (mState == Null) {
		return mState;
	}

	if (mState >= FILECHKSEL_Exit) {
		mState = Null;
		return mState;
	}

	int memChkState = mMemChkMgr->update(controller);
	if (memChkState == ogScrMemChkMgr::Finished) {
		if (mSkipFileSelect) {
			mState = ForceExit;
			return mState;
		}

		mFileSelectMgr->start(mIsSaveOperation, 0);
		mIsScreenVisible = true;

	} else if (memChkState == ogScrMemChkMgr::ExitSuccess) {
		mState = ForceExit;
		return mState;

	} else if (memChkState == ogScrMemChkMgr::ExitFailure) {
		mState = ErrorOrCompleted;
		return mState;

	} else if (memChkState == ogScrMemChkMgr::Inactive) {
		if (!ogCheckInsCard()) {
#if defined(VERSION_PIKIDEMO)
			SeSystem::stopSysSe(JACSYS_CardAccess);
			SeSystem::playSysSe(JACSYS_CardError);
#else
			SeSystem::stopSysSe(SYSSE_CARDACCESS);
			SeSystem::playSysSe(SYSSE_CARDERROR);
#endif
			mState = ErrorOrCompleted;
			return mState;
		}

		mDataBScreen->update();
		switch (mFileSelectMgr->update(controller, cardInfo)) {
		case zen::ogScrFileSelectMgr::PostSaveAction:
			mState = ErrorOrCompleted;
			break;
		case zen::ogScrFileSelectMgr::SelectionA:
			mState = SelectionA;
			break;
		case zen::ogScrFileSelectMgr::SelectionB:
			mState = SelectionB;
			break;
		case zen::ogScrFileSelectMgr::SelectionC:
			mState = SelectionC;
			break;
		case zen::ogScrFileSelectMgr::ReturnToIPL:
			mState = ForceExit;
			break;
		}
	}

	return mState;
}

/**
 * @todo: Documentation
 */
void zen::ogScrFileChkSelMgr::draw(Graphics& gfx)
{
	if (mState == Null) {
		return;
	}

	if (mIsScreenVisible) {
		P2DPerspGraph perspGraph(0, 0, 640, 480, 30.0f, 1.0f, 5000.0f);
		perspGraph.setPort();
		mDataBScreen->draw(0, 0, &perspGraph);
	}

	mFileSelectMgr->draw(gfx);
	mMemChkMgr->draw(gfx);
}
