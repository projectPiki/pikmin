#include "jaudio/heapctrl.h"

#include "jaudio/dummyrom.h"

#include "Dolphin/OS/OSMessage.h"
#include "Dolphin/ar.h"
#include "Dolphin/OS/OSCache.h"

#define DMABUFFER_SIZE (0x10000)
static u8 dmabuffer[DMABUFFER_SIZE] ATTRIBUTE_ALIGN(32);

static u32 global_id = 0;

/*
 * --INFO--
 * Address:	8000E9C0
 * Size:	000034
 */
static void ARAMFinish(volatile u32 param_1)
{
	u32 badCompiler[2];

	ARQRequest* request = (ARQRequest*)param_1;
	OSSendMessage((OSMessageQueue*)request->owner, (OSMessage)1, OS_MESSAGE_BLOCK);
}

/*
 * --INFO--
 * Address:	8000EA00
 * Size:	0000E8
 */
static void ARAM_TO_ARAM_DMA(u32 src, u32 dst, u32 totalSize)
{
	ARQRequest request;
	OSMessageQueue msgQueue;
	OSMessage msg;
	u32 burstSize;

	OSInitMessageQueue(&msgQueue, &msg, 1);
	while (totalSize != 0) {
		burstSize = totalSize >= DMABUFFER_SIZE ? DMABUFFER_SIZE : totalSize;

		ARQPostRequest(&request, (u32)&msgQueue, ARQ_TYPE_ARAM_TO_MRAM, ARQ_PRIORITY_LOW, src, (u32)dmabuffer, burstSize, &ARAMFinish);
		OSReceiveMessage(&msgQueue, NULL, OS_MESSAGE_BLOCK);
		ARQPostRequest(&request, (u32)&msgQueue, ARQ_TYPE_MRAM_TO_ARAM, ARQ_PRIORITY_LOW, (u32)dmabuffer, dst, burstSize, &ARAMFinish);
		OSReceiveMessage(&msgQueue, NULL, OS_MESSAGE_BLOCK);

		totalSize -= burstSize;
		src += burstSize;
		dst += burstSize;
	}
}

/*
 * --INFO--
 * Address:	8000EB00
 * Size:	0000FC
 */
static void DRAM_TO_DRAM_DMA(u32 src, u32 dst, u32 totalSize)
{
	ARQRequest request;
	OSMessageQueue msgQueue;
	OSMessage msg;
	u32 dma_buffer_top;
	u32 burstSize;

	dma_buffer_top = (u32)JAC_ARAM_DMA_BUFFER_TOP;
	OSInitMessageQueue(&msgQueue, &msg, 1);
	DCFlushRange((void*)src, totalSize);
	DCInvalidateRange((void*)dst, totalSize);
	while (totalSize != 0) {
		burstSize = totalSize >= DMABUFFER_SIZE ? DMABUFFER_SIZE : totalSize;

		ARQPostRequest(&request, (u32)&msgQueue, ARQ_TYPE_MRAM_TO_ARAM, ARQ_PRIORITY_LOW, src, dma_buffer_top, burstSize, &ARAMFinish);
		OSReceiveMessage(&msgQueue, NULL, OS_MESSAGE_BLOCK);
		ARQPostRequest(&request, (u32)&msgQueue, ARQ_TYPE_ARAM_TO_MRAM, ARQ_PRIORITY_LOW, dma_buffer_top, dst, burstSize, &ARAMFinish);
		OSReceiveMessage(&msgQueue, NULL, OS_MESSAGE_BLOCK);

		totalSize -= burstSize;
		src += burstSize;
		dst += burstSize;
	}
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
void Jac_InitHeap(jaheap_* heap)
{
	heap->_08 = 0;
	heap->_0C = 0;
	heap->_10 = 0;
	heap->_04 = global_id++;
	heap->_00 = 0;
	heap->_02 = 0;
	heap->_14 = 0;
	heap->_18 = NULL;
	heap->_1C = 0;
	heap->_20 = 0;
	heap->_24 = 0;
	heap->_28 = 0;
}

/*
 * --INFO--
 * Address:	8000EC60
 * Size:	000038
 */
void Jac_SelfInitHeap(jaheap_* heap, u32 param_2, u32 param_3, u32 param_4)
{
	heap->_08 = param_2;
	heap->_10 = param_3;
	heap->_0C = 0;
	heap->_00 = 0;
	heap->_01 = param_4;
	heap->_02 = 0;
	heap->_14 = NULL;
	heap->_18 = NULL;
	heap->_1C = 0;
	heap->_20 = 0;
	heap->_24 = 0;
	heap->_28 = 0;
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
BOOL Jac_SetGroupHeap(jaheap_* heapA, jaheap_* heapB)
{
	if (heapA->_20 || heapA->_28) {
		return FALSE;
	}
	heapA->_20 = heapB;
	heapA->_28 = heapB->_24;
	heapB->_24 = heapA;
	return TRUE;
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
void Jac_InitMotherHeap(jaheap_* heap, u32 param_2, u32 param_3, u8 param_4)
{
	heap->_08 = param_2 + 0x1f & 0xffffffe0;
	heap->_0C = 0;
	heap->_10 = param_3 - (param_2 & 0x1f);
	heap->_04 = global_id++;
	heap->_00 = 1;
	heap->_01 = param_4;
	heap->_02 = 0;
	heap->_14 = NULL;
	heap->_18 = NULL;
	heap->_1C = NULL;
	heap->_20 = NULL;
	heap->_24 = NULL;
	heap->_28 = NULL;
}

/*
 * --INFO--
 * Address:	8000EE40
 * Size:	0001B4
 */
BOOL Jac_AllocHeap(jaheap_*, jaheap_*, u32)
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
static void Jac_Move_Children(jaheap_*, s32)
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
void Jac_GarbageCollection_St(jaheap_* heap)
{
	jaheap_* heap_00;
	u32 src;
	u32 dst;

	dst     = heap->_08;
	heap_00 = heap->_14;
	if (heap_00 == NULL) {
		heap->_0C = 0;
		return;
	}
	do {
		src = heap_00->_08;
		if (dst != src) {
			switch (heap->_01) {
			case 0:
				ARAM_TO_ARAM_DMA(src, dst, heap_00->_10);
				break;
			case 1:
				DRAM_TO_DRAM_DMA(src, dst, heap_00->_10);
				break;
			}
			Jac_Move_Children(heap_00, dst - heap_00->_08);
			heap_00->_08 = dst;
		}
		dst = heap_00->_08 + heap_00->_10;
	} while (heap_00 = heap_00->_1C);

	heap->_0C = dst - heap->_08;
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
