#include "zen/DrawWMPause.h"
#include "zen/DrawMenu.h"
#include "zen/Math.h"
#include "P2D/Picture.h"
#include "SoundMgr.h"
#include "DebugLog.h"
#include "sysNew.h"

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
DEFINE_PRINT("drawWMPause")

/*
 * --INFO--
 * Address:	801E9CF8
 * Size:	0000A8
 */
zen::DrawWMPause::DrawWMPause()
{
	mPauseMenu = new DrawMenu("screen/blo/pause_w.blo", false, false);
	mPauseMenu->setCancelSelectMenuNo(0);
	P2DScreen* pause = mPauseMenu->getScreenPtr();
	mBackPane        = (P2DPicture*)pause->search('back', true);
	mBackPane->setAlpha(0);
	mReturnFlag = RETURN_NULL;
}

/*
 * --INFO--
 * Address:	801E9DA0
 * Size:	000060
 */
void zen::DrawWMPause::start()
{
	mPauseMenu->start(0);
	mReturnFlag = CourseSelected;
	mBackPane->show();
	mBackPane->setAlpha(0);
	SeSystem::playSysSe(SYSSE_PAUSE);
}

/*
 * --INFO--
 * Address:	801E9E00
 * Size:	00017C
 */
zen::DrawWMPause::returnStatusFlag zen::DrawWMPause::update(Controller* controller)
{
	if (mPauseMenu->update(controller)) {
		int sel     = mPauseMenu->getSelectMenu();
		mReturnFlag = (mPauseMenu->checkSelectMenuCancel()) ? DiaryOpened : (returnStatusFlag)(sel + 1);
	}

	DrawMenu::StatusFlag pauseState = mPauseMenu->getStatusFlag();
	switch (pauseState) {
	case DrawMenu::STATUS_Unk0:
		mBackPane->hide();
		break;

	case DrawMenu::STATUS_Unk1:
		mBackPane->show();
		mBackPane->setAlpha(zen::RoundOff(127.0f * mPauseMenu->getRatio()));
		break;

	case DrawMenu::STATUS_Unk2:
		break;

	case DrawMenu::STATUS_Unk3:
		f32 alpha = 127.0f * (1.0f - mPauseMenu->getRatio());
		mBackPane->setAlpha(zen::RoundOff(alpha));
		break;
	}

	return mReturnFlag;
}

/*
 * --INFO--
 * Address:	801E9F7C
 * Size:	000024
 */
void zen::DrawWMPause::draw(Graphics& gfx)
{
	mPauseMenu->draw(gfx);
}
