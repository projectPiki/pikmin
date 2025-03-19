#ifndef _JAUDIO_JAMMAIN_2_H
#define _JAUDIO_JAMMAIN_2_H

#include "types.h"

typedef struct seqp_ seqp_;

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

void Jam_OfsToAddr(void);
void Jam_WriteRegDirect(void);
void Jam_WriteRegParam(void);
void Jam_ReadRegDirect(void);
void Jam_ReadReg32(void);
void Jam_WriteRegXY(void);
void Jam_WritePortApp(void);
void Jam_ReadPortApp(void);
void Jam_CheckExportApp(void);
void Jam_CheckImportApp(void);
void Jam_WritePortIndirect(void);
void Jam_ReadPortIndirect(void);
void Jam_CheckPortIndirect(void);
void Jam_WritePortAppDirect(void);
void Jam_ReadPortAppDirect(void);
void Jam_CheckPortAppDirect(void);
void Jam_WritePort(void);
void Jam_ReadPort(void);
void Jam_WritePortChild(void);
void Jam_WritePortBros(void);
void Jam_InitRegistTrack(void);
void Jam_UnRegistTrack(void);
void Jam_GetTrackHandle(void);
void Jam_InitExtBuffer(void);
void Jam_AssignExtBuffer(void);
void Jam_AssignExtBufferP(void);
void Jam_SetExtFirFilterD(void);
void Jam_SetExtParamD(void);
void Jam_OnExtSwitchD(void);
void Jam_OffExtSwitchD(void);
void Jam_SetExtSwitchDirectD(void);
void Jam_SetExtFirFilter(void);
void Jam_SetExtParam(void);
void Jam_OnExtSwitch(void);
void Jam_OffExtSwitch(void);
void Jam_SetExtSwitchDirect(void);
void Jam_SetExtFirFilterP(void);
void Jam_SetExtParamP(void);
void Jam_OnExtSwitchP(void);
void Jam_OffExtSwitchP(void);
void Jam_SetExtSwitchDirectP(void);
void Jam_CheckRunningCounter(void);
void Jam_RegisterTrackCallback(void);
void Jam_SetTrackExtPanPower(void);
void Jam_UpdateTrackAll(void);
void Jam_UpdateTrack(void);
void Jam_UpdateTempo(void);
void Jam_MuteTrack(void);
void Jam_MuteChildTracks(void);
void Jam_PauseTrack(void);
void Jam_UnPauseTrack(void);
void Jam_SetInterrupt(void);
void Jam_TryInterrupt(void);
void Jam_SeqmainNote(void);
void SeqUpdate(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

// I feel like, for these global functions that are not extern "C", the programmers just
// forgot to make them static. I will still expose them in header for now in case I'm wrong.

void Extend8to16(u8);
void Jam_SEQtimeToDSPtime(seqp_*, s32, u8);
void Jam_WriteTimeParam(seqp_*, u8);
void Jam_ReadRegXY(seqp_*);
void Jam_RegistTrack(seqp_*, u32);
void Cmd_Process(seqp_*, u8, u16);
void RegCmd_Process(seqp_*, int, u32);

#endif
