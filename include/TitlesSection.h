#ifndef _TITLESECTION_H
#define _TITLESECTION_H

#include "types.h"
#include "Section.h"
#include "Camera.h"
#include "Light.h"
#include "Font.h"
#include "sysNew.h"
#include "CinematicPlayer.h"
#include "gameflow.h"
#include "Interface.h"
#include "zen/ogStart.h"
#include "zen/DrawHiScore.h"
#include "zen/ogTitle.h"
#include "Menu.h"
#include "DayMgr.h"

extern zen::ogScrStartMgr* startWindow;
extern zen::ogScrTitleMgr* titleWindow;
extern zen::DrawHiScore* totalWindow;
extern bool startWindowOn;
extern bool titleWindowOn;
extern bool totalWindowOn;

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct TitlesSection : public Section {
	virtual void init(); // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
