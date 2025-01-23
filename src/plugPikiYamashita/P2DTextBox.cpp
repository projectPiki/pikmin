#include "P2D/TextBox.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	801B44AC
 * Size:	000038
 */
void P2DTextBox::makeResident()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0xF0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B44E4
 * Size:	000050
 */
void P2DTextBox::loadResource()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  li        r3, 0x20
	  bl        -0x16D4FC
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x34
	  lwz       r4, 0xEC(r30)
	  bl        0x18A0

	.loc_0x34:
	  stw       r31, 0xF0(r30)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B4534
 * Size:	00020C
 */
P2DTextBox::P2DTextBox(P2DPane*, RandomAccessStream*, u16)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r5
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  bl        -0x3A24
	  lis       r3, 0x802E
	  lwz       r30, 0x8(r1)
	  addi      r0, r3, 0x8B0
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  lis       r4, 0x464F
	  stw       r0, 0x10C(r30)
	  addi      r3, r1, 0x20
	  addi      r4, r4, 0x4E54
	  stw       r31, 0x20(r1)
	  bl        -0x1310
	  stw       r3, 0xEC(r30)
	  addi      r4, r1, 0x1C
	  li        r5, 0x4
	  lwz       r3, 0x20(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lbz       r7, 0x1F(r1)
	  addi      r4, r1, 0x18
	  lbz       r6, 0x1E(r1)
	  li        r5, 0x4
	  lbz       r3, 0x1D(r1)
	  lbz       r0, 0x1C(r1)
	  stb       r0, 0xF4(r30)
	  stb       r3, 0xF5(r30)
	  stb       r6, 0xF6(r30)
	  stb       r7, 0xF7(r30)
	  lwz       r3, 0x20(r1)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lbz       r6, 0x1B(r1)
	  mr        r3, r31
	  lbz       r5, 0x1A(r1)
	  lbz       r4, 0x19(r1)
	  lbz       r0, 0x18(r1)
	  stb       r0, 0xF8(r30)
	  stb       r4, 0xF9(r30)
	  stb       r5, 0xFA(r30)
	  stb       r6, 0xFB(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r29,r3,0,24,31
	  rlwinm    r0,r3,0,25,31
	  stw       r0, 0xFC(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r3,r3,0,24,31
	  rlwinm.   r0,r29,0,24,24
	  stw       r3, 0x100(r30)
	  beq-      .loc_0x184
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  sth       r0, 0x104(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  sth       r0, 0x106(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  sth       r0, 0x108(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  sth       r0, 0x10A(r30)

	.loc_0x184:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r29, r3
	  addi      r3, r29, 0x1
	  bl        -0x16D6D0
	  lwz       r30, 0x8(r1)
	  mr        r5, r29
	  stw       r3, 0x10C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r4, 0x10C(r30)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x10C(r30)
	  li        r31, 0
	  addi      r3, r1, 0x20
	  stbx      r31, r4, r29
	  li        r4, 0x4
	  bl        -0x13D8
	  sth       r31, 0x110(r30)
	  mr        r3, r30
	  sth       r31, 0x112(r30)
	  stw       r31, 0xF0(r30)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B4740
 * Size:	000068
 */
void P2DTextBox::drawSelf(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x60(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x5C(r1)
	  addi      r29, r3, 0
	  addi      r3, r1, 0x14
	  bl        -0x1769AC
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x30(r12)
	  addi      r6, r1, 0x14
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B47A8
 * Size:	000198
 */
void P2DTextBox::drawSelf(int, int, Matrix4f*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stw       r31, 0xE4(r1)
	  mr        r31, r3
	  stw       r30, 0xE0(r1)
	  addi      r30, r6, 0
	  stw       r29, 0xDC(r1)
	  addi      r29, r5, 0
	  stw       r28, 0xD8(r1)
	  addi      r28, r4, 0
	  lwz       r0, 0xF0(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x44
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x4144

	.loc_0x44:
	  lwz       r0, 0xF8(r31)
	  addi      r8, r1, 0x30
	  addi      r7, r1, 0x34
	  stw       r0, 0x30(r1)
	  addi      r3, r1, 0x78
	  lwz       r0, 0xF4(r31)
	  stw       r0, 0x34(r1)
	  lwz       r4, 0xF0(r31)
	  lha       r5, 0x104(r31)
	  lha       r6, 0x106(r31)
	  bl        0x190
	  lha       r3, 0x108(r31)
	  lha       r0, 0x10A(r31)
	  cmpwi     r3, 0
	  ble-      .loc_0x84
	  b         .loc_0x88

	.loc_0x84:
	  li        r3, 0

	.loc_0x88:
	  cmpwi     r0, 0
	  stw       r3, 0xB0(r1)
	  ble-      .loc_0x98
	  b         .loc_0x9C

	.loc_0x98:
	  li        r0, 0

	.loc_0x9C:
	  stw       r0, 0xB4(r1)
	  addi      r3, r30, 0
	  addi      r4, r31, 0x78
	  addi      r5, r1, 0x38
	  bl        -0x176780
	  addi      r3, r1, 0x38
	  li        r4, 0
	  bl        0x5FBF4
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x78
	  bl        0x27C
	  lha       r6, 0x1A(r31)
	  addi      r3, r1, 0x78
	  lha       r4, 0x1E(r31)
	  lha       r5, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r6, r4, r6
	  lwz       r4, 0x10C(r31)
	  lwz       r7, 0xFC(r31)
	  sub       r5, r0, r5
	  lwz       r8, 0x100(r31)
	  lha       r9, 0x110(r31)
	  lha       r10, 0x112(r31)
	  bl        0x308
	  lfs       f1, 0x90(r1)
	  lfs       f0, -0x4920(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x120
	  lfs       f0, -0x491C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x128

	.loc_0x120:
	  lfs       f0, -0x491C(r2)
	  fsubs     f0, f1, f0

	.loc_0x128:
	  fctiwz    f0, f0
	  stfd      f0, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  extsh     r0, r0
	  sth       r0, 0x114(r31)
	  lfs       f1, 0x94(r1)
	  lfs       f0, -0x4920(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x15C
	  lfs       f0, -0x491C(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x164

	.loc_0x15C:
	  lfs       f0, -0x491C(r2)
	  fsubs     f0, f1, f0

	.loc_0x164:
	  fctiwz    f0, f0
	  stfd      f0, 0xD0(r1)
	  lwz       r0, 0xD4(r1)
	  extsh     r0, r0
	  sth       r0, 0x116(r31)
	  lwz       r0, 0xEC(r1)
	  lwz       r31, 0xE4(r1)
	  lwz       r30, 0xE0(r1)
	  lwz       r29, 0xDC(r1)
	  lwz       r28, 0xD8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801B4940
 * Size:	000064
 */
P2DTextBox::~P2DTextBox()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x48
	  lis       r3, 0x802E
	  addi      r0, r3, 0x8B0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x3BB0
	  extsh.    r0, r31
	  ble-      .loc_0x48
	  mr        r3, r30
	  bl        -0x16D7D8

	.loc_0x48:
	  mr        r3, r30
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
