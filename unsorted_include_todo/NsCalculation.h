#ifndef _NSCALCULATION_H
#define _NSCALCULATION_H

/*
 * @brief TODO
 */
struct NsCalculation {
	void calcLagrange(float, const Vector3f*, Vector3f&);
	void calcMatrix(const Vector3f&, const Vector3f&, const Vector3f&, const Vector3f&, Matrix4f&);
	void calcJointPos(const Vector3f&, const Vector3f&, float, float, Vector3f&, Vector3f&);
	void calcMat4toMat3(const Matrix4f&, Matrix3f&);
};

#endif
