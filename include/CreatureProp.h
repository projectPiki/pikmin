#ifndef _CREATUREPROP_H
#define _CREATUREPROP_H

#include "types.h"
#include "Parameters.h"
#include "Ayu.h"

/**
 * @brief TODO
 *
 * @note Size: 0x58.
 */
struct CreatureProp {

	/**
	 * @brief TODO
	 */
	struct Properties : public Parameters {
		inline Properties()
		    : mFriction(this, 0.5f, 0.0f, 1.0f, "s00", "friction")
		    , mWallReflection(this, 0.5f, 0.0f, 1.0f, "s01", "wallReflection")
		    , mFaceDirAdjust(this, 0.25f, 0.0f, 1.0f, "s02", "faceDirAdjust")
		    , mAcceleration(this, 0.1f, 0.01f, 2.0f, "s03", "accel")
		    , mBounceFactor(this, 0.3f, 0.01f, 2.0f, "s04", "bounceFactor")
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
	Properties mCreatureProps; // _00

	virtual void read(struct RandomAccessStream& input) { mCreatureProps.Parameters::read(input); }; // _08
};

#endif
