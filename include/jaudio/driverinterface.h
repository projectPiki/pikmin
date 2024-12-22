#ifndef _JAUDIO_DRIVERINTERFACE_H
#define _JAUDIO_DRIVERINTERFACE_H

#include "types.h"
#include "jaudio/audiostruct.h"

/////////// JAUDIO DRIVER INTERFACE DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
void Channel_SetMixerLevel(f32);
void Get_GlobalHandle();
void List_CountChannel(JC**);
void List_CutChannel(JC*);
void List_GetChannel(JC**);
void List_AddChannelTail(JC**, JC*);
void List_AddChannel(JC**, JC*);
void FixAllocChannel(JCS*, u32);
void FixReleaseChannel(JC*);
void FixReleaseChannelAll(JCS*);
void FixMoveChannelAll(JCS*, JCS*);
void InitJcs(JCS*);
void Channel_Init(JC*);
void InitGlobalChannel();
void UpdateJcToDSP(JC*);
void UpdateEffecterParam(JC*);
void DoEffectOsc(JC*, u8, f32);
void StopLogicalChannel(JC*);
void CheckLogicalChannel(JC*);
void PlayLogicalChannel(JC*);
void ResetInitialVolume(JC*);
void Add_WaitDSPChannel(JC*);
void Del_WaitDSPChannel(JC*);
void __Entry_WaitChannel(u8);
void EntryCheck_WaitDSPChannel();
void ForceStopLogicalChannel(JC*);

///////////////////////////////////////////////////////////

#endif
