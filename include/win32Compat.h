#ifndef _WIN32_COMPAT_H
#define _WIN32_COMPAT_H

// Compatibility shims for building the Windows (VC6) target of Pikmin.
//
// The DOL build gets its standard library from include/stl (the CodeWarrior/EABI MSL).
// We cannot put include/stl on the VC6 search path: its replacement <stddef.h>/<math.h>/...
// shadow VC6's own CRT headers and do not parse (PPC intrinsics, __HI, f128, ...). So the
// Windows build uses VC6's system headers instead, and this file supplies only the extra
// pieces the shared code expects from `#include "math.h"` beyond VC6's <math.h>: the game
// math constants, and the `std::` float helpers. Guarded WIN32, so the DOL path is untouched.

#include "types.h"
#include <math.h> // VC6 system math: double sqrt/fmod used by the std:: helpers below

// NOTE: we deliberately do NOT `#undef near`/`#undef far`. windows.h defines them as empty
// macros; undefining them re-exposes VC6's reserved obsolete `near`/`far` keywords (C4226),
// which is worse. Source identifiers named near/far are instead renamed at the definition.

// VC6 uses the pre-standard for-scope rule: a variable declared in `for (int i ...)` leaks
// into the enclosing block, so a second same-named loop in one function is a redefinition
// (C2374). The codebase (written for MWCC's standard scoping) redeclares freely. This is
// the standard VC6-era fix - give each `for` its own scope. Safe here because the codebase
// consistently braces loop bodies, so the `else` never dangles. Verified codegen-neutral at
// /Od against the already-matching AyuStack functions.
#define for if (0) {} else for

// Game math constants (mirror include/stl/math.h). VC6's <math.h> does not define these.
#ifndef PI
#define LONG_TAU   6.2831854820251465
#define TAU        6.2831855f
#define PI         3.1415927f
#define HALF_PI    1.5707964f
#define THIRD_PI   1.0471976f
#define QUARTER_PI 0.7853982f
#define SIN_2_5    0.43633234f
#define M_SQRT3    1.73205f
#endif
#ifndef M_PI
#define M_PI 3.1415926535897932
#endif

// VC6's <math.h> predates C99 and does not define NAN. Construct a quiet NaN from its
// IEEE-754 bit pattern. (Writing 0.0f/0.0f instead would be a compile-time divide-by-zero
// error under VC6's constant folder.)
#ifndef NAN
static const union {
	u32 __bits;
	f32 __f;
} __piki_nan = { 0x7FC00000 };
#define NAN (__piki_nan.__f)
#endif

#ifdef __cplusplus
// The shared headers reference std::sqrtf / std::fmodf (defined in include/stl/math.h on the
// DOL side). VC6's CRT has the double math functions but not these C99 float names in `std`,
// so provide thin wrappers over the double versions. Matching each to its real body address
// is a later grind concern; for now these just make the module compile.
namespace std {
inline f32 sqrtf(f32 x) { return (f32)sqrt((f64)x); }
inline f32 fmodf(f32 x, f32 m) { return (f32)fmod((f64)x, (f64)m); }
} // namespace std
#endif

#endif
