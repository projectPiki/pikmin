#include "Shape.h"

#include "Animator.h"
#include "CinematicPlayer.h"
#include "CmdStream.h"
#include "Collision.h"
#include "Colour.h"
#include "Common/String.h"
#include "DebugLog.h"
#include "Delegate.h"
#include "Dolphin/mtx.h"
#include "Font.h"
#include "Graphics.h"
#include "Joint.h"
#include "Material.h"
#include "Mesh.h"
#include "PVW.h"
#include "Texture.h"
#include "Vector.h"
#include "sysNew.h"
#include "system.h"
#include "timers.h"

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(23)

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("shapeBase")

Vector3f fnVerts[0x200];
Vector3f fnNorms[0x200];
Vector2f fnTexs[0x200];
u8 matUsed[0x100];
int matIndex;
int usedIndex;
int _dlindx;

static const char* modes[5] = {
	"NONE", "OPA", "TEX", "NONE", "XLU",
};

/**
 * @brief Reads the envelope data from a stream.
 * @param stream The stream to read from.
 * @note UNUSED Size: 0000DC
 */
void Envelope::read(RandomAccessStream& stream)
{
	mIndexCount = stream.readShort();

	// Allocate a single block for both indices and weights
	void* arr = new u8[8 * mIndexCount];
	mIndices  = (s32*)arr;

	// Point weights to after indices in that block
	mWeights = (f32*)&((f32*)arr)[mIndexCount];

	for (int i = 0; i < mIndexCount; i++) {
		mIndices[i] = stream.readShort();
		mWeights[i] = stream.readFloat();
	}
}

/**
 * @brief Reads the display list data from a stream.
 * @param stream The stream to read from.
 */
void DispList::read(RandomAccessStream& stream)
{
	// Match stack size with the original function
	STACK_PAD_VAR(1);

	mFlags      = stream.readInt();
	mFaceCount  = stream.readInt();
	mDataLength = stream.readInt();

	stream.skipPadding(0x20);

	mData = new (0x20) u8[mDataLength];
	stream.read(mData, mDataLength);
}

/**
 * @brief Reads the matrix group data from a stream.
 * @param stream The stream to read from.
 */
void MtxGroup::read(RandomAccessStream& stream)
{
	mDepLength = stream.readInt();
	if (mDepLength) {
		mDepList = new int[mDepLength];
		for (int i = 0; i < mDepLength; i++) {
			mDepList[i] = stream.readShort();
		}
	}

	mDispLength = stream.readInt();
	if (mDispLength) {
		mDispList = new DispList[mDispLength];
		for (int i = 0; i < mDispLength; i++) {
			mDispList[i].read(stream);
		}
	}
}

/**
 * @TODO: Documentation
 */
void Mesh::read(RandomAccessStream& stream)
{
	mParentJoint      = stream.readInt();
	mVertexDescriptor = stream.readInt();
	mMtxGroupCount    = stream.readInt();

	if (mMtxGroupCount) {
		mMtxGroupList = new MtxGroup[mMtxGroupCount];
		mMtxDepIdx    = 0;
		for (int i = 0; i < mMtxGroupCount; i++) {
			mMtxGroupList[i].read(stream);

			if (mMtxGroupList[i].mDepLength > mMtxDepIdx) {
				mMtxDepIdx = mMtxGroupList[i].mDepLength;
			}
		}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000018
 */
void Joint::overrideAnim(AnimContext* anim)
{
	mParentShape->mAnimOverrides[mIndex] = anim;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void Joint::read(RandomAccessStream& stream)
{
	// Match stack size with the original function
	STACK_PAD_VAR(1);

	mParentIndex = stream.readInt();

	int flags      = stream.readInt();
	mUseVolume     = flags & 0x1;
	mUseLightGroup = (flags & 0x4000) != 0;

	mBounds.mMin.read(stream);
	mBounds.mMax.read(stream);
	stream.readFloat();

	mSRT.s.read(stream);
	mSRT.r.read(stream);
	mSRT.t.read(stream);

	mMatPolyCount = stream.readInt();
	mMatPoly.initCore("");
	for (int i = 0; i < mMatPolyCount; i++) {
		MatPoly* mPoly    = new MatPoly();
		mPoly->mIndex     = stream.readShort();
		mPoly->mMeshIndex = stream.readShort();
		mMatPoly.add(mPoly);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00043C
 */
void Joint::render(Graphics& gfx)
{
#if 0 // This is a messy DLL-exclusive function that somebody left really unfinished.  It would be nice to see it restored.
	if (!mFlags)
		return;

	for (Joint::MatPoly* matPoly = (MatPoly*)mMatPoly.mChild; matPoly; matPoly = (MatPoly*)matPoly->mNext) {
		Mesh* mesh = matPoly->mMesh;
		if ((gfx.m_dword8 & matPoly->mMaterial->mFlags) == 0) {
			continue;
		}

		gfx.useMaterial(matPoly->mMaterial);
		for (int j = 0; j < mesh->mMtxGroupCount; ++j) {
			MtxGroup* mtxGroup              = &mesh->mMtxGroupList[j];
			immut Matrix4f* matrixArray[10] = { &Matrix4f::ident };
			for (int k = 0; k < mtxGroup->mDependencyLength; ++k) {
				int depIndex = mtxGroup->mDependencyList[k];
				if (depIndex == -1)
					continue;

				VtxMatrix* vtxMatrix = &mParentShape->mVtxMatrixList[depIndex];
				// A lot wrong here.
				immut Matrix4f* matrix
				    = mParentShape->mCurrentAnimation->m_state
				        ? BaseShape::getAnimMatrix(mParentShape,
				                                   vtxMatrix->mIndex + (vtxMatrix->mHasPartialWeights ? 0 : mParentShape->mJointCount))
				        : &mParentShape->mJointList[vtxMatrix->mIndex].mAnimMatrix;
				matrixArray[k] = matrix;
			}
			Vector3f* vertices  = mParentShape->mVertexList;
			Vector2f* texCoords = mParentShape->mTexCoordList[0];
			Vector3f* normal    = (mesh->m_vcd & 0x10000) ? mParentShape->mNBTList : mParentShape->mNormalList;
			int normalStride    = (mesh->m_vcd & 0x10000) ? 3 : 1;
			DispList* dispList  = mtxGroup->mDispList;
			for (int l = 0; l < mtxGroup->mDispListLength; ++l, dispList++) {
				gfx.setCullFront(gfx.m_dword338 ^ dispList->mFlags & 3);

				for (FaceNode* faceNode = (FaceNode*)dispList->mFaceNode.mChild; faceNode; faceNode = (FaceNode*)faceNode->mNext) {
					int* vertexIndex   = faceNode->mVtxIdx;
					int* matrixIndex   = faceNode->mMtxIdx;
					int* normalIndex   = faceNode->mNrmIdx;
					int* texCoordIndex = faceNode->mTexCoords[0];
					for (int n = 0; n < faceNode->mFaceCount; ++n) {
						immut Matrix4f* matrix      = matrixIndex ? matrixArray[*matrixIndex++] : matrixArray[0];
						Vector3f* vertex            = &vertices[*vertexIndex++];
						Vector3f* transformedVertex = &unk_101C8B68++;
						vertex->multMatrixTo(*matrix, *transformedVertex);
						if (normalIndex) {
							Vector3f* normalPtr         = &normal[normalStride * *normalIndex++];
							Vector3f* transformedNormal = &unk_101C7368++;
							normalPtr->rotateTo(*matrix, *transformedNormal);
						}
						if (texCoordIndex) {
							// Assuming unk_101C6368 is a pointer to a Vector3f or similar structure for texture coordinates.
							Vector3f* texCoord = &unk_101C6368++;
							texCoord->x        = texCoords[*texCoordIndex].x;
							texCoord->y        = texCoords[*texCoordIndex++].y;
						}
					}
					if (dispList->mFlags & 0x1000000) {
						gfx.drawOneStrip(&unk_101C8B68, normalIndex ? &unk_101C7368 : 0, texCoordIndex ? &unk_101C6368 : 0,
						                 faceNode->mFaceCount);
					} else {
						gfx.drawOneTri(&unk_101C8B68, normalIndex ? &unk_101C7368 : 0, texCoordIndex ? &unk_101C6368 : 0,
						               faceNode->mFaceCount);
					}
				}
			}
		}
		gfx.useMaterial(nullptr);
	}
#endif
}

/**
 * @TODO: Documentation
 */
void AnimContext::animate(f32 animSpeed)
{
	mCurrentFrame += gsys->getFrameTime() * animSpeed;

	int frame = static_cast<int>(mCurrentFrame);
	if (frame >= mData->mTotalFrameCount) {
		mCurrentFrame = 0.0f;
	}
}

/**
 * @TODO: Documentation
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

	PVWKeyInfoF32 start, end, unused;

	if (dataSize == 3) {
		start.mTime    = data.mData[offset];
		start.mValue   = data.mData[offset + 1];
		start.mTangent = data.mData[offset + 2];
		offset += dataSize;
		end.mTime    = data.mData[offset];
		end.mValue   = data.mData[offset + 1];
		end.mTangent = data.mData[offset + 2];
		(void)(start.mTangent - end.mTangent);
	} else {
		start.mTime    = data.mData[offset];
		start.mValue   = data.mData[offset + 1];
		start.mTangent = data.mData[offset + 3];
		offset += dataSize;
		end.mTime    = data.mData[offset];
		end.mValue   = data.mData[offset + 1];
		end.mTangent = data.mData[offset + 2];
	}

	// Interpolation calculations
	const f32 fps /*maybe*/ = 30.f;
	f32 t                   = (currTime - start.mTime) * (1.0f / fps);
	f32 frameDelta          = fps / (end.mTime - start.mTime);
	f32 tSqr                = t * t;
	f32 deltaSqr            = frameDelta * frameDelta;
	f32 tCube               = tSqr * t;
	f32 deltaCube           = deltaSqr * frameDelta;

	return (2.0f * tCube * deltaCube - 3.0f * tSqr * deltaSqr + 1.0f) * start.mValue
	     + (-2.0f * tCube * deltaCube + 3.0f * tSqr * deltaSqr) * end.mValue
	     + (tCube * deltaSqr - 2.0f * tSqr * frameDelta + t) * start.mTangent + (tCube * deltaSqr - tSqr * frameDelta) * end.mTangent;
}

/**
 * @TODO: Documentation
 */
CamDataInfo::CamDataInfo()
{
	mCamera.mNear        = 1.0f;
	mCamera.mFar         = 15000.0f;
	mCamera.mAspectRatio = 640.0f / 480.0f;
	mUseStaticCamera     = 0;
};

/**
 * @TODO: Documentation
 */
void CamDataInfo::update(f32 currentFrame, immut Matrix4f& mtx)
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
			((f32*)&mCamera.mPosition)[i] = extract(currentFrame, thisParam, *mSceneData->mCameraAnimations);
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
			((f32*)&mCamera.mFocus)[i] = extract(currentFrame, thisParam, *mSceneData->mCameraAnimations);
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
			val1 = extract(currentFrame, thisParam, *mSceneData->mCameraAnimations);
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
			val2 = extract(currentFrame, thisParam, *mSceneData->mCameraAnimations);
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

	STACK_PAD_VAR(4);
}

/**
 * @TODO: Documentation
 */
void LightDataInfo::update(f32 currentFrame)
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
			((f32*)&vec1)[i] = extract(currentFrame, thisParam, *mSceneData->mLightAnimations);
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
			tmp2[i] = extract(currentFrame, thisParam, *mSceneData->mLightAnimations);
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
			((f32*)&vec2)[i - 1] = extract(currentFrame, thisParam, *mSceneData->mLightAnimations);
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

	STACK_PAD_VAR(3);
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void AnimData::extractSRT(SRT& srt, int, AnimDataInfo* info, f32 p4)
{
	if (info->mFlags & AnimDataFlags::MatrixCalculated) {
		return;
	}

	if (!(info->mFlags & AnimDataFlags::AllScaleStatic)) {
		f32* scale = (f32*)&srt.s;
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

		if ((info->mFlags & AnimDataFlags::AllIndividualScaleStatic) == AnimDataFlags::AllIndividualScaleStatic) {
			info->mFlags |= AnimDataFlags::AllScaleStatic;
		}
	}

	if (!(info->mFlags & AnimDataFlags::AllRotationStatic)) {
		f32* rotate = (f32*)&srt.r;
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

		if ((info->mFlags & AnimDataFlags::AllIndividualRotationStatic) == AnimDataFlags::AllIndividualRotationStatic) {
			info->mFlags |= AnimDataFlags::AllRotationStatic;
		}
	}

	if (!(info->mFlags & AnimDataFlags::AllTranslationStatic)) {
		f32* transl = (f32*)&srt.t;
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

		if ((info->mFlags & AnimDataFlags::AllIndividualTranslationStatic) == AnimDataFlags::AllIndividualTranslationStatic) {
			info->mFlags |= AnimDataFlags::AllTranslationStatic;
		}
	}
}

/**
 * @TODO: Documentation
 */
void AnimData::makeAnimSRT(int boneId, immut Matrix4f* parent, Matrix4f* output, AnimDataInfo* info, f32 pos)
{
	int frameNum = pos;
	if (frameNum < 0 || frameNum > mTotalFrameCount) {
		ERROR("makeSRT too large a frame number : %d / %d : %f\n", frameNum, mTotalFrameCount, pos);
	}

	Matrix4f mtx;
	bool check = true;
	Matrix4f* boneTransform;
	if ((info->mFlags & AnimDataFlags::AllComponentsStatic) != AnimDataFlags::AllComponentsStatic
	    && mAnimInfoList[frameNum].mCachedMtxBlock) {
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
		if ((info->mFlags & AnimDataFlags::AllComponentsStatic) == AnimDataFlags::AllComponentsStatic) {
			boneTransform = &info->mMtx;
			if (!(info->mFlags & AnimDataFlags::MatrixCalculated)) {
				boneTransform->makeSRT(srt.s, srt.r, srt.t);
				info->mFlags |= AnimDataFlags::MatrixCalculated;
			}
		} else {
			output->makeConcatSRT(parent, *boneTransform, srt);
			return;
		}
	}

	PSMTXConcat(parent->mMtx, boneTransform->mMtx, output->mMtx);
}

/**
 * @TODO: Documentation
 */
void AnimData::detach()
{
	for (int i = 0; i < mTotalFrameCount; i++) {
		mAnimInfoList[i].initData();
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00005C
 */
void AnimData::initData()
{
	mAnimInfoList = new AnimCacheInfo[mTotalFrameCount];
}

/**
 * @TODO: Documentation
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

		if ((mAnimInfo[i].mFlags & AnimDataFlags::AllComponentsStatic) != AnimDataFlags::AllComponentsStatic) {
			mAnimJointIndices[i] = animJointCount++;
		} else {
			mAnimJointIndices[i] = 0;
			staticJointCount++;
		}
	}

	mActiveJointCount = mJointCount - staticJointCount;
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void AnimDck::extractSRT(SRT& srt, int, AnimDataInfo* anim, f32 time)
{
	STACK_PAD_VAR(2);
	if (anim->mFlags & AnimDataFlags::MatrixCalculated) {
		return;
	}

	// APPLY SCALE
	if (!(anim->mFlags & AnimDataFlags::AllScaleStatic)) {
		// loop for x y and z
		f32* s = (f32*)&srt.s;
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

		if ((anim->mFlags & AnimDataFlags::AllIndividualScaleStatic) == AnimDataFlags::AllIndividualScaleStatic) {
			anim->mFlags |= AnimDataFlags::AllScaleStatic;
		}
	}

	// APPLY ROTATION
	if (!(anim->mFlags & AnimDataFlags::AllRotationStatic)) {
		// loop for x y and z
		f32* r           = (f32*)&srt.r;
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

		if ((anim->mFlags & AnimDataFlags::AllIndividualRotationStatic) == AnimDataFlags::AllIndividualRotationStatic) {
			anim->mFlags |= AnimDataFlags::AllRotationStatic;
		}
	}

	// APPLY TRANSLATION
	if (!(anim->mFlags & AnimDataFlags::AllTranslationStatic)) {
		// loop for x y and z
		f32* t           = (f32*)&srt.t;
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

		if ((anim->mFlags & AnimDataFlags::AllIndividualTranslationStatic) == AnimDataFlags::AllIndividualTranslationStatic) {
			anim->mFlags |= AnimDataFlags::AllTranslationStatic;
		}
	}
}

/**
 * @TODO: Documentation
 */
void AnimDck::makeAnimSRT(int a, immut Matrix4f* mtx1, Matrix4f* mtx2, AnimDataInfo* anim, f32 time)
{
	SRT& srt = anim->mSRT;
	extractSRT(srt, a, anim, time);
	if ((anim->mFlags & AnimDataFlags::AllComponentsStatic) == AnimDataFlags::AllComponentsStatic) {
		if (!(anim->mFlags & AnimDataFlags::MatrixCalculated)) {
			anim->mMtx.makeSRT(srt.s, srt.r, srt.t);
			anim->mFlags |= AnimDataFlags::MatrixCalculated;
		}
		PSMTXConcat(mtx1->mMtx, anim->mMtx.mMtx, mtx2->mMtx);
	} else {
		Matrix4f mtx;
		mtx2->makeConcatSRT(mtx1, mtx, srt);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00013C
 */
void BaseShape::exportIni(RandomAccessStream& stream, bool doSkipLights)
{
	PRINT("*---------------------------- exporting ini!!!!!!!!!!!\n");
	if (mRouteGroup.Child()) {
		stream.print("// Route info file for %s", Name());
		for (RouteGroup* route = (RouteGroup*)mRouteGroup.Child(); route; route = (RouteGroup*)route->mNext) {
			route->saveini("", stream);
		}
		stream.print("\n");
	}
	if (!doSkipLights && mLightGroup.Child()) {
		stream.print("// LightGroups info file for %s", Name());
		for (LightGroup* light = (LightGroup*)mLightGroup.Child(); light; light = (LightGroup*)light->mNext) {
			light->saveini("", stream);
		}
		stream.print("\n");
	}
	if (mCollisionInfo.Child()) {
		stream.print("// Collision info file for %s", Name());
		for (ObjCollInfo* info = (ObjCollInfo*)mCollisionInfo.Child(); info; info = (ObjCollInfo*)info->mNext) {
			info->saveini("", stream);
		}
		stream.print("\n");
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void ShapeDynMaterials::animate(f32* data)
{
	gsys->mTimer->start("shpDynMats", true);

	for (int i = 0; i < mMatCount; i++) {
		Material& mat = mMaterials[i];
		if (mat.mFlags & MATFLAG_PVW) {
			if (mat.mColourInfo.mTotalFrameCount != 0) {
				mat.mColourInfo.animate(data, mat.Colour());
			}

			for (int j = 0; j < 3; j++) {
				if (mat.mTevInfo->mTevColRegs[j].mAnimFrameCount) {
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

/**
 * @TODO: Documentation
 */
void ShapeDynMaterials::updateContext()
{
	for (int i = 0; i < mMatCount; i++) {
		Material& mat = mMaterials[i];
		if (mat.mFlags & MATFLAG_PVW) {
			mShape->mMaterialList[mat.mIndex].Colour() = mat.Colour();

			for (int j = 0; j < 3; j++) {
				if (mat.mTevInfo->mTevColRegs[j].mAnimFrameCount) {
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

/**
 * @TODO: Documentation
 */
BaseShape::BaseShape()
{
	mName             = "noname";
	mAnimMatrices     = nullptr;
	mAnimMatrixId     = 0;
	mSystemFlags      = 0;
	mVertexCacheFlags = VertexCacheFlags::None;
	_2AC              = 1;
	mVtxMatrixCount   = 0;
	mVtxMatrixList    = nullptr;
	mMaterialCount    = 0;
	mMaterialList     = nullptr;
	mTevInfoCount     = 0;
	mTevInfoList      = nullptr;
	mMeshCount        = 0;
	mMeshList         = nullptr;

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

/**
 * @TODO: Documentation
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
				if (mat->mFlags & MATFLAG_PVW) {
					if (mat->mColourInfo.mTotalFrameCount) {
						check2 = true;
					}
					for (int j = 0; j < 3; j++) {
						if (mat->mTevInfo->mTevColRegs[j].mAnimFrameCount) {
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

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
ShapeDynMaterials* BaseShape::instanceMaterials(int p1)
{
	ShapeDynMaterials* dynMats = new ShapeDynMaterials();
	makeInstance(*dynMats, p1);
	return dynMats;
}

/**
 * @TODO: Documentation
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
		if (mat->mFlags & MATFLAG_PVW) {
			mat->mTevInfo = new PVWTevInfo();
			memcpy(mat->mTevInfo, mMaterialList[matUsed[i]].mTevInfo, sizeof(PVWTevInfo));
		}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 0000B4
 */
void recShowInfos(Graphics&, ObjCollInfo*)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000074
 */
void BaseShape::drawobjcolls(Graphics&, Camera&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00006C
 */
void BaseShape::drawlights(Graphics& gfx, Camera& cam)
{
	immut Matrix4f* activeMtx = gfx.mActiveMatrix;
	if (mLightGroup.Child()) {
		for (LightGroup* light = (LightGroup*)mLightGroup.Child(); light; light = (LightGroup*)light->mNext) {
			light->refresh(gfx, activeMtx);
		}
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00007C
 */
void BaseShape::drawroutes(Graphics& gfx, Camera& cam)
{
	for (RouteGroup* route = (RouteGroup*)mRouteGroup.mChild; route; route = (RouteGroup*)route->mNext) {
		gfx.useMatrix(cam.mLookAtMtx, 0);
		route->refresh(gfx, route);
	}
}

/**
 * @TODO: Documentation
 */
void BaseShape::drawculled(Graphics& gfx, Camera& cam, ShapeDynMaterials* dynMats)
{
	immut Matrix4f* mtx = gfx.mActiveMatrix;
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
			gfx.useTexture(nullptr, GX_TEXMAP0);
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

/**
 * @TODO: Documentation
 */
void BaseShape::drawshape(Graphics& gfx, Camera& cam, ShapeDynMaterials* dynMats)
{
	gsys->mTimer->start("drawShape", true);
	u32 prevRender = gfx.mRenderState;
	if (mMeshCount) {
		if (!(mSystemFlags & ShapeFlags::AlwaysRedraw) && (mSystemFlags & ShapeFlags::AllowCaching)
		    && (gfx.mRenderState & GFXRENDER_Unk3)) {
			gfx.cacheShape(this, dynMats);
			gfx.mRenderState &= ~GFXRENDER_Unk3;
		}

		if ((mSystemFlags & ShapeFlags::AlwaysRedraw) || (gfx.mRenderState & (GFXRENDER_Unk1 | GFXRENDER_Unk2 | GFXRENDER_Unk4))) {
			if (dynMats) {
				for (ShapeDynMaterials* iMat = dynMats; iMat; iMat = iMat->mParent) {
					iMat->updateContext();
				}
			}

			immut Matrix4f* activeMtx = gfx.mActiveMatrix;
			gfx.drawMeshes(cam, (Shape*)this);
			gfx.useMatrix(*activeMtx, 0);
			drawlights(gfx, cam);
			if (gsys->mToggleDebugInfo && (gfx.mRenderState & GFXRENDER_Unk3)) {
				gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
				drawroutes(gfx, cam);
			}
		}
	}

	gfx.mRenderState = prevRender;
	gsys->mTimer->stop("drawShape");
}

/**
 * @TODO: Documentation
 */
void BaseShape::resolveTextureNames()
{
	if (mTextureNameList) {
		for (int i = 0; i < mAttrListMatCount; i++) {
			const char* texName = mTextureNameList[i];
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000064
 */
void BaseShape::skipChunk(RandomAccessStream& stream, u32 amt)
{
	for (u32 i = 0; i < amt; i++) {
		stream.readByte();
	}
}

/**
 * @TODO: Documentation
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

/**
 * @TODO: Documentation
 */
void BaseShape::read(RandomAccessStream& stream)
{
	u32 chunkType;
	u32 before;
	u32 after;
	STACK_PAD_VAR(1);
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
			mVertexList = reinterpret_cast<Vector3f*>(new (0x20) Vec[mVertexCount]); // hmm.
			for (int i = 0; i < mVertexCount; i++) {
				mVertexList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexNormal: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mNormalCount = stream.readInt();
			stream.skipPadding(0x20);
			mNormalList = reinterpret_cast<Vector3f*>(new (0x20) Vec[mNormalCount]); // hmm
			for (int i = 0; i < mNormalCount; i++) {
				mNormalList[i].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexNBT: {
			before = gsys->getHeap(SYSHEAP_App)->getFree();

			mNBTCount = stream.readInt();
			stream.skipPadding(0x20);
			mNBTList = reinterpret_cast<NBT*>(new (0x20) Vec[3 * mNBTCount]);
			for (int i = 0; i < mNBTCount; i++) {
				reinterpret_cast<Vector3f*>(mNBTList)[3 * i].read(stream);
				reinterpret_cast<Vector3f*>(mNBTList)[3 * i + 1].read(stream);
				reinterpret_cast<Vector3f*>(mNBTList)[3 * i + 2].read(stream);
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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

			// Sorts materials in the following order:
			// 1. Alpha-blended materials (transparent, needs to be last).
			// 2. Alpha-test materials (cutout transparency).
			// 3. Opaque materials (no transparency, needs to be first).
			// This is to handle transparency correctly without per-frame depth sorting.
			recAddMatpoly(mJointList, 4); // MATFLAG_ALPHA_BLEND
			recAddMatpoly(mJointList, 2); // MATFLAG_ALPHA_TEST
			recAddMatpoly(mJointList, 1); // MATFLAG_OPAQUE

			for (int i = 0; i < mTotalMatpolyCount; i++) {
				mMatpolyList[i]->mJointList = mMatpolyList[i]->mMesh->mJointList;
			}

			after = gsys->getHeap(SYSHEAP_App)->getFree();
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
			((before - after) / 1024.0f); // The DLL does nothing here but this is clearly resembles a stripped KB print
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
	STACK_PAD_TERNARY(chunkType, 11);
}

/**
 * @TODO: Documentation
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
				STACK_PAD_VAR(1);
				if (light->mMatSource[i] == ':') {
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
#ifdef WIN32
		route->mDebugWaypointTexture            = gsys->loadTexture("rootRing.txe", true);
		route->mDebugWaypointTexture->mTexFlags = (0x100 | 0x1);
#else
		route->mDebugWaypointTexture = nullptr;
#endif
	}
}

/**
 * @TODO: Documentation
 */
void BaseShape::initialise()
{
	STACK_PAD_VAR(1);
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

	for (int i = 0, unused = 0; i < mMaterialCount; i++, unused++) {
		if (mMaterialList[i].mFlags & MATFLAG_PVW) {
			for (int j = 0; j < (int)mMaterialList[i].mTextureInfo.mTextureDataCount; j++) {
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
		!!unused;
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

/**
 * @TODO: Documentation
 */
void BaseShape::createCollisions(int gridSize)
{
	// the DLL version has a whole section at the top doing vector nonsense which sort of got stripped?
	// clearly still has some stack things remaining
	STACK_PAD_VAR(768);

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

/**
 * @TODO: Documentation
 */
void BaseShape::calcBasePose(immut Matrix4f& target)
{
	for (int i = 0; i < mJointCount; i++) {
		SRT srt;
		srt.s = mJointList[i].mSRT.s;
		srt.r = mJointList[i].mSRT.r;
		srt.t = mJointList[i].mSRT.t;

		int parentIndex = mJointList[i].mParentIndex;
		Matrix4f initialPose;
		immut Matrix4f* currentMatrix = parentIndex == -1 ? &target : &mJointList[parentIndex].mAnimMatrix;
		mJointList[i].mAnimMatrix.makeConcatSRT(currentMatrix, initialPose, srt);
		mJointList[i].mAnimMatrix.inverse(&mJointList[i].mInverseAnimMatrix);
	}
}

/**
 * @TODO: Documentation
 */
AnimData* BaseShape::loadDck(immut char* name, RandomAccessStream& s)
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

/**
 * @TODO: Documentation
 */
AnimData* BaseShape::importDck(immut char* name, CmdStream* cmds)
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

/**
 * @TODO: Documentation
 */
AnimData* BaseShape::loadDca(immut char* name, RandomAccessStream& s)
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

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000138
 */
void BaseShape::importDca(immut char* name, CmdStream* cmds)
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

/**
 * @TODO: Documentation
 */
AnimData* BaseShape::loadAnimation(immut char* name, bool isRelativePath)
{
	RandomAccessStream* stream = gsys->openFile(name, isRelativePath, true);
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

/**
 * @TODO: Documentation
 */
Matrix4f& BaseShape::getAnimMatrix(int i)
{
	return mAnimMatrices[i];
}

/**
 * @TODO: Documentation
 */
void BaseShape::backupAnimOverrides(AnimContext** animList)
{
	mBackupAnimOverrides = animList;
	for (int i = 0; i < mJointCount; i++) {
		mBackupAnimOverrides[i] = mAnimOverrides[i];
	}
}

/**
 * @TODO: Documentation
 */
void BaseShape::restoreAnimOverrides()
{
	for (int i = 0; i < mJointCount; i++) {
		mAnimOverrides[i] = mBackupAnimOverrides[i];
	}
}

/**
 * @TODO: Documentation
 */
void BaseShape::overrideAnim(int jointIdx, AnimContext* anim)
{
	Joint* joint = &mJointList[jointIdx];
	joint->overrideAnim(anim);
	if (joint->mChild) {
		((Joint*)joint->mChild)->recOverrideAnim(anim);
	}
}

/**
 * @TODO: Documentation
 */
AnimFrameCacher::AnimFrameCacher(int num)
{
	mCache      = new AyuCache(num * 64);
	mInfo.mName = "root";
	mInfo.mNext = mInfo.mPrev = &mInfo;
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 00004C
 */
void AnimFrameCacher::updateInfo(AnimCacheInfo* info)
{
	if (mInfo.mNext != info->mCachedMtxBlock) {
		info->mCachedMtxBlock->remove();
		mInfo.insertAfter(info->mCachedMtxBlock);
	}
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000050
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

/**
 * @TODO: Documentation
 */
void AnimFrameCacher::cacheFrameSpace(int p1, AnimCacheInfo* info)
{
	u32 texSize = OSRoundDown32B(59 + 4 * p1 + 64 * p1);

	while (true) {
		if (mCache->largestBlockFree() > texSize) {
			FrameCacher* alloc      = (FrameCacher*)mCache->mallocL(texSize);
			alloc->mBoneMtxList     = &alloc->mBoneMatrices[0];
			alloc->mBoneMatricesEnd = &alloc->mBoneMatrices[p1];
			alloc->mInfo            = &info->mCachedMtxBlock;

			for (int i = 0; i < p1; i++) {
				alloc->mBoneMtxList[i] = 0;
			}

			info->mCachedMtxBlock = alloc;
			mInfo.insertAfter(alloc);
			break;
		}

		removeOldest();
	}
}

/**
 * @TODO: Documentation
 */
void BaseShape::updateAnim(Graphics& gfx, immut Matrix4f& mtx, f32* p3)
{
	gsys->mTimer->start("updateAnim", true);
	gsys->mAnimatedPolygons++;
	mAnimMatrices = gfx.getMatrices(mAnimMatrixId);

	if (mCurrentAnimation->mData) {
		if (!p3) {
			mCurrentAnimation->animate(mCurrentAnimation->mAnimSpeed);
		}

		for (int i = 0; i < mJointCount; i++) {
			AnimData* data = mAnimOverrides[i]->mData;
			if (!data) {
				ERROR("no joint anim!!\n");
			}
			f32* frame = (p3) ? p3 : &mAnimOverrides[i]->mCurrentFrame;

			if (mFrameCacher && data->mAnimFlags & ANIMFLAG_UseCache) {
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
				immut Matrix4f& srt = (mJointList[i].mParentIndex != -1) ? mAnimMatrices[mJointList[i].mParentIndex] : mtx;

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
			srt.s = joint->mSRT.s;
			srt.r = joint->mSRT.r;
			srt.t = joint->mSRT.t;
			Matrix4f tmpMtx;
			immut Matrix4f* jointMtx = (joint->mParentIndex == -1) ? &mtx : &mJointList[joint->mParentIndex].mAnimMatrix;
			joint->mAnimMatrix.makeConcatSRT(jointMtx, tmpMtx, srt);
			joint++;
		}
	}

	gsys->mTimer->stop("updateAnim");
}

/**
 * @TODO: Documentation
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

			register immut Matrix4f& mtx1 = weighted;
			register Matrix4f& mtx2       = mAnimMatrices[mJointCount + i];

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

/**
 * @TODO: Documentation
 */
void BaseShape::makeNormalIndexes(u16* indices)
{
	for (int i = 0; i < mTotalMatpolyCount; i++) {
		Mesh* mesh = &mMeshList[mMatpolyList[i]->mMeshIndex];

		for (int j = 0; j < mesh->mMtxGroupCount; j++) {
			MtxGroup* group    = &mesh->mMtxGroupList[j];
			DispList* dispList = group->mDispList;
			for (int k = 0; k < group->mDispLength; k++) {
				u8* data    = dispList->mData;
				u32 dataLen = dispList->mDataLength;

				while (dataLen && data < dispList->mData + dataLen) {
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

/**
 * @TODO: Documentation
 */
f32 BaseShape::calcJointWorldPos(Graphics& gfx, int index, Vector3f& worldPos)
{
	if (index == -1) {
		return 0.0f;
	}

	immut Matrix4f& orig = getAnimMatrix(index);
	worldPos.multMatrix(getAnimMatrix(index));
	worldPos.multMatrix(gfx.mCamera->mInverseLookAtMtx);
	return reinterpret_cast<immut Vector3f*>(&orig)->length();
}

/**
 * @TODO: Documentation
 */
void BaseShape::calcJointWorldDir(Graphics& gfx, int index, Vector3f& worldDir)
{
	if (index == -1) {
		return;
	}

	getAnimMatrix(index);
	immut Matrix4f& animMtx = getAnimMatrix(index);
	worldDir.rotate(animMtx);
	worldDir.rotate(gfx.mCamera->mInverseLookAtMtx);
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000084
 */
void BaseShape::calcJointWorldScale(Graphics&, int, Vector3f&)
{
	// UNUSED FUNCTION
}

/**
 * @TODO: Documentation
 * @note UNUSED Size: 000148
 */
CollTriInfo* BaseShape::findCollTri(Vector3f&, Vector3f&, Vector3f&, char*)
{
	// UNUSED FUNCTION
}

#ifdef DEVELOP

// TODO: UNCOMMENT THIS ONCE FILE IS LINKED

// void BaseShape::removeMtxDependancy()
//{
//	for (int i = 0; i < mMeshCount; i++) {
//		Mesh* mesh = &mMeshList[i];
//		for (int j = 0; j < mesh->mMtxGroupCount; j++) {
//			mesh->mMtxGroupList[j].mDepLength = 0;
//		}
//	}
//}

#endif
