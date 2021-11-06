#include "types.h"



/*
 * --INFO--
 * Address:	800250B0
 * Size:	000038
 */
void Stream::readInt()
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x4
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  lwz       r12, 0x4(r3)
  addi      r4, r1, 0xC
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0xC(r1)
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800250E8
 * Size:	000038
 */
void Stream::readByte()
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  lwz       r12, 0x4(r3)
  addi      r4, r1, 0xC
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lbz       r3, 0xC(r1)
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025120
 * Size:	000038
 */
void Stream::readShort()
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  lwz       r12, 0x4(r3)
  addi      r4, r1, 0xC
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lha       r3, 0xC(r1)
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025158
 * Size:	000038
 */
void Stream::readFloat()
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x4
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  lwz       r12, 0x4(r3)
  addi      r4, r1, 0xC
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lfs       f1, 0xC(r1)
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025190
 * Size:	00007C
 */
void Stream::readString()
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
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r31, r3, 0
  addi      r3, r31, 0x1
  bl        0x2B924
  addi      r0, r3, 0
  addi      r3, r30, 0
  lwz       r12, 0x4(r30)
  mr        r30, r0
  addi      r4, r30, 0
  lwz       r12, 0x3C(r12)
  addi      r5, r31, 0
  mtlr      r12
  blrl      
  li        r0, 0
  stbx      r0, r30, r31
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
 * Address:	8002520C
 * Size:	000038
 */
void Stream::readString(char *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r4, 0x18(r1)
  addi      r4, r1, 0x14
  stw       r5, 0x14(r1)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x1C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x24(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025244
 * Size:	0000A4
 */
void Stream::readString(String &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r4
  stw       r29, 0x14(r1)
  mr        r29, r3
  lwz       r12, 0x4(r29)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x0(r30)
  addi      r31, r3, 0
  cmpw      r0, r31
  bge-      .loc_0x60
  cmpwi     r31, 0
  beq-      .loc_0x54
  addi      r3, r31, 0x1
  bl        0x2B854
  b         .loc_0x58

.loc_0x54:
  li        r3, 0

.loc_0x58:
  stw       r3, 0x4(r30)
  stw       r31, 0x0(r30)

.loc_0x60:
  mr        r3, r29
  lwz       r4, 0x4(r30)
  lwz       r12, 0x4(r29)
  mr        r5, r31
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x4(r30)
  li        r0, 0
  stbx      r0, r3, r31
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
 * Address:	800252E8
 * Size:	000038
 */
void Stream::writeInt(int)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x4
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r4, 0x10(r1)
  addi      r4, r1, 0x10
  lwz       r12, 0x4(r3)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025320
 * Size:	000038
 */
void Stream::writeByte(unsigned char)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  stb       r4, 0xC(r1)
  addi      r4, r1, 0xC
  lwz       r12, 0x4(r3)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025358
 * Size:	000038
 */
void Stream::writeShort(short)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x2
  stw       r0, 0x4(r1)
  stwu      r1, -0x10(r1)
  sth       r4, 0xE(r1)
  addi      r4, r1, 0xE
  lwz       r12, 0x4(r3)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x14(r1)
  addi      r1, r1, 0x10
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025390
 * Size:	000038
 */
void Stream::writeFloat(float)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x4
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stfs      f1, 0x10(r1)
  addi      r4, r1, 0x10
  lwz       r12, 0x4(r3)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800253C8
 * Size:	00003C
 */
void Stream::writeString(char *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r4, 0x14(r1)
  addi      r4, r1, 0x10
  stw       r0, 0x10(r1)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x38(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x1C(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80025404
 * Size:	0000D4
 */
void Stream::writeString(String &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  stw       r29, 0x1C(r1)
  addi      r29, r4, 0
  stw       r28, 0x18(r1)
  addi      r28, r3, 0
  addi      r3, r29, 0
  bl        0x4C4
  addi      r0, r3, 0x3
  addi      r3, r28, 0
  lwz       r12, 0x4(r28)
  rlwinm    r31,r0,0,0,29
  addi      r4, r31, 0
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  mr        r3, r29
  bl        0x49C
  lwz       r12, 0x4(r28)
  mr        r5, r3
  lwz       r4, 0x4(r29)
  mr        r3, r28
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  li        r0, 0
  stb       r0, 0x10(r1)
  li        r30, 0
  b         .loc_0xA0

.loc_0x80:
  mr        r3, r28
  lwz       r12, 0x4(r28)
  addi      r4, r1, 0x10
  li        r5, 0x1
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  addi      r30, r30, 0x1

.loc_0xA0:
  mr        r3, r29
  bl        0x448
  sub       r0, r31, r3
  cmpw      r30, r0
  blt+      .loc_0x80
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
 * Size:	0000C4
 */
void Stream::print(char *, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void Stream::vPrintf(char *, std::@class$1stream_cpp *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800254D8
 * Size:	000004
 */
void Stream::read(void *, int)
{
}

/*
 * --INFO--
 * Address:	800254DC
 * Size:	000004
 */
void Stream::write(void *, int)
{
}

/*
 * --INFO--
 * Address:	800254E0
 * Size:	000008
 */
u32  Stream::getPending()
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	800254E8
 * Size:	000008
 */
u32  Stream::getAvailable()
{
	return 0x0;
}

/*
 * --INFO--
 * Address:	800254F0
 * Size:	000004
 */
void Stream::close()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void RandomAccessStream::writeTo(int, void *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800254F4
 * Size:	000004
 */
void RandomAccessStream::setPosition(int)
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void RandomAccessStream::readFrom(int, void *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void RandomAccessStream::writeIntTo(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void RandomAccessStream::readIntFrom(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800254F8
 * Size:	000008
 */
u32  Stream::getClosing()
{
	return 0x0;
}
