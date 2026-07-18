#include "DebugLog.h"
#include "Graphics.h"
#include "Matrix3f.h"
#include "zen/particle.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(29)

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("particleGenerator")

static u8 lpsPos[48] ATTRIBUTE_ALIGN(32) = {
	255, 231, 0, 25, 0,   0,   0, 25, 0, 25, 0, 0,  0, 25, 255, 231, 0, 0,  255, 231, 255, 231, 0,   0,
	0,   0,   0, 25, 255, 231, 0, 0,  0, 25, 0, 25, 0, 0,  255, 231, 0, 25, 0,   0,   255, 231, 255, 231,
};

static u8 lpsCoord[8] ATTRIBUTE_ALIGN(32) = {
	0, 0, 1, 0, 1, 1, 0, 1,
};

static inline void readDDF_U32(u32* outVal, u8*& data, u32 size)
{
	*outVal = *((u32*)data);
	data += size;
}

static inline void readDDF_Vector(Vector3f* outVec, u8*& data)
{
	outVec->set(u32ToFloat(((u32*)data)[0]), u32ToFloat(((u32*)data)[1]), u32ToFloat(((u32*)data)[2]));
	data += sizeof(Vector3f);
}

static inline void readDDF_Float(f32* outVal, u8*& data, u32 size)
{
	*outVal = u32ToFloat(((u32*)data)[0]);
	data += size;
}

static inline void readDDF_U8(u8* outVal, u8*& data, u32 size)
{
	*outVal = (data)[0];
	data += size;
}

static inline void readDDF_FloatArray(f32** outArray, u8*& data, u32 size)
{
	*outArray = (f32*)(data);
	for (u32 i = 0; i < size; i++) {
		data += 4;
	}
}

static inline void readDDF_Short(s16* outVal, u8*& data, u32 size)
{
	*outVal = *(s16*)data;
	data += size;
}

static inline void readDDF_Colour(Colour* outColour, u8*& data, u32 size)
{
	outColour->r = (data)[0];
	outColour->g = (data)[1];
	outColour->b = (data)[2];
	outColour->a = (data)[3];
	data += size;
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::init(u8* data, Texture* tex1, Texture* tex2, immut Vector3f& pos, zen::particleMdlManager* mdlMgr,
                                  zen::CallBack1<zen::particleGenerator*>* cb1,
                                  zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cb2)
{
	if (data) {
		// this is unreachable in the DLL, had to do some digging to drag it out
		if (false) {
			PRINT("VERSION FLAG [%s]\n", "1-01"); // The actual code is more nuanced (array of strings, but it always loads the first one?)
			ERROR(" [%c%c%c%c] is wrong pcr version.\n", data[0], data[1], data[2], data[3]);
		}

		ClearPtclsStatus(tex1, tex2);
		mControlFlags = PTCLCTRL_Active | PTCLCTRL_Visible;

		if (data[6]) {
			mAnimData.set(&data[8]);
			mDrawCallBack = &particleGenerator::drawPtclBillboard;
		} else {
			STACK_PAD_VAR(1);
			mLengthScale  = u32ToFloat(((u32*)data)[2]);
			mPivotOffsetY = u32ToFloat(((u32*)data)[3]);
			mAnimData.set(&data[16]);

			static_cast<bool>(data);

			u32 rotType                            = mAnimData.mFlags.bits.mRotationType & 0x7;
			mOrientedDrawConfig.mOrientationSource = mAnimData.mFlags.bits.mOrientationSource;
			mOrientedDrawConfig.mIsDoubleSided     = mAnimData.mFlags.bits.mIsDoubleSided;
			mOrientedDrawConfig.mFlipNormal        = 0;
			mAnimData.mFlags.all &= 0x1;
			mDrawCallBack = &particleGenerator::drawPtclOriented;

			switch (rotType) {
			case 0:
			{
				mRotAxisCallBack = &particleGenerator::RotAxisY;
				break;
			}
			case 1:
			{
				mRotAxisCallBack = &particleGenerator::RotAxisX;
				break;
			}
			case 2:
			{
				mRotAxisCallBack = &particleGenerator::RotAxisZ;
				break;
			}
			case 3:
			{
				mRotAxisCallBack = &particleGenerator::RotAxisXY;
				break;
			}
			case 4:
			{
				mRotAxisCallBack = &particleGenerator::RotAxisXZ;
				break;
			}
			case 5:
			{
				mRotAxisCallBack = &particleGenerator::RotAxisYZ;
				break;
			}
			case 6:
			{
				mRotAxisCallBack = &particleGenerator::RotAxisXYZ;
				break;
			}
#if defined(VERSION_GPIJ01) || defined(VERSION_PIKIDEMO)
			default:
			{
				ERROR("Unknown RotAxis Type:%d \n", rotType);
				break;
			}
#endif
			}
		}

		pmSetDDF(&data[((u16*)data)[2]]);
		mMdlMgr  = mdlMgr;
		mEmitPos = pos;
		setCallBack(cb1, cb2);
	}
}

/**
 * @todo: Documentation
 */
bool zen::particleGenerator::update(f32 timeStep)
{
	bool res = false;
	if (!(mControlFlags & PTCLCTRL_Stop)) {
		if (!(mControlFlags & PTCLCTRL_Finished)) {
			if (!(mControlFlags & PTCLCTRL_GenStopped)) {
				SetPtclsLife();
			}
		} else if (mPtclMdlListManager.getOrigin() == mPtclMdlListManager.getTopList()
		           && mPtclChildListManager.getOrigin() == mPtclChildListManager.getTopList()) {
			mControlFlags ^= ~PTCLCTRL_Active;
			res = true;
		}

		UpdatePtclsStatus(timeStep);
		if (!(mControlFlags & PTCLCTRL_GenStopped)) {
			mPassTimer += timeStep;
		}
		mCurrentFrame = mPassTimer;
		if (mCurrentFrame >= mMaxFrame) {
			mPassTimer    = 0.0f;
			mCurrentFrame = 0;
			if (++mCurrentPass >= mMaxPasses) {
				if (mMaxPasses) {
					mCurrentPass = mMaxPasses;
					finish();
				}
			}
		}

		if (!(mControlFlags & PTCLCTRL_Finished) && mCallBack1) {
			mCallBack1->invoke(this);
		}
	}

	return res;
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::draw(Graphics& gfx)
{
	if (mControlFlags & PTCLCTRL_Visible) {
		bool light = gfx.setLighting(false, nullptr);
		int blend  = gfx.setCBlending(BLEND_Additive);
		gfx.setDepth(false);

		if (mChildTexture) {
			gfx.useTexture(mChildTexture, GX_TEXMAP0);
		} else {
			gfx.useTexture(mTexture, GX_TEXMAP0);
		}
		drawPtclChildren(gfx);

		gfx.useTexture(mTexture, GX_TEXMAP0);
		(this->*mDrawCallBack)(gfx);

		gfx.setDepth(true);
		gfx.setCBlending(blend);
		gfx.setLighting(light, nullptr);
	}
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::pmSetDDF(u8* data)
{
	if (!data) {
		return;
	}

	readDDF_U32(&mParticleFlags, data, 4);
	readDDF_Vector(&mEmitPosOffset, data);
	readDDF_Vector(&mEmitDir, data);
	readDDF_Vector(&mEmissionBoxSize, data);
	readDDF_Float(&mEmissionSpread, data, 4);

	if (mParticleFlags & (PTCLFLAG_EmissionRateManual | PTCLFLAG_EmissionRateLinear)) {
		readDDF_U8(&mEmissionRateKeyCount, data, 4);
		readDDF_FloatArray(&mEmissionRateKeyframes, data, mEmissionRateKeyCount);
		readDDF_FloatArray(&mEmissionRateValues, data, mEmissionRateKeyCount);
	} else {
		readDDF_Float(&mEmissionRate, data, 4);
	}

	readDDF_Float(&mEmissionRateJitter, data, 4);
	readDDF_Float(&mEmissionRadiusScale, data, 4);

	if (mParticleFlags & (PTCLFLAG_EmissionRadiusManual | PTCLFLAG_EmissionRadiusLinear)) {
		readDDF_U8(&mEmissionRadiusKeyCount, data, 4);
		readDDF_FloatArray(&mEmissionRadiusKeyframes, data, mEmissionRadiusKeyCount);
		readDDF_FloatArray(&mEmissionRadiusValues, data, mEmissionRadiusKeyCount);
	} else {
		readDDF_Float(&mEmissionRadius, data, 4);
	}

	if (mParticleFlags & (PTCLFLAG_InitVelocityManual | PTCLFLAG_InitVelocityLinear)) {
		readDDF_U8(&mInitialVelocityKeyCount, data, 4);
		readDDF_FloatArray(&mInitVelIntpThresholds, data, mInitialVelocityKeyCount);
		readDDF_FloatArray(&mInitVelIntpValues, data, mInitialVelocityKeyCount);
	} else {
		readDDF_Float(&mInitVel, data, 4);
	}

	readDDF_Float(&mInitialVelocityJitter, data, 4);
	readDDF_Float(&mDrag, data, 4);
	readDDF_Float(&mDragJitter, data, 4);
	readDDF_Float(&mMaxVel, data, 4);
	readDDF_Float(&mScaleThreshold1, data, 4);
	readDDF_Float(&mScaleThreshold2, data, 4);
	readDDF_Float(&mMinScaleFactor1, data, 4);
	readDDF_Float(&mMinScaleFactor2, data, 4);
	readDDF_Float(&mScaleSize, data, 4);
	readDDF_Float(&mSizeJitter, data, 4);
	readDDF_Float(&mAlphaThreshold1, data, 4);
	readDDF_Float(&mAlphaThreshold2, data, 4);
	readDDF_Float(&mAlphaJitter, data, 4);
	readDDF_Float(&mLifetimeJitter, data, 4);

	readDDF_Short(&mRotSpeedMin, data, 2);
	readDDF_Short(&mRotSpeedJitter, data, 2);
	readDDF_Short(&mRotAngle, data, 2);
	readDDF_Short(&mBaseLifetime, data, 2);
	readDDF_Short(&mMaxFrame, data, 2);
	readDDF_U8(&mFreePtclMotionTime, data, 1);
	readDDF_U8(&_UNUSED112, data, 1);
	readDDF_U8(&mMaxPasses, data, 1);
	readDDF_U8(&mBlendFactor, data, 1);
	readDDF_U8(&mZMode, data, 2);

	if (mParticleFlags & PTCLFLAG_UseGravityField) {
		readDDF_Vector(&mGravFieldAccel, data);
	}

	if (mParticleFlags & PTCLFLAG_UseAirField) {
		readDDF_Vector(&mAirFieldVelocity, data);
	}

	if (mParticleFlags & PTCLFLAG_UseVortexField) {
		readDDF_Vector(&mVortexCenter, data);
		readDDF_Float(&mVortexRotationSpeed, data, 4);
		readDDF_Float(&mVortexStrength, data, 4);
		readDDF_Float(&mVortexFalloffFactor, data, 4);
		readDDF_Float(&mVortexFalloffDivisor, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_UseDampedNewtonField) {
		readDDF_Vector(&mDampedNewtonFieldDir, data);
		readDDF_Float(&mDampedNewtonFieldStrength, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_UseNewtonField) {
		readDDF_Vector(&mNewtonFieldDir, data);
		readDDF_Float(&mNewtonFieldStrength, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_UseSolidTexField) {
		readDDF_Vector(&mSolidFieldForceMultiplier, data);
		readDDF_U8(&mSolidFieldGridScale, data, 1);
		readDDF_U8(&mSolidFieldType, data, 1);
		readDDF_U8(&mSolidFieldSampleOffset, data, 2);
		mSolidTexFieldData = UseSolidTex[mSolidFieldType];
	}

	if (mParticleFlags & PTCLFLAG_UseJitterField) {
		readDDF_Float(&mJitterStrength, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_UseLineField) {
		readDDF_Vector(&mLineFieldAxis, data);
		readDDF_Float(&mLineFieldAxialForce, data, 4);
		readDDF_Float(&mLineFieldRadialForce, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_EnableChildParticles) {
		readDDF_Float(&mChildScaleFactor, data, 4);
		readDDF_Float(&mChildAlphaMultiplier, data, 4);
		readDDF_Float(&mChildPosJitter, data, 4);
		readDDF_Colour(&mChildColor, data, 4);
		readDDF_U8(&_124, data, 1);
		readDDF_U8(&mChildSpawnInterval, data, 3);
	}

	f32 len;
	if (mParticleFlags & PTCLFLAG_UseVortexField) {
		len = mVortexCenter.x * mVortexCenter.x + mVortexCenter.y * mVortexCenter.y + mVortexCenter.z * mVortexCenter.z;
		if (len == 0.0f) {
			pmGetArbitUnitVec(mVortexCenter);
		} else {
			len = std::sqrtf(len);
			mVortexCenter.x /= len;
			mVortexCenter.y /= len;
			mVortexCenter.z /= len;
		}
	}

	if (mParticleFlags & PTCLFLAG_UseLineField) {
		len = mLineFieldAxis.x * mLineFieldAxis.x + mLineFieldAxis.y * mLineFieldAxis.y + mLineFieldAxis.z * mLineFieldAxis.z;
		if (len == 0.0f) {
			pmGetArbitUnitVec(mLineFieldAxis);
		} else {
			len = std::sqrtf(len);
			mLineFieldAxis.x /= len;
			mLineFieldAxis.y /= len;
			mLineFieldAxis.z /= len;
		}
	}

	mScaleRate1 = (mScaleThreshold1 == 0.0f) ? 1.0f : (1.0f - mMinScaleFactor1) / mScaleThreshold1;
	mScaleRate2 = (mScaleThreshold2 == 1.0f) ? 1.0f : (1.0f - mMinScaleFactor2) / (1.0f - mScaleThreshold2);
	mAlphaRate1 = (mAlphaThreshold1 == 0.0f) ? 1.0f : 1.0f / mAlphaThreshold1;
	mAlphaRate2 = (mAlphaThreshold2 == 1.0f) ? 1.0f : 1.0f / (1.0f - mAlphaThreshold2);

	STACK_PAD_VAR(6);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000074
 */
f32 zen::particleGenerator::pmIntpManual(f32* frameThresholds, f32* values)
{
	int i;
	for (i = 1; mCurrentFrame > mMaxFrame * frameThresholds[i]; i++) {
		;
	}
	return values[i - 1];
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A0
 */
f32 zen::particleGenerator::pmIntpLinear(f32* frameThresholds, f32* values)
{
	int i;
	f32 ratio = f32(mCurrentFrame) / f32(mMaxFrame);
	for (i = 1; ratio > frameThresholds[i]; i++) {
		;
	}
	return (values[i] * (ratio - frameThresholds[i - 1]) + values[i - 1] * (frameThresholds[i] - ratio))
	     / (frameThresholds[i] - frameThresholds[i - 1]);
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::SetPtclsLife()
{
	if (mParticleFlags & PTCLFLAG_DisableEmission) {
		return;
	}

	f32 a;
	if (mParticleFlags & (PTCLFLAG_EmissionRateManual | PTCLFLAG_EmissionRateLinear)) {
		if (mParticleFlags & PTCLFLAG_EmissionRateManual) {
			a = pmIntpManual(mEmissionRateKeyframes, mEmissionRateValues);
		} else {
			a = pmIntpLinear(mEmissionRateKeyframes, mEmissionRateValues);
		}
	} else {
		a = mEmissionRate;
	}

	int i = 0;
	mPartialParticleCount += a + RandShift(a * mEmissionRateJitter);
	int max               = mPartialParticleCount;
	mPartialParticleCount = mPartialParticleCount - max;

	(void)max;
	for (i = 0; i < max; i++) {
		particleMdl* ptcl = pmGetParticle();
		if (ptcl) {
			ptcl->mLifeTime = mBaseLifetime * (1.0f - Rand(mLifetimeJitter));
			ptcl->mBBoardColourAnim.init(&mAnimData, ptcl->mLifeTime);
			PtclsGen(ptcl);
			if (mCallBack2) {
				mCallBack2->invoke(this, ptcl);
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::PtclsGen(zen::particleMdl* ptcl)
{
	Vector3f ptclPos;
	Vector3f ptclVel;
	Vector3f emitDir;
	Vector3f tmp4;
	Vector3f tmp5;
	Vector3f tmp6;
	f32 scale;
	f32 c;
	f32 initVel;
	f32 b;
	emitDir.x = mEmitDir.x;
	emitDir.y = mEmitDir.y;
	emitDir.z = mEmitDir.z;
	scale     = emitDir.x * emitDir.x + emitDir.y * emitDir.y + emitDir.z * emitDir.z;
	if (scale == 0.0f) {
		pmGetArbitUnitVec(emitDir);
	} else {
		scale = std::sqrtf(scale);
		emitDir.x /= scale;
		emitDir.y /= scale;
		emitDir.z /= scale;
	}

	tmp4.x = mEmissionBoxSize.x;
	tmp4.y = mEmissionBoxSize.y;
	tmp4.z = mEmissionBoxSize.z;

	if (mParticleFlags & (PTCLFLAG_InitVelocityManual | PTCLFLAG_InitVelocityLinear)) {
		if (mParticleFlags & PTCLFLAG_InitVelocityManual) {
			initVel = pmIntpManual(mInitVelIntpThresholds, mInitVelIntpValues);
		} else {
			initVel = pmIntpLinear(mInitVelIntpThresholds, mInitVelIntpValues);
		}
	} else {
		initVel = mInitVel;
	}

	if (mParticleFlags & (PTCLFLAG_EmissionRadiusManual | PTCLFLAG_EmissionRadiusLinear)) {
		if (mParticleFlags & PTCLFLAG_EmissionRadiusManual) {
			b = pmIntpManual(mEmissionRadiusKeyframes, mEmissionRadiusValues);
		} else {
			b = pmIntpLinear(mEmissionRadiusKeyframes, mEmissionRadiusValues);
		}
	} else {
		b = mEmissionRadius;
	}

	c = mEmissionRadiusScale * b;

	if (int(mParticleFlags & (PTCLFLAG_EmitShapeSphere | PTCLFLAG_EmitShapeBox)) == 1) {
		if (int(mParticleFlags & (PTCLFLAG_VelDirOmni | PTCLFLAG_VelDirDirectional)) == 4) {
			pmGetArbitUnitVec(ptclVel);
			tmp5.x = ptclVel.x;
			tmp5.y = ptclVel.y;
			tmp5.z = ptclVel.z;

			scale = c + Rand(b - c);
			tmp5.x *= scale;
			tmp5.y *= scale;
			tmp5.z *= scale;

			ptclPos.x = mEmitPosOffset.x + tmp5.x;
			ptclPos.y = mEmitPosOffset.y + tmp5.y;
			ptclPos.z = mEmitPosOffset.z + tmp5.z;

			scale = initVel + RandShift(initVel * mInitialVelocityJitter);
			ptclVel.x *= scale;
			ptclVel.y *= scale;
			ptclVel.z *= scale;

		} else if (int(mParticleFlags & (PTCLFLAG_VelDirOmni | PTCLFLAG_VelDirDirectional)) == 8) {
			ptclPos.x = mEmitPosOffset.x;
			ptclPos.y = mEmitPosOffset.y;
			ptclPos.z = mEmitPosOffset.z;
			pmGetArbitUnitVec(tmp5);
			tmp5.cross(tmp5, emitDir);

			scale = Rand(mEmissionSpread);
			tmp5.x *= scale;
			tmp5.y *= scale;
			tmp5.z *= scale;

			ptclVel.x = emitDir.x + tmp5.x;
			ptclVel.y = emitDir.y + tmp5.y;
			ptclVel.z = emitDir.z + tmp5.z;

			ptclVel.normalize();

			scale = initVel + RandShift(initVel * mInitialVelocityJitter);
			ptclVel.x *= scale;
			ptclVel.y *= scale;
			ptclVel.z *= scale;

		} else {
			pmGetArbitUnitVec(tmp5);
			ptclVel.cross(tmp5, emitDir);
			scale = ptclVel.x * ptclVel.x + ptclVel.y * ptclVel.y + ptclVel.z * ptclVel.z;
			if (scale == 0.0f) {
				ptcl->mLifeTime = 1;
				ptcl->mAge      = 0;
				ptcl->mAgeTimer = 0.0f;
			} else {
				scale = std::sqrtf(scale);
				ptclVel.x /= scale;
				ptclVel.y /= scale;
				ptclVel.z /= scale;
			}

			tmp5.x = ptclVel.x;
			tmp5.y = ptclVel.y;
			tmp5.z = ptclVel.z;
			scale  = c + Rand(b - c);
			tmp5.x *= scale;
			tmp5.y *= scale;
			tmp5.z *= scale;

			ptclPos.x = mEmitPosOffset.x + tmp5.x;
			ptclPos.y = mEmitPosOffset.y + tmp5.y;
			ptclPos.z = mEmitPosOffset.z + tmp5.z;

			scale = initVel + RandShift(initVel * mInitialVelocityJitter);
			ptclVel.x *= scale;
			ptclVel.y *= scale;
			ptclVel.z *= scale;
		}
	} else if (int(mParticleFlags & (PTCLFLAG_EmitShapeSphere | PTCLFLAG_EmitShapeBox)) == 2) {
		ptclPos.x = RandShift(1.0f) * tmp4.x + mEmitPosOffset.x;
		ptclPos.y = RandShift(1.0f) * tmp4.y + mEmitPosOffset.y;
		ptclPos.z = RandShift(1.0f) * tmp4.z + mEmitPosOffset.z;

		scale     = initVel + RandShift(initVel * mInitialVelocityJitter);
		ptclVel.x = emitDir.x * scale;
		ptclVel.y = emitDir.y * scale;
		ptclVel.z = emitDir.z * scale;
	} else {
		f32 d = mEmissionRadiusScale;
		pmGetArbitUnitVec(tmp5);
		ptclVel.cross(tmp5, emitDir);
		scale = ptclVel.x * ptclVel.x + ptclVel.y * ptclVel.y + ptclVel.z * ptclVel.z;
		if (scale == 0.0f) {
			ptcl->mLifeTime = 1;
			ptcl->mAge      = 0;
			ptcl->mAgeTimer = 0.0f;

		} else {
			scale = std::sqrtf(scale);
			ptclVel.x /= scale;
			ptclVel.y /= scale;
			ptclVel.z /= scale;
		}

		scale  = RandShift(1.0f) * tmp4.y;
		tmp6.x = emitDir.x * scale + ptclVel.x * tmp4.x;
		tmp6.y = emitDir.y * scale + ptclVel.y * tmp4.x;
		tmp6.z = emitDir.z * scale + ptclVel.z * tmp4.x;

		scale     = 1.0f + Rand(d - 1.0f);
		ptclPos.x = tmp6.x * scale + mEmitPosOffset.x;
		ptclPos.y = tmp6.y * scale + mEmitPosOffset.y;
		ptclPos.z = tmp6.z * scale + mEmitPosOffset.z;

		if (int(mParticleFlags & (PTCLFLAG_VelDirOmni | PTCLFLAG_VelDirDirectional)) == 8) {
			scale     = initVel + RandShift(initVel * mInitialVelocityJitter);
			ptclVel.x = emitDir.x * scale;
			ptclVel.y = emitDir.y * scale;
			ptclVel.z = emitDir.z * scale;
		} else {
			scale = initVel + RandShift(initVel * mInitialVelocityJitter);
			ptclVel.x *= scale;
			ptclVel.y *= scale;
			ptclVel.z *= scale;
		}
	}

	ptclVel.add(mEmitVelocity);

	ptcl->mLocalPosition.x = ptclPos.x;
	ptcl->mLocalPosition.y = ptclPos.y;
	ptcl->mLocalPosition.z = ptclPos.z;
	ptcl->mVelocity.x      = ptclVel.x;
	ptcl->mVelocity.y      = ptclVel.y;
	ptcl->mVelocity.z      = ptclVel.z;
	ptcl->mSize            = (mSizeJitter - 2.0f * mSizeJitter * RandShift(1.0f)) * mScaleSize + mScaleSize;
	if (ptcl->mSize < 0.0f) {
		ptcl->mSize = 0.0f;
	}

	ptcl->mRotSpeed       = f32(mRotSpeedMin) + f32(mRotSpeedJitter) * RandShift(1.0f);
	ptcl->mRotAngle       = f32(mRotAngle) * RandShift(1.0f);
	ptcl->_UNUSED4C       = Rand(_UNUSED112);
	ptcl->mOrientedNormal = mOrientedNormal;
	ptcl->mGlobalPosition = getGPos();
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::pmCalcAccel(zen::particleMdl* ptcl)
{
	if (mParticleFlags & PTCLFLAG_UseGravityField) {
		ptcl->mAcceleration.x += mGravFieldAccel.x;
		ptcl->mAcceleration.y += mGravFieldAccel.y;
		ptcl->mAcceleration.z += mGravFieldAccel.z;
	}

	f32 diffX, diffY, diffZ;
	if (mParticleFlags & PTCLFLAG_UseVortexField) {
		f32 scale = mVortexCenter.dot(ptcl->mLocalPosition);
		Vector3f vortexForce;
		vortexForce.x = ptcl->mLocalPosition.x - mVortexCenter.x * scale;
		vortexForce.y = ptcl->mLocalPosition.y - mVortexCenter.y * scale;
		vortexForce.z = ptcl->mLocalPosition.z - mVortexCenter.z * scale;

		scale = vortexForce.x * vortexForce.x + vortexForce.y * vortexForce.y + vortexForce.z * vortexForce.z;
		f32 v = (mVortexFalloffDivisor == 0.0f)
		          ? 1.0f
		          : (mVortexFalloffFactor * mVortexFalloffDivisor - scale) / (mVortexFalloffDivisor + scale) + 1.0f;

		scale = mVortexStrength * v;
		vortexForce.x *= scale;
		vortexForce.y *= scale;
		vortexForce.z *= scale;

		f32 rotAngle = mVortexRotationSpeed * v;
		f32 sinTheta = sinf(rotAngle);
		f32 cosTheta = cosf(rotAngle);
		f32 cosComp  = 1.0f - cosTheta;

		f32 axisX = mVortexCenter.x;
		f32 axisY = mVortexCenter.y;
		f32 axisZ = mVortexCenter.z;

		diffX = ptcl->mLocalPosition.x;
		diffY = ptcl->mLocalPosition.y;
		diffZ = ptcl->mLocalPosition.z;

		ptcl->mLocalPosition.x = (cosComp * axisX * axisX + cosTheta) * diffX + (cosComp * axisX * axisY + sinTheta * axisZ) * diffY
		                       + (cosComp * axisX * axisZ - sinTheta * axisY) * diffZ + vortexForce.x;
		ptcl->mLocalPosition.y = (cosComp * axisX * axisY - sinTheta * axisZ) * diffX + (cosComp * axisY * axisY + cosTheta) * diffY
		                       + (cosComp * axisY * axisZ + sinTheta * axisX) * diffZ + vortexForce.y;
		ptcl->mLocalPosition.z = (cosComp * axisX * axisZ + sinTheta * axisY) * diffX + (cosComp * axisY * axisZ - sinTheta * axisX) * diffY
		                       + (cosComp * axisZ * axisZ + cosTheta) * diffZ + vortexForce.z;
	}

	if (mParticleFlags & PTCLFLAG_UseDampedNewtonField) {
		ptcl->mAcceleration.x += (mDampedNewtonFieldDir.x - ptcl->mLocalPosition.x) * mDampedNewtonFieldStrength - ptcl->mVelocity.x;
		ptcl->mAcceleration.y += (mDampedNewtonFieldDir.y - ptcl->mLocalPosition.y) * mDampedNewtonFieldStrength - ptcl->mVelocity.y;
		ptcl->mAcceleration.z += (mDampedNewtonFieldDir.z - ptcl->mLocalPosition.z) * mDampedNewtonFieldStrength - ptcl->mVelocity.z;
	}

	if (mParticleFlags & PTCLFLAG_UseNewtonField) {
		ptcl->mAcceleration.x += (mNewtonFieldDir.x - ptcl->mLocalPosition.x) * mNewtonFieldStrength;
		ptcl->mAcceleration.y += (mNewtonFieldDir.y - ptcl->mLocalPosition.y) * mNewtonFieldStrength;
		ptcl->mAcceleration.z += (mNewtonFieldDir.z - ptcl->mLocalPosition.z) * mNewtonFieldStrength;
	}

	if (mParticleFlags & PTCLFLAG_UseSolidTexField) {
		int a     = 1 << (mSolidFieldGridScale + 5);
		int b     = 16 << mSolidFieldGridScale;
		int xPlus = (int(ptcl->mLocalPosition.x) + mSolidFieldSampleOffset + b) % a;
		if (xPlus < 0)
			xPlus += a;
		xPlus >>= mSolidFieldGridScale;

		int xMinus = (int(ptcl->mLocalPosition.x) - mSolidFieldSampleOffset + b) % a;
		if (xMinus < 0)
			xMinus += a;
		xMinus >>= mSolidFieldGridScale;

		int yPlus = (int(ptcl->mLocalPosition.y) + mSolidFieldSampleOffset + b) % a;
		if (yPlus < 0)
			yPlus += a;
		yPlus >>= mSolidFieldGridScale;

		int yMinus = (int(ptcl->mLocalPosition.y) - mSolidFieldSampleOffset + b) % a;
		if (yMinus < 0)
			yMinus += a;
		yMinus >>= mSolidFieldGridScale;

		int zPlus = (int(ptcl->mLocalPosition.z) + mSolidFieldSampleOffset + b) % a;
		if (zPlus < 0)
			zPlus += a;
		zPlus >>= mSolidFieldGridScale;

		int zMinus = (int(ptcl->mLocalPosition.z) - mSolidFieldSampleOffset + b) % a;
		if (zMinus < 0)
			zMinus += a;
		zMinus >>= mSolidFieldGridScale;

		int xScale
		    = ((mSolidTexFieldData[(yPlus << 5) + xPlus] & 0x7C00) >> 10) - ((mSolidTexFieldData[(yMinus << 5) + xMinus] & 0x7C00) >> 10);
		int yScale
		    = ((mSolidTexFieldData[(zPlus << 5) + yPlus] & 0x3E0) >> 5) - ((mSolidTexFieldData[(zMinus << 5) + yMinus] & 0x3E0) >> 5);
		int zScale = (mSolidTexFieldData[(xPlus << 5) + zPlus] & 0x1F) - (mSolidTexFieldData[(xMinus << 5) + zMinus] & 0x1F);

		ptcl->mAcceleration.x += mSolidFieldForceMultiplier.x * xScale;
		ptcl->mAcceleration.y += mSolidFieldForceMultiplier.y * yScale;
		ptcl->mAcceleration.z += mSolidFieldForceMultiplier.z * zScale;
	}

	if (mParticleFlags & PTCLFLAG_UseJitterField) {
		ptcl->mAcceleration.x += RandShift(mJitterStrength);
		ptcl->mAcceleration.y += RandShift(mJitterStrength);
		ptcl->mAcceleration.z += RandShift(mJitterStrength);
	}

	if (mParticleFlags & PTCLFLAG_UseLineField) {
		Vector3f vec;
		ptcl->mVelocity.x = ptcl->mVelocity.y = ptcl->mVelocity.z = 0.0f;
		f32 dot1 = mLineFieldAxis.x * ptcl->mLocalPosition.x + mLineFieldAxis.y * ptcl->mLocalPosition.y
		         + mLineFieldAxis.z * ptcl->mLocalPosition.z;
		diffX = mLineFieldAxis.x * dot1 - ptcl->mLocalPosition.x;
		diffY = mLineFieldAxis.y * dot1 - ptcl->mLocalPosition.y;
		diffZ = mLineFieldAxis.z * dot1 - ptcl->mLocalPosition.z;

		ptcl->mAcceleration.x += mLineFieldAxialForce * mLineFieldAxis.x + mLineFieldRadialForce * diffX;
		ptcl->mAcceleration.y += mLineFieldAxialForce * mLineFieldAxis.y + mLineFieldRadialForce * diffY;
		ptcl->mAcceleration.z += mLineFieldAxialForce * mLineFieldAxis.z + mLineFieldRadialForce * diffZ;
	}

	if (mParticleFlags & PTCLFLAG_UseAirField) {
		ptcl->mLocalPosition.x += mAirFieldVelocity.x;
		ptcl->mLocalPosition.y += mAirFieldVelocity.y;
		ptcl->mLocalPosition.z += mAirFieldVelocity.z;
	}
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::UpdatePtclsStatus(f32 timeStep)
{
	f32 dragFactor  = mDrag - Rand(mDragJitter);
	zenList* origin = mPtclMdlListManager.getOrigin();
	zenList* list   = mPtclMdlListManager.getTopList();
	while (list != origin) {
		zenList* next     = list->mNext;
		particleMdl* ptcl = (particleMdl*)list;

		if (ptcl->mAge + 1 >= ptcl->mLifeTime) {
			pmPutParticle(ptcl);
		} else {
			ptcl->mAcceleration.x = ptcl->mAcceleration.y = ptcl->mAcceleration.z = 0.0f;
			if (ptcl->mAge >= mFreePtclMotionTime) {
				pmCalcAccel(ptcl);
			}

			ptcl->mVelocity.x *= dragFactor;
			ptcl->mVelocity.y *= dragFactor;
			ptcl->mVelocity.z *= dragFactor;

			ptcl->mVelocity.x += ptcl->mAcceleration.x;
			ptcl->mVelocity.y += ptcl->mAcceleration.y;
			ptcl->mVelocity.z += ptcl->mAcceleration.z;

			if (mParticleFlags & PTCLFLAG_ClampVelocity) {
				f32 speed
				    = ptcl->mVelocity.x * ptcl->mVelocity.x + ptcl->mVelocity.y * ptcl->mVelocity.y + ptcl->mVelocity.z * ptcl->mVelocity.z;
				if (speed > mMaxVel * mMaxVel) {
					f32 norm = std::sqrtf(speed);
					ptcl->mVelocity.x *= mMaxVel / norm;
					ptcl->mVelocity.y *= mMaxVel / norm;
					ptcl->mVelocity.z *= mMaxVel / norm;
				}
			}

			ptcl->mLocalPosition.x += ptcl->mVelocity.x;
			ptcl->mLocalPosition.y += ptcl->mVelocity.y;
			ptcl->mLocalPosition.z += ptcl->mVelocity.z;

			f32 normalisedAge = f32(ptcl->mAge) / f32(ptcl->mLifeTime);
			if (normalisedAge < mScaleThreshold1) {
				ptcl->mScaleFactor = normalisedAge * mScaleRate1 + mMinScaleFactor1;
			} else if (normalisedAge < mScaleThreshold2) {
				ptcl->mScaleFactor = 1.0f;
			} else {
				ptcl->mScaleFactor = (1.0f - normalisedAge) * mScaleRate2 + mMinScaleFactor2;
			}

			if (normalisedAge < mAlphaThreshold1) {
				ptcl->mAlphaFactor = normalisedAge * mAlphaRate1;
			} else if (normalisedAge < mAlphaThreshold2) {
				ptcl->mAlphaFactor = 1.0f;
			} else {
				ptcl->mAlphaFactor = (1.0f - normalisedAge) * mAlphaRate2;
			}

			ptcl->mAlphaFactor *= (1.0f - Rand(mAlphaJitter));
			ptcl->mRotAngle += ptcl->mRotSpeed;
			ptcl->mAgeTimer += timeStep;
			ptcl->mAge = RoundOff(ptcl->mAgeTimer);

			if (mParticleFlags & PTCLFLAG_EnableChildParticles && ((ptcl->mAge + 1) % mChildSpawnInterval) == 0) {
				particleChildMdl* child = pmGetParticleChild();
				if (child) {
					child->mGlobalPosition  = ptcl->mGlobalPosition;
					child->mLocalPosition.x = RandShift(mChildPosJitter) + ptcl->mLocalPosition.x;
					child->mLocalPosition.y = RandShift(mChildPosJitter) + ptcl->mLocalPosition.y;
					child->mLocalPosition.z = RandShift(mChildPosJitter) + ptcl->mLocalPosition.z;
					child->mSize            = ptcl->mSize * ptcl->mScaleFactor * mChildScaleFactor;

					if (mParticleFlags & PTCLFLAG_InheritParentColor) {
						child->mPrimaryColor.r = ptcl->mPrimaryColor.r;
						child->mPrimaryColor.g = ptcl->mPrimaryColor.g;
						child->mPrimaryColor.b = ptcl->mPrimaryColor.b;
						child->mPrimaryColor.a = ptcl->mPrimaryColor.a;
					} else {
						child->mPrimaryColor.r = mChildColor.r;
						child->mPrimaryColor.g = mChildColor.g;
						child->mPrimaryColor.b = mChildColor.b;
						child->mPrimaryColor.a = 255;
					}

					child->mPrimaryColor.a *= mChildAlphaMultiplier;
					child->_2C = 0.0f;
					child->_31 = 0;
					child->_30 = _124;
					child->_32 = RoundOff(child->mPrimaryColor.a / (child->_30 / timeStep));
				}
			}

			ptcl->mBBoardColourAnim.update(timeStep, &ptcl->mPrimaryColor, &ptcl->mEnvColor);

			if (mCallBack2) {
				mCallBack2->invoke(this, ptcl);
			}
		}

		list = next;
	}

	updatePtclChildren(timeStep);
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::ClearPtclsStatus(Texture* tex, Texture* childTex)
{
	mTexture      = tex;
	mChildTexture = childTex;
	mEmitPosPtr   = nullptr;
	mEmitVelocity.set(0.0f, 0.0f, 0.0f);

	mControlFlags  = 0;
	mParticleFlags = PTCLFLAG_EmitShapeSphere | PTCLFLAG_VelDirOmni;

	mEmissionRateJitter = mEmissionSpread = mEmissionRadiusScale = mEmissionRadius = 0.0f;
	mEmissionBoxSize.x = mEmissionBoxSize.y = mEmissionBoxSize.z = 0.0f;
	mEmitDir.x = mEmitDir.z = 0.0f;
	mEmitPosOffset.x = mEmitPosOffset.y = mEmitPosOffset.z = 0.0f;

	mEmitDir.y = 1.0f;

	mEmissionRate          = 2.0f;
	mInitVel               = 3.0f;
	mInitialVelocityJitter = mDragJitter = mMaxVel = 0.0f;
	mDrag                                          = 0.99f;
	mScaleThreshold1 = mMinScaleFactor1 = mMinScaleFactor2 = mSizeJitter = mLifetimeJitter = mAlphaThreshold1 = mAlphaJitter = 0.0f;
	mRotSpeedMin = mRotSpeedJitter = mRotAngle = 0;
	mBaseLifetime                              = 50;
	_UNUSED112                                 = 0;
	mScaleThreshold2 = mAlphaThreshold2 = 1.0f;
	mScaleSize                          = 1.0f;
	mChildScaleFactor                   = 1.0f;
	mChildAlphaMultiplier               = 1.0f;
	mChildPosJitter                     = 0.0f;
	mChildSpawnInterval                 = 5;
	_124                                = 5;
	mChildColor.set(0, 0, 0, 255);

	// this is necessary for load ordering to work. blame Yamashita, not me.
	mGravFieldAccel.x = mGravFieldAccel.y = mGravFieldAccel.z = mAirFieldVelocity.x = mAirFieldVelocity.y = mAirFieldVelocity.z
	    = mVortexCenter.x = mVortexCenter.z = mVortexRotationSpeed = mVortexStrength = mVortexFalloffFactor = mDampedNewtonFieldDir.x
	    = mDampedNewtonFieldDir.y = mDampedNewtonFieldDir.z = mDampedNewtonFieldStrength = mNewtonFieldDir.x = mNewtonFieldDir.y
	    = mNewtonFieldDir.z = mNewtonFieldStrength = mSolidFieldForceMultiplier.x = mSolidFieldForceMultiplier.y
	    = mSolidFieldForceMultiplier.z = mJitterStrength = mLineFieldAxis.x = mLineFieldAxis.z = mLineFieldAxialForce
	    = mLineFieldRadialForce                                                                = 0.0f;
	mVortexFalloffDivisor                                                                      = 1.0f;
	mLineFieldAxis.y                                                                           = 1.0f;
	mVortexCenter.y                                                                            = 1.0f;
	mSolidFieldGridScale = mSolidFieldType = mSolidFieldSampleOffset = mFreePtclMotionTime = 0;
	mMaxFrame                                                                              = 80;
	mMaxPasses                                                                             = 0;
	mPartialParticleCount                                                                  = 0.0f;
	mPassTimer                                                                             = 0.0f;

	mCurrentFrame = 0;
	mCurrentPass  = 0;
	mBlendFactor = mZMode = 0;
	mOrientedNormal.set(0.0f, 1.0f, 0.0f);
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::drawPtclBillboard(Graphics& gfx)
{
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	GXSetAlphaCompare(GX_GEQUAL, 1, GX_AOP_AND, GX_LEQUAL, 255);
	gfx.setBlendMode(mBlendFactor, mZMode, mAnimData.mBlendMode);

	if (gfx.initParticle(false)) {
		zenList* origin = mPtclMdlListManager.getOrigin();
		zenList* list   = mPtclMdlListManager.getTopList();
		while (list != origin) {
			zenList* next     = list->mNext;
			particleMdl* ptcl = (particleMdl*)list;

			Colour col(ptcl->mPrimaryColor.r, ptcl->mPrimaryColor.g, ptcl->mPrimaryColor.b,
			           RoundOff(ptcl->mPrimaryColor.a * ptcl->mAlphaFactor));
			gfx.setPrimEnv(&col, &ptcl->mEnvColor);
			gfx.drawRotParticle(*gfx.mCamera, ptcl->mLocalPosition + ptcl->mGlobalPosition, -ptcl->mRotAngle,
			                    ptcl->mSize * ptcl->mScaleFactor * 25.0f);

			list = next;
		}
	}
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::drawPtclOriented(Graphics& gfx)
{
	gfx.setBlendMode(mBlendFactor, mZMode, mAnimData.mBlendMode);
	GXSetCullMode(GX_CULL_NONE);
	GXClearVtxDesc();
	GXSetVtxDesc(GX_VA_PNMTXIDX, GX_DIRECT);
	GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
	GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);

	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S16, 0);
	GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_U8, 0);

	GXSetArray(GX_VA_POS, lpsPos, 6);
	GXSetArray(GX_VA_TEX0, lpsCoord, 2);

	GXSetNumChans(0);
	GXSetNumTexGens(1);
	GXSetNumTevStages(1);
	GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR_NULL);
	GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX3X4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
	Vector3f vec1;
	STACK_PAD_VAR(3);
	Matrix4f mtx1; // 0x104
	Mtx mtx2;      // 0xD4
	Mtx mtx3;      // 0xA4
	Vector3f vec2;
	STACK_PAD_VAR(3);
	Vector3f vec3;
	f32 cosVal;
	f32 sinVal;
	Colour col;
	mtx3[2][3]      = 0.0f;
	mtx3[0][3]      = 0.0f;
	mtx3[1][3]      = 25.0f * mPivotOffsetY;
	zenList* origin = mPtclMdlListManager.getOrigin();
	zenList* list   = mPtclMdlListManager.getTopList();
	zenList* next;
	for (list; list != origin; list = next) {
		next              = list->mNext;
		particleMdl* ptcl = (particleMdl*)list;

		col.set(ptcl->mPrimaryColor.r, ptcl->mPrimaryColor.g, ptcl->mPrimaryColor.b, RoundOff(ptcl->mPrimaryColor.a * ptcl->mAlphaFactor));
		gfx.setPrimEnv(&col, &ptcl->mEnvColor);

		MTXIdentity(mtx2);

		f32 a  = ptcl->mSize * ptcl->mScaleFactor;
		cosVal = cosShort(ptcl->mRotAngle);
		sinVal = sinShort(ptcl->mRotAngle);
		(this->*mRotAxisCallBack)(mtx3, sinVal, cosVal);

		MTXTrans(mtx1.mMtx, ptcl->mLocalPosition.x + ptcl->mGlobalPosition.x, ptcl->mLocalPosition.y + ptcl->mGlobalPosition.y,
		         ptcl->mLocalPosition.z + ptcl->mGlobalPosition.z);
		MTXConcat(gfx.mCamera->mLookAtMtx.mMtx, mtx1.mMtx, mtx1.mMtx);

		Vector3f* vec;
		switch (mOrientedDrawConfig.mOrientationSource) {
		case 0:
		{
			vec = &ptcl->mVelocity;
			break;
		}
		case 1:
		{
			vec = &ptcl->mLocalPosition;
			break;
		}
		}

		vec1.x = vec->x;
		vec1.y = vec->y;
		vec1.z = vec->z;

		f32 len = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
		if (len != 0.0f) {
			f32 v = a * mLengthScale; // f27
			vec1.normalize();

			vec2.cross(vec1, ptcl->mOrientedNormal);

			len = vec2.x * vec2.x + vec2.y * vec2.y + vec2.z * vec2.z;
			if (len != 0.0f) {
				vec2.normalize();

				if (mOrientedDrawConfig.mFlipNormal) {
					vec3 = ptcl->mOrientedNormal;
					vec1.cross(vec3, vec2);
					vec1.normalize();
				} else {
					vec3.cross(vec2, vec1);
					vec3.normalize();
				}

				mtx2[0][0] = vec2.x * a;
				mtx2[1][0] = vec2.y * a;
				mtx2[2][0] = vec2.z * a;

				mtx2[0][1] = vec1.x * v;
				mtx2[1][1] = vec1.y * v;
				mtx2[2][1] = vec1.z * v;

				mtx2[0][2] = vec3.x * a;
				mtx2[1][2] = vec3.y * a;
				mtx2[2][2] = vec3.z * a;

				ptcl->mOrientedNormal = vec3;
			} else {
				ptcl->mAgeTimer = ptcl->mLifeTime;
				ptcl->mAge      = ptcl->mLifeTime;
				continue;
			}
		} else {
			ptcl->mAgeTimer = ptcl->mLifeTime;
			ptcl->mAge      = ptcl->mLifeTime;
			continue;
		}

		MTXConcat(mtx2, mtx3, mtx2);
		MTXConcat(mtx1.mMtx, mtx2, mtx1.mMtx);

		GXLoadPosMtxImm(mtx1.mMtx, 0);

		if (mOrientedDrawConfig.mIsDoubleSided) {
			GXBegin(GX_QUADS, GX_VTXFMT0, 8);
			GXTexCoord2u8(0, 0);
			GXTexCoord2u8(0, 0);
			GXTexCoord2u8(1, 1);
			GXTexCoord2u8(0, 2);
			GXTexCoord2u8(2, 0);
			GXTexCoord2u8(3, 3);
			GXTexCoord2u8(0, 4);
			GXTexCoord2u8(0, 0);
			GXTexCoord2u8(5, 1);
			GXTexCoord2u8(0, 6);
			GXTexCoord2u8(2, 0);
			GXTexCoord2u8(7, 3);
		} else {
			GXBegin(GX_QUADS, GX_VTXFMT0, 4);
			GXTexCoord2u8(0, 0);
			GXTexCoord2u8(0, 0);
			GXTexCoord2u8(1, 1);
			GXTexCoord2u8(0, 2);
			GXTexCoord2u8(2, 0);
			GXTexCoord2u8(3, 3);
		}
	}
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::RotAxisX(Mtx& mtx, f32& p2, f32& p3)
{
	mtx[1][1] = mtx[2][2] = p3;
	f32 tmp               = p2;
	mtx[2][1]             = tmp;
	mtx[1][2]             = -tmp;

	mtx[0][1] = mtx[1][0] = mtx[0][2] = mtx[2][0] = 0.0f;
	mtx[0][0]                                     = 1.0f;
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::RotAxisY(Mtx& mtx, f32& p2, f32& p3)
{
	mtx[0][0] = mtx[2][2] = p3;
	f32 tmp               = p2;
	mtx[0][2]             = tmp;
	mtx[2][0]             = -tmp;

	mtx[0][1] = mtx[1][0] = mtx[1][2] = mtx[2][1] = 0.0f;
	mtx[1][1]                                     = 1.0f;
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::RotAxisZ(Mtx& mtx, f32& p2, f32& p3)
{
	mtx[0][0] = mtx[1][1] = p3;
	f32 tmp               = p2;
	mtx[0][1]             = tmp;
	mtx[1][0]             = -tmp;

	mtx[0][2] = mtx[2][0] = mtx[2][1] = mtx[1][2] = 0.0f;
	mtx[2][2]                                     = 1.0f;
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::RotAxisXY(Mtx& mtx, f32& p2, f32& p3)
{
	mtx[0][0] = mtx[1][1] = p3;
	mtx[2][0] = mtx[1][2] = p2;

	mtx[2][1] = mtx[0][2] = -p2 * p3;
	mtx[0][1]             = p2 * p2;
	mtx[2][2]             = p3 * p3;

	mtx[1][0] = 0.0f;
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::RotAxisXZ(Mtx& mtx, f32& p2, f32& p3)
{
	mtx[0][0] = mtx[2][2] = p3;
	f32 tmp               = p2;
	mtx[1][0]             = tmp;
	mtx[2][1]             = -tmp;

	f32 tmp2  = p2 * p3;
	mtx[1][2] = tmp2;
	mtx[0][1] = -tmp2;

	f32 tmp3  = p2;
	mtx[0][2] = -tmp3 * p2;
	mtx[1][1] = p3 * p3;

	mtx[2][0] = 0.0f;
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::RotAxisYZ(Mtx& mtx, f32& p2, f32& p3)
{
	mtx[1][1] = mtx[2][2] = p3;
	f32 tmp               = p2;
	mtx[2][0]             = tmp;
	mtx[0][1]             = -tmp;

	f32 tmp2  = p2 * p3;
	mtx[1][0] = tmp2;
	mtx[0][2] = -tmp2;

	f32 tmp3  = p2;
	mtx[1][2] = -tmp3 * p2;
	mtx[0][0] = p3 * p3;

	mtx[2][1] = 0.0f;
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::RotAxisXYZ(Mtx& mtx, f32& p2, f32& p3)
{
	mtx[0][0] = mtx[2][2] = p3 * p3;
	mtx[0][1] = mtx[1][2] = -p3 * p2;
	mtx[1][0] = mtx[2][1] = (1.0f - p2) * (p3 * p2);
	mtx[0][2]             = -p2;
	mtx[1][1]             = p3 * p3 + p2 * p2 * p2;
	mtx[2][0]             = p2 * (p2 + p3 * p3);
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::updatePtclChildren(f32 timeStep)
{
	zenList* orig = mPtclChildListManager.getOrigin();
	zenList* list = mPtclChildListManager.getTopList();
	zenList* next;
	while (list != orig) {
		particleChildMdl* child = (particleChildMdl*)list;
		next                    = list->mNext;

		if (child->_31 + 1 >= child->_30) {
			pmPutParticleChild(child);

		} else {
			if (child->mPrimaryColor.a > child->_32) {
				child->mPrimaryColor.a -= child->_32;
			} else {
				child->mPrimaryColor.a = 0;
			}
			child->_2C += timeStep;
			child->_31 = RoundOff(child->_2C);
		}

		list = next;
	}
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::drawPtclChildren(Graphics& gfx)
{
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.setBlendMode(mBlendFactor, mZMode, 0);
	GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ONE, GX_CC_C0, GX_CC_ZERO);

	if (!gfx.initParticle(true)) {
		return;
	}

	zenList* orig = mPtclChildListManager.getOrigin();
	zenList* list = mPtclChildListManager.getTopList();
	zenList* next;
	while (list != orig) {
		particleChildMdl* child = (particleChildMdl*)list;
		next                    = list->mNext;

		gfx.setPrimEnv(&child->mPrimaryColor, &child->mPrimaryColor);
		gfx.drawParticle(*gfx.mCamera, child->mLocalPosition + child->mGlobalPosition, 25.0f * child->mSize);

		list = next;
	}
}

/**
 * @todo: Documentation
 */
void zen::particleGenerator::forceFinish()
{
	finish();
	while (mPtclMdlListManager.getOrigin() != mPtclMdlListManager.getTopList()) {
		pmPutParticle(mPtclMdlListManager.getTopList());
	}

	while (mPtclChildListManager.getOrigin() != mPtclChildListManager.getTopList()) {
		pmPutParticleChild(mPtclChildListManager.getTopList());
	}
}

/**
 * @todo: Documentation
 */
bool zen::particleGenerator::finish(zen::CallBack1<zen::particleGenerator*>* cbGen,
                                    zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cbPtcl)
{
	if (mCallBack1 == cbGen && mCallBack2 == cbPtcl) {
		PRINT("finish ptcl. call back pointer.\n");
		finish();
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
bool zen::particleGenerator::forceFinish(zen::CallBack1<zen::particleGenerator*>* cbGen,
                                         zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cbPtcl)
{
	if (mCallBack1 == cbGen && mCallBack2 == cbPtcl) {
		PRINT("force finish ptcl. call back pointer.\n");
		forceFinish();
		return true;
	}

	return false;
}

/**
 * @todo: Documentation
 */
zen::particleMdl* zen::particleGenerator::pmGetParticle()
{
	zenList* ptcl = mMdlMgr->getPtcl();
	if (ptcl) {
		mPtclMdlListManager.put(ptcl);
	}
	return (particleMdl*)ptcl;
}

/**
 * @todo: Documentation
 */
zen::particleChildMdl* zen::particleGenerator::pmGetParticleChild()
{
	zenList* child = mMdlMgr->getPtclChild();
	if (child) {
		mPtclChildListManager.put(child);
	}
	return (particleChildMdl*)child;
}
