#ifndef _TYPES_H
#define _TYPES_H

// r2 is  803F0200
// r13 is 803E4D20

typedef int BOOL;
typedef unsigned int uint;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float f32;
typedef double f64;
typedef long double f128;
typedef volatile f32 vf32;
typedef volatile f64 vf64;
typedef volatile f128 vf128;

typedef u32 unknown;

#ifdef __MWERKS__
#define PRINT(...)
#define ERROR(...)
#else
#define PRINT(...) _Print(__VA_ARGS__)
#define ERROR(...) _Error(__VA_ARGS__)
#endif

#define WINDOWS_ONLY_START (#ifdef _WIN32)
#define WINDOWS_ONLY_END   (#endif)

#define DEFINE_ENUM_TYPE(name, ...)  \
	struct name {                    \
		enum Values { __VA_ARGS__ }; \
		typedef Values Type;         \
	}

#ifndef __cplusplus
typedef u16 wchar_t;
#endif

/* uint<x>_t */
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef int intptr_t;
typedef unsigned int uintptr_t;

typedef unsigned long size_t;

#define TRUE    1
#define FALSE   0
#define NULL    ((void*)0)
#define nullptr 0

#define PATH_MAX (256)

// Sets specific flag to 1
#define SET_FLAG(x, val) (x |= (val))

// Resets specific flag from (val) back to 0
#define RESET_FLAG(x, val) (x &= ~(val))

// Return 1 if flag is set, 0 if flag is not set
#define IS_FLAG(x, val) (x & val)

// Array size define
#define ARRAY_SIZE(o) (sizeof((o)) / sizeof(*(o)))

// Align X to the previous N bytes (N must be power of two)
#define ALIGN_PREV(X, N) ((X) & ~((N) - 1))

// Align X to the next N bytes (N must be power of two)
#define ALIGN_NEXT(X, N) ALIGN_PREV(((X) + (N) - 1), N)

// True if X is aligned to N bytes, else false
#define IS_ALIGNED(X, N) ((X & ((N) - 1)) == 0)

// True if X is not aligned to N bytes, else false
#define IS_NOT_ALIGNED(X, N) (((X) & ((N) - 1)) != 0)

// Align object to num bytes (num should be power of two)
#define ATTRIBUTE_ALIGN(num) __attribute__((aligned(num)))

// Checks if a flag is set in a bitfield
#define IS_FLAG_SET(flags, bitsFromLSB) (((flags) >> (bitsFromLSB) & 1))

#define ASSERT_HANG(cond) \
	if (!(cond)) {        \
		while (true) { }  \
	}

// Get the maximum of two values
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// Get the minimum of two values
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// Rounds a float to a u8
#define ROUND_F32_TO_U8(a) a >= 0.0f ? a + 0.5f : a - 0.5f

// Number of bytes in a kilobyte
#define KILOBYTE_BYTECOUNT 1024

#define BUMP_REGISTER(reg) \
	{                      \
		asm { mr reg, reg }   \
	}

#ifdef __MWERKS__
#define WEAKFUNC        __declspec(weak)
#define DECL_SECT(name) __declspec(section name)
#define ASM             asm
#else
#define WEAKFUNC
#define DECL_SECT(name)
#define ASM
#endif

#endif // _TYPES_H
