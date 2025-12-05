#include "Camera.h"
#include "DebugLog.h"
#include "Geometry.h"
#include "Graphics.h"
#include "Texture.h"
#include "sysNew.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
void CullFrustum::vectorToWorldPlane(Vector3f& vec, CullingPlane& worldPlane)
{
	projectVector(vec, worldPlane.mPlane.mNormal);
	worldPlane.mPlane.mOffset = worldPlane.mPlane.mNormal.dot(mPosition);
}

/*
 * --INFO--
 * Address:	80041584
 * Size:	00006C
 */
bool CullFrustum::isPointVisible(Vector3f& point, f32 cutoff)
{
	for (int i = 0; i < mActivePlaneCount; i++) {
		Plane* plane = &mPlanePointers[i]->mPlane;
		if (point.x * plane->mNormal.x + point.y * plane->mNormal.y + point.z * plane->mNormal.z - plane->mOffset < -cutoff) {
			return false;
		}
	}

	return true;
}

/*
 * --INFO--
 * Address:	800415F0
 * Size:	000FBC
 */
void CullFrustum::draw(Graphics& gfx)
{
	gfx.mHasTexGen        = FALSE;
	bool prevLightSetting = gfx.setLighting(false, nullptr);
	gfx.useMatrix(gfx.mCamera->mLookAtMtx, 0);
	gfx.useTexture(nullptr, GX_TEXMAP0);
	gfx.setColour(Colour(255, 255, 255, 255), true);
	gfx.setAuxColour(Colour(255, 255, 255, 255));
	gfx.drawLine(mPosition, mFocus);

	f32 targetDist = mPosition.distance(mFocus);
	f32 tanTheta   = sinf(mFov / 2.0f * PI / 180.0f) * targetDist / cosf(mFov / 2.0f * PI / 180.0f);

	f32 divTanTheta = tanTheta / mAspectRatio;
	f32 roundedTan  = divTanTheta * mAspectRatio;
	f32 tanTheta2   = tanTheta;

	Vector3f vec1(-roundedTan, tanTheta2, 0.0f);
	Vector3f vec2(roundedTan, tanTheta2, 0.0f);
	Vector3f vec3(roundedTan, -tanTheta2, 0.0f);
	Vector3f vec4(-roundedTan, -tanTheta2, 0.0f);

	Vector3f targ1(vec1.DP(mViewXAxis) + mFocus.x, vec1.DP(mViewYAxis) + mFocus.y, vec1.DP(mViewZAxis) + mFocus.z);
	Vector3f targ2(vec2.DP(mViewXAxis) + mFocus.x, vec2.DP(mViewYAxis) + mFocus.y, vec2.DP(mViewZAxis) + mFocus.z);
	Vector3f targ3(vec3.DP(mViewXAxis) + mFocus.x, vec3.DP(mViewYAxis) + mFocus.y, vec3.DP(mViewZAxis) + mFocus.z);
	Vector3f targ4(vec4.DP(mViewXAxis) + mFocus.x, vec4.DP(mViewYAxis) + mFocus.y, vec4.DP(mViewZAxis) + mFocus.z);

	Vector3f dir(mFocus - mPosition);
	dir.normalise();
	dir.multiply(mNear);
	dir.add(mPosition);

	f32 invDist = mNear / mFocus.distance(mPosition);
	f32 divDist = divTanTheta * invDist;
	f32 tanDist = tanTheta * invDist;

	Vector3f vec5(-divDist, tanDist, 0.0f);
	Vector3f vec6(divDist, tanDist, 0.0f);
	Vector3f vec7(divDist, -tanDist, 0.0f);
	Vector3f vec8(-divDist, -tanDist, 0.0f);

	Vector3f dir1(vec5.DP(mViewXAxis) + dir.x, vec5.DP(mViewYAxis) + dir.y, vec5.DP(mViewZAxis) + dir.z);
	Vector3f dir2(vec6.DP(mViewXAxis) + dir.x, vec6.DP(mViewYAxis) + dir.y, vec6.DP(mViewZAxis) + dir.z);
	Vector3f dir3(vec7.DP(mViewXAxis) + dir.x, vec7.DP(mViewYAxis) + dir.y, vec7.DP(mViewZAxis) + dir.z);
	Vector3f dir4(vec8.DP(mViewXAxis) + dir.x, vec8.DP(mViewYAxis) + dir.y, vec8.DP(mViewZAxis) + dir.z);

	Vector3f odir = mFocus - mPosition;
	odir.normalise();
	odir.multiply(mFar);
	odir.add(mPosition);

	invDist    = mFar / mFocus.distance(mPosition);
	roundedTan = roundedTan * invDist;
	tanTheta2  = tanTheta2 * invDist;

	Vector3f vec9(-roundedTan, tanTheta2, 0.0f);
	Vector3f vec10(roundedTan, tanTheta2, 0.0f);
	Vector3f vec11(roundedTan, -tanTheta2, 0.0f);
	Vector3f vec12(-roundedTan, -tanTheta2, 0.0f);

	Vector3f odir1(vec9.DP(mViewXAxis) + odir.x, vec9.DP(mViewYAxis) + odir.y, vec9.DP(mViewZAxis) + odir.z);
	Vector3f odir2(vec10.DP(mViewXAxis) + odir.x, vec10.DP(mViewYAxis) + odir.y, vec10.DP(mViewZAxis) + odir.z);
	Vector3f odir3(vec11.DP(mViewXAxis) + odir.x, vec11.DP(mViewYAxis) + odir.y, vec11.DP(mViewZAxis) + odir.z);
	Vector3f odir4(vec12.DP(mViewXAxis) + odir.x, vec12.DP(mViewYAxis) + odir.y, vec12.DP(mViewZAxis) + odir.z);

	gfx.setColour(Colour(32, 255, 32, 128), true);
	gfx.drawLine(dir1, dir2);
	gfx.drawLine(dir2, dir3);
	gfx.drawLine(dir3, dir4);
	gfx.drawLine(dir4, dir1);

	gfx.drawLine(dir1, targ1);
	gfx.drawLine(dir2, targ2);
	gfx.drawLine(dir3, targ3);
	gfx.drawLine(dir4, targ4);

	gfx.drawLine(targ1, targ2);
	gfx.drawLine(targ2, targ3);
	gfx.drawLine(targ3, targ4);
	gfx.drawLine(targ4, targ1);

	gfx.setColour(Colour(255, 32, 32, 128), true);
	gfx.drawLine(odir1, odir2);
	gfx.drawLine(odir2, odir3);
	gfx.drawLine(odir3, odir4);
	gfx.drawLine(odir4, odir1);

	gfx.drawLine(odir1, targ1);
	gfx.drawLine(odir2, targ2);
	gfx.drawLine(odir3, targ3);
	gfx.drawLine(odir4, targ4);

	gfx.setColour(Colour(255, 0, 0, 16), true);
	Vector3f vec3Block1[4];
	Vector2f vec2Block1[4];
	vec2Block1[0].set(0.0f, 0.0f);
	vec2Block1[1].set(0.0f, 0.0f);
	vec2Block1[2].set(0.0f, 0.0f);
	vec2Block1[3].set(0.0f, 0.0f);

	vec3Block1[0] = dir2;
	vec3Block1[1] = dir1;
	vec3Block1[2] = odir1;
	vec3Block1[3] = odir2;
	gfx.drawOneTri(vec3Block1, nullptr, vec2Block1, 4);

	gfx.setColour(Colour(255, 0, 32, 16), true);
	vec3Block1[0] = dir3;
	vec3Block1[1] = dir2;
	vec3Block1[2] = odir2;
	vec3Block1[3] = odir3;
	gfx.drawOneTri(vec3Block1, nullptr, vec2Block1, 4);

	gfx.setColour(Colour(255, 0, 0, 16), true);
	vec3Block1[0] = dir4;
	vec3Block1[1] = dir3;
	vec3Block1[2] = odir3;
	vec3Block1[3] = odir4;
	gfx.drawOneTri(vec3Block1, nullptr, vec2Block1, 4);

	gfx.setColour(Colour(255, 0, 32, 16), true);
	vec3Block1[0] = dir1;
	vec3Block1[1] = dir4;
	vec3Block1[2] = odir4;
	vec3Block1[3] = odir1;
	gfx.drawOneTri(vec3Block1, nullptr, vec2Block1, 4);

	gfx.setLighting(prevLightSetting, nullptr);
}

/*
 * --INFO--
 * Address:	800425AC
 * Size:	00046C
 */
void CullFrustum::updateViewPlanes(f32 leftScale, f32 rightScale, f32 bottomScale, f32 topScale)
{
	CullingPlane* planes = &mCullPlanes[mViewPlaneIdx];
	Vector3f vec;
	vec.x = mWidth / absF(leftScale);
	vec.y = 0.0f;
	vec.z = mDepth;
	vec.normalise();
	vectorToWorldPlane(vec, planes[0]);
	planes[0].CheckMinMaxDir();
	planes[0].mIsEnabled = true;

	vec.x = -mWidth / absF(rightScale);
	vec.y = 0.0f;
	vec.z = mDepth;
	vec.normalise();
	vectorToWorldPlane(vec, planes[1]);
	planes[1].CheckMinMaxDir();
	planes[1].mIsEnabled = true;

	vec.x = 0.0f;
	vec.y = absF(bottomScale) * -mWidth;
	vec.z = mDepth;
	vec.normalise();
	vectorToWorldPlane(vec, planes[2]);
	planes[2].CheckMinMaxDir();
	planes[2].mIsEnabled = true;

	vec.x = 0.0f;
	vec.y = absF(topScale) * mWidth;
	vec.z = mDepth;
	vec.normalise();
	vectorToWorldPlane(vec, planes[3]);
	planes[3].CheckMinMaxDir();
	planes[3].mIsEnabled = true;

	mTotalPlaneCount = &planes[4] - mCullPlanes;
}

/*
 * --INFO--
 * Address:	80042A18
 * Size:	00023C
 */
void CullFrustum::createViewPlanes()
{
	CullingPlane* planes = mCullPlanes;
	Vector3f vec;
	mTotalPlaneCount = 0;
	mDepth           = sinf(PI * (0.5f * mFov) / 180.0f);
	mWidth           = cosf(PI * (0.5f * mFov) / 180.0f);
	vectorToWorldPlane(Vector3f(0.0f, 0.0f, 1.0f), planes[0]);
	planes[0].mPlane.mOffset += mNear;
	planes[0].CheckMinMaxDir();
	planes[0].mIsEnabled = true;

	vectorToWorldPlane(Vector3f(0.0f, 0.0f, -1.0f), planes[1]);
	planes[1].mPlane.mOffset -= 2600.0f;
	planes[1].CheckMinMaxDir();
	planes[1].mIsEnabled = true;

	mViewPlaneIdx = &planes[2] - mCullPlanes;

	FORCE_DONT_INLINE;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000BC
 */
void CullFrustum::additionalPlanes(CullFrustum*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void CullFrustum::createVecs()
{
	// col1 = x axis after transforming
	mViewXAxis.x = mLookAtMtx.mMtx[0][0];
	mViewXAxis.y = mLookAtMtx.mMtx[1][0];
	mViewXAxis.z = -mLookAtMtx.mMtx[2][0];

	// col2 = y axis after transforming
	mViewYAxis.x = mLookAtMtx.mMtx[0][1];
	mViewYAxis.y = mLookAtMtx.mMtx[1][1];
	mViewYAxis.z = -mLookAtMtx.mMtx[2][1];

	// col3 = z axis after transforming
	mViewZAxis.x = mLookAtMtx.mMtx[0][2];
	mViewZAxis.y = mLookAtMtx.mMtx[1][2];
	mViewZAxis.z = -mLookAtMtx.mMtx[2][2];
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void CullFrustum::createInvVecs()
{
	mInvXAxis.x = mLookAtMtx.mMtx[0][0];
	mInvXAxis.y = mLookAtMtx.mMtx[0][1];
	mInvXAxis.z = mLookAtMtx.mMtx[0][2];

	mInvYAxis.x = mLookAtMtx.mMtx[1][0];
	mInvYAxis.y = mLookAtMtx.mMtx[1][1];
	mInvYAxis.z = mLookAtMtx.mMtx[1][2];

	mInvZAxis.x = -mLookAtMtx.mMtx[2][0];
	mInvZAxis.y = -mLookAtMtx.mMtx[2][1];
	mInvZAxis.z = -mLookAtMtx.mMtx[2][2];
}

/*
 * --INFO--
 * Address:	80042C54
 * Size:	000150
 */
void CullFrustum::update(f32 aspectRatio, f32 fov, f32 near, f32 far)
{
	mAspectRatio   = aspectRatio;
	mVerticalScale = 1.0f;
	mFov           = fov;
	mNear          = near;
	mFar           = far;

	createVecs();
	createInvVecs();
	createViewPlanes();
	updateViewPlanes(mAspectRatio, -mAspectRatio, -mVerticalScale, mVerticalScale);

	for (int i = 0; i < mTotalPlaneCount; i++) {
		mPlanePointers[i] = &mCullPlanes[i];
	}

	mActivePlaneCount = mTotalPlaneCount;
	mBoundOffset.set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	80042DA4
 * Size:	000268
 */
void CullFrustum::calcVectors(Vector3f& eyePos, Vector3f& targetPos)
{
	mPosition = eyePos;
	mFocus    = targetPos;

	// make sure eye pos and target pos aren't exactly the same, since we need a direction to point the camera
	if (mPosition.x == mFocus.x && mPosition.z == mFocus.z) {
		mFocus.z += 0.0001f;
	}

	// construct target view direction
	mViewZAxis.x = mPosition.x - mFocus.x;
	mViewZAxis.y = mPosition.y - mFocus.y;
	mViewZAxis.z = mPosition.z - mFocus.z;
	mViewZAxis.normalise();

	// construct perpendicular direction manually
	mViewXAxis.set(mViewZAxis.z, 0.0f, -mViewZAxis.x);
	mViewXAxis.normalise();

	// calculate vertical direction by crossing z and x
	mViewYAxis = mViewZAxis;
	mViewYAxis.CP(mViewXAxis);
	mViewYAxis.normalise();

	// construct lookat matrices
	mLookAtMtx.makeLookat(mPosition, mViewXAxis, mViewYAxis, mViewZAxis);
	mLookAtMtx.inverse(&mInverseLookAtMtx);

	update(1.0f, mFov, mNear, mFar);
}

/*
 * --INFO--
 * Address:	8004300C
 * Size:	00003C
 */
void CullFrustum::calcLookAt(Vector3f& p1, Vector3f& p2, Vector3f* p3)
{
	mLookAtMtx.makeLookat(p1, p2, p3);
	mLookAtMtx.inverse(&mInverseLookAtMtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void CullFrustum::calcLookFrom(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00015C
 */
void Camera::camReflect(Camera&, Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80043048
 * Size:	00017C
 */
f32 Camera::projectWorldPoint(Graphics& gfx, Vector3f& point)
{
	f32 dist = mProjectionMatrix.mMtx[3][0] * point.x + mProjectionMatrix.mMtx[3][1] * point.y + mProjectionMatrix.mMtx[3][2] * point.z
	         + mProjectionMatrix.mMtx[3][3];
	if (dist <= 0.0f) {
		return dist;
	}

	point.multMatrix(mProjectionMatrix);
	f32 norm = 1.0f / dist;
	point.x *= norm;
	point.y *= norm;
	point.z *= norm;

	point.x *= gfx.mScreenWidth / 2.0f;
	point.y *= -(gfx.mScreenHeight / 2.0f);

	point.x += gfx.mScreenWidth / 2.0f;
	point.y += gfx.mScreenHeight / 2.0f;

	return point.z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000170
 */
f32 Camera::projectCamPoint(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	800431C4
 * Size:	000150
 */
Camera::Camera()
{
	mRotation.set(0.0f, 4.363323f, 0.0f);
	_32C.set(0.0f, 0.0f, 0.0f);
	mAspectRatio = 1.0f;
	mBlur        = 110.0f;
}

/*
 * --INFO--
 * Address:	80043314
 * Size:	0000D0
 */
void LightCamera::initLightmap(int size, int texFmt)
{
	mLightMap                = new Texture();
	f32 sizeFactor           = 1.0f / f32(size);
	mLightMap->mWidthFactor  = sizeFactor;
	mLightMap->mHeightFactor = sizeFactor;
	mLightMap->mTexFlags     = (Texture::TEX_CLAMP_S | Texture::TEX_Unk2 | Texture::TEX_CLAMP_T);
	mLightMap->createBuffer(size, size, texFmt, nullptr);
	gsys->addTexture(mLightMap, "internalLightmap");
}

/*
 * --INFO--
 * Address:	800433E4
 * Size:	000508
 */
void LightCamera::calcProjection(Graphics& gfx, bool p2, Node* p3)
{
	f32 targetDist = mPosition.distance(mFocus);
	f32 cosTheta   = cosf(PI * mFov / 180.0f);
	f32 sinTheta   = sinf(PI * mFov / 180.0f);
	f32 tanTheta   = sinTheta / cosTheta;
	mFrustumRange  = tanTheta * targetDist;
	mFrustumSize   = mFrustumRange;

	Vector3f vec(mFrustumSize * (1.0f / tanTheta), mFrustumRange * (1.0f / tanTheta), 1.0f);
	Vector3f dir = mPosition - mFocus;

	mProjectionX = dir.length() / vec.x;
	mProjectionY = dir.length() / vec.y;

	mProjectionScale.set(0.5f * mProjectionX, 0.5f * mProjectionY, 1.0f);

	if (mLightMap && p3) {
		mProjectionX = 0.5f * (mProjectionX - 1.0f);
		mProjectionY = 0.5f * (mProjectionY - 1.0f);

		f32 width  = 2.0f * mLightMap->mWidth;
		f32 height = 2.0f * mLightMap->mHeight;
		gfx.setPerspective(mPerspectiveMatrix.mMtx, mFov, mAspectRatio, 30.0f, mFar, 1.0f);

		gfx.setViewport(RectArea(-(mProjectionX * width), -(height * mProjectionY), width + (int(width * mProjectionX)),
		                         height + (int(height * mProjectionY))));

		Camera* cam = gfx.mCamera;
		gfx.setClearColour(Colour(0, 0, 0, 0));
		gfx.clearBuffer(3, 0);

		gfx.setScissor(RectArea(4, 4, int(width) - 4, int(height) - 4));
		gfx.setFog(false);
		gfx.setLighting(false, nullptr);
		gfx.setCamera(this);
		gfx.useTexture(nullptr, GX_TEXMAP0);
		p3->draw(gfx);

		mLightMap->grabBuffer(mLightMap->mWidth, mLightMap->mHeight, true, true);
		gfx.setCamera(cam);
	}
}
