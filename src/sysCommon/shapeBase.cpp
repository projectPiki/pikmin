#include "Shape.h"

#include "Animator.h"
#include "Joint.h"
#include "Mesh.h"
#include "timers.h"
#include "Colour.h"
#include "Material.h"
#include "Collision.h"
#include "Texture.h"
#include "Vector.h"
#include "CmdStream.h"
#include "String.h"
#include "Font.h"
#include "sysNew.h"
#include "system.h"
#include "PVW.h"
#include "Delegate.h"
#include "CinematicPlayer.h"
#include "Graphics.h"
#include "Dolphin/mtx.h"
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
DEFINE_PRINT("shapeBase")

Vector3f fnVerts[0x200];
Vector3f fnNorms[0x200];
Vector2f fnTexs[0x200];
u8 matUsed[0x100];
int matIndex;
int usedIndex;
int _dlindx;

static char* modes[5] = {
	"NONE", "OPA", "TEX", "NONE", "XLU",
};

/*
 * --INFO--
 * Address:	........
 * Size:	0000DC
 */
void Envelope::read(RandomAccessStream& stream)
{
	mIndexCount = stream.readShort();
	// why would you do this.
	void* why = new u8[8 * mIndexCount];
	mIndices  = (s32*)why;
	mWeights  = (f32*)&((f32*)why)[mIndexCount];
	for (int i = 0; i < mIndexCount; i++) {
		mIndices[i] = stream.readShort();
		mWeights[i] = stream.readFloat();
	}
}

/*
 * --INFO--
 * Address:	80029F98
 * Size:	000100
 * Regswaps
 */
void DispList::read(RandomAccessStream& stream)
{
	// Match stack size with the original function
	u32 badCompiler;

	mFlags      = stream.readInt();
	mFaceCount  = stream.readInt();
	mDataLength = stream.readInt();

	stream.skipPadding(0x20);

	mData = new (0x20) char[mDataLength];
	stream.read(mData, mDataLength);
}

/*
 * --INFO--
 * Address:	8002A098
 * Size:	00013C
 */
void MtxGroup::read(RandomAccessStream& stream)
{
	mDependencyLength = stream.readInt();
	if (mDependencyLength) {
		mDependencyList = new int[mDependencyLength];
		for (int i = 0; i < mDependencyLength; i++) {
			mDependencyList[i] = stream.readShort();
		}
	}

	mDispListLength = stream.readInt();
	if (mDispListLength) {
		mDispList = new DispList[mDispListLength];
		for (int i = 0; i < mDispListLength; i++) {
			mDispList[i].read(stream);
		}
	}
}

/*
 * --INFO--
 * Address:	8002A268
 * Size:	000110
 */
void Mesh::read(RandomAccessStream& stream)
{
	mParentJoint      = stream.readInt();
	mVertexDescriptor = stream.readInt();
	mMtxGroupCount    = stream.readInt();

	if (mMtxGroupCount) {
		mMtxGroupList = new MtxGroup[mMtxGroupCount];
		mMtxDepIndex  = 0;
		for (int i = 0; i < mMtxGroupCount; i++) {
			mMtxGroupList[i].read(stream);

			if (mMtxGroupList[i].mDependencyLength > mMtxDepIndex) {
				mMtxDepIndex = mMtxGroupList[i].mDependencyLength;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void Joint::recShowHierarchy()
{
	for (Joint* joint = this; joint != nullptr; joint = static_cast<Joint*>(joint->mNext)) {
		PRINT("got joint %08x\n", joint);

		if (joint->mChild) {
			static_cast<Joint*>(joint->mChild)->recShowHierarchy();
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void Joint::overrideAnim(AnimContext* anim)
{
	mParentShape->mAnimOverrides[mIndex] = anim;
}

/*
 * --INFO--
 * Address:	8002A38C
 * Size:	0000A4
 */
void Joint::recOverrideAnim(AnimContext* anim)
{
	for (Joint* joint = this; joint != nullptr; joint = static_cast<Joint*>(joint->mNext)) {
		joint->overrideAnim(anim);

		if (joint->mChild) {
			static_cast<Joint*>(joint->mChild)->recOverrideAnim(anim);
		}
	}
}

/*
 * --INFO--
 * Address:	8002A430
 * Size:	0002DC
 */
void Joint::read(RandomAccessStream& stream)
{
	// Match stack size with the original function
	u32 badCompiler;

	mParentIndex = stream.readInt();

	int flags      = stream.readInt();
	mUseVolume     = flags & 0x1;
	mUseLightGroup = (flags & 0x4000) != 0;

	mBounds.mMin.read(stream);
	mBounds.mMax.read(stream);
	stream.readFloat();

	mScale.read(stream);
	mRotation.read(stream);
	mTranslation.read(stream);

	mMatPolyCount = stream.readInt();
	mMatPoly.initCore("");
	for (int i = 0; i < mMatPolyCount; i++) {
		MatPoly* mPoly    = new MatPoly();
		mPoly->mIndex     = stream.readShort();
		mPoly->mMeshIndex = stream.readShort();
		mMatPoly.add(mPoly);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00043C
 */
void Joint::render(Graphics& gfx)
{
	// Only in the DLL.
}

/*
 * --INFO--
 * Address:	8002A70C
 * Size:	00004C
 */
void AnimContext::animate(f32 time)
{
	mCurrentFrame += gsys->getFrameTime() * time;

	int frame = static_cast<int>(mCurrentFrame);
	if (frame >= mData->mTotalFrameCount) {
		mCurrentFrame = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	8002A758
 * Size:	0001C4
 */
static f32 extract(f32 currTime, AnimParam& param, DataChunk& data)
{
	int dataSize  = (param.mFlags == 0) ? 3 : 4;
	bool isActive = false;
	int offset    = param.mDataOffset;

	// Early return if current time is not active within any data range
	for (int i = 0; i < param.mEntryNum - 1; ++i) {
		if (data.mData[offset] <= currTime && data.mData[offset + dataSize] >= currTime) {
			isActive = true;
			break;
		}
		offset += dataSize;
	}

	if (!isActive) {
		return data.mData[dataSize * (param.mEntryNum - 1) + param.mDataOffset + 1];
	}

	f32 time1;
	f32 startTangent;
	f32 startValue;
	f32 time2;
	f32 endValue;
	f32 endTangent;
	if (dataSize == 3) {
		startTangent = data.mData[offset + 2];
		time1        = data.mData[offset];
		startValue   = data.mData[offset + 1];
		offset += dataSize;
		endTangent = data.mData[offset + 2];
		time2      = data.mData[offset];
		endValue   = data.mData[offset + 1];

	} else {
		time1        = data.mData[offset];
		startTangent = data.mData[offset + 3];
		startValue   = data.mData[offset + 1];
		offset += dataSize;
		time2      = data.mData[offset];
		endValue   = data.mData[offset + 1];
		endTangent = data.mData[offset + 2];
	}

	// Interpolation calculations
	// Chat-GPT says Hermite Interpolation
	const f32 fps /*maybe*/ = 30.f;
	f32 t                   = (currTime - time1) * (1.0f / fps);
	f32 frameDelta          = fps / (time2 - time1);
	f32 tSqr                = t * t;
	f32 deltaSqr            = frameDelta * frameDelta;
	f32 tCube               = tSqr * t;
	f32 deltaCube           = deltaSqr * frameDelta;

	return (2.0f * tCube * deltaCube - 3.0f * tSqr * deltaSqr + 1.0f) * startValue
	     + (-2.0f * tCube * deltaCube + 3.0f * tSqr * deltaSqr) * endValue
	     + (tCube * deltaSqr - 2.0f * tSqr * frameDelta + t) * startTangent + (tCube * deltaSqr - tSqr * frameDelta) * endTangent;

	u8 badCompiler[0x24];

	/*
	.loc_0x0:
	  stwu      r1, -0x50(r1)
	  stfd      f31, 0x48(r1)
	  stfd      f30, 0x40(r1)
	  lwz       r0, 0x8(r3)
	  cmpwi     r0, 0
	  bne-      .loc_0x20
	  li        r6, 0x3
	  b         .loc_0x24

	.loc_0x20:
	  li        r6, 0x4

	.loc_0x24:
	  lwz       r5, 0x0(r3)
	  rlwinm    r7,r6,2,0,29
	  lwz       r0, 0x4(r3)
	  li        r10, 0
	  subic.    r9, r5, 0x1
	  mr        r11, r0
	  rlwinm    r5,r0,2,0,29
	  mtctr     r9
	  ble-      .loc_0x88

	.loc_0x48:
	  lwz       r8, 0x8(r4)
	  lfsx      f0, r8, r5
	  fcmpo     cr0, f0, f1
	  cror      2, 0, 0x2
	  bne-      .loc_0x7C
	  add       r0, r11, r6
	  rlwinm    r0,r0,2,0,29
	  lfsx      f0, r8, r0
	  fcmpo     cr0, f0, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x7C
	  li        r10, 0x1
	  b         .loc_0x88

	.loc_0x7C:
	  add       r5, r5, r7
	  add       r11, r11, r6
	  bdnz+     .loc_0x48

	.loc_0x88:
	  rlwinm.   r0,r10,0,24,31
	  bne-      .loc_0xB0
	  mullw     r0, r6, r9
	  lwz       r3, 0x4(r3)
	  lwz       r4, 0x8(r4)
	  add       r0, r3, r0
	  rlwinm    r0,r0,2,0,29
	  add       r3, r4, r0
	  lfs       f1, 0x4(r3)
	  b         .loc_0x1B4

	.loc_0xB0:
	  cmpwi     r6, 0x3
	  bne-      .loc_0xEC
	  lwz       r3, 0x8(r4)
	  rlwinm    r0,r11,2,0,29
	  add       r11, r11, r6
	  addi      r5, r3, 0x8
	  lfsx      f4, r3, r0
	  rlwinm    r4,r11,2,0,29
	  lfsx      f8, r5, r0
	  lfsx      f0, r5, r4
	  addi      r5, r3, 0x4
	  lfsx      f7, r5, r0
	  lfsx      f2, r3, r4
	  lfsx      f9, r5, r4
	  b         .loc_0x120

	.loc_0xEC:
	  rlwinm    r0,r11,2,0,29
	  lwz       r3, 0x8(r4)
	  add       r11, r11, r6
	  rlwinm    r5,r11,2,0,29
	  lfsx      f4, r3, r0
	  addi      r6, r3, 0x4
	  lfsx      f2, r3, r5
	  add       r4, r3, r0
	  lfsx      f7, r6, r0
	  add       r3, r3, r5
	  lfs       f8, 0xC(r4)
	  lfsx      f9, r6, r5
	  lfs       f0, 0x8(r3)

	.loc_0x120:
	  fsubs     f2, f2, f4
	  lfs       f3, -0x7D18(r2)
	  fsubs     f4, f1, f4
	  lfs       f5, -0x7D1C(r2)
	  lfs       f6, -0x7D14(r2)
	  fdivs     f12, f3, f2
	  lfs       f2, -0x7D10(r2)
	  lfs       f1, -0x7D08(r2)
	  lfs       f3, -0x7D0C(r2)
	  fmuls     f11, f5, f4
	  fmuls     f10, f12, f12
	  fmuls     f13, f11, f11
	  fmuls     f30, f10, f12
	  fmuls     f31, f13, f11
	  fmuls     f4, f2, f13
	  fmuls     f5, f6, f13
	  fmuls     f2, f6, f31
	  fmuls     f1, f1, f31
	  fmuls     f6, f4, f10
	  fmuls     f2, f2, f30
	  fmuls     f1, f1, f30
	  fmuls     f10, f31, f10
	  fmuls     f4, f5, f12
	  fsubs     f2, f2, f6
	  fadds     f1, f1, f6
	  fsubs     f4, f10, f4
	  fadds     f2, f3, f2
	  fmuls     f5, f13, f12
	  fadds     f3, f11, f4
	  fmuls     f2, f7, f2
	  fmuls     f1, f9, f1
	  fsubs     f4, f10, f5
	  fmuls     f3, f8, f3
	  fadds     f1, f2, f1
	  fmuls     f2, f0, f4
	  fadds     f0, f3, f1
	  fadds     f1, f2, f0

	.loc_0x1B4:
	  lfd       f31, 0x48(r1)
	  lfd       f30, 0x40(r1)
	  addi      r1, r1, 0x50
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8002A998
 * Size:	000334
 */
CamDataInfo::CamDataInfo()
{
	mCamera.mNear        = 1.0f;
	mCamera.mFar         = 15000.0f;
	mCamera.mAspectRatio = 640.0f / 480.0f;
	mUseStaticCamera     = 0;
};

/*
 * --INFO--
 * Address:	8002A998
 * Size:	000334
 */
void CamDataInfo::update(f32 p1, Matrix4f& mtx)
{
	volatile f32 val1;
	volatile f32 val2;
	AnimParam* params1 = mCamPosAnims;
	for (int i = 0; i < 3; i++) { // x, y, z
		AnimParam& thisParam = params1[i];
		switch (thisParam.mEntryNum) {
		case 0:
			((f32*)&mCamera.mPosition)[i] = 0.0f;
			break;
		case 1:
			((f32*)&mCamera.mPosition)[i] = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			((f32*)&mCamera.mPosition)[i] = extract(p1, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
	}

	AnimParam* params2 = mCamLatAnims;
	for (int i = 0; i < 3; i++) {
		AnimParam& thisParam = params2[i];
		switch (thisParam.mEntryNum) {
		case 0:
			((f32*)&mCamera.mFocus)[i] = 0.0f;
			break;
		case 1:
			((f32*)&mCamera.mFocus)[i] = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			((f32*)&mCamera.mFocus)[i] = extract(p1, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
	}

	AnimParam* params3 = mCamTwistAnims;
	for (int i = 0; i < 1; i++) {
		AnimParam& thisParam = params3[i];
		switch (thisParam.mEntryNum) {
		case 0:
			val1 = 1.0f;
			break;
		case 1:
			val1 = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			val1 = extract(p1, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
	}

	AnimParam* params4 = mCamFovyAnims;
	for (int i = 0; i < 1; i++) {
		AnimParam& thisParam = params4[i];
		switch (thisParam.mEntryNum) {
		case 0:
			val2 = 1.0f;
			break;
		case 1:
			val2 = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			val2 = extract(p1, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
	}

	mCamera.mPosition.multMatrix(mtx);
	mCamera.mFocus.multMatrix(mtx);
	mCamera.mFov = val2;

	if (mBlendRatio > 0.0f) {
		mCamera.mFov = (mTargetFov - mCamera.mFov) * mBlendRatio + mCamera.mFov;

		mCamera.mPosition.x += (mCameraPosition.x - mCamera.mPosition.x) * mBlendRatio;
		mCamera.mPosition.y += (mCameraPosition.y - mCamera.mPosition.y) * mBlendRatio;
		mCamera.mPosition.z += (mCameraPosition.z - mCamera.mPosition.z) * mBlendRatio;

		mCamera.mFocus.x += (mCameraLookAt.x - mCamera.mFocus.x) * mBlendRatio;
		mCamera.mFocus.y += (mCameraLookAt.y - mCamera.mFocus.y) * mBlendRatio;
		mCamera.mFocus.z += (mCameraLookAt.z - mCamera.mFocus.z) * mBlendRatio;

	} else if (mUseStaticCamera) {
		mCamera.mFocus = mStaticLookAt;
	}

	mCamera.calcLookAt(mCamera.mPosition, mCamera.mFocus, nullptr);

	u32 badCompiler[4];
}

/*
 * --INFO--
 * Address:	8002ACCC
 * Size:	000264
 */
void LightDataInfo::update(f32 p1)
{
	Vector3f vec1;
	Vector3f vec2;

	AnimParam* params1 = mLightPosAnims;
	for (int i = 0; i < 3; i++) {
		AnimParam& thisParam = params1[i];
		switch (thisParam.mEntryNum) {
		case 0:
			((f32*)&vec1)[i] = 1.0f;
			break;
		case 1:
			((f32*)&vec1)[i] = mSceneData->mLightAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			((f32*)&vec1)[i] = extract(p1, thisParam, *mSceneData->mLightAnimations);
			break;
		}
	}

	f32* tmp2          = (f32*)&vec2;
	AnimParam* params2 = mLightColourAnims;
	for (int i = 0; i < 3; i++) {
		AnimParam& thisParam = params2[i];
		switch (thisParam.mEntryNum) {
		case 0:
			tmp2[i] = 1.0f;
			break;
		case 1:
			tmp2[i] = mSceneData->mLightAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			tmp2[i] = extract(p1, thisParam, *mSceneData->mLightAnimations);
			break;
		}
	}

	for (int i = 0; i < 1; i++) {
		AnimParam* params3   = mLightVisibleAnims;
		AnimParam& thisParam = params3[i];
		switch (thisParam.mEntryNum) {
		case 0:
			((f32*)&vec2)[i - 1] = 1.0f;
			break;
		case 1:
			((f32*)&vec2)[i - 1] = mSceneData->mLightAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			((f32*)&vec2)[i - 1] = extract(p1, thisParam, *mSceneData->mLightAnimations);
			break;
		}
	}

	mIsActive = ((f32*)&vec2)[-1] == 1.0f;

	if (mIsActive) {
		mLight.mDiffuseColour.set(vec2.x, vec2.y, vec2.z, 255);
		mLight.mPosition.set(vec1);
		mLight.mDistancedRange = 1000.0f;
		mLight.update();
	}

	u32 badCompiler[3];
}

/*
 * --INFO--
 * Address:	8002AF30
 * Size:	000D4C
 */
void SceneData::parse(CmdStream* stream)
{
	mCameraAnimations = nullptr;
	mLightAnimations  = nullptr;

	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);

		if (stream->isToken("<SCENE_KEY_ANM_INFO>")) {
			stream->getToken(true);
			getAnimInfo(stream);
		} else if (stream->isToken("<KEY_CAMERA_ANM>")) {
			mCameraAnimations = new DataChunk();
			mCameraAnimations->getData(stream);
		} else if (stream->isToken("<KEY_CAMERA_TABLE>")) {
			stream->getToken(true);

			int index = -1;
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);
				if (stream->isToken("index")) {
					sscanf(stream->getToken(true), "%d", &index);

				} else if (stream->isToken("name")) {
					stream->getToken(true);

				} else if (stream->isToken("cam_pos_x")) {
					AnimParam* param = &mCameraData[index].mCamPosAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_pos_y")) {
					AnimParam* param = &mCameraData[index].mCamPosAnims[1];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_pos_z")) {
					AnimParam* param = &mCameraData[index].mCamPosAnims[2];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_lat_x")) {
					AnimParam* param = &mCameraData[index].mCamLatAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_lat_y")) {
					AnimParam* param = &mCameraData[index].mCamLatAnims[1];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_lat_z")) {
					AnimParam* param = &mCameraData[index].mCamLatAnims[2];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_twist")) {
					AnimParam* param = &mCameraData[index].mCamTwistAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_fovy")) {
					AnimParam* param = &mCameraData[index].mCamFovyAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_near")) {
					AnimParam* param = &mCameraData[index].mCamNearAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("cam_far")) {
					AnimParam* param = &mCameraData[index].mCamFarAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);
				}
			}

			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
		} else if (stream->isToken("<KEY_DIFFUSE_LIGHT_ANM>")) {
			mLightAnimations = new DataChunk();
			mLightAnimations->getData(stream);

		} else if (stream->isToken("<KEY_DIFFUSE_LIGHT_TABLE>")) {
			stream->getToken(true);

			int index = -1;
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);
				if (stream->isToken("index")) {
					sscanf(stream->getToken(true), "%d", &index);

				} else if (stream->isToken("name")) {
					stream->getToken(true);

				} else if (stream->isToken("light_pos_x")) {
					AnimParam* param = &mLightData[index].mLightPosAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("light_pos_y")) {
					AnimParam* param = &mLightData[index].mLightPosAnims[1];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("light_pos_z")) {
					AnimParam* param = &mLightData[index].mLightPosAnims[2];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("light_r_param")) {
					AnimParam* param = &mLightData[index].mLightColourAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("light_g_param")) {
					AnimParam* param = &mLightData[index].mLightColourAnims[1];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("light_b_param")) {
					AnimParam* param = &mLightData[index].mLightColourAnims[2];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);

				} else if (stream->isToken("light_visible")) {
					AnimParam* param = &mLightData[index].mLightVisibleAnims[0];
					sscanf(stream->getToken(true), "%d", &param->mEntryNum);
					sscanf(stream->getToken(true), "%d", &param->mDataOffset);
					sscanf(stream->getToken(true), "%d", &param->mFlags);
				}
			}

			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
		} else {
			stream->getToken(true);
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);
			}

			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8002BD1C
 * Size:	0001F4
 */
void SceneData::getAnimInfo(CmdStream* stream)
{
	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);

		if (stream->isToken("numcameras")) {
			sscanf(stream->getToken(true), "%d", &mNumCameras);
			mCameraData = new CamDataInfo[mNumCameras];

			for (int i = 0; i < mNumCameras; i++) {
				mCameraData[i].mSceneData = this;
				mCameraData[i].mCameraIdx = i;
			}

		} else if (stream->isToken("numDifLights")) {
			sscanf(stream->getToken(true), "%d", &mNumLights);
			mLightData = new LightDataInfo[mNumLights];

			for (int i = 0; i < mNumLights; i++) {
				mLightData[i].mSceneData = this;
				mLightData[i].mLightIdx  = i;
			}

		} else if (stream->isToken("numframes")) {
			sscanf(stream->getToken(true), "%d", &mNumFrames);

		} else {
			stream->skipLine();
		}
	}

	if (!stream->endOfCmds()) {
		stream->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	8002BF4C
 * Size:	000370
 */
void AnimData::extractSRT(SRT& srt, int, AnimDataInfo* info, f32 p4)
{
	if (info->mFlags & 0x8000) {
		return;
	}

	if (!(info->mFlags & 0x8)) {
		f32* scale = (f32*)&srt.mScale;
		for (int i = 0; i < 3; i++) {
			AnimParam& param = info->mScale[i];
			int offset;
			if (int(p4) < param.mEntryNum) {
				offset = param.mDataOffset + int(p4);
			} else {
				offset = param.mDataOffset + (param.mEntryNum - 1);
			}

			scale[i] = mScaleDataBlock->mData[offset];
		}

		if ((info->mFlags & 7) == 7) {
			info->mFlags |= 8;
		}
	}

	if (!(info->mFlags & 0x80)) {
		f32* rotate = (f32*)&srt.mRotation;
		for (int i = 0; i < 3; i++) {
			AnimParam& param = info->mRotation[i];
			int offset;
			if (int(p4) < param.mEntryNum) {
				offset = param.mDataOffset + int(p4);
			} else {
				offset = param.mDataOffset + (param.mEntryNum - 1);
			}

			rotate[i] = mRotateDataBlock->mData[offset];
		}

		if ((info->mFlags & 0x70) == 0x70) {
			info->mFlags |= 0x80;
		}
	}

	if (!(info->mFlags & 0x800)) {
		f32* transl = (f32*)&srt.mTranslation;
		for (int i = 0; i < 3; i++) {
			AnimParam& param = info->mTranslation[i];
			int offset;
			if (int(p4) < param.mEntryNum) {
				offset = param.mDataOffset + int(p4);
			} else {
				offset = param.mDataOffset + (param.mEntryNum - 1);
			}

			transl[i] = mTranslationDataBlock->mData[offset];
		}

		if ((info->mFlags & 0x700) == 0x700) {
			info->mFlags |= 0x800;
		}
	}
}

/*
 * --INFO--
 * Address:	8002C2BC
 * Size:	000150
 */
void AnimData::makeAnimSRT(int boneId, Matrix4f* parent, Matrix4f* output, AnimDataInfo* info, f32 pos)
{
	int frameNum = pos;
	if (frameNum < 0 || frameNum > mTotalFrameCount) {
		ERROR("makeSRT too large a frame number : %d / %d : %f\n", frameNum, mTotalFrameCount, pos);
	}

	Matrix4f mtx;
	bool check = true;
	Matrix4f* boneTransform;
	if ((info->mFlags & 0x777) != 0x777 && mAnimInfoList[frameNum].mCachedMtxBlock) {
		AnimCacheInfo* cache = (AnimCacheInfo*)mAnimInfoList[frameNum].mCachedMtxBlock;
		if (cache->mBoneMtxList[boneId]) {
			check = false;
		} else {
			cache->mBoneMtxList[boneId] = &cache->mBoneMatrices[boneId];
		}
		boneTransform = cache->mBoneMtxList[boneId];
	} else {
		boneTransform = &mtx;
	}

	if (check) {
		SRT& srt = info->mSRT;
		extractSRT(info->mSRT, boneId, info, pos);
		if ((info->mFlags & 0x777) == 0x777) {
			boneTransform = &info->mMtx;
			if (!(info->mFlags & 0x8000)) {
				boneTransform->makeSRT(srt.mScale, srt.mRotation, srt.mTranslation);
				info->mFlags |= 0x8000;
			}
		} else {
			output->makeConcatSRT(parent, *boneTransform, srt);
			return;
		}
	}

	PSMTXConcat(parent->mMtx, boneTransform->mMtx, output->mMtx);
}

/*
 * --INFO--
 * Address:	8002C40C
 * Size:	00003C
 */
void AnimData::detach()
{
	for (int i = 0; i < mTotalFrameCount; i++) {
		mAnimInfoList[i].initData();
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void AnimData::initData()
{
	mAnimInfoList = new AnimCacheInfo[mTotalFrameCount];
}

/*
 * --INFO--
 * Address:	8002C458
 * Size:	00025C
 */
void AnimData::checkMask()
{
	for (int i = 0; i < mJointCount; i++) {
		mAnimInfo[i].mFlags = 0;
		int scaleFlag       = 0;
		for (int j = 0; j < 3; j++) {
			if (mAnimInfo[i].mScale[j].mEntryNum == 1) {
				mAnimInfo[i].mFlags |= 1 << scaleFlag;
			}

			scaleFlag++;
		}

		int rotateFlag = scaleFlag + 1;
		for (int j = 0; j < 3; j++) {
			if (mAnimInfo[i].mRotation[j].mEntryNum == 1) {
				mAnimInfo[i].mFlags |= 1 << rotateFlag;
			}

			rotateFlag++;
		}

		int transFlag = rotateFlag + 1;
		for (int j = 0; j < 3; j++) {
			if (mAnimInfo[i].mTranslation[j].mEntryNum == 1) {
				mAnimInfo[i].mFlags |= 1 << transFlag;
			}

			transFlag++;
		}
	}

	mAnimJointIndices    = new u16[mJointCount];
	int animJointCount   = 0;
	int staticJointCount = 0;

	for (int i = 0; i < mJointCount; i++) {
		if (i >= mModel->mJointCount) {
			continue;
		}

		if ((mAnimInfo[i].mFlags & 0x777) != 0x777) {
			mAnimJointIndices[i] = animJointCount++;
		} else {
			mAnimJointIndices[i] = 0;
			staticJointCount++;
		}
	}

	mActiveJointCount = mJointCount - staticJointCount;
}

/*
 * --INFO--
 * Address:	8002C6B4
 * Size:	0003D4
 */
void AnimDca::read(RandomAccessStream& input)
{
	mJointCount      = input.readInt();
	mTotalFrameCount = input.readInt();

	mScaleDataBlock = new DataChunk();
	mScaleDataBlock->read(input);

	mRotateDataBlock = new DataChunk();
	mRotateDataBlock->read(input);

	mTranslationDataBlock = new DataChunk();
	mTranslationDataBlock->read(input);

	mAnimInfo = new AnimDataInfo[mJointCount];

	for (int i = 0; i < mJointCount; i++) {
		mAnimInfo[i].mGroupIndex = input.readInt();

		int parentIndex          = input.readInt();
		mAnimInfo[i].mParentInfo = parentIndex == -1 ? 0 : &mAnimInfo[parentIndex];

		// Read scale parameters (3 entries for x, y, and z)
		int j;
		for (j = 0; j < 3; j++) {
			AnimParam* scaleParam   = &mAnimInfo[i].mScale[j];
			scaleParam->mEntryNum   = input.readInt();
			scaleParam->mDataOffset = input.readInt();
		}

		// Read rotation parameters (3 entries for x, y, and z)
		for (j = 0; j < 3; j++) {
			AnimParam* rotationParam   = &mAnimInfo[i].mRotation[j];
			rotationParam->mEntryNum   = input.readInt();
			rotationParam->mDataOffset = input.readInt();
		}

		// Read translation parameters (3 entries for x, y, and z)
		for (j = 0; j < 3; j++) {
			AnimParam* translationParam   = &mAnimInfo[i].mTranslation[j];
			translationParam->mEntryNum   = input.readInt();
			translationParam->mDataOffset = input.readInt();
		}
	}

	checkMask();
	initData();
}

/*
 * --INFO--
 * Address:	8002CABC
 * Size:	000A8C
 */
void AnimDca::parse(CmdStream* stream)
{
	mScaleDataBlock = mRotateDataBlock = mTranslationDataBlock = nullptr;

	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);

		if (stream->isToken("<ANM_INFO>")) {
			stream->getToken(true);
			getAnimInfo(stream);
		} else if (stream->isToken("<SCALING>")) {
			mScaleDataBlock = new DataChunk();
			mScaleDataBlock->getData(stream);
			if (mScaleDataBlock->mDataSize != mScaleDataBlock->mDataIndex) {
				PRINT("got %d scaling values\n", mScaleDataBlock->mDataIndex);
			}
		} else if (stream->isToken("<ROTATION>")) {
			mRotateDataBlock = new DataChunk();
			mRotateDataBlock->getData(stream);
			for (int i = 0; i < mRotateDataBlock->mDataIndex; i++) {
				// convert degrees to radians
				mRotateDataBlock->mData[i] = mRotateDataBlock->mData[i] * PI / 180.0f;
			}
			if (mRotateDataBlock->mDataSize != mRotateDataBlock->mDataIndex) {
				PRINT("got %d rotation values\n", mRotateDataBlock->mDataIndex);
			}

		} else if (stream->isToken("<TRANSLATION>")) {
			mTranslationDataBlock = new DataChunk();
			mTranslationDataBlock->getData(stream);
			if (mTranslationDataBlock->mDataSize != mTranslationDataBlock->mDataIndex) {
				PRINT("got %d translate values\n", mTranslationDataBlock->mDataIndex);
			}
		} else if (stream->isToken("<JOINT>")) {
			stream->getToken(true);
			int index = -1;
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);

				if (stream->isToken("index")) {
					sscanf(stream->getToken(true), "%d", &index);

				} else if (stream->isToken("name")) {
					stream->getToken(true);

				} else if (stream->isToken("kind")) {
					stream->getToken(true);

				} else if (stream->isToken("parent")) {
					int parentIdx;
					sscanf(stream->getToken(true), "%d", &parentIdx);
					stream->getToken(true);
					AnimDataInfo* parent;
					if (parentIdx == -1) {
						parent = nullptr;
					} else {
						parent = &mAnimInfo[parentIdx];
					}

					mAnimInfo[index].mParentInfo = parent;

				} else if (stream->isToken("child")) {
					stream->getToken(true);
					stream->getToken(true);

				} else if (stream->isToken("brother_next")) {
					stream->getToken(true);
					stream->getToken(true);

				} else if (stream->isToken("brother_prev")) {
					stream->getToken(true);
					stream->getToken(true);

				} else if (stream->isToken("sx_param")) {
					AnimParam& param = mAnimInfo[index].mScale[0];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);

				} else if (stream->isToken("sy_param")) {
					AnimParam& param = mAnimInfo[index].mScale[1];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);

				} else if (stream->isToken("sz_param")) {
					AnimParam& param = mAnimInfo[index].mScale[2];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);

				} else if (stream->isToken("rx_param")) {
					AnimParam& param = mAnimInfo[index].mRotation[0];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);

				} else if (stream->isToken("ry_param")) {
					AnimParam& param = mAnimInfo[index].mRotation[1];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);

				} else if (stream->isToken("rz_param")) {
					AnimParam& param = mAnimInfo[index].mRotation[2];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);

				} else if (stream->isToken("tx_param")) {
					AnimParam& param = mAnimInfo[index].mTranslation[0];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);

				} else if (stream->isToken("ty_param")) {
					AnimParam& param = mAnimInfo[index].mTranslation[1];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);

				} else if (stream->isToken("tz_param")) {
					AnimParam& param = mAnimInfo[index].mTranslation[2];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
				}
			}

			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
		} else {
			stream->getToken(true);
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);
			}

			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
		}
	}

	checkMask();
	initData();
}

/*
 * --INFO--
 * Address:	8002D548
 * Size:	000154
 */
void AnimDca::getAnimInfo(CmdStream* stream)
{
	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);

		if (stream->isToken("numjoints")) {
			sscanf(stream->getToken(true), "%d", &mJointCount);
			mAnimInfo = new AnimDataInfo[mJointCount];

			for (int i = 0; i < mJointCount; i++) {
				mAnimInfo[i].mGroupIndex = i;
			}

		} else if (stream->isToken("numframes")) {
			sscanf(stream->getToken(true), "%d", &mTotalFrameCount);

		} else {
			stream->skipLine();
		}
	}

	if (!stream->endOfCmds()) {
		stream->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	8002D69C
 * Size:	00010C
 */
AnimDck::AnimDck(BaseShape* model, int joints)
{
	mModel           = model;
	mJointCount      = joints;
	mTotalFrameCount = 0;
	mAnimInfo        = new AnimDataInfo[mJointCount];

	for (int i = 0; i < joints; i++) {
		int parentIndex          = model->mJointList[i].mParentIndex;
		mAnimInfo[i].mParentInfo = parentIndex == -1 ? nullptr : &mAnimInfo[parentIndex];
	}
}

/*
 * --INFO--
 * Address:	8002D7A8
 * Size:	00041C
 */
void AnimDck::read(RandomAccessStream& stream)
{
	// Read the number of joints and frames
	mJointCount      = stream.readInt();
	mTotalFrameCount = stream.readInt();

	// Read scale data
	mScaleDataBlock = new DataChunk;
	mScaleDataBlock->read(stream);

	// Read rotation data
	mRotateDataBlock = new DataChunk;
	mRotateDataBlock->read(stream);

	// Read translation data
	mTranslationDataBlock = new DataChunk;
	mTranslationDataBlock->read(stream);

	// Read animation info for each joint
	mAnimInfo = new AnimDataInfo[mJointCount];
	for (int i = 0; i < mJointCount; i++) {
		mAnimInfo[i].mGroupIndex = stream.readInt();

		int parentIndex          = stream.readInt();
		mAnimInfo[i].mParentInfo = parentIndex == -1 ? 0 : &mAnimInfo[parentIndex];

		// Read scale parameters (3 entries for x, y, and z)
		int j;
		for (j = 0; j < 3; j++) {
			AnimParam* scaleParam   = &mAnimInfo[i].mScale[j];
			scaleParam->mEntryNum   = stream.readInt();
			scaleParam->mDataOffset = stream.readInt();
			scaleParam->mFlags      = stream.readInt();
		}

		// Read rotation parameters (3 entries for x, y, and z)
		for (j = 0; j < 3; j++) {
			AnimParam* rotationParam   = &mAnimInfo[i].mRotation[j];
			rotationParam->mEntryNum   = stream.readInt();
			rotationParam->mDataOffset = stream.readInt();
			rotationParam->mFlags      = stream.readInt();
		}

		// Read translation parameters (3 entries for x, y, and z)
		for (j = 0; j < 3; j++) {
			AnimParam* translationParam   = &mAnimInfo[i].mTranslation[j];
			translationParam->mEntryNum   = stream.readInt();
			translationParam->mDataOffset = stream.readInt();
			translationParam->mFlags      = stream.readInt();
		}
	}

	checkMask();
	initData();
}

/*
 * --INFO--
 * Address:	8002DBC4
 * Size:	000CE4
 */
void AnimDck::parse(CmdStream* stream)
{
	// this is all reserved for parsing Dck from a text based format which doesnt exist

	mScaleDataBlock = mRotateDataBlock = mTranslationDataBlock = nullptr;

	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);

		if (stream->isToken("<KEY_ANM_INFO>")) {
			stream->getToken(true);
			getAnimInfo(stream);
		} else if (stream->isToken("<KEY_SCALING>")) {
			mScaleDataBlock = new DataChunk();
			mScaleDataBlock->getData(stream);
			if (mScaleDataBlock->mDataSize != mScaleDataBlock->mDataIndex) {
				PRINT("got %d scaling values\n", mScaleDataBlock->mDataIndex);
			}
		} else if (stream->isToken("<KEY_ROTATION>")) {
			mRotateDataBlock = new DataChunk();
			mRotateDataBlock->getData(stream);
			if (mRotateDataBlock->mDataSize != mRotateDataBlock->mDataIndex) {
				PRINT("got %d rotation values\n", mRotateDataBlock->mDataIndex);
			}

		} else if (stream->isToken("<KEY_TRANSLATION>")) {
			mTranslationDataBlock = new DataChunk();
			mTranslationDataBlock->getData(stream);
			if (mTranslationDataBlock->mDataSize != mTranslationDataBlock->mDataIndex) {
				PRINT("got %d translate values\n", mTranslationDataBlock->mDataIndex);
			}
		} else if (stream->isToken("<JOINT>")) {
			stream->getToken(true);
			int index = -1;
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);

				if (stream->isToken("index")) {
					sscanf(stream->getToken(true), "%d", &index);

				} else if (stream->isToken("name")) {
					stream->getToken(true);

				} else if (stream->isToken("kind")) {
					stream->getToken(true);

				} else if (stream->isToken("parent")) {
					int parentIdx;
					sscanf(stream->getToken(true), "%d", &parentIdx);
					stream->getToken(true);
					AnimDataInfo* parent;
					if (parentIdx == -1) {
						parent = nullptr;
					} else {
						parent = &mAnimInfo[parentIdx];
					}

					mAnimInfo[index].mParentInfo = parent;

				} else if (stream->isToken("child")) {
					stream->getToken(true);
					stream->getToken(true);

				} else if (stream->isToken("brother_next")) {
					stream->getToken(true);
					stream->getToken(true);

				} else if (stream->isToken("brother_prev")) {
					stream->getToken(true);
					stream->getToken(true);

				} else if (stream->isToken("sx_param")) {
					AnimParam& param = mAnimInfo[index].mScale[0];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);

				} else if (stream->isToken("sy_param")) {
					AnimParam& param = mAnimInfo[index].mScale[1];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);

				} else if (stream->isToken("sz_param")) {
					AnimParam& param = mAnimInfo[index].mScale[2];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);

				} else if (stream->isToken("rx_param")) {
					AnimParam& param = mAnimInfo[index].mRotation[0];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);

				} else if (stream->isToken("ry_param")) {
					AnimParam& param = mAnimInfo[index].mRotation[1];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);

				} else if (stream->isToken("rz_param")) {
					AnimParam& param = mAnimInfo[index].mRotation[2];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);

				} else if (stream->isToken("tx_param")) {
					AnimParam& param = mAnimInfo[index].mTranslation[0];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);

				} else if (stream->isToken("ty_param")) {
					AnimParam& param = mAnimInfo[index].mTranslation[1];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);

				} else if (stream->isToken("tz_param")) {
					AnimParam& param = mAnimInfo[index].mTranslation[2];
					sscanf(stream->getToken(true), "%d", &param.mEntryNum);
					sscanf(stream->getToken(true), "%d", &param.mDataOffset);
					sscanf(stream->getToken(true), "%d", &param.mFlags);
				}
			}

			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
		} else {
			stream->getToken(true);
			while (!stream->endOfCmds() && !stream->endOfSection()) {
				stream->getToken(true);
			}

			if (!stream->endOfCmds()) {
				stream->getToken(true);
			}
		}
	}

	checkMask();
	initData();

	bool* checks = new bool[mRotateDataBlock->mDataIndex];

	for (int i = 0; i < mRotateDataBlock->mDataIndex; i++) {
		checks[i] = false;
	}

	for (int i = 0; i < mJointCount; i++) {
		for (int j = 0; j < 3; j++) {
			// this is insane but required
			int* param = (int*)&mAnimInfo[i].mRotation[j];
			switch (param[0]) {
			case 0:
				break;
			case 1:
				if (!checks[param[1]]) {
					mRotateDataBlock->mData[param[1]] = mRotateDataBlock->mData[param[1]] * PI / 180.0f;
					checks[param[1]]                  = true;
				}
				break;
			default:
				int size   = (param[2] == 0) ? 3 : 4;
				int offset = param[1] + 1;
				for (int k = 0; k < param[0]; k++) {
					if (!checks[offset]) {
						mRotateDataBlock->mData[offset]     = mRotateDataBlock->mData[offset] * PI / 180.0f;
						mRotateDataBlock->mData[offset + 1] = mRotateDataBlock->mData[offset + 1] * PI / 180.0f;
						if (size == 4) {
							mRotateDataBlock->mData[offset + 2] = mRotateDataBlock->mData[offset + 2] * PI / 180.0f;
						}
						checks[offset] = true;
					}
					offset += size;
				}
				break;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8002E8A8
 * Size:	000154
 */
void AnimDck::getAnimInfo(CmdStream* stream)
{
	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);
		if (stream->isToken("numjoints")) {
			sscanf(stream->getToken(true), "%d", &mJointCount);
			mAnimInfo = new AnimDataInfo[mJointCount];
			for (int i = 0; i < mJointCount; i++) {
				mAnimInfo[i].mGroupIndex = i;
			}
		} else if (stream->isToken("numframes")) {
			sscanf(stream->getToken(true), "%d", &mTotalFrameCount);
		} else {
			stream->skipLine();
		}
	}

	if (!stream->endOfCmds()) {
		stream->getToken(true);
	}
}

/*
 * --INFO--
 * Address:	8002E9FC
 * Size:	000220
 */
void AnimDck::extractSRT(SRT& srt, int, AnimDataInfo* anim, f32 time)
{
	u32 badCompiler[2];
	if (anim->mFlags & 0x8000) {
		return;
	}

	// APPLY SCALE
	if (!(anim->mFlags & 8)) {
		// loop for x y and z
		f32* s = (f32*)&srt.mScale;
		for (int i = 0; i < 3; i++) {
			AnimParam* param = &anim->mScale[i];
			switch (param->mEntryNum) {
			case 0: // 0 entries, default to 1.0
				s[i] = 1.0f;
				break;
			case 1: // 1 entry, use the value of that entry alone
				s[i] = mScaleDataBlock->mData[param->mDataOffset];
				break;
			default: // multiple entries, use the extract method
				s[i] = extract(time, *param, *mScaleDataBlock);
				break;
			}
		}
		if ((anim->mFlags & 7) == 7) {
			anim->mFlags |= 8;
		}
	}

	// APPLY ROTATION
	if (!(anim->mFlags & 0x80)) {
		// loop for x y and z
		f32* r           = (f32*)&srt.mRotation;
		AnimParam* param = anim->mRotation;
		for (int i = 0; i < 3; i++) {
			AnimParam& p = param[i];
			switch (param[i].mEntryNum) {
			case 0: // 0 entries, default to 1.0
				r[i] = 0.0f;
				break;
			case 1: // 1 entry, use the value of that entry alone
				r[i] = mRotateDataBlock->mData[param[i].mDataOffset];
				break;
			default: // multiple entries, use the extract method
				r[i] = extract(time, p, *mRotateDataBlock);
				break;
			}
		}
		if ((anim->mFlags & 0x70) == 0x70) {
			anim->mFlags |= 0x80;
		}
	}

	// APPLY TRANSLATION
	if (!(anim->mFlags & 0x800)) {
		// loop for x y and z
		f32* t           = (f32*)&srt.mTranslation;
		AnimParam* param = anim->mTranslation;
		for (int i = 0; i < 3; i++) {
			AnimParam& p = param[i];
			switch (param[i].mEntryNum) {
			case 0: // 0 entries, default to 1.0
				t[i] = 1.0f;
				break;
			case 1: // 1 entry, use the value of that entry alone
				t[i] = mTranslationDataBlock->mData[param[i].mDataOffset];
				break;
			default: // multiple entries, use the extract method
				t[i] = extract(time, p, *mTranslationDataBlock);
				break;
			}
		}
		if ((anim->mFlags & 0x700) == 0x700) {
			anim->mFlags |= 0x800;
		}
	}
}

/*
 * --INFO--
 * Address:	8002EC1C
 * Size:	0000CC
 */
void AnimDck::makeAnimSRT(int a, Matrix4f* mtx1, Matrix4f* mtx2, AnimDataInfo* anim, f32 time)
{
	SRT& srt = anim->mSRT;
	extractSRT(srt, a, anim, time);
	if ((anim->mFlags & 0x777) == 0x777) {
		if (!(anim->mFlags & 0x8000)) {
			anim->mMtx.makeSRT(srt.mScale, srt.mRotation, srt.mTranslation);
			anim->mFlags |= 0x8000;
		}
		PSMTXConcat(mtx1->mMtx, anim->mMtx.mMtx, mtx2->mMtx);
	} else {
		Matrix4f mtx;
		mtx2->makeConcatSRT(mtx1, mtx, srt);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void BaseShape::exportIni(RandomAccessStream& stream, bool doSkipLights)
{
	PRINT("*---------------------------- exporting ini!!!!!!!!!!!\n");
	if (mRouteGroup.Child()) {
		stream.print("// Route info file for %s", Name());
		for (RouteGroup* route = (RouteGroup*)mRouteGroup.Child(); route; route = (RouteGroup*)route->mNext) {
			route->saveini("", stream);
		}
		// stream.print("\n");
	}
	if (!doSkipLights && mLightGroup.Child()) {
		stream.print("// LightGroups info file for %s", Name());
		for (LightGroup* light = (LightGroup*)mLightGroup.Child(); light; light = (LightGroup*)light->mNext) {
			light->saveini("", stream);
		}
		// stream.print("\n");
	}
	if (mCollisionInfo.Child()) {
		stream.print("// Collision info file for %s", Name());
		for (ObjCollInfo* info = (ObjCollInfo*)mCollisionInfo.Child(); info; info = (ObjCollInfo*)info->mNext) {
			info->saveini("", stream);
		}
		// stream.print("\n");
	}
}

/*
 * --INFO--
 * Address:	8002ECE8
 * Size:	000364
 */
void BaseShape::importIni(RandomAccessStream& stream)
{
	CmdStream* cmd = new CmdStream(&stream);

	if (cmd) {
		while (!cmd->endOfCmds() && !cmd->endOfSection()) {
			cmd->getToken(true);

			if (cmd->isToken("collinfo")) {
				int jointIdx;
				sscanf(cmd->getToken(true), "%d", &jointIdx);

				ObjCollInfo* info  = new ObjCollInfo();
				info->mJointIndex  = jointIdx;
				info->mParentShape = this;
				mCollisionInfo.add(info);
				cmd->getToken(true);
				info->loadini(cmd);

			} else if (cmd->isToken("lightgroup")) {
				int jointIdx;
				sscanf(cmd->getToken(true), "%d", &jointIdx);
				LightGroup* light   = new LightGroup();
				light->mJointIndex  = jointIdx;
				light->mParentShape = (Shape*)this;
				mLightGroup.add(light);
				cmd->getToken(true);
				light->loadini(cmd);

			} else if (cmd->isToken("route")) {
				RouteGroup* route = makeRouteGroup();
				mRouteGroup.add(route);
				cmd->getToken(true);
				route->loadini(cmd);
			}
		}

		if (!cmd->endOfCmds()) {
			cmd->getToken(true);
		}
	}
}

/*
 * --INFO--
 * Address:	8002F09C
 * Size:	0000F4
 */
void ShapeDynMaterials::animate(f32* data)
{
	gsys->mTimer->start("shpDynMats", true);

	for (int i = 0; i < mMatCount; i++) {
		Material& mat = mMaterials[i];
		if (mat.mFlags & 1) {
			if (mat.mColourInfo.mTotalFrameCount != 0) {
				mat.mColourInfo.animate(data, mat.Colour());
			}

			for (int j = 0; j < 3; j++) {
				if (mat.mTevInfo->mTevColRegs[j]._08) {
					mat.mTevInfo->mTevColRegs[j].animate(data, mat.mTevInfo->mTevColRegs[j].mAnimatedColor);
				}
			}

			for (int j = 0; j < (int)mat.mTextureInfo.mTextureDataCount; j++) {
				if (mat.mTextureInfo.mTextureData[j].mAnimationFactor != 255) {
					mat.mTextureInfo.mTextureData[j].animate(data, mat.mTextureInfo.mTextureData[j].mAnimatedTexMtx);
				}
			}
		}
	}

	gsys->mTimer->stop("shpDynMats");
}

/*
 * --INFO--
 * Address:	8002F190
 * Size:	0001E8
 */
void ShapeDynMaterials::updateContext()
{
	for (int i = 0; i < mMatCount; i++) {
		Material& mat = mMaterials[i];
		if (mat.mFlags & 0x1) {
			mShape->mMaterialList[mat.mIndex].Colour() = mat.Colour();

			for (int j = 0; j < 3; j++) {
				if (mat.mTevInfo->mTevColRegs[j]._08) {
					mShape->mMaterialList[mat.mIndex].mTevInfo->mTevColRegs[j].mAnimatedColor = mat.mTevInfo->mTevColRegs[j].mAnimatedColor;
				}
			}

			for (int j = 0; j < (int)mat.mTextureInfo.mTextureDataCount; j++) {
				if (mat.mTextureInfo.mTextureData[j].mAnimationFactor != 255) {
					mShape->mMaterialList[mat.mIndex].mTextureInfo.mTextureData[j].mAnimatedTexMtx
					    = mat.mTextureInfo.mTextureData[j].mAnimatedTexMtx;
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8002F378
 * Size:	00030C
 */
BaseShape::BaseShape()
{
	mName           = "noname";
	mAnimMatrices   = nullptr;
	mAnimMatrixId   = 0;
	mSystemFlags    = 0;
	_13C            = 0;
	_2AC            = 1;
	mVtxMatrixCount = 0;
	mVtxMatrixList  = nullptr;
	mMaterialCount  = 0;
	mMaterialList   = nullptr;
	mTevInfoCount   = 0;
	mTevInfoList    = nullptr;
	mMeshCount      = 0;
	mMeshList       = nullptr;

	mEnvelopeCount = 0;
	mEnvelopeList  = nullptr;

	mJointCount        = 0;
	mJointList         = nullptr;
	mTotalMatpolyCount = 0;
	mMatpolyList       = nullptr;
	mTexAttrCount      = 0;
	mTextureCount      = 0;

	mCurrentAnimation = 0;
	mFrameCacher      = nullptr;

	// debugData.initCore("");
	mCollisionInfo.initCore("");
	mLightGroup.initCore("");
	mRouteGroup.initCore("");

	mTotalActiveTexCoords = 0;
	mVertexCount          = 0;
	mVertexList           = nullptr;
	mVtxColorList         = 0;

	mTexCoordList[0] = nullptr;
	mTexCoordList[1] = nullptr;
	mTexCoordList[2] = nullptr;
	mTexCoordList[3] = nullptr;
	mTexCoordList[4] = nullptr;
	mTexCoordList[5] = nullptr;
	mTexCoordList[6] = nullptr;
	mTexCoordList[7] = nullptr;

	mNormalList           = nullptr;
	mNBTList              = 0;
	mFallbackTexAttrCount = 0;
	mAttrListMatCount     = 0;
	mResolvedTextureList  = nullptr;
	mTextureNameList      = nullptr;

	mBaseRoomCount = 0;
	mRoomInfoList  = nullptr;
	mTriCount      = 0;
	mTriList       = nullptr;
	mCollGroups    = nullptr;
}

/*
 * --INFO--
 * Address:	8002F684
 * Size:	00016C
 */
void BaseShape::countMaterials(Joint* joint, u32 p2)
{
	for (int i = 0; i < mTotalMatpolyCount; i++) {
		if (mMatpolyList[i]->mJointList == joint) {
			bool check = false;
			for (int j = 0; j < matIndex; j++) {
				if (matUsed[j] == (int)mMatpolyList[i]->mMaterial->mIndex) {
					check = true;
					break;
				}
			}

			if (!check) {
				Material* mat = mMatpolyList[i]->mMaterial;
				bool check2   = false;
				if (mat->mFlags & 1) {
					if (mat->mColourInfo.mTotalFrameCount) {
						check2 = true;
					}
					for (int j = 0; j < 3; j++) {
						if (mat->mTevInfo->mTevColRegs[j]._08) {
							check2 = true;
						}
					}
					for (int j = 0; j < (int)mat->mTextureInfo.mTextureDataCount; j++) {
						if (mat->mTextureInfo.mTextureData[j].mAnimationFactor != 255) {
							check2 = true;
						}
					}
				}

				usedIndex++;
				if (check2) {
					matUsed[matIndex] = mMatpolyList[i]->mMaterial->mIndex;
					matIndex++;
				}
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8002F7F0
 * Size:	0000C4
 */
void BaseShape::recTraverseMaterials(Joint* joint, IDelegate2<Joint*, u32>* delegate)
{
	for (Joint* jnt = joint; jnt; jnt = (Joint*)jnt->mNext) {
		delegate->invoke(jnt, 0);
		if (!jnt->mChild) {
			continue;
		}
		recTraverseMaterials((Joint*)jnt->mChild, delegate);
	}
}

/*
 * --INFO--
 * Address:	8002F8B4
 * Size:	000078
 */
ShapeDynMaterials* BaseShape::instanceMaterials(int p1)
{
	ShapeDynMaterials* dynMats = new ShapeDynMaterials();
	makeInstance(*dynMats, p1);
	return dynMats;
}

/*
 * --INFO--
 * Address:	8002F92C
 * Size:	00030C
 */
void BaseShape::makeInstance(ShapeDynMaterials& dynMats, int p2)
{
	dynMats.mShape = this;
	for (int i = 0; i < 0x100; i++) {
		matUsed[i] = 0;
	}

	matIndex     = 0;
	usedIndex    = 0;
	Joint* joint = &mJointList[p2];
	countMaterials(joint, 0);

	if (joint->mChild) {
		recTraverseMaterials((Joint*)joint->mChild, &Delegate2<BaseShape, Joint*, u32>(this, &countMaterials));
	}

	dynMats.mMatCount  = matIndex;
	dynMats.mMaterials = new Material[dynMats.mMatCount];

	for (int i = 0; i < dynMats.mMatCount; i++) {
		Material* mat = &dynMats.mMaterials[i];
		memcpy(mat, &mMaterialList[matUsed[i]], sizeof(Material));
		if (mat->mFlags & 1) {
			mat->mTevInfo = new PVWTevInfo();
			memcpy(mat->mTevInfo, mMaterialList[matUsed[i]].mTevInfo, sizeof(PVWTevInfo));
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void recShowInfos(Graphics&, ObjCollInfo*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000074
 */
void BaseShape::drawobjcolls(Graphics&, Camera&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void BaseShape::drawlights(Graphics& gfx, Camera& cam)
{
	Matrix4f* activeMtx = gfx.mActiveMatrix;
	if (mLightGroup.Child()) {
		for (LightGroup* light = (LightGroup*)mLightGroup.Child(); light; light = (LightGroup*)light->mNext) {
			light->refresh(gfx, activeMtx);
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00007C
 */
void BaseShape::drawroutes(Graphics& gfx, Camera& cam)
{
	for (RouteGroup* route = (RouteGroup*)mRouteGroup.mChild; route; route = (RouteGroup*)route->mNext) {
		gfx.useMatrix(cam.mLookAtMtx, 0);
		route->refresh(gfx, route);
	}
}

/*
 * --INFO--
 * Address:	8002FCF4
 * Size:	000778
 */
void BaseShape::drawculled(Graphics& gfx, Camera& cam, ShapeDynMaterials* dynMats)
{
	Matrix4f* mtx = gfx.mActiveMatrix;
	gfx.initMesh((Shape*)this);
	int culledJointCount = 0;
	if (dynMats) {
		for (ShapeDynMaterials* iMat = dynMats; iMat; iMat = iMat->mParent) {
			iMat->updateContext();
		}
	}

	for (int i = 0; i < mJointCount; i++) {
		BoundBox& box = mJointList[i].mBounds;
		if (cam.isBoundVisible(box, 0x8000 | 0x10 | 0x20 | 0x1 | 0x2 | 0x4 | 0x8)) {
			for (int j = mTotalMatpolyCount - 1; j >= 0; j--) {
				if (mMatpolyList[j]->mJointList == &mJointList[i]) {
					gfx.drawSingleMatpoly((Shape*)this, mMatpolyList[j]);
				}
			}
		} else {
			culledJointCount++;
			mJointList[i].mCullIndex = -1;
		}
	}

	if (gsys->mToggleDebugInfo) {
		for (int i = 0; i < mJointCount; i++) {
			gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
			gfx.useTexture(nullptr, 0);
			gfx.setColour(Colour(255, 32, 32, 255), true);
			bool lighting = gfx.setLighting(false, nullptr);
			mJointList[i].mBounds.draw(gfx);
			gfx.setLighting(lighting, nullptr);
			gfx.useMatrix(*mtx, 0);
			BoundBox& box = mJointList[i].mBounds;

			if (cam.isBoundVisible(box, 0x8000 | 0x10 | 0x20 | 0x1 | 0x2 | 0x4 | 0x8)) {
				bool lighting = gfx.setLighting(false, nullptr);
				gfx.useMatrix(Matrix4f::ident, 0);
				gfx.setColour(Colour(255, 255, 255, 255), true);
				int blend = gfx.setCBlending(0);
				Vector3f centre((box.mMax.x + box.mMin.x) * 0.5f, (box.mMax.y + box.mMin.y) * 0.5f + 10.0f,
				                (box.mMax.z + box.mMin.z) * 0.5f);
				centre.multMatrix(gfx.mCamera->mLookAtMtx);
				char buf[PATH_MAX];
				sprintf(buf, "%d", mJointList[i].mCullIndex);
				gfx.perspPrintf(gsys->mConsFont, centre, -(gsys->mConsFont->stringWidth(buf) / 2), 0, buf);
				gfx.setCBlending(blend);
				gfx.setLighting(lighting, nullptr);
			}
		}
	}
}

/*
 * --INFO--
 * Address:	8003046C
 * Size:	0001A0
 */
void BaseShape::drawshape(Graphics& gfx, Camera& cam, ShapeDynMaterials* dynMats)
{
	gsys->mTimer->start("drawShape", true);
	u32 prevRender = gfx.mRenderState;
	if (mMeshCount) {
		if (!(mSystemFlags & ShapeFlags::AlwaysRedraw) && (mSystemFlags & ShapeFlags::AllowCaching) && (gfx.mRenderState & 0x400)) {
			gfx.cacheShape(this, dynMats);
			gfx.mRenderState &= ~0x400;
		}

		if ((mSystemFlags & ShapeFlags::AlwaysRedraw) || (gfx.mRenderState & (0x8000 | 0x300))) {
			if (dynMats) {
				for (ShapeDynMaterials* iMat = dynMats; iMat; iMat = iMat->mParent) {
					iMat->updateContext();
				}
			}

			Matrix4f* activeMtx = gfx.mActiveMatrix;
			gfx.drawMeshes(cam, (Shape*)this);
			gfx.useMatrix(*activeMtx, 0);
			drawlights(gfx, cam);
			if (gsys->mToggleDebugInfo && (gfx.mRenderState & 0x400)) {
				gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
				drawroutes(gfx, cam);
			}
		}
	}

	gfx.mRenderState = prevRender;
	gsys->mTimer->stop("drawShape");
}

/*
 * --INFO--
 * Address:	8003060C
 * Size:	00040C
 */
void BaseShape::resolveTextureNames()
{
	if (mTextureNameList) {
		for (int i = 0; i < mAttrListMatCount; i++) {
			char* texName = &mTextureNameList[32 * i];
			char filepath[PATH_MAX];
			sprintf(filepath, "%s%s", gsys->mTextureBase2, texName);
			mResolvedTextureList[i] = gsys->loadTexture(filepath, true);
			if (!mResolvedTextureList[i]) {
				sprintf(filepath, "%s%s", gsys->mTextureBase1, texName);
				mResolvedTextureList[i] = gsys->loadTexture(filepath, true);
			}

			if (!mResolvedTextureList[i]) {
				PRINT("Could not load texture %s\n", texName);
			}
		}
	}

	if (mFallbackTexAttrCount || mAttrListMatCount) {
		PRINT("making tmp attrlist and materials : %d : %d\n", mFallbackTexAttrCount, mAttrListMatCount);
		int count    = mFallbackTexAttrCount ? mFallbackTexAttrCount : mAttrListMatCount;
		mTexAttrList = new TexAttr[count];
		for (int i = 0; i < count; i++) {
			mTexAttrList[i].mIndex        = i;
			mTexAttrList[i].mTextureIndex = (i | mAttrListMatCount != 0) ? 0x8000 : 0;
			mTexAttrList[i].mTexture      = mResolvedTextureList[i];
		}

		Material* matList = new Material[count];
		if (mMaterialCount == count) {
			PRINT("ALREADY HAS CORRECT NUMBER OF MATERIALS!!!!\n");
			for (int i = 0; i < count; i++) {
				matList[i] = mMaterialList[i];
			}
		}

		mMaterialCount = count;
		for (int i = 0; i < count; i++) {
			matList[i].mIndex        = i;
			matList[i].mTextureIndex = i;
		}

		mMaterialList = matList;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void BaseShape::skipChunk(RandomAccessStream& stream, u32 amt)
{
	for (u32 i = 0; i < amt; i++) {
		stream.readByte();
	}
}

/*
 * --INFO--
 * Address:	80030A74
 * Size:	0000CC
 */
void BaseShape::recAddMatpoly(Joint* parentJoint, int f)
{
	FOREACH_NODE(Joint, parentJoint, currentJoint)
	{
		if (currentJoint->mChild) {
			recAddMatpoly((Joint*)currentJoint->mChild, f);
		}

		FOREACH_NODE(Joint::MatPoly, currentJoint->mMatPoly.mChild, poly)
		{
			Material* mat = &mMaterialList[poly->mIndex];

			if ((mat->mFlags >> 8) & f) {
				poly->mMaterial         = mat;
				poly->mMesh             = &mMeshList[poly->mMeshIndex];
				mMatpolyList[_dlindx++] = poly;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	80030B40
 * Size:	002590
 */
void BaseShape::read(RandomAccessStream& stream)
{
	u32 chunkType;
	u32 before;
	u32 after;
	u32 badCompiler;
	do {
		u32 pos = stream.getPosition();

		chunkType  = stream.readInt();
		u32 length = stream.readInt();

		if (pos & 0x1F) {
			ERROR("chunk start not on boundary %08x!\n", pos);
		}

		switch (chunkType) {
		case BaseShapeChunk::Header: {
			stream.skipPadding(0x20);
			int unused   = stream.readInt();
			mSystemFlags = stream.readInt();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::Vertex: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mVertexCount = stream.readInt();
			stream.skipPadding(0x20);
			mVertexList = (Vector3f*)(new (0x20) Vec[mVertexCount]); // hmm.
			for (int i = 0; i < mVertexCount; i++) {
				mVertexList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexNormal: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mNormalCount = stream.readInt();
			stream.skipPadding(0x20);
			mNormalList = (Vector3f*)(new (0x20) Vec[mNormalCount]); // hmm
			for (int i = 0; i < mNormalCount; i++) {
				mNormalList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexNBT: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mNBTCount = stream.readInt();
			stream.skipPadding(0x20);
			mNBTList = (NBT*)(new (0x20) Vec[3 * mNBTCount]);
			for (int i = 0; i < mNBTCount; i++) {
				((Vector3f*)mNBTList)[3 * i].read(stream);
				((Vector3f*)mNBTList)[3 * i + 1].read(stream);
				((Vector3f*)mNBTList)[3 * i + 2].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexColour: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mVtxColorCount = stream.readInt();
			stream.skipPadding(0x20);
			mVtxColorList = (Colour*)(new (0x20) GXColor[mVtxColorCount]);
			for (int i = 0; i < mVtxColorCount; i++) {
				mVtxColorList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::TexCoord0:
		case BaseShapeChunk::TexCoord1:
		case BaseShapeChunk::TexCoord2:
		case BaseShapeChunk::TexCoord3:
		case BaseShapeChunk::TexCoord4:
		case BaseShapeChunk::TexCoord5:
		case BaseShapeChunk::TexCoord6:
		case BaseShapeChunk::TexCoord7: {
			before    = gsys->getHeap(SYSHEAP_App)->getFree();
			int index = chunkType - BaseShapeChunk::TexCoord0;

			mTexCoordCounts[index] = stream.readInt();
			stream.skipPadding(0x20);
			mTexCoordList[index] = new (0x20) Vector2f[mTexCoordCounts[index]];

			for (int i = 0; i < mTexCoordCounts[index]; i++) {
				mTexCoordList[index][i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			mTotalActiveTexCoords++;
			break;
		}

		case BaseShapeChunk::Texture: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mTextureCount = stream.readInt();
			stream.skipPadding(0x20);
			mTextureList = new TexImg[mTextureCount];
			for (int i = 0; i < mTextureCount; i++) {
				mTextureList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::TextureAttribute: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mTexAttrCount = stream.readInt();
			stream.skipPadding(0x20);
			mTexAttrList = new TexAttr[mTexAttrCount];
			for (int i = 0; i < mTexAttrCount; i++) {
				mTexAttrList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::Material: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mMaterialCount = stream.readInt();
			mTevInfoCount  = stream.readInt();

			stream.skipPadding(0x20);

			if (mTevInfoCount) {
				mTevInfoList = new PVWTevInfo[mTevInfoCount];
				for (int i = 0; i < mTevInfoCount; i++) {
					mTevInfoList[i].read(stream);
				}
			}

			if (mMaterialCount) {
				mMaterialList = new Material[mMaterialCount];
				for (int i = 0; i < mMaterialCount; i++) {
					mMaterialList[i].mIndex = i;
					mMaterialList[i].read(stream);
					mMaterialList[i].mTevInfo = &mTevInfoList[mMaterialList[i].mTevInfoIndex];

					MatobjInfo* info = new MatobjInfo;
					info->mTarget    = &mMaterialList[i];
					gsys->addGfxObject(info);
				}
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexMatrix: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mVtxMatrixCount = stream.readInt();
			stream.skipPadding(0x20);
			mVtxMatrixList = new VtxMatrix[mVtxMatrixCount];
			for (int i = 0; i < mVtxMatrixCount; i++) {
				mVtxMatrixList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::MatrixEnvelope: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mEnvelopeCount = stream.readInt();
			stream.skipPadding(0x20);
			mEnvelopeList = new Envelope[mEnvelopeCount];
			for (int i = 0; i < mEnvelopeCount; i++) {
				mEnvelopeList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::Mesh: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mMeshCount = stream.readInt();
			stream.skipPadding(0x20);
			mMeshList = new Mesh[mMeshCount];
			for (int i = 0; i < mMeshCount; i++) {
				mMeshList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::Joint: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mJointCount = stream.readInt();
			stream.skipPadding(0x20);
			mJointList = new Joint[mJointCount];
			for (int i = 0; i < mMeshCount; i++) {
				if (mMeshList[i].mParentJoint != -1) {
					mMeshList[i].mJointList = &mJointList[mMeshList[i].mParentJoint];
				}
			}

			for (int i = 0; i < mJointCount; i++) {
				mJointList[i].mParentShape = this;
				mJointList[i].read(stream);
				mCourseExtents.expandBound(mJointList[i].mBounds);
			}

			stream.skipPadding(0x20);

			mTotalMatpolyCount = 0;
			for (int i = 0; i < mJointCount; i++) {
				mTotalMatpolyCount += mJointList[i].mMatPolyCount;
			}

			mMatpolyList = new Joint::MatPoly*[mTotalMatpolyCount];

			for (int i = 0; i < mJointCount; i++) {
				mJointList[i].mIndex = i;
				if (mJointList[i].mParentIndex != -1) {
					mJointList[mJointList[i].mParentIndex].add(&mJointList[i]);
				}
			}

			_dlindx = 0;
			recAddMatpoly(mJointList, 4);
			recAddMatpoly(mJointList, 2);
			recAddMatpoly(mJointList, 1);

			for (int i = 0; i < mTotalMatpolyCount; i++) {
				mMatpolyList[i]->mJointList = mMatpolyList[i]->mMesh->mJointList;
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			break;
		}

		case BaseShapeChunk::JointName: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mJointCount = stream.readInt();
			stream.skipPadding(0x20);
			for (int i = 0; i < mJointCount; i++) {
				String name(0);
				stream.readString(name);
				mJointList[i].setName(name.mString);
			}

			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::CollisionPrism: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mTriCount      = stream.readInt();
			mBaseRoomCount = stream.readInt();
			stream.skipPadding(0x20);
			mRoomInfoList = new RoomInfo[mBaseRoomCount];

			for (int i = 0; i < mBaseRoomCount; i++) {
				mRoomInfoList[i].read(stream);
			}
			stream.skipPadding(0x20);

			mTriList = new CollTriInfo[mTriCount];

			for (int i = 0; i < mTriCount; i++) {
				mTriList[i].read(stream);
				mTriList[i].init(mRoomInfoList, mVertexList);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("This isn't in the DLL but clearly needs a kb print", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::CollisionGrid: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			mCourseExtents.read(stream);
			mGridSize  = stream.readFloat();
			mGridSizeX = stream.readInt();
			mGridSizeY = stream.readInt();

			mCollGroups          = new CollGroup*[mGridSizeX * mGridSizeY];
			int groupCount       = stream.readInt();
			int maxTrisPerGroup  = 0;
			CollGroup* tmpGroups = new CollGroup[groupCount];

			for (int i = 0; i < groupCount; i++) {
				tmpGroups[i].mFarCulledTriCount = stream.readShort();
				tmpGroups[i].mTriCount          = stream.readShort();
				tmpGroups[i].mTriangleList      = new CollTriInfo*[tmpGroups[i].mTriCount];

				if (tmpGroups[i].mTriCount > maxTrisPerGroup) {
					maxTrisPerGroup = tmpGroups[i].mTriCount;
				}

				for (int j = 0; j < tmpGroups[i].mTriCount; j++) {
					int idx                       = stream.readInt();
					tmpGroups[i].mTriangleList[j] = &mTriList[idx];
				}

				if (tmpGroups[i].mFarCulledTriCount) {
					tmpGroups[i].mFarCulledTriDistances = new u8[tmpGroups[i].mFarCulledTriCount];
					for (int j = 0; j < tmpGroups[i].mFarCulledTriCount; j++) {
						tmpGroups[i].mFarCulledTriDistances[j] = stream.readByte();
					}
				}
			}

			PRINT("got a max of %d col tris in one block!\n", maxTrisPerGroup);

			CollGroup* group     = new CollGroup();
			group->mTriCount     = 0;
			group->mTriangleList = nullptr;
			int validTriCount    = 0;
			f32 maxDist          = 0.0f;
			for (int i = 0; i < mGridSizeY; i++) {
				for (int j = 0; j < mGridSizeX; j++) {
					int groupIdx = stream.readInt();
					if (groupIdx == -1) {
						mCollGroups[j + i * mGridSizeX] = group;
						continue;
					}

					mCollGroups[j + i * mGridSizeX] = &tmpGroups[groupIdx];
					f32 cellSize                    = 64.0f;
					f32 cellMinX                    = mCourseExtents.mMin.x + f32(j) * cellSize;
					f32 cellMinZ                    = mCourseExtents.mMin.z + f32(i) * cellSize;

					f32 expansionSize = 64.0f * 1.0f;
					BoundBox cellBox;
					Vector3f lower(cellMinX - 64.0f, mCourseExtents.mMin.y - expansionSize, cellMinZ - 64.0f);
					cellBox.expandBound(lower);
					Vector3f upper(cellMinX + cellSize + expansionSize, mCourseExtents.mMax.y + expansionSize,
					               cellMinZ + cellSize + expansionSize);
					cellBox.expandBound(upper);

					for (int k = 0; k < tmpGroups[groupIdx].mTriCount; k++) {
						CollTriInfo* tri = tmpGroups[groupIdx].mTriangleList[k];
						f32 dist         = triRectDistance(&mVertexList[tri->mVertexIndices[0]], &mVertexList[tri->mVertexIndices[1]],
						                                   &mVertexList[tri->mVertexIndices[2]], cellBox, false);
						if (dist >= 0.001f) {
							validTriCount++;
							if (dist > maxDist) {
								maxDist = dist;
							}
						}
					}
				}
			}

			PRINT("maxDist = %f : got a total of %d col tris in lists mem = %d bytes!\n", maxDist, validTriCount, 8 * validTriCount);

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			PRINT("!!!!!!!!!!!!!!!!! COLLGRID USING %.2f kbytes\n", (before - after) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}

		default: {
			skipChunk(stream, length);
		}
		}
	} while (chunkType != 0xFFFF);

	if (stream.getPending()) {
		importIni(stream);
	}

	mAnimMatrixId = mJointCount + mEnvelopeCount;

	// i don't even care anymore. i am numb to this.
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
	PRINT("fake", chunkType ? "fake" : "fake");
}

/*
 * --INFO--
 * Address:	800338B8
 * Size:	000248
 */
void BaseShape::initIni(bool p1)
{
	for (LightGroup* light = (LightGroup*)mLightGroup.Child(); light; light = (LightGroup*)light->mNext) {
		if (!light->mTexSource) {
			continue;
		}

		int idx = -1;
		if (light->mMatSource) {
			for (int i = 0; i < (int)strlen(light->mMatSource); i++) {
				u8* src = (u8*)light->mMatSource;
				if (src[i] == (u32)':') {
					sscanf(&light->mMatSource[i + 1], "%d", &idx);
					break;
				}
			}
		}

		if (idx == -1) {
			light->mHaloTex = gsys->loadTexture(light->mTexSource, true);
		}

		Material* mat;
		if (idx == -1) {
			mat = nullptr;
		} else {
			mat = &mMaterialList[idx];
		}

		u32 heapIdx = gsys->mActiveHeapIdx;
		if (heapIdx == SYSHEAP_Teki) {
			gsys->setHeap(SYSHEAP_App);
		}

		// god you better hope there's a halo texture, this is a very illegal cast.
		light->mFlareGroup = gsys->registerLFlare((light->mHaloTex) ? light->mHaloTex : (Texture*)mat);

		gsys->setHeap(heapIdx);
		if (idx != -1) {
			light->mFlareGroup->mMaterial = mat;
			light->mFlareGroup->mTexture  = mat->mTexture;
		}
	}

	for (ObjCollInfo* coll = (ObjCollInfo*)mCollisionInfo.Child(); coll; coll = (ObjCollInfo*)coll->mNext) {
		if (coll->mCollType == OCT_Platform && p1) {
			coll->mPlatShape = gsys->loadShape(coll->mPlatformName, true);
			if (coll->mPlatShape) {
				coll->mPlatShape->createCollisions(32);
			}
			if (coll->mFlags) {
				coll->mPlatShape->mSystemFlags |= ShapeFlags::IsPlatform;
			}
		}
		for (ObjCollInfo* childColl = (ObjCollInfo*)coll->Child(); childColl; childColl = (ObjCollInfo*)childColl->mNext) {
			if (childColl->mCollType == OCT_Platform && p1) {
				childColl->mPlatShape = gsys->loadShape(childColl->mPlatformName, true);
				if (childColl->mPlatShape) {
					childColl->mPlatShape->createCollisions(32);
				}
				if (childColl->mFlags) {
					childColl->mPlatShape->mSystemFlags |= ShapeFlags::IsPlatform;
				}
			}
		}
	}

	for (RouteGroup* route = (RouteGroup*)mRouteGroup.Child(); route; route = (RouteGroup*)route->mNext) {
		// route->_BC = gsys->loadTexture("rootRing.txe", true);
		// route->_BC->mTexFlags = (0x100 | 0x1);
		route->mDebugWaypointTexture = nullptr;
	}
}

/*
 * --INFO--
 * Address:	80033B00
 * Size:	000258
 */
void BaseShape::initialise()
{
	u32 badCompiler;
	for (int i = 0; i < mTexAttrCount; i++) {
		if (!(mTexAttrList[i].mTextureIndex & 0x8000)) {
			mTexAttrList[i].mImage         = &mTextureList[mTexAttrList[i].mTextureIndex];
			mTexAttrList[i].mImage->mIndex = mTexAttrList[i].mTextureIndex;
			mTexAttrList[i].initImage();
		} else {
			if (!mTexAttrList[i].mTexture) {
				mTexAttrList[i].mTexture = mResolvedTextureList[mTexAttrList[i].mTextureIndex & 0x7FFF];
			}
		}
	}

	for (int i = 0; i < mMaterialCount; i++) {
		if (mMaterialList[i].mFlags & 1) {
			for (int j = 0; j < mMaterialList[i].mTextureInfo.mTextureDataCount; j++) {
				mMaterialList[i].mTextureInfo.mTextureData[j].mTextureAttribute
				    = &mTexAttrList[mMaterialList[i].mTextureInfo.mTextureData[j].mSourceAttrIndex];
				mMaterialList[i].mTextureInfo.mTextureData[j].mTexture
				    = mTexAttrList[mMaterialList[i].mTextureInfo.mTextureData[j].mSourceAttrIndex].mTexture;
			}
		} else if (mMaterialList[i].mTextureIndex != -1) {
			mMaterialList[i].mAttribute = &mTexAttrList[mMaterialList[i].mTextureIndex];
			mMaterialList[i].mTexture   = mTexAttrList[mMaterialList[i].mTextureIndex].mTexture;
		} else {
			mMaterialList[i].mTexture = nullptr;
		}
	}

	mCurrentAnimation                = new AnimContext();
	mCurrentAnimation->mData         = nullptr;
	mCurrentAnimation->mCurrentFrame = 0.0f;
	importDck(nullptr, nullptr);
	calcBasePose(Matrix4f::ident);
	if (mJointCount) {
		mAnimOverrides = new AnimContext*[mJointCount];

		for (int i = 0; i < mJointCount; i++) {
			mAnimOverrides[i] = mCurrentAnimation;
		}
	}

	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  li        r31, 0
	  stw       r30, 0x20(r1)
	  addi      r30, r3, 0
	  stw       r29, 0x1C(r1)
	  li        r29, 0
	  b         .loc_0x94

	.loc_0x28:
	  lwz       r0, 0x6C(r30)
	  add       r5, r0, r29
	  lwz       r4, 0x18(r5)
	  rlwinm.   r0,r4,0,16,16
	  bne-      .loc_0x70
	  mulli     r0, r4, 0x34
	  lwz       r3, 0x78(r30)
	  add       r0, r3, r0
	  stw       r0, 0x30(r5)
	  lwz       r0, 0x6C(r30)
	  add       r3, r0, r29
	  lwz       r0, 0x18(r3)
	  lwz       r3, 0x30(r3)
	  stw       r0, 0x14(r3)
	  lwz       r0, 0x6C(r30)
	  add       r3, r0, r29
	  bl        -0xAC44
	  b         .loc_0x8C

	.loc_0x70:
	  lwzu      r0, 0x2C(r5)
	  cmplwi    r0, 0
	  bne-      .loc_0x8C
	  lwz       r3, 0x2A0(r30)
	  rlwinm    r0,r4,2,15,29
	  lwzx      r0, r3, r0
	  stw       r0, 0x0(r5)

	.loc_0x8C:
	  addi      r29, r29, 0x34
	  addi      r31, r31, 0x1

	.loc_0x94:
	  lwz       r0, 0x68(r30)
	  cmpw      r31, r0
	  blt+      .loc_0x28
	  li        r4, 0
	  li        r3, 0
	  b         .loc_0x180

	.loc_0xAC:
	  lwz       r0, 0x44(r30)
	  add       r7, r0, r3
	  lwz       r0, 0x18(r7)
	  rlwinm.   r0,r0,0,31,31
	  beq-      .loc_0x130
	  li        r10, 0
	  li        r8, 0
	  b         .loc_0x118

	.loc_0xCC:
	  lwz       r0, 0x84(r6)
	  addi      r10, r10, 0x1
	  lwz       r6, 0x6C(r30)
	  add       r7, r0, r8
	  lwz       r0, 0x0(r7)
	  mulli     r0, r0, 0x34
	  add       r0, r6, r0
	  stw       r0, 0x4(r7)
	  lwz       r6, 0x44(r30)
	  lwz       r7, 0x6C(r30)
	  addi      r0, r6, 0x84
	  lwzx      r0, r3, r0
	  add       r9, r0, r8
	  lwz       r0, 0x0(r9)
	  addi      r8, r8, 0x9C
	  mulli     r6, r0, 0x34
	  addi      r0, r6, 0x2C
	  lwzx      r0, r7, r0
	  stw       r0, 0x8(r9)

	.loc_0x118:
	  lwz       r0, 0x44(r30)
	  add       r6, r3, r0
	  lwz       r0, 0x74(r6)
	  cmpw      r10, r0
	  blt+      .loc_0xCC
	  b         .loc_0x178

	.loc_0x130:
	  lwz       r0, 0x1C(r7)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x170
	  mulli     r0, r0, 0x34
	  lwz       r6, 0x6C(r30)
	  add       r0, r6, r0
	  stw       r0, 0x20(r7)
	  lwz       r0, 0x44(r30)
	  lwz       r7, 0x6C(r30)
	  add       r8, r0, r3
	  lwz       r0, 0x1C(r8)
	  mulli     r6, r0, 0x34
	  addi      r0, r6, 0x2C
	  lwzx      r0, r7, r0
	  stw       r0, 0x24(r8)
	  b         .loc_0x178

	.loc_0x170:
	  li        r0, 0
	  stw       r0, 0x24(r7)

	.loc_0x178:
	  addi      r3, r3, 0x9C
	  addi      r4, r4, 0x1

	.loc_0x180:
	  lwz       r0, 0x40(r30)
	  cmpw      r4, r0
	  blt+      .loc_0xAC
	  li        r3, 0x10
	  bl        0x13374
	  cmplwi    r3, 0
	  beq-      .loc_0x1C0
	  lis       r4, 0x8023
	  subi      r0, r4, 0x7730
	  stw       r0, 0xC(r3)
	  li        r0, 0
	  stw       r0, 0x0(r3)
	  lfs       f0, -0x7D20(r2)
	  stfs      f0, 0x4(r3)
	  lfs       f0, -0x7D18(r2)
	  stfs      f0, 0x8(r3)

	.loc_0x1C0:
	  stw       r3, 0x18(r30)
	  li        r29, 0
	  addi      r3, r30, 0
	  lwz       r6, 0x18(r30)
	  li        r4, 0
	  li        r5, 0
	  stw       r29, 0x0(r6)
	  lfs       f0, -0x7D20(r2)
	  lwz       r6, 0x18(r30)
	  stfs      f0, 0x4(r6)
	  bl        0xE50
	  lis       r3, 0x803A
	  subi      r4, r3, 0x77C0
	  addi      r3, r30, 0
	  bl        0xC08
	  lwz       r0, 0x58(r30)
	  cmpwi     r0, 0
	  beq-      .loc_0x23C
	  rlwinm    r3,r0,2,0,29
	  bl        0x132F8
	  stw       r3, 0x1C(r30)
	  li        r4, 0
	  b         .loc_0x230

	.loc_0x21C:
	  lwz       r0, 0x18(r30)
	  addi      r4, r4, 0x1
	  lwz       r3, 0x1C(r30)
	  stwx      r0, r3, r29
	  addi      r29, r29, 0x4

	.loc_0x230:
	  lwz       r0, 0x58(r30)
	  cmpw      r4, r0
	  blt+      .loc_0x21C

	.loc_0x23C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  lwz       r29, 0x1C(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80033D58
 * Size:	000BA8
 */
void BaseShape::createCollisions(int gridSize)
{
	// the DLL version has a whole section at the top doing vector nonsense which sort of got stripped?
	// clearly still has some stack things remaining
	u32 badCompiler[768];

	u32 heapStart = gsys->getHeap(SYSHEAP_App)->getFree();

	if (mCollGroups) {
		return;
	}

	mCourseExtents.resetBound();
	for (int i = 0; i < mTriCount; i++) {
		mCourseExtents.expandBound(mVertexList[mTriList[i].mVertexIndices[0]]);
		mCourseExtents.expandBound(mVertexList[mTriList[i].mVertexIndices[1]]);
		mCourseExtents.expandBound(mVertexList[mTriList[i].mVertexIndices[2]]);
	}
	CollGroup unused;
	mGridSize  = gridSize;
	mGridSizeX = (mCourseExtents.mMax.x - mCourseExtents.mMin.x + mGridSize) / mGridSize;
	mGridSizeY = (mCourseExtents.mMax.z - mCourseExtents.mMin.z + mGridSize) / mGridSize;

	PRINT("Gridsize %f : course extents from (%.1f, %.1f, %.1f) - (%.1f, %.1f, %.1f) : grid %d x %d\n", mCourseExtents.mMin.x,
	      mCourseExtents.mMin.y, mCourseExtents.mMin.z, mCourseExtents.mMax.x, mCourseExtents.mMax.y, mCourseExtents.mMax.z, mGridSizeX,
	      mGridSizeY);
	mCollGroups       = new CollGroup*[mGridSizeX * mGridSizeY];
	CollGroup* groups = new CollGroup[mGridSizeX * mGridSizeY];
	for (int j = 0; j < mGridSizeX * mGridSizeY; j++) {
		mCollGroups[j] = &groups[j];
	}

	int triCount = 0;
	CollTriInfo* tris[256];
	int b         = 0;
	int c         = 0;
	int numUnique = 0;
	for (int y = 0; y < mGridSizeY; y++) {
		for (int x = 0; x < mGridSizeX; x++) {
			f32 minX = x * mGridSize + mCourseExtents.mMin.x;
			f32 minZ = y * mGridSize + mCourseExtents.mMin.z;
			f32 size = mGridSize * 1.0f;

			BoundBox box1;
			box1.expandBound(Vector3f(minX - size, mCourseExtents.mMin.y - size, minZ - size));

			box1.expandBound(Vector3f(minX + mGridSize + size, mCourseExtents.mMax.y + size, minZ + mGridSize + size));

			triCount = 0;
			for (int i = 0; i < mTriCount; i++) {
				BoundBox box2;
				box2.resetBound();
				box2.expandBound(mVertexList[mTriList[i].mVertexIndices[0]]);
				box2.expandBound(mVertexList[mTriList[i].mVertexIndices[1]]);
				box2.expandBound(mVertexList[mTriList[i].mVertexIndices[2]]);

				if (box2.intersects(box1)) {
					f32* boxVals      = (f32*)&box1;
					int indices[8][3] = {
						{ 0, 1, 2 }, { 0, 1, 5 }, { 0, 4, 2 }, { 0, 4, 5 }, { 3, 1, 2 }, { 3, 1, 5 }, { 3, 4, 2 }, { 3, 4, 5 },
					};
					CullingPlane unused2[3];
					bool check1 = true;
					int d       = 0;
					for (int j = 0; j < 8; j++) {
						Vector3f point(boxVals[indices[j][0]], boxVals[indices[j][1]], boxVals[indices[j][2]]);
						if (mTriList[i].mTriangle.dist(point) < 0.0f) {
							d++;
						}
					}

					if (d == 8) {
						check1 = false;
					}

					if (check1) {
						tris[triCount] = &mTriList[i];
						triCount++;
						if (triCount == 1024) {
							ERROR("Too many tris per block for collision system!!");
						}
					}
				}
			}

			if (triCount) {
				b += triCount;
				CollGroup* groupA = nullptr;

				for (int i = 0; i < c; i++) {
					int row = i / mGridSizeX; // might be other way around?
					int col = i % mGridSizeX;

					CollGroup* group = mCollGroups[col + mGridSizeX * row];
					if (group->mTriCount == triCount) {
						bool check2 = true;
						for (int j = 0; j < triCount; j++) {
							if (group->mTriangleList[j] != tris[j]) {
								check2 = false;
								break;
							}
						}

						if (check2) {
							groupA = group;
							break;
						}
					}
				}

				if (!groupA) {
					CollGroup* g     = mCollGroups[x + y * mGridSizeX];
					g->mTriCount     = triCount;
					g->mTriangleList = new CollTriInfo*[triCount];
					for (int i = 0; i < triCount; i++) {
						g->mTriangleList[i] = tris[i];
					}

					numUnique++;
				} else {
					mCollGroups[x + y * mGridSizeX]->mTriangleList = groupA->mTriangleList;
					mCollGroups[x + y * mGridSizeX]->mTriCount     = groupA->mTriCount;
				}
			}

			c++;
		}
	}

	PRINT("got a total of %d unique groups\n", numUnique);
	PRINT("*------------------------------------------- collision data uses %.2fk\n",
	      (heapStart - gsys->getHeap(SYSHEAP_App)->getFree()) / 1024.0f);
}

/*
 * --INFO--
 * Address:	80034900
 * Size:	000150
 */
void BaseShape::calcBasePose(Matrix4f& target)
{
	for (int i = 0; i < mJointCount; i++) {
		SRT srt;
		srt.mScale       = mJointList[i].mScale;
		srt.mRotation    = mJointList[i].mRotation;
		srt.mTranslation = mJointList[i].mTranslation;

		int parentIndex = mJointList[i].mParentIndex;
		Matrix4f initialPose;
		Matrix4f* currentMatrix = parentIndex == -1 ? &target : &mJointList[parentIndex].mAnimMatrix;
		mJointList[i].mAnimMatrix.makeConcatSRT(currentMatrix, initialPose, srt);
		mJointList[i].mAnimMatrix.inverse(&mJointList[i].mInverseAnimMatrix);
	}
}

/*
 * --INFO--
 * Address:	80034A50
 * Size:	0000E8
 */
AnimData* BaseShape::loadDck(char* name, RandomAccessStream& s)
{
	AnimDck* pDck = new AnimDck(name);
	pDck->mModel  = this;
	pDck->read(s);
	if (pDck->mJointCount != mJointCount) {
		PRINT("(%s) NUMJOINTS DOES NOT MATCH, THINGS MIGHT GO WRONG!!!\n", name);
	}

	mCurrentAnimation->mData         = pDck;
	mCurrentAnimation->mCurrentFrame = 0.0f;
	return pDck;
}

/*
 * --INFO--
 * Address:	80034B38
 * Size:	0001E0
 */
AnimData* BaseShape::importDck(char* name, CmdStream* cmds)
{
	AnimDck* data;
	if (!name) {
		data = new AnimDck(this, mJointCount);
		data->setName("Null Anim");
	} else {
		data         = new AnimDck(name);
		data->mModel = this;
		data->parse(cmds);
	}

	if (data->mJointCount != mJointCount) {
		PRINT("(%s) NUMJOINTS DOES NOT MATCH, THINGS MIGHT GO WRONG!!!\n", name);
		data = nullptr;
	}

	// debugData.add(data);
	mCurrentAnimation->mData         = data;
	mCurrentAnimation->mCurrentFrame = 0.0f;
	return data;
}

/*
 * --INFO--
 * Address:	80034D18
 * Size:	0000DC
 */
AnimData* BaseShape::loadDca(char* name, RandomAccessStream& s)
{
	AnimDca* pDca = new AnimDca(name);
	pDca->mModel  = this;
	pDca->read(s);
	if (pDca->mJointCount != mJointCount) {
		PRINT("(%s) NUMJOINTS DOES NOT MATCH, THINGS MIGHT GO WRONG!!!\n", name);
	}

	mCurrentAnimation->mData = pDca;
	return pDca;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
void BaseShape::importDca(char* name, CmdStream* cmds)
{
	AnimDca* data;
	if (!name) {
		data = new AnimDca(this, mJointCount);
	} else {
		data         = new AnimDca(name);
		data->mModel = this;
		data->parse(cmds);
	}

	if (data->mJointCount != mJointCount) {
		PRINT("NUMJOINTS DOES NOT MATCH, THINGS MIGHT GO WRONG!!!\n");
	}

	// debugData.add(data);
	mCurrentAnimation->mData = data;
}

/*
 * --INFO--
 * Address:	80034DF4
 * Size:	0001C4
 */
AnimData* BaseShape::loadAnimation(char* name, bool p2)
{
	RandomAccessStream* stream = gsys->openFile(name, p2, true);
	if (stream) {

		CmdStream* cmds = new CmdStream(stream);
		if (cmds) {

			int i = strlen(name) - 1;
			for (i; i >= 0; i--) {
				if (name[i] == (u32)'.') {
					break;
				}
			}

			if (!strcmp(&name[i], ".dck")) {
				importDck(name, cmds);
			} else if (!strcmp(&name[i], ".dca")) {
				importDca(name, cmds);
			}

			stream->close();

			if (!mCurrentAnimation->mData) {
				PRINT("returning NULL anim!!\n");
			}

			return mCurrentAnimation->mData;
		}
	} else {
		PRINT("failed to open %s\n", name);
	}

	return nullptr;
}

/*
 * --INFO--
 * Address:	80034FE8
 * Size:	000010
 */
Matrix4f& BaseShape::getAnimMatrix(int i)
{
	return mAnimMatrices[i];
}

/*
 * --INFO--
 * Address:	80034FF8
 * Size:	000038
 */
void BaseShape::backupAnimOverrides(AnimContext** animList)
{
	mBackupAnimOverrides = animList;
	for (int i = 0; i < mJointCount; i++) {
		mBackupAnimOverrides[i] = mAnimOverrides[i];
	}
}

/*
 * --INFO--
 * Address:	80035030
 * Size:	000034
 */
void BaseShape::restoreAnimOverrides()
{
	for (int i = 0; i < mJointCount; i++) {
		mAnimOverrides[i] = mBackupAnimOverrides[i];
	}
}

/*
 * --INFO--
 * Address:	80035064
 * Size:	000094
 */
void BaseShape::overrideAnim(int jointIdx, AnimContext* anim)
{
	Joint* joint = &mJointList[jointIdx];
	joint->overrideAnim(anim);
	if (joint->mChild) {
		((Joint*)joint->mChild)->recOverrideAnim(anim);
	}
}

/*
 * --INFO--
 * Address:	800350F8
 * Size:	000074
 */
AnimFrameCacher::AnimFrameCacher(int num)
{
	mCache      = new AyuCache(num * 64);
	mInfo.mName = "root";
	mInfo.mNext = mInfo.mPrev = &mInfo;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void AnimFrameCacher::updateInfo(AnimCacheInfo* info)
{
	if (mInfo.mNext != info->mCachedMtxBlock) {
		info->mCachedMtxBlock->remove();
		mInfo.insertAfter(info->mCachedMtxBlock);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void AnimFrameCacher::removeOldest()
{
	TexCacheInfo* prev = (TexCacheInfo*)mInfo.mPrev;
	void* p            = prev;
	prev->remove();
	prev->_0C->mPrev = nullptr;
	mCache->cacheFree(p);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003516C
 * Size:	0001A8
 */
void AnimFrameCacher::cacheFrameSpace(int p1, AnimCacheInfo* info)
{
	u32 texSize = OSRoundDown32B(59 + 4 * p1 + 64 * p1);

	while (true) {
		if (mCache->largestBlockFree() > texSize) {
			FrameCacher* alloc = (FrameCacher*)mCache->mallocL(texSize);
			alloc->_18         = &alloc->_1C[0];
			alloc->_14         = &alloc->_1C[p1];
			alloc->_0C         = &info->mCachedMtxBlock;

			for (int i = 0; i < p1; i++) {
				alloc->_18[i] = 0;
			}

			info->mCachedMtxBlock = alloc;
			mInfo.insertAfter(alloc);
			break;
		}

		removeOldest();
	}
}

/*
 * --INFO--
 * Address:	80035314
 * Size:	0002E0
 */
void BaseShape::updateAnim(Graphics& gfx, Matrix4f& mtx, f32* p3)
{
	gsys->mTimer->start("updateAnim", true);
	gsys->mAnimatedPolygons++;
	mAnimMatrices = gfx.getMatrices(mAnimMatrixId);

	if (mCurrentAnimation->mData) {
		if (!p3) {
			mCurrentAnimation->animate(mCurrentAnimation->mFrameRate);
		}

		for (int i = 0; i < mJointCount; i++) {
			AnimData* data = mAnimOverrides[i]->mData;
			if (!data) {
				ERROR("no joint anim!!\n");
			}
			f32* frame = (p3) ? p3 : &mAnimOverrides[i]->mCurrentFrame;

			if (mFrameCacher && data->mAnimFlags & ANIMFLAG_Unk3) {
				int frameNum = int(*frame);
				if (frameNum >= data->mTotalFrameCount) {
					ERROR("updateAnim: too large a frame number : %d / %d, %f\n", frameNum, data->mTotalFrameCount, *frame);
				}
				if (!data->mAnimInfoList[frameNum].mCachedMtxBlock) {
					mFrameCacher->cacheFrameSpace(data->mActiveJointCount, &data->mAnimInfoList[frameNum]);
				} else {
					mFrameCacher->updateInfo(&data->mAnimInfoList[frameNum]);
				}
			}

			if (data->mTotalFrameCount) {
				Matrix4f& srt = (mJointList[i].mParentIndex != -1) ? mAnimMatrices[mJointList[i].mParentIndex] : mtx;

				data->makeAnimSRT(data->mAnimJointIndices[i], &srt, &mAnimMatrices[i], &data->mAnimInfo[i], *frame);
			} else {
				PSMTXConcat(mtx.mMtx, mJointList[i].mAnimMatrix.mMtx, mAnimMatrices[i].mMtx);
			}
		}

		calcWeightedMatrices();
	} else {
		Joint* joint = &mJointList[0];
		for (int i = 0; i < mJointCount; i++) {
			SRT srt;
			srt.mScale       = joint->mScale;
			srt.mRotation    = joint->mRotation;
			srt.mTranslation = joint->mTranslation;
			Matrix4f tmpMtx;
			Matrix4f* jointMtx = (joint->mParentIndex == -1) ? &mtx : &mJointList[joint->mParentIndex].mAnimMatrix;
			joint->mAnimMatrix.makeConcatSRT(jointMtx, tmpMtx, srt);
			joint++;
		}
	}

	gsys->mTimer->stop("updateAnim");
}

/*
 * --INFO--
 * Address:	800355F4
 * Size:	000190
 */
void BaseShape::calcWeightedMatrices()
{
	for (int i = 0; i < mEnvelopeCount; i++) {
		f32* mtx = (f32*)&mAnimMatrices[mJointCount + i];
		for (int j = 0; j < 12; j++) {
			*mtx = 0.0f;
			mtx++;
		}

		for (int j = 0; j < mEnvelopeList[i].mIndexCount; j++) {
			int idx    = mEnvelopeList[i].mIndices[j];
			f32 weight = mEnvelopeList[i].mWeights[j];

			// this is some bullshit right here.

			Matrix4f weighted;
			PSMTXConcat(getAnimMatrix(idx).mMtx, mJointList[idx].mInverseAnimMatrix.mMtx, weighted.mMtx);

			register Matrix4f& mtx1 = weighted;
			register Matrix4f& mtx2 = mAnimMatrices[mJointCount + i];

			f32 weights[2]         = {};
			register f32* weightsR = weights;
			weights[0]             = weight;
			weights[1]             = weight;

			// could probably make this a static inline but eh.
			ASM
			{
				psq_l f0, 0x0(weightsR), 0, 0;
				psq_l f1, 0x0(mtx2), 0, 0;
				psq_l f2, 0x0(mtx1), 0, 0;
				ps_madd f1, f2, f0, f1;
				psq_st f1, 0x0(mtx2), 0, 0;

				psq_l f3, 0x8(mtx2), 0, 0;
				psq_l f2, 0x8(mtx1), 0, 0;
				ps_madd f3, f2, f0, f3;
				psq_st f3, 0x8(mtx2), 0, 0;

				psq_l f1, 0x10(mtx2), 0, 0;
				psq_l f2, 0x10(mtx1), 0, 0;
				ps_madd f1, f2, f0, f1;
				psq_st f1, 0x10(mtx2), 0, 0;

				psq_l f3, 0x18(mtx2), 0, 0;
				psq_l f2, 0x18(mtx1), 0, 0;
				ps_madd f3, f2, f0, f3;
				psq_st f3, 0x18(mtx2), 0, 0;

				psq_l f1, 0x20(mtx2), 0, 0;
				psq_l f2, 0x20(mtx1), 0, 0;
				ps_madd f1, f2, f0, f1;
				psq_st f1, 0x20(mtx2), 0, 0;

				psq_l f3, 0x28(mtx2), 0, 0;
				psq_l f2, 0x28(mtx1), 0, 0;
				ps_madd f3, f2, f0, f3;
				psq_st f3, 0x28(mtx2), 0, 0;
			};
		}
	}
}

/*
 * --INFO--
 * Address:	80035784
 * Size:	000140
 */
void BaseShape::makeNormalIndexes(u16* indices)
{
	for (int i = 0; i < mTotalMatpolyCount; i++) {
		Mesh* mesh = &mMeshList[mMatpolyList[i]->mMeshIndex];

		for (int j = 0; j < mesh->mMtxGroupCount; j++) {
			MtxGroup* group    = &mesh->mMtxGroupList[j];
			DispList* dispList = group->mDispList;
			for (int k = 0; k < group->mDispListLength; k++) {
				u8* data    = (u8*)dispList->mData;
				u32 dataLen = dispList->mDataLength;

				while (dataLen && data < (u8*)&dispList->mData[dataLen]) {
					int first = *data++;
					if (!first) {
						dataLen = 0;
					} else {
						int count = (data[0] << 8) | data[1];
						data += 2;
						for (int m = 0; m < count; m++) {
							if (mesh->mVertexDescriptor & 1) {
								data++;
							}

							if (mesh->mVertexDescriptor & 2) {
								data++;
							}
							int shift       = 6;
							u16 idxIdx      = u16((data[0] << 8) | data[1]);
							u16 idx         = u16((data[2] << 8) | data[3]);
							indices[idxIdx] = idx;
							if (mesh->mVertexDescriptor & 4) {
								shift = 8;
							}
							data += shift;
						}
					}
				}
				dispList++;
			}
		}
	}
}

/*
 * --INFO--
 * Address:	800358C4
 * Size:	0000F8
 */
f32 BaseShape::calcJointWorldPos(Graphics& gfx, int index, Vector3f& worldPos)
{
	if (index == -1) {
		return 0.0f;
	}

	Matrix4f& orig = getAnimMatrix(index);
	worldPos.multMatrix(getAnimMatrix(index));
	worldPos.multMatrix(gfx.mCamera->mInverseLookAtMtx);
	return ((Vector3f&)orig).length();
}

/*
 * --INFO--
 * Address:	800359BC
 * Size:	000060
 */
void BaseShape::calcJointWorldDir(Graphics& gfx, int index, Vector3f& worldDir)
{
	if (index == -1) {
		return;
	}

	getAnimMatrix(index);
	Matrix4f& animMtx = getAnimMatrix(index);
	worldDir.rotate(animMtx);
	worldDir.rotate(gfx.mCamera->mInverseLookAtMtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
void BaseShape::calcJointWorldScale(Graphics&, int, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000148
 */
CollTriInfo* BaseShape::findCollTri(Vector3f&, Vector3f&, Vector3f&, char*)
{
	// UNUSED FUNCTION
}
