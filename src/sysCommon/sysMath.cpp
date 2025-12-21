#include "math.h"

#include "BoundBox.h"
#include "Camera.h"
#include "Collision.h"
#include "DebugLog.h"
#include "Graphics.h"
#include "KMath.h"
#include "Matrix3f.h"
#include "Plane.h"
#include "stl/math.h"

/*
 * --INFO--
 * Address: ........
 * Size:    00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

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
bool Plane::equal(immut Plane& other)
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
		mPVertexXIndex = 3;
		mNVertexXIndex = 0;
	} else {
		mPVertexXIndex = 0;
		mNVertexXIndex = 3;
	}

	if (mPlane.mNormal.y < 0.0f) {
		mPVertexYIndex = 4;
		mNVertexYIndex = 1;
	} else {
		mPVertexYIndex = 1;
		mNVertexYIndex = 4;
	}

	if (mPlane.mNormal.z < 0.0f) {
		mPVertexZIndex = 5;
		mNVertexZIndex = 2;
	} else {
		mPVertexZIndex = 2;
		mNVertexZIndex = 5;
	}
}

/*
 * --INFO--
 * Address: ........
 * Size:    0000AC
 */
void Vector3f::rotateTranspose(immut Matrix4f&)
{
	// FAKE but easiest way to juggle the float ordering
	Vector3f vec;
	vec.x = 1.0f;
	vec.y = 1.0f;
	vec.z = 1.0f;
	vec.x *= 2.0f;
	vec.y *= 2.0f;
	vec.z *= 2.0f;
	*this = vec;
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 8003760C
 * Size:    0000AC
 */
void Vector3f::rotate(immut Matrix4f& mtx)
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
void Vector3f::rotateTo(immut Matrix4f& mtx, Vector3f& outVec)
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
void Vector3f::multMatrix(immut Matrix4f& mtx)
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
void Vector3f::multMatrixTo(immut Matrix4f& mtx, Vector3f& outVec)
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
void Vector3f::rotate(immut Quat&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: ........
 * Size:    000104
 */
void Vector3f::rotateInverse(immut Quat&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address: 800378BC
 * Size:    0004E4
 */
void Quat::fromMat3f(immut Matrix3f& mtx)
{
	f32 diag = mtx.mMtx[0][0] + mtx.mMtx[1][1] + mtx.mMtx[2][2];
	f32 a    = 0.25f * (1.0f + diag);                        // f4
	f32 b    = a - 0.5f * (mtx.mMtx[1][1] + mtx.mMtx[2][2]); // f2, f5
	f32 c    = a - 0.5f * (mtx.mMtx[2][2] + mtx.mMtx[0][0]); // f6
	f32 d    = a - 0.5f * (mtx.mMtx[0][0] + mtx.mMtx[1][1]); // f7

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
		v.x   = t * (mtx.mMtx[2][1] - mtx.mMtx[1][2]);
		v.y   = t * (mtx.mMtx[0][2] - mtx.mMtx[2][0]);
		v.z   = t * (mtx.mMtx[1][0] - mtx.mMtx[0][1]);
	} break;
	case 1: {
		v.x   = std::sqrtf(b);
		f32 t = 0.25f / v.x;
		s     = t * (mtx.mMtx[2][1] - mtx.mMtx[1][2]);
		v.y   = t * (mtx.mMtx[0][1] + mtx.mMtx[1][0]);
		v.z   = t * (mtx.mMtx[0][2] + mtx.mMtx[2][0]);
	} break;
	case 2: {
		v.y   = std::sqrtf(c);
		f32 t = 0.25f / v.y;
		s     = t * (mtx.mMtx[0][2] - mtx.mMtx[2][0]);
		v.z   = t * (mtx.mMtx[1][2] + mtx.mMtx[2][1]);
		v.x   = t * (mtx.mMtx[1][0] + mtx.mMtx[0][1]);
	} break;
	case 3: {
		v.z   = std::sqrtf(d);
		f32 t = 0.25f / v.z;
		s     = t * (mtx.mMtx[1][0] - mtx.mMtx[0][1]);
		v.x   = t * (mtx.mMtx[2][0] + mtx.mMtx[0][2]);
		v.y   = t * (mtx.mMtx[2][1] + mtx.mMtx[1][2]);
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
void Quat::rotate(immut Vector3f& axis, f32 angle)
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
void Quat::multiply(immut Quat& other)
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
void Quat::multiplyTo(immut Quat& other, Quat& outQuat)
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
void Quat::genVectorX(Vector3f& outVec) immut
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
void Quat::genVectorY(Vector3f& outVec) immut
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
void Quat::genVectorZ(Vector3f& outVec) immut
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
void Quat::slerp(immut Quat& other, f32 t, int)
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
void Quat::fromEuler(immut Vector3f& angles)
{
	STACK_PAD_VAR(3);

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
	f32 min;

	x1 -= x0;
	if (x1 < 0.0f) {
		x1 = -x1;
	}

	y1 -= y0;
	if (y1 < 0.0f) {
		y1 = -y1;
	}

	if (x1 > y1) {
		min = y1;
	} else {
		min = x1;
	}

	return (x1 + y1) - (0.5f * min);
}

/*
 * --INFO--
 * Address: ........
 * Size:    000080
 */
f32 qdist3(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1)
{
	f32 min, mid, max;

	x1 -= x0;
	if (x1 < 0.0f) {
		x1 = -x1;
	}

	y1 -= y0;
	if (y1 < 0.0f) {
		y1 = -y1;
	}

	z1 -= z0;
	if (z1 < 0.0f) {
		z1 = -z1;
	}

	if (x1 > y1) {
		min = y1;
		mid = x1;
	} else {
		min = x1;
		mid = y1;
	}

	if (mid > z1) {
		max = mid;
		mid = z1;
	} else {
		max = z1;
	}

	return (min + mid) / 2.0f + max;
}

/*
 * --INFO--
 * Address: 80038678
 * Size:    0001BC
 */
void CollTriInfo::init(RoomInfo* info, immut Vector3f* vertices)
{
	for (int i = 0; i < 3; ++i) {
		immut Vector3f& nextVertex    = vertices[mVertexIndices[(i + 1) % 3]];
		immut Vector3f& currentVertex = vertices[mVertexIndices[i % 3]];

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
int CollTriInfo::behindEdge(immut Vector3f& point)
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
static bool pointInsideTri(KTri& tri, Vector3f& point)
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
f32 triRectDistance(immut Vector3f* vertex1, immut Vector3f* vertex2, immut Vector3f* vertex3, BoundBox& boundingBox, bool)
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
	Vector3f rectDims;

	botLeft   = boundingBox.mMin;
	botLeft.y = 0.0f;

	// Calculate XZ dimensions of rectangle
	rectDims   = boundingBox.mMax - boundingBox.mMin;
	rectDims.y = 0.0f;

	// Set rectangle corner points
	topLeft  = botLeft + Vector3f(rectDims.x, 0.0f, 0.0f);
	botRight = botLeft + Vector3f(0.0f, 0.0f, rectDims.z);
	topRight = botLeft + Vector3f(rectDims.x, 0.0f, rectDims.z);

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
bool KRect::inside(immut Vector3f& point)
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
void KTri::set(immut Vector3f& pointA, immut Vector3f& pointB, immut Vector3f& pointC)
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
f32 sqrDistance(KSegment& segment, KTri& tri, f32* outP3, f32* outP4, f32* outP5)
{
	Vector3f segToTri    = tri.Origin() - segment.Origin();
	f32 sqrLenSeg        = segment.Direction().squaredLength();
	f32 dotSegEdge0      = -segment.Direction().DP(tri.Edge0());
	f32 dotSegEdge1      = -segment.Direction().DP(tri.Edge1());
	f32 sqrLenEdge0      = tri.Edge0().squaredLength(); // why'd you do this this way...
	f32 dotEdge01        = tri.Edge0().DP(tri.Edge1());
	f32 sqrLenEdge1      = tri.Edge1().DP(tri.Edge1()); // ... and this this way. w/e man.
	f32 dotSegToTriSeg   = -segToTri.DP(segment.Direction());
	f32 dotSegToTriEdge0 = segToTri.DP(tri.Edge0());
	f32 dotSegToTriEdge1 = segToTri.DP(tri.Edge1());

	f32 a   = sqrLenEdge0 * sqrLenEdge1 - dotEdge01 * dotEdge01;
	f32 b   = dotSegEdge1 * dotEdge01 - dotSegEdge0 * sqrLenEdge1;
	f32 c   = dotSegEdge0 * dotEdge01 - dotSegEdge1 * sqrLenEdge0;
	f32 det = sqrLenSeg * a + dotSegEdge0 * b + dotSegEdge1 * c;

	KSegment tmpSeg;
	Vector3f point;
	f32 sqrDist, tmpDist;
	f32 currP3, currP4, currP5;
	f32 tmpP3, tmpP4, tmpP5;

	if (absF(det) >= gs_fTolerance) {
		// A

		f32 d    = sqrLenSeg * sqrLenEdge1 - dotSegEdge1 * dotSegEdge1;
		f32 e    = dotSegEdge1 * dotSegEdge0 - sqrLenSeg * dotEdge01;
		f32 f    = sqrLenSeg * sqrLenEdge0 - dotSegEdge0 * dotSegEdge0;
		f32 norm = 1.0f / det;
		f32 g    = -dotSegToTriSeg * norm;
		f32 h    = -dotSegToTriEdge0 * norm;
		f32 i    = -dotSegToTriEdge1 * norm;
		currP3   = a * g + b * h + c * i;
		currP4   = b * g + d * h + e * i;
		currP5   = c * g + e * h + f * i;

		if (currP3 < 0.0f) {
			if (currP4 + currP5 <= 1.0f) {
				if (currP4 < 0.0f) {
					if (currP5 < 0.0f) {
						// B

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge1();
						sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
						currP4             = 0.0f;

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge0();
						tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
						tmpP5              = 0.0f;

						if (tmpDist < sqrDist) {
							sqrDist = tmpDist;
							currP3  = tmpP3;
							currP4  = tmpP4;
							currP5  = tmpP5;
						}

						tmpDist = sqrDistance(segment.Origin(), tri, &tmpP4, &tmpP5);
						tmpP3   = 0.0f;
						if (tmpDist < sqrDist) {
							sqrDist = tmpDist;
							currP3  = tmpP3;
							currP4  = tmpP4;
							currP5  = tmpP5;
						}
					} else {
						// C

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge1();
						sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
						currP4             = 0.0f;

						tmpDist = sqrDistance(segment.Origin(), tri, &tmpP4, &tmpP5);
						tmpP3   = 0.0f;

						if (tmpDist < sqrDist) {
							sqrDist = tmpDist;
							currP3  = tmpP3;
							currP4  = tmpP4;
							currP5  = tmpP5;
						}
					}
				} else {
					if (currP5 < 0.0f) {
						// D

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge0();
						sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP4);
						currP5             = 0.0f;

						tmpDist = sqrDistance(segment.Origin(), tri, &tmpP4, &tmpP5);
						tmpP3   = 0.0f;

						if (tmpDist < sqrDist) {
							sqrDist = tmpDist;
							currP3  = tmpP3;
							currP4  = tmpP4;
							currP5  = tmpP5;
						}
					} else {
						// E

						sqrDist = sqrDistance(segment.Origin(), tri, &currP4, &currP5);
						currP3  = 0.0f;
					}
				}
			} else if (currP4 < 0.0f) {
				// F

				tmpSeg.Origin()    = tri.Origin();
				tmpSeg.Direction() = tri.Edge1();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
				currP4             = 0.0f;

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
				tmpP4              = 1.0f - tmpP5;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}

				tmpDist = sqrDistance(segment.Origin(), tri, &tmpP4, &tmpP5);
				tmpP3   = 0.0f;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}
			} else if (currP5 < 0.0f) {
				// G

				tmpSeg.Origin()    = tri.Origin();
				tmpSeg.Direction() = tri.Edge0();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP4);
				currP5             = 0.0f;

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
				tmpP4              = 1.0f - tmpP5;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}

				tmpDist = sqrDistance(segment.Origin(), tri, &tmpP4, &tmpP5);
				tmpP3   = 0.0f;
				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}
			} else {
				// H

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
				currP4             = 1.0f - currP5;

				tmpDist = sqrDistance(segment.Origin(), tri, &tmpP4, &tmpP5);
				tmpP3   = 0.0f;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}
			}

		} else if (currP3 <= 1.0f) {
			if (currP4 + currP5 <= 1.0f) {
				if (currP4 < 0.0f) {
					if (currP5 < 0.0f) {
						// I

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge1();
						sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
						currP4             = 0.0f;

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge0();
						tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
						tmpP5              = 0.0f;

						if (tmpDist < sqrDist) {
							sqrDist = tmpDist;
							currP3  = tmpP3;
							currP4  = tmpP4;
							currP5  = tmpP5;
						}
					} else {
						// J

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge1();
						sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
						currP4             = 0.0f;
					}
				} else if (currP5 < 0.0f) {
					// K

					tmpSeg.Origin()    = tri.Origin();
					tmpSeg.Direction() = tri.Edge0();
					sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP4);
					currP5             = 0.0f;

				} else {
					// L

					sqrDist = (sqrLenSeg * currP3 + dotSegEdge0 * currP4 + dotSegEdge1 * currP5 + 2.0f * dotSegToTriSeg) * currP3
					        + (dotSegEdge0 * currP3 + sqrLenEdge0 * currP4 + dotEdge01 * currP5 + 2.0f * dotSegToTriEdge0) * currP4
					        + (dotSegEdge1 * currP3 + dotEdge01 * currP4 + sqrLenEdge1 * currP5 + 2.0f * dotSegToTriEdge1) * currP5
					        + segToTri.squaredLength();
				}
			} else if (currP4 < 0.0f) {
				// M

				tmpSeg.Origin()    = tri.Origin();
				tmpSeg.Direction() = tri.Edge1();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
				currP4             = 0.0f;

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
				tmpP4              = 1.0f - tmpP5;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}
			} else if (currP5 < 0.0f) {
				// N

				tmpSeg.Origin()    = tri.Origin();
				tmpSeg.Direction() = tri.Edge0();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP4);
				currP5             = 0.0f;

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
				tmpP4              = 1.0f - tmpP5;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}
			} else {
				// O

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
				currP4             = 1.0f - currP5;
			}
		} else {
			if (currP4 + currP5 <= 1.0f) {
				if (currP4 < 0.0f) {
					if (currP5 < 0.0f) {
						// P

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge1();
						sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
						currP4             = 0.0f;

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge0();
						tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
						tmpP5              = 0.0f;
						if (tmpDist < sqrDist) {
							sqrDist = tmpDist;
							currP3  = tmpP3;
							currP4  = tmpP4;
							currP5  = tmpP5;
						}

						point   = segment.Origin() + segment.Direction();
						tmpDist = sqrDistance(point, tri, &tmpP4, &tmpP5);
						tmpP3   = 1.0f;

						if (tmpDist < sqrDist) {
							sqrDist = tmpDist;
							currP3  = tmpP3;
							currP4  = tmpP4;
							currP5  = tmpP5;
						}
					} else {
						// Q

						tmpSeg.Origin()    = tri.Origin();
						tmpSeg.Direction() = tri.Edge1();
						sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
						currP4             = 0.0f;

						point   = segment.Origin() + segment.Direction();
						tmpDist = sqrDistance(point, tri, &tmpP4, &tmpP5);
						tmpP3   = 1.0f;
						if (tmpDist < sqrDist) {
							sqrDist = tmpDist;
							currP3  = tmpP3;
							currP4  = tmpP4;
							currP5  = tmpP5;
						}
					}
				} else if (currP5 < 0.0f) {
					// R

					tmpSeg.Origin()    = tri.Origin();
					tmpSeg.Direction() = tri.Edge0();
					sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP4);
					currP5             = 0.0f;

					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, tri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				} else {
					// S

					point   = segment.Origin() + segment.Direction();
					sqrDist = sqrDistance(point, tri, &currP4, &currP5);
					currP3  = 1.0f;
				}
			} else if (currP4 < 0.0f) {
				// T

				tmpSeg.Origin()    = tri.Origin();
				tmpSeg.Direction() = tri.Edge1();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
				currP4             = 0.0f;

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
				tmpP4              = 1.0f - tmpP5;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}

				point   = segment.Origin() + segment.Direction();
				tmpDist = sqrDistance(point, tri, &tmpP4, &tmpP5);
				tmpP3   = 1.0f;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}
			} else if (currP5 < 0.0f) {
				// U

				tmpSeg.Origin()    = tri.Origin();
				tmpSeg.Direction() = tri.Edge0();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP4);
				currP5             = 0.0f;

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
				tmpP4              = 1.0f - tmpP5;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}

				point   = segment.Origin() + segment.Direction();
				tmpDist = sqrDistance(point, tri, &tmpP4, &tmpP5);
				tmpP3   = 1.0f;

				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}
			} else {
				// V

				tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
				tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
				sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP5);
				currP4             = 1.0f - currP5;

				point   = segment.Origin() + segment.Direction();
				tmpDist = sqrDistance(point, tri, &tmpP4, &tmpP5);
				tmpP3   = 1.0f;
				if (tmpDist < sqrDist) {
					sqrDist = tmpDist;
					currP3  = tmpP3;
					currP4  = tmpP4;
					currP5  = tmpP5;
				}
			}
		}
	} else {
		// W

		tmpSeg.Origin()    = tri.Origin();
		tmpSeg.Direction() = tri.Edge0();
		sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP4);
		currP5             = 0.0f;

		tmpSeg.Direction() = tri.Edge1();
		tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
		tmpP4              = 0.0f;

		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}

		tmpSeg.Origin()    = tri.Origin() + tri.Edge0();
		tmpSeg.Direction() = tri.Edge1() - tri.Edge0();
		tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
		tmpP4              = 1.0f - tmpP5;

		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}

		tmpDist = sqrDistance(segment.Origin(), tri, &tmpP4, &tmpP5);
		tmpP3   = 0.0f;
		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}

		point   = segment.Origin() + segment.Direction();
		tmpDist = sqrDistance(point, tri, &tmpP4, &tmpP5);
		tmpP3   = 1.0f;
		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}
	}

	if (outP3) {
		*outP3 = currP3;
	}
	if (outP4) {
		*outP4 = currP4;
	}
	if (outP5) {
		*outP5 = currP5;
	}

	return absF(sqrDist);
}

/*
 * --INFO--
 * Address: 8003AE50
 * Size:    000828
 */
f32 sqrDistance(KSegment& segment1, KSegment& segment2, f32* outP3, f32* outP4)
{
	Vector3f origToOrig   = segment1.Origin() - segment2.Origin();
	f32 sqrLenSeg1        = segment1.Direction().squaredLength();
	f32 dotSegSeg         = -segment1.Direction().DP(segment2.Direction());
	f32 sqrLenSeg2        = segment2.Direction().squaredLength();
	f32 dotOrigToOrigSeg1 = origToOrig.DP(segment1.Direction());
	f32 sqrDistOrigToOrig = origToOrig.squaredLength();

	f32 absDet = absF(sqrLenSeg1 * sqrLenSeg2 - dotSegSeg * dotSegSeg);

	f32 dotOrigToOrigSeg2;
	f32 currP3;
	f32 currP4;
	f32 sqrDist;

	if (absDet >= gs_fTolerance) {
		// A

		dotOrigToOrigSeg2 = -origToOrig.DP(segment2.Direction());
		currP3            = dotSegSeg * dotOrigToOrigSeg2 - sqrLenSeg2 * dotOrigToOrigSeg1;
		currP4            = dotSegSeg * dotOrigToOrigSeg1 - sqrLenSeg1 * dotOrigToOrigSeg2;

		if (currP3 >= 0.0f) {
			if (currP3 <= absDet) {
				if (currP4 >= 0.0f) {
					if (currP4 <= absDet) {
						// B

						f32 norm = 1.0f / absDet;
						currP3 *= norm;
						currP4 *= norm;
						sqrDist = (sqrLenSeg1 * currP3 + dotSegSeg * currP4 + 2.0f * dotOrigToOrigSeg1) * currP3
						        + (dotSegSeg * currP3 + sqrLenSeg2 * currP4 + 2.0f * dotOrigToOrigSeg2) * currP4 + sqrDistOrigToOrig;

					} else {
						// C

						currP4  = 1.0f;
						f32 tmp = dotSegSeg + dotOrigToOrigSeg1;
						if (tmp >= 0.0f) {
							currP3  = 0.0f;
							sqrDist = sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
						} else if (-tmp >= sqrLenSeg1) {
							currP3  = 1.0f;
							sqrDist = sqrLenSeg1 + sqrLenSeg2 + sqrDistOrigToOrig + 2.0f * (dotOrigToOrigSeg2 + tmp);
						} else {
							currP3  = -tmp / sqrLenSeg1;
							sqrDist = tmp * currP3 + sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
						}
					}

				} else {
					// D

					currP4 = 0.0f;
					if (dotOrigToOrigSeg1 >= 0.0f) {
						currP3  = 0.0f;
						sqrDist = sqrDistOrigToOrig;
					} else if (-dotOrigToOrigSeg1 >= sqrLenSeg1) {
						currP3  = 1.0f;
						sqrDist = sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
					} else {
						currP3  = -dotOrigToOrigSeg1 / sqrLenSeg1;
						sqrDist = dotOrigToOrigSeg1 * currP3 + sqrDistOrigToOrig;
					}
				}

			} else {
				if (currP4 >= 0.0f) {
					if (currP4 <= absDet) {
						// E

						currP3  = 1.0f;
						f32 tmp = dotSegSeg + dotOrigToOrigSeg2;
						if (tmp >= 0.0f) {
							currP4  = 0.0f;
							sqrDist = sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
						} else if (-tmp >= sqrLenSeg2) {
							currP4  = 1.0f;
							sqrDist = sqrLenSeg1 + sqrLenSeg2 + sqrDistOrigToOrig + 2.0f * (dotOrigToOrigSeg1 + tmp);
						} else {
							currP4  = -tmp / sqrLenSeg2;
							sqrDist = tmp * currP4 + sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
						}

					} else {
						// F

						f32 tmp = dotSegSeg + dotOrigToOrigSeg1;
						if (-tmp <= sqrLenSeg1) {
							currP4 = 1.0f;
							if (tmp >= 0.0f) {
								currP3  = 0.0f;
								sqrDist = sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
							} else {
								currP3  = -tmp / sqrLenSeg1;
								sqrDist = tmp * currP3 + sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
							}
						} else {
							currP3 = 1.0f;
							tmp    = dotSegSeg + dotOrigToOrigSeg2;
							if (tmp >= 0.0f) {
								currP4  = 0.0f;
								sqrDist = sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
							} else if (-tmp >= sqrLenSeg2) {
								currP4  = 1.0f;
								sqrDist = sqrLenSeg1 + sqrLenSeg2 + sqrDistOrigToOrig + 2.0f * (dotOrigToOrigSeg1 + tmp);
							} else {
								currP4  = -tmp / sqrLenSeg2;
								sqrDist = tmp * currP4 + sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
							}
						}
					}

				} else {
					// G

					if (-dotOrigToOrigSeg1 < sqrLenSeg1) {
						currP4 = 0.0f;
						if (dotOrigToOrigSeg1 >= 0.0f) {
							currP3  = 0.0f;
							sqrDist = sqrDistOrigToOrig;
						} else {
							currP3  = -dotOrigToOrigSeg1 / sqrLenSeg1;
							sqrDist = dotOrigToOrigSeg1 * currP3 + sqrDistOrigToOrig;
						}
					} else {
						currP3  = 1.0f;
						f32 tmp = dotSegSeg + dotOrigToOrigSeg2;
						if (tmp >= 0.0f) {
							currP4  = 0.0f;
							sqrDist = sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
						} else if (-tmp >= sqrLenSeg2) {
							currP4  = 1.0f;
							sqrDist = sqrLenSeg1 + sqrLenSeg2 + sqrDistOrigToOrig + 2.0f * (dotOrigToOrigSeg1 + tmp);
						} else {
							currP4  = -tmp / sqrLenSeg2;
							sqrDist = tmp * currP4 + sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
						}
					}
				}
			}
		} else {
			if (currP4 >= 0.0f) {
				if (currP4 <= absDet) {
					// H

					currP3 = 0.0f;
					if (dotOrigToOrigSeg2 >= 0.0f) {
						currP4  = 0.0f;
						sqrDist = sqrDistOrigToOrig;
					} else if (-dotOrigToOrigSeg2 >= sqrLenSeg2) {
						currP4  = 1.0f;
						sqrDist = sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
					} else {
						currP4  = -dotOrigToOrigSeg2 / sqrLenSeg2;
						sqrDist = dotOrigToOrigSeg2 * currP4 + sqrDistOrigToOrig;
					}
				} else {
					// I

					f32 tmp = dotSegSeg + dotOrigToOrigSeg1;
					if (tmp < 0.0f) {
						currP4 = 1.0f;
						if (-tmp >= sqrLenSeg1) {
							currP3  = 1.0f;
							sqrDist = sqrLenSeg1 + sqrLenSeg2 + sqrDistOrigToOrig + 2.0f * (dotOrigToOrigSeg2 + tmp);
						} else {
							currP3  = -tmp / sqrLenSeg1;
							sqrDist = tmp * currP3 + sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
						}
					} else {
						currP3 = 0.0f;
						if (dotOrigToOrigSeg2 >= 0.0f) {
							currP4  = 0.0f;
							sqrDist = sqrDistOrigToOrig;
						} else if (-dotOrigToOrigSeg2 >= sqrLenSeg2) {
							currP4  = 1.0f;
							sqrDist = sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
						} else {
							currP4  = -dotOrigToOrigSeg2 / sqrLenSeg2;
							sqrDist = dotOrigToOrigSeg2 * currP4 + sqrDistOrigToOrig;
						}
					}
				}

			} else {
				// J

				if (dotOrigToOrigSeg1 < 0.0f) {
					currP4 = 0.0f;
					if (-dotOrigToOrigSeg1 >= sqrLenSeg1) {
						currP3  = 1.0f;
						sqrDist = sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
					} else {
						currP3  = -dotOrigToOrigSeg1 / sqrLenSeg1;
						sqrDist = dotOrigToOrigSeg1 * currP3 + sqrDistOrigToOrig;
					}
				} else {
					currP3 = 0.0f;
					if (dotOrigToOrigSeg2 >= 0.0f) {
						currP4  = 0.0f;
						sqrDist = sqrDistOrigToOrig;
					} else if (-dotOrigToOrigSeg2 >= sqrLenSeg2) {
						currP4  = 1.0f;
						sqrDist = sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
					} else {
						currP4  = -dotOrigToOrigSeg2 / sqrLenSeg2;
						sqrDist = dotOrigToOrigSeg2 * currP4 + sqrDistOrigToOrig;
					}
				}
			}
		}
	} else {
		// K

		if (dotSegSeg > 0.0f) {
			if (dotOrigToOrigSeg1 >= 0.0f) {
				currP3  = 0.0f;
				currP4  = 0.0f;
				sqrDist = sqrDistOrigToOrig;
			} else if (-dotOrigToOrigSeg1 <= sqrLenSeg1) {
				currP3  = -dotOrigToOrigSeg1 / sqrLenSeg1;
				currP4  = 0.0f;
				sqrDist = dotOrigToOrigSeg1 * currP3 + sqrDistOrigToOrig;
			} else {
				dotOrigToOrigSeg2 = -origToOrig.DP(segment2.Direction());
				currP3            = 1.0f;
				f32 tmp           = sqrLenSeg1 + dotOrigToOrigSeg1;

				if (-tmp >= dotSegSeg) {
					currP4  = 1.0f;
					sqrDist = sqrLenSeg1 + sqrLenSeg2 + sqrDistOrigToOrig + 2.0f * (dotSegSeg + dotOrigToOrigSeg1 + dotOrigToOrigSeg2);
				} else {
					currP4  = -tmp / dotSegSeg;
					sqrDist = sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig
					        + (sqrLenSeg2 * currP4 + 2.0f * (dotSegSeg + dotOrigToOrigSeg2)) * currP4;
				}
			}
		} else {
			if (-dotOrigToOrigSeg1 >= sqrLenSeg1) {
				currP3  = 1.0f;
				currP4  = 0.0f;
				sqrDist = sqrLenSeg1 + 2.0f * dotOrigToOrigSeg1 + sqrDistOrigToOrig;
			} else if (dotOrigToOrigSeg1 <= 0.0f) {
				currP3  = -dotOrigToOrigSeg1 / sqrLenSeg1;
				currP4  = 0.0f;
				sqrDist = dotOrigToOrigSeg1 * currP3 + sqrDistOrigToOrig;
			} else {
				dotOrigToOrigSeg2 = -origToOrig.DP(segment2.Direction());
				currP3            = 0.0f;
				if (dotOrigToOrigSeg1 >= -dotSegSeg) {
					currP4  = 1.0f;
					sqrDist = sqrLenSeg2 + 2.0f * dotOrigToOrigSeg2 + sqrDistOrigToOrig;
				} else {
					currP4  = -dotOrigToOrigSeg1 / dotSegSeg;
					sqrDist = (2.0f * dotOrigToOrigSeg2 + sqrLenSeg2 * currP4) * currP4 + sqrDistOrigToOrig;
				}
			}
		}
	}

	if (outP3) {
		*outP3 = currP3;
	}
	if (outP4) {
		*outP4 = currP4;
	}

	return absF(sqrDist);
}

/*
 * --INFO--
 * Address: 8003B678
 * Size:    001D9C
 */
f32 sqrDistance(KSegment& segment, KRect& rect, f32* p3, f32* p4, f32* p5)
{

	Vector3f segToRect    = rect.mBotTri.Origin() - segment.Origin();
	f32 sqrLenSeg         = segment.Direction().squaredLength();
	f32 dotSegEdge0       = -segment.Direction().DP(rect.mBotTri.Edge0());
	f32 dotSegEdge1       = -segment.Direction().DP(rect.mBotTri.Edge1());
	f32 sqrLenEdge0       = rect.mBotTri.Edge0().squaredLength();
	f32 sqrLenEdge1       = rect.mBotTri.Edge1().squaredLength();
	f32 dotSegToRectSeg   = -segToRect.DP(segment.Direction());
	f32 dotSegToRectEdge0 = segToRect.DP(rect.mBotTri.Edge0());
	f32 dotSegToRectEdge1 = segToRect.DP(rect.mBotTri.Edge1());

	f32 sqr01    = sqrLenEdge0 * sqrLenEdge1;
	f32 dotSqr01 = -dotSegEdge0 * sqrLenEdge1;
	f32 dotSqr10 = -dotSegEdge1 * sqrLenEdge0;
	f32 det      = sqrLenSeg * sqr01 + dotSegEdge0 * dotSqr01 + dotSegEdge1 * dotSqr10;

	KSegment tmpSeg;
	Vector3f point;
	f32 currP3, currP4, currP5, tmpP3, tmpP4, tmpP5;

	f32 sqrDist;
	f32 tmpDist;

	if (absF(det) >= gs_fTolerance) {
		// A

		f32 a    = sqrLenSeg * sqrLenEdge1 - dotSegEdge1 * dotSegEdge1;
		f32 b    = dotSegEdge1 * dotSegEdge0;
		f32 c    = sqrLenSeg * sqrLenEdge0 - dotSegEdge0 * dotSegEdge0;
		f32 norm = 1.0f / det;
		f32 d    = -dotSegToRectSeg * norm;
		f32 e    = -dotSegToRectEdge0 * norm;
		f32 f    = -dotSegToRectEdge1 * norm;

		currP3 = sqr01 * d + dotSqr01 * e + dotSqr10 * f;
		currP4 = dotSqr01 * d + a * e + b * f;
		currP5 = dotSqr10 * d + b * e + c * f;

		if (currP3 < 0.0f) {
			if (currP4 < 0.0f) {
				if (currP5 < 0.0f) {
					// B
					// Origin to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

					// Origin to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

					// Segment origin to rect - comparison 2
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				} else if (currP5 <= 1.0f) {
					// C

					// Origin to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

					// Segment origin to rect - comparison 1
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				} else {
					// D

					// Origin to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

					// Point C to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

					// Segment origin to rect - comparison 2
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				}
			} else if (currP4 <= 1.0f) {
				if (currP5 < 0.0f) {
					// E

					// Origin to Edge 0 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP4);
					currP5  = 0.0f;

					// Segment origin to rect - comparison 1
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				} else if (currP5 <= 1.0f) {
					// F

					// Segment origin to rect
					sqrDist = sqrDistance(segment.Origin(), rect.mBotTri, &currP4, &currP5);
					currP3  = 0.0f;

				} else {
					// G

					// Point C to Edge 0 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP4);
					currP5  = 1.0f;

					// Segment origin to rect - comparison 1
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				}
			} else {
				if (currP5 < 0.0f) {
					// H

					// Point B to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

					// Origin to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

					// Segment origin to rect - comparison 2
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else if (currP5 <= 1.0f) {
					// I

					// Point B to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

					// Segment origin to rect - comparison 1
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else {
					// J

					// Point B to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

					// Point C to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

					// Segment origin to rect - comparison 1
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				}
			}
		} else if (currP3 <= 1.0f) {
			if (currP4 < 0.0f) {
				if (currP5 < 0.0f) {
					// K

					// Origin to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

					// Origin to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else if (currP5 <= 1.0f) {
					// L

					// Origin to Edge 1
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

				} else {
					// M

					// Origin to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

					// Point C to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				}

			} else if (currP4 <= 1.0f) {
				if (currP5 < 0.0f) {
					// N

					// Origin to Edge 0
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP4);
					currP5  = 0.0f;

				} else if (currP5 <= 1.0f) {
					// O

					sqrDist = ((sqrLenSeg * currP3 + dotSegEdge0 * currP4 + dotSegEdge1 * currP5 + 2.0f * dotSegToRectSeg) * currP3
					           + (dotSegEdge0 * currP3 + sqrLenEdge0 * currP4 + 2.0f * dotSegToRectEdge0) * currP4
					           + (dotSegEdge1 * currP3 + sqrLenEdge1 * currP5 + 2.0f * dotSegToRectEdge1) * currP5)
					        + segToRect.squaredLength();

				} else {
					// P

					// Point C to Edge 0
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP4);
					currP5  = 1.0f;
				}

			} else {
				if (currP5 < 0.0f) {
					// Q

					// Point B to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

					// Origin to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else if (currP5 <= 1.0f) {
					// R

					// Point B to Edge 1
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

				} else {
					// S

					// Point B to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

					// Point C to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				}
			}
		} else {
			if (currP4 < 0.0f) {
				if (currP5 < 0.0f) {
					// T

					// Origin to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

					// Origin to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

					// Segment end to rect - comparison 2

					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else if (currP5 <= 1.0f) {
					// U

					// Origin to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

					// accidental copy-paste?
					tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);

					// Seg end to rect - comparison 1
					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else {
					// V

					// Origin to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 0.0f;

					// Point C to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

					// Seg end to rect - comparison 2
					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				}

			} else if (currP4 <= 1.0f) {
				if (currP5 < 0.0f) {
					// W

					// Origin to Edge 0
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP4);
					currP5  = 0.0f;

					// Seg end to rect - comparison 1
					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else if (currP5 <= 1.0f) {
					// X

					// Seg end to rect
					point   = segment.Origin() + segment.Direction();
					sqrDist = sqrDistance(point, rect.mBotTri, &currP4, &currP5);
					currP3  = 1.0f;

				} else {
					// Y

					// Point C to Edge 0 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP4);
					currP5  = 1.0f;

					// Seg end to rect - comparison 1
					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				}

			} else {
				if (currP5 < 0.0f) {
					// Z

					// Point B to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

					// Origin to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 0.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

					// Segment end - comparison 2
					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else if (currP5 <= 1.0f) {
					// AA

					// Point B to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

					// Segment end - comparison 1
					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

				} else {
					// AB

					// Point B to Edge 1 - base case to compare to
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
					tmpSeg.Direction() = rect.mBotTri.Edge1();

					sqrDist = sqrDistance(segment, tmpSeg, &currP3, &currP5);
					currP4  = 1.0f;

					// Point C to Edge 0 - comparison 1
					tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
					tmpSeg.Direction() = rect.mBotTri.Edge0();

					tmpDist = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
					tmpP5   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}

					// Segment end - comparison 2
					point   = segment.Origin() + segment.Direction();
					tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
					tmpP3   = 1.0f;

					if (tmpDist < sqrDist) {
						sqrDist = tmpDist;
						currP3  = tmpP3;
						currP4  = tmpP4;
						currP5  = tmpP5;
					}
				}
			}
		}

	} else {
		// AC

		// Origin to Edge 0 - base case to compare to
		tmpSeg.Origin()    = rect.mBotTri.Origin();
		tmpSeg.Direction() = rect.mBotTri.Edge0();
		sqrDist            = sqrDistance(segment, tmpSeg, &currP3, &currP4);
		currP5             = 0.0f;

		// Origin to Edge 1 - comparison 1
		tmpSeg.Direction() = rect.mBotTri.Edge1();
		tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
		tmpP4              = 0.0f;

		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}

		// Point C to Edge 0 - comparison 2
		tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge1();
		tmpSeg.Direction() = rect.mBotTri.Edge0();
		tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP4);
		tmpP5              = 1.0f;

		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}

		// Point B to Edge 1 - comparison 3
		tmpSeg.Origin()    = rect.mBotTri.Origin() + rect.mBotTri.Edge0();
		tmpSeg.Direction() = rect.mBotTri.Edge1();
		tmpDist            = sqrDistance(segment, tmpSeg, &tmpP3, &tmpP5);
		tmpP4              = 1.0f;

		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}

		// Seg origin to rect - comparison 4
		tmpDist = sqrDistance(segment.Origin(), rect.mBotTri, &tmpP4, &tmpP5);
		tmpP3   = 0.0f;

		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}

		// Seg origin to rect - comparison 4
		point   = segment.Origin() + segment.Direction();
		tmpDist = sqrDistance(point, rect.mBotTri, &tmpP4, &tmpP5);
		tmpP3   = 1.0f;

		if (tmpDist < sqrDist) {
			sqrDist = tmpDist;
			currP3  = tmpP3;
			currP4  = tmpP4;
			currP5  = tmpP5;
		}
	}

	if (p3) {
		*p3 = currP3;
	}
	if (p4) {
		*p4 = currP4;
	}
	if (p5) {
		*p5 = currP5;
	}

	return absF(sqrDist);
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
f32 sqrDistance(immut Vector3f& point, KTri& tri, f32* outBaryU, f32* outBaryV)
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
