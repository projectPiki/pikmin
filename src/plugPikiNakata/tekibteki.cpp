#include "types.h"
#include "teki.h"
#include "CreatureProp.h"
#include "Shape.h"
#include "zen/particle.h"
#include "Graphics.h"
#include "BaseInf.h"
#include "SoundMgr.h"
#include "nlib/System.h"
#include "MapMgr.h"
#include "sysNew.h"
#include "Pellet.h"
#include "RadarInfo.h"
#include "TekiStrategy.h"
#include "EffectMgr.h"

int BTeki::TEKI_OPTION_VISIBLE            = 1 << 0;
int BTeki::TEKI_OPTION_SHADOW_VISIBLE     = 1 << 1;
int BTeki::TEKI_OPTION_LIFE_GAUGE_VISIBLE = 1 << 2;
int BTeki::TEKI_OPTION_ATARI              = 1 << 3;
int BTeki::TEKI_OPTION_ALIVE              = 1 << 4;
int BTeki::TEKI_OPTION_ORGANIC            = 1 << 5;
int BTeki::TEKI_OPTION_MANUAL_ANIMATION   = 1 << 7;
int BTeki::TEKI_OPTION_GRAVITATABLE       = 1 << 8;
int BTeki::TEKI_OPTION_INVINCIBLE         = 1 << 9;
int BTeki::TEKI_OPTION_PRESSED            = 1 << 10;
int BTeki::TEKI_OPTION_DRAWED             = 1 << 13;
int BTeki::TEKI_OPTION_SHAPE_VISIBLE      = 1 << 14;
int BTeki::TEKI_OPTION_DAMAGE_COUNTABLE   = 1 << 15;

int BTeki::ANIMATION_KEY_OPTION_FINISHED  = 1 << KEY_Finished;
int BTeki::ANIMATION_KEY_OPTION_ACTION_0  = 1 << KEY_Action0;
int BTeki::ANIMATION_KEY_OPTION_ACTION_1  = 1 << KEY_Action1;
int BTeki::ANIMATION_KEY_OPTION_ACTION_2  = 1 << KEY_Action2;
int BTeki::ANIMATION_KEY_OPTION_LOOPSTART = 1 << KEY_LoopStart;
int BTeki::ANIMATION_KEY_OPTION_LOOPEND   = 1 << KEY_LoopEnd;

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
 * Address:	80143F5C
 * Size:	000064
 */
void BTeki::viewStartTrembleMotion(f32 motionSpeed)
{
	startMotion(14);
	setTekiOption(TEKIOPT_ManualAnimation);
	mMotionSpeed = motionSpeed;
}

/*
 * --INFO--
 * Address:	80143FC0
 * Size:	000008
 */
void BTeki::viewSetMotionSpeed(f32 speed)
{
	mMotionSpeed = speed;
}

/*
 * --INFO--
 * Address:	80143FC8
 * Size:	00002C
 */
void BTeki::viewDoAnimation()
{
	doAnimation();
}

/*
 * --INFO--
 * Address:	80143FF4
 * Size:	00004C
 */
void BTeki::viewFinishMotion()
{
	mTekiAnimator->finishMotion(PaniMotionInfo(-1, this));
}

/*
 * --INFO--
 * Address:	80144040
 * Size:	00001C
 */
Vector3f BTeki::viewGetScale()
{
	return mScale;
}

/*
 * --INFO--
 * Address:	8014405C
 * Size:	000018
 */
f32 BTeki::viewGetBottomRadius()
{
	return mTekiParams->getF(TPF_CorpseSize);
}

/*
 * --INFO--
 * Address:	80144074
 * Size:	000018
 */
f32 BTeki::viewGetHeight()
{
	return mTekiParams->getF(TPF_CorpseHeight);
}

/*
 * --INFO--
 * Address:	8014408C
 * Size:	0000A4
 */
void BTeki::viewDraw(Graphics& gfx, Matrix4f& mat)
{
	gfx.useMatrix(Matrix4f::ident, 0);
	mTekiAnimator->updateContext();
	mTekiShape->mShape->updateAnim(gfx, mat, nullptr);
	mTekiShape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
}

/*
 * --INFO--
 * Address:	80144130
 * Size:	000024
 */
void BTeki::viewKill()
{
	kill(false);
}

/*
 * --INFO--
 * Address:	80144154
 * Size:	00000C
 */
void BTeki::doStore(CreatureInf* info)
{
	info->mStartAnimId = mTekiType;
}

/*
 * --INFO--
 * Address:	80144160
 * Size:	00000C
 */
void BTeki::doRestore(CreatureInf* info)
{
	mTekiType = (TekiTypes)info->mStartAnimId;
}

/*
 * --INFO--
 * Address:	8014416C
 * Size:	0000B0
 */
TekiShapeObject::TekiShapeObject(Shape* shape)
{
	mShape               = shape;
	mShape->mFrameCacher = nullptr;
	mAnimMgr             = new AnimMgr(shape, nullptr, 0x8000, nullptr);
	mShape->overrideAnim(0, &mAnimContext);
}

/*
 * --INFO--
 * Address:	8014421C
 * Size:	000010
 */
bool BTeki::isPellet(int objType)
{
	return objType == OBJTYPE_Pellet;
}

/*
 * --INFO--
 * Address:	8014422C
 * Size:	000050
 */
f32 BTeki::calcCircleDistanceStatic(Vector3f& pos1, f32 rad1, Vector3f& pos2, f32 rad2)
{
	return qdist2(pos1.x, pos1.z, pos2.x, pos2.z) - rad1 - rad2;
}

/*
 * --INFO--
 * Address:	8014427C
 * Size:	000014
 */
bool BTeki::alwaysUpdatePlatform()
{
	return mTekiType == TEKI_Shell;
}

/*
 * --INFO--
 * Address:	80144290
 * Size:	0000A8
 */
f32 BTeki::calcSphereDistanceStatic(Vector3f& pos1, f32 rad1, Vector3f& pos2, f32 rad2)
{
	return pos1.distance(pos2) - rad1 - rad2; // not quite right

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  fmr       f31, f2
	  stfd      f30, 0x40(r1)
	  fmr       f30, f1
	  lfs       f0, -0x58B0(r2)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f0, 0x30(r1)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x0(r3)
	  lfs       f4, 0x8(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x8(r3)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0x4(r3)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x2C(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x2C(r1)
	  stfs      f0, 0x30(r1)
	  stfs      f1, 0x34(r1)
	  stfs      f3, 0x38(r1)
	  lfs       f1, 0x30(r1)
	  lfs       f0, 0x34(r1)
	  lfs       f2, 0x38(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1366D4
	  fsubs     f0, f1, f30
	  lwz       r0, 0x54(r1)
	  lfd       f30, 0x40(r1)
	  fsubs     f1, f0, f31
	  lfd       f31, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80144338
 * Size:	000238
 */
void BTeki::moveTowardStatic(Vector3f&, Vector3f&, f32, Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  fmr       f31, f1
	  stw       r31, 0x7C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x78(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x68
	  bl        -0x274E0
	  lfs       f0, -0x58B0(r2)
	  mr        r4, r30
	  addi      r3, r1, 0x5C
	  stfs      f0, 0x6C(r1)
	  bl        -0x274F4
	  lfs       f5, -0x58B0(r2)
	  stfs      f5, 0x60(r1)
	  lfs       f1, 0x68(r1)
	  lfs       f0, 0x5C(r1)
	  lfs       f3, 0x6C(r1)
	  lfs       f2, 0x60(r1)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x70(r1)
	  lfs       f1, 0x64(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0x0(r31)
	  fsubs     f0, f4, f1
	  stfs      f2, 0x4(r31)
	  stfs      f0, 0x8(r31)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  lfs       f2, 0x8(r31)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f4, f2, f0
	  fcmpo     cr0, f4, f5
	  ble-      .loc_0xF8
	  fsqrte    f1, f4
	  lfd       f3, -0x58A8(r2)
	  lfd       f2, -0x58A0(r2)
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
	  stfs      f0, 0x44(r1)
	  lfs       f4, 0x44(r1)

	.loc_0xF8:
	  lfs       f0, -0x58B0(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x108
	  b         .loc_0x10C

	.loc_0x108:
	  fneg      f4, f4

	.loc_0x10C:
	  lfs       f0, -0x1CB0(r13)
	  fcmpo     cr0, f4, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x170
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x136834
	  lfs       f0, -0x58B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0x170
	  lfs       f0, 0x0(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x8(r31)

	.loc_0x170:
	  lfs       f0, 0x0(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x0(r31)
	  lfs       f0, 0x4(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x4(r31)
	  lfs       f0, 0x8(r31)
	  fmuls     f0, f0, f31
	  stfs      f0, 0x8(r31)
	  lfs       f2, -0x58B0(r2)
	  stfs      f2, 0x50(r1)
	  stfs      f2, 0x4C(r1)
	  lfs       f1, 0x5C(r1)
	  lfs       f0, 0x68(r1)
	  stfs      f2, 0x48(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x34(r1)
	  lfs       f0, 0x34(r1)
	  stfs      f0, 0x48(r1)
	  lfs       f1, 0x60(r1)
	  lfs       f0, 0x6C(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4C(r1)
	  lfs       f1, 0x64(r1)
	  lfs       f0, 0x70(r1)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  lfs       f1, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  lfs       f2, 0x50(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1368F4
	  fmr       f2, f31
	  bl        .loc_0x238
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x218
	  li        r3, 0x1
	  b         .loc_0x21C

	.loc_0x218:
	  li        r3, 0

	.loc_0x21C:
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lwz       r31, 0x7C(r1)
	  lwz       r30, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr

	.loc_0x238:
	*/
}

/*
 * --INFO--
 * Address:	80144570
 * Size:	000028
 */
bool BTeki::arrivedAt(f32 p1, f32 p2)
{
	return p1 <= 2.0f * p2 * NSystem::system->getFrameTime();
}

/*
 * --INFO--
 * Address:	80144598
 * Size:	000398
 */
BTeki::BTeki()
    : Creature(nullptr)
{
	mObjType             = OBJTYPE_Teki;
	mLifeGauge._1C       = 1;
	mProps               = new CreatureProp();
	mPersonality         = new TekiPersonality();
	mTekiAnimator        = new PaniTekiAnimator();
	mVibrationController = new NVibrationFunction();
	_348                 = 20;
	_450                 = new u32[_348];
	_34C                 = 0;
	mParticleGenerators  = new zen::particleGenerator*[4];
	mCollInfo            = new CollInfo(22);
	mSeContext           = new SeContext(this, 1);
	mParticleGenPack     = new zen::PtclGenPack(3);
}

/*
 * --INFO--
 * Address:	80144930
 * Size:	000064
 */
void BTeki::init(int tekiType)
{
	mTekiType   = (TekiTypes)tekiType;
	mTekiParams = tekiMgr->getTekiParameters(mTekiType);
	mSearchBuffer.init(mTekiSearchData, 3);
	resetCreatureFlag(CF_Unk1 | CF_Unk10);
	Creature::init();
}

/*
 * --INFO--
 * Address:	80144994
 * Size:	000378
 */
void BTeki::reset()
{
	if (tekiOptUpdateMgr) {
		_174.init(tekiOptUpdateMgr);
	}

	clearTekiOptions();
	setTekiOption(TEKIOPT_Visible | TEKIOPT_ShadowVisible | TEKIOPT_LifeGaugeVisible | TEKIOPT_Atari | TEKIOPT_Alive | TEKIOPT_Organic
	              | TEKIOPT_Unk11 | TEKIOPT_ShapeVisible | TEKIOPT_DamageCountable);

	resetPosition(mPersonality->mPosition);
	mDirection        = mPersonality->mFaceDirection;
	_26C              = getSize();
	mIsDead           = 0;
	mStateID          = 0;
	mPreviousStateId  = 0;
	mActionStateId    = 0;
	mCurrentQueueId   = 0;
	mHealth           = getParameterF(TPF_Life);
	mStoredDamage     = 0.0f;
	_340              = 0.0f;
	_344              = -1;
	_3C0              = 0.0f;
	_3BC              = 0;
	mCurrentAnimEvent = -1;

	clearAnimationKeyOptions();
	_3B0            = 0;
	mMotionSpeed    = 0.0f;
	mAnimationSpeed = 0.0f;

	for (int i = 0; i < 4; i++) {
		mTargetCreatures[i].mPtr = nullptr;
	}

	_350 = 'test';
	_354 = -1;
	mTargetPosition.set(0.0f, 0.0f, 0.0f);
	mTargetAngle = 0.0f;
	_398.set(0.0f, 0.0f, 0.0f);
	_3A4 = 0.0f;

	mPellet = nullptr;

	mTekiShape = tekiMgr->getTekiShapeObject(mTekiType);

	if (!mTekiShape) {
		clearTekiOption(TEKIOPT_Visible | TEKIOPT_ShadowVisible | TEKIOPT_LifeGaugeVisible | TEKIOPT_Atari | TEKIOPT_Alive
		                | TEKIOPT_Organic);
	} else {
		mTekiShape->mShape->makeInstance(mDynamicMaterials, 0);
		mCollInfo->initInfo(mTekiShape->mShape, nullptr, nullptr);
		mTekiAnimator->init(&mTekiShape->mAnimContext, mTekiShape->mAnimMgr, tekiMgr->mMotionTable);
	}

	if (mTekiShape && mTekiShape->mShape) {
		mPlatMgr.init(this, mapMgr, mTekiShape->mShape);
	}

	for (int i = 0; i < _348; i++) {
		_450[i] = 0;
	}

	for (int i = 0; i < 4; i++) {
		mParticleGenerators[i] = 0;
	}

	_3C4 = 0.0f;
	_3C8 = 0.0f;
	_3CC = 0.0f;
	_3D0 = 0.0f;
	_3D4 = 0.0f;

	_3F0 = -1;
	_3F4 = -1;
	_3F8 = -1;
	_3FC = -1;
	_400 = -1;
	_404 = -1;
	_408 = -1;
	_40C = -1;

	if (getParameterI(TPI_CullingType) == CULLAI_CullAIOffCamera) {
		resetCreatureFlag(CF_AIAlwaysActive);
	} else {
		setCreatureFlag(CF_AIAlwaysActive);
	}

	mCollisionRadius = getParameterF(TPF_CollisionRadius);

	prepareEffects();
	resetVelocity();

	getCentreSize();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stw       r31, 0xD4(r1)
	  addi      r31, r3, 0
	  stw       r30, 0xD0(r1)
	  stw       r29, 0xCC(r1)
	  lwz       r4, 0x3050(r13)
	  cmplwi    r4, 0
	  beq-      .loc_0x30
	  addi      r3, r31, 0x174
	  bl        -0x9F51C

	.loc_0x30:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lis       r4, 0x1
	  subi      r4, r4, 0x37C1
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r4, 0x2C8(r31)
	  lwz       r12, 0x0(r31)
	  addi      r4, r4, 0x4
	  lwz       r12, 0x2C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x2C8(r31)
	  mr        r3, r31
	  lfs       f0, 0x1C(r4)
	  stfs      f0, 0xA0(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x3C(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x26C(r31)
	  li        r29, 0
	  li        r30, -0x1
	  stw       r29, 0x31C(r31)
	  mr        r3, r31
	  stw       r29, 0x324(r31)
	  stw       r29, 0x330(r31)
	  stw       r29, 0x338(r31)
	  stw       r29, 0x334(r31)
	  lwz       r4, 0x2C4(r31)
	  lwz       r4, 0x84(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f0, 0x0(r4)
	  stfs      f0, 0x58(r31)
	  lfs       f0, -0x58B0(r2)
	  stfs      f0, 0x33C(r31)
	  stfs      f0, 0x340(r31)
	  stw       r30, 0x344(r31)
	  stfs      f0, 0x3C0(r31)
	  stw       r29, 0x3BC(r31)
	  stw       r30, 0x3A8(r31)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1E8(r12)
	  mtlr      r12
	  blrl
	  stw       r29, 0x3B0(r31)
	  lis       r3, 0x7465
	  addi      r0, r3, 0x7374
	  lfs       f1, -0x58B0(r2)
	  stfs      f1, 0x3B4(r31)
	  stfs      f1, 0x3AC(r31)
	  stw       r29, 0x418(r31)
	  stw       r29, 0x41C(r31)
	  stw       r29, 0x420(r31)
	  stw       r29, 0x424(r31)
	  stw       r0, 0x350(r31)
	  stw       r30, 0x354(r31)
	  lfs       f0, -0x974(r13)
	  stfs      f0, 0x388(r31)
	  lfs       f0, -0x970(r13)
	  stfs      f0, 0x38C(r31)
	  lfs       f0, -0x96C(r13)
	  stfs      f0, 0x390(r31)
	  stfs      f1, 0x394(r31)
	  lfs       f0, -0x968(r13)
	  stfs      f0, 0x398(r31)
	  lfs       f0, -0x964(r13)
	  stfs      f0, 0x39C(r31)
	  lfs       f0, -0x960(r13)
	  stfs      f0, 0x3A0(r31)
	  stfs      f1, 0x3A4(r31)
	  stw       r29, 0x2BC(r31)
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x320(r31)
	  bl        0x6230
	  stw       r3, 0x2D0(r31)
	  lwz       r3, 0x2D0(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x1A8
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0x3F
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1EC

	.loc_0x1A8:
	  lwz       r3, 0x0(r3)
	  addi      r4, r31, 0x3E0
	  li        r5, 0
	  bl        -0x11521C
	  lwz       r4, 0x2D0(r31)
	  li        r5, 0
	  lwz       r3, 0x220(r31)
	  li        r6, 0
	  lwz       r4, 0x0(r4)
	  bl        -0xBAFFC
	  lwz       r5, 0x2D0(r31)
	  lwz       r6, 0x3160(r13)
	  lwz       r3, 0x2CC(r31)
	  addi      r4, r5, 0x4
	  lwz       r5, 0x14(r5)
	  lwz       r6, 0x40(r6)
	  bl        -0x25A58

	.loc_0x1EC:
	  lwz       r3, 0x2D0(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x214
	  lwz       r6, 0x0(r3)
	  cmplwi    r6, 0
	  beq-      .loc_0x214
	  lwz       r5, 0x2F00(r13)
	  addi      r4, r31, 0
	  addi      r3, r31, 0x2D4
	  bl        -0xB6AE4

	.loc_0x214:
	  li        r5, 0
	  addi      r4, r5, 0
	  li        r6, 0
	  b         .loc_0x234

	.loc_0x224:
	  lwz       r3, 0x450(r31)
	  addi      r6, r6, 0x1
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4

	.loc_0x234:
	  lwz       r0, 0x348(r31)
	  cmpw      r6, r0
	  blt+      .loc_0x224
	  lwz       r3, 0x3D8(r31)
	  li        r4, 0
	  li        r0, -0x1
	  stw       r4, 0x0(r3)
	  lwz       r3, 0x3D8(r31)
	  stw       r4, 0x4(r3)
	  lwz       r3, 0x3D8(r31)
	  stw       r4, 0x8(r3)
	  lwz       r3, 0x3D8(r31)
	  stw       r4, 0xC(r3)
	  lfs       f0, -0x58B0(r2)
	  stfs      f0, 0x3C4(r31)
	  stfs      f0, 0x3C8(r31)
	  stfs      f0, 0x3CC(r31)
	  stfs      f0, 0x3D0(r31)
	  stfs      f0, 0x3D4(r31)
	  stw       r0, 0x3F0(r31)
	  stw       r0, 0x3F4(r31)
	  stw       r0, 0x3F8(r31)
	  stw       r0, 0x3FC(r31)
	  stw       r0, 0x400(r31)
	  stw       r0, 0x404(r31)
	  stw       r0, 0x408(r31)
	  stw       r0, 0x40C(r31)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x2CC
	  lwz       r0, 0xC8(r31)
	  rlwinm    r0,r0,0,12,10
	  stw       r0, 0xC8(r31)
	  b         .loc_0x2D8

	.loc_0x2CC:
	  lwz       r0, 0xC8(r31)
	  oris      r0, r0, 0x10
	  stw       r0, 0xC8(r31)

	.loc_0x2D8:
	  lwz       r4, 0x2C4(r31)
	  mr        r3, r31
	  lwz       r4, 0x84(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f0, 0xB0(r4)
	  stfs      f0, 0x270(r31)
	  bl        .loc_0x378
	  addi      r3, r1, 0xA4
	  subi      r4, r13, 0x9E4
	  subi      r5, r13, 0x9E0
	  subi      r6, r13, 0x9DC
	  bl        -0x10DB80
	  addi      r3, r31, 0x70
	  addi      r4, r1, 0xA4
	  addi      r5, r1, 0xA8
	  addi      r6, r1, 0xAC
	  bl        -0xE7624
	  addi      r3, r1, 0x98
	  subi      r4, r13, 0x9F0
	  subi      r5, r13, 0x9EC
	  subi      r6, r13, 0x9E8
	  bl        -0x10DBA8
	  addi      r3, r31, 0xA4
	  addi      r4, r1, 0x98
	  addi      r5, r1, 0x9C
	  addi      r6, r1, 0xA0
	  bl        -0xE764C
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0xDC(r1)
	  lwz       r31, 0xD4(r1)
	  lwz       r30, 0xD0(r1)
	  lwz       r29, 0xCC(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr

	.loc_0x378:
	*/
}

/*
 * --INFO--
 * Address:	80144D0C
 * Size:	00011C
 */
void BTeki::prepareEffects()
{
	if (!effectMgr) {
		return;
	}

	for (int i = 0; i < 3; i++) {
		zen::particleGenerator* ptcl
		    = effectMgr->create((EffectMgr::effTypeTable)(i + EffectMgr::EFF_RippleWhite2), Vector3f(0.0f, 0.0f, 0.0f), nullptr, nullptr);
		if (!ptcl) {
			(ptcl->mScaleSize);
			break;
		}

		ptcl->mOrientedNormalVector = Vector3f(0.0f, 0.0f, 0.0f);
		f32 val                     = ptcl->mScaleSize;
		ptcl->setScaleSize(val * getParameterF(TPF_RippleScale));
		ptcl->pmSwitchOn(zen::PTCLGEN_GenStopped);
		mParticleGenPack->setPtclGenPtr(i, ptcl);
	}

	mParticleGenPack->setEmitPosPtr(&getPosition());
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stw       r31, 0x64(r1)
	  stw       r30, 0x60(r1)
	  stw       r29, 0x5C(r1)
	  stw       r28, 0x58(r1)
	  addi      r28, r3, 0
	  lwz       r0, 0x3180(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0xF8
	  li        r30, 0
	  addi      r31, r1, 0x44

	.loc_0x38:
	  lfs       f0, -0x95C(r13)
	  mr        r5, r31
	  lfs       f1, -0x958(r13)
	  addi      r4, r30, 0x34
	  stfs      f0, 0x44(r1)
	  lfs       f0, -0x954(r13)
	  li        r6, 0
	  stfs      f1, 0x48(r1)
	  li        r7, 0
	  lwz       r3, 0x3180(r13)
	  stfs      f0, 0x4C(r1)
	  bl        0x57DC8
	  mr.       r29, r3
	  bne-      .loc_0x74
	  b         .loc_0xEC

	.loc_0x74:
	  lfs       f0, -0x950(r13)
	  li        r4, 0x13
	  lfs       f1, -0x94C(r13)
	  stfs      f0, 0x38(r1)
	  lfs       f0, -0x948(r13)
	  stfs      f1, 0x3C(r1)
	  stfs      f0, 0x40(r1)
	  lwz       r3, 0x38(r1)
	  lwz       r0, 0x3C(r1)
	  stw       r3, 0x1DC(r29)
	  stw       r0, 0x1E0(r29)
	  lwz       r0, 0x40(r1)
	  stw       r0, 0x1E4(r29)
	  lwz       r3, 0x2C4(r28)
	  lfs       f31, 0xF0(r29)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x228F0
	  fmuls     f0, f31, f1
	  addi      r4, r30, 0
	  addi      r5, r29, 0
	  stfs      f0, 0xF0(r29)
	  lwz       r0, 0x80(r29)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r29)
	  lwz       r3, 0x3DC(r28)
	  bl        0x952A0
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x3
	  blt+      .loc_0x38

	.loc_0xEC:
	  addi      r4, r28, 0x94
	  lwz       r3, 0x3DC(r28)
	  bl        0x952A4

	.loc_0xF8:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  lwz       r30, 0x60(r1)
	  lwz       r29, 0x5C(r1)
	  lwz       r28, 0x58(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void BTeki::setCorpsePartJoint(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80144E28
 * Size:	000080
 */
void BTeki::startAI(int)
{
	TekiStrategy* strat = getStrategy();
	if (strat) {
		strat->start(*static_cast<Teki*>(this));
		ID32& id = mPersonality->mID;
		if (Pellet::isUfoPartsID(id.mId)) {
			radarInfo->attachParts(this);
			pelletMgr->addUseList(id.mId);
		}
	}
}

/*
 * --INFO--
 * Address:	80144EA8
 * Size:	0000A0
 */
void BTeki::update()
{
	// sigh
	u32 badCompiler[6];

	Creature::update();
	if (mIsDead == 0) {
		updateTimers();
		if (mHealth > 0.0f) {
			f32 max = getParameterF(TPF_Life);
			f32 inc = getParameterF(TPF_LifeRecoverRate);
			mHealth += NSystem::system->getFrameTime() * (max * inc);

			if (mHealth >= max) {
				mHealth = max;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80144F48
 * Size:	0000C8
 */
void BTeki::doAnimation()
{
	if (!mTekiShape) {
		return;
	}
	if (isTekiOption(TEKIOPT_ManualAnimation)) {
		mAnimationSpeed = mMotionSpeed;
	} else if (!(mTekiAnimator->mAnimInfo->mParams.mFlags() & AnimInfo::FLAG_Unk2)) {
		mAnimationSpeed = mTekiAnimator->mAnimInfo->mParams.mSpeed();
	} else if (isTekiOption(TEKIOPT_StoppingMove)) {
		mAnimationSpeed = mPreStopAnimationSpeed;
	} else {
		mAnimationSpeed = doGetVelocityAnimSpeed();
	}

	mTekiAnimator->animate(mAnimationSpeed);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r0, 0x2D0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xB4
	  lwz       r5, 0x410(r31)
	  rlwinm.   r0,r5,0,24,24
	  beq-      .loc_0x38
	  lfs       f0, 0x3B4(r31)
	  stfs      f0, 0x3AC(r31)
	  b         .loc_0x9C

	.loc_0x38:
	  lwz       r3, 0x2CC(r31)
	  lwz       r4, 0x28(r3)
	  lwz       r0, 0x24(r4)
	  rlwinm.   r0,r0,0,30,30
	  bne-      .loc_0x58
	  lfs       f0, 0x34(r4)
	  stfs      f0, 0x3AC(r31)
	  b         .loc_0x9C

	.loc_0x58:
	  rlwinm.   r0,r5,0,19,19
	  beq-      .loc_0x6C
	  lfs       f0, 0x3B8(r31)
	  stfs      f0, 0x3AC(r31)
	  b         .loc_0x9C

	.loc_0x6C:
	  lfs       f1, 0xA4(r31)
	  lfs       f0, 0xA8(r31)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xAC(r31)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x137394
	  mr        r3, r31
	  bl        0x160
	  stfs      f1, 0x3AC(r31)

	.loc_0x9C:
	  lwz       r3, 0x2CC(r31)
	  lfs       f1, 0x3AC(r31)
	  lwz       r12, 0x30(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl

	.loc_0xB4:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145010
 * Size:	000064
 */
void BTeki::startMotion(int motionID)
{
	mTekiAnimator->startMotion(PaniMotionInfo(motionID, this));
	mCurrentAnimEvent = -1;
	clearAnimationKeyOptions();
}

/*
 * --INFO--
 * Address:	80145074
 * Size:	000098
 */
void BTeki::startStoppingMove()
{
	resetVelocity();
	setTekiOption(TEKIOPT_StoppingMove);
	mPreStopAnimationSpeed = mAnimationSpeed;
}

/*
 * --INFO--
 * Address:	8014510C
 * Size:	000030
 */
void BTeki::finishStoppingMove()
{
	clearTekiOption(TEKIOPT_StoppingMove);
}

/*
 * --INFO--
 * Address:	8014513C
 * Size:	0000A4
 */
f32 BTeki::getVelocityAnimationSpeed(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stfd      f29, 0x60(r1)
	  fmr       f29, f1
	  stw       r31, 0x5C(r1)
	  mr        r31, r3
	  lwz       r5, 0x2CC(r3)
	  lwz       r3, 0x2C8(r3)
	  lwz       r5, 0x28(r5)
	  lwz       r3, 0x34(r3)
	  lfs       f0, -0x58AC(r2)
	  lfs       f1, 0x34(r5)
	  lwz       r3, 0x4(r3)
	  fdivs     f30, f1, f0
	  bl        -0x22CB0
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x22CC8
	  fmuls     f2, f29, f30
	  lfs       f0, -0x5884(r2)
	  fmuls     f1, f1, f31
	  fmuls     f0, f0, f30
	  fdivs     f1, f2, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x84
	  fmr       f1, f0

	.loc_0x84:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lfd       f29, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801451E0
 * Size:	000080
 */
void BTeki::animationKeyUpdated(PaniAnimKeyEvent& event)
{
	if (event.mEventType == KEY_PlaySound) {
		playTableSound(event.mValue);
		return;
	}

	if (event.mEventType == KEY_PlayEffect) {
		createTekiEffect(event.mValue);
		return;
	}

	mCurrentAnimEvent = event.mEventType;
	setAnimationKeyOption(1 << event.mEventType);
}

/*
 * --INFO--
 * Address:	80145260
 * Size:	0001E0
 */
void BTeki::doAI()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  stw       r30, 0x38(r1)
	  lwz       r0, 0x31C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x1C0
	  lwz       r0, -0x5F04(r13)
	  cmpwi     r0, 0x3
	  blt-      .loc_0x48
	  addi      r3, r31, 0x174
	  bl        -0x9FE44
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1C0

	.loc_0x48:
	  mr        r3, r31
	  bl        0x3688
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  li        r0, -0x1
	  stw       r0, 0x3A8(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1E8(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x28C(r31)
	  cmplwi    r3, 0
	  bne-      .loc_0x98
	  lwz       r3, 0x3DC(r31)
	  bl        0x94E24
	  b         .loc_0xDC

	.loc_0x98:
	  bl        -0x2F278
	  mr        r30, r3
	  lwz       r3, 0x3DC(r31)
	  bl        0x94F08
	  rlwinm    r0,r3,0,24,31
	  cntlzw    r0, r0
	  rlwinm.   r0,r0,27,24,31
	  beq-      .loc_0xCC
	  cmpwi     r30, 0x5
	  beq-      .loc_0xDC
	  lwz       r3, 0x3DC(r31)
	  bl        0x94DF0
	  b         .loc_0xDC

	.loc_0xCC:
	  cmpwi     r30, 0x5
	  bne-      .loc_0xDC
	  lwz       r3, 0x3DC(r31)
	  bl        0x94DA0

	.loc_0xDC:
	  lwz       r0, 0x410(r31)
	  rlwinm.   r0,r0,0,23,23
	  beq-      .loc_0x104
	  mr        r3, r31
	  bl        0x35DC
	  lwz       r12, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x180(r12)
	  mtlr      r12
	  blrl

	.loc_0x104:
	  lfs       f1, 0x3D0(r31)
	  lfs       f0, -0x58B0(r2)
	  lfs       f30, -0x5880(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x134
	  lwz       r3, 0x428(r31)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  fadds     f30, f30, f1

	.loc_0x134:
	  lwz       r0, 0x410(r31)
	  rlwinm.   r0,r0,0,21,21
	  beq-      .loc_0x15C
	  lfs       f0, -0x944(r13)
	  stfs      f0, 0x7C(r31)
	  lfs       f0, -0x940(r13)
	  stfs      f0, 0x80(r31)
	  lfs       f0, -0x93C(r13)
	  stfs      f0, 0x84(r31)
	  b         .loc_0x198

	.loc_0x15C:
	  lwz       r3, 0x2C8(r31)
	  li        r4, 0
	  lwz       r3, 0x34(r3)
	  bl        -0x221B8
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x221CC
	  fmuls     f1, f1, f31
	  fdivs     f0, f1, f30
	  fmuls     f1, f1, f30
	  stfs      f1, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f1, 0x84(r31)

	.loc_0x198:
	  mr        r3, r31
	  bl        0x37AC
	  lwz       r0, 0x31C(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1C0
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1EC(r12)
	  mtlr      r12
	  blrl

	.loc_0x1C0:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145440
 * Size:	00000C
 */
void BTeki::die()
{
	mIsDead = 1;
}

/*
 * --INFO--
 * Address:	8014544C
 * Size:	000258
 */
void BTeki::dieSoon()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1B
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stmw      r27, 0xC4(r1)
	  mr        r31, r3
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x0(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1A8
	  mr        r3, r31
	  bl        0x918
	  lwz       r4, 0x320(r31)
	  lis       r3, 0x802D
	  subi      r0, r3, 0x252C
	  rlwinm    r3,r4,2,0,29
	  add       r3, r0, r3
	  lwz       r27, 0x0(r3)
	  addi      r3, r1, 0xB0
	  addi      r4, r27, 0
	  bl        -0x10162C
	  addi      r3, r1, 0xA4
	  bl        -0x28674
	  lis       r4, 0x6361
	  lwz       r3, 0x220(r31)
	  addi      r4, r4, 0x7263
	  bl        -0xBBDC8
	  cmplwi    r3, 0
	  bne-      .loc_0xCC
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x8C
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x8C(r1)
	  lfs       f1, 0x90(r1)
	  stfs      f0, 0xA4(r1)
	  lfs       f0, 0x94(r1)
	  stfs      f1, 0xA8(r1)
	  stfs      f0, 0xAC(r1)
	  b         .loc_0xE4

	.loc_0xCC:
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0xA4(r1)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0xA8(r1)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0xAC(r1)

	.loc_0xE4:
	  lfs       f1, 0xA0(r31)
	  addi      r4, r27, 0
	  addi      r3, r31, 0x2B8
	  addi      r5, r1, 0xA4
	  bl        -0xB05CC
	  lwz       r0, 0x2BC(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x23C
	  addi      r3, r1, 0x98
	  bl        -0x28700
	  lfs       f30, 0xA0(r31)
	  fmr       f1, f30
	  bl        0xD65F4
	  fmr       f31, f1
	  fmr       f1, f30
	  bl        0xD677C
	  stfs      f1, 0x98(r1)
	  li        r4, 0x29
	  lfs       f0, -0x9D8(r13)
	  stfs      f0, 0x9C(r1)
	  stfs      f31, 0xA0(r1)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x230BC
	  lfs       f0, 0x98(r1)
	  li        r0, 0x2
	  fmuls     f0, f0, f1
	  stfs      f0, 0x98(r1)
	  lfs       f0, 0x9C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x9C(r1)
	  lfs       f0, 0xA0(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xA0(r1)
	  lwz       r3, 0x2C4(r31)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0xA8(r3)
	  stfs      f0, 0x9C(r1)
	  lwz       r3, 0x2BC(r31)
	  lfs       f0, 0x98(r1)
	  stfsu     f0, 0x70(r3)
	  lfs       f0, 0x9C(r1)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0xA0(r1)
	  stfs      f0, 0x8(r3)
	  stw       r0, 0x31C(r31)

	.loc_0x1A8:
	  mr        r3, r31
	  bl        -0xBA95C
	  mr        r3, r31
	  bl        0xE98
	  lwz       r3, 0x2C(r31)
	  bl        -0xA1688
	  lwz       r3, 0x30F8(r13)
	  li        r29, 0
	  addi      r27, r31, 0
	  addi      r0, r3, 0x1
	  stw       r0, 0x30F8(r13)
	  mr        r30, r29

	.loc_0x1D8:
	  lwz       r0, 0x418(r27)
	  addi      r28, r27, 0x418
	  cmplwi    r0, 0
	  beq-      .loc_0x1F4
	  lwz       r3, 0x0(r28)
	  bl        -0x612CC
	  stw       r30, 0x0(r28)

	.loc_0x1F4:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x4
	  addi      r27, r27, 0x4
	  blt+      .loc_0x1D8
	  addi      r3, r31, 0x2D4
	  bl        -0xB74F4
	  lwz       r0, 0x31C(r31)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x230
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x1F0(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x23C

	.loc_0x230:
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0xBA9A4

	.loc_0x23C:
	  lmw       r27, 0xC4(r1)
	  lwz       r0, 0xEC(r1)
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  addi      r1, r1, 0xE8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801456A4
 * Size:	000094
 */
void BTeki::becomeCorpse()
{
	for (int i = 0; i < 4; i++) {
		if (mParticleGenerators[i]) {
			mParticleGenerators[i]->finish();
		}
	}

	mParticleGenPack->finish();
}

/*
 * --INFO--
 * Address:	80145738
 * Size:	000150
 */
void BTeki::doKill()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  addi      r27, r3, 0
	  lwz       r0, 0x3050(r13)
	  cmplwi    r0, 0
	  beq-      .loc_0x28
	  addi      r3, r27, 0x174
	  bl        -0xA0288

	.loc_0x28:
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  li        r4, 0x10
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C(r27)
	  bl        -0xA17FC
	  li        r30, 0
	  addi      r28, r27, 0
	  addi      r31, r30, 0

	.loc_0x54:
	  lwz       r0, 0x418(r28)
	  addi      r29, r28, 0x418
	  cmplwi    r0, 0
	  beq-      .loc_0x70
	  lwz       r3, 0x0(r29)
	  bl        -0x61434
	  stw       r31, 0x0(r29)

	.loc_0x70:
	  addi      r30, r30, 0x1
	  cmpwi     r30, 0x4
	  addi      r28, r28, 0x4
	  blt+      .loc_0x54
	  addi      r3, r27, 0x2D4
	  bl        -0xB765C
	  lwz       r3, 0x3D8(r27)
	  li        r0, 0
	  lwz       r4, 0x0(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0xB0
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  lwz       r3, 0x3D8(r27)
	  stw       r0, 0x0(r3)

	.loc_0xB0:
	  lwz       r3, 0x3D8(r27)
	  lwz       r4, 0x4(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0xD4
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  lwz       r3, 0x3D8(r27)
	  stw       r0, 0x4(r3)

	.loc_0xD4:
	  lwz       r3, 0x3D8(r27)
	  lwz       r4, 0x8(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0xF8
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  lwz       r3, 0x3D8(r27)
	  stw       r0, 0x8(r3)

	.loc_0xF8:
	  lwz       r3, 0x3D8(r27)
	  lwz       r4, 0xC(r3)
	  cmplwi    r4, 0
	  beq-      .loc_0x11C
	  lwz       r3, 0x80(r4)
	  ori       r3, r3, 0x2
	  stw       r3, 0x80(r4)
	  lwz       r3, 0x3D8(r27)
	  stw       r0, 0xC(r3)

	.loc_0x11C:
	  lwz       r3, 0x3DC(r27)
	  bl        0x948F8
	  lwz       r3, 0x3160(r13)
	  mr        r4, r27
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x7C(r12)
	  mtlr      r12
	  blrl
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145888
 * Size:	000080
 */
void BTeki::exitCourse()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  li        r30, 0
	  addi      r31, r30, 0
	  stw       r29, 0x14(r1)
	  li        r29, 0
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0

	.loc_0x2C:
	  lwz       r3, 0x3D8(r28)
	  lwzx      r3, r3, r30
	  cmplwi    r3, 0
	  beq-      .loc_0x48
	  bl        0x5B338
	  lwz       r3, 0x3D8(r28)
	  stwx      r31, r3, r30

	.loc_0x48:
	  addi      r29, r29, 0x1
	  cmpwi     r29, 0x4
	  addi      r30, r30, 0x4
	  blt+      .loc_0x2C
	  lwz       r3, 0x3DC(r28)
	  bl        0x948B0
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145908
 * Size:	0000AC
 */
void BTeki::gravitate(f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stw       r31, 0x3C(r1)
	  mr        r31, r3
	  lwz       r4, 0x3150(r13)
	  lfs       f2, 0x39C(r3)
	  lfs       f3, 0x28C(r4)
	  fmuls     f0, f1, f3
	  fsubs     f0, f2, f0
	  stfs      f0, 0x39C(r31)
	  lfs       f1, 0x398(r31)
	  lfs       f2, 0x39C(r31)
	  fmuls     f1, f1, f3
	  lfs       f0, 0x94(r31)
	  lfs       f4, 0x3A0(r31)
	  fmuls     f2, f2, f3
	  fadds     f0, f0, f1
	  fmuls     f4, f4, f3
	  stfs      f0, 0x94(r31)
	  lfs       f0, 0x98(r31)
	  fadds     f0, f0, f2
	  stfs      f0, 0x98(r31)
	  lfs       f0, 0x9C(r31)
	  fadds     f0, f0, f4
	  stfs      f0, 0x9C(r31)
	  bl        0x2FF0
	  addi      r3, r31, 0x98
	  lfs       f0, 0x98(r31)
	  fcmpo     cr0, f0, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x98
	  stfs      f1, 0x0(r3)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xAC(r12)
	  mtlr      r12
	  blrl

	.loc_0x98:
	  lwz       r0, 0x44(r1)
	  lwz       r31, 0x3C(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801459B4
 * Size:	0000D4
 */
void BTeki::updateTimers()
{
	/*
	.loc_0x0:
	  lfs       f1, -0x58B0(r2)
	  lfs       f0, 0x3C4(r3)
	  lwz       r4, 0x3150(r13)
	  fcmpo     cr0, f0, f1
	  lfs       f2, 0x28C(r4)
	  ble-      .loc_0x30
	  fsubs     f0, f0, f2
	  stfs      f0, 0x3C4(r3)
	  lfs       f0, 0x3C4(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x30
	  stfs      f1, 0x3C4(r3)

	.loc_0x30:
	  addi      r3, r3, 0x4
	  lfs       f0, 0x3C4(r3)
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x58
	  fsubs     f0, f0, f2
	  stfs      f0, 0x3C4(r3)
	  lfs       f0, 0x3C4(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x58
	  stfs      f1, 0x3C4(r3)

	.loc_0x58:
	  lfs       f0, 0x3C8(r3)
	  addi      r3, r3, 0x4
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0x80
	  fsubs     f0, f0, f2
	  stfs      f0, 0x3C4(r3)
	  lfs       f0, 0x3C4(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0x80
	  stfs      f1, 0x3C4(r3)

	.loc_0x80:
	  lfs       f0, 0x3C8(r3)
	  addi      r3, r3, 0x4
	  fcmpo     cr0, f0, f1
	  ble-      .loc_0xA8
	  fsubs     f0, f0, f2
	  stfs      f0, 0x3C4(r3)
	  lfs       f0, 0x3C4(r3)
	  fcmpo     cr0, f0, f1
	  bge-      .loc_0xA8
	  stfs      f1, 0x3C4(r3)

	.loc_0xA8:
	  lfs       f0, 0x3C8(r3)
	  addi      r3, r3, 0x4
	  fcmpo     cr0, f0, f1
	  blelr-
	  fsubs     f0, f0, f2
	  stfs      f0, 0x3C4(r3)
	  lfs       f0, 0x3C4(r3)
	  fcmpo     cr0, f0, f1
	  bgelr-
	  stfs      f1, 0x3C4(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145A88
 * Size:	000074
 */
bool BTeki::stimulate(Interaction&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x58
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x5C

	.loc_0x58:
	  li        r3, 0

	.loc_0x5C:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145AFC
 * Size:	00009C
 */
f32 BTeki::getiMass()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stw       r31, 0x64(r1)
	  mr        r31, r3
	  lwz       r3, 0x2C4(r3)
	  lfs       f1, -0x58B0(r2)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f30, 0x8(r3)
	  fcmpo     cr0, f30, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x44
	  b         .loc_0x80

	.loc_0x44:
	  lwz       r3, 0x2C8(r31)
	  li        r4, 0
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x2367C
	  lwz       r3, 0x2C4(r31)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x23694
	  fmuls     f0, f1, f31
	  lfs       f1, -0x5880(r2)
	  fmuls     f0, f30, f0
	  fdivs     f1, f1, f0

	.loc_0x80:
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lwz       r31, 0x64(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145B98
 * Size:	00002C
 */
void BTeki::getTekiCollisionSize()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
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
 * Address:	80145BC4
 * Size:	000030
 */
void BTeki::makeDamaged()
{
	mHealth -= mStoredDamage;
	if (mHealth < 0.0f) {
		mHealth = 0.0f;
	}

	mStoredDamage = 0.0f;
}

/*
 * --INFO--
 * Address:	80145BF4
 * Size:	00004C
 */
void BTeki::startDamageMotion(f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  fmr       f5, f1
	  stw       r0, 0x4(r1)
	  fmr       f3, f2
	  stwu      r1, -0x8(r1)
	  lfs       f0, -0x58B0(r2)
	  lfs       f4, 0x3D0(r3)
	  fcmpo     cr0, f4, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3C
	  stfs      f5, 0x3D0(r3)
	  fmr       f1, f0
	  fmr       f2, f5
	  lwz       r3, 0x428(r3)
	  bl        -0x2A0B8

	.loc_0x3C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145C40
 * Size:	000024
 */
void BTeki::releasePlatCollisions()
{
	mPlatMgr.release();
}

/*
 * --INFO--
 * Address:	80145C64
 * Size:	000150
 */
void BTeki::createDeadEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x30
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C4(r31)
	  addi      r31, r1, 0x30
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x18(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x98
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3D
	  li        r6, 0
	  li        r7, 0
	  bl        0x56E74
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3E
	  li        r6, 0
	  li        r7, 0
	  bl        0x56E5C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3F
	  li        r6, 0
	  li        r7, 0
	  bl        0x56E44
	  b         .loc_0x13C

	.loc_0x98:
	  cmpwi     r0, 0x1
	  bne-      .loc_0xEC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3A
	  li        r6, 0
	  li        r7, 0
	  bl        0x56E20
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3B
	  li        r6, 0
	  li        r7, 0
	  bl        0x56E08
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x3C
	  li        r6, 0
	  li        r7, 0
	  bl        0x56DF0
	  b         .loc_0x13C

	.loc_0xEC:
	  cmpwi     r0, 0
	  bne-      .loc_0x13C
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x37
	  li        r6, 0
	  li        r7, 0
	  bl        0x56DCC
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x38
	  li        r6, 0
	  li        r7, 0
	  bl        0x56DB4
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0
	  li        r4, 0x39
	  li        r6, 0
	  li        r7, 0
	  bl        0x56D9C

	.loc_0x13C:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145DB4
 * Size:	0000B4
 */
void BTeki::createSoulEffect()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stw       r31, 0x44(r1)
	  addi      r31, r3, 0
	  addi      r4, r31, 0
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x30
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2C4(r31)
	  addi      r5, r1, 0x30
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x18(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x64
	  lwz       r3, 0x3180(r13)
	  li        r4, 0x42
	  li        r6, 0
	  li        r7, 0
	  bl        0x56D28
	  b         .loc_0xA0

	.loc_0x64:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x84
	  lwz       r3, 0x3180(r13)
	  li        r4, 0x41
	  li        r6, 0
	  li        r7, 0
	  bl        0x56D08
	  b         .loc_0xA0

	.loc_0x84:
	  cmpwi     r0, 0
	  bne-      .loc_0xA0
	  lwz       r3, 0x3180(r13)
	  li        r4, 0x40
	  li        r6, 0
	  li        r7, 0
	  bl        0x56CE8

	.loc_0xA0:
	  lwz       r0, 0x4C(r1)
	  lwz       r31, 0x44(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80145E68
 * Size:	00019C
 */
void BTeki::spawnItems()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x138(r1)
	  stfd      f31, 0x130(r1)
	  stw       r31, 0x12C(r1)
	  mr        r31, r3
	  stw       r30, 0x128(r1)
	  stw       r29, 0x124(r1)
	  stw       r28, 0x120(r1)
	  lwz       r5, 0x2C8(r3)
	  lis       r3, 0x6E6F
	  addi      r4, r3, 0x6E65
	  addi      r30, r5, 0x28
	  addi      r3, r30, 0
	  li        r5, 0x2A
	  bl        -0x101FBC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x70
	  lwz       r4, 0x0(r30)
	  addi      r3, r31, 0
	  li        r5, -0x2
	  li        r6, 0x1
	  bl        .loc_0x19C
	  lwz       r3, 0x2F28(r13)
	  mr        r4, r31
	  bl        -0xCA7B8
	  mr        r3, r31
	  bl        -0xBB238

	.loc_0x70:
	  lwz       r3, 0x2C8(r31)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f31, 0xC(r3)
	  bl        0xD2184
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x5878(r2)
	  stw       r0, 0x11C(r1)
	  lis       r0, 0x4330
	  lfs       f1, -0x587C(r2)
	  stw       r0, 0x118(r1)
	  lfs       f0, -0x5880(r2)
	  lfd       f2, 0x118(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0xFC
	  lwz       r4, 0x2C8(r31)
	  lwz       r3, 0x34(r4)
	  lwz       r29, 0x20(r4)
	  lwz       r3, 0x0(r3)
	  lwz       r28, 0x24(r4)
	  lwz       r3, 0x0(r3)
	  lwz       r30, 0x0(r3)
	  lwz       r0, 0x4(r3)
	  sub       r3, r0, r30
	  bl        -0x276A4
	  add       r0, r30, r3
	  mr        r6, r0
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  addi      r5, r28, 0
	  bl        .loc_0x19C

	.loc_0xFC:
	  lwz       r3, 0x2C8(r31)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f31, 0x10(r3)
	  bl        0xD20F8
	  xoris     r0, r3, 0x8000
	  lfd       f3, -0x5878(r2)
	  stw       r0, 0x11C(r1)
	  lis       r0, 0x4330
	  lfs       f1, -0x587C(r2)
	  stw       r0, 0x118(r1)
	  lfs       f0, -0x5880(r2)
	  lfd       f2, 0x118(r1)
	  fsubs     f2, f2, f3
	  fdivs     f1, f2, f1
	  fmuls     f0, f0, f1
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x178
	  lwz       r3, 0x2C8(r31)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r30, 0x8(r3)
	  lwz       r0, 0xC(r3)
	  sub       r3, r0, r30
	  bl        -0x27728
	  add       r0, r30, r3
	  mr        r4, r0
	  addi      r3, r31, 0
	  bl        0x2D0

	.loc_0x178:
	  lwz       r0, 0x13C(r1)
	  lfd       f31, 0x130(r1)
	  lwz       r31, 0x12C(r1)
	  lwz       r30, 0x128(r1)
	  lwz       r29, 0x124(r1)
	  lwz       r28, 0x120(r1)
	  addi      r1, r1, 0x138
	  mtlr      r0
	  blr

	.loc_0x19C:
	*/
}

/*
 * --INFO--
 * Address:	80146004
 * Size:	0002A8
 */
void BTeki::spawnPellets(int, int, int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x148(r1)
	  stfd      f31, 0x140(r1)
	  stfd      f30, 0x138(r1)
	  stfd      f29, 0x130(r1)
	  stfd      f28, 0x128(r1)
	  stfd      f27, 0x120(r1)
	  stfd      f26, 0x118(r1)
	  stfd      f25, 0x110(r1)
	  stmw      r23, 0xEC(r1)
	  addi      r24, r3, 0
	  addi      r25, r4, 0
	  addi      r4, r24, 0
	  addi      r26, r5, 0
	  addi      r27, r6, 0
	  addi      r3, r1, 0xB4
	  lwz       r12, 0x0(r24)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0xB4(r1)
	  lfs       f1, 0xB8(r1)
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xBC(r1)
	  stfs      f1, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  lwz       r3, 0x2C4(r24)
	  lwz       r4, 0x84(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x48(r3)
	  lfs       f29, 0xA0(r4)
	  cmpwi     r0, 0x1
	  lfs       f28, 0x9C(r4)
	  bne-      .loc_0xA0
	  lfs       f27, 0xA0(r24)
	  b         .loc_0xE0

	.loc_0xA0:
	  bl        0xD1FCC
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5878(r2)
	  stw       r0, 0xE4(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x587C(r2)
	  stw       r0, 0xE0(r1)
	  lfs       f2, -0x5880(r2)
	  lfd       f0, 0xE0(r1)
	  lfs       f1, -0x5898(r2)
	  fsubs     f4, f0, f4
	  lfs       f0, -0x1CA4(r13)
	  fmuls     f0, f1, f0
	  fdivs     f1, f4, f3
	  fmuls     f1, f2, f1
	  fmuls     f27, f0, f1

	.loc_0xE0:
	  lfs       f30, -0x5898(r2)
	  xoris     r31, r27, 0x8000
	  lfd       f31, -0x5878(r2)
	  addi      r29, r1, 0xA0
	  li        r28, 0
	  lis       r30, 0x4330
	  b         .loc_0x270

	.loc_0xFC:
	  cmpwi     r26, -0x2
	  bne-      .loc_0x134
	  lwz       r3, 0x301C(r13)
	  addi      r4, r25, 0
	  li        r5, 0
	  bl        -0xADB64
	  addi      r23, r3, 0
	  addi      r3, r25, 0
	  bl        -0xB0D74
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x160
	  li        r3, 0x122
	  bl        -0xA0DBC
	  b         .loc_0x160

	.loc_0x134:
	  cmpwi     r26, 0
	  blt-      .loc_0x144
	  mr        r4, r26
	  b         .loc_0x150

	.loc_0x144:
	  li        r3, 0x2
	  bl        -0x278A8
	  mr        r4, r3

	.loc_0x150:
	  lwz       r3, 0x301C(r13)
	  mr        r5, r25
	  bl        -0xADC24
	  mr        r23, r3

	.loc_0x160:
	  cmplwi    r23, 0
	  beq-      .loc_0x278
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  addi      r4, r1, 0xC8
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  xoris     r0, r28, 0x8000
	  stw       r31, 0xDC(r1)
	  lfs       f2, -0x1CA4(r13)
	  stw       r0, 0xE4(r1)
	  stw       r30, 0xE0(r1)
	  stw       r30, 0xD8(r1)
	  lfd       f1, 0xE0(r1)
	  lfd       f0, 0xD8(r1)
	  fsubs     f1, f1, f31
	  fsubs     f0, f0, f31
	  fdivs     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f0, f30, f0
	  fadds     f25, f27, f0
	  fmr       f1, f25
	  bl        0xD5994
	  fmr       f26, f1
	  fmr       f1, f25
	  bl        0xD5B1C
	  fmuls     f1, f28, f1
	  mr        r4, r29
	  fmuls     f0, f28, f26
	  addi      r3, r23, 0xE0
	  stfs      f1, 0x70(r23)
	  stfs      f29, 0x74(r23)
	  stfs      f0, 0x78(r23)
	  lfs       f0, 0xA0(r24)
	  stfs      f0, 0xA0(r23)
	  lfs       f1, -0x938(r13)
	  lfs       f0, -0x934(r13)
	  stfs      f1, 0xA0(r1)
	  lfs       f1, 0xA0(r23)
	  stfs      f1, 0xA4(r1)
	  stfs      f0, 0xA8(r1)
	  bl        -0x10DF24
	  lwz       r3, 0x2C4(r24)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x44(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x244
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  li        r4, 0x1
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x25C

	.loc_0x244:
	  mr        r3, r23
	  lwz       r12, 0x0(r23)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl

	.loc_0x25C:
	  addi      r3, r23, 0
	  addi      r4, r23, 0
	  li        r5, 0xBB
	  bl        -0xBBCB8
	  addi      r28, r28, 0x1

	.loc_0x270:
	  cmpw      r28, r27
	  blt+      .loc_0xFC

	.loc_0x278:
	  lmw       r23, 0xEC(r1)
	  lwz       r0, 0x14C(r1)
	  lfd       f31, 0x140(r1)
	  lfd       f30, 0x138(r1)
	  lfd       f29, 0x130(r1)
	  lfd       f28, 0x128(r1)
	  lfd       f27, 0x120(r1)
	  lfd       f26, 0x118(r1)
	  lfd       f25, 0x110(r1)
	  addi      r1, r1, 0x148
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801462AC
 * Size:	0001EC
 */
void BTeki::spawnWaters(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x110(r1)
	  stfd      f31, 0x108(r1)
	  stfd      f30, 0x100(r1)
	  stfd      f29, 0xF8(r1)
	  stfd      f28, 0xF0(r1)
	  stfd      f27, 0xE8(r1)
	  stfd      f26, 0xE0(r1)
	  stfd      f25, 0xD8(r1)
	  stmw      r27, 0xC4(r1)
	  addi      r28, r3, 0
	  addi      r27, r4, 0
	  addi      r4, r28, 0
	  addi      r3, r1, 0x90
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x90(r1)
	  lfs       f1, 0x94(r1)
	  stfs      f0, 0xA4(r1)
	  lfs       f0, 0x98(r1)
	  stfs      f1, 0xA8(r1)
	  stfs      f0, 0xAC(r1)
	  lwz       r3, 0x2C4(r28)
	  lwz       r4, 0x84(r3)
	  lwz       r3, 0x0(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r3, 0x0(r3)
	  lwz       r4, 0x0(r4)
	  lwz       r0, 0x48(r3)
	  lfs       f31, 0xA0(r4)
	  cmpwi     r0, 0x1
	  lfs       f30, 0x9C(r4)
	  bne-      .loc_0x98
	  lfs       f26, 0xA0(r28)
	  b         .loc_0xD8

	.loc_0x98:
	  bl        0xD1D2C
	  xoris     r0, r3, 0x8000
	  lfd       f4, -0x5878(r2)
	  stw       r0, 0xBC(r1)
	  lis       r0, 0x4330
	  lfs       f3, -0x587C(r2)
	  stw       r0, 0xB8(r1)
	  lfs       f2, -0x5880(r2)
	  lfd       f0, 0xB8(r1)
	  lfs       f1, -0x5898(r2)
	  fsubs     f4, f0, f4
	  lfs       f0, -0x1CA4(r13)
	  fmuls     f0, f1, f0
	  fdivs     f1, f4, f3
	  fmuls     f1, f2, f1
	  fmuls     f26, f0, f1

	.loc_0xD8:
	  lfs       f27, -0x5898(r2)
	  xoris     r31, r27, 0x8000
	  lfd       f28, -0x5878(r2)
	  li        r29, 0
	  lis       r30, 0x4330
	  b         .loc_0x1B4

	.loc_0xF0:
	  lwz       r3, 0x30AC(r13)
	  li        r4, 0x6
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  mr.       r28, r3
	  beq-      .loc_0x1BC
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  addi      r4, r1, 0xA4
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  xoris     r0, r29, 0x8000
	  stw       r31, 0xB4(r1)
	  lfs       f2, -0x1CA4(r13)
	  stw       r0, 0xBC(r1)
	  stw       r30, 0xB8(r1)
	  stw       r30, 0xB0(r1)
	  lfd       f1, 0xB8(r1)
	  lfd       f0, 0xB0(r1)
	  fsubs     f1, f1, f28
	  fsubs     f0, f0, f28
	  fdivs     f0, f1, f0
	  fmuls     f0, f2, f0
	  fmuls     f0, f27, f0
	  fadds     f25, f26, f0
	  fmr       f1, f25
	  bl        0xD5744
	  fmr       f29, f1
	  fmr       f1, f25
	  bl        0xD58CC
	  fmuls     f1, f30, f1
	  mr        r3, r28
	  fmuls     f0, f30, f29
	  li        r4, 0
	  stfs      f1, 0x70(r28)
	  stfs      f31, 0x74(r28)
	  stfs      f0, 0x78(r28)
	  lwz       r12, 0x0(r28)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r28, 0
	  addi      r4, r28, 0
	  li        r5, 0xBB
	  bl        -0xBBEA4
	  addi      r29, r29, 0x1

	.loc_0x1B4:
	  cmpw      r29, r27
	  blt+      .loc_0xF0

	.loc_0x1BC:
	  lmw       r27, 0xC4(r1)
	  lwz       r0, 0x114(r1)
	  lfd       f31, 0x108(r1)
	  lfd       f30, 0x100(r1)
	  lfd       f29, 0xF8(r1)
	  lfd       f28, 0xF0(r1)
	  lfd       f27, 0xE8(r1)
	  lfd       f26, 0xE0(r1)
	  lfd       f25, 0xD8(r1)
	  addi      r1, r1, 0x110
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146498
 * Size:	000040
 */
void BTeki::spawnCorpseParts()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        0x2488
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x24(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801464D8
 * Size:	0000D8
 */
void BTeki::generateTeki(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  mr        r30, r3
	  lwz       r3, 0x3160(r13)
	  bl        0x4658
	  mr.       r31, r3
	  bne-      .loc_0x30
	  li        r3, 0
	  b         .loc_0xC0

	.loc_0x30:
	  lwz       r3, 0x2C8(r31)
	  bl        0x674C
	  lwz       r3, 0x2C8(r31)
	  li        r4, 0x2
	  lfs       f0, 0x94(r30)
	  stfsu     f0, 0x4(r3)
	  lfs       f0, 0x98(r30)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x9C(r30)
	  stfs      f0, 0x8(r3)
	  lwz       r5, 0x2C8(r30)
	  lwz       r3, 0x2C8(r31)
	  lfsu      f0, 0x10(r5)
	  stfsu     f0, 0x10(r3)
	  lfs       f0, 0x4(r5)
	  stfs      f0, 0x4(r3)
	  lfs       f0, 0x8(r5)
	  stfs      f0, 0x8(r3)
	  lfs       f0, 0xA0(r30)
	  lwz       r3, 0x2C8(r31)
	  stfs      f0, 0x1C(r3)
	  lwz       r3, 0x2C8(r30)
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x24094
	  lwz       r4, 0x2C8(r31)
	  mr        r3, r31
	  lwz       r4, 0x34(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  stfs      f1, 0x8(r4)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x170(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31

	.loc_0xC0:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void BTeki::outputDirectionPosition(Vector3f&, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801465B0
 * Size:	000190
 */
void BTeki::outputSpawnPosition(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stfd      f31, 0x98(r1)
	  stfd      f30, 0x90(r1)
	  stfd      f29, 0x88(r1)
	  stw       r31, 0x84(r1)
	  stw       r30, 0x80(r1)
	  addi      r30, r4, 0
	  li        r4, 0x17
	  stw       r29, 0x7C(r1)
	  mr        r29, r3
	  lwz       r3, 0x2C4(r3)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x24118
	  lwz       r3, 0x2C4(r29)
	  fmr       f29, f1
	  li        r4, 0x16
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x24130
	  lfs       f0, -0x58B0(r2)
	  fmr       f30, f1
	  stfs      f0, 0x70(r1)
	  stfs      f0, 0x6C(r1)
	  stfs      f0, 0x68(r1)
	  lfs       f31, 0xA0(r29)
	  fmr       f1, f31
	  bl        0xD5530
	  stfs      f1, 0x50(r1)
	  fmr       f1, f31
	  addi      r31, r1, 0x50
	  bl        0xD56B4
	  stfs      f1, 0x4C(r1)
	  addi      r4, r1, 0x4C
	  addi      r6, r31, 0
	  addi      r3, r1, 0x68
	  subi      r5, r13, 0x9D8
	  bl        -0xE8FC0
	  lwz       r3, 0x2C8(r29)
	  li        r4, 0
	  bl        -0x1E7A4
	  fmr       f31, f1
	  lwz       r3, 0x2C4(r29)
	  li        r4, 0x1
	  bl        -0x1E79C
	  fmuls     f1, f1, f31
	  lfs       f0, 0x68(r1)
	  li        r4, 0
	  fmuls     f1, f30, f1
	  fmuls     f0, f0, f1
	  stfs      f0, 0x68(r1)
	  lfs       f0, 0x6C(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x70(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x94(r29)
	  stfs      f0, 0x0(r30)
	  lfs       f0, 0x98(r29)
	  stfs      f0, 0x4(r30)
	  lfs       f0, 0x9C(r29)
	  stfs      f0, 0x8(r30)
	  lwz       r3, 0x2C8(r29)
	  lwz       r3, 0x34(r3)
	  bl        -0x234AC
	  lwz       r3, 0x2C4(r29)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x234C0
	  fmuls     f0, f1, f31
	  lfs       f1, 0x4(r30)
	  fmuls     f0, f29, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x0(r30)
	  lfs       f0, 0x68(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x0(r30)
	  lfs       f1, 0x4(r30)
	  lfs       f0, 0x6C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4(r30)
	  lfs       f1, 0x8(r30)
	  lfs       f0, 0x70(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8(r30)
	  lwz       r0, 0xA4(r1)
	  lfd       f31, 0x98(r1)
	  lfd       f30, 0x90(r1)
	  lfd       f29, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  lwz       r29, 0x7C(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146740
 * Size:	000250
 */
void BTeki::spawnTeki(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xC0(r1)
	  stfd      f31, 0xB8(r1)
	  stfd      f30, 0xB0(r1)
	  stfd      f29, 0xA8(r1)
	  stfd      f28, 0xA0(r1)
	  stw       r31, 0x9C(r1)
	  stw       r30, 0x98(r1)
	  stw       r29, 0x94(r1)
	  mr        r29, r3
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x194(r12)
	  mtlr      r12
	  blrl
	  mr.       r30, r3
	  bne-      .loc_0x4C
	  li        r3, 0
	  b         .loc_0x224

	.loc_0x4C:
	  lfs       f0, -0x58B0(r2)
	  li        r4, 0x17
	  stfs      f0, 0x8C(r1)
	  stfs      f0, 0x88(r1)
	  stfs      f0, 0x84(r1)
	  lwz       r3, 0x2C4(r29)
	  lwz       r3, 0x84(r3)
	  bl        -0x23598
	  lwz       r3, 0x2C4(r29)
	  fmr       f31, f1
	  li        r4, 0x16
	  lwz       r3, 0x84(r3)
	  bl        -0x235AC
	  lfs       f0, -0x58B0(r2)
	  fmr       f30, f1
	  mr        r3, r29
	  stfs      f0, 0x74(r1)
	  stfs      f0, 0x70(r1)
	  stfs      f0, 0x6C(r1)
	  bl        0x230
	  fmr       f29, f1
	  bl        0x1E8
	  stfs      f1, 0x50(r1)
	  fmr       f1, f29
	  addi      r31, r1, 0x50
	  bl        0x1F8
	  stfs      f1, 0x4C(r1)
	  addi      r4, r1, 0x4C
	  addi      r6, r31, 0
	  addi      r3, r1, 0x6C
	  subi      r5, r13, 0x9D8
	  bl        -0xE917C
	  addi      r3, r29, 0
	  li        r4, 0
	  bl        .loc_0x250
	  fmr       f29, f1
	  addi      r3, r29, 0
	  li        r4, 0x1
	  bl        0x188
	  fmuls     f1, f1, f29
	  addi      r4, r29, 0x94
	  lfs       f0, 0x6C(r1)
	  addi      r3, r1, 0x84
	  addi      r5, r4, 0x4
	  fmuls     f1, f30, f1
	  addi      r6, r4, 0x8
	  fmuls     f0, f0, f1
	  stfs      f0, 0x6C(r1)
	  lfs       f0, 0x70(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0x74(r1)
	  bl        -0xE91D8
	  lwz       r3, 0x2C8(r29)
	  li        r4, 0
	  bl        -0x1E9BC
	  fmr       f29, f1
	  lwz       r3, 0x2C4(r29)
	  li        r4, 0x1
	  bl        -0x1E9B4
	  fmuls     f0, f1, f29
	  lfs       f1, 0x88(r1)
	  fmuls     f0, f31, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x84(r1)
	  lfs       f0, 0x6C(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x84(r1)
	  lfs       f1, 0x88(r1)
	  lfs       f0, 0x70(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x8C(r1)
	  lfs       f0, 0x74(r1)
	  fadds     f0, f1, f0
	  stfs      f0, 0x8C(r1)
	  lwz       r3, 0x84(r1)
	  lwz       r0, 0x88(r1)
	  stw       r3, 0x94(r30)
	  stw       r0, 0x98(r30)
	  lwz       r0, 0x8C(r1)
	  stw       r0, 0x9C(r30)
	  lfs       f30, 0xA0(r29)
	  fmr       f1, f30
	  bl        0xD526C
	  fmr       f29, f1
	  fmr       f1, f30
	  bl        0xD53F4
	  lwz       r3, 0x2C8(r29)
	  fmr       f30, f1
	  lfs       f28, -0x9D8(r13)
	  li        r4, 0x1
	  lwz       r3, 0x34(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x2443C
	  lwz       r3, 0x2C4(r29)
	  fmr       f31, f1
	  li        r4, 0x18
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x24454
	  fmuls     f0, f1, f31
	  addi      r3, r30, 0
	  li        r4, 0
	  fmuls     f1, f30, f0
	  fmuls     f28, f28, f0
	  fmuls     f0, f29, f0
	  stfs      f1, 0x70(r30)
	  stfs      f28, 0x74(r30)
	  stfs      f0, 0x78(r30)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30

	.loc_0x224:
	  lwz       r0, 0xC4(r1)
	  lfd       f31, 0xB8(r1)
	  lfd       f30, 0xB0(r1)
	  lfd       f29, 0xA8(r1)
	  lfd       f28, 0xA0(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  lwz       r29, 0x94(r1)
	  addi      r1, r1, 0xC0
	  mtlr      r0
	  blr

	.loc_0x250:
	*/
}

/*
 * --INFO--
 * Address:	80146A10
 * Size:	000004
 */
void BTeki::shootBall(Creature&)
{
}

/*
 * --INFO--
 * Address:	80146A14
 * Size:	0000B4
 */
void BTeki::dump()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  stw       r30, 0x50(r1)
	  stw       r29, 0x4C(r1)
	  mr        r29, r3
	  lwz       r3, 0x2CC(r3)
	  lwz       r0, 0x44(r3)
	  cmpwi     r0, 0
	  lwz       r0, 0x28(r3)
	  cmplwi    r0, 0
	  lis       r3, 0x802B
	  subi      r30, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r30, 0x34(r1)
	  addi      r31, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r31, 0x34(r1)
	  subi      r0, r3, 0x2A84
	  stw       r0, 0x34(r1)
	  addi      r4, r1, 0x34
	  addi      r3, r29, 0
	  stw       r29, 0x38(r1)
	  bl        0x19EC
	  stw       r30, 0x2C(r1)
	  lis       r4, 0x802D
	  subi      r0, r4, 0x2A4C
	  stw       r31, 0x2C(r1)
	  addi      r30, r3, 0
	  addi      r4, r1, 0x2C
	  stw       r0, 0x2C(r1)
	  addi      r3, r29, 0
	  stw       r29, 0x30(r1)
	  bl        0x19C4
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0x1B00
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  lwz       r30, 0x50(r1)
	  lwz       r29, 0x4C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146AC8
 * Size:	0000E8
 */
void BTeki::nearestAngleTarget(Creature*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stfd      f31, 0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  stw       r29, 0x14(r1)
	  mr.       r29, r4
	  stw       r28, 0x10(r1)
	  addi      r28, r3, 0
	  bne-      .loc_0x34
	  li        r3, 0
	  b         .loc_0xC4

	.loc_0x34:
	  lwz       r30, 0x418(r28)
	  cmplwi    r30, 0
	  bne-      .loc_0x48
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0x48:
	  cmplw     r29, r30
	  bne-      .loc_0x58
	  li        r3, 0
	  b         .loc_0xC4

	.loc_0x58:
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        0x4D0
	  addi      r31, r3, 0
	  addi      r3, r28, 0
	  addi      r4, r30, 0
	  bl        0x4C0
	  rlwinm.   r0,r31,0,24,31
	  beq-      .loc_0xC0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xB8
	  addi      r4, r29, 0x94
	  addi      r3, r28, 0
	  bl        0x7AC
	  fmr       f31, f1
	  addi      r4, r30, 0x94
	  addi      r3, r28, 0
	  bl        0x79C
	  fcmpo     cr0, f31, f1
	  bge-      .loc_0xB0
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0xB0:
	  li        r3, 0
	  b         .loc_0xC4

	.loc_0xB8:
	  li        r3, 0x1
	  b         .loc_0xC4

	.loc_0xC0:
	  li        r3, 0

	.loc_0xC4:
	  lwz       r0, 0x2C(r1)
	  lfd       f31, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  lwz       r28, 0x10(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146BB0
 * Size:	000020
 */
void BTeki::cullableCenter(Creature&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  bl        -0xB932C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146BD0
 * Size:	000088
 */
void BTeki::cullableSphere(Creature&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stfd      f31, 0x28(r1)
	  stfd      f30, 0x20(r1)
	  fmr       f30, f1
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f31
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  fadds     f1, f30, f0
	  bl        -0xB93A4
	  lwz       r0, 0x34(r1)
	  lfd       f31, 0x28(r1)
	  lfd       f30, 0x20(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146C58
 * Size:	0000BC
 */
void BTeki::inSectorPosition(Vector3f&, f32, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stfd      f31, 0x40(r1)
	  fmr       f31, f2
	  stfd      f30, 0x38(r1)
	  fmr       f30, f1
	  stw       r31, 0x34(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x30(r1)
	  mr        r30, r3
	  addi      r0, r30, 0x94
	  mr        r4, r0
	  addi      r3, r1, 0x24
	  bl        -0x29E10
	  lfs       f3, 0x2C(r1)
	  lfs       f2, 0x8(r31)
	  lfs       f1, 0x24(r1)
	  lfs       f0, 0x0(r31)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x139078
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x74
	  li        r3, 0
	  b         .loc_0x9C

	.loc_0x74:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x62C
	  lfs       f0, -0x5894(r2)
	  fmuls     f0, f31, f0
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x98
	  li        r3, 0
	  b         .loc_0x9C

	.loc_0x98:
	  li        r3, 0x1

	.loc_0x9C:
	  lwz       r0, 0x4C(r1)
	  lfd       f31, 0x40(r1)
	  lfd       f30, 0x38(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146D14
 * Size:	000190
 */
void BTeki::visibleCreature(Creature&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0xF68
	  lis       r5, 0x802C
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stw       r31, 0xC4(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xC0(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0xB4
	  stw       r0, 0xB4(r1)
	  addi      r0, r5, 0x6964
	  lis       r5, 0x802D
	  stw       r0, 0xB4(r1)
	  subi      r0, r5, 0x295C
	  stw       r0, 0xB4(r1)
	  stw       r30, 0xB8(r1)
	  bl        0x3130
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x60
	  li        r3, 0
	  b         .loc_0x174

	.loc_0x60:
	  lwz       r5, 0x2C4(r30)
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f31, 0x18(r5)
	  fmr       f1, f31
	  bl        -0xB9504
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x94
	  li        r3, 0
	  b         .loc_0x174

	.loc_0x94:
	  addi      r4, r30, 0x94
	  addi      r3, r1, 0xA8
	  bl        -0x29F30
	  addi      r4, r31, 0x94
	  addi      r3, r1, 0x9C
	  bl        -0x29F3C
	  lwz       r3, 0x2C4(r30)
	  lfs       f1, 0xAC(r1)
	  lwz       r3, 0x84(r3)
	  lfs       f2, 0xA0(r1)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f0, 0x70(r3)
	  fadds     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0xDC
	  li        r3, 0
	  b         .loc_0x174

	.loc_0xDC:
	  lfs       f3, 0xB0(r1)
	  lfs       f2, 0xA4(r1)
	  lfs       f1, 0xA8(r1)
	  lfs       f0, 0x9C(r1)
	  fsubs     f2, f3, f2
	  fsubs     f1, f1, f0
	  fmuls     f0, f2, f2
	  fmuls     f1, f1, f1
	  fadds     f1, f1, f0
	  bl        -0x1391D4
	  fcmpo     cr0, f1, f31
	  ble-      .loc_0x114
	  li        r3, 0
	  b         .loc_0x174

	.loc_0x114:
	  lfs       f1, 0x3D4(r30)
	  lfs       f0, -0x58B0(r2)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0x130
	  li        r3, 0x1
	  b         .loc_0x174

	.loc_0x130:
	  addi      r3, r30, 0
	  addi      r4, r1, 0x9C
	  bl        0x4B4
	  lwz       r3, 0x2C4(r30)
	  lfs       f2, -0x5894(r2)
	  lwz       r3, 0x84(r3)
	  lfs       f0, -0x1CA8(r13)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f3, 0x1C(r3)
	  fmuls     f2, f3, f2
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x170
	  li        r3, 0
	  b         .loc_0x174

	.loc_0x170:
	  li        r3, 0x1

	.loc_0x174:
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  lwz       r31, 0xC4(r1)
	  lwz       r30, 0xC0(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146EA4
 * Size:	000154
 */
void BTeki::separateCreature(Creature&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0xF68
	  lis       r5, 0x802C
	  stwu      r1, -0x70(r1)
	  stfd      f31, 0x68(r1)
	  stfd      f30, 0x60(r1)
	  stw       r31, 0x5C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x58(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x4C
	  stw       r0, 0x4C(r1)
	  addi      r0, r5, 0x6964
	  lis       r5, 0x802D
	  stw       r0, 0x4C(r1)
	  subi      r0, r5, 0x295C
	  stw       r0, 0x4C(r1)
	  stw       r30, 0x50(r1)
	  bl        0x2F9C
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x64
	  li        r3, 0x1
	  b         .loc_0x134

	.loc_0x64:
	  lwz       r0, 0x184(r31)
	  cmplw     r0, r30
	  bne-      .loc_0x78
	  li        r3, 0
	  b         .loc_0x134

	.loc_0x78:
	  lwz       r3, 0x2C8(r30)
	  li        r4, 0
	  lwz       r3, 0x34(r3)
	  bl        -0x23D18
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x23D2C
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x24A80
	  fmuls     f0, f31, f30
	  lwz       r12, 0x0(r31)
	  lfs       f2, -0x5880(r2)
	  mr        r3, r31
	  lwz       r12, 0x64(r12)
	  fmuls     f0, f1, f0
	  mtlr      r12
	  fadds     f30, f2, f0
	  blrl
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f31
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  fadds     f1, f30, f0
	  bl        -0xB9714
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x114
	  li        r3, 0x1
	  b         .loc_0x134

	.loc_0x114:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x2AE0
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x130
	  li        r3, 0x1
	  b         .loc_0x134

	.loc_0x130:
	  li        r3, 0

	.loc_0x134:
	  lwz       r0, 0x74(r1)
	  lfd       f31, 0x68(r1)
	  lfd       f30, 0x60(r1)
	  lwz       r31, 0x5C(r1)
	  lwz       r30, 0x58(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80146FF8
 * Size:	000154
 */
void BTeki::contactCreature(Creature&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802B
	  stw       r0, 0x4(r1)
	  subi      r0, r5, 0xF68
	  lis       r5, 0x802C
	  stwu      r1, -0x60(r1)
	  stfd      f31, 0x58(r1)
	  stfd      f30, 0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x48(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x40
	  stw       r0, 0x40(r1)
	  addi      r0, r5, 0x6964
	  lis       r5, 0x802D
	  stw       r0, 0x40(r1)
	  subi      r0, r5, 0x295C
	  stw       r0, 0x40(r1)
	  stw       r30, 0x44(r1)
	  bl        0x2E48
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x64
	  li        r3, 0
	  b         .loc_0x134

	.loc_0x64:
	  lwz       r0, 0x184(r31)
	  cmplw     r0, r30
	  bne-      .loc_0x78
	  li        r3, 0x1
	  b         .loc_0x134

	.loc_0x78:
	  lwz       r3, 0x2C8(r30)
	  li        r4, 0
	  lwz       r3, 0x34(r3)
	  bl        -0x23E6C
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x23E80
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x24BD4
	  fmuls     f2, f31, f30
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lfs       f0, -0x5880(r2)
	  fmuls     f1, f1, f2
	  lwz       r12, 0x64(r12)
	  fsubs     f30, f1, f0
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f31
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  fadds     f1, f30, f0
	  bl        -0xB9868
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x114
	  li        r3, 0
	  b         .loc_0x134

	.loc_0x114:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x298C
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x130
	  li        r3, 0
	  b         .loc_0x134

	.loc_0x130:
	  li        r3, 0x1

	.loc_0x134:
	  lwz       r0, 0x64(r1)
	  lfd       f31, 0x58(r1)
	  lfd       f30, 0x50(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x60
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014714C
 * Size:	0001B4
 */
bool BTeki::attackableCreature(Creature&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stw       r31, 0x74(r1)
	  mr        r31, r4
	  stw       r30, 0x70(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x184(r4)
	  cmplw     r0, r30
	  bne-      .loc_0x38
	  li        r3, 0
	  b         .loc_0x194

	.loc_0x38:
	  lis       r3, 0x802B
	  subi      r0, r3, 0xF68
	  lis       r3, 0x802C
	  stw       r0, 0x60(r1)
	  addi      r0, r3, 0x6964
	  lis       r3, 0x802D
	  stw       r0, 0x60(r1)
	  subi      r0, r3, 0x295C
	  stw       r0, 0x60(r1)
	  addi      r4, r31, 0
	  addi      r3, r1, 0x60
	  stw       r30, 0x64(r1)
	  bl        0x2CDC
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x7C
	  li        r0, 0
	  b         .loc_0x140

	.loc_0x7C:
	  lwz       r0, 0x184(r31)
	  cmplw     r0, r30
	  bne-      .loc_0x90
	  li        r0, 0x1
	  b         .loc_0x140

	.loc_0x90:
	  lwz       r3, 0x2C8(r30)
	  li        r4, 0
	  bl        -0x1F330
	  fmr       f30, f1
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x1
	  bl        -0x1F328
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  bl        -0x23FF8
	  fmuls     f2, f31, f30
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lfs       f0, -0x5880(r2)
	  fmuls     f1, f1, f2
	  lwz       r12, 0x64(r12)
	  fsubs     f30, f1, f0
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  fadds     f0, f1, f31
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  fadds     f1, f30, f0
	  bl        -0xB99C8
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x120
	  li        r0, 0
	  b         .loc_0x140

	.loc_0x120:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x282C
	  fcmpo     cr0, f1, f30
	  ble-      .loc_0x13C
	  li        r0, 0
	  b         .loc_0x140

	.loc_0x13C:
	  li        r0, 0x1

	.loc_0x140:
	  rlwinm.   r0,r0,0,24,31
	  bne-      .loc_0x150
	  li        r3, 0
	  b         .loc_0x194

	.loc_0x150:
	  addi      r4, r31, 0x94
	  addi      r3, r30, 0
	  bl        .loc_0x1B4
	  lwz       r3, 0x2C4(r30)
	  lfs       f2, -0x1CA8(r13)
	  lwz       r3, 0x84(r3)
	  lfs       f0, -0x5894(r2)
	  lwz       r3, 0x4(r3)
	  lwz       r3, 0x0(r3)
	  lfs       f3, 0x24(r3)
	  fmuls     f2, f3, f2
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x190
	  li        r3, 0
	  b         .loc_0x194

	.loc_0x190:
	  li        r3, 0x1

	.loc_0x194:
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  lwz       r31, 0x74(r1)
	  lwz       r30, 0x70(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr

	.loc_0x1B4:
	*/
}

/*
 * --INFO--
 * Address:	80147300
 * Size:	0000F0
 */
void BTeki::calcTargetAngle(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stw       r31, 0x54(r1)
	  mr        r31, r3
	  lfs       f0, -0x58B0(r2)
	  stfs      f0, 0x3C(r1)
	  stfs      f0, 0x38(r1)
	  stfs      f0, 0x34(r1)
	  lfs       f1, 0x0(r4)
	  lfs       f0, 0x94(r3)
	  lfs       f4, 0x8(r4)
	  fsubs     f0, f1, f0
	  lfs       f3, 0x9C(r31)
	  lfs       f2, 0x4(r4)
	  lfs       f1, 0x98(r31)
	  fsubs     f3, f4, f3
	  stfs      f0, 0x28(r1)
	  fsubs     f1, f2, f1
	  lfs       f0, 0x28(r1)
	  stfs      f0, 0x34(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f3, 0x3C(r1)
	  lfs       f1, 0x34(r1)
	  lfs       f2, 0x3C(r1)
	  bl        -0x2955C
	  lfs       f4, 0xA0(r31)
	  lfs       f0, -0x58B0(r2)
	  lfs       f3, -0x5898(r2)
	  lfs       f2, -0x1CA4(r13)
	  fcmpo     cr0, f4, f0
	  fmuls     f0, f3, f2
	  bge-      .loc_0x8C
	  fadds     f4, f4, f0
	  b         .loc_0x9C

	.loc_0x8C:
	  fcmpo     cr0, f4, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x9C
	  fsubs     f4, f4, f0

	.loc_0x9C:
	  fcmpo     cr0, f4, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xC4
	  fsubs     f1, f4, f1
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xBC
	  b         .loc_0xDC

	.loc_0xBC:
	  fmr       f1, f0
	  b         .loc_0xDC

	.loc_0xC4:
	  fsubs     f1, f1, f4
	  fsubs     f0, f0, f1
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xD8
	  b         .loc_0xDC

	.loc_0xD8:
	  fmr       f1, f0

	.loc_0xDC:
	  lwz       r0, 0x5C(r1)
	  lwz       r31, 0x54(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801473F0
 * Size:	0001DC
 */
void BTeki::moveToward(Vector3f&, f32)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  fmr       f31, f1
	  stw       r31, 0x84(r1)
	  stw       r30, 0x80(r1)
	  addi      r30, r3, 0
	  addi      r31, r30, 0x94
	  addi      r3, r1, 0x5C
	  bl        -0x2A598
	  lfs       f0, -0x58B0(r2)
	  mr        r4, r31
	  addi      r3, r1, 0x68
	  stfs      f0, 0x60(r1)
	  bl        -0x2A5AC
	  lfs       f0, -0x58B0(r2)
	  stfs      f0, 0x6C(r1)
	  lfs       f1, 0x5C(r1)
	  lfs       f0, 0x68(r1)
	  lfs       f3, 0x60(r1)
	  lfs       f2, 0x6C(r1)
	  fsubs     f0, f1, f0
	  lfs       f4, 0x64(r1)
	  lfs       f1, 0x70(r1)
	  fsubs     f2, f3, f2
	  stfs      f0, 0xA4(r30)
	  fsubs     f0, f4, f1
	  stfs      f2, 0xA8(r30)
	  stfs      f0, 0xAC(r30)
	  lfs       f1, 0xA4(r30)
	  lfs       f0, 0xA8(r30)
	  lfs       f2, 0xAC(r30)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x139848
	  lfs       f0, -0x58B0(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xAC
	  b         .loc_0xB0

	.loc_0xAC:
	  fneg      f1, f1

	.loc_0xB0:
	  lfs       f0, -0x1CB0(r13)
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  beq-      .loc_0xF8
	  lfs       f1, 0xA4(r30)
	  lfs       f0, 0xA8(r30)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xAC(r30)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x139890
	  lfs       f0, -0x58B0(r2)
	  fcmpu     cr0, f0, f1
	  beq-      .loc_0xF8
	  addi      r3, r30, 0xA4
	  bl        -0xBDF98

	.loc_0xF8:
	  lfs       f0, 0xA4(r30)
	  addi      r6, r1, 0x3C
	  addi      r5, r1, 0x38
	  fmuls     f0, f0, f31
	  addi      r4, r1, 0x34
	  addi      r3, r1, 0x48
	  stfs      f0, 0xA4(r30)
	  lfs       f0, 0xA8(r30)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xA8(r30)
	  lfs       f0, 0xAC(r30)
	  fmuls     f0, f0, f31
	  stfs      f0, 0xAC(r30)
	  lfs       f0, -0x58B0(r2)
	  stfs      f0, 0x50(r1)
	  stfs      f0, 0x4C(r1)
	  stfs      f0, 0x48(r1)
	  lfs       f1, 0x68(r1)
	  lfs       f3, 0x70(r1)
	  lfs       f2, 0x64(r1)
	  lfs       f0, 0x5C(r1)
	  fsubs     f2, f3, f2
	  fsubs     f0, f1, f0
	  stfs      f2, 0x3C(r1)
	  lfs       f2, 0x6C(r1)
	  lfs       f1, 0x60(r1)
	  fsubs     f1, f2, f1
	  stfs      f0, 0x34(r1)
	  stfs      f1, 0x38(r1)
	  bl        -0xE9ED0
	  lfs       f1, 0x48(r1)
	  lfs       f0, 0x4C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x50(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x139940
	  lfs       f0, -0x5898(r2)
	  lwz       r3, 0x3150(r13)
	  fmuls     f2, f0, f31
	  lfs       f0, 0x28C(r3)
	  fmuls     f0, f2, f0
	  fcmpo     cr0, f1, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1BC
	  li        r3, 0x1
	  b         .loc_0x1C0

	.loc_0x1BC:
	  li        r3, 0

	.loc_0x1C0:
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lwz       r31, 0x84(r1)
	  lwz       r30, 0x80(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801475CC
 * Size:	0000C8
 */
void BTeki::turnToward(f32, f32)
{
	/*
	.loc_0x0:
	  lfs       f5, 0xA0(r3)
	  lfs       f0, -0x58B0(r2)
	  lfs       f4, -0x5898(r2)
	  lfs       f3, -0x1CA4(r13)
	  fcmpo     cr0, f5, f0
	  fmuls     f4, f4, f3
	  bge-      .loc_0x24
	  fadds     f5, f5, f4
	  b         .loc_0x34

	.loc_0x24:
	  fcmpo     cr0, f5, f4
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x34
	  fsubs     f5, f5, f4

	.loc_0x34:
	  fcmpo     cr0, f1, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x58
	  fsubs     f3, f1, f5
	  fsubs     f0, f4, f3
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x6C
	  fsubs     f1, f1, f4
	  b         .loc_0x6C

	.loc_0x58:
	  fsubs     f3, f5, f1
	  fsubs     f0, f4, f3
	  fcmpo     cr0, f0, f3
	  bge-      .loc_0x6C
	  fadds     f1, f1, f4

	.loc_0x6C:
	  lwz       r4, 0x3150(r13)
	  fcmpo     cr0, f1, f5
	  li        r0, 0
	  lfs       f0, 0x28C(r4)
	  fmuls     f2, f2, f0
	  ble-      .loc_0xA4
	  fsubs     f0, f1, f5
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0x98
	  fmr       f2, f0
	  li        r0, 0x1

	.loc_0x98:
	  fadds     f0, f5, f2
	  stfs      f0, 0xA0(r3)
	  b         .loc_0xC0

	.loc_0xA4:
	  fsubs     f0, f5, f1
	  fcmpo     cr0, f0, f2
	  bge-      .loc_0xB8
	  fmr       f2, f0
	  li        r0, 0x1

	.loc_0xB8:
	  fsubs     f0, f5, f2
	  stfs      f0, 0xA0(r3)

	.loc_0xC0:
	  mr        r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80147694
 * Size:	00004C
 */
void BTeki::rotateTeki(f32)
{
	/*
	.loc_0x0:
	  lfs       f4, 0xA0(r3)
	  lfs       f0, -0x58B0(r2)
	  lfs       f3, -0x5898(r2)
	  lfs       f2, -0x1CA4(r13)
	  fcmpo     cr0, f4, f0
	  fmuls     f0, f3, f2
	  bge-      .loc_0x24
	  fadds     f4, f4, f0
	  b         .loc_0x34

	.loc_0x24:
	  fcmpo     cr0, f4, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x34
	  fsubs     f4, f4, f0

	.loc_0x34:
	  lwz       r4, 0x3150(r13)
	  lfs       f0, 0x28C(r4)
	  fmuls     f0, f1, f0
	  fadds     f0, f4, f0
	  stfs      f0, 0xA0(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000218
 */
void BTeki::jumpTo(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000168
 */
void BTeki::insideDirection(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801476E0
 * Size:	000254
 */
Creature* BTeki::getClosestNaviPiki(Condition&, f32*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stmw      r26, 0xB0(r1)
	  mr        r30, r3
	  addi      r26, r4, 0
	  addi      r31, r5, 0
	  lwz       r3, 0x3120(r13)
	  bl        -0x30340
	  addi      r0, r3, 0
	  addi      r3, r26, 0
	  lwz       r12, 0x0(r26)
	  mr        r28, r0
	  addi      r4, r28, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x54
	  li        r28, 0

	.loc_0x54:
	  lwz       r3, 0x3068(r13)
	  addi      r29, r30, 0x94
	  addi      r4, r29, 0
	  lwz       r12, 0x0(r3)
	  mr        r5, r26
	  lwz       r12, 0x6C(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r28, 0
	  addi      r27, r3, 0
	  li        r26, 0
	  bne-      .loc_0x94
	  cmplwi    r27, 0
	  beq-      .loc_0x1AC
	  mr        r26, r27
	  b         .loc_0x1AC

	.loc_0x94:
	  cmplwi    r27, 0
	  bne-      .loc_0xA4
	  mr        r26, r28
	  b         .loc_0x1AC

	.loc_0xA4:
	  lfs       f0, -0x58B0(r2)
	  addi      r6, r1, 0x64
	  addi      r5, r1, 0x60
	  stfs      f0, 0xA0(r1)
	  addi      r4, r1, 0x5C
	  addi      r3, r1, 0x98
	  stfs      f0, 0x9C(r1)
	  stfs      f0, 0x98(r1)
	  lfs       f1, 0x9C(r28)
	  lfs       f0, 0x8(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x64(r1)
	  lfs       f1, 0x98(r28)
	  lfs       f0, 0x4(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x60(r1)
	  lfs       f1, 0x94(r28)
	  lfs       f0, 0x0(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x5C(r1)
	  bl        -0xEA148
	  lfs       f1, 0x98(r1)
	  lfs       f0, 0x9C(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0xA0(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x139BB8
	  lfs       f0, -0x58B0(r2)
	  fmr       f31, f1
	  addi      r6, r1, 0x58
	  stfs      f0, 0x8C(r1)
	  addi      r5, r1, 0x54
	  addi      r4, r1, 0x50
	  stfs      f0, 0x88(r1)
	  addi      r3, r1, 0x84
	  stfs      f0, 0x84(r1)
	  lfs       f1, 0x9C(r27)
	  lfs       f0, 0x8(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x58(r1)
	  lfs       f1, 0x98(r27)
	  lfs       f0, 0x4(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x54(r1)
	  lfs       f1, 0x94(r27)
	  lfs       f0, 0x0(r29)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x50(r1)
	  bl        -0xEA1C4
	  lfs       f1, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x8C(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x139C34
	  fcmpo     cr0, f31, f1
	  bge-      .loc_0x1A8
	  mr        r26, r28
	  b         .loc_0x1AC

	.loc_0x1A8:
	  mr        r26, r27

	.loc_0x1AC:
	  cmplwi    r31, 0
	  beq-      .loc_0x238
	  cmplwi    r26, 0
	  beq-      .loc_0x238
	  lfs       f0, -0x58B0(r2)
	  addi      r6, r1, 0x4C
	  addi      r5, r1, 0x48
	  stfs      f0, 0x78(r1)
	  addi      r4, r1, 0x44
	  addi      r3, r1, 0x70
	  stfs      f0, 0x74(r1)
	  stfs      f0, 0x70(r1)
	  lfs       f1, 0x9C(r26)
	  lfs       f0, 0x9C(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4C(r1)
	  lfs       f1, 0x98(r26)
	  lfs       f0, 0x98(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x48(r1)
	  lfs       f1, 0x94(r26)
	  lfs       f0, 0x94(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x44(r1)
	  bl        -0xEA260
	  lfs       f1, 0x70(r1)
	  lfs       f0, 0x74(r1)
	  fmuls     f1, f1, f1
	  lfs       f2, 0x78(r1)
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x139CD0
	  stfs      f1, 0x0(r31)

	.loc_0x238:
	  mr        r3, r26
	  lmw       r26, 0xB0(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80147934
 * Size:	0000DC
 */
void BTeki::attackTarget(Creature&, f32, f32, Condition&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  fmr       f31, f2
	  stfd      f30, 0x40(r1)
	  fmr       f30, f1
	  stw       r31, 0x3C(r1)
	  mr        r31, r4
	  stw       r30, 0x38(r1)
	  mr        r30, r3
	  mr        r3, r5
	  lwz       r12, 0x0(r5)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x50
	  li        r3, 0
	  b         .loc_0xBC

	.loc_0x50:
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x2114
	  lfs       f0, -0x5880(r2)
	  fadds     f0, f0, f30
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x74
	  li        r3, 0
	  b         .loc_0xBC

	.loc_0x74:
	  lis       r3, 0x802B
	  subi      r0, r3, 0x3064
	  stw       r0, 0x20(r1)
	  lis       r3, 0x802B
	  subi      r3, r3, 0x31FC
	  stw       r30, 0x24(r1)
	  li        r0, 0
	  addi      r4, r1, 0x20
	  stw       r3, 0x20(r1)
	  mr        r3, r31
	  stfs      f31, 0x28(r1)
	  stw       r0, 0x2C(r1)
	  stb       r0, 0x30(r1)
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r3, 0x1

	.loc_0xBC:
	  lwz       r0, 0x54(r1)
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  lwz       r31, 0x3C(r1)
	  lwz       r30, 0x38(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80147A10
 * Size:	000108
 */
void BTeki::outputHitCenter(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x78(r1)
	  stfd      f31, 0x70(r1)
	  stfd      f30, 0x68(r1)
	  stfd      f29, 0x60(r1)
	  stfd      f28, 0x58(r1)
	  stfd      f27, 0x50(r1)
	  stfd      f26, 0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  mr        r30, r3
	  lfs       f28, 0xA0(r3)
	  fmr       f1, f28
	  bl        0xD4108
	  fmr       f27, f1
	  fmr       f1, f28
	  bl        0xD4290
	  fmr       f28, f1
	  lfs       f26, -0x9D8(r13)
	  lwz       r3, 0x2C8(r30)
	  li        r4, 0
	  bl        -0x1FBB8
	  fmr       f29, f1
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x1
	  bl        -0x1FBB0
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0xA
	  lwz       r3, 0x84(r3)
	  bl        -0x24880
	  mr        r3, r30
	  fmr       f31, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x188(r12)
	  mtlr      r12
	  blrl
	  fmuls     f3, f30, f29
	  lfs       f0, 0x94(r30)
	  lfs       f2, 0x98(r30)
	  fmuls     f4, f31, f3
	  lfs       f3, 0x9C(r30)
	  fadds     f1, f1, f4
	  fmuls     f4, f28, f1
	  fmuls     f26, f26, f1
	  fmuls     f1, f27, f1
	  fadds     f0, f0, f4
	  fadds     f2, f2, f26
	  fadds     f1, f3, f1
	  stfs      f0, 0x0(r31)
	  stfs      f2, 0x4(r31)
	  stfs      f1, 0x8(r31)
	  lwz       r0, 0x7C(r1)
	  lfd       f31, 0x70(r1)
	  lfd       f30, 0x68(r1)
	  lfd       f29, 0x60(r1)
	  lfd       f28, 0x58(r1)
	  lfd       f27, 0x50(r1)
	  lfd       f26, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x78
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001F4
 */
void BTeki::attackRangeNaviPiki(Interaction&, Condition&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00015C
 */
void BTeki::interactTeki(Interaction&, Condition&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80147B18
 * Size:	00007C
 */
void BTeki::interactNaviPiki(Interaction&, Condition&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  bl        .loc_0x7C
	  addi      r31, r3, 0
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  addi      r5, r30, 0
	  bl        0xD0
	  rlwinm.   r0,r31,0,24,31
	  li        r4, 0x1
	  bne-      .loc_0x58
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0x58
	  li        r4, 0

	.loc_0x58:
	  lwz       r0, 0x2C(r1)
	  mr        r3, r4
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x7C:
	*/
}

/*
 * --INFO--
 * Address:	80147B94
 * Size:	000090
 */
void BTeki::interactNavi(Interaction&, Condition&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r5, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  lwz       r3, 0x3120(r13)
	  bl        -0x307F8
	  addi      r0, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  mr        r30, r0
	  addi      r4, r30, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x70
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r31, 0x1

	.loc_0x70:
	  mr        r3, r31
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80147C24
 * Size:	000150
 */
void BTeki::interactPiki(Interaction&, Condition&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x48(r1)
	  stmw      r26, 0x30(r1)
	  addi      r26, r4, 0
	  addi      r27, r5, 0
	  li        r29, 0
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xDC

	.loc_0x3C:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x60
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x78

	.loc_0x60:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x78:
	  cmplwi    r3, 0
	  addi      r28, r3, 0
	  beq-      .loc_0x138
	  mr        r3, r27
	  lwz       r12, 0x0(r27)
	  mr        r4, r28
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xC0
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r26
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  li        r29, 0x1

	.loc_0xC0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xDC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x104
	  li        r0, 0x1
	  b         .loc_0x130

	.loc_0x104:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x12C
	  li        r0, 0x1
	  b         .loc_0x130

	.loc_0x12C:
	  li        r0, 0

	.loc_0x130:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x3C

	.loc_0x138:
	  mr        r3, r29
	  lmw       r26, 0x30(r1)
	  lwz       r0, 0x4C(r1)
	  addi      r1, r1, 0x48
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80147D74
 * Size:	000034
 */
void BTeki::flick()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  bl        0x64
	  mr        r3, r31
	  bl        0x270
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80147DA8
 * Size:	000044
 */
void BTeki::flick(InteractFlick&, InteractFlick&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r5, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  bl        0x90
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x298
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80147DEC
 * Size:	000068
 */
void BTeki::flickUpper()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  subi      r0, r5, 0x3168
	  stwu      r1, -0x58(r1)
	  subi      r6, r6, 0x3064
	  lwz       r4, 0x2C4(r3)
	  lfs       f1, -0x58B0(r2)
	  lwz       r7, 0x84(r4)
	  addi      r4, r1, 0x40
	  lfs       f0, -0x5870(r2)
	  lwz       r7, 0x4(r7)
	  lwz       r5, 0x0(r7)
	  lfs       f2, 0x84(r5)
	  stw       r6, 0x40(r1)
	  stw       r3, 0x44(r1)
	  stw       r0, 0x40(r1)
	  stfs      f2, 0x48(r1)
	  stfs      f1, 0x4C(r1)
	  stfs      f0, 0x50(r1)
	  bl        .loc_0x68
	  lwz       r0, 0x5C(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0x68:
	*/
}

/*
 * --INFO--
 * Address:	80147E54
 * Size:	0001AC
 */
void BTeki::flickUpper(InteractFlick&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x98(r1)
	  stfd      f31, 0x90(r1)
	  stfd      f30, 0x88(r1)
	  stfd      f29, 0x80(r1)
	  stfd      f28, 0x78(r1)
	  stmw      r26, 0x60(r1)
	  addi      r26, r3, 0
	  addi      r27, r4, 0
	  addi      r4, r26, 0
	  addi      r3, r1, 0x44
	  bl        -0xB7200
	  addi      r30, r1, 0x44
	  addi      r3, r30, 0
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lfd       f29, -0x5878(r2)
	  mr        r29, r3
	  lfs       f30, -0x587C(r2)
	  lis       r31, 0x4330
	  lfs       f31, -0x5880(r2)
	  b         .loc_0x12C

	.loc_0x64:
	  cmpwi     r29, -0x1
	  bne-      .loc_0x88
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0xA0

	.loc_0x88:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0xA0:
	  cmplwi    r3, 0
	  addi      r28, r3, 0
	  beq-      .loc_0x188
	  lwz       r3, 0x2C4(r26)
	  li        r4, 0x20
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x25A3C
	  fmr       f28, f1
	  bl        0xD0158
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x5C(r1)
	  stw       r31, 0x58(r1)
	  lfd       f0, 0x58(r1)
	  fsubs     f0, f0, f29
	  fdivs     f0, f0, f30
	  fmuls     f0, f31, f0
	  fcmpo     cr0, f0, f28
	  bge-      .loc_0x110
	  mr        r3, r28
	  lwz       r12, 0x0(r28)
	  mr        r4, r27
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r29, 0
	  blt-      .loc_0x110
	  subi      r29, r29, 0x1

	.loc_0x110:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r29, r3

	.loc_0x12C:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x154
	  li        r0, 0x1
	  b         .loc_0x180

	.loc_0x154:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r29
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x17C
	  li        r0, 0x1
	  b         .loc_0x180

	.loc_0x17C:
	  li        r0, 0

	.loc_0x180:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x64

	.loc_0x188:
	  lmw       r26, 0x60(r1)
	  lwz       r0, 0x9C(r1)
	  lfd       f31, 0x90(r1)
	  lfd       f30, 0x88(r1)
	  lfd       f29, 0x80(r1)
	  lfd       f28, 0x78(r1)
	  addi      r1, r1, 0x98
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148000
 * Size:	000068
 */
void BTeki::flickLower()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r6, 0x802B
	  stw       r0, 0x4(r1)
	  lis       r5, 0x802B
	  subi      r0, r5, 0x3168
	  stwu      r1, -0x80(r1)
	  subi      r6, r6, 0x3064
	  lwz       r4, 0x2C4(r3)
	  lfs       f0, -0x5870(r2)
	  lwz       r7, 0x84(r4)
	  addi      r4, r1, 0x68
	  lwz       r7, 0x4(r7)
	  lwz       r5, 0x0(r7)
	  lfs       f1, 0x90(r5)
	  lfs       f2, 0x88(r5)
	  stw       r6, 0x68(r1)
	  stw       r3, 0x6C(r1)
	  stw       r0, 0x68(r1)
	  stfs      f2, 0x70(r1)
	  stfs      f1, 0x74(r1)
	  stfs      f0, 0x78(r1)
	  bl        .loc_0x68
	  lwz       r0, 0x84(r1)
	  addi      r1, r1, 0x80
	  mtlr      r0
	  blr

	.loc_0x68:
	*/
}

/*
 * --INFO--
 * Address:	80148068
 * Size:	000284
 */
void BTeki::flickLower(InteractFlick&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF8(r1)
	  stfd      f31, 0xF0(r1)
	  stfd      f30, 0xE8(r1)
	  stw       r31, 0xE4(r1)
	  addi      r31, r4, 0
	  li        r4, 0
	  stw       r30, 0xE0(r1)
	  mr        r30, r3
	  stw       r29, 0xDC(r1)
	  lwz       r3, 0x2C8(r3)
	  bl        -0x201E4
	  fmr       f30, f1
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0x1
	  bl        -0x201DC
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x2D
	  lwz       r3, 0x84(r3)
	  bl        -0x24EAC
	  lis       r3, 0x802B
	  fmuls     f0, f31, f30
	  subi      r29, r3, 0xF68
	  lwz       r3, 0x3120(r13)
	  lis       r4, 0x802C
	  stw       r29, 0x9C(r1)
	  addi      r12, r4, 0x6964
	  stw       r29, 0xBC(r1)
	  lis       r7, 0x802D
	  fmuls     f0, f1, f0
	  stw       r29, 0xC8(r1)
	  lis       r4, 0x802C
	  lis       r6, 0x802C
	  stw       r29, 0xAC(r1)
	  lis       r5, 0x802D
	  stw       r29, 0xB4(r1)
	  lis       r9, 0x802D
	  subi      r0, r7, 0x29D8
	  stw       r12, 0x9C(r1)
	  addi      r7, r4, 0x685C
	  addi      r10, r6, 0x6890
	  stw       r12, 0xBC(r1)
	  subi      r8, r5, 0x295C
	  addi      r6, r1, 0xB4
	  stw       r12, 0xC8(r1)
	  addi      r4, r1, 0xBC
	  subi      r11, r9, 0x2924
	  stw       r0, 0x9C(r1)
	  addi      r9, r1, 0xA8
	  addi      r5, r1, 0xAC
	  stw       r29, 0xA8(r1)
	  addi      r0, r1, 0x9C
	  stw       r12, 0xAC(r1)
	  stw       r12, 0xB4(r1)
	  stw       r7, 0xBC(r1)
	  stw       r7, 0xC8(r1)
	  stw       r30, 0xA0(r1)
	  stw       r12, 0xA8(r1)
	  stw       r10, 0xAC(r1)
	  stw       r8, 0xB4(r1)
	  stw       r6, 0xC0(r1)
	  stw       r4, 0xCC(r1)
	  stfs      f0, 0xA4(r1)
	  stw       r11, 0xA8(r1)
	  stw       r9, 0xB0(r1)
	  stw       r30, 0xB8(r1)
	  stw       r5, 0xC4(r1)
	  stw       r0, 0xD0(r1)
	  bl        -0x30DBC
	  lwz       r12, 0xC8(r1)
	  mr        r29, r3
	  addi      r4, r29, 0
	  lwz       r12, 0x8(r12)
	  addi      r3, r1, 0xC8
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x158
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r31
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x158:
	  lfs       f0, -0x58B0(r2)
	  li        r0, 0
	  addi      r3, r1, 0x84
	  stfs      f0, 0xC(r31)
	  lwz       r4, 0x3068(r13)
	  stw       r4, 0x88(r1)
	  stw       r0, 0x8C(r1)
	  bl        -0xB8420
	  b         .loc_0x204

	.loc_0x17C:
	  lwz       r4, 0x84(r1)
	  cmpwi     r4, -0x1
	  bne-      .loc_0x1A4
	  lwz       r3, 0x88(r1)
	  li        r4, 0
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x1B8

	.loc_0x1A4:
	  lwz       r3, 0x88(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x1B8:
	  cmplwi    r3, 0
	  addi      r29, r3, 0
	  beq-      .loc_0x260
	  lwz       r12, 0xC8(r1)
	  addi      r4, r29, 0
	  addi      r3, r1, 0xC8
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x1FC
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r31
	  lwz       r12, 0xA0(r12)
	  mtlr      r12
	  blrl

	.loc_0x1FC:
	  addi      r3, r1, 0x84
	  bl        -0xB85D0

	.loc_0x204:
	  lwz       r3, 0x88(r1)
	  lwz       r4, 0x84(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x22C
	  li        r0, 0x1
	  b         .loc_0x258

	.loc_0x22C:
	  lwz       r3, 0x88(r1)
	  lwz       r4, 0x84(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x254
	  li        r0, 0x1
	  b         .loc_0x258

	.loc_0x254:
	  li        r0, 0

	.loc_0x258:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x17C

	.loc_0x260:
	  lwz       r0, 0xFC(r1)
	  lfd       f31, 0xF0(r1)
	  lfd       f30, 0xE8(r1)
	  lwz       r31, 0xE4(r1)
	  lwz       r30, 0xE0(r1)
	  lwz       r29, 0xDC(r1)
	  addi      r1, r1, 0xF8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801482EC
 * Size:	000174
 */
void BTeki::checkNaviPiki(Condition&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  mr        r29, r4
	  lwz       r3, 0x3120(r13)
	  bl        -0x30F48
	  lwz       r12, 0x0(r29)
	  addi      r0, r3, 0
	  addi      r3, r29, 0
	  lwz       r12, 0x8(r12)
	  mr        r4, r0
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x50
	  li        r3, 0x1
	  b         .loc_0x158

	.loc_0x50:
	  lwz       r31, 0x3068(r13)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xF8

	.loc_0x70:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x98
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  b         .loc_0xB4

	.loc_0x98:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3

	.loc_0xB4:
	  lwz       r12, 0x0(r29)
	  mr        r3, r29
	  mr        r4, r0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDC
	  li        r3, 0x1
	  b         .loc_0x158

	.loc_0xDC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xF8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x120
	  li        r0, 0x1
	  b         .loc_0x14C

	.loc_0x120:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x148
	  li        r0, 0x1
	  b         .loc_0x14C

	.loc_0x148:
	  li        r0, 0

	.loc_0x14C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x70
	  li        r3, 0

	.loc_0x158:
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148460
 * Size:	000148
 */
void BTeki::countPikis(Condition&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  stw       r29, 0x2C(r1)
	  li        r29, 0
	  stw       r28, 0x28(r1)
	  addi      r28, r4, 0
	  lwz       r31, 0x3068(r13)
	  lwz       r12, 0x0(r31)
	  addi      r3, r31, 0
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xC8

	.loc_0x44:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x6C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3
	  b         .loc_0x88

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r0, r3

	.loc_0x88:
	  lwz       r12, 0x0(r28)
	  mr        r3, r28
	  mr        r4, r0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xAC
	  addi      r29, r29, 0x1

	.loc_0xAC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xC8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xF0
	  li        r0, 0x1
	  b         .loc_0x11C

	.loc_0xF0:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x118
	  li        r0, 0x1
	  b         .loc_0x11C

	.loc_0x118:
	  li        r0, 0

	.loc_0x11C:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x44
	  mr        r3, r29
	  lwz       r0, 0x3C(r1)
	  lwz       r31, 0x34(r1)
	  lwz       r30, 0x30(r1)
	  lwz       r29, 0x2C(r1)
	  lwz       r28, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
void BTeki::countTekis(Condition&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801485A8
 * Size:	000054
 */
void BTeki::getFlickDamageCount(int)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2C4(r3)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x28(r3)
	  cmpw      r4, r0
	  bgt-      .loc_0x24
	  lwz       r3, 0x34(r3)
	  blr

	.loc_0x24:
	  lwz       r0, 0x2C(r3)
	  cmpw      r4, r0
	  bgt-      .loc_0x38
	  lwz       r3, 0x38(r3)
	  blr

	.loc_0x38:
	  lwz       r0, 0x30(r3)
	  cmpw      r4, r0
	  bgt-      .loc_0x4C
	  lwz       r3, 0x3C(r3)
	  blr

	.loc_0x4C:
	  lwz       r3, 0x40(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801485FC
 * Size:	000040
 */
void BTeki::eventPerformed(TekiEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  bl        0x324
	  lwz       r12, 0x0(r3)
	  mr        r4, r31
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014863C
 * Size:	000098
 */
void BTeki::collisionCallback(CollEvent&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r4
	  stw       r30, 0x20(r1)
	  mr        r30, r3
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x80
	  lwz       r31, 0x0(r31)
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x88(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x80
	  addi      r5, r30, 0
	  addi      r6, r31, 0
	  addi      r3, r1, 0x10
	  li        r4, 0x1
	  bl        0x1D2C
	  lwz       r12, 0x0(r30)
	  addi      r4, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x1A0(r12)
	  mtlr      r12
	  blrl

	.loc_0x80:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801486D4
 * Size:	00001C
 */
bool BTeki::ignoreAtari(Creature*)
{
	/*
	.loc_0x0:
	  lwz       r0, 0x184(r4)
	  cmplw     r0, r3
	  bne-      .loc_0x14
	  li        r3, 0x1
	  blr

	.loc_0x14:
	  li        r3, 0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801486F0
 * Size:	000050
 */
void BTeki::bounceCallback()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0xC
	  bl        0x1C88
	  lwz       r12, 0x0(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x1A0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148740
 * Size:	000050
 */
void BTeki::wallCallback(Plane&, DynCollObject*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x2
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  addi      r31, r3, 0
	  addi      r5, r31, 0
	  addi      r3, r1, 0x14
	  bl        0x1C38
	  lwz       r12, 0x0(r31)
	  addi      r4, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x1A0(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148790
 * Size:	000050
 */
void BTeki::interact(TekiInteractionKey&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  addi      r30, r3, 0
	  bl        0x188
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x20(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801487E0
 * Size:	000148
 */
void BTeki::interactDefault(TekiInteractionKey&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  lwz       r0, 0x0(r4)
	  cmpwi     r0, 0
	  bne-      .loc_0xB0
	  lwz       r0, 0x410(r30)
	  lwz       r31, 0x4(r4)
	  rlwinm.   r0,r0,0,22,22
	  beq-      .loc_0x3C
	  li        r3, 0
	  b         .loc_0x130

	.loc_0x3C:
	  mr        r3, r31
	  bl        -0xCC7E0
	  stw       r3, 0x344(r30)
	  lfs       f1, 0x33C(r30)
	  lfs       f0, 0x8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x33C(r30)
	  lwz       r0, 0x410(r30)
	  rlwinm.   r0,r0,0,16,16
	  beq-      .loc_0x74
	  lfs       f1, 0x340(r30)
	  lfs       f0, -0x5880(r2)
	  fadds     f0, f1, f0
	  stfs      f0, 0x340(r30)

	.loc_0x74:
	  lwz       r3, 0x41C(r30)
	  lwz       r31, 0x4(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x94
	  beq-      .loc_0x94
	  bl        -0x644FC
	  li        r0, 0
	  stw       r0, 0x41C(r30)

	.loc_0x94:
	  stw       r31, 0x41C(r30)
	  lwz       r3, 0x41C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0xA8
	  bl        -0x64528

	.loc_0xA8:
	  li        r3, 0x1
	  b         .loc_0x130

	.loc_0xB0:
	  cmpwi     r0, 0x1
	  bne-      .loc_0x12C
	  lwz       r31, 0x4(r4)
	  li        r4, 0x45
	  lwz       r3, 0x3180(r13)
	  li        r6, 0
	  addi      r5, r31, 0x8
	  li        r7, 0
	  bl        0x54288
	  lwz       r0, 0x320(r30)
	  cmpwi     r0, 0x11
	  bne-      .loc_0x104
	  lwz       r3, 0x20(r31)
	  bl        -0xC0B84
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x12C
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x5F
	  bl        -0xBE328
	  b         .loc_0x12C

	.loc_0x104:
	  cmpwi     r0, 0x9
	  bne-      .loc_0x12C
	  lwz       r3, 0x20(r31)
	  bl        -0xC0BB0
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x12C
	  addi      r3, r30, 0
	  addi      r4, r30, 0
	  li        r5, 0x44
	  bl        -0xBE354

	.loc_0x12C:
	  li        r3, 0

	.loc_0x130:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148928
 * Size:	00000C
 */
void BTeki::getGravity()
{
	/*
	.loc_0x0:
	  lwz       r3, 0x2F80(r13)
	  lfs       f1, 0x30(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148934
 * Size:	00002C
 */
TekiStrategy* BTeki::getStrategy()
{
	return tekiMgr->getStrategy(mTekiType);
}

/*
 * --INFO--
 * Address:	80148960
 * Size:	000034
 */
void BTeki::getSeaLevel()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0x94
	  stw       r0, 0x4(r1)
	  li        r4, 0x1
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r5)
	  lfs       f2, 0x8(r5)
	  bl        -0xE0A7C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148994
 * Size:	000044
 */
void BTeki::getYFromSeaLevel()
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r4, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r31)
	  lfs       f2, 0x9C(r31)
	  bl        -0xE0AB4
	  lfs       f0, 0x98(r31)
	  lwz       r0, 0x2C(r1)
	  fsubs     f1, f0, f1
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801489D8
 * Size:	000074
 */
void BTeki::makePositionRoute(Vector3f&, Vector3f&, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  addi      r30, r6, 0
	  stw       r29, 0x1C(r1)
	  addi      r29, r4, 0
	  addi      r4, r5, 0
	  stw       r28, 0x18(r1)
	  addi      r28, r3, 0
	  bl        0xE0
	  lwz       r31, 0x10(r3)
	  addi      r3, r28, 0
	  addi      r4, r29, 0
	  bl        0xD0
	  lwz       r4, 0x10(r3)
	  addi      r3, r28, 0
	  addi      r5, r31, 0
	  addi      r6, r30, 0
	  bl        .loc_0x74
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  lwz       r28, 0x18(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x74:
	*/
}

/*
 * --INFO--
 * Address:	80148A4C
 * Size:	000098
 */
void BTeki::makeWayPointRoute(int, int, bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  li        r7, 0
	  stw       r0, 0x4(r1)
	  addi      r0, r7, 0
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  addi      r29, r5, 0
	  addi      r30, r6, 0
	  li        r4, 0
	  b         .loc_0x40

	.loc_0x30:
	  lwz       r3, 0x450(r27)
	  addi      r4, r4, 0x1
	  stwx      r0, r3, r7
	  addi      r7, r7, 0x4

	.loc_0x40:
	  lwz       r31, 0x348(r27)
	  cmpw      r4, r31
	  blt+      .loc_0x30
	  lwz       r3, 0x302C(r13)
	  lwz       r4, 0x350(r27)
	  bl        -0xA8A90
	  lwz       r4, 0x450(r27)
	  addi      r5, r31, 0
	  addi      r6, r28, 0
	  addi      r7, r29, 0
	  addi      r8, r30, 0
	  bl        -0xA8F6C
	  stw       r3, 0x34C(r27)
	  lwz       r3, 0x34C(r27)
	  lwz       r0, 0x348(r27)
	  cmpw      r3, r0
	  cmpwi     r3, 0
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148AE4
 * Size:	000034
 */
void BTeki::getTargetNearestWayPoint(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r6, r3
	  stw       r0, 0x4(r1)
	  mr        r5, r4
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x350(r6)
	  li        r6, 0
	  lwz       r3, 0x302C(r13)
	  bl        -0xA7A1C
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148B18
 * Size:	000034
 */
void BTeki::getNearestWayPoint()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  addi      r5, r4, 0x94
	  li        r6, 0
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x302C(r13)
	  lwz       r4, 0x350(r4)
	  bl        -0xA7A50
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148B4C
 * Size:	000030
 */
void BTeki::getWayPoint(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r6, r3
	  stw       r0, 0x4(r1)
	  mr        r5, r4
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x302C(r13)
	  lwz       r4, 0x350(r6)
	  bl        -0xA74F0
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148B7C
 * Size:	00002C
 */
void BTeki::getRouteWayPoint(int)
{
	/*
	.loc_0x0:
	  cmpwi     r4, 0
	  blt-      .loc_0x14
	  lwz       r0, 0x348(r3)
	  cmpw      r4, r0
	  ble-      .loc_0x1C

	.loc_0x14:
	  li        r3, 0
	  blr

	.loc_0x1C:
	  lwz       r3, 0x450(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r3, r3, r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148BA8
 * Size:	000040
 */
void BTeki::updateLifeGauge()
{
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r5, r3
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r4, 0x2C4(r3)
	  addi      r3, r5, 0x1E0
	  lfs       f1, 0x58(r5)
	  lwz       r4, 0x84(r4)
	  lwz       r4, 0x4(r4)
	  lwz       r4, 0x0(r4)
	  lfs       f2, 0x0(r4)
	  bl        -0xECB60
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148BE8
 * Size:	00006C
 */
void BTeki::refresh(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r0, 0x31C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x54
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x320(r30)
	  bl        0x2100
	  cmplwi    r3, 0
	  beq-      .loc_0x54
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl

	.loc_0x54:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148C54
 * Size:	000174
 */
void BTeki::drawDefault(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stfd      f31, 0x30(r1)
	  stw       r31, 0x2C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x28(r1)
	  mr        r30, r3
	  lwz       r0, 0x2D0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x40
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x2000
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  lwz       r12, 0x0(r30)
	  fmr       f31, f1
	  mr        r4, r30
	  lwz       r12, 0x60(r12)
	  addi      r3, r1, 0x1C
	  mtlr      r12
	  blrl
	  fmr       f1, f31
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r1, 0x1C
	  bl        -0x107768
	  rlwinm.   r0,r3,0,24,31
	  bne-      .loc_0xB4
	  lwz       r0, 0xC8(r30)
	  oris      r0, r0, 0x8
	  stw       r0, 0xC8(r30)
	  b         .loc_0xC0

	.loc_0xB4:
	  lwz       r0, 0xC8(r30)
	  rlwinm    r0,r0,0,13,11
	  stw       r0, 0xC8(r30)

	.loc_0xC0:
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x100
	  addi      r3, r30, 0x40
	  bl        -0xB4B94
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x100
	  lwz       r0, 0x410(r30)
	  rlwinm.   r0,r0,0,20,20
	  bne-      .loc_0x100
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x40
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl

	.loc_0x100:
	  lwz       r0, 0x410(r30)
	  rlwinm.   r0,r0,0,25,25
	  beq-      .loc_0x118
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,11,11
	  beq-      .loc_0x130

	.loc_0x118:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x1B0(r12)
	  mtlr      r12
	  blrl

	.loc_0x130:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x158
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  mr        r4, r31
	  lwz       r12, 0x1B4(r12)
	  mtlr      r12
	  blrl

	.loc_0x158:
	  lwz       r0, 0x3C(r1)
	  lfd       f31, 0x30(r1)
	  lwz       r31, 0x2C(r1)
	  lwz       r30, 0x28(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80148DC8
 * Size:	00023C
 */
void BTeki::drawTekiShape(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xF0(r1)
	  stw       r31, 0xEC(r1)
	  addi      r31, r4, 0
	  stw       r30, 0xE8(r1)
	  mr        r30, r3
	  stw       r29, 0xE4(r1)
	  lwz       r0, 0x410(r3)
	  rlwinm.   r0,r0,0,17,17
	  beq-      .loc_0x220
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x800
	  lwz       r12, 0x1D0(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, -0x58B0(r2)
	  addi      r4, r1, 0x64
	  addi      r3, r1, 0xC8
	  stfs      f0, 0xD0(r1)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xD0(r1)
	  lfs       f0, -0x5880(r2)
	  lfs       f3, -0x930(r13)
	  stfs      f0, 0xD4(r1)
	  lfs       f2, -0x92C(r13)
	  lfs       f1, 0xA0(r30)
	  lfs       f0, -0x928(r13)
	  stfs      f3, 0x64(r1)
	  stfs      f2, 0x68(r1)
	  stfs      f0, 0x6C(r1)
	  bl        -0x1110B4
	  addi      r3, r1, 0xBC
	  bl        -0x2C008
	  addi      r3, r1, 0xC8
	  addi      r4, r1, 0xBC
	  bl        -0x110D64
	  lfs       f1, 0x3A4(r30)
	  addi      r3, r1, 0xC8
	  addi      r4, r1, 0xBC
	  bl        -0x1110D8
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x94
	  addi      r5, r1, 0xC8
	  addi      r6, r30, 0x7C
	  bl        -0x10A188
	  lwz       r3, 0x2E4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x7C
	  addi      r3, r3, 0x1E0
	  bl        -0x10ADCC
	  lwz       r12, 0x3B4(r31)
	  lis       r4, 0x803A
	  mr        r3, r31
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2CC(r30)
	  lwz       r12, 0x30(r3)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2D0(r30)
	  addi      r4, r31, 0
	  addi      r5, r1, 0x7C
	  lwz       r3, 0x0(r3)
	  li        r6, 0
	  bl        -0x113BD8
	  lwz       r3, 0x220(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x140
	  addi      r4, r31, 0
	  li        r5, 0
	  bl        -0xBF418

	.loc_0x140:
	  addi      r3, r30, 0x2D4
	  addi      r4, r31, 0
	  bl        -0xBAD48
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  bne-      .loc_0x220
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r29, 0x20(r3)
	  cmpwi     r29, 0x1
	  bne-      .loc_0x180
	  mr        r3, r31
	  lfs       f1, 0x3C0(r30)
	  bl        -0x11F768

	.loc_0x180:
	  lwz       r3, 0x2C4(r30)
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r3, 0x0(r3)
	  lwz       r0, 0x14(r3)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x1D0
	  lwz       r4, 0x3BC(r30)
	  lis       r0, 0x4330
	  lfd       f1, -0x5878(r2)
	  addi      r3, r30, 0x3E0
	  xoris     r4, r4, 0x8000
	  stw       r4, 0xDC(r1)
	  addi      r4, r1, 0x70
	  stw       r0, 0xD8(r1)
	  lfd       f0, 0xD8(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x70(r1)
	  bl        -0x119EF4
	  b         .loc_0x1DC

	.loc_0x1D0:
	  addi      r3, r30, 0x3E0
	  li        r4, 0
	  bl        -0x119F04

	.loc_0x1DC:
	  lwz       r3, 0x2D0(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  addi      r6, r30, 0x3E0
	  lwz       r3, 0x0(r3)
	  bl        -0x118B4C
	  cmpwi     r29, 0x1
	  bne-      .loc_0x208
	  mr        r3, r31
	  lfs       f1, -0x5880(r2)
	  bl        -0x11F7F0

	.loc_0x208:
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  li        r4, 0x2000
	  lwz       r12, 0x1CC(r12)
	  mtlr      r12
	  blrl

	.loc_0x220:
	  lwz       r0, 0xF4(r1)
	  lwz       r31, 0xEC(r1)
	  lwz       r30, 0xE8(r1)
	  lwz       r29, 0xE4(r1)
	  addi      r1, r1, 0xF0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149004
 * Size:	0000B0
 */
void BTeki::drawTekiDebugInfo(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r4
	  stw       r29, 0x14(r1)
	  mr        r29, r3
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x320(r29)
	  bl        0x1CEC
	  cmplwi    r3, 0
	  addi      r31, r3, 0
	  beq-      .loc_0x94
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  mr        r31, r0
	  addi      r4, r29, 0
	  lwz       r12, 0x1C(r12)
	  addi      r5, r30, 0
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x3B4(r30)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x94:
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
 * Address:	801490B4
 * Size:	0002C0
 */
void BTeki::drawTekiDebugInfoDefault(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x118(r1)
	  stfd      f31, 0x110(r1)
	  addi      r6, r1, 0xDC
	  stfd      f30, 0x108(r1)
	  stmw      r26, 0xF0(r1)
	  li        r27, 0
	  mr        r30, r3
	  addi      r31, r30, 0x94
	  li        r28, 0xFF
	  addi      r29, r4, 0
	  mr        r5, r31
	  stb       r27, 0xDC(r1)
	  stb       r27, 0xDD(r1)
	  stb       r28, 0xDE(r1)
	  stb       r28, 0xDF(r1)
	  lwz       r7, 0x2C4(r30)
	  lwz       r7, 0x84(r7)
	  lwz       r7, 0x4(r7)
	  lwz       r7, 0x0(r7)
	  lfs       f1, 0x18(r7)
	  bl        .loc_0x2C0
	  stb       r28, 0xD8(r1)
	  addi      r26, r1, 0xD8
	  li        r4, 0
	  stb       r28, 0xD9(r1)
	  stb       r27, 0xDA(r1)
	  stb       r28, 0xDB(r1)
	  lwz       r3, 0x2C8(r30)
	  lwz       r3, 0x34(r3)
	  bl        -0x25F20
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x25F34
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0x8
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x26C88
	  fmuls     f0, f30, f31
	  lwz       r12, 0x0(r30)
	  mr        r3, r30
	  lwz       r12, 0x188(r12)
	  fmuls     f30, f1, f0
	  mtlr      r12
	  blrl
	  fadds     f1, f1, f30
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  addi      r5, r31, 0
	  addi      r6, r26, 0
	  bl        .loc_0x2C0
	  addi      r3, r1, 0xE0
	  bl        -0x2C344
	  lfs       f0, -0x58B0(r2)
	  stfs      f0, 0xCC(r1)
	  stfs      f0, 0xC8(r1)
	  stfs      f0, 0xC4(r1)
	  lfs       f30, 0xA0(r30)
	  fmr       f1, f30
	  bl        0xD29A0
	  stfs      f1, 0xAC(r1)
	  fmr       f1, f30
	  addi      r26, r1, 0xAC
	  bl        0xD2B24
	  stfs      f1, 0xA8(r1)
	  addi      r4, r1, 0xA8
	  addi      r6, r26, 0
	  addi      r3, r1, 0xC4
	  subi      r5, r13, 0x9D8
	  bl        -0xEBB50
	  addi      r3, r30, 0
	  li        r4, 0
	  bl        -0x2858
	  fmr       f30, f1
	  addi      r3, r30, 0
	  li        r4, 0x1
	  bl        -0x284C
	  fmuls     f31, f1, f30
	  lwz       r3, 0x2C4(r30)
	  li        r4, 0xA
	  bl        -0x2133C
	  mr        r3, r30
	  fmr       f30, f1
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x188(r12)
	  mtlr      r12
	  blrl
	  fmuls     f2, f30, f31
	  lfs       f0, 0xC4(r1)
	  addi      r26, r1, 0xD4
	  li        r4, 0
	  fadds     f1, f1, f2
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC4(r1)
	  lfs       f0, 0xC8(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xC8(r1)
	  lfs       f0, 0xCC(r1)
	  fmuls     f0, f0, f1
	  stfs      f0, 0xCC(r1)
	  lfs       f1, 0x0(r31)
	  lfs       f0, 0xC4(r1)
	  lfs       f4, 0x8(r31)
	  lfs       f3, 0xCC(r1)
	  fadds     f0, f1, f0
	  lfs       f2, 0x4(r31)
	  lfs       f1, 0xC8(r1)
	  fadds     f3, f4, f3
	  stb       r28, 0xD4(r1)
	  fadds     f1, f2, f1
	  stfs      f0, 0xE0(r1)
	  stb       r27, 0xD5(r1)
	  stfs      f1, 0xE4(r1)
	  stb       r27, 0xD6(r1)
	  stfs      f3, 0xE8(r1)
	  stb       r28, 0xD7(r1)
	  lwz       r3, 0x2C8(r30)
	  lwz       r3, 0x34(r3)
	  bl        -0x26090
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x260A4
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0xB
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x26DF8
	  fmuls     f0, f30, f31
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  addi      r6, r26, 0
	  fmuls     f1, f1, f0
	  addi      r5, r1, 0xE0
	  bl        .loc_0x2C0
	  stb       r28, 0xD0(r1)
	  addi      r26, r1, 0xD0
	  li        r4, 0
	  stb       r27, 0xD1(r1)
	  stb       r28, 0xD2(r1)
	  stb       r28, 0xD3(r1)
	  lwz       r3, 0x2C8(r30)
	  lwz       r3, 0x34(r3)
	  bl        -0x260FC
	  lwz       r3, 0x2C4(r30)
	  fmr       f30, f1
	  li        r4, 0x1
	  lwz       r3, 0x84(r3)
	  bl        -0x26110
	  lwz       r3, 0x2C4(r30)
	  fmr       f31, f1
	  li        r4, 0x2D
	  lwz       r3, 0x84(r3)
	  lwz       r3, 0x4(r3)
	  bl        -0x26E64
	  fmuls     f0, f31, f30
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  addi      r5, r31, 0
	  fmuls     f1, f1, f0
	  addi      r6, r26, 0
	  bl        .loc_0x2C0
	  lmw       r26, 0xF0(r1)
	  lwz       r0, 0x11C(r1)
	  lfd       f31, 0x110(r1)
	  lfd       f30, 0x108(r1)
	  addi      r1, r1, 0x118
	  mtlr      r0
	  blr

	.loc_0x2C0:
	*/
}

/*
 * --INFO--
 * Address:	80149374
 * Size:	0000F8
 */
void BTeki::drawRange(Graphics&, Vector3f&, f32, Colour&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD8(r1)
	  stfd      f31, 0xD0(r1)
	  fmr       f31, f1
	  addi      r0, r1, 0x1C
	  stw       r31, 0xCC(r1)
	  mr        r31, r6
	  addi      r3, r1, 0x28
	  stw       r30, 0xC8(r1)
	  mr        r30, r5
	  addi      r5, r1, 0x34
	  stw       r29, 0xC4(r1)
	  addi      r29, r4, 0
	  mr        r4, r5
	  lfs       f2, -0x90C(r13)
	  mr        r5, r3
	  lfs       f1, -0x918(r13)
	  mr        r6, r0
	  lfs       f0, -0x924(r13)
	  stfs      f2, 0x1C(r1)
	  addi      r3, r1, 0x80
	  lfs       f2, -0x908(r13)
	  stfs      f1, 0x28(r1)
	  lfs       f1, -0x914(r13)
	  stfs      f0, 0x34(r1)
	  lfs       f0, -0x920(r13)
	  stfs      f2, 0x20(r1)
	  lfs       f2, -0x904(r13)
	  stfs      f1, 0x2C(r1)
	  lfs       f1, -0x910(r13)
	  stfs      f0, 0x38(r1)
	  lfs       f0, -0x91C(r13)
	  stfs      f2, 0x24(r1)
	  stfs      f1, 0x30(r1)
	  stfs      f0, 0x3C(r1)
	  bl        -0x10B310
	  lwz       r3, 0x2E4(r29)
	  addi      r4, r1, 0x80
	  addi      r5, r1, 0x40
	  addi      r3, r3, 0x1E0
	  bl        -0x10B344
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r31, 0
	  li        r5, 0x1
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  fmr       f1, f31
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  addi      r5, r1, 0x40
	  bl        -0x11FFD8
	  lwz       r0, 0xDC(r1)
	  lfd       f31, 0xD0(r1)
	  lwz       r31, 0xCC(r1)
	  lwz       r30, 0xC8(r1)
	  lwz       r29, 0xC4(r1)
	  addi      r1, r1, 0xD8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014946C
 * Size:	0000F4
 */
void BTeki::refresh2d(Graphics&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x48(r1)
	  mr        r30, r3
	  lwz       r0, 0x31C(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0xDC
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x320(r30)
	  bl        0x1B38
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDC
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xDC
	  lwz       r0, 0xC8(r30)
	  rlwinm.   r0,r0,0,12,12
	  beq-      .loc_0x68
	  b         .loc_0xDC

	.loc_0x68:
	  lwz       r0, 0x410(r30)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0xDC
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x3C
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x3C(r1)
	  mr        r4, r31
	  addi      r3, r30, 0x1E0
	  stfs      f0, 0x1E0(r30)
	  lfs       f0, 0x40(r1)
	  stfs      f0, 0x1E4(r30)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x1E8(r30)
	  lwz       r5, 0x2C4(r30)
	  lwz       r5, 0x84(r5)
	  lwz       r5, 0x4(r5)
	  lwz       r5, 0x0(r5)
	  lfs       f0, 0x44(r5)
	  stfs      f0, 0x1F0(r30)
	  lwz       r5, 0x2E4(r31)
	  lfs       f1, -0x586C(r2)
	  lfs       f0, 0x1D0(r5)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x214(r30)
	  bl        -0xED4A0

	.loc_0xDC:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149560
 * Size:	000088
 */
void BTeki::getFreeSlot()
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x736C
	  stw       r0, 0x4(r1)
	  addi      r4, r4, 0x6F74
	  stwu      r1, -0x28(r1)
	  stmw      r27, 0x14(r1)
	  addi      r27, r3, 0
	  lwz       r3, 0x220(r3)
	  bl        -0xBFE70
	  mr        r30, r3
	  bl        -0xC17F8
	  addi      r31, r3, 0
	  li        r29, 0
	  b         .loc_0x68

	.loc_0x38:
	  addi      r3, r30, 0
	  addi      r4, r29, 0
	  bl        -0xC17B4
	  addi      r28, r3, 0
	  addi      r3, r27, 0
	  addi      r4, r28, 0
	  bl        .loc_0x88
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x64
	  mr        r3, r28
	  b         .loc_0x74

	.loc_0x64:
	  addi      r29, r29, 0x1

	.loc_0x68:
	  cmpw      r29, r31
	  blt+      .loc_0x38
	  li        r3, 0

	.loc_0x74:
	  lmw       r27, 0x14(r1)
	  lwz       r0, 0x2C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr

	.loc_0x88:
	*/
}

/*
 * --INFO--
 * Address:	801495E8
 * Size:	000140
 */
bool BTeki::isFreeCollPart(CollPart*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x50(r1)
	  stw       r31, 0x4C(r1)
	  stw       r30, 0x48(r1)
	  stw       r29, 0x44(r1)
	  addi      r29, r4, 0
	  addi      r4, r3, 0
	  addi      r3, r1, 0x30
	  bl        -0xB8988
	  addi      r31, r1, 0x30
	  addi      r3, r31, 0
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3
	  b         .loc_0xC4

	.loc_0x48:
	  cmpwi     r30, -0x1
	  bne-      .loc_0x6C
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  li        r4, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  b         .loc_0x84

	.loc_0x6C:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x84:
	  cmplwi    r3, 0
	  bne-      .loc_0x94
	  li        r3, 0x1
	  b         .loc_0x124

	.loc_0x94:
	  lwz       r0, 0x188(r3)
	  cmplw     r0, r29
	  bne-      .loc_0xA8
	  li        r3, 0
	  b         .loc_0x124

	.loc_0xA8:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r30, r3

	.loc_0xC4:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0xEC
	  li        r0, 0x1
	  b         .loc_0x118

	.loc_0xEC:
	  mr        r3, r31
	  lwz       r12, 0x0(r31)
	  mr        r4, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r3, 0
	  bne-      .loc_0x114
	  li        r0, 0x1
	  b         .loc_0x118

	.loc_0x114:
	  li        r0, 0

	.loc_0x118:
	  rlwinm.   r0,r0,0,24,31
	  beq+      .loc_0x48
	  li        r3, 0x1

	.loc_0x124:
	  lwz       r0, 0x54(r1)
	  lwz       r31, 0x4C(r1)
	  lwz       r30, 0x48(r1)
	  lwz       r29, 0x44(r1)
	  addi      r1, r1, 0x50
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149728
 * Size:	000080
 */
void BTeki::playTableSound(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  mr        r31, r4
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x320(r30)
	  bl        0x1600
	  cmplwi    r3, 0
	  beq-      .loc_0x68
	  lwz       r0, 0x0(r3)
	  cmpw      r31, r0
	  bge-      .loc_0x68
	  lwz       r3, 0x4(r3)
	  rlwinm    r0,r31,2,0,29
	  lwzx      r4, r3, r0
	  cmplwi    r4, 0
	  beq-      .loc_0x68
	  mr        r3, r30
	  lwz       r4, 0x0(r4)
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x1C0(r12)
	  mtlr      r12
	  blrl

	.loc_0x68:
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801497A8
 * Size:	000024
 */
void BTeki::playSound(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2C(r3)
	  bl        -0xA59E8
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801497CC
 * Size:	000024
 */
void BTeki::stopSound(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2C(r3)
	  bl        -0xA5938
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801497F0
 * Size:	000058
 */
void BTeki::createTekiEffect(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r4
	  stw       r30, 0x10(r1)
	  mr        r30, r3
	  lwz       r3, 0x3160(r13)
	  lwz       r4, 0x320(r30)
	  bl        0x1504
	  lwz       r12, 0x0(r3)
	  addi      r4, r30, 0
	  addi      r5, r31, 0
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  lwz       r30, 0x10(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void BTeki::getCameraAnimationMatrix(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void BTeki::outputWorldAnimationMatrix(Matrix4f&, int, Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80149848
 * Size:	0000A8
 */
void BTeki::outputWorldAnimationPosition(Vector3f&, int, Matrix4f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  addi      r31, r5, 0
	  stw       r30, 0xA0(r1)
	  addi      r30, r6, 0
	  stw       r29, 0x9C(r1)
	  addi      r29, r4, 0
	  stw       r28, 0x98(r1)
	  addi      r28, r3, 0
	  addi      r3, r1, 0x58
	  bl        -0x2DB80
	  lwz       r3, 0x2D0(r28)
	  mr        r4, r31
	  lwz       r3, 0x0(r3)
	  bl        -0x1148A0
	  addi      r31, r3, 0
	  addi      r3, r1, 0x18
	  bl        -0x2DB9C
	  addi      r3, r1, 0x18
	  addi      r4, r31, 0
	  bl        -0x2DB28
	  addi      r3, r1, 0x18
	  li        r4, 0x3
	  bl        -0x2D984
	  addi      r3, r30, 0
	  addi      r4, r1, 0x18
	  addi      r5, r1, 0x58
	  bl        -0x10B7E8
	  addi      r5, r29, 0
	  addi      r3, r1, 0x58
	  li        r4, 0x3
	  bl        -0x2D9C8
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  lwz       r28, 0x98(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801498F0
 * Size:	000044
 */
void BTeki::getPositionMapCode(Vector3f&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r4)
	  lfs       f2, 0x8(r4)
	  li        r4, 0x1
	  bl        -0xE1734
	  cmplwi    r3, 0
	  bne-      .loc_0x30
	  li        r3, -0x1
	  b         .loc_0x34

	.loc_0x30:
	  bl        -0x338A0

	.loc_0x34:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149934
 * Size:	000048
 */
void BTeki::getPositionMapCode()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0x94
	  stw       r0, 0x4(r1)
	  li        r4, 0x1
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r5)
	  lfs       f2, 0x8(r5)
	  bl        -0xE177C
	  cmplwi    r3, 0
	  bne-      .loc_0x34
	  li        r3, -0x1
	  b         .loc_0x38

	.loc_0x34:
	  bl        -0x338E8

	.loc_0x38:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8014997C
 * Size:	00005C
 */
bool BTeki::inWaterTeki()
{
	/*
	.loc_0x0:
	  mflr      r0
	  addi      r5, r3, 0x94
	  stw       r0, 0x4(r1)
	  li        r4, 0x1
	  stwu      r1, -0x8(r1)
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x0(r5)
	  lfs       f2, 0x8(r5)
	  bl        -0xE17C4
	  cmplwi    r3, 0
	  bne-      .loc_0x34
	  li        r3, -0x1
	  b         .loc_0x38

	.loc_0x34:
	  bl        -0x33930

	.loc_0x38:
	  cmpwi     r3, 0x5
	  bne-      .loc_0x48
	  li        r3, 0x1
	  b         .loc_0x4C

	.loc_0x48:
	  li        r3, 0

	.loc_0x4C:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801499D8
 * Size:	000020
 */
void BTeki::moveNestPosition()
{
	/*
	.loc_0x0:
	  lwz       r5, 0x2C8(r3)
	  lwz       r4, 0x10(r5)
	  lwz       r0, 0x14(r5)
	  stw       r4, 0x94(r3)
	  stw       r0, 0x98(r3)
	  lwz       r0, 0x18(r5)
	  stw       r0, 0x9C(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801499F8
 * Size:	000024
 */
void BTeki::startParticleGenerator(int)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x3D8(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r3, r3, r0
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  rlwinm    r0,r0,0,29,27
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149A1C
 * Size:	000024
 */
void BTeki::stopParticleGenerator(int)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x3D8(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r3, r3, r0
	  cmplwi    r3, 0
	  beqlr-
	  lwz       r0, 0x80(r3)
	  ori       r0, r0, 0x8
	  stw       r0, 0x80(r3)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149A40
 * Size:	000030
 */
void BTeki::setParticleGeneratorPosition(int, Vector3f&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x3D8(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r4, r3, r0
	  cmplwi    r4, 0
	  beqlr-
	  lwz       r3, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r3, 0xC(r4)
	  stw       r0, 0x10(r4)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0x14(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149A70
 * Size:	000030
 */
void BTeki::setParticleGeneratorDirection(int, Vector3f&)
{
	/*
	.loc_0x0:
	  lwz       r3, 0x3D8(r3)
	  rlwinm    r0,r4,2,0,29
	  lwzx      r4, r3, r0
	  cmplwi    r4, 0
	  beqlr-
	  lwz       r3, 0x0(r5)
	  lwz       r0, 0x4(r5)
	  stw       r3, 0xA0(r4)
	  stw       r0, 0xA4(r4)
	  lwz       r0, 0x8(r5)
	  stw       r0, 0xA8(r4)
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80149AA0
 * Size:	0000E0
 */
void BTeki::calcCollisionDistance(Creature&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x58(r1)
	  stfd      f31, 0x50(r1)
	  stfd      f30, 0x48(r1)
	  stw       r31, 0x44(r1)
	  mr        r31, r4
	  stw       r30, 0x40(r1)
	  addi      r30, r3, 0
	  addi      r3, r1, 0x10
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r31
	  lwz       r12, 0x0(r31)
	  addi      r3, r1, 0x1C
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x28
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r4, r30
	  lwz       r12, 0x0(r30)
	  addi      r3, r1, 0x34
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  lfs       f1, 0x34(r1)
	  lfs       f2, 0x30(r1)
	  lfs       f3, 0x1C(r1)
	  lfs       f4, 0x18(r1)
	  bl        -0x111508
	  fmr       f30, f1
	  mr        r3, r30
	  bl        .loc_0xE0
	  mr        r3, r31
	  fmr       f31, f1
	  lwz       r12, 0x0(r31)
	  lwz       r12, 0x5C(r12)
	  mtlr      r12
	  blrl
	  fsubs     f0, f30, f1
	  lwz       r0, 0x5C(r1)
	  lfd       f30, 0x48(r1)
	  lwz       r31, 0x44(r1)
	  fsubs     f1, f0, f31
	  lfd       f31, 0x50(r1)
	  lwz       r30, 0x40(r1)
	  addi      r1, r1, 0x58
	  mtlr      r0
	  blr

	.loc_0xE0:
	*/
}

/*
 * --INFO--
 * Address:	80149B80
 * Size:	00002C
 */
void BTeki::getCollisionSize()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x5C(r12)
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
 * Address:	........
 * Size:	000038
 */
void BTeki::getCollisionCenter()
{
	// UNUSED FUNCTION
}
