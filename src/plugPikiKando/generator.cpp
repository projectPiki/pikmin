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
 * Size:	0000F4
 */
void _Print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void writeID(RandomAccessStream &, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void readID(RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void printID(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void sprintID(char *, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DACB4
 * Size:	000030
 */
GenBase::GenBase(unsigned long, char *, char *)
{
/*
.loc_0x0:
  li        r0, 0
  lis       r7, 0x802C
  stw       r0, 0x0(r3)
  subi      r0, r7, 0x542C
  stw       r0, 0x4(r3)
  lis       r7, 0x5F5F
  addi      r0, r7, 0x5F5F
  stw       r4, 0x8(r3)
  stw       r5, 0x10(r3)
  stw       r6, 0x14(r3)
  stw       r0, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void GenBase::writeVersion(RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DACE4
 * Size:	00000C
 */
void GenBase::getLatestVersion()
{
/*
.loc_0x0:
  lis       r3, 0x7564
  addi      r3, r3, 0x6566
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00016C
 */
void GenBase::write(RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DACF0
 * Size:	000020
 */
void GenBase::ramSaveParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x7C210
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DAD10
 * Size:	000020
 */
void GenBase::ramLoadParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x7C184
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void GenBase::readVersion(RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void GenBase::read(RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DAD30
 * Size:	000004
 */
void GenBase::doRead(RandomAccessStream &)
{
}

/*
 * --INFO--
 * Address:	800DAD34
 * Size:	0000FC
 */
void makeObjectPiki()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x38
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  bl        -0x93D4C
  mr.       r30, r3
  beq-      .loc_0xDC
  li        r31, 0
  lis       r3, 0x802C
  stw       r31, 0x0(r30)
  subi      r0, r3, 0x542C
  lis       r3, 0x7069
  stw       r0, 0x4(r30)
  addi      r0, r3, 0x6B69
  lis       r3, 0x802C
  stw       r0, 0x8(r30)
  subi      r0, r3, 0x59C4
  lis       r3, 0x802C
  stw       r0, 0x10(r30)
  subi      r0, r3, 0x59B8
  lis       r3, 0x5F5F
  stw       r0, 0x14(r30)
  addi      r0, r3, 0x5F5F
  lis       r3, 0x802C
  stw       r0, 0xC(r30)
  subi      r0, r3, 0x5490
  lis       r3, 0x802C
  stw       r0, 0x4(r30)
  subi      r0, r3, 0x565C
  stw       r0, 0x4(r30)
  addi      r5, r1, 0x14
  addi      r4, r30, 0
  lwz       r0, -0x3A70(r13)
  addi      r3, r30, 0x18
  stw       r0, 0x1C(r1)
  lwz       r0, 0x1C(r1)
  stw       r0, 0x14(r1)
  bl        -0x7C354
  lis       r3, 0x802A
  addi      r29, r3, 0x60C4
  stw       r29, 0x20(r30)
  addi      r5, r1, 0x10
  addi      r4, r30, 0
  stw       r31, 0x24(r30)
  addi      r3, r30, 0x28
  lwz       r0, -0x3A6C(r13)
  stw       r0, 0x24(r1)
  lwz       r0, 0x24(r1)
  stw       r0, 0x10(r1)
  bl        -0x7C384
  stw       r29, 0x30(r30)
  stw       r31, 0x34(r30)

.loc_0xDC:
  mr        r3, r30
  lwz       r0, 0x3C(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void GenObjectFactory::getProduct(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void GenObjectFactory::createInstance()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DAE30
 * Size:	000050
 */
void GenObject::getLatestVersion()
{
/*
.loc_0x0:
  lwz       r7, 0x3074(r13)
  li        r4, 0
  lwz       r3, 0x8(r3)
  mr        r5, r4
  lwz       r0, 0x0(r7)
  cmpwi     r0, 0
  mtctr     r0
  blelr-    

.loc_0x20:
  lwz       r6, 0x8(r7)
  lwzx      r0, r6, r5
  cmplw     r3, r0
  bne-      .loc_0x40
  rlwinm    r0,r4,4,0,27
  add       r3, r6, r0
  lwz       r3, 0xC(r3)
  blr       

.loc_0x40:
  addi      r5, r5, 0x10
  addi      r4, r4, 0x1
  bdnz+     .loc_0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	800DAE80
 * Size:	00017C
 */
void makeTypeOne()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x68
  stw       r0, 0x4(r1)
  stwu      r1, -0x68(r1)
  stw       r31, 0x64(r1)
  stw       r30, 0x60(r1)
  stw       r29, 0x5C(r1)
  bl        -0x93E98
  mr.       r30, r3
  beq-      .loc_0x15C
  li        r31, 0
  lis       r3, 0x802C
  stw       r31, 0x0(r30)
  subi      r0, r3, 0x542C
  lis       r3, 0x316F
  stw       r0, 0x4(r30)
  addi      r0, r3, 0x6E65
  lis       r3, 0x802C
  stw       r0, 0x8(r30)
  subi      r0, r3, 0x59AC
  lis       r3, 0x802C
  stw       r0, 0x10(r30)
  subi      r0, r3, 0x59A0
  lis       r3, 0x5F5F
  stw       r0, 0x14(r30)
  addi      r0, r3, 0x5F5F
  lis       r3, 0x802C
  stw       r0, 0xC(r30)
  subi      r0, r3, 0x54C8
  stw       r0, 0x4(r30)
  addi      r3, r1, 0x34
  subi      r4, r13, 0x3A68
  bl        -0x8A428
  lwz       r0, 0x34(r1)
  addi      r5, r1, 0x20
  addi      r4, r30, 0
  stw       r0, 0x20(r1)
  addi      r3, r30, 0x18
  bl        -0x7C498
  lis       r3, 0x802A
  addi      r29, r3, 0x60C4
  stw       r29, 0x20(r30)
  addi      r3, r1, 0x3C
  subi      r4, r13, 0x3A64
  stw       r31, 0x24(r30)
  bl        -0x8A45C
  lwz       r0, 0x3C(r1)
  addi      r5, r1, 0x1C
  addi      r4, r30, 0
  stw       r0, 0x1C(r1)
  addi      r3, r30, 0x28
  bl        -0x7C4CC
  stw       r29, 0x30(r30)
  lis       r3, 0x802C
  subi      r0, r3, 0x56E0
  stw       r31, 0x34(r30)
  addi      r5, r1, 0x2C
  addi      r4, r30, 0
  stw       r0, 0x4(r30)
  addi      r3, r30, 0x38
  lwz       r0, -0x3A70(r13)
  stw       r0, 0x44(r1)
  lwz       r0, 0x44(r1)
  stw       r0, 0x2C(r1)
  bl        -0x7C500
  stw       r29, 0x40(r30)
  addi      r5, r1, 0x28
  addi      r4, r30, 0
  stw       r31, 0x44(r30)
  addi      r3, r30, 0x48
  lwz       r0, -0x3A6C(r13)
  stw       r0, 0x4C(r1)
  lwz       r0, 0x4C(r1)
  stw       r0, 0x28(r1)
  bl        -0x7C528
  stw       r29, 0x50(r30)
  addi      r5, r1, 0x24
  addi      r4, r30, 0
  stw       r31, 0x54(r30)
  addi      r3, r30, 0x58
  lwz       r0, -0x3A60(r13)
  stw       r0, 0x54(r1)
  lwz       r0, 0x54(r1)
  stw       r0, 0x24(r1)
  bl        -0x7C550
  stw       r29, 0x60(r30)
  stw       r31, 0x64(r30)

.loc_0x15C:
  mr        r3, r30
  lwz       r0, 0x6C(r1)
  lwz       r31, 0x64(r1)
  lwz       r30, 0x60(r1)
  lwz       r29, 0x5C(r1)
  addi      r1, r1, 0x68
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DAFFC
 * Size:	000130
 */
void makeTypeAtOnce()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x48
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  stw       r30, 0x40(r1)
  stw       r29, 0x3C(r1)
  bl        -0x94014
  mr.       r30, r3
  beq-      .loc_0x110
  li        r31, 0
  lis       r3, 0x802C
  stw       r31, 0x0(r30)
  subi      r0, r3, 0x542C
  lis       r3, 0x6174
  stw       r0, 0x4(r30)
  addi      r0, r3, 0x6F6E
  lis       r3, 0x802C
  stw       r0, 0x8(r30)
  subi      r0, r3, 0x59AC
  lis       r3, 0x802C
  stw       r0, 0x10(r30)
  subi      r0, r3, 0x5990
  lis       r3, 0x5F5F
  stw       r0, 0x14(r30)
  addi      r0, r3, 0x5F5F
  lis       r3, 0x802C
  stw       r0, 0xC(r30)
  subi      r0, r3, 0x54C8
  stw       r0, 0x4(r30)
  addi      r3, r1, 0x24
  subi      r4, r13, 0x3A68
  bl        -0x8A5A4
  lwz       r0, 0x24(r1)
  addi      r5, r1, 0x18
  addi      r4, r30, 0
  stw       r0, 0x18(r1)
  addi      r3, r30, 0x18
  bl        -0x7C614
  lis       r3, 0x802A
  addi      r29, r3, 0x60C4
  stw       r29, 0x20(r30)
  addi      r3, r1, 0x2C
  subi      r4, r13, 0x3A64
  stw       r31, 0x24(r30)
  bl        -0x8A5D8
  lwz       r0, 0x2C(r1)
  addi      r5, r1, 0x14
  addi      r4, r30, 0
  stw       r0, 0x14(r1)
  addi      r3, r30, 0x28
  bl        -0x7C648
  stw       r29, 0x30(r30)
  lis       r3, 0x802C
  subi      r0, r3, 0x5740
  stw       r31, 0x34(r30)
  addi      r5, r1, 0x1C
  addi      r4, r30, 0
  stw       r0, 0x4(r30)
  addi      r3, r30, 0x38
  lwz       r0, -0x3A70(r13)
  stw       r0, 0x34(r1)
  lwz       r0, 0x34(r1)
  stw       r0, 0x1C(r1)
  bl        -0x7C67C
  stw       r29, 0x40(r30)
  li        r0, 0x1
  stw       r0, 0x44(r30)

.loc_0x110:
  mr        r3, r30
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DB12C
 * Size:	00015C
 */
void makeTypeInitRand()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x58
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stw       r31, 0x54(r1)
  stw       r30, 0x50(r1)
  stw       r29, 0x4C(r1)
  bl        -0x94144
  mr.       r30, r3
  beq-      .loc_0x13C
  li        r31, 0
  lis       r3, 0x802C
  stw       r31, 0x0(r30)
  subi      r0, r3, 0x542C
  lis       r3, 0x6972
  stw       r0, 0x4(r30)
  addi      r0, r3, 0x6E64
  lis       r3, 0x802C
  stw       r0, 0x8(r30)
  subi      r0, r3, 0x59AC
  lis       r3, 0x802C
  stw       r0, 0x10(r30)
  subi      r0, r3, 0x597C
  lis       r3, 0x5F5F
  stw       r0, 0x14(r30)
  addi      r0, r3, 0x5F5F
  lis       r3, 0x802C
  stw       r0, 0xC(r30)
  subi      r0, r3, 0x54C8
  stw       r0, 0x4(r30)
  addi      r3, r1, 0x2C
  subi      r4, r13, 0x3A68
  bl        -0x8A6D4
  lwz       r0, 0x2C(r1)
  addi      r5, r1, 0x1C
  addi      r4, r30, 0
  stw       r0, 0x1C(r1)
  addi      r3, r30, 0x18
  bl        -0x7C744
  lis       r3, 0x802A
  addi      r29, r3, 0x60C4
  stw       r29, 0x20(r30)
  addi      r3, r1, 0x34
  subi      r4, r13, 0x3A64
  stw       r31, 0x24(r30)
  bl        -0x8A708
  lwz       r0, 0x34(r1)
  addi      r5, r1, 0x18
  addi      r4, r30, 0
  stw       r0, 0x18(r1)
  addi      r3, r30, 0x28
  bl        -0x7C778
  stw       r29, 0x30(r30)
  lis       r3, 0x802C
  subi      r0, r3, 0x57A4
  stw       r31, 0x34(r30)
  addi      r5, r1, 0x24
  addi      r4, r30, 0
  stw       r0, 0x4(r30)
  addi      r3, r30, 0x38
  lwz       r0, -0x3A70(r13)
  stw       r0, 0x3C(r1)
  lwz       r0, 0x3C(r1)
  stw       r0, 0x24(r1)
  bl        -0x7C7AC
  stw       r29, 0x40(r30)
  li        r0, 0x1
  addi      r5, r1, 0x20
  stw       r0, 0x44(r30)
  mr        r4, r30
  addi      r3, r30, 0x48
  lwz       r0, -0x3A6C(r13)
  stw       r0, 0x44(r1)
  lwz       r0, 0x44(r1)
  stw       r0, 0x20(r1)
  bl        -0x7C7D8
  stw       r29, 0x50(r30)
  li        r0, 0x5
  stw       r0, 0x54(r30)

.loc_0x13C:
  mr        r3, r30
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
 * Address:	........
 * Size:	000070
 */
void GenTypeFactory::getProduct(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001FC
 */
void GenTypeFactory::createInstance()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DB288
 * Size:	000050
 */
void GenType::getLatestVersion()
{
/*
.loc_0x0:
  lwz       r7, 0x3078(r13)
  li        r4, 0
  lwz       r3, 0x8(r3)
  mr        r5, r4
  lwz       r0, 0x0(r7)
  cmpwi     r0, 0
  mtctr     r0
  blelr-    

.loc_0x20:
  lwz       r6, 0x8(r7)
  lwzx      r0, r6, r5
  cmplw     r3, r0
  bne-      .loc_0x40
  rlwinm    r0,r4,4,0,27
  add       r3, r6, r0
  lwz       r3, 0xC(r3)
  blr       

.loc_0x40:
  addi      r5, r5, 0x10
  addi      r4, r4, 0x1
  bdnz+     .loc_0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	800DB2D8
 * Size:	00006C
 */
void GenType::ramSaveParameters(RandomAccessStream &)
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
 * Address:	800DB344
 * Size:	00006C
 */
void GenType::ramLoadParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  stw       r30, 0x18(r1)
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
 * Address:	800DB3B0
 * Size:	0000C0
 */
void GenTypeOne::ramSaveParameters(RandomAccessStream &)
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
  lwz       r12, 0x2C(r12)
  extsh     r4, r0
  mtlr      r12
  blrl      
  lwz       r12, 0x4(r31)
  mr        r3, r31
  lwz       r0, 0x54(r30)
  lwz       r12, 0x2C(r12)
  extsh     r4, r0
  mtlr      r12
  blrl      
  lwz       r12, 0x4(r31)
  mr        r3, r31
  lwz       r0, 0x64(r30)
  lwz       r12, 0x2C(r12)
  extsh     r4, r0
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
 * Address:	800DB470
 * Size:	0000C0
 */
void GenTypeOne::ramLoadParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  addi      r31, r4, 0
  stw       r30, 0x28(r1)
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
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  stw       r0, 0x44(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  stw       r0, 0x54(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  stw       r0, 0x64(r30)
  lwz       r0, 0x34(r1)
  lwz       r31, 0x2C(r1)
  lwz       r30, 0x28(r1)
  addi      r1, r1, 0x30
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DB530
 * Size:	000088
 */
void GenTypeAtOnce::ramSaveParameters(RandomAccessStream &)
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
 * Address:	800DB5B8
 * Size:	000088
 */
void GenTypeAtOnce::ramLoadParameters(RandomAccessStream &)
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
 * Address:	800DB640
 * Size:	0000A4
 */
void GenTypeInitRand::ramSaveParameters(RandomAccessStream &)
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
  lwz       r0, 0x54(r30)
  lwz       r12, 0x28(r12)
  rlwinm    r4,r0,0,24,31
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
 * Address:	800DB6E4
 * Size:	0000A4
 */
void GenTypeInitRand::ramLoadParameters(RandomAccessStream &)
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
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  rlwinm    r0,r3,0,24,31
  stw       r0, 0x54(r30)
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
 * Address:	800DB788
 * Size:	00007C
 */
void GenArea::doWrite(RandomAccessStream &)
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
  lfs       f1, 0x18(r30)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0x1C(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0x20(r30)
  lwz       r12, 0x4(r31)
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
 * Address:	800DB804
 * Size:	00007C
 */
void GenArea::doRead(RandomAccessStream &)
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
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x18(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x1C(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x20(r30)
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
 * Address:	800DB880
 * Size:	0000D8
 */
void makeCircleArea()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x34
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  bl        -0x94890
  addi      r31, r3, 0
  mr.       r4, r31
  beq-      .loc_0xC0
  li        r0, 0
  lis       r3, 0x802C
  stw       r0, 0x0(r31)
  subi      r0, r3, 0x542C
  lis       r3, 0x6369
  stw       r0, 0x4(r31)
  addi      r0, r3, 0x7263
  lis       r3, 0x802C
  stw       r0, 0x8(r31)
  subi      r0, r3, 0x5930
  lis       r3, 0x802C
  stw       r0, 0x10(r31)
  subi      r0, r3, 0x5924
  lis       r3, 0x5F5F
  stw       r0, 0x14(r31)
  addi      r0, r3, 0x5F5F
  lis       r3, 0x802C
  stw       r0, 0xC(r31)
  subi      r0, r3, 0x5538
  stw       r0, 0x4(r31)
  lis       r3, 0x802C
  subi      r0, r3, 0x5880
  lfs       f0, -0x6790(r2)
  addi      r5, r1, 0xC
  addi      r3, r4, 0x24
  stfs      f0, 0x20(r31)
  stfs      f0, 0x1C(r31)
  stfs      f0, 0x18(r31)
  stw       r0, 0x4(r31)
  lwz       r0, -0x3A70(r13)
  stw       r0, 0x14(r1)
  lwz       r0, 0x14(r1)
  stw       r0, 0xC(r1)
  bl        -0x7CEA8
  lis       r3, 0x802A
  addi      r0, r3, 0x6098
  stw       r0, 0x2C(r31)
  lfs       f0, -0x678C(r2)
  stfs      f0, 0x30(r31)

.loc_0xC0:
  mr        r3, r31
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DB958
 * Size:	000098
 */
void makePointArea()
{
/*
.loc_0x0:
  mflr      r0
  li        r3, 0x24
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  bl        -0x94964
  cmplwi    r3, 0
  beq-      .loc_0x88
  li        r0, 0
  lis       r4, 0x802C
  stw       r0, 0x0(r3)
  subi      r0, r4, 0x542C
  lis       r4, 0x7069
  stw       r0, 0x4(r3)
  addi      r0, r4, 0x6E74
  lis       r4, 0x802C
  stw       r0, 0x8(r3)
  subi      r0, r4, 0x5930
  lis       r4, 0x802C
  stw       r0, 0x10(r3)
  subi      r0, r4, 0x5914
  lis       r4, 0x5F5F
  stw       r0, 0x14(r3)
  addi      r0, r4, 0x5F5F
  lis       r4, 0x802C
  stw       r0, 0xC(r3)
  subi      r0, r4, 0x5538
  stw       r0, 0x4(r3)
  lis       r4, 0x802C
  subi      r0, r4, 0x581C
  lfs       f0, -0x6790(r2)
  stfs      f0, 0x20(r3)
  stfs      f0, 0x1C(r3)
  stfs      f0, 0x18(r3)
  stw       r0, 0x4(r3)

.loc_0x88:
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
void GenAreaFactory::getProduct(unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
void GenAreaFactory::createInstance()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DB9F0
 * Size:	000050
 */
void GenArea::getLatestVersion()
{
/*
.loc_0x0:
  lwz       r7, 0x307C(r13)
  li        r4, 0
  lwz       r3, 0x8(r3)
  mr        r5, r4
  lwz       r0, 0x0(r7)
  cmpwi     r0, 0
  mtctr     r0
  blelr-    

.loc_0x20:
  lwz       r6, 0x8(r7)
  lwzx      r0, r6, r5
  cmplw     r3, r0
  bne-      .loc_0x40
  rlwinm    r0,r4,4,0,27
  add       r3, r6, r0
  lwz       r3, 0xC(r3)
  blr       

.loc_0x40:
  addi      r5, r5, 0x10
  addi      r4, r4, 0x1
  bdnz+     .loc_0x20
  blr
*/
}

/*
 * --INFO--
 * Address:	800DBA40
 * Size:	000040
 */
void GenAreaCircle::ramSaveParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  lfs       f0, 0x30(r3)
  mr        r3, r4
  lwz       r12, 0x4(r4)
  fctiwz    f0, f0
  lwz       r12, 0x2C(r12)
  stfd      f0, 0x10(r1)
  mtlr      r12
  lwz       r4, 0x14(r1)
  blrl      
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DBA80
 * Size:	000060
 */
void GenAreaCircle::ramLoadParameters(RandomAccessStream &)
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
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6788(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0x1C(r1)
  lis       r0, 0x4330
  stw       r0, 0x18(r1)
  lfd       f0, 0x18(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x30(r31)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DBAE0
 * Size:	000170
 */
Generator::Generator()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x738C
  subi      r4, r13, 0x3A50
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  lis       r3, 0x8022
  stw       r30, 0x10(r1)
  li        r30, 0
  stw       r0, 0x0(r31)
  addi      r0, r3, 0x737C
  addi      r3, r31, 0
  stw       r0, 0x0(r31)
  stw       r30, 0x10(r31)
  stw       r30, 0xC(r31)
  stw       r30, 0x8(r31)
  bl        -0xB6C54
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x0(r31)
  addi      r3, r31, 0
  subi      r4, r13, 0x3A50
  bl        -0x9B404
  lis       r3, 0x802C
  subi      r0, r3, 0x5584
  stw       r0, 0x0(r31)
  addi      r3, r31, 0x58
  bl        -0x97CF8
  addi      r3, r31, 0x64
  bl        -0x97D00
  lfs       f0, -0x6790(r2)
  lis       r6, 0x7069
  lis       r3, 0x316F
  stfs      f0, 0xA0(r31)
  lis       r4, 0x2020
  addi      r7, r6, 0x6E74
  stfs      f0, 0x9C(r31)
  addi      r5, r3, 0x6E65
  addi      r0, r6, 0x6B69
  stfs      f0, 0x98(r31)
  addi      r3, r31, 0x58
  addi      r4, r4, 0x2020
  stfs      f0, 0xAC(r31)
  stfs      f0, 0xA8(r31)
  stfs      f0, 0xA4(r31)
  stw       r30, 0x20(r31)
  stw       r7, 0x24(r31)
  stw       r30, 0x28(r31)
  stw       r5, 0x2C(r31)
  lfs       f0, -0x3A5C(r13)
  stfs      f0, 0x98(r31)
  lfs       f0, -0x3A58(r13)
  stfs      f0, 0x9C(r31)
  lfs       f0, -0x3A54(r13)
  stfs      f0, 0xA0(r31)
  stw       r30, 0x30(r31)
  stw       r0, 0x34(r31)
  stw       r30, 0x74(r31)
  bl        -0x97D0C
  lis       r4, 0x7630
  addi      r3, r31, 0x64
  addi      r4, r4, 0x2E30
  bl        -0x97D1C
  addi      r3, r31, 0x38
  subi      r4, r13, 0x3A48
  bl        0x13D76C
  stw       r30, 0x7C(r31)
  lis       r3, 0x803A
  subi      r6, r13, 0x3A40
  stw       r30, 0x78(r31)
  li        r5, 0x1
  subi      r4, r3, 0x2848
  stw       r30, 0x84(r31)
  li        r0, -0x1
  addi      r3, r31, 0
  stw       r30, 0x88(r31)
  stw       r30, 0x10(r31)
  stw       r30, 0xC(r31)
  stw       r30, 0x8(r31)
  stw       r6, 0x4(r31)
  stb       r5, 0xB0(r31)
  lwz       r4, 0x2FC(r4)
  stw       r4, 0x8C(r31)
  stw       r0, 0x94(r31)
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
 * Address:	800DBC50
 * Size:	000154
 */
Generator::Generator(int)
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x738C
  subi      r4, r13, 0x3A50
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  lis       r3, 0x8022
  stw       r30, 0x10(r1)
  li        r30, 0
  stw       r0, 0x0(r31)
  addi      r0, r3, 0x737C
  addi      r3, r31, 0
  stw       r0, 0x0(r31)
  stw       r30, 0x10(r31)
  stw       r30, 0xC(r31)
  stw       r30, 0x8(r31)
  bl        -0xB6DC4
  lis       r3, 0x8023
  subi      r0, r3, 0x71E0
  stw       r0, 0x0(r31)
  addi      r3, r31, 0
  subi      r4, r13, 0x3A50
  bl        -0x9B574
  lis       r3, 0x802C
  subi      r0, r3, 0x5584
  stw       r0, 0x0(r31)
  addi      r3, r31, 0x58
  bl        -0x97E68
  addi      r3, r31, 0x64
  bl        -0x97E70
  lfs       f0, -0x6790(r2)
  lis       r6, 0x7069
  lis       r3, 0x316F
  stfs      f0, 0xA0(r31)
  lis       r4, 0x2020
  addi      r7, r6, 0x6E74
  stfs      f0, 0x9C(r31)
  addi      r5, r3, 0x6E65
  addi      r0, r6, 0x6B69
  stfs      f0, 0x98(r31)
  addi      r3, r31, 0x58
  addi      r4, r4, 0x2020
  stfs      f0, 0xAC(r31)
  stfs      f0, 0xA8(r31)
  stfs      f0, 0xA4(r31)
  stw       r30, 0x20(r31)
  stw       r7, 0x24(r31)
  stw       r30, 0x28(r31)
  stw       r5, 0x2C(r31)
  lfs       f0, -0x3A3C(r13)
  stfs      f0, 0x98(r31)
  lfs       f0, -0x3A38(r13)
  stfs      f0, 0x9C(r31)
  lfs       f0, -0x3A34(r13)
  stfs      f0, 0xA0(r31)
  stw       r30, 0x30(r31)
  stw       r0, 0x34(r31)
  bl        -0x97E78
  lis       r4, 0x7630
  addi      r3, r31, 0x64
  addi      r4, r4, 0x2E30
  bl        -0x97E88
  addi      r3, r31, 0x38
  subi      r4, r13, 0x3A48
  bl        0x13D600
  stw       r30, 0x7C(r31)
  subi      r5, r13, 0x3A40
  li        r4, 0x1
  stw       r30, 0x78(r31)
  li        r0, -0x1
  addi      r3, r31, 0
  stw       r30, 0x10(r31)
  stw       r30, 0xC(r31)
  stw       r30, 0x8(r31)
  stw       r5, 0x4(r31)
  stb       r4, 0xB0(r31)
  stw       r0, 0x94(r31)
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
 * Address:	........
 * Size:	000054
 */
Generator::~Generator()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void Generator::updateUseList()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DBDA4
 * Size:	000038
 */
void Generator::isExpired()
{
/*
.loc_0x0:
  lwz       r4, 0x94(r3)
  cmpwi     r4, -0x1
  bne-      .loc_0x14
  li        r3, 0
  blr       

.loc_0x14:
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x2FC(r3)
  cmpw      r4, r0
  bge-      .loc_0x30
  li        r3, 0x1
  blr       

.loc_0x30:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DBDDC
 * Size:	000104
 */
void Generator::loadCreature(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  addi      r31, r4, 0
  stw       r30, 0x48(r1)
  mr        r30, r3
  lwz       r0, 0x30(r3)
  cmplwi    r0, 0
  beq-      .loc_0xEC
  lfs       f0, -0x6790(r2)
  stfs      f0, 0x24(r1)
  stfs      f0, 0x20(r1)
  stfs      f0, 0x1C(r1)
  stfs      f0, 0x30(r1)
  stfs      f0, 0x2C(r1)
  stfs      f0, 0x28(r1)
  stfs      f0, 0x3C(r1)
  stfs      f0, 0x38(r1)
  stfs      f0, 0x34(r1)
  lwz       r3, 0x28(r30)
  cmplwi    r3, 0
  beq-      .loc_0x74
  lwz       r12, 0x4(r3)
  addi      r5, r30, 0
  addi      r4, r1, 0x1C
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      

.loc_0x74:
  lwz       r4, 0x30(r30)
  addi      r3, r1, 0x10
  lwz       r4, 0x8(r4)
  bl        -0x97FC8
  lwz       r3, 0x30(r30)
  addi      r4, r1, 0x1C
  lwz       r12, 0x4(r3)
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x84(r30)
  lwz       r3, 0x84(r30)
  cmplwi    r3, 0
  beq-      .loc_0xEC
  stw       r30, 0x64(r3)
  lwz       r3, 0x88(r30)
  addi      r0, r3, 0x1
  stw       r0, 0x88(r30)
  lwz       r0, 0x74(r30)
  rlwinm.   r0,r0,0,28,28
  beq-      .loc_0xDC
  lwz       r3, 0x84(r30)
  addi      r4, r31, 0
  li        r5, 0x1
  bl        -0x51E18
  b         .loc_0xEC

.loc_0xDC:
  lwz       r3, 0x84(r30)
  addi      r4, r31, 0
  li        r5, 0
  bl        -0x51E2C

.loc_0xEC:
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DBEE0
 * Size:	000078
 */
void Generator::saveCreature(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r3, 0x84(r3)
  cmplwi    r3, 0
  beq-      .loc_0x60
  lwz       r3, 0x6C(r3)
  bl        -0x474D4
  lwz       r0, 0x74(r30)
  rlwinm.   r0,r0,0,28,28
  beq-      .loc_0x50
  lwz       r3, 0x84(r30)
  addi      r4, r31, 0
  li        r5, 0x1
  bl        -0x51DB8
  b         .loc_0x60

.loc_0x50:
  lwz       r3, 0x84(r30)
  addi      r4, r31, 0
  li        r5, 0
  bl        -0x51DCC

.loc_0x60:
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
 * Address:	800DBF58
 * Size:	00023C
 */
void Generator::init()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stfd      f31, 0x48(r1)
  stw       r31, 0x44(r1)
  mr        r31, r3
  stw       r30, 0x40(r1)
  stw       r29, 0x3C(r1)
  lwz       r4, 0x94(r3)
  cmpwi     r4, -0x1
  bne-      .loc_0x34
  li        r0, 0
  b         .loc_0x54

.loc_0x34:
  lis       r3, 0x803A
  subi      r3, r3, 0x2848
  lwz       r0, 0x2FC(r3)
  cmpw      r4, r0
  bge-      .loc_0x50
  li        r0, 0x1
  b         .loc_0x54

.loc_0x50:
  li        r0, 0

.loc_0x54:
  rlwinm.   r0,r0,0,24,31
  beq-      .loc_0x68
  li        r0, 0
  stw       r0, 0x88(r31)
  b         .loc_0x21C

.loc_0x68:
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0x80
  li        r0, 0
  stw       r0, 0x88(r31)
  b         .loc_0x98

.loc_0x80:
  lwz       r0, 0x74(r31)
  rlwinm.   r0,r0,0,29,29
  bne-      .loc_0x98
  li        r0, 0
  stw       r0, 0x88(r31)
  b         .loc_0x21C

.loc_0x98:
  li        r0, 0
  stw       r0, 0x84(r31)
  lwz       r3, 0x20(r31)
  cmplwi    r3, 0
  beq-      .loc_0xC0
  lwz       r12, 0x4(r3)
  mr        r4, r31
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      

.loc_0xC0:
  lwz       r3, 0x30(r31)
  cmplwi    r3, 0
  beq-      .loc_0xE0
  lwz       r12, 0x4(r3)
  mr        r4, r31
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      

.loc_0xE0:
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x1F0
  lwz       r0, 0x74(r31)
  rlwinm.   r0,r0,0,29,29
  beq-      .loc_0x1F0
  lis       r4, 0x803A
  lwz       r3, 0x8C(r31)
  subi      r4, r4, 0x2848
  lwz       r0, 0x90(r31)
  lwz       r4, 0x2FC(r4)
  add       r0, r3, r0
  cmpw      r4, r0
  blt-      .loc_0x14C
  stw       r4, 0x8C(r31)
  lwz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x21C
  li        r0, 0
  stw       r0, 0x88(r31)
  mr        r4, r31
  lwz       r3, 0x28(r31)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  b         .loc_0x21C

.loc_0x14C:
  lwz       r30, 0x88(r31)
  li        r0, 0
  li        r29, 0
  stw       r0, 0x88(r31)
  lfs       f31, -0x6790(r2)
  b         .loc_0x1E4

.loc_0x164:
  stfs      f31, 0x14(r1)
  addi      r5, r31, 0
  addi      r4, r1, 0xC
  stfs      f31, 0x10(r1)
  stfs      f31, 0xC(r1)
  stfs      f31, 0x20(r1)
  stfs      f31, 0x1C(r1)
  stfs      f31, 0x18(r1)
  stfs      f31, 0x2C(r1)
  stfs      f31, 0x28(r1)
  stfs      f31, 0x24(r1)
  lwz       r3, 0x28(r31)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x30(r31)
  cmplwi    r3, 0
  beq-      .loc_0x1E0
  lwz       r12, 0x4(r3)
  addi      r4, r1, 0xC
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  beq-      .loc_0x1E0
  stw       r31, 0x64(r3)
  lwz       r4, 0x88(r31)
  addi      r0, r4, 0x1
  stw       r0, 0x88(r31)
  stw       r3, 0x84(r31)

.loc_0x1E0:
  addi      r29, r29, 0x1

.loc_0x1E4:
  cmpw      r29, r30
  blt+      .loc_0x164
  b         .loc_0x21C

.loc_0x1F0:
  lwz       r0, 0x28(r31)
  cmplwi    r0, 0
  beq-      .loc_0x21C
  li        r0, 0
  stw       r0, 0x88(r31)
  mr        r4, r31
  lwz       r3, 0x28(r31)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      

.loc_0x21C:
  lwz       r0, 0x54(r1)
  lfd       f31, 0x48(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DC194
 * Size:	000004
 */
void GenType::init(Generator *)
{
}

/*
 * --INFO--
 * Address:	800DC198
 * Size:	000004
 */
void GenArea::init(Generator *)
{
}

/*
 * --INFO--
 * Address:	800DC19C
 * Size:	000088
 */
void Generator::informDeath(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  stw       r30, 0x18(r1)
  mr        r30, r3
  lwz       r0, 0x84(r3)
  cmplw     r31, r0
  bne-      .loc_0x30
  li        r0, 0
  stw       r0, 0x84(r30)

.loc_0x30:
  lwz       r3, 0x88(r30)
  subi      r0, r3, 0x1
  stw       r0, 0x88(r30)
  lwz       r3, 0x6C(r31)
  cmpwi     r3, 0x37
  bne-      .loc_0x4C
  bl        -0x477AC

.loc_0x4C:
  lwz       r0, 0x88(r30)
  cmpwi     r0, 0
  bgt-      .loc_0x70
  li        r0, 0
  lis       r3, 0x803A
  stw       r0, 0x88(r30)
  subi      r3, r3, 0x2848
  lwz       r0, 0x2FC(r3)
  stw       r0, 0x8C(r30)

.loc_0x70:
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
 * Address:	800DC224
 * Size:	000004
 */
void Generator::update()
{
}

/*
 * --INFO--
 * Address:	800DC228
 * Size:	0001AC
 */
void Generator::render(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE0(r1)
  stw       r31, 0xDC(r1)
  addi      r31, r4, 0
  stw       r30, 0xD8(r1)
  addi      r30, r3, 0
  lwz       r5, 0x2DEC(r13)
  lwz       r0, 0x20(r5)
  cmplwi    r0, 0
  beq-      .loc_0x194
  lfs       f0, -0x6790(r2)
  addi      r6, r1, 0x38
  addi      r5, r1, 0x2C
  stfs      f0, 0x54(r1)
  addi      r3, r1, 0x98
  addi      r4, r1, 0x4C
  stfs      f0, 0x50(r1)
  stfs      f0, 0x4C(r1)
  lfs       f0, -0x6780(r2)
  stfs      f0, 0x4C(r1)
  stfs      f0, 0x50(r1)
  stfs      f0, 0x54(r1)
  lfs       f1, 0x98(r30)
  lfs       f0, 0xA4(r30)
  lfs       f5, 0xA0(r30)
  fadds     f1, f1, f0
  lfs       f4, 0xAC(r30)
  lfs       f3, 0x9C(r30)
  lfs       f2, 0xA8(r30)
  fadds     f4, f5, f4
  stfs      f1, 0x24(r1)
  fadds     f3, f3, f2
  lfs       f0, -0x3A30(r13)
  lfs       f2, 0x24(r1)
  stfs      f0, 0x2C(r1)
  lfs       f1, -0x3A2C(r13)
  stfs      f2, 0x38(r1)
  lfs       f0, -0x3A28(r13)
  stfs      f3, 0x3C(r1)
  stfs      f1, 0x30(r1)
  stfs      f4, 0x40(r1)
  stfs      f0, 0x34(r1)
  bl        -0x9E1E0
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x98
  addi      r5, r1, 0x58
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x58
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  li        r5, 0xFF
  lwz       r3, 0x2F54(r13)
  stb       r5, 0x44(r1)
  li        r4, 0x7D
  li        r0, 0
  stb       r4, 0x45(r1)
  addi      r4, r31, 0
  li        r6, 0
  stb       r0, 0x46(r1)
  stb       r5, 0x47(r1)
  lwz       r3, 0x44(r3)
  lwz       r0, 0x44(r1)
  stw       r0, 0x2C(r3)
  lwz       r3, 0x2F54(r13)
  lwz       r5, 0x2E4(r31)
  bl        -0xABEE0
  lwz       r3, 0x20(r30)
  cmplwi    r3, 0
  beq-      .loc_0x14C
  lwz       r12, 0x4(r3)
  addi      r4, r31, 0
  addi      r5, r30, 0
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      

.loc_0x14C:
  lwz       r3, 0x30(r30)
  cmplwi    r3, 0
  beq-      .loc_0x170
  lwz       r12, 0x4(r3)
  addi      r4, r31, 0
  addi      r5, r30, 0
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      

.loc_0x170:
  lwz       r3, 0x28(r30)
  cmplwi    r3, 0
  beq-      .loc_0x194
  lwz       r12, 0x4(r3)
  addi      r4, r31, 0
  addi      r5, r30, 0
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      

.loc_0x194:
  lwz       r0, 0xE4(r1)
  lwz       r31, 0xDC(r1)
  lwz       r30, 0xD8(r1)
  addi      r1, r1, 0xE0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DC3D4
 * Size:	000004
 */
void GenType::render(Graphics &, Generator *)
{
}

/*
 * --INFO--
 * Address:	800DC3D8
 * Size:	000004
 */
void GenArea::render(Graphics &, Generator *)
{
}

/*
 * --INFO--
 * Address:	800DC3DC
 * Size:	000734
 */
void Generator::read(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE8(r1)
  stw       r31, 0xE4(r1)
  addi      r31, r4, 0
  stw       r30, 0xE0(r1)
  addi      r30, r3, 0
  addi      r3, r30, 0x58
  stw       r29, 0xDC(r1)
  bl        -0x98364
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0xA8
  addi      r3, r30, 0x64
  addi      r4, r31, 0
  bl        -0x9837C
  lwz       r12, 0x4(r31)
  mr        r3, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0xAF(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0xAE(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0xAD(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0xAC(r1)
  lwz       r0, 0xAC(r1)
  stw       r0, 0x70(r30)

.loc_0xA8:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x74(r30)
  lis       r4, 0x7630
  addi      r3, r30, 0x64
  addi      r4, r4, 0x2E30
  bl        -0x984B4
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0x10C
  li        r29, 0

.loc_0xE0:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  addi      r0, r29, 0x38
  addi      r29, r29, 0x1
  stbx      r3, r30, r0
  cmpwi     r29, 0x20
  blt+      .loc_0xE0
  b         .loc_0x190

.loc_0x10C:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  stw       r0, 0x88(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  stw       r0, 0x8C(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  stw       r0, 0x90(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  stw       r0, 0x94(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x58(r12)
  mtlr      r12
  blrl      

.loc_0x190:
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x240
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6788(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0xD4(r1)
  lis       r29, 0x4330
  addi      r3, r31, 0
  stw       r29, 0xD0(r1)
  lfd       f0, 0xD0(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x98(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6788(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0xCC(r1)
  mr        r3, r31
  stw       r29, 0xC8(r1)
  lfd       f0, 0xC8(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0x9C(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  extsh     r0, r3
  lfd       f1, -0x6788(r2)
  xoris     r0, r0, 0x8000
  stw       r0, 0xC4(r1)
  stw       r29, 0xC0(r1)
  lfd       f0, 0xC0(r1)
  fsubs     f0, f0, f1
  stfs      f0, 0xA0(r30)
  b         .loc_0x288

.loc_0x240:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x98(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x9C(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0xA0(r30)

.loc_0x288:
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x2B0
  lfs       f0, -0x3A14(r13)
  stfs      f0, 0xA4(r30)
  lfs       f0, -0x3A10(r13)
  stfs      f0, 0xA8(r30)
  lfs       f0, -0x3A0C(r13)
  stfs      f0, 0xAC(r30)
  b         .loc_0x2F8

.loc_0x2B0:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0xA4(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0xA8(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0xAC(r30)

.loc_0x2F8:
  li        r0, 0
  stw       r0, 0x30(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0xAB(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0xAA(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0xA9(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0xA8(r1)
  lwz       r4, 0xA8(r1)
  lwz       r3, 0x3074(r13)
  bl        0x4A4
  stw       r3, 0x30(r30)
  lwz       r29, 0x30(r30)
  cmplwi    r29, 0
  beq-      .loc_0x458
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0x3F4
  lwz       r12, 0x4(r31)
  mr        r3, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x7B(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x7A(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x79(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x78(r1)
  lwz       r0, 0x78(r1)
  stw       r0, 0xC(r29)
  b         .loc_0x40C

.loc_0x3F4:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  stw       r3, 0xC(r29)

.loc_0x40C:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x44C
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  b         .loc_0x458

.loc_0x44C:
  addi      r3, r29, 0
  addi      r4, r31, 0
  bl        -0x7DC98

.loc_0x458:
  li        r0, 0
  stw       r0, 0x20(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x9B(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x9A(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x99(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x98(r1)
  lwz       r4, 0x98(r1)
  lwz       r3, 0x307C(r13)
  bl        0x2D8
  stw       r3, 0x20(r30)
  lwz       r29, 0x20(r30)
  cmplwi    r29, 0
  beq-      .loc_0x5B8
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0x554
  lwz       r12, 0x4(r31)
  mr        r3, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x77(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x76(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x75(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x74(r1)
  lwz       r0, 0x74(r1)
  stw       r0, 0xC(r29)
  b         .loc_0x56C

.loc_0x554:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  stw       r3, 0xC(r29)

.loc_0x56C:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x5AC
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  b         .loc_0x5B8

.loc_0x5AC:
  addi      r3, r29, 0
  addi      r4, r31, 0
  bl        -0x7DDF8

.loc_0x5B8:
  li        r0, 0
  stw       r0, 0x28(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x8B(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x8A(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x89(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x88(r1)
  lwz       r4, 0x88(r1)
  lwz       r3, 0x3078(r13)
  bl        .loc_0x734
  stw       r3, 0x28(r30)
  lwz       r29, 0x28(r30)
  cmplwi    r29, 0
  beq-      .loc_0x718
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0x6B4
  lwz       r12, 0x4(r31)
  mr        r3, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x73(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x72(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x71(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  stb       r3, 0x70(r1)
  lwz       r0, 0x70(r1)
  stw       r0, 0xC(r29)
  b         .loc_0x6CC

.loc_0x6B4:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  stw       r3, 0xC(r29)

.loc_0x6CC:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x70C
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  b         .loc_0x718

.loc_0x70C:
  addi      r3, r29, 0
  addi      r4, r31, 0
  bl        -0x7DF58

.loc_0x718:
  lwz       r0, 0xEC(r1)
  lwz       r31, 0xE4(r1)
  lwz       r30, 0xE0(r1)
  lwz       r29, 0xDC(r1)
  addi      r1, r1, 0xE8
  mtlr      r0
  blr       

.loc_0x734:
*/
}

/*
 * --INFO--
 * Address:	800DCB10
 * Size:	00006C
 */
void Factory<GenType>::create(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  li        r7, 0
  stw       r0, 0x4(r1)
  li        r5, 0
  stwu      r1, -0x8(r1)
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x58

.loc_0x24:
  lwz       r6, 0x8(r3)
  lwzx      r0, r6, r5
  cmplw     r4, r0
  bne-      .loc_0x4C
  rlwinm    r0,r7,4,0,27
  add       r3, r6, r0
  lwz       r12, 0x4(r3)
  mtlr      r12
  blrl      
  b         .loc_0x5C

.loc_0x4C:
  addi      r5, r5, 0x10
  addi      r7, r7, 0x1
  bdnz+     .loc_0x24

.loc_0x58:
  li        r3, 0

.loc_0x5C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DCB7C
 * Size:	00006C
 */
void Factory<GenArea>::create(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  li        r7, 0
  stw       r0, 0x4(r1)
  li        r5, 0
  stwu      r1, -0x8(r1)
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x58

.loc_0x24:
  lwz       r6, 0x8(r3)
  lwzx      r0, r6, r5
  cmplw     r4, r0
  bne-      .loc_0x4C
  rlwinm    r0,r7,4,0,27
  add       r3, r6, r0
  lwz       r12, 0x4(r3)
  mtlr      r12
  blrl      
  b         .loc_0x5C

.loc_0x4C:
  addi      r5, r5, 0x10
  addi      r7, r7, 0x1
  bdnz+     .loc_0x24

.loc_0x58:
  li        r3, 0

.loc_0x5C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DCBE8
 * Size:	00006C
 */
void Factory<GenObject>::create(unsigned long)
{
/*
.loc_0x0:
  mflr      r0
  li        r7, 0
  stw       r0, 0x4(r1)
  li        r5, 0
  stwu      r1, -0x8(r1)
  lwz       r0, 0x0(r3)
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x58

.loc_0x24:
  lwz       r6, 0x8(r3)
  lwzx      r0, r6, r5
  cmplw     r4, r0
  bne-      .loc_0x4C
  rlwinm    r0,r7,4,0,27
  add       r3, r6, r0
  lwz       r12, 0x4(r3)
  mtlr      r12
  blrl      
  b         .loc_0x5C

.loc_0x4C:
  addi      r5, r5, 0x10
  addi      r7, r7, 0x1
  bdnz+     .loc_0x24

.loc_0x58:
  li        r3, 0

.loc_0x5C:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DCC54
 * Size:	000760
 */
void Generator::write(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x98(r1)
  stw       r31, 0x94(r1)
  addi      r31, r4, 0
  stw       r30, 0x90(r1)
  addi      r30, r3, 0
  addi      r3, r30, 0x58
  stw       r29, 0x8C(r1)
  bl        -0x98C70
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0xA8
  addi      r3, r30, 0x64
  addi      r4, r31, 0
  bl        -0x98C88
  lwz       r0, 0x70(r30)
  mr        r3, r31
  stw       r0, 0x38(r1)
  lwz       r12, 0x4(r31)
  lbz       r4, 0x3B(r1)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x3A(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x39(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x38(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      

.loc_0xA8:
  mr        r3, r31
  lwz       r4, 0x74(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0xFC
  li        r29, 0

.loc_0xD0:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  addi      r0, r29, 0x38
  lbzx      r4, r30, r0
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  addi      r29, r29, 0x1
  cmpwi     r29, 0x20
  blt+      .loc_0xD0
  b         .loc_0x184

.loc_0xFC:
  mr        r3, r31
  lwz       r0, 0x88(r30)
  lwz       r12, 0x4(r31)
  extsh     r4, r0
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r0, 0x8C(r30)
  lwz       r12, 0x4(r31)
  extsh     r4, r0
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r4, 0x28(r30)
  lwz       r12, 0x4(r31)
  lwz       r0, 0x24(r4)
  lwz       r12, 0x2C(r12)
  extsh     r4, r0
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r0, 0x94(r30)
  lwz       r12, 0x4(r31)
  extsh     r4, r0
  lwz       r12, 0x2C(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x58(r12)
  mtlr      r12
  blrl      

.loc_0x184:
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x294
  lfs       f0, 0x98(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lis       r29, 0x4330
  fctiwz    f0, f0
  lwz       r12, 0x2C(r12)
  lfd       f2, -0x6788(r2)
  stfd      f0, 0x80(r1)
  mtlr      r12
  lfs       f0, 0xA4(r30)
  lwz       r0, 0x84(r1)
  extsh     r0, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x7C(r1)
  stw       r29, 0x78(r1)
  lfd       f1, 0x78(r1)
  fsubs     f1, f1, f2
  fadds     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x70(r1)
  lwz       r4, 0x74(r1)
  blrl      
  lfs       f0, 0x9C(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  fctiwz    f1, f0
  lfd       f2, -0x6788(r2)
  lwz       r12, 0x2C(r12)
  lfs       f0, 0xA8(r30)
  stfd      f1, 0x68(r1)
  mtlr      r12
  lwz       r0, 0x6C(r1)
  extsh     r0, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x64(r1)
  stw       r29, 0x60(r1)
  lfd       f1, 0x60(r1)
  fsubs     f1, f1, f2
  fadds     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x58(r1)
  lwz       r4, 0x5C(r1)
  blrl      
  lfs       f0, 0xA0(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  fctiwz    f1, f0
  lfd       f2, -0x6788(r2)
  lwz       r12, 0x2C(r12)
  lfs       f0, 0xAC(r30)
  stfd      f1, 0x50(r1)
  mtlr      r12
  lwz       r0, 0x54(r1)
  extsh     r0, r0
  xoris     r0, r0, 0x8000
  stw       r0, 0x4C(r1)
  stw       r29, 0x48(r1)
  lfd       f1, 0x48(r1)
  fsubs     f1, f1, f2
  fadds     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x40(r1)
  lwz       r4, 0x44(r1)
  blrl      
  b         .loc_0x324

.loc_0x294:
  mr        r3, r31
  lfs       f1, 0x98(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0x9C(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0xA0(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0xA4(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0xA8(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lfs       f1, 0xAC(r30)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      

.loc_0x324:
  lwz       r29, 0x30(r30)
  cmplwi    r29, 0
  beq-      .loc_0x46C
  lwz       r0, 0x8(r29)
  mr        r3, r31
  stw       r0, 0x2C(r1)
  lwz       r12, 0x4(r31)
  lbz       r4, 0x2F(r1)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x2E(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x2D(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x2C(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0x41C
  mr        r3, r29
  lwz       r12, 0x4(r29)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x20(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lbz       r4, 0x23(r1)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x22(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x21(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x20(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      

.loc_0x41C:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x45C
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  b         .loc_0x484

.loc_0x45C:
  addi      r3, r29, 0
  addi      r4, r31, 0
  bl        -0x7E5CC
  b         .loc_0x484

.loc_0x46C:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  li        r4, 0
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      

.loc_0x484:
  lwz       r29, 0x20(r30)
  cmplwi    r29, 0
  beq-      .loc_0x5CC
  lwz       r0, 0x8(r29)
  mr        r3, r31
  stw       r0, 0x28(r1)
  lwz       r12, 0x4(r31)
  lbz       r4, 0x2B(r1)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x2A(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x29(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x28(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0x57C
  mr        r3, r29
  lwz       r12, 0x4(r29)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x1C(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lbz       r4, 0x1F(r1)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x1E(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x1D(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x1C(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      

.loc_0x57C:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x5BC
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  b         .loc_0x5E4

.loc_0x5BC:
  addi      r3, r29, 0
  addi      r4, r31, 0
  bl        -0x7E72C
  b         .loc_0x5E4

.loc_0x5CC:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  li        r4, 0
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      

.loc_0x5E4:
  lwz       r29, 0x28(r30)
  cmplwi    r29, 0
  beq-      .loc_0x72C
  lwz       r0, 0x8(r29)
  mr        r3, r31
  stw       r0, 0x24(r1)
  lwz       r12, 0x4(r31)
  lbz       r4, 0x27(r1)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x26(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x25(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x24(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  bne-      .loc_0x6DC
  mr        r3, r29
  lwz       r12, 0x4(r29)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x18(r1)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lbz       r4, 0x1B(r1)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x1A(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x19(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lbz       r4, 0x18(r1)
  lwz       r12, 0x4(r31)
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      

.loc_0x6DC:
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lbz       r0, 0x3070(r13)
  cmplwi    r0, 0
  beq-      .loc_0x71C
  mr        r3, r29
  lwz       r12, 0x4(r29)
  mr        r4, r31
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  b         .loc_0x744

.loc_0x71C:
  addi      r3, r29, 0
  addi      r4, r31, 0
  bl        -0x7E88C
  b         .loc_0x744

.loc_0x72C:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  li        r4, 0
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      

.loc_0x744:
  lwz       r0, 0x9C(r1)
  lwz       r31, 0x94(r1)
  lwz       r30, 0x90(r1)
  lwz       r29, 0x8C(r1)
  addi      r1, r1, 0x98
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DD3B4
 * Size:	000514
 */
GeneratorMgr::GeneratorMgr()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r4, 0x738C
  subi      r5, r13, 0x39FC
  stwu      r1, -0x40(r1)
  lis       r4, 0x802C
  stw       r31, 0x3C(r1)
  subi      r31, r4, 0x59E0
  subi      r4, r13, 0x39FC
  stw       r30, 0x38(r1)
  stw       r29, 0x34(r1)
  addi      r29, r3, 0
  lis       r3, 0x8022
  stw       r28, 0x30(r1)
  li        r28, 0
  stw       r0, 0x0(r29)
  addi      r0, r3, 0x737C
  lis       r3, 0x8023
  stw       r0, 0x0(r29)
  subi      r0, r3, 0x71E0
  addi      r3, r29, 0
  stw       r28, 0x10(r29)
  stw       r28, 0xC(r29)
  stw       r28, 0x8(r29)
  stw       r5, 0x4(r29)
  stw       r0, 0x0(r29)
  bl        -0x9CCE4
  lis       r3, 0x802C
  subi      r0, r3, 0x55DC
  stw       r0, 0x0(r29)
  addi      r3, r29, 0x24
  bl        -0x995D8
  addi      r3, r29, 0x30
  bl        -0x995E0
  addi      r3, r29, 0x40
  bl        -0x995E8
  lfs       f1, -0x6790(r2)
  lis       r30, 0x7630
  addi      r3, r29, 0x24
  stfs      f1, 0x54(r29)
  addi      r4, r30, 0x2E31
  stfs      f1, 0x50(r29)
  stfs      f1, 0x4C(r29)
  lfs       f0, -0x3A08(r13)
  stfs      f0, 0x4C(r29)
  lfs       f0, -0x3A04(r13)
  stfs      f0, 0x50(r29)
  lfs       f0, -0x3A00(r13)
  stfs      f0, 0x54(r29)
  stfs      f1, 0x58(r29)
  stw       r28, 0x3C(r29)
  stw       r28, 0x20(r29)
  bl        -0x995C4
  addi      r3, r29, 0x30
  addi      r4, r30, 0x2E30
  bl        -0x995D0
  lwz       r0, 0x3074(r13)
  cmplwi    r0, 0
  bne-      .loc_0x1A0
  li        r3, 0x10
  bl        -0x964A4
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x11C
  li        r3, 0xC0
  bl        -0x964B8
  stw       r3, 0x8(r30)
  li        r0, 0xC
  stw       r0, 0x4(r30)
  stw       r28, 0x0(r30)

.loc_0x11C:
  stw       r30, 0x3074(r13)
  lwz       r5, 0x0(r30)
  lwz       r0, 0x4(r30)
  cmpw      r5, r0
  bge-      .loc_0x1A0
  lis       r4, 0x7069
  lwz       r3, 0x8(r30)
  addi      r4, r4, 0x6B69
  rlwinm    r0,r5,4,0,27
  stwx      r4, r3, r0
  lis       r4, 0x800E
  lis       r3, 0x7630
  lwz       r0, 0x0(r30)
  subi      r6, r4, 0x52CC
  lwz       r4, 0x8(r30)
  addi      r5, r31, 0x28
  rlwinm    r0,r0,4,0,27
  add       r4, r4, r0
  stw       r6, 0x4(r4)
  addi      r4, r3, 0x2E30
  lwz       r0, 0x0(r30)
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,4,0,27
  add       r3, r3, r0
  stw       r5, 0x8(r3)
  lwz       r0, 0x0(r30)
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,4,0,27
  add       r3, r3, r0
  stw       r4, 0xC(r3)
  lwz       r3, 0x0(r30)
  addi      r0, r3, 0x1
  stw       r0, 0x0(r30)

.loc_0x1A0:
  lwz       r0, 0x307C(r13)
  cmplwi    r0, 0
  bne-      .loc_0x318
  li        r3, 0x10
  bl        -0x96560
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x1DC
  li        r3, 0x60
  bl        -0x96574
  stw       r3, 0x8(r30)
  li        r3, 0x6
  li        r0, 0
  stw       r3, 0x4(r30)
  stw       r0, 0x0(r30)

.loc_0x1DC:
  stw       r30, 0x307C(r13)
  lwz       r5, 0x0(r30)
  lwz       r0, 0x4(r30)
  cmpw      r5, r0
  bge-      .loc_0x260
  lis       r4, 0x7069
  lwz       r3, 0x8(r30)
  addi      r4, r4, 0x6E74
  rlwinm    r0,r5,4,0,27
  stwx      r4, r3, r0
  lis       r4, 0x800E
  lis       r3, 0x7630
  lwz       r0, 0x0(r30)
  subi      r6, r4, 0x46A8
  lwz       r4, 0x8(r30)
  addi      r5, r31, 0xCC
  rlwinm    r0,r0,4,0,27
  add       r4, r4, r0
  stw       r6, 0x4(r4)
  addi      r4, r3, 0x2E30
  lwz       r0, 0x0(r30)
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,4,0,27
  add       r3, r3, r0
  stw       r5, 0x8(r3)
  lwz       r0, 0x0(r30)
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,4,0,27
  add       r3, r3, r0
  stw       r4, 0xC(r3)
  lwz       r3, 0x0(r30)
  addi      r0, r3, 0x1
  stw       r0, 0x0(r30)

.loc_0x260:
  lwz       r7, 0x307C(r13)
  lwz       r5, 0x0(r7)
  lwz       r0, 0x4(r7)
  cmpw      r5, r0
  bge-      .loc_0x2E4
  lis       r4, 0x6369
  lwz       r3, 0x8(r7)
  addi      r4, r4, 0x7263
  rlwinm    r0,r5,4,0,27
  stwx      r4, r3, r0
  lis       r4, 0x800E
  lis       r3, 0x7630
  lwz       r0, 0x0(r7)
  subi      r6, r4, 0x4780
  lwz       r4, 0x8(r7)
  addi      r5, r31, 0xD8
  rlwinm    r0,r0,4,0,27
  add       r4, r4, r0
  stw       r6, 0x4(r4)
  addi      r4, r3, 0x2E30
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

.loc_0x2E4:
  lwz       r5, 0x307C(r13)
  li        r4, 0
  lwz       r0, 0x0(r5)
  cmpwi     r0, 0
  mtctr     r0
  ble-      .loc_0x318

.loc_0x2FC:
  lwz       r3, 0x8(r5)
  lwzx      r3, r3, r4
  subis     r0, r3, 0x6369
  cmplwi    r0, 0x7263
  beq-      .loc_0x318
  addi      r4, r4, 0x10
  bdnz+     .loc_0x2FC

.loc_0x318:
  lwz       r0, 0x3078(r13)
  cmplwi    r0, 0
  bne-      .loc_0x4E0
  li        r3, 0x10
  bl        -0x966D8
  addi      r30, r3, 0
  mr.       r0, r30
  beq-      .loc_0x354
  li        r3, 0x60
  bl        -0x966EC
  stw       r3, 0x8(r30)
  li        r3, 0x6
  li        r0, 0
  stw       r3, 0x4(r30)
  stw       r0, 0x0(r30)

.loc_0x354:
  stw       r30, 0x3078(r13)
  lwz       r5, 0x0(r30)
  lwz       r0, 0x4(r30)
  cmpw      r5, r0
  bge-      .loc_0x3D8
  lis       r4, 0x316F
  lwz       r3, 0x8(r30)
  addi      r4, r4, 0x6E65
  rlwinm    r0,r5,4,0,27
  stwx      r4, r3, r0
  lis       r4, 0x800E
  lis       r3, 0x7630
  lwz       r0, 0x0(r30)
  subi      r6, r4, 0x5180
  lwz       r4, 0x8(r30)
  addi      r5, r31, 0x80
  rlwinm    r0,r0,4,0,27
  add       r4, r4, r0
  stw       r6, 0x4(r4)
  addi      r4, r3, 0x2E30
  lwz       r0, 0x0(r30)
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,4,0,27
  add       r3, r3, r0
  stw       r5, 0x8(r3)
  lwz       r0, 0x0(r30)
  lwz       r3, 0x8(r30)
  rlwinm    r0,r0,4,0,27
  add       r3, r3, r0
  stw       r4, 0xC(r3)
  lwz       r3, 0x0(r30)
  addi      r0, r3, 0x1
  stw       r0, 0x0(r30)

.loc_0x3D8:
  lwz       r7, 0x3078(r13)
  lwz       r5, 0x0(r7)
  lwz       r0, 0x4(r7)
  cmpw      r5, r0
  bge-      .loc_0x45C
  lis       r4, 0x6174
  lwz       r3, 0x8(r7)
  addi      r4, r4, 0x6F6E
  rlwinm    r0,r5,4,0,27
  stwx      r4, r3, r0
  lis       r4, 0x800E
  lis       r3, 0x7630
  lwz       r0, 0x0(r7)
  subi      r6, r4, 0x5004
  lwz       r4, 0x8(r7)
  addi      r5, r31, 0x8C
  rlwinm    r0,r0,4,0,27
  add       r4, r4, r0
  stw       r6, 0x4(r4)
  addi      r4, r3, 0x2E30
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

.loc_0x45C:
  lwz       r7, 0x3078(r13)
  lwz       r5, 0x0(r7)
  lwz       r0, 0x4(r7)
  cmpw      r5, r0
  bge-      .loc_0x4E0
  lis       r4, 0x6972
  lwz       r3, 0x8(r7)
  addi      r4, r4, 0x6E64
  rlwinm    r0,r5,4,0,27
  stwx      r4, r3, r0
  lis       r4, 0x800E
  lis       r3, 0x7630
  lwz       r0, 0x0(r7)
  subi      r6, r4, 0x4ED4
  lwz       r4, 0x8(r7)
  addi      r5, r31, 0x9C
  rlwinm    r0,r0,4,0,27
  add       r4, r4, r0
  stw       r6, 0x4(r4)
  addi      r4, r3, 0x2E30
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

.loc_0x4E0:
  li        r0, 0
  stb       r0, 0x5C(r29)
  addi      r0, r31, 0xF8
  addi      r3, r29, 0
  stw       r0, 0x4(r29)
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  lwz       r29, 0x34(r1)
  lwz       r28, 0x30(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DD8C8
 * Size:	000040
 */
void GeneratorMgr::init()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  lwz       r31, 0x20(r3)
  b         .loc_0x24

.loc_0x18:
  mr        r3, r31
  bl        -0x198C
  lwz       r31, 0x7C(r31)

.loc_0x24:
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
 * Address:	800DD908
 * Size:	00001C
 */
void GeneratorMgr::setDayLimit(int)
{
/*
.loc_0x0:
  lwz       r3, 0x20(r3)
  b         .loc_0x10

.loc_0x8:
  stw       r4, 0x94(r3)
  lwz       r3, 0x7C(r3)

.loc_0x10:
  cmplwi    r3, 0
  bne+      .loc_0x8
  blr
*/
}

/*
 * --INFO--
 * Address:	800DD924
 * Size:	0000A0
 */
void GeneratorMgr::updateUseList()
{
/*
.loc_0x0:
  mflr      r0
  lis       r4, 0x803A
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  subi      r31, r4, 0x2848
  stw       r30, 0x10(r1)
  lwz       r30, 0x20(r3)
  b         .loc_0x80

.loc_0x24:
  lwz       r3, 0x94(r30)
  cmpwi     r3, -0x1
  bne-      .loc_0x38
  li        r0, 0
  b         .loc_0x50

.loc_0x38:
  lwz       r0, 0x2FC(r31)
  cmpw      r3, r0
  bge-      .loc_0x4C
  li        r0, 0x1
  b         .loc_0x50

.loc_0x4C:
  li        r0, 0

.loc_0x50:
  rlwinm.   r0,r0,0,24,31
  bne-      .loc_0x7C
  lwz       r3, 0x30(r30)
  cmplwi    r3, 0
  beq-      .loc_0x7C
  lwz       r12, 0x4(r3)
  addi      r4, r30, 0
  li        r5, 0x1
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      

.loc_0x7C:
  lwz       r30, 0x7C(r30)

.loc_0x80:
  cmplwi    r30, 0
  bne+      .loc_0x24
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
 * Address:	800DD9C4
 * Size:	00004C
 */
void GeneratorMgr::update()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  lwz       r31, 0x20(r3)
  b         .loc_0x30

.loc_0x18:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  lwz       r31, 0x7C(r31)

.loc_0x30:
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
 * Address:	800DDA10
 * Size:	00005C
 */
void GeneratorMgr::render(Graphics &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r4
  lwz       r31, 0x20(r3)
  b         .loc_0x3C

.loc_0x20:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x18(r12)
  mtlr      r12
  blrl      
  lwz       r31, 0x7C(r31)

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
 * Address:	800DDA6C
 * Size:	000274
 */
void GeneratorMgr::read(RandomAccessStream &, bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r4, 0
  stw       r30, 0x20(r1)
  mr        r30, r3
  stw       r29, 0x1C(r1)
  stw       r28, 0x18(r1)
  addi      r28, r5, 0
  lwz       r6, 0x20(r3)
  cmplwi    r6, 0
  beq-      .loc_0x5C
  beq-      .loc_0x54
  lis       r3, 0x802C
  subi      r0, r3, 0x5584
  stw       r0, 0x0(r6)
  li        r0, 0
  addi      r3, r6, 0
  stw       r0, 0x7C(r6)
  bl        -0x96910

.loc_0x54:
  li        r0, 0
  stw       r0, 0x3C(r30)

.loc_0x5C:
  addi      r3, r30, 0x30
  addi      r4, r31, 0
  bl        -0x99A34
  lis       r4, 0x7630
  addi      r3, r30, 0x30
  addi      r4, r4, 0x2E30
  bl        -0x99B00
  rlwinm.   r0,r3,0,24,31
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x4C(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x50(r30)
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  lis       r4, 0x7630
  stfs      f1, 0x54(r30)
  addi      r3, r30, 0x30
  addi      r4, r4, 0x2E31
  bl        -0x99B5C
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xF4
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x58(r30)

.loc_0xF4:
  rlwinm.   r0,r28,0,24,31
  bne-      .loc_0x15C
  lwz       r3, 0x3120(r13)
  bl        0x39858
  cmplwi    r3, 0
  beq-      .loc_0x15C
  lwz       r4, 0x4C(r30)
  lwz       r0, 0x50(r30)
  stw       r4, 0x94(r3)
  stw       r0, 0x98(r3)
  lwz       r0, 0x54(r30)
  stw       r0, 0x9C(r3)
  lwz       r4, 0x4C(r30)
  lwz       r0, 0x50(r30)
  stw       r4, 0x1AC(r3)
  stw       r0, 0x1B0(r3)
  lwz       r0, 0x54(r30)
  stw       r0, 0x1B4(r3)
  lfs       f1, 0x58(r30)
  lfs       f0, -0x6778(r2)
  lfs       f2, -0x677C(r2)
  fdivs     f0, f1, f0
  fmuls     f0, f2, f0
  stfs      f0, 0xA0(r3)
  lfs       f0, 0xA0(r3)
  stfs      f0, 0x8C(r3)

.loc_0x15C:
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x3C(r30)
  li        r0, 0
  li        r28, 0
  stw       r0, 0x20(r30)
  b         .loc_0x248

.loc_0x184:
  lwz       r0, 0x20(r30)
  cmplwi    r0, 0
  bne-      .loc_0x1E0
  li        r3, 0xB8
  bl        -0x96BFC
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x1A8
  bl        -0x2130

.loc_0x1A8:
  stw       r29, 0x20(r30)
  mr        r4, r31
  lwz       r3, 0x20(r30)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x20(r30)
  stw       r30, 0x80(r3)
  lwz       r3, 0x3094(r13)
  lwz       r4, 0x20(r30)
  lwz       r3, 0x0(r3)
  bl        -0x9D66C
  b         .loc_0x244

.loc_0x1E0:
  li        r3, 0xB8
  bl        -0x96C4C
  addi      r29, r3, 0
  mr.       r3, r29
  beq-      .loc_0x1F8
  bl        -0x2180

.loc_0x1F8:
  stw       r30, 0x80(r29)
  mr        r3, r29
  mr        r4, r31
  lwz       r12, 0x0(r29)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x20(r30)
  b         .loc_0x220

.loc_0x21C:
  mr        r3, r0

.loc_0x220:
  lwz       r0, 0x7C(r3)
  cmplwi    r0, 0
  bne+      .loc_0x21C
  stw       r29, 0x7C(r3)
  mr        r4, r29
  stw       r3, 0x78(r29)
  lwz       r3, 0x3094(r13)
  lwz       r3, 0x0(r3)
  bl        -0x9D6D4

.loc_0x244:
  addi      r28, r28, 0x1

.loc_0x248:
  lwz       r0, 0x3C(r30)
  cmpw      r28, r0
  blt+      .loc_0x184
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
void GeneratorMgr::write(RandomAccessStream &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void GeneratorMgr::setNaviPos()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void GeneratorMgr::changeNaviPos()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DDCE0
 * Size:	00006C
 */
void GenObjectPiki::ramSaveParameters(RandomAccessStream &)
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
 * Address:	800DDD4C
 * Size:	00006C
 */
void GenObjectPiki::ramLoadParameters(RandomAccessStream &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  addi      r31, r4, 0
  stw       r30, 0x18(r1)
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
 * Address:	800DDDB8
 * Size:	000214
 */
void GenObjectPiki::birth(BirthInfo &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  li        r31, 0
  stw       r30, 0x40(r1)
  addi      r30, r4, 0
  stw       r29, 0x3C(r1)
  mr        r29, r3
  stw       r28, 0x38(r1)
  lwz       r12, 0x4(r29)
  lwz       r12, 0x20(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x34(r29)
  cmpwi     r0, 0x3
  mr        r28, r0
  bne-      .loc_0xA0
  bl        0x13A270
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6788(r2)
  stw       r0, 0x34(r1)
  lis       r0, 0x4330
  lfs       f2, -0x6770(r2)
  stw       r0, 0x30(r1)
  lfs       f1, -0x6774(r2)
  lfd       f3, 0x30(r1)
  lfs       f0, -0x676C(r2)
  fsubs     f3, f3, f4
  fdivs     f2, f3, f2
  fmuls     f1, f1, f2
  fmuls     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x20(r1)
  lwz       r0, 0x24(r1)
  stfd      f0, 0x28(r1)
  cmpwi     r0, 0x3
  lwz       r28, 0x2C(r1)
  blt-      .loc_0xA0
  li        r28, 0

.loc_0xA0:
  lwzu      r0, 0x24(r29)
  cmpwi     r0, 0
  beq-      .loc_0xBC
  blt-      .loc_0x1F0
  cmpwi     r0, 0x3
  bge-      .loc_0x1F0
  b         .loc_0x148

.loc_0xBC:
  lwz       r3, 0x30AC(r13)
  li        r4, 0xF
  lwz       r12, 0x0(r3)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  mr.       r29, r3
  beq-      .loc_0x1F0
  mr        r3, r29
  lwz       r12, 0x0(r29)
  mr        r4, r30
  lwz       r12, 0x28(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2F00(r13)
  li        r4, 0x1
  lfs       f1, 0x94(r29)
  lfs       f2, 0x9C(r29)
  bl        -0x75FB8
  stfs      f1, 0x98(r29)
  addi      r3, r29, 0
  addi      r4, r28, 0
  bl        0xEBD4
  mr        r3, r29
  lwz       r12, 0x0(r29)
  li        r4, 0
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2E8(r29)
  addi      r4, r29, 0
  li        r5, 0x6
  bl        -0x6079C
  mr        r31, r29
  b         .loc_0x1F0

.loc_0x148:
  lwz       r3, 0x3068(r13)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x78(r12)
  mtlr      r12
  blrl      
  mr.       r31, r3
  beq-      .loc_0x1F0
  lis       r3, 0x803D
  rlwinm    r4,r28,2,0,29
  addi      r0, r3, 0x1E88
  add       r4, r0, r4
  lwz       r3, 0x0(r4)
  addi      r0, r3, 0x1
  stw       r0, 0x0(r4)
  bl        0x34628
  lwz       r3, 0x3120(r13)
  bl        0x39484
  addi      r4, r3, 0
  addi      r3, r31, 0
  bl        -0x11F08
  addi      r3, r31, 0
  addi      r4, r30, 0
  bl        -0x53354
  addi      r3, r31, 0
  addi      r4, r28, 0
  bl        -0x146EC
  lwz       r0, 0x0(r29)
  cmpwi     r0, 0x1
  bne-      .loc_0x1D8
  lwz       r3, 0x3120(r13)
  bl        0x3944C
  addi      r5, r3, 0
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x10DBC
  b         .loc_0x1F0

.loc_0x1D8:
  lwz       r3, 0x3120(r13)
  bl        0x39430
  addi      r5, r3, 0
  addi      r3, r31, 0
  li        r4, 0x1
  bl        -0x10DD8

.loc_0x1F0:
  mr        r3, r31
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  lwz       r30, 0x40(r1)
  lwz       r29, 0x3C(r1)
  lwz       r28, 0x38(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void deg2rad(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DDFCC
 * Size:	0000A4
 */
void GenTypeOne::init(Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  mr        r31, r4
  mr        r5, r31
  lfs       f0, -0x6790(r2)
  addi      r4, r1, 0x10
  stfs      f0, 0x18(r1)
  stfs      f0, 0x14(r1)
  stfs      f0, 0x10(r1)
  stfs      f0, 0x24(r1)
  stfs      f0, 0x20(r1)
  stfs      f0, 0x1C(r1)
  stfs      f0, 0x30(r1)
  stfs      f0, 0x2C(r1)
  stfs      f0, 0x28(r1)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x30(r31)
  cmplwi    r3, 0
  beq-      .loc_0x90
  lwz       r12, 0x4(r3)
  addi      r4, r1, 0x10
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  beq-      .loc_0x90
  stw       r31, 0x64(r3)
  lwz       r4, 0x88(r31)
  addi      r0, r4, 0x1
  stw       r0, 0x88(r31)
  stw       r3, 0x84(r31)

.loc_0x90:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE070
 * Size:	0001B8
 */
void GenTypeOne::setBirthInfo(BirthInfo &, Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB8(r1)
  stw       r31, 0xB4(r1)
  addi      r31, r5, 0
  stw       r30, 0xB0(r1)
  mr        r30, r4
  stw       r29, 0xAC(r1)
  addi      r29, r3, 0
  lfs       f0, -0x6790(r2)
  stfs      f0, 0x88(r1)
  stfs      f0, 0x84(r1)
  stfs      f0, 0x80(r1)
  lwz       r4, 0x20(r5)
  cmplwi    r4, 0
  beq-      .loc_0x5C
  lwz       r12, 0x4(r4)
  addi      r5, r31, 0
  addi      r3, r1, 0x80
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  b         .loc_0x8C

.loc_0x5C:
  lfs       f1, 0x98(r31)
  lfs       f0, 0xA4(r31)
  lfs       f3, 0x9C(r31)
  lfs       f2, 0xA8(r31)
  fadds     f0, f1, f0
  lfs       f4, 0xA0(r31)
  lfs       f1, 0xAC(r31)
  fadds     f2, f3, f2
  stfs      f0, 0x80(r1)
  fadds     f0, f4, f1
  stfs      f2, 0x84(r1)
  stfs      f0, 0x88(r1)

.loc_0x8C:
  lfs       f0, -0x6790(r2)
  lis       r4, 0x4330
  stfs      f0, 0x7C(r1)
  stfs      f0, 0x78(r1)
  stfs      f0, 0x74(r1)
  lfd       f4, -0x6788(r2)
  lwz       r0, 0x44(r29)
  lfs       f2, -0x6778(r2)
  xoris     r0, r0, 0x8000
  lwz       r3, 0x54(r29)
  stw       r0, 0x94(r1)
  xoris     r0, r3, 0x8000
  lwz       r5, 0x64(r29)
  stw       r4, 0x90(r1)
  xoris     r3, r5, 0x8000
  lfs       f5, -0x677C(r2)
  lfd       f0, 0x90(r1)
  stw       r0, 0x9C(r1)
  fsubs     f0, f0, f4
  stw       r3, 0xA4(r1)
  fdivs     f0, f0, f2
  stw       r4, 0x98(r1)
  stw       r4, 0xA0(r1)
  lfd       f1, 0x98(r1)
  lfd       f3, 0xA0(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f5, f0
  fsubs     f3, f3, f4
  fdivs     f1, f1, f2
  stfs      f0, 0x74(r1)
  fdivs     f0, f3, f2
  fmuls     f1, f5, f1
  fmuls     f0, f5, f0
  stfs      f1, 0x78(r1)
  stfs      f0, 0x7C(r1)
  lfs       f1, 0x98(r31)
  lfs       f0, 0xA4(r31)
  lwz       r3, 0x80(r1)
  fadds     f0, f1, f0
  lwz       r0, 0x84(r1)
  stfs      f0, 0x3C(r1)
  lfs       f0, 0x3C(r1)
  stfs      f0, 0x58(r1)
  lfs       f1, 0x9C(r31)
  lfs       f0, 0xA8(r31)
  fadds     f0, f1, f0
  stfs      f0, 0x5C(r1)
  lfs       f1, 0xA0(r31)
  lfs       f0, 0xAC(r31)
  fadds     f0, f1, f0
  stfs      f0, 0x60(r1)
  stw       r3, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0x88(r1)
  stw       r0, 0x8(r30)
  lwz       r3, 0x74(r1)
  lwz       r0, 0x78(r1)
  stw       r3, 0xC(r30)
  stw       r0, 0x10(r30)
  lwz       r0, 0x7C(r1)
  stw       r0, 0x14(r30)
  lwz       r3, 0x58(r1)
  lwz       r0, 0x5C(r1)
  stw       r3, 0x18(r30)
  stw       r0, 0x1C(r30)
  lwz       r0, 0x60(r1)
  stw       r0, 0x20(r30)
  stw       r31, 0x24(r30)
  lwz       r0, 0xBC(r1)
  lwz       r31, 0xB4(r1)
  lwz       r30, 0xB0(r1)
  lwz       r29, 0xAC(r1)
  addi      r1, r1, 0xB8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE228
 * Size:	000168
 */
void GenTypeOne::render(Graphics &, Generator *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r8, 0x4330
  stw       r0, 0x4(r1)
  stwu      r1, -0x120(r1)
  stw       r31, 0x11C(r1)
  addi      r31, r4, 0
  addi      r6, r1, 0x4C
  lfs       f0, -0x6790(r2)
  addi      r4, r1, 0x74
  stfs      f0, 0x7C(r1)
  stfs      f0, 0x78(r1)
  stfs      f0, 0x74(r1)
  stfs      f0, 0x70(r1)
  stfs      f0, 0x6C(r1)
  stfs      f0, 0x68(r1)
  lfd       f4, -0x6788(r2)
  lwz       r0, 0x44(r3)
  lwz       r7, 0x54(r3)
  xoris     r0, r0, 0x8000
  lfs       f2, -0x6778(r2)
  stw       r0, 0x104(r1)
  xoris     r0, r7, 0x8000
  lwz       r3, 0x64(r3)
  stw       r8, 0x100(r1)
  xoris     r7, r3, 0x8000
  lfs       f5, -0x677C(r2)
  lfd       f0, 0x100(r1)
  addi      r3, r1, 0xC0
  stw       r0, 0x10C(r1)
  fsubs     f0, f0, f4
  stw       r7, 0x114(r1)
  fdivs     f0, f0, f2
  stw       r8, 0x108(r1)
  stw       r8, 0x110(r1)
  lfd       f1, 0x108(r1)
  lfd       f3, 0x110(r1)
  fsubs     f1, f1, f4
  fmuls     f0, f5, f0
  fsubs     f3, f3, f4
  fdivs     f1, f1, f2
  stfs      f0, 0x68(r1)
  fdivs     f0, f3, f2
  fmuls     f1, f5, f1
  fmuls     f0, f5, f0
  stfs      f1, 0x6C(r1)
  stfs      f0, 0x70(r1)
  lfs       f0, -0x6768(r2)
  stfs      f0, 0x74(r1)
  stfs      f0, 0x78(r1)
  stfs      f0, 0x7C(r1)
  lfs       f1, 0x98(r5)
  lfs       f0, 0xA4(r5)
  lfs       f4, 0xA0(r5)
  fadds     f0, f1, f0
  lfs       f3, 0xAC(r5)
  lfs       f2, 0x9C(r5)
  lfs       f1, 0xA8(r5)
  fadds     f3, f4, f3
  stfs      f0, 0x3C(r1)
  fadds     f1, f2, f1
  addi      r5, r1, 0x68
  lfs       f0, 0x3C(r1)
  stfs      f0, 0x4C(r1)
  stfs      f1, 0x50(r1)
  stfs      f3, 0x54(r1)
  bl        -0xA0238
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0xC0
  addi      r5, r1, 0x80
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x80
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x2F58(r13)
  mr        r4, r31
  lwz       r5, 0x2E4(r31)
  li        r6, 0
  bl        -0xADF0C
  lwz       r0, 0x124(r1)
  lwz       r31, 0x11C(r1)
  addi      r1, r1, 0x120
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE390
 * Size:	000008
 */
void GenTypeAtOnce::getMaxCount()
{
/*
.loc_0x0:
  lwz       r3, 0x44(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE398
 * Size:	0000E4
 */
void GenTypeAtOnce::init(Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x58(r1)
  stfd      f31, 0x50(r1)
  stw       r31, 0x4C(r1)
  stw       r30, 0x48(r1)
  li        r30, 0
  stw       r29, 0x44(r1)
  addi      r29, r4, 0
  stw       r28, 0x40(r1)
  mr        r28, r3
  lfs       f31, -0x6790(r2)
  lwz       r31, 0x44(r3)
  b         .loc_0xB8

.loc_0x38:
  stfs      f31, 0x1C(r1)
  addi      r3, r28, 0
  addi      r5, r29, 0
  stfs      f31, 0x18(r1)
  addi      r4, r1, 0x14
  stfs      f31, 0x14(r1)
  stfs      f31, 0x28(r1)
  stfs      f31, 0x24(r1)
  stfs      f31, 0x20(r1)
  stfs      f31, 0x34(r1)
  stfs      f31, 0x30(r1)
  stfs      f31, 0x2C(r1)
  lwz       r12, 0x4(r28)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x30(r29)
  cmplwi    r3, 0
  beq-      .loc_0xB4
  lwz       r12, 0x4(r3)
  addi      r4, r1, 0x14
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  beq-      .loc_0xB4
  stw       r29, 0x64(r3)
  lwz       r4, 0x88(r29)
  addi      r0, r4, 0x1
  stw       r0, 0x88(r29)
  stw       r3, 0x84(r29)

.loc_0xB4:
  addi      r30, r30, 0x1

.loc_0xB8:
  cmpw      r30, r31
  blt+      .loc_0x38
  lwz       r0, 0x5C(r1)
  lfd       f31, 0x50(r1)
  lwz       r31, 0x4C(r1)
  lwz       r30, 0x48(r1)
  lwz       r29, 0x44(r1)
  lwz       r28, 0x40(r1)
  addi      r1, r1, 0x58
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE47C
 * Size:	000138
 */
void GenTypeAtOnce::setBirthInfo(BirthInfo &, Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stw       r31, 0x5C(r1)
  addi      r31, r5, 0
  stw       r30, 0x58(r1)
  addi      r30, r4, 0
  lfs       f0, -0x6790(r2)
  stfs      f0, 0x54(r1)
  stfs      f0, 0x50(r1)
  stfs      f0, 0x4C(r1)
  lwz       r4, 0x20(r5)
  cmplwi    r4, 0
  beq-      .loc_0x54
  lwz       r12, 0x4(r4)
  addi      r5, r31, 0
  addi      r3, r1, 0x4C
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  b         .loc_0x84

.loc_0x54:
  lfs       f1, 0x98(r31)
  lfs       f0, 0xA4(r31)
  lfs       f3, 0x9C(r31)
  lfs       f2, 0xA8(r31)
  fadds     f0, f1, f0
  lfs       f4, 0xA0(r31)
  lfs       f1, 0xAC(r31)
  fadds     f2, f3, f2
  stfs      f0, 0x4C(r1)
  fadds     f0, f4, f1
  stfs      f2, 0x50(r1)
  stfs      f0, 0x54(r1)

.loc_0x84:
  lfs       f1, 0x98(r31)
  lfs       f0, 0xA4(r31)
  lfs       f2, -0x39F4(r13)
  fadds     f3, f1, f0
  lfs       f1, -0x39F0(r13)
  lfs       f0, -0x39EC(r13)
  lwz       r3, 0x4C(r1)
  stfs      f3, 0x20(r1)
  lwz       r0, 0x50(r1)
  lfs       f3, 0x20(r1)
  stfs      f3, 0x3C(r1)
  lfs       f4, 0x9C(r31)
  lfs       f3, 0xA8(r31)
  fadds     f3, f4, f3
  stfs      f3, 0x40(r1)
  lfs       f4, 0xA0(r31)
  lfs       f3, 0xAC(r31)
  stfs      f2, 0x30(r1)
  fadds     f2, f4, f3
  stfs      f1, 0x34(r1)
  stfs      f2, 0x44(r1)
  stfs      f0, 0x38(r1)
  stw       r3, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0x54(r1)
  stw       r0, 0x8(r30)
  lwz       r3, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r3, 0xC(r30)
  stw       r0, 0x10(r30)
  lwz       r0, 0x38(r1)
  stw       r0, 0x14(r30)
  lwz       r3, 0x3C(r1)
  lwz       r0, 0x40(r1)
  stw       r3, 0x18(r30)
  stw       r0, 0x1C(r30)
  lwz       r0, 0x44(r1)
  stw       r0, 0x20(r30)
  stw       r31, 0x24(r30)
  lwz       r0, 0x64(r1)
  lwz       r31, 0x5C(r1)
  lwz       r30, 0x58(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE5B4
 * Size:	000008
 */
void GenTypeInitRand::getMaxCount()
{
/*
.loc_0x0:
  lwz       r3, 0x54(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE5BC
 * Size:	000144
 */
void GenTypeInitRand::init(Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x78(r1)
  stfd      f31, 0x70(r1)
  stw       r31, 0x6C(r1)
  stw       r30, 0x68(r1)
  stw       r29, 0x64(r1)
  addi      r29, r4, 0
  stw       r28, 0x60(r1)
  addi      r28, r3, 0
  bl        0x139A8C
  xoris     r0, r3, 0x8000
  lfd       f3, -0x6788(r2)
  stw       r0, 0x5C(r1)
  lis       r3, 0x4330
  lfs       f0, -0x6770(r2)
  li        r30, 0
  stw       r3, 0x58(r1)
  lwz       r4, 0x44(r28)
  lfd       f1, 0x58(r1)
  lwz       r0, 0x54(r28)
  fsubs     f2, f1, f3
  lfs       f1, -0x6774(r2)
  sub       r0, r0, r4
  lfs       f31, -0x6790(r2)
  xoris     r0, r0, 0x8000
  fdivs     f2, f2, f0
  stw       r0, 0x54(r1)
  stw       r3, 0x50(r1)
  lfd       f0, 0x50(r1)
  fmuls     f1, f1, f2
  fsubs     f0, f0, f3
  fmuls     f0, f1, f0
  fctiwz    f0, f0
  stfd      f0, 0x48(r1)
  lwz       r0, 0x4C(r1)
  add       r31, r4, r0
  b         .loc_0x118

.loc_0x98:
  stfs      f31, 0x28(r1)
  addi      r3, r28, 0
  addi      r5, r29, 0
  stfs      f31, 0x24(r1)
  addi      r4, r1, 0x20
  stfs      f31, 0x20(r1)
  stfs      f31, 0x34(r1)
  stfs      f31, 0x30(r1)
  stfs      f31, 0x2C(r1)
  stfs      f31, 0x40(r1)
  stfs      f31, 0x3C(r1)
  stfs      f31, 0x38(r1)
  lwz       r12, 0x4(r28)
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x30(r29)
  cmplwi    r3, 0
  beq-      .loc_0x114
  lwz       r12, 0x4(r3)
  addi      r4, r1, 0x20
  lwz       r12, 0x34(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  beq-      .loc_0x114
  stw       r29, 0x64(r3)
  lwz       r4, 0x88(r29)
  addi      r0, r4, 0x1
  stw       r0, 0x88(r29)
  stw       r3, 0x84(r29)

.loc_0x114:
  addi      r30, r30, 0x1

.loc_0x118:
  cmpw      r30, r31
  blt+      .loc_0x98
  lwz       r0, 0x7C(r1)
  lfd       f31, 0x70(r1)
  lwz       r31, 0x6C(r1)
  lwz       r30, 0x68(r1)
  lwz       r29, 0x64(r1)
  lwz       r28, 0x60(r1)
  addi      r1, r1, 0x78
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE700
 * Size:	000138
 */
void GenTypeInitRand::setBirthInfo(BirthInfo &, Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x60(r1)
  stw       r31, 0x5C(r1)
  addi      r31, r5, 0
  stw       r30, 0x58(r1)
  addi      r30, r4, 0
  lfs       f0, -0x6790(r2)
  stfs      f0, 0x54(r1)
  stfs      f0, 0x50(r1)
  stfs      f0, 0x4C(r1)
  lwz       r4, 0x20(r5)
  cmplwi    r4, 0
  beq-      .loc_0x54
  lwz       r12, 0x4(r4)
  addi      r5, r31, 0
  addi      r3, r1, 0x4C
  lwz       r12, 0x30(r12)
  mtlr      r12
  blrl      
  b         .loc_0x84

.loc_0x54:
  lfs       f1, 0x98(r31)
  lfs       f0, 0xA4(r31)
  lfs       f3, 0x9C(r31)
  lfs       f2, 0xA8(r31)
  fadds     f0, f1, f0
  lfs       f4, 0xA0(r31)
  lfs       f1, 0xAC(r31)
  fadds     f2, f3, f2
  stfs      f0, 0x4C(r1)
  fadds     f0, f4, f1
  stfs      f2, 0x50(r1)
  stfs      f0, 0x54(r1)

.loc_0x84:
  lfs       f1, 0x98(r31)
  lfs       f0, 0xA4(r31)
  lfs       f2, -0x39E8(r13)
  fadds     f3, f1, f0
  lfs       f1, -0x39E4(r13)
  lfs       f0, -0x39E0(r13)
  lwz       r3, 0x4C(r1)
  stfs      f3, 0x20(r1)
  lwz       r0, 0x50(r1)
  lfs       f3, 0x20(r1)
  stfs      f3, 0x3C(r1)
  lfs       f4, 0x9C(r31)
  lfs       f3, 0xA8(r31)
  fadds     f3, f4, f3
  stfs      f3, 0x40(r1)
  lfs       f4, 0xA0(r31)
  lfs       f3, 0xAC(r31)
  stfs      f2, 0x30(r1)
  fadds     f2, f4, f3
  stfs      f1, 0x34(r1)
  stfs      f2, 0x44(r1)
  stfs      f0, 0x38(r1)
  stw       r3, 0x0(r30)
  stw       r0, 0x4(r30)
  lwz       r0, 0x54(r1)
  stw       r0, 0x8(r30)
  lwz       r3, 0x30(r1)
  lwz       r0, 0x34(r1)
  stw       r3, 0xC(r30)
  stw       r0, 0x10(r30)
  lwz       r0, 0x38(r1)
  stw       r0, 0x14(r30)
  lwz       r3, 0x3C(r1)
  lwz       r0, 0x40(r1)
  stw       r3, 0x18(r30)
  stw       r0, 0x1C(r30)
  lwz       r0, 0x44(r1)
  stw       r0, 0x20(r30)
  stw       r31, 0x24(r30)
  lwz       r0, 0x64(r1)
  lwz       r31, 0x5C(r1)
  lwz       r30, 0x58(r1)
  addi      r1, r1, 0x60
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE838
 * Size:	000088
 */
void GenAreaPoint::getPos(Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stw       r31, 0x4C(r1)
  addi      r31, r3, 0
  addi      r0, r1, 0x24
  lfs       f1, 0xA0(r5)
  addi      r6, r1, 0x28
  lfs       f0, 0xAC(r5)
  addi      r4, r1, 0x20
  addi      r3, r1, 0x2C
  fadds     f0, f1, f0
  stfs      f0, 0x28(r1)
  lfs       f1, 0x9C(r5)
  lfs       f0, 0xA8(r5)
  fadds     f0, f1, f0
  stfs      f0, 0x24(r1)
  lfs       f1, 0x98(r5)
  lfs       f0, 0xA4(r5)
  mr        r5, r0
  fadds     f0, f1, f0
  stfs      f0, 0x20(r1)
  bl        -0xA7774
  lfs       f1, 0x30(r1)
  lfs       f2, 0x34(r1)
  lfs       f0, 0x2C(r1)
  stfs      f0, 0x0(r31)
  stfs      f1, 0x4(r31)
  stfs      f2, 0x8(r31)
  lwz       r0, 0x54(r1)
  lwz       r31, 0x4C(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DE8C0
 * Size:	000004
 */
void GenAreaPoint::render(Graphics &, Generator *)
{
}

/*
 * --INFO--
 * Address:	800DE8C4
 * Size:	0001A4
 */
void GenAreaCircle::getPos(Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC8(r1)
  stfd      f31, 0xC0(r1)
  addi      r0, r1, 0x3C
  addi      r6, r1, 0x40
  stfd      f30, 0xB8(r1)
  stfd      f29, 0xB0(r1)
  stfd      f28, 0xA8(r1)
  stfd      f27, 0xA0(r1)
  stfd      f26, 0x98(r1)
  stw       r31, 0x94(r1)
  stw       r30, 0x90(r1)
  addi      r30, r4, 0
  stw       r29, 0x8C(r1)
  addi      r29, r3, 0
  addi      r3, r1, 0x38
  lfs       f1, 0xA0(r5)
  addi      r4, r3, 0
  lfs       f0, 0xAC(r5)
  addi      r3, r1, 0x4C
  fadds     f0, f1, f0
  stfs      f0, 0x40(r1)
  lfs       f1, 0x9C(r5)
  lfs       f0, 0xA8(r5)
  fadds     f0, f1, f0
  stfs      f0, 0x3C(r1)
  lfs       f1, 0x98(r5)
  lfs       f0, 0xA4(r5)
  mr        r5, r0
  fadds     f0, f1, f0
  stfs      f0, 0x38(r1)
  bl        -0xA7828
  lfs       f31, 0x4C(r1)
  lfs       f30, 0x50(r1)
  lfs       f29, 0x54(r1)
  bl        0x13971C
  xoris     r0, r3, 0x8000
  lfd       f3, -0x6788(r2)
  stw       r0, 0x84(r1)
  lis       r31, 0x4330
  lfs       f1, -0x6770(r2)
  stw       r31, 0x80(r1)
  lfs       f0, -0x6774(r2)
  lfd       f2, 0x80(r1)
  fsubs     f2, f2, f3
  fdivs     f1, f2, f1
  fmuls     f28, f0, f1
  bl        0x1396EC
  xoris     r0, r3, 0x8000
  lfs       f2, -0x6774(r2)
  stw       r0, 0x7C(r1)
  lfd       f5, -0x6788(r2)
  fsubs     f1, f2, f28
  stw       r31, 0x78(r1)
  lfs       f3, -0x6770(r2)
  lfd       f4, 0x78(r1)
  lfs       f0, 0x30(r30)
  fsubs     f4, f4, f5
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f1, f1, f2
  fadds     f27, f28, f1
  fmuls     f27, f27, f0
  bl        0x1396AC
  xoris     r0, r3, 0x8000
  lfd       f4, -0x6788(r2)
  stw       r0, 0x74(r1)
  lfs       f3, -0x6770(r2)
  stw       r31, 0x70(r1)
  lfs       f2, -0x6774(r2)
  lfd       f1, 0x70(r1)
  lfs       f0, -0x677C(r2)
  fsubs     f4, f1, f4
  lfs       f1, -0x6768(r2)
  fdivs     f3, f4, f3
  fmuls     f2, f2, f3
  fmuls     f0, f0, f2
  fmuls     f26, f1, f0
  fmr       f1, f26
  bl        0x13D150
  fmuls     f28, f27, f1
  fmr       f1, f26
  bl        0x13D2D8
  fmuls     f2, f27, f1
  lfs       f1, -0x39DC(r13)
  fadds     f0, f28, f29
  fadds     f3, f1, f30
  fadds     f1, f2, f31
  stfs      f1, 0x0(r29)
  stfs      f3, 0x4(r29)
  stfs      f0, 0x8(r29)
  lwz       r0, 0xCC(r1)
  lfd       f31, 0xC0(r1)
  lfd       f30, 0xB8(r1)
  lfd       f29, 0xB0(r1)
  lfd       f28, 0xA8(r1)
  lfd       f27, 0xA0(r1)
  lfd       f26, 0x98(r1)
  lwz       r31, 0x94(r1)
  lwz       r30, 0x90(r1)
  lwz       r29, 0x8C(r1)
  addi      r1, r1, 0xC8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DEA68
 * Size:	000130
 */
void GenAreaCircle::render(Graphics &, Generator *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xE8(r1)
  stw       r31, 0xE4(r1)
  addi      r31, r4, 0
  addi      r0, r1, 0x34
  lfs       f0, -0x6790(r2)
  addi      r6, r1, 0x40
  addi      r4, r1, 0x50
  stfs      f0, 0x58(r1)
  stfs      f0, 0x54(r1)
  stfs      f0, 0x50(r1)
  lfs       f1, -0x6764(r2)
  lfs       f2, 0x30(r3)
  addi      r3, r1, 0x9C
  lfs       f0, -0x39D8(r13)
  fdivs     f1, f2, f1
  stfs      f1, 0x50(r1)
  stfs      f0, 0x54(r1)
  stfs      f1, 0x58(r1)
  lfs       f1, 0x98(r5)
  lfs       f0, 0xA4(r5)
  lfs       f5, 0xA0(r5)
  fadds     f1, f1, f0
  lfs       f4, 0xAC(r5)
  lfs       f3, 0x9C(r5)
  lfs       f2, 0xA8(r5)
  fadds     f4, f5, f4
  stfs      f1, 0x2C(r1)
  fadds     f3, f3, f2
  lfs       f0, -0x39D4(r13)
  mr        r5, r0
  lfs       f2, 0x2C(r1)
  stfs      f0, 0x34(r1)
  lfs       f1, -0x39D0(r13)
  stfs      f2, 0x40(r1)
  lfs       f0, -0x39CC(r13)
  stfs      f3, 0x44(r1)
  stfs      f1, 0x38(r1)
  stfs      f4, 0x48(r1)
  stfs      f0, 0x3C(r1)
  bl        -0xA0A18
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x9C
  addi      r5, r1, 0x5C
  lwz       r12, 0x70(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x3B4(r31)
  addi      r4, r1, 0x5C
  li        r5, 0
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  li        r5, 0xFF
  lwz       r3, 0x2F5C(r13)
  stb       r5, 0x4C(r1)
  li        r0, 0
  addi      r4, r31, 0
  stb       r5, 0x4D(r1)
  li        r6, 0
  stb       r0, 0x4E(r1)
  stb       r5, 0x4F(r1)
  lwz       r3, 0x44(r3)
  lwz       r0, 0x4C(r1)
  stw       r0, 0x2C(r3)
  lwz       r3, 0x2F5C(r13)
  lwz       r5, 0x2E4(r31)
  bl        -0xAE714
  lwz       r0, 0xEC(r1)
  lwz       r31, 0xE4(r1)
  addi      r1, r1, 0xE8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DEB98
 * Size:	000058
 */
GeneratorList::GeneratorList()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  li        r3, 0xB8
  bl        -0x97BB0
  addi      r31, r3, 0
  mr.       r3, r31
  beq-      .loc_0x38
  lis       r4, 0x2
  subi      r4, r4, 0x1DC0
  bl        -0x2F7C

.loc_0x38:
  stw       r31, 0x0(r30)
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
 * Address:	800DEBF0
 * Size:	000038
 */
void GeneratorList::findGenerator(int)
{
/*
.loc_0x0:
  lwz       r3, 0x0(r3)
  lwz       r3, 0x10(r3)
  b         .loc_0x28

.loc_0xC:
  lbz       r0, 0xB0(r3)
  cmplwi    r0, 0
  bne-      .loc_0x24
  lwz       r0, 0xB4(r3)
  cmpw      r0, r4
  beqlr-    

.loc_0x24:
  lwz       r3, 0xC(r3)

.loc_0x28:
  cmplwi    r3, 0
  bne+      .loc_0xC
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	800DEC28
 * Size:	000070
 */
void GeneratorList::createRamGenerators()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  li        r31, 0
  stw       r30, 0x18(r1)
  li        r30, 0x1
  stw       r29, 0x14(r1)
  lwz       r3, 0x0(r3)
  lwz       r29, 0x10(r3)
  b         .loc_0x4C

.loc_0x2C:
  lbz       r0, 0xB0(r29)
  cmplwi    r0, 0
  bne-      .loc_0x48
  stb       r30, 0x3070(r13)
  mr        r3, r29
  bl        -0x2D10
  stb       r31, 0x3070(r13)

.loc_0x48:
  lwz       r29, 0xC(r29)

.loc_0x4C:
  cmplwi    r29, 0
  bne+      .loc_0x2C
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
 * Address:	800DEC98
 * Size:	0000B0
 */
void GeneratorList::updateUseList()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  lwz       r4, 0x0(r3)
  lis       r3, 0x803A
  subi      r31, r3, 0x2848
  lwz       r30, 0x10(r4)
  b         .loc_0x90

.loc_0x28:
  lbz       r0, 0xB0(r30)
  cmplwi    r0, 0
  bne-      .loc_0x8C
  lwz       r3, 0x94(r30)
  cmpwi     r3, -0x1
  bne-      .loc_0x48
  li        r0, 0
  b         .loc_0x60

.loc_0x48:
  lwz       r0, 0x2FC(r31)
  cmpw      r3, r0
  bge-      .loc_0x5C
  li        r0, 0x1
  b         .loc_0x60

.loc_0x5C:
  li        r0, 0

.loc_0x60:
  rlwinm.   r0,r0,0,24,31
  bne-      .loc_0x8C
  lwz       r3, 0x30(r30)
  cmplwi    r3, 0
  beq-      .loc_0x8C
  lwz       r12, 0x4(r3)
  addi      r4, r30, 0
  li        r5, 0x1
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      

.loc_0x8C:
  lwz       r30, 0xC(r30)

.loc_0x90:
  cmplwi    r30, 0
  bne+      .loc_0x28
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
 * Address:	800DED48
 * Size:	000008
 */
void GenAreaCircle::getRadius()
{
/*
.loc_0x0:
  lfs       f1, 0x30(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	800DED50
 * Size:	000004
 */
void GenArea::update(Generator *)
{
}

/*
 * --INFO--
 * Address:	800DED54
 * Size:	000008
 */
void GenArea::getRadius()
{
/*
.loc_0x0:
  lfs       f1, -0x6790(r2)
  blr
*/
}

/*
 * --INFO--
 * Address:	800DED5C
 * Size:	000004
 */
void GenType::update(Generator *)
{
}

/*
 * --INFO--
 * Address:	800DED60
 * Size:	000008
 */
u32  GenTypeOne::getMaxCount()
{
	return 0x1;
}
