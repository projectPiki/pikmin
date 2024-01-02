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
 * Address:	800E2FB4
 * Size:	000004
 */
SearchSystem::SearchSystem() { }

/*
 * --INFO--
 * Address:	800E2FB8
 * Size:	00046C
 */
void SearchSystem::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x2FAB(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x150
	  bl        .loc_0x46C
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x3160(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x54
	  lwz       r3, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x54:
	  lwz       r3, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x3168(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x8C
	  lwz       r3, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x8C:
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0x3140(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3068(r13)
	  lwz       r4, 0x3140(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xF4
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0xF4:
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x12C:
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x45C
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x45C

	.loc_0x150:
	  lwz       r3, 0x3068(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3068(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x3160(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x1A4
	  lwz       r3, 0x3068(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x1A4:
	  lwz       r4, 0x3168(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x1C4
	  lwz       r3, 0x3068(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x1C4:
	  lwz       r3, 0x3068(r13)
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3068(r13)
	  lwz       r4, 0x301C(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x3160(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x248
	  lwz       r3, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x248:
	  lwz       r4, 0x3168(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x268
	  lwz       r3, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x268:
	  lwz       r3, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0x301C(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3120(r13)
	  lwz       r4, 0x3140(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3068(r13)
	  lwz       r4, 0x3140(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x2E8
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x3140(r13)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x2E8:
	  lwz       r3, 0x3068(r13)
	  lwz       r4, 0x3120(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x68(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x301C(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x301C(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x39C
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3168(r13)
	  lwz       r4, 0x301C(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x39C:
	  lwz       r3, 0x3160(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x408
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x301C(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x408:
	  lwz       r3, 0x301C(r13)
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3168(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x45C
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3168(r13)
	  lwz       r4, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl

	.loc_0x45C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x46C:
	*/
}

/*
 * --INFO--
 * Address:	800E3424
 * Size:	0007EC
 */
void SearchSystem::updateLoopOptimised()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stmw      r26, 0x68(r1)
	  li        r31, 0
	  li        r29, 0
	  lfs       f31, -0x6730(r2)
	  b         .loc_0x7C0

	.loc_0x28:
	  lwz       r3, 0x34(r4)
	  lwzx      r0, r3, r29
	  cmpwi     r0, 0
	  bne-      .loc_0x7B8
	  lwz       r27, 0x3120(r13)
	  lwz       r4, 0x28(r4)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwzx      r30, r4, r29
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x170

	.loc_0x60:
	  cmpwi     r26, -0x1
	  bne-      .loc_0x88
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0xA4

	.loc_0x88:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xA4:
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xF4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F11C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x154

	.loc_0xF4:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x57A00
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x12C
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x12C
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0xB90

	.loc_0x12C:
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x154
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0xB68

	.loc_0x154:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x170:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x198
	  li        r0, 0x1
	  b         .loc_0x1C4

	.loc_0x198:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r26
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1C0
	  li        r0, 0x1
	  b         .loc_0x1C4

	.loc_0x1C0:
	  li        r0, 0

	.loc_0x1C4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x60
	  lwz       r26, 0x3160(r13)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x30C

	.loc_0x1EC:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x214
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x230

	.loc_0x214:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x230:
	  addi      r3, r28, 0x40
	  bl        -0x4F4C8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x290
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F2B8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0

	.loc_0x290:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x57B9C
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x2C8
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x2C8
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0x9F4

	.loc_0x2C8:
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x2F0
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x2F0
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0x9CC

	.loc_0x2F0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x30C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x334
	  li        r0, 0x1
	  b         .loc_0x360

	.loc_0x334:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x35C
	  li        r0, 0x1
	  b         .loc_0x360

	.loc_0x35C:
	  li        r0, 0

	.loc_0x360:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1EC
	  lwz       r26, 0x3168(r13)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x4A8

	.loc_0x388:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x3B0
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x3CC

	.loc_0x3B0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x3CC:
	  addi      r3, r28, 0x40
	  bl        -0x4F664
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48C
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x42C
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F454
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x48C

	.loc_0x42C:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x57D38
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x464
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x464
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0x858

	.loc_0x464:
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x48C
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x48C
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0x830

	.loc_0x48C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x4A8:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x4D0
	  li        r0, 0x1
	  b         .loc_0x4FC

	.loc_0x4D0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x4F8
	  li        r0, 0x1
	  b         .loc_0x4FC

	.loc_0x4F8:
	  li        r0, 0

	.loc_0x4FC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x388
	  lwz       r26, 0x30AC(r13)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x644

	.loc_0x524:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x54C
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x568

	.loc_0x54C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x568:
	  addi      r3, r28, 0x40
	  bl        -0x4F800
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x628
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x5C8
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F5F0
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x628

	.loc_0x5C8:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x57ED4
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x600
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x600
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0x6BC

	.loc_0x600:
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x628
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x628
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0x694

	.loc_0x628:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x644:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x66C
	  li        r0, 0x1
	  b         .loc_0x698

	.loc_0x66C:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x694
	  li        r0, 0x1
	  b         .loc_0x698

	.loc_0x694:
	  li        r0, 0

	.loc_0x698:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x524
	  addi      r27, r31, 0x1
	  rlwinm    r26,r27,2,0,29
	  b         .loc_0x7A8

	.loc_0x6AC:
	  lwz       r3, 0x34(r4)
	  lwzx      r0, r3, r26
	  cmpwi     r0, 0
	  bne-      .loc_0x7A0
	  lbz       r0, -0x5F05(r13)
	  lwz       r3, 0x28(r4)
	  cmplwi    r0, 0
	  lwzx      r28, r3, r26
	  bne-      .loc_0x6DC
	  lbz       r0, 0x2FAC(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x6FC

	.loc_0x6DC:
	  addi      r3, r30, 0x168
	  bl        -0x3E6AC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x6FC
	  addi      r3, r28, 0x168
	  bl        -0x3E6BC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7A0

	.loc_0x6FC:
	  lwz       r0, -0x5F10(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x74C
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0x40
	  addi      r4, r28, 0x40
	  bl        -0x4F774
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x7A0

	.loc_0x74C:
	  addi      r3, r30, 0
	  addi      r4, r28, 0
	  bl        -0x58058
	  fmr       f30, f1
	  fcmpo     cr0, f30, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x7A0
	  lwz       r0, 0x1CC(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x784
	  fmr       f1, f30
	  addi      r4, r28, 0
	  addi      r3, r30, 0x1B8
	  bl        0x538

	.loc_0x784:
	  lwz       r0, 0x1CC(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x7A0
	  fmr       f1, f30
	  addi      r4, r30, 0
	  addi      r3, r28, 0x1B8
	  bl        0x51C

	.loc_0x7A0:
	  addi      r26, r26, 0x4
	  addi      r27, r27, 0x1

	.loc_0x7A8:
	  lwz       r4, 0x3068(r13)
	  lwz       r0, 0x2C(r4)
	  cmpw      r27, r0
	  blt+      .loc_0x6AC

	.loc_0x7B8:
	  addi      r29, r29, 0x4
	  addi      r31, r31, 0x1

	.loc_0x7C0:
	  lwz       r4, 0x3068(r13)
	  lwz       r0, 0x2C(r4)
	  cmpw      r31, r0
	  blt+      .loc_0x28
	  lmw       r26, 0x68(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E3C10
 * Size:	000070
 */
SearchBuffer::SearchBuffer()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r4, 0x2374
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  stw       r0, 0x0(r3)
	  lis       r3, 0x802C
	  subi      r0, r3, 0x4EC0
	  stw       r31, 0x4(r30)
	  addi      r3, r30, 0
	  stw       r0, 0x0(r30)
	  sth       r31, 0x1A(r30)
	  stw       r31, 0x20(r30)
	  sth       r31, 0x18(r30)
	  stw       r31, 0x14(r30)
	  bl        0x238
	  stb       r31, 0x24(r30)
	  mr        r3, r30
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
 * Address:	800E3C80
 * Size:	0001D8
 */
void SearchBuffer::init(SearchData*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r9, 0
	  stw       r0, 0x4(r1)
	  extsh     r0, r5
	  cmpwi     r5, 0
	  stwu      r1, -0x8(r1)
	  addi      r8, r9, 0
	  addi      r6, r9, 0
	  sth       r0, 0x1A(r3)
	  stw       r4, 0x14(r3)
	  lfs       f0, -0x672C(r2)
	  ble-      .loc_0x1B8
	  rlwinm.   r0,r5,29,3,31
	  mtctr     r0
	  beq-      .loc_0x188

	.loc_0x3C:
	  lwz       r4, 0x14(r3)
	  addi      r7, r9, 0x8
	  addi      r0, r9, 0x4
	  stwx      r8, r4, r7
	  addi      r7, r9, 0x14
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  addi      r0, r9, 0x10
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stwx      r8, r4, r7
	  addi      r7, r9, 0x14
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  addi      r0, r9, 0x10
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stwx      r8, r4, r7
	  addi      r7, r9, 0x14
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  addi      r0, r9, 0x10
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stwx      r8, r4, r7
	  addi      r7, r9, 0x14
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  addi      r0, r9, 0x10
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stwx      r8, r4, r7
	  addi      r7, r9, 0x14
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  addi      r0, r9, 0x10
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stwx      r8, r4, r7
	  addi      r7, r9, 0x14
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  addi      r0, r9, 0x10
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stwx      r8, r4, r7
	  addi      r7, r9, 0x14
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  addi      r0, r9, 0x10
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stwx      r8, r4, r7
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  bdnz+     .loc_0x3C
	  andi.     r5, r5, 0x7
	  beq-      .loc_0x1B8

	.loc_0x188:
	  mtctr     r5

	.loc_0x18C:
	  lwz       r4, 0x14(r3)
	  addi      r7, r9, 0x8
	  addi      r0, r9, 0x4
	  stwx      r8, r4, r7
	  lwz       r4, 0x14(r3)
	  add       r4, r4, r9
	  stw       r6, 0x0(r4)
	  addi      r9, r9, 0xC
	  lwz       r4, 0x14(r3)
	  stfsx     f0, r4, r0
	  bdnz+     .loc_0x18C

	.loc_0x1B8:
	  li        r0, 0
	  sth       r0, 0x18(r3)
	  stw       r0, 0x10(r3)
	  bl        0x50
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void SearchBuffer::operator=(SearchBuffer&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void SearchBuffer::getIndex(Creature*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E3E58
 * Size:	00003C
 */
void SearchBuffer::clear()
{
	/*
	.loc_0x0:
	  li        r6, 0
	  addi      r5, r6, 0
	  li        r7, 0
	  b         .loc_0x20

	.loc_0x10:
	  lwz       r4, 0x14(r3)
	  addi      r7, r7, 0x1
	  stwx      r5, r4, r6
	  addi      r6, r6, 0xC

	.loc_0x20:
	  lha       r0, 0x18(r3)
	  cmpw      r7, r0
	  blt+      .loc_0x10
	  li        r0, 0
	  sth       r0, 0x18(r3)
	  sth       r0, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SearchBuffer::reset()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E3E94
 * Size:	000060
 */
void SearchBuffer::invalidate()
{
	/*
	.loc_0x0:
	  lbz       r0, -0x5F07(r13)
	  cmplwi    r0, 0
	  beqlr-
	  li        r6, 0
	  addi      r7, r6, 0
	  addi      r5, r6, 0
	  b         .loc_0x2C

	.loc_0x1C:
	  lwz       r4, 0x14(r3)
	  addi      r6, r6, 0x1
	  stwx      r5, r4, r7
	  addi      r7, r7, 0xC

	.loc_0x2C:
	  lha       r0, 0x18(r3)
	  cmpw      r6, r0
	  blt+      .loc_0x1C
	  li        r4, 0
	  sth       r4, 0x18(r3)
	  li        r0, -0x1
	  sth       r4, 0x1C(r3)
	  lfs       f0, -0x6728(r2)
	  stfs      f0, 0x8(r3)
	  stw       r0, 0xC(r3)
	  sth       r4, 0x18(r3)
	  sth       r4, 0x1C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E3EF4
 * Size:	0001E8
 */
void SearchBuffer::insertQuick(Creature*, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  fmr       f31, f1
	  stw       r31, 0x54(r1)
	  mr        r31, r4
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  stw       r29, 0x4C(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x64
	  b         .loc_0x1C8

	.loc_0x64:
	  lha       r6, 0x18(r30)
	  lha       r7, 0x1A(r30)
	  cmpw      r6, r7
	  blt-      .loc_0x80
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f0, f31
	  blt-      .loc_0x1C8

	.loc_0x80:
	  cmpwi     r6, 0
	  mtctr     r6
	  li        r4, 0
	  addi      r5, r4, 0
	  ble-      .loc_0xB4

	.loc_0x94:
	  lwz       r3, 0x14(r30)
	  lwzx      r0, r3, r5
	  cmplw     r0, r31
	  bne-      .loc_0xA8
	  b         .loc_0xB8

	.loc_0xA8:
	  addi      r5, r5, 0xC
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x94

	.loc_0xB4:
	  li        r4, -0x1

	.loc_0xB8:
	  cmpwi     r4, -0x1
	  bne-      .loc_0x1C8
	  cmpw      r6, r7
	  blt-      .loc_0x140
	  lwz       r0, 0xC(r30)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x1C8
	  mulli     r0, r0, 0xC
	  lwz       r3, 0x14(r30)
	  add       r29, r3, r0
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0xF8
	  bl        0x38C
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0xF8:
	  lwz       r0, 0xC(r30)
	  lwz       r3, 0x14(r30)
	  mulli     r0, r0, 0xC
	  add       r29, r3, r0
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x124
	  beq-      .loc_0x124
	  bl        0x360
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x124:
	  stw       r31, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x138
	  bl        0x334

	.loc_0x138:
	  stfs      f31, 0x8(r30)
	  b         .loc_0x1C8

	.loc_0x140:
	  mulli     r0, r6, 0xC
	  lwz       r3, 0x14(r30)
	  add       r29, r3, r0
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x164
	  bl        0x320
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x164:
	  lha       r0, 0x18(r30)
	  lwz       r3, 0x14(r30)
	  mulli     r0, r0, 0xC
	  add       r29, r3, r0
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  beq-      .loc_0x190
	  bl        0x2F4
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x190:
	  stw       r31, 0x0(r29)
	  lwz       r3, 0x0(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x1A4
	  bl        0x2C8

	.loc_0x1A4:
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x1BC
	  stfs      f31, 0x8(r30)
	  lha       r0, 0x18(r30)
	  stw       r0, 0xC(r30)

	.loc_0x1BC:
	  lha       r3, 0x18(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x18(r30)

	.loc_0x1C8:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E40DC
 * Size:	000204
 */
void SearchBuffer::insert(Creature*, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  fmr       f31, f1
	  stmw      r27, 0x2C(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0
	  lbz       r0, -0x5F07(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x40
	  fmr       f1, f31
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x220
	  b         .loc_0x1EC

	.loc_0x40:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1EC
	  lha       r6, 0x18(r29)
	  li        r4, 0
	  addi      r5, r4, 0
	  cmpwi     r6, 0
	  mtctr     r6
	  ble-      .loc_0x94

	.loc_0x74:
	  lwz       r3, 0x14(r29)
	  lwzx      r0, r3, r5
	  cmplw     r0, r30
	  bne-      .loc_0x88
	  b         .loc_0x98

	.loc_0x88:
	  addi      r5, r5, 0xC
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x74

	.loc_0x94:
	  li        r4, -0x1

	.loc_0x98:
	  cmpwi     r4, -0x1
	  bne-      .loc_0x1C0
	  subi      r31, r6, 0x1
	  mulli     r28, r31, 0xC
	  b         .loc_0x128

	.loc_0xAC:
	  lwz       r5, 0x14(r29)
	  add       r3, r5, r28
	  lfs       f0, 0x4(r3)
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x130
	  lha       r4, 0x1A(r29)
	  addi      r0, r31, 0x1
	  cmpw      r0, r4
	  bge-      .loc_0xFC
	  lwz       r0, 0x0(r3)
	  stw       r0, 0xC(r3)
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r28
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x10(r3)
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r28
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x14(r3)
	  b         .loc_0x120

	.loc_0xFC:
	  subi      r0, r4, 0x1
	  mulli     r0, r0, 0xC
	  add       r27, r5, r0
	  lwz       r3, 0x0(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x120
	  bl        0x17C
	  li        r0, 0
	  stw       r0, 0x0(r27)

	.loc_0x120:
	  subi      r28, r28, 0xC
	  subi      r31, r31, 0x1

	.loc_0x128:
	  cmpwi     r31, 0
	  bge+      .loc_0xAC

	.loc_0x130:
	  lha       r0, 0x1A(r29)
	  addi      r3, r31, 0x1
	  cmpw      r3, r0
	  bge-      .loc_0x1EC
	  mulli     r0, r3, 0xC
	  lwz       r3, 0x14(r29)
	  add       r27, r3, r0
	  lwz       r3, 0x0(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x168
	  beq-      .loc_0x168
	  bl        0x134
	  li        r0, 0
	  stw       r0, 0x0(r27)

	.loc_0x168:
	  stw       r30, 0x0(r27)
	  lwz       r3, 0x0(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  bl        0x108

	.loc_0x17C:
	  mulli     r4, r31, 0xC
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r4
	  li        r0, -0x1
	  stw       r0, 0x14(r3)
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r4
	  stfs      f31, 0x10(r3)
	  lha       r3, 0x18(r29)
	  addi      r0, r3, 0x1
	  sth       r0, 0x18(r29)
	  lha       r0, 0x18(r29)
	  lha       r3, 0x1A(r29)
	  cmpw      r0, r3
	  blt-      .loc_0x1EC
	  sth       r3, 0x18(r29)
	  b         .loc_0x1EC

	.loc_0x1C0:
	  mulli     r4, r4, 0xC
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r4
	  lwzu      r0, 0x8(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x1E0
	  li        r0, 0
	  stw       r0, 0x0(r3)

	.loc_0x1E0:
	  lwz       r0, 0x14(r29)
	  add       r3, r0, r4
	  stfs      f31, 0x4(r3)

	.loc_0x1EC:
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void SearchBuffer::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E42E0
 * Size:	00002C
 */
void SearchBuffer::getCreature(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  blt-      .loc_0x14
	  lha       r0, 0x18(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x1C

	.loc_0x14:
	  li        r3, 0
	  blr

	.loc_0x1C:
	  mulli     r0, r4, 0xC
	  lwz       r3, 0x14(r3)
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E430C
 * Size:	000008
 */
u32 SearchBuffer::getFirst() { return 0x0; }

/*
 * --INFO--
 * Address:	800E4314
 * Size:	000008
 */
void SearchBuffer::getNext(int)
{
	/*
	.loc_0x0:
	  addi      r3, r4, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E431C
 * Size:	00001C
 */
void SearchBuffer::isDone(int)
{
	/*
	.loc_0x0:
	  lha       r0, 0x18(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}
