#ifndef _CONTAINERMODE_H
#define _CONTAINERMODE_H

/**
 * .obj __vt__13ContainerMode, weak
 * .4byte __RTTI__13ContainerMode
 * .4byte 0
 * .4byte update__13ContainerModeFP10Controller
 * .4byte draw__13ContainerModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct ContainerMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
