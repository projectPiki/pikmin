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
	u32 _00; // _00, unknown
	T _04;   // _04, maybe min or max?
	T _08;   // _08, maybe min or max?
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

	T get(int);

	inline void input(ParaParameters* other)
	{
		for (int i = 0; i < mParaCount; i++) {
			mParameters[i] = other->mParameters[i];
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
	ParaParameterInfoI();

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
	ParaParameterInfoF();

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
	void getF(int);

	// _08 = VTBL
	ParaParametersI* mIntParams;   // _00
	ParaParametersF* mFloatParams; // _04

	// VTBL below members

	virtual void read(Stream&);  // _08
	virtual void write(Stream&); // _0C
	virtual void print();        // _10
};

#endif
