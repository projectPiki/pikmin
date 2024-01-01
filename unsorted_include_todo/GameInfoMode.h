#ifndef _GAMEINFOMODE_H
#define _GAMEINFOMODE_H

/**
 * .obj __vt__12GameInfoMode, weak
 * .4byte __RTTI__12GameInfoMode
 * .4byte 0
 * .4byte update__12GameInfoModeFP10Controller
 * .4byte draw__12GameInfoModeFR8Graphics
*/

/**
 * @brief TODO
 */
struct GameInfoMode {
	virtual void update(Controller *);  // _08
	virtual void draw(Graphics &);      // _0C

};

#endif
