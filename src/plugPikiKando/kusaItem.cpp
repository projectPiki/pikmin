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
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("kusa")

/**
 * @todo: Documentation
 */
KusaItem::KusaItem(CreatureProp* props, Shape* shape)
    : ItemCreature(OBJTYPE_Kusa, mProps, shape)
    , mKusaCollision(0)
{
	mProps = props;
	setCreatureFlag(CF_DisableAutoFaceDir);
}

/**
 * @todo: Documentation
 */
void KusaItem::startAI(int)
{
	setCreatureFlag(CF_DisableAutoFaceDir);
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
 * @todo: Documentation
 */
void KusaItem::doLoad(RandomAccessStream& input)
{
	mHealth = input.readFloat();
	if (mHealth >= mMaxHealth) {
		mBaseItem->mIsActive = false;
	}
}

/**
 * @todo: Documentation
 */
void KusaItem::doSave(RandomAccessStream& output)
{
	output.writeFloat(mHealth);
}

/**
 * @todo: Documentation
 */
bool KusaItem::ignoreAtari(Creature* creature)
{
	if (creature->mStickTarget == this) {
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
f32 KusaItem::getSize()
{
	return 10.0f;
}

/**
 * @todo: Documentation
 */
f32 KusaItem::getiMass()
{
	return 0.0f;
}

/**
 * @todo: Documentation
 */
void KusaItem::update()
{
	mSRT.t = mGroundPosition;
	ItemCreature::update();
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
BoBaseItem::BoBaseItem(CreatureProp* props, Shape* shape)
    : ItemCreature(OBJTYPE_BoBase, mProps, shape)
    , mBaseCollision(0)
{
	mProps = props;
	setCreatureFlag(CF_DisableAutoFaceDir);
	mStickItem = nullptr;
	mSeContext = new SeContext();
	mSeContext->setContext(this, 4);
}

/**
 * @todo: Documentation
 */
void BoBaseItem::startAI(int)
{
	setCreatureFlag(CF_DisableAutoFaceDir);
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
 * @todo: Documentation
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
 * @todo: Documentation
 */
f32 BoBaseItem::getSize()
{
	return 10.0f;
}

/**
 * @todo: Documentation
 */
f32 BoBaseItem::getiMass()
{
	return 0.0f;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
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
 * @todo: Documentation
 */
bool BoBaseItem::isAlive()
{
	return mIsActive;
}
