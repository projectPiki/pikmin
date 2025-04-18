#include "zen/particle.h"
#include "Matrix3f.h"
#include "Graphics.h"
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
DEFINE_PRINT("particleGenerator")

static u8 lpsPos[48] ATTRIBUTE_ALIGN(32) = {
	255, 231, 0, 25, 0,   0,   0, 25, 0, 25, 0, 0,  0, 25, 255, 231, 0, 0,  255, 231, 255, 231, 0,   0,
	0,   0,   0, 25, 255, 231, 0, 0,  0, 25, 0, 25, 0, 0,  255, 231, 0, 25, 0,   0,   255, 231, 255, 231,
};

static u8 lpsCoord[8] = {
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

/*
 * --INFO--
 * Address:	8019CD0C
 * Size:	00024C
 */
void zen::particleGenerator::init(u8* data, Texture* tex1, Texture* tex2, Vector3f& pos, zen::particleMdlManager* mdlMgr,
                                  zen::CallBack1<zen::particleGenerator*>* cb1,
                                  zen::CallBack2<zen::particleGenerator*, zen::particleMdl*>* cb2)
{
	if (data) {
		if (false) { // this is unreachable in the DLL, had to do some digging to drag it out
			PRINT("VERSION FLAG [%s]\n", 1);
			ERROR(" [%c%c%c%c] is wrong pcr version.\n", data[0], data[1], data[2], data[3]);
		}

		ClearPtclsStatus(tex1, tex2);
		mControlFlags = PTCLCTRL_Active | PTCLCTRL_Visible;

		if (data[6]) {
			mAnimData.set(&data[8]);
			mDrawCallBack = &drawPtclBillboard;
		} else {
			u32 badCompiler;
			_60 = u32ToFloat(((u32*)data)[2]);
			_64 = u32ToFloat(((u32*)data)[3]);
			mAnimData.set(&data[16]);

			u32 rotType = (mAnimData.mFlags.bits._m1) & 0x7;
			_68.m0      = (mAnimData.mFlags.bits._m5);
			_68.m1      = mAnimData.mFlags.bits._m6;
			_68.m2      = 0;
			mAnimData.mFlags.all &= 0x1;
			mDrawCallBack = &drawPtclOriented;

			switch (rotType) {
			case 0:
				mRotAxisCallBack = &RotAxisY;
				break;
			case 1:
				mRotAxisCallBack = &RotAxisX;
				break;
			case 2:
				mRotAxisCallBack = &RotAxisZ;
				break;
			case 3:
				mRotAxisCallBack = &RotAxisXY;
				break;
			case 4:
				mRotAxisCallBack = &RotAxisXZ;
				break;
			case 5:
				mRotAxisCallBack = &RotAxisYZ;
				break;
			case 6:
				mRotAxisCallBack = &RotAxisXYZ;
				break;
			}
		}

		pmSetDDF(&data[((u16*)data)[2]]);
		mMdlMgr  = mdlMgr;
		mEmitPos = pos;
		setCallBack(cb1, cb2);
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x70(r1)
	  stmw      r25, 0x54(r1)
	  mr.       r26, r4
	  lis       r4, 0x802E
	  addi      r25, r3, 0
	  addi      r27, r7, 0
	  addi      r28, r8, 0
	  addi      r29, r9, 0
	  addi      r30, r10, 0
	  subi      r31, r4, 0x59E0
	  beq-      .loc_0x238
	  addi      r3, r25, 0
	  addi      r4, r5, 0
	  addi      r5, r6, 0
	  bl        0x2FC4
	  li        r0, 0x14
	  stw       r0, 0x80(r25)
	  lbz       r0, 0x6(r26)
	  cmplwi    r0, 0
	  beq-      .loc_0x80
	  addi      r3, r25, 0x48
	  addi      r4, r26, 0x8
	  bl        0x50A4
	  lwz       r3, 0x70(r31)
	  lwz       r0, 0x74(r31)
	  stw       r3, 0x1E8(r25)
	  stw       r0, 0x1EC(r25)
	  lwz       r0, 0x78(r31)
	  stw       r0, 0x1F0(r25)
	  b         .loc_0x1E4

	.loc_0x80:
	  lwz       r0, 0x8(r26)
	  addi      r3, r25, 0x48
	  addi      r4, r26, 0x10
	  stw       r0, 0x44(r1)
	  lfs       f0, 0x44(r1)
	  stfs      f0, 0x60(r25)
	  lwz       r0, 0xC(r26)
	  stw       r0, 0x3C(r1)
	  lfs       f0, 0x3C(r1)
	  stfs      f0, 0x64(r25)
	  bl        0x505C
	  lbz       r4, 0x4A(r25)
	  li        r3, 0
	  lbz       r0, 0x68(r25)
	  rlwimi    r0,r4,5,24,24
	  stb       r0, 0x68(r25)
	  rlwinm    r5,r4,28,29,31
	  cmplwi    r5, 0x6
	  lbz       r4, 0x4A(r25)
	  lbz       r0, 0x68(r25)
	  rlwimi    r0,r4,5,25,25
	  stb       r0, 0x68(r25)
	  lbz       r0, 0x68(r25)
	  rlwimi    r0,r3,5,26,26
	  stb       r0, 0x68(r25)
	  lbz       r0, 0x4A(r25)
	  rlwinm    r0,r0,0,31,31
	  stb       r0, 0x4A(r25)
	  lwz       r3, 0x7C(r31)
	  lwz       r0, 0x80(r31)
	  stw       r3, 0x1E8(r25)
	  stw       r0, 0x1EC(r25)
	  lwz       r0, 0x84(r31)
	  stw       r0, 0x1F0(r25)
	  bgt-      .loc_0x1E4
	  lis       r3, 0x802E
	  subi      r3, r3, 0x5904
	  rlwinm    r0,r5,2,0,29
	  lwzx      r0, r3, r0
	  mtctr     r0
	  bctr
	  lwz       r3, 0x88(r31)
	  lwz       r0, 0x8C(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0x90(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0x94(r31)
	  lwz       r0, 0x98(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0x9C(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xA0(r31)
	  lwz       r0, 0xA4(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xA8(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xAC(r31)
	  lwz       r0, 0xB0(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xB4(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xB8(r31)
	  lwz       r0, 0xBC(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xC0(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xC4(r31)
	  lwz       r0, 0xC8(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xCC(r31)
	  stw       r0, 0x1FC(r25)
	  b         .loc_0x1E4
	  lwz       r3, 0xD0(r31)
	  lwz       r0, 0xD4(r31)
	  stw       r3, 0x1F4(r25)
	  stw       r0, 0x1F8(r25)
	  lwz       r0, 0xD8(r31)
	  stw       r0, 0x1FC(r25)

	.loc_0x1E4:
	  lhz       r0, 0x4(r26)
	  addi      r3, r25, 0
	  add       r4, r26, r0
	  bl        0x328
	  stw       r28, 0x1D0(r25)
	  cmplwi    r29, 0
	  lwz       r3, 0x0(r27)
	  lwz       r0, 0x4(r27)
	  stw       r3, 0xC(r25)
	  stw       r0, 0x10(r25)
	  lwz       r0, 0x8(r27)
	  stw       r0, 0x14(r25)
	  stw       r29, 0x1D4(r25)
	  beq-      .loc_0x234
	  lwz       r3, 0x1D4(r25)
	  mr        r4, r25
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x234:
	  stw       r30, 0x1D8(r25)

	.loc_0x238:
	  lmw       r25, 0x54(r1)
	  lwz       r0, 0x74(r1)
	  addi      r1, r1, 0x70
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8019CF58
 * Size:	000154
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

/*
 * --INFO--
 * Address:	8019D0AC
 * Size:	000178
 */
void zen::particleGenerator::draw(Graphics& gfx)
{
	if (mControlFlags & PTCLCTRL_Visible) {
		bool light = gfx.setLighting(false, nullptr);
		int blend  = gfx.setCBlending(1);
		gfx.setDepth(false);

		if (mChildTexture) {
			gfx.useTexture(mChildTexture, 0);
		} else {
			gfx.useTexture(mTexture, 0);
		}
		drawPtclChildren(gfx);

		gfx.useTexture(mTexture, 0);
		(this->*mDrawCallBack)(gfx);

		gfx.setDepth(true);
		gfx.setCBlending(blend);
		gfx.setLighting(light, nullptr);
	}
}

/*
 * --INFO--
 * Address:	8019D224
 * Size:	000B58
 */
void zen::particleGenerator::pmSetDDF(u8* data)
{
	if (!data) {
		return;
	}

	readDDF_U32(&mParticleFlags, data, 4);
	readDDF_Vector(&mEmitPosOffset, data);
	readDDF_Vector(&mEmitDir, data);
	readDDF_Vector(&_AC, data);
	readDDF_Float(&_C0, data, 4);

	if (mParticleFlags & (PTCLFLAG_Unk6 | PTCLFLAG_Unk7)) {
		readDDF_U8(&_1C4, data, 4);
		readDDF_FloatArray(&_1AC, data, _1C4);
		readDDF_FloatArray(&_1B0, data, _1C4);
	} else {
		readDDF_Float(&_B8, data, 4);
	}

	readDDF_Float(&_BC, data, 4);
	readDDF_Float(&_C4, data, 4);

	if (mParticleFlags & (PTCLFLAG_Unk8 | PTCLFLAG_Unk9)) {
		readDDF_U8(&_1C5, data, 4);
		readDDF_FloatArray(&_1B4, data, _1C5);
		readDDF_FloatArray(&_1B8, data, _1C5);
	} else {
		readDDF_Float(&_C8, data, 4);
	}

	if (mParticleFlags & (PTCLFLAG_Unk10 | PTCLFLAG_Unk11)) {
		readDDF_U8(&_1C6, data, 4);
		readDDF_FloatArray(&_1BC, data, _1C6);
		readDDF_FloatArray(&_1C0, data, _1C6);
	} else {
		readDDF_Float(&mInitVel, data, 4);
	}

	readDDF_Float(&_D0, data, 4);
	readDDF_Float(&mDrag, data, 4);
	readDDF_Float(&mDragJitter, data, 4);
	readDDF_Float(&mMaxVel, data, 4);
	readDDF_Float(&_E0, data, 4);
	readDDF_Float(&_E4, data, 4);
	readDDF_Float(&_E8, data, 4);
	readDDF_Float(&_EC, data, 4);
	readDDF_Float(&mScaleSize, data, 4);
	readDDF_Float(&_F4, data, 4);
	readDDF_Float(&_F8, data, 4);
	readDDF_Float(&_FC, data, 4);
	readDDF_Float(&_100, data, 4);
	readDDF_Float(&_10C, data, 4);

	readDDF_Short(&_104, data, 2);
	readDDF_Short(&_106, data, 2);
	readDDF_Short(&_108, data, 2);
	readDDF_Short(&_110, data, 2);
	readDDF_Short(&mMaxFrame, data, 2);
	readDDF_U8(&mFreePtclMotionTime, data, 1);
	readDDF_U8(&_112, data, 1);
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
		readDDF_Float(&_158, data, 4);
		readDDF_Float(&_15C, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_UseDampedNewtonField) {
		readDDF_Vector(&mDampedNewtonFieldDir, data);
		readDDF_Float(&mDampedNewtonFieldStrength, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_UseNewtonField) {
		readDDF_Vector(&mNewtonFieldDir, data);
		readDDF_Float(&mNewtonFieldStrength, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_UseSolidTex) {
		readDDF_Vector(&_180, data);
		readDDF_U8(&_18C, data, 1);
		readDDF_U8(&mSolidFieldType, data, 1);
		readDDF_U8(&_18D, data, 2);
		mSolidTexFieldData = UseSolidTex[mSolidFieldType];
	}

	if (mParticleFlags & PTCLFLAG_UseJitter) {
		readDDF_Float(&mJitterStrength, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_Unk23) {
		readDDF_Vector(&_194, data);
		readDDF_Float(&_1A0, data, 4);
		readDDF_Float(&_1A4, data, 4);
	}

	if (mParticleFlags & PTCLFLAG_Unk13) {
		readDDF_Float(&_114, data, 4);
		readDDF_Float(&_118, data, 4);
		readDDF_Float(&_11C, data, 4);
		readDDF_Colour(&_120, data, 4);
		readDDF_U8(&_124, data, 1);
		readDDF_U8(&_125, data, 3);
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

	if (mParticleFlags & PTCLFLAG_Unk23) {
		len = _194.x * _194.x + _194.y * _194.y + _194.z * _194.z;
		if (len == 0.0f) {
			pmGetArbitUnitVec(_194);
		} else {
			len = std::sqrtf(len);
			_194.x /= len;
			_194.y /= len;
			_194.z /= len;
		}
	}

	_6C = (_E0 == 0.0f) ? 1.0f : (1.0f - _E8) / _E0;
	_70 = (_E4 == 1.0f) ? 1.0f : (1.0f - _EC) / (1.0f - _E4);
	_74 = (_F8 == 0.0f) ? 1.0f : 1.0f / _F8;
	_78 = (_FC == 1.0f) ? 1.0f : 1.0f / (1.0f - _FC);

	u32 badCompiler[6];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
f32 zen::particleGenerator::pmIntpManual(f32* frameThresholds, f32* values)
{
	int i;
	for (i = 1; mCurrentFrame > mMaxFrame * frameThresholds[i]; i++) {
		;
	}
	return values[i - 1];
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A0
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

/*
 * --INFO--
 * Address:	8019DD7C
 * Size:	0002F8
 */
void zen::particleGenerator::SetPtclsLife()
{
	if (mParticleFlags & PTCLFLAG_Unk12) {
		return;
	}

	f32 a;
	if (mParticleFlags & (PTCLFLAG_Unk6 | PTCLFLAG_Unk7)) {
		if (mParticleFlags & PTCLFLAG_Unk6) {
			a = pmIntpManual(_1AC, _1B0);
		} else {
			a = pmIntpLinear(_1AC, _1B0);
		}
	} else {
		a = _B8;
	}

	_88 += a + RandShift(a * _BC);
	int max = _88;
	_88     = _88 - max;

	for (int i = 0; i < max; i++) {
		particleMdl* ptcl = pmGetParticle();
		if (ptcl) {
			ptcl->mLifeTime = _110 * (1.0f - Rand(_10C));
			ptcl->mBBoardColourAnim.init(&mAnimData, ptcl->mLifeTime);
			PtclsGen(ptcl);
			if (mCallBack2) {
				mCallBack2->invoke(this, ptcl);
			}
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x90(r1)
	  stfd      f31, 0x88(r1)
	  stfd      f30, 0x80(r1)
	  stfd      f29, 0x78(r1)
	  stfd      f28, 0x70(r1)
	  stfd      f27, 0x68(r1)
	  stmw      r26, 0x50(r1)
	  mr        r31, r3
	  lwz       r3, 0x84(r3)
	  rlwinm.   r0,r3,0,19,19
	  bne-      .loc_0x2D0
	  rlwinm.   r0,r3,0,24,25
	  beq-      .loc_0x158
	  rlwinm.   r0,r3,0,25,25
	  beq-      .loc_0xB8
	  lwz       r4, 0x1AC(r31)
	  li        r5, 0x1
	  lha       r0, 0x1C8(r31)
	  lis       r3, 0x4330
	  lha       r8, 0x90(r31)
	  lwz       r6, 0x1B0(r31)
	  addi      r7, r4, 0x4
	  lfd       f3, -0x4C48(r2)
	  xoris     r4, r8, 0x8000
	  xoris     r0, r0, 0x8000
	  b         .loc_0x78

	.loc_0x70:
	  addi      r7, r7, 0x4
	  addi      r5, r5, 0x1

	.loc_0x78:
	  stw       r0, 0x44(r1)
	  lfs       f0, 0x0(r7)
	  stw       r3, 0x40(r1)
	  stw       r4, 0x4C(r1)
	  lfd       f1, 0x40(r1)
	  stw       r3, 0x48(r1)
	  fsubs     f1, f1, f3
	  lfd       f2, 0x48(r1)
	  fsubs     f2, f2, f3
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f2, f0
	  bgt+      .loc_0x70
	  rlwinm    r0,r5,2,0,29
	  add       r3, r6, r0
	  lfs       f27, -0x4(r3)
	  b         .loc_0x15C

	.loc_0xB8:
	  lha       r4, 0x90(r31)
	  lis       r3, 0x4330
	  lha       r0, 0x1C8(r31)
	  li        r5, 0x1
	  xoris     r4, r4, 0x8000
	  xoris     r0, r0, 0x8000
	  stw       r4, 0x44(r1)
	  lwz       r7, 0x1AC(r31)
	  stw       r0, 0x4C(r1)
	  lfd       f2, -0x4C48(r2)
	  addi      r6, r7, 0x4
	  stw       r3, 0x40(r1)
	  lwz       r4, 0x1B0(r31)
	  stw       r3, 0x48(r1)
	  lfd       f1, 0x40(r1)
	  lfd       f0, 0x48(r1)
	  fsubs     f1, f1, f2
	  fsubs     f0, f0, f2
	  fdivs     f3, f1, f0
	  b         .loc_0x110

	.loc_0x108:
	  addi      r6, r6, 0x4
	  addi      r5, r5, 0x1

	.loc_0x110:
	  lfs       f0, 0x0(r6)
	  fcmpo     cr0, f3, f0
	  bgt+      .loc_0x108
	  rlwinm    r0,r5,2,0,29
	  add       r3, r7, r0
	  lfsx      f5, r7, r0
	  lfs       f0, -0x4(r3)
	  add       r3, r4, r0
	  fsubs     f1, f5, f3
	  lfs       f2, -0x4(r3)
	  fsubs     f3, f3, f0
	  lfsx      f4, r4, r0
	  fsubs     f0, f5, f0
	  fmuls     f3, f4, f3
	  fmuls     f1, f2, f1
	  fadds     f1, f3, f1
	  fdivs     f27, f1, f0
	  b         .loc_0x15C

	.loc_0x158:
	  lfs       f27, 0xB8(r31)

	.loc_0x15C:
	  lfs       f0, 0xBC(r31)
	  fmuls     f28, f27, f0
	  bl        0x7A190
	  xoris     r0, r3, 0x8000
	  lfs       f0, -0x4C40(r2)
	  stw       r0, 0x44(r1)
	  lis       r29, 0x4330
	  lfd       f30, -0x4C48(r2)
	  fmuls     f0, f0, f28
	  stw       r29, 0x40(r1)
	  lfs       f31, -0x4C68(r2)
	  addi      r30, r31, 0x48
	  lfd       f2, 0x40(r1)
	  lfs       f1, 0x88(r31)
	  li        r28, 0
	  fsubs     f2, f2, f30
	  fdivs     f2, f2, f31
	  fmuls     f0, f0, f2
	  fsubs     f0, f0, f28
	  fadds     f0, f27, f0
	  fadds     f0, f1, f0
	  stfs      f0, 0x88(r31)
	  lfs       f1, 0x88(r31)
	  fctiwz    f0, f1
	  stfd      f0, 0x48(r1)
	  lwz       r27, 0x4C(r1)
	  xoris     r0, r27, 0x8000
	  stw       r0, 0x3C(r1)
	  stw       r29, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  fsubs     f0, f0, f30
	  fsubs     f0, f1, f0
	  stfs      f0, 0x88(r31)
	  lfs       f28, -0x4C50(r2)
	  lfs       f29, -0x4C70(r2)
	  b         .loc_0x2C8

	.loc_0x1EC:
	  mr        r3, r31
	  bl        0x2E80
	  mr.       r26, r3
	  beq-      .loc_0x2C4
	  lfs       f27, 0x10C(r31)
	  bl        0x7A0F4
	  xoris     r0, r3, 0x8000
	  lha       r3, 0x110(r31)
	  stw       r0, 0x3C(r1)
	  li        r0, 0
	  xoris     r3, r3, 0x8000
	  stw       r29, 0x38(r1)
	  lfd       f0, 0x38(r1)
	  stw       r3, 0x44(r1)
	  fsubs     f0, f0, f30
	  stw       r29, 0x40(r1)
	  fdivs     f1, f0, f31
	  lfd       f0, 0x40(r1)
	  fmuls     f2, f27, f1
	  fsubs     f1, f0, f30
	  fsubs     f0, f28, f2
	  fmuls     f0, f1, f0
	  fctiwz    f0, f0
	  stfd      f0, 0x48(r1)
	  lwz       r3, 0x4C(r1)
	  sth       r3, 0x2C(r26)
	  lha       r3, 0x2C(r26)
	  stfs      f29, 0x6C(r26)
	  stb       r0, 0x70(r26)
	  stw       r30, 0x74(r26)
	  lwz       r4, 0x74(r26)
	  cmplwi    r4, 0
	  beq-      .loc_0x290
	  lbz       r0, 0x2(r4)
	  cmplwi    r0, 0
	  beq-      .loc_0x284
	  sth       r3, 0x72(r26)
	  b         .loc_0x294

	.loc_0x284:
	  lbz       r0, 0x1(r4)
	  sth       r0, 0x72(r26)
	  b         .loc_0x294

	.loc_0x290:
	  sth       r3, 0x72(r26)

	.loc_0x294:
	  addi      r3, r31, 0
	  addi      r4, r26, 0
	  bl        .loc_0x2F8
	  lwz       r3, 0x1D8(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x2C4
	  lwz       r12, 0x0(r3)
	  addi      r4, r31, 0
	  addi      r5, r26, 0
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x2C4:
	  addi      r28, r28, 0x1

	.loc_0x2C8:
	  cmpw      r28, r27
	  blt+      .loc_0x1EC

	.loc_0x2D0:
	  lmw       r26, 0x50(r1)
	  lwz       r0, 0x94(r1)
	  lfd       f31, 0x88(r1)
	  lfd       f30, 0x80(r1)
	  lfd       f29, 0x78(r1)
	  lfd       f28, 0x70(r1)
	  lfd       f27, 0x68(r1)
	  addi      r1, r1, 0x90
	  mtlr      r0
	  blr

	.loc_0x2F8:
	*/
}

/*
 * --INFO--
 * Address:	8019E074
 * Size:	000F00
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

	tmp4.x = _AC.x;
	tmp4.y = _AC.y;
	tmp4.z = _AC.z;

	if (mParticleFlags & (PTCLFLAG_Unk10 | PTCLFLAG_Unk11)) {
		if (mParticleFlags & PTCLFLAG_Unk10) {
			initVel = pmIntpManual(_1BC, _1C0);
		} else {
			initVel = pmIntpLinear(_1BC, _1C0);
		}
	} else {
		initVel = mInitVel;
	}

	if (mParticleFlags & (PTCLFLAG_Unk8 | PTCLFLAG_Unk9)) {
		if (mParticleFlags & PTCLFLAG_Unk8) {
			b = pmIntpManual(_1B4, _1B8);
		} else {
			b = pmIntpLinear(_1B4, _1B8);
		}
	} else {
		b = _C8;
	}

	c = _C4 * b;

	if (int(mParticleFlags & (PTCLFLAG_Unk0 | PTCLFLAG_Unk1)) == 1) {
		if (int(mParticleFlags & (PTCLFLAG_Unk2 | PTCLFLAG_Unk3)) == 4) {
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

			scale = initVel + RandShift(initVel * _D0);
			ptclVel.x *= scale;
			ptclVel.y *= scale;
			ptclVel.z *= scale;

		} else if (int(mParticleFlags & (PTCLFLAG_Unk2 | PTCLFLAG_Unk3)) == 8) {
			ptclPos.x = mEmitPosOffset.x;
			ptclPos.y = mEmitPosOffset.y;
			ptclPos.z = mEmitPosOffset.z;
			pmGetArbitUnitVec(tmp5);
			tmp5.cross(tmp5, emitDir);

			scale = Rand(_C0);
			tmp5.x *= scale;
			tmp5.y *= scale;
			tmp5.z *= scale;

			ptclVel.x = emitDir.x + tmp5.x;
			ptclVel.y = emitDir.y + tmp5.y;
			ptclVel.z = emitDir.z + tmp5.z;

			ptclVel.normalize();

			scale = initVel + RandShift(initVel * _D0);
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
				ptcl->_30       = 0.0f;
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

			scale = initVel + RandShift(initVel * _D0);
			ptclVel.x *= scale;
			ptclVel.y *= scale;
			ptclVel.z *= scale;
		}
	} else if (int(mParticleFlags & (PTCLFLAG_Unk0 | PTCLFLAG_Unk1)) == 2) {
		ptclPos.x = RandShift(1.0f) * tmp4.x + mEmitPosOffset.x;
		ptclPos.y = RandShift(1.0f) * tmp4.y + mEmitPosOffset.y;
		ptclPos.z = RandShift(1.0f) * tmp4.z + mEmitPosOffset.z;

		scale     = initVel + RandShift(initVel * _D0);
		ptclVel.x = emitDir.x * scale;
		ptclVel.y = emitDir.y * scale;
		ptclVel.z = emitDir.z * scale;
	} else {
		f32 d = _C4;
		pmGetArbitUnitVec(tmp5);
		ptclVel.cross(tmp5, emitDir);
		scale = ptclVel.x * ptclVel.x + ptclVel.y * ptclVel.y + ptclVel.z * ptclVel.z;
		if (scale == 0.0f) {
			ptcl->mLifeTime = 1;
			ptcl->mAge      = 0;
			ptcl->_30       = 0.0f;

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

		if (int(mParticleFlags & (PTCLFLAG_Unk2 | PTCLFLAG_Unk3)) == 8) {
			scale     = initVel + RandShift(initVel * _D0);
			ptclVel.x = emitDir.x * scale;
			ptclVel.y = emitDir.y * scale;
			ptclVel.z = emitDir.z * scale;
		} else {
			scale = initVel + RandShift(initVel * _D0);
			ptclVel.x *= scale;
			ptclVel.y *= scale;
			ptclVel.z *= scale;
		}
	}

	ptclVel.add(mEmitVelocity);

	ptcl->mPosition.x = ptclPos.x;
	ptcl->mPosition.y = ptclPos.y;
	ptcl->mPosition.z = ptclPos.z;
	ptcl->mVelocity.x = ptclVel.x;
	ptcl->mVelocity.y = ptclVel.y;
	ptcl->mVelocity.z = ptclVel.z;
	ptcl->_24         = (_F4 - 2.0f * _F4 * RandShift(1.0f)) * mScaleSize + mScaleSize;
	if (ptcl->_24 < 0.0f) {
		ptcl->_24 = 0.0f;
	}

	ptcl->_5A          = f32(_104) + f32(_106) * RandShift(1.0f);
	ptcl->_58          = f32(_108) * RandShift(1.0f);
	ptcl->_4C          = Rand(_112);
	ptcl->_5C          = mOrientedNormalVector;
	ptcl->mLocalOffset = getGPos();
}

/*
 * --INFO--
 * Address:	8019EF74
 * Size:	000754
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
		f32 scale = mVortexCenter.dot(ptcl->mPosition);
		Vector3f vortexForce;
		vortexForce.x = ptcl->mPosition.x - mVortexCenter.x * scale;
		vortexForce.y = ptcl->mPosition.y - mVortexCenter.y * scale;
		vortexForce.z = ptcl->mPosition.z - mVortexCenter.z * scale;

		scale = vortexForce.x * vortexForce.x + vortexForce.y * vortexForce.y + vortexForce.z * vortexForce.z;
		f32 v = (_15C == 0.0f) ? 1.0f : (_158 * _15C - scale) / (_15C + scale) + 1.0f;

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

		diffX = ptcl->mPosition.x;
		diffY = ptcl->mPosition.y;
		diffZ = ptcl->mPosition.z;

		ptcl->mPosition.x = (cosComp * axisX * axisX + cosTheta) * diffX + (cosComp * axisX * axisY + sinTheta * axisZ) * diffY
		                  + (cosComp * axisX * axisZ - sinTheta * axisY) * diffZ + vortexForce.x;
		ptcl->mPosition.y = (cosComp * axisX * axisY - sinTheta * axisZ) * diffX + (cosComp * axisY * axisY + cosTheta) * diffY
		                  + (cosComp * axisY * axisZ + sinTheta * axisX) * diffZ + vortexForce.y;
		ptcl->mPosition.z = (cosComp * axisX * axisZ + sinTheta * axisY) * diffX + (cosComp * axisY * axisZ - sinTheta * axisX) * diffY
		                  + (cosComp * axisZ * axisZ + cosTheta) * diffZ + vortexForce.z;
	}

	if (mParticleFlags & PTCLFLAG_UseDampedNewtonField) {
		ptcl->mAcceleration.x += (mDampedNewtonFieldDir.x - ptcl->mPosition.x) * mDampedNewtonFieldStrength - ptcl->mVelocity.x;
		ptcl->mAcceleration.y += (mDampedNewtonFieldDir.y - ptcl->mPosition.y) * mDampedNewtonFieldStrength - ptcl->mVelocity.y;
		ptcl->mAcceleration.z += (mDampedNewtonFieldDir.z - ptcl->mPosition.z) * mDampedNewtonFieldStrength - ptcl->mVelocity.z;
	}

	if (mParticleFlags & PTCLFLAG_UseNewtonField) {
		ptcl->mAcceleration.x += (mNewtonFieldDir.x - ptcl->mPosition.x) * mNewtonFieldStrength;
		ptcl->mAcceleration.y += (mNewtonFieldDir.y - ptcl->mPosition.y) * mNewtonFieldStrength;
		ptcl->mAcceleration.z += (mNewtonFieldDir.z - ptcl->mPosition.z) * mNewtonFieldStrength;
	}

	if (mParticleFlags & PTCLFLAG_UseSolidTex) {
		int a     = 1 << (_18C + 5);
		int b     = 16 << _18C;
		int xPlus = (int(ptcl->mPosition.x) + _18D + b) % a;
		if (xPlus < 0)
			xPlus += a;
		xPlus >>= _18C;

		int xMinus = (int(ptcl->mPosition.x) - _18D + b) % a;
		if (xMinus < 0)
			xMinus += a;
		xMinus >>= _18C;

		int yPlus = (int(ptcl->mPosition.y) + _18D + b) % a;
		if (yPlus < 0)
			yPlus += a;
		yPlus >>= _18C;

		int yMinus = (int(ptcl->mPosition.y) - _18D + b) % a;
		if (yMinus < 0)
			yMinus += a;
		yMinus >>= _18C;

		int zPlus = (int(ptcl->mPosition.z) + _18D + b) % a;
		if (zPlus < 0)
			zPlus += a;
		zPlus >>= _18C;

		int zMinus = (int(ptcl->mPosition.z) - _18D + b) % a;
		if (zMinus < 0)
			zMinus += a;
		zMinus >>= _18C;

		int xScale
		    = ((mSolidTexFieldData[(yPlus << 5) + xPlus] & 0x7C00) >> 10) - ((mSolidTexFieldData[(yMinus << 5) + xMinus] & 0x7C00) >> 10);
		int yScale
		    = ((mSolidTexFieldData[(zPlus << 5) + yPlus] & 0x3E0) >> 5) - ((mSolidTexFieldData[(zMinus << 5) + yMinus] & 0x3E0) >> 5);
		int zScale = (mSolidTexFieldData[(xPlus << 5) + zPlus] & 0x1F) - (mSolidTexFieldData[(xMinus << 5) + zMinus] & 0x1F);

		ptcl->mAcceleration.x += _180.x * xScale;
		ptcl->mAcceleration.y += _180.y * yScale;
		ptcl->mAcceleration.z += _180.z * zScale;
	}

	if (mParticleFlags & PTCLFLAG_UseJitter) {
		ptcl->mAcceleration.x += RandShift(mJitterStrength);
		ptcl->mAcceleration.y += RandShift(mJitterStrength);
		ptcl->mAcceleration.z += RandShift(mJitterStrength);
	}

	if (mParticleFlags & PTCLFLAG_Unk23) {
		Vector3f vec;
		ptcl->mVelocity.x = ptcl->mVelocity.y = ptcl->mVelocity.z = 0.0f;
		f32 dot1 = _194.x * ptcl->mPosition.x + _194.y * ptcl->mPosition.y + _194.z * ptcl->mPosition.z;
		diffX    = _194.x * dot1 - ptcl->mPosition.x;
		diffY    = _194.y * dot1 - ptcl->mPosition.y;
		diffZ    = _194.z * dot1 - ptcl->mPosition.z;

		ptcl->mAcceleration.x += _1A0 * _194.x + _1A4 * diffX;
		ptcl->mAcceleration.y += _1A0 * _194.y + _1A4 * diffY;
		ptcl->mAcceleration.z += _1A0 * _194.z + _1A4 * diffZ;
	}

	if (mParticleFlags & PTCLFLAG_UseAirField) {
		ptcl->mPosition.x += mAirFieldVelocity.x;
		ptcl->mPosition.y += mAirFieldVelocity.y;
		ptcl->mPosition.z += mAirFieldVelocity.z;
	}
}

/*
 * --INFO--
 * Address:	8019F6C8
 * Size:	000648
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

			if (mParticleFlags & PTCLFLAG_ClampVel) {
				f32 speed
				    = ptcl->mVelocity.x * ptcl->mVelocity.x + ptcl->mVelocity.y * ptcl->mVelocity.y + ptcl->mVelocity.z * ptcl->mVelocity.z;
				if (speed > mMaxVel * mMaxVel) {
					f32 norm = std::sqrtf(speed);
					ptcl->mVelocity.x *= mMaxVel / norm;
					ptcl->mVelocity.y *= mMaxVel / norm;
					ptcl->mVelocity.z *= mMaxVel / norm;
				}
			}

			ptcl->mPosition.x += ptcl->mVelocity.x;
			ptcl->mPosition.y += ptcl->mVelocity.y;
			ptcl->mPosition.z += ptcl->mVelocity.z;

			f32 normalisedAge = f32(ptcl->mAge) / f32(ptcl->mLifeTime);
			if (normalisedAge < _E0) {
				ptcl->_50 = normalisedAge * _6C + _E8;
			} else if (normalisedAge < _E4) {
				ptcl->_50 = 1.0f;
			} else {
				ptcl->_50 = (1.0f - normalisedAge) * _70 + _EC;
			}

			if (normalisedAge < _F8) {
				ptcl->_54 = normalisedAge * _74;
			} else if (normalisedAge < _FC) {
				ptcl->_54 = 1.0f;
			} else {
				ptcl->_54 = (1.0f - normalisedAge) * _78;
			}

			ptcl->_54 *= (1.0f - Rand(_100));
			ptcl->_58 += ptcl->_5A;
			ptcl->_30 += timeStep;
			ptcl->mAge = RoundOff(ptcl->_30);

			if (mParticleFlags & PTCLFLAG_Unk13 && ((ptcl->mAge + 1) % _125) == 0) {
				particleChildMdl* child = pmGetParticleChild();
				if (child) {
					child->mLocalOffset = ptcl->mLocalOffset;
					child->mPosition.x  = RandShift(_11C) + ptcl->mPosition.x;
					child->mPosition.y  = RandShift(_11C) + ptcl->mPosition.y;
					child->mPosition.z  = RandShift(_11C) + ptcl->mPosition.z;
					child->_24          = ptcl->_24 * ptcl->_50 * _114;

					if (mParticleFlags & PTCLFLAG_Unk14) {
						child->mPrimaryColor.r = ptcl->mPrimaryColor.r;
						child->mPrimaryColor.g = ptcl->mPrimaryColor.g;
						child->mPrimaryColor.b = ptcl->mPrimaryColor.b;
						child->mPrimaryColor.a = ptcl->mPrimaryColor.a;
					} else {
						child->mPrimaryColor.r = _120.r;
						child->mPrimaryColor.g = _120.g;
						child->mPrimaryColor.b = _120.b;
						child->mPrimaryColor.a = 255;
					}

					child->mPrimaryColor.a *= _118;
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

/*
 * --INFO--
 * Address:	8019FD10
 * Size:	0001C4
 */
void zen::particleGenerator::ClearPtclsStatus(Texture* tex, Texture* childTex)
{
	mTexture      = tex;
	mChildTexture = childTex;
	mEmitPosPtr   = nullptr;
	mEmitVelocity.set(0.0f, 0.0f, 0.0f);

	mControlFlags  = 0;
	mParticleFlags = PTCLFLAG_Unk0 | PTCLFLAG_Unk2;

	_BC = _C0 = _C4 = _C8 = 0.0f;
	_AC.x = _AC.y = _AC.z = 0.0f;
	mEmitDir.x = mEmitDir.z = 0.0f;
	mEmitPosOffset.x = mEmitPosOffset.y = mEmitPosOffset.z = 0.0f;

	mEmitDir.y = 1.0f;

	_B8      = 2.0f;
	mInitVel = 3.0f;
	_D0 = mDragJitter = mMaxVel = 0.0f;
	mDrag                       = 0.99f;
	_E0 = _E8 = _EC = _F4 = _10C = _F8 = _100 = 0.0f;
	_104 = _106 = _108 = 0;
	_110               = 50;
	_112               = 0;
	_E4 = _FC  = 1.0f;
	mScaleSize = 1.0f;
	_114       = 1.0f;
	_118       = 1.0f;
	_11C       = 0.0f;
	_125       = 5;
	_124       = 5;
	_120.set(0, 0, 0, 255);

	// this is necessary for load ordering to work. blame Yamashita, not me.
	mGravFieldAccel.x = mGravFieldAccel.y = mGravFieldAccel.z = mAirFieldVelocity.x = mAirFieldVelocity.y = mAirFieldVelocity.z
	    = mVortexCenter.x = mVortexCenter.z = mVortexRotationSpeed = mVortexStrength = _158 = mDampedNewtonFieldDir.x
	    = mDampedNewtonFieldDir.y = mDampedNewtonFieldDir.z = mDampedNewtonFieldStrength = mNewtonFieldDir.x = mNewtonFieldDir.y
	    = mNewtonFieldDir.z = mNewtonFieldStrength = _180.x = _180.y = _180.z = mJitterStrength = _194.x = _194.z = _1A0 = _1A4 = 0.0f;
	_15C                                                                                                                        = 1.0f;
	_194.y                                                                                                                      = 1.0f;
	mVortexCenter.y                                                                                                             = 1.0f;
	_18C = mSolidFieldType = _18D = mFreePtclMotionTime = 0;
	mMaxFrame                                           = 80;
	mMaxPasses                                          = 0;
	_88                                                 = 0.0f;
	mPassTimer                                          = 0.0f;

	mCurrentFrame = 0;
	mCurrentPass  = 0;
	mBlendFactor = mZMode = 0;
	mOrientedNormalVector.set(0.0f, 1.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8019FED4
 * Size:	0001DC
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

			Colour col(ptcl->mPrimaryColor.r, ptcl->mPrimaryColor.g, ptcl->mPrimaryColor.b, RoundOff(ptcl->mPrimaryColor.a * ptcl->_54));
			gfx.setPrimEnv(&col, &ptcl->mEnvColor);
			gfx.drawRotParticle(*gfx.mCamera, ptcl->mPosition + ptcl->mLocalOffset, -ptcl->_58, ptcl->_24 * ptcl->_50 * 25.0f);

			list = next;
		}
	}
}

/*
 * --INFO--
 * Address:	801A00B0
 * Size:	0006A8
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
	u32 badCompiler1[3];
	Matrix4f mtx1; // 0x104
	Mtx mtx2;      // 0xD4
	Mtx mtx3;      // 0xA4
	Vector3f vec2;
	u32 badCompiler[3];
	Vector3f vec3;
	mtx3[2][3]      = 0.0f;
	mtx3[0][3]      = 0.0f;
	mtx3[1][3]      = 25.0f * _64;
	zenList* origin = mPtclMdlListManager.getOrigin();
	zenList* list   = mPtclMdlListManager.getTopList();
	zenList* next;
	for (list; list != origin; list = next) {
		next              = list->mNext;
		particleMdl* ptcl = (particleMdl*)list;

		f32 cosVal;
		f32 sinVal;
		Colour col(ptcl->mPrimaryColor.r, ptcl->mPrimaryColor.g, ptcl->mPrimaryColor.b, RoundOff(ptcl->mPrimaryColor.a * ptcl->_54));
		gfx.setPrimEnv(&col, &ptcl->mEnvColor);

		PSMTXIdentity(mtx2);

		f32 a  = ptcl->_24 * ptcl->_50;
		cosVal = costable[ptcl->_58 & 0x3FFC];
		sinVal = sintable[ptcl->_58 & 0x3FFC];
		(this->*mRotAxisCallBack)(mtx3, sinVal, cosVal);

		MTXTrans(mtx1.mMtx, ptcl->mPosition.x + ptcl->mLocalOffset.x, ptcl->mPosition.y + ptcl->mLocalOffset.y,
		         ptcl->mPosition.z + ptcl->mLocalOffset.z);

		PSMTXConcat(gfx.mCamera->mLookAtMtx.mMtx, mtx1.mMtx, mtx1.mMtx);

		Vector3f* vec;
		switch (_68.m0) {
		case 0:
			vec = &ptcl->mVelocity;
			break;
		case 1:
			vec = &ptcl->mPosition;
			break;
		}

		vec1.x = vec->x;
		vec1.y = vec->y;
		vec1.z = vec->z;

		f32 len = vec1.x * vec1.x + vec1.y * vec1.y + vec1.z * vec1.z;
		if (len != 0.0f) {
			f32 v = a * _60; // f27
			vec1.normalize();

			vec2.cross(vec1, ptcl->_5C);

			len = vec2.x * vec2.x + vec2.y * vec2.y + vec2.z * vec2.z;
			if (len != 0.0f) {
				vec2.normalize();

				if (_68.m2) {
					vec3 = ptcl->_5C;
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

				ptcl->_5C = vec3;
			} else {
				ptcl->_30  = ptcl->mLifeTime;
				ptcl->mAge = ptcl->mLifeTime;
				continue;
			}
		} else {
			ptcl->_30  = ptcl->mLifeTime;
			ptcl->mAge = ptcl->mLifeTime;
			continue;
		}

		PSMTXConcat(mtx2, mtx3, mtx2);
		PSMTXConcat(mtx1.mMtx, mtx2, mtx1.mMtx);

		GXLoadPosMtxImm(mtx1.mMtx, 0);

		if (_68.m1) {
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

	u32 badCompiler2[5];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x1F0(r1)
	  stfd      f31, 0x1E8(r1)
	  stfd      f30, 0x1E0(r1)
	  stfd      f29, 0x1D8(r1)
	  stfd      f28, 0x1D0(r1)
	  stfd      f27, 0x1C8(r1)
	  stfd      f26, 0x1C0(r1)
	  stfd      f25, 0x1B8(r1)
	  stfd      f24, 0x1B0(r1)
	  stfd      f23, 0x1A8(r1)
	  stfd      f22, 0x1A0(r1)
	  stfd      f21, 0x198(r1)
	  stfd      f20, 0x190(r1)
	  stmw      r22, 0x168(r1)
	  addi      r22, r3, 0
	  addi      r23, r4, 0
	  addi      r3, r23, 0
	  lwz       r12, 0x3B4(r23)
	  lbz       r4, 0x1CB(r22)
	  lwz       r12, 0x54(r12)
	  lbz       r5, 0x1CC(r22)
	  lbz       r6, 0x48(r22)
	  mtlr      r12
	  blrl
	  li        r3, 0
	  bl        0x70D2C
	  bl        0x6FADC
	  li        r3, 0
	  li        r4, 0x1
	  bl        0x6F2D4
	  li        r3, 0x9
	  li        r4, 0x2
	  bl        0x6F2C8
	  li        r3, 0xD
	  li        r4, 0x2
	  bl        0x6F2BC
	  li        r3, 0
	  li        r4, 0x9
	  li        r5, 0x1
	  li        r6, 0x3
	  li        r7, 0
	  bl        0x6FAEC
	  li        r3, 0
	  li        r4, 0xD
	  li        r5, 0x1
	  li        r6, 0
	  li        r7, 0
	  bl        0x6FAD4
	  lis       r3, 0x802E
	  subi      r4, r3, 0x59A0
	  li        r3, 0x9
	  li        r5, 0x6
	  bl        0x70234
	  li        r3, 0xD
	  addi      r4, r13, 0x10E0
	  li        r5, 0x2
	  bl        0x70224
	  li        r3, 0
	  bl        0x71D34
	  li        r3, 0x1
	  bl        0x70580
	  li        r3, 0x1
	  bl        0x737B4
	  li        r3, 0
	  li        r4, 0
	  li        r5, 0
	  li        r6, 0xFF
	  bl        0x73600
	  li        r3, 0
	  li        r4, 0x1
	  li        r5, 0x4
	  li        r6, 0x3C
	  li        r7, 0
	  li        r8, 0x7D
	  bl        0x70278
	  lfs       f23, -0x4C70(r2)
	  lis       r4, 0x8039
	  lis       r3, 0x8039
	  stfs      f23, 0x88(r1)
	  addi      r29, r4, 0x4840
	  addi      r30, r3, 0x840
	  stfs      f23, 0x84(r1)
	  lis       r28, 0x4330
	  lis       r31, 0xCC01
	  stfs      f23, 0xD0(r1)
	  lfs       f1, -0x4C24(r2)
	  stfs      f23, 0x80(r1)
	  lfd       f24, -0x4C38(r2)
	  stfs      f23, 0xB0(r1)
	  lfs       f25, -0x4C30(r2)
	  lfs       f0, 0x64(r22)
	  lfd       f26, -0x4C48(r2)
	  fmuls     f0, f1, f0
	  stfs      f0, 0xC0(r1)
	  lwz       r27, 0x28(r22)
	  lwz       r26, 0x8(r27)
	  b         .loc_0x65C

	.loc_0x18C:
	  lbz       r0, 0x2B(r26)
	  lfs       f0, 0x54(r26)
	  stw       r0, 0x164(r1)
	  lwz       r25, 0x8(r26)
	  stw       r28, 0x160(r1)
	  lfd       f1, 0x160(r1)
	  fsubs     f1, f1, f24
	  fmuls     f0, f1, f0
	  fcmpo     cr0, f0, f23
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1C0
	  fadds     f0, f25, f0
	  b         .loc_0x1C4

	.loc_0x1C0:
	  fsubs     f0, f0, f25

	.loc_0x1C4:
	  lbz       r7, 0x2A(r26)
	  fctiwz    f0, f0
	  lbz       r6, 0x29(r26)
	  mr        r3, r23
	  lbz       r0, 0x28(r26)
	  stfd      f0, 0x160(r1)
	  addi      r4, r1, 0x74
	  stb       r0, 0x74(r1)
	  addi      r5, r26, 0x68
	  lwz       r0, 0x164(r1)
	  stb       r6, 0x75(r1)
	  stb       r7, 0x76(r1)
	  stb       r0, 0x77(r1)
	  lwz       r12, 0x3B4(r23)
	  lwz       r12, 0xB0(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r1, 0xD4
	  bl        0x5D8D8
	  lhz       r0, 0x58(r26)
	  mr        r3, r22
	  lfs       f2, 0x24(r26)
	  addi      r4, r1, 0xA4
	  rlwinm    r0,r0,30,18,29
	  add       r5, r29, r0
	  lfs       f1, 0x50(r26)
	  lfs       f0, 0x0(r5)
	  addi      r5, r1, 0x78
	  fmuls     f28, f2, f1
	  addi      r6, r1, 0x7C
	  stfs      f0, 0x7C(r1)
	  addi      r12, r22, 0x1F4
	  lhz       r0, 0x58(r26)
	  rlwinm    r0,r0,30,18,29
	  add       r7, r30, r0
	  lfs       f0, 0x0(r7)
	  stfs      f0, 0x78(r1)
	  bl        0x74A28
	  nop
	  lfs       f1, 0xC(r26)
	  addi      r3, r1, 0x104
	  lfs       f0, 0x18(r26)
	  lfs       f4, 0x10(r26)
	  lfs       f2, 0x1C(r26)
	  fadds     f1, f1, f0
	  lfs       f3, 0x14(r26)
	  lfs       f0, 0x20(r26)
	  fadds     f2, f4, f2
	  fadds     f3, f3, f0
	  bl        0x5DAA8
	  lwz       r3, 0x2E4(r23)
	  addi      r4, r1, 0x104
	  addi      r5, r4, 0
	  addi      r3, r3, 0x1E0
	  bl        0x5D874
	  lbz       r0, 0x68(r22)
	  rlwinm    r0,r0,25,31,31
	  cmpwi     r0, 0x1
	  beq-      .loc_0x2C8
	  bge-      .loc_0x2CC
	  cmpwi     r0, 0
	  bge-      .loc_0x2C0
	  b         .loc_0x2CC

	.loc_0x2C0:
	  addi      r24, r26, 0x34
	  b         .loc_0x2CC

	.loc_0x2C8:
	  addi      r24, r26, 0xC

	.loc_0x2CC:
	  lfs       f30, 0x0(r24)
	  lfs       f31, 0x4(r24)
	  fmuls     f1, f30, f30
	  lfs       f29, 0x8(r24)
	  fmuls     f0, f31, f31
	  fmuls     f2, f29, f29
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x514
	  lfs       f0, 0x60(r22)
	  fmuls     f27, f28, f0
	  bl        -0x19276C
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x314
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1

	.loc_0x314:
	  lfs       f4, 0x60(r26)
	  lfs       f5, 0x5C(r26)
	  lfs       f1, 0x64(r26)
	  fmuls     f0, f29, f4
	  fmuls     f3, f29, f5
	  fmuls     f2, f30, f1
	  fmuls     f1, f31, f1
	  fmuls     f4, f30, f4
	  fsubs     f21, f3, f2
	  fsubs     f20, f1, f0
	  fmuls     f2, f31, f5
	  fmuls     f0, f21, f21
	  fmuls     f1, f20, f20
	  fsubs     f22, f4, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f22, f22
	  fadds     f1, f1, f0
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x4EC
	  bl        -0x1927D0
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x378
	  fdivs     f20, f20, f1
	  fdivs     f21, f21, f1
	  fdivs     f22, f22, f1

	.loc_0x378:
	  lbz       r0, 0x68(r22)
	  rlwinm.   r0,r0,27,31,31
	  beq-      .loc_0x3FC
	  lwz       r3, 0x5C(r26)
	  lwz       r0, 0x60(r26)
	  stw       r3, 0x80(r1)
	  stw       r0, 0x84(r1)
	  lwz       r0, 0x64(r26)
	  stw       r0, 0x88(r1)
	  lfs       f4, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  lfs       f5, 0x80(r1)
	  fmuls     f3, f4, f22
	  fmuls     f2, f0, f21
	  fmuls     f1, f0, f20
	  fmuls     f0, f5, f22
	  fsubs     f30, f3, f2
	  fmuls     f3, f5, f21
	  fsubs     f31, f1, f0
	  fmuls     f2, f4, f20
	  fmuls     f1, f30, f30
	  fmuls     f0, f31, f31
	  fsubs     f29, f3, f2
	  fadds     f0, f1, f0
	  fmuls     f1, f29, f29
	  fadds     f1, f1, f0
	  bl        -0x192850
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x47C
	  fdivs     f30, f30, f1
	  fdivs     f31, f31, f1
	  fdivs     f29, f29, f1
	  b         .loc_0x47C

	.loc_0x3FC:
	  fmuls     f1, f21, f29
	  fmuls     f0, f22, f31
	  fmuls     f3, f22, f30
	  fmuls     f2, f20, f29
	  fsubs     f4, f1, f0
	  fmuls     f1, f20, f31
	  fmuls     f0, f21, f30
	  fsubs     f2, f3, f2
	  stfs      f4, 0x80(r1)
	  fsubs     f0, f1, f0
	  stfs      f2, 0x84(r1)
	  stfs      f0, 0x88(r1)
	  lfs       f1, 0x80(r1)
	  lfs       f0, 0x84(r1)
	  lfs       f2, 0x88(r1)
	  fmuls     f1, f1, f1
	  fmuls     f0, f0, f0
	  fmuls     f2, f2, f2
	  fadds     f0, f1, f0
	  fadds     f1, f2, f0
	  bl        -0x1928BC
	  fcmpu     cr0, f23, f1
	  beq-      .loc_0x47C
	  lfs       f0, 0x80(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x80(r1)
	  lfs       f0, 0x84(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x84(r1)
	  lfs       f0, 0x88(r1)
	  fdivs     f0, f0, f1
	  stfs      f0, 0x88(r1)

	.loc_0x47C:
	  fmuls     f2, f20, f28
	  lfs       f0, 0x80(r1)
	  fmuls     f1, f21, f28
	  lwz       r3, 0x80(r1)
	  fmuls     f4, f22, f28
	  stfs      f2, 0xD4(r1)
	  fmuls     f3, f30, f27
	  fmuls     f2, f31, f27
	  lwz       r0, 0x84(r1)
	  stfs      f1, 0xE4(r1)
	  fmuls     f1, f29, f27
	  stfs      f4, 0xF4(r1)
	  fmuls     f0, f0, f28
	  stfs      f3, 0xD8(r1)
	  stfs      f2, 0xE8(r1)
	  stfs      f1, 0xF8(r1)
	  stfs      f0, 0xDC(r1)
	  lfs       f0, 0x84(r1)
	  fmuls     f0, f0, f28
	  stfs      f0, 0xEC(r1)
	  lfs       f0, 0x88(r1)
	  fmuls     f0, f0, f28
	  stfs      f0, 0xFC(r1)
	  stw       r3, 0x5C(r26)
	  stw       r0, 0x60(r26)
	  lwz       r0, 0x88(r1)
	  stw       r0, 0x64(r26)
	  b         .loc_0x53C

	.loc_0x4EC:
	  lha       r0, 0x2C(r26)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  stw       r28, 0x160(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f0, f0, f26
	  stfs      f0, 0x30(r26)
	  lha       r0, 0x2C(r26)
	  sth       r0, 0x2E(r26)
	  b         .loc_0x658

	.loc_0x514:
	  lha       r0, 0x2C(r26)
	  xoris     r0, r0, 0x8000
	  stw       r0, 0x164(r1)
	  stw       r28, 0x160(r1)
	  lfd       f0, 0x160(r1)
	  fsubs     f0, f0, f26
	  stfs      f0, 0x30(r26)
	  lha       r0, 0x2C(r26)
	  sth       r0, 0x2E(r26)
	  b         .loc_0x658

	.loc_0x53C:
	  addi      r3, r1, 0xD4
	  addi      r5, r3, 0
	  addi      r4, r1, 0xA4
	  bl        0x5D5C8
	  addi      r3, r1, 0x104
	  addi      r5, r3, 0
	  addi      r4, r1, 0xD4
	  bl        0x5D5B8
	  addi      r3, r1, 0x104
	  li        r4, 0
	  bl        0x73E40
	  lbz       r0, 0x68(r22)
	  rlwinm.   r0,r0,26,31,31
	  beq-      .loc_0x608
	  li        r3, 0x80
	  li        r4, 0
	  li        r5, 0x8
	  bl        0x705A4
	  li        r9, 0
	  stb       r9, -0x8000(r31)
	  li        r8, 0x1
	  li        r7, 0x2
	  stb       r9, -0x8000(r31)
	  li        r6, 0x3
	  li        r5, 0x4
	  stb       r9, -0x8000(r31)
	  li        r4, 0x5
	  li        r3, 0x6
	  stb       r9, -0x8000(r31)
	  li        r0, 0x7
	  stb       r8, -0x8000(r31)
	  stb       r8, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r7, -0x8000(r31)
	  stb       r7, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r6, -0x8000(r31)
	  stb       r6, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r5, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r4, -0x8000(r31)
	  stb       r8, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r3, -0x8000(r31)
	  stb       r7, -0x8000(r31)
	  stb       r9, -0x8000(r31)
	  stb       r0, -0x8000(r31)
	  stb       r6, -0x8000(r31)
	  b         .loc_0x658

	.loc_0x608:
	  li        r3, 0x80
	  li        r4, 0
	  li        r5, 0x4
	  bl        0x70510
	  li        r5, 0
	  stb       r5, -0x8000(r31)
	  li        r4, 0x1
	  li        r3, 0x2
	  stb       r5, -0x8000(r31)
	  li        r0, 0x3
	  stb       r5, -0x8000(r31)
	  stb       r5, -0x8000(r31)
	  stb       r4, -0x8000(r31)
	  stb       r4, -0x8000(r31)
	  stb       r5, -0x8000(r31)
	  stb       r3, -0x8000(r31)
	  stb       r3, -0x8000(r31)
	  stb       r5, -0x8000(r31)
	  stb       r0, -0x8000(r31)
	  stb       r0, -0x8000(r31)

	.loc_0x658:
	  mr        r26, r25

	.loc_0x65C:
	  cmplw     r26, r27
	  bne+      .loc_0x18C
	  lmw       r22, 0x168(r1)
	  lwz       r0, 0x1F4(r1)
	  lfd       f31, 0x1E8(r1)
	  lfd       f30, 0x1E0(r1)
	  lfd       f29, 0x1D8(r1)
	  lfd       f28, 0x1D0(r1)
	  lfd       f27, 0x1C8(r1)
	  lfd       f26, 0x1C0(r1)
	  lfd       f25, 0x1B8(r1)
	  lfd       f24, 0x1B0(r1)
	  lfd       f23, 0x1A8(r1)
	  lfd       f22, 0x1A0(r1)
	  lfd       f21, 0x198(r1)
	  lfd       f20, 0x190(r1)
	  addi      r1, r1, 0x1F0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	801A0758
 * Size:	00003C
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

/*
 * --INFO--
 * Address:	801A0794
 * Size:	00003C
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

/*
 * --INFO--
 * Address:	801A07D0
 * Size:	00003C
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

/*
 * --INFO--
 * Address:	801A080C
 * Size:	000054
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

/*
 * --INFO--
 * Address:	801A0860
 * Size:	00005C
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

/*
 * --INFO--
 * Address:	801A08BC
 * Size:	00005C
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

/*
 * --INFO--
 * Address:	801A0918
 * Size:	00008C
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

/*
 * --INFO--
 * Address:	801A09A4
 * Size:	000110
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

/*
 * --INFO--
 * Address:	801A0AB4
 * Size:	000148
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
		gfx.drawParticle(*gfx.mCamera, child->mPosition + child->mLocalOffset, 25.0f * child->_24);

		list = next;
	}
}

/*
 * --INFO--
 * Address:	801A0BFC
 * Size:	0000CC
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

/*
 * --INFO--
 * Address:	801A0CC8
 * Size:	000034
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

/*
 * --INFO--
 * Address:	801A0CFC
 * Size:	0000F0
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

/*
 * --INFO--
 * Address:	801A0DEC
 * Size:	000070
 */
zen::particleMdl* zen::particleGenerator::pmGetParticle()
{
	zenList* ptcl = mMdlMgr->getPtcl();
	if (ptcl) {
		mPtclMdlListManager.put(ptcl);
	}
	return (particleMdl*)ptcl;
}

/*
 * --INFO--
 * Address:	801A0EB0
 * Size:	000074
 */
zen::particleChildMdl* zen::particleGenerator::pmGetParticleChild()
{
	zenList* child = mMdlMgr->getPtclChild();
	if (child) {
		mPtclChildListManager.put(child);
	}
	return (particleChildMdl*)child;
}
