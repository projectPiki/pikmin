#include "DebugLog.h"
#include "Vector.h"
#include "nlib/Geometry.h"
#include "nlib/Math.h"

/**
 * @todo: Documentation
 * @note UNUSED Size: 00009C
 */
DEFINE_ERROR(__LINE__) // Never used in the DLL

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F4
 */
DEFINE_PRINT("nlibgeometry")

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
NAxisAngle4f::NAxisAngle4f()
{
	mAxis.construct(NVector3f(0.0f, 1.0f, 0.0f));
	mAngle = 0.0f;
}

/**
 * @todo: Documentation
 */
NAxisAngle4f::NAxisAngle4f(immut NVector3f& axis, f32 angle)
{
	construct(axis, angle);
}

/**
 * @todo: Documentation
 */
void NAxisAngle4f::construct(immut NVector3f& axis, f32 angle)
{
	inputAxis(axis);
	setAngle(angle);
}

/**
 * @todo: Documentation
 */
NMatrix4f::NMatrix4f()
{
	input(NMatrix4f(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
NMatrix4f::NMatrix4f(immut Matrix4f& mat)
{
	construct(mat);
}

/**
 * @todo: Documentation
 */
void NMatrix4f::construct(immut Matrix4f& mat)
{
	input(mat);
}

/**
 * @todo: Documentation
 */
NMatrix4f::NMatrix4f(f32 x00, f32 x01, f32 x02, f32 x03, f32 x10, f32 x11, f32 x12, f32 x13, f32 x20, f32 x21, f32 x22, f32 x23, f32 x30,
                     f32 x31, f32 x32, f32 x33)
{
	set(x00, x01, x02, x03, x10, x11, x12, x13, x20, x21, x22, x23, x30, x31, x32, x33);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000060
 */
void NMatrix4f::construct(f32 x00, f32 x01, f32 x02, f32 x03, f32 x10, f32 x11, f32 x12, f32 x13, f32 x20, f32 x21, f32 x22, f32 x23,
                          f32 x30, f32 x31, f32 x32, f32 x33)
{
	set(x00, x01, x02, x03, x10, x11, x12, x13, x20, x21, x22, x23, x30, x31, x32, x33);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
NMatrix4f::NMatrix4f(immut Mtx44 mtx)
{
	construct(mtx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000020
 */
void NMatrix4f::construct(immut Mtx44 mtx)
{
	input(mtx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000090
 */
void NMatrix4f::input(immut Mtx44 mtx)
{
	NMathf::copyArray44(mMtx, mtx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000090
 */
void NMatrix4f::output(Mtx44 mtx) immut
{
	NMathf::copyArray44(mtx, mMtx);
}

/**
 * @todo: Documentation
 */
void NMatrix4f::input(immut Matrix4f& mat)
{
	NMathf::copyArray44(this->mMtx, mat.mMtx);
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 000018
 */
void NMatrix4f::setRow(int row, f32 x, f32 y, f32 z)
{
	mMtx[row][0] = x;
	mMtx[row][1] = y;
	mMtx[row][2] = z;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void NMatrix4f::inputRow(int row, immut Vector3f& vec)
{
	setRow(row, vec.x, vec.y, vec.z);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028
 */
void NMatrix4f::inputRow(int row, immut Vector3f& vec, f32 trans)
{
	inputRow(row, vec);
	mMtx[row][3] = trans;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void NMatrix4f::outputRow(int row, Vector3f& outRow) immut
{
	outRow.set(mMtx[row][0], mMtx[row][1], mMtx[row][2]);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000B0
 */
void NMatrix4f::inputRows(immut NVector3f& row0, immut NVector3f& row1, immut NVector3f& row2)
{
	inputRow(0, row0, 0.0f);
	inputRow(1, row1, 0.0f);
	inputRow(2, row2, 0.0f);
	inputRow(0, NVector3f(0.0f, 0.0f, 0.0f), 1.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000018
 */
void NMatrix4f::setCol(int col, f32 x, f32 y, f32 z)
{
	mMtx[0][col] = x;
	mMtx[1][col] = y;
	mMtx[2][col] = z;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void NMatrix4f::inputCol(int col, immut Vector3f& input)
{
	setCol(col, input.x, input.y, input.z);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028
 */
void NMatrix4f::inputCol(int col, immut Vector3f& input, f32 trans)
{
	inputCol(col, input);
	mMtx[3][col] = trans;
}

/**
 * @todo: Documentation
 */
void NMatrix4f::outputCol(int col, Vector3f& output) immut
{
	output.set(mMtx[0][col], mMtx[1][col], mMtx[2][col]);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000B0
 */
void NMatrix4f::inputCols(immut NVector3f& col0, immut NVector3f& col1, immut NVector3f& col2)
{
	inputCol(0, col0, 0.0f);
	inputCol(1, col1, 0.0f);
	inputCol(2, col2, 0.0f);
	inputCol(3, NVector3f(0.0f, 0.0f, 0.0f), 1.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000020
 */
void NMatrix4f::mul(immut Matrix4f& mtx)
{
	multiply(mtx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
void NMatrix4f::mul2(immut Matrix4f& mtx, Matrix4f& outMtx) immut
{
	multiplyTo(mtx, outMtx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000C8
 */
void NMatrix4f::scale(f32 scale)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mMtx[i][j] *= scale;
		}
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000130
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

/**
 * @todo: Documentation
 */
void NMatrix4f::makeIdentRow(int row)
{
	mMtx[row][0] = 0.0f;
	mMtx[row][1] = 0.0f;
	mMtx[row][2] = 0.0f;
	mMtx[row][3] = 1.0f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NMatrix4f::println() immut
{
	for (int i = 0; i < 4; i++) {
		PRINT_NAKATA("|%f,%f,%f,%f|\n", mMtx[i][0], mMtx[i][1], mMtx[i][2], mMtx[i][3]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000090
 */
NOrientation::NOrientation()
{
	input(NVector3f(0.0f, 0.0f, 1.0f), NVector3f(0.0f, 1.0f, 0.0f));
}

/**
 * @todo: Documentation
 */
NOrientation::NOrientation(immut Vector3f& direction)
{
	construct(direction);
}

/**
 * @todo: Documentation
 */
void NOrientation::construct(immut Vector3f& direction)
{
	input(direction, NVector3f(0.0f, 1.0f, 0.0f));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000060
 */
NOrientation::NOrientation(immut Vector3f& direction, immut Vector3f& up)
{
	construct(direction, up);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034
 */
void NOrientation::construct(immut Vector3f& direction, immut Vector3f& up)
{
	input(direction, up);
}

/**
 * @todo: Documentation
 */
void NOrientation::normalize()
{
	if (mUpVector.isParallel(mDirection)) {
		makeUp();
	}

	NVector3f NRef left = NVector3f();
	outputLeft(left);

	NTransform3D NRef transform = NTransform3D();

	NAxisAngle4f NRef axisAngle = NAxisAngle4f(left, NMathF::pi / 2.0f);

	transform.inputAxisAngle(axisAngle);
	mUpVector.input(mDirection);
	transform.transform(mUpVector);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void NOrientation::transform(immut NTransform3D& transform)
{
	transform.transform(mDirection);
	transform.transform(mUpVector);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void NOrientation::outputRight(NVector3f& outRight) immut
{
	outRight.cross(mDirection, mUpVector);
}

/**
 * @todo: Documentation
 */
void NOrientation::outputLeft(NVector3f& outLeft) immut
{
	outLeft.cross(mUpVector, mDirection);
}

/**
 * @todo: Documentation
 */
void NOrientation::makeUp()
{
	NOrientation NRef orient = NOrientation(mDirection);

	if (!orient.mDirection.isParallel(NVector3f(0.0f, 1.0f, 0.0f))) {
		orient.inputUp(NVector3f(0.0f, 1.0f, 0.0f));

	} else if (!orient.mDirection.isParallel(NVector3f(0.0f, 0.0f, 1.0f))) {
		orient.inputUp(NVector3f(0.0f, 0.0f, 1.0f));

	} else {
		PRINT_NAKATA("?makeUp\n");
	}

	orient.normalize();
	mUpVector.input(orient.mUpVector);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000124
 */
void NOrientation::outputTransform(NTransform3D& transform) immut
{
	NVector3f NRef left = NVector3f();
	outputLeft(left);

	transform.inputCols(left, mUpVector, mDirection);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000068
 */
void NOrientation::inputTransform(immut NTransform3D& transform)
{
	transform.outputCol(1, mUpVector);
	transform.outputCol(2, mDirection);
	mUpVector.normalize();
	mDirection.normalize();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000CC
 */
void NOrientation::outputRotation(NTransform3D& transform) immut
{
	NVector3f NRef left = NVector3f();
	outputLeft(left);

	transform.inputCol(0, left);
	transform.inputCol(1, mUpVector);
	transform.inputCol(2, mDirection);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034
 */
void NOrientation::inputRotation(immut NTransform3D& transform)
{
	transform.outputCol(1, mUpVector);
	transform.outputCol(1, mDirection);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034
 */
void NOrientation::println() immut
{
	PRINT_NAKATA("fore:");
	mDirection.println();
	PRINT_NAKATA("up:");
	mUpVector.println();
}

/**
 * @todo: Documentation
 */
NPolar3f::NPolar3f()
{
	set(1.0f, 0.0f, 0.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
NPolar3f::NPolar3f(f32 rad, f32 inc, f32 azi)
{
	construct(rad, inc, azi);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000020
 */
void NPolar3f::construct(f32 rad, f32 inc, f32 azi)
{
	set(rad, inc, azi);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
NPolar3f::NPolar3f(immut NPolar3f& other)
{
	construct(other);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C
 */
void NPolar3f::construct(immut NPolar3f& other)
{
	set(other.mRadius, other.mInclination, other.mAzimuth);
}

/**
 * @todo: Documentation
 */
NPolar3f::NPolar3f(immut Vector3f& point)
{
	construct(point);
}

/**
 * @todo: Documentation
 */
void NPolar3f::construct(immut Vector3f& point)
{
	input(point);
}

/**
 * @todo: Documentation
 */
void NPolar3f::set(f32 radius, f32 inclination, f32 azimuth)
{
	mRadius      = radius;
	mInclination = inclination;
	mAzimuth     = azimuth;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
void NPolar3f::input(immut NPolar3f& other)
{
	set(other.mRadius, other.mInclination, other.mAzimuth);
}

/**
 * @todo: Documentation
 */
void NPolar3f::input(immut Vector3f& point)
{
	set(point.length(), NMathF::atan2(NMathF::length(point.x, point.z), point.y), NMathF::atan2(point.x, point.z));
}

/**
 * @todo: Documentation
 */
void NPolar3f::output(Vector3f& point) immut
{
	f32 sinInc = NMathF::sin(mInclination);
	f32 cosInc = NMathF::cos(mInclination);
	f32 sinAzi = NMathF::sin(mAzimuth);
	f32 cosAzi = NMathF::cos(mAzimuth);

	point.set(mRadius * sinInc * sinAzi, mRadius * cosInc, mRadius * sinInc * cosAzi);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
void NPolar3f::negate()
{
	set(mRadius, NMathF::pi - mInclination, NMathF::pi + mAzimuth);
	round();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054
 */
void NPolar3f::interpolate(immut NPolar3f& start, immut NPolar3f& end, f32 t)
{
	set(NMathF::interpolate(start.mRadius, end.mRadius, t), NMathF::interpolate(start.mInclination, end.mInclination, t),
	    NMathF::interpolate(start.mAzimuth, end.mAzimuth, t));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00005C
 */
void NPolar3f::roundMeridian()
{
	mInclination = NMathF::roundAngle(mInclination);
	if (mInclination > NMathF::pi) {
		mInclination = 2.0f * NMathF::pi - mInclination;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NPolar3f::println() immut
{
	PRINT_NAKATA("(%f,%f,%f)\n", mRadius, mInclination, mAzimuth);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00005C
 */
NPosture2D::NPosture2D()
{
	mTranslation.construct(0.0f, 0.0f, 0.0f);
	mDirection = 0.0f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000068
 */
NPosture2D::NPosture2D(immut Vector3f& trans, f32 dir)
{
	construct(trans, dir);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000020
 */
void NPosture2D::construct(immut Vector3f& trans, f32 dir)
{
	mTranslation.input(trans);
	mDirection = dir;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000094
 */
void NPosture2D::outputTransform(NTransform3D& transform)
{
	transform.inputTranslation(mTranslation);
	NAxisAngle4f NRef axisAngle = NAxisAngle4f();
	outputAxisAngle(axisAngle);
	transform.inputRotation(axisAngle);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000110
 */
void NPosture2D::outputInverseTransform(NTransform3D& transform)
{
	NTransform3D NRef trans1 = NTransform3D();
	NTransform3D NRef trans2 = NTransform3D();
	NVector3f NRef pos       = NVector3f(mTranslation);
	pos.negate();
	trans1.inputTranslation(pos);

	NAxisAngle4f NRef axisAngle = NAxisAngle4f();
	axisAngle.inputAxis(NVector3f(0.0f, 1.0f, 0.0f));
	axisAngle.setAngle(-mDirection);
	trans2.inputRotation(axisAngle);
	transform.mul2(trans1, trans2);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000068
 */
void NPosture2D::outputAxisAngle(NAxisAngle4f& axisAngle)
{
	axisAngle.inputAxis(NVector3f(0.0f, 1.0f, 0.0f));
	axisAngle.setAngle(mDirection);
}

/**
 * @todo: Documentation
 */
void NPosture2D::readData(Stream& input)
{
	mTranslation.read(input);
	mDirection = input.readFloat();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000024
 */
void NPosture2D::println() immut
{
	PRINT_NAKATA("translation:");
	mTranslation.println();
	PRINT_NAKATA("direction:%f\n", mDirection);
}

/**
 * @todo: Documentation
 */
NPosture3D::NPosture3D()
{
	mViewpoint.input(NVector3f(0.0f, 0.0f, 0.0f));
	mWatchpoint.input(NVector3f(0.0f, 0.0f, 1.0f));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000060
 */
NPosture3D::NPosture3D(immut NPosture3D& other)
{
	construct(other);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00005C
 */
void NPosture3D::construct(immut NPosture3D& other)
{
	input(other);
}

/**
 * @todo: Documentation
 */
NPosture3D::NPosture3D(immut Vector3f& view, immut Vector3f& watch)
{
	construct(view, watch);
}

/**
 * @todo: Documentation
 */
void NPosture3D::construct(immut Vector3f& view, immut Vector3f& watch)
{
	mViewpoint.input(view);
	mWatchpoint.input(watch);
}

/**
 * @todo: Documentation
 */
void NPosture3D::normalize()
{
	NVector3f NRef dir = NVector3f();
	outputRelative(dir);
	if (NMathF::isZero(dir.length())) {
		PRINT_NAKATA("?normalize:zero:" MISSING_NEWLINE);
		mWatchpoint.add(NVector3f(0.0f, 0.0f, 1.0f));
	}
}

/**
 * @todo: Documentation
 */
void NPosture3D::outputRelative(NVector3f& dir) immut
{
	dir.sub2(mWatchpoint, mViewpoint);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054
 */
void NPosture3D::outputUnitVector(NVector3f& dir) immut
{
	outputRelative(dir);
	dir.normalize();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void NPosture3D::transform(immut NTransform3D& transform)
{
	transform.transform(mViewpoint);
	transform.transform(mWatchpoint);
}

/**
 * @todo: Documentation
 */
void NPosture3D::translate(immut Vector3f& offset)
{
	mViewpoint.add(offset);
	mWatchpoint.add(offset);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000064
 */
void NPosture3D::rotate(immut NVector3f& pivot, immut NPolar3f& rotationDelta)
{
	rotatePoint(mViewpoint, pivot, rotationDelta);
	rotatePoint(mWatchpoint, pivot, rotationDelta);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0001CC
 */
void NPosture3D::rotatePoint(NVector3f& point, immut NVector3f& pivot, immut NPolar3f& rotationDelta) immut
{
	NVector3f NRef tempVec = NVector3f();
	NPolar3f NRef tempPol  = NPolar3f();

	tempVec.sub2(point, pivot);

	tempPol.input(tempVec);
	tempPol.add(rotationDelta);
	tempPol.output(tempVec);

	point.add2(pivot, tempVec);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000070
 */
void NPosture3D::interpolate(immut NPosture3D& start, immut NPosture3D& end, f32 t)
{
	mViewpoint.interpolate(start.mViewpoint, end.mViewpoint, t);
	mWatchpoint.interpolate(start.mWatchpoint, end.mWatchpoint, t);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000D8
 */
void NPosture3D::input(immut NPosture2D& other2D)
{
	inputViewpoint(other2D.getTranslation());

	NVector3f NRef watch = NVector3f();
	watch.set(NMathF::sin(other2D.getDirection()), 0.0f, NMathF::cos(other2D.getDirection()));
	watch.add(mViewpoint);

	inputWatchpoint(watch);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000094
 */
void NPosture3D::output(NPosture2D& out2D) immut
{
	out2D.inputTranslation(mViewpoint);
	NVector3f NRef dir = NVector3f();
	outputRelative(dir);
	out2D.setDirection(NMathF::atan2(dir.x, dir.z));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000078
 */
void NPosture3D::outputTransform(immut NPosture3D& otherPosture, NTransform3D& outTransform) immut
{
	NTransform3D NRef temp = NTransform3D();
	outputInverseTransform(outTransform);
	otherPosture.outputTransform(temp);
	outTransform.mul(temp);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0002A0
 */
void NPosture3D::outputTransform(NTransform3D& transform) immut
{
	transform.inputTranslation(mViewpoint);
	NVector3f NRef dir = NVector3f();
	dir.sub2(mWatchpoint, mViewpoint);
	dir.normalize();
	NOrientation NRef orient = NOrientation(dir);
	orient.normalize();
	orient.outputRotation(transform);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000418
 */
void NPosture3D::outputInverseTransform(NTransform3D& invTransform) immut
{
	NTransform3D NRef trans1 = NTransform3D();
	NTransform3D NRef trans2 = NTransform3D();

	NVector3f NRef pos = NVector3f(mViewpoint);
	pos.negate();

	trans1.inputTranslation(pos);

	NVector3f NRef dir = NVector3f();
	dir.sub2(mWatchpoint, mViewpoint);
	dir.normalize();

	NOrientation NRef orient = NOrientation(dir);
	orient.normalize();
	orient.outputRotation(trans2);

	trans2.transpose();
	invTransform.mul2(trans1, trans2);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00010C
 */
void NPosture3D::inputTransform(immut NTransform3D& transform)
{
	transform.outputTranslation(mViewpoint);
	NOrientation NRef orient = NOrientation();
	orient.inputRotation(transform);
	mWatchpoint.add2(mViewpoint, orient.getFore());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C
 */
f32 NPosture3D::calcDirection() immut
{
	NVector3f NRef dir = NVector3f();
	outputRelative(dir);
	return NMathF::atan2(dir.x, dir.z);
}

/**
 * @todo: Documentation
 */
void NPosture3D::readData(Stream& input)
{
	mViewpoint.read(input);
	mWatchpoint.read(input);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000038
 */
void NPosture3D::println() immut
{
	mViewpoint.println();
	mWatchpoint.println();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
NSpecialMatrix::NSpecialMatrix(int dim)
{
	construct(dim);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000008
 */
void NSpecialMatrix::construct(int dim)
{
	mDimension = dim;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
NLowerMatrix::NLowerMatrix(f32* values, int dim)
{
	construct(values, dim);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00000C
 */
void NLowerMatrix::construct(f32* values, int dim)
{
	NSpecialMatrix::construct(dim);
	mLower = values;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000060
 */
void NLowerMatrix::solve(immut NVector& inVec, NVector& outVec)
{
	outVec.mValues[0] = inVec.mValues[0];
	for (int i = 1; i < mDimension; i++) {
		outVec.mValues[i] = inVec.mValues[i] - mLower[i - 1] * outVec.mValues[i - 1];
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
void NLowerMatrix::println() immut
{
	for (int i = 0; i < mDimension - 1; i++) {
		PRINT_NAKATA("l[%d]:%f\n", i, mLower[i]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
NUpperMatrix::NUpperMatrix(f32* centreVals, f32* upperVals, int dim)
{
	construct(centreVals, upperVals, dim);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000010
 */
void NUpperMatrix::construct(f32* centreVals, f32* upperVals, int dim)
{
	NSpecialMatrix::construct(dim);
	mCentre = centreVals;
	mUpper  = upperVals;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000180
 */
void NUpperMatrix::solve(immut NVector& inVec, NVector& outVec)
{
	outVec.mValues[mDimension - 1] = inVec.mValues[mDimension - 1] / mCentre[mDimension - 1];

	for (int i = mDimension - 2; i >= 0; i--) {
		outVec.mValues[i] = (inVec.mValues[i] - mUpper[i] * outVec.mValues[i + 1]) / mCentre[i];
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000A4
 */
void NUpperMatrix::println() immut
{
	for (int i = 0; i < mDimension; i++) {
		PRINT_NAKATA("e[%d]:%f\n", i, mCentre[i]);
	}
	for (int i = 0; i < mDimension - 1; i++) {
		PRINT_NAKATA("u[%d]:%f\n", i, mUpper[i]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00006C
 */
LUMatrix::LUMatrix(f32* centreVals, f32* lowerVals, f32* upperVals, int dim)
{
	construct(centreVals, lowerVals, upperVals, dim);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034
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

/**
 * @todo: Documentation
 */
void LUMatrix::setDimension(int dim)
{
	NSpecialMatrix::setDimension(dim);
	mLower.setDimension(dim);
	mUpper.setDimension(dim);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00022C
 */
void LUMatrix::solve(immut NVector& inVec, NVector& outVec)
{
	f32 vals[16];
	decompose();
	NVector NRef tmp = NVector(vals, mDimension);
	mLower.solve(inVec, tmp);
	mUpper.solve(tmp, outVec);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000B0
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
void LUMatrix::println() immut
{
	for (int i = 0; i < mDimension; i++) {
		PRINT_NAKATA("e[%d]:%f\n", i, mCentreVals[i]);
	}
	for (int i = 0; i < mDimension - 1; i++) {
		PRINT_NAKATA("l[%d]:%f\n", i, mLowerVals[i]);
	}
	for (int i = 0; i < mDimension - 1; i++) {
		PRINT_NAKATA("u[%d]:%f\n", i, mUpperVals[i]);
	}
}

/**
 * @todo: Documentation
 */
NTransform3D::NTransform3D()
{
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000098
 */
NTransform3D::NTransform3D(immut NMatrix4f& mtx)
{
	construct(mtx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000020
 */
void NTransform3D::construct(immut NMatrix4f& mtx)
{
	construct(mtx);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000090
 */
void NTransform3D::translate(immut Vector3f& offset)
{
	NVector3f NRef trans = NVector3f();
	outputTranslation(trans);
	trans.add(offset);
	inputTranslation(trans);
}

/**
 * @todo: Documentation
 */
void NTransform3D::rotate(immut Vector3f& point)
{
	NTransform3D NRef rotation = NTransform3D();
	outputRotation(rotation);
	rotation.rotate(point);
	STACK_PAD_STRUCT(3);
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

/**
 * @todo: Documentation
 */
void NTransform3D::transform(Vector3f& point) immut
{
	point.multMatrix(*this);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000044
 */
void NTransform3D::transform(immut Vector3f& inputPoint, Vector3f& outputPoint) immut
{
	outputPoint = inputPoint;
	transform(outputPoint);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000184
 */
void NTransform3D::transform(NVector& vec) immut
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 00018C
 */
void NTransform3D::transform(immut NVector& in, NVector& out) immut
{
	out.input(in);
	transform(out);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000094
 */
void NTransform3D::inputVector(immut Vector3f& vec)
{
	makeIdentity();
	inputTranslation(vec);
}

/**
 * @todo: Documentation
 */
void NTransform3D::inputAxisAngle(immut NAxisAngle4f& axisAngle)
{
	makeRotate(axisAngle.getAxis(), axisAngle.getAngle());
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
void NTransform3D::inputTranslation(immut Vector3f& trans)
{
	inputCol(3, trans);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00001C
 */
void NTransform3D::outputTranslation(Vector3f& trans) immut
{
	outputCol(3, trans);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00004C
 */
void NTransform3D::inputRotation(immut Matrix4f& rotMtx)
{
	for (int i = 0; i < 3; i++) {
		setRow(i, rotMtx.mMtx[i][0], rotMtx.mMtx[i][1], rotMtx.mMtx[i][2]);
	}
}

/**
 * @todo: Documentation
 */
void NTransform3D::outputRotation(Matrix4f& rotMtx) immut
{
	NVector3f NRef row = NVector3f();
	for (int i = 0; i < 3; i++) {
		outputRow(i, row);
		rotMtx.mMtx[i][0] = row.x;
		rotMtx.mMtx[i][1] = row.y;
		rotMtx.mMtx[i][2] = row.z;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E4
 */
void NTransform3D::inputRotation(immut NAxisAngle4f& axisAngle)
{
	NTransform3D NRef trans = NTransform3D();
	trans.inputAxisAngle(axisAngle);
	inputRotation(trans);
}

/**
 * @todo: Documentation
 */
NVector::NVector()
{
	mValues = nullptr;
	mSize   = 0;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
NVector::NVector(f32* values, int size)
{
	construct(values, size);
}

/**
 * @todo: Documentation
 */
void NVector::construct(f32* values, int size)
{
	mValues = values;
	mSize   = size;
	makeZero();
}

/**
 * @todo: Documentation
 */
void NVector::makeZero()
{
	for (int i = 0; i < mSize; i++) {
		mValues[i] = 0.0f;
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
void NVector::add(immut NVector&)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000118
 */
f32 NVector::dot(immut NVector&) immut
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000034
 */
void NVector::input(immut NVector&)
{
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
void NVector::println() immut
{
	// UNUSED FUNCTION
	for (int i = 0; i < mSize; i++) {
		PRINT_NAKATA("e[%d]:%f\n", i, mValues[i]);
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 00002C
 */
void NVector3f::printVector3f(immut Vector3f& vec)
{
	NVector3f(vec).print();
}

/**
 * @todo: Documentation
 */
void NVector3f::printlnVector3f(immut Vector3f& vec)
{
	NVector3f(vec).println();
}

/**
 * @todo: Documentation
 */
NVector3f::NVector3f()
{
	set(0.0f, 0.0f, 0.0f);
}

/**
 * @todo: Documentation
 */
NVector3f::NVector3f(immut Vector3f& vec)
{
	construct(vec);
}

/**
 * @todo: Documentation
 */
void NVector3f::construct(immut Vector3f& vec)
{
	set(vec.x, vec.y, vec.z);
}

/**
 * @todo: Documentation
 */
NVector3f::NVector3f(f32 x, f32 y, f32 z)
{
	construct(x, y, z);
}

/**
 * @todo: Documentation
 */
void NVector3f::construct(f32 x, f32 y, f32 z)
{
	set(x, y, z);
}

/**
 * @todo: Documentation
 */
NVector3f::NVector3f(immut Vector3f& start, immut Vector3f& end)
{
	construct(start, end);
}

/**
 * @todo: Documentation
 */
void NVector3f::construct(immut Vector3f& start, immut Vector3f& end)
{
	set(end.x - start.x, end.y - start.y, end.z - start.z);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000054
 */
void NVector3f::interpolate(immut Vector3f& start, immut Vector3f& end, f32 t)
{
	set(NMathF::interpolate(start.x, end.x, t), NMathF::interpolate(start.y, end.y, t), NMathF::interpolate(start.z, end.z, t));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000B4
 */
bool NVector3f::isZero() immut
{
	return (NMathF::isZero(x) && NMathF::isZero(y) && NMathF::isZero(z));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000F0
 */
bool NVector3f::equals(immut Vector3f& vec) immut
{
	return NVector3f(*this, vec).isZero();
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000058
 */
bool NVector3f::isVertical(immut Vector3f& vec) immut
{
	return NMathF::isZero(dot(vec));
}

/**
 * @todo: Documentation
 */
bool NVector3f::isParallel(immut Vector3f& vec) immut
{
	return NMathF::equals(NMathf::absolute(dot(vec)), 1.0f);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000144
 */
void NVector3f::makeUnitVector(immut Vector3f& start, immut Vector3f& end)
{
	sub2(end, start);
	f32 dist = length();
	if (NMathF::isPositive(dist)) {
		normalize();
	} else {
		input(NVector3f(0.0f, 0.0f, 1.0f));
	}
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000088
 */
void NVector3f::outputQuat(f32 theta, Quat& q) immut
{
	f32 scale = NMathF::sin(theta / 2.0f);
	q.set(scale * x, scale * y, scale * z, NMathF::cos(theta / 2.0f));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 0000E0
 */
f32 NVector3f::calcAngle(immut NVector3f& other) immut
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 000098
 */
f32 NVector3f::calcLargerAngle(immut NVector3f& other) immut
{
	return TAU - calcAngle(other);
	// UNUSED FUNCTION
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000004
 */
void NVector3f::print() immut
{
	PRINT_NAKATA("(%f,%f,%f)", x, y, z);
}

/**
 * @todo: Documentation
 */
void NVector3f::println() immut
{
	PRINT_NAKATA("(%f,%f,%f)\n", x, y, z);
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000028
 */
void NVector3f::normalizeByLength(f32 length)
{
	x /= length;
	y /= length;
	z /= length;
}

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
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

/**
 * @todo: Documentation
 * @note UNUSED Size: 00003C
 */
f32 NAlpha::fadeInValue(f32 x)
{
	f32 val = sinf(x * (NMathF::pi / 2.0f) + (NMathF::pi / 2.0f));
	return 1.0f - val;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
f32 NAlpha::fadeOutValue(f32 x)
{
	return sinf(x * (NMathF::pi / 2));
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080
 */
f32 NAlpha::fadeInOutValue(f32 x)
{
	if (x < 0.5f) {
		return 0.5f * fadeInValue(2.0f * x);
	}
	return fadeOutValue(2.0f * (x - 0.5f)) * 0.5f + 0.5f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000080
 */
f32 NAlpha::fadeOutInValue(f32 x)
{
	if (x < 0.5f) {
		return fadeOutValue(2.0f * x) * 0.5f;
	}

	return fadeInValue(2.0f * (x - 0.5f)) * 0.5f + 0.5f;
}

/**
 * @todo: Documentation
 * @note UNUSED Size: 000030
 */
NAlpha::NAlpha()
{
	mOffset = 0.0f;
	mScale  = 1.0f;
	mMode   = 0;
	mValue  = mOffset;
}

/**
 * @todo: Documentation
 */
void NAlpha::reset()
{
	mValue = mOffset;
}

/**
 * @todo: Add documentation
 * Address:	1004BE90 in plugPiki
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

/**
 * @todo: Documentation
 */
void NAlpha::readData(Stream& input)
{
	mOffset = input.readFloat();
	mScale  = input.readFloat();
	mMode   = input.readByte();
}
