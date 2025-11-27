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

#ifndef __cplusplus
typedef u16 wchar_t;
#endif

// Workaround to introduce scoped enums (A feature of C++11 and onward).
#define BEGIN_ENUM_TYPE(name) \
	struct name {             \
		typedef

#define END_ENUM_TYPE \
	Type;             \
	}

// For bugfixes that can fit sub-statement, use this instead of a clunky #if #else #endif.
#if defined(BUGFIX)
#define TERNARY_BUGFIX(fixed, buggy) fixed
#else
#define TERNARY_BUGFIX(fixed, buggy) buggy
#endif

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
#define ARRAY_SIZE(o)        (sizeof((o)) / sizeof(*(o)))   // Array size define
#define ALIGN_PREV(X, N)     ((X) & ~((N) - 1))             // Align X to the previous N bytes (N must be power of two)
#define ALIGN_NEXT(X, N)     ALIGN_PREV(((X) + (N) - 1), N) // Align X to the next N bytes (N must be power of two)
#define IS_NOT_ALIGNED(X, N) (((X) & ((N) - 1)) != 0)       // True if X is not aligned to N bytes, else false
#define ATTRIBUTE_ALIGN(num) __attribute__((aligned(num)))  // Align object to num bytes (num should be power of two)

#ifdef __MWERKS__
#define BUMP_REGISTER(reg) \
	{                      \
		asm { mr reg, reg }   \
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

#define REPEAT1(x)  x
#define REPEAT2(x)  REPEAT1(x); x
#define REPEAT3(x)  REPEAT2(x); x
#define REPEAT4(x)  REPEAT3(x); x
#define REPEAT5(x)  REPEAT4(x); x
#define REPEAT6(x)  REPEAT5(x); x
#define REPEAT7(x)  REPEAT6(x); x
#define REPEAT8(x)  REPEAT7(x); x
#define REPEAT9(x)  REPEAT8(x); x
#define REPEAT10(x) REPEAT9(x); x
#define REPEAT11(x) REPEAT10(x); x
#define REPEAT12(x) REPEAT11(x); x

#define REPEAT(x, n) REPEAT##n(x)

// Add an unused local variable to pad the stack by some number of words
#define STACK_PAD_VAR(n) do { int pad[n]; } while (0)

// Create a temporary struct to pad the stack by some number of words
#define STACK_PAD_STRUCT(n) if (0) (struct { int pad[n]; }){}

// Add an unused variable in an inline function to pad the stack by some number of words
inline void padStack(void) { int pad = 0; }
#define STACK_PAD_INLINE(n) REPEAT(padStack(), n)

// Uses a ternary to pad the stack by some number of words
#define STACK_PAD_TERNARY(expr, n) REPEAT((expr) ? "fake" : "fake", n)

// clang-format on

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
