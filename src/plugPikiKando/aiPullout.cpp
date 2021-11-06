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
 * Address:	800BD670
 * Size:	000100
 */
ActPullout::ActPullout(Piki *)
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
  bl        0x6730
  lis       r3, 0x802C
  subi      r0, r3, 0x7ED0
  stw       r0, 0x0(r30)
  li        r4, 0
  lis       r3, 0x802B
  stw       r4, 0x14(r30)
  addi      r0, r3, 0x72DC
  li        r3, 0x24
  stw       r0, 0x0(r30)
  stw       r4, 0x18(r30)
  bl        -0x766C8
  mr.       r30, r3
  beq-      .loc_0x74
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        -0x2778

.loc_0x74:
  li        r3, 0x40
  bl        -0x766E4
  mr.       r29, r3
  beq-      .loc_0x90
  addi      r3, r29, 0
  addi      r4, r31, 0
  bl        -0x15914

.loc_0x90:
  li        r3, 0x28
  bl        -0x76700
  mr.       r28, r3
  beq-      .loc_0xAC
  addi      r3, r28, 0
  addi      r4, r31, 0
  bl        0x4C0

.loc_0xAC:
  lwz       r3, 0x8(r1)
  addi      r5, r30, 0
  addi      r7, r29, 0
  crclr     6, 0x6
  addi      r9, r28, 0
  li        r4, 0x3
  li        r6, 0
  li        r8, 0
  li        r10, 0
  bl        0x6C30
  lwz       r3, 0x8(r1)
  li        r0, 0
  stw       r0, 0x18(r3)
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
 * Address:	800BD770
 * Size:	000250
 */
void ActPullout::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x210(r1)
  stfd      f31, 0x208(r1)
  stfd      f30, 0x200(r1)
  stmw      r25, 0x1E4(r1)
  mr.       r30, r4
  addi      r29, r3, 0
  bne-      .loc_0x1D4
  lwz       r27, 0x3068(r13)
  li        r31, 0
  addi      r3, r27, 0
  lwz       r12, 0x0(r27)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  lfs       f31, -0x6C48(r2)
  addi      r26, r3, 0
  addi      r28, r1, 0x20
  b         .loc_0xFC

.loc_0x50:
  cmpwi     r26, -0x1
  bne-      .loc_0x74
  mr        r3, r27
  lwz       r12, 0x0(r27)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x8C

.loc_0x74:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r26
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x8C:
  mr        r25, r3
  lwz       r4, 0xC(r29)
  bl        -0x30988
  lwz       r0, 0xC(r29)
  fmr       f30, f1
  cmplw     r25, r0
  beq-      .loc_0xE0
  mr        r3, r25
  lwz       r12, 0x0(r25)
  lwz       r12, 0x80(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xE0
  fcmpo     cr0, f30, f31
  bge-      .loc_0xE0
  cmpwi     r31, 0x64
  bge-      .loc_0xE0
  rlwinm    r0,r31,2,0,29
  stwx      r25, r28, r0
  addi      r31, r31, 0x1

.loc_0xE0:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r26
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r26, r3

.loc_0xFC:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r26
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0x124
  li        r0, 0x1
  b         .loc_0x150

.loc_0x124:
  mr        r3, r27
  lwz       r12, 0x0(r27)
  mr        r4, r26
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
  beq+      .loc_0x50
  cmpwi     r31, 0
  ble-      .loc_0x1D4
  bl        0x15A7A0
  xoris     r0, r3, 0x8000
  lfd       f3, -0x6C38(r2)
  stw       r0, 0x1DC(r1)
  lis       r3, 0x4330
  xoris     r0, r31, 0x8000
  lfs       f0, -0x6C40(r2)
  stw       r3, 0x1D8(r1)
  lfs       f1, -0x6C44(r2)
  lfd       f2, 0x1D8(r1)
  stw       r0, 0x1D4(r1)
  fsubs     f2, f2, f3
  stw       r3, 0x1D0(r1)
  fdivs     f2, f2, f0
  lfd       f0, 0x1D0(r1)
  fmuls     f1, f1, f2
  fsubs     f0, f0, f3
  fmuls     f0, f0, f1
  fctiwz    f0, f0
  stfd      f0, 0x1C0(r1)
  lwz       r0, 0x1C4(r1)
  stfd      f0, 0x1C8(r1)
  cmpw      r0, r31
  lwz       r0, 0x1CC(r1)
  blt-      .loc_0x1C8
  subi      r0, r31, 0x1

.loc_0x1C8:
  rlwinm    r0,r0,2,0,29
  addi      r3, r1, 0x20
  lwzx      r30, r3, r0

.loc_0x1D4:
  cmplwi    r30, 0
  beq-      .loc_0x21C
  lwz       r3, 0x18(r29)
  cmplwi    r3, 0
  beq-      .loc_0x1F8
  beq-      .loc_0x1F8
  bl        0x26A10
  li        r0, 0
  stw       r0, 0x18(r29)

.loc_0x1F8:
  stw       r30, 0x18(r29)
  lwz       r3, 0x18(r29)
  cmplwi    r3, 0
  beq-      .loc_0x20C
  bl        0x269E4

.loc_0x20C:
  addi      r3, r29, 0
  addi      r4, r30, 0
  bl        0x6590
  b         .loc_0x234

.loc_0x21C:
  lwz       r3, 0x18(r29)
  cmplwi    r3, 0
  beq-      .loc_0x234
  bl        0x269D4
  li        r0, 0
  stw       r0, 0x18(r29)

.loc_0x234:
  lmw       r25, 0x1E4(r1)
  lwz       r0, 0x214(r1)
  lfd       f31, 0x208(r1)
  lfd       f30, 0x200(r1)
  addi      r1, r1, 0x210
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BD9C0
 * Size:	0000DC
 */
void ActPullout::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x28(r1)
  stw       r31, 0x24(r1)
  mr        r31, r3
  lwz       r0, 0x18(r3)
  cmplwi    r0, 0
  bne-      .loc_0x28
  li        r3, 0x2
  b         .loc_0xC8

.loc_0x28:
  lwz       r3, 0xC(r31)
  lbz       r0, 0x518(r3)
  cmplwi    r0, 0
  beq-      .loc_0x90
  lwz       r4, 0x504(r3)
  lwz       r4, 0xADC(r4)
  cmplwi    r4, 0
  beq-      .loc_0x50
  lwz       r0, 0x4(r4)
  b         .loc_0x54

.loc_0x50:
  li        r0, -0x1

.loc_0x54:
  cmpwi     r0, 0x5
  beq-      .loc_0x64
  li        r3, 0x1
  b         .loc_0xC8

.loc_0x64:
  lfs       f0, -0x4740(r13)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x473C(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x4738(r13)
  stfs      f0, 0x8(r3)
  lwz       r3, 0xC(r31)
  lwz       r4, 0x504(r3)
  addi      r4, r4, 0x94
  bl        -0x3300C
  b         .loc_0xC4

.loc_0x90:
  mr        r3, r31
  bl        0x65A0
  cmpwi     r3, 0
  beq-      .loc_0xC8
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x48(r12)
  mtlr      r12
  blrl      
  li        r3, 0
  b         .loc_0xC8
  b         .loc_0xC8

.loc_0xC4:
  li        r3, 0

.loc_0xC8:
  lwz       r0, 0x2C(r1)
  lwz       r31, 0x24(r1)
  addi      r1, r1, 0x28
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BDA9C
 * Size:	000050
 */
void ActPullout::cleanup()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  bl        0x69F4
  lwz       r3, 0xC(r31)
  li        r0, 0x1
  stb       r0, 0x518(r3)
  lwz       r3, 0x18(r31)
  cmplwi    r3, 0
  beq-      .loc_0x3C
  bl        0x268A0
  li        r0, 0
  stw       r0, 0x18(r31)

.loc_0x3C:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BDAEC
 * Size:	000074
 */
void ActPulloutCreature::cleanup()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  mr        r31, r3
  lbz       r0, 0x24(r3)
  cmplwi    r0, 0
  bne-      .loc_0x48
  lwz       r0, 0x20(r31)
  cmplwi    r0, 0
  mr        r4, r0
  beq-      .loc_0x48
  lwz       r3, 0x490(r4)
  li        r5, 0x2
  lwz       r12, 0x0(r3)
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      

.loc_0x48:
  lwz       r3, 0x20(r31)
  cmplwi    r3, 0
  beq-      .loc_0x60
  bl        0x2682C
  li        r0, 0
  stw       r0, 0x20(r31)

.loc_0x60:
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BDB60
 * Size:	000078
 */
void ActPulloutCreature::animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x0(r4)
  cmpwi     r0, 0x1
  beq-      .loc_0x68
  bge-      .loc_0x28
  cmpwi     r0, 0
  bge-      .loc_0x60
  b         .loc_0x68

.loc_0x28:
  cmpwi     r0, 0x3
  bge-      .loc_0x68
  li        r0, 0x1
  stb       r0, 0x24(r3)
  lwz       r0, 0x20(r3)
  cmplwi    r0, 0
  mr        r3, r0
  beq-      .loc_0x68
  lwz       r12, 0x0(r3)
  lwz       r4, 0x4B8(r3)
  lwz       r12, 0x12C(r12)
  mtlr      r12
  blrl      
  b         .loc_0x68

.loc_0x60:
  li        r0, 0x2
  stw       r0, 0x18(r3)

.loc_0x68:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BDBD8
 * Size:	00005C
 */
ActPulloutCreature::ActPulloutCreature(Piki *)
{
/*
.loc_0x0:
  mflr      r0
  li        r5, 0x1
  stw       r0, 0x4(r1)
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r3, 0
  bl        0x61E0
  lis       r3, 0x802B
  subi      r0, r3, 0x246C
  lis       r3, 0x802B
  stw       r0, 0x14(r31)
  addi      r3, r3, 0x7200
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
 * Address:	800BDC34
 * Size:	000094
 */
void ActPulloutCreature::init(Creature *)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  li        r31, 0
  stw       r30, 0x18(r1)
  mr        r30, r4
  stw       r29, 0x14(r1)
  addi      r29, r3, 0
  stw       r31, 0x18(r3)
  lwz       r3, 0x20(r3)
  cmplwi    r3, 0
  beq-      .loc_0x40
  beq-      .loc_0x40
  bl        0x26700
  stw       r31, 0x20(r29)

.loc_0x40:
  stw       r30, 0x20(r29)
  lwz       r3, 0x20(r29)
  cmplwi    r3, 0
  beq-      .loc_0x54
  bl        0x266D8

.loc_0x54:
  lwz       r3, 0xC(r29)
  li        r0, 0
  lfs       f0, -0x4734(r13)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x4730(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x472C(r13)
  stfs      f0, 0x8(r3)
  stb       r0, 0x24(r29)
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
 * Address:	800BDCC8
 * Size:	000240
 */
void ActPulloutCreature::exec()
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0xA0(r1)
  stfd      f31, 0x98(r1)
  stw       r31, 0x94(r1)
  mr        r31, r3
  stw       r30, 0x90(r1)
  stw       r29, 0x8C(r1)
  lfs       f0, -0x4728(r13)
  lwz       r3, 0xC(r3)
  stfsu     f0, 0xA4(r3)
  lfs       f0, -0x4724(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x4720(r13)
  stfs      f0, 0x8(r3)
  lwz       r0, 0x18(r31)
  cmpwi     r0, 0x1
  beq-      .loc_0x184
  bge-      .loc_0x58
  cmpwi     r0, 0
  bge-      .loc_0x68
  b         .loc_0x21C

.loc_0x58:
  cmpwi     r0, 0x3
  bge-      .loc_0x21C
  li        r3, 0x2
  b         .loc_0x220

.loc_0x68:
  lwz       r4, 0xC(r31)
  lwz       r3, 0x20(r31)
  lfsu      f1, 0x94(r4)
  lfsu      f3, 0x94(r3)
  lfs       f0, 0x8(r4)
  lfs       f2, 0x8(r3)
  fsubs     f1, f3, f1
  fsubs     f2, f2, f0
  bl        0x15DCA8
  lwz       r3, 0xC(r31)
  fmr       f31, f1
  lfs       f2, 0xA0(r3)
  bl        -0x857AC
  lfs       f0, -0x6C30(r2)
  lwz       r3, 0xC(r31)
  fmuls     f1, f0, f1
  lfs       f0, 0xA0(r3)
  fadds     f0, f0, f1
  stfs      f0, 0xA0(r3)
  lwz       r3, 0xC(r31)
  lfs       f1, 0xA0(r3)
  bl        -0x857FC
  lwz       r3, 0xC(r31)
  stfs      f1, 0xA0(r3)
  fmr       f1, f31
  lwz       r3, 0xC(r31)
  lfs       f2, 0xA0(r3)
  bl        -0x857E8
  stfs      f1, 0x4C(r1)
  lfs       f0, -0x6C2C(r2)
  lwz       r0, 0x4C(r1)
  rlwinm    r0,r0,0,1,31
  stw       r0, 0x4C(r1)
  lfs       f1, 0x4C(r1)
  fcmpo     cr0, f1, f0
  bge-      .loc_0x21C
  li        r0, 0x1
  cmplwi    r31, 0
  stw       r0, 0x18(r31)
  mr        r29, r31
  beq-      .loc_0x110
  addi      r29, r29, 0x14

.loc_0x110:
  addi      r3, r1, 0x58
  li        r4, 0x5
  bl        0x61178
  addi      r30, r3, 0
  addi      r5, r29, 0
  addi      r3, r1, 0x60
  li        r4, 0x5
  bl        0x61198
  mr        r4, r3
  lwz       r3, 0xC(r31)
  mr        r5, r30
  bl        0xCBD4
  lis       r3, 0x802B
  lwz       r5, 0xC(r31)
  subi      r0, r3, 0x3064
  stw       r0, 0x50(r1)
  lis       r3, 0x802B
  subi      r0, r3, 0x2CFC
  stw       r5, 0x54(r1)
  addi      r4, r1, 0x50
  stw       r0, 0x50(r1)
  lwz       r3, 0x20(r31)
  lwz       r12, 0x0(r3)
  lwz       r12, 0xA0(r12)
  mtlr      r12
  blrl      
  lfs       f0, -0x6C28(r2)
  stfs      f0, 0x1C(r31)
  b         .loc_0x21C

.loc_0x184:
  lwz       r3, 0x2DEC(r13)
  lis       r0, 0x4330
  lfs       f1, 0x1C(r31)
  lfs       f0, 0x28C(r3)
  lwz       r29, 0x20(r31)
  fadds     f0, f1, f0
  stfs      f0, 0x1C(r31)
  lwz       r3, 0x4B8(r29)
  lfd       f1, -0x6C38(r2)
  xoris     r3, r3, 0x8000
  lfs       f2, 0x1C(r31)
  stw       r3, 0x84(r1)
  stw       r0, 0x80(r1)
  lfd       f0, 0x80(r1)
  fsubs     f0, f0, f1
  fcmpo     cr0, f2, f0
  cror      2, 0x1, 0x2
  bne-      .loc_0x200
  cmplwi    r31, 0
  addi      r4, r31, 0
  beq-      .loc_0x1DC
  addi      r4, r4, 0x14

.loc_0x1DC:
  lwz       r3, 0xC(r31)
  addi      r3, r3, 0x354
  bl        0x61C14
  cmplwi    r29, 0
  addi      r4, r29, 0
  beq-      .loc_0x1F8
  addi      r4, r4, 0x2B8

.loc_0x1F8:
  addi      r3, r29, 0x354
  bl        0x61BFC

.loc_0x200:
  lwz       r3, 0xC(r31)
  lfs       f0, -0x471C(r13)
  stfsu     f0, 0x70(r3)
  lfs       f0, -0x4718(r13)
  stfs      f0, 0x4(r3)
  lfs       f0, -0x4714(r13)
  stfs      f0, 0x8(r3)

.loc_0x21C:
  li        r3, 0

.loc_0x220:
  lwz       r0, 0xA4(r1)
  lfd       f31, 0x98(r1)
  lwz       r31, 0x94(r1)
  lwz       r30, 0x90(r1)
  lwz       r29, 0x8C(r1)
  addi      r1, r1, 0xA0
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800BDF08
 * Size:	00006C
 */
ActPulloutCreature::~ActPulloutCreature()
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
  addi      r3, r3, 0x7200
  stw       r3, 0x0(r30)
  addi      r0, r3, 0x64
  addi      r3, r30, 0
  stw       r0, 0x14(r30)
  li        r4, 0
  bl        0x5EC4
  extsh.    r0, r31
  ble-      .loc_0x50
  mr        r3, r30
  bl        -0x76DA8

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
 * Address:	800BDF74
 * Size:	000074
 */
ActPullout::~ActPullout()
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
  addi      r0, r3, 0x72DC
  stw       r0, 0x0(r30)
  beq-      .loc_0x48
  lis       r3, 0x802C
  subi      r0, r3, 0x7ED0
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  li        r4, 0
  bl        0x5E50

.loc_0x48:
  extsh.    r0, r31
  ble-      .loc_0x58
  mr        r3, r30
  bl        -0x76E1C

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
 * Address:	800BDFE8
 * Size:	000008
 */
void ActPulloutCreature::@20@animationKeyUpdated(PaniAnimKeyEvent &)
{
/*
.loc_0x0:
  subi      r3, r3, 0x14
  b         -0x48C
*/
}
