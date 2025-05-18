#ifndef _JAUDIO_JAMMAIN_2_H
#define _JAUDIO_JAMMAIN_2_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef struct seqp_ seqp_;
typedef struct jcs_ jcs_;

/**
 * @brief TODO
 *
 * @note Size: ?.
 */
struct seqp_ {
	u8 _00[0x004 - 0x000];  // _000
	u32 _04;                // _004
	u32 _08;                // _008
	u32 _0C[2];             // _00C | Exact length unknown, but it is an array.
	u8 _10[0x084 - 0x014];  // _008
	u32 _84;                // _084
	u32 _88;                // _088;
	u32 _8C;                // _08C
	u8 _90[0x0d5 - 0x090];  // _008
	u8 _D5;                 // _0D5
	u8 _D6[0x0d8 - 0x0d6];  // _0D6
	jcs_* _D8;              // _0D8 | FIXME: NOT ACTUALLY A POINTER, THIS IS A MEMBER AT THIS OFFSET.
	u8 _DC[0x126 - 0x0dc];  // _0DC
	u16 _126[2];            // _126 | Exact length unknown, but it is an array.
	u8 _12A[0x33c - 0x12a]; // _12A
	u8 _33C;                // _33C
	u8 _33D[0x397 - 0x33d]; // _33D
	u8 _397;                // _397
	u8 _398[0x39d - 0x398]; // _398
	u8 _39D;                // _39D
	u8 _39E[0x3a4 - 0x39e]; // _39E
	u8 _3A4;                // _3A4
	u8 _3A5[0x3a6 - 0x3a5]; // _3A5
	u8 _3A6;                // _3A6
	u8 _3A7;                // _3A7
	u8 _3A8[0x3c8 - 0x3a8]; // _3A7
	u32 _3C8;               // _3C8
	u32 _3CC;               // _3CC
	u32 _3D0;               // _3D0
	u32 _3D4;               // _3D4
};

typedef u32 (*TrackCallback)(seqp_*, u16); // TODO: Confirm return type

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
int Jam_WritePortAppDirect(seqp_*, int, int);  // TODO: types unknown;
void Jam_ReadPortAppDirect(seqp_*, u32, u16*); // TODO: types unknown
int Jam_CheckPortAppDirect(seqp_*, int, int);  // TODO: types unknown
void Jam_WritePort(void);
void Jam_ReadPort(void);
void Jam_WritePortChild(void);
void Jam_WritePortBros(void);
void Jam_InitRegistTrack(void);
void Jam_UnRegistTrack(seqp_*);
seqp_* Jam_GetTrackHandle(u32);
void Jam_InitExtBuffer(int*);
BOOL Jam_AssignExtBuffer(seqp_*, int*);
void Jam_AssignExtBufferP(void);
void Jam_SetExtFirFilterD(void);
void Jam_SetExtParamD(f32, int*, int);
void Jam_OnExtSwitchD(int*, int);
void Jam_OffExtSwitchD(void);
void Jam_SetExtSwitchDirectD(void);
void Jam_SetExtFirFilter(void);
void Jam_SetExtParam(f32, int*, int);
void Jam_OnExtSwitch(int*, int);
void Jam_OffExtSwitch(int*, int);
void Jam_SetExtSwitchDirect(void);
void Jam_SetExtFirFilterP(void);
void Jam_SetExtParamP(void);
void Jam_OnExtSwitchP(void);
void Jam_OffExtSwitchP(void);
void Jam_SetExtSwitchDirectP(void);
void Jam_CheckRunningCounter(void);
void Jam_RegisterTrackCallback(TrackCallback);
void Jam_SetTrackExtPanPower(void);
void Jam_UpdateTrackAll(void);
void Jam_UpdateTrack(seqp_*, u32);
void Jam_UpdateTempo(void);
void Jam_MuteTrack(int*, int);
void Jam_MuteChildTracks(void);
void Jam_PauseTrack(seqp_*, u32); // TODO: types uncertain
void Jam_UnPauseTrack(seqp_*, u32);
void Jam_SetInterrupt(void);
void Jam_TryInterrupt(void);
void Jam_SeqmainNote(void);
void SeqUpdate(void);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
