#ifndef _SPLINEINTERPOLATOR_H
#define _SPLINEINTERPOLATOR_H

/*
 * @brief TODO
 */
struct SplineInterpolator {
	void reset();
	void interpolateNext(float, NPosture3D&);
	void outputPosture(float, NPosture3D&);
	void searchSegmentIndex(float, int);
};

#endif
