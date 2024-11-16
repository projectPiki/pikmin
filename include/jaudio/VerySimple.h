#ifndef _JAUDIO_VERYSIMPLE_H
#define _JAUDIO_VERYSIMPLE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO "VERY SIMPLE" FUNCTIONS ////////////
void Jac_StopSe(void);             // args
void Jac_PauseCheck(void);         // args
void Jac_SysSEDemoFadeCheck(void); // args
void Jac_PlaySystemSe(void);       // args
void Jac_StopSystemSe(void);       // args
void Jac_CheckBootOk(void);        // args
void Jac_Start(void);              // args
void Jac_Freeze_Precall(void);     // args
void Jac_Freeze(void);             // args
void Jac_AddDVDBuffer(void);       // args
void Jac_BackDVDBuffer(void);      // args

///////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
