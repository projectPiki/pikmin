#include "Matrix4f.h"

#include "Vector.h"
#include "SRT.h"

f32 sintable[0x1000];
f32 costable[0x1000];
Matrix4f Matrix4f::ident;

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */

Matrix4f::Matrix4f(Mtx44 mtx)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mMtx[i][j] = mtx[i][j];
		}
	}
}

/*
 * --INFO--
 * Address:	8003DDBC
 * Size:	00004C
 */
void Matrix4f::makeIdentity()
{
	mMtx[0][0] = 1.0f;
	mMtx[0][1] = 0.0f;
	mMtx[0][2] = 0.0f;
	mMtx[0][3] = 0.0f;
	mMtx[1][0] = 0.0f;
	mMtx[1][1] = 1.0f;
	mMtx[1][2] = 0.0f;
	mMtx[1][3] = 0.0f;
	mMtx[2][0] = 0.0f;
	mMtx[2][1] = 0.0f;
	mMtx[2][2] = 1.0f;
	mMtx[2][3] = 0.0f;
	mMtx[3][0] = 0.0f;
	mMtx[3][1] = 0.0f;
	mMtx[3][2] = 0.0f;
	mMtx[3][3] = 1.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void Matrix4f::blend(Matrix4f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001A4
 */
void Matrix4f::makeOrtho(f32, f32, f32, f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void Matrix4f::makePerspective(f32, f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003DE08
 * Size:	0000C0
 * @note ChatGPT 1 shotted this, props to our assistant dev!
 */
void Matrix4f::makeRotate(Vector3f& axis, f32 angleSin, f32 angleCos)
{
	f32 x = axis.x;
	f32 y = axis.y;
	f32 z = axis.z;

	f32 inv = 1.0f - angleCos;

	mMtx[0][0] = inv * x * x + angleCos;
	mMtx[0][1] = inv * x * y + angleSin * z;
	mMtx[0][2] = inv * x * z - angleSin * y;
	mMtx[0][3] = 0.0f;

	mMtx[1][0] = inv * x * y - angleSin * z;
	mMtx[1][1] = inv * y * y + angleCos;
	mMtx[1][2] = inv * y * z + angleSin * x;
	mMtx[1][3] = 0.0f;

	mMtx[2][0] = inv * x * z + angleSin * y;
	mMtx[2][1] = inv * y * z - angleSin * x;
	mMtx[2][2] = inv * z * z + angleCos;
	mMtx[2][3] = 0.0f;

	mMtx[3][0] = 0.0f;
	mMtx[3][1] = 0.0f;
	mMtx[3][2] = 0.0f;
	mMtx[3][3] = 1.0f;
}

/*
 * --INFO--
 * Address:	8003DEC8
 * Size:	00006C
 */
void Matrix4f::makeRotate(Vector3f& axis, f32 angle)
{
	f32 angleSin = sinf(angle);
	f32 angleCos = cosf(angle);

	makeRotate(axis, angleSin, angleCos);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000178
 */
void Matrix4f::makeBallRotate(Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void Matrix4f::rotate(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000138
 */
void Matrix4f::rotate(f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003DF34
 * Size:	0001A0
 */
void Matrix4f::multiply(Matrix4f& other)
{
	Matrix4f result;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.mMtx[i][j] = 0.0f;
			for (int k = 0; k < 4; k++) {
				result.mMtx[i][j] += mMtx[i][k] * other.mMtx[k][j];
			}
		}
	}

	*this = result;
}

/*
 * --INFO--
 * Address:	8003E0D4
 * Size:	000020
 */
void Matrix4f::multiplyTo(Matrix4f& mtxB, Matrix4f& outMtx)
{
	PSMTXConcat(mMtx, mtxB.mMtx, outMtx.mMtx);
}

/*
 * --INFO--
 * Address:	8003E0F4
 * Size:	00019C
 */
void Matrix4f::makeSRT(Vector3f& scale, Vector3f& rotation, Vector3f& translation)
{
	u32 stackFix[6];

	f32 sinX = sinf(rotation.x);
	f32 sinY = sinf(rotation.y);
	f32 sinZ = sinf(rotation.z);

	f32 cosX = cosf(rotation.x);
	f32 cosY = cosf(rotation.y);
	f32 cosZ = cosf(rotation.z);

	f32 cosX_cosZ = cosX * cosZ;
	f32 sinX_sinY = sinX * sinY;
	f32 cosX_sinZ = cosX * sinZ;

	mMtx[0][0] = cosY * cosZ * scale.x;
	mMtx[1][0] = cosY * sinZ * scale.x;
	mMtx[2][0] = scale.x * -sinY;

	mMtx[3][0] = mMtx[3][1] = mMtx[3][2] = 0.0f;

	mMtx[0][1] = (sinX_sinY * cosZ - cosX_sinZ) * scale.y;
	mMtx[1][1] = (sinX_sinY * sinZ + cosX_cosZ) * scale.y;
	mMtx[2][1] = sinX * cosY * scale.y;

	mMtx[0][2] = (cosX_cosZ * sinY + sinX * sinZ) * scale.z;
	mMtx[1][2] = (cosX_sinZ * sinY - sinX * cosZ) * scale.z;
	mMtx[2][2] = cosX * cosY * scale.z;

	mMtx[0][3] = translation.x;
	mMtx[1][3] = translation.y;
	mMtx[2][3] = translation.z;
	mMtx[3][3] = 1.0f;
}

/*
 * --INFO--
 * Address:	8003E290
 * Size:	0001AC
 */
void Matrix4f::makeConcatSRT(Matrix4f* a, Matrix4f& b, SRT& srt)
{
	u32 stackFix[6];

	f32 sinX = sinf(srt.mRotation.x);
	f32 sinY = sinf(srt.mRotation.y);
	f32 sinZ = sinf(srt.mRotation.z);

	f32 cosX = cosf(srt.mRotation.x);
	f32 cosY = cosf(srt.mRotation.y);
	f32 cosZ = cosf(srt.mRotation.z);

	f32 cosX_cosZ = cosX * cosZ;
	f32 sinX_sinY = sinX * sinY;
	f32 cosX_sinZ = cosX * sinZ;

	b.mMtx[0][0] = cosY * cosZ * srt.mScale.x;
	b.mMtx[1][0] = cosY * sinZ * srt.mScale.x;
	b.mMtx[2][0] = srt.mScale.x * -sinY;

	b.mMtx[0][1] = (sinX_sinY * cosZ - cosX_sinZ) * srt.mScale.y;
	b.mMtx[1][1] = (sinX_sinY * sinZ + cosX_cosZ) * srt.mScale.y;
	b.mMtx[2][1] = sinX * cosY * srt.mScale.y;

	b.mMtx[0][2] = (cosX_cosZ * sinY + sinX * sinZ) * srt.mScale.z;
	b.mMtx[1][2] = (cosX_sinZ * sinY - sinX * cosZ) * srt.mScale.z;
	b.mMtx[2][2] = cosX * cosY * srt.mScale.z;

	b.mMtx[0][3] = srt.mTranslation.x;
	b.mMtx[1][3] = srt.mTranslation.y;
	b.mMtx[2][3] = srt.mTranslation.z;

	b.mMtx[3][0] = 0.0f;
	b.mMtx[3][1] = 0.0f;
	b.mMtx[3][2] = 0.0f;
	b.mMtx[3][3] = 1.0f;

	PSMTXConcat(a->mMtx, b.mMtx, mMtx);
}

/*
 * --INFO--
 * Address:	8003E43C
 * Size:	000380
 */
void Matrix4f::inverse(Matrix4f* inv)
{
	Matrix4f tMtx;

	Matrix4f* temp;
	if (inv == this) {
		temp = &tMtx;
	} else {
		temp = inv;
	}

	f32 determinant = mMtx[0][0] * mMtx[1][1] * mMtx[2][2] + mMtx[0][1] * mMtx[1][2] * mMtx[2][0] + mMtx[0][2] * mMtx[1][0] * mMtx[2][1]
	                - mMtx[2][0] * mMtx[1][1] * mMtx[0][2] - mMtx[1][0] * mMtx[0][1] * mMtx[2][2] - mMtx[0][0] * mMtx[2][1] * mMtx[1][2];

	if (determinant == 0.0f) {
		temp->makeIdentity();
		temp->mMtx[0][3] = -mMtx[0][3];
		temp->mMtx[1][3] = -mMtx[1][3];
		temp->mMtx[2][3] = -mMtx[2][3];
	} else {
		f32 invDet = 1.0f / determinant;

		temp->mMtx[0][0] = (mMtx[1][1] * mMtx[2][2] - mMtx[2][1] * mMtx[1][2]) * invDet;
		temp->mMtx[0][1] = -(mMtx[0][1] * mMtx[2][2] - mMtx[2][1] * mMtx[0][2]) * invDet;
		temp->mMtx[0][2] = (mMtx[0][1] * mMtx[1][2] - mMtx[1][1] * mMtx[0][2]) * invDet;

		temp->mMtx[1][0] = -(mMtx[1][0] * mMtx[2][2] - mMtx[2][0] * mMtx[1][2]) * invDet;
		temp->mMtx[1][1] = (mMtx[0][0] * mMtx[2][2] - mMtx[2][0] * mMtx[0][2]) * invDet;
		temp->mMtx[1][2] = -(mMtx[0][0] * mMtx[1][2] - mMtx[1][0] * mMtx[0][2]) * invDet;

		temp->mMtx[2][0] = (mMtx[1][0] * mMtx[2][1] - mMtx[2][0] * mMtx[1][1]) * invDet;
		temp->mMtx[2][1] = -(mMtx[0][0] * mMtx[2][1] - mMtx[2][0] * mMtx[0][1]) * invDet;
		temp->mMtx[2][2] = (mMtx[0][0] * mMtx[1][1] - mMtx[1][0] * mMtx[0][1]) * invDet;

		temp->mMtx[0][3] = -temp->mMtx[0][0] * mMtx[0][3] - temp->mMtx[0][1] * mMtx[1][3] - temp->mMtx[0][2] * mMtx[2][3];
		temp->mMtx[1][3] = -temp->mMtx[1][0] * mMtx[0][3] - temp->mMtx[1][1] * mMtx[1][3] - temp->mMtx[1][2] * mMtx[2][3];
		temp->mMtx[2][3] = -temp->mMtx[2][0] * mMtx[0][3] - temp->mMtx[2][1] * mMtx[1][3] - temp->mMtx[2][2] * mMtx[2][3];
	}

	temp->mMtx[3][0] = 0.0f;
	temp->mMtx[3][1] = 0.0f;
	temp->mMtx[3][2] = 0.0f;
	temp->mMtx[3][3] = 1.0f;

	if (temp == &tMtx) {
		*inv = tMtx;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000244
 */
void Matrix4f::makeAligned(Vector3f&, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void Matrix4f::rotateX(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void Matrix4f::rotateY(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000100
 */
void Matrix4f::rotateZ(f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void Matrix4f::translate(f32, f32, f32)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003E7BC
 * Size:	0000C4
 */
void Matrix4f::scale(Vector3f& scaleVector)
{
	mMtx[0][0] *= scaleVector.x;
	mMtx[1][0] *= scaleVector.x;
	mMtx[2][0] *= scaleVector.x;
	mMtx[3][0] *= scaleVector.x;

	mMtx[0][1] *= scaleVector.y;
	mMtx[1][1] *= scaleVector.y;
	mMtx[2][1] *= scaleVector.y;
	mMtx[3][1] *= scaleVector.y;

	mMtx[0][2] *= scaleVector.z;
	mMtx[1][2] *= scaleVector.z;
	mMtx[2][2] *= scaleVector.z;
	mMtx[3][2] *= scaleVector.z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0003C0
 */
void Matrix4f::makeLookfrom(Vector3f&, Vector3f&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003E880
 * Size:	000300
 */
void Matrix4f::makeLookat(Vector3f& cameraPos, Vector3f& targetPos, Vector3f* optionalUp)
{
	Vector3f forward;
	Vector3f right;
	Vector3f up;

	forward.x = cameraPos.x - targetPos.x;
	forward.y = cameraPos.y - targetPos.y;
	forward.z = cameraPos.z - targetPos.z;
	forward.normalise();

	if (optionalUp) {
		// Custom up vector calculation
		up    = *optionalUp;
		right = up;
		right.CP(forward);
		right.normalise();
	} else {
		// Default up vector calculation
		right.set(forward.z, 0.0f, -forward.x);
		right.normalise();
		up = forward;
		up.CP(right);
		up.normalise();
	}

	makeLookat(cameraPos, right, up, forward);
}

/*
 * --INFO--
 * Address:	8003EB80
 * Size:	000100
 */
void Matrix4f::makeLookat(Vector3f& cameraPos, Vector3f& rightDir, Vector3f& upDir, Vector3f& backDir)
{
	setRow(0, rightDir);
	mMtx[0][3] = -cameraPos.DP(rightDir);

	setRow(1, upDir);
	mMtx[1][3] = -cameraPos.DP(upDir);

	setRow(2, backDir);
	mMtx[2][3] = -cameraPos.DP(backDir);

	mMtx[3][0] = 0.0f;
	mMtx[3][1] = 0.0f;
	mMtx[3][2] = 0.0f;
	mMtx[3][3] = 1.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000164
 */
void Matrix4f::makeProjection(Vector3f&, Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000140
 */
void Matrix4f::makeReflection(Plane&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	8003EC80
 * Size:	000084
 */
void Matrix4f::transposeTo(Matrix4f& dest)
{
	for (int i = 0; i < 4; i++) {
		dest.mMtx[i][0] = mMtx[0][i];
		dest.mMtx[i][1] = mMtx[1][i];
		dest.mMtx[i][2] = mMtx[2][i];
		dest.mMtx[i][3] = mMtx[3][i];
	}
}

/*
 * --INFO--
 * Address:	8003ED04
 * Size:	00012C
 */
void Matrix4f::makeVQS(Vector3f& translation, Quat& rotation, Vector3f& scale)
{
	f32 yy2 = 2.0f * rotation.v.y * rotation.v.y;
	f32 zz2 = 2.0f * rotation.v.z * rotation.v.z;
	f32 xx2 = 2.0f * rotation.v.x * rotation.v.x;

	f32 xy2 = 2.0f * rotation.v.x * rotation.v.y;
	f32 xz2 = 2.0f * rotation.v.x * rotation.v.z;
	f32 yz2 = 2.0f * rotation.v.y * rotation.v.z;

	f32 sz = 2.0f * rotation.s * rotation.v.z;
	f32 sx = 2.0f * rotation.s * rotation.v.x;
	f32 sy = 2.0f * rotation.s * rotation.v.y;

	mMtx[0][0] = (1.0f - yy2 - zz2) * scale.x;
	mMtx[0][1] = (xy2 - sz) * scale.y;
	mMtx[0][2] = (xz2 + sy) * scale.z;

	mMtx[1][0] = (xy2 + sz) * scale.x;
	mMtx[1][1] = (1.0f - xx2 - zz2) * scale.y;
	mMtx[1][2] = (yz2 - sx) * scale.z;

	mMtx[2][0] = (xz2 - sy) * scale.x;
	mMtx[2][1] = (yz2 + sx) * scale.y;
	mMtx[2][2] = (1.0f - xx2 - yy2) * scale.z;

	mMtx[0][3] = translation.x;
	mMtx[1][3] = translation.y;
	mMtx[2][3] = translation.z;

	mMtx[3][0] = 0.0f;
	mMtx[3][1] = 0.0f;
	mMtx[3][2] = 0.0f;
	mMtx[3][3] = 1.0f;
}
