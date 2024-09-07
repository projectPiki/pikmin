#ifndef _DELEGATE_H
#define _DELEGATE_H

#include "types.h"

/**
 * @brief Parent class for single argument delegates.
 */
template <typename A>
struct IDelegate1 {
	virtual void invoke(A) = 0; // _08
};

/**
 * @brief Parent class for double argument delegates.
 */
template <typename A, typename B>
struct IDelegate2 {
	virtual void invoke(A, B) = 0; // _08
};

/**
 * @brief Single argument delegates.
 *
 * @tparam T The type of the target object executing the member function.
 * @tparam A The type of the argument to supply to the member function.
 */
template <typename T, typename A>
struct Delegate1 : public IDelegate1<A> {
	typedef void (T::*CallbackFunc)(A);

	inline Delegate1(T target, CallbackFunc func)
	{
		mTarget   = target;
		mFunction = func;
	}

	virtual void invoke(A arg) { mTarget.*mCallback(arg); } // _08

	// _00     = VTBL
	// _00-_04 = IDelegate1
	T mTarget;              // _04
	CallbackFunc mCallback; // _08
};

/**
 * @brief Single argument delegates.
 *
 * @tparam T The type of the target object executing the member function.
 * @tparam A The type of the first argument to supply to the member function.
 * @tparam B The type of the second argument to supply to the member function.
 */
template <typename T, typename A, typename B>
struct Delegate2 : public IDelegate2<A, B> {
	typedef void (T::*CallbackFunc)(A, B);

	inline Delegate2(T target, CallbackFunc func)
	{
		mTarget   = target;
		mFunction = func;
	}

	virtual void invoke(A argA, B argB) { mTarget.*mCallback(argA, argB); } // _08

	// _00     = VTBL
	// _00-_04 = IDelegate2
	T mTarget;              // _04
	CallbackFunc mCallback; // _08
};

#endif
