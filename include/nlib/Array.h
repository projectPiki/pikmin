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

	virtual bool contains(T* elem) // _08
	{
		return indexOf(elem, 0) >= 0;
	}
	virtual int indexOf(T* elem) // _0C
	{
		return indexOf(elem, 0);
	}
	virtual int indexOf(T* elem, int startIdx) // _10
	{
		if (!elem) {
			return -1;
		}

		for (startIdx; startIdx < mCount; startIdx++) {
			if (mArray[startIdx] == elem) {
				return startIdx;
			}
		}

		return -1;
	}
	virtual void set(int idx, T* elem) // _14
	{
		if (idx >= 0 && idx <= mMax - 1) {
			mArray[idx] = elem;
			if (idx + 1 > mCount) {
				mCount = idx + 1;
			}
		}
	}
	virtual void add(T* elem) // _18
	{
		if (mCount < mMax) {
			mCount++;
		} else {
			return;
		}
		mArray[mCount - 1] = elem;
	}
	virtual void removeAll() // _1C
	{
		remove(0, mCount);
	}
	virtual void remove(int startIdx, int numToRemove) // _20
	{
		for (int i = 0; i < numToRemove; i++) {
			mArray[startIdx + i] = nullptr;
		}

		for (int i = 0; i < mCount - (startIdx + numToRemove); i++) {
			mArray[startIdx + i] = mArray[numToRemove + i];
		}
		mCount -= numToRemove;
	}
	virtual void remove(T* elem) // _24
	{
		remove(indexOf(elem));
	}
	virtual void remove(int idx) // _28
	{
		if (idx >= 0 && idx <= mCount - 1) {
			for (int i = idx; i < mCount - 1; i++) {
				mArray[i] = mArray[i + 1];
			}

			mCount--;
		}
	}
	virtual void add(int idx, T* elem) // _2C
	{
		if (idx >= mCount) {
			add(elem);
		} else {
			insert(idx, elem);
		}
	}
	virtual void insert(int idx, T* elem) // _30
	{
		if (idx < mCount) {
			for (int i = mCount; i >= idx + 1; i--) {
				mArray[i] = mArray[i - 1];
			}
			mArray[idx] = elem;
			mCount++;
		}
	}
	virtual T* get(int idx) // _34
	{
		if (idx < 0 || idx > mMax - 1) {
			return nullptr;
		}
		return mArray[idx];
	}
	virtual T* firstElement() { return get(0); }         // _38
	virtual T* lastElement() { return get(mCount - 1); } // _3C

	// DLL inlines:
	int getSize() { return mCount; }
	int getCapacity() { return mMax; } // NNode only

	// _00 = VTBL
	int mMax;   // _04, max size of array, a.k.a. capacity
	int mCount; // _08, current size of array, a.k.a. size
	T** mArray; // _0C
};

#endif
