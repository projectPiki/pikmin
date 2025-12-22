#include "zen/ogTutorial.h"
#include "DebugLog.h"
#include "PlayerState.h"
#include "sysNew.h"
#include "zen/ogMessage.h"
#include "zen/ogSub.h"

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

/**
 * @TODO: Documentation
 */
zen::ogScrTutorialMgr::ogScrTutorialMgr()
{
	mMessageMgr = new ogScrMessageMgr("screen/blo/tu_base.blo");
	mMessageMgr->MakeAndSetPageInfo(bloFiles_Tutorial);
	mMessageMgr->setSolidMode(true);
	mStatus = Status_Null;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void zen::ogScrTutorialMgr::draw(Graphics& gfx)
{
	if (mStatus != -1) {
		mMessageMgr->draw(gfx);
	}
}

/**
 * @TODO: Documentation
 */
void zen::ogScrTutorialMgr::start(EnumTutorial state)
{
	int days       = 1;
	int parts      = 10;
	int totalParts = MAX_UFO_PARTS;
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
