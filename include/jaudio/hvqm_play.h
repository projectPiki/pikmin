#ifndef _JAUDIO_HVQM_PLAY_H
#define _JAUDIO_HVQM_PLAY_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jac_HVQM_Init(immut char* filepath, u8*, u32);
void Jac_HVQM_ThreadStart(void);
BOOL Jac_HVQM_Update(void);
void Jac_HVQM_ForceStop(void);
void Jac_CountReadyPictures(void);
int Jac_GetPicture(void*, int*, int*); // TODO: types unsure (return can be -1 though)

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

static void __LoadFin(u32);

#endif
