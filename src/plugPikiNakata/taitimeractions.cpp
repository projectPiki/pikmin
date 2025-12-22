#include "DebugLog.h"
#include "TAI/TimerActions.h"
#include "system.h"
#include "teki.h"

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
DEFINE_PRINT("taitimeractions")

void TaiTimerAction::start(Teki& teki)
{
	resetTimer(teki);
}

bool TaiTimerAction::act(Teki& teki)
{
	return teki.timerElapsed(mTimerIdx);
}

void TaiTimerAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mTimerLength, mRandomRate);
}

void TaiResetTimerAction::start(Teki& teki)
{
	resetTimer(teki);
}

void TaiResetTimerAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mTimerLength, mRandomRate);
}

bool TaiTimerElapsedAction::act(Teki& teki)
{
	return teki.timerElapsed(mTimerIdx);
}

void TaiStartingTimerAction::start(Teki& teki)
{
	TaiTimerAction::start(teki);
}

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
