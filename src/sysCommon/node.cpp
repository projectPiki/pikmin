#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800405D8
 * Size:	000038
 */
void CoreNode::add(CoreNode *)
{
/*
.loc_0x0:
  lwz       r0, 0x10(r3)
  cmplwi    r0, 0
  mr        r5, r0
  beq-      .loc_0x2C
  b         .loc_0x18

.loc_0x14:
  mr        r5, r0

.loc_0x18:
  lwz       r0, 0xC(r5)
  cmplwi    r0, 0
  bne+      .loc_0x14
  stw       r4, 0xC(r5)
  b         .loc_0x30

.loc_0x2C:
  stw       r4, 0x10(r3)

.loc_0x30:
  stw       r3, 0x8(r4)
  blr
*/
}

/*
 * --INFO--
 * Address:	80040610
 * Size:	000070
 */
void CoreNode::del()
{
/*
.loc_0x0:
  lwz       r4, 0x8(r3)
  cmplwi    r4, 0
  beqlr-    
  addi      r5, r4, 0x10
  lwz       r4, 0x10(r4)
  li        r6, 0
  b         .loc_0x64

.loc_0x1C:
  cmplw     r4, r3
  bne-      .loc_0x5C
  cmplwi    r6, 0
  beq-      .loc_0x44
  lwz       r4, 0xC(r4)
  li        r0, 0
  stw       r4, 0xC(r6)
  stw       r0, 0xC(r3)
  stw       r0, 0x8(r3)
  blr       

.loc_0x44:
  lwz       r4, 0xC(r4)
  li        r0, 0
  stw       r4, 0x0(r5)
  stw       r0, 0xC(r3)
  stw       r0, 0x8(r3)
  blr       

.loc_0x5C:
  mr        r6, r4
  lwz       r4, 0xC(r4)

.loc_0x64:
  cmplwi    r4, 0
  bne+      .loc_0x1C
  blr
*/
}

/*
 * --INFO--
 * Address:	80040680
 * Size:	000020
 */
void CoreNode::getChildCount()
{
/*
.loc_0x0:
  lwz       r4, 0x10(r3)
  li        r3, 0
  b         .loc_0x14

.loc_0xC:
  lwz       r4, 0xC(r4)
  addi      r3, r3, 0x1

.loc_0x14:
  cmplwi    r4, 0
  bne+      .loc_0xC
  blr
*/
}

/*
 * --INFO--
 * Address:	800406A0
 * Size:	00009C
 */
void CoreNode::load(char *, char *, unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  addi      r6, r5, 0
  stw       r0, 0x4(r1)
  addi      r5, r4, 0
  crclr     6, 0x6
  subi      r4, r13, 0x7998
  stwu      r1, -0x120(r1)
  stw       r31, 0x11C(r1)
  stw       r30, 0x118(r1)
  addi      r30, r3, 0
  addi      r3, r1, 0x18
  bl        0x1D5ECC
  lwz       r3, 0x2DEC(r13)
  addi      r4, r1, 0x18
  li        r5, 0x1
  lwz       r12, 0x1A0(r3)
  li        r6, 0x1
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr.       r31, r3
  beq-      .loc_0x84
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x4C(r12)
  mtlr      r12
  blrl      

.loc_0x84:
  lwz       r0, 0x124(r1)
  lwz       r31, 0x11C(r1)
  lwz       r30, 0x118(r1)
  addi      r1, r1, 0x120
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8004073C
 * Size:	000028
 */
void Node::init(char *)
{
/*
.loc_0x0:
  li        r6, 0
  stw       r6, 0x10(r3)
  li        r5, 0x3
  li        r0, -0x1
  stw       r6, 0xC(r3)
  stw       r6, 0x8(r3)
  stw       r4, 0x4(r3)
  stw       r5, 0x18(r3)
  stw       r0, 0x1C(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80040764
 * Size:	00006C
 */
void Node::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  lwz       r31, 0x10(r3)
  b         .loc_0x50

.loc_0x18:
  lwz       r0, 0x18(r31)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x4C
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x1C(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      

.loc_0x4C:
  lwz       r31, 0xC(r31)

.loc_0x50:
  cmplwi    r31, 0
  bne+      .loc_0x18
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800407D0
 * Size:	00005C
 */
void Node::draw(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r4
  lwz       r31, 0x10(r3)
  b         .loc_0x3C

.loc_0x20:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lwz       r31, 0xC(r31)

.loc_0x3C:
  cmplwi    r31, 0
  bne+      .loc_0x20
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
 * Address:	8004082C
 * Size:	00002C
 */
void Node::render(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
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
 * Address:	........
 * Size:	000128
 */
SRTNode::SRTNode(char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80040858
 * Size:	00007C
 */
void SRTNode::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r31, 0x10(r3)
  b         .loc_0x5C

.loc_0x20:
  lwz       r0, 0x18(r31)
  rlwinm.   r0,r0,0,31,31
  beq-      .loc_0x58
  mr        r3, r31
  lwz       r12, 0x0(r31)
  addi      r4, r30, 0x20
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      

.loc_0x58:
  lwz       r31, 0xC(r31)

.loc_0x5C:
  cmplwi    r31, 0
  bne+      .loc_0x20
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
 * Address:	800408D4
 * Size:	000064
 */
void NodeMgr::Del(Node *)
{
/*
.loc_0x0:
  li        r0, 0x1
  cmplwi    r4, 0
  stb       r0, 0x0(r3)
  beqlr-    
  lwz       r3, 0x8(r4)
  cmplwi    r3, 0
  beqlr-    
  lwz       r5, 0x10(r3)
  li        r3, 0
  b         .loc_0x58

.loc_0x28:
  cmplw     r5, r4
  bne-      .loc_0x50
  cmplwi    r3, 0
  beq-      .loc_0x44
  lwz       r0, 0xC(r5)
  stw       r0, 0xC(r3)
  blr       

.loc_0x44:
  lwz       r0, 0xC(r5)
  lwz       r3, 0x8(r4)
  stw       r0, 0x10(r3)

.loc_0x50:
  mr        r3, r5
  lwz       r5, 0xC(r5)

.loc_0x58:
  cmplwi    r5, 0
  bne+      .loc_0x28
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000EC
 */
void NodeMgr::recFindNode(CoreNode *, char *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void NodeMgr::findNode(char *, CoreNode *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80040938
 * Size:	00003C
 */
NodeMgr::NodeMgr()
{
/*
.loc_0x0:
  lis       r4, 0x8022
  addi      r0, r4, 0x738C
  lis       r4, 0x8022
  stw       r0, 0x4(r3)
  addi      r0, r4, 0x737C
  stw       r0, 0x4(r3)
  li        r5, 0
  lis       r4, 0x8023
  stw       r5, 0x14(r3)
  subi      r0, r4, 0x7274
  stw       r5, 0x10(r3)
  stw       r5, 0xC(r3)
  stw       r0, 0x8(r3)
  stb       r5, 0x0(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
NodeMgr::~NodeMgr()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80040974
 * Size:	000004
 */
void SRTNode::concat()
{
}

/*
 * --INFO--
 * Address:	80040978
 * Size:	000004
 */
void SRTNode::concat(Matrix4f &)
{
}

/*
 * --INFO--
 * Address:	8004097C
 * Size:	000008
 */
void SRTNode::getModelMatrix()
{
/*
.loc_0x0:
  addi      r3, r3, 0x20
  blr
*/
}
