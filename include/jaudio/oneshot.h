#ifndef _JAUDIO_ONESHOT_H
#define _JAUDIO_ONESHOT_H

#include "types.h"

typedef struct jc_ jc_;
typedef struct Inst_ Inst_;
typedef struct Perc_ Perc_;
typedef struct Pmap_ Pmap_;
typedef struct Osc_ Osc_;
typedef struct jcs_ jcs_;
typedef struct Vmap_ Vmap_;

typedef struct CtrlWave_ {
	int _00;             // _00
	int _04;             // _04
	int _08;             // _08
	u32 sampleSrcType;   // _0C
	u8 _10[0x34 - 0x10]; // _10, unknown
	u32 waveAddr;        // _34, unknown
} CtrlWave_;
typedef union SOUNDID_ SOUNDID_;

/**
 * @brief This is a "boxed" integer type to be passed by value.
 *
 * @note Size: 4. Why wasn't this just an enum... This compiler is not smart enough to optimize this.
 */
union SOUNDID_ {
	u32 value; // _00
	u8 bytes[4];
};

void Effecter_Overwrite_1ShotD(jc_* jc, Osc_* osc, u32 oscIndex);
Perc_* PercRead(u32 bankIndex, u32 percIndex);
Inst_* InstRead(u32 bankIndex, u32 instIndex);
Vmap_* VmapRead(Inst_* inst, u8 key, u8 velocity);
void Init_1shot(jcs_* chanMgr, u32 oneShotMode);
void Stop_1Shot(jc_* jc);
void Stop_1Shot_R(jc_* jc, u16 releaseFrames);
void AllStop_1Shot(jcs_* chanMgr);
void SetPitchTarget_1Shot(jc_* jc, f32 targetPitch, u32 duration);
void SetKeyTarget_1Shot(jc_* jc, u8 targetKey, u32 duration);
void Gate_1Shot(jc_* jc, u8 key, u8 velocity, s32 playId);
void UpdatePause_1Shot(jc_* jc, u8 pauseFlag);
void UpdatePanPower_1Shot(jc_* jc, f32 left, f32 right, f32 fxMix, f32 dolby);
void FlushRelease_1Shot(jcs_* chanMgr);
u32 One_CheckInstWave(SOUNDID_ soundId); // Return type unsure
jc_* Play_1shot(jcs_* chanMgr, SOUNDID_ soundId, u32 noteId);
jc_* Play_1shot_Perc(jcs_* chanMgr, SOUNDID_ soundId, u32 noteId);
jc_* Play_1shot_Osc(jcs_* chanMgr, SOUNDID_ soundId, u32 noteId);

#endif
