#ifndef _CMCOURSESELECTMODE_H
#define _CMCOURSESELECTMODE_H

/**
 * .obj __vt__18CMcourseSelectMode, weak
 * .4byte __RTTI__18CMcourseSelectMode
 * .4byte 0
 * .4byte update__18CMcourseSelectModeFP10Controller
 * .4byte draw__18CMcourseSelectModeFR8Graphics
 */

/**
 * @brief TODO
 */
struct CMcourseSelectMode {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C
};

#endif
