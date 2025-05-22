#include "jaudio/driverinterface.h"

#include "jaudio/dspinterface.h"

typedef struct PanMatrix_ PanMatrix_;

/*
 * --INFO--
 * Address:	80009400
 * Size:	000024
 */
void Channel_SetMixerLevel(f32)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  lfs       f0, -0x7FC8(r2)
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  sth       r0, -0x7FE8(r13)
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009440
 * Size:	00000C
 */
jcs_* Get_GlobalHandle()
{
	/*
	.loc_0x0:
	  lis       r3, 0x802F
	  addi      r3, r3, 0x24E0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009460
 * Size:	000020
 */
int List_CountChannel(jc_** jc)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x0(r3)
	  li        r3, 0

	.loc_0x8:
	  cmplwi    r4, 0
	  beqlr-
	  lwz       r4, 0x24(r4)
	  addi      r3, r3, 0x1
	  b         .loc_0x8
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void Check_GlobalActiveChannel()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Check_GlobalRelease(jc_**)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void List_GlobalChannel()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80009480
 * Size:	000070
 */
void List_CutChannel(jc_*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x8(r3)
	  li        r7, 0
	  lwz       r0, 0x0(r5)
	  cmplw     r0, r3
	  mr        r6, r0
	  bne-      .loc_0x30
	  lwz       r4, 0x24(r3)
	  li        r0, 0
	  stw       r4, 0x0(r5)
	  stw       r0, 0x8(r3)
	  li        r3, 0
	  blr

	.loc_0x30:
	  cmplwi    r6, 0
	  addi      r7, r7, 0x1
	  bne-      .loc_0x44
	  li        r3, -0x1
	  blr

	.loc_0x44:
	  lwz       r0, 0x24(r6)
	  cmplw     r0, r3
	  beq-      .loc_0x58
	  mr        r6, r0
	  b         .loc_0x30

	.loc_0x58:
	  lwz       r4, 0x24(r3)
	  li        r0, 0
	  stw       r4, 0x24(r6)
	  stw       r0, 0x8(r3)
	  mr        r3, r7
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009500
 * Size:	000030
 */
jc_* List_GetChannel(jc_** jc)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  mr        r5, r0
	  bne-      .loc_0x18
	  li        r3, 0
	  blr

	.loc_0x18:
	  lwz       r4, 0x24(r5)
	  li        r0, 0
	  stw       r4, 0x0(r3)
	  mr        r3, r5
	  stw       r0, 0x8(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009540
 * Size:	000048
 */
void List_AddChannelTail(jc_**, jc_*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r3)
	  cmplwi    r5, 0
	  stw       r3, 0x8(r4)
	  bne-      .loc_0x20
	  stw       r4, 0x0(r3)
	  li        r0, 0
	  stw       r0, 0x24(r4)
	  blr

	.loc_0x20:
	  lwz       r0, 0x24(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x3C
	  stw       r4, 0x24(r5)
	  li        r0, 0
	  stw       r0, 0x24(r4)
	  blr

	.loc_0x3C:
	  mr        r5, r0
	  b         .loc_0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800095A0
 * Size:	000014
 */
void List_AddChannel(jc_**, jc_*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x0(r3)
	  stw       r3, 0x8(r4)
	  stw       r4, 0x0(r3)
	  stw       r0, 0x24(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800095C0
 * Size:	00009C
 */
BOOL FixAllocChannel(jcs_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r25, 0x1C(r1)
	  li        r26, 0
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802F
	  addi      r31, r3, 0x24E0
	  stw       r4, 0xC(r1)
	  addi      r30, r31, 0x8
	  lwz       r27, 0x8(r1)
	  lwz       r28, 0xC(r1)
	  addi      r29, r27, 0x8
	  b         .loc_0x64

	.loc_0x38:
	  mr        r3, r30
	  bl        -0xFC
	  mr.       r25, r3
	  beq-      .loc_0x6C
	  addi      r3, r29, 0
	  addi      r4, r25, 0
	  bl        -0x70
	  stw       r27, 0x4(r25)
	  mr        r3, r25
	  bl        0x444
	  addi      r26, r26, 0x1

	.loc_0x64:
	  cmplw     r26, r28
	  blt+      .loc_0x38

	.loc_0x6C:
	  lwz       r0, 0x0(r27)
	  addi      r3, r26, 0
	  add       r0, r0, r26
	  stw       r0, 0x0(r27)
	  lwz       r0, 0x0(r31)
	  sub       r0, r0, r26
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x3C(r1)
	  lmw       r25, 0x1C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009660
 * Size:	000060
 */
void FixReleaseChannel(jc_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0x24E0
	  addi      r4, r30, 0
	  addi      r3, r31, 0x8
	  bl        -0xE4
	  lwz       r5, 0x4(r30)
	  li        r3, 0
	  lwz       r4, 0x0(r5)
	  subi      r0, r4, 0x1
	  stw       r0, 0x0(r5)
	  lwz       r4, 0x0(r31)
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r31)
	  stw       r31, 0x4(r30)
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800096C0
 * Size:	0000F0
 */
void FixReleaseChannelAll(jcs_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  addi      r30, r4, 0x24E0
	  addi      r31, r3, 0
	  addi      r28, r30, 0x8

	.loc_0x20:
	  addi      r3, r31, 0x8
	  bl        -0x1E4
	  mr.       r27, r3
	  beq-      .loc_0x44
	  addi      r3, r28, 0
	  addi      r4, r27, 0
	  bl        -0x158
	  stw       r30, 0x4(r27)
	  b         .loc_0x20

	.loc_0x44:
	  addi      r29, r30, 0xC

	.loc_0x48:
	  addi      r3, r31, 0xC
	  bl        -0x20C
	  mr.       r27, r3
	  beq-      .loc_0x6C
	  addi      r3, r29, 0
	  addi      r4, r27, 0
	  bl        -0x180
	  stw       r30, 0x4(r27)
	  b         .loc_0x48

	.loc_0x6C:
	  addi      r29, r30, 0x10

	.loc_0x70:
	  addi      r3, r31, 0x10
	  bl        -0x234
	  mr.       r27, r3
	  beq-      .loc_0x94
	  addi      r3, r29, 0
	  addi      r4, r27, 0
	  bl        -0x1A8
	  stw       r30, 0x4(r27)
	  b         .loc_0x70

	.loc_0x94:
	  addi      r3, r31, 0x14
	  bl        -0x258
	  mr.       r29, r3
	  beq-      .loc_0xC0
	  mr        r3, r29
	  bl        0x14F8
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        -0x1D4
	  stw       r30, 0x4(r29)
	  b         .loc_0x94

	.loc_0xC0:
	  lwz       r5, 0x0(r30)
	  li        r0, 0
	  lwz       r4, 0x0(r31)
	  li        r3, 0
	  add       r4, r5, r4
	  stw       r4, 0x0(r30)
	  stw       r0, 0x0(r31)
	  lwz       r0, 0x2C(r1)
	  lmw       r27, 0x14(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800097C0
 * Size:	0000EC
 */
void FixMoveChannelAll(jcs_*, jcs_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r30, r4, 0

	.loc_0x18:
	  addi      r3, r29, 0x8
	  bl        -0x2DC
	  mr.       r31, r3
	  beq-      .loc_0x3C
	  addi      r3, r30, 0x8
	  addi      r4, r31, 0
	  bl        -0x250
	  stw       r30, 0x4(r31)
	  b         .loc_0x18

	.loc_0x3C:
	  addi      r3, r29, 0xC
	  bl        -0x300
	  mr.       r31, r3
	  beq-      .loc_0x60
	  addi      r3, r30, 0xC
	  addi      r4, r31, 0
	  bl        -0x274
	  stw       r30, 0x4(r31)
	  b         .loc_0x3C

	.loc_0x60:
	  addi      r3, r29, 0x10
	  bl        -0x324
	  mr.       r31, r3
	  beq-      .loc_0x84
	  addi      r3, r30, 0x10
	  addi      r4, r31, 0
	  bl        -0x298
	  stw       r30, 0x4(r31)
	  b         .loc_0x60

	.loc_0x84:
	  addi      r3, r29, 0x14
	  bl        -0x348
	  mr.       r31, r3
	  beq-      .loc_0xA8
	  addi      r3, r30, 0x14
	  addi      r4, r31, 0
	  bl        -0x2BC
	  stw       r30, 0x4(r31)
	  b         .loc_0x84

	.loc_0xA8:
	  lwz       r4, 0x0(r30)
	  li        r5, 0
	  lwz       r0, 0x0(r29)
	  li        r3, 0
	  add       r0, r4, r0
	  stw       r0, 0x0(r30)
	  stw       r5, 0x0(r29)
	  lwz       r4, 0x4(r30)
	  lwz       r0, 0x4(r29)
	  add       r0, r4, r0
	  stw       r0, 0x4(r30)
	  stw       r5, 0x4(r29)
	  lwz       r0, 0x2C(r1)
	  lmw       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800098C0
 * Size:	000070
 */
void PanCalc(const PanMatrix_*, const PanMatrix_*, u8)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r5,0,24,31
	  lis       r5, 0x8022
	  mulli     r7, r0, 0x3
	  addi      r6, r5, 0x48E0
	  li        r0, 0x3
	  lfs       f1, -0x7FC4(r2)
	  li        r5, 0
	  add       r6, r6, r7
	  mtctr     r0

	.loc_0x24:
	  lbz       r0, 0x0(r6)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x44
	  bge-      .loc_0x38
	  b         .loc_0x60

	.loc_0x38:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x60
	  b         .loc_0x50

	.loc_0x44:
	  lfsx      f0, r3, r5
	  fadds     f1, f1, f0
	  b         .loc_0x60

	.loc_0x50:
	  lfsx      f2, r3, r5
	  lfsx      f0, r4, r5
	  fmuls     f0, f2, f0
	  fadds     f1, f1, f0

	.loc_0x60:
	  addi      r5, r5, 0x4
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0x24
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009940
 * Size:	000104
 */
void InitJcs(jcs_*)
{
	/*
	.loc_0x0:
	  li        r6, 0
	  li        r5, 0x1
	  stw       r6, 0x8(r3)
	  li        r0, 0x8
	  addi      r4, r6, 0
	  stw       r6, 0xC(r3)
	  stw       r6, 0x10(r3)
	  stw       r6, 0x14(r3)
	  stw       r6, 0x4(r3)
	  stw       r6, 0x0(r3)
	  stw       r5, 0x70(r3)
	  lfs       f0, -0x7FC0(r2)
	  stfs      f0, 0x18(r3)
	  stfs      f0, 0x1C(r3)
	  lfs       f0, -0x7FBC(r2)
	  stfs      f0, 0x20(r3)
	  lfs       f0, -0x7FC4(r2)
	  stfs      f0, 0x24(r3)
	  stfs      f0, 0x28(r3)
	  mtctr     r0

	.loc_0x50:
	  addi      r0, r4, 0x2C
	  addi      r4, r4, 0x2
	  sthx      r6, r3, r0
	  bdnz+     .loc_0x50
	  li        r0, 0x7FFF
	  li        r6, 0
	  sth       r0, 0x2C(r3)
	  li        r0, 0x4
	  addi      r7, r6, 0
	  li        r4, 0
	  sth       r6, 0x4C(r3)
	  mtctr     r0

	.loc_0x80:
	  addi      r5, r4, 0x3C
	  addi      r0, r7, 0x5A
	  sthx      r6, r3, r5
	  addi      r7, r7, 0x1
	  addi      r4, r4, 0x2
	  stbx      r6, r3, r0
	  bdnz+     .loc_0x80
	  li        r11, 0
	  lis       r4, 0x2
	  stb       r11, 0x60(r3)
	  li        r0, 0x7FFF
	  li        r10, 0x150
	  li        r9, 0x210
	  sth       r0, 0x3C(r3)
	  li        r8, 0x352
	  li        r7, 0x412
	  addi      r6, r4, 0x103
	  stb       r11, 0x61(r3)
	  li        r5, 0x258
	  li        r4, 0x1A
	  li        r0, 0x1
	  sth       r10, 0x4E(r3)
	  sth       r9, 0x50(r3)
	  sth       r8, 0x52(r3)
	  sth       r7, 0x54(r3)
	  sth       r11, 0x56(r3)
	  sth       r11, 0x58(r3)
	  stw       r6, 0x68(r3)
	  sth       r5, 0x6C(r3)
	  stb       r4, 0x62(r3)
	  stb       r0, 0x63(r3)
	  stb       r0, 0x64(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009A60
 * Size:	000138
 */
void Channel_Init(jc_*)
{
	/*
	.loc_0x0:
	  li        r8, 0
	  stw       r8, 0x28(r3)
	  stw       r8, 0x2C(r3)
	  stw       r8, 0x30(r3)
	  stw       r8, 0x34(r3)
	  stw       r8, 0x10(r3)
	  stb       r8, 0xC(r3)
	  stw       r8, 0x14(r3)
	  stw       r8, 0x18(r3)
	  stw       r8, 0x1C(r3)
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x88
	  li        r0, 0x150
	  lis       r4, 0x1
	  sth       r0, 0x108(r3)
	  li        r5, 0x210
	  li        r0, 0x352
	  li        r7, 0x412
	  sth       r5, 0x10A(r3)
	  addi      r6, r4, 0x101
	  li        r5, 0x258
	  li        r4, 0x1A
	  sth       r0, 0x10C(r3)
	  li        r0, 0x1
	  sth       r7, 0x10E(r3)
	  sth       r8, 0x110(r3)
	  sth       r8, 0x112(r3)
	  stw       r6, 0x120(r3)
	  sth       r5, 0x124(r3)
	  stb       r4, 0xB8(r3)
	  stb       r0, 0xB9(r3)
	  stb       r0, 0xBA(r3)
	  b         .loc_0xEC

	.loc_0x88:
	  li        r0, 0x6
	  mtctr     r0

	.loc_0x90:
	  lwz       r5, 0x4(r3)
	  addi      r4, r8, 0x4E
	  addi      r0, r8, 0x108
	  addi      r8, r8, 0x2
	  lhzx      r4, r5, r4
	  sthx      r4, r3, r0
	  bdnz+     .loc_0x90
	  lwz       r4, 0x4(r3)
	  li        r0, 0x3
	  li        r6, 0
	  lwz       r4, 0x68(r4)
	  stw       r4, 0x120(r3)
	  lwz       r4, 0x4(r3)
	  lhz       r4, 0x6C(r4)
	  sth       r4, 0x124(r3)
	  mtctr     r0

	.loc_0xD0:
	  lwz       r5, 0x4(r3)
	  addi      r4, r6, 0x62
	  addi      r0, r6, 0xB8
	  addi      r6, r6, 0x1
	  lbzx      r4, r5, r4
	  stbx      r4, r3, r0
	  bdnz+     .loc_0xD0

	.loc_0xEC:
	  li        r0, 0x4
	  li        r4, 0
	  li        r5, 0
	  mtctr     r0

	.loc_0xFC:
	  addi      r0, r4, 0x38
	  addi      r4, r4, 0x4
	  stwx      r5, r3, r0
	  bdnz+     .loc_0xFC
	  li        r0, 0
	  stb       r0, 0x2(r3)
	  lhz       r4, 0x126(r3)
	  addi      r0, r4, 0x1
	  sth       r0, 0x126(r3)
	  lhz       r0, 0x126(r3)
	  cmpwi     r0, 0
	  bnelr-
	  li        r0, 0x1
	  sth       r0, 0x126(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009BA0
 * Size:	000030
 */
void Channel_FirstInit(jc_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x20(r3)
	  stw       r0, 0x24(r3)
	  stw       r0, 0x4(r3)
	  bl        -0x15C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009BE0
 * Size:	00007C
 */
void InitGlobalChannel()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  addi      r0, r3, 0x24E0
	  stwu      r1, -0x20(r1)
	  stmw      r27, 0xC(r1)
	  mr        r28, r0
	  addi      r3, r28, 0
	  bl        -0x2C0
	  lis       r3, 0x802F
	  li        r27, 0
	  addi      r30, r3, 0x2560
	  li        r31, 0

	.loc_0x34:
	  add       r29, r30, r31
	  addi      r3, r29, 0
	  bl        -0x7C
	  addi      r3, r28, 0x8
	  addi      r4, r29, 0
	  bl        -0x688
	  addi      r27, r27, 0x1
	  stw       r28, 0x4(r29)
	  cmpwi     r27, 0x100
	  addi      r31, r31, 0x140
	  blt+      .loc_0x34
	  li        r0, 0x100
	  stw       r0, 0x0(r28)
	  lmw       r27, 0xC(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009C60
 * Size:	0000D8
 */
void __UpdateJcToDSPInit(jc_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r28, 0x10(r1)
	  mr        r28, r3
	  lwz       r4, 0x20(r3)
	  lwz       r3, 0x4(r3)
	  lbz       r30, 0x0(r4)
	  lbz       r4, 0x60(r3)
	  mr        r3, r30
	  bl        0x1958
	  li        r29, 0
	  li        r31, 0

	.loc_0x34:
	  lwz       r3, 0x4(r28)
	  addi      r4, r31, 0x114
	  addi      r0, r29, 0x5A
	  lhax      r5, r28, r4
	  lbzx      r6, r3, r0
	  addi      r3, r30, 0
	  rlwinm    r4,r29,0,24,31
	  bl        0x1950
	  addi      r29, r29, 0x1
	  addi      r31, r31, 0x2
	  cmplwi    r29, 0x6
	  blt+      .loc_0x34
	  mr        r3, r30
	  lhz       r4, 0xF8(r28)
	  bl        0x18D4
	  lwz       r4, 0x4(r28)
	  lbz       r0, 0x61(r4)
	  rlwinm.   r0,r0,0,26,26
	  beq-      .loc_0x8C
	  addi      r3, r30, 0
	  addi      r4, r4, 0x3C
	  bl        0x1C98

	.loc_0x8C:
	  lwz       r4, 0x4(r28)
	  lbz       r0, 0x61(r4)
	  rlwinm.   r0,r0,0,27,31
	  beq-      .loc_0xA8
	  addi      r3, r30, 0
	  addi      r4, r4, 0x2C
	  bl        0x1CBC

	.loc_0xA8:
	  lwz       r4, 0x4(r28)
	  mr        r3, r30
	  lbz       r4, 0x61(r4)
	  bl        0x1CEC
	  mr        r3, r30
	  lbz       r4, 0x2(r28)
	  bl        0x19E0
	  lmw       r28, 0x10(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80009D40
 * Size:	0000D8
 */
static void __UpdateJcToDSP(jc_* jc)
{
	u8 uVar1;

	uVar1 = jc->_20->buffer_idx;
	for (u32 i = 0; i < 6; ++i) {
		DSP_SetMixerVolume(uVar1, i, jc->_114[i], jc->mMgr->_5A[i]);
	}
	DSP_SetPitch(uVar1, jc->_F8);
	if ((jc->mMgr->_61 & 0x20) != 0)
		DSP_SetIIRFilterParam(uVar1, jc->mMgr->_3C);
	if ((jc->mMgr->_61 & 0x1f) != 0)
		DSP_SetFIR8FilterParam(uVar1, jc->mMgr->_2C);
	DSP_SetFilterMode(uVar1, jc->mMgr->_61);
	DSP_SetDistFilter(uVar1, jc->mMgr->_4C);
	DSP_SetPauseFlag(uVar1, jc->_02);
}

/*
 * --INFO--
 * Address:	80009E20
 * Size:	000038
 */
void UpdateJcToDSP(jc_* jc)
{
	__UpdateJcToDSP(jc);
	DSP_FlushChannel(jc->_20->buffer_idx);
}

/*
 * --INFO--
 * Address:	80009E60
 * Size:	000348
 */
void UpdateEffecterParam(jc_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  addi      r11, r1, 0xA8
	  bl        0x20AFCC
	  stmw      r25, 0x2C(r1)
	  mr        r30, r3
	  lfs       f28, -0x7FC4(r2)
	  lwz       r0, 0xFC(r3)
	  lwz       r3, 0x4(r3)
	  cmplw     r0, r3
	  bne-      .loc_0x90
	  lfs       f0, 0x1C(r3)
	  li        r0, 0x3
	  li        r5, 0
	  stfs      f0, 0x100(r30)
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x104(r30)
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0xD0(r30)
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x24(r3)
	  stfs      f0, 0xDC(r30)
	  lwz       r3, 0x4(r30)
	  lfs       f0, 0x28(r3)
	  stfs      f0, 0xE8(r30)
	  mtctr     r0

	.loc_0x74:
	  lwz       r4, 0x4(r30)
	  addi      r3, r5, 0x62
	  addi      r0, r5, 0xB8
	  addi      r5, r5, 0x1
	  lbzx      r3, r4, r3
	  stbx      r3, r30, r0
	  bdnz+     .loc_0x74

	.loc_0x90:
	  lwz       r0, -0x7FE4(r13)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xCC
	  bge-      .loc_0x118
	  cmpwi     r0, 0
	  bge-      .loc_0xAC
	  b         .loc_0x118

	.loc_0xAC:
	  lfs       f31, -0x7FBC(r2)
	  addi      r3, r30, 0xD4
	  lfs       f28, -0x7FC4(r2)
	  addi      r4, r30, 0xBC
	  lbz       r5, 0xB9(r30)
	  bl        -0x660
	  fmr       f29, f1
	  b         .loc_0x118

	.loc_0xCC:
	  lbz       r5, 0xB8(r30)
	  cmplwi    r5, 0
	  bne-      .loc_0xE0
	  lfs       f31, -0x7FBC(r2)
	  b         .loc_0xF0

	.loc_0xE0:
	  addi      r3, r30, 0xC8
	  addi      r4, r30, 0xBC
	  bl        -0x688
	  fmr       f31, f1

	.loc_0xF0:
	  lbz       r5, 0xB9(r30)
	  addi      r3, r30, 0xD4
	  addi      r4, r30, 0xBC
	  bl        -0x69C
	  fmr       f29, f1
	  lbz       r5, 0xBA(r30)
	  addi      r3, r30, 0xE0
	  addi      r4, r30, 0xBC
	  bl        -0x6B0
	  fmr       f28, f1

	.loc_0x118:
	  lfs       f2, 0xB4(r30)
	  lfs       f1, 0xF0(r30)
	  lfs       f0, -0x7FC4(r2)
	  fmuls     f1, f2, f1
	  lfs       f2, 0x104(r30)
	  fcmpo     cr0, f31, f0
	  fmuls     f30, f2, f1
	  bge-      .loc_0x140
	  fmr       f31, f0
	  b         .loc_0x150

	.loc_0x140:
	  lfs       f0, -0x7FC0(r2)
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0x150
	  fmr       f31, f0

	.loc_0x150:
	  lfs       f0, -0x7FC4(r2)
	  fcmpo     cr0, f29, f0
	  bge-      .loc_0x164
	  fmr       f29, f0
	  b         .loc_0x174

	.loc_0x164:
	  lfs       f0, -0x7FC0(r2)
	  fcmpo     cr0, f29, f0
	  ble-      .loc_0x174
	  fmr       f29, f0

	.loc_0x174:
	  lfs       f0, -0x7FC4(r2)
	  fcmpo     cr0, f28, f0
	  bge-      .loc_0x188
	  fmr       f28, f0
	  b         .loc_0x198

	.loc_0x188:
	  lfs       f0, -0x7FC0(r2)
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0x198
	  fmr       f28, f0

	.loc_0x198:
	  lfs       f1, 0xB0(r30)
	  lis       r3, 0x8022
	  lfs       f0, 0xEC(r30)
	  lis       r4, 0x8022
	  lfs       f2, 0x100(r30)
	  addi      r27, r3, 0x4934
	  fmuls     f0, f1, f0
	  lfs       f1, -0x7FB8(r2)
	  addi      r26, r4, 0x4954
	  li        r31, 0
	  li        r29, 0
	  lis       r28, 0x4330
	  fmuls     f0, f2, f0
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x20(r1)
	  lwz       r0, 0x24(r1)
	  sth       r0, 0xF8(r30)
	  lfs       f24, -0x7FC0(r2)
	  lfs       f25, -0x7FC4(r2)
	  fsubs     f23, f24, f31
	  lfd       f26, -0x7FB0(r2)
	  fsubs     f22, f24, f29
	  fsubs     f21, f24, f28

	.loc_0x1F8:
	  add       r25, r30, r29
	  fmr       f20, f30
	  lhz       r0, 0x108(r25)
	  sth       r0, 0xC(r1)
	  lbz       r0, 0xC(r1)
	  cmplwi    r0, 0
	  bne-      .loc_0x220
	  li        r0, 0
	  sth       r0, 0x114(r25)
	  b         .loc_0x31C

	.loc_0x220:
	  lbz       r0, 0xD(r1)
	  rlwinm.   r0,r0,28,28,31
	  beq-      .loc_0x27C
	  cmplwi    r0, 0x7
	  bgt-      .loc_0x270
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r26, r0
	  mtctr     r0
	  bctr
	  fmr       f27, f31
	  b         .loc_0x270
	  fmr       f27, f29
	  b         .loc_0x270
	  fmr       f27, f28
	  b         .loc_0x270
	  fmr       f27, f23
	  b         .loc_0x270
	  fmr       f27, f22
	  b         .loc_0x270
	  fmr       f27, f21

	.loc_0x270:
	  fmr       f1, f27
	  bl        0x3CCC
	  fmuls     f20, f20, f1

	.loc_0x27C:
	  lbz       r0, 0xD(r1)
	  rlwinm.   r0,r0,0,28,31
	  beq-      .loc_0x2D8
	  cmplwi    r0, 0x7
	  bgt-      .loc_0x2CC
	  rlwinm    r0,r0,2,0,29
	  lwzx      r0, r27, r0
	  mtctr     r0
	  bctr
	  fmr       f27, f31
	  b         .loc_0x2CC
	  fmr       f27, f29
	  b         .loc_0x2CC
	  fmr       f27, f28
	  b         .loc_0x2CC
	  fmr       f27, f23
	  b         .loc_0x2CC
	  fmr       f27, f22
	  b         .loc_0x2CC
	  fmr       f27, f21

	.loc_0x2CC:
	  fmr       f1, f27
	  bl        0x3C70
	  fmuls     f20, f20, f1

	.loc_0x2D8:
	  fcmpo     cr0, f20, f25
	  bge-      .loc_0x2E8
	  fmr       f20, f25
	  b         .loc_0x2F4

	.loc_0x2E8:
	  fcmpo     cr0, f20, f24
	  ble-      .loc_0x2F4
	  fmr       f20, f24

	.loc_0x2F4:
	  lhz       r0, -0x7FE8(r13)
	  stw       r0, 0x24(r1)
	  stw       r28, 0x20(r1)
	  lfd       f0, 0x20(r1)
	  fsubs     f0, f0, f26
	  fmuls     f0, f20, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  sth       r0, 0x114(r25)

	.loc_0x31C:
	  addi      r31, r31, 0x1
	  addi      r29, r29, 0x2
	  cmplwi    r31, 0x6
	  blt+      .loc_0x1F8
	  lwz       r0, 0xAC(r1)
	  addi      r11, r1, 0xA8
	  bl        0x20ACF4
	  lmw       r25, 0x2C(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A1C0
 * Size:	000068
 */
void DoEffectOsc(jc_*, u8, f32)
{
	/*
	.loc_0x0:
	  rlwinm    r0,r4,0,24,31
	  cmpwi     r0, 0x2
	  beq-      .loc_0x50
	  bge-      .loc_0x20
	  cmpwi     r0, 0
	  beq-      .loc_0x40
	  bge-      .loc_0x30
	  blr

	.loc_0x20:
	  cmpwi     r0, 0x4
	  beq-      .loc_0x60
	  bgelr-
	  b         .loc_0x58

	.loc_0x30:
	  lfs       f0, 0xEC(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xEC(r3)
	  blr

	.loc_0x40:
	  lfs       f0, 0xF0(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xF0(r3)
	  blr

	.loc_0x50:
	  stfs      f1, 0xCC(r3)
	  blr

	.loc_0x58:
	  stfs      f1, 0xD8(r3)
	  blr

	.loc_0x60:
	  stfs      f1, 0xE4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A240
 * Size:	000084
 */
void KillBrokenLogicalChannels(dspch_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  addi      r27, r3, 0
	  addi      r30, r4, 0x2560
	  li        r29, 0
	  li        r31, 0

	.loc_0x24:
	  add       r3, r30, r31
	  lwz       r0, 0x20(r3)
	  addi      r28, r3, 0
	  cmplw     r0, r27
	  bne-      .loc_0x60
	  mr        r3, r28
	  bl        0x404
	  mr        r3, r28
	  bl        -0xE04
	  cmpwi     r3, -0x1
	  beq-      .loc_0x60
	  lwz       r3, 0x4(r28)
	  addi      r4, r28, 0
	  addi      r3, r3, 0x8
	  bl        -0xCFC

	.loc_0x60:
	  addi      r29, r29, 0x1
	  addi      r31, r31, 0x140
	  cmplwi    r29, 0x100
	  blt+      .loc_0x24
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A2E0
 * Size:	000384
 */
void CommonCallbackLogicalChannel(dspch_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stmw      r27, 0x54(r1)
	  li        r29, 0
	  stw       r3, 0x8(r1)
	  lwz       r31, 0x8(r1)
	  lwz       r0, 0x8(r31)
	  addi      r28, r31, 0x8
	  stw       r0, 0x48(r1)
	  lwz       r30, 0x48(r1)
	  cmplwi    r30, 0
	  bne-      .loc_0x50
	  li        r0, 0
	  addi      r3, r31, 0
	  stw       r0, 0xC(r31)
	  stb       r0, 0x3(r31)
	  bl        -0xE4
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x50:
	  lwz       r3, 0x20(r30)
	  cmplw     r3, r31
	  beq-      .loc_0xBC
	  cmplwi    r3, 0
	  beq-      .loc_0x7C
	  lwz       r0, 0x8(r3)
	  cmplw     r0, r30
	  bne-      .loc_0x7C
	  mr        r3, r31
	  bl        -0x114
	  b         .loc_0xA4

	.loc_0x7C:
	  mr        r3, r30
	  bl        0x320
	  mr        r3, r30
	  bl        -0xEE8
	  cmpwi     r3, -0x1
	  beq-      .loc_0xA4
	  lwz       r3, 0x4(r30)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x8
	  bl        -0xDE0

	.loc_0xA4:
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x0(r28)
	  stb       r0, 0x3(r31)
	  stw       r0, 0xC(r31)
	  b         .loc_0x370

	.loc_0xBC:
	  cmplwi    r4, 0x2
	  bne-      .loc_0x114
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0xE4
	  addi      r3, r30, 0
	  li        r4, 0x1
	  mtlr      r12
	  blrl
	  b         .loc_0x10C

	.loc_0xE4:
	  mr        r3, r30
	  bl        0x2B8
	  mr        r3, r30
	  bl        -0xF50
	  cmpwi     r3, -0x1
	  beq-      .loc_0x10C
	  lwz       r3, 0x4(r30)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x8
	  bl        -0xE48

	.loc_0x10C:
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x114:
	  lwz       r5, 0x10(r30)
	  cmplwi    r5, 0
	  beq-      .loc_0x13C
	  lwz       r5, 0x24(r5)
	  lwz       r0, 0x0(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x13C
	  bl        0xD50
	  li        r3, -0x1
	  b         .loc_0x370

	.loc_0x13C:
	  cmplwi    r4, 0x4
	  bne-      .loc_0x16C
	  lwz       r0, 0x120(r30)
	  cmplwi    r3, 0
	  rlwinm    r4,r0,16,24,31
	  beq-      .loc_0x164
	  lbzu      r0, 0x3(r3)
	  cmplw     r4, r0
	  bge-      .loc_0x164
	  stb       r4, 0x0(r3)

	.loc_0x164:
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x16C:
	  cmplwi    r4, 0x3
	  bne-      .loc_0x1A8
	  li        r0, 0x6
	  addi      r3, r30, 0
	  stb       r0, 0x48(r30)
	  bl        -0xFE0
	  cmpwi     r3, -0x1
	  bne-      .loc_0x194
	  li        r3, 0x1
	  b         .loc_0x370

	.loc_0x194:
	  lwz       r3, 0x4(r30)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x14
	  bl        -0xEE0
	  li        r4, 0

	.loc_0x1A8:
	  cmplwi    r4, 0
	  bne-      .loc_0x320
	  lfs       f0, -0x7FC0(r2)
	  li        r0, 0
	  stfs      f0, 0xEC(r30)
	  stfs      f0, 0xF0(r30)
	  lfs       f0, -0x7FBC(r2)
	  stfs      f0, 0xCC(r30)
	  lfs       f0, -0x7FC4(r2)
	  stfs      f0, 0xD8(r30)
	  stfs      f0, 0xE4(r30)
	  stw       r0, 0x44(r1)
	  b         .loc_0x2A0

	.loc_0x1DC:
	  rlwinm    r3,r0,2,0,29
	  addi      r28, r3, 0x38
	  add       r28, r30, r28
	  lwz       r3, 0x0(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x294
	  mulli     r4, r0, 0x18
	  addi      r27, r4, 0x48
	  add       r27, r30, r27
	  addi      r4, r27, 0
	  bl        0x2E5C
	  lwz       r4, 0x0(r28)
	  mr        r3, r30
	  lbz       r4, 0x0(r4)
	  bl        -0x334
	  lbz       r0, 0x0(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0x290
	  lwz       r12, 0x28(r30)
	  cmplwi    r12, 0
	  bne-      .loc_0x278
	  mr        r3, r30
	  bl        0x16C
	  cmpwi     r3, 0
	  bne-      .loc_0x250
	  lbz       r3, 0x0(r31)
	  bl        0x12FC
	  lbz       r3, 0x0(r31)
	  bl        0x15F4

	.loc_0x250:
	  mr        r3, r30
	  bl        -0x10B4
	  cmpwi     r3, -0x1
	  beq-      .loc_0x270
	  lwz       r3, 0x4(r30)
	  addi      r4, r30, 0
	  addi      r3, r3, 0x8
	  bl        -0xFAC

	.loc_0x270:
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x278:
	  addi      r3, r30, 0
	  li        r4, 0x2
	  mtlr      r12
	  blrl
	  li        r3, 0
	  b         .loc_0x370

	.loc_0x290:
	  addi      r29, r29, 0x1

	.loc_0x294:
	  lwz       r3, 0x44(r1)
	  addi      r0, r3, 0x1
	  stw       r0, 0x44(r1)

	.loc_0x2A0:
	  lwz       r0, 0x44(r1)
	  cmplwi    r0, 0x4
	  blt+      .loc_0x1DC
	  cmplwi    r29, 0
	  beq-      .loc_0x2C4
	  mr        r3, r30
	  bl        -0x738
	  li        r0, 0x1
	  stb       r0, 0x3(r30)

	.loc_0x2C4:
	  lwz       r12, 0x2C(r30)
	  cmplwi    r12, 0
	  beq-      .loc_0x2F4
	  addi      r3, r30, 0
	  li        r4, 0
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0x1
	  bne-      .loc_0x2F4
	  lbz       r3, 0x3(r30)
	  addi      r0, r3, 0x1
	  stb       r0, 0x3(r30)

	.loc_0x2F4:
	  lwz       r0, 0x28(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x308
	  li        r3, 0x1
	  b         .loc_0x370

	.loc_0x308:
	  addi      r4, r30, 0x34
	  lwz       r3, 0x34(r30)
	  cmpwi     r3, 0
	  ble-      .loc_0x320
	  subi      r0, r3, 0x1
	  stw       r0, 0x0(r4)

	.loc_0x320:
	  addi      r27, r30, 0x34
	  lwz       r0, 0x34(r30)
	  cmpwi     r0, 0
	  bne-      .loc_0x34C
	  lwz       r12, 0x28(r30)
	  addi      r3, r30, 0
	  li        r4, 0
	  mtlr      r12
	  blrl
	  lwz       r0, 0x30(r30)
	  stw       r0, 0x0(r27)

	.loc_0x34C:
	  addi      r27, r30, 0x3
	  lbz       r0, 0x3(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x36C
	  mr        r3, r30
	  bl        -0x820
	  li        r0, 0
	  stb       r0, 0x0(r27)

	.loc_0x36C:
	  li        r3, 0x1

	.loc_0x370:
	  lmw       r27, 0x54(r1)
	  lwz       r0, 0x6C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A680
 * Size:	000078
 */
void StopLogicalChannel(jc_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x20(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x28:
	  li        r31, 0
	  stw       r31, 0xC(r3)
	  lwz       r3, 0x20(r30)
	  sth       r31, 0x6(r3)
	  lwz       r3, 0x20(r30)
	  lbz       r3, 0x0(r3)
	  bl        0x1160
	  lwz       r3, 0x20(r30)
	  lbz       r3, 0x0(r3)
	  bl        0x1454
	  lwz       r3, 0x20(r30)
	  mr        r4, r30
	  bl        0x7A8
	  stw       r31, 0x20(r30)
	  li        r3, 0x1

	.loc_0x64:
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A700
 * Size:	000028
 */
BOOL CheckLogicalChannel(jc_*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x10(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x20
	  lbz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  blr

	.loc_0x20:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A740
 * Size:	000180
 */
BOOL PlayLogicalChannel(jc_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r29, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0x16C

	.loc_0x28:
	  mr        r3, r31
	  bl        -0x6C
	  cmpwi     r3, 0
	  bne-      .loc_0x40
	  li        r3, 0
	  b         .loc_0x16C

	.loc_0x40:
	  lis       r4, 0x8001
	  lwz       r3, 0x20(r31)
	  subi      r4, r4, 0x5D20
	  li        r0, 0x1
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x20(r31)
	  sth       r0, 0x6(r3)
	  lbz       r0, 0xC(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0xAC
	  bge-      .loc_0x78
	  cmpwi     r0, 0
	  bge-      .loc_0x84
	  b         .loc_0xAC

	.loc_0x78:
	  cmpwi     r0, 0x3
	  bge-      .loc_0xAC
	  b         .loc_0x9C

	.loc_0x84:
	  lwz       r3, 0x20(r31)
	  lwz       r4, 0x10(r31)
	  lbz       r3, 0x0(r3)
	  lwz       r5, 0x14(r31)
	  bl        0xF4C
	  b         .loc_0xAC

	.loc_0x9C:
	  lwz       r3, 0x20(r31)
	  lwz       r4, 0x14(r31)
	  lbz       r3, 0x0(r3)
	  bl        0xED8

	.loc_0xAC:
	  li        r29, 0
	  li        r30, 0

	.loc_0xB4:
	  addi      r3, r30, 0x108
	  lwz       r0, -0x7FE4(r13)
	  lhzx      r3, r31, r3
	  cmplwi    r0, 0
	  sth       r3, 0xC(r1)
	  bne-      .loc_0xFC
	  lbz       r0, 0xC(r1)
	  cmpwi     r0, 0x9
	  beq-      .loc_0xF4
	  bge-      .loc_0xFC
	  cmpwi     r0, 0x8
	  bge-      .loc_0xE8
	  b         .loc_0xFC

	.loc_0xE8:
	  li        r0, 0xB
	  stb       r0, 0xC(r1)
	  b         .loc_0xFC

	.loc_0xF4:
	  li        r0, 0x2
	  stb       r0, 0xC(r1)

	.loc_0xFC:
	  lwz       r3, 0x20(r31)
	  rlwinm    r4,r29,0,24,31
	  lbz       r5, 0xC(r1)
	  lbz       r3, 0x0(r3)
	  bl        0xF94
	  addi      r29, r29, 0x1
	  addi      r30, r30, 0x2
	  cmplwi    r29, 0x6
	  blt+      .loc_0xB4
	  lwz       r0, 0x4(r31)
	  mr        r3, r31
	  stw       r0, 0xFC(r31)
	  bl        -0xA0C
	  mr        r3, r31
	  bl        -0xC14
	  lwz       r0, 0x120(r31)
	  lwz       r3, 0x20(r31)
	  stb       r0, 0x3(r3)
	  lhz       r0, 0x124(r31)
	  lwz       r3, 0x20(r31)
	  sth       r0, 0x4(r3)
	  lwz       r3, 0x20(r31)
	  lbz       r3, 0x0(r3)
	  bl        0x1008
	  lwz       r3, 0x20(r31)
	  lbz       r3, 0x0(r3)
	  bl        0x127C
	  li        r3, 0x1

	.loc_0x16C:
	  lmw       r29, 0x14(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A8C0
 * Size:	000074
 */
void ResetInitialVolume(jc_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0x60

	.loc_0x28:
	  mr        r3, r31
	  bl        -0x1EC
	  cmpwi     r3, 0
	  bne-      .loc_0x40
	  li        r3, 0
	  b         .loc_0x60

	.loc_0x40:
	  mr        r3, r31
	  bl        -0xAA4
	  mr        r3, r31
	  bl        -0xCAC
	  lwz       r3, 0x20(r31)
	  lbz       r3, 0x0(r3)
	  bl        0x1208
	  li        r3, 0x1

	.loc_0x60:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000A940
 * Size:	0000B0
 */
BOOL Add_WaitDSPChannel(jc_* jc)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  lwz       r0, 0x2BD0(r13)
	  cmplwi    r0, 0x20
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0x9C

	.loc_0x28:
	  lwz       r0, 0x120(r31)
	  rlwinm    r3,r0,0,24,31
	  bl        0x870
	  cmpwi     r3, 0
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x9C

	.loc_0x44:
	  lwz       r0, 0x2BD8(r13)
	  lis       r4, 0x8030
	  lis       r3, 0x8030
	  addi      r4, r4, 0x65E0
	  rlwinm    r6,r0,2,0,29
	  addi      r0, r3, 0x6560
	  add       r3, r4, r6
	  li        r5, 0
	  stw       r5, 0x0(r3)
	  add       r3, r0, r6
	  stw       r31, 0x0(r3)
	  lwz       r4, 0x2BD8(r13)
	  lwz       r3, 0x2BD0(r13)
	  addi      r0, r4, 0x1
	  stw       r0, 0x2BD8(r13)
	  addi      r3, r3, 0x1
	  lwz       r0, 0x2BD8(r13)
	  stw       r3, 0x2BD0(r13)
	  cmplwi    r0, 0x20
	  bne-      .loc_0x98
	  stw       r5, 0x2BD8(r13)

	.loc_0x98:
	  li        r3, 0x1

	.loc_0x9C:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AA00
 * Size:	000064
 */
void Del_WaitDSPChannel(jc_*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2BD0(r13)
	  lis       r4, 0x8030
	  addi      r5, r4, 0x6560
	  lwz       r7, 0x2BD4(r13)
	  li        r8, 0
	  mtctr     r0
	  cmplwi    r0, 0
	  ble-      .loc_0x5C

	.loc_0x20:
	  add       r0, r7, r8
	  rlwinm    r6,r0,2,25,29
	  add       r4, r5, r6
	  lwz       r0, 0x0(r4)
	  cmplw     r0, r3
	  bne-      .loc_0x54
	  lis       r3, 0x8030
	  li        r5, 0
	  addi      r0, r3, 0x6560
	  li        r3, 0x1
	  add       r4, r0, r6
	  stw       r5, 0x0(r4)
	  blr

	.loc_0x54:
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x20

	.loc_0x5C:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AA80
 * Size:	0000FC
 */
void __Entry_WaitChannel(u8)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8030
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  rlwinm    r31,r3,0,24,31
	  addi      r30, r4, 0x6560
	  b         .loc_0xDC

	.loc_0x20:
	  lwz       r4, 0x2BD4(r13)
	  rlwinm    r0,r4,2,0,29
	  add       r3, r30, r0
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  mr        r29, r0
	  beq-      .loc_0xB4
	  li        r3, 0
	  addi      r4, r29, 0
	  bl        0x29C
	  cmplwi    r3, 0
	  beq-      .loc_0xE8
	  stw       r3, 0x20(r29)
	  mr        r3, r29
	  bl        -0x398
	  mr        r3, r29
	  bl        -0x1660
	  cmpwi     r3, -0x1
	  beq-      .loc_0x7C
	  lwz       r3, 0x4(r29)
	  addi      r4, r29, 0
	  addi      r3, r3, 0xC
	  bl        -0x15B8

	.loc_0x7C:
	  lwz       r3, 0x2BD4(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2BD4(r13)
	  lwz       r0, 0x2BD4(r13)
	  cmplwi    r0, 0x20
	  bne-      .loc_0x9C
	  li        r0, 0
	  stw       r0, 0x2BD4(r13)

	.loc_0x9C:
	  lwz       r3, 0x2BD0(r13)
	  cmplwi    r31, 0x1
	  subi      r0, r3, 0x1
	  stw       r0, 0x2BD0(r13)
	  beq-      .loc_0xE8
	  b         .loc_0xDC

	.loc_0xB4:
	  addi      r0, r4, 0x1
	  stw       r0, 0x2BD4(r13)
	  lwz       r0, 0x2BD4(r13)
	  cmplwi    r0, 0x20
	  bne-      .loc_0xD0
	  li        r0, 0
	  stw       r0, 0x2BD4(r13)

	.loc_0xD0:
	  lwz       r3, 0x2BD0(r13)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2BD0(r13)

	.loc_0xDC:
	  lwz       r0, 0x2BD0(r13)
	  cmplwi    r0, 0
	  bne+      .loc_0x20

	.loc_0xE8:
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AB80
 * Size:	0000C4
 */
void EntryCheck_WaitDSPChannel()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802F
	  stw       r0, 0x4(r1)
	  li        r3, 0
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r30, r4, 0x24E0
	  bl        -0x11C
	  addis     r30, r30, 0x1
	  li        r31, 0
	  b         .loc_0xA4

	.loc_0x2C:
	  lwz       r0, 0x2BD4(r13)
	  add       r0, r0, r31
	  rlwinm    r0,r0,2,25,29
	  add       r5, r30, r0
	  lwz       r0, 0x4080(r5)
	  cmplwi    r0, 0
	  mr        r3, r0
	  beq-      .loc_0xA0
	  lwz       r4, 0x4100(r5)
	  addi      r0, r4, 0x1
	  stw       r0, 0x4100(r5)
	  lwz       r4, 0x30(r3)
	  cmpwi     r4, 0
	  ble-      .loc_0x6C
	  subi      r0, r4, 0x1
	  stw       r0, 0x30(r3)

	.loc_0x6C:
	  lwz       r0, 0x30(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xA0
	  lwz       r12, 0x28(r3)
	  li        r4, 0x6
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2BD4(r13)
	  li        r4, 0
	  add       r0, r0, r31
	  rlwinm    r0,r0,2,25,29
	  add       r3, r30, r0
	  stw       r4, 0x4080(r3)

	.loc_0xA0:
	  addi      r31, r31, 0x1

	.loc_0xA4:
	  lwz       r0, 0x2BD0(r13)
	  cmplw     r31, r0
	  blt+      .loc_0x2C
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000AC60
 * Size:	00004C
 */
void Cancel_WaitDSPChannel(jc_*)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x2BD0(r13)
	  lis       r4, 0x8030
	  addi      r5, r4, 0x6560
	  lwz       r6, 0x2BD4(r13)
	  li        r8, 0
	  li        r0, 0
	  mtctr     r7
	  cmplwi    r7, 0
	  blelr-

	.loc_0x24:
	  add       r4, r6, r8
	  rlwinm    r4,r4,2,25,29
	  add       r7, r5, r4
	  lwz       r4, 0x0(r7)
	  cmplw     r4, r3
	  bne-      .loc_0x40
	  stw       r0, 0x0(r7)

	.loc_0x40:
	  addi      r8, r8, 0x1
	  bdnz+     .loc_0x24
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000ACC0
 * Size:	000038
 */
void ForceStopLogicalChannel(jc_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x20(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x28

	.loc_0x20:
	  bl        0x480
	  li        r3, 0x1

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
