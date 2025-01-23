#include "nlib/Geometry.h"
#include "nlib/Math.h"
#include "Vector.h"
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
DEFINE_PRINT("nlibgeometry")

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
NAxisAngle4f::NAxisAngle4f()
{
	mAxis.construct(NVector3f(0.0f, 1.0f, 0.0f));
	mAngle = 0.0f;
}

/*
 * --INFO--
 * Address:	8011BC80
 * Size:	000058
 */
NAxisAngle4f::NAxisAngle4f(NVector3f& axis, f32 angle)
{
	construct(axis, angle);
}

/*
 * --INFO--
 * Address:	8011BCD8
 * Size:	000020
 */
void NAxisAngle4f::construct(NVector3f& axis, f32 angle)
{
	inputAxis(axis);
	setAngle(angle);
}

/*
 * --INFO--
 * Address:	8011BCF8
 * Size:	000080
 */
NMatrix4f::NMatrix4f()
{
	input(NMatrix4f(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NMatrix4f::NMatrix4f(Matrix4f& mat)
{
	construct(mat);
}

/*
 * --INFO--
 * Address:	8011BD78
 * Size:	000020
 */
void NMatrix4f::construct(Matrix4f& mat)
{
	input(mat);
}

/*
 * --INFO--
 * Address:	8011BD98
 * Size:	000070
 */
NMatrix4f::NMatrix4f(f32 x00, f32 x01, f32 x02, f32 x03, f32 x10, f32 x11, f32 x12, f32 x13, f32 x20, f32 x21, f32 x22, f32 x23, f32 x30,
                     f32 x31, f32 x32, f32 x33)
{
	set(x00, x01, x02, x03, x10, x11, x12, x13, x20, x21, x22, x23, x30, x31, x32, x33);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void NMatrix4f::construct(f32 x00, f32 x01, f32 x02, f32 x03, f32 x10, f32 x11, f32 x12, f32 x13, f32 x20, f32 x21, f32 x22, f32 x23,
                          f32 x30, f32 x31, f32 x32, f32 x33)
{
	set(x00, x01, x02, x03, x10, x11, x12, x13, x20, x21, x22, x23, x30, x31, x32, x33);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NMatrix4f::NMatrix4f(Mtx44 mtx)
{
	construct(mtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NMatrix4f::construct(Mtx44 mtx)
{
	input(mtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NMatrix4f::input(Mtx44 mtx)
{
	NMathf::copyArray44(mMtx, mtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NMatrix4f::output(Mtx44 mtx)
{
	NMathf::copyArray44(mtx, mMtx);
}

/*
 * --INFO--
 * Address:	8011BE08
 * Size:	000090
 */
void NMatrix4f::input(Matrix4f& mat)
{
	NMathf::copyArray44(this->mMtx, mat.mMtx);
}

/*
 * --INFO--
 * Address:	8011BE98
 * Size:	00006C
 */
void NMatrix4f::set(f32 x00, f32 x01, f32 x02, f32 x03, f32 x10, f32 x11, f32 x12, f32 x13, f32 x20, f32 x21, f32 x22, f32 x23, f32 x30,
                    f32 x31, f32 x32, f32 x33)
{
	mMtx[0][0] = x00;
	mMtx[0][1] = x01;
	mMtx[0][2] = x02;
	mMtx[0][3] = x03;

	mMtx[1][0] = x10;
	mMtx[1][1] = x11;
	mMtx[1][2] = x12;
	mMtx[1][3] = x13;

	mMtx[2][0] = x20;
	mMtx[2][1] = x21;
	mMtx[2][2] = x22;
	mMtx[2][3] = x23;

	mMtx[3][0] = x30;
	mMtx[3][1] = x31;
	mMtx[3][2] = x32;
	mMtx[3][3] = x33;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void NMatrix4f::setRow(int row, f32 x, f32 y, f32 z)
{
	mMtx[row][0] = x;
	mMtx[row][1] = y;
	mMtx[row][2] = z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::inputRow(int row, Vector3f& vec)
{
	setRow(row, vec.x, vec.y, vec.z);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NMatrix4f::inputRow(int row, Vector3f& vec, f32 trans)
{
	inputRow(row, vec);
	mMtx[row][3] = trans;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::outputRow(int row, Vector3f& outRow)
{
	outRow.set(mMtx[row][0], mMtx[row][1], mMtx[row][2]);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void NMatrix4f::inputRows(NVector3f& row0, NVector3f& row1, NVector3f& row2)
{
	inputRow(0, row0, 0.0f);
	inputRow(1, row1, 0.0f);
	inputRow(2, row2, 0.0f);
	inputRow(0, NVector3f(0.0f, 0.0f, 0.0f), 1.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000018
 */
void NMatrix4f::setCol(int col, f32 x, f32 y, f32 z)
{
	mMtx[0][col] = x;
	mMtx[1][col] = y;
	mMtx[2][col] = z;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NMatrix4f::inputCol(int col, Vector3f& input)
{
	setCol(col, input.x, input.y, input.z);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NMatrix4f::inputCol(int col, Vector3f& input, f32 trans)
{
	inputCol(col, input);
	mMtx[3][col] = trans;
}

/*
 * --INFO--
 * Address:	8011BF04
 * Size:	000024
 */
void NMatrix4f::outputCol(int col, Vector3f& output)
{
	output.set(mMtx[0][col], mMtx[1][col], mMtx[2][col]);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void NMatrix4f::inputCols(NVector3f& col0, NVector3f& col1, NVector3f& col2)
{
	inputCol(0, col0, 0.0f);
	inputCol(1, col1, 0.0f);
	inputCol(2, col2, 0.0f);
	inputCol(3, NVector3f(0.0f, 0.0f, 0.0f), 1.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NMatrix4f::mul(Matrix4f& mtx)
{
	multiply(mtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
void NMatrix4f::mul2(Matrix4f& mtx, Matrix4f& outMtx)
{
	multiplyTo(mtx, outMtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C8
 */
void NMatrix4f::scale(f32 scale)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mMtx[i][j] *= scale;
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000130
 */
void NMatrix4f::transpose()
{
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < i; j++) {
			f32 prev   = mMtx[i][j];
			mMtx[i][j] = mMtx[j][i];
			mMtx[j][i] = prev;
		}
	}
}

/*
 * --INFO--
 * Address:	8011BF28
 * Size:	000024
 */
void NMatrix4f::makeIdentRow(int row)
{
	mMtx[row][0] = 0.0f;
	mMtx[row][1] = 0.0f;
	mMtx[row][2] = 0.0f;
	mMtx[row][3] = 1.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NMatrix4f::println()
{
	for (int i = 0; i < 4; i++) {
		PRINT("|%f,%f,%f,%f|\n", mMtx[i][0], mMtx[i][1], mMtx[i][2], mMtx[i][3]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
NOrientation::NOrientation()
{
	input(NVector3f(0.0f, 0.0f, 1.0f), NVector3f(0.0f, 1.0f, 0.0f));
}

/*
 * --INFO--
 * Address:	8011BF4C
 * Size:	000050
 */
NOrientation::NOrientation(Vector3f& direction)
{
	construct(direction);
}

/*
 * --INFO--
 * Address:	8011BF9C
 * Size:	000078
 */
void NOrientation::construct(Vector3f& direction)
{
	input(direction, NVector3f(0.0f, 1.0f, 0.0f));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
NOrientation::NOrientation(Vector3f& direction, Vector3f& up)
{
	construct(direction, up);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NOrientation::construct(Vector3f& direction, Vector3f& up)
{
	input(direction, up);
}

/*
 * --INFO--
 * Address:	8011C014
 * Size:	0000D4
 */
void NOrientation::normalize()
{
	if (mUpVector.isParallel(mDirection)) {
		makeUp();
	}

	NVector3f& left = NVector3f();
	outputLeft(left);

	NTransform3D& transform = NTransform3D();

	NAxisAngle4f& axisAngle = NAxisAngle4f(left, NMathF::pi / 2.0f);

	transform.inputAxisAngle(axisAngle);
	mUpVector.input(mDirection);
	transform.transform(mUpVector);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NOrientation::transform(NTransform3D& transform)
{
	transform.transform(mDirection);
	transform.transform(mUpVector);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NOrientation::outputRight(NVector3f& outRight)
{
	outRight.cross(mDirection, mUpVector);
}

/*
 * --INFO--
 * Address:	8011C0E8
 * Size:	00004C
 */
void NOrientation::outputLeft(NVector3f& outLeft)
{
	outLeft.cross(mUpVector, mDirection);
}

/*
 * --INFO--
 * Address:	8011C134
 * Size:	000254
 */
void NOrientation::makeUp()
{
	NOrientation& orient = NOrientation(mDirection);

	if (!orient.mDirection.isParallel(NVector3f(0.0f, 1.0f, 0.0f))) {
		orient.inputUp(NVector3f(0.0f, 1.0f, 0.0f));

	} else if (!orient.mDirection.isParallel(NVector3f(0.0f, 0.0f, 1.0f))) {
		orient.inputUp(NVector3f(0.0f, 0.0f, 1.0f));

	} else {
		PRINT("?makeUp\n");
	}

	orient.normalize();
	mUpVector.input(orient.mUpVector);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000124
 */
void NOrientation::outputTransform(NTransform3D& transform)
{
	NVector3f& left = NVector3f();
	outputLeft(left);

	transform.inputCols(left, mUpVector, mDirection);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void NOrientation::inputTransform(NTransform3D& transform)
{
	transform.outputCol(1, mUpVector);
	transform.outputCol(2, mDirection);
	mUpVector.normalize();
	mDirection.normalize();
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000CC
 */
void NOrientation::outputRotation(NTransform3D& transform)
{
	NVector3f& left = NVector3f();
	outputLeft(left);

	transform.inputCol(0, left);
	transform.inputCol(1, mUpVector);
	transform.inputCol(2, mDirection);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NOrientation::inputRotation(NTransform3D& transform)
{
	transform.outputCol(1, mUpVector);
	transform.outputCol(1, mDirection);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NOrientation::println()
{
	PRINT("fore:");
	mDirection.println();
	PRINT("up:");
	mUpVector.println();
}

/*
 * --INFO--
 * Address:	8011C3A4
 * Size:	00003C
 */
NPolar3f::NPolar3f()
{
	set(1.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NPolar3f::NPolar3f(f32 rad, f32 inc, f32 azi)
{
	construct(rad, inc, azi);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NPolar3f::construct(f32 rad, f32 inc, f32 azi)
{
	set(rad, inc, azi);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NPolar3f::NPolar3f(NPolar3f& other)
{
	construct(other);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void NPolar3f::construct(NPolar3f& other)
{
	set(other.mRadius, other.mInclination, other.mAzimuth);
}

/*
 * --INFO--
 * Address:	8011C3E0
 * Size:	000030
 */
NPolar3f::NPolar3f(Vector3f& point)
{
	construct(point);
}

/*
 * --INFO--
 * Address:	8011C410
 * Size:	000020
 */
void NPolar3f::construct(Vector3f& point)
{
	input(point);
}

/*
 * --INFO--
 * Address:	8011C430
 * Size:	000010
 */
void NPolar3f::set(f32 radius, f32 inclination, f32 azimuth)
{
	mRadius      = radius;
	mInclination = inclination;
	mAzimuth     = azimuth;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NPolar3f::input(NPolar3f& other)
{
	set(other.mRadius, other.mInclination, other.mAzimuth);
}

/*
 * --INFO--
 * Address:	8011C440
 * Size:	0000A8
 */
void NPolar3f::input(Vector3f& point)
{
	set(point.length(), NMathF::atan2(NMathF::length(point.x, point.z), point.y), NMathF::atan2(point.x, point.z));
}

/*
 * --INFO--
 * Address:	8011C4E8
 * Size:	0000A4
 */
void NPolar3f::output(Vector3f& point)
{
	f32 sinInc = NMathF::sin(mInclination);
	f32 cosInc = NMathF::cos(mInclination);
	f32 sinAzi = NMathF::sin(mAzimuth);
	f32 cosAzi = NMathF::cos(mAzimuth);

	point.set(mRadius * sinInc * sinAzi, mRadius * cosInc, mRadius * sinInc * cosAzi);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NPolar3f::negate()
{
	set(mRadius, NMathF::pi - mInclination, NMathF::pi + mAzimuth);
	round();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NPolar3f::interpolate(NPolar3f& start, NPolar3f& end, f32 t)
{
	set(NMathF::interpolate(start.mRadius, end.mRadius, t), NMathF::interpolate(start.mInclination, end.mInclination, t),
	    NMathF::interpolate(start.mAzimuth, end.mAzimuth, t));
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NPolar3f::roundMeridian()
{
	mInclination = NMathF::roundAngle(mInclination);
	if (mInclination > NMathF::pi) {
		mInclination = 2.0f * NMathF::pi - mInclination;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
bool NPolar3f::clampMeridian(f32 angle)
{
	f32 complAngle = NMathF::pi - angle;
	if (mInclination < angle) {
		mInclination = angle;
		return true;
	}
	if (mInclination > complAngle) {
		mInclination = complAngle;
		return true;
	}

	return false;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NPolar3f::println()
{
	PRINT("(%f,%f,%f)\n", mRadius, mInclination, mAzimuth);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
NPosture2D::NPosture2D()
{
	mTranslation.construct(0.0f, 0.0f, 0.0f);
	mDirection = 0.0f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
NPosture2D::NPosture2D(Vector3f& trans, f32 dir)
{
	construct(trans, dir);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NPosture2D::construct(Vector3f& trans, f32 dir)
{
	mTranslation.input(trans);
	mDirection = dir;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NPosture2D::outputTransform(NTransform3D& transform)
{
	transform.inputTranslation(mTranslation);
	NAxisAngle4f& axisAngle = NAxisAngle4f();
	outputAxisAngle(axisAngle);
	transform.inputRotation(axisAngle);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000110
 */
void NPosture2D::outputInverseTransform(NTransform3D& transform)
{
	NTransform3D& trans1 = NTransform3D();
	NTransform3D& trans2 = NTransform3D();
	NVector3f& pos       = NVector3f(mTranslation);
	pos.negate();
	trans1.inputTranslation(pos);

	NAxisAngle4f& axisAngle = NAxisAngle4f();
	axisAngle.inputAxis(NVector3f(0.0f, 1.0f, 0.0f));
	axisAngle.setAngle(-mDirection);
	trans2.inputRotation(axisAngle);
	transform.mul2(trans1, trans2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000068
 */
void NPosture2D::outputAxisAngle(NAxisAngle4f& axisAngle)
{
	axisAngle.inputAxis(NVector3f(0.0f, 1.0f, 0.0f));
	axisAngle.setAngle(mDirection);
}

/*
 * --INFO--
 * Address:	8011C58C
 * Size:	000094
 */
void NPosture2D::readData(Stream& input)
{
	mTranslation.read(input);
	mDirection = input.readFloat();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000024
 */
void NPosture2D::println()
{
	PRINT("translation:");
	mTranslation.println();
	PRINT("direction:%f\n", mDirection);
}

/*
 * --INFO--
 * Address:	8011C620
 * Size:	0000A0
 */
NPosture3D::NPosture3D()
{
	mViewpoint.input(NVector3f(0.0f, 0.0f, 0.0f));
	mWatchpoint.input(NVector3f(0.0f, 0.0f, 1.0f));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
NPosture3D::NPosture3D(NPosture3D& other)
{
	construct(other);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
void NPosture3D::construct(NPosture3D& other)
{
	input(other);
}

/*
 * --INFO--
 * Address:	8011C6C0
 * Size:	000070
 */
NPosture3D::NPosture3D(Vector3f& view, Vector3f& watch)
{
	construct(view, watch);
}

/*
 * --INFO--
 * Address:	8011C730
 * Size:	000034
 */
void NPosture3D::construct(Vector3f& view, Vector3f& watch)
{
	mViewpoint.input(view);
	mWatchpoint.input(watch);
}

/*
 * --INFO--
 * Address:	8011C764
 * Size:	0000D4
 */
void NPosture3D::normalize()
{
	NVector3f& dir = NVector3f();
	outputRelative(dir);
	if (NMathF::isZero(dir.length())) {
		PRINT("?normalize:zero:");
		mWatchpoint.add(NVector3f(0.0f, 0.0f, 1.0f));
	}
}

/*
 * --INFO--
 * Address:	8011C838
 * Size:	000034
 */
void NPosture3D::outputRelative(NVector3f& dir)
{
	dir.sub2(mWatchpoint, mViewpoint);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NPosture3D::outputUnitVector(NVector3f& dir)
{
	outputRelative(dir);
	dir.normalize();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NPosture3D::transform(NTransform3D& transform)
{
	transform.transform(mViewpoint);
	transform.transform(mWatchpoint);
}

/*
 * --INFO--
 * Address:	8011C86C
 * Size:	000064
 */
void NPosture3D::translate(Vector3f& offset)
{
	mViewpoint.add(offset);
	mWatchpoint.add(offset);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000064
 */
void NPosture3D::rotate(NVector3f& p1, NPolar3f& p2)
{
	rotatePoint(mViewpoint, p1, p2);
	rotatePoint(mWatchpoint, p1, p2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001CC
 */
void NPosture3D::rotatePoint(NVector3f& p1, NVector3f& p2, NPolar3f& p3)
{
	NVector3f& tempVec = NVector3f();
	NPolar3f& tempPol  = NPolar3f();

	tempVec.sub2(p1, p2);

	tempPol.input(tempVec);
	tempPol.add(p3);
	tempPol.output(tempVec);

	p1.add2(p2, tempVec);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000070
 */
void NPosture3D::interpolate(NPosture3D& start, NPosture3D& end, f32 t)
{
	mViewpoint.interpolate(start.mViewpoint, end.mViewpoint, t);
	mWatchpoint.interpolate(start.mWatchpoint, end.mWatchpoint, t);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000D8
 */
void NPosture3D::input(NPosture2D& other2D)
{
	inputViewpoint(other2D.getTranslation());

	NVector3f& watch = NVector3f();
	watch.set(NMathF::sin(other2D.getDirection()), 0.0f, NMathF::cos(other2D.getDirection()));
	watch.add(mViewpoint);

	inputWatchpoint(watch);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NPosture3D::output(NPosture2D& out2D)
{
	out2D.inputTranslation(mViewpoint);
	NVector3f& dir = NVector3f();
	outputRelative(dir);
	out2D.setDirection(NMathF::atan2(dir.x, dir.z));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000078
 */
void NPosture3D::outputTransform(NPosture3D& p1, NTransform3D& outTransform)
{
	NTransform3D& temp = NTransform3D();
	outputInverseTransform(outTransform);
	p1.outputTransform(temp);
	outTransform.mul(temp);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0002A0
 */
void NPosture3D::outputTransform(NTransform3D& transform)
{
	transform.inputTranslation(mViewpoint);
	NVector3f& dir = NVector3f();
	dir.sub2(mWatchpoint, mViewpoint);
	dir.normalize();
	NOrientation& orient = NOrientation(dir);
	orient.normalize();
	orient.outputRotation(transform);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000418
 */
void NPosture3D::outputInverseTransform(NTransform3D& invTransform)
{
	NTransform3D& trans1 = NTransform3D();
	NTransform3D& trans2 = NTransform3D();

	NVector3f& pos = NVector3f(mViewpoint);
	pos.negate();

	trans1.inputTranslation(pos);

	NVector3f& dir = NVector3f();
	dir.sub2(mWatchpoint, mViewpoint);
	dir.normalize();

	NOrientation& orient = NOrientation(dir);
	orient.normalize();
	orient.outputRotation(trans2);

	trans2.transpose();
	invTransform.mul2(trans1, trans2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00010C
 */
void NPosture3D::inputTransform(NTransform3D& transform)
{
	transform.outputTranslation(mViewpoint);
	NOrientation& orient = NOrientation();
	orient.inputRotation(transform);
	mWatchpoint.add2(mViewpoint, orient.getFore());
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
f32 NPosture3D::calcDirection()
{
	NVector3f& dir = NVector3f();
	outputRelative(dir);
	return NMathF::atan2(dir.x, dir.z);
}

/*
 * --INFO--
 * Address:	8011C8D0
 * Size:	0000C4
 */
void NPosture3D::readData(Stream& input)
{
	mViewpoint.read(input);
	mWatchpoint.read(input);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000038
 */
void NPosture3D::println()
{
	mViewpoint.println();
	mWatchpoint.println();
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
NSpecialMatrix::NSpecialMatrix(int dim)
{
	construct(dim);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000008
 */
void NSpecialMatrix::construct(int dim)
{
	mDimension = dim;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
NLowerMatrix::NLowerMatrix(f32* values, int dim)
{
	construct(values, dim);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00000C
 */
void NLowerMatrix::construct(f32* values, int dim)
{
	NSpecialMatrix::construct(dim);
	mLower = values;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000060
 */
void NLowerMatrix::solve(NVector& inVec, NVector& outVec)
{
	outVec.mValues[0] = inVec.mValues[0];
	for (int i = 1; i < mDimension; i++) {
		outVec.mValues[i] = inVec.mValues[i] - mLower[i - 1] * outVec.mValues[i - 1];
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NLowerMatrix::println()
{
	for (int i = 0; i < mDimension - 1; i++) {
		PRINT("l[%d]:%f\n", i, mLower[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
NUpperMatrix::NUpperMatrix(f32* centreVals, f32* upperVals, int dim)
{
	construct(centreVals, upperVals, dim);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000010
 */
void NUpperMatrix::construct(f32* centreVals, f32* upperVals, int dim)
{
	NSpecialMatrix::construct(dim);
	mCentre = centreVals;
	mUpper  = upperVals;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000180
 */
void NUpperMatrix::solve(NVector& inVec, NVector& outVec)
{
	outVec.mValues[mDimension - 1] = inVec.mValues[mDimension - 1] / mCentre[mDimension - 1];

	for (int i = mDimension - 2; i >= 0; i--) {
		outVec.mValues[i] = (inVec.mValues[i] - mUpper[i] * outVec.mValues[i + 1]) / mCentre[i];
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000A4
 */
void NUpperMatrix::println()
{
	for (int i = 0; i < mDimension; i++) {
		PRINT("e[%d]:%f\n", i, mCentre[i]);
	}
	for (int i = 0; i < mDimension - 1; i++) {
		PRINT("u[%d]:%f\n", i, mUpper[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00006C
 */
LUMatrix::LUMatrix(f32* centreVals, f32* lowerVals, f32* upperVals, int dim)
{
	construct(centreVals, lowerVals, upperVals, dim);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void LUMatrix::construct(f32* centreVals, f32* lowerVals, f32* upperVals, int dim)
{
	NSpecialMatrix::construct(dim);
	mCentreVals = centreVals;
	mLowerVals  = lowerVals;
	mUpperVals  = upperVals;
	mLower.construct(mLowerVals, dim);
	mUpper.construct(mCentreVals, mUpperVals, dim);
}

/*
 * --INFO--
 * Address:	8011C994
 * Size:	000064
 */
void LUMatrix::setDimension(int dim)
{
	NSpecialMatrix::setDimension(dim);
	mLower.setDimension(dim);
	mUpper.setDimension(dim);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00022C
 */
void LUMatrix::solve(NVector& inVec, NVector& outVec)
{
	f32 vals[16];
	decompose();
	NVector& tmp = NVector(vals, mDimension);
	mLower.solve(inVec, tmp);
	mUpper.solve(tmp, outVec);
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B0
 */
void LUMatrix::decompose()
{
	mUpper.setCenter(0, mCentreVals[0]);
	for (int i = 1; i < mDimension; i++) {
		mLower.setLower(i, mLowerVals[i - 1] / mUpper.getCenter(i - 1));

		mUpper.setCenter(i, mCentreVals[i] - mLower.getLower(i) * mUpperVals[i - 1]);
	}
	for (int i = 0; i < mDimension - 1; i++) {
		mUpper.setUpper(i, mUpperVals[i]);
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
void LUMatrix::println()
{
	for (int i = 0; i < mDimension; i++) {
		PRINT("e[%d]:%f\n", i, mCentreVals[i]);
	}
	for (int i = 0; i < mDimension - 1; i++) {
		PRINT("l[%d]:%f\n", i, mLowerVals[i]);
	}
	for (int i = 0; i < mDimension - 1; i++) {
		PRINT("u[%d]:%f\n", i, mUpperVals[i]);
	}
}

/*
 * --INFO--
 * Address:	8011CA00
 * Size:	000080
 */
NTransform3D::NTransform3D()
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
NTransform3D::NTransform3D(NMatrix4f& mtx)
{
	construct(mtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
void NTransform3D::construct(NMatrix4f& mtx)
{
	construct(mtx);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000090
 */
void NTransform3D::translate(Vector3f& offset)
{
	NVector3f& trans = NVector3f();
	outputTranslation(trans);
	trans.add(offset);
	inputTranslation(trans);
}

/*
 * --INFO--
 * Address:	8011CB08
 * Size:	00019C
 */
void NTransform3D::rotate(Vector3f& point)
{
	NTransform3D& rotation = NTransform3D();
	outputRotation(rotation);
	rotation.rotate(point);
	/*
	.loc_0x0:
	  mflr      r0
	  stw       r0, 0x4(r1)
	  stwu      r1, -0x220(r1)
	  stw       r31, 0x21C(r1)
	  addi      r31, r3, 0
	  addi      r3, r1, 0x14C
	  stw       r30, 0x218(r1)
	  stw       r29, 0x214(r1)
	  addi      r29, r4, 0
	  lfs       f2, -0x5FF0(r2)
	  stfs      f2, 0x8(r1)
	  fmr       f3, f2
	  fmr       f4, f2
	  stfs      f2, 0xC(r1)
	  fmr       f5, f2
	  fmr       f7, f2
	  lfs       f1, -0x5FEC(r2)
	  fmr       f8, f2
	  stfs      f1, 0x10(r1)
	  fmr       f6, f1
	  stfs      f2, 0x14(r1)
	  stfs      f2, 0x18(r1)
	  stfs      f2, 0x1C(r1)
	  stfs      f2, 0x20(r1)
	  stfs      f1, 0x24(r1)
	  bl        -0xCD4
	  addi      r3, r1, 0x1CC
	  addi      r4, r1, 0x14C
	  bl        -0xF8
	  addi      r30, r1, 0x1CC
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        0x16C
	  addi      r3, r1, 0xCC
	  bl        -0xDDB74
	  lfs       f2, -0x5FF0(r2)
	  addi      r3, r1, 0xCC
	  stfs      f2, 0x8(r1)
	  fmr       f3, f2
	  fmr       f4, f2
	  stfs      f2, 0xC(r1)
	  fmr       f5, f2
	  fmr       f7, f2
	  lfs       f1, -0x5FEC(r2)
	  fmr       f8, f2
	  stfs      f1, 0x10(r1)
	  fmr       f6, f1
	  stfs      f2, 0x14(r1)
	  stfs      f2, 0x18(r1)
	  stfs      f2, 0x1C(r1)
	  stfs      f2, 0x20(r1)
	  stfs      f1, 0x24(r1)
	  bl        -0xD40
	  addi      r3, r1, 0x18C
	  addi      r4, r1, 0xCC
	  bl        -0x164
	  addi      r31, r1, 0x18C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x100
	  addi      r3, r1, 0x10C
	  bl        -0xDDBE0
	  lfs       f2, -0x5FF0(r2)
	  addi      r3, r1, 0x4C
	  stfs      f2, 0x8(r1)
	  fmr       f3, f2
	  fmr       f4, f2
	  stfs      f2, 0xC(r1)
	  fmr       f5, f2
	  fmr       f7, f2
	  lfs       f1, -0x5FEC(r2)
	  fmr       f8, f2
	  stfs      f1, 0x10(r1)
	  fmr       f6, f1
	  stfs      f2, 0x14(r1)
	  stfs      f2, 0x18(r1)
	  stfs      f2, 0x1C(r1)
	  stfs      f2, 0x20(r1)
	  stfs      f1, 0x24(r1)
	  bl        -0xEAC
	  addi      r4, r3, 0
	  addi      r3, r1, 0x10C
	  bl        -0xE48
	  addi      r30, r1, 0x10C
	  addi      r3, r31, 0
	  addi      r4, r30, 0
	  bl        0x94
	  addi      r3, r1, 0x8C
	  bl        -0xF70
	  addi      r31, r1, 0x8C
	  addi      r3, r30, 0
	  addi      r4, r31, 0
	  bl        0x7C
	  addi      r3, r31, 0
	  addi      r4, r29, 0
	  bl        .loc_0x0
	  lwz       r0, 0x224(r1)
	  lwz       r31, 0x21C(r1)
	  lwz       r30, 0x218(r1)
	  lwz       r29, 0x214(r1)
	  addi      r1, r1, 0x220
	  mtlr      r0
	  blr
	*/
}

/*
 * --INFO--
 * Address:	8011CCA4
 * Size:	00002C
 */
void NTransform3D::transform(Vector3f& point)
{
	point.multMatrix(*this);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void NTransform3D::transform(Vector3f& p1, Vector3f& p2)
{
	p2 = p1;
	transform(p2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000184
 */
void NTransform3D::transform(NVector& vec)
{
	f32 vals[4];
	NVector tmp(vals, 4);
	tmp.input(vec);
	for (int i = 0; i < 4; i++) {
		vec.mValues[i] = 0.0f;
		for (int j = 0; j < 4; j++) {
			vec.mValues[i] += tmp.mValues[j] * mMtx[i][j];
		}
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00018C
 */
void NTransform3D::transform(NVector& p1, NVector& p2)
{
	p2.input(p1);
	transform(p2);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000094
 */
void NTransform3D::inputVector(Vector3f& vec)
{
	makeIdentity();
	inputTranslation(vec);
}

/*
 * --INFO--
 * Address:	8011CCD0
 * Size:	000024
 */
void NTransform3D::inputAxisAngle(NAxisAngle4f& axisAngle)
{
	makeRotate(axisAngle.getAxis(), axisAngle.getAngle());
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NTransform3D::inputTranslation(Vector3f& trans)
{
	inputCol(3, trans);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00001C
 */
void NTransform3D::outputTranslation(Vector3f& trans)
{
	outputCol(3, trans);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
void NTransform3D::inputRotation(Matrix4f& rotMtx)
{
	for (int i = 0; i < 3; i++) {
		setRow(i, rotMtx.mMtx[i][0], rotMtx.mMtx[i][1], rotMtx.mMtx[i][2]);
	}
}

/*
 * --INFO--
 * Address:	8011CCF4
 * Size:	0000CC
 */
void NTransform3D::outputRotation(Matrix4f& rotMtx)
{
	NVector3f& row = NVector3f();
	for (int i = 0; i < 3; i++) {
		outputRow(i, row);
		rotMtx.mMtx[i][0] = row.x;
		rotMtx.mMtx[i][1] = row.y;
		rotMtx.mMtx[i][2] = row.z;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E4
 */
void NTransform3D::inputRotation(NAxisAngle4f& axisAngle)
{
	NTransform3D& trans = NTransform3D();
	trans.inputAxisAngle(axisAngle);
	inputRotation(trans);
}

/*
 * --INFO--
 * Address:	8011CDC0
 * Size:	000010
 */
NVector::NVector()
{
	mValues = nullptr;
	mSize   = 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NVector::NVector(f32* values, int size)
{
	construct(values, size);
}

/*
 * --INFO--
 * Address:	8011CDD0
 * Size:	000028
 */
void NVector::construct(f32* values, int size)
{
	mValues = values;
	mSize   = size;
	makeZero();
}

/*
 * --INFO--
 * Address:	8011CDF8
 * Size:	000030
 */
void NVector::makeZero()
{
	for (int i = 0; i < mSize; i++) {
		mValues[i] = 0.0f;
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
void NVector::add(NVector&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000118
 */
f32 NVector::dot(NVector&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void NVector::input(NVector&)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
void NVector::println()
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void NVector3f::printVector3f(Vector3f& vec)
{
	NVector3f(vec).print();
}

/*
 * --INFO--
 * Address:	8011CE28
 * Size:	00002C
 */
void NVector3f::printlnVector3f(Vector3f& vec)
{
	NVector3f(vec).println();
}

/*
 * --INFO--
 * Address:	8011CE54
 * Size:	00002C
 */
NVector3f::NVector3f()
{
	set(0.0f, 0.0f, 0.0f);
}

/*
 * --INFO--
 * Address:	8011CE80
 * Size:	000040
 */
NVector3f::NVector3f(Vector3f& vec)
{
	construct(vec);
}

/*
 * --INFO--
 * Address:	8011CEC0
 * Size:	00001C
 */
void NVector3f::construct(Vector3f& vec)
{
	set(vec.x, vec.y, vec.z);
}

/*
 * --INFO--
 * Address:	8011CEDC
 * Size:	000040
 */
NVector3f::NVector3f(f32 x, f32 y, f32 z)
{
	construct(x, y, z);
}

/*
 * --INFO--
 * Address:	8011CF1C
 * Size:	000010
 */
void NVector3f::construct(f32 x, f32 y, f32 z)
{
	set(x, y, z);
}

/*
 * --INFO--
 * Address:	8011CF2C
 * Size:	000040
 */
NVector3f::NVector3f(Vector3f& start, Vector3f& end)
{
	construct(start, end);
}

/*
 * --INFO--
 * Address:	8011CF6C
 * Size:	000034
 */
void NVector3f::construct(Vector3f& start, Vector3f& end)
{
	set(end.x - start.x, end.y - start.y, end.z - start.z);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000054
 */
void NVector3f::interpolate(Vector3f& start, Vector3f& end, f32 t)
{
	set(NMathF::interpolate(start.x, end.x, t), NMathF::interpolate(start.y, end.y, t), NMathF::interpolate(start.z, end.z, t));
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000B4
 */
bool NVector3f::isZero()
{
	return (NMathF::isZero(x) && NMathF::isZero(y) && NMathF::isZero(z));
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F0
 */
bool NVector3f::equals(Vector3f& vec)
{
	return NVector3f(*this, vec).isZero();
}

/*
 * --INFO--
 * Address:	........
 * Size:	000058
 */
bool NVector3f::isVertical(Vector3f& vec)
{
	return NMathF::isZero(dot(vec));
}

/*
 * --INFO--
 * Address:	8011CFA0
 * Size:	000074
 */
bool NVector3f::isParallel(Vector3f& vec)
{
	return NMathF::equals(NMathf::absolute(dot(vec)), 1.0f);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000144
 */
void NVector3f::makeUnitVector(Vector3f& start, Vector3f& end)
{
	sub2(end, start);
	f32 dist = length();
	if (NMathF::isPositive(dist)) {
		normalize();
	} else {
		input(NVector3f(0.0f, 0.0f, 1.0f));
	}
}

/*
 * --INFO--
 * Address:	........
 * Size:	000088
 */
void NVector3f::outputQuat(f32 theta, Quat& q)
{
	f32 scale = NMathF::sin(theta / 2.0f);
	q.set(scale * x, scale * y, scale * z, NMathF::cos(theta / 2.0f));
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000E0
 */
f32 NVector3f::calcAngle(NVector3f& other)
{
	f32 proj = dot(other);
	if (proj > 1.0f) {
		proj = 1.0f;
	}
	if (proj < -1.0f) {
		proj = -1.0f;
	}

	return NMathF::roundAngle(proj); // idk which function this is
	                                 // UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000098
 */
f32 NVector3f::calcLargerAngle(NVector3f& other)
{
	return TAU - calcAngle(other);
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000004
 */
void NVector3f::print()
{
	PRINT("(%f,%f,%f)", x, y, z);
}

/*
 * --INFO--
 * Address:	8011D014
 * Size:	000004
 */
void NVector3f::println()
{
	PRINT("(%f,%f,%f)\n", x, y, z);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000028
 */
void NVector3f::normalizeByLength(f32 length)
{
	x /= length;
	y /= length;
	z /= length;
}

/*
 * --INFO--
 * Address:	8011D018
 * Size:	0000E8
 */
bool NVector3f::normalizeCheck()
{
	f32 len = length();
	if (NMathF::isZero(len)) {
		return false;
	}

	x /= len;
	y /= len;
	z /= len;
	return true;
}

/*
 * --INFO--
 * Address:	8011D100
 * Size:	0000DC
 */
void NVector3f::normalize()
{
	f32 len = length();
	if (NMathF::isZero(len)) {
		PRINT("!normalize:zero:%f\n", len);
		return;
	}

	x /= len;
	y /= len;
	z /= len;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00003C
 */
f32 NAlpha::fadeInValue(f32 x)
{
	f32 val = sinf(x * (NMathF::pi / 2.0f) + (NMathF::pi / 2.0f));
	return 1.0f - val;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
f32 NAlpha::fadeOutValue(f32 x)
{
	return sinf(x * (NMathF::pi / 2));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
f32 NAlpha::fadeInOutValue(f32 x)
{
	if (x < 0.5f) {
		return 0.5f * fadeInValue(2.0f * x);
	}
	return fadeOutValue(2.0f * (x - 0.5f)) * 0.5f + 0.5f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000080
 */
f32 NAlpha::fadeOutInValue(f32 x)
{
	if (x < 0.5f) {
		return fadeOutValue(2.0f * x) * 0.5f;
	}

	return fadeInValue(2.0f * (x - 0.5f)) * 0.5f + 0.5f;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000030
 */
NAlpha::NAlpha()
{
	mOffset = 0.0f;
	mScale  = 1.0f;
	mMode   = 0;
	mValue  = mOffset;
}

/*
 * --INFO--
 * Address:	8011D1DC
 * Size:	00000C
 */
void NAlpha::reset()
{
	mValue = mOffset;
}

/*
 * --INFO--
 * Address:	8011D1E8 (1004BE90 in plugPiki)
 * Size:	000198
 */
f32 NAlpha::getValue(f32 input)
{
	// If the scale is very small, set it to 1.0f
	if (NMathF::isZero(mScale)) {
		PRINT("?isZero(period)\n");
		mScale = 1.0f;
	}

	// Normalise the input value to the range [mOffset, mOffset + mScale]
	f32 normalisedValue = (input - mOffset) / mScale;

	switch (mMode) {
	case NAlphaMode::Linear:
		return normalisedValue;
	case NAlphaMode::FadeIn:
		return fadeInValue(normalisedValue);
	case NAlphaMode::FadeOut:
		return fadeOutValue(normalisedValue);
	case NAlphaMode::FadeInOut:
		return fadeInOutValue(normalisedValue);
	case NAlphaMode::FadeOutIn:
		return fadeOutInValue(normalisedValue);
	default:
		return normalisedValue;
	}
}

/*
 * --INFO--
 * Address:	8011D380
 * Size:	00007C
 */
void NAlpha::readData(Stream& input)
{
	mOffset = input.readFloat();
	mScale  = input.readFloat();
	mMode   = input.readByte();
}
