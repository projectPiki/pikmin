#include "PikiAI.h"
#include "PikiMgr.h"
#include "Navi.h"
#include "PikiState.h"
#include "GameStat.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "sysNew.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("free")

static int motions[] = { PIKIANIM_Rinbow, PIKIANIM_Akubi, PIKIANIM_Sagasu2, PIKIANIM_Chatting };
int numMotions       = 4;

/*
 * --INFO--
 * Address:	800BA600
 * Size:	0000CC
 */
ActFree::ActFree(Piki* piki)
    : Action(piki, true)
{
	setName("free");
	mSelectAction = new ActFreeSelect(piki);
}

/*
 * --INFO--
 * Address:	800BA6CC
 * Size:	0000D0
 */
void ActFree::initBoid(Vector3f& targetPosition, f32 radius)
{
	mIsBoidActive   = 1;
	mTargetPosition = targetPosition;
	mArrivalRadius  = radius;
	if (mPiki->isHolding()) {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick), PaniMotionInfo(PIKIANIM_Pick));
		mPiki->enableMotionBlend();
	} else {
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Walk), PaniMotionInfo(PIKIANIM_Walk));
	}

	mBoidTimer = 3.0f;
}

/*
 * --INFO--
 * Address:	800BA79C
 * Size:	0001C4
 */
void ActFree::exeBoid()
{
	Vector3f dirToTarget = mTargetPosition - mPiki->mPosition;
	f32 distanceToTarget = dirToTarget.normalise();
	mBoidTimer -= gsys->getFrameTime();

	if (distanceToTarget < 0.9f * mArrivalRadius || mBoidTimer <= 0.0f) {
		mPiki->enableFixPos();
		mFixedPositionTimer = 3.0f;
		mIsBoidActive       = 0;
		mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		if (mPiki->isHolding() && mPiki->mPikiAnimMgr.getUpperAnimator().getCurrentMotionIndex() != PIKIANIM_Pick) {
			mPiki->startMotion(PaniMotionInfo(PIKIANIM_Pick, this), PaniMotionInfo(PIKIANIM_Pick));
			mPiki->mPikiAnimMgr.getUpperAnimator().mAnimationCounter = 18.0f;
			mPiki->mPikiAnimMgr.getLowerAnimator().mAnimationCounter = 18.0f;
			mPiki->enableMotionBlend();
		}
	} else {
		mPiki->setSpeed(0.5f, dirToTarget);
	}
}

/*
 * --INFO--
 * Address:	800BA960
 * Size:	0002F4
 */
void ActFree::init(Creature*)
{
	mIsBoidActive           = 0;
	mCollisionCooldownTimer = 1.0f;
	mBoidTimer              = C_PIKI_PROP(mPiki)._2EC() + randFloat(3.0f);
	_20                     = 0.9f * mBoidTimer;
	_24                     = 0.8f * mBoidTimer;

	mPiki->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
	if (mPiki->isHolding()) {
		PRINT("### piki is holding !\n");
		mPiki->startMotion(PaniMotionInfo(PIKIANIM_Wait, this), PaniMotionInfo(PIKIANIM_Wait));
	} else {
		f32 r         = unitRandFloat();
		int motionIdx = f32(numMotions) * r;
		if (motionIdx >= numMotions) {
			motionIdx = 0;
		}
		mPiki->startMotion(PaniMotionInfo(motions[motionIdx], this), PaniMotionInfo(motions[motionIdx]));
	}

	mPiki->setPastel();
	_1C            = 0;
	mTouchedPlayer = 0;
	mSelectAction->init(nullptr);

	GameStat::workPikis.dec(mPiki->mColor);
	GameStat::freePikis.inc(mPiki->mColor);

	GameStat::update();

	if (mPiki->aiCullable() && !PikiMgr::meNukiMode) {
		seSystem->playPikiSound(SEF_PIKI_BREAKUP, mPiki->mPosition);
	}

	EffectParm parm(&mPiki->mEffectPos);
	mPiki->mFreeLightEffect->mColor = mPiki->mColor;
	mPiki->mFreeLightEffect->emit(parm);
	mPiki->enableFixPos();
	mFixedPositionTimer = 3.0f;

	// u32 badCompiler[2];

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0xC0(r1)
	  stw       r31, 0xBC(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xB8(r1)
	  stw       r29, 0xB4(r1)
	  stb       r0, 0x46(r3)
	  lfs       f0, -0x6CEC(r2)
	  stfs      f0, 0x40(r3)
	  bl        0x15D6E4
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0xC(r31)
	  stw       r0, 0xAC(r1)
	  lis       r30, 0x4330
	  lfd       f1, -0x6CE0(r2)
	  stw       r30, 0xA8(r1)
	  lfs       f3, -0x6CE8(r2)
	  lfd       f0, 0xA8(r1)
	  lfs       f2, -0x6CEC(r2)
	  fsubs     f4, f0, f1
	  lwz       r3, 0x224(r3)
	  lfs       f0, -0x6CFC(r2)
	  lfs       f1, 0x2F8(r3)
	  fdivs     f3, f4, f3
	  fmuls     f2, f2, f3
	  fmuls     f0, f0, f2
	  fadds     f0, f1, f0
	  stfs      f0, 0x28(r31)
	  lfs       f1, -0x6CF8(r2)
	  lfs       f0, 0x28(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x20(r31)
	  lfs       f1, -0x6CE4(r2)
	  lfs       f0, 0x28(r31)
	  fmuls     f0, f1, f0
	  stfs      f0, 0x24(r31)
	  lwz       r3, 0xC(r31)
	  lfs       f0, -0x48A8(r13)
	  stfsu     f0, 0xA4(r3)
	  lfs       f0, -0x48A4(r13)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x48A0(r13)
	  stfs      f0, 0x8(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0x2AC(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x108
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0xD4
	  lwz       r29, 0x14(r31)

	.loc_0xD4:
	  addi      r3, r1, 0x50
	  li        r4, 0x3
	  bl        0x6451C
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x58
	  li        r4, 0x3
	  bl        0x6453C
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xFF78
	  b         .loc_0x1C0

	.loc_0x108:
	  bl        0x15D608
	  xoris     r0, r3, 0x8000
	  lwz       r3, -0x48B8(r13)
	  stw       r0, 0xAC(r1)
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6CE0(r2)
	  stw       r30, 0xA8(r1)
	  lfs       f0, -0x6CE8(r2)
	  lfd       f1, 0xA8(r1)
	  stw       r0, 0xA4(r1)
	  fsubs     f2, f1, f3
	  lfs       f1, -0x6CEC(r2)
	  stw       r30, 0xA0(r1)
	  fdivs     f2, f2, f0
	  lfd       f0, 0xA0(r1)
	  fmuls     f1, f1, f2
	  fsubs     f0, f0, f3
	  fmuls     f0, f0, f1
	  fctiwz    f0, f0
	  stfd      f0, 0x90(r1)
	  lwz       r0, 0x94(r1)
	  stfd      f0, 0x98(r1)
	  cmpw      r0, r3
	  lwz       r0, 0x9C(r1)
	  blt-      .loc_0x170
	  li        r0, 0

	.loc_0x170:
	  cmplwi    r31, 0
	  addi      r29, r31, 0
	  beq-      .loc_0x180
	  lwz       r29, 0x14(r31)

	.loc_0x180:
	  lis       r3, 0x802B
	  rlwinm    r4,r0,2,0,29
	  addi      r0, r3, 0x6A6C
	  add       r30, r0, r4
	  lwz       r4, 0x0(r30)
	  addi      r3, r1, 0x40
	  bl        0x64460
	  lwz       r4, 0x0(r30)
	  addi      r30, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r1, 0x48
	  bl        0x64480
	  mr        r4, r3
	  lwz       r3, 0xC(r31)
	  mr        r5, r30
	  bl        0xFEBC

	.loc_0x1C0:
	  lwz       r3, 0xC(r31)
	  bl        0xEF44
	  li        r0, 0
	  sth       r0, 0x1C(r31)
	  li        r4, 0
	  stb       r0, 0x45(r31)
	  lwz       r3, 0x18(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x48(r12)
	  mtlr      r12
	  blrl
	  lwz       r5, 0xC(r31)
	  lis       r4, 0x803D
	  lis       r3, 0x803D
	  lhz       r5, 0x510(r5)
	  addi      r4, r4, 0x1E88
	  addi      r0, r3, 0x1E7C
	  rlwinm    r3,r5,2,0,29
	  add       r4, r4, r3
	  lwz       r3, 0x0(r4)
	  subi      r3, r3, 0x1
	  stw       r3, 0x0(r4)
	  lwz       r3, 0xC(r31)
	  lhz       r3, 0x510(r3)
	  rlwinm    r3,r3,2,0,29
	  add       r4, r0, r3
	  lwz       r3, 0x0(r4)
	  addi      r0, r3, 0x1
	  stw       r0, 0x0(r4)
	  bl        0x579CC
	  lwz       r4, 0xC(r31)
	  lwz       r0, 0xC8(r4)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x264
	  lbz       r0, 0x306E(r13)
	  cmplwi    r0, 0
	  bne-      .loc_0x264
	  lwz       r3, 0x3038(r13)
	  addi      r5, r4, 0x94
	  li        r4, 0xFF
	  bl        -0x167B8

	.loc_0x264:
	  lwz       r3, 0xC(r31)
	  addi      r4, r1, 0x60
	  lfs       f1, -0x6D00(r2)
	  addi      r0, r3, 0x464
	  lfs       f0, -0x6CEC(r2)
	  stfs      f1, 0x68(r1)
	  stfs      f1, 0x64(r1)
	  stfs      f1, 0x60(r1)
	  stfs      f1, 0x74(r1)
	  stfs      f1, 0x70(r1)
	  stfs      f1, 0x6C(r1)
	  stw       r0, 0x80(r1)
	  stfs      f0, 0x84(r1)
	  lwz       r3, 0xC(r31)
	  lhz       r0, 0x510(r3)
	  lwz       r3, 0x434(r3)
	  sth       r0, 0xC(r3)
	  lwz       r3, 0xC(r31)
	  lwz       r3, 0x434(r3)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0xC(r31)
	  lwz       r0, 0xC8(r3)
	  oris      r0, r0, 0x40
	  stw       r0, 0xC8(r3)
	  lfs       f0, -0x6CFC(r2)
	  stfs      f0, 0x2C(r31)
	  lwz       r0, 0xC4(r1)
	  lwz       r31, 0xBC(r1)
	  lwz       r30, 0xB8(r1)
	  lwz       r29, 0xB4(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800BAC54
 * Size:	0000AC
 */
void ActFree::cleanup()
{
	mPiki->disableFixPos();
	mPiki->mCreatureFlags &= ~CF_IsPositionFixed;
	mPiki->mFreeLightEffect->kill();
	GameStat::workPikis.inc(mPiki->mColor);
	GameStat::freePikis.dec(mPiki->mColor);
	// if (GameStat::freePikis < 0) {
	// 	ERROR("counter minus(fp)");
	// }
	GameStat::update();
}

/*
 * --INFO--
 * Address:	800BAD00
 * Size:	000004
 */
void ActFree::animationKeyUpdated(PaniAnimKeyEvent&)
{
}

/*
 * --INFO--
 * Address:	800BAD04
 * Size:	0000F0
 */
int ActFree::exec()
{
	Creature* target;
	u32 badCompiler[23]; // huh.

	if (mCollisionCooldownTimer > 0.0f) {
		mCollisionCooldownTimer -= gsys->getFrameTime();
	}

	// Look, but don't touch.
	if (mTouchedPlayer) {
		mPiki->mFSM->transit(mPiki, PIKISTATE_LookAt);
		return ACTOUT_Continue;
	}

	if (mIsBoidActive) {
		exeBoid();
		return ACTOUT_Continue;
	}

	int res = mSelectAction->exec();
	if (!mPiki->mPikiUpdateContext.updatable()) {
		return ACTOUT_Continue;
	}

	if (mPiki->graspSituation(&target)) {
		mSelectAction->finishRest();
	}

	return res;
}

/*
 * --INFO--
 * Address:	800BADF4
 * Size:	0000D8
 */
void ActFree::procCollideMsg(Piki* piki, MsgCollide* msg)
{
	if (mCollisionCooldownTimer > 0.0f || mIsBoidActive) {
		return;
	}

	Creature* collider = msg->mEvent.mCollider;
	if (collider->mObjType == OBJTYPE_Navi && !piki->isKinoko() && !collider->mStickListHead && !mTouchedPlayer
	    && (piki->mPlayerId == -1 || static_cast<Navi*>(collider)->mNaviID == piki->mPlayerId)) {
		rumbleMgr->start(2, 0, nullptr);
		mTouchedPlayer = 1;
		piki->mNavi    = static_cast<Navi*>(collider);
	}
}
