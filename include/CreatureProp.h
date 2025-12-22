#ifndef _CREATUREPROP_H
#define _CREATUREPROP_H

#include "Ayu.h"
#include "Parameters.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct CreatureProp {

	/**
	 * @brief TODO
	 */
	struct Parms : public Parameters {
		inline Parms()
		    : mFriction(this, 0.5f, 0.0f, 1.0f, "s00", MATCHING_PARM_NAME("friction"))
		    , mWallReflection(this, 0.5f, 0.0f, 1.0f, "s01", MATCHING_PARM_NAME("wallReflection"))
		    , mFaceDirAdjust(this, 0.25f, 0.0f, 1.0f, "s02", MATCHING_PARM_NAME("faceDirAdjust"))
		    , mAcceleration(this, 0.1f, 0.01f, 2.0f, "s03", MATCHING_PARM_NAME("accel"))
		    , mBounceFactor(this, 0.3f, 0.01f, 2.0f, "s04", MATCHING_PARM_NAME("bounceFactor"))
		{
		}

		// _00-_04 = Parameters
		Parm<f32> mFriction;       // _04, s00
		Parm<f32> mWallReflection; // _14, s01
		Parm<f32> mFaceDirAdjust;  // _24, s02
		Parm<f32> mAcceleration;   // _34, s03
		Parm<f32> mBounceFactor;   // _44, s04
	};

	CreatureProp() { }

	// _54 = VTBL
	Parms mCreatureProps; // _00

	virtual void read(RandomAccessStream& input) { mCreatureProps.read(input); }; // _08
};

#endif
