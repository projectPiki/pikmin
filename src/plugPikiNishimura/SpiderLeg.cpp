#include "Spider.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "NsMath.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"
#include "DebugLog.h"

namespace Kumo {
static int leg_index[4][3] = {
	{ 12, 11, 10 },
	{ 15, 14, 13 },
	{ 6, 5, 4 },
	{ 9, 8, 7 },
};

static int legId[3][3] = {
	{ 3, 2, 0 },
	{ 1, -1, 2 },
	{ 3, 0, 1 },
};
} // namespace Kumo

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
			effectMgr->create(EffectMgr::EFF_Unk184, mSpider->mPosition, &mHalfDeadCallBackJoints[legNum], nullptr);
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

		zen::particleGenerator* ptclGen = effectMgr->create(EffectMgr::EFF_Unk183, mSpider->mPosition, nullptr, nullptr);
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

		zen::particleGenerator* ptclGen1 = effectMgr->create(EffectMgr::EFF_Unk186, midPt, nullptr, nullptr);
		if (ptclGen1) {
			ptclGen1->setEmitDir(dir);
		}

		zen::particleGenerator* ptclGen2 = effectMgr->create(EffectMgr::EFF_Unk185, midPt, nullptr, nullptr);
		if (ptclGen2) {
			ptclGen2->setEmitDir(dir);
		}

		effectMgr->create(EffectMgr::EFF_Unk189, legPart->mCentre, nullptr, nullptr);

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
			effectMgr->create(EffectMgr::EFF_Unk190, legPart->mCentre, nullptr, nullptr);
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
		effectMgr->create(EffectMgr::EFF_Unk192, mSpider->mPosition, &mPerishCallBacks[i + p2], nullptr);
		effectMgr->create(EffectMgr::EFF_Unk191, mSpider->mPosition, &mPerishCallBacks[i + p2], nullptr);
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
	effectMgr->create(EffectMgr::EFF_Unk189, body->mCentre, nullptr, nullptr);
	rumbleMgr->start(5, 0, mSpider->mPosition);
	if (mSpider->mSeContext) {
		mSpider->mSeContext->playSound(0x2C);
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

	int boundedCount = NsMathI::intLoop(count, 1, 11);
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
		mSpider->mSeContext->playSound(0x2D);
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
	effectMgr->create(EffectMgr::EFF_Unk67, _12C[legNum][0], nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Unk85, footPos, nullptr, nullptr);
	mRippleCallBacks[legNum].set(&_0D[legNum]);

	zen::particleGenerator* ptclGen1 = effectMgr->create(EffectMgr::EFF_Unk14, footPos, &mRippleCallBacks[legNum], nullptr);
	if (ptclGen1) {
		f32 scale = ptclGen1->getScaleSize();
		ptclGen1->setScaleSize(3.0f * scale);
	}
	zen::particleGenerator* ptclGen2 = effectMgr->create(EffectMgr::EFF_Unk12, footPos, &mRippleCallBacks[legNum], nullptr);
	if (ptclGen2) {
		f32 scale = ptclGen2->getScaleSize();
		ptclGen2->setScaleSize(3.0f * scale);
	}
	zen::particleGenerator* ptclGen3 = effectMgr->create(EffectMgr::EFF_Unk13, footPos, &mRippleCallBacks[legNum], nullptr);
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
		_E8[i] = 0;
		_11[i] = 0;
		_0D[i] = false;
		_D0[i] = C_SPIDER_PROP(mSpider)._264();

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
		_D0[i]   = NsLibMath<f32>::toGoal(_D0[i], goal, C_SPIDER_PROP(mSpider)._4A4() * gsys->getFrameTime());

		if (_D0[i] < C_SPIDER_PROP(mSpider)._284()) {
			_D0[i] = C_SPIDER_PROP(mSpider)._284();
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
	/*
	.loc_0x0:
	  lbz       r0, 0x9(r3)
	  cmplwi    r0, 0
	  bnelr-
	  lbz       r0, 0x15(r3)
	  cmplwi    r0, 0
	  beqlr-
	  lbz       r0, 0x7(r3)
	  cmplwi    r0, 0
	  bnelr-
	  lwz       r4, 0x0(r3)
	  addi      r5, r4, 0x2EC
	  lwz       r0, 0x3BC(r4)
	  lwz       r4, 0x2EC(r4)
	  cmpw      r4, r0
	  ble-      .loc_0x48
	  li        r0, 0x1
	  stb       r0, 0x7(r3)
	  blr

	.loc_0x48:
	  addi      r0, r4, 0x1
	  stw       r0, 0x0(r5)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80157074
 * Size:	000138
 */
void SpiderLeg::setShakeOffNewParameter()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r3
	  lfs       f0, -0x5658(r2)
	  lfs       f1, 0xC8(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x6C
	  lbz       r0, 0x1D(r31)
	  stb       r0, 0x1E(r31)
	  lwz       r4, 0x0(r31)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x224(r4)
	  lfs       f0, 0x28C(r3)
	  lfs       f1, 0x400(r4)
	  lfs       f2, 0xC8(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC8(r31)
	  lfs       f1, 0xC8(r31)
	  lfs       f0, -0x5654(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x7C
	  li        r0, 0x1
	  stb       r0, 0x1D(r31)
	  b         .loc_0x7C

	.loc_0x6C:
	  lfs       f0, -0x568C(r2)
	  li        r0, 0x1
	  stfs      f0, 0xC8(r31)
	  stb       r0, 0x7(r31)

	.loc_0x7C:
	  lwz       r4, 0x0(r31)
	  lwz       r3, 0x2DEC(r13)
	  lwz       r4, 0x224(r4)
	  lfs       f0, 0x28C(r3)
	  lfs       f1, 0x3F0(r4)
	  lfs       f2, 0xCC(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xCC(r31)
	  lfs       f1, 0xCC(r31)
	  lfs       f0, -0x5650(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xB8
	  fsubs     f0, f1, f0
	  stfs      f0, 0xCC(r31)

	.loc_0xB8:
	  lfs       f1, -0x5648(r2)
	  lfs       f0, 0xCC(r31)
	  fmuls     f1, f1, f0
	  bl        0xC4BB0
	  lfs       f2, -0x564C(r2)
	  lfs       f0, 0x268(r31)
	  fmuls     f1, f2, f1
	  fadds     f0, f0, f1
	  stfs      f0, 0x268(r31)
	  lbz       r0, 0x4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  lwz       r4, 0x0(r31)
	  lwz       r0, 0x2C(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x124
	  lwz       r3, 0x3178(r13)
	  addi      r6, r4, 0x94
	  li        r4, 0x3
	  li        r5, 0
	  bl        0x25C58
	  lwz       r3, 0x0(r31)
	  li        r4, 0x2B
	  lwz       r3, 0x2C(r3)
	  bl        -0xB33BC
	  li        r0, 0
	  stb       r0, 0x4(r31)

	.loc_0x124:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801571AC
 * Size:	0001B4
 */
void SpiderLeg::setBodyShakeNewParameter()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  lbz       r0, 0x6(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x50
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0x80(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x440(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x50
	  li        r0, 0x1
	  stb       r0, 0x6(r31)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x430(r3)
	  stfs      f0, 0xCC(r31)

	.loc_0x50:
	  lbz       r0, 0x6(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x184
	  lbz       r0, 0x1D(r31)
	  stb       r0, 0x1E(r31)
	  lfs       f1, 0x84(r31)
	  lfs       f0, 0xCC(r31)
	  lfs       f2, 0x80(r31)
	  fmuls     f0, f1, f0
	  fneg      f2, f2
	  stfs      f0, 0x84(r31)
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0x84(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x420(r3)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x84(r31)
	  lfs       f1, 0x80(r31)
	  lfs       f0, 0x84(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x80(r31)
	  lfs       f1, 0x84(r31)
	  lfs       f0, -0x568C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xBC
	  b         .loc_0xC0

	.loc_0xBC:
	  fneg      f1, f1

	.loc_0xC0:
	  lfs       f0, -0x5644(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x104
	  lfs       f1, 0x80(r31)
	  lfs       f0, -0x568C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xE0
	  b         .loc_0xE4

	.loc_0xE0:
	  fneg      f1, f1

	.loc_0xE4:
	  lfs       f0, -0x5644(r2)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x104
	  lfs       f0, -0x568C(r2)
	  li        r0, 0x1
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  stb       r0, 0x7(r31)

	.loc_0x104:
	  lfs       f1, 0x84(r31)
	  lfs       f0, -0x568C(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x11C
	  li        r0, 0x1
	  stb       r0, 0x1D(r31)

	.loc_0x11C:
	  lbz       r0, 0x1D(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x138
	  lfs       f1, 0xCC(r31)
	  lfs       f0, -0x5640(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xCC(r31)

	.loc_0x138:
	  lbz       r0, 0x4(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A0
	  lwz       r4, 0x0(r31)
	  lwz       r0, 0x2C(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A0
	  lwz       r3, 0x3178(r13)
	  addi      r6, r4, 0x94
	  li        r4, 0x3
	  li        r5, 0
	  bl        0x25AC4
	  lwz       r3, 0x0(r31)
	  li        r4, 0x2B
	  lwz       r3, 0x2C(r3)
	  bl        -0xB3550
	  li        r0, 0
	  stb       r0, 0x4(r31)
	  b         .loc_0x1A0

	.loc_0x184:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x564C(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x80(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x80(r31)

	.loc_0x1A0:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80157360
 * Size:	0003A4
 */
void SpiderLeg::setNextDirAndCent()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x140(r1)
	  stfd      f31, 0x138(r1)
	  stfd      f30, 0x130(r1)
	  stfd      f29, 0x128(r1)
	  stfd      f28, 0x120(r1)
	  stw       r31, 0x11C(r1)
	  mr        r31, r3
	  lbz       r0, 0x9(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x380
	  lbz       r0, 0x15(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x380
	  lbz       r0, 0x7(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x380
	  lwz       r3, 0x0(r31)
	  lfs       f0, -0x568C(r2)
	  lwz       r4, 0x224(r3)
	  lfs       f2, 0x2D0(r4)
	  lfs       f1, 0x2C0(r4)
	  fsubs     f28, f2, f1
	  fcmpo     cr0, f28, f0
	  ble-      .loc_0x6C
	  b         .loc_0x70

	.loc_0x6C:
	  fneg      f28, f28

	.loc_0x70:
	  bl        0xC0CA0
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x563C(r2)
	  stw       r0, 0x114(r1)
	  lis       r0, 0x4330
	  fmuls     f3, f0, f28
	  lwz       r3, 0x0(r31)
	  stw       r0, 0x110(r1)
	  lfd       f2, -0x5668(r2)
	  lfd       f1, 0x110(r1)
	  lfs       f0, -0x5674(r2)
	  fsubs     f4, f1, f2
	  lwz       r4, 0x224(r3)
	  lfs       f5, -0x5678(r2)
	  lfs       f2, 0x310(r4)
	  fdivs     f6, f4, f0
	  lfs       f1, 0x300(r4)
	  lfs       f0, -0x568C(r2)
	  lfs       f4, 0x2C0(r4)
	  fsubs     f28, f2, f1
	  fmuls     f1, f5, f6
	  fcmpo     cr0, f28, f0
	  fmuls     f0, f3, f1
	  fadds     f30, f4, f0
	  ble-      .loc_0xD8
	  b         .loc_0xDC

	.loc_0xD8:
	  fneg      f28, f28

	.loc_0xDC:
	  bl        0xC0C34
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x563C(r2)
	  stw       r0, 0x114(r1)
	  lis       r0, 0x4330
	  fmuls     f3, f0, f28
	  lwz       r3, 0x0(r31)
	  stw       r0, 0x110(r1)
	  lfd       f2, -0x5668(r2)
	  lfd       f1, 0x110(r1)
	  lfs       f0, -0x5674(r2)
	  fsubs     f4, f1, f2
	  lwz       r4, 0x224(r3)
	  lfs       f5, -0x5678(r2)
	  lfs       f2, 0x4F0(r4)
	  fdivs     f6, f4, f0
	  lfs       f1, 0x4E0(r4)
	  lfs       f0, -0x568C(r2)
	  lfs       f4, 0x300(r4)
	  fsubs     f28, f2, f1
	  fmuls     f1, f5, f6
	  fcmpo     cr0, f28, f0
	  fmuls     f0, f3, f1
	  fadds     f29, f4, f0
	  ble-      .loc_0x144
	  b         .loc_0x148

	.loc_0x144:
	  fneg      f28, f28

	.loc_0x148:
	  bl        0xC0BC8
	  xoris     r0, r3, 0x8000
	  lwz       r4, 0x0(r31)
	  stw       r0, 0x114(r1)
	  lis       r0, 0x4330
	  lfs       f0, -0x563C(r2)
	  stw       r0, 0x110(r1)
	  lwz       r3, 0x224(r4)
	  fmuls     f0, f0, f28
	  lfd       f3, -0x5668(r2)
	  lfd       f1, 0x110(r1)
	  lfs       f2, -0x5674(r2)
	  fsubs     f3, f1, f3
	  lfs       f6, -0x5678(r2)
	  lfs       f5, 0x4E0(r3)
	  lfs       f1, 0x94(r4)
	  fdivs     f7, f3, f2
	  lfs       f2, 0x9C(r4)
	  lfs       f3, 0x30C(r4)
	  lfs       f4, 0x314(r4)
	  fmuls     f6, f6, f7
	  fmuls     f0, f0, f6
	  fadds     f28, f5, f0
	  bl        -0x11EEDC
	  lwz       r3, 0x0(r31)
	  fmr       f31, f1
	  lfs       f0, -0x568C(r2)
	  lfsu      f1, 0xA0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1CC
	  lfs       f0, -0x5650(r2)
	  fadds     f1, f0, f1
	  b         .loc_0x1E0

	.loc_0x1CC:
	  lfs       f0, -0x5650(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1E0
	  fsubs     f1, f1, f0

	.loc_0x1E0:
	  stfs      f1, 0x0(r3)
	  lwz       r4, 0x0(r31)
	  lfs       f1, 0x94(r4)
	  lfs       f3, 0x30C(r4)
	  lfs       f2, 0x314(r4)
	  lfs       f0, 0x9C(r4)
	  fsubs     f1, f3, f1
	  fsubs     f2, f2, f0
	  bl        0xC4498
	  stfs      f1, 0xE4(r31)
	  lwz       r3, 0x0(r31)
	  lfs       f3, 0xE4(r31)
	  lfs       f0, 0xA0(r3)
	  fcmpo     cr0, f3, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x23C
	  fsubs     f2, f3, f0
	  lfs       f1, -0x5650(r2)
	  fsubs     f0, f1, f2
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x254
	  fsubs     f3, f3, f1
	  b         .loc_0x254

	.loc_0x23C:
	  fsubs     f2, f0, f3
	  lfs       f1, -0x5650(r2)
	  fsubs     f0, f1, f2
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x254
	  fadds     f3, f3, f1

	.loc_0x254:
	  stfs      f3, 0xE4(r31)
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0xE4(r31)
	  lfs       f0, 0xA0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2D0
	  fsubs     f1, f1, f0
	  fcmpo     cr0, f1, f29
	  bge-      .loc_0x2A4
	  lfs       f0, -0x5638(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x330
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x4D0(r3)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x29C
	  fmuls     f30, f30, f28
	  b         .loc_0x330

	.loc_0x29C:
	  lfs       f30, -0x568C(r2)
	  b         .loc_0x330

	.loc_0x2A4:
	  fadds     f0, f0, f29
	  stfs      f0, 0xE4(r31)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x4D0(r3)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x2C8
	  fmuls     f30, f30, f28
	  b         .loc_0x330

	.loc_0x2C8:
	  lfs       f30, -0x568C(r2)
	  b         .loc_0x330

	.loc_0x2D0:
	  fsubs     f1, f0, f1
	  fcmpo     cr0, f1, f29
	  bge-      .loc_0x308
	  lfs       f0, -0x5638(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x330
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x4D0(r3)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x300
	  fmuls     f30, f30, f28
	  b         .loc_0x330

	.loc_0x300:
	  lfs       f30, -0x568C(r2)
	  b         .loc_0x330

	.loc_0x308:
	  fsubs     f0, f0, f29
	  stfs      f0, 0xE4(r31)
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x4D0(r3)
	  fcmpo     cr0, f31, f0
	  bge-      .loc_0x32C
	  fmuls     f30, f30, f28
	  b         .loc_0x330

	.loc_0x32C:
	  lfs       f30, -0x568C(r2)

	.loc_0x330:
	  lfs       f1, 0xE4(r31)
	  bl        0xC4654
	  lwz       r3, 0x0(r31)
	  fmuls     f1, f30, f1
	  lfs       f0, 0x94(r3)
	  fadds     f0, f0, f1
	  stfs      f0, 0x24C(r31)
	  lfs       f1, 0xE4(r31)
	  bl        0xC44A4
	  lwz       r3, 0x0(r31)
	  fmuls     f1, f30, f1
	  li        r4, 0x1
	  lfs       f0, 0x9C(r3)
	  fadds     f0, f0, f1
	  stfs      f0, 0x254(r31)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x24C(r31)
	  lfs       f2, 0x254(r31)
	  bl        -0xEF7D4
	  stfs      f1, 0x250(r31)

	.loc_0x380:
	  lwz       r0, 0x144(r1)
	  lfd       f31, 0x138(r1)
	  lfd       f30, 0x130(r1)
	  lfd       f29, 0x128(r1)
	  lfd       f28, 0x120(r1)
	  lwz       r31, 0x11C(r1)
	  addi      r1, r1, 0x140
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80157704
 * Size:	0002E8
 */
void SpiderLeg::setWalkNewPosition()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x120(r1)
	  stfd      f31, 0x118(r1)
	  stfd      f30, 0x110(r1)
	  stfd      f29, 0x108(r1)
	  stfd      f28, 0x100(r1)
	  stfd      f27, 0xF8(r1)
	  stfd      f26, 0xF0(r1)
	  stfd      f25, 0xE8(r1)
	  stfd      f24, 0xE0(r1)
	  stfd      f23, 0xD8(r1)
	  stfd      f22, 0xD0(r1)
	  stfd      f21, 0xC8(r1)
	  stfd      f20, 0xC0(r1)
	  stmw      r21, 0x94(r1)
	  mr        r21, r3
	  lis       r3, 0x8022
	  mr        r28, r21
	  mr        r27, r21
	  addi      r29, r1, 0x6C
	  addi      r30, r3, 0x26D0
	  li        r22, 0
	  lis       r31, 0x4330
	  lfs       f22, -0x568C(r2)
	  lfs       f24, -0x5658(r2)
	  lfd       f25, -0x5668(r2)
	  lfs       f26, -0x5674(r2)
	  lfs       f27, -0x5678(r2)
	  lfs       f28, -0x563C(r2)
	  lfs       f29, -0x5634(r2)
	  lfs       f30, -0x5630(r2)
	  lfs       f31, -0x5660(r2)

	.loc_0x84:
	  lbz       r0, 0x7(r21)
	  cmplwi    r0, 0
	  bne-      .loc_0x214
	  add       r26, r21, r22
	  addi      r23, r26, 0x9
	  lbz       r0, 0x9(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x214
	  addi      r25, r26, 0x15
	  lbz       r0, 0x15(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x214
	  addi      r24, r26, 0x19
	  lbz       r0, 0x19(r26)
	  cmplwi    r0, 0
	  bne-      .loc_0x214
	  lwz       r3, 0x0(r30)
	  lwz       r0, 0x4(r30)
	  stw       r3, 0x6C(r1)
	  stw       r0, 0x70(r1)
	  lwz       r3, 0x8(r30)
	  lwz       r0, 0xC(r30)
	  stw       r3, 0x74(r1)
	  stw       r0, 0x78(r1)
	  lwz       r3, 0x0(r21)
	  lfs       f0, 0x0(r29)
	  lwz       r4, 0x224(r3)
	  fmuls     f2, f24, f0
	  lfs       f3, 0xE4(r21)
	  lfs       f1, 0x2F0(r4)
	  lfs       f0, 0x2E0(r4)
	  fsubs     f23, f3, f2
	  fsubs     f21, f1, f0
	  fcmpo     cr0, f21, f22
	  ble-      .loc_0x114
	  b         .loc_0x118

	.loc_0x114:
	  fneg      f21, f21

	.loc_0x118:
	  bl        0xC0854
	  xoris     r0, r3, 0x8000
	  lwz       r3, 0x0(r21)
	  stw       r0, 0x8C(r1)
	  fmuls     f0, f28, f21
	  lwz       r3, 0x224(r3)
	  fmr       f1, f23
	  stw       r31, 0x88(r1)
	  lfs       f2, 0x2E0(r3)
	  lfd       f3, 0x88(r1)
	  fsubs     f3, f3, f25
	  fdivs     f3, f3, f26
	  fmuls     f3, f27, f3
	  fmuls     f0, f0, f3
	  fadds     f20, f2, f0
	  bl        0xC4490
	  fmuls     f21, f20, f1
	  fmr       f1, f23
	  bl        0xC42F0
	  lfs       f0, 0x12C(r28)
	  fmuls     f1, f20, f1
	  li        r4, 0x1
	  stfs      f0, 0x1BC(r28)
	  lfs       f0, 0x130(r28)
	  stfs      f0, 0x1C0(r28)
	  lfs       f0, 0x134(r28)
	  stfs      f0, 0x1C4(r28)
	  lfs       f0, 0x24C(r21)
	  fadds     f0, f0, f21
	  stfs      f0, 0x1D4(r28)
	  lfs       f0, 0x254(r21)
	  fadds     f0, f0, f1
	  stfs      f0, 0x1DC(r28)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x1D4(r28)
	  lfs       f2, 0x1DC(r28)
	  bl        -0xEF9A8
	  fsubs     f0, f1, f29
	  li        r3, 0
	  li        r0, 0x1
	  stfs      f0, 0x1D8(r28)
	  lfs       f0, 0x1D4(r28)
	  lfs       f1, 0x12C(r28)
	  fmuls     f0, f30, f0
	  fadds     f0, f1, f0
	  fdivs     f0, f0, f31
	  stfs      f0, 0x1C8(r28)
	  lfs       f0, 0x1DC(r28)
	  lfs       f1, 0x134(r28)
	  fmuls     f0, f30, f0
	  fadds     f0, f1, f0
	  fdivs     f0, f0, f31
	  stfs      f0, 0x1D0(r28)
	  lwz       r4, 0x0(r21)
	  lfs       f0, 0xD0(r27)
	  lfs       f1, 0x98(r4)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1CC(r28)
	  stb       r3, 0xD(r26)
	  stb       r3, 0x0(r25)
	  stb       r0, 0x0(r24)
	  stb       r0, 0x0(r23)
	  stfs      f22, 0xA8(r27)

	.loc_0x214:
	  addi      r0, r22, 0x9
	  lbzx      r0, r21, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x28C
	  lfs       f1, 0x70(r27)
	  lfs       f0, 0xD0(r27)
	  lwz       r3, 0x0(r21)
	  fadds     f0, f1, f0
	  lfs       f3, 0x1CC(r28)
	  lwz       r4, 0x224(r3)
	  lwz       r3, 0x2DEC(r13)
	  fsubs     f2, f3, f0
	  lfs       f1, 0x4C0(r4)
	  fmr       f4, f0
	  lfs       f0, 0x28C(r3)
	  fcmpo     cr0, f2, f22
	  fmuls     f0, f1, f0
	  ble-      .loc_0x260
	  b         .loc_0x264

	.loc_0x260:
	  fneg      f2, f2

	.loc_0x264:
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x274
	  fmr       f0, f4
	  b         .loc_0x288

	.loc_0x274:
	  fcmpo     cr0, f3, f4
	  bge-      .loc_0x284
	  fadds     f0, f3, f0
	  b         .loc_0x288

	.loc_0x284:
	  fsubs     f0, f3, f0

	.loc_0x288:
	  stfs      f0, 0x1CC(r28)

	.loc_0x28C:
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x4
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x24
	  addi      r27, r27, 0x4
	  blt+      .loc_0x84
	  lmw       r21, 0x94(r1)
	  lwz       r0, 0x124(r1)
	  lfd       f31, 0x118(r1)
	  lfd       f30, 0x110(r1)
	  lfd       f29, 0x108(r1)
	  lfd       f28, 0x100(r1)
	  lfd       f27, 0xF8(r1)
	  lfd       f26, 0xF0(r1)
	  lfd       f25, 0xE8(r1)
	  lfd       f24, 0xE0(r1)
	  lfd       f23, 0xD8(r1)
	  lfd       f22, 0xD0(r1)
	  lfd       f21, 0xC8(r1)
	  lfd       f20, 0xC0(r1)
	  addi      r1, r1, 0x120
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000210
 */
void SpiderLeg::checkGroundTimer()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801579EC
 * Size:	000168
 */
void SpiderLeg::checkMotionRatio()
{
	/*
	.loc_0x0:
	  stwu      r1, -0x88(r1)
	  lbz       r0, 0x8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x160
	  li        r0, 0x4
	  lfs       f5, -0x562C(r2)
	  mtctr     r0
	  lfd       f4, -0x5668(r2)
	  addi      r7, r3, 0
	  li        r4, 0
	  lis       r6, 0x4330

	.loc_0x2C:
	  add       r9, r3, r4
	  lbz       r0, 0x9(r9)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  lwz       r0, 0xF8(r3)
	  cmpwi     r0, 0x1
	  bge-      .loc_0x154
	  lfs       f0, 0xA8(r7)
	  fcmpo     cr0, f0, f5
	  bge-      .loc_0x9C
	  lwz       r0, 0xE8(r7)
	  lwz       r5, 0x0(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x84(r1)
	  lwz       r8, 0x224(r5)
	  stw       r6, 0x80(r1)
	  lfs       f1, 0x220(r8)
	  lfd       f0, 0x80(r1)
	  lfs       f3, 0x210(r8)
	  fsubs     f2, f0, f4
	  lfs       f0, 0x230(r8)
	  fmuls     f1, f2, f1
	  fsubs     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  fmr       f2, f1
	  bge-      .loc_0xE0
	  fmr       f2, f0
	  b         .loc_0xE0

	.loc_0x9C:
	  lwz       r0, 0xE8(r7)
	  lwz       r5, 0x0(r3)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x84(r1)
	  lwz       r8, 0x224(r5)
	  stw       r6, 0x80(r1)
	  lfs       f1, 0x250(r8)
	  lfd       f0, 0x80(r1)
	  lfs       f3, 0x240(r8)
	  fsubs     f2, f0, f4
	  lfs       f0, 0x260(r8)
	  fmuls     f1, f2, f1
	  fadds     f1, f3, f1
	  fcmpo     cr0, f1, f0
	  fmr       f2, f1
	  ble-      .loc_0xE0
	  fmr       f2, f0

	.loc_0xE0:
	  lwz       r5, 0x2DEC(r13)
	  addi      r8, r9, 0x19
	  lfs       f1, 0xA8(r7)
	  lfs       f0, 0x28C(r5)
	  fmuls     f0, f2, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0xA8(r7)
	  lbz       r0, 0x19(r9)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  lwz       r5, 0x0(r3)
	  lfs       f1, 0xA8(r7)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x320(r5)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x154
	  addic.    r0, r4, 0x1
	  bge-      .loc_0x130
	  addi      r5, r4, 0x5
	  b         .loc_0x140

	.loc_0x130:
	  addi      r5, r4, 0x1
	  cmpwi     r5, 0x3
	  ble-      .loc_0x140
	  subi      r5, r4, 0x3

	.loc_0x140:
	  addi      r0, r5, 0x15
	  li        r5, 0x1
	  stbx      r5, r3, r0
	  li        r0, 0
	  stb       r0, 0x0(r8)

	.loc_0x154:
	  addi      r7, r7, 0x4
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x2C

	.loc_0x160:
	  addi      r1, r1, 0x88
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80157B54
 * Size:	000168
 */
void SpiderLeg::makeNewPosition()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stmw      r26, 0x48(r1)
	  addi      r30, r3, 0
	  lbz       r0, 0x3174(r13)
	  extsb.    r0, r0
	  bne-      .loc_0x38
	  lfs       f0, -0x568C(r2)
	  li        r0, 0x1
	  stb       r0, 0x3174(r13)
	  stfs      f0, 0x3170(r13)

	.loc_0x38:
	  lbz       r0, 0x8(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x14C
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, -0x5628(r2)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0x3170(r13)
	  fmuls     f1, f1, f0
	  lfs       f0, -0x5650(r2)
	  fadds     f1, f2, f1
	  stfs      f1, 0x3170(r13)
	  lfs       f1, 0x3170(r13)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x78
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3170(r13)

	.loc_0x78:
	  li        r31, 0
	  lfd       f30, -0x5668(r2)
	  mulli     r3, r31, 0x24
	  lfs       f31, -0x5624(r2)
	  rlwinm    r0,r31,2,0,29
	  add       r27, r30, r3
	  add       r26, r30, r0
	  lis       r29, 0x4330

	.loc_0x98:
	  addi      r0, r31, 0x9
	  lbzx      r0, r30, r0
	  cmplwi    r0, 0
	  beq-      .loc_0x138
	  lfs       f1, 0xA8(r26)
	  addi      r3, r27, 0x1BC
	  addi      r4, r27, 0x12C
	  bl        0x246C0
	  xoris     r0, r31, 0x8000
	  lwz       r3, 0x0(r30)
	  stw       r0, 0x44(r1)
	  lwz       r3, 0x224(r3)
	  stw       r29, 0x40(r1)
	  lfs       f1, 0x3170(r13)
	  addi      r28, r3, 0x390
	  lfd       f0, 0x40(r1)
	  fsubs     f0, f0, f30
	  fadds     f1, f1, f0
	  bl        0xC40B4
	  lwz       r0, 0xE8(r26)
	  lwz       r3, 0x0(r30)
	  xoris     r0, r0, 0x8000
	  lfs       f2, 0x0(r28)
	  stw       r0, 0x3C(r1)
	  lwz       r3, 0x224(r3)
	  stw       r29, 0x38(r1)
	  lfs       f0, 0x3A0(r3)
	  lfd       f3, 0x38(r1)
	  fsubs     f3, f3, f30
	  fmuls     f2, f3, f2
	  fmuls     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x120
	  fmr       f1, f0

	.loc_0x120:
	  lfs       f0, 0xA8(r26)
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x138
	  lfs       f0, 0x130(r27)
	  fadds     f0, f0, f1
	  stfs      f0, 0x130(r27)

	.loc_0x138:
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x4
	  addi      r27, r27, 0x24
	  addi      r26, r26, 0x4
	  blt+      .loc_0x98

	.loc_0x14C:
	  lmw       r26, 0x48(r1)
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void SpiderLeg::calcSpiderDirection()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void SpiderLeg::calcShakeOffDirection()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80157CBC
 * Size:	0001D0
 */
void SpiderLeg::calcStickersPiki()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  li        r0, 0
	  stwu      r1, -0x78(r1)
	  stmw      r22, 0x50(r1)
	  addi      r25, r3, 0
	  stw       r0, 0xE8(r3)
	  stw       r0, 0xEC(r3)
	  stw       r0, 0xF0(r3)
	  stw       r0, 0xF4(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x220(r3)
	  bl        -0xCE5E4
	  mr        r26, r3
	  bl        -0xCFF64
	  lwz       r4, 0x0(r25)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x40
	  bl        -0xC7080
	  addi      r29, r1, 0x40
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r4, 0x802D
	  addi      r28, r3, 0
	  subi      r31, r4, 0xAA8
	  b         .loc_0x160

	.loc_0x74:
	  cmpwi     r28, -0x1
	  bne-      .loc_0x9C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r23, r3
	  b         .loc_0xB8

	.loc_0x9C:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r23, r3

	.loc_0xB8:
	  lwz       r12, 0x0(r23)
	  mr        r3, r23
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x144
	  addi      r22, r31, 0
	  li        r27, 0
	  b         .loc_0x13C

	.loc_0xE0:
	  lwz       r4, 0x188(r23)
	  addi      r3, r1, 0x1C
	  bl        -0xCFF04
	  lwz       r24, 0x1C(r1)
	  addi      r3, r26, 0
	  addi      r4, r27, 0
	  bl        -0xCFFC8
	  addi      r4, r3, 0
	  addi      r3, r1, 0x28
	  bl        -0xCFF20
	  lwz       r0, 0x28(r1)
	  cmplw     r0, r24
	  bne-      .loc_0x134
	  lwz       r0, 0x0(r22)
	  cmpwi     r0, 0
	  blt-      .loc_0x134
	  rlwinm    r3,r0,2,0,29
	  addi      r4, r3, 0xE8
	  lwzx      r3, r25, r4
	  addi      r0, r3, 0x1
	  stwx      r0, r25, r4

	.loc_0x134:
	  addi      r22, r22, 0x4
	  addi      r27, r27, 0x1

	.loc_0x13C:
	  cmpw      r27, r30
	  blt+      .loc_0xE0

	.loc_0x144:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x160:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x188
	  li        r0, 0x1
	  b         .loc_0x1B4

	.loc_0x188:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x1B0
	  li        r0, 0x1
	  b         .loc_0x1B4

	.loc_0x1B0:
	  li        r0, 0

	.loc_0x1B4:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x74
	  lmw       r22, 0x50(r1)
	  lwz       r0, 0x7C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void SpiderLeg::calcShakeOff()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80157E8C
 * Size:	0002C0
 */
void SpiderLeg::setIdealCentre(Vector3f&)
{
	/*
	.loc_0x0:
	  lwz       r5, 0x0(r3)
	  lwz       r0, 0x2E4(r5)
	  cmpwi     r0, 0x7
	  bge-      .loc_0x290
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x12C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r4)
	  lfs       f2, 0x130(r3)
	  lfs       f1, 0x1C0(r3)
	  lfs       f0, -0x5634(r2)
	  fsubs     f1, f2, f1
	  lfs       f2, 0x4(r4)
	  fdivs     f1, f1, f0
	  fadds     f1, f2, f1
	  stfs      f1, 0x4(r4)
	  lfs       f2, 0x8(r4)
	  lfs       f1, 0x134(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0x8(r4)
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x150(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0x0(r4)
	  lfs       f2, 0x154(r3)
	  lfs       f1, 0x1E4(r3)
	  lfs       f3, 0x4(r4)
	  fsubs     f1, f2, f1
	  fdivs     f1, f1, f0
	  fadds     f1, f3, f1
	  stfs      f1, 0x4(r4)
	  lfs       f2, 0x8(r4)
	  lfs       f1, 0x158(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0x8(r4)
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x174(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0x0(r4)
	  lfs       f2, 0x178(r3)
	  lfs       f1, 0x208(r3)
	  lfs       f3, 0x4(r4)
	  fsubs     f1, f2, f1
	  fdivs     f1, f1, f0
	  fadds     f1, f3, f1
	  stfs      f1, 0x4(r4)
	  lfs       f2, 0x8(r4)
	  lfs       f1, 0x17C(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0x8(r4)
	  lfs       f2, 0x0(r4)
	  lfs       f1, 0x198(r3)
	  fadds     f1, f2, f1
	  stfs      f1, 0x0(r4)
	  lfs       f2, 0x19C(r3)
	  lfs       f1, 0x22C(r3)
	  lfs       f3, 0x4(r4)
	  fsubs     f1, f2, f1
	  fdivs     f0, f1, f0
	  fadds     f0, f3, f0
	  stfs      f0, 0x4(r4)
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x1A0(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r4)
	  lfs       f0, 0x0(r4)
	  lfs       f1, -0x5620(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x8(r4)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x8(r4)
	  lbz       r0, 0xD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x178
	  lwz       r5, 0x0(r3)
	  lfs       f2, 0x0(r4)
	  lfs       f0, 0x12C(r3)
	  lwz       r5, 0x224(r5)
	  fsubs     f1, f0, f2
	  lfs       f4, 0x134(r3)
	  lfs       f0, 0x3E0(r5)
	  lfs       f3, 0x8(r4)
	  fmuls     f0, f1, f0
	  fsubs     f3, f4, f3
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r4)
	  lwz       r5, 0x0(r3)
	  lfs       f1, 0x8(r4)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3E0(r5)
	  fmuls     f0, f3, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r4)

	.loc_0x178:
	  lbz       r0, 0xE(r3)
	  addi      r6, r3, 0x24
	  cmplwi    r0, 0
	  beq-      .loc_0x1D4
	  lwz       r5, 0x0(r3)
	  lfs       f2, 0x0(r4)
	  lfs       f0, 0x12C(r6)
	  lwz       r5, 0x224(r5)
	  fsubs     f1, f0, f2
	  lfs       f4, 0x134(r6)
	  lfs       f0, 0x3E0(r5)
	  lfs       f3, 0x8(r4)
	  fmuls     f0, f1, f0
	  fsubs     f3, f4, f3
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r4)
	  lwz       r5, 0x0(r3)
	  lfs       f1, 0x8(r4)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3E0(r5)
	  fmuls     f0, f3, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r4)

	.loc_0x1D4:
	  lbz       r0, 0xF(r3)
	  addi      r6, r6, 0x24
	  cmplwi    r0, 0
	  beq-      .loc_0x230
	  lwz       r5, 0x0(r3)
	  lfs       f2, 0x0(r4)
	  lfs       f0, 0x12C(r6)
	  lwz       r5, 0x224(r5)
	  fsubs     f1, f0, f2
	  lfs       f4, 0x134(r6)
	  lfs       f0, 0x3E0(r5)
	  lfs       f3, 0x8(r4)
	  fmuls     f0, f1, f0
	  fsubs     f3, f4, f3
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r4)
	  lwz       r5, 0x0(r3)
	  lfs       f1, 0x8(r4)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3E0(r5)
	  fmuls     f0, f3, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r4)

	.loc_0x230:
	  lbz       r0, 0x10(r3)
	  addi      r6, r6, 0x24
	  cmplwi    r0, 0
	  beq-      .loc_0x2A4
	  lwz       r5, 0x0(r3)
	  lfs       f2, 0x0(r4)
	  lfs       f0, 0x12C(r6)
	  lwz       r5, 0x224(r5)
	  fsubs     f1, f0, f2
	  lfs       f4, 0x134(r6)
	  lfs       f0, 0x3E0(r5)
	  lfs       f3, 0x8(r4)
	  fmuls     f0, f1, f0
	  fsubs     f3, f4, f3
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r4)
	  lwz       r5, 0x0(r3)
	  lfs       f1, 0x8(r4)
	  lwz       r5, 0x224(r5)
	  lfs       f0, 0x3E0(r5)
	  fmuls     f0, f3, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r4)
	  b         .loc_0x2A4

	.loc_0x290:
	  lfs       f0, 0x300(r5)
	  stfs      f0, 0x0(r4)
	  lwz       r5, 0x0(r3)
	  lfs       f0, 0x308(r5)
	  stfs      f0, 0x8(r4)

	.loc_0x2A4:
	  lfs       f1, -0x561C(r2)
	  lfs       f0, 0xE0(r3)
	  lfs       f2, 0x4(r4)
	  fadds     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x4(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8015814C
 * Size:	00020C
 */
void SpiderLeg::setRealCentre(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x60(r1)
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x258(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f1, 0x3C0(r3)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x258(r31)
	  lfs       f0, 0x25C(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x25C(r31)
	  lfs       f0, 0x260(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x260(r31)
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x264(r31)
	  lwz       r3, 0x224(r3)
	  fsubs     f1, f1, f0
	  lfs       f2, 0x258(r31)
	  lfs       f0, 0x3B0(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x258(r31)
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0x4(r4)
	  lfs       f0, 0x268(r31)
	  lwz       r3, 0x224(r3)
	  fsubs     f1, f1, f0
	  lfs       f2, 0x25C(r31)
	  lfs       f0, 0x3B0(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x25C(r31)
	  lwz       r3, 0x0(r31)
	  lfs       f1, 0x8(r4)
	  lfs       f0, 0x26C(r31)
	  lwz       r3, 0x224(r3)
	  fsubs     f1, f1, f0
	  lfs       f2, 0x260(r31)
	  lfs       f0, 0x3B0(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x260(r31)
	  lfs       f1, 0x258(r31)
	  lfs       f3, 0x260(r31)
	  lfs       f0, 0x25C(r31)
	  fmuls     f2, f1, f1
	  fmuls     f3, f3, f3
	  fmuls     f1, f0, f0
	  lfs       f0, -0x568C(r2)
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x140
	  fsqrte    f1, f4
	  lfd       f3, -0x5688(r2)
	  lfd       f2, -0x5680(r2)
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
	  stfs      f0, 0x38(r1)
	  lfs       f4, 0x38(r1)

	.loc_0x140:
	  lfs       f0, -0x5618(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1C8
	  lfs       f1, 0x258(r31)
	  lfs       f0, 0x25C(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x260(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14A678
	  lfs       f0, -0x568C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x1A0
	  lfs       f0, 0x258(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x258(r31)
	  lfs       f0, 0x25C(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x25C(r31)
	  lfs       f0, 0x260(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x260(r31)

	.loc_0x1A0:
	  lfs       f0, 0x258(r31)
	  lfs       f1, -0x5618(r2)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x258(r31)
	  lfs       f0, 0x25C(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x25C(r31)
	  lfs       f0, 0x260(r31)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x260(r31)

	.loc_0x1C8:
	  lfs       f1, 0x264(r31)
	  lfs       f0, 0x258(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x264(r31)
	  lfs       f1, 0x268(r31)
	  lfs       f0, 0x25C(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x268(r31)
	  lfs       f1, 0x26C(r31)
	  lfs       f0, 0x260(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x26C(r31)
	  lwz       r0, 0x64(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000310
 */
void SpiderLeg::setCentrePosition()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80158358
 * Size:	000174
 */
void SpiderLeg::updateAnimation(const BossShapeObject*, Graphics&, Matrix4f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x150(r1)
	  stw       r31, 0x14C(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x148(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x144(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x140(r1)
	  mr        r28, r3
	  addi      r6, r28, 0x264
	  lwz       r7, 0x0(r3)
	  addi      r3, r1, 0xC0
	  addi      r4, r7, 0x7C
	  addi      r5, r7, 0x88
	  bl        -0x11A2A4
	  lwz       r3, 0x2E4(r30)
	  addi      r4, r1, 0xC0
	  addi      r5, r1, 0x100
	  addi      r3, r3, 0x1E0
	  bl        -0x11A2D8
	  lwz       r3, 0x0(r28)
	  addi      r3, r3, 0x33C
	  lwz       r12, 0x30(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r29)
	  addi      r4, r30, 0
	  addi      r5, r1, 0x100
	  li        r6, 0
	  bl        -0x1230C4
	  lwz       r3, 0x2E4(r30)
	  addi      r4, r31, 0
	  addi      r3, r3, 0x1E0
	  bl        -0x119FAC
	  lbz       r0, 0x5(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x154
	  lfs       f0, -0x568C(r2)
	  li        r3, 0x8
	  stfs      f0, 0x1C(r1)
	  stfs      f0, 0x20(r1)
	  stfs      f0, 0x24(r1)
	  stfs      f0, 0x28(r1)
	  stfs      f0, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x38(r1)
	  b         .loc_0x144

	.loc_0xCC:
	  subfic    r0, r3, 0x9
	  cmpwi     r3, 0x9
	  mtctr     r0
	  bge-      .loc_0xE8

	.loc_0xDC:
	  stfs      f0, 0x0(r4)
	  addi      r4, r4, 0x4
	  bdnz+     .loc_0xDC

	.loc_0xE8:
	  lfs       f0, -0x5678(r2)
	  li        r4, 0xE
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x2C(r1)
	  stfs      f0, 0x1C(r1)
	  lwz       r3, 0x0(r29)
	  bl        -0x123470
	  addi      r4, r1, 0x80
	  bl        -0x11A024
	  lwz       r3, 0x0(r29)
	  li        r4, 0xF
	  bl        -0x123484
	  addi      r4, r3, 0
	  addi      r3, r1, 0x80
	  addi      r5, r1, 0x40
	  bl        -0x11A3A8
	  addi      r3, r1, 0x40
	  addi      r4, r1, 0x1C
	  bl        0x24394
	  addi      r3, r28, 0x270
	  addi      r4, r1, 0x1C
	  bl        -0x120BD8
	  b         .loc_0x154

	.loc_0x144:
	  rlwinm    r0,r3,2,0,29
	  addi      r4, r1, 0x1C
	  add       r4, r4, r0
	  b         .loc_0xCC

	.loc_0x154:
	  lwz       r0, 0x154(r1)
	  lwz       r31, 0x14C(r1)
	  lwz       r30, 0x148(r1)
	  lwz       r29, 0x144(r1)
	  lwz       r28, 0x140(r1)
	  addi      r1, r1, 0x150
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void SpiderLeg::setJointMatrix(const BossShapeObject*, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
void SpiderLeg::setLength()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801584CC
 * Size:	000130
 */
void SpiderLeg::getHeight()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stfd      f30, 0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  li        r29, 0
	  mulli     r0, r29, 0x24
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  lfs       f31, -0x5614(r2)
	  lfs       f30, -0x5690(r2)
	  addi      r30, r28, 0
	  add       r31, r28, r0

	.loc_0x40:
	  lwz       r3, 0x2F00(r13)
	  li        r4, 0x1
	  lfs       f1, 0x12C(r31)
	  lfs       f2, 0x134(r31)
	  bl        -0xF0618
	  stfs      f1, 0x70(r30)
	  lfs       f1, 0x70(r30)
	  lfs       f0, 0x130(r31)
	  fsubs     f1, f1, f0
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x74
	  fadds     f0, f0, f1
	  stfs      f0, 0x130(r31)

	.loc_0x74:
	  lbz       r0, 0x8(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0xC8
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0xAC
	  lfs       f0, 0xA8(r30)
	  fcmpo     cr0, f0, f30
	  ble-      .loc_0xF4
	  add       r3, r28, r29
	  li        r0, 0
	  stb       r0, 0x9(r3)
	  li        r0, 0x1
	  stb       r0, 0xD(r3)
	  b         .loc_0xF4

	.loc_0xAC:
	  lfs       f0, 0xA8(r30)
	  fcmpo     cr0, f0, f30
	  bge-      .loc_0xF4
	  addi      r0, r29, 0xD
	  li        r3, 0
	  stbx      r3, r28, r0
	  b         .loc_0xF4

	.loc_0xC8:
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0xE8
	  add       r3, r28, r29
	  li        r0, 0
	  stb       r0, 0x9(r3)
	  li        r0, 0x1
	  stb       r0, 0xD(r3)
	  b         .loc_0xF4

	.loc_0xE8:
	  addi      r0, r29, 0xD
	  li        r3, 0
	  stbx      r3, r28, r0

	.loc_0xF4:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x4
	  addi      r31, r31, 0x24
	  addi      r30, r30, 0x4
	  blt+      .loc_0x40
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lfd       f30, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void SpiderLeg::getLegController()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void SpiderLeg::setQuatParameter()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801585FC
 * Size:	000248
 */
void SpiderLeg::stepDamageNavi(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r4, 0x24
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stfd      f30, 0x98(r1)
	  stmw      r25, 0x7C(r1)
	  addi      r29, r3, 0
	  add       r26, r29, r0
	  lwz       r31, 0x3120(r13)
	  lfs       f1, -0x5610(r2)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lfs       f0, 0x130(r26)
	  lwz       r12, 0xC(r12)
	  fadds     f31, f1, f0
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f30, -0x568C(r2)
	  lis       r4, 0x802B
	  addi      r30, r3, 0
	  subi      r27, r5, 0x3064
	  subi      r28, r4, 0x32D4
	  b         .loc_0x1D0

	.loc_0x64:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x8C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3
	  b         .loc_0xA8

	.loc_0x8C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r25, r3

	.loc_0xA8:
	  cmplwi    r25, 0
	  beq-      .loc_0x1B4
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1B4
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1B4
	  mr        r3, r25
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x1B4
	  lfs       f4, 0x98(r25)
	  fcmpo     cr0, f31, f4
	  ble-      .loc_0x1B4
	  stfs      f30, 0x54(r1)
	  stfs      f30, 0x50(r1)
	  stfs      f30, 0x4C(r1)
	  lfs       f1, 0x94(r25)
	  lfs       f0, 0x12C(r26)
	  lfs       f2, 0x130(r26)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r25)
	  lfs       f1, 0x134(r26)
	  fsubs     f2, f4, f2
	  stfs      f0, 0x3C(r1)
	  fsubs     f1, f3, f1
	  lfs       f0, 0x3C(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f2, 0x50(r1)
	  stfs      f1, 0x54(r1)
	  lfs       f1, 0x4C(r1)
	  lfs       f0, 0x50(r1)
	  lfs       f2, 0x54(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14AB2C
	  lwz       r5, 0x0(r29)
	  lwz       r4, 0x224(r5)
	  lfs       f0, 0x330(r4)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1B4
	  lfs       f0, 0x340(r4)
	  addi      r3, r25, 0
	  addi      r4, r1, 0x5C
	  stw       r27, 0x5C(r1)
	  stw       r5, 0x60(r1)
	  stw       r28, 0x5C(r1)
	  stfs      f0, 0x64(r1)
	  lwz       r12, 0x0(r25)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x1B4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1D0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1F8
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x1F8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x220
	  li        r0, 0x1
	  b         .loc_0x224

	.loc_0x220:
	  li        r0, 0

	.loc_0x224:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x64
	  lmw       r25, 0x7C(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  lfd       f30, 0x98(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80158844
 * Size:	000230
 */
void SpiderLeg::stepDamagePiki(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r4, 0x24
	  stwu      r1, -0xA8(r1)
	  stfd      f31, 0xA0(r1)
	  stfd      f30, 0x98(r1)
	  stfd      f29, 0x90(r1)
	  stfd      f28, 0x88(r1)
	  stmw      r25, 0x6C(r1)
	  addi      r29, r3, 0
	  add       r4, r29, r0
	  lwz       r31, 0x3068(r13)
	  lfs       f1, -0x5610(r2)
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lfs       f2, 0x130(r4)
	  lfs       f0, -0x5634(r2)
	  lwz       r12, 0xC(r12)
	  fadds     f29, f1, f2
	  fsubs     f28, f2, f0
	  lfs       f31, 0x12C(r4)
	  lfs       f30, 0x134(r4)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lis       r4, 0x802B
	  addi      r30, r3, 0
	  subi      r27, r5, 0x3064
	  subi      r28, r4, 0x32D4
	  b         .loc_0x1B0

	.loc_0x78:
	  cmpwi     r30, -0x1
	  bne-      .loc_0xA0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3
	  b         .loc_0xBC

	.loc_0xA0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r26, r3

	.loc_0xBC:
	  cmplwi    r26, 0
	  beq-      .loc_0x194
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x194
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x194
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x194
	  lwz       r0, 0x184(r26)
	  lwz       r25, 0x0(r29)
	  cmplw     r0, r25
	  beq-      .loc_0x194
	  lfs       f0, 0x98(r26)
	  fcmpo     cr0, f0, f29
	  bge-      .loc_0x194
	  fcmpo     cr0, f0, f28
	  ble-      .loc_0x194
	  fmr       f3, f31
	  lfs       f1, 0x94(r26)
	  fmr       f4, f30
	  lfs       f2, 0x9C(r26)
	  bl        -0x120368
	  lwz       r3, 0x224(r25)
	  lfs       f0, 0x330(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x194
	  lwz       r6, 0x0(r29)
	  addi      r3, r26, 0
	  addi      r4, r1, 0x40
	  lwz       r5, 0x224(r6)
	  lfs       f0, 0x350(r5)
	  stw       r27, 0x40(r1)
	  stw       r6, 0x44(r1)
	  stw       r28, 0x40(r1)
	  stfs      f0, 0x48(r1)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x194:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0x1B0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1D8
	  li        r0, 0x1
	  b         .loc_0x204

	.loc_0x1D8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x200
	  li        r0, 0x1
	  b         .loc_0x204

	.loc_0x200:
	  li        r0, 0

	.loc_0x204:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x78
	  lmw       r25, 0x6C(r1)
	  lwz       r0, 0xAC(r1)
	  lfd       f31, 0xA0(r1)
	  lfd       f30, 0x98(r1)
	  lfd       f29, 0x90(r1)
	  lfd       f28, 0x88(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80158A74
 * Size:	0002C4
 */
void SpiderLeg::stepShakeOffPiki(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x108(r1)
	  stfd      f31, 0x100(r1)
	  stfd      f30, 0xF8(r1)
	  stfd      f29, 0xF0(r1)
	  stfd      f28, 0xE8(r1)
	  stfd      f27, 0xE0(r1)
	  stmw      r17, 0xA4(r1)
	  mr        r23, r3
	  addi      r24, r4, 0
	  li        r27, 0
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x220(r3)
	  bl        -0xCF3A4
	  mr.       r26, r3
	  beq-      .loc_0x50
	  mr        r3, r26
	  bl        -0xD0D2C
	  mr        r27, r3

	.loc_0x50:
	  addi      r3, r1, 0x84
	  lwz       r4, 0x0(r23)
	  bl        -0xC7E48
	  addi      r29, r1, 0x84
	  addi      r3, r29, 0
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lis       r5, 0x802B
	  lfs       f31, -0x560C(r2)
	  lis       r4, 0x802B
	  lfd       f27, -0x5668(r2)
	  lis       r6, 0x802D
	  lfs       f28, -0x5674(r2)
	  lfs       f29, -0x5678(r2)
	  addi      r28, r3, 0
	  lfs       f30, -0x563C(r2)
	  subi      r21, r5, 0x3064
	  subi      r22, r4, 0x3168
	  addi      r30, r1, 0x4C
	  subi      r31, r6, 0xAA8
	  lis       r20, 0x4330
	  b         .loc_0x240

	.loc_0xB0:
	  cmpwi     r28, -0x1
	  bne-      .loc_0xD8
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3
	  b         .loc_0xF4

	.loc_0xD8:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r18, r3

	.loc_0xF4:
	  cmplwi    r18, 0
	  beq-      .loc_0x224
	  mr        r3, r18
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x224
	  addi      r17, r31, 0
	  li        r25, 0
	  b         .loc_0x21C

	.loc_0x124:
	  lwz       r0, 0x0(r17)
	  cmpw      r24, r0
	  bne-      .loc_0x214
	  lwz       r0, 0x188(r18)
	  cmplwi    r0, 0
	  beq-      .loc_0x214
	  cmplwi    r26, 0
	  beq-      .loc_0x214
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  bl        -0xD0DD4
	  cmplwi    r3, 0
	  beq-      .loc_0x214
	  lwz       r4, 0x188(r18)
	  addi      r3, r1, 0x60
	  bl        -0xD0D34
	  lwz       r19, 0x60(r1)
	  addi      r3, r26, 0
	  addi      r4, r25, 0
	  bl        -0xD0DF8
	  addi      r4, r3, 0
	  addi      r3, r1, 0x6C
	  bl        -0xD0D50
	  lwz       r0, 0x6C(r1)
	  cmplw     r0, r19
	  bne-      .loc_0x214
	  lwz       r3, 0x0(r23)
	  lwz       r3, 0x224(r3)
	  addi      r19, r3, 0x360
	  bl        0xBF464
	  xoris     r0, r3, 0x8000
	  lfs       f0, 0x0(r19)
	  stw       r0, 0x9C(r1)
	  stw       r20, 0x98(r1)
	  lfd       f1, 0x98(r1)
	  fsubs     f1, f1, f27
	  fdivs     f1, f1, f28
	  fmuls     f1, f29, f1
	  fmuls     f1, f30, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x214
	  lwz       r7, 0x0(r23)
	  addi      r3, r18, 0
	  addi      r4, r30, 0
	  lwz       r6, 0x224(r7)
	  lfs       f0, 0x370(r6)
	  lfs       f1, 0x380(r6)
	  stw       r21, 0x4C(r1)
	  stw       r7, 0x50(r1)
	  stw       r22, 0x4C(r1)
	  stfs      f0, 0x54(r1)
	  stfs      f1, 0x58(r1)
	  stfs      f31, 0x5C(r1)
	  lwz       r12, 0x0(r18)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r28, 0
	  blt-      .loc_0x214
	  subi      r28, r28, 0x1

	.loc_0x214:
	  addi      r17, r17, 0x4
	  addi      r25, r25, 0x1

	.loc_0x21C:
	  cmpw      r25, r27
	  blt+      .loc_0x124

	.loc_0x224:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r28, r3

	.loc_0x240:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x268
	  li        r0, 0x1
	  b         .loc_0x294

	.loc_0x268:
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x290
	  li        r0, 0x1
	  b         .loc_0x294

	.loc_0x290:
	  li        r0, 0

	.loc_0x294:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0xB0
	  lmw       r17, 0xA4(r1)
	  lwz       r0, 0x10C(r1)
	  lfd       f31, 0x100(r1)
	  lfd       f30, 0xF8(r1)
	  lfd       f29, 0xF0(r1)
	  lfd       f28, 0xE8(r1)
	  lfd       f27, 0xE0(r1)
	  addi      r1, r1, 0x108
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80158D38
 * Size:	000140
 */
void SpiderLeg::emitOnGroundEffect(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  mulli     r4, r30, 0x24
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  lwz       r3, 0x0(r3)
	  addi      r31, r4, 0x12C
	  add       r31, r29, r31
	  addi      r4, r31, 0
	  bl        -0x99FC
	  cmpwi     r3, 0x5
	  bne-      .loc_0x50
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        -0x26F4
	  b         .loc_0x68

	.loc_0x50:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0xE0
	  li        r6, 0
	  li        r7, 0
	  bl        0x43D9C

	.loc_0x68:
	  lwz       r3, 0x0(r29)
	  lbz       r0, 0x3BA(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xD8
	  cmpwi     r30, 0
	  bne-      .loc_0x90
	  lis       r4, 0x6C65
	  addi      r3, r29, 0
	  addi      r4, r4, 0x6733
	  bl        -0x33BC

	.loc_0x90:
	  cmpwi     r30, 0x1
	  bne-      .loc_0xA8
	  lis       r4, 0x6C65
	  addi      r3, r29, 0
	  addi      r4, r4, 0x6734
	  bl        -0x33D4

	.loc_0xA8:
	  cmpwi     r30, 0x2
	  bne-      .loc_0xC0
	  lis       r4, 0x6C65
	  addi      r3, r29, 0
	  addi      r4, r4, 0x6732
	  bl        -0x33EC

	.loc_0xC0:
	  cmpwi     r30, 0x3
	  bne-      .loc_0xD8
	  lis       r4, 0x6C65
	  addi      r3, r29, 0
	  addi      r4, r4, 0x6731
	  bl        -0x3404

	.loc_0xD8:
	  lwz       r3, 0x0(r29)
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xF0
	  li        r4, 0x29
	  bl        -0xB5054

	.loc_0xF0:
	  lwz       r3, 0x3178(r13)
	  addi      r6, r31, 0
	  li        r4, 0xE
	  li        r5, 0
	  bl        0x23F9C
	  lwz       r3, 0x30D8(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3
	  bl        -0x34E70
	  lfs       f1, 0x25C(r29)
	  lfs       f0, -0x5678(r2)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x25C(r29)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void SpiderLeg::onGroundFunction()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
void SpiderLeg::emitOffGroundEffect()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80158E78
 * Size:	000270
 */
void SpiderLeg::setKneeDirection()
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
	  stfd      f26, 0xA0(r1)
	  stfd      f25, 0x98(r1)
	  stfd      f24, 0x90(r1)
	  stfd      f23, 0x88(r1)
	  stfd      f22, 0x80(r1)
	  stmw      r25, 0x64(r1)
	  mr        r31, r3
	  lfs       f1, 0xC8(r3)
	  bl        0xC2E30
	  lis       r3, 0x8022
	  fmr       f29, f1
	  addi      r4, r3, 0x26E0
	  lfs       f23, -0x564C(r2)
	  lwz       r3, 0x0(r4)
	  mr        r27, r31
	  lwz       r0, 0x4(r4)
	  mr        r26, r31
	  lfd       f24, -0x5668(r2)
	  addi      r28, r1, 0x44
	  stw       r3, 0x44(r1)
	  lfs       f25, -0x5678(r2)
	  li        r25, 0
	  stw       r0, 0x48(r1)
	  lis       r30, 0x4330
	  lfs       f30, -0x5658(r2)
	  lwz       r3, 0x8(r4)
	  lwz       r0, 0xC(r4)
	  lfs       f31, -0x568C(r2)
	  stw       r3, 0x4C(r1)
	  stw       r0, 0x50(r1)

	.loc_0x98:
	  lfs       f0, 0x0(r28)
	  lwz       r3, 0x0(r31)
	  fmuls     f0, f30, f0
	  lfs       f27, -0x21C(r13)
	  lfs       f1, 0xA0(r3)
	  lfs       f26, -0x218(r13)
	  fsubs     f22, f1, f0
	  fmr       f1, f22
	  bl        0xC2DB8
	  fmr       f28, f1
	  fmr       f1, f22
	  bl        0xC2C18
	  fmuls     f0, f27, f27
	  fmuls     f2, f28, f28
	  fmr       f27, f1
	  fadds     f0, f2, f0
	  fmuls     f1, f27, f27
	  fadds     f1, f1, f0
	  bl        -0x14B318
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0xF4
	  fdivs     f28, f28, f1
	  fdivs     f27, f27, f1

	.loc_0xF4:
	  lfs       f3, 0x12C(r27)
	  fmuls     f0, f26, f26
	  lfs       f1, 0x264(r31)
	  lfs       f2, 0x134(r27)
	  fsubs     f26, f3, f1
	  lfs       f1, 0x26C(r31)
	  fsubs     f22, f2, f1
	  fmuls     f1, f26, f26
	  fmuls     f2, f22, f22
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14B358
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x134
	  fdivs     f26, f26, f1
	  fdivs     f22, f22, f1

	.loc_0x134:
	  fmuls     f1, f23, f28
	  fmuls     f0, f23, f27
	  fadds     f1, f1, f26
	  fadds     f0, f0, f22
	  stfs      f1, 0xFC(r26)
	  stfs      f31, 0x100(r26)
	  stfs      f0, 0x104(r26)
	  lfs       f1, 0xFC(r26)
	  lfs       f0, 0x100(r26)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x104(r26)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14B3A8
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x1A0
	  lfs       f0, 0xFC(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0xFC(r26)
	  lfs       f0, 0x100(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x100(r26)
	  lfs       f0, 0x104(r26)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x104(r26)

	.loc_0x1A0:
	  stfs      f25, 0x100(r26)
	  lwz       r0, 0xF8(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x21C
	  lfs       f1, 0xFC(r26)
	  lfs       f2, 0x104(r26)
	  bl        0xC29C8
	  xoris     r0, r25, 0x8000
	  lwz       r3, 0x0(r31)
	  stw       r0, 0x5C(r1)
	  fmr       f26, f1
	  lwz       r3, 0x224(r3)
	  stw       r30, 0x58(r1)
	  lfs       f1, 0xCC(r31)
	  addi      r29, r3, 0x410
	  lfd       f0, 0x58(r1)
	  fsubs     f0, f0, f24
	  fmuls     f0, f23, f0
	  fadds     f1, f1, f0
	  bl        0xC2C84
	  lfs       f0, 0x0(r29)
	  fmuls     f0, f29, f0
	  fmuls     f0, f0, f1
	  fadds     f22, f26, f0
	  fmr       f1, f22
	  bl        0xC2C6C
	  stfs      f1, 0xFC(r26)
	  fmr       f1, f22
	  stfs      f25, 0x100(r26)
	  bl        0xC2AC8
	  stfs      f1, 0x104(r26)

	.loc_0x21C:
	  addi      r25, r25, 0x1
	  cmpwi     r25, 0x4
	  addi      r28, r28, 0x4
	  addi      r27, r27, 0x24
	  addi      r26, r26, 0xC
	  blt+      .loc_0x98
	  lmw       r25, 0x64(r1)
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
 * Address:	........
 * Size:	00028C
 */
void SpiderLeg::getJointMatrix(Vector3f&, Vector3f&, Vector3f&, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000184
 */
void SpiderLeg::calcQuatToMatrix(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801590E8
 * Size:	000684
 */
void SpiderLeg::create3Joint(BossShapeObject*, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1C8(r1)
	  stfd      f31, 0x1C0(r1)
	  stfd      f30, 0x1B8(r1)
	  stfd      f29, 0x1B0(r1)
	  stfd      f28, 0x1A8(r1)
	  stmw      r17, 0x16C(r1)
	  li        r23, 0
	  addi      r19, r3, 0
	  mulli     r8, r23, 0xC
	  mulli     r7, r23, 0x24
	  lis       r3, 0x802D
	  subi      r0, r3, 0xAD8
	  rlwinm    r6,r23,3,0,28
	  rlwinm    r3,r23,8,0,23
	  add       r24, r0, r8
	  addi      r20, r4, 0
	  addi      r21, r5, 0
	  addi      r25, r19, 0
	  add       r29, r19, r7
	  lfs       f31, -0x568C(r2)
	  add       r28, r19, r8
	  add       r27, r19, r6
	  add       r26, r19, r3
	  addi      r31, r1, 0x104
	  addi      r30, r1, 0xF8

	.loc_0x6C:
	  lfs       f1, 0x8C(r27)
	  addi      r3, r29, 0x144
	  lfs       f2, 0x88(r27)
	  addi      r4, r29, 0x12C
	  addi      r5, r28, 0xFC
	  addi      r6, r29, 0x138
	  bl        0x233B8
	  lfs       f3, 0x144(r29)
	  lfs       f2, 0x12C(r29)
	  lfs       f1, 0x148(r29)
	  lfs       f0, 0x130(r29)
	  fsubs     f28, f3, f2
	  lfs       f3, 0x14C(r29)
	  lfs       f2, 0x134(r29)
	  fsubs     f29, f1, f0
	  lfs       f1, -0x214(r13)
	  lfs       f0, -0x210(r13)
	  fsubs     f30, f3, f2
	  stfs      f1, 0x134(r1)
	  stfs      f0, 0x138(r1)
	  lfs       f0, -0x20C(r13)
	  stfs      f0, 0x13C(r1)
	  lfs       f1, -0x208(r13)
	  lfs       f0, -0x204(r13)
	  stfs      f1, 0x140(r1)
	  stfs      f0, 0x144(r1)
	  lfs       f0, -0x200(r13)
	  stfs      f0, 0x148(r1)
	  lfs       f1, -0x1FC(r13)
	  lfs       f0, -0x1F8(r13)
	  stfs      f1, 0x14C(r1)
	  stfs      f0, 0x150(r1)
	  lfs       f0, -0x1F4(r13)
	  stfs      f0, 0x154(r1)
	  lfs       f1, 0x138(r29)
	  lfs       f0, 0x144(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x134(r1)
	  lfs       f1, 0x13C(r29)
	  lfs       f0, 0x148(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x138(r1)
	  lfs       f1, 0x140(r29)
	  lfs       f0, 0x14C(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x13C(r1)
	  lfs       f2, 0x148(r1)
	  lfs       f6, 0x144(r1)
	  lfs       f5, 0x140(r1)
	  fmuls     f1, f29, f2
	  fmuls     f0, f30, f6
	  fmuls     f3, f30, f5
	  fmuls     f2, f28, f2
	  fsubs     f4, f1, f0
	  fmuls     f1, f28, f6
	  fmuls     f0, f29, f5
	  fsubs     f2, f3, f2
	  stfs      f4, 0x14C(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x150(r1)
	  stfs      f0, 0x154(r1)
	  lfs       f7, 0x13C(r1)
	  lfs       f5, 0x150(r1)
	  lfs       f8, 0x134(r1)
	  fmuls     f2, f7, f7
	  lfs       f0, 0x154(r1)
	  fmuls     f4, f5, f7
	  lfs       f9, 0x138(r1)
	  lfs       f10, 0x14C(r1)
	  fmuls     f3, f0, f9
	  fmuls     f1, f0, f8
	  fmuls     f0, f10, f7
	  fsubs     f6, f4, f3
	  fmuls     f4, f10, f9
	  fmuls     f3, f5, f8
	  fsubs     f5, f1, f0
	  stfs      f6, 0x140(r1)
	  fmuls     f1, f8, f8
	  fmuls     f0, f9, f9
	  fsubs     f3, f4, f3
	  stfs      f5, 0x144(r1)
	  fadds     f0, f1, f0
	  stfs      f3, 0x148(r1)
	  lfs       f3, 0x148(r1)
	  fadds     f1, f2, f0
	  lfs       f10, 0x144(r1)
	  lfs       f6, 0x140(r1)
	  fmuls     f2, f9, f3
	  fmuls     f0, f7, f10
	  fmuls     f4, f7, f6
	  fmuls     f3, f8, f3
	  fsubs     f5, f2, f0
	  fmuls     f2, f8, f10
	  fmuls     f0, f9, f6
	  fsubs     f3, f4, f3
	  stfs      f5, 0x14C(r1)
	  fsubs     f0, f2, f0
	  stfs      f3, 0x150(r1)
	  stfs      f0, 0x154(r1)
	  bl        -0x14B6A0
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x228
	  lfs       f0, 0x134(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x134(r1)
	  lfs       f0, 0x138(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x138(r1)
	  lfs       f0, 0x13C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x13C(r1)

	.loc_0x228:
	  lfs       f1, 0x140(r1)
	  lfs       f0, 0x144(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x148(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14B6F0
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x278
	  lfs       f0, 0x140(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x140(r1)
	  lfs       f0, 0x144(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x144(r1)
	  lfs       f0, 0x148(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x148(r1)

	.loc_0x278:
	  lfs       f1, 0x14C(r1)
	  lfs       f0, 0x150(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x154(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14B740
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x2C8
	  lfs       f0, 0x14C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x14C(r1)
	  lfs       f0, 0x150(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x150(r1)
	  lfs       f0, 0x154(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x154(r1)

	.loc_0x2C8:
	  addi      r3, r1, 0x134
	  addi      r4, r1, 0x140
	  addi      r5, r1, 0x14C
	  addi      r6, r29, 0x144
	  addi      r7, r26, 0x300
	  bl        0x22FC4
	  lfs       f1, -0x214(r13)
	  lfs       f0, -0x210(r13)
	  stfs      f1, 0x110(r1)
	  stfs      f0, 0x114(r1)
	  lfs       f0, -0x20C(r13)
	  stfs      f0, 0x118(r1)
	  lfs       f1, -0x208(r13)
	  lfs       f0, -0x204(r13)
	  stfs      f1, 0x11C(r1)
	  stfs      f0, 0x120(r1)
	  lfs       f0, -0x200(r13)
	  stfs      f0, 0x124(r1)
	  lfs       f1, -0x1FC(r13)
	  lfs       f0, -0x1F8(r13)
	  stfs      f1, 0x128(r1)
	  stfs      f0, 0x12C(r1)
	  lfs       f0, -0x1F4(r13)
	  stfs      f0, 0x130(r1)
	  lfs       f1, 0x12C(r29)
	  lfs       f0, 0x138(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x110(r1)
	  lfs       f1, 0x130(r29)
	  lfs       f0, 0x13C(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x114(r1)
	  lfs       f1, 0x134(r29)
	  lfs       f0, 0x140(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x118(r1)
	  lfs       f2, 0x124(r1)
	  lfs       f6, 0x120(r1)
	  lfs       f5, 0x11C(r1)
	  fmuls     f1, f29, f2
	  fmuls     f0, f30, f6
	  fmuls     f3, f30, f5
	  fmuls     f2, f28, f2
	  fsubs     f4, f1, f0
	  fmuls     f1, f28, f6
	  fmuls     f0, f29, f5
	  fsubs     f2, f3, f2
	  stfs      f4, 0x128(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x12C(r1)
	  stfs      f0, 0x130(r1)
	  lfs       f7, 0x118(r1)
	  lfs       f5, 0x12C(r1)
	  lfs       f8, 0x110(r1)
	  fmuls     f2, f7, f7
	  lfs       f0, 0x130(r1)
	  fmuls     f4, f5, f7
	  lfs       f9, 0x114(r1)
	  lfs       f10, 0x128(r1)
	  fmuls     f3, f0, f9
	  fmuls     f1, f0, f8
	  fmuls     f0, f10, f7
	  fsubs     f6, f4, f3
	  fmuls     f4, f10, f9
	  fmuls     f3, f5, f8
	  fsubs     f5, f1, f0
	  stfs      f6, 0x11C(r1)
	  fmuls     f1, f8, f8
	  fmuls     f0, f9, f9
	  fsubs     f3, f4, f3
	  stfs      f5, 0x120(r1)
	  fadds     f0, f1, f0
	  stfs      f3, 0x124(r1)
	  lfs       f3, 0x124(r1)
	  fadds     f1, f2, f0
	  lfs       f10, 0x120(r1)
	  lfs       f6, 0x11C(r1)
	  fmuls     f2, f9, f3
	  fmuls     f0, f7, f10
	  fmuls     f4, f7, f6
	  fmuls     f3, f8, f3
	  fsubs     f5, f2, f0
	  fmuls     f2, f8, f10
	  fmuls     f0, f9, f6
	  fsubs     f3, f4, f3
	  stfs      f5, 0x128(r1)
	  fsubs     f0, f2, f0
	  stfs      f3, 0x12C(r1)
	  stfs      f0, 0x130(r1)
	  bl        -0x14B8D4
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x45C
	  lfs       f0, 0x110(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x110(r1)
	  lfs       f0, 0x114(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x114(r1)
	  lfs       f0, 0x118(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x118(r1)

	.loc_0x45C:
	  lfs       f1, 0x11C(r1)
	  lfs       f0, 0x120(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x124(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14B924
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x4AC
	  lfs       f0, 0x11C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x11C(r1)
	  lfs       f0, 0x120(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x120(r1)
	  lfs       f0, 0x124(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x124(r1)

	.loc_0x4AC:
	  lfs       f1, 0x128(r1)
	  lfs       f0, 0x12C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x130(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14B974
	  fcmpu     cr0, f31, f1
	  beq-      .loc_0x4FC
	  lfs       f0, 0x128(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x128(r1)
	  lfs       f0, 0x12C(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x12C(r1)
	  lfs       f0, 0x130(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x130(r1)

	.loc_0x4FC:
	  addi      r3, r1, 0x110
	  addi      r4, r1, 0x11C
	  addi      r5, r1, 0x128
	  addi      r6, r29, 0x138
	  addi      r7, r26, 0x2C0
	  bl        0x22D90
	  lbz       r0, 0x8(r19)
	  cmplwi    r0, 0
	  beq-      .loc_0x5DC
	  lfs       f0, 0x60(r25)
	  fcmpo     cr0, f0, f31
	  ble-      .loc_0x5DC
	  stfs      f31, 0xCC(r1)
	  addi      r3, r1, 0xD4
	  stfs      f31, 0xC8(r1)
	  stfs      f31, 0xC4(r1)
	  bl        -0x10A778
	  addi      r3, r26, 0x2C0
	  addi      r4, r1, 0x44
	  bl        -0x11B1F4
	  addi      r3, r1, 0x44
	  addi      r4, r26, 0x280
	  addi      r5, r1, 0x84
	  bl        -0x11B56C
	  addi      r3, r1, 0x84
	  addi      r4, r1, 0xD4
	  bl        0x231D0
	  addi      r3, r1, 0xC4
	  addi      r4, r1, 0xD4
	  bl        -0x121D9C
	  lfs       f1, 0x60(r25)
	  addi      r3, r1, 0xC4
	  addi      r4, r19, 0x270
	  li        r5, 0
	  bl        -0x1214E8
	  lfs       f1, -0x1E4(r13)
	  mr        r4, r30
	  lfs       f0, -0x1F0(r13)
	  mr        r6, r31
	  stfs      f1, 0x104(r1)
	  lfs       f1, -0x1E0(r13)
	  addi      r3, r1, 0x84
	  stfs      f0, 0xF8(r1)
	  addi      r5, r1, 0xC4
	  lfs       f0, -0x1EC(r13)
	  stfs      f1, 0x108(r1)
	  lfs       f1, -0x1DC(r13)
	  stfs      f0, 0xFC(r1)
	  lfs       f0, -0x1E8(r13)
	  stfs      f1, 0x10C(r1)
	  stfs      f0, 0x100(r1)
	  bl        -0x11A9AC
	  addi      r3, r26, 0x2C0
	  addi      r4, r1, 0x84
	  addi      r5, r26, 0x280
	  bl        -0x11B5EC

	.loc_0x5DC:
	  lfs       f0, 0x12C(r29)
	  li        r22, 0
	  rlwinm    r3,r22,2,0,29
	  stfs      f0, 0x28C(r26)
	  rlwinm    r0,r22,6,0,25
	  add       r18, r24, r3
	  lfs       f0, 0x130(r29)
	  add       r17, r26, r0
	  stfs      f0, 0x29C(r26)
	  lfs       f0, 0x134(r29)
	  stfs      f0, 0x2AC(r26)

	.loc_0x608:
	  lwz       r3, 0x0(r20)
	  lwz       r4, 0x0(r18)
	  bl        -0x124710
	  lwz       r4, 0x2E4(r21)
	  addi      r5, r3, 0
	  addi      r3, r4, 0x1E0
	  addi      r4, r17, 0x280
	  bl        -0x11B638
	  addi      r22, r22, 0x1
	  cmpwi     r22, 0x3
	  addi      r18, r18, 0x4
	  addi      r17, r17, 0x40
	  blt+      .loc_0x608
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x4
	  addi      r29, r29, 0x24
	  addi      r28, r28, 0xC
	  addi      r27, r27, 0x8
	  addi      r26, r26, 0x100
	  addi      r25, r25, 0x4
	  addi      r24, r24, 0xC
	  blt+      .loc_0x6C
	  lmw       r17, 0x16C(r1)
	  lwz       r0, 0x1CC(r1)
	  lfd       f31, 0x1C0(r1)
	  lfd       f30, 0x1B8(r1)
	  lfd       f29, 0x1B0(r1)
	  lfd       f28, 0x1A8(r1)
	  addi      r1, r1, 0x1C8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void SpiderLeg::createMatrixScale(BossShapeObject*, Graphics&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SpiderLeg::setGroundFlag()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void SpiderLeg::checkMotionFinished()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8015976C
 * Size:	0002EC
 */
void SpiderLeg::update()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stfd      f31, 0x98(r1)
	  stfd      f30, 0x90(r1)
	  stfd      f29, 0x88(r1)
	  stfd      f28, 0x80(r1)
	  stw       r31, 0x7C(r1)
	  mr        r31, r3
	  bl        -0x28D8
	  lbz       r0, 0x8(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x8C
	  lwz       r0, 0xF8(r31)
	  cmpwi     r0, 0x1
	  beq-      .loc_0x78
	  bge-      .loc_0x50
	  cmpwi     r0, 0
	  bge-      .loc_0x5C
	  b         .loc_0x8C

	.loc_0x50:
	  cmpwi     r0, 0x3
	  bge-      .loc_0x8C
	  b         .loc_0x84

	.loc_0x5C:
	  mr        r3, r31
	  bl        -0x27AC
	  mr        r3, r31
	  bl        -0x2474
	  mr        r3, r31
	  bl        -0x20D8
	  b         .loc_0x8C

	.loc_0x78:
	  mr        r3, r31
	  bl        -0x2774
	  b         .loc_0x8C

	.loc_0x84:
	  mr        r3, r31
	  bl        -0x2648

	.loc_0x8C:
	  mr        r3, r31
	  bl        -0x1E10
	  mr        r3, r31
	  bl        -0x1CB0
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x7
	  bge-      .loc_0xE8
	  lfs       f4, 0x94(r3)
	  lfs       f1, 0x12C(r31)
	  lfs       f5, 0x9C(r3)
	  lfs       f0, 0x134(r31)
	  fsubs     f2, f1, f4
	  lfs       f3, 0x174(r31)
	  fsubs     f0, f0, f5
	  lfs       f1, 0x17C(r31)
	  fadds     f2, f3, f2
	  fadds     f0, f1, f0
	  fsubs     f1, f2, f4
	  fsubs     f2, f0, f5
	  bl        0xC21B0
	  lwz       r3, 0x0(r31)
	  stfs      f1, 0x8C(r3)

	.loc_0xE8:
	  lwz       r3, 0x0(r31)
	  lfs       f0, 0x8C(r3)
	  stfs      f0, 0xA0(r3)
	  lwz       r0, 0xF8(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x120
	  lwz       r3, 0x0(r31)
	  lfs       f0, 0x80(r31)
	  lfs       f1, 0x8C(r3)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8C(r3)
	  lwz       r3, 0x0(r31)
	  lfs       f0, 0x8C(r3)
	  stfs      f0, 0xA0(r3)

	.loc_0x120:
	  mr        r3, r31
	  bl        -0x1BD4
	  lwz       r0, 0xF8(r31)
	  cmpwi     r0, 0
	  ble-      .loc_0x164
	  lbz       r0, 0x1D(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x164
	  lbz       r0, 0x1E(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0x164
	  lwz       r3, 0x0(r31)
	  bl        -0xB844
	  lwz       r3, 0x0(r31)
	  li        r0, 0
	  lwz       r3, 0x3C0(r3)
	  stb       r0, 0x8(r3)

	.loc_0x164:
	  lwz       r4, 0x0(r31)
	  mr        r3, r31
	  lfs       f0, -0x224(r13)
	  addi      r5, r4, 0x98
	  stfs      f0, 0x54(r1)
	  addi      r4, r1, 0x54
	  lfs       f0, 0x0(r5)
	  stfs      f0, 0x58(r1)
	  lfs       f0, -0x220(r13)
	  stfs      f0, 0x5C(r1)
	  bl        -0x1A6C
	  addi      r3, r31, 0
	  addi      r4, r1, 0x54
	  bl        -0x17B8
	  lfs       f0, -0x568C(r2)
	  addi      r6, r1, 0x30
	  addi      r5, r1, 0x2C
	  stfs      f0, 0x4C(r1)
	  addi      r4, r1, 0x28
	  addi      r3, r1, 0x44
	  stfs      f0, 0x48(r1)
	  stfs      f0, 0x44(r1)
	  lfs       f0, 0x54(r1)
	  lfs       f2, 0x26C(r31)
	  lfs       f1, 0x5C(r1)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x30(r1)
	  lfs       f2, 0x268(r31)
	  lfs       f1, 0x58(r1)
	  fsubs     f1, f2, f1
	  stfs      f1, 0x2C(r1)
	  lfs       f1, 0x264(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x28(r1)
	  bl        -0xFC2CC
	  lfs       f1, 0x44(r1)
	  lfs       f0, 0x48(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x4C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14BD3C
	  lwz       r3, 0x0(r31)
	  lwz       r3, 0x224(r3)
	  lfs       f0, 0x3D0(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2B0
	  lfs       f3, 0x54(r1)
	  fsubs     f31, f1, f0
	  lfs       f2, 0x264(r31)
	  lfs       f1, 0x58(r1)
	  lfs       f0, 0x268(r31)
	  fsubs     f30, f3, f2
	  lfs       f2, 0x5C(r1)
	  fsubs     f29, f1, f0
	  lfs       f0, 0x26C(r31)
	  fmuls     f1, f30, f30
	  fsubs     f28, f2, f0
	  fmuls     f0, f29, f29
	  fmuls     f2, f28, f28
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14BD90
	  lfs       f0, -0x568C(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x280
	  fdivs     f30, f30, f1
	  fdivs     f29, f29, f1
	  fdivs     f28, f28, f1

	.loc_0x280:
	  fmuls     f30, f30, f31
	  lfs       f0, 0x264(r31)
	  fmuls     f29, f29, f31
	  fmuls     f28, f28, f31
	  fadds     f0, f0, f30
	  stfs      f0, 0x264(r31)
	  lfs       f0, 0x268(r31)
	  fadds     f0, f0, f29
	  stfs      f0, 0x268(r31)
	  lfs       f0, 0x26C(r31)
	  fadds     f0, f0, f28
	  stfs      f0, 0x26C(r31)

	.loc_0x2B0:
	  lfs       f0, 0x264(r31)
	  lwz       r3, 0x0(r31)
	  stfs      f0, 0x94(r3)
	  lfs       f0, 0x26C(r31)
	  lwz       r3, 0x0(r31)
	  stfs      f0, 0x9C(r3)
	  lwz       r0, 0xA4(r1)
	  lfd       f31, 0x98(r1)
	  lfd       f30, 0x90(r1)
	  lfd       f29, 0x88(r1)
	  lfd       f28, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80159A58
 * Size:	0006A4
 */
void SpiderLeg::refresh(BossShapeObject*, Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x160(r1)
	  stfd      f31, 0x158(r1)
	  addi      r6, r1, 0xCC
	  stfd      f30, 0x150(r1)
	  stfd      f29, 0x148(r1)
	  stmw      r19, 0x114(r1)
	  addi      r24, r3, 0
	  addi      r25, r4, 0
	  addi      r26, r5, 0
	  bl        -0x172C
	  li        r31, 0
	  mulli     r4, r31, 0xC
	  lis       r3, 0x802D
	  subi      r0, r3, 0xAD8
	  rlwinm    r3,r31,8,0,23
	  add       r28, r0, r4
	  addi      r27, r24, 0
	  add       r29, r24, r3

	.loc_0x50:
	  li        r23, 0
	  rlwinm    r3,r23,6,0,25
	  rlwinm    r0,r23,2,0,29
	  addi      r30, r27, 0
	  add       r21, r29, r3
	  add       r22, r28, r0

	.loc_0x68:
	  lwz       r3, 0x0(r25)
	  lwz       r4, 0x0(r22)
	  bl        -0x124AE0
	  addi      r4, r3, 0
	  addi      r3, r1, 0xCC
	  addi      r5, r21, 0x280
	  bl        -0x11BA04
	  cmpwi     r23, 0
	  bne-      .loc_0x9C
	  lwz       r3, 0x0(r24)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x7
	  blt-      .loc_0xB4

	.loc_0x9C:
	  lfs       f0, 0x28C(r21)
	  stfs      f0, 0x12C(r30)
	  lfs       f0, 0x29C(r21)
	  stfs      f0, 0x130(r30)
	  lfs       f0, 0x2AC(r21)
	  stfs      f0, 0x134(r30)

	.loc_0xB4:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x3
	  addi      r21, r21, 0x40
	  addi      r22, r22, 0x4
	  addi      r30, r30, 0xC
	  blt+      .loc_0x68
	  addi      r31, r31, 0x1
	  cmpwi     r31, 0x4
	  addi      r29, r29, 0x100
	  addi      r28, r28, 0xC
	  addi      r27, r27, 0x24
	  blt+      .loc_0x50
	  lwz       r3, 0x0(r24)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x7
	  blt-      .loc_0x224
	  lfs       f31, -0x568C(r2)
	  addi      r20, r24, 0
	  addi      r19, r24, 0
	  addi      r28, r1, 0x70
	  addi      r29, r1, 0x6C
	  addi      r30, r1, 0x68
	  addi      r31, r1, 0x64
	  addi      r22, r1, 0x60
	  addi      r21, r1, 0x5C
	  li        r23, 0

	.loc_0x11C:
	  stfs      f31, 0xAC(r1)
	  addi      r27, r20, 0x138
	  addi      r4, r30, 0
	  stfs      f31, 0xA8(r1)
	  addi      r5, r29, 0
	  addi      r6, r28, 0
	  stfs      f31, 0xA4(r1)
	  addi      r3, r1, 0xA4
	  lfs       f1, 0x140(r20)
	  lfs       f0, 0x134(r20)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x13C(r20)
	  lfs       f0, 0x130(r20)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x6C(r1)
	  lfs       f1, 0x138(r20)
	  lfs       f0, 0x12C(r20)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x68(r1)
	  bl        -0xFC538
	  lfs       f1, 0xA4(r1)
	  lfs       f0, 0xA8(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xAC(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14BFA8
	  stfs      f1, 0x88(r19)
	  mr        r4, r21
	  addi      r5, r22, 0
	  stfs      f31, 0xA0(r1)
	  addi      r6, r31, 0
	  addi      r3, r1, 0x98
	  stfs      f31, 0x9C(r1)
	  stfs      f31, 0x98(r1)
	  lfs       f1, 0x14C(r20)
	  lfs       f0, 0x8(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x148(r20)
	  lfs       f0, 0x4(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  lfs       f1, 0x144(r20)
	  lfs       f0, 0x0(r27)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x5C(r1)
	  bl        -0xFC5B0
	  lfs       f1, 0x98(r1)
	  lfs       f0, 0x9C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x14C020
	  addi      r23, r23, 0x1
	  stfs      f1, 0x8C(r19)
	  cmpwi     r23, 0x4
	  addi      r20, r20, 0x24
	  addi      r19, r19, 0x8
	  blt+      .loc_0x11C

	.loc_0x224:
	  mr        r3, r24
	  bl        -0x17B4
	  lbz       r0, 0x8(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x310
	  li        r0, 0x2
	  mtctr     r0
	  li        r4, 0

	.loc_0x244:
	  add       r3, r24, r4
	  lbz       r0, 0xD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2A4
	  lbz       r0, 0x11(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x2A4
	  addi      r5, r3, 0x19
	  lbz       r0, 0x19(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x2A4
	  addic.    r0, r4, 0x1
	  addi      r3, r4, 0x1
	  bge-      .loc_0x284
	  addi      r3, r3, 0x4
	  b         .loc_0x290

	.loc_0x284:
	  cmpwi     r3, 0x3
	  ble-      .loc_0x290
	  subi      r3, r3, 0x4

	.loc_0x290:
	  addi      r0, r3, 0x15
	  li        r3, 0x1
	  stbx      r3, r24, r0
	  li        r0, 0
	  stb       r0, 0x0(r5)

	.loc_0x2A4:
	  addi      r4, r4, 0x1
	  add       r3, r24, r4
	  lbz       r0, 0xD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x308
	  lbz       r0, 0x11(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x308
	  addi      r5, r3, 0x19
	  lbz       r0, 0x19(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x308
	  addic.    r0, r4, 0x1
	  addi      r3, r4, 0x1
	  bge-      .loc_0x2E8
	  addi      r3, r3, 0x4
	  b         .loc_0x2F4

	.loc_0x2E8:
	  cmpwi     r3, 0x3
	  ble-      .loc_0x2F4
	  subi      r3, r3, 0x4

	.loc_0x2F4:
	  addi      r0, r3, 0x15
	  li        r3, 0x1
	  stbx      r3, r24, r0
	  li        r0, 0
	  stb       r0, 0x0(r5)

	.loc_0x308:
	  addi      r4, r4, 0x1
	  bdnz+     .loc_0x244

	.loc_0x310:
	  lbz       r0, 0x8(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x40C
	  lfs       f4, 0x130(r24)
	  lfs       f2, 0x70(r24)
	  lfs       f3, -0x5628(r2)
	  fsubs     f2, f4, f2
	  lfs       f1, -0x568C(r2)
	  lfs       f0, -0x5678(r2)
	  fsubs     f2, f2, f3
	  fdivs     f2, f2, f3
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x34C
	  fmr       f2, f1
	  b         .loc_0x358

	.loc_0x34C:
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x358
	  fmr       f2, f0

	.loc_0x358:
	  stfs      f2, 0x60(r24)
	  addi      r3, r24, 0x4
	  addi      r4, r24, 0x24
	  lfs       f4, 0x154(r24)
	  lfs       f2, 0x74(r24)
	  fsubs     f2, f4, f2
	  fsubs     f2, f2, f3
	  fdivs     f2, f2, f3
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x388
	  fmr       f2, f1
	  b         .loc_0x394

	.loc_0x388:
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x394
	  fmr       f2, f0

	.loc_0x394:
	  stfs      f2, 0x60(r3)
	  lfs       f4, 0x154(r4)
	  addi      r4, r4, 0x24
	  lfs       f2, 0x74(r3)
	  addi      r3, r3, 0x4
	  fsubs     f2, f4, f2
	  fsubs     f2, f2, f3
	  fdivs     f2, f2, f3
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x3C4
	  fmr       f2, f1
	  b         .loc_0x3D0

	.loc_0x3C4:
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x3D0
	  fmr       f2, f0

	.loc_0x3D0:
	  stfs      f2, 0x60(r3)
	  lfs       f2, 0x74(r3)
	  addi      r3, r3, 0x4
	  lfs       f4, 0x154(r4)
	  fsubs     f2, f4, f2
	  fsubs     f2, f2, f3
	  fdivs     f2, f2, f3
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x3FC
	  fmr       f2, f1
	  b         .loc_0x408

	.loc_0x3FC:
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x408
	  fmr       f2, f0

	.loc_0x408:
	  stfs      f2, 0x60(r3)

	.loc_0x40C:
	  li        r23, 0

	.loc_0x410:
	  add       r3, r24, r23
	  lbz       r0, 0xD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x45C
	  lbz       r0, 0x11(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x45C
	  addi      r3, r24, 0
	  addi      r4, r23, 0
	  bl        -0x1890
	  addi      r3, r24, 0
	  addi      r4, r23, 0
	  bl        -0x1654
	  addi      r3, r24, 0
	  addi      r4, r23, 0
	  bl        -0x1430
	  addi      r3, r24, 0
	  addi      r4, r23, 0
	  bl        -0x1178

	.loc_0x45C:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x4
	  blt+      .loc_0x410
	  li        r23, 0
	  mulli     r0, r23, 0x24
	  add       r19, r24, r0

	.loc_0x474:
	  add       r3, r24, r23
	  lbz       r0, 0xD(r3)
	  cmplwi    r0, 0
	  bne-      .loc_0x4E0
	  lbz       r0, 0x11(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x4E0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r19, 0x12C
	  li        r4, 0xB5
	  li        r6, 0
	  li        r7, 0
	  bl        0x42C3C
	  cmplwi    r3, 0
	  beq-      .loc_0x4B8
	  addi      r0, r19, 0x12C
	  stw       r0, 0x18(r3)

	.loc_0x4B8:
	  lwz       r3, 0x3180(r13)
	  addi      r5, r19, 0x12C
	  li        r4, 0xB6
	  li        r6, 0
	  li        r7, 0
	  bl        0x42C14
	  cmplwi    r3, 0
	  beq-      .loc_0x4E0
	  addi      r0, r19, 0x12C
	  stw       r0, 0x18(r3)

	.loc_0x4E0:
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x4
	  addi      r19, r19, 0x24
	  blt+      .loc_0x474
	  mr        r3, r24
	  bl        -0x10D4
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  addi      r5, r26, 0
	  bl        -0xE74
	  lwz       r3, 0x0(r24)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x590
	  li        r26, 0
	  addi      r20, r24, 0

	.loc_0x520:
	  li        r23, 0
	  addi      r19, r23, 0

	.loc_0x528:
	  lwz       r3, 0x0(r25)
	  mr        r4, r26
	  bl        -0x124FA0
	  add       r3, r3, r19
	  lfs       f0, 0x20(r20)
	  lfs       f29, 0x0(r3)
	  mr        r4, r26
	  lfs       f30, 0x10(r3)
	  lfs       f31, 0x20(r3)
	  fmuls     f29, f29, f0
	  fmuls     f30, f30, f0
	  lwz       r3, 0x0(r25)
	  fmuls     f31, f31, f0
	  bl        -0x124FCC
	  add       r3, r3, r19
	  stfs      f29, 0x0(r3)
	  addi      r23, r23, 0x1
	  cmpwi     r23, 0x3
	  stfs      f30, 0x10(r3)
	  addi      r19, r19, 0x4
	  stfs      f31, 0x20(r3)
	  blt+      .loc_0x528
	  addi      r26, r26, 0x1
	  cmpwi     r26, 0xF
	  addi      r20, r20, 0x4
	  ble+      .loc_0x520

	.loc_0x590:
	  lbz       r0, 0xD(r24)
	  stb       r0, 0x11(r24)
	  lbz       r0, 0xE(r24)
	  stb       r0, 0x12(r24)
	  lbz       r0, 0xF(r24)
	  stb       r0, 0x13(r24)
	  lbz       r0, 0x10(r24)
	  stb       r0, 0x14(r24)
	  lbz       r0, 0x8(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x684
	  lbz       r3, 0x7(r24)
	  li        r0, 0
	  cmplwi    r3, 0
	  beq-      .loc_0x5E0
	  lbz       r3, 0x9(r24)
	  cmplwi    r3, 0
	  bne-      .loc_0x5E0
	  stb       r0, 0x8(r24)
	  b         .loc_0x5EC

	.loc_0x5E0:
	  li        r0, 0x1
	  stb       r0, 0x8(r24)
	  b         .loc_0x66C

	.loc_0x5EC:
	  lbz       r3, 0x7(r24)
	  cmplwi    r3, 0
	  beq-      .loc_0x60C
	  lbz       r3, 0xA(r24)
	  cmplwi    r3, 0
	  bne-      .loc_0x60C
	  stb       r0, 0x8(r24)
	  b         .loc_0x618

	.loc_0x60C:
	  li        r0, 0x1
	  stb       r0, 0x8(r24)
	  b         .loc_0x66C

	.loc_0x618:
	  lbz       r3, 0x7(r24)
	  cmplwi    r3, 0
	  beq-      .loc_0x638
	  lbz       r3, 0xB(r24)
	  cmplwi    r3, 0
	  bne-      .loc_0x638
	  stb       r0, 0x8(r24)
	  b         .loc_0x644

	.loc_0x638:
	  li        r0, 0x1
	  stb       r0, 0x8(r24)
	  b         .loc_0x66C

	.loc_0x644:
	  lbz       r3, 0x7(r24)
	  cmplwi    r3, 0
	  beq-      .loc_0x664
	  lbz       r3, 0xC(r24)
	  cmplwi    r3, 0
	  bne-      .loc_0x664
	  stb       r0, 0x8(r24)
	  b         .loc_0x66C

	.loc_0x664:
	  li        r0, 0x1
	  stb       r0, 0x8(r24)

	.loc_0x66C:
	  lbz       r0, 0x8(r24)
	  cmplwi    r0, 0
	  bne-      .loc_0x684
	  lwz       r3, 0x0(r24)
	  li        r0, 0x1
	  stb       r0, 0x2BD(r3)

	.loc_0x684:
	  lmw       r19, 0x114(r1)
	  lwz       r0, 0x164(r1)
	  lfd       f31, 0x158(r1)
	  lfd       f30, 0x150(r1)
	  lfd       f29, 0x148(r1)
	  addi      r1, r1, 0x160
	  mtlr      r0
	  blr
	*/
}
