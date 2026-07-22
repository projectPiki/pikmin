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
#include <stddef.h>

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(23)

/**
 * @todo: Documentation
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
	s32* arr      = new s32[2 * mIndexCount];
	mJointIndices = arr;

	// Point weights to after indices in that block
	mWeights = &reinterpret_cast<f32*>(arr)[mIndexCount];

	for (int weightIdx = 0; weightIdx < mIndexCount; weightIdx++) {
		mJointIndices[weightIdx] = stream.readShort();
		mWeights[weightIdx]      = stream.readFloat();
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
		for (int depIdx = 0; depIdx < mDepLength; depIdx++) {
			mDepList[depIdx] = stream.readShort();
		}
	}

	mDispLength = stream.readInt();
	if (mDispLength) {
		mDispList = new DispList[mDispLength];
		for (int dispIdx = 0; dispIdx < mDispLength; dispIdx++) {
			mDispList[dispIdx].read(stream);
#if defined(WIN32)
			DlobjInfo* info = new DlobjInfo();
			info->mDispList = &mDispList[dispIdx];
			gsys->addGfxObject(info);
#endif
		}
	}
}

/**
 * @todo: Documentation
 */
void Mesh::read(RandomAccessStream& stream)
{
	mParentJoint   = stream.readInt();
	mFeatureFlags  = stream.readInt();
	mMtxGroupCount = stream.readInt();

	if (mMtxGroupCount) {
		mMtxGroupList = new MtxGroup[mMtxGroupCount];
		mMtxDepIdx    = 0;
		for (int mtxGroupIdx = 0; mtxGroupIdx < mMtxGroupCount; mtxGroupIdx++) {
			mMtxGroupList[mtxGroupIdx].read(stream);

			if (mMtxGroupList[mtxGroupIdx].mDepLength > mMtxDepIdx) {
				mMtxDepIdx = mMtxGroupList[mtxGroupIdx].mDepLength;
			}
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C
 */
void Joint::recShowHierarchy()
{
	FOREACH_NODE(Joint, this, joint)
	{
		PRINT("got joint %08x\n", joint);

		if (joint->mChild) {
			Joint* child = static_cast<Joint*>(joint->mChild);
			child->recShowHierarchy();
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000018
 */
void Joint::overrideAnim(AnimContext* anim)
{
	mParentShape->mAnimOverrides[mIndex] = anim;
}

/**
 * @todo: Documentation
 */
void Joint::recOverrideAnim(AnimContext* anim)
{
	FOREACH_NODE(Joint, this, joint)
	{
		joint->overrideAnim(anim);

		if (joint->mChild) {
			Joint* child = static_cast<Joint*>(joint->mChild);
			child->recOverrideAnim(anim);
		}
	}
}

/**
 * @todo: Documentation
 */
void Joint::read(RandomAccessStream& stream)
{
	mParentIndex = stream.readInt();

	u16 flags      = stream.readInt();
	mUseVolume     = (flags & 0x0001) != 0;
	mUseLightGroup = (flags & 0x4000) != 0;

	// x86 regswap happens here.
	mBounds.mMin.read(stream);
	mBounds.mMax.read(stream);
	float unusedBoundPadding = stream.readFloat();

	mScale.read(stream);
	mRotation.read(stream);
	mTranslation.read(stream);

	mMatPolyCount = stream.readInt();
	mMatPoly.initCore("");
	for (int matPolyCount = 0; matPolyCount < mMatPolyCount; matPolyCount++) {
		MatPoly* mPoly    = new MatPoly();
		mPoly->mIndex     = stream.readShort();
		mPoly->mMeshIndex = stream.readShort();
		mMatPoly.add(mPoly);
	}
}

#if defined(WIN32)

/**
 * @todo: Documentation
 */
void Joint::write(RandomAccessStream& stream)
{
	stream.writeInt(mParentIndex);

	u32 flags = mUseVolume ? 0x0001 : 0;
	flags |= mUseLightGroup ? 0x4000 : 0;
	stream.writeInt(flags);

	mBounds.mMin.write(stream);
	mBounds.mMax.write(stream);
	stream.writeFloat(0.0f);

	mScale.write(stream);
	mRotation.write(stream);
	mTranslation.write(stream);

	stream.writeInt(mMatPolyCount);
	int matPolyCount = 0;
	FOREACH_NODE(MatPoly, mMatPoly.mChild, matPoly)
	{
		stream.writeShort(matPoly->mIndex);
		stream.writeShort(matPoly->mMeshIndex);
		++matPolyCount;
	}
}

#endif

/**
 * @todo: Documentation
 * @note UNUSED Size: 00043C (Matching by size)
 */
void Joint::render(Graphics& gfx)
{
	// This is definitely a mistake (logical NOT + bitwise AND), however it does not matter in practice.  Interestingly,
	// this same mistake also happened in `DGXGraphics::drawSingleMatpoly`.  Most cursed, however, is that an additional
	// `and  ecx, 0xff` instruction spawns if I don't cast `Joint::VisibilityFlags::Visible` to an integer.
	if (!mVisibilityFlag & static_cast<int>(Visible)) {
		return;
	}

	// Optionally draw joint bounding box
	if (false) {
		BoundBox& bbox = mBounds;

		bool oldLighting = gfx.setLighting(false, nullptr);
		Matrix4f viewMtx;
		gfx.calcViewMatrix(mParentShape->getAnimMatrix(mIndex), viewMtx);
		gfx.useMatrix(viewMtx, 0);
		gfx.setColour(Colour(64, 64, 255, 128), true);

		gfx.drawLine(Vector3f(bbox.mMin.x, bbox.mMin.y, bbox.mMin.z), Vector3f(bbox.mMax.x, bbox.mMin.y, bbox.mMin.z));
		gfx.drawLine(Vector3f(bbox.mMax.x, bbox.mMin.y, bbox.mMin.z), Vector3f(bbox.mMax.x, bbox.mMin.y, bbox.mMax.z));
		gfx.drawLine(Vector3f(bbox.mMax.x, bbox.mMin.y, bbox.mMax.z), Vector3f(bbox.mMin.x, bbox.mMin.y, bbox.mMax.z));
		gfx.drawLine(Vector3f(bbox.mMin.x, bbox.mMin.y, bbox.mMax.z), Vector3f(bbox.mMin.x, bbox.mMin.y, bbox.mMin.z));
		gfx.drawLine(Vector3f(bbox.mMin.x, bbox.mMax.y, bbox.mMin.z), Vector3f(bbox.mMax.x, bbox.mMax.y, bbox.mMin.z));
		gfx.drawLine(Vector3f(bbox.mMax.x, bbox.mMax.y, bbox.mMin.z), Vector3f(bbox.mMax.x, bbox.mMax.y, bbox.mMax.z));
		gfx.drawLine(Vector3f(bbox.mMax.x, bbox.mMax.y, bbox.mMax.z), Vector3f(bbox.mMin.x, bbox.mMax.y, bbox.mMax.z));
		gfx.drawLine(Vector3f(bbox.mMin.x, bbox.mMax.y, bbox.mMax.z), Vector3f(bbox.mMin.x, bbox.mMax.y, bbox.mMin.z));
		gfx.drawLine(Vector3f(bbox.mMin.x, bbox.mMin.y, bbox.mMin.z), Vector3f(bbox.mMin.x, bbox.mMax.y, bbox.mMin.z));
		gfx.drawLine(Vector3f(bbox.mMax.x, bbox.mMin.y, bbox.mMin.z), Vector3f(bbox.mMax.x, bbox.mMax.y, bbox.mMin.z));
		gfx.drawLine(Vector3f(bbox.mMin.x, bbox.mMin.y, bbox.mMax.z), Vector3f(bbox.mMin.x, bbox.mMax.y, bbox.mMax.z));
		gfx.drawLine(Vector3f(bbox.mMax.x, bbox.mMin.y, bbox.mMax.z), Vector3f(bbox.mMax.x, bbox.mMax.y, bbox.mMax.z));

		gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
		gfx.setLighting(oldLighting, nullptr);
	}

	immut Matrix4f* animMatrices[10];
	int matPolyCount = 0; // Counted but never used.

	FOREACH_NODE(MatPoly, mMatPoly.mChild, matPoly)
	{
		Mesh* mesh = matPoly->mMesh;
		++matPolyCount;

		if (!(matPoly->mMaterial->mFlags & gfx.mMatRenderMask)) {
			continue;
		}
		gfx.useMaterial(matPoly->mMaterial);

		for (int mtxGroupIdx = 0; mtxGroupIdx < mesh->mMtxGroupCount; ++mtxGroupIdx) {

			MtxGroup* mtxGroup = &mesh->mMtxGroupList[mtxGroupIdx];

			if (mtxGroup->mDepLength == 0) {
				animMatrices[0] = &Matrix4f::ident;
			}
			for (int depListIdx = 0; depListIdx < mtxGroup->mDepLength; ++depListIdx) {

				int depIndex = mtxGroup->mDepList[depListIdx];

				if (depIndex != -1) {

					VtxMatrix* vtxMatrix = &mParentShape->mVtxMatrixList[depIndex];

					if (mParentShape->mCurrentAnimation->mData) {
						if (vtxMatrix->mHasPartialWeights) {
							animMatrices[depListIdx] = &mParentShape->getAnimMatrix(vtxMatrix->mIndex);
						} else {
							animMatrices[depListIdx] = &mParentShape->getAnimMatrix(mParentShape->mJointCount + vtxMatrix->mIndex);
						}
					} else {
						animMatrices[depListIdx] = &mParentShape->mJointList[vtxMatrix->mIndex].mAnimMatrix;
					}
				}
			}

			Vector3f* shapeVertices  = mParentShape->mVertexList;
			Vector2f* shapeTexCoords = mParentShape->mTexCoordList[0];
			Vector3f* shapeNormals   = (mesh->mFeatureFlags & Mesh::FeatureFlags::VtxNBT)
			                             ? reinterpret_cast<Vector3f*>(mParentShape->mNBTList)
			                             : mParentShape->mNormalList;
			int normalStride         = (mesh->mFeatureFlags & Mesh::FeatureFlags::VtxNBT) ? sizeof(NBT) / sizeof(Vector3f) : 1;
			DispList* currDispList   = mtxGroup->mDispList;

			for (int dispListCount = 0; dispListCount < mtxGroup->mDispLength; ++dispListCount) {
				int oldCullFront = gfx.setCullFront((currDispList->mFlags & 3) ^ gfx.mCullFlip); // Never restored

				FOREACH_NODE(FaceNode, currDispList->mFaceNode.mChild, faceNode)
				{
					Vector3f* drawVerts = fnVerts;
					Vector3f* drawNorms = fnNorms;
					Vector2f* drawTexs  = fnTexs; // This goes unused despite being populated

					int* vertexIndices   = faceNode->mVtxIdx;
					int* matrixIndices   = faceNode->mMtxIdx;
					int* normalIndices   = faceNode->mNrmIdx;
					int* texCoordIndices = faceNode->mTexCoords[0];

					if (faceNode->mFaceCount > 0x200 - 1) {
						TERNARY_BUGFIX(ERROR, PRINT)("too many vertices!!\n");
					}

					for (int faceCount = 0; faceCount < faceNode->mFaceCount; ++faceCount) {
						if (matrixIndices) {
							shapeVertices[*vertexIndices++].multMatrixTo(*animMatrices[*matrixIndices], *drawVerts++);
							if (normalIndices) {
								shapeNormals[*normalIndices++ * normalStride].rotateTo(*animMatrices[*matrixIndices], *drawNorms++);
							}
							++matrixIndices;
						} else {
							shapeVertices[*vertexIndices++].multMatrixTo(*animMatrices[0], *drawVerts++);
							if (normalIndices) {
								shapeNormals[*normalIndices++ * normalStride].rotateTo(*animMatrices[0], *drawNorms++);
							}
						}
						if (texCoordIndices) {
							*drawTexs++ = shapeTexCoords[*texCoordIndices++];
						}
					}
					if (currDispList->mFlags & 0x1000000 /* Has triangle strip? */) {
						gfx.drawOneStrip(fnVerts, faceNode->mNrmIdx ? fnNorms : nullptr, faceNode->mTexCoords[0] ? fnTexs : nullptr,
						                 faceNode->mFaceCount);
					} else {
						gfx.drawOneTri(fnVerts, faceNode->mNrmIdx ? fnNorms : nullptr, faceNode->mTexCoords[0] ? fnTexs : nullptr,
						               faceNode->mFaceCount);
					}
				}
				++currDispList;
			}
		}
	}

	gfx.useMaterial(nullptr);
}

/**
 * @todo: Documentation
 */
void AnimContext::animate(f32 animSpeed)
{
	mCurrentFrame += gsys->getFrameTime() * animSpeed;

	if (static_cast<int>(mCurrentFrame) >= mData->mTotalFrameCount) {
		mCurrentFrame = 0.0f;
	}
}

/**
 * @todo: Documentation
 */
static f32 extract(f32 currTime, AnimParam& param, DataChunk& data)
{
	int dataSize  = (param.mFlags == 0) ? 3 : 4;
	bool isActive = false;
	int offset    = param.mDataOffset;

	// Early return if current time is not active within any data range
	for (int rangeIdx = 0; rangeIdx < param.mEntryNum - 1; ++rangeIdx) {
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
 * @todo: Documentation
 */
CamDataInfo::CamDataInfo()
{
	mCamera.mNear        = 1.0f;
	mCamera.mFar         = 15000.0f;
	mCamera.mAspectRatio = 640.0f / 480.0f;
	mUseStaticCamera     = false;
};

/**
 * @todo: Documentation
 */
void CamDataInfo::update(f32 currentFrame, immut Matrix4f& mtx)
{
	f32 cameraTwist[1];
	f32 cameraFovy[1];

	f32(&camPosXYZ)[3]         = reinterpret_cast<f32(&)[3]>(mCamera.mPosition);
	AnimParam(&camPosAnims)[3] = mCamPosAnims;

	for (int camPosIdx = 0; camPosIdx < 3; camPosIdx++) {
		AnimParam& thisParam = camPosAnims[camPosIdx];
		switch (thisParam.mEntryNum) {
		case 0:
		{
			camPosXYZ[camPosIdx] = 0.0f;
			break;
		}
		case 1:
		{
			camPosXYZ[camPosIdx] = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		}
		default:
		{
			camPosXYZ[camPosIdx] = extract(currentFrame, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
		}
	}

	f32(&camFocusXYZ)[3]       = reinterpret_cast<f32(&)[3]>(mCamera.mFocus);
	AnimParam(&camLatAnims)[3] = mCamLatAnims;

	for (int camLatIdx = 0; camLatIdx < 3; camLatIdx++) {
		AnimParam& thisParam = camLatAnims[camLatIdx];
		switch (thisParam.mEntryNum) {
		case 0:
		{
			camFocusXYZ[camLatIdx] = 0.0f;
			break;
		}
		case 1:
		{
			camFocusXYZ[camLatIdx] = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		}
		default:
		{
			camFocusXYZ[camLatIdx] = extract(currentFrame, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
		}
	}

	f32(&camTwistVals)[1]        = cameraTwist;
	AnimParam(&camTwistAnims)[1] = mCamTwistAnims;

	for (int camTwistIdx = 0; camTwistIdx < 1; camTwistIdx++) {
		AnimParam& thisParam = camTwistAnims[camTwistIdx];
		switch (thisParam.mEntryNum) {
		case 0:
		{
			camTwistVals[camTwistIdx] = 1.0f;
			break;
		}
		case 1:
		{
			camTwistVals[camTwistIdx] = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		}
		default:
		{
			camTwistVals[camTwistIdx] = extract(currentFrame, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
		}
	}

	f32(&camFovyVals)[1]        = cameraFovy;
	AnimParam(&camFovyAnims)[1] = mCamFovyAnims;

	for (int camFovyIdx = 0; camFovyIdx < 1; camFovyIdx++) {
		AnimParam& thisParam = camFovyAnims[camFovyIdx];
		switch (thisParam.mEntryNum) {
		case 0:
		{
			camFovyVals[camFovyIdx] = 1.0f;
			break;
		}
		case 1:
		{
			camFovyVals[camFovyIdx] = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		}
		default:
		{
			camFovyVals[camFovyIdx] = extract(currentFrame, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
		}
	}

	mCamera.mPosition.multMatrix(mtx);
	mCamera.mFocus.multMatrix(mtx);
	mCamera.mFov = cameraFovy[0];

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
}

/**
 * @todo: Documentation
 */
void LightDataInfo::update(f32 currentFrame)
{
	Vector3f lightPosition;
	Vector3f lightColour;
	f32 lightVisible[1];

	f32(&lightPosXYZ)[3]         = reinterpret_cast<f32(&)[3]>(lightPosition);
	AnimParam(&lightPosAnims)[3] = mLightPosAnims;

	for (int lightPosIdx = 0; lightPosIdx < 3; lightPosIdx++) {
		AnimParam& thisParam = lightPosAnims[lightPosIdx];
		switch (thisParam.mEntryNum) {
		case 0:
		{
			lightPosXYZ[lightPosIdx] = 1.0f;
			break;
		}
		case 1:
		{
			lightPosXYZ[lightPosIdx] = mSceneData->mLightAnimations->mData[thisParam.mDataOffset];
			break;
		}
		default:
		{
			lightPosXYZ[lightPosIdx] = extract(currentFrame, thisParam, *mSceneData->mLightAnimations);
			break;
		}
		}
	}

	f32(&lightColourRGB)[3]         = reinterpret_cast<f32(&)[3]>(lightColour);
	AnimParam(&lightColourAnims)[3] = mLightColourAnims;

	for (int lightColourIdx = 0; lightColourIdx < 3; lightColourIdx++) {
		AnimParam& thisParam = lightColourAnims[lightColourIdx];
		switch (thisParam.mEntryNum) {
		case 0:
		{
			lightColourRGB[lightColourIdx] = 1.0f;
			break;
		}
		case 1:
		{
			lightColourRGB[lightColourIdx] = mSceneData->mLightAnimations->mData[thisParam.mDataOffset];
			break;
		}
		default:
		{
			lightColourRGB[lightColourIdx] = extract(currentFrame, thisParam, *mSceneData->mLightAnimations);
			break;
		}
		}
	}

	f32(&lightVisibleVals)[1]        = lightVisible;
	AnimParam(&lightVisibleAnims)[1] = mLightVisibleAnims;

	for (int lightVisibleIdx = 0; lightVisibleIdx < 1; lightVisibleIdx++) {
		AnimParam& thisParam = lightVisibleAnims[lightVisibleIdx];
		switch (thisParam.mEntryNum) {
		case 0:
		{
			lightVisibleVals[lightVisibleIdx] = 1.0f;
			break;
		}
		case 1:
		{
			lightVisibleVals[lightVisibleIdx] = mSceneData->mLightAnimations->mData[thisParam.mDataOffset];
			break;
		}
		default:
		{
			lightVisibleVals[lightVisibleIdx] = extract(currentFrame, thisParam, *mSceneData->mLightAnimations);
			break;
		}
		}
	}

	mIsActive = lightVisible[0] == 1.0f;

	if (mIsActive) {
		mLight.mDiffuseColour.set(lightColour.x, lightColour.y, lightColour.z, 255);
		mLight.mPosition.set(lightPosition.x, lightPosition.y, lightPosition.z);
		mLight.mDistancedRange = 1000.0f;
		mLight.update();
	}
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void SceneData::getAnimInfo(CmdStream* stream)
{
	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);

		if (stream->isToken("numcameras")) {
			sscanf(stream->getToken(true), "%d", &mNumCameras);
			mCameraData = new CamDataInfo[mNumCameras];

			for (int cameraIdx = 0; cameraIdx < mNumCameras; cameraIdx++) {
				mCameraData[cameraIdx].mSceneData = this;
				mCameraData[cameraIdx].mCameraIdx = cameraIdx;
			}

		} else if (stream->isToken("numDifLights")) {
			sscanf(stream->getToken(true), "%d", &mNumLights);
			mLightData = new LightDataInfo[mNumLights];

			for (int lightIdx = 0; lightIdx < mNumLights; lightIdx++) {
				mLightData[lightIdx].mSceneData = this;
				mLightData[lightIdx].mLightIdx  = lightIdx;
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
 * @todo: Documentation
 */
void AnimData::extractSRT(SRT& srt, int, AnimDataInfo* info, f32 time)
{
	if (!(info->mFlags & AnimDataFlags::MatrixCalculated)) {

		if (!(info->mFlags & AnimDataFlags::AllScaleStatic)) {

			// Can't make this a reference of f32[3] because what is done below.
			f32* scale = reinterpret_cast<f32*>(&srt.s);

			for (int axisIdx = 0; axisIdx < 3; axisIdx++) {
				AnimParam& param = info->mScale[axisIdx];

				int offset = (int(time) < param.mEntryNum) ? param.mDataOffset + int(time) : param.mDataOffset + (param.mEntryNum - 1);
				*scale++   = mScaleDataBlock->mData[offset]; // YOU HAVE THE LOOP VARIABLE.  WHY?
			}

			if ((info->mFlags & AnimDataFlags::AllIndividualScaleStatic) == AnimDataFlags::AllIndividualScaleStatic) {
				info->mFlags |= AnimDataFlags::AllScaleStatic;
			}
		}

		if (!(info->mFlags & AnimDataFlags::AllRotationStatic)) {

			// Can't make this a reference of f32[3] because what is done below.
			f32* rotation = reinterpret_cast<f32*>(&srt.r);

			for (int axisIdx = 0; axisIdx < 3; axisIdx++) {
				AnimParam& param = info->mRotation[axisIdx];

				int offset  = (int(time) < param.mEntryNum) ? param.mDataOffset + int(time) : param.mDataOffset + (param.mEntryNum - 1);
				*rotation++ = mRotateDataBlock->mData[offset]; // YOU HAVE THE LOOP VARIABLE.  WHY?
			}

			if ((info->mFlags & AnimDataFlags::AllIndividualRotationStatic) == AnimDataFlags::AllIndividualRotationStatic) {
				info->mFlags |= AnimDataFlags::AllRotationStatic;
			}
		}

		if (!(info->mFlags & AnimDataFlags::AllTranslationStatic)) {

			// Can't make this a reference of f32[3] because what is done below.
			f32* translation = reinterpret_cast<f32*>(&srt.t);

			for (int axisIdx = 0; axisIdx < 3; axisIdx++) {
				AnimParam& param = info->mTranslation[axisIdx];

				int offset     = (int(time) < param.mEntryNum) ? param.mDataOffset + int(time) : param.mDataOffset + (param.mEntryNum - 1);
				*translation++ = mTranslationDataBlock->mData[offset]; // YOU HAVE THE LOOP VARIABLE.  WHY?
			}

			if ((info->mFlags & AnimDataFlags::AllIndividualTranslationStatic) == AnimDataFlags::AllIndividualTranslationStatic) {
				info->mFlags |= AnimDataFlags::AllTranslationStatic;
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void AnimData::makeAnimSRT(int boneId, immut Matrix4f* parent, Matrix4f* output, AnimDataInfo* info, f32 pos)
{
	int frameNum = pos;
	if (frameNum < 0 || frameNum >= mTotalFrameCount) {
		ERROR("makeSRT too large a frame number : %d / %d : %f\n", frameNum, mTotalFrameCount, pos);
	}

	Matrix4f mtx;
	Matrix4f* boneTransform;

	bool check = true;
	if ((info->mFlags & AnimDataFlags::AllComponentsStatic) != AnimDataFlags::AllComponentsStatic
	    && mAnimInfoList[frameNum].mCachedMtxBlock) {
		AnimCacheInfo* cache = static_cast<AnimCacheInfo*>(mAnimInfoList[frameNum].mCachedMtxBlock);
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
		extractSRT(srt, boneId, info, pos);
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

#if defined(WIN32)
	parent->multiplyTo(*boneTransform, *output);
#else
	MTXConcat(parent->mMtx, boneTransform->mMtx, output->mMtx);
#endif
}

/**
 * @todo: Documentation
 */
void AnimData::detach()
{
	for (int frameIdx = 0; frameIdx < mTotalFrameCount; frameIdx++) {
		mAnimInfoList[frameIdx].initData();
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00005C
 */
void AnimData::initData()
{
	mAnimInfoList = new AnimCacheInfo[mTotalFrameCount];
}

/**
 * @todo: Documentation
 */
void AnimData::checkMask()
{
	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		mAnimInfo[jointIdx].mFlags = 0;

		int bit = 0;
		int axisIdx;

		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			if (mAnimInfo[jointIdx].mScale[axisIdx].mEntryNum == 1) {
				mAnimInfo[jointIdx].mFlags |= (1 << bit);
			}
			bit++;
		}
		bit++;

		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			if (mAnimInfo[jointIdx].mRotation[axisIdx].mEntryNum == 1) {
				mAnimInfo[jointIdx].mFlags |= (1 << bit);
			}
			bit++;
		}
		bit++;

		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			if (mAnimInfo[jointIdx].mTranslation[axisIdx].mEntryNum == 1) {
				mAnimInfo[jointIdx].mFlags |= (1 << bit);
			}
			bit++;
		}
		bit++;
	}

	mAnimJointIndices    = new u16[mJointCount];
	int animJointCount   = 0;
	int staticJointCount = 0;

	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		if (jointIdx < mModel->mJointCount) {
			if ((mAnimInfo[jointIdx].mFlags & AnimDataFlags::AllComponentsStatic) != AnimDataFlags::AllComponentsStatic) {
				mAnimJointIndices[jointIdx] = animJointCount++;
			} else {
				mAnimJointIndices[jointIdx] = 0;
				staticJointCount++;
			}
		}
	}

	mActiveJointCount = mJointCount - staticJointCount;
}

/**
 * @todo: Documentation
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

	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		mAnimInfo[jointIdx].mGroupIndex = input.readInt();

		int parentIndex                 = input.readInt();
		mAnimInfo[jointIdx].mParentInfo = parentIndex == -1 ? 0 : &mAnimInfo[parentIndex];

		// Read scale parameters (3 entries for x, y, and z)
		int axisIdx;
		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			AnimParam* scaleParam   = &mAnimInfo[jointIdx].mScale[axisIdx];
			scaleParam->mEntryNum   = input.readInt();
			scaleParam->mDataOffset = input.readInt();
		}

		// Read rotation parameters (3 entries for x, y, and z)
		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			AnimParam* rotationParam   = &mAnimInfo[jointIdx].mRotation[axisIdx];
			rotationParam->mEntryNum   = input.readInt();
			rotationParam->mDataOffset = input.readInt();
		}

		// Read translation parameters (3 entries for x, y, and z)
		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			AnimParam* translationParam   = &mAnimInfo[jointIdx].mTranslation[axisIdx];
			translationParam->mEntryNum   = input.readInt();
			translationParam->mDataOffset = input.readInt();
		}
	}

	checkMask();
	initData();
}

/**
 * @todo: Documentation
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
			for (int rotateValueIdx = 0; rotateValueIdx < mRotateDataBlock->mDataIndex; rotateValueIdx++) {
				// convert degrees to radians
				mRotateDataBlock->mData[rotateValueIdx] = mRotateDataBlock->mData[rotateValueIdx] * PI / 180.0f;
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
					mAnimInfo[index].mParentInfo = (parentIdx == -1) ? nullptr : &mAnimInfo[parentIdx];

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
 * @todo: Documentation
 */
void AnimDca::getAnimInfo(CmdStream* stream)
{
	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);

		if (stream->isToken("numjoints")) {
			sscanf(stream->getToken(true), "%d", &mJointCount);
			mAnimInfo = new AnimDataInfo[mJointCount];

			for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
				mAnimInfo[jointIdx].mGroupIndex = jointIdx;
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
 * @todo: Documentation
 */
AnimDck::AnimDck(BaseShape* model, int joints)
{
	mModel           = model;
	mJointCount      = joints;
	mTotalFrameCount = 0;
	mAnimInfo        = new AnimDataInfo[mJointCount];

	for (int jointIdx = 0; jointIdx < joints; jointIdx++) {
		mAnimInfo[jointIdx].mParentInfo
		    = (model->mJointList[jointIdx].mParentIndex == -1) ? nullptr : &mAnimInfo[model->mJointList[jointIdx].mParentIndex];
	}
}

/**
 * @todo: Documentation
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
	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		mAnimInfo[jointIdx].mGroupIndex = stream.readInt();

		int parentIndex                 = stream.readInt();
		mAnimInfo[jointIdx].mParentInfo = parentIndex == -1 ? 0 : &mAnimInfo[parentIndex];

		// Read scale parameters (3 entries for x, y, and z)
		int axisIdx;
		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			AnimParam* scaleParam   = &mAnimInfo[jointIdx].mScale[axisIdx];
			scaleParam->mEntryNum   = stream.readInt();
			scaleParam->mDataOffset = stream.readInt();
			scaleParam->mFlags      = stream.readInt();
		}

		// Read rotation parameters (3 entries for x, y, and z)
		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			AnimParam* rotationParam   = &mAnimInfo[jointIdx].mRotation[axisIdx];
			rotationParam->mEntryNum   = stream.readInt();
			rotationParam->mDataOffset = stream.readInt();
			rotationParam->mFlags      = stream.readInt();
		}

		// Read translation parameters (3 entries for x, y, and z)
		for (axisIdx = 0; axisIdx < 3; axisIdx++) {
			AnimParam* translationParam   = &mAnimInfo[jointIdx].mTranslation[axisIdx];
			translationParam->mEntryNum   = stream.readInt();
			translationParam->mDataOffset = stream.readInt();
			translationParam->mFlags      = stream.readInt();
		}
	}

	checkMask();
	initData();
}

/**
 * @todo: Documentation
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
					mAnimInfo[index].mParentInfo = (parentIdx == -1) ? nullptr : &mAnimInfo[parentIdx];

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
	for (int checkIdx = 0; checkIdx < mRotateDataBlock->mDataIndex; checkIdx++) {
		checks[checkIdx] = false;
	}

	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		for (int axisIdx = 0; axisIdx < 3; axisIdx++) {
			// this is insane but required
			int* param = reinterpret_cast<int*>(&mAnimInfo[jointIdx].mRotation[axisIdx]);
			switch (param[0]) {
			case 0:
			{
				break;
			}
			case 1:
			{
				if (!checks[param[1]]) {
					mRotateDataBlock->mData[param[1]] = mRotateDataBlock->mData[param[1]] * PI / 180.0f;
					checks[param[1]]                  = true;
				}
				break;
			}
			default:
			{
				int size   = (param[2] == 0) ? 3 : 4;
				int offset = param[1] + 1;
				for (int keyIdx = 0; keyIdx < param[0]; keyIdx++) {
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
}

/**
 * @todo: Documentation
 */
void AnimDck::getAnimInfo(CmdStream* stream)
{
	while (!stream->endOfCmds() && !stream->endOfSection()) {
		stream->getToken(true);
		if (stream->isToken("numjoints")) {
			sscanf(stream->getToken(true), "%d", &mJointCount);
			mAnimInfo = new AnimDataInfo[mJointCount];
			for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
				mAnimInfo[jointIdx].mGroupIndex = jointIdx;
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
 * @todo: Documentation
 */
void AnimDck::extractSRT(SRT& srt, int, AnimDataInfo* anim, f32 time)
{
	if (!(anim->mFlags & AnimDataFlags::MatrixCalculated)) {

		// APPLY SCALE
		if (!(anim->mFlags & AnimDataFlags::AllScaleStatic)) {

			f32(&scale)[3]           = reinterpret_cast<f32(&)[3]>(srt.s);
			AnimParam(&animScale)[3] = anim->mScale;

			for (int axisIdx = 0; axisIdx < 3; axisIdx++) {

				AnimParam& thisParam = animScale[axisIdx];

				switch (thisParam.mEntryNum) {
				case 0: // 0 entries, default to 1.0
				{
					scale[axisIdx] = 1.0f;
					break;
				}
				case 1: // 1 entry, use the value of that entry alone
				{
					scale[axisIdx] = mScaleDataBlock->mData[thisParam.mDataOffset];
					break;
				}
				default: // multiple entries, use the extract method
				{
					scale[axisIdx] = extract(time, thisParam, *mScaleDataBlock);
					break;
				}
				}
			}

			if ((anim->mFlags & AnimDataFlags::AllIndividualScaleStatic) == AnimDataFlags::AllIndividualScaleStatic) {
				anim->mFlags |= AnimDataFlags::AllScaleStatic;
			}
		}

		// APPLY ROTATION
		if (!(anim->mFlags & AnimDataFlags::AllRotationStatic)) {

			f32(&rotation)[3]           = reinterpret_cast<f32(&)[3]>(srt.r);
			AnimParam(&animRotation)[3] = anim->mRotation;

			for (int axisIdx = 0; axisIdx < 3; axisIdx++) {

				AnimParam& thisParam = animRotation[axisIdx];

				switch (thisParam.mEntryNum) {
				case 0: // 0 entries, default to 1.0
				{
					rotation[axisIdx] = 0.0f;
					break;
				}
				case 1: // 1 entry, use the value of that entry alone
				{
					rotation[axisIdx] = mRotateDataBlock->mData[thisParam.mDataOffset];
					break;
				}
				default: // multiple entries, use the extract method
				{
					rotation[axisIdx] = extract(time, thisParam, *mRotateDataBlock);
					break;
				}
				}
			}

			if ((anim->mFlags & AnimDataFlags::AllIndividualRotationStatic) == AnimDataFlags::AllIndividualRotationStatic) {
				anim->mFlags |= AnimDataFlags::AllRotationStatic;
			}
		}

		// APPLY TRANSLATION
		if (!(anim->mFlags & AnimDataFlags::AllTranslationStatic)) {

			f32(&translation)[3]           = reinterpret_cast<f32(&)[3]>(srt.t);
			AnimParam(&animTranslation)[3] = anim->mTranslation;

			for (int axisIdx = 0; axisIdx < 3; axisIdx++) {

				AnimParam& thisParam = animTranslation[axisIdx];

				switch (thisParam.mEntryNum) {
				case 0: // 0 entries, default to 1.0
				{
					translation[axisIdx] = 1.0f;
					break;
				}
				case 1: // 1 entry, use the value of that entry alone
				{
					translation[axisIdx] = mTranslationDataBlock->mData[thisParam.mDataOffset];
					break;
				}
				default: // multiple entries, use the extract method
				{
					translation[axisIdx] = extract(time, thisParam, *mTranslationDataBlock);
					break;
				}
				}
			}

			if ((anim->mFlags & AnimDataFlags::AllIndividualTranslationStatic) == AnimDataFlags::AllIndividualTranslationStatic) {
				anim->mFlags |= AnimDataFlags::AllTranslationStatic;
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void AnimDck::makeAnimSRT(int boneAnimIdx, immut Matrix4f* mtx1, Matrix4f* mtx2, AnimDataInfo* anim, f32 time)
{
	SRT& srt = anim->mSRT;
	extractSRT(srt, boneAnimIdx, anim, time);
	if ((anim->mFlags & AnimDataFlags::AllComponentsStatic) == AnimDataFlags::AllComponentsStatic) {
		if (!(anim->mFlags & AnimDataFlags::MatrixCalculated)) {
			anim->mMtx.makeSRT(srt.s, srt.r, srt.t);
			anim->mFlags |= AnimDataFlags::MatrixCalculated;
		}
#if defined(WIN32)
		mtx1->multiplyTo(anim->mMtx, *mtx2);
#else
		MTXConcat(mtx1->mMtx, anim->mMtx.mMtx, mtx2->mMtx);
#endif
	} else {
		Matrix4f mtx;
		mtx2->makeConcatSRT(mtx1, mtx, srt);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00013C
 */
void BaseShape::exportIni(RandomAccessStream& stream, bool doSkipLights)
{
	PRINT("*---------------------------- exporting ini!!!!!!!!!!!\n");
	if (mRouteGroup.Child()) {
		stream.print("// Route info file for %s", Name());
		FOREACH_NODE(RouteGroup, mRouteGroup.Child(), route)
		{
			route->saveini("", stream);
		}
		stream.print("\n");
	}
	if (!doSkipLights && mLightGroup.Child()) {
		stream.print("// LightGroups info file for %s", Name());
		FOREACH_NODE(LightGroup, mLightGroup.Child(), light)
		{
			light->saveini("", stream);
		}
		stream.print("\n");
	}
	if (mCollisionInfo.Child()) {
		stream.print("// Collision info file for %s", Name());
		FOREACH_NODE(ObjCollInfo, mCollisionInfo.Child(), info)
		{
			info->saveini("", stream);
		}
		stream.print("\n");
	}
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 */
void ShapeDynMaterials::animate(f32* data)
{
	gsys->mTimer->start("shpDynMats", true);

	for (int matIdx = 0; matIdx < mMatCount; matIdx++) {
		Material& mat = mMaterials[matIdx];
		if (mat.mFlags & MATFLAG_PVW) {
			if (mat.mColourInfo.mTotalFrameCount != 0) {
				mat.mColourInfo.animate(data, mat.getColour());
			}

			for (int tevColIdx = 0; tevColIdx < 3; tevColIdx++) {
				if (mat.mTevInfo->mTevColRegs[tevColIdx].mAnimFrameCount) {
					mat.mTevInfo->mTevColRegs[tevColIdx].animate(data, mat.mTevInfo->mTevColRegs[tevColIdx].mAnimatedColor);
				}
			}

			for (int textureIdx = 0; textureIdx < (int)mat.mTextureInfo.mTextureDataCount; textureIdx++) {
				if (mat.mTextureInfo.mTextureData[textureIdx].mAnimationFactor != 255) {
					mat.mTextureInfo.mTextureData[textureIdx].animate(data, mat.mTextureInfo.mTextureData[textureIdx].mAnimatedTexMtx);
				}
			}
		}
	}

	gsys->mTimer->stop("shpDynMats");
}

/**
 * @todo: Documentation
 */
void ShapeDynMaterials::updateContext()
{
	for (int matIdx = 0; matIdx < mMatCount; matIdx++) {
		Material& mat = mMaterials[matIdx];
		if (mat.mFlags & MATFLAG_PVW) {
			mModel->mMaterialList[mat.mIndex].getColour() = mat.getColour();

			for (int tevColIdx = 0; tevColIdx < 3; tevColIdx++) {
				if (mat.mTevInfo->mTevColRegs[tevColIdx].mAnimFrameCount) {
					mModel->mMaterialList[mat.mIndex].mTevInfo->mTevColRegs[tevColIdx].mAnimatedColor
					    = mat.mTevInfo->mTevColRegs[tevColIdx].mAnimatedColor;
				}
			}

			for (int textureIdx = 0; textureIdx < (int)mat.mTextureInfo.mTextureDataCount; textureIdx++) {
				if (mat.mTextureInfo.mTextureData[textureIdx].mAnimationFactor != 255) {
					mModel->mMaterialList[mat.mIndex].mTextureInfo.mTextureData[textureIdx].mAnimatedTexMtx
					    = mat.mTextureInfo.mTextureData[textureIdx].mAnimatedTexMtx;
				}
			}
		}
	}
}

/**
 * @todo: Documentation
 */
BaseShape::BaseShape()
{
	mName             = "noname";
	mAnimMatrices     = nullptr;
	mAnimMtxCount     = 0;
	mShapeFlags       = ShapeFlags::None;
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

#if defined(WIN32)
	mDebugData.initCore("");
#endif
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
	mNBTList              = nullptr;
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
 * @todo: Documentation
 */
void BaseShape::countMaterials(Joint* joint, u32)
{
	for (int matPolyIdx = 0; matPolyIdx < mTotalMatpolyCount; matPolyIdx++) {
		if (mMatpolyList[matPolyIdx]->mJointList == joint) {
			bool alreadyCounted = false;
			for (int usedMatIdx = 0; usedMatIdx < matIndex; usedMatIdx++) {
				if (matUsed[usedMatIdx] == (int)mMatpolyList[matPolyIdx]->mMaterial->mIndex) {
					alreadyCounted = true;
					break;
				}
			}

			if (!alreadyCounted) {
				Material* mat   = mMatpolyList[matPolyIdx]->mMaterial;
				bool isAnimated = false;
				if (mat->mFlags & MATFLAG_PVW) {
					if (mat->mColourInfo.mTotalFrameCount) {
						isAnimated = true;
					}
					for (int tevRegIdx = 0; tevRegIdx < 3; tevRegIdx++) {
						if (mat->mTevInfo->mTevColRegs[tevRegIdx].mAnimFrameCount) {
							isAnimated = true;
						}
					}
					for (int texDataIdx = 0; texDataIdx < (int)mat->mTextureInfo.mTextureDataCount; texDataIdx++) {
						if (mat->mTextureInfo.mTextureData[texDataIdx].mAnimationFactor != 255) {
							isAnimated = true;
						}
					}
				}

				usedIndex++;
				if (isAnimated) {
					matUsed[matIndex] = mMatpolyList[matPolyIdx]->mMaterial->mIndex;
					matIndex++;
				}
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::recTraverseMaterials(Joint* joint, IDelegate2<Joint*, u32>* delegate)
{
	FOREACH_NODE(Joint, joint, jnt)
	{
		delegate->invoke(jnt, 0);
		if (jnt->mChild) {
			recTraverseMaterials(static_cast<Joint*>(jnt->mChild), delegate);
		}
	}
}

/**
 * @todo: Documentation
 */
ShapeDynMaterials* BaseShape::instanceMaterials(int jointIdx)
{
	ShapeDynMaterials* dynMats = new ShapeDynMaterials();
	makeInstance(*dynMats, jointIdx);
	return dynMats;
}

/**
 * @todo: Documentation
 */
void BaseShape::makeInstance(ShapeDynMaterials& animatedMats, int jointIdx)
{
	animatedMats.mModel = this;
	for (int matSlotIdx = 0; matSlotIdx < 0x100; matSlotIdx++) {
		matUsed[matSlotIdx] = 0;
	}

	matIndex  = 0;
	usedIndex = matIndex;

	Joint* joint = &mJointList[jointIdx];
	countMaterials(joint, 0);

	if (joint->mChild) {
		// We must keep commas out of the `stack_new` macro for building on MSVC 6.0 because it lacks variadic arguments.
		typedef Delegate2<BaseShape, Joint*, u32> CountMaterialsDelegate;
		recTraverseMaterials(static_cast<Joint*>(joint->mChild), stack_new(CountMaterialsDelegate)(this, &BaseShape::countMaterials));
	}

	animatedMats.mMatCount  = matIndex;
	animatedMats.mMaterials = new Material[animatedMats.mMatCount];

	for (int matIdx = 0; matIdx < animatedMats.mMatCount; matIdx++) {
		Material* mat = &animatedMats.mMaterials[matIdx];
		memcpy(mat, &mMaterialList[matUsed[matIdx]], sizeof(Material));
		if (mat->mFlags & MATFLAG_PVW) {
			mat->mTevInfo = new PVWTevInfo();
			memcpy(mat->mTevInfo, mMaterialList[matUsed[matIdx]].mTevInfo, sizeof(PVWTevInfo));
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000B4 (Matching by size)
 */
void recShowInfos(Graphics& gfx, ObjCollInfo* info)
{
	FOREACH_NODE(ObjCollInfo, info, currInfo)
	{
		if (currInfo->mCollType != OCT_Invalid) {
			currInfo->showInfo(gfx, *gfx.mActiveMatrix);
		}
		if (currInfo->Child()) {
			recShowInfos(gfx, static_cast<ObjCollInfo*>(currInfo->Child()));
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000074 (Matching by size)
 */
void BaseShape::drawobjcolls(Graphics& gfx, Camera& cam)
{
	recShowInfos(gfx, static_cast<ObjCollInfo*>(mCollisionInfo.Child()));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C
 */
void BaseShape::drawlights(Graphics& gfx, Camera& cam)
{
	immut Matrix4f* activeMtx = gfx.mActiveMatrix;
	if (mLightGroup.Child()) {
		FOREACH_NODE(LightGroup, mLightGroup.Child(), light)
		{
			light->refresh(gfx, activeMtx);
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00007C
 */
void BaseShape::drawroutes(Graphics& gfx, Camera& cam)
{
	FOREACH_NODE(RouteGroup, mRouteGroup.mChild, route)
	{
		gfx.useMatrix(cam.mLookAtMtx, 0);
		route->refresh(gfx, route);
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::drawculled(Graphics& gfx, Camera& cam, ShapeDynMaterials* dynMats)
{
	immut Matrix4f* mtx = gfx.mActiveMatrix;
	gfx.initMesh((Shape*)this);
	int culledJointCount = 0;
	if (dynMats) {
		FOREACH_NODE(ShapeDynMaterials, dynMats, iMat)
		{
			iMat->updateContext();
		}
	}

	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		BoundBox& box = mJointList[jointIdx].mBounds;
		if (cam.isBoundVisible(box, 0x8000 | 0x10 | 0x20 | 0x1 | 0x2 | 0x4 | 0x8)) {
			for (int matPolyIdx = mTotalMatpolyCount - 1; matPolyIdx >= 0; matPolyIdx--) {
				if (mMatpolyList[matPolyIdx]->mJointList == &mJointList[jointIdx]) {
					gfx.drawSingleMatpoly((Shape*)this, mMatpolyList[matPolyIdx]);
				}
			}
		} else {
			culledJointCount++;
			mJointList[jointIdx].mCullIndex = -1;
		}
	}

	if (gsys->mToggleDebugInfo) {
		for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
			gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
			gfx.useTexture(nullptr, GX_TEXMAP0);
			gfx.setColour(Colour(255, 32, 32, 255), true);
			bool lighting = gfx.setLighting(false, nullptr);
			mJointList[jointIdx].mBounds.draw(gfx);
			gfx.setLighting(lighting, nullptr);
			gfx.useMatrix(*mtx, 0);
			BoundBox& box = mJointList[jointIdx].mBounds;

			if (cam.isBoundVisible(box, 0x8000 | 0x10 | 0x20 | 0x1 | 0x2 | 0x4 | 0x8) && true) {

				bool lighting = gfx.setLighting(false, nullptr);
				gfx.useMatrix(Matrix4f::ident, 0);
				gfx.setColour(COLOUR_WHITE, true);
				int blend = gfx.setCBlending(BLEND_Alpha);
				Vector3f centre((box.mMax.x + box.mMin.x) * 0.5f, (box.mMax.y + box.mMin.y) * 0.5f + 10.0f,
				                (box.mMax.z + box.mMin.z) * 0.5f);
				centre.multMatrix(gfx.mCamera->mLookAtMtx);
				char buf[PATH_MAX];
				sprintf(buf, "%d", mJointList[jointIdx].mCullIndex);
				gfx.perspPrintf(gsys->mConsFont, centre, -(gsys->mConsFont->stringWidth(buf) / 2), 0, buf);
				gfx.setCBlending(blend);
				gfx.setLighting(lighting, nullptr);
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::drawshape(Graphics& gfx, Camera& cam, ShapeDynMaterials* dynMats)
{
	gsys->mTimer->start("drawShape", true);
	u32 prevRender = gfx.mMatRenderMask;
	if (mMeshCount) {
		if (!(mShapeFlags & ShapeFlags::AlwaysRedraw) && (mShapeFlags & ShapeFlags::AllowCaching)
		    && (gfx.mMatRenderMask & MATFLAG_AlphaBlend)) {
			gfx.cacheShape(this, dynMats);
			gfx.mMatRenderMask &= ~MATFLAG_AlphaBlend;
		}

		if ((mShapeFlags & ShapeFlags::AlwaysRedraw)
		    || (gfx.mMatRenderMask & (MATFLAG_Opaque | MATFLAG_AlphaTest | MATFLAG_InverseColorBlend))) {
			if (dynMats) {
				FOREACH_NODE(ShapeDynMaterials, dynMats, iMat)
				{
					iMat->updateContext();
				}
			}

			immut Matrix4f* activeMtx = gfx.mActiveMatrix;
			gfx.drawMeshes(cam, (Shape*)this);
			gfx.useMatrix(*activeMtx, 0);
			drawlights(gfx, cam);
			if (gsys->mToggleDebugInfo && (gfx.mMatRenderMask & MATFLAG_AlphaBlend)) {
				gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
				drawroutes(gfx, cam);
			}
		}
	}

	gfx.mMatRenderMask = prevRender;
	gsys->mTimer->stop("drawShape");
}

/**
 * @todo: Documentation
 */
void BaseShape::resolveTextureNames()
{
	if (mTextureNameList) {
		for (int attrMatIdx = 0; attrMatIdx < mAttrListMatCount; attrMatIdx++) {
			const char* texName = mTextureNameList[attrMatIdx];
			char filepath[PATH_MAX];
			sprintf(filepath, "%s%s", gsys->mTextureBase2, texName);
			mResolvedTextureList[attrMatIdx] = gsys->loadTexture(filepath, true);
			if (!mResolvedTextureList[attrMatIdx]) {
				sprintf(filepath, "%s%s", gsys->mTextureBase1, texName);
				mResolvedTextureList[attrMatIdx] = gsys->loadTexture(filepath, true);
			}

			if (!mResolvedTextureList[attrMatIdx]) {
				PRINT("Could not load texture %s\n", texName);
			}
		}
	}

	if (mFallbackTexAttrCount || mAttrListMatCount) {
		PRINT("making tmp attrlist and materials : %d : %d\n", mFallbackTexAttrCount, mAttrListMatCount);
		int count    = mFallbackTexAttrCount ? mFallbackTexAttrCount : mAttrListMatCount;
		mTexAttrList = new TexAttr[count];
		for (int texAttrIdx = 0; texAttrIdx < count; texAttrIdx++) {
			mTexAttrList[texAttrIdx].mIndex        = texAttrIdx;
			mTexAttrList[texAttrIdx].mTextureIndex = (texAttrIdx | mAttrListMatCount != 0) ? 0x8000 : 0;
			mTexAttrList[texAttrIdx].mTexture      = mResolvedTextureList[texAttrIdx];
		}

		Material* matList = new Material[count];
		if (mMaterialCount == count) {
			PRINT("ALREADY HAS CORRECT NUMBER OF MATERIALS!!!!\n");
			for (int materialCopyIdx = 0; materialCopyIdx < count; materialCopyIdx++) {
				matList[materialCopyIdx] = mMaterialList[materialCopyIdx];
			}
		}

		mMaterialCount = count;
		for (int matIdx = 0; matIdx < count; matIdx++) {
			matList[matIdx].mIndex        = matIdx;
			matList[matIdx].mTextureIndex = matIdx;
		}

		mMaterialList = matList;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000064
 */
void BaseShape::skipChunk(RandomAccessStream& stream, u32 amt)
{
	for (u32 skippedByteIdx = 0; skippedByteIdx < amt; skippedByteIdx++) {
		stream.readByte();
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::recAddMatpoly(Joint* parentJoint, int flag)
{
	FOREACH_NODE(Joint, parentJoint, currentJoint)
	{
		if (currentJoint->mChild) {
			recAddMatpoly((Joint*)currentJoint->mChild, flag);
		}

		FOREACH_NODE(Joint::MatPoly, currentJoint->mMatPoly.mChild, poly)
		{
			Material* mat = &mMaterialList[poly->mIndex];

			if ((mat->mFlags >> 8) & flag) {
				poly->mMaterial         = mat;
				poly->mMesh             = &mMeshList[poly->mMeshIndex];
				mMatpolyList[_dlindx++] = poly;
			}
		}
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::read(RandomAccessStream& stream)
{
	int unused = 0;

	u32 freeBefore; // This is not supposed to be reused in every switch case BUT doing so fixes stack for the DOL.
	STACK_PAD_VAR(1);

	while (true) {
		u32 chunkStartPosition = stream.getPosition();
		u32 chunkType          = stream.readInt();
		u32 chunkLength        = stream.readInt();

		if (chunkStartPosition & 0x1F) {
			ERROR("chunk start not on boundary %08x!\n", chunkStartPosition);
		}

		switch (chunkType) {
		case BaseShapeChunk::Header:
		{
			stream.skipPadding(0x20);
			int unused  = stream.readInt();
			mShapeFlags = stream.readInt();
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::Vertex:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mVertexCount = stream.readInt();
			stream.skipPadding(0x20);
			mVertexList = reinterpret_cast<Vector3f*>(new (0x20) char[sizeof(Vector3f) * mVertexCount]); // hmm.
			for (int vertexIdx = 0; vertexIdx < mVertexCount; vertexIdx++) {
				mVertexList[vertexIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::VertexNormal:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mNormalCount = stream.readInt();
			stream.skipPadding(0x20);
			mNormalList = reinterpret_cast<Vector3f*>(new (0x20) char[sizeof(Vector3f) * mNormalCount]); // hmm
			for (int normalIdx = 0; normalIdx < mNormalCount; normalIdx++) {
				mNormalList[normalIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::VertexNBT:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mNBTCount = stream.readInt();
			stream.skipPadding(0x20);
			mNBTList = reinterpret_cast<NBT*>(new (0x20) char[(sizeof(Vector3f) * mNBTCount * 3)]); // really
			for (int nbtIdx = 0; nbtIdx < mNBTCount; nbtIdx++) {
				reinterpret_cast<Vector3f*>(mNBTList)[3 * nbtIdx].read(stream);
				reinterpret_cast<Vector3f*>(mNBTList)[3 * nbtIdx + 1].read(stream);
				reinterpret_cast<Vector3f*>(mNBTList)[3 * nbtIdx + 2].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::VertexColour:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mVtxColorCount = stream.readInt();
			stream.skipPadding(0x20);
			mVtxColorList = (Colour*)(new (0x20) GXColor[mVtxColorCount]);
			for (int colorIdx = 0; colorIdx < mVtxColorCount; colorIdx++) {
				mVtxColorList[colorIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
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
		case BaseShapeChunk::TexCoord7:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();
			int index  = chunkType - BaseShapeChunk::TexCoord0;

			mTexCoordCounts[index] = stream.readInt();
			stream.skipPadding(0x20);
			mTexCoordList[index] = new (0x20) Vector2f[mTexCoordCounts[index]];

			for (int texCoordIdx = 0; texCoordIdx < mTexCoordCounts[index]; texCoordIdx++) {
				mTexCoordList[index][texCoordIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			mTotalActiveTexCoords++;
			break;
		}
		case BaseShapeChunk::Texture:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mTextureCount = stream.readInt();
			stream.skipPadding(0x20);
			mTextureList = new TexImg[mTextureCount];
			for (int textureIdx = 0; textureIdx < mTextureCount; textureIdx++) {
				mTextureList[textureIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::TextureAttribute:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mTexAttrCount = stream.readInt();
			stream.skipPadding(0x20);
			mTexAttrList = new TexAttr[mTexAttrCount];
			for (int texAttrIdx = 0; texAttrIdx < mTexAttrCount; texAttrIdx++) {
				mTexAttrList[texAttrIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::Material:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mMaterialCount = stream.readInt();
			mTevInfoCount  = stream.readInt();

			stream.skipPadding(0x20);

			if (mTevInfoCount) {
				mTevInfoList = new PVWTevInfo[mTevInfoCount];
				for (int tevInfoIdx = 0; tevInfoIdx < mTevInfoCount; tevInfoIdx++) {
					mTevInfoList[tevInfoIdx].read(stream);
				}
			}

			if (mMaterialCount) {
				mMaterialList = new Material[mMaterialCount];
				for (int materialIdx = 0; materialIdx < mMaterialCount; materialIdx++) {
					mMaterialList[materialIdx].mIndex = materialIdx;
					mMaterialList[materialIdx].read(stream);
					mMaterialList[materialIdx].mTevInfo = &mTevInfoList[mMaterialList[materialIdx].mTevInfoIndex];

					MatobjInfo* info = new MatobjInfo;
					info->mTarget    = &mMaterialList[materialIdx];
					gsys->addGfxObject(info);
				}
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::VertexMatrix:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mVtxMatrixCount = stream.readInt();
			stream.skipPadding(0x20);
			mVtxMatrixList = new VtxMatrix[mVtxMatrixCount];
			for (int vtxMatrixIdx = 0; vtxMatrixIdx < mVtxMatrixCount; vtxMatrixIdx++) {
				mVtxMatrixList[vtxMatrixIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::MatrixEnvelope:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mEnvelopeCount = stream.readInt();
			stream.skipPadding(0x20);
			mEnvelopeList = new Envelope[mEnvelopeCount];
			for (int envelopeIdx = 0; envelopeIdx < mEnvelopeCount; envelopeIdx++) {
				mEnvelopeList[envelopeIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::Mesh:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mMeshCount = stream.readInt();
			stream.skipPadding(0x20);
			mMeshList = new Mesh[mMeshCount];
			for (int meshIdx = 0; meshIdx < mMeshCount; meshIdx++) {
				mMeshList[meshIdx].read(stream);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::Joint:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mJointCount = stream.readInt();
			stream.skipPadding(0x20);
			mJointList = new Joint[mJointCount];
			for (int meshIdx = 0; meshIdx < mMeshCount; meshIdx++) {
				if (mMeshList[meshIdx].mParentJoint != -1) {
					mMeshList[meshIdx].mJointList = &mJointList[mMeshList[meshIdx].mParentJoint];
				}
			}

			for (int jointIdx1 = 0; jointIdx1 < mJointCount; jointIdx1++) {
				mJointList[jointIdx1].mParentShape = this;
				mJointList[jointIdx1].read(stream);
				mCourseExtents.expandBound(mJointList[jointIdx1].mBounds);
			}

			stream.skipPadding(0x20);

			mTotalMatpolyCount = 0;
			for (int jointIdx2 = 0; jointIdx2 < mJointCount; jointIdx2++) {
				mTotalMatpolyCount += mJointList[jointIdx2].mMatPolyCount;
			}

			mMatpolyList = new Joint::MatPoly*[mTotalMatpolyCount];

			for (int jointIdx3 = 0; jointIdx3 < mJointCount; jointIdx3++) {
				mJointList[jointIdx3].mIndex = jointIdx3;
				if (mJointList[jointIdx3].mParentIndex != -1) {
					mJointList[mJointList[jointIdx3].mParentIndex].add(&mJointList[jointIdx3]);
				}
			}

			_dlindx = 0;

			// Sorts materials in the following order:
			// 1. Alpha-blended materials (transparent, needs to be last).
			// 2. Alpha-test materials (cutout transparency).
			// 3. Opaque materials (no transparency, needs to be first).
			// This is to handle transparency correctly without per-frame depth sorting.
			recAddMatpoly(mJointList, MATFLAG_AlphaBlend >> 8);
			recAddMatpoly(mJointList, MATFLAG_AlphaTest >> 8);
			recAddMatpoly(mJointList, MATFLAG_Opaque >> 8);

			for (int matPolyIdx = 0; matPolyIdx < mTotalMatpolyCount; matPolyIdx++) {
				mMatpolyList[matPolyIdx]->mJointList = mMatpolyList[matPolyIdx]->mMesh->mJointList;
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			break;
		}
		case BaseShapeChunk::JointName:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mJointCount = stream.readInt();
			stream.skipPadding(0x20);
			for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
				String name(0);
				stream.readString(name);
				mJointList[jointIdx].setName(name.mString);
			}

			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::CollisionPrism:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();

			mTriCount      = stream.readInt();
			mBaseRoomCount = stream.readInt();
			stream.skipPadding(0x20);
			mRoomInfoList = new RoomInfo[mBaseRoomCount];

			for (int roomIdx = 0; roomIdx < mBaseRoomCount; roomIdx++) {
				mRoomInfoList[roomIdx].read(stream);
			}
			stream.skipPadding(0x20);

			mTriList = new CollTriInfo[mTriCount];

			for (int triIdx = 0; triIdx < mTriCount; triIdx++) {
				mTriList[triIdx].read(stream);
				mTriList[triIdx].init(mRoomInfoList, mVertexList);
			}

			// This resembles the math done for the "kilobytes used" PRINT in the `BaseShapeChunk::CollisionGrid` chunk.
			(static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f;
			stream.skipPadding(0x20);
			break;
		}
		case BaseShapeChunk::CollisionGrid:
		{
			freeBefore = gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			mCourseExtents.read(stream);
			mGridSize  = stream.readFloat();
			mGridSizeX = stream.readInt();
			mGridSizeY = stream.readInt();

			mCollGroups          = new CollGroup*[mGridSizeX * mGridSizeY];
			int groupCount       = stream.readInt();
			int maxTrisPerGroup  = 0;
			CollGroup* tmpGroups = new CollGroup[groupCount];

			for (int groupIdx = 0; groupIdx < groupCount; groupIdx++) {
				tmpGroups[groupIdx].mFarCulledTriCount = stream.readShort();
				tmpGroups[groupIdx].mTriCount          = stream.readShort();
				tmpGroups[groupIdx].mTriangleList      = new CollTriInfo*[tmpGroups[groupIdx].mTriCount];

				if (tmpGroups[groupIdx].mTriCount > maxTrisPerGroup) {
					maxTrisPerGroup = tmpGroups[groupIdx].mTriCount;
				}

				for (int triSlotIdx = 0; triSlotIdx < tmpGroups[groupIdx].mTriCount; triSlotIdx++) {
					int idx                                       = stream.readInt();
					tmpGroups[groupIdx].mTriangleList[triSlotIdx] = &mTriList[idx];
				}

				if (tmpGroups[groupIdx].mFarCulledTriCount) {
					tmpGroups[groupIdx].mFarCulledTriDistances = new u8[tmpGroups[groupIdx].mFarCulledTriCount];
					for (int farCullIdx = 0; farCullIdx < tmpGroups[groupIdx].mFarCulledTriCount; farCullIdx++) {
						tmpGroups[groupIdx].mFarCulledTriDistances[farCullIdx] = stream.readByte();
					}
				}
			}

			PRINT("got a max of %d col tris in one block!\n", maxTrisPerGroup);

			CollGroup* group     = new CollGroup();
			group->mTriCount     = 0;
			group->mTriangleList = nullptr;
			int validTriCount    = 0;
			f32 maxDist          = 0.0f;
			for (int row = 0; row < mGridSizeY; row++) {
				for (int col = 0; col < mGridSizeX; col++) {
					int groupIdx = stream.readInt();
					if (groupIdx == -1) {
						mCollGroups[row * mGridSizeX + col] = group;
					} else {
						mCollGroups[row * mGridSizeX + col] = &tmpGroups[groupIdx];
						f32 cellSize                        = 64.0f;
						f32 cellMinX                        = mCourseExtents.mMin.x + col * cellSize;
						f32 cellMinZ                        = mCourseExtents.mMin.z + row * cellSize;
						f32 cellBorderSize                  = cellSize * 1.0f;

						BoundBox cellBox;
						cellBox.expandBound(Vector3f(cellMinX - cellBorderSize, mCourseExtents.mMin.y - cellBorderSize,
						                             cellMinZ - cellBorderSize)); //
						cellBox.expandBound(Vector3f(cellMinX + cellSize + cellBorderSize, mCourseExtents.mMax.y + cellBorderSize,
						                             cellMinZ + cellSize + cellBorderSize));

						for (int triIdx = 0; triIdx < tmpGroups[groupIdx].mTriCount; triIdx++) {
							CollTriInfo* tri = tmpGroups[groupIdx].mTriangleList[triIdx];
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
			}

			PRINT("maxDist = %f : got a total of %d col tris in lists mem = %d bytes!\n", maxDist, validTriCount, 8 * validTriCount);

			PRINT("!!!!!!!!!!!!!!!!! COLLGRID USING %.2f kbytes\n",
			      (static_cast<size_t>(freeBefore - gsys->getHeap(SYSHEAP_App)->getFree())) / 1024.0f);
			stream.skipPadding(0x20);
			break;
		}
		default:
		{
			skipChunk(stream, chunkLength);
			break;
		}
		}
		if (chunkType == 0xFFFF) {
			break;
		}
	};

	if (stream.getPending() != 0) {
		importIni(stream);
	}

	// one matrix for each joint and for each envelope
	mAnimMtxCount = mJointCount + mEnvelopeCount;

	// i don't even care anymore. i am numb to this.
	STACK_PAD_INLINE(11);
}

/**
 * @todo: Documentation
 */
void BaseShape::initIni(bool usePlatforms)
{
	FOREACH_NODE(LightGroup, mLightGroup.Child(), light)
	{
		if (light->mTexSource) {

			int idx = -1;
			if (light->mMatSource) {
				for (int separatorIdx = 0; separatorIdx < (int)strlen(light->mMatSource); separatorIdx++) {
					if (light->mMatSource[separatorIdx] == ':') {
						sscanf(&light->mMatSource[separatorIdx + 1], "%d", &idx);
						break;
					}
				}
			}

			if (idx == -1) {
				light->mHaloTex = gsys->loadTexture(light->mTexSource, true);
			}

			Material* mat = (idx == -1) ? nullptr : &mMaterialList[idx];

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
	}

	FOREACH_NODE(ObjCollInfo, mCollisionInfo.Child(), coll)
	{
		if (coll->mCollType == OCT_Platform && usePlatforms) {
			coll->mPlatShape = gsys->loadShape(coll->mPlatformName, true);
			if (coll->mPlatShape) {
				coll->mPlatShape->createCollisions(32);
			}
			if (coll->mFlags) {
				coll->mPlatShape->mShapeFlags |= ShapeFlags::IsPlatform;
			}
		}

		FOREACH_NODE(ObjCollInfo, coll->Child(), childColl)
		{
			if (childColl->mCollType == OCT_Platform && usePlatforms) {
				childColl->mPlatShape = gsys->loadShape(childColl->mPlatformName, true);
				if (childColl->mPlatShape) {
					childColl->mPlatShape->createCollisions(32);
				}
				if (childColl->mFlags) {
					childColl->mPlatShape->mShapeFlags |= ShapeFlags::IsPlatform;
				}
			}
		}
	}

	FOREACH_NODE(RouteGroup, mRouteGroup.Child(), route)
	{
#ifdef WIN32
		route->mDebugWaypointTexture            = gsys->loadTexture("rootRing.txe", true);
		route->mDebugWaypointTexture->mTexFlags = Texture::TEX_CLAMP_S | Texture::TEX_CLAMP_T;
#else
		route->mDebugWaypointTexture = nullptr;
#endif
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::initialise()
{
	for (int texAttrIdx = 0; texAttrIdx < mTexAttrCount; texAttrIdx++) {
		if (!(mTexAttrList[texAttrIdx].mTextureIndex & 0x8000)) {
			mTexAttrList[texAttrIdx].mImage         = &mTextureList[mTexAttrList[texAttrIdx].mTextureIndex];
			mTexAttrList[texAttrIdx].mImage->mIndex = mTexAttrList[texAttrIdx].mTextureIndex;
			mTexAttrList[texAttrIdx].initImage();
		} else {
			if (!mTexAttrList[texAttrIdx].mTexture) {
				mTexAttrList[texAttrIdx].mTexture = mResolvedTextureList[mTexAttrList[texAttrIdx].mTextureIndex & 0x7FFF];
			}
		}
	}

	for (int matIdx = 0; matIdx < mMaterialCount; matIdx++) {
		!!(&mMaterialList[matIdx]);
		if (mMaterialList[matIdx].mFlags & MATFLAG_PVW) {
			for (int texDataIdx = 0; texDataIdx < (int)mMaterialList[matIdx].mTextureInfo.mTextureDataCount; texDataIdx++) {
				mMaterialList[matIdx].mTextureInfo.mTextureData[texDataIdx].mTextureAttribute
				    = &mTexAttrList[mMaterialList[matIdx].mTextureInfo.mTextureData[texDataIdx].mSourceAttrIndex];
				mMaterialList[matIdx].mTextureInfo.mTextureData[texDataIdx].mTexture
				    = mTexAttrList[mMaterialList[matIdx].mTextureInfo.mTextureData[texDataIdx].mSourceAttrIndex].mTexture;
				!!(&mMaterialList[matIdx].mTextureInfo);
				!!(&mMaterialList[matIdx].mTextureInfo);
				mMaterialList[matIdx].mTextureInfo.mTextureData[texDataIdx].mTexture;
#if 0 // This is what the DLL actually does instead of all this noise.
				Texture* unused = mMaterialList[matIdx].mTextureInfo.mTextureData[texDataIdx].mTexture;
#endif
			}
		} else if (mMaterialList[matIdx].mTextureIndex != -1) {
			!!(mTexAttrList[0].mTexture);
			int carrier                      = matIdx;
			mMaterialList[matIdx].mAttribute = &mTexAttrList[mMaterialList[matIdx].mTextureIndex];
			!!(mTexAttrList[mMaterialList[matIdx].mTextureIndex].mTexture);
			mMaterialList[matIdx].mTexture = mTexAttrList[mMaterialList[matIdx].mTextureIndex].mTexture;
			!!((mMaterialList[matIdx].mTexture, carrier));
		} else {
			mMaterialList[matIdx].mTexture = nullptr;
		}
	}

	mCurrentAnimation                = new AnimContext();
	mCurrentAnimation->mData         = nullptr;
	mCurrentAnimation->mCurrentFrame = 0.0f;
	importDck(nullptr, nullptr);
	calcBasePose(Matrix4f::ident);
	if (mJointCount) {
		mAnimOverrides = new AnimContext*[mJointCount];

		for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
			mAnimOverrides[jointIdx] = mCurrentAnimation;
		}
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::createCollisions(int gridSize)
{
	u32 heapStart = gsys->getHeap(SYSHEAP_App)->getFree();

#if defined(WIN32)
	for (int triIdx = 0; triIdx < mTriCount; triIdx++) {
		for (int edgeIdx = 0; edgeIdx < 3; edgeIdx++) {
			if (mTriList[triIdx].mAdjacentTriIndices[edgeIdx] >= 0) {
				Vector3f edgeVectors[2];
				Vector3f unitVecs[2];

				edgeVectors[0].set(mVertexList[mTriList[triIdx].mVertexIndices[edgeIdx % 3]].x
				                       - mVertexList[mTriList[triIdx].mVertexIndices[(edgeIdx + 1) % 3]].x,
				                   mVertexList[mTriList[triIdx].mVertexIndices[edgeIdx % 3]].y
				                       - mVertexList[mTriList[triIdx].mVertexIndices[(edgeIdx + 1) % 3]].y,
				                   mVertexList[mTriList[triIdx].mVertexIndices[edgeIdx % 3]].z
				                       - mVertexList[mTriList[triIdx].mVertexIndices[(edgeIdx + 1) % 3]].z);
				edgeVectors[1].set(mVertexList[mTriList[triIdx].mVertexIndices[(edgeIdx + 1) % 3]].x
				                       - mVertexList[mTriList[triIdx].mVertexIndices[edgeIdx % 3]].x,
				                   mVertexList[mTriList[triIdx].mVertexIndices[(edgeIdx + 1) % 3]].y
				                       - mVertexList[mTriList[triIdx].mVertexIndices[edgeIdx % 3]].y,
				                   mVertexList[mTriList[triIdx].mVertexIndices[(edgeIdx + 1) % 3]].z
				                       - mVertexList[mTriList[triIdx].mVertexIndices[edgeIdx % 3]].z);

				unitVecs[0] = edgeVectors[0];
				unitVecs[0].normalise();
				unitVecs[0].CP(mTriList[triIdx].mTriangle.mNormal);

				// This cross product is never used
				unitVecs[1] = edgeVectors[1];
				unitVecs[1].normalise();
				unitVecs[1].CP(mTriList[mTriList[triIdx].mAdjacentTriIndices[edgeIdx]].mTriangle.mNormal);

				f32 adjacentNormalDot
				    = mTriList[triIdx].mTriangle.mNormal.DP(mTriList[mTriList[triIdx].mAdjacentTriIndices[edgeIdx]].mTriangle.mNormal);
				f32 edgeNormalDot = unitVecs[0].DP(mTriList[mTriList[triIdx].mAdjacentTriIndices[edgeIdx]].mTriangle.mNormal);

				f32 edgeAngle = acosf(edgeNormalDot);
				if (adjacentNormalDot < 0.0f) {
					edgeAngle = -edgeAngle;
				}

				Vector3f anglePoints[4];
				anglePoints[0].set(sinf(edgeAngle + PI) * 100.0f, cosf(edgeAngle + PI) * 100.0f, 0.0f);
				anglePoints[1].set(0.0f, 0.0f, 0.0f);
				anglePoints[2].set(0.0f, 0.0f, 0.0f);
				anglePoints[3].set(100.0f, 0.0f, 0.0f);

				unitVecs[0] = anglePoints[1] - anglePoints[0];
				unitVecs[0].normalise();
				unitVecs[1] = anglePoints[2] - anglePoints[3];
				unitVecs[1].normalise();

				Vector3f offsetPoints[4];
				offsetPoints[0] = anglePoints[0] + Vector3f(sinf(edgeAngle - HALF_PI), cosf(edgeAngle - HALF_PI), 0.0f);
				offsetPoints[1] = anglePoints[1] + Vector3f(sinf(edgeAngle - HALF_PI), cosf(edgeAngle - HALF_PI), 0.0f);
				offsetPoints[2] = anglePoints[2] + Vector3f(0.0f, 1.0f, 0.0f);
				offsetPoints[3] = anglePoints[3] + Vector3f(0.0f, 1.0f, 0.0f);

				f32 edgeSomething      = 0.0f;
				f32 lineIntersectDenom = (-unitVecs[1].x * unitVecs[0].y) - (unitVecs[0].x * -unitVecs[1].y);
				if (lineIntersectDenom != 0.0f) {
					edgeSomething = ((offsetPoints[2].x - offsetPoints[1].x) * unitVecs[1].y
					                 + (offsetPoints[2].y - offsetPoints[1].y) * -unitVecs[1].x)
					              / lineIntersectDenom;
				}
				mTriList[triIdx].mEdgeSomething[edgeIdx] = edgeSomething;

			} else {
				mTriList[triIdx].mEdgeSomething[edgeIdx] = 1.0f;
			}
		}
	}
#endif

	if (!mCollGroups) {
		mCourseExtents.resetBound();
		for (int triIdx = 0; triIdx < mTriCount; triIdx++) {
			mCourseExtents.expandBound(mVertexList[mTriList[triIdx].mVertexIndices[0]]);
			mCourseExtents.expandBound(mVertexList[mTriList[triIdx].mVertexIndices[1]]);
			mCourseExtents.expandBound(mVertexList[mTriList[triIdx].mVertexIndices[2]]);
		}

		CollGroup unused;
		mGridSize  = gridSize;
		mGridSizeX = (mCourseExtents.mMax.x - mCourseExtents.mMin.x + mGridSize) / mGridSize;
		mGridSizeY = (mCourseExtents.mMax.z - mCourseExtents.mMin.z + mGridSize) / mGridSize;

		PRINT("Gridsize %f : course extents from (%.1f, %.1f, %.1f) - (%.1f, %.1f, %.1f) : grid %d x %d\n", mGridSize,
		      mCourseExtents.mMin.x, mCourseExtents.mMin.y, mCourseExtents.mMin.z, mCourseExtents.mMax.x, mCourseExtents.mMax.y,
		      mCourseExtents.mMax.z, mGridSizeX, mGridSizeY);
		mCollGroups       = new CollGroup*[mGridSizeX * mGridSizeY];
		CollGroup* groups = new CollGroup[mGridSizeX * mGridSizeY];
		for (int collGroupIdx = 0; collGroupIdx < mGridSizeX * mGridSizeY; collGroupIdx++) {
			mCollGroups[collGroupIdx] = &groups[collGroupIdx];
		}

		int currCellTriCount = 0;
		u32 unused2[768];
		CollTriInfo* tris[256];
		int totalTriCount    = 0; // Calculation goes unused.
		int scannedCellCount = 0;
		int numUnique        = 0;
		for (int gridY = 0; gridY < mGridSizeY; gridY++) {
			for (int gridX = 0; gridX < mGridSizeX; gridX++) {
				f32 minX = gridX * mGridSize + mCourseExtents.mMin.x;
				f32 minZ = gridY * mGridSize + mCourseExtents.mMin.z;
				f32 size = mGridSize * 1.0f;

				BoundBox box1;
				box1.expandBound(Vector3f(minX - size, mCourseExtents.mMin.y - size, minZ - size));
				box1.expandBound(Vector3f(minX + mGridSize + size, mCourseExtents.mMax.y + size, minZ + mGridSize + size));

				currCellTriCount = 0;
				for (int triIdx = 0; triIdx < mTriCount; triIdx++) {
					BoundBox box2;
					box2.resetBound();
					box2.expandBound(mVertexList[mTriList[triIdx].mVertexIndices[0]]);
					box2.expandBound(mVertexList[mTriList[triIdx].mVertexIndices[1]]);
					box2.expandBound(mVertexList[mTriList[triIdx].mVertexIndices[2]]);

					if (box2.intersects(box1)) {
						f32(&bboxVals)[6]     = reinterpret_cast<f32(&)[6]>(box1);
						int bboxIndices[8][3] = {
							{ 0, 1, 2 }, { 0, 1, 5 }, { 0, 4, 2 }, { 0, 4, 5 }, { 3, 1, 2 }, { 3, 1, 5 }, { 3, 4, 2 }, { 3, 4, 5 },
						};
						CullingPlane unused3[3];
						bool doVerifyTriCountIsUnderLimit = true;
						int d                             = 0;
						for (int bboxCornerIdx = 0; bboxCornerIdx < 8; bboxCornerIdx++) {
							Vector3f point(bboxVals[bboxIndices[bboxCornerIdx][0]], bboxVals[bboxIndices[bboxCornerIdx][1]],
							               bboxVals[bboxIndices[bboxCornerIdx][2]]);
							if (mTriList[triIdx].mTriangle.dist(point) < 0.0f) {
								d++;
							}
						}

						if (d == 8) {
							doVerifyTriCountIsUnderLimit = false;
						}

						if (doVerifyTriCountIsUnderLimit) {
							tris[currCellTriCount] = &mTriList[triIdx];
							currCellTriCount++;
							if (currCellTriCount == 1024) {
								ERROR("Too many tris per block for collision system!!");
							}
						}
					}
				}

				if (currCellTriCount != 0) {
					totalTriCount += currCellTriCount;
					CollGroup* groupA = nullptr;

					for (int prevCellIdx = 0; prevCellIdx < scannedCellCount; prevCellIdx++) {
						int row = prevCellIdx / mGridSizeX;
						int col = prevCellIdx % mGridSizeX;

						CollGroup* group = mCollGroups[row * mGridSizeX + col];
						if (group->mTriCount == currCellTriCount) {
							bool check2 = true;
							for (int triListIdx = 0; triListIdx < currCellTriCount; triListIdx++) {
								if (group->mTriangleList[triListIdx] != tris[triListIdx]) {
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
						CollGroup* g     = mCollGroups[gridY * mGridSizeX + gridX];
						g->mTriCount     = currCellTriCount;
						g->mTriangleList = new CollTriInfo*[currCellTriCount];
						for (int triCopyIdx = 0; triCopyIdx < currCellTriCount; triCopyIdx++) {
							g->mTriangleList[triCopyIdx] = tris[triCopyIdx];
						}

						numUnique++;
					} else {
						mCollGroups[gridY * mGridSizeX + gridX]->mTriangleList = groupA->mTriangleList;
						mCollGroups[gridY * mGridSizeX + gridX]->mTriCount     = groupA->mTriCount;
					}
				}

				scannedCellCount++;
			}
		}

		PRINT("got a total of %d unique groups\n", numUnique);
		PRINT("*------------------------------------------- collision data uses %.2fk\n",
		      (heapStart - gsys->getHeap(SYSHEAP_App)->getFree()) / 1024.0f);
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::calcBasePose(immut Matrix4f& target)
{
	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		SRT srt;
		srt.s = mJointList[jointIdx].mScale;
		srt.r = mJointList[jointIdx].mRotation;
		srt.t = mJointList[jointIdx].mTranslation;

		int parentIndex = mJointList[jointIdx].mParentIndex;
		Matrix4f initialPose;
		immut Matrix4f* currentMatrix = parentIndex == -1 ? &target : &mJointList[parentIndex].mAnimMatrix;
		mJointList[jointIdx].mAnimMatrix.makeConcatSRT(currentMatrix, initialPose, srt);
		mJointList[jointIdx].mAnimMatrix.inverse(&mJointList[jointIdx].mInverseAnimMatrix);
	}
}

/**
 * @todo: Documentation
 */
AnimData* BaseShape::loadDck(immut char* name, RandomAccessStream& s)
{
	AnimDck* pDck = new AnimDck(name);
	pDck->mModel  = this;
	pDck->read(s);
	if (pDck->mJointCount != mJointCount) {
		PRINT("(%s) NUMJOINTS DOES NOT MATCH, THINGS MIGHT GO WRONG!!!\n", name);
	}

#if defined(WIN32)
	mDebugData.add(pDck);
#endif
	mCurrentAnimation->mData         = pDck;
	mCurrentAnimation->mCurrentFrame = 0.0f;
	return pDck;
}

/**
 * @todo: Documentation
 */
AnimData* BaseShape::importDck(immut char* name, CmdStream* cmds)
{
	AnimDck* data = nullptr;
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

#if defined(WIN32)
	mDebugData.add(data);
#endif
	mCurrentAnimation->mData         = data;
	mCurrentAnimation->mCurrentFrame = 0.0f;
	return data;
}

/**
 * @todo: Documentation
 */
AnimData* BaseShape::loadDca(immut char* name, RandomAccessStream& s)
{
	AnimDca* pDca = new AnimDca(name);
	pDca->mModel  = this;
	pDca->read(s);
	if (pDca->mJointCount != mJointCount) {
		PRINT("(%s) NUMJOINTS DOES NOT MATCH, THINGS MIGHT GO WRONG!!!\n", name);
	}

#if defined(WIN32)
	mDebugData.add(pDca);
#endif
	mCurrentAnimation->mData = pDca;
	return pDca;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000138
 */
void BaseShape::importDca(immut char* name, CmdStream* cmds)
{
	AnimDca* data = nullptr;
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

#if defined(WIN32)
	mDebugData.add(data);
#endif
	mCurrentAnimation->mData = data;
}

/**
 * @todo: Documentation
 */
AnimData* BaseShape::loadAnimation(immut char* name, bool isRelativePath)
{
	RandomAccessStream* stream = gsys->openFile(name, isRelativePath);
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
 * @brief Gets reference to animation matrix by index.
 *
 * @param animIdx Index of animation matrix to get (indexed by joint indices, then envelope indices).
 * @return Reference to animation matrix.
 */
Matrix4f& BaseShape::getAnimMatrix(int animIdx)
{
	return mAnimMatrices[animIdx];
}

/**
 * @todo: Documentation
 */
void BaseShape::backupAnimOverrides(AnimContext** animList)
{
	mBackupAnimOverrides = animList;
	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		mBackupAnimOverrides[jointIdx] = mAnimOverrides[jointIdx];
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::restoreAnimOverrides()
{
	for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
		mAnimOverrides[jointIdx] = mBackupAnimOverrides[jointIdx];
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::overrideAnim(int jointIdx, AnimContext* anim)
{
	Joint* joint = &mJointList[jointIdx];
	joint->overrideAnim(anim);
	if (joint->mChild) {
		Joint* childJoint = static_cast<Joint*>(joint->mChild);
		childJoint->recOverrideAnim(anim);
	}
}

/**
 * @todo: Documentation
 */
AnimFrameCacher::AnimFrameCacher(int num)
{
	mCache      = new AyuCache(num * 64);
	mInfo.mName = "root";
	mInfo.mNext = mInfo.mPrev = &mInfo;
}

/**
 * @todo: Documentation
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
 * @todo: Documentation
 * @note UNUSED Size: 000050
 */
void AnimFrameCacher::removeOldest()
{
	AnimCacheInfo* oldest = static_cast<AnimCacheInfo*>(mInfo.mPrev);
	mInfo.mPrev->remove();
	*oldest->_0C = nullptr;
	mCache->cacheFree(oldest);
}

/**
 * @todo: Documentation
 */
void AnimFrameCacher::cacheFrameSpace(int numTextures, AnimCacheInfo* info)
{
	u32 texSize = OSRoundDown32B(59 + 4 * numTextures + 64 * numTextures);

	while (true) {
		u32 freeSize = mCache->largestBlockFree();
		if (freeSize > texSize) {
			FrameCacher* alloc       = static_cast<FrameCacher*>(mCache->mallocL(texSize)); // I hate you
			FrameCacher* cacher      = alloc;
			cacher->mBoneMtxList     = &alloc->mBoneMatrices[0];
			cacher->mBoneMatricesEnd = &alloc->mBoneMatrices[numTextures];
			cacher->mInfo            = &info->mCachedMtxBlock;

			for (int boneIdx = 0; boneIdx < numTextures; boneIdx++) {
				cacher->mBoneMtxList[boneIdx] = 0;
			}

			info->mCachedMtxBlock = cacher;
			mInfo.insertAfter(cacher);
			break;
		}

		removeOldest();
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::updateAnim(Graphics& gfx, immut Matrix4f& mtx, f32* overrideFrame)
{
	gsys->mTimer->start("updateAnim", true);
	gsys->mAnimatedPolygons++;
	mAnimMatrices = gfx.getMatrices(mAnimMtxCount);

	if (mCurrentAnimation->mData) {
		if (!overrideFrame) {
			mCurrentAnimation->animate(mCurrentAnimation->mAnimSpeed);
		}

		for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
			AnimData* data = mAnimOverrides[jointIdx]->mData;
			if (!data) {
				ERROR("no joint anim!!\n");
			}
			f32* frame = (overrideFrame) ? overrideFrame : &mAnimOverrides[jointIdx]->mCurrentFrame;

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
				immut Matrix4f* srtMtx
				    = (mJointList[jointIdx].mParentIndex != -1) ? &mAnimMatrices[mJointList[jointIdx].mParentIndex] : &mtx;
				data->makeAnimSRT(data->mAnimJointIndices[jointIdx], srtMtx, &mAnimMatrices[jointIdx], &data->mAnimInfo[jointIdx], *frame);
			} else {
#if defined(WIN32)
				mtx.multiplyTo(mJointList[jointIdx].mAnimMatrix, mAnimMatrices[jointIdx]);
#else
				MTXConcat(mtx.mMtx, mJointList[jointIdx].mAnimMatrix.mMtx, mAnimMatrices[jointIdx].mMtx);
#endif
			}
		}

		calcWeightedMatrices();
	} else {
		Joint* joint = &mJointList[0];
		for (int jointIdx = 0; jointIdx < mJointCount; jointIdx++) {
			SRT srt;
			srt.s = joint->mScale;
			srt.r = joint->mRotation;
			srt.t = joint->mTranslation;
			Matrix4f tmpMtx;
			immut Matrix4f* jointMtx = (joint->mParentIndex == -1) ? &mtx : &mJointList[joint->mParentIndex].mAnimMatrix;
			joint->mAnimMatrix.makeConcatSRT(jointMtx, tmpMtx, srt);
			joint++;
		}
	}

	gsys->mTimer->stop("updateAnim");
}

/**
 * @brief Likely fabricated static inline function useful for DOL-exclusive code in `BaseShape::calcWeightedMatrices`.
 */
static inline void addMatrixWeights(register f32* animMtx, register f32* weightedMtx, register f32 weights[2])
{
#ifdef __MWERKS__
	asm {
		psq_l    f0, 0x00 (weights), 0, 0;

		psq_l    f1, 0x00 (animMtx), 0, 0;
		psq_l    f2, 0x00 (weightedMtx), 0, 0;
		ps_madd  f1, f2, f0, f1;
		psq_st   f1, 0x00 (animMtx), 0, 0;

		psq_l    f3, 0x08 (animMtx), 0, 0;
		psq_l    f2, 0x08 (weightedMtx), 0, 0;
		ps_madd  f3, f2, f0, f3;
		psq_st   f3, 0x08 (animMtx), 0, 0;

		psq_l    f1, 0x10 (animMtx), 0, 0;
		psq_l    f2, 0x10 (weightedMtx), 0, 0;
		ps_madd  f1, f2, f0, f1;
		psq_st   f1, 0x10 (animMtx), 0, 0;

		psq_l    f3, 0x18 (animMtx), 0, 0;
		psq_l    f2, 0x18 (weightedMtx), 0, 0;
		ps_madd  f3, f2, f0, f3;
		psq_st   f3, 0x18 (animMtx), 0, 0;

		psq_l    f1, 0x20 (animMtx), 0, 0;
		psq_l    f2, 0x20 (weightedMtx), 0, 0;
		ps_madd  f1, f2, f0, f1;
		psq_st   f1, 0x20 (animMtx), 0, 0;

		psq_l    f3, 0x28 (animMtx), 0, 0;
		psq_l    f2, 0x28 (weightedMtx), 0, 0;
		ps_madd  f3, f2, f0, f3;
		psq_st   f3, 0x28 (animMtx), 0, 0;
	}
#endif
}

/**
 * @todo: Documentation
 */
void BaseShape::calcWeightedMatrices()
{
	for (int envIdx = 0; envIdx < mEnvelopeCount; envIdx++) {
		f32* animMtxFloats = reinterpret_cast<f32*>(&mAnimMatrices[mJointCount + envIdx].mMtx);
#ifdef WIN32
		for (int count = 0; count < 16; count++)
#else
		for (int count = 0; count < 12; count++)
#endif
		{
			*animMtxFloats = 0.0f;
			animMtxFloats++;
		}

		for (int weightIdx = 0; weightIdx < mEnvelopeList[envIdx].mIndexCount; weightIdx++) {
			int idx    = mEnvelopeList[envIdx].mJointIndices[weightIdx];
			f32 weight = mEnvelopeList[envIdx].mWeights[weightIdx];

			Matrix4f weightedMtx;
			f32* weightedMtxFloats;

#ifdef WIN32
			getAnimMatrix(idx).multiplyTo(mJointList[idx].mInverseAnimMatrix, weightedMtx);
#else
			MTXConcat(getAnimMatrix(idx).mMtx, mJointList[idx].mInverseAnimMatrix.mMtx, weightedMtx.mMtx);
#endif
			weightedMtxFloats = reinterpret_cast<f32*>(&weightedMtx);
			animMtxFloats     = reinterpret_cast<f32*>(&mAnimMatrices[mJointCount + envIdx]);
#if defined(WIN32)
			for (int count = 0; count < 12; count++) {
				*animMtxFloats += *weightedMtxFloats * weight;
				weightedMtxFloats++;
				animMtxFloats++;
			}
#else
			f32 weights[2]   = { weight, weight };
			f32* REF_weights = weights; // This indicates to me that this inline asm was probably not in a static inline, but idc.
			addMatrixWeights(animMtxFloats, weightedMtxFloats, weights);
#endif
		}
	}
}

/**
 * @todo: Documentation
 */
void BaseShape::makeNormalIndexes(u16* indices)
{
	for (int matPolyIdx = 0; matPolyIdx < mTotalMatpolyCount; matPolyIdx++) {
		Joint::MatPoly* matPoly = mMatpolyList[matPolyIdx];
		Mesh* mesh              = &mMeshList[matPoly->mMeshIndex];

		for (int mtxGroupIdx = 0; mtxGroupIdx < mesh->mMtxGroupCount; mtxGroupIdx++) {
			MtxGroup* group    = &mesh->mMtxGroupList[mtxGroupIdx];
			DispList* dispList = group->mDispList;
			for (int dispListIdx = 0; dispListIdx < group->mDispLength; dispListIdx++) {
				u8* data    = dispList->mData;
				u32 dataLen = dispList->mDataLength;

				while (dataLen && data < dispList->mData + dataLen) {
					int first = *data++;
					if (!first) {
						dataLen = 0;
					} else {
						int count = (data[0] << 8) | data[1];
						data += 2;
						for (int vertexCmdIdx = 0; vertexCmdIdx < count; vertexCmdIdx++) {
							u8 unused = 0;
							if (mesh->mFeatureFlags & Mesh::FeatureFlags::PosAndNrm) {
								unused = *data++;
							}

							if (mesh->mFeatureFlags & Mesh::FeatureFlags::Tex1MtxIdx) {
								data++;
							}
							int shift       = 6;
							u16 idxIdx      = u16((data[0] << 8) | data[1]);
							indices[idxIdx] = u16((data[2] << 8) | data[3]);
							if (mesh->mFeatureFlags & Mesh::FeatureFlags::VtxColor) {
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
 * @todo: Documentation
 */
f32 BaseShape::calcJointWorldPos(Graphics& gfx, int jointIdx, Vector3f& worldPos)
{
	if (jointIdx == -1) {
		return 0.0f;
	}

	immut Matrix4f& orig = getAnimMatrix(jointIdx);
	worldPos.multMatrix(getAnimMatrix(jointIdx));
	worldPos.multMatrix(gfx.mCamera->mInverseLookAtMtx);
	return reinterpret_cast<immut Vector3f*>(&orig)->length();
}

/**
 * @todo: Documentation
 */
void BaseShape::calcJointWorldDir(Graphics& gfx, int jointIdx, Vector3f& worldDir)
{
	if (jointIdx != -1) {
		immut Matrix4f& orig = getAnimMatrix(jointIdx); // Clearly copy-pasted, lol.
		worldDir.rotate(getAnimMatrix(jointIdx));
		worldDir.rotate(gfx.mCamera->mInverseLookAtMtx);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000084 (Matching by size)
 */
void BaseShape::calcJointWorldScale(Graphics& gfx, int jointIdx, Vector3f& outVec)
{
	if (jointIdx != -1) {
		immut Matrix4f& animMtx = getAnimMatrix(jointIdx);

		f32 scale = Vector3f(animMtx.mMtx[0][0], animMtx.mMtx[0][1], animMtx.mMtx[0][2]).length();
		outVec.set(scale, scale, scale);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000148 (Nonmatching by size)
 */
CollTriInfo* BaseShape::findCollTri(Vector3f& vtx1, Vector3f& vtx2, Vector3f& vtx3, char*)
{
	Vector3f* searchVertices[3];
	searchVertices[0] = &vtx1;
	searchVertices[1] = &vtx2;
	searchVertices[2] = &vtx3;

	for (int triIdx = 0; triIdx < mTriCount; ++triIdx) {
		for (int windingOffset = 0; windingOffset < 3; ++windingOffset) {
			int verticesSame = 0;
			for (int vertexIdx = 0; vertexIdx < 3; ++vertexIdx) {
				// This complex operation really trips up Ghidra... Pretty sure it's functionally equivalent?
				if (mVertexList[mTriList[triIdx].mVertexIndices[2 - (windingOffset + vertexIdx) % 3]].isSame(*searchVertices[vertexIdx])) {
					++verticesSame;
				}
			}
			if (verticesSame == 3) {
				return &mTriList[triIdx];
			}
		}
	}
	return nullptr;
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
