#ifndef _NEWPIKIGAME_H
#define _NEWPIKIGAME_H

#include "types.h"
#include "LifeGauge.h"
#include "MemStat.h"
#include "Section.h"
#include "MapMgr.h"
#include "jaudio/PikiScene.h"
#include "Interface.h"

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
