#include "MovSampleSection.h"
#include "Dolphin/gx.h"
#include "jaudio/app_inter.h"
#include "Graphics.h"
#include "DebugLog.h"

GXTexObj YtexObj;
GXTexObj UVtexObj;

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
DEFINE_PRINT("TODO: Replace")

/*
 * --INFO--
 * Address:	80077EF0
 * Size:	0003F0
 */
void convHVQM4TexY8UV8(int, int, u8*, u8*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r11, r5, 0
	  stw       r0, 0x4(r1)
	  srawi     r0, r3, 0x2
	  addze     r0, r0
	  stwu      r1, -0x38(r1)
	  rlwinm    r8,r0,2,0,29
	  add       r0, r5, r8
	  stmw      r25, 0x1C(r1)
	  add       r7, r0, r8
	  mr        r12, r0
	  addi      r25, r7, 0
	  addi      r10, r4, 0
	  addi      r9, r6, 0
	  add       r26, r7, r8
	  b         .loc_0x1F4

	.loc_0x40:
	  cmpwi     r3, 0
	  addi      r7, r3, 0x7
	  rlwinm    r7,r7,29,3,31
	  ble-      .loc_0x1D8
	  rlwinm.   r0,r7,30,2,31
	  mtctr     r0
	  beq-      .loc_0x17C

	.loc_0x5C:
	  lwz       r0, 0x0(r11)
	  stw       r0, 0x0(r9)
	  lwz       r0, 0x4(r11)
	  stw       r0, 0x4(r9)
	  lwz       r0, 0x0(r12)
	  stw       r0, 0x8(r9)
	  lwz       r0, 0x4(r12)
	  stw       r0, 0xC(r9)
	  lwz       r0, 0x0(r25)
	  stw       r0, 0x10(r9)
	  lwz       r0, 0x4(r25)
	  stw       r0, 0x14(r9)
	  lwz       r0, 0x0(r26)
	  stw       r0, 0x18(r9)
	  lwz       r0, 0x4(r26)
	  stw       r0, 0x1C(r9)
	  lwz       r0, 0x8(r11)
	  stw       r0, 0x20(r9)
	  lwz       r0, 0xC(r11)
	  stw       r0, 0x24(r9)
	  lwz       r0, 0x8(r12)
	  stw       r0, 0x28(r9)
	  lwz       r0, 0xC(r12)
	  stw       r0, 0x2C(r9)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x30(r9)
	  lwz       r0, 0xC(r25)
	  stw       r0, 0x34(r9)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x38(r9)
	  lwz       r0, 0xC(r26)
	  stw       r0, 0x3C(r9)
	  lwz       r0, 0x10(r11)
	  stw       r0, 0x40(r9)
	  lwz       r0, 0x14(r11)
	  stw       r0, 0x44(r9)
	  lwz       r0, 0x10(r12)
	  stw       r0, 0x48(r9)
	  lwz       r0, 0x14(r12)
	  stw       r0, 0x4C(r9)
	  lwz       r0, 0x10(r25)
	  stw       r0, 0x50(r9)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x54(r9)
	  lwz       r0, 0x10(r26)
	  stw       r0, 0x58(r9)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x5C(r9)
	  lwz       r0, 0x18(r11)
	  stw       r0, 0x60(r9)
	  lwz       r0, 0x1C(r11)
	  addi      r11, r11, 0x20
	  stw       r0, 0x64(r9)
	  lwz       r0, 0x18(r12)
	  stw       r0, 0x68(r9)
	  lwz       r0, 0x1C(r12)
	  addi      r12, r12, 0x20
	  stw       r0, 0x6C(r9)
	  lwz       r0, 0x18(r25)
	  stw       r0, 0x70(r9)
	  lwz       r0, 0x1C(r25)
	  addi      r25, r25, 0x20
	  stw       r0, 0x74(r9)
	  lwz       r0, 0x18(r26)
	  stw       r0, 0x78(r9)
	  lwz       r0, 0x1C(r26)
	  addi      r26, r26, 0x20
	  stw       r0, 0x7C(r9)
	  addi      r9, r9, 0x80
	  bdnz+     .loc_0x5C
	  andi.     r7, r7, 0x3
	  beq-      .loc_0x1D8

	.loc_0x17C:
	  mtctr     r7

	.loc_0x180:
	  lwz       r0, 0x0(r11)
	  stw       r0, 0x0(r9)
	  lwz       r0, 0x4(r11)
	  addi      r11, r11, 0x8
	  stw       r0, 0x4(r9)
	  lwz       r0, 0x0(r12)
	  stw       r0, 0x8(r9)
	  lwz       r0, 0x4(r12)
	  addi      r12, r12, 0x8
	  stw       r0, 0xC(r9)
	  lwz       r0, 0x0(r25)
	  stw       r0, 0x10(r9)
	  lwz       r0, 0x4(r25)
	  addi      r25, r25, 0x8
	  stw       r0, 0x14(r9)
	  lwz       r0, 0x0(r26)
	  stw       r0, 0x18(r9)
	  lwz       r0, 0x4(r26)
	  addi      r26, r26, 0x8
	  stw       r0, 0x1C(r9)
	  addi      r9, r9, 0x20
	  bdnz+     .loc_0x180

	.loc_0x1D8:
	  add       r0, r26, r8
	  add       r7, r0, r8
	  addi      r11, r26, 0
	  mr        r12, r0
	  addi      r25, r7, 0
	  add       r26, r7, r8
	  subi      r10, r10, 0x4

	.loc_0x1F4:
	  cmpwi     r10, 0
	  bgt+      .loc_0x40
	  srawi     r31, r3, 0x1
	  addze     r31, r31
	  srawi     r30, r4, 0x1
	  mullw     r0, r3, r4
	  addze     r30, r30
	  add       r4, r5, r0
	  add       r3, r4, r31
	  mullw     r29, r31, r30
	  add       r8, r4, r29
	  add       r10, r8, r31
	  add       r11, r10, r31
	  add       r7, r3, r31
	  addi      r5, r3, 0
	  addi      r9, r8, 0
	  add       r8, r7, r31
	  add       r12, r11, r31
	  add       r3, r6, r0
	  b         .loc_0x3C4

	.loc_0x244:
	  addi      r28, r31, 0x3
	  rlwinm    r28,r28,30,2,31
	  cmpwi     r31, 0
	  mtctr     r28
	  ble-      .loc_0x3A0

	.loc_0x258:
	  lbz       r25, 0x0(r9)
	  lbz       r26, 0x0(r4)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x1(r4)
	  rlwimi    r25,r26,24,0,7
	  lbz       r28, 0x1(r9)
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x0(r3)
	  lbz       r25, 0x2(r9)
	  lbz       r28, 0x3(r9)
	  addi      r9, r9, 0x4
	  lbz       r26, 0x2(r4)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x3(r4)
	  rlwimi    r25,r26,24,0,7
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x4(r3)
	  addi      r4, r4, 0x4
	  lbz       r25, 0x0(r10)
	  lbz       r26, 0x0(r5)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x1(r5)
	  rlwimi    r25,r26,24,0,7
	  lbz       r28, 0x1(r10)
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x8(r3)
	  lbz       r25, 0x2(r10)
	  lbz       r28, 0x3(r10)
	  addi      r10, r10, 0x4
	  lbz       r26, 0x2(r5)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x3(r5)
	  rlwimi    r25,r26,24,0,7
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0xC(r3)
	  addi      r5, r5, 0x4
	  lbz       r25, 0x0(r11)
	  lbz       r26, 0x0(r7)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x1(r7)
	  rlwimi    r25,r26,24,0,7
	  lbz       r28, 0x1(r11)
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x10(r3)
	  lbz       r25, 0x2(r11)
	  lbz       r28, 0x3(r11)
	  addi      r11, r11, 0x4
	  lbz       r26, 0x2(r7)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x3(r7)
	  rlwimi    r25,r26,24,0,7
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x14(r3)
	  addi      r7, r7, 0x4
	  lbz       r25, 0x0(r12)
	  lbz       r26, 0x0(r8)
	  rlwinm    r25,r25,16,0,15
	  lbz       r27, 0x1(r8)
	  rlwimi    r25,r26,24,0,7
	  lbz       r28, 0x1(r12)
	  rlwimi    r25,r27,8,16,23
	  or        r25, r28, r25
	  stw       r25, 0x18(r3)
	  lbz       r28, 0x2(r12)
	  lbz       r25, 0x3(r12)
	  addi      r12, r12, 0x4
	  lbz       r27, 0x2(r8)
	  rlwinm    r28,r28,16,0,15
	  lbz       r26, 0x3(r8)
	  rlwimi    r28,r27,24,0,7
	  rlwimi    r28,r26,8,16,23
	  or        r28, r25, r28
	  stw       r28, 0x1C(r3)
	  addi      r3, r3, 0x20
	  addi      r8, r8, 0x4
	  bdnz+     .loc_0x258

	.loc_0x3A0:
	  add       r5, r8, r31
	  add       r10, r12, r31
	  add       r7, r5, r31
	  addi      r4, r8, 0
	  add       r11, r10, r31
	  addi      r9, r12, 0
	  add       r8, r7, r31
	  add       r12, r11, r31
	  subi      r30, r30, 0x4

	.loc_0x3C4:
	  cmpwi     r30, 0
	  bgt+      .loc_0x244
	  rlwinm    r4,r29,1,0,30
	  addi      r3, r6, 0
	  add       r4, r0, r4
	  bl        0x17E954
	  lmw       r25, 0x1C(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800782E0
 * Size:	000034
 */
static void* playbackFunc(void*)
{
	while (!finishPlayback) {
		Jac_StreamMovieUpdate();
	}
	return nullptr;
}

/*
 * --INFO--
 * Address:	80078314
 * Size:	000258
 */
void MovSampleSection::init()
{
	Node::init("<MovSampleSection>");
	gsys->mFrameRate  = 1;
	gsys->mTimerState = 0;
	gsys->startLoading(nullptr, true, 60);

	MovSampleSetupSection* sect = new MovSampleSetupSection;
	add(sect);
	gsys->endLoading();
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r25, 0x14(r1)
	  subi      r26, r4, 0x3728
	  lis       r4, 0x803D
	  addi      r31, r4, 0x260
	  addi      r28, r3, 0
	  addi      r4, r26, 0xC4
	  bl        -0x37C00
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x1
	  li        r0, 0
	  stw       r4, 0x14(r3)
	  li        r4, 0
	  li        r5, 0x1
	  lwz       r3, 0x2DEC(r13)
	  li        r6, 0x3C
	  stw       r0, 0x18(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x50
	  bl        -0x31378
	  addi      r29, r3, 0
	  mr.       r27, r29
	  beq-      .loc_0x224
	  addi      r3, r27, 0
	  subi      r4, r13, 0x64C0
	  bl        -0x433DC
	  lis       r3, 0x8023
	  subi      r30, r3, 0x71E0
	  stw       r30, 0x0(r29)
	  addi      r3, r27, 0
	  subi      r4, r13, 0x64C0
	  bl        -0x37C70
	  lis       r3, 0x802B
	  subi      r0, r3, 0x35B0
	  stw       r0, 0x0(r29)
	  addi      r0, r26, 0xD8
	  li        r3, 0x50
	  stw       r0, 0x4(r29)
	  bl        -0x313C4
	  addi      r25, r3, 0
	  mr.       r0, r25
	  beq-      .loc_0xF8
	  addi      r3, r25, 0
	  addi      r4, r26, 0xEC
	  bl        -0x43428
	  stw       r30, 0x0(r25)
	  addi      r3, r25, 0
	  addi      r4, r26, 0xEC
	  bl        -0x37CB4
	  lis       r3, 0x8023
	  subi      r0, r3, 0x714C
	  stw       r0, 0x0(r25)
	  addi      r3, r25, 0
	  li        r4, 0x1
	  bl        -0x37A58

	.loc_0xF8:
	  stw       r25, 0x2C(r29)
	  li        r0, 0xA0
	  lis       r26, 0xE0
	  stw       r0, 0x28(r29)
	  li        r30, 0
	  addi      r3, r26, 0
	  stw       r30, 0x30(r29)
	  li        r4, 0x20
	  lwz       r5, 0x2DEC(r13)
	  lfs       f0, -0x7720(r2)
	  stfs      f0, 0x8(r5)
	  lfs       f0, -0x771C(r2)
	  stfs      f0, 0xC(r5)
	  bl        -0x312D8
	  lis       r4, 0x803A
	  subi      r4, r4, 0x2848
	  lwz       r0, 0x2B0(r4)
	  lis       r4, 0x802B
	  rlwinm    r5,r0,2,0,29
	  subi      r0, r4, 0x367C
	  add       r5, r0, r5
	  addi      r4, r3, 0
	  lwz       r3, 0x0(r5)
	  mr        r5, r26
	  bl        -0x6100C
	  li        r3, 0x280
	  li        r0, 0x1E0
	  sth       r3, 0x2F1A(r13)
	  lis       r3, 0x7
	  addi      r26, r3, 0x800
	  sth       r0, 0x2F18(r13)
	  addi      r3, r26, 0
	  li        r4, 0x20
	  bl        -0x31328
	  stw       r3, 0x48(r29)
	  addi      r3, r26, 0
	  li        r4, 0x20
	  bl        -0x31338
	  stw       r3, 0x4C(r29)

	.loc_0x194:
	  lhz       r3, 0x2F1A(r13)
	  li        r4, 0x10
	  lhz       r0, 0x2F18(r13)
	  lwz       r6, 0x48(r29)
	  mullw     r5, r3, r0
	  addi      r3, r6, 0
	  add       r26, r6, r5
	  bl        -0x751A4
	  lhz       r5, 0x2F1A(r13)
	  mr        r3, r26
	  lhz       r0, 0x2F18(r13)
	  li        r4, 0x80
	  srawi     r5, r5, 0x1
	  addze     r5, r5
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  mullw     r0, r5, r0
	  rlwinm    r5,r0,1,0,30
	  bl        -0x751D0
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x2
	  addi      r29, r29, 0x4
	  blt+      .loc_0x194
	  lis       r3, 0x8008
	  subi      r4, r3, 0x7D20
	  addi      r3, r31, 0x40
	  addi      r6, r31, 0x1350
	  li        r5, 0
	  li        r7, 0x1000
	  li        r8, 0x14
	  li        r9, 0x1
	  bl        0x183BA0
	  li        r0, 0
	  stb       r0, 0x2F1C(r13)
	  addi      r3, r31, 0x40
	  bl        0x184090

	.loc_0x224:
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  bl        -0x37F68
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x30(r12)
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
 * Address:	8007856C
 * Size:	00014C
 */
void MovSampleSetupSection::update()
{
	mControl->update();

	if (gsys->_258 < 0) {
		Jac_StreamMovieGetPicture();
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  mr        r30, r3
	  stw       r29, 0x2C(r1)
	  lwz       r3, 0x2C(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  lwz       r3, 0x2DEC(r13)
	  stw       r0, 0x20(r1)
	  li        r31, 0
	  lwz       r0, 0x258(r3)
	  cmpwi     r0, 0
	  bge-      .loc_0x60
	  addi      r3, r1, 0x20
	  addi      r4, r1, 0x1C
	  addi      r5, r1, 0x18
	  bl        -0x61064
	  mr        r31, r3

	.loc_0x60:
	  lwz       r5, 0x20(r1)
	  cmplwi    r5, 0
	  beq-      .loc_0xA0
	  cmpwi     r31, 0
	  beq-      .loc_0xA0
	  lwz       r0, 0x3C(r30)
	  lwz       r3, 0x1C(r1)
	  xori      r0, r0, 0x1
	  lwz       r4, 0x18(r1)
	  rlwinm    r0,r0,2,0,29
	  add       r6, r30, r0
	  lwz       r6, 0x48(r6)
	  bl        -0x70C
	  lwz       r0, 0x3C(r30)
	  xori      r0, r0, 0x1
	  stw       r0, 0x3C(r30)

	.loc_0xA0:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  addi      r29, r3, 0x244
	  lwz       r0, 0x244(r3)
	  li        r5, 0
	  cmpwi     r0, 0
	  bne-      .loc_0xD8
	  lwz       r4, 0x2C(r30)
	  lis       r3, 0x100
	  addi      r0, r3, 0x3000
	  lwz       r3, 0x28(r4)
	  and.      r0, r3, r0
	  beq-      .loc_0xD8
	  li        r5, 0x1

	.loc_0xD8:
	  rlwinm.   r0,r5,0,24,31
	  bne-      .loc_0xE8
	  cmpwi     r31, -0x1
	  bne-      .loc_0x130

	.loc_0xE8:
	  bl        -0x61174
	  lis       r3, 0x803D
	  addi      r3, r3, 0x2A0
	  bl        0x183C68
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0
	  beq-      .loc_0x118
	  li        r3, 0xD
	  li        r4, 0
	  bl        -0x5E998
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x118:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, 0x1
	  stw       r0, 0x1F0(r3)
	  lwz       r3, 0x2DEC(r13)
	  stb       r0, 0x0(r3)

	.loc_0x130:
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
 * Address:	800786B8
 * Size:	0006F8
 */
void MovSampleSetupSection::draw(Graphics& gfx)
{
	gfx.setViewport(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setScissor(RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));
	gfx.setClearColour(Colour(0, 0, 0, 0));
	gfx.clearBuffer(3, false);
	Mtx mtx;
	gfx.setOrthogonal(mtx, RectArea(0, 0, gfx.mScreenWidth, gfx.mScreenHeight));

	GXSetNumTexGens(2);
	GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, 60, 0, 125);
	GXSetTexCoordGen2(GX_TEXCOORD1, GX_TG_MTX3X4, GX_TG_TEX0, 60, 0, 125);
	GXInvalidateTexAll();
	GXSetBlendMode(GX_BM_NONE, GX_BL_ONE, GX_BL_ZERO, GX_LO_CLEAR);
	GXSetNumTevStages(4);

	GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
	GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_TEXC, GX_CC_KONST, GX_CC_C0);
	GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
	GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_A0);
	GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_FALSE, GX_TEVPREV);
	GXSetTevKColorSel(GX_TEVSTAGE0, GX_TEV_KCSEL_K0);
	GXSetTevKAlphaSel(GX_TEVSTAGE0, GX_TEV_KASEL_K0_A);
	GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP1);

	GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP1, GX_COLOR_NULL);
	GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_TEXC, GX_CC_KONST, GX_CC_CPREV);
	GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, GX_FALSE, GX_TEVPREV);
	GXSetTevAlphaIn(GX_TEVSTAGE1, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_APREV);
	GXSetTevAlphaOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_2, GX_FALSE, GX_TEVPREV);
	GXSetTevKColorSel(GX_TEVSTAGE1, GX_TEV_KCSEL_K1);
	GXSetTevKAlphaSel(GX_TEVSTAGE1, GX_TEV_KASEL_K1_A);
	GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);

	GXSetTevOrder(GX_TEVSTAGE2, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
	GXSetTevColorIn(GX_TEVSTAGE2, GX_CC_ZERO, GX_CC_TEXC, GX_CC_KONST, GX_CC_CPREV);
	GXSetTevColorOp(GX_TEVSTAGE2, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevAlphaIn(GX_TEVSTAGE2, GX_CA_ZERO, GX_CA_TEXA, GX_CA_KONST, GX_CA_APREV);
	GXSetTevAlphaOp(GX_TEVSTAGE2, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevKColorSel(GX_TEVSTAGE2, GX_TEV_KCSEL_K2);
	GXSetTevKAlphaSel(GX_TEVSTAGE2, GX_TEV_KASEL_K2_A);
	GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP2);

	GXSetTevOrder(GX_TEVSTAGE3, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
	GXSetTevColorIn(GX_TEVSTAGE3, GX_CC_CPREV, GX_CC_APREV, GX_CC_KONST, GX_CC_ZERO);
	GXSetTevColorOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevAlphaIn(GX_TEVSTAGE3, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
	GXSetTevAlphaOp(GX_TEVSTAGE3, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
	GXSetTevSwapMode(GX_TEVSTAGE3, GX_TEV_SWAP0, GX_TEV_SWAP0);
	GXSetTevKColorSel(GX_TEVSTAGE3, GX_TEV_KCSEL_K3);

	GXColorS10 col1 = {};
	GXSetTevColorS10(GX_TEVREG0, col1);

	GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
	GXSetTevSwapModeTable(GX_TEV_SWAP1, GX_CH_RED, GX_CH_ALPHA, GX_CH_ALPHA, GX_CH_ALPHA);
	GXSetTevSwapModeTable(GX_TEV_SWAP2, GX_CH_RED, GX_CH_RED, GX_CH_ALPHA, GX_CH_RED);

	GXInitTexObj(&YtexObj, _48[_3C], ImgW, ImgH, GX_TF_I8, GX_CLAMP, GX_CLAMP, GX_FALSE);
	GXInitTexObjLOD(&YtexObj, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
	GXLoadTexObj(&YtexObj, GX_TEXMAP1);

	GXInitTexObj(&UVtexObj, _48[_3C], ImgW * 2, ImgH * 2, GX_TF_IA8, GX_CLAMP, GX_CLAMP, GX_FALSE);
	GXInitTexObjLOD(&UVtexObj, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
	GXLoadTexObj(&UVtexObj, GX_TEXMAP0);

	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.testRectangle(RectArea(0, 0, 640, 480));

	GXSetTevSwapModeTable(GX_TEV_SWAP0, GX_CH_RED, GX_CH_GREEN, GX_CH_BLUE, GX_CH_ALPHA);
	GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
	GXSetTevSwapMode(GX_TEVSTAGE1, GX_TEV_SWAP0, GX_TEV_SWAP0);
	GXSetTevSwapMode(GX_TEVSTAGE2, GX_TEV_SWAP0, GX_TEV_SWAP0);
	GXSetTevSwapMode(GX_TEVSTAGE3, GX_TEV_SWAP0, GX_TEV_SWAP0);

	gfx.setColour(Colour(255, 255, 64, 255), true);
	gfx.setAuxColour(Colour(255, 0, 64, 255));

	gameflow.drawLoadLogo(gfx, false, gameflow.mLevelBannerTexture, gameflow.mLevelBannerFadeValue);

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F8(r1)
	  stw       r31, 0x1F4(r1)
	  mr        r31, r4
	  stw       r30, 0x1F0(r1)
	  li        r30, 0
	  stw       r29, 0x1EC(r1)
	  stw       r28, 0x1E8(r1)
	  mr        r28, r3
	  lis       r3, 0x803D
	  lwz       r5, 0x310(r4)
	  addi      r29, r3, 0x260
	  lwz       r0, 0x30C(r4)
	  addi      r4, r1, 0x94
	  mr        r3, r31
	  stw       r30, 0x94(r1)
	  stw       r30, 0x98(r1)
	  stw       r0, 0x9C(r1)
	  stw       r5, 0xA0(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x310(r31)
	  addi      r4, r1, 0x84
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  stw       r30, 0x84(r1)
	  stw       r30, 0x88(r1)
	  stw       r0, 0x8C(r1)
	  stw       r5, 0x90(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x50(r12)
	  mtlr      r12
	  blrl
	  stb       r30, 0x80(r1)
	  addi      r4, r1, 0x80
	  addi      r3, r31, 0
	  stb       r30, 0x81(r1)
	  stb       r30, 0x82(r1)
	  stb       r30, 0x83(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xB4(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x3
	  li        r5, 0
	  lwz       r12, 0x38(r12)
	  mtlr      r12
	  blrl
	  lwz       r6, 0x310(r31)
	  addi      r5, r1, 0x70
	  lwz       r0, 0x30C(r31)
	  mr        r3, r31
	  addi      r4, r1, 0x1A4
	  stw       r30, 0x70(r1)
	  stw       r30, 0x74(r1)
	  stw       r0, 0x78(r1)
	  stw       r6, 0x7C(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x2
	  bl        0x197F64
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x4
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x197C78
	  li        r3, 0x1
	  li        r4, 0x1
	  li        r5, 0x4
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x197C5C
	  bl        0x19A120
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  bl        0x19B438
	  li        r3, 0x4
	  bl        0x19B148
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0xFF
	  bl        0x19AF94
	  li        r3, 0
	  li        r4, 0xF
	  li        r5, 0x8
	  li        r6, 0xE
	  li        r7, 0x2
	  bl        0x19A8F8
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        0x19A9E0
	  li        r3, 0
	  li        r4, 0x7
	  li        r5, 0x4
	  li        r6, 0x6
	  li        r7, 0x1
	  bl        0x19A944
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        0x19AA6C
	  li        r3, 0
	  li        r4, 0xC
	  bl        0x19AC7C
	  li        r3, 0
	  li        r4, 0x1C
	  bl        0x19ACDC
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x1
	  bl        0x19AD38
	  li        r3, 0x1
	  li        r4, 0x1
	  li        r5, 0x1
	  li        r6, 0xFF
	  bl        0x19AEF0
	  li        r3, 0x1
	  li        r4, 0xF
	  li        r5, 0x8
	  li        r6, 0xE
	  li        r7, 0
	  bl        0x19A854
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  bl        0x19A93C
	  li        r3, 0x1
	  li        r4, 0x7
	  li        r5, 0x4
	  li        r6, 0x6
	  li        r7, 0
	  bl        0x19A8A0
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  li        r8, 0
	  bl        0x19A9C8
	  li        r3, 0x1
	  li        r4, 0xD
	  bl        0x19ABD8
	  li        r3, 0x1
	  li        r4, 0x1D
	  bl        0x19AC38
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  bl        0x19AC94
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0xFF
	  bl        0x19AE4C
	  li        r3, 0x2
	  li        r4, 0xF
	  li        r5, 0x8
	  li        r6, 0xE
	  li        r7, 0
	  bl        0x19A7B0
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x19A898
	  li        r3, 0x2
	  li        r4, 0x7
	  li        r5, 0x4
	  li        r6, 0x6
	  li        r7, 0
	  bl        0x19A7FC
	  li        r3, 0x2
	  li        r4, 0x1
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x19A924
	  li        r3, 0x2
	  li        r4, 0xE
	  bl        0x19AB34
	  li        r3, 0x2
	  li        r4, 0x1E
	  bl        0x19AB94
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0x2
	  bl        0x19ABF0
	  li        r3, 0x3
	  li        r4, 0xFF
	  li        r5, 0xFF
	  li        r6, 0xFF
	  bl        0x19ADA8
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0xE
	  li        r7, 0xF
	  bl        0x19A70C
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x19A7F4
	  li        r3, 0x3
	  li        r4, 0x7
	  li        r5, 0x7
	  li        r6, 0x7
	  li        r7, 0x7
	  bl        0x19A758
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0
	  li        r7, 0x1
	  li        r8, 0
	  bl        0x19A880
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  bl        0x19AB64
	  li        r3, 0x3
	  li        r4, 0xF
	  bl        0x19AA80
	  lwz       r3, -0x7738(r2)
	  addi      r4, r1, 0x24
	  lwz       r0, -0x7734(r2)
	  stw       r3, 0x2C(r1)
	  li        r3, 0x1
	  stw       r0, 0x30(r1)
	  lwz       r5, 0x2C(r1)
	  lwz       r0, 0x30(r1)
	  stw       r5, 0x24(r1)
	  stw       r0, 0x28(r1)
	  bl        0x19A96C
	  lwz       r0, -0x7730(r2)
	  addi      r4, r1, 0x34
	  li        r3, 0
	  stw       r0, 0x38(r1)
	  lwz       r0, 0x38(r1)
	  stw       r0, 0x34(r1)
	  bl        0x19A9C4
	  lwz       r0, -0x772C(r2)
	  addi      r4, r1, 0x3C
	  li        r3, 0x1
	  stw       r0, 0x40(r1)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0x3C(r1)
	  bl        0x19A9A8
	  lwz       r0, -0x7728(r2)
	  addi      r4, r1, 0x44
	  li        r3, 0x2
	  stw       r0, 0x48(r1)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x44(r1)
	  bl        0x19A98C
	  lwz       r0, -0x7724(r2)
	  addi      r4, r1, 0x4C
	  li        r3, 0x3
	  stw       r0, 0x50(r1)
	  lwz       r0, 0x50(r1)
	  stw       r0, 0x4C(r1)
	  bl        0x19A970
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0x3
	  bl        0x19AAFC
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0x3
	  li        r6, 0x3
	  li        r7, 0x3
	  bl        0x19AAE4
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x3
	  li        r7, 0
	  bl        0x19AACC
	  lwz       r0, 0x3C(r28)
	  mr        r3, r29
	  lhz       r5, 0x2F1A(r13)
	  li        r7, 0x1
	  rlwinm    r0,r0,2,0,29
	  add       r4, r28, r0
	  lhz       r6, 0x2F18(r13)
	  lwz       r28, 0x48(r4)
	  li        r8, 0
	  li        r9, 0
	  addi      r4, r28, 0
	  li        r10, 0
	  bl        0x199614
	  lfs       f1, -0x7718(r2)
	  addi      r3, r29, 0
	  li        r4, 0
	  fmr       f2, f1
	  li        r5, 0
	  fmr       f3, f1
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        0x199840
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        0x199B78
	  lhz       r4, 0x2F1A(r13)
	  addi      r3, r29, 0x20
	  lhz       r0, 0x2F18(r13)
	  li        r7, 0x3
	  srawi     r5, r4, 0x1
	  mullw     r4, r4, r0
	  addze     r5, r5
	  srawi     r0, r0, 0x1
	  addze     r0, r0
	  add       r4, r28, r4
	  rlwinm    r5,r5,0,16,31
	  rlwinm    r6,r0,0,16,31
	  li        r8, 0
	  li        r9, 0
	  li        r10, 0
	  bl        0x1995A0
	  lfs       f1, -0x7718(r2)
	  addi      r3, r29, 0x20
	  li        r4, 0
	  fmr       f2, f1
	  li        r5, 0
	  fmr       f3, f1
	  li        r6, 0
	  li        r7, 0
	  li        r8, 0
	  bl        0x1997CC
	  addi      r3, r29, 0x20
	  li        r4, 0
	  bl        0x199B04
	  li        r29, 0xFF
	  stb       r29, 0x6C(r1)
	  addi      r4, r1, 0x6C
	  addi      r3, r31, 0
	  stb       r29, 0x6D(r1)
	  li        r5, 0x1
	  stb       r29, 0x6E(r1)
	  stb       r29, 0x6F(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stw       r30, 0x5C(r1)
	  li        r0, 0x280
	  li        r5, 0x1E0
	  stw       r30, 0x60(r1)
	  addi      r4, r1, 0x5C
	  addi      r3, r31, 0
	  stw       r0, 0x64(r1)
	  stw       r5, 0x68(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xE0(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0x1
	  li        r6, 0x2
	  li        r7, 0x3
	  bl        0x19A978
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        0x19A910
	  li        r3, 0x1
	  li        r4, 0
	  li        r5, 0
	  bl        0x19A900
	  li        r3, 0x2
	  li        r4, 0
	  li        r5, 0
	  bl        0x19A8F0
	  li        r3, 0x3
	  li        r4, 0
	  li        r5, 0
	  bl        0x19A8E0
	  stb       r29, 0x58(r1)
	  li        r28, 0x40
	  addi      r4, r1, 0x58
	  stb       r29, 0x59(r1)
	  mr        r3, r31
	  li        r5, 0x1
	  stb       r28, 0x5A(r1)
	  stb       r29, 0x5B(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  stb       r29, 0x54(r1)
	  addi      r4, r1, 0x54
	  addi      r3, r31, 0
	  stb       r30, 0x55(r1)
	  stb       r28, 0x56(r1)
	  stb       r29, 0x57(r1)
	  lwz       r12, 0x3B4(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r6, 0x310(r3)
	  addi      r4, r31, 0
	  lfs       f1, 0x314(r3)
	  li        r5, 0
	  bl        -0x277C4
	  lwz       r0, 0x1FC(r1)
	  lwz       r31, 0x1F4(r1)
	  lwz       r30, 0x1F0(r1)
	  lwz       r29, 0x1EC(r1)
	  lwz       r28, 0x1E8(r1)
	  addi      r1, r1, 0x1F8
	  mtlr      r0
	  blr
	*/
}
