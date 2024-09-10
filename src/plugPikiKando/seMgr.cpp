#include "types.h"

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
 * Address:	800A3428
 * Size:	000180
 */
SeMgr::SeMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  addi      r0, r4, 0x738C
	  lis       r4, 0x802B
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0x1B70
	  subi      r4, r13, 0x5380
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lis       r3, 0x8022
	  stw       r0, 0x0(r29)
	  addi      r0, r3, 0x737C
	  addi      r3, r29, 0
	  stw       r0, 0x0(r29)
	  stw       r31, 0x10(r29)
	  stw       r31, 0xC(r29)
	  stw       r31, 0x8(r29)
	  bl        -0x7E5A8
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x0(r29)
	  addi      r3, r29, 0
	  subi      r4, r13, 0x5380
	  bl        -0x62D58
	  lis       r3, 0x802B
	  addi      r0, r3, 0x1CC4
	  stw       r0, 0x0(r29)
	  li        r0, 0x80
	  stw       r31, 0x20(r29)
	  stw       r31, 0x24(r29)
	  stw       r0, 0x28(r29)
	  lwz       r0, 0x28(r29)
	  rlwinm    r3,r0,3,0,28
	  bl        -0x5C4B8
	  stw       r3, 0x2C(r29)
	  addi      r3, r29, 0
	  li        r4, 0x7
	  subi      r5, r13, 0x5378
	  bl        0x100
	  addi      r3, r29, 0
	  li        r4, 0x8
	  subi      r5, r13, 0x5370
	  bl        0xF0
	  addi      r3, r29, 0
	  li        r4, 0x6
	  subi      r5, r13, 0x5368
	  bl        0xE0
	  addi      r3, r29, 0
	  addi      r5, r30, 0xC
	  li        r4, 0
	  bl        0xD0
	  lis       r31, 0x1
	  addi      r3, r29, 0
	  subi      r4, r31, 0x7FFE
	  addi      r5, r30, 0x18
	  bl        0xBC
	  addi      r3, r29, 0
	  addi      r5, r30, 0x24
	  li        r4, 0x3
	  bl        0xAC
	  addi      r3, r29, 0
	  subi      r4, r31, 0x7FF9
	  addi      r5, r30, 0x34
	  bl        0x9C
	  addi      r3, r29, 0
	  subi      r4, r31, 0x7FFD
	  addi      r5, r30, 0x40
	  bl        0x8C
	  addi      r3, r29, 0
	  addi      r5, r30, 0x54
	  li        r4, 0x2
	  bl        0x7C
	  addi      r3, r29, 0
	  subi      r4, r31, 0x7FFA
	  addi      r5, r30, 0x60
	  bl        0x6C
	  addi      r3, r29, 0
	  subi      r4, r31, 0x7FFC
	  addi      r5, r30, 0x6C
	  bl        0x5C
	  addi      r3, r29, 0
	  subi      r4, r31, 0x7FFB
	  addi      r5, r30, 0x7C
	  bl        0x4C
	  mr        r3, r29
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A35A8
 * Size:	000028
 */
void SeMgr::playNaviSound(s32, s32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r4, 0
	  stw       r0, 0x4(r1)
	  addi      r4, r5, 0
	  stwu      r1, -0x8(r1)
	  bl        -0x8B3BC
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void SeMgr::findInfo(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A35D0
 * Size:	000034
 */
void SeMgr::addInfo(int, char*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x24(r3)
	  lwz       r6, 0x2C(r3)
	  rlwinm    r0,r0,3,0,28
	  stwx      r4, r6, r0
	  lwz       r0, 0x24(r3)
	  lwz       r4, 0x2C(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r4, r4, r0
	  stw       r5, 0x4(r4)
	  lwz       r4, 0x24(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3604
 * Size:	000004
 */
void SeMgr::update() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::play(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SeMgr::stop(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::playBGM(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void SeMgr::stopBGM()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void SeMgr::stopSoundAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A3608
 * Size:	000010
 */
void SeMgr::joinBattle()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x20(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x20(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3618
 * Size:	000024
 */
void SeMgr::leaveBattle()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x20(r3)
	  subi      r0, r4, 0x1
	  stw       r0, 0x20(r3)
	  lwz       r0, 0x20(r3)
	  cmpwi     r0, 0
	  bgtlr-
	  li        r0, 0
	  stw       r0, 0x20(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A363C
 * Size:	000038
 */
void SeMgr::setPikiNum(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bne-      .loc_0x20
	  li        r3, 0
	  bl        -0x8AF14
	  b         .loc_0x28

	.loc_0x20:
	  mr        r3, r4
	  bl        -0x8AF20

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3674
 * Size:	0000E4
 */
void SeWin::doRender(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r4
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r30)
	  lis       r4, 0x802B
	  addi      r6, r4, 0x1BF8
	  lwz       r12, 0x2C(r12)
	  mr        r3, r30
	  addi      r4, r31, 0
	  mtlr      r12
	  li        r5, 0x20
	  blrl
	  lwz       r5, 0x4C(r30)
	  addi      r3, r1, 0x20
	  crclr     6, 0x6
	  subi      r4, r13, 0x5360
	  bl        0x172EC4
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  addi      r6, r1, 0x20
	  lwz       r12, 0x2C(r12)
	  li        r5, 0x50
	  mtlr      r12
	  blrl
	  lwz       r4, 0x3030(r13)
	  addi      r3, r1, 0x20
	  lwz       r0, 0x4C(r30)
	  crclr     6, 0x6
	  lwz       r4, 0x2C(r4)
	  rlwinm    r0,r0,3,0,28
	  add       r4, r4, r0
	  lwz       r5, 0x4(r4)
	  subi      r4, r13, 0x5358
	  bl        0x172E7C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  addi      r6, r1, 0x20
	  lwz       r12, 0x2C(r12)
	  li        r5, 0x8C
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3758
 * Size:	0002E4
 */
void SeWin::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  mr        r31, r3
	  lwz       r0, 0x28(r3)
	  cmpwi     r0, 0x1001
	  beq-      .loc_0xBC
	  bge-      .loc_0x30
	  cmpwi     r0, 0x1000
	  bge-      .loc_0x3C
	  b         .loc_0x2D0

	.loc_0x30:
	  cmpwi     r0, 0x1003
	  bge-      .loc_0x2D0
	  b         .loc_0x8C

	.loc_0x3C:
	  lwz       r3, 0x54(r31)
	  subi      r0, r3, 0x1
	  stw       r0, 0x54(r31)
	  lwz       r3, 0x24(r31)
	  addi      r0, r3, 0x20
	  stw       r0, 0x24(r31)
	  lwz       r0, 0x54(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x68
	  li        r0, 0x1001
	  stw       r0, 0x28(r31)

	.loc_0x68:
	  lwz       r3, 0x48(r31)
	  bl        -0x62CF0
	  fabs      f1, f1
	  lfs       f0, -0x7290(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2D0
	  li        r0, 0x1
	  stb       r0, 0x60(r31)
	  b         .loc_0x2D0

	.loc_0x8C:
	  lwz       r3, 0x54(r31)
	  subi      r0, r3, 0x1
	  stw       r0, 0x54(r31)
	  lwz       r3, 0x24(r31)
	  addi      r0, r3, 0x20
	  stw       r0, 0x24(r31)
	  lwz       r0, 0x54(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x2D0
	  li        r0, 0x1003
	  stw       r0, 0x28(r31)
	  b         .loc_0x2D0

	.loc_0xBC:
	  lbz       r0, 0x60(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xE8
	  lwz       r3, 0x48(r31)
	  bl        -0x62D50
	  fabs      f1, f1
	  lfs       f0, -0x7290(r2)
	  fcmpo     cr0, f1, f0
	  bgt-      .loc_0x2D0
	  li        r0, 0
	  stb       r0, 0x60(r31)

	.loc_0xE8:
	  lwz       r3, 0x48(r31)
	  bl        -0x62D70
	  lfs       f0, -0x7290(r2)
	  li        r5, 0x1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x174
	  lwz       r0, 0x58(r31)
	  cmpwi     r0, 0
	  bgt-      .loc_0x118
	  lfs       f0, -0x728C(r2)
	  stfs      f0, 0x5C(r31)
	  b         .loc_0x12C

	.loc_0x118:
	  lfs       f1, 0x5C(r31)
	  lfs       f0, -0x7288(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x12C
	  li        r5, 0

	.loc_0x12C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x5C(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C(r31)
	  lfs       f1, 0x5C(r31)
	  lfs       f0, -0x7284(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x168
	  lwz       r3, 0x58(r31)
	  cmpwi     r3, 0x6
	  bge-      .loc_0x204
	  addi      r0, r3, 0x1
	  stw       r0, 0x58(r31)
	  b         .loc_0x204

	.loc_0x168:
	  li        r0, 0x1
	  stw       r0, 0x58(r31)
	  b         .loc_0x204

	.loc_0x174:
	  lfs       f0, -0x7280(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1F4
	  lwz       r0, 0x58(r31)
	  cmpwi     r0, 0
	  blt-      .loc_0x198
	  lfs       f0, -0x728C(r2)
	  stfs      f0, 0x5C(r31)
	  b         .loc_0x1AC

	.loc_0x198:
	  lfs       f1, 0x5C(r31)
	  lfs       f0, -0x7288(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1AC
	  li        r5, 0

	.loc_0x1AC:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x5C(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C(r31)
	  lfs       f1, 0x5C(r31)
	  lfs       f0, -0x7284(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1E8
	  lwz       r3, 0x58(r31)
	  cmpwi     r3, -0x6
	  ble-      .loc_0x204
	  subi      r0, r3, 0x1
	  stw       r0, 0x58(r31)
	  b         .loc_0x204

	.loc_0x1E8:
	  li        r0, -0x1
	  stw       r0, 0x58(r31)
	  b         .loc_0x204

	.loc_0x1F4:
	  li        r0, 0
	  stw       r0, 0x58(r31)
	  lfs       f0, -0x728C(r2)
	  stfs      f0, 0x5C(r31)

	.loc_0x204:
	  lwz       r4, 0x58(r31)
	  cmpwi     r4, 0
	  beq-      .loc_0x26C
	  rlwinm.   r0,r5,0,24,31
	  beq-      .loc_0x26C
	  cmpwi     r4, 0
	  ble-      .loc_0x250
	  lwz       r3, 0x3030(r13)
	  lwz       r5, 0x4C(r31)
	  lwz       r3, 0x24(r3)
	  add       r0, r4, r5
	  cmpw      r0, r3
	  blt-      .loc_0x240
	  sub       r3, r3, r5
	  subi      r4, r3, 0x1

	.loc_0x240:
	  lwz       r0, 0x4C(r31)
	  add       r0, r0, r4
	  stw       r0, 0x4C(r31)
	  b         .loc_0x26C

	.loc_0x250:
	  lwz       r0, 0x4C(r31)
	  add.      r0, r4, r0
	  bge-      .loc_0x260
	  li        r4, 0

	.loc_0x260:
	  lwz       r0, 0x4C(r31)
	  add       r0, r0, r4
	  stw       r0, 0x4C(r31)

	.loc_0x26C:
	  lwz       r3, 0x48(r31)
	  lwz       r3, 0x28(r3)
	  rlwinm.   r0,r3,0,19,19
	  beq-      .loc_0x2A4
	  lwz       r3, 0x50(r31)
	  bl        -0x8CEF8
	  lwz       r3, 0x3030(r13)
	  lwz       r0, 0x4C(r31)
	  lwz       r3, 0x2C(r3)
	  rlwinm    r0,r0,3,0,28
	  add       r3, r3, r0
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x50(r31)
	  b         .loc_0x2D0

	.loc_0x2A4:
	  rlwinm.   r0,r3,0,18,18
	  bne-      .loc_0x2B4
	  rlwinm.   r0,r3,0,15,15
	  beq-      .loc_0x2D0

	.loc_0x2B4:
	  lwz       r3, 0x4C(r31)
	  bl        -0x8CF30
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x2D0:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3A3C
 * Size:	00007C
 */
void SeWin::open()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x28(r3)
	  cmpwi     r0, 0x1000
	  beq-      .loc_0x68
	  mr        r3, r31
	  bl        0x6E5A8
	  mr        r3, r31
	  bl        0x6E3AC
	  lwz       r4, 0x24(r31)
	  li        r3, -0x78
	  li        r0, 0
	  addi      r4, r4, 0x78
	  srawi     r4, r4, 0x5
	  addze     r4, r4
	  stw       r4, 0x54(r31)
	  stw       r3, 0x24(r31)
	  stw       r0, 0x58(r31)
	  stw       r0, 0x50(r31)
	  stw       r0, 0x4C(r31)
	  lfs       f0, -0x728C(r2)
	  stfs      f0, 0x5C(r31)
	  stb       r0, 0x60(r31)

	.loc_0x68:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A3AB8
 * Size:	00004C
 */
void SeWin::close()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x28(r3)
	  cmpwi     r0, 0x1002
	  beq-      .loc_0x38
	  mr        r3, r31
	  bl        0x6E52C
	  mr        r3, r31
	  bl        0x6E33C
	  li        r0, 0xF
	  stw       r0, 0x54(r31)

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
