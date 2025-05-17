#ifndef _JAUDIO_PIKIBGM_H
#define _JAUDIO_PIKIBGM_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO PIKMIN BGM FUNCTIONS ////////////
void Jac_InitBgm(void);                 // args
void Jac_FadeOutBgm(u32, u32);          // args
void Jac_StopBgm(u32);                  // arg type unsure
void Jac_ReadyBgm(int);                 // args
void Jac_PlayBgm(int, int);             // args
BOOL Jac_ChangeBgmMode(int, int);       // args
void Jac_SetBgmModeFlag(u32, u32, u32); // args
void Jac_BgmFrameWork(void);            // args
void Jac_MoveBgmTrackVol(int);          // args
void Jac_ChangeBgmTrackVol(int);        // args
void Jac_GameVolume(u8 bgmVol, u8 seVol);
void Jac_EasyCrossFade(u32, u32); // args
void Jac_DemoFade(f32, int, int); // TODO: types unsure
void Jac_EnterBossMode(void);     // args
void Jac_ExitBossMode(void);      // args

/////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
