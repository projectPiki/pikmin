#ifndef _PSU_TREE_H
#define _PSU_TREE_H

#include "types.h"

/**
 * @brief TODO
 */
template <typename T>
struct PSUTree {
	~PSUTree();

	PSUTree<T>* getFirstChild() const;
	PSUTree<T>* getEndChild() const;

	// TODO: members
};

#endif
