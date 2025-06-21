#include "King.h"
#include "SoundMgr.h"
#include "Pellet.h"
#include "RadarInfo.h"
#include "Matrix3f.h"
#include "MapCode.h"
#include "NsMath.h"
#include "RumbleMgr.h"
#include "Graphics.h"
#include "Pcam/CameraManager.h"
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
 * Size:	0000F4
 */
DEFINE_PRINT("KingBody");

/*
 * --INFO--
 * Address:	........
 * Size:	00017C
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

/*
 * --INFO--
 * Address:	80172D84
 * Size:	0000DC
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

/*
 * --INFO--
 * Address:	80172E60
 * Size:	00024C
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

/*
 * --INFO--
 * Address:	801730AC
 * Size:	000210
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

/*
 * --INFO--
 * Address:	801732BC
 * Size:	000250
 */
void KingBody::createUfoParts()
{
	Pellet* ufoPart = pelletMgr->newPellet(mKing->mPelletID.mId, nullptr);
	if (ufoPart) {
		CollPart* nosePart = mKing->mCollInfo->getSphere('nose');
		f32 angle          = atan2f(nosePart->mCentre.x - mKing->mPosition.x, nosePart->mCentre.z - mKing->mPosition.z);
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

	mKing->mIsBossBgm = false;
	mKing->detachGenerator();
}

/*
 * --INFO--
 * Address:	8017350C
 * Size:	0000DC
 */
void KingBody::killCallBackEffect(bool p1)
{
	int i;
	for (i = 0; i < 3; i++) {
		effectMgr->kill(&mSalivaCallBacks[i], mSalivaParticleCallBack, p1);
	}

	effectMgr->kill(mSpreadSalivaCallBack, mSalivaParticleCallBack, p1);
	effectMgr->kill(mDamageStarCallBack, nullptr, p1);

	for (i = 0; i < 2; i++) {
		effectMgr->kill(&mRippleCallBacks[i], nullptr, p1);
	}
}

/*
 * --INFO--
 * Address:	801735E8
 * Size:	00023C
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

/*
 * --INFO--
 * Address:	8017385C
 * Size:	00023C
 */
void KingBody::init(King* king)
{
	mKing                 = king;
	mIsBlending           = 0;
	mBlendingRatio        = 0.0f;
	mMoveSpeed            = 0.0f;
	mDoFallSalivaEffect   = 0;
	mDoSpreadSalivaEffect = 0;

	for (int i = 0; i < 2; i++) {
		mPrevIsFootOnGround[i]      = 1;
		mIsFootOnGround[i]          = true;
		mIsFootGeneratingRipples[i] = false;
		mFootMapAttr[i]             = ATTR_NULL;
		mFootPosList[i].set(0.0f, 0.0f, 0.0f);
		mOldFootPosList[i].set(0.0f, 0.0f, 0.0f);
	}

	_UNUSED54.set(0.0f, 0.0f, 0.0f);
	setSalivaEffect();
}

/*
 * --INFO--
 * Address:	80173A98
 * Size:	000028
 */
void KingBody::initBlending(f32 blendRate)
{
	if (mBlendingRatio > 0.0f) {
		mIsBlending = 1;
	}
	mBlendingRatio = 0.00001f;
	mBlendingRate  = blendRate;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
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

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void KingBody::checkOnGround()
{
	for (int i = 0; i < 2; i++) {
		f32 heightDiff = mFootPosList[i].y - mKing->mPosition.y;
		if (heightDiff < 3.75f) {
			mIsFootOnGround[i] = true;
		} else if (heightDiff > 10.0f) {
			mIsFootOnGround[i] = false;
		}
	}
}

/*
 * --INFO--
 * Address:	80173AC0
 * Size:	0001E0
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

/*
 * --INFO--
 * Address:	80173CA0
 * Size:	000140
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
				rumbleMgr->start(RUMBLE_Unk4, 0, mKing->mPosition);
				cameraMgr->startVibrationEvent(3, mKing->mPosition);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
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

/*
 * --INFO--
 * Address:	........
 * Size:	000014
 */
void KingBody::copyOnGround()
{
	for (int i = 0; i < 2; i++) {
		mPrevIsFootOnGround[i] = mIsFootOnGround[i];
	}
}

/*
 * --INFO--
 * Address:	80173DE0
 * Size:	000198
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

/*
 * --INFO--
 * Address:	........
 * Size:	00012C
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

/*
 * --INFO--
 * Address:	........
 * Size:	000AD0
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

/*
 * --INFO--
 * Address:	80173F78
 * Size:	000578
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
			animMatrices[i].getColumn(0, colX);
			animMatrices[i].getColumn(1, colY);
			animMatrices[i].getColumn(2, colZ);

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

/*
 * --INFO--
 * Address:	801744F0
 * Size:	000230
 */
void KingBody::copyJointPosition(Matrix4f* animMatrices)
{
	// TODO: sort out what these joints correspond to
	mOldFootPosList[0] = mFootPosList[0];
	mOldFootPosList[1] = mFootPosList[1];

	animMatrices[3].getColumn(3, mFootPosList[0]);
	animMatrices[6].getColumn(3, mFootPosList[1]);
	animMatrices[31].getColumn(1, mNormalisedJointDir);

	mNormalisedJointDir.multiply(-1.0f);
	mNormalisedJointDir.normalise();

	animMatrices[14].getColumn(3, mSalivaJointPositions[3]);
	animMatrices[15].getColumn(3, mSalivaJointPositions[2]);
	animMatrices[16].getColumn(3, mSalivaJointPositions[1]);
	animMatrices[17].getColumn(3, mSalivaJointPositions[0]);

	mPrevSalivaEffectPos = mSalivaEffectPos;

	animMatrices[31].getColumn(3, mSalivaEffectPos);
	animMatrices[45].getColumn(3, mEyePositions[0]);
	animMatrices[51].getColumn(3, mEyePositions[1]);
	animMatrices[10].getColumn(3, mCheekPositions[0]);
	animMatrices[9].getColumn(3, mCheekPositions[1]);
	animMatrices[13].getColumn(3, mMouthPos);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void KingBody::returnJoint(BossShapeObject* shapeObj, Graphics& gfx, Matrix4f* animMatrices)
{
	for (int i = 0; i < 66; i++) {
		Matrix4f& jointMtx = shapeObj->mShape->getAnimMatrix(i);
		gfx.mCamera->mLookAtMtx.multiplyTo(animMatrices[i], jointMtx);
	}
}

/*
 * --INFO--
 * Address:	80174720
 * Size:	000C6C
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
