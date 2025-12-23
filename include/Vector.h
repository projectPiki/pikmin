#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "Stream.h"
#include "math.h"
#include "sysMath.h"
#include "types.h"

struct AgeServer;
struct Matrix3f;
struct Matrix4f;
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

	Vector3f(const Vector3f& other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	//!
	//! NB: do NOT make an operator= definition, needs to use the default.
	//!

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
	void input(immut Vector3f& other) { set(other.x, other.y, other.z); }
	void output(Vector3f& outVec) immut { outVec.set(x, y, z); }

	f32 length() immut { return std::sqrtf(SQUARE(x) + SQUARE(y) + SQUARE(z)); }
	f32 squaredLength() immut { return SQUARE(x) + SQUARE(y) + SQUARE(z); }

	// TODO: implementions are guessed, a manual check if accurate required
	f32 DP(immut Vector3f& other) immut { return x * other.x + y * other.y + z * other.z; }
	f32 dot(immut Vector3f& other) immut { return x * other.x + y * other.y + z * other.z; }

	f32 distance(immut Vector3f& to) immut
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

	void CP(immut Vector3f& other)
	{
		Vector3f tmp;
		tmp.x = y * other.z - z * other.y;
		tmp.y = z * other.x - x * other.z;
		tmp.z = x * other.y - y * other.x;
		x     = tmp.x;
		y     = tmp.y;
		z     = tmp.z;
	}

	void cross(immut Vector3f& vec1, immut Vector3f& vec2)
	{
		set(vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x);
	}

	void add(immut Vector3f& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void add2(immut Vector3f& a, immut Vector3f& b) { set(a.x + b.x, a.y + b.y, a.z + b.z); }

	void sub(immut Vector3f& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	void sub(immut Vector3f& a, immut Vector3f& b)
	{
		x = a.x - b.x;
		y = a.y - b.y;
		z = a.z - b.z;
	}

	void sub2(immut Vector3f& a, immut Vector3f& b) { set(a.x - b.x, a.y - b.y, a.z - b.z); }

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

	void scale2(f32 scale, immut Vector3f& vec)
	{
		x = scale * vec.x;
		y = scale * vec.y;
		z = scale * vec.z;
	}

	void negate()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	void bounce(immut Vector3f& surface, f32 elasticity)
	{
		f32 dp = -DP(surface) * elasticity;
		if (dp > 0.0f) {
			x = surface.x * dp + x;
			y = surface.y * dp + y;
			z = surface.z * dp + z;
		}
	}

	void lerpTo(immut Vector3f& other, f32 t, Vector3f& outVec)
	{
		outVec.x = (other.x - x) * t + x;
		outVec.y = (other.y - y) * t + y;
		outVec.z = (other.z - z) * t + z;
	}

	void rotate(immut Matrix4f&);
	void rotateTo(immut Matrix4f&, Vector3f&);
	void multMatrix(immut Matrix4f&);
	void multMatrixTo(immut Matrix4f&, Vector3f&);
	void rotateTranspose(immut Matrix4f&);
	void rotate(immut Quat&);
	void rotateInverse(immut Quat&);

	// unused/inlined (ALL HAVE NOT BEEN CHECKED FOR ACCURACY):
	void normalize() { normalise(); }

	// NB: this gets the orthogonal component, not the projected component.
	void project(immut Vector3f& dirToRemove)
	{
		f32 projAmt = DP(dirToRemove);
		x           = -(projAmt * dirToRemove.x - x);
		y           = -(projAmt * dirToRemove.y - y);
		z           = -(projAmt * dirToRemove.z - z);
	}

	void middle(immut Vector3f& a, immut Vector3f& b)
	{
		add2(a, b);
		scale(0.5f);
	}

	bool isSame(immut Vector3f& other) immut
	{
		return fabsf(x - other.x) < 0.0001f && fabsf(y - other.y) < 0.0001f && fabsf(z - other.z) < 0.0001f;
	}

	void add(immut Vector3f& a, immut Vector3f& b)
	{
		x = a.x + b.x;
		y = a.y + b.y;
		z = a.z + b.z;
	}

	void add(f32 _x, f32 _y, f32 _z)
	{
		x += _x;
		y += _y;
		z += _z;
	}

#ifdef WIN32
	void genAge(AgeServer&, char*, Vector3f&, Vector3f&)
	{
		// Empty implementation
	}
#endif

	f32 x; // _00
	f32 y; // _04
	f32 z; // _08
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

	void write(Stream& stream)
	{
		stream.writeFloat(x);
		stream.writeFloat(y);
	}

	void read(Stream& stream)
	{
		x = stream.readFloat();
		y = stream.readFloat();
	}

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
	void read(Stream& stream)
	{
		x = stream.readInt();
		y = stream.readInt();
	}

	void write(Stream& stream)
	{
		stream.writeInt(x);
		stream.writeInt(y);
	}

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

	void fromMat3f(immut Matrix3f&);
	void rotate(immut Vector3f&, f32);
	void multiply(immut Quat&);
	void normalise();
	void genVectorX(Vector3f&) immut;
	void genVectorY(Vector3f&) immut;
	void genVectorZ(Vector3f&) immut;
	void slerp(immut Quat&, f32, int);
	void fromEuler(immut Vector3f&);

	// unused/inlined:
	void multiplyTo(immut Quat&, Quat&);

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

//!
//! These are taken from the DLL, do NOT remove
//!
inline Vector3f operator*(const Vector3f& a, const f32& b)
{
	return Vector3f(a.x * b, a.y * b, a.z * b);
}

inline Vector3f operator*(const f32& b, const Vector3f& a)
{
	return a * b;
}

inline Vector3f operator+(const Vector3f& a, const Vector3f& b)
{
	return Vector3f(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector3f operator-(const Vector3f& a, const Vector3f& b)
{
	return Vector3f(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline Vector3f operator-(const Vector3f& a)
{
	return Vector3f(-a.x, -a.y, -a.z);
}

inline Vector3f operator/(const Vector3f& a, const f32& b)
{
	return a * (1.0f / b);
}

inline Vector3f CP(const Vector3f& a, const Vector3f& b)
{
	f32 x = a.y * b.z - a.z * b.y;
	f32 y = a.z * b.x - a.x * b.z;
	f32 z = a.x * b.y - a.y * b.x;
	return Vector3f(x, y, z);
}

#endif
