#ifndef _PSU_TREE_H
#define _PSU_TREE_H

#include "types.h"
#include "PSU/LinkList.h"

/**
 * @brief TODO
 *
 * @note Size: 0x1C.
 */
template <typename T>
struct PSUTree : public PSUList<T>, public PSULink<T> {
	inline PSUTree(T* owner)
	    : PSUList<T>()
	    , PSULink<T>(owner)
	{
	}

	~PSUTree();

	PSUTree<T>* getFirstChild() const { return (PSUTree<T>*)getFirst(); }
	PSUTree<T>* getEndChild() const { return nullptr; }
	PSUTree<T>* getNextChild() const { return (PSUTree<T>*)mNext; }
	T* getObject() const { return (T*)mObject; }

	// DLL inlines to do:
	bool appendChild(PSUTree<T>* child) { return PSUList::append(child); }
	bool removeChild(PSUTree<T>* child);
	PSUTree<T>* getParent() const;

	// PSUList at _00
	// PSULink at _0C
};

/**
 * @brief TODO
 */
template <typename T>
struct PSUTreeIterator {
	PSUTreeIterator()
	    : mTree(nullptr)
	{
	}
	PSUTreeIterator(PSUTree<T>* tree)
	    : mTree(tree)
	{
	}

	// these are all the inlines according to the DLL:
	bool operator!=(const PSUTree<T>* other) const { return mTree != other; };

	PSUTreeIterator<T>& operator=(PSUTree<T>*); // DLL, to do

	PSUTreeIterator<T> operator++(int)
	{
		PSUTreeIterator<T> prev = *this;
		mTree                   = mTree->getNextChild();
		return prev;
	}

	PSUTreeIterator<T>& operator++()
	{
		mTree = mTree->getNextChild();
		return *this;
	}

	T* operator->() const { return mTree->getObject(); }
	T* getObject() const { return mTree->getObject(); }

	PSUTree<T>* mTree; // _00
};

#endif
