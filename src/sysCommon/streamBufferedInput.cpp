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
 * Address:	80025500
 * Size:	000098
 */
void BufferedInputStream::init(Stream *, unsigned char *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r6, 0
  stw       r30, 0x20(r1)
  addi      r30, r5, 0
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  lwz       r3, 0x0(r4)
  bl        0x1AE10
  stw       r3, 0x0(r28)
  cmplwi    r30, 0
  stw       r31, 0xC(r28)
  beq-      .loc_0x4C
  mr        r3, r30
  b         .loc_0x58

.loc_0x4C:
  lwz       r3, 0xC(r28)
  li        r4, 0x20
  bl        0x21C14

.loc_0x58:
  stw       r3, 0x8(r28)
  li        r0, 0
  addi      r3, r28, 0
  stw       r0, 0x18(r28)
  stw       r0, 0x14(r28)
  stw       r0, 0x10(r28)
  stw       r29, 0x1C(r28)
  bl        0xE4
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
 * Address:	80025598
 * Size:	0000C0
 */
BufferedInputStream::BufferedInputStream(Stream *, unsigned char *, int)
{
/*
.loc_0x0:
  mflr      r0
  lis       r7, 0x8022
  stw       r0, 0x4(r1)
  addi      r0, r7, 0x7398
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r6
  stw       r30, 0x20(r1)
  addi      r30, r5, 0
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  lis       r3, 0x8022
  stw       r0, 0x4(r28)
  addi      r0, r3, 0x74C8
  lis       r3, 0x8022
  stw       r0, 0x4(r28)
  addi      r0, r3, 0x7464
  stw       r0, 0x4(r28)
  lwz       r3, 0x0(r4)
  bl        0x1AD54
  stw       r3, 0x0(r28)
  cmplwi    r30, 0
  stw       r31, 0xC(r28)
  beq-      .loc_0x70
  mr        r3, r30
  b         .loc_0x7C

.loc_0x70:
  lwz       r3, 0xC(r28)
  li        r4, 0x20
  bl        0x21B58

.loc_0x7C:
  stw       r3, 0x8(r28)
  li        r0, 0
  addi      r3, r28, 0
  stw       r0, 0x18(r28)
  stw       r0, 0x14(r28)
  stw       r0, 0x10(r28)
  stw       r29, 0x1C(r28)
  bl        .loc_0xC0
  mr        r3, r28
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  lwz       r28, 0x18(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr       

.loc_0xC0:
*/
}

/*
 * --INFO--
 * Address:	80025658
 * Size:	000088
 */
void BufferedInputStream::fillBuffer()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x14(r3)
  lwz       r0, 0x10(r31)
  sub.      r0, r0, r3
  bne-      .loc_0x74
  mr        r3, r31
  lwz       r12, 0x4(r31)
  lwz       r12, 0x44(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x10(r31)
  lwz       r0, 0x10(r31)
  lwz       r3, 0xC(r31)
  cmpw      r0, r3
  ble-      .loc_0x50
  stw       r3, 0x10(r31)

.loc_0x50:
  lwz       r3, 0x1C(r31)
  lwz       r4, 0x8(r31)
  lwz       r12, 0x4(r3)
  lwz       r5, 0x10(r31)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  li        r0, 0
  stw       r0, 0x14(r31)

.loc_0x74:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800256E0
 * Size:	000044
 */
void BufferedInputStream::getPending()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x1C(r3)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x44(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x18(r31)
  lwz       r31, 0x14(r1)
  sub       r3, r3, r0
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025724
 * Size:	000104
 */
void BufferedInputStream::read(void *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r5, 0
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  stw       r28, 0x18(r1)
  b         .loc_0xDC

.loc_0x2C:
  lwz       r3, 0x14(r30)
  lwz       r0, 0x10(r30)
  sub.      r0, r0, r3
  bne-      .loc_0x8C
  mr        r3, r30
  lwz       r12, 0x4(r30)
  lwz       r12, 0x44(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x10(r30)
  lwz       r0, 0x10(r30)
  lwz       r3, 0xC(r30)
  cmpw      r0, r3
  ble-      .loc_0x68
  stw       r3, 0x10(r30)

.loc_0x68:
  lwz       r3, 0x1C(r30)
  lwz       r4, 0x8(r30)
  lwz       r12, 0x4(r3)
  lwz       r5, 0x10(r30)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  li        r0, 0
  stw       r0, 0x14(r30)

.loc_0x8C:
  lwz       r4, 0x14(r30)
  mr        r28, r31
  lwz       r0, 0x10(r30)
  sub       r0, r0, r4
  cmpw      r31, r0
  ble-      .loc_0xA8
  mr        r28, r0

.loc_0xA8:
  lwz       r0, 0x8(r30)
  addi      r3, r29, 0
  addi      r5, r28, 0
  add       r4, r0, r4
  bl        -0x223C8
  lwz       r0, 0x14(r30)
  add       r29, r29, r28
  sub       r31, r31, r28
  add       r0, r0, r28
  stw       r0, 0x14(r30)
  lwz       r0, 0x18(r30)
  add       r0, r0, r28
  stw       r0, 0x18(r30)

.loc_0xDC:
  cmpwi     r31, 0
  bne+      .loc_0x2C
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
 * Address:	80025828
 * Size:	000030
 */
void BufferedInputStream::close()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r3, 0x1C(r3)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x4C(r12)
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
 * Address:	80025858
 * Size:	000008
 */
void BufferedInputStream::getPosition()
{
/*
.loc_0x0:
  lwz       r3, 0x18(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80025860
 * Size:	00002C
 */
void RandomAccessStream::getLength()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x48(r12)
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
 * Address:	8002588C
 * Size:	000008
 */
u32  RandomAccessStream::getPosition()
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	80025894
 * Size:	00005C
 */
void RandomAccessStream::getPending()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  stw       r30, 0x10(r1)
  mr        r30, r3
  lwz       r12, 0x4(r30)
  lwz       r12, 0x60(r12)
  mtlr      r12
  blrl      
  addi      r31, r3, 0
  addi      r3, r30, 0
  lwz       r12, 0x4(r30)
  lwz       r12, 0x58(r12)
  mtlr      r12
  blrl      
  sub       r3, r31, r3
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
