#include "PUT/Geometry.h"

/*
 * --INFO--
 * Address:	801B3628
 * Size:	000024
 */
void PUTRect::set(int x0, int y0, int x1, int y1)
{
	mMin.x = x0;
	mMin.y = y0;

	mMax.x = x1;
	mMax.y = y1;
}

/*
 * --INFO--
 * Address:	801B364C
 * Size:	000024
 */
void PUTRect::copy(const PUTRect& other)
{
	mMin.x = other.mMin.x;
	mMin.y = other.mMin.y;

	mMax.x = other.mMax.x;
	mMax.y = other.mMax.y;
}

/*
 * --INFO--
 * Address:	........
 * Size:	000044
 */
void PUTRect::add(const PUTPoint& point)
{
	mMin.x += point.x;
	mMax.x += point.x;

	mMin.y += point.y;
	mMax.y += point.y;
}

/*
 * --INFO--
 * Address:	801B3670
 * Size:	000034
 */
void PUTRect::add(int x, int y)
{
	mMin.x += x;
	mMax.x += x;

	mMin.y += y;
	mMax.y += y;
}

/*
 * --INFO--
 * Address:	801B36A4
 * Size:	000080
 */
bool PUTRect::intersect(const PUTRect& other)
{
	if (mMin.x < other.mMin.x) {
		mMin.x = other.mMin.x;
	}

	if (mMin.y < other.mMin.y) {
		mMin.y = other.mMin.y;
	}

	if (mMax.x > other.mMax.x) {
		mMax.x = other.mMax.x;
	}

	if (mMax.y > other.mMax.y) {
		mMax.y = other.mMax.y;
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

	mMin.x = point.x;
	mMin.y = point.y;

	mMax.x = mMin.x + width;
	mMax.y = mMin.y + height;
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

	mMin.x = newMinX;
	mMin.y = newMinY;

	mMax.x = mMin.x + width;
	mMax.y = mMin.y + height;
}

/*
 * --INFO--
 * Address:	801B3768
 * Size:	00001C
 */
void PUTRect::resize(int width, int height)
{
	mMax.x = mMin.x + width;
	mMax.y = mMin.y + height;
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
	if (mMin.x > mMax.x) {
		int max = mMax.x;
		mMax.x  = mMin.x;
		mMin.x  = max;
	}

	if (mMin.y > mMax.y) {
		int max = mMax.y;
		mMax.y  = mMin.y;
		mMin.y  = max;
	}
}

/*
 * --INFO--
 * Address:	801B37C0
 * Size:	000030
 */
bool PUTRect::isEmpty() const
{
	return (mMin.x >= mMax.x) || (mMin.y >= mMax.y);
}
