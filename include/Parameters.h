#ifndef _PARAMETERS_H
#define _PARAMETERS_H

#include "Ayu.h"
#include "types.h"

struct AgeServer;
struct Parameters;
struct RandomAccessStream;

/**
 * @brief TODO
 */
struct BaseParm {
	BaseParm(Parameters*, ayuID);

	// _08    = VTBL
	ayuID mID;       // _00
	BaseParm* mNext; // _04

#ifdef WIN32
	virtual void genAge(AgeServer&);
#endif

	virtual int size() = 0;                     // _08
	virtual void write(RandomAccessStream&) { } // _0C
	virtual void read(RandomAccessStream&) { }  // _10
};

/**
 * @brief TODO
 */
struct Parameters {
	Parameters() // this is Parameters(char*) in the DLL, but there's no char* mName in the DOL version.
	    : mHead(nullptr)
	{
	}

	void write(RandomAccessStream&);
	void read(RandomAccessStream&);

	// .dll exclusive functions
	void genAge(AgeServer&, int);
	void genAgeParms(AgeServer&, int);

	// unused/inlined:
	int sizeInFile();

	BaseParm* mHead; // _00
};

/**
 * @brief TODO
 *
 * @note Size: 0xC + sizeof(T) (so usually 0x10).
 */
template <typename T>
struct Parm : public BaseParm {
	Parm(Parameters* owner, T value, T min, T max, ayuID id, immut char* name)
	    : BaseParm(owner, id)
	{
		mValue = value;
#ifdef WIN32
		mDefaultValue = value;
		mMinValue     = min;
		mMaxValue     = max;
		mName         = name;
#endif
	}

	virtual int size() { return sizeof(T); } // _08
	virtual void write(RandomAccessStream&); // _0C
	virtual void read(RandomAccessStream&);  // _10

	T& operator()() { return mValue; }
	void operator()(T val) { mValue = val; }

	// _08     = VTBL
	// _00-_0C = BaseParm
	T mValue;          // _0C
#ifdef WIN32           //
	T mDefaultValue;   // _10
	T mMinValue;       // _14
	T mMaxValue;       // _18
	immut char* mName; // _1C
#endif
};

// For some reason, giving `CreatureProp::Parms` its parameter strings messes up matching.
#define MATCHING_PARM_NAME(name) TERNARY_BUILD_MATCHING(nullptr, name)

#endif
