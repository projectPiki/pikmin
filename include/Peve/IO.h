#ifndef _PEVE_IO_H
#define _PEVE_IO_H

#include "types.h"
#include "nlib/Geometry.h"

struct Creature;
struct PcamCamera;

/**
 * @brief TODO
 */
struct PeveCameraPostureIO : public NPosture3DIO {
	PeveCameraPostureIO();

	virtual void input(NPosture3D&);  // _08
	virtual void output(NPosture3D&); // _0C

	void construct(PcamCamera*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveCameraViewpointIO : public NVector3fIO {
	PeveCameraViewpointIO();

	virtual void input(NVector3f&);  // _08
	virtual void output(NVector3f&); // _0C

	// unused/inlined:
	void construct(PcamCamera*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveCameraWatchpointIO : public NVector3fIO {
	PeveCameraWatchpointIO();

	virtual void input(NVector3f&);  // _08
	virtual void output(NVector3f&); // _0C

	// unused/inlined:
	void construct(PcamCamera*);

	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveClampVector3fIO : public NVector3fIOClass {
	PeveClampVector3fIO();

	virtual void input(NVector3f&); // _08

	void construct();

	// TODO: members
};

/**
 * @brief TODO
 */
struct PeveCreaturePositionIO : public NVector3fIO {
	PeveCreaturePositionIO();

	virtual void input(NVector3f&);  // _08
	virtual void output(NVector3f&); // _0C

	// unused/inlined:
	void construct(Creature*);

	// TODO: members
};

#endif
