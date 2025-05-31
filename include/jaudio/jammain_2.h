#ifndef _JAUDIO_JAMMAIN_2_H
#define _JAUDIO_JAMMAIN_2_H

#include "types.h"

#include "jaudio/audiostruct.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

extern s16 CUTOFF_TO_IIR_TABLE[128][4];

typedef struct seqp_ seqp_;
typedef struct TrackPort_ TrackPort_;
typedef struct MoveParam_ MoveParam_;
typedef struct AInnerParam_ AInnerParam_;
typedef union TimedParam_ TimedParam_;
typedef struct OuterParam_ OuterParam_;
typedef struct RegisterParam_ RegisterParam_;
typedef union URegisterParam_ URegisterParam_;

typedef u32 (*CmdFunction)();              // TODO: Confirm return type
typedef u32 (*TrackCallback)(seqp_*, u16); // TODO: Confirm return type

/**
 * @brief This is an invented type of an unknown name.
 *
 * @note Size: 4
 */
struct TrackPort_ {
	u8 importFlag; // _00
	u8 exportFlag; // _01
	u16 value;     // _02
};

/**
 * @brief Name borrowed from `JASTrack.h` from Pikmin 2.
 *
 * @note Size: 16
 */
struct MoveParam_ {
	f32 _00; // _00
	f32 _04; // _04
	f32 _08; // _08
	f32 _0C; // _0C
};

/**
 * @brief Name borrowed from `JASTrack.h` from Pikmin 2.
 *
 * @note Size: 0x120
 */
struct AInnerParam_ {
	MoveParam_ volume;     // _00
	MoveParam_ pitch;      // _10
	MoveParam_ fxmix;      // _20
	MoveParam_ pan;        // _30
	MoveParam_ dolby;      // _40
	MoveParam_ _50;        // _50
	MoveParam_ osc0Width;  // _60
	MoveParam_ osc0Rate;   // _70
	MoveParam_ osc0Vertex; // _80
	MoveParam_ osc1Width;  // _90
	MoveParam_ osc1Rate;   // _A0
	MoveParam_ osc1Vertex; // _B0
	MoveParam_ IIRs[4];    // _C0
	MoveParam_ _100;       // _100
	MoveParam_ _110;       // _110
};

union TimedParam_ {
	AInnerParam_ inner;  // Get individual params by member name
	MoveParam_ move[18]; // Get individual params by index
};

/**
 * @brief Name borrowed from `JASTrack.h` from Pikmin 2.
 *
 * @note Size: 0x40.
 */
struct OuterParam_ {
	u32 _00;             // _00
	u32 _04;             // _04
	u16 _08;             // _08
	u16 _0A;             // _0A | Confirmed unsigned `Cmd_OutSwitch`
	f32 _0C;             // _0C
	f32 _10;             // _10
	f32 _14;             // _14
	f32 _18;             // _18
	f32 _1C;             // _1C
	f32 _20;             // _20
	s16 _24[8];          // _24 | Exact length and signed confirmed. For loop in `Jam_SetExtFirFilterD`.
	u8 _34[0x40 - 0x34]; // _34
};

/**
 * @brief Name borrowed from `JASRegisterParam.h` from Pikmin 2.
 *
 * @note Size: 0x40.
 */
struct RegisterParam_ {
	u8 _00[0x06 - 0x00]; // _00 | 00 - 02
	u16 _06;             // _06 | 03
	u8 _08[0x0C - 0x08]; // _08 | 04 - 05
	u16 _0C;             // _0C | 06
	u16 _0E;             // _0E | 07
	u16 _10[5];          // _10 | 08 - 12 | Exact length confirmed: `Cmd_PanPowSet`.
	u16 _1A;             // _1A | 13
	u8 _1C[0x20 - 0x1C]; // _1C | 14
	u32 _20[4];          // _20 | 15 - 22 | Exact length semi-confirmed; Pikmin 2 also says 4.
	u8 _30[0x40 - 0x30]; // _1C | 23 - 31
};

/**
 * @brief Invented struct necessitated by behavior in `seqsetup.c`.
 *
 * @note Size: 0x40.
 */
union URegisterParam_ {
	RegisterParam_ param;
	u16 reg[32];
};

// This is used heavily for jamosc.c, it might be embedded into seqp somewhere...?
typedef struct Osc_definition {
	u8 _00;   // _00
	f32 _04;  // _04
	s16* _08; // _08
	s16* _0C; // _0C
	f32 _10;  // _10
	f32 _14;  // _14
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
	seqp_* parent;            // _040
	seqp_* children[16];      // _044 | Exact length confirmed.
	u32 _84;                  // _084
	u32 _88;                  // _088;
	u32 _8C;                  // _08C
	u32 _90;                  // _090
	u8 _94[8];                // _094 | Exact length confirmed.
	jc_* _9C[8];              // _09C | Exact length confirmed.
	u16 _BC[8];               // _0BC | Exact length conformed.
	u8 _CC[0x0d0 - 0x0cc];    // _0CC
	u32 _D0;                  // _0D0
	u8 _D4;                   // _0D4
	u8 _D5;                   // _0D5
	u8 _D6;                   // _0D6
	u8 _D7[0x0d8 - 0x0d7];    // _0D7
	jcs_ _D8;                 // _0D8
	TimedParam_ timedParam;   // _14C
	URegisterParam_ regParam; // _26C
	OuterParam_* _2AC;        // _2AC
	OuterParam_* _2B0[16];    // _2B0 | Exact length confirmed.
	TrackPort_ trackPort[16]; // _2F0 | Exact length confirmed.
	f32 _330;                 // _330
	f32 _334;                 // _334
	u16 _338;                 // _338
	u16 _33A;                 // _33A
	u8 _33C;                  // _33C
	u8 _33D;                  // _33D
	Osc_definition _340[2];   // _340
	u8 _370[2];               // _370 | Exact length unknown.
	s16 _372[12];             // _372 | ADS table?
	s16 _38A[6];              // _38A | REL table?
	s8 _396;                  // _396 | Confirmed signed (`Cmd_Transpose`)
	u8 _397;                  // _397
	s32 _398;                 // _398 | Might be signed (See: `Init_Track`)
	u8 _39C;                  // _39C
	u8 _39D;                  // _39D
	u8 _39E;                  // _39E
	u8 _39F[0x3a0 - 0x39f];   // _39F
	u16 _3A0;                 // _3A0
	u8 _3A2[0x3a4 - 0x3a2];   // _3A2
	u8 _3A4;                  // _3A4
	u8 _3A5;                  // _3A5
	u8 _3A6;                  // _3A6
	u8 _3A7;                  // _3A7
	u32 _3A8[2];              // _3A8 | Exact length unknown.
	u8 _3B0[0x3c8 - 0x3b0];   // _3A8
	u32 _3C8;                 // _3C8
	u32 _3CC;                 // _3CC
	u32 _3D0;                 // _3D0
	u32 _3D4;                 // _3D4
	u32 _3D8;                 // _3D8
	u8 _3DC[3];               // _3DC | Exact length confirmed.
	u8 _3DF[3];               // _3DF | Exact length confirmed.
	u8 isRegistered;          // _3E2
	u8 _3E3;                  // _3E3
	u8 _3E4;                  // _3E4
	u8 _3E5[0x3e8 - 0x3e5];   // _3E5
	u8 _3E8[2];               // _3E8 | Exact length unknown, but it is an array.
	u8 _3EA[0x434 - 0x3ea];   // _3EA | Exact size of struct confirmed by `Jaf_HandleToSeq`.
};

void* Jam_OfsToAddr(seqp_*, u32);         // TODO: Change return type to u8* if that's more convenient.
void Jam_WriteRegDirect(seqp_*, u8, u16); // Is param_3 is u8 or a u16?
void Jam_WriteRegParam(void);
u16 Jam_ReadRegDirect(seqp_*, u8);
u32 Jam_ReadReg32(seqp_* track, u8 index);
void Jam_WriteRegXY(seqp_* track, u32 param_2);
void Jam_WritePortApp(void);
void Jam_ReadPortApp(void);
void Jam_CheckExportApp(void);
void Jam_CheckImportApp(void);
void Jam_WritePortIndirect(void);
void Jam_ReadPortIndirect(void);
void Jam_CheckPortIndirect(void);
BOOL Jam_WritePortAppDirect(seqp_*, u32, u16);
BOOL Jam_ReadPortAppDirect(seqp_*, u32, u16*);
BOOL Jam_CheckPortAppDirect(seqp_*, u32, u16);
void Jam_WritePort(void);
void Jam_ReadPort(void);
void Jam_WritePortChild(void);
void Jam_WritePortBros(void);
void Jam_InitRegistTrack(void);
void Jam_UnRegistTrack(seqp_*);
seqp_* Jam_GetTrackHandle(u32);
void Jam_InitExtBuffer(OuterParam_*);
BOOL Jam_AssignExtBuffer(seqp_*, OuterParam_*);
BOOL Jam_AssignExtBufferP(seqp_*, u8, OuterParam_*);
void Jam_SetExtFirFilterD(OuterParam_*, s16*);
void Jam_SetExtParamD(f32, OuterParam_*, u8);
void Jam_OnExtSwitchD(OuterParam_*, u16);
void Jam_OffExtSwitchD(OuterParam_*, u16);
void Jam_SetExtSwitchDirectD(void);
void Jam_SetExtFirFilter(void);
void Jam_SetExtParam(f32, seqp_*, u8);
void Jam_OnExtSwitch(seqp_*, u16);
void Jam_OffExtSwitch(seqp_*, u16);
void Jam_SetExtSwitchDirect(void);
void Jam_SetExtFirFilterP(void);
void Jam_SetExtParamP(f32, seqp_*, u8, u8);
void Jam_OnExtSwitchP(seqp_*, u8, u16);
void Jam_OffExtSwitchP(seqp_*, u8, u16);
void Jam_SetExtSwitchDirectP(void);
void Jam_CheckRunningCounter(void);
BOOL Jam_RegisterTrackCallback(TrackCallback);
void Jam_SetTrackExtPanPower(void);
void Jam_UpdateTrackAll(seqp_*);
void Jam_UpdateTrack(seqp_*, u32);
void Jam_UpdateTempo(seqp_*);
void Jam_MuteTrack(seqp_*, u8);
void Jam_MuteChildTracks(void);
void Jam_PauseTrack(seqp_*, u8);
void Jam_UnPauseTrack(seqp_*, u8);
void Jam_SetInterrupt(seqp_*, u16);
BOOL Jam_TryInterrupt(seqp_*);
s32 Jam_SeqmainNote(seqp_*, unknown);
void SeqUpdate(seqp_*, u32);

#ifdef __cplusplus
};
#endif // ifdef __cplusplus

#endif
