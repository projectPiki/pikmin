#ifndef _NEWPIKIGAME_H
#define _NEWPIKIGAME_H

#include "Interface.h"
#include "LifeGauge.h"
#include "MapMgr.h"
#include "MemStat.h"
#include "Section.h"
#include "jaudio/piki_scene.h"
#include "types.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct NewPikiGameSection : public Section {
	NewPikiGameSection();

	virtual void init() { } // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
