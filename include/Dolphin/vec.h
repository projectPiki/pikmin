#ifndef _DOLPHIN_VEC_H
#define _DOLPHIN_VEC_H

#include "types.h"
#include "VersionGroups.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

typedef struct Vec {
	f32 x;
	f32 y;
	f32 z;
} Vec;

typedef struct SVec {
	s16 x;
	s16 y;
	s16 z;
} SVec;

f32 PSVECSquareMag(Vec*);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
f32 PSVECMag(Vec*);
#else
f32 VECMag(Vec*);
#endif

#ifdef __cplusplus
}
#endif

#endif
