#ifndef _DOLPHIN_MTX_H
#define _DOLPHIN_MTX_H

#include "types.h"
#include "VersionGroups.h"

#ifdef __cplusplus
extern "C" {
#endif // ifdef __cplusplus

#include "Dolphin/vec.h"

/////////////// TYPE DEFINES ///////////////
#define MTXDegToRad(a) ((a) * 0.01745329252f)

typedef f32 Mtx[3][4];
typedef f32 Mtx23[2][3];
typedef f32 Mtx33[3][3];
typedef f32 Mtx44[4][4];
typedef f32 (*MtxP)[4];
typedef f32 (*Mtx3P)[3];
typedef f32 PSQuaternion[4];

typedef struct Quaternion {
	f32 x, y, z, w;
} Quaternion;

////////////////////////////////////////////

////// PAIRED SINGLE MATRIX FUNCTIONS //////
void PSMTXIdentity(Mtx mtx);
void PSMTXConcat(const Mtx A, const Mtx B, Mtx concat);
void PSMTXTranspose(const Mtx src, Mtx xPose);
u32 PSMTXInverse(const Mtx src, Mtx inv);
////////////////////////////////////////////

///////////  MATRIX44 FUNCTIONS ////////////
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
void C_MTXPerspective(Mtx44 mtx, f32 fovY, f32 aspect, f32 n, f32 f);
void C_MTXOrtho(Mtx44 mtx, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);
#else
void MTXPerspective(Mtx44 mtx, f32 fovY, f32 aspect, f32 n, f32 f);
void MTXOrtho(Mtx44 mtx, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);
#endif
////////////////////////////////////////////

///////// CODED C MATRIX FUNCTIONS /////////
void MTXTrans(Mtx m, f32 xT, f32 yT, f32 zT);
#if defined(VERSION_PIKIDEMO) || defined(VERSION_GPIP01_00)
void C_MTXLightPerspective(Mtx m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
void PSMTXScale(Mtx m, f32 xS, f32 yS, f32 zS);
#else
void MTXScale(Mtx m, f32 xS, f32 yS, f32 zS);
void MTXLightPerspective(Mtx m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
#endif
////////////////////////////////////////////

////////////// MATRIX INLINES //////////////
static inline void MTXSetPosition(Mtx mtx, const Vec* pos)
{
	mtx[0][3] = pos->x;
	mtx[1][3] = pos->y;
	mtx[2][3] = pos->z;
}

////////////////////////////////////////////

#ifdef __cplusplus
}
#endif

#endif
