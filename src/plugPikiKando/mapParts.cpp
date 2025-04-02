#include "MapMgr.h"
#include "Font.h"
#include "DebugLog.h"
#include "Graphics.h"

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
DEFINE_PRINT("mapParts")

char* MapParts::shapeFiles[4] = {
	"mapparts/cone.mod",
	"mapparts/cylinder.mod",
	"mapparts/cube.mod",
	"mapparts/board.mod",
};

/*
 * --INFO--
 * Address:	801184A8
 * Size:	000018
 */
char* MapParts::getShapeFile(int idx)
{
	return shapeFiles[idx];
}

/*
 * --INFO--
 * Address:	801184C0
 * Size:	00005C
 */
void MapParts::applyVelocity(Plane&, Vector3f&, Vector3f& force)
{
	mVelocity = mVelocity + force;
}

/*
 * --INFO--
 * Address:	8011851C
 * Size:	000078
 */
MapEntity::MapEntity(Shape* shape)
    : MapParts(shape)
{
	mVelocity.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80118594
 * Size:	000100
 */
void MapEntity::update()
{
	mPosition = mPosition + gsys->getFrameTime() * mVelocity;
	mVelocity = mVelocity - mVelocity * 0.1f;
	DynCollShape::update();
}

/*
 * --INFO--
 * Address:	80118694
 * Size:	0000D0
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

/*
 * --INFO--
 * Address:	80118764
 * Size:	000040
 */
void MapSlider::init()
{
	if (mCurrentPart) {
		mPosition      = mCurrentPart->mStartPosition;
		mCurrentTimer  = mHoldTime1;
		mStateMode     = 2;
		mDirectionMode = 1;
	}
}

/*
 * --INFO--
 * Address:	801187A4
 * Size:	00036C
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
				mStateMode    = 3;
				mCurrentTimer = holdTime;
			}
			break;
		case 2:
			mCurrentTimer -= gsys->getFrameTime();
			mVelocity.set(0.0f, 0.0f, 0.0f);
			if (mMoveMode == 1 || mDirectionMode == 1) {
				if (mCurrentTimer < 0.0f && activationReached) {
					mDirectionMode = (mDirectionMode == 1) ? 0 : 1;
					mStateMode     = mDirectionMode;
				} else if (mActivationCount >= 1 && !activationReached) {
					mCurrentTimer = holdTime;
				}
			} else if (mCurrentTimer < 0.0f) {
				mDirectionMode = (mDirectionMode == 1) ? 0 : 1;
				mStateMode     = mDirectionMode;
			}
			break;
		case 3:
			mVelocity.set(0.0f, 0.0f, 0.0f);
			if (!mContactCount) {
				mStateMode    = 2;
				mCurrentTimer = holdTime;
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

/*
 * --INFO--
 * Address:	80118B10
 * Size:	0001EC
 */
void MapSlider::refresh(Graphics& gfx)
{
	Vector3f textPos(0.0f, 20.0f, 0.0f);
	textPos.multMatrix(mWorldMatrix);
	bool light = gfx.setLighting(false, nullptr);
	gfx.useMatrix(Matrix4f::ident, 0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.useTexture(gsys->mConsFont->mTexture, 0);
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
