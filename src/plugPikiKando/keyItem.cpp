#include "KeyItem.h"
#include "DebugLog.h"
#include "DoorItem.h"
#include "Font.h"
#include "Graphics.h"
#include "MapMgr.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("keyItem")

KeyItem::KeyItem(CreatureProp* props, Shape* model)
    : Creature(props)
{
	mModel = model;
	_68    = 4;
	mSearchBuffer.init(mSearch, 3);
	resetCreatureFlag(CF_Unk10);
	setCreatureFlag(CF_Unk1);
	mObjType = OBJTYPE_Key;
	mState   = KeyState::Inactive;
}

f32 KeyItem::getSize()
{
	return 25.0f;
}

void KeyItem::init(immut Vector3f& pos)
{
	f32 scale = 1.0f;
	mSRT.s.set(scale, scale, scale);
	Creature::init(pos);
	mSearchBuffer.init(mSearch, 3);
	mState = KeyState::Inactive;
}

void KeyItem::startAI(int)
{
	mState = KeyState::Active;
}

bool KeyItem::isVisible()
{
	bool visible = false;

	if (mState != KeyState::Collected && mState != KeyState::Inactive) {
		visible = true;
	}

	return visible;
}

void KeyItem::doKill()
{
	PRINT("key is killed ?\n");
	mState = KeyState::Collected;
	itemMgr->kill(this);
}

void KeyItem::update()
{
	f32 rotationSpeed = mVelocity.length() / 150.0f * 0.01f + 0.025f;
	if (rotationSpeed > 2.0f) {
		rotationSpeed = 2.0f;
	}

	mFaceDirection += rotationSpeed * TAU;
	mFaceDirection = roundAng(mFaceDirection);
	mGrid.updateGrid(mSRT.t);
	updateAI();

	STACK_PAD_VAR(2);
}

void KeyItem::collisionCallback(immut CollEvent&)
{
}

f32 KeyItem::getiMass()
{
	return 10.0f;
}

void KeyItem::refresh(Graphics& gfx)
{
	Matrix4f transform, viewTransform;

	mWorldMtx.makeSRT(mSRT.s, mSRT.r, Vector3f(mSRT.t.x, mSRT.t.y + 20.0f, mSRT.t.z));
	gfx.calcViewMatrix(mWorldMtx, viewTransform);
	gfx.useMatrix(viewTransform, 0);

	gfx.mCamera->setBoundOffset(&mSRT.t);
	mapMgr->getLight(mSRT.t.x, mSRT.t.z);

	bool l = gfx.setLighting(true, nullptr);
	mModel->drawshape(gfx, *gfx.mCamera, nullptr);
	gfx.mCamera->setBoundOffset(nullptr);
}

DoorItem::DoorItem(int objType, CreatureProp* props, Shape* shape)
    : ItemCreature(objType, props, shape)
{
	mStateId              = DoorState::Inactive;
	mFadeTimer            = 0.0f;
	mDestinationStagePath = nullptr;
	mLabelText            = nullptr;
}

void DoorItem::disappear()
{
	if (mStateId != DoorState::Vanishing) {
		mStateId   = DoorState::Vanishing;
		mFadeTimer = 2.5f;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void DoorItem::becomeGate()
{
	mObjType = OBJTYPE_Gate;
}

f32 DoorItem::getSize()
{
	if (mObjType == OBJTYPE_Gate) {
		return 60.0f;
	}

	return 30.0f;
}

void DoorItem::init(immut Vector3f& pos)
{
	ItemCreature::init(pos);
	f32 scale = 1.0f;
	if (mObjType == OBJTYPE_Gate) {
		scale = 2.0f;
	}
	mSRT.s.set(scale, scale, scale);
	mStateId = DoorState::Inactive;
}

void DoorItem::startAI(int)
{
	mStateId = DoorState::Active;
}

void DoorItem::update()
{
	if (mStateId == DoorState::Vanishing) {
		mFadeTimer -= gsys->getFrameTime();
		f32 yscale = (mFadeTimer / 2.5f) * 2.0f;
		mSRT.t.y -= gsys->getFrameTime() * 3.0f;

		mSRT.s.set(2.0f, yscale, 2.0f);

		if (mFadeTimer < 0.0f) {
			mStateId = DoorState::Killed;
			kill(false);
		}
	} else {
		ItemCreature::update();
	}
}

bool DoorItem::isVisible()
{
	bool res = false;
	if (mStateId != 1 && mStateId != DoorState::Inactive) {
		res = true;
	}
	return res;
}

f32 DoorItem::getiMass()
{
	return 0.0f;
}

bool DoorItem::isAtari()
{
	bool res = true;
	if (mStateId != DoorState::Active && mStateId != DoorState::Vanishing) {
		res = false;
	}
	return res;
}

void DoorItem::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	Matrix4f mtx;
	gfx.calcViewMatrix(mWorldMtx, mtx);

	Vector3f pos(0.0f, 40.0f, 0.0f);
	pos.multMatrix(mtx);
	bool set = gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);

	char str[256];

	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.useTexture(gsys->mConsFont->mTexture, GX_TEXMAP0);
	int blend = gfx.setCBlending(0);

	sprintf(str, "%s", mLabelText);
	gfx.perspPrintf(gsys->mConsFont, pos, -(gsys->mConsFont->stringWidth(str) / 2), 0, str);

	gfx.setCBlending(blend);
	gfx.setLighting(set, nullptr);
	gfx.useMatrix(mtx, nullptr);
	ItemCreature::refresh(gfx);
}
