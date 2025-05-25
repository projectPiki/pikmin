#ifndef _INTROGAMESECTION_H
#define _INTROGAMESECTION_H

#include "types.h"
#include "Section.h"
#include "Camera.h"
#include "DayMgr.h"
#include "system.h"
#include "gameflow.h"
#include "EffectMgr.h"
#include "MoviePlayer.h"
#include "Graphics.h"
#include "jaudio/piki_scene.h"
#include "ModeState.h"

/**
 * @brief TODO
 *
 * @note Size: 0x20.
 */
struct IntroGameSection : public Section {
	IntroGameSection();

	virtual void init() { } // _30 (weak)

	// _00     = VTBL
	// _00-_20 = Section
};

/**
 * @brief TODO
 *
 * @note In introGame.cpp because IntroModeState needs to be there.
 */
struct IntroGameSetupSection;

#endif
