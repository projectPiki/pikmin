#ifndef _COMMON_LLIST_H
#define _COMMON_LLIST_H

#include "types.h"

#include "assert_line.h"
#include "sysNew.h"

/**
 * @brief A container implementing a contiguous dynamic array (contrary to the name of this header suggesting it's a linked list).
 * This container assumes `T` is a non-owning pointer (or some other primitive type) and is worse than `std::vector` in many ways.
 * The member variables of this class don't use hungarian notation because the assertions' stringized conditions need their names.
 * @note Size: 0x0C
 */
template <typename T>
class List {
public:
	/**
	 * @param s The initial capacity of this container.
	 * @warning If `s == 0`, then it is up to the user to call `allocate` before using other member functions.
	 */
	List(int s = 0)
	{
		num        = 0;
		array_size = 0;
		element    = nullptr;
		if (s != 0) {
			allocate(s);
		}
	}

	/**
	 * @brief Automatically frees allocated memory.
	 */
	~List()
	{
		// This technically doesn't matter to Pikmin's `operator delete`, but it's wrong and it happens all over this file.
		TERNARY_BUGFIX(delete[], delete) element;
	}

	/**
	 * @brief Bounds-checked access to `element` (enforced by a debug assertion).
	 */
	T& operator[](int i)
	{
		assert_line(i>=0 && i<num, 33);
		return element[i];
	}

	/**
	 * @brief Bounds-checked access to `element` (enforced by a debug assertion).
	 * @note This is a fabricated member function to support const-correct usage.
	 */
	const T& operator[](int i) const
	{
		assert_line(i>=0 && i<num, 33);
		return element[i];
	}

	/**
	 * @brief Copies elements to new storage of capacity `s` greater or equal to the
	 * number of active elements in the container (enforced by a debug assertion).
	 * @warning `s == 0` is not allowed by this function (enforced by a debug assertion).
	 */
	void allocate(int s)
	{
		assert_line(s>0, 53);
		assert_line(s>=num, 54);
		T* old_element = element;

		array_size = s;
		element    = new T[array_size];
		assert_line(element, 58);

		for (int i = 0; i < num; ++i) {
			element[i] = old_element[i];
		}

		if (old_element) {
			TERNARY_BUGFIX(delete[], delete) old_element;
		}
	}

	/**
	 * @brief Reallocates storage to fit `s` elements, then sets the number of active elements in the container to `s`.
	 * If called by `SetSize(0)`, then the storage of the container is reset as if the constructor `List(0)` was called.
	 * @warning If `s == 0`, then it is up to the user to call `allocate` before using other member functions.
	 */
	void SetSize(int s)
	{
		if (s == 0) {
			if (element) {
				TERNARY_BUGFIX(delete[], delete) element;
				element = nullptr;
			}
			array_size = 0;
		} else {
			allocate(s);
		}
		num = s;
	}

	/**
	 * @brief Appends `t` to the active elements of the container, reallocating storage if it is necessary to do so.
	 */
	void Add(T t)
	{
		assert_line(num<=array_size, 87);
		if (num == array_size) {
			allocate(array_size != 0 ? array_size * 2 : 16);
		}
		element[num++] = t;
	}

	/**
	 * @brief Appends `t` to the active elements of the container by calling `Add(t)` iff `t` is not equal to an existing element.
	 * @return `true` if `t` was successfully added to the container, otherwise `false`.
	 */
	bool AddUnique(T t)
	{
		if (Contains(t) == 0) {
			Add(t);
			return true;
		}
		return false;
	}

	/**
	 * @brief Discard the element at index `i` of the container, copying subsequent elements back one place.
	 */
	void DelIndex(int i)
	{
		assert_line(i<num, 125);
		--num;
		while (i < num) {
			element[i] = element[i + 1];
			++i;
		}
	}

	/**
	 * @brief Discard the first element in the container equal to `t` by calling `DelIndex(index of first element equal to t)`.
	 * @warning This function assumes only one element within the container is equal to `t` (enforced by a debug assertion).
	 */
	void Remove(T t)
	{
		int i;

		for (i = 0; i < num; ++i) {
			if (element[i] == t) {
				break;
			}
		}
		DelIndex(i);
		for (i = 0; i < num; ++i) {
			assert_line(element[i] != t, 143);
		}
	}

	/**
	 * @return The index of the first element in the container equal to `t`, or `0`(!) if one is not found.
	 */
	int Find(T t) immut
	{
		int i;

		for (i = 0; i < num; ++i) {
			if (element[i] == t) {
				return i;
			}
		}
		return 0; // Surely this is fine :^)
	}

	/**
	 * @return The number of elements in the container equal to `t`.
	 */
	int Contains(T t) immut
	{
		int i;

		int count = 0;
		for (i = 0; i < num; ++i) {
			if (element[i] == t) {
				++count;
			}
		}
		return count;
	}

	// The stringized assertions require specific names.
	T* element;     // _00, Contiguous storage for elements
	int num;        // _04, Number of active elements
	int array_size; // _08, Capacity of the container
};

#endif
