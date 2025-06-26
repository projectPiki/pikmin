#include "P2D/Graph.h"
#include "Dolphin/gx.h"

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
P2DOrthoGraph::P2DOrthoGraph()
    : P2DGrafContext(0, 0, 0, 0) // TODO: fix later
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
P2DOrthoGraph::P2DOrthoGraph(const PUTRect& rect)
    : P2DGrafContext(rect)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801AFCF0
 * Size:	0000C4
 */
P2DOrthoGraph::P2DOrthoGraph(int x0, int y0, int width, int height)
    : P2DGrafContext(x0, y0, width, height)
{
	mLogicalViewBounds = PUTRect(0, 0, width, height);
	mLogicalFarZ       = -1;
	mLogicalNearZ      = 1;
	setLookat();
	mGrafType = P2DGRAF_Ortho;
}

/*
 * --INFO--
 * Address:	801AFDB4
 * Size:	0000D8
 */
void P2DOrthoGraph::setPort()
{
	P2DGrafContext::setPort();

#if defined(VERSION_G98E01_PIKIDEMO) || defined(VERSION_GPIP01_00)
	C_MTXOrtho(mProjectionMtx.mMtx, mLogicalViewBounds.mMinY, mLogicalViewBounds.mMaxY, mLogicalViewBounds.mMinX, mLogicalViewBounds.mMaxX,
	           mLogicalNearZ, mLogicalFarZ);
#else
	MTXOrtho(mProjectionMtx.mMtx, mLogicalViewBounds.mMinY, mLogicalViewBounds.mMaxY, mLogicalViewBounds.mMinX, mLogicalViewBounds.mMaxX,
	         mLogicalNearZ, mLogicalFarZ);
#endif
	GXSetProjection(mProjectionMtx.mMtx, GX_ORTHOGRAPHIC);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void P2DOrthoGraph::setOrtho(const PUTRect& p1, int p2, int p3)
{
	mLogicalViewBounds = p1;
	mLogicalFarZ       = -p3;
	mLogicalNearZ      = -p2;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void P2DOrthoGraph::setOrigin(int x, int y)
{
	mLogicalViewBounds.add(-x, -y);
}

/*
 * --INFO--
 * Address:	801AFE8C
 * Size:	00003C
 */
void P2DOrthoGraph::setLookat()
{
	mViewMtx.makeIdentity();
	GXLoadPosMtxImm(mViewMtx.mMtx, 0);
}

/*
 * --INFO--
 * Address:	801AFEC8
 * Size:	00026C
 */
void P2DOrthoGraph::scissorBounds(PUTRect* outBounds, PUTRect* inBounds)
{
	outBounds->mMinX = int(getWidthPower() * (inBounds->mMinX - mLogicalViewBounds.mMinX) + mViewportBounds.mMinX + 0.1f);
	outBounds->mMaxX = int(getWidthPower() * (inBounds->mMaxX - mLogicalViewBounds.mMinX) + mViewportBounds.mMinX + 0.9f);

	outBounds->mMinY = int(getHeightPower() * (inBounds->mMinY - mLogicalViewBounds.mMinY) + mViewportBounds.mMinY + 0.1f);
	outBounds->mMaxY = int(getHeightPower() * (inBounds->mMaxY - mLogicalViewBounds.mMinY) + mViewportBounds.mMinY + 0.9f);
}
