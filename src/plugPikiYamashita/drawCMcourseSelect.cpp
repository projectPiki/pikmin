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
 * Address:	801EC478
 * Size:	0001B8
 */
void zen::DrawCMCSmenu::modeAppear(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stfd      f29, 0x58(r1)
	  stfd      f28, 0x50(r1)
	  stmw      r27, 0x3C(r1)
	  mr        r27, r3
	  li        r28, 0
	  li        r29, 0
	  li        r31, 0
	  lfs       f31, -0x3ED8(r2)
	  lfs       f28, -0x3EE0(r2)
	  lfs       f29, -0x3EDC(r2)
	  lfs       f30, -0x3ED4(r2)
	  b         .loc_0x144

	.loc_0x44:
	  lwz       r0, 0x198(r27)
	  add       r30, r0, r31
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5C
	  b         .loc_0x12C

	.loc_0x5C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x98
	  stfs      f0, 0x4(r30)
	  li        r0, 0
	  lfs       f1, -0x3EE0(r2)
	  lfs       f4, -0x3EDC(r2)
	  stw       r0, 0x0(r30)
	  b         .loc_0xA8

	.loc_0x98:
	  fdivs     f0, f1, f0
	  fmuls     f1, f31, f0
	  bl        0x2F7D0
	  fsubs     f4, f28, f1

	.loc_0xA8:
	  lfs       f2, 0x20(r30)
	  lfs       f0, 0x2C(r30)
	  fmuls     f2, f2, f4
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xD0
	  fadds     f0, f30, f0
	  b         .loc_0xD4

	.loc_0xD0:
	  fsubs     f0, f0, f30

	.loc_0xD4:
	  lfs       f2, 0x1C(r30)
	  fctiwz    f3, f0
	  lfs       f0, 0x28(r30)
	  fmuls     f2, f2, f4
	  fmuls     f0, f0, f1
	  stfd      f3, 0x30(r1)
	  lwz       r5, 0x34(r1)
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x108
	  fadds     f0, f30, f0
	  b         .loc_0x10C

	.loc_0x108:
	  fsubs     f0, f0, f30

	.loc_0x10C:
	  lwz       r3, 0xC(r30)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x30(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x34(r1)
	  mtlr      r12
	  blrl

	.loc_0x12C:
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x13C
	  addi      r28, r28, 0x1

	.loc_0x13C:
	  addi      r31, r31, 0x34
	  addi      r29, r29, 0x1

	.loc_0x144:
	  lwz       r0, 0x10C(r27)
	  cmpw      r29, r0
	  blt+      .loc_0x44
	  cmpw      r28, r0
	  bne-      .loc_0x190
	  lfs       f1, -0x3EE0(r2)
	  addi      r3, r27, 0x114
	  fmr       f2, f1
	  bl        -0x119C4
	  lfs       f1, -0x3EE0(r2)
	  addi      r3, r27, 0x144
	  fmr       f2, f1
	  bl        -0x119D4
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0x1
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl

	.loc_0x190:
	  lmw       r27, 0x3C(r1)
	  li        r3, 0
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lfd       f29, 0x58(r1)
	  lfd       f28, 0x50(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EC630
 * Size:	0002A8
 */
void zen::DrawCMCSmenu::setModeFunc(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stfd      f27, 0xD0(r1)
	  stfd      f26, 0xC8(r1)
	  stfd      f25, 0xC0(r1)
	  stmw      r26, 0xA8(r1)
	  mr        r26, r3
	  bl        0x43A4
	  lwz       r0, 0x100(r26)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x44
	  b         .loc_0x278

	.loc_0x44:
	  lis       r3, 0x802E
	  addi      r5, r3, 0x6CA4
	  lwz       r4, 0x0(r5)
	  li        r29, 0
	  lwz       r0, 0x4(r5)
	  lis       r3, 0x803A
	  addi      r28, r29, 0
	  stw       r4, 0x180(r26)
	  subi      r30, r3, 0x2848
	  li        r27, 0
	  stw       r0, 0x184(r26)
	  lis       r31, 0x4330
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x188(r26)
	  lfs       f30, -0x3EDC(r2)
	  lfs       f31, -0x3ED4(r2)
	  lfs       f25, -0x3ED0(r2)
	  lfs       f26, -0x3EE0(r2)
	  lfd       f27, -0x3EC8(r2)
	  b         .loc_0x254

	.loc_0x94:
	  lwz       r0, 0x198(r26)
	  addi      r3, r29, 0x10
	  cmpwi     r27, 0x3
	  add       r3, r0, r3
	  lfs       f29, 0x0(r3)
	  li        r4, 0
	  lfs       f28, 0x4(r3)
	  bge-      .loc_0xBC
	  li        r4, 0x1
	  b         .loc_0xFC

	.loc_0xBC:
	  cmpwi     r27, 0
	  blt-      .loc_0xEC
	  cmpwi     r27, 0x5
	  bgt-      .loc_0xEC
	  li        r0, 0x1
	  lbz       r3, 0xB6(r30)
	  slw       r0, r0, r27
	  and       r0, r3, r0
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  b         .loc_0xF0

	.loc_0xEC:
	  li        r0, 0

	.loc_0xF0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xFC
	  li        r4, 0x1

	.loc_0xFC:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0x220
	  lwz       r3, 0x174(r26)
	  fcmpo     cr0, f28, f30
	  li        r4, 0x1
	  lwzx      r3, r3, r28
	  addi      r0, r29, 0xC
	  stb       r4, 0x14(r3)
	  cror      2, 0x1, 0x2
	  lwz       r3, 0x198(r26)
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  bne-      .loc_0x140
	  fadds     f0, f31, f28
	  b         .loc_0x144

	.loc_0x140:
	  fsubs     f0, f28, f31

	.loc_0x144:
	  fsubs     f1, f29, f25
	  fctiwz    f0, f0
	  fcmpo     cr0, f1, f30
	  stfd      f0, 0xA0(r1)
	  lwz       r5, 0xA4(r1)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x168
	  fadds     f0, f31, f1
	  b         .loc_0x16C

	.loc_0x168:
	  fsubs     f0, f1, f31

	.loc_0x16C:
	  lwz       r0, 0x198(r26)
	  fctiwz    f0, f0
	  add       r3, r0, r29
	  lwz       r3, 0xC(r3)
	  stfd      f0, 0xA0(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0xA4(r1)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  xoris     r0, r27, 0x8000
	  lwz       r3, 0x198(r26)
	  stw       r0, 0x9C(r1)
	  li        r0, 0x1
	  add       r3, r3, r29
	  stw       r31, 0x98(r1)
	  lfd       f0, 0x98(r1)
	  stw       r0, 0x0(r3)
	  fsubs     f0, f0, f27
	  stfs      f30, 0x4(r3)
	  fmuls     f0, f31, f0
	  fadds     f0, f26, f0
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0xC(r3)
	  lha       r0, 0x18(r4)
	  lha       r4, 0x1A(r4)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x94(r1)
	  xoris     r0, r4, 0x8000
	  stw       r31, 0x90(r1)
	  stw       r0, 0x8C(r1)
	  lfd       f0, 0x90(r1)
	  stw       r31, 0x88(r1)
	  fsubs     f1, f0, f27
	  lfd       f0, 0x88(r1)
	  fsubs     f0, f0, f27
	  stfs      f1, 0x1C(r3)
	  stfs      f0, 0x20(r3)
	  lfs       f0, 0x27E8(r13)
	  stfs      f0, 0x24(r3)
	  stfs      f29, 0x28(r3)
	  stfs      f28, 0x2C(r3)
	  lfs       f0, 0x27EC(r13)
	  stfs      f0, 0x30(r3)
	  b         .loc_0x248

	.loc_0x220:
	  lwz       r3, 0x174(r26)
	  li        r4, 0
	  addi      r0, r29, 0xC
	  lwzx      r3, r3, r28
	  stb       r4, 0x14(r3)
	  lwz       r3, 0x198(r26)
	  lwzx      r3, r3, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x248:
	  addi      r29, r29, 0x34
	  addi      r28, r28, 0xC
	  addi      r27, r27, 0x1

	.loc_0x254:
	  lwz       r0, 0x10C(r26)
	  cmpw      r27, r0
	  blt+      .loc_0x94
	  addi      r3, r26, 0x114
	  lfs       f1, -0x3EDC(r2)
	  bl        -0x117E0
	  addi      r3, r26, 0x144
	  lfs       f1, -0x3EDC(r2)
	  bl        -0x117EC

	.loc_0x278:
	  lmw       r26, 0xA8(r1)
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lfd       f27, 0xD0(r1)
	  lfd       f26, 0xC8(r1)
	  lfd       f25, 0xC0(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801EC8D8
 * Size:	0003A4
 */
zen::DrawCMcourseSelect::DrawCMcourseSelect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r7, 0
	  stw       r0, 0x4(r1)
	  li        r6, -0x1
	  lis       r4, 0x802E
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stmw      r23, 0x7C(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8022
	  addi      r5, r3, 0x2758
	  addi      r29, r4, 0x6C78
	  li        r3, 0x4C4
	  lfs       f0, -0x3EDC(r2)
	  stfs      f0, 0x2C(r31)
	  stfs      f0, 0x28(r31)
	  stfs      f0, 0x24(r31)
	  stw       r7, 0x20(r31)
	  stw       r6, 0x30(r31)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x34(r31)
	  stw       r0, 0x38(r31)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x3C(r31)
	  stw       r7, 0x4C(r31)
	  stw       r6, 0x50(r31)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x54(r31)
	  stw       r0, 0x58(r31)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x5C(r31)
	  stw       r7, 0x68(r31)
	  stw       r7, 0x6C(r31)
	  stw       r7, 0x70(r31)
	  stw       r7, 0x74(r31)
	  lwz       r4, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r4, 0x7C(r31)
	  stw       r0, 0x80(r31)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x84(r31)
	  stw       r7, 0x78(r31)
	  bl        -0x1A5984
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0xD0
	  li        r4, 0x10
	  li        r5, 0x400
	  li        r6, 0x1
	  bl        -0x30E4

	.loc_0xD0:
	  stw       r23, 0x88(r31)
	  li        r3, 0x100
	  bl        -0x1A59AC
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0xFC
	  addi      r4, r29, 0x38
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x2D45C

	.loc_0xFC:
	  stw       r23, 0x0(r31)
	  li        r3, 0x100
	  bl        -0x1A59D8
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x128
	  addi      r4, r29, 0x50
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x2D488

	.loc_0x128:
	  stw       r23, 0x4(r31)
	  li        r3, 0x100
	  bl        -0x1A5A04
	  addi      r23, r3, 0
	  mr.       r3, r23
	  beq-      .loc_0x154
	  addi      r4, r29, 0x68
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0x1
	  bl        -0x2D4B4

	.loc_0x154:
	  stw       r23, 0x8(r31)
	  lis       r3, 0x7261
	  addi      r4, r3, 0x6E6B
	  lwz       r3, 0x4(r31)
	  li        r5, 0x1
	  lwz       r7, 0x0(r31)
	  addi      r28, r3, 0x4
	  lwz       r6, 0x8(r31)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  addi      r27, r7, 0x4
	  addi      r30, r6, 0x4
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r3)
	  li        r4, 0x163
	  li        r5, 0xEA
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lis       r4, 0x6265
	  addi      r4, r4, 0x7374
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r3)
	  li        r4, 0x195
	  li        r5, 0xA4
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r4, 0x6162
	  addi      r4, r4, 0x746E
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x8C(r31)
	  li        r26, 0
	  stb       r26, 0x90(r31)
	  lwz       r3, 0x8C(r31)
	  lbz       r4, 0x90(r31)
	  bl        -0x2D214
	  stw       r26, 0x14(r31)
	  li        r0, -0x3
	  li        r3, 0x19C
	  stw       r0, 0xC(r31)
	  bl        -0x1A5AFC
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0x360
	  stw       r25, 0x50(r1)
	  addi      r4, r29, 0x80
	  li        r5, 0x1
	  lwz       r3, 0x50(r1)
	  li        r6, 0x1
	  bl        0x3628
	  lis       r3, 0x802E
	  lwz       r23, 0x50(r1)
	  addi      r0, r3, 0x6D68
	  stw       r0, 0x0(r23)
	  lwz       r24, 0x10C(r23)
	  mulli     r3, r24, 0x34
	  addi      r3, r3, 0x8
	  bl        -0x1A5B40
	  lis       r4, 0x801F
	  subi      r4, r4, 0x3384
	  addi      r7, r24, 0
	  li        r5, 0
	  li        r6, 0x34
	  bl        0x280CC
	  stw       r3, 0x198(r23)
	  mr        r29, r26
	  lis       r24, 0x4330
	  lfd       f31, -0x3EC8(r2)
	  b         .loc_0x344

	.loc_0x29C:
	  addi      r5, r26, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x54
	  addi      r4, r13, 0x2818
	  bl        0x29A14
	  lwz       r23, 0x50(r1)
	  li        r5, 0x1
	  lbz       r0, 0x55(r1)
	  lwz       r12, 0x4(r23)
	  addi      r3, r23, 0x4
	  lbz       r4, 0x54(r1)
	  rlwinm    r0,r0,16,0,15
	  lwz       r12, 0x34(r12)
	  rlwimi    r0,r4,24,0,7
	  lbz       r6, 0x56(r1)
	  lbz       r4, 0x57(r1)
	  mtlr      r12
	  rlwimi    r0,r6,8,16,23
	  or        r4, r4, r0
	  blrl
	  lwz       r0, 0x198(r23)
	  addi      r26, r26, 0x1
	  add       r4, r0, r29
	  stw       r3, 0xC(r4)
	  addi      r29, r29, 0x34
	  lwz       r3, 0xC(r4)
	  lha       r0, 0x18(r3)
	  lha       r3, 0x1A(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x74(r1)
	  xoris     r0, r3, 0x8000
	  stw       r24, 0x70(r1)
	  stw       r0, 0x6C(r1)
	  lfd       f0, 0x70(r1)
	  stw       r24, 0x68(r1)
	  fsubs     f1, f0, f31
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f31
	  stfs      f1, 0x10(r4)
	  stfs      f0, 0x14(r4)
	  lfs       f0, 0x27F0(r13)
	  stfs      f0, 0x18(r4)

	.loc_0x344:
	  lwz       r4, 0x50(r1)
	  lwz       r0, 0x10C(r4)
	  cmpw      r26, r0
	  blt+      .loc_0x29C
	  lis       r3, 0x100
	  addi      r0, r3, 0x1000
	  stw       r0, 0x190(r4)

	.loc_0x360:
	  stw       r25, 0x1C(r31)
	  addi      r4, r27, 0
	  addi      r3, r31, 0x20
	  bl        0x83C
	  addi      r3, r31, 0x4C
	  addi      r4, r28, 0
	  bl        0xDB4
	  addi      r3, r31, 0x6C
	  addi      r4, r30, 0
	  bl        0x18B8
	  mr        r3, r31
	  lmw       r23, 0x7C(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ECC7C
 * Size:	000088
 */
zen::DrawCMCSmenu::MenuExpansion::MenuExpansion()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x3EDC(r2)
	  li        r0, 0
	  stfs      f1, 0x18(r3)
	  stfs      f1, 0x14(r3)
	  stfs      f1, 0x10(r3)
	  stfs      f1, 0x24(r3)
	  stfs      f1, 0x20(r3)
	  stfs      f1, 0x1C(r3)
	  stfs      f1, 0x30(r3)
	  stfs      f1, 0x2C(r3)
	  stfs      f1, 0x28(r3)
	  stw       r0, 0xC(r3)
	  lfs       f0, 0x27F4(r13)
	  stfs      f0, 0x10(r3)
	  lfs       f0, 0x27F8(r13)
	  stfs      f0, 0x14(r3)
	  lfs       f0, 0x27FC(r13)
	  stfs      f0, 0x18(r3)
	  lfs       f0, 0x2800(r13)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, 0x2804(r13)
	  stfs      f0, 0x20(r3)
	  lfs       f0, 0x2808(r13)
	  stfs      f0, 0x24(r3)
	  lfs       f0, 0x280C(r13)
	  stfs      f0, 0x28(r3)
	  lfs       f0, 0x2810(r13)
	  stfs      f0, 0x2C(r3)
	  lfs       f0, 0x2814(r13)
	  stfs      f0, 0x30(r3)
	  stfs      f1, 0x8(r3)
	  stfs      f1, 0x4(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
zen::DrawMenuBase::~DrawMenuBase()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801ECD04
 * Size:	000294
 */
void zen::DrawCMcourseSelect::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  stw       r30, 0x90(r1)
	  stw       r29, 0x8C(r1)
	  addi      r29, r3, 0
	  stw       r0, 0x14(r3)
	  lwz       r3, 0x88(r3)
	  bl        -0x305C
	  li        r0, -0x1
	  stw       r0, 0xC(r29)
	  addi      r3, r29, 0x20
	  lfs       f1, -0x3EC0(r2)
	  bl        0x910
	  lwz       r30, 0x1C(r29)
	  li        r31, 0
	  lwz       r4, 0x198(r30)
	  addi      r3, r30, 0x114
	  lwz       r4, 0xC(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x198(r30)
	  lwz       r4, 0x40(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x198(r30)
	  lwz       r4, 0x74(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x198(r30)
	  lwz       r4, 0xA8(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lwz       r4, 0x198(r30)
	  lwz       r4, 0xDC(r4)
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  lfs       f1, -0x3EDC(r2)
	  bl        -0x11D04
	  addi      r3, r30, 0x144
	  lfs       f1, -0x3EDC(r2)
	  bl        -0x11D10
	  addi      r3, r29, 0x4C
	  bl        0x12A4
	  lwz       r4, 0x70(r29)
	  mr        r3, r29
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r31,7,24,24
	  stb       r0, 0xC(r4)
	  bl        .loc_0x294
	  lfs       f0, 0x2820(r13)
	  addi      r5, r1, 0x78
	  lfs       f1, 0x2824(r13)
	  li        r4, 0x19
	  stfs      f0, 0x78(r1)
	  lfs       f0, 0x2828(r13)
	  li        r6, 0
	  stfs      f1, 0x7C(r1)
	  li        r7, 0
	  stfs      f0, 0x80(r1)
	  lwz       r3, 0x88(r29)
	  bl        -0x32DC
	  lfs       f0, 0x282C(r13)
	  addi      r5, r1, 0x6C
	  lfs       f1, 0x2830(r13)
	  li        r4, 0x1A
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x2834(r13)
	  li        r6, 0
	  stfs      f1, 0x70(r1)
	  li        r7, 0
	  stfs      f0, 0x74(r1)
	  lwz       r3, 0x88(r29)
	  bl        -0x330C
	  lfs       f0, 0x2838(r13)
	  addi      r5, r1, 0x60
	  lfs       f1, 0x283C(r13)
	  li        r4, 0x1B
	  stfs      f0, 0x60(r1)
	  lfs       f0, 0x2840(r13)
	  li        r6, 0
	  stfs      f1, 0x64(r1)
	  li        r7, 0
	  stfs      f0, 0x68(r1)
	  lwz       r3, 0x88(r29)
	  bl        -0x333C
	  lfs       f0, 0x2844(r13)
	  addi      r5, r1, 0x54
	  lfs       f1, 0x2848(r13)
	  li        r4, 0x1C
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x284C(r13)
	  li        r6, 0
	  stfs      f1, 0x58(r1)
	  li        r7, 0
	  stfs      f0, 0x5C(r1)
	  lwz       r3, 0x88(r29)
	  bl        -0x336C
	  lfs       f0, 0x2850(r13)
	  addi      r5, r1, 0x48
	  lfs       f1, 0x2854(r13)
	  li        r4, 0x1D
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x2858(r13)
	  li        r6, 0
	  stfs      f1, 0x4C(r1)
	  li        r7, 0
	  stfs      f0, 0x50(r1)
	  lwz       r3, 0x88(r29)
	  bl        -0x339C
	  lfs       f0, 0x285C(r13)
	  addi      r5, r1, 0x3C
	  lfs       f1, 0x2860(r13)
	  li        r4, 0x1E
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x2864(r13)
	  li        r6, 0
	  stfs      f1, 0x40(r1)
	  li        r7, 0
	  stfs      f0, 0x44(r1)
	  lwz       r3, 0x88(r29)
	  bl        -0x33CC
	  lfs       f0, 0x2868(r13)
	  addi      r5, r1, 0x30
	  lfs       f1, 0x286C(r13)
	  li        r4, 0x1F
	  stfs      f0, 0x30(r1)
	  lfs       f0, 0x2870(r13)
	  li        r6, 0
	  stfs      f1, 0x34(r1)
	  li        r7, 0
	  stfs      f0, 0x38(r1)
	  lwz       r3, 0x88(r29)
	  bl        -0x33FC
	  lfs       f0, 0x2874(r13)
	  addi      r5, r1, 0x24
	  lfs       f1, 0x2878(r13)
	  li        r4, 0x20
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x287C(r13)
	  li        r6, 0
	  stfs      f1, 0x28(r1)
	  li        r7, 0
	  stfs      f0, 0x2C(r1)
	  lwz       r3, 0x88(r29)
	  bl        -0x342C
	  stb       r31, 0x90(r29)
	  lwz       r3, 0x8C(r29)
	  lbz       r4, 0x90(r29)
	  bl        -0x2D6A0
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  lwz       r29, 0x8C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr

	.loc_0x294:
	*/
}

/*
 * --INFO--
 * Address:	801ECF98
 * Size:	000080
 */
void zen::DrawCMcourseSelect::setBestScore()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  mr        r29, r3
	  lwz       r4, 0x1C(r3)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x108(r4)
	  addi      r3, r3, 0x94
	  addi      r4, r1, 0x18
	  stw       r0, 0x18(r1)
	  bl        -0x19910C
	  li        r30, 0
	  addi      r31, r1, 0x18

	.loc_0x44:
	  lwz       r5, 0xC(r31)
	  addi      r4, r30, 0
	  addi      r3, r29, 0x4C
	  bl        0x12D8
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x5
	  addi      r31, r31, 0x4
	  blt+      .loc_0x44
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED018
 * Size:	00011C
 */
void zen::DrawCMcourseSelect::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x84
	  bge-      .loc_0x38
	  cmpwi     r0, 0x1
	  bge-      .loc_0x44
	  b         .loc_0xA4

	.loc_0x38:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xA4
	  b         .loc_0xA0

	.loc_0x44:
	  lwz       r0, 0x48(r30)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0xA4
	  li        r0, 0x2
	  stw       r0, 0x14(r30)
	  lwz       r3, 0x1C(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0x4C
	  lfs       f1, -0x3ED4(r2)
	  bl        0x1088
	  addi      r3, r30, 0x6C
	  bl        0x1784
	  b         .loc_0xA4

	.loc_0x84:
	  mr        r3, r30
	  bl        0x170
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA4
	  li        r0, 0x3
	  stw       r0, 0x14(r30)
	  b         .loc_0xA4

	.loc_0xA0:
	  li        r31, 0x1

	.loc_0xA4:
	  addi      r3, r30, 0x20
	  bl        0x518
	  addi      r3, r30, 0x4C
	  bl        0xF30
	  addi      r3, r30, 0x6C
	  bl        0x16CC
	  lwz       r3, 0x0(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x88(r30)
	  bl        -0x358C
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED134
 * Size:	000044
 */
void zen::DrawCMCSmenu::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        0x366C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0x2
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED178
 * Size:	000090
 */
void zen::DrawCMcourseSelect::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0x88(r3)
	  bl        -0x35EC
	  lwz       r3, 0x1C(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x8(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
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
 * Address:	801ED208
 * Size:	000008
 */
void zen::DrawCMcourseSelect::getReturnStatusFlag()
{
	/*
	.loc_0x0:
	  lwz       r3, 0xC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED210
 * Size:	000100
 */
void zen::DrawCMcourseSelect::modeOperation(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r3
	  stw       r30, 0x60(r1)
	  stw       r29, 0x5C(r1)
	  stw       r28, 0x58(r1)
	  lwz       r3, 0x1C(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x1C(r31)
	  mr        r28, r3
	  lwz       r0, 0x18C(r4)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x8C
	  lwz       r0, 0x108(r4)
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  stw       r0, 0x28(r1)
	  addi      r3, r3, 0x94
	  addi      r4, r1, 0x28
	  bl        -0x1993AC
	  li        r30, 0
	  addi      r29, r1, 0x28

	.loc_0x6C:
	  lwz       r5, 0xC(r29)
	  addi      r4, r30, 0
	  addi      r3, r31, 0x4C
	  bl        0x1038
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x5
	  addi      r29, r29, 0x4
	  blt+      .loc_0x6C

	.loc_0x8C:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0xBC
	  lwz       r3, 0x1C(r31)
	  lwz       r0, 0x2950(r13)
	  lwz       r3, 0x108(r3)
	  cmpw      r3, r0
	  bne-      .loc_0xB4
	  li        r0, -0x2
	  stw       r0, 0xC(r31)
	  b         .loc_0xB8

	.loc_0xB4:
	  stw       r3, 0xC(r31)

	.loc_0xB8:
	  li        r28, 0x1

	.loc_0xBC:
	  lbz       r3, 0x90(r31)
	  cmplwi    r3, 0xFF
	  bge-      .loc_0xDC
	  addi      r0, r3, 0x1
	  stb       r0, 0x90(r31)
	  lwz       r3, 0x8C(r31)
	  lbz       r4, 0x90(r31)
	  bl        -0x2DA10

	.loc_0xDC:
	  mr        r3, r28
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  lwz       r28, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED310
 * Size:	000168
 */
void zen::DrawCMCSmenu::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stfd      f30, 0x58(r1)
	  stfd      f29, 0x50(r1)
	  stfd      f28, 0x48(r1)
	  stmw      r27, 0x34(r1)
	  mr        r27, r3
	  mr        r28, r4
	  li        r29, 0
	  li        r31, 0
	  lfs       f31, -0x3ED8(r2)
	  lfs       f28, -0x3EE0(r2)
	  lfs       f29, -0x3EDC(r2)
	  lfs       f30, -0x3ED4(r2)

	.loc_0x40:
	  lwz       r0, 0x198(r27)
	  add       r30, r0, r31
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x58
	  b         .loc_0x128

	.loc_0x58:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x94
	  stfs      f0, 0x4(r30)
	  li        r0, 0
	  lfs       f1, -0x3EE0(r2)
	  lfs       f4, -0x3EDC(r2)
	  stw       r0, 0x0(r30)
	  b         .loc_0xA4

	.loc_0x94:
	  fdivs     f0, f1, f0
	  fmuls     f1, f31, f0
	  bl        0x2E93C
	  fsubs     f4, f28, f1

	.loc_0xA4:
	  lfs       f2, 0x20(r30)
	  lfs       f0, 0x2C(r30)
	  fmuls     f2, f2, f4
	  fmuls     f0, f0, f1
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xCC
	  fadds     f0, f30, f0
	  b         .loc_0xD0

	.loc_0xCC:
	  fsubs     f0, f0, f30

	.loc_0xD0:
	  lfs       f2, 0x1C(r30)
	  fctiwz    f3, f0
	  lfs       f0, 0x28(r30)
	  fmuls     f2, f2, f4
	  fmuls     f0, f0, f1
	  stfd      f3, 0x28(r1)
	  lwz       r5, 0x2C(r1)
	  fadds     f0, f2, f0
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x104
	  fadds     f0, f30, f0
	  b         .loc_0x108

	.loc_0x104:
	  fsubs     f0, f0, f30

	.loc_0x108:
	  lwz       r3, 0xC(r30)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x28(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x2C(r1)
	  mtlr      r12
	  blrl

	.loc_0x128:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x5
	  addi      r31, r31, 0x34
	  blt+      .loc_0x40
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  bl        0x3134
	  lmw       r27, 0x34(r1)
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  lfd       f29, 0x50(r1)
	  lfd       f28, 0x48(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801ED478
 * Size:	000008
 */
u32 zen::DrawMenuBase::modeDefault(Controller*) { return 0x0; }
