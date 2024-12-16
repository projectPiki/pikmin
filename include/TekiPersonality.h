#ifndef _TEKIPERSONALITY_H
#define _TEKIPERSONALITY_H

#include "types.h"
#include "Vector.h"
#include "ID32.h"
#include "ParaParameters.h"

struct RandomAccessStream;
struct ParaMultiParameters;

/**
 * @brief TODO
 *
 * @note Size: 0x38.
 */
struct TekiPersonality {

	/**
	 * @brief TODO
	 */
	enum IntParamTypes {
		INT_PelletMinCount = 0,
		INT_PelletMaxCount = 1,
		INT_WaterMinCount  = 2,
		INT_WaterMaxCount  = 3,
		INT_Parameter0     = 4,
		INT_ParamCount, // 5
	};

	TekiPersonality();

	virtual void read(RandomAccessStream&, int); // _08
	virtual void write(RandomAccessStream&);     // _0C

	void reset();
	void input(TekiPersonality&);

	f32 getF(int idx) { return mParams->getF(idx); }
	int getI(int idx) { return mParams->getI(idx); }

	inline void init()
	{
		mPosition.set(Vector3f(0.0f, 0.0f, 0.0f));
		mScale.set(Vector3f(0.0f, 0.0f, 0.0f));
		mFaceDirection = 0.0f;
	}

	// _00 = VTBL
	Vector3f mPosition;           // _04
	Vector3f mScale;              // _10
	f32 mFaceDirection;           // _1C
	u32 _20;                      // _20, unknown
	u32 _24;                      // _24, unknown
	ID32 mID;                     // _28
	ParaMultiParameters* mParams; // _34
};

#endif
