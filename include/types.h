#ifndef _TYPES_H
#define _TYPES_H

// r2  is 803F0200
// r13 is 803E4D20

// Custom types
typedef int BOOL;
typedef unsigned int uint;
typedef unsigned long size_t;

// Standard types
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

// Volatile types
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
typedef u8 unknown8;
typedef u16 unknown16;
typedef u32 unknown32;
typedef u64 unknown64;

#ifndef __cplusplus
typedef u16 wchar_t;
#endif

// Workaround for strongly typed enums (our version of C++ doesn't support them)
#define DEFINE_ENUM_TYPE(name, ...)  \
	struct name {                    \
		enum Values { __VA_ARGS__ }; \
		typedef Values Type;         \
	}

// Workaround for Visual Studio and VS Code not recognising the above macro as a valid type
#define BEGIN_ENUM_TYPE(name) \
	struct name {             \
		typedef

#define END_ENUM_TYPE \
	Type;             \
	}

// Workarounds for our version of C++ and other stupidities
#undef TRUE
#define TRUE (1)
#undef FALSE
#define FALSE (0)

#if !defined(__cplusplus)
#define NULL    ((void*)0)
#define nullptr 0
#elif __cplusplus >= 201103L
#define NULL nullptr
#else
#define NULL    0
#define nullptr 0
#endif

// Random and useful macros
#define PATH_MAX  (256)                     // Max path length
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) // Returns the maximum of a and b
#define MIN(a, b) (((a) < (b)) ? (a) : (b)) // Returns the minimum of a and b

// Flag manipulation macros
#define SET_FLAG(x, val)                (x |= (val))                     // Sets specific flag to 1
#define RESET_FLAG(x, val)              (x &= ~(val))                    // Resets specific flag from (val) back to 0
#define IS_FLAG(x, val)                 (x & val)                        // Return 1 if flag is set, 0 if flag is not set
#define ARRAY_SIZE(o)                   (sizeof((o)) / sizeof(*(o)))     // Array size define
#define ALIGN_PREV(X, N)                ((X) & ~((N) - 1))               // Align X to the previous N bytes (N must be power of two)
#define ALIGN_NEXT(X, N)                ALIGN_PREV(((X) + (N) - 1), N)   // Align X to the next N bytes (N must be power of two)
#define IS_ALIGNED(X, N)                ((X & ((N) - 1)) == 0)           // True if X is aligned to N bytes, else false
#define IS_NOT_ALIGNED(X, N)            (((X) & ((N) - 1)) != 0)         // True if X is not aligned to N bytes, else false
#define ATTRIBUTE_ALIGN(num)            __attribute__((aligned(num)))    // Align object to num bytes (num should be power of two)
#define IS_FLAG_SET(flags, bitsFromLSB) (((flags) >> (bitsFromLSB) & 1)) // Checks if a flag is set in a bitfield
#define ASSERT_HANG(cond) \
	if (!(cond)) {        \
		while (true) { }  \
	}

#ifdef __MWERKS__
#define BUMP_REGISTER(reg)  \
	{                       \
		asm { mr reg, reg } \
	}
#else
#define BUMP_REGISTER(reg) (void)0
#endif

// clang-format off
#define FORCE_DONT_INLINE \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; \
	(void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0; (void*)0;
// clang-format on

inline void padStack(void)
{
	int pad = 0;
}
#define PAD_STACK() padStack()

#ifdef __MWERKS__
#define WEAKFUNC        __declspec(weak)
#define DECL_SECT(name) __declspec(section name)
#define ASM             asm
#else
#define WEAKFUNC
#define DECL_SECT(name)
#define ASM
#endif

#define INIT  DECL_SECT(".init")
#define CTORS DECL_SECT(".ctors")

// Disable clangd warnings
#ifdef __clang__
// Allow string literals to be converted to char*
#pragma clang diagnostic ignored "-Wc++11-compat-deprecated-writable-strings"
#endif

#endif // _TYPES_H
