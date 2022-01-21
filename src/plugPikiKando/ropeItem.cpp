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
 * Address:	800ED9DC
 * Size:	0000B0
 */
RopeItem::RopeItem(CreatureProp*, Shape*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  bl        -0x59354
	  lis       r3, 0x802C
	  subi      r0, r3, 0x2B14
	  lis       r3, 0x8009
	  stw       r0, 0x0(r30)
	  subi      r4, r3, 0x5808
	  addi      r3, r30, 0x2D4
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x3
	  bl        0x127050
	  stw       r31, 0x2F8(r30)
	  li        r0, 0x4
	  addi      r3, r30, 0x1B8
	  stw       r0, 0x68(r30)
	  addi      r4, r30, 0x2D4
	  li        r5, 0x3
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,23,21
	  stw       r0, 0xC8(r30)
	  lwz       r0, 0xC8(r30)
	  ori       r0, r0, 0x1
	  stw       r0, 0xC8(r30)
	  bl        -0x9DD4
	  li        r0, 0x12
	  stw       r0, 0x6C(r30)
	  li        r0, 0
	  addi      r3, r30, 0
	  lfs       f0, -0x64D8(r2)
	  stfs      f0, 0x270(r30)
	  stw       r0, 0x2FC(r30)
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
 * Address:	800EDA8C
 * Size:	000008
 */
u32 RopeItem::isAtari() { return 0x0; }

/*
 * --INFO--
 * Address:	800EDA94
 * Size:	000008
 */
void RopeItem::getSize()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x64D8(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EDA9C
 * Size:	00004C
 */
void RopeItem::init(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lfs       f0, -0x64D4(r2)
	  stfs      f0, 0x7C(r3)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  bl        -0x62EBC
	  addi      r3, r31, 0x1B8
	  addi      r4, r31, 0x2D4
	  li        r5, 0x3
	  bl        -0x9E50
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EDAE8
 * Size:	000290
 */
void RopeItem::autoInit()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stmw      r27, 0x2C(r1)
	  mr        r30, r3
	  lwz       r0, 0x2D0(r3)
	  lwz       r31, 0x30AC(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x148
	  mr        r3, r31
	  lfs       f31, -0x64D0(r2)
	  lwz       r12, 0x0(r31)
	  li        r27, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0xD4

	.loc_0x4C:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x74
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x90

	.loc_0x74:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x90:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x60D04
	  lwz       r0, 0x6C(r29)
	  cmpwi     r0, 0x11
	  bne-      .loc_0xB8
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0xB8
	  mr        r27, r29
	  fmr       f31, f1

	.loc_0xB8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0xD4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xFC
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0xFC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x124
	  li        r0, 0x1
	  b         .loc_0x128

	.loc_0x124:
	  li        r0, 0

	.loc_0x128:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x4C
	  cmplwi    r27, 0
	  beq-      .loc_0x278
	  addi      r3, r30, 0
	  addi      r4, r27, 0
	  bl        -0x5952C
	  b         .loc_0x278

	.loc_0x148:
	  mr        r3, r31
	  lfs       f31, -0x64D0(r2)
	  lwz       r12, 0x0(r31)
	  li        r27, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3
	  b         .loc_0x208

	.loc_0x16C:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x194
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x1B0

	.loc_0x194:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x1B0:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x60E24
	  lwz       r0, 0x6C(r29)
	  cmpwi     r0, 0x12
	  bne-      .loc_0x1EC
	  lwz       r3, 0x2D0(r30)
	  lwz       r0, 0x2D0(r29)
	  subi      r3, r3, 0x1
	  cmpw      r3, r0
	  bne-      .loc_0x1EC
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x1EC
	  mr        r27, r29
	  fmr       f31, f1

	.loc_0x1EC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x208:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x230
	  li        r0, 0x1
	  b         .loc_0x25C

	.loc_0x230:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x258
	  li        r0, 0x1
	  b         .loc_0x25C

	.loc_0x258:
	  li        r0, 0

	.loc_0x25C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x16C
	  cmplwi    r27, 0
	  beq-      .loc_0x278
	  addi      r3, r30, 0
	  addi      r4, r27, 0
	  bl        -0x59660

	.loc_0x278:
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
 * Address:	800EDD78
 * Size:	000004
 */
void RopeItem::startAI(int) { }

/*
 * --INFO--
 * Address:	800EDD7C
 * Size:	000034
 */
void RopeItem::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x7C(r12)
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
 * Address:	800EDDB0
 * Size:	000008
 */
void RopeItem::getiMass()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x64CC(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EDDB8
 * Size:	000008
 */
u32 RopeItem::needShadow() { return 0x0; }

/*
 * --INFO--
 * Address:	800EDDC0
 * Size:	000008
 */
u32 RopeItem::isAlive() { return 0x1; }

/*
 * --INFO--
 * Address:	800EDDC8
 * Size:	000008
 */
u32 RopeItem::isVisible() { return 0x1; }
