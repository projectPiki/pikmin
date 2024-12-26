#include "Nucleus.h"
#include "Slime.h"
#include "EffectMgr.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR();

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("NucleusAi");

/*
 * --INFO--
 * Address:	8017A544
 * Size:	000020
 */
NucleusAi::NucleusAi(Nucleus* nucleus) { mNucleus = nucleus; }

/*
 * --INFO--
 * Address:	8017A564
 * Size:	000074
 */
void NucleusAi::initAI(Nucleus* nucleus)
{
	mNucleus = nucleus;
	mNucleus->set2E4(2);
	mNucleus->set2E8(2);
	mNucleus->mAnimator.startMotion(PaniMotionInfo(2, this));
	mNucleus->setMotionSpeed(30.0f);
	mStickPikiCount = 0;
}

/*
 * --INFO--
 * Address:	8017A5D8
 * Size:	00007C
 */
void NucleusAi::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Action0:
		keyAction0();
		break;
	case KEY_Action1:
		keyAction1();
		break;
	case KEY_LoopEnd:
		keyLoopEnd();
		break;
	case KEY_Done:
		keyFinished();
		break;
	case KEY_PlaySound:
		playSound(event.mValue);
		break;
	}
}

/*
 * --INFO--
 * Address:	8017A654
 * Size:	000004
 */
void NucleusAi::keyAction0() { }

/*
 * --INFO--
 * Address:	8017A658
 * Size:	000004
 */
void NucleusAi::keyAction1() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::keyAction2()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::keyAction3()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8017A65C
 * Size:	000014
 */
void NucleusAi::keyLoopEnd() { mNucleus->_2EC++; }

/*
 * --INFO--
 * Address:	8017A670
 * Size:	000010
 */
void NucleusAi::keyFinished() { mNucleus->_2BD = 1; }

/*
 * --INFO--
 * Address:	8017A680
 * Size:	000004
 */
void NucleusAi::playSound(int) { }

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NucleusAi::setEveryFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NucleusAi::setBossPosition()
{
	mNucleus->mPosition.x = mNucleus->mSlime->_3DC.x;
	mNucleus->mPosition.z = mNucleus->mSlime->_3DC.z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NucleusAi::setSlimeDamagePoint() { mNucleus->mSlime->mSlimeAi->addDamagePoint(mNucleus->getDamage()); }

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NucleusAi::afterProcessing()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NucleusAi::dieTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void NucleusAi::isMotionFinishTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NucleusAi::damageTransit()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void NucleusAi::initDie(int val)
{
	mNucleus->set2E8(val);
	mNucleus->_2BD = 0;
	mNucleus->_2EC = 0;
	mNucleus->mAnimator.startMotion(PaniMotionInfo(1, this));
	mNucleus->_2D4 = 0.0f;
	effectMgr->create(EffectMgr::EFF_Unk57, mNucleus->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Unk56, mNucleus->mPosition, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Unk55, mNucleus->mPosition, nullptr, nullptr);
	mNucleus->doKill();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NucleusAi::initDamage(int val)
{
	mNucleus->set2E8(val);
	mNucleus->_2BD = 0;
	mNucleus->_2EC = 0;
	mNucleus->mAnimator.startMotion(PaniMotionInfo(1, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NucleusAi::initFollow(int val)
{
	mNucleus->set2E8(val);
	mNucleus->_2BD = 0;
	mNucleus->_2EC = 0;
	mNucleus->mAnimator.startMotion(PaniMotionInfo(2, this));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::dieState() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::damageState() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NucleusAi::followState() { }

/*
 * --INFO--
 * Address:	8017A684
 * Size:	0002D0
 */
void NucleusAi::update()
{
	// still somehow needs more inlines (and a lot of them)
	mStickPikiCount = mNucleus->getStickPikiCount();
	setBossPosition();
	setSlimeDamagePoint();
	switch (mNucleus->getCurrStateID()) {
	case 0: // dead?
		break;
	case 1: // damaged?
		if (mNucleus->isDead()) {
			initDie(0);
		} else if (mNucleus->is2BD()) {
			initFollow(2);
		}
		break;
	case 2: // following?
		if (mNucleus->isDead()) {
			initDie(0);
		} else if (mNucleus->isDamagePending()) {
			initDamage(1);
		}
		break;
	}

	mNucleus->resetDamage();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stw       r31, 0x94(r1)
	  mr        r31, r3
	  lwz       r3, 0x8(r3)
	  bl        -0x2B650
	  stw       r3, 0x4(r31)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x3B8(r4)
	  lfs       f0, 0x3DC(r3)
	  stfs      f0, 0x94(r4)
	  lwz       r4, 0x8(r31)
	  lwz       r3, 0x3B8(r4)
	  lfs       f0, 0x3E4(r3)
	  stfs      f0, 0x9C(r4)
	  lwz       r3, 0x8(r31)
	  lfs       f1, 0x2C0(r3)
	  lwz       r3, 0x3B8(r3)
	  lwz       r3, 0x400(r3)
	  bl        -0x15AA4
	  lwz       r3, 0x8(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x78
	  bge-      .loc_0x6C
	  b         .loc_0x2B0

	.loc_0x6C:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x2B0
	  b         .loc_0x18C

	.loc_0x78:
	  lfs       f1, 0x2C4(r3)
	  lfs       f0, -0x519C(r2)
	  fcmpo     cr0, f1, f0
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x140
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x84
	  lwz       r6, 0x8(r31)
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5B7AC
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B588
	  lfs       f0, -0x519C(r2)
	  li        r4, 0x39
	  lwz       r3, 0x8(r31)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x2D4(r3)
	  lwz       r5, 0x8(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x223C8
	  lwz       r5, 0x8(r31)
	  li        r4, 0x38
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x223AC
	  lwz       r5, 0x8(r31)
	  li        r4, 0x37
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x22390
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2B0

	.loc_0x140:
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2B0
	  li        r0, 0x2
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0x7C
	  li        r4, 0x2
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5B86C
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B648
	  b         .loc_0x2B0

	.loc_0x18C:
	  lfs       f0, 0x2C4(r3)
	  lfs       f1, -0x519C(r2)
	  fcmpo     cr0, f0, f1
	  mfcr      r0
	  rlwinm.   r0,r0,2,31,31
	  bne-      .loc_0x254
	  li        r0, 0
	  stw       r0, 0x2E8(r3)
	  addi      r5, r31, 0
	  addi      r3, r1, 0x74
	  lwz       r6, 0x8(r31)
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5B8C0
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B69C
	  lfs       f0, -0x519C(r2)
	  li        r4, 0x39
	  lwz       r3, 0x8(r31)
	  li        r6, 0
	  li        r7, 0
	  stfs      f0, 0x2D4(r3)
	  lwz       r5, 0x8(r31)
	  lwz       r3, 0x3180(r13)
	  addi      r5, r5, 0x94
	  bl        0x222B4
	  lwz       r5, 0x8(r31)
	  li        r4, 0x38
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x22298
	  lwz       r5, 0x8(r31)
	  li        r4, 0x37
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r5, 0x94
	  li        r7, 0
	  bl        0x2227C
	  lwz       r3, 0x8(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x10C(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x2B0

	.loc_0x254:
	  lfs       f0, 0x2C0(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x268
	  li        r0, 0x1
	  b         .loc_0x26C

	.loc_0x268:
	  li        r0, 0

	.loc_0x26C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x2B0
	  li        r0, 0x1
	  stw       r0, 0x2E8(r3)
	  li        r0, 0
	  addi      r5, r31, 0
	  lwz       r6, 0x8(r31)
	  addi      r3, r1, 0x6C
	  li        r4, 0x1
	  stb       r0, 0x2BD(r6)
	  lwz       r6, 0x8(r31)
	  stw       r0, 0x2EC(r6)
	  bl        -0x5B994
	  lwz       r5, 0x8(r31)
	  addi      r4, r3, 0
	  addi      r3, r5, 0x33C
	  bl        -0x5B770

	.loc_0x2B0:
	  lfs       f0, -0x519C(r2)
	  lwz       r3, 0x8(r31)
	  stfs      f0, 0x2C0(r3)
	  lwz       r0, 0x9C(r1)
	  lwz       r31, 0x94(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}
