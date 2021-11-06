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
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A5710
 * Size:	000014
 */
void CPlate::getCreature(int)
{
/*
.loc_0x0:
  rlwinm    r4,r4,5,0,26
  lwz       r3, 0x80(r3)
  addi      r0, r4, 0x18
  lwzx      r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A5724
 * Size:	00022C
 */
CPlate::CPlate(MapMgr *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r4, 0x2374
  subi      r4, r13, 0x51B8
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  li        r31, 0
  stw       r30, 0x50(r1)
  addi      r30, r3, 0
  stw       r29, 0x4C(r1)
  stw       r0, 0x0(r3)
  lis       r3, 0x8022
  addi      r0, r3, 0x738C
  stw       r31, 0x4(r30)
  lis       r3, 0x8022
  stw       r0, 0x8(r30)
  addi      r0, r3, 0x737C
  addi      r3, r30, 0x8
  stw       r0, 0x8(r30)
  stw       r31, 0x18(r30)
  stw       r31, 0x14(r30)
  stw       r31, 0x10(r30)
  bl        -0x808AC
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x8(r30)
  addi      r3, r30, 0x8
  subi      r4, r13, 0x51B8
  bl        -0x6505C
  lis       r3, 0x802B
  addi      r3, r3, 0x4EA4
  stw       r3, 0x0(r30)
  addi      r0, r3, 0x18
  addi      r5, r1, 0x2C
  stw       r0, 0x8(r30)
  addi      r3, r30, 0x2C
  addi      r4, r30, 0x28
  stw       r31, 0x28(r30)
  lwz       r0, -0x51B0(r13)
  stw       r0, 0x34(r1)
  lwz       r0, 0x34(r1)
  stw       r0, 0x2C(r1)
  bl        -0x46D50
  lis       r3, 0x802A
  addi      r29, r3, 0x6098
  stw       r29, 0x34(r30)
  addi      r5, r1, 0x28
  addi      r3, r30, 0x3C
  lfs       f0, -0x7240(r2)
  addi      r4, r30, 0x28
  stfs      f0, 0x38(r30)
  lwz       r0, -0x51AC(r13)
  stw       r0, 0x3C(r1)
  lwz       r0, 0x3C(r1)
  stw       r0, 0x28(r1)
  bl        -0x46D84
  stw       r29, 0x44(r30)
  addi      r5, r1, 0x24
  addi      r3, r30, 0x4C
  lfs       f0, -0x723C(r2)
  addi      r4, r30, 0x28
  stfs      f0, 0x48(r30)
  lwz       r0, -0x51A8(r13)
  stw       r0, 0x44(r1)
  lwz       r0, 0x44(r1)
  stw       r0, 0x24(r1)
  bl        -0x46DB0
  stw       r29, 0x54(r30)
  li        r0, 0x6E
  lfs       f0, -0x7238(r2)
  stfs      f0, 0x58(r30)
  lfs       f1, -0x7234(r2)
  stfs      f1, 0x64(r30)
  stfs      f1, 0x60(r30)
  stfs      f1, 0x5C(r30)
  stfs      f1, 0x90(r30)
  stfs      f1, 0x8C(r30)
  stfs      f1, 0x88(r30)
  stfs      f1, 0x9C(r30)
  stfs      f1, 0x98(r30)
  stfs      f1, 0x94(r30)
  stfs      f1, 0xA8(r30)
  stfs      f1, 0xA4(r30)
  stfs      f1, 0xA0(r30)
  stfs      f1, 0xB8(r30)
  stfs      f1, 0xB4(r30)
  stfs      f1, 0xB0(r30)
  stw       r0, 0x84(r30)
  lfs       f0, -0x7230(r2)
  stfs      f0, 0x6C(r30)
  stfs      f0, 0x68(r30)
  lfs       f0, -0x51D0(r13)
  stfs      f0, 0x88(r30)
  lfs       f0, -0x51CC(r13)
  stfs      f0, 0x8C(r30)
  lfs       f0, -0x51C8(r13)
  stfs      f0, 0x90(r30)
  stfs      f1, 0xAC(r30)
  lwz       r29, 0x84(r30)
  rlwinm    r3,r29,5,0,26
  addi      r3, r3, 0x8
  bl        -0x5E8B8
  lis       r4, 0x800A
  addi      r4, r4, 0x5950
  addi      r7, r29, 0
  li        r5, 0
  li        r6, 0x20
  bl        0x16F354
  stw       r3, 0x80(r30)
  lis       r3, 0x802B
  addi      r5, r3, 0x4E3C
  stw       r31, 0x74(r30)
  li        r0, 0x1
  addi      r3, r30, 0x8
  stw       r31, 0x78(r30)
  subi      r4, r13, 0x51A4
  li        r6, 0x1
  stw       r31, 0x7C(r30)
  stb       r31, 0xC8(r30)
  stb       r0, 0xC9(r30)
  bl        -0x65268
  lfs       f0, -0x51C4(r13)
  mr        r3, r30
  stfs      f0, 0xB0(r30)
  lfs       f0, -0x51C0(r13)
  stfs      f0, 0xB4(r30)
  lfs       f0, -0x51BC(r13)
  stfs      f0, 0xB8(r30)
  stw       r31, 0xC4(r30)
  stw       r31, 0xC0(r30)
  stw       r31, 0xBC(r30)
  lwz       r0, 0x5C(r1)
  lwz       r31, 0x54(r1)
  lwz       r30, 0x50(r1)
  lwz       r29, 0x4C(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A5950
 * Size:	000030
 */
CPlate::Slot::Slot()
{
/*
.loc_0x0:
  lfs       f0, -0x7234(r2)
  li        r0, 0
  stfs      f0, 0x8(r3)
  stfs      f0, 0x4(r3)
  stfs      f0, 0x0(r3)
  stfs      f0, 0x14(r3)
  stfs      f0, 0x10(r3)
  stfs      f0, 0xC(r3)
  stw       r0, 0x18(r3)
  stw       r0, 0x18(r3)
  stw       r0, 0x1C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A5980
 * Size:	000008
 */
u32  CPlate::canNaviRunFast()
{
	return 0x1;
}

/*
 * --INFO--
 * Address:	800A5988
 * Size:	000004
 */
void CPlate::init(Vector3f &)
{
}

/*
 * --INFO--
 * Address:	800A598C
 * Size:	0001C0
 */
void CPlate::setPos(Vector3f &, float, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stfd      f31, 0xD8(r1)
  fmr       f31, f1
  stfd      f30, 0xD0(r1)
  stfd      f29, 0xC8(r1)
  stw       r31, 0xC4(r1)
  mr        r31, r5
  stw       r30, 0xC0(r1)
  mr        r30, r4
  stw       r29, 0xBC(r1)
  mr        r29, r3
  lfs       f2, 0xA0(r3)
  lfs       f1, 0xA8(r3)
  fmuls     f2, f2, f2
  lfs       f0, -0x7234(r2)
  fmuls     f1, f1, f1
  lfs       f3, 0x38(r3)
  fadds     f1, f2, f1
  fcmpo     cr0, f1, f0
  ble-      .loc_0x6C
  fsqrte    f0, f1
  fmul      f0, f1, f0
  frsp      f0, f0
  stfs      f0, 0x74(r1)
  lfs       f1, 0x74(r1)

.loc_0x6C:
  lfs       f0, -0x722C(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x7C
  lfs       f3, -0x7234(r2)

.loc_0x7C:
  lfs       f0, 0x68(r29)
  fmr       f1, f31
  stfs      f31, 0xAC(r29)
  fadds     f29, f0, f3
  lwz       r3, 0x0(r30)
  lwz       r0, 0x4(r30)
  stw       r3, 0x88(r29)
  stw       r0, 0x8C(r29)
  lwz       r0, 0x8(r30)
  stw       r0, 0x90(r29)
  bl        0x176124
  fmuls     f30, f29, f1
  fmr       f1, f31
  bl        0x1762AC
  fmuls     f2, f29, f1
  lfs       f0, -0x519C(r13)
  fmr       f1, f31
  stfs      f2, 0x94(r1)
  lfs       f3, 0x88(r29)
  lfs       f2, 0x94(r1)
  fadds     f2, f3, f2
  stfs      f2, 0x68(r1)
  lfs       f2, 0x68(r1)
  stfs      f2, 0xA4(r1)
  lfs       f2, 0x8C(r29)
  fadds     f0, f2, f0
  stfs      f0, 0xA8(r1)
  lfs       f0, 0x90(r29)
  fadds     f0, f0, f30
  stfs      f0, 0xAC(r1)
  lwz       r3, 0xA4(r1)
  lwz       r0, 0xA8(r1)
  stw       r3, 0x94(r29)
  stw       r0, 0x98(r29)
  lwz       r0, 0xAC(r1)
  stw       r0, 0x9C(r29)
  lwz       r3, 0x0(r31)
  lwz       r0, 0x4(r31)
  stw       r3, 0xA0(r29)
  stw       r0, 0xA4(r29)
  lwz       r0, 0x8(r31)
  stw       r0, 0xA8(r29)
  bl        0x1760A4
  lfs       f0, 0x70(r29)
  fmuls     f30, f0, f1
  fmr       f1, f31
  bl        0x176228
  lfs       f2, 0x70(r29)
  li        r0, 0
  lfs       f0, -0x5198(r13)
  fmuls     f1, f2, f1
  stfs      f1, 0x78(r1)
  lfs       f2, 0x0(r30)
  lfs       f1, 0x78(r1)
  fadds     f1, f2, f1
  stfs      f1, 0x5C(r1)
  lfs       f1, 0x5C(r1)
  stfs      f1, 0x88(r1)
  lfs       f1, 0x4(r30)
  fadds     f0, f1, f0
  stfs      f0, 0x8C(r1)
  lfs       f0, 0x8(r30)
  fadds     f0, f0, f30
  stfs      f0, 0x90(r1)
  lwz       r4, 0x88(r1)
  lwz       r3, 0x8C(r1)
  stw       r4, 0x5C(r29)
  stw       r3, 0x60(r29)
  lwz       r3, 0x90(r1)
  stw       r3, 0x64(r29)
  stb       r0, 0xC9(r29)
  lwz       r0, 0xE4(r1)
  lfd       f31, 0xD8(r1)
  lfd       f30, 0xD0(r1)
  lfd       f29, 0xC8(r1)
  lwz       r31, 0xC4(r1)
  lwz       r30, 0xC0(r1)
  lwz       r29, 0xBC(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A5B4C
 * Size:	0001BC
 */
void CPlate::setPosGray(Vector3f &, float, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stfd      f31, 0xD8(r1)
  fmr       f31, f1
  stfd      f30, 0xD0(r1)
  stfd      f29, 0xC8(r1)
  stw       r31, 0xC4(r1)
  mr        r31, r5
  stw       r30, 0xC0(r1)
  mr        r30, r4
  stw       r29, 0xBC(r1)
  mr        r29, r3
  lfs       f2, 0xA0(r3)
  lfs       f1, 0xA8(r3)
  fmuls     f2, f2, f2
  lfs       f0, -0x7234(r2)
  fmuls     f1, f1, f1
  lfs       f3, 0x38(r3)
  fadds     f1, f2, f1
  fcmpo     cr0, f1, f0
  ble-      .loc_0x6C
  fsqrte    f0, f1
  fmul      f0, f1, f0
  frsp      f0, f0
  stfs      f0, 0x74(r1)
  lfs       f1, 0x74(r1)

.loc_0x6C:
  lfs       f0, -0x722C(r2)
  fcmpo     cr0, f1, f0
  ble-      .loc_0x7C
  lfs       f3, -0x7234(r2)

.loc_0x7C:
  lfs       f0, 0x68(r29)
  fmr       f1, f31
  lwz       r3, 0x0(r30)
  lwz       r0, 0x4(r30)
  fadds     f29, f0, f3
  stw       r3, 0x88(r29)
  stw       r0, 0x8C(r29)
  lwz       r0, 0x8(r30)
  stw       r0, 0x90(r29)
  bl        0x175F68
  fmuls     f30, f29, f1
  fmr       f1, f31
  bl        0x1760F0
  fmuls     f2, f29, f1
  lfs       f0, -0x5194(r13)
  fmr       f1, f31
  stfs      f2, 0x94(r1)
  lfs       f3, 0x88(r29)
  lfs       f2, 0x94(r1)
  fadds     f2, f3, f2
  stfs      f2, 0x68(r1)
  lfs       f2, 0x68(r1)
  stfs      f2, 0xA4(r1)
  lfs       f2, 0x8C(r29)
  fadds     f0, f2, f0
  stfs      f0, 0xA8(r1)
  lfs       f0, 0x90(r29)
  fadds     f0, f0, f30
  stfs      f0, 0xAC(r1)
  lwz       r3, 0xA4(r1)
  lwz       r0, 0xA8(r1)
  stw       r3, 0x94(r29)
  stw       r0, 0x98(r29)
  lwz       r0, 0xAC(r1)
  stw       r0, 0x9C(r29)
  lwz       r3, 0x0(r31)
  lwz       r0, 0x4(r31)
  stw       r3, 0xA0(r29)
  stw       r0, 0xA4(r29)
  lwz       r0, 0x8(r31)
  stw       r0, 0xA8(r29)
  bl        0x175EE8
  lfs       f0, 0x70(r29)
  fmuls     f30, f0, f1
  fmr       f1, f31
  bl        0x17606C
  lfs       f2, 0x70(r29)
  li        r0, 0
  lfs       f0, -0x5190(r13)
  fmuls     f1, f2, f1
  stfs      f1, 0x78(r1)
  lfs       f2, 0x0(r30)
  lfs       f1, 0x78(r1)
  fadds     f1, f2, f1
  stfs      f1, 0x5C(r1)
  lfs       f1, 0x5C(r1)
  stfs      f1, 0x88(r1)
  lfs       f1, 0x4(r30)
  fadds     f0, f1, f0
  stfs      f0, 0x8C(r1)
  lfs       f0, 0x8(r30)
  fadds     f0, f0, f30
  stfs      f0, 0x90(r1)
  lwz       r4, 0x88(r1)
  lwz       r3, 0x8C(r1)
  stw       r4, 0x5C(r29)
  stw       r3, 0x60(r29)
  lwz       r3, 0x90(r1)
  stw       r3, 0x64(r29)
  stb       r0, 0xC9(r29)
  lwz       r0, 0xE4(r1)
  lfd       f31, 0xD8(r1)
  lfd       f30, 0xD0(r1)
  lfd       f29, 0xC8(r1)
  lwz       r31, 0xC4(r1)
  lwz       r30, 0xC0(r1)
  lwz       r29, 0xBC(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E0
 */
void CPlate::setPosNeutral(Vector3f &, float, Vector3f &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A5D08
 * Size:	0000B0
 */
void CPlate::getSlot(Creature *, SlotChangeListner *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stmw      r27, 0x1C(r1)
  addi      r30, r3, 0
  mr        r27, r4
  addi      r31, r5, 0
  lwz       r0, 0x520(r4)
  rlwinm    r0,r0,2,0,29
  add       r4, r30, r0
  lwz       r3, 0xBC(r4)
  addi      r0, r3, 0x1
  stw       r0, 0xBC(r4)
  lwz       r4, 0x7C(r30)
  lwz       r0, 0x80(r30)
  rlwinm    r3,r4,5,0,26
  addi      r29, r3, 0x18
  add       r29, r0, r29
  lwz       r3, 0x0(r29)
  addi      r28, r4, 0
  cmplwi    r3, 0
  beq-      .loc_0x68
  beq-      .loc_0x68
  bl        0x3E608
  li        r0, 0
  stw       r0, 0x0(r29)

.loc_0x68:
  stw       r27, 0x0(r29)
  lwz       r3, 0x0(r29)
  cmplwi    r3, 0
  beq-      .loc_0x7C
  bl        0x3E5DC

.loc_0x7C:
  lwz       r4, 0x80(r30)
  rlwinm    r0,r28,5,0,26
  addi      r3, r28, 0
  add       r4, r4, r0
  stw       r31, 0x1C(r4)
  lwz       r4, 0x7C(r30)
  addi      r0, r4, 0x1
  stw       r0, 0x7C(r30)
  lwz       r0, 0x34(r1)
  lmw       r27, 0x1C(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A5DB8
 * Size:	000050
 */
void CPlate::changeFlower(Piki *)
{
/*
.loc_0x0:
  lwz       r5, 0x520(r4)
  lis       r4, 0x5555
  addi      r0, r4, 0x5556
  addi      r7, r5, 0x2
  mulhw     r4, r0, r7
  rlwinm    r0,r4,1,31,31
  add       r4, r4, r0
  rlwinm    r0,r5,2,0,29
  mulli     r6, r4, 0x3
  add       r5, r3, r0
  lwz       r4, 0xBC(r5)
  sub       r0, r7, r6
  rlwinm    r0,r0,2,0,29
  addi      r4, r4, 0x1
  stw       r4, 0xBC(r5)
  add       r4, r3, r0
  lwz       r3, 0xBC(r4)
  subi      r0, r3, 0x1
  stw       r0, 0xBC(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	800A5E08
 * Size:	000144
 */
void CPlate::releaseSlot(Creature *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stmw      r27, 0x2C(r1)
  rlwinm    r31,r5,5,0,26
  addi      r29, r3, 0
  addi      r27, r5, 0
  lwz       r0, 0x80(r3)
  add       r28, r0, r31
  lwz       r0, 0x18(r28)
  cmplw     r0, r4
  lwz       r0, 0x520(r4)
  rlwinm    r0,r0,2,0,29
  add       r4, r29, r0
  lwz       r3, 0xBC(r4)
  subi      r0, r3, 0x1
  stw       r0, 0xBC(r4)
  lwz       r3, 0x18(r28)
  cmplwi    r3, 0
  beq-      .loc_0x5C
  bl        0x3E514
  li        r0, 0
  stw       r0, 0x18(r28)

.loc_0x5C:
  lwz       r3, 0x7C(r29)
  addi      r30, r27, 0
  subi      r0, r3, 0x1
  stw       r0, 0x7C(r29)
  lwz       r3, 0x74(r29)
  subi      r0, r3, 0x1
  stw       r0, 0x74(r29)
  b         .loc_0x124

.loc_0x7C:
  lwz       r0, 0x80(r29)
  addi      r28, r31, 0x18
  add       r28, r0, r28
  lwz       r3, 0x0(r28)
  cmplwi    r3, 0
  beq-      .loc_0xA0
  bl        0x3E4D0
  li        r0, 0
  stw       r0, 0x0(r28)

.loc_0xA0:
  lwz       r5, 0x80(r29)
  addi      r27, r31, 0x18
  addi      r0, r30, 0x1
  add       r27, r5, r27
  lwz       r3, 0x0(r27)
  rlwinm    r4,r0,5,0,26
  addi      r0, r4, 0x18
  cmplwi    r3, 0
  lwzx      r28, r5, r0
  beq-      .loc_0xD8
  beq-      .loc_0xD8
  bl        0x3E498
  li        r0, 0
  stw       r0, 0x0(r27)

.loc_0xD8:
  stw       r28, 0x0(r27)
  lwz       r3, 0x0(r27)
  cmplwi    r3, 0
  beq-      .loc_0xEC
  bl        0x3E46C

.loc_0xEC:
  lwz       r3, 0x80(r29)
  addi      r0, r31, 0x1C
  addi      r4, r30, 0
  add       r5, r3, r31
  lwz       r3, 0x3C(r5)
  stw       r3, 0x1C(r5)
  lwz       r3, 0x80(r29)
  lwzx      r3, r3, r0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r31, r31, 0x20
  addi      r30, r30, 0x1

.loc_0x124:
  lwz       r0, 0x7C(r29)
  cmpw      r30, r0
  blt+      .loc_0x7C
  lmw       r27, 0x2C(r1)
  lwz       r0, 0x44(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
void CPlate::swapSlot(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A5F4C
 * Size:	000024
 */
void CPlate::validSlot(int)
{
/*
.loc_0x0:
  cmpwi     r4, 0
  blt-      .loc_0x14
  lwz       r0, 0x7C(r3)
  cmpw      r4, r0
  blt-      .loc_0x1C

.loc_0x14:
  li        r3, 0
  blr       

.loc_0x1C:
  li        r3, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	800A5F70
 * Size:	000424
 */
void CPlate::sortByColor(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB0(r1)
  stmw      r16, 0x70(r1)
  addi      r16, r4, 0
  addi      r24, r3, 0
  addi      r3, r16, 0
  bl        0x21EE4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x30
  li        r0, 0x1
  b         .loc_0x34

.loc_0x30:
  li        r0, 0

.loc_0x34:
  lhz       r29, 0x510(r16)
  lis       r3, 0x5555
  neg       r5, r0
  lwz       r27, 0x520(r16)
  addi      r4, r29, 0x1
  addi      r0, r3, 0x5556
  mulhw     r3, r0, r4
  rlwinm    r0,r3,1,31,31
  add       r0, r3, r0
  mulli     r0, r0, 0x3
  subic     r3, r5, 0x1
  subfe     r3, r3, r5
  rlwinm    r23,r3,0,24,31
  sub       r28, r4, r0
  li        r26, 0
  li        r30, 0
  b         .loc_0x404

.loc_0x78:
  li        r25, 0
  li        r31, 0
  b         .loc_0x3F0

.loc_0x84:
  lwz       r5, 0x80(r24)
  addi      r0, r5, 0x18
  lwzx      r3, r30, r0
  add       r22, r5, r31
  lwz       r4, 0x18(r22)
  lhz       r0, 0x510(r3)
  mr        r16, r3
  lhz       r3, 0x510(r4)
  addi      r17, r4, 0
  cmpw      r0, r3
  beq-      .loc_0x20C
  cmpw      r0, r29
  bne-      .loc_0xC0
  li        r0, 0x1
  b         .loc_0xD4

.loc_0xC0:
  cmpw      r0, r28
  bne-      .loc_0xD0
  li        r0, 0x2
  b         .loc_0xD4

.loc_0xD0:
  li        r0, 0x3

.loc_0xD4:
  cmpw      r3, r29
  bne-      .loc_0xE4
  li        r3, 0x1
  b         .loc_0xF8

.loc_0xE4:
  cmpw      r3, r28
  bne-      .loc_0xF4
  li        r3, 0x2
  b         .loc_0xF8

.loc_0xF4:
  li        r3, 0x3

.loc_0xF8:
  cmpw      r25, r26
  ble-      .loc_0x3E8
  cmpw      r3, r0
  bge-      .loc_0x3E8
  lwz       r21, 0x18(r22)
  add       r18, r5, r30
  lwz       r19, 0x1C(r22)
  addi      r17, r22, 0x18
  cmplwi    r21, 0
  lwz       r16, 0x18(r18)
  lwz       r20, 0x1C(r18)
  beq-      .loc_0x138
  lwz       r3, 0x0(r17)
  bl        0x3E2D0
  li        r0, 0
  stw       r0, 0x0(r17)

.loc_0x138:
  lwz       r0, 0x18(r22)
  addi      r17, r22, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x160
  lwz       r3, 0x0(r17)
  cmplwi    r3, 0
  beq-      .loc_0x160
  bl        0x3E2A8
  li        r0, 0
  stw       r0, 0x0(r17)

.loc_0x160:
  stw       r16, 0x0(r17)
  lwz       r3, 0x0(r17)
  cmplwi    r3, 0
  beq-      .loc_0x174
  bl        0x3E27C

.loc_0x174:
  stw       r20, 0x1C(r22)
  mr        r4, r25
  lwz       r3, 0x1C(r22)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x18(r18)
  addi      r16, r18, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x1B0
  lwz       r3, 0x0(r16)
  bl        0x3E258
  li        r0, 0
  stw       r0, 0x0(r16)

.loc_0x1B0:
  lwz       r0, 0x18(r18)
  addi      r16, r18, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x1D8
  lwz       r3, 0x0(r16)
  cmplwi    r3, 0
  beq-      .loc_0x1D8
  bl        0x3E230
  li        r0, 0
  stw       r0, 0x0(r16)

.loc_0x1D8:
  stw       r21, 0x0(r16)
  lwz       r3, 0x0(r16)
  cmplwi    r3, 0
  beq-      .loc_0x1EC
  bl        0x3E204

.loc_0x1EC:
  stw       r19, 0x1C(r18)
  mr        r4, r26
  lwz       r3, 0x1C(r18)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x3E8

.loc_0x20C:
  cmplwi    r23, 0
  beq-      .loc_0x258
  mr        r3, r16
  bl        0x21CE8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x22C
  li        r0, 0
  b         .loc_0x230

.loc_0x22C:
  li        r0, 0x1

.loc_0x230:
  mr        r18, r0
  addi      r3, r17, 0
  bl        0x21CC8
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x24C
  li        r0, 0
  b         .loc_0x250

.loc_0x24C:
  li        r0, 0x1

.loc_0x250:
  mr        r4, r0
  b         .loc_0x298

.loc_0x258:
  mr        r3, r16
  bl        0x21CA4
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x270
  li        r0, 0x1
  b         .loc_0x274

.loc_0x270:
  li        r0, 0

.loc_0x274:
  mr        r18, r0
  addi      r3, r17, 0
  bl        0x21C84
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x290
  li        r0, 0x1
  b         .loc_0x294

.loc_0x290:
  li        r0, 0

.loc_0x294:
  mr        r4, r0

.loc_0x298:
  lwz       r0, 0x520(r16)
  cmpw      r27, r0
  bne-      .loc_0x2AC
  li        r3, 0
  b         .loc_0x2B0

.loc_0x2AC:
  li        r3, 0x1

.loc_0x2B0:
  lwz       r0, 0x520(r17)
  add       r18, r18, r3
  cmpw      r27, r0
  bne-      .loc_0x2C8
  li        r0, 0
  b         .loc_0x2CC

.loc_0x2C8:
  li        r0, 0x1

.loc_0x2CC:
  cmpw      r25, r26
  add       r4, r4, r0
  ble-      .loc_0x3E8
  cmpw      r4, r18
  bge-      .loc_0x3E8
  lwz       r0, 0x80(r24)
  add       r22, r0, r31
  lwz       r21, 0x18(r22)
  add       r20, r0, r30
  lwz       r19, 0x1C(r22)
  addi      r17, r22, 0x18
  cmplwi    r21, 0
  lwz       r16, 0x18(r20)
  lwz       r18, 0x1C(r20)
  beq-      .loc_0x318
  lwz       r3, 0x0(r17)
  bl        0x3E0F0
  li        r0, 0
  stw       r0, 0x0(r17)

.loc_0x318:
  lwz       r0, 0x18(r22)
  addi      r17, r22, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x340
  lwz       r3, 0x0(r17)
  cmplwi    r3, 0
  beq-      .loc_0x340
  bl        0x3E0C8
  li        r0, 0
  stw       r0, 0x0(r17)

.loc_0x340:
  stw       r16, 0x0(r17)
  lwz       r3, 0x0(r17)
  cmplwi    r3, 0
  beq-      .loc_0x354
  bl        0x3E09C

.loc_0x354:
  stw       r18, 0x1C(r22)
  mr        r4, r25
  lwz       r3, 0x1C(r22)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x18(r20)
  addi      r16, r20, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x390
  lwz       r3, 0x0(r16)
  bl        0x3E078
  li        r0, 0
  stw       r0, 0x0(r16)

.loc_0x390:
  lwz       r0, 0x18(r20)
  addi      r16, r20, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x3B8
  lwz       r3, 0x0(r16)
  cmplwi    r3, 0
  beq-      .loc_0x3B8
  bl        0x3E050
  li        r0, 0
  stw       r0, 0x0(r16)

.loc_0x3B8:
  stw       r21, 0x0(r16)
  lwz       r3, 0x0(r16)
  cmplwi    r3, 0
  beq-      .loc_0x3CC
  bl        0x3E024

.loc_0x3CC:
  stw       r19, 0x1C(r20)
  mr        r4, r26
  lwz       r3, 0x1C(r20)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x3E8:
  addi      r31, r31, 0x20
  addi      r25, r25, 0x1

.loc_0x3F0:
  lwz       r0, 0x7C(r24)
  cmpw      r25, r0
  blt+      .loc_0x84
  addi      r30, r30, 0x20
  addi      r26, r26, 0x1

.loc_0x404:
  lwz       r0, 0x7C(r24)
  cmpw      r26, r0
  blt+      .loc_0x78
  lmw       r16, 0x70(r1)
  lwz       r0, 0xB4(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A6394
 * Size:	0002DC
 */
void CPlate::rearrangeSlot(Vector3f &, float, Vector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stfd      f31, 0xD8(r1)
  stfd      f30, 0xD0(r1)
  stfd      f29, 0xC8(r1)
  stmw      r20, 0x98(r1)
  mr        r24, r3
  mr        r25, r4
  lwz       r3, 0x7C(r3)
  lfs       f29, -0x7234(r2)
  lfd       f30, -0x7228(r2)
  subi      r27, r3, 0x1
  lfd       f31, -0x7220(r2)
  b         .loc_0x2B4

.loc_0x3C:
  addi      r26, r27, 0
  rlwinm    r29,r27,5,0,26
  b         .loc_0x2A8

.loc_0x48:
  lwz       r3, 0x80(r24)
  addi      r0, r29, 0x18
  lfs       f3, 0x4(r25)
  lwzx      r3, r3, r0
  lfs       f1, 0x0(r25)
  addi      r3, r3, 0x94
  lfs       f4, 0x8(r25)
  lfs       f2, 0x4(r3)
  lfs       f0, 0x0(r3)
  fsubs     f3, f3, f2
  lfs       f2, 0x8(r3)
  fsubs     f1, f1, f0
  fsubs     f2, f4, f2
  fmuls     f0, f3, f3
  fmuls     f1, f1, f1
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f0, f2, f0
  fcmpo     cr0, f0, f29
  ble-      .loc_0xE8
  fsqrte    f2, f0
  fmul      f1, f2, f2
  fmul      f2, f30, f2
  fmul      f1, f0, f1
  fsub      f1, f31, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f30, f2
  fmul      f1, f0, f1
  fsub      f1, f31, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f30, f2
  fmul      f1, f0, f1
  fsub      f1, f31, f1
  fmul      f1, f2, f1
  fmul      f0, f0, f1
  frsp      f0, f0
  stfs      f0, 0x68(r1)
  lfs       f0, 0x68(r1)

.loc_0xE8:
  subi      r0, r26, 0x1
  lwz       r3, 0x80(r24)
  rlwinm    r4,r0,5,0,26
  lfs       f4, 0x4(r25)
  addi      r0, r4, 0x18
  lfs       f2, 0x0(r25)
  lwzx      r3, r3, r0
  lfs       f5, 0x8(r25)
  addi      r3, r3, 0x94
  lfs       f3, 0x4(r3)
  lfs       f1, 0x0(r3)
  fsubs     f4, f4, f3
  lfs       f3, 0x8(r3)
  fsubs     f2, f2, f1
  fsubs     f3, f5, f3
  fmuls     f1, f4, f4
  fmuls     f2, f2, f2
  fmuls     f3, f3, f3
  fadds     f1, f2, f1
  fadds     f3, f3, f1
  fcmpo     cr0, f3, f29
  ble-      .loc_0x190
  fsqrte    f2, f3
  fmul      f1, f2, f2
  fmul      f2, f30, f2
  fmul      f1, f3, f1
  fsub      f1, f31, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f30, f2
  fmul      f1, f3, f1
  fsub      f1, f31, f1
  fmul      f2, f2, f1
  fmul      f1, f2, f2
  fmul      f2, f30, f2
  fmul      f1, f3, f1
  fsub      f1, f31, f1
  fmul      f1, f2, f1
  fmul      f1, f3, f1
  frsp      f1, f1
  stfs      f1, 0x60(r1)
  lfs       f3, 0x60(r1)

.loc_0x190:
  fcmpo     cr0, f0, f3
  bge-      .loc_0x2A0
  lwz       r0, 0x80(r24)
  add       r22, r0, r29
  lwz       r28, 0x18(r22)
  add       r30, r0, r4
  lwz       r31, 0x1C(r22)
  addi      r21, r22, 0x18
  cmplwi    r28, 0
  lwz       r20, 0x18(r30)
  lwz       r23, 0x1C(r30)
  beq-      .loc_0x1D0
  lwz       r3, 0x0(r21)
  bl        0x3DE14
  li        r0, 0
  stw       r0, 0x0(r21)

.loc_0x1D0:
  lwz       r0, 0x18(r22)
  addi      r21, r22, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x1F8
  lwz       r3, 0x0(r21)
  cmplwi    r3, 0
  beq-      .loc_0x1F8
  bl        0x3DDEC
  li        r0, 0
  stw       r0, 0x0(r21)

.loc_0x1F8:
  stw       r20, 0x0(r21)
  lwz       r3, 0x0(r21)
  cmplwi    r3, 0
  beq-      .loc_0x20C
  bl        0x3DDC0

.loc_0x20C:
  stw       r23, 0x1C(r22)
  mr        r4, r26
  lwz       r3, 0x1C(r22)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x18(r30)
  addi      r21, r30, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x248
  lwz       r3, 0x0(r21)
  bl        0x3DD9C
  li        r0, 0
  stw       r0, 0x0(r21)

.loc_0x248:
  lwz       r0, 0x18(r30)
  addi      r21, r30, 0x18
  cmplwi    r0, 0
  beq-      .loc_0x270
  lwz       r3, 0x0(r21)
  cmplwi    r3, 0
  beq-      .loc_0x270
  bl        0x3DD74
  li        r0, 0
  stw       r0, 0x0(r21)

.loc_0x270:
  stw       r28, 0x0(r21)
  lwz       r3, 0x0(r21)
  cmplwi    r3, 0
  beq-      .loc_0x284
  bl        0x3DD48

.loc_0x284:
  stw       r31, 0x1C(r30)
  subi      r4, r26, 0x1
  lwz       r3, 0x1C(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x2A0:
  subi      r29, r29, 0x20
  subi      r26, r26, 0x1

.loc_0x2A8:
  cmpwi     r26, 0x1
  bge+      .loc_0x48
  subi      r27, r27, 0x1

.loc_0x2B4:
  cmpwi     r27, 0x1
  bge+      .loc_0x3C
  lmw       r20, 0x98(r1)
  lwz       r0, 0xE4(r1)
  lfd       f31, 0xD8(r1)
  lfd       f30, 0xD0(r1)
  lfd       f29, 0xC8(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A6670
 * Size:	000188
 */
void CPlate::refresh(int, float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  lwz       r5, 0x74(r3)
  cmpw      r4, r5
  bge-      .loc_0x28
  lwz       r0, 0x7C(r3)
  sub       r5, r5, r4
  sub       r0, r0, r5
  stw       r0, 0x7C(r3)

.loc_0x28:
  xoris     r5, r4, 0x8000
  stw       r4, 0x74(r3)
  lis       r0, 0x4330
  stw       r5, 0x44(r1)
  lfd       f4, -0x7200(r2)
  stw       r0, 0x40(r1)
  lfs       f2, -0x7218(r2)
  lfd       f3, 0x40(r1)
  lfs       f0, -0x7234(r2)
  fsubs     f3, f3, f4
  fdivs     f4, f3, f2
  fcmpo     cr0, f4, f0
  ble-      .loc_0x74
  fsqrte    f0, f4
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x38(r1)
  lfs       f3, 0x38(r1)
  b         .loc_0x78

.loc_0x74:
  fmr       f3, f4

.loc_0x78:
  addi      r5, r3, 0x58
  lfs       f2, -0x7214(r2)
  lfs       f0, 0x58(r3)
  fmuls     f0, f2, f0
  fmuls     f0, f0, f3
  stfs      f0, 0x70(r3)
  lfs       f0, -0x7234(r2)
  fcmpo     cr0, f4, f0
  ble-      .loc_0xB0
  fsqrte    f0, f4
  fmul      f0, f4, f0
  frsp      f0, f0
  stfs      f0, 0x34(r1)
  lfs       f4, 0x34(r1)

.loc_0xB0:
  lfs       f2, -0x7210(r2)
  lfs       f0, 0x0(r5)
  fmuls     f0, f2, f0
  fmuls     f0, f0, f4
  stfs      f0, 0x70(r3)
  lfs       f2, -0x720C(r2)
  lfs       f0, 0x0(r5)
  lfs       f3, 0x70(r3)
  fmuls     f0, f2, f0
  fcmpo     cr0, f0, f3
  ble-      .loc_0xE8
  fmr       f2, f0
  fmr       f0, f3
  b         .loc_0xEC

.loc_0xE8:
  fmr       f2, f3

.loc_0xEC:
  fsubs     f0, f2, f0
  xoris     r0, r4, 0x8000
  stw       r0, 0x44(r1)
  lis       r0, 0x4330
  fneg      f0, f0
  stw       r0, 0x40(r1)
  fmuls     f1, f1, f0
  lfd       f0, 0x40(r1)
  fadds     f1, f2, f1
  stfs      f1, 0x6C(r3)
  lfd       f1, -0x7200(r2)
  lfs       f3, -0x7208(r2)
  fsubs     f1, f0, f1
  lfs       f4, 0x0(r5)
  lfs       f2, -0x7218(r2)
  lfs       f0, 0x6C(r3)
  fmuls     f5, f3, f1
  fmuls     f0, f2, f0
  fmuls     f1, f5, f4
  fmuls     f1, f1, f4
  fdivs     f0, f1, f0
  stfs      f0, 0x68(r3)
  lfs       f1, 0x48(r3)
  lfs       f0, 0x68(r3)
  fcmpo     cr0, f0, f1
  ble-      .loc_0x174
  stfs      f1, 0x68(r3)
  lfs       f3, 0x0(r5)
  lfs       f0, 0x68(r3)
  fmuls     f1, f5, f3
  fmuls     f0, f2, f0
  fmuls     f1, f1, f3
  fdivs     f0, f1, f0
  stfs      f0, 0x6C(r3)

.loc_0x174:
  bl        .loc_0x188
  lwz       r0, 0x4C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr       

.loc_0x188:
*/
}

/*
 * --INFO--
 * Address:	800A67F8
 * Size:	000234
 */
void CPlate::refreshSlot()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x100(r1)
  stfd      f31, 0xF8(r1)
  addi      r6, r1, 0x2C
  addi      r5, r1, 0x38
  stfd      f30, 0xF0(r1)
  addi      r4, r1, 0x44
  stfd      f29, 0xE8(r1)
  stfd      f28, 0xE0(r1)
  stfd      f27, 0xD8(r1)
  stmw      r24, 0xB8(r1)
  mr        r31, r3
  li        r25, 0
  lfs       f3, 0x68(r3)
  lfs       f1, -0x5178(r13)
  lfs       f2, -0x5174(r13)
  fneg      f30, f3
  stfs      f1, 0x2C(r1)
  lfs       f0, -0x5180(r13)
  stfs      f2, 0x30(r1)
  lfs       f1, -0x5170(r13)
  stfs      f0, 0x38(r1)
  lfs       f2, -0x518C(r13)
  stfs      f1, 0x34(r1)
  lfs       f1, -0x5188(r13)
  lfs       f4, 0xAC(r3)
  addi      r3, r1, 0x68
  lfs       f3, -0x517C(r13)
  stfs      f2, 0x44(r1)
  lfs       f0, -0x5184(r13)
  stfs      f4, 0x3C(r1)
  stfs      f1, 0x48(r1)
  stfs      f3, 0x40(r1)
  stfs      f0, 0x4C(r1)
  bl        -0x68790
  lfs       f0, -0x516C(r13)
  addi      r3, r1, 0x50
  lfs       f1, -0x5168(r13)
  addi      r4, r1, 0x68
  stfs      f0, 0x50(r1)
  lfs       f0, -0x5164(r13)
  addi      r5, r31, 0xB0
  stfs      f1, 0x54(r1)
  stfs      f0, 0x58(r1)
  bl        -0x6F09C
  lfs       f28, -0x7214(r2)
  li        r24, 0x1
  lfd       f29, -0x7200(r2)
  li        r27, 0
  lfs       f31, -0x7234(r2)
  lis       r30, 0x4330
  b         .loc_0x200

.loc_0xD4:
  lfs       f1, 0x68(r31)
  fmuls     f0, f30, f30
  fmuls     f1, f1, f1
  fsubs     f1, f1, f0
  fcmpo     cr0, f1, f31
  ble-      .loc_0x100
  fsqrte    f0, f1
  fmul      f0, f1, f0
  frsp      f0, f0
  stfs      f0, 0x28(r1)
  lfs       f1, 0x28(r1)

.loc_0x100:
  lfs       f0, 0x6C(r31)
  lfs       f3, 0x58(r31)
  fmuls     f2, f0, f1
  lfs       f1, 0x68(r31)
  fmuls     f0, f28, f3
  fdivs     f1, f2, f1
  fdivs     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0xA8(r1)
  lwz       r0, 0xAC(r1)
  stfd      f0, 0xB0(r1)
  cmpwi     r0, 0
  lwz       r3, 0xB4(r1)
  bge-      .loc_0x13C
  li        r3, 0

.loc_0x13C:
  xoris     r0, r3, 0x8000
  stw       r0, 0xB4(r1)
  xoris     r29, r24, 0x8000
  rlwinm    r3,r3,1,0,30
  stw       r30, 0xB0(r1)
  addi      r28, r27, 0
  addi      r26, r3, 0x1
  lfd       f0, 0xB0(r1)
  stw       r29, 0xAC(r1)
  fsubs     f0, f0, f29
  stw       r30, 0xA8(r1)
  fmuls     f0, f0, f3
  lfd       f1, 0xA8(r1)
  fsubs     f1, f1, f29
  fmuls     f0, f28, f0
  fmuls     f27, f1, f0
  b         .loc_0x1E8

.loc_0x180:
  lwz       r0, 0x74(r31)
  cmpw      r25, r0
  bge-      .loc_0x1C4
  lwz       r0, 0x80(r31)
  addi      r4, r1, 0x68
  add       r3, r0, r28
  stfs      f27, 0x0(r3)
  lfs       f0, -0x5160(r13)
  stfs      f0, 0x4(r3)
  stfs      f30, 0x8(r3)
  lwz       r0, 0x80(r31)
  add       r3, r0, r28
  addi      r5, r3, 0xC
  bl        -0x6F19C
  addi      r28, r28, 0x20
  addi      r27, r27, 0x20
  addi      r25, r25, 0x1

.loc_0x1C4:
  stw       r29, 0xAC(r1)
  subi      r26, r26, 0x1
  lfs       f0, 0x58(r31)
  stw       r30, 0xA8(r1)
  lfd       f1, 0xA8(r1)
  fsubs     f1, f1, f29
  fmuls     f0, f1, f0
  fmuls     f0, f28, f0
  fsubs     f27, f27, f0

.loc_0x1E8:
  cmpwi     r26, 0
  bgt+      .loc_0x180
  lfs       f0, 0x58(r31)
  mulli     r24, r24, -0x1
  fmuls     f0, f28, f0
  fadds     f30, f30, f0

.loc_0x200:
  lwz       r0, 0x74(r31)
  cmpw      r25, r0
  blt+      .loc_0xD4
  lmw       r24, 0xB8(r1)
  lwz       r0, 0x104(r1)
  lfd       f31, 0xF8(r1)
  lfd       f30, 0xF0(r1)
  lfd       f29, 0xE8(r1)
  lfd       f28, 0xE0(r1)
  lfd       f27, 0xD8(r1)
  addi      r1, r1, 0x100
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A6A2C
 * Size:	000038
 */
void CPlate::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  mr        r31, r3
  lfs       f1, 0xAC(r3)
  bl        0x175110
  lfs       f1, 0xAC(r31)
  bl        0x17529C
  lwz       r0, 0x6C(r1)
  lwz       r31, 0x64(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void CPlate::postUpdate(float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A6A64
 * Size:	0002CC
 */
void CPlate::render(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x120(r1)
  stfd      f31, 0x118(r1)
  stmw      r27, 0x104(r1)
  addi      r29, r3, 0
  addi      r30, r4, 0
  lbz       r0, 0x2FA8(r13)
  cmplwi    r0, 0
  beq-      .loc_0x2B4
  lfs       f0, -0x7234(r2)
  addi      r5, r1, 0x50
  addi      r3, r1, 0xBC
  stfs      f0, 0x78(r1)
  addi      r4, r1, 0x70
  addi      r6, r29, 0x5C
  stfs      f0, 0x74(r1)
  stfs      f0, 0x70(r1)
  lfs       f0, -0x71F8(r2)
  stfs      f0, 0x70(r1)
  stfs      f0, 0x74(r1)
  stfs      f0, 0x78(r1)
  lfs       f0, -0x515C(r13)
  lfs       f1, -0x5158(r13)
  stfs      f0, 0x50(r1)
  lfs       f0, -0x5154(r13)
  stfs      f1, 0x54(r1)
  stfs      f0, 0x58(r1)
  bl        -0x689E0
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  addi      r4, r1, 0xBC
  addi      r5, r1, 0x7C
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  addi      r4, r1, 0x7C
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  li        r27, 0x7D
  stb       r27, 0x68(r1)
  li        r28, 0xFF
  li        r31, 0
  stb       r28, 0x69(r1)
  mr        r4, r30
  li        r6, 0
  stb       r31, 0x6A(r1)
  stb       r28, 0x6B(r1)
  lwz       r3, 0x2F54(r13)
  lwz       r0, 0x68(r1)
  lwz       r3, 0x44(r3)
  stw       r0, 0x2C(r3)
  lwz       r3, 0x2F54(r13)
  lwz       r5, 0x2E4(r30)
  bl        -0x766E0
  lfs       f0, -0x5150(r13)
  addi      r5, r1, 0x44
  lfs       f1, -0x514C(r13)
  addi      r3, r1, 0xBC
  stfs      f0, 0x44(r1)
  lfs       f0, -0x5148(r13)
  addi      r4, r1, 0x70
  stfs      f1, 0x48(r1)
  addi      r6, r29, 0x94
  stfs      f0, 0x4C(r1)
  bl        -0x68A84
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  addi      r4, r1, 0xBC
  addi      r5, r1, 0x7C
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  addi      r4, r1, 0x7C
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  stb       r27, 0x68(r1)
  li        r3, 0xAF
  li        r0, 0xC8
  stb       r3, 0x69(r1)
  addi      r4, r30, 0
  li        r6, 0
  stb       r0, 0x6A(r1)
  stb       r28, 0x6B(r1)
  lwz       r3, 0x2F54(r13)
  lwz       r0, 0x68(r1)
  lwz       r3, 0x44(r3)
  stw       r0, 0x2C(r3)
  lwz       r3, 0x2F54(r13)
  lwz       r5, 0x2E4(r30)
  bl        -0x76780
  lfs       f31, -0x71F4(r2)
  addi      r27, r1, 0x38
  li        r28, 0
  b         .loc_0x2A8

.loc_0x19C:
  lwz       r0, 0x80(r29)
  addi      r7, r31, 0xC
  addi      r5, r27, 0
  add       r7, r0, r7
  lfs       f0, 0x0(r7)
  addi      r3, r1, 0xBC
  addi      r4, r1, 0x70
  stfs      f0, 0x5C(r1)
  addi      r6, r1, 0x5C
  lfs       f0, 0x4(r7)
  stfs      f0, 0x60(r1)
  lfs       f0, 0x8(r7)
  stfs      f0, 0x64(r1)
  lfs       f1, 0x5C(r1)
  lfs       f0, 0x94(r29)
  lfs       f3, 0x60(r1)
  lfs       f2, 0x98(r29)
  fadds     f0, f1, f0
  lfs       f4, 0x64(r1)
  lfs       f1, 0x9C(r29)
  fadds     f2, f3, f2
  stfs      f0, 0x5C(r1)
  fadds     f0, f4, f1
  stfs      f2, 0x60(r1)
  stfs      f0, 0x64(r1)
  stfs      f31, 0x70(r1)
  stfs      f31, 0x74(r1)
  stfs      f31, 0x78(r1)
  lfs       f0, -0x5144(r13)
  lfs       f1, -0x5140(r13)
  stfs      f0, 0x38(r1)
  lfs       f0, -0x513C(r13)
  stfs      f1, 0x3C(r1)
  stfs      f0, 0x40(r1)
  bl        -0x68B94
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  addi      r4, r1, 0xBC
  addi      r5, r1, 0x7C
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  mr        r3, r30
  lwz       r12, 0x3B4(r30)
  addi      r4, r1, 0x7C
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  li        r0, 0
  stb       r0, 0x68(r1)
  li        r3, 0xFF
  li        r0, 0xA
  stb       r3, 0x69(r1)
  addi      r4, r30, 0
  li        r6, 0
  stb       r0, 0x6A(r1)
  stb       r3, 0x6B(r1)
  lwz       r3, 0x2F54(r13)
  lwz       r0, 0x68(r1)
  lwz       r3, 0x44(r3)
  stw       r0, 0x2C(r3)
  lwz       r3, 0x2F54(r13)
  lwz       r5, 0x2E4(r30)
  bl        -0x76894
  addi      r31, r31, 0x20
  addi      r28, r28, 0x1

.loc_0x2A8:
  lwz       r0, 0x7C(r29)
  cmpw      r28, r0
  blt+      .loc_0x19C

.loc_0x2B4:
  lmw       r27, 0x104(r1)
  lwz       r0, 0x124(r1)
  lfd       f31, 0x118(r1)
  addi      r1, r1, 0x120
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A6D30
 * Size:	000008
 */
u32  CPlate::getFirst()
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	800A6D38
 * Size:	000008
 */
void CPlate::getNext(int)
{
/*
.loc_0x0:
  addi      r3, r4, 0x1
  blr
*/
}

/*
 * --INFO--
 * Address:	800A6D40
 * Size:	000018
 */
void CPlate::isDone(int)
{
/*
.loc_0x0:
  lwz       r0, 0x74(r3)
  srawi     r3, r4, 0x1F
  rlwinm    r5,r0,1,31,31
  subc      r0, r4, r0
  adde      r3, r3, r5
  blr
*/
}

/*
 * --INFO--
 * Address:	800A6D58
 * Size:	000024
 */
void CPlate::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x28
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x481D0
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800A6D7C
 * Size:	000008
 */
void CPlate::@8@read(RandomAccessStream &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x8
  b         -0x28
*/
}

/*
 * --INFO--
 * Address:	800A6D84
 * Size:	000008
 */
void CPlate::@8@render(Graphics &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x8
  b         -0x324
*/
}

/*
 * --INFO--
 * Address:	800A6D8C
 * Size:	000008
 */
void CPlate::@8@update()
{
/*
.loc_0x0:
  subi      r3, r3, 0x8
  b         -0x364
*/
}
