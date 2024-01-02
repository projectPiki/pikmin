#include "types.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
void _Error(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E467C
 * Size:	000020
 */
void RockGen::workable()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x3C8(r3)
	  li        r3, 0x5
	  eqv       r0, r3, r4
	  subc      r3, r4, r3
	  rlwinm    r0,r0,1,31,31
	  addze     r3, r0
	  rlwinm    r3,r3,0,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E469C
 * Size:	000018
 */
void RockGen::startWork()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x3C8(r3)
	  cmpwi     r4, 0x5
	  bgelr-
	  addi      r0, r4, 0x1
	  stw       r0, 0x3C8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E46B4
 * Size:	000018
 */
void RockGen::finishWork()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x3C8(r3)
	  cmpwi     r4, 0
	  blelr-
	  subi      r0, r4, 0x1
	  stw       r0, 0x3C8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E46CC
 * Size:	000020
 */
void GrassGen::workable()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x3C8(r3)
	  li        r3, 0x5
	  eqv       r0, r3, r4
	  subc      r3, r4, r3
	  rlwinm    r0,r0,1,31,31
	  addze     r3, r0
	  rlwinm    r3,r3,0,31,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E46EC
 * Size:	000018
 */
void GrassGen::startWork()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x3C8(r3)
	  cmpwi     r4, 0x5
	  bgelr-
	  addi      r0, r4, 0x1
	  stw       r0, 0x3C8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4704
 * Size:	000018
 */
void GrassGen::finishWork()
{
	/*
	.loc_0x0:
	  lwz       r4, 0x3C8(r3)
	  cmpwi     r4, 0
	  blelr-
	  subi      r0, r4, 0x1
	  stw       r0, 0x3C8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E471C
 * Size:	00025C
 */
void RockGen::resolve()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stfd      f27, 0xD0(r1)
	  stfd      f26, 0xC8(r1)
	  stfd      f25, 0xC0(r1)
	  stfd      f24, 0xB8(r1)
	  stmw      r22, 0x90(r1)
	  mr        r31, r3
	  li        r26, 0
	  lhz       r27, 0x3D6(r3)
	  lfs       f28, -0x66F0(r2)
	  lfd       f29, -0x66E8(r2)
	  subi      r30, r27, 0x1
	  lfd       f30, -0x66E0(r2)
	  lfs       f31, -0x66D8(r2)

	.loc_0x50:
	  li        r25, 0
	  li        r28, 0
	  b         .loc_0x214

	.loc_0x5C:
	  lwz       r0, 0x3D0(r31)
	  addi      r23, r25, 0x1
	  rlwinm    r29,r23,4,0,27
	  add       r24, r0, r28
	  b         .loc_0x204

	.loc_0x70:
	  lwz       r0, 0x3D0(r31)
	  lfs       f3, 0x8(r24)
	  add       r22, r0, r29
	  lfs       f1, 0x0(r24)
	  lfs       f2, 0x8(r22)
	  lfs       f0, 0x0(r22)
	  fsubs     f25, f3, f2
	  lfs       f3, 0x4(r24)
	  fsubs     f27, f1, f0
	  lfs       f2, 0x4(r22)
	  fmuls     f0, f25, f25
	  fmuls     f1, f27, f27
	  fsubs     f26, f3, f2
	  fadds     f24, f1, f0
	  fcmpo     cr0, f24, f28
	  ble-      .loc_0x100
	  fsqrte    f1, f24
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f0, f1, f0
	  fmul      f0, f24, f0
	  frsp      f0, f0
	  stfs      f0, 0x54(r1)
	  lfs       f24, 0x54(r1)

	.loc_0x100:
	  fmuls     f1, f27, f27
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xD6BF0
	  fcmpu     cr0, f28, f1
	  beq-      .loc_0x12C
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x12C:
	  fcmpo     cr0, f24, f31
	  bge-      .loc_0x1FC
	  lfs       f1, -0x3868(r13)
	  li        r4, 0x1
	  lfs       f0, 0x0(r24)
	  fmuls     f3, f27, f1
	  fmuls     f2, f26, f1
	  fmuls     f1, f25, f1
	  fsubs     f0, f0, f3
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x4(r24)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x8(r24)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  lwz       r3, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r3, 0x0(r24)
	  stw       r0, 0x4(r24)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x8(r24)
	  lfs       f0, 0x0(r22)
	  fadds     f0, f0, f3
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x4(r22)
	  fadds     f0, f0, f2
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x8(r22)
	  fadds     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0x0(r22)
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x8(r22)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r24)
	  lfs       f2, 0x8(r24)
	  bl        -0x7C9F4
	  stfs      f1, 0x4(r24)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r22)
	  lfs       f2, 0x8(r22)
	  bl        -0x7CA0C
	  stfs      f1, 0x4(r22)

	.loc_0x1FC:
	  addi      r29, r29, 0x10
	  addi      r23, r23, 0x1

	.loc_0x204:
	  cmpw      r23, r27
	  blt+      .loc_0x70
	  addi      r28, r28, 0x10
	  addi      r25, r25, 0x1

	.loc_0x214:
	  cmpw      r25, r30
	  blt+      .loc_0x5C
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x4
	  blt+      .loc_0x50
	  lmw       r22, 0x90(r1)
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lfd       f27, 0xD0(r1)
	  lfd       f26, 0xC8(r1)
	  lfd       f25, 0xC0(r1)
	  lfd       f24, 0xB8(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4978
 * Size:	00025C
 */
void GrassGen::resolve()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stfd      f29, 0xE0(r1)
	  stfd      f28, 0xD8(r1)
	  stfd      f27, 0xD0(r1)
	  stfd      f26, 0xC8(r1)
	  stfd      f25, 0xC0(r1)
	  stfd      f24, 0xB8(r1)
	  stmw      r22, 0x90(r1)
	  mr        r31, r3
	  li        r26, 0
	  lhz       r27, 0x3D2(r3)
	  lfs       f28, -0x66F0(r2)
	  lfd       f29, -0x66E8(r2)
	  subi      r30, r27, 0x1
	  lfd       f30, -0x66E0(r2)
	  lfs       f31, -0x66D8(r2)

	.loc_0x50:
	  li        r25, 0
	  li        r28, 0
	  b         .loc_0x214

	.loc_0x5C:
	  lwz       r0, 0x3CC(r31)
	  addi      r23, r25, 0x1
	  rlwinm    r29,r23,4,0,27
	  add       r24, r0, r28
	  b         .loc_0x204

	.loc_0x70:
	  lwz       r0, 0x3CC(r31)
	  lfs       f3, 0x8(r24)
	  add       r22, r0, r29
	  lfs       f1, 0x0(r24)
	  lfs       f2, 0x8(r22)
	  lfs       f0, 0x0(r22)
	  fsubs     f25, f3, f2
	  lfs       f3, 0x4(r24)
	  fsubs     f27, f1, f0
	  lfs       f2, 0x4(r22)
	  fmuls     f0, f25, f25
	  fmuls     f1, f27, f27
	  fsubs     f26, f3, f2
	  fadds     f24, f1, f0
	  fcmpo     cr0, f24, f28
	  ble-      .loc_0x100
	  fsqrte    f1, f24
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f29, f1
	  fmul      f0, f24, f0
	  fsub      f0, f30, f0
	  fmul      f0, f1, f0
	  fmul      f0, f24, f0
	  frsp      f0, f0
	  stfs      f0, 0x54(r1)
	  lfs       f24, 0x54(r1)

	.loc_0x100:
	  fmuls     f1, f27, f27
	  fmuls     f0, f26, f26
	  fmuls     f2, f25, f25
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0xD6E4C
	  fcmpu     cr0, f28, f1
	  beq-      .loc_0x12C
	  fdivs     f27, f27, f1
	  fdivs     f26, f26, f1
	  fdivs     f25, f25, f1

	.loc_0x12C:
	  fcmpo     cr0, f24, f31
	  bge-      .loc_0x1FC
	  lfs       f1, -0x3864(r13)
	  li        r4, 0x1
	  lfs       f0, 0x0(r24)
	  fmuls     f3, f27, f1
	  fmuls     f2, f26, f1
	  fmuls     f1, f25, f1
	  fsubs     f0, f0, f3
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x64(r1)
	  lfs       f0, 0x4(r24)
	  fsubs     f0, f0, f2
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x8(r24)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  lwz       r3, 0x64(r1)
	  lwz       r0, 0x68(r1)
	  stw       r3, 0x0(r24)
	  stw       r0, 0x4(r24)
	  lwz       r0, 0x6C(r1)
	  stw       r0, 0x8(r24)
	  lfs       f0, 0x0(r22)
	  fadds     f0, f0, f3
	  stfs      f0, 0x38(r1)
	  lfs       f0, 0x38(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f0, 0x4(r22)
	  fadds     f0, f0, f2
	  stfs      f0, 0x5C(r1)
	  lfs       f0, 0x8(r22)
	  fadds     f0, f0, f1
	  stfs      f0, 0x60(r1)
	  lwz       r3, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0x0(r22)
	  stw       r0, 0x4(r22)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x8(r22)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r24)
	  lfs       f2, 0x8(r24)
	  bl        -0x7CC50
	  stfs      f1, 0x4(r24)
	  li        r4, 0x1
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r22)
	  lfs       f2, 0x8(r22)
	  bl        -0x7CC68
	  stfs      f1, 0x4(r22)

	.loc_0x1FC:
	  addi      r29, r29, 0x10
	  addi      r23, r23, 0x1

	.loc_0x204:
	  cmpw      r23, r27
	  blt+      .loc_0x70
	  addi      r28, r28, 0x10
	  addi      r25, r25, 0x1

	.loc_0x214:
	  cmpw      r25, r30
	  blt+      .loc_0x5C
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0x4
	  blt+      .loc_0x50
	  lmw       r22, 0x90(r1)
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lfd       f29, 0xE0(r1)
	  lfd       f28, 0xD8(r1)
	  lfd       f27, 0xD0(r1)
	  lfd       f26, 0xC8(r1)
	  lfd       f25, 0xC0(r1)
	  lfd       f24, 0xB8(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4BD4
 * Size:	0000A0
 */
RockGen::RockGen(Shape*, CreatureProp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x21
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  bl        0x10CB8
	  lis       r3, 0x802C
	  subi      r3, r3, 0x47F8
	  stw       r3, 0x0(r30)
	  addi      r3, r3, 0x114
	  li        r0, 0
	  stw       r3, 0x2B8(r30)
	  li        r3, 0x28
	  lfs       f0, -0x66F0(r2)
	  stfs      f0, 0x3E0(r30)
	  stfs      f0, 0x3DC(r30)
	  stfs      f0, 0x3D8(r30)
	  stw       r0, 0x3D0(r30)
	  sth       r0, 0x3D6(r30)
	  sth       r0, 0x3D4(r30)
	  bl        -0x9DC2C
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x70
	  bl        -0x40FE4

	.loc_0x70:
	  stw       r31, 0x2C(r30)
	  addi      r4, r30, 0
	  li        r5, 0x4
	  lwz       r3, 0x2C(r30)
	  bl        -0x40F20
	  mr        r3, r30
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
 * Address:	800E4C74
 * Size:	000284
 */
void RockGen::create(int, f32, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stfd      f31, 0xE8(r1)
	  stfd      f30, 0xE0(r1)
	  stfd      f29, 0xD8(r1)
	  stfd      f28, 0xD0(r1)
	  stfd      f27, 0xC8(r1)
	  fmr       f27, f1
	  stfd      f26, 0xC0(r1)
	  stfd      f25, 0xB8(r1)
	  stfd      f24, 0xB0(r1)
	  stfd      f23, 0xA8(r1)
	  stfd      f22, 0xA0(r1)
	  stfd      f21, 0x98(r1)
	  stmw      r26, 0x80(r1)
	  mr        r28, r4
	  rlwinm    r4,r4,4,0,27
	  addi      r27, r3, 0
	  addi      r3, r4, 0x8
	  bl        -0x9DCC0
	  lis       r4, 0x800E
	  addi      r4, r4, 0x4EF8
	  addi      r7, r28, 0
	  li        r5, 0
	  li        r6, 0x10
	  bl        0x12FF4C
	  stw       r3, 0x3D0(r27)
	  li        r29, 0
	  li        r30, 0
	  sth       r28, 0x3D4(r27)
	  lis       r31, 0x4330
	  sth       r28, 0x3D6(r27)
	  stfs      f27, 0x3E4(r27)
	  lfd       f28, -0x66B8(r2)
	  lfs       f29, -0x66D0(r2)
	  lfs       f30, -0x66D4(r2)
	  lfs       f31, -0x66CC(r2)
	  lfs       f24, -0x66C8(r2)
	  lfs       f25, -0x66C4(r2)
	  lfs       f26, -0x66C0(r2)
	  b         .loc_0x234

	.loc_0xA8:
	  bl        0x133354
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x7C(r1)
	  stw       r31, 0x78(r1)
	  lfd       f0, 0x78(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f23, f30, f0
	  bl        0x133334
	  xoris     r0, r3, 0x8000
	  fsubs     f0, f30, f23
	  stw       r0, 0x74(r1)
	  stw       r31, 0x70(r1)
	  lfd       f1, 0x70(r1)
	  fsubs     f1, f1, f28
	  fdivs     f1, f1, f29
	  fmuls     f1, f30, f1
	  fmuls     f0, f0, f1
	  fadds     f22, f23, f0
	  fmuls     f22, f22, f27
	  bl        0x133304
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x6C(r1)
	  stw       r31, 0x68(r1)
	  lfd       f0, 0x68(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f21, f31, f0
	  fmr       f1, f21
	  bl        0x136DC0
	  fmuls     f23, f22, f1
	  fmr       f1, f21
	  bl        0x136F48
	  fmuls     f1, f22, f1
	  lfs       f0, -0x3860(r13)
	  li        r4, 0x1
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  stfs      f23, 0x40(r1)
	  lfs       f1, 0x38(r1)
	  lfs       f0, 0x94(r27)
	  lfs       f3, 0x3C(r1)
	  lfs       f2, 0x98(r27)
	  fadds     f0, f1, f0
	  lfs       f4, 0x40(r1)
	  lfs       f1, 0x9C(r27)
	  fadds     f2, f3, f2
	  stfs      f0, 0x38(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x38(r1)
	  lfs       f2, 0x40(r1)
	  bl        -0x7CEF4
	  stfs      f1, 0x3C(r1)
	  lwz       r4, 0x3D0(r27)
	  lwz       r3, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  add       r26, r4, r30
	  stw       r3, 0x0(r26)
	  stw       r0, 0x4(r26)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0x8(r26)
	  bl        0x133250
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x64(r1)
	  stw       r31, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f0, f25, f0
	  fmuls     f0, f24, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stb       r0, 0xC(r26)
	  bl        0x133218
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x54(r1)
	  addi      r30, r30, 0x10
	  addi      r29, r29, 0x1
	  stw       r31, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f0, f26, f0
	  fmuls     f0, f24, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r0, 0x4C(r1)
	  stb       r0, 0xD(r26)
	  lbz       r0, 0xD(r26)
	  rlwinm    r3,r0,1,0,30
	  addi      r0, r3, 0x2
	  stb       r0, 0xE(r26)

	.loc_0x234:
	  cmpw      r29, r28
	  blt+      .loc_0xA8
	  mr        r3, r27
	  bl        -0x798
	  lmw       r26, 0x80(r1)
	  lwz       r0, 0xF4(r1)
	  lfd       f31, 0xE8(r1)
	  lfd       f30, 0xE0(r1)
	  lfd       f29, 0xD8(r1)
	  lfd       f28, 0xD0(r1)
	  lfd       f27, 0xC8(r1)
	  lfd       f26, 0xC0(r1)
	  lfd       f25, 0xB8(r1)
	  lfd       f24, 0xB0(r1)
	  lfd       f23, 0xA8(r1)
	  lfd       f22, 0xA0(r1)
	  lfd       f21, 0x98(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4EF8
 * Size:	000014
 */
Pebble::Pebble()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x66F0(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4F0C
 * Size:	000010
 */
void RockGen::setSizeAndNum(f32, int)
{
	/*
	.loc_0x0:
	  sth       r4, 0x3D4(r3)
	  sth       r4, 0x3D6(r3)
	  stfs      f1, 0x3E4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4F1C
 * Size:	00005C
 */
void RockGen::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x3C8(r3)
	  lhz       r4, 0x3D6(r31)
	  lfs       f1, 0x3E4(r31)
	  bl        -0x2D0
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  bl        -0x50A30
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  li        r5, 0
	  bl        -0x509A4
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4F78
 * Size:	000010
 */
void RockGen::killPebble()
{
	/*
	.loc_0x0:
	  lhz       r4, 0x3D4(r3)
	  subi      r0, r4, 0x1
	  sth       r0, 0x3D4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E4F88
 * Size:	00003C
 */
void RockGen::doSave(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0
	  stw       r0, 0x4(r1)
	  addi      r3, r4, 0
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x4(r4)
	  lhz       r0, 0x3D4(r5)
	  lwz       r12, 0x28(r12)
	  rlwinm    r4,r0,0,24,31
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
 * Address:	800E4FC4
 * Size:	000080
 */
void RockGen::doLoad(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r3, r4, 0
	  lwz       r12, 0x4(r4)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r0,r3,0,24,31
	  sth       r0, 0x3D4(r31)
	  li        r6, 0
	  li        r5, 0
	  b         .loc_0x58

	.loc_0x3C:
	  subi      r0, r3, 0x1
	  lwz       r4, 0x3D0(r31)
	  sub       r0, r0, r6
	  rlwinm    r3,r0,4,0,27
	  addi      r0, r3, 0xE
	  stbx      r5, r4, r0
	  addi      r6, r6, 0x1

	.loc_0x58:
	  lhz       r4, 0x3D4(r31)
	  lhz       r3, 0x3D6(r31)
	  sub       r0, r3, r4
	  cmpw      r6, r0
	  blt+      .loc_0x3C
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5044
 * Size:	00002C
 */
void RockGen::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C
	  bl        -0x41170

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5070
 * Size:	000190
 */
void RockGen::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stfd      f31, 0xF8(r1)
	  stfd      f30, 0xF0(r1)
	  stfd      f29, 0xE8(r1)
	  stfd      f28, 0xE0(r1)
	  stmw      r24, 0xC0(r1)
	  mr        r29, r3
	  mr        r30, r4
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x66B0(r2)
	  addi      r4, r29, 0x94
	  lwz       r3, 0x2E4(r30)
	  fmuls     f1, f0, f1
	  bl        -0xA3B34
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x16C
	  lfs       f28, -0x66AC(r2)
	  addi      r27, r1, 0x1C
	  lfs       f29, -0x66A8(r2)
	  addi      r26, r1, 0x28
	  lfd       f30, -0x66A0(r2)
	  lfs       f31, -0x66C4(r2)
	  li        r31, 0
	  li        r25, 0
	  lis       r28, 0x4330
	  b         .loc_0x160

	.loc_0x7C:
	  lwz       r0, 0x3D0(r29)
	  add       r3, r0, r25
	  lbz       r0, 0xE(r3)
	  addi      r24, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  lbz       r0, 0xC(r24)
	  mr        r4, r26
	  lfs       f3, -0x3850(r13)
	  mr        r5, r27
	  stw       r0, 0xBC(r1)
	  lfs       f0, -0x385C(r13)
	  mr        r6, r24
	  stw       r28, 0xB8(r1)
	  addi      r3, r1, 0x74
	  lfs       f1, -0x3858(r13)
	  lfd       f2, 0xB8(r1)
	  stfs      f0, 0x28(r1)
	  fsubs     f4, f2, f30
	  lfs       f2, -0x384C(r13)
	  stfs      f3, 0x1C(r1)
	  lfs       f0, -0x3854(r13)
	  fdivs     f3, f4, f31
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  fmuls     f0, f29, f3
	  fmuls     f0, f28, f0
	  stfs      f0, 0x20(r1)
	  stfs      f2, 0x24(r1)
	  bl        -0xA706C
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x74
	  addi      r5, r1, 0x34
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stw       r0, 0x324(r30)
	  addi      r3, r30, 0
	  addi      r4, r1, 0x34
	  lwz       r12, 0x3B4(r30)
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0xD(r24)
	  mr        r4, r30
	  lwz       r7, 0x30AC(r13)
	  li        r6, 0
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x4C
	  lwz       r5, 0x2E4(r30)
	  lwzx      r3, r7, r0
	  bl        -0xB4D58

	.loc_0x158:
	  addi      r25, r25, 0x10
	  addi      r31, r31, 0x1

	.loc_0x160:
	  lhz       r0, 0x3D6(r29)
	  cmpw      r31, r0
	  blt+      .loc_0x7C

	.loc_0x16C:
	  lmw       r24, 0xC0(r1)
	  lwz       r0, 0x104(r1)
	  lfd       f31, 0xF8(r1)
	  lfd       f30, 0xF0(r1)
	  lfd       f29, 0xE8(r1)
	  lfd       f28, 0xE0(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5200
 * Size:	000008
 */
void RockGen::getSize()
{
	/*
	.loc_0x0:
	  lfs       f1, 0x3E4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5208
 * Size:	0000E0
 */
void RockGen::getRandomPebble()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lhz       r0, 0x3D4(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0xCC

	.loc_0x28:
	  bl        0x132E40
	  xoris     r0, r3, 0x8000
	  lhz       r4, 0x3D6(r31)
	  stw       r0, 0x24(r1)
	  lis       r3, 0x4330
	  lhz       r0, 0x3D4(r31)
	  cmpwi     r4, 0
	  stw       r3, 0x20(r1)
	  mtctr     r4
	  lfd       f1, -0x66B8(r2)
	  lfd       f0, 0x20(r1)
	  li        r4, 0
	  stw       r0, 0x1C(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x66D0(r2)
	  stw       r3, 0x18(r1)
	  lfs       f3, -0x66D4(r2)
	  fdivs     f4, f1, f0
	  lfd       f1, -0x66A0(r2)
	  lfd       f0, 0x18(r1)
	  lfs       f2, -0x66C8(r2)
	  fmuls     f3, f3, f4
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f3
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x10(r1)
	  lwz       r5, 0x14(r1)
	  ble-      .loc_0xC8

	.loc_0x9C:
	  lwz       r0, 0x3D0(r31)
	  add       r3, r0, r4
	  lbz       r0, 0xE(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xC0
	  cmpwi     r5, 0
	  bgt-      .loc_0xBC
	  b         .loc_0xCC

	.loc_0xBC:
	  subi      r5, r5, 0x1

	.loc_0xC0:
	  addi      r4, r4, 0x10
	  bdnz+     .loc_0x9C

	.loc_0xC8:
	  li        r3, 0

	.loc_0xCC:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E52E8
 * Size:	0000A0
 */
GrassGen::GrassGen(Shape*, CreatureProp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x22
	  stw       r0, 0x4(r1)
	  li        r6, 0
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  bl        0x105A4
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4988
	  stw       r3, 0x0(r30)
	  addi      r3, r3, 0x114
	  li        r0, 0
	  stw       r3, 0x2B8(r30)
	  li        r3, 0x28
	  lfs       f0, -0x66F0(r2)
	  stfs      f0, 0x3DC(r30)
	  stfs      f0, 0x3D8(r30)
	  stfs      f0, 0x3D4(r30)
	  stw       r0, 0x3CC(r30)
	  sth       r0, 0x3D2(r30)
	  sth       r0, 0x3D0(r30)
	  bl        -0x9E340
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x70
	  bl        -0x416F8

	.loc_0x70:
	  stw       r31, 0x2C(r30)
	  addi      r4, r30, 0
	  li        r5, 0x4
	  lwz       r3, 0x2C(r30)
	  bl        -0x41634
	  mr        r3, r30
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
 * Address:	800E5388
 * Size:	000244
 */
void GrassGen::create(int, f32, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stfd      f30, 0xC0(r1)
	  stfd      f29, 0xB8(r1)
	  stfd      f28, 0xB0(r1)
	  stfd      f27, 0xA8(r1)
	  fmr       f27, f1
	  stfd      f26, 0xA0(r1)
	  stfd      f25, 0x98(r1)
	  stfd      f24, 0x90(r1)
	  stfd      f23, 0x88(r1)
	  stfd      f22, 0x80(r1)
	  stmw      r26, 0x68(r1)
	  mr        r31, r4
	  rlwinm    r4,r4,4,0,27
	  addi      r30, r3, 0
	  addi      r29, r31, 0
	  addi      r3, r4, 0x8
	  bl        -0x9E3D4
	  lis       r4, 0x800E
	  addi      r4, r4, 0x55CC
	  addi      r7, r29, 0
	  li        r5, 0
	  li        r6, 0x10
	  bl        0x12F838
	  stw       r3, 0x3CC(r30)
	  li        r27, 0
	  li        r28, 0
	  sth       r31, 0x3D0(r30)
	  lis       r29, 0x4330
	  sth       r31, 0x3D2(r30)
	  stfs      f27, 0x3E0(r30)
	  lfd       f28, -0x66B8(r2)
	  lfs       f29, -0x66D0(r2)
	  lfs       f30, -0x66D4(r2)
	  lfs       f31, -0x66CC(r2)
	  lfs       f25, -0x66C8(r2)
	  lfs       f26, -0x66C4(r2)
	  b         .loc_0x1F8

	.loc_0xA4:
	  bl        0x132C44
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x64(r1)
	  stw       r29, 0x60(r1)
	  lfd       f0, 0x60(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f24, f30, f0
	  bl        0x132C24
	  xoris     r0, r3, 0x8000
	  fsubs     f0, f30, f24
	  stw       r0, 0x5C(r1)
	  stw       r29, 0x58(r1)
	  lfd       f1, 0x58(r1)
	  fsubs     f1, f1, f28
	  fdivs     f1, f1, f29
	  fmuls     f1, f30, f1
	  fmuls     f0, f0, f1
	  fadds     f23, f24, f0
	  fmuls     f23, f23, f27
	  bl        0x132BF4
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x54(r1)
	  stw       r29, 0x50(r1)
	  lfd       f0, 0x50(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f22, f31, f0
	  fmr       f1, f22
	  bl        0x1366B0
	  fmuls     f24, f23, f1
	  fmr       f1, f22
	  bl        0x136838
	  fmuls     f1, f23, f1
	  lfs       f0, -0x3848(r13)
	  li        r4, 0x1
	  stfs      f1, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f24, 0x3C(r1)
	  lfs       f1, 0x34(r1)
	  lfs       f0, 0x94(r30)
	  lfs       f3, 0x38(r1)
	  lfs       f2, 0x98(r30)
	  fadds     f0, f1, f0
	  lfs       f4, 0x3C(r1)
	  lfs       f1, 0x9C(r30)
	  fadds     f2, f3, f2
	  stfs      f0, 0x34(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x38(r1)
	  stfs      f0, 0x3C(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x34(r1)
	  lfs       f2, 0x3C(r1)
	  bl        -0x7D604
	  stfs      f1, 0x38(r1)
	  lwz       r4, 0x3CC(r30)
	  lwz       r3, 0x34(r1)
	  lwz       r0, 0x38(r1)
	  add       r26, r4, r28
	  stw       r3, 0x0(r26)
	  stw       r0, 0x4(r26)
	  lwz       r0, 0x3C(r1)
	  stw       r0, 0x8(r26)
	  bl        0x132B40
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x4C(r1)
	  li        r3, 0
	  li        r0, 0x1
	  stw       r29, 0x48(r1)
	  addi      r28, r28, 0x10
	  addi      r27, r27, 0x1
	  lfd       f0, 0x48(r1)
	  fsubs     f0, f0, f28
	  fdivs     f0, f0, f29
	  fmuls     f0, f30, f0
	  fmuls     f0, f26, f0
	  fmuls     f0, f25, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x40(r1)
	  lwz       r4, 0x44(r1)
	  stb       r4, 0xE(r26)
	  stb       r3, 0xD(r26)
	  stb       r0, 0xC(r26)

	.loc_0x1F8:
	  cmpw      r27, r31
	  blt+      .loc_0xA4
	  mr        r3, r30
	  bl        -0xC14
	  lmw       r26, 0x68(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lfd       f30, 0xC0(r1)
	  lfd       f29, 0xB8(r1)
	  lfd       f28, 0xB0(r1)
	  lfd       f27, 0xA8(r1)
	  lfd       f26, 0xA0(r1)
	  lfd       f25, 0x98(r1)
	  lfd       f24, 0x90(r1)
	  lfd       f23, 0x88(r1)
	  lfd       f22, 0x80(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E55CC
 * Size:	000014
 */
Grass::Grass()
{
	/*
	.loc_0x0:
	  lfs       f0, -0x66F0(r2)
	  stfs      f0, 0x8(r3)
	  stfs      f0, 0x4(r3)
	  stfs      f0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E55E0
 * Size:	000010
 */
void GrassGen::setSizeAndNum(f32, int)
{
	/*
	.loc_0x0:
	  sth       r4, 0x3D0(r3)
	  sth       r4, 0x3D2(r3)
	  stfs      f1, 0x3E0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E55F0
 * Size:	00005C
 */
void GrassGen::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r3, 0
	  stw       r0, 0x3C8(r3)
	  lhz       r4, 0x3D2(r31)
	  lfs       f1, 0x3E0(r31)
	  bl        -0x290
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  bl        -0x51104
	  addi      r3, r31, 0x40
	  addi      r4, r31, 0x94
	  li        r5, 0
	  bl        -0x51078
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E564C
 * Size:	00002C
 */
void GrassGen::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x1C
	  bl        -0x41778

	.loc_0x1C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5678
 * Size:	000190
 */
void GrassGen::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stfd      f31, 0xF8(r1)
	  stfd      f30, 0xF0(r1)
	  stfd      f29, 0xE8(r1)
	  stfd      f28, 0xE0(r1)
	  stmw      r24, 0xC0(r1)
	  mr        r29, r3
	  mr        r30, r4
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x66B0(r2)
	  addi      r4, r29, 0x94
	  lwz       r3, 0x2E4(r30)
	  fmuls     f1, f0, f1
	  bl        -0xA413C
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x16C
	  lfs       f28, -0x66AC(r2)
	  addi      r27, r1, 0x1C
	  lfs       f29, -0x66A8(r2)
	  addi      r26, r1, 0x28
	  lfd       f30, -0x66A0(r2)
	  lfs       f31, -0x66C4(r2)
	  li        r31, 0
	  li        r25, 0
	  lis       r28, 0x4330
	  b         .loc_0x160

	.loc_0x7C:
	  lwz       r0, 0x3CC(r29)
	  add       r3, r0, r25
	  lbz       r0, 0xC(r3)
	  addi      r24, r3, 0
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  lbz       r0, 0xE(r24)
	  mr        r4, r26
	  lfs       f3, -0x3838(r13)
	  mr        r5, r27
	  stw       r0, 0xBC(r1)
	  lfs       f0, -0x3844(r13)
	  mr        r6, r24
	  stw       r28, 0xB8(r1)
	  addi      r3, r1, 0x74
	  lfs       f1, -0x3840(r13)
	  lfd       f2, 0xB8(r1)
	  stfs      f0, 0x28(r1)
	  fsubs     f4, f2, f30
	  lfs       f2, -0x3834(r13)
	  stfs      f3, 0x1C(r1)
	  lfs       f0, -0x383C(r13)
	  fdivs     f3, f4, f31
	  stfs      f1, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  fmuls     f0, f29, f3
	  fmuls     f0, f28, f0
	  stfs      f0, 0x20(r1)
	  stfs      f2, 0x24(r1)
	  bl        -0xA7674
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r1, 0x74
	  addi      r5, r1, 0x34
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stw       r0, 0x324(r30)
	  addi      r3, r30, 0
	  addi      r4, r1, 0x34
	  lwz       r12, 0x3B4(r30)
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lbz       r0, 0xD(r24)
	  mr        r4, r30
	  lwz       r7, 0x30AC(r13)
	  li        r6, 0
	  rlwinm    r3,r0,2,0,29
	  addi      r0, r3, 0x58
	  lwz       r5, 0x2E4(r30)
	  lwzx      r3, r7, r0
	  bl        -0xB5360

	.loc_0x158:
	  addi      r25, r25, 0x10
	  addi      r31, r31, 0x1

	.loc_0x160:
	  lhz       r0, 0x3D2(r29)
	  cmpw      r31, r0
	  blt+      .loc_0x7C

	.loc_0x16C:
	  lmw       r24, 0xC0(r1)
	  lwz       r0, 0x104(r1)
	  lfd       f31, 0xF8(r1)
	  lfd       f30, 0xF0(r1)
	  lfd       f29, 0xE8(r1)
	  lfd       f28, 0xE0(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5808
 * Size:	000008
 */
void GrassGen::getSize()
{
	/*
	.loc_0x0:
	  lfs       f1, 0x3E0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5810
 * Size:	0000E0
 */
void GrassGen::getRandomGrass()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  mr        r31, r3
	  lhz       r0, 0x3D0(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x28
	  li        r3, 0
	  b         .loc_0xCC

	.loc_0x28:
	  bl        0x132838
	  xoris     r0, r3, 0x8000
	  lhz       r4, 0x3D2(r31)
	  stw       r0, 0x24(r1)
	  lis       r3, 0x4330
	  lhz       r0, 0x3D0(r31)
	  cmpwi     r4, 0
	  stw       r3, 0x20(r1)
	  mtctr     r4
	  lfd       f1, -0x66B8(r2)
	  lfd       f0, 0x20(r1)
	  li        r4, 0
	  stw       r0, 0x1C(r1)
	  fsubs     f1, f0, f1
	  lfs       f0, -0x66D0(r2)
	  stw       r3, 0x18(r1)
	  lfs       f3, -0x66D4(r2)
	  fdivs     f4, f1, f0
	  lfd       f1, -0x66A0(r2)
	  lfd       f0, 0x18(r1)
	  lfs       f2, -0x66C8(r2)
	  fmuls     f3, f3, f4
	  fsubs     f0, f0, f1
	  fmuls     f0, f0, f3
	  fmuls     f0, f2, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x10(r1)
	  lwz       r5, 0x14(r1)
	  ble-      .loc_0xC8

	.loc_0x9C:
	  lwz       r0, 0x3CC(r31)
	  add       r3, r0, r4
	  lbz       r0, 0xC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xC0
	  cmpwi     r5, 0
	  bgt-      .loc_0xBC
	  b         .loc_0xCC

	.loc_0xBC:
	  subi      r5, r5, 0x1

	.loc_0xC0:
	  addi      r4, r4, 0x10
	  bdnz+     .loc_0x9C

	.loc_0xC8:
	  li        r3, 0

	.loc_0xCC:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
WeedsGen::WeedsGen(Shape*, CreatureProp*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E58F0
 * Size:	000004
 */
void WeedsGen::update() { }

/*
 * --INFO--
 * Address:	800E58F4
 * Size:	000004
 */
void WeedsGen::refresh(Graphics&) { }

/*
 * --INFO--
 * Address:	800E58F8
 * Size:	0001CC
 */
void WeedsGen::startAI(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stfd      f29, 0x70(r1)
	  stfd      f28, 0x68(r1)
	  stfd      f27, 0x60(r1)
	  stfd      f26, 0x58(r1)
	  stfd      f25, 0x50(r1)
	  stfd      f24, 0x48(r1)
	  stw       r31, 0x44(r1)
	  lis       r31, 0x4330
	  stw       r30, 0x40(r1)
	  li        r30, 0
	  stw       r29, 0x3C(r1)
	  stw       r28, 0x38(r1)
	  mr        r28, r3
	  lfd       f31, -0x66B8(r2)
	  lfs       f27, -0x66D0(r2)
	  lfs       f28, -0x66D4(r2)
	  lfs       f29, -0x6698(r2)
	  lfs       f30, -0x66CC(r2)
	  b         .loc_0x180

	.loc_0x60:
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x20
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r29, r3
	  beq-      .loc_0x17C
	  bl        0x1326F8
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x34(r1)
	  stw       r31, 0x30(r1)
	  lfd       f0, 0x30(r1)
	  fsubs     f0, f0, f31
	  fdivs     f0, f0, f27
	  fmuls     f0, f28, f0
	  fmuls     f25, f29, f0
	  bl        0x1326D4
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x2C(r1)
	  stw       r31, 0x28(r1)
	  lfd       f0, 0x28(r1)
	  fsubs     f0, f0, f31
	  fdivs     f0, f0, f27
	  fmuls     f0, f28, f0
	  fmuls     f24, f30, f0
	  fmr       f1, f24
	  bl        0x136190
	  fmuls     f26, f25, f1
	  fmr       f1, f24
	  bl        0x136318
	  fmuls     f1, f25, f1
	  lfs       f0, -0x3830(r13)
	  li        r4, 0x1
	  stfs      f1, 0x1C(r1)
	  stfs      f0, 0x20(r1)
	  stfs      f26, 0x24(r1)
	  lfs       f1, 0x1C(r1)
	  lfs       f0, 0x94(r28)
	  lfs       f3, 0x20(r1)
	  lfs       f2, 0x98(r28)
	  fadds     f0, f1, f0
	  lfs       f4, 0x24(r1)
	  lfs       f1, 0x9C(r28)
	  fadds     f2, f3, f2
	  stfs      f0, 0x1C(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x1C(r1)
	  lfs       f2, 0x24(r1)
	  bl        -0x7DB24
	  stfs      f1, 0x20(r1)
	  addi      r3, r29, 0
	  addi      r4, r1, 0x1C
	  lwz       r0, 0x3D0(r28)
	  stw       r0, 0x224(r29)
	  stw       r28, 0x3CC(r29)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x3CC(r28)
	  addi      r3, r29, 0
	  li        r4, 0
	  stw       r0, 0x308(r29)
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x17C:
	  addi      r30, r30, 0x1

	.loc_0x180:
	  lwz       r0, 0x3C8(r28)
	  cmpw      r30, r0
	  blt+      .loc_0x60
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lfd       f29, 0x70(r1)
	  lfd       f28, 0x68(r1)
	  lfd       f27, 0x60(r1)
	  lfd       f26, 0x58(r1)
	  lfd       f25, 0x50(r1)
	  lfd       f24, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  lwz       r29, 0x3C(r1)
	  lwz       r28, 0x38(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
Weed::Weed()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E5AC4
 * Size:	000024
 */
void Weed::startAI(int)
{
	/*
	.loc_0x0:
	  lfs       f0, -0x382C(r13)
	  li        r0, 0
	  stfs      f0, 0x7C(r3)
	  lfs       f0, -0x3828(r13)
	  stfs      f0, 0x80(r3)
	  lfs       f0, -0x3824(r13)
	  stfs      f0, 0x84(r3)
	  sth       r0, 0x3C8(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5AE8
 * Size:	0000CC
 */
void Weed::interactPullout(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stfd      f31, 0x38(r1)
	  stfd      f30, 0x30(r1)
	  stfd      f29, 0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lhz       r0, 0x3C8(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0xA8
	  li        r0, 0x1
	  sth       r0, 0x3C8(r31)
	  li        r0, 0
	  sth       r0, 0x3CA(r31)
	  lfs       f29, 0xA0(r4)
	  fmr       f1, f29
	  bl        0x136028
	  lfs       f0, -0x6694(r2)
	  fneg      f30, f0
	  fmuls     f31, f30, f1
	  fmr       f1, f29
	  bl        0x1361A8
	  fmuls     f1, f30, f1
	  lfs       f0, -0x3820(r13)
	  li        r3, 0x1
	  stfs      f1, 0x10(r1)
	  stfs      f0, 0x14(r1)
	  stfs      f31, 0x18(r1)
	  lwz       r4, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r4, 0x70(r31)
	  stw       r0, 0x74(r31)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0x78(r31)
	  lwz       r4, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r4, 0xA4(r31)
	  stw       r0, 0xA8(r31)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0xAC(r31)
	  b         .loc_0xAC

	.loc_0xA8:
	  li        r3, 0

	.loc_0xAC:
	  lwz       r0, 0x44(r1)
	  lfd       f31, 0x38(r1)
	  lfd       f30, 0x30(r1)
	  lfd       f29, 0x28(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5BB4
 * Size:	00009C
 */
void Weed::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r3
	  bl        0x1002C
	  lhz       r0, 0x3C8(r31)
	  cmplwi    r0, 0x1
	  bne-      .loc_0x88
	  lhz       r3, 0x3CA(r31)
	  addi      r0, r3, 0x1
	  sth       r0, 0x3CA(r31)
	  lhz       r0, 0x3CA(r31)
	  cmplwi    r0, 0x1E
	  ble-      .loc_0x4C
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x5AF18
	  b         .loc_0x88

	.loc_0x4C:
	  stw       r0, 0x14(r1)
	  lis       r0, 0x4330
	  lfd       f2, -0x66A0(r2)
	  stw       r0, 0x10(r1)
	  lfs       f1, -0x66D8(r2)
	  lfd       f0, 0x10(r1)
	  lfs       f3, -0x66D4(r2)
	  fsubs     f2, f0, f2
	  lfs       f0, -0x6690(r2)
	  fdivs     f1, f2, f1
	  fsubs     f1, f3, f1
	  fmuls     f1, f1, f0
	  stfs      f1, 0x7C(r31)
	  stfs      f1, 0x80(r31)
	  stfs      f1, 0x84(r31)

	.loc_0x88:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5C50
 * Size:	000108
 */
void Weed::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x50(r1)
	  addi      r30, r3, 0
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xA7B88
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x10
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  li        r0, 0x1
	  stw       r0, 0x324(r31)
	  addi      r3, r31, 0
	  addi      r4, r1, 0x10
	  lwz       r12, 0x3B4(r31)
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r30, 0x94
	  lwz       r4, 0x2E4(r31)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xAC
	  lwz       r3, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x160(r4)

	.loc_0xAC:
	  lwz       r3, 0x308(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0xB58A0
	  lwz       r4, 0x2E4(r31)
	  li        r0, 0
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xF0
	  lwz       r3, 0x0(r0)
	  lwz       r0, 0x4(r0)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x8(r0)
	  stw       r0, 0x160(r4)

	.loc_0xF0:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5D58
 * Size:	000014
 */
void Weed::isVisible()
{
	/*
	.loc_0x0:
	  lhz       r0, 0x3C8(r3)
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5D6C
 * Size:	000008
 */
u32 Weed::isAlive() { return 0x1; }

/*
 * --INFO--
 * Address:	800E5D74
 * Size:	000014
 */
void Weed::isAtari()
{
	/*
	.loc_0x0:
	  lhz       r0, 0x3C8(r3)
	  neg       r0, r0
	  cntlzw    r0, r0
	  rlwinm    r3,r0,27,5,31
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5D88
 * Size:	000008
 */
u32 Weed::needFlick(Creature*) { return 0x0; }

/*
 * --INFO--
 * Address:	800E5D90
 * Size:	000014
 */
void GrassGen::isAlive()
{
	/*
	.loc_0x0:
	  lhz       r0, 0x3D0(r3)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5DA4
 * Size:	000008
 */
u32 GrassGen::isVisible() { return 0x1; }

/*
 * --INFO--
 * Address:	800E5DAC
 * Size:	000008
 */
u32 GrassGen::needFlick(Creature*) { return 0x0; }

/*
 * --INFO--
 * Address:	800E5DB4
 * Size:	000014
 */
void RockGen::isAlive()
{
	/*
	.loc_0x0:
	  lhz       r0, 0x3D4(r3)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r3, r0, r3
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E5DC8
 * Size:	000008
 */
u32 RockGen::isVisible() { return 0x1; }

/*
 * --INFO--
 * Address:	800E5DD0
 * Size:	000008
 */
u32 RockGen::needFlick(Creature*) { return 0x0; }
