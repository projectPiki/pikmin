

/*
 * --INFO--
 * Address:	8020CA64
 * Size:	0000A4
 */
void DeleteCallback(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  mr.       r29, r4
  stw       r28, 0x10(r1)
  addi      r28, r3, 0
  mulli     r5, r28, 0x108
  lis       r3, 0x803D
  addi      r0, r3, 0x3420
  add       r31, r0, r5
  lwz       r30, 0xD0(r31)
  li        r0, 0
  stw       r0, 0xD0(r31)
  blt-      .loc_0x5C
  lhz       r4, 0xBE(r31)
  addi      r3, r28, 0
  addi      r5, r30, 0
  bl        -0x334C
  mr.       r29, r3
  bge-      .loc_0x84

.loc_0x5C:
  addi      r3, r31, 0
  addi      r4, r29, 0
  bl        -0x3BA8
  cmplwi    r30, 0
  beq-      .loc_0x84
  addi      r12, r30, 0
  mtlr      r12
  addi      r3, r28, 0
  addi      r4, r29, 0
  blrl      

.loc_0x84:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	8020CB08
 * Size:	000128
 */
void CARDFastDeleteAsync(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r5, 0
  stw       r29, 0x1C(r1)
  mr.       r29, r4
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  blt-      .loc_0x34
  cmpwi     r29, 0x7F
  blt-      .loc_0x3C

.loc_0x34:
  li        r3, -0x80
  b         .loc_0x108

.loc_0x3C:
  addi      r3, r28, 0
  addi      r4, r1, 0x14
  bl        -0x3CDC
  cmpwi     r3, 0
  bge-      .loc_0x54
  b         .loc_0x108

.loc_0x54:
  lwz       r3, 0x14(r1)
  bl        -0x32B0
  rlwinm    r0,r29,6,0,25
  add       r31, r3, r0
  addi      r3, r31, 0
  bl        -0x1088
  mr.       r4, r3
  bge-      .loc_0x80
  lwz       r3, 0x14(r1)
  bl        -0x3C60
  b         .loc_0x108

.loc_0x80:
  lwz       r3, 0x14(r1)
  mr        r4, r29
  bl        -0xCB0
  cmpwi     r3, 0
  beq-      .loc_0xA4
  lwz       r3, 0x14(r1)
  li        r4, -0x1
  bl        -0x3C84
  b         .loc_0x108

.loc_0xA4:
  lhz       r0, 0x36(r31)
  mr        r3, r31
  lwz       r6, 0x14(r1)
  li        r4, 0xFF
  li        r5, 0x40
  sth       r0, 0xBE(r6)
  bl        -0x2098A4
  cmplwi    r30, 0
  beq-      .loc_0xD0
  mr        r0, r30
  b         .loc_0xD8

.loc_0xD0:
  lis       r3, 0x8020
  addi      r0, r3, 0x7E60

.loc_0xD8:
  lwz       r5, 0x14(r1)
  lis       r3, 0x8021
  subi      r4, r3, 0x359C
  stw       r0, 0xD0(r5)
  mr        r3, r28
  bl        -0x31A4
  mr.       r31, r3
  bge-      .loc_0x104
  lwz       r3, 0x14(r1)
  mr        r4, r31
  bl        -0x3CE8

.loc_0x104:
  mr        r3, r31

.loc_0x108:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  mtlr      r0
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	8020CC30
 * Size:	000048
 */
void CARDFastDelete(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x8020
  stw       r0, 0x4(r1)
  addi      r5, r5, 0x7E64
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        -0x144
  cmpwi     r3, 0
  bge-      .loc_0x2C
  b         .loc_0x34

.loc_0x2C:
  mr        r3, r31
  bl        -0x3B34

.loc_0x34:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void CARDDeleteAsync(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void CARDDelete(void)
{
	// UNUSED FUNCTION
}