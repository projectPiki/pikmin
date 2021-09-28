

/*
 * --INFO--
 * Address:	8021BF4C
 * Size:	000028
 */
void TRKHandleRequestEvent(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x8(r3)
  bl        0x68C
  bl        0xF94
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021BF74
 * Size:	000020
 */
void TRKHandleSupportEvent(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x3A4C
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021BF94
 * Size:	00002C
 */
void TRKIdle(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x3B58
  cmpwi     r3, 0
  bne-      .loc_0x1C
  bl        0x480C

.loc_0x1C:
  addi      r1, r1, 0x8
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8021BFC0
 * Size:	0000F4
 */
void TRKNubMainLoop(void)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x803D
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0x5CE4
  stw       r30, 0x18(r1)
  li        r30, 0
  stw       r29, 0x14(r1)
  li        r29, 0
  b         .loc_0xD0

.loc_0x2C:
  addi      r3, r1, 0x8
  bl        0x144
  cmpwi     r3, 0
  beq-      .loc_0xA4
  lbz       r0, 0x8(r1)
  li        r29, 0
  cmpwi     r0, 0x2
  beq-      .loc_0x70
  bge-      .loc_0x60
  cmpwi     r0, 0
  beq-      .loc_0x98
  bge-      .loc_0x7C
  b         .loc_0x98

.loc_0x60:
  cmpwi     r0, 0x5
  beq-      .loc_0x90
  bge-      .loc_0x98
  b         .loc_0x84

.loc_0x70:
  addi      r3, r1, 0x8
  bl        -0xE8
  b         .loc_0x98

.loc_0x7C:
  li        r30, 0x1
  b         .loc_0x98

.loc_0x84:
  addi      r3, r1, 0x8
  bl        0x35D4
  b         .loc_0x98

.loc_0x90:
  addi      r3, r1, 0x8
  bl        -0xE0

.loc_0x98:
  addi      r3, r1, 0x8
  bl        0x290
  b         .loc_0xD0

.loc_0xA4:
  cmpwi     r29, 0
  beq-      .loc_0xBC
  lwz       r3, 0x0(r31)
  lbz       r0, 0x0(r3)
  cmplwi    r0, 0
  beq-      .loc_0xC8

.loc_0xBC:
  li        r29, 0x1
  bl        0xD64
  b         .loc_0xD0

.loc_0xC8:
  bl        -0xF4
  li        r29, 0

.loc_0xD0:
  cmpwi     r30, 0
  beq+      .loc_0x2C
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  lwz       r0, 0x4(r1)
  mtlr      r0
  blr
*/
}