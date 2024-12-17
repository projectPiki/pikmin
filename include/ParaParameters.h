#ifndef _PARAPARAMETERS_H
#define _PARAPARAMETERS_H

#include "types.h"
#include "sysNew.h"

struct Stream;

/**
 * @brief TODO
 */
template <typename T>
struct ParaParameterInfo {

	inline void set(char* name, T min, T max)
	{
		mName = name;
		mMin  = min;
		mMax  = max;
	}

	char* mName; // _00
	T mMin;      // _04
	T mMax;      // _08
};

/**
 * @brief TODO
 */
template <typename T>
struct ParaParameters {
	ParaParameters(int count, ParaParameterInfo<T>* info)
	{
		mParaCount = count;
		mParaInfo  = info;
		if (mParaCount > 0) {
			mParameters = new T[mParaCount];
		} else {
			mParameters = nullptr;
		}

		for (int i = 0; i < mParaCount; i++) {
			mParameters[i] = 0;
		}
	}

	T get(int idx) { return mParameters[idx]; }

	void set(int idx, T val) { mParameters[idx] = val; }

	inline void input(ParaParameters* other)
	{
		for (int i = 0; i < mParaCount; i++) {
			mParameters[i] = other->mParameters[i];
		}
	}

	inline void readIn(RandomAccessStream& input, int count)
	{
		for (int i = 0; i <= count; i++) {
			mParameters[i] = input.readInt();
		}
	}

	// _0C = VTBL
	T* mParameters;                  // _00
	int mParaCount;                  // _04
	ParaParameterInfo<T>* mParaInfo; // _08

	// VTBL below members

	virtual void read(Stream&) { }  // _08
	virtual void write(Stream&) { } // _0C
	virtual void print() { }        // _10
};

/*
 * @brief TODO
 */
struct ParaParameterInfoI : public ParaParameterInfo<int> {
	ParaParameterInfoI()
	{
		mName = nullptr;
		mMin  = 0;
		mMax  = 0;
	}

	// TODO: members
};

/**
 * @brief TODO
 */
struct ParaParametersI : public ParaParameters<int> {
	ParaParametersI(int, ParaParameterInfoI*); // unused/inlined

	virtual void read(Stream&);  // _08
	virtual void write(Stream&); // _0C
	virtual void print();        // _10

	// TODO: members
};

/*
 * @brief TODO
 */
struct ParaParameterInfoF : public ParaParameterInfo<f32> {
	ParaParameterInfoF()
	{
		mName = nullptr;
		mMin  = 0.0f;
		mMax  = 0.0f;
	}

	inline void set(char* name, f32 min, f32 max) { ParaParameterInfo<f32>::set(name, min, max); }

	// TODO: members
};

/**
 * @brief TODO
 */
struct ParaParametersF : public ParaParameters<f32> {
	ParaParametersF(int, ParaParameterInfoF*); // unused/inlined

	virtual void read(Stream&);  // _08
	virtual void write(Stream&); // _0C
	virtual void print();        // _10

	// TODO: members
};

/**
 * @brief TODO
 */
struct ParaMultiParameters {
	ParaMultiParameters(int, ParaParameterInfoI*, int, ParaParameterInfoF*);

	void input(ParaMultiParameters&);

	f32 getF(int idx) { return mFloatParams->get(idx); }
	int getI(int idx) { return mIntParams->get(idx); }

	void setF(int idx, f32 val) { mFloatParams->set(idx, val); }
	void setI(int idx, int val) { mIntParams->set(idx, val); }

	ParaParameterInfoI* getInfoI(int idx) { return static_cast<ParaParameterInfoI*>(&mIntParams->mParaInfo[idx]); }

	// _08 = VTBL
	ParaParametersI* mIntParams;   // _00
	ParaParametersF* mFloatParams; // _04

	// VTBL below members

	virtual void read(Stream&);  // _08
	virtual void write(Stream&); // _0C
	virtual void print();        // _10
};

#endif
