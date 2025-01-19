#include "SeedItem.h"
#include "DebugLog.h"
#include "ItemMgr.h"
#include "NaviMgr.h"
#include "AIConstant.h"
#include "Graphics.h"
#include "Interactions.h"

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
DEFINE_PRINT("seedItem")

/*
 * --INFO--
 * Address:	800EDDD0
 * Size:	0000DC
 */
SeedItem::SeedItem(CreatureProp* props, Shape** shapes)
    : Creature(props)
{
	mShape        = shapes[0];
	mShape2       = shapes[1];
	mCurrentShape = mShape;

	f32 scale = 0.2f;
	mScale.set(scale, scale, scale);
	_68 = 4;
	resetCreatureFlag(CF_Unk10);
	setCreatureFlag(CF_Unk1 | CF_Unk5);
	mSearchBuffer.init(mSearch, 3);
	mObjType = OBJTYPE_Seed;
	mStateId = 3;
}

/*
 * --INFO--
 * Address:	800EDEAC
 * Size:	000008
 */
f32 SeedItem::getSize()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800EDEB4
 * Size:	000044
 */
void SeedItem::init(Vector3f& pos)
{
	Creature::init(pos);
	mSearchBuffer.init(mSearch, 3);
	mStateId = 3;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void SeedItem::startBirth()
{
	mStateId      = 0;
	mCurrentShape = mShape;
	resetCreatureFlag(CF_GravityEnabled);
	setCreatureFlag(CF_Unk5);
	mVelocity.y = 10.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void SeedItem::startSown()
{
	mStateId      = 1;
	_2E0          = 200.0f;
	mCurrentShape = mShape2;
	setCreatureFlag(CF_GravityEnabled);
	resetCreatureFlag(CF_Unk5);
}

/*
 * --INFO--
 * Address:	800EDEF8
 * Size:	000014
 */
bool SeedItem::isVisible()
{
	return mStateId != 2;
}

/*
 * --INFO--
 * Address:	800EDF0C
 * Size:	000008
 */
bool SeedItem::isAtari()
{
	return false;
}

/*
 * --INFO--
 * Address:	800EDF14
 * Size:	00003C
 */
void SeedItem::doKill()
{
	PRINT("seed is killed ?\n");
	mStateId = 2;
	itemMgr->kill(this);
	/*
	.loc_0x0:
	  mflr      r0
	  mr        r4, r3
	  stw       r0, 0x4(r1)
	  li        r0, 0x2
	  stwu      r1, -0x8(r1)
	  stw       r0, 0x2B8(r3)
	  lwz       r3, 0x30AC(r13)
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x7C(r12)
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
 * Address:	800EDF50
 * Size:	00023C
 */
void SeedItem::update()
{
	if (mStateId == 0) {
		Navi* navi    = naviMgr->getNavi();
		Vector3f diff = navi->mPosition - mPosition;
		diff.y        = 0.0f;
		f32 dist      = diff.length();

		f32 mult, vel, y;
		if (dist < 20.0f) {
			y    = 30.0f;
			vel  = 200.0f;
			mult = 1.0f;
		} else if (dist < 200.0f) {
			y    = ((dist - 20.0f) / 180.0f) * 70.0f + 30.0f;
			vel  = ((dist - 20.0f) / 180.0f) * 150.0f + 200.0f;
			mult = ((dist - 20.0f) / 180.0f) * 5.0f + 1.0f;
		} else {
			y    = 100.0f;
			vel  = 350.0f;
			mult = 6.0f;
		}
		mDirection += gsys->getFrameTime() * PI * mult;
		mDirection = roundAng(mDirection);

		mRotation.set(0.0f, mDirection, 0.0f);

		diff        = diff * (1.0f / dist);
		mVelocity.x = vel * diff.x;
		mVelocity.z = vel * diff.z;
		if (mPosition.y < y && mVelocity.y < 100.0f) {
			mVelocity.y += AIConstant::_instance->mConstants._24() * gsys->getFrameTime() * 2.5f;
		}
		if (dist < 8.0f) {
			navi->_72C++;
			kill(nullptr);
		}
	}
	updateAI();
}

/*
 * --INFO--
 * Address:	800EE18C
 * Size:	000010
 */
void SeedItem::doAI()
{
	if (mStateId == 2) {
		return;
	}
	/*
	.loc_0x0:
	  lwz       r0, 0x2B8(r3)
	  cmpwi     r0, 0x2
	  beqlr-
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE19C
 * Size:	000138
 */
void SeedItem::refresh(Graphics& gfx)
{
	if (mStateId != 2) {
		Matrix4f unused;
		mTransformMatrix.makeSRT(mScale, mRotation, mPosition);

		Matrix4f mtx;
		gfx.calcViewMatrix(mTransformMatrix, mtx);
		gfx.useMatrix(mtx, 0);
		gfx.mCamera->setBoundOffset(&mPosition);
		mapMgr->getLight(mPosition.x, mPosition.z);
		gfx.setLighting(true, nullptr);
		mCurrentShape->drawshape(gfx, *gfx.mCamera, nullptr);
		gfx.mCamera->setBoundOffset(nullptr);
	}

	f32 badcompiler[2];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xA0(r1)
	  stw       r31, 0x9C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x98(r1)
	  mr        r30, r3
	  lwz       r0, 0x2B8(r3)
	  cmpwi     r0, 0x2
	  beq-      .loc_0x120
	  addi      r3, r30, 0x228
	  addi      r4, r30, 0x7C
	  addi      r5, r30, 0x88
	  addi      r6, r30, 0x94
	  bl        -0xB00E0
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r30, 0x228
	  addi      r5, r1, 0x14
	  lwz       r12, 0x70(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  addi      r4, r1, 0x14
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r30, 0x94
	  lwz       r4, 0x2E4(r31)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0xB0
	  lwz       r3, 0x94(r30)
	  lwz       r0, 0x98(r30)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x9C(r30)
	  stw       r0, 0x160(r4)

	.loc_0xB0:
	  lwz       r3, 0x2F00(r13)
	  lfs       f1, 0x94(r30)
	  lfs       f2, 0x9C(r30)
	  bl        -0x864C0
	  mr        r3, r31
	  lwz       r12, 0x3B4(r31)
	  li        r4, 0x1
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x2E4(r30)
	  mr        r4, r31
	  lwz       r5, 0x2E4(r31)
	  li        r6, 0
	  bl        -0xBDE1C
	  lwz       r4, 0x2E4(r31)
	  li        r0, 0
	  stb       r0, 0x154(r4)
	  lbz       r0, 0x154(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x120
	  lwz       r3, 0x0(r0)
	  lwz       r0, 0x4(r0)
	  stw       r3, 0x158(r4)
	  stw       r0, 0x15C(r4)
	  lwz       r0, 0x8(r0)
	  stw       r0, 0x160(r4)

	.loc_0x120:
	  lwz       r0, 0xA4(r1)
	  lwz       r31, 0x9C(r1)
	  lwz       r30, 0x98(r1)
	  addi      r1, r1, 0xA0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800EE2D4
 * Size:	00003C
 */
bool SeedItem::stimulate(Interaction& act)
{
	act.actCommon(this);
	return true;
}

/*
 * --INFO--
 * Address:	800EE310
 * Size:	000008
 */
f32 SeedItem::getHeight()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800EE318
 * Size:	000008
 */
f32 SeedItem::getiMass()
{
	return 100.0f;
}
