#include "zen/ogRader.h"
#include "Vector.h"
#include "P2D/Pane.h"

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
 * Address:	........
 * Size:	000058
 */
Vector3f zen::ogRaderMgr::ogCalcDispXZ(Vector3f)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::setOffsetSub(P2DPicture*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801850A0
 * Size:	000970
 */
zen::ogRaderMgr::ogRaderMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1A0(r1)
	  stfd      f31, 0x198(r1)
	  stmw      r26, 0x180(r1)
	  addi      r31, r3, 0
	  lis       r3, 0x802D
	  addi      r29, r3, 0x50B8
	  li        r3, 0xF8
	  lfs       f0, -0x5014(r2)
	  stfs      f0, 0x438(r31)
	  stfs      f0, 0x434(r31)
	  stfs      f0, 0x430(r31)
	  stfs      f0, 0x444(r31)
	  stfs      f0, 0x440(r31)
	  stfs      f0, 0x43C(r31)
	  bl        -0x13E0DC
	  addi      r30, r3, 0
	  mr.       r0, r30
	  beq-      .loc_0xA8
	  addi      r26, r30, 0
	  addi      r3, r1, 0x150
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x2E520
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0x150
	  addi      r3, r26, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x2B8A4
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  stb       r0, 0xEC(r30)
	  stw       r0, 0xF0(r30)
	  stw       r0, 0xF4(r30)

	.loc_0xA8:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  mr        r27, r30
	  lha       r4, 0x26(r3)
	  mulli     r0, r4, 0xC
	  add       r3, r29, r0
	  lfs       f0, 0x1C(r3)
	  cmpwi     r4, 0x2
	  stfs      f0, 0x24(r31)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x28(r31)
	  lfs       f0, 0x24(r3)
	  stfs      f0, 0x2C(r31)
	  beq-      .loc_0x198
	  bge-      .loc_0xF8
	  cmpwi     r4, 0
	  beq-      .loc_0x108
	  bge-      .loc_0x150
	  b         .loc_0x270

	.loc_0xF8:
	  cmpwi     r4, 0x4
	  beq-      .loc_0x228
	  bge-      .loc_0x270
	  b         .loc_0x1E0

	.loc_0x108:
	  li        r0, 0
	  stw       r0, 0x54(r31)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x58
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x2DA3C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r4, 0x6D61
	  addi      r4, r4, 0x7030
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)
	  b         .loc_0x2B4

	.loc_0x150:
	  li        r0, 0x1
	  stw       r0, 0x54(r31)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x70
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x2D9F4
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r4, 0x6D61
	  addi      r4, r4, 0x7031
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)
	  b         .loc_0x2B4

	.loc_0x198:
	  li        r0, 0x2
	  stw       r0, 0x54(r31)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x88
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x2D9AC
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r4, 0x6D61
	  addi      r4, r4, 0x7032
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)
	  b         .loc_0x2B4

	.loc_0x1E0:
	  li        r0, 0x3
	  stw       r0, 0x54(r31)
	  addi      r3, r27, 0
	  addi      r4, r29, 0xA0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x2D964
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r4, 0x6D61
	  addi      r4, r4, 0x7033
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)
	  b         .loc_0x2B4

	.loc_0x228:
	  li        r0, 0x4
	  stw       r0, 0x54(r31)
	  addi      r3, r27, 0
	  addi      r4, r29, 0xB8
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x2D91C
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r4, 0x6D61
	  addi      r4, r4, 0x7034
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)
	  b         .loc_0x2B4

	.loc_0x270:
	  li        r0, 0
	  stw       r0, 0x54(r31)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x58
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x2D8D4
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r4, 0x6D61
	  addi      r4, r4, 0x7030
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x4C(r31)

	.loc_0x2B4:
	  li        r3, 0x198
	  bl        -0x13E354
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x2D0
	  mr        r4, r27
	  bl        -0x67EC

	.loc_0x2D0:
	  stw       r26, 0x50(r31)
	  lis       r4, 0x726F
	  addi      r3, r27, 0
	  lfs       f0, -0x5014(r2)
	  addi      r4, r4, 0x6F74
	  li        r5, 0x1
	  stfs      f0, 0x450(r31)
	  stw       r30, 0x3C(r31)
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x58(r31)
	  addi      r3, r27, 0
	  lis       r29, 0x6D62
	  lwz       r12, 0x0(r27)
	  addi      r4, r29, 0x7069
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x5C(r31)
	  addi      r3, r27, 0
	  lis       r28, 0x6D72
	  lwz       r12, 0x0(r27)
	  addi      r4, r28, 0x7069
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x60(r31)
	  addi      r3, r27, 0
	  lis       r26, 0x6D79
	  lwz       r12, 0x0(r27)
	  addi      r4, r26, 0x7069
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x64(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6D6D
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x7069
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x68(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x7061
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x7274
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x80(r31)
	  addi      r3, r27, 0
	  lis       r4, 0x6F72
	  lwz       r12, 0x0(r27)
	  addi      r4, r4, 0x696D
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x6C(r31)
	  addi      r3, r27, 0
	  addi      r4, r29, 0x6369
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x70(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x6369
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x74(r31)
	  addi      r3, r27, 0
	  addi      r4, r26, 0x6369
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x78(r31)
	  addi      r3, r27, 0
	  addi      r4, r28, 0x6F69
	  lwz       r12, 0x0(r27)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x7C(r31)
	  li        r29, 0
	  lwz       r5, 0x6C(r31)
	  lha       r4, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  lha       r3, 0x18(r5)
	  sub       r4, r0, r4
	  lha       r0, 0x1C(r5)
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  extsh     r0, r0
	  sth       r0, 0xB8(r5)
	  extsh     r0, r4
	  sth       r0, 0xBA(r5)
	  lwz       r5, 0x70(r31)
	  lha       r4, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  lha       r3, 0x18(r5)
	  sub       r4, r0, r4
	  lha       r0, 0x1C(r5)
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  extsh     r0, r0
	  sth       r0, 0xB8(r5)
	  extsh     r0, r4
	  sth       r0, 0xBA(r5)
	  lwz       r5, 0x74(r31)
	  lha       r4, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  lha       r3, 0x18(r5)
	  sub       r4, r0, r4
	  lha       r0, 0x1C(r5)
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  extsh     r0, r0
	  sth       r0, 0xB8(r5)
	  extsh     r0, r4
	  sth       r0, 0xBA(r5)
	  lwz       r5, 0x78(r31)
	  lha       r4, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  lha       r3, 0x18(r5)
	  sub       r4, r0, r4
	  lha       r0, 0x1C(r5)
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  extsh     r0, r0
	  sth       r0, 0xB8(r5)
	  extsh     r0, r4
	  sth       r0, 0xBA(r5)
	  lwz       r5, 0x7C(r31)
	  lha       r4, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  lha       r3, 0x18(r5)
	  sub       r4, r0, r4
	  lha       r0, 0x1C(r5)
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  extsh     r0, r0
	  sth       r0, 0xB8(r5)
	  extsh     r0, r4
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x5C(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x60(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x64(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x68(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x80(r31)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r29,7,24,24
	  stb       r0, 0xC(r3)
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  lis       r4, 0x695F
	  addi      r4, r4, 0x6273
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  stw       r3, 0x424(r31)
	  li        r0, 0xFF
	  lis       r3, 0x6666
	  stb       r0, 0x178(r1)
	  addi      r26, r31, 0x100
	  addi      r30, r3, 0x6667
	  stb       r0, 0x179(r1)
	  li        r27, 0
	  stb       r0, 0x17A(r1)
	  stb       r0, 0x17B(r1)
	  stb       r29, 0x174(r1)
	  lfs       f31, -0x5030(r2)
	  stb       r29, 0x175(r1)
	  stb       r29, 0x176(r1)
	  stb       r29, 0x177(r1)

	.loc_0x638:
	  li        r3, 0x114
	  bl        -0x13E6D8
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x66C
	  lwz       r4, 0x5C(r31)
	  lbz       r0, 0xF1(r4)
	  cmplwi    r0, 0
	  ble-      .loc_0x664
	  lwz       r4, 0xEC(r4)
	  b         .loc_0x668

	.loc_0x664:
	  li        r4, 0

	.loc_0x668:
	  bl        0x2C470

	.loc_0x66C:
	  stw       r28, 0x0(r26)
	  lwz       r3, 0x0(r26)
	  lwz       r5, 0x424(r31)
	  addic.    r4, r3, 0xD0
	  beq-      .loc_0x684
	  addi      r4, r4, 0xC

	.loc_0x684:
	  addi      r3, r5, 0xD0
	  bl        0x2DD94
	  mulhw     r6, r30, r27
	  lwz       r3, 0x0(r26)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  srawi     r0, r6, 0x2
	  rlwinm    r4,r0,1,31,31
	  mtlr      r12
	  add       r0, r0, r4
	  mulli     r5, r0, 0xA
	  srawi     r0, r6, 0x2
	  rlwinm    r4,r0,1,31,31
	  sub       r5, r27, r5
	  add       r0, r0, r4
	  mulli     r4, r5, 0xA
	  mulli     r5, r0, 0xA
	  addi      r4, r4, 0xA
	  addi      r5, r5, 0xA
	  blrl
	  lwz       r3, 0x0(r26)
	  addi      r27, r27, 0x1
	  li        r28, 0
	  stfs      f31, 0xC0(r3)
	  cmpwi     r27, 0x64
	  stfs      f31, 0xC4(r3)
	  stfs      f31, 0xC8(r3)
	  lwz       r3, 0x0(r26)
	  lwz       r0, 0x178(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0x0(r26)
	  lwz       r0, 0x174(r1)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0x0(r26)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r28,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r5, 0x0(r26)
	  addi      r26, r26, 0x8
	  lha       r4, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  lha       r3, 0x18(r5)
	  sub       r4, r0, r4
	  lha       r0, 0x1C(r5)
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  extsh     r0, r0
	  sth       r0, 0xB8(r5)
	  extsh     r0, r4
	  sth       r0, 0xBA(r5)
	  blt+      .loc_0x638
	  lis       r3, 0x6666
	  lfs       f31, -0x5010(r2)
	  addi      r29, r31, 0
	  addi      r30, r3, 0x6667

	.loc_0x76C:
	  li        r3, 0x114
	  bl        -0x13E80C
	  addi      r26, r3, 0
	  mr.       r3, r26
	  beq-      .loc_0x7A0
	  lwz       r4, 0x80(r31)
	  lbz       r0, 0xF1(r4)
	  cmplwi    r0, 0
	  ble-      .loc_0x798
	  lwz       r4, 0xEC(r4)
	  b         .loc_0x79C

	.loc_0x798:
	  li        r4, 0

	.loc_0x79C:
	  bl        0x2C33C

	.loc_0x7A0:
	  stw       r26, 0x84(r29)
	  lwz       r3, 0x84(r29)
	  lwz       r5, 0x424(r31)
	  addic.    r4, r3, 0xD0
	  beq-      .loc_0x7B8
	  addi      r4, r4, 0xC

	.loc_0x7B8:
	  addi      r3, r5, 0xD0
	  bl        0x2DC60
	  mulhw     r6, r30, r28
	  lwz       r3, 0x84(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  srawi     r0, r6, 0x2
	  rlwinm    r4,r0,1,31,31
	  mtlr      r12
	  add       r0, r0, r4
	  mulli     r5, r0, 0xA
	  srawi     r0, r6, 0x2
	  rlwinm    r4,r0,1,31,31
	  sub       r5, r28, r5
	  add       r0, r0, r4
	  mulli     r4, r5, 0xA
	  mulli     r5, r0, 0xA
	  addi      r4, r4, 0xA
	  addi      r5, r5, 0xA
	  blrl
	  lwz       r3, 0x84(r29)
	  addi      r28, r28, 0x1
	  li        r9, 0
	  stfs      f31, 0xC0(r3)
	  cmpwi     r28, 0x1E
	  stfs      f31, 0xC4(r3)
	  stfs      f31, 0xC8(r3)
	  lwz       r3, 0x84(r29)
	  lwz       r0, 0x178(r1)
	  stw       r0, 0x108(r3)
	  lwz       r3, 0x84(r29)
	  lwz       r0, 0x174(r1)
	  stw       r0, 0x10C(r3)
	  lwz       r3, 0x84(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r9,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r5, 0x84(r29)
	  addi      r29, r29, 0x4
	  lha       r4, 0x1A(r5)
	  lha       r0, 0x1E(r5)
	  lha       r3, 0x18(r5)
	  sub       r4, r0, r4
	  lha       r0, 0x1C(r5)
	  srawi     r4, r4, 0x1
	  addze     r4, r4
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  extsh     r0, r0
	  sth       r0, 0xB8(r5)
	  extsh     r0, r4
	  sth       r0, 0xBA(r5)
	  blt+      .loc_0x76C
	  lwz       r4, 0x4C(r31)
	  li        r6, 0x80
	  li        r0, 0xFF
	  lbz       r3, 0xC(r4)
	  rlwimi    r3,r9,7,24,24
	  li        r7, 0x1
	  stb       r3, 0xC(r4)
	  addi      r3, r31, 0
	  li        r4, 0
	  lwz       r8, 0x4C(r31)
	  li        r5, 0
	  stw       r8, 0x420(r31)
	  lwz       r8, 0x420(r31)
	  sth       r9, 0xB8(r8)
	  sth       r9, 0xBA(r8)
	  lwz       r8, 0x424(r31)
	  sth       r9, 0xB8(r8)
	  sth       r9, 0xBA(r8)
	  sth       r9, 0x458(r31)
	  lha       r9, 0x458(r31)
	  lwz       r8, 0x420(r31)
	  stb       r9, 0xF0(r8)
	  stb       r6, 0x178(r1)
	  stb       r6, 0x179(r1)
	  stb       r0, 0x17A(r1)
	  stb       r0, 0x17B(r1)
	  lwz       r6, 0x420(r31)
	  lwz       r0, 0x178(r1)
	  stw       r0, 0x108(r6)
	  lwz       r6, 0x420(r31)
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r6)
	  lwz       r6, 0x424(r31)
	  lbz       r0, 0xC(r6)
	  rlwimi    r0,r7,7,24,24
	  stb       r0, 0xC(r6)
	  bl        0xD8
	  lfs       f0, -0x500C(r2)
	  mr        r3, r31
	  stfs      f0, 0x428(r31)
	  lfs       f0, -0x5014(r2)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x38(r31)
	  stfs      f0, 0x454(r31)
	  lfs       f1, 0x454(r31)
	  bl        .loc_0x970
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  mr        r3, r31
	  lwz       r0, 0x1A4(r1)
	  lfd       f31, 0x198(r1)
	  lmw       r26, 0x180(r1)
	  addi      r1, r1, 0x1A0
	  mtlr      r0
	  blr

	.loc_0x970:
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::ogRaderMgr::setRaderScale(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void zen::ogRaderMgr::chaseRaderScale(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80185A10
 * Size:	00008C
 */
void zen::ogRaderMgr::setRaderAngle(f32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x28(r1)
	  li        r4, 0x2
	  lfs       f0, 0xC(r3)
	  lfs       f2, 0x10(r3)
	  fctiwz    f0, f0
	  lwz       r5, 0x58(r3)
	  fctiwz    f2, f2
	  stfd      f0, 0x18(r1)
	  stfd      f2, 0x20(r1)
	  lwz       r0, 0x1C(r1)
	  lwz       r6, 0x24(r1)
	  extsh     r0, r0
	  sth       r0, 0xB8(r5)
	  extsh     r0, r6
	  sth       r0, 0xBA(r5)
	  lwz       r3, 0x58(r3)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,5,25,26
	  stb       r0, 0xC(r3)
	  stfs      f1, 0xBC(r3)
	  lfs       f1, 0xBC(r3)
	  lfs       f0, -0x5014(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x70
	  lfs       f0, -0x5004(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r3)
	  b         .loc_0x84

	.loc_0x70:
	  lfs       f0, -0x5004(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x84
	  fsubs     f0, f1, f0
	  stfs      f0, 0xBC(r3)

	.loc_0x84:
	  addi      r1, r1, 0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80185A9C
 * Size:	000098
 */
void zen::ogRaderMgr::setRaderScroll(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r3
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x10(r3)
	  fctiwz    f1, f1
	  lwz       r3, 0x420(r3)
	  fctiwz    f0, f0
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x20(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x18(r1)
	  lwz       r6, 0x24(r1)
	  mtlr      r12
	  lwz       r0, 0x1C(r1)
	  add       r30, r4, r6
	  add       r31, r5, r0
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  blrl
	  lwz       r3, 0x424(r29)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
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
 * Address:	........
 * Size:	00025C
 */
void zen::ogRaderMgr::getOrimaPos()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000158
 */
void zen::ogRaderMgr::getContainerPos()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void zen::ogRaderMgr::getRocketPos()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80185B34
 * Size:	000220
 */
void zen::ogRaderMgr::getPartsPos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x3
	  mtctr     r0
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stfd      f28, 0xF0(r1)
	  stfd      f27, 0xE8(r1)
	  stfd      f26, 0xE0(r1)
	  stfd      f25, 0xD8(r1)
	  stfd      f24, 0xD0(r1)
	  stw       r31, 0xCC(r1)
	  addi      r31, r3, 0
	  addi      r5, r31, 0
	  stw       r30, 0xC8(r1)
	  stw       r29, 0xC4(r1)

	.loc_0x4C:
	  lwz       r3, 0x84(r5)
	  li        r4, 0
	  addi      r6, r6, 0x8
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x88(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8C(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x90(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x94(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x98(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x9C(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0xA0(r5)
	  addi      r5, r5, 0x20
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  bdnz+     .loc_0x4C
	  b         .loc_0x1D8

	.loc_0xE0:
	  subfic    r0, r6, 0x1E
	  cmpwi     r6, 0x1E
	  mtctr     r0
	  bge-      .loc_0x108

	.loc_0xF0:
	  lwz       r3, 0x84(r5)
	  addi      r5, r5, 0x4
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  bdnz+     .loc_0xF0

	.loc_0x108:
	  lwz       r3, 0x2F28(r13)
	  mr        r30, r31
	  lfs       f29, -0x5030(r2)
	  lwz       r29, 0x10(r3)
	  lfs       f30, -0x5020(r2)
	  lfs       f31, -0x501C(r2)
	  lfs       f24, -0x5018(r2)
	  lfs       f25, -0x502C(r2)
	  lfs       f26, -0x5028(r2)
	  lfs       f27, -0x5024(r2)
	  lfs       f28, -0x5010(r2)
	  b         .loc_0x1CC

	.loc_0x138:
	  addi      r3, r1, 0x88
	  addi      r4, r29, 0
	  bl        -0x10A4F0
	  lfs       f1, 0x88(r1)
	  li        r4, 0x1
	  lfs       f0, 0x90(r1)
	  fadds     f1, f31, f1
	  lwz       r3, 0x84(r30)
	  fadds     f0, f26, f0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  fmuls     f1, f30, f1
	  stb       r0, 0xC(r3)
	  fmuls     f0, f25, f0
	  lwz       r3, 0x84(r30)
	  fmuls     f1, f29, f1
	  fmuls     f0, f29, f0
	  lwz       r12, 0x0(r3)
	  fdivs     f1, f1, f24
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  fdivs     f0, f0, f27
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0xB8(r1)
	  stfd      f0, 0xB0(r1)
	  lwz       r4, 0xBC(r1)
	  lwz       r5, 0xB4(r1)
	  blrl
	  lfs       f0, 0x428(r31)
	  lwz       r3, 0x84(r30)
	  addi      r30, r30, 0x4
	  fdivs     f0, f28, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r29, 0xC(r29)

	.loc_0x1CC:
	  cmplwi    r29, 0
	  bne+      .loc_0x138
	  b         .loc_0x1E4

	.loc_0x1D8:
	  rlwinm    r0,r6,2,0,29
	  add       r5, r31, r0
	  b         .loc_0xE0

	.loc_0x1E4:
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lfd       f28, 0xF0(r1)
	  lfd       f27, 0xE8(r1)
	  lfd       f26, 0xE0(r1)
	  lfd       f25, 0xD8(r1)
	  lfd       f24, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  lwz       r29, 0xC4(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80185D54
 * Size:	0004E4
 */
void zen::ogRaderMgr::getAllPikiPos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x6
	  mtctr     r0
	  stwu      r1, -0x180(r1)
	  stfd      f31, 0x178(r1)
	  stfd      f30, 0x170(r1)
	  stfd      f29, 0x168(r1)
	  stfd      f28, 0x160(r1)
	  stfd      f27, 0x158(r1)
	  stfd      f26, 0x150(r1)
	  stfd      f25, 0x148(r1)
	  stmw      r27, 0x134(r1)
	  addi      r28, r3, 0
	  li        r3, 0
	  addi      r5, r28, 0x100
	  sth       r3, 0xFC(r28)

	.loc_0x48:
	  lwz       r3, 0x0(r5)
	  li        r4, 0
	  addi      r6, r6, 0x10
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x8(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x10(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x18(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x20(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x28(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x30(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x38(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x40(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x48(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x50(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x58(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x60(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x68(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x70(r5)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x78(r5)
	  addi      r5, r5, 0x80
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  bdnz+     .loc_0x48
	  subfic    r0, r6, 0x64
	  cmpwi     r6, 0x64
	  mtctr     r0
	  bge-      .loc_0x180

	.loc_0x168:
	  lwz       r3, 0x0(r5)
	  addi      r5, r5, 0x8
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  bdnz+     .loc_0x168

	.loc_0x180:
	  lwz       r31, 0x3068(r13)
	  addi      r29, r28, 0x100
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f31, -0x5030(r2)
	  mr        r30, r3
	  lfs       f30, -0x5020(r2)
	  lfs       f29, -0x501C(r2)
	  lfs       f28, -0x5018(r2)
	  lfs       f27, -0x502C(r2)
	  lfs       f26, -0x5028(r2)
	  lfs       f25, -0x5024(r2)
	  b         .loc_0x2CC

	.loc_0x1C0:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x1E4
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1FC

	.loc_0x1E4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1FC:
	  mr        r27, r3
	  lwz       r12, 0x0(r27)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2B0
	  lfs       f1, 0x94(r27)
	  li        r4, 0x1
	  lfs       f0, 0x9C(r27)
	  fadds     f1, f29, f1
	  lha       r0, 0x510(r27)
	  fadds     f0, f26, f0
	  sth       r0, 0x4(r29)
	  fmuls     f1, f30, f1
	  fmuls     f0, f27, f0
	  lwz       r3, 0x0(r29)
	  fmuls     f1, f31, f1
	  lbz       r0, 0xC(r3)
	  fmuls     f0, f31, f0
	  rlwimi    r0,r4,7,24,24
	  fdivs     f1, f1, f28
	  stb       r0, 0xC(r3)
	  lwz       r3, 0x0(r29)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  fdivs     f0, f0, f25
	  mtlr      r12
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x128(r1)
	  stfd      f0, 0x120(r1)
	  lwz       r4, 0x12C(r1)
	  lwz       r5, 0x124(r1)
	  blrl
	  lfs       f0, 0x428(r28)
	  lwz       r3, 0x0(r29)
	  addi      r29, r29, 0x8
	  fdivs     f0, f31, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lha       r3, 0xFC(r28)
	  addi      r0, r3, 0x1
	  sth       r0, 0xFC(r28)

	.loc_0x2B0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x2CC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x2F4
	  li        r0, 0x1
	  b         .loc_0x320

	.loc_0x2F4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x31C
	  li        r0, 0x1
	  b         .loc_0x320

	.loc_0x31C:
	  li        r0, 0

	.loc_0x320:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x1C0
	  lwz       r3, 0x30AC(r13)
	  lwz       r30, 0x64(r3)
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfs       f25, -0x5030(r2)
	  mr        r31, r3
	  lfs       f26, -0x5020(r2)
	  lfs       f27, -0x501C(r2)
	  lfs       f28, -0x5018(r2)
	  lfs       f29, -0x502C(r2)
	  lfs       f30, -0x5028(r2)
	  lfs       f31, -0x5024(r2)
	  b         .loc_0x458

	.loc_0x368:
	  cmpwi     r31, -0x1
	  bne-      .loc_0x38C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x3A4

	.loc_0x38C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x3A4:
	  lfs       f1, 0x94(r3)
	  li        r0, -0x1
	  lfs       f0, 0x9C(r3)
	  li        r4, 0x1
	  fadds     f1, f27, f1
	  fadds     f0, f30, f0
	  sth       r0, 0x4(r29)
	  fmuls     f1, f26, f1
	  lwz       r3, 0x0(r29)
	  fmuls     f0, f29, f0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  fmuls     f1, f25, f1
	  stb       r0, 0xC(r3)
	  fmuls     f0, f25, f0
	  lwz       r3, 0x0(r29)
	  fdivs     f1, f1, f28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  fdivs     f0, f0, f31
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x120(r1)
	  stfd      f0, 0x128(r1)
	  lwz       r4, 0x124(r1)
	  lwz       r5, 0x12C(r1)
	  blrl
	  lfs       f0, 0x428(r28)
	  mr        r3, r30
	  lwz       r5, 0x0(r29)
	  mr        r4, r31
	  fdivs     f0, f25, f0
	  addi      r29, r29, 0x8
	  stfs      f0, 0xC0(r5)
	  stfs      f0, 0xC4(r5)
	  stfs      f0, 0xC8(r5)
	  lha       r5, 0xFC(r28)
	  addi      r0, r5, 0x1
	  sth       r0, 0xFC(r28)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r31, r3

	.loc_0x458:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x480
	  li        r0, 0x1
	  b         .loc_0x4AC

	.loc_0x480:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x4A8
	  li        r0, 0x1
	  b         .loc_0x4AC

	.loc_0x4A8:
	  li        r0, 0

	.loc_0x4AC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x368
	  lmw       r27, 0x134(r1)
	  lwz       r0, 0x184(r1)
	  lfd       f31, 0x178(r1)
	  lfd       f30, 0x170(r1)
	  lfd       f29, 0x168(r1)
	  lfd       f28, 0x160(r1)
	  lfd       f27, 0x158(r1)
	  lfd       f26, 0x150(r1)
	  lfd       f25, 0x148(r1)
	  addi      r1, r1, 0x180
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80186238
 * Size:	0005D4
 */
void zen::ogRaderMgr::startSub()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x4
	  stwu      r1, -0x1B8(r1)
	  stfd      f31, 0x1B0(r1)
	  stfd      f30, 0x1A8(r1)
	  stfd      f29, 0x1A0(r1)
	  stfd      f28, 0x198(r1)
	  stfd      f27, 0x190(r1)
	  stfd      f26, 0x188(r1)
	  stfd      f25, 0x180(r1)
	  stfd      f24, 0x178(r1)
	  stw       r31, 0x174(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x170(r1)
	  stw       r29, 0x16C(r1)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0x50(r3)
	  lfs       f1, -0x4FFC(r2)
	  bl        -0x7370
	  li        r0, 0
	  sth       r0, 0x458(r31)
	  lha       r0, 0x458(r31)
	  lwz       r3, 0x420(r31)
	  stb       r0, 0xF0(r3)
	  lfs       f0, -0x500C(r2)
	  stfs      f0, 0x428(r31)
	  stfs      f0, 0x42C(r31)
	  lfs       f0, 0x428(r31)
	  lwz       r3, 0x420(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, 0x428(r31)
	  lfs       f0, -0x5030(r2)
	  lwz       r3, 0x424(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r4, 0x6C(r31)
	  addic.    r0, r4, 0xD0
	  lwz       r3, 0xE0(r4)
	  addi      r4, r4, 0xD0
	  beq-      .loc_0xB8
	  addi      r4, r4, 0xC

	.loc_0xB8:
	  bl        0x2D288
	  lwz       r3, 0x6C(r31)
	  lwz       r5, 0x424(r31)
	  addic.    r4, r3, 0xD0
	  beq-      .loc_0xD0
	  addi      r4, r4, 0xC

	.loc_0xD0:
	  addi      r3, r5, 0xD0
	  bl        0x2D1B0
	  lwz       r0, 0x70(r31)
	  addi      r29, r31, 0
	  li        r30, 0
	  stw       r0, 0x40(r31)
	  lwz       r0, 0x74(r31)
	  stw       r0, 0x44(r31)
	  lwz       r0, 0x78(r31)
	  stw       r0, 0x48(r31)

	.loc_0xF8:
	  lwz       r4, 0x40(r29)
	  addic.    r0, r4, 0xD0
	  lwz       r3, 0xE0(r4)
	  addi      r4, r4, 0xD0
	  beq-      .loc_0x110
	  addi      r4, r4, 0xC

	.loc_0x110:
	  bl        0x2D230
	  lwz       r3, 0x40(r29)
	  lwz       r5, 0x424(r31)
	  addic.    r4, r3, 0xD0
	  beq-      .loc_0x128
	  addi      r4, r4, 0xC

	.loc_0x128:
	  addi      r3, r5, 0xD0
	  bl        0x2D158
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x3
	  addi      r29, r29, 0x4
	  blt+      .loc_0xF8
	  lwz       r4, 0x7C(r31)
	  addic.    r0, r4, 0xD0
	  lwz       r3, 0xE0(r4)
	  addi      r4, r4, 0xD0
	  beq-      .loc_0x158
	  addi      r4, r4, 0xC

	.loc_0x158:
	  bl        0x2D1E8
	  lwz       r3, 0x7C(r31)
	  lwz       r5, 0x424(r31)
	  addic.    r4, r3, 0xD0
	  beq-      .loc_0x170
	  addi      r4, r4, 0xC

	.loc_0x170:
	  addi      r3, r5, 0xD0
	  bl        0x2D110
	  lwz       r3, 0x3120(r13)
	  bl        -0x6EFF0
	  mr        r30, r3
	  lwz       r3, 0x94(r3)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x430(r31)
	  stw       r0, 0x434(r31)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x438(r31)
	  lfs       f2, 0x430(r31)
	  lfs       f4, 0x438(r31)
	  lfs       f0, -0x5014(r2)
	  stfs      f0, 0x90(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f0, 0x88(r1)
	  stfs      f0, 0x8C(r1)
	  lfs       f1, -0x501C(r2)
	  lfs       f0, -0x5028(r2)
	  fadds     f2, f1, f2
	  lfs       f3, -0x5020(r2)
	  fadds     f0, f0, f4
	  lfs       f1, -0x502C(r2)
	  lfs       f4, -0x5030(r2)
	  fmuls     f3, f3, f2
	  lfs       f2, -0x5018(r2)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x5024(r2)
	  fmuls     f3, f4, f3
	  fmuls     f1, f4, f1
	  fdivs     f2, f3, f2
	  fdivs     f0, f1, f0
	  stfs      f2, 0x88(r1)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0x108(r1)
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0x10C(r1)
	  lfs       f0, 0x90(r1)
	  stfs      f0, 0x110(r1)
	  lwz       r3, 0x108(r1)
	  lwz       r0, 0x10C(r1)
	  stw       r3, 0x43C(r31)
	  stw       r0, 0x440(r31)
	  lwz       r0, 0x110(r1)
	  stw       r0, 0x444(r31)
	  lfs       f0, 0x43C(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x160(r1)
	  lwz       r0, 0x164(r1)
	  stw       r0, 0x448(r31)
	  lfs       f0, 0x444(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x158(r1)
	  lwz       r0, 0x15C(r1)
	  stw       r0, 0x44C(r31)
	  lwz       r3, 0x6C(r31)
	  lwz       r4, 0x448(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r5, 0x44C(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5030(r2)
	  li        r4, 0x2
	  lfs       f0, 0x428(r31)
	  lwz       r3, 0x6C(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, -0x5000(r2)
	  lfs       f0, 0x8C(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x450(r31)
	  lwz       r3, 0x6C(r31)
	  lfs       f1, 0x450(r31)
	  bl        .loc_0x5D4
	  lfs       f3, 0x444(r31)
	  lfs       f1, 0x38(r31)
	  lfs       f2, 0x43C(r31)
	  lfs       f0, 0x34(r31)
	  fadds     f3, f3, f1
	  lfs       f1, 0xC(r31)
	  fadds     f2, f2, f0
	  lfs       f0, 0x10(r31)
	  fneg      f4, f3
	  lfs       f5, 0x428(r31)
	  fctiwz    f1, f1
	  fneg      f2, f2
	  lfs       f3, -0x5030(r2)
	  fmuls     f4, f5, f4
	  lwz       r3, 0x420(r31)
	  fctiwz    f0, f0
	  fmuls     f2, f5, f2
	  stfd      f1, 0x140(r1)
	  fdivs     f1, f4, f3
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x138(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x144(r1)
	  fdivs     f0, f2, f3
	  lwz       r0, 0x13C(r1)
	  mtlr      r12
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x150(r1)
	  stfd      f0, 0x148(r1)
	  lwz       r29, 0x154(r1)
	  lwz       r30, 0x14C(r1)
	  add       r29, r29, r0
	  add       r30, r30, r4
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  blrl
	  lwz       r3, 0x424(r31)
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0
	  lfs       f28, -0x5014(r2)
	  rlwinm    r0,r30,2,0,29
	  lfs       f29, -0x5030(r2)
	  lfs       f30, -0x5020(r2)
	  add       r29, r31, r0
	  lfs       f31, -0x501C(r2)
	  lfs       f24, -0x5018(r2)
	  lfs       f25, -0x502C(r2)
	  lfs       f26, -0x5028(r2)
	  lfs       f27, -0x5024(r2)

	.loc_0x388:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r30
	  bl        -0x93C10
	  cmplwi    r3, 0
	  beq-      .loc_0x474
	  addi      r5, r3, 0x94
	  lfs       f0, 0x94(r3)
	  addi      r3, r1, 0xF4
	  addi      r4, r1, 0xD0
	  stfs      f0, 0xD0(r1)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0xD4(r1)
	  lfs       f0, 0x8(r5)
	  stfs      f0, 0xD8(r1)
	  bl        -0x1134B4
	  stfs      f28, 0x68(r1)
	  addi      r3, r1, 0xE8
	  addi      r4, r1, 0x60
	  stfs      f28, 0x64(r1)
	  stfs      f28, 0x60(r1)
	  stfs      f28, 0x64(r1)
	  lfs       f1, 0xF4(r1)
	  lfs       f0, 0xFC(r1)
	  fadds     f1, f31, f1
	  fadds     f0, f26, f0
	  fmuls     f1, f30, f1
	  fmuls     f0, f25, f0
	  fmuls     f1, f29, f1
	  fmuls     f0, f29, f0
	  fdivs     f1, f1, f24
	  fdivs     f0, f0, f27
	  stfs      f1, 0x60(r1)
	  stfs      f0, 0x68(r1)
	  bl        -0x113500
	  lfs       f0, 0xE8(r1)
	  lfs       f2, 0xF0(r1)
	  lwz       r3, 0x40(r29)
	  fctiwz    f1, f0
	  fctiwz    f0, f2
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x138(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x140(r1)
	  mtlr      r12
	  lwz       r4, 0x13C(r1)
	  lwz       r5, 0x144(r1)
	  blrl
	  lfs       f0, 0x428(r31)
	  li        r4, 0x1
	  lwz       r3, 0x40(r29)
	  fdivs     f0, f29, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x40(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x488

	.loc_0x474:
	  lwz       r3, 0x40(r29)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x488:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x3
	  addi      r29, r29, 0x4
	  blt+      .loc_0x388
	  lwz       r3, 0x30AC(r13)
	  bl        -0x93A9C
	  addi      r5, r3, 0x94
	  lfs       f0, 0x94(r3)
	  addi      r3, r1, 0xC4
	  addi      r4, r1, 0xA0
	  stfs      f0, 0xA0(r1)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0xA4(r1)
	  lfs       f0, 0x8(r5)
	  stfs      f0, 0xA8(r1)
	  bl        -0x1135B8
	  lfs       f0, -0x5014(r2)
	  addi      r3, r1, 0xB8
	  addi      r4, r1, 0x48
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  stfs      f0, 0x4C(r1)
	  lfs       f3, -0x501C(r2)
	  lfs       f2, 0xC4(r1)
	  lfs       f1, -0x5028(r2)
	  lfs       f0, 0xCC(r1)
	  fadds     f2, f3, f2
	  lfs       f3, -0x5020(r2)
	  fadds     f0, f1, f0
	  lfs       f1, -0x502C(r2)
	  fmuls     f2, f3, f2
	  lfs       f4, -0x5030(r2)
	  fmuls     f1, f1, f0
	  fmuls     f3, f4, f2
	  lfs       f2, -0x5018(r2)
	  lfs       f0, -0x5024(r2)
	  fmuls     f1, f4, f1
	  fdivs     f2, f3, f2
	  fdivs     f0, f1, f0
	  stfs      f2, 0x48(r1)
	  stfs      f0, 0x50(r1)
	  bl        -0x113624
	  lfs       f0, 0xB8(r1)
	  lfs       f2, 0xC0(r1)
	  lwz       r3, 0x7C(r31)
	  fctiwz    f1, f0
	  fctiwz    f0, f2
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x138(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x140(r1)
	  mtlr      r12
	  lwz       r4, 0x13C(r1)
	  lwz       r5, 0x144(r1)
	  blrl
	  lfs       f1, -0x5030(r2)
	  mr        r3, r31
	  lfs       f0, 0x428(r31)
	  lwz       r4, 0x7C(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC0(r4)
	  stfs      f0, 0xC4(r4)
	  stfs      f0, 0xC8(r4)
	  bl        -0xA6C
	  lfs       f0, -0x5014(r2)
	  stfs      f0, 0x34(r31)
	  stfs      f0, 0x38(r31)
	  lwz       r0, 0x1BC(r1)
	  lfd       f31, 0x1B0(r1)
	  lfd       f30, 0x1A8(r1)
	  lfd       f29, 0x1A0(r1)
	  lfd       f28, 0x198(r1)
	  lfd       f27, 0x190(r1)
	  lfd       f26, 0x188(r1)
	  lfd       f25, 0x180(r1)
	  lfd       f24, 0x178(r1)
	  lwz       r31, 0x174(r1)
	  lwz       r30, 0x170(r1)
	  lwz       r29, 0x16C(r1)
	  addi      r1, r1, 0x1B8
	  mtlr      r0
	  blr

	.loc_0x5D4:
	*/
}

/*
 * --INFO--
 * Address:	8018680C
 * Size:	000048
 */
void P2DPane::rotate(P2DRotateAxis, f32)
{
	/*
	.loc_0x0:
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,5,25,26
	  stb       r0, 0xC(r3)
	  stfs      f1, 0xBC(r3)
	  lfs       f1, 0xBC(r3)
	  lfs       f0, -0x5014(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x30
	  lfs       f0, -0x5004(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0xBC(r3)
	  blr

	.loc_0x30:
	  lfs       f0, -0x5004(r2)
	  fcmpo     cr0, f1, f0
	  blelr-
	  fsubs     f0, f1, f0
	  stfs      f0, 0xBC(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void zen::ogRaderMgr::start()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80186854
 * Size:	000128
 */
void zen::ogRaderMgr::startMenu(P2DPane*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x114
	  lwz       r3, 0x2F6C(r13)
	  cmplwi    r3, 0
	  beq-      .loc_0x38
	  lbz       r0, 0x11(r3)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x114

	.loc_0x38:
	  li        r0, 0x1
	  stw       r0, 0x4(r31)
	  li        r6, 0
	  li        r0, 0xC8
	  stb       r6, 0x0(r31)
	  lis       r5, 0x4330
	  addi      r3, r31, 0
	  stb       r6, 0x1(r31)
	  stb       r6, 0x2(r31)
	  sth       r0, 0x45A(r31)
	  lha       r6, 0x18(r4)
	  lha       r0, 0x1C(r4)
	  lha       r7, 0x1A(r4)
	  sub       r8, r0, r6
	  lha       r4, 0x1E(r4)
	  srawi     r0, r8, 0x1
	  lfd       f2, -0x4FF8(r2)
	  addze     r0, r0
	  sub       r9, r4, r7
	  add       r4, r6, r0
	  srawi     r0, r9, 0x1
	  xoris     r4, r4, 0x8000
	  addze     r0, r0
	  stw       r4, 0x44(r1)
	  add       r0, r7, r0
	  xoris     r0, r0, 0x8000
	  stw       r5, 0x40(r1)
	  stw       r0, 0x3C(r1)
	  lfd       f0, 0x40(r1)
	  stw       r5, 0x38(r1)
	  fsubs     f1, f0, f2
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f2
	  stfs      f1, 0xC(r31)
	  stfs      f0, 0x10(r31)
	  stw       r8, 0x1C(r31)
	  stw       r9, 0x20(r31)
	  stw       r6, 0x14(r31)
	  stw       r7, 0x18(r31)
	  bl        -0x6F0
	  lfs       f0, -0x500C(r2)
	  stfs      f0, 0x428(r31)
	  stfs      f0, 0x42C(r31)
	  lfs       f0, 0x428(r31)
	  lwz       r3, 0x420(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, 0x428(r31)
	  lfs       f0, -0x5030(r2)
	  lwz       r3, 0x424(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)

	.loc_0x114:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018697C
 * Size:	000024
 */
void zen::ogRaderMgr::MapOn()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x2F6C(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x18
	  lbz       r0, 0x11(r4)
	  rlwinm.   r0,r0,0,31,31
	  beqlr-

	.loc_0x18:
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void zen::ogRaderMgr::MapOff()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801869A0
 * Size:	000168
 */
void zen::ogRaderMgr::updateGame(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x28(r4)
	  rlwinm.   r0,r0,0,21,21
	  beq-      .loc_0xA0
	  lwz       r0, 0x8(r31)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x74
	  bge-      .loc_0x40
	  cmpwi     r0, 0
	  beq-      .loc_0x4C
	  bge-      .loc_0x60
	  b         .loc_0x108

	.loc_0x40:
	  cmpwi     r0, 0x4
	  bge-      .loc_0x108
	  b         .loc_0x88

	.loc_0x4C:
	  lfs       f0, -0x500C(r2)
	  li        r0, 0x1
	  stfs      f0, 0x42C(r31)
	  stw       r0, 0x8(r31)
	  b         .loc_0x108

	.loc_0x60:
	  lfs       f0, -0x4FF0(r2)
	  li        r0, 0x2
	  stfs      f0, 0x42C(r31)
	  stw       r0, 0x8(r31)
	  b         .loc_0x108

	.loc_0x74:
	  lfs       f0, -0x4FEC(r2)
	  li        r0, 0x3
	  stfs      f0, 0x42C(r31)
	  stw       r0, 0x8(r31)
	  b         .loc_0x108

	.loc_0x88:
	  li        r0, 0x5
	  stw       r0, 0x8(r31)
	  lwz       r3, 0x50(r31)
	  lfs       f1, -0x4FE8(r2)
	  bl        -0x7AA0
	  b         .loc_0x108

	.loc_0xA0:
	  lwz       r4, 0x20(r4)
	  rlwinm.   r0,r4,0,23,23
	  beq-      .loc_0xD8
	  lha       r3, 0x45A(r31)
	  cmpwi     r3, 0
	  ble-      .loc_0xD8
	  subi      r0, r3, 0x1
	  sth       r0, 0x45A(r31)
	  lha       r0, 0x45A(r31)
	  sth       r0, 0x458(r31)
	  lha       r0, 0x458(r31)
	  lwz       r3, 0x420(r31)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x108

	.loc_0xD8:
	  rlwinm.   r0,r4,0,22,22
	  beq-      .loc_0x108
	  lha       r3, 0x45A(r31)
	  cmpwi     r3, 0xFF
	  bge-      .loc_0x108
	  addi      r0, r3, 0x1
	  sth       r0, 0x45A(r31)
	  lha       r0, 0x45A(r31)
	  sth       r0, 0x458(r31)
	  lha       r0, 0x458(r31)
	  lwz       r3, 0x420(r31)
	  stb       r0, 0xF0(r3)

	.loc_0x108:
	  lfs       f2, 0x428(r31)
	  lfs       f1, 0x42C(r31)
	  lfs       f0, -0x5008(r2)
	  fsubs     f1, f1, f2
	  fdivs     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x428(r31)
	  lfs       f0, 0x428(r31)
	  lwz       r3, 0x420(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, 0x428(r31)
	  lfs       f0, -0x5030(r2)
	  lwz       r3, 0x424(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80186B08
 * Size:	000100
 */
void zen::ogRaderMgr::AreaScroll(f32*, f32*, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lfs       f3, 0x0(r4)
	  lfs       f0, 0x0(r5)
	  fadds     f5, f3, f1
	  lfs       f1, 0x430(r3)
	  fadds     f6, f0, f2
	  lfs       f0, 0x438(r3)
	  lfs       f3, 0x24(r3)
	  fadds     f4, f5, f1
	  lfs       f1, 0x28(r3)
	  fadds     f2, f6, f0
	  lfs       f0, -0x5014(r2)
	  fsubs     f3, f4, f3
	  fsubs     f1, f2, f1
	  fmuls     f2, f3, f3
	  fmuls     f1, f1, f1
	  fadds     f4, f2, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xB4
	  fsqrte    f1, f4
	  lfd       f3, -0x4FE0(r2)
	  lfd       f2, -0x4FD8(r2)
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

	.loc_0xB4:
	  lfs       f0, 0x2C(r31)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0xDC
	  stfs      f5, 0x0(r4)
	  li        r3, 0x132
	  stfs      f6, 0x0(r5)
	  bl        -0xE1860
	  li        r0, 0x1
	  stb       r0, 0x0(r31)
	  b         .loc_0xEC

	.loc_0xDC:
	  li        r3, 0x132
	  bl        -0xE1840
	  li        r0, 0
	  stb       r0, 0x0(r31)

	.loc_0xEC:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80186C08
 * Size:	000298
 */
void zen::ogRaderMgr::updateMenu(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stfd      f30, 0x28(r1)
	  stfd      f29, 0x20(r1)
	  stfd      f28, 0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  stw       r30, 0x10(r1)
	  addi      r30, r4, 0
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x270
	  lfs       f31, 0x428(r31)
	  mr        r3, r30
	  bl        -0x146104
	  fmr       f28, f1
	  lfs       f0, -0x4FD0(r2)
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0xA0
	  lfs       f1, -0x4FCC(r2)
	  lfs       f0, -0x5030(r2)
	  fmuls     f31, f31, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x80
	  fmr       f31, f0
	  li        r3, 0x130
	  bl        -0xE18D0
	  li        r0, 0
	  stb       r0, 0x1(r31)
	  b         .loc_0xF4

	.loc_0x80:
	  lbz       r0, 0x1(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xF4
	  li        r3, 0x130
	  bl        -0xE1924
	  li        r0, 0x1
	  stb       r0, 0x1(r31)
	  b         .loc_0xF4

	.loc_0xA0:
	  lfs       f0, -0x4FC8(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0xF4
	  lfs       f1, -0x4FC4(r2)
	  lfs       f0, -0x4FC0(r2)
	  fmuls     f31, f31, f1
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0xD8
	  fmr       f31, f0
	  li        r3, 0x131
	  bl        -0xE1928
	  li        r0, 0
	  stb       r0, 0x2(r31)
	  b         .loc_0xF4

	.loc_0xD8:
	  lbz       r0, 0x2(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xF4
	  li        r3, 0x131
	  bl        -0xE197C
	  li        r0, 0x1
	  stb       r0, 0x2(r31)

	.loc_0xF4:
	  lfs       f1, 0x454(r31)
	  bl        0x94E54
	  fmr       f29, f1
	  lfs       f1, 0x454(r31)
	  bl        0x94FDC
	  lwz       r3, 0x20(r30)
	  fmr       f30, f1
	  rlwinm.   r0,r3,0,12,12
	  beq-      .loc_0x138
	  lfs       f0, -0x4FBC(r2)
	  addi      r3, r31, 0
	  addi      r4, r31, 0x34
	  fmuls     f1, f0, f30
	  addi      r5, r31, 0x38
	  fmuls     f2, f0, f29
	  bl        -0x230
	  b         .loc_0x15C

	.loc_0x138:
	  rlwinm.   r0,r3,0,10,10
	  beq-      .loc_0x15C
	  lfs       f0, -0x4FB8(r2)
	  addi      r3, r31, 0
	  addi      r4, r31, 0x34
	  fmuls     f1, f0, f30
	  addi      r5, r31, 0x38
	  fmuls     f2, f0, f29
	  bl        -0x258

	.loc_0x15C:
	  lwz       r3, 0x20(r30)
	  rlwinm.   r0,r3,0,9,9
	  beq-      .loc_0x18C
	  lfs       f1, -0x4FBC(r2)
	  mr        r3, r31
	  lfs       f0, -0x4FB8(r2)
	  addi      r4, r31, 0x34
	  fmuls     f1, f1, f29
	  fmuls     f2, f0, f30
	  addi      r5, r31, 0x38
	  bl        -0x284
	  b         .loc_0x1B4

	.loc_0x18C:
	  rlwinm.   r0,r3,0,11,11
	  beq-      .loc_0x1B4
	  lfs       f1, -0x4FB8(r2)
	  mr        r3, r31
	  lfs       f0, -0x4FBC(r2)
	  addi      r4, r31, 0x34
	  fmuls     f1, f1, f29
	  fmuls     f2, f0, f30
	  addi      r5, r31, 0x38
	  bl        -0x2B0

	.loc_0x1B4:
	  lbz       r0, 0x0(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1DC
	  lwz       r0, 0x20(r30)
	  rlwinm.   r0,r0,0,9,12
	  bne-      .loc_0x1DC
	  li        r3, 0x132
	  bl        -0xE1A30
	  li        r0, 0
	  stb       r0, 0x0(r31)

	.loc_0x1DC:
	  lbz       r0, 0x1(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x204
	  lfs       f0, -0x4FE8(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x204
	  li        r3, 0x130
	  bl        -0xE1A58
	  li        r0, 0
	  stb       r0, 0x1(r31)

	.loc_0x204:
	  lbz       r0, 0x2(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x22C
	  lfs       f0, -0x4FB4(r2)
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0x22C
	  li        r3, 0x131
	  bl        -0xE1A80
	  li        r0, 0
	  stb       r0, 0x2(r31)

	.loc_0x22C:
	  lfs       f0, 0x428(r31)
	  fcmpu     cr0, f31, f0
	  beq-      .loc_0x270
	  stfs      f31, 0x428(r31)
	  stfs      f31, 0x42C(r31)
	  lfs       f0, 0x428(r31)
	  lwz       r3, 0x420(r31)
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, 0x428(r31)
	  lfs       f0, -0x5030(r2)
	  lwz       r3, 0x424(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)

	.loc_0x270:
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lfd       f30, 0x28(r1)
	  lfd       f29, 0x20(r1)
	  lfd       f28, 0x18(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80186EA0
 * Size:	000748
 */
zen::ogRaderMgr::RaderStatus zen::ogRaderMgr::update(Controller*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F0(r1)
	  stfd      f31, 0x1E8(r1)
	  stfd      f30, 0x1E0(r1)
	  stfd      f29, 0x1D8(r1)
	  stfd      f28, 0x1D0(r1)
	  stfd      f27, 0x1C8(r1)
	  stfd      f26, 0x1C0(r1)
	  stfd      f25, 0x1B8(r1)
	  stfd      f24, 0x1B0(r1)
	  stw       r31, 0x1AC(r1)
	  mr        r31, r3
	  stw       r30, 0x1A8(r1)
	  stw       r29, 0x1A4(r1)
	  addi      r29, r4, 0
	  lwz       r3, 0x8(r3)
	  cmpwi     r3, -0x1
	  bne-      .loc_0x50
	  b         .loc_0x70C

	.loc_0x50:
	  cmpwi     r3, 0x7
	  bne-      .loc_0x68
	  li        r0, -0x1
	  stw       r0, 0x8(r31)
	  lwz       r3, 0x8(r31)
	  b         .loc_0x70C

	.loc_0x68:
	  cmpwi     r3, 0x5
	  bne-      .loc_0xB8
	  lha       r3, 0x458(r31)
	  cmpwi     r3, 0
	  ble-      .loc_0xA8
	  subi      r0, r3, 0xA
	  sth       r0, 0x458(r31)
	  lha       r0, 0x458(r31)
	  cmpwi     r0, 0
	  bge-      .loc_0x98
	  li        r0, 0
	  sth       r0, 0x458(r31)

	.loc_0x98:
	  lha       r0, 0x458(r31)
	  lwz       r3, 0x420(r31)
	  stb       r0, 0xF0(r3)
	  b         .loc_0xB0

	.loc_0xA8:
	  li        r0, 0x7
	  stw       r0, 0x8(r31)

	.loc_0xB0:
	  lwz       r3, 0x8(r31)
	  b         .loc_0x70C

	.loc_0xB8:
	  cmpwi     r3, 0x4
	  bne-      .loc_0x10C
	  lha       r3, 0x458(r31)
	  lha       r0, 0x45A(r31)
	  cmpw      r3, r0
	  bge-      .loc_0xFC
	  addi      r0, r3, 0xA
	  sth       r0, 0x458(r31)
	  lha       r0, 0x458(r31)
	  lha       r3, 0x45A(r31)
	  cmpw      r0, r3
	  ble-      .loc_0xEC
	  sth       r3, 0x458(r31)

	.loc_0xEC:
	  lha       r0, 0x458(r31)
	  lwz       r3, 0x420(r31)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x104

	.loc_0xFC:
	  li        r0, 0
	  stw       r0, 0x8(r31)

	.loc_0x104:
	  lwz       r3, 0x8(r31)
	  b         .loc_0x70C

	.loc_0x10C:
	  lwz       r3, 0x50(r31)
	  bl        -0x7F94
	  lwz       r0, 0x8(r31)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x150
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0
	  bne-      .loc_0x13C
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x634
	  b         .loc_0x150

	.loc_0x13C:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x150
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        -0x3E4

	.loc_0x150:
	  lwz       r3, 0x3120(r13)
	  bl        -0x6FC30
	  mr        r30, r3
	  lwz       r3, 0x94(r3)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x430(r31)
	  stw       r0, 0x434(r31)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x438(r31)
	  lfs       f2, 0x430(r31)
	  lfs       f4, 0x438(r31)
	  lfs       f0, -0x5014(r2)
	  stfs      f0, 0x90(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f0, 0x88(r1)
	  stfs      f0, 0x8C(r1)
	  lfs       f1, -0x501C(r2)
	  lfs       f0, -0x5028(r2)
	  fadds     f2, f1, f2
	  lfs       f3, -0x5020(r2)
	  fadds     f0, f0, f4
	  lfs       f1, -0x502C(r2)
	  lfs       f4, -0x5030(r2)
	  fmuls     f3, f3, f2
	  lfs       f2, -0x5018(r2)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x5024(r2)
	  fmuls     f3, f4, f3
	  fmuls     f1, f4, f1
	  fdivs     f2, f3, f2
	  fdivs     f0, f1, f0
	  stfs      f2, 0x88(r1)
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x88(r1)
	  stfs      f0, 0x134(r1)
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0x138(r1)
	  lfs       f0, 0x90(r1)
	  stfs      f0, 0x13C(r1)
	  lwz       r3, 0x134(r1)
	  lwz       r0, 0x138(r1)
	  stw       r3, 0x43C(r31)
	  stw       r0, 0x440(r31)
	  lwz       r0, 0x13C(r1)
	  stw       r0, 0x444(r31)
	  lfs       f0, 0x43C(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x198(r1)
	  lwz       r0, 0x19C(r1)
	  stw       r0, 0x448(r31)
	  lfs       f0, 0x444(r31)
	  fctiwz    f0, f0
	  stfd      f0, 0x190(r1)
	  lwz       r0, 0x194(r1)
	  stw       r0, 0x44C(r31)
	  lwz       r3, 0x6C(r31)
	  lwz       r4, 0x448(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r5, 0x44C(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x5030(r2)
	  li        r4, 0x2
	  lfs       f0, 0x428(r31)
	  lwz       r3, 0x6C(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lfs       f1, -0x5000(r2)
	  lfs       f0, 0x8C(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x450(r31)
	  lwz       r3, 0x6C(r31)
	  lfs       f1, 0x450(r31)
	  bl        -0x914
	  lfs       f3, 0x444(r31)
	  lfs       f1, 0x38(r31)
	  lfs       f2, 0x43C(r31)
	  lfs       f0, 0x34(r31)
	  fadds     f3, f3, f1
	  lfs       f1, 0xC(r31)
	  fadds     f2, f2, f0
	  lfs       f0, 0x10(r31)
	  fneg      f4, f3
	  lfs       f5, 0x428(r31)
	  fctiwz    f1, f1
	  fneg      f2, f2
	  lfs       f3, -0x5030(r2)
	  fmuls     f4, f5, f4
	  lwz       r3, 0x420(r31)
	  fctiwz    f0, f0
	  fmuls     f2, f5, f2
	  stfd      f1, 0x178(r1)
	  fdivs     f1, f4, f3
	  lwz       r12, 0x0(r3)
	  stfd      f0, 0x170(r1)
	  lwz       r12, 0x14(r12)
	  lwz       r4, 0x17C(r1)
	  fdivs     f0, f2, f3
	  lwz       r0, 0x174(r1)
	  mtlr      r12
	  fctiwz    f1, f1
	  fctiwz    f0, f0
	  stfd      f1, 0x188(r1)
	  stfd      f0, 0x180(r1)
	  lwz       r29, 0x18C(r1)
	  lwz       r30, 0x184(r1)
	  add       r29, r29, r0
	  add       r30, r30, r4
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  blrl
	  lwz       r3, 0x424(r31)
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  li        r30, 0
	  lfs       f28, -0x5014(r2)
	  rlwinm    r0,r30,2,0,29
	  lfs       f29, -0x5030(r2)
	  lfs       f30, -0x5020(r2)
	  add       r29, r31, r0
	  lfs       f31, -0x501C(r2)
	  lfs       f24, -0x5018(r2)
	  lfs       f25, -0x502C(r2)
	  lfs       f26, -0x5028(r2)
	  lfs       f27, -0x5024(r2)

	.loc_0x360:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r30
	  bl        -0x94850
	  cmplwi    r3, 0
	  beq-      .loc_0x44C
	  addi      r5, r3, 0x94
	  lfs       f0, 0x94(r3)
	  addi      r3, r1, 0x120
	  addi      r4, r1, 0xFC
	  stfs      f0, 0xFC(r1)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0x100(r1)
	  lfs       f0, 0x8(r5)
	  stfs      f0, 0x104(r1)
	  bl        -0x1140F4
	  stfs      f28, 0x68(r1)
	  addi      r3, r1, 0x114
	  addi      r4, r1, 0x60
	  stfs      f28, 0x64(r1)
	  stfs      f28, 0x60(r1)
	  stfs      f28, 0x64(r1)
	  lfs       f1, 0x120(r1)
	  lfs       f0, 0x128(r1)
	  fadds     f1, f31, f1
	  fadds     f0, f26, f0
	  fmuls     f1, f30, f1
	  fmuls     f0, f25, f0
	  fmuls     f1, f29, f1
	  fmuls     f0, f29, f0
	  fdivs     f1, f1, f24
	  fdivs     f0, f0, f27
	  stfs      f1, 0x60(r1)
	  stfs      f0, 0x68(r1)
	  bl        -0x114140
	  lfs       f0, 0x114(r1)
	  lfs       f2, 0x11C(r1)
	  lwz       r3, 0x40(r29)
	  fctiwz    f1, f0
	  fctiwz    f0, f2
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x170(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x178(r1)
	  mtlr      r12
	  lwz       r4, 0x174(r1)
	  lwz       r5, 0x17C(r1)
	  blrl
	  lfs       f0, 0x428(r31)
	  li        r4, 0x1
	  lwz       r3, 0x40(r29)
	  fdivs     f0, f29, f0
	  stfs      f0, 0xC0(r3)
	  stfs      f0, 0xC4(r3)
	  stfs      f0, 0xC8(r3)
	  lwz       r3, 0x40(r29)
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0x460

	.loc_0x44C:
	  lwz       r3, 0x40(r29)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x460:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x3
	  addi      r29, r29, 0x4
	  blt+      .loc_0x360
	  lwz       r3, 0x30AC(r13)
	  bl        -0x946DC
	  addi      r5, r3, 0x94
	  lfs       f0, 0x94(r3)
	  addi      r3, r1, 0xF0
	  addi      r4, r1, 0xCC
	  stfs      f0, 0xCC(r1)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0xD0(r1)
	  lfs       f0, 0x8(r5)
	  stfs      f0, 0xD4(r1)
	  bl        -0x1141F8
	  lfs       f0, -0x5014(r2)
	  addi      r3, r1, 0xE4
	  addi      r4, r1, 0x48
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  stfs      f0, 0x4C(r1)
	  lfs       f3, -0x501C(r2)
	  lfs       f2, 0xF0(r1)
	  lfs       f1, -0x5028(r2)
	  lfs       f0, 0xF8(r1)
	  fadds     f2, f3, f2
	  lfs       f3, -0x5020(r2)
	  fadds     f0, f1, f0
	  lfs       f1, -0x502C(r2)
	  fmuls     f2, f3, f2
	  lfs       f4, -0x5030(r2)
	  fmuls     f1, f1, f0
	  fmuls     f3, f4, f2
	  lfs       f2, -0x5018(r2)
	  lfs       f0, -0x5024(r2)
	  fmuls     f1, f4, f1
	  fdivs     f2, f3, f2
	  fdivs     f0, f1, f0
	  stfs      f2, 0x48(r1)
	  stfs      f0, 0x50(r1)
	  bl        -0x114264
	  lfs       f0, 0xE4(r1)
	  lfs       f2, 0xEC(r1)
	  lwz       r3, 0x7C(r31)
	  fctiwz    f1, f0
	  fctiwz    f0, f2
	  lwz       r12, 0x0(r3)
	  stfd      f1, 0x170(r1)
	  lwz       r12, 0x14(r12)
	  stfd      f0, 0x178(r1)
	  mtlr      r12
	  lwz       r4, 0x174(r1)
	  lwz       r5, 0x17C(r1)
	  blrl
	  lfs       f1, -0x5030(r2)
	  mr        r3, r31
	  lfs       f0, 0x428(r31)
	  lwz       r4, 0x7C(r31)
	  fdivs     f0, f1, f0
	  stfs      f0, 0xC0(r4)
	  stfs      f0, 0xC4(r4)
	  stfs      f0, 0xC8(r4)
	  bl        -0x16AC
	  mr        r3, r31
	  bl        -0x18D4
	  addi      r3, r31, 0x100
	  li        r4, 0
	  b         .loc_0x6F4

	.loc_0x578:
	  lha       r0, 0x4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5EC
	  bge-      .loc_0x594
	  cmpwi     r0, 0
	  bge-      .loc_0x5A0
	  b         .loc_0x684

	.loc_0x594:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x684
	  b         .loc_0x638

	.loc_0x5A0:
	  lwz       r5, 0x5C(r31)
	  lbz       r0, 0x108(r5)
	  stb       r0, 0x168(r1)
	  lbz       r0, 0x109(r5)
	  stb       r0, 0x169(r1)
	  lbz       r0, 0x10A(r5)
	  stb       r0, 0x16A(r1)
	  lbz       r0, 0x10B(r5)
	  stb       r0, 0x16B(r1)
	  lbz       r0, 0x10C(r5)
	  stb       r0, 0x164(r1)
	  lbz       r0, 0x10D(r5)
	  stb       r0, 0x165(r1)
	  lbz       r0, 0x10E(r5)
	  stb       r0, 0x166(r1)
	  lbz       r0, 0x10F(r5)
	  stb       r0, 0x167(r1)
	  lbz       r6, 0xF0(r5)
	  b         .loc_0x6CC

	.loc_0x5EC:
	  lwz       r5, 0x60(r31)
	  lbz       r0, 0x108(r5)
	  stb       r0, 0x168(r1)
	  lbz       r0, 0x109(r5)
	  stb       r0, 0x169(r1)
	  lbz       r0, 0x10A(r5)
	  stb       r0, 0x16A(r1)
	  lbz       r0, 0x10B(r5)
	  stb       r0, 0x16B(r1)
	  lbz       r0, 0x10C(r5)
	  stb       r0, 0x164(r1)
	  lbz       r0, 0x10D(r5)
	  stb       r0, 0x165(r1)
	  lbz       r0, 0x10E(r5)
	  stb       r0, 0x166(r1)
	  lbz       r0, 0x10F(r5)
	  stb       r0, 0x167(r1)
	  lbz       r6, 0xF0(r5)
	  b         .loc_0x6CC

	.loc_0x638:
	  lwz       r5, 0x64(r31)
	  lbz       r0, 0x108(r5)
	  stb       r0, 0x168(r1)
	  lbz       r0, 0x109(r5)
	  stb       r0, 0x169(r1)
	  lbz       r0, 0x10A(r5)
	  stb       r0, 0x16A(r1)
	  lbz       r0, 0x10B(r5)
	  stb       r0, 0x16B(r1)
	  lbz       r0, 0x10C(r5)
	  stb       r0, 0x164(r1)
	  lbz       r0, 0x10D(r5)
	  stb       r0, 0x165(r1)
	  lbz       r0, 0x10E(r5)
	  stb       r0, 0x166(r1)
	  lbz       r0, 0x10F(r5)
	  stb       r0, 0x167(r1)
	  lbz       r6, 0xF0(r5)
	  b         .loc_0x6CC

	.loc_0x684:
	  lwz       r5, 0x68(r31)
	  lbz       r0, 0x108(r5)
	  stb       r0, 0x168(r1)
	  lbz       r0, 0x109(r5)
	  stb       r0, 0x169(r1)
	  lbz       r0, 0x10A(r5)
	  stb       r0, 0x16A(r1)
	  lbz       r0, 0x10B(r5)
	  stb       r0, 0x16B(r1)
	  lbz       r0, 0x10C(r5)
	  stb       r0, 0x164(r1)
	  lbz       r0, 0x10D(r5)
	  stb       r0, 0x165(r1)
	  lbz       r0, 0x10E(r5)
	  stb       r0, 0x166(r1)
	  lbz       r0, 0x10F(r5)
	  stb       r0, 0x167(r1)
	  lbz       r6, 0xF0(r5)

	.loc_0x6CC:
	  lwz       r5, 0x0(r3)
	  addi      r4, r4, 0x1
	  lwz       r0, 0x168(r1)
	  stw       r0, 0x108(r5)
	  lwz       r5, 0x0(r3)
	  lwz       r0, 0x164(r1)
	  stw       r0, 0x10C(r5)
	  lwz       r5, 0x0(r3)
	  addi      r3, r3, 0x8
	  stb       r6, 0xF0(r5)

	.loc_0x6F4:
	  lha       r0, 0xFC(r31)
	  cmpw      r4, r0
	  blt+      .loc_0x578
	  lwz       r3, 0x3C(r31)
	  bl        0x2B5AC
	  lwz       r3, 0x8(r31)

	.loc_0x70C:
	  lwz       r0, 0x1F4(r1)
	  lfd       f31, 0x1E8(r1)
	  lfd       f30, 0x1E0(r1)
	  lfd       f29, 0x1D8(r1)
	  lfd       f28, 0x1D0(r1)
	  lfd       f27, 0x1C8(r1)
	  lfd       f26, 0x1C0(r1)
	  lfd       f25, 0x1B8(r1)
	  lfd       f24, 0x1B0(r1)
	  lwz       r31, 0x1AC(r1)
	  lwz       r30, 0x1A8(r1)
	  lwz       r29, 0x1A4(r1)
	  addi      r1, r1, 0x1F0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void zen::ogRaderMgr::RotatePos(f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00045C
 */
void zen::ogRaderMgr::DrawCircle(u8, u8, u8, u8, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801875E8
 * Size:	00003C
 */
void zen::ogRaderMgr::end()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, -0x1
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x8(r3)
	  li        r3, 0x132
	  bl        -0xE2258
	  li        r3, 0x130
	  bl        -0xE2260
	  li        r3, 0x131
	  bl        -0xE2268
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80187624
 * Size:	00016C
 */
void zen::ogRaderMgr::draw(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x118(r1)
	  stw       r31, 0x114(r1)
	  mr        r31, r3
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x158
	  lwz       r3, 0x2E4(r4)
	  lfs       f1, 0x194(r3)
	  lfs       f0, 0x19C(r3)
	  fneg      f1, f1
	  fneg      f2, f0
	  bl        0x943A0
	  stfs      f1, 0x454(r31)
	  li        r4, 0x2
	  lfs       f0, 0xC(r31)
	  lfs       f2, 0x10(r31)
	  fctiwz    f0, f0
	  lfs       f1, 0x454(r31)
	  fctiwz    f2, f2
	  lwz       r3, 0x58(r31)
	  stfd      f0, 0x100(r1)
	  stfd      f2, 0x108(r1)
	  lwz       r0, 0x104(r1)
	  lwz       r5, 0x10C(r1)
	  extsh     r0, r0
	  sth       r0, 0xB8(r3)
	  extsh     r0, r5
	  sth       r0, 0xBA(r3)
	  lwz       r3, 0x58(r31)
	  bl        -0xE94
	  lwz       r0, 0x8(r31)
	  cmpwi     r0, 0x6
	  beq-      .loc_0x158
	  lfs       f2, -0x4FC0(r2)
	  addi      r4, r1, 0x14
	  lwz       r0, -0x4FB0(r2)
	  li        r3, 0
	  fmr       f4, f2
	  stw       r0, 0x14(r1)
	  lfs       f1, -0x5014(r2)
	  lfs       f3, -0x4FAC(r2)
	  bl        0x8C2C8
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x8C46C
	  lfs       f1, -0x4FA8(r2)
	  addi      r3, r1, 0x18
	  lfs       f2, -0x4FC0(r2)
	  li        r4, 0
	  lfs       f3, -0x4FA4(r2)
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x28A8C
	  addi      r3, r1, 0x18
	  bl        0x28B94
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x10C
	  lwz       r3, 0x14(r31)
	  lwz       r4, 0x18(r31)
	  lwz       r5, 0x1C(r31)
	  lwz       r6, 0x20(r31)
	  bl        0x8CFA4

	.loc_0x10C:
	  lwz       r3, 0x3C(r31)
	  addi      r6, r1, 0x18
	  li        r4, 0
	  li        r5, 0
	  bl        0x2B794
	  lwz       r0, 0x4(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x140
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x280
	  li        r6, 0x1E0
	  bl        0x8CF70

	.loc_0x140:
	  lis       r3, 0x802E
	  addi      r0, r3, 0x698
	  lis       r3, 0x802E
	  stw       r0, 0x18(r1)
	  addi      r0, r3, 0x5D4
	  stw       r0, 0x18(r1)

	.loc_0x158:
	  lwz       r0, 0x11C(r1)
	  lwz       r31, 0x114(r1)
	  addi      r1, r1, 0x118
	  mtlr      r0
	  blr
	*/
}
