#include "nlib/Spline.h"
#include "nlib/Array.h"
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
DEFINE_PRINT("nlibspline")

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
SplineInterpolator::SplineInterpolator(int size, NPool<SplineSegment>* segPool)
{
	mFrameArray      = new NArray<SplineKeyFrame>(size);
	_04              = segPool;
	mViewpointCurve  = new SplineCurve(size - 1);
	mWatchpointCurve = new SplineCurve(size - 1);
	_10              = 0;
}

/*
 * --INFO--
 * Address:	8011DE60
 * Size:	00000C
 */
void SplineInterpolator::reset()
{
	_10 = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void SplineInterpolator::makeSpline()
{
	f32 fVals[16];
	NVector3f* vecVals[16];
	if (mFrameArray->getSize() < 2) {
		return;
	}

	for (int i = 0; i < mFrameArray->getSize(); i++) {
		fVals[i] = mFrameArray->get(i)->getParameter();
	}

	for (int i = 0; i < mFrameArray->getSize(); i++) {
		vecVals[i] = &mFrameArray->get(i)->getPosture().getViewpoint();
	}

	mViewpointCurve->makeCurve(fVals, vecVals, mFrameArray->getSize());

	for (int i = 0; i < mFrameArray->getSize(); i++) {
		vecVals[i] = &mFrameArray->get(i)->getPosture().getWatchpoint();
	}

	mWatchpointCurve->makeCurve(fVals, vecVals, mFrameArray->getSize());
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
bool SplineInterpolator::interpolate(f32 t, NPosture3D& outPosture, bool isDirect)
{
	if (isDirect) {
		return interpolateDirect(t, outPosture);
	}

	return interpolateNext(t, outPosture);
}

/*
 * --INFO--
 * Address:	8011DE6C
 * Size:	0000E0
 */
bool SplineInterpolator::interpolateNext(f32 t, NPosture3D& outPosture)
{
	if (mFrameArray->getSize() == 0) {
		return false;
	}

	if (mFrameArray->getSize() == 1) {
		outPosture.input(mFrameArray->get(0)->getPosture());
		return true;
	}

	int idx = searchSegmentIndex(t, _10);
	if (idx < 0) {
		PRINT("?interpolateNext:nextIndex<0\n");
		return false;
	}

	_10 = idx;
	outputPosture(t, outPosture);
	return true;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000FC
 */
bool SplineInterpolator::interpolateDirect(f32 t, NPosture3D& outPosture)
{
	u8 prev  = _10;
	_10      = 0;
	bool res = interpolateNext(t, outPosture);
	_10      = prev;
	return res;
}

/*
 * --INFO--
 * Address:	8011DF4C
 * Size:	0000F0
 */
void SplineInterpolator::outputPosture(f32 t, NPosture3D& outPosture)
{
	f32 thisParam = mFrameArray->get(_10)->getParameter();
	f32 nextParam = mFrameArray->get(_10 + 1)->getParameter();
	f32 newT      = (t - thisParam) / (nextParam - thisParam);
	mViewpointCurve->getSegment(_10)->outputPosition(newT, outPosture.getViewpoint());
	mWatchpointCurve->getSegment(_10)->outputPosition(newT, outPosture.getWatchpoint());
}

/*
 * --INFO--
 * Address:	8011E03C
 * Size:	0000BC
 */
int SplineInterpolator::searchSegmentIndex(f32 targetParam, int startIdx)
{
	if (mFrameArray->getSize() < 2) {
		return 0;
	}

	for (int i = startIdx; i < mFrameArray->getSize() - 1; i++) {
		if (targetParam <= mFrameArray->get(i + 1)->getParameter()) {
			return i;
		}
	}

	PRINT("?searchSegmentIndex:%f,%f,%d\n", targetParam, mFrameArray->get(mFrameArray->getSize() - 1)->getParameter(), startIdx);
	return mFrameArray->getSize() - 2;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void SplineInterpolator::addFrame(SplineKeyFrame*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void NArray<SplineKeyFrame>::add(SplineKeyFrame*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
void SplineInterpolator::addSegment()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void NArray<SplineSegment>::add(SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void NPool<SplineSegment>::newObject()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void SplineInterpolator::removeAllFrames()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NArray<SplineSegment>::removeAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void NArray<SplineSegment>::remove(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NPool<SplineSegment>::deleteObject(SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
void NPool<SplineSegment>::deleteObject(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NPool<SplineSegment>::indexOf(SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NPool<SplineSegment>::indexOf(SplineSegment*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NArray<SplineKeyFrame>::removeAll()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
void NArray<SplineKeyFrame>::remove(int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
SplineKeyFrame::SplineKeyFrame()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void SplineKeyFrame::transform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void SplineKeyFrame::inputPosture(NPosture3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void SplineKeyFrame::outputPosture(NPosture3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void SplineKeyFrame::interpolate(SplineKeyFrame&, f32, NPosture3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void SplineKeyFrame::readData(Stream&, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
SplineSegment::SplineSegment()
{
	mPolyFunX.construct(mCoeffsX, 3);
	mPolyFunY.construct(mCoeffsY, 3);
	mPolyFunZ.construct(mCoeffsZ, 3);
	mFunction3D.construct(&mPolyFunX, &mPolyFunY, &mPolyFunZ);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001EC
 */
f32 SplineSegment::calcDistance(NVector3f&, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
SplineCurve::SplineCurve(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003E8
 */
void SplineCurve::makeCurve(f32*, NVector3f**, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000334
 */
void SplineCurve::makeFunctions(int, f32*, f32*, NPolynomialFunction**)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
int NArray<SplineKeyFrame>::indexOf(SplineKeyFrame*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NArray<SplineKeyFrame>::set(int, SplineKeyFrame*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineKeyFrame>::remove(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void NArray<SplineKeyFrame>::insert(int, SplineKeyFrame*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
SplineKeyFrame* NArray<SplineKeyFrame>::firstElement()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
SplineKeyFrame* NArray<SplineKeyFrame>::lastElement()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
int NArray<SplineSegment>::indexOf(SplineSegment*, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NArray<SplineSegment>::set(int, SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineSegment>::remove(int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
void NArray<SplineSegment>::insert(int, SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
SplineSegment* NArray<SplineSegment>::firstElement()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
SplineSegment* NArray<SplineSegment>::lastElement()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineSegment>::remove(SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineSegment>::add(int, SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
int NArray<SplineSegment>::indexOf(SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
bool NArray<SplineSegment>::contains(SplineSegment*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineKeyFrame>::remove(SplineKeyFrame*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000050
 */
void NArray<SplineKeyFrame>::add(int, SplineKeyFrame*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
int NArray<SplineKeyFrame>::indexOf(SplineKeyFrame*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
bool NArray<SplineKeyFrame>::contains(SplineKeyFrame*)
{
	// UNUSED FUNCTION
}
