#ifndef _NLIB_GEOMETRY3D_H
#define _NLIB_GEOMETRY3D_H

#include "types.h"
#include "nlib/Geometry.h"

struct NSegment;
struct Plane;

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
	void calcDistance(NVector3f&, f32*);
	void calcVerticalProjection(NVector3f&);
	void outputPosition(f32, NVector3f&);

	// unused/inlined:
	void construct(NLine&);
	void calcDistance(NLine&, f32*, f32*);
	void outputVerticalPosition(NVector3f&, NVector3f&);
	void outputPositionY(f32, NVector3f&);

	// _00 = VTBL
	NVector3f mStart;     // _04
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
	void intersects(NLine&, f32*);
	void outputIntersection(NLine&, NVector3f&);
	void intersectsRay(NLine&, f32*);
	void outputRayIntersection(NLine&, NVector3f&);
	void intersectsSegment(NSegment&, f32*);
	void outputSegmentIntersection(NSegment&, NVector3f&);
	void outputPosition(NVector3f&);
	void negate();
	void adjustTo(NVector3f&, f32);
	void adjust(NVector3f&);
	void outputIntersectionLineY(NPlane&, NLine&);
	void calcAngle(NPlane&);
	void calcY(f32, f32);

	// _00 = VTBL
	NVector3f mNormal; // _04
	f32 mOffset;       // _10
};

/**
 * @brief TODO
 */
struct NSegment {
	NSegment();                       // unused/inlined
	NSegment(NVector3f&, NVector3f&); // unused/inlined
	NSegment(NSegment&);              // unused/inlined

	// unused/inlined:
	void construct(NVector3f&, NVector3f&);
	void construct(NSegment&);
	void calcDistanceAsSegment(NVector3f&, f32*, f32*);
	void calcDistanceAsSegment(NLine&, f32*, f32*);
	void calcSegmentDistanceAsSegment(NSegment&, f32*, f32*);
	void transform(NTransform3D&);
	void translate(NVector3f&);
	void makeProjectionY();
	void println();

	// TODO: members
};

#endif
