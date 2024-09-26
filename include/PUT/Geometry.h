#ifndef _PUT_GEOMETRY_H
#define _PUT_GEOMETRY_H

#include "types.h"

/**
 * @brief TODO
 */
struct PUTPoint {
	// TODO: members
};

/**
 * @brief TODO
 */
struct PUTRect {
	void set(int, int, int, int);
	void copy(const PUTRect&);
	void add(int, int);
	void intersect(const PUTRect&);
	void move(int, int);
	void resize(int, int);
	void normalize();
	void isEmpty() const;
	s16 getWidth() const;
	s16 getHeight() const;

	// unused/inlined:
	void add(const PUTPoint&);
	void move(const PUTPoint&);
	void reform(int, int, int, int);

	// TODO: members
};

#endif
