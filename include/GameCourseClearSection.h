#ifndef _GAMECOURSECLEARSECTION_H
#define _GAMECOURSECLEARSECTION_H

#include "Camera.h"
#include "P2D/Screen.h"
#include "Parameters.h"
#include "Section.h"
#include "types.h"
#include "zen/DrawCM.h"
#include "zen/DrawContainer.h"
#include "zen/DrawCountDown.h"
#include "zen/DrawFinalResult.h"
#include "zen/DrawGameInfo.h"
#include "zen/DrawGameOver.h"
#include "zen/DrawHiScore.h"
#include "zen/DrawHurryUp.h"
#include "zen/DrawProgre.h"
#include "zen/DrawSave.h"
#include "zen/DrawUfoParts.h"
#include "zen/DrawWMPause.h"
#include "zen/DrawWorldMap.h"
#include "zen/particle.h"

struct Menu;
struct Font;
struct GameModeBase;

/**
 * @brief TODO
 *
 * @note Size: 0x10. In gameCourseClear.cpp for PRINT reasons.
 */
struct GameModeMgr;

/**
 * @brief TODO
 *
 * @note Size: 0x554. In gameCourseClear.cpp because of PRINT usage.
 */
struct GameCourseClearScreen;

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct GameCourseClearSection : public Section {
	GameCourseClearSection();

	virtual void init() { } // _30

	// _00     = VTBL
	// _00-_20 = Section
};

#endif
