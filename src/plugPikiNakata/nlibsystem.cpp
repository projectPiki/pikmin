#include "nlib/System.h"
#include "nlib/Node.h"
#include "sysNew.h"
#include "Dolphin/os.h"

System* NSystem::system;

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...) { OSPanic(__FILE__, __LINE__, fmt, "nlibsystem"); }

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
 * Address:	8011E0F8
 * Size:	0000CC
 */
NNode::NNode(int size)
{
	if (size > 0) {
		mNodeArray = new NArray<NNode>(size);
	} else {
		mNodeArray = nullptr;
	}
}

/*
 * --INFO--
 * Address:	8011E1C4
 * Size:	000038
 */
void NNode::setChild(int idx, NNode* child)
{
	if (mNodeArray) {
		mNodeArray->set(idx, child);
	}
}

/*
 * --INFO--
 * Address:	8011E1FC
 * Size:	00003C
 */
void NArray<NNode>::set(int, NNode*)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  lwz       r6, 0x4(r3)
	  subi      r0, r6, 0x1
	  cmpw      r4, r0
	  bgtlr-
	  lwz       r6, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  addi      r4, r4, 0x1
	  stwx      r5, r6, r0
	  lwz       r0, 0x8(r3)
	  cmpw      r4, r0
	  blelr-
	  stw       r4, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E238
 * Size:	000038
 */
void NNode::addChild(NNode*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E270
 * Size:	000038
 */
void NArray<NNode>::add(NNode*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  cmpw      r5, r0
	  bgelr-
	  addi      r0, r5, 0x1
	  stw       r0, 0x8(r3)
	  b         .loc_0x20
	  blr

	.loc_0x20:
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  stw       r4, -0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E2A8
 * Size:	000038
 */
void NNode::addChild(int, NNode*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E2E0
 * Size:	000050
 */
void NArray<NNode>::add(int, NNode*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x8(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  mr        r4, r5
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x40

	.loc_0x30:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E330
 * Size:	000114
 */
void NArray<NNode>::insert(int, NNode*)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x8(r3)
	  cmpw      r4, r7
	  bgelr-
	  addi      r0, r4, 0x1
	  cmpw      r7, r0
	  addi      r6, r7, 0x1
	  rlwinm    r7,r7,2,0,29
	  sub       r6, r6, r0
	  blt-      .loc_0xF8
	  rlwinm.   r0,r6,29,3,31
	  mtctr     r0
	  beq-      .loc_0xDC

	.loc_0x30:
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  bdnz+     .loc_0x30
	  andi.     r6, r6, 0x7
	  beq-      .loc_0xF8

	.loc_0xDC:
	  mtctr     r6

	.loc_0xE0:
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  bdnz+     .loc_0xE0

	.loc_0xF8:
	  lwz       r6, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  stwx      r5, r6, r0
	  lwz       r4, 0x8(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E444
 * Size:	000040
 */
void NNode::getChild(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  bne-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x30

	.loc_0x20:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x30:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E484
 * Size:	000030
 */
void NArray<NNode>::get(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  blt-      .loc_0x18
	  lwz       r5, 0x4(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  ble-      .loc_0x20

	.loc_0x18:
	  li        r3, 0
	  blr

	.loc_0x20:
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E4B4
 * Size:	000038
 */
void NNode::removeChild(NNode*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E4EC
 * Size:	000050
 */
void NArray<NNode>::remove(NNode*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E53C
 * Size:	000050
 */
void NArray<NNode>::remove(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  lwz       r5, 0x8(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  bgtlr-
	  rlwinm    r6,r4,2,0,29
	  b         .loc_0x38

	.loc_0x20:
	  lwz       r0, 0xC(r3)
	  addi      r4, r4, 0x1
	  add       r5, r0, r6
	  lwz       r0, 0x4(r5)
	  addi      r6, r6, 0x4
	  stw       r0, 0x0(r5)

	.loc_0x38:
	  lwz       r5, 0x8(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  blt+      .loc_0x20
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E58C
 * Size:	000030
 */
void NArray<NNode>::indexOf(NNode*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
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
 * Address:	8011E5BC
 * Size:	000054
 */
void NArray<NNode>::indexOf(NNode*, int)
{
	/*
	.loc_0x0:
	  cmplwi    r4, 0
	  bne-      .loc_0x10
	  li        r3, -0x1
	  blr

	.loc_0x10:
	  lwz       r6, 0x8(r3)
	  rlwinm    r7,r5,2,0,29
	  sub       r0, r6, r5
	  cmpw      r5, r6
	  mtctr     r0
	  bge-      .loc_0x4C

	.loc_0x28:
	  lwz       r6, 0xC(r3)
	  lwzx      r0, r6, r7
	  cmplw     r0, r4
	  bne-      .loc_0x40
	  mr        r3, r5
	  blr

	.loc_0x40:
	  addi      r7, r7, 0x4
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x28

	.loc_0x4C:
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E610
 * Size:	000038
 */
void NNode::removeChild(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E648
 * Size:	000038
 */
void NNode::removeAllChildren()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl

	.loc_0x28:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E680
 * Size:	000034
 */
void NArray<NNode>::removeAll()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r5, 0x8(r3)
	  lwz       r12, 0x20(r12)
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
 * Address:	8011E6B4
 * Size:	00013C
 */
void NArray<NNode>::remove(int, int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  cmpwi     r5, 0
	  li        r6, 0
	  stw       r31, 0x1C(r1)
	  ble-      .loc_0xEC
	  cmpwi     r5, 0x8
	  subi      r7, r5, 0x8
	  ble-      .loc_0xC0
	  addi      r0, r7, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r7, 0
	  mtctr     r0
	  ble-      .loc_0xC0

	.loc_0x34:
	  add       r12, r4, r6
	  lwz       r7, 0xC(r3)
	  rlwinm    r0,r12,2,0,29
	  li        r31, 0
	  stwx      r31, r7, r0
	  addi      r7, r12, 0x1
	  addi      r0, r12, 0x2
	  lwz       r8, 0xC(r3)
	  rlwinm    r7,r7,2,0,29
	  addi      r10, r12, 0x3
	  stwx      r31, r8, r7
	  addi      r9, r12, 0x4
	  addi      r8, r12, 0x5
	  lwz       r11, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  addi      r7, r12, 0x6
	  stwx      r31, r11, r0
	  addi      r0, r12, 0x7
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0xC(r3)
	  rlwinm    r9,r9,2,0,29
	  rlwinm    r8,r8,2,0,29
	  stwx      r31, r11, r10
	  rlwinm    r7,r7,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r10, 0xC(r3)
	  addi      r6, r6, 0x8
	  stwx      r31, r10, r9
	  lwz       r9, 0xC(r3)
	  stwx      r31, r9, r8
	  lwz       r8, 0xC(r3)
	  stwx      r31, r8, r7
	  lwz       r7, 0xC(r3)
	  stwx      r31, r7, r0
	  bdnz+     .loc_0x34

	.loc_0xC0:
	  sub       r0, r5, r6
	  cmpw      r6, r5
	  mtctr     r0
	  li        r8, 0
	  bge-      .loc_0xEC

	.loc_0xD4:
	  add       r0, r4, r6
	  lwz       r7, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  stwx      r8, r7, r0
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0xD4

	.loc_0xEC:
	  add       r7, r4, r5
	  li        r9, 0
	  b         .loc_0x118

	.loc_0xF8:
	  add       r0, r5, r9
	  lwz       r8, 0xC(r3)
	  rlwinm    r6,r0,2,0,29
	  add       r0, r4, r9
	  lwzx      r6, r8, r6
	  rlwinm    r0,r0,2,0,29
	  stwx      r6, r8, r0
	  addi      r9, r9, 0x1

	.loc_0x118:
	  lwz       r6, 0x8(r3)
	  sub       r0, r6, r7
	  cmpw      r9, r0
	  blt+      .loc_0xF8
	  sub       r0, r6, r5
	  stw       r0, 0x8(r3)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
NListNode::NListNode()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NListNode::addChild(NListNode*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NListNode::removeChild(NListNode*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NListNode::getChildCount()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void NListNode::addChild(int, NListNode*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NListNode::toString()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
NList::NList()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NList::addList(NList*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NList::toString()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
NHeap::NHeap(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011E7F0
 * Size:	00007C
 */
void NHeap::release()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r0, 0x4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x64
	  li        r31, 0
	  b         .loc_0x54

	.loc_0x2C:
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x1

	.loc_0x54:
	  lwz       r3, 0x4(r30)
	  lwz       r0, 0x8(r3)
	  cmpw      r31, r0
	  blt+      .loc_0x2C

	.loc_0x64:
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
 * Address:	8011E86C
 * Size:	000030
 */
void NArray<NHeap>::get(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  blt-      .loc_0x18
	  lwz       r5, 0x4(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  ble-      .loc_0x20

	.loc_0x18:
	  li        r3, 0
	  blr

	.loc_0x20:
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E89C
 * Size:	000008
 */
void NSystem::initSystem(System* sys)
{
	system = sys;
	/*
	.loc_0x0:
	  stw       r3, 0x3150(r13)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E8A4
 * Size:	000094
 */
void NSystem::randomInt(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  bl        0xF97B8
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x5F98(r2)
	  stw       r0, 0x34(r1)
	  lis       r4, 0x4330
	  addi      r3, r31, 0x1
	  lfs       f0, -0x5F9C(r2)
	  stw       r4, 0x30(r1)
	  xoris     r0, r3, 0x8000
	  lfs       f1, -0x5FA0(r2)
	  lfd       f2, 0x30(r1)
	  stw       r0, 0x2C(r1)
	  fsubs     f2, f2, f3
	  stw       r4, 0x28(r1)
	  fdivs     f2, f2, f0
	  lfd       f0, 0x28(r1)
	  fmuls     f1, f1, f2
	  fsubs     f0, f0, f3
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x18(r1)
	  lwz       r0, 0x1C(r1)
	  stfd      f0, 0x20(r1)
	  cmpw      r0, r3
	  lwz       r3, 0x24(r1)
	  bne-      .loc_0x80
	  mr        r3, r31

	.loc_0x80:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E938
 * Size:	000034
 */
int NSystem::getFreeHeap()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x3150(r13)
	  bl        -0xDF92C
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  sub       r3, r0, r4
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E96C
 * Size:	000030
 */
void NHeap::addHeap(NHeap*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x4(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x18(r12)
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
 * Address:	8011E99C
 * Size:	000038
 */
void NArray<NHeap>::add(NHeap*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  cmpw      r5, r0
	  bgelr-
	  addi      r0, r5, 0x1
	  stw       r0, 0x8(r3)
	  b         .loc_0x20
	  blr

	.loc_0x20:
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r3, r0
	  stw       r4, -0x4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011E9D4
 * Size:	000044
 */
void NArray<NNode>::contains(NNode*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  srawi     r4, r3, 0x1F
	  rlwinm    r5,r0,1,31,31
	  subc      r0, r3, r0
	  adde      r3, r4, r5
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011EA18
 * Size:	000054
 */
void NArray<NHeap>::indexOf(NHeap*, int)
{
	/*
	.loc_0x0:
	  cmplwi    r4, 0
	  bne-      .loc_0x10
	  li        r3, -0x1
	  blr

	.loc_0x10:
	  lwz       r6, 0x8(r3)
	  rlwinm    r7,r5,2,0,29
	  sub       r0, r6, r5
	  cmpw      r5, r6
	  mtctr     r0
	  bge-      .loc_0x4C

	.loc_0x28:
	  lwz       r6, 0xC(r3)
	  lwzx      r0, r6, r7
	  cmplw     r0, r4
	  bne-      .loc_0x40
	  mr        r3, r5
	  blr

	.loc_0x40:
	  addi      r7, r7, 0x4
	  addi      r5, r5, 0x1
	  bdnz+     .loc_0x28

	.loc_0x4C:
	  li        r3, -0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011EA6C
 * Size:	00003C
 */
void NArray<NHeap>::set(int, NHeap*)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  lwz       r6, 0x4(r3)
	  subi      r0, r6, 0x1
	  cmpw      r4, r0
	  bgtlr-
	  lwz       r6, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  addi      r4, r4, 0x1
	  stwx      r5, r6, r0
	  lwz       r0, 0x8(r3)
	  cmpw      r4, r0
	  blelr-
	  stw       r4, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011EAA8
 * Size:	00013C
 */
void NArray<NHeap>::remove(int, int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  cmpwi     r5, 0
	  li        r6, 0
	  stw       r31, 0x1C(r1)
	  ble-      .loc_0xEC
	  cmpwi     r5, 0x8
	  subi      r7, r5, 0x8
	  ble-      .loc_0xC0
	  addi      r0, r7, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r7, 0
	  mtctr     r0
	  ble-      .loc_0xC0

	.loc_0x34:
	  add       r12, r4, r6
	  lwz       r7, 0xC(r3)
	  rlwinm    r0,r12,2,0,29
	  li        r31, 0
	  stwx      r31, r7, r0
	  addi      r7, r12, 0x1
	  addi      r0, r12, 0x2
	  lwz       r8, 0xC(r3)
	  rlwinm    r7,r7,2,0,29
	  addi      r10, r12, 0x3
	  stwx      r31, r8, r7
	  addi      r9, r12, 0x4
	  addi      r8, r12, 0x5
	  lwz       r11, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  addi      r7, r12, 0x6
	  stwx      r31, r11, r0
	  addi      r0, r12, 0x7
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0xC(r3)
	  rlwinm    r9,r9,2,0,29
	  rlwinm    r8,r8,2,0,29
	  stwx      r31, r11, r10
	  rlwinm    r7,r7,2,0,29
	  rlwinm    r0,r0,2,0,29
	  lwz       r10, 0xC(r3)
	  addi      r6, r6, 0x8
	  stwx      r31, r10, r9
	  lwz       r9, 0xC(r3)
	  stwx      r31, r9, r8
	  lwz       r8, 0xC(r3)
	  stwx      r31, r8, r7
	  lwz       r7, 0xC(r3)
	  stwx      r31, r7, r0
	  bdnz+     .loc_0x34

	.loc_0xC0:
	  sub       r0, r5, r6
	  cmpw      r6, r5
	  mtctr     r0
	  li        r8, 0
	  bge-      .loc_0xEC

	.loc_0xD4:
	  add       r0, r4, r6
	  lwz       r7, 0xC(r3)
	  rlwinm    r0,r0,2,0,29
	  stwx      r8, r7, r0
	  addi      r6, r6, 0x1
	  bdnz+     .loc_0xD4

	.loc_0xEC:
	  add       r7, r4, r5
	  li        r9, 0
	  b         .loc_0x118

	.loc_0xF8:
	  add       r0, r5, r9
	  lwz       r8, 0xC(r3)
	  rlwinm    r6,r0,2,0,29
	  add       r0, r4, r9
	  lwzx      r6, r8, r6
	  rlwinm    r0,r0,2,0,29
	  stwx      r6, r8, r0
	  addi      r9, r9, 0x1

	.loc_0x118:
	  lwz       r6, 0x8(r3)
	  sub       r0, r6, r7
	  cmpw      r9, r0
	  blt+      .loc_0xF8
	  sub       r0, r6, r5
	  stw       r0, 0x8(r3)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011EBE4
 * Size:	000050
 */
void NArray<NHeap>::remove(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  bltlr-
	  lwz       r5, 0x8(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  bgtlr-
	  rlwinm    r6,r4,2,0,29
	  b         .loc_0x38

	.loc_0x20:
	  lwz       r0, 0xC(r3)
	  addi      r4, r4, 0x1
	  add       r5, r0, r6
	  lwz       r0, 0x4(r5)
	  addi      r6, r6, 0x4
	  stw       r0, 0x0(r5)

	.loc_0x38:
	  lwz       r5, 0x8(r3)
	  subi      r0, r5, 0x1
	  cmpw      r4, r0
	  blt+      .loc_0x20
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011EC34
 * Size:	000114
 */
void NArray<NHeap>::insert(int, NHeap*)
{
	/*
	.loc_0x0:
	  lwz       r7, 0x8(r3)
	  cmpw      r4, r7
	  bgelr-
	  addi      r0, r4, 0x1
	  cmpw      r7, r0
	  addi      r6, r7, 0x1
	  rlwinm    r7,r7,2,0,29
	  sub       r6, r6, r0
	  blt-      .loc_0xF8
	  rlwinm.   r0,r6,29,3,31
	  mtctr     r0
	  beq-      .loc_0xDC

	.loc_0x30:
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  bdnz+     .loc_0x30
	  andi.     r6, r6, 0x7
	  beq-      .loc_0xF8

	.loc_0xDC:
	  mtctr     r6

	.loc_0xE0:
	  lwz       r0, 0xC(r3)
	  add       r8, r0, r7
	  lwz       r0, -0x4(r8)
	  subi      r7, r7, 0x4
	  stw       r0, 0x0(r8)
	  bdnz+     .loc_0xE0

	.loc_0xF8:
	  lwz       r6, 0xC(r3)
	  rlwinm    r0,r4,2,0,29
	  stwx      r5, r6, r0
	  lwz       r4, 0x8(r3)
	  addi      r0, r4, 0x1
	  stw       r0, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011ED48
 * Size:	000030
 */
void NArray<NHeap>::firstElement()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
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
 * Address:	8011ED78
 * Size:	000034
 */
void NArray<NHeap>::lastElement()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x8(r3)
	  lwz       r12, 0x34(r12)
	  subi      r4, r4, 0x1
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
 * Address:	8011EDAC
 * Size:	000030
 */
void NArray<NNode>::firstElement()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x34(r12)
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
 * Address:	8011EDDC
 * Size:	000034
 */
void NArray<NNode>::lastElement()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x8(r3)
	  lwz       r12, 0x34(r12)
	  subi      r4, r4, 0x1
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
 * Address:	8011EE10
 * Size:	000050
 */
void NArray<NHeap>::remove(NHeap*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011EE60
 * Size:	000034
 */
void NArray<NHeap>::removeAll()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r5, 0x8(r3)
	  lwz       r12, 0x20(r12)
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
 * Address:	8011EE94
 * Size:	000050
 */
void NArray<NHeap>::add(int, NHeap*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0x8(r3)
	  cmpw      r4, r0
	  blt-      .loc_0x30
	  lwz       r12, 0x0(r3)
	  mr        r4, r5
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x40

	.loc_0x30:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x40:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011EEE4
 * Size:	000030
 */
void NArray<NHeap>::indexOf(NHeap*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
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
 * Address:	8011EF14
 * Size:	000044
 */
void NArray<NHeap>::contains(NHeap*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0
	  srawi     r4, r3, 0x1F
	  rlwinm    r5,r0,1,31,31
	  subc      r0, r3, r0
	  adde      r3, r4, r5
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}
