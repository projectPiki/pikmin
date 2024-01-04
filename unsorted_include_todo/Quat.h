#ifndef _QUAT_H
#define _QUAT_H

/*
 * @brief TODO
 */
struct Quat {
	void fromMat3f(Matrix3f&);
	void rotate(Vector3f&, float);
	void multiply(Quat&);
	void normalise();
	void genVectorX(Vector3f&);
	void genVectorY(Vector3f&);
	void genVectorZ(Vector3f&);
	void slerp(Quat&, float, int);
	void fromEuler(Vector3f&);
};

#endif
