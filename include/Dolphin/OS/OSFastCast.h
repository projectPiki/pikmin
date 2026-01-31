#ifndef _DOLPHIN_OS_OSFASTCAST_H
#define _DOLPHIN_OS_OSFASTCAST_H

#include "Dolphin/PPCArch.h"
#include "types.h"

BEGIN_SCOPE_EXTERN_C

/////////////// FAST CAST DEFINES /////////////////////////////////////////////////////////////////

// Paired-singles quantization TYPE and SCALE encodings for GPRs for fast-casting
//  - Types 1-3 are reserved by PowerPC 750cl.
//  - Fast-casting exclusively uses SCALE = 0.

#define OS_GQR_F32 (0x0000) // Single-precision floating-point (no conversion)
#define OS_GQR_U8  (0x0004) // Unsigned 8-bit integer
#define OS_GQR_U16 (0x0005) // Unsigned 16-bit integer
#define OS_GQR_S8  (0x0006) // Signed 8-bit integer
#define OS_GQR_S16 (0x0007) // Signed 16-bit integer

// GQRs reserved for fast-casting (0-1 are reserved by the compiler)

#define OS_FASTCAST_U8  (2)
#define OS_FASTCAST_U16 (3)
#define OS_FASTCAST_S8  (4)
#define OS_FASTCAST_S16 (5)

///////////////////////////////////////////////////////////////////////////////////////////////////

/////////////// FAST CAST INLINES /////////////////////////////////////////////////////////////////

static inline void OSInitFastCast()
{
#ifdef __MWERKS__
	asm {
		li        r3,     OS_GQR_U8
		oris      r3, r3, OS_GQR_U8
		mtspr     GQR2, r3
		li        r3,     OS_GQR_U16
		oris      r3, r3, OS_GQR_U16
		mtspr     GQR3, r3
		li        r3,     OS_GQR_S8
		oris      r3, r3, OS_GQR_S8
		mtspr     GQR4, r3
		li        r3,     OS_GQR_S16
		oris      r3, r3, OS_GQR_S16
		mtspr     GQR5, r3
	}
#endif
}

static inline void OSf32tou8(register f32* in, register u8* out)
{
#ifdef __MWERKS__
	asm {
		lfs      f1, 0 (in)
		psq_st   f1, 0 (out), 1, OS_FASTCAST_U8
	}
#else
	*out = *in;
#endif
}

static inline void OSf32tou16(register f32* in, register u16* out)
{
#ifdef __MWERKS__
	asm {
		lfs      f1, 0 (in)
		psq_st   f1, 0 (out), 1, OS_FASTCAST_U16
	}
#else
	*out = *in;
#endif
}

static inline void OSf32tos8(register f32* in, register s8* out)
{
#ifdef __MWERKS__
	asm {
		lfs      fp1, 0 (in)
		psq_st   fp1, 0 (out), 1, OS_FASTCAST_S8
	}
#else
	*out = *in;
#endif
}

static inline void OSf32tos16(register f32* in, register s16* out)
{
#ifdef __MWERKS__
	asm {
		lfs      fp1, 0 (in)
		psq_st   fp1, 0 (out), 1, OS_FASTCAST_S16
	}
#else
	*out = *in;
#endif
}

static inline void OSu8tof32(register u8* in, register f32* out)
{
#ifdef __MWERKS__
	asm {
		psq_l    fp1, 0 (in), 1, OS_FASTCAST_U8
		stfs     fp1, 0 (out)
	}
#else
	*out = *in;
#endif
}

static inline void OSu16tof32(register u16* in, register f32* out)
{
#ifdef __MWERKS__
	asm {
		psq_l    fp1, 0 (in), 1, OS_FASTCAST_U16
		stfs     fp1, 0 (out)
	}
#else
	*out = *in;
#endif
}

static inline void OSs8tof32(register s8* in, register f32* out)
{
#ifdef __MWERKS__
	asm {
		psq_l    fp1, 0 (in), 1, OS_FASTCAST_S8
		stfs     fp1, 0 (out)
	}
#else
	*out = *in;
#endif
}

static inline void OSs16tof32(register s16* in, register f32* out)
{
#ifdef __MWERKS__
	asm {
		psq_l    fp1, 0 (in), 1, OS_FASTCAST_S16
		stfs     fp1, 0 (out)
	}
#else
	*out = *in;
#endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////

END_SCOPE_EXTERN_C

#endif
