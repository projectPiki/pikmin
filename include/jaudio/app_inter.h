#ifndef _JAUDIO_APP_INTER_H
#define _JAUDIO_APP_INTER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jac_Pause(void);
void Jac_StreamMovieInit(char* filepath, u8*, int);
void Jac_StreamMovieStop(void);
void Jac_StreamMovieUpdate(void);
int Jac_StreamMovieGetPicture(void*, int*, int*); // TODO: return type unknown (same as Jac_GetPicture)

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
