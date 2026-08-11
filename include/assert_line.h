#ifndef _ASSERT_LINE_H
#define _ASSERT_LINE_H

#include "types.h"

#include <assert.h>

// In places that used the `assert` macro, the original line number matters for matching.
// Also, the condition of the assertion gets stringized by the macro.  We stop clang-format
// meddling with the formatting of the condition with the `WhitespaceSensitiveMacros` rule.
#if defined(_MSC_VER) && defined(BUILD_MATCHING)
#define assert_line(cond, line) (void)((cond) || (_assert(#cond, __FILE__, line), 0))
#else
#define assert_line(cond, line) assert(cond)
#endif

#endif
