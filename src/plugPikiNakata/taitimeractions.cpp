#include "DebugLog.h"
#include "TAI/TimerActions.h"
#include "system.h"
#include "teki.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taitimeractions")

/**
 * @TODO: Documentation
 */
void TaiTimerAction::start(Teki& teki)
{
	resetTimer(teki);
}

/**
 * @TODO: Documentation
 */
bool TaiTimerAction::act(Teki& teki)
{
	return teki.timerElapsed(mTimerIdx);
}

/**
 * @TODO: Documentation
 */
void TaiTimerAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mTimerLength, mRandomRate);
}

/**
 * @TODO: Documentation
 */
void TaiResetTimerAction::start(Teki& teki)
{
	resetTimer(teki);
}

/**
 * @TODO: Documentation
 */
void TaiResetTimerAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mTimerLength, mRandomRate);
}

/**
 * @TODO: Documentation
 */
bool TaiTimerElapsedAction::act(Teki& teki)
{
	return teki.timerElapsed(mTimerIdx);
}

/**
 * @TODO: Documentation
 */
void TaiStartingTimerAction::start(Teki& teki)
{
	TaiTimerAction::start(teki);
}

/**
 * @TODO: Documentation
 */
bool TaiStartingTimerAction::act(Teki& teki)
{
	if (teki.timerElapsed(mTimerIdx)) {
		if (NMathF::occurred(mChance)) {
			return true;
		}
		resetTimer(teki);
	}
	return false;
}
