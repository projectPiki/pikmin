#include "Spider.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "NsMath.h"
#include "MapCode.h"
#include "Stickers.h"
#include "RumbleMgr.h"
#include "Interactions.h"
#include "NaviMgr.h"
#include "Pcam/CameraManager.h"
#include "PikiMgr.h"
#include "Matrix3f.h"
#include "SoundMgr.h"
#include "DebugLog.h"

namespace Kumo {
static int leg_index[4][3] = {
	{ 12, 11, 10 },
	{ 15, 14, 13 },
	{ 6, 5, 4 },
	{ 9, 8, 7 },
};

static int legId[9] = {
	3, 2, 0, 1, -1, 2, 3, 0, 1,
};
} // namespace Kumo

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("SpiderLeg");

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void SpiderLeg::setHalfDeadEffect(u32 legCollPartID, int jointIdx, int legNum)
{
	CollPart* legPart = mSpider->mCollInfo->getSphere(legCollPartID);
	for (int i = 0; i < 3; i++) {
		CollPart* child = legPart->getChild();
		if (!child) {
			return;
		}
		if (i == jointIdx) {
			mHalfDeadCallBackJoints[legNum].set(&legPart->mCentre, mSpider);
			effectMgr->create(EffectMgr::EFF_Spider_HalfDead, mSpider->mPosition, &mHalfDeadCallBackJoints[legNum], nullptr);
		}
		legPart = child;
	}
}

/*
 * --INFO--
 * Address:	80155A08
 * Size:	000184
 */
void SpiderLeg::setHalfDeadFallEffect(u32 legCollPartID)
{
	CollPart* legPart = mSpider->mCollInfo->getSphere(legCollPartID);
	for (int i = 0; i < 3; i++) {
		CollPart* child = legPart->getChild();
		if (!child) {
			return;
		}

		zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Spider_HalfDeadFall, mSpider->mPosition, nullptr, nullptr);
		if (ptclGen) {
			Vector3f midPt = child->mCentre + legPart->mCentre;
			midPt.multiply(0.5f);
			Vector3f dir = child->mCentre - legPart->mCentre;
			dir.normalise();

			ptclGen->setEmitPos(midPt);
			ptclGen->setEmitDir(dir);
		}

		legPart = child;
	}
}

/*
 * --INFO--
 * Address:	80155B8C
 * Size:	0001DC
 */
void SpiderLeg::setDeadBombEffect(u32 legCollPartID)
{
	CollPart* legPart = mSpider->mCollInfo->getSphere(legCollPartID);
	for (int i = 0; i < 3; i++) {
		CollPart* child = legPart->getChild();
		if (!child) {
			return;
		}

		Vector3f midPt = child->mCentre + legPart->mCentre;
		midPt.multiply(0.5f);
		Vector3f dir = child->mCentre - legPart->mCentre;
		dir.normalise();

		zen::particleGenerator* ptclGen1 = effectMgr->create(EffectMgr::EFF_Spider_DeadBombSmoke, midPt, nullptr, nullptr);
		if (ptclGen1) {
			ptclGen1->setEmitDir(dir);
		}

		zen::particleGenerator* ptclGen2 = effectMgr->create(EffectMgr::EFF_Spider_DeadBombDebris, midPt, nullptr, nullptr);
		if (ptclGen2) {
			ptclGen2->setEmitDir(dir);
		}

		effectMgr->create(EffectMgr::EFF_Spider_DeadBombSparks, legPart->mCentre, nullptr, nullptr);

		legPart = child;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void SpiderLeg::setSmallSparkEffect(u32 legCollPartID, int* p2)
{
	CollPart* legPart = mSpider->mCollInfo->getSphere(legCollPartID);
	for (int i = 0; i < 3; i++) {
		if (p2[i]) {
			effectMgr->create(EffectMgr::EFF_Spider_SmallSparks, legPart->mCentre, nullptr, nullptr);
		}
		legPart = legPart->getChild();
		if (!legPart) {
			break;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void SpiderLeg::setPerishEffect(u32 legCollPartID, int p2)
{
	CollPart* legPart = mSpider->mCollInfo->getSphere(legCollPartID);
	for (int i = 0; i < 3; i++) {
		CollPart* child = legPart->getChild();
		if (!child) {
			return;
		}

		mPerishCallBacks[i + p2].set(&child->mCentre, &legPart->mCentre, mSpider);
		effectMgr->create(EffectMgr::EFF_Spider_PerishBubbles, mSpider->mPosition, &mPerishCallBacks[i + p2], nullptr);
		effectMgr->create(EffectMgr::EFF_Spider_PerishSmoke, mSpider->mPosition, &mPerishCallBacks[i + p2], nullptr);
		legPart = child;
	}
}

/*
 * --INFO--
 * Address:	80155D68
 * Size:	000228
 */
void SpiderLeg::createHalfDeadEffect()
{
	setHalfDeadEffect('leg1', 1, 0);
	setHalfDeadEffect('leg2', 2, 1);
	setHalfDeadEffect('leg3', 1, 2);
	setHalfDeadEffect('leg4', 2, 3);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void SpiderLeg::createHalfDeadFallEffect(int idx)
{
	if (idx == 0) {
		setHalfDeadFallEffect('leg3');
	}
	if (idx == 1) {
		setHalfDeadFallEffect('leg4');
	}
	if (idx == 2) {
		setHalfDeadFallEffect('leg2');
	}
	if (idx == 3) {
		setHalfDeadFallEffect('leg1');
	}
}

/*
 * --INFO--
 * Address:	80155F90
 * Size:	0000C0
 */
void SpiderLeg::createDeadBombEffect()
{
	setDeadBombEffect('leg1');
	setDeadBombEffect('leg2');
	setDeadBombEffect('leg3');
	setDeadBombEffect('leg4');
	CollPart* body = mSpider->mCollInfo->getSphere('tama');
	effectMgr->create(EffectMgr::EFF_Spider_DeadBombSparks, body->mCentre, nullptr, nullptr);
	rumbleMgr->start(RUMBLE_Unk5, 0, mSpider->mPosition);
	if (mSpider->mSeContext) {
		mSpider->mSeContext->playSound(SE_SPIDER_DEAD);
	}
}

/*
 * --INFO--
 * Address:	80156050
 * Size:	000384
 */
void SpiderLeg::createSmallSparkEffect(int count)
{
	int i;
	int legVals[12] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	int tmp1 = NsLibMath<int>::revice(count, 1, 11);
	for (i = 0; i < tmp1; i++) {
		legVals[i] = 1;
	}

	// shuffle
	for (i = 0; i < 12; i++) {
		tmp1          = NsMathI::getRand(12);
		int tmp       = legVals[i];
		legVals[i]    = legVals[tmp1];
		legVals[tmp1] = tmp;
	}

	setSmallSparkEffect('leg1', &legVals[0]);
	setSmallSparkEffect('leg2', &legVals[3]);
	setSmallSparkEffect('leg3', &legVals[6]);
	setSmallSparkEffect('leg4', &legVals[9]);

	if (mSpider->mSeContext) {
		mSpider->mSeContext->playSound(SE_SPIDER_BOMB);
	}
}

/*
 * --INFO--
 * Address:	801563D4
 * Size:	0002B8
 */
void SpiderLeg::createPerishEffect()
{
	setPerishEffect('leg1', 0);
	setPerishEffect('leg2', 3);
	setPerishEffect('leg3', 6);
	setPerishEffect('leg4', 9);
}

/*
 * --INFO--
 * Address:	8015668C
 * Size:	00014C
 */
void SpiderLeg::createRippleEffect(int legNum)
{
	Vector3f footPos(mJointPositions[legNum][0]);
	footPos.y -= 5.0f;
	effectMgr->create(EffectMgr::EFF_SmokeRing_M, mJointPositions[legNum][0], nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Frog_BubbleRingS, footPos, nullptr, nullptr);
	mRippleCallBacks[legNum].set(&mIsOnGround[legNum]);

	zen::particleGenerator* ptclGen1 = effectMgr->create(EffectMgr::EFF_RippleWhite, footPos, &mRippleCallBacks[legNum], nullptr);
	if (ptclGen1) {
		f32 scale = ptclGen1->getScaleSize();
		ptclGen1->setScaleSize(3.0f * scale);
	}
	zen::particleGenerator* ptclGen2 = effectMgr->create(EffectMgr::EFF_RippleSurface, footPos, &mRippleCallBacks[legNum], nullptr);
	if (ptclGen2) {
		f32 scale = ptclGen2->getScaleSize();
		ptclGen2->setScaleSize(3.0f * scale);
	}
	zen::particleGenerator* ptclGen3 = effectMgr->create(EffectMgr::EFF_RippleBlack, footPos, &mRippleCallBacks[legNum], nullptr);
	if (ptclGen3) {
		f32 scale = ptclGen3->getScaleSize();
		ptclGen3->setScaleSize(3.0f * scale);
	}
}

/*
 * --INFO--
 * Address:	801567D8
 * Size:	0000E0
 */
void SpiderLeg::killCallBackEffect(bool doForceFinish)
{
	int i;
	for (i = 0; i < 4; i++) {
		effectMgr->kill(&mHalfDeadCallBackJoints[i], nullptr, doForceFinish);
	}
	for (i = 0; i < 12; i++) {
		effectMgr->kill(&mPerishCallBacks[i], nullptr, doForceFinish);
	}
	for (i = 0; i < 4; i++) {
		effectMgr->kill(&mRippleCallBacks[i], nullptr, doForceFinish);
	}
}

/*
 * --INFO--
 * Address:	801568B8
 * Size:	000238
 */
void SpiderLeg::setLegScaleParam(int jointIdx)
{
	f32 stepTime = 1.0f / C_SPIDER_PROP(mSpider).mDeadMotionDelay();
	if (jointIdx < 3) {
		for (int i = 0; i < 4; i++) {
			mSegmentScale[Kumo::leg_index[i][jointIdx]]
			    = NsLibMath<f32>::toGoal(mSegmentScale[Kumo::leg_index[i][jointIdx]], 0.0f, gsys->getFrameTime() * stepTime);
		}
	} else {
		for (int i = 0; i < 4; i++) {
			mSegmentScale[i] = NsLibMath<f32>::toGoal(mSegmentScale[i], 0.0f, gsys->getFrameTime() * stepTime);
		}
	}
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r3)
	  cmpwi     r4, 0x3
	  lfs       f1, -0x5678(r2)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x4A0(r5)
	  fdivs     f4, f1, f0
	  bge-      .loc_0x100
	  li        r0, 0x2
	  lfs       f1, -0x568C(r2)
	  lis       r6, 0x802D
	  mtctr     r0
	  lwz       r5, 0x2DEC(r13)
	  rlwinm    r4,r4,2,0,29
	  subi      r0, r6, 0xAD8
	  add       r6, r0, r4
	  li        r7, 0

	.loc_0x40:
	  lwz       r0, 0x0(r6)
	  lfs       f0, 0x28C(r5)
	  rlwinm    r4,r0,2,0,29
	  addi      r4, r4, 0x20
	  fmuls     f0, f4, f0
	  add       r4, r3, r4
	  lfs       f3, 0x0(r4)
	  fsubs     f2, f3, f1
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x6C
	  b         .loc_0x70

	.loc_0x6C:
	  fneg      f2, f2

	.loc_0x70:
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x80
	  fmr       f0, f1
	  b         .loc_0x94

	.loc_0x80:
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x90
	  fadds     f0, f3, f0
	  b         .loc_0x94

	.loc_0x90:
	  fsubs     f0, f3, f0

	.loc_0x94:
	  stfs      f0, 0x0(r4)
	  lwzu      r0, 0xC(r6)
	  lfs       f0, 0x28C(r5)
	  rlwinm    r4,r0,2,0,29
	  addi      r4, r4, 0x20
	  fmuls     f0, f4, f0
	  add       r4, r3, r4
	  lfs       f3, 0x0(r4)
	  fsubs     f2, f3, f1
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0xC4
	  b         .loc_0xC8

	.loc_0xC4:
	  fneg      f2, f2

	.loc_0xC8:
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0xD8
	  fmr       f0, f1
	  b         .loc_0xEC

	.loc_0xD8:
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0xE8
	  fadds     f0, f3, f0
	  b         .loc_0xEC

	.loc_0xE8:
	  fsubs     f0, f3, f0

	.loc_0xEC:
	  stfs      f0, 0x0(r4)
	  addi      r6, r6, 0xC
	  addi      r7, r7, 0x1
	  bdnz+     .loc_0x40
	  blr

	.loc_0x100:
	  lfs       f1, -0x568C(r2)
	  lfs       f3, 0x20(r3)
	  lwz       r4, 0x2DEC(r13)
	  fsubs     f2, f3, f1
	  lfs       f0, 0x28C(r4)
	  fcmpo     cr0, f2, f1
	  fmuls     f0, f4, f0
	  ble-      .loc_0x124
	  b         .loc_0x128

	.loc_0x124:
	  fneg      f2, f2

	.loc_0x128:
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x138
	  fmr       f0, f1
	  b         .loc_0x14C

	.loc_0x138:
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x148
	  fadds     f0, f3, f0
	  b         .loc_0x14C

	.loc_0x148:
	  fsubs     f0, f3, f0

	.loc_0x14C:
	  stfs      f0, 0x20(r3)
	  addi      r3, r3, 0x4
	  lfs       f3, 0x20(r3)
	  lfs       f0, 0x28C(r4)
	  fsubs     f2, f3, f1
	  fmuls     f0, f4, f0
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x170
	  b         .loc_0x174

	.loc_0x170:
	  fneg      f2, f2

	.loc_0x174:
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x184
	  fmr       f0, f1
	  b         .loc_0x198

	.loc_0x184:
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x194
	  fadds     f0, f3, f0
	  b         .loc_0x198

	.loc_0x194:
	  fsubs     f0, f3, f0

	.loc_0x198:
	  stfs      f0, 0x20(r3)
	  lfs       f3, 0x24(r3)
	  addi      r3, r3, 0x4
	  lfs       f0, 0x28C(r4)
	  fsubs     f2, f3, f1
	  fmuls     f0, f4, f0
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x1BC
	  b         .loc_0x1C0

	.loc_0x1BC:
	  fneg      f2, f2

	.loc_0x1C0:
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x1D0
	  fmr       f0, f1
	  b         .loc_0x1E4

	.loc_0x1D0:
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x1E0
	  fadds     f0, f3, f0
	  b         .loc_0x1E4

	.loc_0x1E0:
	  fsubs     f0, f3, f0

	.loc_0x1E4:
	  stfs      f0, 0x20(r3)
	  lfs       f3, 0x24(r3)
	  addi      r3, r3, 0x4
	  lfs       f0, 0x28C(r4)
	  fsubs     f2, f3, f1
	  fmuls     f0, f4, f0
	  fcmpo     cr0, f2, f1
	  ble-      .loc_0x208
	  b         .loc_0x20C

	.loc_0x208:
	  fneg      f2, f2

	.loc_0x20C:
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x21C
	  fmr       f0, f1
	  b         .loc_0x230

	.loc_0x21C:
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x22C
	  fadds     f0, f3, f0
	  b         .loc_0x230

	.loc_0x22C:
	  fsubs     f0, f3, f0

	.loc_0x230:
	  stfs      f0, 0x20(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80156AF0
 * Size:	000154
 */
SpiderLeg::SpiderLeg(Spider* spider)
{
	mSpider                 = spider;
	mHalfDeadCallBackJoints = new SpiderGenHalfDeadCallBackJoint[4];
	mPerishCallBacks        = new SpiderGenPerishCallBack[12];
	mRippleCallBacks        = new SpiderGenRippleCallBack[4];
}

/*
 * --INFO--
 * Address:	80156C98
 * Size:	000190
 */
void SpiderLeg::init(Spider* spider)
{
	mSpider = spider;
	initParm(0);
	mInitialised = 1;
	mIsMoving    = 0;
	mCentreVelocity.set(0.0f, 0.0f, 0.0f);
	mCurrentCentre = mSpider->mPosition;

	for (int i = 0; i < 4; i++) {
		mStuckPikiCount[i]      = 0;
		mPrevOnGround[i]        = 0;
		mIsOnGround[i]          = false;
		mFootRaiseHeightList[i] = C_SPIDER_PROP(mSpider)._264();

		mJointPositions[i][0] = mSpider->mPosition;
		mBezierPoints[i][0]   = mJointPositions[i][0];
	}

	for (int i = 0; i < 16; i++) {
		mSegmentScale[i] = 1.0f;
	}
}

/*
 * --INFO--
 * Address:	80156E28
 * Size:	000090
 */
void SpiderLeg::initParm(int motionType)
{
	mMotionType            = (SpiderLegMotionType::Type)motionType;
	mSoundQueued           = 1;
	mBodyShakeStarted      = 0;
	mIsMoving              = 1;
	mMotionFinishFlag      = 0;
	mPrevShakeDirection    = 0;
	mShakeDirectionChanged = 0;
	for (int i = 0; i < 4; i++) {
		mLegMoving[i]         = 0;
		mLegCanMove[i]        = 0;
		mLegMidStep[i]        = 0;
		mLegMotionProgress[i] = 0.0f;
		mJointBlendFactor[i]  = 0.0f;
	}

	mLegCanMove[0]    = 1;
	mOscillationPhase = 0.0f;
	mShakePhase       = 0.0f;
	mShakeAngularVel  = 0.0f;
	mShakeAngle       = 0.0f;
}

/*
 * --INFO--
 * Address:	80156EB8
 * Size:	000168
 */
#pragma push
#pragma ppc_unroll_factor_limit 1
void SpiderLeg::setLegParameter()
{
	if (mSpider->getAlive()) {
		mPikiWeightOffset = mSpider->getStickPikiCount() * C_SPIDER_PROP(mSpider)._294();
		if (mPikiWeightOffset > C_SPIDER_PROP(mSpider)._2A4()) {
			mPikiWeightOffset = C_SPIDER_PROP(mSpider)._2A4();
		}
	} else {
		mPikiWeightOffset = 0.0f;
	}

	for (int i = 0; i < 4; i++) {
		f32 goal = C_SPIDER_PROP(mSpider)._264() - mStuckPikiCount[i] * C_SPIDER_PROP(mSpider)._274() - 0.5f * mPikiWeightOffset;
		mFootRaiseHeightList[i]
		    = NsLibMath<f32>::toGoal(mFootRaiseHeightList[i], goal, C_SPIDER_PROP(mSpider)._4A4() * gsys->getFrameTime());

		if (mFootRaiseHeightList[i] < C_SPIDER_PROP(mSpider)._284()) {
			mFootRaiseHeightList[i] = C_SPIDER_PROP(mSpider)._284();
		}
	}
}
#pragma pop

/*
 * --INFO--
 * Address:	80157020
 * Size:	000054
 */
void SpiderLeg::setWalkNewParameter()
{
	if (!mLegMoving[0] && mLegCanMove[0] && !mMotionFinishFlag) {
		if (mSpider->getLoopCounter() > mSpider->mActiveWalkCycleCount) {
			mMotionFinishFlag = 1;
		} else {
			mSpider->addLoopCounter(1);
		}
	}
}

/*
 * --INFO--
 * Address:	80157074
 * Size:	000138
 */
void SpiderLeg::setShakeOffNewParameter()
{
	if (mShakePhase < PI) {
		mPrevShakeDirection = mShakeDirectionChanged;
		mShakePhase += C_SPIDER_PROP(mSpider)._3F4() * gsys->getFrameTime();
		if (mShakePhase > HALF_PI) {
			mShakeDirectionChanged = 1;
		}
	} else {
		mShakePhase       = 0.0f;
		mMotionFinishFlag = 1;
	}

	mOscillationPhase += C_SPIDER_PROP(mSpider)._3E4() * gsys->getFrameTime();
	if (mOscillationPhase > TAU) {
		mOscillationPhase -= TAU;
	}

	mCurrentCentre.y += 1.5f * sinf(30.0f * mOscillationPhase);

	if (mSoundQueued && mSpider->mSeContext) {
		rumbleMgr->start(RUMBLE_Unk3, 0, mSpider->mPosition);
		mSpider->mSeContext->playSound(SE_SPIDER_SWING);
		mSoundQueued = false;
	}
}

/*
 * --INFO--
 * Address:	801571AC
 * Size:	0001B4
 */
void SpiderLeg::setBodyShakeNewParameter()
{
	if (!mBodyShakeStarted && mShakeAngle > C_SPIDER_PROP(mSpider)._434()) {
		mBodyShakeStarted = true;
		mOscillationPhase = C_SPIDER_PROP(mSpider)._424();
	}

	if (mBodyShakeStarted) {
		mPrevShakeDirection = mShakeDirectionChanged;
		f32 val             = -mShakeAngle;
		mShakeAngularVel *= mOscillationPhase;
		mShakeAngularVel += val * C_SPIDER_PROP(mSpider)._414();
		mShakeAngle += mShakeAngularVel;

		if (NsLibMath<f32>::abs(mShakeAngularVel) < 0.05f && NsLibMath<f32>::abs(mShakeAngle) < 0.05f) {
			mShakeAngle       = 0.0f;
			mShakeAngularVel  = 0.0f;
			mMotionFinishFlag = true;
		}
		if (mShakeAngularVel > 0.0f) {
			mShakeDirectionChanged = true;
		}

		if (mShakeDirectionChanged) {
			mOscillationPhase *= 0.97f;
		}

		if (mSoundQueued && mSpider->mSeContext) {
			rumbleMgr->start(RUMBLE_Unk3, 0, mSpider->mPosition);
			mSpider->mSeContext->playSound(SE_SPIDER_SWING);
			mSoundQueued = false;
		}
	} else {
		mShakeAngle += 1.5f * gsys->getFrameTime();
	}
}

/*
 * --INFO--
 * Address:	80157360
 * Size:	0003A4
 */
void SpiderLeg::setNextDirAndCent()
{
	if (!mLegMoving[0] && mLegCanMove[0] && !mMotionFinishFlag) {
		f32 centreDist = C_SPIDER_PROP(mSpider)._2B4()
		               + NsMathF::getRand(NsLibMath<f32>::abs(C_SPIDER_PROP(mSpider)._2C4() - C_SPIDER_PROP(mSpider)._2B4()));
		f32 dirChangeThreshold = C_SPIDER_PROP(mSpider)._2F4()
		                       + NsMathF::getRand(NsLibMath<f32>::abs(C_SPIDER_PROP(mSpider)._304() - C_SPIDER_PROP(mSpider)._2F4()));
		f32 distFactor = C_SPIDER_PROP(mSpider)._4D4()
		               + NsMathF::getRand(NsLibMath<f32>::abs(C_SPIDER_PROP(mSpider)._4E4() - C_SPIDER_PROP(mSpider)._4D4()));
		f32 factorThreshold
		    = qdist2(mSpider->mPosition.x, mSpider->mPosition.z, mSpider->getTargetPosition()->x, mSpider->getTargetPosition()->z);

		mSpider->mFaceDirection = NsMathF::roundAngle(mSpider->mFaceDirection);
		mTargetDirection
		    = atan2f(mSpider->getTargetPosition()->x - mSpider->mPosition.x, mSpider->getTargetPosition()->z - mSpider->mPosition.z);
		mTargetDirection = NsMathF::calcNearerDirection(mSpider->mFaceDirection, mTargetDirection);

		if (mTargetDirection > mSpider->mFaceDirection) {
			f32 diff = mTargetDirection - mSpider->mFaceDirection;
			if (diff < dirChangeThreshold) {
				if (diff > QUARTER_PI) {
					if (factorThreshold < C_SPIDER_PROP(mSpider)._4C4()) {
						centreDist *= distFactor;
					} else {
						centreDist = 0.0f;
					}
				}
			} else {
				mTargetDirection = mSpider->mFaceDirection + dirChangeThreshold;
				if (factorThreshold < C_SPIDER_PROP(mSpider)._4C4()) {
					centreDist *= distFactor;
				} else {
					centreDist = 0.0f;
				}
			}
		} else {
			f32 diff = mSpider->mFaceDirection - mTargetDirection;
			if (diff < dirChangeThreshold) {
				if (diff > QUARTER_PI) {
					if (factorThreshold < C_SPIDER_PROP(mSpider)._4C4()) {
						centreDist *= distFactor;
					} else {
						centreDist = 0.0f;
					}
				}
			} else {
				mTargetDirection = mSpider->mFaceDirection - dirChangeThreshold;
				if (factorThreshold < C_SPIDER_PROP(mSpider)._4C4()) {
					centreDist *= distFactor;
				} else {
					centreDist = 0.0f;
				}
			}
		}

		mTargetCentre.x = centreDist * sinf(mTargetDirection) + mSpider->mPosition.x;
		mTargetCentre.z = centreDist * cosf(mTargetDirection) + mSpider->mPosition.z;
		mTargetCentre.y = mapMgr->getMinY(mTargetCentre.x, mTargetCentre.z, true);
	}

	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	80157704
 * Size:	0002E8
 */
void SpiderLeg::setWalkNewPosition()
{
	for (int i = 0; i < 4; i++) {
		if (!mMotionFinishFlag && !mLegMoving[i] && mLegCanMove[i] && !mLegMidStep[i]) {
			Vector3f vec(0.0f, 0.0f, 0.0f);
			f32 vals[4] = { 1.75f, 1.25f, 0.25f, 0.75f };
			f32 angle   = mTargetDirection - PI * vals[i];
			f32 dist    = C_SPIDER_PROP(mSpider)._2D4()
			         + NsMathF::getRand(NsLibMath<f32>::abs(C_SPIDER_PROP(mSpider)._2E4() - C_SPIDER_PROP(mSpider)._2D4()));

			vec.x = dist * sinf(angle);
			vec.z = dist * cosf(angle);

			mBezierPoints[i][0].x = mJointPositions[i][0].x;
			mBezierPoints[i][0].y = mJointPositions[i][0].y;
			mBezierPoints[i][0].z = mJointPositions[i][0].z;

			mBezierPoints[i][2].x = mTargetCentre.x + vec.x;
			mBezierPoints[i][2].z = mTargetCentre.z + vec.z;

			f32 minY              = mapMgr->getMinY(mBezierPoints[i][2].x, mBezierPoints[i][2].z, true);
			mBezierPoints[i][2].y = minY - 10.0f;

			mBezierPoints[i][1].x = (mJointPositions[i][0].x + 4.0f * mBezierPoints[i][2].x) / 5.0f;
			mBezierPoints[i][1].z = (mJointPositions[i][0].z + 4.0f * mBezierPoints[i][2].z) / 5.0f;
			mBezierPoints[i][1].y = mSpider->mPosition.y + mFootRaiseHeightList[i];

			mIsOnGround[i]        = false;
			mLegCanMove[i]        = false;
			mLegMidStep[i]        = true;
			mLegMoving[i]         = true;
			mLegMotionProgress[i] = 0.0f;
		}

		if (mLegMoving[i]) {
			f32 goal              = mGroundHeight[i] + mFootRaiseHeightList[i];
			f32 step              = C_SPIDER_PROP(mSpider)._4B4() * gsys->getFrameTime();
			mBezierPoints[i][1].y = NsLibMath<f32>::toGoal(mBezierPoints[i][1].y, goal, step);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000210
 */
void SpiderLeg::checkGroundTimer()
{
	setLegParameter();
	if (mIsMoving) {
		switch (mMotionType) {
		case SpiderLegMotionType::Walk:
			setWalkNewParameter();
			setNextDirAndCent();
			setWalkNewPosition();
			break;
		case SpiderLegMotionType::ShakeOff:
			setShakeOffNewParameter();
			break;
		case SpiderLegMotionType::BodyShake:
			setBodyShakeNewParameter();
		}
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801579EC
 * Size:	000168
 */
void SpiderLeg::checkMotionRatio()
{
	if (mIsMoving) {
		for (int i = 0; i < 4; i++) {
			if (mLegMoving[i] && mMotionType < SpiderLegMotionType::ShakeOff) {
				f32 speed;
				if (mLegMotionProgress[i] < 1.1f) {
					speed = C_SPIDER_PROP(mSpider)._204() - mStuckPikiCount[i] * C_SPIDER_PROP(mSpider)._214();
					if (speed < C_SPIDER_PROP(mSpider)._224()) {
						speed = C_SPIDER_PROP(mSpider)._224();
					}
				} else {
					speed = C_SPIDER_PROP(mSpider)._234() + mStuckPikiCount[i] * C_SPIDER_PROP(mSpider)._244();
					if (speed > C_SPIDER_PROP(mSpider)._254()) {
						speed = C_SPIDER_PROP(mSpider)._254();
					}
				}

				mLegMotionProgress[i] += speed * gsys->getFrameTime();

				if (mLegMidStep[i] && mLegMotionProgress[i] > C_SPIDER_PROP(mSpider)._314()) {
					mLegCanMove[NsMathI::intLoop(i + 1, 0, 3)] = true;
					mLegMidStep[i]                             = false;
				}
			}
		}
	}

	// again? all the inlines seem good? idk man.
	STACK_PAD_VAR(2);
}

/*
 * --INFO--
 * Address:	80157B54
 * Size:	000168
 */
void SpiderLeg::makeNewPosition()
{
	static f32 vibSpin = 0.0f;
	if (mIsMoving) {
		vibSpin += 50.0f * gsys->getFrameTime();
		if (vibSpin > TAU) {
			vibSpin -= TAU;
		}

		for (int i = 0; i < 4; i++) {
			if (mLegMoving[i]) {
				NsCalculation::calcLagrange(mLegMotionProgress[i], mBezierPoints[i], mJointPositions[i][0]);

				f32 yOffs = mStuckPikiCount[i] * C_SPIDER_PROP(mSpider)._384() * sinf(vibSpin + i);
				if (yOffs > C_SPIDER_PROP(mSpider)._394()) {
					yOffs = C_SPIDER_PROP(mSpider)._394();
				}

				if (mLegMotionProgress[i] > 0.01f) {
					mJointPositions[i][0].y += yOffs;
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void SpiderLeg::calcSpiderDirection()
{
	if (mSpider->getCurrentState() < SPIDERAI_Start) {
		f32 x                = mJointPositions[0][0].x - mSpider->mPosition.x + mJointPositions[2][0].x - mSpider->mPosition.x;
		f32 z                = mJointPositions[0][0].z - mSpider->mPosition.z + mJointPositions[2][0].z - mSpider->mPosition.z;
		mSpider->mRotation.y = atan2f(x, z);
	}
	mSpider->mFaceDirection = mSpider->mRotation.y;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void SpiderLeg::calcShakeOffDirection()
{
	if (mMotionType == SpiderLegMotionType::BodyShake) {
		mSpider->mRotation.y += mShakeAngle;
		mSpider->mFaceDirection = mSpider->mRotation.y;
	}
}

/*
 * --INFO--
 * Address:	80157CBC
 * Size:	0001D0
 */
void SpiderLeg::calcStickersPiki()
{
	int i;
	for (i = 0; i < 4; i++) {
		mStuckPikiCount[i] = 0;
	}

	CollPart* boundPart = mSpider->mCollInfo->getBoundingSphere();
	int partCount       = boundPart->getChildCount();

	Stickers stuckList(mSpider);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki->isAlive()) {
			for (i = 0; i < partCount; i++) {
				if (boundPart->getChildAt(i)->getID().mId == piki->getStickPart()->getID().mId && Kumo::legId[i] >= 0) {
					mStuckPikiCount[Kumo::legId[i]]++;
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void SpiderLeg::calcShakeOff()
{
	if (mMotionType > SpiderLegMotionType::Walk && mShakeDirectionChanged && !mPrevShakeDirection) {
		mSpider->calcFlickPiki();
		mSpider->mSpiderAi->mCanFlick = false;
	}
}

/*
 * --INFO--
 * Address:	80157E8C
 * Size:	0002C0
 */
void SpiderLeg::setIdealCentre(Vector3f& centre)
{
	if (mSpider->getCurrentState() < SPIDERAI_Start) {
		Vector3f vec(0.0f, 0.0f, 0.0f);
		int i;
		for (i = 0; i < 4; i++) {
			centre.x += mJointPositions[i][0].x;
			centre.y += (mJointPositions[i][0].y - mBezierPoints[i][0].y) / 10.0f;
			centre.z += mJointPositions[i][0].z;
		}

		centre.x /= 4.0f;
		centre.z /= 4.0f;

		for (i = 0; i < 4; i++) {
			if (mIsOnGround[i]) {
				vec.x = mJointPositions[i][0].x - centre.x;
				vec.z = mJointPositions[i][0].z - centre.z;
				centre.x += C_SPIDER_PROP(mSpider)._3D4() * vec.x;
				centre.z += C_SPIDER_PROP(mSpider)._3D4() * vec.z;
			}
		}
	} else {
		centre.x = mSpider->getInitPosition()->x;
		centre.z = mSpider->getInitPosition()->z;
	}

	centre.y -= 15.0f + mPikiWeightOffset;
}

/*
 * --INFO--
 * Address:	8015814C
 * Size:	00020C
 */
void SpiderLeg::setRealCentre(Vector3f& centre)
{
	mCentreVelocity.multiply(C_SPIDER_PROP(mSpider)._3B4());

	mCentreVelocity.x += C_SPIDER_PROP(mSpider)._3A4() * (centre.x - mCurrentCentre.x);
	mCentreVelocity.y += C_SPIDER_PROP(mSpider)._3A4() * (centre.y - mCurrentCentre.y);
	mCentreVelocity.z += C_SPIDER_PROP(mSpider)._3A4() * (centre.z - mCurrentCentre.z);

	f32 dist = mCentreVelocity.length();

	if (dist > 6.0f) {
		mCentreVelocity.normalise();
		mCentreVelocity.multiply(6.0f);
	}

	mCurrentCentre.x += mCentreVelocity.x;
	mCurrentCentre.y += mCentreVelocity.y;
	mCurrentCentre.z += mCentreVelocity.z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000310
 */
void SpiderLeg::setCentrePosition()
{
	Vector3f centre(0.0f, mSpider->mPosition.y, 0.0f);
	setIdealCentre(centre);
	setRealCentre(centre);

	f32 dist = centre.distance(mCurrentCentre);
	if (dist > C_SPIDER_PROP(mSpider)._3C4()) {
		dist -= C_SPIDER_PROP(mSpider)._3C4();
		Vector3f dir(centre.x - mCurrentCentre.x, centre.y - mCurrentCentre.y, centre.z - mCurrentCentre.z);
		dir.normalise();
		dir.multiply(dist);
		mCurrentCentre.add(dir);
	}

	mSpider->mPosition.x = mCurrentCentre.x;
	mSpider->mPosition.z = mCurrentCentre.z;
}

/*
 * --INFO--
 * Address:	80158358
 * Size:	000174
 */
void SpiderLeg::updateAnimation(const BossShapeObject* shapeObj, Graphics& gfx, Matrix4f& animMtx)
{
	Matrix4f mtx1;
	Matrix4f mtx2;

	mtx2.makeSRT(mSpider->mScale, mSpider->mRotation, mCurrentCentre);
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx2, mtx1);

	mSpider->mAnimator.updateContext();

	shapeObj->mShape->updateAnim(gfx, mtx1, nullptr);

	gfx.mCamera->mLookAtMtx.inverse(&animMtx);

	if (mInitialised) {
		Matrix4f mtx3;
		Matrix4f mtx4;
		Matrix3f mtx33;

		shapeObj->mShape->getAnimMatrix(14).inverse(&mtx3);
		mtx3.multiplyTo(shapeObj->mShape->getAnimMatrix(15), mtx4);
		NsCalculation::calcMat4toMat3(mtx4, mtx33);

		mJointRotation.fromMat3f(mtx33);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void SpiderLeg::setJointMatrix(const BossShapeObject* shapeObj, Matrix4f& animMtx)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			animMtx.multiplyTo(shapeObj->mShape->getAnimMatrix(Kumo::leg_index[i][j]), mJointMatrices[i][j]);

			if (j != 0 || mSpider->getCurrentState() >= SPIDERAI_Start) {
				mJointMatrices[i][j].getColumn(3, mJointPositions[i][j]);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
void SpiderLeg::setLength()
{
	if (mSpider->getCurrentState() >= SPIDERAI_Start) {
		for (int i = 0; i < 4; i++) {
			mLegSegmentLength[i][0] = mJointPositions[i][0].distance(mJointPositions[i][1]);
			f32 dist2               = mJointPositions[i][1].distance(mJointPositions[i][2]);
			mLegSegmentLength[i][1] = dist2;
		}
	}
}

/*
 * --INFO--
 * Address:	801584CC
 * Size:	000130
 */
void SpiderLeg::getHeight()
{
	for (int i = 0; i < 4; i++) {
		mGroundHeight[i] = mapMgr->getMinY(mJointPositions[i][0].x, mJointPositions[i][0].z, true);

		f32 diff = mGroundHeight[i] - mJointPositions[i][0].y;
		if (diff > -5.0f) {
			mJointPositions[i][0].y += diff;
		}

		if (mIsMoving) {
			if (diff > -5.0f) {
				if (mLegMotionProgress[i] > 0.5f) {
					mLegMoving[i]  = false;
					mIsOnGround[i] = true;
				}
			} else if (mLegMotionProgress[i] < 0.5f) {
				mIsOnGround[i] = false;
			}
		} else if (diff > -5.0f) {
			mLegMoving[i]  = false;
			mIsOnGround[i] = true;
		} else {
			mIsOnGround[i] = false;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void SpiderLeg::getLegController()
{
	if (mIsMoving) {
		for (int i = 0; i < 4; i++) {
			if (mIsOnGround[i] && !mPrevOnGround[i] && mLegMidStep[i]) {
				mLegCanMove[NsMathI::intLoop(i + 1, 0, 3)] = true;
				mLegMidStep[i]                             = false;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void SpiderLeg::setQuatParameter()
{
	if (mIsMoving) {
		for (int i = 0; i < 4; i++) {
			f32 val              = (mJointPositions[i][0].y - mGroundHeight[i] - 50.0f) / 50.0f;
			mJointBlendFactor[i] = NsLibMath<f32>::revice(val, 0.0f, 1.0f);
		}
	}
}

/*
 * --INFO--
 * Address:	801585FC
 * Size:	000248
 */
void SpiderLeg::stepDamageNavi(int legNum)
{
	f32 heightCheck = mJointPositions[legNum][0].y + 2.0f;
	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi && navi->isAlive() && navi->isVisible() && !navi->isBuried() && heightCheck > navi->mPosition.y) {
			if (mJointPositions[legNum][0].distance(navi->mPosition) < C_SPIDER_PROP(mSpider)._324()) {
				InteractPress press(mSpider, C_SPIDER_PROP(mSpider)._334());
				navi->stimulate(press);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80158844
 * Size:	000230
 */
void SpiderLeg::stepDamagePiki(int legNum)
{
	Vector3f footPos(mJointPositions[legNum][0]);
	f32 heightAbove = mJointPositions[legNum][0].y + 2.0f;
	f32 heightBelow = mJointPositions[legNum][0].y - 10.0f;
	Iterator iter(pikiMgr);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki && piki->isAlive() && piki->isVisible() && !piki->isBuried() && piki->getStickObject() != mSpider
		    && piki->mPosition.y < heightAbove && piki->mPosition.y > heightBelow) {
			if (qdist2(piki->mPosition.x, piki->mPosition.z, footPos.x, footPos.z) < C_SPIDER_PROP(mSpider)._324()) {
				InteractPress press(mSpider, C_SPIDER_PROP(mSpider)._344());
				piki->stimulate(press);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80158A74
 * Size:	0002C4
 */
void SpiderLeg::stepShakeOffPiki(int legNum)
{
	int childCount      = 0;
	CollPart* boundPart = mSpider->mCollInfo->getBoundingSphere();
	if (boundPart) {
		childCount = boundPart->getChildCount();
	}

	Stickers stuckList(mSpider);
	Iterator iter(&stuckList);
	CI_LOOP(iter)
	{
		Creature* piki = *iter;
		if (piki && piki->isAlive()) {
			for (int i = 0; i < childCount; i++) {
				if (legNum == Kumo::legId[i] && piki->getStickPart() && boundPart && boundPart->getChildAt(i)
				    && boundPart->getChildAt(i)->getID().mId == piki->getStickPart()->getID().mId) {
					if (NsMathF::getRand(1.0f) < C_SPIDER_PROP(mSpider)._354()) {
						piki->stimulate(
						    InteractFlick(mSpider, C_SPIDER_PROP(mSpider)._364(), C_SPIDER_PROP(mSpider)._374(), FLICK_BACKWARDS_ANGLE));
						iter.dec();
					}
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80158D38
 * Size:	000140
 */
void SpiderLeg::emitOnGroundEffect(int legNum)
{
	if (mSpider->getMapAttribute(mJointPositions[legNum][0]) == ATTR_Water) {
		createRippleEffect(legNum);
	} else {
		effectMgr->create(EffectMgr::EFF_BigDustRing, mJointPositions[legNum][0], nullptr, nullptr);
	}

	if (mSpider->mIsHalfDead) {
		createHalfDeadFallEffect(legNum);
	}

	if (mSpider->mSeContext) {
		mSpider->mSeContext->playSound(SE_SPIDER_WALK);
	}

	rumbleMgr->start(RUMBLE_Unk14, 0, mJointPositions[legNum][0]);
	cameraMgr->startVibrationEvent(3, mJointPositions[legNum][0]);
	mCentreVelocity.y -= 1.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void SpiderLeg::onGroundFunction()
{
	for (int i = 0; i < 4; i++) {
		if (mIsOnGround[i] && !mPrevOnGround[i]) {
			stepDamageNavi(i);
			stepDamagePiki(i);
			stepShakeOffPiki(i);
			emitOnGroundEffect(i);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void SpiderLeg::emitOffGroundEffect()
{
	for (int i = 0; i < 4; i++) {
		if (!mIsOnGround[i] && mPrevOnGround[i]) {
			zen::particleGenerator* ptclGen1
			    = effectMgr->create(EffectMgr::EFF_Spider_OffGroundDebris, mJointPositions[i][0], nullptr, nullptr);
			if (ptclGen1) {
				ptclGen1->setEmitPosPtr(&mJointPositions[i][0]);
			}
			zen::particleGenerator* ptclGen2
			    = effectMgr->create(EffectMgr::EFF_Spider_OffGroundSmoke, mJointPositions[i][0], nullptr, nullptr);
			if (ptclGen2) {
				ptclGen2->setEmitPosPtr(&mJointPositions[i][0]);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80158E78
 * Size:	000270
 */
void SpiderLeg::setKneeDirection()
{
	f32 sinVal  = sinf(mShakePhase);
	f32 vals[4] = { 1.75f, 1.25f, 0.25f, 0.75f };

	for (int i = 0; i < 4; i++) {
		Vector3f vec1(0.0f, 0.0f, 0.0f);
		Vector3f vec2(0.0f, 0.0f, 0.0f);
		f32 angle = mSpider->mFaceDirection - PI * vals[i];
		vec1.x    = sinf(angle);
		vec1.z    = cosf(angle);
		vec1.normalise();

		vec2.x = mJointPositions[i][0].x - mCurrentCentre.x;
		vec2.z = mJointPositions[i][0].z - mCurrentCentre.z;
		vec2.normalise();

		mKneeDirection[i].x = 1.5f * vec1.x + vec2.x;
		mKneeDirection[i].y = 0.0f;
		mKneeDirection[i].z = 1.5f * vec1.z + vec2.z;

		mKneeDirection[i].normalise();
		mKneeDirection[i].y = 1.0f;

		if (mMotionType == SpiderLegMotionType::ShakeOff) {
			f32 ang  = atan2f(mKneeDirection[i].x, mKneeDirection[i].z);
			f32 ang2 = C_SPIDER_PROP(mSpider)._404() * sinVal * sinf(mOscillationPhase + 1.5f * i);

			mKneeDirection[i].x = sinf(ang + ang2);
			mKneeDirection[i].y = 1.0f;
			mKneeDirection[i].z = cosf(ang + ang2);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00028C
 */
void SpiderLeg::getJointMatrix(Vector3f& vec1, Vector3f& vec2, Vector3f& vec3, Matrix4f& animMtx)
{
	Vector3f xAxis(1.0f, 0.0f, 0.0f);
	Vector3f yAxis(0.0f, 1.0f, 0.0f);
	Vector3f zAxis(0.0f, 0.0f, 1.0f);

	xAxis.sub(vec2, vec1);
	NsCalculation::calcOuterPro(vec3, yAxis, zAxis);
	NsCalculation::calcOuterPro(zAxis, xAxis, yAxis);
	NsCalculation::calcOuterPro(xAxis, yAxis, zAxis);

	xAxis.normalise();
	yAxis.normalise();
	zAxis.normalise();

	NsCalculation::calcMatrix(xAxis, yAxis, zAxis, vec1, animMtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000184
 */
void SpiderLeg::calcQuatToMatrix(int legNum)
{
	if (mIsMoving && mJointBlendFactor[legNum] > 0.0f) {
		Matrix4f mtx1;
		Matrix4f mtx2;
		Quat q1;
		Matrix3f mtx33;

		mJointMatrices[legNum][1].inverse(&mtx1);
		mtx1.multiplyTo(mJointMatrices[legNum][0], mtx2);
		NsCalculation::calcMat4toMat3(mtx2, mtx33);
		q1.fromMat3f(mtx33);
		q1.slerp(mJointRotation, mJointBlendFactor[legNum], 0);
		mtx2.makeVQS(Vector3f(0.0f, 0.0f, 0.0f), q1, Vector3f(1.0f, 1.0f, 1.0f));
		mJointMatrices[legNum][1].multiplyTo(mtx2, mJointMatrices[legNum][0]);
	}
}

/*
 * --INFO--
 * Address:	801590E8
 * Size:	000684
 */
void SpiderLeg::create3Joint(BossShapeObject* shapeObj, Graphics& gfx)
{
	Vector3f vec;
	for (int i = 0; i < 4; i++) {
		NsCalculation::calcJointPos(mJointPositions[i][2], mJointPositions[i][0], mLegSegmentLength[i][1], mLegSegmentLength[i][0],
		                            mKneeDirection[i], mJointPositions[i][1]);
		vec.sub(mJointPositions[i][2], mJointPositions[i][0]);
		getJointMatrix(mJointPositions[i][2], mJointPositions[i][1], vec, mJointMatrices[i][2]);
		getJointMatrix(mJointPositions[i][1], mJointPositions[i][0], vec, mJointMatrices[i][1]);
		calcQuatToMatrix(i);
		mJointMatrices[i][0].setColumn(3, mJointPositions[i][0]);

		for (int j = 0; j < 3; j++) {
			gfx.mCamera->mLookAtMtx.multiplyTo(mJointMatrices[i][j], shapeObj->mShape->getAnimMatrix(Kumo::leg_index[i][j]));
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void SpiderLeg::createMatrixScale(BossShapeObject* shapeObj, Graphics& gfx)
{
	if (mSpider->getCurrentState() == SPIDERAI_Die) {
		Vector3f col;
		for (int i = 0; i <= 15; i++) {
			for (int j = 0; j < 3; j++) {
				shapeObj->mShape->getAnimMatrix(i).getColumn(j, col);
				col.multiply(mSegmentScale[i]);
				shapeObj->mShape->getAnimMatrix(i).setColumn(j, col);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderLeg::setGroundFlag()
{
	for (int i = 0; i < 4; i++) {
		mPrevOnGround[i] = mIsOnGround[i];
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void SpiderLeg::checkMotionFinished()
{
	if (mIsMoving) {
		for (int i = 0; i < 4; i++) {
			if (mMotionFinishFlag && !mLegMoving[i]) {
				mIsMoving = false;
			} else {
				mIsMoving = true;
				break;
			}
		}

		if (!mIsMoving) {
			mSpider->setMotionFinish(true);
		}
	}
}

/*
 * --INFO--
 * Address:	8015976C
 * Size:	0002EC
 */
void SpiderLeg::update()
{
	checkGroundTimer();
	checkMotionRatio();
	makeNewPosition();
	calcSpiderDirection();
	calcShakeOffDirection();
	calcStickersPiki();
	calcShakeOff();
	setCentrePosition();
}

/*
 * --INFO--
 * Address:	80159A58
 * Size:	0006A4
 */
void SpiderLeg::refresh(BossShapeObject* shapeObj, Graphics& gfx)
{
	Matrix4f animMtx;
	updateAnimation(shapeObj, gfx, animMtx);
	setJointMatrix(shapeObj, animMtx);
	setLength();
	getHeight();
	getLegController();
	setQuatParameter();
	onGroundFunction();
	emitOffGroundEffect();
	setKneeDirection();
	create3Joint(shapeObj, gfx);
	createMatrixScale(shapeObj, gfx);
	setGroundFlag();
	checkMotionFinished();
}
