#ifndef _NLIB_SPLINE_H
#define _NLIB_SPLINE_H

#include "types.h"

struct NPolynomialFunction;
struct NPosture3D;
struct NTransform3D;
struct NVector3f;
struct Stream;

/**
 * @brief TODO
 */
template <typename T>
struct NPool {

	void newObject();
	void deleteObject(T*);
	void deleteObject(int);
	void indexOf(T*);
	void indexOf(T*, int);

	// TODO: members
};

/**
 * @brief TODO
 */
struct SplineSegment {
	SplineSegment();

	// unused/inlined:
	void calcDistance(NVector3f&, f32*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct SplineCurve {
	SplineCurve(int);

	// unused/inlined:
	void makeCurve(f32*, NVector3f**, int);
	void makeFunctions(int, f32*, f32*, NPolynomialFunction**);

	// TODO: members
};

/**
 * @brief TODO
 */
struct SplineKeyFrame {
	SplineKeyFrame(); // unused/inlined

	// unused/inlined:
	void transform(NTransform3D&);
	void inputPosture(NPosture3D&);
	void outputPosture(NPosture3D&);
	void interpolate(SplineKeyFrame&, f32, NPosture3D&);
	void readData(Stream&, int);

	// TODO: members
};

/**
 * @brief TODO
 */
struct SplineInterpolator {
	SplineInterpolator(int, NPool<SplineSegment>*); // unused/inlined

	void reset();
	void interpolateNext(f32, NPosture3D&);
	void outputPosture(f32, NPosture3D&);
	void searchSegmentIndex(f32, int);

	// unused/inlined:
	void makeSpline();
	void interpolate(f32, NPosture3D&, bool);
	void interpolateDirect(f32, NPosture3D&);
	void addFrame(SplineKeyFrame*);
	void addSegment();
	void removeAllFrames();

	// TODO: members
};

#endif
