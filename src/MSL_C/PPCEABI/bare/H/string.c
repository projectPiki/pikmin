#include "types.h"

#define K1 0x80808080
#define K2 0xFEFEFEFF

/*
 * --INFO--
 * Address:	........
 * Size:	0000F4
 */
void __strerror(void)
{
	// UNUSED FUNCTION
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
 * Address:	802190E8
 * Size:	00006C
 */
char* strstr(const char* str, const char* substr)
{
	/*
	.loc_0x0:
	  cmplwi    r4, 0
	  subi      r5, r3, 0x1
	  subi      r4, r4, 0x1
	  beqlr-
	  lbzu      r6, 0x1(r4)
	  cmplwi    r6, 0
	  bne-      .loc_0x58
	  blr

	.loc_0x20:
	  cmplw     r0, r6
	  bne-      .loc_0x58
	  subi      r7, r5, 0x1
	  subi      r8, r4, 0x1

	.loc_0x30:
	  lbzu      r0, 0x1(r7)
	  lbzu      r3, 0x1(r8)
	  cmplw     r0, r3
	  bne-      .loc_0x48
	  cmplwi    r0, 0
	  bne+      .loc_0x30

	.loc_0x48:
	  cmplwi    r3, 0
	  bne-      .loc_0x58
	  mr        r3, r5
	  blr

	.loc_0x58:
	  lbzu      r0, 0x1(r5)
	  cmplwi    r0, 0
	  bne+      .loc_0x20
	  li        r3, 0
	  blr
	*/
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
 * Size:	0000C0
 */
size_t strspn(const char* dst, const char* src)
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
 * Size:	000048
 */
char* strrchr(const char* str, int ch)
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
 * Size:	000020
 */
int strcoll(const char* lhs, const char* rhs)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	80219154
 * Size:	000030
 */
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
 * Address:	80219184
 * Size:	000040
 */
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

/*
 * --INFO--
 * Address:	802191C4
 * Size:	000124
 */
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

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
char* strncat(char* dst, const char* src, size_t n)
{
	// UNUSED FUNCTION
}

/*
 * --INFO--
 * Address:	802192E8
 * Size:	00002C
 */
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
 * Address:	80219314
 * Size:	000044
 */
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

/*
 * --INFO--
 * Address:	80219358
 * Size:	0000B4
 */
char* strcpy(char* dst, const char* src)
{
	register u8 *destb, *fromb;
	register u32 w, t, align;

	fromb = (u8*)src;
	destb = (u8*)dst;

	if ((align = ((int)fromb & 3)) != ((int)destb & 3)) {
		goto bytecopy;
	}

	if (align) {
		if ((*destb = *fromb) == 0)
			return (dst);
		for (align = 3 - align; align; align--) {
			if ((*(++destb) = *(++fromb)) == 0)
				return (dst);
		}
		++destb;
		++fromb;
	}

	w = *((int*)(fromb));

	t = w + K2;

	t &= K1;
	if (t)
		goto bytecopy;
	--((int*)(destb));

	do {
		*(++((int*)(destb))) = w;
		w                    = *(++((int*)(fromb)));

		t = w + K2;
		t &= K1;
		if (t)
			goto adjust;
	} while (1);

adjust:
	++((int*)(destb));
bytecopy:
	if ((*destb = *fromb) == 0)
		return dst;
	do {
		if ((*(++destb) = *(++fromb)) == 0)
			return dst;
	} while (1);

	return dst;
}

/*
 * --INFO--
 * Address:	8021940C
 * Size:	000020
 */
size_t strlen(const char* str)
{
	size_t len = -1;
	u8* p      = (u8*)str - 1;

	do
		len++;
	while (*++p);
	return (len);
}
