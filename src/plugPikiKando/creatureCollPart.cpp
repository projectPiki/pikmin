

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
 * Address:	8008E0BC
 * Size:	000004
 */
void CreatureCollPart::touchCallback(Plane &, Vector3f &, Vector3f &)
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8008E0C0
 * Size:	0000A0
 */
void CreaturePlatMgr::init(Creature *, MapMgr *, Shape *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  addi      r30, r5, 0
  stw       r29, 0x2C(r1)
  addi      r29, r4, 0
  stw       r28, 0x28(r1)
  addi      r28, r3, 0
  stw       r0, 0x44(r3)
  stw       r6, 0x0(r3)
  lwz       r3, 0x0(r3)
  lwz       r31, 0xF8(r3)
  b         .loc_0x78

.loc_0x40:
  lwz       r0, 0x48(r31)
  cmplwi    r0, 0
  beq-      .loc_0x74
  addi      r3, r30, 0
  addi      r4, r31, 0
  addi      r5, r29, 0
  bl        -0x24C84
  lwz       r4, 0x44(r28)
  addi      r0, r4, 0x1
  rlwinm    r4,r4,2,0,29
  stw       r0, 0x44(r28)
  addi      r0, r4, 0x4
  stwx      r3, r28, r0

.loc_0x74:
  lwz       r31, 0xC(r31)

.loc_0x78:
  cmplwi    r31, 0
  bne+      .loc_0x40
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  lwz       r28, 0x28(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8008E160
 * Size:	000068
 */
void CreaturePlatMgr::release()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  li        r30, 0
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  addi      r31, r29, 0
  b         .loc_0x38

.loc_0x28:
  lwz       r3, 0x4(r31)
  bl        -0x4DB7C
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0x38:
  lwz       r0, 0x44(r29)
  cmpw      r30, r0
  blt+      .loc_0x28
  li        r0, 0
  stw       r0, 0x44(r29)
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8008E1C8
 * Size:	0000FC
 */
void CreaturePlatMgr::update(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stmw      r27, 0x54(r1)
  addi      r28, r3, 0
  addi      r29, r4, 0
  addi      r31, r28, 0
  li        r30, 0
  b         .loc_0xDC

.loc_0x24:
  lwz       r27, 0x4(r31)
  addi      r3, r27, 0x5C
  addi      r4, r27, 0x9C
  bl        -0x4FDBC
  lwz       r3, 0x0(r28)
  lwz       r4, 0x144(r27)
  bl        -0x5921C
  lwz       r6, 0x0(r3)
  addi      r4, r1, 0x10
  lwz       r0, 0x4(r3)
  addi      r5, r27, 0x5C
  stw       r6, 0x10(r1)
  stw       r0, 0x14(r1)
  lwz       r6, 0x8(r3)
  lwz       r0, 0xC(r3)
  stw       r6, 0x18(r1)
  stw       r0, 0x1C(r1)
  lwz       r6, 0x10(r3)
  lwz       r0, 0x14(r3)
  stw       r6, 0x20(r1)
  stw       r0, 0x24(r1)
  lwz       r6, 0x18(r3)
  lwz       r0, 0x1C(r3)
  stw       r6, 0x28(r1)
  stw       r0, 0x2C(r1)
  lwz       r6, 0x20(r3)
  lwz       r0, 0x24(r3)
  stw       r6, 0x30(r1)
  stw       r0, 0x34(r1)
  lwz       r6, 0x28(r3)
  lwz       r0, 0x2C(r3)
  stw       r6, 0x38(r1)
  stw       r0, 0x3C(r1)
  lwz       r6, 0x30(r3)
  lwz       r0, 0x34(r3)
  stw       r6, 0x40(r1)
  stw       r0, 0x44(r1)
  lwz       r6, 0x38(r3)
  lwz       r0, 0x3C(r3)
  stw       r6, 0x48(r1)
  stw       r0, 0x4C(r1)
  lwz       r3, 0x2E4(r29)
  addi      r3, r3, 0x220
  bl        -0x501C4
  addi      r31, r31, 0x4
  addi      r30, r30, 0x1

.loc_0xDC:
  lwz       r0, 0x44(r28)
  cmpw      r30, r0
  blt+      .loc_0x24
  lmw       r27, 0x54(r1)
  lwz       r0, 0x6C(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8008E2C4
 * Size:	000004
 */
void CreatureCollPart::update()
{
/*
.loc_0x0:
  blr
*/
}

/*
 * --INFO--
 * Address:	8008E2C8
 * Size:	000004
 */
void CreatureCollPart::refresh(Graphics &)
{
/*
.loc_0x0:
  blr
*/
}