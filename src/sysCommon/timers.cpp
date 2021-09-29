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
  m_word0 = 0;
  m_word8 = 0;
  /*
.loc_0x0:
  li        r0, 0
  stw       r0, 0x0(r3)
  stw       r0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80040994
 * Size:	000010
 */
void Timers::newFrame()
{
  m_frameCount++;
  /*
.loc_0x0:
  lwz       r4, 0x4(r3)
  addi      r0, r4, 0x1
  stw       r0, 0x4(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800409A4
 * Size:	000004
 */
void Timers::_start(char *, bool)
{
  return;
  /*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	800409A8
 * Size:	000004
 */
void Timers::_stop(char *)
{
  return;
  /*
.loc_0x0:
  blr
*/
}

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
void Timers::draw(Graphics &, Font *)
{
  return;
  /*
.loc_0x0:
  blr
*/
}