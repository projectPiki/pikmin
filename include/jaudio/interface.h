#ifndef _JAUDIO_INTERFACE_H
#define _JAUDIO_INTERFACE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO GLOBAL INTERFACE FUNCTIONS ////////////
void Jac_OutputMode(int mode); // args
void Jac_SetBGMVolume(u8 vol);
void Jac_SetSEVolume(u8 vol);
void Jac_Gsync();
void Jac_SetProcessStatus(u32 processStat);
void Jac_StreamMovieUpdate();
void Jac_StreamMovieInit(const char* path, u8*, int);
void Jac_StreamMovieGetPicture();

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
