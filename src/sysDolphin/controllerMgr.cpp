#include "Controller.h"

#include "DebugLog.h"
#include "Dolphin/pad.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("ControllerMgr");

static PADStatus sControllerPad[PAD_MAX_CONTROLLERS];
static u32 padChannels[PAD_CHANMAX] = { PAD_CHAN0_BIT, PAD_CHAN1_BIT, PAD_CHAN2_BIT, PAD_CHAN3_BIT };

/**
 * @TODO: Documentation
 */
void ControllerMgr::update()
{
	PADRead(sControllerPad);
	PADClamp(sControllerPad);
	u32 padMask = 0;
	for (int i = 0; i < PAD_MAX_CONTROLLERS; i++) {
		if (sControllerPad[i].err == PAD_ERR_NO_CONTROLLER) {
			padMask |= padChannels[i];
		}
	}
	if (padMask) {
		PADReset(padMask);
	}
}

/**
 * @TODO: Documentation
 */
bool ControllerMgr::keyDown(int btn)
{
	return (sControllerPad[0].button & btn);
}

/**
 * @TODO: Documentation
 */
void ControllerMgr::init()
{
	PADSetSpec(PAD_SPEC_5);
	PADInit();
}

/**
 * @TODO: Documentation
 */
void ControllerMgr::updateController(Controller* controller)
{
	// import stick values from controller
	controller->mMainStickX = sControllerPad[controller->mPlayerNum - 1].stickX;
	controller->mMainStickY = sControllerPad[controller->mPlayerNum - 1].stickY;
	controller->mSubStickX  = sControllerPad[controller->mPlayerNum - 1].substickX;
	controller->mSubStickY  = sControllerPad[controller->mPlayerNum - 1].substickY;

	u32 keyStatus = 0;

	// A B X Y
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_A) {
		keyStatus |= KBBTN_A;
	}
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_B) {
		keyStatus |= KBBTN_B;
	}
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_X) {
		keyStatus |= KBBTN_X;
	}
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_Y) {
		keyStatus |= KBBTN_Y;
	}

	// TRIGGERS (Z, R, L)
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_TRIGGER_Z) {
		keyStatus |= KBBTN_Z;
	}
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_TRIGGER_R) {
		keyStatus |= KBBTN_R;
	}
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_TRIGGER_L) {
		keyStatus |= KBBTN_L;
	}

	// STICKS (THRESHOLD IS +/- 32, RANGE IS [-128, 127])
	if (sControllerPad[controller->mPlayerNum - 1].stickX < -PAD_MIN_STICK_READ) {
		keyStatus |= KBBTN_MSTICK_LEFT;
	}
	if (sControllerPad[controller->mPlayerNum - 1].stickX > PAD_MIN_STICK_READ) {
		keyStatus |= KBBTN_MSTICK_RIGHT;
	}
	if (sControllerPad[controller->mPlayerNum - 1].stickY < -PAD_MIN_STICK_READ) {
		keyStatus |= KBBTN_MSTICK_DOWN;
	}
	if (sControllerPad[controller->mPlayerNum - 1].stickY > PAD_MIN_STICK_READ) {
		keyStatus |= KBBTN_MSTICK_UP;
	}
	if (sControllerPad[controller->mPlayerNum - 1].substickX < -PAD_MIN_STICK_READ) {
		keyStatus |= KBBTN_CSTICK_LEFT;
	}
	if (sControllerPad[controller->mPlayerNum - 1].substickX > PAD_MIN_STICK_READ) {
		keyStatus |= KBBTN_CSTICK_RIGHT;
	}
	if (sControllerPad[controller->mPlayerNum - 1].substickY < -PAD_MIN_STICK_READ) {
		keyStatus |= KBBTN_CSTICK_DOWN;
	}
	if (sControllerPad[controller->mPlayerNum - 1].substickY > PAD_MIN_STICK_READ) {
		keyStatus |= KBBTN_CSTICK_UP;
	}

	// DPAD BUTTONS
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_LEFT) {
		keyStatus |= KBBTN_DPAD_LEFT;
	}
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_RIGHT) {
		keyStatus |= KBBTN_DPAD_RIGHT;
	}
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_UP) {
		keyStatus |= KBBTN_DPAD_UP;
	}
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_DOWN) {
		keyStatus |= KBBTN_DPAD_DOWN;
	}

	// START
	if (sControllerPad[controller->mPlayerNum - 1].button & PAD_BUTTON_START) {
		keyStatus |= KBBTN_START;
	}

	// import analog and trigger values
	controller->mAnalogA  = sControllerPad[controller->mPlayerNum - 1].analogA;
	controller->mAnalogB  = sControllerPad[controller->mPlayerNum - 1].analogB;
	controller->mTriggerL = sControllerPad[controller->mPlayerNum - 1].triggerLeft;
	controller->mTriggerR = sControllerPad[controller->mPlayerNum - 1].triggerRight;

	// process pressed buttons
	controller->updateCont(keyStatus);
}
