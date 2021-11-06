#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801124B8
 * Size:	0000A8
 */
void GameStat::init()
{
/*
.loc_0x0:
  lis       r3, 0x803D
  addi      r3, r3, 0x1E58
  li        r0, 0
  stw       r0, 0x8(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x0(r3)
  stw       r0, 0x14(r3)
  stw       r0, 0x10(r3)
  stw       r0, 0xC(r3)
  stw       r0, 0x30F8(r13)
  stw       r0, 0x30FC(r13)
  stw       r0, 0x20(r3)
  stw       r0, 0x1C(r3)
  stw       r0, 0x18(r3)
  stw       r0, 0x2C(r3)
  stw       r0, 0x28(r3)
  stw       r0, 0x24(r3)
  stw       r0, 0x38(r3)
  stw       r0, 0x34(r3)
  stw       r0, 0x30(r3)
  stw       r0, 0x44(r3)
  stw       r0, 0x40(r3)
  stw       r0, 0x3C(r3)
  stw       r0, 0x50(r3)
  stw       r0, 0x4C(r3)
  stw       r0, 0x48(r3)
  stw       r0, 0x5C(r3)
  stw       r0, 0x58(r3)
  stw       r0, 0x54(r3)
  stw       r0, 0x68(r3)
  stw       r0, 0x64(r3)
  stw       r0, 0x60(r3)
  stw       r0, 0x74(r3)
  stw       r0, 0x70(r3)
  stw       r0, 0x6C(r3)
  stw       r0, 0x80(r3)
  stw       r0, 0x7C(r3)
  stw       r0, 0x78(r3)
  stw       r0, 0x3104(r13)
  stw       r0, 0x3100(r13)
  stb       r0, 0x3108(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	80112560
 * Size:	0000C4
 */
void GameStat::update()
{
/*
.loc_0x0:
  lis       r3, 0x803D
  addi      r5, r3, 0x1E58
  lwz       r0, 0x24(r5)
  lwz       r3, 0x3C(r5)
  lwz       r4, 0x30(r5)
  add       r0, r0, r3
  lwz       r3, 0x18(r5)
  add       r0, r0, r4
  add       r0, r3, r0
  stw       r0, 0x6C(r5)
  lwz       r3, 0x40(r5)
  lwz       r0, 0x28(r5)
  lwz       r4, 0x34(r5)
  add       r0, r0, r3
  lwz       r3, 0x1C(r5)
  add       r0, r0, r4
  add       r0, r3, r0
  stw       r0, 0x70(r5)
  lwz       r3, 0x44(r5)
  lwz       r0, 0x2C(r5)
  lwz       r4, 0x38(r5)
  add       r0, r0, r3
  lwz       r3, 0x20(r5)
  add       r0, r0, r4
  add       r0, r3, r0
  stw       r0, 0x74(r5)
  addi      r4, r5, 0x80
  lwz       r3, 0x6C(r5)
  lwz       r0, 0x48(r5)
  add       r0, r3, r0
  stw       r0, 0x78(r5)
  lwz       r3, 0x70(r5)
  lwz       r0, 0x4C(r5)
  add       r0, r3, r0
  stw       r0, 0x7C(r5)
  lwz       r3, 0x74(r5)
  lwz       r0, 0x50(r5)
  add       r0, r3, r0
  stw       r0, 0x80(r5)
  lwz       r4, 0x0(r4)
  lwz       r0, 0x7C(r5)
  lwz       r3, 0x78(r5)
  add       r4, r0, r4
  lwz       r0, 0x3104(r13)
  add       r4, r3, r4
  cmpw      r4, r0
  blelr-    
  stw       r4, 0x3104(r13)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GameStat::Counter::dump(char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void GameStat::ColCounter::dump(char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80112624
 * Size:	000004
 */
void GameStat::dump()
{
}

/*
 * --INFO--
 * Address:	80112628
 * Size:	00009C
 */
void __sinit_gameStat_cpp(void)
{
/*
.loc_0x0:
  lis       r3, 0x803D
  addi      r3, r3, 0x1E58
  li        r0, 0
  stw       r0, 0x8(r3)
  stw       r0, 0x4(r3)
  stw       r0, 0x0(r3)
  stw       r0, 0x14(r3)
  stw       r0, 0x10(r3)
  stw       r0, 0xC(r3)
  stw       r0, 0x30F8(r13)
  stw       r0, 0x30FC(r13)
  stw       r0, 0x20(r3)
  stw       r0, 0x1C(r3)
  stw       r0, 0x18(r3)
  stw       r0, 0x2C(r3)
  stw       r0, 0x28(r3)
  stw       r0, 0x24(r3)
  stw       r0, 0x38(r3)
  stw       r0, 0x34(r3)
  stw       r0, 0x30(r3)
  stw       r0, 0x44(r3)
  stw       r0, 0x40(r3)
  stw       r0, 0x3C(r3)
  stw       r0, 0x50(r3)
  stw       r0, 0x4C(r3)
  stw       r0, 0x48(r3)
  stw       r0, 0x5C(r3)
  stw       r0, 0x58(r3)
  stw       r0, 0x54(r3)
  stw       r0, 0x68(r3)
  stw       r0, 0x64(r3)
  stw       r0, 0x60(r3)
  stw       r0, 0x74(r3)
  stw       r0, 0x70(r3)
  stw       r0, 0x6C(r3)
  stw       r0, 0x80(r3)
  stw       r0, 0x7C(r3)
  stw       r0, 0x78(r3)
  blr
*/
}
