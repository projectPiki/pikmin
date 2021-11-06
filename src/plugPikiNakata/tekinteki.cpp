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
 * Size:	00000C
 */
TekiMessage::TekiMessage(int, NTeki *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8014B9F8
 * Size:	000114
 */
NTeki::NTeki()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  extsh.    r0, r4
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  stw       r30, 0x10(r1)
  beq-      .loc_0x34
  addi      r0, r31, 0x46C
  lis       r3, 0x802B
  stw       r0, 0x2C0(r31)
  subi      r0, r3, 0x246C
  stw       r0, 0x46C(r31)

.loc_0x34:
  addi      r3, r31, 0
  li        r4, 0
  bl        -0x749C
  lis       r3, 0x802D
  subi      r3, r3, 0x2208
  stw       r3, 0x0(r31)
  addi      r6, r3, 0x1F4
  addi      r4, r3, 0x114
  lwz       r5, 0x2C0(r31)
  addi      r0, r31, 0x46C
  li        r3, 0x40
  stw       r6, 0x0(r5)
  stw       r4, 0x2B8(r31)
  lwz       r4, 0x2C0(r31)
  sub       r0, r0, r4
  stw       r0, 0x4(r4)
  bl        -0x104A68
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0x88
  bl        -0x259A8

.loc_0x88:
  stw       r30, 0x45C(r31)
  li        r3, 0x1C
  bl        -0x104A84
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xA4
  bl        -0x25B94

.loc_0xA4:
  stw       r30, 0x460(r31)
  li        r3, 0x38
  bl        -0x104AA0
  addi      r30, r3, 0
  mr.       r3, r30
  beq-      .loc_0xC0
  bl        -0x25724

.loc_0xC0:
  stw       r30, 0x464(r31)
  li        r3, 0x34
  bl        -0x104ABC
  mr.       r30, r3
  beq-      .loc_0xF4
  addi      r3, r30, 0
  li        r4, 0
  bl        -0x26584
  lis       r3, 0x802C
  addi      r0, r3, 0x63AC
  stw       r0, 0x0(r30)
  addi      r3, r30, 0x14
  bl        -0x2EC94

.loc_0xF4:
  stw       r30, 0x468(r31)
  mr        r3, r31
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
 * Address:	8014BB0C
 * Size:	0001D4
 */
void NTeki::sendMessage(int)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xC8(r1)
  stfd      f31, 0xC0(r1)
  stmw      r22, 0x98(r1)
  addi      r23, r3, 0
  addi      r24, r4, 0
  lwz       r26, 0x3160(r13)
  lwz       r12, 0x0(r26)
  addi      r3, r26, 0
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f31, -0x5860(r2)
  addi      r25, r3, 0
  addi      r27, r1, 0x7C
  addi      r31, r23, 0x94
  addi      r30, r1, 0x50
  addi      r29, r1, 0x4C
  addi      r28, r1, 0x48
  b         .loc_0x160

.loc_0x54:
  cmpwi     r25, -0x1
  bne-      .loc_0x78
  mr        r3, r26
  lwz       r12, 0x0(r26)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x90

.loc_0x78:
  mr        r3, r26
  lwz       r12, 0x0(r26)
  mr        r4, r25
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x90:
  cmplw     r3, r23
  addi      r22, r3, 0
  beq-      .loc_0x144
  stfs      f31, 0x6C(r1)
  mr        r4, r28
  addi      r5, r29, 0
  stfs      f31, 0x68(r1)
  addi      r6, r30, 0
  addi      r3, r1, 0x64
  stfs      f31, 0x64(r1)
  lfs       f1, 0x9C(r22)
  lfs       f0, 0x8(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0x50(r1)
  lfs       f1, 0x98(r22)
  lfs       f0, 0x4(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0x4C(r1)
  lfs       f1, 0x94(r22)
  lfs       f0, 0x0(r31)
  fsubs     f0, f1, f0
  stfs      f0, 0x48(r1)
  bl        -0xEE568
  lfs       f1, 0x64(r1)
  lfs       f0, 0x68(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x6C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x13DFD8
  lwz       r3, 0x2C4(r23)
  lwz       r3, 0x84(r3)
  lwz       r3, 0x4(r3)
  lwz       r3, 0x0(r3)
  lfs       f0, 0x68(r3)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  bne-      .loc_0x144
  stw       r24, 0x7C(r1)
  addi      r3, r22, 0
  addi      r4, r27, 0
  stw       r23, 0x80(r1)
  bl        .loc_0x1D4

.loc_0x144:
  mr        r3, r26
  lwz       r12, 0x0(r26)
  mr        r4, r25
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r25, r3

.loc_0x160:
  mr        r3, r26
  lwz       r12, 0x0(r26)
  mr        r4, r25
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x188
  li        r0, 0x1
  b         .loc_0x1B4

.loc_0x188:
  mr        r3, r26
  lwz       r12, 0x0(r26)
  mr        r4, r25
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x1B0
  li        r0, 0x1
  b         .loc_0x1B4

.loc_0x1B0:
  li        r0, 0

.loc_0x1B4:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x54
  lmw       r22, 0x98(r1)
  lwz       r0, 0xCC(r1)
  lfd       f31, 0xC0(r1)
  addi      r1, r1, 0xC8
  mtlr      r0
  blr       

.loc_0x1D4:
*/
}

/*
 * --INFO--
 * Address:	8014BCE0
 * Size:	000054
 */
void NTeki::receiveMessage(TekiMessage &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  addi      r5, r31, 0
  lwz       r6, 0x4(r4)
  addi      r3, r1, 0x10
  li        r4, 0x4
  bl        -0x1938
  lwz       r12, 0x0(r31)
  addi      r4, r3, 0
  addi      r3, r31, 0
  lwz       r12, 0x1A0(r12)
  mtlr      r12
  blrl      
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8014BD34
 * Size:	000014
 */
void BTeki::@1132@4@animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  li        r11, 0x4
  lwzx      r11, r3, r11
  add       r3, r3, r11
  subi      r3, r3, 0x46C
  b         -0x6B64
*/
}
