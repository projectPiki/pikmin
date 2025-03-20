#ifndef _JAUDIO_APP_INTER_H
#define _JAUDIO_APP_INTER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jac_Pause(void);
void Jac_StreamMovieInit(void);
void Jac_StreamMovieStop(void);
void Jac_StreamMovieUpdate(void);
void Jac_StreamMovieGetPicture(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
