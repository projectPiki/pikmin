#ifndef _JAUDIO_HVQM_PLAY_H
#define _JAUDIO_HVQM_PLAY_H

#include "types.h"

typedef struct StreamHeader_ StreamHeader;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jac_HVQM_Init(void);
void Jac_HVQM_ThreadStart(void);
void Jac_HVQM_Update(void);
void Jac_HVQM_ForceStop(void);
void Jac_CountReadyPictures(void);
void Jac_GetPicture(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
