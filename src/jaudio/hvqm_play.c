#include "jaudio/hvqm_play.h"

/*
 * --INFO--
 * Address:	8001DC80
 * Size:	000104
 */
static void __ReLoad()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  lwz       r6, 0x2D88(r13)
	  cmplwi    r6, 0
	  bne-      .loc_0x28
	  li        r0, 0x1
	  stw       r0, 0x2D68(r13)
	  b         .loc_0xF0

	.loc_0x28:
	  lwz       r4, 0x2D6C(r13)
	  li        r3, 0x3
	  lis       r5, 0x803E
	  divwu     r0, r4, r3
	  subi      r5, r5, 0x3320
	  mullw     r0, r0, r3
	  sub       r0, r4, r0
	  rlwinm    r0,r0,4,0,27
	  add       r4, r5, r0
	  lbzu      r0, 0x4(r4)
	  cmplwi    r0, 0x3
	  bne-      .loc_0xF0
	  lis       r0, 0x8
	  li        r3, 0x1
	  cmplw     r6, r0
	  stb       r3, 0x0(r4)
	  bge-      .loc_0x74
	  stw       r6, 0x2D84(r13)
	  b         .loc_0x78

	.loc_0x74:
	  stw       r0, 0x2D84(r13)

	.loc_0x78:
	  lwz       r3, 0x2D84(r13)
	  lwz       r0, 0x2D88(r13)
	  sub       r0, r0, r3
	  stw       r0, 0x2D88(r13)
	  bl        0x1DB274
	  lwz       r10, 0x2D6C(r13)
	  li        r8, 0x3
	  lwz       r4, 0x2DA8(r13)
	  addi      r31, r3, 0
	  divwu     r0, r10, r8
	  lis       r6, 0x8039
	  addi      r5, r4, 0x1
	  lwz       r7, 0x2D84(r13)
	  stw       r5, 0x2DA8(r13)
	  lis       r5, 0x8002
	  lis       r4, 0x8039
	  subi      r9, r5, 0x2260
	  mullw     r8, r0, r8
	  subi      r0, r6, 0x5680
	  subi      r4, r4, 0x56C0
	  addi      r3, r10, 0
	  rlwinm    r6,r10,19,0,12
	  sub       r5, r10, r8
	  li        r8, 0
	  rlwinm    r5,r5,2,0,29
	  add       r5, r0, r5
	  lwz       r5, 0x0(r5)
	  bl        -0x16464
	  mr        r3, r31
	  bl        0x1DB238

	.loc_0xF0:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001DDA0
 * Size:	000074
 */
static void __LoadFin(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803E
	  stw       r0, 0x4(r1)
	  li        r4, 0x3
	  subi      r5, r5, 0x3320
	  stwu      r1, -0x8(r1)
	  lwz       r7, 0x2D6C(r13)
	  lwz       r6, 0x2DA8(r13)
	  divwu     r3, r7, r4
	  subi      r0, r6, 0x1
	  stw       r0, 0x2DA8(r13)
	  li        r6, 0x2
	  rlwinm    r0,r7,19,0,12
	  mullw     r3, r3, r4
	  sub       r3, r7, r3
	  rlwinm    r3,r3,4,0,27
	  add       r3, r5, r3
	  stb       r6, 0x4(r3)
	  stw       r0, 0x8(r3)
	  lwz       r0, 0x2D84(r13)
	  stw       r0, 0xC(r3)
	  lwz       r3, 0x2D6C(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2D6C(r13)
	  bl        -0x180
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001DE20
 * Size:	000198
 */
static void __VirtualLoad(u32, u32, u8*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x803E
	  stw       r0, 0x4(r1)
	  lis       r7, 0x8039
	  subi      r6, r6, 0x3320
	  stwu      r1, -0x40(r1)
	  stmw      r23, 0x1C(r1)
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  li        r4, 0x3
	  subi      r30, r7, 0x56C0
	  add       r0, r3, r26
	  li        r28, 0
	  li        r5, 0
	  mtctr     r4

	.loc_0x3C:
	  add       r7, r6, r5
	  addi      r9, r7, 0x4
	  lbz       r4, 0x4(r7)
	  cmplwi    r4, 0x2
	  bne-      .loc_0x158
	  lwz       r8, 0x8(r7)
	  cmplw     r8, r3
	  bgt-      .loc_0x144
	  lwz       r4, 0xC(r7)
	  add       r4, r8, r4
	  cmplw     r4, r3
	  ble-      .loc_0x144
	  cmplw     r4, r0
	  ble-      .loc_0xA8
	  lis       r4, 0x803E
	  rlwinm    r6,r28,2,0,29
	  subi      r0, r4, 0x3320
	  add       r6, r30, r6
	  add       r4, r0, r5
	  lwz       r6, 0x40(r6)
	  lwz       r0, 0x8(r4)
	  addi      r4, r27, 0
	  addi      r5, r26, 0
	  sub       r0, r3, r0
	  add       r3, r6, r0
	  bl        -0x17F40
	  b         .loc_0x164

	.loc_0xA8:
	  addi      r7, r28, 0x1
	  li        r31, 0x3
	  divwu     r4, r7, r31
	  mullw     r4, r4, r31
	  sub       r29, r7, r4
	  rlwinm    r4,r29,4,0,27
	  add       r4, r6, r4
	  lbz       r4, 0x4(r4)
	  cmplwi    r4, 0x2
	  bne-      .loc_0x130
	  lis       r6, 0x803E
	  rlwinm    r4,r28,2,0,29
	  subi      r6, r6, 0x3320
	  add       r4, r30, r4
	  add       r25, r6, r5
	  lwz       r5, 0x40(r4)
	  lwz       r7, 0x8(r25)
	  mr        r4, r27
	  lwz       r6, 0xC(r25)
	  sub       r3, r3, r7
	  add       r6, r7, r6
	  add       r3, r5, r3
	  sub       r24, r0, r6
	  sub       r23, r26, r24
	  addi      r5, r23, 0
	  bl        -0x17FAC
	  rlwinm    r0,r29,2,0,29
	  addi      r5, r24, 0
	  add       r3, r30, r0
	  add       r4, r27, r23
	  lwz       r3, 0x40(r3)
	  bl        -0x17FC4
	  stb       r31, 0x4(r25)
	  b         .loc_0x164

	.loc_0x130:
	  lwz       r4, 0x2D68(r13)
	  cmpwi     r4, 0
	  beq-      .loc_0x158
	  li        r3, -0x1
	  b         .loc_0x184

	.loc_0x144:
	  addis     r4, r8, 0x8
	  cmplw     r4, r3
	  bgt-      .loc_0x158
	  li        r4, 0x3
	  stb       r4, 0x0(r9)

	.loc_0x158:
	  addi      r28, r28, 0x1
	  addi      r5, r5, 0x10
	  bdnz+     .loc_0x3C

	.loc_0x164:
	  cmplwi    r28, 0x3
	  bne-      .loc_0x180
	  li        r0, 0x3
	  mtctr     r0

	.loc_0x174:
	  bdnz-     .loc_0x174
	  li        r3, 0
	  b         .loc_0x184

	.loc_0x180:
	  mr        r3, r26

	.loc_0x184:
	  lmw       r23, 0x1C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001DFC0
 * Size:	000050
 */
static void InitAudio1(StreamHeader*, u8*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  addi      r4, r5, 0
	  bl        -0x3BC
	  addi      r8, r31, 0
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0x1
	  li        r7, 0
	  bl        -0x1EB8
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001E020
 * Size:	0003BC
 */
void Jac_HVQM_Init(const char* filepath, u8*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0x1
	  lis       r7, 0x8039
	  stwu      r1, -0x90(r1)
	  stmw      r26, 0x78(r1)
	  subi      r31, r7, 0x56C0
	  addi      r26, r4, 0
	  lis       r29, 0x4
	  stw       r3, 0x8(r1)
	  stw       r0, -0x7EBC(r13)
	  stw       r6, 0x70(r1)
	  b         .loc_0x48

	.loc_0x38:
	  stbx      r6, r26, r0
	  lwz       r3, 0x70(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x70(r1)

	.loc_0x48:
	  lwz       r0, 0x70(r1)
	  cmplw     r0, r5
	  blt+      .loc_0x38
	  lis       r0, 0x4
	  li        r6, 0
	  li        r3, 0x1
	  cmplw     r5, r0
	  stw       r6, 0x2D6C(r13)
	  stw       r6, 0x2DA8(r13)
	  stw       r6, 0x2DA0(r13)
	  stw       r3, 0x2D7C(r13)
	  stw       r3, 0x2DB0(r13)
	  stw       r6, 0x2D78(r13)
	  stw       r6, 0x2D74(r13)
	  blt-      .loc_0x3A8
	  subis     r3, r5, 0x4
	  lis       r0, 0x6
	  cmplw     r3, r0
	  addi      r28, r26, 0
	  blt-      .loc_0x3A8
	  addis     r3, r26, 0x4
	  li        r0, 0x3
	  stw       r3, 0x2DAC(r13)
	  subis     r27, r5, 0xA
	  addis     r26, r26, 0xA
	  lis       r4, 0x8
	  mtctr     r0

	.loc_0xB4:
	  cmplw     r27, r4
	  blt-      .loc_0x3A8
	  add       r3, r31, r6
	  subis     r27, r27, 0x8
	  stw       r26, 0x40(r3)
	  addis     r26, r26, 0x8
	  addi      r6, r6, 0x4
	  bdnz+     .loc_0xB4
	  lis       r3, 0x803E
	  li        r0, 0x3
	  subi      r5, r3, 0x3320
	  li        r3, 0
	  li        r6, 0x3
	  mtctr     r0

	.loc_0xEC:
	  add       r4, r5, r3
	  addi      r3, r3, 0x10
	  stb       r6, 0x4(r4)
	  bdnz+     .loc_0xEC
	  li        r0, 0
	  lwz       r30, 0x8(r1)
	  stw       r0, 0x2D70(r13)
	  mr        r3, r30
	  stw       r0, 0x2D68(r13)
	  bl        -0x162B0
	  lwz       r10, 0x2D6C(r13)
	  li        r5, 0x3
	  stw       r3, 0x2D88(r13)
	  addi      r4, r30, 0
	  divwu     r0, r10, r5
	  addi      r3, r10, 0
	  lwz       r7, 0x2D88(r13)
	  addi      r8, r1, 0x68
	  li        r6, 0
	  subis     r7, r7, 0x8
	  stw       r7, 0x2D88(r13)
	  lis       r7, 0x8
	  mullw     r0, r0, r5
	  li        r9, 0
	  sub       r0, r10, r0
	  rlwinm    r0,r0,2,0,29
	  add       r5, r31, r0
	  lwz       r5, 0x40(r5)
	  bl        -0x1687C

	.loc_0x160:
	  lwz       r0, 0x68(r1)
	  cmplwi    r0, 0
	  beq+      .loc_0x160
	  lis       r3, 0x803E
	  li        r0, 0
	  subi      r6, r3, 0x3320
	  li        r5, 0x2
	  stw       r0, 0x8(r6)
	  lis       r0, 0x8
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  stb       r5, 0x4(r6)
	  stw       r0, 0xC(r6)
	  lwz       r5, 0x2D6C(r13)
	  addi      r0, r5, 0x1
	  stw       r0, 0x2D6C(r13)
	  bl        0x1FB198
	  bl        -0x544
	  lwz       r3, 0x40(r31)
	  li        r0, 0x8
	  addi      r6, r31, 0x44
	  subi      r4, r3, 0x8
	  mtctr     r0

	.loc_0x1BC:
	  lwzu      r3, 0x8(r4)
	  lwz       r0, 0x4(r4)
	  stwu      r3, 0x8(r6)
	  stw       r0, 0x4(r6)
	  bdnz+     .loc_0x1BC
	  lwz       r5, 0x8(r4)
	  li        r4, 0
	  li        r0, -0x1
	  addi      r3, r31, 0x7C
	  stw       r5, 0x8(r6)
	  lwz       r5, 0x2D70(r13)
	  stw       r4, 0x2D98(r13)
	  addi      r5, r5, 0x44
	  stw       r5, 0x2D70(r13)
	  stw       r4, 0x2D9C(r13)
	  stw       r0, -0x7EC0(r13)
	  lbz       r0, 0x88(r31)
	  stw       r0, 0x38(r1)
	  lwz       r4, 0x8C(r31)
	  lwz       r0, 0x38(r1)
	  stw       r4, 0x3C(r1)
	  cmpwi     r0, 0x4
	  lwz       r4, 0x7C(r31)
	  stw       r4, 0x34(r1)
	  beq-      .loc_0x240
	  bge-      .loc_0x234
	  cmpwi     r0, 0x2
	  beq-      .loc_0x258
	  bge-      .loc_0x268
	  b         .loc_0x288

	.loc_0x234:
	  cmpwi     r0, 0x6
	  bge-      .loc_0x288
	  b         .loc_0x274

	.loc_0x240:
	  lwz       r5, 0x34(r1)
	  li        r4, 0x12
	  rlwinm    r5,r5,4,0,27
	  divwu     r4, r5, r4
	  stw       r4, 0x30(r1)
	  b         .loc_0x288

	.loc_0x258:
	  lwz       r4, 0x34(r1)
	  rlwinm    r4,r4,31,1,31
	  stw       r4, 0x30(r1)
	  b         .loc_0x288

	.loc_0x268:
	  lwz       r4, 0x34(r1)
	  stw       r4, 0x30(r1)
	  b         .loc_0x288

	.loc_0x274:
	  lwz       r5, 0x34(r1)
	  li        r4, 0x24
	  rlwinm    r5,r5,4,0,27
	  divwu     r4, r5, r4
	  stw       r4, 0x30(r1)

	.loc_0x288:
	  li        r10, 0
	  li        r7, 0x10
	  stw       r10, 0x0(r3)
	  li        r6, 0x1E
	  li        r3, 0x4
	  addi      r5, r1, 0x40
	  lwz       r9, 0x34(r1)
	  li        r4, 0
	  lwz       r8, 0x3C(r1)
	  stw       r9, 0x40(r1)
	  lwz       r9, 0x30(r1)
	  stw       r9, 0x44(r1)
	  sth       r8, 0x48(r1)
	  sth       r0, 0x4A(r1)
	  sth       r7, 0x4C(r1)
	  sth       r6, 0x4E(r1)
	  mtctr     r3

	.loc_0x2CC:
	  addi      r0, r4, 0x10
	  addi      r4, r4, 0x4
	  stwx      r10, r5, r0
	  bdnz+     .loc_0x2CC
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x40
	  bl        -0x348
	  stw       r26, 0x2DA4(r13)
	  addi      r26, r26, 0x20
	  subi      r27, r27, 0x20
	  bl        0x53D4
	  lwz       r3, 0x2DA4(r13)
	  addi      r4, r31, 0x80
	  bl        0x53E8
	  lwz       r3, 0x2DA4(r13)
	  bl        0x5404
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  cmplw     r27, r0
	  blt-      .loc_0x3A8
	  lwz       r3, 0x2DA4(r13)
	  mr        r4, r26
	  add       r26, r26, r0
	  sub       r27, r27, r0
	  bl        0x5454
	  lis       r5, 0x7
	  lis       r4, 0x803E
	  lis       r3, 0x1234
	  li        r0, 0x18
	  addi      r6, r5, 0x800
	  subi      r5, r4, 0x34D0
	  addi      r4, r3, 0x5678
	  li        r8, 0
	  li        r3, 0
	  mtctr     r0

	.loc_0x35C:
	  cmplw     r27, r6
	  blt-      .loc_0x38C
	  add       r7, r5, r3
	  subis     r27, r27, 0x7
	  stw       r26, 0x0(r7)
	  addis     r26, r26, 0x7
	  addi      r8, r8, 0x1
	  addi      r3, r3, 0x10
	  stw       r4, 0xC(r7)
	  addi      r26, r26, 0x800
	  subi      r27, r27, 0x800
	  bdnz+     .loc_0x35C

	.loc_0x38C:
	  stw       r8, 0x2D80(r13)
	  bl        0x6F0
	  bl        -0x17834
	  mr        r26, r3

	.loc_0x39C:
	  bl        -0x1783C
	  cmplw     r26, r3
	  beq+      .loc_0x39C

	.loc_0x3A8:
	  lmw       r26, 0x78(r1)
	  lwz       r0, 0x94(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void hvqm_proc(void*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void OSInitFastCast(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001E3E0
 * Size:	000050
 */
static void hvqm_forcestop()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  lwz       r0, -0x7EB8(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x3C
	  lis       r3, 0x8039
	  subi      r31, r3, 0x5618
	  addi      r3, r31, 0
	  bl        0x1DD6E8
	  cmpwi     r3, 0
	  bne-      .loc_0x3C
	  mr        r3, r31
	  bl        0x1DDEB0

	.loc_0x3C:
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void Jac_HVQM_ThreadStart(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001E440
 * Size:	000394
 */
void Jac_HVQM_Update(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8039
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r24, 0x10(r1)
	  subi      r31, r4, 0x56C0
	  addi      r30, r31, 0x64
	  lwz       r3, 0x2D9C(r13)
	  lwz       r0, 0x64(r31)
	  lwz       r29, 0x2DAC(r13)
	  cmplw     r3, r0
	  bne-      .loc_0x38
	  li        r3, 0x1
	  b         .loc_0x380

	.loc_0x38:
	  lis       r4, 0x803E
	  lis       r3, 0x8
	  subi      r25, r4, 0x3320
	  subi      r26, r3, 0x5EE0
	  li        r28, 0

	.loc_0x4C:
	  lwz       r0, -0x7EC0(r13)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x90
	  lwz       r3, 0x2D70(r13)
	  addi      r5, r31, 0x90
	  li        r4, 0x14
	  bl        -0x684
	  cmpwi     r3, 0
	  bne-      .loc_0x78
	  li        r3, 0
	  b         .loc_0x380

	.loc_0x78:
	  lwz       r4, 0x2D70(r13)
	  lwz       r3, -0x7EC0(r13)
	  addi      r4, r4, 0x14
	  addi      r0, r3, 0x1
	  stw       r4, 0x2D70(r13)
	  stw       r0, -0x7EC0(r13)

	.loc_0x90:
	  lwz       r0, 0x2DB0(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0xC8
	  lwz       r3, 0x2D70(r13)
	  li        r4, 0x8
	  addi      r5, r13, 0x2D8C
	  bl        -0x6C8
	  cmpwi     r3, 0
	  bne-      .loc_0xBC
	  li        r3, 0
	  b         .loc_0x380

	.loc_0xBC:
	  lwz       r3, 0x2D70(r13)
	  addi      r0, r3, 0x8
	  stw       r0, 0x2D70(r13)

	.loc_0xC8:
	  lhz       r0, 0x2D8C(r13)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x158
	  bge-      .loc_0xE0
	  cmpwi     r0, 0
	  bge-      .loc_0xE8

	.loc_0xE0:
	  li        r3, -0x1
	  b         .loc_0x380

	.loc_0xE8:
	  addi      r24, r13, 0x2D8C
	  lwzu      r3, 0x4(r24)
	  bl        -0xA10
	  cmpwi     r3, 0
	  bne-      .loc_0x108
	  li        r0, 0
	  stw       r0, 0x2DB0(r13)
	  b         .loc_0x310

	.loc_0x108:
	  lwz       r3, 0x2D70(r13)
	  mr        r5, r29
	  lwz       r4, 0x0(r24)
	  bl        -0x734
	  cmpwi     r3, 0
	  bne-      .loc_0x130
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x2DB0(r13)
	  b         .loc_0x380

	.loc_0x130:
	  mr        r3, r29
	  lwz       r4, 0x0(r24)
	  bl        -0xAF8
	  li        r0, 0x1
	  lwz       r3, 0x2D70(r13)
	  stw       r0, 0x2DB0(r13)
	  lwz       r0, 0x0(r24)
	  add       r0, r3, r0
	  stw       r0, 0x2D70(r13)
	  b         .loc_0x310

	.loc_0x158:
	  lwz       r0, -0x7EBC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x1B4
	  lwz       r3, 0x2D78(r13)
	  lwz       r0, 0x2D80(r13)
	  cmplw     r3, r0
	  bne-      .loc_0x1B4
	  li        r3, 0
	  bl        -0x1278
	  cmpwi     r3, 0
	  beq-      .loc_0x1A4
	  lfs       f1, -0x7DE0(r2)
	  li        r3, 0
	  li        r4, 0x3FFF
	  li        r5, 0x3FFF
	  bl        -0x1194
	  li        r0, 0
	  stw       r0, -0x7EBC(r13)
	  b         .loc_0x1B4

	.loc_0x1A4:
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x2DB0(r13)
	  b         .loc_0x380

	.loc_0x1B4:
	  lwz       r0, 0x2DA0(r13)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x20C
	  bge-      .loc_0x1D0
	  cmpwi     r0, 0
	  bge-      .loc_0x1DC
	  b         .loc_0x274

	.loc_0x1D0:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x274
	  b         .loc_0x248

	.loc_0x1DC:
	  lwz       r3, 0x2D70(r13)
	  li        r4, 0x4
	  addi      r5, r13, 0x2D94
	  bl        -0x808
	  cmpwi     r3, 0
	  bne-      .loc_0x200
	  li        r0, 0
	  stw       r0, 0x2DB0(r13)
	  b         .loc_0x37C

	.loc_0x200:
	  lwz       r3, 0x2DA0(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2DA0(r13)

	.loc_0x20C:
	  addi      r3, r13, 0x2D8C
	  lwz       r6, 0x2D70(r13)
	  lwz       r4, 0x4(r3)
	  addi      r5, r29, 0
	  addi      r3, r6, 0x4
	  subi      r4, r4, 0x4
	  bl        -0x844
	  cmpwi     r3, 0
	  bne-      .loc_0x23C
	  li        r0, 0
	  stw       r0, 0x2DB0(r13)
	  b         .loc_0x37C

	.loc_0x23C:
	  lwz       r3, 0x2DA0(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2DA0(r13)

	.loc_0x248:
	  lwz       r3, 0x2D94(r13)
	  lwz       r0, 0x2D98(r13)
	  add       r3, r3, r0
	  bl        0x44C
	  cmpwi     r3, 0
	  bne-      .loc_0x26C
	  li        r0, 0
	  stw       r0, 0x2DB0(r13)
	  b         .loc_0x37C

	.loc_0x26C:
	  li        r0, 0
	  stw       r0, 0x2DA0(r13)

	.loc_0x274:
	  li        r0, 0x1
	  addi      r24, r13, 0x2D8C
	  stw       r0, 0x2DB0(r13)
	  lwz       r3, 0x2D70(r13)
	  lwz       r0, 0x4(r24)
	  add       r0, r3, r0
	  stw       r0, 0x2D70(r13)
	  bl        0x1DECD0
	  lhz       r0, 0x2(r24)
	  mr        r24, r4
	  lwz       r6, 0x2D94(r13)
	  mr        r3, r29
	  lwz       r4, 0x2D98(r13)
	  rlwinm    r5,r0,0,24,31
	  add       r4, r6, r4
	  bl        0x450
	  mr        r27, r3
	  bl        0x1DECA8
	  cmplwi    r27, 0x1
	  subc      r27, r4, r24
	  bgt-      .loc_0x310
	  lwz       r4, 0x2D78(r13)
	  lwz       r3, -0x7EC0(r13)
	  addi      r4, r4, 0x1
	  addi      r0, r3, 0x1
	  stw       r4, 0x2D78(r13)
	  stw       r0, -0x7EC0(r13)
	  lwz       r5, -0x7EC0(r13)
	  lwz       r0, 0x98(r31)
	  cmplw     r5, r0
	  bne-      .loc_0x310
	  lwz       r4, 0x2D98(r13)
	  li        r0, -0x1
	  lwz       r3, 0x2D9C(r13)
	  add       r4, r4, r5
	  stw       r0, -0x7EC0(r13)
	  addi      r0, r3, 0x1
	  stw       r4, 0x2D98(r13)
	  stw       r0, 0x2D9C(r13)

	.loc_0x310:
	  lwz       r3, 0x2D9C(r13)
	  lwz       r0, 0x0(r30)
	  cmplw     r3, r0
	  bne-      .loc_0x328
	  li        r3, 0x1
	  b         .loc_0x380

	.loc_0x328:
	  li        r0, 0x3
	  li        r3, 0
	  mtctr     r0

	.loc_0x334:
	  add       r4, r25, r3
	  lbz       r0, 0x4(r4)
	  cmplwi    r0, 0x3
	  bne-      .loc_0x34C
	  bl        -0xB04
	  b         .loc_0x354

	.loc_0x34C:
	  addi      r3, r3, 0x10
	  bdnz+     .loc_0x334

	.loc_0x354:
	  cmplwi    r28, 0
	  bne-      .loc_0x370
	  cmpw      r27, r26
	  blt-      .loc_0x370
	  lwz       r0, 0x2D7C(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x37C

	.loc_0x370:
	  addi      r28, r28, 0x1
	  cmplwi    r28, 0x2
	  blt+      .loc_0x4C

	.loc_0x37C:
	  li        r3, 0

	.loc_0x380:
	  lmw       r24, 0x10(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001E7E0
 * Size:	000074
 */
void Jac_HVQM_ForceStop(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8039
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x5674
	  li        r3, 0
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x18(r4)
	  stw       r0, 0x2D9C(r13)
	  bl        -0x1360
	  bl        0x1DA778
	  lwz       r0, 0x2D68(r13)
	  li        r4, 0
	  stw       r4, 0x2D88(r13)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5C
	  lwz       r0, 0x2DA8(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x5C
	  bl        0x1DA77C

	.loc_0x4C:
	  lwz       r0, 0x2D68(r13)
	  cmpwi     r0, 0x1
	  bne+      .loc_0x4C
	  b         .loc_0x60

	.loc_0x5C:
	  bl        0x1DA768

	.loc_0x60:
	  bl        -0x460
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void Jac_CountReadyPictures(void)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8001E860
 * Size:	000228
 */
int Jac_GetPicture(void*, int*, int*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x8039
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r28, 0x18(r1)
	  subi      r31, r6, 0x56C0
	  addi      r28, r3, 0
	  li        r30, 0
	  li        r29, -0x1
	  lhz       r0, 0x80(r31)
	  stw       r0, 0x0(r4)
	  lhz       r0, 0x82(r31)
	  stw       r0, 0x0(r5)
	  lwz       r0, -0x7EBC(r13)
	  cmpwi     r0, 0
	  beq-      .loc_0x50
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x0(r28)
	  b         .loc_0x214

	.loc_0x50:
	  li        r3, 0
	  li        r4, 0x2
	  bl        -0x1138
	  cmpwi     r3, -0x1
	  bne-      .loc_0x78
	  bl        -0x4E4
	  li        r0, 0
	  li        r3, -0x1
	  stw       r0, 0x0(r28)
	  b         .loc_0x214

	.loc_0x78:
	  lwz       r10, 0x2D80(r13)
	  li        r4, 0
	  lis       r6, 0x803E
	  addi      r5, r4, 0
	  addi      r0, r4, 0
	  stw       r3, 0x2D74(r13)
	  subi      r6, r6, 0x34D0
	  li        r11, 0
	  mtctr     r10
	  cmplwi    r10, 0
	  ble-      .loc_0xF4

	.loc_0xA4:
	  add       r7, r6, r4
	  addi      r8, r7, 0x8
	  lwz       r9, 0x8(r7)
	  cmplwi    r9, 0
	  beq-      .loc_0xE8
	  lwz       r7, 0x4(r7)
	  cmplw     r7, r3
	  bgt-      .loc_0xDC
	  cmplw     r30, r7
	  bge-      .loc_0xD4
	  addi      r30, r7, 0
	  addi      r29, r11, 0

	.loc_0xD4:
	  stw       r5, 0x0(r8)
	  b         .loc_0xE8

	.loc_0xDC:
	  cmplwi    r9, 0x2
	  bne-      .loc_0xE8
	  stw       r0, 0x0(r8)

	.loc_0xE8:
	  addi      r11, r11, 0x1
	  addi      r4, r4, 0x10
	  bdnz+     .loc_0xA4

	.loc_0xF4:
	  cmpwi     r29, -0x1
	  beq-      .loc_0x114
	  lis       r4, 0x803E
	  rlwinm    r0,r29,4,0,27
	  subi      r4, r4, 0x34D0
	  li        r5, 0x2
	  add       r4, r4, r0
	  stw       r5, 0x8(r4)

	.loc_0x114:
	  lis       r4, 0x803E
	  li        r8, 0
	  subi      r5, r4, 0x34D0
	  li        r4, 0
	  mtctr     r10
	  cmplwi    r10, 0
	  ble-      .loc_0x1B0

	.loc_0x130:
	  add       r7, r5, r4
	  lwz       r0, 0x8(r7)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A4
	  lwz       r0, 0x4(r7)
	  cmplw     r3, r0
	  bne-      .loc_0x1A4
	  lis       r5, 0x803E
	  li        r0, 0x2
	  subi      r6, r5, 0x34D0
	  cmpwi     r29, -0x1
	  add       r4, r6, r4
	  li        r5, 0
	  stw       r0, 0x8(r4)
	  lwz       r0, 0x0(r7)
	  stw       r0, 0x0(r28)
	  stw       r5, 0x2D7C(r13)
	  beq-      .loc_0x18C
	  cmplw     r29, r8
	  beq-      .loc_0x18C
	  rlwinm    r0,r29,4,0,27
	  add       r4, r6, r0
	  stw       r5, 0x8(r4)

	.loc_0x18C:
	  cmpwi     r3, 0x3
	  bge-      .loc_0x19C
	  li        r0, 0
	  stw       r0, 0x0(r28)

	.loc_0x19C:
	  addi      r3, r3, 0x1
	  b         .loc_0x214

	.loc_0x1A4:
	  addi      r8, r8, 0x1
	  addi      r4, r4, 0x10
	  bdnz+     .loc_0x130

	.loc_0x1B0:
	  li        r0, 0x1
	  cmpwi     r29, -0x1
	  stw       r0, 0x2D7C(r13)
	  beq-      .loc_0x1F0
	  lis       r4, 0x803E
	  rlwinm    r5,r29,4,0,27
	  subi      r0, r4, 0x34D0
	  cmpwi     r3, 0x3
	  add       r3, r0, r5
	  lwz       r0, 0x0(r3)
	  stw       r0, 0x0(r28)
	  bge-      .loc_0x1E8
	  li        r0, 0
	  stw       r0, 0x0(r28)

	.loc_0x1E8:
	  addi      r3, r30, 0x1
	  b         .loc_0x214

	.loc_0x1F0:
	  lwz       r3, 0x2D9C(r13)
	  lwz       r0, 0x64(r31)
	  cmplw     r3, r0
	  bne-      .loc_0x208
	  li        r3, 0
	  bl        -0x15C4

	.loc_0x208:
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x0(r28)

	.loc_0x214:
	  lmw       r28, 0x18(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001EAA0
 * Size:	000040
 */
static void InitPic()
{
	/*
	.loc_0x0:
	  lwz       r6, 0x2D80(r13)
	  li        r5, 0
	  lis       r4, 0x803E
	  addi      r3, r5, 0
	  stw       r5, 0x2DB4(r13)
	  subi      r0, r4, 0x34D0
	  stw       r5, 0x2DB8(r13)
	  mtctr     r6
	  cmplwi    r6, 0
	  blelr-

	.loc_0x28:
	  add       r4, r0, r3
	  addi      r3, r3, 0x10
	  stw       r5, 0x4(r4)
	  stw       r5, 0x8(r4)
	  bdnz+     .loc_0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001EAE0
 * Size:	000044
 */
static void CheckDraw(u32)
{
	/*
	.loc_0x0:
	  lis       r5, 0x803E
	  lwz       r4, 0x2D80(r13)
	  subi      r5, r5, 0x34D0
	  lwz       r0, 0x4(r5)
	  sub       r3, r3, r0
	  divwu     r0, r3, r4
	  mullw     r0, r0, r4
	  sub       r0, r3, r0
	  rlwinm    r0,r0,4,0,27
	  add       r3, r5, r0
	  lwz       r0, 0x8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x3C
	  li        r3, 0
	  blr

	.loc_0x3C:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8001EB40
 * Size:	0000FC
 */
static void Decode1(u8*, u32, u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x803E
	  stw       r0, 0x4(r1)
	  subi      r7, r6, 0x34D0
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r31, r4, 0
	  addi      r4, r3, 0
	  addi      r29, r7, 0x4
	  lwz       r0, 0x4(r7)
	  lwz       r6, 0x2D80(r13)
	  sub       r3, r31, r0
	  divwu     r0, r3, r6
	  mullw     r0, r0, r6
	  sub       r0, r3, r0
	  rlwinm    r30,r0,4,0,27
	  add       r3, r7, r30
	  lwz       r0, 0x8(r3)
	  addi      r28, r3, 0x8
	  lwz       r27, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  li        r3, -0x1
	  b         .loc_0xE8

	.loc_0x60:
	  rlwinm    r0,r5,0,24,31
	  cmpwi     r0, 0x20
	  beq-      .loc_0xA4
	  bge-      .loc_0x7C
	  cmpwi     r0, 0x10
	  beq-      .loc_0x88
	  b         .loc_0xD8

	.loc_0x7C:
	  cmpwi     r0, 0x30
	  beq-      .loc_0xC4
	  b         .loc_0xD8

	.loc_0x88:
	  lwz       r3, 0x2DA4(r13)
	  mr        r5, r27
	  bl        0x5038
	  lwz       r0, 0x2DB4(r13)
	  stw       r0, 0x2DB8(r13)
	  stw       r27, 0x2DB4(r13)
	  b         .loc_0xD8

	.loc_0xA4:
	  lwz       r3, 0x2DA4(r13)
	  mr        r5, r27
	  lwz       r6, 0x2DB4(r13)
	  bl        0x5528
	  lwz       r0, 0x2DB4(r13)
	  stw       r0, 0x2DB8(r13)
	  stw       r27, 0x2DB4(r13)
	  b         .loc_0xD8

	.loc_0xC4:
	  lwz       r3, 0x2DA4(r13)
	  mr        r5, r27
	  lwz       r6, 0x2DB8(r13)
	  lwz       r7, 0x2DB4(r13)
	  bl        0x5528

	.loc_0xD8:
	  stwx      r31, r29, r30
	  li        r0, 0x1
	  li        r3, 0
	  stw       r0, 0x0(r28)

	.loc_0xE8:
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}
