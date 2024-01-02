#include "types.h"

/*
 * --INFO--
 * Address:	8000E9C0
 * Size:	000034
 */
void ARAMFinish(u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  li        r5, 0x1
	  stwu      r1, -0x18(r1)
	  stw       r3, 0x8(r1)
	  lwz       r3, 0x8(r1)
	  lwz       r3, 0x4(r3)
	  bl        0x1EAE34
	  lwz       r0, 0x1C(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000EA00
 * Size:	0000E8
 */
void ARAM_TO_ARAM_DMA(u32, u32, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stmw      r25, 0x5C(r1)
	  addi      r25, r3, 0
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r3, r1, 0x18
	  addi      r4, r1, 0x14
	  li        r5, 0x1
	  bl        0x1EAD8C
	  lis       r4, 0x8031
	  lis       r3, 0x8001
	  subi      r30, r4, 0x680
	  subi      r31, r3, 0x1640
	  lis       r29, 0x1
	  b         .loc_0xCC

	.loc_0x44:
	  cmplw     r27, r29
	  blt-      .loc_0x54
	  lis       r28, 0x1
	  b         .loc_0x58

	.loc_0x54:
	  mr        r28, r27

	.loc_0x58:
	  addi      r7, r25, 0
	  addi      r8, r30, 0
	  addi      r9, r28, 0
	  addi      r10, r31, 0
	  addi      r3, r1, 0x38
	  addi      r4, r1, 0x18
	  li        r5, 0x1
	  li        r6, 0
	  bl        0x1F9240
	  addi      r3, r1, 0x18
	  li        r4, 0
	  li        r5, 0x1
	  bl        0x1EAE54
	  addi      r7, r30, 0
	  addi      r8, r26, 0
	  addi      r9, r28, 0
	  addi      r10, r31, 0
	  addi      r3, r1, 0x38
	  addi      r4, r1, 0x18
	  li        r5, 0
	  li        r6, 0
	  bl        0x1F920C
	  addi      r3, r1, 0x18
	  li        r4, 0
	  li        r5, 0x1
	  bl        0x1EAE20
	  sub       r27, r27, r28
	  add       r25, r25, r28
	  add       r26, r26, r28

	.loc_0xCC:
	  cmplwi    r27, 0
	  bne+      .loc_0x44
	  lmw       r25, 0x5C(r1)
	  lwz       r0, 0x7C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000EB00
 * Size:	0000FC
 */
void DRAM_TO_DRAM_DMA(u32, u32, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stmw      r25, 0x5C(r1)
	  addi      r25, r3, 0
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  addi      r3, r1, 0x18
	  addi      r4, r1, 0x14
	  li        r5, 0x1
	  lwz       r28, 0x2B30(r13)
	  bl        0x1EAC88
	  addi      r3, r25, 0
	  addi      r4, r27, 0
	  bl        0x1E80B0
	  addi      r3, r26, 0
	  addi      r4, r27, 0
	  bl        0x1E8074
	  lis       r3, 0x8001
	  lis       r30, 0x1
	  subi      r31, r3, 0x1640
	  b         .loc_0xE0

	.loc_0x58:
	  cmplw     r27, r30
	  blt-      .loc_0x68
	  lis       r29, 0x1
	  b         .loc_0x6C

	.loc_0x68:
	  mr        r29, r27

	.loc_0x6C:
	  addi      r7, r25, 0
	  addi      r8, r28, 0
	  addi      r9, r29, 0
	  addi      r10, r31, 0
	  addi      r3, r1, 0x38
	  addi      r4, r1, 0x18
	  li        r5, 0
	  li        r6, 0
	  bl        0x1F912C
	  addi      r3, r1, 0x18
	  li        r4, 0
	  li        r5, 0x1
	  bl        0x1EAD40
	  addi      r7, r28, 0
	  addi      r8, r26, 0
	  addi      r9, r29, 0
	  addi      r10, r31, 0
	  addi      r3, r1, 0x38
	  addi      r4, r1, 0x18
	  li        r5, 0x1
	  li        r6, 0
	  bl        0x1F90F8
	  addi      r3, r1, 0x18
	  li        r4, 0
	  li        r5, 0x1
	  bl        0x1EAD0C
	  sub       r27, r27, r29
	  add       r25, r25, r29
	  add       r26, r26, r29

	.loc_0xE0:
	  cmplwi    r27, 0
	  bne+      .loc_0x58
	  lmw       r25, 0x5C(r1)
	  lwz       r0, 0x7C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void Jac_GetUnlockHeap(jaheap_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void Jac_CheckAlloc(jaheap_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000EC00
 * Size:	000044
 */
void Jac_InitHeap(jaheap_*)
{
	/*
	.loc_0x0:
	  li        r5, 0
	  stw       r5, 0x8(r3)
	  stw       r5, 0xC(r3)
	  stw       r5, 0x10(r3)
	  lwz       r4, 0x2C20(r13)
	  addi      r0, r4, 0x1
	  stw       r0, 0x2C20(r13)
	  stw       r4, 0x4(r3)
	  stb       r5, 0x0(r3)
	  sth       r5, 0x2(r3)
	  stw       r5, 0x14(r3)
	  stw       r5, 0x18(r3)
	  stw       r5, 0x1C(r3)
	  stw       r5, 0x20(r3)
	  stw       r5, 0x24(r3)
	  stw       r5, 0x28(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000EC60
 * Size:	000038
 */
void Jac_SelfInitHeap(jaheap_*, u32, u32, u32)
{
	/*
	.loc_0x0:
	  stw       r4, 0x8(r3)
	  li        r0, 0
	  stw       r5, 0x10(r3)
	  stw       r0, 0xC(r3)
	  stb       r0, 0x0(r3)
	  stb       r6, 0x1(r3)
	  sth       r0, 0x2(r3)
	  stw       r0, 0x14(r3)
	  stw       r0, 0x18(r3)
	  stw       r0, 0x1C(r3)
	  stw       r0, 0x20(r3)
	  stw       r0, 0x24(r3)
	  stw       r0, 0x28(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000ECA0
 * Size:	000100
 */
void Jac_SelfAllocHeap(jaheap_*, jaheap_*, u32, u32)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x8(r3)
	  cmplwi    r7, 0
	  beq-      .loc_0x20
	  addis     r0, r7, 0x1
	  cmplwi    r0, 0xFFFF
	  beq-      .loc_0x20
	  li        r3, 0
	  blr

	.loc_0x20:
	  stw       r6, 0x8(r3)
	  li        r6, 0
	  stw       r5, 0x10(r3)
	  stw       r6, 0xC(r3)
	  stb       r6, 0x0(r3)
	  lbz       r0, 0x1(r4)
	  stb       r0, 0x1(r3)
	  sth       r6, 0x2(r3)
	  stw       r6, 0x14(r3)
	  stw       r4, 0x18(r3)
	  lwz       r5, 0x14(r4)
	  cmplwi    r5, 0
	  bne-      .loc_0x78
	  stw       r3, 0x14(r4)
	  stw       r6, 0x1C(r3)
	  lwz       r5, 0x8(r4)
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0x10(r3)
	  sub       r0, r0, r5
	  add       r0, r3, r0
	  stw       r0, 0xC(r4)
	  b         .loc_0xEC

	.loc_0x78:
	  lwz       r6, 0x8(r3)
	  mr        r7, r5
	  lwz       r0, 0x8(r5)
	  cmplw     r6, r0
	  bge-      .loc_0x98
	  stw       r5, 0x1C(r3)
	  stw       r3, 0x14(r4)
	  b         .loc_0xEC

	.loc_0x98:
	  lwz       r5, 0x1C(r7)
	  cmplwi    r5, 0
	  bne-      .loc_0xCC
	  li        r0, 0
	  stw       r0, 0x1C(r3)
	  stw       r3, 0x1C(r7)
	  lwz       r5, 0x8(r4)
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0x10(r3)
	  sub       r0, r0, r5
	  add       r0, r3, r0
	  stw       r0, 0xC(r4)
	  b         .loc_0xEC

	.loc_0xCC:
	  lwz       r0, 0x8(r5)
	  cmplw     r6, r0
	  bge-      .loc_0xE4
	  stw       r5, 0x1C(r3)
	  stw       r3, 0x1C(r7)
	  b         .loc_0xEC

	.loc_0xE4:
	  mr        r7, r5
	  b         .loc_0x98

	.loc_0xEC:
	  lhz       r5, 0x2(r4)
	  li        r3, 0x1
	  addi      r0, r5, 0x1
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000EDA0
 * Size:	000038
 */
void Jac_SetGroupHeap(jaheap_*, jaheap_*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x18
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x20

	.loc_0x18:
	  li        r3, 0
	  blr

	.loc_0x20:
	  stw       r4, 0x20(r3)
	  lwz       r0, 0x24(r4)
	  stw       r0, 0x28(r3)
	  stw       r3, 0x24(r4)
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void Jac_CutdownHeap(jaheap_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000EDE0
 * Size:	00005C
 */
void Jac_InitMotherHeap(jaheap_*, u32, u32, u8)
{
	/*
	.loc_0x0:
	  addi      r7, r4, 0x1F
	  rlwinm    r0,r4,0,27,31
	  rlwinm    r4,r7,0,0,26
	  li        r7, 0
	  stw       r4, 0x8(r3)
	  sub       r4, r5, r0
	  li        r0, 0x1
	  stw       r7, 0xC(r3)
	  stw       r4, 0x10(r3)
	  lwz       r5, 0x2C20(r13)
	  addi      r4, r5, 0x1
	  stw       r4, 0x2C20(r13)
	  stw       r5, 0x4(r3)
	  stb       r0, 0x0(r3)
	  stb       r6, 0x1(r3)
	  sth       r7, 0x2(r3)
	  stw       r7, 0x14(r3)
	  stw       r7, 0x18(r3)
	  stw       r7, 0x1C(r3)
	  stw       r7, 0x20(r3)
	  stw       r7, 0x24(r3)
	  stw       r7, 0x28(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000EE40
 * Size:	0001B4
 */
void Jac_AllocHeap(jaheap_*, jaheap_*, u32)
{
	/*
	.loc_0x0:
	  lwz       r6, 0x8(r4)
	  addi      r0, r5, 0x1F
	  rlwinm    r0,r0,0,0,26
	  cmplwi    r6, 0
	  bne-      .loc_0x1C
	  li        r3, 0
	  blr

	.loc_0x1C:
	  lwz       r5, 0x8(r3)
	  cmplwi    r5, 0
	  beq-      .loc_0x3C
	  addis     r5, r5, 0x1
	  cmplwi    r5, 0xFFFF
	  beq-      .loc_0x3C
	  li        r3, 0
	  blr

	.loc_0x3C:
	  lwz       r7, 0xC(r4)
	  lwz       r5, 0x10(r4)
	  sub       r5, r5, r7
	  cmplw     r5, r0
	  bge-      .loc_0x12C
	  lwz       r7, 0x14(r4)
	  lis       r5, 0x1000
	  addi      r8, r6, 0
	  subi      r12, r5, 0x1
	  addi      r9, r7, 0
	  li        r10, 0

	.loc_0x68:
	  cmplwi    r9, 0
	  beq-      .loc_0xA8
	  lwz       r6, 0x8(r9)
	  sub       r5, r6, r8
	  cmplw     r5, r0
	  blt-      .loc_0x98
	  sub       r5, r5, r0
	  cmplw     r5, r12
	  bge-      .loc_0x98
	  addi      r10, r9, 0
	  addi      r11, r8, 0
	  addi      r12, r5, 0

	.loc_0x98:
	  lwz       r5, 0x10(r9)
	  lwz       r9, 0x1C(r9)
	  add       r8, r6, r5
	  b         .loc_0x68

	.loc_0xA8:
	  cmplwi    r10, 0
	  bne-      .loc_0xB8
	  li        r3, 0
	  blr

	.loc_0xB8:
	  cmplw     r10, r7
	  bne-      .loc_0xCC
	  stw       r7, 0x1C(r3)
	  stw       r3, 0x14(r4)
	  b         .loc_0xF0

	.loc_0xCC:
	  mr        r6, r7

	.loc_0xD0:
	  lwz       r5, 0x1C(r6)
	  cmplw     r5, r10
	  bne-      .loc_0xE8
	  stw       r5, 0x1C(r3)
	  stw       r3, 0x1C(r6)
	  b         .loc_0xF0

	.loc_0xE8:
	  mr        r6, r5
	  b         .loc_0xD0

	.loc_0xF0:
	  stw       r11, 0x8(r3)
	  li        r5, 0
	  stw       r0, 0x10(r3)
	  stw       r5, 0xC(r3)
	  stb       r5, 0x0(r3)
	  lbz       r0, 0x1(r4)
	  stb       r0, 0x1(r3)
	  sth       r5, 0x2(r3)
	  stw       r5, 0x14(r3)
	  stw       r4, 0x18(r3)
	  li        r3, 0x1
	  lhz       r5, 0x2(r4)
	  addi      r0, r5, 0x1
	  sth       r0, 0x2(r4)
	  blr

	.loc_0x12C:
	  add       r5, r6, r7
	  li        r6, 0
	  stw       r5, 0x8(r3)
	  stw       r0, 0x10(r3)
	  stw       r6, 0xC(r3)
	  stb       r6, 0x0(r3)
	  lbz       r5, 0x1(r4)
	  stb       r5, 0x1(r3)
	  sth       r6, 0x2(r3)
	  stw       r6, 0x14(r3)
	  stw       r4, 0x18(r3)
	  lwz       r7, 0x14(r4)
	  cmplwi    r7, 0
	  bne-      .loc_0x170
	  stw       r3, 0x14(r4)
	  stw       r6, 0x1C(r3)
	  b         .loc_0x18C

	.loc_0x170:
	  lwz       r5, 0x1C(r7)
	  cmplwi    r5, 0
	  bne-      .loc_0x184
	  stw       r3, 0x1C(r7)
	  b         .loc_0x18C

	.loc_0x184:
	  mr        r7, r5
	  b         .loc_0x170

	.loc_0x18C:
	  li        r5, 0
	  stw       r5, 0x1C(r3)
	  li        r3, 0x1
	  lwz       r5, 0xC(r4)
	  add       r0, r5, r0
	  stw       r0, 0xC(r4)
	  lhz       r5, 0x2(r4)
	  addi      r0, r5, 0x1
	  sth       r0, 0x2(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000F000
 * Size:	0001B0
 */
void Jac_DeleteHeap(jaheap_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r28, 0x20(r1)
	  stw       r3, 0x8(r1)
	  lwz       r31, 0x8(r1)
	  lwz       r0, 0x8(r31)
	  addi      r30, r31, 0x8
	  cmplwi    r0, 0
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0x19C

	.loc_0x30:
	  addi      r29, r31, 0x14
	  lwz       r3, 0x14(r31)
	  b         .loc_0x48

	.loc_0x3C:
	  lwz       r28, 0x1C(r3)
	  bl        .loc_0x0
	  mr        r3, r28

	.loc_0x48:
	  cmplwi    r3, 0
	  bne+      .loc_0x3C
	  li        r0, 0
	  addi      r28, r31, 0x24
	  stw       r0, 0x0(r29)
	  lwz       r3, 0x24(r31)
	  b         .loc_0x70

	.loc_0x64:
	  lwz       r29, 0x28(r3)
	  bl        .loc_0x0
	  mr        r3, r29

	.loc_0x70:
	  cmplwi    r3, 0
	  bne+      .loc_0x64
	  li        r4, 0
	  addi      r6, r31, 0x18
	  stw       r4, 0x0(r28)
	  lwz       r3, 0x18(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x12C
	  lwzu      r7, 0x14(r3)
	  cmplw     r7, r31
	  bne-      .loc_0xBC
	  lwz       r0, 0x1C(r31)
	  stw       r0, 0x0(r3)
	  lwz       r0, 0x1C(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x11C
	  lwz       r3, 0x0(r6)
	  stw       r4, 0xC(r3)
	  b         .loc_0x11C

	.loc_0xBC:
	  cmplwi    r7, 0
	  bne-      .loc_0xD4
	  li        r0, 0
	  li        r3, 0
	  stw       r0, 0x0(r30)
	  b         .loc_0x19C

	.loc_0xD4:
	  lwz       r0, 0x1C(r7)
	  cmplw     r0, r31
	  bne-      .loc_0x114
	  lwz       r0, 0x1C(r31)
	  stw       r0, 0x1C(r7)
	  lwz       r0, 0x1C(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x11C
	  lwz       r5, 0x0(r6)
	  lwz       r3, 0x8(r7)
	  lwz       r0, 0x10(r7)
	  lwz       r4, 0x8(r5)
	  add       r0, r3, r0
	  sub       r0, r0, r4
	  stw       r0, 0xC(r5)
	  b         .loc_0x11C

	.loc_0x114:
	  mr        r7, r0
	  b         .loc_0xBC

	.loc_0x11C:
	  lwz       r4, 0x0(r6)
	  lhz       r3, 0x2(r4)
	  subi      r0, r3, 0x1
	  sth       r0, 0x2(r4)

	.loc_0x12C:
	  addi      r4, r31, 0x20
	  lwz       r3, 0x20(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x190
	  lwzu      r5, 0x24(r3)
	  cmplw     r5, r31
	  bne-      .loc_0x154
	  lwz       r0, 0x28(r31)
	  stw       r0, 0x0(r3)
	  b         .loc_0x184

	.loc_0x154:
	  cmplwi    r5, 0
	  bne-      .loc_0x164
	  li        r3, 0
	  b         .loc_0x19C

	.loc_0x164:
	  lwz       r0, 0x28(r5)
	  cmplw     r0, r31
	  bne-      .loc_0x17C
	  lwz       r0, 0x28(r31)
	  stw       r0, 0x28(r5)
	  b         .loc_0x184

	.loc_0x17C:
	  mr        r5, r0
	  b         .loc_0x154

	.loc_0x184:
	  li        r0, 0
	  stw       r0, 0x0(r4)
	  stw       r0, 0x28(r31)

	.loc_0x190:
	  li        r0, 0
	  li        r3, 0x1
	  stw       r0, 0x0(r30)

	.loc_0x19C:
	  lmw       r28, 0x20(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000F1C0
 * Size:	000064
 */
void Jac_Move_Children(jaheap_*, s32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stmw      r30, 0x10(r1)
	  mr.       r30, r4
	  beq-      .loc_0x50
	  lwz       r31, 0x14(r3)

	.loc_0x1C:
	  cmplwi    r31, 0
	  beq-      .loc_0x50
	  lwz       r0, 0x8(r31)
	  add       r0, r0, r30
	  stw       r0, 0x8(r31)
	  lwz       r0, 0x14(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x48
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        .loc_0x0

	.loc_0x48:
	  lwz       r31, 0x1C(r31)
	  b         .loc_0x1C

	.loc_0x50:
	  lwz       r0, 0x1C(r1)
	  lmw       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8000F240
 * Size:	0000C8
 */
void Jac_GarbageCollection_St(jaheap_*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stmw      r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r0, 0x14(r3)
	  lwz       r30, 0x8(r3)
	  cmplwi    r0, 0
	  mr        r31, r0
	  bne-      .loc_0x34
	  li        r0, 0
	  stw       r0, 0xC(r29)
	  b         .loc_0xB4

	.loc_0x34:
	  lwz       r0, 0x8(r31)
	  cmplw     r30, r0
	  mr        r3, r0
	  beq-      .loc_0x90
	  lbz       r0, 0x1(r29)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x70
	  bge-      .loc_0x7C
	  cmpwi     r0, 0
	  bge-      .loc_0x60
	  b         .loc_0x7C

	.loc_0x60:
	  lwz       r5, 0x10(r31)
	  mr        r4, r30
	  bl        -0x8A8
	  b         .loc_0x7C

	.loc_0x70:
	  lwz       r5, 0x10(r31)
	  mr        r4, r30
	  bl        -0x7B8

	.loc_0x7C:
	  lwz       r0, 0x8(r31)
	  addi      r3, r31, 0
	  sub       r4, r30, r0
	  bl        -0x108
	  stw       r30, 0x8(r31)

	.loc_0x90:
	  lwz       r3, 0x8(r31)
	  lwz       r0, 0x10(r31)
	  lwz       r31, 0x1C(r31)
	  add       r30, r3, r0
	  cmplwi    r31, 0
	  bne+      .loc_0x34
	  lwz       r0, 0x8(r29)
	  sub       r0, r30, r0
	  stw       r0, 0xC(r29)

	.loc_0xB4:
	  lmw       r29, 0x14(r1)
	  lwz       r0, 0x24(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void Jac_CheckFreeHeap_Total(jaheap_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void Jac_CheckFreeHeap_Linear(jaheap_*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8000F320
 * Size:	0000C4
 */
void Jac_ShowHeap(jaheap_*, u32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stmw      r29, 0x74(r1)
	  addi      r29, r4, 0
	  stw       r3, 0x8(r1)
	  lis       r3, 0x8022
	  addi      r5, r3, 0x2108
	  lwz       r3, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  lwz       r30, 0x8(r1)
	  stw       r3, 0x4C(r1)
	  stw       r0, 0x50(r1)
	  lbz       r0, 0x8(r5)
	  stb       r0, 0x54(r1)
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x68(r1)
	  lwz       r0, 0x68(r1)
	  cmplwi    r0, 0
	  beq-      .loc_0x80

	.loc_0x50:
	  lwz       r31, 0x68(r1)
	  lwz       r0, 0x14(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x6C
	  addi      r3, r31, 0
	  addi      r4, r29, 0x1
	  bl        .loc_0x0

	.loc_0x6C:
	  lwz       r0, 0x1C(r31)
	  stw       r0, 0x68(r1)
	  lwz       r0, 0x68(r1)
	  cmplwi    r0, 0
	  bne+      .loc_0x50

	.loc_0x80:
	  lwz       r30, 0x24(r30)
	  cmplwi    r30, 0
	  beq-      .loc_0xB0

	.loc_0x8C:
	  lwz       r0, 0x24(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xA4
	  addi      r3, r30, 0
	  addi      r4, r29, 0x1
	  bl        .loc_0x0

	.loc_0xA4:
	  lwz       r30, 0x28(r30)
	  cmplwi    r30, 0
	  bne+      .loc_0x8C

	.loc_0xB0:
	  lmw       r29, 0x74(r1)
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}
