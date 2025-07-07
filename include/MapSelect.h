#ifndef _MAPSELECT_H
#define _MAPSELECT_H

#include "Camera.h"
#include "Controller.h"
#include "Font.h"
#include "Menu.h"
#include "Section.h"
#include "gameflow.h"
#include "system.h"
#include "types.h"
#include "zen/DrawCM.h"
#include "zen/DrawWorldMap.h"

struct Menu;
struct Font;

extern zen::DrawWorldMap* mapWindow;
extern zen::DrawCMcourseSelect* selectWindow;

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct MapSelectSection : public Section {
	MapSelectSection();

	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
