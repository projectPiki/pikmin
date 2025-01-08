#ifndef _GLOBALSHAPE_H
#define _GLOBALSHAPE_H

#include "types.h"

struct Shape;

/*
 * @brief TODO
 */
namespace GlobalShape {
void exitCourse();
void init();

extern Shape* arrowShape;
extern Shape* markerShape;
extern Shape* axisShape;
extern Shape* enShape;
extern Shape* markerShape2;
extern Shape* cursorShape;
} // namespace GlobalShape

#endif
