#ifndef _DOLPHIN_VEC_H
#define _DOLPHIN_VEC_H

#include "types.h"

BEGIN_SCOPE_EXTERN_C

/////////////// TYPE DEFINES //////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// VECTOR FUNCTION ALIAS MACROS //////////////////////////////////////////////////////////////////////////////////////////////

#if DEBUG

#define VECAdd            C_VECAdd
#define VECSubtract       C_VECSubtract
#define VECScale          C_VECScale
#define VECNormalize      C_VECNormalize
#define VECSquareMag      C_VECSquareMag
#define VECMag            C_VECMag
#define VECDotProduct     C_VECDotProduct
#define VECCrossProduct   C_VECCrossProduct
#define VECHalfAngle      C_VECHalfAngle
#define VECReflect        C_VECReflect
#define VECSquareDistance C_VECSquareDistance
#define VECDistance       C_VECDistance

#else

#define VECAdd            PSVECAdd
#define VECSubtract       PSVECSubtract
#define VECScale          PSVECScale
#define VECNormalize      PSVECNormalize
#define VECSquareMag      PSVECSquareMag
#define VECDotProduct     PSVECDotProduct
#define VECCrossProduct   PSVECCrossProduct
#define VECSquareDistance PSVECSquareDistance
// Handling Dolphin OS revision 37 vs 47, see longer comment in "mtx.h" for an explanation to what's going on.
#if defined(BUILD_MATCHING) && (defined(VERSION_GPIJ01) || defined(VERSION_GPIE01))
#define C_VECMag       VECMag
#define C_VECHalfAngle VECHalfAngle
#define C_VECReflect   VECReflect
#define C_VECDistance  VECDistance
#else
#define VECMag       PSVECMag
#define VECHalfAngle C_VECHalfAngle // No paired-singles implementation
#define VECReflect   C_VECReflect   // No paired-singles implementation
#define VECDistance  PSVECDistance
#endif

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// VECTOR FUNCTIONS //////////////////////////////////////////////////////////////////////////////////////////////////////////

void C_VECAdd(const Vec* a, const Vec* b, Vec* ab);
void PSVECAdd(const Vec* a, const Vec* b, Vec* ab);
void C_VECSubtract(const Vec* a, const Vec* b, Vec* a_b);
void PSVECSubtract(const Vec* a, const Vec* b, Vec* a_b);
void C_VECScale(const Vec* src, Vec* dst, f32 scale);
void PSVECScale(const Vec* src, Vec* dst, f32 scale);
void C_VECNormalize(const Vec* src, Vec* unit);
void PSVECNormalize(const Vec* src, Vec* unit);
f32 C_VECSquareMag(const Vec* v);
f32 PSVECSquareMag(const Vec* v);
f32 C_VECMag(const Vec* v);
f32 PSVECMag(const Vec* v);
f32 C_VECDotProduct(const Vec* a, const Vec* b);
f32 PSVECDotProduct(const Vec* a, const Vec* b);
void C_VECCrossProduct(const Vec* a, const Vec* b, Vec* axb);
void PSVECCrossProduct(const Vec* a, const Vec* b, Vec* axb);
void C_VECHalfAngle(const Vec* a, const Vec* b, Vec* half);
void C_VECReflect(const Vec* src, const Vec* normal, Vec* dst);
f32 C_VECSquareDistance(const Vec* a, const Vec* b);
f32 PSVECSquareDistance(const Vec* a, const Vec* b);
f32 C_VECDistance(const Vec* a, const Vec* b);
f32 PSVECDistance(const Vec* a, const Vec* b);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
