#ifndef _NLIB_ARRAY_H
#define _NLIB_ARRAY_H

#include "types.h"

/**
 * @brief TODO
 */
template <typename T>
struct NArray {
	NArray(int max)
	{
		mMax   = max;
		mCount = 0;
		mArray = new T*[mMax];
		for (int i = 0; i < mMax; i++) {
			mArray[i] = nullptr;
		}
	}

	virtual void contains(T*);     // _08
	virtual void indexOf(T*);      // _0C
	virtual void indexOf(T*, int); // _10
	virtual void set(int, T*);     // _14
	virtual void add(T*);          // _18
	virtual void removeAll();      // _1C
	virtual void remove(int, int); // _20
	virtual void remove(T*);       // _24
	virtual void remove(int);      // _28
	virtual void add(int, T*);     // _2C
	virtual void insert(int, T*);  // _30
	virtual void get(int);         // _34
	virtual void firstElement();   // _38
	virtual void lastElement();    // _3C

	// _00 = VTBL
	int mMax;   // _04, max size of array
	int mCount; // _08, current size of array
	T** mArray; // _0C
};

#endif
