#ifndef _MAPSELECT_H
#define _MAPSELECT_H

#include "types.h"
#include "Font.h"
#include "Section.h"
#include "Menu.h"
#include "Camera.h"
#include "system.h"
#include "zen/DrawWorldMap.h"
#include "zen/DrawCM.h"
#include "gameflow.h"
#include "Controller.h"

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
