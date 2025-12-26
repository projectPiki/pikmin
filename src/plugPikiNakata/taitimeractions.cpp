#include "DebugLog.h"
#include "TAI/TimerActions.h"
#include "system.h"
#include "teki.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("taitimeractions")

/**
 * @todo: Documentation
 */
void TaiTimerAction::start(Teki& teki)
{
	resetTimer(teki);
}

/**
 * @todo: Documentation
 */
bool TaiTimerAction::act(Teki& teki)
{
	return teki.timerElapsed(mTimerIdx);
}

/**
 * @todo: Documentation
 */
void TaiTimerAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mTimerLength, mRandomRate);
}

/**
 * @todo: Documentation
 */
void TaiResetTimerAction::start(Teki& teki)
{
	resetTimer(teki);
}

/**
 * @todo: Documentation
 */
void TaiResetTimerAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mTimerLength, mRandomRate);
}

/**
 * @todo: Documentation
 */
bool TaiTimerElapsedAction::act(Teki& teki)
{
	return teki.timerElapsed(mTimerIdx);
}

/**
 * @todo: Documentation
 */
void TaiStartingTimerAction::start(Teki& teki)
{
	TaiTimerAction::start(teki);
}

/**
 * @todo: Documentation
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
