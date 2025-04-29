#ifndef _GAMECOURSECLEARSECTION_H
#define _GAMECOURSECLEARSECTION_H

#include "types.h"
#include "Section.h"
#include "Parameters.h"
#include "zen/particle.h"
#include "P2D/Screen.h"
#include "zen/DrawFinalResult.h"
#include "zen/DrawSave.h"
#include "zen/DrawUfoParts.h"
#include "zen/DrawHiScore.h"
#include "zen/DrawGameInfo.h"
#include "zen/DrawGameOver.h"
#include "zen/DrawContainer.h"
#include "zen/DrawCountDown.h"
#include "zen/DrawCM.h"
#include "zen/DrawWMPause.h"
#include "zen/DrawWorldMap.h"
#include "zen/DrawProgre.h"
#include "zen/DrawHurryUp.h"
#include "Camera.h"

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
