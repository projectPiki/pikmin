#include "types.h"



/*
 * --INFO--
 * Address:	........
 * Size:	000098
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
 * Address:	800438EC
 * Size:	000038
 */
void AtxStream::close()
{
/*
.loc_0x0:
  mflr      r0
  mr        r4, r3
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r5, 0x2DEC(r13)
  lwz       r3, 0x278(r5)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xC(r12)
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
 * Address:	80043924
 * Size:	0000D8
 */
void AtxStream::open(char *, int)
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
  lwz       r6, 0x2DEC(r13)
  lwz       r0, 0x278(r6)
  cmplwi    r0, 0
  mr        r3, r0
  bne-      .loc_0x38
  li        r3, 0
  b         .loc_0xC0

.loc_0x38:
  lwz       r12, 0x0(r3)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x68
  lwz       r4, 0x2DEC(r13)
  li        r0, 0
  li        r3, 0
  stw       r0, 0x278(r4)
  b         .loc_0xC0

.loc_0x68:
  mr        r3, r30
  lwz       r12, 0x4(r30)
  addi      r4, r31, 0
  li        r5, 0x4
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x8(r30)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0xFFFF
  bne-      .loc_0xA8
  li        r3, 0
  b         .loc_0xC0

.loc_0xA8:
  mr        r3, r30
  lwz       r12, 0x4(r30)
  lwz       r12, 0x54(r12)
  mtlr      r12
  blrl      
  li        r3, 0x1

.loc_0xC0:
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
 * Address:	800439FC
 * Size:	000094
 */
void AtxStream::write(void *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  addi      r30, r5, 0
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  stw       r28, 0x20(r1)
  addi      r28, r3, 0
  lwz       r6, 0x2DEC(r13)
  lwz       r31, 0x278(r6)
  lwz       r12, 0x0(r31)
  addi      r3, r31, 0
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x8(r28)
  addi      r4, r29, 0
  addi      r5, r30, 0
  lwz       r12, 0x4(r3)
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
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
 * Address:	........
 * Size:	000004
 */
void AtxRouter::unlock()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void AtxRouter::lock()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80043A90
 * Size:	000094
 */
void AtxStream::read(void *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x30(r1)
  stw       r31, 0x2C(r1)
  stw       r30, 0x28(r1)
  addi      r30, r5, 0
  stw       r29, 0x24(r1)
  addi      r29, r4, 0
  stw       r28, 0x20(r1)
  addi      r28, r3, 0
  lwz       r6, 0x2DEC(r13)
  lwz       r31, 0x278(r6)
  lwz       r12, 0x0(r31)
  addi      r3, r31, 0
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x8(r28)
  addi      r4, r29, 0
  addi      r5, r30, 0
  lwz       r12, 0x4(r3)
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
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
 * Address:	80043B24
 * Size:	000080
 */
void AtxStream::getPending()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r3
  lwz       r4, 0x2DEC(r13)
  lwz       r31, 0x278(r4)
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x8(r30)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x44(r12)
  mtlr      r12
  blrl      
  addi      r0, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  mr        r31, r0
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
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
 * Address:	80043BA4
 * Size:	000074
 */
void AtxStream::flush()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  mr        r30, r3
  lwz       r4, 0x2DEC(r13)
  lwz       r31, 0x278(r4)
  lwz       r12, 0x0(r31)
  mr        r3, r31
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x8(r30)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x54(r12)
  mtlr      r12
  blrl      
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
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
 * Address:	........
 * Size:	0000D0
 */
void AtxCommandStream::checkCommands()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
void AtxFileStream::open(char *, unsigned long)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80043C18
 * Size:	00005C
 */
void AtxFileStream::setPosition(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  stw       r4, 0x8(r3)
  addi      r3, r31, 0x10
  li        r4, 0x66
  lwz       r12, 0x14(r31)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  addi      r3, r31, 0x10
  lwz       r4, 0x8(r31)
  lwz       r12, 0x14(r31)
  lwz       r12, 0x24(r12)
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
 * Address:	80043C74
 * Size:	000098
 */
void AtxFileStream::read(void *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r5, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  li        r4, 0x64
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  addi      r3, r29, 0x10
  lwz       r12, 0x14(r29)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  addi      r3, r29, 0x10
  lwz       r12, 0x14(r29)
  mr        r4, r31
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  addi      r3, r29, 0x10
  lwz       r12, 0x14(r29)
  addi      r4, r30, 0
  addi      r5, r31, 0
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x8(r29)
  add       r0, r0, r31
  stw       r0, 0x8(r29)
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80043D0C
 * Size:	0000AC
 */
void AtxFileStream::write(void *, int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  addi      r31, r5, 0
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  li        r4, 0x65
  stw       r29, 0x1C(r1)
  addi      r29, r3, 0
  addi      r3, r29, 0x10
  lwz       r12, 0x14(r29)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  addi      r3, r29, 0x10
  lwz       r12, 0x14(r29)
  mr        r4, r31
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  addi      r3, r29, 0x10
  lwz       r12, 0x14(r29)
  addi      r4, r30, 0
  addi      r5, r31, 0
  lwz       r12, 0x40(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x8(r29)
  add       r0, r0, r31
  stw       r0, 0x8(r29)
  lwz       r3, 0x8(r29)
  lwz       r0, 0xC(r29)
  cmpw      r3, r0
  ble-      .loc_0x90
  stw       r3, 0xC(r29)

.loc_0x90:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  lwz       r30, 0x20(r1)
  lwz       r29, 0x1C(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	80043DB8
 * Size:	00007C
 */
void AtxFileStream::close()
{
/*
.loc_0x0:
  mflr      r0
  li        r4, 0x67
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  addi      r3, r31, 0x10
  lwz       r12, 0x14(r31)
  lwz       r12, 0x24(r12)
  mtlr      r12
  blrl      
  addi      r3, r31, 0x10
  lwz       r12, 0x14(r31)
  lwz       r12, 0x54(r12)
  mtlr      r12
  blrl      
  addi      r3, r31, 0x10
  lwz       r12, 0x14(r31)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  addi      r3, r31, 0x10
  lwz       r12, 0x14(r31)
  lwz       r12, 0x4C(r12)
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
 * Address:	80043E34
 * Size:	000010
 */
void AtxFileStream::getPending()
{
/*
.loc_0x0:
  lwz       r4, 0x8(r3)
  lwz       r0, 0xC(r3)
  sub       r3, r0, r4
  blr
*/
}

/*
 * --INFO--
 * Address:	80043E44
 * Size:	000008
 */
void AtxFileStream::getPosition()
{
/*
.loc_0x0:
  lwz       r3, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80043E4C
 * Size:	000008
 */
void AtxFileStream::getLength()
{
/*
.loc_0x0:
  lwz       r3, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80043E54
 * Size:	000008
 */
void AtxFileStream::setLength(int a1)
{
// Generated from stw r4, 0xC(r3)
_0C = a1;
}
