#ifndef _PELLETANIMATOR_H
#define _PELLETANIMATOR_H

#include "types.h"
#include "CoreNode.h"
#include "Parameters.h"
#include "PaniAnimator.h"
#include "String.h"

struct PaniAnimKeyListener;
struct PaniMotionInfo;
struct PaniMotionTable;

/**
 * @brief TODO
 *
 * @note Size: 0x5C.
 */
struct PelletAnimInfo : public Parameters, public CoreNode {
	PelletAnimInfo();

	void createShapeObject();

	// _04     = VTBL 1
	// _58     = VTBL 2
	// _00-_04 = Parameters
	// _04-_18 = CoreNode
	ID32 mID;            // _18
	u8 _24[0x58 - 0x24]; // _24, unknown

	virtual void read(RandomAccessStream&); // _18
};

/**
 * @brief TODO
 */
struct PelletAnimator {
	PelletAnimator();

	void init(AnimContext*, AnimContext*, AnimMgr*, PaniMotionTable*);
	void finishMotion(PaniMotionInfo*, PaniMotionInfo*);
	void startMotion(PaniMotionInfo&, PaniMotionInfo&);
	void startMotion(PaniMotionInfo&);
	void updateAnimation(f32, f32);
	void updateContext();

	// unused/inlined:
	void startMotion(PaniMotionInfo*, PaniMotionInfo*);
	void finishMotion(PaniAnimKeyListener*);

	PaniPelletAnimator _00; // _00
	PaniPelletAnimator _54; // _54
};

#endif
