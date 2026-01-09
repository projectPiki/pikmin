#include "DebugLog.h"
#include "Graphics.h"
#include "King.h"
#include "MapCode.h"
#include "Matrix3f.h"
#include "NsMath.h"
#include "Pcam/CameraManager.h"
#include "Pellet.h"
#include "RadarInfo.h"
#include "RumbleMgr.h"
#include "SoundMgr.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("KingBody");

/**
 * @todo: Documentation
 * @note UNUSED Size: 00017C
 */
void KingBody::setSalivaEffect()
{
	mSalivaCallBacks[0].set(&mSalivaJointPositions[1], &mSalivaJointPositions[2], mKing);
	mSalivaParticleCallBack->set(mKing);
	effectMgr->create(EffectMgr::EFF_King_Saliva1A, Vector3f(0.0f, 0.0f, 0.0f), &mSalivaCallBacks[0], mSalivaParticleCallBack);

	mSalivaCallBacks[1].set(&mSalivaJointPositions[0], &mSalivaJointPositions[3], mKing);
	effectMgr->create(EffectMgr::EFF_King_Saliva1A, Vector3f(0.0f, 0.0f, 0.0f), &mSalivaCallBacks[1], mSalivaParticleCallBack);

	mSalivaCallBacks[2].set(&mSalivaJointPositions[0], &mSalivaJointPositions[1], mKing);
	effectMgr->create(EffectMgr::EFF_King_Saliva1B, Vector3f(0.0f, 0.0f, 0.0f), &mSalivaCallBacks[2], mSalivaParticleCallBack);

	mSpreadSalivaCallBack->set(mKing);
	zen::particleGenerator* ptcl
	    = effectMgr->create(EffectMgr::EFF_King_Saliva2, Vector3f(0.0f, 0.0f, 0.0f), mSpreadSalivaCallBack, mSalivaParticleCallBack);
	if (ptcl) {
		ptcl->setEmitPosPtr(&mSalivaEffectPos);
	}
}

/**
 * @todo: Documentation
 */
void KingBody::setSeedFlashEffect()
{
	mDamageStarCallBack->set(mKing);

	for (int i = 0; i < 2; i++) {
		effectMgr->create(EffectMgr::EFF_Piki_HitA, mEyePositions[i], nullptr, nullptr);
		effectMgr->create(EffectMgr::EFF_Piki_HitB, mEyePositions[i], nullptr, nullptr);
		zen::particleGenerator* ptcl
		    = effectMgr->create(EffectMgr::EFF_King_SeedFlash, Vector3f(0.0f, 0.0f, 0.0f), mDamageStarCallBack, nullptr);
		if (ptcl) {
			ptcl->setEmitPosPtr(&mEyePositions[i]);
		}
	}
}

/**
 * @todo: Documentation
 */
void KingBody::setEatBombEffect()
{
	Vector3f dir(sinf(mKing->mFaceDirection), 0.0f, cosf(mKing->mFaceDirection));
	Vector3f effectPos            = mMouthPos + 50.0f * dir;
	zen::particleGenerator* ptcl1 = effectMgr->create(EffectMgr::EFF_King_EatBomb2, effectPos, nullptr, nullptr);
	if (ptcl1) {
		ptcl1->setEmitDir(dir);
	}
	zen::particleGenerator* ptcl2 = effectMgr->create(EffectMgr::EFF_King_EatBomb1, effectPos, nullptr, nullptr);
	if (ptcl2) {
		ptcl2->setEmitDir(dir);
	}

	mDamageStarCallBack->set(mKing);
	for (int i = 0; i < 2; i++) {
		zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_King_EatBomb3, mCheekPositions[i], nullptr, nullptr);
		if (ptcl) {
			ptcl->setEmitDir(dir);
		}
	}

	setSeedFlashEffect();
}

/**
 * @todo: Documentation
 */
void KingBody::createWaterEffect(int idx)
{
	effectMgr->create(EffectMgr::EFF_P_Bubbles, mFootPosList[idx], nullptr, nullptr);
	if (!mIsFootGeneratingRipples[idx]) {
		mIsFootGeneratingRipples[idx] = true;
		mRippleCallBacks[idx].set(mKing, &mFootPosList[idx], &mIsFootGeneratingRipples[idx]);
		zen::particleGenerator* ptcl1
		    = effectMgr->create(EffectMgr::EFF_RippleWhite, Vector3f(0.0f, 0.0f, 0.0f), &mRippleCallBacks[idx], nullptr);
		if (ptcl1) {
			ptcl1->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = ptcl1->getScaleSize();
			ptcl1->setScaleSize(2.0f * f0);
		}
		zen::particleGenerator* ptcl2
		    = effectMgr->create(EffectMgr::EFF_RippleSurface, Vector3f(0.0f, 0.0f, 0.0f), &mRippleCallBacks[idx], nullptr);
		if (ptcl2) {
			ptcl2->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = ptcl2->getScaleSize();
			ptcl2->setScaleSize(2.0f * f0);
		}
		zen::particleGenerator* ptcl3
		    = effectMgr->create(EffectMgr::EFF_RippleBlack, Vector3f(0.0f, 0.0f, 0.0f), &mRippleCallBacks[idx], nullptr);
		if (ptcl3) {
			ptcl3->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = ptcl3->getScaleSize();
			ptcl3->setScaleSize(2.0f * f0);
		}
	}
}

/**
 * @todo: Documentation
 */
void KingBody::createUfoParts()
{
	Pellet* ufoPart = pelletMgr->newPellet(mKing->mPelletID.mId, nullptr);
	if (ufoPart) {
		CollPart* nosePart = mKing->mCollInfo->getSphere('nose');
		f32 angle          = atan2f(nosePart->mCentre.x - mKing->mSRT.t.x, nosePart->mCentre.z - mKing->mSRT.t.z);
		f32 xOffs          = sinf(angle) + sinf(mKing->mFaceDirection);
		f32 zOffs          = cosf(angle) + cosf(mKing->mFaceDirection);
		Vector3f dir(xOffs, 0.0f, zOffs);
		Vector3f partPos(nosePart->mCentre);
		partPos.y -= 80.0f;

		ufoPart->init(partPos);

		dir.normalise();
		ufoPart->mVelocity.set(250.0f * dir.x, 0.0f, 250.0f * dir.z);

		ufoPart->mFaceDirection = mKing->mFaceDirection;
		ufoPart->startAI(0);

		zen::particleGenerator* ptcl = effectMgr->create(EffectMgr::EFF_King_SpitParts, partPos, nullptr, mSpitPartsParticleCallBack);

		radarInfo->detachParts(mKing);

		if (ptcl) {
			dir.y = -0.5f;
			ptcl->setEmitDir(dir);
		}

		if (Pellet::isUfoPartsID(mKing->mPelletID.mId)) {
			SeSystem::playSysSe(SYSSE_PARTS_APPEAR);
		}
	}

#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIJ01_01)
#else
	mKing->mIsBossBgm = false;
#endif
	mKing->detachGenerator();
}

/**
 * @todo: Documentation
 */
void KingBody::killCallBackEffect(bool doForceFinish)
{
	int i;
	for (i = 0; i < 3; i++) {
		effectMgr->kill(&mSalivaCallBacks[i], mSalivaParticleCallBack, doForceFinish);
	}

	effectMgr->kill(mSpreadSalivaCallBack, mSalivaParticleCallBack, doForceFinish);
	effectMgr->kill(mDamageStarCallBack, nullptr, doForceFinish);

	for (i = 0; i < 2; i++) {
		effectMgr->kill(&mRippleCallBacks[i], nullptr, doForceFinish);
	}
}

/**
 * @todo: Documentation
 */
KingBody::KingBody(King*)
{
	mBlendStartMatrices        = new Matrix4f[66];
	mBlendResultMatrices       = new Matrix4f[66];
	mSalivaCallBacks           = new KingGenSalivaCallBack[3];
	mSpreadSalivaCallBack      = new KingGenSpreadSalivaCallBack;
	mSalivaParticleCallBack    = new KingGenSalivaParticleCallBack;
	mDamageStarCallBack        = new KingGenDamageStarCallBack;
	mRippleCallBacks           = new KingGenRippleCallBack[2];
	mSpitPartsParticleCallBack = new KingGenSpitPartsParticleCallBack;
}

/**
 * @todo: Documentation
 */
void KingBody::init(King* king)
{
	mKing                 = king;
	mIsBlending           = false;
	mBlendingRatio        = 0.0f;
	mMoveSpeed            = 0.0f;
	mDoFallSalivaEffect   = false;
	mDoSpreadSalivaEffect = false;

	for (int i = 0; i < 2; i++) {
		mPrevIsFootOnGround[i]      = true;
		mIsFootOnGround[i]          = true;
		mIsFootGeneratingRipples[i] = false;
		mFootMapAttr[i]             = ATTR_NULL;
		mFootPosList[i].set(0.0f, 0.0f, 0.0f);
		mOldFootPosList[i].set(0.0f, 0.0f, 0.0f);
	}

	_UNUSED54.set(0.0f, 0.0f, 0.0f);
	setSalivaEffect();
}

/**
 * @todo: Documentation
 */
void KingBody::initBlending(f32 blendRate)
{
	if (mBlendingRatio > 0.0f) {
		mIsBlending = true;
	}
	mBlendingRatio = 0.00001f;
	mBlendingRate  = blendRate;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000040
 */
void KingBody::updateBlendingRatio()
{
	if (mBlendingRatio > 0.0f) {
		mBlendingRatio += gsys->getFrameTime() * mBlendingRate;
		if (mBlendingRatio > 1.0f) {
			mBlendingRatio = 0.0f;
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C
 */
void KingBody::checkOnGround()
{
	for (int i = 0; i < 2; i++) {
		f32 heightDiff = mFootPosList[i].y - mKing->mSRT.t.y;
		if (heightDiff < 3.75f) {
			mIsFootOnGround[i] = true;
		} else if (heightDiff > 10.0f) {
			mIsFootOnGround[i] = false;
		}
	}
}

/**
 * @todo: Documentation
 */
void KingBody::setVelocityFromPosition()
{
	if (mMoveSpeed > 0.0f) {
		bool isTouchingGround = false;
		Vector3f dir(sinf(mKing->mFaceDirection), 0.0f, cosf(mKing->mFaceDirection));
		for (int i = 0; i < 2; i++) {
			if (mIsFootOnGround[i]) {
				isTouchingGround = true;
			}
		}

		if (isTouchingGround) {
			if (mKing->getOnWall()) {
				mKing->mTargetVelocity = ((mKing->getAnimTimer() * gsys->getFrameTime() * mMoveSpeed) / 5.0f) * dir;
			} else {
				mKing->mTargetVelocity = (mKing->getAnimTimer() * gsys->getFrameTime() * mMoveSpeed) * dir;
			}
		} else if (!mKing->getOnWall()) {
			mKing->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
			mKing->mVelocity.set(0.0f, 0.0f, 0.0f);
		}
	} else {
		mKing->mTargetVelocity.set(0.0f, 0.0f, 0.0f);
		mKing->mVelocity.set(0.0f, 0.0f, 0.0f);
	}

	mKing->setOnWall(false);
}

/**
 * @todo: Documentation
 */
void KingBody::emitOnGroundEffect()
{
	for (int i = 0; i < 2; i++) {
		if (mIsFootOnGround[i] && !mPrevIsFootOnGround[i]) {
			mFootMapAttr[i] = mKing->getMapAttribute(mFootPosList[i]);
			if (mFootMapAttr[i] == ATTR_Water) {
				createWaterEffect(i);
			} else {
				mIsFootGeneratingRipples[i] = false;
			}

			if (mKing->getCurrentState() > KINGAI_Die && mKing->getCurrentState() < KINGAI_Appear) {
				// i.e. not die, appear or stay
				Vector3f footPos = mFootPosList[i];
				footPos.y -= 5.0f;
				effectMgr->create(EffectMgr::EFF_King_StepCloud, footPos, nullptr, nullptr);
				if (mKing->mSeContext) {
					mKing->mSeContext->playSound(SE_KING_WALK);
				}
				rumbleMgr->start(RUMBLE_Unk4, 0, mKing->mSRT.t);
				cameraMgr->startVibrationEvent(3, mKing->mSRT.t);
			}
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D4
 */
void KingBody::emitSlipEffect()
{
	for (int i = 0; i < 2; i++) {
		if (mIsFootOnGround[i] && qdist2(mFootPosList[i].x, mFootPosList[i].z, mOldFootPosList[i].x, mOldFootPosList[i].z) > 2.0f) {
			Vector3f footPos = mFootPosList[i];
			footPos.y -= 5.0f;
			effectMgr->create(EffectMgr::EFF_King_Slip, footPos, nullptr, nullptr);
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000014
 */
void KingBody::copyOnGround()
{
	for (int i = 0; i < 2; i++) {
		mPrevIsFootOnGround[i] = mIsFootOnGround[i];
	}
}

/**
 * @todo: Documentation
 */
void KingBody::update()
{
	updateBlendingRatio();
	checkOnGround();
	setVelocityFromPosition();
	emitOnGroundEffect();
	emitSlipEffect();
	copyOnGround();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00012C
 */
void KingBody::makeAnimation(BossShapeObject* shapeObj, Graphics& gfx, Matrix4f* animMatrices)
{
	Matrix4f tmp;
	Matrix4f lookAtInv;
	gfx.mCamera->mLookAtMtx.inverse(&lookAtInv);
	for (int i = 0; i < 66; i++) {
		tmp = shapeObj->mShape->getAnimMatrix(i);
		NsCalculation::calcMtxBotIdent(tmp);
		lookAtInv.multiplyTo(tmp, animMatrices[i]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000AD0
 */
void KingBody::checkBlendingParm(Matrix4f* animMatrices)
{
	int i; // nishimura has a real holdover from C in pre-declaring these loop variables, damn
	if (mBlendingRatio == 0.0f) {
		for (i = 0; i < 66; i++) {
			mBlendStartMatrices[i] = animMatrices[i];
		}
	} else if (mIsBlending) {
		for (i = 0; i < 66; i++) {
			mBlendStartMatrices[i] = mBlendResultMatrices[i];
		}
		mIsBlending = false;
	}
}

/**
 * @todo: Documentation
 */
void KingBody::makeBlending(Matrix4f* animMatrices)
{
	if (mBlendingRatio > 0.0f) {
		f32 tComp = 1.0f - mBlendingRatio;
		Vector3f blendPositions[66];
		for (int i = 0; i < 66; i++) {
			blendPositions[i].x = mBlendingRatio * animMatrices[i].mMtx[0][3] + tComp * mBlendStartMatrices[i].mMtx[0][3];
			blendPositions[i].y = mBlendingRatio * animMatrices[i].mMtx[1][3] + tComp * mBlendStartMatrices[i].mMtx[1][3];
			blendPositions[i].z = mBlendingRatio * animMatrices[i].mMtx[2][3] + tComp * mBlendStartMatrices[i].mMtx[2][3];
		}

		for (int i = 0; i < 66; i++) {
			Vector3f colX;
			Vector3f colY;
			Vector3f colZ;

			NsCalculation::calcMtxTrans(animMatrices[i], 0, colX);
			NsCalculation::calcMtxTrans(animMatrices[i], 1, colY);
			NsCalculation::calcMtxTrans(animMatrices[i], 2, colZ);

			f32 xLen = colX.length();
			f32 yLen = colY.length();
			f32 zLen = colZ.length();

			Matrix3f mtx1;
			Matrix3f mtx2;
			Quat q1;
			Quat q2;

			Vector3f scales(xLen, yLen, zLen);
			NsCalculation::calcMat4toMat3(animMatrices[i], mtx1);
			q1.fromMat3f(mtx1);
			NsCalculation::calcMat4toMat3(mBlendStartMatrices[i], mtx2);
			q2.fromMat3f(mtx2);

			q2.slerp(q1, mBlendingRatio, 0);
			animMatrices[i].makeVQS(blendPositions[i], q2, scales);
			mBlendResultMatrices[i] = animMatrices[i];
		}
	}
}

/**
 * @todo: Documentation
 */
void KingBody::copyJointPosition(immut Matrix4f* animMatrices)
{
	// TODO: sort out what these joints correspond to
	mOldFootPosList[0] = mFootPosList[0];
	mOldFootPosList[1] = mFootPosList[1];

	NsCalculation::calcMtxTrans(animMatrices[3], 3, mFootPosList[0]);
	NsCalculation::calcMtxTrans(animMatrices[6], 3, mFootPosList[1]);
	NsCalculation::calcMtxTrans(animMatrices[31], 1, mNormalisedJointDir);

	mNormalisedJointDir.multiply(-1.0f);
	mNormalisedJointDir.normalise();

	for (int i = 3, j = 14; i > -1; --i, ++j) {
		NsCalculation::calcMtxTrans(animMatrices[j], 3, mSalivaJointPositions[i]);
	}

	mPrevSalivaEffectPos = mSalivaEffectPos;

	NsCalculation::calcMtxTrans(animMatrices[31], 3, mSalivaEffectPos);
	NsCalculation::calcMtxTrans(animMatrices[45], 3, mEyePositions[0]);
	NsCalculation::calcMtxTrans(animMatrices[51], 3, mEyePositions[1]);
	NsCalculation::calcMtxTrans(animMatrices[10], 3, mCheekPositions[0]);
	NsCalculation::calcMtxTrans(animMatrices[9], 3, mCheekPositions[1]);
	NsCalculation::calcMtxTrans(animMatrices[13], 3, mMouthPos);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080
 */
void KingBody::returnJoint(BossShapeObject* shapeObj, Graphics& gfx, immut Matrix4f* animMatrices)
{
	for (int i = 0; i < 66; i++) {
		Matrix4f& jointMtx = shapeObj->mShape->getAnimMatrix(i);
		gfx.mCamera->mLookAtMtx.multiplyTo(animMatrices[i], jointMtx);
	}
}

/**
 * @todo: Documentation
 */
void KingBody::refresh(BossShapeObject* shapeObj, Graphics& gfx)
{
	Matrix4f animMatrices[66];
	makeAnimation(shapeObj, gfx, animMatrices);
	checkBlendingParm(animMatrices);
	makeBlending(animMatrices);
	copyJointPosition(animMatrices);
	returnJoint(shapeObj, gfx, animMatrices);
}
