#include "zen/ogSub.h"
#include "zen/Number.h"
#include "P2D/TextBox.h"
#include "gameflow.h"
#include "DebugLog.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("OgSubSection");

namespace zen {
static char workString[0x400];

static char wkstr[0x400]      = {};
static char numStrBuf[0x100]  = {};
static char formatStr[0x100]  = {};
static int SpecialNumber[100] = {};

/*
 * --INFO--
 * Address:	8017E850
 * Size:	00002C
 */
bool zen::ogCheckInsCard()
{
	return gameflow.mMemoryCard.isCardInserted();
}

/*
 * --INFO--
 * Address:	8017E87C
 * Size:	000068
 */
f32 zen::calcPuruPuruScale(f32 p1)
{
	u32 badCompiler[2];

	f32 val = (p1 / 0.5f);
	if (val > 1.0f) {
		val = 1.0f;
	}
	f32 cosVal = cosf(2.0f * TAU * val);
	return 1.0f + (0.08f * (1.0f - val) * (1.0f + cosVal));
}

/*
 * --INFO--
 * Address:	8017E8E4
 * Size:	000174
 */
void zen::setNumberTag(P2DScreen*, u32, int*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  addi      r29, r6, 0
	  stw       r28, 0x40(r1)
	  mr        r28, r5
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r3, 0
	  li        r3, 0x1C
	  bl        -0x137920
	  mr.       r30, r3
	  beq-      .loc_0x148
	  lis       r3, 0x802D
	  addi      r0, r3, 0x3004
	  stw       r0, 0x0(r30)
	  addi      r4, r31, 0
	  addi      r3, r30, 0x4
	  li        r5, 0x12
	  bl        0x31DB8
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FF4
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0x4
	  bl        0x40D94
	  stw       r28, 0x4(r30)
	  lis       r3, 0x802D
	  addi      r0, r3, 0x2FE4
	  stw       r29, 0x8(r30)
	  li        r4, 0
	  stw       r0, 0x0(r30)
	  stb       r4, 0x18(r30)
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x10(r30)
	  stw       r4, 0x14(r30)
	  lfs       f0, -0x50D8(r2)
	  stfs      f0, 0xC(r30)
	  lbz       r0, 0x18(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xEC
	  addi      r3, r30, 0x4
	  bl        .loc_0x174
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2388
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x118
	  stw       r0, 0xEC(r31)
	  b         .loc_0x118

	.loc_0xEC:
	  addi      r3, r30, 0x4
	  bl        .loc_0x174
	  lbz       r0, 0xF1(r31)
	  lis       r4, 0x803D
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r4, 0x2360
	  add       r3, r3, r5
	  cmplwi    r0, 0
	  lwz       r0, 0x0(r3)
	  ble-      .loc_0x118
	  stw       r0, 0xEC(r31)

	.loc_0x118:
	  lha       r5, 0x1A(r31)
	  lha       r4, 0x1E(r31)
	  lha       r3, 0x18(r31)
	  lha       r0, 0x1C(r31)
	  sub       r4, r4, r5
	  srawi     r4, r4, 0x1
	  sub       r0, r0, r3
	  srawi     r0, r0, 0x1
	  extsh     r0, r0
	  sth       r0, 0xB8(r31)
	  extsh     r0, r4
	  sth       r0, 0xBA(r31)

	.loc_0x148:
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        0x31C68
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  lwz       r28, 0x40(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr

	.loc_0x174:
	*/
}

/*
 * --INFO--
 * Address:	8017EA94
 * Size:	000064
 */
void zen::setTextColor(P2DTextBox*, P2DPicture*)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x30(r1)
	  li        r0, 0
	  lbz       r5, 0xF4(r3)
	  stb       r5, 0x2C(r1)
	  lbz       r5, 0xF5(r3)
	  stb       r5, 0x2D(r1)
	  lbz       r5, 0xF6(r3)
	  stb       r5, 0x2E(r1)
	  lbz       r5, 0xF7(r3)
	  stb       r5, 0x2F(r1)
	  lbz       r5, 0xF8(r3)
	  stb       r5, 0x28(r1)
	  lbz       r5, 0xF9(r3)
	  stb       r5, 0x29(r1)
	  lbz       r5, 0xFA(r3)
	  stb       r5, 0x2A(r1)
	  lbz       r3, 0xFB(r3)
	  stb       r3, 0x2B(r1)
	  stb       r0, 0x2B(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x108(r4)
	  lwz       r0, 0x28(r1)
	  stw       r0, 0x10C(r4)
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017EAF8
 * Size:	000088
 */
bool zen::getStringCVS(char*, char*, s16)
{
	/*
	.loc_0x0:
	  li        r6, 0x200
	  b         .loc_0x34

	.loc_0x8:
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x1C
	  li        r3, 0x1
	  blr

	.loc_0x1C:
	  cmplwi    r0, 0x2C
	  beq-      .loc_0x2C
	  cmplwi    r0, 0xA
	  bne-      .loc_0x30

	.loc_0x2C:
	  subi      r5, r5, 0x1

	.loc_0x30:
	  addi      r4, r4, 0x1

	.loc_0x34:
	  extsh.    r0, r5
	  bgt+      .loc_0x8

	.loc_0x3C:
	  lbz       r0, 0x0(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x78
	  cmplwi    r0, 0x2C
	  beq-      .loc_0x78
	  cmplwi    r0, 0xA
	  beq-      .loc_0x78
	  subi      r6, r6, 0x1
	  stb       r0, 0x0(r3)
	  extsh.    r0, r6
	  addi      r3, r3, 0x1
	  addi      r4, r4, 0x1
	  bge+      .loc_0x3C
	  li        r3, 0x1
	  blr

	.loc_0x78:
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017EB80
 * Size:	000328
 */
zen::PikaAlphaMgr::PikaAlphaMgr(P2DScreen*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x2A8(r1)
	  stfd      f31, 0x2A0(r1)
	  stfd      f30, 0x298(r1)
	  stmw      r19, 0x264(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  li        r30, 0
	  sth       r0, 0x4(r3)

	.loc_0x2C:
	  addi      r5, r30, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x54
	  addi      r4, r13, 0x958
	  bl        0x979DC
	  lwz       r12, 0x0(r27)
	  mr        r3, r27
	  lbz       r0, 0x55(r1)
	  li        r5, 0
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x54(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x56(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x57(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x2FC
	  lwz       r3, 0xE0(r31)
	  lwz       r4, 0xC(r3)
	  lhz       r0, 0x8(r4)
	  cmplwi    r0, 0x12
	  bne-      .loc_0x2FC
	  lwz       r28, 0x10C(r31)
	  li        r3, 0
	  lbz       r0, 0xC(r31)
	  rlwimi    r0,r3,7,24,24
	  addi      r29, r4, 0
	  stb       r0, 0xC(r31)
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  li        r5, 0
	  bl        -0x140
	  addi      r3, r1, 0x5C
	  bl        0x9A7EC
	  frsp      f31, f1
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  li        r5, 0x1
	  bl        -0x15C
	  addi      r3, r1, 0x5C
	  bl        0x9A7D0
	  frsp      f30, f1
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        0x31A38
	  lbz       r0, 0xF4(r31)
	  li        r3, 0x12C
	  stb       r0, 0x44(r1)
	  lbz       r0, 0xF5(r31)
	  stb       r0, 0x45(r1)
	  lbz       r0, 0xF6(r31)
	  stb       r0, 0x46(r1)
	  lbz       r0, 0xF7(r31)
	  stb       r0, 0x47(r1)
	  lbz       r24, 0x47(r1)
	  lbz       r0, 0xF8(r31)
	  stb       r0, 0x40(r1)
	  lbz       r0, 0xF9(r31)
	  stb       r0, 0x41(r1)
	  lbz       r0, 0xFA(r31)
	  stb       r0, 0x42(r1)
	  lbz       r0, 0xFB(r31)
	  stb       r0, 0x43(r1)
	  lbz       r31, 0x43(r1)
	  bl        -0x137CB8
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x164
	  fmr       f1, f31
	  addi      r4, r29, 0
	  fmr       f2, f30
	  addi      r5, r24, 0
	  addi      r6, r31, 0
	  bl        0x454

	.loc_0x164:
	  lha       r0, 0x4(r26)
	  li        r29, 0
	  li        r31, 0
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x8
	  stwx      r25, r26, r0

	.loc_0x17C:
	  extsh     r24, r31
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  addi      r5, r24, 0x2
	  bl        -0x214
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  addi      r3, r1, 0x5C
	  bl        0x9AE80
	  rlwinm    r25,r3,0,24,31
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  addi      r5, r24, 0x3
	  bl        -0x238
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  addi      r3, r1, 0x5C
	  bl        0x9AE5C
	  rlwinm    r23,r3,0,24,31
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  addi      r5, r24, 0x4
	  bl        -0x25C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  addi      r3, r1, 0x5C
	  bl        0x9AE38
	  rlwinm    r22,r3,0,24,31
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  addi      r5, r24, 0x5
	  bl        -0x280
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  addi      r3, r1, 0x5C
	  bl        0x9AE14
	  rlwinm    r21,r3,0,24,31
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  addi      r5, r24, 0x6
	  bl        -0x2A4
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  addi      r3, r1, 0x5C
	  bl        0x9ADF0
	  rlwinm    r20,r3,0,24,31
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  addi      r5, r24, 0x7
	  bl        -0x2C8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  addi      r3, r1, 0x5C
	  bl        0x9ADCC
	  rlwinm    r19,r3,0,24,31
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  addi      r5, r24, 0x8
	  bl        -0x2EC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x2F0
	  addi      r3, r1, 0x5C
	  bl        0x9A638
	  stb       r25, 0x4C(r1)
	  rlwinm    r4,r29,0,16,31
	  li        r0, 0xFF
	  frsp      f0, f1
	  stb       r21, 0x48(r1)
	  cmplwi    r4, 0x14
	  stb       r23, 0x4D(r1)
	  stb       r20, 0x49(r1)
	  stb       r22, 0x4E(r1)
	  stb       r19, 0x4A(r1)
	  stb       r0, 0x4F(r1)
	  stb       r0, 0x4B(r1)
	  lha       r0, 0x4(r26)
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x8
	  lwzx      r5, r26, r0
	  bge-      .loc_0x2E0
	  rlwinm    r3,r4,2,0,29
	  lwz       r0, 0x4C(r1)
	  add       r6, r5, r3
	  stw       r0, 0x30(r6)
	  addi      r0, r4, 0x1
	  lwz       r3, 0x48(r1)
	  stw       r3, 0x80(r6)
	  stfs      f0, 0xD0(r6)
	  sth       r0, 0x128(r5)

	.loc_0x2E0:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x14
	  addi      r31, r31, 0x7
	  blt+      .loc_0x17C

	.loc_0x2F0:
	  lha       r3, 0x4(r26)
	  addi      r0, r3, 0x1
	  sth       r0, 0x4(r26)

	.loc_0x2FC:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x64
	  blt+      .loc_0x2C
	  mr        r3, r26
	  lmw       r19, 0x264(r1)
	  lwz       r0, 0x2AC(r1)
	  lfd       f31, 0x2A0(r1)
	  lfd       f30, 0x298(r1)
	  addi      r1, r1, 0x2A8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017EEA8
 * Size:	00006C
 */
void zen::PikaAlphaMgr::start()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  rlwinm    r0,r30,2,0,29
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  li        r3, 0
	  stw       r3, 0x0(r29)
	  add       r31, r29, r0
	  b         .loc_0x44

	.loc_0x34:
	  lwz       r3, 0x8(r31)
	  bl        0x79C
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x44:
	  lha       r0, 0x4(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x34
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
 * Address:	8017EF14
 * Size:	000084
 */
void zen::PikaAlphaMgr::startFadeIn(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  fmr       f31, f1
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  rlwinm    r0,r30,2,0,29
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  li        r3, 0x1
	  stw       r3, 0x0(r29)
	  add       r31, r29, r0
	  b         .loc_0x58

	.loc_0x3C:
	  fmr       f1, f31
	  lwz       r3, 0x8(r31)
	  lfs       f2, -0x50D8(r2)
	  lfs       f3, -0x50E4(r2)
	  bl        0x740
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x58:
	  lha       r0, 0x4(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x3C
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017EF98
 * Size:	000084
 */
void zen::PikaAlphaMgr::startFadeOut(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  fmr       f31, f1
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  rlwinm    r0,r30,2,0,29
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  li        r3, 0x2
	  stw       r3, 0x0(r29)
	  add       r31, r29, r0
	  b         .loc_0x58

	.loc_0x3C:
	  fmr       f1, f31
	  lwz       r3, 0x8(r31)
	  lfs       f2, -0x50D8(r2)
	  lfs       f3, -0x50E4(r2)
	  bl        0x71C
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x58:
	  lha       r0, 0x4(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x3C
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017F01C
 * Size:	000118
 */
void zen::PikaAlphaMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  stw       r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x4C
	  bge-      .loc_0x40
	  cmpwi     r0, -0x1
	  beq-      .loc_0xF8
	  bge-      .loc_0xCC
	  b         .loc_0xF8

	.loc_0x40:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xF8
	  b         .loc_0x8C

	.loc_0x4C:
	  li        r29, 0
	  rlwinm    r0,r29,2,0,29
	  add       r30, r28, r0
	  li        r31, 0
	  b         .loc_0x7C

	.loc_0x60:
	  lwz       r3, 0x8(r30)
	  bl        0x6C8
	  cmpwi     r3, 0x1
	  bne-      .loc_0x74
	  stw       r31, 0x0(r28)

	.loc_0x74:
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x1

	.loc_0x7C:
	  lha       r0, 0x4(r28)
	  cmpw      r29, r0
	  blt+      .loc_0x60
	  b         .loc_0xF8

	.loc_0x8C:
	  li        r29, 0
	  rlwinm    r0,r29,2,0,29
	  add       r30, r28, r0
	  li        r31, -0x1
	  b         .loc_0xBC

	.loc_0xA0:
	  lwz       r3, 0x8(r30)
	  bl        0x688
	  cmpwi     r3, 0
	  bne-      .loc_0xB4
	  stw       r31, 0x0(r28)

	.loc_0xB4:
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x1

	.loc_0xBC:
	  lha       r0, 0x4(r28)
	  cmpw      r29, r0
	  blt+      .loc_0xA0
	  b         .loc_0xF8

	.loc_0xCC:
	  li        r31, 0
	  rlwinm    r0,r31,2,0,29
	  add       r30, r28, r0
	  b         .loc_0xEC

	.loc_0xDC:
	  lwz       r3, 0x8(r30)
	  bl        0x64C
	  addi      r30, r30, 0x4
	  addi      r31, r31, 0x1

	.loc_0xEC:
	  lha       r0, 0x4(r28)
	  cmpw      r31, r0
	  blt+      .loc_0xDC

	.loc_0xF8:
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
 * Address:	8017F134
 * Size:	0000F0
 */
zen::setTenmetuAlpha::setTenmetuAlpha(P2DPicture*, f32, f32, u8, u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r7, 0x8003
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  fmr       f31, f2
	  stfd      f30, 0x40(r1)
	  fmr       f30, f1
	  stmw      r27, 0x2C(r1)
	  mr        r27, r3
	  subi      r31, r7, 0x3C8
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  addi      r28, r4, 0
	  addi      r4, r31, 0
	  addi      r3, r27, 0x30
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0x14
	  bl        0x958F0
	  addi      r4, r31, 0
	  addi      r3, r27, 0x80
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0x14
	  bl        0x958D8
	  li        r6, 0
	  stw       r6, 0x0(r27)
	  lis       r0, 0x4330
	  addi      r3, r27, 0
	  stw       r28, 0x4(r27)
	  stfs      f30, 0x8(r27)
	  stfs      f31, 0xC(r27)
	  stb       r29, 0x1C(r27)
	  stb       r30, 0x1D(r27)
	  lbz       r5, 0x1C(r27)
	  lbz       r4, 0x1D(r27)
	  lfd       f1, -0x50D0(r2)
	  sub       r4, r4, r5
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x24(r1)
	  stw       r0, 0x20(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x18(r27)
	  sth       r6, 0x128(r27)
	  sth       r6, 0x12A(r27)
	  stfs      f31, 0x120(r27)
	  stfs      f31, 0x124(r27)
	  lfs       f0, -0x50D8(r2)
	  stfs      f0, 0x10(r27)
	  lfs       f0, -0x50E4(r2)
	  stfs      f0, 0x14(r27)
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lmw       r27, 0x2C(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017F224
 * Size:	0000F0
 */
zen::setTenmetuAlpha::setTenmetuAlpha(P2DPicture*, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8003
	  stw       r0, 0x4(r1)
	  li        r6, 0x4
	  li        r7, 0x14
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  fmr       f31, f1
	  stw       r31, 0x2C(r1)
	  subi      r31, r5, 0x3C8
	  li        r5, 0
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  addi      r4, r31, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  addi      r3, r29, 0x30
	  bl        0x95808
	  addi      r4, r31, 0
	  addi      r3, r29, 0x80
	  li        r5, 0
	  li        r6, 0x4
	  li        r7, 0x14
	  bl        0x957F0
	  li        r6, 0
	  stw       r6, 0x0(r29)
	  li        r4, 0xFF
	  lis       r0, 0x4330
	  stw       r30, 0x4(r29)
	  mr        r3, r29
	  stfs      f31, 0x8(r29)
	  lfs       f2, -0x50D8(r2)
	  stfs      f2, 0xC(r29)
	  stb       r6, 0x1C(r29)
	  stb       r4, 0x1D(r29)
	  lbz       r5, 0x1C(r29)
	  lbz       r4, 0x1D(r29)
	  lfd       f1, -0x50D0(r2)
	  sub       r4, r4, r5
	  xoris     r4, r4, 0x8000
	  stw       r4, 0x1C(r1)
	  stw       r0, 0x18(r1)
	  lfd       f0, 0x18(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x18(r29)
	  sth       r6, 0x128(r29)
	  sth       r6, 0x12A(r29)
	  stfs      f2, 0x120(r29)
	  stfs      f2, 0x124(r29)
	  stfs      f2, 0x10(r29)
	  lfs       f0, -0x50E4(r2)
	  stfs      f0, 0x14(r29)
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017F314
 * Size:	000368
 */
void zen::setTenmetuAlpha::updateColor()
{
	/*
	.loc_0x0:
	  stwu      r1, -0xA0(r1)
	  lha       r7, 0x128(r3)
	  extsh.    r0, r7
	  ble-      .loc_0x360
	  lha       r5, 0x12A(r3)
	  addi      r4, r5, 0x1
	  divw      r0, r4, r7
	  rlwinm    r8,r5,2,0,29
	  addi      r6, r8, 0x30
	  add       r6, r3, r6
	  lbz       r5, 0x0(r6)
	  mullw     r0, r0, r7
	  stb       r5, 0x38(r1)
	  lbz       r5, 0x1(r6)
	  sub       r0, r4, r0
	  stb       r5, 0x39(r1)
	  rlwinm    r4,r0,2,0,29
	  addi      r5, r4, 0x30
	  lbz       r0, 0x2(r6)
	  add       r5, r3, r5
	  add       r4, r3, r8
	  stb       r0, 0x3A(r1)
	  lbz       r0, 0x3(r6)
	  stb       r0, 0x3B(r1)
	  lbz       r0, 0x0(r5)
	  stb       r0, 0x34(r1)
	  lbz       r0, 0x1(r5)
	  stb       r0, 0x35(r1)
	  lbz       r0, 0x2(r5)
	  stb       r0, 0x36(r1)
	  lbz       r0, 0x3(r5)
	  stb       r0, 0x37(r1)
	  lfs       f2, 0x120(r3)
	  lfs       f1, 0xD0(r4)
	  lfs       f0, -0x50E4(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x9C
	  fmr       f1, f0

	.loc_0x9C:
	  lbz       r4, 0x38(r1)
	  lis       r5, 0x4330
	  lbz       r0, 0x34(r1)
	  stw       r4, 0x9C(r1)
	  lfs       f0, -0x50E4(r2)
	  stw       r0, 0x94(r1)
	  lfd       f4, -0x50C8(r2)
	  fsubs     f5, f0, f1
	  stw       r5, 0x98(r1)
	  stw       r5, 0x90(r1)
	  lfd       f3, 0x98(r1)
	  lfd       f2, 0x90(r1)
	  fsubs     f3, f3, f4
	  fsubs     f2, f2, f4
	  fmuls     f3, f3, f5
	  fmuls     f2, f2, f1
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x88(r1)
	  lwz       r0, 0x8C(r1)
	  stb       r0, 0x30(r1)
	  lbz       r4, 0x39(r1)
	  lbz       r0, 0x35(r1)
	  stw       r4, 0x84(r1)
	  stw       r0, 0x7C(r1)
	  stw       r5, 0x80(r1)
	  stw       r5, 0x78(r1)
	  lfd       f3, 0x80(r1)
	  lfd       f2, 0x78(r1)
	  fsubs     f3, f3, f4
	  fsubs     f2, f2, f4
	  fmuls     f3, f3, f5
	  fmuls     f2, f2, f1
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stb       r0, 0x31(r1)
	  lbz       r4, 0x3A(r1)
	  lbz       r0, 0x36(r1)
	  stw       r4, 0x6C(r1)
	  stw       r0, 0x64(r1)
	  stw       r5, 0x68(r1)
	  stw       r5, 0x60(r1)
	  lfd       f3, 0x68(r1)
	  lfd       f2, 0x60(r1)
	  fsubs     f3, f3, f4
	  fsubs     f2, f2, f4
	  fmuls     f3, f3, f5
	  fmuls     f2, f2, f1
	  fadds     f2, f3, f2
	  fctiwz    f2, f2
	  stfd      f2, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stb       r0, 0x32(r1)
	  lbz       r4, 0x3B(r1)
	  lbz       r0, 0x37(r1)
	  stw       r4, 0x54(r1)
	  stw       r0, 0x4C(r1)
	  stw       r5, 0x50(r1)
	  stw       r5, 0x48(r1)
	  lfd       f3, 0x50(r1)
	  lfd       f2, 0x48(r1)
	  fsubs     f3, f3, f4
	  fsubs     f2, f2, f4
	  fmuls     f3, f3, f5
	  fmuls     f1, f2, f1
	  fadds     f1, f3, f1
	  fctiwz    f1, f1
	  stfd      f1, 0x40(r1)
	  lwz       r0, 0x44(r1)
	  stb       r0, 0x33(r1)
	  lwz       r4, 0x4(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x108(r4)
	  lha       r4, 0x12A(r3)
	  rlwinm    r0,r4,2,0,29
	  add       r6, r3, r0
	  lwz       r0, 0x80(r6)
	  addi      r5, r4, 0x1
	  stw       r0, 0x38(r1)
	  lha       r4, 0x128(r3)
	  divw      r0, r5, r4
	  mullw     r0, r0, r4
	  sub       r0, r5, r0
	  rlwinm    r0,r0,2,0,29
	  add       r4, r3, r0
	  lwz       r0, 0x80(r4)
	  stw       r0, 0x34(r1)
	  lfs       f2, 0x120(r3)
	  lfs       f1, 0xD0(r6)
	  fdivs     f3, f2, f1
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x218
	  fmr       f3, f0

	.loc_0x218:
	  lbz       r4, 0x38(r1)
	  lis       r6, 0x4330
	  lbz       r0, 0x34(r1)
	  li        r5, 0
	  stw       r4, 0x44(r1)
	  lfs       f0, -0x50E4(r2)
	  stw       r0, 0x4C(r1)
	  lfd       f2, -0x50C8(r2)
	  fsubs     f4, f0, f3
	  stw       r6, 0x40(r1)
	  stw       r6, 0x48(r1)
	  lfd       f1, 0x40(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fmuls     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x50(r1)
	  lwz       r0, 0x54(r1)
	  stb       r0, 0x30(r1)
	  lbz       r4, 0x39(r1)
	  lbz       r0, 0x35(r1)
	  stw       r4, 0x5C(r1)
	  stw       r0, 0x64(r1)
	  stw       r6, 0x58(r1)
	  stw       r6, 0x60(r1)
	  lfd       f1, 0x58(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fmuls     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stb       r0, 0x31(r1)
	  lbz       r4, 0x3A(r1)
	  lbz       r0, 0x36(r1)
	  stw       r4, 0x74(r1)
	  stw       r0, 0x7C(r1)
	  stw       r6, 0x70(r1)
	  stw       r6, 0x78(r1)
	  lfd       f1, 0x70(r1)
	  lfd       f0, 0x78(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fmuls     f1, f1, f4
	  fmuls     f0, f0, f3
	  fadds     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x80(r1)
	  lwz       r0, 0x84(r1)
	  stb       r0, 0x32(r1)
	  stb       r5, 0x33(r1)
	  lwz       r4, 0x4(r3)
	  lwz       r0, 0x30(r1)
	  stw       r0, 0x10C(r4)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x120(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x120(r3)
	  lha       r0, 0x12A(r3)
	  lfs       f1, 0x120(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r4, r3, r0
	  lfs       f0, 0xD0(r4)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x360
	  lfs       f0, -0x50D8(r2)
	  stfs      f0, 0x120(r3)
	  lha       r4, 0x12A(r3)
	  addi      r0, r4, 0x1
	  sth       r0, 0x12A(r3)
	  lha       r4, 0x12A(r3)
	  lha       r0, 0x128(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x360
	  sth       r5, 0x12A(r3)

	.loc_0x360:
	  addi      r1, r1, 0xA0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017F67C
 * Size:	000024
 */
void zen::setTenmetuAlpha::start()
{
	/*
	.loc_0x0:
	  li        r0, 0
	  sth       r0, 0x12A(r3)
	  li        r0, 0x1
	  lfs       f0, 0x124(r3)
	  stfs      f0, 0xC(r3)
	  lfs       f0, 0x124(r3)
	  stfs      f0, 0x120(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017F6A0
 * Size:	000060
 */
void zen::setTenmetuAlpha::startFadeIn(f32, f32, f32)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x1
	  beqlr-
	  lfs       f0, -0x50D8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x20
	  lfs       f1, -0x50C0(r2)

	.loc_0x20:
	  li        r0, 0
	  fsubs     f0, f3, f2
	  sth       r0, 0x12A(r3)
	  li        r0, 0x2
	  lfs       f4, 0x124(r3)
	  stfs      f4, 0xC(r3)
	  lfs       f4, 0x124(r3)
	  stfs      f4, 0x120(r3)
	  stfs      f1, 0x14(r3)
	  lfs       f1, -0x50D8(r2)
	  stfs      f1, 0x10(r3)
	  stfs      f2, 0x24(r3)
	  stfs      f3, 0x28(r3)
	  stfs      f0, 0x20(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017F700
 * Size:	000048
 */
void zen::setTenmetuAlpha::startFadeOut(f32, f32, f32)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  beqlr-
	  lfs       f0, -0x50D8(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x20
	  lfs       f1, -0x50C0(r2)

	.loc_0x20:
	  stfs      f1, 0x14(r3)
	  fsubs     f0, f3, f2
	  li        r0, 0x3
	  lfs       f1, -0x50D8(r2)
	  stfs      f1, 0x10(r3)
	  stfs      f2, 0x24(r3)
	  stfs      f3, 0x28(r3)
	  stfs      f0, 0x20(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void zen::setTenmetuAlpha::calcAlpha(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017F748
 * Size:	000358
 */
zen::setTenmetuAlpha::TenmetuMode zen::setTenmetuAlpha::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  cmpwi     r3, 0
	  bne-      .loc_0x28
	  b         .loc_0x340

	.loc_0x28:
	  cmpwi     r3, 0x2
	  beq-      .loc_0x4C
	  bge-      .loc_0x40
	  cmpwi     r3, 0x1
	  bge-      .loc_0x280
	  b         .loc_0x33C

	.loc_0x40:
	  cmpwi     r3, 0x4
	  bge-      .loc_0x33C
	  b         .loc_0x168

	.loc_0x4C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r31)
	  lfs       f2, 0x10(r31)
	  lfs       f1, 0x14(r31)
	  lfs       f0, -0x50D8(r2)
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  fmr       f3, f1
	  bge-      .loc_0x80
	  fmr       f3, f0

	.loc_0x80:
	  lfs       f0, -0x50E4(r2)
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x98
	  li        r0, 0x1
	  fmr       f3, f0
	  stw       r0, 0x0(r31)

	.loc_0x98:
	  lfs       f2, 0x20(r31)
	  lfs       f1, 0x8(r31)
	  lfs       f0, -0x50D8(r2)
	  fmuls     f2, f2, f3
	  lfs       f3, 0x24(r31)
	  fcmpo     cr0, f1, f0
	  fadds     f31, f3, f2
	  ble-      .loc_0x33C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0xC(r31)
	  lfs       f1, 0x8(r31)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0xE4
	  fsubs     f0, f0, f1
	  stfs      f0, 0xC(r31)

	.loc_0xE4:
	  mr        r3, r31
	  bl        -0x51C
	  lfs       f2, -0x50BC(r2)
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x8(r31)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x9C4A0
	  lfs       f0, -0x50E4(r2)
	  lis       r0, 0x4330
	  lfs       f2, 0x18(r31)
	  fadds     f3, f0, f1
	  lfs       f0, -0x50E8(r2)
	  lbz       r4, 0x1C(r31)
	  lfd       f1, -0x50C8(r2)
	  fmuls     f2, f2, f3
	  lwz       r3, 0x4(r31)
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x70(r1)
	  lwz       r5, 0x74(r1)
	  add       r4, r4, r5
	  rlwinm    r4,r4,0,24,31
	  stw       r4, 0x6C(r1)
	  stw       r0, 0x68(r1)
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f31
	  fctiwz    f0, f0
	  stfd      f0, 0x60(r1)
	  lwz       r0, 0x64(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x33C

	.loc_0x168:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r31)
	  lfs       f2, 0x10(r31)
	  lfs       f1, 0x14(r31)
	  lfs       f0, -0x50D8(r2)
	  fdivs     f3, f2, f1
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x198
	  fmr       f3, f0

	.loc_0x198:
	  lfs       f0, -0x50E4(r2)
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x1B0
	  li        r0, 0
	  fmr       f3, f0
	  stw       r0, 0x0(r31)

	.loc_0x1B0:
	  lfs       f2, 0x20(r31)
	  lfs       f1, 0x8(r31)
	  lfs       f0, -0x50D8(r2)
	  fmuls     f2, f2, f3
	  lfs       f3, 0x28(r31)
	  fcmpo     cr0, f1, f0
	  fsubs     f31, f3, f2
	  ble-      .loc_0x33C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0xC(r31)
	  lfs       f1, 0x8(r31)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x1FC
	  fsubs     f0, f0, f1
	  stfs      f0, 0xC(r31)

	.loc_0x1FC:
	  mr        r3, r31
	  bl        -0x634
	  lfs       f2, -0x50BC(r2)
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x8(r31)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x9C388
	  lfs       f0, -0x50E4(r2)
	  lis       r0, 0x4330
	  lfs       f2, 0x18(r31)
	  fadds     f3, f0, f1
	  lfs       f0, -0x50E8(r2)
	  lbz       r4, 0x1C(r31)
	  lfd       f1, -0x50C8(r2)
	  fmuls     f2, f2, f3
	  lwz       r3, 0x4(r31)
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x60(r1)
	  lwz       r5, 0x64(r1)
	  add       r4, r4, r5
	  rlwinm    r4,r4,0,24,31
	  stw       r4, 0x6C(r1)
	  stw       r0, 0x68(r1)
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f31
	  fctiwz    f0, f0
	  stfd      f0, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x33C

	.loc_0x280:
	  lfs       f1, 0x8(r31)
	  lfs       f0, -0x50D8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x33C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xC(r31)
	  lfs       f0, 0xC(r31)
	  lfs       f1, 0x8(r31)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x2BC
	  fsubs     f0, f0, f1
	  stfs      f0, 0xC(r31)

	.loc_0x2BC:
	  mr        r3, r31
	  bl        -0x6F4
	  lfs       f2, -0x50BC(r2)
	  lfs       f1, 0xC(r31)
	  lfs       f0, 0x8(r31)
	  fmuls     f1, f2, f1
	  fdivs     f1, f1, f0
	  bl        0x9C2C8
	  lfs       f4, -0x50E4(r2)
	  lis       r0, 0x4330
	  lfs       f2, 0x18(r31)
	  fadds     f3, f4, f1
	  lfs       f0, -0x50E8(r2)
	  lbz       r4, 0x1C(r31)
	  lfd       f1, -0x50C8(r2)
	  fmuls     f2, f2, f3
	  lwz       r3, 0x4(r31)
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x60(r1)
	  lwz       r5, 0x64(r1)
	  add       r4, r4, r5
	  rlwinm    r4,r4,0,24,31
	  stw       r4, 0x6C(r1)
	  stw       r0, 0x68(r1)
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f4
	  fctiwz    f0, f0
	  stfd      f0, 0x70(r1)
	  lwz       r0, 0x74(r1)
	  stb       r0, 0xF0(r3)

	.loc_0x33C:
	  lwz       r3, 0x0(r31)

	.loc_0x340:
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017FAA0
 * Size:	000080
 */
zen::ogFadeMgr::ogFadeMgr(P2DPane*, u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  rlwinm    r5,r5,0,24,31
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x0(r3)
	  lis       r0, 0x4330
	  stw       r4, 0x4(r3)
	  lfs       f0, -0x50E4(r2)
	  stw       r5, 0x24(r1)
	  stfs      f0, 0xC(r31)
	  lfs       f1, -0x50D8(r2)
	  stw       r0, 0x20(r1)
	  stfs      f1, 0x10(r31)
	  lfd       f0, 0x20(r1)
	  stfs      f1, 0x14(r31)
	  stfs      f1, 0x18(r31)
	  lfd       f1, -0x50C8(r2)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x1C(r31)
	  lwz       r4, 0x4(r31)
	  lhz       r0, 0x8(r4)
	  sth       r0, 0x8(r31)
	  bl        0x84
	  mr        r3, r31
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017FB20
 * Size:	000068
 */
void zen::ogFadeMgr::start(zen::ogFadeMgr::ogFadeStatusFlag, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x50D8(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x58
	  stw       r4, 0x0(r3)
	  stfs      f1, 0xC(r3)
	  stfs      f0, 0x10(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x4C
	  bge-      .loc_0x54
	  cmpwi     r0, 0x1
	  bge-      .loc_0x40
	  b         .loc_0x54

	.loc_0x40:
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x14(r3)
	  b         .loc_0x54

	.loc_0x4C:
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x14(r3)

	.loc_0x54:
	  bl        .loc_0x68

	.loc_0x58:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr

	.loc_0x68:
	*/
}

/*
 * --INFO--
 * Address:	8017FB88
 * Size:	000078
 */
void zen::ogFadeMgr::setAlpha()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  lhz       r0, 0x8(r3)
	  cmpwi     r0, 0x13
	  beq-      .loc_0x3C
	  bge-      .loc_0x5C
	  cmpwi     r0, 0x12
	  bge-      .loc_0x20
	  b         .loc_0x5C

	.loc_0x20:
	  lfs       f0, 0x14(r3)
	  lwz       r3, 0x4(r3)
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stb       r0, 0xF0(r3)
	  b         .loc_0x70

	.loc_0x3C:
	  lfs       f0, 0x14(r3)
	  lwz       r3, 0x4(r3)
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stb       r0, 0xF7(r3)
	  stb       r0, 0xFB(r3)
	  b         .loc_0x70

	.loc_0x5C:
	  lwz       r3, 0x4(r3)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x70:
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017FC00
 * Size:	000140
 */
zen::ogFadeMgr::ogFadeStatusFlag zen::ogFadeMgr::update()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x38(r1)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x18
	  mr        r3, r0
	  b         .loc_0x138

	.loc_0x18:
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x10(r3)
	  lfs       f0, 0x28C(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x10(r3)
	  lfs       f0, 0x10(r3)
	  lfs       f1, 0xC(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x40
	  stfs      f1, 0x10(r3)

	.loc_0x40:
	  lfs       f1, 0x10(r3)
	  lfs       f0, 0xC(r3)
	  lwz       r0, 0x0(r3)
	  fdivs     f3, f1, f0
	  cmpwi     r0, 0x2
	  beq-      .loc_0x8C
	  bge-      .loc_0xAC
	  cmpwi     r0, 0x1
	  bge-      .loc_0x68
	  b         .loc_0xAC

	.loc_0x68:
	  lfs       f1, -0x50E4(r2)
	  lfs       f0, 0x1C(r3)
	  fsubs     f1, f1, f3
	  lfs       f2, 0x18(r3)
	  fmuls     f0, f0, f3
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r3)
	  b         .loc_0xAC

	.loc_0x8C:
	  lfs       f1, -0x50E4(r2)
	  lfs       f0, 0x18(r3)
	  fsubs     f1, f1, f3
	  lfs       f2, 0x1C(r3)
	  fmuls     f0, f0, f3
	  fmuls     f1, f2, f1
	  fadds     f0, f1, f0
	  stfs      f0, 0x14(r3)

	.loc_0xAC:
	  lhz       r0, 0x8(r3)
	  cmpwi     r0, 0x13
	  beq-      .loc_0xE4
	  bge-      .loc_0x104
	  cmpwi     r0, 0x12
	  bge-      .loc_0xC8
	  b         .loc_0x104

	.loc_0xC8:
	  lfs       f0, 0x14(r3)
	  lwz       r4, 0x4(r3)
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stb       r0, 0xF0(r4)
	  b         .loc_0x118

	.loc_0xE4:
	  lfs       f0, 0x14(r3)
	  lwz       r4, 0x4(r3)
	  fctiwz    f0, f0
	  stfd      f0, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stb       r0, 0xF7(r4)
	  stb       r0, 0xFB(r4)
	  b         .loc_0x118

	.loc_0x104:
	  lwz       r4, 0x4(r3)
	  li        r5, 0
	  lbz       r0, 0xC(r4)
	  rlwimi    r0,r5,7,24,24
	  stb       r0, 0xC(r4)

	.loc_0x118:
	  lfs       f1, 0x10(r3)
	  lfs       f0, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x134
	  li        r0, 0
	  stw       r0, 0x0(r3)

	.loc_0x134:
	  lwz       r3, 0x0(r3)

	.loc_0x138:
	  addi      r1, r1, 0x38
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void zen::movePicturePos(P2DPicture*, P2DPicture*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017FD40
 * Size:	000024
 */
void P2DPane::move(int x, int y)
{
	mBounds.move(x, y);
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x18
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        0x339D4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017FD64
 * Size:	000178
 */
zen::ogTexAnimSubMgr::ogTexAnimSubMgr(P2DScreen*, P2DPicture*, P2DTextBox*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x250(r1)
	  stmw      r25, 0x234(r1)
	  addi      r25, r3, 0
	  li        r27, 0
	  rlwinm    r29,r27,1,0,30
	  mr        r26, r4
	  addi      r31, r25, 0
	  addi      r30, r29, 0x1
	  sth       r0, 0x14(r3)
	  stw       r5, 0x0(r3)
	  stw       r6, 0x4(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r28, 0x10C(r3)

	.loc_0x40:
	  addi      r4, r28, 0
	  addi      r3, r1, 0x2C
	  extsh     r5, r29
	  bl        -0x12B8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xFC
	  addi      r3, r1, 0x2C
	  addi      r4, r13, 0x960
	  bl        0x99400
	  cmpwi     r3, 0
	  beq-      .loc_0xFC
	  lwz       r12, 0x0(r26)
	  mr        r3, r26
	  lbz       r0, 0x2D(r1)
	  li        r5, 0x1
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x2C(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x2E(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x2F(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  stw       r3, 0x1A8(r31)
	  addi      r4, r28, 0
	  addi      r3, r1, 0x2C
	  extsh     r5, r30
	  bl        -0x1328
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xFC
	  addi      r3, r1, 0x2C
	  bl        0x995FC
	  frsp      f0, f1
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x64
	  addi      r29, r29, 0x2
	  stfs      f0, 0x18(r31)
	  addi      r31, r31, 0x4
	  lha       r3, 0x14(r25)
	  addi      r30, r30, 0x2
	  addi      r0, r3, 0x1
	  sth       r0, 0x14(r25)
	  blt+      .loc_0x40

	.loc_0xFC:
	  li        r0, 0
	  sth       r0, 0x16(r25)
	  lfs       f0, -0x50D8(r2)
	  stfs      f0, 0xC(r25)
	  lfs       f0, -0x50E4(r2)
	  stfs      f0, 0x10(r25)
	  lha       r0, 0x14(r25)
	  cmpwi     r0, 0
	  ble-      .loc_0x160
	  lha       r0, 0x16(r25)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r25, r0
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x8(r25)
	  lha       r0, 0x16(r25)
	  lwz       r5, 0x0(r25)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r25, r0
	  lha       r4, 0x18(r5)
	  lwz       r3, 0x1A8(r3)
	  lha       r5, 0x1A(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x160:
	  mr        r3, r25
	  lmw       r25, 0x234(r1)
	  lwz       r0, 0x254(r1)
	  addi      r1, r1, 0x250
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
void zen::ogTexAnimSubMgr::update()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017FEDC
 * Size:	0000F4
 */
zen::ogTexAnimMgr::ogTexAnimMgr(P2DScreen*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x58(r1)
	  stmw      r25, 0x3C(r1)
	  addi      r28, r3, 0
	  addi      r29, r4, 0
	  addi      r31, r28, 0
	  li        r30, 0
	  stw       r0, 0x0(r3)

	.loc_0x28:
	  addi      r5, r30, 0
	  crclr     6, 0x6
	  addi      r3, r1, 0x30
	  addi      r4, r13, 0x964
	  bl        0x96684
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  lbz       r0, 0x31(r1)
	  li        r5, 0
	  lwz       r12, 0x34(r12)
	  lbz       r4, 0x30(r1)
	  rlwinm    r0,r0,16,0,15
	  lbz       r6, 0x32(r1)
	  mtlr      r12
	  rlwimi    r0,r4,24,0,7
	  lbz       r7, 0x33(r1)
	  rlwimi    r0,r6,8,16,23
	  or        r4, r7, r0
	  blrl
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  lwz       r4, 0xE0(r3)
	  lwz       r4, 0xC(r4)
	  lhz       r0, 0x8(r4)
	  cmplwi    r0, 0x12
	  bne-      .loc_0xCC
	  addi      r26, r4, 0
	  addi      r25, r3, 0
	  li        r3, 0x338
	  bl        -0x138F74
	  addi      r27, r3, 0
	  mr.       r3, r27
	  beq-      .loc_0xBC
	  addi      r4, r29, 0
	  addi      r5, r26, 0
	  addi      r6, r25, 0
	  bl        -0x230

	.loc_0xBC:
	  stw       r27, 0x4(r31)
	  lwz       r3, 0x0(r28)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r28)

	.loc_0xCC:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x64
	  addi      r31, r31, 0x4
	  blt+      .loc_0x28
	  mr        r3, r28
	  lmw       r25, 0x3C(r1)
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8017FFD0
 * Size:	00014C
 */
void zen::ogTexAnimMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  li        r29, 0
	  stw       r28, 0x28(r1)
	  mr        r28, r3
	  addi      r31, r28, 0
	  lfs       f31, -0x50D8(r2)
	  b         .loc_0x11C

	.loc_0x34:
	  lwz       r30, 0x4(r31)
	  lha       r0, 0x14(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x114
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r30)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0xC(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC(r30)
	  lfs       f1, 0xC(r30)
	  lfs       f0, 0x8(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x114
	  lha       r0, 0x16(r30)
	  li        r4, 0
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x1A8
	  lwzx      r3, r30, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  lha       r3, 0x16(r30)
	  addi      r0, r3, 0x1
	  sth       r0, 0x16(r30)
	  lha       r3, 0x16(r30)
	  lha       r0, 0x14(r30)
	  cmpw      r3, r0
	  blt-      .loc_0xB0
	  sth       r4, 0x16(r30)

	.loc_0xB0:
	  stfs      f31, 0xC(r30)
	  lha       r0, 0x16(r30)
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x18
	  lfsx      f0, r30, r0
	  stfs      f0, 0x8(r30)
	  lha       r0, 0x16(r30)
	  lwz       r5, 0x0(r30)
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x1A8
	  lha       r4, 0x18(r5)
	  lwzx      r3, r30, r0
	  lha       r5, 0x1A(r5)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lha       r0, 0x16(r30)
	  li        r4, 0x1
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x1A8
	  lwzx      r3, r30, r0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)

	.loc_0x114:
	  addi      r31, r31, 0x4
	  addi      r29, r29, 0x1

	.loc_0x11C:
	  lwz       r0, 0x0(r28)
	  cmpw      r29, r0
	  blt+      .loc_0x34
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018011C
 * Size:	000030
 */
int zen::getSpecialNumber(int idx)
{
	if (idx < 0 || idx > 99) {
		return -1;
	}

	return SpecialNumber[idx];
}

/*
 * --INFO--
 * Address:	8018014C
 * Size:	00002C
 */
void zen::setSpecialNumber(int idx, int value)
{
	if (idx < 0 || idx > 99) {
		return;
	}

	SpecialNumber[idx] = value;
}

/*
 * --INFO--
 * Address:	80180178
 * Size:	000218
 */
void zen::cnvSpecialNumber(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r25, 0x14(r1)
	  addi      r30, r4, 0x2750
	  addi      r31, r3, 0
	  addi      r29, r31, 0
	  addi      r28, r30, 0x1C
	  addi      r3, r30, 0x51C
	  addi      r4, r13, 0x96C
	  bl        0x991B4

	.loc_0x30:
	  lbz       r3, 0x0(r29)
	  lbz       r27, 0x1(r29)
	  cmplwi    r3, 0
	  lbz       r26, 0x2(r29)
	  lbz       r25, 0x3(r29)
	  beq-      .loc_0x1F0
	  cmplwi    r3, 0x1B
	  bne-      .loc_0x1C0
	  addi      r3, r29, 0x1
	  addi      r4, r13, 0x970
	  li        r5, 0x2
	  bl        0x98FB0
	  cmpwi     r3, 0
	  bne-      .loc_0x70
	  addi      r29, r29, 0x3
	  b         .loc_0x30

	.loc_0x70:
	  cmplwi    r27, 0x5A
	  bne-      .loc_0xD0
	  cmplwi    r26, 0
	  beq-      .loc_0x1F0
	  cmplwi    r26, 0x30
	  blt-      .loc_0xC8
	  cmplwi    r26, 0x39
	  bgt-      .loc_0xC8
	  subi      r0, r26, 0x30
	  cmpwi     r0, 0x1
	  mr        r5, r0
	  addi      r29, r29, 0x3
	  ble-      .loc_0xB8
	  crclr     6, 0x6
	  addi      r3, r30, 0x51C
	  addi      r4, r13, 0x974
	  bl        0x96370
	  b         .loc_0x30

	.loc_0xB8:
	  addi      r3, r30, 0x51C
	  addi      r4, r13, 0x96C
	  bl        0x99120
	  b         .loc_0x30

	.loc_0xC8:
	  addi      r29, r29, 0x1
	  b         .loc_0x30

	.loc_0xD0:
	  cmplwi    r27, 0x64
	  bne-      .loc_0x1AC
	  cmplwi    r26, 0
	  beq-      .loc_0x1F0
	  cmplwi    r26, 0x30
	  blt-      .loc_0x1A4
	  cmplwi    r26, 0x39
	  bgt-      .loc_0x1A4
	  cmplwi    r25, 0x30
	  blt-      .loc_0x158
	  cmplwi    r25, 0x39
	  bgt-      .loc_0x158
	  subi      r0, r26, 0x30
	  crclr     6, 0x6
	  mulli     r3, r0, 0xA
	  add       r3, r25, r3
	  subi      r3, r3, 0x30
	  rlwinm    r0,r3,2,0,29
	  add       r3, r30, r0
	  lwz       r25, 0x61C(r3)
	  addi      r3, r28, 0
	  addi      r4, r30, 0x51C
	  addi      r5, r25, 0
	  addi      r29, r29, 0x4
	  bl        0x962F0
	  addi      r5, r25, 0
	  crclr     6, 0x6
	  addi      r3, r30, 0x41C
	  addi      r4, r30, 0x51C
	  bl        0x962DC
	  addi      r3, r30, 0x41C
	  bl        0x99148
	  add       r28, r28, r3
	  b         .loc_0x30

	.loc_0x158:
	  subi      r0, r26, 0x30
	  crclr     6, 0x6
	  rlwinm    r0,r0,2,0,29
	  add       r3, r30, r0
	  lwz       r25, 0x61C(r3)
	  addi      r3, r28, 0
	  addi      r4, r30, 0x51C
	  addi      r5, r25, 0
	  addi      r29, r29, 0x3
	  bl        0x962A4
	  addi      r5, r25, 0
	  crclr     6, 0x6
	  addi      r3, r30, 0x41C
	  addi      r4, r30, 0x51C
	  bl        0x96290
	  addi      r3, r30, 0x41C
	  bl        0x990FC
	  add       r28, r28, r3
	  b         .loc_0x30

	.loc_0x1A4:
	  addi      r29, r29, 0x2
	  b         .loc_0x30

	.loc_0x1AC:
	  lbz       r0, 0x0(r29)
	  addi      r29, r29, 0x1
	  stb       r0, 0x0(r28)
	  addi      r28, r28, 0x1
	  b         .loc_0x30

	.loc_0x1C0:
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0x1E0
	  stb       r3, 0x0(r28)
	  lbz       r0, 0x1(r29)
	  addi      r29, r29, 0x2
	  stb       r0, 0x1(r28)
	  addi      r28, r28, 0x2
	  b         .loc_0x30

	.loc_0x1E0:
	  stb       r3, 0x0(r28)
	  addi      r28, r28, 0x1
	  addi      r29, r29, 0x1
	  b         .loc_0x30

	.loc_0x1F0:
	  li        r0, 0
	  stb       r0, 0x0(r28)
	  addi      r3, r31, 0
	  addi      r4, r30, 0x1C
	  bl        0x98FE0
	  lmw       r25, 0x14(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80180390
 * Size:	000090
 */
zen::TypingTextMgr::TypingTextMgr(P2DTextBox* textBox)
{
	mTextBox = textBox;
	mTextPtr = textBox->getString();
	sprintf(mTextBuf, "");
	_00  = 0;
	_410 = 0.0f;
	_414 = 0;

	textBox->hide();
	mCtrlTagMgr = new ogMsgCtrlTagMgr();
}

/*
 * --INFO--
 * Address:	80180420
 * Size:	000074
 */
void zen::TypingTextMgr::start()
{
	u32 badCompiler;

	_00  = 1;
	_410 = 0.0f;
	_414 = 0;
	sprintf(mTextBuf, "");
	mTextBox->show();
	mTextBox->setString(mTextBuf);
}

/*
 * --INFO--
 * Address:	80180494
 * Size:	000160
 */
zen::ogMsgCtrlTagMgr::ogMsgCtrlTagMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  li        r3, 0xF8
	  stw       r30, 0x20(r1)
	  stw       r29, 0x1C(r1)
	  stw       r28, 0x18(r1)
	  bl        -0x1394B4
	  addi      r29, r3, 0
	  mr.       r0, r29
	  beq-      .loc_0x8C
	  addi      r28, r29, 0
	  addi      r3, r1, 0xC
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x280
	  li        r7, 0x1E0
	  bl        0x33148
	  lis       r4, 0x726F
	  addi      r7, r4, 0x6F74
	  addi      r8, r1, 0xC
	  addi      r3, r28, 0
	  li        r4, 0
	  li        r5, 0x8
	  li        r6, 0x1
	  bl        0x304CC
	  lis       r3, 0x802E
	  addi      r0, r3, 0x7E0
	  stw       r0, 0x0(r29)
	  li        r0, 0
	  stb       r0, 0xEC(r29)
	  stw       r0, 0xF0(r29)
	  stw       r0, 0xF4(r29)

	.loc_0x8C:
	  lis       r3, 0x802D
	  addi      r28, r29, 0
	  addi      r4, r3, 0x2EFC
	  addi      r3, r28, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  bl        0x326C4
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  lis       r4, 0x6D61
	  addi      r4, r4, 0x7275
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  addi      r30, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  lis       r4, 0x74
	  addi      r4, r4, 0x656E
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  addi      r29, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x0(r28)
	  lis       r4, 0x68
	  addi      r4, r4, 0x616E
	  lwz       r12, 0x34(r12)
	  li        r5, 0x1
	  mtlr      r12
	  blrl
	  lwz       r4, 0x10C(r30)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  bl        0x98DA4
	  lwz       r4, 0x10C(r29)
	  addi      r3, r31, 0x8
	  bl        0x98D98
	  lwz       r4, 0x10C(r30)
	  addi      r3, r31, 0x10
	  bl        0x98D8C
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
 * Address:	801805F4
 * Size:	0003A8
 */
void zen::ogMsgCtrlTagMgr::CheckCtrlTag(char*, s16*, f32*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r25, 0x24(r1)
	  addi      r26, r4, 0
	  mr        r27, r5
	  addi      r28, r6, 0
	  addi      r25, r3, 0
	  lha       r31, 0x0(r5)
	  lfs       f0, -0x50D8(r2)
	  add       r4, r26, r31
	  lbz       r0, 0x0(r4)
	  addi      r29, r4, 0
	  mr.       r30, r0
	  stfs      f0, 0x0(r6)
	  bne-      .loc_0x48
	  li        r3, 0x1
	  b         .loc_0x394

	.loc_0x48:
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  li        r5, 0x2
	  bl        0x98B3C
	  cmpwi     r3, 0
	  bne-      .loc_0x70
	  lfs       f0, -0x50B8(r2)
	  addi      r29, r31, 0x2
	  stfs      f0, 0x0(r28)
	  b         .loc_0x38C

	.loc_0x70:
	  addi      r3, r29, 0
	  addi      r4, r25, 0x8
	  li        r5, 0x2
	  bl        0x98B14
	  cmpwi     r3, 0
	  bne-      .loc_0x98
	  lfs       f0, -0x50B8(r2)
	  addi      r29, r31, 0x2
	  stfs      f0, 0x0(r28)
	  b         .loc_0x38C

	.loc_0x98:
	  cmplwi    r30, 0x1B
	  bne-      .loc_0x33C
	  addi      r29, r31, 0x1
	  extsh     r0, r29
	  add       r30, r26, r0
	  addi      r3, r30, 0
	  addi      r4, r13, 0x97C
	  li        r5, 0x2
	  bl        0x98AD8
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x980
	  li        r5, 0x2
	  bl        0x98AC0
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x970
	  li        r5, 0x2
	  bl        0x98AA8
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x984
	  li        r5, 0x1
	  bl        0x98A90
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x988
	  li        r5, 0x2
	  bl        0x98A78
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x98C
	  li        r5, 0x2
	  bl        0x98A60
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x990
	  li        r5, 0x2
	  bl        0x98A48
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x994
	  li        r5, 0x2
	  bl        0x98A30
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x998
	  li        r5, 0x2
	  bl        0x98A18
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x99C
	  li        r5, 0x2
	  bl        0x98A00
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9A0
	  li        r5, 0x2
	  bl        0x989E8
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9A4
	  li        r5, 0x2
	  bl        0x989D0
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9A8
	  li        r5, 0x2
	  bl        0x989B8
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9AC
	  li        r5, 0x2
	  bl        0x989A0
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9B0
	  li        r5, 0x2
	  bl        0x98988
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9B4
	  li        r5, 0x2
	  bl        0x98970
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9B8
	  li        r5, 0x2
	  bl        0x98958
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9BC
	  li        r5, 0x2
	  bl        0x98940
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9C0
	  li        r5, 0x2
	  bl        0x98928
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9C4
	  li        r5, 0x2
	  bl        0x98910
	  cmpwi     r3, 0
	  beq-      .loc_0x2A4
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9C8
	  li        r5, 0x2
	  bl        0x988F8
	  cmpwi     r3, 0
	  bne-      .loc_0x38C

	.loc_0x2A4:
	  addi      r3, r30, 0
	  addi      r4, r13, 0x984
	  li        r5, 0x1
	  bl        0x988E0
	  cmpwi     r3, 0
	  bne-      .loc_0x2C4
	  addi      r29, r29, 0x1
	  b         .loc_0x38C

	.loc_0x2C4:
	  addi      r3, r30, 0
	  addi      r4, r13, 0x970
	  li        r5, 0x2
	  bl        0x988C0
	  cmpwi     r3, 0
	  bne-      .loc_0x2EC
	  lfs       f0, -0x50B8(r2)
	  addi      r29, r29, 0x2
	  stfs      f0, 0x0(r28)
	  b         .loc_0x38C

	.loc_0x2EC:
	  addi      r3, r30, 0
	  addi      r4, r13, 0x9CC
	  bl        0x98800
	  cmplwi    r3, 0
	  beq-      .loc_0x334
	  sub       r4, r3, r30
	  lis       r3, 0x803D
	  addi      r28, r4, 0x1
	  addi      r31, r3, 0x1EE0
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  addi      r5, r28, 0
	  bl        0x98A04
	  add       r3, r31, r28
	  li        r0, 0
	  stb       r0, 0x0(r3)
	  add       r29, r29, r28
	  b         .loc_0x38C

	.loc_0x334:
	  addi      r29, r29, 0x2
	  b         .loc_0x38C

	.loc_0x33C:
	  rlwinm.   r0,r30,0,24,24
	  beq-      .loc_0x354
	  addi      r29, r31, 0x2
	  li        r3, 0x11E
	  bl        -0xDB5CC
	  b         .loc_0x38C

	.loc_0x354:
	  addi      r3, r25, 0x10
	  addi      r4, r30, 0
	  bl        0x98804
	  cmplwi    r3, 0
	  beq-      .loc_0x380
	  lfs       f0, -0x50B8(r2)
	  li        r3, 0x11E
	  stfs      f0, 0x0(r28)
	  bl        -0xDB5F4
	  addi      r29, r31, 0x1
	  b         .loc_0x38C

	.loc_0x380:
	  addi      r29, r31, 0x1
	  li        r3, 0x11E
	  bl        -0xDB608

	.loc_0x38C:
	  sth       r29, 0x0(r27)
	  li        r3, 0

	.loc_0x394:
	  lmw       r25, 0x24(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8018099C
 * Size:	000104
 */
void zen::TypingTextMgr::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x38
	  lwz       r3, 0x8(r31)
	  li        r4, 0
	  lbz       r0, 0xC(r3)
	  rlwimi    r0,r4,7,24,24
	  stb       r0, 0xC(r3)
	  b         .loc_0xF0

	.loc_0x38:
	  cmpwi     r0, 0x2
	  bne-      .loc_0x50
	  lwz       r0, 0xC(r31)
	  lwz       r3, 0x8(r31)
	  stw       r0, 0x10C(r3)
	  b         .loc_0xF0

	.loc_0x50:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x410(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x410(r31)
	  lfs       f1, 0x410(r31)
	  lfs       f0, -0x50B4(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xF0
	  fsubs     f0, f1, f0
	  addi      r5, r31, 0x414
	  addi      r6, r1, 0x24
	  stfs      f0, 0x410(r31)
	  lwz       r3, 0x4(r31)
	  lwz       r4, 0xC(r31)
	  bl        -0x438
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xA4
	  li        r0, 0x2
	  stw       r0, 0x0(r31)

	.loc_0xA4:
	  lfs       f1, 0x24(r1)
	  lfs       f0, -0x50D8(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xBC
	  fneg      f0, f1
	  stfs      f0, 0x410(r31)

	.loc_0xBC:
	  lha       r0, 0x414(r31)
	  cmpwi     r0, 0x3FF
	  ble-      .loc_0xD0
	  li        r0, 0x3FF
	  sth       r0, 0x414(r31)

	.loc_0xD0:
	  lwz       r4, 0xC(r31)
	  addi      r3, r31, 0x10
	  lha       r5, 0x414(r31)
	  bl        0x9889C
	  lha       r0, 0x414(r31)
	  li        r4, 0
	  add       r3, r31, r0
	  stb       r4, 0x10(r3)

	.loc_0xF0:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80180AA0
 * Size:	0003B4
 */
void zen::cnvSpecialNumberHyphen(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802D
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x240(r1)
	  stmw      r22, 0x218(r1)
	  addi      r30, r4, 0x2750
	  addi      r26, r3, 0
	  addi      r29, r26, 0
	  addi      r28, r30, 0x1C
	  addi      r3, r30, 0x51C
	  li        r27, 0
	  addi      r4, r13, 0x96C
	  bl        0x98888
	  addi      r25, r1, 0x14
	  addi      r31, r1, 0x118

	.loc_0x3C:
	  lbz       r3, 0x0(r29)
	  lbz       r24, 0x1(r29)
	  cmplwi    r3, 0
	  lbz       r23, 0x2(r29)
	  lbz       r22, 0x3(r29)
	  beq-      .loc_0x370
	  cmplwi    r3, 0x1B
	  bne-      .loc_0x340
	  addi      r3, r29, 0x1
	  addi      r4, r13, 0x970
	  li        r5, 0x2
	  bl        0x9867C
	  cmpwi     r3, 0
	  bne-      .loc_0x7C
	  addi      r29, r29, 0x3
	  b         .loc_0x3C

	.loc_0x7C:
	  cmplwi    r24, 0x5A
	  bne-      .loc_0xD0
	  cmplwi    r23, 0x30
	  blt+      .loc_0x3C
	  cmplwi    r23, 0x39
	  bgt+      .loc_0x3C
	  subi      r0, r23, 0x30
	  cmpwi     r0, 0x1
	  mr        r27, r0
	  addi      r29, r29, 0x3
	  ble-      .loc_0xC0
	  addi      r5, r27, 0
	  crclr     6, 0x6
	  addi      r3, r30, 0x51C
	  addi      r4, r13, 0x974
	  bl        0x95A40
	  b         .loc_0x3C

	.loc_0xC0:
	  addi      r3, r30, 0x51C
	  addi      r4, r13, 0x96C
	  bl        0x987F0
	  b         .loc_0x3C

	.loc_0xD0:
	  cmplwi    r24, 0x64
	  bne-      .loc_0x32C
	  cmplwi    r23, 0x30
	  blt-      .loc_0x324
	  cmplwi    r23, 0x39
	  bgt-      .loc_0x324
	  cmplwi    r22, 0x30
	  blt-      .loc_0x214
	  cmplwi    r22, 0x39
	  bgt-      .loc_0x214
	  subi      r0, r23, 0x30
	  mulli     r3, r0, 0xA
	  add       r3, r22, r3
	  subi      r3, r3, 0x30
	  rlwinm    r0,r3,2,0,29
	  add       r3, r30, r0
	  lwz       r0, 0x61C(r3)
	  addi      r29, r29, 0x4
	  cmpwi     r0, 0
	  mr        r22, r0
	  blt-      .loc_0x150
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  addi      r5, r22, 0
	  addi      r4, r30, 0x51C
	  bl        0x959C4
	  addi      r5, r22, 0
	  crclr     6, 0x6
	  addi      r3, r30, 0x41C
	  addi      r4, r30, 0x51C
	  bl        0x959B0
	  b         .loc_0x204

	.loc_0x150:
	  cmpwi     r27, 0
	  li        r4, 0
	  ble-      .loc_0x1D4
	  cmpwi     r27, 0x8
	  subi      r3, r27, 0x8
	  ble-      .loc_0x388
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  addi      r3, r1, 0x118
	  li        r0, 0x2A
	  ble-      .loc_0x388

	.loc_0x184:
	  stb       r0, 0x0(r3)
	  addi      r4, r4, 0x8
	  stb       r0, 0x1(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x3(r3)
	  stb       r0, 0x4(r3)
	  stb       r0, 0x5(r3)
	  stb       r0, 0x6(r3)
	  stb       r0, 0x7(r3)
	  addi      r3, r3, 0x8
	  bdnz+     .loc_0x184
	  b         .loc_0x388

	.loc_0x1B4:
	  sub       r0, r27, r4
	  cmpw      r4, r27
	  mtctr     r0
	  li        r0, 0x2A
	  bge-      .loc_0x1D4

	.loc_0x1C8:
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0x1C8

	.loc_0x1D4:
	  li        r0, 0
	  crclr     6, 0x6
	  stbx      r0, r31, r27
	  addi      r3, r28, 0
	  addi      r5, r31, 0
	  addi      r4, r13, 0x9D0
	  bl        0x9590C
	  addi      r5, r31, 0
	  crclr     6, 0x6
	  addi      r3, r30, 0x41C
	  addi      r4, r13, 0x9D0
	  bl        0x958F8

	.loc_0x204:
	  addi      r3, r30, 0x41C
	  bl        0x98764
	  add       r28, r28, r3
	  b         .loc_0x3C

	.loc_0x214:
	  subi      r0, r23, 0x30
	  rlwinm    r0,r0,2,0,29
	  add       r3, r30, r0
	  lwz       r0, 0x61C(r3)
	  addi      r29, r29, 0x3
	  cmpwi     r0, 0
	  mr        r22, r0
	  blt-      .loc_0x260
	  addi      r3, r28, 0
	  crclr     6, 0x6
	  addi      r5, r22, 0
	  addi      r4, r30, 0x51C
	  bl        0x958B4
	  addi      r5, r22, 0
	  crclr     6, 0x6
	  addi      r3, r30, 0x41C
	  addi      r4, r30, 0x51C
	  bl        0x958A0
	  b         .loc_0x314

	.loc_0x260:
	  cmpwi     r27, 0
	  li        r4, 0
	  ble-      .loc_0x2E4
	  cmpwi     r27, 0x8
	  subi      r3, r27, 0x8
	  ble-      .loc_0x394
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  addi      r3, r1, 0x14
	  li        r0, 0x2A
	  ble-      .loc_0x394

	.loc_0x294:
	  stb       r0, 0x0(r3)
	  addi      r4, r4, 0x8
	  stb       r0, 0x1(r3)
	  stb       r0, 0x2(r3)
	  stb       r0, 0x3(r3)
	  stb       r0, 0x4(r3)
	  stb       r0, 0x5(r3)
	  stb       r0, 0x6(r3)
	  stb       r0, 0x7(r3)
	  addi      r3, r3, 0x8
	  bdnz+     .loc_0x294
	  b         .loc_0x394

	.loc_0x2C4:
	  sub       r0, r27, r4
	  cmpw      r4, r27
	  mtctr     r0
	  li        r0, 0x2A
	  bge-      .loc_0x2E4

	.loc_0x2D8:
	  stb       r0, 0x0(r3)
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0x2D8

	.loc_0x2E4:
	  li        r0, 0
	  crclr     6, 0x6
	  stbx      r0, r25, r27
	  addi      r3, r28, 0
	  addi      r5, r25, 0
	  addi      r4, r13, 0x9D0
	  bl        0x957FC
	  addi      r5, r25, 0
	  crclr     6, 0x6
	  addi      r3, r30, 0x41C
	  addi      r4, r13, 0x9D0
	  bl        0x957E8

	.loc_0x314:
	  addi      r3, r30, 0x41C
	  bl        0x98654
	  add       r28, r28, r3
	  b         .loc_0x3C

	.loc_0x324:
	  addi      r29, r29, 0x2
	  b         .loc_0x3C

	.loc_0x32C:
	  lbz       r0, 0x0(r29)
	  addi      r29, r29, 0x1
	  stb       r0, 0x0(r28)
	  addi      r28, r28, 0x1
	  b         .loc_0x3C

	.loc_0x340:
	  rlwinm.   r0,r3,0,24,24
	  beq-      .loc_0x360
	  stb       r3, 0x0(r28)
	  lbz       r0, 0x1(r29)
	  addi      r29, r29, 0x2
	  stb       r0, 0x1(r28)
	  addi      r28, r28, 0x2
	  b         .loc_0x3C

	.loc_0x360:
	  stb       r3, 0x0(r28)
	  addi      r28, r28, 0x1
	  addi      r29, r29, 0x1
	  b         .loc_0x3C

	.loc_0x370:
	  li        r0, 0
	  stb       r0, 0x0(r28)
	  addi      r3, r26, 0
	  addi      r4, r30, 0x1C
	  bl        0x98538
	  b         .loc_0x3A0

	.loc_0x388:
	  addi      r3, r1, 0x118
	  add       r3, r3, r4
	  b         .loc_0x1B4

	.loc_0x394:
	  addi      r3, r1, 0x14
	  add       r3, r3, r4
	  b         .loc_0x2C4

	.loc_0x3A0:
	  lmw       r22, 0x218(r1)
	  lwz       r0, 0x244(r1)
	  addi      r1, r1, 0x240
	  mtlr      r0
	  blr
	*/
}

} // namespace zen
