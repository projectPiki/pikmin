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
 * Size:	0000F4
 */
void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800946A4
 * Size:	000058
 */
RopeCreature::RopeCreature(CreatureProp*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        -0x97E0
	  lis       r3, 0x802B
	  subi      r0, r3, 0x524
	  stw       r0, 0x0(r31)
	  li        r0, 0
	  addi      r3, r31, 0
	  lfs       f0, -0x7418(r2)
	  stfs      f0, 0x2CC(r31)
	  stfs      f0, 0x2C8(r31)
	  stfs      f0, 0x2C4(r31)
	  stw       r0, 0x2B8(r31)
	  stw       r0, 0x2BC(r31)
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800946FC
 * Size:	0001A8
 */
void RopeCreature::setRope(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x68(r1)
	  addi      r30, r3, 0
	  addi      r4, r30, 0
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x34
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x40
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, 0x40(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f1, 0x44(r1)
	  fsubs     f2, f2, f0
	  lfs       f0, 0x38(r1)
	  lfs       f4, 0x48(r1)
	  lfs       f3, 0x3C(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x58(r1)
	  fsubs     f1, f4, f3
	  stfs      f0, 0x5C(r1)
	  stfs      f1, 0x60(r1)
	  lwz       r3, 0x58(r1)
	  lwz       r0, 0x5C(r1)
	  stw       r3, 0x2C4(r30)
	  stw       r0, 0x2C8(r30)
	  lwz       r0, 0x60(r1)
	  stw       r0, 0x2CC(r30)
	  lfs       f1, 0x2C4(r30)
	  lfs       f0, 0x2C8(r30)
	  lfs       f2, 0x2CC(r30)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x86B70
	  lfs       f0, -0x7418(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xE8
	  lfs       f0, 0x2C4(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x2C4(r30)
	  lfs       f0, 0x2C8(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x2C8(r30)
	  lfs       f0, 0x2CC(r30)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x2CC(r30)

	.loc_0xE8:
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x5C(r1)
	  fmuls     f2, f1, f1
	  lfs       f3, 0x60(r1)
	  fmuls     f1, f0, f0
	  lfs       f0, -0x7418(r2)
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x16C
	  fsqrte    f1, f4
	  lfd       f3, -0x7410(r2)
	  lfd       f2, -0x7408(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f4, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f4, f0
	  frsp      f0, f0
	  stfs      f0, 0x20(r1)
	  lfs       f4, 0x20(r1)

	.loc_0x16C:
	  stfs      f4, 0x2C0(r30)
	  stw       r31, 0x2B8(r30)
	  lwz       r3, 0x2B8(r30)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x12
	  bne-      .loc_0x188
	  stw       r30, 0x2BC(r3)

	.loc_0x188:
	  lfs       f0, -0x7400(r2)
	  stfs      f0, 0x2C0(r30)
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800948A4
 * Size:	0000D4
 */
void RopeCreature::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  bl        -0x96B0
	  lwz       r3, 0x2B8(r31)
	  lfs       f0, 0x94(r31)
	  lfsu      f1, 0x94(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x24(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x98(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x34(r1)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x9C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x38(r1)
	  lwz       r3, 0x30(r1)
	  lwz       r0, 0x34(r1)
	  stw       r3, 0x2C4(r31)
	  stw       r0, 0x2C8(r31)
	  lwz       r0, 0x38(r1)
	  stw       r0, 0x2CC(r31)
	  lfs       f1, 0x2C4(r31)
	  lfs       f0, 0x2C8(r31)
	  lfs       f2, 0x2CC(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x86CF0
	  lfs       f0, -0x7418(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xC0
	  lfs       f0, 0x2C4(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x2C4(r31)
	  lfs       f0, 0x2C8(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x2C8(r31)
	  lfs       f0, 0x2CC(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x2CC(r31)

	.loc_0xC0:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80094978
 * Size:	0000B4
 */
void RopeCreature::getRopePos(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  addi      r0, r1, 0x1C
	  addi      r6, r1, 0x24
	  stfd      f30, 0x58(r1)
	  addi      r5, r1, 0x20
	  stfd      f29, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  mr        r31, r3
	  addi      r3, r1, 0x2C
	  lfs       f2, 0x2C0(r4)
	  lfs       f0, 0x2CC(r4)
	  fmuls     f1, f2, f1
	  lfs       f31, 0x94(r4)
	  lfs       f30, 0x98(r4)
	  lfs       f29, 0x9C(r4)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x2C8(r4)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x20(r1)
	  lfs       f0, 0x2C4(r4)
	  mr        r4, r0
	  fmuls     f0, f0, f1
	  stfs      f0, 0x1C(r1)
	  bl        -0x5D8C8
	  lfs       f0, 0x2C(r1)
	  lfs       f1, 0x30(r1)
	  fadds     f0, f31, f0
	  lfs       f2, 0x34(r1)
	  fadds     f3, f30, f1
	  fadds     f1, f29, f2
	  stfs      f0, 0x0(r31)
	  stfs      f3, 0x4(r31)
	  stfs      f1, 0x8(r31)
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  lfd       f29, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80094A2C
 * Size:	000004
 */
void RopeCreature::refresh(Graphics&) { }

/*
 * --INFO--
 * Address:	80094A30
 * Size:	000008
 */
u32 RopeCreature::needShadow() { return 0x0; }
