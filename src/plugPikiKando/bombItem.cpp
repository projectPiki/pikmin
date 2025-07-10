#include "BombItem.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "MapCode.h"
#include "MoviePlayer.h"
#include "gameflow.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

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
	Creature* obj = coll.mCollider;
	int state     = getCurrState()->getID();

	if (obj->mObjType != OBJTYPE_Piki && state == 1) {
		if (coll.mColliderPart->getID().mId == 'beat') {
			PRINT("***BOMB COLLIDE WITH KING COLL PART!!!!!!!!!\n");
			C_SAI(this)->start(this, BombAI::BOMB_Mizu);
		} else {
			C_SAI(this)->start(this, BombAI::BOMB_Bomb);
		}
	}
}

/*
 * --INFO--
 * Address:	800EA238
 * Size:	000058
 */
bool BombItem::isVisible()
{
	int state = getCurrState()->getID();

	if (state == BombAI::BOMB_Mizu || state == BombAI::BOMB_Die || state == BombAI::BOMB_Unk1 || state == BombAI::BOMB_Set) {
		return false;
	}

	return true;
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
	int state = getCurrState()->getID();

	if (state == BombAI::BOMB_Mizu || state == BombAI::BOMB_Die || state == BombAI::BOMB_Unk1 || state == BombAI::BOMB_Set) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address:	800EA2F0
 * Size:	0000AC
 */
BombItem::BombItem(CreatureProp* props, ItemShapeObject* shape, SimpleAI* ai)
    : ItemCreature(OBJTYPE_Bomb, props, nullptr)
    , mBombColl(0)
{
	mLifeGauge.mSnapToTargetHealth = true;
	mItemShapeObject               = shape;
	mStateMachine                  = ai;
	mLifeGauge.mRenderStyle        = LifeGauge::Wheel;
}

/*
 * --INFO--
 * Address:	800EA39C
 * Size:	0000E8
 */
void BombItem::startAI(int)
{
	enableFixPos();
	setInsideView();

	mSeContext = &mSound;
	mSeContext->setContext(this, 1);

	mCollInfo = &mBombColl;
	mCollInfo->initInfo(mItemShapeObject->mShape, mCollParts, mCollPartIdList);

	mItemAnimator.startMotion(PaniMotionInfo(0));
	mMotionSpeed = 0.0f;

	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);

	C_SAI(this)->start(this, BombAI::BOMB_Unk0);

	mLifeGauge.mPosition = mPosition;
	mLifeGauge.mOffset.set(0.0f, 20.0f, 0.0f);
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
	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	ItemCreature::update();

	int state = getCurrState()->getID();
	if (state != BombAI::BOMB_Die && state != BombAI::BOMB_Bomb && state != BombAI::BOMB_Mizu && mGroundTriangle
	    && MapCode::getAttribute(mGroundTriangle) == ATTR_Water) {
		PRINT("BOMB WATER START **********\n");
		mStateMachine->transit(this, BombAI::BOMB_Mizu);
	}

	if (state == BombAI::BOMB_Unk1 && mGroundTriangle) {
		C_SAI(this)->start(this, BombAI::BOMB_Bomb);
	}
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
	int state = getCurrState()->getID();

	if (state == 2) {
		mLifeGauge.updValue(mCurrentItemHealth, mMaxItemHealth);
		mLifeGauge.mPosition = mPosition;
		mLifeGauge.mScale    = 5000.0f / gfx.mCamera->mNear;
		mLifeGauge.refresh(gfx);
	}
}

/*
 * --INFO--
 * Address:	800EA608
 * Size:	0000A8
 */
void BombItem::refresh(Graphics& gfx)
{
	if (gameflow.mMoviePlayer->mIsActive) {
		return;
	}

	int state = getCurrState()->getID();
	ItemCreature::refresh(gfx);

	// welcome to DLL heaven/hell.
	// why is this called here and never used?
	// WHY does it fix the issues with the updateInfo call?
	// I hate this compiler SO much.
	aiCullable();

	mCollInfo->updateInfo(gfx, false);
	if (state == BombAI::BOMB_Set) {
		renderTimer(gfx);
	}
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
	int state = getCurrState()->getID();
	PRINT("****** BOMB %x \n", this);
	PRINT("state = %d\n", state);
	PRINT("alive = %s visible = %s\n", isAlive() ? "true" : "false", isVisible() ? "true" : "false");
}
