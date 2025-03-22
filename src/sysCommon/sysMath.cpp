#include "types.h"
#include "math.h"
#include "Plane.h"
#include "Camera.h"
#include "Matrix3f.h"
#include "stl/math.h"
#include "Collision.h"
#include "BoundBox.h"
#include "KMath.h"
#include "Graphics.h"
#include "DebugLog.h"

/*
 * --INFO--
 * Address: ........
 * Size:    00009C
 */
DEFINE_ERROR()

/*
 * --INFO--
 * Address: ........
 * Size:    0000F0
 */
DEFINE_PRINT(nullptr)

/*
 * --INFO--
 * Address: ........
 * Size:    0000C0
 */
bool Plane::equal(Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000148
 */
f32 Plane::calcRadScale()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000074
 */
void Plane::reflect(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    00006C
 */
void Plane::reflectVector(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000078
 */
void Plane::bounceVector(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000084
 */
void Plane::frictionVector(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 8003756C
 * Size:    0000A0
 */
void CullingPlane::CheckMinMaxDir()
{
	if (mPlane.mNormal.x < 0.0f) {
		_10 = 3;
		_1C = 0;
	} else {
		_10 = 0;
		_1C = 3;
	}

	if (mPlane.mNormal.y < 0.0f) {
		_14 = 4;
		_20 = 1;
	} else {
		_14 = 1;
		_20 = 4;
	}

	if (mPlane.mNormal.z < 0.0f) {
		_18 = 5;
		_24 = 2;
	} else {
		_18 = 2;
		_24 = 5;
	}
}

/*
 * --INFO--
 * Address: ........
 * Size:    0000AC
 */
void Vector3f::rotateTranspose(Matrix4f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 8003760C
 * Size:    0000AC
 */
void Vector3f::rotate(Matrix4f& mtx)
{
	Vector3f vec;
	vec.x = mtx.mMtx[0][0] * x + mtx.mMtx[0][1] * y + mtx.mMtx[0][2] * z;
	vec.y = mtx.mMtx[1][0] * x + mtx.mMtx[1][1] * y + mtx.mMtx[1][2] * z;
	vec.z = mtx.mMtx[2][0] * x + mtx.mMtx[2][1] * y + mtx.mMtx[2][2] * z;

	*this = vec;
}

/*
 * --INFO--
 * Address: 800376B8
 * Size:    000094
 */
void Vector3f::rotateTo(Matrix4f& mtx, Vector3f& outVec)
{
	outVec.x = mtx.mMtx[0][0] * x + mtx.mMtx[0][1] * y + mtx.mMtx[0][2] * z;
	outVec.y = mtx.mMtx[1][0] * x + mtx.mMtx[1][1] * y + mtx.mMtx[1][2] * z;
	outVec.z = mtx.mMtx[2][0] * x + mtx.mMtx[2][1] * y + mtx.mMtx[2][2] * z;
}

/*
 * --INFO--
 * Address: 8003774C
 * Size:    0000C4
 */
void Vector3f::multMatrix(Matrix4f& mtx)
{
	Vector3f vec;
	vec.x = mtx.mMtx[0][0] * x + mtx.mMtx[0][1] * y + mtx.mMtx[0][2] * z + mtx.mMtx[0][3];
	vec.y = mtx.mMtx[1][0] * x + mtx.mMtx[1][1] * y + mtx.mMtx[1][2] * z + mtx.mMtx[1][3];
	vec.z = mtx.mMtx[2][0] * x + mtx.mMtx[2][1] * y + mtx.mMtx[2][2] * z + mtx.mMtx[2][3];
	*this = vec;
}

/*
 * --INFO--
 * Address: 80037810
 * Size:    0000AC
 */
void Vector3f::multMatrixTo(Matrix4f& mtx, Vector3f& outVec)
{
	outVec.x = mtx.mMtx[0][0] * x + mtx.mMtx[0][1] * y + mtx.mMtx[0][2] * z + mtx.mMtx[0][3];
	outVec.y = mtx.mMtx[1][0] * x + mtx.mMtx[1][1] * y + mtx.mMtx[1][2] * z + mtx.mMtx[1][3];
	outVec.z = mtx.mMtx[2][0] * x + mtx.mMtx[2][1] * y + mtx.mMtx[2][2] * z + mtx.mMtx[2][3];
}

/*
 * --INFO--
 * Address: ........
 * Size:    000110
 */
void Vector3f::rotate(Quat&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000104
 */
void Vector3f::rotateInverse(Quat&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 800378BC
 * Size:    0004E4
 */
void Quat::fromMat3f(Matrix3f& mtx)
{
	f32 diag = mtx.mMtx[0] + mtx.mMtx[4] + mtx.mMtx[8];
	f32 a    = 0.25f * (1.0f + diag);                  // f4
	f32 b    = a - 0.5f * (mtx.mMtx[4] + mtx.mMtx[8]); // f2, f5
	f32 c    = a - 0.5f * (mtx.mMtx[8] + mtx.mMtx[0]); // f6
	f32 d    = a - 0.5f * (mtx.mMtx[0] + mtx.mMtx[4]); // f7

	int type;
	if (a > b) {
		if (a > c) {
			if (a > d) {
				type = 0;
			} else {
				type = 3;
			}
		} else if (c > d) {
			type = 2;
		} else {
			type = 3;
		}
	} else if (b > c) {
		if (b > d) {
			type = 1;
		} else {
			type = 3;
		}
	} else if (c > d) {
		type = 2;
	} else {
		type = 3;
	}

	switch (type) {
	case 0: {
		s     = std::sqrtf(a);
		f32 t = 0.25f / s;
		v.x   = t * (mtx.mMtx[7] - mtx.mMtx[5]);
		v.y   = t * (mtx.mMtx[2] - mtx.mMtx[6]);
		v.z   = t * (mtx.mMtx[3] - mtx.mMtx[1]);
	} break;
	case 1: {
		v.x   = std::sqrtf(b);
		f32 t = 0.25f / v.x;
		s     = t * (mtx.mMtx[7] - mtx.mMtx[5]);
		v.y   = t * (mtx.mMtx[1] + mtx.mMtx[3]);
		v.z   = t * (mtx.mMtx[2] + mtx.mMtx[6]);
	} break;
	case 2: {
		v.y   = std::sqrtf(c);
		f32 t = 0.25f / v.y;
		s     = t * (mtx.mMtx[2] - mtx.mMtx[6]);
		v.z   = t * (mtx.mMtx[5] + mtx.mMtx[7]);
		v.x   = t * (mtx.mMtx[3] + mtx.mMtx[1]);
	} break;
	case 3: {
		v.z   = std::sqrtf(d);
		f32 t = 0.25f / v.z;
		s     = t * (mtx.mMtx[3] - mtx.mMtx[1]);
		v.x   = t * (mtx.mMtx[6] + mtx.mMtx[2]);
		v.y   = t * (mtx.mMtx[7] + mtx.mMtx[5]);
	} break;
	}

	if (s < 0.0f) {
		s   = -s;
		v.x = -v.x;
		v.y = -v.y;
		v.z = -v.z;
	}

	f32 n = 1.0f / std::sqrtf(SQUARE(s) + SQUARE(v.x) + SQUARE(v.y) + SQUARE(v.z));

	s *= n;
	v.x *= n;
	v.y *= n;
	v.z *= n;
}

/*
 * --INFO--
 * Address: 80037DA0
 * Size:    0000A4
 */
void Quat::rotate(Vector3f& axis, f32 angle)
{
	f32 theta  = 0.5f * angle;
	f32 sinVal = sinf(theta);
	f32 cosVal = cosf(theta);

	Quat quat(axis.x * sinVal, axis.y * sinVal, axis.z * sinVal, cosVal);

	multiply(quat);
}

/*
 * --INFO--
 * Address: 80037E44
 * Size:    0000EC
 */
void Quat::multiply(Quat& other)
{
	Quat tmp;
	tmp.s   = other.s * s - other.v.x * v.x - other.v.y * v.y - other.v.z * v.z;
	tmp.v.x = (other.v.y * v.z + (other.s * v.x + other.v.x * s)) - other.v.z * v.y;
	tmp.v.y = (other.v.z * v.x + (other.s * v.y + other.v.y * s)) - other.v.x * v.z;
	tmp.v.z = (other.v.x * v.y + (other.s * v.z + other.v.z * s)) - other.v.y * v.x;
	*this   = tmp;
}

/*
 * --INFO--
 * Address: ........
 * Size:    000104
 */
void Quat::multiplyTo(Quat& other, Quat& outQuat)
{
	outQuat.s   = other.s * s - other.v.x * v.x - other.v.y * v.y - other.v.z * v.z;
	outQuat.v.x = (other.v.y * v.z + (other.s * v.x + other.v.x * s)) - other.v.z * v.y;
	outQuat.v.y = (other.v.z * v.x + (other.s * v.y + other.v.y * s)) - other.v.x * v.z;
	outQuat.v.z = (other.v.x * v.y + (other.s * v.z + other.v.z * s)) - other.v.y * v.x;
}

/*
 * --INFO--
 * Address: 80037F30
 * Size:    0000D4
 */
void Quat::normalise()
{
	f32 factor = 1.0f / std::sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + s * s);
	v.x *= factor;
	v.y *= factor;
	v.z *= factor;
	s *= factor;
}

/*
 * --INFO--
 * Address: 80038004
 * Size:    000080
 */
void Quat::genVectorX(Vector3f& outVec)
{
	f32 yy   = v.y * v.y;
	f32 zz   = v.z * v.z;
	outVec.x = (1.0f - 2.0f * yy) - (2.0f * zz);

	f32 xy   = v.x * v.y;
	f32 sz   = s * v.z;
	outVec.y = 2.0f * xy + 2.0f * sz;

	f32 xz   = v.x * v.z;
	f32 sy   = s * v.y;
	outVec.z = 2.0f * xz - 2.0f * sy;
}

/*
 * --INFO--
 * Address: 80038084
 * Size:    000080
 */
void Quat::genVectorY(Vector3f& outVec)
{
	f32 xy   = v.x * v.y;
	f32 sz   = s * v.z;
	outVec.x = 2.0f * xy - 2.0f * sz;

	f32 xx   = v.x * v.x;
	f32 zz   = v.z * v.z;
	outVec.y = (1.0f - 2.0f * xx) - (2.0f * zz);

	f32 yz   = v.y * v.z;
	f32 sx   = s * v.x;
	outVec.z = 2.0f * yz + 2.0f * sx;
}

/*
 * --INFO--
 * Address: 80038104
 * Size:    000080
 */
void Quat::genVectorZ(Vector3f& outVec)
{
	f32 xz   = v.x * v.z;
	f32 sy   = s * v.y;
	outVec.x = 2.0f * xz + 2.0f * sy;

	f32 yz   = v.y * v.z;
	f32 sx   = s * v.x;
	outVec.y = 2.0f * yz - 2.0f * sx;

	f32 xx   = v.x * v.x;
	f32 yy   = v.y * v.y;
	outVec.z = (1.0f - 2.0f * xx) - (2.0f * yy);
}

/*
 * --INFO--
 * Address: 80038184
 * Size:    000164
 */
void Quat::slerp(Quat& other, f32 t, int)
{
	f32 dot = v.x * other.v.x + v.y * other.v.y + v.z * other.v.z + s * other.s;
	BOOL isNegative;
	if (dot < 0.0) {
		dot        = -dot;
		isNegative = TRUE;
	} else {
		isNegative = FALSE;
	}

	f32 tComp;
	if (1.0f - dot < 0.000001) {
		tComp = 1.0f - t;
	} else {
		f32 acosVal = acosf(dot);
		f32 sinVal  = sinf(acosVal);
		f32 ang     = t * acosVal;
		tComp       = sinf(acosVal - ang) / sinVal;
		t           = sinf(ang) / sinVal;
	}

	if (isNegative) {
		t = -t;
	}

	v.x = tComp * v.x + t * other.v.x;
	v.y = tComp * v.y + t * other.v.y;
	v.z = tComp * v.z + t * other.v.z;
	s   = tComp * s + t * other.s;
}

/*
 * --INFO--
 * Address: 800382E8
 * Size:    0002A0
 */
void Quat::fromEuler(Vector3f& angles)
{
	u32 badCompiler[3];

	Quat psiQ;
	Quat thetaQ;
	Quat phiQ;
	f32 psi   = 0.5f * angles.x;
	f32 theta = 0.5f * angles.y;
	f32 phi   = 0.5f * angles.z;

	psiQ.v.x = sinf(psi);
	psiQ.v.y = 0.0f;
	psiQ.v.z = 0.0f;
	psiQ.s   = cosf(psi);

	thetaQ.v.x = 0.0f;
	thetaQ.v.y = sinf(theta);
	thetaQ.v.z = 0.0f;
	thetaQ.s   = cosf(theta);

	phiQ.v.x = 0.0f;
	phiQ.v.y = 0.0f;
	phiQ.v.z = sinf(phi);
	phiQ.s   = cosf(phi);

	psiQ.multiplyTo(thetaQ, *this);
	multiplyTo(phiQ, *this);
	normalise();
}

/*
 * --INFO--
 * Address: 80038588
 * Size:    00002C
 */
f32 roundAng(f32 x)
{
	if (x < 0.0f) {
		x += TAU;
	}

	if (x >= TAU) {
		x -= TAU;
	}

	return x;
}

/*
 * --INFO--
 * Address: 800385B4
 * Size:    000074
 */
f32 angDist(f32 angle1, f32 angle2)
{
	f32 angle = roundAng(angle1 - angle2);

	if (angle >= PI) {
		angle = -roundAng(TAU - angle);
	}
	return angle;
}

/*
 * --INFO--
 * Address: 80038628
 * Size:    000050
 */
f32 qdist2(f32 x0, f32 y0, f32 x1, f32 y1)
{
	x1 -= x0;
	if (x1 < 0.0f) {
		x1 = -x1;
	}

	y1 -= y0;
	if (y1 < 0.0f) {
		y1 = -y1;
	}

	f32 min = (x1 > y1) ? y1 : x1;

	return (x1 + y1) - (0.5f * min);
}

/*
 * --INFO--
 * Address: ........
 * Size:    000080
 */
f32 qdist3(f32, f32, f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 80038678
 * Size:    0001BC
 */
void CollTriInfo::init(RoomInfo* info, Vector3f* vertices)
{
	for (int i = 0; i < 3; ++i) {
		Vector3f& nextVertex    = vertices[mVertexIndices[(i + 1) % 3]];
		Vector3f& currentVertex = vertices[mVertexIndices[i % 3]];

		Vector3f edgeNormal = nextVertex - currentVertex;

		edgeNormal.normalise();
		edgeNormal.CP(mTriangle.mNormal);
		mEdgePlanes[i].mNormal = edgeNormal;
		mEdgePlanes[i].mOffset = edgeNormal.DP(nextVertex);
	}
}

/*
 * --INFO--
 * Address: 80038834
 * Size:    0000C4
 */
int CollTriInfo::behindEdge(Vector3f& point)
{
	for (int i = 0; i < 3; i++) {
		if (mEdgePlanes[i].dist(point) < 0.0f) {
			return i;
		}
	}

	return -1;
}

/*
 * --INFO--
 * Address: 800388F8
 * Size:    000644
 */
void BoundBox::draw(Graphics& gfx)
{
	// Top face
	gfx.drawLine(Vector3f(mMin.x, mMin.y, mMin.z), Vector3f(mMax.x, mMin.y, mMin.z));
	gfx.drawLine(Vector3f(mMax.x, mMin.y, mMin.z), Vector3f(mMax.x, mMin.y, mMax.z));
	gfx.drawLine(Vector3f(mMax.x, mMin.y, mMax.z), Vector3f(mMin.x, mMin.y, mMax.z));
	gfx.drawLine(Vector3f(mMin.x, mMin.y, mMax.z), Vector3f(mMin.x, mMin.y, mMin.z));

	// Bottom face
	gfx.drawLine(Vector3f(mMin.x, mMax.y, mMin.z), Vector3f(mMax.x, mMax.y, mMin.z));
	gfx.drawLine(Vector3f(mMax.x, mMax.y, mMin.z), Vector3f(mMax.x, mMax.y, mMax.z));
	gfx.drawLine(Vector3f(mMax.x, mMax.y, mMax.z), Vector3f(mMin.x, mMax.y, mMax.z));
	gfx.drawLine(Vector3f(mMin.x, mMax.y, mMax.z), Vector3f(mMin.x, mMax.y, mMin.z));

	// Vertical edges
	gfx.drawLine(Vector3f(mMin.x, mMin.y, mMin.z), Vector3f(mMin.x, mMax.y, mMin.z));
	gfx.drawLine(Vector3f(mMax.x, mMin.y, mMin.z), Vector3f(mMax.x, mMax.y, mMin.z));
	gfx.drawLine(Vector3f(mMin.x, mMin.y, mMax.z), Vector3f(mMin.x, mMax.y, mMax.z));
	gfx.drawLine(Vector3f(mMax.x, mMin.y, mMax.z), Vector3f(mMax.x, mMax.y, mMax.z));

	Vector3f triangleVertices[4];
	Vector2f unk2[4];
	gfx.setColour(Colour(gfx.mPrimaryColour.r, gfx.mPrimaryColour.g, gfx.mPrimaryColour.b, 32), true);

	triangleVertices[0].set(mMin.x, mMin.y, mMax.z);
	triangleVertices[1].set(mMin.x, mMax.y, mMax.z);
	triangleVertices[2].set(mMax.x, mMax.y, mMax.z);
	triangleVertices[3].set(mMax.x, mMin.y, mMax.z);
	gfx.drawOneTri(triangleVertices, nullptr, unk2, 4);

	triangleVertices[0].set(mMax.x, mMax.y, mMin.z);
	triangleVertices[1].set(mMax.x, mMin.y, mMin.z);
	triangleVertices[2].set(mMax.x, mMin.y, mMax.z);
	triangleVertices[3].set(mMax.x, mMax.y, mMax.z);
	gfx.drawOneTri(triangleVertices, nullptr, unk2, 4);

	triangleVertices[0].set(mMax.x, mMin.y, mMin.z);
	triangleVertices[1].set(mMax.x, mMax.y, mMin.z);
	triangleVertices[2].set(mMin.x, mMax.y, mMin.z);
	triangleVertices[3].set(mMin.x, mMin.y, mMin.z);
	gfx.drawOneTri(triangleVertices, nullptr, unk2, 4);

	triangleVertices[0].set(mMin.x, mMax.y, mMax.z);
	triangleVertices[1].set(mMin.x, mMin.y, mMax.z);
	triangleVertices[2].set(mMin.x, mMin.y, mMin.z);
	triangleVertices[3].set(mMin.x, mMax.y, mMin.z);
	gfx.drawOneTri(triangleVertices, nullptr, unk2, 4);
}

/*
 * --INFO--
 * Address: 80038F3C
 * Size:    0000E8
 */
bool pointInsideTri(KTri& tri, Vector3f& point)
{
	Vector3f vertex1;
	Vector3f vertex2;
	Vector3f vertex3;

	vertex1 = tri.Origin();
	vertex2 = vertex1 + tri.Edge0();
	vertex3 = vertex1 + tri.Edge1();

	Vector3f edge1 = vertex2 - vertex1;
	Vector3f edge2 = vertex3 - vertex2;
	Vector3f edge3 = vertex1 - vertex3;

	Vector3f toPoint1 = point - vertex1;
	edge1.CP(toPoint1);
	if (edge1.y > 0.0f) {
		return false;
	}

	Vector3f toPoint2 = point - vertex2;
	edge2.CP(toPoint2);
	if (edge2.y > 0.0f) {
		return false;
	}

	Vector3f toPoint3 = point - vertex3;
	edge3.CP(toPoint3);
	if (edge3.y > 0.0f) {
		return false;
	}

	return true;
}

/*
 * --INFO--
 * Address: 80039024
 * Size:    000260
 */
f32 triRectDistance(Vector3f* vertex1, Vector3f* vertex2, Vector3f* vertex3, BoundBox& boundingBox, bool)
{
	// Project triangle vertices onto XZ plane (y=0)
	Vector3f projVertex1 = *vertex1;
	Vector3f projVertex2 = *vertex2;
	Vector3f projVertex3 = *vertex3;
	projVertex1.y = projVertex2.y = projVertex3.y = 0.0f;

	// Create triangle and rectangle objects for intersection tests
	KTri projTriangle;
	KRect projRectangle;
	projTriangle.set(projVertex1, projVertex2, projVertex3);

	// Calculate rectangle corners from bounding box XZ coordinates
	Vector3f botLeft;
	Vector3f topLeft;
	Vector3f botRight;
	Vector3f topRight;

	botLeft   = boundingBox.mMin;
	botLeft.y = 0.0f;

	// Calculate XZ dimensions of rectangle
	Vector3f rectDimensions(boundingBox.mMax.x - boundingBox.mMin.x, 0.0f, boundingBox.mMax.z - boundingBox.mMin.z);

	// Set rectangle corner points
	topLeft  = botLeft + Vector3f(rectDimensions.x, 0.0f, 0.0f);
	botRight = botLeft + Vector3f(0.0f, 0.0f, rectDimensions.z);
	topRight = botLeft + rectDimensions;

	projRectangle.mBotTri.set(botLeft, topLeft, botRight);

	// Check if any triangle vertex is inside rectangle
	if (projRectangle.inside(projVertex1)) {
		return 0.0f;
	}

	if (projRectangle.inside(projVertex2)) {
		return 0.0f;
	}

	if (projRectangle.inside(projVertex3)) {
		return 0.0f;
	}

	// Check if any rectangle corner is inside triangle
	if (pointInsideTri(projTriangle, botLeft)) {
		return 0.0f;
	}

	if (pointInsideTri(projTriangle, topLeft)) {
		return 0.0f;
	}

	if (pointInsideTri(projTriangle, botRight)) {
		return 0.0f;
	}

	if (pointInsideTri(projTriangle, topRight)) {
		return 0.0f;
	}

	// Calculate minimum distance between non-intersecting shapes
	f32 a, b, c, d;
	u32 badCompiler[7];
	return distanceTriRect(projTriangle, projRectangle, &a, &b, &c, &d);
}

/*
 * --INFO--
 * Address: 80039284
 * Size:    0001A8
 */
f32 distanceTriRect(KTri& tri, KRect& rect, f32* barycentricU, f32* barycentricV, f32* p5, f32* p6)
{
	f32 sqrDist = sqrDistance(tri, rect, barycentricU, barycentricV, p5, p6);

	Vector3f closestPoint;
	closestPoint = tri.Origin() + tri.Edge0() * *barycentricU + tri.Edge1() * *barycentricV;

	if (rect.inside(closestPoint)) {
		return 0.0f;
	}

	return std::sqrtf(sqrDist);
}

/*
 * --INFO--
 * Address: 8003942C
 * Size:    000070
 */
bool KRect::inside(Vector3f& point)
{
	Vector3f rectMin = mBotTri.Origin();

	Vector3f rectMax;
	rectMax = (mBotTri.Origin() + mBotTri.Edge0()) + mBotTri.Edge1();

	if (point.x >= rectMin.x && point.x <= rectMax.x && point.z >= rectMin.z && point.z <= rectMax.z) {
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address: 8003949C
 * Size:    00002C
 */
KTri::KTri()
{
}

/*
 * --INFO--
 * Address: 800394C8
 * Size:    0000C4
 */
void KTri::set(Vector3f& pointA, Vector3f& pointB, Vector3f& pointC)
{
	mVertA  = pointA;
	mSideAB = pointB - pointA;
	mSideAC = pointC - pointA;
}

/*
 * --INFO--
 * Address: ........
 * Size:    000020
 */
KSegment::KSegment()
{
	// UNUSED FUNCTION
}

f32 gs_fTolerance = 0.00001f;

/*
 * --INFO--
 * Address: 8003958C
 * Size:    0018C4
 */
f32 sqrDistance(KSegment&, KTri&, f32*, f32*, f32*)
{
	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x6A8(r1)
	  stfd      f31, 0x6A0(r1)
	  stfd      f30, 0x698(r1)
	  stfd      f29, 0x690(r1)
	  stfd      f28, 0x688(r1)
	  stfd      f27, 0x680(r1)
	  stfd      f26, 0x678(r1)
	  stfd      f25, 0x670(r1)
	  stfd      f24, 0x668(r1)
	  stfd      f23, 0x660(r1)
	  stfd      f22, 0x658(r1)
	  stfd      f21, 0x650(r1)
	  stfd      f20, 0x648(r1)
	  stmw      r24, 0x628(r1)
	  addi      r25, r4, 0
	  addi      r24, r3, 0
	  addi      r31, r24, 0xC
	  addi      r30, r25, 0xC
	  addi      r29, r25, 0x18
	  mr        r26, r5
	  mr        r27, r6
	  mr        r28, r7
	  lfs       f3, 0x4(r4)
	  lfs       f2, 0x4(r3)
	  lfs       f28, 0x10(r4)
	  fsubs     f9, f3, f2
	  lfs       f22, 0x10(r3)
	  lfs       f2, 0x1C(r4)
	  fmuls     f26, f28, f28
	  lfs       f29, 0xC(r4)
	  lfs       f3, 0x18(r4)
	  fmuls     f20, f22, f28
	  lfs       f7, 0xC(r3)
	  fmuls     f12, f9, f22
	  lfs       f5, 0x14(r4)
	  fmuls     f21, f7, f29
	  lfs       f1, 0x0(r4)
	  fmuls     f27, f29, f29
	  lfs       f0, 0x0(r3)
	  fmuls     f25, f29, f3
	  fsubs     f10, f1, f0
	  lfs       f11, 0x14(r3)
	  fmuls     f1, f7, f3
	  lfs       f4, 0x20(r4)
	  fmuls     f0, f22, f2
	  fmuls     f13, f10, f7
	  lfs       f8, 0x8(r4)
	  lfs       f6, 0x8(r3)
	  fadds     f21, f21, f20
	  fmuls     f20, f11, f4
	  fsubs     f8, f8, f6
	  fmuls     f6, f22, f22
	  fadds     f0, f1, f0
	  fmuls     f22, f11, f5
	  fmuls     f7, f7, f7
	  fadds     f0, f20, f0
	  fadds     f1, f22, f21
	  fadds     f20, f13, f12
	  fmuls     f21, f8, f11
	  fmuls     f13, f10, f29
	  fmuls     f12, f9, f28
	  fmuls     f24, f28, f2
	  fadds     f28, f7, f6
	  fadds     f21, f21, f20
	  fadds     f6, f27, f26
	  fmuls     f30, f5, f5
	  fadds     f7, f25, f24
	  fmuls     f26, f5, f4
	  fmuls     f23, f3, f3
	  fmuls     f22, f2, f2
	  fmuls     f29, f11, f11
	  fmuls     f20, f8, f5
	  fadds     f12, f13, f12
	  fadds     f5, f29, f28
	  fmuls     f24, f4, f4
	  fadds     f11, f23, f22
	  fneg      f29, f1
	  fneg      f28, f0
	  fadds     f6, f30, f6
	  fadds     f7, f26, f7
	  fadds     f11, f24, f11
	  fneg      f27, f21
	  fadds     f12, f20, f12
	  lfs       f1, -0x7C60(r2)
	  fmuls     f21, f6, f11
	  fmuls     f20, f7, f7
	  stfs      f1, 0x5F0(r1)
	  fmuls     f13, f28, f7
	  fmuls     f0, f29, f11
	  stfs      f1, 0x5EC(r1)
	  fsubs     f31, f21, f20
	  fsubs     f13, f13, f0
	  stfs      f1, 0x5E8(r1)
	  fmuls     f21, f29, f7
	  fmuls     f0, f28, f6
	  stfs      f1, 0x5FC(r1)
	  fmuls     f20, f5, f31
	  fsubs     f30, f21, f0
	  stfs      f1, 0x5F8(r1)
	  fmuls     f0, f29, f13
	  fmuls     f21, f10, f3
	  stfs      f1, 0x5F4(r1)
	  fmuls     f3, f28, f30
	  fadds     f0, f20, f0
	  stfs      f1, 0x5E4(r1)
	  fmuls     f2, f9, f2
	  stfs      f1, 0x5E0(r1)
	  fadds     f20, f3, f0
	  fmuls     f3, f8, f4
	  lfs       f0, -0x7A14(r13)
	  fadds     f2, f21, f2
	  stfs      f1, 0x5DC(r1)
	  fabs      f4, f20
	  fadds     f2, f3, f2
	  fcmpo     cr0, f4, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x161C
	  lfs       f0, -0x7C5C(r2)
	  fneg      f3, f27
	  fneg      f4, f12
	  fdivs     f20, f0, f20
	  fmuls     f3, f3, f20
	  fmuls     f26, f4, f20
	  fneg      f4, f2
	  fmuls     f22, f31, f3
	  fmuls     f21, f13, f26
	  fmuls     f31, f4, f20
	  fmuls     f20, f28, f29
	  fmuls     f4, f5, f7
	  fmuls     f24, f5, f11
	  fmuls     f23, f28, f28
	  fsubs     f4, f20, f4
	  fmuls     f20, f30, f31
	  fadds     f21, f22, f21
	  fsubs     f23, f24, f23
	  fmuls     f24, f5, f6
	  fmuls     f25, f29, f29
	  fadds     f21, f20, f21
	  fmuls     f22, f13, f3
	  fmuls     f23, f23, f26
	  fsubs     f25, f24, f25
	  stfs      f21, 0x5D8(r1)
	  fmuls     f30, f30, f3
	  fmuls     f13, f4, f26
	  lfs       f3, 0x5D8(r1)
	  fmuls     f21, f4, f31
	  fadds     f24, f22, f23
	  fmuls     f26, f25, f31
	  fadds     f4, f30, f13
	  fadds     f13, f21, f24
	  fcmpo     cr0, f3, f1
	  fadds     f4, f26, f4
	  stfs      f13, 0x5D4(r1)
	  stfs      f4, 0x5D0(r1)
	  bge-      .loc_0x8E4
	  lfs       f3, 0x5D4(r1)
	  lfs       f4, 0x5D0(r1)
	  fadds     f2, f3, f4
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x4E4
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x428
	  fcmpo     cr0, f4, f1
	  bge-      .loc_0x398
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D4(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lwz       r7, 0x0(r25)
	  addi      r6, r1, 0x5C8
	  lwz       r0, 0x4(r25)
	  stw       r7, 0x5E8(r1)
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5C4(r1)
	  bge-      .loc_0x358
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)

	.loc_0x358:
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  addi      r5, r1, 0x5C8
	  addi      r6, r1, 0x5C4
	  bl        0x3F88
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x398:
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D4(r1)
	  addi      r4, r25, 0
	  addi      r5, r1, 0x5C8
	  addi      r6, r1, 0x5C4
	  bl        0x3EF8
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x428:
	  fcmpo     cr0, f4, f1
	  bge-      .loc_0x4C0
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D4
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D0(r1)
	  addi      r4, r25, 0
	  addi      r5, r1, 0x5C8
	  addi      r6, r1, 0x5C4
	  bl        0x3E60
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x4C0:
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  addi      r5, r1, 0x5D4
	  addi      r6, r1, 0x5D0
	  bl        0x3E20
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  stfs      f0, 0x5D8(r1)
	  b         .loc_0x184C

	.loc_0x4E4:
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x660
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D4(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x5C4
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x480(r1)
	  lfs       f0, 0x480(r1)
	  stfs      f0, 0x5A4(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5A8(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5AC(r1)
	  lwz       r0, 0x5A4(r1)
	  lwz       r7, 0x5A8(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x5AC(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x46C(r1)
	  lfs       f0, 0x46C(r1)
	  stfs      f0, 0x598(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x59C(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x5A0(r1)
	  lwz       r7, 0x598(r1)
	  lwz       r0, 0x59C(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x5A0(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C5C(r2)
	  fcmpo     cr0, f1, f31
	  lfs       f3, 0x5C4(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x5C8(r1)
	  bge-      .loc_0x620
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)

	.loc_0x620:
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  addi      r5, r1, 0x5C8
	  addi      r6, r1, 0x5C4
	  bl        0x3CC0
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x660:
	  fcmpo     cr0, f4, f1
	  bge-      .loc_0x7DC
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D4
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D0(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x5C4
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x458(r1)
	  lfs       f0, 0x458(r1)
	  stfs      f0, 0x58C(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x590(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x594(r1)
	  lwz       r0, 0x58C(r1)
	  lwz       r7, 0x590(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x594(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x444(r1)
	  lfs       f0, 0x444(r1)
	  stfs      f0, 0x580(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x584(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x588(r1)
	  lwz       r7, 0x580(r1)
	  lwz       r0, 0x584(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x588(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C5C(r2)
	  fcmpo     cr0, f1, f31
	  lfs       f3, 0x5C4(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x5C8(r1)
	  bge-      .loc_0x79C
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)

	.loc_0x79C:
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  addi      r5, r1, 0x5C8
	  addi      r6, r1, 0x5C4
	  bl        0x3B44
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x7DC:
	  lfs       f1, 0x0(r25)
	  mr        r3, r24
	  lfs       f0, 0x0(r30)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x5D0
	  stfs      f0, 0x430(r1)
	  lfs       f0, 0x430(r1)
	  stfs      f0, 0x574(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x578(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x57C(r1)
	  lwz       r0, 0x574(r1)
	  lwz       r7, 0x578(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x57C(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x41C(r1)
	  lfs       f0, 0x41C(r1)
	  stfs      f0, 0x568(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x56C(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x570(r1)
	  lwz       r7, 0x568(r1)
	  lwz       r0, 0x56C(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x570(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f2, -0x7C5C(r2)
	  fmr       f31, f1
	  lfs       f0, 0x5D0(r1)
	  mr        r3, r24
	  addi      r4, r25, 0
	  fsubs     f0, f2, f0
	  addi      r5, r1, 0x5C8
	  addi      r6, r1, 0x5C4
	  stfs      f0, 0x5D4(r1)
	  bl        0x3A3C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x8E4:
	  fcmpo     cr0, f3, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE5C
	  lfs       f4, 0x5D4(r1)
	  lfs       f13, 0x5D0(r1)
	  fadds     f26, f4, f13
	  fcmpo     cr0, f26, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB10
	  fcmpo     cr0, f4, f1
	  bge-      .loc_0xA2C
	  fcmpo     cr0, f13, f1
	  bge-      .loc_0x9D8
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D4(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lwz       r7, 0x0(r25)
	  addi      r6, r1, 0x5C8
	  lwz       r0, 0x4(r25)
	  stw       r7, 0x5E8(r1)
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5C4(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x9D8:
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  stfs      f0, 0x5D4(r1)
	  b         .loc_0x184C

	.loc_0xA2C:
	  fcmpo     cr0, f13, f1
	  bge-      .loc_0xA88
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D4
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0xA88:
	  fmuls     f26, f5, f3
	  lfs       f31, -0x7C58(r2)
	  fmuls     f5, f29, f4
	  fmuls     f1, f29, f3
	  fmuls     f0, f6, f4
	  fmuls     f30, f28, f3
	  fmuls     f29, f7, f4
	  fmuls     f28, f28, f13
	  fadds     f6, f26, f5
	  fmuls     f5, f7, f13
	  fadds     f0, f1, f0
	  fmuls     f26, f11, f13
	  fadds     f11, f30, f29
	  fmuls     f7, f31, f27
	  fadds     f6, f28, f6
	  fmuls     f1, f31, f12
	  fadds     f0, f5, f0
	  fadds     f5, f7, f6
	  fmuls     f6, f31, f2
	  fadds     f2, f26, f11
	  fadds     f0, f1, f0
	  fmuls     f3, f3, f5
	  fadds     f5, f6, f2
	  fmuls     f2, f4, f0
	  fmuls     f1, f10, f10
	  fmuls     f0, f9, f9
	  fmuls     f4, f13, f5
	  fadds     f3, f3, f2
	  fmuls     f2, f8, f8
	  fadds     f0, f1, f0
	  fadds     f1, f4, f3
	  fadds     f0, f2, f0
	  fadds     f31, f1, f0
	  b         .loc_0x184C

	.loc_0xB10:
	  fcmpo     cr0, f4, f1
	  bge-      .loc_0xC50
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D4(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x5C4
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x408(r1)
	  lfs       f0, 0x408(r1)
	  stfs      f0, 0x55C(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x560(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x564(r1)
	  lwz       r0, 0x55C(r1)
	  lwz       r7, 0x560(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x564(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3F4(r1)
	  lfs       f0, 0x3F4(r1)
	  stfs      f0, 0x550(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x554(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x558(r1)
	  lwz       r7, 0x550(r1)
	  lwz       r0, 0x554(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x558(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C5C(r2)
	  fcmpo     cr0, f1, f31
	  lfs       f3, 0x5C4(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x5C8(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0xC50:
	  fcmpo     cr0, f13, f1
	  bge-      .loc_0xD90
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D4
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D0(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x5C4
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x3E0(r1)
	  lfs       f0, 0x3E0(r1)
	  stfs      f0, 0x544(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x548(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x54C(r1)
	  lwz       r0, 0x544(r1)
	  lwz       r7, 0x548(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x54C(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3CC(r1)
	  lfs       f0, 0x3CC(r1)
	  stfs      f0, 0x538(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x53C(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x540(r1)
	  lwz       r7, 0x538(r1)
	  lwz       r0, 0x53C(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x540(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C5C(r2)
	  fcmpo     cr0, f1, f31
	  lfs       f3, 0x5C4(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x5C8(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0xD90:
	  lfs       f1, 0x0(r25)
	  mr        r3, r24
	  lfs       f0, 0x0(r30)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x5D0
	  stfs      f0, 0x3B8(r1)
	  lfs       f0, 0x3B8(r1)
	  stfs      f0, 0x52C(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x530(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x534(r1)
	  lwz       r0, 0x52C(r1)
	  lwz       r7, 0x530(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x534(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x3A4(r1)
	  lfs       f0, 0x3A4(r1)
	  stfs      f0, 0x520(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x524(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x528(r1)
	  lwz       r7, 0x520(r1)
	  lwz       r0, 0x524(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x528(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f2, -0x7C5C(r2)
	  fmr       f31, f1
	  lfs       f0, 0x5D0(r1)
	  fsubs     f0, f2, f0
	  stfs      f0, 0x5D4(r1)
	  b         .loc_0x184C

	.loc_0xE5C:
	  lfs       f3, 0x5D4(r1)
	  lfs       f4, 0x5D0(r1)
	  fadds     f2, f3, f4
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x118C
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x1070
	  fcmpo     cr0, f4, f1
	  bge-      .loc_0xFB0
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D4(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lwz       r7, 0x0(r25)
	  addi      r6, r1, 0x5C8
	  lwz       r0, 0x4(r25)
	  stw       r7, 0x5E8(r1)
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5C4(r1)
	  bge-      .loc_0xF40
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)

	.loc_0xF40:
	  lfs       f1, 0x0(r24)
	  mr        r4, r25
	  lfs       f0, 0xC(r24)
	  addi      r3, r1, 0x5DC
	  lfs       f3, 0x4(r24)
	  lfs       f2, 0x10(r24)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r24)
	  addi      r5, r1, 0x5C8
	  lfs       f1, 0x14(r24)
	  fadds     f2, f3, f2
	  stfs      f0, 0x5DC(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x5C4
	  stfs      f2, 0x5E0(r1)
	  stfs      f0, 0x5E4(r1)
	  bl        0x3370
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0xFB0:
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r4, r25
	  stfs      f0, 0x5D4(r1)
	  addi      r3, r1, 0x5DC
	  addi      r5, r1, 0x5C8
	  lfs       f1, 0x0(r24)
	  addi      r6, r1, 0x5C4
	  lfs       f0, 0x0(r31)
	  lfs       f2, 0x4(r24)
	  fadds     f0, f1, f0
	  lfs       f1, 0x4(r31)
	  lfs       f4, 0x8(r24)
	  lfs       f3, 0x8(r31)
	  fadds     f1, f2, f1
	  stfs      f0, 0x5DC(r1)
	  fadds     f0, f4, f3
	  stfs      f1, 0x5E0(r1)
	  stfs      f0, 0x5E4(r1)
	  bl        0x32B0
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x1070:
	  fcmpo     cr0, f4, f1
	  bge-      .loc_0x1138
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D4
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r4, r25
	  stfs      f0, 0x5D0(r1)
	  addi      r3, r1, 0x5DC
	  addi      r5, r1, 0x5C8
	  lfs       f1, 0x0(r24)
	  addi      r6, r1, 0x5C4
	  lfs       f0, 0x0(r31)
	  lfs       f2, 0x4(r24)
	  fadds     f0, f1, f0
	  lfs       f1, 0x4(r31)
	  lfs       f4, 0x8(r24)
	  lfs       f3, 0x8(r31)
	  fadds     f1, f2, f1
	  stfs      f0, 0x5DC(r1)
	  fadds     f0, f4, f3
	  stfs      f1, 0x5E0(r1)
	  stfs      f0, 0x5E4(r1)
	  bl        0x31E8
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x1138:
	  lfs       f1, 0x0(r24)
	  mr        r4, r25
	  lfs       f0, 0x0(r31)
	  addi      r3, r1, 0x5DC
	  lfs       f3, 0x4(r24)
	  lfs       f2, 0x4(r31)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r24)
	  addi      r5, r1, 0x5D4
	  lfs       f1, 0x8(r31)
	  fadds     f2, f3, f2
	  stfs      f0, 0x5DC(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x5D0
	  stfs      f2, 0x5E0(r1)
	  stfs      f0, 0x5E4(r1)
	  bl        0x3178
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  stfs      f0, 0x5D8(r1)
	  b         .loc_0x184C

	.loc_0x118C:
	  fcmpo     cr0, f3, f1
	  bge-      .loc_0x1338
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D0
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0x18(r25)
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D4(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x5C4
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x360(r1)
	  lfs       f0, 0x360(r1)
	  stfs      f0, 0x514(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x518(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x51C(r1)
	  lwz       r0, 0x514(r1)
	  lwz       r7, 0x518(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x51C(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x34C(r1)
	  lfs       f0, 0x34C(r1)
	  stfs      f0, 0x508(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x50C(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x510(r1)
	  lwz       r7, 0x508(r1)
	  lwz       r0, 0x50C(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x510(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C5C(r2)
	  fcmpo     cr0, f1, f31
	  lfs       f3, 0x5C4(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x5C8(r1)
	  bge-      .loc_0x12C8
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)

	.loc_0x12C8:
	  lfs       f1, 0x0(r24)
	  mr        r4, r25
	  lfs       f0, 0xC(r24)
	  addi      r3, r1, 0x5DC
	  lfs       f3, 0x4(r24)
	  lfs       f2, 0x10(r24)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r24)
	  addi      r5, r1, 0x5C8
	  lfs       f1, 0x14(r24)
	  fadds     f2, f3, f2
	  stfs      f0, 0x5DC(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x5C4
	  stfs      f2, 0x5E0(r1)
	  stfs      f0, 0x5E4(r1)
	  bl        0x2FE8
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x1338:
	  fcmpo     cr0, f4, f1
	  bge-      .loc_0x14E4
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D4
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D0(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x5C4
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x32C(r1)
	  lfs       f0, 0x32C(r1)
	  stfs      f0, 0x4FC(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x500(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x504(r1)
	  lwz       r0, 0x4FC(r1)
	  lwz       r7, 0x500(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x504(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x318(r1)
	  lfs       f0, 0x318(r1)
	  stfs      f0, 0x4F0(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4F4(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4F8(r1)
	  lwz       r7, 0x4F0(r1)
	  lwz       r0, 0x4F4(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x4F8(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C5C(r2)
	  fcmpo     cr0, f1, f31
	  lfs       f3, 0x5C4(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x5C8(r1)
	  bge-      .loc_0x1474
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)

	.loc_0x1474:
	  lfs       f1, 0x0(r24)
	  mr        r4, r25
	  lfs       f0, 0xC(r24)
	  addi      r3, r1, 0x5DC
	  lfs       f3, 0x4(r24)
	  lfs       f2, 0x10(r24)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r24)
	  addi      r5, r1, 0x5C8
	  lfs       f1, 0x14(r24)
	  fadds     f2, f3, f2
	  stfs      f0, 0x5DC(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x5C4
	  stfs      f2, 0x5E0(r1)
	  stfs      f0, 0x5E4(r1)
	  bl        0x2E3C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x14E4:
	  lfs       f1, 0x0(r25)
	  mr        r3, r24
	  lfs       f0, 0x0(r30)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x5D0
	  stfs      f0, 0x2F8(r1)
	  lfs       f0, 0x2F8(r1)
	  stfs      f0, 0x4E4(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4E8(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4EC(r1)
	  lwz       r0, 0x4E4(r1)
	  lwz       r7, 0x4E8(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x4EC(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x0(r29)
	  lfs       f0, 0x0(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2E4(r1)
	  lfs       f0, 0x2E4(r1)
	  stfs      f0, 0x4D8(r1)
	  lfs       f1, 0x4(r29)
	  lfs       f0, 0x4(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4DC(r1)
	  lfs       f1, 0x8(r29)
	  lfs       f0, 0x8(r30)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4E0(r1)
	  lwz       r7, 0x4D8(r1)
	  lwz       r0, 0x4DC(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x4E0(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f2, -0x7C5C(r2)
	  fmr       f31, f1
	  lfs       f0, 0x5D0(r1)
	  addi      r4, r25, 0
	  addi      r3, r1, 0x5DC
	  fsubs     f0, f2, f0
	  addi      r5, r1, 0x5C8
	  addi      r6, r1, 0x5C4
	  stfs      f0, 0x5D4(r1)
	  lfs       f1, 0x0(r24)
	  lfs       f0, 0x0(r31)
	  lfs       f3, 0x4(r24)
	  lfs       f2, 0x4(r31)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r24)
	  lfs       f1, 0x8(r31)
	  fadds     f2, f3, f2
	  stfs      f0, 0x5DC(r1)
	  fadds     f0, f4, f1
	  stfs      f2, 0x5E0(r1)
	  stfs      f0, 0x5E4(r1)
	  bl        0x2D04
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)
	  b         .loc_0x184C

	.loc_0x161C:
	  lwz       r6, 0x0(r25)
	  mr        r3, r24
	  lwz       r0, 0x4(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5D8
	  stw       r6, 0x5E8(r1)
	  addi      r6, r1, 0x5D4
	  stw       r0, 0x5EC(r1)
	  lwz       r0, 0x8(r25)
	  stw       r0, 0x5F0(r1)
	  lwz       r7, 0xC(r25)
	  lwz       r0, 0x10(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x14(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r24
	  stfs      f0, 0x5D0(r1)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  lwz       r7, 0x18(r25)
	  addi      r6, r1, 0x5C4
	  lwz       r0, 0x1C(r25)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x20(r25)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5C8(r1)
	  bge-      .loc_0x16C0
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f3, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)

	.loc_0x16C0:
	  lfs       f1, 0x0(r25)
	  mr        r3, r24
	  lfs       f0, 0xC(r25)
	  addi      r4, r1, 0x5E8
	  addi      r5, r1, 0x5CC
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x5C4
	  stfs      f0, 0x2C4(r1)
	  lfs       f0, 0x2C4(r1)
	  stfs      f0, 0x4CC(r1)
	  lfs       f1, 0x4(r25)
	  lfs       f0, 0x10(r25)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4D0(r1)
	  lfs       f1, 0x8(r25)
	  lfs       f0, 0x14(r25)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4D4(r1)
	  lwz       r0, 0x4CC(r1)
	  lwz       r7, 0x4D0(r1)
	  stw       r0, 0x5E8(r1)
	  lwz       r0, 0x4D4(r1)
	  stw       r7, 0x5EC(r1)
	  stw       r0, 0x5F0(r1)
	  lfs       f1, 0x18(r25)
	  lfs       f0, 0xC(r25)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x2B0(r1)
	  lfs       f0, 0x2B0(r1)
	  stfs      f0, 0x4C0(r1)
	  lfs       f1, 0x1C(r25)
	  lfs       f0, 0x10(r25)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4C4(r1)
	  lfs       f1, 0x20(r25)
	  lfs       f0, 0x14(r25)
	  fsubs     f0, f1, f0
	  stfs      f0, 0x4C8(r1)
	  lwz       r7, 0x4C0(r1)
	  lwz       r0, 0x4C4(r1)
	  stw       r7, 0x5F4(r1)
	  stw       r0, 0x5F8(r1)
	  lwz       r0, 0x4C8(r1)
	  stw       r0, 0x5FC(r1)
	  bl        .loc_0x18C4
	  lfs       f0, -0x7C5C(r2)
	  fcmpo     cr0, f1, f31
	  lfs       f3, 0x5C4(r1)
	  fsubs     f0, f0, f3
	  stfs      f0, 0x5C8(r1)
	  bge-      .loc_0x17A4
	  lfs       f2, 0x5CC(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C8(r1)
	  stfs      f2, 0x5D8(r1)
	  stfs      f0, 0x5D4(r1)
	  stfs      f3, 0x5D0(r1)

	.loc_0x17A4:
	  addi      r3, r24, 0
	  addi      r4, r25, 0
	  addi      r5, r1, 0x5C8
	  addi      r6, r1, 0x5C4
	  bl        0x2B3C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x17E0
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)

	.loc_0x17E0:
	  lfs       f1, 0x0(r24)
	  mr        r4, r25
	  lfs       f0, 0xC(r24)
	  addi      r3, r1, 0x5DC
	  lfs       f3, 0x4(r24)
	  lfs       f2, 0x10(r24)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r24)
	  addi      r5, r1, 0x5C8
	  lfs       f1, 0x14(r24)
	  fadds     f2, f3, f2
	  stfs      f0, 0x5DC(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x5C4
	  stfs      f2, 0x5E0(r1)
	  stfs      f0, 0x5E4(r1)
	  bl        0x2AD0
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x5CC(r1)
	  bge-      .loc_0x184C
	  lfs       f2, 0x5C8(r1)
	  fmr       f31, f1
	  lfs       f0, 0x5C4(r1)
	  stfs      f3, 0x5D8(r1)
	  stfs      f2, 0x5D4(r1)
	  stfs      f0, 0x5D0(r1)

	.loc_0x184C:
	  cmplwi    r26, 0
	  beq-      .loc_0x185C
	  lfs       f0, 0x5D8(r1)
	  stfs      f0, 0x0(r26)

	.loc_0x185C:
	  cmplwi    r27, 0
	  beq-      .loc_0x186C
	  lfs       f0, 0x5D4(r1)
	  stfs      f0, 0x0(r27)

	.loc_0x186C:
	  cmplwi    r28, 0
	  beq-      .loc_0x187C
	  lfs       f0, 0x5D0(r1)
	  stfs      f0, 0x0(r28)

	.loc_0x187C:
	  lmw       r24, 0x628(r1)
	  fabs      f1, f31
	  lwz       r0, 0x6AC(r1)
	  lfd       f31, 0x6A0(r1)
	  lfd       f30, 0x698(r1)
	  lfd       f29, 0x690(r1)
	  lfd       f28, 0x688(r1)
	  lfd       f27, 0x680(r1)
	  lfd       f26, 0x678(r1)
	  lfd       f25, 0x670(r1)
	  lfd       f24, 0x668(r1)
	  lfd       f23, 0x660(r1)
	  lfd       f22, 0x658(r1)
	  lfd       f21, 0x650(r1)
	  lfd       f20, 0x648(r1)
	  addi      r1, r1, 0x6A8
	  mtlr      r0
	  blr

	.loc_0x18C4:
	*/
}

/*
 * --INFO--
 * Address: 8003AE50
 * Size:    000828
 */
f32 sqrDistance(KSegment&, KSegment&, f32*, f32*)
{
	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  stwu      r1, -0xE8(r1)
	  stfd      f31, 0xE0(r1)
	  stfd      f30, 0xD8(r1)
	  stfd      f29, 0xD0(r1)
	  stfd      f28, 0xC8(r1)
	  stfd      f27, 0xC0(r1)
	  stfd      f26, 0xB8(r1)
	  stfd      f25, 0xB0(r1)
	  lfs       f9, 0xC(r3)
	  lfs       f1, 0xC(r4)
	  lfs       f8, 0x10(r3)
	  fmuls     f28, f9, f9
	  lfs       f0, 0x10(r4)
	  fmuls     f4, f9, f1
	  lfs       f10, 0x14(r3)
	  fmuls     f3, f8, f0
	  lfs       f2, 0x14(r4)
	  fmuls     f13, f8, f8
	  fmuls     f7, f1, f1
	  lfs       f26, 0x4(r3)
	  fmuls     f6, f0, f0
	  lfs       f27, 0x4(r4)
	  fadds     f3, f4, f3
	  fmuls     f5, f10, f2
	  lfs       f31, 0x0(r3)
	  fadds     f13, f28, f13
	  lfs       f30, 0x0(r4)
	  fadds     f11, f5, f3
	  fsubs     f5, f31, f30
	  lfs       f25, 0x8(r3)
	  fsubs     f4, f26, f27
	  lfs       f3, 0x8(r4)
	  fmuls     f29, f10, f10
	  fadds     f7, f7, f6
	  lfs       f12, -0x7A14(r13)
	  fmuls     f28, f2, f2
	  fadds     f6, f29, f13
	  fneg      f11, f11
	  fmuls     f29, f5, f9
	  fmuls     f30, f4, f8
	  fadds     f7, f28, f7
	  fsubs     f3, f25, f3
	  fmuls     f13, f11, f11
	  fmuls     f8, f6, f7
	  fmuls     f31, f5, f5
	  fmuls     f9, f4, f4
	  fsubs     f8, f8, f13
	  fmuls     f28, f3, f10
	  fadds     f30, f29, f30
	  fabs      f10, f8
	  fmuls     f13, f3, f3
	  fadds     f9, f31, f9
	  fcmpo     cr0, f10, f12
	  fadds     f8, f28, f30
	  fadds     f9, f13, f9
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x664
	  fmuls     f1, f5, f1
	  lfs       f5, -0x7C60(r2)
	  fmuls     f0, f4, f0
	  fmuls     f4, f3, f2
	  fmuls     f3, f7, f8
	  fadds     f0, f1, f0
	  fmuls     f2, f11, f8
	  fadds     f0, f4, f0
	  fneg      f0, f0
	  fmuls     f4, f11, f0
	  fmuls     f1, f6, f0
	  fsubs     f3, f4, f3
	  fsubs     f1, f2, f1
	  fcmpo     cr0, f3, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4A4
	  fcmpo     cr0, f3, f10
	  cror      2, 0, 0x2
	  bne-      .loc_0x270
	  fcmpo     cr0, f1, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x218
	  fcmpo     cr0, f1, f10
	  cror      2, 0, 0x2
	  bne-      .loc_0x198
	  lfs       f2, -0x7C5C(r2)
	  lfs       f12, -0x7C58(r2)
	  fdivs     f2, f2, f10
	  fmuls     f10, f3, f2
	  fmuls     f1, f1, f2
	  fmuls     f8, f12, f8
	  fmuls     f5, f6, f10
	  fmuls     f4, f11, f1
	  fmuls     f3, f11, f10
	  fmuls     f2, f7, f1
	  fadds     f5, f5, f4
	  fmuls     f4, f12, f0
	  fadds     f0, f3, f2
	  fadds     f2, f8, f5
	  fadds     f0, f4, f0
	  fmuls     f2, f10, f2
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x198:
	  fadds     f4, f11, f8
	  lfs       f1, -0x7C5C(r2)
	  fcmpo     cr0, f4, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1C4
	  lfs       f2, -0x7C58(r2)
	  fmr       f10, f5
	  fmuls     f0, f2, f0
	  fadds     f0, f7, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x1C4:
	  fneg      f2, f4
	  fcmpo     cr0, f2, f6
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x1F4
	  fadds     f3, f6, f7
	  lfs       f2, -0x7C58(r2)
	  fadds     f0, f0, f4
	  fmr       f10, f1
	  fadds     f3, f9, f3
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  b         .loc_0x7E8

	.loc_0x1F4:
	  fdivs     f5, f2, f6
	  lfs       f3, -0x7C58(r2)
	  fmuls     f2, f4, f5
	  fmuls     f3, f3, f0
	  fmr       f10, f5
	  fadds     f0, f7, f2
	  fadds     f0, f3, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x218:
	  fcmpo     cr0, f8, f5
	  fmr       f1, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x234
	  fmr       f10, f5
	  fmr       f0, f9
	  b         .loc_0x7E8

	.loc_0x234:
	  fneg      f0, f8
	  fcmpo     cr0, f0, f6
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x25C
	  lfs       f0, -0x7C58(r2)
	  lfs       f10, -0x7C5C(r2)
	  fmuls     f0, f0, f8
	  fadds     f0, f6, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x25C:
	  fdivs     f2, f0, f6
	  fmuls     f0, f8, f2
	  fmr       f10, f2
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x270:
	  fcmpo     cr0, f1, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3E8
	  fcmpo     cr0, f1, f10
	  cror      2, 0, 0x2
	  bne-      .loc_0x308
	  fadds     f0, f11, f0
	  lfs       f10, -0x7C5C(r2)
	  fcmpo     cr0, f0, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2B4
	  lfs       f0, -0x7C58(r2)
	  fmr       f1, f5
	  fmuls     f0, f0, f8
	  fadds     f0, f6, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x2B4:
	  fneg      f1, f0
	  fcmpo     cr0, f1, f7
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x2E4
	  fadds     f3, f6, f7
	  lfs       f2, -0x7C58(r2)
	  fadds     f0, f8, f0
	  fmr       f1, f10
	  fadds     f3, f9, f3
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  b         .loc_0x7E8

	.loc_0x2E4:
	  fdivs     f3, f1, f7
	  lfs       f1, -0x7C58(r2)
	  fmuls     f0, f0, f3
	  fmuls     f2, f1, f8
	  fmr       f1, f3
	  fadds     f0, f6, f0
	  fadds     f0, f2, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x308:
	  fadds     f4, f11, f8
	  fneg      f2, f4
	  fcmpo     cr0, f2, f6
	  cror      2, 0, 0x2
	  bne-      .loc_0x368
	  fcmpo     cr0, f4, f5
	  lfs       f1, -0x7C5C(r2)
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x344
	  lfs       f2, -0x7C58(r2)
	  fmr       f10, f5
	  fmuls     f0, f2, f0
	  fadds     f0, f7, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x344:
	  fdivs     f5, f2, f6
	  lfs       f3, -0x7C58(r2)
	  fmuls     f2, f4, f5
	  fmuls     f3, f3, f0
	  fmr       f10, f5
	  fadds     f0, f7, f2
	  fadds     f0, f3, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x368:
	  fadds     f0, f11, f0
	  lfs       f10, -0x7C5C(r2)
	  fcmpo     cr0, f0, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x394
	  lfs       f0, -0x7C58(r2)
	  fmr       f1, f5
	  fmuls     f0, f0, f8
	  fadds     f0, f6, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x394:
	  fneg      f1, f0
	  fcmpo     cr0, f1, f7
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x3C4
	  fadds     f3, f6, f7
	  lfs       f2, -0x7C58(r2)
	  fadds     f0, f8, f0
	  fmr       f1, f10
	  fadds     f3, f9, f3
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  b         .loc_0x7E8

	.loc_0x3C4:
	  fdivs     f3, f1, f7
	  lfs       f1, -0x7C58(r2)
	  fmuls     f0, f0, f3
	  fmuls     f2, f1, f8
	  fmr       f1, f3
	  fadds     f0, f6, f0
	  fadds     f0, f2, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x3E8:
	  fneg      f2, f8
	  fcmpo     cr0, f2, f6
	  bge-      .loc_0x424
	  fcmpo     cr0, f8, f5
	  fmr       f1, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x410
	  fmr       f10, f5
	  fmr       f0, f9
	  b         .loc_0x7E8

	.loc_0x410:
	  fdivs     f2, f2, f6
	  fmuls     f0, f8, f2
	  fmr       f10, f2
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x424:
	  fadds     f0, f11, f0
	  lfs       f10, -0x7C5C(r2)
	  fcmpo     cr0, f0, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x450
	  lfs       f0, -0x7C58(r2)
	  fmr       f1, f5
	  fmuls     f0, f0, f8
	  fadds     f0, f6, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x450:
	  fneg      f1, f0
	  fcmpo     cr0, f1, f7
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x480
	  fadds     f3, f6, f7
	  lfs       f2, -0x7C58(r2)
	  fadds     f0, f8, f0
	  fmr       f1, f10
	  fadds     f3, f9, f3
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  b         .loc_0x7E8

	.loc_0x480:
	  fdivs     f3, f1, f7
	  lfs       f1, -0x7C58(r2)
	  fmuls     f0, f0, f3
	  fmuls     f2, f1, f8
	  fmr       f1, f3
	  fadds     f0, f6, f0
	  fadds     f0, f2, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x4A4:
	  fcmpo     cr0, f1, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x5C8
	  fcmpo     cr0, f1, f10
	  cror      2, 0, 0x2
	  bne-      .loc_0x510
	  fcmpo     cr0, f0, f5
	  fmr       f10, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x4D8
	  fmr       f1, f5
	  fmr       f0, f9
	  b         .loc_0x7E8

	.loc_0x4D8:
	  fneg      f1, f0
	  fcmpo     cr0, f1, f7
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x500
	  lfs       f2, -0x7C58(r2)
	  lfs       f1, -0x7C5C(r2)
	  fmuls     f0, f2, f0
	  fadds     f0, f7, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x500:
	  fdivs     f1, f1, f7
	  fmuls     f0, f0, f1
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x510:
	  fadds     f4, f11, f8
	  fcmpo     cr0, f4, f5
	  bge-      .loc_0x574
	  fneg      f2, f4
	  lfs       f1, -0x7C5C(r2)
	  fcmpo     cr0, f2, f6
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x550
	  fadds     f3, f6, f7
	  lfs       f2, -0x7C58(r2)
	  fadds     f0, f0, f4
	  fmr       f10, f1
	  fadds     f3, f9, f3
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  b         .loc_0x7E8

	.loc_0x550:
	  fdivs     f5, f2, f6
	  lfs       f3, -0x7C58(r2)
	  fmuls     f2, f4, f5
	  fmuls     f3, f3, f0
	  fmr       f10, f5
	  fadds     f0, f7, f2
	  fadds     f0, f3, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x574:
	  fcmpo     cr0, f0, f5
	  fmr       f10, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x590
	  fmr       f1, f5
	  fmr       f0, f9
	  b         .loc_0x7E8

	.loc_0x590:
	  fneg      f1, f0
	  fcmpo     cr0, f1, f7
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x5B8
	  lfs       f2, -0x7C58(r2)
	  lfs       f1, -0x7C5C(r2)
	  fmuls     f0, f2, f0
	  fadds     f0, f7, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x5B8:
	  fdivs     f1, f1, f7
	  fmuls     f0, f0, f1
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x5C8:
	  fcmpo     cr0, f8, f5
	  bge-      .loc_0x610
	  fneg      f0, f8
	  fmr       f1, f5
	  fcmpo     cr0, f0, f6
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x5FC
	  lfs       f0, -0x7C58(r2)
	  lfs       f10, -0x7C5C(r2)
	  fmuls     f0, f0, f8
	  fadds     f0, f6, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x5FC:
	  fdivs     f2, f0, f6
	  fmuls     f0, f8, f2
	  fmr       f10, f2
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x610:
	  fcmpo     cr0, f0, f5
	  fmr       f10, f5
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x62C
	  fmr       f1, f5
	  fmr       f0, f9
	  b         .loc_0x7E8

	.loc_0x62C:
	  fneg      f1, f0
	  fcmpo     cr0, f1, f7
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x654
	  lfs       f2, -0x7C58(r2)
	  lfs       f1, -0x7C5C(r2)
	  fmuls     f0, f2, f0
	  fadds     f0, f7, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x654:
	  fdivs     f1, f1, f7
	  fmuls     f0, f0, f1
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x664:
	  lfs       f12, -0x7C60(r2)
	  fcmpo     cr0, f11, f12
	  ble-      .loc_0x738
	  fcmpo     cr0, f8, f12
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x68C
	  fmr       f10, f12
	  fmr       f1, f12
	  fmr       f0, f9
	  b         .loc_0x7E8

	.loc_0x68C:
	  fneg      f10, f8
	  fcmpo     cr0, f10, f6
	  cror      2, 0, 0x2
	  bne-      .loc_0x6B4
	  fdivs     f1, f10, f6
	  fmuls     f0, f8, f1
	  fmr       f10, f1
	  fmr       f1, f12
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x6B4:
	  fadds     f12, f6, f8
	  lfs       f10, -0x7C5C(r2)
	  fmuls     f5, f5, f1
	  fmuls     f1, f4, f0
	  fneg      f0, f12
	  fmuls     f2, f3, f2
	  fadds     f1, f5, f1
	  fcmpo     cr0, f0, f11
	  fadds     f1, f2, f1
	  fneg      f5, f1
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x708
	  fadds     f0, f11, f8
	  lfs       f2, -0x7C58(r2)
	  fadds     f3, f6, f7
	  fmr       f1, f10
	  fadds     f0, f5, f0
	  fadds     f3, f9, f3
	  fmuls     f0, f2, f0
	  fadds     f0, f3, f0
	  b         .loc_0x7E8

	.loc_0x708:
	  fdivs     f1, f0, f11
	  lfs       f4, -0x7C58(r2)
	  fadds     f0, f11, f5
	  fmuls     f3, f4, f8
	  fmuls     f2, f7, f1
	  fmuls     f0, f4, f0
	  fadds     f3, f6, f3
	  fadds     f0, f2, f0
	  fadds     f2, f9, f3
	  fmuls     f0, f1, f0
	  fadds     f0, f2, f0
	  b         .loc_0x7E8

	.loc_0x738:
	  fneg      f13, f8
	  fcmpo     cr0, f13, f6
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x764
	  lfs       f0, -0x7C58(r2)
	  fmr       f1, f12
	  lfs       f10, -0x7C5C(r2)
	  fmuls     f0, f0, f8
	  fadds     f0, f6, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x764:
	  fcmpo     cr0, f8, f12
	  cror      2, 0, 0x2
	  bne-      .loc_0x788
	  fdivs     f1, f13, f6
	  fmuls     f0, f8, f1
	  fmr       f10, f1
	  fmr       f1, f12
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x788:
	  fmuls     f5, f5, f1
	  fmuls     f1, f4, f0
	  fneg      f0, f11
	  fmuls     f2, f3, f2
	  fadds     f1, f5, f1
	  fcmpo     cr0, f8, f0
	  fmr       f10, f12
	  fadds     f0, f2, f1
	  fneg      f2, f0
	  cror      2, 0x1, 0x2
	  bne-      .loc_0x7CC
	  lfs       f0, -0x7C58(r2)
	  lfs       f1, -0x7C5C(r2)
	  fmuls     f0, f0, f2
	  fadds     f0, f7, f0
	  fadds     f0, f9, f0
	  b         .loc_0x7E8

	.loc_0x7CC:
	  fdivs     f1, f13, f11
	  lfs       f0, -0x7C58(r2)
	  fmuls     f2, f0, f2
	  fmuls     f0, f7, f1
	  fadds     f0, f2, f0
	  fmuls     f0, f1, f0
	  fadds     f0, f9, f0

	.loc_0x7E8:
	  cmplwi    r5, 0
	  beq-      .loc_0x7F4
	  stfs      f10, 0x0(r5)

	.loc_0x7F4:
	  cmplwi    r6, 0
	  beq-      .loc_0x800
	  stfs      f1, 0x0(r6)

	.loc_0x800:
	  fabs      f1, f0
	  lfd       f31, 0xE0(r1)
	  lfd       f30, 0xD8(r1)
	  lfd       f29, 0xD0(r1)
	  lfd       f28, 0xC8(r1)
	  lfd       f27, 0xC0(r1)
	  lfd       f26, 0xB8(r1)
	  lfd       f25, 0xB0(r1)
	  addi      r1, r1, 0xE8
	  blr
	*/
}

/*
 * --INFO--
 * Address: 8003B678
 * Size:    001D9C
 */
f32 sqrDistance(KSegment& segment, KRect& rect, f32* p3, f32* p4, f32* p5)
{

	FORCE_DONT_INLINE;
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x720(r1)
	  stfd      f31, 0x718(r1)
	  stfd      f30, 0x710(r1)
	  stfd      f29, 0x708(r1)
	  stfd      f28, 0x700(r1)
	  stfd      f27, 0x6F8(r1)
	  stfd      f26, 0x6F0(r1)
	  stfd      f25, 0x6E8(r1)
	  stfd      f24, 0x6E0(r1)
	  stfd      f23, 0x6D8(r1)
	  stfd      f22, 0x6D0(r1)
	  stfd      f21, 0x6C8(r1)
	  stmw      r25, 0x6AC(r1)
	  lfs       f31, 0xC(r3)
	  mr        r26, r4
	  lfs       f5, 0xC(r4)
	  mr        r25, r3
	  lfs       f2, 0x18(r4)
	  lfs       f13, 0x10(r3)
	  fmuls     f12, f31, f5
	  lfs       f4, 0x10(r4)
	  fmuls     f10, f31, f2
	  lfs       f0, 0x1C(r4)
	  fmuls     f11, f13, f4
	  fmuls     f9, f13, f0
	  lfs       f30, 0x14(r3)
	  lfs       f6, 0x14(r4)
	  fmuls     f8, f31, f31
	  lfs       f3, 0x20(r4)
	  fadds     f12, f12, f11
	  lfs       f25, 0x4(r4)
	  fmuls     f21, f30, f6
	  lfs       f24, 0x4(r3)
	  fadds     f9, f10, f9
	  fadds     f21, f21, f12
	  lfs       f23, 0x0(r4)
	  fmuls     f11, f30, f3
	  lfs       f22, 0x0(r3)
	  fmuls     f7, f13, f13
	  fadds     f12, f11, f9
	  lfs       f28, 0x8(r4)
	  fsubs     f11, f23, f22
	  lfs       f27, 0x8(r3)
	  fsubs     f10, f25, f24
	  fsubs     f9, f28, f27
	  lfs       f1, -0x7C60(r2)
	  fneg      f26, f21
	  addi      r31, r25, 0xC
	  fneg      f25, f12
	  fmuls     f23, f5, f5
	  stfs      f1, 0x678(r1)
	  fmuls     f21, f4, f4
	  addi      r8, r26, 0xC
	  fmuls     f22, f2, f2
	  fmuls     f12, f0, f0
	  stfs      f1, 0x674(r1)
	  fmuls     f27, f6, f6
	  addi      r30, r26, 0x18
	  fadds     f24, f23, f21
	  fmuls     f23, f3, f3
	  stfs      f1, 0x670(r1)
	  fadds     f12, f22, f12
	  mr        r27, r5
	  fadds     f7, f8, f7
	  fmuls     f28, f30, f30
	  stfs      f1, 0x684(r1)
	  fadds     f12, f23, f12
	  mr        r28, r6
	  fneg      f23, f26
	  stfs      f1, 0x680(r1)
	  fadds     f8, f27, f24
	  fneg      f22, f25
	  mr        r29, r7
	  fadds     f7, f28, f7
	  stfs      f1, 0x67C(r1)
	  fmuls     f27, f22, f8
	  fmuls     f29, f23, f12
	  stfs      f1, 0x66C(r1)
	  fmuls     f28, f8, f12
	  stfs      f1, 0x668(r1)
	  fmuls     f22, f26, f29
	  fmuls     f23, f7, f28
	  lfs       f21, -0x7A14(r13)
	  fmuls     f24, f25, f27
	  stfs      f1, 0x664(r1)
	  fadds     f22, f23, f22
	  fmuls     f23, f9, f30
	  fmuls     f31, f11, f31
	  fmuls     f13, f10, f13
	  fadds     f30, f24, f22
	  fmuls     f5, f11, f5
	  fadds     f13, f31, f13
	  fmuls     f4, f10, f4
	  fabs      f22, f30
	  fadds     f13, f23, f13
	  fmuls     f2, f11, f2
	  fmuls     f0, f10, f0
	  fcmpo     cr0, f22, f21
	  fmuls     f6, f9, f6
	  fadds     f4, f5, f4
	  fadds     f0, f2, f0
	  fmuls     f3, f9, f3
	  fneg      f13, f13
	  cror      2, 0x1, 0x2
	  fadds     f2, f6, f4
	  fadds     f3, f3, f0
	  bne-      .loc_0x1A94
	  lfs       f0, -0x7C5C(r2)
	  fneg      f4, f13
	  fneg      f5, f2
	  fdivs     f21, f0, f30
	  fmuls     f4, f4, f21
	  fmuls     f6, f5, f21
	  fneg      f5, f3
	  fmuls     f23, f28, f4
	  fmuls     f22, f29, f6
	  fmuls     f28, f5, f21
	  fmuls     f30, f7, f12
	  fmuls     f5, f25, f26
	  fmuls     f24, f25, f25
	  fmuls     f21, f27, f28
	  fadds     f22, f23, f22
	  fsubs     f24, f30, f24
	  fmuls     f31, f7, f8
	  fmuls     f30, f26, f26
	  fadds     f22, f21, f22
	  fmuls     f23, f29, f4
	  fmuls     f24, f24, f6
	  fsubs     f29, f31, f30
	  stfs      f22, 0x660(r1)
	  fmuls     f27, f27, f4
	  fmuls     f6, f5, f6
	  lfs       f4, 0x660(r1)
	  fmuls     f31, f5, f28
	  fadds     f30, f23, f24
	  fmuls     f28, f29, f28
	  fadds     f5, f27, f6
	  fadds     f6, f31, f30
	  fcmpo     cr0, f4, f1
	  fadds     f5, f28, f5
	  stfs      f6, 0x65C(r1)
	  stfs      f5, 0x658(r1)
	  bge-      .loc_0xA48
	  lfs       f2, 0x65C(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x528
	  lfs       f2, 0x658(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x358
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xAC4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lwz       r7, 0x0(r26)
	  addi      r6, r1, 0x650
	  lwz       r0, 0x4(r26)
	  stw       r7, 0x670(r1)
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xB14
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x318
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0x318:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x1EDC
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x358:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x3F4
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xBCC
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x1E40
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x3F4:
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xC5C
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lfs       f1, 0x0(r26)
	  addi      r6, r1, 0x650
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x514(r1)
	  lfs       f0, 0x514(r1)
	  stfs      f0, 0x62C(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x630(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x634(r1)
	  lwz       r0, 0x62C(r1)
	  lwz       r7, 0x630(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x634(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xCE4
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x4E8
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0x4E8:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x1D0C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x528:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x6C8
	  lfs       f2, 0x658(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x5D0
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x65C
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xDA8
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x658(r1)
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x1C64
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x5D0:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x600
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r1, 0x65C
	  addi      r6, r1, 0x658
	  bl        0x1C18
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  stfs      f0, 0x660(r1)
	  b         .loc_0x1D28

	.loc_0x600:
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r30)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x65C
	  stfs      f0, 0x500(r1)
	  lfs       f0, 0x500(r1)
	  stfs      f0, 0x620(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x624(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x628(r1)
	  lwz       r0, 0x620(r1)
	  lwz       r7, 0x624(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x628(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xEA0
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x658(r1)
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x1B6C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x6C8:
	  lfs       f2, 0x658(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x808
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x4EC(r1)
	  lfs       f0, 0x4EC(r1)
	  stfs      f0, 0x614(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x618(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x61C(r1)
	  lwz       r0, 0x614(r1)
	  lwz       r7, 0x618(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x61C(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xF74
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lwz       r7, 0x0(r26)
	  addi      r6, r1, 0x650
	  lwz       r0, 0x4(r26)
	  stw       r7, 0x670(r1)
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0xFC4
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x7C8
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0x7C8:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x1A2C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x808:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x8DC
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x4D8(r1)
	  lfs       f0, 0x4D8(r1)
	  stfs      f0, 0x608(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x60C(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x610(r1)
	  lwz       r0, 0x608(r1)
	  lwz       r7, 0x60C(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x610(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x10B4
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x1958
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x8DC:
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x4C4(r1)
	  lfs       f0, 0x4C4(r1)
	  stfs      f0, 0x5FC(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x600(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x604(r1)
	  lwz       r0, 0x5FC(r1)
	  lwz       r7, 0x600(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x604(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x117C
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lfs       f1, 0x0(r26)
	  addi      r6, r1, 0x650
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x4B0(r1)
	  lfs       f0, 0x4B0(r1)
	  stfs      f0, 0x5F0(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5F4(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5F8(r1)
	  lwz       r0, 0x5F0(r1)
	  lwz       r7, 0x5F4(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x5F8(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1204
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0xA08
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0xA08:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x17EC
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0xA48:
	  fcmpo     cr0, f4, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x10CC
	  lfs       f5, 0x65C(r1)
	  fcmpo     cr0, f5, f1
	  bge-      .loc_0xC84
	  lfs       f2, 0x658(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0xB2C
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x12D4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lwz       r7, 0x0(r26)
	  addi      r6, r1, 0x650
	  lwz       r0, 0x4(r26)
	  stw       r7, 0x670(r1)
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1324
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0xB2C:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xB8C
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x13A0
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  stfs      f0, 0x65C(r1)
	  b         .loc_0x1D28

	.loc_0xB8C:
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x13F4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lfs       f1, 0x0(r26)
	  addi      r6, r1, 0x650
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x49C(r1)
	  lfs       f0, 0x49C(r1)
	  stfs      f0, 0x5E4(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5E8(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5EC(r1)
	  lwz       r0, 0x5E4(r1)
	  lwz       r7, 0x5E8(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x5EC(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x147C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0xC84:
	  fcmpo     cr0, f5, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xE00
	  lfs       f6, 0x658(r1)
	  fcmpo     cr0, f6, f1
	  bge-      .loc_0xCF0
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x65C
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1504
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0xCF0:
	  fcmpo     cr0, f6, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xD74
	  fmuls     f7, f7, f4
	  lfs       f28, -0x7C58(r2)
	  fmuls     f0, f26, f5
	  fmuls     f27, f25, f6
	  fmuls     f1, f26, f4
	  fadds     f7, f7, f0
	  fmuls     f0, f8, f5
	  fmuls     f25, f25, f4
	  fmuls     f12, f12, f6
	  fmuls     f8, f28, f13
	  fadds     f7, f27, f7
	  fmuls     f2, f28, f2
	  fadds     f0, f1, f0
	  fadds     f1, f8, f7
	  fmuls     f8, f28, f3
	  fadds     f7, f25, f12
	  fadds     f0, f2, f0
	  fmuls     f3, f4, f1
	  fadds     f4, f8, f7
	  fmuls     f2, f5, f0
	  fmuls     f1, f11, f11
	  fmuls     f0, f10, f10
	  fmuls     f4, f6, f4
	  fadds     f3, f3, f2
	  fmuls     f2, f9, f9
	  fadds     f0, f1, f0
	  fadds     f1, f4, f3
	  fadds     f0, f2, f0
	  fadds     f31, f1, f0
	  b         .loc_0x1D28

	.loc_0xD74:
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r30)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x65C
	  stfs      f0, 0x488(r1)
	  lfs       f0, 0x488(r1)
	  stfs      f0, 0x5D8(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5DC(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5E0(r1)
	  lwz       r0, 0x5D8(r1)
	  lwz       r7, 0x5DC(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x5E0(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1614
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0xE00:
	  lfs       f2, 0x658(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0xF04
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x474(r1)
	  lfs       f0, 0x474(r1)
	  stfs      f0, 0x5CC(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5D0(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5D4(r1)
	  lwz       r0, 0x5CC(r1)
	  lwz       r7, 0x5D0(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x5D4(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x16AC
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lwz       r7, 0x0(r26)
	  addi      r6, r1, 0x650
	  lwz       r0, 0x4(r26)
	  stw       r7, 0x670(r1)
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x16FC
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0xF04:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0xF9C
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x460(r1)
	  lfs       f0, 0x460(r1)
	  stfs      f0, 0x5C0(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C4(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5C8(r1)
	  lwz       r0, 0x5C0(r1)
	  lwz       r7, 0x5C4(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x5C8(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x17B0
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  stfs      f0, 0x65C(r1)
	  b         .loc_0x1D28

	.loc_0xF9C:
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x44C(r1)
	  lfs       f0, 0x44C(r1)
	  stfs      f0, 0x5B4(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5B8(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5BC(r1)
	  lwz       r0, 0x5B4(r1)
	  lwz       r7, 0x5B8(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x5BC(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x183C
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lfs       f1, 0x0(r26)
	  addi      r6, r1, 0x650
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x438(r1)
	  lfs       f0, 0x438(r1)
	  stfs      f0, 0x5A8(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5AC(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5B0(r1)
	  lwz       r0, 0x5A8(r1)
	  lwz       r7, 0x5AC(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x5B0(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x18C4
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x10CC:
	  lfs       f2, 0x65C(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x1454
	  lfs       f2, 0x658(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x1210
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x194C
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lwz       r7, 0x0(r26)
	  addi      r6, r1, 0x650
	  lwz       r0, 0x4(r26)
	  stw       r7, 0x670(r1)
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x199C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x11A0
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0x11A0:
	  lfs       f1, 0x0(r25)
	  mr        r4, r26
	  lfs       f0, 0xC(r25)
	  addi      r3, r1, 0x664
	  lfs       f3, 0x4(r25)
	  lfs       f2, 0x10(r25)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r25)
	  addi      r5, r1, 0x650
	  lfs       f1, 0x14(r25)
	  fadds     f2, f3, f2
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x64C
	  stfs      f2, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0x1024
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x1210:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x12F0
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1A84
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0xF88
	  lfs       f1, 0x0(r25)
	  mr        r4, r26
	  lfs       f0, 0x0(r31)
	  addi      r3, r1, 0x664
	  lfs       f3, 0x4(r25)
	  lfs       f2, 0x4(r31)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r25)
	  addi      r5, r1, 0x650
	  lfs       f1, 0x8(r31)
	  fadds     f2, f3, f2
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x64C
	  stfs      f2, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0xF44
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x12F0:
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x658
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1B58
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lfs       f1, 0x0(r26)
	  addi      r6, r1, 0x650
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x40C(r1)
	  lfs       f0, 0x40C(r1)
	  stfs      f0, 0x59C(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5A0(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x5A4(r1)
	  lwz       r0, 0x59C(r1)
	  lwz       r7, 0x5A0(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x5A4(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1BE0
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x13E4
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0x13E4:
	  lfs       f1, 0x0(r25)
	  mr        r4, r26
	  lfs       f0, 0xC(r25)
	  addi      r3, r1, 0x664
	  lfs       f3, 0x4(r25)
	  lfs       f2, 0x10(r25)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r25)
	  addi      r5, r1, 0x650
	  lfs       f1, 0x14(r25)
	  fadds     f2, f3, f2
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x64C
	  stfs      f2, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0xDE0
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x1454:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x1684
	  lfs       f2, 0x658(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x152C
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x65C
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1CD4
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r4, r26
	  stfs      f0, 0x658(r1)
	  addi      r3, r1, 0x664
	  addi      r5, r1, 0x650
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x64C
	  lfs       f0, 0x0(r31)
	  lfs       f2, 0x4(r25)
	  fadds     f0, f1, f0
	  lfs       f1, 0x4(r31)
	  lfs       f4, 0x8(r25)
	  lfs       f3, 0x8(r31)
	  fadds     f1, f2, f1
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f3
	  stfs      f1, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0xD08
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x152C:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x158C
	  lfs       f1, 0x0(r25)
	  mr        r4, r26
	  lfs       f0, 0x0(r31)
	  addi      r3, r1, 0x664
	  lfs       f3, 0x4(r25)
	  lfs       f2, 0x4(r31)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r25)
	  addi      r5, r1, 0x65C
	  lfs       f1, 0x8(r31)
	  fadds     f2, f3, f2
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x658
	  stfs      f2, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0xC8C
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  stfs      f0, 0x660(r1)
	  b         .loc_0x1D28

	.loc_0x158C:
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r30)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x65C
	  stfs      f0, 0x3D4(r1)
	  lfs       f0, 0x3D4(r1)
	  stfs      f0, 0x590(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x594(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x598(r1)
	  lwz       r0, 0x590(r1)
	  lwz       r7, 0x594(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x598(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1E2C
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r4, r26
	  stfs      f0, 0x658(r1)
	  addi      r3, r1, 0x664
	  addi      r5, r1, 0x650
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x64C
	  lfs       f0, 0x0(r31)
	  lfs       f2, 0x4(r25)
	  fadds     f0, f1, f0
	  lfs       f1, 0x4(r31)
	  lfs       f4, 0x8(r25)
	  lfs       f3, 0x8(r31)
	  fadds     f1, f2, f1
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f3
	  stfs      f1, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0xBB0
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x1684:
	  lfs       f2, 0x658(r1)
	  fcmpo     cr0, f2, f1
	  bge-      .loc_0x17F4
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x3B4(r1)
	  lfs       f0, 0x3B4(r1)
	  stfs      f0, 0x584(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x588(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x58C(r1)
	  lwz       r0, 0x584(r1)
	  lwz       r7, 0x588(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x58C(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1F30
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lwz       r7, 0x0(r26)
	  addi      r6, r1, 0x650
	  lwz       r0, 0x4(r26)
	  stw       r7, 0x670(r1)
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x1F80
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x1784
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0x1784:
	  lfs       f1, 0x0(r25)
	  mr        r4, r26
	  lfs       f0, 0xC(r25)
	  addi      r3, r1, 0x664
	  lfs       f3, 0x4(r25)
	  lfs       f2, 0x10(r25)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r25)
	  addi      r5, r1, 0x650
	  lfs       f1, 0x14(r25)
	  fadds     f2, f3, f2
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x64C
	  stfs      f2, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0xA40
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x17F4:
	  fcmpo     cr0, f2, f0
	  cror      2, 0, 0x2
	  bne-      .loc_0x18F8
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x394(r1)
	  lfs       f0, 0x394(r1)
	  stfs      f0, 0x578(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x57C(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x580(r1)
	  lwz       r0, 0x578(r1)
	  lwz       r7, 0x57C(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x580(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x20A0
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r4, r26
	  stfs      f0, 0x65C(r1)
	  addi      r3, r1, 0x664
	  addi      r5, r1, 0x650
	  lfs       f1, 0x0(r25)
	  addi      r6, r1, 0x64C
	  lfs       f0, 0x0(r31)
	  lfs       f2, 0x4(r25)
	  fadds     f0, f1, f0
	  lfs       f1, 0x4(r31)
	  lfs       f4, 0x8(r25)
	  lfs       f3, 0x8(r31)
	  fadds     f1, f2, f1
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f3
	  stfs      f1, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0x93C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x18F8:
	  lfs       f1, 0x0(r26)
	  mr        r3, r25
	  lfs       f0, 0x0(r8)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x658
	  stfs      f0, 0x374(r1)
	  lfs       f0, 0x374(r1)
	  stfs      f0, 0x56C(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x570(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r8)
	  fadds     f0, f1, f0
	  stfs      f0, 0x574(r1)
	  lwz       r0, 0x56C(r1)
	  lwz       r7, 0x570(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x574(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x2198
	  lfs       f0, -0x7C5C(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x65C(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lfs       f1, 0x0(r26)
	  addi      r6, r1, 0x650
	  lfs       f0, 0x0(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x360(r1)
	  lfs       f0, 0x360(r1)
	  stfs      f0, 0x560(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x4(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x564(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x8(r30)
	  fadds     f0, f1, f0
	  stfs      f0, 0x568(r1)
	  lwz       r0, 0x560(r1)
	  lwz       r7, 0x564(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x568(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x2220
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x1A24
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0x1A24:
	  lfs       f1, 0x0(r25)
	  mr        r4, r26
	  lfs       f0, 0xC(r25)
	  addi      r3, r1, 0x664
	  lfs       f3, 0x4(r25)
	  lfs       f2, 0x10(r25)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r25)
	  addi      r5, r1, 0x650
	  lfs       f1, 0x14(r25)
	  fadds     f2, f3, f2
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x64C
	  stfs      f2, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0x7A0
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)
	  b         .loc_0x1D28

	.loc_0x1A94:
	  lwz       r6, 0x0(r26)
	  mr        r3, r25
	  lwz       r0, 0x4(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x660
	  stw       r6, 0x670(r1)
	  addi      r6, r1, 0x65C
	  stw       r0, 0x674(r1)
	  lwz       r0, 0x8(r26)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x22FC
	  lfs       f0, -0x7C60(r2)
	  fmr       f31, f1
	  mr        r3, r25
	  stfs      f0, 0x658(r1)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  lwz       r7, 0x18(r26)
	  addi      r6, r1, 0x64C
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x2334
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x650(r1)
	  bge-      .loc_0x1B38
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f3, 0x65C(r1)
	  stfs      f0, 0x658(r1)

	.loc_0x1B38:
	  lfs       f1, 0x0(r26)
	  addi      r3, r25, 0
	  lfs       f0, 0x18(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x650
	  stfs      f0, 0x340(r1)
	  lfs       f0, 0x340(r1)
	  stfs      f0, 0x554(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x1C(r26)
	  fadds     f0, f1, f0
	  stfs      f0, 0x558(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x20(r26)
	  fadds     f0, f1, f0
	  stfs      f0, 0x55C(r1)
	  lwz       r0, 0x554(r1)
	  lwz       r7, 0x558(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x55C(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0xC(r26)
	  lwz       r0, 0x10(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x14(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x23D8
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x64C(r1)
	  bge-      .loc_0x1BDC
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x650(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f0, 0x65C(r1)
	  stfs      f3, 0x658(r1)

	.loc_0x1BDC:
	  lfs       f1, 0x0(r26)
	  addi      r3, r25, 0
	  lfs       f0, 0xC(r26)
	  addi      r4, r1, 0x670
	  addi      r5, r1, 0x654
	  fadds     f0, f1, f0
	  addi      r6, r1, 0x64C
	  stfs      f0, 0x32C(r1)
	  lfs       f0, 0x32C(r1)
	  stfs      f0, 0x548(r1)
	  lfs       f1, 0x4(r26)
	  lfs       f0, 0x10(r26)
	  fadds     f0, f1, f0
	  stfs      f0, 0x54C(r1)
	  lfs       f1, 0x8(r26)
	  lfs       f0, 0x14(r26)
	  fadds     f0, f1, f0
	  stfs      f0, 0x550(r1)
	  lwz       r0, 0x548(r1)
	  lwz       r7, 0x54C(r1)
	  stw       r0, 0x670(r1)
	  lwz       r0, 0x550(r1)
	  stw       r7, 0x674(r1)
	  stw       r0, 0x678(r1)
	  lwz       r7, 0x18(r26)
	  lwz       r0, 0x1C(r26)
	  stw       r7, 0x67C(r1)
	  stw       r0, 0x680(r1)
	  lwz       r0, 0x20(r26)
	  stw       r0, 0x684(r1)
	  bl        -0x247C
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x650(r1)
	  bge-      .loc_0x1C80
	  lfs       f2, 0x654(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f2, 0x660(r1)
	  stfs      f3, 0x65C(r1)
	  stfs      f0, 0x658(r1)

	.loc_0x1C80:
	  addi      r3, r25, 0
	  addi      r4, r26, 0
	  addi      r5, r1, 0x650
	  addi      r6, r1, 0x64C
	  bl        0x574
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C60(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1CBC
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)

	.loc_0x1CBC:
	  lfs       f1, 0x0(r25)
	  mr        r4, r26
	  lfs       f0, 0xC(r25)
	  addi      r3, r1, 0x664
	  lfs       f3, 0x4(r25)
	  lfs       f2, 0x10(r25)
	  fadds     f0, f1, f0
	  lfs       f4, 0x8(r25)
	  addi      r5, r1, 0x650
	  lfs       f1, 0x14(r25)
	  fadds     f2, f3, f2
	  stfs      f0, 0x664(r1)
	  fadds     f0, f4, f1
	  addi      r6, r1, 0x64C
	  stfs      f2, 0x668(r1)
	  stfs      f0, 0x66C(r1)
	  bl        0x508
	  fcmpo     cr0, f1, f31
	  lfs       f3, -0x7C5C(r2)
	  stfs      f3, 0x654(r1)
	  bge-      .loc_0x1D28
	  lfs       f2, 0x650(r1)
	  fmr       f31, f1
	  lfs       f0, 0x64C(r1)
	  stfs      f3, 0x660(r1)
	  stfs      f2, 0x65C(r1)
	  stfs      f0, 0x658(r1)

	.loc_0x1D28:
	  cmplwi    r27, 0
	  beq-      .loc_0x1D38
	  lfs       f0, 0x660(r1)
	  stfs      f0, 0x0(r27)

	.loc_0x1D38:
	  cmplwi    r28, 0
	  beq-      .loc_0x1D48
	  lfs       f0, 0x65C(r1)
	  stfs      f0, 0x0(r28)

	.loc_0x1D48:
	  cmplwi    r29, 0
	  beq-      .loc_0x1D58
	  lfs       f0, 0x658(r1)
	  stfs      f0, 0x0(r29)

	.loc_0x1D58:
	  lmw       r25, 0x6AC(r1)
	  fabs      f1, f31
	  lwz       r0, 0x724(r1)
	  lfd       f31, 0x718(r1)
	  lfd       f30, 0x710(r1)
	  lfd       f29, 0x708(r1)
	  lfd       f28, 0x700(r1)
	  lfd       f27, 0x6F8(r1)
	  lfd       f26, 0x6F0(r1)
	  lfd       f25, 0x6E8(r1)
	  lfd       f24, 0x6E0(r1)
	  lfd       f23, 0x6D8(r1)
	  lfd       f22, 0x6D0(r1)
	  lfd       f21, 0x6C8(r1)
	  addi      r1, r1, 0x720
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address: 8003D414
 * Size:    000468
 */
f32 sqrDistance(KTri& tri, KRect& rect, f32* p3, f32* p4, f32* p5, f32* p6)
{
	f32 tmpP3, tmpP4, tmpP32, tmpP42;
	f32 tmpP5, tmpP6, tmpP52, tmpP62;

	KSegment segment;
	segment.Origin()    = tri.Origin();
	segment.Direction() = tri.Edge0();

	f32 sqrDist = sqrDistance(segment, rect, &tmpP3, &tmpP5, &tmpP6);
	tmpP4       = 0.0f;

	segment.Direction() = tri.Edge1();
	f32 tmpDist         = sqrDistance(segment, rect, &tmpP42, &tmpP52, &tmpP62);
	tmpP32              = 0.0f;

	if (tmpDist < sqrDist) {
		sqrDist = tmpDist;
		tmpP3   = tmpP32;
		tmpP4   = tmpP42;
		tmpP5   = tmpP52;
		tmpP6   = tmpP62;
	}

	segment.Origin()    = segment.Origin() + tri.Edge0();
	segment.Direction() = segment.Direction() - tri.Edge0();
	tmpDist             = sqrDistance(segment, rect, &tmpP42, &tmpP52, &tmpP62);
	tmpP32              = 1.0f - tmpP42;

	if (tmpDist < sqrDist) {
		sqrDist = tmpDist;
		tmpP3   = tmpP32;
		tmpP4   = tmpP42;
		tmpP5   = tmpP52;
		tmpP6   = tmpP62;
	}

	segment.Origin()    = rect.mBotTri.Origin();
	segment.Direction() = rect.mBotTri.Edge0();
	tmpDist             = sqrDistance(segment, tri, &tmpP52, &tmpP32, &tmpP42);
	tmpP62              = 0.0f;

	if (tmpDist < sqrDist) {
		sqrDist = tmpDist;
		tmpP3   = tmpP32;
		tmpP4   = tmpP42;
		tmpP5   = tmpP52;
		tmpP6   = tmpP62;
	}

	segment.Direction() = rect.mBotTri.Edge1();
	tmpDist             = sqrDistance(segment, tri, &tmpP62, &tmpP32, &tmpP42);
	tmpP52              = 0.0f;

	if (tmpDist < sqrDist) {
		sqrDist = tmpDist;
		tmpP3   = tmpP32;
		tmpP4   = tmpP42;
		tmpP5   = tmpP52;
		tmpP6   = tmpP62;
	}

	segment.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
	segment.Direction() = rect.mBotTri.Edge0();
	tmpDist             = sqrDistance(segment, tri, &tmpP52, &tmpP32, &tmpP42);
	tmpP62              = 1.0f;

	if (tmpDist < sqrDist) {
		sqrDist = tmpDist;
		tmpP3   = tmpP32;
		tmpP4   = tmpP42;
		tmpP5   = tmpP52;
		tmpP6   = tmpP62;
	}

	segment.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
	segment.Direction() = rect.mBotTri.Edge1();
	tmpDist             = sqrDistance(segment, tri, &tmpP62, &tmpP32, &tmpP42);
	tmpP52              = 1.0f;

	if (tmpDist < sqrDist) {
		sqrDist = tmpDist;
		tmpP3   = tmpP32;
		tmpP4   = tmpP42;
		tmpP5   = tmpP52;
		tmpP6   = tmpP62;
	}

	if (p3) {
		*p3 = tmpP3;
	}
	if (p4) {
		*p4 = tmpP4;
	}
	if (p5) {
		*p5 = tmpP5;
	}
	if (p6) {
		*p6 = tmpP6;
	}
	return absF(sqrDist);
}

/*
 * --INFO--
 * Address: 8003D87C
 * Size:    000540
 */
f32 sqrDistance(Vector3f& point, KTri& tri, f32* outBaryU, f32* outBaryV)
{
	Vector3f pointToOrigin = tri.Origin() - point;
	f32 sqrLenEdge0        = tri.Edge0().squaredLength();
	f32 dotEdge0Edge1      = tri.Edge0().DP(tri.Edge1());
	f32 sqrLenEdge1        = tri.Edge1().squaredLength();
	f32 dotDirEdge0        = pointToOrigin.DP(tri.Edge0());
	f32 dotDirEdge1        = pointToOrigin.DP(tri.Edge1());
	f32 sqrDistToPoint     = pointToOrigin.squaredLength();
	f32 absDet             = absF(sqrLenEdge0 * sqrLenEdge1 - dotEdge0Edge1 * dotEdge0Edge1);
	f32 u                  = dotEdge0Edge1 * dotDirEdge1 - sqrLenEdge1 * dotDirEdge0;
	f32 v                  = dotEdge0Edge1 * dotDirEdge0 - sqrLenEdge0 * dotDirEdge1;

	f32 sqrDist;
	if (u + v <= absDet) {
		// projected point falls inside triangle's edges
		// adjust barycentric coordinates + calculate square distance

		if (u < 0.0f) {
			if (v < 0.0f) {
				// u and v are both negative, need to bound them to [0,1]
				if (dotDirEdge0 < 0.0f) {
					v = 0.0f;
					if (-dotDirEdge0 >= sqrLenEdge0) {
						u       = 1.0f;
						sqrDist = sqrLenEdge0 + 2.0f * dotDirEdge0 + sqrDistToPoint;
					} else {
						u       = -dotDirEdge0 / sqrLenEdge0;
						sqrDist = dotDirEdge0 * u + sqrDistToPoint;
					}
				} else {
					u = 0.0f;
					if (dotDirEdge1 >= 0.0f) {
						v       = 0.0f;
						sqrDist = sqrDistToPoint;
					} else if (-dotDirEdge1 >= sqrLenEdge1) {
						v       = 1.0f;
						sqrDist = sqrLenEdge1 + 2.0f * dotDirEdge1 + sqrDistToPoint;
					} else {
						v       = -dotDirEdge1 / sqrLenEdge1;
						sqrDist = dotDirEdge1 * v + sqrDistToPoint;
					}
				}
			} else {
				u = 0.0f;
				if (dotDirEdge1 >= 0.0f) {
					v       = 0.0f;
					sqrDist = sqrDistToPoint;
				} else if (-dotDirEdge1 >= sqrLenEdge1) {
					v       = 1.0f;
					sqrDist = sqrLenEdge1 + 2.0f * dotDirEdge1 + sqrDistToPoint;
				} else {
					v       = -dotDirEdge1 / sqrLenEdge1;
					sqrDist = dotDirEdge1 * v + sqrDistToPoint;
				}
			}
		} else if (v < 0.0f) {
			v = 0.0f;
			if (dotDirEdge0 >= 0.0f) {
				u       = 0.0f;
				sqrDist = sqrDistToPoint;
			} else if (-dotDirEdge0 >= sqrLenEdge0) {
				u       = 1.0f;
				sqrDist = sqrLenEdge0 + 2.0f * dotDirEdge0 + sqrDistToPoint;
			} else {
				u       = -dotDirEdge0 / sqrLenEdge0;
				sqrDist = dotDirEdge0 * u + sqrDistToPoint;
			}
		} else {
			// closest point is inside the triangle. normalise coordinates
			u *= 1.0f / absDet;
			v *= 1.0f / absDet;
			sqrDist = (sqrLenEdge0 * u + dotEdge0Edge1 * v + 2.0f * dotDirEdge0) * u
			        + (dotEdge0Edge1 * u + sqrLenEdge1 * v + 2.0f * dotDirEdge1) * v + sqrDistToPoint;
		}
	} else if (u < 0.0f) {
		f32 tmp1 = dotEdge0Edge1 + dotDirEdge0;
		f32 tmp2 = sqrLenEdge1 + dotDirEdge1;

		if (tmp2 > tmp1) {
			f32 tmp3 = tmp2 - tmp1;
			f32 tmp4 = sqrLenEdge0 - 2.0f * dotEdge0Edge1 + sqrLenEdge1;
			if (tmp3 >= tmp4) {
				u       = 1.0f;
				v       = 0.0f;
				sqrDist = sqrLenEdge0 + 2.0f * dotDirEdge0 + sqrDistToPoint;
			} else {
				u       = tmp3 / tmp4;
				v       = 1.0f - u;
				sqrDist = (sqrLenEdge0 * u + dotEdge0Edge1 * v + 2.0f * dotDirEdge0) * u
				        + (dotEdge0Edge1 * u + sqrLenEdge1 * v + 2.0f * dotDirEdge1) * v + sqrDistToPoint;
			}
		} else {
			u = 0.0f;
			if (tmp2 <= 0.0f) {
				v       = 1.0f;
				sqrDist = sqrLenEdge1 + 2.0f * dotDirEdge1 + sqrDistToPoint;
			} else if (dotDirEdge1 >= 0.0f) {
				v       = 0.0f;
				sqrDist = sqrDistToPoint;
			} else {
				v       = -dotDirEdge1 / sqrLenEdge1;
				sqrDist = dotDirEdge1 * v + sqrDistToPoint;
			}
		}
	} else if (v < 0.0f) {
		f32 tmp1 = dotEdge0Edge1 + dotDirEdge1;
		f32 tmp2 = sqrLenEdge0 + dotDirEdge0;

		if (tmp2 > tmp1) {
			f32 tmp3 = tmp2 - tmp1;
			f32 tmp4 = sqrLenEdge0 - 2.0f * dotEdge0Edge1 + sqrLenEdge1;
			if (tmp3 >= tmp4) {
				v       = 1.0f;
				u       = 0.0f;
				sqrDist = sqrLenEdge1 + 2.0f * dotDirEdge1 + sqrDistToPoint;
			} else {
				v       = tmp3 / tmp4;
				u       = 1.0f - v;
				sqrDist = (sqrLenEdge0 * u + dotEdge0Edge1 * v + 2.0f * dotDirEdge0) * u
				        + (dotEdge0Edge1 * u + sqrLenEdge1 * v + 2.0f * dotDirEdge1) * v + sqrDistToPoint;
			}
		} else {
			v = 0.0f;
			if (tmp2 <= 0.0f) {
				u       = 1.0f;
				sqrDist = sqrLenEdge0 + 2.0f * dotDirEdge0 + sqrDistToPoint;
			} else if (dotDirEdge0 >= 0.0f) {
				u       = 0.0f;
				sqrDist = sqrDistToPoint;
			} else {
				u       = -dotDirEdge0 / sqrLenEdge0;
				sqrDist = dotDirEdge0 * u + sqrDistToPoint;
			}
		}
	} else {
		f32 tmp1 = sqrLenEdge1 + dotDirEdge1 - dotEdge0Edge1 - dotDirEdge0;
		if (tmp1 <= 0.0f) {
			u       = 0.0f;
			v       = 1.0f;
			sqrDist = sqrLenEdge1 + 2.0f * dotDirEdge1 + sqrDistToPoint;
		} else {
			f32 tmp2 = sqrLenEdge0 - 2.0f * dotEdge0Edge1 + sqrLenEdge1;
			if (tmp1 >= tmp2) {
				u       = 1.0f;
				v       = 0.0f;
				sqrDist = sqrLenEdge0 + 2.0f * dotDirEdge0 + sqrDistToPoint;
			} else {
				u       = tmp1 / tmp2;
				v       = 1.0f - u;
				sqrDist = (sqrLenEdge0 * u + dotEdge0Edge1 * v + 2.0f * dotDirEdge0) * u
				        + (dotEdge0Edge1 * u + sqrLenEdge1 * v + 2.0f * dotDirEdge1) * v + sqrDistToPoint;
			}
		}
	}

	if (outBaryU) {
		*outBaryU = u;
	}
	if (outBaryV) {
		*outBaryV = v;
	}

	return absF(sqrDist);
}
