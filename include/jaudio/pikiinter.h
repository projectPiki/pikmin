#ifndef _JAUDIO_PIKIINTER_H
#define _JAUDIO_PIKIINTER_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

/**
 * @brief TODO
 */
struct SVector_ {
	f32 x; // _00
	f32 y; // _04
	f32 z; // _08
};

//////////// JAUDIO PIKMIN INTERFACE FUNCTIONS ////////////
void Jac_InitEventSystem(void);                            // args
void Jac_EventFrameCheck(void);                            // args
void Jac_UpdateCamera(struct Vector3f*, struct Vector3f*); // args
int Jac_CreateEvent(u32, struct SVector_*);                // args
BOOL Jac_UpdateEventPosition(int, struct Vector3f*);       // args
void Jac_PlayEventAction(int, int);                        // args
void Jac_StopEventAction(int, int);                        // args
void MML_StopEventAction(u8, u8, u16);                     // args
void MML_StopEventAll(u8, u16);                            // args
BOOL Jac_DestroyEvent(s32);                                // args
void Jac_InitAllEvent(void);                               // args
int Jac_CheckFreeEvents(void);                             // args
int Jac_GetActiveEvents(u32*);                             // args

///////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
