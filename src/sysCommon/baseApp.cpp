#include "BaseApp.h"
#include "AtxStream.h"
#include "Age.h"

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
	init("<Node>");
	mWindowNode.init("<Node>");

	_2C            = 0;
	mCommandStream = 0;
	mAgeServer     = 0;
	_28            = 1;

	nodeMgr->firstNode().add(this);
}

/*
 * --INFO--
 * Address:	80024ED4
 * Size:	000008
 */
// void CoreNode::setName(char* name) { mName = name; }

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
int BaseApp::idleupdate()
{
#ifndef __MWERKS__
	bool hasUpdates = false;

	if (mCommandStream) {
		const int commandStatus = mCommandStream->checkCommands();

		if (commandStatus == -1) {
			mCommandStream = nullptr;
		} else if (commandStatus) {
			hasUpdates = true;
		}
	}

	if (mAgeServer) {
		const int serverStatus = mAgeServer->update();

		if (serverStatus == -1) {
			stopAgeServer();
			mAgeServer = nullptr;
		} else if (serverStatus) {
			hasUpdates = true;
		}
	}

	return hasUpdates;
#endif
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
// void Stream::flush() { }

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
int BaseApp::idle() { return 0; }

/*
 * --INFO--
 * Address:	80024FD8
 * Size:	000008
 */
bool BaseApp::keyDown(int, int, int) { return false; }

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
// void Node::concat() { }

/*
 * --INFO--
 * Address:	8002509C
 * Size:	000008
 */
// Matrix4f* Node::getModelMatrix() { return nullptr; }

/*
 * --INFO--
 * Address:	800250A4
 * Size:	000004
 */
// void CoreNode::read(RandomAccessStream&) { }

/*
 * --INFO--
 * Address:	800250A8
 * Size:	000008
 */
// int ANode::getAgeNodeType() { return 0x0; }
