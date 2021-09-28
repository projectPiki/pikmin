

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void ErrorCode2Num(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000128
 */
void Convert(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802020FC
 * Size:	000158
 */
void __DVDStoreErrorCode(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  subis     r0, r3, 0x123
  cmplwi    r0, 0x4567
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  bne-      .loc_0x24
  li        r31, 0xFF
  b         .loc_0x134

.loc_0x24:
  cmplwi    r0, 0x4568
  bne-      .loc_0x34
  li        r31, 0xFE
  b         .loc_0x134

.loc_0x34:
  li        r0, 0x2
  lis       r4, 0x802F
  mtctr     r0
  subi      r6, r4, 0x76D0
  rlwinm    r4,r3,8,24,31
  rlwinm    r3,r3,0,8,31
  li        r5, 0

.loc_0x50:
  lwz       r0, 0x0(r6)
  cmplw     r3, r0
  bne-      .loc_0x64
  rlwinm    r3,r5,0,24,31
  b         .loc_0x11C

.loc_0x64:
  lwzu      r0, 0x4(r6)
  addi      r5, r5, 0x1
  cmplw     r3, r0
  bne-      .loc_0x7C
  rlwinm    r3,r5,0,24,31
  b         .loc_0x11C

.loc_0x7C:
  lwzu      r0, 0x4(r6)
  addi      r5, r5, 0x1
  cmplw     r3, r0
  bne-      .loc_0x94
  rlwinm    r3,r5,0,24,31
  b         .loc_0x11C

.loc_0x94:
  lwzu      r0, 0x4(r6)
  addi      r5, r5, 0x1
  cmplw     r3, r0
  bne-      .loc_0xAC
  rlwinm    r3,r5,0,24,31
  b         .loc_0x11C

.loc_0xAC:
  lwzu      r0, 0x4(r6)
  addi      r5, r5, 0x1
  cmplw     r3, r0
  bne-      .loc_0xC4
  rlwinm    r3,r5,0,24,31
  b         .loc_0x11C

.loc_0xC4:
  lwzu      r0, 0x4(r6)
  addi      r5, r5, 0x1
  cmplw     r3, r0
  bne-      .loc_0xDC
  rlwinm    r3,r5,0,24,31
  b         .loc_0x11C

.loc_0xDC:
  lwzu      r0, 0x4(r6)
  addi      r5, r5, 0x1
  cmplw     r3, r0
  bne-      .loc_0xF4
  rlwinm    r3,r5,0,24,31
  b         .loc_0x11C

.loc_0xF4:
  lwzu      r0, 0x4(r6)
  addi      r5, r5, 0x1
  cmplw     r3, r0
  bne-      .loc_0x10C
  rlwinm    r3,r5,0,24,31
  b         .loc_0x11C

.loc_0x10C:
  addi      r6, r6, 0x4
  addi      r5, r5, 0x1
  bdnz+     .loc_0x50
  li        r3, 0x1D

.loc_0x11C:
  cmplwi    r4, 0x6
  blt-      .loc_0x128
  li        r4, 0x6

.loc_0x128:
  mulli     r0, r4, 0x1E
  rlwinm    r3,r3,0,24,31
  add       r31, r3, r0

.loc_0x134:
  bl        -0x788C
  stb       r31, 0x24(r3)
  li        r3, 0x1
  bl        -0x7510
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}