#ifndef _MATRIX4F_H
#define _MATRIX4F_H

/*
 * @brief TODO
 */
struct Matrix4f {
	void makeIdentity();
	void makeRotate(Vector3f&, float, float);
	void makeRotate(Vector3f&, float);
	void multiply(Matrix4f&);
	void multiplyTo(Matrix4f&, Matrix4f&);
	void makeSRT(Vector3f&, Vector3f&, Vector3f&);
	void makeConcatSRT(Matrix4f*, Matrix4f&, SRT&);
	void inverse(Matrix4f*);
	void scale(Vector3f&);
	void makeLookat(Vector3f&, Vector3f&, Vector3f*);
	void makeLookat(Vector3f&, Vector3f&, Vector3f&, Vector3f&);
	void transposeTo(Matrix4f&);
	void makeVQS(Vector3f&, Quat&, Vector3f&);
};

#endif
