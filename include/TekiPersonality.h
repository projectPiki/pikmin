#ifndef _TEKIPERSONALITY_H
#define _TEKIPERSONALITY_H

#include "ID32.h"
#include "ParaParameters.h"
#include "Vector.h"
#include "types.h"

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
		INT_NectarMinCount = 2,
		INT_NectarMaxCount = 3,
		INT_Parameter0     = 4,
		INT_ParamCount, // 5
	};

	/**
	 * @brief TODO
	 */
	enum FltParamTypes {
		FLT_Size               = 0,
		FLT_Strength           = 1,
		FLT_TerritoryRange     = 2,
		FLT_PelletAppearChance = 3,
		FLT_NectarAppearChance = 4,
		FLT_ParamCount, // 5
	};

	TekiPersonality();

	virtual void read(RandomAccessStream&, int); // _08
	virtual void write(RandomAccessStream&);     // _0C

	void reset();
	void input(TekiPersonality&);

	f32 getF(int idx) { return mParams->getF(idx); }
	int getI(int idx) { return mParams->getI(idx); }

	void setF(int idx, f32 val) { mParams->setF(idx, val); }
	void setI(int idx, int val) { mParams->setI(idx, val); }

	void genAge(AgeServer&);

	// _00 = VTBL
	Vector3f mPosition;           // _04
	Vector3f mNestPosition;       // _10
	f32 mFaceDirection;           // _1C
	int mPelletKind;              // _20
	int mPelletColor;             // _24
	ID32 mID;                     // _28
	ParaMultiParameters* mParams; // _34
};

#endif
