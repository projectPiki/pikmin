#include "types.h"

#include "timers.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
// void _Error(char *, ...)
// {
// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
// void _Print(char *, ...)
// {
// UNUSED FUNCTION
// }

/*
 * --INFO--
 * Address:	80040984
 * Size:	000010
 */
void Timers::reset()
{
	_00 = 0;
	_08 = 0;
}

/*
 * --INFO--
 * Address:	80040994
 * Size:	000010
 */
void Timers::newFrame() { mFrameCount++; }

/*
 * --INFO--
 * Address:	800409A4
 * Size:	000004
 */
void Timers::_start(char*, bool) { return; }

/*
 * --INFO--
 * Address:	800409A8
 * Size:	000004
 */
void Timers::_stop(char*) { return; }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void Timers::showTimes()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800409AC
 * Size:	000004
 */
void Timers::draw(Graphics&, Font*) { return; }
