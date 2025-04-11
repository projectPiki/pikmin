#include "PUT/Geometry.h"

/*
 * --INFO--
 * Address:	801B3628
 * Size:	000024
 */
void PUTRect::set(int x0, int y0, int x1, int y1)
{
	mMinX = x0;
	mMinY = y0;

	mMaxX = x1;
	mMaxY = y1;
}

/*
 * --INFO--
 * Address:	801B364C
 * Size:	000024
 */
void PUTRect::copy(const PUTRect& other)
{
	mMinX = other.mMinX;
	mMinY = other.mMinY;

	mMaxX = other.mMaxX;
	mMaxY = other.mMaxY;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void PUTRect::add(const PUTPoint& point)
{
	mMinX += point.x;
	mMaxX += point.x;

	mMinY += point.y;
	mMaxY += point.y;
}

/*
 * --INFO--
 * Address:	801B3670
 * Size:	000034
 */
void PUTRect::add(int x, int y)
{
	mMinX += x;
	mMaxX += x;

	mMinY += y;
	mMaxY += y;
}

/*
 * --INFO--
 * Address:	801B36A4
 * Size:	000080
 */
bool PUTRect::intersect(const PUTRect& other)
{
	if (mMinX < other.mMinX) {
		mMinX = other.mMinX;
	}

	if (mMinY < other.mMinY) {
		mMinY = other.mMinY;
	}

	if (mMaxX > other.mMaxX) {
		mMaxX = other.mMaxX;
	}

	if (mMaxY > other.mMaxY) {
		mMaxY = other.mMaxY;
	}

	bool res = !isEmpty();
	// probably debug things here
	return res;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void PUTRect::move(const PUTPoint& point)
{
	s16 width  = getWidth();
	s16 height = getHeight();

	mMinX = point.x;
	mMinY = point.y;

	mMaxX = mMinX + width;
	mMaxY = mMinY + height;
}

/*
 * --INFO--
 * Address:	801B3724
 * Size:	000044
 */
void PUTRect::move(int newMinX, int newMinY)
{
	s16 width  = getWidth();
	s16 height = getHeight();

	mMinX = newMinX;
	mMinY = newMinY;

	mMaxX = mMinX + width;
	mMaxY = mMinY + height;
}

/*
 * --INFO--
 * Address:	801B3768
 * Size:	00001C
 */
void PUTRect::resize(int width, int height)
{
	mMaxX = mMinX + width;
	mMaxY = mMinY + height;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000034
 */
void PUTRect::reform(int, int, int, int)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	801B3784
 * Size:	00003C
 */
void PUTRect::normalize()
{
	if (mMinX > mMaxX) {
		int max = mMaxX;
		mMaxX   = mMinX;
		mMinX   = max;
	}

	if (mMinY > mMaxY) {
		int max = mMaxY;
		mMaxY   = mMinY;
		mMinY   = max;
	}
}

/*
 * --INFO--
 * Address:	801B37C0
 * Size:	000030
 */
bool PUTRect::isEmpty() const
{
	return (mMinX >= mMaxX) || (mMinY >= mMaxY);
}
