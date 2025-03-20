#ifndef _JAUDIO_INTERFACE_H
#define _JAUDIO_INTERFACE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO GLOBAL INTERFACE FUNCTIONS ////////////
void Jac_OutputMode(int mode);
void Jac_SetBGMVolume(u8 vol);
void Jac_SetSEVolume(u8 vol);
void Jac_Gsync();
void Jac_SetProcessStatus(u32 processStat);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
