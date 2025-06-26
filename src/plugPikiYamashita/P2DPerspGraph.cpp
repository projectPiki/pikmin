#include "P2D/Graph.h"
#include "Dolphin/gx.h"
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
DEFINE_PRINT("P2DPersGraph") // nice typo

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
P2DPerspGraph::P2DPerspGraph()
    : P2DGrafContext(0, 0, 0, 0) // TODO: fix later
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000084
 */
P2DPerspGraph::P2DPerspGraph(const PUTRect& rect, f32, f32, f32)
    : P2DGrafContext(rect)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B0190
 * Size:	000084
 */
P2DPerspGraph::P2DPerspGraph(int x0, int y0, int width, int height, f32 fovy, f32 nearZ, f32 farZ)
    : P2DGrafContext(x0, y0, width, height)
{
	set(fovy, nearZ, farZ);
	mGrafType = P2DGRAF_Persp;
}

/*
 * --INFO--
 * Address:	801B0214
 * Size:	000060
 */
void P2DPerspGraph::set(f32 fovy, f32 nearZ, f32 farZ)
{
	setFovy(fovy);
	setNearClip(nearZ);
	setFarClip(farZ);
	setLookat();
}

/*
 * --INFO--
 * Address:	801B0274
 * Size:	00002C
 */
void P2DPerspGraph::setFovy(f32 fovy)
{
	mFovy = fovy;
	if (fovy < 1.0f) {
		mFovy = 1.0f;
	} else if (fovy > 179.0f) {
		mFovy = 179.0f;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
void P2DPerspGraph::getMatrix(Matrix4f& mtx)
{
	f32 aspectRatio = f32(mViewportBounds.getWidth()) / f32(mViewportBounds.getHeight());
	mtx.makePerspective(mFovy, aspectRatio, mNearClipZ, mFarClipZ); // NB: unimplemented
}

/*
 * --INFO--
 * Address:	801B02A0
 * Size:	00016C
 */
void P2DPerspGraph::setPort()
{
	P2DGrafContext::setPort();
	Matrix4f perspMtx;
	f32 width  = f32(mViewportBounds.getWidth());
	f32 height = f32(mViewportBounds.getHeight());
#if defined(VERSION_GPIP01_00)
	C_MTXPerspective(perspMtx.mMtx, mFovy, width / height, mNearClipZ, mFarClipZ);
#else
	MTXPerspective(perspMtx.mMtx, mFovy, width / height, mNearClipZ, mFarClipZ);
#endif

	GXSetProjection(perspMtx.mMtx, GX_PERSPECTIVE);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mProjectionMtx.mMtx[j][i] = perspMtx.mMtx[j][i];
		}
	}

	f32 zScale                = (1.0f / (mFarClipZ - mNearClipZ));
	mProjectionMtx.mMtx[2][2] = zScale * -(mFarClipZ + mNearClipZ);
	mProjectionMtx.mMtx[2][3] = zScale * -(2.0f * mFarClipZ * mNearClipZ);

	GXSetZMode(GX_FALSE, GX_ALWAYS, GX_FALSE);
}

/*
 * --INFO--
 * Address:	801B040C
 * Size:	000094
 */
void P2DPerspGraph::setLookat()
{
	mDistance = ((f32(mViewportBounds.mMaxY) - f32(mViewportBounds.mMinY)) / 2.0f) / tanf(mFovy * PI / 360.0f);
	makeLookat();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void P2DPerspGraph::setDistance(f32 distance)
{
	mDistance = distance;
	makeLookat();
}

/*
 * --INFO--
 * Address:	801B04A0
 * Size:	0001FC
 */
void P2DPerspGraph::makeLookat()
{
	f32 halfWidth  = (f32(mViewportBounds.mMaxX) - f32(mViewportBounds.mMinX)) / 2.0f;
	f32 halfHeight = (f32(mViewportBounds.mMaxY) - f32(mViewportBounds.mMinY)) / 2.0f;

	Vector3f cameraPos;
	Vector3f targetPos;

	cameraPos.x = halfWidth;
	cameraPos.y = halfHeight;
	cameraPos.z = -mDistance;

	targetPos.x = halfWidth;
	targetPos.y = halfHeight;
	targetPos.z = 0.0f;

	Vector3f upDir;
	upDir.x = 0.0f;
	upDir.y = -1.0f;
	upDir.z = 0.0f;

	mViewMtx.makeLookat(cameraPos, targetPos, &upDir);
	mViewMtx.makeLookat(Vector3f(0.0f, 0.0f, 250.0f), Vector3f(0.0f, 0.0f, 0.0f), &Vector3f(0.0f, 1.0f, 0.0f));
	mViewMtx.makeLookat(Vector3f(halfWidth, halfHeight, -mDistance), Vector3f(1.0f, 0.0f, 0.0f), Vector3f(0.0f, -1.0f, 0.0f),
	                    Vector3f(0.0f, 0.0f, -1.0f));

	GXLoadPosMtxImm(mViewMtx.mMtx, 0);
}
