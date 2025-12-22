#ifndef _JAUDIO_PIKISCENE_H
#define _JAUDIO_PIKISCENE_H

#include "types.h"

typedef enum JacSceneID {
	SCENE_NULL  = -1,
	SCENE_Unk0  = 0,
	SCENE_Unk1  = 1,
	SCENE_Unk2  = 2,
	SCENE_Unk3  = 3,
	SCENE_Unk4  = 4,
	SCENE_Unk5  = 5,
	SCENE_Unk6  = 6,
	SCENE_Unk7  = 7,
	SCENE_Unk8  = 8,
	SCENE_Unk9  = 9,
	SCENE_Unk10 = 10,
	SCENE_Unk11 = 11,
	SCENE_Unk12 = 12,
	SCENE_Unk13 = 13,
	SCENE_COUNT,
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
