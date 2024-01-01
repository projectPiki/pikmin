#ifndef _COUNTDOWNMODE_H
#define _COUNTDOWNMODE_H

/**
 * .obj __vt__13CountDownMode, weak
 * .4byte __RTTI__13CountDownMode
 * .4byte 0
 * .4byte update__13CountDownModeFP10Controller
 * .4byte draw__13CountDownModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct CountDownMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
