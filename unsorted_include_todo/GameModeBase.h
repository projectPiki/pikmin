#ifndef _GAMEMODEBASE_H
#define _GAMEMODEBASE_H

/**
 * .obj __vt__12GameModeBase, weak
 * .4byte __RTTI__12GameModeBase
 * .4byte 0
 * .4byte update__12GameModeBaseFP10Controller
 * .4byte draw__12GameModeBaseFR8Graphics
 */

/**
 * @brief TODO
 */
struct GameModeBase {
	virtual void update(Controller*); // _08
	virtual void draw(Graphics&);     // _0C
};

#endif
