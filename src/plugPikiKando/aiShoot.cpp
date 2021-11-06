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
 * Address:	800C216C
 * Size:	000120
 */
ActShoot::ActShoot(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r4
  stw       r30, 0x18(r1)
  stw       r29, 0x14(r1)
  stw       r28, 0x10(r1)
  stw       r3, 0x8(r1)
  lwz       r30, 0x8(r1)
  addi      r3, r30, 0
  bl        0x1C34
  lis       r3, 0x802C
  subi      r0, r3, 0x7ED0
  stw       r0, 0x0(r30)
  li        r4, 0
  lis       r3, 0x802B
  stw       r4, 0x14(r30)
  addi      r0, r3, 0x7B84
  li        r3, 0x24
  stw       r0, 0x0(r30)
  stw       r4, 0x20(r30)
  bl        -0x7B1C4
  mr.       r30, r3
  beq-      .loc_0x74
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        -0x7274

.loc_0x74:
  li        r3, 0x10
  bl        -0x7B1E0
  mr.       r29, r3
  beq-      .loc_0xB4
  lis       r4, 0x802B
  addi      r0, r4, 0x70A0
  lis       r4, 0x802B
  stw       r0, 0x0(r3)
  addi      r0, r4, 0x6C50
  stw       r0, 0x0(r3)
  li        r0, 0
  stw       r0, 0x4(r3)
  lfs       f0, -0x6B08(r2)
  stfs      f0, 0x8(r3)
  lfs       f0, -0x6B04(r2)
  stfs      f0, 0xC(r3)

.loc_0xB4:
  li        r3, 0x24
  bl        -0x7B220
  mr.       r28, r3
  beq-      .loc_0xD0
  addi      r3, r28, 0
  addi      r4, r31, 0
  bl        0x574

.loc_0xD0:
  lwz       r3, 0x8(r1)
  addi      r5, r30, 0
  addi      r6, r29, 0
  crclr     6, 0x6
  addi      r7, r28, 0
  li        r4, 0x2
  li        r8, 0
  bl        0x2118
  lwz       r3, 0x8(r1)
  li        r0, 0
  stw       r0, 0x20(r3)
  stb       r0, 0x18(r3)
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
 * Address:	800C228C
 * Size:	0000B0
 */
void ActShoot::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  stw       r30, 0x18(r1)
  addi      r30, r3, 0
  lwz       r0, 0x6C(r4)
  cmpwi     r0, 0x36
  bne-      .loc_0x40
  stw       r4, 0x24(r30)
  mr        r3, r30
  bl        .loc_0xB0
  li        r0, 0x1
  stb       r0, 0x18(r30)
  mr        r31, r3
  b         .loc_0x54

.loc_0x40:
  li        r0, 0
  stw       r0, 0x24(r30)
  mr        r31, r4
  stw       r0, 0x1C(r30)
  stb       r0, 0x18(r30)

.loc_0x54:
  cmplwi    r31, 0
  beq-      .loc_0x98
  lwz       r3, 0x20(r30)
  cmplwi    r3, 0
  beq-      .loc_0x78
  beq-      .loc_0x78
  bl        0x22074
  li        r0, 0
  stw       r0, 0x20(r30)

.loc_0x78:
  stw       r31, 0x20(r30)
  lwz       r3, 0x20(r30)
  cmplwi    r3, 0
  beq-      .loc_0x8C
  bl        0x22048

.loc_0x8C:
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        0x1BF4

.loc_0x98:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr       

.loc_0xB0:
*/
}

/*
 * --INFO--
 * Address:	800C233C
 * Size:	000178
 */
void ActShoot::findTarget()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x50(r1)
  stfd      f31, 0x48(r1)
  stfd      f30, 0x40(r1)
  stmw      r27, 0x2C(r1)
  mr        r27, r3
  li        r28, 0
  lwz       r30, 0x3160(r13)
  lfs       f31, -0x6B00(r2)
  lwz       r12, 0x0(r30)
  addi      r3, r30, 0
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r29, r3
  b         .loc_0xFC

.loc_0x44:
  cmpwi     r29, -0x1
  bne-      .loc_0x6C
  mr        r3, r30
  lwz       r12, 0x0(r30)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3
  b         .loc_0x88

.loc_0x6C:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r31, r3

.loc_0x88:
  lwz       r4, 0xC(r27)
  mr        r3, r31
  bl        -0x35550
  lwz       r12, 0x0(r31)
  fmr       f30, f1
  mr        r3, r31
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE0
  mr        r3, r31
  lwz       r12, 0x0(r31)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE0
  fcmpo     cr0, f30, f31
  bge-      .loc_0xE0
  fmr       f31, f30
  mr        r28, r31

.loc_0xE0:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r29, r3

.loc_0xFC:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x124
  li        r0, 0x1
  b         .loc_0x150

.loc_0x124:
  mr        r3, r30
  lwz       r12, 0x0(r30)
  mr        r4, r29
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x14C
  li        r0, 0x1
  b         .loc_0x150

.loc_0x14C:
  li        r0, 0

.loc_0x150:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x44
  mr        r3, r28
  lmw       r27, 0x2C(r1)
  lwz       r0, 0x54(r1)
  lfd       f31, 0x48(r1)
  lfd       f30, 0x40(r1)
  addi      r1, r1, 0x50
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000288
 */
void ActShoot::decideTarget()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800C24B4
 * Size:	0001CC
 */
void ActShoot::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stfd      f31, 0x40(r1)
  stfd      f30, 0x38(r1)
  stw       r31, 0x34(r1)
  stw       r30, 0x30(r1)
  stw       r29, 0x2C(r1)
  mr        r29, r3
  lwz       r0, 0x20(r3)
  cmplwi    r0, 0
  bne-      .loc_0x38
  li        r3, 0x2
  b         .loc_0x1A8

.loc_0x38:
  mr        r3, r29
  bl        0x1B04
  cmpwi     r3, 0
  beq-      .loc_0x1A8
  lbz       r0, 0x18(r29)
  cmplwi    r0, 0
  beq-      .loc_0x1A4
  lfs       f30, -0x6B00(r2)
  li        r31, 0
  lwz       r0, 0x3160(r13)
  addi      r3, r1, 0x10
  stw       r0, 0x14(r1)
  stw       r31, 0x18(r1)
  bl        -0x32764
  b         .loc_0x118

.loc_0x74:
  lwz       r4, 0x10(r1)
  cmpwi     r4, -0x1
  bne-      .loc_0xA0
  lwz       r3, 0x14(r1)
  li        r4, 0
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xB8

.loc_0xA0:
  lwz       r3, 0x14(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xB8:
  lwz       r4, 0xC(r29)
  mr        r3, r30
  bl        -0x356F8
  lwz       r12, 0x0(r30)
  fmr       f31, f1
  mr        r3, r30
  lwz       r12, 0x88(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x110
  mr        r3, r30
  lwz       r12, 0x0(r30)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x110
  fcmpo     cr0, f31, f30
  bge-      .loc_0x110
  fmr       f30, f31
  mr        r31, r30

.loc_0x110:
  addi      r3, r1, 0x10
  bl        -0x32930

.loc_0x118:
  lwz       r3, 0x14(r1)
  lwz       r4, 0x10(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x140
  li        r0, 0x1
  b         .loc_0x16C

.loc_0x140:
  lwz       r3, 0x14(r1)
  lwz       r4, 0x10(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x168
  li        r0, 0x1
  b         .loc_0x16C

.loc_0x168:
  li        r0, 0

.loc_0x16C:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x74
  cmplwi    r31, 0
  beq-      .loc_0x19C
  mr        r3, r29
  lwz       r4, 0x24(r29)
  lwz       r12, 0x0(r29)
  lwz       r12, 0x48(r12)
  mtlr      r12
  blrl      
  li        r3, 0
  b         .loc_0x1A8

.loc_0x19C:
  li        r3, 0x2
  b         .loc_0x1A8

.loc_0x1A4:
  li        r3, 0x2

.loc_0x1A8:
  lwz       r0, 0x4C(r1)
  lfd       f31, 0x40(r1)
  lfd       f30, 0x38(r1)
  lwz       r31, 0x34(r1)
  lwz       r30, 0x30(r1)
  lwz       r29, 0x2C(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C2680
 * Size:	000040
 */
void ActShoot::cleanup()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x20(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2C
  bl        0x21CCC
  li        r0, 0
  stw       r0, 0x20(r31)

.loc_0x2C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C26C0
 * Size:	000040
 */
void ActShootCreature::cleanup()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lwz       r3, 0x20(r3)
  cmplwi    r3, 0
  beq-      .loc_0x2C
  bl        0x21C8C
  li        r0, 0
  stw       r0, 0x20(r31)

.loc_0x2C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C2700
 * Size:	0000AC
 */
void ActShootCreature::animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r3, 0
  lwz       r0, 0x0(r4)
  cmpwi     r0, 0x1
  beq-      .loc_0x40
  bge-      .loc_0x34
  cmpwi     r0, 0
  bge-      .loc_0x58
  b         .loc_0x94

.loc_0x34:
  cmpwi     r0, 0x3
  bge-      .loc_0x94
  b         .loc_0x4C

.loc_0x40:
  li        r0, 0x2
  stw       r0, 0x18(r30)
  b         .loc_0x94

.loc_0x4C:
  li        r0, 0x1
  stw       r0, 0x18(r30)
  b         .loc_0x94

.loc_0x58:
  li        r0, 0x4
  stw       r0, 0x18(r30)
  addi      r3, r1, 0x10
  li        r4, 0x2
  lfs       f0, -0x6AF4(r2)
  stfs      f0, 0x1C(r30)
  bl        0x5C7E8
  addi      r31, r3, 0
  addi      r3, r1, 0x18
  li        r4, 0x2
  bl        0x5C7D8
  mr        r4, r3
  lwz       r3, 0xC(r30)
  mr        r5, r31
  bl        0x8248

.loc_0x94:
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
 * Address:	800C27AC
 * Size:	00005C
 */
ActShootCreature::ActShootCreature(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        0x160C
  lis       r3, 0x802B
  subi      r0, r3, 0x246C
  lis       r3, 0x802B
  stw       r0, 0x14(r31)
  addi      r3, r3, 0x7ABC
  stw       r3, 0x0(r31)
  addi      r3, r3, 0x64
  li        r0, 0
  stw       r3, 0x14(r31)
  mr        r3, r31
  stw       r0, 0x20(r31)
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C2808
 * Size:	000088
 */
void ActShootCreature::init(Creature *)
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
  lwz       r3, 0x20(r3)
  cmplwi    r3, 0
  beq-      .loc_0x38
  beq-      .loc_0x38
  bl        0x21B38
  li        r0, 0
  stw       r0, 0x20(r30)

.loc_0x38:
  stw       r31, 0x20(r30)
  lwz       r3, 0x20(r30)
  cmplwi    r3, 0
  beq-      .loc_0x4C
  bl        0x21B0C

.loc_0x4C:
  li        r0, 0
  stw       r0, 0x18(r30)
  lwz       r3, 0xC(r30)
  lfs       f0, -0x44D0(r13)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x44CC(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x44C8(r13)
  stfs      f0, 0x8(r3)
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
 * Address:	800C2890
 * Size:	0002DC
 */
void ActShootCreature::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xB0(r1)
  stw       r31, 0xAC(r1)
  mr        r31, r3
  stw       r30, 0xA8(r1)
  stw       r29, 0xA4(r1)
  lwz       r0, 0x18(r3)
  cmpwi     r0, 0
  bne-      .loc_0x70
  li        r0, 0x1
  cmplwi    r31, 0
  stw       r0, 0x18(r31)
  mr        r29, r31
  beq-      .loc_0x40
  addi      r29, r29, 0x14

.loc_0x40:
  addi      r3, r1, 0x74
  li        r4, 0x17
  bl        0x5C680
  addi      r30, r3, 0
  addi      r5, r29, 0
  addi      r3, r1, 0x7C
  li        r4, 0x17
  bl        0x5C6A0
  mr        r4, r3
  lwz       r3, 0xC(r31)
  mr        r5, r30
  bl        0x80DC

.loc_0x70:
  lwz       r0, 0x18(r31)
  cmpwi     r0, 0x4
  bne-      .loc_0xA8
  lwz       r3, 0x2DEC(r13)
  lfs       f1, 0x1C(r31)
  lfs       f0, 0x28C(r3)
  fsubs     f0, f1, f0
  stfs      f0, 0x1C(r31)
  lfs       f1, 0x1C(r31)
  lfs       f0, -0x6AFC(r2)
  fcmpo     cr0, f1, f0
  bge-      .loc_0xA8
  li        r0, 0x5
  stw       r0, 0x18(r31)

.loc_0xA8:
  lwz       r3, 0x20(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x74(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0xCC
  li        r3, 0x2
  b         .loc_0x2C0

.loc_0xCC:
  lwz       r0, 0x18(r31)
  cmpwi     r0, 0x4
  bne-      .loc_0x23C
  lwz       r4, 0xC(r31)
  lwz       r3, 0x20(r31)
  lfsu      f1, 0x94(r3)
  lfsu      f0, 0x94(r4)
  lfs       f3, 0x4(r3)
  lfs       f2, 0x4(r4)
  fsubs     f0, f1, f0
  lfs       f4, 0x8(r3)
  lfs       f1, 0x8(r4)
  fsubs     f2, f3, f2
  stfs      f0, 0x94(r1)
  fsubs     f0, f4, f1
  stfs      f2, 0x98(r1)
  stfs      f0, 0x9C(r1)
  lfs       f1, 0x94(r1)
  lfs       f3, 0x9C(r1)
  lfs       f0, 0x98(r1)
  fmuls     f2, f1, f1
  fmuls     f3, f3, f3
  fmuls     f1, f0, f0
  lfs       f0, -0x6AFC(r2)
  fadds     f1, f2, f1
  fadds     f6, f3, f1
  fcmpo     cr0, f6, f0
  ble-      .loc_0x194
  fsqrte    f1, f6
  lfd       f3, -0x6AF0(r2)
  lfd       f2, -0x6AE8(r2)
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f6, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f6, f0
  fsub      f0, f2, f0
  fmul      f1, f1, f0
  fmul      f0, f1, f1
  fmul      f1, f3, f1
  fmul      f0, f6, f0
  fsub      f0, f2, f0
  fmul      f0, f1, f0
  fmul      f0, f6, f0
  frsp      f0, f0
  stfs      f0, 0x4C(r1)
  lfs       f6, 0x4C(r1)

.loc_0x194:
  lfs       f1, -0x6AF8(r2)
  lfs       f0, 0x94(r1)
  fdivs     f4, f1, f6
  lfs       f2, 0x98(r1)
  lfs       f3, 0x9C(r1)
  fmuls     f0, f0, f4
  fmuls     f5, f2, f4
  fmuls     f2, f3, f4
  stfs      f0, 0x94(r1)
  stfs      f5, 0x98(r1)
  stfs      f2, 0x9C(r1)
  lfs       f0, -0x6B04(r2)
  fcmpo     cr0, f6, f0
  bge-      .loc_0x204
  lfs       f5, -0x44C4(r13)
  addi      r4, r1, 0x94
  lfs       f0, 0x94(r1)
  lfs       f2, 0x98(r1)
  fmuls     f0, f0, f5
  lfs       f3, 0x9C(r1)
  fmuls     f4, f2, f5
  fmuls     f2, f3, f5
  stfs      f0, 0x94(r1)
  stfs      f4, 0x98(r1)
  stfs      f2, 0x9C(r1)
  lwz       r3, 0xC(r31)
  bl        0x934C
  b         .loc_0x23C

.loc_0x204:
  lfs       f0, -0x6B08(r2)
  fcmpo     cr0, f6, f0
  ble-      .loc_0x220
  lwz       r3, 0xC(r31)
  addi      r4, r1, 0x94
  bl        0x9330
  b         .loc_0x23C

.loc_0x220:
  lwz       r3, 0xC(r31)
  lfs       f0, -0x44C0(r13)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x44BC(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x44B8(r13)
  stfs      f0, 0x8(r3)

.loc_0x23C:
  lwz       r4, 0xC(r31)
  lwz       r3, 0x20(r31)
  lfsu      f1, 0x94(r4)
  lfsu      f3, 0x94(r3)
  lfs       f0, 0x8(r4)
  lfs       f2, 0x8(r3)
  fsubs     f1, f3, f1
  fsubs     f2, f2, f0
  bl        0x158F0C
  lwz       r3, 0xC(r31)
  lfs       f2, 0xA0(r3)
  bl        -0x8A544
  lfs       f0, -0x6AE0(r2)
  lwz       r3, 0xC(r31)
  fmuls     f1, f0, f1
  lfs       f0, 0xA0(r3)
  fadds     f0, f0, f1
  stfs      f0, 0xA0(r3)
  lwz       r3, 0xC(r31)
  lfs       f1, 0xA0(r3)
  bl        -0x8A594
  lwz       r3, 0xC(r31)
  stfs      f1, 0xA0(r3)
  lwz       r0, 0x18(r31)
  cmpwi     r0, 0x5
  bne-      .loc_0x2AC
  li        r3, 0x2
  b         .loc_0x2C0

.loc_0x2AC:
  cmpwi     r0, 0x2
  bne-      .loc_0x2BC
  li        r0, 0x3
  stw       r0, 0x18(r31)

.loc_0x2BC:
  li        r3, 0

.loc_0x2C0:
  lwz       r0, 0xB4(r1)
  lwz       r31, 0xAC(r1)
  lwz       r30, 0xA8(r1)
  lwz       r29, 0xA4(r1)
  addi      r1, r1, 0xB0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800C2B6C
 * Size:	00006C
 */
ActShootCreature::~ActShootCreature()
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
  beq-      .loc_0x50
  lis       r3, 0x802B
  addi      r3, r3, 0x7ABC
  stw       r3, 0x0(r30)
  addi      r0, r3, 0x64
  addi      r3, r30, 0
  stw       r0, 0x14(r30)
  li        r4, 0
  bl        0x1260
  extsh.    r0, r31
  ble-      .loc_0x50
  mr        r3, r30
  bl        -0x7BA0C

.loc_0x50:
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
 * Address:	800C2BD8
 * Size:	000074
 */
ActShoot::~ActShoot()
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
  beq-      .loc_0x58
  lis       r3, 0x802B
  addi      r0, r3, 0x7B84
  stw       r0, 0x0(r30)
  beq-      .loc_0x48
  lis       r3, 0x802C
  subi      r0, r3, 0x7ED0
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  li        r4, 0
  bl        0x11EC

.loc_0x48:
  extsh.    r0, r31
  ble-      .loc_0x58
  mr        r3, r30
  bl        -0x7BA80

.loc_0x58:
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
 * Address:	800C2C4C
 * Size:	000008
 */
void ActShootCreature::@20@animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x14
  b         -0x550
*/
}
