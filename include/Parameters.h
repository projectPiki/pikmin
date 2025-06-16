#ifndef _PARAMETERS_H
#define _PARAMETERS_H

#include "types.h"
#include "Ayu.h"

struct Parameters;
struct AgeServer;

/**
 * @brief TODO
 */
struct BaseParm {
	BaseParm(Parameters*, ayuID);

	// _08    = VTBL
	char* mID;       // _00
	BaseParm* mNext; // _04

#ifdef DEVELOP
	virtual void genAge(AgeServer&);
#endif

	virtual int size() = 0;                            // _08
	virtual void write(struct RandomAccessStream&) { } // _0C
	virtual void read(RandomAccessStream&) { }         // _10
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
	Parm(Parameters* owner, T value, T min, T max, ayuID id, char* str)
	    : BaseParm(owner, id)
	{
		mValue = value;
	}

	virtual int size() { return sizeof(T); }        // _08
	virtual void write(struct RandomAccessStream&); // _0C
	virtual void read(RandomAccessStream&);         // _10

	T& operator()() { return mValue; }
	void operator()(T val) { mValue = val; }

	// _08     = VTBL
	// _00-_0C = BaseParm
	T mValue; // _0C
};

#endif
