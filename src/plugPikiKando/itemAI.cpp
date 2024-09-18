#include "ItemAI.h"
#include "PikiHeadItem.h"
#include "BombItem.h"
#include "GoalItem.h"
#include "GemItem.h"
#include "Collision.h"

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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800EECE8
 * Size:	00033C
 */
SluiceAI::SluiceAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  bl        -0x71820
	  lis       r3, 0x802C
	  subi      r0, r3, 0x1B50
	  stw       r0, 0x0(r31)
	  li        r3, 0xC
	  bl        -0xA7D14
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lis       r4, 0x802B
	  subi      r0, r4, 0x2950
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2988
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  subi      r4, r4, 0x2C60
	  li        r0, 0
	  stw       r4, 0x0(r3)
	  stw       r0, 0x8(r3)

	.loc_0x70:
	  addi      r30, r3, 0
	  li        r3, 0xC
	  bl        -0xA7D5C
	  cmplwi    r3, 0
	  beq-      .loc_0xB8
	  lis       r4, 0x802B
	  subi      r0, r4, 0x2950
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2988
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  subi      r4, r4, 0x2C60
	  li        r0, 0x1
	  stw       r4, 0x0(r3)
	  stw       r0, 0x8(r3)

	.loc_0xB8:
	  li        r0, 0x6
	  stw       r0, 0xC(r31)
	  li        r0, 0
	  addi      r29, r3, 0
	  stw       r0, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA7DB8
	  stw       r3, 0x4(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA7DC8
	  stw       r3, 0x10(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA7DD8
	  stw       r3, 0x14(r31)
	  li        r3, 0x4
	  bl        -0xA7DE4
	  mr.       r6, r3
	  beq-      .loc_0x124
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1C28
	  stw       r0, 0x0(r3)

	.loc_0x124:
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x718A8
	  li        r3, 0x4
	  bl        -0xA7E24
	  mr.       r6, r3
	  beq-      .loc_0x164
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1CAC
	  stw       r0, 0x0(r3)

	.loc_0x164:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x718E8
	  li        r3, 0x4
	  bl        -0xA7E64
	  mr.       r6, r3
	  beq-      .loc_0x1A4
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1C80
	  stw       r0, 0x0(r3)

	.loc_0x1A4:
	  addi      r3, r31, 0
	  li        r4, 0x3
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x71928
	  li        r3, 0x4
	  bl        -0xA7EA4
	  mr.       r6, r3
	  beq-      .loc_0x1E4
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1CD8
	  stw       r0, 0x0(r3)

	.loc_0x1E4:
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x71968
	  li        r3, 0x4
	  bl        -0xA7EE4
	  mr.       r6, r3
	  beq-      .loc_0x224
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1C50
	  stw       r0, 0x0(r3)

	.loc_0x224:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x719A8
	  li        r3, 0x4
	  bl        -0xA7F24
	  mr.       r6, r3
	  beq-      .loc_0x264
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1D08
	  stw       r0, 0x0(r3)

	.loc_0x264:
	  addi      r3, r31, 0
	  li        r4, 0x5
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x719E8
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r6, 0x4
	  bl        -0x71914
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x2
	  li        r6, 0x3
	  bl        -0x71928
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x3
	  li        r6, 0x3
	  bl        -0x7193C
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x3
	  li        r6, 0x4
	  bl        -0x71950
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x1
	  li        r6, 0x2
	  bl        -0x71964
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0x1
	  li        r6, 0x5
	  bl        -0x71978
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x5
	  li        r6, 0x2
	  bl        -0x7198C
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x5
	  li        r6, 0x1
	  bl        -0x719A0
	  mr        r3, r31
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF024
 * Size:	00003C
 */
void SluiceAI::Init::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x2D4(r4)
	  lwz       r3, 0x2E8(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
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
 * Address:	800EF060
 * Size:	00006C
 */
void SluiceAI::MotionDone::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2D4(r4)
	  cmpwi     r3, 0
	  bgt-      .loc_0x3C
	  li        r0, 0
	  stw       r0, 0x2D4(r4)
	  li        r5, 0x1
	  lwz       r3, 0x2E8(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C

	.loc_0x3C:
	  subi      r0, r3, 0x1
	  stw       r0, 0x2D4(r4)
	  li        r5, 0x2
	  lwz       r3, 0x2E8(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF0CC
 * Size:	000010
 */
void SluiceAI::AddCount::act(AICreature*)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2D4(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2D4(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF0DC
 * Size:	00008C
 */
void SluiceAI::WaitInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x50
	  lwz       r3, 0x454(r31)
	  li        r4, 0x1
	  bl        -0x4D9A4
	  lwz       r3, 0x2C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  bl        -0x4B1A4
	  b         .loc_0x5C

	.loc_0x50:
	  lwz       r3, 0x454(r31)
	  li        r4, 0
	  bl        -0x4D9C4

	.loc_0x5C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x150(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        0x7894
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF168
 * Size:	00008C
 */
void SluiceAI::ChangeInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lfs       f1, -0x6458(r2)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x2D0(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        0x77A4
	  lwz       r3, 0x440(r31)
	  lwz       r4, 0x2D0(r31)
	  subi      r0, r3, 0x1
	  cmpw      r4, r0
	  bne-      .loc_0x6C
	  lwz       r3, 0x454(r31)
	  li        r4, 0x1
	  bl        -0x4DA60

	.loc_0x6C:
	  lwz       r3, 0x2D0(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2D0(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF1F4
 * Size:	00006C
 */
void SluiceAI::DamageInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  lwz       r3, 0x444(r4)
	  lwz       r0, 0x440(r4)
	  cmpw      r3, r0
	  bge-      .loc_0x58
	  mr        r3, r31
	  lfs       f1, -0x6458(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x2D0(r31)
	  lwz       r12, 0x0(r31)
	  addi      r4, r4, 0x3
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl

	.loc_0x58:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF260
 * Size:	00050C
 */
PikiHeadAI::PikiHeadAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  bl        -0x71D98
	  lis       r3, 0x802C
	  subi      r0, r3, 0x1D44
	  stw       r0, 0x0(r31)
	  li        r3, 0xF
	  li        r0, 0
	  stw       r3, 0xC(r31)
	  stw       r0, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA82A0
	  stw       r3, 0x4(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA82B0
	  stw       r3, 0x10(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA82C0
	  stw       r3, 0x14(r31)
	  addi      r3, r31, 0
	  li        r4, 0xD
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x71D6C
	  li        r3, 0x4
	  bl        -0xA82E8
	  mr.       r6, r3
	  beq-      .loc_0xB0
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1D70
	  stw       r0, 0x0(r3)

	.loc_0xB0:
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r5, 0x6
	  li        r7, 0
	  li        r8, 0
	  bl        -0x71DAC
	  li        r3, 0x4
	  bl        -0xA8328
	  mr.       r30, r3
	  beq-      .loc_0xF0
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1E38
	  stw       r0, 0x0(r3)

	.loc_0xF0:
	  li        r3, 0x4
	  bl        -0xA8350
	  mr.       r7, r3
	  beq-      .loc_0x118
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1E68
	  stw       r0, 0x0(r3)

	.loc_0x118:
	  addi      r3, r31, 0
	  addi      r6, r30, 0
	  li        r4, 0xE
	  li        r5, -0x1
	  li        r8, 0
	  bl        -0x71E14
	  li        r3, 0x4
	  bl        -0xA8390
	  mr.       r30, r3
	  beq-      .loc_0x158
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1DA0
	  stw       r0, 0x0(r3)

	.loc_0x158:
	  li        r3, 0x4
	  bl        -0xA83B8
	  mr.       r29, r3
	  beq-      .loc_0x180
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1DD4
	  stw       r0, 0x0(r3)

	.loc_0x180:
	  li        r3, 0x4
	  bl        -0xA83E0
	  mr.       r8, r3
	  beq-      .loc_0x1A8
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1E04
	  stw       r0, 0x0(r3)

	.loc_0x1A8:
	  addi      r3, r31, 0
	  addi      r6, r30, 0
	  addi      r7, r29, 0
	  li        r4, 0
	  li        r5, 0
	  bl        -0x71EA4
	  li        r3, 0x4
	  bl        -0xA8420
	  mr.       r29, r3
	  beq-      .loc_0x1E8
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1E98
	  stw       r0, 0x0(r3)

	.loc_0x1E8:
	  li        r3, 0x4
	  bl        -0xA8448
	  mr.       r7, r3
	  beq-      .loc_0x210
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1EC8
	  stw       r0, 0x0(r3)

	.loc_0x210:
	  addi      r3, r31, 0
	  addi      r6, r29, 0
	  li        r4, 0x3
	  li        r5, -0x1
	  li        r8, 0
	  bl        -0x71F0C
	  li        r3, 0x4
	  bl        -0xA8488
	  mr.       r29, r3
	  beq-      .loc_0x250
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1EF8
	  stw       r0, 0x0(r3)

	.loc_0x250:
	  li        r3, 0x4
	  bl        -0xA84B0
	  mr.       r7, r3
	  beq-      .loc_0x278
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1F28
	  stw       r0, 0x0(r3)

	.loc_0x278:
	  addi      r3, r31, 0
	  addi      r6, r29, 0
	  li        r4, 0x4
	  li        r5, -0x1
	  li        r8, 0
	  bl        -0x71F74
	  addi      r3, r31, 0
	  li        r4, 0x5
	  li        r5, 0x2
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x71F90
	  li        r3, 0x4
	  bl        -0xA850C
	  mr.       r29, r3
	  beq-      .loc_0x2D4
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1F58
	  stw       r0, 0x0(r3)

	.loc_0x2D4:
	  li        r3, 0x4
	  bl        -0xA8534
	  mr.       r7, r3
	  beq-      .loc_0x2FC
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1F88
	  stw       r0, 0x0(r3)

	.loc_0x2FC:
	  addi      r3, r31, 0
	  addi      r6, r29, 0
	  li        r4, 0x6
	  li        r5, 0x3
	  li        r8, 0
	  bl        -0x71FF8
	  addi      r3, r31, 0
	  li        r4, 0x7
	  li        r5, 0x4
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x72014
	  li        r3, 0x4
	  bl        -0xA8590
	  mr.       r6, r3
	  beq-      .loc_0x358
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1FB8
	  stw       r0, 0x0(r3)

	.loc_0x358:
	  addi      r3, r31, 0
	  li        r4, 0x8
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x72054
	  li        r3, 0x4
	  bl        -0xA85D0
	  mr.       r6, r3
	  beq-      .loc_0x398
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x1FEC
	  stw       r0, 0x0(r3)

	.loc_0x398:
	  addi      r3, r31, 0
	  li        r4, 0x9
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x72094
	  addi      r3, r31, 0
	  li        r4, 0xA
	  li        r5, 0x5
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x720B0
	  li        r3, 0x4
	  bl        -0xA862C
	  mr.       r29, r3
	  beq-      .loc_0x3F4
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x201C
	  stw       r0, 0x0(r3)

	.loc_0x3F4:
	  li        r3, 0x4
	  bl        -0xA8654
	  mr.       r7, r3
	  beq-      .loc_0x41C
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x204C
	  stw       r0, 0x0(r3)

	.loc_0x41C:
	  addi      r3, r31, 0
	  addi      r6, r29, 0
	  li        r4, 0xB
	  li        r5, -0x1
	  li        r8, 0
	  bl        -0x72118
	  li        r3, 0x4
	  bl        -0xA8694
	  mr.       r6, r3
	  beq-      .loc_0x45C
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x207C
	  stw       r0, 0x0(r3)

	.loc_0x45C:
	  addi      r3, r31, 0
	  li        r4, 0xC
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x72158
	  lwz       r5, 0x2F34(r13)
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r6, 0x2
	  bl        -0x72084
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r6, 0x3
	  bl        -0x72098
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x5
	  li        r6, 0x6
	  bl        -0x720AC
	  lwz       r5, 0x2F48(r13)
	  addi      r3, r31, 0
	  li        r4, 0x7
	  li        r6, 0x8
	  bl        -0x720C0
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x8
	  li        r6, 0x6
	  bl        -0x720D4
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0xA
	  li        r6, 0xB
	  bl        -0x720E8
	  mr        r3, r31
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF76C
 * Size:	000114
 */
void PikiHeadAI::BounceSound::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  lfs       f1, 0x94(r4)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f2, 0x9C(r31)
	  bl        -0x875B8
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  bl        0x268E4
	  cmpwi     r3, 0x5
	  bne-      .loc_0x98
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xF
	  li        r6, 0
	  li        r7, 0
	  bl        0xAD368
	  lwz       r4, 0x3E0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x84
	  addi      r3, r31, 0
	  li        r5, 0xD5
	  bl        -0x65234
	  b         .loc_0x100

	.loc_0x84:
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x10F
	  bl        -0x4B3F4
	  b         .loc_0x100

	.loc_0x98:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x32
	  li        r6, 0
	  li        r7, 0
	  bl        0xAD320
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x33
	  li        r6, 0
	  li        r7, 0
	  bl        0xAD308
	  lwz       r4, 0x3E0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xE4
	  addi      r3, r31, 0
	  li        r5, 0xD4
	  bl        -0x65294
	  b         .loc_0x100

	.loc_0xE4:
	  lwz       r3, 0x3038(r13)
	  li        r4, 0x10E
	  bl        -0x4A594
	  lwz       r3, 0x3038(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x10E
	  bl        -0x4B460

	.loc_0x100:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF880
 * Size:	000044
 */
void PikiHeadAI::FlyingEffect::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x31
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  addi      r3, r31, 0x3E4
	  addi      r4, r31, 0x94
	  bl        0x24AFC
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,14,12
	  stw       r0, 0xC8(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF8C4
 * Size:	000028
 */
void PikiHeadAI::FlyingExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0x3E4
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x94
	  stwu      r1, -0x8(r1)
	  bl        0x24B50
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF8EC
 * Size:	000024
 */
void PikiHeadAI::FlyingCleanup::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0x3E4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x24C18
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF910
 * Size:	00000C
 */
void PikiHeadAI::BuryInit2::act(AICreature*)
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x3D0(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF91C
 * Size:	000034
 */
void PikiHeadAI::BuryExec2::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0xC
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2E8(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
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
 * Address:	800EF950
 * Size:	000088
 */
void PikiHeadAI::BuryInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  lwz       r3, 0xC8(r4)
	  oris      r3, r3, 0x4
	  stw       r3, 0xC8(r4)
	  stw       r0, 0x3D0(r4)
	  bl        0x1286F8
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x2C(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x68(r3)
	  stw       r0, 0x28(r1)
	  lfd       f1, -0x6448(r2)
	  lfd       f0, 0x28(r1)
	  lfs       f3, -0x6450(r2)
	  fsubs     f4, f0, f1
	  lfs       f2, -0x6454(r2)
	  lfs       f0, -0x644C(r2)
	  lfs       f1, 0x398(r3)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D8(r31)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EF9D8
 * Size:	000080
 */
void PikiHeadAI::BuryExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2D8(r31)
	  lfs       f1, 0x2D8(r31)
	  lfs       f0, -0x6440(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x6C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0x1
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0x4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x6C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFA58
 * Size:	000074
 */
void PikiHeadAI::TaneInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  bl        0x128604
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x68(r3)
	  stw       r0, 0x20(r1)
	  lfd       f1, -0x6448(r2)
	  lfd       f0, 0x20(r1)
	  lfs       f3, -0x6450(r2)
	  fsubs     f4, f0, f1
	  lfs       f2, -0x6454(r2)
	  lfs       f0, -0x644C(r2)
	  lfs       f1, 0x3A8(r3)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D8(r31)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFACC
 * Size:	000058
 */
void PikiHeadAI::TaneExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2D8(r4)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, -0x6440(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x48
	  lwz       r3, 0x2E8(r4)
	  li        r5, 0x5
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x48:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFB24
 * Size:	0000D8
 */
void PikiHeadAI::WaitInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  lwz       r0, 0x3D0(r4)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x70
	  bl        0x12852C
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x68(r3)
	  stw       r0, 0x38(r1)
	  lfd       f1, -0x6448(r2)
	  lfd       f0, 0x38(r1)
	  lfs       f3, -0x6450(r2)
	  fsubs     f4, f0, f1
	  lfs       f2, -0x6454(r2)
	  lfs       f0, -0x644C(r2)
	  lfs       f1, 0x3C8(r3)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D8(r31)
	  b         .loc_0xBC

	.loc_0x70:
	  bl        0x1284DC
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x3C(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x68(r3)
	  stw       r0, 0x38(r1)
	  lfd       f1, -0x6448(r2)
	  lfd       f0, 0x38(r1)
	  lfs       f3, -0x6450(r2)
	  fsubs     f4, f0, f1
	  lfs       f2, -0x6454(r2)
	  lfs       f0, -0x644C(r2)
	  lfs       f1, 0x3B8(r3)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D8(r31)

	.loc_0xBC:
	  li        r0, 0
	  stw       r0, 0x2D4(r31)
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFBFC
 * Size:	000130
 */
void PikiHeadAI::WaitExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r4
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2D8(r31)
	  lfs       f1, 0x2D8(r31)
	  lfs       f2, -0x6440(r2)
	  fcmpo     cr0, f1, f2
	  bge-      .loc_0x84
	  lwz       r0, 0x3D0(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x64
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0xA
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x11C

	.loc_0x64:
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0x7
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x11C

	.loc_0x84:
	  lfs       f0, -0x644C(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x11C
	  lwz       r0, 0x2D4(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x11C
	  lwz       r0, 0x3D0(r31)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x11C
	  lfs       f0, 0x94(r31)
	  addi      r4, r1, 0x1C
	  li        r3, 0x9
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x4C(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, -0x643C(r2)
	  stfs      f1, 0x50(r1)
	  lfs       f1, 0x4C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4C(r1)
	  stfs      f2, 0x24(r1)
	  lwz       r6, 0x48(r1)
	  stfs      f2, 0x20(r1)
	  lwz       r5, 0x4C(r1)
	  stfs      f2, 0x1C(r1)
	  lwz       r0, 0x50(r1)
	  stfs      f2, 0x30(r1)
	  lfs       f0, -0x6454(r2)
	  stfs      f2, 0x2C(r1)
	  stfs      f2, 0x28(r1)
	  stw       r6, 0x1C(r1)
	  stw       r5, 0x20(r1)
	  stw       r0, 0x24(r1)
	  stfs      f0, 0x40(r1)
	  bl        0x245D4
	  li        r0, 0x1
	  stw       r0, 0x2D4(r31)

	.loc_0x11C:
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFD2C
 * Size:	000148
 */
void PikiHeadAI::GrowupedExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r6, r3, 0x2668
	  lis       r3, 0x8022
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  lis       r4, 0x5555
	  lwz       r5, 0x3D0(r31)
	  addi      r0, r4, 0x5556
	  addi      r7, r31, 0
	  addi      r5, r5, 0x1
	  mulhw     r4, r0, r5
	  rlwinm    r0,r4,1,31,31
	  add       r0, r4, r0
	  mulli     r0, r0, 0x3
	  sub       r0, r5, r0
	  stw       r0, 0x3D0(r31)
	  addi      r4, r3, 0x2674
	  lwz       r5, 0x0(r6)
	  lwz       r0, 0x4(r6)
	  stw       r5, 0x54(r1)
	  stw       r0, 0x58(r1)
	  lwz       r0, 0x8(r6)
	  stw       r0, 0x5C(r1)
	  lwz       r3, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r3, 0x48(r1)
	  stw       r0, 0x4C(r1)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x50(r1)
	  lwz       r4, 0x3E0(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xA8
	  lwz       r0, 0x3D0(r7)
	  addi      r5, r1, 0x54
	  addi      r3, r7, 0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r5, r0
	  bl        -0x65818
	  b         .loc_0xC4

	.loc_0xA8:
	  lwz       r0, 0x3D0(r7)
	  addi      r4, r1, 0x48
	  lwz       r3, 0x3038(r13)
	  addi      r5, r7, 0x94
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  bl        -0x4B9E4

	.loc_0xC4:
	  lfs       f0, 0x94(r31)
	  addi      r4, r1, 0x10
	  li        r3, 0xA
	  stfs      f0, 0x3C(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x40(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, -0x643C(r2)
	  stfs      f1, 0x44(r1)
	  lfs       f1, 0x40(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x40(r1)
	  lfs       f1, -0x6440(r2)
	  lwz       r6, 0x3C(r1)
	  stfs      f1, 0x18(r1)
	  lwz       r5, 0x40(r1)
	  stfs      f1, 0x14(r1)
	  lwz       r0, 0x44(r1)
	  stfs      f1, 0x10(r1)
	  lfs       f0, -0x6454(r2)
	  stfs      f1, 0x24(r1)
	  stfs      f1, 0x20(r1)
	  stfs      f1, 0x1C(r1)
	  stw       r6, 0x10(r1)
	  stw       r5, 0x14(r1)
	  stw       r0, 0x18(r1)
	  stfs      f0, 0x34(r1)
	  bl        0x24484
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFE74
 * Size:	000034
 */
void PikiHeadAI::GrowEffect::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x6
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2E8(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
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
 * Address:	800EFEA8
 * Size:	00007C
 */
void PikiHeadAI::KaretaInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r4
	  bl        0x1281B4
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x2C(r1)
	  lis       r4, 0x4330
	  lwz       r3, 0x68(r3)
	  li        r0, 0
	  stw       r4, 0x28(r1)
	  lfd       f1, -0x6448(r2)
	  lfd       f0, 0x28(r1)
	  lfs       f3, -0x6450(r2)
	  fsubs     f4, f0, f1
	  lfs       f2, -0x6454(r2)
	  lfs       f0, -0x644C(r2)
	  lfs       f1, 0x3D8(r3)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x2D8(r31)
	  stw       r0, 0x3D0(r31)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFF24
 * Size:	000058
 */
void PikiHeadAI::KaretaExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2D8(r4)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, -0x6440(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x48
	  lwz       r3, 0x2E8(r4)
	  li        r5, 0x3
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x48:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFF7C
 * Size:	000028
 */
void PikiHeadAI::Dead::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0
	  stwu      r1, -0x8(r1)
	  bl        -0x652B0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EFFA4
 * Size:	000390
 */
BombAI::BombAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  stw       r28, 0x20(r1)
	  bl        -0x72AE0
	  lis       r3, 0x802C
	  subi      r0, r3, 0x20B4
	  stw       r0, 0x0(r31)
	  li        r3, 0xC
	  bl        -0xA8FD4
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  lis       r4, 0x802B
	  subi      r0, r4, 0x2950
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2988
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  subi      r4, r4, 0x2C60
	  li        r0, 0
	  stw       r4, 0x0(r3)
	  stw       r0, 0x8(r3)

	.loc_0x74:
	  addi      r29, r3, 0
	  li        r3, 0xC
	  bl        -0xA901C
	  cmplwi    r3, 0
	  beq-      .loc_0xBC
	  lis       r4, 0x802B
	  subi      r0, r4, 0x2950
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2988
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  subi      r4, r4, 0x2C60
	  li        r0, 0x1
	  stw       r4, 0x0(r3)
	  stw       r0, 0x8(r3)

	.loc_0xBC:
	  addi      r30, r3, 0
	  li        r3, 0xC
	  bl        -0xA9064
	  cmplwi    r3, 0
	  beq-      .loc_0x104
	  lis       r4, 0x802B
	  subi      r0, r4, 0x2950
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2988
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  subi      r4, r4, 0x2C60
	  li        r0, 0x2
	  stw       r4, 0x0(r3)
	  stw       r0, 0x8(r3)

	.loc_0x104:
	  li        r0, 0x6
	  stw       r0, 0xC(r31)
	  li        r0, 0
	  stw       r0, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA90BC
	  stw       r3, 0x4(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA90CC
	  stw       r3, 0x10(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xA90DC
	  stw       r3, 0x14(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, -0x1
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x72B88
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, -0x1
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x72BA4
	  li        r3, 0x4
	  bl        -0xA9120
	  mr.       r28, r3
	  beq-      .loc_0x1A4
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x20D4
	  stw       r0, 0x0(r3)

	.loc_0x1A4:
	  li        r3, 0x4
	  bl        -0xA9148
	  mr.       r7, r3
	  beq-      .loc_0x1CC
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x20FC
	  stw       r0, 0x0(r3)

	.loc_0x1CC:
	  addi      r3, r31, 0
	  addi      r6, r28, 0
	  li        r4, 0x2
	  li        r5, -0x1
	  li        r8, 0
	  bl        -0x72C0C
	  li        r3, 0x4
	  bl        -0xA9188
	  mr.       r28, r3
	  beq-      .loc_0x20C
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2124
	  stw       r0, 0x0(r3)

	.loc_0x20C:
	  li        r3, 0x4
	  bl        -0xA91B0
	  mr.       r7, r3
	  beq-      .loc_0x234
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x21C4
	  stw       r0, 0x0(r3)

	.loc_0x234:
	  addi      r3, r31, 0
	  addi      r6, r28, 0
	  li        r4, 0x3
	  li        r5, 0
	  li        r8, 0
	  bl        -0x72C74
	  li        r3, 0x4
	  bl        -0xA91F0
	  mr.       r28, r3
	  beq-      .loc_0x274
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x21F0
	  stw       r0, 0x0(r3)

	.loc_0x274:
	  li        r3, 0x4
	  bl        -0xA9218
	  mr.       r7, r3
	  beq-      .loc_0x29C
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x221C
	  stw       r0, 0x0(r3)

	.loc_0x29C:
	  addi      r3, r31, 0
	  addi      r6, r28, 0
	  li        r4, 0x4
	  li        r5, -0x1
	  li        r8, 0
	  bl        -0x72CDC
	  li        r3, 0x4
	  bl        -0xA9258
	  mr.       r28, r3
	  beq-      .loc_0x2DC
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2248
	  stw       r0, 0x0(r3)

	.loc_0x2DC:
	  li        r3, 0x4
	  bl        -0xA9280
	  mr.       r7, r3
	  beq-      .loc_0x304
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2270
	  stw       r0, 0x0(r3)

	.loc_0x304:
	  addi      r3, r31, 0
	  addi      r6, r28, 0
	  li        r4, 0x5
	  li        r5, -0x1
	  li        r8, 0
	  bl        -0x72D44
	  addi      r3, r31, 0
	  addi      r5, r29, 0
	  li        r4, 0
	  li        r6, 0x2
	  bl        -0x72C70
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x2
	  li        r6, 0x3
	  bl        -0x72C84
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0
	  li        r6, 0x3
	  bl        -0x72C98
	  lwz       r5, 0x2F34(r13)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r6, 0x3
	  bl        -0x72CAC
	  mr        r3, r31
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
 * Address:	800F0334
 * Size:	000080
 */
void BombAI::SetInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r4
	  bl        0x127D28
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x3068(r13)
	  stw       r0, 0x24(r1)
	  lis       r0, 0x4330
	  lwz       r3, 0x68(r3)
	  stw       r0, 0x20(r1)
	  lfd       f1, -0x6448(r2)
	  lfd       f0, 0x20(r1)
	  lfs       f3, -0x6450(r2)
	  fsubs     f4, f0, f1
	  lfs       f2, -0x6454(r2)
	  lfs       f0, -0x6438(r2)
	  lfs       f1, 0x408(r3)
	  fdivs     f3, f4, f3
	  fmuls     f3, f2, f3
	  fmuls     f0, f0, f3
	  fadds     f0, f2, f0
	  fmuls     f0, f1, f0
	  stfs      f0, 0x2D8(r31)
	  lfs       f0, 0x2D8(r31)
	  stfs      f0, 0x2E0(r31)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F03B4
 * Size:	000070
 */
void BombAI::SetExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2D8(r4)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, -0x6440(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x60
	  li        r0, 0xA
	  stw       r0, 0x1C(r1)
	  li        r3, 0x1
	  li        r0, 0
	  stw       r3, 0x20(r1)
	  addi      r5, r1, 0x1C
	  stw       r0, 0x2D0(r4)
	  lwz       r3, 0x2E8(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x60:
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F0424
 * Size:	000E3C
 */
void BombAI::BombInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x2C0(r1)
	  stfd      f31, 0x2B8(r1)
	  stfd      f30, 0x2B0(r1)
	  stfd      f29, 0x2A8(r1)
	  stfd      f28, 0x2A0(r1)
	  stfd      f27, 0x298(r1)
	  stfd      f26, 0x290(r1)
	  stmw      r22, 0x268(r1)
	  addi      r31, r4, 0
	  lwz       r0, 0x3160(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xE10
	  lis       r3, 0x802C
	  lwz       r4, 0x3068(r13)
	  subi      r0, r3, 0x2150
	  lfs       f1, -0x6458(r2)
	  lis       r3, 0x802C
	  stw       r0, 0x264(r1)
	  subi      r0, r3, 0x215C
	  stw       r0, 0x264(r1)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x68(r4)
	  lwz       r12, 0x14C(r12)
	  lfs       f27, 0x418(r4)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x11
	  addi      r3, r3, 0x70
	  bl        -0x6CAA4
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0x8
	  li        r5, 0
	  bl        0x8C91C
	  lfs       f1, -0x6440(r2)
	  lfs       f0, -0x6454(r2)
	  stfs      f1, 0x23C(r1)
	  stfs      f1, 0x238(r1)
	  stfs      f1, 0x234(r1)
	  stfs      f1, 0x248(r1)
	  stfs      f1, 0x244(r1)
	  stfs      f1, 0x240(r1)
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x234(r1)
	  stw       r0, 0x238(r1)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x23C(r1)
	  stfs      f0, 0x258(r1)
	  lwz       r0, 0x2D0(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xF0
	  li        r3, 0x14
	  addi      r4, r1, 0x234
	  bl        0x23DD4
	  b         .loc_0xFC

	.loc_0xF0:
	  li        r3, 0x13
	  addi      r4, r1, 0x234
	  bl        0x23DC4

	.loc_0xFC:
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x14
	  addi      r3, r3, 0x54
	  bl        -0x6E068
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x12C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x14
	  lfs       f1, -0x6434(r2)
	  li        r5, 0
	  addi      r3, r3, 0x54
	  bl        -0x6DDCC

	.loc_0x12C:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0x1F
	  bl        -0x65FA8
	  lfs       f0, -0x6440(r2)
	  stfs      f0, 0x2D8(r31)
	  lwz       r29, 0x3120(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802D
	  addi      r30, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r24, r4, 0x2614
	  b         .loc_0x274

	.loc_0x174:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x198
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1B0

	.loc_0x198:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1B0:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x636E4
	  mr        r3, r26
	  fadds     f26, f1, f26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x258
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0x258
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r5, 0x68(r4)
	  addi      r4, r1, 0x218
	  lfs       f0, 0x438(r5)
	  stw       r25, 0x218(r1)
	  stw       r31, 0x21C(r1)
	  stw       r24, 0x218(r1)
	  stfs      f0, 0x220(r1)
	  stw       r0, 0x224(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x258:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x274:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x29C
	  li        r0, 0x1
	  b         .loc_0x2C8

	.loc_0x29C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x2C4
	  li        r0, 0x1
	  b         .loc_0x2C8

	.loc_0x2C4:
	  li        r0, 0

	.loc_0x2C8:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x174
	  lwz       r29, 0x3068(r13)
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802D
	  addi      r30, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r24, r4, 0x2614
	  b         .loc_0x420

	.loc_0x300:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x324
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x33C

	.loc_0x324:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x33C:
	  mr        r26, r3
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x63870
	  mr        r3, r26
	  fadds     f26, f1, f26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x404
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3AC
	  mr        r3, r26
	  bl        -0x28270
	  cmpwi     r3, 0xE
	  bne-      .loc_0x404

	.loc_0x3AC:
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0x404
	  mr        r3, r26
	  bl        -0x2828C
	  cmpwi     r3, 0x21
	  beq-      .loc_0x404
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r5, 0x68(r4)
	  addi      r4, r1, 0x1FC
	  lfs       f0, 0x458(r5)
	  stw       r25, 0x1FC(r1)
	  stw       r31, 0x200(r1)
	  stw       r24, 0x1FC(r1)
	  stfs      f0, 0x204(r1)
	  stw       r0, 0x208(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x404:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x420:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x448
	  li        r0, 0x1
	  b         .loc_0x474

	.loc_0x448:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x470
	  li        r0, 0x1
	  b         .loc_0x474

	.loc_0x470:
	  li        r0, 0

	.loc_0x474:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x300
	  lwz       r28, 0x3160(r13)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f28, -0x6440(r2)
	  lis       r4, 0x802D
	  addi      r27, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r24, r4, 0x2614
	  addi      r30, r1, 0x16C
	  addi      r29, r1, 0x17C
	  b         .loc_0x66C

	.loc_0x4B8:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x4E0
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x4FC

	.loc_0x4E0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x4FC:
	  lwz       r12, 0x0(r26)
	  mr        r3, r26
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x650
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x650
	  lwz       r3, 0x220(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x650
	  bl        -0x66E14
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x650
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  lfs       f3, 0x94(r26)
	  lfs       f4, 0x9C(r26)
	  bl        -0xB8358
	  mr        r3, r26
	  fmr       f26, f1
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fsubs     f0, f26, f27
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f0, f28
	  bgt-      .loc_0x650
	  fmr       f1, f27
	  lwz       r3, 0x220(r26)
	  addi      r4, r31, 0x94
	  addi      r5, r1, 0x264
	  bl        -0x67C84
	  cmplwi    r3, 0
	  beq-      .loc_0x5E0
	  lwz       r5, 0x3068(r13)
	  mr        r4, r29
	  lwz       r5, 0x68(r5)
	  lfs       f0, 0x448(r5)
	  stw       r25, 0x17C(r1)
	  stw       r31, 0x180(r1)
	  stw       r24, 0x17C(r1)
	  stfs      f0, 0x184(r1)
	  stw       r3, 0x188(r1)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x650

	.loc_0x5E0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x64FF4
	  fsubs     f0, f1, f27
	  fsubs     f0, f0, f26
	  fcmpo     cr0, f0, f28
	  bge-      .loc_0x650
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r5, 0x68(r4)
	  mr        r4, r30
	  lfs       f0, 0x448(r5)
	  stw       r25, 0x16C(r1)
	  stw       r31, 0x170(r1)
	  stw       r24, 0x16C(r1)
	  stfs      f0, 0x174(r1)
	  stw       r0, 0x178(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x650:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x66C:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x694
	  li        r0, 0x1
	  b         .loc_0x6C0

	.loc_0x694:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x6BC
	  li        r0, 0x1
	  b         .loc_0x6C0

	.loc_0x6BC:
	  li        r0, 0

	.loc_0x6C0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4B8
	  lwz       r27, 0x3168(r13)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f28, -0x6440(r2)
	  lis       r4, 0x802D
	  addi      r28, r3, 0
	  subi      r25, r5, 0x3064
	  subi      r24, r4, 0x2614
	  addi      r30, r1, 0x14C
	  addi      r29, r1, 0x15C
	  b         .loc_0x8BC

	.loc_0x704:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x72C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0x748

	.loc_0x72C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0x748:
	  lwz       r12, 0x0(r26)
	  mr        r3, r26
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A0
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A0
	  lwz       r3, 0x220(r26)
	  cmplwi    r3, 0
	  beq-      .loc_0x8A0
	  bl        -0x67060
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8A0
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  lfs       f3, 0x94(r26)
	  lfs       f4, 0x9C(r26)
	  bl        -0xB85A4
	  mr        r3, r26
	  fmr       f26, f1
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fsubs     f0, f26, f27
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f0, f28
	  bgt-      .loc_0x8A0
	  fmr       f1, f27
	  lwz       r3, 0x220(r26)
	  addi      r4, r31, 0x94
	  addi      r5, r1, 0x264
	  bl        -0x67ED0
	  lwz       r4, 0x3068(r13)
	  cmplwi    r3, 0
	  lwz       r4, 0x68(r4)
	  addi      r4, r4, 0x448
	  beq-      .loc_0x830
	  lfs       f0, 0x0(r4)
	  mr        r4, r29
	  stw       r25, 0x15C(r1)
	  stw       r31, 0x160(r1)
	  stw       r24, 0x15C(r1)
	  stfs      f0, 0x164(r1)
	  stw       r3, 0x168(r1)
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x8A0

	.loc_0x830:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x65244
	  fsubs     f0, f1, f27
	  fsubs     f0, f0, f26
	  fcmpo     cr0, f0, f28
	  bge-      .loc_0x8A0
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r5, 0x68(r4)
	  mr        r4, r30
	  lfs       f0, 0x448(r5)
	  stw       r25, 0x14C(r1)
	  stw       r31, 0x150(r1)
	  stw       r24, 0x14C(r1)
	  stfs      f0, 0x154(r1)
	  stw       r0, 0x158(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x8A0:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x8BC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x8E4
	  li        r0, 0x1
	  b         .loc_0x910

	.loc_0x8E4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x90C
	  li        r0, 0x1
	  b         .loc_0x910

	.loc_0x90C:
	  li        r0, 0

	.loc_0x910:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x704
	  lwz       r3, 0x30AC(r13)
	  lwz       r27, 0x68(r3)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f29, -0x6440(r2)
	  lis       r4, 0x802D
	  lfd       f30, -0x6428(r2)
	  lfd       f31, -0x6420(r2)
	  addi      r28, r3, 0
	  subi      r30, r5, 0x3064
	  subi      r25, r4, 0x2614
	  lis       r29, 0x666C
	  b         .loc_0xBB4

	.loc_0x95C:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x980
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x998

	.loc_0x980:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x998:
	  lwz       r5, 0x6C(r3)
	  li        r4, 0x1
	  lfs       f26, -0x6430(r2)
	  addi      r26, r3, 0
	  cmpwi     r5, 0x16
	  addi      r3, r4, 0
	  addi      r0, r4, 0
	  beq-      .loc_0x9C4
	  cmpwi     r5, 0x17
	  beq-      .loc_0x9C4
	  li        r0, 0

	.loc_0x9C4:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x9D8
	  cmpwi     r5, 0x18
	  beq-      .loc_0x9D8
	  li        r3, 0

	.loc_0x9D8:
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x9EC
	  cmpwi     r5, 0x19
	  beq-      .loc_0x9EC
	  li        r4, 0

	.loc_0x9EC:
	  rlwinm.   r0,r4,0,24,31
	  beq-      .loc_0xAF0
	  lwz       r3, 0x220(r26)
	  addi      r4, r29, 0x6167
	  bl        -0x67710
	  addi      r23, r3, 0
	  li        r22, 0
	  b         .loc_0xADC

	.loc_0xA0C:
	  addi      r3, r23, 0
	  addi      r4, r22, 0
	  bl        -0x6904C
	  lfs       f2, 0x98(r31)
	  mr        r24, r3
	  lfs       f3, 0x8(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xC(r3)
	  fsubs     f4, f1, f0
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f3, f3
	  fsubs     f2, f2, f1
	  fmuls     f1, f4, f4
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f28, f2, f0
	  fcmpo     cr0, f28, f29
	  ble-      .loc_0xAAC
	  fsqrte    f1, f28
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f28, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f28, f0
	  fsub      f0, f31, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f30, f1
	  fmul      f0, f28, f0
	  fsub      f0, f31, f0
	  fmul      f0, f1, f0
	  fmul      f0, f28, f0
	  frsp      f0, f0
	  stfs      f0, 0xE4(r1)
	  lfs       f28, 0xE4(r1)

	.loc_0xAAC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x0(r24)
	  fsubs     f0, f28, f0
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f0, f26
	  bge-      .loc_0xAD8
	  fmr       f26, f0

	.loc_0xAD8:
	  addi      r22, r22, 0x1

	.loc_0xADC:
	  mr        r3, r23
	  bl        -0x69174
	  cmpw      r22, r3
	  blt+      .loc_0xA0C
	  b         .loc_0xB18

	.loc_0xAF0:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        -0x64024
	  fsubs     f26, f1, f26

	.loc_0xB18:
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r26, 0
	  lwz       r4, 0x68(r4)
	  lfs       f0, 0x438(r4)
	  stw       r30, 0x1AC(r1)
	  stw       r31, 0x1B0(r1)
	  stw       r25, 0x1AC(r1)
	  stfs      f0, 0x1B4(r1)
	  stw       r0, 0x1B8(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB98
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB98
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0xB98
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  addi      r4, r1, 0x1AC
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0xB98:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xBB4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBDC
	  li        r0, 0x1
	  b         .loc_0xC08

	.loc_0xBDC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xC04
	  li        r0, 0x1
	  b         .loc_0xC08

	.loc_0xC04:
	  li        r0, 0

	.loc_0xC08:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x95C
	  lwz       r27, 0x30AC(r13)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802D
	  addi      r28, r3, 0
	  subi      r29, r5, 0x3064
	  subi      r26, r4, 0x2614
	  b         .loc_0xDB4

	.loc_0xC40:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xC68
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3
	  b         .loc_0xC84

	.loc_0xC68:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r24, r3

	.loc_0xC84:
	  addi      r22, r24, 0
	  addi      r3, r22, 0
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fmr       f26, f1
	  addi      r3, r31, 0
	  addi      r4, r22, 0
	  bl        -0x641BC
	  cmplw     r24, r31
	  fsubs     f26, f1, f26
	  beq-      .loc_0xD98
	  lwz       r0, 0x6C(r24)
	  li        r23, 0
	  cmpwi     r0, 0xE
	  bne-      .loc_0xD0C
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0xD0C
	  lwz       r12, 0x0(r24)
	  mr        r3, r24
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x5
	  beq-      .loc_0xD54
	  cmpwi     r0, 0x4
	  beq-      .loc_0xD54
	  cmpwi     r0, 0x3
	  beq-      .loc_0xD54
	  li        r23, 0x1
	  b         .loc_0xD54

	.loc_0xD0C:
	  mr        r3, r22
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD54
	  mr        r3, r22
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xD54
	  fcmpo     cr0, f26, f27
	  cror      2, 0, 0x2
	  bne-      .loc_0xD54
	  li        r23, 0x1

	.loc_0xD54:
	  rlwinm.   r0,r23,0,24,31
	  beq-      .loc_0xD98
	  lwz       r4, 0x3068(r13)
	  li        r0, 0
	  addi      r3, r22, 0
	  lwz       r5, 0x68(r4)
	  addi      r4, r1, 0x18C
	  lfs       f0, 0x428(r5)
	  stw       r29, 0x18C(r1)
	  stw       r31, 0x190(r1)
	  stw       r26, 0x18C(r1)
	  stfs      f0, 0x194(r1)
	  stw       r0, 0x198(r1)
	  lwz       r12, 0x0(r22)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0xD98:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xDB4:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDDC
	  li        r0, 0x1
	  b         .loc_0xE08

	.loc_0xDDC:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xE04
	  li        r0, 0x1
	  b         .loc_0xE08

	.loc_0xE04:
	  li        r0, 0

	.loc_0xE08:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xC40

	.loc_0xE10:
	  lmw       r22, 0x268(r1)
	  lwz       r0, 0x2C4(r1)
	  lfd       f31, 0x2B8(r1)
	  lfd       f30, 0x2B0(r1)
	  lfd       f29, 0x2A8(r1)
	  lfd       f28, 0x2A0(r1)
	  lfd       f27, 0x298(r1)
	  lfd       f26, 0x290(r1)
	  addi      r1, r1, 0x2C0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F1260
 * Size:	000034
 */
void BombAI::BombExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x5
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2E8(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
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
 * Address:	800F1294
 * Size:	00000C
 */
void BombAI::MizuInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x6454(r2)
	  stfs      f0, 0x2D8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F12A0
 * Size:	000080
 */
void BombAI::MizuExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2D8(r4)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2D8(r4)
	  lfs       f31, 0x2D8(r4)
	  lfs       f0, -0x6440(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x5C
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0x5
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C:
	  stfs      f31, 0x7C(r31)
	  stfs      f31, 0x80(r31)
	  stfs      f31, 0x84(r31)
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F1320
 * Size:	000024
 */
void BombAI::DieInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x6418(r2)
	  stfs      f0, 0x2D8(r4)
	  lfs       f0, -0x3280(r13)
	  stfs      f0, 0x7C(r4)
	  lfs       f0, -0x327C(r13)
	  stfs      f0, 0x80(r4)
	  lfs       f0, -0x3278(r13)
	  stfs      f0, 0x84(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F1344
 * Size:	00007C
 */
void BombAI::DieExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r4, 0x2DEC(r13)
	  lwz       r12, 0x14C(r12)
	  lfs       f1, -0x6440(r2)
	  lfs       f31, 0x28C(r4)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x2D8(r31)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x2D8(r31)
	  lfs       f1, 0x2D8(r31)
	  lfs       f0, -0x6440(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x64
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x666C4

	.loc_0x64:
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F13C0
 * Size:	0003E0
 */
GoalAI::GoalAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  bl        -0x73EFC
	  lis       r3, 0x802C
	  subi      r0, r3, 0x22A4
	  stw       r0, 0x0(r31)
	  li        r3, 0xC
	  bl        -0xAA3F0
	  cmplwi    r3, 0
	  beq-      .loc_0x74
	  lis       r4, 0x802B
	  subi      r0, r4, 0x2950
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2988
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  subi      r4, r4, 0x2C60
	  li        r0, 0
	  stw       r4, 0x0(r3)
	  stw       r0, 0x8(r3)

	.loc_0x74:
	  addi      r30, r3, 0
	  li        r3, 0x14
	  bl        -0xAA438
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xB0
	  lis       r4, 0x802C
	  subi      r4, r4, 0x26F4
	  bl        -0xBC49C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x26FC
	  lis       r3, 0x802C
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x22FC
	  stw       r0, 0x0(r29)

	.loc_0xB0:
	  li        r0, 0x7
	  stw       r0, 0xC(r31)
	  li        r0, 0
	  stw       r0, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAA484
	  stw       r3, 0x4(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAA494
	  stw       r3, 0x10(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAA4A4
	  stw       r3, 0x14(r31)
	  li        r3, 0x4
	  bl        -0xAA4B0
	  mr.       r6, r3
	  beq-      .loc_0x118
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2338
	  stw       r0, 0x0(r3)

	.loc_0x118:
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x73F74
	  li        r3, 0x4
	  bl        -0xAA4F0
	  mr.       r6, r3
	  beq-      .loc_0x158
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2440
	  stw       r0, 0x0(r3)

	.loc_0x158:
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0x2
	  li        r7, 0
	  li        r8, 0
	  bl        -0x73FB4
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x73FD0
	  li        r3, 0x4
	  bl        -0xAA54C
	  mr.       r6, r3
	  beq-      .loc_0x1B4
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x23E8
	  stw       r0, 0x0(r3)

	.loc_0x1B4:
	  addi      r3, r31, 0
	  li        r4, 0x3
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x74010
	  li        r3, 0x4
	  bl        -0xAA58C
	  mr.       r7, r3
	  beq-      .loc_0x1F4
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2414
	  stw       r0, 0x0(r3)

	.loc_0x1F4:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, -0x1
	  li        r6, 0
	  li        r8, 0
	  bl        -0x74050
	  li        r3, 0x4
	  bl        -0xAA5CC
	  mr.       r6, r3
	  beq-      .loc_0x234
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2364
	  stw       r0, 0x0(r3)

	.loc_0x234:
	  addi      r3, r31, 0
	  li        r4, 0x5
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x74090
	  li        r3, 0x4
	  bl        -0xAA60C
	  mr.       r28, r3
	  beq-      .loc_0x274
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2390
	  stw       r0, 0x0(r3)

	.loc_0x274:
	  li        r3, 0x4
	  bl        -0xAA634
	  mr.       r8, r3
	  beq-      .loc_0x29C
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x23BC
	  stw       r0, 0x0(r3)

	.loc_0x29C:
	  addi      r3, r31, 0
	  addi      r6, r28, 0
	  li        r4, 0x6
	  li        r5, -0x1
	  li        r7, 0
	  bl        -0x740F8
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0
	  li        r6, 0x1
	  bl        -0x74024
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r6, 0x2
	  bl        -0x74038
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x2
	  li        r6, 0x1
	  bl        -0x7404C
	  lwz       r5, 0x2F3C(r13)
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r6, 0x3
	  bl        -0x74060
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x3
	  li        r6, 0x1
	  bl        -0x74074
	  lwz       r5, 0x2F38(r13)
	  addi      r3, r31, 0
	  li        r4, 0x3
	  li        r6, 0x4
	  bl        -0x74088
	  addi      r4, r29, 0
	  addi      r3, r3, 0x20
	  bl        -0xB111C
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x3
	  li        r6, 0
	  bl        -0x740A8
	  addi      r3, r31, 0
	  addi      r5, r30, 0
	  li        r4, 0x4
	  li        r6, 0x1
	  bl        -0x740BC
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r6, 0
	  bl        -0x740D0
	  lwz       r5, 0x2F3C(r13)
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r6, 0x3
	  bl        -0x740E4
	  addi      r4, r29, 0
	  addi      r3, r3, 0x20
	  bl        -0xB1178
	  lwz       r5, 0x2F48(r13)
	  addi      r3, r31, 0
	  li        r4, 0x5
	  li        r6, 0x6
	  bl        -0x74104
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x6
	  li        r6, 0
	  bl        -0x74118
	  mr        r3, r31
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F17A0
 * Size:	000028
 */
bool GoalAI::NotFinished::satisfy(AICreature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2D0(r4)
	  cmpwi     r0, 0
	  bgt-      .loc_0x18
	  lwz       r0, 0x2D4(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0x20

	.loc_0x18:
	  li        r3, 0x1
	  blr

	.loc_0x20:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F17C8
 * Size:	0000B8
 */
void GoalAI::WaitInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  lwz       r0, 0x3B0(r4)
	  cmpwi     r0, 0x6
	  blt-      .loc_0x28
	  cmpwi     r0, 0x8
	  ble-      .loc_0xA4

	.loc_0x28:
	  lwz       r4, 0x434(r31)
	  lwz       r0, 0x430(r31)
	  lwz       r3, 0x42C(r31)
	  add       r0, r0, r4
	  add.      r0, r3, r0
	  ble-      .loc_0x74
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0xC
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, -0x6458(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xA4

	.loc_0x74:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0x1
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, -0x6458(r2)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14C(r12)
	  mtlr      r12
	  blrl

	.loc_0xA4:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F1880
 * Size:	000038
 */
void GoalAI::BootInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lhz       r4, 0x428(r4)
	  lwz       r12, 0x130(r12)
	  addi      r4, r4, 0x3
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
 * Address:	800F18B8
 * Size:	000460
 */
void GoalAI::BootEmit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stmw      r26, 0x70(r1)
	  mr        r29, r3
	  mr        r30, r4
	  li        r4, 0xF
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r27, r3
	  beq-      .loc_0x124
	  lhz       r4, 0x428(r30)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1EAC
	  rlwinm    r3,r4,2,0,29
	  add       r5, r0, r3
	  lwz       r4, 0x0(r5)
	  addi      r3, r27, 0
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r5)
	  addi      r4, r1, 0x64
	  lfs       f0, 0x94(r30)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x68(r1)
	  lfs       f1, 0x9C(r30)
	  lfs       f0, -0x6414(r2)
	  stfs      f1, 0x6C(r1)
	  lfs       f1, 0x68(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r27
	  lhz       r4, 0x428(r30)
	  bl        -0x4EC0
	  bl        0x12670C
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0x12A1E4
	  lfs       f0, -0x6410(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x12A368
	  lfs       f0, -0x6410(r2)
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  fmuls     f0, f0, f1
	  li        r5, 0xCC
	  stfs      f0, 0x70(r27)
	  lfs       f0, -0x3274(r13)
	  stfs      f0, 0x74(r27)
	  stfs      f31, 0x78(r27)
	  bl        -0x673F4
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r30, 0x3E0(r27)
	  addi      r4, r27, 0
	  li        r5, 0
	  lwz       r3, 0x2E8(r27)
	  bl        -0x7427C
	  b         .loc_0x444

	.loc_0x124:
	  lwz       r3, 0x30AC(r13)
	  li        r31, 0
	  lfs       f30, -0x6440(r2)
	  lwz       r28, 0x64(r3)
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3
	  b         .loc_0x1D0

	.loc_0x150:
	  cmpwi     r27, -0x1
	  bne-      .loc_0x174
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x18C

	.loc_0x174:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x18C:
	  mr        r26, r3
	  lfs       f3, 0x94(r30)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  lfs       f4, 0x9C(r30)
	  bl        -0xB9430
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x1B4
	  fmr       f30, f1
	  mr        r31, r26

	.loc_0x1B4:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r27, r3

	.loc_0x1D0:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F8
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x1F8:
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x220
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x220:
	  li        r0, 0

	.loc_0x224:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x150
	  cmplwi    r31, 0
	  beq-      .loc_0x2B4
	  lis       r3, 0x803D
	  lwz       r4, 0x3CC(r31)
	  addi      r3, r3, 0x1DF0
	  li        r5, 0
	  bl        -0x2C2E4
	  lwz       r3, 0x30AC(r13)
	  lwz       r4, 0x3CC(r31)
	  bl        0xEB0
	  lwz       r5, 0x42C(r3)
	  lis       r4, 0x803D
	  addi      r0, r4, 0x1EA0
	  addi      r4, r5, 0x1
	  stw       r4, 0x42C(r3)
	  lwz       r3, 0x3CC(r31)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x20A28
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x66E64
	  lwz       r4, 0x3CC(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1E88
	  rlwinm    r3,r4,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  b         .loc_0x42C

	.loc_0x2B4:
	  lwz       r27, 0x3068(r13)
	  li        r31, 0
	  lfs       f30, -0x6440(r2)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x35C

	.loc_0x2DC:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x300
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x318

	.loc_0x300:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x318:
	  mr        r26, r3
	  lfs       f3, 0x94(r30)
	  lfs       f1, 0x94(r3)
	  lfs       f2, 0x9C(r3)
	  lfs       f4, 0x9C(r30)
	  bl        -0xB95BC
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x340
	  fmr       f30, f1
	  mr        r31, r26

	.loc_0x340:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x35C:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x384
	  li        r0, 0x1
	  b         .loc_0x3B0

	.loc_0x384:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x3AC
	  li        r0, 0x1
	  b         .loc_0x3B0

	.loc_0x3AC:
	  li        r0, 0

	.loc_0x3B0:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x2DC
	  cmplwi    r31, 0
	  beq-      .loc_0x42C
	  lis       r3, 0x803D
	  addi      r3, r3, 0x1DF0
	  addi      r4, r31, 0
	  bl        -0x2C4A0
	  lwz       r3, 0x30AC(r13)
	  lhz       r4, 0x510(r31)
	  bl        0xD28
	  lwz       r5, 0x520(r31)
	  lis       r4, 0x803D
	  addi      r0, r4, 0x1EA0
	  rlwinm    r4,r5,2,0,29
	  add       r4, r3, r4
	  lwz       r3, 0x42C(r4)
	  addi      r3, r3, 0x1
	  stw       r3, 0x42C(r4)
	  lhz       r3, 0x510(r31)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x20894
	  li        r0, 0x1
	  stb       r0, 0x584(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x67000

	.loc_0x42C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x444:
	  lmw       r26, 0x70(r1)
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F1D18
 * Size:	000004
 */
void GoalAI::BootDone::act(AICreature*) { }

/*
 * --INFO--
 * Address:	800F1D1C
 * Size:	00032C
 */
void GoalAI::EmitPiki::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  stfd      f30, 0x178(r1)
	  stw       r31, 0x174(r1)
	  mr        r31, r4
	  stw       r30, 0x170(r1)
	  stw       r29, 0x16C(r1)
	  lwz       r0, 0x2D4(r4)
	  cmpwi     r0, 0
	  ble-      .loc_0xA0
	  bl        0x126324
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x9E
	  li        r6, 0
	  li        r7, 0
	  bl        0xAADD4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0x9F
	  li        r6, 0
	  li        r7, 0
	  bl        0xAADBC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xA0
	  li        r6, 0
	  li        r7, 0
	  bl        0xAADA4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xA1
	  li        r6, 0
	  li        r7, 0
	  bl        0xAAD8C
	  lwz       r3, 0x2D4(r31)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2D4(r31)

	.loc_0xA0:
	  lwz       r0, 0x2D0(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x2DC
	  lwz       r5, 0x6C(r31)
	  cmpwi     r5, 0x10
	  beq-      .loc_0xCC
	  lis       r3, 0x802C
	  crclr     6, 0x6
	  subi      r4, r3, 0x26E8
	  addi      r3, r1, 0x44
	  bl        0x1247B4

	.loc_0xCC:
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0xF
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  lhz       r0, 0x428(r31)
	  lis       r4, 0x803D
	  mr.       r29, r3
	  rlwinm    r5,r0,2,0,29
	  addi      r0, r4, 0x1EAC
	  add       r5, r0, r5
	  lwz       r4, 0x0(r5)
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r5)
	  beq-      .loc_0x208
	  lfs       f0, 0x94(r31)
	  mr        r3, r29
	  addi      r4, r1, 0x38
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x3C(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, -0x6414(r2)
	  stfs      f1, 0x40(r1)
	  lfs       f1, 0x3C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3C(r1)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lhz       r4, 0x428(r31)
	  bl        -0x53D0
	  bl        0x1261FC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6448(r2)
	  stw       r0, 0x164(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x6450(r2)
	  stw       r0, 0x160(r1)
	  lfs       f2, -0x6454(r2)
	  lfd       f1, 0x160(r1)
	  lfs       f0, -0x640C(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x644C(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f30, f1, f0
	  fmr       f1, f30
	  bl        0x129C9C
	  lfs       f0, -0x6410(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x129E20
	  lfs       f0, -0x6410(r2)
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  fmuls     f0, f0, f1
	  li        r5, 0xCC
	  stfs      f0, 0x70(r29)
	  lfs       f0, -0x3270(r13)
	  stfs      f0, 0x74(r29)
	  stfs      f31, 0x78(r29)
	  bl        -0x6793C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r31, 0x3E0(r29)
	  addi      r4, r29, 0
	  li        r5, 0
	  lwz       r3, 0x2E8(r29)
	  bl        -0x747C4
	  b         .loc_0x2D0

	.loc_0x208:
	  lis       r3, 0x803D
	  lhz       r4, 0x428(r31)
	  addi      r3, r3, 0x1DF0
	  li        r5, 0
	  bl        -0x2C71C
	  lwz       r4, 0x42C(r31)
	  lis       r3, 0x803D
	  addi      r0, r3, 0x1EA0
	  addi      r3, r4, 0x1
	  stw       r3, 0x42C(r31)
	  lhz       r3, 0x428(r31)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x205FC
	  lis       r3, 0x803A
	  subi      r30, r3, 0x2848
	  lwz       r3, 0x1DC(r30)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2D0
	  lwz       r5, 0x2F6C(r13)
	  lbz       r0, 0x1B6(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x2D0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r29, r3, 0xA8
	  lwz       r4, 0xA8(r3)
	  addi      r3, r5, 0x54
	  lhz       r4, 0x26(r4)
	  addi      r4, r4, 0x15
	  bl        -0x6FAE8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2D0
	  lwz       r3, 0x0(r29)
	  lwz       r5, 0x2F6C(r13)
	  lhz       r4, 0x26(r3)
	  addi      r3, r5, 0x54
	  addi      r4, r4, 0x15
	  bl        -0x6F87C
	  lwz       r3, 0x1E8(r30)
	  li        r4, 0
	  li        r5, 0x15
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2D0:
	  lwz       r3, 0x2D0(r31)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2D0(r31)

	.loc_0x2DC:
	  lwz       r0, 0x2D0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x308
	  lwz       r0, 0x2D4(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x308
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x134(r12)
	  mtlr      r12
	  blrl

	.loc_0x308:
	  lwz       r0, 0x18C(r1)
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lwz       r31, 0x174(r1)
	  lwz       r30, 0x170(r1)
	  lwz       r29, 0x16C(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2048
 * Size:	000004
 */
void GoalAI::EmitWait::act(AICreature*) { }

/*
 * --INFO--
 * Address:	800F204C
 * Size:	000078
 */
void GoalAI::Effect::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r7, 0
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  addi      r5, r1, 0x10
	  lfs       f0, 0x94(r4)
	  li        r4, 0xE2
	  stfs      f0, 0x10(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x14(r1)
	  lfs       f1, 0x9C(r31)
	  lfs       f0, -0x6408(r2)
	  stfs      f1, 0x18(r1)
	  lfs       f1, 0x14(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r1)
	  lwz       r3, 0x3180(r13)
	  bl        0xAAA9C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xD6
	  bl        -0x67AF8
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001AC
 */
GemAI::GemAI()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800F20C4
 * Size:	0000C0
 */
void GemAI::RiseInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  addi      r4, r1, 0x10
	  lfs       f2, -0x6440(r2)
	  stfs      f2, 0x2D8(r31)
	  lfs       f0, -0x6434(r2)
	  stfs      f0, 0x2E0(r31)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x80
	  stw       r0, 0xC8(r31)
	  lfs       f1, 0x94(r31)
	  lfs       f0, -0x6454(r2)
	  stfs      f1, 0x3C(r1)
	  lfs       f1, 0x98(r31)
	  stfs      f1, 0x40(r1)
	  lfs       f1, 0x9C(r31)
	  stfs      f2, 0x18(r1)
	  stfs      f2, 0x14(r1)
	  stfs      f2, 0x10(r1)
	  stfs      f2, 0x24(r1)
	  stfs      f1, 0x44(r1)
	  stfs      f2, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  stfs      f2, 0x1C(r1)
	  lwz       r5, 0x40(r1)
	  stw       r0, 0x10(r1)
	  lwz       r0, 0x44(r1)
	  stw       r5, 0x14(r1)
	  stw       r0, 0x18(r1)
	  stfs      f0, 0x34(r1)
	  bl        0x22194
	  lwz       r4, 0x2C0(r31)
	  addi      r3, r31, 0
	  li        r5, 0xCB
	  bl        -0x67BA8
	  lfs       f0, -0x6440(r2)
	  li        r0, 0
	  stfs      f0, 0x74(r31)
	  stw       r0, 0x2D0(r31)
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2184
 * Size:	000178
 */
void GemAI::RiseExec::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r4
	  lfs       f0, -0x6440(r2)
	  lfs       f1, 0x2E0(r4)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x5C
	  lfs       f0, -0x326C(r13)
	  stfs      f0, 0x70(r31)
	  lfs       f0, -0x3268(r13)
	  stfs      f0, 0x74(r31)
	  lfs       f0, -0x3264(r13)
	  stfs      f0, 0x78(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x2E0(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2E0(r31)
	  b         .loc_0x15C

	.loc_0x5C:
	  lwz       r0, 0x2D0(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x70
	  li        r0, 0x1
	  stw       r0, 0x2D0(r31)

	.loc_0x70:
	  lwz       r3, 0x2C0(r31)
	  lfsu      f3, 0x94(r3)
	  lfs       f1, 0x94(r31)
	  lfs       f0, -0x6440(r2)
	  fsubs     f31, f3, f1
	  lfs       f2, 0x8(r3)
	  lfs       f1, 0x9C(r31)
	  fmuls     f0, f0, f0
	  fsubs     f30, f2, f1
	  fmuls     f1, f31, f31
	  fmuls     f2, f30, f30
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xE45E8
	  lfs       f0, -0x6440(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xBC
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1

	.loc_0xBC:
	  lfs       f1, -0x3260(r13)
	  fmuls     f0, f31, f1
	  fmuls     f1, f30, f1
	  stfs      f0, 0x70(r31)
	  stfs      f1, 0x78(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x74(r31)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x2D8(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x2D8(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x6404(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x74(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x74(r31)
	  lfs       f2, 0x2D8(r31)
	  lfs       f1, -0x6400(r2)
	  lfs       f0, -0x6454(r2)
	  fdivs     f1, f2, f1
	  fsubs     f2, f0, f1
	  fcmpo     cr0, f1, f0
	  stfs      f2, 0x7C(r31)
	  stfs      f2, 0x80(r31)
	  cror      2, 0x1, 0x2
	  stfs      f2, 0x84(r31)
	  bne-      .loc_0x15C
	  lwz       r3, 0x2E8(r31)
	  addi      r4, r31, 0
	  li        r5, 0x2
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x30FC(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x30FC(r13)

	.loc_0x15C:
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F22FC
 * Size:	000098
 */
void GemAI::Die::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  lwz       r4, 0x2C0(r4)
	  lwz       r0, 0x3E0(r31)
	  lhz       r3, 0x428(r4)
	  cmpw      r3, r0
	  bne-      .loc_0x30
	  lwz       r3, 0x3F8(r31)
	  b         .loc_0x34

	.loc_0x30:
	  lwz       r3, 0x3FC(r31)

	.loc_0x34:
	  li        r0, 0xA
	  stw       r0, 0x14(r1)
	  li        r0, 0
	  stw       r0, 0x18(r1)
	  lwz       r0, 0x2D0(r4)
	  add       r0, r0, r3
	  stw       r0, 0x2D0(r4)
	  lwz       r3, 0x2E8(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lwz       r12, 0x0(r3)
	  addi      r5, r1, 0x14
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl

	.loc_0x70:
	  li        r0, 0
	  stb       r0, 0x3E4(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x6769C
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2394
 * Size:	000254
 */
WaterAI::WaterAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r3
	  stw       r29, 0x1C(r1)
	  bl        -0x74ECC
	  lis       r3, 0x802C
	  subi      r0, r3, 0x2514
	  stw       r0, 0x0(r30)
	  li        r3, 0xC
	  bl        -0xAB3C0
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  lis       r4, 0x802B
	  subi      r0, r4, 0x2950
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2988
	  stw       r0, 0x0(r3)
	  li        r0, -0x1
	  lis       r4, 0x802B
	  stw       r0, 0x4(r3)
	  subi      r4, r4, 0x2C60
	  li        r0, 0
	  stw       r4, 0x0(r3)
	  stw       r0, 0x8(r3)

	.loc_0x70:
	  li        r0, 0x5
	  stw       r0, 0xC(r30)
	  li        r0, 0
	  addi      r31, r3, 0
	  stw       r0, 0x8(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAB41C
	  stw       r3, 0x4(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAB42C
	  stw       r3, 0x10(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAB43C
	  stw       r3, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x74EE8
	  addi      r3, r30, 0
	  li        r4, 0x1
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x74F04
	  addi      r3, r30, 0
	  li        r4, 0x2
	  li        r5, 0x3
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x74F20
	  addi      r3, r30, 0
	  li        r4, 0x3
	  li        r5, 0x2
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x74F3C
	  li        r3, 0x4
	  bl        -0xAB4B8
	  mr.       r6, r3
	  beq-      .loc_0x14C
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x25AC
	  stw       r0, 0x0(r3)

	.loc_0x14C:
	  addi      r3, r30, 0
	  li        r4, 0x4
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x74F7C
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r30, 0
	  li        r4, 0x3
	  li        r6, 0
	  bl        -0x74EA8
	  li        r3, 0x14
	  bl        -0xAB50C
	  mr.       r29, r3
	  beq-      .loc_0x1B0
	  lis       r3, 0x802C
	  subi      r4, r3, 0x26F4
	  addi      r3, r29, 0
	  bl        -0xBD570
	  lis       r3, 0x802B
	  subi      r0, r3, 0x26FC
	  lis       r3, 0x802C
	  stw       r0, 0x0(r29)
	  subi      r0, r3, 0x253C
	  stw       r0, 0x0(r29)

	.loc_0x1B0:
	  lwz       r5, 0x2F40(r13)
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r6, 0x1
	  bl        -0x74EF4
	  addi      r4, r29, 0
	  addi      r3, r3, 0x20
	  bl        -0xB1F88
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r30, 0
	  li        r4, 0
	  li        r6, 0
	  bl        -0x74F14
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  li        r4, 0
	  li        r6, 0x2
	  bl        -0x74F28
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r30, 0
	  li        r4, 0x1
	  li        r6, 0
	  bl        -0x74F3C
	  addi      r3, r30, 0
	  addi      r5, r31, 0
	  li        r4, 0x1
	  li        r6, 0x2
	  bl        -0x74F50
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r30, 0
	  li        r4, 0x2
	  li        r6, 0x4
	  bl        -0x74F64
	  mr        r3, r30
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F25E8
 * Size:	000040
 */
bool WaterAI::CollideChar::satisfy(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2BC(r4)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x36
	  bne-      .loc_0x2C
	  li        r3, 0x140
	  bl        -0x4D22C
	  li        r3, 0x1
	  b         .loc_0x30

	.loc_0x2C:
	  li        r3, 0

	.loc_0x30:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2628
 * Size:	000028
 */
void WaterAI::Die::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0
	  stwu      r1, -0x8(r1)
	  bl        -0x6795C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2650
 * Size:	0001D8
 */
FallWaterAI::FallWaterAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  bl        -0x75180
	  lis       r3, 0x802C
	  subi      r0, r3, 0x25E0
	  stw       r0, 0x0(r31)
	  li        r3, 0x5
	  li        r0, 0
	  stw       r3, 0xC(r31)
	  stw       r0, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAB688
	  stw       r3, 0x4(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAB698
	  stw       r3, 0x10(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xAB6A8
	  stw       r3, 0x14(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x75154
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        -0x75170
	  li        r3, 0x4
	  bl        -0xAB6EC
	  mr.       r6, r3
	  beq-      .loc_0xC4
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2640
	  stw       r0, 0x0(r3)

	.loc_0xC4:
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x751B0
	  li        r3, 0x4
	  bl        -0xAB72C
	  mr.       r6, r3
	  beq-      .loc_0x104
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x2674
	  stw       r0, 0x0(r3)

	.loc_0x104:
	  addi      r3, r31, 0
	  li        r4, 0x3
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x751F0
	  li        r3, 0x4
	  bl        -0xAB76C
	  mr.       r6, r3
	  beq-      .loc_0x144
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  subi      r0, r4, 0x26A4
	  stw       r0, 0x0(r3)

	.loc_0x144:
	  addi      r3, r31, 0
	  li        r4, 0x4
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x75230
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0
	  li        r6, 0x1
	  bl        -0x7515C
	  lwz       r5, 0x2F34(r13)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r6, 0x2
	  bl        -0x75170
	  lwz       r5, 0x2F44(r13)
	  addi      r3, r31, 0
	  li        r4, 0x1
	  li        r6, 0x2
	  bl        -0x75184
	  lwz       r5, 0x2F48(r13)
	  addi      r3, r31, 0
	  li        r4, 0x2
	  li        r6, 0x3
	  bl        -0x75198
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r31, 0
	  li        r4, 0x3
	  li        r6, 0x4
	  bl        -0x751AC
	  mr        r3, r31
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2828
 * Size:	000054
 */
void FallWaterAI::CollideInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lfs       f1, -0x63FC(r2)
	  lwz       r12, 0x138(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3038(r13)
	  addi      r6, r31, 0x94
	  li        r4, 0x1
	  li        r5, 0x8B
	  bl        -0x4E430
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F287C
 * Size:	000080
 */
void FallWaterAI::EmitInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  li        r4, 0x1
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x68
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  addi      r4, r30, 0x94
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x68:
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
 * Address:	800F28FC
 * Size:	000028
 */
void FallWaterAI::DisappearInit::act(AICreature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  li        r4, 0
	  stwu      r1, -0x8(r1)
	  bl        -0x67C30
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800F2924
 * Size:	000054
 */
bool CndBombable::satisfy(CollPart*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  beq-      .loc_0x40
	  addi      r3, r1, 0x10
	  bl        -0x6AA60
	  lis       r4, 0x2A2A
	  addi      r3, r1, 0x10
	  addi      r4, r4, 0x622A
	  li        r5, 0x2A
	  bl        -0xAEA68
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x40
	  li        r3, 0x1
	  b         .loc_0x44

	.loc_0x40:
	  li        r3, 0

	.loc_0x44:
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}
