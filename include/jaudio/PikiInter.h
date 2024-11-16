#ifndef _JAUDIO_PIKIINTER_H
#define _JAUDIO_PIKIINTER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO PIKMIN INTERFACE FUNCTIONS ////////////
void Jac_InitEventSystem(void);     // args
void Jac_EventFrameCheck(void);     // args
void Jac_UpdateCamera(void);        // args
void Jac_CreateEvent(void);         // args
void Jac_UpdateEventPosition(void); // args
void Jac_PlayEventAction(void);     // args
void Jac_StopEventAction(void);     // args
void MML_StopEventAction(void);     // args
void MML_StopEventAll(void);        // args
void Jac_DestroyEvent(void);        // args
void Jac_InitAllEvent(void);        // args
void Jac_CheckFreeEvents(void);     // args
void Jac_GetActiveEvents(void);     // args

///////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
