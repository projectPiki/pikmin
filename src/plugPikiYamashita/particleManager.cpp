#include "zen/particle.h"

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
 * Address:	801A1100
 * Size:	00013C
 */
void zen::particleManager::init(u32, u32, u32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r25, 0x2C(r1)
	  addi      r29, r4, 0
	  cmplwi    r29, 0x1000
	  addi      r28, r3, 0
	  addi      r30, r5, 0
	  addi      r31, r6, 0
	  ble-      .loc_0x2C
	  li        r29, 0x1000

	.loc_0x2C:
	  cmplwi    r30, 0x2000
	  ble-      .loc_0x38
	  li        r30, 0x2000

	.loc_0x38:
	  cmplwi    r31, 0x2000
	  ble-      .loc_0x44
	  li        r31, 0x2000

	.loc_0x44:
	  stfs      f1, 0x98(r28)
	  rlwinm    r3,r29,9,0,22
	  addi      r3, r3, 0x8
	  stw       r29, 0x74(r28)
	  stw       r30, 0x78(r28)
	  stw       r31, 0x7C(r28)
	  bl        -0x15A158
	  lis       r4, 0x801A
	  lis       r5, 0x801A
	  subi      r4, r4, 0x5D30
	  addi      r5, r5, 0x123C
	  addi      r7, r29, 0
	  li        r6, 0x200
	  bl        0x73AB0
	  stw       r3, 0x30(r28)
	  li        r25, 0
	  li        r26, 0
	  lwz       r4, 0x0(r28)
	  stw       r4, 0x8(r4)
	  lwz       r3, 0x0(r28)
	  stw       r4, 0x4(r3)
	  lwz       r4, 0x10(r28)
	  stw       r4, 0x8(r4)
	  lwz       r3, 0x10(r28)
	  stw       r4, 0x4(r3)
	  lwz       r4, 0x20(r28)
	  stw       r4, 0x8(r4)
	  lwz       r3, 0x20(r28)
	  stw       r4, 0x4(r3)
	  b         .loc_0xF8

	.loc_0xBC:
	  lwz       r0, 0x30(r28)
	  add       r27, r0, r26
	  addi      r3, r27, 0
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r28)
	  mr        r4, r27
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r26, r26, 0x200
	  addi      r25, r25, 0x1

	.loc_0xF8:
	  cmplw     r25, r29
	  blt+      .loc_0xBC
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  addi      r3, r28, 0x34
	  bl        0x5C8
	  addi      r0, r28, 0x34
	  stw       r0, 0x70(r28)
	  li        r0, 0
	  stw       r0, 0x8C(r28)
	  stw       r0, 0x90(r28)
	  stw       r0, 0x94(r28)
	  lwz       r0, 0x4C(r1)
	  lmw       r25, 0x2C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A123C
 * Size:	00004C
 */
zen::particleGenerator::~particleGenerator()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x34
	  lis       r3, 0x802D
	  addi      r3, r3, 0x6590
	  extsh.    r0, r4
	  stw       r3, 0x0(r31)
	  ble-      .loc_0x34
	  mr        r3, r31
	  bl        -0x15A0C0

	.loc_0x34:
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
 * Address:	801A1288
 * Size:	000074
 */
void zen::particleManager::createGenerator(u8*, Texture*, Texture*, Vector3f&, zen::CallBack1<zen::particleGenerator*>*,
                                           zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r24, 0x28(r1)
	  addi      r24, r3, 0
	  addi      r25, r4, 0
	  addi      r26, r5, 0
	  addi      r27, r6, 0
	  addi      r28, r7, 0
	  addi      r29, r8, 0
	  addi      r30, r9, 0
	  bl        0x48C
	  mr.       r31, r3
	  beq-      .loc_0x5C
	  addi      r3, r31, 0
	  addi      r4, r25, 0
	  addi      r5, r26, 0
	  addi      r6, r27, 0
	  addi      r7, r28, 0
	  addi      r9, r29, 0
	  addi      r10, r30, 0
	  addi      r8, r24, 0x34
	  bl        -0x45D4

	.loc_0x5C:
	  mr        r3, r31
	  lmw       r24, 0x28(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A12FC
 * Size:	000110
 */
void zen::particleManager::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  stw       r30, 0x38(r1)
	  stw       r29, 0x34(r1)
	  stw       r28, 0x30(r1)
	  mr        r28, r3
	  lwz       r4, 0x2DEC(r13)
	  lwz       r31, 0x0(r3)
	  lfs       f1, 0x98(r3)
	  lfs       f0, 0x28C(r4)
	  lwz       r30, 0x8(r31)
	  fmuls     f31, f1, f0
	  b         .loc_0x88

	.loc_0x40:
	  fmr       f1, f31
	  lwz       r29, 0x8(r30)
	  mr        r3, r30
	  bl        -0x43F0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x84
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x20(r28)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x84:
	  mr        r30, r29

	.loc_0x88:
	  cmplw     r30, r31
	  bne+      .loc_0x40
	  addi      r3, r28, 0x60
	  fmr       f1, f31
	  bl        0xED8
	  lwz       r5, 0x20(r28)
	  lwz       r4, 0x8(r5)
	  cmplw     r4, r5
	  beq-      .loc_0xEC
	  lwz       r3, 0x10(r28)
	  lwz       r5, 0x4(r5)
	  lwz       r3, 0x4(r3)
	  lwz       r0, 0x8(r3)
	  stw       r0, 0x4(r4)
	  lwz       r3, 0x10(r28)
	  lwz       r3, 0x4(r3)
	  stw       r4, 0x8(r3)
	  lwz       r3, 0x10(r28)
	  stw       r5, 0x4(r3)
	  lwz       r0, 0x10(r28)
	  stw       r0, 0x8(r5)
	  lwz       r4, 0x20(r28)
	  stw       r4, 0x8(r4)
	  lwz       r3, 0x20(r28)
	  stw       r4, 0x4(r3)

	.loc_0xEC:
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  lwz       r29, 0x34(r1)
	  lwz       r28, 0x30(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void zen::particleManager::calcActiveList()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::particleManager::debugUpdate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A140C
 * Size:	000074
 */
void zen::particleManager::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  mr        r29, r4
	  stw       r28, 0x18(r1)
	  mr        r28, r3
	  lwz       r31, 0x0(r3)
	  lwz       r3, 0x8(r31)
	  b         .loc_0x40

	.loc_0x30:
	  lwz       r30, 0x8(r3)
	  mr        r4, r29
	  bl        -0x4398
	  mr        r3, r30

	.loc_0x40:
	  cmplw     r3, r31
	  bne+      .loc_0x30
	  addi      r3, r28, 0x60
	  addi      r4, r29, 0
	  bl        0xFF0
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
 * Address:	801A1480
 * Size:	0000A8
 */
void zen::particleManager::cullingDraw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  mr        r28, r4
	  mr        r27, r3
	  lwz       r31, 0x0(r3)
	  lwz       r4, 0x8(r31)
	  b         .loc_0x80

	.loc_0x24:
	  lwz       r3, 0x18(r4)
	  mr        r29, r4
	  lwz       r30, 0x8(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x3C
	  b         .loc_0x40

	.loc_0x3C:
	  addi      r3, r29, 0xC

	.loc_0x40:
	  lfs       f0, 0x0(r3)
	  addi      r4, r1, 0x18
	  lfs       f1, -0x4C20(r2)
	  stfs      f0, 0x18(r1)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x1C(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x20(r1)
	  lwz       r3, 0x2E4(r28)
	  bl        -0x15FF60
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  bl        -0x444C

	.loc_0x7C:
	  mr        r4, r30

	.loc_0x80:
	  cmplw     r4, r31
	  bne+      .loc_0x24
	  addi      r3, r27, 0x60
	  addi      r4, r28, 0
	  bl        0xF3C
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void zen::particleManager::debugDraw(Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801A1528
 * Size:	00009C
 */
void zen::particleManager::killAllGenarator(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r4,0,24,31
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  addi      r29, r3, 0
	  beq-      .loc_0x54
	  b         .loc_0x38

	.loc_0x28:
	  mr        r4, r0
	  addi      r3, r29, 0
	  li        r5, 0x1
	  bl        .loc_0x9C

	.loc_0x38:
	  lwz       r3, 0x0(r29)
	  lwz       r0, 0x8(r3)
	  cmplw     r3, r0
	  bne+      .loc_0x28
	  addi      r3, r29, 0x60
	  bl        0x1164
	  b         .loc_0x80

	.loc_0x54:
	  lwz       r31, 0x0(r29)
	  lwz       r3, 0x8(r31)
	  b         .loc_0x78

	.loc_0x60:
	  lwz       r30, 0x8(r3)
	  mr        r4, r3
	  addi      r3, r29, 0
	  li        r5, 0
	  bl        .loc_0x9C
	  mr        r3, r30

	.loc_0x78:
	  cmplw     r3, r31
	  bne+      .loc_0x60

	.loc_0x80:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0x9C:
	*/
}

/*
 * --INFO--
 * Address:	801A15C4
 * Size:	000098
 */
void zen::particleManager::killGenerator(zen::particleGenerator*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r3, 0
	  bl        0x128
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x7C
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0x70
	  mr        r3, r30
	  bl        -0xA04
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x20(r29)
	  mr        r4, r30
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x7C

	.loc_0x70:
	  lwz       r0, 0x80(r30)
	  ori       r0, r0, 0x2
	  stw       r0, 0x80(r30)

	.loc_0x7C:
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
 * Address:	801A165C
 * Size:	0000B4
 */
void zen::particleManager::killGenerator(zen::CallBack1<zen::particleGenerator*>*,
                                         zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  mr        r25, r3
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  rlwinm    r31,r6,0,24,31
	  lwz       r30, 0x0(r3)
	  lwz       r3, 0x8(r30)
	  b         .loc_0x98

	.loc_0x2C:
	  cmplwi    r31, 0
	  lwz       r29, 0x8(r3)
	  mr        r28, r3
	  beq-      .loc_0x84
	  addi      r3, r28, 0
	  addi      r4, r26, 0
	  addi      r5, r27, 0
	  bl        -0x9A8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x94
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x20(r25)
	  mr        r4, r28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x94

	.loc_0x84:
	  addi      r3, r28, 0
	  addi      r4, r26, 0
	  addi      r5, r27, 0
	  bl        -0xA24

	.loc_0x94:
	  mr        r3, r29

	.loc_0x98:
	  cmplw     r3, r30
	  bne+      .loc_0x2C
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A1710
 * Size:	000030
 */
void zen::particleManager::pmCheckList(zen::particleGenerator*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r3)
	  li        r3, 0
	  lwz       r6, 0x8(r5)
	  b         .loc_0x24

	.loc_0x10:
	  cmplw     r6, r4
	  bne-      .loc_0x20
	  li        r3, 0x1
	  blr

	.loc_0x20:
	  lwz       r6, 0x8(r6)

	.loc_0x24:
	  cmplw     r6, r5
	  bne+      .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A1740
 * Size:	000094
 */
void zen::particleManager::pmGetPtclGen()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x10(r3)
	  lwz       r0, 0x8(r3)
	  cmplw     r3, r0
	  beq-      .loc_0x44
	  mr        r31, r0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0x44:
	  cmplwi    r31, 0
	  beq-      .loc_0x78
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
