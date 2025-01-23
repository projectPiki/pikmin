#include "timers.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("Timers")

/*
 * --INFO--
 * Address:	80040984
 * Size:	000010
 */
void Timers::reset()
{
	mTimerInf = nullptr;
	_08       = 0;
}

/*
 * --INFO--
 * Address:	80040994
 * Size:	000010
 */
void Timers::newFrame()
{
	mFrameCount++;
}

/*
 * --INFO--
 * Address:	800409A4
 * Size:	000004
 */
void Timers::_start(char*, bool)
{
}

/*
 * --INFO--
 * Address:	800409A8
 * Size:	000004
 */
void Timers::_stop(char*)
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void Timers::showTimes()
{
}

/*
 * --INFO--
 * Address:	800409AC
 * Size:	000004
 */
void Timers::draw(Graphics&, Font*)
{
	return;
}
