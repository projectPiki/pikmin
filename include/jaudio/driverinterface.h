#ifndef _JAUDIO_DRIVERINTERFACE_H
#define _JAUDIO_DRIVERINTERFACE_H

#include "types.h"
#include "jaudio/audiostruct.h"

/////////// JAUDIO DRIVER INTERFACE DEFINITIONS ///////////
// Global functions (all C++, so no extern C wrap).
void Channel_SetMixerLevel(f32);
jcs_* Get_GlobalHandle();
void List_CountChannel(jc_**);
void List_CutChannel(jc_*);
void List_GetChannel(jc_**);
void List_AddChannelTail(jc_**, jc_*);
void List_AddChannel(jc_**, jc_*);
void FixAllocChannel(jcs_*, u32);
void FixReleaseChannel(jc_*);
void FixReleaseChannelAll(jcs_*);
void FixMoveChannelAll(jcs_*, jcs_*);
void InitJcs(jcs_*);
void Channel_Init(jc_*);
void InitGlobalChannel();
void UpdateJcToDSP(jc_*);
void UpdateEffecterParam(jc_*);
void DoEffectOsc(jc_*, u8, f32);
void StopLogicalChannel(jc_*);
void CheckLogicalChannel(jc_*);
void PlayLogicalChannel(jc_*);
void ResetInitialVolume(jc_*);
void Add_WaitDSPChannel(jc_*);
void Del_WaitDSPChannel(jc_*);
void __Entry_WaitChannel(u8);
void EntryCheck_WaitDSPChannel();
void ForceStopLogicalChannel(jc_*);

///////////////////////////////////////////////////////////

#endif
