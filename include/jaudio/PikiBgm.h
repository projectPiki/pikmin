#ifndef _JAUDIO_PIKIBGM_H
#define _JAUDIO_PIKIBGM_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO PIKMIN BGM FUNCTIONS ////////////
void Jac_InitBgm(void);           // args
void Jac_FadeOutBgm(unknown, unknown); // args
void Jac_StopBgm(u32);            // arg type unsure
void Jac_ReadyBgm(void);          // args
void Jac_PlayBgm(void);           // args
void Jac_ChangeBgmMode(void);     // args
void Jac_SetBgmModeFlag(unknown, unknown, unknown); // args
void Jac_BgmFrameWork(void);      // args
void Jac_MoveBgmTrackVol(void);   // args
void Jac_ChangeBgmTrackVol(void); // args
void Jac_GameVolume(u8 bgmVol, u8 seVol);
void Jac_EasyCrossFade(void);     // args
void Jac_DemoFade(f32, int, int); // TODO: types unsure
void Jac_EnterBossMode(void);     // args
void Jac_ExitBossMode(void);      // args

/////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
