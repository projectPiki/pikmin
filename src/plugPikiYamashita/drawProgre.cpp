#include "zen/DrawProgre.h"

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
 * Address:	801DA250
 * Size:	0001B4
 */
zen::DrawProgre::DrawProgre()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  addi      r31, r3, 0
	  li        r3, 0x1D8
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  stw       r28, 0x28(r1)
	  bl        -0x193270
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x48
	  lis       r4, 0x802E
	  addi      r4, r4, 0x5788
	  li        r5, 0
	  li        r6, 0
	  bl        -0x17198

	.loc_0x48:
	  stw       r29, 0x0(r31)
	  li        r4, 0x1
	  lwz       r3, 0x0(r31)
	  bl        -0x1596C
	  lwz       r4, 0x0(r31)
	  li        r30, 0
	  lis       r3, 0x100
	  stw       r30, 0x1C8(r4)
	  addi      r0, r3, 0x1000
	  li        r3, 0x30
	  lwz       r4, 0x0(r31)
	  stw       r0, 0x1C4(r4)
	  bl        -0x1932C4
	  mr.       r28, r3
	  beq-      .loc_0x184
	  stw       r30, 0xC(r28)
	  li        r3, 0x100
	  stw       r30, 0x8(r28)
	  stw       r30, 0x10(r28)
	  lfs       f0, -0x41C8(r2)
	  stfs      f0, 0x14(r28)
	  lfs       f0, -0x41C4(r2)
	  stfs      f0, 0x18(r28)
	  lfs       f1, 0x14(r28)
	  lfs       f0, 0x18(r28)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x1C(r28)
	  bl        -0x193300
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0xDC
	  lis       r4, 0x802E
	  addi      r4, r4, 0x57A0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  bl        -0x1ADB4

	.loc_0xDC:
	  stw       r29, 0x4(r28)
	  lis       r30, 0x6D73
	  addi      r4, r30, 0x5F31
	  lwz       r3, 0x4(r28)
	  li        r5, 0x1
	  addi      r29, r3, 0x4
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x20(r28)
	  addi      r3, r29, 0
	  addi      r4, r30, 0x5F32
	  lwz       r12, 0x0(r29)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x24(r28)
	  lis       r6, 0x796F
	  li        r8, 0
	  lwz       r7, 0x20(r28)
	  addi      r4, r29, 0
	  addi      r5, r29, 0
	  lbz       r0, 0xC(r7)
	  rlwimi    r0,r8,7,24,24
	  addi      r3, r28, 0x8
	  stb       r0, 0xC(r7)
	  addi      r6, r6, 0x6B6F
	  lwz       r7, 0x24(r28)
	  lbz       r0, 0xC(r7)
	  rlwimi    r0,r8,7,24,24
	  stb       r0, 0xC(r7)
	  bl        -0x174D4
	  addi      r4, r29, 0
	  addi      r5, r29, 0
	  addi      r3, r28, 0x10
	  bl        -0x10EF8
	  addi      r3, r28, 0
	  li        r4, 0
	  bl        .loc_0x1B4

	.loc_0x184:
	  stw       r28, 0xC(r31)
	  li        r0, -0x1
	  addi      r3, r31, 0
	  stw       r0, 0x4(r31)
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0x1B4:
	*/
}

/*
 * --INFO--
 * Address:	801DA404
 * Size:	0000D8
 */
void zen::DrawProgreMes::setMode(zen::DrawProgreMes::modeFlag)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stw       r4, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x80
	  bge-      .loc_0x34
	  cmpwi     r0, 0
	  beq-      .loc_0x40
	  bge-      .loc_0x50
	  b         .loc_0xC8

	.loc_0x34:
	  cmpwi     r0, 0x4
	  bge-      .loc_0xC8
	  b         .loc_0x9C

	.loc_0x40:
	  lfs       f0, -0x41C8(r2)
	  stfs      f0, 0x28(r5)
	  stfs      f0, 0x2C(r5)
	  b         .loc_0xC8

	.loc_0x50:
	  lfs       f1, -0x41C8(r2)
	  li        r0, 0x1
	  addi      r3, r5, 0x8
	  stfs      f1, 0x28(r5)
	  lfs       f0, -0x41C0(r2)
	  stfs      f0, 0x2C(r5)
	  lfs       f0, 0x2C(r5)
	  stw       r0, 0x10(r5)
	  stfs      f1, 0x14(r5)
	  stfs      f0, 0x18(r5)
	  bl        -0x17514
	  b         .loc_0xC8

	.loc_0x80:
	  li        r0, 0x2
	  stw       r0, 0x10(r5)
	  lfs       f0, -0x41C8(r2)
	  stfs      f0, 0x14(r5)
	  lfs       f0, -0x41C4(r2)
	  stfs      f0, 0x18(r5)
	  b         .loc_0xC8

	.loc_0x9C:
	  lfs       f1, -0x41C8(r2)
	  li        r0, 0x3
	  addi      r3, r5, 0x8
	  stfs      f1, 0x28(r5)
	  lfs       f0, -0x41C0(r2)
	  stfs      f0, 0x2C(r5)
	  lfs       f0, 0x2C(r5)
	  stw       r0, 0x10(r5)
	  stfs      f1, 0x14(r5)
	  stfs      f0, 0x18(r5)
	  bl        -0x17548

	.loc_0xC8:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DA4DC
 * Size:	000050
 */
void zen::DrawProgre::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  bl        -0x16840
	  li        r0, 0
	  stw       r0, 0x4(r31)
	  li        r3, 0x113
	  bl        -0x135194
	  lwz       r3, 0xC(r31)
	  li        r4, 0
	  bl        -0x110
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DA52C
 * Size:	0002A0
 */
int zen::DrawProgre::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r3
	  stw       r30, 0x70(r1)
	  stw       r29, 0x6C(r1)
	  mr        r29, r4
	  lwz       r30, 0xC(r3)
	  lwz       r0, 0x0(r30)
	  cmpwi     r0, 0x2
	  beq-      .loc_0xC4
	  bge-      .loc_0x44
	  cmpwi     r0, 0
	  beq-      .loc_0x54
	  bge-      .loc_0x80
	  b         .loc_0x130

	.loc_0x44:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x130
	  bge-      .loc_0x130
	  b         .loc_0xF0

	.loc_0x54:
	  addi      r3, r30, 0x8
	  bl        -0x17610
	  li        r0, 0
	  stw       r0, 0x10(r30)
	  addi      r3, r30, 0x8
	  lfs       f1, -0x41C8(r2)
	  stfs      f1, 0x14(r30)
	  lfs       f0, -0x41C4(r2)
	  stfs      f0, 0x18(r30)
	  bl        -0x17618
	  b         .loc_0x130

	.loc_0x80:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x28(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r30)
	  lfs       f1, 0x28(r30)
	  lfs       f0, 0x2C(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB4
	  addi      r3, r30, 0
	  li        r4, 0x2
	  bl        -0x1D4
	  b         .loc_0x130

	.loc_0xB4:
	  addi      r3, r30, 0x8
	  fdivs     f1, f1, f0
	  bl        -0x1765C
	  b         .loc_0x130

	.loc_0xC4:
	  lis       r3, 0x100
	  lwz       r4, 0x28(r29)
	  addi      r0, r3, 0x1000
	  and.      r0, r4, r0
	  beq-      .loc_0x130
	  li        r3, 0x111
	  bl        -0x135294
	  addi      r3, r30, 0
	  li        r4, 0x3
	  bl        -0x210
	  b         .loc_0x130

	.loc_0xF0:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x28(r30)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r30)
	  lfs       f1, 0x28(r30)
	  lfs       f0, 0x2C(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x124
	  addi      r3, r30, 0
	  li        r4, 0x4
	  bl        -0x244
	  b         .loc_0x130

	.loc_0x124:
	  addi      r3, r30, 0x8
	  fdivs     f1, f1, f0
	  bl        -0x176CC

	.loc_0x130:
	  addi      r3, r30, 0x10
	  bl        -0x10834
	  lwz       r3, 0x4(r30)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  mr        r4, r29
	  bl        -0x161AC
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x234
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x1D0(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x178
	  lwz       r0, 0x110(r3)
	  b         .loc_0x190

	.loc_0x178:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x18C
	  li        r0, -0x1
	  b         .loc_0x190

	.loc_0x18C:
	  lwz       r0, 0x110(r3)

	.loc_0x190:
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1F0
	  bge-      .loc_0x234
	  cmpwi     r0, 0
	  bge-      .loc_0x1A8
	  b         .loc_0x234

	.loc_0x1A8:
	  lwz       r3, 0xC(r31)
	  li        r7, 0
	  li        r6, 0x1
	  lwz       r5, 0x20(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r5, 0x24(r3)
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r5, 0x24(r3)
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r5)
	  bl        -0x310
	  b         .loc_0x234

	.loc_0x1F0:
	  lwz       r3, 0xC(r31)
	  li        r7, 0
	  li        r6, 0x1
	  lwz       r5, 0x20(r3)
	  li        r4, 0x1
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r5, 0x24(r3)
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r5)
	  lwz       r5, 0x20(r3)
	  lbz       r0, 0xC(r5)
	  rlwimi    r0,r6,7,24,24
	  stb       r0, 0xC(r5)
	  bl        -0x358

	.loc_0x234:
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x4
	  beq-      .loc_0x248
	  b         .loc_0x280

	.loc_0x248:
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x1D0(r3)
	  cmpwi     r0, 0
	  blt-      .loc_0x260
	  lwz       r3, 0x110(r3)
	  b         .loc_0x278

	.loc_0x260:
	  lbz       r0, 0x1D4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x274
	  li        r3, -0x1
	  b         .loc_0x278

	.loc_0x274:
	  lwz       r3, 0x110(r3)

	.loc_0x278:
	  addi      r0, r3, 0x1
	  stw       r0, 0x4(r31)

	.loc_0x280:
	  lwz       r3, 0x4(r31)
	  lwz       r0, 0x7C(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  lwz       r29, 0x6C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801DA7CC
 * Size:	000048
 */
void zen::DrawProgre::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  bl        -0x15F04
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x4(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
