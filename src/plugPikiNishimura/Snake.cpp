#include "Snake.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Shape.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT("Snake");

/**
 * @todo: Documentation
 */
SnakeProp::SnakeProp()
{
	mCreatureProps.mFriction(1.0f);
	mCreatureProps.mFaceDirAdjust(0.0f);
	mCreatureProps.mAcceleration(1.0f);
}

/**
 * @todo: Documentation
 */
Snake::Snake(CreatureProp* props)
    : Boss(props)
{
	mCollInfo      = new CollInfo(24);
	mBoundsUpdater = new BoundSphereUpdater(this);
	mSnakeAi       = new SnakeAi(this);
	mSnakeBody     = new SnakeBody(this);
}

/**
 * @todo: Documentation
 * @param type `true` for sphere snake, `false` for box snake
 */
void Snake::setBossType(bool type)
{
	mBossType = type;
}

/**
 * @todo: Documentation
 */
f32 Snake::getCentreSize()
{
	return mBoundsUpdater->mSize;
}

/**
 * @todo: Documentation
 */
f32 Snake::getiMass()
{
	return 0.0001f;
}

/**
 * @todo: Documentation
 */
void Snake::init(immut Vector3f& pos)
{
	mCollisionRadius = 15.0f;
	setShadowSize(30.0f);
	mBossType      = true;
	_3C0           = mSRT.r.y;
	_3C4           = 0.0f;
	mSpawnPosition = pos;
	mSnakeAi->initAI(this);
	mSnakeBody->init(pos, this);
	mCollInfo->setUpdater('bnds', mBoundsUpdater);
	mCollInfo->makeTubesChild('tube', 7);
}

/**
 * @todo: Documentation
 */
void Snake::doKill()
{
	setIsAlive(false);
	setIsAtari(false);
	mSnakeBody->killCallBackEffect(false);
	bossMgr->kill(this);
}

/**
 * @todo: Documentation
 */
void Snake::exitCourse()
{
	mSnakeBody->killCallBackEffect(true);
}

/**
 * @todo: Documentation
 */
void Snake::update()
{
	doAI();
	moveVelocity();
	moveNew(gsys->getFrameTime());
	doAnimation();
}

/**
 * @todo: Documentation
 */
void Snake::refresh(Graphics& gfx)
{
	Matrix4f onCamMtx;
	mWorldMtx.makeSRT(mSRT.s, mSRT.r, mSRT.t);
	gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, onCamMtx);
	mAnimator.updateContext();
	mShapeObject->mShape->updateAnim(gfx, onCamMtx, nullptr);
	mSnakeBody->refresh(mShapeObject, gfx);
	mCollInfo->updateInfo(gfx, false);
}

/**
 * @todo: Documentation
 */
void Snake::drawShape(Graphics& gfx)
{
	mShapeObject->mShape->calcWeightedMatrices();
	gfx.useMatrix(Matrix4f::ident, 0);
	mShapeObject->mShape->drawshape(gfx, *gfx.mCamera, nullptr);

#if defined(DEVELOP) || defined(WIN32)
	Boss::drawShape(gfx);

	// This is really distracting to be enabled by default, so I've taken the liberty of adding a toggle.
#if !defined(BUILD_MATCHING)
	if (gsys->mToggleDebugInfo)
#endif
	{
		Matrix4f transformMtx;
		mWorldMtx.makeSRT(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(0.0f, 0.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f));
		gfx.mCamera->mLookAtMtx.multiplyTo(mWorldMtx, transformMtx);

		if (getCurrentState() == SNAKEAI_Under) {
			if (mBossType) {
				f32 detectionRadius    = SNAKE_PROP.mType1DetectionRadius();
				f32 maxAppearRadius    = SNAKE_PROP.mType1AppearDist() + detectionRadius;
				f32 maxTerritoryRadius = BOSS_PROP.mTerritoryRadius() + maxAppearRadius;

				gfx.setColour(Colour(255, 0, 0, 255), true);
				gfx.drawSphere(mSpawnPosition, detectionRadius, transformMtx);

				gfx.setColour(Colour(255, 255, 0, 255), true);
				gfx.drawSphere(mSpawnPosition, maxAppearRadius, transformMtx);

				gfx.setColour(Colour(0, 0, 255, 255), true);
				gfx.drawSphere(mSpawnPosition, maxTerritoryRadius, transformMtx);
			} else {
				Vector3f boxVerts[8];
				Vector3f boxSeam[2];

				f32 perpendicular = _3C0 + HALF_PI;
				Vector3f local_dc(sinf(_3C0), 0.0f, cosf(_3C0));
				Vector3f local_e8(sinf(perpendicular), 0.0f, cosf(perpendicular));

				boxVerts[0] = mSpawnPosition + SNAKE_PROP.mType2AppearFrontDist() * local_dc
				            + Vector3f(0.0f, SNAKE_PROP.mType2AppearVertDist(), 0.0f) - SNAKE_PROP.mType2AppearSideDist() * local_e8;
				boxVerts[1] = mSpawnPosition + SNAKE_PROP.mType2AppearFrontDist() * local_dc
				            + Vector3f(0.0f, -SNAKE_PROP.mType2AppearVertDist(), 0.0f) - SNAKE_PROP.mType2AppearSideDist() * local_e8;
				boxVerts[2] = mSpawnPosition + SNAKE_PROP.mType2AppearFrontDist() * local_dc
				            + Vector3f(0.0f, SNAKE_PROP.mType2AppearVertDist(), 0.0f) + SNAKE_PROP.mType2AppearSideDist() * local_e8;
				boxVerts[3] = mSpawnPosition + SNAKE_PROP.mType2AppearFrontDist() * local_dc
				            + Vector3f(0.0f, -SNAKE_PROP.mType2AppearVertDist(), 0.0f) + SNAKE_PROP.mType2AppearSideDist() * local_e8;
				boxVerts[4] = mSpawnPosition - SNAKE_PROP.mType2AppearFrontDist() * local_dc
				            + Vector3f(0.0f, SNAKE_PROP.mType2AppearVertDist(), 0.0f) - SNAKE_PROP.mType2AppearSideDist() * local_e8;
				boxVerts[5] = mSpawnPosition - SNAKE_PROP.mType2AppearFrontDist() * local_dc
				            + Vector3f(0.0f, -SNAKE_PROP.mType2AppearVertDist(), 0.0f) - SNAKE_PROP.mType2AppearSideDist() * local_e8;
				boxVerts[6] = mSpawnPosition - SNAKE_PROP.mType2AppearFrontDist() * local_dc
				            + Vector3f(0.0f, SNAKE_PROP.mType2AppearVertDist(), 0.0f) + SNAKE_PROP.mType2AppearSideDist() * local_e8;
				boxVerts[7] = mSpawnPosition - SNAKE_PROP.mType2AppearFrontDist() * local_dc
				            + Vector3f(0.0f, -SNAKE_PROP.mType2AppearVertDist(), 0.0f) + SNAKE_PROP.mType2AppearSideDist() * local_e8;

				boxSeam[0] = mSpawnPosition + SNAKE_PROP.mType2AppearFrontDist() * local_dc
				           + Vector3f(0.0f, SNAKE_PROP.mType2AppearVertDist(), 0.0f);
				boxSeam[1] = mSpawnPosition - SNAKE_PROP.mType2AppearFrontDist() * local_dc
				           + Vector3f(0.0f, SNAKE_PROP.mType2AppearVertDist(), 0.0f);

				gfx.setColour(Colour(255, 0, 0, 255), true);
				gfx.useMatrix(transformMtx, 0);

				gfx.drawLine(boxVerts[0], boxVerts[1]);
				gfx.drawLine(boxVerts[0], boxVerts[2]);
				gfx.drawLine(boxVerts[0], boxVerts[4]);
				gfx.drawLine(boxVerts[1], boxVerts[3]);
				gfx.drawLine(boxVerts[1], boxVerts[5]);
				gfx.drawLine(boxVerts[2], boxVerts[3]);
				gfx.drawLine(boxVerts[2], boxVerts[6]);
				gfx.drawLine(boxVerts[3], boxVerts[7]);
				gfx.drawLine(boxVerts[4], boxVerts[5]);
				gfx.drawLine(boxVerts[4], boxVerts[6]);
				gfx.drawLine(boxVerts[5], boxVerts[7]);
				gfx.drawLine(boxVerts[6], boxVerts[7]);

				gfx.setColour(Colour(255, 255, 0, 255), true);
				gfx.drawLine(boxSeam[0], boxSeam[1]);
			}
		}
		if (getCurrentState() != SNAKEAI_Under) {
			Vector3f boxVerts[8];

			Vector3f horizPos(mSRT.t);
			horizPos.y = 0.0f;

			u8 r[] = { 255, 000, 000, 255, 000 };
			u8 g[] = { 255, 000, 255, 000, 255 };
			u8 b[] = { 000, 255, 000, 255, 255 };

			for (int i = 0; i < 5; i++) {
				boxVerts[0] = horizPos + mSnakeAi->mAttackDists[i] * mSnakeAi->mSnakeFrontDir
				            + Vector3f(0.0f, mSnakeAi->mAttackPositions[i].y + mSnakeAi->mAttackHeights[i], 0.0f)
				            + mSnakeAi->mAttackMinus[i] * mSnakeAi->mSnakeSideDir;
				boxVerts[1] = horizPos + mSnakeAi->mAttackDists[i] * mSnakeAi->mSnakeFrontDir
				            + Vector3f(0.0f, mSnakeAi->mAttackPositions[i].y - mSnakeAi->mAttackHeights[i], 0.0f)
				            + mSnakeAi->mAttackMinus[i] * mSnakeAi->mSnakeSideDir;
				boxVerts[2] = horizPos + mSnakeAi->mAttackDists[i] * mSnakeAi->mSnakeFrontDir
				            + Vector3f(0.0f, mSnakeAi->mAttackPositions[i].y + mSnakeAi->mAttackHeights[i], 0.0f)
				            + mSnakeAi->mAttackPlus[i] * mSnakeAi->mSnakeSideDir;
				boxVerts[3] = horizPos + mSnakeAi->mAttackDists[i] * mSnakeAi->mSnakeFrontDir
				            + Vector3f(0.0f, mSnakeAi->mAttackPositions[i].y - mSnakeAi->mAttackHeights[i], 0.0f)
				            + mSnakeAi->mAttackPlus[i] * mSnakeAi->mSnakeSideDir;
				boxVerts[4] = horizPos + mSnakeAi->mAttackLimits[i] * mSnakeAi->mSnakeFrontDir
				            + Vector3f(0.0f, mSnakeAi->mAttackPositions[i].y + mSnakeAi->mAttackHeights[i], 0.0f)
				            + mSnakeAi->mAttackMinus[i] * mSnakeAi->mSnakeSideDir;
				boxVerts[5] = horizPos + mSnakeAi->mAttackLimits[i] * mSnakeAi->mSnakeFrontDir
				            + Vector3f(0.0f, mSnakeAi->mAttackPositions[i].y - mSnakeAi->mAttackHeights[i], 0.0f)
				            + mSnakeAi->mAttackMinus[i] * mSnakeAi->mSnakeSideDir;
				boxVerts[6] = horizPos + mSnakeAi->mAttackLimits[i] * mSnakeAi->mSnakeFrontDir
				            + Vector3f(0.0f, mSnakeAi->mAttackPositions[i].y + mSnakeAi->mAttackHeights[i], 0.0f)
				            + mSnakeAi->mAttackPlus[i] * mSnakeAi->mSnakeSideDir;
				boxVerts[7] = horizPos + mSnakeAi->mAttackLimits[i] * mSnakeAi->mSnakeFrontDir
				            + Vector3f(0.0f, mSnakeAi->mAttackPositions[i].y - mSnakeAi->mAttackHeights[i], 0.0f)
				            + mSnakeAi->mAttackPlus[i] * mSnakeAi->mSnakeSideDir;

				gfx.setColour(Colour(r[i], g[i], b[i], 255), true);

				gfx.drawSphere(mSnakeAi->mAttackPositions[i], 5.0f, transformMtx);

				gfx.useMatrix(transformMtx, 0);

				gfx.drawLine(boxVerts[0], boxVerts[1]);
				gfx.drawLine(boxVerts[0], boxVerts[2]);
				gfx.drawLine(boxVerts[0], boxVerts[4]);
				gfx.drawLine(boxVerts[1], boxVerts[3]);
				gfx.drawLine(boxVerts[1], boxVerts[5]);
				gfx.drawLine(boxVerts[2], boxVerts[3]);
				gfx.drawLine(boxVerts[2], boxVerts[6]);
				gfx.drawLine(boxVerts[3], boxVerts[7]);
				gfx.drawLine(boxVerts[4], boxVerts[5]);
				gfx.drawLine(boxVerts[4], boxVerts[6]);
				gfx.drawLine(boxVerts[5], boxVerts[7]);
				gfx.drawLine(boxVerts[6], boxVerts[7]);
			}
		}
	}
#endif
}

/**
 * @todo: Documentation
 */
void Snake::refresh2d(Graphics& gfx)
{
	mLifeGauge.mPosition = mSRT.t;
	mLifeGauge.mPosition.y += BOSS_PROP.mLifeGaugeHeight();
	mLifeGauge.mScale = BOSS_PROP.mLifeGaugeScale() * _3C4 / gfx.mCamera->mNear;
	mLifeGauge.refresh(gfx);
}

/**
 * @todo: Documentation
 */
void Snake::doAI()
{
	mSnakeAi->update();
}

/**
 * @todo: Documentation
 */
void Snake::doAnimation()
{
	if (mShapeObject) {
		mAnimator.animate(getAnimTimer());
	}

	mSnakeBody->update();
}
