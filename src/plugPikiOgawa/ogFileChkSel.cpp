#include "zen/ogFileChkSel.h"
#include "zen/ogMemChk.h"
#include "zen/ogFileSelect.h"
#include "zen/ogSub.h"
#include "P2D/Screen.h"
#include "P2D/Graph.h"
#include "SoundMgr.h"
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
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void zen::ogScrFileChkSelMgr::init()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80193594
 * Size:	000110
 */
zen::ogScrFileChkSelMgr::ogScrFileChkSelMgr()
{
	mState           = FILECHKSEL_NULL;
	_04              = false;
	_0D              = false;
	mIsScreenVisible = false;
	mDataBScreen     = new P2DScreen();
	mDataBScreen->set("screen/blo/data_b.blo", true, true, true);
	mMemChkMgr     = new ogScrMemChkMgr();
	mFileSelectMgr = new ogScrFileSelectMgr();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void zen::ogScrFileChkSelMgr::startSub()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801936A4
 * Size:	000050
 */
void zen::ogScrFileChkSelMgr::start(bool p1)
{
	_0D    = p1;
	_04    = false;
	mState = FILECHKSEL_Unk0;
	mMemChkMgr->start();
	_0C              = false;
	mIsScreenVisible = false;
}

/*
 * --INFO--
 * Address:	801936F4
 * Size:	000054
 */
void zen::ogScrFileChkSelMgr::startSave()
{
	_0D    = false;
	_04    = true;
	mState = FILECHKSEL_Unk0;
	mMemChkMgr->start();
	_0C              = false;
	mIsScreenVisible = false;
}

/*
 * --INFO--
 * Address:	80193748
 * Size:	000198
 */
zen::ogScrFileChkSelMgr::returnStatusFlag zen::ogScrFileChkSelMgr::update(Controller* controller, CardQuickInfo& cardInfo)
{
	if (mState == FILECHKSEL_NULL) {
		return mState;
	}

	if (mState >= FILECHKSEL_Exit) {
		mState = FILECHKSEL_NULL;
		return mState;
	}

	int memChkState = mMemChkMgr->update(controller);
	if (memChkState == ogScrMemChkMgr::STATE_Finished) {
		if (_0D) {
			mState = FILECHKSEL_Unk5;
			return mState;
		}

		mFileSelectMgr->start(_04, 0);
		mIsScreenVisible = true;

	} else if (memChkState == ogScrMemChkMgr::STATE_ErrorB) {
		mState = FILECHKSEL_Unk5;
		return mState;

	} else if (memChkState == ogScrMemChkMgr::STATE_ErrorA) {
		mState = FILECHKSEL_Unk1;
		return mState;

	} else if (memChkState == ogScrMemChkMgr::STATE_NULL) {
		if (!ogCheckInsCard()) {
			SeSystem::stopSysSe(SYSSE_CARDACCESS);
			SeSystem::playSysSe(SYSSE_CARDERROR);
			mState = FILECHKSEL_Unk1;
			return mState;
		}

		mDataBScreen->update();
		switch (mFileSelectMgr->update(controller, cardInfo)) {
		case 6:
			mState = FILECHKSEL_Unk1;
			break;
		case 7:
			mState = FILECHKSEL_Unk2;
			break;
		case 8:
			mState = FILECHKSEL_Unk3;
			break;
		case 9:
			mState = FILECHKSEL_Unk4;
			break;
		case 10:
			mState = FILECHKSEL_Unk5;
			break;
		}
	}

	return mState;
}

/*
 * --INFO--
 * Address:	801938E0
 * Size:	0000BC
 */
void zen::ogScrFileChkSelMgr::draw(Graphics& gfx)
{
	if (mState == FILECHKSEL_NULL) {
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
