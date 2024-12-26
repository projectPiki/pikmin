#ifndef _VECTOR3F_H
#define _VECTOR3F_H

#include "types.h"
#include "math.h"
#include "Stream.h"
#include "std/Math.h"
#include "PowerPC_EABI_Support/MSL_C/PPC_EABI/math_ppc.h"

struct Matrix3f;
struct Quat;

/**
 * @brief TODO
 *
 * @note Size: 0xC.
 */
struct Vector3f {
	Vector3f() { x = y = z = 0.0f; }
	Vector3f(f32 const& _x, f32 const& _y, f32 const& _z)
	    : x(_x)
	    , y(_y)
	    , z(_z)
	{
	}

	inline Vector3f operator*(const Vector3f& other) const { return Vector3f(x * other.x, y * other.y, z * other.z); }
	inline Vector3f operator*(const f32& scale) const { return Vector3f(x * scale, y * scale, z * scale); }
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

	inline void write(Stream& stream)
	{
		stream.writeFloat(x);
		stream.writeFloat(y);
		stream.writeFloat(z);
	}

	inline f32 distance(Vector3f& to)
	{
		Vector3f result;
		result.sub2(to, *this);
		return result.length();
	}

	inline f32 distanceFrom(Vector3f& from)
	{
		x = x - from.x;
		y = y - from.y;
		z = z - from.z;
		return length();
	}

	inline void sub2(Vector3f& a, Vector3f& b) { set(a.x - b.x, a.y - b.y, a.z - b.z); }

	inline void set(const f32& pX, const f32& pY, const f32& pZ)
	{
		x = pX;
		y = pY;
		z = pZ;
	}

	inline void setUniform(f32 val) { set(val, val, val); }

	inline void input(const Vector3f& other) { set(other.x, other.y, other.z); }

	inline void set(Vector3f& other) { set(other.x, other.y, other.z); }

	inline void operator*=(const f32 other)
	{
		this->x *= other;
		this->y *= other;
		this->z *= other;
	}

	inline void operator+=(Vector3f& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	// NB: do NOT make an operator= definition, needs to use the default.

	inline void set(const f32 val) { x = y = z = val; }

	void div(f32 divisor) // weak
	{
		x /= divisor;
		y /= divisor;
		z /= divisor;
	}

	inline f32 dot(Vector3f& other) const { return x * other.x + y * other.y + z * other.z; }

	inline f32 squaredLength() const { return x * x + y * y + z * z; }
	inline f32 squaredLength2D() const { return x * x + z * z; }
	inline f32 length() const { return std::sqrtf(x * x + y * y + z * z); }
	inline f32 length2D() const { return std::sqrtf(squaredLength2D()); }

	// seems good according to InteractBomb::actPiki
	inline f32 normalise()
	{
		f32 norm = length();
		if (norm != 0.0f) {
			x /= norm;
			y /= norm;
			z /= norm;
		}
		return norm;
	}

	inline f32 angSep(Vector3f& b) { return atan2f(b.x - x, b.z - z); }

	const f32 getX() const { return x; }
	const f32 getY() const { return y; }
	const f32 getZ() const { return z; }

	f32 getX() { return x; }
	f32 getY() { return y; }
	f32 getZ() { return z; }

	void input(Vector3f&);

	void makeIdentity()
	{
		x = 1.0f;
		y = 1.0f;
		z = 1.0f;
	}

	void reset() { set(Vector3f(0.0f, 0.0f, 0.0f)); }

	void lerpTo(Vector3f& other, f32 t, Vector3f& outVec)
	{
		outVec.x = (other.x - x) * t + x;
		outVec.y = (other.y - y) * t + y;
		outVec.z = (other.z - z) * t + z;
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

	bool isSame(Vector3f& other)
	{
		if (absF(x - other.x) < 0.0001f && absF(y - other.y) < 0.0001f && absF(z - other.z) < 0.0001f) {
			return true;
		}
		return false;
	}

	void cross(Vector3f& vec1, Vector3f& vec2)
	{
		x = vec1.y * vec2.z - vec1.z * vec2.y;
		y = vec1.z * vec2.x - vec1.x * vec2.z;
		z = vec1.x * vec2.y - vec1.y * vec2.x;
	}

	void cross(Vector3f& vec2)
	{
		Vector3f tmp;
		tmp.x = y * vec2.z - z * vec2.y;
		tmp.y = z * vec2.x - x * vec2.z;
		tmp.z = x * vec2.y - y * vec2.x;
		x     = tmp.x;
		y     = tmp.y;
		z     = tmp.z;
	}

	void multiply(f32 scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
	}

	void add(Vector3f& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void sub(Vector3f& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	void add2(Vector3f& a, Vector3f& b) { set(a.x + b.x, a.y + b.y, a.z + b.z); }

	// unused/inlined:
	void rotateTranspose(Matrix4f&);
	void rotate(Quat&);
	void rotateInverse(Quat&);

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

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct Vector2f {
	Vector2f() { }
	Vector2f(const f32& x, const f32& y);

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

	inline void set(f32 _x, f32 _y, f32 _z, f32 _s)
	{
		v.x = _x;
		v.y = _y;
		v.z = _z;
		s   = _s;
	}

	Vector3f v; // _00, vector/imaginary part
	f32 s;      // _0C, scalar/real part
};

inline Vector3f operator-(const Vector3f& a, const Vector3f& b) { return Vector3f(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vector3f operator+(const Vector3f& a, const Vector3f& b) { return Vector3f(a.x + b.x, a.y + b.y, a.z + b.z); }
inline f32 Vector3f_diffX(Vector3f& a, Vector3f& b) { return a.getX() - b.getX(); }
inline f32 Vector3f_diffY(Vector3f& a, Vector3f& b) { return a.getY() - b.getY(); }
inline f32 Vector3f_diffZ(Vector3f& a, Vector3f& b) { return a.getZ() - b.getZ(); }

#endif
