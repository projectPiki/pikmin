#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
ParaParametersI::ParaParametersI(int, ParaParameterInfoI*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801215A4
 * Size:	000080
 */
void ParaParametersI::read(Stream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x0(r28)
	  addi      r30, r30, 0x1
	  stwx      r3, r4, r31
	  addi      r31, r31, 0x4

	.loc_0x54:
	  lwz       r0, 0x4(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	80121624
 * Size:	000080
 */
void ParaParametersI::write(Stream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  rlwinm    r31,r30,2,0,29
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  mr        r3, r29
	  lwz       r4, 0x0(r28)
	  lwz       r12, 0x4(r29)
	  lwzx      r4, r4, r31
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x4(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	801216A4
 * Size:	000058
 */
void ParaParametersI::print()
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
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
 * Size:	00009C
 */
ParaParametersF::ParaParametersF(int, ParaParameterInfoF*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801216FC
 * Size:	000080
 */
void ParaParametersF::read(Stream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  li        r31, 0
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  mr        r3, r29
	  lwz       r12, 0x4(r29)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r28)
	  addi      r30, r30, 0x1
	  stfsx     f1, r3, r31
	  addi      r31, r31, 0x4

	.loc_0x54:
	  lwz       r0, 0x4(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	8012177C
 * Size:	000080
 */
void ParaParametersF::write(Stream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  rlwinm    r31,r30,2,0,29
	  stw       r29, 0x14(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  b         .loc_0x54

	.loc_0x30:
	  mr        r3, r29
	  lwz       r4, 0x0(r28)
	  lwz       r12, 0x4(r29)
	  lfsx      f1, r4, r31
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  addi      r31, r31, 0x4
	  addi      r30, r30, 0x1

	.loc_0x54:
	  lwz       r0, 0x4(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x30
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
 * Address:	801217FC
 * Size:	000058
 */
void ParaParametersF::print()
{
	/*
	.loc_0x0:
	  lwz       r5, 0x4(r3)
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
 * Address:	80121854
 * Size:	0000A8
 */
ParaMultiParameters::ParaMultiParameters(int, ParaParameterInfoI*, int, ParaParameterInfoF*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r8, 0x802C
	  stw       r0, 0x4(r1)
	  addi      r0, r8, 0x50B0
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  addi      r28, r5, 0
	  addi      r29, r6, 0
	  addi      r30, r7, 0
	  stw       r0, 0x8(r3)
	  li        r3, 0x10
	  bl        -0xDA884
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x5C
	  addi      r4, r27, 0
	  addi      r5, r28, 0
	  bl        0xEC
	  lis       r3, 0x802C
	  addi      r0, r3, 0x5150
	  stw       r0, 0xC(r31)

	.loc_0x5C:
	  stw       r31, 0x0(r26)
	  li        r3, 0x10
	  bl        -0xDA8B4
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x8C
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  bl        .loc_0xA8
	  lis       r3, 0x802C
	  addi      r0, r3, 0x50F8
	  stw       r0, 0xC(r31)

	.loc_0x8C:
	  stw       r31, 0x4(r26)
	  mr        r3, r26
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr

	.loc_0xA8:
	*/
}

/*
 * --INFO--
 * Address:	801218FC
 * Size:	000090
 */
void ParaParameters<f32>::ParaParameters(int, ParaParameterInfo<f32>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802C
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x510C
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r0, 0xC(r3)
	  stw       r4, 0x4(r3)
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x44
	  rlwinm    r3,r0,2,0,29
	  bl        -0xDA930
	  stw       r3, 0x0(r31)
	  b         .loc_0x4C

	.loc_0x44:
	  li        r0, 0
	  stw       r0, 0x0(r31)

	.loc_0x4C:
	  lfs       f0, -0x5F48(r2)
	  li        r5, 0
	  li        r4, 0
	  b         .loc_0x6C

	.loc_0x5C:
	  lwz       r3, 0x0(r31)
	  addi      r5, r5, 0x1
	  stfsx     f0, r3, r4
	  addi      r4, r4, 0x4

	.loc_0x6C:
	  lwz       r0, 0x4(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x5C
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
 * Address:	8012198C
 * Size:	000090
 */
void ParaParameters<int>::ParaParameters(int, ParaParameterInfo<int>*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802C
	  stw       r0, 0x4(r1)
	  addi      r0, r6, 0x5164
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  stw       r0, 0xC(r3)
	  stw       r4, 0x4(r3)
	  stw       r5, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0
	  ble-      .loc_0x44
	  rlwinm    r3,r0,2,0,29
	  bl        -0xDA9C0
	  stw       r3, 0x0(r31)
	  b         .loc_0x4C

	.loc_0x44:
	  li        r0, 0
	  stw       r0, 0x0(r31)

	.loc_0x4C:
	  li        r5, 0
	  addi      r4, r5, 0
	  li        r6, 0
	  b         .loc_0x6C

	.loc_0x5C:
	  lwz       r3, 0x0(r31)
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4

	.loc_0x6C:
	  lwz       r0, 0x4(r31)
	  cmpw      r6, r0
	  blt+      .loc_0x5C
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
 * Address:	80121A1C
 * Size:	000074
 */
void ParaMultiParameters::input(ParaMultiParameters&)
{
	/*
	.loc_0x0:
	  li        r7, 0
	  lwz       r9, 0x0(r4)
	  lwz       r8, 0x0(r3)
	  mr        r10, r7
	  b         .loc_0x2C

	.loc_0x14:
	  lwz       r6, 0x0(r9)
	  addi      r7, r7, 0x1
	  lwz       r5, 0x0(r8)
	  lwzx      r0, r6, r10
	  stwx      r0, r5, r10
	  addi      r10, r10, 0x4

	.loc_0x2C:
	  lwz       r0, 0x4(r8)
	  cmpw      r7, r0
	  blt+      .loc_0x14
	  li        r5, 0
	  lwz       r7, 0x4(r4)
	  lwz       r6, 0x4(r3)
	  mr        r8, r5
	  b         .loc_0x64

	.loc_0x4C:
	  lwz       r4, 0x0(r7)
	  addi      r5, r5, 0x1
	  lwz       r3, 0x0(r6)
	  lfsx      f0, r4, r8
	  stfsx     f0, r3, r8
	  addi      r8, r8, 0x4

	.loc_0x64:
	  lwz       r0, 0x4(r6)
	  cmpw      r5, r0
	  blt+      .loc_0x4C
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80121A90
 * Size:	000060
 */
void ParaMultiParameters::read(Stream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0xC(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0xC(r3)
	  lwz       r12, 0x8(r12)
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
 * Address:	80121AF0
 * Size:	000060
 */
void ParaMultiParameters::write(Stream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0xC(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r30)
	  mr        r4, r31
	  lwz       r12, 0xC(r3)
	  lwz       r12, 0xC(r12)
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
 * Address:	80121B50
 * Size:	000050
 */
void ParaMultiParameters::print()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  lwz       r12, 0xC(r3)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r31)
	  lwz       r12, 0xC(r3)
	  lwz       r12, 0x10(r12)
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
 * Address:	80121BA0
 * Size:	000004
 */
void ParaParameters<f32>::read(Stream&) { }

/*
 * --INFO--
 * Address:	80121BA4
 * Size:	000004
 */
void ParaParameters<f32>::write(Stream&) { }

/*
 * --INFO--
 * Address:	80121BA8
 * Size:	000004
 */
void ParaParameters<f32>::print() { }

/*
 * --INFO--
 * Address:	80121BAC
 * Size:	000004
 */
void ParaParameters<int>::read(Stream&) { }

/*
 * --INFO--
 * Address:	80121BB0
 * Size:	000004
 */
void ParaParameters<int>::write(Stream&) { }

/*
 * --INFO--
 * Address:	80121BB4
 * Size:	000004
 */
void ParaParameters<int>::print() { }
