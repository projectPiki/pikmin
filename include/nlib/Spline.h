#ifndef _NLIB_SPLINE_H
#define _NLIB_SPLINE_H

#include "nlib/Array.h"
#include "nlib/Function.h"
#include "nlib/Geometry3D.h"
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
public:
	SplineSegment();

	// unused/inlined:
	f32 calcDistance(NVector3f&, f32*);

	// DLL inlines:
	void outputPosition(f32 t, NVector3f& pos) { mFunction3D.outputPosition(t, pos); }

protected:
	NFunction3D mFunction3D;       // _00
	NPolynomialFunction mPolyFunX; // _0C
	NPolynomialFunction mPolyFunY; // _18
	NPolynomialFunction mPolyFunZ; // _24
	f32 mCoeffsX[4];               // _30
	f32 mCoeffsY[4];               // _40
	f32 mCoeffsZ[4];               // _50
};

/**
 * @brief TODO
 */
struct SplineCurve {
public:
	SplineCurve(int);

	void makeCurve(f32*, NVector3f**, int);
	SplineSegment* getSegment(int idx) { return mSegmentArray->get(idx); }
	int getSegmentCount();
	void addSegment(SplineSegment*);
	void removeAllSegments();

protected:
	static void makeFunctions(int, f32*, f32*, NPolynomialFunction**);

	NArray<SplineSegment>* mSegmentArray; // _00
};

/**
 * @brief TODO
 */
struct SplineKeyFrame {
public:
	SplineKeyFrame(); // unused/inlined

	// unused/inlined:
	virtual void interpolate(SplineKeyFrame&, f32, NPosture3D&); // _08
	virtual void transform(NTransform3D&);                       // _0C
	virtual void inputPosture(NPosture3D&);                      // _10
	virtual void outputPosture(NPosture3D&);                     // _14
	virtual void readData(Stream&, int);                         // _18

	// DLL inlines:
	NPosture3D& getPosture() { return mPosture; }
	f32 getParameter() { return mParameter; }

protected:
	// _00     = VTBL
	NPosture3D mPosture; // _04
	f32 mParameter;      // _20
};

/**
 * @brief TODO
 */
struct SplineInterpolator {
public:
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

	// DLL inlines:
	SplineKeyFrame* getFrame(int idx) { return mFrameArray->get(idx); }

protected:
	// TODO: members
	NArray<SplineKeyFrame>* mFrameArray; // _00
	NPool<SplineSegment>* _04;           // _04
	SplineCurve* mViewpointCurve;        // _08
	SplineCurve* mWatchpointCurve;       // _0C
	u8 _10;                              // _10
};

#endif
