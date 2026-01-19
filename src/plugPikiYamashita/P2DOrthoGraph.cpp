#include "Dolphin/gx.h"
#include "P2D/Graph.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 000088
 */
P2DOrthoGraph::P2DOrthoGraph()
    : P2DGrafContext(0, 0, 0, 0) // TODO: fix later
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000C8
 */
P2DOrthoGraph::P2DOrthoGraph(const PUTRect& rect)
    : P2DGrafContext(rect)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 */
void P2DOrthoGraph::setPort()
{
	P2DGrafContext::setPort();

	MTXOrtho(mProjectionMtx.mMtx, mLogicalViewBounds.mMinY, mLogicalViewBounds.mMaxY, mLogicalViewBounds.mMinX, mLogicalViewBounds.mMaxX,
	         mLogicalNearZ, mLogicalFarZ);
	GXSetProjection(mProjectionMtx.mMtx, GX_ORTHOGRAPHIC);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void P2DOrthoGraph::setOrtho(const PUTRect& viewBounds, int nearZ, int farZ)
{
	mLogicalViewBounds = viewBounds;
	mLogicalFarZ       = -farZ;
	mLogicalNearZ      = -nearZ;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E4
 */
void P2DOrthoGraph::setOrigin(int x, int y)
{
	mLogicalViewBounds.add(-x, -y);
}

/**
 * @todo: Documentation
 */
void P2DOrthoGraph::setLookat()
{
	mViewMtx.makeIdentity();
	GXLoadPosMtxImm(mViewMtx.mMtx, 0);
}

/**
 * @todo: Documentation
 */
void P2DOrthoGraph::scissorBounds(PUTRect* outBounds, PUTRect* inBounds)
{
	outBounds->mMinX = int(getWidthPower() * (inBounds->mMinX - mLogicalViewBounds.mMinX) + mViewportBounds.mMinX + 0.1f);
	outBounds->mMaxX = int(getWidthPower() * (inBounds->mMaxX - mLogicalViewBounds.mMinX) + mViewportBounds.mMinX + 0.9f);

	outBounds->mMinY = int(getHeightPower() * (inBounds->mMinY - mLogicalViewBounds.mMinY) + mViewportBounds.mMinY + 0.1f);
	outBounds->mMaxY = int(getHeightPower() * (inBounds->mMaxY - mLogicalViewBounds.mMinY) + mViewportBounds.mMinY + 0.9f);
}
