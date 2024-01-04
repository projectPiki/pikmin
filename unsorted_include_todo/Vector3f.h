#ifndef _VECTOR3F_H
#define _VECTOR3F_H

/*
 * @brief TODO
 */
struct Vector3f {
	Vector3f(const float&, const float&, const float&);
	void rotate(Matrix4f&);
	void rotateTo(Matrix4f&, Vector3f&);
	void multMatrix(Matrix4f&);
	void multMatrixTo(Matrix4f&, Vector3f&);
};

#endif
