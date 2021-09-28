

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
 * Address:	800F7E8C
 * Size:	000268
 */
void PaniItemAnimator::createMotionTable()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x8
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  bl        -0xB0EA0
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x30
  li        r4, 0xF
  bl        0x27150

.loc_0x30:
  li        r3, 0x8
  bl        -0xB0EBC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x4C
  li        r4, 0
  bl        0x270F4

.loc_0x4C:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x0(r4)
  bl        -0xB0EE0
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x70
  li        r4, 0x1
  bl        0x270D0

.loc_0x70:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x4(r4)
  bl        -0xB0F04
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x94
  li        r4, 0x2
  bl        0x270AC

.loc_0x94:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x8(r4)
  bl        -0xB0F28
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xB8
  li        r4, 0x3
  bl        0x27088

.loc_0xB8:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0xC(r4)
  bl        -0xB0F4C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xDC
  li        r4, 0x4
  bl        0x27064

.loc_0xDC:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x10(r4)
  bl        -0xB0F70
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x100
  li        r4, 0x5
  bl        0x27040

.loc_0x100:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x14(r4)
  bl        -0xB0F94
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x124
  li        r4, 0x6
  bl        0x2701C

.loc_0x124:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x18(r4)
  bl        -0xB0FB8
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x148
  li        r4, 0x7
  bl        0x26FF8

.loc_0x148:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x1C(r4)
  bl        -0xB0FDC
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x16C
  li        r4, 0x8
  bl        0x26FD4

.loc_0x16C:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x20(r4)
  bl        -0xB1000
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x190
  li        r4, 0x9
  bl        0x26FB0

.loc_0x190:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x24(r4)
  bl        -0xB1024
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1B4
  li        r4, 0xA
  bl        0x26F8C

.loc_0x1B4:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x28(r4)
  bl        -0xB1048
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1D8
  li        r4, 0xB
  bl        0x26F68

.loc_0x1D8:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x2C(r4)
  bl        -0xB106C
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x1FC
  li        r4, 0xC
  bl        0x26F44

.loc_0x1FC:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x30(r4)
  bl        -0xB1090
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x220
  li        r4, 0xD
  bl        0x26F20

.loc_0x220:
  lwz       r4, 0x4(r31)
  li        r3, 0x8
  stw       r30, 0x34(r4)
  bl        -0xB10B4
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x244
  li        r4, 0xE
  bl        0x26EFC

.loc_0x244:
  lwz       r4, 0x4(r31)
  mr        r3, r31
  stw       r30, 0x38(r4)
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
 * Address:	800F80F4
 * Size:	00003C
 */
void PaniItemAnimator::PaniItemAnimator()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        0x26FD8
  lis       r3, 0x802C
  subi      r0, r3, 0x68
  stw       r0, 0x30(r31)
  mr        r3, r31
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}