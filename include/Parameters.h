#ifndef _PARAMETERS_H
#define _PARAMETERS_H

#include "types.h"

struct Parameters;

/**
 * @brief TODO
 */
struct BaseParm {
	BaseParm(Parameters*, struct ayuID);

	// _08    = VTBL
	char* mID;       // _00
	BaseParm* mNext; // _04

	virtual int size() = 0;                            // _08
	virtual void write(struct RandomAccessStream&) { } // _0C
	virtual void read(RandomAccessStream&) { }         // _10
};

/**
 * @brief TODO
 */
struct Parameters {
	void write(RandomAccessStream&);
	void read(RandomAccessStream&);

	// unused/inlined:
	void sizeInFile();

	BaseParm* mHead; // _00
};

/**
 * @brief TODO
 */
template <typename T>
struct Parm : public BaseParm {
	Parm(Parameters*, T, T, T, ayuID, char*);

	virtual int size();                             // _08
	virtual void write(struct RandomAccessStream&); // _0C
	virtual void read(RandomAccessStream&);         // _10

	inline T& operator()() { return mValue; }

	// _08     = VTBL
	// _00-_0C = BaseParm
	T mValue; // _0C
};

#endif
