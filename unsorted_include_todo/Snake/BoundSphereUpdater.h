#ifndef _SNAKE_BOUNDSPHEREUPDATER_H
#define _SNAKE_BOUNDSPHEREUPDATER_H

/**
 * .obj __vt__Q25Snake18BoundSphereUpdater, weak
 * .4byte __RTTI__Q25Snake18BoundSphereUpdater
 * .4byte 0
 * .4byte getPos__Q25Snake18BoundSphereUpdaterFv
 * .4byte getSize__Q25Snake18BoundSphereUpdaterFv
 */

namespace Snake {
/**
 * @brief TODO
 */
struct BoundSphereUpdater {
	virtual void getPos();  // _08
	virtual void getSize(); // _0C
};
} // namespace Snake

#endif
