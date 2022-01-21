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
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800849E8
 * Size:	00002C
 */
void AIPerf::clearCounts()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x2FD4(r13)
	  stw       r0, 0x2FD0(r13)
	  stw       r0, 0x2FCC(r13)
	  stw       r0, 0x2FC8(r13)
	  stw       r0, 0x2FC4(r13)
	  stw       r0, 0x2FC0(r13)
	  stw       r0, 0x2FBC(r13)
	  stw       r0, 0x2FB8(r13)
	  stw       r0, 0x2FB4(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80084A14
 * Size:	000C20
 */
void AIPerf::addMenu(Menu*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x128(r1)
	  stw       r31, 0x124(r1)
	  subi      r31, r5, 0x16E0
	  stw       r30, 0x120(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x11C(r1)
	  addi      r29, r3, 0
	  li        r3, 0x40
	  stw       r28, 0x118(r1)
	  bl        -0x3DA40
	  li        r3, 0x14
	  bl        -0x3DA48
	  mr.       r6, r3
	  beq-      .loc_0x90
	  lwz       r0, 0x3C(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x40(r31)
	  lis       r4, 0x802A
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xF8(r1)
	  addi      r0, r4, 0x7A80
	  stw       r7, 0xFC(r1)
	  lwz       r4, 0x44(r31)
	  stw       r4, 0x100(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r30, 0x4(r3)
	  lwz       r4, 0xF8(r1)
	  lwz       r0, 0xFC(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x100(r1)
	  stw       r0, 0x10(r3)

	.loc_0x90:
	  addi      r3, r30, 0
	  li        r4, 0x20
	  li        r5, 0x2000
	  bl        -0x2715C
	  li        r3, 0x40
	  bl        -0x3DAB4
	  lbz       r0, -0x5F15(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0xC0
	  addi      r5, r31, 0x12C
	  b         .loc_0xC4

	.loc_0xC0:
	  addi      r5, r31, 0x13C

	.loc_0xC4:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x191AB4
	  li        r3, 0x14
	  bl        -0x3DAE8
	  mr.       r6, r3
	  beq-      .loc_0x130
	  lwz       r0, 0x48(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x4C(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xEC(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0xF0(r1)
	  lwz       r4, 0x50(r31)
	  stw       r4, 0xF4(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0xEC(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xF4(r1)
	  stw       r0, 0x10(r3)

	.loc_0x130:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x27038
	  li        r3, 0x40
	  bl        -0x3DB58
	  lbz       r0, 0x2FA0(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  addi      r5, r31, 0x150
	  b         .loc_0x168

	.loc_0x164:
	  addi      r5, r31, 0x164

	.loc_0x168:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x191A10
	  li        r3, 0x14
	  bl        -0x3DB8C
	  mr.       r6, r3
	  beq-      .loc_0x1D4
	  lwz       r0, 0x54(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x58(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xE0(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0xE4(r1)
	  lwz       r4, 0x5C(r31)
	  stw       r4, 0xE8(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0xE0(r1)
	  lwz       r0, 0xE4(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xE8(r1)
	  stw       r0, 0x10(r3)

	.loc_0x1D4:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x270DC
	  li        r3, 0x40
	  bl        -0x3DBFC
	  lwz       r5, -0x5F04(r13)
	  crclr     6, 0x6
	  addi      r28, r3, 0
	  addi      r4, r31, 0x178
	  bl        0x191984
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x27110
	  li        r3, 0x14
	  bl        -0x3DC30
	  mr.       r6, r3
	  beq-      .loc_0x278
	  lwz       r0, 0x60(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x64(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xD4(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0xD8(r1)
	  lwz       r4, 0x68(r31)
	  stw       r4, 0xDC(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0xD4(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xDC(r1)
	  stw       r0, 0x10(r3)

	.loc_0x278:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x8
	  bl        -0x27348
	  li        r3, 0x14
	  bl        -0x3DCA0
	  mr.       r6, r3
	  beq-      .loc_0x2E8
	  lwz       r0, 0x6C(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x70(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xC8(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0xCC(r1)
	  lwz       r4, 0x74(r31)
	  stw       r4, 0xD0(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0xC8(r1)
	  lwz       r0, 0xCC(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xD0(r1)
	  stw       r0, 0x10(r3)

	.loc_0x2E8:
	  addi      r3, r30, 0
	  li        r4, 0x8
	  li        r5, 0x4000
	  bl        -0x273B4
	  li        r3, 0x40
	  bl        -0x3DD0C
	  lbz       r0, -0x5F16(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x318
	  addi      r5, r31, 0x188
	  b         .loc_0x31C

	.loc_0x318:
	  addi      r5, r31, 0x198

	.loc_0x31C:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x19185C
	  li        r3, 0x14
	  bl        -0x3DD40
	  mr.       r6, r3
	  beq-      .loc_0x388
	  lwz       r0, 0x78(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x7C(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xBC(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0xC0(r1)
	  lwz       r4, 0x80(r31)
	  stw       r4, 0xC4(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0xBC(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xC4(r1)
	  stw       r0, 0x10(r3)

	.loc_0x388:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x27290
	  li        r3, 0x40
	  bl        -0x3DDB0
	  lbz       r0, 0x2FA8(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x3BC
	  addi      r5, r31, 0x1AC
	  b         .loc_0x3C0

	.loc_0x3BC:
	  addi      r5, r31, 0x1C0

	.loc_0x3C0:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x1917B8
	  li        r3, 0x14
	  bl        -0x3DDE4
	  mr.       r6, r3
	  beq-      .loc_0x42C
	  lwz       r0, 0x84(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x88(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xB0(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0xB4(r1)
	  lwz       r4, 0x8C(r31)
	  stw       r4, 0xB8(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0xB0(r1)
	  lwz       r0, 0xB4(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xB8(r1)
	  stw       r0, 0x10(r3)

	.loc_0x42C:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x27334
	  li        r3, 0x40
	  bl        -0x3DE54
	  lbz       r0, 0x2FA9(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x460
	  addi      r5, r31, 0x1D4
	  b         .loc_0x464

	.loc_0x460:
	  addi      r5, r31, 0x1E8

	.loc_0x464:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x191714
	  li        r3, 0x14
	  bl        -0x3DE88
	  mr.       r6, r3
	  beq-      .loc_0x4D0
	  lwz       r0, 0x90(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x94(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0xA4(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0xA8(r1)
	  lwz       r4, 0x98(r31)
	  stw       r4, 0xAC(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0xA4(r1)
	  lwz       r0, 0xA8(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xAC(r1)
	  stw       r0, 0x10(r3)

	.loc_0x4D0:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x273D8
	  li        r3, 0x40
	  bl        -0x3DEF8
	  lbz       r0, 0x2FA1(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x504
	  addi      r5, r31, 0x1FC
	  b         .loc_0x508

	.loc_0x504:
	  addi      r5, r31, 0x20C

	.loc_0x508:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x191670
	  li        r3, 0x14
	  bl        -0x3DF2C
	  mr.       r6, r3
	  beq-      .loc_0x574
	  lwz       r0, 0x9C(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xA0(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x98(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x9C(r1)
	  lwz       r4, 0xA4(r31)
	  stw       r4, 0xA0(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x98(r1)
	  lwz       r0, 0x9C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0xA0(r1)
	  stw       r0, 0x10(r3)

	.loc_0x574:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x2747C
	  li        r3, 0x40
	  bl        -0x3DF9C
	  lis       r4, 0x8022
	  lwz       r0, 0x2FA4(r13)
	  addi      r6, r4, 0x23E0
	  crclr     6, 0x6
	  lwz       r5, 0x0(r6)
	  rlwinm    r0,r0,2,0,29
	  lwz       r4, 0x4(r6)
	  mr        r28, r3
	  stw       r5, 0x104(r1)
	  addi      r5, r1, 0x104
	  stw       r4, 0x108(r1)
	  subi      r4, r13, 0x5EE8
	  lwz       r6, 0x8(r6)
	  stw       r6, 0x10C(r1)
	  lwzx      r5, r5, r0
	  bl        0x1915B8
	  li        r3, 0x14
	  bl        -0x3DFE4
	  mr.       r6, r3
	  beq-      .loc_0x62C
	  lwz       r0, 0xA8(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xAC(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x8C(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x90(r1)
	  lwz       r4, 0xB0(r31)
	  stw       r4, 0x94(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x8C(r1)
	  lwz       r0, 0x90(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x94(r1)
	  stw       r0, 0x10(r3)

	.loc_0x62C:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x27534
	  li        r3, 0x40
	  bl        -0x3E054
	  lbz       r0, -0x5F18(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x660
	  addi      r5, r31, 0x218
	  b         .loc_0x664

	.loc_0x660:
	  addi      r5, r31, 0x224

	.loc_0x664:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x191514
	  li        r3, 0x14
	  bl        -0x3E088
	  mr.       r6, r3
	  beq-      .loc_0x6D0
	  lwz       r0, 0xB4(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xB8(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x80(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x84(r1)
	  lwz       r4, 0xBC(r31)
	  stw       r4, 0x88(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x10(r3)

	.loc_0x6D0:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x275D8
	  li        r3, 0x40
	  bl        -0x3E0F8
	  lbz       r0, -0x5F17(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x704
	  addi      r5, r31, 0x230
	  b         .loc_0x708

	.loc_0x704:
	  addi      r5, r31, 0x23C

	.loc_0x708:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x191470
	  li        r3, 0x14
	  bl        -0x3E12C
	  mr.       r6, r3
	  beq-      .loc_0x774
	  lwz       r0, 0xC0(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xC4(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x74(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x78(r1)
	  lwz       r4, 0xC8(r31)
	  stw       r4, 0x7C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x774:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x2767C
	  li        r3, 0x40
	  bl        -0x3E19C
	  lbz       r0, -0x5F14(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x7A8
	  addi      r5, r31, 0x248
	  b         .loc_0x7AC

	.loc_0x7A8:
	  addi      r5, r31, 0x254

	.loc_0x7AC:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x1913CC
	  li        r3, 0x14
	  bl        -0x3E1D0
	  mr.       r6, r3
	  beq-      .loc_0x818
	  lwz       r0, 0xCC(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xD0(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x68(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x6C(r1)
	  lwz       r4, 0xD4(r31)
	  stw       r4, 0x70(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0x10(r3)

	.loc_0x818:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x27720
	  li        r3, 0x40
	  bl        -0x3E240
	  lbz       r0, -0x5F07(r13)
	  addi      r28, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x84C
	  addi      r5, r31, 0x260
	  b         .loc_0x850

	.loc_0x84C:
	  addi      r5, r31, 0x26C

	.loc_0x850:
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  bl        0x191328
	  li        r3, 0x14
	  bl        -0x3E274
	  mr.       r6, r3
	  beq-      .loc_0x8BC
	  lwz       r0, 0xD8(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xDC(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x5C(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x60(r1)
	  lwz       r4, 0xE0(r31)
	  stw       r4, 0x64(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x5C(r1)
	  lwz       r0, 0x60(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x64(r1)
	  stw       r0, 0x10(r3)

	.loc_0x8BC:
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r7, 0x1
	  bl        -0x277C4
	  li        r3, 0x40
	  bl        -0x3E2E4
	  lwz       r5, 0x2FB0(r13)
	  crclr     6, 0x6
	  addi      r28, r3, 0
	  addi      r4, r31, 0x278
	  bl        0x19129C
	  addi      r3, r30, 0
	  addi      r5, r28, 0
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x277F8
	  li        r3, 0x14
	  bl        -0x3E318
	  mr.       r6, r3
	  beq-      .loc_0x960
	  lwz       r0, 0xE4(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xE8(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x50(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x54(r1)
	  lwz       r4, 0xEC(r31)
	  stw       r4, 0x58(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x58(r1)
	  stw       r0, 0x10(r3)

	.loc_0x960:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x8
	  bl        -0x27A30
	  li        r3, 0x14
	  bl        -0x3E388
	  mr.       r6, r3
	  beq-      .loc_0x9D0
	  lwz       r0, 0xF0(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0xF4(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x44(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x48(r1)
	  lwz       r4, 0xF8(r31)
	  stw       r4, 0x4C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x44(r1)
	  lwz       r0, 0x48(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x4C(r1)
	  stw       r0, 0x10(r3)

	.loc_0x9D0:
	  addi      r3, r30, 0
	  li        r4, 0x8
	  li        r5, 0x4000
	  bl        -0x27A9C
	  addi      r3, r30, 0
	  addi      r5, r31, 0x288
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x278EC
	  li        r3, 0x14
	  bl        -0x3E40C
	  mr.       r6, r3
	  beq-      .loc_0xA54
	  lwz       r0, 0xFC(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x100(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x38(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x3C(r1)
	  lwz       r4, 0x104(r31)
	  stw       r4, 0x40(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0x10(r3)

	.loc_0xA54:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x8
	  bl        -0x27B24
	  addi      r3, r30, 0
	  addi      r5, r31, 0x298
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x27974
	  li        r3, 0x14
	  bl        -0x3E494
	  mr.       r6, r3
	  beq-      .loc_0xADC
	  lwz       r0, 0x108(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x10C(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x2C(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x30(r1)
	  lwz       r4, 0x110(r31)
	  stw       r4, 0x34(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x10(r3)

	.loc_0xADC:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x8
	  bl        -0x27BAC
	  addi      r3, r30, 0
	  addi      r5, r31, 0x2A8
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x279FC
	  li        r3, 0x14
	  bl        -0x3E51C
	  mr.       r6, r3
	  beq-      .loc_0xB64
	  lwz       r0, 0x114(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x118(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x20(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x24(r1)
	  lwz       r4, 0x11C(r31)
	  stw       r4, 0x28(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x10(r3)

	.loc_0xB64:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x8
	  bl        -0x27C34
	  addi      r3, r30, 0
	  addi      r5, r31, 0x2B8
	  li        r4, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        -0x27A84
	  li        r3, 0x14
	  bl        -0x3E5A4
	  mr.       r6, r3
	  beq-      .loc_0xBEC
	  lwz       r0, 0x120(r31)
	  lis       r5, 0x802A
	  lwz       r7, 0x124(r31)
	  lis       r4, 0x802B
	  addi      r5, r5, 0x65F0
	  stw       r0, 0x14(r1)
	  subi      r0, r4, 0x1214
	  stw       r7, 0x18(r1)
	  lwz       r4, 0x128(r31)
	  stw       r4, 0x1C(r1)
	  stw       r5, 0x0(r3)
	  stw       r0, 0x0(r3)
	  stw       r29, 0x4(r3)
	  lwz       r4, 0x14(r1)
	  lwz       r0, 0x18(r1)
	  stw       r4, 0x8(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x1C(r1)
	  stw       r0, 0x10(r3)

	.loc_0xBEC:
	  lis       r4, 0x1
	  subi      r5, r4, 0x8000
	  addi      r3, r30, 0
	  li        r4, 0x8
	  bl        -0x27CBC
	  lwz       r0, 0x12C(r1)
	  lwz       r31, 0x124(r1)
	  lwz       r30, 0x120(r1)
	  lwz       r29, 0x11C(r1)
	  lwz       r28, 0x118(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085634
 * Size:	000088
 */
void AIPerf::toggleMoveType(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  lis       r5, 0x5555
	  addi      r0, r5, 0x5556
	  crclr     6, 0x6
	  stwu      r1, -0x20(r1)
	  addi      r7, r3, 0x23EC
	  lwz       r6, 0x2FA4(r13)
	  addi      r3, r1, 0x10
	  addi      r6, r6, 0x1
	  mulhw     r5, r0, r6
	  rlwinm    r0,r5,1,31,31
	  add       r0, r5, r0
	  mulli     r0, r0, 0x3
	  sub       r0, r6, r0
	  stw       r0, 0x2FA4(r13)
	  lwz       r6, 0x0(r7)
	  lwz       r5, 0x4(r7)
	  lwz       r0, 0x2FA4(r13)
	  stw       r6, 0x10(r1)
	  rlwinm    r0,r0,2,0,29
	  stw       r5, 0x14(r1)
	  lwz       r5, 0x8(r7)
	  stw       r5, 0x18(r1)
	  lwz       r6, 0x30(r4)
	  subi      r4, r13, 0x5EE8
	  lwzx      r5, r3, r0
	  lwz       r3, 0x18(r6)
	  bl        0x190EF0
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800856BC
 * Size:	000078
 */
void AIPerf::toggleGeneratorMode(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x2FA1(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x2FA1(r13)
	  lbz       r0, 0x2FA1(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x14E4
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x14D4

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190E78
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085734
 * Size:	000078
 */
void AIPerf::toggleBridge(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, -0x5F15(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, -0x5F15(r13)
	  lbz       r0, -0x5F15(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x15B4
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x1418

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190E00
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800857AC
 * Size:	000078
 */
void AIPerf::toggleShowRoute(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x2FA0(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x2FA0(r13)
	  lbz       r0, 0x2FA0(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x1590
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x157C

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190D88
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void AIPerf::toggleAIGrid(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80085824
 * Size:	000078
 */
void AIPerf::toggleKando(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x2FA8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x2FA8(r13)
	  lbz       r0, 0x2FA8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x1534
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x13E4

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190D10
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008589C
 * Size:	000078
 */
void AIPerf::toggleLOD(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, -0x5F18(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, -0x5F18(r13)
	  lbz       r0, -0x5F18(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x14C8
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x14BC

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190C98
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085914
 * Size:	000078
 */
void AIPerf::toggleColls(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, -0x5F17(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, -0x5F17(r13)
	  lbz       r0, -0x5F17(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x14B0
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x14A4

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190C20
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8008598C
 * Size:	000078
 */
void AIPerf::toggleASync(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, -0x5F14(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, -0x5F14(r13)
	  lbz       r0, -0x5F14(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x1498
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x148C

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190BA8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085A04
 * Size:	000078
 */
void AIPerf::toggleInsQuick(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, -0x5F07(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, -0x5F07(r13)
	  lbz       r0, -0x5F07(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x1480
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x1474

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190B30
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085A7C
 * Size:	000078
 */
void AIPerf::toggleSoundDebug(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x2FA9(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x2FA9(r13)
	  lbz       r0, 0x2FA9(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x150C
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x14F8

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190AB8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void AIPerf::toggleUpdateMgr(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void AIPerf::togglePikiMabiki(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void AIPerf::togglePsOptimise(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80085AF4
 * Size:	000078
 */
void AIPerf::toggleCollSort(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, -0x5F16(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r0, 0
	  b         .loc_0x24

	.loc_0x20:
	  li        r0, 0x1

	.loc_0x24:
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, -0x5F16(r13)
	  lbz       r0, -0x5F16(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x4C
	  lis       r3, 0x802B
	  subi      r5, r3, 0x1558
	  b         .loc_0x54

	.loc_0x4C:
	  lis       r3, 0x802B
	  subi      r5, r3, 0x1548

	.loc_0x54:
	  lwz       r3, 0x30(r4)
	  crclr     6, 0x6
	  subi      r4, r13, 0x5EE8
	  lwz       r3, 0x18(r3)
	  bl        0x190A40
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void AIPerf::toggleIteratorCull(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void AIPerf::toggleUseGrid(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void AIPerf::incGridShift(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void AIPerf::decGridShift(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80085B6C
 * Size:	00004C
 */
void AIPerf::incOptLevel(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, -0x5F04(r13)
	  cmpwi     r3, 0x3
	  bge-      .loc_0x20
	  addi      r0, r3, 0x1
	  stw       r0, -0x5F04(r13)

	.loc_0x20:
	  lwz       r6, 0x30(r4)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x1568
	  lwz       r5, -0x5F04(r13)
	  lwz       r3, 0x18(r6)
	  crclr     6, 0x6
	  bl        0x1909F4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085BB8
 * Size:	00004C
 */
void AIPerf::decOptLevel(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, -0x5F04(r13)
	  cmpwi     r3, 0
	  ble-      .loc_0x20
	  subi      r0, r3, 0x1
	  stw       r0, -0x5F04(r13)

	.loc_0x20:
	  lwz       r6, 0x30(r4)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x1568
	  lwz       r5, -0x5F04(r13)
	  lwz       r3, 0x18(r6)
	  crclr     6, 0x6
	  bl        0x1909A8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085C04
 * Size:	000160
 */
void AIPerf::incUfoLevel(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  stw       r28, 0x20(r1)
	  lwz       r0, 0x2FB0(r13)
	  cmpwi     r0, 0x1E
	  bgt-      .loc_0x124
	  cmpwi     r0, 0x10
	  li        r30, 0
	  blt-      .loc_0x3C
	  li        r30, 0x1

	.loc_0x3C:
	  lwz       r3, 0x30AC(r13)
	  bl        0x6CFF4
	  lwz       r4, 0x2F6C(r13)
	  mr.       r29, r3
	  lbz       r28, 0x10(r4)
	  beq-      .loc_0xCC
	  lwz       r0, 0x2FB0(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x90
	  cmplwi    r29, 0
	  addi      r5, r29, 0
	  beq-      .loc_0x70
	  addi      r5, r5, 0x2B8

	.loc_0x70:
	  addi      r3, r1, 0x18
	  li        r4, 0
	  bl        0x99310
	  addi      r5, r3, 0
	  addi      r3, r29, 0x524
	  li        r4, 0
	  bl        0x6408C
	  b         .loc_0xBC

	.loc_0x90:
	  cmplwi    r29, 0
	  addi      r5, r29, 0
	  beq-      .loc_0xA0
	  addi      r5, r5, 0x2B8

	.loc_0xA0:
	  addi      r3, r1, 0x10
	  li        r4, 0x1
	  bl        0x992E0
	  addi      r5, r3, 0
	  addi      r3, r29, 0x524
	  li        r4, 0
	  bl        0x6405C

	.loc_0xBC:
	  lfs       f1, -0x75D0(r2)
	  addi      r3, r29, 0x524
	  li        r4, 0
	  bl        0x64084

	.loc_0xCC:
	  lwz       r4, 0x2FB0(r13)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x1338
	  lwz       r3, 0x2F6C(r13)
	  rlwinm    r4,r4,2,0,29
	  add       r4, r0, r4
	  lwz       r4, 0x0(r4)
	  mr        r5, r30
	  bl        -0x49D8
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x4D08
	  cmplwi    r29, 0
	  beq-      .loc_0x118
	  lwz       r3, 0x2F6C(r13)
	  lbz       r4, 0x10(r3)
	  cmpw      r28, r4
	  beq-      .loc_0x118
	  mr        r3, r29
	  bl        0x61B4C

	.loc_0x118:
	  lwz       r3, 0x2FB0(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2FB0(r13)

	.loc_0x124:
	  lwz       r6, 0x30(r31)
	  lis       r3, 0x802B
	  subi      r4, r3, 0x12C0
	  lwz       r5, 0x2FB0(r13)
	  lwz       r3, 0x18(r6)
	  crclr     6, 0x6
	  bl        0x190858
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085D64
 * Size:	000038
 */
void AIPerf::decUfoLevel(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802B
	  stw       r0, 0x4(r1)
	  crclr     6, 0x6
	  stwu      r1, -0x8(r1)
	  lwz       r6, 0x30(r4)
	  subi      r4, r3, 0x12C0
	  lwz       r5, 0x2FB0(r13)
	  lwz       r3, 0x18(r6)
	  bl        0x190810
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void AIPerf::toggleUpdateSearchBuffer(Menu&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80085D9C
 * Size:	000170
 */
void AIPerf::collectPikis(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  stw       r30, 0x40(r1)
	  stw       r29, 0x3C(r1)
	  lwz       r3, 0x3120(r13)
	  bl        0x9160C
	  lfs       f0, 0x6F0(r3)
	  lwz       r30, 0x3068(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x6F4(r3)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x6F8(r3)
	  mr        r3, r30
	  stfs      f0, 0x30(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0xF8

	.loc_0x58:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x80
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0x9C

	.loc_0x80:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x9C:
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDC
	  lwz       r0, 0x184(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xDC
	  lwz       r3, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x9C(r31)

	.loc_0xDC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0xF8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x120
	  li        r0, 0x1
	  b         .loc_0x14C

	.loc_0x120:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x148
	  li        r0, 0x1
	  b         .loc_0x14C

	.loc_0x148:
	  li        r0, 0

	.loc_0x14C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x58
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
 * Address:	80085F0C
 * Size:	0000B8
 */
void AIPerf::fullfillPiki(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803D
	  stw       r0, 0x4(r1)
	  lis       r3, 0x803D
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r30, r4, 0x1DF0
	  addi      r31, r3, 0x1EA0
	  li        r28, 0

	.loc_0x24:
	  lwz       r3, 0x2F6C(r13)
	  li        r0, 0x1
	  slw       r0, r0, r28
	  lbz       r3, 0x184(r3)
	  and.      r0, r3, r0
	  beq-      .loc_0x98
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r28
	  bl        0x6CA68
	  mr.       r29, r3
	  beq-      .loc_0x98
	  li        r27, 0

	.loc_0x54:
	  lhz       r4, 0x428(r29)
	  addi      r3, r30, 0
	  li        r5, 0
	  bl        0x3F8AC
	  lwz       r3, 0x42C(r29)
	  addi      r0, r3, 0x1
	  stw       r0, 0x42C(r29)
	  lhz       r0, 0x428(r29)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r31, r0
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x8C5CC
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x64
	  blt+      .loc_0x54

	.loc_0x98:
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x3
	  blt+      .loc_0x24
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80085FC4
 * Size:	000114
 */
void AIPerf::flowerPiki(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xA0

	.loc_0x34:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x70

	.loc_0x58:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  lwz       r12, 0x0(r3)
	  li        r4, 0x2
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xA0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC8
	  li        r0, 0x1
	  b         .loc_0xF4

	.loc_0xC8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xF0
	  li        r0, 0x1
	  b         .loc_0xF4

	.loc_0xF0:
	  li        r0, 0

	.loc_0xF4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x34
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800860D8
 * Size:	000398
 */
void AIPerf::breakSluice(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stmw      r26, 0x60(r1)
	  lwz       r3, 0x3120(r13)
	  bl        0x912D0
	  mr.       r31, r3
	  beq-      .loc_0x37C
	  lwz       r3, 0x30AC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x37C
	  lwz       r28, 0x68(r3)
	  li        r30, 0
	  lfs       f31, -0x75CC(r2)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x134

	.loc_0x5C:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x84
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0xA0

	.loc_0x84:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0xA0:
	  lwz       r5, 0x6C(r29)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  cmpwi     r5, 0x16
	  addi      r0, r3, 0
	  beq-      .loc_0xC4
	  cmpwi     r5, 0x17
	  beq-      .loc_0xC4
	  li        r0, 0

	.loc_0xC4:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0xD8
	  cmpwi     r5, 0x18
	  beq-      .loc_0xD8
	  li        r4, 0

	.loc_0xD8:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0xEC
	  cmpwi     r5, 0x19
	  beq-      .loc_0xEC
	  li        r3, 0

	.loc_0xEC:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x118
	  lfs       f1, 0x6F0(r31)
	  lfs       f2, 0x6F8(r31)
	  lfs       f3, 0x94(r29)
	  lfs       f4, 0x9C(r29)
	  bl        -0x4DBB4
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x118
	  fmr       f31, f1
	  mr        r30, r29

	.loc_0x118:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x134:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x15C
	  li        r0, 0x1
	  b         .loc_0x188

	.loc_0x15C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x184
	  li        r0, 0x1
	  b         .loc_0x188

	.loc_0x184:
	  li        r0, 0

	.loc_0x188:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x5C
	  lwz       r27, 0x3020(r13)
	  li        r26, 0
	  lfs       f30, -0x75CC(r2)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x250

	.loc_0x1B8:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x1DC
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1F4

	.loc_0x1DC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1F4:
	  mr        r29, r3
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x234
	  lfs       f1, 0x6F0(r31)
	  lfs       f2, 0x6F8(r31)
	  lfs       f3, 0x94(r29)
	  lfs       f4, 0x9C(r29)
	  bl        -0x4DCD0
	  fcmpo     cr0, f1, f30
	  bge-      .loc_0x234
	  fmr       f30, f1
	  mr        r26, r29

	.loc_0x234:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x250:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x278
	  li        r0, 0x1
	  b         .loc_0x2A4

	.loc_0x278:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2A0
	  li        r0, 0x1
	  b         .loc_0x2A4

	.loc_0x2A0:
	  li        r0, 0

	.loc_0x2A4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1B8
	  cmplwi    r30, 0
	  beq-      .loc_0x2D0
	  cmplwi    r26, 0
	  beq-      .loc_0x2D0
	  fcmpo     cr0, f31, f30
	  bge-      .loc_0x2CC
	  li        r26, 0
	  b         .loc_0x2D0

	.loc_0x2CC:
	  li        r30, 0

	.loc_0x2D0:
	  cmplwi    r30, 0
	  beq-      .loc_0x320
	  lis       r3, 0x802B
	  lfs       f0, -0x75C8(r2)
	  subi      r0, r3, 0x3064
	  stw       r0, 0x34(r1)
	  lis       r3, 0x802D
	  subi      r4, r3, 0x2614
	  stw       r31, 0x38(r1)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r4, 0x34(r1)
	  addi      r4, r1, 0x34
	  stfs      f0, 0x3C(r1)
	  stw       r0, 0x40(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x37C

	.loc_0x320:
	  cmplwi    r26, 0
	  beq-      .loc_0x37C
	  lwz       r29, 0x404(r26)
	  li        r28, 0
	  lfs       f31, -0x75CC(r2)
	  li        r27, 0
	  b         .loc_0x35C

	.loc_0x33C:
	  addi      r3, r26, 0
	  addi      r4, r28, 0
	  li        r5, 0x1
	  bl        0x18194
	  lwz       r3, 0x3D0(r26)
	  addi      r28, r28, 0x1
	  stfsx     f31, r3, r27
	  addi      r27, r27, 0x4

	.loc_0x35C:
	  cmpw      r28, r29
	  blt+      .loc_0x33C
	  lwz       r3, 0x3F8(r26)
	  li        r4, 0x1
	  bl        0x1B32C
	  lwz       r3, 0x3FC(r26)
	  li        r4, 0x1
	  bl        0x1B320

	.loc_0x37C:
	  lmw       r26, 0x60(r1)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80086470
 * Size:	000008
 */
u32 WorkObject::isBridge() { return 0x0; }

/*
 * --INFO--
 * Address:	80086478
 * Size:	000030
 */
void Delegate1<AIPerf, Menu&>::invoke(Menu&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  addi      r12, r5, 0x8
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x18E8A0
	  nop
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
