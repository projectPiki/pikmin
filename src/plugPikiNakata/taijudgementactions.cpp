

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
 * Address:	8012F4CC
 * Size:	000050
 */
void TaiVisibleTargetAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x418(r4)
  cmplwi    r0, 0
  bne-      .loc_0x20
  li        r3, 0
  b         .loc_0x40

.loc_0x20:
  addi      r3, r4, 0
  mr        r4, r0
  bl        0x17820
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x3C
  li        r3, 0
  b         .loc_0x40

.loc_0x3C:
  li        r3, 0x1

.loc_0x40:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012F51C
 * Size:	000050
 */
void TaiContactTargetAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x418(r4)
  cmplwi    r0, 0
  bne-      .loc_0x20
  li        r3, 0
  b         .loc_0x40

.loc_0x20:
  addi      r3, r4, 0
  mr        r4, r0
  bl        0x17AB4
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x3C
  li        r3, 0
  b         .loc_0x40

.loc_0x3C:
  li        r3, 0x1

.loc_0x40:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012F56C
 * Size:	000050
 */
void TaiSeparateTargetAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r0, 0x418(r4)
  cmplwi    r0, 0
  bne-      .loc_0x20
  li        r3, 0x1
  b         .loc_0x40

.loc_0x20:
  addi      r3, r4, 0
  mr        r4, r0
  bl        0x17910
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x3C
  li        r3, 0
  b         .loc_0x40

.loc_0x3C:
  li        r3, 0x1

.loc_0x40:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012F5BC
 * Size:	000074
 */
void TaiTargetLostAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r4
  lwz       r0, 0x418(r4)
  cmplwi    r0, 0
  mr        r4, r0
  bne-      .loc_0x2C
  li        r3, 0x1
  b         .loc_0x60

.loc_0x2C:
  mr        r3, r31
  bl        0x17728
  rlwinm.   r0,r3,0,24,31
  bne-      .loc_0x5C
  lwz       r3, 0x418(r31)
  cmplwi    r3, 0
  beq-      .loc_0x54
  bl        -0x4B298
  li        r0, 0
  stw       r0, 0x418(r31)

.loc_0x54:
  li        r3, 0x1
  b         .loc_0x60

.loc_0x5C:
  li        r3, 0

.loc_0x60:
  lwz       r0, 0x24(r1)
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012F630
 * Size:	0000BC
 */
void TaiOutsideTerritoryAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r8, r4, 0x94
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  addi      r31, r3, 0
  addi      r6, r1, 0x28
  lwz       r7, 0x2C8(r4)
  addi      r5, r1, 0x24
  lfs       f0, -0x5CB8(r2)
  addi      r4, r1, 0x20
  addi      r7, r7, 0x10
  stfs      f0, 0x3C(r1)
  addi      r3, r1, 0x34
  stfs      f0, 0x38(r1)
  stfs      f0, 0x34(r1)
  lfs       f1, 0x8(r8)
  lfs       f0, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x28(r1)
  lfs       f1, 0x4(r8)
  lfs       f0, 0x4(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x24(r1)
  lfs       f1, 0x0(r8)
  lfs       f0, 0x0(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x20(r1)
  bl        -0xD2014
  lfs       f1, 0x34(r1)
  lfs       f0, 0x38(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x3C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x121A84
  lfs       f0, 0x8(r31)
  fcmpo     cr0, f1, f0
  mfcr      r0
  rlwinm    r3,r0,2,31,31
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012F6EC
 * Size:	0000C0
 */
void TaiInsideTerritoryAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  addi      r8, r4, 0x94
  stw       r0, 0x4(r1)
  stwu      r1, -0x48(r1)
  stw       r31, 0x44(r1)
  addi      r31, r3, 0
  addi      r6, r1, 0x28
  lwz       r7, 0x2C8(r4)
  addi      r5, r1, 0x24
  lfs       f0, -0x5CB8(r2)
  addi      r4, r1, 0x20
  addi      r7, r7, 0x10
  stfs      f0, 0x3C(r1)
  addi      r3, r1, 0x34
  stfs      f0, 0x38(r1)
  stfs      f0, 0x34(r1)
  lfs       f1, 0x8(r8)
  lfs       f0, 0x8(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x28(r1)
  lfs       f1, 0x4(r8)
  lfs       f0, 0x4(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x24(r1)
  lfs       f1, 0x0(r8)
  lfs       f0, 0x0(r7)
  fsubs     f0, f1, f0
  stfs      f0, 0x20(r1)
  bl        -0xD20D0
  lfs       f1, 0x34(r1)
  lfs       f0, 0x38(r1)
  fmuls     f1, f1, f1
  lfs       f2, 0x3C(r1)
  fmuls     f0, f0, f0
  fmuls     f2, f2, f2
  fadds     f0, f1, f0
  fadds     f1, f2, f0
  bl        -0x121B40
  lfs       f0, 0x8(r31)
  fcmpo     cr0, f1, f0
  cror      2, 0, 0x2
  mfcr      r0
  rlwinm    r3,r0,3,31,31
  lwz       r0, 0x4C(r1)
  lwz       r31, 0x44(r1)
  addi      r1, r1, 0x48
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012F7AC
 * Size:	0000AC
 */
void TaiTargetVisibleNaviPikiAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  lis       r3, 0x802B
  stw       r0, 0x4(r1)
  subi      r0, r3, 0xF68
  lis       r3, 0x802C
  stwu      r1, -0x28(r1)
  li        r5, 0
  stw       r31, 0x24(r1)
  stw       r30, 0x20(r1)
  addi      r30, r4, 0
  addi      r4, r1, 0x18
  stw       r0, 0x18(r1)
  addi      r0, r3, 0x6964
  lis       r3, 0x802D
  stw       r0, 0x18(r1)
  subi      r0, r3, 0x2AF4
  addi      r3, r30, 0
  stw       r0, 0x18(r1)
  stw       r30, 0x1C(r1)
  bl        0x17EE8
  mr.       r31, r3
  bne-      .loc_0x60
  li        r3, 0
  b         .loc_0x94

.loc_0x60:
  lwz       r3, 0x418(r30)
  cmplwi    r3, 0
  beq-      .loc_0x7C
  beq-      .loc_0x7C
  bl        -0x4B4B0
  li        r0, 0
  stw       r0, 0x418(r30)

.loc_0x7C:
  stw       r31, 0x418(r30)
  lwz       r3, 0x418(r30)
  cmplwi    r3, 0
  beq-      .loc_0x90
  bl        -0x4B4DC

.loc_0x90:
  li        r3, 0x1

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
 * Address:	8012F858
 * Size:	0000F0
 */
void TaiTargetVisibleNaviAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802B
  stw       r0, 0x4(r1)
  subi      r6, r5, 0xF68
  lis       r5, 0x802C
  stwu      r1, -0x60(r1)
  addi      r9, r5, 0x6964
  lis       r5, 0x802C
  stw       r31, 0x5C(r1)
  addi      r0, r5, 0x685C
  lis       r5, 0x802D
  stw       r30, 0x58(r1)
  subi      r7, r5, 0x2AF4
  lis       r5, 0x802D
  stw       r6, 0x48(r1)
  addi      r30, r4, 0
  subi      r8, r5, 0x27BC
  lwz       r3, 0x3120(r13)
  stw       r6, 0x40(r1)
  addi      r5, r1, 0x48
  stw       r6, 0x3C(r1)
  addi      r6, r1, 0x40
  addi      r4, r30, 0x94
  stw       r9, 0x48(r1)
  stw       r0, 0x48(r1)
  addi      r0, r1, 0x3C
  stw       r9, 0x40(r1)
  stw       r9, 0x3C(r1)
  stw       r7, 0x40(r1)
  stw       r6, 0x4C(r1)
  stw       r8, 0x3C(r1)
  stw       r30, 0x44(r1)
  stw       r0, 0x50(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x6C(r12)
  mtlr      r12
  blrl      
  mr.       r31, r3
  bne-      .loc_0xA4
  li        r3, 0
  b         .loc_0xD8

.loc_0xA4:
  lwz       r3, 0x418(r30)
  cmplwi    r3, 0
  beq-      .loc_0xC0
  beq-      .loc_0xC0
  bl        -0x4B5A0
  li        r0, 0
  stw       r0, 0x418(r30)

.loc_0xC0:
  stw       r31, 0x418(r30)
  lwz       r3, 0x418(r30)
  cmplwi    r3, 0
  beq-      .loc_0xD4
  bl        -0x4B5CC

.loc_0xD4:
  li        r3, 0x1

.loc_0xD8:
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
 * Address:	8012F948
 * Size:	000128
 */
void TaiHasStickersInMouthAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r3, r1, 0x28
  stw       r30, 0x38(r1)
  bl        -0x9ECDC
  addi      r31, r1, 0x28
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xB0

.loc_0x3C:
  cmpwi     r30, -0x1
  bne-      .loc_0x60
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x78

.loc_0x60:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x78:
  cmplwi    r3, 0
  beq-      .loc_0x10C
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,16,16
  beq-      .loc_0x94
  li        r3, 0x1
  b         .loc_0x110

.loc_0x94:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xB0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD8
  li        r0, 0x1
  b         .loc_0x104

.loc_0xD8:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x100
  li        r0, 0x1
  b         .loc_0x104

.loc_0x100:
  li        r0, 0

.loc_0x104:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x3C

.loc_0x10C:
  li        r3, 0

.loc_0x110:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8012FA70
 * Size:	000128
 */
void TaiHasStickersOnBodyAction::act(Teki &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x40(r1)
  stw       r31, 0x3C(r1)
  addi      r3, r1, 0x28
  stw       r30, 0x38(r1)
  bl        -0x9EE04
  addi      r31, r1, 0x28
  addi      r3, r31, 0
  lwz       r12, 0x0(r31)
  lwz       r12, 0xC(r12)
  mtlr      r12
  blrl      
  mr        r30, r3
  b         .loc_0xB0

.loc_0x3C:
  cmpwi     r30, -0x1
  bne-      .loc_0x60
  mr        r3, r31
  lwz       r12, 0x0(r31)
  li        r4, 0
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  b         .loc_0x78

.loc_0x60:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      

.loc_0x78:
  cmplwi    r3, 0
  beq-      .loc_0x10C
  lwz       r0, 0xC8(r3)
  rlwinm.   r0,r0,0,16,16
  bne-      .loc_0x94
  li        r3, 0x1
  b         .loc_0x110

.loc_0x94:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x10(r12)
  mtlr      r12
  blrl      
  mr        r30, r3

.loc_0xB0:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x14(r12)
  mtlr      r12
  blrl      
  rlwinm.   r0,r3,0,24,31
  beq-      .loc_0xD8
  li        r0, 0x1
  b         .loc_0x104

.loc_0xD8:
  mr        r3, r31
  lwz       r12, 0x0(r31)
  mr        r4, r30
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  cmplwi    r3, 0
  bne-      .loc_0x100
  li        r0, 0x1
  b         .loc_0x104

.loc_0x100:
  li        r0, 0

.loc_0x104:
  rlwinm.   r0,r0,0,24,31
  beq+      .loc_0x3C

.loc_0x10C:
  li        r3, 0

.loc_0x110:
  lwz       r0, 0x44(r1)
  lwz       r31, 0x3C(r1)
  lwz       r30, 0x38(r1)
  addi      r1, r1, 0x40
  mtlr      r0
  blr
*/
}