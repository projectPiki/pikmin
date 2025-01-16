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
struct PelletShapeObject;

/**
 * @brief TODO
 *
 * @note Size: 0x60.
 */
struct PelletAnimInfo : public Parameters, public CoreNode {
	PelletAnimInfo();

	PelletShapeObject* createShapeObject();

	// _04     = VTBL 1
	// _58     = VTBL 2
	// _00-_04 = Parameters
	// _04-_18 = CoreNode
	ID32 mID;         // _18
	int _24;          // _24
	int mTekiType;    // _28, for corpses
	Parm<String> _2C; // _2C
	Parm<String> _40; // _40
	int _54;          // _54

	// why is this split like this.
	virtual void read(RandomAccessStream&); // _18

	PelletShapeObject* mPelletShapeObject; // _5C
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

	PaniPelletAnimator& getLowerAnimator() { return mLowerAnimator; }
	PaniPelletAnimator& getUpperAnimator() { return mUpperAnimator; }

	// DLL inlines:
	int getMainMotionIndex();

	PaniPelletAnimator mLowerAnimator; // _00
	PaniPelletAnimator mUpperAnimator; // _54
};

#endif
