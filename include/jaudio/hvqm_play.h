#ifndef _JAUDIO_HVQM_PLAY_H
#define _JAUDIO_HVQM_PLAY_H

#include "types.h"

typedef struct StreamHeader_ StreamHeader;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jac_HVQM_Init(const char* filepath, u8*, int);
void Jac_HVQM_ThreadStart(void);
void Jac_HVQM_Update(void);
void Jac_HVQM_ForceStop(void);
void Jac_CountReadyPictures(void);
int Jac_GetPicture(void); // TODO: types unsure (return can be -1 though)

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
