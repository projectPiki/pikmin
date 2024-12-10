#include "jaudio/dvdthread.h"

/*
 * --INFO--
 * Address:	800073E0
 * Size:	000060
 */
static void* GetCallStack()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x10(r1)
	  stw       r31, 0xC(r1)
	  bl        0x1F1B8C
	  lwz       r6, 0x2B90(r13)
	  lis       r4, 0x802F
	  subi      r0, r4, 0x65D0
	  addi      r5, r6, 0x1
	  rlwinm    r4,r6,8,0,23
	  stw       r5, 0x2B90(r13)
	  add       r31, r0, r4
	  lwz       r0, 0x2B90(r13)
	  cmplwi    r0, 0x80
	  bne-      .loc_0x44
	  li        r0, 0
	  stw       r0, 0x2B90(r13)

	.loc_0x44:
	  bl        0x1F1B80
	  mr        r3, r31
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007440
 * Size:	00008C
 */
static s32 DVDReadMutex(DVDFileInfo*, void*, s32, s32, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  addi      r31, r7, 0
	  lwz       r0, 0x2B9C(r13)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x38
	  addi      r3, r13, 0x2B94
	  bl        0x1F5548

	.loc_0x38:
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  addi      r5, r29, 0
	  addi      r6, r30, 0
	  li        r7, 0x2
	  bl        0x1F8280
	  cmpwi     r3, -0x1
	  bne-      .loc_0x78
	  lwz       r12, 0x2BA0(r13)
	  cmplwi    r12, 0
	  beq-      .loc_0x78
	  addi      r3, r31, 0
	  addi      r4, r28, 0
	  mtlr      r12
	  blrl
	  b         .loc_0x38

	.loc_0x78:
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800074E0
 * Size:	00004C
 */
void DVDT_SetRootPath(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  stw       r3, 0x8(r1)
	  lwz       r31, 0x8(r1)
	  mr        r3, r31
	  bl        0x211F10
	  cmplwi    r3, 0x1F
	  bge-      .loc_0x38
	  lis       r3, 0x8022
	  addi      r4, r31, 0
	  addi      r3, r3, 0x2EB0
	  bl        0x211E44

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007540
 * Size:	000080
 */
void DVDT_ExtendPath(char*, char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  lbzu      r0, 0x2EB0(r5)
	  extsb.    r0, r0
	  beq-      .loc_0x60
	  addi      r3, r30, 0
	  addi      r4, r5, 0
	  bl        0x211DE8
	  lbz       r0, 0x0(r31)
	  cmpwi     r0, 0x2F
	  bne-      .loc_0x50
	  addi      r3, r30, 0
	  addi      r4, r31, 0x1
	  bl        0x211D60
	  b         .loc_0x6C

	.loc_0x50:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x211D50
	  b         .loc_0x6C

	.loc_0x60:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x211DB0

	.loc_0x6C:
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
s32 DVDT_AddTaskHigh(TaskCallback, void*, size_t)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800075C0
 * Size:	00007C
 */
s32 DVDT_AddTask(TaskCallback, void*, size_t)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r29, 0x1C(r1)
	  addi      r29, r3, 0
	  addi      r31, r4, 0
	  addi      r30, r5, 0
	  lwz       r0, 0x2B78(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x68

	.loc_0x30:
	  bl        -0x210
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  mr        r31, r0
	  addi      r5, r30, 0
	  addi      r4, r31, 0x4
	  bl        -0x1688
	  lis       r3, 0x802F
	  stw       r29, 0x0(r31)
	  subi      r3, r3, 0x67F0
	  addi      r4, r31, 0
	  li        r5, 0x1
	  bl        0x1F21F4
	  li        r3, 0x1

	.loc_0x68:
	  lmw       r29, 0x1C(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007640
 * Size:	00003C
 */
void jac_dvdproc_init()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x802F
	  stw       r0, 0x4(r1)
	  lis       r4, 0x802F
	  subi      r3, r3, 0x67F0
	  subi      r4, r4, 0x67D0
	  stwu      r1, -0x8(r1)
	  li        r5, 0x80
	  bl        0x1F2154
	  li        r0, 0x1
	  stw       r0, 0x2B78(r13)
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007680
 * Size:	000088
 */
void* jac_dvdproc(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r28, 0x10(r1)
	  bl        0x310
	  lis       r3, 0x1
	  bl        -0x1F18
	  addi      r0, r3, 0
	  addi      r3, r13, 0x2B94
	  mr        r28, r0
	  bl        0x1F442C
	  lis       r3, 0x802F
	  lis       r31, 0x1
	  subi      r30, r3, 0x67F0

	.loc_0x38:
	  addi      r3, r30, 0
	  addi      r4, r1, 0xC
	  li        r5, 0x1
	  bl        0x1F2218
	  lwz       r29, 0xC(r1)
	  bl        0x354
	  lwz       r0, 0x2B7C(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x6C
	  addi      r3, r28, 0
	  subi      r5, r31, 0x8000
	  li        r4, 0x2
	  bl        0x2F8

	.loc_0x6C:
	  cmplwi    r29, 0
	  beq+      .loc_0x38
	  lwz       r12, 0x0(r29)
	  addi      r3, r29, 0x4
	  mtlr      r12
	  blrl
	  b         .loc_0x38
	*/
}

/*
 * --INFO--
 * Address:	80007720
 * Size:	000048
 */
static void __DoError(DVDCall*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x50(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x20
	  li        r0, -0x1
	  stw       r0, 0x0(r4)

	.loc_0x20:
	  lwz       r12, 0x54(r3)
	  cmplwi    r12, 0
	  beq-      .loc_0x38
	  li        r3, -0x1
	  mtlr      r12
	  blrl

	.loc_0x38:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007780
 * Size:	000044
 */
static void __DoFinish(DVDCall*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x50(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x1C
	  stw       r4, 0x0(r5)

	.loc_0x1C:
	  lwz       r12, 0x54(r3)
	  cmplwi    r12, 0
	  beq-      .loc_0x34
	  lwz       r3, 0x0(r3)
	  mtlr      r12
	  blrl

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800077E0
 * Size:	000024
 */
static void __DVDT_CheckBack(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x0(r3)
	  bl        -0x70
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007820
 * Size:	0000D0
 */
s32 DVDT_LoadtoDRAM_Main(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stmw      r30, 0x48(r1)
	  addi      r30, r3, 0
	  addi      r4, r1, 0xC
	  addi      r3, r30, 0x4
	  bl        0x8C4
	  cmpwi     r3, 0
	  bne-      .loc_0x3C
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x130
	  li        r3, -0x1
	  b         .loc_0xBC

	.loc_0x3C:
	  lwz       r3, 0x40(r1)
	  cmplwi    r3, 0
	  bne-      .loc_0x5C
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x150
	  li        r3, -0x1
	  b         .loc_0xBC

	.loc_0x5C:
	  lwz       r0, 0x4C(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x7C
	  stw       r3, 0x4C(r30)
	  lwz       r3, 0x48(r30)
	  lwz       r0, 0x4C(r30)
	  sub       r0, r0, r3
	  stw       r0, 0x4C(r30)

	.loc_0x7C:
	  lwz       r3, 0x44(r30)
	  lwz       r4, 0x4C(r30)
	  bl        0x1EF314
	  lwz       r4, 0x44(r30)
	  addi      r3, r1, 0xC
	  lwz       r5, 0x4C(r30)
	  addi      r7, r30, 0x4
	  lwz       r6, 0x48(r30)
	  bl        -0x47C
	  addi      r31, r3, 0
	  addi      r3, r1, 0xC
	  bl        0x1F7B0C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        -0x154
	  li        r3, 0

	.loc_0xBC:
	  lwz       r0, 0x54(r1)
	  lmw       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007900
 * Size:	000084
 */
s32 DVDT_LoadtoDRAM(u32, char*, u32, u32, u32, u32*, Jac_DVDCallback)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stmw      r26, 0x80(r1)
	  addi      r31, r1, 0x24
	  addi      r26, r5, 0
	  addi      r27, r6, 0
	  addi      r28, r7, 0
	  addi      r29, r8, 0
	  addi      r30, r9, 0
	  stw       r3, 0x24(r1)
	  addi      r3, r31, 0x4
	  bl        -0x3F0
	  stw       r26, 0x68(r1)
	  cmplwi    r29, 0
	  stw       r29, 0x74(r1)
	  beq-      .loc_0x4C
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x4C:
	  stw       r30, 0x78(r1)
	  lis       r3, 0x8000
	  addi      r3, r3, 0x7820
	  addi      r4, r31, 0
	  stw       r27, 0x6C(r1)
	  li        r5, 0x58
	  stw       r28, 0x70(r1)
	  bl        -0x3A8
	  lmw       r26, 0x80(r1)
	  li        r3, 0
	  lwz       r0, 0x9C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800079A0
 * Size:	000038
 */
static void __Alloc_DVDBuffer()
{
	/*
	.loc_0x0:
	  lwz       r0, 0x2B7C(r13)
	  cmplwi    r0, 0
	  bnelr-
	  lwz       r5, 0x2B80(r13)
	  li        r3, 0
	  addi      r0, r3, 0
	  addi      r4, r13, 0x2BA4
	  mtctr     r5
	  cmplwi    r5, 0
	  blelr-

	.loc_0x28:
	  stwx      r0, r4, r3
	  addi      r3, r3, 0x4
	  bdnz+     .loc_0x28
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800079E0
 * Size:	000030
 */
static void __WriteBufferSize(u8*, u32, u32)
{
	/*
	.loc_0x0:
	  stw       r5, 0x2B7C(r13)
	  li        r6, 0
	  addi      r7, r13, 0x2BA4
	  stw       r4, 0x2B80(r13)
	  mtctr     r4
	  cmplwi    r4, 0
	  blelr-

	.loc_0x1C:
	  stwx      r3, r7, r6
	  add       r3, r3, r5
	  addi      r6, r6, 0x4
	  bdnz+     .loc_0x1C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007A20
 * Size:	000040
 */
static void __UpdateBuffer()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x2B8C(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x30
	  lwz       r3, 0x2B88(r13)
	  lwz       r5, 0x2B84(r13)
	  bl        -0x60
	  li        r0, 0
	  stw       r0, 0x2B8C(r13)
	  stw       r0, 0x2B88(r13)

	.loc_0x30:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007A60
 * Size:	000058
 */
void DVDT_SetBuffer(u8*, u32, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r6, r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2B78(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  mr        r4, r6
	  bl        -0xA0
	  b         .loc_0x48

	.loc_0x28:
	  stw       r5, 0x2B84(r13)
	  lis       r4, 0x802F
	  li        r5, 0
	  stw       r3, 0x2B88(r13)
	  subi      r3, r4, 0x67F0
	  li        r4, 0
	  stw       r6, 0x2B8C(r13)
	  bl        0x1F1D70

	.loc_0x48:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007AC0
 * Size:	0000BC
 */
s32 DVDT_CloseBuffer(u8*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x2B78(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  bl        -0x104
	  li        r3, 0x1
	  b         .loc_0xAC

	.loc_0x30:
	  lwz       r0, 0x2B88(r13)
	  cmplw     r0, r3
	  bne-      .loc_0x60
	  li        r0, 0
	  lis       r3, 0x802F
	  stw       r0, 0x2B8C(r13)
	  subi      r3, r3, 0x67F0
	  li        r4, 0
	  li        r5, 0
	  bl        0x1F1D00
	  li        r3, 0x1
	  b         .loc_0xAC

	.loc_0x60:
	  lwz       r0, 0x2BA4(r13)
	  cmplw     r0, r3
	  bne-      .loc_0xA8
	  lwz       r0, 0x2B8C(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0xA0
	  li        r5, 0
	  li        r0, 0x1
	  lis       r3, 0x802F
	  stw       r5, 0x2B88(r13)
	  subi      r3, r3, 0x67F0
	  li        r4, 0
	  stw       r5, 0x2B84(r13)
	  li        r5, 0
	  stw       r0, 0x2B8C(r13)
	  bl        0x1F1CB8

	.loc_0xA0:
	  li        r3, 0
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r3, 0x1

	.loc_0xAC:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void DVDT_GetCurrentBuffer(u8**)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80007B80
 * Size:	000010
 */
static void ARAM_DMAfinish(u32)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2BB0(r13)
	  subi      r0, r3, 0x1
	  stw       r0, 0x2BB0(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007BA0
 * Size:	00022C
 */
s32 DVDT_LoadtoARAM_Main(void*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802F
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r24, 0x18(r1)
	  addi      r27, r3, 0
	  subi      r28, r4, 0x67F0
	  lbz       r0, 0x2BB8(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x38
	  li        r3, 0
	  li        r0, 0x1
	  stw       r3, 0x2BB4(r13)
	  stb       r0, 0x2BB8(r13)

	.loc_0x38:
	  addis     r4, r28, 0x1
	  addi      r3, r27, 0x4
	  subi      r4, r4, 0x7DE0
	  bl        0x51C
	  cmpwi     r3, 0
	  bne-      .loc_0x64
	  addi      r3, r27, 0
	  li        r4, 0
	  bl        -0x4D8
	  li        r3, -0x1
	  b         .loc_0x218

	.loc_0x64:
	  addis     r3, r28, 0x1
	  lwz       r0, -0x7DAC(r3)
	  cmplwi    r0, 0
	  mr        r26, r0
	  bne-      .loc_0x8C
	  addi      r3, r27, 0
	  li        r4, 0x1
	  bl        -0x500
	  li        r3, -0x1
	  b         .loc_0x218

	.loc_0x8C:
	  lwz       r0, 0x4C(r27)
	  cmplwi    r0, 0
	  bne-      .loc_0xAC
	  stw       r26, 0x4C(r27)
	  lwz       r3, 0x48(r27)
	  lwz       r0, 0x4C(r27)
	  sub       r0, r0, r3
	  stw       r0, 0x4C(r27)

	.loc_0xAC:
	  bl        0x1F576C
	  lis       r3, 0x8000
	  addis     r29, r28, 0x1
	  addi      r31, r3, 0x7B80
	  lis       r30, 0x1234
	  b         .loc_0x1E0

	.loc_0xC4:
	  lwz       r5, 0x2BAC(r13)
	  addi      r4, r13, 0x2BA4
	  lwz       r6, 0x2B80(r13)
	  addi      r3, r5, 0x1
	  rlwinm    r5,r5,2,0,29
	  divwu     r0, r3, r6
	  lwzx      r24, r4, r5
	  mullw     r0, r0, r6
	  sub       r0, r3, r0
	  stw       r0, 0x2BAC(r13)

	.loc_0xEC:
	  lwz       r0, 0x2BB0(r13)
	  cmplw     r0, r6
	  beq+      .loc_0xEC
	  lwz       r3, 0x4C(r27)
	  lwz       r0, 0x2B7C(r13)
	  cmplw     r3, r0
	  bge-      .loc_0x13C
	  addi      r0, r3, 0x1F
	  addis     r3, r28, 0x1
	  rlwinm    r25,r0,0,0,26
	  lwz       r6, 0x48(r27)
	  addi      r4, r24, 0
	  addi      r5, r25, 0
	  subi      r3, r3, 0x7DE0
	  addi      r7, r27, 0x4
	  bl        -0x888
	  li        r0, 0
	  mr        r26, r3
	  stw       r0, 0x4C(r27)
	  b         .loc_0x180

	.loc_0x13C:
	  mr        r25, r0
	  addis     r3, r28, 0x1
	  lwz       r6, 0x48(r27)
	  addi      r4, r24, 0
	  addi      r5, r25, 0
	  subi      r3, r3, 0x7DE0
	  addi      r7, r27, 0x4
	  bl        -0x8B8
	  lwz       r4, 0x48(r27)
	  addi      r26, r3, 0
	  lwz       r0, 0x2B7C(r13)
	  add       r0, r4, r0
	  stw       r0, 0x48(r27)
	  lwz       r3, 0x2B7C(r13)
	  lwz       r0, 0x4C(r27)
	  sub       r0, r0, r3
	  stw       r0, 0x4C(r27)

	.loc_0x180:
	  lwz       r0, 0x2BB4(r13)
	  mr        r7, r24
	  lwz       r8, 0x44(r27)
	  addi      r9, r25, 0
	  rlwinm    r0,r0,5,0,26
	  addi      r10, r31, 0
	  add       r3, r29, r0
	  addi      r4, r30, 0x5678
	  li        r5, 0
	  li        r6, 0x1
	  subi      r3, r3, 0x7DA4
	  bl        0x1FFF6C
	  lwz       r3, 0x2BB4(r13)
	  lwz       r4, 0x2BB0(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2BB4(r13)
	  addi      r3, r4, 0x1
	  lwz       r0, 0x2BB4(r13)
	  stw       r3, 0x2BB0(r13)
	  rlwinm    r0,r0,0,30,31
	  stw       r0, 0x2BB4(r13)
	  lwz       r0, 0x44(r27)
	  add       r0, r0, r25
	  stw       r0, 0x44(r27)

	.loc_0x1E0:
	  lwz       r0, 0x4C(r27)
	  cmplwi    r0, 0
	  bne+      .loc_0xC4
	  addis     r3, r28, 0x1
	  subi      r3, r3, 0x7DE0
	  bl        0x1F7640

	.loc_0x1F8:
	  lwz       r0, 0x2BB0(r13)
	  cmplwi    r0, 0
	  bne+      .loc_0x1F8
	  bl        0x1F5614
	  addi      r3, r27, 0
	  addi      r4, r26, 0
	  bl        -0x630
	  li        r3, 0

	.loc_0x218:
	  lmw       r24, 0x18(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007DE0
 * Size:	000084
 */
s32 DVDT_LoadtoARAM(u32, char*, u32, u32, u32, u32*, Jac_DVDCallback)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stmw      r26, 0x80(r1)
	  addi      r31, r1, 0x24
	  addi      r26, r5, 0
	  addi      r27, r6, 0
	  addi      r28, r7, 0
	  addi      r29, r8, 0
	  addi      r30, r9, 0
	  stw       r3, 0x24(r1)
	  addi      r3, r31, 0x4
	  bl        -0x8D0
	  stw       r26, 0x68(r1)
	  cmplwi    r29, 0
	  stw       r29, 0x74(r1)
	  beq-      .loc_0x4C
	  li        r0, 0
	  stw       r0, 0x0(r29)

	.loc_0x4C:
	  stw       r30, 0x78(r1)
	  lis       r3, 0x8000
	  addi      r3, r3, 0x7BA0
	  addi      r4, r31, 0
	  stw       r27, 0x6C(r1)
	  li        r5, 0x58
	  stw       r28, 0x70(r1)
	  bl        -0x888
	  lmw       r26, 0x80(r1)
	  li        r3, 0
	  lwz       r0, 0x9C(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void ARAM_DMAfinish2(u32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void DVDT_ARAMtoDRAM_Main(void*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void DVDT_DRAMtoARAM_Main(void*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void DVDT_ARAMtoDRAM(u32, u32, u32, u32, u32*, void (*)(u32))
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void DVDT_DRAMtoARAM(u32, u32, u32, u32, u32*, void (*)(u32))
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80007E80
 * Size:	000070
 */
s32 DVDT_CheckFile(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802F
	  subi      r31, r3, 0x67F0
	  addi      r3, r1, 0x10
	  lwz       r4, 0x8(r1)
	  bl        -0x964
	  addis     r4, r31, 0x1
	  addi      r3, r1, 0x10
	  subi      r4, r4, 0x7C6C
	  bl        0x24C
	  cmpwi     r3, 0
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x5C

	.loc_0x48:
	  addis     r3, r31, 0x1
	  lwz       r31, -0x7C38(r3)
	  subi      r3, r3, 0x7C6C
	  bl        0x1F7500
	  mr        r3, r31

	.loc_0x5C:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007F00
 * Size:	000070
 */
s32 DVDT_LoadFile(char*, u8*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r4, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  li        r6, 0
	  li        r7, 0
	  stwu      r1, -0x20(r1)
	  li        r9, 0
	  stw       r3, 0x8(r1)
	  addi      r8, r1, 0x1C
	  li        r3, 0
	  stw       r0, 0x1C(r1)
	  lwz       r4, 0x8(r1)
	  bl        -0x634

	.loc_0x38:
	  lwz       r0, 0x1C(r1)
	  cmplwi    r0, 0
	  beq+      .loc_0x38
	  lwz       r3, 0x1C(r1)
	  addis     r0, r3, 0x1
	  cmplwi    r0, 0xFFFF
	  bne-      .loc_0x5C
	  li        r3, 0
	  b         .loc_0x60

	.loc_0x5C:
	  lwz       r3, 0x1C(r1)

	.loc_0x60:
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80007F80
 * Size:	000040
 */
void DVDT_CheckPass(u32, u32*, Jac_DVDCallback)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r3, 0x14(r1)
	  lis       r3, 0x8000
	  addi      r0, r1, 0x14
	  addi      r3, r3, 0x77E0
	  stw       r4, 0x64(r1)
	  mr        r4, r0
	  stw       r5, 0x68(r1)
	  li        r5, 0x58
	  bl        -0x9EC
	  lwz       r0, 0x74(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Jac_CheckFile(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void Jac_LoadFile(char*, u8*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void DVDT_Pause()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void DVDT_UnPause()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void Jac_RegisterDVDErrorCallback(void (*)(char*, u8*))
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80007FC0
 * Size:	000030
 */
s32 Jac_RegisterExtFastOpen(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r4, r3, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  addi      r3, r1, 0xC
	  bl        -0xA94
	  addi      r3, r1, 0xC
	  bl        0x24
	  lwz       r0, 0x54(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008000
 * Size:	000100
 */
s32 Jac_RegisterFastOpen(char*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802F
	  subi      r29, r3, 0x67F0
	  lwz       r28, 0x8(r1)
	  mr        r3, r28
	  bl        0x2113E8
	  cmplwi    r3, 0x3F
	  ble-      .loc_0x38
	  li        r3, -0x1
	  b         .loc_0xEC

	.loc_0x38:
	  addis     r30, r29, 0x1
	  li        r27, 0
	  li        r31, 0
	  b         .loc_0x78

	.loc_0x48:
	  add       r3, r30, r31
	  addi      r4, r28, 0
	  subi      r3, r3, 0x7BB8
	  bl        0x211170
	  cmpwi     r3, 0
	  bne-      .loc_0x70
	  rlwinm    r0,r27,2,0,29
	  add       r3, r30, r0
	  lwz       r3, -0x73B8(r3)
	  b         .loc_0xEC

	.loc_0x70:
	  addi      r27, r27, 0x1
	  addi      r31, r31, 0x40

	.loc_0x78:
	  lwz       r0, 0x2BBC(r13)
	  cmplw     r27, r0
	  blt+      .loc_0x48
	  cmplwi    r0, 0x20
	  bne-      .loc_0x94
	  li        r3, -0x1
	  b         .loc_0xEC

	.loc_0x94:
	  mr        r3, r28
	  bl        0x1F6F20
	  stw       r3, 0x1C(r1)
	  lwz       r0, 0x1C(r1)
	  cmpwi     r0, -0x1
	  beq-      .loc_0xE8
	  lwz       r0, 0x2BBC(r13)
	  addis     r31, r29, 0x1
	  addi      r4, r28, 0
	  rlwinm    r0,r0,6,0,25
	  add       r3, r31, r0
	  subi      r3, r3, 0x7BB8
	  bl        0x211294
	  lwz       r0, 0x2BBC(r13)
	  lwz       r4, 0x1C(r1)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  stw       r4, -0x73B8(r3)
	  lwz       r3, 0x2BBC(r13)
	  addi      r0, r3, 0x1
	  stw       r0, 0x2BBC(r13)

	.loc_0xE8:
	  lwz       r3, 0x1C(r1)

	.loc_0xEC:
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80008100
 * Size:	000050
 */
BOOL Jac_DVDOpen(char*, DVDFileInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r31, r4, 0
	  bl        -0x118
	  cmpwi     r3, -0x1
	  bne-      .loc_0x34
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x1F71E0
	  b         .loc_0x3C

	.loc_0x34:
	  mr        r4, r31
	  bl        0x1F7160

	.loc_0x3C:
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}
