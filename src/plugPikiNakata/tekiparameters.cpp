#include "TekiParameters.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014BD48
 * Size:	000954
 */
TekiParameters::TekiParameters(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x738C
	  lis       r6, 0x802D
	  stwu      r1, -0xA8(r1)
	  stmw      r14, 0x60(r1)
	  addi      r28, r3, 0
	  lis       r3, 0x8022
	  stw       r4, 0x38(r1)
	  subi      r31, r6, 0x1FF8
	  subi      r4, r13, 0x628
	  stw       r5, 0x3C(r1)
	  stw       r0, 0x0(r28)
	  addi      r0, r3, 0x737C
	  addi      r3, r28, 0
	  stw       r0, 0x0(r28)
	  li        r0, 0
	  stw       r0, 0x10(r28)
	  stw       r0, 0xC(r28)
	  stw       r0, 0x8(r28)
	  bl        -0x126EC8
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r28)
	  addi      r3, r28, 0
	  subi      r4, r13, 0x628
	  bl        -0x10B678
	  lis       r3, 0x802D
	  subi      r0, r3, 0x1A94
	  lis       r3, 0x8004
	  stw       r0, 0x0(r28)
	  addi      r4, r3, 0x3E5C
	  addi      r3, r28, 0x24
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x8
	  bl        0xC8C94
	  li        r30, 0
	  mulli     r0, r30, 0xC
	  add       r29, r28, r0
	  lis       r27, 0x6E6F

	.loc_0xA8:
	  addi      r3, r29, 0x24
	  addi      r4, r27, 0x6E65
	  bl        -0x107F34
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x8
	  addi      r29, r29, 0xC
	  blt+      .loc_0xA8
	  lwz       r27, 0x38(r1)
	  mulli     r3, r27, 0xC
	  addi      r3, r3, 0x8
	  bl        -0x104E14
	  lis       r4, 0x8012
	  addi      r4, r4, 0x5454
	  addi      r7, r27, 0
	  li        r5, 0
	  li        r6, 0xC
	  bl        0xC8DF8
	  li        r0, 0
	  stw       r3, 0x40(r1)
	  mulli     r0, r0, 0xC
	  stw       r0, 0x44(r1)
	  li        r0, 0x1
	  mulli     r29, r0, 0xC
	  lwz       r0, 0x44(r1)
	  add       r4, r3, r0
	  addi      r0, r31, 0x24
	  stw       r0, 0x0(r4)
	  li        r0, 0
	  li        r5, 0x2
	  stw       r0, 0x4(r4)
	  li        r9, 0x1
	  mulli     r25, r5, 0xC
	  stw       r9, 0x8(r4)
	  li        r5, 0x3
	  mulli     r26, r5, 0xC
	  add       r4, r3, r29
	  addi      r5, r31, 0x30
	  stw       r5, 0x0(r4)
	  li        r5, 0x4
	  mulli     r14, r5, 0xC
	  stw       r0, 0x4(r4)
	  stw       r9, 0x8(r4)
	  add       r4, r3, r25
	  addi      r5, r31, 0x3C
	  stw       r5, 0x0(r4)
	  addi      r6, r31, 0x4C
	  li        r5, 0x5
	  stw       r0, 0x4(r4)
	  mulli     r15, r5, 0xC
	  stw       r9, 0x8(r4)
	  add       r4, r3, r26
	  stw       r6, 0x0(r4)
	  li        r6, -0x1
	  li        r5, 0x6
	  stw       r6, 0x4(r4)
	  li        r6, 0x22
	  mulli     r16, r5, 0xC
	  stw       r6, 0x8(r4)
	  li        r5, 0x7
	  mulli     r30, r5, 0xC
	  add       r4, r3, r14
	  addi      r5, r31, 0x58
	  stw       r5, 0x0(r4)
	  li        r5, 0x8
	  mulli     r17, r5, 0xC
	  stw       r0, 0x4(r4)
	  li        r8, 0x64
	  stw       r8, 0x8(r4)
	  add       r4, r3, r15
	  addi      r5, r31, 0x64
	  stw       r5, 0x0(r4)
	  add       r6, r3, r16
	  li        r7, 0x2
	  stw       r0, 0x4(r4)
	  li        r5, 0x9
	  mulli     r18, r5, 0xC
	  stw       r9, 0x8(r4)
	  addi      r4, r31, 0x74
	  stw       r4, 0x0(r6)
	  add       r4, r3, r30
	  addi      r10, r31, 0x88
	  stw       r0, 0x4(r6)
	  add       r5, r3, r17
	  stw       r7, 0x8(r6)
	  addi      r7, r31, 0x94
	  add       r6, r3, r18
	  stw       r10, 0x0(r4)
	  addi      r10, r31, 0xA0
	  stw       r0, 0x4(r4)
	  stw       r9, 0x8(r4)
	  stw       r7, 0x0(r5)
	  stw       r0, 0x4(r5)
	  stw       r9, 0x8(r5)
	  stw       r10, 0x0(r6)
	  stw       r0, 0x4(r6)
	  li        r4, 0xA
	  lwz       r27, 0x3C(r1)
	  mulli     r19, r4, 0xC
	  li        r4, 0xC8
	  stw       r4, 0x8(r6)
	  add       r5, r3, r19
	  addi      r6, r31, 0xB0
	  stw       r6, 0x0(r5)
	  li        r6, 0xB
	  mulli     r20, r6, 0xC
	  stw       r0, 0x4(r5)
	  stw       r4, 0x8(r5)
	  add       r5, r3, r20
	  addi      r6, r31, 0xC4
	  stw       r6, 0x0(r5)
	  li        r6, 0xC
	  mulli     r21, r6, 0xC
	  stw       r0, 0x4(r5)
	  stw       r4, 0x8(r5)
	  add       r5, r3, r21
	  addi      r6, r31, 0xD8
	  stw       r6, 0x0(r5)
	  li        r6, 0xD
	  mulli     r22, r6, 0xC
	  stw       r0, 0x4(r5)
	  stw       r4, 0x8(r5)
	  add       r4, r3, r22
	  addi      r5, r31, 0xEC
	  stw       r5, 0x0(r4)
	  li        r5, 0xE
	  mulli     r23, r5, 0xC
	  stw       r0, 0x4(r4)
	  stw       r8, 0x8(r4)
	  add       r4, r3, r23
	  addi      r5, r31, 0x104
	  stw       r5, 0x0(r4)
	  li        r5, 0xF
	  mulli     r24, r5, 0xC
	  stw       r0, 0x4(r4)
	  stw       r8, 0x8(r4)
	  add       r4, r3, r24
	  addi      r5, r31, 0x11C
	  stw       r5, 0x0(r4)
	  li        r5, 0x10
	  mulli     r5, r5, 0xC
	  stw       r0, 0x4(r4)
	  stw       r5, 0x48(r1)
	  addi      r5, r31, 0x134
	  stw       r8, 0x8(r4)
	  lwz       r4, 0x48(r1)
	  add       r4, r3, r4
	  stw       r5, 0x0(r4)
	  li        r5, 0x11
	  mulli     r5, r5, 0xC
	  stw       r0, 0x4(r4)
	  stw       r5, 0x4C(r1)
	  addi      r5, r31, 0x14C
	  stw       r8, 0x8(r4)
	  lwz       r4, 0x4C(r1)
	  add       r4, r3, r4
	  stw       r5, 0x0(r4)
	  li        r5, 0x12
	  mulli     r5, r5, 0xC
	  stw       r0, 0x4(r4)
	  stw       r5, 0x50(r1)
	  addi      r5, r31, 0x164
	  stw       r9, 0x8(r4)
	  lwz       r4, 0x50(r1)
	  add       r4, r3, r4
	  stw       r5, 0x0(r4)
	  li        r5, 0x13
	  mulli     r5, r5, 0xC
	  stw       r0, 0x4(r4)
	  stw       r5, 0x54(r1)
	  stw       r9, 0x8(r4)
	  lwz       r4, 0x54(r1)
	  add       r4, r3, r4
	  addi      r3, r31, 0x17C
	  stw       r3, 0x0(r4)
	  mulli     r3, r27, 0xC
	  stw       r0, 0x4(r4)
	  addi      r3, r3, 0x8
	  stw       r8, 0x8(r4)
	  bl        -0x1050B4
	  lis       r4, 0x8012
	  addi      r4, r4, 0x543C
	  addi      r7, r27, 0
	  li        r5, 0
	  li        r6, 0xC
	  bl        0xC8B58
	  lwz       r0, 0x44(r1)
	  add       r10, r3, r29
	  subi      r4, r13, 0x610
	  add       r5, r3, r0
	  stw       r4, 0x58(r1)
	  subi      r0, r13, 0x620
	  stw       r0, 0x0(r5)
	  add       r11, r3, r25
	  addi      r4, r31, 0x190
	  lfs       f5, -0x5858(r2)
	  add       r12, r3, r26
	  stw       r4, 0x5C(r1)
	  add       r7, r3, r30
	  add       r8, r3, r17
	  stfs      f5, 0x4(r5)
	  subi      r0, r13, 0x618
	  add       r4, r3, r14
	  lfs       f0, -0x5854(r2)
	  addi      r25, r31, 0x1A0
	  addi      r26, r31, 0x1B0
	  stfs      f0, 0x8(r5)
	  add       r5, r3, r15
	  add       r6, r3, r16
	  stw       r0, 0x0(r10)
	  addi      r27, r31, 0x1C0
	  lwz       r0, 0x58(r1)
	  addi      r29, r31, 0x1D0
	  lfs       f4, -0x5850(r2)
	  addi      r30, r31, 0x1E0
	  stfs      f4, 0x4(r10)
	  add       r9, r3, r18
	  addi      r17, r3, 0
	  lfs       f3, -0x584C(r2)
	  stfs      f3, 0x8(r10)
	  addi      r10, r31, 0x1F4
	  stw       r0, 0x0(r11)
	  lwz       r0, 0x5C(r1)
	  stfs      f4, 0x4(r11)
	  lfs       f2, -0x5848(r2)
	  stfs      f2, 0x8(r11)
	  stw       r0, 0x0(r12)
	  stfs      f4, 0x4(r12)
	  lfs       f1, -0x5844(r2)
	  stfs      f1, 0x8(r12)
	  stw       r25, 0x0(r4)
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  stw       r26, 0x0(r5)
	  stfs      f4, 0x4(r5)
	  lfs       f0, -0x5840(r2)
	  stfs      f0, 0x8(r5)
	  stw       r27, 0x0(r6)
	  stfs      f4, 0x4(r6)
	  stfs      f2, 0x8(r6)
	  stw       r29, 0x0(r7)
	  stfs      f4, 0x4(r7)
	  stfs      f2, 0x8(r7)
	  stw       r30, 0x0(r8)
	  stfs      f4, 0x4(r8)
	  stfs      f2, 0x8(r8)
	  stw       r10, 0x0(r9)
	  stfs      f4, 0x4(r9)
	  stfs      f2, 0x8(r9)
	  add       r6, r3, r19
	  addi      r0, r31, 0x208
	  stw       r0, 0x0(r6)
	  add       r7, r3, r20
	  addi      r5, r31, 0x218
	  stfs      f5, 0x4(r6)
	  add       r4, r3, r21
	  addi      r0, r31, 0x22C
	  stfs      f1, 0x8(r6)
	  add       r10, r3, r22
	  addi      r26, r31, 0x23C
	  stw       r5, 0x0(r7)
	  add       r5, r3, r23
	  addi      r25, r31, 0x250
	  stfs      f4, 0x4(r7)
	  add       r6, r3, r24
	  addi      r29, r31, 0x264
	  stfs      f1, 0x8(r7)
	  addi      r12, r31, 0x27C
	  lwz       r7, 0x48(r1)
	  addi      r27, r31, 0x294
	  stw       r0, 0x0(r4)
	  lwz       r0, 0x4C(r1)
	  add       r7, r3, r7
	  stfs      f4, 0x4(r4)
	  addi      r11, r31, 0x2A8
	  add       r8, r3, r0
	  stfs      f1, 0x8(r4)
	  lwz       r0, 0x50(r1)
	  stw       r26, 0x0(r10)
	  add       r9, r3, r0
	  lwz       r0, 0x54(r1)
	  stfs      f4, 0x4(r10)
	  add       r4, r3, r0
	  stfs      f3, 0x8(r10)
	  addi      r0, r31, 0x2B4
	  stw       r25, 0x0(r5)
	  stfs      f4, 0x4(r5)
	  stfs      f3, 0x8(r5)
	  stw       r29, 0x0(r6)
	  stfs      f5, 0x4(r6)
	  stfs      f2, 0x8(r6)
	  stw       r12, 0x0(r7)
	  stfs      f5, 0x4(r7)
	  stfs      f2, 0x8(r7)
	  stw       r27, 0x0(r8)
	  lfs       f0, -0x583C(r2)
	  stfs      f0, 0x4(r8)
	  lfs       f0, -0x5838(r2)
	  stfs      f0, 0x8(r8)
	  stw       r11, 0x0(r9)
	  stfs      f5, 0x4(r9)
	  stfs      f1, 0x8(r9)
	  stw       r0, 0x0(r4)
	  stfs      f4, 0x4(r4)
	  lfs       f0, -0x5834(r2)
	  stfs      f0, 0x8(r4)
	  li        r0, 0x14
	  mulli     r0, r0, 0xC
	  add       r4, r3, r0
	  addi      r0, r31, 0x2C4
	  stw       r0, 0x0(r4)
	  li        r0, 0x15
	  mulli     r0, r0, 0xC
	  stfs      f5, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x2D0
	  stw       r0, 0x0(r4)
	  li        r0, 0x16
	  mulli     r0, r0, 0xC
	  stfs      f5, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x2E0
	  stw       r0, 0x0(r4)
	  li        r0, 0x17
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x2F0
	  stw       r0, 0x0(r4)
	  li        r0, 0x18
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x300
	  stw       r0, 0x0(r4)
	  li        r0, 0x19
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x310
	  stw       r0, 0x0(r4)
	  li        r0, 0x1A
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f3, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x31C
	  stw       r0, 0x0(r4)
	  li        r0, 0x1B
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x32C
	  stw       r0, 0x0(r4)
	  li        r0, 0x1C
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f3, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x338
	  stw       r0, 0x0(r4)
	  li        r0, 0x1D
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x348
	  stw       r0, 0x0(r4)
	  li        r0, 0x1E
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r5, r3, r0
	  addi      r0, r31, 0x358
	  stw       r0, 0x0(r5)
	  li        r0, 0x1F
	  mulli     r4, r0, 0xC
	  stfs      f4, 0x4(r5)
	  stfs      f5, 0x8(r5)
	  li        r0, 0x20
	  add       r4, r3, r4
	  addi      r5, r31, 0x370
	  stw       r5, 0x0(r4)
	  mulli     r6, r0, 0xC
	  stfs      f4, 0x4(r4)
	  li        r0, 0x21
	  lfs       f0, -0x5830(r2)
	  mulli     r5, r0, 0xC
	  stfs      f0, 0x8(r4)
	  add       r6, r3, r6
	  addi      r0, r31, 0x388
	  stw       r0, 0x0(r6)
	  li        r0, 0x22
	  mulli     r4, r0, 0xC
	  stfs      f4, 0x4(r6)
	  stfs      f5, 0x8(r6)
	  add       r6, r3, r5
	  addi      r0, r31, 0x39C
	  stw       r0, 0x0(r6)
	  li        r0, 0x23
	  mulli     r5, r0, 0xC
	  stfs      f4, 0x4(r6)
	  stfs      f1, 0x8(r6)
	  add       r6, r3, r4
	  addi      r0, r31, 0x3B0
	  stw       r0, 0x0(r6)
	  li        r0, 0x24
	  mulli     r4, r0, 0xC
	  stfs      f4, 0x4(r6)
	  stfs      f1, 0x8(r6)
	  add       r6, r3, r5
	  addi      r0, r31, 0x3C4
	  stw       r0, 0x0(r6)
	  li        r0, 0x25
	  mulli     r5, r0, 0xC
	  stfs      f4, 0x4(r6)
	  stfs      f1, 0x8(r6)
	  add       r6, r3, r4
	  addi      r0, r31, 0x3D8
	  stw       r0, 0x0(r6)
	  li        r0, 0x26
	  mulli     r4, r0, 0xC
	  stfs      f4, 0x4(r6)
	  stfs      f1, 0x8(r6)
	  add       r6, r3, r5
	  addi      r0, r31, 0x3EC
	  stw       r0, 0x0(r6)
	  li        r0, 0x27
	  mulli     r5, r0, 0xC
	  stfs      f4, 0x4(r6)
	  stfs      f5, 0x8(r6)
	  add       r4, r3, r4
	  addi      r0, r31, 0x400
	  stw       r0, 0x0(r4)
	  li        r0, 0x28
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  lfs       f0, -0x582C(r2)
	  add       r5, r3, r5
	  addi      r6, r31, 0x40C
	  stfs      f0, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x430
	  stw       r6, 0x0(r5)
	  stfs      f4, 0x4(r5)
	  stfs      f1, 0x8(r5)
	  stw       r0, 0x0(r4)
	  li        r0, 0x29
	  stfs      f4, 0x4(r4)
	  mulli     r0, r0, 0xC
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x450
	  stw       r0, 0x0(r4)
	  li        r0, 0x2A
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x46C
	  stw       r0, 0x0(r4)
	  li        r0, 0x2B
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x488
	  stw       r0, 0x0(r4)
	  li        r0, 0x2C
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f3, 0x8(r4)
	  add       r4, r3, r0
	  addi      r0, r31, 0x49C
	  stw       r0, 0x0(r4)
	  li        r0, 0x2D
	  mulli     r5, r0, 0xC
	  stfs      f4, 0x4(r4)
	  lfs       f0, -0x5828(r2)
	  li        r0, 0x2E
	  mulli     r6, r0, 0xC
	  stfs      f0, 0x8(r4)
	  add       r4, r3, r5
	  addi      r0, r31, 0x4B0
	  stw       r0, 0x0(r4)
	  li        r0, 0x2F
	  mulli     r5, r0, 0xC
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  add       r6, r3, r6
	  addi      r0, r31, 0x4BC
	  stw       r0, 0x0(r6)
	  li        r0, 0x30
	  mulli     r4, r0, 0xC
	  stfs      f4, 0x4(r6)
	  stfs      f1, 0x8(r6)
	  add       r5, r3, r5
	  addi      r0, r31, 0x4D0
	  stw       r0, 0x0(r5)
	  li        r0, 0x31
	  mulli     r0, r0, 0xC
	  stfs      f4, 0x4(r5)
	  stfs      f1, 0x8(r5)
	  add       r5, r3, r4
	  addi      r4, r31, 0x4E4
	  stw       r4, 0x0(r5)
	  add       r4, r3, r0
	  addi      r0, r31, 0x4F8
	  stfs      f4, 0x4(r5)
	  li        r3, 0xC
	  stfs      f1, 0x8(r5)
	  stw       r0, 0x0(r4)
	  stfs      f4, 0x4(r4)
	  stfs      f1, 0x8(r4)
	  bl        -0x105608
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0x8E8
	  lwz       r4, 0x38(r1)
	  mr        r7, r17
	  lwz       r5, 0x40(r1)
	  lwz       r6, 0x3C(r1)
	  bl        -0x2ADD8

	.loc_0x8E8:
	  stw       r27, 0x84(r28)
	  li        r0, -0x1
	  addi      r3, r28, 0
	  lwz       r4, 0x84(r28)
	  lwz       r5, 0x0(r4)
	  lwz       r5, 0x0(r5)
	  stw       r0, 0xC(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5834(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x50(r5)
	  lwz       r5, 0x4(r4)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x54(r5)
	  lwz       r5, 0x4(r4)
	  lfs       f0, -0x5844(r2)
	  lwz       r5, 0x0(r5)
	  stfs      f0, 0x70(r5)
	  lwz       r4, 0x4(r4)
	  lfs       f0, -0x5824(r2)
	  lwz       r4, 0x0(r4)
	  stfs      f0, 0xB0(r4)
	  lwz       r0, 0xAC(r1)
	  lmw       r14, 0x60(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014C69C
 * Size:	0003C4
 */
void TekiParameters::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r27, 0x4C(r1)
	  addi      r30, r4, 0
	  addi      r27, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r27)
	  lwz       r0, 0x20(r27)
	  lwz       r31, 0x84(r27)
	  cmpwi     r0, 0x7
	  bgt-      .loc_0x1D4
	  li        r28, 0
	  mulli     r0, r28, 0xC
	  add       r29, r27, r0

	.loc_0x4C:
	  addi      r3, r29, 0x24
	  addi      r4, r30, 0
	  bl        -0x108654
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x8
	  addi      r29, r29, 0xC
	  blt+      .loc_0x4C
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r28, 0
	  addi      r29, r28, 0

	.loc_0x98:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x0(r31)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x10
	  lwz       r4, 0x0(r4)
	  stwx      r3, r4, r29
	  addi      r29, r29, 0x4
	  ble+      .loc_0x98
	  li        r28, 0x14
	  li        r29, 0x50
	  b         .loc_0xFC

	.loc_0xD4:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x0(r31)
	  addi      r28, r28, 0x1
	  lwz       r4, 0x0(r4)
	  stwx      r3, r4, r29
	  addi      r29, r29, 0x4

	.loc_0xFC:
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x4(r3)
	  cmpw      r28, r0
	  blt+      .loc_0xD4
	  li        r28, 0
	  addi      r29, r28, 0

	.loc_0x114:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x26
	  lwz       r3, 0x0(r3)
	  stfsx     f1, r3, r29
	  addi      r29, r29, 0x4
	  ble+      .loc_0x114
	  li        r28, 0x32
	  li        r29, 0xC8
	  b         .loc_0x178

	.loc_0x150:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  addi      r28, r28, 0x1
	  lwz       r3, 0x0(r3)
	  stfsx     f1, r3, r29
	  addi      r29, r29, 0x4

	.loc_0x178:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x4(r3)
	  cmpw      r28, r0
	  blt+      .loc_0x150
	  lfs       f0, -0x5844(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x70(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5820(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x9C(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x581C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xA0(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5850(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xA4(r3)
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xA8(r3)
	  b         .loc_0x3B0

	.loc_0x1D4:
	  cmpwi     r0, 0x8
	  bgt-      .loc_0x2B8
	  li        r28, 0
	  mulli     r0, r28, 0xC
	  add       r29, r27, r0

	.loc_0x1E8:
	  addi      r3, r29, 0x24
	  addi      r4, r30, 0
	  bl        -0x1087F0
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x8
	  addi      r29, r29, 0xC
	  blt+      .loc_0x1E8
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0xC(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  li        r28, 0
	  addi      r29, r28, 0

	.loc_0x224:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x27
	  lwz       r3, 0x0(r3)
	  stfsx     f1, r3, r29
	  addi      r29, r29, 0x4
	  ble+      .loc_0x224
	  li        r28, 0x32
	  li        r29, 0xC8
	  b         .loc_0x288

	.loc_0x260:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  addi      r28, r28, 0x1
	  lwz       r3, 0x0(r3)
	  stfsx     f1, r3, r29
	  addi      r29, r29, 0x4

	.loc_0x288:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x4(r3)
	  cmpw      r28, r0
	  blt+      .loc_0x260
	  lfs       f0, -0x5820(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0x9C(r3)
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x581C(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xA0(r3)
	  b         .loc_0x3B0

	.loc_0x2B8:
	  cmpwi     r0, 0x9
	  bgt-      .loc_0x314
	  li        r28, 0
	  mulli     r0, r28, 0xC
	  add       r29, r27, r0

	.loc_0x2CC:
	  addi      r3, r29, 0x24
	  addi      r4, r30, 0
	  bl        -0x1088D4
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x8
	  addi      r29, r29, 0xC
	  blt+      .loc_0x2CC
	  lwz       r3, 0x84(r27)
	  mr        r4, r30
	  lwz       r12, 0x8(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  lfs       f0, -0x5824(r2)
	  lwz       r3, 0x0(r3)
	  stfs      f0, 0xB0(r3)
	  b         .loc_0x3B0

	.loc_0x314:
	  cmpwi     r0, 0xA
	  bgt-      .loc_0x370
	  li        r28, 0
	  mulli     r0, r28, 0xC
	  add       r29, r27, r0

	.loc_0x328:
	  addi      r3, r29, 0x24
	  addi      r4, r30, 0
	  bl        -0x108930
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x8
	  addi      r29, r29, 0xC
	  blt+      .loc_0x328
	  lwz       r3, 0x84(r27)
	  mr        r4, r30
	  lwz       r12, 0x8(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x28(r3)
	  stfs      f0, 0xB4(r3)
	  b         .loc_0x3B0

	.loc_0x370:
	  li        r28, 0
	  mulli     r0, r28, 0xC
	  add       r29, r27, r0

	.loc_0x37C:
	  addi      r3, r29, 0x24
	  addi      r4, r30, 0
	  bl        -0x108984
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x8
	  addi      r29, r29, 0xC
	  blt+      .loc_0x37C
	  lwz       r3, 0x84(r27)
	  mr        r4, r30
	  lwz       r12, 0x8(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x3B0:
	  lmw       r27, 0x4C(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}
