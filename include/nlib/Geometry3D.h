#ifndef _NLIB_GEOMETRY3D_H
#define _NLIB_GEOMETRY3D_H

#include "nlib/Geometry.h"
#include "types.h"

struct NSegment;
struct Plane;
struct NLine;

/**
 * @brief TODO
 */
struct NLine {
	NLine(NVector3f&, NVector3f&);
	NLine();       // unused/inlined
	NLine(NLine&); // unused/inlined

	virtual void transform(NTransform3D&); // _08
	virtual void println();                // _0C

	void construct(NVector3f&, NVector3f&);
	f32 calcDistance(NVector3f&, f32*);
	f32 calcVerticalProjection(NVector3f&);
	void outputPosition(f32, NVector3f&);

	// unused/inlined:
	void construct(NLine&);
	f32 calcDistance(NLine&, f32*, f32*);
	void outputVerticalPosition(NVector3f&, NVector3f&);
	void outputPositionY(f32, NVector3f&);

	NVector3f& getDirection() { return mDirection; }
	NVector3f& getPosition() { return mPosition; }

	void inputDirection(NVector3f&, NVector3f&); // DLL, to do
	void inputPosition(NVector3f&);              // DLL, to do

	// _00 = VTBL
	NVector3f mPosition;  // _04
	NVector3f mDirection; // _10
};

/**
 * @brief TODO
 */
struct NPlane {
	NPlane(NVector3f& normal, NVector3f& point);
	NPlane();                                   // unused/inlined
	NPlane(NVector3f&, f32);                    // unused/inlined
	NPlane(NVector3f&, NVector3f&, NVector3f&); // unused/inlined
	NPlane(Plane&);                             // unused/inlined
	NPlane(NPlane&);                            // unused/inlined

	virtual void transform(NTransform3D&); // _08
	virtual void println();                // _0C

	void construct(NVector3f& normal, NVector3f& point);
	void outputVerticalPosition(NVector3f&, NVector3f&);

	// unused/inlined:
	void construct(NVector3f&, f32);
	void construct(NVector3f&, NVector3f&, NVector3f&);
	void construct(Plane&);
	void construct(NPlane&);
	bool intersects(NLine&, f32*);
	bool outputIntersection(NLine&, NVector3f&);
	bool intersectsRay(NLine&, f32*);
	bool outputRayIntersection(NLine&, NVector3f&);
	bool intersectsSegment(NSegment&, f32*);
	bool outputSegmentIntersection(NSegment&, NVector3f&);
	void outputPosition(NVector3f&);
	void negate();
	bool adjustTo(NVector3f&, f32);
	bool adjust(NVector3f&);
	bool outputIntersectionLineY(NPlane&, NLine&);
	f32 calcAngle(NPlane&);
	f32 calcY(f32, f32);

	f32 judge(Vector3f& point) { return mNormal.dot(point) + mDifference; }

	void setDifference(Vector3f& point) { mDifference = -mNormal.dot(point); }

	NVector3f& getNormal() { return mNormal; }

	// _00 = VTBL
	NVector3f mNormal; // _04
	f32 mDifference;   // _10
};

/**
 * @brief TODO
 */
struct NSegment : public NLine {
	NSegment();                       // unused/inlined
	NSegment(NVector3f&, NVector3f&); // unused/inlined
	NSegment(NSegment&);              // unused/inlined

	virtual void transform(NTransform3D&); // _08
	virtual void println();                // _0C
	virtual void translate(NVector3f&);    // _10
	virtual void makeProjectionY();        // _14

	// unused/inlined:
	void construct(NVector3f&, NVector3f&);
	void construct(NSegment&);
	f32 calcDistanceAsSegment(NVector3f&, f32*, f32*);
	f32 calcDistanceAsSegment(NLine&, f32*, f32*);
	f32 calcSegmentDistanceAsSegment(NSegment&, f32*, f32*);

	NVector3f& getEdge();       // DLL, to do
	f32 calcLength();           // DLL, to do
	void inputEdge(NVector3f&); // DLL, to do
	void normalize();           // DLL, to do

	// _00     = VTBL
	// _00-_1C = NLine
	NVector3f mEdge; // _1C
};

#endif
