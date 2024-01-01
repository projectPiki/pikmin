#ifndef _SLIME_BOUNDSPHEREUPDATER_H
#define _SLIME_BOUNDSPHEREUPDATER_H

/**
 * .obj __vt__Q25Slime18BoundSphereUpdater, weak
 * .4byte __RTTI__Q25Slime18BoundSphereUpdater
 * .4byte 0
 * .4byte getPos__Q25Slime18BoundSphereUpdaterFv
 * .4byte getSize__Q25Slime18BoundSphereUpdaterFv
*/

namespace Slime {
/**
 * @brief TODO
 */
struct BoundSphereUpdater {
	virtual void getPos();  // _08
	virtual void getSize(); // _0C

};
} // namespace Slime

#endif
