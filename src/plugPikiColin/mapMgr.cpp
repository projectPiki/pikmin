#include "DynObject.h"
#include "DynColl.h"
#include "MapMgr.h"
#include "Creature.h"
#include "PikiMacros.h"

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
 * Address:	800617C0
 * Size:	000268
 */
void DynCollShape::createDupCollData()
{
	// just here to check DynCollShape ctor compiles, remove later
	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  lwz       r3, 0x2C(r3)
	  lwz       r29, 0x238(r3)
	  mulli     r3, r29, 0xC
	  addi      r3, r3, 0x8
	  bl        -0x1A7EC
	  lis       r4, 0x8003
	  addi      r4, r4, 0x5B24
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0xC
	  bl        0x1B3420
	  stw       r3, 0x30(r31)
	  lwz       r4, 0x2C(r31)
	  lwz       r3, 0x30(r31)
	  lwz       r0, 0x238(r4)
	  lwz       r4, 0x23C(r4)
	  mulli     r5, r0, 0xC
	  bl        -0x5E410
	  lwz       r3, 0x2C(r31)
	  lwz       r29, 0x168(r3)
	  mulli     r3, r29, 0x58
	  addi      r3, r3, 0x8
	  bl        -0x1A834
	  lis       r4, 0x8003
	  subi      r4, r4, 0x7DEC
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0x58
	  bl        0x1B33D8
	  stw       r3, 0x34(r31)
	  lwz       r4, 0x2C(r31)
	  lwz       r3, 0x34(r31)
	  lwz       r0, 0x168(r4)
	  lwz       r4, 0x16C(r4)
	  mulli     r5, r0, 0x58
	  bl        -0x5E458
	  li        r29, 0
	  stw       r29, 0x40(r31)
	  lwz       r3, 0x2C(r31)
	  lwz       r3, 0x58(r3)
	  bl        -0x1A87C
	  stw       r3, 0x38(r31)
	  li        r5, 0
	  b         .loc_0xF8

	.loc_0xD0:
	  lwz       r4, 0x5C(r3)
	  addi      r0, r29, 0x20
	  lwz       r3, 0x38(r31)
	  addi      r29, r29, 0x11C
	  lwzx      r0, r4, r0
	  neg       r4, r0
	  subic     r0, r4, 0x1
	  subfe     r0, r0, r4
	  stbx      r0, r3, r5
	  addi      r5, r5, 0x1

	.loc_0xF8:
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x58(r3)
	  cmpw      r5, r0
	  blt+      .loc_0xD0
	  lwz       r0, 0x170(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x248
	  stw       r0, 0x3C(r31)
	  lwz       r0, 0x3C(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1A8DC
	  stw       r3, 0x40(r31)
	  li        r29, 0
	  li        r30, 0
	  b         .loc_0x238

	.loc_0x134:
	  lwz       r0, 0x168(r3)
	  li        r28, 0
	  li        r4, 0
	  cmpwi     r0, 0
	  mtctr     r0
	  ble-      .loc_0x16C

	.loc_0x14C:
	  lwz       r3, 0x34(r31)
	  addi      r0, r4, 0x10
	  lhax      r0, r3, r0
	  cmpw      r29, r0
	  bne-      .loc_0x164
	  addi      r28, r28, 0x1

	.loc_0x164:
	  addi      r4, r4, 0x58
	  bdnz+     .loc_0x14C

	.loc_0x16C:
	  li        r3, 0x24
	  bl        -0x1A92C
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  sth       r0, 0x4(r3)
	  stw       r0, 0x18(r3)
	  stw       r0, 0xC(r3)

	.loc_0x190:
	  lwz       r4, 0x40(r31)
	  extsh     r0, r28
	  stwx      r3, r4, r30
	  lwz       r4, 0x2C(r31)
	  lwz       r3, 0x40(r31)
	  lwz       r4, 0x174(r4)
	  lwzx      r3, r3, r30
	  lwzx      r4, r4, r30
	  stw       r4, 0x18(r3)
	  lwz       r3, 0x40(r31)
	  lwzx      r3, r3, r30
	  sth       r0, 0x4(r3)
	  lwz       r3, 0x40(r31)
	  lwzx      r3, r3, r30
	  lha       r0, 0x4(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x1A98C
	  lwz       r4, 0x40(r31)
	  li        r5, 0
	  addi      r6, r5, 0
	  lwzx      r4, r4, r30
	  li        r7, 0
	  stw       r3, 0x8(r4)
	  b         .loc_0x220

	.loc_0x1F0:
	  lwz       r0, 0x34(r31)
	  add       r4, r0, r5
	  lha       r0, 0x10(r4)
	  cmpw      r29, r0
	  bne-      .loc_0x218
	  lwz       r0, 0x40(r31)
	  lwzx      r3, r30, r0
	  lwz       r3, 0x8(r3)
	  stwx      r4, r3, r6
	  addi      r6, r6, 0x4

	.loc_0x218:
	  addi      r5, r5, 0x58
	  addi      r7, r7, 0x1

	.loc_0x220:
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x168(r3)
	  cmpw      r7, r0
	  blt+      .loc_0x1F0
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x1

	.loc_0x238:
	  lwz       r3, 0x2C(r31)
	  lwz       r0, 0x170(r3)
	  cmpw      r29, r0
	  blt+      .loc_0x134

	.loc_0x248:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001FC
 */
void DynCollShape::drawAtari(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80061A28
 * Size:	0003CC
 */
void DynCollShape::updatePos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stmw      r25, 0x34(r1)
	  addi      r26, r3, 0
	  lfs       f0, -0x6D18(r13)
	  stfs      f0, 0x44(r3)
	  lfs       f0, -0x6D14(r13)
	  stfs      f0, 0x48(r3)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0x4C(r3)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0x50(r3)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0x54(r3)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0x58(r3)
	  b         .loc_0x1B8

	.loc_0x54:
	  lwz       r4, 0x23C(r3)
	  addi      r3, r5, 0x4
	  lfs       f3, 0x5C(r26)
	  addi      r0, r5, 0x8
	  add       r4, r4, r5
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x60(r26)
	  lfs       f0, 0x4(r4)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x64(r26)
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r4)
	  lfs       f4, 0x68(r26)
	  fmuls     f1, f3, f1
	  lwz       r4, 0x30(r26)
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fadds     f0, f4, f0
	  stfsx     f0, r4, r5
	  lwz       r4, 0x2C(r26)
	  lfs       f3, 0x6C(r26)
	  lwz       r4, 0x23C(r4)
	  lfs       f1, 0x70(r26)
	  add       r4, r4, r5
	  lfs       f5, 0x74(r26)
	  lfs       f2, 0x0(r4)
	  lfs       f0, 0x4(r4)
	  lfs       f4, 0x8(r4)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  lfs       f3, 0x78(r26)
	  fmuls     f1, f5, f4
	  lwz       r4, 0x30(r26)
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fadds     f0, f3, f0
	  stfsx     f0, r4, r3
	  lwz       r3, 0x2C(r26)
	  lfs       f3, 0x7C(r26)
	  lwz       r3, 0x23C(r3)
	  lfs       f1, 0x80(r26)
	  add       r3, r3, r5
	  lfs       f5, 0x84(r26)
	  lfs       f2, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  lfs       f4, 0x8(r3)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  lfs       f3, 0x88(r26)
	  fmuls     f1, f5, f4
	  lwz       r3, 0x30(r26)
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  fadds     f0, f3, f0
	  stfsx     f0, r3, r0
	  lwz       r0, 0x30(r26)
	  lfs       f0, 0x44(r26)
	  add       r3, r0, r5
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x14C
	  stfs      f1, 0x44(r26)

	.loc_0x14C:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x48(r26)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x160
	  stfs      f1, 0x48(r26)

	.loc_0x160:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x4C(r26)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x174
	  stfs      f1, 0x4C(r26)

	.loc_0x174:
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x50(r26)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x188
	  stfs      f1, 0x50(r26)

	.loc_0x188:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x54(r26)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x19C
	  stfs      f1, 0x54(r26)

	.loc_0x19C:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x58(r26)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1B0
	  stfs      f1, 0x58(r26)

	.loc_0x1B0:
	  addi      r5, r5, 0xC
	  addi      r6, r6, 0x1

	.loc_0x1B8:
	  lwz       r3, 0x2C(r26)
	  lwz       r0, 0x238(r3)
	  cmpw      r6, r0
	  blt+      .loc_0x54
	  li        r28, 0
	  lfs       f31, -0x78B0(r2)
	  mulli     r29, r28, 0x58
	  b         .loc_0x3A4

	.loc_0x1D8:
	  lwz       r4, 0x16C(r3)
	  addi      r3, r29, 0x18
	  lwz       r0, 0x34(r26)
	  addi      r5, r29, 0x18
	  add       r3, r4, r3
	  addi      r4, r26, 0x5C
	  add       r5, r0, r5
	  bl        -0x2A564
	  lwz       r0, 0x34(r26)
	  addi      r25, r29, 0x18
	  add       r25, r0, r25
	  lfs       f1, 0x0(r25)
	  lfs       f0, 0x4(r25)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r25)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x5400C
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x254
	  lfs       f0, 0x0(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r25)
	  lfs       f0, 0x4(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r25)
	  lfs       f0, 0x8(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r25)

	.loc_0x254:
	  lwz       r0, 0x34(r26)
	  li        r27, 0
	  lwz       r3, 0x30(r26)
	  rlwinm    r31,r27,4,0,27
	  add       r5, r0, r29
	  lwz       r0, 0x4(r5)
	  li        r30, 0
	  lfs       f3, 0x18(r5)
	  mulli     r0, r0, 0xC
	  lfs       f1, 0x1C(r5)
	  lfs       f4, 0x20(r5)
	  add       r3, r3, r0
	  lfs       f2, 0x0(r3)
	  lfs       f0, 0x4(r3)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x8(r3)
	  fmuls     f0, f1, f0
	  fmuls     f1, f4, f3
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x24(r5)

	.loc_0x2A8:
	  lwz       r3, 0x2C(r26)
	  add       r25, r29, r31
	  lwz       r0, 0x34(r26)
	  addi      r5, r25, 0x28
	  lwz       r4, 0x16C(r3)
	  addi      r3, r25, 0x28
	  add       r3, r4, r3
	  addi      r4, r26, 0x5C
	  add       r5, r0, r5
	  bl        -0x2A63C
	  lwz       r0, 0x34(r26)
	  addi      r25, r25, 0x28
	  add       r25, r0, r25
	  lfs       f1, 0x0(r25)
	  lfs       f0, 0x4(r25)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r25)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x540E4
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x32C
	  lfs       f0, 0x0(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r25)
	  lfs       f0, 0x4(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r25)
	  lfs       f0, 0x8(r25)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r25)

	.loc_0x32C:
	  lwz       r5, 0x34(r26)
	  addi      r0, r30, 0x4
	  add       r3, r29, r31
	  lwz       r4, 0x30(r26)
	  add       r6, r29, r5
	  lwzx      r0, r6, r0
	  addi      r3, r3, 0x28
	  add       r3, r5, r3
	  mulli     r0, r0, 0xC
	  lfs       f3, 0x0(r3)
	  lfs       f1, 0x4(r3)
	  lfs       f4, 0x8(r3)
	  add       r3, r4, r0
	  lfs       f2, 0x0(r3)
	  addi      r27, r27, 0x1
	  lfs       f0, 0x4(r3)
	  addi      r0, r31, 0x34
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  lfs       f1, 0x8(r3)
	  cmpwi     r27, 0x3
	  fmuls     f1, f4, f1
	  fadds     f0, f2, f0
	  addi      r31, r31, 0x10
	  addi      r30, r30, 0x4
	  fadds     f0, f1, f0
	  stfsx     f0, r6, r0
	  blt+      .loc_0x2A8
	  addi      r29, r29, 0x58
	  addi      r28, r28, 0x1

	.loc_0x3A4:
	  lwz       r3, 0x2C(r26)
	  lwz       r0, 0x168(r3)
	  cmpw      r28, r0
	  blt+      .loc_0x1D8
	  lmw       r25, 0x34(r1)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80061DF4
 * Size:	000044
 */
void DynCollShape::jointVisible(int, int)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x2C(r3)
	  mulli     r0, r4, 0x11C
	  lwz       r4, 0x5C(r6)
	  neg       r6, r5
	  add       r4, r4, r0
	  lwz       r4, 0x8(r4)
	  lwz       r7, 0x10(r4)
	  b         .loc_0x38

	.loc_0x20:
	  subic     r5, r6, 0x1
	  lwz       r4, 0x38(r3)
	  lwz       r0, 0x14(r7)
	  subfe     r5, r5, r6
	  stbx      r5, r4, r0
	  lwz       r7, 0xC(r7)

	.loc_0x38:
	  cmplwi    r7, 0
	  bne+      .loc_0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80061E38
 * Size:	000094
 */
void DynCollShape::adjust(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  addi      r3, r31, 0x274
	  lwz       r5, 0x94(r4)
	  lwz       r0, 0x98(r4)
	  addi      r4, r30, 0x9C
	  stw       r5, 0x274(r31)
	  stw       r0, 0x278(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x27C(r31)
	  bl        -0x2A728
	  lwz       r5, 0x274(r31)
	  addi      r3, r31, 0x94
	  lwz       r0, 0x278(r31)
	  addi      r4, r30, 0x5C
	  stw       r5, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x27C(r31)
	  stw       r0, 0x9C(r31)
	  bl        -0x2A74C
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1AC(r31)
	  stw       r0, 0x1B0(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1B4(r31)
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
 * Address:	80061ECC
 * Size:	000048
 */
void DynCollShape::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r31, 0x5C
	  addi      r4, r31, 0x9C
	  bl        -0x23AAC
	  addi      r3, r31, 0x5C
	  addi      r4, r31, 0x11C
	  addi      r5, r31, 0x128
	  addi      r6, r31, 0x134
	  bl        -0x23E08
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80061F14
 * Size:	00003C
 */
void DynCollShape::updateContext()
{
	/*
	.loc_0x0:
	  li        r7, 0
	  li        r6, 0
	  b         .loc_0x28

	.loc_0xC:
	  lwz       r5, 0x38(r3)
	  addi      r0, r6, 0x20
	  lwz       r4, 0x5C(r4)
	  addi      r6, r6, 0x11C
	  lbzx      r5, r5, r7
	  addi      r7, r7, 0x1
	  stwx      r5, r4, r0

	.loc_0x28:
	  lwz       r4, 0x2C(r3)
	  lwz       r0, 0x58(r4)
	  cmpw      r7, r0
	  blt+      .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80061F50
 * Size:	000064
 */
void DynCollShape::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r7, 0
	  stw       r0, 0x4(r1)
	  addi      r8, r7, 0
	  stwu      r1, -0x8(r1)
	  b         .loc_0x34

	.loc_0x18:
	  lwz       r6, 0x38(r3)
	  addi      r0, r8, 0x20
	  lwz       r5, 0x5C(r9)
	  addi      r8, r8, 0x11C
	  lbzx      r6, r6, r7
	  addi      r7, r7, 0x1
	  stwx      r6, r5, r0

	.loc_0x34:
	  lwz       r9, 0x2C(r3)
	  lwz       r0, 0x58(r9)
	  cmpw      r7, r0
	  blt+      .loc_0x18
	  lwz       r5, 0x2E4(r4)
	  addi      r3, r9, 0
	  li        r6, 0
	  bl        -0x31B34
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80061FB4
 * Size:	000034
 */
void MapObjAnimator::finishOneShot()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x18(r3)
	  lwz       r3, 0x34(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x24
	  bl        0x1D0

	.loc_0x24:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000364
 */
DynMapObject::DynMapObject(MapMgr*, MapAnimShapeObject* obj)
    : DynCollShape(obj)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80061FE8
 * Size:	0001BC
 */
DynCollShape::DynCollShape(Shape* shape)
{
	mShape = shape;
	if (mShape) {
		createDupCollData();
	}

	_11C = Vector3f(1.0f, 1.0f, 1.0f);
	_134 = Vector3f(0.0f, 0.0f, 0.0f);
	_128 = _134;
	_5C.makeIdentity();
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r5, 0x738C
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x8022
	  stw       r30, 0x38(r1)
	  li        r30, 0
	  stw       r29, 0x34(r1)
	  addi      r29, r4, 0
	  subi      r4, r13, 0x6CD0
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x737C
	  addi      r3, r31, 0
	  stw       r0, 0x0(r31)
	  stw       r30, 0x10(r31)
	  stw       r30, 0xC(r31)
	  stw       r30, 0x8(r31)
	  bl        -0x3D164
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r31)
	  addi      r3, r31, 0
	  subi      r4, r13, 0x6CD0
	  bl        -0x21914
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C4C
	  stw       r0, 0x0(r31)
	  lis       r3, 0x802B
	  li        r4, -0x1
	  stw       r30, 0x20(r31)
	  subi      r0, r3, 0x6BCC
	  stw       r4, 0x24(r31)
	  stw       r30, 0x28(r31)
	  stw       r0, 0x0(r31)
	  lfs       f1, -0x78B0(r2)
	  stfs      f1, 0x4C(r31)
	  stfs      f1, 0x48(r31)
	  stfs      f1, 0x44(r31)
	  stfs      f1, 0x58(r31)
	  stfs      f1, 0x54(r31)
	  stfs      f1, 0x50(r31)
	  lfs       f0, -0x6D18(r13)
	  stfs      f0, 0x44(r31)
	  lfs       f0, -0x6D14(r13)
	  stfs      f0, 0x48(r31)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0x4C(r31)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0x50(r31)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0x54(r31)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0x58(r31)
	  stfs      f1, 0x124(r31)
	  stfs      f1, 0x120(r31)
	  stfs      f1, 0x11C(r31)
	  stfs      f1, 0x130(r31)
	  stfs      f1, 0x12C(r31)
	  stfs      f1, 0x128(r31)
	  stfs      f1, 0x13C(r31)
	  stfs      f1, 0x138(r31)
	  stfs      f1, 0x134(r31)
	  stw       r29, 0x2C(r31)
	  lwz       r0, 0x2C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x11C
	  mr        r3, r31
	  bl        -0x940

	.loc_0x11C:
	  lfs       f0, -0x6D00(r13)
	  addi      r3, r31, 0x5C
	  lfs       f1, -0x6CFC(r13)
	  stfs      f0, 0x24(r1)
	  lfs       f0, -0x6CF8(r13)
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  lwz       r4, 0x24(r1)
	  lwz       r0, 0x28(r1)
	  stw       r4, 0x11C(r31)
	  stw       r0, 0x120(r31)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x124(r31)
	  lfs       f0, -0x6CF4(r13)
	  lfs       f1, -0x6CF0(r13)
	  stfs      f0, 0x18(r1)
	  lfs       f0, -0x6CEC(r13)
	  stfs      f1, 0x1C(r1)
	  stfs      f0, 0x20(r1)
	  lwz       r4, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stw       r4, 0x134(r31)
	  stw       r0, 0x138(r31)
	  lwz       r0, 0x20(r1)
	  stw       r0, 0x13C(r31)
	  lwz       r4, 0x134(r31)
	  lwz       r0, 0x138(r31)
	  stw       r4, 0x128(r31)
	  stw       r0, 0x12C(r31)
	  lwz       r0, 0x13C(r31)
	  stw       r0, 0x130(r31)
	  bl        -0x243C4
	  mr        r3, r31
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800621A4
 * Size:	000024
 */
void DynMapObject::nextState()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x518(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x518(r3)
	  lwz       r0, 0x518(r3)
	  cmpwi     r0, 0x6
	  bnelr-
	  li        r0, 0
	  stw       r0, 0x518(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800621C8
 * Size:	00003C
 */
void DynMapObject::touchCallback(Plane&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x518(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x30
	  bgelr-
	  cmpwi     r0, 0
	  bnelr-
	  lfs       f0, -0x7894(r2)
	  stfs      f0, 0x51C(r3)
	  lwz       r4, 0x518(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x518(r3)
	  blr

	.loc_0x30:
	  lfs       f0, -0x7894(r2)
	  stfs      f0, 0x51C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80062204
 * Size:	0001A8
 */
void DynMapObject::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r0, 0x518(r3)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x90
	  bge-      .loc_0x30
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3C
	  b         .loc_0x114

	.loc_0x30:
	  cmpwi     r0, 0x5
	  bge-      .loc_0x114
	  b         .loc_0xC8

	.loc_0x3C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x51C(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x51C(r31)
	  lfs       f1, 0x51C(r31)
	  lfs       f0, -0x78B0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x114
	  lfs       f0, -0x7894(r2)
	  addi      r3, r31, 0x144
	  li        r4, 0x2
	  stfs      f0, 0x51C(r31)
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x8
	  bl        -0x11310
	  lwz       r3, 0x518(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x518(r31)
	  b         .loc_0x114

	.loc_0x90:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x51C(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x51C(r31)
	  lfs       f1, 0x51C(r31)
	  lfs       f0, -0x78B0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x114
	  stfs      f0, 0x51C(r31)
	  lwz       r3, 0x518(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x518(r31)
	  b         .loc_0x114

	.loc_0xC8:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x51C(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x51C(r31)
	  lfs       f1, 0x51C(r31)
	  lfs       f0, -0x78B0(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x114
	  stfs      f0, 0x51C(r31)
	  addi      r3, r31, 0x144
	  li        r4, 0x2
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0x8
	  bl        -0x11398
	  lwz       r3, 0x518(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x518(r31)

	.loc_0x114:
	  lfs       f2, -0x788C(r2)
	  addi      r3, r31, 0x144
	  lfs       f0, 0x538(r31)
	  lfs       f4, -0x7890(r2)
	  lfs       f1, 0x53C(r31)
	  fadds     f0, f2, f0
	  lfs       f3, 0x540(r31)
	  fadds     f1, f4, f1
	  stfs      f0, 0x4FC(r31)
	  fadds     f0, f4, f3
	  stfs      f1, 0x500(r31)
	  stfs      f0, 0x504(r31)
	  lfs       f1, 0x53C(r31)
	  lfs       f0, 0x538(r31)
	  fadds     f1, f2, f1
	  stfs      f0, 0x508(r31)
	  stfs      f1, 0x50C(r31)
	  lfs       f0, 0x540(r31)
	  stfs      f0, 0x510(r31)
	  lwz       r12, 0x174(r31)
	  lfs       f1, -0x7888(r2)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r31, 0x5C
	  addi      r4, r31, 0x9C
	  bl        -0x23F44
	  addi      r3, r31, 0x5C
	  addi      r4, r31, 0x11C
	  addi      r5, r31, 0x128
	  addi      r6, r31, 0x134
	  bl        -0x242A0
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800623AC
 * Size:	00002C
 */
void DynMapObject::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x44(r12)
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
 * Address:	800623D8
 * Size:	000184
 */
void DynMapObject::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stmw      r27, 0xD4(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  addi      r3, r1, 0x90
	  addi      r4, r28, 0x520
	  addi      r5, r28, 0x52C
	  addi      r6, r28, 0x538
	  bl        -0x2430C
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r1, 0x90
	  addi      r5, r1, 0x50
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r28, 0x144
	  bl        -0x11264
	  lwz       r3, 0x140(r28)
	  addi      r4, r29, 0
	  addi      r5, r1, 0x50
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x2D128
	  li        r30, 0
	  li        r31, 0
	  b         .loc_0x130

	.loc_0x74:
	  lwz       r3, 0x548(r28)
	  lwzx      r27, r3, r31
	  addi      r3, r27, 0x5C
	  addi      r4, r27, 0x9C
	  bl        -0x24020
	  lwz       r3, 0x2C(r28)
	  lwz       r4, 0x140(r27)
	  bl        -0x2D480
	  lwz       r6, 0x0(r3)
	  addi      r4, r1, 0x10
	  lwz       r0, 0x4(r3)
	  addi      r5, r27, 0x5C
	  stw       r6, 0x10(r1)
	  stw       r0, 0x14(r1)
	  lwz       r6, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  stw       r6, 0x18(r1)
	  stw       r0, 0x1C(r1)
	  lwz       r6, 0x10(r3)
	  lwz       r0, 0x14(r3)
	  stw       r6, 0x20(r1)
	  stw       r0, 0x24(r1)
	  lwz       r6, 0x18(r3)
	  lwz       r0, 0x1C(r3)
	  stw       r6, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  lwz       r6, 0x20(r3)
	  lwz       r0, 0x24(r3)
	  stw       r6, 0x30(r1)
	  stw       r0, 0x34(r1)
	  lwz       r6, 0x28(r3)
	  lwz       r0, 0x2C(r3)
	  stw       r6, 0x38(r1)
	  stw       r0, 0x3C(r1)
	  lwz       r6, 0x30(r3)
	  lwz       r0, 0x34(r3)
	  stw       r6, 0x40(r1)
	  stw       r0, 0x44(r1)
	  lwz       r6, 0x38(r3)
	  lwz       r0, 0x3C(r3)
	  stw       r6, 0x48(r1)
	  stw       r0, 0x4C(r1)
	  lwz       r3, 0x2E4(r29)
	  addi      r3, r3, 0x220
	  bl        -0x24428
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x130:
	  lwz       r0, 0x544(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x74
	  lwz       r12, 0x3B4(r29)
	  lis       r4, 0x803A
	  mr        r3, r29
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r28)
	  mr        r4, r29
	  lwz       r5, 0x2E4(r29)
	  li        r6, 0
	  bl        -0x320D8
	  lmw       r27, 0xD4(r1)
	  lwz       r0, 0xEC(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006255C
 * Size:	000030
 */
void DynCollObjBody::touchCallback(Plane&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x140(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x70(r12)
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
 * Address:	8006258C
 * Size:	000030
 */
void DynCollObjBody::applyVelocity(Plane&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x140(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
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
 * Address:	800625BC
 * Size:	0001B8
 */
void DynObjBody::touchCallback(Plane&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  stfd      f30, 0xC8(r1)
	  stfd      f29, 0xC0(r1)
	  stw       r31, 0xBC(r1)
	  stw       r30, 0xB8(r1)
	  mr        r30, r5
	  stw       r29, 0xB4(r1)
	  mr        r29, r3
	  lfs       f3, 0x0(r4)
	  lfs       f2, 0x0(r6)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x4(r6)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x8(r4)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x8(r6)
	  lfs       f0, -0x78B0(r2)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x190
	  fmuls     f0, f4, f1
	  addi      r0, r1, 0x48
	  addi      r6, r1, 0x50
	  addi      r5, r1, 0x4C
	  stfs      f0, 0x50(r1)
	  addi      r3, r1, 0x94
	  lfs       f0, 0x4(r4)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x0(r4)
	  mr        r4, r0
	  fmuls     f0, f0, f1
	  stfs      f0, 0x48(r1)
	  bl        -0x2B538
	  lfs       f1, 0x8(r30)
	  addis     r31, r29, 0x1
	  lfs       f0, 0x4154(r29)
	  addi      r6, r1, 0x44
	  lfs       f2, 0x0(r30)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x3318(r31)
	  lfs       f3, 0x4(r30)
	  addi      r5, r1, 0x40
	  lfs       f31, 0x94(r1)
	  stfs      f0, 0x44(r1)
	  fmuls     f31, f31, f1
	  lfs       f30, 0x98(r1)
	  addi      r4, r1, 0x3C
	  lfs       f0, 0x4150(r29)
	  lfs       f29, 0x9C(r1)
	  fsubs     f0, f3, f0
	  addi      r3, r1, 0x6C
	  fmuls     f30, f30, f1
	  fmuls     f29, f29, f1
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x414C(r29)
	  fsubs     f0, f2, f0
	  stfs      f0, 0x3C(r1)
	  bl        -0x2B59C
	  lfs       f0, 0x5C(r29)
	  lfs       f6, 0x6C(r1)
	  fmuls     f1, f31, f0
	  lfs       f7, 0x70(r1)
	  lfs       f2, -0x5DD0(r31)
	  fmuls     f0, f6, f29
	  lfs       f3, 0x74(r1)
	  fadds     f2, f2, f1
	  fmuls     f1, f3, f31
	  fmuls     f4, f7, f29
	  stfs      f2, -0x5DD0(r31)
	  fmuls     f3, f3, f30
	  fsubs     f2, f1, f0
	  lfs       f0, 0x5C(r29)
	  lfs       f5, -0x5DCC(r31)
	  fsubs     f3, f4, f3
	  fmuls     f4, f30, f0
	  fmuls     f1, f6, f30
	  fmuls     f0, f7, f31
	  fadds     f4, f5, f4
	  fsubs     f0, f1, f0
	  stfs      f4, -0x5DCC(r31)
	  lfs       f1, 0x5C(r29)
	  lfs       f4, -0x5DC8(r31)
	  fmuls     f1, f29, f1
	  fadds     f1, f4, f1
	  stfs      f1, -0x5DC8(r31)
	  lfs       f1, -0x5DC4(r31)
	  fadds     f1, f1, f3
	  stfs      f1, -0x5DC4(r31)
	  lfs       f1, -0x5DC0(r31)
	  fadds     f1, f1, f2
	  stfs      f1, -0x5DC0(r31)
	  lfs       f1, -0x5DBC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, -0x5DBC(r31)

	.loc_0x190:
	  lwz       r0, 0xDC(r1)
	  lfd       f31, 0xD0(r1)
	  lfd       f30, 0xC8(r1)
	  lfd       f29, 0xC0(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80062774
 * Size:	0001B8
 */
void DynObjBody::applyVelocity(Plane&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  stfd      f30, 0xC8(r1)
	  stfd      f29, 0xC0(r1)
	  stw       r31, 0xBC(r1)
	  stw       r30, 0xB8(r1)
	  mr        r30, r5
	  stw       r29, 0xB4(r1)
	  mr        r29, r3
	  lfs       f3, 0x0(r4)
	  lfs       f2, 0x0(r6)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x4(r6)
	  fmuls     f2, f3, f2
	  lfs       f4, 0x8(r4)
	  fmuls     f1, f1, f0
	  lfs       f3, 0x8(r6)
	  lfs       f0, -0x78B0(r2)
	  fmuls     f3, f4, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x190
	  fmuls     f0, f4, f1
	  addi      r0, r1, 0x48
	  addi      r6, r1, 0x50
	  addi      r5, r1, 0x4C
	  stfs      f0, 0x50(r1)
	  addi      r3, r1, 0x94
	  lfs       f0, 0x4(r4)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x0(r4)
	  mr        r4, r0
	  fmuls     f0, f0, f1
	  stfs      f0, 0x48(r1)
	  bl        -0x2B6F0
	  lfs       f1, 0x8(r30)
	  addis     r31, r29, 0x1
	  lfs       f0, 0x4154(r29)
	  addi      r6, r1, 0x44
	  lfs       f2, 0x0(r30)
	  fsubs     f0, f1, f0
	  lfs       f1, 0x3318(r31)
	  lfs       f3, 0x4(r30)
	  addi      r5, r1, 0x40
	  lfs       f31, 0x94(r1)
	  stfs      f0, 0x44(r1)
	  fmuls     f31, f31, f1
	  lfs       f30, 0x98(r1)
	  addi      r4, r1, 0x3C
	  lfs       f0, 0x4150(r29)
	  lfs       f29, 0x9C(r1)
	  fsubs     f0, f3, f0
	  addi      r3, r1, 0x6C
	  fmuls     f30, f30, f1
	  fmuls     f29, f29, f1
	  stfs      f0, 0x40(r1)
	  lfs       f0, 0x414C(r29)
	  fsubs     f0, f2, f0
	  stfs      f0, 0x3C(r1)
	  bl        -0x2B754
	  lfs       f0, 0x5C(r29)
	  lfs       f6, 0x6C(r1)
	  fmuls     f1, f31, f0
	  lfs       f7, 0x70(r1)
	  lfs       f2, -0x5DD0(r31)
	  fmuls     f0, f6, f29
	  lfs       f3, 0x74(r1)
	  fadds     f2, f2, f1
	  fmuls     f1, f3, f31
	  fmuls     f4, f7, f29
	  stfs      f2, -0x5DD0(r31)
	  fmuls     f3, f3, f30
	  fsubs     f2, f1, f0
	  lfs       f0, 0x5C(r29)
	  lfs       f5, -0x5DCC(r31)
	  fsubs     f3, f4, f3
	  fmuls     f4, f30, f0
	  fmuls     f1, f6, f30
	  fmuls     f0, f7, f31
	  fadds     f4, f5, f4
	  fsubs     f0, f1, f0
	  stfs      f4, -0x5DCC(r31)
	  lfs       f1, 0x5C(r29)
	  lfs       f4, -0x5DC8(r31)
	  fmuls     f1, f29, f1
	  fadds     f1, f4, f1
	  stfs      f1, -0x5DC8(r31)
	  lfs       f1, -0x5DC4(r31)
	  fadds     f1, f1, f3
	  stfs      f1, -0x5DC4(r31)
	  lfs       f1, -0x5DC0(r31)
	  fadds     f1, f1, f2
	  stfs      f1, -0x5DC0(r31)
	  lfs       f1, -0x5DBC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, -0x5DBC(r31)

	.loc_0x190:
	  lwz       r0, 0xDC(r1)
	  lfd       f31, 0xD0(r1)
	  lfd       f30, 0xC8(r1)
	  lfd       f29, 0xC0(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8006292C
 * Size:	000868
 */
void DynObjBody::integrate(int, int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x308(r1)
	  stfd      f31, 0x300(r1)
	  stfd      f30, 0x2F8(r1)
	  stfd      f29, 0x2F0(r1)
	  stfd      f28, 0x2E8(r1)
	  stfd      f27, 0x2E0(r1)
	  stfd      f26, 0x2D8(r1)
	  stfd      f25, 0x2D0(r1)
	  stfd      f24, 0x2C8(r1)
	  stfd      f23, 0x2C0(r1)
	  stmw      r27, 0x2AC(r1)
	  addi      r27, r3, 0
	  addi      r28, r5, 0
	  bl        -0x1484C
	  mulli     r3, r28, 0x308C
	  addi      r30, r3, 0x4118
	  add       r30, r27, r30
	  addis     r3, r27, 0x1
	  lfs       f1, 0x40(r30)
	  lfs       f0, 0x3300(r3)
	  addi      r28, r30, 0x1C
	  lfs       f3, 0x44(r30)
	  addi      r29, r30, 0x10
	  lfs       f2, 0x3304(r3)
	  fmuls     f0, f1, f0
	  lfs       f4, 0x48(r30)
	  lfs       f1, 0x3308(r3)
	  fmuls     f2, f3, f2
	  addi      r31, r30, 0x4
	  stfs      f0, 0x40(r30)
	  fmuls     f0, f4, f1
	  stfs      f2, 0x44(r30)
	  stfs      f0, 0x48(r30)
	  lfs       f1, 0x58(r30)
	  lfs       f0, 0x330C(r3)
	  lfs       f3, 0x5C(r30)
	  lfs       f2, 0x3310(r3)
	  fmuls     f0, f1, f0
	  lfs       f4, 0x60(r30)
	  lfs       f1, 0x3314(r3)
	  fmuls     f2, f3, f2
	  stfs      f0, 0x58(r30)
	  fmuls     f0, f4, f1
	  stfs      f2, 0x5C(r30)
	  stfs      f0, 0x60(r30)
	  lfs       f31, 0x0(r30)
	  lfs       f30, 0xC(r30)
	  lfs       f29, 0x18(r30)
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  lfs       f28, 0x4(r30)
	  fmuls     f2, f29, f29
	  lfs       f27, 0x10(r30)
	  fadds     f0, f1, f0
	  lfs       f26, 0x1C(r30)
	  fadds     f1, f2, f0
	  bl        -0x54DD4
	  lfs       f0, -0x78B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x104
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x104:
	  fmuls     f3, f30, f26
	  fmuls     f2, f29, f27
	  fmuls     f1, f29, f28
	  fmuls     f0, f31, f26
	  fsubs     f26, f3, f2
	  fmuls     f3, f31, f27
	  fsubs     f27, f1, f0
	  fmuls     f2, f30, f28
	  fmuls     f1, f26, f26
	  fmuls     f0, f27, f27
	  fsubs     f28, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f28, f28
	  fadds     f1, f1, f0
	  bl        -0x54E28
	  lfs       f0, -0x78B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x158
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x158:
	  fmuls     f3, f27, f29
	  fmuls     f2, f28, f30
	  fmuls     f1, f28, f31
	  fmuls     f0, f26, f29
	  fsubs     f25, f3, f2
	  fmuls     f3, f26, f30
	  fsubs     f24, f1, f0
	  fmuls     f2, f27, f31
	  fmuls     f1, f25, f25
	  fmuls     f0, f24, f24
	  fsubs     f23, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f23, f23
	  fadds     f1, f1, f0
	  bl        -0x54E7C
	  lfs       f0, -0x78B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1AC
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1
	  fdivs     f23, f23, f1

	.loc_0x1AC:
	  stfs      f31, 0x0(r30)
	  addi      r4, r30, 0
	  addi      r3, r30, 0x24
	  stfs      f25, 0x0(r31)
	  stfs      f26, 0x8(r30)
	  stfs      f30, 0xC(r30)
	  stfs      f24, 0x0(r29)
	  stfs      f27, 0x14(r30)
	  stfs      f29, 0x18(r30)
	  stfs      f23, 0x0(r28)
	  stfs      f28, 0x20(r30)
	  bl        -0x2B248
	  addi      r3, r1, 0x1D4
	  bl        -0x13C60
	  lfs       f1, 0x0(r30)
	  addi      r5, r1, 0x1D4
	  lfs       f0, 0x64(r27)
	  addi      r6, r30, 0xC
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r27)
	  lfs       f5, 0x4(r30)
	  addi      r5, r5, 0xC
	  lfs       f0, 0x7C(r27)
	  fadds     f3, f3, f2
	  lfs       f1, 0x8(r30)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x1D4(r1)
	  lfs       f0, 0x68(r27)
	  lfs       f1, 0x0(r30)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r27)
	  lfs       f5, 0x4(r30)
	  lfs       f0, 0x80(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r30)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x1D8(r1)
	  lfs       f0, 0x6C(r27)
	  lfs       f1, 0x0(r30)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r27)
	  lfs       f5, 0x4(r30)
	  lfs       f1, 0x8(r30)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x84(r27)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x1DC(r1)
	  lfs       f1, 0x0(r6)
	  lfs       f0, 0x64(r27)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x7C(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x68(r27)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x80(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x6C(r27)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  addi      r6, r6, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x84(r27)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  addi      r5, r5, 0xC
	  lfs       f1, 0x0(r6)
	  addi      r31, r1, 0x254
	  lfs       f0, 0x64(r27)
	  addi      r3, r1, 0x1AC
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x7C(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x68(r27)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x80(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x6C(r27)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x84(r27)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  lwz       r0, 0x1D4(r1)
	  lwz       r4, 0x1D8(r1)
	  stw       r0, 0x254(r1)
	  lwz       r0, 0x1DC(r1)
	  stw       r4, 0x258(r1)
	  lwz       r4, 0x1E0(r1)
	  stw       r0, 0x25C(r1)
	  lwz       r0, 0x1E4(r1)
	  stw       r4, 0x260(r1)
	  lwz       r4, 0x1E8(r1)
	  stw       r0, 0x264(r1)
	  lwz       r0, 0x1EC(r1)
	  stw       r4, 0x268(r1)
	  lwz       r4, 0x1F0(r1)
	  stw       r0, 0x26C(r1)
	  lwz       r0, 0x1F4(r1)
	  stw       r4, 0x270(r1)
	  stw       r0, 0x274(r1)
	  bl        -0x13EC0
	  lfs       f0, 0x0(r30)
	  addi      r3, r1, 0x180
	  stfs      f0, 0x1AC(r1)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x1B8(r1)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x1C4(r1)
	  lfs       f0, 0xC(r30)
	  stfs      f0, 0x1B0(r1)
	  lfs       f0, 0x10(r30)
	  stfs      f0, 0x1BC(r1)
	  lfs       f0, 0x14(r30)
	  stfs      f0, 0x1C8(r1)
	  lfs       f0, 0x18(r30)
	  stfs      f0, 0x1B4(r1)
	  lfs       f0, 0x1C(r30)
	  stfs      f0, 0x1C0(r1)
	  lfs       f0, 0x20(r30)
	  stfs      f0, 0x1CC(r1)
	  lwz       r0, 0x1AC(r1)
	  lwz       r4, 0x1B0(r1)
	  stw       r0, 0x230(r1)
	  lwz       r0, 0x1B4(r1)
	  stw       r4, 0x234(r1)
	  lwz       r4, 0x1B8(r1)
	  stw       r0, 0x238(r1)
	  lwz       r0, 0x1BC(r1)
	  stw       r4, 0x23C(r1)
	  lwz       r4, 0x1C0(r1)
	  stw       r0, 0x240(r1)
	  lwz       r0, 0x1C4(r1)
	  stw       r4, 0x244(r1)
	  lwz       r4, 0x1C8(r1)
	  stw       r0, 0x248(r1)
	  lwz       r0, 0x1CC(r1)
	  stw       r4, 0x24C(r1)
	  stw       r0, 0x250(r1)
	  bl        -0x13F58
	  lfs       f0, 0x230(r1)
	  addi      r4, r1, 0x180
	  lfs       f1, 0x254(r1)
	  addi      r5, r31, 0xC
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x23C(r1)
	  lfs       f5, 0x258(r1)
	  addi      r4, r4, 0xC
	  lfs       f1, 0x25C(r1)
	  fadds     f3, f3, f2
	  lfs       f0, 0x248(r1)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x180(r1)
	  lfs       f0, 0x234(r1)
	  lfs       f1, 0x254(r1)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x240(r1)
	  lfs       f5, 0x258(r1)
	  lfs       f1, 0x25C(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x24C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x184(r1)
	  lfs       f0, 0x238(r1)
	  lfs       f1, 0x254(r1)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x244(r1)
	  lfs       f5, 0x258(r1)
	  lfs       f1, 0x25C(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x250(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x188(r1)
	  lfs       f0, 0x230(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x23C(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x248(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r4)
	  lfs       f0, 0x234(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x240(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x24C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r4)
	  lfs       f0, 0x238(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x244(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  addi      r5, r5, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x250(r1)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r4)
	  addi      r4, r4, 0xC
	  lfs       f0, 0x230(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x23C(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x248(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r4)
	  lfs       f0, 0x234(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x240(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x24C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r4)
	  lfs       f0, 0x238(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x244(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x250(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r4)
	  lwz       r0, 0x180(r1)
	  lwz       r3, 0x184(r1)
	  stw       r0, 0x278(r1)
	  lwz       r0, 0x188(r1)
	  stw       r3, 0x27C(r1)
	  lwz       r3, 0x18C(r1)
	  stw       r0, 0x280(r1)
	  lwz       r0, 0x190(r1)
	  stw       r3, 0x284(r1)
	  lwz       r3, 0x194(r1)
	  stw       r0, 0x288(r1)
	  lwz       r0, 0x198(r1)
	  stw       r3, 0x28C(r1)
	  lwz       r3, 0x19C(r1)
	  stw       r0, 0x290(r1)
	  lwz       r0, 0x1A0(r1)
	  stw       r3, 0x294(r1)
	  stw       r0, 0x298(r1)
	  lwz       r3, 0x278(r1)
	  lwz       r0, 0x27C(r1)
	  stw       r3, 0x64(r30)
	  stw       r0, 0x68(r30)
	  lwz       r3, 0x280(r1)
	  lwz       r0, 0x284(r1)
	  stw       r3, 0x6C(r30)
	  stw       r0, 0x70(r30)
	  lwz       r3, 0x288(r1)
	  lwz       r0, 0x28C(r1)
	  stw       r3, 0x74(r30)
	  stw       r0, 0x78(r30)
	  lwz       r3, 0x290(r1)
	  lwz       r0, 0x294(r1)
	  stw       r3, 0x7C(r30)
	  stw       r0, 0x80(r30)
	  lwz       r0, 0x298(r1)
	  stw       r0, 0x84(r30)
	  lfs       f0, -0x78B0(r2)
	  stfs      f0, 0x17C(r1)
	  stfs      f0, 0x178(r1)
	  stfs      f0, 0x174(r1)
	  lfs       f4, 0x58(r30)
	  lfs       f1, 0x64(r30)
	  lfs       f3, 0x5C(r30)
	  lfs       f0, 0x68(r30)
	  fmuls     f1, f4, f1
	  lfs       f5, 0x60(r30)
	  fmuls     f0, f3, f0
	  lfs       f2, 0x6C(r30)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x174(r1)
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x74(r30)
	  lfs       f2, 0x78(r30)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x178(r1)
	  lfs       f1, 0x7C(r30)
	  lfs       f0, 0x80(r30)
	  lfs       f2, 0x84(r30)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x17C(r1)
	  lfs       f0, 0x174(r1)
	  stfs      f0, 0x224(r1)
	  lfs       f0, 0x178(r1)
	  stfs      f0, 0x228(r1)
	  lfs       f0, 0x17C(r1)
	  stfs      f0, 0x22C(r1)
	  lwz       r3, 0x224(r1)
	  lwz       r0, 0x228(r1)
	  stw       r3, 0x4C(r30)
	  stw       r0, 0x50(r30)
	  lwz       r0, 0x22C(r1)
	  stw       r0, 0x54(r30)
	  lmw       r27, 0x2AC(r1)
	  lwz       r0, 0x30C(r1)
	  lfd       f31, 0x300(r1)
	  lfd       f30, 0x2F8(r1)
	  lfd       f29, 0x2F0(r1)
	  lfd       f28, 0x2E8(r1)
	  lfd       f27, 0x2E0(r1)
	  lfd       f26, 0x2D8(r1)
	  lfd       f25, 0x2D0(r1)
	  lfd       f24, 0x2C8(r1)
	  lfd       f23, 0x2C0(r1)
	  addi      r1, r1, 0x308
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80063194
 * Size:	0008A8
 */
void DynObjSeeSaw::integrate(int, int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x308(r1)
	  stfd      f31, 0x300(r1)
	  stfd      f30, 0x2F8(r1)
	  stfd      f29, 0x2F0(r1)
	  stfd      f28, 0x2E8(r1)
	  stfd      f27, 0x2E0(r1)
	  stfd      f26, 0x2D8(r1)
	  stfd      f25, 0x2D0(r1)
	  stfd      f24, 0x2C8(r1)
	  stfd      f23, 0x2C0(r1)
	  stmw      r27, 0x2AC(r1)
	  addi      r27, r3, 0
	  addi      r28, r5, 0
	  bl        -0x150B4
	  mulli     r3, r28, 0x308C
	  addi      r30, r3, 0x4118
	  add       r30, r27, r30
	  addis     r4, r27, 0x1
	  addi      r3, r30, 0x40
	  addi      r4, r4, 0x335C
	  bl        -0x2BBE0
	  addis     r4, r27, 0x1
	  addi      r3, r30, 0x58
	  addi      r4, r4, 0x335C
	  bl        -0x2BBF0
	  addis     r31, r27, 0x1
	  lfs       f1, 0x40(r30)
	  lfs       f0, 0x3300(r31)
	  mr        r4, r31
	  lfs       f3, 0x44(r30)
	  addi      r3, r30, 0x40
	  lfs       f2, 0x3304(r31)
	  fmuls     f0, f1, f0
	  lfs       f4, 0x48(r30)
	  lfs       f1, 0x3308(r31)
	  fmuls     f2, f3, f2
	  addi      r4, r4, 0x331C
	  stfs      f0, 0x40(r30)
	  fmuls     f0, f4, f1
	  stfs      f2, 0x44(r30)
	  stfs      f0, 0x48(r30)
	  lfs       f1, 0x58(r30)
	  lfs       f0, 0x330C(r31)
	  lfs       f3, 0x5C(r30)
	  lfs       f2, 0x3310(r31)
	  fmuls     f0, f1, f0
	  lfs       f4, 0x60(r30)
	  lfs       f1, 0x3314(r31)
	  fmuls     f2, f3, f2
	  stfs      f0, 0x58(r30)
	  fmuls     f0, f4, f1
	  stfs      f2, 0x5C(r30)
	  stfs      f0, 0x60(r30)
	  bl        -0x2BC64
	  addi      r4, r31, 0
	  addi      r3, r30, 0x58
	  addi      r4, r4, 0x331C
	  bl        -0x2BC74
	  lfs       f31, 0x0(r30)
	  addi      r28, r30, 0x1C
	  lfs       f30, 0xC(r30)
	  addi      r29, r30, 0x10
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  lfs       f29, 0x18(r30)
	  addi      r31, r30, 0x4
	  lfs       f27, 0x10(r30)
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  lfs       f28, 0x4(r30)
	  lfs       f26, 0x1C(r30)
	  fadds     f1, f2, f0
	  bl        -0x5567C
	  lfs       f0, -0x78B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x144
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x144:
	  fmuls     f3, f30, f26
	  fmuls     f2, f29, f27
	  fmuls     f1, f29, f28
	  fmuls     f0, f31, f26
	  fsubs     f26, f3, f2
	  fmuls     f3, f31, f27
	  fsubs     f27, f1, f0
	  fmuls     f2, f30, f28
	  fmuls     f1, f26, f26
	  fmuls     f0, f27, f27
	  fsubs     f28, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f28, f28
	  fadds     f1, f1, f0
	  bl        -0x556D0
	  lfs       f0, -0x78B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x198
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1
	  fdivs     f28, f28, f1

	.loc_0x198:
	  fmuls     f3, f27, f29
	  fmuls     f2, f28, f30
	  fmuls     f1, f28, f31
	  fmuls     f0, f26, f29
	  fsubs     f25, f3, f2
	  fmuls     f3, f26, f30
	  fsubs     f24, f1, f0
	  fmuls     f2, f27, f31
	  fmuls     f1, f25, f25
	  fmuls     f0, f24, f24
	  fsubs     f23, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f23, f23
	  fadds     f1, f1, f0
	  bl        -0x55724
	  lfs       f0, -0x78B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1EC
	  fdivs     f25, f25, f1
	  fdivs     f24, f24, f1
	  fdivs     f23, f23, f1

	.loc_0x1EC:
	  stfs      f31, 0x0(r30)
	  addi      r4, r30, 0
	  addi      r3, r30, 0x24
	  stfs      f25, 0x0(r31)
	  stfs      f26, 0x8(r30)
	  stfs      f30, 0xC(r30)
	  stfs      f24, 0x0(r29)
	  stfs      f27, 0x14(r30)
	  stfs      f29, 0x18(r30)
	  stfs      f23, 0x0(r28)
	  stfs      f28, 0x20(r30)
	  bl        -0x2BAF0
	  addi      r3, r1, 0x1D4
	  bl        -0x14508
	  lfs       f1, 0x0(r30)
	  addi      r5, r1, 0x1D4
	  lfs       f0, 0x64(r27)
	  addi      r6, r30, 0xC
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r27)
	  lfs       f5, 0x4(r30)
	  addi      r5, r5, 0xC
	  lfs       f0, 0x7C(r27)
	  fadds     f3, f3, f2
	  lfs       f1, 0x8(r30)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x1D4(r1)
	  lfs       f0, 0x68(r27)
	  lfs       f1, 0x0(r30)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r27)
	  lfs       f5, 0x4(r30)
	  lfs       f0, 0x80(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r30)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x1D8(r1)
	  lfs       f0, 0x6C(r27)
	  lfs       f1, 0x0(r30)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r27)
	  lfs       f5, 0x4(r30)
	  lfs       f1, 0x8(r30)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x84(r27)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x1DC(r1)
	  lfs       f1, 0x0(r6)
	  lfs       f0, 0x64(r27)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x7C(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x68(r27)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x80(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x6C(r27)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  addi      r6, r6, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x84(r27)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  addi      r5, r5, 0xC
	  lfs       f1, 0x0(r6)
	  addi      r31, r1, 0x254
	  lfs       f0, 0x64(r27)
	  addi      r3, r1, 0x1AC
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x70(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x7C(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r5)
	  lfs       f0, 0x68(r27)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x74(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f0, 0x80(r27)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f1, 0x8(r6)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r5)
	  lfs       f0, 0x6C(r27)
	  lfs       f1, 0x0(r6)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x78(r27)
	  lfs       f5, 0x4(r6)
	  lfs       f1, 0x8(r6)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x84(r27)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r5)
	  lwz       r0, 0x1D4(r1)
	  lwz       r4, 0x1D8(r1)
	  stw       r0, 0x254(r1)
	  lwz       r0, 0x1DC(r1)
	  stw       r4, 0x258(r1)
	  lwz       r4, 0x1E0(r1)
	  stw       r0, 0x25C(r1)
	  lwz       r0, 0x1E4(r1)
	  stw       r4, 0x260(r1)
	  lwz       r4, 0x1E8(r1)
	  stw       r0, 0x264(r1)
	  lwz       r0, 0x1EC(r1)
	  stw       r4, 0x268(r1)
	  lwz       r4, 0x1F0(r1)
	  stw       r0, 0x26C(r1)
	  lwz       r0, 0x1F4(r1)
	  stw       r4, 0x270(r1)
	  stw       r0, 0x274(r1)
	  bl        -0x14768
	  lfs       f0, 0x0(r30)
	  addi      r3, r1, 0x180
	  stfs      f0, 0x1AC(r1)
	  lfs       f0, 0x4(r30)
	  stfs      f0, 0x1B8(r1)
	  lfs       f0, 0x8(r30)
	  stfs      f0, 0x1C4(r1)
	  lfs       f0, 0xC(r30)
	  stfs      f0, 0x1B0(r1)
	  lfs       f0, 0x10(r30)
	  stfs      f0, 0x1BC(r1)
	  lfs       f0, 0x14(r30)
	  stfs      f0, 0x1C8(r1)
	  lfs       f0, 0x18(r30)
	  stfs      f0, 0x1B4(r1)
	  lfs       f0, 0x1C(r30)
	  stfs      f0, 0x1C0(r1)
	  lfs       f0, 0x20(r30)
	  stfs      f0, 0x1CC(r1)
	  lwz       r0, 0x1AC(r1)
	  lwz       r4, 0x1B0(r1)
	  stw       r0, 0x230(r1)
	  lwz       r0, 0x1B4(r1)
	  stw       r4, 0x234(r1)
	  lwz       r4, 0x1B8(r1)
	  stw       r0, 0x238(r1)
	  lwz       r0, 0x1BC(r1)
	  stw       r4, 0x23C(r1)
	  lwz       r4, 0x1C0(r1)
	  stw       r0, 0x240(r1)
	  lwz       r0, 0x1C4(r1)
	  stw       r4, 0x244(r1)
	  lwz       r4, 0x1C8(r1)
	  stw       r0, 0x248(r1)
	  lwz       r0, 0x1CC(r1)
	  stw       r4, 0x24C(r1)
	  stw       r0, 0x250(r1)
	  bl        -0x14800
	  lfs       f0, 0x230(r1)
	  addi      r4, r1, 0x180
	  lfs       f1, 0x254(r1)
	  addi      r5, r31, 0xC
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x23C(r1)
	  lfs       f5, 0x258(r1)
	  addi      r4, r4, 0xC
	  lfs       f1, 0x25C(r1)
	  fadds     f3, f3, f2
	  lfs       f0, 0x248(r1)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x180(r1)
	  lfs       f0, 0x234(r1)
	  lfs       f1, 0x254(r1)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x240(r1)
	  lfs       f5, 0x258(r1)
	  lfs       f1, 0x25C(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x24C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x184(r1)
	  lfs       f0, 0x238(r1)
	  lfs       f1, 0x254(r1)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x244(r1)
	  lfs       f5, 0x258(r1)
	  lfs       f1, 0x25C(r1)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x250(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x188(r1)
	  lfs       f0, 0x230(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x23C(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x248(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r4)
	  lfs       f0, 0x234(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x240(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x24C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r4)
	  lfs       f0, 0x238(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x244(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  addi      r5, r5, 0xC
	  fadds     f3, f3, f2
	  lfs       f0, 0x250(r1)
	  fmuls     f2, f5, f4
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r4)
	  addi      r4, r4, 0xC
	  lfs       f0, 0x230(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x23C(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x248(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x0(r4)
	  lfs       f0, 0x234(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x240(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x24C(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x4(r4)
	  lfs       f0, 0x238(r1)
	  lfs       f1, 0x0(r5)
	  lfs       f3, -0x78B0(r2)
	  fmuls     f2, f1, f0
	  lfs       f4, 0x244(r1)
	  lfs       f5, 0x4(r5)
	  lfs       f1, 0x8(r5)
	  fadds     f3, f3, f2
	  fmuls     f2, f5, f4
	  lfs       f0, 0x250(r1)
	  fmuls     f0, f1, f0
	  fadds     f3, f3, f2
	  fadds     f3, f3, f0
	  stfs      f3, 0x8(r4)
	  lwz       r0, 0x180(r1)
	  lwz       r3, 0x184(r1)
	  stw       r0, 0x278(r1)
	  lwz       r0, 0x188(r1)
	  stw       r3, 0x27C(r1)
	  lwz       r3, 0x18C(r1)
	  stw       r0, 0x280(r1)
	  lwz       r0, 0x190(r1)
	  stw       r3, 0x284(r1)
	  lwz       r3, 0x194(r1)
	  stw       r0, 0x288(r1)
	  lwz       r0, 0x198(r1)
	  stw       r3, 0x28C(r1)
	  lwz       r3, 0x19C(r1)
	  stw       r0, 0x290(r1)
	  lwz       r0, 0x1A0(r1)
	  stw       r3, 0x294(r1)
	  stw       r0, 0x298(r1)
	  lwz       r3, 0x278(r1)
	  lwz       r0, 0x27C(r1)
	  stw       r3, 0x64(r30)
	  stw       r0, 0x68(r30)
	  lwz       r3, 0x280(r1)
	  lwz       r0, 0x284(r1)
	  stw       r3, 0x6C(r30)
	  stw       r0, 0x70(r30)
	  lwz       r3, 0x288(r1)
	  lwz       r0, 0x28C(r1)
	  stw       r3, 0x74(r30)
	  stw       r0, 0x78(r30)
	  lwz       r3, 0x290(r1)
	  lwz       r0, 0x294(r1)
	  stw       r3, 0x7C(r30)
	  stw       r0, 0x80(r30)
	  lwz       r0, 0x298(r1)
	  stw       r0, 0x84(r30)
	  lfs       f0, -0x78B0(r2)
	  stfs      f0, 0x17C(r1)
	  stfs      f0, 0x178(r1)
	  stfs      f0, 0x174(r1)
	  lfs       f4, 0x58(r30)
	  lfs       f1, 0x64(r30)
	  lfs       f3, 0x5C(r30)
	  lfs       f0, 0x68(r30)
	  fmuls     f1, f4, f1
	  lfs       f5, 0x60(r30)
	  fmuls     f0, f3, f0
	  lfs       f2, 0x6C(r30)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x174(r1)
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x74(r30)
	  lfs       f2, 0x78(r30)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x178(r1)
	  lfs       f1, 0x7C(r30)
	  lfs       f0, 0x80(r30)
	  lfs       f2, 0x84(r30)
	  fmuls     f1, f4, f1
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x17C(r1)
	  lfs       f0, 0x174(r1)
	  stfs      f0, 0x224(r1)
	  lfs       f0, 0x178(r1)
	  stfs      f0, 0x228(r1)
	  lfs       f0, 0x17C(r1)
	  stfs      f0, 0x22C(r1)
	  lwz       r3, 0x224(r1)
	  lwz       r0, 0x228(r1)
	  stw       r3, 0x4C(r30)
	  stw       r0, 0x50(r30)
	  lwz       r0, 0x22C(r1)
	  stw       r0, 0x54(r30)
	  lmw       r27, 0x2AC(r1)
	  lwz       r0, 0x30C(r1)
	  lfd       f31, 0x300(r1)
	  lfd       f30, 0x2F8(r1)
	  lfd       f29, 0x2F0(r1)
	  lfd       f28, 0x2E8(r1)
	  lfd       f27, 0x2E0(r1)
	  lfd       f26, 0x2D8(r1)
	  lfd       f25, 0x2D0(r1)
	  lfd       f24, 0x2C8(r1)
	  lfd       f23, 0x2C0(r1)
	  addi      r1, r1, 0x308
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80063A3C
 * Size:	0000F8
 */
void DynObjBody::initRender(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  addis     r3, r31, 0x1
	  lfs       f0, -0x6CC8(r13)
	  addis     r4, r31, 0x1
	  addis     r5, r31, 0x1
	  lfs       f1, -0x6CC4(r13)
	  stfs      f0, 0x10(r1)
	  lfs       f0, -0x6CC0(r13)
	  addi      r6, r1, 0x10
	  stfs      f1, 0x14(r1)
	  addi      r3, r3, 0x32BC
	  addi      r4, r4, 0x3260
	  stfs      f0, 0x18(r1)
	  addi      r5, r5, 0x328C
	  bl        -0x24D80
	  addis     r31, r31, 0x1
	  lwz       r4, 0x32FC(r31)
	  addi      r3, r4, 0x5C
	  addi      r4, r4, 0x9C
	  bl        -0x2565C
	  lwz       r4, 0x32FC(r31)
	  lwz       r3, 0x32BC(r31)
	  lwz       r0, 0x32C0(r31)
	  stw       r3, 0x5C(r4)
	  stw       r0, 0x60(r4)
	  lwz       r3, 0x32C4(r31)
	  lwz       r0, 0x32C8(r31)
	  stw       r3, 0x64(r4)
	  stw       r0, 0x68(r4)
	  lwz       r3, 0x32CC(r31)
	  lwz       r0, 0x32D0(r31)
	  stw       r3, 0x6C(r4)
	  stw       r0, 0x70(r4)
	  lwz       r3, 0x32D4(r31)
	  lwz       r0, 0x32D8(r31)
	  stw       r3, 0x74(r4)
	  stw       r0, 0x78(r4)
	  lwz       r3, 0x32DC(r31)
	  lwz       r0, 0x32E0(r31)
	  stw       r3, 0x7C(r4)
	  stw       r0, 0x80(r4)
	  lwz       r3, 0x32E4(r31)
	  lwz       r0, 0x32E8(r31)
	  stw       r3, 0x84(r4)
	  stw       r0, 0x88(r4)
	  lwz       r3, 0x32EC(r31)
	  lwz       r0, 0x32F0(r31)
	  stw       r3, 0x8C(r4)
	  stw       r0, 0x90(r4)
	  lwz       r3, 0x32F4(r31)
	  lwz       r0, 0x32F8(r31)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80063B34
 * Size:	0003E8
 */
void DynObjBody::applyWorldSpring(int, int, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r5, 0xC
	  stwu      r1, -0x1E0(r1)
	  stfd      f31, 0x1D8(r1)
	  addi      r5, r1, 0xA4
	  stfd      f30, 0x1D0(r1)
	  stfd      f29, 0x1C8(r1)
	  stfd      f28, 0x1C0(r1)
	  stfd      f27, 0x1B8(r1)
	  stfd      f26, 0x1B0(r1)
	  stfd      f25, 0x1A8(r1)
	  stfd      f24, 0x1A0(r1)
	  stfd      f23, 0x198(r1)
	  stfd      f22, 0x190(r1)
	  stfd      f21, 0x188(r1)
	  stw       r31, 0x184(r1)
	  mulli     r31, r4, 0x308C
	  stw       r30, 0x180(r1)
	  addi      r30, r31, 0x4118
	  stw       r29, 0x17C(r1)
	  mr        r29, r6
	  addi      r6, r1, 0xA8
	  stw       r28, 0x178(r1)
	  addi      r28, r3, 0
	  add       r30, r28, r30
	  add       r4, r30, r0
	  lfs       f1, 0x3C(r30)
	  lfs       f22, 0x94(r4)
	  addi      r3, r1, 0xFC
	  lfs       f23, 0x90(r4)
	  lfs       f0, 0x38(r30)
	  fsubs     f3, f22, f1
	  lfs       f1, 0x50(r30)
	  fsubs     f4, f23, f0
	  lfs       f0, 0x54(r30)
	  fmuls     f1, f1, f3
	  lfs       f24, 0x8C(r4)
	  addi      r4, r1, 0xA0
	  fmuls     f0, f0, f4
	  lfs       f2, 0x34(r30)
	  fsubs     f2, f24, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA0(r1)
	  lfs       f1, 0x54(r30)
	  lfs       f0, 0x4C(r30)
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f3
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA4(r1)
	  lfs       f1, 0x4C(r30)
	  lfs       f0, 0x50(r30)
	  fmuls     f1, f1, f4
	  fmuls     f0, f0, f2
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  bl        -0x2CAF8
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x0(r29)
	  fsubs     f27, f1, f23
	  lfs       f2, 0x8(r29)
	  fsubs     f26, f0, f24
	  lfs       f1, -0x78B0(r2)
	  fsubs     f28, f2, f22
	  fmuls     f2, f26, f26
	  lfs       f7, 0x48(r30)
	  fmuls     f0, f27, f27
	  lfs       f4, 0x104(r1)
	  fmuls     f3, f28, f28
	  fadds     f0, f2, f0
	  lfs       f6, 0x44(r30)
	  lfs       f5, 0x100(r1)
	  fadds     f31, f7, f4
	  lfs       f4, 0x40(r30)
	  fadds     f0, f3, f0
	  lfs       f2, 0xFC(r1)
	  fadds     f30, f6, f5
	  fadds     f29, f4, f2
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x19C
	  fsqrte    f2, f0
	  lfd       f4, -0x78A8(r2)
	  lfd       f3, -0x78A0(r2)
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f1, f2, f1
	  fmul      f1, f0, f1
	  frsp      f1, f1
	  stfs      f1, 0xBC(r1)
	  lfs       f3, 0xBC(r1)
	  b         .loc_0x1A0

	.loc_0x19C:
	  fmr       f3, f0

	.loc_0x1A0:
	  lfs       f1, -0x78B0(r2)
	  lfs       f2, -0x7898(r2)
	  fcmpo     cr0, f0, f1
	  lfs       f21, -0x7880(r2)
	  fsubs     f25, f3, f2
	  ble-      .loc_0x210
	  fsqrte    f2, f0
	  lfd       f4, -0x78A8(r2)
	  lfd       f3, -0x78A0(r2)
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f2, f2, f1
	  fmul      f1, f2, f2
	  fmul      f2, f4, f2
	  fmul      f1, f0, f1
	  fsub      f1, f3, f1
	  fmul      f1, f2, f1
	  fmul      f0, f0, f1
	  frsp      f0, f0
	  stfs      f0, 0xB8(r1)
	  lfs       f0, 0xB8(r1)

	.loc_0x210:
	  lfs       f3, -0x7898(r2)
	  fmuls     f2, f26, f26
	  fmuls     f1, f27, f27
	  lfs       f4, -0x7884(r2)
	  fdivs     f0, f0, f3
	  lfs       f5, -0x787C(r2)
	  fsubs     f4, f4, f0
	  fmuls     f3, f28, f28
	  fadds     f0, f2, f1
	  fmuls     f2, f5, f4
	  fadds     f1, f3, f0
	  fadds     f21, f21, f2
	  bl        -0x56134
	  fdivs     f0, f25, f1
	  addi      r6, r1, 0x9C
	  addi      r5, r1, 0x98
	  addi      r4, r1, 0x94
	  addi      r3, r1, 0xD8
	  fmuls     f25, f26, f0
	  fmuls     f27, f27, f0
	  fmuls     f26, f28, f0
	  fmuls     f3, f25, f29
	  fmuls     f2, f27, f30
	  fmuls     f1, f25, f25
	  fmuls     f0, f27, f27
	  fadds     f3, f3, f2
	  fmuls     f4, f26, f31
	  fadds     f0, f1, f0
	  fmuls     f2, f26, f26
	  fadds     f1, f4, f3
	  fneg      f3, f21
	  fadds     f0, f2, f0
	  fdivs     f0, f1, f0
	  fmuls     f0, f3, f0
	  fmuls     f2, f26, f0
	  fmuls     f1, f27, f0
	  fmuls     f0, f25, f0
	  stfs      f2, 0x9C(r1)
	  stfs      f1, 0x98(r1)
	  stfs      f0, 0x94(r1)
	  bl        -0x2CCC8
	  add       r7, r28, r31
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0x4154(r7)
	  addi      r6, r1, 0x90
	  lfs       f3, 0xD8(r1)
	  fadds     f26, f26, f1
	  fsubs     f0, f22, f0
	  lfs       f2, 0xDC(r1)
	  fadds     f22, f25, f3
	  addi      r5, r1, 0x8C
	  stfs      f0, 0x90(r1)
	  fadds     f25, f27, f2
	  addi      r4, r1, 0x88
	  lfs       f0, 0x4150(r7)
	  addi      r3, r1, 0xCC
	  fsubs     f0, f23, f0
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x414C(r7)
	  fsubs     f0, f24, f0
	  stfs      f0, 0x88(r1)
	  bl        -0x2CD1C
	  lfs       f0, 0x5C(r28)
	  addis     r3, r28, 0x1
	  lfs       f6, 0xCC(r1)
	  fmuls     f1, f22, f0
	  lfs       f7, 0xD0(r1)
	  lfs       f2, -0x5DD0(r3)
	  fmuls     f0, f6, f26
	  lfs       f3, 0xD4(r1)
	  fadds     f2, f2, f1
	  fmuls     f1, f3, f22
	  fmuls     f4, f7, f26
	  stfs      f2, -0x5DD0(r3)
	  fmuls     f3, f3, f25
	  fsubs     f2, f1, f0
	  lfs       f0, 0x5C(r28)
	  lfs       f5, -0x5DCC(r3)
	  fsubs     f3, f4, f3
	  fmuls     f4, f25, f0
	  fmuls     f1, f6, f25
	  fmuls     f0, f7, f22
	  fadds     f4, f5, f4
	  fsubs     f0, f1, f0
	  stfs      f4, -0x5DCC(r3)
	  lfs       f1, 0x5C(r28)
	  lfs       f4, -0x5DC8(r3)
	  fmuls     f1, f26, f1
	  fadds     f1, f4, f1
	  stfs      f1, -0x5DC8(r3)
	  lfs       f1, -0x5DC4(r3)
	  fadds     f1, f1, f3
	  stfs      f1, -0x5DC4(r3)
	  lfs       f1, -0x5DC0(r3)
	  fadds     f1, f1, f2
	  stfs      f1, -0x5DC0(r3)
	  lfs       f1, -0x5DBC(r3)
	  fadds     f0, f1, f0
	  stfs      f0, -0x5DBC(r3)
	  lwz       r0, 0x1E4(r1)
	  lfd       f31, 0x1D8(r1)
	  lfd       f30, 0x1D0(r1)
	  lfd       f29, 0x1C8(r1)
	  lfd       f28, 0x1C0(r1)
	  lfd       f27, 0x1B8(r1)
	  lfd       f26, 0x1B0(r1)
	  lfd       f25, 0x1A8(r1)
	  lfd       f24, 0x1A0(r1)
	  lfd       f23, 0x198(r1)
	  lfd       f22, 0x190(r1)
	  lfd       f21, 0x188(r1)
	  lwz       r31, 0x184(r1)
	  lwz       r30, 0x180(r1)
	  lwz       r29, 0x17C(r1)
	  lwz       r28, 0x178(r1)
	  addi      r1, r1, 0x1E0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80063F1C
 * Size:	0001AC
 */
void DynObjBody::render(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r4, 0
	  addi      r5, r1, 0x14
	  stw       r30, 0x60(r1)
	  addi      r30, r3, 0
	  addis     r4, r30, 0x1
	  stw       r29, 0x5C(r1)
	  addi      r3, r31, 0
	  addi      r4, r4, 0x32BC
	  stw       r28, 0x58(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  addis     r4, r30, 0x1
	  lwz       r5, 0x2E4(r31)
	  addi      r0, r4, 0x3260
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x154(r5)
	  lbz       r0, 0x154(r5)
	  cmplwi    r0, 0
	  beq-      .loc_0x84
	  lwz       r3, 0x3260(r4)
	  lwz       r0, 0x3264(r4)
	  stw       r3, 0x158(r5)
	  stw       r0, 0x15C(r5)
	  lwz       r0, 0x3268(r4)
	  stw       r0, 0x160(r5)

	.loc_0x84:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x14
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2E4(r31)
	  li        r0, 0
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xD0
	  lwz       r3, 0x0(r0)
	  lwz       r0, 0x4(r0)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x8(r0)
	  stw       r0, 0x160(r4)

	.loc_0xD0:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x10(r1)
	  addi      r4, r1, 0x10
	  addi      r3, r31, 0
	  stb       r0, 0x11(r1)
	  li        r5, 0x1
	  stb       r0, 0x12(r1)
	  stb       r0, 0x13(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r28, 0
	  rlwinm    r0,r28,4,0,27
	  add       r29, r30, r0
	  b         .loc_0x180

	.loc_0x14C:
	  lwz       r0, 0x4098(r29)
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r5, r29, 0x409C
	  mulli     r4, r0, 0xC
	  lwz       r12, 0x98(r12)
	  addis     r4, r4, 0x1
	  mtlr      r12
	  addi      r4, r4, 0x248
	  add       r4, r30, r4
	  blrl
	  addi      r29, r29, 0x10
	  addi      r28, r28, 0x1

	.loc_0x180:
	  lwz       r0, 0x4094(r30)
	  cmpw      r28, r0
	  blt+      .loc_0x14C
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
 * Address:	800640C8
 * Size:	0001E0
 */
void DynObjBody::computeForces(int, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stmw      r26, 0x70(r1)
	  addi      r30, r4, 0
	  mulli     r4, r30, 0x308C
	  addi      r29, r3, 0
	  addis     r3, r29, 0x1
	  addi      r31, r4, 0x4118
	  add       r31, r29, r31
	  lwz       r5, 0x32B8(r3)
	  lfs       f1, 0x34(r31)
	  lfs       f0, 0x140(r5)
	  lfs       f3, 0x158(r5)
	  fsubs     f2, f1, f0
	  lfs       f1, 0x3C(r31)
	  lfs       f0, 0x148(r5)
	  fdivs     f2, f2, f3
	  fctiwz    f2, f2
	  fsubs     f0, f1, f0
	  stfd      f2, 0x58(r1)
	  fdivs     f0, f0, f3
	  lwz       r0, 0x5C(r1)
	  stfd      f2, 0x68(r1)
	  cmpwi     r0, 0
	  lwz       r4, 0x6C(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x60(r1)
	  lwz       r3, 0x64(r1)
	  blt-      .loc_0x98
	  cmpwi     r3, 0
	  blt-      .loc_0x98
	  lwz       r6, 0x15C(r5)
	  cmpw      r4, r6
	  bge-      .loc_0x98
	  lwz       r0, 0x160(r5)
	  cmpw      r3, r0
	  blt-      .loc_0xA0

	.loc_0x98:
	  li        r0, 0
	  b         .loc_0xB4

	.loc_0xA0:
	  mullw     r0, r3, r6
	  lwz       r3, 0x164(r5)
	  add       r0, r4, r0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r3, r0

	.loc_0xB4:
	  lfs       f0, -0x6CBC(r13)
	  addi      r4, r1, 0x30
	  lfs       f1, -0x6CB8(r13)
	  mr        r27, r0
	  stfs      f0, 0x30(r1)
	  lfs       f0, -0x6CB4(r13)
	  mr        r3, r29
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  bl        -0x160D4
	  li        r26, 0
	  rlwinm    r0,r26,4,0,27
	  add       r28, r29, r0
	  b         .loc_0x108

	.loc_0xEC:
	  lwz       r5, 0x4098(r28)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r6, r28, 0x409C
	  bl        -0x690
	  addi      r28, r28, 0x10
	  addi      r26, r26, 0x1

	.loc_0x108:
	  lwz       r0, 0x4094(r29)
	  cmpw      r26, r0
	  blt+      .loc_0xEC
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  addi      r4, r30, 0
	  addi      r5, r27, 0
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x6CCC(r13)
	  addis     r3, r29, 0x1
	  lfs       f1, 0x2F04(r13)
	  fneg      f5, f0
	  lfs       f2, 0x40(r31)
	  lfs       f0, 0x44(r31)
	  fneg      f6, f1
	  lfs       f1, 0x48(r31)
	  fmuls     f3, f5, f2
	  lfs       f2, 0x5C(r29)
	  fmuls     f4, f5, f0
	  lfs       f0, -0x5DD0(r3)
	  fmuls     f1, f5, f1
	  fmuls     f3, f3, f2
	  fmuls     f4, f4, f2
	  fmuls     f1, f1, f2
	  fadds     f0, f0, f3
	  stfs      f0, -0x5DD0(r3)
	  lfs       f0, -0x5DCC(r3)
	  fadds     f0, f0, f4
	  stfs      f0, -0x5DCC(r3)
	  lfs       f0, -0x5DC8(r3)
	  fadds     f0, f0, f1
	  stfs      f0, -0x5DC8(r3)
	  lfs       f0, 0x4C(r31)
	  lfs       f1, -0x5DC4(r3)
	  fmuls     f0, f6, f0
	  lfs       f3, 0x54(r31)
	  lfs       f2, 0x50(r31)
	  fmuls     f3, f6, f3
	  fadds     f0, f1, f0
	  fmuls     f1, f6, f2
	  stfs      f0, -0x5DC4(r3)
	  lfs       f0, -0x5DC0(r3)
	  fadds     f0, f0, f1
	  stfs      f0, -0x5DC0(r3)
	  lfs       f0, -0x5DBC(r3)
	  fadds     f0, f0, f3
	  stfs      f0, -0x5DBC(r3)
	  lwz       r0, 0x8C(r1)
	  lmw       r26, 0x70(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800642A8
 * Size:	000268
 */
void DynObjBody::initBodyCollisions()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r8, 0
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  stw       r30, 0x30(r1)
	  addis     r30, r31, 0x1
	  stw       r29, 0x2C(r1)
	  lfs       f0, -0x78B0(r2)
	  stfs      f0, 0x18(r1)
	  stfs      f0, 0x14(r1)
	  stfs      f0, 0x10(r1)
	  stfs      f0, 0x24(r1)
	  stfs      f0, 0x20(r1)
	  stfs      f0, 0x1C(r1)
	  lfs       f1, -0x6D18(r13)
	  lfs       f0, -0x6D14(r13)
	  stfs      f1, 0x10(r1)
	  stfs      f0, 0x14(r1)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0x18(r1)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0x20(r1)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0x24(r1)
	  b         .loc_0x1BC

	.loc_0x78:
	  lwz       r7, 0x8C(r31)
	  li        r9, 0
	  li        r10, 0
	  cmpwi     r7, 0
	  mtctr     r7
	  ble-      .loc_0xE8

	.loc_0x90:
	  lwz       r3, 0x90(r31)
	  lwz       r0, 0x23C(r4)
	  add       r3, r10, r3
	  mulli     r3, r3, 0xC
	  add       r6, r31, r3
	  add       r3, r0, r5
	  lfs       f1, 0x94(r6)
	  lfs       f0, 0x0(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0xE0
	  lfs       f1, 0x98(r6)
	  lfs       f0, 0x4(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0xE0
	  lfs       f1, 0x9C(r6)
	  lfs       f0, 0x8(r3)
	  fcmpu     cr0, f1, f0
	  bne-      .loc_0xE0
	  li        r9, 0x1
	  b         .loc_0xE8

	.loc_0xE0:
	  addi      r10, r10, 0x1
	  bdnz+     .loc_0x90

	.loc_0xE8:
	  rlwinm.   r0,r9,0,24,31
	  bne-      .loc_0x1B4
	  lwz       r0, 0x90(r31)
	  lwz       r4, 0x23C(r4)
	  add       r0, r7, r0
	  mulli     r3, r0, 0xC
	  add       r4, r4, r5
	  addi      r3, r3, 0x94
	  lfs       f2, 0x8(r4)
	  lfs       f1, 0x4(r4)
	  add       r3, r31, r3
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x0(r3)
	  stfs      f1, 0x4(r3)
	  stfs      f2, 0x8(r3)
	  lwz       r3, 0x8C(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8C(r31)
	  lwz       r3, 0x32B4(r30)
	  lfs       f0, 0x10(r1)
	  lwz       r0, 0x23C(r3)
	  add       r3, r0, r5
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x150
	  stfs      f1, 0x10(r1)

	.loc_0x150:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x14(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x164
	  stfs      f1, 0x14(r1)

	.loc_0x164:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x18(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x178
	  stfs      f1, 0x18(r1)

	.loc_0x178:
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x1C(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x18C
	  stfs      f1, 0x1C(r1)

	.loc_0x18C:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x20(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1A0
	  stfs      f1, 0x20(r1)

	.loc_0x1A0:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x24(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1B4
	  stfs      f1, 0x24(r1)

	.loc_0x1B4:
	  addi      r5, r5, 0xC
	  addi      r8, r8, 0x1

	.loc_0x1BC:
	  lwz       r4, 0x32B4(r30)
	  lwz       r0, 0x238(r4)
	  cmpw      r8, r0
	  blt+      .loc_0x78
	  lfs       f0, -0x78B0(r2)
	  mr        r3, r31
	  stfs      f0, 0x88(r31)
	  lwz       r12, 0x0(r31)
	  lfs       f1, 0x1C(r1)
	  lfs       f0, 0x10(r1)
	  lwz       r12, 0x30(r12)
	  lfs       f4, 0x20(r1)
	  fsubs     f1, f1, f0
	  lfs       f2, 0x14(r1)
	  mtlr      r12
	  lfs       f3, 0x24(r1)
	  lfs       f0, 0x18(r1)
	  fsubs     f2, f4, f2
	  fsubs     f3, f3, f0
	  blrl
	  li        r3, 0x144
	  bl        -0x1D4B4
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x23C
	  lwz       r4, 0x32B4(r30)
	  bl        -0x24E4
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6DB8
	  stw       r0, 0x0(r29)
	  li        r0, 0
	  stw       r0, 0x140(r29)

	.loc_0x23C:
	  addis     r3, r31, 0x1
	  stw       r29, 0x32FC(r3)
	  lwz       r3, 0x32FC(r3)
	  stw       r31, 0x140(r3)
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
 * Address:	80064510
 * Size:	0003A4
 */
void DynObjBody::readScript(MapMgr*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r27, 0x4C(r1)
	  mr        r31, r3
	  addi      r27, r4, 0
	  addi      r4, r5, 0
	  subi      r29, r6, 0x7298
	  li        r5, 0x1
	  li        r6, 0x1
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0x390
	  li        r3, 0x11C
	  bl        -0x1D558
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x64
	  mr        r4, r30
	  bl        -0x239F4

	.loc_0x64:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  mr        r30, r28
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  addis     r28, r31, 0x1
	  b         .loc_0x354

	.loc_0x84:
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x234EC
	  addi      r3, r30, 0
	  subi      r4, r13, 0x6CB0
	  bl        -0x231D4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xBC
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x2350C
	  bl        -0x24280
	  stw       r3, 0x4(r31)
	  b         .loc_0x354

	.loc_0xBC:
	  addi      r3, r30, 0
	  addi      r4, r29, 0xC
	  bl        -0x23200
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF0
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x23538
	  addi      r4, r3, 0
	  addi      r3, r27, 0
	  bl        0x4E30
	  stw       r3, 0x32B4(r28)
	  b         .loc_0x354

	.loc_0xF0:
	  addi      r3, r30, 0
	  addi      r4, r29, 0x18
	  bl        -0x23234
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x190
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x2356C
	  crclr     6, 0x6
	  addi      r5, r1, 0x40
	  subi      r4, r13, 0x6CA8
	  bl        0x1B3A68
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x23588
	  crclr     6, 0x6
	  addi      r5, r1, 0x3C
	  subi      r4, r13, 0x6CA8
	  bl        0x1B3A4C
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x235A4
	  crclr     6, 0x6
	  addi      r5, r1, 0x38
	  subi      r4, r13, 0x6CA8
	  bl        0x1B3A30
	  lwz       r0, 0x90(r31)
	  lfs       f2, 0x38(r1)
	  mulli     r3, r0, 0xC
	  lfs       f1, 0x3C(r1)
	  lfs       f0, 0x40(r1)
	  addi      r3, r3, 0x94
	  add       r3, r31, r3
	  stfs      f0, 0x0(r3)
	  stfs      f1, 0x4(r3)
	  stfs      f2, 0x8(r3)
	  lwz       r3, 0x90(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x90(r31)
	  b         .loc_0x354

	.loc_0x190:
	  addi      r3, r30, 0
	  addi      r4, r29, 0x24
	  bl        -0x232D4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x254
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x2360C
	  crclr     6, 0x6
	  addi      r5, r1, 0x34
	  subi      r4, r13, 0x6CA4
	  bl        0x1B39C8
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x23628
	  crclr     6, 0x6
	  addi      r5, r1, 0x30
	  subi      r4, r13, 0x6CA8
	  bl        0x1B39AC
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x23644
	  crclr     6, 0x6
	  addi      r5, r1, 0x2C
	  subi      r4, r13, 0x6CA8
	  bl        0x1B3990
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x23660
	  crclr     6, 0x6
	  addi      r5, r1, 0x28
	  subi      r4, r13, 0x6CA8
	  bl        0x1B3974
	  lwz       r0, 0x4094(r31)
	  lfs       f2, 0x28(r1)
	  rlwinm    r3,r0,4,0,27
	  lfs       f1, 0x2C(r1)
	  addi      r3, r3, 0x4098
	  lfs       f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  add       r3, r31, r3
	  stw       r0, 0x0(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f1, 0x8(r3)
	  stfs      f2, 0xC(r3)
	  lwz       r3, 0x4094(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x4094(r31)
	  b         .loc_0x354

	.loc_0x254:
	  addi      r3, r30, 0
	  addi      r4, r29, 0x30
	  bl        -0x23398
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x354
	  addi      r3, r30, 0
	  addi      r4, r29, 0x3C
	  bl        -0x233AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2E0
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x236E4
	  addis     r5, r31, 0x1
	  crclr     6, 0x6
	  subi      r4, r13, 0x6CA8
	  addi      r5, r5, 0x3300
	  bl        0x1B38EC
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x23704
	  addis     r5, r31, 0x1
	  crclr     6, 0x6
	  subi      r4, r13, 0x6CA8
	  addi      r5, r5, 0x3304
	  bl        0x1B38CC
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x23724
	  addis     r5, r31, 0x1
	  crclr     6, 0x6
	  subi      r4, r13, 0x6CA8
	  addi      r5, r5, 0x3308
	  bl        0x1B38AC
	  b         .loc_0x354

	.loc_0x2E0:
	  addi      r3, r30, 0
	  addi      r4, r29, 0x48
	  bl        -0x23424
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x354
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x2375C
	  addis     r5, r31, 0x1
	  crclr     6, 0x6
	  subi      r4, r13, 0x6CA8
	  addi      r5, r5, 0x330C
	  bl        0x1B3874
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x2377C
	  addis     r5, r31, 0x1
	  crclr     6, 0x6
	  subi      r4, r13, 0x6CA8
	  addi      r5, r5, 0x3310
	  bl        0x1B3854
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x2379C
	  addis     r5, r31, 0x1
	  crclr     6, 0x6
	  subi      r4, r13, 0x6CA8
	  addi      r5, r5, 0x3314
	  bl        0x1B3834

	.loc_0x354:
	  mr        r3, r30
	  bl        -0x23B10
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x374
	  mr        r3, r30
	  bl        -0x233F0
	  rlwinm.   r0,r3,0,24,31
	  beq+      .loc_0x84

	.loc_0x374:
	  mr        r3, r30
	  bl        -0x23B30
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x390
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x237EC

	.loc_0x390:
	  lmw       r27, 0x4C(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800648B4
 * Size:	000538
 */
void DynObjPushable::render(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1D8(r1)
	  stmw      r27, 0x1C4(r1)
	  addi      r31, r4, 0
	  addi      r30, r3, 0
	  addis     r4, r30, 0x1
	  addi      r3, r31, 0
	  addi      r5, r1, 0x17C
	  addi      r4, r4, 0x32BC
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x17C
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addis     r3, r30, 0x1
	  lfs       f0, -0x78B0(r2)
	  lfs       f2, -0x5DD0(r3)
	  lfs       f1, -0x5DCC(r3)
	  fmuls     f2, f2, f2
	  lfs       f3, -0x5DC8(r3)
	  fmuls     f1, f1, f1
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xDC
	  fsqrte    f1, f4
	  lfd       f3, -0x78A8(r2)
	  lfd       f2, -0x78A0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x20(r1)
	  lfs       f4, 0x20(r1)

	.loc_0xDC:
	  lfs       f3, -0x78B0(r2)
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x17C
	  addis     r3, r30, 0x1
	  lfs       f1, -0x5DD0(r3)
	  lfs       f0, -0x5DCC(r3)
	  fmuls     f1, f1, f1
	  lfs       f2, -0x5DC8(r3)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f4, f2, f0
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x16C
	  fsqrte    f1, f4
	  lfd       f3, -0x78A8(r2)
	  lfd       f2, -0x78A0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x1C(r1)
	  lfs       f4, 0x1C(r1)

	.loc_0x16C:
	  lfs       f0, 0x60(r30)
	  addis     r3, r30, 0x1
	  fmuls     f0, f0, f4
	  stfs      f0, 0x331C(r3)

	.loc_0x17C:
	  addis     r29, r30, 0x1
	  lfs       f1, 0x331C(r29)
	  lfs       f0, 0x3320(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1C4
	  lfs       f0, -0x6CA0(r13)
	  stfs      f0, -0x5DD0(r29)
	  lfs       f0, -0x6C9C(r13)
	  stfs      f0, -0x5DCC(r29)
	  lfs       f0, -0x6C98(r13)
	  stfs      f0, -0x5DC8(r29)
	  lfs       f0, -0x6C94(r13)
	  stfs      f0, -0x5DC4(r29)
	  lfs       f0, -0x6C90(r13)
	  stfs      f0, -0x5DC0(r29)
	  lfs       f0, -0x6C8C(r13)
	  stfs      f0, -0x5DBC(r29)
	  b         .loc_0x244

	.loc_0x1C4:
	  lfs       f1, -0x5DD0(r29)
	  lfs       f0, -0x5DCC(r29)
	  fmuls     f1, f1, f1
	  lfs       f2, -0x5DC8(r29)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x56E58
	  lfs       f0, -0x78B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x218
	  lfs       f0, -0x5DD0(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, -0x5DD0(r29)
	  lfs       f0, -0x5DCC(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, -0x5DCC(r29)
	  lfs       f0, -0x5DC8(r29)
	  fdivs     f0, f0, f1
	  stfs      f0, -0x5DC8(r29)

	.loc_0x218:
	  addis     r3, r30, 0x1
	  lfs       f1, 0x3324(r3)
	  lfs       f0, -0x5DD0(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, -0x5DD0(r3)
	  lfs       f0, -0x5DCC(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, -0x5DCC(r3)
	  lfs       f0, -0x5DC8(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, -0x5DC8(r3)

	.loc_0x244:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  addi      r0, r3, 0
	  lis       r4, 0x803A
	  lwz       r12, 0x74(r12)
	  addi      r3, r31, 0
	  subi      r4, r4, 0x77C0
	  mtlr      r12
	  mr        r28, r0
	  li        r5, 0
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x6C(r1)
	  addi      r4, r1, 0x6C
	  addi      r3, r31, 0
	  stb       r0, 0x6D(r1)
	  li        r5, 0x1
	  stb       r0, 0x6E(r1)
	  stb       r0, 0x6F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x6C88(r13)
	  mr        r27, r3
	  lfs       f0, -0x6C84(r13)
	  addis     r29, r30, 0x1
	  stfs      f1, 0x170(r1)
	  addi      r3, r1, 0x170
	  stfs      f0, 0x174(r1)
	  lfs       f0, -0x6C80(r13)
	  stfs      f0, 0x178(r1)
	  lfs       f1, 0x170(r1)
	  lfs       f0, 0x3260(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x170(r1)
	  lfs       f1, 0x174(r1)
	  lfs       f0, 0x3264(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x174(r1)
	  lfs       f1, 0x178(r1)
	  lfs       f0, 0x3268(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x178(r1)
	  lwz       r4, 0x2E4(r31)
	  addi      r4, r4, 0x1E0
	  bl        -0x2D494
	  lfs       f1, 0x331C(r29)
	  addi      r3, r1, 0x70
	  crset     6, 0x6
	  subi      r4, r13, 0x6C7C
	  bl        0x1B19A4
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x70
	  lwz       r3, 0x10(r3)
	  bl        -0x3CAD0
	  lwz       r12, 0x3B4(r31)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r31, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x170
	  crclr     6, 0x6
	  addi      r8, r1, 0x70
	  li        r7, 0
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  mr        r4, r27
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x3B4(r31)
	  mr        r4, r29
	  mr        r3, r31
	  lwz       r12, 0x70(r12)
	  addi      r5, r1, 0x24
	  addi      r4, r4, 0x32BC
	  mtlr      r12
	  blrl
	  addi      r0, r29, 0x3260
	  lwz       r4, 0x2E4(r31)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x41C
	  lwz       r3, 0x3260(r29)
	  lwz       r0, 0x3264(r29)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x3268(r29)
	  stw       r0, 0x160(r4)

	.loc_0x41C:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x24
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2E4(r31)
	  li        r0, 0
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x468
	  lwz       r3, 0x0(r0)
	  lwz       r0, 0x4(r0)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x8(r0)
	  stw       r0, 0x160(r4)

	.loc_0x468:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x64(r1)
	  addi      r4, r1, 0x64
	  addi      r3, r31, 0
	  stb       r0, 0x65(r1)
	  li        r5, 0x1
	  stb       r0, 0x66(r1)
	  stb       r0, 0x67(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r29, 0
	  rlwinm    r0,r29,4,0,27
	  add       r28, r30, r0
	  b         .loc_0x518

	.loc_0x4E4:
	  lwz       r0, 0x4098(r28)
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r5, r28, 0x409C
	  mulli     r4, r0, 0xC
	  lwz       r12, 0x98(r12)
	  addis     r4, r4, 0x1
	  mtlr      r12
	  addi      r4, r4, 0x248
	  add       r4, r30, r4
	  blrl
	  addi      r28, r28, 0x10
	  addi      r29, r29, 0x1

	.loc_0x518:
	  lwz       r0, 0x4094(r30)
	  cmpw      r29, r0
	  blt+      .loc_0x4E4
	  lmw       r27, 0x1C4(r1)
	  lwz       r0, 0x1DC(r1)
	  addi      r1, r1, 0x1D8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80064DEC
 * Size:	0006B0
 */
MapMgr::MapMgr(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802B
	  stw       r30, 0x60(r1)
	  subi      r30, r3, 0x7298
	  addi      r3, r31, 0x114
	  stw       r29, 0x5C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x58(r1)
	  li        r28, 0
	  lfs       f2, -0x78B0(r2)
	  stfs      f2, 0x10(r31)
	  fmr       f1, f2
	  fmr       f0, f2
	  stfs      f2, 0xC(r31)
	  stfs      f2, 0x8(r31)
	  stw       r28, 0x64(r31)
	  stw       r28, 0x68(r31)
	  stw       r28, 0x6C(r31)
	  stw       r28, 0x70(r31)
	  stfs      f2, 0x98(r31)
	  stfs      f2, 0x94(r31)
	  stfs      f2, 0x90(r31)
	  stfs      f1, 0xA4(r31)
	  stfs      f1, 0xA0(r31)
	  stfs      f1, 0x9C(r31)
	  lfs       f1, -0x6D18(r13)
	  stfs      f1, 0x90(r31)
	  lfs       f1, -0x6D14(r13)
	  stfs      f1, 0x94(r31)
	  lfs       f1, -0x6D10(r13)
	  stfs      f1, 0x98(r31)
	  lfs       f1, -0x6D0C(r13)
	  stfs      f1, 0x9C(r31)
	  lfs       f1, -0x6D08(r13)
	  stfs      f1, 0xA0(r31)
	  lfs       f1, -0x6D04(r13)
	  stfs      f1, 0xA4(r31)
	  stfs      f0, 0xBC(r31)
	  stfs      f0, 0xB8(r31)
	  stfs      f0, 0xB4(r31)
	  stfs      f2, 0xC8(r31)
	  stfs      f2, 0xC4(r31)
	  stfs      f2, 0xC0(r31)
	  stfs      f2, 0xD4(r31)
	  stfs      f2, 0xD0(r31)
	  stfs      f2, 0xCC(r31)
	  lfs       f0, -0x6D18(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x6D14(r13)
	  stfs      f0, 0xC4(r31)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0xC8(r31)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0xCC(r31)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0xD0(r31)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0xD4(r31)
	  stfs      f2, 0xE0(r31)
	  stfs      f2, 0xDC(r31)
	  stfs      f2, 0xD8(r31)
	  stfs      f2, 0xEC(r31)
	  stfs      f2, 0xE8(r31)
	  stfs      f2, 0xE4(r31)
	  lfs       f0, -0x6D18(r13)
	  stfs      f0, 0xD8(r31)
	  lfs       f0, -0x6D14(r13)
	  stfs      f0, 0xDC(r31)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0xE0(r31)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0xE4(r31)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0xE8(r31)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0xEC(r31)
	  bl        0x4604
	  stw       r29, 0x0(r31)
	  li        r0, 0x91
	  subi      r4, r13, 0x6C74
	  lfs       f0, -0x78B0(r2)
	  stfs      f0, 0x4C4(r31)
	  stfs      f0, 0x4C0(r31)
	  stfs      f0, 0x4CC(r31)
	  stfs      f0, 0x4C8(r31)
	  stw       r28, 0x3180(r13)
	  stw       r0, 0x4BC(r31)
	  lwz       r3, 0x2FE8(r13)
	  bl        0x217DC
	  li        r3, 0x1418
	  bl        -0x1DF60
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x194
	  lwz       r5, 0x0(r31)
	  mr        r4, r31
	  bl        0x6538

	.loc_0x194:
	  stw       r28, 0x4(r31)
	  subi      r4, r13, 0x6C74
	  lwz       r3, 0x2FE8(r13)
	  bl        0x218BC
	  li        r3, 0
	  stw       r3, 0x10C(r31)
	  li        r0, 0x12C
	  stw       r3, 0x60(r31)
	  stw       r3, 0xA8(r31)
	  stw       r0, 0xB0(r31)
	  lwz       r0, 0xB0(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x1F0
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x54
	  bl        0x2177C
	  lwz       r0, 0xB0(r31)
	  mulli     r3, r0, 0xC
	  bl        -0x1DFC4
	  stw       r3, 0xF0(r31)
	  addi      r4, r30, 0x54
	  lwz       r3, 0x2FE8(r13)
	  bl        0x21870

	.loc_0x1F0:
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x60
	  bl        0x21754
	  li        r3, 0x148
	  bl        -0x1DFE8
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x230
	  li        r4, 0
	  bl        -0x3018
	  lis       r3, 0x802B
	  subi      r0, r3, 0xD20
	  stw       r0, 0x0(r28)
	  li        r0, 0
	  stw       r0, 0x144(r28)
	  stw       r0, 0x140(r28)

	.loc_0x230:
	  stw       r28, 0x4D0(r31)
	  li        r29, 0
	  subi      r0, r13, 0x6CD0
	  lwz       r3, 0x4D0(r31)
	  addi      r4, r30, 0x60
	  stw       r29, 0x10(r3)
	  stw       r29, 0xC(r3)
	  stw       r29, 0x8(r3)
	  stw       r0, 0x4(r3)
	  lwz       r3, 0x2FE8(r13)
	  bl        0x21804
	  lfs       f0, -0x6D18(r13)
	  subi      r4, r13, 0x6C6C
	  stfs      f0, 0x90(r31)
	  lfs       f0, -0x6D14(r13)
	  stfs      f0, 0x94(r31)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0x98(r31)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0x9C(r31)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0xA0(r31)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0xA4(r31)
	  lwz       r3, 0x2FE8(r13)
	  bl        0x216B8
	  li        r3, 0xC08
	  bl        -0x1E084
	  lis       r4, 0x8006
	  addi      r4, r4, 0x549C
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x100
	  bl        0x1AFB88
	  stw       r3, 0x14(r31)
	  subi      r4, r13, 0x6C6C
	  lwz       r3, 0x2FE8(r13)
	  bl        0x21798
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x6C
	  bl        0x2167C
	  li        r3, 0x140
	  bl        -0x1E0C0
	  mr.       r28, r3
	  beq-      .loc_0x434
	  addi      r3, r28, 0
	  subi      r4, r13, 0x6CD0
	  bl        -0x30120
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r28)
	  addi      r3, r28, 0
	  subi      r4, r13, 0x6CD0
	  bl        -0x249B4
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C4C
	  stw       r0, 0x0(r28)
	  lis       r3, 0x802B
	  li        r4, -0x1
	  stw       r29, 0x20(r28)
	  subi      r0, r3, 0x6BCC
	  addi      r3, r28, 0x44
	  stw       r4, 0x24(r28)
	  subi      r4, r13, 0x6D18
	  subi      r5, r13, 0x6D14
	  stw       r29, 0x28(r28)
	  subi      r6, r13, 0x6D10
	  stw       r0, 0x0(r28)
	  lfs       f0, -0x78B0(r2)
	  stfs      f0, 0x4C(r28)
	  stfs      f0, 0x48(r28)
	  stfs      f0, 0x44(r28)
	  stfs      f0, 0x58(r28)
	  stfs      f0, 0x54(r28)
	  stfs      f0, 0x50(r28)
	  bl        -0x7ABC
	  addi      r3, r28, 0x50
	  subi      r4, r13, 0x6D0C
	  subi      r5, r13, 0x6D08
	  subi      r6, r13, 0x6D04
	  bl        -0x7AD0
	  lfs       f0, -0x78B0(r2)
	  stfs      f0, 0x124(r28)
	  stfs      f0, 0x120(r28)
	  stfs      f0, 0x11C(r28)
	  stfs      f0, 0x130(r28)
	  stfs      f0, 0x12C(r28)
	  stfs      f0, 0x128(r28)
	  stfs      f0, 0x13C(r28)
	  stfs      f0, 0x138(r28)
	  stfs      f0, 0x134(r28)
	  stw       r29, 0x2C(r28)
	  lwz       r0, 0x2C(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x3B4
	  mr        r3, r28
	  bl        -0x39DC

	.loc_0x3B4:
	  lfs       f0, -0x6D00(r13)
	  addi      r3, r28, 0x5C
	  lfs       f1, -0x6CFC(r13)
	  stfs      f0, 0x40(r1)
	  lfs       f0, -0x6CF8(r13)
	  stfs      f1, 0x44(r1)
	  stfs      f0, 0x48(r1)
	  lwz       r4, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stw       r4, 0x11C(r28)
	  stw       r0, 0x120(r28)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x124(r28)
	  lfs       f0, -0x6CF4(r13)
	  lfs       f1, -0x6CF0(r13)
	  stfs      f0, 0x4C(r1)
	  lfs       f0, -0x6CEC(r13)
	  stfs      f1, 0x50(r1)
	  stfs      f0, 0x54(r1)
	  lwz       r4, 0x4C(r1)
	  lwz       r0, 0x50(r1)
	  stw       r4, 0x134(r28)
	  stw       r0, 0x138(r28)
	  lwz       r0, 0x54(r1)
	  stw       r0, 0x13C(r28)
	  lwz       r4, 0x134(r28)
	  lwz       r0, 0x138(r28)
	  stw       r4, 0x128(r28)
	  stw       r0, 0x12C(r28)
	  lwz       r0, 0x13C(r28)
	  stw       r0, 0x130(r28)
	  bl        -0x27460

	.loc_0x434:
	  stw       r28, 0x88(r31)
	  addi      r4, r30, 0x6C
	  lwz       r3, 0x2FE8(r13)
	  bl        0x2161C
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x78
	  bl        0x21500
	  li        r0, 0x3
	  stw       r0, 0x110(r31)
	  li        r28, 0
	  subi      r0, r13, 0x6CD0
	  stw       r28, 0x124(r31)
	  li        r3, 0xC
	  stw       r28, 0x120(r31)
	  stw       r28, 0x11C(r31)
	  stw       r0, 0x118(r31)
	  bl        -0x1E25C
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x4D4
	  lis       r3, 0x8023
	  subi      r0, r3, 0x7DA8
	  stw       r0, 0x4(r29)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x709C
	  stw       r28, 0x0(r29)
	  li        r3, 0x9C
	  stw       r0, 0x4(r29)
	  bl        -0x1E28C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x4B8
	  bl        -0x35658

	.loc_0x4B8:
	  stw       r28, 0x8(r29)
	  li        r0, 0xFF
	  lwz       r3, 0x8(r29)
	  stbu      r0, 0x2C(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x3(r3)

	.loc_0x4D4:
	  stw       r29, 0x4AC(r31)
	  li        r0, 0x100
	  li        r3, 0x10
	  lwz       r4, 0x4AC(r31)
	  lwz       r4, 0x8(r4)
	  stw       r0, 0x18(r4)
	  bl        -0x1E2D4
	  addi      r28, r3, 0
	  mr.       r0, r28
	  beq-      .loc_0x564
	  lis       r3, 0x8023
	  subi      r0, r3, 0x7DA8
	  stw       r0, 0x4(r28)
	  li        r4, 0
	  lis       r3, 0x802B
	  stw       r4, 0x0(r28)
	  subi      r0, r3, 0x70CC
	  li        r3, 0x9C
	  stw       r0, 0x4(r28)
	  stw       r4, 0xC(r28)
	  bl        -0x1E30C
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x538
	  bl        -0x356D8

	.loc_0x538:
	  stw       r29, 0x8(r28)
	  li        r5, 0
	  li        r3, 0x80
	  lwz       r4, 0x8(r28)
	  li        r0, 0x20
	  stw       r5, 0x24(r4)
	  lwz       r4, 0x8(r28)
	  stbu      r3, 0x2C(r4)
	  stb       r3, 0x1(r4)
	  stb       r3, 0x2(r4)
	  stb       r0, 0x3(r4)

	.loc_0x564:
	  stw       r28, 0x4B0(r31)
	  lis       r3, 0x1
	  subi      r5, r3, 0x7F00
	  lwz       r3, 0x4B0(r31)
	  li        r0, 0xFF
	  addi      r4, r30, 0x78
	  lwz       r3, 0x8(r3)
	  stw       r5, 0x18(r3)
	  lwz       r3, 0x4B0(r31)
	  lwz       r3, 0x8(r3)
	  stbu      r0, 0x2C(r3)
	  stb       r0, 0x1(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x3(r3)
	  lwz       r3, 0x2FE8(r13)
	  bl        0x214BC
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x84
	  bl        0x213A0
	  li        r3, 0x3C
	  bl        -0x1E39C
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x5C8
	  bl        -0x2121C

	.loc_0x5C8:
	  stw       r28, 0x4B4(r31)
	  li        r0, 0x105
	  li        r4, 0x140
	  lfs       f0, -0x7874(r2)
	  li        r5, 0xF0
	  lwz       r3, 0x4B4(r31)
	  li        r6, 0x8
	  li        r7, 0
	  stfs      f0, 0x28(r3)
	  lfs       f0, -0x7870(r2)
	  lwz       r3, 0x4B4(r31)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4B4(r31)
	  sth       r0, 0x6(r3)
	  lwz       r3, 0x4B4(r31)
	  bl        -0x20E8C
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r30, 0x94
	  lwz       r4, 0x4B4(r31)
	  bl        -0x25C08
	  li        r3, 0x3C
	  bl        -0x1E404
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x630
	  bl        -0x21284

	.loc_0x630:
	  stw       r28, 0x4B8(r31)
	  li        r0, 0x105
	  li        r4, 0x140
	  lfs       f0, -0x7874(r2)
	  li        r5, 0xF0
	  lwz       r3, 0x4B8(r31)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x28(r3)
	  lfs       f0, -0x7870(r2)
	  lwz       r3, 0x4B8(r31)
	  stfs      f0, 0x2C(r3)
	  lwz       r3, 0x4B8(r31)
	  sth       r0, 0x6(r3)
	  lwz       r3, 0x4B8(r31)
	  bl        -0x20EF4
	  lwz       r3, 0x2DEC(r13)
	  addi      r5, r30, 0x94
	  lwz       r4, 0x4B8(r31)
	  bl        -0x25C70
	  lwz       r3, 0x2FE8(r13)
	  addi      r4, r30, 0x84
	  bl        0x213D4
	  mr        r3, r31
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
 * Address:	8006549C
 * Size:	000018
 */
MapRoom::MapRoom()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  lfs       f0, -0x7884(r2)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800654B4
 * Size:	000030
 */
void MapMgr::initEffects()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x6B4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x1E4C0
	  cmplwi    r3, 0
	  beq-      .loc_0x20
	  bl        0x136CDC

	.loc_0x20:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800654E4
 * Size:	0003C4
 */
void MapMgr::initShape()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x24E0
	  lis       r5, 0x803A
	  stwu      r1, -0x70(r1)
	  lis       r6, 0x802B
	  addi      r4, r4, 0xB0
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stmw      r25, 0x44(r1)
	  addi      r26, r3, 0
	  li        r25, 0
	  subi      r3, r5, 0x2848
	  subi      r29, r6, 0x7298
	  li        r5, 0x1
	  stw       r25, 0x8C(r26)
	  bl        -0x12818
	  stw       r3, 0x60(r26)
	  addi      r4, r26, 0x64
	  li        r5, 0
	  lwz       r3, 0x60(r26)
	  lwz       r0, 0x14(r3)
	  ori       r0, r0, 0x4
	  stw       r0, 0x14(r3)
	  lwz       r3, 0x60(r26)
	  bl        -0x35C20
	  lwz       r3, 0x60(r26)
	  li        r6, 0
	  lwz       r5, 0x58(r3)
	  cmpwi     r5, 0
	  ble-      .loc_0xC8
	  cmpwi     r5, 0x8
	  subi      r4, r5, 0x8
	  ble-      .loc_0x3A0
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  ble-      .loc_0x3A0

	.loc_0xA0:
	  addi      r25, r25, 0x8E0
	  addi      r6, r6, 0x8
	  bdnz+     .loc_0xA0
	  b         .loc_0x3A0

	.loc_0xB0:
	  sub       r0, r5, r6
	  cmpw      r6, r5
	  mtctr     r0
	  bge-      .loc_0xC8

	.loc_0xC0:
	  addi      r4, r4, 0x11C
	  bdnz+     .loc_0xC0

	.loc_0xC8:
	  li        r4, 0x40
	  bl        -0x31858
	  lwz       r3, 0x60(r26)
	  lfs       f0, 0x90(r26)
	  lfsu      f1, 0x140(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xE8
	  stfs      f1, 0x90(r26)

	.loc_0xE8:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x94(r26)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xFC
	  stfs      f1, 0x94(r26)

	.loc_0xFC:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x98(r26)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x110
	  stfs      f1, 0x98(r26)

	.loc_0x110:
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x9C(r26)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x124
	  stfs      f1, 0x9C(r26)

	.loc_0x124:
	  lfs       f1, 0x10(r3)
	  lfs       f0, 0xA0(r26)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x138
	  stfs      f1, 0xA0(r26)

	.loc_0x138:
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0xA4(r26)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x14C
	  stfs      f1, 0xA4(r26)

	.loc_0x14C:
	  li        r3, 0x1B0
	  bl        -0x1E630
	  mr.       r27, r3
	  beq-      .loc_0x1F4
	  lis       r3, 0x8022
	  addi      r0, r3, 0x738C
	  lis       r3, 0x8022
	  stw       r0, 0x0(r27)
	  addi      r0, r3, 0x737C
	  stw       r0, 0x0(r27)
	  li        r25, 0
	  addi      r3, r27, 0
	  stw       r25, 0x10(r27)
	  addi      r4, r29, 0xB4
	  stw       r25, 0xC(r27)
	  stw       r25, 0x8(r27)
	  bl        -0x4079C
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r27)
	  addi      r3, r27, 0
	  addi      r4, r29, 0xB4
	  bl        -0x24F4C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x712C
	  lis       r3, 0x8006
	  stw       r0, 0x0(r27)
	  addi      r4, r3, 0x58A8
	  addi      r3, r27, 0x44
	  li        r5, 0
	  li        r6, 0x24
	  li        r7, 0xA
	  bl        0x1AF3C0
	  li        r0, 0x2
	  stw       r0, 0x30(r27)
	  lfs       f0, -0x7868(r2)
	  stfs      f0, 0x34(r27)
	  stw       r25, 0x38(r27)
	  stw       r25, 0x3C(r27)
	  stw       r25, 0x2C(r27)
	  stw       r25, 0x20(r27)
	  stw       r25, 0x24(r27)

	.loc_0x1F4:
	  stw       r27, 0x108(r26)
	  lis       r3, 0x802B
	  subi      r31, r3, 0x6F80
	  lfs       f0, -0x7864(r2)
	  li        r27, 0
	  lis       r30, 0x1
	  stfs      f0, 0xFC(r26)
	  lfs       f0, -0x7860(r2)
	  stfs      f0, 0x100(r26)
	  lfs       f31, -0x78B0(r2)
	  stfs      f31, 0xF4(r26)
	  stfs      f31, 0xF8(r26)
	  lfs       f30, -0x7884(r2)
	  b         .loc_0x38C

	.loc_0x22C:
	  addi      r3, r30, 0x331C
	  bl        -0x1E710
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x2A4
	  bl        -0x84B8
	  stw       r31, 0x0(r28)
	  addis     r3, r28, 0x1
	  li        r0, 0
	  stfs      f31, 0x3308(r3)
	  stfs      f31, 0x3304(r3)
	  stfs      f31, 0x3300(r3)
	  stfs      f31, 0x3314(r3)
	  stfs      f31, 0x3310(r3)
	  stfs      f31, 0x330C(r3)
	  stw       r0, 0x32B4(r3)
	  stw       r0, 0x8C(r28)
	  lfs       f0, -0x6CE8(r13)
	  stfs      f0, 0x3300(r3)
	  lfs       f0, -0x6CE4(r13)
	  stfs      f0, 0x3304(r3)
	  lfs       f0, -0x6CE0(r13)
	  stfs      f0, 0x3308(r3)
	  lfs       f0, -0x6CDC(r13)
	  stfs      f0, 0x330C(r3)
	  lfs       f0, -0x6CD8(r13)
	  stfs      f0, 0x3310(r3)
	  lfs       f0, -0x6CD4(r13)
	  stfs      f0, 0x3314(r3)
	  stfs      f30, 0x3318(r3)

	.loc_0x2A4:
	  lwz       r0, 0x60(r26)
	  addis     r25, r28, 0x1
	  addi      r3, r28, 0
	  stw       r0, 0x32B8(r25)
	  addi      r4, r26, 0
	  addi      r5, r29, 0xC0
	  bl        -0x1290
	  mr        r3, r28
	  bl        -0x1500
	  lfs       f0, -0x6C64(r13)
	  mr        r4, r28
	  stfs      f0, 0x20(r28)
	  lfs       f0, -0x6C60(r13)
	  stfs      f0, 0x24(r28)
	  lfs       f0, -0x6C5C(r13)
	  stfs      f0, 0x28(r28)
	  lfs       f0, -0x6C58(r13)
	  lfs       f1, -0x6C54(r13)
	  stfs      f0, 0x34(r1)
	  lfs       f0, -0x6C50(r13)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lwz       r3, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r3, 0x44(r28)
	  stw       r0, 0x48(r28)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x4C(r28)
	  lfs       f0, -0x6C4C(r13)
	  lfs       f1, -0x6C48(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x6C44(r13)
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  lwz       r3, 0x28(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r3, 0x2C(r28)
	  stw       r0, 0x30(r28)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x34(r28)
	  lfs       f0, -0x6C40(r13)
	  lfs       f1, -0x6C3C(r13)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, -0x6C38(r13)
	  stfs      f1, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  lwz       r3, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r3, 0x38(r28)
	  stw       r0, 0x3C(r28)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x40(r28)
	  lwz       r3, 0x108(r26)
	  bl        -0x25284
	  lwz       r3, 0x88(r26)
	  lwz       r4, 0x32FC(r25)
	  bl        -0x25290
	  addi      r27, r27, 0x1

	.loc_0x38C:
	  cmpwi     r27, 0
	  blt+      .loc_0x22C
	  li        r0, 0x1
	  stb       r0, 0x104(r26)
	  b         .loc_0x3A8

	.loc_0x3A0:
	  mulli     r4, r6, 0x11C
	  b         .loc_0xB0

	.loc_0x3A8:
	  lmw       r25, 0x44(r1)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800658A8
 * Size:	000020
 */
Collision::Collision()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x78B0(r2)
	  stfs      f0, 0xC(r3)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800658C8
 * Size:	000004
 */
void MapMgr::createLights() { }

/*
 * --INFO--
 * Address:	800658CC
 * Size:	0000FC
 */
void MapMgr::updateSimulation()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  lbz       r0, 0x104(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  lwz       r3, 0x108(r30)
	  bl        -0x15D30
	  li        r0, 0
	  stb       r0, 0x104(r30)
	  lwz       r3, 0x108(r30)
	  stw       r0, 0x20(r3)

	.loc_0x3C:
	  lwz       r3, 0x108(r30)
	  lwz       r4, 0x2DEC(r13)
	  lwz       r0, 0x20(r3)
	  lfs       f1, 0x28C(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0xE4
	  lfs       f0, 0xF8(r30)
	  fadds     f0, f0, f1
	  stfs      f0, 0xF8(r30)
	  b         .loc_0xC0

	.loc_0x64:
	  lwz       r3, 0x108(r30)
	  lwz       r0, 0x20(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xB0
	  lwz       r31, 0x10(r3)
	  b         .loc_0x94

	.loc_0x7C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x68(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0xC(r31)

	.loc_0x94:
	  cmplwi    r31, 0
	  bne+      .loc_0x7C
	  lwz       r3, 0x108(r30)
	  lfs       f1, 0xFC(r30)
	  lfs       f2, 0x100(r30)
	  lwz       r4, 0x60(r30)
	  bl        -0x15CFC

	.loc_0xB0:
	  lfs       f1, 0xF4(r30)
	  lfs       f0, 0xFC(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0xF4(r30)

	.loc_0xC0:
	  lfs       f1, 0xF8(r30)
	  lfs       f0, 0xF4(r30)
	  lfs       f2, 0xFC(r30)
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f2
	  bgt+      .loc_0x64
	  fdivs     f1, f0, f2
	  lwz       r3, 0x108(r30)
	  bl        -0x15A14

	.loc_0xE4:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800659C8
 * Size:	0001D4
 */
void MapMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr        r29, r3
	  bl        -0x118
	  lwz       r30, 0x108(r29)
	  lwz       r31, 0x10(r30)
	  b         .loc_0x48

	.loc_0x2C:
	  mr        r3, r31
	  lwz       r4, 0x28(r30)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0xC(r31)

	.loc_0x48:
	  cmplwi    r31, 0
	  bne+      .loc_0x2C
	  lwz       r3, 0x88(r29)
	  lwz       r31, 0x10(r3)
	  b         .loc_0x1B0

	.loc_0x5C:
	  lwz       r0, 0x28(r31)
	  cmplwi    r0, 0
	  mr        r30, r0
	  beq-      .loc_0x110
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x110
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0xA4
	  addi      r3, r30, 0x40
	  bl        0x2E730
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1AC

	.loc_0xA4:
	  lwz       r5, 0x6C(r30)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  cmpwi     r5, 0x16
	  addi      r0, r3, 0
	  beq-      .loc_0xC8
	  cmpwi     r5, 0x17
	  beq-      .loc_0xC8
	  li        r0, 0

	.loc_0xC8:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0xDC
	  cmpwi     r5, 0x18
	  beq-      .loc_0xDC
	  li        r4, 0

	.loc_0xDC:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0xF0
	  cmpwi     r5, 0x19
	  beq-      .loc_0xF0
	  li        r3, 0

	.loc_0xF0:
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x100
	  cmpwi     r5, 0x26
	  bne-      .loc_0x110

	.loc_0x100:
	  addi      r3, r30, 0x40
	  bl        0x2E6C4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1AC

	.loc_0x110:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x40C8
	  li        r0, 0
	  cmplwi    r30, 0
	  stw       r0, 0x20(r31)
	  beq-      .loc_0x1AC
	  lwz       r6, 0x6C(r30)
	  li        r3, 0x1
	  addi      r4, r3, 0
	  cmpwi     r6, 0x16
	  addi      r5, r3, 0
	  beq-      .loc_0x160
	  cmpwi     r6, 0x17
	  beq-      .loc_0x160
	  mr        r5, r0

	.loc_0x160:
	  rlwinm.   r0,r5,0,24,31
	  bne-      .loc_0x174
	  cmpwi     r6, 0x18
	  beq-      .loc_0x174
	  li        r4, 0

	.loc_0x174:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x188
	  cmpwi     r6, 0x19
	  beq-      .loc_0x188
	  li        r3, 0

	.loc_0x188:
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x194
	  b         .loc_0x1AC

	.loc_0x194:
	  cmpwi     r6, 0x37
	  bne-      .loc_0x1A0
	  b         .loc_0x1AC

	.loc_0x1A0:
	  bne-      .loc_0x1A8
	  b         .loc_0x1AC

	.loc_0x1A8:
	  cmpwi     r6, 0x26

	.loc_0x1AC:
	  lwz       r31, 0xC(r31)

	.loc_0x1B0:
	  cmplwi    r31, 0
	  bne+      .loc_0x5C
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80065B9C
 * Size:	000008
 */
bool Creature::alwaysUpdatePlatform() { return false; }

/*
 * --INFO--
 * Address:	80065BA4
 * Size:	0000F4
 */
void MapMgr::preRender(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  stw       r0, 0x18(r3)
	  addi      r3, r29, 0
	  stw       r0, 0x1C(r28)
	  lwz       r12, 0x3B4(r29)
	  lwz       r4, 0x4AC(r28)
	  lwz       r12, 0xC0(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x300
	  stw       r0, 0x4(r29)
	  lwz       r31, 0x124(r28)
	  b         .loc_0x98

	.loc_0x58:
	  addi      r30, r31, 0x14
	  addi      r3, r30, 0
	  addi      r4, r31, 0x37C
	  addi      r5, r31, 0x388
	  bl        -0x22E68
	  lwz       r0, 0x110(r28)
	  cmpwi     r0, 0
	  ble-      .loc_0x80
	  li        r6, 0
	  b         .loc_0x84

	.loc_0x80:
	  lwz       r6, 0x394(r31)

	.loc_0x84:
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  li        r5, 0
	  bl        -0x22850
	  lwz       r31, 0xC(r31)

	.loc_0x98:
	  cmplwi    r31, 0
	  bne+      .loc_0x58
	  li        r0, 0x700
	  stw       r0, 0x4(r29)
	  addi      r3, r29, 0
	  li        r4, 0
	  lwz       r12, 0x3B4(r29)
	  lwz       r12, 0xC0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x110(r28)
	  cmpwi     r3, 0
	  beq-      .loc_0xD4
	  subi      r0, r3, 0x1
	  stw       r0, 0x110(r28)

	.loc_0xD4:
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
 * Address:	80065C98
 * Size:	00019C
 */
void MapMgr::drawShadowCasters(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r25, 0x14(r1)
	  addi      r26, r4, 0
	  addi      r25, r3, 0
	  addi      r3, r26, 0
	  li        r4, 0
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  li        r4, 0x2
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x1
	  lwz       r28, 0x124(r25)
	  lis       r4, 0x803A
	  addi      r29, r3, 0
	  subi      r30, r5, 0x7900
	  subi      r31, r4, 0x77C0
	  b         .loc_0x150

	.loc_0x64:
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  addi      r27, r28, 0x14
	  addi      r5, r27, 0
	  lwz       r12, 0xE4(r12)
	  li        r4, 0x1
	  mtlr      r12
	  blrl
	  lwz       r4, 0x4B0(r25)
	  mr        r3, r26
	  lwz       r0, 0x358(r27)
	  lwz       r4, 0x8(r4)
	  stw       r0, 0x24(r4)
	  lwz       r4, 0x4B0(r25)
	  stw       r27, 0xC(r4)
	  lwz       r12, 0x3B4(r26)
	  lwz       r4, 0x4B0(r25)
	  lwz       r12, 0xC0(r12)
	  mtlr      r12
	  blrl
	  stw       r30, 0x4(r26)
	  addi      r3, r26, 0
	  addi      r4, r31, 0
	  stw       r27, 0x338(r26)
	  li        r5, 0
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x60(r25)
	  mr        r4, r26
	  lwz       r5, 0x2E4(r26)
	  li        r6, 0
	  bl        -0x3608C
	  li        r0, 0
	  stw       r0, 0x338(r26)
	  li        r0, 0x700
	  addi      r3, r26, 0
	  stw       r0, 0x4(r26)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x3B4(r26)
	  lwz       r12, 0xC4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  li        r4, 0
	  lwz       r12, 0xC0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xE4(r12)
	  mtlr      r12
	  blrl
	  lwz       r28, 0xC(r28)

	.loc_0x150:
	  cmplwi    r28, 0
	  bne+      .loc_0x64
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  mr        r4, r29
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x3B4(r26)
	  li        r4, 0x1
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  lmw       r25, 0x14(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80065E34
 * Size:	000438
 */
void MapMgr::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x138(r1)
	  stfd      f31, 0x130(r1)
	  stfd      f30, 0x128(r1)
	  stmw      r26, 0x110(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  addi      r3, r28, 0
	  li        r4, 0
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lwz       r29, 0x8C(r27)
	  cmplwi    r29, 0
	  beq-      .loc_0x244
	  lwz       r3, 0x14(r29)
	  li        r31, 0
	  rlwinm    r30,r31,2,0,29
	  addi      r0, r3, 0x1
	  stw       r0, 0x14(r29)
	  lis       r26, 0x4330
	  stw       r31, 0x2F0C(r13)
	  lfs       f30, -0x785C(r2)
	  stw       r31, 0x2F08(r13)
	  lfd       f31, -0x7858(r2)
	  stw       r31, 0x2F10(r13)
	  b         .loc_0x1E4

	.loc_0x74:
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r30
	  lfs       f1, 0x1C(r3)
	  bl        0x1B5E34
	  lwz       r3, 0x4(r29)
	  li        r0, 0
	  lwzx      r3, r3, r30
	  addi      r4, r3, 0x1C
	  lfs       f1, 0x18(r3)
	  lfs       f0, 0x1C(r3)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xE0
	  lwz       r0, 0x24(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0xB8
	  lfs       f3, -0x7894(r2)
	  b         .loc_0xBC

	.loc_0xB8:
	  lfs       f3, -0x7878(r2)

	.loc_0xBC:
	  lwz       r3, 0x2DEC(r13)
	  fsubs     f1, f1, f0
	  lfs       f2, 0x0(r4)
	  li        r0, 0x1
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f3, f0
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r4)

	.loc_0xE0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x1DC
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r30
	  lbz       r0, 0x2C(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x104
	  lwz       r4, 0x10(r29)
	  bl        0x3CC

	.loc_0x104:
	  lwz       r3, 0x4(r29)
	  li        r0, 0
	  lwzx      r3, r3, r30
	  stb       r0, 0x2C(r3)
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r30
	  lfs       f1, 0x1C(r3)
	  bl        0x1B5D94
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x13C
	  lwz       r3, 0x4(r29)
	  lwzx      r3, r3, r30
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)

	.loc_0x13C:
	  lwz       r3, 0x4(r29)
	  li        r0, 0xFF
	  lwzx      r6, r3, r30
	  lbz       r3, 0x10(r6)
	  lbz       r4, 0x11(r6)
	  stw       r3, 0xEC(r1)
	  lbz       r3, 0x12(r6)
	  stw       r26, 0xE8(r1)
	  stw       r4, 0xFC(r1)
	  lfd       f0, 0xE8(r1)
	  stw       r3, 0x10C(r1)
	  fsubs     f0, f0, f31
	  stw       r26, 0xF8(r1)
	  stw       r26, 0x108(r1)
	  fmuls     f0, f1, f0
	  lfd       f2, 0xF8(r1)
	  lfd       f3, 0x108(r1)
	  fsubs     f2, f2, f31
	  fctiwz    f0, f0
	  fsubs     f3, f3, f31
	  fmuls     f2, f1, f2
	  stfd      f0, 0xE0(r1)
	  fmuls     f1, f1, f3
	  fctiwz    f0, f2
	  lwz       r3, 0xE4(r1)
	  fctiwz    f1, f1
	  stb       r3, 0xC(r6)
	  stfd      f0, 0xF0(r1)
	  stfd      f1, 0x100(r1)
	  lwz       r4, 0xF4(r1)
	  lwz       r3, 0x104(r1)
	  stb       r4, 0xD(r6)
	  stb       r3, 0xE(r6)
	  stb       r0, 0xF(r6)
	  lwz       r3, 0x4(r29)
	  lwz       r4, 0x14(r29)
	  lwzx      r3, r3, r30
	  lwz       r5, 0x10(r29)
	  lwz       r6, 0x0(r29)
	  bl        .loc_0x438

	.loc_0x1DC:
	  addi      r30, r30, 0x4
	  addi      r31, r31, 0x1

	.loc_0x1E4:
	  lwz       r0, 0xC(r29)
	  cmpw      r31, r0
	  blt+      .loc_0x74
	  lwz       r4, 0x2F10(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x244
	  b         .loc_0x23C

	.loc_0x200:
	  lha       r0, 0xC(r4)
	  cmpwi     r0, 0xFF
	  bge-      .loc_0x214
	  rlwinm    r0,r0,0,24,31
	  b         .loc_0x218

	.loc_0x214:
	  li        r0, 0xFF

	.loc_0x218:
	  lwz       r3, 0x8(r4)
	  stb       r0, 0x0(r3)
	  lwz       r3, 0x8(r4)
	  stb       r0, 0x1(r3)
	  lwz       r3, 0x8(r4)
	  stb       r0, 0x2(r3)
	  lwz       r3, 0x8(r4)
	  stb       r0, 0x3(r3)
	  lwz       r4, 0x4(r4)

	.loc_0x23C:
	  cmplwi    r4, 0
	  bne+      .loc_0x200

	.loc_0x244:
	  lwz       r0, 0x60(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x41C
	  addi      r3, r27, 0x64
	  li        r4, 0
	  bl        -0x36FF0
	  li        r0, 0x1
	  stw       r0, 0x324(r28)
	  addi      r6, r1, 0x3C
	  addi      r5, r1, 0x48
	  lfs       f2, -0x6C1C(r13)
	  addi      r4, r1, 0x54
	  lfs       f1, -0x6C28(r13)
	  addi      r3, r1, 0x60
	  lfs       f0, -0x6C34(r13)
	  stfs      f2, 0x3C(r1)
	  lfs       f2, -0x6C18(r13)
	  stfs      f1, 0x48(r1)
	  lfs       f1, -0x6C24(r13)
	  stfs      f0, 0x54(r1)
	  lfs       f0, -0x6C30(r13)
	  stfs      f2, 0x40(r1)
	  lfs       f2, -0x6C14(r13)
	  stfs      f1, 0x4C(r1)
	  lfs       f1, -0x6C20(r13)
	  stfs      f0, 0x58(r1)
	  lfs       f0, -0x6C2C(r13)
	  stfs      f2, 0x44(r1)
	  stfs      f1, 0x50(r1)
	  stfs      f0, 0x5C(r1)
	  bl        -0x27FFC
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r1, 0x60
	  addi      r5, r1, 0xA0
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0x1
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x300
	  stw       r0, 0x4(r28)
	  addi      r4, r28, 0
	  addi      r5, r1, 0xA0
	  lwz       r3, 0x60(r27)
	  li        r6, 0
	  bl        -0x30E30
	  lwz       r12, 0x3B4(r28)
	  lis       r4, 0x803A
	  mr        r3, r28
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x60(r27)
	  mr        r4, r28
	  lwz       r5, 0x2E4(r28)
	  addi      r6, r27, 0x64
	  bl        -0x36484
	  li        r0, 0x700
	  stw       r0, 0x4(r28)
	  li        r0, 0
	  stw       r0, 0x324(r28)
	  lwz       r3, 0x88(r27)
	  lwz       r26, 0x10(r3)
	  b         .loc_0x3E4

	.loc_0x364:
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r26, 0x5C
	  addi      r5, r26, 0xDC
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r26, 0xDC
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stw       r0, 0x324(r28)
	  addi      r3, r28, 0
	  li        r4, 0x1
	  lwz       r12, 0x3B4(r28)
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r28
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  stw       r0, 0x324(r28)
	  lwz       r26, 0xC(r26)

	.loc_0x3E4:
	  cmplwi    r26, 0
	  bne+      .loc_0x364
	  lwz       r3, 0x108(r27)
	  lwz       r26, 0x10(r3)
	  b         .loc_0x414

	.loc_0x3F8:
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  mr        r4, r28
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r26, 0xC(r26)

	.loc_0x414:
	  cmplwi    r26, 0
	  bne+      .loc_0x3F8

	.loc_0x41C:
	  lmw       r26, 0x110(r1)
	  lwz       r0, 0x13C(r1)
	  lfd       f31, 0x130(r1)
	  lfd       f30, 0x128(r1)
	  addi      r1, r1, 0x138
	  mtlr      r0
	  blr

	.loc_0x438:
	*/
}

/*
 * --INFO--
 * Address:	8006626C
 * Size:	000094
 */
void SoftLight::addLight(u32, LShortColour*, Shape*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  beqlr-
	  li        r7, 0
	  addi      r8, r7, 0
	  li        r9, 0
	  b         .loc_0x84

	.loc_0x1C:
	  lwz       r5, 0x30(r3)
	  lwzx      r5, r5, r7
	  lwz       r0, 0x0(r5)
	  cmplw     r4, r0
	  beq-      .loc_0x50
	  lwz       r0, 0x2F10(r13)
	  stw       r0, 0x4(r5)
	  lwz       r5, 0x30(r3)
	  lwzx      r0, r5, r7
	  stw       r0, 0x2F10(r13)
	  lwz       r5, 0x30(r3)
	  lwzx      r5, r5, r7
	  stw       r4, 0x0(r5)

	.loc_0x50:
	  lwz       r5, 0x34(r3)
	  addi      r9, r9, 0x1
	  lwz       r6, 0x30(r3)
	  lhax      r0, r5, r8
	  addi      r8, r8, 0x2
	  lbz       r5, 0xC(r3)
	  lwzx      r6, r6, r7
	  addi      r7, r7, 0x4
	  mullw     r0, r5, r0
	  lha       r5, 0xC(r6)
	  srawi     r0, r0, 0x8
	  add       r0, r5, r0
	  sth       r0, 0xC(r6)

	.loc_0x84:
	  lwz       r0, 0x28(r3)
	  cmpw      r9, r0
	  blt+      .loc_0x1C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80066300
 * Size:	000060
 */
void SoftLight::subLight(LShortColour*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x30(r3)
	  cmplwi    r0, 0
	  beqlr-
	  li        r6, 0
	  addi      r7, r6, 0
	  li        r8, 0
	  b         .loc_0x50

	.loc_0x1C:
	  lwz       r5, 0x34(r3)
	  addi      r8, r8, 0x1
	  lwz       r4, 0x30(r3)
	  lhax      r0, r5, r6
	  addi      r6, r6, 0x2
	  lbz       r5, 0xC(r3)
	  lwzx      r4, r4, r7
	  addi      r7, r7, 0x4
	  mullw     r5, r5, r0
	  lha       r0, 0xC(r4)
	  srawi     r5, r5, 0x8
	  sub       r0, r0, r5
	  sth       r0, 0xC(r4)

	.loc_0x50:
	  lwz       r0, 0x28(r3)
	  cmpw      r8, r0
	  blt+      .loc_0x1C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80066360
 * Size:	00078C
 */
void MapMgr::showCollisions(Vector3f&)
{
	/*
	.loc_0x0:
	  stwu      r1, -0xF8(r1)
	  lis       r5, 0x4330
	  lwz       r6, 0x0(r4)
	  lwz       r0, 0x4(r4)
	  stw       r6, 0xB4(r3)
	  stw       r0, 0xB8(r3)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0xBC(r3)
	  lfs       f6, 0x90(r3)
	  lfs       f0, 0xB4(r3)
	  lfs       f5, -0x7850(r2)
	  fsubs     f1, f0, f6
	  lfs       f7, 0x98(r3)
	  lfs       f0, 0xBC(r3)
	  lfd       f3, -0x7848(r2)
	  fmuls     f2, f1, f5
	  fsubs     f1, f0, f7
	  lfs       f4, -0x784C(r2)
	  lfs       f0, -0x6D18(r13)
	  fctiwz    f2, f2
	  stfs      f0, 0xC0(r3)
	  fmuls     f1, f1, f5
	  stfd      f2, 0xF0(r1)
	  lfs       f0, -0x6D14(r13)
	  lwz       r0, 0xF4(r1)
	  fctiwz    f1, f1
	  stfs      f0, 0xC4(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0xEC(r1)
	  lfs       f0, -0x6D10(r13)
	  stfd      f1, 0xE0(r1)
	  stw       r5, 0xE8(r1)
	  lwz       r0, 0xE4(r1)
	  stfs      f0, 0xC8(r3)
	  lfd       f1, 0xE8(r1)
	  xoris     r0, r0, 0x8000
	  lfs       f0, -0x6D0C(r13)
	  stw       r0, 0xDC(r1)
	  fsubs     f1, f1, f3
	  stfs      f0, 0xCC(r3)
	  fmuls     f0, f1, f4
	  stw       r5, 0xD8(r1)
	  lfs       f1, -0x6D08(r13)
	  lfd       f2, 0xD8(r1)
	  fadds     f0, f6, f0
	  stfs      f1, 0xD0(r3)
	  fsubs     f2, f2, f3
	  lfs       f1, -0x6D04(r13)
	  fsubs     f5, f0, f4
	  stfs      f1, 0xD4(r3)
	  fmuls     f1, f2, f4
	  lfs       f2, 0xC0(r3)
	  lfs       f3, 0x94(r3)
	  fadds     f1, f7, f1
	  fcmpo     cr0, f5, f2
	  fsubs     f3, f3, f4
	  fsubs     f4, f1, f4
	  bge-      .loc_0xEC
	  stfs      f5, 0xC0(r3)

	.loc_0xEC:
	  lfs       f2, 0xC4(r3)
	  fcmpo     cr0, f3, f2
	  bge-      .loc_0xFC
	  stfs      f3, 0xC4(r3)

	.loc_0xFC:
	  lfs       f2, 0xC8(r3)
	  fcmpo     cr0, f4, f2
	  bge-      .loc_0x10C
	  stfs      f4, 0xC8(r3)

	.loc_0x10C:
	  lfs       f2, 0xCC(r3)
	  fcmpo     cr0, f5, f2
	  ble-      .loc_0x11C
	  stfs      f5, 0xCC(r3)

	.loc_0x11C:
	  lfs       f2, 0xD0(r3)
	  fcmpo     cr0, f3, f2
	  ble-      .loc_0x12C
	  stfs      f3, 0xD0(r3)

	.loc_0x12C:
	  lfs       f2, 0xD4(r3)
	  fcmpo     cr0, f4, f2
	  ble-      .loc_0x13C
	  stfs      f4, 0xD4(r3)

	.loc_0x13C:
	  lfs       f6, -0x784C(r2)
	  lfs       f4, 0xA0(r3)
	  fadds     f3, f0, f6
	  lfs       f2, 0xC0(r3)
	  fadds     f5, f1, f6
	  fadds     f4, f4, f6
	  fadds     f7, f6, f3
	  fadds     f3, f6, f5
	  fcmpo     cr0, f7, f2
	  bge-      .loc_0x168
	  stfs      f7, 0xC0(r3)

	.loc_0x168:
	  lfs       f2, 0xC4(r3)
	  fcmpo     cr0, f4, f2
	  bge-      .loc_0x178
	  stfs      f4, 0xC4(r3)

	.loc_0x178:
	  lfs       f2, 0xC8(r3)
	  fcmpo     cr0, f3, f2
	  bge-      .loc_0x188
	  stfs      f3, 0xC8(r3)

	.loc_0x188:
	  lfs       f2, 0xCC(r3)
	  fcmpo     cr0, f7, f2
	  ble-      .loc_0x198
	  stfs      f7, 0xCC(r3)

	.loc_0x198:
	  lfs       f2, 0xD0(r3)
	  fcmpo     cr0, f4, f2
	  ble-      .loc_0x1A8
	  stfs      f4, 0xD0(r3)

	.loc_0x1A8:
	  lfs       f2, 0xD4(r3)
	  fcmpo     cr0, f3, f2
	  ble-      .loc_0x1B8
	  stfs      f3, 0xD4(r3)

	.loc_0x1B8:
	  lfs       f2, -0x6D18(r13)
	  stfs      f2, 0xD8(r3)
	  lfs       f2, -0x6D14(r13)
	  stfs      f2, 0xDC(r3)
	  lfs       f2, -0x6D10(r13)
	  stfs      f2, 0xE0(r3)
	  lfs       f2, -0x6D0C(r13)
	  stfs      f2, 0xE4(r3)
	  lfs       f2, -0x6D08(r13)
	  stfs      f2, 0xE8(r3)
	  lfs       f2, -0x6D04(r13)
	  stfs      f2, 0xEC(r3)
	  lfs       f2, 0xD8(r3)
	  lfs       f4, 0x94(r3)
	  lfs       f3, -0x784C(r2)
	  fcmpo     cr0, f0, f2
	  fsubs     f3, f4, f3
	  bge-      .loc_0x204
	  stfs      f0, 0xD8(r3)

	.loc_0x204:
	  lfs       f2, 0xDC(r3)
	  fcmpo     cr0, f3, f2
	  bge-      .loc_0x214
	  stfs      f3, 0xDC(r3)

	.loc_0x214:
	  lfs       f2, 0xE0(r3)
	  fcmpo     cr0, f1, f2
	  bge-      .loc_0x224
	  stfs      f1, 0xE0(r3)

	.loc_0x224:
	  lfs       f2, 0xE4(r3)
	  fcmpo     cr0, f0, f2
	  ble-      .loc_0x234
	  stfs      f0, 0xE4(r3)

	.loc_0x234:
	  lfs       f2, 0xE8(r3)
	  fcmpo     cr0, f3, f2
	  ble-      .loc_0x244
	  stfs      f3, 0xE8(r3)

	.loc_0x244:
	  lfs       f2, 0xEC(r3)
	  fcmpo     cr0, f1, f2
	  ble-      .loc_0x254
	  stfs      f1, 0xEC(r3)

	.loc_0x254:
	  lfs       f3, -0x784C(r2)
	  lfs       f2, 0xA0(r3)
	  fadds     f4, f0, f3
	  lfs       f0, 0xD8(r3)
	  fadds     f5, f1, f3
	  fadds     f1, f2, f3
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x278
	  stfs      f4, 0xD8(r3)

	.loc_0x278:
	  lfs       f0, 0xDC(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x288
	  stfs      f1, 0xDC(r3)

	.loc_0x288:
	  lfs       f0, 0xE0(r3)
	  fcmpo     cr0, f5, f0
	  bge-      .loc_0x298
	  stfs      f5, 0xE0(r3)

	.loc_0x298:
	  lfs       f0, 0xE4(r3)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x2A8
	  stfs      f4, 0xE4(r3)

	.loc_0x2A8:
	  lfs       f0, 0xE8(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2B8
	  stfs      f1, 0xE8(r3)

	.loc_0x2B8:
	  lfs       f0, 0xEC(r3)
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x2C8
	  stfs      f5, 0xEC(r3)

	.loc_0x2C8:
	  lwz       r5, 0xD8(r3)
	  lis       r6, 0x803A
	  lwz       r0, 0xDC(r3)
	  stwu      r5, -0x2240(r6)
	  stw       r0, 0x4(r6)
	  lwz       r5, 0xE0(r3)
	  lwz       r0, 0xE4(r3)
	  stw       r5, 0x8(r6)
	  stw       r0, 0xC(r6)
	  lwz       r5, 0xE8(r3)
	  lwz       r0, 0xEC(r3)
	  stw       r5, 0x10(r6)
	  stw       r0, 0x14(r6)
	  lfs       f0, -0x78B0(r2)
	  stfs      f0, 0xAC(r1)
	  stfs      f0, 0xA8(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f0, 0xB8(r1)
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xB0(r1)
	  lfs       f1, -0x6D18(r13)
	  lfs       f0, -0x6D14(r13)
	  stfs      f1, 0xA4(r1)
	  stfs      f0, 0xA8(r1)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0xAC(r1)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0xB0(r1)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0xB4(r1)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0xB8(r1)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0xA4(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x35C
	  stfs      f1, 0xA4(r1)

	.loc_0x35C:
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0xA8(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x370
	  stfs      f1, 0xA8(r1)

	.loc_0x370:
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0xAC(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x384
	  stfs      f1, 0xAC(r1)

	.loc_0x384:
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0xB0(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x398
	  stfs      f1, 0xB0(r1)

	.loc_0x398:
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0xB4(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3AC
	  stfs      f1, 0xB4(r1)

	.loc_0x3AC:
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0xB8(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3C0
	  stfs      f1, 0xB8(r1)

	.loc_0x3C0:
	  lfs       f2, 0xA4(r1)
	  li        r5, 0
	  lfs       f1, -0x6C10(r13)
	  lfs       f0, -0x6C0C(r13)
	  fsubs     f1, f2, f1
	  stfs      f1, 0xA4(r1)
	  lfs       f1, 0xA8(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f1, 0xAC(r1)
	  lfs       f0, -0x6C08(r13)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xAC(r1)
	  lfs       f1, 0xB0(r1)
	  lfs       f0, -0x6C04(r13)
	  fadds     f0, f1, f0
	  stfs      f0, 0xB0(r1)
	  lfs       f1, 0xB4(r1)
	  lfs       f0, -0x6C00(r13)
	  fadds     f0, f1, f0
	  stfs      f0, 0xB4(r1)
	  lfs       f1, 0xB8(r1)
	  lfs       f0, -0x6BFC(r13)
	  fadds     f0, f1, f0
	  stfs      f0, 0xB8(r1)
	  lwz       r6, 0x88(r3)
	  lwz       r9, 0x10(r6)
	  b         .loc_0x534

	.loc_0x430:
	  lfs       f1, 0x44(r9)
	  lfs       f0, 0xB0(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x4B0
	  lfs       f1, 0x50(r9)
	  lfs       f0, 0xA4(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4B0
	  lfs       f1, 0x48(r9)
	  lfs       f0, 0xB4(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x4B0
	  lfs       f1, 0x54(r9)
	  lfs       f0, 0xA8(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4B0
	  lfs       f1, 0x4C(r9)
	  lfs       f0, 0xB8(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x4B0
	  lfs       f1, 0x58(r9)
	  lfs       f0, 0xAC(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4B0
	  li        r0, 0x1
	  b         .loc_0x4B4

	.loc_0x4B0:
	  li        r0, 0

	.loc_0x4B4:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x530
	  li        r10, 0
	  li        r8, 0
	  b         .loc_0x524

	.loc_0x4C8:
	  lwz       r6, 0x40(r9)
	  lwz       r7, 0x38(r9)
	  lwzx      r6, r6, r8
	  lwz       r0, 0x18(r6)
	  lbzx      r0, r7, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x51C
	  lwz       r0, 0x2C(r9)
	  stw       r0, 0x10(r6)
	  lwz       r6, 0x40(r9)
	  lwz       r0, 0x30(r9)
	  lwzx      r6, r6, r8
	  stw       r0, 0x14(r6)
	  lwz       r6, 0x40(r9)
	  lwzx      r6, r6, r8
	  stw       r9, 0x1C(r6)
	  lwz       r6, 0x40(r9)
	  lwzx      r6, r6, r8
	  stw       r5, 0x20(r6)
	  lwz       r5, 0x40(r9)
	  lwzx      r5, r5, r8

	.loc_0x51C:
	  addi      r8, r8, 0x4
	  addi      r10, r10, 0x1

	.loc_0x524:
	  lwz       r0, 0x3C(r9)
	  cmpw      r10, r0
	  blt+      .loc_0x4C8

	.loc_0x530:
	  lwz       r9, 0xC(r9)

	.loc_0x534:
	  cmplwi    r9, 0
	  bne+      .loc_0x430
	  lwz       r8, 0x60(r3)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x140(r8)
	  lfs       f3, 0x158(r8)
	  fsubs     f2, f1, f0
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x148(r8)
	  fdivs     f2, f2, f3
	  fctiwz    f2, f2
	  fsubs     f0, f1, f0
	  stfd      f2, 0xE8(r1)
	  fdivs     f0, f0, f3
	  lwz       r0, 0xEC(r1)
	  stfd      f2, 0xD8(r1)
	  cmpwi     r0, 0
	  lwz       r6, 0xDC(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0xE0(r1)
	  lwz       r4, 0xE4(r1)
	  blt-      .loc_0x5AC
	  cmpwi     r4, 0
	  blt-      .loc_0x5AC
	  lwz       r7, 0x15C(r8)
	  cmpw      r6, r7
	  bge-      .loc_0x5AC
	  lwz       r0, 0x160(r8)
	  cmpw      r4, r0
	  blt-      .loc_0x5B4

	.loc_0x5AC:
	  li        r6, 0
	  b         .loc_0x5C8

	.loc_0x5B4:
	  mullw     r0, r4, r7
	  lwz       r4, 0x164(r8)
	  add       r0, r6, r0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r6, r4, r0

	.loc_0x5C8:
	  cmplwi    r6, 0
	  beq-      .loc_0x5FC
	  lha       r0, 0x4(r6)
	  cmpwi     r0, 0
	  beq-      .loc_0x5FC
	  stw       r8, 0x10(r6)
	  li        r0, 0
	  lwz       r4, 0x60(r3)
	  lwz       r4, 0x23C(r4)
	  stw       r4, 0x14(r6)
	  stw       r0, 0x1C(r6)
	  stw       r5, 0x20(r6)
	  mr        r5, r6

	.loc_0x5FC:
	  lbz       r0, -0x5F17(r13)
	  b         .loc_0x774

	.loc_0x604:
	  cmplwi    r5, 0
	  beq-      .loc_0x770
	  lha       r7, 0x4(r5)
	  extsh.    r4, r7
	  beq-      .loc_0x770
	  lha       r4, 0x6(r5)
	  lwz       r6, 0xAC(r3)
	  sub       r4, r7, r4
	  add       r4, r6, r4
	  stw       r4, 0xAC(r3)
	  lha       r8, 0x6(r5)
	  lha       r4, 0x4(r5)
	  cmpw      r4, r8
	  sub       r6, r4, r8
	  bne-      .loc_0x688
	  cmpwi     r8, 0
	  li        r9, 0
	  ble-      .loc_0x688
	  cmpwi     r8, 0x8
	  subi      r7, r8, 0x8
	  ble-      .loc_0x674
	  addi      r4, r7, 0x7
	  rlwinm    r4,r4,29,3,31
	  cmpwi     r7, 0
	  mtctr     r4
	  ble-      .loc_0x674

	.loc_0x66C:
	  addi      r9, r9, 0x8
	  bdnz+     .loc_0x66C

	.loc_0x674:
	  sub       r4, r8, r9
	  cmpw      r9, r8
	  mtctr     r4
	  bge-      .loc_0x688

	.loc_0x684:
	  bdnz-     .loc_0x684

	.loc_0x688:
	  li        r7, 0
	  li        r4, 0
	  b         .loc_0x764

	.loc_0x694:
	  lwz       r10, 0xA8(r3)
	  lwz       r8, 0xB0(r3)
	  cmpw      r10, r8
	  bge-      .loc_0x75C
	  cmplwi    r0, 0
	  beq-      .loc_0x710
	  cmpw      r7, r6
	  bge-      .loc_0x6CC
	  mulli     r8, r10, 0xC
	  lwz       r9, 0xF0(r3)
	  addi      r8, r8, 0x8
	  li        r10, 0
	  stwx      r10, r9, r8
	  b         .loc_0x724

	.loc_0x6CC:
	  lwz       r9, 0xC(r5)
	  sub       r8, r7, r6
	  lbzx      r8, r9, r8
	  cmplwi    r8, 0x10
	  bge-      .loc_0x6F8
	  mulli     r8, r10, 0xC
	  lwz       r9, 0xF0(r3)
	  addi      r8, r8, 0x8
	  li        r10, 0x2
	  stwx      r10, r9, r8
	  b         .loc_0x724

	.loc_0x6F8:
	  mulli     r8, r10, 0xC
	  lwz       r9, 0xF0(r3)
	  addi      r8, r8, 0x8
	  li        r10, 0x1
	  stwx      r10, r9, r8
	  b         .loc_0x724

	.loc_0x710:
	  mulli     r8, r10, 0xC
	  lwz       r9, 0xF0(r3)
	  addi      r8, r8, 0x8
	  li        r10, 0
	  stwx      r10, r9, r8

	.loc_0x724:
	  lwz       r8, 0xA8(r3)
	  lwz       r9, 0xF0(r3)
	  mulli     r8, r8, 0xC
	  stwx      r5, r9, r8
	  lwz       r8, 0xA8(r3)
	  lwz       r10, 0x8(r5)
	  mulli     r8, r8, 0xC
	  lwz       r9, 0xF0(r3)
	  lwzx      r10, r10, r4
	  addi      r8, r8, 0x4
	  stwx      r10, r9, r8
	  lwz       r8, 0xA8(r3)
	  addi      r8, r8, 0x1
	  stw       r8, 0xA8(r3)

	.loc_0x75C:
	  addi      r4, r4, 0x4
	  addi      r7, r7, 0x1

	.loc_0x764:
	  lha       r8, 0x4(r5)
	  cmpw      r7, r8
	  blt+      .loc_0x694

	.loc_0x770:
	  lwz       r5, 0x20(r5)

	.loc_0x774:
	  cmplwi    r5, 0
	  bne+      .loc_0x604
	  b         .loc_0x784
	  b         .loc_0x674

	.loc_0x784:
	  addi      r1, r1, 0xF8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void MapMgr::closeCollTri(CollGroup*, CollTriInfo*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80066AEC
 * Size:	000160
 */
void MapMgr::drawXLU(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stw       r31, 0xBC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xB8(r1)
	  mr        r30, r3
	  lwz       r0, 0x60(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x148
	  lwz       r3, 0x4(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        0x8474
	  li        r0, 0x1
	  stw       r0, 0x324(r31)
	  addi      r6, r1, 0x10
	  addi      r5, r1, 0x1C
	  lfs       f2, -0x6BE0(r13)
	  addi      r4, r1, 0x28
	  lfs       f1, -0x6BEC(r13)
	  addi      r3, r1, 0x34
	  lfs       f0, -0x6BF8(r13)
	  stfs      f2, 0x10(r1)
	  lfs       f2, -0x6BDC(r13)
	  stfs      f1, 0x1C(r1)
	  lfs       f1, -0x6BE8(r13)
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x6BF4(r13)
	  stfs      f2, 0x14(r1)
	  lfs       f2, -0x6BD8(r13)
	  stfs      f1, 0x20(r1)
	  lfs       f1, -0x6BE4(r13)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, -0x6BF0(r13)
	  stfs      f2, 0x18(r1)
	  stfs      f1, 0x24(r1)
	  stfs      f0, 0x30(r1)
	  bl        -0x28A90
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x34
	  addi      r5, r1, 0x74
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x74
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x1
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x400
	  stw       r0, 0x4(r31)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x74
	  lwz       r3, 0x60(r30)
	  li        r6, 0
	  bl        -0x318E0
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x60(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  addi      r6, r30, 0x64
	  bl        -0x367BC
	  li        r0, 0x700
	  stw       r0, 0x4(r31)

	.loc_0x148:
	  lwz       r0, 0xC4(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80066C4C
 * Size:	000EDC
 */
void MapMgr::postrefresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x468(r1)
	  stfd      f31, 0x460(r1)
	  stfd      f30, 0x458(r1)
	  stfd      f29, 0x450(r1)
	  stmw      r21, 0x424(r1)
	  mr        r30, r3
	  addi      r31, r4, 0
	  lwz       r0, 0x60(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xEBC
	  lwz       r3, 0x4(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        0x830C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0xFFC
	  lwz       r3, 0x2EAC(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  bl        -0xAE10
	  lwz       r3, 0x2EAC(r13)
	  mr        r4, r31
	  bl        -0xADDC

	.loc_0x68:
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  bl        -0x3E60C
	  lwz       r3, 0x2DEC(r13)
	  mr        r4, r31
	  bl        -0x2715C
	  lwz       r3, 0x3180(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0xB0
	  mr        r4, r31
	  bl        0x135CF8

	.loc_0xB0:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x340
	  lwz       r7, 0x310(r31)
	  li        r0, 0
	  lwz       r6, 0x30C(r31)
	  addi      r5, r1, 0x1C4
	  addi      r3, r31, 0
	  stw       r0, 0x1C4(r1)
	  addi      r4, r1, 0x380
	  stw       r0, 0x1C8(r1)
	  stw       r6, 0x1CC(r1)
	  stw       r7, 0x1D0(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x3B4(r31)
	  mr        r22, r0
	  li        r4, 0
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  li        r21, 0xFF
	  stb       r21, 0x1C0(r1)
	  addi      r4, r1, 0x1C0
	  addi      r3, r31, 0
	  stb       r21, 0x1C1(r1)
	  li        r5, 0x1
	  stb       r21, 0x1C2(r1)
	  stb       r21, 0x1C3(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r21, 0x1BC(r1)
	  addi      r4, r1, 0x1BC
	  addi      r3, r31, 0
	  stb       r21, 0x1BD(r1)
	  stb       r21, 0x1BE(r1)
	  stb       r21, 0x1BF(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4B4(r30)
	  li        r6, 0
	  li        r7, 0x1
	  lhz       r4, 0x8(r3)
	  lhz       r5, 0xA(r3)
	  bl        -0x227A4
	  mr        r3, r31
	  lwz       r4, 0x4B8(r30)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x4B4(r30)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0x1
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x200
	  lfs       f0, -0x78B0(r2)
	  lwz       r3, 0x2E4(r31)
	  stfs      f0, 0x344(r3)

	.loc_0x200:
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x6
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x2E4(r31)
	  addi      r6, r3, 0
	  li        r0, 0xFF
	  lfs       f0, 0x344(r5)
	  addi      r4, r1, 0x1B8
	  addi      r3, r31, 0
	  fctiwz    f0, f0
	  stb       r0, 0x1B8(r1)
	  mr        r21, r6
	  stb       r0, 0x1B9(r1)
	  li        r5, 0
	  stfd      f0, 0x418(r1)
	  stb       r0, 0x1BA(r1)
	  lwz       r0, 0x41C(r1)
	  stb       r0, 0x1BB(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xB0(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x310(r31)
	  li        r0, 0
	  lwz       r5, 0x30C(r31)
	  addi      r4, r1, 0x1A8
	  addi      r3, r31, 0
	  stw       r0, 0x1A8(r1)
	  stw       r0, 0x1AC(r1)
	  stw       r5, 0x1B0(r1)
	  stw       r6, 0x1B4(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xD8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  mr        r4, r21
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4B8(r30)
	  li        r6, 0
	  li        r7, 0x1
	  lhz       r4, 0x8(r3)
	  lhz       r5, 0xA(r3)
	  bl        -0x228C8
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x1
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r22, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r5, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  lfs       f1, 0x1CC(r5)
	  addi      r4, r5, 0x260
	  lwz       r12, 0x3C(r12)
	  lfs       f2, 0x1C4(r5)
	  mtlr      r12
	  lfs       f3, 0x1D0(r5)
	  lfs       f4, 0x1D4(r5)
	  lfs       f5, -0x7884(r2)
	  blrl

	.loc_0x340:
	  lfs       f2, 0x4C4(r30)
	  lfs       f0, 0x4CC(r30)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x380
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7894(r2)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4C4(r30)
	  lfs       f0, 0x4C4(r30)
	  lfs       f1, 0x4CC(r30)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x3B0
	  stfs      f1, 0x4C4(r30)
	  b         .loc_0x3B0

	.loc_0x380:
	  ble-      .loc_0x3B0
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7894(r2)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x4C4(r30)
	  lfs       f0, 0x4C4(r30)
	  lfs       f1, 0x4CC(r30)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x3B0
	  stfs      f1, 0x4C4(r30)

	.loc_0x3B0:
	  lfs       f2, 0x4C0(r30)
	  lfs       f0, 0x4C8(r30)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x3F0
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7894(r2)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x4C0(r30)
	  lfs       f0, 0x4C0(r30)
	  lfs       f1, 0x4C8(r30)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x420
	  stfs      f1, 0x4C0(r30)
	  b         .loc_0x420

	.loc_0x3F0:
	  ble-      .loc_0x420
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7894(r2)
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x4C0(r30)
	  lfs       f0, 0x4C0(r30)
	  lfs       f1, 0x4C8(r30)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x420
	  stfs      f1, 0x4C0(r30)

	.loc_0x420:
	  lfs       f0, 0x4C0(r30)
	  lfs       f1, -0x78B0(r2)
	  fcmpo     cr0, f0, f1
	  bgt-      .loc_0x43C
	  lfs       f0, 0x4C4(r30)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x5EC

	.loc_0x43C:
	  lwz       r6, 0x310(r31)
	  li        r21, 0
	  lwz       r0, 0x30C(r31)
	  addi      r5, r1, 0x198
	  addi      r3, r31, 0
	  stw       r21, 0x198(r1)
	  addi      r4, r1, 0x340
	  stw       r21, 0x19C(r1)
	  stw       r0, 0x1A0(r1)
	  stw       r6, 0x1A4(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x3
	  bl        0x1AC57C
	  lfs       f1, -0x7840(r2)
	  li        r0, 0xA0
	  lfs       f0, 0x4C0(r30)
	  addi      r4, r1, 0x194
	  addi      r3, r31, 0
	  fmuls     f0, f1, f0
	  stb       r0, 0x194(r1)
	  li        r5, 0x1
	  stb       r0, 0x195(r1)
	  fctiwz    f0, f0
	  stb       r0, 0x196(r1)
	  stfd      f0, 0x418(r1)
	  lwz       r0, 0x41C(r1)
	  stb       r0, 0x197(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x4B8(r30)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x4B8(r30)
	  addi      r5, r1, 0x174
	  addi      r4, r1, 0x184
	  lhz       r7, 0xA(r6)
	  mr        r3, r31
	  lhz       r0, 0x8(r6)
	  li        r6, 0
	  stw       r21, 0x174(r1)
	  stw       r21, 0x178(r1)
	  stw       r0, 0x17C(r1)
	  stw       r7, 0x180(r1)
	  lwz       r7, 0x310(r31)
	  lwz       r0, 0x30C(r31)
	  stw       r21, 0x184(r1)
	  stw       r21, 0x188(r1)
	  stw       r0, 0x18C(r1)
	  stw       r7, 0x190(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xD0(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0x3
	  bl        0x1AC4AC
	  lfs       f0, 0x4C4(r30)
	  addi      r4, r1, 0x170
	  lfs       f1, -0x7840(r2)
	  mr        r3, r31
	  stb       r21, 0x170(r1)
	  fmuls     f0, f1, f0
	  li        r5, 0x1
	  stb       r21, 0x171(r1)
	  fctiwz    f0, f0
	  stb       r21, 0x172(r1)
	  stfd      f0, 0x410(r1)
	  lwz       r0, 0x414(r1)
	  stb       r0, 0x173(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0x160
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r21, 0x160(r1)
	  stw       r21, 0x164(r1)
	  stw       r0, 0x168(r1)
	  stw       r5, 0x16C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xD4(r12)
	  mtlr      r12
	  blrl

	.loc_0x5EC:
	  lwz       r0, 0xA8(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0xEAC
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x3B4(r31)
	  mr        r29, r0
	  li        r4, 0
	  lwz       r12, 0x30(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x3B4(r31)
	  mr        r28, r0
	  li        r4, 0
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  lfs       f0, -0x78B0(r2)
	  stb       r0, 0x334(r1)
	  lis       r3, 0x5555
	  li        r23, 0
	  stb       r0, 0x335(r1)
	  addi      r26, r3, 0x5556
	  li        r22, 0
	  stb       r23, 0x336(r1)
	  stb       r0, 0x337(r1)
	  stb       r0, 0x338(r1)
	  stb       r23, 0x339(r1)
	  stb       r23, 0x33A(r1)
	  stb       r0, 0x33B(r1)
	  stb       r23, 0x33C(r1)
	  stb       r23, 0x33D(r1)
	  stb       r0, 0x33E(r1)
	  stb       r0, 0x33F(r1)
	  stfs      f0, 0x318(r1)
	  stfs      f0, 0x314(r1)
	  stfs      f0, 0x310(r1)
	  stfs      f0, 0x324(r1)
	  stfs      f0, 0x320(r1)
	  stfs      f0, 0x31C(r1)
	  stfs      f0, 0x330(r1)
	  stfs      f0, 0x32C(r1)
	  stfs      f0, 0x328(r1)
	  b         .loc_0x960

	.loc_0x700:
	  lwz       r0, 0xF0(r30)
	  lfs       f5, -0x6BD4(r13)
	  add       r3, r0, r23
	  lwz       r4, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x4(r4)
	  lfsu      f0, 0x18(r4)
	  mulli     r0, r0, 0xC
	  lwz       r3, 0x14(r3)
	  lfs       f2, 0x4(r4)
	  fmuls     f1, f0, f5
	  lfs       f4, 0x8(r4)
	  add       r3, r3, r0
	  fmuls     f3, f2, f5
	  lfs       f0, 0x0(r3)
	  fmuls     f5, f4, f5
	  lfs       f2, 0x4(r3)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r3)
	  fadds     f2, f3, f2
	  stfs      f0, 0x310(r1)
	  fadds     f1, f5, f4
	  stfs      f2, 0x314(r1)
	  stfs      f1, 0x318(r1)
	  lwz       r0, 0xF0(r30)
	  lfs       f3, -0x6BD0(r13)
	  add       r3, r0, r23
	  lwz       r5, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x18(r5)
	  lwz       r0, 0x8(r5)
	  lfs       f2, 0x20(r5)
	  fmuls     f0, f0, f3
	  lfs       f1, 0x1C(r5)
	  mulli     r0, r0, 0xC
	  lwz       r3, 0x14(r3)
	  fmuls     f1, f1, f3
	  stfs      f0, 0xDC(r1)
	  fmuls     f2, f2, f3
	  add       r3, r3, r0
	  lfs       f0, 0xDC(r1)
	  stfs      f0, 0x13C(r1)
	  stfs      f1, 0x140(r1)
	  stfs      f2, 0x144(r1)
	  lfs       f1, 0x13C(r1)
	  lfs       f0, 0x0(r3)
	  lfs       f3, -0x6BCC(r13)
	  fadds     f0, f1, f0
	  stfs      f0, 0xD0(r1)
	  lfs       f0, 0xD0(r1)
	  stfs      f0, 0x148(r1)
	  lfs       f1, 0x140(r1)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x14C(r1)
	  lfs       f1, 0x144(r1)
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x150(r1)
	  lwz       r0, 0x148(r1)
	  lwz       r3, 0x14C(r1)
	  stw       r0, 0x31C(r1)
	  lwz       r0, 0x150(r1)
	  stw       r3, 0x320(r1)
	  stw       r0, 0x324(r1)
	  lwz       r0, 0xF0(r30)
	  add       r3, r0, r23
	  lwz       r5, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x18(r5)
	  lwz       r0, 0xC(r5)
	  lfs       f2, 0x20(r5)
	  fmuls     f0, f0, f3
	  lfs       f1, 0x1C(r5)
	  mulli     r0, r0, 0xC
	  lwz       r3, 0x14(r3)
	  fmuls     f1, f1, f3
	  stfs      f0, 0xCC(r1)
	  fmuls     f2, f2, f3
	  add       r3, r3, r0
	  lfs       f0, 0xCC(r1)
	  stfs      f0, 0x124(r1)
	  stfs      f1, 0x128(r1)
	  stfs      f2, 0x12C(r1)
	  lfs       f1, 0x124(r1)
	  lfs       f0, 0x0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC0(r1)
	  stfs      f0, 0x130(r1)
	  lfs       f1, 0x128(r1)
	  lfs       f0, 0x4(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x134(r1)
	  lfs       f1, 0x12C(r1)
	  li        r24, 0
	  lfs       f0, 0x8(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x138(r1)
	  lwz       r0, 0x130(r1)
	  lwz       r3, 0x134(r1)
	  stw       r0, 0x328(r1)
	  lwz       r0, 0x138(r1)
	  stw       r3, 0x32C(r1)
	  stw       r0, 0x330(r1)

	.loc_0x8A4:
	  mr        r3, r31
	  lwz       r5, 0xF0(r30)
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x334
	  addi      r0, r5, 0x8
	  lwzx      r0, r23, r0
	  li        r5, 0x1
	  lwz       r12, 0xA8(r12)
	  rlwinm    r0,r0,2,0,29
	  mtlr      r12
	  add       r4, r4, r0
	  blrl
	  mulhw     r5, r26, r24
	  addi      r4, r24, 0x1
	  mulhw     r3, r26, r4
	  rlwinm    r0,r5,1,31,31
	  add       r5, r5, r0
	  rlwinm    r0,r3,1,31,31
	  mulli     r5, r5, 0x3
	  add       r0, r3, r0
	  mulli     r0, r0, 0x3
	  addi      r3, r31, 0
	  sub       r5, r24, r5
	  lwz       r12, 0x3B4(r31)
	  sub       r0, r4, r0
	  lwz       r12, 0x98(r12)
	  mulli     r4, r5, 0xC
	  mtlr      r12
	  addi      r21, r1, 0x310
	  add       r21, r21, r4
	  mulli     r0, r0, 0xC
	  addi      r5, r1, 0x310
	  addi      r4, r21, 0
	  add       r5, r5, r0
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r21, 0
	  li        r5, 0x1
	  lwz       r12, 0x9C(r12)
	  mtlr      r12
	  blrl
	  addi      r24, r24, 0x1
	  cmpwi     r24, 0x3
	  blt+      .loc_0x8A4
	  addi      r23, r23, 0xC
	  addi      r22, r22, 0x1

	.loc_0x960:
	  lwz       r0, 0xA8(r30)
	  cmpw      r22, r0
	  blt+      .loc_0x700
	  li        r0, 0xFF
	  stb       r0, 0x120(r1)
	  addi      r4, r1, 0x120
	  addi      r3, r31, 0
	  stb       r0, 0x121(r1)
	  li        r5, 0x1
	  stb       r0, 0x122(r1)
	  stb       r0, 0x123(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, -0x786C(r2)
	  addi      r3, r1, 0x304
	  lfs       f1, 0xB8(r30)
	  lfs       f0, 0xB4(r30)
	  fadds     f1, f2, f1
	  stfs      f0, 0x304(r1)
	  stfs      f1, 0x308(r1)
	  lfs       f0, 0xBC(r30)
	  stfs      f0, 0x30C(r1)
	  lwz       r4, 0x2E4(r31)
	  addi      r4, r4, 0x1E0
	  bl        -0x2FEC8
	  lbz       r0, -0x5F17(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x9F4
	  lwz       r5, 0xAC(r30)
	  addi      r3, r1, 0x204
	  lwz       r6, 0xA8(r30)
	  crclr     6, 0x6
	  subi      r4, r13, 0x6BC4
	  bl        0x1AEF60
	  b         .loc_0xA08

	.loc_0x9F4:
	  lwz       r5, 0xA8(r30)
	  addi      r3, r1, 0x204
	  crclr     6, 0x6
	  subi      r4, r13, 0x6CA4
	  bl        0x1AEF48

	.loc_0xA08:
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x204
	  lwz       r3, 0x10(r3)
	  bl        -0x3F54C
	  lwz       r12, 0x3B4(r31)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r31, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x304
	  crclr     6, 0x6
	  addi      r8, r1, 0x204
	  li        r7, 0
	  blrl
	  lis       r3, 0x803A
	  lfd       f31, -0x7848(r2)
	  lfs       f29, -0x783C(r2)
	  subi      r27, r3, 0x2240
	  addi      r25, r1, 0xA4
	  addi      r24, r1, 0xA0
	  addi      r23, r1, 0x9C
	  li        r21, 0
	  li        r22, 0
	  lis       r26, 0x4330
	  b         .loc_0xDA8

	.loc_0xA9C:
	  lwz       r0, 0xF0(r30)
	  add       r4, r0, r22
	  lwz       r3, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x4(r3)
	  lwz       r3, 0x14(r4)
	  mulli     r0, r0, 0xC
	  add       r3, r3, r0
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x1F8(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x1FC(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x200(r1)
	  lwz       r0, 0xF0(r30)
	  add       r4, r0, r22
	  lwz       r3, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0x14(r4)
	  mulli     r0, r0, 0xC
	  add       r3, r3, r0
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x1EC(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x1F0(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x1F4(r1)
	  lwz       r0, 0xF0(r30)
	  add       r4, r0, r22
	  lwz       r3, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0xC(r3)
	  lwz       r3, 0x14(r4)
	  mulli     r0, r0, 0xC
	  add       r3, r3, r0
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x1E0(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x1E4(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x1E8(r1)
	  lfs       f0, 0x1F8(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x410(r1)
	  lwz       r0, 0x414(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x41C(r1)
	  stw       r26, 0x418(r1)
	  lfd       f0, 0x418(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x1F8(r1)
	  lfs       f0, 0x200(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x408(r1)
	  lwz       r0, 0x40C(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x404(r1)
	  stw       r26, 0x400(r1)
	  lfd       f0, 0x400(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x200(r1)
	  lfs       f0, 0x1EC(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x3F8(r1)
	  lwz       r0, 0x3FC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x3F4(r1)
	  stw       r26, 0x3F0(r1)
	  lfd       f0, 0x3F0(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x1EC(r1)
	  lfs       f0, 0x1F4(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x3E8(r1)
	  lwz       r0, 0x3EC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x3E4(r1)
	  stw       r26, 0x3E0(r1)
	  lfd       f0, 0x3E0(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x1F4(r1)
	  lfs       f0, 0x1E0(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0x3D8(r1)
	  lwz       r0, 0x3DC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x3D4(r1)
	  stw       r26, 0x3D0(r1)
	  lfd       f0, 0x3D0(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x1E0(r1)
	  lfs       f0, 0x1E8(r1)
	  addi      r6, r27, 0
	  addi      r3, r1, 0x1F8
	  fctiwz    f0, f0
	  addi      r4, r1, 0x1EC
	  addi      r5, r1, 0x1E0
	  li        r7, 0
	  stfd      f0, 0x3C8(r1)
	  lwz       r0, 0x3CC(r1)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x3C4(r1)
	  stw       r26, 0x3C0(r1)
	  lfd       f0, 0x3C0(r1)
	  fsubs     f0, f0, f31
	  stfs      f0, 0x1E8(r1)
	  bl        -0x2E870
	  lfs       f3, 0x200(r1)
	  fmr       f30, f1
	  lfs       f0, 0x1F4(r1)
	  mr        r4, r23
	  lfs       f2, 0x1F8(r1)
	  fadds     f3, f3, f0
	  lfs       f0, 0x1EC(r1)
	  mr        r5, r24
	  mr        r6, r25
	  stfs      f3, 0xA4(r1)
	  fadds     f0, f2, f0
	  addi      r3, r1, 0x108
	  lfs       f2, 0x1FC(r1)
	  lfs       f1, 0x1F0(r1)
	  fadds     f1, f2, f1
	  stfs      f0, 0x9C(r1)
	  stfs      f1, 0xA0(r1)
	  bl        -0x307C0
	  lfs       f1, 0x108(r1)
	  addi      r0, r22, 0x4
	  lfs       f0, 0x1E0(r1)
	  addi      r3, r1, 0x1D4
	  lfs       f3, 0x10C(r1)
	  lfs       f2, 0x1E4(r1)
	  fadds     f0, f1, f0
	  lfs       f1, 0x1E8(r1)
	  lfs       f4, 0x110(r1)
	  fadds     f2, f3, f2
	  stfs      f0, 0x1D4(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x1D8(r1)
	  stfs      f0, 0x1DC(r1)
	  lfs       f0, 0x1D4(r1)
	  fmuls     f0, f0, f29
	  stfs      f0, 0x1D4(r1)
	  lfs       f0, 0x1D8(r1)
	  fmuls     f0, f0, f29
	  stfs      f0, 0x1D8(r1)
	  lfs       f0, 0x1DC(r1)
	  fmuls     f0, f0, f29
	  stfs      f0, 0x1DC(r1)
	  lwz       r4, 0xF0(r30)
	  lfs       f6, -0x6BC8(r13)
	  lwzx      r4, r4, r0
	  lfsu      f0, 0x18(r4)
	  lfs       f1, 0x1D4(r1)
	  lfs       f2, 0x4(r4)
	  fmuls     f0, f0, f6
	  lfs       f5, 0x8(r4)
	  fmuls     f2, f2, f6
	  lfs       f3, 0x1D8(r1)
	  fadds     f0, f1, f0
	  lfs       f4, 0x1DC(r1)
	  fmuls     f5, f5, f6
	  fadds     f2, f3, f2
	  stfs      f0, 0x1D4(r1)
	  fadds     f1, f4, f5
	  stfs      f2, 0x1D8(r1)
	  stfs      f1, 0x1DC(r1)
	  lwz       r4, 0x2E4(r31)
	  addi      r4, r4, 0x1E0
	  bl        -0x30240
	  fmr       f1, f30
	  addi      r3, r1, 0x204
	  crset     6, 0x6
	  subi      r4, r13, 0x6C7C
	  bl        0x1AEBF8
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x204
	  lwz       r3, 0x10(r3)
	  bl        -0x3F87C
	  lwz       r12, 0x3B4(r31)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r31, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x1D4
	  crclr     6, 0x6
	  addi      r8, r1, 0x204
	  li        r7, 0
	  blrl
	  addi      r22, r22, 0xC
	  addi      r21, r21, 0x1

	.loc_0xDA8:
	  lwz       r0, 0xA8(r30)
	  cmpw      r21, r0
	  blt+      .loc_0xA9C
	  mr        r3, r31
	  lwz       r4, 0x2E4(r31)
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, -0x5F17(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xE20
	  li        r6, 0xFF
	  stb       r6, 0xF8(r1)
	  li        r0, 0x80
	  addi      r4, r1, 0xF8
	  stb       r0, 0xF9(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  stb       r6, 0xFA(r1)
	  stb       r6, 0xFB(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0xD8
	  addi      r4, r31, 0
	  bl        -0x2F170

	.loc_0xE20:
	  li        r0, 0x40
	  stb       r0, 0xF4(r1)
	  li        r0, 0xFF
	  addi      r4, r1, 0xF4
	  stb       r0, 0xF5(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  stb       r0, 0xF6(r1)
	  stb       r0, 0xF7(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0xC0
	  addi      r4, r31, 0
	  bl        -0x2F1B0
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x1
	  lwz       r12, 0xB8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  mr        r4, r29
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl

	.loc_0xEAC:
	  li        r0, 0
	  stw       r0, 0xA8(r30)
	  stw       r0, 0xAC(r30)
	  stw       r0, 0x324(r31)

	.loc_0xEBC:
	  lmw       r21, 0x424(r1)
	  lwz       r0, 0x46C(r1)
	  lfd       f31, 0x460(r1)
	  lfd       f30, 0x458(r1)
	  lfd       f29, 0x450(r1)
	  addi      r1, r1, 0x468
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80067B28
 * Size:	000270
 */
void MapMgr::updatePos(f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stfd      f31, 0xF8(r1)
	  stfd      f30, 0xF0(r1)
	  stfd      f29, 0xE8(r1)
	  stfd      f28, 0xE0(r1)
	  stfd      f27, 0xD8(r1)
	  stfd      f26, 0xD0(r1)
	  stfd      f25, 0xC8(r1)
	  fmr       f25, f2
	  stfd      f24, 0xC0(r1)
	  fmr       f24, f1
	  stfd      f23, 0xB8(r1)
	  stmw      r21, 0x8C(r1)
	  lwz       r23, 0x8C(r3)
	  lfs       f26, -0x6BBC(r13)
	  cmplwi    r23, 0
	  beq-      .loc_0x238
	  li        r31, 0
	  lfs       f31, -0x78B0(r2)
	  lfs       f30, -0x7830(r2)
	  mr        r24, r31
	  lfs       f23, -0x7838(r2)
	  addi      r27, r1, 0x3C
	  lfs       f28, -0x7878(r2)
	  lfs       f29, -0x7834(r2)
	  addi      r26, r1, 0x38
	  addi      r25, r1, 0x34
	  addi      r30, r1, 0x48
	  addi      r29, r1, 0x44
	  addi      r28, r1, 0x40
	  b         .loc_0x22C

	.loc_0x84:
	  lwz       r3, 0x4(r23)
	  lwzx      r7, r3, r24
	  lfs       f0, 0x18(r7)
	  fcmpu     cr0, f23, f0
	  beq-      .loc_0x224
	  lwz       r0, 0x24(r7)
	  cmpwi     r0, 0
	  beq-      .loc_0xB0
	  lfs       f0, 0x14(r7)
	  fmuls     f27, f28, f0
	  b         .loc_0xB8

	.loc_0xB0:
	  lfs       f0, 0x14(r7)
	  fmuls     f27, f29, f0

	.loc_0xB8:
	  stfs      f31, 0x6C(r1)
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  stfs      f31, 0x68(r1)
	  addi      r6, r30, 0
	  addi      r3, r1, 0x64
	  stfs      f31, 0x64(r1)
	  lfs       f0, 0x8(r7)
	  fsubs     f0, f25, f0
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x4(r7)
	  fsubs     f0, f26, f0
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x0(r7)
	  fsubs     f0, f24, f0
	  stfs      f0, 0x40(r1)
	  bl        -0xA594
	  lfs       f1, 0x64(r1)
	  lfs       f0, 0x68(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x6C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x5A004
	  fcmpo     cr0, f1, f27
	  bge-      .loc_0x134
	  lwz       r3, 0x4(r23)
	  lwzx      r3, r3, r24
	  stfs      f23, 0x18(r3)

	.loc_0x134:
	  lwz       r3, 0x4(r23)
	  lwzx      r3, r3, r24
	  lwz       r0, 0x24(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x224
	  li        r22, 0
	  addi      r21, r22, 0
	  b         .loc_0x218

	.loc_0x154:
	  cmpw      r31, r22
	  beq-      .loc_0x210
	  lwz       r3, 0x4(r23)
	  lwzx      r7, r3, r21
	  lwzx      r8, r24, r3
	  lwz       r3, 0x20(r7)
	  lwz       r0, 0x20(r8)
	  cmpw      r3, r0
	  bne-      .loc_0x210
	  lfs       f0, 0x1C(r7)
	  fcmpo     cr0, f0, f30
	  ble-      .loc_0x210
	  stfs      f31, 0x5C(r1)
	  addi      r4, r25, 0
	  addi      r5, r26, 0
	  stfs      f31, 0x58(r1)
	  addi      r6, r27, 0
	  addi      r3, r1, 0x54
	  stfs      f31, 0x54(r1)
	  lfs       f1, 0x8(r7)
	  lfs       f0, 0x8(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3C(r1)
	  lfs       f1, 0x4(r7)
	  lfs       f0, 0x4(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x38(r1)
	  lfs       f1, 0x0(r7)
	  lfs       f0, 0x0(r8)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x34(r1)
	  bl        -0xA66C
	  lfs       f1, 0x54(r1)
	  lfs       f0, 0x58(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x5C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x5A0DC
	  lwz       r0, 0x4(r23)
	  lwzx      r3, r24, r0
	  lfs       f0, 0x14(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x210
	  stfs      f23, 0x18(r3)

	.loc_0x210:
	  addi      r21, r21, 0x4
	  addi      r22, r22, 0x1

	.loc_0x218:
	  lwz       r0, 0xC(r23)
	  cmpw      r22, r0
	  blt+      .loc_0x154

	.loc_0x224:
	  addi      r24, r24, 0x4
	  addi      r31, r31, 0x1

	.loc_0x22C:
	  lwz       r0, 0xC(r23)
	  cmpw      r31, r0
	  blt+      .loc_0x84

	.loc_0x238:
	  lmw       r21, 0x8C(r1)
	  lwz       r0, 0x104(r1)
	  lfd       f31, 0xF8(r1)
	  lfd       f30, 0xF0(r1)
	  lfd       f29, 0xE8(r1)
	  lfd       f28, 0xE0(r1)
	  lfd       f27, 0xD8(r1)
	  lfd       f26, 0xD0(r1)
	  lfd       f25, 0xC8(r1)
	  lfd       f24, 0xC0(r1)
	  lfd       f23, 0xB8(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80067D98
 * Size:	000008
 */
void MapMgr::getLight(f32, f32)
{
	/*
	.loc_0x0:
	  lfs       f1, -0x7884(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80067DA0
 * Size:	000164
 */
void MapMgr::getCollGroupList(f32, f32, bool)
{
	/*
	.loc_0x0:
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x50(r1)
	  li        r7, 0
	  beq-      .loc_0xB8
	  lwz       r4, 0x88(r3)
	  lwz       r8, 0x10(r4)
	  b         .loc_0xB0

	.loc_0x1C:
	  lfs       f0, 0x44(r8)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xAC
	  lfs       f0, 0x50(r8)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xAC
	  lfs       f0, 0x4C(r8)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xAC
	  lfs       f0, 0x58(r8)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xAC
	  lwz       r4, 0x2C(r8)
	  lwz       r0, 0x14(r4)
	  rlwinm.   r0,r0,0,27,27
	  beq-      .loc_0xAC
	  li        r9, 0
	  li        r6, 0
	  b         .loc_0xA0

	.loc_0x70:
	  lwz       r4, 0x40(r8)
	  lwz       r5, 0x38(r8)
	  lwzx      r4, r4, r6
	  lwz       r0, 0x18(r4)
	  lbzx      r0, r5, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x98
	  stw       r7, 0x20(r4)
	  lwz       r4, 0x40(r8)
	  lwzx      r7, r4, r6

	.loc_0x98:
	  addi      r6, r6, 0x4
	  addi      r9, r9, 0x1

	.loc_0xA0:
	  lwz       r0, 0x3C(r8)
	  cmpw      r9, r0
	  blt+      .loc_0x70

	.loc_0xAC:
	  lwz       r8, 0xC(r8)

	.loc_0xB0:
	  cmplwi    r8, 0
	  bne+      .loc_0x1C

	.loc_0xB8:
	  lwz       r5, 0x60(r3)
	  lfs       f3, 0x140(r5)
	  lfs       f0, 0x148(r5)
	  fsubs     f1, f1, f3
	  lfs       f3, 0x158(r5)
	  fsubs     f0, f2, f0
	  fdivs     f1, f1, f3
	  fctiwz    f1, f1
	  fdivs     f0, f0, f3
	  stfd      f1, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stfd      f1, 0x48(r1)
	  cmpwi     r0, 0
	  fctiwz    f0, f0
	  lwz       r4, 0x4C(r1)
	  stfd      f0, 0x40(r1)
	  lwz       r3, 0x44(r1)
	  blt-      .loc_0x120
	  cmpwi     r3, 0
	  blt-      .loc_0x120
	  lwz       r6, 0x15C(r5)
	  cmpw      r4, r6
	  bge-      .loc_0x120
	  lwz       r0, 0x160(r5)
	  cmpw      r3, r0
	  blt-      .loc_0x128

	.loc_0x120:
	  li        r3, 0
	  b         .loc_0x13C

	.loc_0x128:
	  mullw     r0, r3, r6
	  lwz       r3, 0x164(r5)
	  add       r0, r4, r0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r3, r0

	.loc_0x13C:
	  cmplwi    r3, 0
	  beq-      .loc_0x158
	  lha       r0, 0x4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x158
	  stw       r7, 0x20(r3)
	  mr        r7, r3

	.loc_0x158:
	  mr        r3, r7
	  addi      r1, r1, 0x50
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80067F04
 * Size:	000164
 */
f32 MapMgr::getMinY(f32, f32, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  fmr       f30, f2
	  stfd      f29, 0x40(r1)
	  fmr       f29, f1
	  lwz       r5, 0x18(r3)
	  addi      r0, r5, 0x1
	  stw       r0, 0x18(r3)
	  lfs       f31, -0x782C(r2)
	  bl        -0x194
	  lbz       r8, -0x5F17(r13)
	  lfs       f0, -0x78B0(r2)
	  b         .loc_0x128

	.loc_0x40:
	  cmplwi    r8, 0
	  beq-      .loc_0x58
	  lha       r4, 0x6(r3)
	  lha       r0, 0x4(r3)
	  sub       r0, r0, r4
	  b         .loc_0x5C

	.loc_0x58:
	  lha       r0, 0x4(r3)

	.loc_0x5C:
	  cmpwi     r0, 0
	  bne-      .loc_0x68
	  lha       r0, 0x4(r3)

	.loc_0x68:
	  cmpwi     r0, 0
	  mtctr     r0
	  li        r7, 0
	  ble-      .loc_0x124

	.loc_0x78:
	  lwz       r4, 0x8(r3)
	  lwzx      r9, r4, r7
	  lfs       f4, 0x1C(r9)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x11C
	  lfs       f2, 0x18(r9)
	  li        r5, 0x1
	  lfs       f1, 0x20(r9)
	  li        r4, 0
	  fmuls     f3, f29, f2
	  fmuls     f2, f30, f1
	  lfs       f1, 0x24(r9)
	  fadds     f2, f3, f2
	  fsubs     f1, f2, f1
	  fneg      f1, f1
	  fdivs     f5, f1, f4
	  b         .loc_0xF8

	.loc_0xBC:
	  lfs       f2, 0x28(r9)
	  lfs       f1, 0x2C(r9)
	  fmuls     f3, f2, f29
	  lfs       f4, 0x30(r9)
	  fmuls     f2, f1, f5
	  lfs       f1, 0x34(r9)
	  fmuls     f4, f4, f30
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xF0
	  li        r5, 0

	.loc_0xF0:
	  addi      r9, r9, 0x10
	  addi      r4, r4, 0x1

	.loc_0xF8:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x108
	  cmpwi     r4, 0x3
	  blt+      .loc_0xBC

	.loc_0x108:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x11C
	  fcmpo     cr0, f5, f31
	  ble-      .loc_0x11C
	  fmr       f31, f5

	.loc_0x11C:
	  addi      r7, r7, 0x4
	  bdnz+     .loc_0x78

	.loc_0x124:
	  lwz       r3, 0x20(r3)

	.loc_0x128:
	  cmplwi    r3, 0
	  bne+      .loc_0x40
	  lfs       f0, -0x782C(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x144
	  lfs       f1, -0x78B0(r2)
	  b         .loc_0x148

	.loc_0x144:
	  fmr       f1, f31

	.loc_0x148:
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  lfd       f29, 0x40(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80068068
 * Size:	000170
 */
void MapMgr::getMaxY(f32, f32, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  fmr       f30, f2
	  stfd      f29, 0x40(r1)
	  fmr       f29, f1
	  lwz       r5, 0x18(r3)
	  addi      r0, r5, 0x1
	  stw       r0, 0x18(r3)
	  lfs       f31, -0x7828(r2)
	  bl        -0x2F8
	  lbz       r8, -0x5F17(r13)
	  lfs       f1, -0x78B0(r2)
	  lfs       f0, -0x7824(r2)
	  b         .loc_0x134

	.loc_0x44:
	  cmplwi    r8, 0
	  beq-      .loc_0x5C
	  lha       r4, 0x6(r3)
	  lha       r0, 0x4(r3)
	  sub       r0, r0, r4
	  b         .loc_0x60

	.loc_0x5C:
	  lha       r0, 0x4(r3)

	.loc_0x60:
	  cmpwi     r0, 0
	  bne-      .loc_0x6C
	  lha       r0, 0x4(r3)

	.loc_0x6C:
	  cmpwi     r0, 0
	  mtctr     r0
	  li        r7, 0
	  ble-      .loc_0x130

	.loc_0x7C:
	  lwz       r4, 0x8(r3)
	  lwzx      r9, r4, r7
	  lfs       f5, 0x1C(r9)
	  fcmpo     cr0, f5, f1
	  ble-      .loc_0x128
	  lfs       f3, 0x18(r9)
	  li        r5, 0x1
	  lfs       f2, 0x20(r9)
	  li        r4, 0
	  fmuls     f4, f29, f3
	  fmuls     f3, f30, f2
	  lfs       f2, 0x24(r9)
	  fadds     f3, f4, f3
	  fsubs     f2, f3, f2
	  fneg      f2, f2
	  fdivs     f6, f2, f5
	  b         .loc_0xFC

	.loc_0xC0:
	  lfs       f3, 0x28(r9)
	  lfs       f2, 0x2C(r9)
	  fmuls     f4, f3, f29
	  lfs       f5, 0x30(r9)
	  fmuls     f3, f2, f6
	  lfs       f2, 0x34(r9)
	  fmuls     f5, f5, f30
	  fadds     f3, f4, f3
	  fadds     f3, f5, f3
	  fsubs     f2, f3, f2
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0xF4
	  li        r5, 0

	.loc_0xF4:
	  addi      r9, r9, 0x10
	  addi      r4, r4, 0x1

	.loc_0xFC:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x10C
	  cmpwi     r4, 0x3
	  blt+      .loc_0xC0

	.loc_0x10C:
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x128
	  fcmpo     cr0, f6, f0
	  ble-      .loc_0x128
	  fcmpo     cr0, f6, f31
	  bge-      .loc_0x128
	  fmr       f31, f6

	.loc_0x128:
	  addi      r7, r7, 0x4
	  bdnz+     .loc_0x7C

	.loc_0x130:
	  lwz       r3, 0x20(r3)

	.loc_0x134:
	  cmplwi    r3, 0
	  bne+      .loc_0x44
	  lfs       f0, -0x7828(r2)
	  fcmpu     cr0, f0, f31
	  bne-      .loc_0x150
	  lfs       f1, -0x78B0(r2)
	  b         .loc_0x154

	.loc_0x150:
	  fmr       f1, f31

	.loc_0x154:
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lfd       f30, 0x48(r1)
	  lfd       f29, 0x40(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800681D8
 * Size:	00015C
 */
void MapMgr::getCurrTri(f32, f32, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stfd      f30, 0x50(r1)
	  fmr       f30, f2
	  stfd      f29, 0x48(r1)
	  fmr       f29, f1
	  stw       r31, 0x44(r1)
	  li        r31, 0
	  lwz       r5, 0x1C(r3)
	  addi      r0, r5, 0x1
	  stw       r0, 0x1C(r3)
	  lfs       f31, -0x782C(r2)
	  bl        -0x470
	  lbz       r9, -0x5F17(r13)
	  lfs       f0, -0x78B0(r2)
	  b         .loc_0x130

	.loc_0x48:
	  cmplwi    r9, 0
	  beq-      .loc_0x60
	  lha       r4, 0x6(r3)
	  lha       r0, 0x4(r3)
	  sub       r0, r0, r4
	  b         .loc_0x64

	.loc_0x60:
	  lha       r0, 0x4(r3)

	.loc_0x64:
	  cmpwi     r0, 0
	  bne-      .loc_0x70
	  lha       r0, 0x4(r3)

	.loc_0x70:
	  cmpwi     r0, 0
	  mtctr     r0
	  li        r8, 0
	  ble-      .loc_0x12C

	.loc_0x80:
	  lwz       r4, 0x8(r3)
	  li        r6, 0x1
	  li        r5, 0
	  lwzx      r10, r4, r8
	  lfs       f2, 0x18(r10)
	  mr        r7, r10
	  lfs       f1, 0x20(r10)
	  fmuls     f4, f29, f2
	  lfs       f2, 0x24(r10)
	  fmuls     f3, f30, f1
	  lfs       f1, 0x1C(r10)
	  fadds     f3, f4, f3
	  fsubs     f2, f3, f2
	  fneg      f2, f2
	  fdivs     f5, f2, f1
	  b         .loc_0xFC

	.loc_0xC0:
	  lfs       f2, 0x28(r7)
	  lfs       f1, 0x2C(r7)
	  fmuls     f3, f2, f29
	  lfs       f4, 0x30(r7)
	  fmuls     f2, f1, f5
	  lfs       f1, 0x34(r7)
	  fmuls     f4, f4, f30
	  fadds     f2, f3, f2
	  fadds     f2, f4, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xF4
	  li        r6, 0

	.loc_0xF4:
	  addi      r7, r7, 0x10
	  addi      r5, r5, 0x1

	.loc_0xFC:
	  rlwinm.   r0,r6,0,24,31
	  beq-      .loc_0x10C
	  cmpwi     r5, 0x3
	  blt+      .loc_0xC0

	.loc_0x10C:
	  rlwinm.   r0,r6,0,24,31
	  beq-      .loc_0x124
	  fcmpo     cr0, f5, f31
	  ble-      .loc_0x124
	  mr        r31, r10
	  fmr       f31, f5

	.loc_0x124:
	  addi      r8, r8, 0x4
	  bdnz+     .loc_0x80

	.loc_0x12C:
	  lwz       r3, 0x20(r3)

	.loc_0x130:
	  cmplwi    r3, 0
	  bne+      .loc_0x48
	  mr        r3, r31
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lfd       f30, 0x50(r1)
	  lfd       f29, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80068334
 * Size:	0002EC
 */
void MapMgr::findEdgePenetration(CollTriInfo&, Vector3f*, Vector3f&, f32, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x5555
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  fmr       f31, f1
	  stfd      f30, 0x178(r1)
	  stfd      f29, 0x170(r1)
	  stfd      f28, 0x168(r1)
	  fneg      f28, f31
	  stfd      f27, 0x160(r1)
	  stfd      f26, 0x158(r1)
	  stfd      f25, 0x150(r1)
	  stmw      r24, 0x130(r1)
	  addi      r25, r4, 0
	  addi      r26, r5, 0
	  addi      r27, r6, 0
	  addi      r28, r7, 0
	  addi      r30, r25, 0
	  addi      r31, r3, 0x5556
	  li        r29, 0
	  lfs       f30, -0x78B0(r2)
	  lfs       f29, -0x7884(r2)

	.loc_0x5C:
	  lfs       f1, 0x28(r30)
	  lfs       f5, 0x0(r27)
	  lfs       f0, 0x2C(r30)
	  lfs       f3, 0x4(r27)
	  fmuls     f4, f1, f5
	  lfs       f6, 0x30(r30)
	  fmuls     f2, f0, f3
	  lfs       f1, 0x8(r27)
	  lfs       f0, 0x34(r30)
	  fmuls     f6, f6, f1
	  fadds     f2, f4, f2
	  fadds     f2, f6, f2
	  fsubs     f0, f2, f0
	  fcmpo     cr0, f0, f30
	  bge-      .loc_0x2A8
	  fcmpo     cr0, f0, f28
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2A8
	  mulhw     r5, r31, r29
	  addi      r4, r29, 0x1
	  mulhw     r3, r31, r4
	  rlwinm    r0,r5,1,31,31
	  add       r0, r5, r0
	  mulli     r5, r0, 0x3
	  rlwinm    r0,r3,1,31,31
	  add       r0, r3, r0
	  sub       r3, r29, r5
	  mulli     r0, r0, 0x3
	  rlwinm    r3,r3,2,0,29
	  addi      r3, r3, 0x4
	  sub       r0, r4, r0
	  lwzx      r4, r25, r3
	  rlwinm    r3,r0,2,0,29
	  mulli     r0, r4, 0xC
	  add       r4, r26, r0
	  addi      r0, r3, 0x4
	  lfs       f4, 0x0(r4)
	  lwzx      r0, r25, r0
	  lfs       f0, 0x8(r4)
	  fsubs     f27, f5, f4
	  mulli     r0, r0, 0xC
	  lfs       f2, 0x4(r4)
	  fsubs     f25, f1, f0
	  fsubs     f26, f3, f2
	  add       r24, r26, r0
	  lfs       f8, 0x8(r24)
	  lfs       f7, 0x4(r24)
	  lfs       f6, 0x0(r24)
	  fsubs     f11, f8, f0
	  fsubs     f12, f7, f2
	  stfs      f27, 0x94(r1)
	  fsubs     f13, f6, f4
	  fmuls     f10, f11, f25
	  lfs       f6, 0x94(r1)
	  fmuls     f8, f12, f26
	  fmuls     f9, f13, f6
	  fmuls     f7, f13, f13
	  fmuls     f6, f12, f12
	  fadds     f9, f9, f8
	  fmuls     f8, f11, f11
	  fadds     f6, f7, f6
	  fadds     f7, f10, f9
	  fadds     f6, f8, f6
	  fdivs     f6, f7, f6
	  fcmpo     cr0, f6, f30
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1FC
	  fcmpo     cr0, f6, f29
	  bge-      .loc_0x1FC
	  fmuls     f8, f13, f6
	  fmuls     f7, f12, f6
	  fmuls     f6, f11, f6
	  fadds     f4, f4, f8
	  fadds     f2, f2, f7
	  fadds     f0, f0, f6
	  fsubs     f4, f5, f4
	  fsubs     f2, f3, f2
	  fsubs     f0, f1, f0
	  stfs      f4, 0x0(r28)
	  stfs      f2, 0x4(r28)
	  stfs      f0, 0x8(r28)
	  lfs       f1, 0x0(r28)
	  lfs       f0, 0x4(r28)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r28)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x5A8B4
	  fcmpu     cr0, f30, f1
	  beq-      .loc_0x1F0
	  lfs       f0, 0x0(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r28)
	  lfs       f0, 0x4(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r28)
	  lfs       f0, 0x8(r28)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r28)

	.loc_0x1F0:
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x2A8
	  b         .loc_0x2BC

	.loc_0x1FC:
	  fmuls     f1, f27, f27
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x5A904
	  fcmpu     cr0, f30, f1
	  beq-      .loc_0x228
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x228:
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x240
	  stfs      f27, 0x0(r28)
	  stfs      f26, 0x4(r28)
	  stfs      f25, 0x8(r28)
	  b         .loc_0x2BC

	.loc_0x240:
	  lfs       f3, 0x0(r27)
	  lfs       f2, 0x0(r24)
	  lfs       f1, 0x4(r27)
	  lfs       f0, 0x4(r24)
	  fsubs     f25, f3, f2
	  lfs       f2, 0x8(r27)
	  fsubs     f26, f1, f0
	  lfs       f0, 0x8(r24)
	  fmuls     f1, f25, f25
	  fsubs     f27, f2, f0
	  fmuls     f0, f26, f26
	  fmuls     f2, f27, f27
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x5A96C
	  fcmpu     cr0, f30, f1
	  beq-      .loc_0x290
	  fdivs     f25, f25, f1
	  fdivs     f26, f26, f1
	  fdivs     f27, f27, f1

	.loc_0x290:
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0x2A8
	  stfs      f25, 0x0(r28)
	  stfs      f26, 0x4(r28)
	  stfs      f27, 0x8(r28)
	  b         .loc_0x2BC

	.loc_0x2A8:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x3
	  addi      r30, r30, 0x10
	  blt+      .loc_0x5C
	  lfs       f1, -0x78B0(r2)

	.loc_0x2BC:
	  lmw       r24, 0x130(r1)
	  lwz       r0, 0x18C(r1)
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lfd       f29, 0x170(r1)
	  lfd       f28, 0x168(r1)
	  lfd       f27, 0x160(r1)
	  lfd       f26, 0x158(r1)
	  lfd       f25, 0x150(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80068620
 * Size:	00082C
 */
void MapMgr::recTraceMove(CollGroup*, MoveTrace&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x158(r1)
	  stfd      f31, 0x150(r1)
	  stfd      f30, 0x148(r1)
	  stfd      f29, 0x140(r1)
	  stfd      f28, 0x138(r1)
	  stfd      f27, 0x130(r1)
	  stfd      f26, 0x128(r1)
	  stmw      r21, 0xFC(r1)
	  mr        r23, r5
	  addi      r21, r3, 0
	  addi      r22, r4, 0
	  lfs       f0, 0xC(r5)
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0x10(r5)
	  stfs      f0, 0xE4(r1)
	  lfs       f0, 0x14(r5)
	  stfs      f0, 0xE8(r1)
	  lfs       f2, 0x1C(r5)
	  lfs       f0, 0xE0(r1)
	  fmuls     f1, f1, f2
	  fmuls     f0, f0, f1
	  stfs      f0, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xE4(r1)
	  lfs       f0, 0xE8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xE8(r1)
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0xE4(r1)
	  fmuls     f5, f1, f1
	  lfs       f2, 0xE8(r1)
	  fmuls     f3, f0, f0
	  lfs       f4, -0x78B0(r2)
	  fmuls     f6, f2, f2
	  fadds     f3, f5, f3
	  fadds     f3, f6, f3
	  fcmpo     cr0, f3, f4
	  ble-      .loc_0x100
	  fsqrte    f5, f3
	  lfd       f7, -0x78A8(r2)
	  lfd       f6, -0x78A0(r2)
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f3, f4
	  fsub      f4, f6, f4
	  fmul      f5, f5, f4
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f3, f4
	  fsub      f4, f6, f4
	  fmul      f5, f5, f4
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f3, f4
	  fsub      f4, f6, f4
	  fmul      f4, f5, f4
	  fmul      f4, f3, f4
	  frsp      f4, f4
	  stfs      f4, 0x70(r1)
	  lfs       f5, 0x70(r1)
	  b         .loc_0x104

	.loc_0x100:
	  fmr       f5, f3

	.loc_0x104:
	  lfs       f4, 0x18(r23)
	  fcmpo     cr0, f5, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x178
	  lfs       f4, -0x78B0(r2)
	  fcmpo     cr0, f3, f4
	  ble-      .loc_0x178
	  fsqrte    f5, f3
	  lfd       f7, -0x78A8(r2)
	  lfd       f6, -0x78A0(r2)
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f3, f4
	  fsub      f4, f6, f4
	  fmul      f5, f5, f4
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f3, f4
	  fsub      f4, f6, f4
	  fmul      f5, f5, f4
	  fmul      f4, f5, f5
	  fmul      f5, f7, f5
	  fmul      f4, f3, f4
	  fsub      f4, f6, f4
	  fmul      f4, f5, f4
	  fmul      f3, f3, f4
	  frsp      f3, f3
	  stfs      f3, 0x6C(r1)
	  lfs       f3, 0x6C(r1)

	.loc_0x178:
	  lfs       f3, 0x0(r23)
	  lfs       f4, 0x4(r23)
	  fadds     f1, f3, f1
	  lfs       f3, 0x8(r23)
	  fadds     f4, f4, f0
	  fadds     f0, f3, f2
	  stfs      f1, 0xD4(r1)
	  stfs      f4, 0xD8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f2, 0x18(r23)
	  lfs       f1, -0x7820(r2)
	  lfs       f0, -0x78B0(r2)
	  fadds     f3, f2, f1
	  stfs      f0, 0xBC(r1)
	  stfs      f0, 0xB8(r1)
	  fctiwz    f2, f3
	  stfs      f0, 0xB4(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xC4(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f1, -0x6D18(r13)
	  lfs       f0, -0x6D14(r13)
	  stfs      f1, 0xB4(r1)
	  stfs      f0, 0xB8(r1)
	  lfs       f0, -0x6D10(r13)
	  stfd      f2, 0xF0(r1)
	  stfs      f0, 0xBC(r1)
	  lwz       r0, 0xF4(r1)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0xC0(r1)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0xC4(r1)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0xC8(r1)
	  lfs       f1, 0xD4(r1)
	  lfs       f0, 0xB4(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x214
	  stfs      f1, 0xB4(r1)

	.loc_0x214:
	  lfs       f2, 0xD8(r1)
	  lfs       f0, 0xB8(r1)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x228
	  stfs      f2, 0xB8(r1)

	.loc_0x228:
	  lfs       f4, 0xDC(r1)
	  lfs       f0, 0xBC(r1)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x23C
	  stfs      f4, 0xBC(r1)

	.loc_0x23C:
	  lfs       f0, 0xC0(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x24C
	  stfs      f1, 0xC0(r1)

	.loc_0x24C:
	  lfs       f0, 0xC4(r1)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x25C
	  stfs      f2, 0xC4(r1)

	.loc_0x25C:
	  lfs       f0, 0xC8(r1)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x26C
	  stfs      f4, 0xC8(r1)

	.loc_0x26C:
	  lfs       f0, 0xB4(r1)
	  rlwinm    r3,r0,0,24,31
	  addi      r29, r22, 0
	  fsubs     f0, f0, f3
	  addi      r30, r3, 0x4
	  li        r28, 0
	  stfs      f0, 0xB4(r1)
	  lfs       f0, 0xB8(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0xB8(r1)
	  lfs       f0, 0xBC(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xC0(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0xC0(r1)
	  lfs       f0, 0xC4(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  fadds     f0, f0, f3
	  stfs      f0, 0xC8(r1)
	  lfs       f31, -0x78B0(r2)
	  stfs      f31, 0xB0(r1)
	  stfs      f31, 0xAC(r1)
	  stfs      f31, 0xA8(r1)
	  lfs       f26, -0x7818(r2)
	  lfs       f27, -0x7878(r2)
	  lfs       f28, -0x781C(r2)
	  b         .loc_0x7E0

	.loc_0x2E4:
	  lha       r3, 0x6(r29)
	  lha       r0, 0x4(r29)
	  sub.      r0, r0, r3
	  mr        r27, r0
	  bne-      .loc_0x2FC
	  lha       r27, 0x4(r22)

	.loc_0x2FC:
	  li        r26, 0
	  li        r31, 0
	  b         .loc_0x7D0

	.loc_0x308:
	  lbz       r0, -0x5F17(r13)
	  lwz       r3, 0x8(r29)
	  cmplwi    r0, 0
	  lwzx      r25, r3, r31
	  beq-      .loc_0x348
	  cmpw      r26, r27
	  blt-      .loc_0x348
	  lwz       r3, 0xC(r29)
	  sub       r0, r26, r27
	  lbzx      r0, r3, r0
	  cmpw      r0, r30
	  ble-      .loc_0x348
	  lbz       r0, -0x5F16(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x7DC
	  b         .loc_0x7C8

	.loc_0x348:
	  lfs       f0, 0x18(r25)
	  li        r24, 0
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0x1C(r25)
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0x20(r25)
	  stfs      f0, 0xA4(r1)
	  lfs       f3, 0x18(r25)
	  lfs       f2, 0xD4(r1)
	  lfs       f1, 0x1C(r25)
	  lfs       f0, 0xD8(r1)
	  fmuls     f2, f3, f2
	  lfs       f3, 0x20(r25)
	  fmuls     f1, f1, f0
	  lfs       f0, 0xDC(r1)
	  lfs       f4, 0x18(r23)
	  fmuls     f3, f3, f0
	  lfs       f0, 0x24(r25)
	  fadds     f1, f2, f1
	  fmr       f30, f4
	  fadds     f1, f3, f1
	  fsubs     f0, f1, f0
	  fcmpo     cr0, f0, f4
	  fmr       f29, f0
	  bge-      .loc_0x3FC
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x3FC
	  addi      r3, r25, 0
	  addi      r4, r1, 0xD4
	  bl        -0x301A8
	  cmpwi     r3, -0x1
	  bne-      .loc_0x3D0
	  li        r24, 0x1
	  b         .loc_0x3FC

	.loc_0x3D0:
	  fmr       f1, f30
	  lwz       r5, 0x14(r29)
	  addi      r3, r21, 0
	  addi      r4, r25, 0
	  addi      r6, r1, 0xD4
	  addi      r7, r1, 0x9C
	  bl        -0x6D4
	  fmr       f29, f1
	  fcmpu     cr0, f31, f29
	  beq-      .loc_0x3FC
	  li        r24, 0x2

	.loc_0x3FC:
	  cmpwi     r24, 0
	  beq-      .loc_0x7C8
	  lwz       r3, 0x24(r23)
	  lfs       f0, -0x7884(r2)
	  cmplwi    r3, 0
	  beq-      .loc_0x424
	  lwz       r4, 0x224(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x424
	  lfs       f0, 0x50(r4)

	.loc_0x424:
	  cmplwi    r3, 0
	  beq-      .loc_0x434
	  li        r0, 0x1
	  stw       r0, 0x1A8(r3)

	.loc_0x434:
	  lwz       r3, 0x1C(r29)
	  li        r4, 0
	  cmplwi    r3, 0
	  bne-      .loc_0x53C
	  lwz       r0, 0x9C(r1)
	  li        r28, 0x1
	  lwz       r3, 0xA0(r1)
	  stw       r0, 0xA8(r1)
	  lwz       r0, 0xA4(r1)
	  stw       r3, 0xAC(r1)
	  lfs       f5, 0x9C(r1)
	  stw       r0, 0xB0(r1)
	  lfs       f6, 0xC(r23)
	  lfs       f2, 0x10(r23)
	  lfs       f1, 0xA0(r1)
	  fmuls     f3, f6, f5
	  lfs       f4, 0x14(r23)
	  fmuls     f1, f2, f1
	  lfs       f2, 0xA4(r1)
	  fmuls     f2, f4, f2
	  fadds     f1, f3, f1
	  fadds     f1, f2, f1
	  fneg      f1, f1
	  fmuls     f3, f0, f1
	  fcmpo     cr0, f3, f31
	  ble-      .loc_0x4D0
	  fmuls     f1, f5, f3
	  fadds     f1, f6, f1
	  stfs      f1, 0xC(r23)
	  lfs       f1, 0xA0(r1)
	  lfs       f2, 0x10(r23)
	  fmuls     f1, f1, f3
	  fadds     f1, f2, f1
	  stfs      f1, 0x10(r23)
	  lfs       f1, 0xA4(r1)
	  lfs       f2, 0x14(r23)
	  fmuls     f1, f1, f3
	  fadds     f1, f2, f1
	  stfs      f1, 0x14(r23)

	.loc_0x4D0:
	  lfs       f3, 0xE0(r1)
	  lfs       f5, 0x9C(r1)
	  lfs       f1, 0xE4(r1)
	  lfs       f6, 0xA0(r1)
	  fmuls     f2, f3, f5
	  lfs       f4, 0xE8(r1)
	  fmuls     f1, f1, f6
	  lfs       f7, 0xA4(r1)
	  fmuls     f4, f4, f7
	  fadds     f1, f2, f1
	  fadds     f1, f4, f1
	  fneg      f1, f1
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x67C
	  fmuls     f2, f5, f0
	  fmuls     f1, f6, f0
	  fmuls     f0, f7, f0
	  fadds     f2, f3, f2
	  stfs      f2, 0xE0(r1)
	  lfs       f2, 0xE4(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xE4(r1)
	  lfs       f1, 0xE8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE8(r1)
	  b         .loc_0x67C

	.loc_0x53C:
	  rlwinm.   r0,r28,0,24,31
	  beq-      .loc_0x580
	  lfs       f4, 0xA8(r1)
	  lfs       f3, 0x9C(r1)
	  lfs       f2, 0xAC(r1)
	  lfs       f1, 0xA0(r1)
	  fmuls     f3, f4, f3
	  lfs       f4, 0xB0(r1)
	  fmuls     f1, f2, f1
	  lfs       f2, 0xA4(r1)
	  fmuls     f2, f4, f2
	  fadds     f1, f3, f1
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f28
	  bge-      .loc_0x580
	  li        r4, 0x1
	  b         .loc_0x67C

	.loc_0x580:
	  lwz       r0, 0x24(r23)
	  cmplwi    r0, 0
	  beq-      .loc_0x5A4
	  cmplwi    r3, 0
	  beq-      .loc_0x5A4
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x5A4
	  lfs       f0, -0x7884(r2)

	.loc_0x5A4:
	  lfs       f6, 0xC(r23)
	  lfs       f5, 0x9C(r1)
	  lfs       f2, 0x10(r23)
	  lfs       f1, 0xA0(r1)
	  fmuls     f3, f6, f5
	  lfs       f4, 0x14(r23)
	  fmuls     f1, f2, f1
	  lfs       f2, 0xA4(r1)
	  fmuls     f2, f4, f2
	  fadds     f1, f3, f1
	  fadds     f1, f2, f1
	  fneg      f1, f1
	  fmuls     f3, f0, f1
	  fcmpo     cr0, f3, f31
	  ble-      .loc_0x614
	  fmuls     f1, f5, f3
	  fadds     f1, f6, f1
	  stfs      f1, 0xC(r23)
	  lfs       f1, 0xA0(r1)
	  lfs       f2, 0x10(r23)
	  fmuls     f1, f1, f3
	  fadds     f1, f2, f1
	  stfs      f1, 0x10(r23)
	  lfs       f1, 0xA4(r1)
	  lfs       f2, 0x14(r23)
	  fmuls     f1, f1, f3
	  fadds     f1, f2, f1
	  stfs      f1, 0x14(r23)

	.loc_0x614:
	  lfs       f3, 0xE0(r1)
	  lfs       f5, 0x9C(r1)
	  lfs       f1, 0xE4(r1)
	  lfs       f6, 0xA0(r1)
	  fmuls     f2, f3, f5
	  lfs       f4, 0xE8(r1)
	  fmuls     f1, f1, f6
	  lfs       f7, 0xA4(r1)
	  fmuls     f4, f4, f7
	  fadds     f1, f2, f1
	  fadds     f1, f4, f1
	  fneg      f1, f1
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x67C
	  fmuls     f2, f5, f0
	  fmuls     f1, f6, f0
	  fmuls     f0, f7, f0
	  fadds     f2, f3, f2
	  stfs      f2, 0xE0(r1)
	  lfs       f2, 0xE4(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xE4(r1)
	  lfs       f1, 0xE8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xE8(r1)

	.loc_0x67C:
	  rlwinm.   r0,r4,0,24,31
	  bne-      .loc_0x6C4
	  fsubs     f2, f30, f29
	  lfs       f0, 0x9C(r1)
	  lfs       f1, 0xD4(r1)
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0xD4(r1)
	  lfs       f0, 0xA0(r1)
	  lfs       f1, 0xD8(r1)
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0xD8(r1)
	  lfs       f0, 0xA4(r1)
	  lfs       f1, 0xDC(r1)
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0xDC(r1)

	.loc_0x6C4:
	  lwz       r3, 0x24(r23)
	  cmplwi    r3, 0
	  beq-      .loc_0x7C8
	  lfs       f0, 0xA0(r1)
	  fcmpo     cr0, f0, f26
	  ble-      .loc_0x6EC
	  stw       r25, 0x28C(r3)
	  lwz       r0, 0x10(r29)
	  lwz       r3, 0x24(r23)
	  stw       r0, 0x294(r3)

	.loc_0x6EC:
	  cmpwi     r24, 0
	  beq-      .loc_0x724
	  lfs       f0, 0x1C(r25)
	  fcmpo     cr0, f0, f27
	  bge-      .loc_0x724
	  fcmpo     cr0, f0, f28
	  ble-      .loc_0x724
	  lwz       r3, 0x24(r23)
	  addi      r4, r25, 0x18
	  lwz       r5, 0x1C(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl

	.loc_0x724:
	  lwz       r4, 0x1C(r29)
	  addi      r0, r25, 0x18
	  lwz       r3, 0x24(r23)
	  stw       r4, 0x280(r3)
	  lwz       r3, 0x24(r23)
	  stw       r0, 0x284(r3)
	  lwz       r0, 0x1C(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x760
	  lwz       r3, 0x24(r23)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x760
	  stw       r25, 0x288(r3)
	  b         .loc_0x76C

	.loc_0x760:
	  lwz       r3, 0x24(r23)
	  li        r0, 0
	  stw       r0, 0x288(r3)

	.loc_0x76C:
	  lwz       r4, 0x1C(r29)
	  cmplwi    r4, 0
	  beq-      .loc_0x7C8
	  cmpwi     r24, 0x1
	  bne-      .loc_0x7A8
	  lwz       r3, 0x24(r4)
	  lwz       r0, 0x10C(r21)
	  cmplw     r3, r0
	  beq-      .loc_0x7A8
	  lwz       r3, 0x20(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x20(r4)
	  lwz       r0, 0x10C(r21)
	  lwz       r3, 0x1C(r29)
	  stw       r0, 0x24(r3)

	.loc_0x7A8:
	  lwz       r3, 0x1C(r29)
	  addi      r4, r25, 0x18
	  addi      r5, r1, 0xD4
	  lwz       r12, 0x0(r3)
	  addi      r6, r23, 0xC
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0x7C8:
	  addi      r31, r31, 0x4
	  addi      r26, r26, 0x1

	.loc_0x7D0:
	  lha       r0, 0x4(r29)
	  cmpw      r26, r0
	  blt+      .loc_0x308

	.loc_0x7DC:
	  lwz       r29, 0x20(r29)

	.loc_0x7E0:
	  cmplwi    r29, 0
	  bne+      .loc_0x2E4
	  lwz       r3, 0xD4(r1)
	  lwz       r0, 0xD8(r1)
	  stw       r3, 0x0(r23)
	  stw       r0, 0x4(r23)
	  lwz       r0, 0xDC(r1)
	  stw       r0, 0x8(r23)
	  lwz       r0, 0x15C(r1)
	  lfd       f31, 0x150(r1)
	  lfd       f30, 0x148(r1)
	  lfd       f29, 0x140(r1)
	  lfd       f28, 0x138(r1)
	  lfd       f27, 0x130(r1)
	  lfd       f26, 0x128(r1)
	  lmw       r21, 0xFC(r1)
	  addi      r1, r1, 0x158
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80068E4C
 * Size:	000004
 */
void DynCollObject::touchCallback(Plane&, Vector3f&, Vector3f&) { }

/*
 * --INFO--
 * Address:	80068E50
 * Size:	000004
 */
void Creature::wallCallback(Plane&, DynCollObject*) { }

/*
 * --INFO--
 * Address:	80068E54
 * Size:	0005D0
 */
void MapMgr::traceMove(Creature*, MoveTrace&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stfd      f31, 0xF8(r1)
	  stfd      f30, 0xF0(r1)
	  stfd      f29, 0xE8(r1)
	  stfd      f28, 0xE0(r1)
	  fmr       f28, f1
	  stmw      r27, 0xCC(r1)
	  mr        r27, r3
	  mr        r29, r5
	  mr        r28, r4
	  li        r31, 0x1
	  li        r3, 0
	  lfs       f0, -0x6BB8(r13)
	  lfs       f2, 0x0(r5)
	  lfs       f1, 0x18(r5)
	  fadds     f0, f2, f0
	  lfs       f2, -0x6BB4(r13)
	  stfs      f0, 0x0(r5)
	  lfs       f0, 0x4(r5)
	  fadds     f0, f0, f1
	  stfs      f0, 0x4(r5)
	  lfs       f0, 0x8(r5)
	  fadds     f0, f0, f2
	  stfs      f0, 0x8(r5)
	  lfs       f1, 0xC(r5)
	  lfs       f0, 0x10(r5)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x14(r5)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x78B0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xEC
	  fsqrte    f1, f4
	  lfd       f3, -0x78A8(r2)
	  lfd       f2, -0x78A0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x44(r1)
	  lfs       f4, 0x44(r1)

	.loc_0xEC:
	  fmuls     f2, f28, f4
	  lfs       f1, -0x7878(r2)
	  b         .loc_0x104

	.loc_0xF8:
	  fmuls     f2, f2, f1
	  rlwinm    r31,r31,1,0,30
	  addi      r3, r3, 0x1

	.loc_0x104:
	  cmpwi     r3, 0x64
	  bge-      .loc_0x11C
	  lfs       f0, 0x18(r29)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  beq+      .loc_0xF8

	.loc_0x11C:
	  cmpwi     r3, 0x32
	  ble-      .loc_0x1A8
	  lfs       f1, 0xC(r29)
	  lfs       f0, 0x10(r29)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x14(r29)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x78B0(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1A8
	  fsqrte    f1, f4
	  lfd       f3, -0x78A8(r2)
	  lfd       f2, -0x78A0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x40(r1)
	  lfs       f4, 0x40(r1)

	.loc_0x1A8:
	  xoris     r0, r31, 0x8000
	  lwz       r3, 0x10C(r27)
	  stw       r0, 0xC4(r1)
	  lis       r0, 0x4330
	  addi      r3, r3, 0x1
	  stw       r3, 0x10C(r27)
	  li        r30, 0
	  stw       r0, 0xC0(r1)
	  lfd       f1, -0x7848(r2)
	  lfd       f0, 0xC0(r1)
	  lfs       f2, -0x7884(r2)
	  fsubs     f0, f0, f1
	  fdivs     f0, f2, f0
	  stfs      f0, 0x1C(r29)
	  lfs       f29, -0x78B0(r2)
	  lfs       f30, -0x7894(r2)
	  lfs       f31, -0x78AC(r2)
	  b         .loc_0x574

	.loc_0x1F0:
	  stfs      f29, 0xA0(r1)
	  stfs      f29, 0x9C(r1)
	  stfs      f29, 0x98(r1)
	  stfs      f29, 0xAC(r1)
	  stfs      f29, 0xA8(r1)
	  stfs      f29, 0xA4(r1)
	  lfs       f1, -0x6D18(r13)
	  lfs       f0, -0x6D14(r13)
	  stfs      f1, 0x98(r1)
	  stfs      f0, 0x9C(r1)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0xA0(r1)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0xA4(r1)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0xA8(r1)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0xAC(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x98(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x24C
	  stfs      f1, 0x98(r1)

	.loc_0x24C:
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x9C(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x260
	  stfs      f1, 0x9C(r1)

	.loc_0x260:
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0xA0(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x274
	  stfs      f1, 0xA0(r1)

	.loc_0x274:
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0xA4(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x288
	  stfs      f1, 0xA4(r1)

	.loc_0x288:
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0xA8(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x29C
	  stfs      f1, 0xA8(r1)

	.loc_0x29C:
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0xAC(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2B0
	  stfs      f1, 0xAC(r1)

	.loc_0x2B0:
	  lfs       f0, 0x18(r29)
	  li        r4, 0
	  lfs       f1, 0x98(r1)
	  fmuls     f2, f30, f0
	  fmuls     f0, f31, f0
	  fsubs     f1, f1, f2
	  stfs      f1, 0x98(r1)
	  lfs       f1, 0x9C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fsubs     f0, f0, f2
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0x18(r29)
	  lfs       f1, 0xA4(r1)
	  fmuls     f2, f30, f0
	  fmuls     f0, f31, f0
	  fadds     f1, f1, f2
	  stfs      f1, 0xA4(r1)
	  lfs       f1, 0xA8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r1)
	  lfs       f0, 0xAC(r1)
	  fadds     f0, f0, f2
	  stfs      f0, 0xAC(r1)
	  stw       r28, 0x24(r29)
	  lbz       r0, 0x20(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x450
	  lwz       r3, 0x88(r27)
	  lwz       r7, 0x10(r3)
	  b         .loc_0x448

	.loc_0x330:
	  lwz       r0, 0x28(r7)
	  cmplwi    r0, 0
	  beq-      .loc_0x344
	  cmplw     r0, r28
	  beq-      .loc_0x444

	.loc_0x344:
	  lfs       f1, 0x44(r7)
	  lfs       f0, 0xA4(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x50(r7)
	  lfs       f0, 0x98(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x48(r7)
	  lfs       f0, 0xA8(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x54(r7)
	  lfs       f0, 0x9C(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x4C(r7)
	  lfs       f0, 0xAC(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3C4
	  lfs       f1, 0x58(r7)
	  lfs       f0, 0xA0(r1)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3C4
	  li        r0, 0x1
	  b         .loc_0x3C8

	.loc_0x3C4:
	  li        r0, 0

	.loc_0x3C8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x444
	  li        r8, 0
	  li        r6, 0
	  b         .loc_0x438

	.loc_0x3DC:
	  lwz       r3, 0x40(r7)
	  lwz       r5, 0x38(r7)
	  lwzx      r3, r3, r6
	  lwz       r0, 0x18(r3)
	  lbzx      r0, r5, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x430
	  lwz       r0, 0x2C(r7)
	  stw       r0, 0x10(r3)
	  lwz       r3, 0x40(r7)
	  lwz       r0, 0x30(r7)
	  lwzx      r3, r3, r6
	  stw       r0, 0x14(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r3, r3, r6
	  stw       r7, 0x1C(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r3, r3, r6
	  stw       r4, 0x20(r3)
	  lwz       r3, 0x40(r7)
	  lwzx      r4, r3, r6

	.loc_0x430:
	  addi      r6, r6, 0x4
	  addi      r8, r8, 0x1

	.loc_0x438:
	  lwz       r0, 0x3C(r7)
	  cmpw      r8, r0
	  blt+      .loc_0x3DC

	.loc_0x444:
	  lwz       r7, 0xC(r7)

	.loc_0x448:
	  cmplwi    r7, 0
	  bne+      .loc_0x330

	.loc_0x450:
	  lwz       r7, 0x60(r27)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x140(r7)
	  lfs       f3, 0x158(r7)
	  fsubs     f2, f1, f0
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x148(r7)
	  fdivs     f2, f2, f3
	  fctiwz    f2, f2
	  fsubs     f0, f1, f0
	  stfd      f2, 0xB0(r1)
	  fdivs     f0, f0, f3
	  lwz       r0, 0xB4(r1)
	  stfd      f2, 0xC0(r1)
	  cmpwi     r0, 0
	  lwz       r5, 0xC4(r1)
	  fctiwz    f0, f0
	  stfd      f0, 0xB8(r1)
	  lwz       r3, 0xBC(r1)
	  blt-      .loc_0x4C0
	  cmpwi     r3, 0
	  blt-      .loc_0x4C0
	  lwz       r6, 0x15C(r7)
	  cmpw      r5, r6
	  bge-      .loc_0x4C0
	  lwz       r0, 0x160(r7)
	  cmpw      r3, r0
	  blt-      .loc_0x4C8

	.loc_0x4C0:
	  li        r5, 0
	  b         .loc_0x4DC

	.loc_0x4C8:
	  mullw     r0, r3, r6
	  lwz       r3, 0x164(r7)
	  add       r0, r5, r0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r3, r0

	.loc_0x4DC:
	  cmplwi    r5, 0
	  beq-      .loc_0x510
	  lha       r0, 0x4(r5)
	  cmpwi     r0, 0
	  beq-      .loc_0x510
	  stw       r7, 0x10(r5)
	  li        r0, 0
	  lwz       r3, 0x60(r27)
	  lwz       r3, 0x23C(r3)
	  stw       r3, 0x14(r5)
	  stw       r0, 0x1C(r5)
	  stw       r4, 0x20(r5)
	  mr        r4, r5

	.loc_0x510:
	  cmplwi    r4, 0
	  beq-      .loc_0x52C
	  fmr       f1, f28
	  addi      r3, r27, 0
	  addi      r5, r29, 0
	  bl        -0xD58
	  b         .loc_0x570

	.loc_0x52C:
	  lfs       f0, 0x1C(r29)
	  lfs       f2, 0xC(r29)
	  fmuls     f1, f28, f0
	  lfs       f3, 0x10(r29)
	  lfs       f4, 0x14(r29)
	  lfs       f0, 0x0(r29)
	  fmuls     f2, f2, f1
	  fmuls     f3, f3, f1
	  fmuls     f4, f4, f1
	  fadds     f0, f0, f2
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x4(r29)
	  fadds     f0, f0, f3
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x8(r29)
	  fadds     f0, f0, f4
	  stfs      f0, 0x8(r29)

	.loc_0x570:
	  addi      r30, r30, 0x1

	.loc_0x574:
	  cmpw      r30, r31
	  blt+      .loc_0x1F0
	  lfs       f1, 0x0(r29)
	  lfs       f0, -0x6BB0(r13)
	  lfs       f2, 0x18(r29)
	  fsubs     f0, f1, f0
	  lfs       f1, -0x6BAC(r13)
	  stfs      f0, 0x0(r29)
	  lfs       f0, 0x4(r29)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x4(r29)
	  lfs       f0, 0x8(r29)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x8(r29)
	  lwz       r0, 0x104(r1)
	  lfd       f31, 0xF8(r1)
	  lfd       f30, 0xF0(r1)
	  lfd       f29, 0xE8(r1)
	  lfd       f28, 0xE0(r1)
	  lmw       r27, 0xCC(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069424
 * Size:	000070
 */
void MapMgr::loadPlatshape(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x5F73
	  stw       r0, 0x4(r1)
	  addi      r5, r5, 0x6870
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r4
	  lwz       r3, 0x2DEC(r13)
	  bl        -0x2A3D4
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  lwz       r31, 0x20(r3)

	.loc_0x38:
	  cmplwi    r31, 0
	  bne-      .loc_0x54
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r30, 0
	  li        r5, 0x1
	  bl        -0x2A26C
	  mr        r31, r3

	.loc_0x54:
	  mr        r3, r31
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
 * Address:	80069494
 * Size:	00009C
 */
CreatureCollPart* MapMgr::requestCollPart(ObjCollInfo*, Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  li        r3, 0x148
	  bl        -0x224BC
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x5C
	  lwz       r4, 0x48(r29)
	  bl        -0x74EC
	  lis       r3, 0x802B
	  subi      r0, r3, 0xD20
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  stw       r0, 0x144(r31)
	  stw       r0, 0x140(r31)

	.loc_0x5C:
	  stw       r30, 0x28(r31)
	  mr        r4, r31
	  stw       r30, 0x140(r31)
	  lwz       r0, 0x30(r29)
	  stw       r0, 0x144(r31)
	  lwz       r3, 0x88(r28)
	  bl        -0x28F30
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
 * Address:	80069530
 * Size:	000134
 */
ShadowCaster::ShadowCaster()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  subi      r4, r13, 0x6CD0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lis       r3, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x737C
	  lis       r3, 0x802B
	  stw       r0, 0x0(r30)
	  subi      r0, r3, 0x717C
	  addi      r3, r30, 0x14
	  stw       r31, 0x10(r30)
	  stw       r31, 0xC(r30)
	  stw       r31, 0x8(r30)
	  stw       r4, 0x4(r30)
	  stw       r0, 0x0(r30)
	  bl        -0x263C4
	  lfs       f0, -0x78B0(r2)
	  li        r0, 0x1
	  addi      r3, r30, 0
	  stfs      f0, 0x378(r30)
	  stfs      f0, 0x374(r30)
	  stfs      f0, 0x370(r30)
	  stw       r31, 0x36C(r30)
	  stfs      f0, 0x384(r30)
	  stfs      f0, 0x380(r30)
	  stfs      f0, 0x37C(r30)
	  stfs      f0, 0x390(r30)
	  stfs      f0, 0x38C(r30)
	  stfs      f0, 0x388(r30)
	  lwz       r4, 0x2DEC(r13)
	  addi      r5, r4, 0x1C
	  lwz       r4, 0x1C(r4)
	  stw       r0, 0x0(r5)
	  neg       r4, r4
	  subic     r0, r4, 0x1
	  lfs       f0, -0x6BA8(r13)
	  subfe     r0, r0, r4
	  rlwinm    r0,r0,0,24,31
	  stfs      f0, 0x178(r30)
	  lfs       f0, -0x6BA4(r13)
	  stfs      f0, 0x17C(r30)
	  lfs       f0, -0x6BA0(r13)
	  stfs      f0, 0x180(r30)
	  lfs       f0, -0x6B9C(r13)
	  stfs      f0, 0x184(r30)
	  lfs       f0, -0x6B98(r13)
	  stfs      f0, 0x188(r30)
	  lfs       f0, -0x6B94(r13)
	  stfs      f0, 0x18C(r30)
	  lfs       f0, -0x6B90(r13)
	  stfs      f0, 0x334(r30)
	  lfs       f0, -0x6B8C(r13)
	  stfs      f0, 0x338(r30)
	  lfs       f0, -0x6B88(r13)
	  stfs      f0, 0x33C(r30)
	  lfs       f0, -0x7814(r2)
	  stfs      f0, 0x1E0(r30)
	  lfs       f0, -0x7884(r2)
	  stfs      f0, 0x1E4(r30)
	  lfs       f0, -0x7810(r2)
	  stfs      f0, 0x1E8(r30)
	  lwz       r4, 0x2DEC(r13)
	  stw       r0, 0x1C(r4)
	  stw       r31, 0x394(r30)
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
 * Address:	80069664
 * Size:	00002C
 */
void ShadowCaster::initShadow()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x14
	  stw       r0, 0x4(r1)
	  li        r4, 0x100
	  li        r5, 0x4
	  stwu      r1, -0x8(r1)
	  bl        -0x26368
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069690
 * Size:	00003C
 */
void MapProjMatHandler::setMaterial(Material*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x0(r3)
	  lwz       r4, 0x8(r4)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xC4(r12)
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
 * Address:	800696CC
 * Size:	000038
 */
void MapProjMatHandler::setTexMatrix(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x0(r3)
	  lwz       r5, 0xC(r5)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xE4(r12)
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
 * Address:	80069704
 * Size:	00003C
 */
void MapShadMatHandler::setMaterial(Material*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x0(r3)
	  lwz       r4, 0x8(r4)
	  lwz       r12, 0x3B4(r3)
	  lwz       r12, 0xC4(r12)
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
 * Address:	80069740
 * Size:	000004
 */
void DynObjPushable::touchCallback(Plane&, Vector3f&, Vector3f&) { }

/*
 * --INFO--
 * Address:	80069744
 * Size:	000004
 */
void DynCollObjBody::update() { }

/*
 * --INFO--
 * Address:	80069748
 * Size:	000004
 */
void DynCollObjBody::adjust(Creature*) { }

/*
 * --INFO--
 * Address:	8006974C
 * Size:	000008
 */
Shape* DynCollShape::getShape()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069754
 * Size:	000004
 */
void DynCollObject::applyVelocity(Plane&, Vector3f&, Vector3f&) { }

/*
 * --INFO--
 * Address:	80069758
 * Size:	000004
 */
void MapObjectPart::update() { }

/*
 * --INFO--
 * Address:	8006975C
 * Size:	000004
 */
void MapObjectPart::refresh(Graphics&) { }

/*
 * --INFO--
 * Address:	80069760
 * Size:	000038
 */
void MapObjectPart::touchCallback(Plane&, Vector3f&, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x144(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80069798
 * Size:	000004
 */
void DynCollObject::adjust(Creature*) { }

/*
 * --INFO--
 * Address:	8006979C
 * Size:	000008
 */
Shape* DynCollObject::getShape() { return nullptr; }

/*
 * --INFO--
 * Address:	800697A4
 * Size:	000058
 */
void __sinit_mapMgr_cpp(void)
{
	/*
	.loc_0x0:
	  lis       r3, 0x803A
	  lfs       f0, -0x78B0(r2)
	  subi      r3, r3, 0x2240
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  stfs      f0, 0x14(r3)
	  stfs      f0, 0x10(r3)
	  stfs      f0, 0xC(r3)
	  lfs       f0, -0x6D18(r13)
	  stfs      f0, 0x0(r3)
	  lfs       f0, -0x6D14(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x6D10(r13)
	  stfs      f0, 0x8(r3)
	  lfs       f0, -0x6D0C(r13)
	  stfs      f0, 0xC(r3)
	  lfs       f0, -0x6D08(r13)
	  stfs      f0, 0x10(r3)
	  lfs       f0, -0x6D04(r13)
	  stfs      f0, 0x14(r3)
	  blr
	*/
}
