#ifndef _TEKIPERSONALITY_H
#define _TEKIPERSONALITY_H

#include "types.h"
#include "Vector.h"
#include "ID32.h"

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

	void getF(int);

	// _00 = VTBL
	Vector3f _04;                 // _04
	Vector3f _10;                 // _10
	f32 _1C;                      // _1C
	u32 _20;                      // _20, unknown
	u32 _24;                      // _24, unknown
	ID32 mID;                     // _28
	ParaMultiParameters* mParams; // _34
};

#endif
