#include "DebugLog.h"
#include "EffectMgr.h"
#include "Graphics.h"
#include "MapCode.h"
#include "MapMgr.h"
#include "Matrix3f.h"
#include "NsMath.h"
#include "Pellet.h"
#include "RumbleMgr.h"
#include "Snake.h"
#include "SoundMgr.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("SnakeBody");

/**
 * @TODO: Documentation
 */
void SnakeBody::setBodyOnGroundEffect()
{
	mOnGroundCallBack->set(mSnake);
	zen::particleGenerator* groundPtclGen = effectMgr->create(EffectMgr::EFF_Snake_OnGround, mSnake->mSRT.t, mOnGroundCallBack, nullptr);
	if (groundPtclGen) {
		groundPtclGen->setEmitPosPtr(&mSnake->mSRT.t);
	}

	mRotateCallBack->set(mSnake);
	zen::particleGenerator* rotatePtclGen = effectMgr->create(EffectMgr::EFF_Snake_Rotate, mSnake->mSRT.t, mRotateCallBack, nullptr);
	if (rotatePtclGen) {
		rotatePtclGen->setEmitPosPtr(&mSnake->mSRT.t);
	}

	// water?
	if (mSnake->getMapAttribute(mSnake->mSRT.t) == ATTR_Water) {
		effectMgr->create(EffectMgr::EFF_Frog_BubbleRingS, mSnake->mSRT.t, nullptr, nullptr);
		zen::particleGenerator* waterPtclGen1 = effectMgr->create(EffectMgr::EFF_RippleWhite, mSnake->mSRT.t, mOnGroundCallBack, nullptr);
		if (waterPtclGen1) {
			waterPtclGen1->setEmitPosPtr(&mSnake->mSRT.t);
			waterPtclGen1->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = waterPtclGen1->getScaleSize();
			waterPtclGen1->setScaleSize(3.0f * f0);
		}
		zen::particleGenerator* waterPtclGen2 = effectMgr->create(EffectMgr::EFF_RippleSurface, mSnake->mSRT.t, mOnGroundCallBack, nullptr);
		if (waterPtclGen2) {
			waterPtclGen2->setEmitPosPtr(&mSnake->mSRT.t);
			waterPtclGen2->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = waterPtclGen2->getScaleSize();
			waterPtclGen2->setScaleSize(3.0f * f0);
		}
		zen::particleGenerator* waterPtclGen3 = effectMgr->create(EffectMgr::EFF_RippleBlack, mSnake->mSRT.t, mOnGroundCallBack, nullptr);
		if (waterPtclGen3) {
			waterPtclGen3->setEmitPosPtr(&mSnake->mSRT.t);
			waterPtclGen3->setOrientedNormalVector(Vector3f(0.0f, 1.0f, 0.0f));
			f32 f0 = waterPtclGen3->getScaleSize();
			waterPtclGen3->setScaleSize(3.0f * f0);
		}
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::killCallBackEffect(bool doForceFinish)
{
	effectMgr->kill(mOnGroundCallBack, nullptr, doForceFinish);
	effectMgr->kill(mRotateCallBack, nullptr, doForceFinish);
}

/**
 * @TODO: Documentation
 */
SnakeBody::SnakeBody(Snake* snake)
{
	mSnake            = snake;
	mOnGroundCallBack = new SnakeGenBodyOnGroundCallBack();
	mRotateCallBack   = new SnakeGenBodyRotateCallBack();
	mDeadPtclGens     = new zen::particleGenerator*[7];
}

/**
 * @TODO: Documentation
 */
void SnakeBody::init(immut Vector3f&, Snake* snake)
{
	mSnake         = snake;
	mIsDying       = false;
	mUseBlend      = false;
	mBlendingRatio = 0.0f;

	for (int i = 0; i < 7; i++) {
		mSegmentLengthList[i] = 0.0f;
		mDeadPtclGens[i]      = nullptr;
	}

	for (int i = 0; i < 8; i++) {
		mSegmentScaleList[i] = 1.0f;
	}

	mDeadEffectSegmentIndex = 7;
}

/**
 * @TODO: Documentation
 */
void SnakeBody::initBlending(f32 blendRate)
{
	if (mBlendingRatio > 0.0f) {
		mUseBlend = true;
	}

	mBlendingRatio = 0.00001f;
	mBlendingRate  = blendRate;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void SnakeBody::updateBlendingRatio()
{
	if (mBlendingRatio > 0.0f) {
		if (mBlendingRatio == 0.00001f && mSnake->getNextState() >= 2 && mSnake->getNextState() <= 3 && mSnake->mSeContext) {
			mSnake->mSeContext->playSound(SE_SNAKE_TURN);
		}

		mBlendingRatio += gsys->getFrameTime() * mBlendingRate;
		if (mBlendingRatio > 1.0f) {
			mBlendingRatio = 0.0f;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void SnakeBody::setInitializePosition()
{
	mSnake->mSRT.t.x = mSnake->getInitPosition()->x;
	mSnake->mSRT.t.z = mSnake->getInitPosition()->z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
void SnakeBody::copyAnimPosition()
{
	if (mSnake->getCurrentState() >= SNAKEAI_ChaseNavi && mSnake->getCurrentState() <= SNAKEAI_ChasePiki) {
		for (int i = 0; i < SnakeJointType::SegmentCount; i++) {
			for (int j = 0; j < 4; j++) {
				mSegmentMatrices[i].getColumn(j, mAnimPosList[i][j]);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void SnakeBody::makeHeadDirection()
{
	if (mSnake->getCurrentState() >= SNAKEAI_ChaseNavi && mSnake->getCurrentState() <= SNAKEAI_ChasePiki) {
		// Calculate the direction from the snake's neck to the target position
		mAnimPosList[SnakeJointType::Neck][0].sub(*mSnake->getTargetPosition(), mAnimPosList[SnakeJointType::Neck][3]);
		NsCalculation::calcOuterPro(mAnimPosList[SnakeJointType::Neck][0], mAnimPosList[SnakeJointType::Neck][1],
		                            mAnimPosList[SnakeJointType::Neck][2]);
		NsCalculation::calcOuterPro(mAnimPosList[SnakeJointType::Neck][2], mAnimPosList[SnakeJointType::Neck][0],
		                            mAnimPosList[SnakeJointType::Neck][1]);
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeTurnVelocity()
{
	if (mSnake->getCurrentState() >= SNAKEAI_ChaseNavi && mSnake->getCurrentState() <= SNAKEAI_ChasePiki) {
		Vector3f segmentOffset;

		// Calculate a reference point by averaging key positions along the snake's body:
		// - The neck (front)
		// - A mid-body segment
		// - The root (back)
		Vector3f centerOfMass
		    = (mAnimPosList[SnakeJointType::Neck][3] + mAnimPosList[SnakeJointType::Segment5][3] + mAnimPosList[SnakeJointType::Root][3])
		    / 3.0f;

		// Determine the direction the snake needs to move to reach its target
		// This creates the primary steering force that guides the snake's movement
		Vector3f targetDirection = mSnake->mSRT.t - *mSnake->getTargetPosition();
		targetDirection.normalise();

		for (int i = 1; i < 7; i++) {
			int j = i - 1;

			// Calculate how far this segment deviates from the snake's center line
			// This helps maintain the snake's natural sinuous movement pattern
			// by preventing segments from bunching up or stretching too far apart
			segmentOffset.sub(mAnimPosList[i][3], centerOfMass);
			segmentOffset.normalise();

			// Combine three influences to determine how this segment should turn:
			// 1. targetDirection: Pulls the segment toward the chase target
			// 2. segmentOffset: Maintains proper spacing between segments
			// 3. mAnimPosList[SnakeJointType::Neck][0]: Current neck orientation as reference
			// Together, these create a smooth, snake-like pursuit movement
			mSegmentTurnVelocityList[j]   = targetDirection + segmentOffset - mAnimPosList[SnakeJointType::Neck][0];
			mSegmentTurnVelocityList[j].y = 0.0f;        // Constrain movement to horizontal
			mSegmentTurnVelocityList[j].normalise();     // Scale to unit length
			mSegmentTurnVelocityList[j].multiply(10.0f); // Scale to desired speed
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void SnakeBody::makeNewPosition()
{
	if (mSnake->getCurrentState() >= SNAKEAI_ChaseNavi && mSnake->getCurrentState() <= SNAKEAI_ChasePiki) {
		for (int i = 1; i < 7; i++) {
			mAnimPosList[i][3].x += mSegmentPositionList[i + 7].x;
			mAnimPosList[i][3].y += mSegmentPositionList[i + 7].y;
			mAnimPosList[i][3].z += mSegmentPositionList[i + 7].z;
		}
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeResultPosition()
{
	if (mSnake->getCurrentState() >= SNAKEAI_ChaseNavi && mSnake->getCurrentState() <= SNAKEAI_ChasePiki) {
		Vector3f segmentDirection;
		Vector3f previousSegmentTarget;
		Vector3f nextSegmentTarget;
		Vector3f smoothPosList[7];

		// Multiple iterations are used to smooth out the snake's movement
		for (int i = 0; i < 10; i++) {

			// Process each segment except the head and tail
			int j;
			for (j = 1; j < 7; j++) {
				int prev = j - 1;
				int next = j + 1;

				// Calculate direction from current segment to previous segment
				segmentDirection.x = mAnimPosList[j][3].x - mAnimPosList[prev][3].x;
				segmentDirection.y = mAnimPosList[j][3].y - mAnimPosList[prev][3].y;
				segmentDirection.z = mAnimPosList[j][3].z - mAnimPosList[prev][3].z;
				segmentDirection.normalise();

				// Calculate target position based on previous segment
				previousSegmentTarget.x = mSegmentLengthList[prev] * segmentDirection.x + mAnimPosList[prev][3].x;
				previousSegmentTarget.y = mSegmentLengthList[prev] * segmentDirection.y + mAnimPosList[prev][3].y;
				previousSegmentTarget.z = mSegmentLengthList[prev] * segmentDirection.z + mAnimPosList[prev][3].z;

				// Calculate direction from current segment to next segment
				segmentDirection.x = mAnimPosList[j][3].x - mAnimPosList[next][3].x;
				segmentDirection.y = mAnimPosList[j][3].y - mAnimPosList[next][3].y;
				segmentDirection.z = mAnimPosList[j][3].z - mAnimPosList[next][3].z;
				segmentDirection.normalise();

				// Calculate target position based on next segment
				nextSegmentTarget.x = mSegmentLengthList[j] * segmentDirection.x + mAnimPosList[next][3].x;
				nextSegmentTarget.y = mSegmentLengthList[j] * segmentDirection.y + mAnimPosList[next][3].y;
				nextSegmentTarget.z = mSegmentLengthList[j] * segmentDirection.z + mAnimPosList[next][3].z;

				// Average the two target positions to get final smoothed positions
				smoothPosList[j].x = (previousSegmentTarget.x + nextSegmentTarget.x) * 0.5f;
				smoothPosList[j].y = (previousSegmentTarget.y + nextSegmentTarget.y) * 0.5f;
				smoothPosList[j].z = (previousSegmentTarget.z + nextSegmentTarget.z) * 0.5f;
			}

			// Update segment positions with smoothed values
			for (j = 1; j < 7; j++) {
				mAnimPosList[j][3].x = smoothPosList[j].x;
				mAnimPosList[j][3].y = smoothPosList[j].y;
				mAnimPosList[j][3].z = smoothPosList[j].z;
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeVectorMatrix()
{
	if (mSnake->getCurrentState() >= SNAKEAI_ChaseNavi && mSnake->getCurrentState() <= SNAKEAI_ChasePiki) {
		for (int i = 0; i < 8; i++) {
			if (i < 7) {
				mAnimPosList[i][0].sub(mAnimPosList[i + 1][3], mAnimPosList[i][3]);
			}

			if (i > 0) {
				mAnimPosList[i][2] = mSegmentTurnVelocityList[4 * i + 4];
				NsCalculation::calcOuterPro(mAnimPosList[i][2], mAnimPosList[i][0], mAnimPosList[i][1]);
				NsCalculation::calcOuterPro(mAnimPosList[i][0], mAnimPosList[i][1], mAnimPosList[i][2]);

			} else {
				mAnimPosList[i][2].x = cosf(mSnake->mFaceDirection);
				mAnimPosList[i][2].y = 0.0f;
				mAnimPosList[i][2].z = -sinf(mSnake->mFaceDirection);
				NsCalculation::calcOuterPro(mAnimPosList[i][2], mAnimPosList[i][0], mAnimPosList[i][1]);
				NsCalculation::calcOuterPro(mAnimPosList[i][0], mAnimPosList[i][1], mAnimPosList[i][2]);
			}

			mAnimPosList[i][0].normalise();
			mAnimPosList[i][1].normalise();
			mAnimPosList[i][2].normalise();
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void SnakeBody::createDeadPellet(immut Vector3f& pelletPos, int itemIdx)
{
	if (itemIdx >= 0) {
		int itemColour = mSnake->getItemColour();
		if (itemColour > PELCOLOUR_MAX || itemColour < PELCOLOR_MIN) {
			itemColour = NsMathI::getRand(3);
		}

		Pellet* newPellet = pelletMgr->newNumberPellet(itemColour, itemIdx);
		if (newPellet) {
			newPellet->init(pelletPos);
			newPellet->mVelocity.set(0.0f, 100.0f, 0.0f);
			newPellet->startAI(0);
		}
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::createDeadHeadEffect()
{
	Vector3f vec;
	f32 angle = mSnake->mFaceDirection - 0.5f;
	vec.x     = 30.0f * sinf(angle) + mSegmentPositionList[mDeadEffectSegmentIndex].x;
	vec.y     = 0.0f + mSegmentPositionList[mDeadEffectSegmentIndex].y;
	vec.z     = 30.0f * cosf(angle) + mSegmentPositionList[mDeadEffectSegmentIndex].z;
	effectMgr->create(EffectMgr::EFF_Snake_DeadHeadSpecks, vec, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Snake_DeadHeadFeathers, vec, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Snake_DeadHeadCloud, vec, nullptr, nullptr);
	rumbleMgr->start(RUMBLE_Unk14, 0, vec);

	createDeadPellet(vec, C_SNAKE_PROP(mSnake).mHeadPelletIndex());

	for (int i = 0; i < 7; i++) {
		mDeadPtclGens[i] = effectMgr->create(EffectMgr::EFF_Snake_DeadBodyExplode, vec, nullptr, nullptr);
		if (mDeadPtclGens[i]) {
			mDeadPtclGens[i]->stopGen();
		}
	}

	if (mSnake->mSeContext) {
		mSnake->mSeContext->playSound(SE_MAR_DROP);
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::createDeadBodyEffect()
{
	Vector3f vec;
	int next = mDeadEffectSegmentIndex + 1;
	vec.x    = (mSegmentPositionList[next].x + mSegmentPositionList[mDeadEffectSegmentIndex].x) / 2.0f;
	vec.y    = (mSegmentPositionList[next].y + mSegmentPositionList[mDeadEffectSegmentIndex].y) / 2.0f;
	vec.z    = (mSegmentPositionList[next].z + mSegmentPositionList[mDeadEffectSegmentIndex].z) / 2.0f;

	f32 minY = mapMgr->getMinY(vec.x, vec.z, true);
	if (minY > vec.y) {
		vec.y = minY;
	}

	if (mDeadPtclGens[mDeadEffectSegmentIndex]) {
		mDeadPtclGens[mDeadEffectSegmentIndex]->setEmitPos(vec);
		mDeadPtclGens[mDeadEffectSegmentIndex]->startGen();
	}

	effectMgr->create(EffectMgr::EFF_Snake_DeadBody1, vec, nullptr, nullptr);
	effectMgr->create(EffectMgr::EFF_Snake_DeadBody2, vec, nullptr, nullptr);
	rumbleMgr->start(RUMBLE_Unk15, 0, vec);

	createDeadPellet(vec, C_SNAKE_PROP(mSnake).mBodyPelletIndex());

	if (mSnake->mSeContext) {
		mSnake->mSeContext->playSound(SE_DORORO_WALK);
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeDeadPattern01()
{
	bool prev = mIsDying;
	mIsDying  = true;

	f32 scaleTime;
	f32 scaleSpeed;
	if (mDeadEffectSegmentIndex == 7) { // head
		scaleSpeed = C_SNAKE_PROP(mSnake).mDeadHeadScaleSpeed();
		scaleTime  = C_SNAKE_PROP(mSnake).mDeadHeadScaleTimer();
	} else { // body
		scaleSpeed = C_SNAKE_PROP(mSnake).mDeadBodyScaleSpeed();
		scaleTime  = C_SNAKE_PROP(mSnake).mDeadBodyScaleTimer()
		          - (6 - mDeadEffectSegmentIndex) * C_SNAKE_PROP(mSnake).mDeadBodyScaleSegmentRatio();
	}

	mSnake->addWalkTimer(gsys->getFrameTime());

	// take _30 to 0 with steps of size frameTime * b
	mSegmentScaleList[mDeadEffectSegmentIndex]
	    = NsLibMath<f32>::toGoal(mSegmentScaleList[mDeadEffectSegmentIndex], 0.0f, gsys->getFrameTime() * scaleSpeed);

	if (!prev && mIsDying) {
		if (mDeadEffectSegmentIndex == 7) {
			createDeadHeadEffect();
		} else {
			createDeadBodyEffect();
		}
	}

	if (mDeadEffectSegmentIndex > 0 && mSegmentScaleList[mDeadEffectSegmentIndex] == 0.0f && mSnake->getWalkTimer() > scaleTime) {
		mDeadEffectSegmentIndex--;
		mIsDying = false;
		mSnake->setWalkTimer(0.0f);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void SnakeBody::makeDeadPattern02()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void SnakeBody::makeDeadScaleParms()
{
	if (mSnake->getCurrentState() == SNAKEAI_Die && mSnake->getMotionFinish()) {
		makeDeadPattern01();
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::update()
{
	updateBlendingRatio();
	setInitializePosition();

	// issue is in copyAnimPosition
	copyAnimPosition();

	makeHeadDirection();
	makeTurnVelocity();
	makeNewPosition();
	makeResultPosition();
	makeVectorMatrix();
	makeDeadScaleParms();
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xB8(r1)
	  stw       r31, 0xB4(r1)
	  mr        r31, r3
	  lfs       f0, -0x554C(r2)
	  lfs       f1, 0xC(r3)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x90
	  lfs       f0, -0x5544(r2)
	  fcmpu     cr0, f0, f1
	  bne-      .loc_0x5C
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E8(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x5C
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x5C
	  lwz       r3, 0x2C(r3)
	  cmplwi    r3, 0
	  beq-      .loc_0x5C
	  li        r4, 0x38
	  bl        -0xBD370

	.loc_0x5C:
	  lwz       r3, 0x2DEC(r13)
	  lfs       f1, 0x10(r31)
	  lfs       f0, 0x28C(r3)
	  lfs       f2, 0xC(r31)
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0xC(r31)
	  lfs       f1, 0xC(r31)
	  lfs       f0, -0x5548(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x90
	  lfs       f0, -0x554C(r2)
	  stfs      f0, 0xC(r31)

	.loc_0x90:
	  lwz       r4, 0x0(r31)
	  lfs       f0, 0x300(r4)
	  stfs      f0, 0x94(r4)
	  lwz       r4, 0x0(r31)
	  lfs       f0, 0x308(r4)
	  stfs      f0, 0x9C(r4)
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x1C0
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x1C0
	  li        r0, 0x4
	  mtctr     r0
	  addi      r5, r31, 0
	  addi      r6, r31, 0

	.loc_0xD0:
	  lfs       f0, 0x284(r6)
	  addi      r3, r6, 0x284
	  addi      r7, r5, 0x128
	  stfs      f0, 0x104(r5)
	  addi      r4, r5, 0x134
	  addi      r9, r5, 0x140
	  lfs       f0, 0x294(r6)
	  addi      r6, r6, 0x40
	  addi      r8, r5, 0x14C
	  stfs      f0, 0x108(r5)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x10C(r5)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x110(r5)
	  lfs       f0, 0x14(r3)
	  stfs      f0, 0x114(r5)
	  lfs       f0, 0x24(r3)
	  stfs      f0, 0x118(r5)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x11C(r5)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x120(r5)
	  lfs       f0, 0x28(r3)
	  stfs      f0, 0x124(r5)
	  addi      r5, r5, 0x30
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x2C(r3)
	  addi      r3, r6, 0x284
	  addi      r6, r6, 0x40
	  stfs      f0, 0x8(r7)
	  addi      r7, r5, 0x128
	  addi      r5, r5, 0x30
	  lfs       f0, 0x0(r3)
	  stfs      f0, 0x0(r4)
	  lfs       f0, 0x10(r3)
	  stfs      f0, 0x4(r4)
	  lfs       f0, 0x20(r3)
	  stfs      f0, 0x8(r4)
	  lfs       f0, 0x4(r3)
	  stfs      f0, 0x0(r9)
	  lfs       f0, 0x14(r3)
	  stfs      f0, 0x4(r9)
	  lfs       f0, 0x24(r3)
	  stfs      f0, 0x8(r9)
	  lfs       f0, 0x8(r3)
	  stfs      f0, 0x0(r8)
	  lfs       f0, 0x18(r3)
	  stfs      f0, 0x4(r8)
	  lfs       f0, 0x28(r3)
	  stfs      f0, 0x8(r8)
	  lfs       f0, 0xC(r3)
	  stfs      f0, 0x0(r7)
	  lfs       f0, 0x1C(r3)
	  stfs      f0, 0x4(r7)
	  lfs       f0, 0x2C(r3)
	  stfs      f0, 0x8(r7)
	  bdnz+     .loc_0xD0

	.loc_0x1C0:
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x2C8
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x2C8
	  lfs       f0, 0x278(r31)
	  lfsu      f1, 0x30C(r3)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x254(r31)
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x27C(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x258(r31)
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x280(r31)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x25C(r31)
	  lfs       f3, 0x258(r31)
	  lfs       f2, 0x268(r31)
	  lfs       f1, 0x25C(r31)
	  lfs       f0, 0x264(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x26C(r31)
	  lfs       f3, 0x25C(r31)
	  lfs       f2, 0x260(r31)
	  lfs       f1, 0x254(r31)
	  lfs       f0, 0x268(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x270(r31)
	  lfs       f3, 0x254(r31)
	  lfs       f2, 0x264(r31)
	  lfs       f1, 0x258(r31)
	  lfs       f0, 0x260(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x274(r31)
	  lfs       f3, 0x270(r31)
	  lfs       f2, 0x25C(r31)
	  lfs       f1, 0x274(r31)
	  lfs       f0, 0x258(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x260(r31)
	  lfs       f3, 0x274(r31)
	  lfs       f2, 0x254(r31)
	  lfs       f1, 0x26C(r31)
	  lfs       f0, 0x25C(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x264(r31)
	  lfs       f3, 0x26C(r31)
	  lfs       f2, 0x258(r31)
	  lfs       f1, 0x270(r31)
	  lfs       f0, 0x254(r31)
	  fmuls     f2, f3, f2
	  fmuls     f0, f1, f0
	  fsubs     f0, f2, f0
	  stfs      f0, 0x268(r31)

	.loc_0x2C8:
	  mr        r3, r31
	  bl        -0x1268
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0x2
	  blt-      .loc_0x408
	  cmpwi     r0, 0x3
	  bgt-      .loc_0x408
	  lfs       f1, 0x158(r31)
	  lfs       f0, 0xBC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x158(r31)
	  lfs       f1, 0x15C(r31)
	  lfs       f0, 0xC0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x15C(r31)
	  lfs       f1, 0x160(r31)
	  lfs       f0, 0xC4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x160(r31)
	  lfs       f1, 0x188(r31)
	  lfs       f0, 0xC8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x188(r31)
	  lfs       f1, 0x18C(r31)
	  lfs       f0, 0xCC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x18C(r31)
	  lfs       f1, 0x190(r31)
	  lfs       f0, 0xD0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x190(r31)
	  lfs       f1, 0x1B8(r31)
	  lfs       f0, 0xD4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1B8(r31)
	  lfs       f1, 0x1BC(r31)
	  lfs       f0, 0xD8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1BC(r31)
	  lfs       f1, 0x1C0(r31)
	  lfs       f0, 0xDC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1C0(r31)
	  lfs       f1, 0x1E8(r31)
	  lfs       f0, 0xE0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1E8(r31)
	  lfs       f1, 0x1EC(r31)
	  lfs       f0, 0xE4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1EC(r31)
	  lfs       f1, 0x1F0(r31)
	  lfs       f0, 0xE8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x1F0(r31)
	  lfs       f1, 0x218(r31)
	  lfs       f0, 0xEC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x218(r31)
	  lfs       f1, 0x21C(r31)
	  lfs       f0, 0xF0(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x21C(r31)
	  lfs       f1, 0x220(r31)
	  lfs       f0, 0xF4(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x220(r31)
	  lfs       f1, 0x248(r31)
	  lfs       f0, 0xF8(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x248(r31)
	  lfs       f1, 0x24C(r31)
	  lfs       f0, 0xFC(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x24C(r31)
	  lfs       f1, 0x250(r31)
	  lfs       f0, 0x100(r31)
	  fadds     f0, f1, f0
	  stfs      f0, 0x250(r31)

	.loc_0x408:
	  mr        r3, r31
	  bl        -0x1090
	  mr        r3, r31
	  bl        -0xDA4
	  lwz       r3, 0x0(r31)
	  lwz       r0, 0x2E4(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x43C
	  lbz       r0, 0x2BD(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x43C
	  mr        r3, r31
	  bl        -0x5C8

	.loc_0x43C:
	  lwz       r0, 0xBC(r1)
	  lwz       r31, 0xB4(r1)
	  addi      r1, r1, 0xB8
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void SnakeBody::makeAnimation(BossShapeObject* shapeObj, Graphics& gfx)
{
	Matrix4f tmpMtx;
	Matrix4f invCamMtx;
	gfx.mCamera->mLookAtMtx.inverse(&invCamMtx);
	// why tho.
	for (int i = 0, j = 0; i < 8; i++, j++) {
		tmpMtx = shapeObj->mShape->getAnimMatrix(j);
		NsCalculation::calcMtxBotIdent(tmpMtx);
		invCamMtx.multiplyTo(tmpMtx, mSegmentMatrices[i]);
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeBodySize()
{
	if (mSegmentLengthList[0] == 0.0f) {
		Vector3f tmpVecs[8];
		int i;
		for (i = 0; i < 8; i++) {
			mSegmentMatrices[i].getColumn(3, tmpVecs[i]);
		}

		for (i = 0; i < 7; i++) {
			mSegmentLengthList[i] = tmpVecs[i].distance(tmpVecs[i + 1]);
		}
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeHeadPosition()
{
	if (mSnake->getCurrentState() == SNAKEAI_Attack) {
		f32 keyVals[5][3] = {
			{ 32.0f, 36.0f, 49.0f }, { 32.0f, 35.0f, 49.0f }, { 32.0f, 37.0f, 49.0f }, { 28.0f, 33.0f, 49.0f }, { 28.0f, 33.0f, 49.0f },
		};

		if (mSnake->mAnimator.getCounter() > keyVals[mSnake->mSnakeAi->mAttackId][0]
		    && mSnake->mAnimator.getCounter() < keyVals[mSnake->mSnakeAi->mAttackId][2]) {
			f32 yDiff = mSnake->mSnakeAi->mAttackPositions[mSnake->mSnakeAi->mAttackId].y - mSnake->mSRT.t.y;
			if (mSnake->mAnimator.getCounter() < keyVals[mSnake->mSnakeAi->mAttackId][1]) {
				mSegmentMatrices[SnakeJointType::Neck].mMtx[1][3]
				    += (mSnake->mAnimator.getCounter() - keyVals[mSnake->mSnakeAi->mAttackId][0])
				     / (keyVals[mSnake->mSnakeAi->mAttackId][1] - keyVals[mSnake->mSnakeAi->mAttackId][0]) * yDiff;
			} else {
				mSegmentMatrices[SnakeJointType::Neck].mMtx[1][3]
				    += (keyVals[mSnake->mSnakeAi->mAttackId][2] - mSnake->mAnimator.getCounter())
				     / (keyVals[mSnake->mSnakeAi->mAttackId][2] - keyVals[mSnake->mSnakeAi->mAttackId][1]) * yDiff;
			}
		}
	} else if (mSnake->getCurrentState() == SNAKEAI_Die && mSnake->mAnimator.getCounter() > 60.0f) {
		f32 yDiff = mSnake->mSnakeAi->mAttackPositions[1].y - mSnake->mSRT.t.y;
		if (mSnake->mAnimator.getCounter() < 70.0f) {
			mSegmentMatrices[SnakeJointType::Neck].mMtx[1][3] += (mSnake->mAnimator.getCounter() - 60.0f) / 10.0f * yDiff;
		} else {
			mSegmentMatrices[SnakeJointType::Neck].mMtx[1][3] += yDiff;
		}
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeBodyMatrix()
{
	if (mSnake->getCurrentState() == SNAKEAI_Attack || mSnake->getCurrentState() == SNAKEAI_Die) {
		Vector3f vec1;
		Vector3f vec2;
		Vector3f vec3;

		Vector3f vecArray[7];
		for (int i = 0; i < 10; i++) {
			int j;
			for (j = 1; j < 7; j++) {
				int prev = j - 1;
				int next = j + 1;
				vec1.x   = mSegmentMatrices[j].mMtx[0][3] - mSegmentMatrices[prev].mMtx[0][3];
				vec1.y   = mSegmentMatrices[j].mMtx[1][3] - mSegmentMatrices[prev].mMtx[1][3];
				vec1.z   = mSegmentMatrices[j].mMtx[2][3] - mSegmentMatrices[prev].mMtx[2][3];
				vec1.normalise();

				vec2.x = mSegmentLengthList[prev] * vec1.x + mSegmentMatrices[prev].mMtx[0][3];
				vec2.y = mSegmentLengthList[prev] * vec1.y + mSegmentMatrices[prev].mMtx[1][3];
				vec2.z = mSegmentLengthList[prev] * vec1.z + mSegmentMatrices[prev].mMtx[2][3];

				vec1.x = mSegmentMatrices[j].mMtx[0][3] - mSegmentMatrices[next].mMtx[0][3];
				vec1.y = mSegmentMatrices[j].mMtx[1][3] - mSegmentMatrices[next].mMtx[1][3];
				vec1.z = mSegmentMatrices[j].mMtx[2][3] - mSegmentMatrices[next].mMtx[2][3];
				vec1.normalise();

				vec3.x = mSegmentLengthList[j] * vec1.x + mSegmentMatrices[next].mMtx[0][3];
				vec3.y = mSegmentLengthList[j] * vec1.y + mSegmentMatrices[next].mMtx[1][3];
				vec3.z = mSegmentLengthList[j] * vec1.z + mSegmentMatrices[next].mMtx[2][3];

				vecArray[j].x = (vec2.x + vec3.x) * 0.5f;
				vecArray[j].y = (vec2.y + vec3.y) * 0.5f;
				vecArray[j].z = (vec2.z + vec3.z) * 0.5f;
			}

			for (j = 1; j < 7; j++) {
				mSegmentMatrices[j].mMtx[0][3] = vecArray[j].x;
				mSegmentMatrices[j].mMtx[1][3] = vecArray[j].y;
				mSegmentMatrices[j].mMtx[2][3] = vecArray[j].z;
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeAnimMatrix()
{
	if (mSnake->getCurrentState() == SNAKEAI_Attack || mSnake->getCurrentState() == SNAKEAI_Die) {
		Vector3f vecArray[8][4];
		int i;
		int j;
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 4; j++) {
				mSegmentMatrices[i].getColumn(j, vecArray[i][j]);
			}
		}
		for (i = 0; i < 7; i++) {
			vecArray[i][0].sub(vecArray[i + 1][3], vecArray[i][3]);
			NsCalculation::calcOuterPro(vecArray[i][2], vecArray[i][0], vecArray[i][1]);
			NsCalculation::calcOuterPro(vecArray[i][0], vecArray[i][1], vecArray[i][2]);

			vecArray[i][0].normalise();
			vecArray[i][1].normalise();
			vecArray[i][2].normalise();
		}

		for (i = 0; i < 7; i++) {
			for (j = 0; j < 3; j++) {
				mSegmentMatrices[i].setColumn(j, vecArray[i][j]);
			}
		}
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::caseOfMatrix(Matrix4f* animMatrices)
{
	if (mSnake->getCurrentState() >= SNAKEAI_ChaseNavi && mSnake->getCurrentState() <= SNAKEAI_ChasePiki) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 4; j++) {
				animMatrices[i].setColumn(j, mAnimPosList[i][j]);
			}
			NsCalculation::calcMtxBotIdent(animMatrices[i]);
		}
	} else {
		for (int i = 0; i < 8; i++) {
			animMatrices[i] = mSegmentMatrices[i];
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00082C
 */
void SnakeBody::checkBlendingParm(Matrix4f* animMatrices)
{
	int i;
	if (mBlendingRatio == 0.0f) {
		for (i = 0; i < 8; i++) {
			mPrevAnimMatrices[i] = animMatrices[i];
		}
	} else if (mUseBlend) {
		for (i = 0; i < 8; i++) {
			mPrevAnimMatrices[i] = mActiveAnimMatrices[i];
		}
		mUseBlend = false;
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::makeBlending(Matrix4f* animMatrices)
{
	int segIdx;

	if (mBlendingRatio > 0.0f) {
		// First, interpolate the positions of the segments based on the blending ratio
		f32 inverseBlendRatio = 1.0f - mBlendingRatio;
		for (segIdx = 0; segIdx < SnakeJointType::SegmentCount; segIdx++) {
			mSegmentPositionList[segIdx].x
			    = mBlendingRatio * animMatrices[segIdx].mMtx[0][3] + inverseBlendRatio * mPrevAnimMatrices[segIdx].mMtx[0][3];
			mSegmentPositionList[segIdx].y
			    = mBlendingRatio * animMatrices[segIdx].mMtx[1][3] + inverseBlendRatio * mPrevAnimMatrices[segIdx].mMtx[1][3];
			mSegmentPositionList[segIdx].z
			    = mBlendingRatio * animMatrices[segIdx].mMtx[2][3] + inverseBlendRatio * mPrevAnimMatrices[segIdx].mMtx[2][3];
		}

		// Then handle rotation and scaling for each segment
		for (segIdx = 0; segIdx < SnakeJointType::SegmentCount; segIdx++) {
			Matrix3f currRotMtx;
			Matrix3f prevRotMtx;
			Quat currRotQuat;
			Quat prevRotQuat;
			Vector3f scale(1.0f, 1.0f, 1.0f);

			// Extract rotation matrices from both animation states
			NsCalculation::calcMat4toMat3(animMatrices[segIdx], currRotMtx);
			currRotQuat.fromMat3f(currRotMtx);
			NsCalculation::calcMat4toMat3(mPrevAnimMatrices[segIdx], prevRotMtx);
			prevRotQuat.fromMat3f(prevRotMtx);

			// Interpolate the rotation matrices
			prevRotQuat.slerp(currRotQuat, mBlendingRatio, 0);

			// Calculate the scaling factor all segments except the neck
			if (segIdx < 7) {
				scale.x = mSegmentPositionList[segIdx].distance(mSegmentPositionList[segIdx + 1]) / mSegmentLengthList[segIdx];
			}

			// Construct the final matrix for the segment and store it in the active matrix list
			animMatrices[segIdx].makeVQS(mSegmentPositionList[segIdx], prevRotQuat, scale);
			mActiveAnimMatrices[segIdx] = animMatrices[segIdx];
		}
	} else {
		// If the blending ratio is 0, just copy the animation matrices to the active matrix list
		for (segIdx = 0; segIdx < SnakeJointType::SegmentCount; segIdx++) {
			mSegmentPositionList[segIdx].x = animMatrices[segIdx].mMtx[0][3];
			mSegmentPositionList[segIdx].y = animMatrices[segIdx].mMtx[1][3];
			mSegmentPositionList[segIdx].z = animMatrices[segIdx].mMtx[2][3];
		}
	}

	mNeckPosition = mSegmentPositionList[SnakeJointType::Neck];
}

/**
 * @TODO: Documentation
 */
void SnakeBody::setDeadPattern01(Matrix4f* animMatrices)
{
	for (int i = 0; i < 8; i++) {
		animMatrices[i].mMtx[0][0] *= mSegmentScaleList[i];
		animMatrices[i].mMtx[1][0] *= mSegmentScaleList[i];
		animMatrices[i].mMtx[2][0] *= mSegmentScaleList[i];
		animMatrices[i].mMtx[0][1] *= mSegmentScaleList[i];
		animMatrices[i].mMtx[1][1] *= mSegmentScaleList[i];
		animMatrices[i].mMtx[2][1] *= mSegmentScaleList[i];
		animMatrices[i].mMtx[0][2] *= mSegmentScaleList[i];
		animMatrices[i].mMtx[1][2] *= mSegmentScaleList[i];
		animMatrices[i].mMtx[2][2] *= mSegmentScaleList[i];

		if (i < 7) {
			animMatrices[i + 1].mMtx[0][3]
			    = (animMatrices[i + 1].mMtx[0][3] - animMatrices[i].mMtx[0][3]) * mSegmentScaleList[i] + animMatrices[i].mMtx[0][3];
			animMatrices[i + 1].mMtx[1][3]
			    = (animMatrices[i + 1].mMtx[1][3] - animMatrices[i].mMtx[1][3]) * mSegmentScaleList[i] + animMatrices[i].mMtx[1][3];
			animMatrices[i + 1].mMtx[2][3]
			    = (animMatrices[i + 1].mMtx[2][3] - animMatrices[i].mMtx[2][3]) * mSegmentScaleList[i] + animMatrices[i].mMtx[2][3];
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000268
 */
void SnakeBody::setDeadPattern02(Matrix4f*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void SnakeBody::setDeadScale(Matrix4f* animMatrices)
{
	if (mSnake->getCurrentState() == SNAKEAI_Die) {
		setDeadPattern01(animMatrices);
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::returnJoint(BossShapeObject* shapeObj, Graphics& gfx, immut Matrix4f* animMatrices)
{
	Matrix4f mtx1; // unused? lol.
	Matrix4f inv8;
	Matrix4f inv7;
	Matrix4f inv11;
	Matrix4f tmpMtx;

	shapeObj->mShape->getAnimMatrix(7).inverse(&inv7);
	shapeObj->mShape->getAnimMatrix(8).inverse(&inv8);
	shapeObj->mShape->getAnimMatrix(11).inverse(&inv11);

	int i, j; // why tho
	for (i = 0, j = 0; i < 8; i++, j++) {
		gfx.mCamera->mLookAtMtx.multiplyTo(animMatrices[i], shapeObj->mShape->getAnimMatrix(j));
	}

	inv7.multiplyTo(shapeObj->mShape->getAnimMatrix(8), tmpMtx);
	shapeObj->mShape->getAnimMatrix(7).multiplyTo(tmpMtx, shapeObj->mShape->getAnimMatrix(8));

	for (i = 9; i <= 10; i++) {
		inv8.multiplyTo(shapeObj->mShape->getAnimMatrix(i), tmpMtx);
		shapeObj->mShape->getAnimMatrix(8).multiplyTo(tmpMtx, shapeObj->mShape->getAnimMatrix(i));
	}

	inv7.multiplyTo(shapeObj->mShape->getAnimMatrix(11), tmpMtx);
	shapeObj->mShape->getAnimMatrix(7).multiplyTo(tmpMtx, shapeObj->mShape->getAnimMatrix(11));

	for (i = 12; i <= 14; i++) {
		inv11.multiplyTo(shapeObj->mShape->getAnimMatrix(i), tmpMtx);
		shapeObj->mShape->getAnimMatrix(11).multiplyTo(tmpMtx, shapeObj->mShape->getAnimMatrix(i));
	}
}

/**
 * @TODO: Documentation
 */
void SnakeBody::refresh(BossShapeObject* shapeObj, Graphics& gfx)
{
	Matrix4f animMatrices[8];
	makeAnimation(shapeObj, gfx);
	makeBodySize();
	makeHeadPosition();
	makeBodyMatrix();
	makeAnimMatrix();
	caseOfMatrix(animMatrices);
	checkBlendingParm(animMatrices);
	makeBlending(animMatrices);
	setDeadScale(animMatrices);
	returnJoint(shapeObj, gfx, animMatrices);
}
