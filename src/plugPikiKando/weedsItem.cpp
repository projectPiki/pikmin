#include "WeedsItem.h"
#include "SoundMgr.h"
#include "MapMgr.h"
#include "Graphics.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(6)

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT("weeds")

/*
 * --INFO--
 * Address:	800E467C
 * Size:	000020
 */
bool RockGen::workable()
{
	return mWorkingPikis < 5;
}

/*
 * --INFO--
 * Address:	800E469C
 * Size:	000018
 */
void RockGen::startWork()
{
	if (workable()) {
		mWorkingPikis++;
	}
}

/*
 * --INFO--
 * Address:	800E46B4
 * Size:	000018
 */
void RockGen::finishWork()
{
	if (mWorkingPikis > 0) {
		mWorkingPikis--;
	}
}

/*
 * --INFO--
 * Address:	800E46CC
 * Size:	000020
 */
bool GrassGen::workable()
{
	return mWorkingPikis < 5;
}

/*
 * --INFO--
 * Address:	800E46EC
 * Size:	000018
 */
void GrassGen::startWork()
{
	if (workable()) {
		mWorkingPikis++;
	}
}

/*
 * --INFO--
 * Address:	800E4704
 * Size:	000018
 */
void GrassGen::finishWork()
{
	if (mWorkingPikis > 0) {
		mWorkingPikis--;
	}
}

/*
 * --INFO--
 * Address:	800E471C
 * Size:	00025C
 */
void RockGen::resolve()
{
	int max = mMaxPebbles;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < max - 1; j++) {
			Vector3f& pos = mPebbles[j].mPosition;

			for (int k = j + 1; k < max; k++) {
				Vector3f& pos2 = mPebbles[k].mPosition;

				Vector3f separation = pos - pos2;
				f32 distance        = std::sqrtf(separation.x * separation.x + separation.z * separation.z);
				separation.normalise();
				if (distance < 30.0f) {
					separation = separation * 15.0f;
					pos        = pos - separation;
					pos2       = pos2 + separation;

					pos.y  = mapMgr->getMinY(pos.x, pos.z, true);
					pos2.y = mapMgr->getMinY(pos2.x, pos2.z, true);
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800E4978
 * Size:	00025C
 */
void GrassGen::resolve()
{
	int max = mTotalGrassCount;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < max - 1; j++) {
			Vector3f* pos = &mGrass[j].mPosition;
			for (int k = j + 1; k < max; k++) {
				Vector3f* pos2 = &mGrass[k].mPosition;
				Vector3f diff  = *pos - *pos2;
				f32 len        = std::sqrtf(diff.x * diff.x + diff.z * diff.z);
				diff.normalise();
				if (len < 30.0f) {
					diff  = diff * 15.0f;
					*pos  = *pos - diff;
					*pos2 = *pos2 + diff;

					pos->y  = mapMgr->getMinY(pos->x, pos->z, true);
					pos2->y = mapMgr->getMinY(pos2->x, pos2->z, true);
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800E4BD4
 * Size:	0000A0
 */
RockGen::RockGen(Shape* shape, CreatureProp* props)
    : ItemCreature(OBJTYPE_RockGen, props, nullptr)
{
	mPebbles       = 0;
	mMaxPebbles    = 0;
	mActivePebbles = 0;
	mSeContext     = new SeContext;
	mSeContext->setContext(this, 4);
}

/*
 * --INFO--
 * Address:	800E4C74
 * Size:	000284
 */
void RockGen::create(int num, f32 radius, int)
{
	mPebbles       = new Pebble[num];
	mActivePebbles = num;
	mMaxPebbles    = num;
	mSize          = radius;

	for (int i = 0; i < num; i++) {
		f32 randomFactor = gsys->getRand(1.0f);
		f32 finalRadius  = ((1.0f - randomFactor) * gsys->getRand(1.0f) + randomFactor);
		finalRadius *= radius;

		f32 randomAngle = (TAU * gsys->getRand(1.0f));
		Vector3f pebbleOffset(sinf(randomAngle) * finalRadius, 0.0f, cosf(randomAngle) * finalRadius);
		pebbleOffset   = pebbleOffset + mPosition;
		pebbleOffset.y = mapMgr->getMinY(pebbleOffset.x, pebbleOffset.z, true);

		Pebble& obj          = mPebbles[i];
		obj.mPosition        = pebbleOffset;
		obj.mRotationDegrees = 0.99999f * (255.0f * gsys->getRand(1.0f));
		obj.mShapeIndex      = 0.99999f * (3.0f * gsys->getRand(1.0f));
		obj.mHealth          = obj.mShapeIndex * 2 + 2;
	}

	resolve();
}

/*
 * --INFO--
 * Address:	800E4F0C
 * Size:	000010
 */
void RockGen::setSizeAndNum(f32 size, int num)
{
	mActivePebbles = num;
	mMaxPebbles    = num;
	mSize          = size;
}

/*
 * --INFO--
 * Address:	800E4F1C
 * Size:	00005C
 */
void RockGen::startAI(int state)
{
	mWorkingPikis = 0;
	create(mMaxPebbles, mSize, 0);
	PRINT("++++++++ CREATE ROCK GEN +++++++\n");
	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);
}

/*
 * --INFO--
 * Address:	800E4F78
 * Size:	000010
 */
void RockGen::killPebble()
{
	mActivePebbles--;
}

/*
 * --INFO--
 * Address:	800E4F88
 * Size:	00003C
 */
void RockGen::doSave(RandomAccessStream& data)
{
	data.writeByte(mActivePebbles);
}

/*
 * --INFO--
 * Address:	800E4FC4
 * Size:	000080
 */
void RockGen::doLoad(RandomAccessStream& data)
{
	mActivePebbles = data.readByte();
	for (int i = 0; i < mMaxPebbles - mActivePebbles; i++) {
		PRINT("%s", mActivePebbles - mMaxPebbles); // fake but fixes register issues

		int offset = mMaxPebbles - 1 - i;

		mPebbles[offset].mHealth = 0;
	}
}

/*
 * --INFO--
 * Address:	800E5044
 * Size:	00002C
 */
void RockGen::update()
{
	if (mSeContext) {
		mSeContext->update();
	}
}

/*
 * --INFO--
 * Address:	800E5070
 * Size:	000190
 */
void RockGen::refresh(Graphics& gfx)
{
	if (!gfx.mCamera->isPointVisible(mPosition, getSize() * 4.0f)) {
		return;
	}

	for (int i = 0; i < mMaxPebbles; i++) {
		Pebble& pebble = mPebbles[i];
		if (!pebble.mHealth) {
			continue;
		}

		Matrix4f mtx;
		f32 yRotation = (pebble.mRotationDegrees / 255.0f) * PI * 2;
		mtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, yRotation, 0.0f), pebble.mPosition);
		Matrix4f mtx2;
		gfx.calcViewMatrix(mtx, mtx2);
		gfx.mHasTexGen = 1;
		gfx.useMatrix(mtx2, 0);
		itemMgr->getPebbleShape(pebble.mShapeIndex)->drawshape(gfx, *gfx.mCamera, nullptr);
	}
}

/*
 * --INFO--
 * Address:	800E5208
 * Size:	0000E0
 */
Pebble* RockGen::getRandomPebble()
{
	if (mActivePebbles <= 0) {
		return nullptr;
	}

	int randomPebbleCount = mActivePebbles * gsys->getRand(1.0f) * 0.99999f;
	for (int i = 0; i < mMaxPebbles; i++) {
		Pebble& pebble = mPebbles[i];
		if (!pebble.mHealth) {
			continue;
		}

		if (randomPebbleCount <= 0) {
			return &pebble;
		}

		randomPebbleCount--;
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	800E52E8
 * Size:	0000A0
 */
GrassGen::GrassGen(Shape* shape, CreatureProp* props)
    : ItemCreature(OBJTYPE_GrassGen, props, nullptr)
{
	mGrass           = 0;
	mTotalGrassCount = 0;
	mActiveGrass     = 0;
	mSeContext       = new SeContext;
	mSeContext->setContext(this, 4);
}

/*
 * --INFO--
 * Address:	800E5388
 * Size:	000244
 */
void GrassGen::create(int num, f32 size, int)
{
	mGrass           = new Grass[num];
	mActiveGrass     = num;
	mTotalGrassCount = num;
	mSize            = size;

	for (int i = 0; i < num; i++) {
		f32 finalRadius = gsys->getRand(1.0f);
		finalRadius     = ((1.0f - finalRadius) * gsys->getRand(1.0f) + finalRadius);
		finalRadius *= size;

		f32 randomAngle = (TAU * gsys->getRand(1.0f));
		Vector3f grassOffset(sinf(randomAngle) * finalRadius, 0.0f, cosf(randomAngle) * finalRadius);
		grassOffset   = grassOffset + mPosition;
		grassOffset.y = mapMgr->getMinY(grassOffset.x, grassOffset.z, true);

		Grass& obj           = mGrass[i];
		obj.mPosition        = grassOffset;
		obj.mRotationDegrees = 0.99999f * (255.0f * gsys->getRand(1.0f));
		obj.mGrassShapeId    = 0;
		obj.mHealth          = 1;
	}

	resolve();
}

/*
 * --INFO--
 * Address:	800E55E0
 * Size:	000010
 */
void GrassGen::setSizeAndNum(f32 size, int num)
{
	mActiveGrass     = num;
	mTotalGrassCount = num;
	mSize            = size;
}

/*
 * --INFO--
 * Address:	800E55F0
 * Size:	00005C
 */
void GrassGen::startAI(int)
{
	mWorkingPikis = 0;
	create(mTotalGrassCount, mSize, 0);
	mGrid.updateGrid(mPosition);
	mGrid.updateAIGrid(mPosition, false);
	PRINT("++++++++ CREATE GRASS GEN +++++++\n");
}

/*
 * --INFO--
 * Address:	800E564C
 * Size:	00002C
 */
void GrassGen::update()
{
	if (mSeContext) {
		mSeContext->update();
	}
}

/*
 * --INFO--
 * Address:	800E5678
 * Size:	000190
 */
void GrassGen::refresh(Graphics& gfx)
{
	if (gfx.mCamera->isPointVisible(mPosition, getSize() * 4.0f)) {
		for (int i = 0; i < mTotalGrassCount; i++) {
			Grass& blade = mGrass[i];
			if (blade.mHealth) {
				Matrix4f mtx;
				f32 yRotation = (blade.mRotationDegrees / 255.0f) * PI * 2.0f;
				mtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, yRotation, 0.0f), blade.mPosition);
				Matrix4f mtx2;
				gfx.calcViewMatrix(mtx, mtx2);
				gfx.mHasTexGen = 1;
				gfx.useMatrix(mtx2, 0);
				itemMgr->getGrassShape(blade.mGrassShapeId)->drawshape(gfx, *gfx.mCamera, nullptr);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800E5810
 * Size:	0000E0
 */
Grass* GrassGen::getRandomGrass()
{
	if (mActiveGrass <= 0)
		return nullptr;

	int id = mActiveGrass * gsys->getRand(1.0f) * 0.99999f;
	for (int i = 0; i < mTotalGrassCount; i++) {
		Grass& blade = mGrass[i];
		if (!blade.mHealth) {
			continue;
		}

		if (id <= 0) {
			return &blade;
		}

		id--;
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
WeedsGen::WeedsGen(Shape* shape, CreatureProp* props)
    : ItemCreature(0, props, shape)
{
	if (!shape) {
		ERROR("ERR\n");
	}
	mWeedsCount      = 0;
	mWeedsGenProps   = props;
	mItemShapeObject = nullptr;
	mWeedShape       = shape;
}

/*
 * --INFO--
 * Address:	800E58F0
 * Size:	000004
 */
void WeedsGen::update()
{
}

/*
 * --INFO--
 * Address:	800E58F4
 * Size:	000004
 */
void WeedsGen::refresh(Graphics&)
{
}

/*
 * --INFO--
 * Address:	800E58F8
 * Size:	0001CC
 */
void WeedsGen::startAI(int ai)
{
	for (int i = 0; i < mWeedsCount; i++) {
		Weed* gen = (Weed*)itemMgr->birth(OBJTYPE_Weed);
		if (!gen) {
			continue;
		}

		f32 size  = gsys->getRand(1.0f) * 50.0f;
		f32 angle = gsys->getRand(1.0f) * TAU;

		Vector3f offset(sinf(angle) * size, 0.0f, cosf(angle) * size);
		offset   = offset + mPosition;
		offset.y = mapMgr->getMinY(offset.x, offset.z, true);

		if (!mWeedShape) {
			ERROR("STAI\n");
		}

		gen->mProps = mWeedsGenProps;
		gen->mGen   = this;
		gen->init(offset);
		gen->mItemShape = mWeedShape;
		gen->startAI(0);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
Weed::Weed()
    : ItemCreature(0, nullptr, nullptr)
{
	mItemShapeObject = nullptr;
	setCreatureFlag(0x11);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800E5AC4
 * Size:	000024
 */
void Weed::startAI(int)
{
	mScale.set(0.1f, 0.1f, 0.1f);
	mIsPulled = 0;
}

/*
 * --INFO--
 * Address:	800E5AE8
 * Size:	0000CC
 */
bool Weed::interactPullout(Creature* item)
{
	if (!mIsPulled) {
		mIsPulled     = 1;
		mPulloutTimer = 0;
		f32 size      = 20.0f;
		f32 angle     = item->mFaceDirection;
		Vector3f velocity(sinf(angle) * -size, 370.0f, cosf(angle) * -size);

		mVelocity       = velocity;
		mTargetVelocity = velocity;
		return true;
	}
	return false;
}

/*
 * --INFO--
 * Address:	800E5BB4
 * Size:	00009C
 */
void Weed::update()
{
	ItemCreature::update();

	if (mIsPulled == 1) {
		mPulloutTimer++;
		if (mPulloutTimer > 30) {
			kill(nullptr);
		} else {
			f32 s = (1.0f - mPulloutTimer / 30.0f);
			s *= 0.1f;
			mScale.set(s, s, s);
		}
	}
}

/*
 * --INFO--
 * Address:	800E5C50
 * Size:	000108
 */
void Weed::refresh(Graphics& gfx)
{
	mWorldMtx.makeSRT(mScale, mRotation, mPosition);
	Matrix4f mtx;
	gfx.calcViewMatrix(mWorldMtx, mtx);
	gfx.mHasTexGen = 1;
	gfx.useMatrix(mtx, 0);
	gfx.mCamera->setBoundOffset(&mPosition);
	mItemShape->drawshape(gfx, *gfx.mCamera, nullptr);
	gfx.mCamera->setBoundOffset(nullptr);
}

/*
 * --INFO--
 * Address:	800E5D58
 * Size:	000014
 */
bool Weed::isVisible()
{
	return mIsPulled == 0;
}

/*
 * --INFO--
 * Address:	800E5D6C
 * Size:	000008
 */
bool Weed::isAlive()
{
	return true;
}

/*
 * --INFO--
 * Address:	800E5D74
 * Size:	000014
 */
bool Weed::isAtari()
{
	return mIsPulled == 0;
}
