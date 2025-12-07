#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include "Vector.h"
#include "types.h"

struct Sphere;

/**
 * @brief A representation of a cylinder in 3D space.
 */
struct Cylinder {
	Cylinder(immut Vector3f& startPoint, immut Vector3f& endPoint, f32 radius = 1.0f)
	    : mStartPoint(startPoint)
	    , mEndPoint(endPoint)
	    , mRadius(radius)
	{
	}

	f32 get2dDist(immut Vector3f& point) immut;
	bool collide(const Sphere& sphere, Vector3f& pushVector, f32& depth) immut;
	f32 getPosRatio(const Vector3f& point) immut; // 0-1 along the cylinder axis

	Vector3f mStartPoint; // _00
	Vector3f mEndPoint;   // _0C
	f32 mRadius;          // _18
};

/**
 * @brief TODO
 */
struct RectArea {
	RectArea(int x0, int y0, int x1, int y1)
	{
		mMinX = x0;
		mMinY = y0;
		mMaxX = x1;
		mMaxY = y1;
	}

	RectArea()
	{
		mMinY = mMaxY = 0;
		mMinX = mMaxX = 0;
	}

	void set(int minX, int minY, int maxX, int maxY)
	{
		mMinX = minX;
		mMinY = minY;
		mMaxX = maxX;
		mMaxY = maxY;
	}

	int width() immut { return mMaxX - mMinX; }
	int height() immut { return mMaxY - mMinY; }

	// other DLL inlines to do:
	bool pointInside(int, int) immut;

	int mMinX; // _00, x1
	int mMinY; // _04, y1
	int mMaxX; // _08, x2
	int mMaxY; // _0C, y2
};

/**
 * @brief TODO
 */
struct Sphere {
	Sphere(immut Vector3f& centre, f32 radius)
	    : mCentre(centre)
	    , mRadius(radius)
	{
	}

	Vector3f mCentre; // _00
	f32 mRadius;      // _04
};

/**
 * @brief TODO
 */
struct Tube {
	// DLL inlines to do:
	Tube(immut Vector3f& start, immut Vector3f& end, f32 startRad, f32 endRad)
	    : mStartPoint(start)
	    , mEndPoint(end)
	    , mStartRadius(startRad)
	    , mEndRadius(endRad)
	{
	}

	Tube() { } // TODO: check this

	f32 getYRatio(f32 heightToCheck) immut;
	bool collide(const Sphere&, Vector3f&, f32&) immut;
	f32 getPosRatio(const Vector3f&) immut;
	void getPosGradient(Vector3f&, f32, Vector3f&, Vector3f&) immut;
	Vector3f setPos(f32) immut;

	// unused/inlined:
	f32 getRatioRadius(f32) immut;

	// TODO: members
	Vector3f mStartPoint; // _00
	Vector3f mEndPoint;   // _0C
	f32 mStartRadius;     // _18
	f32 mEndRadius;       // _1C
};

#endif
