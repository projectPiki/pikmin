#include "types.h"
#include "Animator.h"
#include "Joint.h"
#include "Mesh.h"
#include "Shape.h"
#include "timers.h"
#include "Colour.h"
#include "Material.h"
#include "Collision.h"
#include "Texture.h"
#include "Vector.h"
#include "CmdStream.h"
#include "String.h"
#include "sysNew.h"
#include "system.h"
#include "PVW.h"
#include "Delegate.h"
#include "CinematicPlayer.h"
#include "Graphics.h"
#include "dolphin/mtx.h"
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
	mIndexCount = stream.readInt();
	mIndices    = new s32[mIndexCount];
	mWeights    = new f32[mIndexCount];
	for (int i = 0; i < mIndexCount; i++) {
		mIndices[i] = stream.readInt();
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
	// if (!this->m_flags)
	// 	return;

	// for (Joint::MatPoly* matPoly = this->m_matpolyE4.m_child; matPoly; matPoly = matPoly->m_next) {
	// 	Mesh* mesh = matPoly->m_mesh;
	// 	if ((graphics->m_dword8 & matPoly->m_material->mFlags) == 0) {
	// 		continue;
	// 	}

	// 	graphics->useMaterial(matPoly->m_material);
	// 	for (int j = 0; j < mesh->m_mtxGroupCount; ++j) {
	// 		MtxGroup* mtxGroup               = &mesh->m_groups[j];
	// 		struct Matrix4f* matrixArray[10] = { &Matrix4f::ident };
	// 		for (int k = 0; k < mtxGroup->m_dependencyCount; ++k) {
	// 			int depIndex = mtxGroup->m_dependancies[k];
	// 			if (depIndex == -1)
	// 				continue;

	// 			VtxMatrix* vtxMatrix = &this->m_shape->m_vtxMatrix[depIndex];
	// 			struct Matrix4f* matrix
	// 			    = this->m_shape->m_currentAnims->m_state
	// 			        ? BaseShape::getAnimMatrix(this->m_shape,
	// 			                                   vtxMatrix->m_index + (vtxMatrix->m_partiallyWeighted ? 0 : this->m_shape->m_jointCount))
	// 			        : &this->m_shape->m_joints[vtxMatrix->m_index].m_animMatrix;
	// 			matrixArray[k] = matrix;
	// 		}
	// 		Vector3f* vertices  = this->m_shape->m_vertices;
	// 		Vector2f* texCoords = this->m_shape->m_texCoords[0];
	// 		Vector3f* normal    = (mesh->m_vcd & 0x10000) != 0 ? this->m_shape->m_nbt : this->m_shape->m_normals;
	// 		int normalStride    = (mesh->m_vcd & 0x10000) != 0 ? 3 : 1;
	// 		DispList* dispList  = mtxGroup->m_dispLists;
	// 		for (int l = 0; l < mtxGroup->m_dispListCount; ++l, dispList++) {
	// 			graphics->setCullFront(graphics->m_dword338 ^ dispList->m_flags & 3);

	// 			for (FaceNode* faceNode = dispList->m_face.m_child; faceNode; faceNode = faceNode->m_next) {
	// 				int* vertexIndex   = faceNode->m_vtxIdx;
	// 				int* matrixIndex   = faceNode->m_mtxIdx;
	// 				int* normalIndex   = faceNode->m_nrmIdx;
	// 				int* texCoordIndex = faceNode->m_texcoords[0];
	// 				for (int n = 0; n < faceNode->m_faceCount; ++n) {
	// 					struct Matrix4f* matrix            = matrixIndex ? matrixArray[*matrixIndex++] : matrixArray[0];
	// 					Vector3f* vertex                   = &vertices[*vertexIndex++];
	// 					struct Vector3f* transformedVertex = &unk_101C8B68++;
	// 					vertex->multMatrixTo(matrix, transformedVertex);
	// 					if (normalIndex) {
	// 						Vector3f* normalPtr                = &normal[normalStride * *normalIndex++];
	// 						struct Vector3f* transformedNormal = &unk_101C7368++;
	// 						normalPtr->rotateTo(matrix, transformedNormal);
	// 					}
	// 					if (texCoordIndex) {
	// 						Vector3f* texCoord = &unk_101C6368++; // Assuming unk_101C6368 is a pointer to a
	// 						                                      // Vector3f or similar structure for texture
	// 						                                      // coordinates
	// 						texCoord->x = texCoords[*texCoordIndex].m_x;
	// 						texCoord->y = texCoords[*texCoordIndex++].m_y;
	// 					}
	// 				}
	// 				if (dispList->m_flags & 0x1000000) {
	// 					graphics->drawOneStrip(&unk_101C8B68, normalIndex ? &unk_101C7368 : 0, texCoordIndex ? &unk_101C6368 : 0,
	// 					                       faceNode->m_faceCount);
	// 				} else {
	// 					graphics->drawOneTri(&unk_101C8B68, normalIndex ? &unk_101C7368 : 0, texCoordIndex ? &unk_101C6368 : 0,
	// 					                     faceNode->m_faceCount);
	// 				}
	// 			}
	// 		}
	// 	}
	// 	graphics->useMaterial(nullptr);
	// }
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
	if (frame >= mData->mNumFrames) {
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

	f32 f2;
	f32 f4;
	f32 f7;
	f32 f8;
	f32 f9;
	f32 f0;
	if (dataSize == 3) {
		f4 = data.mData[offset];
		f8 = data.mData[offset + 2];
		f7 = data.mData[offset + 1];
		offset += dataSize;
		f2 = data.mData[offset];
		f0 = data.mData[offset + 2];
		f9 = data.mData[offset + 1];

	} else {
		f4 = data.mData[offset];
		f7 = data.mData[offset + 1];
		f8 = data.mData[offset + 3];
		offset += dataSize;
		f2 = data.mData[offset];
		f9 = data.mData[offset + 1];
		f0 = data.mData[offset + 2];
	}

	// Interpolation calculations
	f32 t          = (currTime - f4) * (1.0f / 30.0f);
	f32 frameDelta = 30.0f / (f2 - f4);
	f32 tSqr       = t * t;
	f32 deltaSqr   = frameDelta * frameDelta;
	f32 tCube      = tSqr * t;
	f32 deltaCube  = deltaSqr * frameDelta;

	return (2.0f * tCube * deltaCube - 3.0f * tSqr * deltaSqr + 1.0f) * f7 + (-2.0f * tCube * deltaCube + 3.0f * tSqr * deltaSqr) * f9
	     + (tCube * deltaSqr - 2.0f * tSqr * frameDelta + t) * f8 + (tCube * deltaSqr - tSqr * frameDelta) * f0;

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
	_2C                  = 0;
};

/*
 * --INFO--
 * Address:	8002A998
 * Size:	000334
 */
void CamDataInfo::update(f32 p1, Matrix4f& mtx)
{
	f32 vals[2];
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
			vals[i + 1] = 1.0f;
			break;
		case 1:
			vals[i + 1] = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			vals[i + 1] = extract(p1, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
	}

	AnimParam* params4 = mCamFovyAnims;
	for (int i = 0; i < 1; i++) {
		AnimParam& thisParam = params4[i];
		switch (thisParam.mEntryNum) {
		case 0:
			vals[i] = 1.0f;
			break;
		case 1:
			vals[i] = mSceneData->mCameraAnimations->mData[thisParam.mDataOffset];
			break;
		default:
			vals[i] = extract(p1, thisParam, *mSceneData->mCameraAnimations);
			break;
		}
	}

	mCamera.mPosition.multMatrix(mtx);
	mCamera.mFocus.multMatrix(mtx);
	mCamera.mFov = vals[0];

	if (_28 > 0.0f) {
		mCamera.mFov = (_24 - mCamera.mFov) * _28 + mCamera.mFov;

		mCamera.mPosition.x += (_00.x - mCamera.mPosition.x) * _28;
		mCamera.mPosition.y += (_00.y - mCamera.mPosition.y) * _28;
		mCamera.mPosition.z += (_00.z - mCamera.mPosition.z) * _28;

		mCamera.mFocus.x += (_0C.x - mCamera.mFocus.x) * _28;
		mCamera.mFocus.y += (_0C.y - mCamera.mFocus.y) * _28;
		mCamera.mFocus.z += (_0C.z - mCamera.mFocus.z) * _28;

	} else if (_2C) {
		mCamera.mFocus = _18;
	}

	mCamera.calcLookAt(mCamera.mPosition, mCamera.mFocus, nullptr);

	u32 badCompiler[4];
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x68(r1)
	  stfd      f31, 0x60(r1)
	  stfd      f30, 0x58(r1)
	  fmr       f30, f1
	  stmw      r27, 0x44(r1)
	  mr        r30, r3
	  addi      r31, r4, 0
	  addi      r29, r30, 0x30
	  addi      r28, r30, 0x20C
	  li        r27, 0
	  lfs       f31, -0x7D20(r2)

	.loc_0x34:
	  lwz       r0, 0x0(r29)
	  addi      r3, r29, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x5C
	  bge-      .loc_0x7C
	  cmpwi     r0, 0
	  bge-      .loc_0x54
	  b         .loc_0x7C

	.loc_0x54:
	  stfs      f31, 0x0(r28)
	  b         .loc_0x90

	.loc_0x5C:
	  lwz       r3, 0x3F4(r30)
	  lwz       r0, 0x4(r29)
	  lwz       r3, 0x14(r3)
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r3)
	  lfsx      f0, r3, r0
	  stfs      f0, 0x0(r28)
	  b         .loc_0x90

	.loc_0x7C:
	  lwz       r4, 0x3F4(r30)
	  fmr       f1, f30
	  lwz       r4, 0x14(r4)
	  bl        -0x2C8
	  stfs      f1, 0x0(r28)

	.loc_0x90:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x3
	  addi      r29, r29, 0xC
	  addi      r28, r28, 0x4
	  blt+      .loc_0x34
	  lfs       f31, -0x7D20(r2)
	  addi      r28, r30, 0x54
	  addi      r29, r30, 0x218
	  li        r27, 0

	.loc_0xB4:
	  lwz       r0, 0x0(r28)
	  addi      r3, r28, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0xDC
	  bge-      .loc_0xFC
	  cmpwi     r0, 0
	  bge-      .loc_0xD4
	  b         .loc_0xFC

	.loc_0xD4:
	  stfs      f31, 0x0(r29)
	  b         .loc_0x110

	.loc_0xDC:
	  lwz       r3, 0x3F4(r30)
	  lwz       r0, 0x4(r28)
	  lwz       r3, 0x14(r3)
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r3)
	  lfsx      f0, r3, r0
	  stfs      f0, 0x0(r29)
	  b         .loc_0x110

	.loc_0xFC:
	  lwz       r4, 0x3F4(r30)
	  fmr       f1, f30
	  lwz       r4, 0x14(r4)
	  bl        -0x348
	  stfs      f1, 0x0(r29)

	.loc_0x110:
	  addi      r27, r27, 0x1
	  cmpwi     r27, 0x3
	  addi      r28, r28, 0xC
	  addi      r29, r29, 0x4
	  blt+      .loc_0xB4
	  lwz       r0, 0x78(r30)
	  addi      r28, r30, 0x78
	  lfs       f0, -0x7D0C(r2)
	  addi      r3, r28, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x154
	  bge-      .loc_0x174
	  cmpwi     r0, 0
	  bge-      .loc_0x14C
	  b         .loc_0x174

	.loc_0x14C:
	  stfs      f0, 0x38(r1)
	  b         .loc_0x188

	.loc_0x154:
	  lwz       r3, 0x3F4(r30)
	  lwz       r0, 0x4(r28)
	  lwz       r3, 0x14(r3)
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r3)
	  lfsx      f0, r3, r0
	  stfs      f0, 0x38(r1)
	  b         .loc_0x188

	.loc_0x174:
	  lwz       r4, 0x3F4(r30)
	  fmr       f1, f30
	  lwz       r4, 0x14(r4)
	  bl        -0x3C0
	  stfs      f1, 0x38(r1)

	.loc_0x188:
	  lwz       r0, 0x84(r30)
	  addi      r28, r30, 0x84
	  lfs       f0, -0x7D0C(r2)
	  addi      r3, r28, 0
	  cmpwi     r0, 0x1
	  beq-      .loc_0x1B8
	  bge-      .loc_0x1D8
	  cmpwi     r0, 0
	  bge-      .loc_0x1B0
	  b         .loc_0x1D8

	.loc_0x1B0:
	  stfs      f0, 0x34(r1)
	  b         .loc_0x1EC

	.loc_0x1B8:
	  lwz       r3, 0x3F4(r30)
	  lwz       r0, 0x4(r28)
	  lwz       r3, 0x14(r3)
	  rlwinm    r0,r0,2,0,29
	  lwz       r3, 0x8(r3)
	  lfsx      f0, r3, r0
	  stfs      f0, 0x34(r1)
	  b         .loc_0x1EC

	.loc_0x1D8:
	  lwz       r4, 0x3F4(r30)
	  fmr       f1, f30
	  lwz       r4, 0x14(r4)
	  bl        -0x424
	  stfs      f1, 0x34(r1)

	.loc_0x1EC:
	  addi      r4, r31, 0
	  addi      r3, r30, 0x20C
	  bl        0xCBC0
	  addi      r3, r30, 0x218
	  addi      r4, r31, 0
	  bl        0xCBB4
	  lfs       f0, 0x34(r1)
	  stfs      f0, 0x274(r30)
	  lfs       f1, 0x28(r30)
	  lfs       f0, -0x7D20(r2)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2E0
	  lfs       f2, 0x274(r30)
	  lfs       f0, 0x24(r30)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x274(r30)
	  lfs       f2, 0x20C(r30)
	  lfs       f0, 0x0(r30)
	  lfs       f1, 0x28(r30)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x20C(r30)
	  lfs       f2, 0x210(r30)
	  lfs       f0, 0x4(r30)
	  lfs       f1, 0x28(r30)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x210(r30)
	  lfs       f2, 0x214(r30)
	  lfs       f0, 0x8(r30)
	  lfs       f1, 0x28(r30)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x214(r30)
	  lfs       f2, 0x218(r30)
	  lfs       f0, 0xC(r30)
	  lfs       f1, 0x28(r30)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x218(r30)
	  lfs       f2, 0x21C(r30)
	  lfs       f0, 0x10(r30)
	  lfs       f1, 0x28(r30)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x21C(r30)
	  lfs       f2, 0x220(r30)
	  lfs       f0, 0x14(r30)
	  lfs       f1, 0x28(r30)
	  fsubs     f0, f0, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  stfs      f0, 0x220(r30)
	  b         .loc_0x304

	.loc_0x2E0:
	  lbz       r0, 0x2C(r30)
	  cmplwi    r0, 0
	  beq-      .loc_0x304
	  lwz       r3, 0x18(r30)
	  lwz       r0, 0x1C(r30)
	  stw       r3, 0x218(r30)
	  stw       r0, 0x21C(r30)
	  lwz       r0, 0x20(r30)
	  stw       r0, 0x220(r30)

	.loc_0x304:
	  addi      r3, r30, 0xA8
	  addi      r4, r30, 0x20C
	  addi      r5, r30, 0x218
	  li        r6, 0
	  bl        0x18360
	  lmw       r27, 0x44(r1)
	  lwz       r0, 0x6C(r1)
	  lfd       f31, 0x60(r1)
	  lfd       f30, 0x58(r1)
	  addi      r1, r1, 0x68
	  mtlr      r0
	  blr
	*/
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

	_54 = ((f32*)&vec2)[-1] == 1.0f;

	if (_54) {
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
void AnimData::makeAnimSRT(int p1, Matrix4f* p2, Matrix4f* p3, AnimDataInfo* info, f32 p5)
{
	int frameNum = p5;
	if (frameNum < 0 || frameNum > mNumFrames) {
		ERROR("makeSRT too large a frame number : %d / %d : %f\n", frameNum, mNumFrames, p5);
	}

	Matrix4f mtx;
	bool check = true;
	Matrix4f* mtxPtr;
	if ((info->mFlags & 0x777) != 0x777 && mAnimInfoList[frameNum]._10) {
		AnimCacheInfo* cache = (AnimCacheInfo*)mAnimInfoList[frameNum]._10;
		if (cache->_18[p1]) {
			check = false;
		} else {
			cache->_18[p1] = &cache->_14[p1];
		}
		mtxPtr = cache->_18[p1];
	} else {
		mtxPtr = &mtx;
	}

	if (check) {
		SRT& srt = info->mSRT;
		extractSRT(info->mSRT, p1, info, p5);
		if ((info->mFlags & 0x777) == 0x777) {
			mtxPtr = &info->mMtx;
			if (!(info->mFlags & 0x8000)) {
				mtxPtr->makeSRT(srt.mScale, srt.mRotation, srt.mTranslation);
				info->mFlags |= 0x8000;
			}
		} else {
			p3->makeConcatSRT(p2, *mtxPtr, srt);
			return;
		}
	}

	PSMTXConcat(p2->mMtx, mtxPtr->mMtx, p3->mMtx);
}

/*
 * --INFO--
 * Address:	8002C40C
 * Size:	00003C
 */
void AnimData::detach()
{
	for (int i = 0; i < mNumFrames; i++) {
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
	mAnimInfoList = new AnimCacheInfo[mNumFrames];
}

/*
 * --INFO--
 * Address:	8002C458
 * Size:	00025C
 */
void AnimData::checkMask()
{
	for (int i = 0; i < mNumJoints; i++) {
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

	_20                  = new u16[mNumJoints];
	int jointCount       = 0;
	int unusedJointCount = 0;

	for (int i = 0; i < mNumJoints; i++) {
		if (i >= mModel->mJointCount) {
			continue;
		}

		if ((mAnimInfo[i].mFlags & 0x777) != 0x777) {
			_20[i] = jointCount++;
		} else {
			_20[i] = 0;
			unusedJointCount++;
		}
	}

	_2C = mNumJoints - unusedJointCount;
}

/*
 * --INFO--
 * Address:	8002C6B4
 * Size:	0003D4
 */
void AnimDca::read(RandomAccessStream& input)
{
	mNumJoints = input.readInt();
	mNumFrames = input.readInt();

	mScaleDataBlock = new DataChunk();
	mScaleDataBlock->read(input);

	mRotateDataBlock = new DataChunk();
	mRotateDataBlock->read(input);

	mTranslationDataBlock = new DataChunk();
	mTranslationDataBlock->read(input);

	mAnimInfo = new AnimDataInfo[mNumJoints];

	for (int i = 0; i < mNumJoints; i++) {
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
			sscanf(stream->getToken(true), "%d", &mNumJoints);
			mAnimInfo = new AnimDataInfo[mNumJoints];

			for (int i = 0; i < mNumJoints; i++) {
				mAnimInfo[i].mGroupIndex = i;
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
 * Address:	8002D69C
 * Size:	00010C
 */
AnimDck::AnimDck(BaseShape* model, int joints)
{
	mModel     = model;
	mNumJoints = joints;
	mNumFrames = 0;
	mAnimInfo  = new AnimDataInfo[mNumJoints];

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
	mNumJoints = stream.readInt();
	mNumFrames = stream.readInt();

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
	mAnimInfo = new AnimDataInfo[mNumJoints];
	for (int i = 0; i < mNumJoints; i++) {
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

	for (int i = 0; i < mNumJoints; i++) {
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
			sscanf(stream->getToken(true), "%d", &mNumJoints);
			mAnimInfo = new AnimDataInfo[mNumJoints];
			for (int i = 0; i < mNumJoints; i++) {
				mAnimInfo[i].mGroupIndex = i;
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
					mat.mTevInfo->mTevColRegs[j].animate(data, mat.mTevInfo->mTevColRegs[j]._00);
				}
			}

			for (int j = 0; j < mat.mTextureInfo.mTextureDataCount; j++) {
				if (mat.mTextureInfo.mTextureData[j]._14 != 255) {
					mat.mTextureInfo.mTextureData[j].animate(data, mat.mTextureInfo.mTextureData[j]._5C);
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
					mShape->mMaterialList[mat.mIndex].mTevInfo->mTevColRegs[j]._00 = mat.mTevInfo->mTevColRegs[j]._00;
				}
			}

			for (int j = 0; j < mat.mTextureInfo.mTextureDataCount; j++) {
				if (mat.mTextureInfo.mTextureData[j]._14 != 255) {
					mShape->mMaterialList[mat.mIndex].mTextureInfo.mTextureData[j]._5C = mat.mTextureInfo.mTextureData[j]._5C;
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
	mNbtList              = 0;

	mTexCoordList[0] = nullptr;
	mTexCoordList[1] = nullptr;
	mTexCoordList[2] = nullptr;
	mTexCoordList[3] = nullptr;
	mTexCoordList[4] = nullptr;
	mTexCoordList[5] = nullptr;
	mTexCoordList[6] = nullptr;
	mTexCoordList[7] = nullptr;

	mNormalList       = nullptr;
	_298              = 0;
	_29C              = 0;
	mAttrListMatCount = 0;
	_2A0              = 0;
	_2A8              = 0;

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
					for (int j = 0; j < mat->mTextureInfo.mTextureDataCount; j++) {
						if (mat->mTextureInfo.mTextureData[j]._14 != 255) {
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
void BaseShape::drawculled(Graphics&, Camera&, ShapeDynMaterials*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x188(r1)
	  stfd      f31, 0x180(r1)
	  stfd      f30, 0x178(r1)
	  stfd      f29, 0x170(r1)
	  stmw      r19, 0x13C(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  mr        r3, r28
	  addi      r29, r5, 0
	  addi      r19, r6, 0
	  lwz       r12, 0x3B4(r28)
	  lwz       r31, 0xC(r4)
	  addi      r4, r27, 0
	  lwz       r12, 0x7C(r12)
	  mtlr      r12
	  blrl
	  cmplwi    r19, 0
	  beq-      .loc_0x68
	  b         .loc_0x60

	.loc_0x54:
	  mr        r3, r19
	  bl        -0xBBC
	  lwz       r19, 0x0(r19)

	.loc_0x60:
	  cmplwi    r19, 0
	  bne+      .loc_0x54

	.loc_0x68:
	  lfs       f29, -0x7D20(r2)
	  li        r21, 0
	  li        r23, 0
	  lis       r25, 0x1
	  b         .loc_0x2C8

	.loc_0x7C:
	  lwz       r4, 0x4(r29)
	  mr        r5, r29
	  lwz       r3, 0x5C(r27)
	  subi      r0, r25, 0x7FC1
	  cmpwi     r4, 0
	  add       r8, r3, r23
	  mtctr     r4
	  addi      r4, r8, 0xCC
	  li        r3, 0
	  ble-      .loc_0x254

	.loc_0xA4:
	  lwz       r6, 0x114(r5)
	  lbz       r7, 0x28(r6)
	  cmplwi    r7, 0
	  beq-      .loc_0x248
	  li        r7, 0x1
	  slw       r7, r7, r3
	  and.      r9, r0, r7
	  beq-      .loc_0x248
	  lbz       r9, 0x154(r29)
	  cmplwi    r9, 0
	  beq-      .loc_0x1A0
	  lwz       r10, 0x1C(r6)
	  lwz       r9, 0x20(r6)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x24(r6)
	  rlwinm    r9,r9,2,0,29
	  lfs       f5, 0x158(r29)
	  lfsx      f1, r4, r10
	  rlwinm    r10,r11,2,0,29
	  lfs       f3, 0x15C(r29)
	  lfsx      f0, r4, r9
	  fadds     f1, f5, f1
	  lfs       f6, 0x0(r6)
	  fadds     f0, f3, f0
	  lfs       f4, 0x4(r6)
	  lfs       f7, 0x160(r29)
	  lfsx      f2, r4, r10
	  fmuls     f1, f6, f1
	  fmuls     f0, f4, f0
	  lfs       f8, 0x8(r6)
	  fadds     f2, f7, f2
	  lfs       f9, 0xC(r6)
	  fadds     f0, f1, f0
	  fmuls     f1, f8, f2
	  fadds     f0, f1, f0
	  fsubs     f0, f0, f9
	  fcmpo     cr0, f0, f29
	  bge-      .loc_0x144
	  li        r0, 0
	  b         .loc_0x254

	.loc_0x144:
	  lwz       r10, 0x10(r6)
	  lwz       r9, 0x14(r6)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x18(r6)
	  rlwinm    r6,r9,2,0,29
	  lfsx      f1, r4, r10
	  lfsx      f0, r4, r6
	  rlwinm    r6,r11,2,0,29
	  fadds     f1, f5, f1
	  lfsx      f2, r4, r6
	  fadds     f0, f3, f0
	  fadds     f2, f7, f2
	  fmuls     f1, f6, f1
	  fmuls     f0, f4, f0
	  fmuls     f2, f8, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fsubs     f0, f0, f9
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x248
	  andc      r0, r0, r7
	  b         .loc_0x248

	.loc_0x1A0:
	  lwz       r10, 0x1C(r6)
	  lwz       r9, 0x20(r6)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x24(r6)
	  rlwinm    r9,r9,2,0,29
	  lfs       f4, 0x0(r6)
	  lfsx      f1, r4, r10
	  rlwinm    r10,r11,2,0,29
	  lfs       f3, 0x4(r6)
	  lfsx      f0, r4, r9
	  fmuls     f1, f4, f1
	  lfs       f5, 0x8(r6)
	  fmuls     f0, f3, f0
	  lfsx      f2, r4, r10
	  lfs       f6, 0xC(r6)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fsubs     f0, f0, f6
	  fcmpo     cr0, f0, f29
	  bge-      .loc_0x1FC
	  li        r0, 0
	  b         .loc_0x254

	.loc_0x1FC:
	  lwz       r10, 0x10(r6)
	  lwz       r9, 0x14(r6)
	  rlwinm    r10,r10,2,0,29
	  lwz       r11, 0x18(r6)
	  rlwinm    r6,r9,2,0,29
	  lfsx      f1, r4, r10
	  lfsx      f0, r4, r6
	  rlwinm    r6,r11,2,0,29
	  fmuls     f1, f4, f1
	  lfsx      f2, r4, r6
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fsubs     f0, f0, f6
	  fcmpo     cr0, f0, f29
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x248
	  andc      r0, r0, r7

	.loc_0x248:
	  addi      r5, r5, 0x4
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0xA4

	.loc_0x254:
	  cmpwi     r0, 0
	  beq-      .loc_0x2B8
	  lwz       r3, 0x60(r27)
	  subi      r0, r3, 0x1
	  mr        r20, r0
	  rlwinm    r19,r0,2,0,29
	  b         .loc_0x2AC

	.loc_0x270:
	  lwz       r3, 0x64(r27)
	  lwz       r0, 0x5C(r27)
	  lwzx      r5, r3, r19
	  add       r0, r0, r23
	  lwz       r3, 0x24(r5)
	  cmplw     r3, r0
	  bne-      .loc_0x2A4
	  lwz       r12, 0x3B4(r28)
	  mr        r3, r28
	  mr        r4, r27
	  lwz       r12, 0x80(r12)
	  mtlr      r12
	  blrl

	.loc_0x2A4:
	  subi      r19, r19, 0x4
	  subi      r20, r20, 0x1

	.loc_0x2AC:
	  cmpwi     r20, 0
	  bge+      .loc_0x270
	  b         .loc_0x2C0

	.loc_0x2B8:
	  li        r0, -0x1
	  stw       r0, 0x114(r8)

	.loc_0x2C0:
	  addi      r23, r23, 0x11C
	  addi      r21, r21, 0x1

	.loc_0x2C8:
	  lwz       r0, 0x58(r27)
	  cmpw      r21, r0
	  blt+      .loc_0x7C
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x758
	  li        r30, 0
	  lfs       f31, -0x7D20(r2)
	  mulli     r22, r30, 0x11C
	  lfs       f29, -0x7CE8(r2)
	  lfs       f30, -0x7CF0(r2)
	  lis       r3, 0x803A
	  subi      r26, r3, 0x77C0
	  addi      r23, r1, 0x1C
	  addi      r24, r1, 0x20
	  lis       r25, 0x1
	  b         .loc_0x74C

	.loc_0x310:
	  mr        r3, r28
	  lwz       r4, 0x2E4(r28)
	  lwz       r12, 0x3B4(r28)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0xCC(r12)
	  mtlr      r12
	  blrl
	  li        r6, 0xFF
	  stb       r6, 0x20(r1)
	  li        r0, 0x20
	  addi      r3, r28, 0
	  stb       r0, 0x21(r1)
	  addi      r4, r24, 0
	  li        r5, 0x1
	  stb       r0, 0x22(r1)
	  stb       r6, 0x23(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x5C(r27)
	  addi      r4, r3, 0
	  addi      r3, r22, 0xCC
	  addi      r19, r4, 0
	  addi      r4, r28, 0
	  add       r3, r0, r3
	  bl        0x8850
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r19, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r31, 0
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x4(r29)
	  addi      r21, r22, 0xCC
	  lwz       r0, 0x5C(r27)
	  addi      r4, r29, 0
	  cmpwi     r3, 0
	  mtctr     r3
	  add       r21, r0, r21
	  subi      r0, r25, 0x7FC1
	  li        r3, 0
	  ble-      .loc_0x5C8

	.loc_0x418:
	  lwz       r5, 0x114(r4)
	  lbz       r6, 0x28(r5)
	  cmplwi    r6, 0
	  beq-      .loc_0x5BC
	  li        r6, 0x1
	  slw       r6, r6, r3
	  and.      r7, r0, r6
	  beq-      .loc_0x5BC
	  lbz       r7, 0x154(r29)
	  cmplwi    r7, 0
	  beq-      .loc_0x514
	  lwz       r8, 0x1C(r5)
	  lwz       r7, 0x20(r5)
	  rlwinm    r8,r8,2,0,29
	  lwz       r9, 0x24(r5)
	  rlwinm    r7,r7,2,0,29
	  lfs       f5, 0x158(r29)
	  lfsx      f1, r21, r8
	  rlwinm    r8,r9,2,0,29
	  lfs       f3, 0x15C(r29)
	  lfsx      f0, r21, r7
	  fadds     f1, f5, f1
	  lfs       f6, 0x0(r5)
	  fadds     f0, f3, f0
	  lfs       f4, 0x4(r5)
	  lfs       f7, 0x160(r29)
	  lfsx      f2, r21, r8
	  fmuls     f1, f6, f1
	  fmuls     f0, f4, f0
	  lfs       f8, 0x8(r5)
	  fadds     f2, f7, f2
	  lfs       f9, 0xC(r5)
	  fadds     f0, f1, f0
	  fmuls     f1, f8, f2
	  fadds     f0, f1, f0
	  fsubs     f0, f0, f9
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x4B8
	  li        r0, 0
	  b         .loc_0x5C8

	.loc_0x4B8:
	  lwz       r8, 0x10(r5)
	  lwz       r7, 0x14(r5)
	  rlwinm    r8,r8,2,0,29
	  lwz       r9, 0x18(r5)
	  rlwinm    r5,r7,2,0,29
	  lfsx      f1, r21, r8
	  lfsx      f0, r21, r5
	  rlwinm    r5,r9,2,0,29
	  fadds     f1, f5, f1
	  lfsx      f2, r21, r5
	  fadds     f0, f3, f0
	  fadds     f2, f7, f2
	  fmuls     f1, f6, f1
	  fmuls     f0, f4, f0
	  fmuls     f2, f8, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fsubs     f0, f0, f9
	  fcmpo     cr0, f0, f31
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x5BC
	  andc      r0, r0, r6
	  b         .loc_0x5BC

	.loc_0x514:
	  lwz       r8, 0x1C(r5)
	  lwz       r7, 0x20(r5)
	  rlwinm    r8,r8,2,0,29
	  lwz       r9, 0x24(r5)
	  rlwinm    r7,r7,2,0,29
	  lfs       f4, 0x0(r5)
	  lfsx      f1, r21, r8
	  rlwinm    r8,r9,2,0,29
	  lfs       f3, 0x4(r5)
	  lfsx      f0, r21, r7
	  fmuls     f1, f4, f1
	  lfs       f5, 0x8(r5)
	  fmuls     f0, f3, f0
	  lfsx      f2, r21, r8
	  lfs       f6, 0xC(r5)
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fsubs     f0, f0, f6
	  fcmpo     cr0, f0, f31
	  bge-      .loc_0x570
	  li        r0, 0
	  b         .loc_0x5C8

	.loc_0x570:
	  lwz       r8, 0x10(r5)
	  lwz       r7, 0x14(r5)
	  rlwinm    r8,r8,2,0,29
	  lwz       r9, 0x18(r5)
	  rlwinm    r5,r7,2,0,29
	  lfsx      f1, r21, r8
	  lfsx      f0, r21, r5
	  rlwinm    r5,r9,2,0,29
	  fmuls     f1, f4, f1
	  lfsx      f2, r21, r5
	  fmuls     f0, f3, f0
	  fmuls     f2, f5, f2
	  fadds     f0, f1, f0
	  fadds     f0, f2, f0
	  fsubs     f0, f0, f6
	  fcmpo     cr0, f0, f31
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x5BC
	  andc      r0, r0, r6

	.loc_0x5BC:
	  addi      r4, r4, 0x4
	  addi      r3, r3, 0x1
	  bdnz+     .loc_0x418

	.loc_0x5C8:
	  cmpwi     r0, 0
	  beq-      .loc_0x744
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x3B4(r28)
	  mr        r20, r0
	  addi      r4, r26, 0
	  lwz       r12, 0x74(r12)
	  li        r5, 0
	  mtlr      r12
	  blrl
	  li        r0, 0xFF
	  stb       r0, 0x1C(r1)
	  addi      r3, r28, 0
	  addi      r4, r23, 0
	  stb       r0, 0x1D(r1)
	  li        r5, 0x1
	  stb       r0, 0x1E(r1)
	  stb       r0, 0x1F(r1)
	  lwz       r12, 0x3B4(r28)
	  lwz       r12, 0xA8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  li        r4, 0
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  lfs       f3, 0x10(r21)
	  mr        r19, r3
	  lfs       f2, 0x4(r21)
	  addi      r3, r1, 0x124
	  lfs       f1, 0xC(r21)
	  lfs       f0, 0x0(r21)
	  fadds     f2, f3, f2
	  lfs       f3, 0x14(r21)
	  fadds     f0, f1, f0
	  fmuls     f1, f29, f2
	  lfs       f2, 0x8(r21)
	  fmuls     f0, f29, f0
	  fadds     f2, f3, f2
	  fadds     f1, f30, f1
	  stfs      f0, 0x124(r1)
	  fmuls     f0, f29, f2
	  stfs      f1, 0x128(r1)
	  stfs      f0, 0x12C(r1)
	  lwz       r4, 0x2E4(r28)
	  addi      r4, r4, 0x1E0
	  bl        0x73B0
	  lwz       r4, 0x5C(r27)
	  addi      r0, r22, 0x114
	  addi      r3, r1, 0x24
	  crclr     6, 0x6
	  lwzx      r5, r4, r0
	  subi      r4, r13, 0x7C94
	  bl        0x1E61E0
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x24
	  lwz       r3, 0x10(r3)
	  bl        -0x8294
	  lwz       r12, 0x3B4(r28)
	  srawi     r0, r3, 0x1
	  lwz       r4, 0x2DEC(r13)
	  addze     r0, r0
	  lwz       r12, 0xF0(r12)
	  lwz       r4, 0x10(r4)
	  addi      r3, r28, 0
	  mtlr      r12
	  neg       r6, r0
	  addi      r5, r1, 0x124
	  crclr     6, 0x6
	  addi      r8, r1, 0x24
	  li        r7, 0
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  mr        r4, r19
	  lwz       r12, 0x60(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x3B4(r28)
	  addi      r4, r20, 0
	  li        r5, 0
	  lwz       r12, 0x30(r12)
	  mtlr      r12
	  blrl

	.loc_0x744:
	  addi      r22, r22, 0x11C
	  addi      r30, r30, 0x1

	.loc_0x74C:
	  lwz       r0, 0x58(r27)
	  cmpw      r30, r0
	  blt+      .loc_0x310

	.loc_0x758:
	  lmw       r19, 0x13C(r1)
	  lwz       r0, 0x18C(r1)
	  lfd       f31, 0x180(r1)
	  lfd       f30, 0x178(r1)
	  lfd       f29, 0x170(r1)
	  addi      r1, r1, 0x188
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003046C
 * Size:	0001A0
 */
void BaseShape::drawshape(Graphics&, Camera&, ShapeDynMaterials*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  mr        r28, r3
	  mr        r29, r4
	  addi      r30, r5, 0
	  addi      r26, r6, 0
	  lwz       r0, 0x50(r3)
	  lwz       r31, 0x4(r4)
	  cmpwi     r0, 0
	  beq-      .loc_0x188
	  lwz       r3, 0x14(r28)
	  rlwinm.   r0,r3,0,29,29
	  bne-      .loc_0x68
	  rlwinm.   r0,r3,0,30,30
	  beq-      .loc_0x68
	  rlwinm.   r0,r31,0,21,21
	  beq-      .loc_0x68
	  addi      r3, r29, 0
	  addi      r4, r28, 0
	  addi      r5, r26, 0
	  bl        -0x7F7C
	  lwz       r0, 0x4(r29)
	  rlwinm    r0,r0,0,22,20
	  stw       r0, 0x4(r29)

	.loc_0x68:
	  lwz       r0, 0x14(r28)
	  rlwinm.   r0,r0,0,29,29
	  bne-      .loc_0x80
	  lwz       r0, 0x4(r29)
	  andi.     r0, r0, 0x8300
	  beq-      .loc_0x188

	.loc_0x80:
	  cmplwi    r26, 0
	  beq-      .loc_0xA0
	  b         .loc_0x98

	.loc_0x8C:
	  mr        r3, r26
	  bl        -0x136C
	  lwz       r26, 0x0(r26)

	.loc_0x98:
	  cmplwi    r26, 0
	  bne+      .loc_0x8C

	.loc_0xA0:
	  mr        r3, r29
	  lwz       r26, 0xC(r29)
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r30, 0
	  addi      r5, r28, 0
	  lwz       r12, 0x84(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r26, 0
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r26, 0x8C(r28)
	  lwz       r27, 0xC(r29)
	  cmplwi    r26, 0
	  beq-      .loc_0x10C
	  b         .loc_0x104

	.loc_0xF0:
	  addi      r3, r26, 0
	  addi      r4, r29, 0
	  addi      r5, r27, 0
	  bl        0x59F0
	  lwz       r26, 0xC(r26)

	.loc_0x104:
	  cmplwi    r26, 0
	  bne+      .loc_0xF0

	.loc_0x10C:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x20(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x188
	  lwz       r0, 0x4(r29)
	  rlwinm.   r0,r0,0,21,21
	  beq-      .loc_0x188
	  mr        r3, r29
	  lwz       r4, 0x2E4(r29)
	  lwz       r12, 0x3B4(r29)
	  li        r5, 0
	  addi      r4, r4, 0x1E0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  lwz       r27, 0x188(r28)
	  b         .loc_0x180

	.loc_0x150:
	  mr        r3, r29
	  lwz       r12, 0x3B4(r29)
	  addi      r4, r30, 0x1E0
	  li        r5, 0
	  lwz       r12, 0x74(r12)
	  mtlr      r12
	  blrl
	  addi      r3, r27, 0
	  addi      r4, r29, 0
	  addi      r5, r27, 0
	  bl        0x6198
	  lwz       r27, 0xC(r27)

	.loc_0x180:
	  cmplwi    r27, 0
	  bne+      .loc_0x150

	.loc_0x188:
	  stw       r31, 0x4(r29)
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8003060C
 * Size:	00040C
 */
void BaseShape::resolveTextureNames()
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x140(r1)
	  stmw      r27, 0x12C(r1)
	  mr        r31, r3
	  lwz       r0, 0x2A8(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0xC8
	  li        r30, 0
	  addi      r29, r30, 0
	  li        r28, 0
	  b         .loc_0xBC

	.loc_0x30:
	  lwz       r0, 0x2A8(r31)
	  addi      r3, r1, 0x24
	  lwz       r4, 0x2DEC(r13)
	  crclr     6, 0x6
	  add       r27, r0, r30
	  lwz       r5, 0x1F8(r4)
	  addi      r6, r27, 0
	  subi      r4, r13, 0x7C44
	  bl        0x1E5F3C
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x24
	  li        r5, 0x1
	  bl        0xEA9C
	  lwz       r4, 0x2A0(r31)
	  stwx      r3, r4, r29
	  lwz       r3, 0x2A0(r31)
	  lwzx      r0, r3, r29
	  cmplwi    r0, 0
	  bne-      .loc_0xB0
	  lwz       r4, 0x2DEC(r13)
	  addi      r6, r27, 0
	  addi      r3, r1, 0x24
	  crclr     6, 0x6
	  lwz       r5, 0x1F4(r4)
	  subi      r4, r13, 0x7C44
	  bl        0x1E5EF8
	  lwz       r3, 0x2DEC(r13)
	  addi      r4, r1, 0x24
	  li        r5, 0x1
	  bl        0xEA58
	  lwz       r4, 0x2A0(r31)
	  stwx      r3, r4, r29

	.loc_0xB0:
	  addi      r30, r30, 0x20
	  addi      r29, r29, 0x4
	  addi      r28, r28, 0x1

	.loc_0xBC:
	  lwz       r0, 0x2A4(r31)
	  cmpw      r28, r0
	  blt+      .loc_0x30

	.loc_0xC8:
	  lwz       r30, 0x29C(r31)
	  cmpwi     r30, 0
	  bne-      .loc_0xE0
	  lwz       r0, 0x2A4(r31)
	  cmpwi     r0, 0
	  beq-      .loc_0x3F8

	.loc_0xE0:
	  cmpwi     r30, 0
	  beq-      .loc_0xEC
	  b         .loc_0xF0

	.loc_0xEC:
	  lwz       r30, 0x2A4(r31)

	.loc_0xF0:
	  mulli     r3, r30, 0x34
	  addi      r3, r3, 0x8
	  bl        0x16900
	  lis       r4, 0x8003
	  addi      r4, r4, 0xA18
	  addi      r7, r30, 0
	  li        r5, 0
	  li        r6, 0x34
	  bl        0x1E450C
	  cmpwi     r30, 0
	  mtctr     r30
	  li        r7, 0
	  stw       r3, 0x6C(r31)
	  addi      r8, r7, 0
	  li        r9, 0
	  lis       r5, 0x1
	  ble-      .loc_0x198

	.loc_0x134:
	  lwz       r3, 0x6C(r31)
	  addi      r0, r7, 0x14
	  stwx      r9, r3, r0
	  lwz       r0, 0x2A4(r31)
	  neg       r3, r0
	  subic     r0, r3, 0x1
	  subfe     r0, r0, r3
	  rlwinm    r0,r0,0,24,31
	  or.       r0, r9, r0
	  beq-      .loc_0x164
	  subi      r6, r5, 0x8000
	  b         .loc_0x168

	.loc_0x164:
	  li        r6, 0

	.loc_0x168:
	  lwz       r4, 0x6C(r31)
	  addi      r3, r7, 0x18
	  addi      r0, r7, 0x2C
	  stwx      r6, r4, r3
	  addi      r7, r7, 0x34
	  addi      r9, r9, 0x1
	  lwz       r4, 0x2A0(r31)
	  lwz       r3, 0x6C(r31)
	  lwzx      r4, r4, r8
	  addi      r8, r8, 0x4
	  stwx      r4, r3, r0
	  bdnz+     .loc_0x134

	.loc_0x198:
	  mulli     r3, r30, 0x9C
	  addi      r3, r3, 0x8
	  bl        0x16858
	  lis       r4, 0x8003
	  subi      r4, r4, 0x3B8
	  addi      r7, r30, 0
	  li        r5, 0
	  li        r6, 0x9C
	  bl        0x1E4464
	  lwz       r0, 0x40(r31)
	  cmpw      r0, r30
	  bne-      .loc_0x320
	  cmpwi     r30, 0
	  mtctr     r30
	  addi      r6, r3, 0
	  li        r5, 0
	  ble-      .loc_0x320

	.loc_0x1DC:
	  lwz       r0, 0x44(r31)
	  add       r4, r0, r5
	  lwz       r0, 0x4(r4)
	  addi      r5, r5, 0x9C
	  stw       r0, 0x4(r6)
	  lwz       r0, 0x8(r4)
	  stw       r0, 0x8(r6)
	  lwz       r0, 0xC(r4)
	  stw       r0, 0xC(r6)
	  lwz       r0, 0x10(r4)
	  stw       r0, 0x10(r6)
	  lwz       r0, 0x14(r4)
	  stw       r0, 0x14(r6)
	  lwz       r0, 0x18(r4)
	  stw       r0, 0x18(r6)
	  lwz       r0, 0x1C(r4)
	  stw       r0, 0x1C(r6)
	  lwz       r0, 0x20(r4)
	  stw       r0, 0x20(r6)
	  lwz       r0, 0x24(r4)
	  stw       r0, 0x24(r6)
	  lwz       r0, 0x28(r4)
	  stw       r0, 0x28(r6)
	  lwz       r7, 0x2C(r4)
	  lwz       r0, 0x30(r4)
	  stw       r7, 0x2C(r6)
	  stw       r0, 0x30(r6)
	  lwz       r7, 0x34(r4)
	  lwz       r0, 0x38(r4)
	  stw       r7, 0x34(r6)
	  stw       r0, 0x38(r6)
	  lwz       r7, 0x3C(r4)
	  lwz       r0, 0x40(r4)
	  stw       r7, 0x3C(r6)
	  stw       r0, 0x40(r6)
	  lwz       r7, 0x44(r4)
	  lwz       r0, 0x48(r4)
	  stw       r7, 0x44(r6)
	  stw       r0, 0x48(r6)
	  lwz       r7, 0x4C(r4)
	  lwz       r0, 0x50(r4)
	  stw       r7, 0x4C(r6)
	  stw       r0, 0x50(r6)
	  lwz       r0, 0x54(r4)
	  stw       r0, 0x54(r6)
	  lwz       r7, 0x58(r4)
	  lwz       r0, 0x5C(r4)
	  stw       r7, 0x58(r6)
	  stw       r0, 0x5C(r6)
	  lwz       r7, 0x60(r4)
	  lwz       r0, 0x64(r4)
	  stw       r7, 0x60(r6)
	  stw       r0, 0x64(r6)
	  lwz       r7, 0x68(r4)
	  lwz       r0, 0x6C(r4)
	  stw       r7, 0x68(r6)
	  stw       r0, 0x6C(r6)
	  lwz       r7, 0x70(r4)
	  lwz       r0, 0x74(r4)
	  stw       r7, 0x70(r6)
	  stw       r0, 0x74(r6)
	  lwz       r7, 0x78(r4)
	  lwz       r0, 0x7C(r4)
	  stw       r7, 0x78(r6)
	  stw       r0, 0x7C(r6)
	  lwz       r7, 0x80(r4)
	  lwz       r0, 0x84(r4)
	  stw       r7, 0x80(r6)
	  stw       r0, 0x84(r6)
	  lwz       r0, 0x88(r4)
	  stw       r0, 0x88(r6)
	  lwz       r0, 0x8C(r4)
	  stw       r0, 0x8C(r6)
	  lwz       r0, 0x90(r4)
	  stw       r0, 0x90(r6)
	  lwz       r0, 0x94(r4)
	  stw       r0, 0x94(r6)
	  lwz       r0, 0x98(r4)
	  stw       r0, 0x98(r6)
	  addi      r6, r6, 0x9C
	  bdnz+     .loc_0x1DC

	.loc_0x320:
	  cmpwi     r30, 0
	  stw       r30, 0x40(r31)
	  li        r10, 0
	  ble-      .loc_0x3E4
	  cmpwi     r30, 0x8
	  subi      r4, r30, 0x8
	  ble-      .loc_0x3EC
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  addi      r9, r3, 0
	  ble-      .loc_0x3EC

	.loc_0x354:
	  stw       r10, 0x14(r9)
	  addi      r0, r10, 0x1
	  addi      r8, r10, 0x2
	  stw       r10, 0x1C(r9)
	  addi      r7, r10, 0x3
	  addi      r6, r10, 0x4
	  stw       r0, 0xB0(r9)
	  addi      r5, r10, 0x5
	  addi      r4, r10, 0x6
	  stw       r0, 0xB8(r9)
	  addi      r0, r10, 0x7
	  addi      r10, r10, 0x8
	  stw       r8, 0x14C(r9)
	  stw       r8, 0x154(r9)
	  stw       r7, 0x1E8(r9)
	  stw       r7, 0x1F0(r9)
	  stw       r6, 0x284(r9)
	  stw       r6, 0x28C(r9)
	  stw       r5, 0x320(r9)
	  stw       r5, 0x328(r9)
	  stw       r4, 0x3BC(r9)
	  stw       r4, 0x3C4(r9)
	  stw       r0, 0x458(r9)
	  stw       r0, 0x460(r9)
	  addi      r9, r9, 0x4E0
	  bdnz+     .loc_0x354
	  b         .loc_0x3EC

	.loc_0x3C0:
	  sub       r0, r30, r10
	  cmpw      r10, r30
	  mtctr     r0
	  bge-      .loc_0x3E4

	.loc_0x3D0:
	  stw       r10, 0x14(r4)
	  stw       r10, 0x1C(r4)
	  addi      r4, r4, 0x9C
	  addi      r10, r10, 0x1
	  bdnz+     .loc_0x3D0

	.loc_0x3E4:
	  stw       r3, 0x44(r31)
	  b         .loc_0x3F8

	.loc_0x3EC:
	  mulli     r0, r10, 0x9C
	  add       r4, r3, r0
	  b         .loc_0x3C0

	.loc_0x3F8:
	  lmw       r27, 0x12C(r1)
	  lwz       r0, 0x144(r1)
	  addi      r1, r1, 0x140
	  mtlr      r0
	  blr
	*/
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
			stream.readInt();
			mSystemFlags = stream.readInt();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::Vertex: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

			mVertexCount = stream.readInt();
			stream.skipPadding(0x20);
			mVertexList = new Vector3f[mVertexCount];
			for (int i = 0; i < mVertexCount; i++) {
				mVertexList[i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexNormal: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

			mNormalCount = stream.readInt();
			stream.skipPadding(0x20);
			mNormalList = new Vector3f[mNormalCount];
			for (int i = 0; i < mVertexCount; i++) {
				mNormalList[i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexNBT: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

			mNbtCount = stream.readInt();
			stream.skipPadding(0x20);
			mNbtList = new NBT[mNbtCount];
			for (int i = 0; i < mNbtCount; i++) {
				mNbtList[i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
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
			int free  = gsys->getHeap(SYSHEAP_App)->getFree();
			int index = chunkType - BaseShapeChunk::TexCoord0;

			mTexCoordCounts[index] = stream.readInt();
			mTexCoordList[index]   = new Vector2f[mTexCoordCounts[index]];

			for (int i = 0; i < mTexCoordCounts[index]; i++) {
				mTexCoordList[index][i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			mTotalActiveTexCoords++;
			break;
		}

		case BaseShapeChunk::Texture: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

			mTextureCount = stream.readInt();
			stream.skipPadding(0x20);
			mTextureList = new TexImg[mTextureCount];
			for (int i = 0; i < mTextureCount; i++) {
				mTextureList[i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::TextureAttribute: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

			mTexAttrCount = stream.readInt();
			stream.skipPadding(0x20);
			mTexAttrList = new TexAttr[mTexAttrCount];
			for (int i = 0; i < mTexAttrCount; i++) {
				mTexAttrList[i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::Material: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

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

					MatobjInfo* info = new MatobjInfo;
					info->mTarget    = &mMaterialList[i];
					gsys->addGfxObject(info);
				}
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::VertexMatrix: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

			mVtxMatrixCount = stream.readInt();
			stream.skipPadding(0x20);
			mVtxMatrixList = new VtxMatrix[mVtxMatrixCount];
			for (int i = 0; i < mVtxMatrixCount; i++) {
				mVtxMatrixList[i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::MatrixEnvelope: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

			mEnvelopeCount = stream.readInt();
			stream.skipPadding(0x20);
			mEnvelopeList = new Envelope[mVtxMatrixCount];
			for (int i = 0; i < mEnvelopeCount; i++) {
				mEnvelopeList[i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::Mesh: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

			mMeshCount = stream.readInt();
			stream.skipPadding(0x20);
			mMeshList = new Mesh[mMeshCount];
			for (int i = 0; i < mMeshCount; i++) {
				mMeshList[i].read(stream);
			}

			gsys->getHeap(SYSHEAP_App)->getFree();
			stream.skipPadding(0x20);
			break;
		}

		case BaseShapeChunk::Joint: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

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

			gsys->getHeap(SYSHEAP_App)->getFree();
			break;
		}

		case BaseShapeChunk::JointName: {
			int free = gsys->getHeap(SYSHEAP_App)->getFree();

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

		default: {
			skipChunk(stream, length);
		}
		}
	} while (chunkType != 0xFFFF);

	if (stream.getPending()) {
		importIni(stream);
	}

	mAnimMatrixId = mEnvelopeCount + mJointCount;

	/*
	.loc_0x0:
	  mflr      r0
	  lis       r12, 0x8003
	  stw       r0, 0x4(r1)
	  addi      r0, r12, 0x30D0
	  lis       r11, 0x8003
	  stwu      r1, -0x2C0(r1)
	  lis       r10, 0x8003
	  lis       r5, 0x8003
	  stfd      f31, 0x2B8(r1)
	  lis       r6, 0x8003
	  lis       r9, 0x8023
	  stfd      f30, 0x2B0(r1)
	  lis       r8, 0x8023
	  lis       r7, 0x8023
	  stfd      f29, 0x2A8(r1)
	  stfd      f28, 0x2A0(r1)
	  stfd      f27, 0x298(r1)
	  stfd      f26, 0x290(r1)
	  stfd      f25, 0x288(r1)
	  stfd      f24, 0x280(r1)
	  stmw      r14, 0x238(r1)
	  lis       r14, 0x8003
	  lis       r16, 0x8003
	  stw       r0, 0x22C(r1)
	  subi      r0, r14, 0x7DEC
	  lis       r18, 0x8003
	  stw       r0, 0x228(r1)
	  addi      r0, r16, 0x30E8
	  lis       r20, 0x8003
	  stw       r0, 0x224(r1)
	  addi      r0, r18, 0x31CC
	  lis       r21, 0x8003
	  stw       r0, 0x220(r1)
	  addi      r0, r20, 0x3220
	  addi      r31, r3, 0
	  stw       r0, 0x21C(r1)
	  subi      r0, r21, 0x3B8
	  addi      r30, r4, 0
	  stw       r0, 0x218(r1)
	  addi      r0, r11, 0x3808
	  subi      r19, r9, 0x795C
	  stw       r0, 0x214(r1)
	  addi      r0, r10, 0xA18
	  subi      r17, r8, 0x796C
	  stw       r0, 0x210(r1)
	  addi      r0, r5, 0x3868
	  subi      r15, r7, 0x79A8
	  stw       r0, 0x20C(r1)
	  addi      r0, r6, 0x38B4
	  lis       r18, 0x6E6F
	  lfs       f24, -0x7CDC(r2)
	  lis       r14, 0x5F67
	  lfd       f29, -0x7CD0(r2)
	  lis       r21, 0x4330
	  lfs       f30, -0x7CE0(r2)
	  lfs       f31, -0x7D20(r2)
	  lfd       f25, -0x7CD8(r2)
	  lfs       f26, -0x7CE4(r2)
	  stw       r0, 0x208(r1)

	.loc_0xEC:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r20, r3, 0
	  addi      r3, r30, 0
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r20, 0x30
	  addi      r23, r3, 0
	  beq-      .loc_0xD48
	  bge-      .loc_0x198
	  cmpwi     r20, 0x13
	  beq-      .loc_0x7A0
	  bge-      .loc_0x16C
	  cmpwi     r20, 0x10
	  beq-      .loc_0x2AC
	  bge-      .loc_0x160
	  cmpwi     r20, 0
	  beq-      .loc_0x1EC
	  b         .loc_0x24F4

	.loc_0x160:
	  cmpwi     r20, 0x12
	  bge-      .loc_0x584
	  b         .loc_0x418

	.loc_0x16C:
	  cmpwi     r20, 0x21
	  beq-      .loc_0x24F4
	  bge-      .loc_0x18C
	  cmpwi     r20, 0x20
	  bge-      .loc_0xAB0
	  cmpwi     r20, 0x18
	  bge-      .loc_0x924
	  b         .loc_0x24F4

	.loc_0x18C:
	  cmpwi     r20, 0x23
	  bge-      .loc_0x24F4
	  b         .loc_0xBFC

	.loc_0x198:
	  cmpwi     r20, 0x60
	  beq-      .loc_0x1800
	  bge-      .loc_0x1C8
	  cmpwi     r20, 0x41
	  beq-      .loc_0x14E4
	  bge-      .loc_0x1BC
	  cmpwi     r20, 0x40
	  bge-      .loc_0x137C
	  b         .loc_0x24F4

	.loc_0x1BC:
	  cmpwi     r20, 0x50
	  beq-      .loc_0x16B4
	  b         .loc_0x24F4

	.loc_0x1C8:
	  cmpwi     r20, 0x100
	  beq-      .loc_0x1C30
	  bge-      .loc_0x1E0
	  cmpwi     r20, 0x62
	  bge-      .loc_0x24F4
	  b         .loc_0x1B20

	.loc_0x1E0:
	  cmpwi     r20, 0x110
	  beq-      .loc_0x1F4C
	  b         .loc_0x24F4

	.loc_0x1EC:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x22C

	.loc_0x214:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x22C:
	  cmpw      r22, r23
	  blt+      .loc_0x214
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x14(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x2A0

	.loc_0x288:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x2A0:
	  cmpw      r22, r23
	  blt+      .loc_0x288
	  b         .loc_0x251C

	.loc_0x2AC:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xE22C
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r25, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x238(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x31C

	.loc_0x304:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x31C:
	  cmpw      r22, r23
	  blt+      .loc_0x304
	  lwz       r0, 0x238(r31)
	  li        r4, 0x20
	  mulli     r3, r0, 0xC
	  bl        0x162F8
	  stw       r3, 0x23C(r31)
	  li        r22, 0
	  li        r24, 0
	  b         .loc_0x39C

	.loc_0x344:
	  mr        r3, r30
	  lwz       r0, 0x23C(r31)
	  lwz       r12, 0x4(r30)
	  add       r23, r0, r24
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x0(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x4(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x8(r23)
	  addi      r24, r24, 0xC
	  addi      r22, r22, 0x1

	.loc_0x39C:
	  lwz       r0, 0x238(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x344
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xE130
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r25, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x40C

	.loc_0x3F4:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x40C:
	  cmpw      r22, r23
	  blt+      .loc_0x3F4
	  b         .loc_0x251C

	.loc_0x418:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xE0C0
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r25, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x28C(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x488

	.loc_0x470:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x488:
	  cmpw      r22, r23
	  blt+      .loc_0x470
	  lwz       r0, 0x28C(r31)
	  li        r4, 0x20
	  mulli     r3, r0, 0xC
	  bl        0x1618C
	  stw       r3, 0x290(r31)
	  li        r22, 0
	  li        r24, 0
	  b         .loc_0x508

	.loc_0x4B0:
	  mr        r3, r30
	  lwz       r0, 0x290(r31)
	  lwz       r12, 0x4(r30)
	  add       r23, r0, r24
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x0(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x4(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x8(r23)
	  addi      r24, r24, 0xC
	  addi      r22, r22, 0x1

	.loc_0x508:
	  lwz       r0, 0x28C(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x4B0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xDFC4
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r25, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x578

	.loc_0x560:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x578:
	  cmpw      r22, r23
	  blt+      .loc_0x560
	  b         .loc_0x251C

	.loc_0x584:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xDF54
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r27, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x294(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x5F4

	.loc_0x5DC:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x5F4:
	  cmpw      r22, r23
	  blt+      .loc_0x5DC
	  lwz       r0, 0x294(r31)
	  li        r4, 0x20
	  mulli     r3, r0, 0x24
	  bl        0x16020
	  stw       r3, 0x298(r31)
	  li        r22, 0
	  li        r24, 0
	  li        r26, 0xC
	  li        r25, 0x18
	  b         .loc_0x724

	.loc_0x624:
	  mr        r3, r30
	  lwz       r0, 0x298(r31)
	  lwz       r12, 0x4(r30)
	  add       r23, r0, r24
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x0(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x4(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x8(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r0, 0x298(r31)
	  lwz       r12, 0x14(r12)
	  add       r23, r0, r26
	  mtlr      r12
	  blrl
	  stfs      f1, 0x0(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x4(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x8(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r0, 0x298(r31)
	  lwz       r12, 0x14(r12)
	  add       r23, r0, r25
	  mtlr      r12
	  blrl
	  stfs      f1, 0x0(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x4(r23)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x8(r23)
	  addi      r24, r24, 0x24
	  addi      r26, r26, 0x24
	  addi      r25, r25, 0x24
	  addi      r22, r22, 0x1

	.loc_0x724:
	  lwz       r0, 0x294(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x624
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xDDA8
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r27, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x794

	.loc_0x77C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x794:
	  cmpw      r22, r23
	  blt+      .loc_0x77C
	  b         .loc_0x251C

	.loc_0x7A0:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xDD38
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r25, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x240(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x810

	.loc_0x7F8:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x810:
	  cmpw      r22, r23
	  blt+      .loc_0x7F8
	  lwz       r0, 0x240(r31)
	  li        r4, 0x20
	  rlwinm    r3,r0,2,0,29
	  bl        0x15E04
	  stw       r3, 0x244(r31)
	  li        r22, 0
	  li        r23, 0
	  b         .loc_0x8A8

	.loc_0x838:
	  mr        r3, r30
	  lwz       r0, 0x244(r31)
	  lwz       r12, 0x4(r30)
	  add       r24, r0, r23
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x0(r24)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1(r24)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x2(r24)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x3(r24)
	  addi      r23, r23, 0x4
	  addi      r22, r22, 0x1

	.loc_0x8A8:
	  lwz       r0, 0x240(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x838
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xDC24
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r25, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x918

	.loc_0x900:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x918:
	  cmpw      r22, r23
	  blt+      .loc_0x900
	  b         .loc_0x251C

	.loc_0x924:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xDBB4
	  lwz       r4, 0x8(r3)
	  subi      r24, r20, 0x18
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r26, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  rlwinm    r4,r24,2,0,29
	  addi      r0, r4, 0x24C
	  stwx      r3, r31, r0
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x9A0

	.loc_0x988:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x9A0:
	  cmpw      r22, r23
	  blt+      .loc_0x988
	  rlwinm    r0,r24,2,0,29
	  add       r25, r31, r0
	  lwz       r22, 0x24C(r25)
	  li        r4, 0x20
	  rlwinm    r3,r22,3,0,28
	  addi      r3, r3, 0x8
	  bl        0x15C68
	  lwz       r4, 0x208(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0x8
	  bl        0x1E3714
	  stw       r3, 0x26C(r25)
	  li        r22, 0
	  li        r23, 0
	  b         .loc_0xA28

	.loc_0x9E8:
	  mr        r3, r30
	  lwz       r0, 0x26C(r25)
	  lwz       r12, 0x4(r30)
	  add       r24, r0, r23
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x0(r24)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x4(r24)
	  addi      r23, r23, 0x8
	  addi      r22, r22, 0x1

	.loc_0xA28:
	  lwz       r0, 0x24C(r25)
	  cmpw      r22, r0
	  blt+      .loc_0x9E8
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xDAA4
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r26, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0xA98

	.loc_0xA80:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0xA98:
	  cmpw      r22, r23
	  blt+      .loc_0xA80
	  lwz       r3, 0x248(r31)
	  addi      r0, r3, 0x1
	  stw       r0, 0x248(r31)
	  b         .loc_0x251C

	.loc_0xAB0:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xDA28
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r24, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x74(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0xB20

	.loc_0xB08:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0xB20:
	  cmpw      r22, r23
	  blt+      .loc_0xB08
	  lwz       r22, 0x74(r31)
	  mulli     r3, r22, 0x34
	  addi      r3, r3, 0x8
	  bl        0x15990
	  lwz       r4, 0x20C(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0x34
	  bl        0x1E35A0
	  li        r22, 0
	  stw       r3, 0x78(r31)
	  mulli     r23, r22, 0x34
	  b         .loc_0xB80

	.loc_0xB5C:
	  lwz       r0, 0x78(r31)
	  addi      r4, r30, 0
	  add       r3, r0, r23
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r23, r23, 0x34
	  addi      r22, r22, 0x1

	.loc_0xB80:
	  lwz       r0, 0x74(r31)
	  cmpw      r22, r0
	  blt+      .loc_0xB5C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xD94C
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r24, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0xBF0

	.loc_0xBD8:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0xBF0:
	  cmpw      r22, r23
	  blt+      .loc_0xBD8
	  b         .loc_0x251C

	.loc_0xBFC:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xD8DC
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r24, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x68(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0xC6C

	.loc_0xC54:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0xC6C:
	  cmpw      r22, r23
	  blt+      .loc_0xC54
	  lwz       r22, 0x68(r31)
	  mulli     r3, r22, 0x34
	  addi      r3, r3, 0x8
	  bl        0x15844
	  lwz       r4, 0x210(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0x34
	  bl        0x1E3454
	  li        r22, 0
	  stw       r3, 0x6C(r31)
	  mulli     r23, r22, 0x34
	  b         .loc_0xCCC

	.loc_0xCA8:
	  lwz       r0, 0x6C(r31)
	  addi      r4, r30, 0
	  add       r3, r0, r23
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r23, r23, 0x34
	  addi      r22, r22, 0x1

	.loc_0xCCC:
	  lwz       r0, 0x68(r31)
	  cmpw      r22, r0
	  blt+      .loc_0xCA8
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xD800
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r24, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0xD3C

	.loc_0xD24:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0xD3C:
	  cmpw      r22, r23
	  blt+      .loc_0xD24
	  b         .loc_0x251C

	.loc_0xD48:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xD790
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r28, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x40(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x48(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0xDD0

	.loc_0xDB8:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0xDD0:
	  cmpw      r22, r23
	  blt+      .loc_0xDB8
	  lwz       r22, 0x48(r31)
	  cmpwi     r22, 0
	  beq-      .loc_0x1208
	  mulli     r3, r22, 0x84
	  addi      r3, r3, 0x8
	  bl        0x156D8
	  lwz       r4, 0x214(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0x84
	  bl        0x1E32E8
	  stw       r3, 0x4C(r31)
	  li        r22, 0
	  li        r23, 0
	  b         .loc_0x11FC

	.loc_0xE14:
	  mr        r3, r30
	  lwz       r0, 0x4C(r31)
	  lwz       r12, 0x4(r30)
	  add       r27, r0, r23
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x0(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x2(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x6(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0xC(r27)
	  addi      r4, r30, 0
	  addi      r3, r27, 0x10
	  bl        0x1C64
	  addi      r3, r27, 0x18
	  addi      r4, r30, 0
	  bl        0x1B60
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x24(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x26(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x28(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x2A(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x2C(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x30(r27)
	  addi      r4, r30, 0
	  addi      r3, r27, 0x34
	  bl        0x1BBC
	  addi      r3, r27, 0x3C
	  addi      r4, r30, 0
	  bl        0x1AB8
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x48(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4A(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4C(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4E(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x50(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x54(r27)
	  addi      r4, r30, 0
	  addi      r3, r27, 0x58
	  bl        0x1B14
	  addi      r3, r27, 0x60
	  addi      r4, r30, 0
	  bl        0x1A10
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x6C(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x6D(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x6E(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x6F(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x70(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x71(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x72(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x73(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x74(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x75(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x76(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x77(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x78(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x79(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x7A(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x7B(r27)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x7C(r27)
	  lwz       r0, 0x7C(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x11F4
	  mulli     r3, r0, 0x1E
	  bl        0x15308
	  li        r25, 0
	  stw       r3, 0x80(r27)
	  mulli     r26, r25, 0x1E
	  b         .loc_0x11E8

	.loc_0x11D0:
	  lwz       r0, 0x80(r27)
	  addi      r4, r30, 0
	  add       r3, r0, r26
	  bl        0x1518
	  addi      r26, r26, 0x1E
	  addi      r25, r25, 0x1

	.loc_0x11E8:
	  lwz       r0, 0x7C(r27)
	  cmplw     r25, r0
	  blt+      .loc_0x11D0

	.loc_0x11F4:
	  addi      r23, r23, 0x84
	  addi      r22, r22, 0x1

	.loc_0x11FC:
	  lwz       r0, 0x48(r31)
	  cmpw      r22, r0
	  blt+      .loc_0xE14

	.loc_0x1208:
	  lwz       r22, 0x40(r31)
	  cmpwi     r22, 0
	  beq-      .loc_0x130C
	  mulli     r3, r22, 0x9C
	  addi      r3, r3, 0x8
	  bl        0x152A8
	  lwz       r4, 0x218(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0x9C
	  bl        0x1E2EB8
	  stw       r3, 0x44(r31)
	  li        r22, 0
	  li        r24, 0
	  b         .loc_0x1300

	.loc_0x1244:
	  lwz       r3, 0x44(r31)
	  addi      r0, r24, 0x14
	  addi      r4, r30, 0
	  stwx      r22, r3, r0
	  lwz       r0, 0x44(r31)
	  add       r3, r0, r24
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x44(r31)
	  li        r3, 0x24
	  lwz       r0, 0x4C(r31)
	  add       r4, r4, r24
	  lwz       r5, 0x8C(r4)
	  mulli     r5, r5, 0x84
	  add       r0, r0, r5
	  stw       r0, 0x90(r4)
	  bl        0x15238
	  mr.       r25, r3
	  beq-      .loc_0x12E0
	  stw       r19, 0x1C(r25)
	  addi      r3, r25, 0xC
	  bl        0x1207C
	  li        r23, 0
	  stw       r23, 0x4(r25)
	  subi      r0, r13, 0x7CA8
	  addi      r3, r25, 0xC
	  stw       r23, 0x0(r25)
	  addi      r4, r18, 0x6E65
	  stw       r0, 0x8(r25)
	  bl        0x120C4
	  stw       r23, 0x18(r25)
	  addi      r3, r25, 0xC
	  addi      r4, r14, 0x6678
	  stw       r17, 0x1C(r25)
	  stw       r23, 0x20(r25)
	  stw       r15, 0x8(r25)
	  bl        0x120A8

	.loc_0x12E0:
	  lwz       r0, 0x44(r31)
	  addi      r4, r25, 0
	  add       r0, r0, r24
	  stw       r0, 0x20(r25)
	  lwz       r3, 0x2DEC(r13)
	  bl        0xD830
	  addi      r24, r24, 0x9C
	  addi      r22, r22, 0x1

	.loc_0x1300:
	  lwz       r0, 0x40(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x1244

	.loc_0x130C:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xD1CC
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r28, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1370

	.loc_0x1358:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1370:
	  cmpw      r22, r23
	  blt+      .loc_0x1358
	  b         .loc_0x251C

	.loc_0x137C:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xD15C
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r25, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x38(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x13EC

	.loc_0x13D4:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x13EC:
	  cmpw      r22, r23
	  blt+      .loc_0x13D4
	  lwz       r0, 0x38(r31)
	  rlwinm    r3,r0,3,0,28
	  bl        0x150C8
	  stw       r3, 0x3C(r31)
	  li        r22, 0
	  li        r23, 0
	  b         .loc_0x1468

	.loc_0x1410:
	  mr        r3, r30
	  lwz       r0, 0x3C(r31)
	  lwz       r12, 0x4(r30)
	  add       r24, r0, r23
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh.    r3, r3
	  blt-      .loc_0x143C
	  li        r0, 0x1
	  b         .loc_0x1440

	.loc_0x143C:
	  li        r0, 0

	.loc_0x1440:
	  stb       r0, 0x0(r24)
	  lbz       r0, 0x0(r24)
	  cmplwi    r0, 0
	  beq-      .loc_0x1458
	  stw       r3, 0x4(r24)
	  b         .loc_0x1460

	.loc_0x1458:
	  subfic    r0, r3, -0x1
	  stw       r0, 0x4(r24)

	.loc_0x1460:
	  addi      r23, r23, 0x8
	  addi      r22, r22, 0x1

	.loc_0x1468:
	  lwz       r0, 0x38(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x1410
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xD064
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r25, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x14D8

	.loc_0x14C0:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x14D8:
	  cmpw      r22, r23
	  blt+      .loc_0x14C0
	  b         .loc_0x251C

	.loc_0x14E4:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xCFF4
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r24, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x30(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1554

	.loc_0x153C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1554:
	  cmpw      r22, r23
	  blt+      .loc_0x153C
	  lwz       r22, 0x30(r31)
	  mulli     r3, r22, 0xC
	  addi      r3, r3, 0x8
	  bl        0x14F5C
	  lwz       r4, 0x21C(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0xC
	  bl        0x1E2B6C
	  stw       r3, 0x34(r31)
	  li        r22, 0
	  li        r23, 0
	  b         .loc_0x1638

	.loc_0x1590:
	  mr        r3, r30
	  lwz       r0, 0x34(r31)
	  lwz       r12, 0x4(r30)
	  add       r26, r0, r23
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  extsh     r0, r3
	  stw       r0, 0x0(r26)
	  lwz       r0, 0x0(r26)
	  rlwinm    r3,r0,3,0,28
	  bl        0x14F08
	  stw       r3, 0x4(r26)
	  li        r25, 0
	  addi      r27, r25, 0
	  lwz       r0, 0x0(r26)
	  rlwinm    r0,r0,2,0,29
	  add       r0, r3, r0
	  stw       r0, 0x8(r26)
	  b         .loc_0x1624

	.loc_0x15E0:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x4(r26)
	  extsh     r0, r3
	  addi      r3, r30, 0
	  stwx      r0, r4, r27
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x8(r26)
	  addi      r25, r25, 0x1
	  stfsx     f1, r3, r27
	  addi      r27, r27, 0x4

	.loc_0x1624:
	  lwz       r0, 0x0(r26)
	  cmpw      r25, r0
	  blt+      .loc_0x15E0
	  addi      r23, r23, 0xC
	  addi      r22, r22, 0x1

	.loc_0x1638:
	  lwz       r0, 0x30(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x1590
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xCE94
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r24, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x16A8

	.loc_0x1690:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x16A8:
	  cmpw      r22, r23
	  blt+      .loc_0x1690
	  b         .loc_0x251C

	.loc_0x16B4:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xCE24
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r24, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x50(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1724

	.loc_0x170C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1724:
	  cmpw      r22, r23
	  blt+      .loc_0x170C
	  lwz       r22, 0x50(r31)
	  mulli     r3, r22, 0x30
	  addi      r3, r3, 0x8
	  bl        0x14D8C
	  lwz       r4, 0x220(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0x30
	  bl        0x1E299C
	  li        r22, 0
	  stw       r3, 0x54(r31)
	  mulli     r23, r22, 0x30
	  b         .loc_0x1784

	.loc_0x1760:
	  lwz       r0, 0x54(r31)
	  addi      r4, r30, 0
	  add       r3, r0, r23
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r23, r23, 0x30
	  addi      r22, r22, 0x1

	.loc_0x1784:
	  lwz       r0, 0x50(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x1760
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xCD48
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r24, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x17F4

	.loc_0x17DC:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x17F4:
	  cmpw      r22, r23
	  blt+      .loc_0x17DC
	  b         .loc_0x251C

	.loc_0x1800:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xCCD8
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r25, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x58(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1870

	.loc_0x1858:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1870:
	  cmpw      r22, r23
	  blt+      .loc_0x1858
	  lwz       r22, 0x58(r31)
	  mulli     r3, r22, 0x11C
	  addi      r3, r3, 0x8
	  bl        0x14C40
	  lwz       r4, 0x224(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0x11C
	  bl        0x1E2850
	  stw       r3, 0x5C(r31)
	  li        r5, 0
	  li        r3, 0
	  b         .loc_0x18D8

	.loc_0x18AC:
	  lwz       r0, 0x54(r31)
	  add       r4, r0, r3
	  lwz       r0, 0x18(r4)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x18D0
	  mulli     r0, r0, 0x11C
	  lwz       r6, 0x5C(r31)
	  add       r0, r6, r0
	  stw       r0, 0x28(r4)

	.loc_0x18D0:
	  addi      r3, r3, 0x30
	  addi      r5, r5, 0x1

	.loc_0x18D8:
	  lwz       r0, 0x50(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x18AC
	  li        r22, 0
	  li        r24, 0
	  b         .loc_0x19A4

	.loc_0x18F0:
	  lwz       r3, 0x5C(r31)
	  addi      r0, r24, 0x118
	  addi      r4, r30, 0
	  stwx      r31, r3, r0
	  lwz       r0, 0x5C(r31)
	  add       r3, r0, r24
	  lwz       r12, 0x0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r0, 0x5C(r31)
	  addi      r3, r24, 0xCC
	  lfs       f0, 0x140(r31)
	  add       r3, r0, r3
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1938
	  stfs      f1, 0x140(r31)

	.loc_0x1938:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x144(r31)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x194C
	  stfs      f1, 0x144(r31)

	.loc_0x194C:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x148(r31)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1960
	  stfs      f1, 0x148(r31)

	.loc_0x1960:
	  lfs       f1, 0xC(r3)
	  lfs       f0, 0x14C(r31)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1974
	  stfs      f1, 0x14C(r31)

	.loc_0x1974:
	  lfs       f1, 0x10(r3)
	  lfs       f0, 0x150(r31)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1988
	  stfs      f1, 0x150(r31)

	.loc_0x1988:
	  lfs       f1, 0x14(r3)
	  lfs       f0, 0x154(r31)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x199C
	  stfs      f1, 0x154(r31)

	.loc_0x199C:
	  addi      r24, r24, 0x11C
	  addi      r22, r22, 0x1

	.loc_0x19A4:
	  lwz       r0, 0x58(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x18F0
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x19F0

	.loc_0x19D8:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x19F0:
	  cmpw      r22, r23
	  blt+      .loc_0x19D8
	  li        r3, 0
	  stw       r3, 0x60(r31)
	  li        r4, 0
	  b         .loc_0x1A28

	.loc_0x1A08:
	  lwz       r5, 0x5C(r31)
	  addi      r0, r3, 0x110
	  lwz       r6, 0x60(r31)
	  addi      r3, r3, 0x11C
	  lwzx      r0, r5, r0
	  addi      r4, r4, 0x1
	  add       r0, r6, r0
	  stw       r0, 0x60(r31)

	.loc_0x1A28:
	  lwz       r0, 0x58(r31)
	  cmpw      r4, r0
	  blt+      .loc_0x1A08
	  lwz       r0, 0x60(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        0x14A88
	  stw       r3, 0x64(r31)
	  li        r23, 0
	  li        r24, 0
	  b         .loc_0x1A84

	.loc_0x1A50:
	  lwz       r3, 0x5C(r31)
	  addi      r0, r24, 0x14
	  stwx      r23, r3, r0
	  lwz       r0, 0x5C(r31)
	  add       r4, r0, r24
	  lwz       r3, 0x18(r4)
	  cmpwi     r3, -0x1
	  beq-      .loc_0x1A7C
	  mulli     r3, r3, 0x11C
	  add       r3, r0, r3
	  bl        0xE020

	.loc_0x1A7C:
	  addi      r24, r24, 0x11C
	  addi      r23, r23, 0x1

	.loc_0x1A84:
	  lwz       r0, 0x58(r31)
	  cmpw      r23, r0
	  blt+      .loc_0x1A50
	  li        r22, 0
	  stw       r22, 0x2DD0(r13)
	  addi      r3, r31, 0
	  li        r5, 0x4
	  lwz       r4, 0x5C(r31)
	  bl        -0x1B70
	  lwz       r4, 0x5C(r31)
	  addi      r3, r31, 0
	  li        r5, 0x2
	  bl        -0x1B80
	  lwz       r4, 0x5C(r31)
	  addi      r3, r31, 0
	  li        r5, 0x1
	  bl        -0x1B90
	  li        r5, 0
	  b         .loc_0x1AEC

	.loc_0x1AD0:
	  lwz       r3, 0x64(r31)
	  addi      r5, r5, 0x1
	  lwzx      r4, r3, r22
	  addi      r22, r22, 0x4
	  lwz       r3, 0x18(r4)
	  lwz       r0, 0x28(r3)
	  stw       r0, 0x24(r4)

	.loc_0x1AEC:
	  lwz       r0, 0x60(r31)
	  cmpw      r5, r0
	  blt+      .loc_0x1AD0
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xC9E0
	  lwz       r0, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  sub       r0, r3, r0
	  sub       r0, r25, r0
	  stw       r0, 0x234(r1)
	  stw       r21, 0x230(r1)
	  b         .loc_0x251C

	.loc_0x1B20:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xC9B8
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x58(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1B84

	.loc_0x1B6C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1B84:
	  cmpw      r22, r23
	  blt+      .loc_0x1B6C
	  li        r22, 0
	  addi      r24, r22, 0
	  addi      r25, r22, 0
	  li        r23, 0
	  b         .loc_0x1BD8

	.loc_0x1BA0:
	  stw       r24, 0x1F4(r1)
	  addi      r3, r30, 0
	  addi      r4, r1, 0x1F0
	  stw       r25, 0x1F0(r1)
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x1C(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0x1F4(r1)
	  addi      r0, r22, 0x4
	  lwz       r3, 0x5C(r31)
	  addi      r22, r22, 0x11C
	  addi      r23, r23, 0x1
	  stwx      r4, r3, r0

	.loc_0x1BD8:
	  lwz       r0, 0x58(r31)
	  cmpw      r23, r0
	  blt+      .loc_0x1BA0
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1C24

	.loc_0x1C0C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1C24:
	  cmpw      r22, r23
	  blt+      .loc_0x1C0C
	  b         .loc_0x251C

	.loc_0x1C30:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xC8A8
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r26, r0, r4
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x168(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x170(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1CB8

	.loc_0x1CA0:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1CB8:
	  cmpw      r22, r23
	  blt+      .loc_0x1CA0
	  lwz       r0, 0x170(r31)
	  rlwinm    r3,r0,2,0,29
	  bl        0x147FC
	  stw       r3, 0x174(r31)
	  li        r22, 0
	  li        r23, 0
	  b         .loc_0x1D04

	.loc_0x1CDC:
	  mr        r3, r30
	  lwz       r0, 0x174(r31)
	  lwz       r12, 0x4(r30)
	  add       r24, r0, r23
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r24)
	  addi      r23, r23, 0x4
	  addi      r22, r22, 0x1

	.loc_0x1D04:
	  lwz       r0, 0x170(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x1CDC
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1D50

	.loc_0x1D38:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1D50:
	  cmpw      r22, r23
	  blt+      .loc_0x1D38
	  lwz       r22, 0x168(r31)
	  mulli     r3, r22, 0x58
	  addi      r3, r3, 0x8
	  bl        0x14760
	  lwz       r4, 0x228(r1)
	  addi      r7, r22, 0
	  li        r5, 0
	  li        r6, 0x58
	  bl        0x1E2370
	  stw       r3, 0x16C(r31)
	  li        r22, 0
	  li        r23, 0
	  b         .loc_0x1ED0

	.loc_0x1D8C:
	  mr        r3, r30
	  lwz       r0, 0x16C(r31)
	  lwz       r12, 0x4(r30)
	  add       r25, r0, r23
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x4(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x8(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0xC(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x10(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x12(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x14(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x16(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x18(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x1C(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x20(r25)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x24(r25)
	  lwz       r0, 0x16C(r31)
	  lwz       r4, 0x174(r31)
	  lwz       r5, 0x23C(r31)
	  add       r3, r0, r23
	  bl        0x5C74
	  addi      r23, r23, 0x58
	  addi      r22, r22, 0x1

	.loc_0x1ED0:
	  lwz       r0, 0x168(r31)
	  cmpw      r22, r0
	  blt+      .loc_0x1D8C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xC5FC
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r26, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1F40

	.loc_0x1F28:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1F40:
	  cmpw      r22, r23
	  blt+      .loc_0x1F28
	  b         .loc_0x251C

	.loc_0x1F4C:
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xC58C
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r16, r0, r4
	  lwz       r12, 0x58(r12)
	  mtlr      r12
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x1FA4

	.loc_0x1F8C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x1FA4:
	  cmpw      r22, r23
	  blt+      .loc_0x1F8C
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x140(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x144(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x148(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x14C(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x150(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x154(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x158(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x15C(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x160(r31)
	  lwz       r3, 0x15C(r31)
	  lwz       r0, 0x160(r31)
	  mullw     r0, r3, r0
	  rlwinm    r3,r0,2,0,29
	  bl        0x14430
	  stw       r3, 0x164(r31)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  addi      r28, r3, 0
	  addi      r23, r28, 0
	  mulli     r3, r23, 0x24
	  addi      r3, r3, 0x8
	  li        r24, 0
	  bl        0x14400
	  lwz       r4, 0x22C(r1)
	  addi      r7, r23, 0
	  li        r5, 0
	  li        r6, 0x24
	  bl        0x1E2010
	  addi      r22, r3, 0
	  addi      r26, r22, 0
	  li        r23, 0
	  b         .loc_0x21D4

	.loc_0x20EC:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x6(r26)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4(r26)
	  lha       r0, 0x4(r26)
	  rlwinm    r3,r0,2,0,29
	  bl        0x143A0
	  stw       r3, 0x8(r26)
	  lha       r0, 0x4(r26)
	  cmpw      r0, r24
	  ble-      .loc_0x213C
	  mr        r24, r0

	.loc_0x213C:
	  li        r25, 0
	  li        r27, 0
	  b         .loc_0x2178

	.loc_0x2148:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  mulli     r0, r3, 0x58
	  lwz       r4, 0x16C(r31)
	  lwz       r3, 0x8(r26)
	  add       r0, r4, r0
	  stwx      r0, r3, r27
	  addi      r27, r27, 0x4
	  addi      r25, r25, 0x1

	.loc_0x2178:
	  lha       r0, 0x4(r26)
	  cmpw      r25, r0
	  blt+      .loc_0x2148
	  lha       r3, 0x6(r26)
	  extsh.    r0, r3
	  beq-      .loc_0x21CC
	  bl        0x14334
	  stw       r3, 0xC(r26)
	  li        r27, 0
	  b         .loc_0x21C0

	.loc_0x21A0:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  lwz       r4, 0xC(r26)
	  stbx      r3, r4, r27
	  addi      r27, r27, 0x1

	.loc_0x21C0:
	  lha       r0, 0x6(r26)
	  cmpw      r27, r0
	  blt+      .loc_0x21A0

	.loc_0x21CC:
	  addi      r26, r26, 0x24
	  addi      r23, r23, 0x1

	.loc_0x21D4:
	  cmpw      r23, r28
	  blt+      .loc_0x20EC
	  li        r3, 0x24
	  bl        0x142E4
	  mr.       r23, r3
	  beq-      .loc_0x2200
	  li        r0, 0
	  stw       r0, 0x8(r3)
	  sth       r0, 0x4(r3)
	  stw       r0, 0x18(r3)
	  stw       r0, 0xC(r3)

	.loc_0x2200:
	  li        r0, 0
	  sth       r0, 0x4(r3)
	  li        r26, 0
	  li        r24, 0
	  stw       r0, 0x8(r3)
	  lfs       f27, -0x7D20(r2)
	  b         .loc_0x2478

	.loc_0x221C:
	  xoris     r0, r24, 0x8000
	  stw       r0, 0x234(r1)
	  li        r25, 0
	  stw       r21, 0x230(r1)
	  lfd       f0, 0x230(r1)
	  fsubs     f0, f0, f29
	  fmuls     f28, f0, f30
	  b         .loc_0x2468

	.loc_0x223C:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, -0x1
	  bne-      .loc_0x2274
	  lwz       r0, 0x15C(r31)
	  lwz       r3, 0x164(r31)
	  mullw     r0, r24, r0
	  add       r0, r25, r0
	  rlwinm    r0,r0,2,0,29
	  stwx      r23, r3, r0
	  b         .loc_0x2464

	.loc_0x2274:
	  lwz       r0, 0x15C(r31)
	  mulli     r4, r3, 0x24
	  lwz       r3, 0x164(r31)
	  mullw     r0, r24, r0
	  add       r0, r25, r0
	  add       r27, r22, r4
	  rlwinm    r0,r0,2,0,29
	  stwx      r27, r3, r0
	  xoris     r0, r25, 0x8000
	  lfs       f0, 0x148(r31)
	  lfs       f2, 0x140(r31)
	  stw       r0, 0x234(r1)
	  fadds     f5, f0, f28
	  stfs      f31, 0x1D0(r1)
	  fsubs     f3, f5, f30
	  stfs      f31, 0x1CC(r1)
	  stfs      f31, 0x1C8(r1)
	  stfs      f31, 0x1DC(r1)
	  stfs      f31, 0x1D8(r1)
	  stfs      f31, 0x1D4(r1)
	  lfs       f1, -0x7CE8(r13)
	  lfs       f0, -0x7CE4(r13)
	  stfs      f1, 0x1C8(r1)
	  stfs      f0, 0x1CC(r1)
	  lfs       f0, -0x7CE0(r13)
	  stw       r21, 0x230(r1)
	  stfs      f0, 0x1D0(r1)
	  lfd       f1, 0x230(r1)
	  lfs       f0, -0x7CDC(r13)
	  fsubs     f1, f1, f29
	  stfs      f0, 0x1D4(r1)
	  lfs       f0, -0x7CD8(r13)
	  fmuls     f1, f1, f30
	  stfs      f0, 0x1D8(r1)
	  fadds     f4, f2, f1
	  lfs       f0, -0x7CD4(r13)
	  stfs      f0, 0x1DC(r1)
	  fsubs     f2, f4, f30
	  lfs       f0, 0x1C8(r1)
	  lfs       f1, 0x144(r31)
	  fcmpo     cr0, f2, f0
	  fsubs     f1, f1, f30
	  bge-      .loc_0x2324
	  stfs      f2, 0x1C8(r1)

	.loc_0x2324:
	  lfs       f0, 0x1CC(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x2334
	  stfs      f1, 0x1CC(r1)

	.loc_0x2334:
	  lfs       f0, 0x1D0(r1)
	  fcmpo     cr0, f3, f0
	  bge-      .loc_0x2344
	  stfs      f3, 0x1D0(r1)

	.loc_0x2344:
	  lfs       f0, 0x1D4(r1)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x2354
	  stfs      f2, 0x1D4(r1)

	.loc_0x2354:
	  lfs       f0, 0x1D8(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x2364
	  stfs      f1, 0x1D8(r1)

	.loc_0x2364:
	  lfs       f0, 0x1DC(r1)
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x2374
	  stfs      f3, 0x1DC(r1)

	.loc_0x2374:
	  fadds     f1, f4, f30
	  lfs       f2, 0x150(r31)
	  lfs       f0, 0x1C8(r1)
	  fadds     f3, f5, f30
	  fadds     f2, f2, f30
	  fadds     f4, f30, f1
	  fadds     f1, f30, f3
	  fcmpo     cr0, f4, f0
	  bge-      .loc_0x239C
	  stfs      f4, 0x1C8(r1)

	.loc_0x239C:
	  lfs       f0, 0x1CC(r1)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x23AC
	  stfs      f2, 0x1CC(r1)

	.loc_0x23AC:
	  lfs       f0, 0x1D0(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x23BC
	  stfs      f1, 0x1D0(r1)

	.loc_0x23BC:
	  lfs       f0, 0x1D4(r1)
	  fcmpo     cr0, f4, f0
	  ble-      .loc_0x23CC
	  stfs      f4, 0x1D4(r1)

	.loc_0x23CC:
	  lfs       f0, 0x1D8(r1)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x23DC
	  stfs      f2, 0x1D8(r1)

	.loc_0x23DC:
	  lfs       f0, 0x1DC(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x23EC
	  stfs      f1, 0x1DC(r1)

	.loc_0x23EC:
	  li        r29, 0
	  li        r28, 0
	  b         .loc_0x2458

	.loc_0x23F8:
	  lwz       r3, 0x8(r27)
	  addi      r6, r1, 0x1C8
	  lwz       r0, 0x23C(r31)
	  li        r7, 0
	  lwzx      r5, r3, r28
	  lwz       r3, 0x4(r5)
	  lwz       r4, 0x8(r5)
	  lwz       r5, 0xC(r5)
	  mulli     r3, r3, 0xC
	  mulli     r4, r4, 0xC
	  mulli     r5, r5, 0xC
	  add       r3, r0, r3
	  add       r4, r0, r4
	  add       r5, r0, r5
	  bl        0x60B4
	  fcmpo     cr0, f1, f24
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2450
	  fcmpo     cr0, f1, f27
	  addi      r26, r26, 0x1
	  ble-      .loc_0x2450
	  fmr       f27, f1

	.loc_0x2450:
	  addi      r28, r28, 0x4
	  addi      r29, r29, 0x1

	.loc_0x2458:
	  lha       r0, 0x4(r27)
	  cmpw      r29, r0
	  blt+      .loc_0x23F8

	.loc_0x2464:
	  addi      r25, r25, 0x1

	.loc_0x2468:
	  lwz       r0, 0x15C(r31)
	  cmpw      r25, r0
	  blt+      .loc_0x223C
	  addi      r24, r24, 0x1

	.loc_0x2478:
	  lwz       r0, 0x160(r31)
	  cmpw      r24, r0
	  blt+      .loc_0x221C
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xC054
	  lwz       r4, 0x8(r3)
	  lwz       r0, 0x4(r3)
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  sub       r0, r0, r4
	  sub       r0, r16, r0
	  lwz       r12, 0x58(r12)
	  stw       r0, 0x234(r1)
	  mtlr      r12
	  stw       r21, 0x230(r1)
	  blrl
	  addi      r0, r3, 0x1F
	  rlwinm    r0,r0,0,0,26
	  sub       r23, r0, r3
	  li        r22, 0
	  b         .loc_0x24E8

	.loc_0x24D0:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x24E8:
	  cmpw      r22, r23
	  blt+      .loc_0x24D0
	  b         .loc_0x251C

	.loc_0x24F4:
	  li        r22, 0
	  b         .loc_0x2514

	.loc_0x24FC:
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  addi      r22, r22, 0x1

	.loc_0x2514:
	  cmplw     r22, r23
	  blt+      .loc_0x24FC

	.loc_0x251C:
	  cmplwi    r20, 0xFFFF
	  bne+      .loc_0xEC
	  mr        r3, r30
	  lwz       r12, 0x4(r30)
	  lwz       r12, 0x44(r12)
	  mtlr      r12
	  blrl
	  cmpwi     r3, 0
	  beq-      .loc_0x254C
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        -0x43A0

	.loc_0x254C:
	  lwz       r3, 0x58(r31)
	  lwz       r0, 0x30(r31)
	  add       r0, r3, r0
	  stw       r0, 0x2C(r31)
	  lwz       r0, 0x2C4(r1)
	  lfd       f31, 0x2B8(r1)
	  lfd       f30, 0x2B0(r1)
	  lfd       f29, 0x2A8(r1)
	  lfd       f28, 0x2A0(r1)
	  lfd       f27, 0x298(r1)
	  lfd       f26, 0x290(r1)
	  lfd       f25, 0x288(r1)
	  lfd       f24, 0x280(r1)
	  lmw       r14, 0x238(r1)
	  addi      r1, r1, 0x2C0
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800330E8
 * Size:	0000E4
 */
Joint::Joint()
    : CoreNode(nullptr)
{
	mFlags = 1;
	_10C   = 0;
}

/*
 * --INFO--
 * Address:	800331CC
 * Size:	000054
 */
Mesh::Mesh()
    : CoreNode("mesh")
{
	mJointList        = nullptr;
	mParentJoint      = -1;
	mVertexDescriptor = 1;
}

/*
 * --INFO--
 * Address:	80033220
 * Size:	000014
 */
Envelope::Envelope()
{
	mIndexCount = 0;
	mIndices    = nullptr;
	mWeights    = nullptr;
}

/*
 * --INFO--
 * Address:	80033234
 * Size:	00032C
 */
void PVWTevStage::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  addi      r31, r4, 0
	  stw       r30, 0x18(r1)
	  addi      r30, r3, 0
	  addi      r3, r31, 0
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x0(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x2(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x3(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x4(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x5(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x6(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x7(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x8(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x9(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xA(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xB(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xC(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xD(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xE(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0xF(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x10(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x11(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x12(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x13(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x14(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x15(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x16(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x17(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x18(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x19(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1A(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1B(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1C(r30)
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  stb       r3, 0x1D(r30)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80033560
 * Size:	0000F8
 */
void PVWAnimInfo1<PVWKeyInfoS10>::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r27, 0x1C(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r27)
	  lwz       r0, 0x0(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0xE4
	  rlwinm    r3,r0,4,0,27
	  bl        0x13A64
	  stw       r3, 0x4(r27)
	  li        r29, 0
	  li        r30, 0
	  b         .loc_0xD8

	.loc_0x54:
	  mr        r3, r28
	  lwz       r0, 0x4(r27)
	  lwz       r12, 0x4(r28)
	  add       r31, r0, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x8(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0xC(r31)
	  addi      r30, r30, 0x10
	  addi      r29, r29, 0x1

	.loc_0xD8:
	  lwz       r0, 0x0(r27)
	  cmplw     r29, r0
	  blt+      .loc_0x54

	.loc_0xE4:
	  lmw       r27, 0x1C(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80033658
 * Size:	0001B0
 */
void PVWAnimInfo3<PVWKeyInfoS10>::read(RandomAccessStream&)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  addi      r28, r4, 0
	  addi      r27, r3, 0
	  addi      r3, r28, 0
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r27)
	  lwz       r0, 0x0(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x19C
	  mulli     r3, r0, 0x28
	  bl        0x1396C
	  stw       r3, 0x4(r27)
	  li        r29, 0
	  li        r30, 0
	  b         .loc_0x190

	.loc_0x54:
	  mr        r3, r28
	  lwz       r0, 0x4(r27)
	  lwz       r12, 0x4(r28)
	  add       r31, r0, r30
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl
	  stw       r3, 0x0(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x4(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x8(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0xC(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x10(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x14(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x18(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  sth       r3, 0x1C(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x10(r12)
	  mtlr      r12
	  blrl
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x20(r31)
	  mr        r3, r28
	  lwz       r12, 0x4(r28)
	  lwz       r12, 0x14(r12)
	  mtlr      r12
	  blrl
	  stfs      f1, 0x24(r31)
	  addi      r30, r30, 0x28
	  addi      r29, r29, 0x1

	.loc_0x190:
	  lwz       r0, 0x0(r27)
	  cmpw      r29, r0
	  blt+      .loc_0x54

	.loc_0x19C:
	  lmw       r27, 0x24(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800338B8
 * Size:	000248
 */
void BaseShape::initIni(bool)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x40(r1)
	  stmw      r27, 0x2C(r1)
	  mr        r29, r3
	  mr        r30, r4
	  lwz       r31, 0x8C(r3)
	  b         .loc_0x134

	.loc_0x20:
	  lwz       r0, 0x34(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x130
	  li        r0, -0x1
	  stw       r0, 0x24(r1)
	  lwz       r0, 0x38(r31)
	  cmplwi    r0, 0
	  beq-      .loc_0x88
	  li        r28, 0
	  b         .loc_0x78

	.loc_0x48:
	  lwz       r3, 0x38(r31)
	  lbzx      r0, r3, r28
	  cmplwi    r0, 0x3A
	  bne-      .loc_0x74
	  add       r3, r28, r3
	  crclr     6, 0x6
	  addi      r5, r1, 0x24
	  subi      r4, r13, 0x7C94
	  addi      r3, r3, 0x1
	  bl        0x1E4770
	  b         .loc_0x88

	.loc_0x74:
	  addi      r28, r28, 0x1

	.loc_0x78:
	  lwz       r3, 0x38(r31)
	  bl        0x1E5AD8
	  cmpw      r28, r3
	  blt+      .loc_0x48

	.loc_0x88:
	  lwz       r0, 0x24(r1)
	  cmpwi     r0, -0x1
	  bne-      .loc_0xA8
	  lwz       r3, 0x2DEC(r13)
	  li        r5, 0x1
	  lwz       r4, 0x34(r31)
	  bl        0xB7B0
	  stw       r3, 0x3C(r31)

	.loc_0xA8:
	  lwz       r0, 0x24(r1)
	  cmpwi     r0, -0x1
	  bne-      .loc_0xBC
	  li        r28, 0
	  b         .loc_0xC8

	.loc_0xBC:
	  mulli     r0, r0, 0x9C
	  lwz       r3, 0x44(r29)
	  add       r28, r3, r0

	.loc_0xC8:
	  lwz       r3, 0x2DEC(r13)
	  lwz       r0, 0x194(r3)
	  cmplwi    r0, 0x4
	  mr        r27, r0
	  bne-      .loc_0xE4
	  li        r4, 0x2
	  bl        0xB6D0

	.loc_0xE4:
	  lwz       r4, 0x3C(r31)
	  cmplwi    r4, 0
	  beq-      .loc_0xF4
	  b         .loc_0xF8

	.loc_0xF4:
	  mr        r4, r28

	.loc_0xF8:
	  lwz       r3, 0x2DEC(r13)
	  bl        0xC0F8
	  stw       r3, 0x68(r31)
	  mr        r4, r27
	  lwz       r3, 0x2DEC(r13)
	  bl        0xB6A4
	  lwz       r0, 0x24(r1)
	  cmpwi     r0, -0x1
	  beq-      .loc_0x130
	  lwz       r3, 0x68(r31)
	  stw       r28, 0x1C(r3)
	  lwz       r0, 0x24(r28)
	  lwz       r3, 0x68(r31)
	  stw       r0, 0x18(r3)

	.loc_0x130:
	  lwz       r31, 0xC(r31)

	.loc_0x134:
	  cmplwi    r31, 0
	  bne+      .loc_0x20
	  lwz       r27, 0xF8(r29)
	  rlwinm    r30,r30,0,24,31
	  b         .loc_0x210

	.loc_0x148:
	  lwz       r0, 0x2C(r27)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x1A0
	  cmplwi    r30, 0
	  beq-      .loc_0x1A0
	  lwz       r3, 0x2DEC(r13)
	  li        r5, 0x1
	  lwz       r4, 0x4C(r27)
	  bl        0xB7E4
	  stw       r3, 0x48(r27)
	  lwz       r3, 0x48(r27)
	  cmplwi    r3, 0
	  beq-      .loc_0x184
	  li        r4, 0x20
	  bl        0x320

	.loc_0x184:
	  lwz       r0, 0x50(r27)
	  cmplwi    r0, 0
	  beq-      .loc_0x1A0
	  lwz       r3, 0x48(r27)
	  lwz       r0, 0x14(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x14(r3)

	.loc_0x1A0:
	  lwz       r28, 0x10(r27)
	  b         .loc_0x204

	.loc_0x1A8:
	  lwz       r0, 0x2C(r28)
	  cmplwi    r0, 0x2
	  bne-      .loc_0x200
	  cmplwi    r30, 0
	  beq-      .loc_0x200
	  lwz       r3, 0x2DEC(r13)
	  li        r5, 0x1
	  lwz       r4, 0x4C(r28)
	  bl        0xB784
	  stw       r3, 0x48(r28)
	  lwz       r3, 0x48(r28)
	  cmplwi    r3, 0
	  beq-      .loc_0x1E4
	  li        r4, 0x20
	  bl        0x2C0

	.loc_0x1E4:
	  lwz       r0, 0x50(r28)
	  cmplwi    r0, 0
	  beq-      .loc_0x200
	  lwz       r3, 0x48(r28)
	  lwz       r0, 0x14(r3)
	  ori       r0, r0, 0x10
	  stw       r0, 0x14(r3)

	.loc_0x200:
	  lwz       r28, 0xC(r28)

	.loc_0x204:
	  cmplwi    r28, 0
	  bne+      .loc_0x1A8
	  lwz       r27, 0xC(r27)

	.loc_0x210:
	  cmplwi    r27, 0
	  bne+      .loc_0x148
	  lwz       r3, 0x188(r29)
	  li        r0, 0
	  b         .loc_0x22C

	.loc_0x224:
	  stw       r0, 0xBC(r3)
	  lwz       r3, 0xC(r3)

	.loc_0x22C:
	  cmplwi    r3, 0
	  bne+      .loc_0x224
	  lmw       r27, 0x2C(r1)
	  lwz       r0, 0x44(r1)
	  addi      r1, r1, 0x40
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80033B00
 * Size:	000258
 */
void BaseShape::initialise()
{
	for (int i = 0; i < mTexAttrCount; i++) {
		if ((mTexAttrList[i].mTextureIndex & 0x8000) != 0) {
			if (!mTexAttrList[i].mTexture) {
				mTexAttrList[i].mTexture = _2A0;
			}
		} else {
			mTexAttrList[i].mImage         = &mTextureList[i];
			mTexAttrList[i].mImage->mIndex = mTexAttrList[i].mTextureIndex & 0x7FFF;
			mTexAttrList[i].initImage();
		}
	}

	mCurrentAnimation = new AnimContext();

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
void BaseShape::createCollisions(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x12C0(r1)
	  stfd      f31, 0x12B8(r1)
	  stfd      f30, 0x12B0(r1)
	  stfd      f29, 0x12A8(r1)
	  stfd      f28, 0x12A0(r1)
	  stfd      f27, 0x1298(r1)
	  stmw      r18, 0x1260(r1)
	  mr        r29, r3
	  addi      r19, r4, 0
	  li        r4, 0x2
	  lwz       r3, 0x2DEC(r13)
	  bl        0xB294
	  lwz       r0, 0x164(r29)
	  lwz       r4, 0x8(r3)
	  lwz       r3, 0x4(r3)
	  cmplwi    r0, 0
	  sub       r31, r3, r4
	  bne-      .loc_0xB80
	  lfs       f0, -0x7CE8(r13)
	  li        r6, 0
	  li        r5, 0
	  stfs      f0, 0x140(r29)
	  lfs       f0, -0x7CE4(r13)
	  stfs      f0, 0x144(r29)
	  lfs       f0, -0x7CE0(r13)
	  stfs      f0, 0x148(r29)
	  lfs       f0, -0x7CDC(r13)
	  stfs      f0, 0x14C(r29)
	  lfs       f0, -0x7CD8(r13)
	  stfs      f0, 0x150(r29)
	  lfs       f0, -0x7CD4(r13)
	  stfs      f0, 0x154(r29)
	  b         .loc_0x244

	.loc_0x8C:
	  lwz       r3, 0x16C(r29)
	  addi      r0, r5, 0x4
	  lwz       r4, 0x23C(r29)
	  lwzx      r0, r3, r0
	  lfs       f0, 0x140(r29)
	  mulli     r0, r0, 0xC
	  add       r3, r4, r0
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xB8
	  stfs      f1, 0x140(r29)

	.loc_0xB8:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x144(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xCC
	  stfs      f1, 0x144(r29)

	.loc_0xCC:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x148(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0xE0
	  stfs      f1, 0x148(r29)

	.loc_0xE0:
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x14C(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0xF4
	  stfs      f1, 0x14C(r29)

	.loc_0xF4:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x150(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x108
	  stfs      f1, 0x150(r29)

	.loc_0x108:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x154(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x11C
	  stfs      f1, 0x154(r29)

	.loc_0x11C:
	  lwz       r3, 0x16C(r29)
	  addi      r0, r5, 0x8
	  lwz       r4, 0x23C(r29)
	  lwzx      r0, r3, r0
	  lfs       f0, 0x140(r29)
	  mulli     r0, r0, 0xC
	  add       r3, r4, r0
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x148
	  stfs      f1, 0x140(r29)

	.loc_0x148:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x144(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x15C
	  stfs      f1, 0x144(r29)

	.loc_0x15C:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x148(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x170
	  stfs      f1, 0x148(r29)

	.loc_0x170:
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x14C(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x184
	  stfs      f1, 0x14C(r29)

	.loc_0x184:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x150(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x198
	  stfs      f1, 0x150(r29)

	.loc_0x198:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x154(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x1AC
	  stfs      f1, 0x154(r29)

	.loc_0x1AC:
	  lwz       r3, 0x16C(r29)
	  addi      r0, r5, 0xC
	  lwz       r4, 0x23C(r29)
	  lwzx      r0, r3, r0
	  lfs       f0, 0x140(r29)
	  mulli     r0, r0, 0xC
	  add       r3, r4, r0
	  lfs       f1, 0x0(r3)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1D8
	  stfs      f1, 0x140(r29)

	.loc_0x1D8:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x144(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x1EC
	  stfs      f1, 0x144(r29)

	.loc_0x1EC:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x148(r29)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x200
	  stfs      f1, 0x148(r29)

	.loc_0x200:
	  lfs       f1, 0x0(r3)
	  lfs       f0, 0x14C(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x214
	  stfs      f1, 0x14C(r29)

	.loc_0x214:
	  lfs       f1, 0x4(r3)
	  lfs       f0, 0x150(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x228
	  stfs      f1, 0x150(r29)

	.loc_0x228:
	  lfs       f1, 0x8(r3)
	  lfs       f0, 0x154(r29)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x23C
	  stfs      f1, 0x154(r29)

	.loc_0x23C:
	  addi      r5, r5, 0x58
	  addi      r6, r6, 0x1

	.loc_0x244:
	  lwz       r0, 0x168(r29)
	  cmpw      r6, r0
	  blt+      .loc_0x8C
	  xoris     r0, r19, 0x8000
	  lfd       f1, -0x7CD0(r2)
	  stw       r0, 0x125C(r1)
	  lis       r0, 0x4330
	  stw       r0, 0x1258(r1)
	  lfd       f0, 0x1258(r1)
	  fsubs     f0, f0, f1
	  stfs      f0, 0x158(r29)
	  lfs       f1, 0x14C(r29)
	  lfs       f0, 0x140(r29)
	  lfs       f2, 0x158(r29)
	  fsubs     f0, f1, f0
	  fadds     f0, f2, f0
	  fdivs     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x1250(r1)
	  lwz       r0, 0x1254(r1)
	  stw       r0, 0x15C(r29)
	  lfs       f1, 0x154(r29)
	  lfs       f0, 0x148(r29)
	  lfs       f2, 0x158(r29)
	  fsubs     f0, f1, f0
	  fadds     f0, f2, f0
	  fdivs     f0, f0, f2
	  fctiwz    f0, f0
	  stfd      f0, 0x1248(r1)
	  lwz       r0, 0x124C(r1)
	  stw       r0, 0x160(r29)
	  lwz       r3, 0x15C(r29)
	  lwz       r0, 0x160(r29)
	  mullw     r0, r3, r0
	  rlwinm    r3,r0,2,0,29
	  bl        0x12FDC
	  stw       r3, 0x164(r29)
	  lwz       r3, 0x15C(r29)
	  lwz       r0, 0x160(r29)
	  mullw     r18, r3, r0
	  mulli     r3, r18, 0x24
	  addi      r3, r3, 0x8
	  bl        0x12FC0
	  lis       r4, 0x8003
	  addi      r4, r4, 0x30D0
	  addi      r7, r18, 0
	  li        r5, 0
	  li        r6, 0x24
	  bl        0x1E0BCC
	  li        r6, 0
	  li        r5, 0
	  b         .loc_0x328

	.loc_0x314:
	  lwz       r4, 0x164(r29)
	  addi      r6, r6, 0x1
	  stwx      r3, r4, r5
	  addi      r3, r3, 0x24
	  addi      r5, r5, 0x4

	.loc_0x328:
	  lwz       r4, 0x15C(r29)
	  lwz       r0, 0x160(r29)
	  mullw     r0, r4, r0
	  cmpw      r6, r0
	  blt+      .loc_0x314
	  lis       r3, 0x8022
	  lfs       f30, -0x7D20(r2)
	  lfd       f31, -0x7CD0(r2)
	  addi      r30, r1, 0x204
	  addi      r25, r1, 0x220
	  addi      r28, r3, 0x22B8
	  li        r23, 0
	  li        r22, 0
	  li        r21, 0
	  lis       r26, 0x4330
	  b         .loc_0xB38

	.loc_0x368:
	  xoris     r27, r21, 0x8000
	  li        r20, 0
	  b         .loc_0xB28

	.loc_0x374:
	  lfs       f3, 0x140(r29)
	  xoris     r0, r20, 0x8000
	  lfs       f4, 0x158(r29)
	  lfs       f2, 0x148(r29)
	  stw       r0, 0x124C(r1)
	  stfs      f30, 0x20C(r1)
	  stfs      f30, 0x208(r1)
	  stfs      f30, 0x204(r1)
	  stfs      f30, 0x218(r1)
	  stfs      f30, 0x214(r1)
	  stfs      f30, 0x210(r1)
	  lfs       f6, -0x7CE8(r13)
	  lfs       f7, -0x7CE4(r13)
	  stfs      f6, 0x204(r1)
	  stfs      f7, 0x208(r1)
	  lfs       f8, -0x7CE0(r13)
	  stw       r26, 0x1248(r1)
	  stfs      f8, 0x20C(r1)
	  lfd       f0, 0x1248(r1)
	  lfs       f9, -0x7CDC(r13)
	  stw       r27, 0x1254(r1)
	  fsubs     f0, f0, f31
	  stfs      f9, 0x210(r1)
	  fmuls     f1, f0, f4
	  stw       r26, 0x1250(r1)
	  lfs       f10, -0x7CD8(r13)
	  lfd       f0, 0x1250(r1)
	  fadds     f5, f3, f1
	  stfs      f10, 0x214(r1)
	  fsubs     f0, f0, f31
	  lfs       f11, -0x7CD4(r13)
	  fsubs     f3, f5, f4
	  stfs      f11, 0x218(r1)
	  fmuls     f1, f0, f4
	  lfs       f0, 0x204(r1)
	  fadds     f12, f2, f1
	  lfs       f1, 0x144(r29)
	  fcmpo     cr0, f3, f0
	  fsubs     f1, f1, f4
	  fsubs     f2, f12, f4
	  bge-      .loc_0x41C
	  stfs      f3, 0x204(r1)

	.loc_0x41C:
	  lfs       f0, 0x208(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x42C
	  stfs      f1, 0x208(r1)

	.loc_0x42C:
	  lfs       f0, 0x20C(r1)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x43C
	  stfs      f2, 0x20C(r1)

	.loc_0x43C:
	  lfs       f0, 0x210(r1)
	  fcmpo     cr0, f3, f0
	  ble-      .loc_0x44C
	  stfs      f3, 0x210(r1)

	.loc_0x44C:
	  lfs       f0, 0x214(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x45C
	  stfs      f1, 0x214(r1)

	.loc_0x45C:
	  lfs       f0, 0x218(r1)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x46C
	  stfs      f2, 0x218(r1)

	.loc_0x46C:
	  lfs       f3, 0x158(r29)
	  lfs       f2, 0x150(r29)
	  fadds     f1, f5, f3
	  lfs       f0, 0x204(r1)
	  fadds     f3, f12, f3
	  fadds     f2, f2, f4
	  fadds     f5, f4, f1
	  fadds     f1, f4, f3
	  fcmpo     cr0, f5, f0
	  bge-      .loc_0x498
	  stfs      f5, 0x204(r1)

	.loc_0x498:
	  lfs       f0, 0x208(r1)
	  fcmpo     cr0, f2, f0
	  bge-      .loc_0x4A8
	  stfs      f2, 0x208(r1)

	.loc_0x4A8:
	  lfs       f0, 0x20C(r1)
	  fcmpo     cr0, f1, f0
	  bge-      .loc_0x4B8
	  stfs      f1, 0x20C(r1)

	.loc_0x4B8:
	  lfs       f0, 0x210(r1)
	  fcmpo     cr0, f5, f0
	  ble-      .loc_0x4C8
	  stfs      f5, 0x210(r1)

	.loc_0x4C8:
	  lfs       f0, 0x214(r1)
	  fcmpo     cr0, f2, f0
	  ble-      .loc_0x4D8
	  stfs      f2, 0x214(r1)

	.loc_0x4D8:
	  lfs       f0, 0x218(r1)
	  fcmpo     cr0, f1, f0
	  ble-      .loc_0x4E8
	  stfs      f1, 0x218(r1)

	.loc_0x4E8:
	  li        r0, 0xC
	  lfs       f0, 0x204(r1)
	  mtctr     r0
	  lfs       f1, 0x210(r1)
	  lfs       f2, 0x208(r1)
	  mr        r4, r25
	  lfs       f3, 0x214(r1)
	  lfs       f4, 0x20C(r1)
	  addi      r8, r1, 0x8
	  lfs       f5, 0x218(r1)
	  subi      r7, r28, 0x8
	  li        r24, 0
	  li        r5, 0
	  li        r3, 0

	.loc_0x520:
	  lwzu      r6, 0x8(r7)
	  lwz       r0, 0x4(r7)
	  stwu      r6, 0x8(r8)
	  stw       r0, 0x4(r8)
	  bdnz+     .loc_0x520
	  b         .loc_0x90C

	.loc_0x538:
	  stfs      f30, 0x1F4(r1)
	  addi      r0, r3, 0x4
	  stfs      f30, 0x1F0(r1)
	  stfs      f30, 0x1EC(r1)
	  stfs      f30, 0x200(r1)
	  stfs      f30, 0x1FC(r1)
	  stfs      f30, 0x1F8(r1)
	  stfs      f6, 0x1EC(r1)
	  stfs      f7, 0x1F0(r1)
	  stfs      f8, 0x1F4(r1)
	  stfs      f9, 0x1F8(r1)
	  stfs      f10, 0x1FC(r1)
	  stfs      f11, 0x200(r1)
	  stfs      f6, 0x1EC(r1)
	  stfs      f7, 0x1F0(r1)
	  stfs      f8, 0x1F4(r1)
	  stfs      f9, 0x1F8(r1)
	  stfs      f10, 0x1FC(r1)
	  stfs      f11, 0x200(r1)
	  lwz       r6, 0x16C(r29)
	  lwz       r7, 0x23C(r29)
	  lwzx      r0, r6, r0
	  lfs       f12, 0x1EC(r1)
	  mulli     r0, r0, 0xC
	  add       r6, r7, r0
	  lfs       f13, 0x0(r6)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x5AC
	  stfs      f13, 0x1EC(r1)

	.loc_0x5AC:
	  lfs       f13, 0x4(r6)
	  lfs       f12, 0x1F0(r1)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x5C0
	  stfs      f13, 0x1F0(r1)

	.loc_0x5C0:
	  lfs       f13, 0x8(r6)
	  lfs       f12, 0x1F4(r1)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x5D4
	  stfs      f13, 0x1F4(r1)

	.loc_0x5D4:
	  lfs       f13, 0x0(r6)
	  lfs       f12, 0x1F8(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x5E8
	  stfs      f13, 0x1F8(r1)

	.loc_0x5E8:
	  lfs       f13, 0x4(r6)
	  lfs       f12, 0x1FC(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x5FC
	  stfs      f13, 0x1FC(r1)

	.loc_0x5FC:
	  lfs       f13, 0x8(r6)
	  lfs       f12, 0x200(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x610
	  stfs      f13, 0x200(r1)

	.loc_0x610:
	  lwz       r6, 0x16C(r29)
	  addi      r0, r3, 0x8
	  lwz       r7, 0x23C(r29)
	  lwzx      r0, r6, r0
	  lfs       f12, 0x1EC(r1)
	  mulli     r0, r0, 0xC
	  add       r6, r7, r0
	  lfs       f13, 0x0(r6)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x63C
	  stfs      f13, 0x1EC(r1)

	.loc_0x63C:
	  lfs       f13, 0x4(r6)
	  lfs       f12, 0x1F0(r1)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x650
	  stfs      f13, 0x1F0(r1)

	.loc_0x650:
	  lfs       f13, 0x8(r6)
	  lfs       f12, 0x1F4(r1)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x664
	  stfs      f13, 0x1F4(r1)

	.loc_0x664:
	  lfs       f13, 0x0(r6)
	  lfs       f12, 0x1F8(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x678
	  stfs      f13, 0x1F8(r1)

	.loc_0x678:
	  lfs       f13, 0x4(r6)
	  lfs       f12, 0x1FC(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x68C
	  stfs      f13, 0x1FC(r1)

	.loc_0x68C:
	  lfs       f13, 0x8(r6)
	  lfs       f12, 0x200(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x6A0
	  stfs      f13, 0x200(r1)

	.loc_0x6A0:
	  lwz       r6, 0x16C(r29)
	  addi      r0, r3, 0xC
	  lwz       r7, 0x23C(r29)
	  lwzx      r0, r6, r0
	  lfs       f12, 0x1EC(r1)
	  mulli     r0, r0, 0xC
	  add       r6, r7, r0
	  lfs       f13, 0x0(r6)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x6CC
	  stfs      f13, 0x1EC(r1)

	.loc_0x6CC:
	  lfs       f13, 0x4(r6)
	  lfs       f12, 0x1F0(r1)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x6E0
	  stfs      f13, 0x1F0(r1)

	.loc_0x6E0:
	  lfs       f13, 0x8(r6)
	  lfs       f12, 0x1F4(r1)
	  fcmpo     cr0, f13, f12
	  bge-      .loc_0x6F4
	  stfs      f13, 0x1F4(r1)

	.loc_0x6F4:
	  lfs       f13, 0x0(r6)
	  lfs       f12, 0x1F8(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x708
	  stfs      f13, 0x1F8(r1)

	.loc_0x708:
	  lfs       f13, 0x4(r6)
	  lfs       f12, 0x1FC(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x71C
	  stfs      f13, 0x1FC(r1)

	.loc_0x71C:
	  lfs       f13, 0x8(r6)
	  lfs       f12, 0x200(r1)
	  fcmpo     cr0, f13, f12
	  ble-      .loc_0x730
	  stfs      f13, 0x200(r1)

	.loc_0x730:
	  lfs       f12, 0x1F8(r1)
	  fcmpo     cr0, f0, f12
	  cror      2, 0, 0x2
	  bne-      .loc_0x798
	  lfs       f12, 0x1EC(r1)
	  fcmpo     cr0, f1, f12
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x798
	  lfs       f12, 0x1FC(r1)
	  fcmpo     cr0, f2, f12
	  cror      2, 0, 0x2
	  bne-      .loc_0x798
	  lfs       f12, 0x1F0(r1)
	  fcmpo     cr0, f3, f12
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x798
	  lfs       f12, 0x200(r1)
	  fcmpo     cr0, f4, f12
	  cror      2, 0, 0x2
	  bne-      .loc_0x798
	  lfs       f12, 0x1F4(r1)
	  fcmpo     cr0, f5, f12
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x798
	  li        r0, 0x1
	  b         .loc_0x79C

	.loc_0x798:
	  li        r0, 0

	.loc_0x79C:
	  rlwinm.   r0,r0,0,24,31
	  beq-      .loc_0x904
	  li        r0, 0xC
	  mtctr     r0
	  addi      r8, r1, 0x184
	  addi      r7, r1, 0x8

	.loc_0x7B4:
	  lwzu      r6, 0x8(r7)
	  lwz       r0, 0x4(r7)
	  stwu      r6, 0x8(r8)
	  stw       r0, 0x4(r8)
	  bdnz+     .loc_0x7B4
	  stfs      f30, 0x110(r1)
	  li        r0, 0x4
	  mtctr     r0
	  addi      r9, r1, 0x18C
	  stfs      f30, 0x10C(r1)
	  li        r10, 0x1
	  stfs      f30, 0x108(r1)
	  li        r11, 0
	  li        r12, 0
	  stfs      f30, 0x13C(r1)
	  stfs      f30, 0x138(r1)
	  stfs      f30, 0x134(r1)
	  stfs      f30, 0x168(r1)
	  stfs      f30, 0x164(r1)
	  stfs      f30, 0x160(r1)

	.loc_0x804:
	  lwz       r6, 0x0(r9)
	  addi      r8, r3, 0x18
	  lwz       r7, 0x16C(r29)
	  lwz       r0, 0x4(r9)
	  rlwinm    r6,r6,2,0,29
	  add       r8, r7, r8
	  lwz       r7, 0x8(r9)
	  rlwinm    r0,r0,2,0,29
	  rlwinm    r7,r7,2,0,29
	  lfs       f28, 0x0(r8)
	  lfsx      f29, r30, r6
	  lfs       f13, 0x4(r8)
	  lfsx      f12, r30, r0
	  fmuls     f29, f28, f29
	  lfs       f27, 0x8(r8)
	  fmuls     f13, f13, f12
	  lfsx      f28, r30, r7
	  lfs       f12, 0xC(r8)
	  fmuls     f28, f27, f28
	  fadds     f13, f29, f13
	  fadds     f13, f28, f13
	  fsubs     f12, f13, f12
	  fcmpo     cr0, f12, f30
	  bge-      .loc_0x868
	  addi      r11, r11, 0x1

	.loc_0x868:
	  lwz       r6, 0xC(r9)
	  addi      r8, r3, 0x18
	  lwz       r7, 0x16C(r29)
	  lwz       r0, 0x10(r9)
	  rlwinm    r6,r6,2,0,29
	  add       r8, r7, r8
	  lwz       r7, 0x14(r9)
	  rlwinm    r0,r0,2,0,29
	  lfs       f28, 0x0(r8)
	  rlwinm    r7,r7,2,0,29
	  lfsx      f29, r30, r6
	  addi      r9, r9, 0xC
	  lfs       f13, 0x4(r8)
	  lfsx      f12, r30, r0
	  fmuls     f29, f28, f29
	  lfs       f27, 0x8(r8)
	  fmuls     f13, f13, f12
	  lfsx      f28, r30, r7
	  lfs       f12, 0xC(r8)
	  fmuls     f28, f27, f28
	  fadds     f13, f29, f13
	  fadds     f13, f28, f13
	  fsubs     f12, f13, f12
	  fcmpo     cr0, f12, f30
	  bge-      .loc_0x8D0
	  addi      r11, r11, 0x1

	.loc_0x8D0:
	  addi      r9, r9, 0xC
	  addi      r12, r12, 0x1
	  bdnz+     .loc_0x804
	  cmpwi     r11, 0x8
	  bne-      .loc_0x8E8
	  li        r10, 0

	.loc_0x8E8:
	  rlwinm.   r0,r10,0,24,31
	  beq-      .loc_0x904
	  lwz       r0, 0x16C(r29)
	  addi      r24, r24, 0x1
	  add       r0, r0, r3
	  stw       r0, 0x0(r4)
	  addi      r4, r4, 0x4

	.loc_0x904:
	  addi      r3, r3, 0x58
	  addi      r5, r5, 0x1

	.loc_0x90C:
	  lwz       r0, 0x168(r29)
	  cmpw      r5, r0
	  blt+      .loc_0x538
	  cmpwi     r24, 0
	  beq-      .loc_0xB20
	  add       r23, r23, r24
	  li        r3, 0
	  li        r4, 0
	  b         .loc_0x9B4

	.loc_0x930:
	  lwz       r5, 0x15C(r29)
	  lwz       r6, 0x164(r29)
	  divw      r0, r4, r5
	  mullw     r5, r0, r5
	  sub       r0, r4, r5
	  add       r0, r0, r5
	  rlwinm    r0,r0,2,0,29
	  lwzx      r5, r6, r0
	  lha       r0, 0x4(r5)
	  addi      r8, r5, 0
	  cmpw      r0, r24
	  bne-      .loc_0x9B0
	  cmpwi     r24, 0
	  mtctr     r24
	  addi      r6, r25, 0
	  li        r9, 0x1
	  li        r7, 0
	  ble-      .loc_0x9A0

	.loc_0x978:
	  lwz       r5, 0x8(r8)
	  lwz       r0, 0x0(r6)
	  lwzx      r5, r5, r7
	  cmplw     r5, r0
	  beq-      .loc_0x994
	  li        r9, 0
	  b         .loc_0x9A0

	.loc_0x994:
	  addi      r6, r6, 0x4
	  addi      r7, r7, 0x4
	  bdnz+     .loc_0x978

	.loc_0x9A0:
	  rlwinm.   r0,r9,0,24,31
	  beq-      .loc_0x9B0
	  mr        r3, r8
	  b         .loc_0x9BC

	.loc_0x9B0:
	  addi      r4, r4, 0x1

	.loc_0x9B4:
	  cmpw      r4, r22
	  blt+      .loc_0x930

	.loc_0x9BC:
	  cmplwi    r3, 0
	  bne-      .loc_0xAE0
	  lwz       r4, 0x15C(r29)
	  extsh     r0, r24
	  lwz       r5, 0x164(r29)
	  rlwinm    r3,r24,2,0,29
	  mullw     r4, r21, r4
	  add       r4, r20, r4
	  rlwinm    r4,r4,2,0,29
	  lwzx      r19, r5, r4
	  sth       r0, 0x4(r19)
	  bl        0x128C4
	  cmpwi     r24, 0
	  stw       r3, 0x8(r19)
	  li        r5, 0
	  ble-      .loc_0xB20
	  cmpwi     r24, 0x8
	  subi      r3, r24, 0x8
	  ble-      .loc_0xB70
	  addi      r0, r3, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r3, 0
	  mtctr     r0
	  addi      r3, r25, 0
	  li        r4, 0
	  ble-      .loc_0xB70

	.loc_0xA24:
	  lwz       r0, 0x0(r3)
	  addi      r11, r4, 0x4
	  lwz       r6, 0x8(r19)
	  addi      r10, r4, 0x8
	  addi      r9, r4, 0xC
	  stwx      r0, r6, r4
	  addi      r8, r4, 0x10
	  addi      r7, r4, 0x14
	  lwz       r18, 0x4(r3)
	  addi      r6, r4, 0x18
	  lwz       r12, 0x8(r19)
	  addi      r0, r4, 0x1C
	  addi      r4, r4, 0x20
	  stwx      r18, r12, r11
	  addi      r5, r5, 0x8
	  lwz       r12, 0x8(r3)
	  lwz       r11, 0x8(r19)
	  stwx      r12, r11, r10
	  lwz       r11, 0xC(r3)
	  lwz       r10, 0x8(r19)
	  stwx      r11, r10, r9
	  lwz       r10, 0x10(r3)
	  lwz       r9, 0x8(r19)
	  stwx      r10, r9, r8
	  lwz       r9, 0x14(r3)
	  lwz       r8, 0x8(r19)
	  stwx      r9, r8, r7
	  lwz       r8, 0x18(r3)
	  lwz       r7, 0x8(r19)
	  stwx      r8, r7, r6
	  lwz       r7, 0x1C(r3)
	  addi      r3, r3, 0x20
	  lwz       r6, 0x8(r19)
	  stwx      r7, r6, r0
	  bdnz+     .loc_0xA24
	  b         .loc_0xB70

	.loc_0xAB4:
	  sub       r0, r24, r5
	  cmpw      r5, r24
	  mtctr     r0
	  bge-      .loc_0xB20

	.loc_0xAC4:
	  lwz       r0, 0x0(r4)
	  addi      r4, r4, 0x4
	  lwz       r3, 0x8(r19)
	  stwx      r0, r3, r6
	  addi      r6, r6, 0x4
	  bdnz+     .loc_0xAC4
	  b         .loc_0xB20

	.loc_0xAE0:
	  lwz       r0, 0x15C(r29)
	  lwz       r4, 0x164(r29)
	  mullw     r0, r21, r0
	  lwz       r5, 0x8(r3)
	  add       r0, r20, r0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r4, r4, r0
	  stw       r5, 0x8(r4)
	  lwz       r0, 0x15C(r29)
	  lwz       r4, 0x164(r29)
	  mullw     r0, r21, r0
	  lha       r5, 0x4(r3)
	  add       r0, r20, r0
	  rlwinm    r0,r0,2,0,29
	  lwzx      r3, r4, r0
	  sth       r5, 0x4(r3)

	.loc_0xB20:
	  addi      r22, r22, 0x1
	  addi      r20, r20, 0x1

	.loc_0xB28:
	  lwz       r0, 0x15C(r29)
	  cmpw      r20, r0
	  blt+      .loc_0x374
	  addi      r21, r21, 0x1

	.loc_0xB38:
	  lwz       r0, 0x160(r29)
	  cmpw      r21, r0
	  blt+      .loc_0x368
	  lwz       r3, 0x2DEC(r13)
	  li        r4, 0x2
	  bl        0xA77C
	  lwz       r4, 0x8(r3)
	  lis       r0, 0x4330
	  lwz       r3, 0x4(r3)
	  sub       r3, r3, r4
	  sub       r3, r31, r3
	  stw       r3, 0x124C(r1)
	  stw       r0, 0x1248(r1)
	  b         .loc_0xB80

	.loc_0xB70:
	  rlwinm    r6,r5,2,0,29
	  addi      r4, r1, 0x220
	  add       r4, r4, r6
	  b         .loc_0xAB4

	.loc_0xB80:
	  lmw       r18, 0x1260(r1)
	  lwz       r0, 0x12C4(r1)
	  lfd       f31, 0x12B8(r1)
	  lfd       f30, 0x12B0(r1)
	  lfd       f29, 0x12A8(r1)
	  lfd       f28, 0x12A0(r1)
	  lfd       f27, 0x1298(r1)
	  addi      r1, r1, 0x12C0
	  mtlr      r0
	  blr
	*/
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
	if (pDck->mNumJoints != mJointCount) {
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
AnimData* BaseShape::importDck(char*, CmdStream*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x38(r1)
	  stmw      r27, 0x24(r1)
	  mr.       r29, r4
	  addi      r28, r3, 0
	  addi      r30, r5, 0
	  bne-      .loc_0x124
	  li        r3, 0x44
	  bl        0x124A8
	  addi      r30, r3, 0
	  mr.       r3, r30
	  beq-      .loc_0x110
	  lis       r4, 0x8022
	  lwz       r31, 0x58(r28)
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r30)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r30)
	  li        r29, 0
	  subi      r4, r13, 0x7CA8
	  stw       r29, 0x10(r30)
	  stw       r29, 0xC(r30)
	  stw       r29, 0x8(r30)
	  bl        -0xFCC8
	  lis       r3, 0x8023
	  subi      r0, r3, 0x775C
	  stw       r0, 0x0(r30)
	  lis       r3, 0x8023
	  subi      r0, r3, 0x77B8
	  stw       r29, 0x24(r30)
	  stw       r29, 0x38(r30)
	  stw       r0, 0x0(r30)
	  stw       r28, 0x34(r30)
	  stw       r31, 0x28(r30)
	  stw       r29, 0x30(r30)
	  lwz       r27, 0x28(r30)
	  mulli     r3, r27, 0xDC
	  addi      r3, r3, 0x8
	  bl        0x1242C
	  lis       r4, 0x8003
	  subi      r4, r4, 0x3578
	  addi      r7, r27, 0
	  li        r5, 0
	  li        r6, 0xDC
	  bl        0x1E0038
	  cmpwi     r31, 0
	  mtctr     r31
	  stw       r3, 0x3C(r30)
	  mr        r5, r29
	  ble-      .loc_0x110

	.loc_0xD0:
	  lwz       r3, 0x5C(r28)
	  addi      r0, r29, 0x18
	  lwzx      r0, r3, r0
	  cmpwi     r0, -0x1
	  bne-      .loc_0xEC
	  li        r4, 0
	  b         .loc_0xF8

	.loc_0xEC:
	  mulli     r0, r0, 0xDC
	  lwz       r3, 0x3C(r30)
	  add       r4, r3, r0

	.loc_0xF8:
	  lwz       r3, 0x3C(r30)
	  addi      r0, r5, 0x70
	  addi      r5, r5, 0xDC
	  stwx      r4, r3, r0
	  addi      r29, r29, 0x11C
	  bdnz+     .loc_0xD0

	.loc_0x110:
	  lis       r3, 0x8023
	  subi      r0, r3, 0x799C
	  stw       r0, 0x4(r30)
	  mr        r27, r30
	  b         .loc_0x1A0

	.loc_0x124:
	  li        r3, 0x44
	  bl        0x123A4
	  mr.       r27, r3
	  beq-      .loc_0x190
	  mr        r3, r29
	  bl        0xB6D0
	  lis       r4, 0x8022
	  addi      r0, r4, 0x738C
	  lis       r4, 0x8022
	  stw       r0, 0x0(r27)
	  addi      r0, r4, 0x737C
	  stw       r0, 0x0(r27)
	  li        r29, 0
	  addi      r4, r3, 0
	  stw       r29, 0x10(r27)
	  addi      r3, r27, 0
	  stw       r29, 0xC(r27)
	  stw       r29, 0x8(r27)
	  bl        -0xFDD0
	  lis       r3, 0x8023
	  subi      r0, r3, 0x775C
	  stw       r0, 0x0(r27)
	  lis       r3, 0x8023
	  subi      r0, r3, 0x77B8
	  stw       r29, 0x24(r27)
	  stw       r29, 0x38(r27)
	  stw       r0, 0x0(r27)

	.loc_0x190:
	  stw       r28, 0x34(r27)
	  addi      r3, r27, 0
	  addi      r4, r30, 0
	  bl        -0x7110

	.loc_0x1A0:
	  lwz       r3, 0x28(r27)
	  lwz       r0, 0x58(r28)
	  cmpw      r3, r0
	  beq-      .loc_0x1B4
	  li        r27, 0

	.loc_0x1B4:
	  lwz       r4, 0x18(r28)
	  mr        r3, r27
	  stw       r27, 0x0(r4)
	  lfs       f0, -0x7D20(r2)
	  lwz       r4, 0x18(r28)
	  stfs      f0, 0x4(r4)
	  lwz       r0, 0x3C(r1)
	  lmw       r27, 0x24(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
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
	if (pDca->mNumJoints != mJointCount) {
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
void BaseShape::importDca(char*, CmdStream*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80034DF4
 * Size:	0001C4
 */
AnimData* BaseShape::loadAnimation(char* name, bool a3)
{
	RandomAccessStream* pRas = gsys->openFile(name, a3, true);
	if (!pRas) {
		PRINT("failed to open %s\n", name);
		return nullptr;
	}

	CmdStream* pCmdStream = new CmdStream(pRas);
	if (!pCmdStream) {
		return nullptr;
	}

	int i = strlen(name) - 1;
	while (i >= 0 && name[i] != '.') {
		i--;
	}

	if (!strcmp(&name[i], ".dck")) {
		importDck(name, pCmdStream);
	} else if (!strcmp(&name[i], ".dca")) {
		importDca(name, pCmdStream);
	}

	pRas->close();

	if (!mCurrentAnimation->mData) {
		PRINT("returning NULL anim!!\n");
	}

	return mCurrentAnimation->mData;

	/*
	.loc_0x0:
	  mflr      r0
	  li        r6, 0x1
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x30(r1)
	  stmw      r26, 0x18(r1)
	  mr        r29, r3
	  mr        r26, r4
	  lwz       r3, 0x2DEC(r13)
	  lwz       r12, 0x1A0(r3)
	  lwz       r12, 0xC(r12)
	  mtlr      r12
	  blrl
	  mr.       r31, r3
	  beq-      .loc_0x1AC
	  li        r3, 0x11C
	  bl        0x121D4
	  addi      r28, r3, 0
	  mr.       r3, r28
	  beq-      .loc_0x54
	  mr        r4, r31
	  bl        0xBD38

	.loc_0x54:
	  cmplwi    r28, 0
	  addi      r30, r28, 0
	  beq-      .loc_0x1AC
	  mr        r3, r26
	  bl        0x1E45B4
	  subic.    r4, r3, 0x1
	  addi      r0, r4, 0x1
	  mtctr     r0
	  add       r3, r26, r4
	  blt-      .loc_0x94

	.loc_0x7C:
	  lbz       r0, 0x0(r3)
	  cmplwi    r0, 0x2E
	  beq-      .loc_0x94
	  subi      r4, r4, 0x1
	  subi      r3, r3, 0x1
	  bdnz+     .loc_0x7C

	.loc_0x94:
	  add       r27, r26, r4
	  addi      r3, r27, 0
	  subi      r4, r13, 0x7C24
	  bl        0x1E4330
	  cmpwi     r3, 0
	  bne-      .loc_0xC0
	  addi      r3, r29, 0
	  addi      r4, r26, 0
	  addi      r5, r30, 0
	  bl        -0x374
	  b         .loc_0x18C

	.loc_0xC0:
	  addi      r3, r27, 0
	  subi      r4, r13, 0x7C1C
	  bl        0x1E4308
	  cmpwi     r3, 0
	  bne-      .loc_0x18C
	  cmplwi    r26, 0
	  addi      r28, r26, 0
	  bne-      .loc_0x128
	  li        r3, 0x44
	  bl        0x1212C
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x184
	  addi      r3, r27, 0
	  subi      r4, r13, 0x7CA8
	  bl        .loc_0x1C4
	  lis       r3, 0x8023
	  subi      r0, r3, 0x775C
	  stw       r0, 0x0(r27)
	  li        r4, 0
	  lis       r3, 0x8023
	  stw       r4, 0x24(r27)
	  subi      r0, r3, 0x777C
	  stw       r4, 0x38(r27)
	  stw       r0, 0x0(r27)
	  b         .loc_0x184

	.loc_0x128:
	  li        r3, 0x44
	  bl        0x120E4
	  addi      r27, r3, 0
	  mr.       r0, r27
	  beq-      .loc_0x174
	  mr        r3, r28
	  bl        0xB40C
	  addi      r4, r3, 0
	  addi      r3, r27, 0
	  bl        .loc_0x1C4
	  lis       r3, 0x8023
	  subi      r0, r3, 0x775C
	  stw       r0, 0x0(r27)
	  li        r4, 0
	  lis       r3, 0x8023
	  stw       r4, 0x24(r27)
	  subi      r0, r3, 0x777C
	  stw       r4, 0x38(r27)
	  stw       r0, 0x0(r27)

	.loc_0x174:
	  stw       r29, 0x34(r27)
	  addi      r3, r27, 0
	  addi      r4, r30, 0
	  bl        -0x84B8

	.loc_0x184:
	  lwz       r3, 0x18(r29)
	  stw       r27, 0x0(r3)

	.loc_0x18C:
	  mr        r3, r31
	  lwz       r12, 0x4(r31)
	  lwz       r12, 0x4C(r12)
	  mtlr      r12
	  blrl
	  lwz       r3, 0x18(r29)
	  lwz       r3, 0x0(r3)
	  b         .loc_0x1B0

	.loc_0x1AC:
	  li        r3, 0

	.loc_0x1B0:
	  lmw       r26, 0x18(r1)
	  lwz       r0, 0x34(r1)
	  addi      r1, r1, 0x30
	  mtlr      r0
	  blr

	.loc_0x1C4:
	*/
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
void BaseShape::backupAnimOverrides(AnimContext**)
{
	/*
	.loc_0x0:
	  stw       r4, 0x20(r3)
	  li        r7, 0
	  li        r6, 0
	  b         .loc_0x28

	.loc_0x10:
	  lwz       r5, 0x1C(r3)
	  addi      r7, r7, 0x1
	  lwz       r4, 0x20(r3)
	  lwzx      r0, r5, r6
	  stwx      r0, r4, r6
	  addi      r6, r6, 0x4

	.loc_0x28:
	  lwz       r0, 0x58(r3)
	  cmpw      r7, r0
	  blt+      .loc_0x10
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80035030
 * Size:	000034
 */
void BaseShape::restoreAnimOverrides()
{
	/*
	.loc_0x0:
	  li        r7, 0
	  li        r6, 0
	  b         .loc_0x24

	.loc_0xC:
	  lwz       r5, 0x20(r3)
	  addi      r7, r7, 0x1
	  lwz       r4, 0x1C(r3)
	  lwzx      r0, r5, r6
	  stwx      r0, r4, r6
	  addi      r6, r6, 0x4

	.loc_0x24:
	  lwz       r0, 0x58(r3)
	  cmpw      r7, r0
	  blt+      .loc_0xC
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80035064
 * Size:	000094
 */
void BaseShape::overrideAnim(int, AnimContext*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  mulli     r0, r4, 0x11C
	  stwu      r1, -0x28(r1)
	  stw       r31, 0x24(r1)
	  stw       r30, 0x20(r1)
	  mr        r30, r5
	  lwz       r3, 0x5C(r3)
	  add       r4, r3, r0
	  lwz       r3, 0x118(r4)
	  lwz       r0, 0x14(r4)
	  lwz       r3, 0x1C(r3)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  lwz       r31, 0x10(r4)
	  cmplwi    r31, 0
	  beq-      .loc_0x7C
	  b         .loc_0x74

	.loc_0x48:
	  lwz       r3, 0x118(r31)
	  lwz       r0, 0x14(r31)
	  lwz       r3, 0x1C(r3)
	  rlwinm    r0,r0,2,0,29
	  stwx      r30, r3, r0
	  lwz       r3, 0x10(r31)
	  cmplwi    r3, 0
	  beq-      .loc_0x70
	  mr        r4, r30
	  bl        -0xAD44

	.loc_0x70:
	  lwz       r31, 0xC(r31)

	.loc_0x74:
	  cmplwi    r31, 0
	  bne+      .loc_0x48

	.loc_0x7C:
	  lwz       r0, 0x2C(r1)
	  lwz       r31, 0x24(r1)
	  lwz       r30, 0x20(r1)
	  addi      r1, r1, 0x28
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	800350F8
 * Size:	000074
 */
AnimFrameCacher::AnimFrameCacher(int)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x20(r1)
	  stw       r31, 0x1C(r1)
	  stw       r30, 0x18(r1)
	  addi      r30, r4, 0
	  stw       r29, 0x14(r1)
	  addi      r29, r3, 0
	  li        r3, 0x130
	  bl        0x11EE8
	  addi      r31, r3, 0
	  mr.       r3, r31
	  beq-      .loc_0x3C
	  rlwinm    r4,r30,6,0,25
	  bl        -0x107B4

	.loc_0x3C:
	  stw       r31, 0x0(r29)
	  subi      r3, r13, 0x7C14
	  addi      r0, r29, 0x4
	  stw       r3, 0x4(r29)
	  mr        r3, r29
	  stw       r0, 0x8(r29)
	  stw       r0, 0xC(r29)
	  lwz       r0, 0x24(r1)
	  lwz       r31, 0x1C(r1)
	  lwz       r30, 0x18(r1)
	  lwz       r29, 0x14(r1)
	  addi      r1, r1, 0x20
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void AnimFrameCacher::updateInfo(AnimCacheInfo*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void AnimFrameCacher::removeOldest()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003516C
 * Size:	0001A8
 */
void AnimFrameCacher::cacheFrameSpace(int, AnimCacheInfo*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  rlwinm    r0,r4,6,0,25
	  stwu      r1, -0x38(r1)
	  stmw      r26, 0x20(r1)
	  rlwinm    r27,r4,2,0,29
	  addi      r30, r4, 0
	  add       r4, r27, r0
	  addi      r0, r4, 0x3B
	  addi      r29, r3, 0
	  addi      r31, r5, 0
	  rlwinm    r26,r0,0,0,26
	  li        r28, 0

	.loc_0x34:
	  lwz       r3, 0x0(r29)
	  bl        -0x103DC
	  cmplw     r3, r26
	  ble-      .loc_0x154
	  lwz       r3, 0x0(r29)
	  mr        r4, r26
	  bl        -0x1063C
	  addi      r4, r3, 0x1C
	  addi      r0, r27, 0x1C
	  stw       r4, 0x18(r3)
	  add       r0, r3, r0
	  stw       r0, 0x14(r3)
	  addi      r0, r31, 0x10
	  cmpwi     r30, 0
	  stw       r0, 0xC(r3)
	  li        r12, 0
	  ble-      .loc_0x130
	  cmpwi     r30, 0x8
	  subi      r4, r30, 0x8
	  ble-      .loc_0x18C
	  addi      r0, r4, 0x7
	  rlwinm    r0,r0,29,3,31
	  cmpwi     r4, 0
	  mtctr     r0
	  li        r11, 0
	  ble-      .loc_0x18C

	.loc_0x9C:
	  lwz       r4, 0x18(r3)
	  li        r10, 0
	  addi      r0, r11, 0x4
	  stwx      r10, r4, r11
	  addi      r8, r11, 0x8
	  addi      r7, r11, 0xC
	  lwz       r4, 0x18(r3)
	  addi      r6, r11, 0x10
	  addi      r5, r11, 0x14
	  stwx      r10, r4, r0
	  addi      r4, r11, 0x18
	  addi      r0, r11, 0x1C
	  lwz       r9, 0x18(r3)
	  addi      r11, r11, 0x20
	  addi      r12, r12, 0x8
	  stwx      r10, r9, r8
	  lwz       r8, 0x18(r3)
	  stwx      r10, r8, r7
	  lwz       r7, 0x18(r3)
	  stwx      r10, r7, r6
	  lwz       r6, 0x18(r3)
	  stwx      r10, r6, r5
	  lwz       r5, 0x18(r3)
	  stwx      r10, r5, r4
	  lwz       r4, 0x18(r3)
	  stwx      r10, r4, r0
	  bdnz+     .loc_0x9C
	  b         .loc_0x18C

	.loc_0x10C:
	  sub       r0, r30, r12
	  cmpw      r12, r30
	  mtctr     r0
	  li        r0, 0
	  bge-      .loc_0x130

	.loc_0x120:
	  lwz       r4, 0x18(r3)
	  stwx      r0, r4, r5
	  addi      r5, r5, 0x4
	  bdnz+     .loc_0x120

	.loc_0x130:
	  stw       r3, 0x10(r31)
	  addi      r0, r29, 0x4
	  lwz       r4, 0xC(r29)
	  stw       r4, 0x8(r3)
	  stw       r0, 0x4(r3)
	  lwz       r4, 0xC(r29)
	  stw       r3, 0x4(r4)
	  stw       r3, 0xC(r29)
	  b         .loc_0x194

	.loc_0x154:
	  lwz       r5, 0x8(r29)
	  lwz       r0, 0x4(r5)
	  mr        r4, r5
	  lwz       r3, 0x8(r5)
	  stw       r0, 0x4(r3)
	  lwz       r0, 0x8(r5)
	  lwz       r3, 0x4(r5)
	  stw       r0, 0x8(r3)
	  lwz       r3, 0xC(r5)
	  stw       r28, 0x0(r3)
	  lwz       r3, 0x0(r29)
	  bl        -0x10650
	  b         .loc_0x34
	  b         .loc_0x194

	.loc_0x18C:
	  rlwinm    r5,r12,2,0,29
	  b         .loc_0x10C

	.loc_0x194:
	  lmw       r26, 0x20(r1)
	  lwz       r0, 0x3C(r1)
	  addi      r1, r1, 0x38
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80035314
 * Size:	0002E0
 */
void BaseShape::updateAnim(Graphics&, Matrix4f&, f32*)
{
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0xD0(r1)
	  stfd      f31, 0xC8(r1)
	  stmw      r21, 0x9C(r1)
	  mr        r30, r3
	  addi      r31, r5, 0
	  addi      r21, r6, 0
	  lwz       r7, 0x2DEC(r13)
	  lwz       r3, 0x1B8(r7)
	  addi      r0, r3, 0x1
	  stw       r0, 0x1B8(r7)
	  mr        r3, r4
	  lwz       r4, 0x2C(r30)
	  bl        -0xCE38
	  stw       r3, 0x28(r30)
	  lwz       r3, 0x18(r30)
	  lwz       r0, 0x0(r3)
	  cmplwi    r0, 0
	  beq-      .loc_0x200
	  cmplwi    r21, 0
	  bne-      .loc_0x6C
	  lwz       r12, 0xC(r3)
	  lfs       f1, 0x8(r3)
	  lwz       r12, 0x8(r12)
	  mtlr      r12
	  blrl

	.loc_0x6C:
	  li        r23, 0
	  mulli     r26, r23, 0xDC
	  li        r28, 0
	  addi      r27, r28, 0
	  rlwinm    r25,r23,6,0,25
	  rlwinm    r24,r23,1,0,30
	  b         .loc_0x1E8

	.loc_0x88:
	  lwz       r3, 0x1C(r30)
	  cmplwi    r21, 0
	  lwzx      r3, r3, r28
	  lwz       r22, 0x0(r3)
	  beq-      .loc_0xA4
	  mr        r29, r21
	  b         .loc_0xA8

	.loc_0xA4:
	  addi      r29, r3, 0x4

	.loc_0xA8:
	  lwz       r3, 0x24(r30)
	  cmplwi    r3, 0
	  beq-      .loc_0x148
	  lwz       r0, 0x24(r22)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0x148
	  lfs       f0, 0x0(r29)
	  lwz       r0, 0x30(r22)
	  fctiwz    f0, f0
	  stfd      f0, 0x88(r1)
	  lwz       r4, 0x8C(r1)
	  stfd      f0, 0x90(r1)
	  cmpw      r4, r0
	  lwz       r0, 0x94(r1)
	  mulli     r0, r0, 0x1C
	  lwz       r4, 0x40(r22)
	  add       r5, r4, r0
	  lwz       r7, 0x10(r5)
	  cmplwi    r7, 0
	  bne-      .loc_0x104
	  lwz       r4, 0x2C(r22)
	  bl        -0x2A4
	  b         .loc_0x148

	.loc_0x104:
	  lwz       r0, 0xC(r3)
	  cmplw     r0, r7
	  beq-      .loc_0x148
	  lwz       r6, 0x4(r7)
	  addi      r0, r3, 0x4
	  lwz       r4, 0x8(r7)
	  stw       r6, 0x4(r4)
	  lwz       r6, 0x8(r7)
	  lwz       r4, 0x4(r7)
	  stw       r6, 0x8(r4)
	  lwz       r5, 0x10(r5)
	  lwz       r4, 0xC(r3)
	  stw       r4, 0x8(r5)
	  stw       r0, 0x4(r5)
	  lwz       r4, 0xC(r3)
	  stw       r5, 0x4(r4)
	  stw       r5, 0xC(r3)

	.loc_0x148:
	  lwz       r0, 0x30(r22)
	  cmpwi     r0, 0
	  beq-      .loc_0x1B4
	  lwz       r3, 0x5C(r30)
	  addi      r0, r27, 0x18
	  lwzx      r0, r3, r0
	  cmpwi     r0, -0x1
	  beq-      .loc_0x178
	  lwz       r3, 0x28(r30)
	  rlwinm    r0,r0,6,0,25
	  add       r0, r3, r0
	  b         .loc_0x17C

	.loc_0x178:
	  mr        r0, r31

	.loc_0x17C:
	  lwz       r12, 0x0(r22)
	  mr        r5, r0
	  lwz       r4, 0x28(r30)
	  mr        r3, r22
	  lwz       r12, 0x14(r12)
	  lwz       r7, 0x20(r22)
	  add       r6, r4, r25
	  lwz       r0, 0x3C(r22)
	  mtlr      r12
	  lhzx      r4, r7, r24
	  lfs       f1, 0x0(r29)
	  add       r7, r0, r26
	  blrl
	  b         .loc_0x1D0

	.loc_0x1B4:
	  lwz       r0, 0x28(r30)
	  addi      r4, r27, 0x48
	  lwz       r6, 0x5C(r30)
	  addi      r3, r31, 0
	  add       r5, r0, r25
	  add       r4, r6, r4
	  bl        0x1C86E0

	.loc_0x1D0:
	  addi      r28, r28, 0x4
	  addi      r27, r27, 0x11C
	  addi      r26, r26, 0xDC
	  addi      r25, r25, 0x40
	  addi      r24, r24, 0x2
	  addi      r23, r23, 0x1

	.loc_0x1E8:
	  lwz       r0, 0x58(r30)
	  cmpw      r23, r0
	  blt+      .loc_0x88
	  mr        r3, r30
	  bl        .loc_0x2E0
	  b         .loc_0x2C8

	.loc_0x200:
	  lwz       r22, 0x5C(r30)
	  li        r23, 0
	  lfs       f31, -0x7D20(r2)
	  b         .loc_0x2BC

	.loc_0x210:
	  stfs      f31, 0x6C(r1)
	  stfs      f31, 0x68(r1)
	  stfs      f31, 0x64(r1)
	  stfs      f31, 0x78(r1)
	  stfs      f31, 0x74(r1)
	  stfs      f31, 0x70(r1)
	  stfs      f31, 0x84(r1)
	  stfs      f31, 0x80(r1)
	  stfs      f31, 0x7C(r1)
	  lwz       r3, 0x24(r22)
	  lwz       r0, 0x28(r22)
	  stw       r3, 0x64(r1)
	  stw       r0, 0x68(r1)
	  lwz       r0, 0x2C(r22)
	  stw       r0, 0x6C(r1)
	  lwz       r3, 0x30(r22)
	  lwz       r0, 0x34(r22)
	  stw       r3, 0x70(r1)
	  stw       r0, 0x74(r1)
	  lwz       r0, 0x38(r22)
	  stw       r0, 0x78(r1)
	  lwz       r3, 0x3C(r22)
	  lwz       r0, 0x40(r22)
	  stw       r3, 0x7C(r1)
	  stw       r0, 0x80(r1)
	  lwz       r0, 0x44(r22)
	  stw       r0, 0x84(r1)
	  lwz       r0, 0x18(r22)
	  cmpwi     r0, -0x1
	  bne-      .loc_0x290
	  mr        r3, r31
	  b         .loc_0x2A0

	.loc_0x290:
	  mulli     r3, r0, 0x11C
	  lwz       r0, 0x5C(r30)
	  addi      r3, r3, 0x48
	  add       r3, r0, r3

	.loc_0x2A0:
	  addi      r4, r3, 0
	  addi      r3, r22, 0x48
	  addi      r5, r1, 0x24
	  addi      r6, r1, 0x64
	  bl        0x8CCC
	  addi      r22, r22, 0x11C
	  addi      r23, r23, 0x1

	.loc_0x2BC:
	  lwz       r0, 0x58(r30)
	  cmpw      r23, r0
	  blt+      .loc_0x210

	.loc_0x2C8:
	  lmw       r21, 0x9C(r1)
	  lwz       r0, 0xD4(r1)
	  lfd       f31, 0xC8(r1)
	  addi      r1, r1, 0xD0
	  mtlr      r0
	  blr

	.loc_0x2E0:
	*/
}

/*
 * --INFO--
 * Address:	800355F4
 * Size:	000190
 */
void BaseShape::calcWeightedMatrices()
{
	for (int i = 0; i < mEnvelopeCount; i++) {
		Matrix4f& mtx = getAnimMatrix(mJointCount);
		mtx.set(0.0f);

		for (int j = 0; j < mEnvelopeList[i].mIndexCount; j++) {
			int idx    = mEnvelopeList[i].mIndices[j];
			int weight = mEnvelopeList[i].mWeights[j];

			Matrix4f weighted;
			Matrix4f& jointMtx = mJointList[idx].mAnimMatrix;
			Matrix4f& shapeMtx = getAnimMatrix(idx);
			shapeMtx.multiplyTo(jointMtx, weighted);

			Matrix4f* mtx = &getAnimMatrix(mJointCount);
			PSMTXConcat(mtx->mMtx, weighted.mMtx, mtx->mMtx);
		}
	}
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x88(r1)
	  stfd      f31, 0x80(r1)
	  stfd      f30, 0x78(r1)
	  stmw      r25, 0x5C(r1)
	  addi      r27, r3, 0
	  addi      r29, r1, 0x14
	  addi      r28, r1, 0xC
	  li        r31, 0
	  li        r26, 0
	  lfs       f31, -0x7D20(r2)
	  b         .loc_0x168

	.loc_0x34:
	  lwz       r3, 0x58(r27)
	  li        r0, 0x2
	  mtctr     r0
	  lwz       r4, 0x28(r27)
	  add       r0, r3, r31
	  rlwinm    r0,r0,6,0,25
	  add       r3, r4, r0

	.loc_0x50:
	  stfs      f31, 0x0(r3)
	  stfs      f31, 0x4(r3)
	  stfs      f31, 0x8(r3)
	  stfs      f31, 0xC(r3)
	  stfs      f31, 0x10(r3)
	  stfs      f31, 0x14(r3)
	  addi      r3, r3, 0x18
	  bdnz+     .loc_0x50
	  li        r30, 0
	  li        r25, 0
	  b         .loc_0x150

	.loc_0x7C:
	  lwz       r0, 0x34(r27)
	  addi      r5, r1, 0x14
	  lwz       r6, 0x28(r27)
	  add       r3, r0, r26
	  lwz       r0, 0x5C(r27)
	  lwz       r4, 0x4(r3)
	  lwz       r3, 0x8(r3)
	  lwzx      r7, r4, r25
	  lfsx      f30, r3, r25
	  mulli     r4, r7, 0x11C
	  rlwinm    r3,r7,6,0,25
	  addi      r4, r4, 0x88
	  add       r3, r6, r3
	  add       r4, r0, r4
	  bl        0x1C8518
	  lwz       r0, 0x58(r27)
	  lwz       r5, 0x28(r27)
	  lwz       r3, -0x7CC8(r2)
	  add       r4, r0, r31
	  lwz       r0, -0x7CC4(r2)
	  rlwinm    r4,r4,6,0,25
	  stw       r3, 0xC(r1)
	  add       r3, r5, r4
	  stw       r0, 0x10(r1)
	  stfs      f30, 0xC(r1)
	  stfs      f30, 0x10(r1)
	  psq_l     f0,0x0(r28),0,0
	  psq_l     f1,0x0(r3),0,0
	  psq_l     f2,0x0(r29),0,0
	  ps_madd   f1, f2, f0, f1
	  psq_st    f1,0x0(r3),0,0
	  psq_l     f3,0x8(r3),0,0
	  psq_l     f2,0x8(r29),0,0
	  ps_madd   f3, f2, f0, f3
	  psq_st    f3,0x8(r3),0,0
	  psq_l     f1,0x10(r3),0,0
	  psq_l     f2,0x10(r29),0,0
	  ps_madd   f1, f2, f0, f1
	  psq_st    f1,0x10(r3),0,0
	  psq_l     f3,0x18(r3),0,0
	  psq_l     f2,0x18(r29),0,0
	  ps_madd   f3, f2, f0, f3
	  psq_st    f3,0x18(r3),0,0
	  psq_l     f1,0x20(r3),0,0
	  psq_l     f2,0x20(r29),0,0
	  ps_madd   f1, f2, f0, f1
	  psq_st    f1,0x20(r3),0,0
	  psq_l     f3,0x28(r3),0,0
	  psq_l     f2,0x28(r29),0,0
	  ps_madd   f3, f2, f0, f3
	  psq_st    f3,0x28(r3),0,0
	  addi      r30, r30, 0x1
	  addi      r25, r25, 0x4

	.loc_0x150:
	  lwz       r3, 0x34(r27)
	  lwzx      r0, r3, r26
	  cmpw      r30, r0
	  blt+      .loc_0x7C
	  addi      r31, r31, 0x1
	  addi      r26, r26, 0xC

	.loc_0x168:
	  lwz       r0, 0x30(r27)
	  cmpw      r31, r0
	  blt+      .loc_0x34
	  lmw       r25, 0x5C(r1)
	  lwz       r0, 0x8C(r1)
	  lfd       f31, 0x80(r1)
	  lfd       f30, 0x78(r1)
	  addi      r1, r1, 0x88
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	80035784
 * Size:	000140
 */
void BaseShape::makeNormalIndexes(u16* indices)
{

	/*
	.loc_0x0:
	  stwu      r1, -0x30(r1)
	  li        r7, 0
	  li        r6, 0
	  stmw      r27, 0x1C(r1)
	  b         .loc_0x128

	.loc_0x14:
	  lwz       r8, 0x64(r3)
	  li        r9, 0
	  lwz       r10, 0x54(r3)
	  li        r5, 0
	  lwzx      r8, r8, r6
	  lwz       r0, 0x20(r8)
	  mulli     r0, r0, 0x30
	  add       r8, r10, r0
	  b         .loc_0x114

	.loc_0x38:
	  lwz       r0, 0x24(r8)
	  li        r10, 0
	  add       r31, r0, r5
	  lwz       r30, 0xC(r31)
	  b         .loc_0x100

	.loc_0x4C:
	  lwz       r29, 0x1C(r30)
	  lwz       r28, 0x18(r30)
	  b         .loc_0xE0

	.loc_0x58:
	  lbz       r0, 0x0(r29)
	  addi      r29, r29, 0x1
	  cmpwi     r0, 0
	  bne-      .loc_0x70
	  li        r28, 0
	  b         .loc_0xE0

	.loc_0x70:
	  lbz       r11, 0x0(r29)
	  lbz       r0, 0x1(r29)
	  addi      r29, r29, 0x2
	  rlwimi.   r0,r11,8,16,23
	  mtctr     r0
	  ble-      .loc_0xE0

	.loc_0x88:
	  lwz       r11, 0x2C(r8)
	  rlwinm.   r0,r11,0,31,31
	  beq-      .loc_0x98
	  addi      r29, r29, 0x1

	.loc_0x98:
	  rlwinm.   r0,r11,0,30,30
	  beq-      .loc_0xA4
	  addi      r29, r29, 0x1

	.loc_0xA4:
	  lbz       r11, 0x0(r29)
	  li        r27, 0x6
	  lbz       r0, 0x1(r29)
	  rlwimi    r0,r11,8,16,23
	  lbz       r12, 0x2(r29)
	  lbz       r11, 0x3(r29)
	  rlwinm    r0,r0,1,15,30
	  rlwimi    r11,r12,8,16,23
	  sthx      r11, r4, r0
	  lwz       r0, 0x2C(r8)
	  rlwinm.   r0,r0,0,29,29
	  beq-      .loc_0xD8
	  li        r27, 0x8

	.loc_0xD8:
	  add       r29, r29, r27
	  bdnz+     .loc_0x88

	.loc_0xE0:
	  cmplwi    r28, 0
	  beq-      .loc_0xF8
	  lwz       r0, 0x1C(r30)
	  add       r0, r0, r28
	  cmplw     r29, r0
	  blt+      .loc_0x58

	.loc_0xF8:
	  addi      r30, r30, 0x74
	  addi      r10, r10, 0x1

	.loc_0x100:
	  lwz       r0, 0x8(r31)
	  cmpw      r10, r0
	  blt+      .loc_0x4C
	  addi      r5, r5, 0x10
	  addi      r9, r9, 0x1

	.loc_0x114:
	  lwz       r0, 0x20(r8)
	  cmpw      r9, r0
	  blt+      .loc_0x38
	  addi      r6, r6, 0x4
	  addi      r7, r7, 0x1

	.loc_0x128:
	  lwz       r0, 0x60(r3)
	  cmpw      r7, r0
	  blt+      .loc_0x14
	  lmw       r27, 0x1C(r1)
	  addi      r1, r1, 0x30
	  blr
	*/
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

/*
 * --INFO--
 * Address:	80035A68
 * Size:	000004
 */
void AnimData::writeType(RandomAccessStream&)
{
}

/*
 * --INFO--
 * Address:	80035A9C
 * Size:	000088
 */
void __sinit_shapeBase_cpp(void)
{
	/*
	.loc_0x0:
	  mflr      r0
	  lis       r3, 0x8039
	  stw       r0, 0x4(r1)
	  li        r5, 0
	  li        r6, 0xC
	  stwu      r1, -0x10(r1)
	  li        r7, 0x200
	  stw       r31, 0xC(r1)
	  stw       r30, 0x8(r1)
	  subi      r30, r3, 0x38C0
	  lis       r3, 0x8003
	  addi      r31, r3, 0x5B24
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x1DEF9C
	  addi      r4, r31, 0
	  addi      r3, r30, 0x1800
	  li        r5, 0
	  li        r6, 0xC
	  li        r7, 0x200
	  bl        0x1DEF84
	  lis       r3, 0x8003
	  addi      r4, r3, 0x38B4
	  addi      r3, r30, 0x3000
	  li        r5, 0
	  li        r6, 0x8
	  li        r7, 0x200
	  bl        0x1DEF68
	  lwz       r0, 0x14(r1)
	  lwz       r31, 0xC(r1)
	  lwz       r30, 0x8(r1)
	  addi      r1, r1, 0x10
	  mtlr      r0
	  blr
	*/
}
