#ifndef _JAUDIO_PIKIINTER_H
#define _JAUDIO_PIKIINTER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO PIKMIN INTERFACE FUNCTIONS ////////////
void Jac_InitEventSystem(void);                            // args
void Jac_EventFrameCheck(void);                            // args
void Jac_UpdateCamera(struct Vector3f*, struct Vector3f*); // args
int Jac_CreateEvent(int, struct SVector_*);                // args
void Jac_UpdateEventPosition(int, struct Vector3f*);       // args
void Jac_PlayEventAction(int, int);                        // args
void Jac_StopEventAction(int, int);                        // args
void MML_StopEventAction(void);                            // args
void MML_StopEventAll(void);                               // args
void Jac_DestroyEvent(s32);                                // args
void Jac_InitAllEvent(void);                               // args
int Jac_CheckFreeEvents(void);                             // args
int Jac_GetActiveEvents(u8*);                              // args

///////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
