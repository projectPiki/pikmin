#ifndef _JAUDIO_PIKIBGM_H
#define _JAUDIO_PIKIBGM_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef struct BgmControl_ BgmControl_;

//////////// JAUDIO PIKMIN BGM FUNCTIONS ////////////
void Jac_InitBgm(void);
void Jac_FadeOutBgm(u32, u32);
void Jac_StopBgm(u32);
void Jac_ReadyBgm(u32);
void Jac_PlayBgm(u32, u32);
BOOL Jac_ChangeBgmMode(u32, u8);
void Jac_SetBgmModeFlag(u32, u8, u8);
void Jac_BgmFrameWork(void);
void Jac_MoveBgmTrackVol(BgmControl_*);
void Jac_ChangeBgmTrackVol(BgmControl_*);
void Jac_GameVolume(u8 bgmVol, u8 seVol);
void Jac_EasyCrossFade(u8, u32);
void Jac_DemoFade(u8, u32, f32);
void Jac_EnterBossMode(void);
void Jac_ExitBossMode(void);

/////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
