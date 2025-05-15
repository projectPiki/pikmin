#ifndef _JAUDIO_PIKIPLAYER_H
#define _JAUDIO_PIKIPLAYER_H

#include "types.h"

//////////// JAUDIO PIKMIN DEMO FUNCTIONS (C++) ////////////
void Jac_PauseOrimaSe();
void Jac_UnPauseOrimaSe();
void Jac_UpdatePikiGaya();

////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO PIKMIN DEMO FUNCTIONS (C) ////////////
void Jac_Orima_Walk(u16 soundID, u32 p2); // args uncertain
void Jac_Orima_Formation(s32, s32);       // args
void Jac_PlayOrimaSe(u32);                // args
void Jac_StopOrimaSe(s32);                // args
void Jac_Piki_Number(u32);                // args

/////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
