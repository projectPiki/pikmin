#ifndef _JAUDIO_PIKIDEMO_H
#define _JAUDIO_PIKIDEMO_H

#include "types.h"

//////////// JAUDIO PIKMIN DEMO FUNCTIONS (C++) ////////////
void Jac_DemoEventUnPauseCheck();
BOOL Jac_DemoCheck();
BOOL Jac_DemoWalkCheck();
void Jac_DemoCheckEvent(u8);
void Jac_PlayDemoSequenceDirect(u32);
void Jac_InitDemoSystem();
void Jac_DemoBGMForceStop();

////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

//////////// JAUDIO PIKMIN DEMO FUNCTIONS (C) ////////////
void Jac_DemoSceneInit(void);                // args
void Jac_StartDemo(int);                     // args
void Jac_DemoSound(void);                    // args
void Jac_DemoFrame(int);                     // args
void Jac_FinishDemo(void);                   // args
void Jac_PrepareDemo(void);                  // args
void Jac_StartPartsFindDemo(u32 p1, int p2); // unsure on first arg
void Jac_FinishPartsFindDemo(void);          // args
void Jac_StartTextDemo(int);                 // args
void Jac_FinishTextDemo(void);               // args
void Jac_SetDemoPartsID(int);                // args
void Jac_SetDemoOnyons(int);                 // args
void Jac_SetDemoPartsCount(int);             // args

/////////////////////////////////////////////////////////

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
