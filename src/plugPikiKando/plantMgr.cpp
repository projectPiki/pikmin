#include "PlantMgr.h"
#include "Generator.h"
#include "Graphics.h"
#include "gameflow.h"
#include "CreatureProp.h"
#include "Dolphin/os.h"
#include "SoundMgr.h"
#include "MapMgr.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
static void _Error(char* fmt, ...)
{
	OSPanic(__FILE__, __LINE__, fmt, "plantMgr");
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
static void _Print(char*, ...)
{
	// UNUSED FUNCTION
}

PlantMgr* plantMgr;

/*
 * --INFO--
 * Address:	80119D3C
 * Size:	0000C8
 */
Plant::Plant()
    : AICreature(nullptr)
{
	mObjType   = OBJTYPE_Plant;
	mPlantType = PLANT_NULL;
	mCollInfo  = new CollInfo(8);
	mSearchBuffer.init(mPlantSearchData, 3);
}

/*
 * --INFO--
 * Address:	80119E04
 * Size:	000048
 */
void Plant::startMotion(int motionID) { mPlantAnimator.startMotion(PaniMotionInfo(motionID, this)); }

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void Plant::reset(int plantType)
{
	_394                    = 1;
	mObjType                = OBJTYPE_Plant;
	mPlantType              = plantType;
	PlantShapeObject* shape = plantMgr->mPlantShapes[plantType];
	mPlantAnimator.init(&shape->mAnimContext, shape->mAnimMgr, plantMgr->mMotionTable);
	mMotionSpeed = 0.0f;
	mCollInfo->initInfo(shape->mShape, nullptr, nullptr);
	mStateMachine = plantMgr->mAI;
}

/*
 * --INFO--
 * Address:	80119E4C
 * Size:	0000B8
 */
void Plant::startAI(int)
{
	_30C   = 0;
	mapMgr = plantMgr->mMapMgr;
	mProps = plantMgr->mPlantProps;
	startMotion(0);
	mMotionSpeed = 0.0f;
	mPlantAnimator.startMotion(PaniMotionInfo(0));
	mPosition.y = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	plantMgr->mAI->start(this, PlantAI::STATE_Wait);
	if (mPlantType == PLANT_Mizukusa) {
		mMotionSpeed = 30.0f;
	}
}

/*
 * --INFO--
 * Address:	80119F04
 * Size:	000038
 */
void Plant::doAnimation() { mPlantAnimator.animate(mMotionSpeed); }

/*
 * --INFO--
 * Address:	80119F3C
 * Size:	0000A4
 */
void Plant::update()
{
	if (_30C) {
		return;
	}

	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);
	if (mPlantType == PLANT_Hae || mPlantType == PLANT_Mizukusa || !mGrid.aiCulling()) {
		doAnimation();
		plantMgr->mAI->exec(this);
	}
}

/*
 * --INFO--
 * Address:	80119FE0
 * Size:	0003C0
 */
void Plant::refresh(Graphics& gfx)
{
	PlantShapeObject* shape = plantMgr->mPlantShapes[mPlantType];
	if (!mPlantAnimator.mAnimInfo) {
		return;
	}

	if (mCollInfo->hasInfo() && 2.0f * getBoundingSphereRadius() > 0.0f) {
		// what the hell is going on in here

		if (!_394) {
			static_cast<SimpleAI*>(mStateMachine)->start(this, PlantAI::STATE_Wait);
			_30C = 1;
		}
	} else {
		_30C = 0;
		_394 = 0;
		mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
		Matrix4f mtx;
		gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, mtx);

		mPlantAnimator.updateContext();
		shape->mShape->updateAnim(gfx, mtx, nullptr);

		gfx.useMatrix(Matrix4f::ident, 0);
		shape->mShape->drawshape(gfx, *gfx.mCamera, nullptr);
		mCollInfo->updateInfo(gfx, false);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA8(r1)
	  stw       r31, 0xA4(r1)
	  stw       r30, 0xA0(r1)
	  mr        r30, r4
	  stw       r29, 0x9C(r1)
	  mr        r29, r3
	  lwz       r5, 0x3140(r13)
	  lhz       r3, 0x304(r3)
	  lwz       r0, 0x338(r29)
	  lwz       r4, 0x40(r5)
	  rlwinm    r3,r3,2,0,29
	  cmplwi    r0, 0
	  lwzx      r31, r4, r3
	  beq-      .loc_0x3A4
	  lwz       r3, 0x220(r29)
	  bl        -0x904D4
	  rlwinm.   r0,r3,0,24,31
	  beq-      .loc_0x304
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x64(r12)
	  mtlr      r12
	  blrl
	  lfs       f2, -0x6030(r2)
	  lfs       f0, -0x6038(r2)
	  fmuls     f5, f2, f1
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x304
	  lfs       f4, 0x94(r29)
	  fmuls     f1, f2, f5
	  lis       r3, 0x1
	  fadds     f3, f4, f5
	  subi      r0, r3, 0x7FC1
	  fsubs     f2, f4, f5
	  addi      r4, r1, 0x7C
	  stfs      f3, 0x1C(r1)
	  li        r3, 0
	  lfs       f4, 0x98(r29)
	  fadds     f1, f4, f1
	  stfs      f1, 0x20(r1)
	  lfs       f1, 0x9C(r29)
	  stfs      f0, 0x84(r1)
	  fadds     f3, f1, f5
	  fsubs     f1, f1, f5
	  stfs      f0, 0x80(r1)
	  stfs      f2, 0x30(r1)
	  stfs      f0, 0x7C(r1)
	  stfs      f4, 0x34(r1)
	  stfs      f0, 0x90(r1)
	  stfs      f3, 0x24(r1)
	  stfs      f1, 0x38(r1)
	  stfs      f0, 0x8C(r1)
	  stfs      f0, 0x88(r1)
	  lwz       r5, 0x30(r1)
	  lwz       r6, 0x34(r1)
	  stw       r5, 0x7C(r1)
	  lwz       r5, 0x38(r1)
	  stw       r6, 0x80(r1)
	  lwz       r6, 0x1C(r1)
	  stw       r5, 0x84(r1)
	  lwz       r5, 0x20(r1)
	  stw       r6, 0x88(r1)
	  stw       r5, 0x8C(r1)
	  lwz       r5, 0x24(r1)
	  stw       r5, 0x90(r1)
	  lwz       r5, 0x2E4(r30)
	  lwz       r7, 0x4(r5)
	  addi      r6, r5, 0
	  cmpwi     r7, 0
	  mtctr     r7
	  ble-      .loc_0x2D4

	.loc_0x124:
	  lwz       r7, 0x114(r6)
	  lbz       r8, 0x28(r7)
	  cmplwi    r8, 0
	  beq-      .loc_0x2C8
	  li        r8, 0x1
	  slw       r8, r8, r3
	  and.      r9, r0, r8
	  beq-      .loc_0x2C8
	  lbz       r9, 0x154(r5)
	  cmplwi    r9, 0
	  beq-      .loc_0x220
	  lwz       r10, 0x1C(r7)
	  lwz       r9, 0x20(r7)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x24(r7)
	  rlwinm    r9,r9,2,0,29
	  lfs       f6, 0x158(r5)
	  lfsx      f2, r4, r10
	  rlwinm    r10,r11,2,0,29
	  lfs       f4, 0x15C(r5)
	  lfsx      f1, r4, r9
	  fadds     f2, f6, f2
	  lfs       f7, 0x0(r7)
	  fadds     f1, f4, f1
	  lfs       f5, 0x4(r7)
	  lfs       f8, 0x160(r5)
	  lfsx      f3, r4, r10
	  fmuls     f2, f7, f2
	  fmuls     f1, f5, f1
	  lfs       f9, 0x8(r7)
	  fadds     f3, f8, f3
	  lfs       f10, 0xC(r7)
	  fadds     f1, f2, f1
	  fmuls     f2, f9, f3
	  fadds     f1, f2, f1
	  fsubs     f1, f1, f10
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1C4
	  li        r0, 0
	  b         .loc_0x2D4

	.loc_0x1C4:
	  lwz       r10, 0x10(r7)
	  lwz       r9, 0x14(r7)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x18(r7)
	  rlwinm    r7,r9,2,0,29
	  lfsx      f2, r4, r10
	  lfsx      f1, r4, r7
	  rlwinm    r7,r11,2,0,29
	  fadds     f2, f6, f2
	  lfsx      f3, r4, r7
	  fadds     f1, f4, f1
	  fadds     f3, f8, f3
	  fmuls     f2, f7, f2
	  fmuls     f1, f5, f1
	  fmuls     f3, f9, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f1, f1, f10
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2C8
	  andc      r0, r0, r8
	  b         .loc_0x2C8

	.loc_0x220:
	  lwz       r10, 0x1C(r7)
	  lwz       r9, 0x20(r7)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x24(r7)
	  rlwinm    r9,r9,2,0,29
	  lfs       f5, 0x0(r7)
	  lfsx      f2, r4, r10
	  rlwinm    r10,r11,2,0,29
	  lfs       f4, 0x4(r7)
	  lfsx      f1, r4, r9
	  fmuls     f2, f5, f2
	  lfs       f6, 0x8(r7)
	  fmuls     f1, f4, f1
	  lfsx      f3, r4, r10
	  lfs       f7, 0xC(r7)
	  fmuls     f3, f6, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f1, f1, f7
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x27C
	  li        r0, 0
	  b         .loc_0x2D4

	.loc_0x27C:
	  lwz       r10, 0x10(r7)
	  lwz       r9, 0x14(r7)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x18(r7)
	  rlwinm    r7,r9,2,0,29
	  lfsx      f2, r4, r10
	  lfsx      f1, r4, r7
	  rlwinm    r7,r11,2,0,29
	  fmuls     f2, f5, f2
	  lfsx      f3, r4, r7
	  fmuls     f1, f4, f1
	  fmuls     f3, f6, f3
	  fadds     f1, f2, f1
	  fadds     f1, f3, f1
	  fsubs     f1, f1, f7
	  fcmpo     cr0, f1, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2C8
	  andc      r0, r0, r8

	.loc_0x2C8:
	  addi      r6, r6, 0x4
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0x124

	.loc_0x2D4:
	  cmpwi     r0, 0
	  bne-      .loc_0x304
	  lbz       r0, 0x394(r29)
	  cmplwi    r0, 0
	  bne-      .loc_0x304
	  lwz       r3, 0x2E8(r29)
	  addi      r4, r29, 0
	  li        r5, 0
	  bl        -0x9CB7C
	  li        r0, 0x1
	  stb       r0, 0x30C(r29)
	  b         .loc_0x3A4

	.loc_0x304:
	  li        r0, 0
	  stb       r0, 0x30C(r29)
	  addi      r3, r29, 0x228
	  addi      r4, r29, 0x7C
	  stb       r0, 0x394(r29)
	  addi      r5, r29, 0x88
	  addi      r6, r29, 0x94
	  bl        -0xDC20C
	  lwz       r3, 0x2E4(r30)
	  addi      r4, r29, 0x228
	  addi      r5, r1, 0x3C
	  addi      r3, r3, 0x1E0
	  bl        -0xDC240
	  addi      r3, r29, 0x310
	  lwz       r12, 0x340(r29)
	  lwz       r12, 0x18(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  addi      r4, r30, 0
	  addi      r5, r1, 0x3C
	  li        r6, 0
	  bl        -0xE5028
	  lwz       r12, 0x3B4(r30)
	  lis       r4, 0x803A
	  mr        r3, r30
	  lwz       r12, 0x74(r12)
	  subi      r4, r4, 0x77C0
	  li        r5, 0
	  mtlr      r12
	  blrl
	  lwz       r3, 0x0(r31)
	  mr        r4, r30
	  lwz       r5, 0x2E4(r30)
	  li        r6, 0
	  bl        -0xE9F04
	  lwz       r3, 0x220(r29)
	  addi      r4, r30, 0
	  li        r5, 0
	  bl        -0x90894

	.loc_0x3A4:
	  lwz       r0, 0xAC(r1)
	  lwz       r31, 0xA4(r1)
	  lwz       r30, 0xA0(r1)
	  lwz       r29, 0x9C(r1)
	  addi      r1, r1, 0xA8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011A3A0
 * Size:	000004
 */
void Plant::doKill() { }

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
PlantAI::PlantAI()
{
	OpponentMove* oppMove = new OpponentMove();
	setup(STATE_COUNT);
	addState(STATE_Wait, -1, new WaitInit(), nullptr, nullptr);
	addState(STATE_Touch, -1, new TouchInit(), nullptr, nullptr);
	addArrow(STATE_Wait, saiCollideEvent, STATE_Touch)->mCondition.add(oppMove);
	addArrow(STATE_Touch, saiMotionDoneEvent, STATE_Wait);
}

/*
 * --INFO--
 * Address:	8011A3A4
 * Size:	0000AC
 */
bool PlantAI::OpponentMove::satisfy(AICreature* plant)
{
	// this stops inlining if you do it directly for some reason, but goes weird otherwise.
	Vector3f* vec = &plant->_2BC->_70;
	f32 dist      = vec->length();
	if (dist > 40.0f) {
		return true;
	}

	return false;
	/*
	.loc_0x0:
	  stwu      r1, -0x20(r1)
	  lwz       r3, 0x2BC(r4)
	  lfs       f0, -0x6038(r2)
	  lfs       f2, 0x70(r3)
	  lfs       f1, 0x74(r3)
	  fmuls     f2, f2, f2
	  lfs       f3, 0x78(r3)
	  fmuls     f1, f1, f1
	  fmuls     f3, f3, f3
	  fadds     f1, f2, f1
	  fadds     f4, f3, f1
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x8C
	  fsqrte    f1, f4
	  lfd       f3, -0x6028(r2)
	  lfd       f2, -0x6020(r2)
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
	  stfs      f0, 0x14(r1)
	  lfs       f4, 0x14(r1)

	.loc_0x8C:
	  lfs       f0, -0x6018(r2)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0xA0
	  li        r3, 0x1
	  b         .loc_0xA4

	.loc_0xA0:
	  li        r3, 0

	.loc_0xA4:
	  addi      r1, r1, 0x20
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011A450
 * Size:	000094
 */
void PlantAI::WaitInit::act(AICreature* plant)
{
	u32 badCompiler;

	if (static_cast<Plant*>(plant)->mPlantType == PLANT_Mizukusa) {
		plant->startMotion(0);
		plant->setMotionSpeed(30.0f);
	} else {
		plant->startMotion(0);
		plant->stopMotion();
	}
}

/*
 * --INFO--
 * Address:	8011A4E4
 * Size:	000064
 */
void PlantAI::TouchInit::act(AICreature* plant)
{
	u32 badCompiler;
	if (static_cast<Plant*>(plant)->mPlantType != PLANT_Mizukusa) {
		if (plant->_2BC->mObjType == OBJTYPE_Navi) {
			SeSystem::playPlayerSe(0x135);
		}

		plant->setMotionSpeed(30.0f);
	}
}

/*
 * --INFO--
 * Address:	8011A548
 * Size:	000478
 */
PlantMgr::PlantMgr(MapMgr* mgr)
{
	mMapMgr = mgr;
	gameflow.addGenNode("plantMgr", this);
	mMotionTable = PaniPlantAnimator::createMotionTable();
	mPlantShapes = new PlantShapeObject*[PLANT_COUNT];
	for (int i = PLANT_START; i < PLANT_COUNT; i++) {
		mPlantShapes[i] = nullptr;
	}

	mAI         = new PlantAI();
	mPlantProps = new CreatureProp();

	mAnimFrameCacher = new AnimFrameCacher(1000);
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x802C
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stmw      r25, 0x84(r1)
	  addi      r27, r4, 0
	  li        r30, 0
	  addi      r29, r5, 0x38A8
	  subi      r4, r13, 0x1F28
	  stw       r3, 0x8(r1)
	  lis       r3, 0x802B
	  subi      r0, r3, 0x2374
	  lwz       r28, 0x8(r1)
	  stw       r28, 0x7C(r1)
	  stw       r0, 0x0(r28)
	  lwz       r31, 0x7C(r1)
	  stw       r30, 0x4(r31)
	  addi      r3, r31, 0x8
	  bl        -0xC78EC
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4F80
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  lis       r3, 0x802C
	  stw       r0, 0x8(r31)
	  subi      r3, r3, 0x51A8
	  lis       r4, 0x8022
	  stw       r3, 0x0(r31)
	  addi      r0, r3, 0x18
	  lis       r3, 0x8022
	  stw       r0, 0x8(r31)
	  addi      r25, r4, 0x738C
	  addi      r26, r3, 0x737C
	  stw       r25, 0x28(r31)
	  addi      r3, r31, 0x28
	  subi      r4, r13, 0x1F20
	  stw       r26, 0x28(r31)
	  stw       r30, 0x38(r31)
	  stw       r30, 0x34(r31)
	  stw       r30, 0x30(r31)
	  bl        -0xF5714
	  lis       r3, 0x802C
	  subi      r0, r3, 0x102C
	  stw       r0, 0x28(r31)
	  lis       r3, 0x802C
	  addi      r4, r3, 0x3B08
	  stw       r30, 0x3C(r31)
	  addi      r0, r4, 0x18
	  addi      r3, r28, 0x4C
	  stw       r4, 0x0(r28)
	  addi      r4, r29, 0x1C
	  stw       r0, 0x8(r28)
	  stw       r25, 0x4C(r28)
	  stw       r26, 0x4C(r28)
	  stw       r30, 0x5C(r28)
	  stw       r30, 0x58(r28)
	  stw       r30, 0x54(r28)
	  bl        -0xF5758
	  lis       r3, 0x802C
	  addi      r0, r3, 0x3C00
	  stw       r0, 0x4C(r28)
	  addi      r0, r29, 0x28
	  cmplwi    r28, 0
	  stw       r30, 0x5C(r28)
	  addi      r5, r28, 0
	  stw       r30, 0x58(r28)
	  stw       r30, 0x54(r28)
	  stw       r0, 0x50(r28)
	  stw       r27, 0x48(r28)
	  beq-      .loc_0x11C
	  addi      r5, r5, 0x8

	.loc_0x11C:
	  lis       r3, 0x803A
	  subi      r3, r3, 0x2848
	  addi      r4, r29, 0x10
	  bl        -0xC7910
	  bl        0xAD4
	  lwz       r27, 0x8(r1)
	  stw       r3, 0x44(r27)
	  li        r3, 0x30
	  bl        -0xD3680
	  stw       r3, 0x40(r27)
	  li        r4, 0
	  li        r6, 0x8
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x0(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x4(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x8(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0xC(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x10(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x14(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x18(r3)
	  lwz       r3, 0x40(r27)
	  stw       r4, 0x1C(r3)
	  b         .loc_0x45C

	.loc_0x190:
	  subfic    r0, r6, 0xC
	  cmpwi     r6, 0xC
	  mtctr     r0
	  bge-      .loc_0x1B4

	.loc_0x1A0:
	  lwz       r3, 0x8(r1)
	  lwz       r3, 0x40(r3)
	  stwx      r4, r3, r5
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0x1A0

	.loc_0x1B4:
	  li        r3, 0x1C
	  bl        -0xD36FC
	  addi      r30, r3, 0
	  mr.       r27, r30
	  beq-      .loc_0x308
	  mr        r3, r27
	  bl        -0x9D230
	  lis       r3, 0x802C
	  addi      r0, r3, 0x3DB0
	  stw       r0, 0x0(r30)
	  li        r3, 0x14
	  bl        -0xD3724
	  addi      r31, r3, 0
	  mr.       r0, r31
	  beq-      .loc_0x214
	  addi      r3, r31, 0
	  addi      r4, r29, 0x1C
	  bl        -0xE5788
	  lis       r3, 0x802B
	  subi      r0, r3, 0x26FC
	  lis       r3, 0x802C
	  stw       r0, 0x0(r31)
	  addi      r0, r3, 0x3D18
	  stw       r0, 0x0(r31)

	.loc_0x214:
	  li        r0, 0x2
	  stw       r0, 0xC(r30)
	  li        r0, 0
	  stw       r0, 0x8(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD3770
	  stw       r3, 0x4(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD3780
	  stw       r3, 0x10(r30)
	  lwz       r0, 0xC(r30)
	  rlwinm    r3,r0,2,0,29
	  bl        -0xD3790
	  stw       r3, 0x14(r30)
	  li        r3, 0x4
	  bl        -0xD379C
	  mr.       r6, r3
	  beq-      .loc_0x27C
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x3CB4
	  stw       r0, 0x0(r3)

	.loc_0x27C:
	  addi      r3, r27, 0
	  li        r4, 0
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x9D260
	  li        r3, 0x4
	  bl        -0xD37DC
	  mr.       r6, r3
	  beq-      .loc_0x2BC
	  lis       r4, 0x802C
	  subi      r0, r4, 0x1C1C
	  lis       r4, 0x802C
	  stw       r0, 0x0(r3)
	  addi      r0, r4, 0x3C88
	  stw       r0, 0x0(r3)

	.loc_0x2BC:
	  addi      r3, r27, 0
	  li        r4, 0x1
	  li        r5, -0x1
	  li        r7, 0
	  li        r8, 0
	  bl        -0x9D2A0
	  lwz       r5, 0x2F40(r13)
	  addi      r3, r27, 0
	  li        r4, 0
	  li        r6, 0x1
	  bl        -0x9D1CC
	  addi      r4, r31, 0
	  addi      r3, r3, 0x20
	  bl        -0xDA260
	  lwz       r5, 0x2F30(r13)
	  addi      r3, r27, 0
	  li        r4, 0x1
	  li        r6, 0
	  bl        -0x9D1EC

	.loc_0x308:
	  lwz       r4, 0x8(r1)
	  li        r3, 0x58
	  stw       r30, 0x64(r4)
	  bl        -0xD3858
	  mr.       r25, r3
	  beq-      .loc_0x42C
	  lis       r3, 0x802B
	  subi      r0, r3, 0x6C8
	  stw       r0, 0x54(r25)
	  li        r0, 0
	  addi      r3, r1, 0x4C
	  stw       r0, 0x0(r25)
	  subi      r4, r13, 0x1F18
	  bl        -0xC9DAC
	  lwz       r0, 0x4C(r1)
	  addi      r5, r1, 0x44
	  addi      r4, r25, 0
	  stw       r0, 0x44(r1)
	  addi      r3, r25, 0x4
	  bl        -0xBBE1C
	  lis       r3, 0x802A
	  addi      r27, r3, 0x6098
	  stw       r27, 0xC(r25)
	  addi      r3, r1, 0x54
	  subi      r4, r13, 0x1F14
	  lfs       f0, -0x6014(r2)
	  stfs      f0, 0x10(r25)
	  bl        -0xC9DE4
	  lwz       r0, 0x54(r1)
	  addi      r5, r1, 0x40
	  addi      r4, r25, 0
	  stw       r0, 0x40(r1)
	  addi      r3, r25, 0x14
	  bl        -0xBBE54
	  stw       r27, 0x1C(r25)
	  addi      r3, r1, 0x5C
	  subi      r4, r13, 0x1F10
	  lfs       f0, -0x6014(r2)
	  stfs      f0, 0x20(r25)
	  bl        -0xC9E14
	  lwz       r0, 0x5C(r1)
	  addi      r5, r1, 0x3C
	  addi      r4, r25, 0
	  stw       r0, 0x3C(r1)
	  addi      r3, r25, 0x24
	  bl        -0xBBE84
	  stw       r27, 0x2C(r25)
	  addi      r3, r1, 0x64
	  subi      r4, r13, 0x1F0C
	  lfs       f0, -0x6010(r2)
	  stfs      f0, 0x30(r25)
	  bl        -0xC9E44
	  lwz       r0, 0x64(r1)
	  addi      r5, r1, 0x38
	  addi      r4, r25, 0
	  stw       r0, 0x38(r1)
	  addi      r3, r25, 0x34
	  bl        -0xBBEB4
	  stw       r27, 0x3C(r25)
	  addi      r3, r1, 0x6C
	  subi      r4, r13, 0x1F08
	  lfs       f0, -0x600C(r2)
	  stfs      f0, 0x40(r25)
	  bl        -0xC9E74
	  lwz       r0, 0x6C(r1)
	  addi      r5, r1, 0x34
	  addi      r4, r25, 0
	  stw       r0, 0x34(r1)
	  addi      r3, r25, 0x44
	  bl        -0xBBEE4
	  stw       r27, 0x4C(r25)
	  lfs       f0, -0x6008(r2)
	  stfs      f0, 0x50(r25)

	.loc_0x42C:
	  lwz       r4, 0x8(r1)
	  li        r3, 0x18
	  stw       r25, 0x68(r4)
	  bl        -0xD397C
	  addi      r25, r3, 0
	  mr.       r3, r25
	  beq-      .loc_0x450
	  li        r4, 0x3E8
	  bl        -0xE589C

	.loc_0x450:
	  lwz       r3, 0x8(r1)
	  stw       r25, 0x6C(r3)
	  b         .loc_0x464

	.loc_0x45C:
	  rlwinm    r5,r6,2,0,29
	  b         .loc_0x190

	.loc_0x464:
	  lmw       r25, 0x84(r1)
	  lwz       r0, 0xA4(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

// see PlantTypes enum for more info on what these are
static char* plantNames[PLANT_COUNT] = {
	"clover",   // 0
	"chidome",  // 1
	"hutaba",   // 2
	"ine",      // 3
	"tanpopo",  // 4
	"ooinu_l",  // 5
	"ooinu_s",  // 6
	"mizukusa", // 7
	"wakame_l", // 8
	"wakame_s", // 9
	"kinokolt", // 10
	"hae",      // 11
};

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
char* PlantMgr::getPlantName(int plantType) { return plantNames[plantType]; }

/*
 * --INFO--
 * Address:	8011A9C0
 * Size:	0000EC
 */
void PlantMgr::initialise()
{
	for (int i = PLANT_START; i < PLANT_COUNT; i++) {
		if (!usePlantType(i)) {
			continue;
		}

		char* name = plantNames[i];
		char shapeFile[256];
		sprintf(shapeFile, "objects/plants/%s.mod", name);

		char unused[256];
		sprintf(unused, "%s", name);

		char plantFileName[256];
		sprintf(plantFileName, "%s.bin", name);

		mPlantShapes[i] = new PlantShapeObject(gameflow.loadShape(shapeFile, true), plantNames[i], plantFileName);
	}
}

/*
 * --INFO--
 * Address:	8011AAAC
 * Size:	0000D8
 */
Plant* PlantMgr::createObject() { return new Plant(); }

/*
 * --INFO--
 * Address:	8011AB84
 * Size:	000030
 */
bool PlantMgr::usePlantType(int type)
{
	FOREACH_NODE(UseNode, mRootUseNode.mChild, node)
	{
		if (node->mPlantType == type) {
			return true;
		}
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void PlantMgr::addUseList(int plantType)
{
	if (!usePlantType(plantType)) {
		UseNode* node    = new UseNode();
		node->mPlantType = plantType;
		mRootUseNode.add(node);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000150
 */
Plant* PlantMgr::birth()
{
	CreatureNode* cnode = new CreatureNode();
	cnode->mCreature    = new Plant();
	mRootNode.add(cnode);
	return static_cast<Plant*>(cnode->mCreature);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011ABB4
 * Size:	000118
 */
PlantShapeObject::PlantShapeObject(Shape* shape, char* plantName, char* fileName)
{
	mShape               = shape;
	mShape->mFrameCacher = plantMgr->mAnimFrameCacher;
	if (plantName) {
		char buf[128];
		sprintf(buf, "objects/plants/%s", fileName);
		mAnimMgr        = new AnimMgr(shape, buf, 0x8000, nullptr);
		mAnimMgr->mName = plantName;
	} else {
		mAnimMgr = new AnimMgr(shape, nullptr, 0, nullptr);
	}

	mShape->overrideAnim(0, &mAnimContext);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
GenObjectPlant::GenObjectPlant()
    : GenObject('plnt', "create Plant")
{
	mPlantType = PLANT_Clover;
}

/*
 * --INFO--
 * Address:	8011ACCC
 * Size:	000078
 */
static GenObject* makeObjectPlant() { return new GenObjectPlant(); }

/*
 * --INFO--
 * Address:	8011AD44
 * Size:	00008C
 */
void GenObjectPlant::initialise()
{
	GenObjectFactory* fact = GenObjectFactory::factory;
	if (fact->mSpawnerCount >= fact->mMaxSpawners) {
		return;
	}

	fact->mSpawnerInfo[fact->mSpawnerCount].mID          = 'plnt';
	fact->mSpawnerInfo[fact->mSpawnerCount].mGenFunction = &makeObjectPlant;
	fact->mSpawnerInfo[fact->mSpawnerCount].mName        = "Generate PLANT";
	fact->mSpawnerInfo[fact->mSpawnerCount].mVersion     = 'v0.0';

	fact->mSpawnerCount++;
}

/*
 * --INFO--
 * Address:	8011ADD0
 * Size:	000040
 */
void GenObjectPlant::doRead(RandomAccessStream& input) { mPlantType = input.readInt(); }

/*
 * --INFO--
 * Address:	8011AE10
 * Size:	0000CC
 */
void GenObjectPlant::updateUseList(Generator* gen, int) { plantMgr->addUseList(mPlantType); }

/*
 * --INFO--
 * Address:	8011AEDC
 * Size:	000190
 */
void* GenObjectPlant::birth(BirthInfo& info)
{
	Plant* plant = plantMgr->birth();
	if (plant) {
		plant->init(info.mPosition);
		plant->mRotation  = info.mRotation;
		plant->mDirection = plant->mRotation.y;
		plant->reset(mPlantType);
		plant->mGenerator = info.mGenerator;
		plant->mHealth    = 1.0f;
		plant->_5C        = plant->mHealth;
		plant->startAI(PlantAI::STATE_Wait);
	}

	return plant;
}

/*
 * --INFO--
 * Address:	8011B06C
 * Size:	00002C
 */
void GenObjectPlant::render(Graphics&, Generator*)
{
	// remnants of some debug thing
	if (plantMgr->usePlantType(mPlantType))
		;
}
