#include "zen/ogTutorial.h"
#include "DebugLog.h"
#include "PlayerState.h"
#include "sysNew.h"
#include "zen/ogMessage.h"
#include "zen/ogSub.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT(nullptr)

/**
 * @todo: Documentation
 */
zen::ogScrTutorialMgr::ogScrTutorialMgr()
{
	mMessageMgr = new ogScrMessageMgr("screen/blo/tu_base.blo");
	mMessageMgr->MakeAndSetPageInfo(bloFiles_Tutorial);
	mMessageMgr->setSolidMode(true);
	mStatus = STATUS_Inactive;
}

/**
 * @todo: Documentation
 */
zen::ogScrTutorialMgr::TutorialStatus zen::ogScrTutorialMgr::update(Controller* input)
{
	if (mStatus == STATUS_Inactive) {
		return mStatus;
	}

	switch (mMessageMgr->update(input)) {
	case zen::ogScrMessageMgr::STATE_Inactive:
		mStatus = STATUS_Inactive;
		break;
	case zen::ogScrMessageMgr::STATE_ActiveDisplay:
		mStatus = STATUS_TextActive;
		break;
	case zen::ogScrMessageMgr::STATE_StartDelay:
		mStatus = STATUS_Starting;
		break;
	case zen::ogScrMessageMgr::STATE_FadingIn:
		mStatus = STATUS_FadeIn;
		break;
	case zen::ogScrMessageMgr::STATE_FadingOut:
		mStatus = STATUS_FadeOut;
		break;
	case zen::ogScrMessageMgr::STATE_Exiting:
		mStatus = STATUS_Exiting;
		break;
	}
	return mStatus;
}

/**
 * @todo: Documentation
 */
void zen::ogScrTutorialMgr::draw(Graphics& gfx)
{
	if (mStatus != -1) {
		mMessageMgr->draw(gfx);
	}
}

/**
 * @todo: Documentation
 */
void zen::ogScrTutorialMgr::start(EnumTutorial textID)
{
	// get dummy values we might need for any text variables
	int days          = 1;
	int parts         = 10;
	int totalParts    = MAX_UFO_PARTS;
	int daysRemaining = 1;
	int powerup       = 77;

	if (playerState) {
		days       = playerState->getCurrDay();
		parts      = playerState->getCurrParts();
		totalParts = playerState->getTotalParts();
		totalParts -= parts;
		daysRemaining = playerState->getTotalDays();
		daysRemaining -= days;
		powerup = playerState->getNextPowerupNumber();
	}

	setSpecialNumber(1, days);
	setSpecialNumber(2, parts);
	setSpecialNumber(3, totalParts);
	setSpecialNumber(4, daysRemaining);
	setSpecialNumber(5, powerup);

	mMessageMgr->start(textID);
	mStatus = STATUS_Starting;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void zen::ogScrTutorialMgr::nextPage()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void zen::ogScrTutorialMgr::backPage()
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C
 */
void zen::ogScrTutorialMgr::setCursorXY(P2DTextBox*)
{
	// UNUSED FUNCTION
}
