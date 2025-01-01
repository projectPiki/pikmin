#include "PikiAI.h"
#include "WeedsItem.h"

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
 * Size:	0000F0
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800A6D94
 * Size:	000054
 */
ActStone::ActStone(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800A6DE8
 * Size:	000058
 */
void ActStone::init(Creature* creature)
{
	mCurrPebble = nullptr;
	if (creature && creature->mObjType == OBJTYPE_RockGen) {
		mRockGen = static_cast<RockGen*>(creature);
		mRockGen->startWork();
	}

	initApproach();
}

/*
 * --INFO--
 * Address:	800A6E40
 * Size:	000074
 */
int ActStone::exec()
{
	if (mCurrPebble == nullptr) {
		return ACTOUT_Success;
	}

	switch (mState) {
	case STATE_Approach:
		return exeApproach();

	case STATE_Adjust:
		return exeAdjust();

	case STATE_Attack:
		return exeAttack();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800A6EB4
 * Size:	00004C
 */
void ActStone::cleanup()
{
	mActor->resetCreatureFlag(CF_Unk22);
	mActor->resetCreatureFlag(CF_FixPosition);
	if (mRockGen) {
		mRockGen->finishWork();
	}
}

/*
 * --INFO--
 * Address:	800A6F00
 * Size:	000084
 */
void ActStone::initApproach()
{
	if (mRockGen) {
		mCurrPebble = mRockGen->getRandomPebble();
	} else {
		mCurrPebble = nullptr;
	}

	mState = STATE_Approach;

	mActor->startMotion(PaniMotionInfo(2), PaniMotionInfo(2));
}

/*
 * --INFO--
 * Address:	800A6F84
 * Size:	000190
 */
int ActStone::exeApproach()
{
	// obvs something funky with the inlines here, haven't solved what
	u32 badCompiler;
	u32 badCompiler2;
	u32 badCompiler3;
	u32 badCompiler4;
	if (!mCurrPebble || mCurrPebble->_0E == 0) {
		mActor->mEmotion = 1;
		return ACTOUT_Fail;
	}

	Vector3f direction = mCurrPebble->mPosition - mActor->mPosition;
	direction.y        = 0.0f;
	f32 dist           = direction.length();
	direction.normalise();

	if (dist <= 20.0f) {
		initAdjust();
		return ACTOUT_Continue;
	}

	mActor->setSpeed(0.7f, direction);
	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r4, 0x20(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x30
	  lbz       r0, 0xE(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x44

	.loc_0x30:
	  lwz       r4, 0xC(r31)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x178

	.loc_0x44:
	  lwz       r3, 0xC(r31)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x0(r4)
	  lfs       f3, 0x4(r4)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r4)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x48(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x48(r1)
	  lfs       f1, 0x50(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x71F0(r2)
	  fmuls     f1, f1, f1
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0xF0
	  fsqrte    f1, f31
	  lfd       f3, -0x71E8(r2)
	  lfd       f2, -0x71E0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f31, 0x2C(r1)

	.loc_0xF0:
	  lfs       f1, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x50(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x99454
	  lfs       f0, -0x71F0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x144
	  lfs       f0, 0x48(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x50(r1)

	.loc_0x144:
	  lfs       f0, -0x71D8(r2)
	  fcmpo     cr0, f31, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x164
	  mr        r3, r31
	  bl        .loc_0x190
	  li        r3, 0
	  b         .loc_0x178

	.loc_0x164:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x48
	  lfs       f1, -0x71D4(r2)
	  bl        0x24CE4
	  li        r3, 0

	.loc_0x178:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr

	.loc_0x190:
	*/
}

/*
 * --INFO--
 * Address:	800A7114
 * Size:	00000C
 */
void ActStone::initAdjust() { mState = STATE_Adjust; }

/*
 * --INFO--
 * Address:	800A7120
 * Size:	0001C4
 */
int ActStone::exeAdjust()
{
	// obvs something funky with the inlines here, haven't solved what
	u32 badCompiler;
	u32 badCompiler2;
	u32 badCompiler3;
	u32 badCompiler4;
	if (!mCurrPebble || mCurrPebble->_0E == 0) {
		mActor->mEmotion = 1;
		return ACTOUT_Fail;
	}

	Vector3f direction = mCurrPebble->mPosition - mActor->mPosition;
	direction.y        = 0.0f;
	f32 dist           = direction.length();
	direction.normalise();

	if (dist < 20.0f) {
		initAttack();
		mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mActor->mVelocity.set(0.0f, 0.0f, 0.0f);
		return ACTOUT_Continue;
	}

	mActor->setSpeed(0.7f, direction);
	return ACTOUT_Continue;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r4, 0x20(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x30
	  lbz       r0, 0xE(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x44

	.loc_0x30:
	  lwz       r4, 0xC(r31)
	  li        r0, 0x1
	  li        r3, 0x1
	  stb       r0, 0x400(r4)
	  b         .loc_0x1AC

	.loc_0x44:
	  lwz       r3, 0xC(r31)
	  lfsu      f0, 0x94(r3)
	  lfs       f1, 0x0(r4)
	  lfs       f3, 0x4(r4)
	  lfs       f2, 0x4(r3)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x8(r4)
	  lfs       f1, 0x8(r3)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x48(r1)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  lfs       f0, 0x48(r1)
	  lfs       f1, 0x50(r1)
	  fmuls     f2, f0, f0
	  lfs       f0, -0x71F0(r2)
	  fmuls     f1, f1, f1
	  fadds     f31, f2, f1
	  fcmpo     cr0, f31, f0
	  ble-      .loc_0xF0
	  fsqrte    f1, f31
	  lfd       f3, -0x71E8(r2)
	  lfd       f2, -0x71E0(r2)
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f1, f1, f0
	  fmul      f0, f1, f1
	  fmul      f1, f3, f1
	  fmul      f0, f31, f0
	  fsub      f0, f2, f0
	  fmul      f0, f1, f0
	  fmul      f0, f31, f0
	  frsp      f0, f0
	  stfs      f0, 0x2C(r1)
	  lfs       f31, 0x2C(r1)

	.loc_0xF0:
	  lfs       f1, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x50(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x995F0
	  lfs       f0, -0x71F0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x144
	  lfs       f0, 0x48(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x50(r1)

	.loc_0x144:
	  lfs       f0, -0x71D0(r2)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x198
	  mr        r3, r31
	  bl        .loc_0x1C4
	  lwz       r4, 0xC(r31)
	  li        r3, 0
	  lfs       f0, -0x50F0(r13)
	  stfsu     f0, 0xA4(r4)
	  lfs       f0, -0x50EC(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x50E8(r13)
	  stfs      f0, 0x8(r4)
	  lwz       r4, 0xC(r31)
	  lfs       f0, -0x50E4(r13)
	  stfsu     f0, 0x70(r4)
	  lfs       f0, -0x50E0(r13)
	  stfs      f0, 0x4(r4)
	  lfs       f0, -0x50DC(r13)
	  stfs      f0, 0x8(r4)
	  b         .loc_0x1AC

	.loc_0x198:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x48
	  lfs       f1, -0x71CC(r2)
	  bl        0x24B14
	  li        r3, 0

	.loc_0x1AC:
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr

	.loc_0x1C4:
	*/
}

/*
 * --INFO--
 * Address:	800A72E4
 * Size:	000094
 */
void ActStone::initAttack()
{
	mState = STATE_Attack;
	mActor->startMotion(PaniMotionInfo(19, this), PaniMotionInfo(19));
	_28 = 0;
	mActor->setCreatureFlag(CF_Unk22);
}

/*
 * --INFO--
 * Address:	800A7378
 * Size:	000174
 */
int ActStone::exeAttack()
{
	if (mCurrPebble->_0E == 0) {
		mActor->resetCreatureFlag(CF_Unk22);
		mActor->resetCreatureFlag(CF_FixPosition);

		initApproach();
		return ACTOUT_Continue;
	}

	mActor->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	mActor->mVelocity.set(0.0f, 0.0f, 0.0f);
	if (_28) {
		initAttack();
		return ACTOUT_Continue;
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800A74EC
 * Size:	00030C
 */
void ActStone::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stw       r31, 0xAC(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xA8(r1)
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x3C
	  bge-      .loc_0x2EC
	  cmpwi     r0, 0
	  bge-      .loc_0x2D8
	  b         .loc_0x2EC

	.loc_0x3C:
	  lhz       r0, 0x18(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x2EC
	  cmplwi    r31, 0
	  addi      r4, r31, 0
	  beq-      .loc_0x58
	  addi      r4, r4, 0x14

	.loc_0x58:
	  lwz       r3, 0xC(r31)
	  addi      r3, r3, 0x354
	  bl        0x78574
	  lwz       r4, 0x20(r31)
	  lbz       r3, 0xE(r4)
	  cmplwi    r3, 0
	  beq-      .loc_0x98
	  subi      r0, r3, 0x1
	  stb       r0, 0xE(r4)
	  lbz       r0, 0xE(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0x90
	  li        r30, 0x2
	  b         .loc_0x9C

	.loc_0x90:
	  li        r30, 0
	  b         .loc_0x9C

	.loc_0x98:
	  li        r30, 0x1

	.loc_0x9C:
	  cmpwi     r30, 0x1
	  beq-      .loc_0x2EC
	  lwz       r3, 0xC(r31)
	  lfs       f1, 0xA0(r3)
	  bl        0x1745BC
	  lwz       r3, 0xC(r31)
	  fmr       f31, f1
	  lfs       f1, 0xA0(r3)
	  bl        0x174740
	  stfs      f1, 0x8C(r1)
	  addi      r4, r1, 0x60
	  lfs       f0, -0x50C0(r13)
	  li        r3, 0xC
	  stfs      f0, 0x90(r1)
	  stfs      f31, 0x94(r1)
	  lfs       f4, -0x50BC(r13)
	  lfs       f1, 0x8C(r1)
	  lwz       r5, 0xC(r31)
	  fmuls     f1, f1, f4
	  lfsu      f0, 0x94(r5)
	  lfs       f3, 0x94(r1)
	  lfs       f2, 0x90(r1)
	  fadds     f0, f1, f0
	  fmuls     f1, f2, f4
	  fmuls     f3, f3, f4
	  stfs      f0, 0x8C(r1)
	  lfs       f0, 0x4(r5)
	  fadds     f0, f1, f0
	  stfs      f0, 0x90(r1)
	  lfs       f0, 0x8(r5)
	  fadds     f0, f3, f0
	  stfs      f0, 0x94(r1)
	  lfs       f1, -0x71F0(r2)
	  lwz       r6, 0x8C(r1)
	  stfs      f1, 0x68(r1)
	  lwz       r5, 0x90(r1)
	  stfs      f1, 0x64(r1)
	  lwz       r0, 0x94(r1)
	  stfs      f1, 0x60(r1)
	  lfs       f0, -0x71C8(r2)
	  stfs      f1, 0x74(r1)
	  stfs      f1, 0x70(r1)
	  stfs      f1, 0x6C(r1)
	  stw       r6, 0x60(r1)
	  stw       r5, 0x64(r1)
	  stw       r0, 0x68(r1)
	  stfs      f0, 0x84(r1)
	  bl        0x6CC9C
	  cmpwi     r30, 0x2
	  bne-      .loc_0x2C4
	  li        r3, 0xA
	  addi      r4, r1, 0x60
	  bl        0x6CC88
	  lwz       r3, 0x24(r31)
	  bl        0x3D918
	  lwz       r3, 0xC(r31)
	  li        r5, 0xB1
	  lwz       r4, 0x24(r31)
	  bl        -0x1D0BC
	  bl        0x1709FC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x71A8(r2)
	  stw       r0, 0xA4(r1)
	  lis       r31, 0x4330
	  lfs       f2, -0x71C4(r2)
	  stw       r31, 0xA0(r1)
	  lfs       f1, -0x71C8(r2)
	  lfd       f3, 0xA0(r1)
	  lfs       f0, -0x71C0(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2EC
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x6
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  beq-      .loc_0x2EC
	  lfs       f0, 0x8C(r1)
	  stfs      f0, 0x54(r1)
	  lfs       f0, 0x90(r1)
	  stfs      f0, 0x58(r1)
	  lfs       f1, 0x94(r1)
	  lfs       f0, -0x71BC(r2)
	  stfs      f1, 0x5C(r1)
	  lfs       f1, 0x58(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x58(r1)
	  bl        0x170978
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x71A8(r2)
	  stw       r0, 0xA4(r1)
	  lfs       f3, -0x71C4(r2)
	  stw       r31, 0xA0(r1)
	  lfs       f2, -0x71C8(r2)
	  lfd       f1, 0xA0(r1)
	  lfs       f0, -0x71B4(r2)
	  fsubs     f4, f1, f4
	  lfs       f1, -0x71B8(r2)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fmuls     f30, f1, f0
	  fmr       f1, f30
	  bl        0x17441C
	  lfs       f0, -0x71B0(r2)
	  fmuls     f31, f0, f1
	  fmr       f1, f30
	  bl        0x1745A0
	  lfs       f2, -0x71B0(r2)
	  mr        r3, r30
	  lfs       f0, -0x71AC(r2)
	  addi      r4, r1, 0x54
	  fmuls     f1, f2, f1
	  stfs      f1, 0x40(r1)
	  stfs      f0, 0x44(r1)
	  stfs      f31, 0x48(r1)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0x40(r1)
	  mr        r3, r30
	  lwz       r0, 0x44(r1)
	  li        r4, 0
	  stw       r5, 0x70(r30)
	  stw       r0, 0x74(r30)
	  lwz       r0, 0x48(r1)
	  stw       r0, 0x78(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2EC

	.loc_0x2C4:
	  lwz       r3, 0xC(r31)
	  li        r5, 0xB0
	  lwz       r4, 0x24(r31)
	  bl        -0x1D208
	  b         .loc_0x2EC

	.loc_0x2D8:
	  lhz       r0, 0x18(r31)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x2EC
	  li        r0, 0x1
	  stb       r0, 0x28(r31)

	.loc_0x2EC:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lwz       r31, 0xAC(r1)
	  lwz       r30, 0xA8(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800A77F8
 * Size:	00006C
 */
ActStone::~ActStone() { }
