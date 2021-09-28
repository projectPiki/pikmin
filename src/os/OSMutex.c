

/*
 * --INFO--
 * Address:	801F99B8
 * Size:	000038
 */
void OSInitMutex(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        0x2108
  li        r0, 0
  stw       r0, 0x8(r31)
  stw       r0, 0xC(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F99F0
 * Size:	0000DC
 */
void OSLockMutex(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  mr        r28, r3
  bl        -0xA94
  mr        r29, r3
  bl        0x20CC
  addi      r30, r3, 0
  li        r31, 0

.loc_0x34:
  lwz       r0, 0x8(r28)
  cmplwi    r0, 0
  bne-      .loc_0x7C
  stw       r30, 0x8(r28)
  lwz       r3, 0xC(r28)
  addi      r0, r3, 0x1
  stw       r0, 0xC(r28)
  lwz       r3, 0x2F8(r30)
  cmplwi    r3, 0
  bne-      .loc_0x64
  stw       r28, 0x2F4(r30)
  b         .loc_0x68

.loc_0x64:
  stw       r28, 0x10(r3)

.loc_0x68:
  stw       r3, 0x14(r28)
  li        r0, 0
  stw       r0, 0x10(r28)
  stw       r28, 0x2F8(r30)
  b         .loc_0xB4

.loc_0x7C:
  cmplw     r0, r30
  bne-      .loc_0x94
  lwz       r3, 0xC(r28)
  addi      r0, r3, 0x1
  stw       r0, 0xC(r28)
  b         .loc_0xB4

.loc_0x94:
  stw       r28, 0x2F0(r30)
  lwz       r3, 0x8(r28)
  lwz       r4, 0x2D0(r30)
  bl        0x2378
  mr        r3, r28
  bl        0x2F24
  stw       r31, 0x2F0(r30)
  b         .loc_0x34

.loc_0xB4:
  mr        r3, r29
  bl        -0xB04
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
 * Address:	801F9ACC
 * Size:	0000C8
 */
void OSUnlockMutex(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  mr        r29, r3
  bl        -0xB6C
  mr        r31, r3
  bl        0x1FF4
  lwz       r0, 0x8(r29)
  addi      r30, r3, 0
  cmplw     r0, r30
  bne-      .loc_0xA4
  lwz       r3, 0xC(r29)
  subic.    r0, r3, 0x1
  stw       r0, 0xC(r29)
  bne-      .loc_0xA4
  lwz       r3, 0x10(r29)
  lwz       r4, 0x14(r29)
  cmplwi    r3, 0
  bne-      .loc_0x60
  stw       r4, 0x2F8(r30)
  b         .loc_0x64

.loc_0x60:
  stw       r4, 0x14(r3)

.loc_0x64:
  cmplwi    r4, 0
  bne-      .loc_0x74
  stw       r3, 0x2F4(r30)
  b         .loc_0x78

.loc_0x74:
  stw       r3, 0x10(r4)

.loc_0x78:
  li        r0, 0
  stw       r0, 0x8(r29)
  lwz       r3, 0x2D0(r30)
  lwz       r0, 0x2D4(r30)
  cmpw      r3, r0
  bge-      .loc_0x9C
  mr        r3, r30
  bl        0x20AC
  stw       r3, 0x2D0(r30)

.loc_0x9C:
  mr        r3, r29
  bl        0x2F3C

.loc_0xA4:
  mr        r3, r31
  bl        -0xBD0
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  mtlr      r0
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	801F9B94
 * Size:	000070
 */
void __OSUnlockAllMutex(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  li        r31, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  b         .loc_0x4C

.loc_0x20:
  lwz       r5, 0x10(r4)
  addi      r3, r4, 0
  cmplwi    r5, 0
  bne-      .loc_0x38
  stw       r31, 0x2F8(r30)
  b         .loc_0x3C

.loc_0x38:
  stw       r31, 0x14(r5)

.loc_0x3C:
  stw       r5, 0x2F4(r30)
  stw       r31, 0xC(r4)
  stw       r31, 0x8(r4)
  bl        0x2ECC

.loc_0x4C:
  lwz       r4, 0x2F4(r30)
  cmplwi    r4, 0
  bne+      .loc_0x20
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void OSTryLockMutex(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F9C04
 * Size:	000020
 */
void OSInitCond(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x1EC4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F9C24
 * Size:	0000D4
 */
void OSWaitCond(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stmw      r27, 0x14(r1)
  addi      r27, r3, 0
  addi      r28, r4, 0
  bl        -0xCC0
  mr        r31, r3
  bl        0x1EA0
  lwz       r0, 0x8(r28)
  addi      r30, r3, 0
  cmplw     r0, r30
  bne-      .loc_0xB8
  lwz       r29, 0xC(r28)
  li        r0, 0
  stw       r0, 0xC(r28)
  lwz       r3, 0x10(r28)
  lwz       r4, 0x14(r28)
  cmplwi    r3, 0
  bne-      .loc_0x58
  stw       r4, 0x2F8(r30)
  b         .loc_0x5C

.loc_0x58:
  stw       r4, 0x14(r3)

.loc_0x5C:
  cmplwi    r4, 0
  bne-      .loc_0x6C
  stw       r3, 0x2F4(r30)
  b         .loc_0x70

.loc_0x6C:
  stw       r3, 0x10(r4)

.loc_0x70:
  li        r0, 0
  stw       r0, 0x8(r28)
  lwz       r3, 0x2D0(r30)
  lwz       r0, 0x2D4(r30)
  cmpw      r3, r0
  bge-      .loc_0x94
  mr        r3, r30
  bl        0x1F5C
  stw       r3, 0x2D0(r30)

.loc_0x94:
  bl        0x1E6C
  mr        r3, r28
  bl        0x2DE8
  bl        0x1EA0
  mr        r3, r27
  bl        0x2CF0
  mr        r3, r28
  bl        -0x2E4
  stw       r29, 0xC(r28)

.loc_0xB8:
  mr        r3, r31
  bl        -0xD3C
  lmw       r27, 0x14(r1)
  lwz       r0, 0x2C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F9CF8
 * Size:	000020
 */
void OSSignalCond(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        0x2DA4
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void IsMember(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801F9D18
 * Size:	000100
 */
void __OSCheckMutex(void)
{
/*
.loc_0x0:
  lwz       r4, 0x0(r3)
  li        r7, 0
  cmplwi    r4, 0
  beq-      .loc_0x24
  lwz       r0, 0x2E4(r4)
  cmplwi    r0, 0
  beq-      .loc_0x24
  li        r3, 0
  blr       

.loc_0x24:
  lwz       r5, 0x4(r3)
  cmplwi    r5, 0
  beq-      .loc_0x44
  lwz       r0, 0x2E0(r5)
  cmplwi    r0, 0
  beq-      .loc_0x44
  li        r3, 0
  blr       

.loc_0x44:
  mr        r6, r4
  b         .loc_0xBC

.loc_0x4C:
  lwz       r4, 0x2E0(r6)
  cmplwi    r4, 0
  beq-      .loc_0x6C
  lwz       r0, 0x2E4(r4)
  cmplw     r6, r0
  beq-      .loc_0x6C
  li        r3, 0
  blr       

.loc_0x6C:
  lwz       r5, 0x2E4(r6)
  cmplwi    r5, 0
  beq-      .loc_0x8C
  lwz       r0, 0x2E0(r5)
  cmplw     r6, r0
  beq-      .loc_0x8C
  li        r3, 0
  blr       

.loc_0x8C:
  lhz       r0, 0x2C8(r6)
  cmplwi    r0, 0x4
  beq-      .loc_0xA0
  li        r3, 0
  blr       

.loc_0xA0:
  lwz       r0, 0x2D0(r6)
  cmpw      r0, r7
  bge-      .loc_0xB4
  li        r3, 0
  blr       

.loc_0xB4:
  mr        r7, r0
  addi      r6, r4, 0

.loc_0xBC:
  cmplwi    r6, 0
  bne+      .loc_0x4C
  lwz       r0, 0x8(r3)
  cmplwi    r0, 0
  beq-      .loc_0xE4
  lwz       r0, 0xC(r3)
  cmpwi     r0, 0
  bgt-      .loc_0xF8
  li        r3, 0
  blr       

.loc_0xE4:
  lwz       r0, 0xC(r3)
  cmpwi     r0, 0
  beq-      .loc_0xF8
  li        r3, 0
  blr       

.loc_0xF8:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	801F9E18
 * Size:	000038
 */
void __OSCheckDeadLock(void)
{
/*
.loc_0x0:
  lwz       r4, 0x2F0(r3)
  b         .loc_0x1C

.loc_0x8:
  cmplw     r4, r3
  bne-      .loc_0x18
  li        r3, 0x1
  blr       

.loc_0x18:
  lwz       r4, 0x2F0(r4)

.loc_0x1C:
  cmplwi    r4, 0
  beq-      .loc_0x30
  lwz       r4, 0x8(r4)
  cmplwi    r4, 0
  bne+      .loc_0x8

.loc_0x30:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	801F9E50
 * Size:	000074
 */
void __OSCheckMutexes(void)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r31, 0x2F4(r3)
  b         .loc_0x50

.loc_0x20:
  lwz       r0, 0x8(r31)
  cmplw     r0, r30
  beq-      .loc_0x34
  li        r3, 0
  b         .loc_0x5C

.loc_0x34:
  mr        r3, r31
  bl        -0x170
  cmpwi     r3, 0
  bne-      .loc_0x4C
  li        r3, 0
  b         .loc_0x5C

.loc_0x4C:
  lwz       r31, 0x10(r31)

.loc_0x50:
  cmplwi    r31, 0
  bne+      .loc_0x20
  li        r3, 0x1

.loc_0x5C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  mtlr      r0
  addi      r1, r1, 0x18
  blr
*/
}