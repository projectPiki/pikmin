#include "types.h"

typedef struct dspch_ dspch_;

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GetDSPchannelHandle(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000AD00
 * Size:	000060
 */
void InitDSPchannel()
{
	/*
	.loc_0x0:
	  li        r3, 0
	  lis       r10, 0x8030
	  li        r0, 0x40
	  addi      r9, r3, 0
	  addi      r8, r3, 0
	  addi      r7, r3, 0
	  addi      r6, r3, 0
	  addi      r5, r3, 0
	  addi      r4, r3, 0
	  addi      r10, r10, 0x6660
	  li        r12, 0
	  mtctr     r0

	.loc_0x30:
	  add       r11, r10, r3
	  addi      r3, r3, 0x10
	  stb       r12, 0x0(r11)
	  addi      r12, r12, 0x1
	  stb       r9, 0x1(r11)
	  stw       r8, 0x8(r11)
	  sth       r7, 0x6(r11)
	  stw       r6, 0xC(r11)
	  stb       r5, 0x3(r11)
	  sth       r4, 0x4(r11)
	  bdnz+     .loc_0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AD60
 * Size:	000114
 */
void AllocDSPchannel(u32, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmplwi    r3, 0
	  stw       r0, 0x4(r1)
	  lis       r3, 0x8030
	  stwu      r1, -0x28(r1)
	  stmw      r30, 0x20(r1)
	  addi      r31, r3, 0x6660
	  stw       r4, 0xC(r1)
	  bne-      .loc_0x88
	  li        r0, 0
	  stw       r0, 0x1C(r1)
	  b         .loc_0x74

	.loc_0x30:
	  lwz       r3, 0x1C(r1)
	  rlwinm    r0,r3,4,0,27
	  add       r30, r31, r0
	  lbz       r0, 0x1(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x6C
	  li        r4, 0x1
	  rlwinm    r3,r3,0,24,31
	  stb       r4, 0x1(r30)
	  lwz       r0, 0xC(r1)
	  stw       r0, 0x8(r30)
	  stb       r4, 0x3(r30)
	  bl        0xA80
	  mr        r3, r30
	  b         .loc_0x100

	.loc_0x6C:
	  addi      r0, r3, 0x1
	  stw       r0, 0x1C(r1)

	.loc_0x74:
	  lwz       r0, 0x1C(r1)
	  cmpwi     r0, 0x40
	  blt+      .loc_0x30
	  li        r3, 0
	  b         .loc_0x100

	.loc_0x88:
	  li        r0, 0x20
	  li        r30, 0x1
	  li        r3, 0x10
	  mtctr     r0

	.loc_0x98:
	  add       r4, r31, r3
	  lbz       r0, 0x1(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0xF0
	  lbz       r0, -0xF(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0xF0
	  li        r3, 0x3
	  li        r0, 0x2
	  stb       r3, 0x1(r4)
	  rlwinm    r3,r30,0,24,31
	  stb       r0, -0xF(r4)
	  lwz       r0, 0xC(r1)
	  stw       r0, 0x8(r4)
	  stw       r0, -0x8(r4)
	  bl        0xA0C
	  subi      r30, r30, 0x1
	  rlwinm    r3,r30,0,24,31
	  bl        0xA00
	  rlwinm    r0,r30,4,0,27
	  add       r3, r31, r0
	  b         .loc_0x100

	.loc_0xF0:
	  addi      r30, r30, 0x2
	  addi      r3, r3, 0x20
	  bdnz+     .loc_0x98
	  li        r3, 0

	.loc_0x100:
	  lwz       r0, 0x2C(r1)
	  lmw       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AE80
 * Size:	0000DC
 */
void DeAllocDSPchannel(dspch_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr.       r31, r3
	  bne-      .loc_0x20
	  li        r3, -0x1
	  b         .loc_0xC8

	.loc_0x20:
	  lwz       r0, 0x8(r31)
	  cmplw     r0, r4
	  beq-      .loc_0x34
	  li        r3, -0x2
	  b         .loc_0xC8

	.loc_0x34:
	  lbz       r0, 0x1(r31)
	  cmpwi     r0, 0x3
	  beq-      .loc_0x90
	  bge-      .loc_0x54
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5C
	  bge-      .loc_0x68
	  b         .loc_0xB4

	.loc_0x54:
	  cmpwi     r0, 0x5
	  bge-      .loc_0xB4

	.loc_0x5C:
	  li        r0, 0
	  stb       r0, 0x1(r31)
	  b         .loc_0xB4

	.loc_0x68:
	  li        r0, 0
	  lis       r3, 0x8030
	  stb       r0, 0x1(r31)
	  addi      r0, r3, 0x6660
	  lbz       r3, 0x0(r31)
	  addi      r3, r3, 0x1
	  rlwinm    r3,r3,4,0,27
	  add       r3, r0, r3
	  bl        .loc_0x0
	  b         .loc_0xB4

	.loc_0x90:
	  li        r0, 0
	  lis       r3, 0x8030
	  stb       r0, 0x1(r31)
	  addi      r0, r3, 0x6660
	  lbz       r3, 0x0(r31)
	  subi      r3, r3, 0x1
	  rlwinm    r3,r3,4,0,27
	  add       r3, r0, r3
	  bl        .loc_0x0

	.loc_0xB4:
	  li        r0, 0
	  li        r3, 0
	  stb       r0, 0x3(r31)
	  stw       r0, 0xC(r31)
	  stw       r0, 0x8(r31)

	.loc_0xC8:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AF60
 * Size:	000104
 */
void GetLowerDSPchannel()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0xFF
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  lis       r4, 0x8030
	  stwu      r1, -0x48(r1)
	  stmw      r27, 0x34(r1)
	  addi      r31, r4, 0x6660
	  stb       r3, 0x2C(r1)
	  stw       r0, 0x28(r1)
	  stw       r0, 0x24(r1)
	  stw       r0, 0x20(r1)
	  b         .loc_0xD8

	.loc_0x34:
	  rlwinm    r0,r30,4,0,27
	  add       r29, r31, r0
	  lbz       r0, 0x1(r29)
	  cmplwi    r0, 0x4
	  beq-      .loc_0xCC
	  cmplwi    r0, 0
	  bne-      .loc_0x60
	  li        r0, 0
	  stb       r0, 0x3(r29)
	  stw       r30, 0x28(r1)
	  b         .loc_0xE4

	.loc_0x60:
	  lwz       r0, 0xC(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  lbz       r3, 0x0(r29)
	  bl        0x590
	  addi      r28, r29, 0x3
	  lbz       r27, 0x2C(r1)
	  lbz       r0, 0x3(r29)
	  cmplw     r0, r27
	  bgt-      .loc_0xCC
	  lbz       r3, 0x0(r29)
	  bl        0x574
	  lbz       r5, 0x0(r28)
	  cmplw     r27, r5
	  bne-      .loc_0xBC
	  lwz       r0, 0x24(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xCC
	  lwz       r4, 0x10C(r3)
	  cmplw     r4, r0
	  bge-      .loc_0xBC
	  cmplwi    r4, 0
	  bne-      .loc_0xCC

	.loc_0xBC:
	  lwz       r0, 0x10C(r3)
	  stw       r0, 0x24(r1)
	  stw       r30, 0x28(r1)
	  stb       r5, 0x2C(r1)

	.loc_0xCC:
	  lwz       r3, 0x20(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x20(r1)

	.loc_0xD8:
	  lwz       r30, 0x20(r1)
	  cmplwi    r30, 0x40
	  blt+      .loc_0x34

	.loc_0xE4:
	  lwz       r0, 0x28(r1)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r31, r0
	  lwz       r0, 0x4C(r1)
	  lmw       r27, 0x34(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B080
 * Size:	0000D8
 */
void GetLowerActiveDSPchannel()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8030
	  stw       r0, 0x4(r1)
	  li        r0, 0xFF
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  li        r30, 0
	  addi      r31, r3, 0x6660
	  li        r27, 0
	  stb       r0, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r30, 0x14(r1)

	.loc_0x30:
	  add       r3, r31, r30
	  lbz       r0, 0x1(r3)
	  cmplwi    r0, 0x4
	  beq-      .loc_0xA0
	  cmplwi    r0, 0
	  beq-      .loc_0xA0
	  addi      r29, r3, 0x3
	  lbz       r28, 0x1C(r1)
	  lbz       r0, 0x3(r3)
	  cmplw     r0, r28
	  bgt-      .loc_0xA0
	  lbz       r3, 0x0(r3)
	  bl        0x480
	  lbz       r5, 0x0(r29)
	  cmplw     r28, r5
	  bne-      .loc_0x90
	  lwz       r0, 0x14(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0xA0
	  lwz       r4, 0x10C(r3)
	  cmplw     r4, r0
	  bge-      .loc_0x90
	  cmplwi    r4, 0
	  bne-      .loc_0xA0

	.loc_0x90:
	  lwz       r0, 0x10C(r3)
	  stw       r0, 0x14(r1)
	  stw       r27, 0x18(r1)
	  stb       r5, 0x1C(r1)

	.loc_0xA0:
	  addi      r27, r27, 0x1
	  addi      r30, r30, 0x10
	  cmplwi    r27, 0x40
	  blt+      .loc_0x30
	  lmw       r27, 0x24(r1)
	  lis       r3, 0x8030
	  lwz       r4, 0x18(r1)
	  addi      r0, r3, 0x6660
	  rlwinm    r3,r4,4,0,27
	  add       r3, r0, r3
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B160
 * Size:	00007C
 */
void ForceStopDSPchannel(dspch_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  stw       r3, 0x8(r1)
	  lwz       r31, 0x8(r1)
	  lbz       r0, 0x1(r31)
	  addi      r30, r31, 0x1
	  cmplwi    r0, 0x4
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x68

	.loc_0x30:
	  lbz       r3, 0x0(r31)
	  bl        0x3CC
	  lhz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x68

	.loc_0x4C:
	  li        r4, 0x1
	  li        r0, 0x4
	  sth       r4, 0x10A(r3)
	  stb       r0, 0x0(r30)
	  lbz       r3, 0x0(r31)
	  bl        0x960
	  li        r3, 0x1

	.loc_0x68:
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B1E0
 * Size:	0000AC
 */
void BreakLowerDSPchannel(u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stb       r3, 0x8(r1)
	  bl        -0x294
	  mr        r31, r3
	  lbz       r0, 0x8(r1)
	  lbz       r3, 0x3(r3)
	  cmplw     r3, r0
	  ble-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x98

	.loc_0x34:
	  bne-      .loc_0x40
	  lbz       r3, 0x0(r31)
	  bl        0x344

	.loc_0x40:
	  lbz       r0, 0x1(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  lwz       r12, 0xC(r31)
	  cmplwi    r12, 0
	  beq-      .loc_0x80
	  addi      r3, r31, 0
	  li        r4, 0x3
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,16,31
	  addi      r3, r31, 0
	  sth       r0, 0x6(r31)
	  bl        -0xF4
	  li        r0, 0x4
	  stb       r0, 0x1(r31)

	.loc_0x80:
	  mr        r3, r31
	  bl        -0x104
	  b         .loc_0x94

	.loc_0x8C:
	  li        r3, 0
	  b         .loc_0x98

	.loc_0x94:
	  li        r3, 0x1

	.loc_0x98:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000B2A0
 * Size:	0000AC
 */
void BreakLowerActiveDSPchannel(u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stb       r3, 0x8(r1)
	  bl        -0x234
	  mr        r31, r3
	  lbz       r0, 0x8(r1)
	  lbz       r3, 0x3(r3)
	  cmplw     r3, r0
	  ble-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x98

	.loc_0x34:
	  bne-      .loc_0x40
	  lbz       r3, 0x0(r31)
	  bl        0x284

	.loc_0x40:
	  lbz       r0, 0x1(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  lwz       r12, 0xC(r31)
	  cmplwi    r12, 0
	  beq-      .loc_0x80
	  addi      r3, r31, 0
	  li        r4, 0x3
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,16,31
	  addi      r3, r31, 0
	  sth       r0, 0x6(r31)
	  bl        -0x1B4
	  li        r0, 0x4
	  stb       r0, 0x1(r31)

	.loc_0x80:
	  mr        r3, r31
	  bl        -0x1C4
	  b         .loc_0x94

	.loc_0x8C:
	  li        r3, 0
	  b         .loc_0x98

	.loc_0x94:
	  li        r3, 0x1

	.loc_0x98:
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
 * Size:	000008
 */
void UpdateDSPchannel(dspch_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000B360
 * Size:	0001F4
 */
void UpdateDSPchannelAll()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stmw      r26, 0x48(r1)
	  bl        0x1F2048
	  lwz       r0, 0x2BE0(r13)
	  stw       r3, 0x2BE0(r13)
	  sub       r26, r3, r0
	  bl        -0x50A0
	  lwz       r0, -0x7FFC(r13)
	  lis       r4, 0x8022
	  addi      r4, r4, 0x4978
	  sub.      r3, r0, r3
	  rlwinm    r0,r3,2,0,29
	  add       r3, r4, r0
	  stw       r26, 0x0(r3)
	  beq-      .loc_0x88
	  lwz       r3, 0x0(r4)
	  lis       r0, 0x4330
	  stw       r26, 0x3C(r1)
	  lfd       f3, -0x7FA0(r2)
	  stw       r3, 0x44(r1)
	  lfs       f0, -0x7FA8(r2)
	  stw       r0, 0x40(r1)
	  stw       r0, 0x38(r1)
	  lfd       f2, 0x40(r1)
	  lfd       f1, 0x38(r1)
	  fsubs     f2, f2, f3
	  fsubs     f1, f1, f3
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x88
	  li        r3, 0x7E
	  bl        -0x144

	.loc_0x88:
	  lis       r3, 0x8030
	  li        r28, 0
	  addi      r30, r3, 0x6660
	  li        r27, 0

	.loc_0x98:
	  add       r0, r30, r27
	  stw       r0, 0x30(r1)
	  lwz       r29, 0x30(r1)
	  addi      r26, r29, 0x1
	  lbz       r0, 0x1(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C8
	  lbz       r3, 0x0(r29)
	  bl        0x148
	  mr        r31, r3
	  lhz       r0, 0x2(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x10C
	  lwz       r12, 0xC(r29)
	  cmplwi    r12, 0
	  beq-      .loc_0xEC
	  addi      r3, r29, 0
	  li        r4, 0x2
	  mtlr      r12
	  blrl
	  sth       r3, 0x6(r29)

	.loc_0xEC:
	  li        r0, 0
	  sth       r0, 0x2(r31)
	  sth       r0, 0x0(r31)
	  lbz       r3, 0x0(r29)
	  bl        0x6C4
	  lbz       r0, 0x0(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C8

	.loc_0x10C:
	  lhz       r0, 0x10A(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x154
	  lwz       r3, 0x10C(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x10C(r31)
	  lwz       r3, 0x10C(r31)
	  lhz       r0, 0x4(r29)
	  cmplw     r3, r0
	  bne-      .loc_0x154
	  lwz       r12, 0xC(r29)
	  cmplwi    r12, 0
	  beq-      .loc_0x154
	  addi      r3, r29, 0
	  li        r4, 0x4
	  mtlr      r12
	  blrl
	  sth       r3, 0x6(r29)

	.loc_0x154:
	  addi      r4, r29, 0xC
	  lwz       r0, 0xC(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C8
	  addi      r26, r29, 0x6
	  lhz       r3, 0x6(r29)
	  cmplwi    r3, 0
	  beq-      .loc_0x17C
	  subi      r0, r3, 0x1
	  sth       r0, 0x0(r26)

	.loc_0x17C:
	  lhz       r0, 0x0(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x1C8
	  lwz       r12, 0x0(r4)
	  addi      r3, r29, 0
	  li        r4, 0
	  mtlr      r12
	  blrl
	  sth       r3, 0x0(r26)
	  lhz       r0, 0x0(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x1C8
	  li        r0, 0
	  li        r3, 0x1
	  sth       r0, 0x2(r31)
	  sth       r0, 0x0(r31)
	  bl        -0xA9C
	  lbz       r3, 0x0(r29)
	  bl        0x5FC

	.loc_0x1C8:
	  addi      r28, r28, 0x1
	  addi      r27, r27, 0x10
	  cmplwi    r28, 0x40
	  blt+      .loc_0x98
	  bl        -0x9B8
	  bl        0x1EA438
	  lmw       r26, 0x48(r1)
	  lwz       r0, 0x64(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}
