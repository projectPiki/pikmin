#ifndef _JAUDIO_PIKISCENE_H
#define _JAUDIO_PIKISCENE_H

#include "types.h"

typedef enum JacResultsType {
	JACRES_EndOfDay    = 0,
	JACRES_FinalResult = 1,
} JacResultsType;

typedef enum JacSceneID {
	SCENE_NULL       = -1,
	SCENE_BootUp     = 0,  // nintendo/boot-up
	SCENE_Title      = 1,  // title screen
	SCENE_FileSelect = 2,  // file select
	SCENE_WorldMap   = 3,  // story mode map select
	SCENE_Unk4       = 4,  // unused
	SCENE_Course     = 5,  // stage-specific track
	SCENE_Results    = 6,  // results (either final or challenge mode)
	SCENE_Unk7       = 7,  // unused
	SCENE_Unk8       = 8,  // unused
	SCENE_Unk9       = 9,  // unused
	SCENE_ChalSelect = 10, // challenge mode map select?
	SCENE_Intro      = 11, // intro/crash landing?
	SCENE_Unk12      = 12, // unused
	SCENE_Exit       = 13, // exit
	SCENE_COUNT,           // 14
} JacSceneID;

//////////// JAUDIO PIKMIN SCENE FUNCTIONS ////////////
void Jac_StopDemoSound(u32);
void Jac_PrepareDemoSound(u32);
void Jac_StartDemoSound(u32);

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jac_Delete_CurrentBgmWave();
u32 Jac_GetCurrentScene();
BOOL Jac_TellChgMode();
void Jac_SceneSetup(u32 sceneID, u32 stageID);
void Jac_SceneExit(u32 sceneID, u32 stageID);
void Jac_SetStreamLevel(u16 stream, u16 se);
void Jac_UpdateStreamLevel();
void Jac_InitStreamSystem();

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

///////////////////////////////////////////////////////

#endif
