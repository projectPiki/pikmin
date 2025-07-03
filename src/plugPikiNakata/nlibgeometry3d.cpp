#include "nlib/Geometry3D.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address:	........
 * Size:	00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
DEFINE_PRINT("nlibgeometry3d");

/*
 * --INFO--
 * Address:	........
 * Size:	00008C
 */
NLine::NLine()
{
	construct(NVector3f(0.0f, 0.0f, 0.0f), NVector3f(0.0f, 0.0f, 1.0f));
}

/*
 * --INFO--
 * Address:	8011D3FC
 * Size:	000070
 */
NLine::NLine(NVector3f& pos, NVector3f& dir)
{
	construct(pos, dir);
}

/*
 * --INFO--
 * Address:	8011D46C
 * Size:	000034
 */
void NLine::construct(NVector3f& pos, NVector3f& dir)
{
	mPosition.input(pos);
	mDirection.input(dir);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
NLine::NLine(NLine& other)
{
	construct(other);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NLine::construct(NLine& other)
{
	construct(other.mPosition, other.mDirection);
}

/*
 * --INFO--
 * Address:	8011D4A0
 * Size:	0000C0
 */
f32 NLine::calcDistance(NVector3f& point, f32* vertProj)
{
	NVector3f& pos = NVector3f();
	f32 proj       = calcVerticalProjection(point);
	outputPosition(proj, pos);

	if (vertProj) {
		*vertProj = proj;
	}

	return pos.distance(point);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002AC
 */
f32 NLine::calcDistance(NLine& other, f32* closestPointThisLine, f32* closestPointOtherLine)
{
	f32 directionsAlignment = mDirection.dot(other.getDirection());

	if (NMathF::equals(directionsAlignment, 1.0f) || NMathF::equals(directionsAlignment, -1.0f)) {
		// Lines are parallel or anti-parallel
		f32 projectionOnLine = 0.0f;
		f32 distance         = calcDistance(other.getPosition(), &projectionOnLine);

		if (closestPointThisLine) {
			*closestPointThisLine = projectionOnLine;
		}

		if (closestPointOtherLine) {
			*closestPointOtherLine = 0.0f;
		}

		return distance;
	}

	NVector3f& otherOrigin  = NVector3f(other.getPosition());
	f32 otherOrigProjection = -otherOrigin.dot(other.getDirection());
	f32 paramOnOtherLine
	    = (otherOrigin.dot(mDirection) * directionsAlignment + otherOrigProjection) / (1.0f - directionsAlignment * directionsAlignment);
	f32 paramOnThisLine = otherOrigin.dot(mDirection) + paramOnOtherLine * directionsAlignment;

	NVector3f& closestPointThis = NVector3f();
	outputPosition(paramOnThisLine, closestPointThis);

	NVector3f& closestPointOther = NVector3f();
	other.outputPosition(paramOnOtherLine, closestPointOther);

	if (closestPointThisLine) {
		*closestPointThisLine = paramOnThisLine;
	}

	if (closestPointOtherLine) {
		*closestPointOtherLine = paramOnOtherLine;
	}

	return closestPointThis.distance(closestPointOther);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NLine::outputVerticalPosition(NVector3f& point, NVector3f& outPos)
{
	outputPosition(calcVerticalProjection(point), outPos);
}

/*
 * --INFO--
 * Address:	8011D560
 * Size:	000064
 */
f32 NLine::calcVerticalProjection(NVector3f& point)
{
	NVector3f& sep = NVector3f(mPosition, point);
	return mDirection.dot(sep);
}

/*
 * --INFO--
 * Address:	8011D5C4
 * Size:	00009C
 */
void NLine::outputPosition(f32 t, NVector3f& outPos)
{
	NVector3f& tmp = NVector3f();
	tmp.scale2(t, mDirection);
	outPos.add2(mPosition, tmp);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A8
 */
void NLine::outputPositionY(f32 p1, NVector3f& outPos)
{
	outputPosition((p1 - mPosition.y) / mDirection.y, outPos);
}

/*
 * --INFO--
 * Address:	8011D660
 * Size:	00004C
 */
void NLine::transform(NTransform3D& transform)
{
	transform.transform(mPosition);
	transform.rotate(mDirection);
}

/*
 * --INFO--
 * Address:	8011D6AC
 * Size:	000038
 */
void NLine::println()
{
	PRINT("position:\n");
	mPosition.println();
	PRINT("direction:\n");
	mDirection.println();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
NPlane::NPlane()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
NPlane::NPlane(NVector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NPlane::construct(NVector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D6E4
 * Size:	000068
 */
NPlane::NPlane(NVector3f& normal, NVector3f& point)
{
	construct(normal, point);
}

/*
 * --INFO--
 * Address:	8011D74C
 * Size:	000050
 */
void NPlane::construct(NVector3f& normal, NVector3f& point)
{
	mNormal.input(normal);
	setDifference(point);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
NPlane::NPlane(NVector3f&, NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E8
 */
void NPlane::construct(NVector3f&, NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
NPlane::NPlane(Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NPlane::construct(Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
NPlane::NPlane(NPlane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NPlane::construct(NPlane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000114
 */
bool NPlane::intersects(NLine&, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00018C
 */
bool NPlane::outputIntersection(NLine&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000154
 */
bool NPlane::intersectsRay(NLine&, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
bool NPlane::outputRayIntersection(NLine&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001DC
 */
bool NPlane::intersectsSegment(NSegment&, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000188
 */
bool NPlane::outputSegmentIntersection(NSegment&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NPlane::outputPosition(NVector3f& outPos)
{
	outPos.scale2(-mDifference, mNormal);
}

/*
 * --INFO--
 * Address:	8011D79C
 * Size:	0000DC
 */
void NPlane::outputVerticalPosition(NVector3f& point, NVector3f& outPos)
{
	f32 t          = judge(point);
	NVector3f& tmp = NVector3f();
	tmp.scale2(-t, mNormal);
	outPos.add2(point, tmp);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
void NPlane::negate()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
bool NPlane::adjustTo(NVector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
bool NPlane::adjust(NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00028C
 */
bool NPlane::outputIntersectionLineY(NPlane&, NLine&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
f32 NPlane::calcAngle(NPlane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
f32 NPlane::calcY(f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8011D878
 * Size:	0000C0
 */
void NPlane::transform(NTransform3D& transform)
{
	NVector3f& tmp = NVector3f();
	outputPosition(tmp);
	transform.rotate(mNormal);
	transform.transform(tmp);
	setDifference(tmp);
}

/*
 * --INFO--
 * Address:	8011D938
 * Size:	000024
 */
void NPlane::println()
{
	PRINT("normal:\n");
	mNormal.println();
	PRINT("difference:%f\n", mDifference);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
NSegment::NSegment()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D4
 */
NSegment::NSegment(NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void NSegment::construct(NVector3f&, NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
NSegment::NSegment(NSegment&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void NSegment::construct(NSegment&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002E0
 */
f32 NSegment::calcDistanceAsSegment(NVector3f&, f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003CC
 */
f32 NSegment::calcDistanceAsSegment(NLine&, f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000230
 */
f32 NSegment::calcSegmentDistanceAsSegment(NSegment&, f32*, f32*)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NSegment::transform(NTransform3D&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NSegment::translate(NVector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NSegment::makeProjectionY()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
void NSegment::println()
{
	NLine::println();
	PRINT("edge:\n");
	mEdge.println();
}
