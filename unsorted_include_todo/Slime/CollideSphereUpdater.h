#ifndef _SLIME_COLLIDESPHEREUPDATER_H
#define _SLIME_COLLIDESPHEREUPDATER_H

/**
 * .obj __vt__Q25Slime20CollideSphereUpdater, weak
 * .4byte __RTTI__Q25Slime20CollideSphereUpdater
 * .4byte 0
 * .4byte getPos__Q25Slime20CollideSphereUpdaterFv
 * .4byte getSize__Q25Slime20CollideSphereUpdaterFv
*/

namespace Slime {
/**
 * @brief TODO
 */
struct CollideSphereUpdater {
	virtual void getPos();  // _08
	virtual void getSize(); // _0C

};
} // namespace Slime

#endif
