#include "ViewPiki.h"
#include "gameflow.h"
#include "Shape.h"
#include "sysNew.h"
#include "MemStat.h"
#include "ItemMgr.h"
#include "MoviePlayer.h"
#include "PikiMgr.h"
#include "UfoItem.h"
#include "AIPerf.h"
#include "MapCode.h"
#include "PikiAI.h"
#include "Font.h"
#include "PikiState.h"
#include "Graphics.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("viewPiki")

PikiShapeObject* PikiShapeObject::_instances[4];
bool PikiShapeObject::firstTime = true;

/*
 * --INFO--
 * Address:	800D8894
 * Size:	000028
 */
void PikiShapeObject::exitCourse()
{
	firstTime     = true;
	_instances[0] = _instances[1] = _instances[2] = _instances[3] = nullptr;
}

/*
 * --INFO--
 * Address:	800D88BC
 * Size:	000028
 */
void PikiShapeObject::init()
{
	firstTime     = true;
	_instances[0] = _instances[1] = _instances[2] = _instances[3] = nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
PikiShapeObject* PikiShapeObject::create(int index)
{
	memStat->start("piki animmgr");
	if (firstTime) {
		initOnce();
	}
	memStat->end("piki animmgr");
	if (index < 0 || index > 3) {
		ERROR("illegal index %d\n");
	}
	return _instances[index];
}

/*
 * --INFO--
 * Address:	800D88E4
 * Size:	00003C
 */
AnimMgr* PikiShapeObject::getAnimMgr()
{
	if (firstTime) {
		initOnce();
	}

	return _instances[0]->mAnimMgr;
}

/*
 * --INFO--
 * Address:	800D8920
 * Size:	0001B4
 */
void PikiShapeObject::initOnce()
{
	_instances[Blue]           = new PikiShapeObject(gameflow.loadShape("pikis/bluModel.mod", true));
	_instances[Blue]->mAnimMgr = new AnimMgr(_instances[Blue]->mShape, "pikis/animMgr.bin", 0x8000, nullptr);

	gameflow.addGenNode("pikiAnimMgr", _instances[Blue]->mAnimMgr);

	_instances[Red]                   = new PikiShapeObject(gameflow.loadShape("pikis/redModel.mod", true));
	_instances[Red]->mAnimMgr         = _instances[Blue]->mAnimMgr;
	_instances[Yellow]                = new PikiShapeObject(gameflow.loadShape("pikis/yelModel.mod", true));
	_instances[Yellow]->mAnimMgr      = _instances[Blue]->mAnimMgr;
	_instances[PIKI_Kinoko]           = new PikiShapeObject(gameflow.loadShape("pikis/kinModel.mod", true));
	_instances[PIKI_Kinoko]->mAnimMgr = _instances[Blue]->mAnimMgr;

	firstTime = false;
}

/*
 * --INFO--
 * Address:	800D8AD4
 * Size:	00009C
 */
PikiShapeObject::PikiShapeObject(Shape* shape)
{
	mShape               = shape;
	mShape->mFrameCacher = gameflow.mFrameCacher;
	mAnimMgr             = nullptr;
	mShape->overrideAnim(0, &mAnimatorA);
	mShape->overrideAnim(1, &mAnimatorB);
}

/*
 * --INFO--
 * Address:	800D8B70
 * Size:	000020
 */
bool ViewPiki::isKinoko()
{
	return mPikiShape == PikiShapeObject::_instances[PIKI_Kinoko];
}

/*
 * --INFO--
 * Address:	800D8B90
 * Size:	000128
 */
void ViewPiki::changeShape(int index)
{
	if (index == -1) {
		index = mFormationPriority;
	}

	mPikiShape = PikiShapeObject::create(index);
	mPikiAnimMgr.changeContext(&mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA);
	mCollInfo->initInfo(mPikiShape->mShape, nullptr, nullptr);

	if (isKinoko()) {
		setColor(mColor);
		mHappaModel = nullptr;
	} else {
		setFlower(mHappa);
	}

	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	setLeaves(index + 1);

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	800D8CB8
 * Size:	000060
 */
ViewPiki::ViewPiki(CreatureProp* prop)
    : Piki(prop)
{
	mPikiShape = nullptr;
	mHappa     = 0;
}

/*
 * --INFO--
 * Address:	800D8D18
 * Size:	0000B4
 */
void ViewPiki::initBirth()
{
	mHappaModel = nullptr;
	mPikiShape  = PikiShapeObject::create(0);
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, pikiMgr->mMotionTable);

	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	setFlower(0);

	f32 badcompiler[4];
}

/*
 * --INFO--
 * Address:	800D8DCC
 * Size:	00026C
 */
void ViewPiki::init(Shape* shp, MapMgr*, Navi* navi)
{
	mPikiShape  = PikiShapeObject::create(0);
	mHappaModel = nullptr;

	mCollInfo = new CollInfo(4);
	mCollInfo->initInfo(mPikiShape->mShape, nullptr, nullptr);
	mPikiAnimMgr.init(mPikiShape->mAnimMgr, &mPikiShape->mAnimatorB, &mPikiShape->mAnimatorA, pikiMgr->mMotionTable);

	f32 scale = 1.0f;
	scale *= pikiMgr->mPikiParms->mPikiParms._12C();
	mScale.set(scale, scale, scale);
	setLeaves(1);

	mPikiAnimMgr.startMotion(PaniMotionInfo(22, this), PaniMotionInfo(22));

	mScale.set(1.0f, 1.0f, 1.0f);
	mRotation.set(0.0f, 0.0f, 0.0f);
	mPosition.set(randBalanced(0.5f) * 300.0f, 0.0f, randBalanced(0.5f) * 300.0f);

	mWorldMtx.makeSRT(mScale, mRotation, mPosition);
	_268 = 0.0f;
	Piki::init(navi);
	mLastPosition       = mPosition;
	mLastEffectPosition = mPosition;

	f32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x802C
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x5CC4
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stw       r31, 0x6C(r1)
	  addi      r31, r6, 0
	  stw       r30, 0x68(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x64(r1)
	  stw       r28, 0x60(r1)
	  lwz       r3, 0x2FE8(r13)
	  bl        -0x526C8
	  lbz       r0, -0x3B90(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x48
	  bl        -0x4F0

	.loc_0x48:
	  lis       r4, 0x802C
	  lwz       r3, 0x2FE8(r13)
	  subi      r4, r4, 0x5CC4
	  bl        -0x525D8
	  lis       r3, 0x803D
	  lwz       r4, 0x1E48(r3)
	  li        r0, 0
	  li        r3, 0x14
	  stw       r4, 0x588(r30)
	  stw       r0, 0x598(r30)
	  bl        -0x91E38
	  addi      r29, r3, 0
	  mr.       r3, r29
	  beq-      .loc_0x88
	  li        r4, 0x4
	  bl        -0x50220

	.loc_0x88:
	  stw       r29, 0x220(r30)
	  li        r5, 0
	  li        r6, 0
	  lwz       r4, 0x588(r30)
	  lwz       r3, 0x220(r30)
	  lwz       r4, 0x0(r4)
	  bl        -0x4F308
	  lwz       r8, 0x588(r30)
	  addi      r3, r30, 0x354
	  lwz       r6, 0x3068(r13)
	  lwz       r4, 0x24(r8)
	  addi      r5, r8, 0x14
	  lwz       r7, 0x64(r6)
	  addi      r6, r8, 0x4
	  bl        0x46A50
	  lwz       r5, 0x3068(r13)
	  mr        r3, r30
	  lfs       f1, -0x6810(r2)
	  li        r4, 0x1
	  lwz       r5, 0x68(r5)
	  lfs       f0, 0x138(r5)
	  fmuls     f1, f1, f0
	  stfs      f1, 0x7C(r30)
	  stfs      f1, 0x80(r30)
	  stfs      f1, 0x84(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x134(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r30, 0
	  addi      r28, r30, 0
	  beq-      .loc_0x10C
	  addi      r28, r28, 0x2B8

	.loc_0x10C:
	  addi      r3, r1, 0x3C
	  li        r4, 0x16
	  bl        0x46078
	  addi      r29, r3, 0
	  addi      r5, r28, 0
	  addi      r3, r1, 0x44
	  li        r4, 0x16
	  bl        0x46098
	  addi      r4, r3, 0
	  addi      r5, r29, 0
	  addi      r3, r30, 0x354
	  bl        0x46B64
	  lfs       f0, -0x3B8C(r13)
	  stfs      f0, 0x7C(r30)
	  lfs       f0, -0x3B88(r13)
	  stfs      f0, 0x80(r30)
	  lfs       f0, -0x3B84(r13)
	  stfs      f0, 0x84(r30)
	  lfs       f0, -0x3B80(r13)
	  stfs      f0, 0x88(r30)
	  lfs       f0, -0x3B7C(r13)
	  stfs      f0, 0x8C(r30)
	  lfs       f0, -0x3B78(r13)
	  stfs      f0, 0x90(r30)
	  bl        0x13F138
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x6800(r2)
	  stw       r0, 0x5C(r1)
	  lis       r29, 0x4330
	  lfs       f1, -0x680C(r2)
	  stw       r29, 0x58(r1)
	  lfs       f0, -0x6810(r2)
	  lfd       f2, 0x58(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f31, f0, f1
	  bl        0x13F108
	  xoris     r0, r3, 0x8000
	  lfs       f1, -0x6804(r2)
	  stw       r0, 0x54(r1)
	  addi      r3, r30, 0x228
	  lfd       f5, -0x6800(r2)
	  fsubs     f0, f31, f1
	  stw       r29, 0x50(r1)
	  lfs       f2, -0x6808(r2)
	  addi      r4, r30, 0x7C
	  lfd       f3, 0x50(r1)
	  lfs       f4, -0x680C(r2)
	  fmuls     f0, f2, f0
	  fsubs     f5, f3, f5
	  lfs       f3, -0x6810(r2)
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  fdivs     f4, f5, f4
	  fmuls     f3, f3, f4
	  fsubs     f1, f3, f1
	  fmuls     f1, f2, f1
	  stfs      f1, 0x94(r30)
	  lfs       f1, -0x3B74(r13)
	  stfs      f1, 0x98(r30)
	  stfs      f0, 0x9C(r30)
	  bl        -0x9AED8
	  lfs       f0, -0x6818(r2)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  stfs      f0, 0x268(r30)
	  bl        -0xCF9C
	  lwz       r3, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x1AC(r30)
	  stw       r0, 0x1B0(r30)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x1B4(r30)
	  lwz       r3, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x58C(r30)
	  stw       r0, 0x590(r30)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x594(r30)
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lwz       r31, 0x6C(r1)
	  lwz       r30, 0x68(r1)
	  lwz       r29, 0x64(r1)
	  lwz       r28, 0x60(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D9038
 * Size:	000064
 */
void ViewPiki::setFlower(int id)
{
	if (!isKinoko()) {
		mHappa      = id;
		mHappaModel = pikiMgr->mLeafModel[id];
	}
}

/*
 * --INFO--
 * Address:	800D909C
 * Size:	000004
 */
void ViewPiki::setLeaves(int)
{
}

/*
 * --INFO--
 * Address:	800D90A0
 * Size:	00017C
 */
void ViewPiki::postUpdate(int _, f32 __)
{
	if (!mMode && !pikiMgr->isUpdating(1)) {
		return;
	}

	if (mMode == 1 && !pikiMgr->isUpdating(2)) {
		return;
	}

	if (!pikiMgr->isUpdating(4)) {
		return;
	}

	if (gameflow.mMoviePlayer->mIsActive && pikiMgr->isUpdating(8)) {
		Vector3f toShip = mPosition - itemMgr->getUfo()->getGoalPos();
		if (toShip.length() > 100.0f) {
			return;
		}
	}

	// Params are unused through all function calls
	Creature::postUpdate(_, __);

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	800D921C
 * Size:	000408
 */
void ViewPiki::update()
{
	if (mMode == PikiMode::FreeMode && !pikiMgr->isUpdating(1)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}
	if (mMode == PikiMode::FormationMode && !pikiMgr->isUpdating(2)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}
	if (!pikiMgr->isUpdating(4)) {
		mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
		return;
	}

	if (gameflow.mMoviePlayer->mIsActive && pikiMgr->isUpdating(8)) {
		Vector3f toShip = mPosition - itemMgr->getUfo()->getGoalPos();
		if (toShip.length() > 100.0f) {
			mVolatileVelocity.set(0.0f, 0.0f, 0.0f);
			return;
		}
	}

	updateColor();
	mHasCollChangedVelocity = 0;
	Creature::update();
	realAI();

	if (mColor == Blue && gameflow.mDemoFlags & 8) {
		return;
	}

	if (mColor == Red && gameflow.mDemoFlags & 0x10) {
		return;
	}

	if (mColor == Yellow && gameflow.mDemoFlags & 0x20) {
		return;
	}

	if (AIPerf::optLevel == 0 && mFloorTri && unitRandFloat() > 0.99f) {
		Vector3f toLastPosition = mLastEffectPosition - mPosition;

		// If we've moved enough, create an effect
		if (toLastPosition.length() > 40.0f) {
			Vector3f pos(mPosition.x, mPosition.y + 1.0f, mPosition.z);
			Vector3f rot(mVelocity.x * 0.01667f, 1.0f, mVelocity.z * 0.01667f);
			EffectParm parm(pos, rot);

			int attr = MapCode::getAttribute(mFloorTri);
			if (attr >= 0 && attr <= 3) {
				utEffectMgr->cast(attr + 3, parm);
			}

			mLastEffectPosition = mPosition;
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x100(r1)
	  stw       r31, 0xFC(r1)
	  mr        r31, r3
	  lhz       r4, 0x4FC(r3)
	  cmplwi    r4, 0
	  bne-      .loc_0x4C
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  rlwinm.   r0,r0,0,31,31
	  bne-      .loc_0x4C
	  lfs       f0, -0x3B70(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x3B6C(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x3B68(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x3F4

	.loc_0x4C:
	  cmplwi    r4, 0x1
	  bne-      .loc_0x80
	  lwz       r3, 0x3068(r13)
	  lhz       r0, 0x70(r3)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x80
	  lfs       f0, -0x3B64(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x3B60(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x3B5C(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x3F4

	.loc_0x80:
	  lwz       r3, 0x3068(r13)
	  lhz       r4, 0x70(r3)
	  rlwinm.   r0,r4,0,29,29
	  bne-      .loc_0xAC
	  lfs       f0, -0x3B58(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x3B54(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x3B50(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x3F4

	.loc_0xAC:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r3, 0x1DC(r3)
	  lbz       r0, 0x124(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1B0
	  rlwinm.   r0,r4,0,28,28
	  beq-      .loc_0x1B0
	  lwz       r3, 0x30AC(r13)
	  bl        0x1994C
	  lwz       r12, 0x0(r3)
	  mr        r4, r3
	  addi      r3, r1, 0x78
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x98(r31)
	  lfs       f2, 0x7C(r1)
	  lfs       f1, 0x94(r31)
	  lfs       f0, 0x78(r1)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x9C(r31)
	  fsubs     f4, f1, f0
	  lfs       f0, 0x80(r1)
	  fmuls     f1, f3, f3
	  fsubs     f3, f2, f0
	  lfs       f0, -0x6818(r2)
	  fmuls     f2, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x188
	  fsqrte    f1, f4
	  lfd       f3, -0x67F8(r2)
	  lfd       f2, -0x67F0(r2)
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
	  stfs      f0, 0x4C(r1)
	  lfs       f4, 0x4C(r1)

	.loc_0x188:
	  lfs       f0, -0x67E8(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x1B0
	  lfs       f0, -0x3B4C(r13)
	  stfs      f0, 0xBC(r31)
	  lfs       f0, -0x3B48(r13)
	  stfs      f0, 0xC0(r31)
	  lfs       f0, -0x3B44(r13)
	  stfs      f0, 0xC4(r31)
	  b         .loc_0x3F4

	.loc_0x1B0:
	  mr        r3, r31
	  bl        -0xF834
	  li        r0, 0
	  stw       r0, 0x1A4(r31)
	  mr        r3, r31
	  bl        -0x4E1D8
	  mr        r3, r31
	  bl        -0xC87C
	  lhz       r4, 0x510(r31)
	  cmplwi    r4, 0
	  bne-      .loc_0x1F0
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,28,28
	  bne-      .loc_0x3F4

	.loc_0x1F0:
	  cmplwi    r4, 0x1
	  bne-      .loc_0x20C
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,27,27
	  bne-      .loc_0x3F4

	.loc_0x20C:
	  cmplwi    r4, 0x2
	  bne-      .loc_0x228
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  lwz       r0, 0x1D8(r3)
	  rlwinm.   r0,r0,0,26,26
	  bne-      .loc_0x3F4

	.loc_0x228:
	  lwz       r0, -0x5F04(r13)
	  cmpwi     r0, 0
	  bne-      .loc_0x3F4
	  lwz       r0, 0x28C(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x3F4
	  bl        0x13EC14
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x6800(r2)
	  stw       r0, 0xF4(r1)
	  lis       r0, 0x4330
	  lfs       f2, -0x680C(r2)
	  stw       r0, 0xF0(r1)
	  lfs       f1, -0x6810(r2)
	  lfd       f3, 0xF0(r1)
	  lfs       f0, -0x67E4(r2)
	  fsubs     f3, f3, f4
	  fdivs     f2, f3, f2
	  fmuls     f1, f1, f2
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x3F4
	  lfs       f3, 0x590(r31)
	  lfs       f2, 0x98(r31)
	  lfs       f1, 0x58C(r31)
	  lfs       f0, 0x94(r31)
	  fsubs     f3, f3, f2
	  lfs       f2, 0x594(r31)
	  fsubs     f4, f1, f0
	  lfs       f0, 0x9C(r31)
	  fmuls     f1, f3, f3
	  fsubs     f3, f2, f0
	  lfs       f0, -0x6818(r2)
	  fmuls     f2, f4, f4
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x318
	  fsqrte    f1, f4
	  lfd       f3, -0x67F8(r2)
	  lfd       f2, -0x67F0(r2)
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
	  stfs      f0, 0x48(r1)
	  lfs       f4, 0x48(r1)

	.loc_0x318:
	  lfs       f0, -0x67E0(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x3F4
	  lfs       f0, 0x94(r31)
	  lfs       f4, -0x6810(r2)
	  stfs      f0, 0xC8(r1)
	  lfs       f3, -0x67DC(r2)
	  lfs       f0, 0x98(r31)
	  lfs       f1, -0x3B40(r13)
	  fadds     f2, f4, f0
	  lfs       f0, -0x6818(r2)
	  stfs      f2, 0xCC(r1)
	  lfs       f2, 0x9C(r31)
	  stfs      f2, 0xD0(r1)
	  lfs       f2, 0x70(r31)
	  fmuls     f2, f3, f2
	  stfs      f2, 0xBC(r1)
	  stfs      f1, 0xC0(r1)
	  lfs       f1, 0x78(r31)
	  stfs      f0, 0x98(r1)
	  fmuls     f1, f3, f1
	  stfs      f0, 0x94(r1)
	  stfs      f0, 0x90(r1)
	  stfs      f0, 0xA4(r1)
	  stfs      f1, 0xC4(r1)
	  stfs      f0, 0xA0(r1)
	  stfs      f0, 0x9C(r1)
	  lwz       r0, 0xC8(r1)
	  lwz       r3, 0xCC(r1)
	  stw       r0, 0x90(r1)
	  lwz       r0, 0xD0(r1)
	  stw       r3, 0x94(r1)
	  lwz       r3, 0xBC(r1)
	  stw       r0, 0x98(r1)
	  lwz       r0, 0xC0(r1)
	  stw       r3, 0x9C(r1)
	  stw       r0, 0xA0(r1)
	  lwz       r0, 0xC4(r1)
	  stw       r0, 0xA4(r1)
	  stfs      f4, 0xB4(r1)
	  lwz       r3, 0x28C(r31)
	  bl        0x3CAA8
	  cmpwi     r3, 0
	  blt-      .loc_0x3DC
	  cmpwi     r3, 0x3
	  bgt-      .loc_0x3DC
	  addi      r3, r3, 0x3
	  addi      r4, r1, 0x90
	  bl        0x3ACEC

	.loc_0x3DC:
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x58C(r31)
	  stw       r0, 0x590(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x594(r31)

	.loc_0x3F4:
	  lwz       r0, 0x104(r1)
	  lwz       r31, 0xFC(r1)
	  addi      r1, r1, 0x100
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800D9624
 * Size:	0000A0
 */
void Piki::startHimaLook(Vector3f* pos)
{
	mLookatTarget = pos;
	mLookTimer    = false;
	mIsLooking    = false;
	mLookAtTarget.reset();
	mIsLooking = 1;
	_334       = gsys->getRand(1.0f) * 3.0f + 4.0f;

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	800D96C4
 * Size:	000018
 */
void Piki::finishLook()
{
	mLookatTarget = nullptr;
	mLookTimer    = 10;
	mIsLooking    = false;
}

/*
 * --INFO--
 * Address:	800D96DC
 * Size:	000014
 */
bool Piki::isLooking()
{
	return mLookatTarget != nullptr;
}

/*
 * --INFO--
 * Address:	800D96F0, 100DE380 in DLL
 * Size:	000378
 */
void Piki::updateLook()
{
	f32 horizontalAngle;
	f32 rotationSpeed = 0.05f;
	f32 horizontalDistance;
	f32 verticalAngle;
	if (mLookatTarget) {
		Vector3f targetOffset = *mLookatTarget - mPosition;
		horizontalAngle       = atan2f(targetOffset.x, targetOffset.z);
		horizontalDistance    = std::sqrtf(targetOffset.x * targetOffset.x + targetOffset.z * targetOffset.z);
		verticalAngle         = atan2f(targetOffset.y, horizontalDistance);
	} else {
		rotationSpeed       = 0.2f;
		f32 diffH           = angDist(0.0f, mHorizontalRotation);
		mHorizontalRotation = roundAng(diffH * rotationSpeed + mHorizontalRotation);
		f32 diffV           = angDist(0.0f, mVerticalRotation);
		mVerticalRotation   = roundAng(diffV * rotationSpeed + mVerticalRotation);
		if (absF(mHorizontalRotation) < 0.1f && absF(mVerticalRotation) < 0.1f) {
			forceFinishLook();
		}
		return;
	}

	f32 currentFacingAngle = roundAng(mHorizontalRotation + mFaceDirection);
	f32 targetAngleDiff    = roundAng(horizontalAngle - mFaceDirection);
	f32 angleAdjustment;

	if (targetAngleDiff < PI) {
		if (mHorizontalRotation > PI) {
			angleAdjustment = TAU - (mHorizontalRotation - targetAngleDiff);
		} else {
			angleAdjustment = angDist(horizontalAngle, currentFacingAngle);
		}
	} else if (mHorizontalRotation <= PI) {
		angleAdjustment = (mHorizontalRotation - targetAngleDiff);
		angleAdjustment = (TAU - angleAdjustment);
		angleAdjustment *= -1.0f;
	} else {
		angleAdjustment = angDist(horizontalAngle, currentFacingAngle);
	}

	if (absF(angleAdjustment) < PI / 20.0f) {
		angleAdjustment = 0.0f;
	}

	mHorizontalRotation = roundAng(angleAdjustment * rotationSpeed + mHorizontalRotation);
	if (mHorizontalRotation > (2.0f * THIRD_PI) && mHorizontalRotation < PI) {
		mHorizontalRotation = (2.0f * THIRD_PI);
	} else if (mHorizontalRotation < (4.0f * THIRD_PI) && mHorizontalRotation >= PI) {
		mHorizontalRotation = (4.0f * THIRD_PI);
	}

	angleAdjustment = angDist(verticalAngle, mVerticalRotation);
	if (absF(angleAdjustment) < PI / 20.0f) {
		angleAdjustment = 0.0f;
	}

	mVerticalRotation = roundAng(angleAdjustment * rotationSpeed + mVerticalRotation);
	if (mVerticalRotation > THIRD_PI && mVerticalRotation < PI) {
		mVerticalRotation = THIRD_PI;
	} else if (mVerticalRotation < (5.0f * THIRD_PI) && mVerticalRotation >= PI) {
		mVerticalRotation = 5.0f * THIRD_PI;
	}

	if (mLookTimer) {
		mLookTimer--;
		if (mLookTimer == 0) {
			forceFinishLook();
		}
	}
}

/*
 * --INFO--
 * Address:	800D9A68
 * Size:	000678
 */
void ViewPiki::demoDraw(Graphics& gfx, Matrix4f* mtx)
{
	Vector3f pos;
	if (AIPerf::optLevel <= 2 || mOptUpdateContext.updatable()) {
		pos.set(0.0f, 0.0f, 0.0f);
		mPikiShape->mShape->calcJointWorldPos(gfx, 0, pos);
		mShadowPos = pos;
		pos.set(0.0f, 4.0f, 0.0f);
		mPikiShape->mShape->calcJointWorldPos(gfx, 1, pos);
		mCatchPos = pos;
	}

	u32 badCompiler;
	if (mHappa == Bud) {
		pos.set(4.0f, 0.0f, 0.0f);
	} else if (mHappa == Flower) {
		pos.set(3.0f, 0.0f, 0.0f);
	} else {
		pos.set(6.0f, 0.0f, 0.0f);
	}
	mPikiShape->mShape->calcJointWorldPos(gfx, 6, pos);
	mEffectPos = pos;

	if (isDamaged() && unitRandFloat() > 0.5f) {
		mPikiShape->mShape->mMaterialList->setColour(Colour(255, 255, 255, 255));
	} else {
		mPikiShape->mShape->mMaterialList->setColour(mCurrentColour);
	}

	if (aiCullable()) {
		mPikiShape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
	}

	if (mIsPanicked) {
		mPanickedEffect->updatePos(mShadowPos);
	}

	if (aiCullable() && AIPerf::optLevel < 3 && mHappaModel) {
		gfx.useMatrix(mPikiShape->mShape->getAnimMatrix(6), 0);
		mHappaModel->drawshape(gfx, *gfx.mCamera, nullptr);
	}

	if (mMode == PikiMode::FormationMode && AIPerf::kandoOnly) {
		gfx.useMatrix(Matrix4f::ident, 0);
		ActCrowd* act = (ActCrowd*)mActiveAction->getCurrAction();
		if (act) {
			Vector3f pos = mPosition;
			int slotID   = act->mCPlateSlotID;
			pos.y += 2.0f * f32(slotID) + 50.0f;
			bool light = gfx.setLighting(false, nullptr);
			gfx.useMatrix(Matrix4f::ident, 0);
			if (act->mState == ActCrowd::STATE_Sort) {
				gfx.setColour(Colour(255, 10, 50, 255), 1);
			} else if (act->mState == ActCrowd::STATE_Unk0) {
				gfx.setColour(Colour(200, 255, 255, 255), 1);
			} else {
				gfx.setColour(Colour(255, 255, 255, 255), 1);
			}

			char* strs[6] = { "A", "B", "C", "D", "E", "F" };
			char buf[256];
			int formMode = act->mMode;
			int cb       = gfx.setCBlending(0);
			pos.multMatrix(gfx.mCamera->mLookAtMtx);
			sprintf(buf, "%s%d", strs[formMode], slotID);
			gfx.perspPrintf(gsys->mConsFont, pos, -(gsys->mConsFont->stringWidth(buf) / 2), 0, buf);
			gfx.setCBlending(cb);
			gfx.setLighting(light, nullptr);
		}
	}

	if (AIPerf::kandoOnly && mActiveAction) {
		if (mActiveAction->getCurrAction()) {
			gfx.useMatrix(Matrix4f::ident, 0);
			mActiveAction->getCurrAction()->draw(gfx);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void printMatrix(char*, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800DA0E0
 * Size:	000B48
 */
void ViewPiki::refresh(Graphics& gfx)
{
	u32 badCompiler[2];
	u32 color = mColor;
	if (color == Blue && gameflow.mDemoFlags & 8) {
		return;
	}
	if (color == Red && gameflow.mDemoFlags & 16) {
		return;
	}
	if (color == Yellow && gameflow.mDemoFlags & 32) {
		return;
	}
	if (mMode == PikiMode::FreeMode && !pikiMgr->isUpdating(1)) {
		return;
	}
	if (mMode == PikiMode::FormationMode && !pikiMgr->isUpdating(2)) {
		return;
	}
	if (!pikiMgr->isUpdating(4)) {
		return;
	}

	if (gameflow.mMoviePlayer->mIsActive && pikiMgr->isUpdating(8)) {
		Vector3f diff = mPosition - itemMgr->getUfo()->getGoalPos();
		if (diff.length() > 100.0f) {
			return;
		}
	}
	Matrix4f mtx;
	f32 size = getSize();
	if (!gfx.mCamera->isPointVisible(mPosition, size * 4.0f)) {
		enableAICulling();
	} else {
		disableAICulling();
		if (AIPerf::useLOD) {
			Vector3f diff = gfx.mCamera->mPosition - mPosition;
			_528          = diff.length();
		} else {
			_528 = 12800.0f;
		}
	}

	if (getState() == PIKISTATE_Pressed) {
		f32 scaleFactor = pikiMgr->mPikiParms->mPikiParms.mPikiDisplayScale();
		f32 scaleXZ, scaleY;
		f32 norm = pikiMgr->mPikiParms->mPikiParms._15C() - pikiMgr->mPikiParms->mPikiParms._16C();
		if (_48C > pikiMgr->mPikiParms->mPikiParms._15C() - pikiMgr->mPikiParms->mPikiParms._16C()) {
			scaleXZ = 2.0f;
			scaleY  = 0.01f;
		} else {
			scaleXZ = (_48C / norm) + 1.0f;
			scaleY  = (1.0f - (_48C / norm)) * 0.99f + 0.01f;
			if (scaleY < 0.0f) {
				ERROR("sacle minus!\n");
			}
		}
		mScale.set(scaleFactor * scaleXZ, scaleFactor * scaleY, scaleFactor * scaleXZ);
	}

	if ((mStickTarget && isStickToPlatform()) || mRope || (mStickTarget && mStickPart && mStickPart->isTubeType())) {
		mWorldMtx = mConstrainedMoveMtx;
		for (int i = 0; i < 3; i++) {
			mWorldMtx.mMtx[i][0] *= mScale.x;
			mWorldMtx.mMtx[i][1] *= mScale.y;
			mWorldMtx.mMtx[i][2] *= mScale.z;
		}

		mWorldMtx.setTranslation(mPosition.x, mPosition.y, mPosition.z);
	} else {
		mWorldMtx.makeSRT(mScale, mRotation, mPosition);
		mConstrainedMoveMtx = mWorldMtx;
	}

	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, mtx);

	if (getState() == PIKISTATE_Swallowed && mSwallowMouthPart) {
		Matrix4f mouthMtx = mSwallowMouthPart->getJointMatrix();
		f32 swallowScale  = 1.0f / ((Vector3f*)&mouthMtx)->length();
		if (swallowScale <= 0.0f) {
			PRINT("swallow scale=%f", swallowScale);
			swallowScale = 1.0f;
		}

		Matrix4f mtx2;
		mtx2.makeSRT(Vector3f(swallowScale, swallowScale, swallowScale), Vector3f(0.0f, 0.0f, HALF_PI), Vector3f(0.0f, 0.0f, 0.0f));
		mouthMtx.multiplyTo(mtx2, mtx);
		mPosition = mSwallowMouthPart->mCentre;
	}

	mPikiAnimMgr.updateContext();
	mPikiShape->mShape->updateAnim(gfx, mtx, nullptr);

	if ((AIPerf::useLOD && _528 < 1200.0f && aiCullable()) || !AIPerf::useLOD) {
		if ((mLookatTarget || mLookTimer) && getState() != PIKISTATE_Swallowed && mMode != PikiMode::ExitMode) {
			updateLook();

			Matrix4f animMtx1   = mPikiShape->mShape->getAnimMatrix(2);
			animMtx1.mMtx[3][0] = animMtx1.mMtx[3][1] = animMtx1.mMtx[3][2] = 0.0f;
			animMtx1.mMtx[3][3]                                             = 1.0f;

			Matrix4f mtx2;
			Matrix4f mtx3;
			animMtx1.inverse(&mtx2);
			Matrix4f mtx4;
			mtx4.makeIdentity();

			f32 sinV = sinf(-mVerticalRotation);
			f32 cosV = cosf(-mVerticalRotation);
			f32 sinH = sinf(mHorizontalRotation);
			f32 cosH = cosf(mHorizontalRotation);

			mtx4.mMtx[0][0] = cosV;
			mtx4.mMtx[0][1] = -sinV;
			mtx4.mMtx[0][2] = 0.0f;

			mtx4.mMtx[1][0] = cosH * sinV;
			mtx4.mMtx[1][1] = cosH * cosV;
			mtx4.mMtx[1][2] = -sinH;

			mtx4.mMtx[2][0] = sinH * sinV;
			mtx4.mMtx[2][1] = sinH * cosV;
			mtx4.mMtx[2][2] = cosH;

			animMtx1.multiplyTo(mtx4, mtx3);

			mPikiShape->mShape->getAnimMatrix(2) = mtx3;

			for (int j = 3; j <= 6; j++) {
				Matrix4f animMtx   = mPikiShape->mShape->getAnimMatrix(j);
				animMtx.mMtx[3][0] = animMtx.mMtx[3][1] = animMtx.mMtx[3][2] = 0.0f;
				animMtx.mMtx[3][3]                                           = 1.0f;

				Matrix4f tmp1;
				Matrix4f tmp2;
				mtx2.multiplyTo(animMtx, tmp1);
				mtx3.multiplyTo(tmp1, tmp2);
				mPikiShape->mShape->getAnimMatrix(j) = tmp2;
			}

			mPikiShape->mShape->calcWeightedMatrices();
		}
	}

	mCollInfo->updateInfo(gfx, false);
	demoDraw(gfx, nullptr);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void ViewPiki::refresh2d(Graphics&, int)
{
	// UNUSED FUNCTION
}
