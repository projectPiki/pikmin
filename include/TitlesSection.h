#ifndef _TITLESECTION_H
#define _TITLESECTION_H

#include "Section.h"
#include "types.h"

/**
 * @brief Game section for the title screen.
 *
 * Finer control is done by the `TitleSetupSection` node in this section's list.
 * The menus themselves are handled by zen::ogScrTitleMgr and zen::ogScrStartMgr (and zen::DrawHiScore for the hiscore screen).
 *
 * @note Size: 0x20.
 */
struct TitlesSection : public Section {
	virtual void init(); // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
