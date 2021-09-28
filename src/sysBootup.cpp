

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
 * Address:	80005560
 * Size:	000088
 */
void main(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  lwz       r3, 0x2DEC(r13)
  bl        0x407A8
  li        r3, 0x18
  bl        0x41A88
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x30
  bl        0x3B3AC

.loc_0x30:
  stw       r31, 0x2DD8(r13)
  li        r3, 0x54
  bl        0x41A6C
  mr.       r31, r3
  beq-      .loc_0x4C
  mr        r3, r31
  bl        0x5A034

.loc_0x4C:
  lwz       r3, 0x2DEC(r13)
  mr        r4, r31
  bl        0x3F600
  lis       r3, 0x8022
  crclr     6, 0x6
  lis       r4, 0x8022
  addi      r5, r4, 0x2DD0
  addi      r3, r3, 0x2DC0
  li        r4, 0x1D
  bl        0x1F2340
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}