#include "GemItem.h"
#include "DebugLog.h"
#include "BaseInf.h"
#include "Stickers.h"
#include "EffectMgr.h"

// theres a lot more to this
int table[16] = { 0, 1, 2, 3 };

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
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
bool GemItem::ignoreAtari(Creature*)
{
	if (getStickObject()) {
		return true;
	}

	if (mObjType == OBJTYPE_NULL12 && _3C8) {
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void GemItem::setAtariFree()
{
	_3C8 = true;
	playEventSound(this, SE_PELLET_BORN);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void GemItem::bounceCallback()
{
	if (_3C8) {
		effectMgr->create(EffectMgr::EFF_BigDustRing, mPosition, nullptr, nullptr);
	}
	_3C8 = false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000108
 */
GemItem::GemItem(CreatureProp* props, int p2, Shape** shapes, Shape**, Shape**, SimpleAI* ai, f32 a1, int, int)
    : ItemCreature(p2, props, shapes[0])
    , mGemCollInfo(0)
{
	mGemType         = p2;
	mColor           = 0;
	mItemShapeObject = itemMgr->getPelletShapeObject(mColor, p2);
	mStateMachine    = ai;
	_3E8             = a1;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void GemItem::initParam(int type)
{
	setColorType(type);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E4390
 * Size:	0000E4
 */
void GemItem::setColorType(int col)
{
	mColor = col;
	if (col >= 3) {
		col = gsys->getRand(1.0f) * 3.0f;
		if (col >= 3) {
			col = 0;
		}
	}
	mColor = col;

	if (mGemType < 0 || mGemType >= 5) {
		ERROR("illegal gem type !\n", mGemType);
		mGemType = 0;
	}
	mItemShapeObject = itemMgr->getPelletShapeObject(mColor, mGemType);

	if (mItemShapeObject) {
		mItemAnimator.init(&mItemShapeObject->mAnimContext, mItemShapeObject->mAnimMgr, itemMgr->mItemMotionTable);
	}

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void GemItem::startAI(int)
{
	mSeContext = &mGemSe;
	mSeContext->setContext(this, 2);
	mCollInfo = &mGemCollInfo;
	mGemCollInfo.initInfo(mItemShapeObject->mShape, mGemColl, nullptr);
	mScale.set(1.0f, 1.0f, 1.0f);
	mRotation.set(1.0f, mDirection, 1.0f);
	resetCreatureFlag(CF_Unk8);
	((SimpleAI*)mStateMachine)->start(this, 0);
	_3D9 = false;
	_3D8 = false;
	playSound(0);
	// v func
	_3CC = 0;
	_3C8 = 0;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000278
 */
void GemItem::update()
{
	// a lot of this is just estimating based on the dll

	if (_3D8) {
		updateLiftup();
	}
	f32 motionScl;
	if (mColor == 1 && mGemType == 1) {
		motionScl = 1.333333f;
	} else {
		motionScl = 2.666666f;
	}
	ItemCreature::update();
	if (mStickListHead) {
		f32 len = mVelocity.length();
		setMotionSpeed(len * motionScl);
		f32 s = getMotionSpeed();
		if (s > 1000.0f) {
			PRINT("motionSpeed = %f : vel(%.1f %.1f %.1f) : getSpeedScl %.1f motionScl %.1f\n", getMotionSpeed(), mVelocity.x, mVelocity.y,
			      mVelocity.z, motionScl, motionScl);
		}
	} else {
		// some virtual func

		if (mCurrentState->getID()) {
			// some virtual func
			if (_3D9) {
				stopEventSound(this, SE_LIFT_TRY);
				stopEventSound(this, SE_LIFT_MOVE);
				finishPick();
			}
			setCreatureFlag(CF_Unk8); // this is a further inline
			if (isCreatureFlag(CF_IsOnGround)) {
				mVelocity = mVelocity * 1.5f;
			}
		}
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
bool GemItem::reachCapacity()
{
	Stickers stick(this);
	return _3F0 < stick.getCount();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00019C
 */
void GemItem::updateLiftup()
{
	f32 a = _3D4;
	_3D4 += gsys->getFrameTime() * 3.333333f;
	if (_3D4 > _3D0) {
		_3D4 = _3D0;
		_3D8 = false;
	}
	enableGroundOffset(_3D4);
	mPosition.y += _3D4 - a;

	Stickers stick(this);
	Iterator it(nullptr);
	CI_LOOP(it)
	{
		Creature* obj          = *it;
		obj->mAttachPosition.y = obj->mAttachPosition.y - (_3D4 - a);
	}
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void GemItem::startPick(f32 val)
{
	playSound(0);
	getCurrentMotionName();
	setFree(false);
	_3D0        = val;
	_3D4        = 0;
	_3D8        = true;
	mVelocity.y = 0.0f;
	enableGroundOffset(0.0f);
	_3D9 = true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void GemItem::finishPick()
{
	PRINT("FINISH PICK ++++++++++++++\n");
	_3D8 = 0;
	_3D0 = 0;
	disableGroundOffset();
	setFree(true);
	_3D9 = 0;
	resetCreatureFlag(CF_IsFlying);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
f32 GemItem::getSize()
{
	return 41.0f * _3E8 / 0.4f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
f32 GemItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800E4474
 * Size:	0001FC
 */
void GemItem::split()
{
	if (_3E4) {
		int something = table[_3E4];
		if (something > 0) {
			PRINT("gem type %d split !\n", mGemType);
			_3E4 = 0;
			kill(false);
			int objType = mGemType == 1 ? OBJTYPE_Gem1 : OBJTYPE_Gem5;
			f32 yvel    = 240.0f;
			for (int i = 0; i < something; i++) {
				Creature* obj = itemMgr->birth(objType);
				Vector3f pos  = mPosition;
				mPosition.y += 10.0f;
				f32 r    = gsys->getRand(1.0f);
				f32 calc = r * PI + r * PI;
				Vector3f velocity(sinf(calc) * 40.0f, yvel, cosf(calc) * 40.0f);
				if (obj) {
					obj->init(pos);
					obj->startAI(0);
					obj->initParam(mColor);
					obj->mVelocity.x = velocity.x;
					obj->mVelocity.y = velocity.y;
					obj->mVelocity.z = velocity.z;
				}
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stfd      f31, 0x98(r1)
	  stfd      f30, 0x90(r1)
	  stfd      f29, 0x88(r1)
	  stfd      f28, 0x80(r1)
	  stfd      f27, 0x78(r1)
	  stfd      f26, 0x70(r1)
	  stfd      f25, 0x68(r1)
	  stfd      f24, 0x60(r1)
	  stfd      f23, 0x58(r1)
	  stfd      f22, 0x50(r1)
	  stmw      r26, 0x38(r1)
	  mr        r31, r3
	  lbz       r0, 0x3E4(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x1C0
	  lwz       r0, 0x3DC(r31)
	  lis       r3, 0x802C
	  subi      r3, r3, 0x4E50
	  mulli     r0, r0, 0x1C
	  add       r3, r3, r0
	  lwz       r29, 0x14(r3)
	  cmpwi     r29, 0
	  ble-      .loc_0x1C0
	  li        r0, 0
	  stb       r0, 0x3E4(r31)
	  addi      r3, r31, 0
	  li        r4, 0
	  bl        -0x5980C
	  lwz       r0, 0x3DC(r31)
	  cmpwi     r0, 0x1
	  bne-      .loc_0x90
	  li        r28, 0xB
	  b         .loc_0x94

	.loc_0x90:
	  li        r28, 0x7

	.loc_0x94:
	  lfs       f24, -0x6708(r2)
	  li        r27, 0
	  lfd       f25, -0x6710(r2)
	  lis       r30, 0x4330
	  lfs       f26, -0x671C(r2)
	  lfs       f27, -0x6720(r2)
	  lfs       f28, -0x6704(r2)
	  lfs       f29, -0x6700(r2)
	  lfs       f30, -0x66FC(r2)
	  lfs       f31, -0x66F8(r2)
	  b         .loc_0x1B8

	.loc_0xC0:
	  lwz       r3, 0x30AC(r13)
	  mr        r4, r28
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x78(r12)
	  mtlr      r12
	  blrl
	  lfs       f0, 0x94(r31)
	  mr        r26, r3
	  stfs      f0, 0x24(r1)
	  lfs       f0, 0x98(r31)
	  stfs      f0, 0x28(r1)
	  lfs       f0, 0x9C(r31)
	  stfs      f0, 0x2C(r1)
	  lfs       f0, 0x98(r31)
	  fadds     f0, f0, f24
	  stfs      f0, 0x98(r31)
	  bl        0x133AFC
	  xoris     r0, r3, 0x8000
	  stw       r0, 0x34(r1)
	  stw       r30, 0x30(r1)
	  lfd       f0, 0x30(r1)
	  fsubs     f0, f0, f25
	  fdivs     f0, f0, f26
	  fmuls     f0, f27, f0
	  fmuls     f0, f29, f0
	  fmuls     f22, f28, f0
	  fmr       f1, f22
	  bl        0x1375B4
	  fmuls     f23, f30, f1
	  fmr       f1, f22
	  bl        0x13773C
	  fmuls     f0, f30, f1
	  cmplwi    r26, 0
	  stfs      f0, 0x10(r1)
	  stfs      f31, 0x14(r1)
	  stfs      f23, 0x18(r1)
	  beq-      .loc_0x1B4
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  addi      r4, r1, 0x24
	  lwz       r12, 0x28(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r12, 0x0(r26)
	  li        r4, 0
	  lwz       r12, 0x34(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r26
	  lwz       r4, 0x3E0(r31)
	  lwz       r12, 0x0(r26)
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x10(r1)
	  lwz       r0, 0x14(r1)
	  stw       r3, 0x70(r26)
	  stw       r0, 0x74(r26)
	  lwz       r0, 0x18(r1)
	  stw       r0, 0x78(r26)

	.loc_0x1B4:
	  addi      r27, r27, 0x1

	.loc_0x1B8:
	  cmpw      r27, r29
	  blt+      .loc_0xC0

	.loc_0x1C0:
	  lmw       r26, 0x38(r1)
	  lwz       r0, 0xA4(r1)
	  lfd       f31, 0x98(r1)
	  lfd       f30, 0x90(r1)
	  lfd       f29, 0x88(r1)
	  lfd       f28, 0x80(r1)
	  lfd       f27, 0x78(r1)
	  lfd       f26, 0x70(r1)
	  lfd       f25, 0x68(r1)
	  lfd       f24, 0x60(r1)
	  lfd       f23, 0x58(r1)
	  lfd       f22, 0x50(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
void GemItem::refresh(Graphics& gfx)
{
	ItemCreature::refresh(gfx);
	mCollInfo->updateInfo(gfx, false);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void GemItem::doStore(CreatureInf* inf)
{
	inf->mStartAnimId = mGemType;
	inf->mEndAnimId   = mColor;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void GemItem::doRestore(CreatureInf* inf)
{
	mGemType = inf->mStartAnimId;
	mColor   = inf->mEndAnimId;
	initParam(mColor);
	startAI(0);
	PRINT("DO RESTORE END ****\n");
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void GemItem::doKill()
{
	mSeContext->releaseEvent();
	itemMgr->kill(this); // guess here because I cant tell from the dll
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
bool GemItem::isAlive()
{
	return true;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void GemItem::setRouteTracer(RouteTracer*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E4670
 * Size:	00000C
 */
void ItemCreature::finalSetup()
{
	_3C4 = 1;
}
