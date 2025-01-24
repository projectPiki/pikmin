#include "KeyItem.h"
#include "DoorItem.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "MapMgr.h"
#include "Font.h"

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
 * Address:	800ED204
 * Size:	0000A8
 */
KeyItem::KeyItem(CreatureProp* props, Shape* model)
    : Creature(props)
{
	mModel = model;
	_68    = 4;
	mSearchBuffer.init(mSearch, 3);
	resetCreatureFlag(CF_Unk10);
	setCreatureFlag(CF_Unk1);
	mObjType = OBJTYPE_Key;
	_2B8     = 2;
}

/*
 * --INFO--
 * Address:	800ED2AC
 * Size:	000008
 */
f32 KeyItem::getSize()
{
	return 25.0f;
}

/*
 * --INFO--
 * Address:	800ED2B4
 * Size:	000054
 */
void KeyItem::init(Vector3f& pos)
{
	f32 scale = 1.0f;
	mScale.set(scale, scale, scale);
	Creature::init(pos);
	mSearchBuffer.init(mSearch, 3);
	_2B8 = 2;
}

/*
 * --INFO--
 * Address:	800ED308
 * Size:	00000C
 */
void KeyItem::startAI(int)
{
	_2B8 = 0;
}

/*
 * --INFO--
 * Address:	800ED314
 * Size:	000020
 */
bool KeyItem::isVisible()
{
	bool res = false;
	if (_2B8 != 1 && _2B8 != 2) {
		res = true;
	}
	return res;
}

/*
 * --INFO--
 * Address:	800ED334
 * Size:	00003C
 */
void KeyItem::doKill()
{
	PRINT("key is killed ?\n");
	_2B8 = 1;
	itemMgr->kill(this);
}

/*
 * --INFO--
 * Address:	800ED370
 * Size:	00010C
 */
void KeyItem::update()
{
	f32 length = mVelocity.length() / 150.0f * 0.01f + 0.025f;
	if (length > 2.0f) {
		length = 2.0f;
	}
	mDirection += length * TAU;
	mDirection = roundAng(mDirection);
	mGrid.updateGrid(mPosition);
	updateAI();

	f32 badcompiler[2];
}

/*
 * --INFO--
 * Address:	800ED47C
 * Size:	000004
 */
void KeyItem::collisionCallback(CollEvent&)
{
}

/*
 * --INFO--
 * Address:	800ED480
 * Size:	000008
 */
f32 KeyItem::getiMass()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800ED488
 * Size:	00014C
 */
void KeyItem::refresh(Graphics& gfx)
{
	Matrix4f mtx, mtx2;

	mTransformMatrix.makeSRT(mScale, mRotation, Vector3f(mPosition.x, mPosition.y + 20.0f, mPosition.z));

	gfx.calcViewMatrix(mTransformMatrix, mtx2);
	gfx.useMatrix(mtx2, 0);
	gfx.mCamera->setBoundOffset(&mPosition);
	mapMgr->getLight(mPosition.x, mPosition.z);
	bool l = gfx.setLighting(true, nullptr);
	mModel->drawshape(gfx, *gfx.mCamera, nullptr);
	gfx.mCamera->setBoundOffset(nullptr);
}

/*
 * --INFO--
 * Address:	800ED5D4
 * Size:	000060
 */
DoorItem::DoorItem(int objType, CreatureProp* props, Shape* shape)
    : ItemCreature(objType, props, shape)
{
	mStateId = 2;
	_3C8     = 0.0f;
	_3D0     = 0;
	_3D4     = 0;
}

/*
 * --INFO--
 * Address:	800ED634
 * Size:	000020
 */
void DoorItem::disappear()
{
	if (mStateId != 3) {
		mStateId = 3;
		_3C8     = 2.5f;
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

/*
 * --INFO--
 * Address:	800ED654
 * Size:	00001C
 */
f32 DoorItem::getSize()
{
	if (mObjType == OBJTYPE_Gate) {
		return 60.0f;
	}
	return 30.0f;
}

/*
 * --INFO--
 * Address:	800ED670
 * Size:	000054
 */
void DoorItem::init(Vector3f& pos)
{
	ItemCreature::init(pos);
	f32 scale = 1.0f;
	if (mObjType == OBJTYPE_Gate) {
		scale = 2.0f;
	}
	mScale.set(scale, scale, scale);
	mStateId = 2;
}

/*
 * --INFO--
 * Address:	800ED6C4
 * Size:	00000C
 */
void DoorItem::startAI(int)
{
	mStateId = 0;
}

/*
 * --INFO--
 * Address:	800ED6D0
 * Size:	0000A8
 */
void DoorItem::update()
{
	if (mStateId == 3) {
		_3C8 -= gsys->getFrameTime();
		f32 yscale = (_3C8 / 2.5f) * 2.0f;
		mPosition.y -= gsys->getFrameTime() * 3.0f;

		mScale.set(2.0f, yscale, 2.0f);

		if (_3C8 < 0.0f) {
			mStateId = 1;
			kill(nullptr);
		}
	} else {
		ItemCreature::update();
	}
}

/*
 * --INFO--
 * Address:	800ED778
 * Size:	000020
 */
bool DoorItem::isVisible()
{
	bool res = false;
	if (mStateId != 1 && mStateId != 2) {
		res = true;
	}
	return res;
}

/*
 * --INFO--
 * Address:	800ED798
 * Size:	000008
 */
f32 DoorItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800ED7A0
 * Size:	000020
 */
bool DoorItem::isAtari()
{
	bool res = true;
	if (mStateId != 0 && mStateId != 3) {
		res = false;
	}
	return res;
}

/*
 * --INFO--
 * Address:	800ED7C0
 * Size:	000204
 */
void DoorItem::refresh(Graphics& gfx)
{
	mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	Matrix4f mtx;
	gfx.calcViewMatrix(mTransformMatrix, mtx);

	Vector3f pos(0.0f, 40.0f, 0.0f);
	pos.multMatrix(mtx);
	bool set = gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);

	char str[256];

	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.useTexture(gsys->mConsFont->mTexture, 0);
	int blend = gfx.setCBlending(0);

	sprintf(str, "%s", _3D4);
	gfx.perspPrintf(gsys->mConsFont, pos, -(gsys->mConsFont->stringWidth(str) / 2), 0, str);

	gfx.setCBlending(blend);
	gfx.setLighting(set, nullptr);
	gfx.useMatrix(mtx, nullptr);
	ItemCreature::refresh(gfx);
}
