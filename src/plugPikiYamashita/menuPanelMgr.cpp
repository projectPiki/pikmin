#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801C94CC
 * Size:	0005AC
 */
void zen::MenuPanelMgr::setCallBack(P2DScreen*, P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C0(r1)
	  stfd      f31, 0x1B8(r1)
	  stfd      f30, 0x1B0(r1)
	  stfd      f29, 0x1A8(r1)
	  stfd      f28, 0x1A0(r1)
	  stfd      f27, 0x198(r1)
	  stfd      f26, 0x190(r1)
	  stfd      f25, 0x188(r1)
	  stfd      f24, 0x180(r1)
	  stfd      f23, 0x178(r1)
	  stfd      f22, 0x170(r1)
	  stfd      f21, 0x168(r1)
	  stfd      f20, 0x160(r1)
	  stfd      f19, 0x158(r1)
	  stfd      f18, 0x150(r1)
	  stmw      r21, 0x124(r1)
	  addi      r22, r4, 0
	  lis       r4, 0x6365
	  addi      r21, r3, 0
	  addi      r23, r5, 0
	  addi      r3, r22, 0
	  addi      r4, r4, 0x6E74
	  li        r5, 0x1
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r24, r3, 0
	  addi      r4, r23, 0
	  bl        -0x99A8
	  addi      r3, r1, 0xD8
	  crclr     6, 0x6
	  li        r26, 0
	  addi      r4, r13, 0x1D5C
	  li        r5, 0
	  bl        0x4D038
	  lis       r5, 0x802D
	  lfs       f19, -0x4568(r2)
	  lis       r4, 0x802D
	  lfd       f20, -0x4530(r2)
	  lis       r3, 0x802E
	  lfs       f21, -0x4560(r2)
	  lfs       f22, -0x4564(r2)
	  addi      r28, r5, 0x3004
	  lfs       f23, -0x455C(r2)
	  addi      r29, r4, 0x2FF4
	  lfs       f24, -0x4558(r2)
	  lfs       f25, -0x4550(r2)
	  addi      r30, r3, 0x209C
	  lfs       f26, -0x454C(r2)
	  lis       r31, 0x4330
	  lfs       f27, -0x4548(r2)
	  lfs       f28, -0x4544(r2)
	  lfs       f29, -0x4540(r2)
	  lfs       f30, -0x453C(r2)
	  lfs       f31, -0x4538(r2)
	  b         .loc_0x520

	.loc_0xEC:
	  addi      r3, r25, 0
	  addi      r4, r23, 0
	  bl        -0x9A20
	  li        r3, 0x64
	  bl        -0x1825C4
	  mr.       r27, r3
	  beq-      .loc_0x4FC
	  stw       r28, 0x0(r27)
	  addi      r4, r25, 0
	  addi      r3, r27, 0x4
	  li        r5, 0x12
	  bl        -0x18EE4
	  stw       r29, 0x0(r27)
	  stw       r30, 0x0(r27)
	  stfs      f19, 0x1C(r27)
	  stfs      f19, 0x18(r27)
	  stfs      f19, 0x14(r27)
	  stfs      f19, 0x28(r27)
	  stfs      f19, 0x24(r27)
	  stfs      f19, 0x20(r27)
	  stfs      f19, 0x34(r27)
	  stfs      f19, 0x30(r27)
	  stfs      f19, 0x2C(r27)
	  stfs      f19, 0x4(r27)
	  bl        0x4EA58
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x11C(r1)
	  stw       r31, 0x118(r1)
	  lfd       f0, 0x118(r1)
	  fsubs     f0, f0, f20
	  fdivs     f0, f0, f21
	  fmuls     f0, f22, f0
	  fcmpo     cr0, f0, f23
	  ble-      .loc_0x17C
	  lfs       f18, -0x4558(r2)
	  b         .loc_0x180

	.loc_0x17C:
	  lfs       f18, -0x4554(r2)

	.loc_0x180:
	  bl        0x4EA24
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x11C(r1)
	  stw       r31, 0x118(r1)
	  lfd       f0, 0x118(r1)
	  fsubs     f0, f0, f20
	  fdivs     f0, f0, f21
	  fmuls     f0, f24, f0
	  fadds     f0, f24, f0
	  fmuls     f0, f0, f18
	  stfs      f0, 0x8(r27)
	  bl        0x4E9F8
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x114(r1)
	  stw       r31, 0x110(r1)
	  lfd       f0, 0x110(r1)
	  fsubs     f0, f0, f20
	  fdivs     f0, f0, f21
	  fmuls     f0, f25, f0
	  fadds     f0, f26, f0
	  stfs      f0, 0xC(r27)
	  bl        0x4E9D0
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x10C(r1)
	  stw       r31, 0x108(r1)
	  lfd       f0, 0x108(r1)
	  fsubs     f0, f0, f20
	  fdivs     f0, f0, f21
	  fmuls     f0, f22, f0
	  fadds     f0, f23, f0
	  stfs      f0, 0x10(r27)
	  stfs      f19, 0x38(r27)
	  stw       r21, 0x3C(r27)
	  lha       r5, 0x1A(r25)
	  lha       r4, 0x1E(r25)
	  lha       r3, 0x18(r25)
	  lha       r0, 0x1C(r25)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r25)
	  extsh     r0, r4
	  sth       r0, 0xBA(r25)
	  lha       r0, 0x18(r25)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x104(r1)
	  stw       r31, 0x100(r1)
	  lfd       f0, 0x100(r1)
	  fsubs     f0, f0, f20
	  stfs      f0, 0x2C(r27)
	  lha       r0, 0x1A(r25)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xFC(r1)
	  stw       r31, 0xF8(r1)
	  lfd       f0, 0xF8(r1)
	  fsubs     f0, f0, f20
	  stfs      f0, 0x30(r27)
	  stfs      f19, 0x34(r27)
	  lfs       f0, 0x2C(r27)
	  stfs      f0, 0x14(r27)
	  lfs       f0, 0x30(r27)
	  stfs      f0, 0x18(r27)
	  lfs       f0, 0x34(r27)
	  stfs      f0, 0x1C(r27)
	  lfs       f0, 0x1D50(r13)
	  stfs      f0, 0x20(r27)
	  lfs       f0, 0x1D54(r13)
	  stfs      f0, 0x24(r27)
	  lfs       f0, 0x1D58(r13)
	  stfs      f0, 0x28(r27)
	  stfs      f19, 0xA4(r1)
	  stfs      f19, 0xA0(r1)
	  stfs      f19, 0x9C(r1)
	  stfs      f19, 0xB0(r1)
	  stfs      f19, 0xAC(r1)
	  stfs      f19, 0xA8(r1)
	  stfs      f19, 0xBC(r1)
	  stfs      f19, 0xB8(r1)
	  stfs      f19, 0xB4(r1)
	  lha       r5, 0x1A(r24)
	  lha       r4, 0x1E(r24)
	  lha       r3, 0x18(r25)
	  lha       r0, 0x1C(r25)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  lha       r6, 0x18(r24)
	  sub       r3, r0, r3
	  lha       r0, 0x1C(r24)
	  srawi     r7, r3, 0x1
	  xoris     r3, r7, 0x8000
	  lfs       f3, 0x2C(r27)
	  sub       r0, r0, r6
	  stw       r3, 0xEC(r1)
	  srawi     r0, r0, 0x1
	  add       r0, r6, r0
	  stw       r31, 0xE8(r1)
	  xoris     r0, r0, 0x8000
	  add       r3, r5, r4
	  stw       r0, 0xE4(r1)
	  xoris     r0, r3, 0x8000
	  lfd       f0, 0xE8(r1)
	  stw       r31, 0xE0(r1)
	  fsubs     f1, f0, f20
	  lfd       f0, 0xE0(r1)
	  stw       r0, 0xF4(r1)
	  fadds     f1, f3, f1
	  fsubs     f0, f0, f20
	  stw       r31, 0xF0(r1)
	  lfd       f2, 0xF0(r1)
	  fcmpo     cr0, f1, f0
	  fsubs     f4, f2, f20
	  bge-      .loc_0x350
	  lfs       f0, -0x4554(r2)
	  b         .loc_0x354

	.loc_0x350:
	  lfs       f0, -0x4558(r2)

	.loc_0x354:
	  lha       r4, 0x1A(r25)
	  xoris     r0, r7, 0x8000
	  lha       r3, 0x1E(r25)
	  fmuls     f1, f27, f0
	  stw       r0, 0xE4(r1)
	  sub       r0, r3, r4
	  fmuls     f0, f28, f0
	  srawi     r0, r0, 0x1
	  xoris     r0, r0, 0x8000
	  stw       r31, 0xE0(r1)
	  fadds     f3, f3, f1
	  stw       r0, 0xEC(r1)
	  lfd       f1, 0xE0(r1)
	  stw       r31, 0xE8(r1)
	  fsubs     f2, f1, f20
	  lfd       f1, 0xE8(r1)
	  fsubs     f1, f1, f20
	  fsubs     f2, f3, f2
	  fsubs     f1, f4, f1
	  stfs      f2, 0x9C(r1)
	  stfs      f1, 0xA0(r1)
	  lfs       f1, 0x34(r27)
	  stfs      f1, 0xA4(r1)
	  lha       r5, 0x1A(r25)
	  lha       r4, 0x1E(r25)
	  lha       r3, 0x18(r25)
	  lha       r0, 0x1C(r25)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  lfs       f1, 0x2C(r27)
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  fadds     f1, f1, f0
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xFC(r1)
	  xoris     r0, r4, 0x8000
	  stw       r0, 0xF4(r1)
	  stw       r31, 0xF8(r1)
	  stw       r31, 0xF0(r1)
	  lfd       f0, 0xF8(r1)
	  lfd       f2, 0xF0(r1)
	  fsubs     f0, f0, f20
	  fsubs     f2, f2, f20
	  fsubs     f0, f1, f0
	  fsubs     f1, f4, f2
	  stfs      f0, 0xA8(r1)
	  stfs      f1, 0xAC(r1)
	  lfs       f0, 0x34(r27)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, 0x2C(r27)
	  stfs      f0, 0xB4(r1)
	  lfs       f0, 0x30(r27)
	  stfs      f0, 0xB8(r1)
	  lfs       f0, 0x34(r27)
	  stfs      f0, 0xBC(r1)
	  lfs       f3, 0x9C(r1)
	  lfs       f5, 0xB4(r1)
	  lfs       f4, 0xA8(r1)
	  fmuls     f1, f29, f3
	  fmuls     f0, f31, f3
	  fmuls     f2, f30, f5
	  stfs      f3, 0x40(r27)
	  fadds     f3, f1, f4
	  fmuls     f1, f31, f5
	  fsubs     f0, f0, f4
	  fsubs     f2, f3, f2
	  fadds     f0, f1, f0
	  fdivs     f1, f2, f30
	  fdivs     f0, f0, f30
	  stfs      f1, 0x44(r27)
	  stfs      f0, 0x48(r27)
	  lfs       f2, 0xA0(r1)
	  lfs       f4, 0xB8(r1)
	  lfs       f3, 0xAC(r1)
	  fmuls     f1, f29, f2
	  fmuls     f0, f30, f4
	  stfs      f2, 0x4C(r27)
	  fadds     f1, f1, f3
	  fsubs     f0, f1, f0
	  fdivs     f0, f0, f30
	  stfs      f0, 0x50(r27)
	  fmuls     f0, f31, f2
	  mr        r3, r27
	  fmuls     f1, f31, f4
	  mr        r4, r25
	  fsubs     f0, f0, f3
	  fadds     f0, f1, f0
	  fdivs     f0, f0, f30
	  stfs      f0, 0x54(r27)
	  lfs       f3, 0xA4(r1)
	  lfs       f5, 0xBC(r1)
	  fmuls     f1, f29, f3
	  lfs       f4, 0xB0(r1)
	  fmuls     f0, f31, f3
	  fmuls     f2, f30, f5
	  stfs      f3, 0x58(r27)
	  fadds     f3, f1, f4
	  fmuls     f1, f31, f5
	  fsubs     f0, f0, f4
	  fsubs     f2, f3, f2
	  fadds     f0, f1, f0
	  fdivs     f1, f2, f30
	  fdivs     f0, f0, f30
	  stfs      f1, 0x5C(r27)
	  stfs      f0, 0x60(r27)
	  bl        .loc_0x5AC

	.loc_0x4FC:
	  addi      r3, r25, 0
	  addi      r4, r27, 0
	  bl        -0x19334
	  addi      r26, r26, 0x1
	  crclr     6, 0x6
	  addi      r5, r26, 0
	  addi      r3, r1, 0xD8
	  addi      r4, r13, 0x1D5C
	  bl        0x4CBB0

	.loc_0x520:
	  lwz       r12, 0x0(r22)
	  mr        r3, r22
	  lbz       r0, 0xD9(r1)
	  li        r5, 0
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0xD8(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0xDA(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0xDB(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  mr.       r25, r3
	  bne+      .loc_0xEC
	  lmw       r21, 0x124(r1)
	  lwz       r0, 0x1C4(r1)
	  lfd       f31, 0x1B8(r1)
	  lfd       f30, 0x1B0(r1)
	  lfd       f29, 0x1A8(r1)
	  lfd       f28, 0x1A0(r1)
	  lfd       f27, 0x198(r1)
	  lfd       f26, 0x190(r1)
	  lfd       f25, 0x188(r1)
	  lfd       f24, 0x180(r1)
	  lfd       f23, 0x178(r1)
	  lfd       f22, 0x170(r1)
	  lfd       f21, 0x168(r1)
	  lfd       f20, 0x160(r1)
	  lfd       f19, 0x158(r1)
	  lfd       f18, 0x150(r1)
	  addi      r1, r1, 0x1C0
	  mtlr      r0
	  blr

	.loc_0x5AC:
	*/
}

/*
 * --INFO--
 * Address:	801C9A78
 * Size:	0003B4
 */
void zen::MenuPanel::update(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  mr        r31, r4
	  stw       r30, 0xA8(r1)
	  mr        r30, r3
	  lwz       r3, 0x3C(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x140
	  bge-      .loc_0x44
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  b         .loc_0x308

	.loc_0x44:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x308
	  b         .loc_0x248

	.loc_0x50:
	  lfs       f1, 0xC(r3)
	  lfs       f0, -0x4528(r2)
	  fmuls     f1, f0, f1
	  bl        0x52080
	  lfs       f0, -0x4558(r2)
	  lfs       f4, -0x4538(r2)
	  fsubs     f3, f0, f1
	  lfs       f2, 0x44(r30)
	  lfs       f1, 0x48(r30)
	  lfs       f5, 0x50(r30)
	  fmuls     f10, f4, f3
	  lfs       f4, 0x54(r30)
	  lfs       f8, 0x5C(r30)
	  fmuls     f1, f1, f10
	  lfs       f6, 0x60(r30)
	  fmuls     f2, f2, f10
	  lfs       f3, 0x40(r30)
	  fmuls     f4, f4, f10
	  fmuls     f7, f6, f10
	  lfs       f6, 0x4C(r30)
	  fmuls     f5, f5, f10
	  lfs       f9, 0x58(r30)
	  fmuls     f8, f8, f10
	  fadds     f2, f3, f2
	  fmuls     f1, f10, f1
	  fadds     f5, f6, f5
	  fmuls     f3, f10, f4
	  fadds     f1, f2, f1
	  fadds     f4, f9, f8
	  fmuls     f2, f10, f7
	  fadds     f3, f5, f3
	  stfs      f1, 0x14(r30)
	  fadds     f1, f4, f2
	  stfs      f3, 0x18(r30)
	  stfs      f1, 0x1C(r30)
	  lfs       f1, -0x4524(r2)
	  fcmpo     cr0, f10, f1
	  bge-      .loc_0xFC
	  stfs      f0, 0xC0(r31)
	  lfs       f1, -0x4520(r2)
	  stfs      f1, 0xC4(r31)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0x124

	.loc_0xFC:
	  stfs      f0, 0xC0(r31)
	  fsubs     f2, f10, f1
	  lfs       f3, -0x451C(r2)
	  lfs       f1, -0x4518(r2)
	  fmuls     f2, f3, f2
	  lfs       f3, -0x4520(r2)
	  fdivs     f1, f2, f1
	  fadds     f1, f3, f1
	  stfs      f1, 0xC4(r31)
	  stfs      f0, 0xC8(r31)

	.loc_0x124:
	  lfs       f0, 0x1D48(r13)
	  stfs      f0, 0x20(r30)
	  lfs       f0, 0x1D4C(r13)
	  stfs      f0, 0x24(r30)
	  lfs       f0, -0x4568(r2)
	  stfs      f0, 0x38(r30)
	  b         .loc_0x308

	.loc_0x140:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x38(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x38(r30)
	  lfs       f1, 0x38(r30)
	  lfs       f0, -0x4558(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x168
	  stfs      f0, 0x38(r30)

	.loc_0x168:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x4(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, -0x4514(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x19C
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4(r30)

	.loc_0x19C:
	  lfs       f1, 0x4(r30)
	  bl        0x520D0
	  lfs       f0, 0x4(r30)
	  fmr       f30, f1
	  fmr       f1, f0
	  bl        0x51F2C
	  fmr       f31, f1
	  lfs       f1, -0x450C(r2)
	  lfs       f2, -0x4510(r2)
	  lfs       f0, -0x4568(r2)
	  fmuls     f1, f1, f31
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1E4
	  lfs       f0, -0x4538(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x1EC

	.loc_0x1E4:
	  lfs       f0, -0x4538(r2)
	  fsubs     f0, f1, f0

	.loc_0x1EC:
	  fctiwz    f0, f0
	  stfd      f0, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  stb       r0, 0xF0(r31)
	  lfs       f1, 0x4(r30)
	  bl        0x52070
	  lfs       f2, 0x38(r30)
	  lfs       f0, 0xC(r30)
	  lfs       f3, -0x4558(r2)
	  fmuls     f0, f2, f0
	  fmuls     f0, f0, f1
	  fadds     f0, f3, f0
	  stfs      f0, 0xC0(r31)
	  stfs      f0, 0xC4(r31)
	  stfs      f0, 0xC8(r31)
	  lfs       f1, 0x38(r30)
	  lfs       f0, 0x10(r30)
	  fmuls     f1, f1, f0
	  fmuls     f0, f30, f1
	  fmuls     f1, f31, f1
	  stfs      f0, 0x20(r30)
	  stfs      f1, 0x24(r30)
	  b         .loc_0x308

	.loc_0x248:
	  lfs       f0, -0x4558(r2)
	  lfs       f1, 0xC(r3)
	  lfs       f2, 0x44(r30)
	  fsubs     f10, f0, f1
	  lfs       f1, 0x48(r30)
	  lfs       f5, 0x50(r30)
	  lfs       f3, 0x54(r30)
	  fmuls     f1, f1, f10
	  fmuls     f4, f3, f10
	  lfs       f8, 0x5C(r30)
	  lfs       f6, 0x60(r30)
	  fmuls     f2, f2, f10
	  lfs       f3, 0x40(r30)
	  fmuls     f7, f6, f10
	  lfs       f6, 0x4C(r30)
	  fmuls     f5, f5, f10
	  lfs       f9, 0x58(r30)
	  fmuls     f8, f8, f10
	  fadds     f2, f3, f2
	  fmuls     f1, f10, f1
	  fadds     f5, f6, f5
	  fmuls     f3, f10, f4
	  fadds     f1, f2, f1
	  fadds     f4, f9, f8
	  fmuls     f2, f10, f7
	  fadds     f3, f5, f3
	  stfs      f1, 0x14(r30)
	  fadds     f1, f4, f2
	  stfs      f3, 0x18(r30)
	  stfs      f1, 0x1C(r30)
	  lfs       f1, -0x4524(r2)
	  fcmpo     cr0, f10, f1
	  bge-      .loc_0x2E0
	  stfs      f0, 0xC0(r31)
	  lfs       f1, -0x4520(r2)
	  stfs      f1, 0xC4(r31)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0x308

	.loc_0x2E0:
	  stfs      f0, 0xC0(r31)
	  fsubs     f2, f10, f1
	  lfs       f3, -0x451C(r2)
	  lfs       f1, -0x4518(r2)
	  fmuls     f2, f3, f2
	  lfs       f3, -0x4520(r2)
	  fdivs     f1, f2, f1
	  fadds     f1, f3, f1
	  stfs      f1, 0xC4(r31)
	  stfs      f0, 0xC8(r31)

	.loc_0x308:
	  lfs       f2, 0x18(r30)
	  lfs       f1, 0x24(r30)
	  lfs       f0, -0x4568(r2)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x330
	  lfs       f0, -0x4538(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x338

	.loc_0x330:
	  lfs       f0, -0x4538(r2)
	  fsubs     f0, f1, f0

	.loc_0x338:
	  lfs       f2, 0x14(r30)
	  fctiwz    f3, f0
	  lfs       f1, 0x20(r30)
	  lfs       f0, -0x4568(r2)
	  fadds     f1, f2, f1
	  stfd      f3, 0xA0(r1)
	  lwz       r5, 0xA4(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x36C
	  lfs       f0, -0x4538(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x374

	.loc_0x36C:
	  lfs       f0, -0x4538(r2)
	  fsubs     f0, f1, f0

	.loc_0x374:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0xA0(r1)
	  mtlr      r12
	  lwz       r4, 0xA4(r1)
	  blrl
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C9E2C
 * Size:	000074
 */
void zen::MenuPanelMgr::update()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x58
	  bge-      .loc_0x1C
	  cmpwi     r0, 0x1
	  bge-      .loc_0x24
	  b         .loc_0x58

	.loc_0x1C:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x58

	.loc_0x24:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r3)
	  lfs       f1, 0x8(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x50
	  stfs      f1, 0x4(r3)
	  li        r0, 0x1
	  b         .loc_0x5C

	.loc_0x50:
	  li        r0, 0
	  b         .loc_0x5C

	.loc_0x58:
	  li        r0, 0x1

	.loc_0x5C:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC(r3)
	  mr        r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C9EA0
 * Size:	000050
 */
void zen::MenuPanelMgr::checkFinish()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  li        r4, 0
	  cmpwi     r0, 0x2
	  beq-      .loc_0x44
	  bge-      .loc_0x20
	  cmpwi     r0, 0x1
	  bge-      .loc_0x28
	  b         .loc_0x44

	.loc_0x20:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x44

	.loc_0x28:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x8(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x48
	  li        r4, 0x1
	  b         .loc_0x48

	.loc_0x44:
	  li        r4, 0x1

	.loc_0x48:
	  mr        r3, r4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801C9EF0
 * Size:	0003B8
 */
void zen::MenuPanel::invoke(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  mr        r31, r4
	  stw       r30, 0xD0(r1)
	  mr        r30, r3
	  lwz       r3, 0x3C(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x140
	  bge-      .loc_0x44
	  cmpwi     r0, 0
	  bge-      .loc_0x50
	  b         .loc_0x308

	.loc_0x44:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x308
	  b         .loc_0x248

	.loc_0x50:
	  lfs       f1, -0x4528(r2)
	  lfs       f0, 0xC(r3)
	  fmuls     f1, f1, f0
	  bl        0x51C08
	  lfs       f0, -0x4558(r2)
	  lfs       f4, -0x4538(r2)
	  fsubs     f3, f0, f1
	  lfs       f2, 0x44(r30)
	  lfs       f1, 0x48(r30)
	  lfs       f5, 0x50(r30)
	  fmuls     f10, f4, f3
	  lfs       f4, 0x54(r30)
	  lfs       f8, 0x5C(r30)
	  fmuls     f1, f1, f10
	  lfs       f6, 0x60(r30)
	  fmuls     f2, f2, f10
	  lfs       f3, 0x40(r30)
	  fmuls     f4, f4, f10
	  fmuls     f7, f6, f10
	  lfs       f6, 0x4C(r30)
	  fmuls     f5, f5, f10
	  lfs       f9, 0x58(r30)
	  fmuls     f8, f8, f10
	  fadds     f2, f3, f2
	  fmuls     f1, f10, f1
	  fadds     f5, f6, f5
	  fmuls     f3, f10, f4
	  fadds     f1, f2, f1
	  fadds     f4, f9, f8
	  fmuls     f2, f10, f7
	  fadds     f3, f5, f3
	  stfs      f1, 0x14(r30)
	  fadds     f1, f4, f2
	  stfs      f3, 0x18(r30)
	  stfs      f1, 0x1C(r30)
	  lfs       f1, -0x4524(r2)
	  fcmpo     cr0, f10, f1
	  bge-      .loc_0xFC
	  stfs      f0, 0xC0(r31)
	  lfs       f1, -0x4520(r2)
	  stfs      f1, 0xC4(r31)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0x124

	.loc_0xFC:
	  stfs      f0, 0xC0(r31)
	  fsubs     f2, f10, f1
	  lfs       f3, -0x451C(r2)
	  lfs       f1, -0x4518(r2)
	  fmuls     f2, f3, f2
	  lfs       f3, -0x4520(r2)
	  fdivs     f1, f2, f1
	  fadds     f1, f3, f1
	  stfs      f1, 0xC4(r31)
	  stfs      f0, 0xC8(r31)

	.loc_0x124:
	  lfs       f0, 0x1D48(r13)
	  stfs      f0, 0x20(r30)
	  lfs       f0, 0x1D4C(r13)
	  stfs      f0, 0x24(r30)
	  lfs       f0, -0x4568(r2)
	  stfs      f0, 0x38(r30)
	  b         .loc_0x308

	.loc_0x140:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x38(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x38(r30)
	  lfs       f1, 0x38(r30)
	  lfs       f0, -0x4558(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x168
	  stfs      f0, 0x38(r30)

	.loc_0x168:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x4(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, -0x4514(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x19C
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4(r30)

	.loc_0x19C:
	  lfs       f1, 0x4(r30)
	  bl        0x51C58
	  lfs       f0, 0x4(r30)
	  fmr       f30, f1
	  fmr       f1, f0
	  bl        0x51AB4
	  fmr       f31, f1
	  lfs       f1, -0x450C(r2)
	  lfs       f2, -0x4510(r2)
	  lfs       f0, -0x4568(r2)
	  fmuls     f1, f1, f31
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1E4
	  lfs       f0, -0x4538(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x1EC

	.loc_0x1E4:
	  lfs       f0, -0x4538(r2)
	  fsubs     f0, f1, f0

	.loc_0x1EC:
	  fctiwz    f0, f0
	  stfd      f0, 0xC8(r1)
	  lwz       r0, 0xCC(r1)
	  stb       r0, 0xF0(r31)
	  lfs       f1, 0x4(r30)
	  bl        0x51BF8
	  lfs       f2, 0x38(r30)
	  lfs       f0, 0xC(r30)
	  lfs       f3, -0x4558(r2)
	  fmuls     f0, f2, f0
	  fmuls     f0, f0, f1
	  fadds     f0, f3, f0
	  stfs      f0, 0xC0(r31)
	  stfs      f0, 0xC4(r31)
	  stfs      f0, 0xC8(r31)
	  lfs       f1, 0x38(r30)
	  lfs       f0, 0x10(r30)
	  fmuls     f1, f1, f0
	  fmuls     f0, f30, f1
	  fmuls     f1, f31, f1
	  stfs      f0, 0x20(r30)
	  stfs      f1, 0x24(r30)
	  b         .loc_0x308

	.loc_0x248:
	  lfs       f0, -0x4558(r2)
	  lfs       f1, 0xC(r3)
	  lfs       f2, 0x44(r30)
	  fsubs     f10, f0, f1
	  lfs       f1, 0x48(r30)
	  lfs       f5, 0x50(r30)
	  lfs       f3, 0x54(r30)
	  fmuls     f1, f1, f10
	  fmuls     f4, f3, f10
	  lfs       f8, 0x5C(r30)
	  lfs       f6, 0x60(r30)
	  fmuls     f2, f2, f10
	  lfs       f3, 0x40(r30)
	  fmuls     f7, f6, f10
	  lfs       f6, 0x4C(r30)
	  fmuls     f5, f5, f10
	  lfs       f9, 0x58(r30)
	  fmuls     f8, f8, f10
	  fadds     f2, f3, f2
	  fmuls     f1, f10, f1
	  fadds     f5, f6, f5
	  fmuls     f3, f10, f4
	  fadds     f1, f2, f1
	  fadds     f4, f9, f8
	  fmuls     f2, f10, f7
	  fadds     f3, f5, f3
	  stfs      f1, 0x14(r30)
	  fadds     f1, f4, f2
	  stfs      f3, 0x18(r30)
	  stfs      f1, 0x1C(r30)
	  lfs       f1, -0x4524(r2)
	  fcmpo     cr0, f10, f1
	  bge-      .loc_0x2E0
	  stfs      f0, 0xC0(r31)
	  lfs       f1, -0x4520(r2)
	  stfs      f1, 0xC4(r31)
	  stfs      f0, 0xC8(r31)
	  b         .loc_0x308

	.loc_0x2E0:
	  stfs      f0, 0xC0(r31)
	  fsubs     f2, f10, f1
	  lfs       f3, -0x451C(r2)
	  lfs       f1, -0x4518(r2)
	  fmuls     f2, f3, f2
	  lfs       f3, -0x4520(r2)
	  fdivs     f1, f2, f1
	  fadds     f1, f3, f1
	  stfs      f1, 0xC4(r31)
	  stfs      f0, 0xC8(r31)

	.loc_0x308:
	  lfs       f2, 0x18(r30)
	  lfs       f1, 0x24(r30)
	  lfs       f0, -0x4568(r2)
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x330
	  lfs       f0, -0x4538(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x338

	.loc_0x330:
	  lfs       f0, -0x4538(r2)
	  fsubs     f0, f1, f0

	.loc_0x338:
	  lfs       f2, 0x14(r30)
	  fctiwz    f3, f0
	  lfs       f1, 0x20(r30)
	  lfs       f0, -0x4568(r2)
	  fadds     f1, f2, f1
	  stfd      f3, 0xC8(r1)
	  lwz       r5, 0xCC(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x36C
	  lfs       f0, -0x4538(r2)
	  fadds     f0, f0, f1
	  b         .loc_0x374

	.loc_0x36C:
	  lfs       f0, -0x4538(r2)
	  fsubs     f0, f1, f0

	.loc_0x374:
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0xC8(r1)
	  mtlr      r12
	  lwz       r4, 0xCC(r1)
	  blrl
	  lwz       r0, 0xEC(r1)
	  li        r3, 0x1
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}
