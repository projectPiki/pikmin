#include "WorkObject.h"
#include "Generator.h"
#include "Interactions.h"
#include "DynColl.h"

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
 * Address:	8009B104
 * Size:	000010
 */
void HinderRock::beginPush()
{
	/*
	.loc_0x0:
	  lhz       r4, 0x3C8(r3)
	  addi      r0, r4, 0x1
	  sth       r0, 0x3C8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B114
 * Size:	000018
 */
void HinderRock::endPush()
{
	/*
	.loc_0x0:
	  lhz       r4, 0x3C8(r3)
	  cmplwi    r4, 0
	  beqlr-
	  subi      r0, r4, 0x1
	  sth       r0, 0x3C8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B12C
 * Size:	00010C
 */
void WorkObjectMgr::finalSetup()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  stw       r30, 0x20(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0x98

	.loc_0x30:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x54
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x6C

	.loc_0x54:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x6C:
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x158(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x98:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC0
	  li        r0, 0x1
	  b         .loc_0xEC

	.loc_0xC0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0xE8
	  li        r0, 0x1
	  b         .loc_0xEC

	.loc_0xE8:
	  li        r0, 0

	.loc_0xEC:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x30
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B238
 * Size:	000004
 */
void WorkObject::finalSetup() { }

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
WorkObject::WorkObject()
    : ItemCreature(0, nullptr, nullptr)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009B23C
 * Size:	000024
 */
void WorkObject::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x1E0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x3E198
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
void WorkObjectMgr::getNameIndex(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void WorkObjectMgr::getName(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void WorkObjectMgr::getShapeNameIndex(char*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void WorkObjectMgr::getShapeName(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009B260
 * Size:	000110
 */
WorkObjectMgr::WorkObjectMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  subi      r4, r13, 0x555C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2374
	  lwz       r30, 0x8(r1)
	  stw       r0, 0x0(r30)
	  addi      r3, r30, 0x8
	  stw       r31, 0x4(r30)
	  bl        -0x662E0
	  lis       r3, 0x8023
	  subi      r0, r3, 0x71E0
	  stw       r0, 0x8(r30)
	  addi      r3, r30, 0x8
	  subi      r4, r13, 0x555C
	  bl        -0x5AB74
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x18
	  lis       r3, 0x802B
	  stw       r0, 0x8(r30)
	  addi      r4, r3, 0x1864
	  lis       r3, 0x8022
	  stw       r4, 0x0(r30)
	  addi      r0, r4, 0x18
	  lis       r4, 0x8022
	  stw       r0, 0x8(r30)
	  addi      r0, r3, 0x738C
	  lis       r3, 0x802B
	  stw       r0, 0x28(r30)
	  addi      r0, r4, 0x737C
	  subi      r4, r13, 0x5554
	  stw       r0, 0x28(r30)
	  addi      r0, r3, 0x1900
	  li        r3, 0x14
	  stw       r31, 0x38(r30)
	  stw       r31, 0x34(r30)
	  stw       r31, 0x30(r30)
	  stw       r4, 0x2C(r30)
	  stw       r0, 0x28(r30)
	  bl        -0x54314
	  stw       r3, 0x40(r30)
	  li        r3, 0x5
	  bl        -0x54320
	  stw       r3, 0x44(r30)
	  mr        r3, r30
	  lwz       r4, 0x44(r30)
	  stb       r31, 0x0(r4)
	  lwz       r4, 0x44(r30)
	  stb       r31, 0x1(r4)
	  lwz       r4, 0x44(r30)
	  stb       r31, 0x2(r4)
	  lwz       r4, 0x44(r30)
	  stb       r31, 0x3(r4)
	  lwz       r4, 0x44(r30)
	  stb       r31, 0x4(r4)
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
 * Address:	8009B370
 * Size:	000054
 */
ObjectMgr::~ObjectMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x3C
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r3, r3, 0x18
	  extsh.    r0, r4
	  stw       r3, 0x8(r31)
	  ble-      .loc_0x3C
	  mr        r3, r31
	  bl        -0x541FC

	.loc_0x3C:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B3C4
 * Size:	000094
 */
void WorkObjectMgr::loadShapes()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  lis       r4, 0x803A
	  addi      r0, r5, 0x1010
	  stwu      r1, -0x28(r1)
	  stmw      r26, 0x10(r1)
	  li        r27, 0
	  li        r28, 0
	  rlwinm    r6,r27,2,0,29
	  add       r29, r0, r6
	  addi      r26, r3, 0
	  addi      r31, r28, 0
	  subi      r30, r4, 0x2848

	.loc_0x38:
	  lwz       r3, 0x44(r26)
	  lbzx      r0, r3, r27
	  cmplwi    r0, 0
	  beq-      .loc_0x64
	  lwz       r4, 0x0(r29)
	  addi      r3, r30, 0
	  li        r5, 0x1
	  bl        -0x48708
	  lwz       r4, 0x40(r26)
	  stwx      r3, r4, r28
	  b         .loc_0x6C

	.loc_0x64:
	  lwz       r3, 0x40(r26)
	  stwx      r31, r3, r28

	.loc_0x6C:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x5
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x4
	  blt+      .loc_0x38
	  lmw       r26, 0x10(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void WorkObjectMgr::addUseList(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009B458
 * Size:	00012C
 */
void WorkObjectMgr::birth(int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r4, 0x1
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r5,2,0,29
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r27, r5, 0
	  li        r29, 0
	  lwz       r3, 0x40(r3)
	  lwzx      r28, r3, r0
	  beq-      .loc_0x88
	  bge-      .loc_0xB0
	  cmpwi     r4, 0
	  bge-      .loc_0x40
	  b         .loc_0xB0

	.loc_0x40:
	  li        r3, 0x428
	  bl        -0x54498
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x60
	  addi      r4, r28, 0
	  li        r5, 0x1
	  bl        0x2268

	.loc_0x60:
	  cmpwi     r27, 0x4
	  stb       r27, 0x400(r30)
	  mr        r29, r30
	  bne-      .loc_0x7C
	  li        r0, 0x3
	  sth       r0, 0x54(r30)
	  b         .loc_0xB0

	.loc_0x7C:
	  li        r0, 0x1
	  sth       r0, 0x54(r30)
	  b         .loc_0xB0

	.loc_0x88:
	  li        r3, 0x478
	  bl        -0x544E0
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0xA4
	  mr        r4, r28
	  bl        0xA24

	.loc_0xA4:
	  li        r0, 0x1
	  sth       r0, 0x54(r30)
	  mr        r29, r30

	.loc_0xB0:
	  li        r3, 0x18
	  bl        -0x54508
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x108
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r30)
	  li        r0, 0
	  lis       r4, 0x802B
	  stw       r0, 0x10(r30)
	  addi      r4, r4, 0x1024
	  stw       r0, 0xC(r30)
	  stw       r0, 0x8(r30)
	  bl        -0x76678
	  lis       r3, 0x802B
	  addi      r0, r3, 0x1900
	  stw       r0, 0x0(r30)
	  stw       r29, 0x14(r30)

	.loc_0x108:
	  addi      r4, r30, 0
	  addi      r3, r31, 0x28
	  bl        -0x5AF90
	  mr        r3, r29
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B584
 * Size:	000088
 */
Creature* WorkObjectMgr::getCreature(int)
{
	return nullptr;
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  lwz       r5, 0x38(r3)
	  li        r6, 0
	  ble-      .loc_0x70
	  cmpwi     r4, 0x8
	  subi      r3, r4, 0x8
	  ble-      .loc_0x58
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  ble-      .loc_0x58

	.loc_0x30:
	  lwz       r3, 0xC(r5)
	  addi      r6, r6, 0x8
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r3, 0xC(r3)
	  lwz       r5, 0xC(r3)
	  bdnz+     .loc_0x30

	.loc_0x58:
	  sub       r0, r4, r6
	  cmpw      r6, r4
	  mtctr     r0
	  bge-      .loc_0x70

	.loc_0x68:
	  lwz       r5, 0xC(r5)
	  bdnz+     .loc_0x68

	.loc_0x70:
	  cmplwi    r5, 0
	  bne-      .loc_0x80
	  li        r3, 0
	  blr

	.loc_0x80:
	  lwz       r3, 0x14(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B60C
 * Size:	000008
 */
int WorkObjectMgr::getFirst() { return 0; }

/*
 * --INFO--
 * Address:	8009B614
 * Size:	000008
 */
int WorkObjectMgr::getNext(int idx) { return idx + 1; }

/*
 * --INFO--
 * Address:	8009B61C
 * Size:	000044
 */
bool WorkObjectMgr::isDone(int)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x28
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  bl        -0x5AFB4
	  cmpw      r31, r3
	  blt-      .loc_0x2C
	  li        r3, 0x1
	  b         .loc_0x30

	.loc_0x2C:
	  li        r3, 0

	.loc_0x30:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B660
 * Size:	000024
 */
int WorkObjectMgr::getSize()
{
	return 0;
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r3, r3, 0x28
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0x5AFF0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00015C
 */
GenObjectWorkObject::GenObjectWorkObject()
    : GenObject(0, nullptr)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009B684
 * Size:	0000A0
 */
void GenObjectWorkObject::ramSaveParameters(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lwz       r0, 0x24(r30)
	  lwz       r12, 0x28(r12)
	  rlwinm    r4,r0,0,24,31
	  mtlr      r12
	  blrl
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r0, 0x34(r30)
	  lwz       r12, 0x28(r12)
	  rlwinm    r4,r0,0,24,31
	  mtlr      r12
	  blrl
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r0, 0x44(r30)
	  lwz       r12, 0x28(r12)
	  rlwinm    r4,r0,0,24,31
	  mtlr      r12
	  blrl
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lfs       f1, 0x54(r30)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B724
 * Size:	0000A0
 */
void GenObjectWorkObject::ramLoadParameters(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x24(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x34(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  stw       r0, 0x44(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x54(r30)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B7C4
 * Size:	00016C
 */
static void makeObjectWorkObject()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r3, 0x6C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  bl        -0x547DC
	  mr.       r31, r3
	  beq-      .loc_0x14C
	  lis       r4, 0x802B
	  lis       r3, 0x802B
	  addi      r5, r4, 0x1030
	  lis       r4, 0x776F
	  addi      r6, r3, 0x103C
	  addi      r3, r31, 0
	  addi      r4, r4, 0x726B
	  bl        0x3F4AC
	  lis       r3, 0x802C
	  subi      r0, r3, 0x5490
	  lis       r3, 0x802B
	  stw       r0, 0x4(r31)
	  addi      r0, r3, 0x1750
	  stw       r0, 0x4(r31)
	  addi      r5, r1, 0x24
	  addi      r4, r31, 0
	  lwz       r0, -0x5544(r13)
	  addi      r3, r31, 0x18
	  stw       r0, 0x2C(r1)
	  lwz       r0, 0x2C(r1)
	  stw       r0, 0x24(r1)
	  bl        -0x3CDC0
	  lis       r3, 0x802A
	  addi      r29, r3, 0x60C4
	  stw       r29, 0x20(r31)
	  li        r30, 0
	  addi      r5, r1, 0x20
	  stw       r30, 0x24(r31)
	  mr        r4, r31
	  addi      r3, r31, 0x28
	  lwz       r0, -0x5540(r13)
	  stw       r0, 0x34(r1)
	  lwz       r0, 0x34(r1)
	  stw       r0, 0x20(r1)
	  bl        -0x3CDF4
	  stw       r29, 0x30(r31)
	  addi      r5, r1, 0x1C
	  addi      r4, r31, 0
	  stw       r30, 0x34(r31)
	  addi      r3, r31, 0x38
	  lwz       r0, -0x553C(r13)
	  stw       r0, 0x3C(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x1C(r1)
	  bl        -0x3CE1C
	  stw       r29, 0x40(r31)
	  li        r0, 0xA
	  addi      r5, r1, 0x18
	  stw       r0, 0x44(r31)
	  mr        r4, r31
	  addi      r3, r31, 0x48
	  lwz       r0, -0x5538(r13)
	  stw       r0, 0x44(r1)
	  lwz       r0, 0x44(r1)
	  stw       r0, 0x18(r1)
	  bl        -0x3CE48
	  lis       r3, 0x802A
	  addi      r0, r3, 0x6098
	  stw       r0, 0x50(r31)
	  lfs       f0, -0x7330(r2)
	  stfs      f0, 0x54(r31)
	  lfs       f0, -0x732C(r2)
	  stfs      f0, 0x68(r31)
	  stfs      f0, 0x64(r31)
	  stfs      f0, 0x60(r31)
	  stw       r30, 0x58(r31)
	  stw       r30, 0x5C(r31)
	  lfs       f0, -0x5550(r13)
	  stfs      f0, 0x60(r31)
	  lfs       f0, -0x554C(r13)
	  stfs      f0, 0x64(r31)
	  lfs       f0, -0x5548(r13)
	  stfs      f0, 0x68(r31)

	.loc_0x14C:
	  mr        r3, r31
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B930
 * Size:	00008C
 */
void GenObjectWorkObject::initialise()
{
	/*
	.loc_0x0:
	  lwz       r7, 0x3074(r13)
	  lwz       r5, 0x0(r7)
	  lwz       r0, 0x4(r7)
	  cmpw      r5, r0
	  bgelr-
	  lis       r4, 0x776F
	  lwz       r3, 0x8(r7)
	  addi      r4, r4, 0x726B
	  rlwinm    r0,r5,4,0,27
	  stwx      r4, r3, r0
	  lis       r6, 0x800A
	  lis       r4, 0x802B
	  lwz       r0, 0x0(r7)
	  lis       r3, 0x7630
	  lwz       r5, 0x8(r7)
	  subi      r6, r6, 0x483C
	  rlwinm    r0,r0,4,0,27
	  add       r5, r5, r0
	  stw       r6, 0x4(r5)
	  addi      r5, r4, 0x1050
	  addi      r4, r3, 0x2E33
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x0(r7)
	  lwz       r3, 0x8(r7)
	  rlwinm    r0,r0,4,0,27
	  add       r3, r3, r0
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x0(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r7)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B9BC
 * Size:	00020C
 */
void GenObjectWorkObject::doRead(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stw       r31, 0x11C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x118(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x114(r1)
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xBC
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  stw       r0, 0x58(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  stw       r0, 0x5C(r30)
	  lwz       r0, 0x58(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1F0
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x60(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x64(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x68(r30)
	  b         .loc_0x1F0

	.loc_0xBC:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  addi      r4, r1, 0x10
	  li        r5, 0x100
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x802B
	  addi      r29, r3, 0xEF8
	  b         .loc_0x104

	.loc_0xE4:
	  lwz       r3, 0x4(r29)
	  addi      r4, r1, 0x10
	  bl        0x17D71C
	  cmpwi     r3, 0
	  bne-      .loc_0x100
	  lwz       r0, 0x0(r29)
	  b         .loc_0x114

	.loc_0x100:
	  addi      r29, r29, 0x8

	.loc_0x104:
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x2
	  bne+      .loc_0xE4
	  li        r0, -0x1

	.loc_0x114:
	  stw       r0, 0x58(r30)
	  lwz       r3, 0xC(r30)
	  subis     r0, r3, 0x7630
	  cmplwi    r0, 0x2E32
	  beq-      .loc_0x130
	  cmplwi    r0, 0x2E33
	  bne-      .loc_0x18C

	.loc_0x130:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  addi      r4, r1, 0x10
	  li        r5, 0x100
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x802B
	  addi      r29, r3, 0xF50
	  b         .loc_0x178

	.loc_0x158:
	  lwz       r3, 0x4(r29)
	  addi      r4, r1, 0x10
	  bl        0x17D6A8
	  cmpwi     r3, 0
	  bne-      .loc_0x174
	  lwz       r0, 0x0(r29)
	  b         .loc_0x188

	.loc_0x174:
	  addi      r29, r29, 0x8

	.loc_0x178:
	  lwz       r0, 0x0(r29)
	  cmpwi     r0, 0x5
	  bne+      .loc_0x158
	  li        r0, -0x1

	.loc_0x188:
	  stw       r0, 0x5C(r30)

	.loc_0x18C:
	  lwz       r3, 0xC(r30)
	  subis     r0, r3, 0x7630
	  cmplwi    r0, 0x2E33
	  bne-      .loc_0x1F0
	  lwz       r0, 0x58(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1F0
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x60(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x64(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x68(r30)

	.loc_0x1F0:
	  lwz       r0, 0x124(r1)
	  lwz       r31, 0x11C(r1)
	  lwz       r30, 0x118(r1)
	  lwz       r29, 0x114(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009BBC8
 * Size:	0001B4
 */
void GenObjectWorkObject::doWrite(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0x3070(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xB8
	  mr        r3, r31
	  lwz       r0, 0x58(r30)
	  lwz       r12, 0x4(r31)
	  extsh     r4, r0
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r0, 0x5C(r30)
	  lwz       r12, 0x4(r31)
	  extsh     r4, r0
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x58(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x19C
	  mr        r3, r31
	  lfs       f1, 0x60(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, 0x64(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, 0x68(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x19C

	.loc_0xB8:
	  lis       r3, 0x802B
	  lwz       r0, 0x58(r30)
	  addi      r3, r3, 0xEF8
	  b         .loc_0xDC

	.loc_0xC8:
	  cmpw      r4, r0
	  bne-      .loc_0xD8
	  lwz       r4, 0x4(r3)
	  b         .loc_0xEC

	.loc_0xD8:
	  addi      r3, r3, 0x8

	.loc_0xDC:
	  lwz       r4, 0x0(r3)
	  cmpwi     r4, 0x2
	  bne+      .loc_0xC8
	  li        r4, 0

	.loc_0xEC:
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lis       r3, 0x802B
	  lwz       r0, 0x5C(r30)
	  addi      r3, r3, 0xF50
	  b         .loc_0x124

	.loc_0x110:
	  cmpw      r4, r0
	  bne-      .loc_0x120
	  lwz       r4, 0x4(r3)
	  b         .loc_0x134

	.loc_0x120:
	  addi      r3, r3, 0x8

	.loc_0x124:
	  lwz       r4, 0x0(r3)
	  cmpwi     r4, 0x5
	  bne+      .loc_0x110
	  li        r4, 0

	.loc_0x134:
	  lwz       r12, 0x4(r31)
	  mr        r3, r31
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x58(r30)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x19C
	  mr        r3, r31
	  lfs       f1, 0x60(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, 0x64(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lfs       f1, 0x68(r30)
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x19C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009BD7C
 * Size:	000020
 */
void GenObjectWorkObject::updateUseList(Generator*, int)
{
	/*
	.loc_0x0:
	  lwz       r4, 0x5C(r3)
	  cmpwi     r4, -0x1
	  beqlr-
	  lwz       r3, 0x3020(r13)
	  li        r0, 0x1
	  lwz       r3, 0x44(r3)
	  stbx      r0, r3, r4
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009BD9C
 * Size:	000180
 */
void* GenObjectWorkObject::birth(BirthInfo&)
{
	return nullptr;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x4C(r1)
	  mr        r29, r3
	  lwz       r0, 0x58(r3)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0x164

	.loc_0x34:
	  lwz       r3, 0x3020(r13)
	  mr        r4, r0
	  lwz       r5, 0x5C(r29)
	  bl        -0x984
	  mr.       r31, r3
	  beq-      .loc_0x160
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x0(r30)
	  lfs       f2, 0x8(r30)
	  bl        -0x33EF4
	  stfs      f1, 0x4(r30)
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r30)
	  lwz       r0, 0x10(r30)
	  stw       r3, 0x88(r31)
	  stw       r0, 0x8C(r31)
	  lwz       r0, 0x14(r30)
	  stw       r0, 0x90(r31)
	  lfs       f0, 0x8C(r31)
	  stfs      f0, 0xA0(r31)
	  lwz       r0, 0x24(r30)
	  stw       r0, 0x64(r31)
	  lwz       r0, 0x58(r29)
	  cmpwi     r0, 0x1
	  bne-      .loc_0xD8
	  lwz       r3, 0x60(r29)
	  lwz       r0, 0x64(r29)
	  stw       r3, 0x40C(r31)
	  stw       r0, 0x410(r31)
	  lwz       r0, 0x68(r29)
	  stw       r0, 0x414(r31)
	  lwz       r0, 0x44(r29)
	  stw       r0, 0x41C(r31)
	  lfs       f0, 0x54(r29)
	  stfs      f0, 0x420(r31)

	.loc_0xD8:
	  lis       r3, 0x803A
	  lwz       r5, 0x24(r29)
	  subi      r3, r3, 0x2848
	  lwz       r7, 0x34(r29)
	  lfs       f0, 0x2DC(r3)
	  lis       r0, 0x4330
	  lfd       f1, -0x7328(r2)
	  mr        r3, r31
	  fctiwz    f0, f0
	  li        r4, 0
	  stfd      f0, 0x40(r1)
	  lwz       r6, 0x44(r1)
	  mullw     r5, r6, r5
	  add       r5, r7, r5
	  xoris     r5, r5, 0x8000
	  stw       r5, 0x3C(r1)
	  stw       r0, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x58(r31)
	  lfs       f0, 0x58(r31)
	  stfs      f0, 0x5C(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x24(r30)
	  lwz       r3, 0x28(r3)
	  lwz       r0, 0x34(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x160
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x1
	  stw       r0, 0xC8(r31)

	.loc_0x160:
	  mr        r3, r31

	.loc_0x164:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009BF1C
 * Size:	000178
 */
HinderRock::HinderRock(Shape*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  li        r4, 0x26
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x14(r1)
	  bl        0x59964
	  lis       r3, 0x802B
	  addi      r3, r3, 0x1944
	  stw       r3, 0x0(r30)
	  addi      r3, r3, 0x114
	  li        r0, 0x26
	  stw       r3, 0x2B8(r30)
	  li        r3, 0x28
	  stw       r0, 0x6C(r30)
	  bl        -0x54F68
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x64
	  bl        0x7CE0

	.loc_0x64:
	  stw       r29, 0x2C(r30)
	  addi      r4, r30, 0
	  li        r5, 0x4
	  lwz       r3, 0x2C(r30)
	  bl        0x7DA4
	  lis       r3, 0x802B
	  addi      r3, r3, 0x1438
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x114
	  lis       r3, 0x8003
	  stw       r0, 0x2B8(r30)
	  subi      r4, r3, 0x7D94
	  addi      r3, r30, 0x3CC
	  li        r5, 0
	  li        r6, 0x10
	  li        r7, 0x4
	  bl        0x178AB0
	  lfs       f0, -0x732C(r2)
	  lis       r3, 0x8003
	  addi      r4, r3, 0x5B24
	  stfs      f0, 0x414(r30)
	  addi      r3, r30, 0x460
	  li        r5, 0
	  stfs      f0, 0x410(r30)
	  li        r6, 0xC
	  li        r7, 0x2
	  stfs      f0, 0x40C(r30)
	  stfs      f0, 0x45C(r30)
	  stfs      f0, 0x458(r30)
	  stfs      f0, 0x454(r30)
	  bl        0x178A78
	  stw       r31, 0x438(r30)
	  li        r3, 0x140
	  lwz       r4, 0x438(r30)
	  lwz       r0, 0x14(r4)
	  ori       r0, r0, 0x10
	  stw       r0, 0x14(r4)
	  bl        -0x55010
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x11C
	  mr        r4, r31
	  bl        -0x3A040
	  lis       r3, 0x802B
	  addi      r0, r3, 0x16A0
	  stw       r0, 0x0(r29)

	.loc_0x11C:
	  stw       r29, 0x434(r30)
	  li        r3, 0x14
	  lwz       r4, 0x434(r30)
	  stw       r30, 0x28(r4)
	  bl        -0x55044
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x144
	  li        r4, 0x14
	  bl        -0x1342C

	.loc_0x144:
	  stw       r29, 0x220(r30)
	  li        r0, 0
	  addi      r3, r30, 0
	  stw       r0, 0x448(r30)
	  stw       r0, 0x450(r30)
	  stw       r0, 0x44C(r30)
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
 * Address:	8009C094
 * Size:	000074
 */
bool HinderRock::insideSafeArea(Vector3f&)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  lfs       f2, 0x98(r3)
	  lfs       f3, 0x9C(r3)
	  lfs       f1, 0x94(r3)
	  lfs       f0, -0x7320(r2)
	  stfs      f1, 0x14(r1)
	  stfs      f2, 0x18(r1)
	  stfs      f3, 0x1C(r1)
	  lfs       f1, 0x40C(r3)
	  stfs      f1, 0x20(r1)
	  lfs       f1, 0x410(r3)
	  stfs      f1, 0x24(r1)
	  lfs       f1, 0x414(r3)
	  addi      r3, r1, 0x14
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  bl        -0x15418
	  lfs       f0, -0x731C(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x60
	  li        r3, 0
	  b         .loc_0x64

	.loc_0x60:
	  li        r3, 0x1

	.loc_0x64:
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009C108
 * Size:	000164
 */
void HinderRock::doLoad(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x43C(r31)
	  li        r0, 0
	  stw       r0, 0x418(r31)
	  sth       r0, 0x3C8(r31)
	  lfs       f0, -0x732C(r2)
	  stfs      f0, 0x440(r31)
	  lbz       r0, 0x43C(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0xA0
	  lwz       r3, 0x40C(r31)
	  li        r4, 0
	  lwz       r0, 0x410(r31)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0x414(r31)
	  stw       r0, 0x9C(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0x34278
	  li        r3, 0x8
	  stfs      f1, 0x98(r31)
	  subfic    r0, r3, 0xA
	  cmpwi     r3, 0xA
	  mtctr     r0
	  bge-      .loc_0x94

	.loc_0x90:
	  bdnz-     .loc_0x90

	.loc_0x94:
	  lwz       r3, 0x424(r31)
	  li        r4, 0x1
	  bl        0x55CC

	.loc_0xA0:
	  lfs       f0, -0x5534(r13)
	  addi      r4, r1, 0x14
	  lfs       f1, -0x5530(r13)
	  addi      r3, r31, 0x228
	  stfs      f0, 0x14(r1)
	  lfs       f0, -0x552C(r13)
	  addi      r5, r31, 0x88
	  stfs      f1, 0x18(r1)
	  addi      r6, r31, 0x94
	  stfs      f0, 0x1C(r1)
	  bl        -0x5E0DC
	  lwz       r4, 0x434(r31)
	  lwz       r3, 0x228(r31)
	  lwz       r0, 0x22C(r31)
	  stw       r3, 0x5C(r4)
	  stw       r0, 0x60(r4)
	  lwz       r3, 0x230(r31)
	  lwz       r0, 0x234(r31)
	  stw       r3, 0x64(r4)
	  stw       r0, 0x68(r4)
	  lwz       r3, 0x238(r31)
	  lwz       r0, 0x23C(r31)
	  stw       r3, 0x6C(r4)
	  stw       r0, 0x70(r4)
	  lwz       r3, 0x240(r31)
	  lwz       r0, 0x244(r31)
	  stw       r3, 0x74(r4)
	  stw       r0, 0x78(r4)
	  lwz       r3, 0x248(r31)
	  lwz       r0, 0x24C(r31)
	  stw       r3, 0x7C(r4)
	  stw       r0, 0x80(r4)
	  lwz       r3, 0x250(r31)
	  lwz       r0, 0x254(r31)
	  stw       r3, 0x84(r4)
	  stw       r0, 0x88(r4)
	  lwz       r3, 0x258(r31)
	  lwz       r0, 0x25C(r31)
	  stw       r3, 0x8C(r4)
	  stw       r0, 0x90(r4)
	  lwz       r3, 0x260(r31)
	  lwz       r0, 0x264(r31)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009C26C
 * Size:	000040
 */
void HinderRock::doSave(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r3)
	  lbz       r4, 0x43C(r31)
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
 * Address:	8009C2AC
 * Size:	000008
 */
f32 HinderRock::getCentreSize()
{
	return 0.0f;
	/*
	.loc_0x0:
	  lfs       f1, 0x430(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009C2B4
 * Size:	000014
 */
bool HinderRock::isFinished()
{
	return false;
	/*
	.loc_0x0:
	  lbz       r0, 0x43C(r3)
	  subfic    r0, r0, 0x2
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009C2C8
 * Size:	0000C8
 */
void HinderRock::getZVector()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stfd      f31, 0xA8(r1)
	  stfd      f30, 0xA0(r1)
	  stfd      f29, 0x98(r1)
	  stw       r31, 0x94(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x90(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x5C
	  bl        0x600
	  lfs       f31, 0x5C(r1)
	  mr        r4, r31
	  lfs       f30, 0x60(r1)
	  addi      r3, r1, 0x50
	  lfs       f29, 0x64(r1)
	  li        r5, 0x3
	  bl        0x5E4
	  lfs       f0, 0x50(r1)
	  lfs       f1, 0x54(r1)
	  fsubs     f31, f0, f31
	  lfs       f0, 0x58(r1)
	  fsubs     f30, f1, f30
	  fsubs     f29, f0, f29
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x8E704
	  lfs       f0, -0x732C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x98
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x98:
	  stfs      f31, 0x0(r30)
	  stfs      f30, 0x4(r30)
	  stfs      f29, 0x8(r30)
	  lwz       r0, 0xB4(r1)
	  lfd       f31, 0xA8(r1)
	  lfd       f30, 0xA0(r1)
	  lfd       f29, 0x98(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009C390
 * Size:	0000C8
 */
void HinderRock::getXVector()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB0(r1)
	  stfd      f31, 0xA8(r1)
	  stfd      f30, 0xA0(r1)
	  stfd      f29, 0x98(r1)
	  stw       r31, 0x94(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x90(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x5C
	  bl        0x538
	  lfs       f31, 0x5C(r1)
	  mr        r4, r31
	  lfs       f30, 0x60(r1)
	  addi      r3, r1, 0x50
	  lfs       f29, 0x64(r1)
	  li        r5, 0x1
	  bl        0x51C
	  lfs       f0, 0x50(r1)
	  lfs       f1, 0x54(r1)
	  fsubs     f31, f0, f31
	  lfs       f0, 0x58(r1)
	  fsubs     f30, f1, f30
	  fsubs     f29, f0, f29
	  fmuls     f1, f31, f31
	  fmuls     f0, f30, f30
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x8E7CC
	  lfs       f0, -0x732C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x98
	  fdivs     f31, f31, f1
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1

	.loc_0x98:
	  stfs      f31, 0x0(r30)
	  stfs      f30, 0x4(r30)
	  stfs      f29, 0x8(r30)
	  lwz       r0, 0xB4(r1)
	  lfd       f31, 0xA8(r1)
	  lfd       f30, 0xA0(r1)
	  lfd       f29, 0x98(r1)
	  lwz       r31, 0x94(r1)
	  lwz       r30, 0x90(r1)
	  addi      r1, r1, 0xB0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void HinderRock::getPlaneIndex(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009C458
 * Size:	0000F8
 */
void HinderRock::getPlaneFlag(Vector3f&)
{
	/*
	.loc_0x0:
	  lfs       f3, 0x3CC(r3)
	  li        r0, 0
	  lfs       f1, 0x0(r4)
	  lfs       f2, 0x3D0(r3)
	  lfs       f0, 0x4(r4)
	  fmuls     f6, f3, f1
	  lfs       f3, 0x3D4(r3)
	  fmuls     f5, f2, f0
	  lfs       f2, 0x8(r4)
	  lfs       f4, 0x3D8(r3)
	  fmuls     f7, f3, f2
	  lfs       f3, -0x732C(r2)
	  fadds     f5, f6, f5
	  fadds     f5, f7, f5
	  fsubs     f4, f5, f4
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x48
	  li        r0, 0x1

	.loc_0x48:
	  lfs       f4, 0x3EC(r3)
	  lfs       f3, 0x3F0(r3)
	  fmuls     f5, f4, f1
	  lfs       f6, 0x3F4(r3)
	  fmuls     f3, f3, f0
	  lfs       f4, 0x3F8(r3)
	  fmuls     f6, f6, f2
	  fadds     f5, f5, f3
	  lfs       f3, -0x732C(r2)
	  fadds     f5, f6, f5
	  fsubs     f4, f5, f4
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x80
	  li        r0, 0x4

	.loc_0x80:
	  lfs       f4, 0x3DC(r3)
	  lfs       f3, 0x3E0(r3)
	  fmuls     f5, f4, f1
	  lfs       f6, 0x3E4(r3)
	  fmuls     f3, f3, f0
	  lfs       f4, 0x3E8(r3)
	  fmuls     f6, f6, f2
	  fadds     f5, f5, f3
	  lfs       f3, -0x732C(r2)
	  fadds     f5, f6, f5
	  fsubs     f4, f5, f4
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0xB8
	  ori       r0, r0, 0x2

	.loc_0xB8:
	  lfs       f4, 0x3FC(r3)
	  lfs       f3, 0x400(r3)
	  fmuls     f4, f4, f1
	  lfs       f5, 0x404(r3)
	  fmuls     f0, f3, f0
	  lfs       f1, 0x408(r3)
	  fmuls     f3, f5, f2
	  fadds     f2, f4, f0
	  lfs       f0, -0x732C(r2)
	  fadds     f2, f3, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xF0
	  ori       r0, r0, 0x8

	.loc_0xF0:
	  mr        r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void HinderRock::getTangentPos(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8009C550
 * Size:	0003A8
 */
void HinderRock::updatePlanes()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1B0(r1)
	  stfd      f31, 0x1A8(r1)
	  stfd      f30, 0x1A0(r1)
	  stfd      f29, 0x198(r1)
	  stfd      f28, 0x190(r1)
	  stfd      f27, 0x188(r1)
	  stfd      f26, 0x180(r1)
	  stfd      f25, 0x178(r1)
	  stfd      f24, 0x170(r1)
	  stw       r31, 0x16C(r1)
	  addi      r31, r3, 0
	  addi      r4, r31, 0
	  addi      r3, r1, 0x134
	  bl        .loc_0x3A8
	  lfs       f1, 0x134(r1)
	  mr        r4, r31
	  lfs       f0, 0x138(r1)
	  addi      r3, r1, 0x128
	  stfs      f1, 0x158(r1)
	  li        r5, 0x2
	  stfs      f0, 0x15C(r1)
	  lfs       f0, 0x13C(r1)
	  stfs      f0, 0x160(r1)
	  bl        .loc_0x3A8
	  lfs       f31, 0x128(r1)
	  mr        r4, r31
	  lfs       f30, 0x12C(r1)
	  addi      r3, r1, 0x11C
	  lfs       f29, 0x130(r1)
	  li        r5, 0x3
	  bl        .loc_0x3A8
	  lfs       f28, 0x11C(r1)
	  lfs       f0, 0x158(r1)
	  lfs       f27, 0x120(r1)
	  fsubs     f0, f0, f28
	  lfs       f26, 0x124(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f0, 0x110(r1)
	  lfs       f25, 0x15C(r1)
	  fsubs     f0, f25, f27
	  stfs      f0, 0x114(r1)
	  lfs       f24, 0x160(r1)
	  fsubs     f0, f24, f26
	  stfs      f0, 0x118(r1)
	  lwz       r3, 0x110(r1)
	  lwz       r0, 0x114(r1)
	  stw       r3, 0x3CC(r31)
	  stw       r0, 0x3D0(r31)
	  lwz       r0, 0x118(r1)
	  stw       r0, 0x3D4(r31)
	  lfs       f1, 0x3CC(r31)
	  lfs       f0, 0x3D0(r31)
	  lfs       f2, 0x3D4(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x8EA08
	  lfs       f0, -0x732C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x12C
	  lfs       f0, 0x3CC(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3CC(r31)
	  lfs       f0, 0x3D0(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3D0(r31)
	  lfs       f0, 0x3D4(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3D4(r31)

	.loc_0x12C:
	  stfs      f1, 0x42C(r31)
	  fsubs     f2, f31, f28
	  fsubs     f1, f30, f27
	  lfs       f5, -0x5528(r13)
	  fsubs     f0, f29, f26
	  lfs       f3, 0x3CC(r31)
	  lfs       f4, 0x3D4(r31)
	  fmuls     f3, f3, f5
	  fmuls     f4, f4, f5
	  stfs      f3, 0xAC(r1)
	  lfs       f3, 0xAC(r1)
	  stfs      f3, 0x104(r1)
	  lfs       f3, 0x3D0(r31)
	  fmuls     f3, f3, f5
	  stfs      f3, 0x108(r1)
	  stfs      f4, 0x10C(r1)
	  lwz       r3, 0x104(r1)
	  lwz       r0, 0x108(r1)
	  stw       r3, 0x3EC(r31)
	  stw       r0, 0x3F0(r31)
	  lwz       r0, 0x10C(r1)
	  stw       r0, 0x3F4(r31)
	  stfs      f2, 0xA0(r1)
	  lfs       f2, 0xA0(r1)
	  stfs      f2, 0xF8(r1)
	  stfs      f1, 0xFC(r1)
	  stfs      f0, 0x100(r1)
	  lwz       r3, 0xF8(r1)
	  lwz       r0, 0xFC(r1)
	  stw       r3, 0x3DC(r31)
	  stw       r0, 0x3E0(r31)
	  lwz       r0, 0x100(r1)
	  stw       r0, 0x3E4(r31)
	  lfs       f1, 0x3DC(r31)
	  lfs       f0, 0x3E0(r31)
	  lfs       f2, 0x3E4(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x8EAE0
	  lfs       f0, -0x732C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x204
	  lfs       f0, 0x3DC(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3DC(r31)
	  lfs       f0, 0x3E0(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3E0(r31)
	  lfs       f0, 0x3E4(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x3E4(r31)

	.loc_0x204:
	  stfs      f1, 0x430(r31)
	  fadds     f2, f31, f28
	  fadds     f1, f30, f27
	  mr        r4, r31
	  lfs       f5, -0x5524(r13)
	  lfs       f0, 0x3DC(r31)
	  lfs       f4, 0x3E4(r31)
	  fmuls     f3, f0, f5
	  addi      r3, r1, 0xC8
	  fmuls     f4, f4, f5
	  li        r5, 0x1
	  fadds     f0, f29, f26
	  stfs      f3, 0x90(r1)
	  lfs       f3, 0x90(r1)
	  stfs      f3, 0xEC(r1)
	  lfs       f3, 0x3E0(r31)
	  fmuls     f3, f3, f5
	  stfs      f3, 0xF0(r1)
	  stfs      f4, 0xF4(r1)
	  lwz       r6, 0xEC(r1)
	  lwz       r0, 0xF0(r1)
	  stw       r6, 0x3FC(r31)
	  stw       r0, 0x400(r31)
	  lwz       r0, 0xF4(r1)
	  stw       r0, 0x404(r31)
	  lfs       f3, 0x3D0(r31)
	  lfs       f6, 0x3D4(r31)
	  lfs       f5, 0x3CC(r31)
	  fmuls     f3, f3, f25
	  lfs       f4, 0x158(r1)
	  fmuls     f6, f6, f24
	  fmuls     f4, f5, f4
	  fadds     f3, f4, f3
	  fadds     f3, f6, f3
	  stfs      f3, 0x3D8(r31)
	  lfs       f4, 0x3DC(r31)
	  lfs       f3, 0x3E0(r31)
	  lfs       f5, 0x3E4(r31)
	  fmuls     f4, f4, f31
	  fmuls     f3, f3, f30
	  fmuls     f5, f5, f29
	  fadds     f3, f4, f3
	  fadds     f3, f5, f3
	  stfs      f3, 0x3E8(r31)
	  lfs       f4, 0x3EC(r31)
	  lfs       f3, 0x3F0(r31)
	  lfs       f5, 0x3F4(r31)
	  fmuls     f4, f4, f28
	  fmuls     f3, f3, f27
	  fmuls     f5, f5, f26
	  fadds     f3, f4, f3
	  fadds     f3, f5, f3
	  stfs      f3, 0x3F8(r31)
	  lfs       f4, 0x3FC(r31)
	  lfs       f3, 0x400(r31)
	  lfs       f5, 0x404(r31)
	  fmuls     f4, f4, f28
	  fmuls     f3, f3, f27
	  fmuls     f5, f5, f26
	  fadds     f3, f4, f3
	  fadds     f3, f5, f3
	  stfs      f3, 0x408(r31)
	  lfs       f3, -0x5520(r13)
	  stfs      f2, 0x84(r1)
	  fmuls     f1, f1, f3
	  lfs       f2, 0x84(r1)
	  fmuls     f0, f0, f3
	  fmuls     f2, f2, f3
	  stfs      f2, 0x70(r1)
	  lfs       f2, 0x70(r1)
	  stfs      f2, 0xE0(r1)
	  stfs      f1, 0xE4(r1)
	  stfs      f0, 0xE8(r1)
	  lwz       r6, 0xE0(r1)
	  lwz       r0, 0xE4(r1)
	  stw       r6, 0x454(r31)
	  stw       r0, 0x458(r31)
	  lwz       r0, 0xE8(r1)
	  stw       r0, 0x45C(r31)
	  lwz       r6, 0x158(r1)
	  lwz       r0, 0x15C(r1)
	  stw       r6, 0x460(r31)
	  stw       r0, 0x464(r31)
	  lwz       r0, 0x160(r1)
	  stw       r0, 0x468(r31)
	  bl        .loc_0x3A8
	  lwz       r3, 0xC8(r1)
	  lwz       r0, 0xCC(r1)
	  stw       r3, 0x46C(r31)
	  stw       r0, 0x470(r31)
	  lwz       r0, 0xD0(r1)
	  stw       r0, 0x474(r31)
	  lwz       r0, 0x1B4(r1)
	  lfd       f31, 0x1A8(r1)
	  lfd       f30, 0x1A0(r1)
	  lfd       f29, 0x198(r1)
	  lfd       f28, 0x190(r1)
	  lfd       f27, 0x188(r1)
	  lfd       f26, 0x180(r1)
	  lfd       f25, 0x178(r1)
	  lfd       f24, 0x170(r1)
	  lwz       r31, 0x16C(r1)
	  addi      r1, r1, 0x1B0
	  mtlr      r0
	  blr

	.loc_0x3A8:
	*/
}

/*
 * --INFO--
 * Address:	8009C8F8
 * Size:	0000A0
 */
void HinderRock::getVertex(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  cmpwi     r5, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  beq-      .loc_0x54
	  bge-      .loc_0x30
	  cmpwi     r5, 0
	  beq-      .loc_0x3C
	  bge-      .loc_0x48
	  b         .loc_0x68

	.loc_0x30:
	  cmpwi     r5, 0x4
	  bge-      .loc_0x68
	  b         .loc_0x60

	.loc_0x3C:
	  lis       r3, 0x7674
	  addi      r0, r3, 0x7830
	  b         .loc_0x68

	.loc_0x48:
	  lis       r3, 0x7674
	  addi      r0, r3, 0x7831
	  b         .loc_0x68

	.loc_0x54:
	  lis       r3, 0x7674
	  addi      r0, r3, 0x7832
	  b         .loc_0x68

	.loc_0x60:
	  lis       r3, 0x7674
	  addi      r0, r3, 0x7833

	.loc_0x68:
	  lwz       r3, 0x220(r4)
	  mr        r4, r0
	  bl        -0x13258
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x8(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009C998
 * Size:	000074
 */
void HinderRock::stimulate(Interaction&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x5C

	.loc_0x44:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009CA0C
 * Size:	000018
 */
bool InteractPush::actHinderRock(HinderRock*)
{
	return true;
	/*
	.loc_0x0:
	  lwz       r0, 0x8(r3)
	  li        r3, 0x1
	  lwz       r5, 0x418(r4)
	  add       r0, r5, r0
	  stw       r0, 0x418(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009CA24
 * Size:	0000C0
 */
void HinderRock::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r4
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x2E4(r4)
	  addi      r4, r30, 0x228
	  addi      r3, r5, 0x1E0
	  addi      r5, r1, 0x10
	  bl        -0x5E97C
	  lwz       r3, 0x438(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x10
	  li        r6, 0
	  bl        -0x67750
	  lwz       r4, 0x434(r30)
	  addi      r3, r4, 0x5C
	  addi      r4, r4, 0x9C
	  bl        -0x5E638
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x434(r30)
	  bl        -0x3AB88
	  lwz       r3, 0x438(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0x6C644
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x12FD4
	  mr        r3, r30
	  bl        -0x578
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009CAE4
 * Size:	00011C
 */
bool HinderRock::workable(Vector3f&)
{
	return false;
	/*
	.loc_0x0:
	  lfs       f3, 0x3CC(r3)
	  li        r0, 0
	  lfs       f1, 0x0(r4)
	  lfs       f2, 0x3D0(r3)
	  lfs       f0, 0x4(r4)
	  fmuls     f6, f3, f1
	  lfs       f3, 0x3D4(r3)
	  fmuls     f5, f2, f0
	  lfs       f2, 0x8(r4)
	  lfs       f4, 0x3D8(r3)
	  fmuls     f7, f3, f2
	  lfs       f3, -0x732C(r2)
	  fadds     f5, f6, f5
	  fadds     f5, f7, f5
	  fsubs     f4, f5, f4
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x48
	  li        r0, 0x1

	.loc_0x48:
	  lfs       f4, 0x3EC(r3)
	  lfs       f3, 0x3F0(r3)
	  fmuls     f5, f4, f1
	  lfs       f6, 0x3F4(r3)
	  fmuls     f3, f3, f0
	  lfs       f4, 0x3F8(r3)
	  fmuls     f6, f6, f2
	  fadds     f5, f5, f3
	  lfs       f3, -0x732C(r2)
	  fadds     f5, f6, f5
	  fsubs     f4, f5, f4
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0x80
	  li        r0, 0x4

	.loc_0x80:
	  lfs       f4, 0x3DC(r3)
	  lfs       f3, 0x3E0(r3)
	  fmuls     f5, f4, f1
	  lfs       f6, 0x3E4(r3)
	  fmuls     f3, f3, f0
	  lfs       f4, 0x3E8(r3)
	  fmuls     f6, f6, f2
	  fadds     f5, f5, f3
	  lfs       f3, -0x732C(r2)
	  fadds     f5, f6, f5
	  fsubs     f4, f5, f4
	  fcmpo     cr0, f4, f3
	  ble-      .loc_0xB8
	  ori       r0, r0, 0x2

	.loc_0xB8:
	  lfs       f4, 0x3FC(r3)
	  lfs       f3, 0x400(r3)
	  fmuls     f4, f4, f1
	  lfs       f5, 0x404(r3)
	  fmuls     f0, f3, f0
	  lfs       f1, 0x408(r3)
	  fmuls     f3, f5, f2
	  fadds     f2, f4, f0
	  lfs       f0, -0x732C(r2)
	  fadds     f2, f3, f2
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xF0
	  ori       r0, r0, 0x8

	.loc_0xF0:
	  rlwinm    r0,r0,0,24,31
	  cmplwi    r0, 0x6
	  beq-      .loc_0x114
	  cmplwi    r0, 0x4
	  beq-      .loc_0x114
	  cmplwi    r0, 0xC
	  beq-      .loc_0x114
	  li        r3, 0
	  blr

	.loc_0x114:
	  li        r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009CC00
 * Size:	000830
 */
void HinderRock::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1D8(r1)
	  stfd      f31, 0x1D0(r1)
	  stfd      f30, 0x1C8(r1)
	  stfd      f29, 0x1C0(r1)
	  stw       r31, 0x1BC(r1)
	  mr        r31, r3
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x30
	  bl        0x72C0

	.loc_0x30:
	  lwz       r6, 0x94(r31)
	  li        r0, 0
	  lwz       r5, 0x98(r31)
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  stw       r6, 0x1E0(r31)
	  stw       r5, 0x1E4(r31)
	  lwz       r5, 0x9C(r31)
	  stw       r5, 0x1E8(r31)
	  lfs       f1, 0x1E4(r31)
	  lfs       f0, -0x7308(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1E4(r31)
	  stb       r0, 0x444(r31)
	  bl        -0x8748
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  li        r5, 0
	  bl        -0x86BC
	  lhz       r5, 0x3C8(r31)
	  cmplwi    r5, 0
	  beq-      .loc_0x98
	  addi      r3, r31, 0x1E0
	  lwz       r6, 0x41C(r31)
	  mr        r4, r3
	  bl        -0x3FD28

	.loc_0x98:
	  lhz       r0, 0x3C8(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x118
	  lbz       r3, 0x43D(r31)
	  addi      r3, r3, 0x1
	  rlwinm    r0,r3,0,24,31
	  stb       r3, 0x43D(r31)
	  cmplwi    r0, 0xA
	  ble-      .loc_0x120
	  li        r0, 0xA
	  stb       r0, 0x43D(r31)
	  addi      r3, r31, 0x1E0
	  bl        -0x3FC14
	  lwz       r3, 0x448(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xE4
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0xE4:
	  lwz       r3, 0x44C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xFC
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0xFC:
	  lwz       r3, 0x450(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x120
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)
	  b         .loc_0x120

	.loc_0x118:
	  li        r0, 0
	  stb       r0, 0x43D(r31)

	.loc_0x120:
	  lbz       r4, 0x43C(r31)
	  cmplwi    r4, 0
	  bne-      .loc_0x740
	  lhz       r3, 0x3C8(r31)
	  lwz       r0, 0x41C(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x740
	  lwz       r3, 0x448(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x264
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x454
	  li        r4, 0xDA
	  li        r6, 0
	  li        r7, 0
	  bl        0xFFDDC
	  stw       r3, 0x448(r31)
	  lwz       r3, 0x448(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x270
	  addi      r0, r31, 0x454
	  stw       r0, 0x18(r3)
	  addi      r4, r31, 0
	  addi      r3, r1, 0xC4
	  li        r5, 0
	  bl        -0x48C
	  lfs       f31, 0xC4(r1)
	  mr        r4, r31
	  lfs       f30, 0xC8(r1)
	  addi      r3, r1, 0xD0
	  lfs       f29, 0xCC(r1)
	  li        r5, 0x1
	  bl        -0x4A8
	  lfs       f2, 0xD8(r1)
	  addi      r6, r1, 0x90
	  lfs       f1, 0xD4(r1)
	  addi      r5, r1, 0x8C
	  lfs       f0, 0xD0(r1)
	  fsubs     f2, f2, f29
	  addi      r4, r1, 0x88
	  fsubs     f1, f1, f30
	  addi      r3, r1, 0xDC
	  fsubs     f0, f0, f31
	  stfs      f2, 0x90(r1)
	  stfs      f1, 0x8C(r1)
	  stfs      f0, 0x88(r1)
	  bl        -0x65CBC
	  lfs       f1, 0xDC(r1)
	  lfs       f0, 0xE0(r1)
	  stfs      f1, 0xB8(r1)
	  stfs      f0, 0xBC(r1)
	  lfs       f0, 0xE4(r1)
	  stfs      f0, 0xC0(r1)
	  lfs       f1, 0xB8(r1)
	  lfs       f0, 0xBC(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xC0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x8F1D4
	  lfs       f0, -0x732C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x22C
	  addi      r3, r1, 0xB8
	  bl        -0x138DC

	.loc_0x22C:
	  lfs       f0, 0xB8(r1)
	  stfs      f0, 0x184(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f0, 0x188(r1)
	  lfs       f0, 0xC0(r1)
	  stfs      f0, 0x18C(r1)
	  lwz       r4, 0x448(r31)
	  lwz       r3, 0x184(r1)
	  lwz       r0, 0x188(r1)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x18C(r1)
	  stw       r0, 0xA8(r4)
	  b         .loc_0x270

	.loc_0x264:
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x270:
	  lwz       r3, 0x44C(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x2E8
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x460
	  li        r4, 0xDB
	  li        r6, 0
	  li        r7, 0
	  bl        0xFFCA8
	  stw       r3, 0x44C(r31)
	  lwz       r3, 0x44C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x2F4
	  addi      r0, r31, 0x460
	  stw       r0, 0x18(r3)
	  lfs       f4, -0x551C(r13)
	  lfs       f0, 0x3FC(r31)
	  lfs       f1, 0x400(r31)
	  lfs       f2, 0x404(r31)
	  fmuls     f0, f0, f4
	  lwz       r3, 0x44C(r31)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x12C(r3)
	  stfs      f3, 0x130(r3)
	  stfs      f1, 0x134(r3)
	  lwz       r0, 0x84(r3)
	  oris      r0, r0, 0x1
	  stw       r0, 0x84(r3)
	  b         .loc_0x2F4

	.loc_0x2E8:
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x2F4:
	  lwz       r3, 0x450(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x36C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x46C
	  li        r4, 0xDB
	  li        r6, 0
	  li        r7, 0
	  bl        0xFFC24
	  stw       r3, 0x450(r31)
	  lwz       r3, 0x450(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x378
	  addi      r0, r31, 0x46C
	  stw       r0, 0x18(r3)
	  lfs       f4, -0x5518(r13)
	  lfs       f0, 0x3DC(r31)
	  lfs       f1, 0x3E0(r31)
	  lfs       f2, 0x3E4(r31)
	  fmuls     f0, f0, f4
	  lwz       r3, 0x450(r31)
	  fmuls     f3, f1, f4
	  fmuls     f1, f2, f4
	  stfs      f0, 0x12C(r3)
	  stfs      f3, 0x130(r3)
	  stfs      f1, 0x134(r3)
	  lwz       r0, 0x84(r3)
	  oris      r0, r0, 0x1
	  stw       r0, 0x84(r3)
	  b         .loc_0x378

	.loc_0x36C:
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)

	.loc_0x378:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  lhz       r0, 0x26(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x3BC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xE
	  addi      r3, r3, 0x54
	  bl        -0x1AAD8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3BC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xE
	  li        r5, 0
	  addi      r3, r3, 0x54
	  bl        -0x1AA9C

	.loc_0x3BC:
	  li        r0, 0x1
	  stb       r0, 0x444(r31)
	  lfs       f1, 0x40C(r31)
	  lfs       f0, 0x94(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x108(r1)
	  lfs       f0, 0x108(r1)
	  stfs      f0, 0x148(r1)
	  lfs       f1, 0x410(r31)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14C(r1)
	  lfs       f1, 0x414(r31)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x150(r1)
	  lwz       r3, 0x148(r1)
	  lwz       r0, 0x14C(r1)
	  stw       r3, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x150(r1)
	  stw       r0, 0x78(r31)
	  lfs       f0, 0x70(r31)
	  lfs       f1, 0x78(r31)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x732C(r2)
	  fmuls     f1, f1, f1
	  fadds     f4, f2, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x48C
	  fsqrte    f1, f4
	  lfd       f3, -0x7318(r2)
	  lfd       f2, -0x7310(r2)
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
	  stfs      f0, 0x104(r1)
	  lfs       f4, 0x104(r1)

	.loc_0x48C:
	  lfs       f0, -0x7304(r2)
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x568
	  lwz       r5, 0x40C(r31)
	  li        r0, 0x2
	  lwz       r3, 0x410(r31)
	  li        r4, 0x1
	  stw       r5, 0x94(r31)
	  stw       r3, 0x98(r31)
	  lwz       r3, 0x414(r31)
	  stw       r3, 0x9C(r31)
	  stb       r0, 0x43C(r31)
	  lwz       r3, 0x424(r31)
	  bl        0x46B0
	  li        r3, 0x11B
	  bl        0x82AC
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xF
	  addi      r3, r3, 0x54
	  bl        -0x1AC14
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x4F8
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xF
	  li        r5, 0
	  addi      r3, r3, 0x54
	  bl        -0x1ABD8

	.loc_0x4F8:
	  lwz       r4, 0x448(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x51C
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x1044B4
	  li        r0, 0
	  stw       r0, 0x448(r31)

	.loc_0x51C:
	  lwz       r4, 0x44C(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x540
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x104490
	  li        r0, 0
	  stw       r0, 0x44C(r31)

	.loc_0x540:
	  lwz       r4, 0x450(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0x810
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0x10446C
	  li        r0, 0
	  stw       r0, 0x450(r31)
	  b         .loc_0x810

	.loc_0x568:
	  lfs       f1, 0x70(r31)
	  lfs       f0, 0x74(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x8F548
	  lfs       f0, -0x732C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x5BC
	  lfs       f0, 0x70(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x74(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x74(r31)
	  lfs       f0, 0x78(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x78(r31)

	.loc_0x5BC:
	  lfs       f2, -0x7300(r2)
	  mr        r3, r31
	  lfs       f1, 0x420(r31)
	  lfs       f0, 0x70(r31)
	  fmuls     f1, f2, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x70(r31)
	  lfs       f0, 0x74(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x74(r31)
	  lfs       f0, 0x78(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x78(r31)
	  lwz       r4, 0x2DEC(r13)
	  lfs       f1, 0x28C(r4)
	  bl        -0xEC1C
	  lfs       f0, -0x5514(r13)
	  addi      r4, r1, 0x13C
	  lfs       f1, -0x5510(r13)
	  addi      r3, r31, 0x228
	  stfs      f0, 0x13C(r1)
	  lfs       f0, -0x550C(r13)
	  addi      r5, r31, 0x88
	  stfs      f1, 0x140(r1)
	  addi      r6, r31, 0x94
	  stfs      f0, 0x144(r1)
	  bl        -0x5F130
	  lwz       r4, 0x434(r31)
	  lwz       r3, 0x228(r31)
	  lwz       r0, 0x22C(r31)
	  stw       r3, 0x5C(r4)
	  stw       r0, 0x60(r4)
	  lwz       r3, 0x230(r31)
	  lwz       r0, 0x234(r31)
	  stw       r3, 0x64(r4)
	  stw       r0, 0x68(r4)
	  lwz       r3, 0x238(r31)
	  lwz       r0, 0x23C(r31)
	  stw       r3, 0x6C(r4)
	  stw       r0, 0x70(r4)
	  lwz       r3, 0x240(r31)
	  lwz       r0, 0x244(r31)
	  stw       r3, 0x74(r4)
	  stw       r0, 0x78(r4)
	  lwz       r3, 0x248(r31)
	  lwz       r0, 0x24C(r31)
	  stw       r3, 0x7C(r4)
	  stw       r0, 0x80(r4)
	  lwz       r3, 0x250(r31)
	  lwz       r0, 0x254(r31)
	  stw       r3, 0x84(r4)
	  stw       r0, 0x88(r4)
	  lwz       r3, 0x258(r31)
	  lwz       r0, 0x25C(r31)
	  stw       r3, 0x8C(r4)
	  stw       r0, 0x90(r4)
	  lwz       r3, 0x260(r31)
	  lwz       r0, 0x264(r31)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x440(r31)
	  lfs       f0, 0x28C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x440(r31)
	  lbz       r0, 0x445(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x6E0
	  lwz       r3, 0x2C(r31)
	  li        r4, 0xAE
	  bl        0x6AFC
	  li        r0, 0x1
	  stb       r0, 0x445(r31)

	.loc_0x6E0:
	  lfs       f1, 0x440(r31)
	  lfs       f0, -0x7320(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x808
	  li        r0, 0x1
	  stb       r0, 0x43C(r31)
	  bl        0x17AD78
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x7328(r2)
	  stw       r0, 0x1B4(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x72FC(r2)
	  stw       r0, 0x1B0(r1)
	  lfs       f2, -0x7320(r2)
	  lfd       f1, 0x1B0(r1)
	  lfs       f0, -0x72F4(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x72F8(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x440(r31)
	  b         .loc_0x808

	.loc_0x740:
	  cmplwi    r4, 0x1
	  bne-      .loc_0x7A0
	  li        r4, 0
	  stb       r4, 0x445(r31)
	  li        r0, 0x1
	  stb       r0, 0x444(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x440(r31)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x440(r31)
	  lfs       f1, 0x440(r31)
	  lfs       f0, -0x732C(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x788
	  stb       r4, 0x43C(r31)
	  stfs      f0, 0x440(r31)

	.loc_0x788:
	  addi      r3, r31, 0x1E0
	  lhz       r5, 0x3C8(r31)
	  lwz       r6, 0x41C(r31)
	  mr        r4, r3
	  bl        -0x4042C
	  b         .loc_0x808

	.loc_0x7A0:
	  lfs       f0, 0x70(r31)
	  lfs       f1, 0x78(r31)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x7320(r2)
	  fmuls     f1, f1, f1
	  fadds     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x808
	  lwz       r3, 0x448(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x7D8
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x7D8:
	  lwz       r3, 0x44C(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x7F0
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x7F0:
	  lwz       r3, 0x450(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x808
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)

	.loc_0x808:
	  li        r0, 0
	  stw       r0, 0x418(r31)

	.loc_0x810:
	  lwz       r0, 0x1DC(r1)
	  lfd       f31, 0x1D0(r1)
	  lfd       f30, 0x1C8(r1)
	  lfd       f29, 0x1C0(r1)
	  lwz       r31, 0x1BC(r1)
	  addi      r1, r1, 0x1D8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009D430
 * Size:	000198
 */
void HinderRock::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  li        r31, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  sth       r31, 0x3C8(r3)
	  stb       r31, 0x43D(r3)
	  stb       r31, 0x428(r3)
	  lwz       r3, 0x220(r3)
	  lwz       r4, 0x438(r30)
	  bl        -0x13904
	  lfs       f3, 0x40C(r30)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x414(r30)
	  lfs       f0, 0x9C(r30)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0x17E574
	  stfs      f1, 0xA0(r30)
	  addi      r4, r1, 0x2C
	  addi      r3, r30, 0x228
	  lfs       f0, -0x5508(r13)
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  stfs      f0, 0x88(r30)
	  stfs      f1, 0x8C(r30)
	  lfs       f0, -0x5504(r13)
	  stfs      f0, 0x90(r30)
	  lfs       f0, -0x5500(r13)
	  lfs       f1, -0x54FC(r13)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, -0x54F8(r13)
	  stfs      f1, 0x30(r1)
	  stfs      f0, 0x34(r1)
	  bl        -0x5F3D4
	  lwz       r4, 0x434(r30)
	  lwz       r3, 0x228(r30)
	  lwz       r0, 0x22C(r30)
	  stw       r3, 0x5C(r4)
	  stw       r0, 0x60(r4)
	  lwz       r3, 0x230(r30)
	  lwz       r0, 0x234(r30)
	  stw       r3, 0x64(r4)
	  stw       r0, 0x68(r4)
	  lwz       r3, 0x238(r30)
	  lwz       r0, 0x23C(r30)
	  stw       r3, 0x6C(r4)
	  stw       r0, 0x70(r4)
	  lwz       r3, 0x240(r30)
	  lwz       r0, 0x244(r30)
	  stw       r3, 0x74(r4)
	  stw       r0, 0x78(r4)
	  lwz       r3, 0x248(r30)
	  lwz       r0, 0x24C(r30)
	  stw       r3, 0x7C(r4)
	  stw       r0, 0x80(r4)
	  lwz       r3, 0x250(r30)
	  lwz       r0, 0x254(r30)
	  stw       r3, 0x84(r4)
	  stw       r0, 0x88(r4)
	  lwz       r3, 0x258(r30)
	  lwz       r0, 0x25C(r30)
	  stw       r3, 0x8C(r4)
	  stw       r0, 0x90(r4)
	  lwz       r3, 0x260(r30)
	  lwz       r0, 0x264(r30)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r3, 0x2F00(r13)
	  lwz       r4, 0x434(r30)
	  lwz       r3, 0x88(r3)
	  bl        -0x5CF84
	  stw       r31, 0x418(r30)
	  lis       r3, 0x7465
	  addi      r4, r3, 0x7374
	  stb       r31, 0x43C(r30)
	  addi      r5, r30, 0x94
	  lfs       f0, -0x732C(r2)
	  stfs      f0, 0x440(r30)
	  lwz       r3, 0x302C(r13)
	  bl        0x3FBC
	  stw       r3, 0x424(r30)
	  li        r4, 0
	  lwz       r3, 0x424(r30)
	  bl        0x41E0
	  stb       r31, 0x445(r30)
	  li        r4, 0
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  bl        -0x356A4
	  stfs      f1, 0x98(r30)
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009D5C8
 * Size:	000154
 */
bool Bridge::workable(Vector3f&)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  addi      r5, r1, 0x1C
	  addi      r6, r1, 0x18
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  bl        0x1484
	  mr        r3, r30
	  bl        0xC44
	  addi      r4, r3, 0
	  cmpwi     r4, -0x1
	  bne-      .loc_0x48
	  li        r3, 0
	  b         .loc_0x138

	.loc_0x48:
	  mr        r3, r30
	  bl        0x13FC
	  lfs       f2, -0x72F0(r2)
	  lfs       f3, 0x18(r1)
	  fadds     f0, f2, f1
	  fsubs     f2, f3, f2
	  stfs      f2, 0x18(r1)
	  lfs       f2, 0x18(r1)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x78
	  li        r3, 0
	  b         .loc_0x138

	.loc_0x78:
	  lfs       f0, -0x732C(r2)
	  fcmpo     cr0, f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xF4
	  fcmpo     cr0, f2, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0xF4
	  lfs       f0, 0x1C(r1)
	  mr        r3, r30
	  fabs      f31, f0
	  bl        0x16B8
	  lfs       f0, -0x7300(r2)
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xC0
	  li        r3, 0
	  b         .loc_0x138

	.loc_0xC0:
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x0(r31)
	  lfs       f2, 0x8(r31)
	  bl        -0x35794
	  lfs       f2, -0x72F0(r2)
	  lfs       f0, 0x4(r31)
	  fsubs     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x108
	  li        r3, 0
	  b         .loc_0x138

	.loc_0xF4:
	  lfs       f0, -0x72EC(r2)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x108
	  li        r3, 0
	  b         .loc_0x138

	.loc_0x108:
	  lfs       f0, 0x1C(r1)
	  mr        r3, r30
	  fabs      f31, f0
	  bl        0x1644
	  lfs       f0, -0x72E8(r2)
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f31, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x134
	  li        r3, 0
	  b         .loc_0x138

	.loc_0x134:
	  li        r3, 0x1

	.loc_0x138:
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009D71C
 * Size:	0002C4
 */
Bridge::Bridge(Shape*, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  li        r4, 0x26
	  stw       r30, 0x28(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x24(r1)
	  stw       r28, 0x20(r1)
	  addi      r28, r5, 0
	  li        r5, 0
	  bl        0x5815C
	  lis       r3, 0x802B
	  addi      r3, r3, 0x1944
	  stw       r3, 0x0(r30)
	  addi      r3, r3, 0x114
	  li        r0, 0x26
	  stw       r3, 0x2B8(r30)
	  li        r3, 0x28
	  stw       r0, 0x6C(r30)
	  bl        -0x56770
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x6C
	  bl        0x64D8

	.loc_0x6C:
	  stw       r29, 0x2C(r30)
	  addi      r4, r30, 0
	  li        r5, 0x4
	  lwz       r3, 0x2C(r30)
	  bl        0x659C
	  lis       r3, 0x802B
	  addi      r3, r3, 0x123C
	  stw       r3, 0x0(r30)
	  addi      r0, r3, 0x114
	  addi      r3, r30, 0x3D8
	  stw       r0, 0x2B8(r30)
	  bl        0x76BB4
	  addi      r3, r30, 0x3E8
	  bl        0x76BAC
	  li        r0, 0
	  stw       r0, 0x414(r30)
	  li        r3, 0x140
	  stw       r0, 0x418(r30)
	  stw       r0, 0x41C(r30)
	  stw       r0, 0x420(r30)
	  stb       r28, 0x3C8(r30)
	  stw       r31, 0x40C(r30)
	  lwz       r4, 0x40C(r30)
	  lwz       r0, 0x14(r4)
	  ori       r0, r0, 0x10
	  stw       r0, 0x14(r4)
	  lwz       r4, 0x40C(r30)
	  lwz       r0, 0x14(r4)
	  ori       r0, r0, 0x4
	  stw       r0, 0x14(r4)
	  bl        -0x567FC
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x108
	  mr        r4, r31
	  bl        -0x3B82C
	  lis       r3, 0x802B
	  addi      r0, r3, 0x16A0
	  stw       r0, 0x0(r29)

	.loc_0x108:
	  stw       r29, 0x408(r30)
	  lwz       r3, 0x408(r30)
	  stw       r30, 0x28(r3)
	  lbz       r0, 0x3C8(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x23C
	  lwz       r3, 0x5C(r31)
	  bl        -0x5D1C0
	  srawi     r0, r3, 0x1
	  addze     r0, r0
	  stw       r0, 0x404(r30)
	  lwz       r0, 0x404(r30)
	  rlwinm    r3,r0,3,0,28
	  bl        -0x56854
	  stw       r3, 0x3D4(r30)
	  lwz       r0, 0x404(r30)
	  lwz       r4, 0x5C(r31)
	  rlwinm    r3,r0,1,0,30
	  subic.    r3, r3, 0x1
	  lwz       r6, 0x10(r4)
	  rlwinm    r5,r3,2,0,29
	  addi      r3, r3, 0x1
	  blt-      .loc_0x290
	  rlwinm.   r0,r3,29,3,31
	  mtctr     r0
	  beq-      .loc_0x21C

	.loc_0x170:
	  lwz       r0, 0x10(r6)
	  lwz       r4, 0x3D4(r30)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  lwz       r4, 0x3D4(r30)
	  lwz       r0, 0x10(r6)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  lwz       r4, 0x3D4(r30)
	  lwz       r0, 0x10(r6)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  lwz       r4, 0x3D4(r30)
	  lwz       r0, 0x10(r6)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  lwz       r4, 0x3D4(r30)
	  lwz       r0, 0x10(r6)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  lwz       r4, 0x3D4(r30)
	  lwz       r0, 0x10(r6)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  lwz       r4, 0x3D4(r30)
	  lwz       r0, 0x10(r6)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  lwz       r4, 0x3D4(r30)
	  lwz       r0, 0x10(r6)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  bdnz+     .loc_0x170
	  andi.     r3, r3, 0x7
	  beq-      .loc_0x290

	.loc_0x21C:
	  mtctr     r3

	.loc_0x220:
	  lwz       r0, 0x10(r6)
	  lwz       r4, 0x3D4(r30)
	  stwx      r0, r4, r5
	  subi      r5, r5, 0x4
	  lwz       r6, 0xC(r6)
	  bdnz+     .loc_0x220
	  b         .loc_0x290

	.loc_0x23C:
	  li        r3, 0x14
	  bl        -0x56958
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x258
	  li        r4, 0x14
	  bl        -0x14D40

	.loc_0x258:
	  stw       r29, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r3, 0x220(r30)
	  li        r6, 0
	  bl        -0x13E24
	  lis       r4, 0x7265
	  lwz       r3, 0x220(r30)
	  addi      r4, r4, 0x6673
	  bl        -0x14288
	  stw       r3, 0x410(r30)
	  lwz       r3, 0x410(r30)
	  bl        -0x15C14
	  stw       r3, 0x404(r30)

	.loc_0x290:
	  lwz       r0, 0x404(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x569B0
	  stw       r3, 0x3D0(r30)
	  mr        r3, r30
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  lwz       r28, 0x20(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009D9E0
 * Size:	000074
 */
void Bridge::stimulate(Interaction&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x44
	  li        r3, 0
	  b         .loc_0x5C

	.loc_0x44:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl

	.loc_0x5C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009DA54
 * Size:	0000E4
 */
void Bridge::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r4
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  lwz       r5, 0x2E4(r4)
	  addi      r4, r30, 0x228
	  addi      r3, r5, 0x1E0
	  addi      r5, r1, 0x10
	  bl        -0x5F9AC
	  lwz       r3, 0x40C(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x10
	  li        r6, 0
	  bl        -0x68780
	  lwz       r4, 0x408(r30)
	  addi      r3, r4, 0x5C
	  addi      r4, r4, 0x9C
	  bl        -0x5F668
	  addi      r3, r30, 0x414
	  li        r4, 0
	  bl        -0x6EA14
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x408(r30)
	  bl        -0x3BBC4
	  lwz       r3, 0x40C(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  addi      r6, r30, 0x414
	  bl        -0x6D680
	  lbz       r0, 0x3C8(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0xB8
	  lwz       r3, 0x220(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0x1401C

	.loc_0xB8:
	  lbz       r3, 0x424(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  subi      r0, r3, 0x1
	  stb       r0, 0x424(r30)

	.loc_0xCC:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009DB38
 * Size:	0000E0
 */
void Bridge::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x24
	  bl        0x6394

	.loc_0x24:
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  bl        -0x9644
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  li        r5, 0
	  bl        -0x95B8
	  lbz       r3, 0x3CC(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0xCC
	  subi      r0, r3, 0x1
	  stb       r0, 0x3CC(r31)
	  lbz       r0, 0x3CC(r31)
	  cmplwi    r0, 0x1E
	  bgt-      .loc_0xCC
	  lha       r4, 0x3CA(r31)
	  cmpwi     r4, -0x1
	  beq-      .loc_0xCC
	  addi      r3, r31, 0
	  li        r5, 0x1
	  bl        0xA08
	  li        r0, -0x1
	  sth       r0, 0x3CA(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xCC
	  lwz       r3, 0x3F8(r31)
	  li        r4, 0x1
	  bl        0x3B94
	  lwz       r3, 0x3FC(r31)
	  li        r4, 0x1
	  bl        0x3B88
	  li        r3, 0x11B
	  bl        0x7784
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0x20
	  addi      r3, r3, 0x70
	  bl        -0x1A200

	.loc_0xCC:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009DC18
 * Size:	000300
 */
void Bridge::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x3
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  stb       r0, 0x424(r3)
	  lbz       r0, 0x3C8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x48
	  lwz       r3, 0x220(r31)
	  li        r5, 0
	  lwz       r4, 0x40C(r31)
	  li        r6, 0
	  bl        -0x140F8

	.loc_0x48:
	  lwz       r3, 0x40C(r31)
	  addi      r4, r31, 0x414
	  li        r5, 0
	  bl        -0x6E340
	  lfs       f0, -0x54F4(r13)
	  addi      r4, r1, 0x28
	  lfs       f1, -0x54F0(r13)
	  addi      r3, r31, 0x228
	  stfs      f0, 0x28(r1)
	  lfs       f0, -0x54EC(r13)
	  addi      r5, r31, 0x88
	  stfs      f1, 0x2C(r1)
	  addi      r6, r31, 0x94
	  stfs      f0, 0x30(r1)
	  bl        -0x5FBA4
	  lwz       r4, 0x408(r31)
	  lwz       r3, 0x228(r31)
	  lwz       r0, 0x22C(r31)
	  stw       r3, 0x5C(r4)
	  stw       r0, 0x60(r4)
	  lwz       r3, 0x230(r31)
	  lwz       r0, 0x234(r31)
	  stw       r3, 0x64(r4)
	  stw       r0, 0x68(r4)
	  lwz       r3, 0x238(r31)
	  lwz       r0, 0x23C(r31)
	  stw       r3, 0x6C(r4)
	  stw       r0, 0x70(r4)
	  lwz       r3, 0x240(r31)
	  lwz       r0, 0x244(r31)
	  stw       r3, 0x74(r4)
	  stw       r0, 0x78(r4)
	  lwz       r3, 0x248(r31)
	  lwz       r0, 0x24C(r31)
	  stw       r3, 0x7C(r4)
	  stw       r0, 0x80(r4)
	  lwz       r3, 0x250(r31)
	  lwz       r0, 0x254(r31)
	  stw       r3, 0x84(r4)
	  stw       r0, 0x88(r4)
	  lwz       r3, 0x258(r31)
	  lwz       r0, 0x25C(r31)
	  stw       r3, 0x8C(r4)
	  stw       r0, 0x90(r4)
	  lwz       r3, 0x260(r31)
	  lwz       r0, 0x264(r31)
	  stw       r3, 0x94(r4)
	  stw       r0, 0x98(r4)
	  lwz       r3, 0x2F00(r13)
	  lwz       r4, 0x408(r31)
	  lwz       r3, 0x88(r3)
	  bl        -0x5D754
	  lbz       r0, 0x3C8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C0
	  lfs       f0, -0x732C(r2)
	  li        r5, 0
	  li        r4, 0
	  b         .loc_0x144

	.loc_0x134:
	  lwz       r3, 0x3D0(r31)
	  addi      r5, r5, 0x1
	  stfsx     f0, r3, r4
	  addi      r4, r4, 0x4

	.loc_0x144:
	  lwz       r0, 0x404(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x134
	  li        r29, 0
	  rlwinm    r30,r29,2,0,29
	  b         .loc_0x188

	.loc_0x15C:
	  lwz       r3, 0x408(r31)
	  li        r5, 0
	  lwz       r4, 0x3D4(r31)
	  lwz       r12, 0x0(r3)
	  lwzx      r4, r4, r30
	  lwz       r12, 0x40(r12)
	  lwz       r4, 0x14(r4)
	  mtlr      r12
	  blrl
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x1

	.loc_0x188:
	  lwz       r0, 0x404(r31)
	  rlwinm    r0,r0,1,0,30
	  cmpw      r29, r0
	  blt+      .loc_0x15C
	  lwz       r3, 0x408(r31)
	  li        r5, 0x1
	  lwz       r4, 0x3D4(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r4, 0x0(r4)
	  lwz       r12, 0x40(r12)
	  lwz       r4, 0x14(r4)
	  mtlr      r12
	  blrl
	  b         .loc_0x1FC

	.loc_0x1C0:
	  lfs       f31, -0x732C(r2)
	  li        r29, 0
	  li        r30, 0
	  b         .loc_0x1F0

	.loc_0x1D0:
	  lwz       r5, 0x3D0(r31)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  stfsx     f31, r5, r30
	  li        r5, 0
	  bl        0x7B8
	  addi      r30, r30, 0x4
	  addi      r29, r29, 0x1

	.loc_0x1F0:
	  lwz       r0, 0x404(r31)
	  cmpw      r29, r0
	  blt+      .loc_0x1D0

	.loc_0x1FC:
	  lis       r30, 0x7465
	  lwz       r3, 0x302C(r13)
	  addi      r4, r30, 0x7374
	  addi      r5, r31, 0x94
	  bl        0x3718
	  stw       r3, 0x3F8(r31)
	  addi      r4, r31, 0
	  addi      r3, r1, 0x1C
	  lwz       r5, 0x3F8(r31)
	  lbz       r0, 0x40(r5)
	  ori       r0, r0, 0x4
	  stb       r0, 0x40(r5)
	  bl        0xDD8
	  lwz       r5, 0x3F8(r31)
	  li        r4, 0
	  lwz       r3, 0x1C(r1)
	  lwz       r0, 0x20(r1)
	  stw       r3, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0x24(r1)
	  stw       r0, 0x8(r5)
	  lwz       r3, 0x3F8(r31)
	  bl        0x3904
	  lwz       r5, 0x404(r31)
	  addi      r4, r31, 0
	  addi      r3, r1, 0x10
	  subi      r5, r5, 0x1
	  bl        0xAC8
	  lfs       f0, 0x10(r1)
	  addi      r4, r30, 0x7374
	  lfs       f1, 0x14(r1)
	  addi      r5, r1, 0x34
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x18(r1)
	  stfs      f1, 0x38(r1)
	  lwz       r3, 0x302C(r13)
	  stfs      f0, 0x3C(r1)
	  bl        0x3694
	  stw       r3, 0x3FC(r31)
	  li        r4, 0
	  lwz       r3, 0x3FC(r31)
	  lbz       r0, 0x40(r3)
	  ori       r0, r0, 0x4
	  stb       r0, 0x40(r3)
	  lwz       r5, 0x3FC(r31)
	  lwz       r3, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  stw       r3, 0x0(r5)
	  stw       r0, 0x4(r5)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x8(r5)
	  lwz       r3, 0x3FC(r31)
	  bl        0x388C
	  li        r0, -0x1
	  sth       r0, 0x3CA(r31)
	  li        r0, 0
	  stb       r0, 0x3CC(r31)
	  lwz       r0, 0x5C(r1)
	  lfd       f31, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009DF18
 * Size:	00018C
 */
void Bridge::doLoad(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stmw      r27, 0x7C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0
	  li        r30, 0x1
	  li        r29, 0
	  li        r31, 0
	  b         .loc_0x8C

	.loc_0x28:
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x3D0(r27)
	  stfsx     f1, r3, r31
	  lwz       r3, 0x3D0(r27)
	  lfs       f0, 0x5C(r27)
	  lfsx      f1, r3, r31
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x70
	  addi      r3, r27, 0
	  addi      r4, r29, 0
	  li        r5, 0x1
	  bl        0x634
	  b         .loc_0x84

	.loc_0x70:
	  addi      r3, r27, 0
	  addi      r4, r29, 0
	  li        r5, 0
	  bl        0x620
	  li        r30, 0

	.loc_0x84:
	  addi      r31, r31, 0x4
	  addi      r29, r29, 0x1

	.loc_0x8C:
	  lwz       r0, 0x404(r27)
	  cmpw      r29, r0
	  blt+      .loc_0x28
	  mr        r3, r27
	  bl        0x434
	  rlwinm.   r0,r30,0,24,31
	  beq-      .loc_0xC0
	  lwz       r3, 0x3F8(r27)
	  li        r4, 0x1
	  bl        0x37A8
	  lwz       r3, 0x3FC(r27)
	  li        r4, 0x1
	  bl        0x379C

	.loc_0xC0:
	  mr        r3, r27
	  bl        0x260
	  addi      r29, r3, 0
	  cmpwi     r29, -0x1
	  beq-      .loc_0x178
	  addi      r3, r1, 0x38
	  addi      r4, r27, 0
	  bl        0xB68
	  lfs       f2, 0x40(r1)
	  addi      r6, r1, 0x28
	  lfs       f3, -0x54E8(r13)
	  addi      r5, r1, 0x24
	  lfs       f1, 0x3C(r1)
	  lfs       f0, 0x38(r1)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  addi      r4, r1, 0x20
	  fmuls     f0, f0, f3
	  stfs      f2, 0x28(r1)
	  addi      r3, r1, 0x44
	  stfs      f1, 0x24(r1)
	  stfs      f0, 0x20(r1)
	  bl        -0x66F14
	  addi      r4, r27, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x50
	  bl        0x908
	  lfs       f1, 0x50(r1)
	  lfs       f0, 0x44(r1)
	  lfs       f3, 0x54(r1)
	  fsubs     f4, f1, f0
	  lfs       f2, 0x48(r1)
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x4C(r1)
	  fsubs     f2, f3, f2
	  stfs      f4, 0x68(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x6C(r1)
	  stfs      f0, 0x70(r1)
	  lwz       r4, 0x3F8(r27)
	  lwz       r3, 0x68(r1)
	  lwz       r0, 0x6C(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x70(r1)
	  stw       r0, 0x8(r4)

	.loc_0x178:
	  lmw       r27, 0x7C(r1)
	  lwz       r0, 0x94(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009E0A4
 * Size:	000080
 */
void Bridge::doSave(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  rlwinm    r31,r30,2,0,29
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  mr        r3, r29
	  lwz       r4, 0x3D0(r28)
	  lwz       r12, 0x4(r29)
	  lfsx      f1, r4, r31
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x404(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	8009E124
 * Size:	0000B0
 */
bool Bridge::insideSafeArea(Vector3f&)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stfd      f30, 0x70(r1)
	  stfd      f29, 0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r4
	  mr        r4, r3
	  lwz       r5, 0x404(r3)
	  lfs       f31, 0x94(r3)
	  lfs       f30, 0x98(r3)
	  subi      r5, r5, 0x1
	  lfs       f29, 0x9C(r3)
	  addi      r3, r1, 0x1C
	  bl        0x7E8
	  stfs      f31, 0x28(r1)
	  mr        r4, r31
	  lfs       f0, 0x1C(r1)
	  addi      r3, r1, 0x28
	  stfs      f30, 0x2C(r1)
	  lfs       f2, 0x20(r1)
	  stfs      f29, 0x30(r1)
	  lfs       f1, 0x24(r1)
	  stfs      f0, 0x34(r1)
	  lfs       f0, -0x7320(r2)
	  stfs      f2, 0x38(r1)
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  bl        -0x174D4
	  lfs       f0, -0x731C(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x8C
	  li        r3, 0
	  b         .loc_0x90

	.loc_0x8C:
	  li        r3, 0x1

	.loc_0x90:
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lfd       f30, 0x70(r1)
	  lfd       f29, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009E1D4
 * Size:	000068
 */
bool Bridge::isFinished()
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  b         .loc_0x40

	.loc_0x20:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x150
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0x50

	.loc_0x3C:
	  addi      r31, r31, 0x1

	.loc_0x40:
	  lwz       r0, 0x404(r30)
	  cmpw      r31, r0
	  blt+      .loc_0x20
	  li        r3, 0x1

	.loc_0x50:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009E23C
 * Size:	000068
 */
void Bridge::getFirstUnfinishedStage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  b         .loc_0x40

	.loc_0x20:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0xE8
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x3C
	  mr        r3, r31
	  b         .loc_0x50

	.loc_0x3C:
	  addi      r31, r31, 0x1

	.loc_0x40:
	  lwz       r0, 0x404(r30)
	  cmpw      r31, r0
	  blt+      .loc_0x20
	  li        r3, -0x1

	.loc_0x50:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009E2A4
 * Size:	000068
 */
void Bridge::getFirstFinishedStage()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  li        r31, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  b         .loc_0x40

	.loc_0x20:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x80
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x3C
	  mr        r3, r31
	  b         .loc_0x50

	.loc_0x3C:
	  addi      r31, r31, 0x1

	.loc_0x40:
	  lwz       r0, 0x404(r30)
	  cmpw      r31, r0
	  blt+      .loc_0x20
	  li        r3, -0x1

	.loc_0x50:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009E30C
 * Size:	000040
 */
void Bridge::getJointIndex(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x3C8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r3, 0
	  b         .loc_0x30

	.loc_0x20:
	  lwz       r3, 0x410(r3)
	  bl        -0x16544
	  lwz       r3, 0x58(r3)
	  lwz       r3, 0x30(r3)

	.loc_0x30:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009E34C
 * Size:	00009C
 */
bool Bridge::isStageFinished(int)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  lbz       r0, 0x3C8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x60
	  cmpwi     r4, 0
	  blt-      .loc_0x34
	  lwz       r0, 0x404(r31)
	  cmpw      r4, r0
	  blt-      .loc_0x3C

	.loc_0x34:
	  li        r3, 0x1
	  b         .loc_0x88

	.loc_0x3C:
	  lwz       r3, 0x3D4(r31)
	  rlwinm    r0,r4,3,0,28
	  lwz       r4, 0x408(r31)
	  add       r3, r3, r0
	  lwz       r3, 0x4(r3)
	  lwz       r4, 0x38(r4)
	  lwz       r0, 0x14(r3)
	  lbzx      r3, r4, r0
	  b         .loc_0x88

	.loc_0x60:
	  beq-      .loc_0x6C
	  li        r0, 0
	  b         .loc_0x7C

	.loc_0x6C:
	  lwz       r3, 0x410(r31)
	  bl        -0x165D0
	  lwz       r3, 0x58(r3)
	  lwz       r0, 0x30(r3)

	.loc_0x7C:
	  lwz       r3, 0x408(r31)
	  lwz       r3, 0x38(r3)
	  lbzx      r3, r3, r0

	.loc_0x88:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009E3E8
 * Size:	0000A4
 */
void Bridge::flatten()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  b         .loc_0x7C

	.loc_0x28:
	  lwz       r0, 0x3D4(r29)
	  lwz       r3, 0x408(r29)
	  add       r5, r0, r31
	  lwz       r4, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lwz       r6, 0x38(r3)
	  lwz       r0, 0x14(r4)
	  lwz       r4, 0x14(r5)
	  lbzx      r0, r6, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  lbzx      r0, r6, r4
	  cmplwi    r0, 0
	  beq-      .loc_0x74
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl

	.loc_0x74:
	  addi      r31, r31, 0x8
	  addi      r30, r30, 0x1

	.loc_0x7C:
	  lwz       r0, 0x404(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x28
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
 * Address:	8009E48C
 * Size:	000128
 */
void Bridge::dump()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x30(r1)
	  li        r5, 0
	  lwz       r6, 0x404(r3)
	  lfs       f5, -0x72E4(r2)
	  cmpwi     r6, 0
	  ble-      .loc_0x120
	  rlwinm.   r0,r6,29,3,31
	  mtctr     r0
	  beq-      .loc_0xF8

	.loc_0x24:
	  lwz       r4, 0x3D0(r3)
	  lfs       f3, 0x5C(r3)
	  lfsx      f4, r4, r5
	  addi      r5, r5, 0x4
	  fdivs     f2, f4, f3
	  lfsx      f4, r4, r5
	  addi      r5, r5, 0x4
	  fmuls     f1, f5, f2
	  fdivs     f2, f4, f3
	  lfsx      f4, r4, r5
	  addi      r5, r5, 0x4
	  fctiwz    f0, f1
	  fmuls     f1, f5, f2
	  fdivs     f2, f4, f3
	  lfsx      f4, r4, r5
	  stfd      f0, 0x28(r1)
	  addi      r5, r5, 0x4
	  fctiwz    f0, f1
	  fmuls     f1, f5, f2
	  fdivs     f2, f4, f3
	  lfsx      f4, r4, r5
	  stfd      f0, 0x28(r1)
	  addi      r5, r5, 0x4
	  fctiwz    f0, f1
	  fmuls     f1, f5, f2
	  fdivs     f2, f4, f3
	  lfsx      f4, r4, r5
	  stfd      f0, 0x28(r1)
	  addi      r5, r5, 0x4
	  fctiwz    f0, f1
	  fmuls     f1, f5, f2
	  fdivs     f2, f4, f3
	  lfsx      f4, r4, r5
	  stfd      f0, 0x28(r1)
	  addi      r5, r5, 0x4
	  fctiwz    f0, f1
	  fmuls     f1, f5, f2
	  fdivs     f2, f4, f3
	  lfsx      f4, r4, r5
	  stfd      f0, 0x28(r1)
	  addi      r5, r5, 0x4
	  fctiwz    f0, f1
	  fmuls     f1, f5, f2
	  fdivs     f2, f4, f3
	  stfd      f0, 0x28(r1)
	  fctiwz    f0, f1
	  fmuls     f1, f5, f2
	  stfd      f0, 0x28(r1)
	  fctiwz    f0, f1
	  stfd      f0, 0x28(r1)
	  bdnz+     .loc_0x24
	  andi.     r6, r6, 0x7
	  beq-      .loc_0x120

	.loc_0xF8:
	  mtctr     r6

	.loc_0xFC:
	  lwz       r4, 0x3D0(r3)
	  lfs       f3, 0x5C(r3)
	  lfsx      f4, r4, r5
	  addi      r5, r5, 0x4
	  fdivs     f2, f4, f3
	  fmuls     f1, f5, f2
	  fctiwz    f0, f1
	  stfd      f0, 0x28(r1)
	  bdnz+     .loc_0xFC

	.loc_0x120:
	  addi      r1, r1, 0x30
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009E5B4
 * Size:	000394
 */
void Bridge::setStageFinished(int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  stw       r30, 0x88(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x84(r1)
	  mr        r29, r3
	  stw       r28, 0x80(r1)
	  lbz       r0, 0x3C8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x340
	  lwz       r8, 0x3D4(r29)
	  rlwinm    r7,r4,3,0,28
	  lwz       r3, 0x404(r29)
	  li        r31, -0x1
	  add       r6, r8, r7
	  subi      r0, r3, 0x1
	  lwz       r5, 0x4(r6)
	  lwzx      r3, r8, r7
	  cmpw      r4, r0
	  lwz       r28, 0x14(r5)
	  lwz       r7, 0x14(r3)
	  bge-      .loc_0x68
	  lwz       r3, 0x8(r6)
	  lwz       r31, 0x14(r3)

	.loc_0x68:
	  rlwinm.   r0,r30,0,24,31
	  rlwinm    r3,r4,1,0,30
	  subi      r0, r3, 0x1
	  beq-      .loc_0xD8
	  lwz       r3, 0x408(r29)
	  addi      r4, r7, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x408(r29)
	  addi      r4, r28, 0
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r31, -0x1
	  beq-      .loc_0x194
	  lwz       r3, 0x408(r29)
	  addi      r4, r31, 0
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x194

	.loc_0xD8:
	  cmpwi     r0, 0
	  ble-      .loc_0x138
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x408(r29)
	  lwzx      r4, r8, r0
	  lwz       r5, 0x38(r3)
	  lwz       r0, 0x14(r4)
	  lbzx      r0, r5, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x11C
	  lwz       r12, 0x0(r3)
	  addi      r4, r7, 0
	  li        r5, 0x1
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x154

	.loc_0x11C:
	  lwz       r12, 0x0(r3)
	  addi      r4, r7, 0
	  li        r5, 0
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x154

	.loc_0x138:
	  lwz       r3, 0x408(r29)
	  addi      r4, r7, 0
	  li        r5, 0x1
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl

	.loc_0x154:
	  lwz       r3, 0x408(r29)
	  addi      r4, r28, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r31, -0x1
	  beq-      .loc_0x194
	  lwz       r3, 0x408(r29)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl

	.loc_0x194:
	  li        r30, 0
	  addi      r31, r30, 0
	  b         .loc_0x1F4

	.loc_0x1A0:
	  lwz       r0, 0x3D4(r29)
	  lwz       r3, 0x408(r29)
	  add       r5, r0, r31
	  lwz       r4, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lwz       r6, 0x38(r3)
	  lwz       r0, 0x14(r4)
	  lwz       r4, 0x14(r5)
	  lbzx      r0, r6, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x1EC
	  lbzx      r0, r6, r4
	  cmplwi    r0, 0
	  beq-      .loc_0x1EC
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl

	.loc_0x1EC:
	  addi      r31, r31, 0x8
	  addi      r30, r30, 0x1

	.loc_0x1F4:
	  lwz       r0, 0x404(r29)
	  cmpw      r30, r0
	  blt+      .loc_0x1A0
	  li        r30, 0
	  addi      r31, r30, 0
	  b         .loc_0x27C

	.loc_0x20C:
	  lbz       r0, 0x3C8(r29)
	  cmplwi    r0, 0
	  beq-      .loc_0x250
	  cmpwi     r30, 0
	  blt-      .loc_0x228
	  cmpw      r30, r3
	  blt-      .loc_0x230

	.loc_0x228:
	  li        r0, 0x1
	  b         .loc_0x268

	.loc_0x230:
	  lwz       r3, 0x3D4(r29)
	  addi      r0, r31, 0x4
	  lwz       r4, 0x408(r29)
	  lwzx      r3, r3, r0
	  lwz       r4, 0x38(r4)
	  lwz       r0, 0x14(r3)
	  lbzx      r0, r4, r0
	  b         .loc_0x268

	.loc_0x250:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x500
	  lwz       r4, 0x408(r29)
	  lwz       r4, 0x38(r4)
	  lbzx      r0, r4, r3

	.loc_0x268:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x274
	  b         .loc_0x28C

	.loc_0x274:
	  addi      r31, r31, 0x8
	  addi      r30, r30, 0x1

	.loc_0x27C:
	  lwz       r3, 0x404(r29)
	  cmpw      r30, r3
	  blt+      .loc_0x20C
	  li        r30, -0x1

	.loc_0x28C:
	  cmpwi     r30, -0x1
	  addi      r28, r30, 0
	  beq-      .loc_0x374
	  addi      r3, r1, 0x44
	  addi      r4, r29, 0
	  bl        0x308
	  lfs       f2, 0x4C(r1)
	  addi      r6, r1, 0x2C
	  lfs       f3, -0x54E4(r13)
	  addi      r5, r1, 0x28
	  lfs       f1, 0x48(r1)
	  lfs       f0, 0x44(r1)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  addi      r4, r1, 0x24
	  fmuls     f0, f0, f3
	  stfs      f2, 0x2C(r1)
	  addi      r3, r1, 0x50
	  stfs      f1, 0x28(r1)
	  stfs      f0, 0x24(r1)
	  bl        -0x67774
	  addi      r4, r29, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x5C
	  bl        .loc_0x394
	  lfs       f1, 0x5C(r1)
	  lfs       f0, 0x50(r1)
	  lfs       f3, 0x60(r1)
	  fsubs     f4, f1, f0
	  lfs       f2, 0x54(r1)
	  lfs       f1, 0x64(r1)
	  lfs       f0, 0x58(r1)
	  fsubs     f2, f3, f2
	  stfs      f4, 0x74(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x78(r1)
	  stfs      f0, 0x7C(r1)
	  lwz       r4, 0x3F8(r29)
	  lwz       r3, 0x74(r1)
	  lwz       r0, 0x78(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0x7C(r1)
	  stw       r0, 0x8(r4)
	  b         .loc_0x374

	.loc_0x340:
	  beq-      .loc_0x34C
	  li        r4, 0
	  b         .loc_0x35C

	.loc_0x34C:
	  lwz       r3, 0x410(r29)
	  bl        -0x16B18
	  lwz       r3, 0x58(r3)
	  lwz       r4, 0x30(r3)

	.loc_0x35C:
	  lwz       r3, 0x408(r29)
	  rlwinm    r5,r30,0,24,31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x40(r12)
	  mtlr      r12
	  blrl

	.loc_0x374:
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  lwz       r29, 0x84(r1)
	  lwz       r28, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr

	.loc_0x394:
	*/
}

/*
 * --INFO--
 * Address:	8009E948
 * Size:	0000C8
 */
void Bridge::getStagePos(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x80(r1)
	  stfd      f31, 0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r4
	  stw       r30, 0x70(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0x3C8(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  addi      r3, r31, 0
	  addi      r4, r5, 0
	  bl        .loc_0xC8
	  fmr       f31, f1
	  addi      r4, r31, 0
	  addi      r3, r1, 0x4C
	  bl        0x1D0
	  lfs       f0, 0x4C(r1)
	  lfs       f2, 0x50(r1)
	  fmuls     f0, f0, f31
	  lfs       f1, 0x94(r31)
	  lfs       f4, 0x54(r1)
	  fmuls     f2, f2, f31
	  lfs       f3, 0x98(r31)
	  fadds     f0, f1, f0
	  lfs       f5, 0x9C(r31)
	  fmuls     f1, f4, f31
	  fadds     f2, f3, f2
	  stfs      f0, 0x0(r30)
	  fadds     f0, f5, f1
	  stfs      f2, 0x4(r30)
	  stfs      f0, 0x8(r30)
	  b         .loc_0xAC

	.loc_0x88:
	  lwz       r3, 0x410(r31)
	  mr        r4, r5
	  bl        -0x16BEC
	  lfsu      f0, 0x4(r3)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x8(r30)

	.loc_0xAC:
	  lwz       r0, 0x84(r1)
	  lfd       f31, 0x78(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr

	.loc_0xC8:
	*/
}

/*
 * --INFO--
 * Address:	8009EA10
 * Size:	000064
 */
void Bridge::getStageZ(int)
{
	/*
	.loc_0x0:
	  stwu      r1, -0x18(r1)
	  cmpwi     r4, 0
	  lfs       f1, -0x72E0(r2)
	  ble-      .loc_0x54
	  subi      r4, r4, 0x1
	  lbz       r0, 0x400(r3)
	  xoris     r3, r4, 0x8000
	  lfd       f1, -0x7328(r2)
	  stw       r3, 0x14(r1)
	  lis       r4, 0x4330
	  lis       r3, 0x802B
	  lfs       f2, -0x72DC(r2)
	  stw       r4, 0x10(r1)
	  rlwinm    r4,r0,2,0,29
	  lfd       f0, 0x10(r1)
	  addi      r0, r3, 0xEA4
	  add       r3, r0, r4
	  fsubs     f1, f0, f1
	  lfs       f0, 0x0(r3)
	  fmuls     f1, f2, f1
	  fadds     f1, f1, f0

	.loc_0x54:
	  lfs       f0, -0x72F0(r2)
	  fsubs     f1, f1, f0
	  addi      r1, r1, 0x18
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009EA74
 * Size:	0000E8
 */
void Bridge::getBridgePos(Vector3f&, f32&, f32&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stfd      f31, 0x98(r1)
	  stfd      f30, 0x90(r1)
	  stw       r31, 0x8C(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x88(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x84(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x80(r1)
	  addi      r28, r3, 0
	  addi      r4, r28, 0
	  addi      r3, r1, 0x5C
	  bl        0x16C
	  lfs       f3, 0x8(r29)
	  mr        r4, r28
	  lfs       f2, 0x64(r1)
	  addi      r3, r1, 0x50
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x5C(r1)
	  fsubs     f31, f3, f2
	  fsubs     f30, f1, f0
	  bl        0xE8
	  lfs       f2, 0x50(r1)
	  mr        r4, r28
	  lfs       f1, -0x732C(r2)
	  addi      r3, r1, 0x44
	  lfs       f0, 0x54(r1)
	  lfs       f3, 0x58(r1)
	  fmuls     f2, f30, f2
	  fmuls     f0, f1, f0
	  fmuls     f1, f31, f3
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r30)
	  bl        .loc_0xE8
	  lfs       f2, 0x44(r1)
	  lfs       f1, -0x732C(r2)
	  lfs       f0, 0x48(r1)
	  fmuls     f2, f30, f2
	  lfs       f3, 0x4C(r1)
	  fmuls     f0, f1, f0
	  fmuls     f1, f31, f3
	  fadds     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r31)
	  lwz       r0, 0xA4(r1)
	  lfd       f31, 0x98(r1)
	  lfd       f30, 0x90(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  lwz       r29, 0x84(r1)
	  lwz       r28, 0x80(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr

	.loc_0xE8:
	*/
}

/*
 * --INFO--
 * Address:	8009EB5C
 * Size:	000060
 */
void Bridge::getBridgeZVec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stfd      f30, 0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lfs       f30, 0x8C(r4)
	  fmr       f1, f30
	  bl        0x17CFD4
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0x17D15C
	  lfs       f0, -0x54E0(r13)
	  stfs      f1, 0x0(r31)
	  stfs      f0, 0x4(r31)
	  stfs      f31, 0x8(r31)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lfd       f30, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009EBBC
 * Size:	000060
 */
void Bridge::getBridgeXVec()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  stfd      f30, 0x38(r1)
	  stw       r31, 0x34(r1)
	  mr        r31, r3
	  lfs       f30, 0x8C(r4)
	  fmr       f1, f30
	  bl        0x17D108
	  fneg      f31, f1
	  fmr       f1, f30
	  bl        0x17CF68
	  lfs       f0, -0x54DC(r13)
	  stfs      f1, 0x0(r31)
	  stfs      f0, 0x4(r31)
	  stfs      f31, 0x8(r31)
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lfd       f30, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009EC1C
 * Size:	0000FC
 */
void Bridge::getStartPos()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stfd      f29, 0x70(r1)
	  stfd      f28, 0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  mr        r30, r3
	  lfs       f31, 0x8C(r4)
	  lfs       f30, 0x94(r4)
	  fmr       f1, f31
	  lfs       f29, 0x98(r4)
	  lfs       f28, 0x9C(r4)
	  bl        0x17CEFC
	  stfs      f1, 0x34(r1)
	  fmr       f1, f31
	  addi      r31, r1, 0x34
	  bl        0x17D080
	  stfs      f1, 0x30(r1)
	  addi      r4, r1, 0x30
	  addi      r6, r31, 0
	  addi      r3, r1, 0x24
	  subi      r5, r13, 0x54E0
	  bl        -0x67B64
	  addi      r3, r1, 0x3C
	  addi      r4, r1, 0x24
	  bl        -0x2BB48
	  lfs       f2, 0x44(r1)
	  addi      r6, r1, 0x20
	  lfs       f3, -0x54D8(r13)
	  addi      r5, r1, 0x1C
	  lfs       f1, 0x40(r1)
	  lfs       f0, 0x3C(r1)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  addi      r4, r1, 0x18
	  fmuls     f0, f0, f3
	  stfs      f2, 0x20(r1)
	  addi      r3, r1, 0x48
	  stfs      f1, 0x1C(r1)
	  stfs      f0, 0x18(r1)
	  bl        -0x67BAC
	  lfs       f0, 0x48(r1)
	  lfs       f1, 0x4C(r1)
	  fsubs     f0, f30, f0
	  lfs       f2, 0x50(r1)
	  fsubs     f3, f29, f1
	  fsubs     f1, f28, f2
	  stfs      f0, 0x0(r30)
	  stfs      f3, 0x4(r30)
	  stfs      f1, 0x8(r30)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lfd       f29, 0x70(r1)
	  lfd       f28, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009ED18
 * Size:	000008
 */
f32 Bridge::getStageDepth()
{
	return 0.0f;
	/*
	.loc_0x0:
	  lfs       f1, -0x72DC(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009ED20
 * Size:	000008
 */
f32 Bridge::getStageWidth()
{
	return 0.0f;
	/*
	.loc_0x0:
	  lfs       f1, -0x72D8(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009ED28
 * Size:	000424
 */
void Bridge::startStageFinished(int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  rlwinm.   r0,r5,0,24,31
	  stwu      r1, -0x128(r1)
	  stfd      f31, 0x120(r1)
	  stfd      f30, 0x118(r1)
	  stw       r31, 0x114(r1)
	  addi      r31, r6, 0xE88
	  stw       r30, 0x110(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x10C(r1)
	  addi      r29, r3, 0
	  stw       r28, 0x108(r1)
	  beq-      .loc_0x3E8
	  lwz       r3, 0x3178(r13)
	  addi      r6, r29, 0x94
	  li        r4, 0x7
	  li        r5, 0
	  bl        0xDE060
	  cmpwi     r30, 0
	  bgt-      .loc_0x60
	  lfs       f31, -0x72E0(r2)
	  b         .loc_0x9C

	.loc_0x60:
	  subi      r3, r30, 0x1
	  lbz       r0, 0x400(r29)
	  xoris     r3, r3, 0x8000
	  lfd       f2, -0x7328(r2)
	  stw       r3, 0x104(r1)
	  lis       r3, 0x4330
	  rlwinm    r0,r0,2,0,29
	  lfs       f3, -0x72DC(r2)
	  stw       r3, 0x100(r1)
	  add       r3, r31, r0
	  lfd       f1, 0x100(r1)
	  lfs       f0, 0x1C(r3)
	  fsubs     f1, f1, f2
	  fmuls     f1, f3, f1
	  fadds     f31, f1, f0

	.loc_0x9C:
	  lfs       f0, 0x94(r29)
	  stfs      f0, 0xF4(r1)
	  lfs       f0, 0x98(r29)
	  stfs      f0, 0xF8(r1)
	  lfs       f0, 0x9C(r29)
	  stfs      f0, 0xFC(r1)
	  lfs       f30, 0x8C(r29)
	  fmr       f1, f30
	  bl        0x17CD70
	  stfs      f1, 0x68(r1)
	  fmr       f1, f30
	  addi      r28, r1, 0x68
	  bl        0x17CEF4
	  stfs      f1, 0x64(r1)
	  addi      r4, r1, 0x64
	  addi      r6, r28, 0
	  addi      r3, r1, 0x58
	  subi      r5, r13, 0x54E0
	  bl        -0x67CF0
	  addi      r3, r1, 0xD0
	  addi      r4, r1, 0x58
	  bl        -0x2BCD4
	  lfs       f0, 0xD0(r1)
	  cmpwi     r30, 0x1
	  lfs       f2, 0xD4(r1)
	  fmuls     f0, f0, f31
	  lfs       f1, 0xF4(r1)
	  lfs       f4, 0xD8(r1)
	  fmuls     f2, f2, f31
	  lfs       f3, 0xF8(r1)
	  fadds     f0, f1, f0
	  lfs       f5, 0xFC(r1)
	  fmuls     f1, f4, f31
	  fadds     f2, f3, f2
	  stfs      f0, 0xF4(r1)
	  fadds     f0, f5, f1
	  stfs      f2, 0xF8(r1)
	  stfs      f0, 0xFC(r1)
	  bne-      .loc_0x174
	  lbz       r0, 0x400(r29)
	  lfs       f1, 0xF8(r1)
	  rlwinm    r0,r0,2,0,29
	  add       r3, r31, r0
	  lfs       f0, 0x30(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0xF8(r1)
	  lbz       r0, 0x400(r29)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x1D8
	  lfs       f1, 0xF8(r1)
	  lfs       f0, -0x72F0(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xF8(r1)
	  b         .loc_0x1D8

	.loc_0x174:
	  subi      r0, r30, 0x1
	  lbz       r3, 0x400(r29)
	  xoris     r0, r0, 0x8000
	  lfd       f2, -0x7328(r2)
	  stw       r0, 0x104(r1)
	  lis       r0, 0x4330
	  rlwinm    r3,r3,2,0,29
	  lfs       f3, 0xF8(r1)
	  stw       r0, 0x100(r1)
	  add       r3, r31, r3
	  lfd       f1, 0x100(r1)
	  lfs       f0, 0x44(r3)
	  fsubs     f1, f1, f2
	  lfs       f2, 0x30(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0xF8(r1)
	  lbz       r0, 0x400(r29)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x1D8
	  lfs       f1, 0xF8(r1)
	  lfs       f0, -0x72F0(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xF8(r1)

	.loc_0x1D8:
	  lfs       f0, 0xF4(r1)
	  stfs      f0, 0xE8(r1)
	  lfs       f0, 0xF8(r1)
	  stfs      f0, 0xEC(r1)
	  lfs       f0, 0xFC(r1)
	  stfs      f0, 0xF0(r1)
	  lfs       f30, 0x8C(r29)
	  fmr       f1, f30
	  bl        0x17CC34
	  stfs      f1, 0x54(r1)
	  fmr       f1, f30
	  addi      r28, r1, 0x54
	  bl        0x17CDB8
	  stfs      f1, 0x50(r1)
	  addi      r4, r1, 0x50
	  addi      r6, r28, 0
	  addi      r3, r1, 0x44
	  subi      r5, r13, 0x54E0
	  bl        -0x67E2C
	  addi      r3, r1, 0xB8
	  addi      r4, r1, 0x44
	  bl        -0x2BE10
	  lfs       f2, 0xC0(r1)
	  addi      r6, r1, 0x40
	  lfs       f3, -0x54D4(r13)
	  addi      r5, r1, 0x3C
	  lfs       f1, 0xBC(r1)
	  lfs       f0, 0xB8(r1)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  addi      r4, r1, 0x38
	  fmuls     f0, f0, f3
	  stfs      f2, 0x40(r1)
	  addi      r3, r1, 0xC4
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x38(r1)
	  bl        -0x67E74
	  lfs       f2, 0xF4(r1)
	  cmpwi     r30, 0
	  lfs       f1, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  fadds     f1, f2, f1
	  stfs      f1, 0xE8(r1)
	  lfs       f1, 0xF8(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xEC(r1)
	  lfs       f1, 0xFC(r1)
	  lfs       f0, 0xCC(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0xF0(r1)
	  ble-      .loc_0x2FC
	  xoris     r3, r30, 0x8000
	  lbz       r0, 0x400(r29)
	  stw       r3, 0x104(r1)
	  lis       r3, 0x4330
	  rlwinm    r0,r0,2,0,29
	  lfd       f2, -0x7328(r2)
	  stw       r3, 0x100(r1)
	  add       r3, r31, r0
	  lfs       f3, 0xF8(r1)
	  lfd       f1, 0x100(r1)
	  lfs       f0, 0x44(r3)
	  fsubs     f1, f1, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0xF8(r1)
	  lbz       r0, 0x400(r29)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x2FC
	  lfs       f1, 0xF8(r1)
	  lfs       f0, -0x72F0(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0xF8(r1)

	.loc_0x2FC:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0xF4
	  li        r4, 0xD7
	  li        r6, 0
	  li        r7, 0
	  bl        0xFDB00
	  mr        r28, r3
	  lwz       r3, 0x3180(r13)
	  addi      r5, r1, 0xE8
	  li        r4, 0xD7
	  li        r6, 0
	  li        r7, 0
	  bl        0xFDAE4
	  cmplwi    r28, 0
	  addi      r31, r3, 0
	  beq-      .loc_0x37C
	  lfs       f30, 0x8C(r29)
	  fmr       f1, f30
	  bl        0x17CC7C
	  fneg      f31, f1
	  fmr       f1, f30
	  bl        0x17CADC
	  stfs      f1, 0xAC(r1)
	  lfs       f0, -0x54DC(r13)
	  stfs      f0, 0xB0(r1)
	  stfs      f31, 0xB4(r1)
	  lwz       r3, 0xAC(r1)
	  lwz       r0, 0xB0(r1)
	  stw       r3, 0xA0(r28)
	  stw       r0, 0xA4(r28)
	  lwz       r0, 0xB4(r1)
	  stw       r0, 0xA8(r28)

	.loc_0x37C:
	  cmplwi    r31, 0
	  beq-      .loc_0x3C4
	  lfs       f31, 0x8C(r29)
	  fmr       f1, f31
	  bl        0x17CC34
	  fneg      f30, f1
	  fmr       f1, f31
	  bl        0x17CA94
	  stfs      f1, 0xA0(r1)
	  lfs       f0, -0x54DC(r13)
	  stfs      f0, 0xA4(r1)
	  stfs      f30, 0xA8(r1)
	  lwz       r3, 0xA0(r1)
	  lwz       r0, 0xA4(r1)
	  stw       r3, 0xA0(r31)
	  stw       r0, 0xA4(r31)
	  lwz       r0, 0xA8(r1)
	  stw       r0, 0xA8(r31)

	.loc_0x3C4:
	  li        r0, 0x3C
	  stb       r0, 0x3CC(r29)
	  extsh     r0, r30
	  addi      r3, r29, 0
	  sth       r0, 0x3CA(r29)
	  addi      r4, r29, 0
	  li        r5, 0xB3
	  bl        -0x14B54
	  b         .loc_0x3FC

	.loc_0x3E8:
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0xB64
	  li        r0, 0
	  stb       r0, 0x3CC(r29)

	.loc_0x3FC:
	  lwz       r0, 0x12C(r1)
	  lfd       f31, 0x120(r1)
	  lfd       f30, 0x118(r1)
	  lwz       r31, 0x114(r1)
	  lwz       r30, 0x110(r1)
	  lwz       r29, 0x10C(r1)
	  lwz       r28, 0x108(r1)
	  addi      r1, r1, 0x128
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009F14C
 * Size:	0000A0
 */
bool InteractBuild::actBridge(Bridge*)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lwz       r0, 0x8(r3)
	  addi      r3, r30, 0
	  lwz       r5, 0x3D0(r4)
	  rlwinm    r0,r0,2,0,29
	  add       r31, r5, r0
	  li        r5, 0xAD
	  bl        -0x14BD0
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0xC(r29)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x0(r31)
	  lfs       f1, 0x5C(r30)
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x80
	  stfs      f1, 0x0(r31)
	  lbz       r0, 0x3CC(r30)
	  cmplwi    r0, 0
	  bne-      .loc_0x80
	  lwz       r4, 0x8(r29)
	  addi      r3, r30, 0
	  li        r5, 0x1
	  bl        -0x4A0

	.loc_0x80:
	  lwz       r0, 0x24(r1)
	  li        r3, 0x1
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
 * Address:	8009F1EC
 * Size:	0002E8
 */
bool InteractBreak::actBridge(Bridge*)
{
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE0(r1)
	  stfd      f31, 0xD8(r1)
	  stw       r31, 0xD4(r1)
	  mr        r31, r4
	  stw       r30, 0xD0(r1)
	  stw       r29, 0xCC(r1)
	  lwz       r0, 0x8(r3)
	  lwz       r4, 0x3D0(r4)
	  rlwinm    r0,r0,2,0,29
	  lfs       f0, 0xC(r3)
	  add       r4, r4, r0
	  lfs       f1, 0x0(r4)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x0(r4)
	  lfs       f31, -0x732C(r2)
	  fcmpo     cr0, f0, f31
	  cror      2, 0, 0x2
	  bne-      .loc_0x2C4
	  stfs      f31, 0x0(r4)
	  lwz       r0, 0x8(r3)
	  mr        r29, r0
	  rlwinm    r30,r0,2,0,29
	  b         .loc_0x88

	.loc_0x68:
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  li        r5, 0
	  bl        -0xCAC
	  lwz       r3, 0x3D0(r31)
	  addi      r29, r29, 0x1
	  stfsx     f31, r3, r30
	  addi      r30, r30, 0x4

	.loc_0x88:
	  lwz       r0, 0x404(r31)
	  cmpw      r29, r0
	  blt+      .loc_0x68
	  lwz       r3, 0x3F8(r31)
	  li        r4, 0
	  bl        0x24E8
	  lwz       r3, 0x3FC(r31)
	  li        r4, 0
	  bl        0x24DC
	  li        r30, 0
	  addi      r29, r30, 0
	  b         .loc_0x128

	.loc_0xB8:
	  lbz       r0, 0x3C8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0xFC
	  cmpwi     r30, 0
	  blt-      .loc_0xD4
	  cmpw      r30, r3
	  blt-      .loc_0xDC

	.loc_0xD4:
	  li        r0, 0x1
	  b         .loc_0x114

	.loc_0xDC:
	  lwz       r3, 0x3D4(r31)
	  addi      r0, r29, 0x4
	  lwz       r4, 0x408(r31)
	  lwzx      r3, r3, r0
	  lwz       r4, 0x38(r4)
	  lwz       r0, 0x14(r3)
	  lbzx      r0, r4, r0
	  b         .loc_0x114

	.loc_0xFC:
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        -0xFE4
	  lwz       r4, 0x408(r31)
	  lwz       r4, 0x38(r4)
	  lbzx      r0, r4, r3

	.loc_0x114:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x120
	  b         .loc_0x138

	.loc_0x120:
	  addi      r29, r29, 0x8
	  addi      r30, r30, 0x1

	.loc_0x128:
	  lwz       r3, 0x404(r31)
	  cmpw      r30, r3
	  blt+      .loc_0xB8
	  li        r30, -0x1

	.loc_0x138:
	  cmpwi     r30, -0x1
	  addi      r29, r30, 0
	  beq-      .loc_0x2C4
	  lfs       f31, 0x8C(r31)
	  fmr       f1, f31
	  bl        0x17C81C
	  stfs      f1, 0x44(r1)
	  fmr       f1, f31
	  addi      r30, r1, 0x44
	  bl        0x17C9A0
	  stfs      f1, 0x40(r1)
	  addi      r4, r1, 0x40
	  addi      r6, r30, 0
	  addi      r3, r1, 0x34
	  subi      r5, r13, 0x54E0
	  bl        -0x68244
	  addi      r3, r1, 0x8C
	  addi      r4, r1, 0x34
	  bl        -0x2C228
	  lfs       f2, 0x94(r1)
	  addi      r6, r1, 0x78
	  lfs       f3, -0x54D0(r13)
	  addi      r5, r1, 0x74
	  lfs       f1, 0x90(r1)
	  lfs       f0, 0x8C(r1)
	  fmuls     f2, f2, f3
	  fmuls     f1, f1, f3
	  addi      r4, r1, 0x70
	  fmuls     f0, f0, f3
	  stfs      f2, 0x78(r1)
	  addi      r3, r1, 0x98
	  stfs      f1, 0x74(r1)
	  stfs      f0, 0x70(r1)
	  bl        -0x6828C
	  lbz       r0, 0x3C8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x25C
	  lfs       f0, -0x732C(r2)
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  bl        -0x9C0
	  stfs      f1, 0x54(r1)
	  addi      r4, r31, 0
	  addi      r3, r1, 0x64
	  bl        -0x884
	  addi      r3, r1, 0x58
	  addi      r4, r1, 0x64
	  addi      r5, r1, 0x54
	  bl        .loc_0x2E8
	  lfs       f1, 0x9C(r31)
	  addi      r6, r1, 0x30
	  lfs       f0, 0x60(r1)
	  addi      r5, r1, 0x2C
	  addi      r4, r1, 0x28
	  fadds     f2, f1, f0
	  lfs       f1, 0x5C(r1)
	  lfs       f0, 0x58(r1)
	  addi      r3, r1, 0x48
	  stfs      f2, 0x30(r1)
	  lfs       f2, 0x98(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0x2C(r1)
	  lfs       f1, 0x94(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  bl        -0x68318
	  addi      r3, r1, 0xA4
	  addi      r4, r1, 0x48
	  bl        -0x2C2FC
	  b         .loc_0x278

	.loc_0x25C:
	  lwz       r3, 0x410(r31)
	  mr        r4, r29
	  bl        -0x17664
	  addi      r4, r3, 0
	  addi      r3, r1, 0xA4
	  addi      r4, r4, 0x4
	  bl        -0x2C31C

	.loc_0x278:
	  lfs       f1, 0xA4(r1)
	  lfs       f0, 0x98(r1)
	  lfs       f3, 0xA8(r1)
	  fsubs     f4, f1, f0
	  lfs       f2, 0x9C(r1)
	  lfs       f1, 0xAC(r1)
	  lfs       f0, 0xA0(r1)
	  fsubs     f2, f3, f2
	  stfs      f4, 0xBC(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  lwz       r4, 0x3F8(r31)
	  lwz       r3, 0xBC(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r3, 0x0(r4)
	  stw       r0, 0x4(r4)
	  lwz       r0, 0xC4(r1)
	  stw       r0, 0x8(r4)

	.loc_0x2C4:
	  lwz       r0, 0xE4(r1)
	  li        r3, 0x1
	  lfd       f31, 0xD8(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  lwz       r29, 0xCC(r1)
	  addi      r1, r1, 0xE0
	  mtlr      r0
	  blr

	.loc_0x2E8:
	*/
}

/*
 * --INFO--
 * Address:	8009F4D4
 * Size:	00002C
 */
void operator*(const Vector3f&, const f32&)
{
	/*
	.loc_0x0:
	  lfs       f3, 0x0(r5)
	  lfs       f0, 0x0(r4)
	  lfs       f1, 0x4(r4)
	  lfs       f2, 0x8(r4)
	  fmuls     f0, f0, f3
	  fmuls     f1, f1, f3
	  fmuls     f2, f2, f3
	  stfs      f0, 0x0(r3)
	  stfs      f1, 0x4(r3)
	  stfs      f2, 0x8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009F500
 * Size:	000008
 */
bool Bridge::isBridge() { return true; }

/*
 * --INFO--
 * Address:	8009F508
 * Size:	000014
 */
bool Bridge::alwaysUpdatePlatform()
{
	return false;
	/*
	.loc_0x0:
	  lbz       r0, 0x424(r3)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009F51C
 * Size:	00000C
 */
void Bridge::finalSetup()
{
	// Generated from stb r0, 0x424(r3)
	// _424 = 3;
}

/*
 * --INFO--
 * Address:	8009F528
 * Size:	000008
 */
bool WorkObject::isVisible() { return true; }

/*
 * --INFO--
 * Address:	8009F530
 * Size:	000008
 */
bool WorkObject::isAlive() { return true; }

/*
 * --INFO--
 * Address:	8009F538
 * Size:	000008
 */
bool WorkObject::isHinderRock() { return false; }

/*
 * --INFO--
 * Address:	8009F540
 * Size:	000008
 */
f32 ItemCreature::getHeight()
{
	return 0.0f;
	/*
	.loc_0x0:
	  lfs       f1, -0x732C(r2)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009F548
 * Size:	000008
 */
bool HinderRock::isHinderRock() { return true; }

/*
 * --INFO--
 * Address:	8009F550
 * Size:	000004
 */
void DynBuildShape::update() { }

/*
 * --INFO--
 * Address:	8009F554
 * Size:	000004
 */
void DynBuildShape::refresh(Graphics&) { }

/*
 * --INFO--
 * Address:	8009F558
 * Size:	00006C
 */
WorkObjectMgr::~WorkObjectMgr()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr.       r31, r3
	  beq-      .loc_0x54
	  lis       r3, 0x802B
	  addi      r3, r3, 0x1864
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)
	  beq-      .loc_0x44
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  stw       r0, 0x8(r31)

	.loc_0x44:
	  extsh.    r0, r4
	  ble-      .loc_0x54
	  mr        r3, r31
	  bl        -0x583FC

	.loc_0x54:
	  mr        r3, r31
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009F5C4
 * Size:	000008
 */
int WorkObjectMgr::getMax()
{
	return 0x10000;
	/*
	.loc_0x0:
	  lis       r3, 0x1
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009F5CC
 * Size:	000008
 */
bool WorkObject::isFinished() { return false; }

/*
 * --INFO--
 * Address:	8009F5D4
 * Size:	000008
 */
bool WorkObject::workable(Vector3f&) { return true; }
