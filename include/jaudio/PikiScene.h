#ifndef _JAUDIO_PIKISCENE_H
#define _JAUDIO_PIKISCENE_H

#include "types.h"

//////////// JAUDIO PIKMIN SCENE FUNCTIONS ////////////
void Jac_StopDemoSound(u32);
void Jac_PrepareDemoSound(u32);
void Jac_StartDemoSound(u32);

///////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO PIKMIN SCENE FUNCTIONS ////////////
void Jac_Delete_CurrentBgmWave();
u32 Jac_GetCurrentScene();
u32 Jac_TellChgMode();
void Jac_SceneSetup(u32, u32);
void Jac_SceneExit(u32, u32);
void Jac_SetStreamLevel(u16 stream, u16 se);
void Jac_UpdateStreamLevel();
void Jac_InitStreamSystem();

///////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
