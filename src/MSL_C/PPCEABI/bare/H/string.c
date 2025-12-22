#include "types.h"

static s32 K1 = 0x80808080;
static s32 K2 = 0xFEFEFEFF;

size_t strlen(const char* str)
{
	size_t len = -1;
	u8* p      = (u8*)str - 1;

	do
		len++;
	while (*++p);
	return (len);
}

char* strcpy(char* dst, const char* src)
{
	u8* p1       = (u8*)dst;
	const u8* p2 = (u8*)src;
	s32 w;
	s32 t;
	u32 align;
	s32 k1;
	s32 k2;

	if ((align = (u32)src & 3) != ((u32)dst & 3)) {
		goto bytecopy;
	}

	if (align != 0) {
		if ((*p1 = *p2) == 0) {
			return dst;
		}

		align = 3 - align;
		while (align != 0) {
			if ((*++p1 = *++p2) == 0) {
				return dst;
			}
			align--;
		}

		p1++;
		p2++;
	}

	k1 = K1;
	k2 = K2;

	w = *(s32*)p2;
	t = w + k2;
	t &= k1;

	if (t != 0) {
		goto bytecopy;
	}

	p1 -= 4;

	while (TRUE) {
#if __MWERKS__
		*++((s32*)p1) = w;
		w             = *++((s32*)p2);
#else
		p1 += 4;
		p2 += 4;
		*(s32*)p1 = w;
		w         = *(s32*)p2;
#endif

		t = w + k2;
		t &= k1;
		if (t != 0) {
			break;
		}
	}

	p1 += 4;

bytecopy:
	if ((*p1 = *p2) == 0) {
		return dst;
	}

	align = 3 - align;
	while (TRUE) {
		if ((*++p1 = *++p2) == 0) {
			return dst;
		}
	}

	return dst;
}

char* strncpy(char* dst, const char* src, size_t n)
{
	const u8* p = (const u8*)src - 1;
	u8* q       = (u8*)dst - 1;
	u8 zero     = 0;

	n++;

	while (--n)
		if (!(*++q = *++p)) {
			while (--n)
				*++q = 0;
			break;
		}
	return (dst);
}

char* strcat(char* dst, const char* src)
{
	const u8* p = (u8*)src - 1;
	u8* q       = (u8*)dst - 1;

	while (*++q)
		;

	q--;

	while (*++q = *++p)
		;

	return (dst);
}

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
char* strncat(char* dst, const char* src, size_t n)
{
	// UNUSED FUNCTION
}

int strcmp(const char* lhs, const char* rhs)
{
	// bless metrowerks for this implementation

	register u8* left  = (u8*)lhs;
	register u8* right = (u8*)rhs;
	u32 align, l1, r1, x;

	l1 = *left;
	r1 = *right;
	if (l1 - r1) {
		return (l1 - r1);
	}

	if ((align = ((int)left & 3)) != ((int)right & 3)) {
		goto bytecopy;
	}
	if (align) {
		if (l1 == 0) {
			return 0;
		}
		for (align = 3 - align; align; align--) {
			l1 = *(++left);
			r1 = *(++right);
			if (l1 - r1) {
				return (l1 - r1);
			}
			if (l1 == 0) {
				return 0;
			}
		}
		left++;
		right++;
	}

	l1 = *(int*)left;
	r1 = *(int*)right;
	x  = l1 + K2;
	if (x & K1) {
		goto adjust;
	}
	while (l1 == r1) {
		l1 = *(++((int*)(left)));
		r1 = *(++((int*)(right)));
		x  = l1 + K2;
		if (x & K1) {
			goto adjust;
		}
	}
	if (l1 > r1)
		return 1;
	return -1;

adjust:
	l1 = *left;
	r1 = *right;
	if (l1 - r1) {
		return (l1 - r1);
	}
bytecopy:
	if (l1 == 0) {
		return 0;
	}
	do {
		l1 = *(++left);
		r1 = *(++right);
		if (l1 - r1) {
			return (l1 - r1);
		}
		if (l1 == 0) {
			return 0;
		}
	} while (1);
}

int strncmp(const char* lhs, const char* rhs, size_t n)
{
	const u8* p1 = (u8*)lhs - 1;
	const u8* p2 = (u8*)rhs - 1;
	u32 c1, c2;

	n++;

	while (--n)
		if ((c1 = *++p1) != (c2 = *++p2))
			return (c1 - c2);
		else if (!c1)
			break;
	return 0;
}

char* strchr(const char* str, int chr)
{
	const u8* p = (u8*)str - 1;
	u32 c       = (chr & 0xFF);
	u32 ch;

	while (ch = *++p)
		if (ch == c)
			return ((char*)p);

	return (c ? 0 : (char*)p);
}

/*
 * --INFO--
 * Address:	........
 * Size:	000020
 */
int strcoll(const char* lhs, const char* rhs)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00005C
 */
size_t strxfrm(char* dst, const char* src, size_t n)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	000048
 */
char* strrchr(const char* str, int ch)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C4
 */
char* strpbrk(const char* dst, const char* breakset)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
size_t strspn(const char* dst, const char* src)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000C0
 */
size_t strcspn(const char* dst, const char* src)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	00013C
 */
char* strtok(char* str, const char* delim)
{
	// UNUSED FUNCTION
}

char* strstr(const char* str, const char* substr)
{
	u8* s1 = (u8*)str - 1;
	u8* p1 = (u8*)substr - 1;
	u32 firstc, c1, c2;

	if (substr == NULL || !(firstc = *++p1)) {
		return (char*)str;
	}

	while ((c1 = *++s1)) {
		if (c1 == firstc) {
			const u8* s2 = s1 - 1;
			const u8* p2 = p1 - 1;

			while ((c1 = *(++s2)) == (c2 = *(++p2)) && c1)
				;

			if (!c2) {
				return (char*)s1;
			}
		}
	}

	return NULL;
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F8
 */
char* strerror(int errnum)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void __strerror(void)
{
	// UNUSED FUNCTION
}
