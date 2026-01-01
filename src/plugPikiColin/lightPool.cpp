#include "Camera.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "Light.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("LightPool");

/**
 * @todo: Documentation
 */
LightPool::LightPool()
{
	mFocusRotationAngle = TAU * gsys->getRand(1.0f);

	mCamera.mPosition.set(0.0f, 50.0f, 0.0f);
	mCamera.mFocus.set(0.0f, 10.0f, 0.00001f);
	mCamera.mRotation.set(0.0f, 0.0f, 0.0f);
	mCamera.mFov  = 5.0f;
	mCamera.mNear = 1.0f;
	mCamera.mFar  = 200.0f;

	mFlags = LightPoolFlags::DrawFrustum;
	mColour.set(255, 255, 64, 128);
}

/**
 * @todo: Documentation
 */
void LightPool::draw(Graphics& gfx)
{
	LightCamera* camera = &mCamera;
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	int oldBlend = gfx.setCBlending(BLEND_AlphaAdditive);
	gfx.setDepth(false);
	bool lighting = gfx.setLighting(false, nullptr);
	gfx.useTexture(mBoxTexture, GX_TEXMAP0);
	gfx.setColour(Colour(255, 255, 64, 64), true);
	gfx.setColour(mColour, true);

	Vector3f eyeVec = camera->mPosition - camera->mFocus;
	eyeVec.normalise();
	eyeVec.multiply(8.0f);
	Vector3f sideVec = camera->mPosition - camera->mFocus;
	sideVec.normalise();

	sideVec.CP(gfx.mCamera->mViewZAxis);
	sideVec.multiply(2.5f * camera->mFov);

	Vector2f texCoords[6];
	Vector3f boxPositions[6];

	boxPositions[0] = camera->mPosition + (sideVec + eyeVec);
	texCoords[0].set(0.0f, 0.0f);

	boxPositions[1] = camera->mPosition + (-(sideVec) + eyeVec);
	texCoords[1].set(1.0f, 0.0f);

	boxPositions[2] = camera->mFocus + (-(sideVec) + -(eyeVec));
	texCoords[2].set(1.0f, 1.0f);

	boxPositions[3] = camera->mFocus + (sideVec + -(eyeVec));
	texCoords[3].set(0.0f, 1.0f);

	gfx.drawOneTri(boxPositions, nullptr, texCoords, 4);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.useTexture(mParticleTexture, GX_TEXMAP0);
	gfx.setCBlending(BLEND_AdditiveNoZ);
	gfx.setColour(COLOUR_WHITE, true);

	if (gfx.initParticle(true)) {
		gfx.drawParticle(*gfx.mCamera, camera->mPosition, 80.0f);
	}

	gfx.setLighting(lighting, nullptr);
	gfx.setCBlending(oldBlend);
	gfx.setDepth(true);
	if (mFlags & LightPoolFlags::DrawFrustum) {
		gfx.setFog(false);
		camera->draw(gfx);
		gfx.setFog(true);
	}
}
