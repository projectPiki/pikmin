#include "zen/ogTutorial.h"
#include "sysNew.h"
#include "zen/ogMessage.h"
#include "PlayerState.h"
#include "zen/ogSub.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
// DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	80182B94
 * Size:	000080
 */
zen::ogScrTutorialMgr::ogScrTutorialMgr()
{
	mMessageMgr = new ogScrMessageMgr("screen/blo/tu_base.blo");
	mMessageMgr->MakeAndSetPageInfo(bloFiles_Tutorial);
	mMessageMgr->_4E0 = 1;
	mStatus           = Status_Null;
}

/*
 * --INFO--
 * Address:	80182C14
 * Size:	0000BC
 */
zen::ogScrTutorialMgr::TutorialStatus zen::ogScrTutorialMgr::update(Controller* input)
{
	if (mStatus == Status_Null) {
		return mStatus;
	}

	switch (mMessageMgr->update(input)) {
	case -1:
		mStatus = Status_Null;
		break;
	case 0:
		mStatus = Status_0;
		break;
	case 1:
		mStatus = Status_1;
		break;
	case 2:
		mStatus = Status_2;
		break;
	case 3:
		mStatus = Status_3;
		break;
	case 4:
		mStatus = Status_4;
		break;
	}
	return mStatus;
}

/*
 * --INFO--
 * Address:	80182CD0
 * Size:	000030
 */
void zen::ogScrTutorialMgr::draw(Graphics& gfx)
{
	if (mStatus != -1) {
		mMessageMgr->draw(gfx);
	}
}

/*
 * --INFO--
 * Address:	80182D00
 * Size:	0000E0
 */
void zen::ogScrTutorialMgr::start(EnumTutorial state)
{
	int days       = 1;
	int parts      = 10;
	int totalParts = 30;
	int totalDays  = 1;
	int powerup    = 77;

	if (playerState) {
		days       = playerState->getCurrDay();
		parts      = playerState->getCurrParts();
		totalParts = playerState->getTotalParts();
		totalParts -= parts;
		totalDays = playerState->getTotalDays();
		totalDays -= days;
		powerup = playerState->getNextPowerupNumber();
	}

	setSpecialNumber(1, days);
	setSpecialNumber(2, parts);
	setSpecialNumber(3, totalParts);
	setSpecialNumber(4, totalDays);
	setSpecialNumber(5, powerup);
	mMessageMgr->start(state);
	mStatus = Status_1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void zen::ogScrTutorialMgr::nextPage()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void zen::ogScrTutorialMgr::backPage()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void zen::ogScrTutorialMgr::setCursorXY(P2DTextBox*)
{
	// UNUSED FUNCTION
}
