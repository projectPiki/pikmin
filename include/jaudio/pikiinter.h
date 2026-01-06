#ifndef _JAUDIO_PIKIINTER_H
#define _JAUDIO_PIKIINTER_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

/**
 * @brief TODO
 */
typedef struct SVector_ {
	f32 x; // _00
	f32 y; // _04
	f32 z; // _08
} SVector_;

/**
 * @brief TODO
 */
typedef enum JacEventType {
	JACEVENT_System    = -2, ///< -2, system sound effects.
	JACEVENT_Player    = -1, ///< -1, captain or captain-pikmin interaction sound effects.
	JACEVENT_NULL      = 0,  ///< 0, no event.
	JACEVENT_Battle    = 1,  ///< 1, teki and boss sound effects.
	JACEVENT_Pellet    = 2,  ///< 2, ufo part and other pellet sound effects.
	JACEVENT_Onyon     = 3,  ///< 3, onyon and pikmin sprout sound effects.
	JACEVENT_Build     = 4,  ///< 4, work object (wall, bridge, box, grass, stone) sound effects.
	JACEVENT_PikiWater = 5,  ///< 5, water-related pikmin sound effects.
	JACEVENT_Piki      = 6,  ///< 6, all other pikmin sound effects.
	JACEVENT_Ufo       = 7,  ///< 7, ufo (ship) related sound effects.
	JACEVENT_Dame      = 8,  ///< 8, idk (see `SeSystem::draw2d`)
	JACEVENT_COUNT,
} JacEventType;

//////////// JAUDIO PIKMIN INTERFACE FUNCTIONS ////////////
void Jac_InitEventSystem(void);                            // args
void Jac_EventFrameCheck(void);                            // args
void Jac_UpdateCamera(struct SVector_*, struct SVector_*); // args
int Jac_CreateEvent(u32, struct SVector_*);                // args
BOOL Jac_UpdateEventPosition(int, struct SVector_*);       // args
BOOL Jac_PlayEventAction(int, int);                        // args
BOOL Jac_StopEventAction(int, int);                        // args
BOOL MML_StopEventAction(u8, u8, u16);                     // args
void MML_StopEventAll(u8, u16);                            // args
BOOL Jac_DestroyEvent(s32);                                // args
void Jac_InitAllEvent(void);                               // args
int Jac_CheckFreeEvents(void);                             // args
int Jac_GetActiveEvents(u32*);                             // args

///////////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
