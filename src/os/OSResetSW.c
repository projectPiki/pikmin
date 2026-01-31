#include "Dolphin/hw_regs.h"
#include "Dolphin/os.h"
#include <stddef.h>

static OSResetCallback ResetCallback;
static BOOL Down;
static BOOL LastState;
static OSTime HoldUp;
static OSTime HoldDown;

extern u8 GameChoice AT_ADDRESS(OS_BASE_CACHED | 0x30E3);

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
OSResetCallback OSSetResetCallback(OSResetCallback)
{
	// UNUSED FUNCTION
}

BOOL OSGetResetButtonState(void)
{
	BOOL enabled;
	BOOL state;
	u32 reg;
	OSTime now;

	enabled = OSDisableInterrupts();

	now = __OSGetSystemTime();

	reg = __PIRegs[0];
	if (!(reg & 0x00010000)) {
		if (!Down) {
			Down     = TRUE;
			state    = HoldUp ? TRUE : FALSE;
			HoldDown = now;
		} else {
			state = (HoldUp || (OSMicrosecondsToTicks(100) < now - HoldDown)) ? TRUE : FALSE;
		}
	} else if (Down) {
		Down  = FALSE;
		state = LastState;
		if (state) {
			HoldUp = now;
		} else {
			HoldUp = 0;
		}
	} else if (HoldUp && (now - HoldUp < OSMillisecondsToTicks(40))) {
		state = TRUE;
	} else {
		state  = FALSE;
		HoldUp = 0;
	}

	LastState = state;
#if defined(VERSION_DPIJ01_PIKIDEMO)
	if (LastState == FALSE && GameChoice & 0x3f) {
#else
	if (GameChoice & 0x3f) {
#endif
		OSTime fire = (GameChoice & 0x3f) * 60;
		fire        = __OSStartTime + OSSecondsToTicks(fire);
		if (fire < now) {
			now -= fire;
			now = OSTicksToSeconds(now) / 2;

#if defined(VERSION_DPIJ01_PIKIDEMO)
			if ((now & 1) == 0 || Down) {
				state = TRUE;
			}
#else
			if ((now & 1) == 0) {
				state = TRUE;
			} else {
				state = FALSE;
			}
#endif
		}
	}

	OSRestoreInterrupts(enabled);
	return state;
}

/**
 * @TODO: Documentation
 */
BOOL OSGetResetSwitchState(void)
{
	BOOL enabled;
	BOOL state;
	u32 reg;

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_G98P01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	return OSGetResetButtonState();
#endif

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
