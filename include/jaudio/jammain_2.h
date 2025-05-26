#ifndef _JAUDIO_JAMMAIN_2_H
#define _JAUDIO_JAMMAIN_2_H

#include "types.h"

#include "jaudio/audiostruct.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef struct seqp_ seqp_;
typedef struct seqp__Invented1 seqp__Invented1;
typedef struct seqp__Invented2 seqp__Invented2;

typedef u32 (*CmdFunction)();              // TODO: Confirm return type
typedef u32 (*TrackCallback)(seqp_*, u16); // TODO: Confirm return type

/**
 * @brief This is an invented type of an unknown name.
 *
 * @note Size: 4
 */
struct seqp__Invented1 {
	u8 cmdImport; // _00
	u8 cmdExport; // _01
	u16 _02;      // _02
};

struct seqp__Invented2 {
	f32 _00; // _00
	f32 _04; // _04
	f32 _08; // _08
	f32 _0C; // _0C
};

// This is used heavily for jamosc.c, it might be embedded into seqp somewhere...?
typedef struct Osc_definition {
	u8 _00;
	f32 _04;
	u16* _08;
	u16* _0C;
	f32 _10;
	f32 _14;
} Osc_definition;

/**
 * @brief TODO
 *
 * @note Size: 0x434.
 */
struct seqp_ {
	u8* _00;                  // _000
	u32 _04;                  // _004
	u32 _08;                  // _008
	u32 _0C[2];               // _00C | Exact length unknown, but it is an array.
	u8 _10[0x02c - 0x014];    // _008
	u16 _2C[2];               // _02C | Exact length unknown, but it is an array.
	u8 _30[0x03c - 0x030];    // _030
	u8 _3C;                   // _03C | Confirmed unsigned by switch cases
	u8 _3D;                   // _03D
	u8 _3E;                   // _03E
	u8 _3F;                   // _03F
	seqp_* _40;               // _040
	seqp_* _44[16];           // _044 | Exact length confirmed. Bounds check in `Cmd_CloseTrack`, `Jam_ReadRegDirect`, `Init_Track`.
	u32 _84;                  // _084
	u32 _88;                  // _088;
	u32 _8C;                  // _08C
	u32 _90;                  // _090
	u8 _94[8];                // _094 | Exact length confirmed. For loop in `Init_Track`, `__AllNoteOff`.
	jc_* _9C[8];              // _09C | Exact length confirmed. For loop in `Init_Track`, `__AllNoteOff`.
	u16 _BC[8];               // _0BC | Exact length conformed. For loop in `Init_Track`.
	u8 _CC[0x0d0 - 0x0cc];    // _0CC
	u32 _D0;                  // _0D0
	u8 _D4;                   // _0D4
	u8 _D5;                   // _0D5
	u8 _D6;                   // _0D6
	u8 _D7[0x0d8 - 0x0d7];    // _0D7
	jcs_ _D8;                 // _0D8
	seqp__Invented2 _14C[18]; // _14C
	u16 _26C[32];             // _26C | Exact length confirmed. For loop in `Init_Track`.
	u16* _2AC;                // _2AC | Are you really?
	u32 _2B0[16];             // _2B0 | Exact length confirmed. For loop in `Init_Track`.
	seqp__Invented1 _2F0[16]; // _2F0 | Exact length confirmed. For loop in `Init_Track`.
	u8 _330[0x334 - 0x330];   // _330
	f32 _334;                 // _334
	u16 _338;                 // _338
	u16 _33A;                 // _33A
	u8 _33C;                  // _33C
	u8 _33D;                  // _33D
	f32 _340;                 // _340
	f32 _344;                 // _344
	void* _348;               // _348
	void* _34C;               // _34C
	f32 _350[8];              // _350
	u8 _370[2];               // _370 | Exact length unknown, but it is an array.
	s16 _372[0x12];           // _374 | This is a pair of some sort of struct, _348 and _34C point to them, see Osc_Setup_ADSR
	s8 _396;                  // _396 | Confirmed signed (Cmd_Transpose)
	u8 _397;                  // _397
	s32 _398;                 // _398 | Might be signed (See: `Init_Track`)
	u8 _39C;                  // _39C
	u8 _39D;                  // _39D
	u8 _39E;                  // _39E
	u8 _39F[0x3a0 - 0x39f];   // _39F
	u16 _3A0;                 // _3A0
	u8 _3A2[0x3a4 - 0x3a2];   // _3A2
	u8 _3A4;                  // _3A4
	u8 _3A5[0x3a6 - 0x3a5];   // _3A5
	u8 _3A6;                  // _3A6
	u8 _3A7;                  // _3A7
	u32 _3A8[2];              // _3A8 | Exact length unknown, but it is an array.
	u8 _3B0[0x3c8 - 0x3b0];   // _3A8
	u32 _3C8;                 // _3C8
	u32 _3CC;                 // _3CC
	u32 _3D0;                 // _3D0
	u32 _3D4;                 // _3D4
	u8 _3D8[0x3dc - 0x3d8];   // _3D8
	u8 _3DC[3];               // _3DC | Exact length confirmed. For loop in `Init_Track`.
	u8 _3DF[3];               // _3DF | Exact length confirmed. For loop in `Init_Track`.
	u8 _3E2;                  // _3E2
	u8 _3E3;                  // _3E3
	u8 _3E4;                  // _3E4
	u8 _3E5[0x3e8 - 0x3e5];   // _3E5
	u8 _3E8[2];               // _3E8 | Exact length unknown, but it is an array.
	u8 _3EA[0x434 - 0x3ea];   // _3EA | Exact size of struct confirmed by `Jaf_HandleToSeq`.
};

void* Jam_OfsToAddr(seqp_*, u32);         // TODO: Change return type to u8* if that's more convenient.
void Jam_WriteRegDirect(seqp_*, u8, u16); // Is param_3 is u8 or a u16?
void Jam_WriteRegParam(void);
u16 Jam_ReadRegDirect(seqp_*, u32);
u32 Jam_ReadReg32(void);
void Jam_WriteRegXY(void);
void Jam_WritePortApp(void);
void Jam_ReadPortApp(void);
void Jam_CheckExportApp(void);
void Jam_CheckImportApp(void);
void Jam_WritePortIndirect(void);
void Jam_ReadPortIndirect(void);
void Jam_CheckPortIndirect(void);
s32 Jam_WritePortAppDirect(seqp_*, u8, u16);
s32 Jam_ReadPortAppDirect(seqp_*, u32, u16*);
s32 Jam_CheckPortAppDirect(seqp_*, u32, u16);
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
void Jam_SetExtFirFilterD(u16*, void*);
void Jam_SetExtParamD(f32, int*, int);
void Jam_OnExtSwitchD(int*, int);
void Jam_OffExtSwitchD(void);
void Jam_SetExtSwitchDirectD(void);
void Jam_SetExtFirFilter(void);
void Jam_SetExtParam(f32, seqp_*, int);
void Jam_OnExtSwitch(seqp_*, int);
void Jam_OffExtSwitch(seqp_*, int);
void Jam_SetExtSwitchDirect(void);
void Jam_SetExtFirFilterP(void);
void Jam_SetExtParamP(void);
void Jam_OnExtSwitchP(void);
void Jam_OffExtSwitchP(void);
void Jam_SetExtSwitchDirectP(void);
void Jam_CheckRunningCounter(void);
BOOL Jam_RegisterTrackCallback(TrackCallback);
void Jam_SetTrackExtPanPower(void);
void Jam_UpdateTrackAll(void);
void Jam_UpdateTrack(seqp_*, u32);
void Jam_UpdateTempo(void);
void Jam_MuteTrack(seqp_*, int);
void Jam_MuteChildTracks(void);
void Jam_PauseTrack(seqp_*, u32); // TODO: types uncertain
void Jam_UnPauseTrack(seqp_*, u32);
void Jam_SetInterrupt(void);
void Jam_TryInterrupt(seqp_*);
void Jam_SeqmainNote(void);
void SeqUpdate(seqp_*, unknown);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
