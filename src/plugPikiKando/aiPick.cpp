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
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800BCAFC
 * Size:	0000E0
 */
ActPickItem::ActPickItem(Piki*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r3, 0x8(r1)
	  lwz       r30, 0x8(r1)
	  addi      r3, r30, 0
	  bl        0x72A8
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7ED0
	  stw       r0, 0x0(r30)
	  li        r4, 0
	  lis       r3, 0x802B
	  stw       r4, 0x14(r30)
	  addi      r0, r3, 0x6EDC
	  lis       r3, 0x802B
	  stw       r0, 0x0(r30)
	  addi      r0, r3, 0x6D78
	  li        r3, 0x24
	  stw       r4, 0x18(r30)
	  stw       r0, 0x10(r30)
	  bl        -0x75B5C
	  mr.       r30, r3
	  beq-      .loc_0x7C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x1C0C

	.loc_0x7C:
	  li        r3, 0x20
	  bl        -0x75B78
	  mr.       r29, r3
	  beq-      .loc_0x98
	  addi      r3, r29, 0
	  addi      r4, r31, 0
	  bl        -0x15198

	.loc_0x98:
	  lwz       r3, 0x8(r1)
	  addi      r5, r30, 0
	  addi      r7, r29, 0
	  crclr     6, 0x6
	  li        r4, 0x2
	  li        r6, 0
	  li        r8, 0
	  bl        0x77C0
	  lwz       r3, 0x8(r1)
	  li        r0, 0
	  stw       r0, 0x18(r3)
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
 * Address:	800BCBDC
 * Size:	000180
 */
void ActPickItem::findItem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stmw      r27, 0x2C(r1)
	  mr        r27, r3
	  li        r28, 0
	  lwz       r30, 0x30AC(r13)
	  lfs       f31, -0x6C58(r2)
	  lwz       r12, 0x0(r30)
	  addi      r3, r30, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x108

	.loc_0x40:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x68
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3
	  b         .loc_0x84

	.loc_0x68:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x84:
	  fmr       f1, f31
	  lwz       r4, 0xC(r27)
	  mr        r3, r31
	  bl        -0x2F3DC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xEC
	  lwz       r0, 0x6C(r31)
	  cmpwi     r0, 0xE
	  bne-      .loc_0xEC
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xEC
	  lwz       r0, 0x2A8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xEC
	  mr        r3, r31
	  lwz       r4, 0xC(r27)
	  bl        -0x2FE38
	  fcmpo     cr0, f1, f31
	  bge-      .loc_0xEC
	  fmr       f31, f1
	  mr        r28, r31

	.loc_0xEC:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x108:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x130
	  li        r0, 0x1
	  b         .loc_0x15C

	.loc_0x130:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x158
	  li        r0, 0x1
	  b         .loc_0x15C

	.loc_0x158:
	  li        r0, 0

	.loc_0x15C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x40
	  mr        r3, r28
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
 * Address:	800BCD5C
 * Size:	0000B0
 */
void ActPickItem::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr.       r31, r4
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r3, 0xC(r3)
	  stb       r0, 0x408(r3)
	  bne-      .loc_0x38
	  mr        r3, r30
	  bl        -0x1B0
	  mr        r31, r3

	.loc_0x38:
	  cmplwi    r31, 0
	  beq-      .loc_0x80
	  lwz       r3, 0x18(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  beq-      .loc_0x5C
	  bl        0x275C0
	  li        r0, 0
	  stw       r0, 0x18(r30)

	.loc_0x5C:
	  stw       r31, 0x18(r30)
	  lwz       r3, 0x18(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  bl        0x27594

	.loc_0x70:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x7140
	  b         .loc_0x98

	.loc_0x80:
	  lwz       r3, 0x18(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  bl        0x27584
	  li        r0, 0
	  stw       r0, 0x18(r30)

	.loc_0x98:
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
 * Address:	800BCE0C
 * Size:	0000E8
 */
void ActPickItem::exec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0xC(r3)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x44
	  li        r0, 0
	  stb       r0, 0x408(r3)
	  li        r0, 0x6
	  li        r3, 0x2
	  lwz       r4, 0xC(r30)
	  stb       r0, 0x400(r4)
	  b         .loc_0xD0

	.loc_0x44:
	  lwz       r31, 0x18(r30)
	  cmplwi    r31, 0
	  addi      r3, r31, 0
	  bne-      .loc_0x5C
	  li        r3, 0x1
	  b         .loc_0xD0

	.loc_0x5C:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x7C
	  li        r3, 0x1
	  b         .loc_0xD0

	.loc_0x7C:
	  lwz       r0, 0x2A8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xA4
	  lwz       r3, 0xC(r30)
	  cmplw     r0, r3
	  beq-      .loc_0xA4
	  li        r0, 0x7
	  stb       r0, 0x400(r3)
	  li        r3, 0x1
	  b         .loc_0xD0

	.loc_0xA4:
	  mr        r3, r30
	  bl        0x7140
	  cmpwi     r3, 0x1
	  bne-      .loc_0xD0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0

	.loc_0xD0:
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
 * Address:	800BCEF4
 * Size:	000040
 */
void ActPickItem::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lwz       r3, 0x18(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C
	  bl        0x27458
	  li        r0, 0
	  stw       r0, 0x18(r31)

	.loc_0x2C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
ActFlower::ActFlower(Piki*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800BCF34
 * Size:	00015C
 */
void ActFlower::init(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x20
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  lfs       f0, -0x47D0(r13)
	  lwz       r3, 0xC(r3)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x47CC(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x47C8(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x47C4(r13)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, -0x47C0(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x47BC(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x490(r4)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r4, 0
	  stb       r4, 0x1C(r31)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x94
	  li        r0, 0x1
	  stb       r0, 0x1D(r31)
	  b         .loc_0x140

	.loc_0x94:
	  stb       r4, 0x1D(r31)
	  lwz       r3, 0xC(r31)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x514(r3)
	  lwz       r0, 0x128(r4)
	  addi      r3, r3, 0x1
	  cmpw      r3, r0
	  blt-      .loc_0xF8
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0xC4
	  lwz       r29, 0x14(r31)

	.loc_0xC4:
	  addi      r3, r1, 0x30
	  li        r4, 0x12
	  bl        0x61F58
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x38
	  li        r4, 0x12
	  bl        0x61F78
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xD9B4
	  b         .loc_0x138

	.loc_0xF8:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x108
	  lwz       r29, 0x14(r31)

	.loc_0x108:
	  addi      r3, r1, 0x20
	  li        r4, 0x11
	  bl        0x61F14
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x28
	  li        r4, 0x11
	  bl        0x61F34
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xD970

	.loc_0x138:
	  lfs       f0, -0x6C54(r2)
	  stfs      f0, 0x18(r31)

	.loc_0x140:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BD090
 * Size:	000120
 */
void ActFlower::animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x48(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x34
	  bge-      .loc_0x108
	  cmpwi     r0, 0
	  bge-      .loc_0x100
	  b         .loc_0x108

	.loc_0x34:
	  lwz       r6, 0xC(r31)
	  lis       r4, 0x802B
	  subi      r0, r4, 0x3064
	  lfs       f0, -0x6C50(r2)
	  lwz       r30, 0x2AC(r6)
	  lis       r3, 0x802B
	  stw       r0, 0x38(r1)
	  subi      r0, r3, 0x2E74
	  addi      r4, r1, 0x38
	  stw       r6, 0x3C(r1)
	  addi      r3, r30, 0
	  stw       r0, 0x38(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x32430
	  lwz       r4, 0xC(r31)
	  lwz       r3, 0x514(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x514(r4)
	  lwz       r3, 0xC(r31)
	  lwz       r5, 0x224(r3)
	  lwz       r6, 0x514(r3)
	  lwz       r0, 0x128(r5)
	  cmpw      r6, r0
	  blt-      .loc_0xDC
	  lwz       r12, 0x0(r3)
	  li        r4, 0x2
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r31)
	  lwzu      r0, 0x514(r3)
	  cmpwi     r0, 0x64
	  ble-      .loc_0x108
	  li        r0, 0x64
	  stw       r0, 0x0(r3)
	  b         .loc_0x108

	.loc_0xDC:
	  lwz       r0, 0x118(r5)
	  cmpw      r6, r0
	  blt-      .loc_0x108
	  lwz       r12, 0x0(r3)
	  li        r4, 0x1
	  lwz       r12, 0x130(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x108

	.loc_0x100:
	  li        r0, 0x1
	  stb       r0, 0x1C(r31)

	.loc_0x108:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BD1B0
 * Size:	000038
 */
void ActFlower::cleanup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0xC(r3)
	  lwz       r3, 0x490(r4)
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
 * Address:	800BD1E8
 * Size:	000074
 */
void ActFlower::exec()
{
	/*
	.loc_0x0:
	  lbz       r0, 0x1D(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x18(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18(r3)
	  lwz       r4, 0xC(r3)
	  lwz       r4, 0x2AC(r4)
	  cmplwi    r4, 0
	  beq-      .loc_0x58
	  lfs       f1, -0x6C50(r2)
	  lfs       f0, 0x18(r3)
	  lfs       f2, -0x6C4C(r2)
	  fsubs     f0, f1, f0
	  fmuls     f0, f2, f0
	  stfs      f0, 0x7C(r4)
	  stfs      f0, 0x80(r4)
	  stfs      f0, 0x84(r4)

	.loc_0x58:
	  lbz       r0, 0x1C(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  li        r3, 0x2
	  blr

	.loc_0x6C:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BD25C
 * Size:	000080
 */
ActFlower::~ActFlower()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x64
	  lis       r3, 0x802B
	  addi      r3, r3, 0x6E14
	  stw       r3, 0x0(r30)
	  addi      r6, r3, 0x68
	  addi      r0, r30, 0x20
	  lwz       r5, 0x14(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  stw       r6, 0x0(r5)
	  lwz       r5, 0x14(r30)
	  sub       r0, r0, r5
	  stw       r0, 0x4(r5)
	  bl        0x6B5C
	  extsh.    r0, r31
	  ble-      .loc_0x64
	  mr        r3, r30
	  bl        -0x76110

	.loc_0x64:
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
 * Address:	800BD2DC
 * Size:	000074
 */
ActPickItem::~ActPickItem()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x58
	  lis       r3, 0x802B
	  addi      r0, r3, 0x6EDC
	  stw       r0, 0x0(r30)
	  beq-      .loc_0x48
	  lis       r3, 0x802C
	  subi      r0, r3, 0x7ED0
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        0x6AE8

	.loc_0x48:
	  extsh.    r0, r31
	  ble-      .loc_0x58
	  mr        r3, r30
	  bl        -0x76184

	.loc_0x58:
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
 * Address:	800BD350
 * Size:	000014
 */
void ActFlower::@32 @4 @animationKeyUpdated(PaniAnimKeyEvent&)
{
	/*
	.loc_0x0:
	  li        r11, 0x4
	  lwzx      r11, r3, r11
	  add       r3, r3, r11
	  subi      r3, r3, 0x20
	  b         -0x2D0
	*/
}
