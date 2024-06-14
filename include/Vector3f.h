#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "types.h"
#include "math.h"
#include "Stream.h"

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct Vector3f {
	Vector3f() { x = y = z = 0.0f; } // yes it's this way around, every vector initialised in a ctor is "in reverse"
	Vector3f(f32 const& _x, f32 const& _y, f32 const& _z)
	    : x(_x)
	    , y(_y)
	    , z(_z)
	{
	}
	inline Vector3f operator*(const Vector3f& other) const { return Vector3f(x * other.x, y * other.y, z * other.z); }
	void rotate(struct Matrix4f&);
	void rotateTo(Matrix4f&, Vector3f&);
	void multMatrix(Matrix4f&);
	void multMatrixTo(Matrix4f&, Vector3f&);

	inline void read(Stream& stream)
	{
		x = stream.readFloat();
		y = stream.readFloat();
		z = stream.readFloat();
	}

	inline f32 distance(Vector3f& to)
	{
		Vector3f result;
		result.sub2(to, *this);
		return result.length();
	}

	inline void sub2(Vector3f& a, Vector3f& b)
	{
		f32 newZ = a.getZ() - b.getZ();
		f32 newY = a.getY() - b.getY();
		f32 newX = a.getX() - b.getX();
		set(newX, newY, newZ);
	}

	inline void set(const f32& pX, const f32& pY, const f32& pZ)
	{
		x = pX;
		y = pY;
		z = pZ;
	}
	inline void operator*=(const f32 other)
	{
		this->x *= other;
		this->y *= other;
		this->z *= other;
	}
	inline void operator=(const Vector3f& other) { set(other.x, other.y, other.z); }

	inline void set(const f32 val) { x = y = z = val; }

	void div(f32); // weak

	inline f32 squaredLength() const { return x * x + y * y + z * z; }
	inline f32 length() const { return sqrtf(squaredLength()); }

	const f32 getX() const { return x; }
	const f32 getY() const { return y; }
	const f32 getZ() const { return z; }

	f32 getX() { return x; }
	f32 getY() { return y; }
	f32 getZ() { return z; }

	f32 x, y, z; // _00, _04, _08
};

inline Vector3f cross(Vector3f& vec1, Vector3f& vec2)
{
	Vector3f outVec;
	outVec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	outVec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	outVec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return outVec;
}

struct Vector2f {
	Vector2f() { }
	Vector2f(const f32& x, const f32& y);
	f32 x, y; // _00, _04
};
inline Vector3f operator-(const Vector3f& a, const Vector3f& b) { return Vector3f(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vector3f operator+(const Vector3f& a, const Vector3f& b) { return Vector3f(a.x + b.x, a.y + b.y, a.z + b.z); }
inline f32 Vector3f_diffX(Vector3f& a, Vector3f& b) { return a.getX() - b.getX(); }
inline f32 Vector3f_diffY(Vector3f& a, Vector3f& b) { return a.getY() - b.getY(); }
inline f32 Vector3f_diffZ(Vector3f& a, Vector3f& b) { return a.getZ() - b.getZ(); }

#endif
