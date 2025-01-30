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
	rumbleMgr->start(5, 0, mSpider->mPosition);
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
	int legVals[12] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	int boundedCount = NsLibMath<int>::revice(count, 1, 11);
	for (int i = 0; i < boundedCount; i++) {
		legVals[i] = 1;
	}

	// shuffle
	for (int i = 0; i < 12; i++) {
		int rand      = NsMathI::getRand1(12);
		int tmp       = legVals[i];
		legVals[i]    = legVals[rand];
		legVals[rand] = tmp;
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
	Vector3f footPos(_12C[legNum][0]);
	footPos.y -= 5.0f;
	effectMgr->create(EffectMgr::EFF_SmokeRing_M, _12C[legNum][0], nullptr, nullptr);
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
		effectMgr->killGenerator(&mHalfDeadCallBackJoints[i], nullptr, doForceFinish);
	}
	for (i = 0; i < 12; i++) {
		effectMgr->killGenerator(&mPerishCallBacks[i], nullptr, doForceFinish);
	}
	for (i = 0; i < 4; i++) {
		effectMgr->killGenerator(&mRippleCallBacks[i], nullptr, doForceFinish);
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
			_20[Kumo::leg_index[i][jointIdx]]
			    = NsLibMath<f32>::toGoal(_20[Kumo::leg_index[i][jointIdx]], 0.0f, gsys->getFrameTime() * stepTime);
		}
	} else {
		for (int i = 0; i < 4; i++) {
			_20[i] = NsLibMath<f32>::toGoal(_20[i], 0.0f, gsys->getFrameTime() * stepTime);
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
	_05 = 1;
	_08 = 0;
	_258.set(0.0f, 0.0f, 0.0f);
	_264 = mSpider->mPosition;

	for (int i = 0; i < 4; i++) {
		_E8[i]                  = 0;
		_11[i]                  = 0;
		mIsOnGround[i]          = false;
		mFootRaiseHeightList[i] = C_SPIDER_PROP(mSpider)._264();

		_12C[i][0] = mSpider->mPosition;
		_1BC[i][0] = _12C[i][0];
	}

	for (int i = 0; i < 16; i++) {
		_20[i] = 1.0f;
	}
}

/*
 * --INFO--
 * Address:	80156E28
 * Size:	000090
 */
void SpiderLeg::initParm(int p1)
{
	_F8 = p1;
	_04 = 1;
	_06 = 0;
	_08 = 1;
	_07 = 0;
	_1E = 0;
	_1D = 0;
	for (int i = 0; i < 4; i++) {
		_09[i] = 0;
		_15[i] = 0;
		_19[i] = 0;
		_A8[i] = 0.0f;
		_60[i] = 0.0f;
	}

	_15[0] = 1;
	_CC    = 0.0f;
	_C8    = 0.0f;
	_84    = 0.0f;
	_80    = 0.0f;
}

/*
 * --INFO--
 * Address:	80156EB8
 * Size:	000168
 */
void SpiderLeg::setLegParameter()
{
	if (mSpider->getAlive()) {
		_E0 = mSpider->getStickPikiCount() * C_SPIDER_PROP(mSpider)._294();
		if (_E0 > C_SPIDER_PROP(mSpider)._2A4()) {
			_E0 = C_SPIDER_PROP(mSpider)._2A4();
		}
	} else {
		_E0 = 0.0f;
	}

	for (int i = 0; i < 4; i++) {
		f32 goal = C_SPIDER_PROP(mSpider)._264() - _E8[i] * C_SPIDER_PROP(mSpider)._274() - 0.5f * _E0;
		mFootRaiseHeightList[i]
		    = NsLibMath<f32>::toGoal(mFootRaiseHeightList[i], goal, C_SPIDER_PROP(mSpider)._4A4() * gsys->getFrameTime());

		if (mFootRaiseHeightList[i] < C_SPIDER_PROP(mSpider)._284()) {
			mFootRaiseHeightList[i] = C_SPIDER_PROP(mSpider)._284();
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stw       r31, 0x8C(r1)
	  mr        r31, r3
	  stw       r30, 0x88(r1)
	  lwz       r30, 0x0(r3)
	  lfs       f0, -0x568C(r2)
	  lfs       f1, 0x2C4(r30)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x80
	  mr        r3, r30
	  bl        -0x7E9C
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x224(r30)
	  stw       r0, 0x84(r1)
	  lis       r0, 0x4330
	  lfd       f2, -0x5668(r2)
	  stw       r0, 0x80(r1)
	  lfs       f0, 0x2A0(r3)
	  lfd       f1, 0x80(r1)
	  fsubs     f1, f1, f2
	  fmuls     f0, f1, f0
	  stfs      f0, 0xE0(r31)
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0xE0(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x2B0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x84
	  stfs      f0, 0xE0(r31)
	  b         .loc_0x84

	.loc_0x80:
	  stfs      f0, 0xE0(r31)

	.loc_0x84:
	  li        r0, 0x4
	  lfd       f7, -0x5668(r2)
	  mtctr     r0
	  lfs       f4, -0x5690(r2)
	  lwz       r4, 0x2DEC(r13)
	  mr        r6, r31
	  lfs       f2, -0x568C(r2)
	  lis       r0, 0x4330

	.loc_0xA4:
	  lwz       r3, 0xE8(r6)
	  lfs       f0, 0xE0(r31)
	  xoris     r3, r3, 0x8000
	  lwz       r5, 0x0(r31)
	  stw       r3, 0x84(r1)
	  fmuls     f3, f4, f0
	  lwz       r5, 0x224(r5)
	  stw       r0, 0x80(r1)
	  lfs       f5, 0x280(r5)
	  lfd       f0, 0x80(r1)
	  lfs       f8, 0x270(r5)
	  fsubs     f6, f0, f7
	  lfs       f1, 0x4B0(r5)
	  lfs       f0, 0x28C(r4)
	  lfs       f9, 0xD0(r6)
	  fmuls     f5, f6, f5
	  fmuls     f1, f1, f0
	  fsubs     f0, f8, f5
	  fsubs     f3, f0, f3
	  fsubs     f0, f9, f3
	  fcmpo     cr0, f0, f2
	  ble-      .loc_0x100
	  b         .loc_0x104

	.loc_0x100:
	  fneg      f0, f0

	.loc_0x104:
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x114
	  fmr       f0, f3
	  b         .loc_0x128

	.loc_0x114:
	  fcmpo     cr0, f9, f3
	  bge-      .loc_0x124
	  fadds     f0, f9, f1
	  b         .loc_0x128

	.loc_0x124:
	  fsubs     f0, f9, f1

	.loc_0x128:
	  stfs      f0, 0xD0(r6)
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0xD0(r6)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x290(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x148
	  stfs      f0, 0xD0(r6)

	.loc_0x148:
	  addi      r6, r6, 0x4
	  bdnz+     .loc_0xA4
	  lwz       r0, 0x94(r1)
	  lwz       r31, 0x8C(r1)
	  lwz       r30, 0x88(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80157020
 * Size:	000054
 */
void SpiderLeg::setWalkNewParameter()
{
	if (!_09[0] && _15[0] && !_07) {
		if (mSpider->getLoopCounter() > mSpider->_3BC) {
			_07 = 1;
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
	if (_C8 < PI) {
		_1E = _1D;
		_C8 += C_SPIDER_PROP(mSpider)._3F4() * gsys->getFrameTime();
		if (_C8 > HALF_PI) {
			_1D = 1;
		}
	} else {
		_C8 = 0.0f;
		_07 = 1;
	}

	_CC += C_SPIDER_PROP(mSpider)._3E4() * gsys->getFrameTime();
	if (_CC > TAU) {
		_CC -= TAU;
	}

	_264.y += 1.5f * sinf(30.0f * _CC);

	if (_04 && mSpider->mSeContext) {
		rumbleMgr->start(3, 0, mSpider->mPosition);
		mSpider->mSeContext->playSound(SE_SPIDER_SWING);
		_04 = false;
	}
}

/*
 * --INFO--
 * Address:	801571AC
 * Size:	0001B4
 */
void SpiderLeg::setBodyShakeNewParameter()
{
	if (!_06 && _80 > C_SPIDER_PROP(mSpider)._434()) {
		_06 = true;
		_CC = C_SPIDER_PROP(mSpider)._424();
	}

	if (_06) {
		_1E     = _1D;
		f32 val = -_80;
		_84 *= _CC;
		_84 += val * C_SPIDER_PROP(mSpider)._414();
		_80 += _84;

		if (NsLibMath<f32>::abs(_84) < 0.05f && NsLibMath<f32>::abs(_80) < 0.05f) {
			_80 = 0.0f;
			_84 = 0.0f;
			_07 = true;
		}
		if (_84 > 0.0f) {
			_1D = true;
		}

		if (_1D) {
			_CC *= 0.97f;
		}

		if (_04 && mSpider->mSeContext) {
			rumbleMgr->start(3, 0, mSpider->mPosition);
			mSpider->mSeContext->playSound(SE_SPIDER_SWING);
			_04 = false;
		}
	} else {
		_80 += 1.5f * gsys->getFrameTime();
	}
}

/*
 * --INFO--
 * Address:	80157360
 * Size:	0003A4
 */
void SpiderLeg::setNextDirAndCent()
{
	if (!_09[0] && _15[0] && !_07) {
		f32 centreDist = C_SPIDER_PROP(mSpider)._2B4()
		               + NsMathF::getRand1(NsLibMath<f32>::abs(C_SPIDER_PROP(mSpider)._2C4() - C_SPIDER_PROP(mSpider)._2B4()));
		f32 dirChangeThreshold = C_SPIDER_PROP(mSpider)._2F4()
		                       + NsMathF::getRand1(NsLibMath<f32>::abs(C_SPIDER_PROP(mSpider)._304() - C_SPIDER_PROP(mSpider)._2F4()));
		f32 distFactor = C_SPIDER_PROP(mSpider)._4D4()
		               + NsMathF::getRand1(NsLibMath<f32>::abs(C_SPIDER_PROP(mSpider)._4E4() - C_SPIDER_PROP(mSpider)._4D4()));
		f32 factorThreshold
		    = qdist2(mSpider->mPosition.x, mSpider->mPosition.z, mSpider->getTargetPosition()->x, mSpider->getTargetPosition()->z);

		mSpider->mFaceDirection = NsMathF::roundAngle(mSpider->mFaceDirection);
		_E4 = atan2f(mSpider->getTargetPosition()->x - mSpider->mPosition.x, mSpider->getTargetPosition()->z - mSpider->mPosition.z);
		_E4 = NsMathF::calcNearerDirection(mSpider->mFaceDirection, _E4);

		if (_E4 > mSpider->mFaceDirection) {
			f32 diff = _E4 - mSpider->mFaceDirection;
			if (diff < dirChangeThreshold) {
				if (diff > QUARTER_PI) {
					if (factorThreshold < C_SPIDER_PROP(mSpider)._4C4()) {
						centreDist *= distFactor;
					} else {
						centreDist = 0.0f;
					}
				}
			} else {
				_E4 = mSpider->mFaceDirection + dirChangeThreshold;
				if (factorThreshold < C_SPIDER_PROP(mSpider)._4C4()) {
					centreDist *= distFactor;
				} else {
					centreDist = 0.0f;
				}
			}
		} else {
			f32 diff = mSpider->mFaceDirection - _E4;
			if (diff < dirChangeThreshold) {
				if (diff > QUARTER_PI) {
					if (factorThreshold < C_SPIDER_PROP(mSpider)._4C4()) {
						centreDist *= distFactor;
					} else {
						centreDist = 0.0f;
					}
				}
			} else {
				_E4 = mSpider->mFaceDirection - dirChangeThreshold;
				if (factorThreshold < C_SPIDER_PROP(mSpider)._4C4()) {
					centreDist *= distFactor;
				} else {
					centreDist = 0.0f;
				}
			}
		}

		_24C.x = centreDist * sinf(_E4) + mSpider->mPosition.x;
		_24C.z = centreDist * cosf(_E4) + mSpider->mPosition.z;
		_24C.y = mapMgr->getMinY(_24C.x, _24C.z, true);
	}

	f32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	80157704
 * Size:	0002E8
 */
void SpiderLeg::setWalkNewPosition()
{
	for (int i = 0; i < 4; i++) {
		if (!_07 && !_09[i] && _15[i] && !_19[i]) {
			Vector3f vec(0.0f, 0.0f, 0.0f);
			f32 vals[4] = { 1.75f, 1.25f, 0.25f, 0.75f };
			f32 angle   = _E4 - PI * vals[i];
			f32 dist    = C_SPIDER_PROP(mSpider)._2D4()
			         + NsMathF::getRand1(NsLibMath<f32>::abs(C_SPIDER_PROP(mSpider)._2E4() - C_SPIDER_PROP(mSpider)._2D4()));

			vec.x = dist * sinf(angle);
			vec.z = dist * cosf(angle);

			_1BC[i][0].x = _12C[i][0].x;
			_1BC[i][0].y = _12C[i][0].y;
			_1BC[i][0].z = _12C[i][0].z;

			_1BC[i][2].x = _24C.x + vec.x;
			_1BC[i][2].z = _24C.z + vec.z;

			f32 minY     = mapMgr->getMinY(_1BC[i][2].x, _1BC[i][2].z, true);
			_1BC[i][2].y = minY - 10.0f;

			_1BC[i][1].x = (_12C[i][0].x + 4.0f * _1BC[i][2].x) / 5.0f;
			_1BC[i][1].z = (_12C[i][0].z + 4.0f * _1BC[i][2].z) / 5.0f;
			_1BC[i][1].y = mSpider->mPosition.y + mFootRaiseHeightList[i];

			mIsOnGround[i] = false;
			_15[i]         = false;
			_19[i]         = true;
			_09[i]         = true;
			_A8[i]         = 0.0f;
		}

		if (_09[i]) {
			f32 goal     = _70[i] + mFootRaiseHeightList[i];
			_1BC[i][1].y = NsLibMath<f32>::toGoal(_1BC[i][1].y, goal, C_SPIDER_PROP(mSpider)._4B4() * gsys->getFrameTime());
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
	if (_08) {
		switch (_F8) {
		case 0:
			setWalkNewParameter();
			setNextDirAndCent();
			setWalkNewPosition();
			break;
		case 1:
			setShakeOffNewParameter();
			break;
		case 2:
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
	if (_08) {
		for (int i = 0; i < 4; i++) {
			if (_09[i] && _F8 < 1) {
				f32 speed;
				if (_A8[i] < 1.1f) {
					speed = C_SPIDER_PROP(mSpider)._204() - _E8[i] * C_SPIDER_PROP(mSpider)._214();
					if (speed < C_SPIDER_PROP(mSpider)._224()) {
						speed = C_SPIDER_PROP(mSpider)._224();
					}
				} else {
					speed = C_SPIDER_PROP(mSpider)._234() + _E8[i] * C_SPIDER_PROP(mSpider)._244();
					if (speed > C_SPIDER_PROP(mSpider)._254()) {
						speed = C_SPIDER_PROP(mSpider)._254();
					}
				}

				_A8[i] += speed * gsys->getFrameTime();

				if (_19[i] && _A8[i] > C_SPIDER_PROP(mSpider)._314()) {
					_15[NsMathI::intLoop(i + 1, 0, 3)] = true;
					_19[i]                             = false;
				}
			}
		}
	}

	// again? all the inlines seem good? idk man.
	f32 badCompiler[2];
}

/*
 * --INFO--
 * Address:	80157B54
 * Size:	000168
 */
void SpiderLeg::makeNewPosition()
{
	static f32 vibSpin = 0.0f;
	if (_08) {
		vibSpin += 50.0f * gsys->getFrameTime();
		if (vibSpin > TAU) {
			vibSpin -= TAU;
		}

		for (int i = 0; i < 4; i++) {
			if (_09[i]) {
				NsCalculation::calcLagrange(_A8[i], _1BC[i], _12C[i][0]);

				f32 yOffs = _E8[i] * C_SPIDER_PROP(mSpider)._384() * sinf(vibSpin + i);
				if (yOffs > C_SPIDER_PROP(mSpider)._394()) {
					yOffs = C_SPIDER_PROP(mSpider)._394();
				}

				if (_A8[i] > 0.01f) {
					_12C[i][0].y += yOffs;
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
		f32 x                = _12C[0][0].x - mSpider->mPosition.x + _12C[2][0].x - mSpider->mPosition.x;
		f32 z                = _12C[0][0].z - mSpider->mPosition.z + _12C[2][0].z - mSpider->mPosition.z;
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
	if (_F8 == 2) {
		mSpider->mRotation.y += _80;
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
		_E8[i] = 0;
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
					_E8[Kumo::legId[i]]++;
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
	if (_F8 > 0 && _1D && !_1E) {
		mSpider->calcFlickPiki();
		mSpider->mSpiderAi->_08 = false;
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
			centre.x += _12C[i][0].x;
			centre.y += (_12C[i][0].y - _1BC[i][0].y) / 10.0f;
			centre.z += _12C[i][0].z;
		}

		centre.x /= 4.0f;
		centre.z /= 4.0f;

		for (i = 0; i < 4; i++) {
			if (mIsOnGround[i]) {
				vec.x = _12C[i][0].x - centre.x;
				vec.z = _12C[i][0].z - centre.z;
				centre.x += C_SPIDER_PROP(mSpider)._3D4() * vec.x;
				centre.z += C_SPIDER_PROP(mSpider)._3D4() * vec.z;
			}
		}
	} else {
		centre.x = mSpider->getInitPosition()->x;
		centre.z = mSpider->getInitPosition()->z;
	}

	centre.y -= 15.0f + _E0;
}

/*
 * --INFO--
 * Address:	8015814C
 * Size:	00020C
 */
void SpiderLeg::setRealCentre(Vector3f& centre)
{
	_258.multiply(C_SPIDER_PROP(mSpider)._3B4());

	_258.x += C_SPIDER_PROP(mSpider)._3A4() * (centre.x - _264.x);
	_258.y += C_SPIDER_PROP(mSpider)._3A4() * (centre.y - _264.y);
	_258.z += C_SPIDER_PROP(mSpider)._3A4() * (centre.z - _264.z);

	f32 dist = _258.length();

	if (dist > 0.0f) {
		_258.normalise();
		_258.multiply(6.0f);
	}

	_264.x += _258.x;
	_264.y += _258.y;
	_264.z += _258.z;
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

	f32 dist = centre.distance(_264);
	if (dist > C_SPIDER_PROP(mSpider)._3C4()) {
		dist -= C_SPIDER_PROP(mSpider)._3C4();
		Vector3f dir(centre.x - _264.x, centre.y - _264.y, centre.z - _264.z);
		dir.normalise();
		dir.multiply(dist);
		_264.add(dir);
	}

	mSpider->mPosition.x = _264.x;
	mSpider->mPosition.z = _264.z;
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

	mtx2.makeSRT(mSpider->mScale, mSpider->mRotation, _264);
	gfx.mCamera->mLookAtMtx.multiplyTo(mtx2, mtx1);

	mSpider->mAnimator.updateContext();

	shapeObj->mShape->updateAnim(gfx, mtx1, nullptr);

	gfx.mCamera->mLookAtMtx.inverse(&animMtx);

	if (_05) {
		Matrix4f mtx3;
		Matrix4f mtx4;
		Matrix3f mtx33;

		shapeObj->mShape->getAnimMatrix(14).inverse(&mtx3);
		mtx3.multiplyTo(shapeObj->mShape->getAnimMatrix(15), mtx4);
		NsCalculation::calcMat4toMat3(mtx4, mtx33);

		_270.fromMat3f(mtx33);
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
			animMtx.multiplyTo(shapeObj->mShape->getAnimMatrix(Kumo::leg_index[i][j]), _280[i][j]);

			if (j != 0 || mSpider->getCurrentState() >= SPIDERAI_Start) {
				_280[i][j].getColumn(3, _12C[i][j]);
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
			_88[i][0] = _12C[i][0].distance(_12C[i][1]);
			f32 dist2 = _12C[i][1].distance(_12C[i][2]);
			_88[i][1] = dist2;
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
		_70[i] = mapMgr->getMinY(_12C[i][0].x, _12C[i][0].z, true);

		f32 diff = _70[i] - _12C[i][0].y;
		if (diff > -5.0f) {
			_12C[i][0].y += diff;
		}

		if (_08) {
			if (diff > -5.0f) {
				if (_A8[i] > 0.5f) {
					_09[i]         = false;
					mIsOnGround[i] = true;
				}
			} else if (_A8[i] < 0.5f) {
				mIsOnGround[i] = false;
			}
		} else if (diff > -5.0f) {
			_09[i]         = false;
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
	if (_08) {
		for (int i = 0; i < 4; i++) {
			if (mIsOnGround[i] && !_11[i] && _19[i]) {
				_15[NsMathI::intLoop(i + 1, 0, 3)] = true;
				_19[i]                             = false;
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
	if (_08) {
		for (int i = 0; i < 4; i++) {
			f32 val = (_12C[i][0].y - _70[i] - 50.0f) / 50.0f;
			_60[i]  = NsLibMath<f32>::revice(val, 0.0f, 1.0f);
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
	f32 heightCheck = _12C[legNum][0].y + 2.0f;
	Iterator iter(naviMgr);
	CI_LOOP(iter)
	{
		Creature* navi = *iter;
		if (navi && navi->isAlive() && navi->isVisible() && !navi->isBuried() && heightCheck > navi->mPosition.y) {
			if (_12C[legNum][0].distance(navi->mPosition) < C_SPIDER_PROP(mSpider)._324()) {
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
	Vector3f footPos(_12C[legNum][0]);
	f32 heightAbove = _12C[legNum][0].y + 2.0f;
	f32 heightBelow = _12C[legNum][0].y - 10.0f;
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
					if (NsMathF::getRand1(1.0f) < C_SPIDER_PROP(mSpider)._354()) {
						f32 damage = C_SPIDER_PROP(mSpider)._374();
						piki->stimulate(InteractFlick(mSpider, C_SPIDER_PROP(mSpider)._364(), damage, FLICK_BACKWARDS_ANGLE));
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
	if (mSpider->getMapAttribute(_12C[legNum][0]) == ATTR_Water) {
		createRippleEffect(legNum);
	} else {
		effectMgr->create(EffectMgr::EFF_BigDustRing, _12C[legNum][0], nullptr, nullptr);
	}

	if (mSpider->_3BA) {
		createHalfDeadFallEffect(legNum);
	}

	if (mSpider->mSeContext) {
		mSpider->mSeContext->playSound(SE_SPIDER_WALK);
	}

	rumbleMgr->start(14, 0, _12C[legNum][0]);
	cameraMgr->startVibrationEvent(3, _12C[legNum][0]);
	_258.y -= 1.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void SpiderLeg::onGroundFunction()
{
	for (int i = 0; i < 4; i++) {
		if (mIsOnGround[i] && !_11[i]) {
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
		if (!mIsOnGround[i] && _11[i]) {
			zen::particleGenerator* ptclGen1 = effectMgr->create(EffectMgr::EFF_Spider_OffGroundDebris, _12C[i][0], nullptr, nullptr);
			if (ptclGen1) {
				ptclGen1->setEmitPosPtr(&_12C[i][0]);
			}
			zen::particleGenerator* ptclGen2 = effectMgr->create(EffectMgr::EFF_Spider_OffGroundSmoke, _12C[i][0], nullptr, nullptr);
			if (ptclGen2) {
				ptclGen2->setEmitPosPtr(&_12C[i][0]);
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
	f32 sinVal  = sinf(_C8);
	f32 vals[4] = { 1.75f, 1.25f, 0.25f, 0.75f };

	for (int i = 0; i < 4; i++) {
		Vector3f vec1(0.0f, 0.0f, 0.0f);
		Vector3f vec2(0.0f, 0.0f, 0.0f);
		f32 angle = mSpider->mFaceDirection - PI * vals[i];
		vec1.x    = sinf(angle);
		vec1.z    = cosf(angle);
		vec1.normalise();

		vec2.x = _12C[i][0].x - _264.x;
		vec2.z = _12C[i][0].z - _264.z;
		vec2.normalise();

		_FC[i].x = 1.5f * vec1.x + vec2.x;
		_FC[i].y = 0.0f;
		_FC[i].z = 1.5f * vec1.z + vec2.z;

		_FC[i].normalise();
		_FC[i].y = 1.0f;

		if (_F8 == 1) {
			f32 ang  = atan2f(_FC[i].x, _FC[i].z);
			f32 ang2 = C_SPIDER_PROP(mSpider)._404() * sinVal * sinf(_CC + 1.5f * i);

			_FC[i].x = sinf(ang + ang2);
			_FC[i].y = 1.0f;
			_FC[i].z = cosf(ang + ang2);
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
	if (_08 && _60[legNum] > 0.0f) {
		Matrix4f mtx1;
		Matrix4f mtx2;
		Quat q1;
		Matrix3f mtx33;

		_280[legNum][1].inverse(&mtx1);
		mtx1.multiplyTo(_280[legNum][0], mtx2);
		NsCalculation::calcMat4toMat3(mtx2, mtx33);
		q1.fromMat3f(mtx33);
		q1.slerp(_270, _60[legNum], 0);
		mtx2.makeVQS(Vector3f(0.0f, 0.0f, 0.0f), q1, Vector3f(1.0f, 1.0f, 1.0f));
		_280[legNum][1].multiplyTo(mtx2, _280[legNum][0]);
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
		NsCalculation::calcJointPos(_12C[i][2], _12C[i][0], _88[i][1], _88[i][0], _FC[i], _12C[i][1]);
		vec.sub(_12C[i][2], _12C[i][0]);
		getJointMatrix(_12C[i][2], _12C[i][1], vec, _280[i][2]);
		getJointMatrix(_12C[i][1], _12C[i][0], vec, _280[i][1]);
		calcQuatToMatrix(i);
		_280[i][0].setColumn(3, _12C[i][0]);

		for (int j = 0; j < 3; j++) {
			gfx.mCamera->mLookAtMtx.multiplyTo(_280[i][j], shapeObj->mShape->getAnimMatrix(Kumo::leg_index[i][j]));
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
				col.multiply(_20[i]);
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
		_11[i] = mIsOnGround[i];
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void SpiderLeg::checkMotionFinished()
{
	if (_08) {
		for (int i = 0; i < 4; i++) {
			if (_07 && !_09[i]) {
				_08 = false;
			} else {
				_08 = true;
				break;
			}
		}

		if (!_08) {
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
