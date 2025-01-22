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
	f32 calcDistance(NVector3f&, f32*);

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
	// TODO: add offset comments once we know what this inherits from
	virtual void transform(NTransform3D&);
	virtual void inputPosture(NPosture3D&);
	virtual void outputPosture(NPosture3D&);
	virtual void interpolate(SplineKeyFrame&, f32, NPosture3D&);
	virtual void readData(Stream&, int);

	// TODO: members
};

/**
 * @brief TODO
 */
struct SplineInterpolator {
	SplineInterpolator(int, NPool<SplineSegment>*); // unused/inlined

	void reset();
	bool interpolateNext(f32, NPosture3D&);
	void outputPosture(f32, NPosture3D&);
	int searchSegmentIndex(f32, int);

	// unused/inlined:
	void makeSpline();
	bool interpolate(f32, NPosture3D&, bool);
	bool interpolateDirect(f32, NPosture3D&);
	void addFrame(SplineKeyFrame*);
	void addSegment();
	void removeAllFrames();

	// TODO: members
};

#endif
