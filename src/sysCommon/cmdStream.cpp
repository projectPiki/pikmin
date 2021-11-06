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
 * Size:	0000AC
 */
void CmdStream::init(Stream *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
CmdStream::CmdStream()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80040B7C
 * Size:	0000B0
 */
CmdStream::CmdStream(Stream *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  li        r0, 0
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r4
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  stw       r0, 0x4(r3)
  lwz       r0, 0x2DE0(r13)
  cmplwi    r0, 0
  bne-      .loc_0x40
  lis       r3, 0x1
  subi      r3, r3, 0x8000
  bl        0x6450
  stw       r3, 0x2DE0(r13)

.loc_0x40:
  lis       r4, 0x1
  lwz       r3, 0x2DE0(r13)
  subi      r5, r4, 0x8000
  li        r4, 0
  bl        -0x3D8AC
  stw       r31, 0x0(r30)
  lwz       r3, 0x0(r30)
  lwz       r12, 0x4(r3)
  lwz       r12, 0x44(r12)
  mtlr      r12
  blrl      
  stw       r3, 0x108(r30)
  li        r0, 0
  addi      r3, r30, 0
  stw       r0, 0x114(r30)
  li        r4, 0x1
  stw       r0, 0x10C(r30)
  stw       r0, 0x110(r30)
  lwz       r0, 0x2DE0(r13)
  stw       r0, 0x4(r30)
  bl        .loc_0xB0
  mr        r3, r30
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0xB0:
*/
}

/*
 * --INFO--
 * Address:	80040C2C
 * Size:	0000EC
 */
void CmdStream::fillBuffer(bool)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  rlwinm.   r0,r4,0,24,31
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  stw       r30, 0x10(r1)
  bne-      .loc_0x34
  lwz       r3, 0x110(r31)
  lwz       r0, 0x114(r31)
  sub       r0, r0, r3
  cmpwi     r0, 0x4000
  blt-      .loc_0xD4

.loc_0x34:
  lwz       r0, 0x10C(r31)
  cmpwi     r0, 0
  beq-      .loc_0x74
  lwz       r0, 0x110(r31)
  li        r5, 0x4000
  lwz       r3, 0x4(r31)
  add       r3, r3, r0
  addi      r4, r3, 0
  addi      r4, r4, 0x4000
  bl        -0x3D870
  lwz       r3, 0x4(r31)
  subi      r0, r3, 0x4000
  stw       r0, 0x4(r31)
  lwz       r3, 0x110(r31)
  addi      r0, r3, 0x4000
  stw       r0, 0x110(r31)

.loc_0x74:
  lwz       r4, 0x10C(r31)
  cmpwi     r4, 0
  beq-      .loc_0x88
  li        r3, 0x4000
  b         .loc_0x90

.loc_0x88:
  lis       r3, 0x1
  subi      r3, r3, 0x8000

.loc_0x90:
  lwz       r0, 0x108(r31)
  addi      r30, r3, 0
  sub       r0, r0, r4
  cmpw      r0, r3
  bge-      .loc_0xA8
  mr        r30, r0

.loc_0xA8:
  lwz       r3, 0x0(r31)
  mr        r5, r30
  lwz       r0, 0x4(r31)
  lwz       r12, 0x4(r3)
  add       r4, r0, r4
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x10C(r31)
  add       r0, r0, r30
  stw       r0, 0x10C(r31)

.loc_0xD4:
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
 * Address:	80040D18
 * Size:	000040
 */
void CmdStream::whiteSpace(char)
{
/*
.loc_0x0:
  rlwinm.   r3,r4,0,24,31
  beq-      .loc_0x30
  cmplwi    r3, 0xD
  beq-      .loc_0x30
  subi      r0, r4, 0x9
  rlwinm    r0,r0,0,24,31
  cmplwi    r0, 0x1
  ble-      .loc_0x30
  cmplwi    r3, 0x20
  beq-      .loc_0x30
  cmplwi    r3, 0x2C
  bne-      .loc_0x38

.loc_0x30:
  li        r3, 0x1
  blr       

.loc_0x38:
  li        r3, 0
  blr
*/
}

/*
 * --INFO--
 * Address:	80040D58
 * Size:	000174
 */
void CmdStream::endOfCmds()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  stw       r30, 0x10(r1)
  lwz       r3, 0x110(r3)
  lwz       r0, 0x114(r31)
  sub       r0, r0, r3
  cmpwi     r0, 0x4000
  blt-      .loc_0xD4
  lwz       r0, 0x10C(r31)
  cmpwi     r0, 0
  beq-      .loc_0x68
  lwz       r0, 0x4(r31)
  li        r5, 0x4000
  add       r3, r0, r3
  addi      r4, r3, 0
  addi      r4, r4, 0x4000
  bl        -0x3D990
  lwz       r3, 0x4(r31)
  subi      r0, r3, 0x4000
  stw       r0, 0x4(r31)
  lwz       r3, 0x110(r31)
  addi      r0, r3, 0x4000
  stw       r0, 0x110(r31)

.loc_0x68:
  lwz       r4, 0x10C(r31)
  cmpwi     r4, 0
  beq-      .loc_0x7C
  li        r30, 0x4000
  b         .loc_0x84

.loc_0x7C:
  lis       r3, 0x1
  subi      r30, r3, 0x8000

.loc_0x84:
  lwz       r0, 0x108(r31)
  sub       r0, r0, r4
  cmpw      r0, r30
  bge-      .loc_0x98
  mr        r30, r0

.loc_0x98:
  lwz       r3, 0x0(r31)
  mr        r5, r30
  lwz       r0, 0x4(r31)
  lwz       r12, 0x4(r3)
  add       r4, r0, r4
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x10C(r31)
  add       r0, r0, r30
  stw       r0, 0x10C(r31)
  b         .loc_0xD4

.loc_0xC8:
  lwz       r3, 0x114(r31)
  addi      r0, r3, 0x1
  stw       r0, 0x114(r31)

.loc_0xD4:
  lwz       r4, 0x114(r31)
  lwz       r5, 0x108(r31)
  cmpw      r4, r5
  bge-      .loc_0x130
  lwz       r3, 0x4(r31)
  lbzx      r3, r3, r4
  cmplwi    r3, 0
  beq-      .loc_0x11C
  cmplwi    r3, 0xD
  beq-      .loc_0x11C
  subi      r0, r3, 0x9
  rlwinm    r0,r0,0,24,31
  cmplwi    r0, 0x1
  ble-      .loc_0x11C
  cmplwi    r3, 0x20
  beq-      .loc_0x11C
  cmplwi    r3, 0x2C
  bne-      .loc_0x124

.loc_0x11C:
  li        r0, 0x1
  b         .loc_0x128

.loc_0x124:
  li        r0, 0

.loc_0x128:
  rlwinm.   r0,r0,0,24,31
  bne+      .loc_0xC8

.loc_0x130:
  cmpw      r4, r5
  bge-      .loc_0x158
  lwz       r3, 0x4(r31)
  lbzx      r0, r3, r4
  cmpwi     r0, -0x1
  bne-      .loc_0x150
  li        r3, 0x1
  b         .loc_0x15C

.loc_0x150:
  li        r3, 0
  b         .loc_0x15C

.loc_0x158:
  li        r3, 0x1

.loc_0x15C:
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
 * Size:	00003C
 */
void CmdStream::LineIsComment()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80040ECC
 * Size:	000050
 */
void CmdStream::copyToToken(int)
{
/*
.loc_0x0:
  cmpwi     r4, 0
  mtctr     r4
  li        r5, 0
  ble-      .loc_0x40

.loc_0x10:
  lwz       r0, 0x114(r3)
  lwz       r4, 0x4(r3)
  add       r0, r0, r5
  lbzx      r0, r4, r0
  cmplwi    r0, 0x9
  mr        r4, r0
  bne-      .loc_0x30
  li        r4, 0x20

.loc_0x30:
  addi      r0, r5, 0x8
  stbx      r4, r3, r0
  addi      r5, r5, 0x1
  bdnz+     .loc_0x10

.loc_0x40:
  add       r3, r3, r5
  li        r0, 0
  stb       r0, 0x8(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	80040F1C
 * Size:	000194
 */
void CmdStream::skipLine()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  stw       r30, 0x10(r1)
  lwz       r3, 0x110(r3)
  lwz       r0, 0x114(r31)
  sub       r0, r0, r3
  cmpwi     r0, 0x4000
  blt-      .loc_0xC4
  lwz       r0, 0x10C(r31)
  cmpwi     r0, 0
  beq-      .loc_0x68
  lwz       r0, 0x4(r31)
  li        r5, 0x4000
  add       r3, r0, r3
  addi      r4, r3, 0
  addi      r4, r4, 0x4000
  bl        -0x3DB54
  lwz       r3, 0x4(r31)
  subi      r0, r3, 0x4000
  stw       r0, 0x4(r31)
  lwz       r3, 0x110(r31)
  addi      r0, r3, 0x4000
  stw       r0, 0x110(r31)

.loc_0x68:
  lwz       r4, 0x10C(r31)
  cmpwi     r4, 0
  beq-      .loc_0x7C
  li        r30, 0x4000
  b         .loc_0x84

.loc_0x7C:
  lis       r3, 0x1
  subi      r30, r3, 0x8000

.loc_0x84:
  lwz       r0, 0x108(r31)
  sub       r0, r0, r4
  cmpw      r0, r30
  bge-      .loc_0x98
  mr        r30, r0

.loc_0x98:
  lwz       r3, 0x0(r31)
  mr        r5, r30
  lwz       r0, 0x4(r31)
  lwz       r12, 0x4(r3)
  add       r4, r0, r4
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x10C(r31)
  add       r0, r0, r30
  stw       r0, 0x10C(r31)

.loc_0xC4:
  lwz       r4, 0x114(r31)
  lwz       r0, 0x108(r31)
  mr        r5, r4
  b         .loc_0xD8

.loc_0xD4:
  addi      r5, r5, 0x1

.loc_0xD8:
  cmpw      r5, r0
  bge-      .loc_0xF8
  lwz       r3, 0x4(r31)
  lbzx      r3, r3, r5
  cmplwi    r3, 0xA
  beq-      .loc_0xF8
  cmplwi    r3, 0xD
  bne+      .loc_0xD4

.loc_0xF8:
  sub.      r0, r5, r4
  li        r4, 0
  mtctr     r0
  ble-      .loc_0x134

.loc_0x108:
  lwz       r0, 0x114(r31)
  lwz       r3, 0x4(r31)
  add       r0, r0, r4
  lbzx      r3, r3, r0
  cmplwi    r3, 0x9
  bne-      .loc_0x124
  li        r3, 0x20

.loc_0x124:
  addi      r0, r4, 0x8
  stbx      r3, r31, r0
  addi      r4, r4, 0x1
  bdnz+     .loc_0x108

.loc_0x134:
  add       r3, r31, r4
  li        r0, 0
  stb       r0, 0x8(r3)
  lwz       r0, 0x4(r31)
  add       r4, r0, r5
  addi      r3, r4, 0
  b         .loc_0x15C

.loc_0x150:
  addi      r4, r4, 0x1
  addi      r5, r5, 0x1
  addi      r3, r3, 0x1

.loc_0x15C:
  lbz       r0, 0x0(r4)
  cmplwi    r0, 0xA
  beq+      .loc_0x150
  lbz       r0, 0x0(r3)
  cmplwi    r0, 0xD
  beq+      .loc_0x150
  stw       r5, 0x114(r31)
  addi      r3, r31, 0x8
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
 * Address:	800410B0
 * Size:	000324
 */
void CmdStream::getToken(bool)
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
  stw       r28, 0x10(r1)
  lwz       r3, 0x110(r3)
  lwz       r0, 0x114(r29)
  sub       r0, r0, r3
  cmpwi     r0, 0x4000
  blt-      .loc_0xD0
  lwz       r0, 0x10C(r29)
  cmpwi     r0, 0
  beq-      .loc_0x74
  lwz       r0, 0x4(r29)
  li        r5, 0x4000
  add       r3, r0, r3
  addi      r4, r3, 0
  addi      r4, r4, 0x4000
  bl        -0x3DCF4
  lwz       r3, 0x4(r29)
  subi      r0, r3, 0x4000
  stw       r0, 0x4(r29)
  lwz       r3, 0x110(r29)
  addi      r0, r3, 0x4000
  stw       r0, 0x110(r29)

.loc_0x74:
  lwz       r4, 0x10C(r29)
  cmpwi     r4, 0
  beq-      .loc_0x88
  li        r28, 0x4000
  b         .loc_0x90

.loc_0x88:
  lis       r3, 0x1
  subi      r28, r3, 0x8000

.loc_0x90:
  lwz       r0, 0x108(r29)
  sub       r0, r0, r4
  cmpw      r0, r28
  bge-      .loc_0xA4
  mr        r28, r0

.loc_0xA4:
  lwz       r3, 0x0(r29)
  mr        r5, r28
  lwz       r0, 0x4(r29)
  lwz       r12, 0x4(r3)
  add       r4, r0, r4
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x10C(r29)
  add       r0, r0, r28
  stw       r0, 0x10C(r29)

.loc_0xD0:
  rlwinm.   r0,r30,0,24,31
  beq-      .loc_0x1A0
  b         .loc_0x160

.loc_0xDC:
  addi      r3, r29, 0
  li        r4, 0
  bl        -0x568
  lwz       r4, 0x114(r29)
  lwz       r0, 0x108(r29)
  mr        r28, r4
  b         .loc_0xFC

.loc_0xF8:
  addi      r28, r28, 0x1

.loc_0xFC:
  cmpw      r28, r0
  bge-      .loc_0x11C
  lwz       r3, 0x4(r29)
  lbzx      r3, r3, r28
  cmplwi    r3, 0xA
  beq-      .loc_0x11C
  cmplwi    r3, 0xD
  bne+      .loc_0xF8

.loc_0x11C:
  addi      r3, r29, 0
  sub       r4, r28, r4
  bl        -0x308
  lwz       r0, 0x4(r29)
  add       r4, r0, r28
  addi      r3, r4, 0
  b         .loc_0x144

.loc_0x138:
  addi      r4, r4, 0x1
  addi      r28, r28, 0x1
  addi      r3, r3, 0x1

.loc_0x144:
  lbz       r0, 0x0(r4)
  cmplwi    r0, 0xA
  beq+      .loc_0x138
  lbz       r0, 0x0(r3)
  cmplwi    r0, 0xD
  beq+      .loc_0x138
  stw       r28, 0x114(r29)

.loc_0x160:
  lwz       r3, 0x4(r29)
  lwz       r0, 0x114(r29)
  add       r3, r3, r0
  lbz       r0, 0x0(r3)
  cmplwi    r0, 0x23
  beq-      .loc_0x18C
  cmplwi    r0, 0x2F
  bne-      .loc_0x194
  lbz       r0, 0x1(r3)
  cmplwi    r0, 0x2F
  bne-      .loc_0x194

.loc_0x18C:
  li        r0, 0x1
  b         .loc_0x198

.loc_0x194:
  li        r0, 0

.loc_0x198:
  rlwinm.   r0,r0,0,24,31
  bne+      .loc_0xDC

.loc_0x1A0:
  lwz       r0, 0x114(r29)
  li        r30, 0
  lwz       r3, 0x4(r29)
  mr        r31, r0
  lbzx      r0, r3, r0
  cmplwi    r0, 0x22
  beq-      .loc_0x1C4
  cmplwi    r0, 0x27
  bne-      .loc_0x1D8

.loc_0x1C4:
  lwz       r3, 0x114(r29)
  li        r30, 0x1
  addi      r31, r31, 0x1
  addi      r0, r3, 0x1
  stw       r0, 0x114(r29)

.loc_0x1D8:
  rlwinm    r28,r30,0,24,31
  b         .loc_0x1E4

.loc_0x1E0:
  addi      r31, r31, 0x1

.loc_0x1E4:
  cmplwi    r28, 0
  beq-      .loc_0x210
  lwz       r3, 0x4(r29)
  li        r0, 0
  lbzx      r3, r3, r31
  cmplwi    r3, 0x22
  beq-      .loc_0x22C
  cmplwi    r3, 0x27
  beq-      .loc_0x22C
  li        r0, 0x1
  b         .loc_0x22C

.loc_0x210:
  lwz       r4, 0x4(r29)
  mr        r3, r29
  lbzx      r4, r4, r31
  bl        -0x5B4
  rlwinm    r0,r3,0,24,31
  cntlzw    r0, r0
  rlwinm    r0,r0,27,5,31

.loc_0x22C:
  rlwinm.   r0,r0,0,24,31
  bne+      .loc_0x1E0
  lwz       r0, 0x114(r29)
  li        r4, 0
  sub.      r0, r31, r0
  mtctr     r0
  ble-      .loc_0x274

.loc_0x248:
  lwz       r0, 0x114(r29)
  lwz       r3, 0x4(r29)
  add       r0, r0, r4
  lbzx      r3, r3, r0
  cmplwi    r3, 0x9
  bne-      .loc_0x264
  li        r3, 0x20

.loc_0x264:
  addi      r0, r4, 0x8
  stbx      r3, r29, r0
  addi      r4, r4, 0x1
  bdnz+     .loc_0x248

.loc_0x274:
  add       r3, r29, r4
  li        r4, 0
  rlwinm.   r0,r30,0,24,31
  stb       r4, 0x8(r3)
  beq-      .loc_0x29C
  lwz       r0, 0x114(r29)
  sub       r0, r31, r0
  add       r3, r29, r0
  stb       r4, 0x8(r3)
  addi      r31, r31, 0x1

.loc_0x29C:
  lwz       r4, 0x108(r29)
  b         .loc_0x2A8

.loc_0x2A4:
  addi      r31, r31, 0x1

.loc_0x2A8:
  cmpw      r31, r4
  bge-      .loc_0x2FC
  lwz       r3, 0x4(r29)
  lbzx      r3, r3, r31
  cmplwi    r3, 0
  beq-      .loc_0x2E8
  cmplwi    r3, 0xD
  beq-      .loc_0x2E8
  subi      r0, r3, 0x9
  rlwinm    r0,r0,0,24,31
  cmplwi    r0, 0x1
  ble-      .loc_0x2E8
  cmplwi    r3, 0x20
  beq-      .loc_0x2E8
  cmplwi    r3, 0x2C
  bne-      .loc_0x2F0

.loc_0x2E8:
  li        r0, 0x1
  b         .loc_0x2F4

.loc_0x2F0:
  li        r0, 0

.loc_0x2F4:
  rlwinm.   r0,r0,0,24,31
  bne+      .loc_0x2A4

.loc_0x2FC:
  stw       r31, 0x114(r29)
  addi      r3, r29, 0x8
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
 * Address:	........
 * Size:	000010
 */
void CmdStream::nextChar()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800413D4
 * Size:	0000B4
 */
void CmdStream::isToken(char *)
{
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
  addi      r3, r29, 0x8
  bl        0x1D8014
  cmplwi    r3, 0
  beq-      .loc_0x4C
  mr        r3, r30
  bl        0x1D8004
  addi      r31, r3, 0
  addi      r3, r29, 0x8
  bl        0x1D7FF8
  cmplw     r3, r31
  beq-      .loc_0x54

.loc_0x4C:
  li        r3, 0
  b         .loc_0x98

.loc_0x54:
  addi      r31, r30, 0
  li        r30, 0
  b         .loc_0x84

.loc_0x60:
  addi      r3, r30, 0x8
  lbz       r0, 0x0(r31)
  lbzx      r3, r29, r3
  cmplw     r3, r0
  beq-      .loc_0x7C
  li        r3, 0
  b         .loc_0x98

.loc_0x7C:
  addi      r30, r30, 0x1
  addi      r31, r31, 0x1

.loc_0x84:
  addi      r3, r29, 0x8
  bl        0x1D7FB0
  cmpw      r30, r3
  blt+      .loc_0x60
  li        r3, 0x1

.loc_0x98:
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
 * Address:	80041488
 * Size:	0000FC
 */
void CmdStream::endOfSection()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  stw       r30, 0x10(r1)
  lwz       r3, 0x110(r3)
  lwz       r0, 0x114(r31)
  sub       r0, r0, r3
  cmpwi     r0, 0x4000
  blt-      .loc_0xC4
  lwz       r0, 0x10C(r31)
  cmpwi     r0, 0
  beq-      .loc_0x68
  lwz       r0, 0x4(r31)
  li        r5, 0x4000
  add       r3, r0, r3
  addi      r4, r3, 0
  addi      r4, r4, 0x4000
  bl        -0x3E0C0
  lwz       r3, 0x4(r31)
  subi      r0, r3, 0x4000
  stw       r0, 0x4(r31)
  lwz       r3, 0x110(r31)
  addi      r0, r3, 0x4000
  stw       r0, 0x110(r31)

.loc_0x68:
  lwz       r4, 0x10C(r31)
  cmpwi     r4, 0
  beq-      .loc_0x7C
  li        r30, 0x4000
  b         .loc_0x84

.loc_0x7C:
  lis       r3, 0x1
  subi      r30, r3, 0x8000

.loc_0x84:
  lwz       r0, 0x108(r31)
  sub       r0, r0, r4
  cmpw      r0, r30
  bge-      .loc_0x98
  mr        r30, r0

.loc_0x98:
  lwz       r3, 0x0(r31)
  mr        r5, r30
  lwz       r0, 0x4(r31)
  lwz       r12, 0x4(r3)
  add       r4, r0, r4
  lwz       r12, 0x3C(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x10C(r31)
  add       r0, r0, r30
  stw       r0, 0x10C(r31)

.loc_0xC4:
  lwz       r3, 0x4(r31)
  lwz       r0, 0x114(r31)
  lbzx      r0, r3, r0
  cmplwi    r0, 0x7D
  bne-      .loc_0xE0
  li        r3, 0x1
  b         .loc_0xE4

.loc_0xE0:
  li        r3, 0

.loc_0xE4:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}
