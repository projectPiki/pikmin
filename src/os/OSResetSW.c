#include "Dolphin/os.h"
#include "Dolphin/hw_regs.h"

static OSResetCallback ResetCallback;
static BOOL Down;
static BOOL LastState;
static OSTime HoldUp;
static OSTime HoldDown;

/*
 * --INFO--
 * Address:	801FA3B4
 * Size:	0000F4
 */
void __OSResetSWInterruptHandler(__OSInterrupt interrupt, OSContext* context)
{
	OSResetCallback callback;

	HoldDown = __OSGetSystemTime();
	while (__OSGetSystemTime() - HoldDown < OSMicrosecondsToTicks(100) && !(__PIRegs[PI_INTRPT_SRC] & PI_INTRPT_RSWST)) {
		;
	}
	if (!(__PIRegs[PI_INTRPT_SRC] & PI_INTRPT_RSWST)) {
		LastState = Down = TRUE;
		__OSMaskInterrupts(OS_INTERRUPTMASK_PI_RSW);
		if (ResetCallback) {
			callback      = ResetCallback;
			ResetCallback = NULL;
			callback();
		}
	}
	__PIRegs[PI_INTRPT_SRC] = 2;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
OSResetCallback OSSetResetCallback(OSResetCallback)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801FA4A8
 * Size:	0001F4
 */
BOOL OSGetResetSwitchState(void)
{
	BOOL enabled;
	BOOL state;
	u32 reg;

	enabled = OSDisableInterrupts();

	reg = __PIRegs[PI_INTRPT_SRC];
	if (!(reg & PI_INTRPT_RSWST)) {
		if (!Down) {
			Down     = TRUE;
			state    = HoldUp ? TRUE : FALSE;
			HoldDown = __OSGetSystemTime();
		} else {
			state = (HoldUp || (OSMicrosecondsToTicks(100) < __OSGetSystemTime() - HoldDown)) ? TRUE : FALSE;
		}
	} else if (Down) {
		Down  = FALSE;
		state = LastState;
		if (state) {
			HoldUp = __OSGetSystemTime();
		}
	} else if (HoldUp && (__OSGetSystemTime() - HoldUp < OSMillisecondsToTicks(40))) {
		state = TRUE;
	} else {
		state  = FALSE;
		HoldUp = 0;
	}

	LastState = state;

	OSRestoreInterrupts(enabled);
	return state;
}
