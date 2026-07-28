#include "Graphics.h"

#include <limits.h>
#include <math.h>
#include <stdarg.h>

#include <Dolphin/GX/GXEnum.h>
#include <gl/gl.h>
#include <gl/glext.h>
#include <gl/glu.h>
#include <wingdi.h>

#include "Age.h"
#include "DebugLog.h"
#include "Font.h"
#include "Mesh.h"
#include "Shape.h"
#include "Vector.h"

DEFINE_ERROR(__LINE__);
DEFINE_PRINT("OGLGraphics")

/**
 * @note All objects with static linkage have fabricated names in DLL-exclusive code
 */

static Vector2f s_glTexCoordBuffer[128];
static Vector3f s_glVertexPosNrmBuffer[2][128];
static bool s_hasGlExtCompiledVertexArray                         = false;
static PFNGLLOCKARRAYSEXTPROC s_glLockArraysEXT                   = nullptr;
static PFNGLUNLOCKARRAYSEXTPROC s_glUnlockArraysEXT               = nullptr;
static PFNGLACTIVETEXTUREARBPROC s_glActiveTextureARB             = nullptr;
static PFNGLMULTITEXCOORD2FARBPROC s_glMultiTexCoord2fARB         = nullptr;
static PFNGLCLIENTACTIVETEXTUREARBPROC s_glClientActiveTextureARB = nullptr;
static BOOL s_isOddNumberedRenderInit                             = FALSE;
static bool s_isEnvMapTexMatrixSet                                = false;

/**
 * @todo Documentation
 */
OGLGraphics::OGLGraphics(int screenWidth, int screenHeight)
{
	mScreenWidth  = screenWidth;
	mScreenHeight = screenHeight;
	mOGLVendor.init((char*)glGetString(GL_VENDOR));
	mOGLRenderer.init((char*)glGetString(GL_RENDERER));
	mOGLVersion.init((char*)glGetString(GL_VERSION));
	mOGLExtensions.init((char*)glGetString(GL_EXTENSIONS));

	if (s_glLockArraysEXT) {
		return;
	}

	PRINT("Vendor: %s\n", mOGLVendor.mString);
	PRINT("Renderer: %s\n", mOGLRenderer.mString);
	PRINT("Version: %s\n", mOGLVersion.mString);

	if (mOGLExtensions.contains("GL_EXT_compiled_vertex_array")) {
		s_hasGlExtCompiledVertexArray = true;
		// Nothing actually uses these OpenGL extension functions
		s_glLockArraysEXT   = (PFNGLLOCKARRAYSEXTPROC)wglGetProcAddress("glLockArraysEXT");
		s_glUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC)wglGetProcAddress("glUnlockArraysEXT");
	}

	if (mOGLExtensions.contains("GL_ARB_multitexture")) {
		s_glActiveTextureARB       = (PFNGLACTIVETEXTUREARBPROC)wglGetProcAddress("glActiveTextureARB");
		s_glMultiTexCoord2fARB     = (PFNGLMULTITEXCOORD2FARBPROC)wglGetProcAddress("glMultiTexCoord2fARB");
		s_glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)wglGetProcAddress("glClientActiveTextureARB");
	}
}

/**
 * @todo Documentation
 */
void OGLGraphics::initRender(int screenWidth, int screenHeight)
{
	Graphics::initRender(screenWidth, screenHeight);
	s_isOddNumberedRenderInit ^= TRUE;

	mLightIntensity = 1.0f;
	glViewport(0, 0, screenWidth, screenHeight);
	s_isEnvMapTexMatrixSet = false;

	glEnable(GL_SCISSOR_TEST);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glPolygonMode(GL_FRONT, GL_FILL);

	mLineWidth = 1.0f;
	glLineWidth(mLineWidth);
	glPointSize(4.0f);

	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	glDisable(GL_TEXTURE_2D);

	setColour(COLOUR_WHITE, true);

	glDisable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	mIsLightingEnabled = false;
	glShadeModel(GL_SMOOTH);

	useTexture(nullptr, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	mBlendMode = BLEND_Alpha;

	glDepthMask(GL_TRUE);
	mIsDepthEnabled = true;

	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	mCullMode = 1; // front culling mode
	mCullFlip = 0;

	GLint whichDrawBuffer;
	glGetIntegerv(GL_DRAW_BUFFER, &whichDrawBuffer);
	glDrawBuffer(GL_BACK);

	mHasTexGen     = FALSE;
	mCustomScale   = nullptr;
	mMatRenderMask = MATFLAG_Opaque | MATFLAG_AlphaTest | MATFLAG_AlphaBlend;
	setMatHandler(nullptr);

	gsys->resetLFlares();
}

/**
 * @todo Documentation
 */
void OGLGraphics::useMatrix(immut Matrix4f& mtx, int a)
{
	Matrix4f invMtx;

	mActiveMatrix = &mtx;
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			invMtx.mMtx[col][row] = mtx.mMtx[row][col];
		}
	}
	glLoadMatrixf(reinterpret_cast<immut GLfloat*>(invMtx.mMtx));

	if (mLightCam) {
		initProjTex(true, mLightCam);
	} else {
		initProjTex(false, nullptr);
	}
}

/**
 * @todo Documentation
 */
void OGLGraphics::setCamera(Camera* camera)
{
	mCamera = camera;
}

/**
 * @todo Documentation
 */
void OGLGraphics::calcViewMatrix(immut Matrix4f& modelMtx, Matrix4f& viewMtx)
{
	mLastModelMatrix = &modelMtx;
	mCamera->mLookAtMtx.multiplyTo(modelMtx, viewMtx);
}

/**
 * @todo Documentation
 */
int OGLGraphics::setCBlending(int blendMode)
{
	int oldBlendMode = mBlendMode;
	mBlendMode       = blendMode;

	if (blendMode != 4) {
		glEnable(GL_DEPTH_TEST);
	}
	switch (blendMode) {
	case BLEND_Alpha:
	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDepthMask(GL_TRUE);
		break;
	}
	case BLEND_Additive:
	{
		glBlendFunc(GL_SRC_COLOR, GL_ONE);
		glDepthMask(GL_FALSE);
		break;
	}
	case BLEND_Subtractive:
	{
		glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_COLOR);
		glDepthMask(GL_TRUE);
		break;
	}
	case BLEND_AlphaAdditive:
	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		glDepthMask(GL_FALSE);
		break;
	}
	case BLEND_AdditiveNoZ:
	{
		glBlendFunc(GL_SRC_COLOR, GL_ONE);
		glDepthMask(GL_FALSE);
		glDisable(GL_DEPTH_TEST);
		break;
	}
	}

	return oldBlendMode;
}

/**
 * @todo Documentation
 */
int OGLGraphics::setCullFront(int cullMode)
{
	int oldCullMode = mCullMode;
	mCullMode       = cullMode;

	if (cullMode == 1) {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	} else if (cullMode == 0) {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
	} else {
		glDisable(GL_CULL_FACE);
	}

	return oldCullMode;
}

/**
 * @todo Documentation
 */
bool OGLGraphics::setDepth(bool enabled)
{
	bool oldEnabled = mIsDepthEnabled;
	mIsDepthEnabled = enabled;

	if (!enabled) {
		glDepthMask(GL_FALSE);
	} else {
		glDepthMask(GL_TRUE);
	}

	return oldEnabled;
}

/**
 * @todo Documentation
 */
bool OGLGraphics::setLighting(bool enabled, PVWLightingInfo* lightInfo)
{
	bool oldEnabled    = mIsLightingEnabled;
	mIsLightingEnabled = enabled;

	for (int i = 0; i < 8; ++i) {
		if (enabled && (mActiveLightMask & (1 << i))) {
			glEnable(GL_LIGHT0 + i);
		} else {
			glDisable(GL_LIGHT0 + i);
		}
	}
	if (!enabled) {
		glDisable(GL_LIGHTING);
	} else {
		glEnable(GL_LIGHTING);
	}

	return oldEnabled;
}

/**
 * @todo Documentation
 */
void OGLGraphics::setLight(Light* light, int idx)
{
	const GLfloat glAmbientColour[4] = {
		mAmbientColour.r / 256.0f,
		mAmbientColour.g / 256.0f,
		mAmbientColour.b / 256.0f,
		mAmbientColour.a / 256.0f * mLightIntensity,
	};

	Vector3f lightPos(light->mPosition);
	lightPos.multMatrix(mCamera->mLookAtMtx);

	const GLfloat glLightPos[4] = {
		lightPos.x,
		lightPos.y,
		lightPos.z,
		1.0f,
	};
	glLightfv(GL_LIGHT0 + idx, GL_POSITION, glLightPos);

	const GLfloat glDiffuseColour[4] = {
		light->mDiffuseColour.r / 256.0f,
		light->mDiffuseColour.g / 256.0f,
		light->mDiffuseColour.b / 256.0f,
		light->mDiffuseColour.a * mLightIntensity / 256.0f,
	};
	glLightfv(GL_LIGHT0 + idx, GL_AMBIENT, glAmbientColour);
	glLightfv(GL_LIGHT0 + idx, GL_DIFFUSE, glDiffuseColour);

	if (GET_LIGHT_TYPE(light->mLightFlag) == LIGHT_Spot) {
		Vector3f lightDir(light->mDirection);
		lightDir.rotate(mCamera->mLookAtMtx);

		const GLfloat glLightDir[4] = {
			lightDir.x,
			lightDir.y,
			lightDir.z,
			1.0f,
		};
		glLightfv(GL_LIGHT0 + idx, GL_SPOT_DIRECTION, glLightDir);
		glLightf(GL_LIGHT0 + idx, GL_SPOT_CUTOFF, light->mSpotAngle);
		glLightf(GL_LIGHT0 + idx, GL_SPOT_EXPONENT, light->mSpotAngle);
	} else {
		const GLfloat glLightDir[4] = {
			0.0f,
			0.0f,
			-1.0f,
			1.0f,
		};
		glLightfv(GL_LIGHT0 + idx, GL_SPOT_DIRECTION, glLightDir);
		glLightf(GL_LIGHT0 + idx, GL_SPOT_CUTOFF, 180.0f);
		glLightf(GL_LIGHT0 + idx, GL_SPOT_EXPONENT, 0.0f);
	}

	glLightf(GL_LIGHT0 + idx, GL_CONSTANT_ATTENUATION, light->mConstantAttn);
	glLightf(GL_LIGHT0 + idx, GL_LINEAR_ATTENUATION, light->mLinearAttn);
	glLightf(GL_LIGHT0 + idx, GL_QUADRATIC_ATTENUATION, light->mQuadAttn);
}

/**
 * @todo Documentation
 */
void OGLGraphics::setPointSize(f32 size)
{
	glPointSize(size);
}

/**
 * @todo Documentation
 */
f32 OGLGraphics::setLineWidth(f32 width)
{
	f32 oldWidth = mLineWidth;

	mLineWidth = width;
	glLineWidth(mLineWidth);

	return oldWidth;
}

/**
 * @todo Documentation
 */
void OGLGraphics::setViewport(immut RectArea& bounds)
{
	mViewportBounds = bounds;
	glViewport(bounds.mMinX, mScreenHeight - (bounds.mMinY + bounds.height()), bounds.width(), bounds.height());
}

/**
 * @todo Documentation
 */
void OGLGraphics::setViewportOffset(immut RectArea& bounds)
{
	glViewport(mViewportBounds.mMinX + bounds.mMinX, mViewportBounds.mMinY + bounds.mMinY, mViewportBounds.width(),
	           mViewportBounds.height());
}

/**
 * @todo Documentation
 */
void OGLGraphics::setScissor(immut RectArea& bounds)
{
	glScissor(bounds.mMinX, mScreenHeight - (bounds.mMinY + bounds.height()), bounds.width(), bounds.height());
}

/**
 * @todo Documentation
 */
void OGLGraphics::setOrthogonal(Mtx44 orthoMtx, immut RectArea& bounds)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(bounds.mMinX, bounds.mMaxX, bounds.mMaxY, bounds.mMinY, -2.0f, 2.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glDisable(GL_ALPHA_TEST);
	glDisable(GL_DEPTH_TEST);
	setLighting(false, nullptr);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	setViewport(bounds);
	setScissor(bounds);
	mLightIntensity = 1.0f;
}

/**
 * @todo Documentation
 */
void OGLGraphics::setPerspective(Mtx44 mtx, f32 fovY, f32 aspect, f32 zNear, f32 zFar, f32 scale)
{
	Mtx44 projectionMtx;

	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovY, aspect, zNear, zFar);
	glScalef(scale, scale, 1.0f);
	glGetFloatv(GL_PROJECTION_MATRIX, reinterpret_cast<GLfloat*>(projectionMtx));

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			mtx[col][row] = projectionMtx[row][col];
		}
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
}

/**
 * @todo Documentation
 */
void OGLGraphics::setClippingPlane(bool enable, Plane* plane)
{
	if (enable) {
		glEnable(GL_CLIP_PLANE0);

		GLdouble glPlaneEquation[4] = {
			plane->mNormal.x,
			plane->mNormal.y,
			plane->mNormal.z,
			plane->mOffset,
		};
		glClipPlane(GL_CLIP_PLANE0, glPlaneEquation);
	} else {
		glDisable(GL_CLIP_PLANE0);
	}
}

/**
 * @todo Documentation
 */
void OGLGraphics::useTexture(Texture* texture, int id)
{
	if (texture) {
		glEnable(GL_TEXTURE_2D);
		if (texture != mActiveTexture[id]) {
			glBindTexture(GL_TEXTURE_2D, texture ? texture->mAttachName : 0);
		}
	} else {
		glDisable(GL_TEXTURE_2D);
	}

	mActiveTexture[id] = texture;
}

/**
 * @todo Documentation
 */
void OGLGraphics::initProjTex(bool enableProj, LightCamera* projCamera)
{
	if (enableProj) {
		const GLfloat identityMtxS[4] = { 1.0f, 0.0f, 0.0f, 0.0f };
		const GLfloat identityMtxT[4] = { 0.0f, 1.0f, 0.0f, 0.0f };
		const GLfloat identityMtxR[4] = { 0.0f, 0.0f, 1.0f, 0.0f };
		const GLfloat identityMtxQ[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
		glTexGenfv(GL_S, GL_OBJECT_PLANE, identityMtxS);
		glTexGenfv(GL_T, GL_OBJECT_PLANE, identityMtxT);
		glTexGenfv(GL_R, GL_OBJECT_PLANE, identityMtxR);
		glTexGenfv(GL_Q, GL_OBJECT_PLANE, identityMtxQ);

		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
		glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glEnable(GL_TEXTURE_GEN_R);
		glEnable(GL_TEXTURE_GEN_Q);

		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		Matrix4f invProjCamLookAtMtx;
		Matrix4f projCamLookAtMtx = projCamera->mLookAtMtx; // You forgot the `&`!
		for (int row1 = 0; row1 < 4; ++row1) {
			for (int col1 = 0; col1 < 4; ++col1) {
				invProjCamLookAtMtx.mMtx[row1][col1] = projCamLookAtMtx.mMtx[col1][row1];
			}
		}

		Matrix4f glProjectionMtx;
		Matrix4f invGfxCamLookAtMtx;
		glGetFloatv(GL_PROJECTION_MATRIX, reinterpret_cast<GLfloat*>(glProjectionMtx.mMtx));
		invProjCamLookAtMtx.multiply(glProjectionMtx);
		glMatrixMode(GL_TEXTURE);

		glLoadIdentity();
		glTranslatef(0.5f, 0.5f, 0.0f);
		glScalef(projCamera->mProjectionScale.x, projCamera->mProjectionScale.y, projCamera->mProjectionScale.z);
		glMultMatrixf(reinterpret_cast<const GLfloat*>(invProjCamLookAtMtx.mMtx));

		Matrix4f& gfxCamLookAtMtx = mCamera->mLookAtMtx;
		for (int row2 = 0; row2 < 4; row2++) {
			for (int col2 = 0; col2 < 4; col2++) {
				invGfxCamLookAtMtx.mMtx[row2][col2] = gfxCamLookAtMtx.mMtx[col2][row2];
			}
		}
		glMultMatrixf(reinterpret_cast<const GLfloat*>(invGfxCamLookAtMtx.mMtx));

		glMatrixMode(GL_MODELVIEW);
	} else {
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
		glDisable(GL_TEXTURE_GEN_R);
		glDisable(GL_TEXTURE_GEN_Q);

		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
	}
}

/**
 * @todo Documentation
 */
void OGLGraphics::initReflectTex(bool enable)
{
	if (enable) {
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, 9218.0f);
		glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, 9218.0f);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD);
	} else {
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
	}
}

/**
 * @todo Documentation
 */
void OGLGraphics::setMaterial(Material* mat, bool param_2)
{
	mCurrentMaterial = mat;
	if (mat) {
		if (mat->mFlags & MATFLAG_Opaque) {
			glDisable(GL_ALPHA_TEST);
			glDisable(GL_BLEND);
			glDepthMask(GL_TRUE);
		} else if (mat->mFlags & MATFLAG_AlphaTest) {
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GEQUAL, 0.5f);
			glDisable(GL_BLEND);
			glDepthMask(GL_TRUE);
		} else if (mat->mFlags & MATFLAG_AlphaBlend) {
			glDisable(GL_ALPHA_TEST);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glDepthMask(GL_FALSE);
		}

		if (mat->mFlags & MATFLAG_PVW) {
			Colour matColour;
			mat->getColour(matColour);

			setColour(matColour, true);
			setLighting((mat->mLightingInfo.mCtrlFlag & LightingControlFlags::EnableColor0) != 0, nullptr);
			if (mat->mTextureInfo.mTextureDataCount != 0) {
				useTexture(mat->mTextureInfo.mTextureData->mTexture, 0);
			} else {
				useTexture(nullptr, 0);
			}
		} else {
			if (s_glMultiTexCoord2fARB) {
				if (mat->mEnvMapTexture) {
					if (!s_isEnvMapTexMatrixSet) {
						s_glActiveTextureARB(GL_TEXTURE1_ARB);
						s_glClientActiveTextureARB(GL_TEXTURE1_ARB);
						mCurrentMaterialHandler->setTexMatrix(true);
						s_glActiveTextureARB(GL_TEXTURE0_ARB);
						s_glClientActiveTextureARB(GL_TEXTURE0_ARB);
					}
					s_glActiveTextureARB(GL_TEXTURE1_ARB);
					s_glClientActiveTextureARB(GL_TEXTURE1_ARB);
					glEnable(GL_TEXTURE_2D);
					useTexture(mat->mEnvMapTexture, 0);
					s_isEnvMapTexMatrixSet = true;
				} else {
					if (s_isEnvMapTexMatrixSet) {
						s_glActiveTextureARB(GL_TEXTURE1_ARB);
						s_glClientActiveTextureARB(GL_TEXTURE1_ARB);
						glDisable(GL_TEXTURE_2D);
						s_isEnvMapTexMatrixSet = false;
					}
				}
				s_glActiveTextureARB(GL_TEXTURE0_ARB);
				s_glClientActiveTextureARB(GL_TEXTURE0_ARB);
			}
			useTexture(mat->mTexture, 0);
			setColour(mat->colour(), true);
		}
	} else {
		glEnable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDepthMask(GL_TRUE);
		if (s_glMultiTexCoord2fARB) {
			s_glActiveTextureARB(GL_TEXTURE1_ARB);
			s_glClientActiveTextureARB(GL_TEXTURE1_ARB);
			glDisable(GL_TEXTURE_2D);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
			mCurrentMaterialHandler->setTexMatrix(0);
			s_glActiveTextureARB(GL_TEXTURE0_ARB);
			s_glClientActiveTextureARB(GL_TEXTURE0_ARB);
		}
	}
}

/**
 * @todo Documentation
 */
void OGLGraphics::initMesh(Shape* model)
{
}

#define UNPACK_U16BE(data) (((data)[0] << 8) | ((data)[1] << 0))

/**
 * @todo Documentation
 */
void OGLGraphics::drawSingleMatpoly(Shape* model, Joint::MatPoly* matPoly)
{
	immut Matrix4f* animMatrices[10];

	Mesh& mesh    = model->mMeshList[matPoly->mMeshIndex];
	Material& mat = model->mMaterialList[matPoly->mIndex];

	if ((mesh.mJointList && !JOINT_IS_VISIBLE(mesh.mJointList[0])) || (mat.mFlags & MATFLAG_Skip)) {
		return;
	}

	if (!(mat.mFlags & mMatRenderMask)) {
		return;
	}

	useMaterial(&mat);

	for (int mtxGroupIdx = 0; mtxGroupIdx < mesh.mMtxGroupCount; ++mtxGroupIdx) {

		MtxGroup& mtxGroup = mesh.mMtxGroupList[mtxGroupIdx];

		if (mtxGroup.mDepLength == 0) {
			animMatrices[0] = &Matrix4f::ident;
		}
		for (int depListIdx = 0; depListIdx < mtxGroup.mDepLength; ++depListIdx) {
			int vtxMtxIdx = mtxGroup.mDepList[depListIdx];
			if (vtxMtxIdx != -1) {

				VtxMatrix& vtxMtx = model->mVtxMatrixList[vtxMtxIdx];

				if (model->mCurrentAnimation->mData) {
					if (vtxMtx.mHasPartialWeights) {
						animMatrices[depListIdx] = &model->getAnimMatrix(vtxMtx.mIndex);
					} else {
						animMatrices[depListIdx] = &model->getAnimMatrix(model->mJointCount + vtxMtx.mIndex);
					}
				} else {
					animMatrices[depListIdx] = &model->mJointList[vtxMtx.mIndex].mAnimMatrix;
				}
			}
		}

		Vector3f* shapeVtxPositions = model->mVertexList;
		Colour* shapeVtxColors      = model->mVtxColorList;
		Vector3f* shapeNormals
		    = (mesh.mFeatureFlags & Mesh::FeatureFlags::VtxNBT) ? reinterpret_cast<Vector3f*>(model->mNBTList) : model->mNormalList;
		int normalStride         = (mesh.mFeatureFlags & Mesh::FeatureFlags::VtxNBT) ? sizeof(NBT) / sizeof(Vector3f) : 1;
		Vector2f* shapeTexCoords = model->mTexCoordList[0];
		DispList* currDispList   = mtxGroup.mDispList;

		for (int dispListCount = 0; dispListCount < mtxGroup.mDispLength; ++dispListCount) {

			gsys->mPolygonCount += currDispList->mFaceCount;
			bool isGlEndListNeeded = false; // This is never changed

			if (mtxGroup.mDepLength == 0) {
				if (currDispList->mOglListHandle == -1) {
					// Do nothing
				} else {
					glCallList(currDispList->mOglListHandle);
					continue;
				}
			}

			int oldCullFront = setCullFront((currDispList->mFlags & 3) ^ mCullFlip); // Never restored

			u8* data       = currDispList->mData;
			int dataLength = currDispList->mDataLength;

			while (dataLength != 0 && data < currDispList->mData + dataLength) {

				int opcode = data[0];
				data += 1;
				if (opcode == 0) {
					dataLength = 0;
					break;
				}
				int dispListTriCount = UNPACK_U16BE(data);
				data += 2;

				// Only the first element of these buffers is ever used.
				Vector3f* glVertex   = s_glVertexPosNrmBuffer[0];
				Vector3f* glNormal   = s_glVertexPosNrmBuffer[1];
				Vector2f* glTexCoord = s_glTexCoordBuffer;

				if (opcode == GX_TRIANGLESTRIP) {
					glBegin(GL_TRIANGLE_STRIP);
				} else if (opcode == GX_TRIANGLES) {
					glBegin(GL_TRIANGLES);
				} else {
					glBegin(GL_TRIANGLE_FAN);
				}

				if (mtxGroup.mDepLength == 0) {

					for (int triCount = 0; triCount < dispListTriCount; ++triCount) {

						u8 animMtxIdx = 0; // Unused in this code path
						if (mesh.mFeatureFlags & Mesh::FeatureFlags::PosAndNrm) {
							animMtxIdx = data[0] / 3;
							data += 1;
						}
						if (mesh.mFeatureFlags & Mesh::FeatureFlags::Tex1MtxIdx) {
							data += 1;
						}

						int texCoordDataSize = 0;
						Vector3f& vtx        = shapeVtxPositions[UNPACK_U16BE(data)];

						glNormal3fv(reinterpret_cast<const GLfloat*>(&shapeNormals[UNPACK_U16BE(data + 2) * normalStride]));
						data += 4;

						if (mesh.mFeatureFlags & Mesh::FeatureFlags::VtxColor) {
							int vtxColorIdx  = UNPACK_U16BE(data);
							Colour& vtxColor = shapeVtxColors[vtxColorIdx];
							glColor4f(vtxColor.r / 255.0f, vtxColor.g / 255.0f, vtxColor.b / 255.0f, vtxColor.a / 255.0f);
							data += 2;
						}

						for (int texMapIdx = 0; texMapIdx < 8; ++texMapIdx) {
							// Effectively `Mesh::FeatureFlags::Tex0 << texMapIdx`
							if (mesh.mFeatureFlags & (1 << (texMapIdx + 3))) {
								texCoordDataSize += 2;
								// `OGLGraphics` only supports `GX_TEXMAP0`
								if (texMapIdx == 0) {
									glTexCoord2fv(reinterpret_cast<const GLfloat*>(&shapeTexCoords[UNPACK_U16BE(data)]));
								}
							}
						}

						glVertex3fv(reinterpret_cast<const GLfloat*>(&vtx));
						data += texCoordDataSize;
					}
				} else {

					for (int triCount = 0; triCount < dispListTriCount; ++triCount) {

						u8 animMtxIdx = 0;
						if (mesh.mFeatureFlags & Mesh::FeatureFlags::PosAndNrm) {
							animMtxIdx = data[0] / 3;
							data += 1;
						}
						if (mesh.mFeatureFlags & Mesh::FeatureFlags::Tex1MtxIdx) {
							data += 1;
						}

						int texCoordDataSize    = 0;
						immut Matrix4f& animMtx = *animMatrices[animMtxIdx];
						Vector3f& vtx           = shapeVtxPositions[UNPACK_U16BE(data)];
						Vector3f& vtxNrm        = shapeNormals[UNPACK_U16BE(data + 2) * normalStride];

						// clang-format off
						glVertex[0].x = animMtx.mMtx[0][0] * vtx.x + animMtx.mMtx[0][1] * vtx.y + animMtx.mMtx[0][2] * vtx.z + animMtx.mMtx[0][3];
						glVertex[0].y = animMtx.mMtx[1][0] * vtx.x + animMtx.mMtx[1][1] * vtx.y + animMtx.mMtx[1][2] * vtx.z + animMtx.mMtx[1][3];
						glVertex[0].z = animMtx.mMtx[2][0] * vtx.x + animMtx.mMtx[2][1] * vtx.y + animMtx.mMtx[2][2] * vtx.z + animMtx.mMtx[2][3];
						// clang-format on

						glNormal[0].x = animMtx.mMtx[0][0] * vtxNrm.x + animMtx.mMtx[0][1] * vtxNrm.y + animMtx.mMtx[0][2] * vtxNrm.z;
						glNormal[0].y = animMtx.mMtx[1][0] * vtxNrm.x + animMtx.mMtx[1][1] * vtxNrm.y + animMtx.mMtx[1][2] * vtxNrm.z;
						glNormal[0].z = animMtx.mMtx[2][0] * vtxNrm.x + animMtx.mMtx[2][1] * vtxNrm.y + animMtx.mMtx[2][2] * vtxNrm.z;

						data += 4;
						if (mesh.mFeatureFlags & Mesh::FeatureFlags::VtxColor) {
							data += 2;
						}

						for (int texMapIdx = 0; texMapIdx < 8; ++texMapIdx) {
							// Effectively `Mesh::FeatureFlags::Tex0 << texMapIdx`
							if (mesh.mFeatureFlags & (1 << (texMapIdx + 3))) {
								texCoordDataSize += 2;
								// `OGLGraphics` only supports `GX_TEXMAP0`
								if (texMapIdx == 0) {
									glTexCoord[0] = shapeTexCoords[UNPACK_U16BE(data)];
								}
							}
						}

						glTexCoord2fv(reinterpret_cast<const GLfloat*>(glTexCoord));
						glNormal3fv(reinterpret_cast<const GLfloat*>(glNormal));
						glVertex3fv(reinterpret_cast<const GLfloat*>(glVertex));

						data += texCoordDataSize;
					}
				}

				glEnd();
			}

			// Guessing they wanted to compile full GL display lists rather than sending one tri at a time.
			if (isGlEndListNeeded) {
				glEndList();
			}
			currDispList += 1;
		}
	}
}

#undef UNPACK_U16BE

/**
 * @todo Documentation
 */
void OGLGraphics::drawMeshes(Camera&, Shape* shape)
{
	for (int i = shape->mTotalMatpolyCount - 1; i >= 0; i--) {
		drawSingleMatpoly(shape, shape->mMatpolyList[i]);
	}
	useMaterial(nullptr);
}

/**
 * @todo Documentation
 */
void OGLGraphics::setColour(immut Colour& color, bool auxToo)
{
	const GLfloat glColor[4] = {
		color.r / 255.0f,
		color.g / 255.0f,
		color.b / 255.0f,
		color.a / 255.0f * mLightIntensity,
	};

	mPrimaryColour = color;
	if (auxToo) {
		mAuxiliaryColour = color;
	}

	glColor4fv(reinterpret_cast<const GLfloat*>(glColor));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, reinterpret_cast<const GLfloat*>(glColor));
	glMaterialfv(GL_FRONT, GL_AMBIENT, reinterpret_cast<const GLfloat*>(glColor));
}

/**
 * @todo Documentation
 */
void OGLGraphics::setAuxColour(immut Colour& color)
{
	mAuxiliaryColour = color;
}

/**
 * @todo Documentation
 */
void OGLGraphics::setClearColour(immut Colour& color)
{
	mBufferClearColour = color;
}

/**
 * @todo Documentation
 * @param bufferFlags Options to clear depth color and/or color buffer.  See `Graphics::ClearBufferFlag`.
 * @param mode Option to change how OpenGL clears the depth (todo: elaborate on that)
 */
void OGLGraphics::clearBuffer(int bufferFlags, bool mode)
{
	if (mode) {
		glClearDepth(0.0); // NB: this functions accept a `double`
		glDepthFunc(GL_ALWAYS);
	} else {
		glClearDepth(1.0); // NB: this functions accept a `double`
		glDepthFunc(GL_LEQUAL);
	}
	if (bufferFlags != 0) {
		glClearColor(mBufferClearColour.r / 255.0f, mBufferClearColour.g / 255.0f, mBufferClearColour.b / 255.0f,
		             mBufferClearColour.a / 255.0f);
		glClear(((bufferFlags & Graphics::ClearBufferFlag::Depth) ? GL_DEPTH_BUFFER_BIT : 0)
		        | ((bufferFlags & Graphics::ClearBufferFlag::Color) ? GL_COLOR_BUFFER_BIT : 0));
	}
}

/**
 * @todo Documentation
 */
void OGLGraphics::setFog(bool enable)
{
	if (enable) {
		const GLfloat glColor[4] = {
			mFogColour.r / 255.0f,
			mFogColour.g / 255.0f,
			mFogColour.b / 255.0f,
			mFogColour.a / 255.0f,
		};
		glEnable(GL_FOG);
		glFogi(GL_FOG_MODE, GL_LINEAR);
		glFogfv(GL_FOG_COLOR, glColor);
		glFogf(GL_FOG_DENSITY, mFogDensity);
		glFogf(GL_FOG_START, mFogStart);
		glFogf(GL_FOG_END, mFogEnd);
	} else {
		glDisable(GL_FOG);
	}
}

/**
 * @todo Documentation
 */
void OGLGraphics::setFog(bool enable, immut Colour& color, f32 density, f32 start, f32 end)
{
	mFogColour  = color;
	mFogStart   = start;
	mFogEnd     = end;
	mFogDensity = density;
	setFog(enable);
}

/**
 * @todo Documentation
 */
void OGLGraphics::drawRectangle(immut RectArea& bounds, immut RectArea& texCoords, immut Vector3f* offset)
{
	glBegin(GL_QUADS);

	// Northwest
	glColor4f(mPrimaryColour.r / 255.0f, mPrimaryColour.g / 255.0f, mPrimaryColour.b / 255.0f, mPrimaryColour.a / 255.0f);
	glTexCoord2f(texCoords.mMinX * mActiveTexture[0]->mWidthFactor, texCoords.mMinY * mActiveTexture[0]->mHeightFactor);
	glVertex3f((offset ? offset->x : 0.0f) + bounds.mMinX, (offset ? offset->y : 0.0f) + bounds.mMinY, (offset ? offset->z : 0.0f));
	// Northeast
	glColor4f(mPrimaryColour.r / 255.0f, mPrimaryColour.g / 255.0f, mPrimaryColour.b / 255.0f, mPrimaryColour.a / 255.0f);
	glTexCoord2f(texCoords.mMaxX * mActiveTexture[0]->mWidthFactor, texCoords.mMinY * mActiveTexture[0]->mHeightFactor);
	glVertex3f((offset ? offset->x : 0.0f) + bounds.mMaxX, (offset ? offset->y : 0.0f) + bounds.mMinY, (offset ? offset->z : 0.0f));
	// Southeast
	glColor4f(mAuxiliaryColour.r / 255.0f, mAuxiliaryColour.g / 255.0f, mAuxiliaryColour.b / 255.0f, mAuxiliaryColour.a / 255.0f);
	glTexCoord2f(texCoords.mMaxX * mActiveTexture[0]->mWidthFactor, texCoords.mMaxY * mActiveTexture[0]->mHeightFactor);
	glVertex3f((offset ? offset->x : 0.0f) + bounds.mMaxX, (offset ? offset->y : 0.0f) + bounds.mMaxY, (offset ? offset->z : 0.0f));
	// Southwest
	glColor4f(mAuxiliaryColour.r / 255.0f, mAuxiliaryColour.g / 255.0f, mAuxiliaryColour.b / 255.0f, mAuxiliaryColour.a / 255.0f);
	glTexCoord2f(texCoords.mMinX * mActiveTexture[0]->mWidthFactor, texCoords.mMaxY * mActiveTexture[0]->mHeightFactor);
	glVertex3f((offset ? offset->x : 0.0f) + bounds.mMinX, (offset ? offset->y : 0.0f) + bounds.mMaxY, (offset ? offset->z : 0.0f));

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::fillRectangle(immut RectArea& bounds)
{
	glBegin(GL_QUADS);

	glColor4f(mPrimaryColour.r / 255.0f, mPrimaryColour.g / 255.0f, mPrimaryColour.b / 255.0f, mPrimaryColour.a / 255.0f);
	glVertex3f(bounds.mMinX, bounds.mMinY, 0.0f);
	glVertex3f(bounds.mMaxX, bounds.mMinY, 0.0f);

	glColor4f(mAuxiliaryColour.r / 255.0f, mAuxiliaryColour.g / 255.0f, mAuxiliaryColour.b / 255.0f, mAuxiliaryColour.a / 255.0f);
	glVertex3f(bounds.mMaxX, bounds.mMaxY, 0.0f);
	glVertex3f(bounds.mMinX, bounds.mMaxY, 0.0f);

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::lineRectangle(immut RectArea& bounds)
{
	glBegin(GL_LINE_LOOP);

	// Shouldn't there be a `glColor4f` call here for the primary colour?  Might be a bug.  Wish I could test it.
#if defined(BUGFIX)
	/* Pending ability to test bugfix */
#endif
	glVertex3f(bounds.mMinX, bounds.mMinY, 0.0f);
	glVertex3f(bounds.mMaxX, bounds.mMinY, 0.0f);

	glColor4f(mAuxiliaryColour.r / 255.0f, mAuxiliaryColour.g / 255.0f, mAuxiliaryColour.b / 255.0f, mAuxiliaryColour.a / 255.0f);
	glVertex3f(bounds.mMaxX, bounds.mMaxY, 0.0f);
	glVertex3f(bounds.mMinX, bounds.mMaxY, 0.0f);

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::drawRotParticle(Camera& cam, immut Vector3f& pos, u16 shortAngle, f32 radius)
{
	f32 angle = shortAngle / f32(USHRT_MAX) * TAU;
	Vector3f nwVtx(radius * sinf(angle - PI * 1 / 4), radius * cosf(angle - PI * 1 / 4), 0.0f);
	Vector3f neVtx(radius * sinf(angle + PI * 1 / 4), radius * cosf(angle + PI * 1 / 4), 0.0f);
	Vector3f seVtx(radius * sinf(angle + PI * 3 / 4), radius * cosf(angle + PI * 3 / 4), 0.0f);
	Vector3f swVtx(radius * sinf(angle + PI * 5 / 4), radius * cosf(angle + PI * 5 / 4), 0.0f);

	glBegin(GL_QUADS);

	// Northwest
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(nwVtx.DP(cam.mViewXAxis) + pos.x, nwVtx.DP(cam.mViewYAxis) + pos.y, nwVtx.DP(cam.mViewZAxis) + pos.z);
	// Northeast
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(neVtx.DP(cam.mViewXAxis) + pos.x, neVtx.DP(cam.mViewYAxis) + pos.y, neVtx.DP(cam.mViewZAxis) + pos.z);
	// Southeast
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(seVtx.DP(cam.mViewXAxis) + pos.x, seVtx.DP(cam.mViewYAxis) + pos.y, seVtx.DP(cam.mViewZAxis) + pos.z);
	// Southwest
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(swVtx.DP(cam.mViewXAxis) + pos.x, swVtx.DP(cam.mViewYAxis) + pos.y, swVtx.DP(cam.mViewZAxis) + pos.z);

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::drawParticle(Camera& cam, immut Vector3f& pos, f32 radius)
{
	Vector3f nwVtx(-radius, radius, 0.0f);
	Vector3f neVtx(radius, radius, 0.0f);
	Vector3f seVtx(radius, -radius, 0.0f);
	Vector3f swVtx(-radius, -radius, 0.0f);

	glBegin(GL_QUADS);

	// Northwest
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(nwVtx.DP(cam.mViewXAxis) + pos.x, nwVtx.DP(cam.mViewYAxis) + pos.y, nwVtx.DP(cam.mViewZAxis) + pos.z);
	// Northeast
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(neVtx.DP(cam.mViewXAxis) + pos.x, neVtx.DP(cam.mViewYAxis) + pos.y, neVtx.DP(cam.mViewZAxis) + pos.z);
	// Southeast
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(seVtx.DP(cam.mViewXAxis) + pos.x, seVtx.DP(cam.mViewYAxis) + pos.y, seVtx.DP(cam.mViewZAxis) + pos.z);
	// Southwest
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(swVtx.DP(cam.mViewXAxis) + pos.x, swVtx.DP(cam.mViewYAxis) + pos.y, swVtx.DP(cam.mViewZAxis) + pos.z);

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::drawCamParticle(Camera& cam, immut Vector3f& pos, immut Vector2f& extents, immut Vector2f& uvMin, immut Vector2f& uvMax)
{
	Vector3f nwVtx(-extents.x + pos.x, extents.y + pos.y, pos.z);
	Vector3f neVtx(extents.x + pos.x, extents.y + pos.y, pos.z);
	Vector3f seVtx(extents.x + pos.x, -extents.y + pos.y, pos.z);
	Vector3f swVtx(-extents.x + pos.x, -extents.y + pos.y, pos.z);

	glBegin(GL_QUADS);

	// Northwest
	glTexCoord2f(uvMin.x, uvMin.y);
	glVertex3fv(reinterpret_cast<const GLfloat*>(&nwVtx));
	// Northeast
	glTexCoord2f(uvMax.x, uvMin.y);
	glVertex3fv(reinterpret_cast<const GLfloat*>(&neVtx));
	// Southeast
	glTexCoord2f(uvMax.x, uvMax.y);
	glVertex3fv(reinterpret_cast<const GLfloat*>(&seVtx));
	// Southwest
	glTexCoord2f(uvMin.x, uvMax.y);
	glVertex3fv(reinterpret_cast<const GLfloat*>(&swVtx));

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::drawPoints(immut Vector3f* points, int count)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, reinterpret_cast<const GLvoid*>(points));
	glDrawArrays(GL_POINTS, 0, count);
	glDisableClientState(GL_VERTEX_ARRAY);
}

/**
 * @todo Documentation
 */
void OGLGraphics::drawOneTri(immut Vector3f* vertices, immut Vector3f* normals, immut Vector2f* texCoords, int count)
{
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < count; i++) {
		if (texCoords) {
			glTexCoord2fv(reinterpret_cast<const GLfloat*>(texCoords++));
		}
		if (normals) {
			glNormal3fv(reinterpret_cast<const GLfloat*>(normals++));
		}
		glVertex3fv(reinterpret_cast<const GLfloat*>(vertices++));
	}

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::drawOneStrip(immut Vector3f* vertices, immut Vector3f* normals, immut Vector2f* texCoords, int count)
{
	glBegin(GL_TRIANGLE_STRIP);

	for (int i = 0; i < count; i++) {
		if (texCoords) {
			glTexCoord2fv(reinterpret_cast<const GLfloat*>(texCoords++));
		}
		if (normals) {
			glNormal3fv(reinterpret_cast<const GLfloat*>(normals++));
		}
		glVertex3fv(reinterpret_cast<const GLfloat*>(vertices++));
	}

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::drawLine(immut Vector3f& start, immut Vector3f& end)
{
	glBegin(GL_LINES);

	glVertex3f(start.x, start.y, start.z);
	glVertex3f(end.x, end.y, end.z);

	glEnd();
}

/**
 * @todo Documentation
 */
void OGLGraphics::texturePrintf(Font* font, int x, int y, immut char* format, ...)
{
	char buffer[PATH_MAX];
	va_list args;

	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	useTexture(font->mTexture, 0);
	int xPos           = x;
	int yPos           = y;
	const char* bufPtr = buffer;

	while (*bufPtr != '\0') {
		int idx;
		// Going to assume this version difference also exists in the PAL DLL.  We'll see someday!
#if 0
		// Avoid impossible condition by converting to `u8`.
		u8 extendedAsciiCodepoint = bufPtr[0];
		if (extendedAsciiCodepoint >= 0xa0) {
			idx = font->charToIndex(bufPtr[0]);
			bufPtr += 1;
		} else
#endif
		if (bufPtr[0] & 0x80) {
			u16 sjis = (static_cast<u8>(bufPtr[0]) << 8) | (static_cast<u8>(bufPtr[1]) << 0);
			idx      = font->charToIndex(sjis);
			bufPtr += 2;
		} else {
			idx = font->charToIndex(bufPtr[0]);
			bufPtr += 1;
		}

		RectArea quadVerts(xPos - font->mChars[idx].mLeftOffset, yPos, xPos - font->mChars[idx].mLeftOffset + font->mChars[idx].mWidth,
		                   yPos + font->mChars[idx].mHeight);
		RectArea& texCoords = font->mChars[idx].mTextureCoords;

		glBegin(GL_QUADS);

		// Northeast
		glColor4f(mPrimaryColour.r / 255.0f, mPrimaryColour.g / 255.0f, mPrimaryColour.b / 255.0f, mPrimaryColour.a / 255.0f);
		glTexCoord2f(texCoords.mMinX * mActiveTexture[0]->mWidthFactor, texCoords.mMinY * mActiveTexture[0]->mHeightFactor);
		glVertex3f(quadVerts.mMinX, quadVerts.mMinY, 0.0f);
		// Northwest
		glColor4f(mPrimaryColour.r / 255.0f, mPrimaryColour.g / 255.0f, mPrimaryColour.b / 255.0f, mPrimaryColour.a / 255.0f);
		glTexCoord2f(texCoords.mMaxX * mActiveTexture[0]->mWidthFactor, texCoords.mMinY * mActiveTexture[0]->mHeightFactor);
		glVertex3f(quadVerts.mMaxX, quadVerts.mMinY, 0.0f);
		// Southwest
		glColor4f(mAuxiliaryColour.r / 255.0f, mAuxiliaryColour.g / 255.0f, mAuxiliaryColour.b / 255.0f, mAuxiliaryColour.a / 255.0f);
		glTexCoord2f(texCoords.mMaxX * mActiveTexture[0]->mWidthFactor, texCoords.mMaxY * mActiveTexture[0]->mHeightFactor);
		glVertex3f(quadVerts.mMaxX, quadVerts.mMaxY, 0.0f);
		// Southeast
		glColor4f(mAuxiliaryColour.r / 255.0f, mAuxiliaryColour.g / 255.0f, mAuxiliaryColour.b / 255.0f, mAuxiliaryColour.a / 255.0f);
		glTexCoord2f(texCoords.mMinX * mActiveTexture[0]->mWidthFactor, texCoords.mMaxY * mActiveTexture[0]->mHeightFactor);
		glVertex3f(quadVerts.mMinX, quadVerts.mMaxY, 0.0f);

		glEnd();

		xPos += (short)font->mChars[idx].mCharSpacing;
	}
}

#if defined(WIN32)

/**
 * @todo Documentation
 */
void OGLGraphics::genAge(AgeServer& server)
{
	server.StartSection("GLRenderer", true);
	server.StartGroup("Lighting");
	mAmbientColour.genAge(server, "ambient");
	server.EndGroup();
	server.EndSection();
}

#endif

/**
 * @todo Documentation
 */
void OGLGraphics::resetCopyFilter()
{
}

/**
 * @todo Documentation
 */
bool OGLGraphics::initParticle(bool hasVtxColor)
{
	return true;
}

/**
 * @todo Documentation
 */
void OGLGraphics::setPrimEnv(immut Colour* primColor, immut Colour* envColor)
{
	setColour(*primColor, true);
}

/**
 * @todo Documentation
 */
void OGLGraphics::blatRectangle(immut RectArea& rect)
{
}
