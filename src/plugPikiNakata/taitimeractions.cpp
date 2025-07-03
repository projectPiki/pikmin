#include "TAI/TimerActions.h"
#include "teki.h"
#include "system.h"
#include "DebugLog.h"

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

/*
 * --INFO--
 * Address:	801436D0
 * Size:	000020
 */
void TaiTimerAction::start(Teki& teki)
{
	resetTimer(teki);
}

/*
 * --INFO--
 * Address:	801436F0
 * Size:	000028
 */
bool TaiTimerAction::act(Teki& teki)
{
	return teki.timerElapsed(mTimerIdx);
}

/*
 * --INFO--
 * Address:	80143718
 * Size:	0000A8
 */
void TaiTimerAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mTimerLength, mRandomRate);
}

/*
 * --INFO--
 * Address:	801437C0
 * Size:	000020
 */
void TaiResetTimerAction::start(Teki& teki)
{
	resetTimer(teki);
}

/*
 * --INFO--
 * Address:	801437E0
 * Size:	0000A8
 */
void TaiResetTimerAction::resetTimer(Teki& teki)
{
	teki.mTimers[mTimerIdx] = NMathF::rateRandom(mTimerLength, mRandomRate);
}

/*
 * --INFO--
 * Address:	80143888
 * Size:	000028
 */
bool TaiTimerElapsedAction::act(Teki& teki)
{
	return teki.timerElapsed(mTimerIdx);
}

/*
 * --INFO--
 * Address:	801438B0
 * Size:	000084
 */
void TaiStartingTimerAction::start(Teki& teki)
{
	TaiTimerAction::start(teki);
}

/*
 * --INFO--
 * Address:	80143988
 * Size:	000114
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
