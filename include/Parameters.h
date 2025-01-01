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
	inline Parameters()
	    : mHead(nullptr)
	{
	}

	void write(RandomAccessStream&);
	void read(RandomAccessStream&);

	inline void addToEnd(BaseParm* newNode)
	{
		BaseParm* node;
		for (node = mHead; node; node = node->mNext) {
			node->mID;
		}

		BaseParm* last = nullptr;
		for (node = mHead; node; node = node->mNext) {
			last = node;
		}

		if (last) {
			last->mNext = newNode;
		} else {
			mHead = newNode;
		}
	}

	// unused/inlined:
	void sizeInFile();

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

	virtual int size();                             // _08
	virtual void write(struct RandomAccessStream&); // _0C
	virtual void read(RandomAccessStream&);         // _10

	inline T& operator()() { return mValue; }
	inline void operator()(f32 val) { mValue = val; }

	inline void setValue(T val) { mValue = val; }

	// _08     = VTBL
	// _00-_0C = BaseParm
	T mValue; // _0C
};

#endif
