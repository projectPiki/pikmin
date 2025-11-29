#include "KusaItem.h"
#include "DebugLog.h"
#include "Dolphin/os.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "Interactions.h"
#include "MapMgr.h"
#include "SoundMgr.h"
#include "sysNew.h"

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
DEFINE_PRINT("kusa")

/*
 * --INFO--
 * Address:	800E5DD8
 * Size:	0000A4
 */
KusaItem::KusaItem(CreatureProp* props, Shape* shape)
    : ItemCreature(OBJTYPE_Kusa, mProps, shape)
    , mKusaCollision(0)
{
	mProps = props;
	setCreatureFlag(CF_Unk10);
}

/*
 * --INFO--
 * Address:	800E5E7C
 * Size:	000118
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

/*
 * --INFO--
 * Address:	800E5F94
 * Size:	000060
 */
void KusaItem::doLoad(RandomAccessStream& input)
{
	mHealth = input.readFloat();
	if (mHealth >= mMaxHealth) {
		mBaseItem->mIsActive = false;
	}
}

/*
 * --INFO--
 * Address:	800E5FF4
 * Size:	000038
 */
void KusaItem::doSave(RandomAccessStream& output)
{
	output.writeFloat(mHealth);
}

/*
 * --INFO--
 * Address:	800E602C
 * Size:	00001C
 */
bool KusaItem::ignoreAtari(Creature* creature)
{
	if (creature->mStickTarget == this) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	800E6048
 * Size:	000008
 */
f32 KusaItem::getSize()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800E6050
 * Size:	000008
 */
f32 KusaItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800E6058
 * Size:	000038
 */
void KusaItem::update()
{
	mSRT.t = mGroundPosition;
	ItemCreature::update();
}

/*
 * --INFO--
 * Address:	800E6090
 * Size:	000144
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

/*
 * --INFO--
 * Address:	800E61D4
 * Size:	0000D8
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

/*
 * --INFO--
 * Address:	800E62AC
 * Size:	0000AC
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

/*
 * --INFO--
 * Address:	800E6358
 * Size:	000030
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

/*
 * --INFO--
 * Address:	800E6388
 * Size:	000008
 */
f32 BoBaseItem::getSize()
{
	return 10.0f;
}

/*
 * --INFO--
 * Address:	800E6390
 * Size:	000008
 */
f32 BoBaseItem::getiMass()
{
	return 0.0f;
}

/*
 * --INFO--
 * Address:	800E6398
 * Size:	0000B4
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

/*
 * --INFO--
 * Address:	800E644C
 * Size:	0000EC
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

/*
 * --INFO--
 * Address:	800E6538
 * Size:	000110
 */
bool BoBaseItem::interactBuild(InteractBuild& build)
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

/*
 * --INFO--
 * Address:	800E6648
 * Size:	000008
 */
bool BoBaseItem::isAlive()
{
	return mIsActive;
}
