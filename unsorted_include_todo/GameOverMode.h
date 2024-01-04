#ifndef _GAMEOVERMODE_H
#define _GAMEOVERMODE_H

/**
 * .obj __vt__12GameOverMode, weak
 * .4byte __RTTI__12GameOverMode
 * .4byte 0
 * .4byte update__12GameOverModeFP10Controller
 * .4byte draw__12GameOverModeFR8Graphics
 */

/**
 * @brief TODO
 */
struct GameOverMode {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C
};

#endif
