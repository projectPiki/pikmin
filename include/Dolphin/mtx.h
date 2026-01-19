#ifndef _DOLPHIN_MTX_H
#define _DOLPHIN_MTX_H

#include "types.h"

#include "Dolphin/vec.h"

BEGIN_SCOPE_EXTERN_C

/////////////// TYPE DEFINES //////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MTXDegToRad(a) ((a) * (3.1415927f / 180.0f))

typedef f32 Mtx[3][4];
typedef f32 Mtx23[2][3];
typedef f32 Mtx33[3][3];
typedef f32 Mtx44[4][4];

typedef f32 (*MtxPtr)[4];
typedef f32 (*Mtx23Ptr)[2];
typedef f32 (*Mtx33Ptr)[3];
typedef f32 (*Mtx44Ptr)[4];
typedef f32 PSQuaternion[4];

typedef struct Quaternion {
	f32 x, y, z, w;
} Quaternion;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// MATRIX FUNCTION ALIAS MACROS //////////////////////////////////////////////////////////////////////////////////////////////

#if DEBUG

#define MTXIdentity         C_MTXIdentity
#define MTXCopy             C_MTXCopy
#define MTXConcat           C_MTXConcat
#define MTXTranspose        C_MTXTranspose
#define MTXInverse          C_MTXInverse
#define MTXInvXpose         C_MTXInvXpose
#define MTXRotRad           C_MTXRotRad
#define MTXRotTrig          C_MTXRotTrig
#define MTXRotAxisRad       C_MTXRotAxisRad
#define MTXTrans            C_MTXTrans
#define MTXTransApply       C_MTXTransApply
#define MTXScale            C_MTXScale
#define MTXScaleApply       C_MTXScaleApply
#define MTXQuat             C_MTXQuat
#define MTXReflect          C_MTXReflect
#define MTXLookAt           C_MTXLookAt
#define MTXLightFrustum     C_MTXLightFrustum
#define MTXLightPerspective C_MTXLightPerspective
#define MTXLightOrtho       C_MTXLightOrtho
#define MTXFrustum          C_MTXFrustum
#define MTXPerspective      C_MTXPerspective
#define MTXOrtho            C_MTXOrtho
#define MTX44Identity       C_MTX44Identity
#define MTX44Copy           C_MTX44Copy
#define MTX44Concat         C_MTX44Concat
#define MTX44Transpose      C_MTX44Transpose
#define MTX44Inverse        C_MTX44Inverse
#define MTX44Trans          C_MTX44Trans
#define MTX44TransApply     C_MTX44TransApply
#define MTX44Scale          C_MTX44Scale
#define MTX44ScaleApply     C_MTX44ScaleApply
#define MTX44RotRad         C_MTX44RotRad
#define MTX44RotTrig        C_MTX44RotTrig
#define MTX44RotAxisRad     C_MTX44RotAxisRad

#else

#define MTXIdentity  PSMTXIdentity
#define MTXCopy      PSMTXCopy
#define MTXConcat    PSMTXConcat
#define MTXTranspose PSMTXTranspose
#define MTXInverse   PSMTXInverse
#define MTXInvXpose  PSMTXInvXpose
// Japanese and American retail versions of Pikmin 1 use Dolphin OS revision 37, which features an unfinished matrix library with
// fewer paired-singles implementations and barely any functions for 4x4 matrices. Japanese and American demo versions of Pikmin 1
// use Dolphin OS revision 47, which by then rounded-out the matrix library. European retail and demo versions of Pikmin 1 use
// Dolphin OS revision 49, which (probably?) has no further changes to the matrix library. Here we do a little bit of redirection
// to juggle these version differences while still producing a useable codebase: for matching Japanese and American retail versions,
// certain `C_`-prefixed function implementations are renamed via macros, and the paired-singles implementations and C functions
// from the future Dolphin OS revisions that shouldn't be accessible are not given function alias macros.
#if defined(BUILD_MATCHING) && (defined(VERSION_GPIJ01) || defined(VERSION_GPIE01))
#define C_MTXRotRad           MTXRotRad
#define C_MTXRotTrig          MTXRotTrig
#define C_MTXRotAxisRad       MTXRotAxisRad
#define C_MTXTrans            MTXTrans
#define C_MTXTransApply       MTXTransApply
#define C_MTXScale            MTXScale
#define C_MTXScaleApply       MTXScaleApply
#define C_MTXQuat             MTXQuat
#define C_MTXReflect          MTXReflect
#define C_MTXLookAt           MTXLookAt
#define C_MTXLightFrustum     MTXLightFrustum
#define C_MTXLightPerspective MTXLightPerspective
#define C_MTXLightOrtho       MTXLightOrtho
#define C_MTXFrustum          MTXFrustum
#define C_MTXPerspective      MTXPerspective
#define C_MTXOrtho            MTXOrtho
#else // VERSION_PIKIDEMO, VERSION_GPIP01, Non-Matching builds
#define MTXRotRad           PSMTXRotRad
#define MTXRotTrig          PSMTXRotTrig
#define MTXRotAxisRad       PSMTXRotAxisRad
#define MTXTrans            PSMTXTrans
#define MTXTransApply       PSMTXTransApply
#define MTXScale            PSMTXScale
#define MTXScaleApply       PSMTXScaleApply
#define MTXQuat             PSMTXQuat
#define MTXReflect          PSMTXReflect
#define MTXLookAt           C_MTXLookAt           // No paired-singles implementation
#define MTXLightFrustum     C_MTXLightFrustum     // No paired-singles implementation
#define MTXLightPerspective C_MTXLightPerspective // No paired-singles implementation
#define MTXLightOrtho       C_MTXLightOrtho       // No paired-singles implementation
#define MTXFrustum          C_MTXFrustum          // No paired-singles implementation
#define MTXPerspective      C_MTXPerspective      // No paired-singles implementation
#define MTXOrtho            C_MTXOrtho            // No paired-singles implementation
#define MTX44Identity       PSMTX44Identity
#define MTX44Copy           PSMTX44Copy
#define MTX44Concat         PSMTX44Concat
#define MTX44Transpose      PSMTX44Transpose
#define MTX44Inverse        C_MTX44Inverse // No paired-singles implementation
#define MTX44Trans          PSMTX44Trans
#define MTX44TransApply     PSMTX44TransApply
#define MTX44Scale          PSMTX44Scale
#define MTX44ScaleApply     PSMTX44ScaleApply
#define MTX44RotRad         PSMTX44RotRad
#define MTX44RotTrig        PSMTX44RotTrig
#define MTX44RotAxisRad     PSMTX44RotAxisRad
#endif

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// MATRIX FUNCTIONS //////////////////////////////////////////////////////////////////////////////////////////////////////////

void C_MTXIdentity(Mtx m);
void PSMTXIdentity(Mtx m);
void C_MTXCopy(const Mtx src, Mtx dst);
void PSMTXCopy(const Mtx src, Mtx dst);
void C_MTXConcat(const Mtx a, const Mtx b, Mtx dst);
void PSMTXConcat(const Mtx a, const Mtx b, Mtx dst);
void C_MTXTranspose(const Mtx src, Mtx xPose);
void PSMTXTranspose(const Mtx src, Mtx xPose);
u32 C_MTXInverse(const Mtx src, Mtx inv);
u32 PSMTXInverse(const Mtx src, Mtx inv);
u32 C_MTXInvXpose(const Mtx src, Mtx inv);
u32 PSMTXInvXpose(const Mtx src, Mtx inv);
void C_MTXRotRad(Mtx m, char axis, f32 rad);
void PSMTXRotRad(Mtx m, char axis, f32 rad);
void C_MTXRotTrig(Mtx m, char axis, f32 sinA, f32 cosA);
void PSMTXRotTrig(Mtx m, char axis, f32 sinA, f32 cosA);
void C_MTXRotAxisRad(Mtx m, const Vec* axis, f32 rad);
void PSMTXRotAxisRad(Mtx m, const Vec* axis, f32 rad);
void C_MTXTrans(Mtx m, f32 xT, f32 yT, f32 zT);
void PSMTXTrans(Mtx m, f32 xT, f32 yT, f32 zT);
void C_MTXTransApply(const Mtx src, Mtx dst, f32 xT, f32 yT, f32 zT);
void PSMTXTransApply(const Mtx src, Mtx dst, f32 xT, f32 yT, f32 zT);
void C_MTXScale(Mtx m, f32 xS, f32 yS, f32 zS);
void PSMTXScale(Mtx m, f32 xS, f32 yS, f32 zS);
void C_MTXScaleApply(const Mtx src, Mtx dst, f32 xS, f32 yS, f32 zS);
void PSMTXScaleApply(const Mtx src, Mtx dst, f32 xS, f32 yS, f32 zS);
void C_MTXQuat(Mtx m, const Quaternion* quat);
void PSMTXQuat(Mtx m, const Quaternion* quat);
void C_MTXReflect(Mtx m, const Vec* p, const Vec* n);
void PSMTXReflect(Mtx m, const Vec* p, const Vec* n);
void C_MTXLookAt(Mtx m, const Vec* camPos, const Vec* camUp, const Vec* target);
void C_MTXLightFrustum(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
void C_MTXLightPerspective(Mtx m, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
void C_MTXLightOrtho(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 scaleS, f32 scaleT, f32 transS, f32 transT);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// MATRIX44 FUNCTIONS ////////////////////////////////////////////////////////////////////////////////////////////////////////

void C_MTXFrustum(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);
void C_MTXPerspective(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f);
void C_MTXOrtho(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);
void C_MTX44Identity(Mtx44 m);
void PSMTX44Identity(Mtx44 m);
void C_MTX44Copy(const Mtx44 src, Mtx44 dst);
void PSMTX44Copy(const Mtx44 src, Mtx44 dst);
void C_MTX44Concat(const Mtx44 a, const Mtx44 b, Mtx44 ab);
void PSMTX44Concat(const Mtx44 a, const Mtx44 b, Mtx44 ab);
void C_MTX44Transpose(const Mtx44 src, Mtx44 xPose);
void PSMTX44Transpose(const Mtx44 src, Mtx44 xPose);
u32 C_MTX44Inverse(const Mtx44 src, Mtx44 inv);
void C_MTX44Trans(Mtx44 m, f32 xT, f32 yT, f32 zT);
void PSMTX44Trans(Mtx44 m, f32 xT, f32 yT, f32 zT);
void C_MTX44TransApply(const Mtx44 src, Mtx44 dst, f32 xT, f32 yT, f32 zT);
void PSMTX44TransApply(const Mtx44 src, Mtx44 dst, f32 xT, f32 yT, f32 zT);
void C_MTX44Scale(Mtx44 m, f32 xS, f32 yS, f32 zS);
void PSMTX44Scale(Mtx44 m, f32 xS, f32 yS, f32 zS);
void C_MTX44ScaleApply(const Mtx44 src, Mtx44 dst, f32 xS, f32 yS, f32 zS);
void PSMTX44ScaleApply(const Mtx44 src, Mtx44 dst, f32 xS, f32 yS, f32 zS);
void C_MTX44RotRad(Mtx44 m, char axis, f32 rad);
void PSMTX44RotRad(Mtx44 m, char axis, f32 rad);
void C_MTX44RotTrig(Mtx44 m, char axis, f32 sinA, f32 cosA);
void PSMTX44RotTrig(Mtx44 m, char axis, f32 sinA, f32 cosA);
void C_MTX44RotAxisRad(Mtx44 m, const Vec* axis, f32 rad);
void PSMTX44RotAxisRad(Mtx44 m, const Vec* axis, f32 rad);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// MATRIX INLINES ////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @todo Documentation
 */
static inline void MTXSetPosition(Mtx mtx, const Vec* pos)
{
	mtx[0][3] = pos->x;
	mtx[1][3] = pos->y;
	mtx[2][3] = pos->z;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
