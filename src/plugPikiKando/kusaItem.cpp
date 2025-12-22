#include "KusaItem.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "Interactions.h"
#include "MapMgr.h"
#include "SoundMgr.h"
#include "sysNew.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("kusa")

/**
 * @TODO: Documentation
 */
KusaItem::KusaItem(CreatureProp* props, Shape* shape)
    : ItemCreature(OBJTYPE_Kusa, mProps, shape)
    , mKusaCollision(0)
{
	mProps = props;
	setCreatureFlag(CF_Unk10);
}

/**
 * @TODO: Documentation
 */
void KusaItem::startAI(int)
{
	setCreatureFlag(CF_Unk10);
	mCollInfo = &mKusaCollision;
	mCollInfo->initInfo(mItemShape, mKusaParts, mPartIDs);
	mCollInfo->makeTubesChild('rope', 1);
	mSRT.s.set(1.0f, 1.0f, 1.0f);

	mGroundPosition   = mSRT.t;
	mGroundPosition.y = mapMgr->getMinY(mSRT.t.x, mSRT.t.z, true);

	mHealth    = 50.0f;
	mMaxHealth = 200.0f;
	mBaseItem  = static_cast<BoBaseItem*>(itemMgr->birth(OBJTYPE_BoBase));

	if (mBaseItem) {
		mBaseItem->init(mGroundPosition);
		mBaseItem->mStickItem = this;
		mBaseItem->startAI(0);
	}
}

/**
 * @TODO: Documentation
 */
void KusaItem::doLoad(RandomAccessStream& input)
{
	mHealth = input.readFloat();
	if (mHealth >= mMaxHealth) {
		mBaseItem->mIsActive = false;
	}
}

/**
 * @TODO: Documentation
 */
void KusaItem::doSave(RandomAccessStream& output)
{
	output.writeFloat(mHealth);
}

/**
 * @TODO: Documentation
 */
bool KusaItem::ignoreAtari(Creature* creature)
{
	if (creature->mStickTarget == this) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
f32 KusaItem::getSize()
{
	return 10.0f;
}

/**
 * @TODO: Documentation
 */
f32 KusaItem::getiMass()
{
	return 0.0f;
}

/**
 * @TODO: Documentation
 */
void KusaItem::update()
{
	mSRT.t = mGroundPosition;
	ItemCreature::update();
}

/**
 * @TODO: Documentation
 */
void KusaItem::refresh(Graphics& gfx)
{
	Matrix4f camMat;
	Matrix4f mat;
	mat.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, mHealth - mMaxHealth, 0.0f));
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	mWorldMtx.multiply(mat);

	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, camMat);
	gfx.setLighting(true, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);

	mItemShape->updateAnim(gfx, camMat, nullptr);
	mItemShape->drawshape(gfx, *gfx.mCamera, nullptr);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @TODO: Documentation
 */
BoBaseItem::BoBaseItem(CreatureProp* props, Shape* shape)
    : ItemCreature(OBJTYPE_BoBase, mProps, shape)
    , mBaseCollision(0)
{
	mProps = props;
	setCreatureFlag(CF_Unk10);
	mStickItem = nullptr;
	mSeContext = new SeContext();
	mSeContext->setContext(this, 4);
}

/**
 * @TODO: Documentation
 */
void BoBaseItem::startAI(int)
{
	setCreatureFlag(CF_Unk10);
	mCollInfo = &mBaseCollision;
	mCollInfo->initInfo(mItemShape, mBaseParts, mPartIDs);
	mSRT.s.set(1.0f, 1.0f, 1.0f);
	mGroundPosition    = mSRT.t;
	mGroundPosition.y  = mapMgr->getMinY(mSRT.t.x, mSRT.t.z, true);
	mIsActive          = true;
	mParticleGenerator = nullptr;
	mEffectDuration    = 0;
}

/**
 * @TODO: Documentation
 */
bool BoBaseItem::ignoreAtari(Creature* creature)
{
	if (creature->mStickTarget == this) {
		return true;
	}

	if (creature == mStickItem) {
		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
f32 BoBaseItem::getSize()
{
	return 10.0f;
}

/**
 * @TODO: Documentation
 */
f32 BoBaseItem::getiMass()
{
	return 0.0f;
}

/**
 * @TODO: Documentation
 */
void BoBaseItem::update()
{
	if (mIsActive) {
		mSRT.t = mGroundPosition;
		ItemCreature::update();

		mEffectDuration--;
		if (mEffectDuration <= 0) {
			mEffectDuration = 0;
			if (mParticleGenerator) {
				PRINT("effect kill\n");
				effectMgr->kill(mParticleGenerator, false);
				mParticleGenerator = nullptr;
			}
		}

		return;
	}

	if (mEffectDuration > 0) {
		mEffectDuration--;
	}
}

/**
 * @TODO: Documentation
 */
void BoBaseItem::refresh(Graphics& gfx)
{
	if (mIsActive || (!mIsActive && mEffectDuration > 0)) {
		Matrix4f camMat;
		mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);

		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, camMat);
		gfx.setLighting(true, nullptr);
		gfx.useMatrix(Matrix4f::ident, 0);

		mItemShape->updateAnim(gfx, camMat, nullptr);
		mItemShape->drawshape(gfx, *gfx.mCamera, nullptr);
		mCollInfo->updateInfo(gfx, false);
	}
}

/**
 * @TODO: Documentation
 */
bool BoBaseItem::interactBuild(immut InteractBuild& build)
{
	if (mStickItem) {
		mStickItem->mHealth = mStickItem->mHealth + build.mProgressRate * 0.4f;
		if (mStickItem->mHealth >= mStickItem->mMaxHealth) {
			mStickItem->mHealth = mStickItem->mMaxHealth;
			mIsActive           = 0;
			effectMgr->create(EffectMgr::EFF_Kusa_Extend2, mSRT.t, nullptr, nullptr);
			playEventSound(this, SEB_WALL_DOWN);
			mEffectDuration = 30;
			if (mParticleGenerator) {
				effectMgr->kill(mParticleGenerator, false);
			}
		} else {
			playEventSound(this, SEB_CONSTRUCTION);
			mEffectDuration = 30;
			if (!mParticleGenerator) {
				mParticleGenerator = effectMgr->create(EffectMgr::EFF_Kusa_Extend1, mSRT.t, nullptr, nullptr);
				PRINT("effect created !!!!\n");
			}
		}

		return true;
	}

	return false;
}

/**
 * @TODO: Documentation
 */
bool BoBaseItem::isAlive()
{
	return mIsActive;
}
