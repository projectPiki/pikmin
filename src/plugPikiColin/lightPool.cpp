#include "Light.h"

#include "Camera.h"
#include "DebugLog.h"
#include "Graphics.h"

/**
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("LightPool");

/**
 * @brief Constructs a light pool with default settings and random starting orbit angle. Will draw debug frustum by default.
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

	// debug drawing is on by default, funnily enough
	mFlags = LightPoolFlags::DrawDebugFrustum;
	mColour.set(255, 255, 64, 128);
}

/**
 * @brief Renders the light pool, including its beam box, particle, and debug frustum if required.
 *
 * @param gfx Graphics context for rendering.
 */
void LightPool::draw(Graphics& gfx)
{
	LightCamera* camera = &mCamera;
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	// prepare graphics settings
	int oldBlend = gfx.setCBlending(BLEND_AlphaAdditive);
	gfx.setDepth(false);
	bool lighting = gfx.setLighting(false, nullptr);

	// draw "box" - rectangle showing the light's "beam" from its camera to the focus
	gfx.useTexture(mBeamTexture, GX_TEXMAP0);
	gfx.setColour(Colour(255, 255, 64, 64), true);
	gfx.setColour(mColour, true);

	Vector3f eyeDirection = camera->mPosition - camera->mFocus;
	eyeDirection.normalise();
	eyeDirection.multiply(8.0f);

	Vector3f sideVec = camera->mPosition - camera->mFocus;
	sideVec.normalise();

	sideVec.CP(gfx.mCamera->mViewZAxis);
	sideVec.multiply(2.5f * camera->mFov);

	// only 4 of these are used
	Vector2f texCoords[6];
	Vector3f boxPositions[6];

	// behind camera, to the right
	boxPositions[0] = camera->mPosition + (sideVec + eyeDirection);
	texCoords[0].set(0.0f, 0.0f);

	// behind camera, to the left
	boxPositions[1] = camera->mPosition + (-(sideVec) + eyeDirection);
	texCoords[1].set(1.0f, 0.0f);

	// in front of camera, to the left
	boxPositions[2] = camera->mFocus + (-(sideVec) + -(eyeDirection));
	texCoords[2].set(1.0f, 1.0f);

	// in front of camera, to the right
	boxPositions[3] = camera->mFocus + (sideVec + -(eyeDirection));
	texCoords[3].set(0.0f, 1.0f);

	gfx.drawOneTri(boxPositions, nullptr, texCoords, 4);

	// draw particles
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.useTexture(mParticleTexture, GX_TEXMAP0);
	gfx.setCBlending(BLEND_AdditiveNoZ);
	gfx.setColour(COLOUR_WHITE, true);

	if (gfx.initParticle(true)) {
		gfx.drawParticle(*gfx.mCamera, camera->mPosition, 80.0f);
	}

	// restore settings
	gfx.setLighting(lighting, nullptr);
	gfx.setCBlending(oldBlend);
	gfx.setDepth(true);

	// draw debug frustum if required
	if (mFlags & LightPoolFlags::DrawDebugFrustum) {
		gfx.setFog(false);
		camera->draw(gfx);
		gfx.setFog(true);
	}
}
