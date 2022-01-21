#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80024DFC
 * Size:	0000D8
 */
BaseApp::BaseApp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r27, r3, 0
	  addi      r28, r4, 0x738C
	  lis       r3, 0x8022
	  addi      r29, r3, 0x737C
	  li        r30, 0
	  addi      r3, r27, 0
	  subi      r4, r13, 0x7EB0
	  stw       r28, 0x0(r27)
	  stw       r29, 0x0(r27)
	  stw       r30, 0x10(r27)
	  stw       r30, 0xC(r27)
	  stw       r30, 0x8(r27)
	  bl        .loc_0xD8
	  lis       r3, 0x8023
	  subi      r31, r3, 0x71E0
	  stw       r31, 0x0(r27)
	  addi      r3, r27, 0
	  subi      r4, r13, 0x7EB0
	  bl        0x1B8E4
	  lis       r3, 0x8022
	  addi      r0, r3, 0x7330
	  stw       r0, 0x0(r27)
	  addi      r3, r27, 0x30
	  subi      r4, r13, 0x7EB0
	  stw       r28, 0x30(r27)
	  stw       r29, 0x30(r27)
	  stw       r30, 0x40(r27)
	  stw       r30, 0x3C(r27)
	  stw       r30, 0x38(r27)
	  bl        .loc_0xD8
	  stw       r31, 0x30(r27)
	  addi      r3, r27, 0x30
	  subi      r4, r13, 0x7EB0
	  bl        0x1B8A8
	  stw       r30, 0x2C(r27)
	  li        r0, 0x1
	  addi      r4, r27, 0
	  stw       r30, 0x20(r27)
	  stw       r30, 0x24(r27)
	  stb       r0, 0x28(r27)
	  lwz       r3, 0x2DD8(r13)
	  addi      r3, r3, 0x4
	  bl        0x1B720
	  mr        r3, r27
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0xD8:
	*/
}

/*
 * --INFO--
 * Address:	80024ED4
 * Size:	000008
 */
void CoreNode::setName(char* a1)
{
	// Generated from stw r4, 0x4(r3)
	_04 = a1;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void BaseApp::idleupdate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void BaseApp::startAgeServer()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void BaseApp::stopAgeServer()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80024EDC
 * Size:	000048
 */
void BaseApp::softReset()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x8022
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  addi      r4, r4, 0x72DC
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x10(r3)
	  addi      r3, r3, 0x30
	  bl        0x1B840
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	80024F24
 * Size:	0000A4
 */
BaseApp::~BaseApp()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr.       r30, r3
	  beq-      .loc_0x88
	  lis       r3, 0x8022
	  addi      r0, r3, 0x7330
	  stw       r0, 0x0(r30)
	  lwz       r3, 0x20(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x6C
	  lwz       r3, 0x8(r3)
	  lis       r4, 0x1
	  subi      r4, r4, 0x1
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x20(r30)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x4(r3)
	  lwz       r12, 0x54(r12)
	  mtlr      r12
	  blrl

	.loc_0x6C:
	  lwz       r3, 0x2DD8(r13)
	  mr        r4, r30
	  bl        0x1B93C
	  extsh.    r0, r31
	  ble-      .loc_0x88
	  mr        r3, r30
	  bl        0x22204

	.loc_0x88:
	  mr        r3, r30
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
 * Address:	80024FC8
 * Size:	000004
 */
void Stream::flush() { }

/*
 * --INFO--
 * Address:	80024FCC
 * Size:	000004
 */
void BaseApp::InitApp(char*) { }

/*
 * --INFO--
 * Address:	80024FD0
 * Size:	000008
 */
u32 BaseApp::idle() { return 0x0; }

/*
 * --INFO--
 * Address:	80024FD8
 * Size:	000008
 */
u32 BaseApp::keyDown(int, int, int) { return 0x0; }

/*
 * --INFO--
 * Address:	80024FE0
 * Size:	000030
 */
void BaseApp::useHeap(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  stw       r4, 0x50(r3)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x50(r5)
	  bl        0x1A06C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80025010
 * Size:	000004
 */
void BaseApp::procCmd(char*) { }

/*
 * --INFO--
 * Address:	80025014
 * Size:	00002C
 */
void Node::concat(Matrix4f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
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
 * Address:	80025040
 * Size:	00002C
 */
void Node::concat(SRT&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
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
 * Address:	8002506C
 * Size:	00002C
 */
void Node::concat(VQS&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x1C(r12)
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
 * Address:	80025098
 * Size:	000004
 */
void Node::concat() { }

/*
 * --INFO--
 * Address:	8002509C
 * Size:	000008
 */
u32 Node::getModelMatrix() { return 0x0; }

/*
 * --INFO--
 * Address:	800250A4
 * Size:	000004
 */
void CoreNode::read(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	800250A8
 * Size:	000008
 */
u32 ANode::getAgeNodeType() { return 0x0; }
