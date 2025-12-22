#include "stl/mem.h"

void* memmove(void* dst, const void* src, size_t len)
{
	u8* csrc;
	u8* cdst;

	int reverse = (u32)src < (u32)dst;

	if (len >= 32) {
		if (((u32)dst ^ (u32)src) & 3) {
			if (!reverse) {
				__copy_longs_unaligned(dst, src, len);
			} else {
				__copy_longs_rev_unaligned(dst, src, len);
			}
		} else {
			if (!reverse) {
				__copy_longs_aligned(dst, src, len);
			} else {
				__copy_longs_rev_aligned(dst, src, len);
			}
		}

		return dst;
	} else {
		if (!reverse) {
			csrc = ((u8*)src) - 1;
			cdst = ((u8*)dst) - 1;
			len++;

			while (--len > 0) {
				*++cdst = *++csrc;
			}
		} else {
			csrc = (u8*)src + len;
			cdst = (u8*)dst + len;
			len++;

			while (--len > 0) {
				*--cdst = *--csrc;
			}
		}
	}

	return dst;
}

void* memchr(u8* s, int c, size_t n)
{
	int n_count;
	size_t char_check;

	char_check = (u8)c;
	s          = &s[-1];
	n_count    = n + 1;
	while (--n_count) {
		if (*++s == char_check) {
			return s;
		}
	}

	return 0;
}

/*
 * --INFO--
 * Address:	........
 * Size:	00002C
 */
void __memrchr(void)
{
	// UNUSED FUNCTION
}

int memcmp(const void* __s1, const void* __s2, size_t __n)
{
	const u8* val1 = ((const u8*)__s1 - 1);
	const u8* val2 = ((const u8*)__s2 - 1);
	size_t size    = __n + 1;

	while (--size > 0) {
		if (*++val1 != *++val2) {
			return (val1[0]) < (val2[0]) ? -1 : 1;
		}
	}

	return 0;
}
