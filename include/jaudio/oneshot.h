#ifndef _JAUDIO_ONESHOT_H
#define _JAUDIO_ONESHOT_H

#include "types.h"

typedef struct jc_ jc_;
typedef struct Inst_ Inst_;
typedef struct Pmap_ Pmap_;
typedef struct Osc_ Osc_;
typedef struct jcs_ jcs_;
typedef struct CtrlWave_ CtrlWave_;

typedef enum JCSTATUS {
	// TODO: this
} JCSTATUS;

typedef enum SOUNDID_ {
	// TODO: this
} SOUNDID_;

void Effecter_Overwrite_1ShotD(jc_*, Osc_*, u32);
void PercRead(u32, u32);
void InstRead(u32, u32);
void VmapRead(Inst_*, u8, u8);
void Init_1shot(jcs_*, u32);
void Stop_1Shot(jc_*);
void Stop_1Shot_R(jc_*, u16);
void AllStop_1Shot(jcs_*);
void SetPitchTarget_1Shot(jc_*, f32, u32);
void SetKeyTarget_1Shot(jc_*, u8, u32);
void Gate_1Shot(jc_*, u8, u8, s32);
void UpdatePause_1Shot(jc_*, u8 a1);
void UpdatePanPower_1Shot(jc_*, f32, f32, f32, f32);
void FlushRelease_1Shot(jcs_*);
void One_CheckInstWave(SOUNDID_);
void Play_1shot(jcs_*, SOUNDID_, u32);
void Play_1shot_Perc(jcs_*, SOUNDID_, u32);
void Play_1shot_Osc(jcs_*, SOUNDID_, u32);

#endif
