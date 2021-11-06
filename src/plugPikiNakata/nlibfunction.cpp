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
 * Size:	000074
 */
NPolynomialFunction::NPolynomialFunction(float *, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B6E4
 * Size:	000028
 */
void NPolynomialFunction::construct(float *, int)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x4
  stw       r0, 0x4(r1)
  addi      r5, r5, 0x1
  stwu      r1, -0x8(r1)
  bl        0x16D8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
NPolynomialFunction::NPolynomialFunction(float *, NPolynomialFunction &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NPolynomialFunction::construct(float *, NPolynomialFunction &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00029C
 */
void NPolynomialFunction::mul2(NPolynomialFunction &, NPolynomialFunction &)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B70C
 * Size:	000114
 */
void NPolynomialFunction::getValue(float)
{
/*
.loc_0x0:
  lwz       r6, 0x8(r3)
  li        r7, 0
  lfs       f7, -0x5FFC(r2)
  cmpwi     r6, 0
  lfs       f8, -0x6000(r2)
  ble-      .loc_0x100
  cmpwi     r6, 0x8
  subi      r4, r6, 0x8
  ble-      .loc_0x108
  addi      r0, r4, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r4, 0
  mtctr     r0
  li        r4, 0
  ble-      .loc_0x108

.loc_0x3C:
  lwz       r0, 0x4(r3)
  addi      r7, r7, 0x8
  add       r5, r0, r4
  lfs       f2, 0x0(r5)
  addi      r4, r4, 0x20
  lfs       f0, 0x4(r5)
  fmuls     f2, f7, f2
  lfs       f6, 0x8(r5)
  fmuls     f7, f7, f1
  lfs       f5, 0xC(r5)
  lfs       f4, 0x10(r5)
  fmuls     f0, f7, f0
  lfs       f3, 0x14(r5)
  fadds     f8, f8, f2
  lfs       f2, 0x18(r5)
  fmuls     f7, f7, f1
  fadds     f8, f8, f0
  lfs       f0, 0x1C(r5)
  fmuls     f6, f7, f6
  fmuls     f7, f7, f1
  fadds     f8, f8, f6
  fmuls     f5, f7, f5
  fmuls     f7, f7, f1
  fadds     f8, f8, f5
  fmuls     f4, f7, f4
  fmuls     f7, f7, f1
  fadds     f8, f8, f4
  fmuls     f3, f7, f3
  fmuls     f7, f7, f1
  fadds     f8, f8, f3
  fmuls     f2, f7, f2
  fmuls     f7, f7, f1
  fadds     f8, f8, f2
  fmuls     f0, f7, f0
  fmuls     f7, f7, f1
  fadds     f8, f8, f0
  bdnz+     .loc_0x3C
  b         .loc_0x108

.loc_0xD4:
  sub       r0, r6, r7
  cmpw      r7, r6
  mtctr     r0
  bge-      .loc_0x100

.loc_0xE4:
  lwz       r4, 0x4(r3)
  lfsx      f0, r4, r5
  addi      r5, r5, 0x4
  fmuls     f0, f7, f0
  fmuls     f7, f7, f1
  fadds     f8, f8, f0
  bdnz+     .loc_0xE4

.loc_0x100:
  fmr       f1, f8
  blr       

.loc_0x108:
  rlwinm    r5,r7,2,0,29
  b         .loc_0xD4
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NPolynomialFunction::getCoefficient(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B820
 * Size:	000058
 */
void NPolynomialFunction::println()
{
/*
.loc_0x0:
  lwz       r5, 0x8(r3)
  li        r6, 0
  cmpwi     r5, 0
  blelr-    
  cmpwi     r5, 0x8
  subi      r4, r5, 0x8
  ble-      .loc_0x38
  addi      r0, r4, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r4, 0
  mtctr     r0
  ble-      .loc_0x38

.loc_0x30:
  addi      r6, r6, 0x8
  bdnz+     .loc_0x30

.loc_0x38:
  sub       r0, r5, r6
  cmpw      r6, r5
  mtctr     r0
  bgelr-    

.loc_0x48:
  bdnz-     .loc_0x48
  blr       
  b         .loc_0x38
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
NLinearFunction::NLinearFunction(float *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NLinearFunction::construct(float *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void NLinearFunction::makeLinearFunction(float, float, float, float)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011B878
 * Size:	00007C
 */
NClampLinearFunction::NClampLinearFunction(float *)
{
/*
.loc_0x0:
  mflr      r0
  lis       r5, 0x802C
  stw       r0, 0x4(r1)
  addi      r0, r5, 0x425C
  stwu      r1, -0x18(r1)
  stw       r31, 0x14(r1)
  addi      r31, r4, 0
  stw       r30, 0x10(r1)
  addi      r30, r3, 0
  lis       r3, 0x802C
  stw       r0, 0x0(r30)
  addi      r0, r3, 0x424C
  addi      r3, r30, 0x4
  stw       r0, 0x0(r30)
  bl        0x1510
  lis       r3, 0x802C
  addi      r0, r3, 0x423C
  lis       r3, 0x802C
  stw       r0, 0x0(r30)
  addi      r0, r3, 0x422C
  stw       r0, 0x0(r30)
  addi      r3, r30, 0
  addi      r4, r31, 0
  bl        .loc_0x7C
  mr        r3, r30
  lwz       r0, 0x1C(r1)
  lwz       r31, 0x14(r1)
  lwz       r30, 0x10(r1)
  addi      r1, r1, 0x18
  mtlr      r0
  blr       

.loc_0x7C:
*/
}

/*
 * --INFO--
 * Address:	8011B8F4
 * Size:	000028
 */
void NClampLinearFunction::construct(float *)
{
/*
.loc_0x0:
  mflr      r0
  addi      r3, r3, 0x4
  stw       r0, 0x4(r1)
  li        r5, 0x2
  stwu      r1, -0x8(r1)
  bl        0x14C8
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	8011B91C
 * Size:	000090
 */
void NClampLinearFunction::makeClampLinearFunction(float, float, float, float)
{
/*
.loc_0x0:
  fsubs     f5, f3, f1
  lfs       f0, -0x6000(r2)
  fcmpo     cr0, f5, f0
  ble-      .loc_0x18
  fmr       f3, f5
  b         .loc_0x1C

.loc_0x18:
  fneg      f3, f5

.loc_0x1C:
  lfs       f0, -0x1CB0(r13)
  fcmpo     cr0, f3, f0
  cror      2, 0, 0x2
  bne-      .loc_0x3C
  lfs       f0, -0x5FFC(r2)
  lwz       r4, 0x4(r3)
  stfs      f0, 0x4(r4)
  b         .loc_0x4C

.loc_0x3C:
  fsubs     f0, f4, f2
  lwz       r4, 0x4(r3)
  fdivs     f0, f0, f5
  stfs      f0, 0x4(r4)

.loc_0x4C:
  lwz       r4, 0x4(r3)
  fcmpo     cr0, f2, f4
  lfs       f0, 0x4(r4)
  fmuls     f0, f0, f1
  fsubs     f0, f2, f0
  stfs      f0, 0x0(r4)
  bge-      .loc_0x70
  fmr       f0, f2
  b         .loc_0x74

.loc_0x70:
  fmr       f0, f4

.loc_0x74:
  fcmpo     cr0, f2, f4
  stfs      f0, 0xC(r3)
  bge-      .loc_0x84
  b         .loc_0x88

.loc_0x84:
  fmr       f4, f2

.loc_0x88:
  stfs      f4, 0x10(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011B9AC
 * Size:	000134
 */
void NClampLinearFunction::getValue(float)
{
/*
.loc_0x0:
  lwz       r6, 0x8(r3)
  li        r4, 0
  lfs       f8, -0x5FFC(r2)
  cmpwi     r6, 0
  lfs       f7, -0x6000(r2)
  ble-      .loc_0x100
  cmpwi     r6, 0x8
  subi      r5, r6, 0x8
  ble-      .loc_0x128
  addi      r0, r5, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r5, 0
  mtctr     r0
  addi      r5, r4, 0
  ble-      .loc_0x128

.loc_0x3C:
  lwz       r0, 0x4(r3)
  addi      r4, r4, 0x8
  add       r7, r0, r5
  lfs       f2, 0x0(r7)
  addi      r5, r5, 0x20
  lfs       f0, 0x4(r7)
  fmuls     f2, f8, f2
  lfs       f6, 0x8(r7)
  fmuls     f8, f8, f1
  lfs       f5, 0xC(r7)
  lfs       f4, 0x10(r7)
  fmuls     f0, f8, f0
  lfs       f3, 0x14(r7)
  fadds     f7, f7, f2
  lfs       f2, 0x18(r7)
  fmuls     f8, f8, f1
  fadds     f7, f7, f0
  lfs       f0, 0x1C(r7)
  fmuls     f6, f8, f6
  fmuls     f8, f8, f1
  fadds     f7, f7, f6
  fmuls     f5, f8, f5
  fmuls     f8, f8, f1
  fadds     f7, f7, f5
  fmuls     f4, f8, f4
  fmuls     f8, f8, f1
  fadds     f7, f7, f4
  fmuls     f3, f8, f3
  fmuls     f8, f8, f1
  fadds     f7, f7, f3
  fmuls     f2, f8, f2
  fmuls     f8, f8, f1
  fadds     f7, f7, f2
  fmuls     f0, f8, f0
  fmuls     f8, f8, f1
  fadds     f7, f7, f0
  bdnz+     .loc_0x3C
  b         .loc_0x128

.loc_0xD4:
  sub       r0, r6, r4
  cmpw      r4, r6
  mtctr     r0
  bge-      .loc_0x100

.loc_0xE4:
  lwz       r4, 0x4(r3)
  lfsx      f0, r4, r5
  addi      r5, r5, 0x4
  fmuls     f0, f8, f0
  fmuls     f8, f8, f1
  fadds     f7, f7, f0
  bdnz+     .loc_0xE4

.loc_0x100:
  lfs       f1, 0xC(r3)
  lfs       f0, 0x10(r3)
  fcmpo     cr0, f7, f1
  bltlr-    
  fcmpo     cr0, f7, f0
  ble-      .loc_0x120
  fmr       f1, f0
  blr       

.loc_0x120:
  fmr       f1, f7
  blr       

.loc_0x128:
  rlwinm    r5,r4,2,0,29
  b         .loc_0xD4
  blr
*/
}

/*
 * --INFO--
 * Address:	8011BAE0
 * Size:	000058
 */
void NClampLinearFunction::println()
{
/*
.loc_0x0:
  lwz       r6, 0x8(r3)
  li        r4, 0
  cmpwi     r6, 0
  blelr-    
  cmpwi     r6, 0x8
  subi      r5, r6, 0x8
  ble-      .loc_0x38
  addi      r0, r5, 0x7
  rlwinm    r0,r0,29,3,31
  cmpwi     r5, 0
  mtctr     r0
  ble-      .loc_0x38

.loc_0x30:
  addi      r4, r4, 0x8
  bdnz+     .loc_0x30

.loc_0x38:
  sub       r0, r6, r4
  cmpw      r4, r6
  mtctr     r0
  bgelr-    

.loc_0x48:
  bdnz-     .loc_0x48
  blr       
  b         .loc_0x38
  blr
*/
}

/*
 * --INFO--
 * Address:	8011BB38
 * Size:	00003C
 */
NVibrationFunction::NVibrationFunction()
{
/*
.loc_0x0:
  lis       r4, 0x802C
  addi      r0, r4, 0x425C
  lis       r4, 0x802C
  stw       r0, 0x0(r3)
  addi      r0, r4, 0x41A8
  stw       r0, 0x0(r3)
  lfs       f0, -0x6000(r2)
  stfs      f0, 0x4(r3)
  lfs       f1, -0x5FF8(r2)
  lfs       f0, -0x1CA4(r13)
  fmuls     f0, f1, f0
  stfs      f0, 0x8(r3)
  lfs       f0, -0x5FFC(r2)
  stfs      f0, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011BB74
 * Size:	000020
 */
void NVibrationFunction::makeVibrationFunction(float, float, float)
{
/*
.loc_0x0:
  stfs      f1, 0x4(r3)
  lfs       f1, -0x5FF8(r2)
  lfs       f0, -0x1CA4(r13)
  fmuls     f0, f1, f0
  fdivs     f0, f0, f2
  stfs      f0, 0x8(r3)
  stfs      f3, 0xC(r3)
  blr
*/
}

/*
 * --INFO--
 * Address:	8011BB94
 * Size:	000044
 */
void NVibrationFunction::getValue(float)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x20(r1)
  stw       r31, 0x1C(r1)
  mr        r31, r3
  lfs       f0, 0x8(r3)
  lfs       f2, 0x4(r3)
  fmuls     f0, f0, f1
  fadds     f1, f2, f0
  bl        0x100130
  lfs       f0, 0xC(r31)
  lwz       r0, 0x24(r1)
  fmuls     f1, f0, f1
  lwz       r31, 0x1C(r1)
  addi      r1, r1, 0x20
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
NFunction3D::NFunction3D()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NFunction3D::construct(NFunction *, NFunction *, NFunction *)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011BBD8
 * Size:	0000A8
 */
void NFunction3D::outputPosition(float, NVector3f &)
{
/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x38(r1)
  stfd      f31, 0x30(r1)
  stfd      f30, 0x28(r1)
  stfd      f29, 0x20(r1)
  fmr       f29, f1
  stw       r31, 0x1C(r1)
  mr        r31, r4
  stw       r30, 0x18(r1)
  mr        r30, r3
  lwz       r3, 0x8(r3)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x4(r30)
  fmr       f30, f1
  fmr       f1, f29
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  lwz       r3, 0x0(r30)
  fmr       f31, f1
  fmr       f1, f29
  lwz       r12, 0x0(r3)
  lwz       r12, 0x8(r12)
  mtlr      r12
  blrl      
  stfs      f1, 0x0(r31)
  stfs      f31, 0x4(r31)
  stfs      f30, 0x8(r31)
  lwz       r0, 0x3C(r1)
  lfd       f31, 0x30(r1)
  lfd       f30, 0x28(r1)
  lfd       f29, 0x20(r1)
  lwz       r31, 0x1C(r1)
  lwz       r30, 0x18(r1)
  addi      r1, r1, 0x38
  mtlr      r0
  blr
*/
}
