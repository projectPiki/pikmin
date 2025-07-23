#ifndef _GLOBALSHAPE_H
#define _GLOBALSHAPE_H

#include "types.h"

struct Shape;

/*
 * @brief TODO
 */
struct GlobalShape {
	static void exitCourse();
	static void init();

	static Shape* arrowShape;
	static Shape* markerShape;
	static Shape* axisShape;
	static Shape* enShape;
	static Shape* markerShape2;
	static Shape* cursorShape;
};

#endif
