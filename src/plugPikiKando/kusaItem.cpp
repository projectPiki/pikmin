#include "KusaItem.h"
#include "MapMgr.h"
#include "Graphics.h"
#include "SoundMgr.h"
#include "EffectMgr.h"
#include "Dolphin/os.h"
#include "sysNew.h"
#include "Interactions.h"
#include "DebugLog.h"

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
	mScale.set(1.0f, 1.0f, 1.0f);
	_814       = mPosition;
	_814.y     = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	mHealth    = 50.0f;
	mMaxHealth = 200.0f;
	mBaseItem  = static_cast<BoBaseItem*>(itemMgr->birth(OBJTYPE_BoBase));

	if (mBaseItem) {
		mBaseItem->init(_814);
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
		mBaseItem->_824 = false;
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
	mPosition = _814;
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
	mTransformMatrix.makeSRT(mScale, mRotation, mPosition);
	mTransformMatrix.multiply(mat);

	gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, camMat);
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
	mScale.set(1.0f, 1.0f, 1.0f);
	_814     = mPosition;
	_814.y   = mapMgr->getMinY(mPosition.x, mPosition.z, true);
	_824     = true;
	mPtclGen = nullptr;
	_825     = 0;
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
	if (_824) {
		mPosition = _814;
		ItemCreature::update();
		_825--;
		if (_825 <= 0) {
			_825 = 0;
			if (mPtclGen) {
				effectMgr->mPtclMgr.killGenerator(mPtclGen, false);
				mPtclGen = nullptr;
			}
		}
		return;
	}

	if (_825 > 0) {
		_825--;
	}
}

/*
 * --INFO--
 * Address:	800E644C
 * Size:	0000EC
 */
void BoBaseItem::refresh(Graphics& gfx)
{
	if (_824 || (!_824 && _825 > 0)) {
		Matrix4f camMat;
		mTransformMatrix.makeSRT(mScale, mRotation, mPosition);

		gfx.mCamera->mLookAtMtx.multiplyTo(mTransformMatrix, camMat);
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
		mStickItem->mHealth += build.mProgressRate * 0.4f; // this needs fixing
		if (mStickItem->mHealth >= mStickItem->mMaxHealth) {
			mHealth = mMaxHealth;
			_824    = 0;
			effectMgr->create(EffectMgr::EFF_Kusa_Extend2, mPosition, nullptr, nullptr);
			playEventSound(this, SEB_WALL_DOWN);
			_825 = 30;
			if (mPtclGen) {
				effectMgr->kill(mPtclGen, false);
			}
		} else {
			playEventSound(this, SEB_CONSTRUCTION);
			_825 = 30;
			if (!mPtclGen) {
				mPtclGen = effectMgr->create(EffectMgr::EFF_Kusa_Extend1, mPosition, nullptr, nullptr);
			}
		}
		return true;
	}
	return false;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x18(r1)
	  stw       r31, 0x14(r1)
	  mr        r31, r3
	  lwz       r3, 0x820(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0xF8
	  lfs       f1, -0x6678(r2)
	  lfs       f0, 0xC(r4)
	  lfsu      f2, 0x58(r3)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x0(r3)
	  lwz       r3, 0x820(r31)
	  lfs       f1, 0x5C(r3)
	  addi      r4, r3, 0x58
	  lfs       f0, 0x58(r3)
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0xB0
	  stfs      f1, 0x0(r4)
	  li        r0, 0
	  addi      r5, r31, 0x94
	  stb       r0, 0x824(r31)
	  li        r4, 0xC7
	  li        r6, 0
	  lwz       r3, 0x3180(r13)
	  li        r7, 0
	  bl        0xB658C
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAB
	  bl        -0x5C008
	  li        r0, 0x1E
	  stb       r0, 0x825(r31)
	  lwz       r4, 0x828(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xF0
	  lwz       r3, 0x3180(r13)
	  li        r5, 0
	  addi      r3, r3, 0x14
	  bl        0xBAFE4
	  b         .loc_0xF0

	.loc_0xB0:
	  addi      r3, r31, 0
	  addi      r4, r31, 0
	  li        r5, 0xAD
	  bl        -0x5C040
	  li        r0, 0x1E
	  stb       r0, 0x825(r31)
	  lwz       r0, 0x828(r31)
	  cmplwi    r0, 0
	  bne-      .loc_0xF0
	  lwz       r3, 0x3180(r13)
	  addi      r5, r31, 0x94
	  li        r4, 0xC6
	  li        r6, 0
	  li        r7, 0
	  bl        0xB6518
	  stw       r3, 0x828(r31)

	.loc_0xF0:
	  li        r3, 0x1
	  b         .loc_0xFC

	.loc_0xF8:
	  li        r3, 0

	.loc_0xFC:
	  lwz       r0, 0x1C(r1)
	  lwz       r31, 0x14(r1)
	  addi      r1, r1, 0x18
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800E6648
 * Size:	000008
 */
bool BoBaseItem::isAlive()
{
	return _824;
}

/*
 * --INFO--
 * Address:	800E6650
 * Size:	000008
 */
bool BoBaseItem::isVisible()
{
	return true;
}

/*
 * --INFO--
 * Address:	800E6658
 * Size:	000008
 */
bool KusaItem::isVisible()
{
	return true;
}

/*
 * --INFO--
 * Address:	800E6660
 * Size:	000008
 */
bool KusaItem::isAlive()
{
	return true;
}
