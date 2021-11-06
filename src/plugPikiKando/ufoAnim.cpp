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
 * Address:	800E97AC
 * Size:	000158
 */
UfoShapeObject::UfoShapeObject(Shape *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r3, 0
  li        r3, 0x88
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  addi      r28, r4, 0
  bl        -0xA27D0
  lis       r4, 0x800F
  subi      r4, r4, 0x66FC
  li        r5, 0
  li        r6, 0x10
  li        r7, 0x8
  bl        0x12B43C
  stw       r3, 0x8(r31)
  lis       r3, 0x802C
  subi      r0, r3, 0x3B4C
  stw       r28, 0x0(r31)
  mr        r29, r0
  li        r3, 0xB8
  bl        -0xA2804
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x84
  lis       r6, 0x1
  addi      r4, r28, 0
  addi      r5, r29, 0
  subi      r6, r6, 0x8000
  li        r7, 0
  bl        -0x98F88

.loc_0x84:
  stw       r30, 0x4(r31)
  lis       r3, 0x802C
  subi      r0, r3, 0x3B34
  lwz       r3, 0x4(r31)
  li        r4, 0
  stw       r0, 0x4(r3)
  lwz       r3, 0x0(r31)
  lwz       r5, 0x8(r31)
  bl        -0xB47EC
  lwz       r5, 0x8(r31)
  li        r4, 0x26
  lwz       r3, 0x0(r31)
  addi      r5, r5, 0x10
  bl        -0xB4800
  lwz       r5, 0x8(r31)
  li        r4, 0x24
  lwz       r3, 0x0(r31)
  addi      r5, r5, 0x20
  bl        -0xB4814
  lwz       r5, 0x8(r31)
  li        r4, 0x13
  lwz       r3, 0x0(r31)
  addi      r5, r5, 0x30
  bl        -0xB4828
  lwz       r5, 0x8(r31)
  li        r4, 0x20
  lwz       r3, 0x0(r31)
  addi      r5, r5, 0x40
  bl        -0xB483C
  lwz       r5, 0x8(r31)
  li        r4, 0x25
  lwz       r3, 0x0(r31)
  addi      r5, r5, 0x50
  bl        -0xB4850
  lwz       r5, 0x8(r31)
  li        r4, 0x1D
  lwz       r3, 0x0(r31)
  addi      r5, r5, 0x60
  bl        -0xB4864
  lwz       r5, 0x8(r31)
  li        r4, 0x35
  lwz       r3, 0x0(r31)
  addi      r5, r5, 0x70
  bl        -0xB4878
  mr        r3, r31
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E9904
 * Size:	000028
 */
AnimContext::AnimContext()
{
/*
.loc_0x0:
  lis       r4, 0x8023
  subi      r0, r4, 0x7730
  stw       r0, 0xC(r3)
  li        r0, 0
  stw       r0, 0x0(r3)
  lfs       f0, -0x65F0(r2)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x65EC(r2)
  stfs      f0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E992C
 * Size:	0002B0
 */
void PaniUfoAnimator::createMotionTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x8
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  bl        -0xA2940
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x30
  li        r4, 0x11
  bl        0x356B0

.loc_0x30:
  li        r3, 0x8
  bl        -0xA295C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x4C
  li        r4, 0
  bl        0x35654

.loc_0x4C:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x0(r4)
  bl        -0xA2980
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x70
  li        r4, 0x1
  bl        0x35630

.loc_0x70:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x4(r4)
  bl        -0xA29A4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x94
  li        r4, 0x2
  bl        0x3560C

.loc_0x94:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x8(r4)
  bl        -0xA29C8
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xB8
  li        r4, 0x3
  bl        0x355E8

.loc_0xB8:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0xC(r4)
  bl        -0xA29EC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xDC
  li        r4, 0x4
  bl        0x355C4

.loc_0xDC:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x10(r4)
  bl        -0xA2A10
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x100
  li        r4, 0x5
  bl        0x355A0

.loc_0x100:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x14(r4)
  bl        -0xA2A34
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x124
  li        r4, 0x6
  bl        0x3557C

.loc_0x124:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x18(r4)
  bl        -0xA2A58
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x148
  li        r4, 0x7
  bl        0x35558

.loc_0x148:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x1C(r4)
  bl        -0xA2A7C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x16C
  li        r4, 0x8
  bl        0x35534

.loc_0x16C:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x20(r4)
  bl        -0xA2AA0
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x190
  li        r4, 0x9
  bl        0x35510

.loc_0x190:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x24(r4)
  bl        -0xA2AC4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1B4
  li        r4, 0xA
  bl        0x354EC

.loc_0x1B4:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x28(r4)
  bl        -0xA2AE8
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1D8
  li        r4, 0xB
  bl        0x354C8

.loc_0x1D8:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x2C(r4)
  bl        -0xA2B0C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1FC
  li        r4, 0xC
  bl        0x354A4

.loc_0x1FC:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x30(r4)
  bl        -0xA2B30
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x220
  li        r4, 0xD
  bl        0x35480

.loc_0x220:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x34(r4)
  bl        -0xA2B54
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x244
  li        r4, 0xE
  bl        0x3545C

.loc_0x244:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x38(r4)
  bl        -0xA2B78
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x268
  li        r4, 0xF
  bl        0x35438

.loc_0x268:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x3C(r4)
  bl        -0xA2B9C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x28C
  li        r4, 0x10
  bl        0x35414

.loc_0x28C:
  lwz       r4, 0x4(r31)
  mr        r3, r31
  stw       r30, 0x40(r4)
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
 * Address:	800E9BDC
 * Size:	00003C
 */
PaniUfoAnimator::PaniUfoAnimator()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        0x354F0
  lis       r3, 0x802C
  subi      r0, r3, 0x3A44
  stw       r0, 0x30(r31)
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E9C18
 * Size:	00005C
 */
UfoAnimator::UfoAnimator()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  li        r3, 0x2A8
  bl        -0xA2C2C
  lis       r4, 0x800F
  subi      r4, r4, 0x6424
  li        r5, 0
  li        r6, 0x54
  li        r7, 0x8
  bl        0x12AFE0
  stw       r3, 0x0(r31)
  li        r3, 0x20
  bl        -0xA2C50
  stw       r3, 0x4(r31)
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E9C74
 * Size:	0000A4
 */
void UfoAnimator::init(UfoShapeObject *, PaniMotionTable *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stfd      f31, 0x40(r1)
  stmw      r25, 0x24(r1)
  li        r28, 0
  mulli     r30, r28, 0x54
  addi      r25, r3, 0
  addi      r26, r4, 0
  addi      r27, r5, 0
  rlwinm    r31,r28,4,0,27
  li        r29, 0
  lfs       f31, -0x65F0(r2)

.loc_0x34:
  lwz       r3, 0x0(r25)
  mr        r6, r27
  lwz       r0, 0x8(r26)
  lwz       r5, 0x4(r26)
  add       r3, r3, r30
  add       r4, r0, r31
  bl        0x35464
  lwz       r5, 0x4(r25)
  addi      r3, r1, 0x14
  li        r4, 0
  stfsx     f31, r5, r29
  bl        0x35284
  lwz       r0, 0x0(r25)
  addi      r4, r3, 0
  add       r3, r0, r30
  bl        0x354DC
  addi      r28, r28, 0x1
  cmpwi     r28, 0x8
  addi      r31, r31, 0x10
  addi      r30, r30, 0x54
  addi      r29, r29, 0x4
  blt+      .loc_0x34
  lmw       r25, 0x24(r1)
  lwz       r0, 0x4C(r1)
  lfd       f31, 0x40(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E9D18
 * Size:	000038
 */
void UfoAnimator::startMotion(int, PaniMotionInfo *)
{
/*
.loc_0x0:
  mflr      r0
  cmplwi    r5, 0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  beq-      .loc_0x28
  mulli     r0, r4, 0x54
  lwz       r3, 0x0(r3)
  addi      r4, r5, 0
  add       r3, r3, r0
  bl        0x35484

.loc_0x28:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E9D50
 * Size:	000010
 */
void UfoAnimator::setMotionSpeed(int, float)
{
/*
.loc_0x0:
  lwz       r3, 0x4(r3)
  rlwinm    r0,r4,2,0,29
  stfsx     f1, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E9D60
 * Size:	000014
 */
void UfoAnimator::getMotionIndex(int)
{
/*
.loc_0x0:
  mulli     r4, r4, 0x54
  lwz       r3, 0x0(r3)
  addi      r0, r4, 0x44
  lwzx      r3, r3, r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800E9D74
 * Size:	000048
 */
void UfoAnimator::stopAllMotions()
{
/*
.loc_0x0:
  lfs       f0, -0x65F0(r2)
  lwz       r4, 0x4(r3)
  stfs      f0, 0x0(r4)
  lwz       r4, 0x4(r3)
  stfs      f0, 0x4(r4)
  lwz       r4, 0x4(r3)
  stfs      f0, 0x8(r4)
  lwz       r4, 0x4(r3)
  stfs      f0, 0xC(r4)
  lwz       r4, 0x4(r3)
  stfs      f0, 0x10(r4)
  lwz       r4, 0x4(r3)
  stfs      f0, 0x14(r4)
  lwz       r4, 0x4(r3)
  stfs      f0, 0x18(r4)
  lwz       r3, 0x4(r3)
  stfs      f0, 0x1C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800E9DBC
 * Size:	000120
 */
void UfoAnimator::initFlagMotions(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stfd      f31, 0x30(r1)
  stmw      r27, 0x1C(r1)
  li        r29, 0x1
  mulli     r31, r29, 0x54
  addi      r27, r3, 0
  addi      r28, r4, 0
  li        r30, 0x4
  lfs       f31, -0x65F0(r2)

.loc_0x2C:
  addi      r3, r1, 0x10
  addi      r4, r29, 0x2
  bl        0x35168
  cmplwi    r3, 0
  beq-      .loc_0x50
  lwz       r0, 0x0(r27)
  addi      r4, r3, 0
  add       r3, r0, r31
  bl        0x353B8

.loc_0x50:
  lwz       r3, 0x4(r27)
  addi      r29, r29, 0x1
  cmpwi     r29, 0x8
  stfsx     f31, r3, r30
  addi      r31, r31, 0x54
  addi      r30, r30, 0x4
  blt+      .loc_0x2C
  addi      r3, r27, 0
  addi      r4, r28, 0
  bl        .loc_0x120
  cmpwi     r28, 0x3
  beq-      .loc_0xA8
  bge-      .loc_0x94
  cmpwi     r28, 0x1
  beq-      .loc_0xD8
  bge-      .loc_0xC0
  b         .loc_0xF0

.loc_0x94:
  cmpwi     r28, 0x6
  bge-      .loc_0xF0
  addi      r3, r27, 0
  li        r4, 0x6
  bl        0x1C0

.loc_0xA8:
  addi      r3, r27, 0
  li        r4, 0x7
  bl        0x1B4
  addi      r3, r27, 0
  li        r4, 0x3
  bl        0x1A8

.loc_0xC0:
  addi      r3, r27, 0
  li        r4, 0x4
  bl        0x19C
  addi      r3, r27, 0
  li        r4, 0x5
  bl        0x190

.loc_0xD8:
  addi      r3, r27, 0
  li        r4, 0x1
  bl        0x184
  addi      r3, r27, 0
  li        r4, 0x2
  bl        0x178

.loc_0xF0:
  lwz       r3, 0x2F6C(r13)
  bl        -0x68D6C
  cmpwi     r28, 0x5
  bne-      .loc_0x108
  lwz       r3, 0x2F6C(r13)
  bl        -0x68E00

.loc_0x108:
  lmw       r27, 0x1C(r1)
  lwz       r0, 0x3C(r1)
  lfd       f31, 0x30(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr       

.loc_0x120:
*/
}

/*
 * --INFO--
 * Address:	800E9EDC
 * Size:	000144
 */
void UfoAnimator::startFlagMotions(int)
{
/*
.loc_0x0:
  mflr      r0
  cmpwi     r4, 0x3
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stfd      f31, 0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  stw       r29, 0x24(r1)
  stw       r28, 0x20(r1)
  addi      r28, r3, 0
  beq-      .loc_0x90
  bge-      .loc_0x48
  cmpwi     r4, 0x1
  beq-      .loc_0xB8
  bge-      .loc_0xA4
  cmpwi     r4, 0
  bge-      .loc_0xD0
  b         .loc_0x120

.loc_0x48:
  cmpwi     r4, 0x5
  beq-      .loc_0x58
  bge-      .loc_0x120
  b         .loc_0x84

.loc_0x58:
  addi      r3, r1, 0x18
  li        r4, 0xA
  bl        0x3501C
  cmplwi    r3, 0
  beq-      .loc_0x7C
  lwz       r5, 0x0(r28)
  addi      r4, r3, 0
  addi      r3, r5, 0x24C
  bl        0x3526C

.loc_0x7C:
  lwz       r3, 0x2F6C(r13)
  bl        -0x68E9C

.loc_0x84:
  lfs       f0, -0x65EC(r2)
  lwz       r3, 0x4(r28)
  stfs      f0, 0x18(r3)

.loc_0x90:
  lfs       f0, -0x65EC(r2)
  lwz       r3, 0x4(r28)
  stfs      f0, 0x1C(r3)
  lwz       r3, 0x4(r28)
  stfs      f0, 0xC(r3)

.loc_0xA4:
  lfs       f0, -0x65EC(r2)
  lwz       r3, 0x4(r28)
  stfs      f0, 0x10(r3)
  lwz       r3, 0x4(r28)
  stfs      f0, 0x14(r3)

.loc_0xB8:
  lfs       f0, -0x65EC(r2)
  lwz       r3, 0x4(r28)
  stfs      f0, 0x4(r3)
  lwz       r3, 0x4(r28)
  stfs      f0, 0x8(r3)
  b         .loc_0x120

.loc_0xD0:
  li        r29, 0x1
  lfs       f31, -0x65F0(r2)
  mulli     r31, r29, 0x54
  li        r30, 0x4

.loc_0xE0:
  addi      r3, r1, 0x10
  addi      r4, r29, 0x2
  bl        0x34F94
  cmplwi    r3, 0
  beq-      .loc_0x104
  lwz       r0, 0x0(r28)
  addi      r4, r3, 0
  add       r3, r0, r31
  bl        0x351E4

.loc_0x104:
  lwz       r3, 0x4(r28)
  addi      r29, r29, 0x1
  cmpwi     r29, 0x8
  stfsx     f31, r3, r30
  addi      r31, r31, 0x54
  addi      r30, r30, 0x4
  blt+      .loc_0xE0

.loc_0x120:
  lwz       r0, 0x3C(r1)
  lfd       f31, 0x30(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  lwz       r29, 0x24(r1)
  lwz       r28, 0x20(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EA020
 * Size:	000088
 */
void UfoAnimator::setMotionLastFrame(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mulli     r31, r4, 0x54
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  lwz       r0, 0x0(r3)
  add       r3, r0, r31
  lwz       r3, 0x28(r3)
  bl        -0x99C60
  lwz       r0, 0x0(r30)
  subi      r4, r3, 0x1
  add       r3, r0, r31
  lwz       r3, 0x28(r3)
  bl        -0x99B98
  xoris     r3, r3, 0x8000
  lwz       r0, 0x0(r30)
  stw       r3, 0x14(r1)
  lis       r4, 0x4330
  lfd       f2, -0x65E0(r2)
  add       r3, r0, r31
  stw       r4, 0x10(r1)
  lfs       f0, -0x65E8(r2)
  lfd       f1, 0x10(r1)
  fsubs     f1, f1, f2
  fsubs     f0, f1, f0
  stfs      f0, 0x2C(r3)
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
 * Address:	800EA0A8
 * Size:	000080
 */
void UfoAnimator::updateAnimation()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  li        r29, 0
  mulli     r30, r29, 0x54
  stw       r28, 0x10(r1)
  addi      r28, r3, 0
  rlwinm    r31,r29,2,0,29

.loc_0x2C:
  lwz       r0, 0x0(r28)
  lwz       r4, 0x4(r28)
  add       r3, r0, r30
  lwz       r12, 0x30(r3)
  lfsx      f1, r4, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  addi      r29, r29, 0x1
  cmpwi     r29, 0x8
  addi      r31, r31, 0x4
  addi      r30, r30, 0x54
  blt+      .loc_0x2C
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  lwz       r28, 0x10(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EA128
 * Size:	000068
 */
void UfoAnimator::updateContext()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  li        r30, 0
  mulli     r31, r30, 0x54
  stw       r29, 0x14(r1)
  addi      r29, r3, 0

.loc_0x24:
  lwz       r0, 0x0(r29)
  add       r3, r0, r31
  lwz       r12, 0x30(r3)
  lwz       r12, 0x18(r12)
  mtlr      r12
  blrl      
  addi      r30, r30, 0x1
  cmpwi     r30, 0x8
  addi      r31, r31, 0x54
  blt+      .loc_0x24
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  lwz       r29, 0x14(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}
