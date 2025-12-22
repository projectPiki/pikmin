#include "Camera.h"
#include "DebugLog.h"
#include "Light.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F0
 */
DEFINE_PRINT(nullptr);

/**
 * @TODO: Documentation
 */
Light::Light()
    : CoreNode("light")
{
	_1C9 = 0;
	_1D8.set(0.0f, 0.0f, 0.0f);
	_240            = 60.0f;
	_244            = 1.0f;
	_248            = 1000.0f;
	mLightType      = 770;
	mMode           = 3;
	mDistancedRange = 3005.0f;
	mAttenuation    = 0.5036f;
	mSpotMode       = 2;
	mSpotAngle      = 45.0f;
	mConstantAttn   = 0.0f;
	mLinearAttn     = 0.0f;
	mQuadAttn       = 0.99559999f;
	mSpotConstTerm  = 1.0f;
	mSpotLinearTerm = 0.0f;
	mSpotQuadTerm   = 0.0f;
	_48             = 0.15f;
	_44             = 0.05f;
	mPosition.set(0.0f, 100.0f, 0.0f);
	mDirection.set(0.0f, -1.0f, 0.0f);
	mDiffuseColour.set(255, 255, 255, 255);

	setLightDistAttn(mDistancedRange, mAttenuation, mMode);
}

/**
 * @TODO: Documentation
 */
void Light::setLightDistAttn(f32 dist, f32 attn, int mode)
{
	mDistancedRange = dist;
	mAttenuation    = attn;
	mMode           = mode;

	if (dist < 0.0f) {
		mode = 0;
	}
	if (attn <= 0.0f || attn >= 1.0f) {
		mode = 0;
	}

	f32 constAttn;
	f32 linearAttn;
	f32 quadAttn;
	switch (mode) {
	case 1:
		constAttn  = 1.0f;
		quadAttn   = 0.0f;
		linearAttn = (1.0f - attn) / (attn * dist);
		break;
	case 2:
		constAttn  = 1.0f;
		linearAttn = 0.5f * (1.0f - attn) / (attn * dist);
		quadAttn   = 0.5f * (1.0f - attn) / (dist * (attn * dist));
		break;
	case 3:
		constAttn  = 1.0f;
		linearAttn = 0.0f;
		quadAttn   = (1.0f - attn) / (dist * (attn * dist));
		break;
	case 0:
	default:
		constAttn  = 1.0f;
		linearAttn = 0.0f;
		quadAttn   = 0.0f;
		break;
	}

	mConstantAttn   = constAttn;
	mLinearAttn     = linearAttn;
	mQuadAttn       = quadAttn;
	mLightValuesSet = 1;
}

/**
 * @TODO: Documentation
 */
void Light::setLightSpot(f32 angle, int spotMode)
{
	if (angle <= 0.0f || angle > 90.0f) {
		spotMode = 0;
	}

	f32 cosTheta = cosf((PI * angle) / 180.0f);
	f32 constTerm;
	f32 linearTerm;
	f32 quadTerm;
	switch (spotMode) {
	case 1:
		constTerm  = -1000.0f * cosTheta;
		linearTerm = 1000.0f;
		quadTerm   = 0.0f;
		break;
	case 2:
		constTerm  = -cosTheta / (1.0f - cosTheta);
		linearTerm = 1.0f / (1.0f - cosTheta);
		quadTerm   = 0.0f;
		break;
	case 3:
		constTerm  = 0.0f;
		linearTerm = -cosTheta / (1.0f - cosTheta);
		quadTerm   = 1.0f / (1.0f - cosTheta);
		break;
	case 4:
		f32 tmp    = SQUARE(1.0f - cosTheta);
		constTerm  = (cosTheta * (cosTheta - 2.0f)) / tmp;
		linearTerm = 2.0f / tmp;
		quadTerm   = -1.0f / tmp;
		break;
	case 5:
		constTerm  = -4.0f * cosTheta / SQUARE(1.0f - cosTheta);
		linearTerm = 4.0f * (1.0f + cosTheta) / SQUARE(1.0f - cosTheta);
		quadTerm   = -4.0f / SQUARE(1.0f - cosTheta);
		break;
	case 6:
		constTerm  = 1.0f - (2.0f * cosTheta * cosTheta) / SQUARE(1.0f - cosTheta);
		linearTerm = 4.0f * cosTheta / SQUARE(1.0f - cosTheta);
		quadTerm   = -2.0f / SQUARE(1.0f - cosTheta);
		break;
	case 0:
	default:
		constTerm  = 1.0f;
		linearTerm = 0.0f;
		quadTerm   = 0.0f;
		break;
	}

	mSpotConstTerm  = constTerm;
	mSpotLinearTerm = linearTerm;
	mSpotQuadTerm   = quadTerm;
	mLightValuesSet = 1;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00002C
 */
void Light::setLightParallel()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000218
 */
void Light::calcLightSizes()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
f32 Light::calcLightMapRadius()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000030
 */
f32 Light::calcLightObjRadius()
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0001C4
 */
void Light::refresh(Graphics&, LFlareGroup*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 */
void Light::update()
{
	switch (mLightType & 0xFF) {
	case 1:
		mConstantAttn = 1.0f;
		mLinearAttn = mQuadAttn = 0.0f;
		mSpotConstTerm          = 1.0f;
		mSpotLinearTerm = mSpotQuadTerm = 0.0f;
		mLightValuesSet                 = 1;
		break;
	case 2:
		setLightDistAttn(mDistancedRange, mAttenuation, mMode);
		mSpotConstTerm  = 1.0f;
		mSpotLinearTerm = mSpotQuadTerm = 0.0f;
		break;
	case 3:
		setLightSpot(mSpotAngle, mSpotMode);
		mConstantAttn = 1.0f;
		mLinearAttn = mQuadAttn = 0.0f;
		break;
	}
}
