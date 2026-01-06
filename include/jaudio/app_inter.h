#ifndef _JAUDIO_APP_INTER_H
#define _JAUDIO_APP_INTER_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

void Jac_Pause(void);
void Jac_StreamMovieInit(immut char* filepath, u8*, int);
void Jac_StreamMovieStop(void);
void Jac_StreamMovieUpdate(void);
int Jac_StreamMovieGetPicture(void*, int*, int*); // TODO: return type unknown (same as Jac_GetPicture)

END_SCOPE_EXTERN_C

#endif
