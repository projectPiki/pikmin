#ifndef _JAUDIO_ONESHOT_H
#define _JAUDIO_ONESHOT_H

#include "types.h"

typedef struct jc_ jc_;
typedef struct Inst_ Inst_;
typedef struct Pmap_ Pmap_;
typedef struct Osc_ Osc_;
typedef struct jcs_ jcs_;
typedef struct CtrlWave_ CtrlWave_;
typedef struct JCSTATUS JCSTATUS;
typedef struct SOUNDID_ SOUNDID_;

struct JCSTATUS {
	// TODO: This is probably also a struct and not an enum.  Confirm.
};

/**
 * @brief This is a "boxed" integer type to be passed by value.
 *
 * @note Size: 4. Why wasn't this just an enum... This compiler is not smart enough to optimize this.
 */
struct SOUNDID_ {
	u32 value; // _00
};

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
u32 One_CheckInstWave(SOUNDID_); // Return type unsure
void Play_1shot(jcs_*, SOUNDID_, u32);
void Play_1shot_Perc(jcs_*, SOUNDID_, u32);
void Play_1shot_Osc(jcs_*, SOUNDID_, u32);

#endif
