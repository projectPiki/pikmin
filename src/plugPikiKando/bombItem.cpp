#include "BombItem.h"
#include "DebugLog.h"
#include "gameflow.h"
#include "MapCode.h"
#include "MoviePlayer.h"
#include "Graphics.h"

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
DEFINE_PRINT("bombItem")

/*
 * --INFO--
 * Address:	800EA190
 * Size:	0000A8
 */
void BombItem::collisionCallback(CollEvent& coll)
{
	Creature* obj             = coll.mCollider;
	AState<AICreature>* state = getCurrState();
	if (obj->mObjType != OBJTYPE_Piki && state->mStateID == 1) {
		if (coll.mColliderPart->getID().mId == 'beat') {
			((SimpleAI*)mStateMachine)->start(this, 4);
		} else {
			((SimpleAI*)mStateMachine)->start(this, 3);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stw       r31, 0x34(r1)
	  stw       r30, 0x30(r1)
	  mr        r30, r4
	  stw       r29, 0x2C(r1)
	  mr        r29, r3
	  lwz       r12, 0x0(r29)
	  lwz       r31, 0x0(r4)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x6C(r31)
	  lwz       r3, 0x4(r3)
	  cmpwi     r0, 0
	  beq-      .loc_0x8C
	  cmpwi     r3, 0x1
	  bne-      .loc_0x8C
	  addi      r3, r1, 0x14
	  lwz       r4, 0x4(r30)
	  bl        -0x62344
	  lwz       r3, 0x14(r1)
	  subis     r0, r3, 0x6265
	  cmplwi    r0, 0x6174
	  bne-      .loc_0x7C
	  lwz       r3, 0x2E8(r29)
	  addi      r4, r29, 0
	  li        r5, 0x4
	  bl        -0x6CAAC
	  b         .loc_0x8C

	.loc_0x7C:
	  lwz       r3, 0x2E8(r29)
	  addi      r4, r29, 0
	  li        r5, 0x3
	  bl        -0x6CAC0

	.loc_0x8C:
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
 * Address:	800EA238
 * Size:	000058
 */
bool BombItem::isVisible()
{
	u32 state = getCurrState()->mStateID;
	if (state == 4 || state == 5 || state - 1 < 2) {
		return false;
	}
	return true;

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x8(r1)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r3)
	  cmpwi     r3, 0x4
	  beq-      .loc_0x3C
	  cmpwi     r3, 0x5
	  beq-      .loc_0x3C
	  subi      r0, r3, 0x1
	  cmplwi    r0, 0x1
	  bgt-      .loc_0x44

	.loc_0x3C:
	  li        r3, 0
	  b         .loc_0x48

	.loc_0x44:
	  li        r3, 0x1

	.loc_0x48:
	  lwz       r0, 0xC(r1)
	  addi      r1, r1, 0x8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EA290
 * Size:	000008
 */
bool BombItem::needShadow()
{
	return false;
}

/*
 * --INFO--
 * Address:	800EA298
 * Size:	000058
 */
bool BombItem::isAlive()
{
	u32 state = getCurrState()->mStateID;
	if (state == 4 || state == 5 || state - 1 < 2) {
		return false;
	}
	return true;

	/*
.loc_0x0:
  mflr      r0
  stw       r0, 0x4(r1)
  stwu      r1, -0x8(r1)
  lwz       r12, 0x0(r3)
  lwz       r12, 0x120(r12)
  mtlr      r12
  blrl
  lwz       r3, 0x4(r3)
  cmpwi     r3, 0x4
  beq-      .loc_0x3C
  cmpwi     r3, 0x5
  beq-      .loc_0x3C
  subi      r0, r3, 0x1
  cmplwi    r0, 0x1
  bgt-      .loc_0x44

.loc_0x3C:
  li        r3, 0
  b         .loc_0x48

.loc_0x44:
  li        r3, 0x1

.loc_0x48:
  lwz       r0, 0xC(r1)
  addi      r1, r1, 0x8
  mtlr      r0
  blr
*/
}

/*
 * --INFO--
 * Address:	800EA2F0
 * Size:	0000AC
 */
BombItem::BombItem(CreatureProp* props, ItemShapeObject* shape, SimpleAI* ai)
    : ItemCreature(14, props, nullptr)
    , mBombColl(0)
{
	mLifeGauge._20   = 1;
	mItemShapeObject = shape;
	mStateMachine    = ai;
	mLifeGauge._1C   = 1;
}

/*
 * --INFO--
 * Address:	800EA39C
 * Size:	0000E8
 */
void BombItem::startAI(int)
{
	mCreatureFlags |= 0x400000;
	mCreatureFlags |= 0x100000;
	mSeContext = &mSound;
	mSeContext->setContext(this, 1);
	mCollInfo = &mBombColl;
	mCollInfo->initInfo(mItemShapeObject->mShape, mCollParts, &_818);
	PaniMotionInfo info(0);
	mItemAnimator.startMotion(info);
	mMotionSpeed = 0.0f;
	mScale.x     = 1.0f;
	mScale.y     = 1.0f;
	mScale.z     = 1.0f;
	((SimpleAI*)mStateMachine)->start(this, 0);
	mLifeGauge.mPosition = mPosition;
	mLifeGauge._0C.set(0.0f, 2.0f, 0.0f);

	/*
	.loc_0x0:
	  mflr      r0
	  li        r5, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  mr        r31, r3
	  addi      r0, r31, 0x3CC
	  lwz       r3, 0xC8(r3)
	  addi      r4, r31, 0
	  oris      r3, r3, 0x40
	  stw       r3, 0xC8(r31)
	  lwz       r3, 0xC8(r31)
	  oris      r3, r3, 0x10
	  stw       r3, 0xC8(r31)
	  stw       r0, 0x2C(r31)
	  lwz       r3, 0x2C(r31)
	  bl        -0x466A8
	  addi      r0, r31, 0x3F4
	  stw       r0, 0x220(r31)
	  addi      r5, r31, 0x408
	  addi      r6, r31, 0x818
	  lwz       r4, 0x3C0(r31)
	  lwz       r3, 0x220(r31)
	  lwz       r4, 0x0(r4)
	  bl        -0x60898
	  addi      r3, r1, 0x10
	  li        r4, 0
	  bl        0x34B50
	  addi      r4, r3, 0
	  addi      r3, r31, 0x36C
	  bl        0x34DAC
	  lfs       f0, -0x65D8(r2)
	  addi      r4, r31, 0
	  li        r5, 0
	  stfs      f0, 0x304(r31)
	  lfs       f0, -0x65D4(r2)
	  stfs      f0, 0x7C(r31)
	  stfs      f0, 0x80(r31)
	  stfs      f0, 0x84(r31)
	  lwz       r3, 0x2E8(r31)
	  bl        -0x6CCE4
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1E0(r31)
	  stw       r0, 0x1E4(r31)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1E8(r31)
	  lfs       f0, -0x34F8(r13)
	  stfs      f0, 0x1EC(r31)
	  lfs       f0, -0x34F4(r13)
	  stfs      f0, 0x1F0(r31)
	  lfs       f0, -0x34F0(r13)
	  stfs      f0, 0x1F4(r31)
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EA484
 * Size:	000008
 */
f32 BombItem::getSize()
{
	return 5.0f;
}

/*
 * --INFO--
 * Address:	800EA48C
 * Size:	000008
 */
f32 BombItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800EA494
 * Size:	0000D8
 */
void BombItem::update()
{
	if (!gameflow.mMoviePlayer->mIsActive) {
		ItemCreature::update();
		int state = getCurrState()->mStateID;
		if (state != 5 && state != 3 && state != 4 && mFloorTri && MapCode::getAttribute(mFloorTri) == ATTR_Water) {
			mStateMachine->transit(this, 4);
		}
		if (state == 1 && mFloorTri) {
			((SimpleAI*)mStateMachine)->start(this, 3);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r4, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r4, r4, 0x2848
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  mr        r30, r3
	  lwz       r4, 0x1DC(r4)
	  lbz       r0, 0x124(r4)
	  cmplwi    r0, 0
	  bne-      .loc_0xC0
	  mr        r3, r30
	  bl        0xB72C
	  mr        r3, r30
	  lwz       r12, 0x0(r30)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0x4(r3)
	  cmpwi     r31, 0x5
	  beq-      .loc_0x9C
	  cmpwi     r31, 0x3
	  beq-      .loc_0x9C
	  cmpwi     r31, 0x4
	  beq-      .loc_0x9C
	  lwz       r3, 0x28C(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x9C
	  bl        0x2BB78
	  cmpwi     r3, 0x5
	  bne-      .loc_0x9C
	  lwz       r3, 0x2E8(r30)
	  addi      r4, r30, 0
	  li        r5, 0x4
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl

	.loc_0x9C:
	  cmpwi     r31, 0x1
	  bne-      .loc_0xC0
	  lwz       r0, 0x28C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0xC0
	  lwz       r3, 0x2E8(r30)
	  addi      r4, r30, 0
	  li        r5, 0x3
	  bl        -0x6CDF8

	.loc_0xC0:
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
 * Address:	800EA56C
 * Size:	000004
 */
void BombItem::renderTimer(Graphics&)
{
}

/*
 * --INFO--
 * Address:	800EA570
 * Size:	000098
 */
void BombItem::refresh2d(Graphics& gfx)
{
	int state = getCurrState()->mStateID;
	if (state == 2) {
		mLifeGauge.updValue(_2D8, _2E0);
		mLifeGauge.mPosition = mPosition;
		mLifeGauge.mScale    = 5000.0f / gfx.mCamera->mNear;
		mLifeGauge.refresh(gfx);
	}
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
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x4(r3)
	  cmpwi     r0, 0x2
	  bne-      .loc_0x80
	  lfs       f1, 0x2D8(r30)
	  addi      r3, r30, 0x1E0
	  lfs       f2, 0x2E0(r30)
	  bl        -0x8E540
	  lwz       r5, 0x94(r30)
	  mr        r4, r31
	  lwz       r0, 0x98(r30)
	  addi      r3, r30, 0x1E0
	  stw       r5, 0x1E0(r30)
	  stw       r0, 0x1E4(r30)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x1E8(r30)
	  lwz       r5, 0x2E4(r31)
	  lfs       f1, -0x65CC(r2)
	  lfs       f0, 0x1D0(r5)
	  fdivs     f0, f1, f0
	  stfs      f0, 0x214(r30)
	  bl        -0x8E548

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
 * Address:	800EA608
 * Size:	0000A8
 */
void BombItem::refresh(Graphics& gfx)
{
	if (!gameflow.mMoviePlayer->mIsActive) {
		int state = getCurrState()->mStateID;
		ItemCreature::refresh(gfx);
		mCollInfo->updateInfo(gfx, false);
		if (state == 2) {
			renderTimer(gfx);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r5, 0x803A
	  stw       r0, 0x4(r1)
	  subi      r5, r5, 0x2848
	  stwu      r1, -0x30(r1)
	  stw       r31, 0x2C(r1)
	  stw       r30, 0x28(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x24(r1)
	  addi      r29, r3, 0
	  lwz       r5, 0x1DC(r5)
	  lbz       r0, 0x124(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x8C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  lwz       r12, 0x120(r12)
	  mtlr      r12
	  blrl
	  lwz       r31, 0x4(r3)
	  addi      r3, r29, 0
	  addi      r4, r30, 0
	  bl        0xB618
	  lwz       r3, 0x220(r29)
	  mr        r4, r30
	  li        r5, 0
	  bl        -0x60B84
	  cmpwi     r31, 0x2
	  bne-      .loc_0x8C
	  mr        r3, r29
	  lwz       r12, 0x0(r29)
	  mr        r4, r30
	  lwz       r12, 0x15C(r12)
	  mtlr      r12
	  blrl

	.loc_0x8C:
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
 * Address:	800EA6B0
 * Size:	000004
 */
void BombItem::renderBlast(Graphics&)
{
}

/*
 * --INFO--
 * Address:	800EA6B4
 * Size:	000060
 */
void BombItem::dump()
{
	getCurrState();
	isAlive();
	isVisible();
}
