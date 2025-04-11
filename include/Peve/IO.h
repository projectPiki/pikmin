#ifndef _PEVE_IO_H
#define _PEVE_IO_H

#include "types.h"
#include "nlib/Geometry.h"
#include "Creature.h"
#include "Pcam/Camera.h"

struct Creature;
struct PcamCamera;

/**
 * @brief TODO
 */
struct PeveCameraPostureIO : public NPosture3DIO {
	PeveCameraPostureIO();

	virtual void input(NPosture3D& posture) { mCamera->inputPosture(posture); }         // _08
	virtual void output(NPosture3D& outPosture) { mCamera->outputPosture(outPosture); } // _0C

	void construct(PcamCamera*);

	// _00     = VTBL
	// _00-_04 = NPosture3DIO
	PcamCamera* mCamera; // _04
};

/**
 * @brief TODO
 */
struct PeveCameraViewpointIO : public NVector3fIO {
	PeveCameraViewpointIO();

	virtual void input(NVector3f& viewPt) { mCamera->inputViewpoint(viewPt); }              // _08
	virtual void output(NVector3f& outViewPt) { outViewPt.input(mCamera->getViewpoint()); } // _0C

	// unused/inlined:
	void construct(PcamCamera*);

	// _00     = VTBL
	// _00-_04 = NVector3fIO
	PcamCamera* mCamera; // _04
};

/**
 * @brief TODO
 */
struct PeveCameraWatchpointIO : public NVector3fIO {
	PeveCameraWatchpointIO();

	virtual void input(NVector3f& watchPt) { mCamera->inputWatchpoint(watchPt); }              // _08
	virtual void output(NVector3f& outWatchPt) { outWatchPt.input(mCamera->getWatchpoint()); } // _0C

	// unused/inlined:
	void construct(PcamCamera*);

	// _00     = VTBL
	// _00-_04 = NVector3fIO
	PcamCamera* mCamera; // _04
};

/**
 * @brief TODO
 */
struct PeveClampVector3fIO : public NVector3fIOClass {
	PeveClampVector3fIO();

	virtual void input(NVector3f&); // _08

	void construct();

	// DLL inlines:
	void setMaxLength(f32 max) { mMaxLength = max; }

	// _00     = VTBL
	// _00-_10 = NVector3fIOClass
	f32 mMaxLength; // _10
};

/**
 * @brief TODO
 */
struct PeveCreaturePositionIO : public NVector3fIO {
	PeveCreaturePositionIO();

	virtual void input(NVector3f& vec) { mCreature->inputPosition(vec); }         // _08
	virtual void output(NVector3f& outVec) { mCreature->outputPosition(outVec); } // _0C

	// unused/inlined:
	void construct(Creature*);

	// _00     = VTBL
	// _00-_04 = NVector3fIO
	Creature* mCreature; // _04
};

#endif
