#include "PikiAI.h"
#include "Interactions.h"
#include "Dolphin/os.h"
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
DEFINE_PRINT("aiBoMake");

/*
 * --INFO--
 * Address:	800AC30C
 * Size:	000054
 */
ActBoMake::ActBoMake(Piki* piki)
    : Action(piki, true)
{
}

/*
 * --INFO--
 * Address:	800AC360
 * Size:	000040
 */
void ActBoMake::init(Creature* creature)
{
	mBuildObject = nullptr;
	if (creature && creature->mObjType == OBJTYPE_BoBase) {
		mBuildObject = creature;
	}

	initApproach();
}

/*
 * --INFO--
 * Address:	800AC3A0
 * Size:	0000A0
 */
int ActBoMake::exec()
{
	if (!mBuildObject) {
		PRINT("done!\n");
		return ACTOUT_Fail;
	}

	if (!mBuildObject->isAlive()) {
		mActor->mEmotion = 0;
		return ACTOUT_Success;
	}

	switch (mState) {
	case STATE_Approach:
		return exeApproach();
	case STATE_Work:
		return exeWork();
	}

	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AC440
 * Size:	000064
 */
void ActBoMake::initApproach()
{
	mState = STATE_Approach;
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
}

/*
 * --INFO--
 * Address:	800AC4A4
 * Size:	00012C
 */
int ActBoMake::exeApproach()
{
	Vector3f direction = mBuildObject->mPosition - mActor->mPosition;
	f32 dist           = direction.normalise();
	if (dist - mBuildObject->getCentreSize() - mActor->getCentreSize() < 3.0f) {
		initWork();
		return ACTOUT_Continue;
	}

	u32 badCompiler; // sigh
	mActor->setSpeed(1.0f, direction);
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AC5D0
 * Size:	0000B4
 */
void ActBoMake::initWork()
{
	// can't stick to a work object if piki is already stuck to something
	if (mActor->mStickTarget) {
		return;
	}

	mActor->startStickObject(mBuildObject, mBuildObject->mCollInfo->getSphere('cent'), -1, 0.0f);
	mActor->startMotion(PaniMotionInfo(PIKIANIM_Kuttuku, this), PaniMotionInfo(PIKIANIM_Kuttuku));
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  stw       r29, 0x24(r1)
	  mr        r29, r3
	  lwz       r3, 0xC(r3)
	  lwz       r0, 0x184(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x98
	  lwz       r5, 0x1C(r29)
	  lis       r3, 0x6365
	  addi      r4, r3, 0x6E74
	  lwz       r3, 0x220(r5)
	  bl        -0x22EFC
	  mr        r5, r3
	  lwz       r3, 0xC(r29)
	  lwz       r4, 0x1C(r29)
	  li        r6, -0x1
	  lfs       f1, -0x70D0(r2)
	  bl        -0x1BF6C
	  cmplwi    r29, 0
	  addi      r30, r29, 0
	  beq-      .loc_0x68
	  addi      r30, r30, 0x14

	.loc_0x68:
	  addi      r3, r1, 0x10
	  li        r4, 0x30
	  bl        0x72918
	  addi      r31, r3, 0
	  addi      r5, r30, 0
	  addi      r3, r1, 0x18
	  li        r4, 0x30
	  bl        0x72938
	  mr        r4, r3
	  lwz       r3, 0xC(r29)
	  mr        r5, r31
	  bl        0x1E374

	.loc_0x98:
	  lwz       r0, 0x34(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  lwz       r29, 0x24(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800AC684
 * Size:	000008
 */
int ActBoMake::exeWork()
{
	return ACTOUT_Continue;
}

/*
 * --INFO--
 * Address:	800AC68C
 * Size:	000024
 */
void ActBoMake::cleanup()
{
	mActor->endStickObject();
}

/*
 * --INFO--
 * Address:	800AC6B0
 * Size:	000078
 */
void ActBoMake::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	switch (event.mEventType) {
	case KEY_Finished:
		break;
	case KEY_Action0:
		InteractBuild build(mActor);
		mBuildObject->stimulate(build); // the one time it's not in the same line, smh
		break;
	}
}
