#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "types.h"
#include "math.h"
#include "Stream.h"
#include "std/Math.h"

struct Matrix3f;
struct Quat;

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct Vector3f {
	Vector3f() { x = y = z = 0.0f; }
	Vector3f(const f32& _x, const f32& _y, const f32& _z)
	    : x(_x)
	    , y(_y)
	    , z(_z)
	{
	}

	// NB: do NOT make an operator= definition, needs to use the default copy ctor.

	// THIS IS THE COMPLETE VECTOR3F INLINE LIST.
	// ANYTHING ELSE IS EITHER A MATH LIBRARY FUNCTION IN DISGUISE, OR FAKE.

	void rotate(struct Matrix4f&);
	void rotateTo(Matrix4f&, Vector3f&);
	void multMatrix(Matrix4f&);
	void multMatrixTo(Matrix4f&, Vector3f&);

	void read(Stream& stream)
	{
		x = stream.readFloat();
		y = stream.readFloat();
		z = stream.readFloat();
	}

	void write(Stream& stream)
	{
		stream.writeFloat(x);
		stream.writeFloat(y);
		stream.writeFloat(z);
	}

	void set(const f32& pX, const f32& pY, const f32& pZ)
	{
		x = pX;
		y = pY;
		z = pZ;
	}

	void set(const Vector3f& other) { set(other.x, other.y, other.z); }

	void input(const Vector3f& other) { set(other.x, other.y, other.z); }

	// TODO: void output(Vector3f&);

	f32 length() const { return std::sqrtf(x * x + y * y + z * z); }

	f32 distance(Vector3f& to)
	{
		Vector3f result;
		result.sub2(to, *this);
		return result.length();
	}

	f32 normalise()
	{
		f32 norm = length();
		if (norm != 0.0f) {
			div(norm);
		}
		return norm;
	}

	// TODO: void normalize();

	// TODO: check if this is correct or if one of these needs adjusting
	f32 DP(Vector3f& other) const { return x * other.x + y * other.y + z * other.z; }
	f32 dot(Vector3f& other) const { return x * other.x + y * other.y + z * other.z; }

	void CP(Vector3f& other)
	{
		Vector3f tmp;
		tmp.x = y * other.z - z * other.y;
		tmp.y = z * other.x - x * other.z;
		tmp.z = x * other.y - y * other.x;
		x     = tmp.x;
		y     = tmp.y;
		z     = tmp.z;
	}

	void cross(Vector3f& vec1, Vector3f& vec2)
	{
		x = vec1.y * vec2.z - vec1.z * vec2.y;
		y = vec1.z * vec2.x - vec1.x * vec2.z;
		z = vec1.x * vec2.y - vec1.y * vec2.x;
	}

	void add(Vector3f& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void add2(Vector3f& a, Vector3f& b) { set(a.x + b.x, a.y + b.y, a.z + b.z); }

	void sub(Vector3f& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	void sub(Vector3f& a, Vector3f& b)
	{
		x = a.x - b.x;
		y = a.y - b.y;
		z = a.z - b.z;
	}

	void sub2(Vector3f& a, Vector3f& b) { set(a.x - b.x, a.y - b.y, a.z - b.z); }

	void div(f32 divisor)
	{
		x /= divisor;
		y /= divisor;
		z /= divisor;
	}

	void multiply(f32 scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
	}

	void scale(f32 scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
	}

	void scale2(f32 scale, Vector3f& vec) { vec.set(scale * x, scale * y, scale * z); }

	// TODO: check if this is this, or x *= -1.0f etc
	void negate()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	void bounce(Vector3f& surface, f32 elasticity)
	{
		f32 dp = -dot(surface) * elasticity;
		if (dp > 0.0f) {
			x = dp * surface.x + x;
			y = dp * surface.y + y;
			z = dp * surface.z + z;
		}
	}

	void lerpTo(Vector3f& other, f32 t, Vector3f& outVec)
	{
		outVec.x = (other.x - x) * t + x;
		outVec.y = (other.y - y) * t + y;
		outVec.z = (other.z - z) * t + z;
	}

	// TODO: void project(Vector3f&);

	// unused/inlined:
	void rotateTranspose(Matrix4f&);

	void rotate(Quat&);
	void rotateInverse(Quat&);

	f32 x, y, z; // _00, _04, _08
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct Vector2f {
	Vector2f() { }
	Vector2f(const f32& _x, const f32& _y)
	{
		x = _x;
		y = _y;
	}

	// this is the only Vector2f inline outside of the constructors.
	void set(f32 _x, f32 _y)
	{
		x = _x;
		y = _y;
	}

	f32 x, y; // _00, _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct Vector2i {

	// this doesn't even have a constructor according to the DLL.
	void set(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	int x, y; // _00, _04
};

/**
 * @brief TODO
 *
 * @note Size: 0x10.
 */
struct Quat {
	Quat() { }

	Quat(f32 _x, f32 _y, f32 _z, f32 _s) { set(_x, _y, _z, _s); }

	void fromMat3f(Matrix3f&);
	void rotate(Vector3f&, f32);
	void multiply(Quat&);
	void normalise();
	void genVectorX(Vector3f&);
	void genVectorY(Vector3f&);
	void genVectorZ(Vector3f&);
	void slerp(Quat&, f32, int);
	void fromEuler(Vector3f&);

	// unused/inlined:
	void multiplyTo(Quat&, Quat&);

	// this is the only inline according to the DLL.
	void set(f32 _x, f32 _y, f32 _z, f32 _s)
	{
		v.x = _x;
		v.y = _y;
		v.z = _z;
		s   = _s;
	}

	Vector3f v; // _00, vector/imaginary part
	f32 s;      // _0C, scalar/real part
};

// these are all in the DLL function list.
inline Vector3f CP(const Vector3f& vec1, const Vector3f& vec2)
{
	Vector3f outVec;
	outVec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	outVec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	outVec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return outVec;
}
inline Vector3f operator*(const Vector3f& a, const f32& b) { return Vector3f(a.x * b, a.y * b, a.z * b); }
inline Vector3f operator*(const f32& b, const Vector3f& a) { return a * b; }
inline Vector3f operator+(const Vector3f& a, const Vector3f& b) { return Vector3f(a.x + b.x, a.y + b.y, a.z + b.z); }
inline Vector3f operator-(const Vector3f& a, const Vector3f& b) { return Vector3f(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vector3f operator-(const Vector3f& a) { return Vector3f(-a.x, -a.y, -a.z); }
inline Vector3f operator/(const Vector3f& a, const f32& b) { return Vector3f(a.x / b, a.y / b, a.z / b); }

#endif
