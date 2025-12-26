#include "DebugLog.h"
#include "Font.h"
#include "Graphics.h"
#include "MapMgr.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("mapParts")

immut char* MapParts::shapeFiles[4] = {
	"mapparts/cone.mod",
	"mapparts/cylinder.mod",
	"mapparts/cube.mod",
	"mapparts/board.mod",
};

/**
 * @todo: Documentation
 */
immut char* MapParts::getShapeFile(int idx)
{
	return shapeFiles[idx];
}

/**
 * @todo: Documentation
 */
void MapParts::applyVelocity(immut Plane&, immut Vector3f&, immut Vector3f& force)
{
	mVelocity = mVelocity + force;
}

/**
 * @todo: Documentation
 */
MapEntity::MapEntity(Shape* shape)
    : MapParts(shape)
{
	mVelocity.set(0.0f, 0.0f, 0.0f);
}

/**
 * @todo: Documentation
 */
void MapEntity::update()
{
	mPosition = mPosition + gsys->getFrameTime() * mVelocity;
	mVelocity = mVelocity - mVelocity * 0.1f;
	DynCollShape::update();
}

/**
 * @todo: Documentation
 */
MapSlider::MapSlider(Shape* shape, int activationCount, int triggerCount, f32 holdTime1, f32 holdTime2, f32 moveSpeed, int moveMode)
    : MapParts(shape)
{
	mActivationCount = activationCount;
	mTriggerCount    = triggerCount;
	mHoldTime1       = holdTime1;
	mHoldTime2       = holdTime2;
	mMoveSpeed       = moveSpeed;
	mMoveMode        = moveMode;
	mFaceDirection   = 0.0f;
}

/**
 * @todo: Documentation
 */
void MapSlider::init()
{
	if (mCurrentPart) {
		mPosition = mCurrentPart->mStartPosition;
		PRINT("MapSlider init() : t(%.1f %.1f %.1f)\n", mPosition.x, mPosition.y, mPosition.z);
		mTimer         = mHoldTime1;
		mStateMode     = 2;
		mDirectionMode = 1;
	}
}

/**
 * @todo: Documentation
 */
void MapSlider::update()
{
	bool activationReached = mContactCount >= mActivationCount;
	bool triggerReached    = mContactCount >= mTriggerCount;

	f32 holdTime;
	if (mDirectionMode == 1) {
		holdTime = mHoldTime1;
	} else {
		holdTime = mHoldTime2;
	}

	if (mCurrentPart) {
		mPosition = mPosition + mVelocity * gsys->getFrameTime();

		Vector3f targetPosition;
		targetPosition = (mDirectionMode == 1) ? mCurrentPart->mStartPosition : mCurrentPart->mEndPosition;

		Vector3f dir = targetPosition - mPosition;
		f32 distance = dir.normalise();
		mVelocity    = dir * mMoveSpeed;

		switch (mStateMode) {
		case 0:
		case 1:
			if (distance < 1.0f) {
				mStateMode = 3;
				mTimer     = holdTime;
			}
			break;
		case 2:
			mTimer -= gsys->getFrameTime();
			mVelocity.set(0.0f, 0.0f, 0.0f);
			if (mMoveMode == 1 || mDirectionMode == 1) {
				if (mTimer < 0.0f && activationReached) {
					mDirectionMode = (mDirectionMode == 1) ? 0 : 1;
					mStateMode     = mDirectionMode;
				} else if (mActivationCount >= 1 && !activationReached) {
					mTimer = holdTime;
				}
			} else if (mTimer < 0.0f) {
				mDirectionMode = (mDirectionMode == 1) ? 0 : 1;
				mStateMode     = mDirectionMode;
			}
			break;
		case 3:
			mVelocity.set(0.0f, 0.0f, 0.0f);
			if (!mContactCount) {
				mStateMode = 2;
				mTimer     = holdTime;
			}
			break;
		}
	} else {
		mFaceDirection += gsys->getFrameTime();
		mRotation.z = mFaceDirection * 0.5f;
		mPosition.x = mSliderPosition.x;
		mPosition.y = mSliderPosition.y;
		mPosition.z = mSliderPosition.z;
	}

	DynCollShape::update();
}

/**
 * @todo: Documentation
 */
void MapSlider::refresh(Graphics& gfx)
{
	Vector3f textPos(0.0f, 20.0f, 0.0f);
	textPos.multMatrix(mWorldMatrix);
	bool light = gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.setColour(COLOUR_WHITE, true);
	gfx.useTexture(gsys->mConsFont->mTexture, GX_TEXMAP0);
	int blend = gfx.setCBlending(0);

	char buf[256];
	int dist = mActivationCount - mContactCount;
	if (dist < 0) {
		dist = 0;
	}

	sprintf(buf, "%d to go!\n", dist);
	int width = -(gsys->mConsFont->stringWidth(buf) / 2);
	gfx.perspPrintf(gsys->mConsFont, textPos, width, 0, buf);

	gfx.setCBlending(blend);
	gfx.setLighting(light, nullptr);
	gfx.useMatrix(mWorldMatrix, 0);
	DynCollShape::refresh(gfx);
}
