#ifndef _PUT_GEOMETRY_H
#define _PUT_GEOMETRY_H

#include "Stream.h"
#include "types.h"

/**
 * @brief TODO
 */
struct PUTPoint {
	PUTPoint()
	{
		x = 0;
		y = 0;
	}

	s16 x, y; // _00, _02
};

/**
 * @brief TODO
 *
 * @note Size: 0x8.
 */
struct PUTRect {
	PUTRect() { set(0, 0, 0, 0); }
	PUTRect(int maxX, int maxY) { set(0, 0, maxX, maxY); }
	PUTRect(int x0, int y0, int x1, int y1) { set(x0, y0, x1, y1); }

	PUTRect(const PUTRect& other) { copy(other); }

	void set(int x0, int y0, int x1, int y1);
	void copy(const PUTRect& other);
	void add(int x, int y);
	bool intersect(const PUTRect& other);
	void move(int newMinX, int newMinY);
	void resize(int width, int height);
	void normalize();
	bool isEmpty() const;

	int getWidth() const { return mMaxX - mMinX; }
	int getHeight() const { return mMaxY - mMinY; }

	// unused/inlined:
	void add(const PUTPoint&);
	void move(const PUTPoint&);
	void reform(int, int, int, int);

	s16 mMinX; // _00
	s16 mMinY; // _02
	s16 mMaxX; // _04
	s16 mMaxY; // _06
};

#endif
