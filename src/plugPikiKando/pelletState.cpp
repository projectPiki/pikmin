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
 * Address:	8009A02C
 * Size:	000400
 */
void PelletStateMachine::init(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0x6
	  stwu      r1, -0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r3, 0
	  stw       r30, 0x68(r1)
	  stw       r0, 0xC(r3)
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x53058
	  stw       r3, 0x4(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x53068
	  stw       r3, 0x10(r31)
	  lwz       r0, 0xC(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        -0x53078
	  stw       r3, 0x14(r31)
	  li        r3, 0x10
	  bl        -0x53084
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x70
	  bl        0x500

	.loc_0x70:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0xF0
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0xA4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0xAC

	.loc_0xA4:
	  li        r0, 0
	  b         .loc_0xB0

	.loc_0xAC:
	  li        r0, 0x1

	.loc_0xB0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0xF0
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0xF0:
	  li        r3, 0x18
	  bl        -0x5311C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x108
	  bl        0x570

	.loc_0x108:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x188
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x13C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x144

	.loc_0x13C:
	  li        r0, 0
	  b         .loc_0x148

	.loc_0x144:
	  li        r0, 0x1

	.loc_0x148:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x188
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x188:
	  li        r3, 0x10
	  bl        -0x531B4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x1A0
	  bl        0x424

	.loc_0x1A0:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x220
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x1D4
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x1DC

	.loc_0x1D4:
	  li        r0, 0
	  b         .loc_0x1E0

	.loc_0x1DC:
	  li        r0, 0x1

	.loc_0x1E0:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x220
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x220:
	  li        r3, 0x38
	  bl        -0x5324C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x238
	  bl        0x5BC

	.loc_0x238:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x2B8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x26C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x274

	.loc_0x26C:
	  li        r0, 0
	  b         .loc_0x278

	.loc_0x274:
	  li        r0, 0x1

	.loc_0x278:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2B8
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x2B8:
	  li        r3, 0x10
	  bl        -0x532E4
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x2D0
	  bl        0x248

	.loc_0x2D0:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x350
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x304
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x30C

	.loc_0x304:
	  li        r0, 0
	  b         .loc_0x310

	.loc_0x30C:
	  li        r0, 0x1

	.loc_0x310:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x350
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x350:
	  li        r3, 0x14
	  bl        -0x5337C
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x368
	  bl        .loc_0x400

	.loc_0x368:
	  lwz       r4, 0x8(r31)
	  lwz       r0, 0xC(r31)
	  cmpw      r4, r0
	  bge-      .loc_0x3E8
	  lwz       r3, 0x4(r31)
	  rlwinm    r0,r4,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x4(r30)
	  cmpwi     r3, 0
	  blt-      .loc_0x39C
	  lwz       r0, 0xC(r31)
	  cmpw      r3, r0
	  blt-      .loc_0x3A4

	.loc_0x39C:
	  li        r0, 0
	  b         .loc_0x3A8

	.loc_0x3A4:
	  li        r0, 0x1

	.loc_0x3A8:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x3E8
	  stw       r31, 0x8(r30)
	  lwz       r0, 0x8(r31)
	  lwz       r4, 0x4(r30)
	  lwz       r3, 0x10(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r0, 0x4(r30)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x14(r31)
	  rlwinm    r0,r0,2,0,29
	  stwx      r4, r3, r0
	  lwz       r3, 0x8(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x8(r31)

	.loc_0x3E8:
	  lwz       r0, 0x74(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr

	.loc_0x400:
	*/
}

/*
 * --INFO--
 * Address:	8009A42C
 * Size:	00004C
 */
PelletUfoLoadState::PelletUfoLoadState()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802B
	  addi      r0, r4, 0xDD4
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xD84
	  stw       r0, 0x0(r3)
	  li        r0, 0x5
	  lis       r5, 0x802B
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r0, r5, 0xD34
	  subi      r5, r13, 0x55F8
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xCE4
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A478
 * Size:	00000C
 */
void PelletUfoLoadState::init(Pellet*)
{
	// Generated from stb r0, 0x10(r3)
	_10 = 8;
}

/*
 * --INFO--
 * Address:	8009A484
 * Size:	000070
 */
void PelletUfoLoadState::exec(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r4, 0
	  lbz       r5, 0x10(r3)
	  subi      r4, r5, 0x1
	  rlwinm.   r0,r4,0,24,31
	  stb       r4, 0x10(r3)
	  bne-      .loc_0x44
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  li        r5, 0x2
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C

	.loc_0x44:
	  lfs       f1, 0x94(r31)
	  li        r4, 0x1
	  lfs       f2, 0x9C(r31)
	  lwz       r3, 0x2F00(r13)
	  bl        -0x325D4
	  stfs      f1, 0x98(r31)

	.loc_0x5C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A4F4
 * Size:	000030
 */
void AState<Pellet>::transit(Pellet*, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x8(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
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
 * Address:	8009A524
 * Size:	00001C
 */
void PelletUfoLoadState::cleanup(Pellet*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0xC8(r4)
	  rlwinm    r0,r0,0,10,8
	  stw       r0, 0xC8(r4)
	  lwz       r0, 0xC8(r4)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A540
 * Size:	00004C
 */
PelletDeadState::PelletDeadState()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802B
	  addi      r0, r4, 0xDD4
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xD84
	  stw       r0, 0x0(r3)
	  li        r0, 0x4
	  lis       r5, 0x802B
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r0, r5, 0xD34
	  subi      r5, r13, 0x55F0
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xC64
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A58C
 * Size:	000004
 */
void PelletDeadState::init(Pellet*) { }

/*
 * --INFO--
 * Address:	8009A590
 * Size:	000004
 */
void PelletDeadState::exec(Pellet*) { }

/*
 * --INFO--
 * Address:	8009A594
 * Size:	000004
 */
void PelletDeadState::cleanup(Pellet*) { }

/*
 * --INFO--
 * Address:	8009A598
 * Size:	000048
 */
PelletNormalState::PelletNormalState()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802B
	  addi      r0, r4, 0xDD4
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xD84
	  stw       r0, 0x0(r3)
	  li        r0, 0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r3)
	  addi      r6, r5, 0xD34
	  subi      r5, r13, 0x55E8
	  stw       r0, 0x8(r3)
	  lis       r4, 0x802B
	  addi      r0, r4, 0xBE8
	  stw       r6, 0x0(r3)
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A5E0
 * Size:	000004
 */
void PelletNormalState::init(Pellet*) { }

/*
 * --INFO--
 * Address:	8009A5E4
 * Size:	000004
 */
void PelletNormalState::exec(Pellet*) { }

/*
 * --INFO--
 * Address:	8009A5E8
 * Size:	000004
 */
void PelletNormalState::cleanup(Pellet*) { }

/*
 * --INFO--
 * Address:	8009A5EC
 * Size:	000050
 */
PelletSwallowedState::PelletSwallowedState()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802B
	  addi      r0, r4, 0xDD4
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xD84
	  stw       r0, 0x0(r3)
	  li        r0, 0x3
	  lis       r5, 0x802B
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r0, r4, 0xD34
	  addi      r5, r5, 0x9DC
	  stw       r0, 0x0(r3)
	  lis       r4, 0x802B
	  addi      r0, r4, 0xB68
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A63C
 * Size:	000004
 */
void PelletSwallowedState::init(Pellet*) { }

/*
 * --INFO--
 * Address:	8009A640
 * Size:	00003C
 */
void PelletSwallowedState::exec(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r0, 0xC8(r4)
	  rlwinm.   r0,r0,0,16,16
	  bne-      .loc_0x2C
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A67C
 * Size:	000024
 */
void PelletSwallowedState::cleanup(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r3, r4
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xA670
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A6A0
 * Size:	00004C
 */
PelletAppearState::PelletAppearState()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802B
	  addi      r0, r4, 0xDD4
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xD84
	  stw       r0, 0x0(r3)
	  li        r0, 0x2
	  lis       r5, 0x802B
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r0, r5, 0xD34
	  subi      r5, r13, 0x55E0
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xAE4
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A6EC
 * Size:	000030
 */
void PelletAppearState::init(Pellet*)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x55C(r4)
	  lfs       f0, -0x7368(r2)
	  lfs       f1, 0xFC(r5)
	  stfs      f0, 0x10(r3)
	  lfs       f0, 0x10(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x7C(r4)
	  stfs      f0, 0x80(r4)
	  stfs      f0, 0x84(r4)
	  lfs       f0, -0x7364(r2)
	  stfs      f0, 0x14(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A71C
 * Size:	000030
 */
void PelletAppearState::procBounceMsg(Pellet*, MsgBounce*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x4C(r12)
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
 * Address:	8009A74C
 * Size:	0000CC
 */
void PelletAppearState::exec(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x8(r1)
	  lwz       r5, 0x55C(r4)
	  lfs       f3, 0xFC(r5)
	  stb       r0, 0x43D(r4)
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, -0x7360(r2)
	  lfs       f0, 0x28C(r5)
	  lfs       f2, 0x10(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x10(r3)
	  lfs       f1, 0x10(r3)
	  lfs       f0, -0x735C(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x60
	  stfs      f0, 0x10(r3)
	  stfs      f3, 0x7C(r4)
	  stfs      f3, 0x80(r4)
	  stfs      f3, 0x84(r4)
	  b         .loc_0x70

	.loc_0x60:
	  fmuls     f0, f1, f3
	  stfs      f0, 0x7C(r4)
	  stfs      f0, 0x80(r4)
	  stfs      f0, 0x84(r4)

	.loc_0x70:
	  lfs       f1, 0x10(r3)
	  lfs       f0, -0x735C(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xBC
	  lwz       r5, 0x2DEC(r13)
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0x28C(r5)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x14(r3)
	  lfs       f1, 0x14(r3)
	  lfs       f0, -0x7358(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xBC
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0xBC:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A818
 * Size:	000004
 */
void PelletAppearState::cleanup(Pellet*) { }

/*
 * --INFO--
 * Address:	8009A81C
 * Size:	00005C
 */
PelletGoalState::PelletGoalState()
{
	/*
	.loc_0x0:
	  lis       r4, 0x802B
	  addi      r0, r4, 0xDD4
	  lis       r4, 0x802B
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xD84
	  stw       r0, 0x0(r3)
	  li        r0, 0x1
	  lis       r5, 0x802B
	  stw       r0, 0x4(r3)
	  li        r0, 0
	  lis       r4, 0x802B
	  stw       r0, 0x8(r3)
	  addi      r0, r5, 0xD34
	  subi      r5, r13, 0x55D8
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0xA64
	  stw       r5, 0xC(r3)
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x7358(r2)
	  stfs      f0, 0x2C(r3)
	  stfs      f0, 0x28(r3)
	  stfs      f0, 0x24(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009A878
 * Size:	00057C
 */
void PelletGoalState::init(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x180(r1)
	  stw       r31, 0x17C(r1)
	  mr        r31, r4
	  stw       r30, 0x178(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x174(r1)
	  stw       r28, 0x170(r1)
	  stb       r0, 0x31(r3)
	  lwz       r3, 0x458(r4)
	  lwz       r0, 0x6C(r3)
	  cmpwi     r0, 0x1E
	  bne-      .loc_0x148
	  li        r0, 0x1
	  stb       r0, 0x31(r30)
	  li        r4, 0xD
	  lwz       r3, 0x2F6C(r13)
	  addi      r3, r3, 0x54
	  bl        -0x18404
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xA0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  li        r0, -0x1
	  sth       r0, 0x1E0(r3)
	  sth       r0, 0x1E2(r3)
	  lwz       r3, 0x30AC(r13)
	  bl        0x5834C
	  lwz       r4, 0x2F6C(r13)
	  addi      r5, r3, 0
	  addi      r3, r4, 0x54
	  li        r4, 0xD
	  bl        -0x183E4
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xC
	  addi      r3, r3, 0x54
	  bl        -0x181C0
	  b         .loc_0x13C

	.loc_0xA0:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x191AC
	  subfic    r0, r3, 0x1
	  cntlzw    r0, r0
	  rlwinm    r29,r0,27,5,31
	  li        r28, 0

	.loc_0xB8:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x191C4
	  addi      r28, r28, 0x1
	  cmpwi     r28, 0x1E
	  blt+      .loc_0xB8
	  lwz       r3, 0x55C(r31)
	  lwz       r3, 0x2C(r3)
	  bl        -0x5E38
	  rlwinm.   r0,r29,0,24,31
	  lis       r4, 0x803A
	  extsh     r0, r3
	  subi      r3, r4, 0x2848
	  sth       r0, 0x1E0(r3)
	  beq-      .loc_0xF8
	  li        r0, 0x2
	  b         .loc_0xFC

	.loc_0xF8:
	  li        r0, 0

	.loc_0xFC:
	  lis       r3, 0x803A
	  extsh     r0, r0
	  subi      r3, r3, 0x2848
	  sth       r0, 0x1E2(r3)
	  addi      r6, r31, 0
	  addi      r7, r31, 0x94
	  lwz       r3, 0x1E8(r3)
	  addi      r8, r31, 0x88
	  li        r4, 0x4F
	  lwz       r12, 0x0(r3)
	  li        r5, 0
	  li        r9, -0x1
	  lwz       r12, 0xC(r12)
	  li        r10, 0x1
	  mtlr      r12
	  blrl

	.loc_0x13C:
	  lwz       r3, 0x2F6C(r13)
	  bl        -0x191F0
	  b         .loc_0x18C

	.loc_0x148:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x24E0
	  lwz       r3, 0xA8(r3)
	  lhz       r0, 0x26(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x18C
	  lwz       r3, 0x2F6C(r13)
	  li        r4, 0xA
	  addi      r3, r3, 0x54
	  bl        -0x18520
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x18C
	  lwz       r3, 0x2F6C(r13)
	  addi      r5, r31, 0
	  li        r4, 0xA
	  addi      r3, r3, 0x54
	  bl        -0x184E4

	.loc_0x18C:
	  mr        r3, r31
	  lfs       f1, -0x7354(r2)
	  bl        -0x4064
	  lwz       r4, 0x458(r31)
	  addi      r3, r1, 0xA8
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x458(r31)
	  addi      r3, r1, 0xB4
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0xB8(r1)
	  lfs       f2, 0xAC(r1)
	  lfs       f1, 0xB4(r1)
	  lfs       f0, 0xA8(r1)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xBC(r1)
	  fsubs     f4, f1, f0
	  lfs       f0, 0xB0(r1)
	  fmuls     f1, f3, f3
	  fsubs     f3, f2, f0
	  lfs       f0, -0x7358(r2)
	  fmuls     f2, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x264
	  fsqrte    f1, f4
	  lfd       f3, -0x7350(r2)
	  lfd       f2, -0x7348(r2)
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
	  stfs      f0, 0x58(r1)
	  lfs       f4, 0x58(r1)

	.loc_0x264:
	  stfs      f4, 0x14(r30)
	  lfs       f1, -0x7358(r2)
	  stfs      f1, 0x10(r30)
	  lfs       f0, -0x7340(r2)
	  stfs      f0, 0x18(r30)
	  lwz       r0, 0xC8(r31)
	  ori       r0, r0, 0x80
	  stw       r0, 0xC8(r31)
	  stfs      f1, 0x74(r31)
	  lwz       r4, 0x458(r31)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x1E
	  beq-      .loc_0x30C
	  lwz       r12, 0x0(r4)
	  addi      r3, r1, 0x9C
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, -0x7358(r2)
	  addi      r4, r1, 0x12C
	  lfs       f0, 0x9C(r1)
	  li        r3, 0
	  stfs      f1, 0x134(r1)
	  lfs       f3, 0xA0(r1)
	  stfs      f1, 0x130(r1)
	  lfs       f2, 0xA4(r1)
	  stfs      f0, 0x158(r1)
	  lfs       f0, -0x735C(r2)
	  stfs      f1, 0x12C(r1)
	  stfs      f3, 0x15C(r1)
	  stfs      f2, 0x160(r1)
	  stfs      f1, 0x140(r1)
	  lwz       r6, 0x158(r1)
	  stfs      f1, 0x13C(r1)
	  lwz       r5, 0x15C(r1)
	  stfs      f1, 0x138(r1)
	  lwz       r0, 0x160(r1)
	  stw       r6, 0x12C(r1)
	  stw       r5, 0x130(r1)
	  stw       r0, 0x134(r1)
	  stfs      f0, 0x150(r1)
	  bl        0x79760

	.loc_0x30C:
	  lfs       f0, 0x7C(r31)
	  addi      r3, r31, 0
	  li        r5, 0xCB
	  stfs      f0, 0x1C(r30)
	  lwz       r4, 0x458(r31)
	  bl        -0x105E4
	  lfs       f2, 0x2B8(r31)
	  lfs       f0, -0x55D0(r13)
	  lfs       f1, -0x55CC(r13)
	  fadds     f2, f2, f0
	  lfs       f0, -0x55C8(r13)
	  stfs      f2, 0x60(r1)
	  lfs       f2, 0x60(r1)
	  stfs      f2, 0x90(r1)
	  lfs       f2, 0x2BC(r31)
	  fadds     f1, f2, f1
	  stfs      f1, 0x94(r1)
	  lfs       f1, 0x2C0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x98(r1)
	  lwz       r3, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stw       r3, 0x2B8(r31)
	  stw       r0, 0x2BC(r31)
	  lwz       r0, 0x98(r1)
	  stw       r0, 0x2C0(r31)
	  lwz       r4, 0x458(r31)
	  lwz       r0, 0x6C(r4)
	  cmpwi     r0, 0x1E
	  bne-      .loc_0x44C
	  lwz       r12, 0x0(r4)
	  addi      r3, r1, 0x78
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x78(r1)
	  addi      r3, r1, 0x6C
	  lfs       f1, 0x7C(r1)
	  stfs      f0, 0x120(r1)
	  lfs       f0, 0x80(r1)
	  stfs      f1, 0x124(r1)
	  stfs      f0, 0x128(r1)
	  lwz       r4, 0x458(r31)
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x7358(r2)
	  addi      r4, r1, 0xE8
	  lfs       f3, 0x6C(r1)
	  li        r3, 0x15
	  stfs      f0, 0xF0(r1)
	  lfs       f2, 0x70(r1)
	  stfs      f0, 0xEC(r1)
	  lfs       f1, 0x74(r1)
	  stfs      f3, 0x114(r1)
	  stfs      f0, 0xE8(r1)
	  stfs      f2, 0x118(r1)
	  stfs      f0, 0xFC(r1)
	  stfs      f1, 0x11C(r1)
	  stfs      f0, 0xF8(r1)
	  stfs      f0, 0xF4(r1)
	  lwz       r0, 0x120(r1)
	  lwz       r5, 0x124(r1)
	  stw       r0, 0xE8(r1)
	  lwz       r0, 0x128(r1)
	  stw       r5, 0xEC(r1)
	  lwz       r5, 0x114(r1)
	  stw       r0, 0xF0(r1)
	  lwz       r0, 0x118(r1)
	  stw       r5, 0xF4(r1)
	  stw       r0, 0xF8(r1)
	  lwz       r0, 0x11C(r1)
	  stw       r0, 0xFC(r1)
	  lfs       f0, -0x735C(r2)
	  stfs      f0, 0x10C(r1)
	  bl        0x7962C
	  li        r3, 0x16
	  addi      r4, r1, 0xE8
	  bl        0x79620

	.loc_0x44C:
	  addi      r3, r1, 0xD8
	  addi      r4, r31, 0
	  bl        -0xA048
	  addi      r30, r1, 0xD8
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3
	  b         .loc_0x4D8

	.loc_0x478:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x49C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x4B4

	.loc_0x49C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x4B4:
	  lwz       r3, 0x6C(r3)
	  bl        -0x62F8
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x4D8:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x500
	  li        r0, 0x1
	  b         .loc_0x52C

	.loc_0x500:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x528
	  li        r0, 0x1
	  b         .loc_0x52C

	.loc_0x528:
	  li        r0, 0

	.loc_0x52C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x478
	  lwz       r3, 0x55C(r31)
	  lwz       r0, 0x5C(r3)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x55C
	  lwz       r3, 0x458(r31)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl

	.loc_0x55C:
	  lwz       r0, 0x184(r1)
	  lwz       r31, 0x17C(r1)
	  lwz       r30, 0x178(r1)
	  lwz       r29, 0x174(r1)
	  lwz       r28, 0x170(r1)
	  addi      r1, r1, 0x180
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009ADF4
 * Size:	0002D4
 */
void PelletGoalState::exec(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x118(r1)
	  stw       r31, 0x114(r1)
	  mr        r31, r4
	  stw       r30, 0x110(r1)
	  mr        r30, r3
	  lfs       f0, -0x7358(r2)
	  lfs       f1, 0x18(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x54
	  stfs      f0, 0x78(r31)
	  li        r0, 0x1
	  stfs      f0, 0x70(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x18(r30)
	  lfs       f0, 0x28C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x18(r30)
	  stb       r0, 0x30(r30)
	  b         .loc_0x2BC

	.loc_0x54:
	  lbz       r0, 0x30(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x144
	  lwz       r5, 0x94(r31)
	  li        r0, 0
	  lwz       r4, 0x98(r31)
	  addi      r3, r1, 0xE0
	  stw       r5, 0x24(r30)
	  stw       r4, 0x28(r30)
	  lwz       r4, 0x9C(r31)
	  stw       r4, 0x2C(r30)
	  stfs      f0, 0x20(r30)
	  stb       r0, 0x30(r30)
	  lwz       r4, 0x458(r31)
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0xE4(r1)
	  lfs       f2, 0x28(r30)
	  lfs       f1, 0xE0(r1)
	  lfs       f0, 0x24(r30)
	  fsubs     f3, f3, f2
	  lfs       f2, 0xE8(r1)
	  fsubs     f4, f1, f0
	  lfs       f0, 0x2C(r30)
	  fmuls     f1, f3, f3
	  fsubs     f3, f2, f0
	  lfs       f0, -0x7358(r2)
	  fmuls     f2, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x138
	  fsqrte    f1, f4
	  lfd       f3, -0x7350(r2)
	  lfd       f2, -0x7348(r2)
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
	  stfs      f0, 0x88(r1)
	  lfs       f4, 0x88(r1)

	.loc_0x138:
	  stfs      f4, 0x14(r30)
	  lfs       f0, -0x7358(r2)
	  stfs      f0, 0x34(r30)

	.loc_0x144:
	  lwz       r4, 0x458(r31)
	  addi      r3, r1, 0xC8
	  lwz       r12, 0x0(r4)
	  lwz       r12, 0x164(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0xC8(r1)
	  lfs       f7, 0x24(r30)
	  lfs       f4, 0x20(r30)
	  fsubs     f0, f0, f7
	  lfs       f5, 0x2C(r30)
	  lfs       f2, 0xD0(r1)
	  lfs       f6, 0x28(r30)
	  fmuls     f0, f0, f4
	  lfs       f1, 0xCC(r1)
	  fsubs     f2, f2, f5
	  stfs      f0, 0xA4(r1)
	  fsubs     f1, f1, f6
	  fmuls     f3, f2, f4
	  lfs       f0, 0xA4(r1)
	  fmuls     f1, f1, f4
	  fadds     f2, f7, f0
	  fadds     f0, f5, f3
	  fadds     f1, f6, f1
	  stfs      f2, 0x98(r1)
	  lfs       f2, 0x98(r1)
	  stfs      f2, 0xBC(r1)
	  stfs      f1, 0xC0(r1)
	  stfs      f0, 0xC4(r1)
	  lwz       r3, 0xBC(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r3, 0x94(r31)
	  stw       r0, 0x98(r31)
	  lwz       r0, 0xC4(r1)
	  stw       r0, 0x9C(r31)
	  lfs       f1, -0x733C(r2)
	  lfs       f0, 0x20(r30)
	  lfs       f3, -0x735C(r2)
	  fmuls     f1, f1, f0
	  lfs       f0, 0x1C(r30)
	  fsubs     f1, f3, f1
	  fmuls     f0, f1, f0
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f2, 0x34(r30)
	  lfs       f1, 0x28C(r3)
	  lfs       f0, 0x14(r30)
	  fmuls     f1, f2, f1
	  lfs       f2, 0x20(r30)
	  fdivs     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x20(r30)
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x7338(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x34(r30)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x34(r30)
	  lfs       f0, 0x20(r30)
	  fcmpo     cr0, f0, f3
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2BC
	  lwz       r3, 0x55C(r31)
	  lwz       r0, 0x5C(r3)
	  cmpwi     r0, 0x3
	  bne-      .loc_0x274
	  lwz       r3, 0x458(r31)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x16C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x28C

	.loc_0x274:
	  lwz       r3, 0x458(r31)
	  mr        r4, r31
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x168(r12)
	  mtlr      r12
	  blrl

	.loc_0x28C:
	  li        r0, 0
	  stb       r0, 0x5B8(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x103B0
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  addi      r4, r31, 0
	  li        r5, 0x4
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl

	.loc_0x2BC:
	  lwz       r0, 0x11C(r1)
	  lwz       r31, 0x114(r1)
	  lwz       r30, 0x110(r1)
	  addi      r1, r1, 0x118
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B0C8
 * Size:	000004
 */
void Suckable::finishSuck(Pellet*) { }

/*
 * --INFO--
 * Address:	8009B0CC
 * Size:	000030
 */
void PelletGoalState::cleanup(Pellet*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lbz       r0, 0x31(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x20
	  li        r3, 0x15
	  bl        0x7923C

	.loc_0x20:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8009B0FC
 * Size:	000004
 */
void AState<Pellet>::resume(Pellet*) { }

/*
 * --INFO--
 * Address:	8009B100
 * Size:	000004
 */
void AState<Pellet>::restart(Pellet*) { }
